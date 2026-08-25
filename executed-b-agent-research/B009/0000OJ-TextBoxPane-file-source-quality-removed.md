# Removed Legacy Operational Package From UID0000OJ

- Source report: [0000OJ-TextBoxPane-file-source-quality.md](0000OJ-TextBoxPane-file-source-quality.md), project-relative path `tools/leaser/Agents/Agent-B009/research/0000OJ-TextBoxPane-file-source-quality.md`.
- Rejected source artifact: SHA256 `D6DFCD16980D8648AF068AF345FEC3AB1D3EB364A0E654A2D2B0B83AE12EE524`.
- Status: historical, inert, and non-authoritative. Never execute any content in this file.
- Prohibition: never submit this companion, any excerpt, or any derived form to `execute_report`.
- Credit: this file is not a B report and receives no Gate 1, Gate 2, coverage, score, IDA, validator, audit, catalog, or lifecycle credit.
- Scope: the fenced blocks preserve verbatim legacy operational text removed from the authoritative report. They are retained only as rejected-artifact history and are not instructions.

## Removed Block 001

Rejected-artifact location: Section 21 legacy operational package.

~~~text
Transaction-copy startup is a fail-closed prerequisite, not an action row or executable transaction package. Bind `CANONICAL` only to the exact normalized canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. First bind a complete physical identity tuple for `CANONICAL`: normalized lexical path, final path resolved from a closed/reopened file handle, exact normalized parent and volume root, volume serial and file ID, regular-file attributes and reparse tag, hardlink count, complete alternate-stream list, byte count `CANON_BASE_SIZE`, and SHA256 `CANON_BASE_SHA256`. Reject any reparse point, symlink, junction, hardlink count other than one, path/final-path alias, named alternate data stream, non-regular file, parent/root/volume mismatch, or identity ambiguity. Before any IDA preflight or mutation, the supervisor creates `BACKUP` and `TX` at exclusive collision-checked no-overwrite paths, with no alias to each other or `CANONICAL`; copies each only from verified `CANONICAL`; invokes built-in file-handle `FileStream.Flush(Boolean)` with `flushToDisk:true` on each newly created file; closes all source/destination handles; and independently reopens each read-only to reproduce the complete physical tuple and exact baseline size/SHA256. This file-handle flush plus closed/reopened receipt is the supported file-persistence proof. No containing-directory handle or directory-metadata flush is required or credited.

Physical replacement capability must be proved before any IDA mutation. The only authorized replacement primitive is the already available built-in `System.IO.File.Replace` four-argument overload, with source equal to the sealed candidate, destination equal to the existing destination path, destination backup name null, and `ignoreMetadataErrors:false`; no custom interop, `Add-Type`, P/Invoke, `MoveFileEx`, shell move, copy-overwrite, delete-then-rename, retry, or second replacement primitive may substitute. In `CANONICAL`'s exact normalized parent and volume, the supervisor must create exclusive collision-checked disposable `PROBE_SOURCE`, `PROBE_DESTINATION`, and `PROBE_CANDIDATE` regular files with distinct deterministic non-IDB payloads and receipts; prove all path-component/final-path/volume-file-ID/reparse/hardlink/alias/stream constraints; copy the candidate only from the source; file-flush, close, reopen, and verify all three; invoke that exact `System.IO.File.Replace` overload once from candidate to destination; and prove source unchanged, destination now equal to the candidate payload and expected candidate file identity, candidate absent, no API-created backup path, and no second/residual probe artifact. Probe cleanup must then remove only the three bound disposable paths and prove exact-parent absence. This probe tests the same operation, parent, volume, permissions, policy route, source preservation, candidate consumption, and receipt path required later; it supplies no IDA or final-persistence credit by itself.

Durability-branch behavior is deterministic. If any required probe/create/copy/file-flush/close/reopen/identity/stream/replace/readback/no-residue primitive is unavailable, returns access denied, is unsupported on the actual volume, is policy-blocked, times out, is ambiguous, or cannot be fully verified, stop before `idb_open` or any IDA mutation and award zero Gate 2B credit. The known directory-handle `Access is denied` and custom write-through policy block are excluded-alternative receipts, not reasons to bypass the approved probe and not successes. If a required primitive becomes unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified after TX work but before the one replacement call, promote nothing, retire every TX role, prove `CANONICAL`/`BACKUP` unchanged, and quarantine or discard TX/candidates only under the existing closed-handle supervisor path. Once the one replacement call is invoked, any exception, timeout, ambiguous result, or incomplete post-receipt is post-promotion unless independent receipts prove `CANONICAL` retained its exact expected-current baseline; never retry. A restoration candidate or replacement failure never counts as restored: keep sealed `BACKUP`, preserve failed-CANON/candidate receipts, use no fallback primitive, and return for supervisor physical recovery. Thus the 49-entity/196-request handoff remains proposed and is not physically implementation-ready until the fresh probe succeeds and the complete final protocol closes.

After the physical startup and probe pass, the literal current-schema open is `idb_open({input_path:TX,mode:"force_headless",run_auto_analysis:false,build_caches:true,init_hexrays:true,idle_ttl_sec:600})`, with no `preferred_session_id`. Require `success:true`, no returned `error`, a returned `session`, returned `session.input_path == TX`, and a nonempty returned `session.session_id`; bind only that exact returned session-ID string as `DB`. `DB` is therefore a response-bound metavariable whose exact returned string is substituted verbatim, never a report-chosen alias, preferred-session value, remembered session, canonical session, canonical path, registry row, or prior attestation value. The current `idb_open` response schema does not expose `session.canonical_path`, so no such field is required.

Only after that open succeeds, call literal public `runtime_attestation({expected_database:DB,expected_canonical_path:TX})`. This public response is one indivisible fail-closed package with two status-bearing levels: require top-level `schema_version:1`, top-level `ok:true`, and top-level `errors:[]`; require every nested worker attestation to have `schema_version:1`, `ok:true`, and `errors:[]`; the listener object has no local `ok` or `errors` fields, and their absence is expected rather than failure. Reject every missing, null, false, malformed, or nonempty top-level or worker status/error field, and reject every stale, duplicate, ambiguous, extra-ownership, partial, or mismatched listener identity/runtime field. Freshness requires a new `attested_at_utc` and nonce for the exact boundary being authorized; cached or earlier responses confer no authority. `runtime_attestation` proves runtime/session/path/process/route/module identity and freshness only; it does not return or prove an IDB file's physical byte count or SHA256, so every physical identity below requires a separate filesystem receipt.

Listener identity is literal. The current public schema supplies no `listener.ok`, `listener.error`, or `listener.errors` fields; do not require or synthesize them, and do not treat their absence as failure. Require `listener.role == "supervisor_listener"`, fresh `listener.nonce` and `listener.attested_at_utc`, exact `listener.endpoint.host == "127.0.0.1"` and `listener.endpoint.port == 13337`, and independent operating-system proof that `listener.process.pid` currently owns that listening port. Record and require exact `listener.process.pid`, `listener.process.parent_pid`, `listener.process.creation_time_100ns`, `listener.process.generation`, `listener.process.sys_executable`, `listener.process.process_image`, and `listener.process.argv`; also require exact `listener.source_root`, `listener.implementation_manifest_sha256`, and complete listener loaded-`modules` validation against `LISTENER_MODULE_BASELINE` as specified below. Reject PID or generation reuse, endpoint drift, a non-owner PID, source-root/role-manifest/module drift, or any listener transition not followed by a wholly fresh package.

Worker ownership, status, and parent routing are literal. Independently require the nested worker's `schema_version:1`, `ok:true`, and `errors:[]`; worker status is independent of top-level status, and neither status-bearing level substitutes for the other. Require exactly one active `workers` route to claim both returned session `DB` and normalized path `TX`; require that route's exact host/port and exactly one matching `supervisor_sessions` row with `session_id == DB`, canonical/input path exactly `TX`, expected backend, `owned == true`, and exact `redirector_pid` and `registered_pid`. The nested worker must have a fresh nonce and `attested_at_utc`, exact role, endpoint host/port equal to that route, exact `process.pid`, `parent_pid`, `creation_time_100ns`, `generation`, `sys_executable`, `process_image`, and `argv`; independently prove that the worker PID owns the route port, that its PID equals the registered worker identity, and that its parent PID equals the attested redirector identity. Require exactly one active worker session with identifier `DB` and canonical/input paths exactly `TX`; reject duplicate, inactive, remembered, canonical-path, competing, or unowned claims. Other concurrent routes may exist only when separately and unambiguously bound and when none claims this `DB` or `TX`.

Loaded implementation identity is literal and role-specific. Require the listener and worker each to enumerate the actually loaded `ida_pro_mcp` and `zeromcp` module objects, its exact source root, and its exact `implementation_manifest_sha256`. For every loaded module row require exact `sys_modules_name`, `module_id`, `file`, `spec_origin`, `resolved_path`, source root, `size`, `mtime_ns`, `ctime_ns`, and 64-hex `sha256`, with every resolved path under that role's attested source root. Seal the listener's complete ordered module rows and manifest against the accepted `LISTENER_MODULE_BASELINE`, seal the worker's complete ordered module rows and manifest against the accepted `WORKER_MODULE_BASELINE`, and require each role to remain unchanged against its own baseline at every protected checkpoint. Listener and worker load different module sets by design: no cross-role row equality or implementation-manifest equality is required or permitted as a substitute for these two role-specific comparisons. A venv path, command line, on-disk candidate module, native-module list, digest alone, separately launched interpreter, or inactive session row is not loaded-runtime proof.

