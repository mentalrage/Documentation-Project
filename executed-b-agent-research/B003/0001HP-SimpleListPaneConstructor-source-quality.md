** TARGET-REPORT-UID:0001HP **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 Report - [UID:0001HP] SimpleListPane Raw Constructor

Assignment: `B003-report-0001HP-simple-list-pane-constructor-20260625`  
Mode: report-only research; no by-* docs, generated files, coverage reports, validator state/cache, tool state, or IDA DB were edited.  
Target: `by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md`

## Final Recommendation

The target should remain a reconstructable emitting SimpleListPane source constructor and should no longer leave formal C++ blank.

Recommended target metadata:

| UID | Completion | Confidence | Owner | Reconstructable | Emitters | Emitter position | Formal C++ disposition |
| --- | ---: | ---: | --- | --- | --- | --- | --- |
| 0001HP | 88 | 90 | 0000D8 | TRUE | 0000D8 | blank | Insert the constructor body below in `RECONSTRUCTION_CPP CODE`. |

The current blank-code rationale is no longer sufficient. Current IDA MCP evidence resolves the call order, bounds type, owner, object/vtable identity, and ABI signature enough for first-draft source reconstruction. The remaining caveats - raw bytes are not an IDA function, no direct start xrefs, no pointer-table hits, and the first explicit parameter is unused - cap confidence but do not justify a blank emitter.

## Formal Reconstruction

Use this exact `RECONSTRUCTION_CPP CODE` insertion text for [UID:0001HP]:

```cpp
SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)
    : ListPane(4,
               10,
               static_cast<unsigned short>(bounds->right - bounds->left),
               static_cast<unsigned short>(bounds->bottom - bounds->top),
               1,
               1,
               1)
{
}
```

This is formal insertion text, not a side snippet. The unnamed first parameter is intentional: `retn 8` proves two explicit 32-bit arguments are part of the ABI, while the body never reads `[ebp+8]`. I do not recommend inventing a source-facing name for that argument without caller evidence.

## Current Target State

The target page currently has `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000D8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000D8`, with blank formal C++. The owner and emitter are correct, but the report should update the implementation-facing content:

- Keep owner/emitter as `0000D8` (`SimpleListPane`).
- Keep `RECONSTRUCTABLE:TRUE`.
- Leave `EMITTER_POSITION_OPTIONAL` blank.
- Replace the blank `RECONSTRUCTION_CPP` block with the formal constructor above.
- Correct the stale behavior wording that describes `ListPane(4, 10, width, 1, height, 1, 1)`. The live call is `ListPane(4, 10, width, height, 1, 1, 1)`.
- Add current MCP evidence and explain the unused first argument as a resolved ABI/signature fact, not an unresolved source-quality blocker.

## Live IDA MCP Evidence

MCP was available and responsive. Session `80de0a67` was active on `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` reported `status: ok`, Hex-Rays ready, and auto-analysis ready.

Target boundary and function state:

- `lookup_funcs` reports `0x005739a0` and `0x005739f6` are not IDA functions; the next function starts at `0x00573a00` as `sub_573A00`.
- Bytes before the target at `0x0057399e` are `cc cc`; bytes after `0x005739f6` are `cc` padding.
- `make_signature_for_range(0x005739a0, 0x005739f6)` is unique for the 86-byte body.
- `xrefs_to(0x005739a0)` and `xrefs_to(0x005739f6)` returned zero references.
- `find_bytes` for absolute pointer `a0 39 57 00` and RVA pointer `a0 39 17 00` returned zero matches.

Instruction-level constructor evidence from `insn_query(0x005739a0, 0x005739f6)`:

- The body reads only the second explicit argument: `mov edx, [ebp+0Ch]`.
- It computes height from `[edx+0x0c] - [edx+0x04]`, matching `RectBounds::bottom - RectBounds::top`.
- It computes width from `[edx+0x08] - [edx+0x00]`, matching `RectBounds::right - RectBounds::left`.
- It pushes constructor arguments in this effective source order before `call sub_4F3A50`: `4`, `10`, `width`, `height`, `1`, `1`, `1`.
- It writes SimpleListPane vtables to `[esi] = 0x00624c64`, `[esi+0xa0] = 0x00624cec`, and `[esi+0xa4] = 0x00624d1c`.
- It returns `this` in `eax` and exits with `retn 8`.

