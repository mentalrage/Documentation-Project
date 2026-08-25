** TARGET-REPORT-UID:000281 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000281] HeadSelectDialogLayoutTableSecondary Source-Quality Report

Agent: B005  
Assignment: B005-report-000281-head-select-dialog-layout-table-secondary-20260625  
Mode: report-only research; no leases, by-* edits, generated edits, validator state/cache edits, lock edits, coverage-report edits, or IDA DB edits performed.

## Outcome

Recommended disposition: populate [UID:000281] with the exact mutable `int` static initializer for `s_highResHeadVerticalOffsets[913]`, keep `CANONICAL_OWNER:000062`, keep `EMITTER_UIDS:000062`, and set `EMITTER_POSITION_OPTIONAL:0` so the storage declaration is emitted before [UID:0001FI] `HeadSelectDialogCore` uses it.

The current blank-C++ rationale is transcription debt, not a source-quality reason to keep the page empty. Live IDA MCP bytes now provide the exact 913-dword image initializer. The correct image initializer keeps indices `900..912` as zero; the constructor patch code already documented in [UID:0001FI] writes the runtime high/current EPF tail values.

## Current State

- Target: `by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md`
- Current target header: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000062`, blank `RECONSTRUCTION_CPP CODE`.
- The strict C++ gate is satisfied: reconstructable true, nonblank emitter route through [UID:000062] to [UID:0000JT], and `(86 + 91) / 2 = 88.5`.
- Current generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp` references `s_highResHeadVerticalOffsets` from [UID:0001FI] but still emits [UID:000281] as an empty marker, so the generated file is incomplete until this storage is defined.
- Generated tracker rows are stale compared with the live target page. The by-* page already records `86/91`; generated reports still show older `72/88` style rows until a validator/autogen refresh.

## Evidence Checked

Local documentation checked:

- [UID:000281] `by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md`.
- [UID:00027Z] `by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md`.
- [UID:000280] `by-memory/0x0066ed20-0x0066eea0.HeadSelectDialogLayoutPadding.md`.
- [UID:000282] `by-memory/0x0066fce4-0x0066fe40.HeadSelectToSelfLookPadding.md`.
- [UID:0001FI] `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`.
- [UID:000062] `by-class/HeadSelectDialog.md`.
- [UID:0000JT] `by-file/HeadSelectDialog.md`.
- [UID:0000SW] `by-global/g_useEpfAssets.md`.
- Generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp`.
- Prior executed B001 HeadSelect source-quality report and B015 primary-table report were used only as leads.

Live IDA MCP evidence was available and used:

- MCP session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`.
- `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `get_bytes`, `xrefs_to`, `insn_query`, `decompile`, `int_convert`, and `entity_query` were used read-only.

## Current MCP Byte Facts

Secondary high/current table `0x0066eea0-0x0066fce4`:

- Byte count: `0xe44` / 3652.
- Dword count: `0x391` / 913.
- Static image/body count before runtime tail: `0x384` / 900 dwords.
- Image tail: indices `900..912` are all zero in the file image.
- Nonzero dwords: 105, all in the static 900-entry body.
- Nonzero bytes: 402.
- Signed dword range: min `-15`, max `15`.
- First 40 signed dwords: `-10, -10, -10, -10, -10, -4, -10, -3, -10, -11, -10, -10, -2, -1, -3, -3, -2, -10, -10, 0, -2, 12, -2, -9, -10, -12, -3, -4, -3, 12, -4, -10, -4, -10, -10, -10, -10, -5, -12, -10`.
- Last 40 image dwords: all zero.
- SHA-256 over the exact 3652 MCP bytes: `eae0749f6d3e3861b8ba222b59a921b37a67d2b77340284c6df7560100f230b3`.

Comparison/support:

- Primary normal table [UID:00027Z] is the paired `s_normalHeadVerticalOffsets[904]` at `0x0066df00-0x0066ed20`: 904 dwords, 900 static dwords plus four image-zero tail slots.
- Inter-table padding [UID:000280] `0x0066ed20-0x0066eea0` is zero padding and must remain no-code.
- Successor padding [UID:000282] `0x0066fce4-0x0066fe40` is zero padding before SelfLookPane state and must remain no-code.

## Current MCP Xrefs And Use Sites

`xrefs_to` for the target and tail slots:

| Address | Current MCP xrefs | Role |
| --- | --- | --- |
| `0x0066eea0` | `0x00551093`, `0x005513ee`, `0x0055168b` | Base table use inside refresh, populate, and constructor. |
| `0x0066fcb0` | `0x005515b2` | Constructor writes high tail index 900. |
| `0x0066fcb4` | `0x005515bc` | Constructor writes high tail index 901. |
| `0x0066fcb8` | `0x005515c6` | Constructor writes high tail index 902. |
| `0x0066fcbc` | `0x005515d0` | Constructor writes high tail index 903. |
| `0x0066fcc0` | `0x005515da` | Constructor writes high tail index 904. |
| `0x0066fcc4` | `0x005515e4` | Constructor writes high tail index 905. |
| `0x0066fcc8` | `0x005515ee` | Constructor writes high tail index 906. |
| `0x0066fccc` | `0x005515f8` | Constructor writes high tail index 907. |
| `0x0066fcd0` | `0x00551602` | Constructor writes high tail index 908. |
| `0x0066fcd4` | `0x0055160c` | Constructor writes high tail index 909. |
| `0x0066fcd8` | `0x00551616` | Constructor writes high tail index 910. |
| `0x0066fcdc` | `0x00551620` | Constructor writes high tail index 911. |
| `0x0066fce0` | `0x0055162a` | Constructor writes high tail index 912. |
| `0x0066fce4` | none | Successor padding start; not part of this table. |
| `0x0066fe40` | `0x005692c7`, `0x00569310` | Next referenced data belongs to SelfLookPane successor state, not HeadSelect. |

A dword-aligned `xrefs_to` sweep over the 900 static body entries found only `0x0066eea0` as referenced. That supports one table object with constructor-patched tail slots, not a mixed range needing child splits.

`insn_query` over `0x00551030-0x005520e5` confirms exact operand forms:

- `0x00551093`: `mov al, byte ptr dword_66EEA0[eax*4]`.
- `0x005513ee`: `mov al, byte ptr dword_66EEA0[eax*4]`.
- `0x0055168b`: `sub ecx, dword_66EEA0[eax*4]`.
- Tail writes are `mov dword_66FCB0, 0FFFFFFFBh`, `mov dword_66FCB4, 0FFFFFFF8h`, `mov dword_66FCB8, 0FFFFFFFEh`, `mov dword_66FCBC, 0FFFFFFF9h`, `mov dword_66FCC0, 0FFFFFFF8h`, `mov dword_66FCC4, 0FFFFFFF7h`, `mov dword_66FCC8, 0FFFFFFFDh`, `mov dword_66FCCC, 0FFFFFFFEh`, `mov dword_66FCD0, 0FFFFFFF7h`, `mov dword_66FCD4, 0FFFFFFFEh`, `mov dword_66FCD8, 0FFFFFFF6h`, `mov dword_66FCDC, 0FFFFFFFDh`, and `mov dword_66FCE0, 0FFFFFFFDh`.

Hex-Rays decompile confirms:

- `RefreshHeadPreview` branches on `byte_66DA97 == 1`; the high/current branch sets preview rect `(36,40,73,95)` and uses `LOBYTE(dword_66EEA0[selectedHead])`.
- `PopulateHeadButtons` branches on `byte_66DA97 == 1`; the high/current branch loads `dword_66EEA0[pageStart + slot]` and writes the low byte into the object-status draw-offset byte.
- The constructor high/current branch writes all thirteen tail slots, then computes `this+712 = objectDrawOffset - dword_66EEA0[selectedHead]`.
- The normal branch uses [UID:00027Z] `dword_66DF00` and normal geometry, keeping the two tables parallel but separate.

`entity_query` found no recovered source/debug name for the table island. Current IDB names are address-derived (`dword_66EEA0`, `dword_66FCB0`, etc.). `s_highResHeadVerticalOffsets[913]` remains a source-facing reconstruction name, already accepted by the HeadSelect docs, not recovered original spelling.

## Source-Quality Decision

This page is source-declared/generated-binary static data. It is not disposable padding, not a generated switch table, not a byte table, and not covered by [UID:0001FI] method code. The method page references and patches the storage but does not define it, so [UID:000281] should carry the storage declaration.

Best source shape:

- File-private mutable `int s_highResHeadVerticalOffsets[913]` under [UID:000062] / [UID:0000JT] `NexusTK/ui/dialogs/HeadSelectDialog.cpp`.
- Keep image tail entries zero in the initializer. The constructor writes runtime values `-5, -8, -2, -7, -8, -9, -3, -2, -9, -2, -10, -3, -3`.
- Use `EMITTER_POSITION_OPTIONAL:0` so the declaration appears before [UID:0001FI] `CurrentHeadOffsetTable`, `PatchHighResHeadOffsets`, and method code.
- Use `int`, not `const int` and not `char`, because the constructor writes dword tail slots and subtracts the full dword table entry.

Source-facing names to preserve:

- `s_highResHeadVerticalOffsets[913]`: this target's table.
- `s_normalHeadVerticalOffsets[904]`: paired [UID:00027Z] normal/legacy table.
- `g_useEpfAssets`: documented alias for `byte_66DA97`; `== 1` selects this high/current EPF table.
- [UID:0001FI] helper names that consume this storage: `PatchHighResHeadOffsets`, `CurrentHeadOffsetTable`, `LowSignedByte`, `RefreshHeadPreview`, `PopulateHeadButtons`, and the constructor.

## Rejected Alternatives

- Byte table rejected: constructor operand `sub ecx, dword_66EEA0[eax*4]` and tail writes prove dword/int storage.
- `const` table rejected: constructor writes indices `900..912` at runtime.
- Initializer with patched tail values rejected: MCP bytes show the image has zeroes at indices `900..912`; runtime code performs the writes.
- Covered-by/comment-only C++ rejected: [UID:0001FI] models behavior but does not define `s_highResHeadVerticalOffsets`.
- Merge with [UID:00027Z] rejected: normal and high/current tables have separate base addresses, separate tail lengths, and separate branch uses.
- Merge with [UID:000282] rejected: `0x0066fce4` has no xrefs, is padding, and the next refs at `0x0066fe40` are SelfLookPane.
- CreateUser/image-control ownership rejected: all target direct users land in HeadSelectDialog methods, and file/class docs place this packet-driven in-game dialog under `HeadSelectDialog.cpp`.
- New global/source file rejected: the data is class/file-local HeadSelect support data, not a process-wide global like `g_useEpfAssets`.

## Open Questions

Resolved for implementation:

- Owner/emitter: [UID:000062] `HeadSelectDialog`, emitted through [UID:0000JT] `NexusTK/ui/dialogs/HeadSelectDialog.cpp`.
- Boundary: exact target range `0x0066eea0-0x0066fce4`; successor [UID:000282] padding stays separate.
- Type: mutable signed dword-compatible `int`.
- Formal C++ readiness: yes, exact initializer is available below.
- Tail modeling: initializer zeroes, constructor runtime patches in [UID:0001FI].
- Split/merge: no split or merge needed.
- Validator/autogen route: target file validator with generated wait, then generated file check.

Remaining but non-blocking:

- Original source spelling of `s_highResHeadVerticalOffsets` is not recovered. The name is behavior-based and already synchronized with accepted HeadSelect source-facing docs.
- [UID:00027Z] still needs or has a separate primary-table implementation path; do not edit it from this [UID:000281] report unless the supervisor explicitly pairs the callback.

## Metadata Recommendation

Recommended target metadata after supervisor-authorized implementation:

```text
COMPLETION:91
CONFIDENCE:93
CANONICAL_OWNER:000062
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000062
EMITTER_POSITION_OPTIONAL:0
```

Completion should rise because the exact initializer can now be formalized and the stale empty-emitter state can be cleared. Confidence should remain below final-perfect because the source-facing table name is inferred rather than symbol-recovered.

## Formal C++ Insertion Text

Replace the target formal block with this exact content during implementation. Keep the image tail zeroes; [UID:0001FI] constructor code remains responsible for runtime tail patches.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace {

int s_highResHeadVerticalOffsets[913] = {
    -10, -10, -10, -10, -10, -4, -10, -3, -10, -11, -10, -10, -2, -1, -3, -3,
    -2, -10, -10, 0, -2, 12, -2, -9, -10, -12, -3, -4, -3, 12, -4, -10,
    -4, -10, -10, -10, -10, -5, -12, -10, -10, -4, -10, -10, -4, -10, -10, -12,
    -10, -10, -10, -10, -10, 15, 11, -10, -10, -10, -10, -10, -10, -10, -10, -10,
    -7, -6, -8, -1, -10, -10, -10, -10, -15, -10, -10, -10, -4, 11, 13, -10,
    -3, -10, -4, -10, -4, -5, -3, -2, -3, 0, -5, -10, -7, -3, -4, -4,
    -4, -10, -4, -4, -5, -5, -11, -8, -1, -9, -6, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,
};

} // namespace
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Support Synchronization Facts

These are the exact facts that should be preserved if the implementation callback includes support-doc synchronization:

- [UID:000281] should remove the stale "formal C++ blank because initializer not transcribed" blocker and replace it with exact MCP byte evidence and the formal initializer.
- [UID:0001FI] already uses `s_highResHeadVerticalOffsets` and models `PatchHighResHeadOffsets`; no method-body logic change is needed.
- [UID:000062] and [UID:0000JT] already route both layout tables through `HeadSelectDialog`; support text may note that [UID:000281] now defines the high/current storage rather than leaving an empty emitter.
- [UID:00027Z] remains a separate primary-table page; do not edit it under this callback unless supervisor explicitly pairs the primary-table implementation.
- [UID:000282] remains no-code padding and must not be merged into [UID:000281].
- [UID:0000SW] remains the source-facing global alias page for `g_useEpfAssets`; [UID:000281] is only a consumer dependency, not the owner of that global.

## Scoped Validators For Implementation

Report-only pass ran no validators and performed no leases. During implementation, use scoped leases only while actively editing/validating and release immediately afterward.

Minimum target-only validation:

> Executable block R001 was removed from this report and preserved verbatim in [000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md](000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, validate only the touched support files:

> Executable block R002 was removed from this report and preserved verbatim in [000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md](000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated-refresh check after the target validator:

> Executable block R003 was removed from this report and preserved verbatim in [000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md](000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated result: `HeadSelectDialog.cpp` contains the `s_highResHeadVerticalOffsets[913]` definition before [UID:0001FI] uses it, and [UID:000281] no longer appears as an empty emitter marker.

## Implementation Tracking Checklist

- [x] Supervisor accepts this report for implementation. Proof: `tools/leaser/Agents/Agent-B005/goal.md` assignment `B005-implement-000281-head-select-secondary-table-20260625` names this report as accepted for implementation.
- [x] Lease only the exact accepted target/support by-* files immediately before edits. Proof: leased only `by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md` as `B005`; no support docs were leased or edited.
- [x] In [UID:000281], set `COMPLETION:91`, `CONFIDENCE:93`, and `EMITTER_POSITION_OPTIONAL:0`. Proof: target metadata now has `COMPLETION:91`, `CONFIDENCE:93`, and `EMITTER_POSITION_OPTIONAL:0`; validator command `000000001446` reported `completion_update`, `confidence_update`, and emitter-position registry update.
- [x] In [UID:000281], replace the formal `RECONSTRUCTION_CPP CODE` block with the exact block above. Proof: target formal block now matches this report's formal insertion text exactly and declares `int s_highResHeadVerticalOffsets[913]`.
- [x] In [UID:000281], update summary/evidence/reconstruction notes to state that the exact initializer is now transcribed and the thirteen tail slots are image zeroes patched by [UID:0001FI]. Proof: target summary and reconstruction notes now say formal C++ declares the exact initializer, indices `900..912` remain image-zero initializer entries, and [UID:0001FI] owns the constructor runtime patches.
- [x] In [UID:000281], add a change-log entry citing live MCP session `80de0a67`, byte hash `eae0749f6d3e3861b8ba222b59a921b37a67d2b77340284c6df7560100f230b3`, xrefs, instruction forms, and boundary evidence. Proof: target evidence and 2026-06-25 change-log entry record session `80de0a67`, `server_health` ok, exact byte/dword counts, SHA-256 hash, base xrefs, tail-write xrefs, operand forms, and successor-boundary evidence.
- [x] If supervisor includes support sync, update only the listed HeadSelect support docs with the support facts above. Proof: support docs were inspected and already state [UID:000281] routes through `HeadSelectDialog`, uses `s_highResHeadVerticalOffsets[913]`, and is paired with `s_normalHeadVerticalOffsets[904]`; no support edit was necessary under the callback's minimum target-page scope.
- [x] Do not edit [UID:00027Z], [UID:000280], [UID:000282], generated files, project-level files, validator state/cache, lock files, IDA DB, or manual coverage reports unless supervisor explicitly expands the callback. Proof: no manual edits were made to those files; generated/project-level/tool state changes were validator-owned side effects from command `000000001446`.
- [x] Run scoped validator commands for touched docs, confirm `ok:1`, and confirm generated refresh no longer leaves [UID:000281] as empty. Proof: ran `python .\tools\validator.py --mode file --file by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md --apply --queue-timeout 240 --wait-generated` from `source-3/project-documentation`; exit code `0`, `command_id: 000000001446`, `command_timestamp: 2026-06-25T13:33:15-04:00`, `ok: 1`, `generated_refresh: completed`, `generated_refresh_command_id: 000000001446`. Generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp` header now has validator command `000000001446`, [UID:000281] emits `s_highResHeadVerticalOffsets[913]`, and [UID:000281] is no longer an empty emitter marker.
- [x] Release all leases immediately after validation. Proof: ran `python .\tools\leaser\leaser.py B005 unlease by-memory\0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md`; current lease report has no `B005` lease.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/000281-HeadSelectDialogLayoutTableSecondary-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/000281-HeadSelectDialogLayoutTableSecondary-source-quality.md","timestamp":"2026-06-25T13:36:42","uid":"000281"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000281-HeadSelectDialogLayoutTableSecondary-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/000281-HeadSelectDialogLayoutTableSecondary-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000281"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