Public tool-surface exclusion and save-schema proof are literal. At the same boundary, a fresh public `tools/list` must expose exactly one public `runtime_attestation`, must expose no public or internal `runtime/attest`, and must prove the current public `idb_save` schema whose exact operation contract is `idb_save({database:DB,path:TX}) -> {ok,error?,path}`. The internal route must never be called. More or fewer public attestation tools, public exposure or use of `runtime/attest`, an absent or drifted `idb_save` schema, any top-level or worker status/error mismatch, or any listener/worker freshness, port-owner, PID/parent, generation, process-image, route, ownership, session, path, role-specific manifest, module-field, or module-hash mismatch hard-stops before the protected boundary. This complete package, not a subset or an inferred equivalent, is the exact `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` contract governing I01-I49. Every later reference to the complete/fresh/role-specific package means the same independent top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]` closure, plus the listener's complete role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; the listener has no local `ok` or `errors` fields, and their absence is expected rather than failure.

Runtime binding is not startup-only. Repeat a fresh complete public `runtime_attestation({expected_database:DB,expected_canonical_path:TX})` package and matching public `tools/list` proof immediately before every persistent `rename`, `set_function_comments`, and `set_repeatable_comments` mutation, and again after that action's complete readback before the next persistent mutation. Repeat it immediately before and immediately after the sole isolated-`TX` save. For each later read-only phase, repeat the complete package before and after the entity/protection readback using only that phase's independently and freshly returned role and exact opened path: saved-TX `DB_VERIFY`, promoted-CANON `DB_FINAL`, failed/ambiguous promoted-CANON `DB_ROLLBACK` when recovery is required, and restored-CANON `DB_RESTORE` after physical restoration. Repeat the physical/runtime boundary proof at pre-promotion and final canonical-persistence checkpoints. `BACKUP` is never opened or attested as a database; it remains only the sealed physical restoration source. Any absent, stale, partial, changed, or mismatched package stops before the protected operation; no earlier attestation, successful action, cache refresh, save response, filesystem receipt, or readback carries authority across a boundary.

Across the complete success/recovery protocol, the database-role namespace contains exactly five pairwise-distinct, freshly returned roles and no extras: `DB` mutates and saves isolated `TX`; `DB_VERIFY` reopens saved `TX` read-only; `DB_FINAL` opens promoted `CANONICAL` read-only; failure-only `DB_ROLLBACK` opens failed or ambiguous promoted `CANONICAL` read-only solely for complete failed-state classification; and `DB_RESTORE` opens restored `CANONICAL` read-only solely for original-baseline proof. Bind each role only from the nonempty `session.session_id` freshly returned by its successful literal current-schema open of that authorized path, and require every returned ID to differ from all other role IDs. `DB_ROLLBACK` and `DB_RESTORE` remain unbound on a successful path and may not be pre-opened, borrowed, or consumed by another phase. No sixth, auxiliary, default, remembered, aliased, or substituted database role is permitted. `BACKUP` is a sealed physical file only and is never opened as `DB`, `DB_VERIFY`, `DB_FINAL`, `DB_ROLLBACK`, `DB_RESTORE`, or any other database role.

Save is one exact public operation and is outside the 196-request topology. After all I01-I49 results and protections pass and the fresh pre-save package succeeds, issue exactly one literal `idb_save({database:DB,path:TX})`. The required current-schema result is an object `{ok,error?,path}` with `ok:true`, absent or exactly empty `error`, and a required nonempty `path` whose normalized absolute value equals exact `TX`. Any `ok:false`, absent/null/empty/different path, nonempty error, unexpected shape, timeout, or ambiguous response is a save failure; do not retry in place. No save may name `CANONICAL` or `BACKUP`, and no other session or default path may substitute for `DB`/`TX`.

The save result is not physical persistence proof. Immediately after the accepted response, while `DB` still names the isolated mutation route, pass the fresh post-save package, flush and close every transaction handle, then independently normalize/stat/hash the regular file at exact `TX`. Bind the separate filesystem receipt as nonzero `TX_SAVED_SIZE` and 64-hex `TX_SAVED_SHA256`, require exact path/size/hash stability on a second physical read, and separately prove `CANONICAL` and `BACKUP` still equal `CANON_BASE_SIZE`/`CANON_BASE_SHA256`. The runtime path and save-response path may establish path equality but never supply the size/hash. After that verified save, retire the exact mutation redirector/worker route, prove its PID/creation identity and active `DB`/`TX` claim absent, and require a successful exclusive-handle probe before any verifier or physical promotion step.

The persistence verifier is a separately returned read-only role. Reopen exact saved `TX` with the same literal current-schema `idb_open` shape and `run_auto_analysis:false`; require `success:true`, no error, exact returned `session.input_path == TX`, and a nonempty freshly returned `session.session_id` distinct from `DB` and from every later returned `DB_FINAL`, `DB_ROLLBACK`, or `DB_RESTORE` ID, then bind only it as `DB_VERIFY`. `DB_VERIFY` may call no mutation, cache-changing repair, save, promotion, or inverse action. Fresh public `tools/list` and the complete role-specific package for `runtime_attestation({expected_database:DB_VERIFY,expected_canonical_path:TX})`, independently retaining top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, must pass before and after a complete persistence readback through `database:DB_VERIFY`. That readback must reproduce every I01-I49 expected persisted/public name, exact FR/FP comment, exact TC-I01..TC-I49 fresh-decompiler/public presentation, and every PF/P01-P04 protected type, frame, byte/range/hash, AR/AP, xref, vtable/RTTI/head, neighbor, raw-nonfunction, and no-action state. Separate filesystem reads before and after must both report exact path `TX`, `TX_SAVED_SIZE`, and `TX_SAVED_SHA256`.

The pre-promotion gate is a four-observation physical and entity identity gate, not a database-role count. Immediately before any promotion, rerun the complete `DB_VERIFY`/`TX` package and full entity/protection readback, then obtain four distinct observations without inferring one from another: exact `CANONICAL` must still have `CANON_BASE_SIZE`/`CANON_BASE_SHA256`; exact distinct `BACKUP` must still have the same immutable preflight identity; physical exact `TX` must still have `TX_SAVED_SIZE`/`TX_SAVED_SHA256`; and `DB_VERIFY` must still report exact opened path `TX`, complete expected entity/protection state, and separate before/after filesystem observations equal to the saved-TX identity. `CANONICAL`, `BACKUP`, and `TX` remain three distinct physical paths; the verifier's path equality to `TX` is the required fourth observation, not a fourth copy or database role. Any path, size, hash, attestation, route, entity, comment, presentation, or protection mismatch forbids promotion.

Physical promotion is supervisor-owned and may not use the mutation or verifier worker. After the four-observation gate, close and retire `DB_VERIFY`, prove both mutation and verifier routes/PIDs inactive and no active route owns `DB`, `DB_VERIFY`, `TX`, or `CANONICAL`, pass exclusive-handle probes, preserve `BACKUP`, and freshly recheck all gated filesystem identities. The exact-parent sealed promotion-candidate contract is indivisible: choose one exclusive collision-checked `PROMOTION_CANDIDATE` whose normalized parent and volume are exactly those of `CANONICAL`, whose path is absent before creation, and whose path is distinct from `CANONICAL`, `BACKUP`, `TX`, and the separately named restoration candidate; reject reparse/symlink/junction components, hardlink count other than one, final-path alias, named ADS, non-regular state, or file-ID collision; copy it only from verified saved `TX`; invoke built-in `FileStream.Flush(true)` on that candidate; close every source/candidate/proof handle; and independently reopen the candidate read-only to require exact normalized/final path, parent/root/volume, regular attributes/reparse tag, volume/file ID, hardlink count, stream list, `TX_SAVED_SIZE`, and `TX_SAVED_SHA256`. Immediately before replacement, a fresh expected-current guard must reproduce the complete baseline `CANONICAL` tuple, saved-TX tuple, sealed-BACKUP tuple, candidate tuple, same-parent/same-volume relationship, closed-handle state, and absence of every other promotion/restoration/probe artifact, with no intervening operation permitted. Invoke the single approved built-in `System.IO.File.Replace` operation once with source `PROMOTION_CANDIDATE`, destination `CANONICAL`, null backup name, and metadata-error ignoring disabled; never retry. TX remains source-preserved. Success requires the candidate path absent, no API-created backup or second artifact, and two independent closed/reopened post-operation `CANONICAL` receipts equal to `TX_SAVED_SIZE`/`TX_SAVED_SHA256`, the expected candidate volume/file identity, one hardlink, no reparse/alias/named stream, while `BACKUP` and `TX` remain exact. No containing-directory flush is attempted or credited; operational persistence is established only by the required pre-replacement file flush, successful built-in atomic replacement, and complete post-operation receipts. Never save a live database directly to canonical and never promote through an open worker. Preserve both `BACKUP` and `TX` through final canonical verification; no cleanup is part of promotion.

Failure handling is phase-specific. Before the save request, any failure saves nothing, retires the isolated route, leaves `CANONICAL` and `BACKUP` at their immutable preflight identities, and permits only supervisor-authorized quarantine or discard of `TX` after closed-route/exclusive-handle proof. A failed, timed-out, malformed, or ambiguous save response is treated as unknown TX state: do not retry or reuse `DB`; pass no promotion gate, retire the route, separately prove canonical/backup unchanged, and quarantine TX with all receipts or discard it only under supervisor authority. Any accepted-save, physical-TX, post-save package, `DB_VERIFY`, entity/protection, or pre-promotion mismatch likewise promotes nothing, retires every opened TX role, and leaves canonical/backup unchanged. Pre-promotion failure classification may use only physical/read-only filesystem diagnostics and any already-open `DB` or `DB_VERIFY` evidence before those routes are retired; it must not open or consume `DB_FINAL`, `DB_ROLLBACK`, `DB_RESTORE`, reuse another one of the five roles, or create an extra database role. Quarantine or discard of `TX` remains supervisor-authorized and occurs only after route retirement, exclusive-handle proof, and the immutable canonical/backup receipts.

Once guarded canonical replacement begins, a failure is post-promotion unless independent receipts prove replacement did not occur and `CANONICAL` still has its exact baseline identity. On any ambiguous replacement or failed promoted-canonical/final proof, first retire every failed `DB_FINAL` or other canonical route that exists, close all canonical handles, and take separate failed-CANON normalized path/size/SHA256/volume-file-identity/link/reparse/stream receipts. Then freshly open exact failed or ambiguous promoted `CANONICAL` read-only with the literal current-schema shape, bind only its new pairwise-distinct returned ID as classification-only `DB_ROLLBACK`, and pass the complete role-specific package for `runtime_attestation({expected_database:DB_ROLLBACK,expected_canonical_path:CANONICAL})` before and after complete classification of every I01-I49 entity/name/comment/presentation and PF/P01-P04 protected state. `DB_ROLLBACK` may issue no mutation or save; retire it and prove its route/PID/session claims absent before restoration. Never open `BACKUP` as a database. Reprove sealed physical `BACKUP` through its complete baseline tuple at exact path, `CANON_BASE_SIZE`, and `CANON_BASE_SHA256`. The exact-parent sealed restoration-candidate contract is separate and indivisible: reprove the approved built-in primitive route is still available and policy-permitted; choose one exclusive collision-checked `RESTORE_CANDIDATE` whose normalized parent and volume are exactly those of `CANONICAL`, whose path is absent before creation, and whose path is distinct from `PROMOTION_CANDIDATE`, `CANONICAL`, `BACKUP`, and `TX`; reject every reparse/symlink/junction, hardlink, alias, ADS, non-regular, or identity collision; copy it only from verified physical `BACKUP`; invoke built-in `FileStream.Flush(true)` on that candidate; close every backup-source/candidate/proof handle; and independently reopen it to require the complete exact-parent physical tuple plus `CANON_BASE_SIZE`/`CANON_BASE_SHA256`. Immediately before restoration, reprove failed-CANON expected-current identity, sealed `BACKUP`, the restoration candidate, closed handles, same parent/volume, and no other candidate/probe residue. Invoke the same approved built-in `System.IO.File.Replace` operation once with source `RESTORE_CANDIDATE`, destination `CANONICAL`, null backup name, and metadata-error ignoring disabled; never retry and never use another primitive. `BACKUP` remains source-preserved. Success requires the candidate absent, no API-created backup/second artifact, and two independent closed/reopened `CANONICAL` receipts equal to the complete baseline path/size/SHA256/volume-file-identity/link/reparse/stream contract while sealed `BACKUP` remains unchanged. No containing-directory flush is attempted or credited. Only then freshly open restored `CANONICAL` read-only, bind only its new pairwise-distinct returned ID as `DB_RESTORE`, pass the complete role-specific package for `runtime_attestation({expected_database:DB_RESTORE,expected_canonical_path:CANONICAL})` before and after the complete original-baseline I01-I49 and PF/P01-P04 readback, repeat restored-canonical and backup filesystem receipts, and retire `DB_RESTORE`. Any unavailable, access-denied, unsupported, policy-blocked, ambiguous, classification, candidate, restore, package, entity/protection, route-retirement, residue, or physical mismatch remains a hard stop, grants no Gate 2B credit, preserves `BACKUP`, and is never reported as restored or successful.

Final promoted persistence requires a new read-only canonical session after the immediate promoted-canonical physical receipt passes. Open exact `CANONICAL` with the literal current-schema `idb_open` shape, require `success:true`, no error, exact returned `session.input_path == CANONICAL`, and a nonempty freshly returned session ID pairwise distinct from `DB`, `DB_VERIFY`, and every later failure-only `DB_ROLLBACK` or restored-CANON `DB_RESTORE` ID; bind only it as `DB_FINAL`. `DB_FINAL` may issue no mutation or save endpoint. Fresh public `tools/list` and the complete package for `runtime_attestation({expected_database:DB_FINAL,expected_canonical_path:CANONICAL})`, independently retaining top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, must pass before and after the same complete I01-I49 entity/comment/presentation and PF/P01-P04 protection readback required of `DB_VERIFY`. Separate filesystem reads before and after must show exact path `CANONICAL`, exact `TX_SAVED_SIZE`, and exact `TX_SAVED_SHA256`; `BACKUP` must remain exact at the immutable preflight identity and `TX` must remain exact at the saved identity. Retire the final read-only route, repeat the canonical/backup/TX physical receipts, and prove no active writable or mutation route remains. Only this exact path-size-hash proof plus the expected entity/protection proof establishes final canonical persistence; only after it passes may the supervisor consider later `BACKUP`/`TX` cleanup. Any `DB_FINAL` or final physical/readback failure enters only the failed-CANON `DB_ROLLBACK` then physical-BACKUP restoration and restored-CANON `DB_RESTORE` sequence above.

No mutation, save, verifier, classification, restore, promotion, or final-persistence operation proceeds on a stale package, stale filesystem receipt, open retired-role handle, or remembered/substituted session/path. The database-role namespace remains closed to exactly `DB`, `DB_VERIFY`, `DB_FINAL`, failure-only `DB_ROLLBACK`, and restored-CANON `DB_RESTORE`; every authorized open returns a fresh ID pairwise distinct from every other returned role ID, and any extra role hard-stops. No role inherits another role's authority, no read-only role gains mutation/save authority, and no filesystem size/SHA256 is attributed to `runtime_attestation`. `BACKUP` remains only the sealed physical restoration source and is never opened as a database.

~~~

## Removed Block 002

Rejected-artifact location: Rejected report line 14.

~~~text
- Supervisor-owned IDA handoff: only after Section 21's physical startup and exact-parent disposable replacement-primitive probe pass, and after the `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and complete fail-closed public runtime package succeed, three TextBox-local applying entities plus 46 selected-unit source-label entities each use four ordered, self-contained literal public requests whose top-level `database` is that exact returned `DB` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`), for 49 entities and 196 requests total. The package has two status-bearing levels: top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`; the listener has no local `ok` or `errors` fields, whose absence is expected rather than failure, and instead must pass complete role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation. Missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. The same complete package is freshly repeated at every Section 21 mutation, save, verifier, rollback/discard, restore, and final canonical-persistence boundary, with each listener/worker module identity sealed to its own role-specific baseline and separate filesystem receipts supplying every physical size/SHA256. After the 196 requests pass, the sole save is literal `idb_save({database:DB,path:TX}) -> {ok,error?,path}`; its accepted result, physical saved-TX receipt, retired mutation route, independent `DB_VERIFY`, four-observation pre-promotion gate, supervisor-owned safe physical replacement, and final read-only `DB_FINAL` entity/protection/path-size-hash proof remain outside and do not alter that topology. Section 21 binds each entity to an exact persisted-type/decompiler/public-presentation contract; the only cache operation is the one-function refresh between rename and fresh decompile, and no type/frame/data/UDT/general-analysis action is recommended. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 003