ListPane constructor evidence:

- `analyze_function/decompile(0x004f3a50)` shows `sub_4F3A50` as the `ListPane` constructor route used by many list controls.
- The decompile initializes the `ScrollablePane` base, installs three ListPane vtables, allocates the primary and selection list helpers, stores selected index `-1`, calls the point/size helper for dimensions, and sets control bytes.
- The current child call at `0x005739ce` is one of the broad caller fanout entries and matches the documented `ListPane` source constructor role.

Vtable and type/name evidence:

- `xrefs_to(0x00624c64)`, `xrefs_to(0x00624cec)`, and `xrefs_to(0x00624d1c)` include this raw constructor plus the SimpleListPane destructor/scalar-deleting destructor functions.
- `entity_query` found the SimpleListPane RTTI/vtable naming evidence, including `??_7SimpleListPane@@6B@`.
- `search_structs/type_query` found no local IDA UDT for `SimpleListPane`, `RectBounds`, or `ListPane`; this supports keeping project documentation names as source-facing names rather than relying on IDA UDT recovery.
- No embedded `SimpleListPane.cpp`, `ListPane.cpp`, or `RectBounds` source filename string was found.

## Support Documentation Evidence

The project documentation gives enough source-facing support for the constructor:

- `by-class/SimpleListPane.md` owns [UID:0001HP] as the SimpleListPane constructor child and already treats the class as an emitting UI control class.
- `by-file/SimpleListPane.md` places the class in `NexusTK/ui/controls/SimpleListPane.cpp` and already states the intended base call as `ListPane::ListPane(4, 10, width, height, 1, 1, 1)`.
- `by-class/ListPane.md`, `by-file/ListPane.md`, and the ListPane constructor memory pages support `ListPane` as the reusable selectable list base called by this target.
- `by-class/RectBounds.md`, `by-file/RectBounds.md`, `by-type/by-struct/RectBoundsLayout.md`, and generated `NexusTK/ui/core/RectBounds.cpp` support the field names `left`, `top`, `right`, and `bottom`, with width as `right - left` and height as `bottom - top`.
- Generated UI control outputs already use source-facing `const RectBounds *bounds` constructor parameters in comparable control constructors.
- The accepted raw-constructor precedent `by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md` shows that raw/non-function/no-direct-start-reference constructors can emit formal first-draft C++ when owner, base call, arguments, and stores are resolved.

Generated `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` currently contains only empty emitter markers, including stale marker scores for this UID. That is expected before implementation and generated refresh; the report should not edit generated output.

## Heuristic And Inference Reanalysis

This target is source-authored constructor code, not padding, compiler-only glue, or a no-owner mixed aggregate.

- Raw-function heuristic: IDA does not define a function at `0x005739a0`, and there are no direct start xrefs or pointer hits. This remains a confidence cap.
- Constructor-shape heuristic: prologue/body/epilogue, `this` in `ecx`, base constructor call, vtable installs, `eax = this`, and `retn 8` strongly identify source constructor code.
- Ownership heuristic: the three vtable writes and RTTI/vtable names identify SimpleListPane, so `CANONICAL_OWNER:0000D8` remains the best owner.
- Source-placement heuristic: `SimpleListPane.cpp` is the best file placement. `ListPane.cpp` is only the base dependency location; ServerSelect placement is rejected because the adjacency is read-only-data layout/link order, not source ownership.
- Range heuristic: the exact byte range begins after `cc cc` padding and ends before `0x00573a00` destructor code, so no split/merge is recommended.
- Argument heuristic: `[ebp+0x0c]` is a `RectBounds` pointer by field offsets and current project type docs. `[ebp+0x08]` is part of the ABI but unused in the body; retaining it as an unnamed `int` is the most precise source-facing choice currently supported.
- Base-call heuristic: the current target page's old `width, 1, height` ordering is incorrect. The push order and `ListPane` decompile support `ListPane(4, 10, width, height, 1, 1, 1)`.

No rare no-code proof is warranted because the current evidence resolves the previous source-shape blockers.

## Metadata Ledger For Related Pages

No new child ranges or split-index pages are proposed. The exact target child and support pages should be handled as follows:

