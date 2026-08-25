** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_header_missing **
# B002-MEMTOOL-00514E60 - SystemMessageMarkerScalarDeletingDestructor

## Final Recommendation

The `auto-generated/by-memory-tool-report.md` Advanced-Error-Scan warning is a real stale filename/name issue, not a missing research-content issue. The target page now correctly documents `0x00514e60-0x00514e98` as a shared `LObject` scalar deleting-destructor wrapper, but the file is still named `0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`.

Recommended action: rename the target page to:

```text
by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md
```

Keep all metadata unchanged:

| Field | Recommendation |
| --- | --- |
| UID | Keep `0001B5` |
| Range | Keep `0x00514e60-0x00514e98` |
| Title | Keep `# 0x00514e60-0x00514e98 - Shared LObject Scalar Deleting Destructor` |
| Completion / confidence | Keep `90/93` |
| `CANONICAL_OWNER` | Keep `NONE` |
| `RECONSTRUCTABLE` | Keep `FALSE` |
| `EMITTER_UIDS` | Keep blank |
| `EMITTER_POSITION_OPTIONAL` | Keep blank |
| C++ entry | Keep blank |

Score before/after: unchanged at `90/93`.

No owner, emitter, range, split/merge, or IDA repair is needed. The page is a reviewed non-emitting compiler-generated wrapper and should stay parentless/non-emitting under the current owner/emitter model.

## Why This Is Not A False Positive

The current page contains the correct semantic title, range, behavior, xref table, classification decision, and score rationale. The only mismatch is the stale filename slug:

```text
SystemMessageMarkerScalarDeletingDestructor
```

Scanner-visible token check against the current page:

| Check | Result |
| --- | --- |
| Full text contains exact old label `SystemMessageMarkerScalarDeletingDestructor` | `false` |
| Scanner-visible normalized text contains old label | `false` |
| Scanner-visible normalized text contains `SharedLObjectScalarDeletingDestructor` | `true` |
| Current title | `# 0x00514e60-0x00514e98 - Shared LObject Scalar Deleting Destructor` |

Adding the stale old label into the page would silence the scanner but would preserve an inaccurate filename. Rename is the cleaner repair because IDA and documentation now prove this is not system-message-marker-exclusive.

## Target

| Field | Value |
| --- | --- |
| Target UID | `0001B5` |
| Current target path | `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md` |
| Recommended target path | `by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md` |
| Source warning | `auto-generated/by-memory-tool-report.md`: missing document text for `SystemMessageMarkerScalarDeletingDestructor` |
| Current generated state | `not_reconstructable`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS` |

## IDA MCP Evidence

Live IDA MCP session `b001_0003gy` over `NexusTK.exe` reconfirmed the existing page evidence.

| Evidence | Result |
| --- | --- |
| `server_health` | OK; `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready |
| `lookup_funcs 0x00514e60` | `sub_514E60`, size `0x38` |
| `lookup_funcs 0x00514e98` | Not a function |
| `lookup_funcs 0x00514ea0` | `sub_514EA0`, size `0x3d`; next function after padding |
| `analyze_function 0x00514e60` | Prototype shape `void *__thiscall(void *Block, char)`; 56-byte body; no ordinary callers |
| Decompile summary | Calls `sub_4F4A90(Block)`, returns without deleting unless `(flags & 1) != 0` and `(flags & 4) == 0`, then calls `sub_4F4AC0(Block)` and returns `Block` |
| Callees | `sub_4F4A90`, `sub_4F4AC0`, `@_guard_check_icall_nop@4` |
| `xrefs_to 0x00514e60` | Exactly four data refs: `0x0061e8e0`, `0x0061e8f0`, `0x0062d6ac`, `0x0062d6d0` |
| Dialog-creator vtable refs | `0x0061e8e0` referenced by `0x00507c90` and `0x00510320`; `0x0061e8f0` referenced by `0x00507c90` and `0x00512840` |
| Header/footer vtable refs | `0x0062d6ac` and `0x0062d6d0` each have 14 data refs across system-message routines |
| Raw bytes | Five leading `0xcc` bytes before `0x00514e60`; exact 56-byte body; eight trailing `0xcc` bytes through `0x00514ea0` |

IDA fact: the function is shared by both system-message marker vtables and dialog-creator vtables. It is not exclusive to `HeaderSystemMessage` / `FooterSystemMessage`.

## Documentation Evidence

| Document | Evidence |
| --- | --- |
| Target page | Current title and prose call this `Shared LObject Scalar Deleting Destructor`; metadata is `90/93`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters |
| `by-memory/-coverage-report.md` | Row already labels the item behavior as `Shared LObject scalar deleting destructor` and classifies it as `ignored` / compiler-generated |
| `auto-generated/-ag-memory-coverage.md` | Current generated row remains `not_reconstructable`, owner `NONE`, blank emitters |
| `by-memory/-ignored.md` | Lists UID `0001B5` as a shared `LObject` scalar deleting destructor wrapper but still links the stale filename |
| `SystemMessagePanes`, `HeaderSystemMessage`, `FooterSystemMessage` docs | Still link the old filename as a non-contiguous/shared destructor helper |
| `DialogCreatorVtableData` | Documents `0x0061e8e0` and `0x0061e8f0` as dialog creator vtable slots pointing to `0x00514e60`, proving broader sharing |
| `MerchantDialogCreatorVtableData` / `PursuitMessageDialogCreatorVtableData` | Exact children identify slot 0 as a shared small scalar deleting destructor wrapper |