Rejected-artifact location: Rejected report line 59.

~~~text
- Preserve all persisted IDB function types, frames, bytes, interior address comments, xrefs, vtable heads, RTTI, and named types. The persistence handoff remains proposed and authorizes no IDA mutation until Section 21's exact-parent disposable built-in-operation probe passes through the approved supervisor route. Apply only the 49 source-quality names, 49 exact-entry cache refreshes, and exact FR/FP comments through 196 deterministic, self-contained literal requests whose top-level `database` value is the exact `DB` returned by Section 21 `idb_open(input_path:TX)` for a verified byte-identical isolated transaction copy; require Section 21's complete fresh public runtime package before every persistent mutation and every save/verifier/rollback/discard/restore/final-persistence boundary. That package independently requires top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, fails closed. Seal listener and worker modules to their own role-specific baselines, and obtain every physical IDB size/SHA256 from separate filesystem receipts. After all entity results pass, require the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` contract, physical saved-TX verification, retired mutation/verifier routes, the four-observation pre-promotion identity gate, safe supervisor physical replacement, phase-specific no-promotion/restore handling, and final read-only canonical entity/protection/path-size-hash proof. Accept only each item's exact fresh-decompiler/public presentation forms, and keep raw non-function heads protected with no `define_func` action. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 004

Rejected-artifact location: Rejected report line 77.

~~~text
- Dated supervisor persistence-capability receipt `2026-08-22`: the supported directory-handle `FlushFileBuffers` route returned `Access is denied`, and a custom write-through interop attempt was policy-blocked before execution. Neither branch mutated `CANONICAL`, `BACKUP`, `TX`, or IDA, and neither supplies durability credit. Fresh B009 read-only local runtime inspection found Windows PowerShell `5.1.19041.7548`, CLR `4.0.30319.42000`, both built-in `System.IO.File.Replace` overloads, and both built-in `System.IO.FileStream.Flush` overloads including `Flush(Boolean)`; B009 invoked no file-replacement or target-file write. Section 21 therefore removes directory flushing and custom interop from the normative path, requires a supervisor-executed disposable exact-parent probe of the approved built-in operations before any IDA mutation, and grants no Gate 2B credit until that probe and the complete final path pass.
~~~

## Removed Block 005

Rejected-artifact location: Rejected report line 78.

~~~text
- Transaction authority is deliberately separate from all dated sessions above. Before any Gate 2B preflight or mutation, the supervisor must create and verify a durable canonical backup, create and verify a byte-identical isolated transaction copy, bind their exact normalized paths as `BACKUP` and `TX`, and record separate canonical/backup/TX filesystem path-size-SHA256 receipts, then pass Section 21's exact-parent disposable built-in-operation probe before `idb_open` or any IDA mutation; the canonical IDB and remembered/current canonical sessions are read-only evidence and backup sources only. Section 21 then calls current-schema `idb_open(input_path:TX)` and requires `success:true`, no error, returned `session.input_path == TX`, and a nonempty returned `session.session_id`; only that returned session ID is bound as `DB`. Before any I01-I49 guard or action, public `runtime_attestation(DB,TX)` must independently pass top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, plus the complete literal listener nonce/generation/PID/port-owner and exact worker/session/path/redirector/parent-route package; missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. Listener and worker loaded-module rows/manifests must each match and remain sealed to its own accepted role-specific baseline, never each other. Fresh public `tools/list` must prove exactly one public `runtime_attestation`, no advertised or invoked `runtime/attest`, and the current `idb_save({database:DB,path:TX}) -> {ok,error?,path}` schema. The same fresh package is repeated at every persistent mutation, sole isolated-TX save, post-save verifier, rollback/discard, restore, and final canonical-persistence boundary; runtime proof never substitutes for the separate physical receipts, independent `DB_VERIFY`, pre-promotion gate, safe replacement, or final `DB_FINAL` entity/protection/path-size-hash proof. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 006

Rejected-artifact location: Rejected report line 116.

~~~text
| Physical durability primitive? | The supported directory-handle flush returned `Access is denied`; custom write-through interop was policy-blocked before execution. Built-in CLR `System.IO.File.Replace` and `FileStream.Flush(Boolean)` are present, but B009 did not execute a target or disposable physical probe. | Exclude directory flush/custom interop, require Section 21's exact-parent disposable built-in-operation probe before any IDA mutation, and grant zero Gate 2B credit on unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitives. The detailed action package is not physically implementation-ready until the supervisor passes that probe. |
~~~

## Removed Block 007

Rejected-artifact location: Rejected report line 141.

~~~text
For C0000OJ-058..060, C0000OJ-066, and C0000OJ-513..559, `no type mutation` and `no type endpoint` mean the persisted IDB function type `P` remains exact. Before any matching row can authorize an IDA mutation, Section 21's exact-parent disposable built-in `FileStream.Flush(true)`/`System.IO.File.Replace` probe must pass through the same approved supervisor route; an unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive hard-stops before mutation and grants no Gate 2B credit. Each row incorporates the Section 21 isolated-copy startup `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)`, the complete indivisible public listener/worker/process/route/module/tool-surface package with separate role-specific module baselines, and its fresh repetition at every persistent mutation, save, verifier, rollback/discard, restore, and final canonical-persistence boundary. The package independently requires top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops every matching row. It also incorporates the exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` result contract, separate filesystem receipts, route retirement, independent `DB_VERIFY`, four-observation pre-promotion gate, safe supervisor physical replacement, phase-specific restore handling, and final read-only `DB_FINAL` entity/protection/path-size-hash proof. Every matching action/cache request and read-only guard remains bound to the exact returned `DB`; each row retains the TC-Ixx fresh decompiler form `D`, permitted public `inspect_items.type` form `P`/`E`, and hard-stop/unsaved-discard conditions. Read-only `inspect_items`/`decompile` guards, runtime packages, save, verifier, promotion/restore, and persistence checks are not additional action stages, and these phrases do not assert byte-for-byte stability of a refreshable presentation string. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 008

Rejected-artifact location: Rejected report line 4925.

~~~text
For C0000OJ-058..060, C0000OJ-066, and C0000OJ-513..559, `no type mutation` and `no type endpoint` mean the persisted IDB function type `P` remains exact. Before any matching row can authorize an IDA mutation, Section 21's exact-parent disposable built-in `FileStream.Flush(true)`/`System.IO.File.Replace` probe must pass through the same approved supervisor route; an unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive hard-stops before mutation and grants no Gate 2B credit. Each row incorporates the Section 21 isolated-copy startup `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)`, the complete indivisible public listener/worker/process/route/module/tool-surface package with separate role-specific module baselines, and its fresh repetition at every persistent mutation, save, verifier, rollback/discard, restore, and final canonical-persistence boundary. The package independently requires top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops every matching row. It also incorporates the exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` result contract, separate filesystem receipts, route retirement, independent `DB_VERIFY`, four-observation pre-promotion gate, safe supervisor physical replacement, phase-specific restore handling, and final read-only `DB_FINAL` entity/protection/path-size-hash proof. Every matching action/cache request and read-only guard remains bound to the exact returned `DB`; each row retains the TC-Ixx fresh decompiler form `D`, permitted public `inspect_items.type` form `P`/`E`, and hard-stop/unsaved-discard conditions. Read-only `inspect_items`/`decompile` guards, runtime packages, save, verifier, promotion/restore, and persistence checks are not additional action stages, and these phrases do not assert byte-for-byte stability of a refreshable presentation string. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 009