| UID | Page | Completion | Confidence | Owner | Reconstructable | Emitters | Position | Formal C++ disposition |
| --- | --- | ---: | ---: | --- | --- | --- | --- | --- |
| 0001HP | `by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md` | 88 | 90 | 0000D8 | TRUE | 0000D8 | blank | Insert formal constructor text. |
| 0000D8 | `by-class/SimpleListPane.md` | keep current 87 | keep current 87 | 0000NQ | TRUE | 0000NQ | blank | Update child status/support notes; class page C++ can remain governed by class-level policy. |
| 0000NQ | `by-file/SimpleListPane.md` | keep current 87 | keep current 86 | FILE | N/A - by-file header has no reconstructable field | N/A | N/A | Update proposed contents/status to show [UID:0001HP] now emits constructor code. |
| 0001W3 | `by-type/by-struct/SimpleListPaneLayout.md` | keep current 85 | keep current 88 | 0000D8 | TRUE | 0000D8 | blank | Correct stale wording if it implies fixed `4`/`10` are written as dimensions at `+0x140/+0x144`; MCP shows dimensions come from bounds. |
| 0003D5 | `by-memory/0x00624c64-0x00624d24.SimpleListPaneVtableData.md` | keep current 85 | keep current 91 | 0000D8 | TRUE | 0000D8 | blank | No raw vtable C++; optionally add current constructor-store evidence. |
| 00026F | `by-memory/0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData.md` | keep current 85 | keep current 91 | NONE | FALSE | blank | blank | No ownership change; exact children remain the source-emitting pages. |

## Exact Documentation Changes To Apply After Supervisor Acceptance

Target page:

- Change target score to `COMPLETION:88` and `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000D8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D8`, and blank `EMITTER_POSITION_OPTIONAL`.
- Insert the formal `SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)` reconstruction block above.
- Fix all behavior/status wording to use `ListPane(4, 10, width, height, 1, 1, 1)`.
- Add current IDA MCP evidence for no function object, raw-range bytes, no pointer hits, unique signature, exact push order, three SimpleListPane vtable stores, and `retn 8`.
- Add `RectBoundsLayout` or equivalent RectBounds support to cross-references/evidence if missing.
- Explain that the unused first argument is intentionally retained as an unnamed `int`, not left as an open investigation item.

Support pages:

- Update `by-class/SimpleListPane.md` to mark [UID:0001HP] as formal-constructor ready instead of blank due to unresolved source shape.
- Update `by-file/SimpleListPane.md` so the proposed contents/status match the formal constructor emission and the corrected `ListPane(4, 10, width, height, 1, 1, 1)` call.
- Review `by-type/by-struct/SimpleListPaneLayout.md` and correct any wording that maps constants `4` and `10` to the bounds-derived size fields. The ListPane constructor receives fixed list-item/list-capacity values first, then width and height.
- Leave `SimpleServerSelectReadOnlyData` ownership as non-emitting aggregate evidence only; do not move this constructor under ServerSelect.
- Do not hand-edit generated output. Refresh generated output only through the accepted project flow after documentation implementation.

## Implementation Checklist

- [x] Edit only the accepted target/support documentation pages after supervisor callback; do not edit by-* docs during report-only review.
  - Proof: implementation callback applied edits only to `by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md`, `by-class/SimpleListPane.md`, `by-file/SimpleListPane.md`, and `by-type/by-struct/SimpleListPaneLayout.md`. The only non-by-* edit was this Agent-B003 report checklist update.
  - Lease proof: B003 leased those four by-* files together immediately before editing; `leaser.py` returned `Success` for all four. B003 released the same four files immediately after the edit/validator batch; `leaser.py` returned `Success` for all four, and `tools/leaser/Agents/current_leases.md` had no B003 rows afterward.
