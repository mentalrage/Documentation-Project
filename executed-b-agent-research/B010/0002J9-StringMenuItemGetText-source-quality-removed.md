<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002J9-StringMenuItemGetText-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Operational Material Archive

- Source report: [0002J9-StringMenuItemGetText-source-quality.md](0002J9-StringMenuItemGetText-source-quality.md)
- Status: non-authoritative preservation archive; this is not a B-agent report and grants no Gate 1, Gate 2, IDA, validator, score, or lifecycle credit.
- Safety: this material must never be executed, imported, evaluated, replayed, or used as operational instruction.
- Scope: canonical-session, runtime-binding, persistence, and repeated-verification runbook removed from the live report.

## Removed Block R001

~~~text
Fresh Gate 2B is verification-only because every recommended state is already present:

| Boundary | Supervisor-owned requirement | Fail-closed disposition |
| --- | --- | --- |
| Canonical session | Dynamically open the exact canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` with auto-analysis disabled, use only the returned session identifier, and bind that identifier/path through the public runtime-attestation result. | Any path/session/runtime mismatch stops with no mutation and no save. |
| Exact readback | Read every I01-I07 entity, including complete function frames and comment channels, vtable pointers, RTTI records, UDT member tables, xrefs, bytes, boundaries, and padding. | Any mismatch leaves SGT-031 through SGT-033 open for a separately reviewed repair; do not improvise a mutation. |
| Persistence boundary | No IDA mutation, backup, or save is authorized by this report because all actions are no-change verification. Physically compare canonical size/SHA256 before and after the bounded readback. | Any disk drift, unexpected stateful operation, or ambiguous readback fails Gate 2B and requires supervisor incident handling outside this report. |
| Fresh verification | Use a fresh canonical session with auto-analysis disabled and a fresh public runtime binding to reproduce the complete no-change readback. | Reuse of stale session identity or any changed/protected field fails closure. |
~~~