Rejected-artifact location: Rejected report line 1774.

~~~text
Normative stage rule: the rename prestate must match the literal physical frame and exact `P`; pure rename may change only the persisted/public name and must leave FR/FP absent. The next exact-entry `force_recompile` must return `summary:{total:1,ok:1,failed:0,all:false}` and exactly one result with the literal address, desired name, `ok:true`, and no `error`. A fresh post-refresh `decompile` must render exact `D`, and fresh public `inspect_items` must retain the desired name with type exact `P` or exact `E` only; when `E` is `same as P`, no second spelling is permitted. FR and FP stages must preserve that refreshed presentation and every protected field while changing only their accepted comment channel. Hard stop before FR, before FP, and before save if any request/result/readback differs; if stale pre-rename pseudocode remains; if calling convention, return type, arity, function boundary, bytes/hash, frame, AR, AP, xrefs, neighboring item, or collision state differs; or if a type/frame/data/UDT/general-analysis endpoint would be required. Discard the transaction unsaved on every failure; no `set_type` or broad analysis request is added.
~~~

## Removed Block 010

Rejected-artifact location: Rejected report line 4516.

~~~text
- Supervisor Gate 2B remains limited to the isolated-copy-bound 49-entity rename/exact-entry-refresh/FR/FP handoff: only after Section 21's physical startup and exact-parent disposable built-in-operation probe pass, followed by `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and Section 21's complete public listener/worker/process/route/module/tool-surface package succeed, including independent top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, with listener and worker each sealed to its own role-specific module baseline, apply 196 ordered, self-contained literal requests and all read-only guards through that exact returned `DB`. Missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. Repeat the full fresh package at every persistent mutation, sole isolated-TX save, post-save verifier, rollback/discard, restore, and final canonical-persistence boundary without changing the 196-request topology. After the entity/protection results pass, require literal `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success, separate saved-TX filesystem receipts, retired mutation route, independent read-only `DB_VERIFY`, the canonical/backup/TX/verifier pre-promotion identity gate, safe supervisor-only physical replacement after route retirement, phase-specific failure/backup restore, and final read-only `DB_FINAL` exact entity/protection and canonical path-size-hash proof before cleanup. Corrected I01-I03 hashes, I03 `arg_8@+2c:1 _BYTE` protection, and exact TC-I01..TC-I49 persisted/fresh-decompiler/public presentation contracts remain mandatory; persisted I03 type retains `char`, formal source retains `bool blackBackground`, and type/frame/data/UDT/general-analysis endpoints remain prohibited. Manual coverage and lifecycle remain supervisor-owned. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 011

Rejected-artifact location: Rejected report line 4689.

~~~text
3. Supervisor restarts Gate 2B from the beginning for C0000OJ-058..066 and C0000OJ-513..559: create/verify the durable backup and byte-identical isolated transaction copy, bind exact normalized `BACKUP`/`TX` paths, record separate canonical/backup/TX filesystem size/SHA256 receipts, then execute and close Section 21's exact-parent disposable built-in `FileStream.Flush(true)`/`System.IO.File.Replace` probe with complete no-residue proof; only after that succeeds require literal current-schema `idb_open` success and exact returned `session.input_path`, bind only the nonempty returned `session.session_id` as `DB`, and pass Section 21's complete public `runtime_attestation(DB,TX)` package before any preflight or mutation. That package independently requires top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. It separately closes listener nonce/generation/PID/`127.0.0.1:13337` ownership, exact DB/TX worker route and redirector/registered-worker parent chain, each role's loaded-module rows and manifest against its own accepted role-specific baseline, and fresh public `tools/list` proof of exactly one `runtime_attestation`, no advertised/invoked `runtime/attest`, and the current save schema; no cross-role manifest equality or runtime-supplied file identity is permitted. Then use the exact 49-entity/196-request handoff with every action/read guard's top-level `database` equal to returned mutation `DB`; I03 PF/S009-S012 protect `_BYTE`; every pure rename must first read back the desired persisted/public name, then its exact-entry `force_recompile` must return one successful non-global result, and only the following fresh decompile may satisfy matching TC-I01..TC-I49 `D`; FR/FP follow only after that guard, and all raw heads and other protected states remain immutable. After all results pass, perform only the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success contract, separate saved-TX path-size-hash receipt, mutation-route retirement, independent read-only `DB_VERIFY` complete readback, four-observation pre-promotion physical/entity gate, the complete exact-parent sealed promotion-candidate contract after closing verifier, immediate canonical physical receipt, and final separately returned read-only `DB_FINAL` complete entity/protection plus exact canonical path-size-hash proof. Any pre-promotion failure leaves canonical/backup unchanged, retires or quarantines/discards TX under physical/read-only diagnostics, and opens no `DB_ROLLBACK` or extra role. Any ambiguous or failed post-promotion final proof first retires failed `DB_FINAL`/canonical routes, takes failed-CANON receipts, opens failed/ambiguous promoted `CANONICAL` read-only only as `DB_ROLLBACK` for complete I01-I49 and PF/P01-P04 classification, retires it, restores physically only from verified `BACKUP`, and opens restored `CANONICAL` read-only only as `DB_RESTORE` for complete original-baseline proof. Backup/TX cleanup is considered only after final persistence passes; lifecycle remains stopped until then. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path.
~~~

## Removed Block 012

Rejected-artifact location: Rejected report line 4698.

~~~text
- Persistence readiness: the source-quality action package is detailed but the physical handoff is not implementation-ready or creditable from prose alone. Confidence in promotion/restoration remains conditional on the supervisor's fresh exact-parent disposable probe and complete built-in replacement/readback path; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive is a hard stop.
~~~

## Removed Block 013

Rejected-artifact location: Rejected report line 4821.

~~~text
- Historical report-only Gate 1 repair changed only report evidence. It preserved the prior Section 21 persisted-type/presentation separation, literal target/support enumeration, compatible identity reconciliation, exact five-role persistence protocol, physical-only `BACKUP`, and the two complete promotion/restoration candidate contracts. The dated Gate 2A callback cycle and this report-only reconciliation do not alter any of those contracts.
~~~

## Removed Block 014

Rejected-artifact location: C0000OJ-058 ledger/checklist row at rejected report line 202.

~~~text
| C0000OJ-058 | 0002RU | I01: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I01 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x591300`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 106-byte exact-range SHA256 `94F6EC80064442BAF6E5A420211B5F66F094AEA8B2B5875FD18057D4F4F3CB71`; complete literal physical prestate/readbacks plus exact-entry `force_recompile` and TC-I01 persisted/fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I01 | incorporate | proposed |
~~~

## Removed Block 015

Rejected-artifact location: C0000OJ-059 ledger/checklist row at rejected report line 203.

~~~text
| C0000OJ-059 | 0002RU | I02: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I02 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x591370`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 137-byte exact-range SHA256 `94E51691B7BBA914E1CFB76CA93E2041D5A56ED6C89CB5ED5DA438C78081FE6D`; complete literal physical prestate/readbacks plus exact-entry `force_recompile` and TC-I02 persisted/fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I02 | incorporate | proposed |
~~~

## Removed Block 016

Rejected-artifact location: C0000OJ-060 ledger/checklist row at rejected report line 204.

~~~text
| C0000OJ-060 | 0002RV | I03: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I03 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x595390`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 291-byte SHA256 `FC01258F12B2AC7D00C68EFA36E3F5814092B50A256697D65B27DEC374973B2E`; protected `arg_8@+2c:1 _BYTE` frame storage, persisted unnamed-`char` type, and exact-entry `force_recompile` plus TC-I03 fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I03 | incorporate | proposed |
~~~

## Removed Block 017

Rejected-artifact location: C0000OJ-066 ledger/checklist row at rejected report line 210.

~~~text
| C0000OJ-066 | 0000OJ | After the isolated-copy startup `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and complete role-specific public runtime package succeed, including independent top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, bind all 49 applying entities to exactly 196 ordered, self-contained literal public action/cache requests, each with top-level `database:DB` using that exact returned session ID. Any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. After every result/protection passes, require the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success, separate physical saved-TX receipt, mutation-route retirement, independent read-only `DB_VERIFY`, four-observation pre-promotion physical/entity gate, supervisor safe physical replacement, phase-specific no-promotion/restore handling, and final read-only `DB_FINAL` expected entity/protection/path-size-hash proof, all without adding an action stage. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | original-proof | Corrected I01-I03 hashes, I03 `arg_8@+2c:1 _BYTE` frame protection, and 49 exact TC-I01..TC-I49 persisted/exact-entry-refresh/fresh-decompiler/public presentation contracts; 49 rename, 49 exact-entry `force_recompile`, 49 FR, and 49 FP requests, each bound to returned `DB`. Section 21 requires independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, exactly one public attestation tool, no `runtime/attest`, current save schema, listener/worker module rows sealed separately to role-specific baselines, and filesystem rather than runtime size/SHA256 receipts; read-only guards, runtime packages, save, verifier, promotion/restore, and final persistence checks are uncounted. | IDA handoff stage ledger | incorporate | proposed |
~~~

## Removed Block 018

Rejected-artifact location: C0000OJ-513 ledger/checklist row at rejected report line 657.

~~~text
| C0000OJ-513 | 0000OJ | Apply the exact isolated-copy-bound 49-entity/196-request source-quality rename/exact-entry-refresh/FR/FP handoff: after `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and the complete role-specific public runtime package independently proves top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, three TextBox-local plus 46 selected-unit compiler-label entities use only that exact returned `DB` and every raw non-function head remains protected. Any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. After all 196 results pass, require the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success, separate saved-TX path-size-hash receipt, retired mutation route, independent `DB_VERIFY`, four-observation pre-promotion gate, safe supervisor physical promotion, phase-specific no-promotion/restore handling, and final read-only `DB_FINAL` complete entity/protection and canonical path-size-hash proof. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | original-proof | Dated canonical read-only rechecks supply all literal physical prestates/readbacks, including I03 `arg_8@+2c:1 _BYTE`; Section 21 supplies all 196 returned-`DB` requests (49 each rename/force_recompile/FR/FP), exact TC-I01..TC-I49 contracts, independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, exactly-one public attestation and no-internal-tool proof, role-specific module baselines, current save schema, separate physical receipts, independent verifier/promotion/restore/final-session gates, and no type/frame/data/general-analysis mutation. These boundary operations and same-`DB` read-only guards are not action stages. | IDA handoff/follow-up | already-present | proposed |
~~~

## Removed Block 019

Rejected-artifact location: C0000OJ-514 ledger/checklist row at rejected report line 658.

~~~text
| C0000OJ-514 | 0000OJ | Supervisor applies I04's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsMaskedText`; require the matching TC-I04 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e260,58e267)`, absent FR/FP, absent desired-name collision, and immutable C083 physical protection. | Section 21 I04 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 020

Rejected-artifact location: C0000OJ-515 ledger/checklist row at rejected report line 659.

