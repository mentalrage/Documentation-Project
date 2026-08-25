** TARGET-REPORT-UID:0001BX **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: [UID:0001BX] MenuDialogDestructorThunks

Report-only assignment: `B002-report-0001BX-MenuDialogDestructorThunks-source-quality-20260629`

Target: `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`

Report path: `tools/leaser/Agents/Agent-B002/research/0001BX-MenuDialogDestructorThunks-source-quality.md`

## Final Recommendation

Keep [UID:0001BX] as a non-emitting, non-reconstructable mixed compiler-glue index. Do not assign a canonical owner, do not add emitters, and do not insert formal C++ or marker code. The target is not one source-authored destructor body; it is an address island that aggregates exact child pages for MSVC adjusted deleting-destructor thunks and scalar deleting destructor wrappers across argumented-menu, shared client/spell, object-image, server-item, text-menu, and shared dialog/list-pane families.

Recommended target metadata after implementation:

| Field | Current source page | Recommended |
| --- | --- | --- |
| `COMPLETION` | `87` | `90` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `NONE` | `NONE` |
| `RECONSTRUCTABLE` | `FALSE` | `FALSE` |
| `EMITTER_UIDS` | blank | blank |
| Formal `RECONSTRUCTION_CPP CODE` | blank | blank |

The score can rise because current IDA MCP confirms the full function inventory, endpoint, xrefs, exact `TextMenuItemList` thunk bytes, scalar wrapper decompile, and generated-tracker staleness. It should not become reconstructable because the range is still generated ABI support and crosses multiple source families.

## Current Target State

The target source page currently has:

- `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and a blank formal C++ block.
- A stale `Item Summary` sentence saying the child remains below 85 completion even though the header is now `87/90`.
- A stale `Status` label, "Current Wave3 owners", for context classes rather than current source ownership semantics.
- An otherwise useful child/split inventory for [UID:00037A] through [UID:00037H] and neighboring shared/object-image/server-item glue.
- A stale source-policy sentence saying the C++ box stays blank because the wrappers are below a "95% final reconstruction threshold"; current by-structure rules make the reason simpler and stronger: `RECONSTRUCTABLE:FALSE`, blank emitters, mixed compiler/linker-generated glue, and no source-authored body.
- Historical change entries still mention old `AUTOGEN_PARENT_UID` wording. Those are historical and can remain as dated history, but any current-status prose should use `CANONICAL_OWNER`/`EMITTER_UIDS` language.

Generated tracker state is stale and must not be edited manually in this report-only pass:

- `auto-generated/-ag-research-tracker.md` still lists UID0001BX as `80/86`, average `83.0`, `reconstructable true`, report count `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` still carries stale source-summary details. This should be refreshed only by the normal supervisor/validator execution path after accepted implementation.

## Historical Report Search

Searched for UID, address, current name, old/generated names, and source-family terms:

- `0001BX`, `0x00520abb`, `00520abb`, `0x00520e2b`, `00520e2b`
- `MenuDialogDestructorThunks`, `MenuDialog destructor`, `destructor thunks`
- child/source terms including `00037A`, `00037C`, `00037E`, `00037G`, `TextMenuItemListDestructorThunks`, `TextMenuItemListScalarDeletingDestructor`, `ObjectImageButtonPaneDestructorThunks`, and `SharedListPaneScalarDeletingDestructor`

Opened matching executed reports or targeted snippets from:

- `executed-b-agent-research/B005/00037A-ArgumentedMenuMenuItemListDestructorThunks-source-routing.md`
- `executed-b-agent-research/B007/00037C-TextInputMenuDialogDestructorThunks-source-routing.md`
- `executed-b-agent-research/B008/00037E-TextMenuDialogDestructorThunks-source-routing.md`
- `executed-b-agent-research/B010/00037G-TextMenuItemListDestructorThunks-source-routing.md`
- `executed-b-agent-research/B001/0001C1-SharedListPaneScalarDeletingDestructor-source-quality.md`
- `executed-b-agent-research/B015/0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md`
- `executed-b-agent-research/B002/0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md`
- related class/file reports for `TextMenuDialogs`, `TextMenuItemList`, `ArgumentedMenuDialogs`, and merchant/text-menu vtable families.

Historical consensus already rejected UID0001BX as a source owner and treated it as a mixed compiler-glue ledger. The only material gap found by this current pass is that the target page still carries stale gate wording, and [UID:00037G]/[UID:00037H] should be synchronized with current MCP byte/decompile proof rather than B010's old "MCP unavailable" limitation.

## Current MCP Session Proof

MCP was available and responsive. I did not start, stop, restart, or manage IDA/MCP.

- Process status check showed `idalib-mcp.exe` PID `9400` and worker Python PID `12076`.
- `initialize` returned server `ida-pro-mcp`.
- `idb_list` returned one active session:
  - session `992d23de`
  - IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - filename `NexusTK.exe.i64`
  - `is_active:true`, `is_analyzing:false`
  - worker PID `12076`
- `server_health(database=992d23de)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.

