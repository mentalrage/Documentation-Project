** TARGET-REPORT-UID:00014Q **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00014Q ExchangeItemListPaneRawConstructor Source-Quality Research

## Final Recommendation

Populate first-draft formal C++ for [UID:00014Q][by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md](../../../../../by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md).

Recommended target metadata:

| Field | Current | Recommended |
| --- | --- | --- |
| `COMPLETION` | `86` | `88` |
| `CONFIDENCE` | `89` | `90` |
| `CANONICAL_OWNER` | `00004S` | keep |
| `RECONSTRUCTABLE` | `TRUE` | keep |
| `EMITTER_UIDS` | `00004S` | keep |

Exact recommended formal `RECONSTRUCTION_CPP CODE` content:

```cpp
ExchangeItemListPane::ExchangeItemListPane()
    : ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)
{
}
```

If the supervisor wants to avoid the `ExchangeItemListRow` type dependency until declaration ordering is fixed, the binary-equivalent fallback is `ListPane(0x206, 8, 0x9c, 0x18, 0, 1, 1)`. My recommendation is the `sizeof(ExchangeItemListRow)` block above because [UID:00014L] already emits dispatcher C++ using `ExchangeItemListRow`, and [UID:00004S] documents the row layout strongly enough for source-facing use.

The old no-code reason is now too broad. Current project precedent includes raw no-function/no-xref constructors such as [UID:0001HP] `SimpleListPaneConstructor` and [UID:0003VG] `ArgumentedMenuMenuItemListRawContextConstructor` with guarded first-draft C++ when constructor shape, class owner, base initializer, and touched state are resolved. [UID:00014Q] is in that category: its behavior is a complete default constructor with no source-authored body statements beyond the `ListPane` base initializer. No direct route to the raw start remains a confidence cap, not a code blocker.

## Evidence Checked

Project docs and generated leads:

- target page [UID:00014Q][by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md](../../../../../by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md)
- direct class owner [UID:00004S][by-class/ExchangeItemListPane.md](../../../../../by-class/ExchangeItemListPane.md)
- source file route [UID:0000J9][by-file/ExchangeDialog.md](../../../../../by-file/ExchangeDialog.md)
- outer dialog class [UID:00004R][by-class/ExchangeDialog.md](../../../../../by-class/ExchangeDialog.md)
- aggregate [UID:00014K][by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md](../../../../../by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md)
- siblings [UID:00014R] and [UID:00014S]
- vtable child [UID:0003NF][by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md](../../../../../by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md)
- [UID:0003TZ][by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md](../../../../../by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) and [UID:00007A][by-class/ListPane.md](../../../../../by-class/ListPane.md)
- generated lead `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`
- executed reports B015 `00004S-ExchangeItemListPane-class-source-quality.md`, B012 `00014R-ExchangeItemListPaneRawUpsertHelper-source-quality.md`, and B015 `00014L-ExchangeDialogPacketDispatcher-source-quality.md`

Live MCP session used:

- IDB session `80de0a67`
- `server_health`: `status: ok`, module `NexusTK.exe`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`

Current MCP tools used: `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `decompile`, `make_signature_for_range`, and `analyze_function`.

## Current Binary Findings

### Boundary And Raw Status

Current `lookup_funcs` reports `Not a function` for `0x004ae05f`, `0x004ae060`, `0x004ae0a3`, `0x004ae0a4`, `0x004ae0b0`, `0x004ae167`, and `0x004ae170`. It reports the next routed virtuals as `nullsub_29` at `0x004ae1b0` size `0x3` and `sub_4AE1C0` at `0x004ae1c0` size `0x2f6`.

Current `insn_query 0x004ae060-0x004ae0b0` returns this shape:

- `0x004ae060`: `push ebp`
- `0x004ae061`: `mov ebp, esp`
- `0x004ae063`: `push ecx`
- `0x004ae064`: `push esi`
- `0x004ae065`: `push 1`
- `0x004ae067`: `push 1`
- `0x004ae069`: `push 0`
- `0x004ae06b`: `push 18h`
- `0x004ae06d`: `push 9Ch`
- `0x004ae072`: `push 8`
- `0x004ae074`: `mov esi, ecx`
- `0x004ae076`: `push 206h`
- `0x004ae07e`: `call sub_4F3A50`
- `0x004ae083`: primary `ExchangeItemListPane` vtable store at `this+0`
- `0x004ae08b`: secondary vtable store at `this+0xa0`
- `0x004ae095`: tertiary vtable store at `this+0xa4`
- `0x004ae09f-0x004ae0a3`: epilogue and `retn`
- `0x004ae0a4`: alignment directive