~~~text
| C0000OJ-515 | 0000OJ | Supervisor applies I05's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__InsertText`; require the matching TC-I05 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e270,58e2a2)`, absent FR/FP, absent desired-name collision, and immutable C084 physical protection. | Section 21 I05 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 021

Rejected-artifact location: C0000OJ-516 ledger/checklist row at rejected report line 660.

~~~text
| C0000OJ-516 | 0000OJ | Supervisor applies I06's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DeleteTextRangeAndClampSelection`; require the matching TC-I06 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e2b0,58e314)`, absent FR/FP, absent desired-name collision, and immutable C085 physical protection. | Section 21 I06 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 022

Rejected-artifact location: C0000OJ-517 ledger/checklist row at rejected report line 661.

~~~text
| C0000OJ-517 | 0000OJ | Supervisor applies I07's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DecodeState`; require the matching TC-I07 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e6a0,58e880)`, absent FR/FP, absent desired-name collision, and immutable C090 physical protection. | Section 21 I07 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 023

Rejected-artifact location: C0000OJ-518 ledger/checklist row at rejected report line 662.

~~~text
| C0000OJ-518 | 0000OJ | Supervisor applies I08's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextLength`; require the matching TC-I08 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e880,58e88b)`, absent FR/FP, absent desired-name collision, and immutable C091 physical protection. | Section 21 I08 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 024

Rejected-artifact location: C0000OJ-519 ledger/checklist row at rejected report line 663.

~~~text
| C0000OJ-519 | 0000OJ | Supervisor applies I09's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextOffsetAtPointXY`; require the matching TC-I09 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ea60,58ea74)`, absent FR/FP, absent desired-name collision, and immutable C093 physical protection. | Section 21 I09 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 025

Rejected-artifact location: C0000OJ-520 ledger/checklist row at rejected report line 664.

~~~text
| C0000OJ-520 | 0000OJ | Supervisor applies I10's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetTextColor`; require the matching TC-I10 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb30,58eb39)`, absent FR/FP, absent desired-name collision, and immutable C095 physical protection. | Section 21 I10 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 026

Rejected-artifact location: C0000OJ-521 ledger/checklist row at rejected report line 665.

~~~text
| C0000OJ-521 | 0000OJ | Supervisor applies I11's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__OnSelectionChanged`; require the matching TC-I11 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb40,58eb43)`, absent FR/FP, absent desired-name collision, and immutable C096 physical protection. | Section 21 I11 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 027

Rejected-artifact location: C0000OJ-522 ledger/checklist row at rejected report line 666.

~~~text
| C0000OJ-522 | 0000OJ | Supervisor applies I12's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DispatchNavigationKey`; require the matching TC-I12 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb50,58ebd3)`, absent FR/FP, absent desired-name collision, and immutable C097 physical protection. | Section 21 I12 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 028

Rejected-artifact location: C0000OJ-523 ledger/checklist row at rejected report line 667.

~~~text
| C0000OJ-523 | 0000OJ | Supervisor applies I13's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollRange`; require the matching TC-I13 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ebf0,58ec7a)`, absent FR/FP, absent desired-name collision, and immutable C099 physical protection. | Section 21 I13 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 029

Rejected-artifact location: C0000OJ-524 ledger/checklist row at rejected report line 668.

~~~text
| C0000OJ-524 | 0000OJ | Supervisor applies I14's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetOverflowCount`; require the matching TC-I14 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ec80,58ecd6)`, absent FR/FP, absent desired-name collision, and immutable C100 physical protection. | Section 21 I14 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 030

Rejected-artifact location: C0000OJ-525 ledger/checklist row at rejected report line 669.

~~~text
| C0000OJ-525 | 0000OJ | Supervisor applies I15's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetPageSize`; require the matching TC-I15 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ece0,58ed13)`, absent FR/FP, absent desired-name collision, and immutable C101 physical protection. | Section 21 I15 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 031

Rejected-artifact location: C0000OJ-526 ledger/checklist row at rejected report line 670.

~~~text
| C0000OJ-526 | 0000OJ | Supervisor applies I16's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollOffset`; require the matching TC-I16 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed20,58ed42)`, absent FR/FP, absent desired-name collision, and immutable C102 physical protection. | Section 21 I16 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 032

Rejected-artifact location: C0000OJ-527 ledger/checklist row at rejected report line 671.

~~~text
| C0000OJ-527 | 0000OJ | Supervisor applies I17's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetContentSize`; require the matching TC-I17 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed50,58ed77)`, absent FR/FP, absent desired-name collision, and immutable C103 physical protection. | Section 21 I17 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 033

Rejected-artifact location: C0000OJ-528 ledger/checklist row at rejected report line 672.

~~~text
| C0000OJ-528 | 0000OJ | Supervisor applies I18's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollDelta`; require the matching TC-I18 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed80,58edc5)`, absent FR/FP, absent desired-name collision, and immutable C104 physical protection. | Section 21 I18 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 034

Rejected-artifact location: C0000OJ-529 ledger/checklist row at rejected report line 673.

~~~text
| C0000OJ-529 | 0000OJ | Supervisor applies I19's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__UpdateRenderRegion`; require the matching TC-I19 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58edd0,58ee4e)`, absent FR/FP, absent desired-name collision, and immutable C105 physical protection. | Section 21 I19 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 035

Rejected-artifact location: C0000OJ-530 ledger/checklist row at rejected report line 674.

~~~text
| C0000OJ-530 | 0000OJ | Supervisor applies I20's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetMaxLength`; require the matching TC-I20 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ee50,58ee67)`, absent FR/FP, absent desired-name collision, and immutable C106 physical protection. | Section 21 I20 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 036

Rejected-artifact location: C0000OJ-531 ledger/checklist row at rejected report line 675.

~~~text
| C0000OJ-531 | 0000OJ | Supervisor applies I21's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetMaxLines`; require the matching TC-I21 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ee70,58ee87)`, absent FR/FP, absent desired-name collision, and immutable C107 physical protection. | Section 21 I21 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 037

Rejected-artifact location: C0000OJ-532 ledger/checklist row at rejected report line 676.

~~~text
| C0000OJ-532 | 0000OJ | Supervisor applies I22's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `MeasureWrappedTextHeight`; require the matching TC-I22 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves cdecl function `[58ee90,58ef57)` constructs/inserts/measures/deletes a temporary TextEditPane, absent FR/FP, absent desired-name collision, and immutable C108 physical protection. | Section 21 I22 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 038

Rejected-artifact location: C0000OJ-533 ledger/checklist row at rejected report line 677.

~~~text
| C0000OJ-533 | 0000OJ | Supervisor applies I23's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextBuffer`; require the matching TC-I23 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ef60,58ef6e)`, absent FR/FP, absent desired-name collision, and immutable C109 physical protection. | Section 21 I23 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 039

Rejected-artifact location: C0000OJ-534 ledger/checklist row at rejected report line 678.

~~~text
| C0000OJ-534 | 0000OJ | Supervisor applies I24's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetStoredTextLength`; require the matching TC-I24 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58efa0,58efab)`, absent FR/FP, absent desired-name collision, and immutable C110 physical protection. | Section 21 I24 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 040

Rejected-artifact location: C0000OJ-535 ledger/checklist row at rejected report line 679.

~~~text
| C0000OJ-535 | 0000OJ | Supervisor applies I25's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__MeasureTextRange`; require the matching TC-I25 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58efb0,58f049)`, absent FR/FP, absent desired-name collision, and immutable C111 physical protection. | Section 21 I25 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 041

Rejected-artifact location: C0000OJ-536 ledger/checklist row at rejected report line 680.

~~~text
| C0000OJ-536 | 0000OJ | Supervisor applies I26's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsSelectionVisible`; require the matching TC-I26 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f0c0,58f0c7)` returns byte `this[346]` (`m_selectionVisible +0x15a`), absent FR/FP, absent desired-name collision, and immutable C114 physical protection. | Section 21 I26 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 042

Rejected-artifact location: C0000OJ-537 ledger/checklist row at rejected report line 681.

~~~text
| C0000OJ-537 | 0000OJ | Supervisor applies I27's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetLineTextRange`; require the matching TC-I27 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f150,58f19e)`, absent FR/FP, absent desired-name collision, and immutable C116 physical protection. | Section 21 I27 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 043

Rejected-artifact location: C0000OJ-538 ledger/checklist row at rejected report line 682.

~~~text
| C0000OJ-538 | 0000OJ | Supervisor applies I28's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetFormatAtOffset`; require the matching TC-I28 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f630,58f686)`, absent FR/FP, absent desired-name collision, and immutable C122 physical protection. | Section 21 I28 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 044

Rejected-artifact location: C0000OJ-539 ledger/checklist row at rejected report line 683.

~~~text
| C0000OJ-539 | 0000OJ | Supervisor applies I29's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ApplySelectionFormat`; require the matching TC-I29 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58fef0,58ffd2)`, absent FR/FP, absent desired-name collision, and immutable C128 physical protection. | Section 21 I29 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 045

Rejected-artifact location: C0000OJ-540 ledger/checklist row at rejected report line 684.

~~~text
| C0000OJ-540 | 0000OJ | Supervisor applies I30's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsDirty`; require the matching TC-I30 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[590130,590137)`, absent FR/FP, absent desired-name collision, and immutable C129 physical protection. | Section 21 I30 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 046

Rejected-artifact location: C0000OJ-541 ledger/checklist row at rejected report line 685.

~~~text
| C0000OJ-541 | 0000OJ | Supervisor applies I31's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__CopySelectionToScrap`; require the matching TC-I31 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5901b0,590496)`, exact scrap-copy body, absent FR/FP, absent `TextEditPane__CopySelectionToScrap` collision, and immutable C130 physical protection. | Section 21 I31 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 047

Rejected-artifact location: C0000OJ-542 ledger/checklist row at rejected report line 686.

~~~text
| C0000OJ-542 | 0000OJ | Supervisor applies I32's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__CopyAllToClipboard`; require the matching TC-I32 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[590520,5905eb)`, exact full-buffer clipboard body, absent FR/FP, absent `TextEditPane__CopyAllToClipboard` collision, and immutable C132 physical protection. | Section 21 I32 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 048

Rejected-artifact location: C0000OJ-543 ledger/checklist row at rejected report line 687.

~~~text
| C0000OJ-543 | 0000OJ | Supervisor applies I33's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__EnforceMaxLength`; require the matching TC-I33 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[591180,5911f8)`, absent FR/FP, absent desired-name collision, and immutable C138 physical protection. | Section 21 I33 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 049

Rejected-artifact location: C0000OJ-544 ledger/checklist row at rejected report line 688.

~~~text
| C0000OJ-544 | 0000OJ | Supervisor applies I34's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__EnforceMaxLines`; require the matching TC-I34 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[591200,5912ad)`, absent FR/FP, absent desired-name collision, and immutable C139 physical protection. | Section 21 I34 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 050

Rejected-artifact location: C0000OJ-545 ledger/checklist row at rejected report line 689.

~~~text
| C0000OJ-545 | 0000OJ | Supervisor applies I35's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ApplySerializedFormatRuns`; require the matching TC-I35 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592090,592436)`, absent FR/FP, absent desired-name collision, and immutable C152 physical protection. | Section 21 I35 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 051

