<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00047Q-UserListPaneOpenSayToUserMessageInputPane-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Legacy Operational Material: UID00047Q

Source report: [00047Q-UserListPaneOpenSayToUserMessageInputPane-source-quality.md](00047Q-UserListPaneOpenSayToUserMessageInputPane-source-quality.md)

> NON-AUTHORITATIVE ARCHIVE. This file contains a removed operational MCP/backup/save/reopen/rollback runbook for audit provenance only and must never be executed, replayed, or submitted. It receives no report, evidence, Gate, coverage, score, IDA, validator, or lifecycle credit.

## Removed Material

~~~text
- Deterministic supervisor safety handoff:
  1. Freshly call `idb_list`; select the then-current canonical session for exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; require public `runtime_attestation` with that returned session ID and exact canonical path to report `ok:true`. Open with `run_auto_analysis:false` if a new canonical session is required.
  2. Before mutation, create a collision-safe durable backup at `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.uid00047Q-prechange-<UTC>.i64` using the supervisor-approved IDB backup path; require file existence, nonzero size, and recorded SHA256 before continuing. Never overwrite a prior backup.
  3. Reread every A001-A006 prestate, all protected frames/items, exact target/constructor/operator-new bytes and bounds, xrefs, comments, and collisions. Drift fails closed before any action.
  4. Execute the clean function rename dry run; apply function renames; execute/apply stack renames; apply types; apply function comments; apply address comments; force-recompile only `0x0059ed60`, `0x005b1570`, `0x005b1990`, and `0x004f4aa0`; reread every exact expected state and every protected unchanged state. Any failed row or unexpected byte/boundary/xref/frame/comment change means no save.
  5. Only after all in-memory readbacks pass, perform the sole canonical save through the `idb_save` operation class to exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Record returned success state, path, canonical size, and SHA256.
  6. Create collision-safe post-save verification copy `source-3/project-documentation/tools/leaser/Agents/ida-backups/NexusTK.exe.uid00047Q-postsave-<UTC>.i64`; require its SHA256 to equal the saved canonical SHA256. Open that copy read-only with `run_auto_analysis:false`, bind its returned session through public `runtime_attestation`, and repeat exact A001-A006 persisted readback, target/dependency bytes, bounds, frames, comments, and xrefs.
  7. On pre-save failure, abandon in-memory changes without saving. On save/post-save persistence mismatch, restore the canonical database from the recorded prechange backup through the supervisor-owned recovery process, freshly attest/reopen the canonical path, prove the entire prestate restored, and do not issue another mutation save in the failed transaction.
~~~

## Removed Block R002 - Gate 2B Operational Sequence

The following text was removed from the source report because it encoded a replayable supervisor operation sequence. It is non-authoritative, must never be executed, and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

~~~text
- All following prestates are dated read-only observations from the attested session, not permanent current authority. Supervisor Gate 2B must call fresh `idb_list`, bind the selected canonical session with public `runtime_attestation`, reread every item/comment/frame/collision immediately before action, fail closed on drift, apply only accepted rows, reread every poststate, and perform the supervisor-owned durable backup/save/persistence procedure.
~~~
## Removed Block R003 - Residual Runtime And Mutation Ordering

The following source-report text was removed because it prescribed runtime discovery, dry-run/apply mechanics, backup/save/reopen order, and rollback handling. It is non-authoritative, must never be executed, and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

~~~text
- Fresh read-only IDA MCP work used canonical session `supervisor-uid0002OW-gate2b-20260813T0115Z`, bound by public `runtime_attestation` at `2026-08-13T05:09:27.556952Z` to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. This session and every readback below are dated research snapshots, not permanent current-state authority; supervisor Gate 2B must freshly enumerate and attest the action-boundary session.

| A001-A004 | `rename` function operations | Collision-check, then dry-run and apply the exact function names from the action table with collision-safe `pure:true`; any collision or prestate drift fails closed. |
| A002-A004 | `rename` stack operations | Dry-run and apply only the exact stack-name deltas from the action table with non-pure handling; stack/local renames must never use `pure:true`. |

- Supervisor Gate 2B safety boundary: dynamically attest the then-current canonical session and exact path; create and verify a collision-safe durable backup; reproduce every A001-A006 and protected prestate; apply only accepted action rows with immediate complete readback; save once only after all in-memory checks pass; verify persistence through a fresh read-only reopen/copy; and use the supervisor-owned rollback procedure on any failure. These are required protections, not a runnable sequence supplied by this report.
~~~