Current `get_bytes` confirms the constructor bytes are exactly `0x004ae060-0x004ae0a4`, followed by twelve `0xcc` bytes at `0x004ae0a4-0x004ae0b0`. The bytes at `0x004ae0b0` begin the raw upsert helper prologue `55 8b ec 81 ec 10 02 00 00 ...`.

Current `make_signature_for_range(0x004ae060, 0x004ae0a4, wildcard_operands=false)` returns a unique signature for the exact 68-byte body.

Conversions verified with `tools/int_convert.py`:

- `0x44` = decimal `68`
- `0x206` = decimal `518`
- `0x9c` = decimal `156`
- `0x18` = decimal `24`
- `0xa0` = decimal `160`
- `0xa4` = decimal `164`

### Call And Vtable Evidence

Current `xrefs_to` reports zero xrefs to:

- `0x004ae060`
- `0x004ae0a4`
- `0x004ae0b0`

Current `find_bytes` reports zero matches for obvious raw-start or boundary pointer encodings:

- VA `0x004ae060`: bytes `60 e0 4a 00`
- RVA `0x000ae060`: bytes `60 e0 0a 00`
- file-offset pattern `0x000ad460`: bytes `60 d4 0a 00`
- VA `0x004ae0a4`: bytes `a4 e0 4a 00`
- VA/RVA/file-offset patterns for successor `0x004ae0b0`

The broad `.text` `insn_query op_any` scan for immediate operands to the raw start timed out. I do not cite it as current evidence. The older B015 class report still contains a broader local PE/Capstone no-route scan; the current pass independently reconfirms no IDA xrefs and no obvious VA/RVA/file-offset pointer constants.

Current `xrefs_to` for the three vtable bases:

- `0x00619dc8`: stores at `0x004acbef`, `0x004acd9c`, and raw constructor `0x004ae083`
- `0x00619e50`: stores at `0x004acbf5`, `0x004acda2`, and raw constructor `0x004ae08b`
- `0x00619e80`: stores at `0x004acbff`, `0x004acdac`, and raw constructor `0x004ae095`

The two `ExchangeDialog` constructor sites inline the same list construction:

- `0x004acbd4-0x004acbff`: pushes `1,1,0,0x18,0x9c,8,0x206`, calls `0x004f3a50`, then installs the three `ExchangeItemListPane` vtable views.
- `0x004acd81-0x004acdac`: repeats the same base call and vtable stores for the second offered-item list.

This explains the no-route condition without rejecting source authorship: the binary retains an out-of-line constructor-shaped body, while the live `ExchangeDialog` constructor inlines equivalent construction for its two list instances.

### Base Constructor Evidence

Current `analyze_function(0x004f3a50)` identifies `sub_4F3A50` as the shared `ListPane` constructor body. Its decompilation calls `ScrollablePane`, installs `ListPane` vtables at `this`, `this+0xa0`, and `this+0xa4`, allocates primary and selection `List` objects, stores selected index `-1`, stores list/config bytes, initializes dimensions, and marks the pane visible. The current [UID:0003TZ] and [UID:00007A] docs agree that final parameter names remain unsettled, but the source-facing role is the reusable `ListPane` constructor.

The raw constructor's base-initializer arguments are therefore:

```text
ListPane(row payload size 0x206, visible/list row count 8,
         width/dimension 0x9c, row height 0x18, 0, 1, 1)
```

## Heuristic And Source-Quality Reanalysis

### Owner And Source Route

Best direct owner remains [UID:00004S] `ExchangeItemListPane`. The `this` receiver is the list pane, the raw body calls the list-pane base constructor, and all three installed vtable views are `ExchangeItemListPane` views. [UID:0000J9] `ExchangeDialog.cpp` remains the source-file route because this is a private control used only by the exchange dialog feature.

Rejected direct owners:

- [UID:0000J9] `ExchangeDialog` file: correct source route, but too broad as the direct semantic owner for a class constructor.
- [UID:00004R] `ExchangeDialog` class: constructs and contains two list controls, but the constructor body is for the nested/private list-pane class, not the outer dialog class.
- [UID:00007A]/[UID:0000KT] `ListPane`: owns the reusable base constructor, not the exchange-specific derived vtables or row type.
- [UID:00008W] `MyItemListPane`: structural analogue only. It has separate ownership and different constructor behavior.
- no-owner or non-reconstructable: rejected because the body is source-shaped NexusTK UI class construction, not padding, runtime glue, or compiler-only thunk material.

### Name And C++ Shape

Best source-facing constructor name: `ExchangeItemListPane::ExchangeItemListPane()`.

The constructor has no explicit stack arguments and returns with plain `retn`, so a default constructor is the best source-facing signature. The vtable writes are compiler-generated construction side effects and should not appear as explicit source statements. The source-authored body is empty after the base initializer.