Rejected-artifact location: C0000OJ-546 ledger/checklist row at rejected report line 690.

~~~text
| C0000OJ-546 | 0000OJ | Supervisor applies I36's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DeleteFormatRange`; require the matching TC-I36 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5927e0,592993)`, absent FR/FP, absent desired-name collision, and immutable C154 physical protection. | Section 21 I36 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 052

Rejected-artifact location: C0000OJ-547 ledger/checklist row at rejected report line 691.

~~~text
| C0000OJ-547 | 0000OJ | Supervisor applies I37's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__RemoveFormatRun`; require the matching TC-I37 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592b60,592bab)`, absent FR/FP, absent desired-name collision, and immutable C155 physical protection. | Section 21 I37 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 053

Rejected-artifact location: C0000OJ-548 ledger/checklist row at rejected report line 692.

~~~text
| C0000OJ-548 | 0000OJ | Supervisor applies I38's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__MeasureLineBreak`; require the matching TC-I38 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592fb0,5931e0)`, absent FR/FP, absent desired-name collision, and immutable C158 physical protection. | Section 21 I38 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 054

Rejected-artifact location: C0000OJ-549 ledger/checklist row at rejected report line 693.

~~~text
| C0000OJ-549 | 0000OJ | Supervisor applies I39's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__InsertTextStorage`; require the matching TC-I39 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5931e0,59327f)`, absent FR/FP, absent desired-name collision, and immutable C159 physical protection. | Section 21 I39 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 055

Rejected-artifact location: C0000OJ-550 ledger/checklist row at rejected report line 694.

~~~text
| C0000OJ-550 | 0000OJ | Supervisor applies I40's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ShiftLineOffsets`; require the matching TC-I40 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[593400,593450)`, absent FR/FP, absent desired-name collision, and immutable C161 physical protection. | Section 21 I40 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 056

Rejected-artifact location: C0000OJ-551 ledger/checklist row at rejected report line 695.

~~~text
| C0000OJ-551 | 0000OJ | Supervisor applies I41's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ShiftFormatRunOffsets`; require the matching TC-I41 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[593450,5934a0)`, absent FR/FP, absent desired-name collision, and immutable C162 physical protection. | Section 21 I41 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 057

Rejected-artifact location: C0000OJ-552 ledger/checklist row at rejected report line 696.

~~~text
| C0000OJ-552 | 0000OJ | Supervisor applies I42's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__HitTestTextRunCallback`; require the matching TC-I42 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5936e0,593875)`, absent FR/FP, absent desired-name collision, and immutable C164 physical protection. | Section 21 I42 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 058

Rejected-artifact location: C0000OJ-553 ledger/checklist row at rejected report line 697.

~~~text
| C0000OJ-553 | 0000OJ | Supervisor applies I43's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__TextRunOffsetMeasureCallback`; require the matching TC-I43 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Dated canonical evidence proves function `[593a20,593b12)`, persisted IDB type `bool __cdecl(TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, __int16, signed __int16, signed __int16, _WORD *, GrafPort *)`, current public presentation with unsigned sixth parameter, exact TC-I43 decompiler form, C124's sole incoming data xref at `0x58f94e`, absent AR/AP/FR/FP, absent desired-name collision, and immutable C165 physical protection. | Section 21 I43 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 059

Rejected-artifact location: C0000OJ-554 ledger/checklist row at rejected report line 698.

~~~text
| C0000OJ-554 | 0000OJ | Supervisor applies I44's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DrawTextCharacters`; require the matching TC-I44 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5946b0,59489f)`, absent FR/FP, absent desired-name collision, and immutable C171 physical protection. | Section 21 I44 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 060

Rejected-artifact location: C0000OJ-555 ledger/checklist row at rejected report line 699.

~~~text
| C0000OJ-555 | 0000OJ | Supervisor applies I45's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__SetPayload`; require the matching TC-I45 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5950a0,5950dc)`, absent FR/FP, absent desired-name collision, and immutable C184 physical protection. | Section 21 I45 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 061

Rejected-artifact location: C0000OJ-556 ledger/checklist row at rejected report line 700.

~~~text
| C0000OJ-556 | 0000OJ | Supervisor applies I46's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__DuplicateText`; require the matching TC-I46 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5950e0,595138)`, absent FR/FP, absent desired-name collision, and immutable C185 physical protection. | Section 21 I46 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 062

Rejected-artifact location: C0000OJ-557 ledger/checklist row at rejected report line 701.

~~~text
| C0000OJ-557 | 0000OJ | Supervisor applies I47's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__DuplicatePayload`; require the matching TC-I47 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[595140,595193)`, absent FR/FP, absent desired-name collision, and immutable C186 physical protection. | Section 21 I47 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 063

Rejected-artifact location: C0000OJ-558 ledger/checklist row at rejected report line 702.

~~~text
| C0000OJ-558 | 0000OJ | Supervisor applies I48's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__SetFromClipboardBlock`; require the matching TC-I48 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[595250,595389)`, absent FR/FP, absent desired-name collision, and immutable C187 physical protection. | Section 21 I48 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 064

Rejected-artifact location: C0000OJ-559 ledger/checklist row at rejected report line 703.

~~~text
| C0000OJ-559 | 0000OJ | Supervisor applies I49's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `EPFTextEditObject__Constructor`; require the matching TC-I49 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5954c0,595590)`, absent FR/FP, absent desired-name collision, and immutable C189 physical protection. | Section 21 I49 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 065

Rejected-artifact location: C0000OJ-058 ledger/checklist row at rejected report line 4986.

~~~text
| [ ] | C0000OJ-058 | 0002RU | I01: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I01 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x591300`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 106-byte exact-range SHA256 `94F6EC80064442BAF6E5A420211B5F66F094AEA8B2B5875FD18057D4F4F3CB71`; complete literal physical prestate/readbacks plus exact-entry `force_recompile` and TC-I01 persisted/fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I01 | incorporate | proposed |
~~~

## Removed Block 066

Rejected-artifact location: C0000OJ-059 ledger/checklist row at rejected report line 4987.

~~~text
| [ ] | C0000OJ-059 | 0002RU | I02: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I02 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x591370`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 137-byte exact-range SHA256 `94E51691B7BBA914E1CFB76CA93E2041D5A56ED6C89CB5ED5DA438C78081FE6D`; complete literal physical prestate/readbacks plus exact-entry `force_recompile` and TC-I02 persisted/fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I02 | incorporate | proposed |
~~~

## Removed Block 067

Rejected-artifact location: C0000OJ-060 ledger/checklist row at rejected report line 4988.

~~~text
| [ ] | C0000OJ-060 | 0002RV | I03: after successful Section 21 `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` startup and a fresh complete public runtime package at each I03 persistent-mutation boundary independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, apply ordered pure rename, exact-entry cache refresh plus fresh decompile/public readback, FR, then FP calls at `0x595390`, all bound to that exact returned `DB`; any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. | very-strong | Fresh canonical 291-byte SHA256 `FC01258F12B2AC7D00C68EFA36E3F5814092B50A256697D65B27DEC374973B2E`; protected `arg_8@+2c:1 _BYTE` frame storage, persisted unnamed-`char` type, and exact-entry `force_recompile` plus TC-I03 fresh-decompiler/public presentation contract; canonical evidence cannot substitute for the isolated returned-`DB` transaction binding or complete repeated runtime proof. | IDA handoff I03 | incorporate | proposed |
~~~

## Removed Block 068

Rejected-artifact location: C0000OJ-066 ledger/checklist row at rejected report line 4994.