The first compact health script reached MCP but failed to pass a database argument after my parser looked for `active` instead of `is_active`; the retry used the `idb_list` structured session id explicitly. This was a client-script extraction error, not MCP unavailability.

## Actual Evidence Checked

Function inventory from current MCP:

| Address | MCP result | Role |
| --- | --- | --- |
| `0x00520abb` | `sub_520ABB`, size `0x0b` | `ArgumentedMenuMenuItemList` adjusted destructor thunk |
| `0x00520ac6` | `sub_520AC6`, size `0x0b` | `ArgumentedMenuMenuItemList` adjusted destructor thunk |
| `0x00520ad1` | `sub_520AD1`, size `0x0b` | shared client/spell list thunk neighbor |
| `0x00520ae7` | `sub_520AE7`, size `0x0b` | object-image button thunk neighbor |
| `0x00520afd` | `sub_520AFD`, size `0x0b` | object-image control thunk neighbor |
| `0x00520b13` | `sub_520B13`, size `0x0b` | server-item list thunk neighbor |
| `0x00520b29` | `sub_520B29`, size `0x0b` | `TextInputMenuDialog` adjusted destructor thunk |
| `0x00520b34` | `sub_520B34`, size `0x0b` | `TextInputMenuDialog` adjusted destructor thunk |
| `0x00520b3f` | `sub_520B3F`, size `0x0b` | `TextMenuDialog` adjusted destructor thunk |
| `0x00520b4a` | `sub_520B4A`, size `0x0b` | `TextMenuDialog` adjusted destructor thunk |
| `0x00520b55` | `sub_520B55`, size `0x0b` | `TextMenuItemList` adjusted destructor thunk |
| `0x00520b60` | `sub_520B60`, size `0x0b` | `TextMenuItemList` adjusted destructor thunk |
| `0x00520b70` | `sub_520B70`, size `0x3b` | shared dialog default scalar wrapper |
| `0x00520bb0` | `sub_520BB0`, size `0x67` | `ArgumentedMenuMenuItemList` scalar wrapper |
| `0x00520c20` | `sub_520C20`, size `0x3b` | shared list-pane scalar wrapper |
| `0x00520c60` | `sub_520C60`, size `0x3b` | `ObjectImageButtonPane` scalar wrapper |
| `0x00520ca0` | `sub_520CA0`, size `0x3b` | `ObjectImageControlPane` scalar wrapper |
| `0x00520ce0` | `sub_520CE0`, size `0x67` | `ServerItemMenuItemList` scalar wrapper |
| `0x00520d50` | `sub_520D50`, size `0x48` | `TextInputMenuDialog` scalar wrapper |
| `0x00520da0` | `sub_520DA0`, size `0x48` | `TextMenuDialog` scalar wrapper |
| `0x00520df0` | `sub_520DF0`, size `0x3b` | `TextMenuItemList` scalar wrapper |
| `0x00520e2b` | not a function | exclusive end/padding area |
| `0x00520e30` | `sub_520E30`, size `0x9b` | successor `MessageAndMessageShowPane` family |

Current xref checks:

- `xrefs_to 0x00520df0`: code refs from `0x00520b5b` inside `sub_520B55` and `0x00520b66` inside `sub_520B60`; data ref at `0x0061ed48` primary `TextMenuItemList` vtable slot.
- `xrefs_to 0x00520b55`: one data ref at `0x0061edd0`.
- `xrefs_to 0x00520b60`: one data ref at `0x0061ee00`.
- Earlier same-session xrefs also confirmed the expected vtable-only refs for the other child functions: argumented-menu slots at `0x0061f4c4/0x0061f54c/0x0061f57c`, text-input slots at `0x0061ee0c/0x0061ee6c/0x0061ee9c`, text-menu slots at `0x0061ecac/0x0061ed0c/0x0061ed3c`, and `TextMenuItemList` slots at `0x0061ed48/0x0061edd0/0x0061ee00`.

