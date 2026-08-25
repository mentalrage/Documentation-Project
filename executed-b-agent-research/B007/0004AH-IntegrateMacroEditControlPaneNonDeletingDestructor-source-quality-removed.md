<!-- REMOVED-MATERIAL-ARCHIVE -->
# Removed Material Archive

- Status: Non-authoritative archival material only.
- Source report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0004AH-IntegrateMacroEditControlPaneNonDeletingDestructor-source-quality.md`
- Safety: This file must never be executed, replayed, or used as an operational runbook.
- Credit: This archive provides no gate, score, coverage, IDA, validator, or lifecycle credit.

# Removed Operational Prose Archive

- Source report: [0004AH-IntegrateMacroEditControlPaneNonDeletingDestructor-source-quality.md](0004AH-IntegrateMacroEditControlPaneNonDeletingDestructor-source-quality.md)
- Authority: this file is non-authoritative and must never be executed.
- Credit: this file is not research evidence and receives no Gate, coverage, score, IDA, validator, or lifecycle credit.

## Removed Gate 2B Runbook

> Current evidence session is a dated read-only snapshot only. At Gate 2B the supervisor must open or use the exact current canonical IDB with `run_auto_analysis:false`, bind the returned session through public `runtime_attestation`, and construct current-schema requests directly from the exact row values below.
>
> | I01 | function range `0x0057ff00-0x0057ff3f` | Function absent; name absent; type absent; frame absent; address regular absent; address repeatable absent; function comments unavailable; 16 code heads; bytes/SHA C001; zero inbound refs; predecessor/successor alignment exact. | Use the current-schema `define_func` operation to define exactly the row's function range, with start `0x0057ff00` and exclusive end `0x0057ff3f`. The operation has no dry-run; perform it only after the row's complete preflight and durable backup. | Fail closed on any changed byte/item/xref/boundary/comment/name or any function/name collision. Do not include `0x0057ff3f`. | One function exactly `[0x0057ff00,0x0057ff3f)`; bytes unchanged; expected frame exactly one row `__return_address`, offset `0x0`, size `0x4`, type `_UNKNOWN *`; both address-comment channels absent. Any other frame/bound fails before save. |
> | I02 | function name at `0x0057ff00` | After I01: auto-name expected `sub_57FF00`; collision queries contain no `IntegrateMacroEditControlPane__Destructor`. | Use the current-schema `rename` operation in pure function-name mode: first perform its supported dry-run, then apply the row's literal `IntegrateMacroEditControlPane__Destructor` name at `0x0057ff00` with overwrite disabled and stop-on-error enabled. | `pure:true`; no overwrite; exactly one target. Requery functions and names immediately. | Exactly one function/name row at `0x0057ff00` with new name, zero `sub_57FF00` function/name rows, unchanged bounds/bytes/frame/comments/xrefs. |
> | I03 | function type at `0x0057ff00` | After I02: current function type is the auto-created no-stack-argument function type; local UDT `IntegrateMacroEditControlPane` exists at ordinal 617, size `0x118`, exact members in Section 13. | Use the current-schema `set_type` operation to apply the row's exact function declaration `void __thiscall IntegrateMacroEditControlPane__Destructor(IntegrateMacroEditControlPane *this)` at `0x0057ff00`. The operation has no dry-run; preflight the UDT and frame first. | Do not alter UDT, members, alignment, function bounds, bytes, comments, or xrefs. | Item/function prototype renders exactly `void __thiscall(IntegrateMacroEditControlPane *this)`; frame remains exactly the I01 one-row frame; no stack argument is created. |
> | I04 | function-regular comment at `0x0057ff00` | After I03: function regular absent; function repeatable absent; address regular absent; address repeatable absent. | Use the current-schema `set_function_comments` operation to set only the function-regular channel at `0x0057ff00` to the row's exact text: `Source IntegrateMacroEditControlPane ordinary destructor: conditionally deletes owned TextEditPane *m_textEdit at +0x110 and nulls it. Vptr restores and the tail transfer to Pane::~Pane are compiler-generated teardown; scalar storage policy remains at 0x00580690.` | Set function-regular only. Preserve function-repeatable and both address channels absent. | Function regular equals the exact requested text; function repeatable/address regular/address repeatable absent; all I01-I03 protections unchanged. |
>
> Supervisor runtime controls: collision-safe durable backup before I01; serial I01-I04 with immediate item/function/type/frame/comment/xref/byte readback; no save on any mismatch; sole save only after all protected state passes; retire the exact worker; fresh canonical-session persistence readback; guarded rollback from the durable backup if persistence differs. No B agent performs these operations.

## Removed Operational Mirrors

> C027: define only after complete prestate, boundary, backup, and collision checks.
>
> C028: pure-rename with dry-run first and no overwrite.
>
> C031: enforce canonical attestation, collision-safe durable backup, serial readbacks, sole save after all protections, fresh-session persistence readback, and guarded no-save rollback.
>
> C046: perform Gate 2B I01-I04 directly through current canonical IDA MCP with save/readback controls.