## Exact Recommended Edits

Apply these edits only after taking any required leases for existing by-* documentation files.

1. Rename:

```text
from: by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md
to:   by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md
```

2. In real documentation files, replace this link target/display:

```markdown
[UID:0001B5][0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md)
```

with:

```markdown
[UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md)
```

Known real-documentation update locations:

| File | Lines observed |
| --- | --- |
| `by-file/SystemMessagePanes.md` | 87 |
| `by-class/HeaderSystemMessage.md` | 19, 77, 94 |
| `by-class/FooterSystemMessage.md` | 19, 77, 94 |
| `by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md` | 98 |
| `by-memory/0x0062d5f8-0x0062da10.SystemMessageReadOnlyData.md` | 30, 114 |
| `by-memory/0x0062d6a8-0x0062d714.SystemMessageEntryVtableData.md` | 63 |
| `by-memory/0x0062d6a8-0x0062d6cc.HeaderSystemMessageVtableData.md` | 48 |
| `by-memory/0x0062d6cc-0x0062d6f0.FooterSystemMessageVtableData.md` | 48 |
| `by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md` | 72 |
| `by-memory/-ignored.md` | 3222, 3232 |

Do not manually edit `auto-generated/*`, project-level generated files, tool temp files, or agent/supervisor notes as part of the rename. Regenerate reports normally where needed.

3. `by-memory/-coverage-report.md` exact row if the supervisor applies coverage text manually or stages an equivalent generated update:

```markdown
    - [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md) 0x00514e60-0x00514e98 | compiler-generated destructor | Shared LObject scalar deleting destructor : ignored : 90% : strong : A002 Batch312 reclassified this as a non-emitting MSVC scalar deleting-destructor wrapper; live IDA `lookup_funcs`/`analyze_function`/`xrefs_to`/`get_int`/`get_bytes` confirmed exact `0x38` / 56-byte body (Verified with `int_convert.py`), no function at `0x00514e98`, successor `0x00514ea0`, no ordinary callers, callees limited to `0x004f4a90`, `0x004f4ac0`, and `0x0041b6a0`, four vtable-only refs `0x0061e8e0/0x0061e8f0/0x0062d6ac/0x0062d6d0`, all four slot dwords pointing to `0x00514e60`, and `0xcc` padding before/after. Source declarations should regenerate or fold this wrapper, so `AUTOGEN_PARENT_UID` remains blank.
```

Placement context: replace the existing `0001B5` row between the `0x00514e5b-0x00514e60` padding row and the `0x00514e98-0x00514ea0` padding row.

Generated coverage rows should become equivalent to:

```markdown
| [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md) | not_reconstructable | `NONE` |  |  | no |  | `by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md` |  |
```

and, in the not-reconstructable rollup:

```markdown
| [UID:0001B5][0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor](by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md) | not_reconstructable | `by-memory/0x00514e60-0x00514e98.SharedLObjectScalarDeletingDestructor.md` |  |  |  |
```

## Rejected Alternatives

| Alternative | Decision |
| --- | --- |
| Add the old slug text to the page | Rejected. It would satisfy the scanner but preserve a stale, misleading name. |
| Keep filename and mark warning false positive | Rejected. Current normalized page text does not contain the old filename label, and the old label is semantically too narrow. |
| Split into system-message and dialog-creator children | Rejected. There is one exact 56-byte compiler wrapper shared by four vtable slots; splitting would duplicate the same bytes. |
| Assign `CANONICAL_OWNER` to `SystemMessagePanes` | Rejected. Header/footer refs support system-message context, but dialog-creator vtable refs prove it is not a single system-message-owned body. |
| Assign `CANONICAL_OWNER` to `LObject` | Rejected. The wrapper calls `LObject` cleanup, but the emitted vtable slots are derived marker/creator ABI entries, not an `LObject` source method. |
| Add `EMITTER_UIDS` | Rejected. `RECONSTRUCTABLE:FALSE` compiler-generated wrapper has no standalone source body to emit. Source declarations for the owning classes/vtables should regenerate or fold this body. |
| IDA function repair | Rejected. IDA already has exact function `sub_514E60` with correct `0x38` size and correct successor boundary. |

## Validation And Rerun Recommendation

No documentation edits were made by Agent-B002, so no validator run was performed. No dry-run validator mode, dry-run validator flow, or memory-range edit mode was used.

After the rename/link updates are applied, rerun normal validation/report flow:

> Executable block R001 was removed from this report and preserved verbatim in [B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor-removed.md](B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor-removed.md). The archived block is non-authoritative and must not be executed.

If multiple related docs are edited, validate the changed by-* pages with the normal validator flow as well. The `memory_ranges.py report` rerun should clear the `SystemMessageMarkerScalarDeletingDestructor` Advanced-Error-Scan warning because the filename and scanner-visible page title will agree.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B002/research/B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md`

No by-memory page, generated report, coverage report, source file, or IDA database edit was made by Agent-B002 for this assignment.

Observed working-tree note: the target page and `auto-generated/by-memory-tool-report.md` were already dirty/untracked during review. Agent-B002 did not modify either file.

## Blockers

None for the MEMTOOL warning triage. The only remaining work is supervised rename/link repair and normal report regeneration.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_header_missing","source_path":"executed-b-agent-research/B002/B002-MEMTOOL-00514E60-SystemMessageMarkerScalarDeletingDestructor.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