Current byte checks:

- `get_bytes 0x00520b55 size 22` returned:
  - `81 e9 a0 00 00 00 e9 90 02 00 00`
  - `81 e9 a4 00 00 00 e9 85 02 00 00`
  - This directly proves the `TextMenuItemList` pair is `sub ecx,0xa0; jmp 0x00520df0` and `sub ecx,0xa4; jmp 0x00520df0`.
- `get_bytes 0x00520e2a size 8` returned `00 cc cc cc cc cc 55 8b`, proving the final byte at `0x00520e2a` is the `retn 4` operand byte, followed by padding and then the `0x00520e30` successor prologue.
- Earlier same-session bytes confirmed analogous `0xa0`/`0xa4` thunk pairs at `0x00520abb`, `0x00520b29`, and `0x00520b3f`, and `0xcc` padding before `0x00520c20` and `0x00520d50`.

Current decompile check:

`decompile 0x00520df0` returned the `TextMenuItemList` scalar wrapper shape:

```c
_DWORD *__thiscall sub_520DF0(_DWORD *Block, char a2)
{
  sub_4F3B60(Block);
  if ( (a2 & 1) == 0 || (a2 & 4) != 0 )
    return Block;
  sub_4F4AC0(Block);
  return Block;
}
```

This is compiler scalar-delete glue around list-pane/base cleanup, not a source-authored method body. The current decompile exposes calls to `0x004f3b60` and `0x004f4ac0`; same-session prior analysis recorded the same wrapper as size `0x3b`.

Decimal conversions verified with `tools/int_convert.py`:

- `0xa0` = `160`
- `0xa4` = `164`
- `0x158` = `344`
- `0x15c` = `348`
- `0x284` = `644`
- `0x28c` = `652`

## Positive Evidence

- The current IDA model exactly matches the page's compiler-glue structure: many `0x0b` adjusted-this thunks, several scalar deleting destructor wrappers, no single large function object covering the nominal range, and a non-function exclusive end at `0x00520e2b`.
- The `TextMenuItemList` byte gap from B010 is now resolved with current MCP bytes. The pair at `0x00520b55` and `0x00520b60` directly encodes `this - 0xa0` and `this - 0xa4` before tail-jumping to the primary scalar wrapper.
- The scalar wrapper at `0x00520df0` has exactly the generated wrapper behavior expected for a compiler deleting destructor: base/list cleanup call, delete-flag test, optional delete helper, and return of `this`.
- Xrefs show vtable-data and thunk-jump reachability, not ordinary source calls. This supports generated ABI dispatch rather than source-authored public/private methods.
- Existing support pages [UID:00037A] through [UID:00037G], [UID:0001BY], [UID:0001C0]/[UID:0001C1], [UID:0003M9]/[UID:0003MA], [UID:0001BZ]/[UID:0001C2], `TextMenuDialogs`, `TextMenuItemList`, and `TextMenuDialogVtables` already carry most owner-specific routing.

## Negative Evidence

- No evidence supports assigning the aggregate [UID:0001BX] to one canonical owner. It physically includes argumented-menu, text-menu, shared client/spell, server-item, object-image, shared dialog default, and shared list-pane glue.
- No evidence supports setting `RECONSTRUCTABLE:TRUE`. By-structure code-entry rules require reconstructable source with a valid emitter route; this target is neither.
- No evidence supports formal C++ on this target. A source block here would either duplicate exact child pages, invent source methods for compiler thunks/scalar wrappers, or merge unrelated source-family cleanup routes.
- No evidence supports a split change to make this aggregate source-emitting. Exact child pages already exist for the owner-specific function starts; the aggregate is useful as an index/ledger, not as a source range.
- The generated tracker's `80/86 reconstructable true` row is stale relative to the source page and current MCP, not a reason to downgrade or add C++.

## Heuristic And Source-Quality Reanalysis

Compiler-generated classification is stronger than source-owner classification here.

Adjusted destructor thunks:

- Pattern: `sub ecx, 0xa0` or `sub ecx, 0xa4`, then `jmp` to the primary scalar deleting destructor.
- Length: `0x0b` bytes.
- Reachability: secondary/tertiary vtable slots and no ordinary direct callers.
- Source policy: regenerate from class layout and virtual destructor declarations; do not hand-port as named source functions.

Scalar deleting destructor wrappers:

- Pattern: vtable/base cleanup or member cleanup, delete-flag test, optional delete helper, return `this`.
- Reachability: primary vtable slot and adjusted-thunk jumps.
- Source policy: document as ABI glue. Source pages should carry ordinary destructor declarations/definitions only where source-authored behavior exists.

Mixed aggregate:

- The target's nominal span contains several unrelated glue families. It is not a coherent source function, class, vtable table, raw helper, or source file.
- The correct documentation role is an index over exact child pages and neighboring glue, with explicit no-code rationale.

## Ranked Source Disposition

1. Keep UID0001BX as `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
   - This matches current MCP and by-structure rules.
2. Preserve exact child pages as owner-specific compiler-glue evidence.
   - The child docs are the right places for per-class vtable route and source-owner context.
3. Update stale target prose and support docs with the current MCP byte/decompile proof.
   - This removes the old below-85 and below-95 threshold language and resolves B010's old live-byte limitation.
4. Reject assigning the aggregate to `TextMenuDialogs`, `ArgumentedMenuDialogs`, `ObjectImageButtonPane`, `ItemMenuDialogs`, or shared list/dialog pages.
   - Each is only a partial semantic context for a subset of the island.
5. Reject first-draft C++ or marker C++ for the target.
   - Blank code is the exact disposition under current project rules.

## Score And Metadata Disposition

Recommended target update:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- blank `EMITTER_UIDS`
- blank formal C++

Reasoning:

- Completion increases because the current pass checked exact function starts, endpoint, child routes, xrefs, bytes, decompile, support docs, generated-tracker staleness, and first-draft C++ disposition.
- Confidence increases because current MCP directly proves the `TextMenuItemList` `0xa0`/`0xa4` bytes and scalar wrapper route that B010 previously treated as a live-byte limitation.
- The score should not exceed the low 90s until the accepted implementation updates the stale target prose and [UID:00037H] blank summary, and until generated reports are refreshed through normal validator/supervisor flow.

Recommended support metadata:

- [UID:00037G] `by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md`: keep `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++; add current MCP byte proof and historicalize the old "MCP unavailable" caveat.
- [UID:00037H] `by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md`: raise from `84/90` to `86/91`, keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++; fill the blank `Item Summary` and add current MCP decompile/endpoint proof.
- `by-file/TextMenuDialogs.md`, `by-class/TextMenuItemList.md`, and `by-type/by-vtable/TextMenuDialogVtables.md`: already contain the correct ordinary-destructor-only and compiler-generated support policy. No required edit, unless the implementer wants to add a concise current-MCP sync note.

## First-Draft C++ / Exact No-Code Disposition

No C++ insertion text is recommended.

The target formal `RECONSTRUCTION_CPP CODE` block must remain empty:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason:

- The target is `RECONSTRUCTABLE:FALSE`.
- `EMITTER_UIDS` is blank by design.
- Every byte range checked in this aggregate is compiler-generated destructor/thunk/scalar-wrapper glue or neighboring glue already documented by exact child pages.
- Source reconstruction belongs to ordinary class/file pages, especially `TextMenuDialogs`, `ArgumentedMenuDialogs`, item menu dialogs, object-image pages, and shared list/dialog support, not to this mixed by-memory aggregate.

## Support-Doc Edit List For Implementation Callback

Edit only after supervisor acceptance and a callback. Lease only files immediately before editing, and release leases immediately after edit/validator batch.

1. Target `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md`
   - Change metadata to `COMPLETION:90`, `CONFIDENCE:92`.
   - Replace stale `Item Summary` below-85 wording with current no-code mixed compiler-glue summary.
   - Replace "Current Wave3 owners" with current source-context wording.
   - Add current MCP evidence: session `992d23de`, health OK, function inventory, `TextMenuItemList` byte proof, scalar wrapper decompile, endpoint proof, and generated tracker stale note.
   - Replace old "below 95% final reconstruction threshold" sentence with current by-structure no-code rationale.
   - Add a 2026-06-29 B002 change entry.