Recommended initializer uses `sizeof(ExchangeItemListRow)` because:

- [UID:00004S] documents `ExchangeItemListRow` with key byte `+0`, padding `+1`, item id `+2`, color `+4`, padding `+5`, and `wchar_t name[256]` at `+6`, total `0x206`.
- [UID:00014L] already emits dispatcher C++ that uses `ExchangeItemListRow`.
- The raw constructor's `0x206` argument is exactly the row payload size; source-quality C++ is more likely to express that through the row type than a magic number.

The literal `0x206` remains a safe fallback if the implementation callback does not also accept row-struct declaration/order cleanup.

### Rejected C++ Alternatives

- Keep formal C++ blank solely because `0x004ae060` has no IDA function object or direct xrefs: rejected. Current project precedent treats raw no-function/no-xref constructor status as a confidence cap when constructor source shape is otherwise resolved.
- Emit the three vtable stores in C++: rejected. They are compiler-generated from the derived constructor.
- Emit `ListPane(0x206, 8, 0x9c, 0x18, 0, 1, 1)` as the primary recommendation: behaviorally correct, but less source-facing than `sizeof(ExchangeItemListRow)` now that the row type is documented and used by the dispatcher.
- Emit helper calls to [UID:00014R] or [UID:00014S]: rejected. Those are separate no-route helper candidates and are not called by this constructor.
- Move constructor ownership to the aggregate [UID:00014K]: rejected. Aggregates carry containment/source-route context; exact method children carry the source/no-code decision.

## Score Rationale

Recommended `88/90` is a narrow improvement over current `86/89`.

Completion rises because this pass adds current live MCP proof for exact bytes, unique range signature, no decompilation/function object, no start xrefs, no obvious pointer constants, two inline `ExchangeDialog` construction sites, base constructor identity, current C++ precedent comparison, and an exact formal constructor block.

Confidence rises to `90` because the constructor source shape is now stable: no explicit arguments, exact base initializer, exact class vtables, exact padding, and a documented row type. It remains below final-audit quality because the raw start has no proven direct route, the broad immediate scan timed out, final `ListPane` parameter names remain inferred, and class/row declaration ordering in generated `ExchangeDialog.cpp` still needs coordinated cleanup.

## Generated And Tracker Freshness Notes

Generated files and generated reports were not edited.

Observed generated/project-owned stale leads:

- `auto-generated/-ag-coverage-report-by-memory.md` still shows [UID:00014Q] as `76%` with older generated text, despite the source page now being `86/89`.
- `auto-generated/-ag-research-tracker.md` still shows [UID:00014Q] as `76/86`.
- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` has a fresh header (`validator-refreshed-at: 2026-06-25T16:42:32-04:00`) but still contains old empty marker comments for [UID:00004S] and [UID:00014Q] with stale scores. Treat it as a generated lead only.

If this report is accepted and implemented, validators should be run with generated freshness checks. Do not manually edit these generated files or reports.

## Implementation Tracking Checklist

Use this only after supervisor acceptance and an implementation callback. No items were applied during this report-only pass.

- [x] Lease only the accepted target/support docs immediately before editing, and release leases immediately after the edit/validator batch. Proof: B009 leased the five accepted by-* docs with `python .\tools\leaser\leaser.py B009 lease ...`; after scoped validators, `python .\tools\leaser\leaser.py B009 unlease ...` returned `Success` for all five paths, and `current_leases.md` showed no active B009 lease entries.
- [x] In [UID:00014Q] `by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md`, change `COMPLETION:86` to `88` and `CONFIDENCE:89` to `90`; keep `CANONICAL_OWNER:00004S`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00004S`. Proof: target metadata now reads `88/90`, owner/emitter remain `00004S`, and reconstructable remains `TRUE`.
- [x] Populate [UID:00014Q] formal `RECONSTRUCTION_CPP CODE` with exactly:

```cpp
ExchangeItemListPane::ExchangeItemListPane()
    : ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)
{
}
```
Proof: the formal target block now contains this exact constructor C++.