~~~text
| [ ] | C0000OJ-066 | 0000OJ | After the isolated-copy startup `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and complete role-specific public runtime package succeed, including independent top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, bind all 49 applying entities to exactly 196 ordered, self-contained literal public action/cache requests, each with top-level `database:DB` using that exact returned session ID. Any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. After every result/protection passes, require the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success, separate physical saved-TX receipt, mutation-route retirement, independent read-only `DB_VERIFY`, four-observation pre-promotion physical/entity gate, supervisor safe physical replacement, phase-specific no-promotion/restore handling, and final read-only `DB_FINAL` expected entity/protection/path-size-hash proof, all without adding an action stage. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | original-proof | Corrected I01-I03 hashes, I03 `arg_8@+2c:1 _BYTE` frame protection, and 49 exact TC-I01..TC-I49 persisted/exact-entry-refresh/fresh-decompiler/public presentation contracts; 49 rename, 49 exact-entry `force_recompile`, 49 FR, and 49 FP requests, each bound to returned `DB`. Section 21 requires independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, exactly one public attestation tool, no `runtime/attest`, current save schema, listener/worker module rows sealed separately to role-specific baselines, and filesystem rather than runtime size/SHA256 receipts; read-only guards, runtime packages, save, verifier, promotion/restore, and final persistence checks are uncounted. | IDA handoff stage ledger | incorporate | proposed |
~~~

## Removed Block 069

Rejected-artifact location: C0000OJ-513 ledger/checklist row at rejected report line 5441.

~~~text
| [ ] | C0000OJ-513 | 0000OJ | Apply the exact isolated-copy-bound 49-entity/196-request source-quality rename/exact-entry-refresh/FR/FP handoff: after `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and the complete role-specific public runtime package independently proves top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation, three TextBox-local plus 46 selected-unit compiler-label entities use only that exact returned `DB` and every raw non-function head remains protected. Any missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. After all 196 results pass, require the sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}` success, separate saved-TX path-size-hash receipt, retired mutation route, independent `DB_VERIFY`, four-observation pre-promotion gate, safe supervisor physical promotion, phase-specific no-promotion/restore handling, and final read-only `DB_FINAL` complete entity/protection and canonical path-size-hash proof. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | original-proof | Dated canonical read-only rechecks supply all literal physical prestates/readbacks, including I03 `arg_8@+2c:1 _BYTE`; Section 21 supplies all 196 returned-`DB` requests (49 each rename/force_recompile/FR/FP), exact TC-I01..TC-I49 contracts, independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, exactly-one public attestation and no-internal-tool proof, role-specific module baselines, current save schema, separate physical receipts, independent verifier/promotion/restore/final-session gates, and no type/frame/data/general-analysis mutation. These boundary operations and same-`DB` read-only guards are not action stages. | IDA handoff/follow-up | already-present | proposed |
~~~

## Removed Block 070

Rejected-artifact location: C0000OJ-514 ledger/checklist row at rejected report line 5442.

~~~text
| [ ] | C0000OJ-514 | 0000OJ | Supervisor applies I04's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsMaskedText`; require the matching TC-I04 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e260,58e267)`, absent FR/FP, absent desired-name collision, and immutable C083 physical protection. | Section 21 I04 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 071

Rejected-artifact location: C0000OJ-515 ledger/checklist row at rejected report line 5443.

~~~text
| [ ] | C0000OJ-515 | 0000OJ | Supervisor applies I05's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__InsertText`; require the matching TC-I05 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e270,58e2a2)`, absent FR/FP, absent desired-name collision, and immutable C084 physical protection. | Section 21 I05 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 072

Rejected-artifact location: C0000OJ-516 ledger/checklist row at rejected report line 5444.

~~~text
| [ ] | C0000OJ-516 | 0000OJ | Supervisor applies I06's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DeleteTextRangeAndClampSelection`; require the matching TC-I06 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e2b0,58e314)`, absent FR/FP, absent desired-name collision, and immutable C085 physical protection. | Section 21 I06 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 073

Rejected-artifact location: C0000OJ-517 ledger/checklist row at rejected report line 5445.

~~~text
| [ ] | C0000OJ-517 | 0000OJ | Supervisor applies I07's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DecodeState`; require the matching TC-I07 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e6a0,58e880)`, absent FR/FP, absent desired-name collision, and immutable C090 physical protection. | Section 21 I07 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 074

Rejected-artifact location: C0000OJ-518 ledger/checklist row at rejected report line 5446.

~~~text
| [ ] | C0000OJ-518 | 0000OJ | Supervisor applies I08's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextLength`; require the matching TC-I08 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58e880,58e88b)`, absent FR/FP, absent desired-name collision, and immutable C091 physical protection. | Section 21 I08 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 075

Rejected-artifact location: C0000OJ-519 ledger/checklist row at rejected report line 5447.

~~~text
| [ ] | C0000OJ-519 | 0000OJ | Supervisor applies I09's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextOffsetAtPointXY`; require the matching TC-I09 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ea60,58ea74)`, absent FR/FP, absent desired-name collision, and immutable C093 physical protection. | Section 21 I09 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 076

Rejected-artifact location: C0000OJ-520 ledger/checklist row at rejected report line 5448.

~~~text
| [ ] | C0000OJ-520 | 0000OJ | Supervisor applies I10's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetTextColor`; require the matching TC-I10 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb30,58eb39)`, absent FR/FP, absent desired-name collision, and immutable C095 physical protection. | Section 21 I10 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 077

Rejected-artifact location: C0000OJ-521 ledger/checklist row at rejected report line 5449.

~~~text
| [ ] | C0000OJ-521 | 0000OJ | Supervisor applies I11's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__OnSelectionChanged`; require the matching TC-I11 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb40,58eb43)`, absent FR/FP, absent desired-name collision, and immutable C096 physical protection. | Section 21 I11 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 078

Rejected-artifact location: C0000OJ-522 ledger/checklist row at rejected report line 5450.

~~~text
| [ ] | C0000OJ-522 | 0000OJ | Supervisor applies I12's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DispatchNavigationKey`; require the matching TC-I12 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58eb50,58ebd3)`, absent FR/FP, absent desired-name collision, and immutable C097 physical protection. | Section 21 I12 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 079

Rejected-artifact location: C0000OJ-523 ledger/checklist row at rejected report line 5451.

~~~text
| [ ] | C0000OJ-523 | 0000OJ | Supervisor applies I13's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollRange`; require the matching TC-I13 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ebf0,58ec7a)`, absent FR/FP, absent desired-name collision, and immutable C099 physical protection. | Section 21 I13 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 080

Rejected-artifact location: C0000OJ-524 ledger/checklist row at rejected report line 5452.

~~~text
| [ ] | C0000OJ-524 | 0000OJ | Supervisor applies I14's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetOverflowCount`; require the matching TC-I14 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ec80,58ecd6)`, absent FR/FP, absent desired-name collision, and immutable C100 physical protection. | Section 21 I14 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 081

Rejected-artifact location: C0000OJ-525 ledger/checklist row at rejected report line 5453.

~~~text
| [ ] | C0000OJ-525 | 0000OJ | Supervisor applies I15's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetPageSize`; require the matching TC-I15 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ece0,58ed13)`, absent FR/FP, absent desired-name collision, and immutable C101 physical protection. | Section 21 I15 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 082

Rejected-artifact location: C0000OJ-526 ledger/checklist row at rejected report line 5454.

~~~text
| [ ] | C0000OJ-526 | 0000OJ | Supervisor applies I16's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollOffset`; require the matching TC-I16 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed20,58ed42)`, absent FR/FP, absent desired-name collision, and immutable C102 physical protection. | Section 21 I16 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 083

Rejected-artifact location: C0000OJ-527 ledger/checklist row at rejected report line 5455.

~~~text
| [ ] | C0000OJ-527 | 0000OJ | Supervisor applies I17's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetContentSize`; require the matching TC-I17 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed50,58ed77)`, absent FR/FP, absent desired-name collision, and immutable C103 physical protection. | Section 21 I17 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 084

Rejected-artifact location: C0000OJ-528 ledger/checklist row at rejected report line 5456.

~~~text
| [ ] | C0000OJ-528 | 0000OJ | Supervisor applies I18's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetScrollDelta`; require the matching TC-I18 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ed80,58edc5)`, absent FR/FP, absent desired-name collision, and immutable C104 physical protection. | Section 21 I18 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 085

Rejected-artifact location: C0000OJ-529 ledger/checklist row at rejected report line 5457.

~~~text
| [ ] | C0000OJ-529 | 0000OJ | Supervisor applies I19's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__UpdateRenderRegion`; require the matching TC-I19 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58edd0,58ee4e)`, absent FR/FP, absent desired-name collision, and immutable C105 physical protection. | Section 21 I19 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 086

Rejected-artifact location: C0000OJ-530 ledger/checklist row at rejected report line 5458.

~~~text
| [ ] | C0000OJ-530 | 0000OJ | Supervisor applies I20's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetMaxLength`; require the matching TC-I20 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ee50,58ee67)`, absent FR/FP, absent desired-name collision, and immutable C106 physical protection. | Section 21 I20 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 087

Rejected-artifact location: C0000OJ-531 ledger/checklist row at rejected report line 5459.

~~~text
| [ ] | C0000OJ-531 | 0000OJ | Supervisor applies I21's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__SetMaxLines`; require the matching TC-I21 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ee70,58ee87)`, absent FR/FP, absent desired-name collision, and immutable C107 physical protection. | Section 21 I21 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 088

Rejected-artifact location: C0000OJ-532 ledger/checklist row at rejected report line 5460.

~~~text
| [ ] | C0000OJ-532 | 0000OJ | Supervisor applies I22's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `MeasureWrappedTextHeight`; require the matching TC-I22 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves cdecl function `[58ee90,58ef57)` constructs/inserts/measures/deletes a temporary TextEditPane, absent FR/FP, absent desired-name collision, and immutable C108 physical protection. | Section 21 I22 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 089

Rejected-artifact location: C0000OJ-533 ledger/checklist row at rejected report line 5461.

~~~text
| [ ] | C0000OJ-533 | 0000OJ | Supervisor applies I23's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetTextBuffer`; require the matching TC-I23 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58ef60,58ef6e)`, absent FR/FP, absent desired-name collision, and immutable C109 physical protection. | Section 21 I23 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 090

Rejected-artifact location: C0000OJ-534 ledger/checklist row at rejected report line 5462.

~~~text
| [ ] | C0000OJ-534 | 0000OJ | Supervisor applies I24's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetStoredTextLength`; require the matching TC-I24 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58efa0,58efab)`, absent FR/FP, absent desired-name collision, and immutable C110 physical protection. | Section 21 I24 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 091

Rejected-artifact location: C0000OJ-535 ledger/checklist row at rejected report line 5463.

~~~text
| [ ] | C0000OJ-535 | 0000OJ | Supervisor applies I25's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__MeasureTextRange`; require the matching TC-I25 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58efb0,58f049)`, absent FR/FP, absent desired-name collision, and immutable C111 physical protection. | Section 21 I25 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 092

Rejected-artifact location: C0000OJ-536 ledger/checklist row at rejected report line 5464.

~~~text
| [ ] | C0000OJ-536 | 0000OJ | Supervisor applies I26's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsSelectionVisible`; require the matching TC-I26 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f0c0,58f0c7)` returns byte `this[346]` (`m_selectionVisible +0x15a`), absent FR/FP, absent desired-name collision, and immutable C114 physical protection. | Section 21 I26 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 093

Rejected-artifact location: C0000OJ-537 ledger/checklist row at rejected report line 5465.

~~~text
| [ ] | C0000OJ-537 | 0000OJ | Supervisor applies I27's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetLineTextRange`; require the matching TC-I27 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f150,58f19e)`, absent FR/FP, absent desired-name collision, and immutable C116 physical protection. | Section 21 I27 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 094

Rejected-artifact location: C0000OJ-538 ledger/checklist row at rejected report line 5466.

~~~text
| [ ] | C0000OJ-538 | 0000OJ | Supervisor applies I28's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__GetFormatAtOffset`; require the matching TC-I28 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58f630,58f686)`, absent FR/FP, absent desired-name collision, and immutable C122 physical protection. | Section 21 I28 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 095

Rejected-artifact location: C0000OJ-539 ledger/checklist row at rejected report line 5467.

~~~text
| [ ] | C0000OJ-539 | 0000OJ | Supervisor applies I29's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ApplySelectionFormat`; require the matching TC-I29 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[58fef0,58ffd2)`, absent FR/FP, absent desired-name collision, and immutable C128 physical protection. | Section 21 I29 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 096

Rejected-artifact location: C0000OJ-540 ledger/checklist row at rejected report line 5468.

~~~text
| [ ] | C0000OJ-540 | 0000OJ | Supervisor applies I30's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__IsDirty`; require the matching TC-I30 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[590130,590137)`, absent FR/FP, absent desired-name collision, and immutable C129 physical protection. | Section 21 I30 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 097

Rejected-artifact location: C0000OJ-541 ledger/checklist row at rejected report line 5469.

~~~text
| [ ] | C0000OJ-541 | 0000OJ | Supervisor applies I31's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__CopySelectionToScrap`; require the matching TC-I31 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5901b0,590496)`, exact scrap-copy body, absent FR/FP, absent `TextEditPane__CopySelectionToScrap` collision, and immutable C130 physical protection. | Section 21 I31 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 098

Rejected-artifact location: C0000OJ-542 ledger/checklist row at rejected report line 5470.

~~~text
| [ ] | C0000OJ-542 | 0000OJ | Supervisor applies I32's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__CopyAllToClipboard`; require the matching TC-I32 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[590520,5905eb)`, exact full-buffer clipboard body, absent FR/FP, absent `TextEditPane__CopyAllToClipboard` collision, and immutable C132 physical protection. | Section 21 I32 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 099

Rejected-artifact location: C0000OJ-543 ledger/checklist row at rejected report line 5471.

~~~text
| [ ] | C0000OJ-543 | 0000OJ | Supervisor applies I33's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__EnforceMaxLength`; require the matching TC-I33 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[591180,5911f8)`, absent FR/FP, absent desired-name collision, and immutable C138 physical protection. | Section 21 I33 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 100

Rejected-artifact location: C0000OJ-544 ledger/checklist row at rejected report line 5472.

~~~text
| [ ] | C0000OJ-544 | 0000OJ | Supervisor applies I34's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__EnforceMaxLines`; require the matching TC-I34 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[591200,5912ad)`, absent FR/FP, absent desired-name collision, and immutable C139 physical protection. | Section 21 I34 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 101

Rejected-artifact location: C0000OJ-545 ledger/checklist row at rejected report line 5473.

~~~text
| [ ] | C0000OJ-545 | 0000OJ | Supervisor applies I35's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ApplySerializedFormatRuns`; require the matching TC-I35 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592090,592436)`, absent FR/FP, absent desired-name collision, and immutable C152 physical protection. | Section 21 I35 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 102

Rejected-artifact location: C0000OJ-546 ledger/checklist row at rejected report line 5474.

~~~text
| [ ] | C0000OJ-546 | 0000OJ | Supervisor applies I36's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DeleteFormatRange`; require the matching TC-I36 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5927e0,592993)`, absent FR/FP, absent desired-name collision, and immutable C154 physical protection. | Section 21 I36 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 103

Rejected-artifact location: C0000OJ-547 ledger/checklist row at rejected report line 5475.

~~~text
| [ ] | C0000OJ-547 | 0000OJ | Supervisor applies I37's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__RemoveFormatRun`; require the matching TC-I37 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592b60,592bab)`, absent FR/FP, absent desired-name collision, and immutable C155 physical protection. | Section 21 I37 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 104

Rejected-artifact location: C0000OJ-548 ledger/checklist row at rejected report line 5476.

~~~text
| [ ] | C0000OJ-548 | 0000OJ | Supervisor applies I38's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__MeasureLineBreak`; require the matching TC-I38 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[592fb0,5931e0)`, absent FR/FP, absent desired-name collision, and immutable C158 physical protection. | Section 21 I38 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 105

Rejected-artifact location: C0000OJ-549 ledger/checklist row at rejected report line 5477.

~~~text
| [ ] | C0000OJ-549 | 0000OJ | Supervisor applies I39's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__InsertTextStorage`; require the matching TC-I39 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5931e0,59327f)`, absent FR/FP, absent desired-name collision, and immutable C159 physical protection. | Section 21 I39 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 106

Rejected-artifact location: C0000OJ-550 ledger/checklist row at rejected report line 5478.

~~~text
| [ ] | C0000OJ-550 | 0000OJ | Supervisor applies I40's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ShiftLineOffsets`; require the matching TC-I40 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[593400,593450)`, absent FR/FP, absent desired-name collision, and immutable C161 physical protection. | Section 21 I40 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 107

Rejected-artifact location: C0000OJ-551 ledger/checklist row at rejected report line 5479.

~~~text
| [ ] | C0000OJ-551 | 0000OJ | Supervisor applies I41's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__ShiftFormatRunOffsets`; require the matching TC-I41 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[593450,5934a0)`, absent FR/FP, absent desired-name collision, and immutable C162 physical protection. | Section 21 I41 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 108

Rejected-artifact location: C0000OJ-552 ledger/checklist row at rejected report line 5480.

~~~text
| [ ] | C0000OJ-552 | 0000OJ | Supervisor applies I42's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__HitTestTextRunCallback`; require the matching TC-I42 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5936e0,593875)`, absent FR/FP, absent desired-name collision, and immutable C164 physical protection. | Section 21 I42 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 109

Rejected-artifact location: C0000OJ-553 ledger/checklist row at rejected report line 5481.

~~~text
| [ ] | C0000OJ-553 | 0000OJ | Supervisor applies I43's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__TextRunOffsetMeasureCallback`; require the matching TC-I43 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Dated canonical evidence proves function `[593a20,593b12)`, persisted IDB type `bool __cdecl(TextEditLineRecord *, const TextRunFormatData *, const wchar_t *, __int16, signed __int16, signed __int16, _WORD *, GrafPort *)`, current public presentation with unsigned sixth parameter, exact TC-I43 decompiler form, C124's sole incoming data xref at `0x58f94e`, absent AR/AP/FR/FP, absent desired-name collision, and immutable C165 physical protection. | Section 21 I43 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 110