2. Support `by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md`
   - Keep current metadata.
   - Add current MCP byte proof for the exact two-thunk sequence:
     - `0x00520b55`: `sub ecx,0xa0; jmp 0x00520df0`
     - `0x00520b60`: `sub ecx,0xa4; jmp 0x00520df0`
   - Historicalize or replace B010's limitation that live-byte confirmation was unavailable.
   - Add a 2026-06-29 B002 change entry.

3. Support `by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md`
   - Change metadata to `COMPLETION:86`, `CONFIDENCE:91`.
   - Fill blank `Item Summary` with the current no-code scalar-wrapper disposition.
   - Add current MCP decompile evidence and endpoint proof.
   - Preserve `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++.
   - Add a 2026-06-29 B002 change entry.

4. Already-present support docs, no required edit:
   - `by-file/TextMenuDialogs.md`
   - `by-class/TextMenuItemList.md`
   - `by-type/by-vtable/TextMenuDialogVtables.md`
   - exact child docs [UID:00037A] through [UID:00037F], [UID:0001BY], [UID:0001C0], [UID:0001C1], [UID:0003M9], [UID:0003MA], [UID:0001BZ], and [UID:0001C2], except where the supervisor wants a broader consistency refresh.

5. Do not manually edit:
   - `auto-generated/-ag-research-tracker.md`
   - `auto-generated/-ag-coverage-report-by-memory.md`
   - manual `-coverage-report.md` files
   - generated C++ files
   - validator/tool state
   - executed research archives
   - IDA DB

## Validators For Implementation Callback

After accepted implementation, run scoped validators from `source-3/project-documentation` with `--queue-timeout 240`:

> Executable block R001 was removed from this report and preserved verbatim in [0001BX-MenuDialogDestructorThunks-source-quality-removed.md](0001BX-MenuDialogDestructorThunks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during the report-only pass, and no leases were taken at report time.

Implementation callback validator results:

| File | Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md` | `python .\tools\validator.py --mode file --file by-memory\0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md --apply --queue-timeout 240` | `000000000389` | `2026-06-29T03:01:26-04:00` | `0` | `1` | Applied `completion_update 90`, `confidence_update 92`, `canonical_owner_update NONE`, registry reconstructable `true -> false`; existing missing-ref diagnostics remain; `generated_refresh: deferred`. |
| `by-memory\0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md` | `python .\tools\validator.py --mode file --file by-memory\0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md --apply --queue-timeout 240` | `000000000390` | `2026-06-29T03:01:38-04:00` | `0` | `1` | Applied `completion_update 88`, `confidence_update 92`, `canonical_owner_update NONE`; existing missing-ref UID diagnostics for `00037H` remain; `generated_refresh: deferred`. |
| `by-memory\0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory\0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000000391` | `2026-06-29T03:01:43-04:00` | `0` | `1` | Applied `completion_update 86`, `confidence_update 91`, `canonical_owner_update NONE`; `generated_refresh: deferred`. |

Validator side effects were tool-owned: each scoped run reported `projected_stats_update` for `project-level/-auto-completion-stats.md` and deferred generated refresh metadata. No generated reports, generated C++ files, manual coverage reports, validator/tool state, executed archives, or IDA DB were manually edited by B002.

## Claim And Incorporation Ledger