- [x] If the supervisor rejects the row-type dependency, use the binary-equivalent fallback `ListPane(0x206, 8, 0x9c, 0x18, 0, 1, 1)` instead and explicitly document that the fallback is less source-facing. Proof: not needed; current docs support `ExchangeItemListRow`, so the accepted `sizeof(ExchangeItemListRow)` form was used and the class page records the raw literal as fallback only.
- [x] Update [UID:00014Q] evidence sections with the 2026-06-25 MCP session `80de0a67`: `server_health`, `lookup_funcs`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `decompile`, `make_signature_for_range`, `analyze_function(0x004f3a50)`, and the two inline `ExchangeDialog` constructor sites. Proof: target evidence now has a dedicated `2026-06-25 B009 accepted source-quality implementation, live MCP session 80de0a67` subsection with these facts.
- [x] Replace the old [UID:00014Q] no-code wording with the current decision: no-function/no-xref status is a confidence cap, while exact constructor shape and project precedent now support guarded first-draft C++. Proof: target status, ownership/routing, B015 reanalysis, and 2026-06-25 change note all state the superseded blank-C++ decision.
- [x] Preserve negative evidence on [UID:00014Q]: no IDA function object, no xrefs to the raw start, no decompilation, zero current VA/RVA/file-offset byte-pattern hits for the raw start, broad immediate scan timed out, and no direct call route. Proof: target 2026-06-25 evidence subsection records all accepted negative checks and the timed-out broad scan limitation.
- [x] Preserve source-shape details on [UID:00014Q]: `0x44` / 68-byte body, twelve `0xcc` bytes at `0x004ae0a4-0x004ae0b0`, base call arguments, vtable installs at `+0`, `+0xa0`, `+0xa4`, and no explicit source statements after the initializer. Proof: target behavior/evidence/score sections preserve these details and the formal C++ body remains empty after the base initializer.
- [x] In [UID:00004S] `by-class/ExchangeItemListPane.md`, update the constructor row and C++ note so [UID:00014Q] is now first-draft C++ ready, while the class page itself remains a declaration/container page and [UID:00014R]/[UID:00014S] remain blank no-route helper candidates. Proof: class status C++ note, method row, no-code proof, and 2026-06-25 change note now record this exact split.
- [x] In [UID:00004S], preserve the `ExchangeItemListRow` layout and add that the constructor initializer should use `sizeof(ExchangeItemListRow)` once declaration/order is handled before dispatcher use. Proof: class purpose row-layout paragraph now includes this source-shape guidance.
- [x] In [UID:0000J9] `by-file/ExchangeDialog.md`, [UID:00004R] `by-class/ExchangeDialog.md`, and [UID:00014K] `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`, update the ExchangeItemListPane source-shape notes: raw constructor emits guarded first-draft constructor C++; raw upsert/find stay blank; the two live `ExchangeDialog` constructor sites inline equivalent list construction for controls `5` and `8`. Proof: all three support pages now contain B009 2026-06-25 notes with those facts.
- [x] Do not change [UID:00014R] or [UID:00014S] C++ blocks from this report. They remain no-route retained/private helper candidates under their current docs. Proof: no edits were made to the [UID:00014R] or [UID:00014S] files; support docs explicitly preserve their blank no-route status.
- [x] Do not edit `auto-generated/**`, project-level generated files, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any `-coverage-report.md`. Proof: manual edits were limited to the five accepted by-* docs plus this B009 report checklist; generated changes, if any, are validator-owned after scoped validation.
- [x] Run scoped validators from `source-3/project-documentation` after accepted edits, at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [00014Q-ExchangeItemListPaneRawConstructor-source-quality-removed.md](00014Q-ExchangeItemListPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Proof:

> Executable block R002 was removed from this report and preserved verbatim in [00014Q-ExchangeItemListPaneRawConstructor-source-quality-removed.md](00014Q-ExchangeItemListPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Capture validator exit codes, `ok` counts, `command_id`, `command_timestamp`, and generated-refresh state. If generated freshness matters and `--wait-generated` is available, use it; otherwise compare generated file/report headers against validator command metadata. Proof: validator command/result details are recorded above; generated refresh caught up to `validator-command-id: 000000001816`, `validator-refreshed-at: 2026-06-25T17:10:40-04:00`, which is newer than the required scoped validator command timestamps.
- [x] Confirm generated freshness after validation: [UID:00014Q] source metadata should refresh in `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` without manual generated-file edits. Proof: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` header is `validator-command-id: 000000001816` and now contains [UID:00014Q] at `Completion:88 | Confidence:90` with the constructor body; `auto-generated/-ag-memory-coverage.md` header is also `000000001816` and lists [UID:00014Q] as `coded`; `auto-generated/-ag-coverage-report-by-memory.md` header is also `000000001816` and shows the updated `88% : very-strong` summary.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python .\tools\leaser\leaser.py B009 unlease ...` returned `Success` for all five accepted by-* paths, and `current_leases.md` contains no B009 active leases.

## Report-Only Pass Status

- Changed files: created this report only.
- Leases: none taken.
- Validators: not run, because no target/support docs were edited in report-only mode.
- IDA MCP: available and used; no IDA DB edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/00014Q-ExchangeItemListPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00014Q-ExchangeItemListPaneRawConstructor-source-quality.md","timestamp":"2026-06-25T17:17:21","uid":"00014Q"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014Q-ExchangeItemListPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/00014Q-ExchangeItemListPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
