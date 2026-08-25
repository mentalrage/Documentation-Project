<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0004HB-TextMenuDialogRawSelectionReplySerializer-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Operational Code Archive

> NON-AUTHORITATIVE ARCHIVE. This companion must never be executed and receives no report, evidence, Gate, coverage, score, IDA, validator, or lifecycle credit.

- Source report: [0004HB-TextMenuDialogRawSelectionReplySerializer-source-quality.md](0004HB-TextMenuDialogRawSelectionReplySerializer-source-quality.md)
- Authority: this file is not a B-agent report, supplies no research evidence, and grants no Gate, IDA, score, validator, coverage, or lifecycle credit.
- Safety: do not execute, import, evaluate, or use the material below as operational instructions.
- Scope: literal MCP request-object syntax removed from the source report during supervisor cleanup. The cleaned report retains the same prestates, intended state changes, expected readbacks, evidence, and fail-closed protections in structured prose.

## Removed Request Package R001

~~~text
`idb_list` request `{}`; `server_health` request `{database:A00.database}`; `runtime_attestation` request `{expected_database:A00.database,expected_canonical_path:"E:\NTK\Resources\NexusTK\NexusTK.exe.i64"}`

`declare_type` request `{database:A00.database,decls:["struct TextMenuDialog;"]}`

`define_func` request `{database:A00.database,items:[{addr:"0x00519110",end:"0x0051920c"}]}`

`rename` request `{database:A00.database,batch:{func:[{addr:"0x00519110",name:"TextMenuDialog__SendMenuReplyByIndex"}],pure:true,allow_overwrite:false,stop_on_error:true,dry_run:true}}`; then identical request with `dry_run:false`

`set_type` request `{database:A00.database,edits:[{addr:"0x00519110",kind:"function",signature:"void __thiscall TextMenuDialog__SendMenuReplyByIndex(TextMenuDialog *this, unsigned short optionIndex)"}]}`

`set_function_comments` request `{database:A00.database,items:[{addr:"0x00519110",comment:"Retained TextMenuDialog::SendMenuReply(unsigned short) overload; serializes opcode 0x39 from dialog fields and indexed item id. The live OnDialogAction small-menu path contains the compiler-inlined call expansion; no current direct route reaches this retained copy."}]}`

`set_address_comments` request `{database:A00.database,items:[{addr:"0x00519191",comment:"m_itemIds[optionIndex] at TextMenuDialog +0x280; optionIndex is the unsigned-short source parameter."}]}`

`set_address_comments` request `{database:A00.database,items:[{addr:"0x005191a2",comment:"If m_hasExtraString at +0x279 is set, append m_extraString from +0x27c as an ANSI length-8 string."}]}`

`set_address_comments` request `{database:A00.database,items:[{addr:"0x005191e3",comment:"Write a local trailing zero after proving cursor < 0x100; QueueAndSendPacket receives the pre-terminator cursor length."}]}`
~~~
## Additional Removed Operational Prose

Source report: [0004HB-TextMenuDialogRawSelectionReplySerializer-source-quality.md](0004HB-TextMenuDialogRawSelectionReplySerializer-source-quality.md)

This text is non-authoritative audit provenance and must never be executed. It is not research evidence and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

> The report-time session/database identifiers are dated provenance only. At Gate 2B the supervisor must freshly select and attest the canonical database for exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, reproduce each literal pre-state below, and stop on any identity or state mismatch. Runtime binding, backup, mutation calls, save, persistence verification, and rollback remain external supervisor operations; this report contains no runnable request package. A01-A08 are supervisor-owned and the B agent performed no mutation.
>
> | A00 | canonical runtime | Dated snapshot database `supervisor-uid0002OW-gate2b-20260813T0115Z`, exact path, attestation `ok:true`; future identity is not frozen | Freshly select and attest only the active canonical session for the exact path; make no IDA database change in this row | Healthy attested canonical identity with no mismatch or error | Fail closed on mismatch; supervisor only |
>
> | A03 | target function name | After A02, expected auto-name `sub_519110`; destination collision must be absent | Perform a no-overwrite pure function rename, first as collision/no-delta dry-run and then apply, to `TextMenuDialog__SendMenuReplyByIndex` | Exact destination name and no unrelated name or analysis delta | Source overload inference; supervisor only |
>
> | C4HB-031 | 0004HB | Require fresh canonical IDB discovery and runtime attestation before Gate 2B | High | dated report-time attestation only | canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` Gate 2B preflight | incorporate | proposed |
>
> | C4HB-051 | 0004HB | Apply and independently verify structured IDA actions only through supervisor Gate 2B | High | IDA authority boundary | canonical IDB UID0004HB transaction and readback | incorporate | proposed |

## Removed Block R002 - Runtime Rediscovery Instruction

The following source-report text was removed because it prescribed runtime discovery and attestation on every Gate 2B attempt. It is non-authoritative, must never be executed, and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

~~~text
- Dated live-MCP snapshot: `idb_list`, `server_health`, and `runtime_attestation` on 2026-08-13 used canonical database `supervisor-uid0002OW-gate2b-20260813T0115Z`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; attestation returned `ok:true`, worker PID `3544`, generation `pid:3544;created:134310578063549307`, route `127.0.0.1:64512`, and empty errors. This identity is provenance only; every supervisor Gate 2B attempt must freshly discover and attest the then-current canonical session.
~~~