Rejected-artifact location: C0000OJ-554 ledger/checklist row at rejected report line 5482.

~~~text
| [ ] | C0000OJ-554 | 0000OJ | Supervisor applies I44's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditPane__DrawTextCharacters`; require the matching TC-I44 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5946b0,59489f)`, absent FR/FP, absent desired-name collision, and immutable C171 physical protection. | Section 21 I44 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 111

Rejected-artifact location: C0000OJ-555 ledger/checklist row at rejected report line 5483.

~~~text
| [ ] | C0000OJ-555 | 0000OJ | Supervisor applies I45's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__SetPayload`; require the matching TC-I45 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5950a0,5950dc)`, absent FR/FP, absent desired-name collision, and immutable C184 physical protection. | Section 21 I45 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 112

Rejected-artifact location: C0000OJ-556 ledger/checklist row at rejected report line 5484.

~~~text
| [ ] | C0000OJ-556 | 0000OJ | Supervisor applies I46's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__DuplicateText`; require the matching TC-I46 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5950e0,595138)`, absent FR/FP, absent desired-name collision, and immutable C185 physical protection. | Section 21 I46 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 113

Rejected-artifact location: C0000OJ-557 ledger/checklist row at rejected report line 5485.

~~~text
| [ ] | C0000OJ-557 | 0000OJ | Supervisor applies I47's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__DuplicatePayload`; require the matching TC-I47 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[595140,595193)`, absent FR/FP, absent desired-name collision, and immutable C186 physical protection. | Section 21 I47 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 114

Rejected-artifact location: C0000OJ-558 ledger/checklist row at rejected report line 5486.

~~~text
| [ ] | C0000OJ-558 | 0000OJ | Supervisor applies I48's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `TextEditScrap__SetFromClipboardBlock`; require the matching TC-I48 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[595250,595389)`, absent FR/FP, absent desired-name collision, and immutable C187 physical protection. | Section 21 I48 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 115

Rejected-artifact location: C0000OJ-559 ledger/checklist row at rejected report line 5487.

~~~text
| [ ] | C0000OJ-559 | 0000OJ | Supervisor applies I49's four exact ordered, self-contained public request objects with top-level `database:DB` bound to the exact session ID returned by Section 21 `idb_open(input_path:TX)` (`rename`, exact-entry `force_recompile`, `set_function_comments`, then `set_repeatable_comments`) to `EPFTextEditObject__Constructor`; require the matching TC-I49 fresh decompile/public readback before FR; no type or physical-frame mutation. | original-proof | Fresh live read-only MCP proves function `[5954c0,595590)`, absent FR/FP, absent desired-name collision, and immutable C189 physical protection. | Section 21 I49 literal returned-DB-bound requests / supervisor Gate 2B | incorporate | proposed |
~~~

## Removed Block 116

Rejected-artifact location: C0000OJ-513 summary at rejected report line 1205.

~~~text
| C0000OJ-513 | IDA scope remains exactly 49 entities/196 self-contained literal requests after `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and the complete role-specific public runtime package independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; every action/read guard uses only that exact returned `DB`, each entity has an exact persisted/exact-entry-refresh/fresh-decompiler/public presentation contract, and raw non-function heads are protected. Missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. The sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}`, separate physical receipts, route retirement, independent `DB_VERIFY`, pre-promotion gate, safe physical promotion, restore roles, and final `DB_FINAL` proof are mandatory supervisor persistence boundaries outside those 196 requests. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | See exact ledger row and TC-I01..TC-I49; selected-unit source closure is `94/94`. |
~~~

## Removed Block 117

Rejected-artifact location: C0000OJ-513 summary at rejected report line 1649.

~~~text
| C0000OJ-513 | IDA scope remains exactly 49 entities/196 self-contained literal requests after `TX -> idb_open -> returned DB -> runtime_attestation(DB,TX)` and the complete role-specific public runtime package independently passes top-level `schema_version:1`/`ok:true`/`errors:[]` and worker `schema_version:1`/`ok:true`/`errors:[]`, with no listener-local `ok` or `errors` fields (their absence is expected rather than failure) and with complete listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation; every action/read guard uses only that exact returned `DB`, each entity has an exact persisted/exact-entry-refresh/fresh-decompiler/public presentation contract, and raw non-function heads are protected. Missing, null, false, malformed, or nonempty top-level or worker status/error state, or any listener identity/runtime-field mismatch, hard-stops. The sole exact `idb_save({database:DB,path:TX}) -> {ok,error?,path}`, separate physical receipts, route retirement, independent `DB_VERIFY`, four-observation pre-promotion gate, safe supervisor physical promotion, phase-specific restore roles, and final `DB_FINAL` proof are mandatory outside those 196 requests. The database-role namespace is closed to exactly five fresh pairwise-distinct roles and no extras: `DB` mutates/saves `TX`, `DB_VERIFY` reads saved `TX`, `DB_FINAL` reads promoted `CANONICAL`, failure-only `DB_ROLLBACK` classifies failed/ambiguous promoted `CANONICAL`, and `DB_RESTORE` proves restored `CANONICAL`; `BACKUP` is never opened as a database. Promotion and restoration are governed only by Section 21's pre-mutation-probed built-in `System.IO.File.Replace` protocol: distinct exclusive collision-checked exact-parent/same-volume candidates copied from verified `TX` or physical `BACKUP`, built-in file-handle `FileStream.Flush(true)`, closed/reopened path-size-SHA256/volume-file-identity/link/reparse/stream receipts, one no-retry expected-current-`CANONICAL`-guarded replacement with no API-created backup path, and exact post-operation/no-residue proof. Directory-handle `FlushFileBuffers` and custom write-through interop are excluded; any unavailable, access-denied, unsupported, policy-blocked, ambiguous, or unverified required primitive grants no Gate 2B credit and follows the phase-specific no-promotion or failed-CANON rollback/physical-`BACKUP`-restore path. | Documentation/generated/source-closure support disposition, not a binary item. Caller/callee, physical inbound/outbound xrefs, and read/write/address/init/destruction/store routes are not applicable. Exact artifact/source route: after the isolated-copy startup and complete runtime package succeeds with independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, apply the exact 49-entity/196-request source-quality rename/exact-entry-refresh/FR/FP handoff for three TextBox-local plus 46 selected-unit compiler-label entities, with every action/read guard bound to returned `DB`, every required boundary freshly reattested, and every raw non-function head protected. Evidence: dated canonical read-only rechecks supply 46 self-contained literal AR/AP/frame/bytes/xref/boundary prestates, absent collisions, and 184 deterministic staged readbacks; the three TextBox-local entities add 12 staged readbacks; Section 21 supplies all 196 literal returned-`DB` requests, TC-I01..TC-I49 exact contracts, the complete listener/worker/process/route/tool-surface package, independent top-level/worker status/error closure plus listener role/freshness/endpoint/port/process/generation/source-root/role-manifest/module validation with no listener-local `ok`/`errors` fields, separate role-specific module baselines, current save schema, physical receipts, verifier/promotion/restore/final-session gates, and no type/frame/data/general-analysis mutation. Destination: IDA handoff/follow-up. |
~~~

## Removed Block 118

Rejected-artifact location: Open Questions durability paragraph.

~~~text
- Containing-directory durability: the supported directory-handle flush returned `Access is denied`, while custom write-through interop was policy-blocked before execution. Resolved by removing both from the success path and specifying one approved built-in `FileStream.Flush(true)` plus `System.IO.File.Replace` protocol with an exact-parent disposable pre-mutation probe, one no-retry expected-current replacement, complete physical receipts, and deterministic unavailable/access-denied/unsupported/policy-blocked handling. The handoff remains proposed and receives no Gate 2B credit until the supervisor executes that probe and complete protocol successfully.
~~~