| Claim / fact to preserve or apply | Action | Target/support doc destination | Verification state | Notes |
| --- | --- | --- | --- | --- |
| UID0001BX is a mixed compiler-generated destructor/thunk/scalar-wrapper island, not one source-authored function. | incorporate | UID0001BX summary/status/ownership decision | applied | Target `Item Summary`, `Status`, `Ownership Decision`, `Score Rationale`, and `Changes` now state this mixed no-code ledger disposition. |
| UID0001BX should remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++. | incorporate | UID0001BX metadata and C++ block | applied | Target metadata preserves `NONE`/`FALSE`/blank emitters/C++; validator `000000000389` confirmed canonical owner `NONE` and registry reconstructable `false`. |
| UID0001BX metadata should rise from `87/90` to `90/92`. | incorporate | UID0001BX header | applied | Target header now `COMPLETION:90`, `CONFIDENCE:92`; validator `000000000389` applied both values with `ok: 1`. |
| The current target `Item Summary` below-85 wording is stale. | historicalize | UID0001BX item summary / change history | applied | Stale below-85 wording replaced by current MCP/no-code summary; 2026-06-29 change entry records the correction. |
| The current "below 95% final reconstruction threshold" C++ rationale is stale. | historicalize | UID0001BX ownership/source-policy prose | applied | Ownership Decision now cites current by-structure reconstructable/emitter/generated-glue no-code rule instead of old threshold. |
| Exact function inventory from `0x00520abb` through `0x00520df0` confirms many child functions, not one aggregate function. | incorporate | UID0001BX IDA MCP Evidence | applied | Target 2026-06-29 evidence block records session `992d23de` and the thunk/scalar-wrapper function inventory. |
| `0x00520e2b` is not a function and `0x00520e30` starts the successor family. | incorporate | UID0001BX endpoint evidence and UID00037H support | applied | UID0001BX and UID00037H record lookup/byte endpoint proof `00 cc cc cc cc cc 55 8b`. |
| `TextMenuItemList` thunks at `0x00520b55`/`0x00520b60` encode `this - 0xa0` / `this - 0xa4` and jump to `0x00520df0`. | incorporate | UID0001BX and UID00037G | applied | UID0001BX and UID00037G now record current MCP bytes `81 e9 a0...` / `81 e9 a4...` and the jump route to `0x00520df0`. |
| `0x00520df0` is a compiler scalar deleting destructor wrapper calling `0x004f3b60` and optionally `0x004f4ac0`. | incorporate | UID0001BX and UID00037H | applied | UID0001BX and UID00037H record current MCP decompile shape through `sub_4F3B60` and `sub_4F4AC0`. |
| `xrefs_to 0x00520df0` are from the two thunks plus primary vtable data, not ordinary callers. | incorporate | UID0001BX, UID00037G, UID00037H | applied | All three changed docs record thunk code refs and primary vtable data ref `0x0061ed48`; UID00037G also records `0x0061edd0`/`0x0061ee00`. |
| UID00037G should keep existing metadata but replace/historicalize old "MCP unavailable" limitation. | incorporate | UID00037G Evidence/Changes | applied | UID00037G remains `88/92`, `NONE`, `FALSE`, blank emitter/C++; evidence now says current MCP resolved B010's live-byte limitation. Validator `000000000390` confirmed metadata. |
| UID00037H blank `Item Summary` should be filled and score raised to `86/91`. | incorporate | UID00037H header/summary/evidence | applied | UID00037H header now `86/91`, summary filled, evidence expanded; validator `000000000391` applied metadata with `ok: 1`. |
| `TextMenuDialogs`, `TextMenuItemList`, and `TextMenuDialogVtables` already carry ordinary-destructor-only policy. | already-present | Those support docs | already-present | Verified by `rg` before edits: the file/class/vtable docs already state ordinary destructor/class layout owns source shape and thunks/scalar wrapper are compiler output. No edit required by callback. |
| Generated tracker/coverage rows are stale and should not be manually edited. | incorporate | UID0001BX implementation note / report only | applied | UID0001BX current MCP evidence block records stale generated tracker/coverage state and says generated files are validator/supervisor-owned refresh outputs. Validators reported `generated_refresh: deferred`; no manual generated edits. |
| Formal C++ insertion text is not needed and must remain blank. | not-applicable | UID0001BX formal C++ block | excluded-with-reason | Excluded because UID0001BX is `RECONSTRUCTABLE:FALSE`, has blank emitters, and represents compiler-generated mixed glue. Formal block remains empty. |
| IDA rename/type/comment changes are not required for this documentation callback. | not-applicable | IDA DB | excluded-with-reason | Excluded because callback was documentation-only; no IDA DB edits were made. |

## Implementation Tracking Checklist

