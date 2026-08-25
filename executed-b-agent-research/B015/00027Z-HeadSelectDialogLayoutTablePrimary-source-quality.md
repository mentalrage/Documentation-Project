** TARGET-REPORT-UID:00027Z **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00027Z] HeadSelectDialogLayoutTablePrimary Source-Quality Report

Agent: B015  
Assignment: B015-report-00027Z-head-select-dialog-layout-table-primary-20260625  
Mode: report-only research; no by-* implementation edits performed.

## Outcome

Recommended disposition: populate [UID:00027Z] with the exact mutable `int` static initializer for `s_normalHeadVerticalOffsets[904]`, keep owner/emitter [UID:000062] `HeadSelectDialog`, and set `EMITTER_POSITION_OPTIONAL:0` so the table declaration is emitted before [UID:0001FI] `HeadSelectDialogCore` uses it.

The existing "blank because full initializer is not transcribed" rationale is no longer a sufficient final state. Live IDA MCP bytes produce an exact initializer for this target. A covered-by/comment-only formal block is not the best result for this page because [UID:0001FI] references and patches the table but does not define the storage; generated `HeadSelectDialog.cpp` currently still has an empty emitter marker for this UID.

## Current State

- Target: `by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md`
- Current target header: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:000062`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000062`, blank formal C++.
- Generated tracker/output is stale: `auto-generated/-ag-research-tracker.md` still reports this row as `72/88`, and generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp` still has `// UID:00027Z ... Completion:72 | Confidence:88 | Empty Emitter Marker`.
- Current generated `HeadSelectDialog.cpp` uses `s_normalHeadVerticalOffsets` and `s_highResHeadVerticalOffsets` in [UID:0001FI] code but does not define either symbol.
- Support pages agree on source routing through [UID:0000JT] `ui/dialogs/HeadSelectDialog.cpp`; [UID:000062] is the direct class owner and current emitter.

## Evidence Checked

Local documentation checked:

- Target page [UID:00027Z].
- [UID:000062] `by-class/HeadSelectDialog.md`.
- [UID:0000JT] `by-file/HeadSelectDialog.md`.
- [UID:0001FI] `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`.
- [UID:000281] `by-memory/0x0066eea0-0x0066fce4.HeadSelectDialogLayoutTableSecondary.md`.
- [UID:000280] `by-memory/0x0066ed20-0x0066eea0.HeadSelectDialogLayoutPadding.md`.
- `by-global/g_useEpfAssets.md`.
- `by-project-structure/proposed-source-tree.md`.
- Generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp`.
- Executed prior report `executed-b-agent-research/B001/0001FI-HeadSelectDialogCore-source-quality.md`.

IDA MCP evidence is current and mandatory evidence was available:

- MCP session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `server_health` returned `status:"ok"` during this pass.
- `get_bytes` was used for the full target range, secondary table comparison range, and the padding range.
- `xrefs_to`, `insn_query`, `decompile`, and `entity_query` were used on the target and HeadSelect core users.

## Current MCP Byte Facts

Primary table `0x0066df00-0x0066ed20`:

- Byte count: `0xe20` / 3616.
- Dword count: 904.
- Static image/body count before runtime tail: 900 dwords.
- Image tail: indices `900:0`, `901:0`, `902:0`, `903:0`.
- Nonzero dwords: 100, all within the static 900-entry body.
- Nonzero bytes: 337.
- Signed dword range: min `-12`, max `20`.
- First 40 signed dwords: `-10, -10, -10, -10, -10, 11, -10, -3, -10, -10, -10, -10, -2, 10, 9, 9, 15, -10, -10, 0, 14, 12, 13, 19, -10, 20, 9, -4, -3, 12, 20, -10, 11, -10, -10, -10, -10, -5, -12, -10`.
- Last 40 image dwords: all zero.
- SHA-256 over the exact 3616 MCP bytes: `22106496b2132daaef4c64e58a9ff1415a099b3f012516c4a5acd24c692611bc`.

Comparison/support:

- Secondary high/current table `0x0066eea0-0x0066fce4`: 3652 bytes, 913 dwords, 900 static dwords plus thirteen zero-in-image tail slots, 105 nonzero static dwords, signed range `-15..15`, SHA-256 `eae0749f6d3e3861b8ba222b59a921b37a67d2b77340284c6df7560100f230b3`.
- Padding `0x0066ed20-0x0066eea0`: 384 bytes, zero nonzero bytes, SHA-256 `a1a4f5721c1c4610af7f71078f3a68c330536d679803b0e0507ee8dc10c5dfca`.

## Current MCP Xrefs And Use Sites

`xrefs_to` for the target:

| Address | Current MCP xrefs | Role |
| --- | --- | --- |
| `0x0066df00` | `0x00551145`, `0x005513f7`, `0x00551b9e` | Base table use inside refresh, populate, constructor. |
| `0x0066ed10` | `0x00551b29` | Constructor writes normal tail index 900. |
| `0x0066ed14` | `0x00551b33` | Constructor writes normal tail index 901. |
| `0x0066ed18` | `0x00551b3d` | Constructor writes normal tail index 902. |
| `0x0066ed1c` | no xrefs | Normal tail index 903 remains zero in image and has no observed direct write. |
| `0x0066ed20` | no xrefs | Successor padding start is not part of the table. |

`insn_query` over `0x00551030-0x005520e5` confirms the exact operand forms:

- `0x00551145`: `mov al, byte ptr dword_66DF00[eax*4]`.
- `0x005513f7`: `mov al, byte ptr dword_66DF00[eax*4]`.
- `0x00551b9e`: `sub ecx, dword_66DF00[eax*4]`.
- `0x00551b29`: `mov dword_66ED10, 0FFFFFFFBh`.
- `0x00551b33`: `mov dword_66ED14, 0FFFFFFF8h`.
- `0x00551b3d`: `mov dword_66ED18, 0FFFFFFFEh`.
- No instruction match for `0x0066ed1c` in the core range.

Hex-Rays decompile confirms:

- `RefreshHeadPreview` branches on `byte_66DA97 == 1`; high branch uses `LOBYTE(dword_66EEA0[v3])`, normal branch uses `LOBYTE(dword_66DF00[v8])`.
- `PopulateHeadButtons` branches on `byte_66DA97 == 1`; high branch loads `dword_66EEA0[v7]`, normal branch loads `dword_66DF00[v7]`, then writes the low byte into object-status draw-offset storage.
- Constructor high branch writes high table tail slots and computes `this+712 = objectDrawOffset - dword_66EEA0[selectedHead]`.
- Constructor normal branch writes `dword_66ED10 = -5`, `dword_66ED14 = -8`, `dword_66ED18 = -2`, then computes `this+712 = objectDrawOffset - dword_66DF00[selectedHead]`.

`entity_query` found no recovered source symbol for the table island; current IDB names remain address-derived `dword_66DF00`/tail dword names through decompile refs. The source-facing `s_normalHeadVerticalOffsets[904]` name remains an evidence-backed reconstruction name, not recovered debug/source spelling.

## Positive Evidence

- Range and count are exact: 904 little-endian signed dwords occupy exactly `0x0066df00-0x0066ed20`.
- The only direct base consumers are HeadSelectDialog methods in [UID:0001FI].
- The table is paired with the high/current EPF companion [UID:000281], selected through process-wide `g_useEpfAssets` / `byte_66DA97`.
- The constructor uses the full dword table value for the selected head; this proves `int`/dword storage, not a byte-only array.
- Refresh and population use the low byte only at the object-status draw-offset write site; that is a use-site truncation, not storage type evidence.
- Runtime tail writes are constructor behavior, not image initializer values. The correct static initializer has zeroes at indices 900-903.
- The successor padding is all zero and unreferenced; it should remain [UID:000280], not be merged into this target.
- The generated core code already references the reconstructed table name, so defining this storage on the data page reduces generated-source incompleteness rather than duplicating behavior.

## Negative Evidence And Rejected Alternatives

- Byte table rejected: the constructor subtracts `dword_66DF00[eax*4]` and writes dword tail slots.
- `const` table rejected: constructor writes indices 900, 901, and 902 at runtime.
- Initializer with patched tail values rejected: the PE image has zero dwords at indices 900-903; runtime code performs the `-5, -8, -2` writes.
- Covered-by/comment-only C++ rejected for this target: [UID:0001FI] models the methods and patch behavior but does not define `s_normalHeadVerticalOffsets`; current generated output still emits an empty marker for [UID:00027Z].
- CreateUserDialogs or image-control ownership rejected: direct xrefs all land in HeadSelectDialog core, and the source-tree/file pages place this packet-driven in-game dialog under `ui/dialogs/HeadSelectDialog.cpp`.
- Merge with [UID:000281] rejected: high table has a separate base address, separate tail length, and separate refs.
- Merge with [UID:000280] padding rejected: MCP bytes show all-zero padding and xrefs show no direct ref to `0x0066ed20`.
- Original source spelling remains unresolved; this affects confidence ceiling but not whether the storage should emit.

## Heuristic And Source-Quality Reanalysis

The page passes the source-declared/generated-binary static-data heuristic. It is non-text memory, but it is not disposable padding: the binary contains source-authored static initializer data, and HeadSelectDialog methods address it as a single indexed array.

The current score gate is satisfied: `RECONSTRUCTABLE:TRUE`, nonblank emitter [UID:000062], and `(86 + 91) / 2 = 88.5`. The earlier blank-C++ reason was practical transcription debt, not a proof that no code belongs on this page. Current MCP bytes remove that transcription blocker.

The best source shape is a mutable file-private `int` array in the same anonymous-namespace storage area as the HeadSelect helper functions. Because the core functions are emitted before this target in the current generated file, the implementation should set `EMITTER_POSITION_OPTIONAL:0` so the declaration appears before the [UID:0001FI] method block.

The paired high/current table [UID:000281] should receive a parallel treatment in a later or same authorized implementation pass; otherwise generated `HeadSelectDialog.cpp` will still have the unresolved `s_highResHeadVerticalOffsets` symbol. That is not a reason to keep [UID:00027Z] blank.

## Ranked Ownership And Source Disposition

1. Preferred: [UID:00027Z] emits `s_normalHeadVerticalOffsets[904]` as mutable file-private static data under [UID:000062] / [UID:0000JT] `HeadSelectDialog.cpp`, before [UID:0001FI]. This matches bytes, xrefs, class ownership, generated references, and runtime tail behavior.
2. Acceptable only as a temporary partial state: keep blank C++ with a note that transcription remains pending. This should not be used as final source-quality disposition after this report.
3. Rejected: comment-only covered-by [UID:0001FI]. The core page covers behavior, not storage definition.
4. Rejected: no-code exact memory proof. This target is reconstructable source-declared static data with direct source-facing consumers.
5. Rejected: split/merge into padding, high table, CreateUser, image-control, or generic layout-row ownership.

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

Completion should rise because the exact initializer can now be formalized and the stale empty-emitter state can be cleared. Confidence should remain below perfect because `s_normalHeadVerticalOffsets` is a reconstructed source-facing name, not recovered original source spelling, and [UID:000281] still needs the same initializer treatment for the generated file to be complete as a pair.

## Formal C++ Insertion Text

Insert this exact block between the [UID:00027Z] formal C++ BEGIN/END lines. Keep the image tail zeroes; constructor patch code in [UID:0001FI] remains responsible for indices 900-902 at runtime.

```cpp
namespace {

int s_normalHeadVerticalOffsets[904] = {
    -10, -10, -10, -10, -10, 11, -10, -3, -10, -10, -10, -10, -2, 10, 9, 9,
    15, -10, -10, 0, 14, 12, 13, 19, -10, 20, 9, -4, -3, 12, 20, -10,
    11, -10, -10, -10, -10, -5, -12, -10, -10, -4, -10, -10, 11, -10, -10, 20,
    -10, -10, -10, -10, -10, 15, 11, -10, -10, -10, -10, -10, -10, -10, -10, -10,
    -7, -6, -8, -1, -10, -10, -10, -10, 17, -10, -10, -10, -4, 11, 13, -10,
    -3, -10, -4, -10, -4, -5, -3, -2, -3, 0, -5, -10, -7, -3, -4, -4,
    -4, -10, -4, -4, -5, -5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
    0, 0, 0, 0, 0, 0, 0, 0,
};

} // namespace
```

## File-Specific Implementation Tracking Checklist

- [x] Supervisor authorizes implementation callback and leases for [UID:00027Z].
  - Proof: 2026-06-25 implementation callback received in `Agent-B015/goal.md`; B015 leased `by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md` immediately before editing and released it after the edit/validator batch.
- [x] Update [UID:00027Z] formal C++ with the exact block above.
  - Proof: target formal `RECONSTRUCTION_CPP` now contains `namespace { int s_normalHeadVerticalOffsets[904] = { ... }; }`; post-edit count check found 904 explicit entries, 100 nonzero entries, signed range `-12..20`, and tail indices `900-903` as `0, 0, 0, 0`.
- [x] Set [UID:00027Z] `EMITTER_POSITION_OPTIONAL:0` so the table appears before [UID:0001FI] method code.
  - Proof: target metadata has `EMITTER_POSITION_OPTIONAL:0`; generated `auto-generated/NexusTK/ui/dialogs/HeadSelectDialog.cpp` from validator command `000000001427` emits `s_normalHeadVerticalOffsets[904]` at the top before `PatchNormalHeadOffsets()`.
- [x] Update [UID:00027Z] score to `COMPLETION:91`, `CONFIDENCE:93` unless supervisor chooses a different grading after incorporation.
  - Proof: target header is `COMPLETION:91` and `CONFIDENCE:93`; validator output recorded `completion_update 00027Z ... 91` and `confidence_update 00027Z ... 93`.
- [x] Update the target summary/reconstruction notes to remove the stale "full initializer not transcribed" blocker and record the 2026-06-25 MCP byte/xref facts.
  - Proof: target now has `Current MCP Byte Facts`, `Xref Map And Use Sites`, `Source Reconstruction Notes`, `Rejected Alternatives And Negative Evidence`, and `Score Rationale` sections with session `80de0a67`, byte counts, SHA-256, xrefs, operand forms, tail-write facts, emitted ordering, and the superseded blank-C++ blocker.
- [x] Do not edit [UID:000280] padding except to leave it separate and no-code.
  - Proof: [UID:000280] was not edited; target records the 384-byte zero-padding separation and keeps merge-with-padding rejected.
- [x] Queue or pair a [UID:000281] implementation pass for `s_highResHeadVerticalOffsets[913]`; generated `HeadSelectDialog.cpp` remains incomplete until both table symbols are defined.
  - Proof: [UID:000281] was not edited per callback scope; target records that [UID:000281] still needs the parallel `s_highResHeadVerticalOffsets[913]` implementation pass and that B005 is assigned that report-only work. Generated `HeadSelectDialog.cpp` still shows [UID:000281] as an empty emitter marker.
- [x] Regenerate/validate only under supervisor implementation instructions, including generated `HeadSelectDialog.cpp` ordering and tracker/coverage refresh.
  - Proof: ran only the callback validator command from `source-3/project-documentation`: `python .\tools\validator.py --mode file --file by-memory\0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md --apply --queue-timeout 240 --wait-generated`; command `000000001427`, timestamp `2026-06-25T07:03:24-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`. Generated `HeadSelectDialog.cpp` header has matching command id/timestamp; generated tracker reports `91/93`; generated memory coverage reports `coded`, emitter position `0`, and `emits_code:true`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00027Z-HeadSelectDialogLayoutTablePrimary-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/00027Z-HeadSelectDialogLayoutTablePrimary-source-quality.md","timestamp":"2026-06-25T07:16:36","uid":"00027Z"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