- [x] Update [UID:0001HP] metadata to `COMPLETION:88`, `CONFIDENCE:90`, owner `0000D8`, reconstructable `TRUE`, emitter `0000D8`, blank emitter position.
  - Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000D8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000D8`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into [UID:0001HP].
  - Proof: target `RECONSTRUCTION_CPP CODE:BEGIN/END` now contains `SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)` with the exact accepted `ListPane(4, 10, static_cast<unsigned short>(bounds->right - bounds->left), static_cast<unsigned short>(bounds->bottom - bounds->top), 1, 1, 1)` initializer shape.
- [x] Replace stale `ListPane(4, 10, width, 1, height, 1, 1)` wording with `ListPane(4, 10, width, height, 1, 1, 1)`.
  - Proof: target behavior, reconstruction notes, support class/file notes, and layout notes now use the corrected order. The stale order remains only in a historical "Before" change note documenting what was corrected.
- [x] Add the 2026-06-25 IDA MCP evidence for boundary, no xrefs/pointer hits, unique bytes, argument reads, base call, vtable writes, and `retn 8`.
  - Proof: target `Evidence Notes` now records live session `80de0a67`, `server_health` status, `lookup_funcs` raw/no-function boundaries and successor functions, raw padding/body bytes and unique signature, `insn_query` field reads and push order, no xrefs/pointer hits, vtable-store xrefs, `ListPane` decompile evidence, and no local IDA UDT/source-filename evidence. `Signature And Call Shape`, `Touched State`, `Parent Gate Analysis`, and `Score Rationale` were updated to carry the same facts into the durable target doc.
- [x] Update SimpleListPane class/file support docs to remove the now-resolved source-shape blocker for [UID:0001HP].
  - Proof: `by-class/SimpleListPane.md` method row now marks [UID:0001HP] formal-constructor ready, documents the unnamed unused ABI argument, `RectBounds` reads, corrected base call, and child-level emission, and adds the 2026-06-25 B003 callback section. `by-file/SimpleListPane.md` proposed contents and source-quality section now state that the constructor blocker is resolved and that remaining file-level blockers are copied-text/destructor source-shape issues, not this constructor.
- [x] Correct or qualify the SimpleListPane layout support wording for ListPane dimensions if present.
  - Proof: `by-type/by-struct/SimpleListPaneLayout.md` no longer maps fixed `4` and `10` to `+0x140`/`+0x144`; those rows now state that inherited point/size storage is initialized from bounds-derived dimensions and that fixed `4`/`10` are earlier `ListPane` list-configuration arguments. The notes and change log include the 2026-06-25 MCP push-order/decompile proof.
- [x] Run the scoped validator only after supervisor implementation approval.
  - Proof: all four requested validator commands were run from `source-3/project-documentation` after the implementation callback and edits:
    - `python .\tools\validator.py --mode file --file by-memory\0x005739a0-0x005739f6.SimpleListPaneConstructor.md --apply --queue-timeout 240` -> `command_id: 000000001668`, `command_timestamp: 2026-06-25T15:00:23-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-class\SimpleListPane.md --apply --queue-timeout 240` -> `command_id: 000000001669`, `command_timestamp: 2026-06-25T15:00:25-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; validator also reported pre-existing `missing_ref_uid 0003D5` references on that page.
    - `python .\tools\validator.py --mode file --file by-file\SimpleListPane.md --apply --queue-timeout 240` -> `command_id: 000000001670`, `command_timestamp: 2026-06-25T15:00:26-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`; validator also reported pre-existing `missing_ref_uid 0003D5` references on that page.
    - `python .\tools\validator.py --mode file --file by-type\by-struct\SimpleListPaneLayout.md --apply --queue-timeout 240` -> `command_id: 000000001671`, `command_timestamp: 2026-06-25T15:00:28-04:00`, exit `0`, `ok: 1`, `generated_refresh: deferred`.
  - Side-effect proof: the validator reported `projected_stats_update` and registry/autogen updates as part of normal scoped validation; no generated/project-level/tool-state files were manually edited.
- [x] Confirm refreshed generated `NexusTK/ui/controls/SimpleListPane.cpp` contains the constructor and that no coverage/report files are hand-edited.
  - Proof: `python .\tools\validator.py --queue-status` at `command_id: 000000001675`, `command_timestamp: 2026-06-25T15:01:13-04:00`, reported zero queued or processing generated-refresh jobs. `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` then had `validator-command-id: 000000001671`, `validator-refreshed-at: 2026-06-25T15:00:28-04:00`, and contained the UID `0001HP` `SimpleListPane::SimpleListPane(int /*unused*/, const RectBounds *bounds)` constructor. No manual `-coverage-report.md`, generated report, project-level report, validator state, tool state, or IDA DB edits were made.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001HP-SimpleListPaneConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0001HP-SimpleListPaneConstructor-source-quality.md","timestamp":"2026-06-25T15:06:49","uid":"0001HP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