- [x] Lease only `by-memory/0x00520abb-0x00520e2b.MenuDialogDestructorThunks.md` immediately before editing it, if supervisor accepts implementation. Proof: `python leaser.py B002 lease ...MenuDialogDestructorThunks.md ...TextMenuItemListDestructorThunks.md ...TextMenuItemListScalarDeletingDestructor.md` returned `Success` for all three accepted by-memory docs.
- [x] Update UID0001BX metadata to `90/92`, owner/emitter/reconstructable unchanged, and leave the formal C++ block empty. Proof: target header now `90/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++; validator `000000000389` applied completion/confidence and owner.
- [x] Replace UID0001BX stale `Item Summary` below-85 wording with current mixed compiler-glue no-code summary. Proof: target `Item Summary` now describes mixed compiler-generated ledger, session `992d23de`, and blank emitter/C++ disposition.
- [x] Replace UID0001BX stale "Current Wave3 owners" and "below 95% final reconstruction threshold" prose with current source-context and by-structure no-code rationale. Proof: target `Status` uses "Current source-context families"; `Ownership Decision` cites current reconstructable/emitter/generated-glue rule.
- [x] Add UID0001BX current MCP evidence: session `992d23de`, server health, function starts/sizes, endpoint, TextMenuItemList bytes, scalar wrapper decompile, xrefs, and generated-tracker stale note. Proof: target `IDA MCP Evidence` has 2026-06-29 B002 block with all listed facts.
- [x] Add a UID0001BX 2026-06-29 B002 change entry. Proof: target `Changes` starts with `2026-06-29 B002 accepted source-quality implementation`.
- [x] Lease only `by-memory/0x00520b55-0x00520b6a.TextMenuItemListDestructorThunks.md` immediately before editing it, if supervisor accepts implementation. Proof: same B002 lease command returned `Success` for UID00037G.
- [x] Add current MCP byte proof to UID00037G and historicalize the old "MCP unavailable" limitation. Proof: UID00037G `Evidence` now says B002 session `992d23de` resolved the B010 live-byte limitation with exact bytes and xrefs.
- [x] Add a UID00037G 2026-06-29 B002 change entry. Proof: UID00037G `Changes` includes the B002 accepted implementation entry.
- [x] Lease only `by-memory/0x00520df0-0x00520e2b.TextMenuItemListScalarDeletingDestructor.md` immediately before editing it, if supervisor accepts implementation. Proof: same B002 lease command returned `Success` for UID00037H.
- [x] Update UID00037H metadata to `86/91`, owner/emitter/reconstructable unchanged, formal C++ blank. Proof: UID00037H header now `86/91`, `NONE`, `FALSE`, blank emitter/C++; validator `000000000391` applied completion/confidence and owner.
- [x] Fill UID00037H blank `Item Summary` with current scalar-wrapper no-code disposition. Proof: UID00037H summary now documents compiler-generated scalar wrapper, vtable-only reachability, decompile shape, endpoint, and blank emitter/C++.
- [x] Add UID00037H current MCP decompile, xref, and endpoint proof. Proof: UID00037H `Evidence` has B002 session `992d23de` paragraph with lookup, xrefs, decompile, and bytes.
- [x] Add a UID00037H 2026-06-29 B002 change entry. Proof: UID00037H `Changes` includes the B002 accepted implementation entry.
- [x] Verify `TextMenuDialogs`, `TextMenuItemList`, and `TextMenuDialogVtables` are still already-present for ordinary-destructor-only policy; edit only if supervisor callback requests it. Proof: pre-edit `rg` found already-present source policy in all three support docs; no edit required by callback.
- [x] Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, executed archives, lock files, or IDA DB. Proof: B002 manually edited only the three accepted by-memory docs and this report; validator reported tool-owned `projected_stats_update` and deferred generated refresh, but no generated/report/tool-state files were manually patched.
- [x] Run scoped validators from `source-3/project-documentation` with `--queue-timeout 240` for UID0001BX, UID00037G, and UID00037H after accepted edits. Proof: validators `000000000389`, `000000000390`, and `000000000391` all exited `0` with `ok: 1`.
- [x] Check validator output/generation refresh for stale UID0001BX tracker/coverage data without manually editing generated files. Proof: all validators reported `generated_refresh: deferred`; UID0001BX source page documents stale generated tracker/coverage state, and no generated files were manually edited.
- [x] Release all leases immediately after the edit/validator batch. Proof: `python leaser.py B002 unlease` returned `Success` for all three leased by-memory files; current lease report shows no B002 active leases.
- [x] Update this report's ledger verification states during implementation callback: `applied`, `already-present`, `excluded-with-reason`, or `blocked`. Proof: ledger above updated all rows; no row remains `proposed` or `blocked`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0001BX-MenuDialogDestructorThunks-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0001BX-MenuDialogDestructorThunks-source-quality.md","timestamp":"2026-06-29T03:13:03","uid":"0001BX"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001BX-MenuDialogDestructorThunks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0001BX-MenuDialogDestructorThunks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001BX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
