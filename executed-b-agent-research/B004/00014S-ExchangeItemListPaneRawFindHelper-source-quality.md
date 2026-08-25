** TARGET-REPORT-UID:00014S **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:00014S] ExchangeItemListPaneRawFindHelper

## Assignment

- Agent: B004
- Assignment id: `B004-report-00014S-ExchangeItemListPaneRawFindHelper-source-quality-20260627`
- Target: [UID:00014S][by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md](../../../../../by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md)
- Required disposition for this turn: report only. I made no by-* edits, no generated edits, no coverage-report edits, no validator/tool-state edits, and no IDA DB writes.
- Current-pass update: this report was refreshed after the MCP restart and is backed by live IDA MCP session `398b87c1`; old session `80de0a67` is intentionally superseded. No subagents or leases were used.

## Recommendation

Implement after supervisor validation.

- Target score recommendation: raise to `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00004S`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00004S`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Do not emit a standalone `ExchangeItemListPane::FindOfferItemRowByKey` method body. The retained raw helper has exact semantics but no current source route or callsite.
- Replace the blank formal C++ block with a formal comment-only covered-by marker. This resolves the not-covered/empty-marker state without inventing a separate callable helper.

Recommended formal insertion for the target page's `RECONSTRUCTION_CPP CODE` block:

```cpp
// Emitted code for this retained raw no-route helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.
```

Recommended target source-disposition marker for implementation:

```text
Source disposition: exact retained raw ExchangeItemListPane key-scan helper; no standalone source emission is currently defensible because live IDA MCP confirms no function object, no inbound xrefs, no pointer/immediate route, and equivalent live row-key scan behavior is already emitted through [UID:00014L] ExchangeDialog packet dispatcher case 2.
```

## Current Target State

The target page currently has `COMPLETION:86`, `CONFIDENCE:89`, owner/emitter [UID:00004S][ExchangeItemListPane](../../../../../by-class/ExchangeItemListPane.md), `RECONSTRUCTABLE:TRUE`, and a blank formal C++ block. Its current prose already documents the key facts: raw start `0x004ae170`, exclusive end `0x004ae1ac`, padding to successor `0x004ae1b0`, row-key scan semantics, best source-facing name `ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const`, and no route proving a separately emitted helper.

The not-covered state is now primarily a formal-code/support-sync problem:

- `auto-generated/-ag-research-tracker.md` still carries stale generated state for this UID with `80/86` and no resolved emitted-code marker.
- `auto-generated/-ag-coverage-report-by-memory.md` still treats the page as `emits_code:false`, stale `80% : strong`.
- Generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` has an empty `UID00014S` marker and stale `Completion:80 Confidence:86`, even though the by-* target page is already `86/89`.
- Manual `by-memory/-coverage-report.md` is also stale, but B-agents must not hand edit coverage-report files.

## Live IDA MCP Session

MCP was available and current. I did not use a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- JSON-RPC flow used: `initialize`, `tools/list`, then `tools/call` with explicit `database` argument per the current schema.
- Session id: `398b87c1`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, `strings_cache_size:2067`
- `idb_list` status: one active adopted worker session, backend `worker`, PID/worker PID `2704`, `is_analyzing:false`, created `2026-06-27T12:27:25.386816`.
- No MCP availability failure occurred during the current refresh. I did not rely on any timed-out broad scan from the superseded `80de0a67` draft; the route conclusion below uses current-session `xrefs_to`, full-database byte-pattern scans, focused immediate scans around the owning cluster, and positive-control successor routes.

## Actual Evidence Checked

### Boundary And Raw Body Evidence

Live MCP `lookup_funcs` confirms the target body is still not an IDA-modeled function:

- `0x004ae160`: not a function.
- `0x004ae167`: not a function.
- `0x004ae170`: not a function.
- `0x004ae1a9`: not a function.
- `0x004ae1ac`: not a function.
- `0x004ae1b0`: `nullsub_29`, size `0x3`.
- `0x004ae1c0`: `sub_4AE1C0`, size `0x2f6`.
- `0x004ae4c0`: `sub_4AE4C0`, size `0x435`.

Live MCP `entity_query kind=functions min=0x004ae160 max=0x004ae1d0` returns only `nullsub_29` at `0x004ae1b0` and `sub_4AE1C0` at `0x004ae1c0`. It does not return a function object for `0x004ae170`.

Live MCP `get_bytes 0x004ae160 size 96` confirms the raw split:

- `0x004ae160`: predecessor tail `e8 fb 5b 04 00 eb 96`.
- `0x004ae167-0x004ae170`: nine `0xcc` padding bytes.
- `0x004ae170-0x004ae1ac`: exact 60-byte raw helper body (`0x3c` / 60, Verified with `int_convert.py`).
- `0x004ae1ac-0x004ae1b0`: four `0xcc` padding bytes.
- `0x004ae1b0`: successor null virtual starts with `c2 08 00`; `0x8` is 8, Verified with `int_convert.py`.

Live MCP `make_signature_for_range 0x004ae170-0x004ae1ac wildcard_operands=false` returned a unique signature for the 60-byte body:

```text
55 8B EC 53 56 57 8B D9 E8 53 5A 04 00 8B F8 33 F6 85 FF 7E 14 56 8B CB E8 33 5C 04 00 8A 4D 08 38 08 74 0F 46 3B F7 7C EC 5F 5E 83 C8 FF 5B 5D C2 04 00 5F 8B C6 5E 5B 5D C2 04 00
```

Live MCP `insn_query 0x004ae160-0x004ae1c0 include_disasm/include_fn` returns the exact key-scan shape:

- `0x004ae170`: prologue; all raw-helper instructions have `fn: null`.
- `0x004ae176`: moves `this` from `ecx` to `ebx`.
- `0x004ae178`: calls `sub_4F3BD0`, the list row count helper.
- `0x004ae17f`: initializes `esi = 0`.
- `0x004ae181-0x004ae183`: exits not-found path when count is `<= 0`.
- `0x004ae185-0x004ae188`: loop pushes `esi`, restores `this`, and calls `sub_4F3DC0`, the row accessor.
- `0x004ae18d-0x004ae190`: loads stack argument `[ebp+8]` into `cl` and compares it with byte `[eax]`, the row key at offset `+0`.
- `0x004ae194-0x004ae197`: increments row index and loops while `esi < count`.
- `0x004ae199-0x004ae1a0`: not-found return path sets `eax = -1` and `retn 4`.
- `0x004ae1a3-0x004ae1a9`: found return path returns `esi` and `retn 4`.
- `0x004ae1ac`: alignment to the positive-control successor `nullsub_29`.

The source-facing signature `int ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const` remains the best description of this ABI: `this` in `ecx`, one stack byte key argument, signed row-index return with `-1` on miss, and no mutation.

### Route And Xref Evidence

Live MCP `xrefs_to` confirms the target is not currently routed:

- `xrefs_to 0x004ae170`: zero xrefs.
- `xrefs_to 0x004ae1ac`: zero xrefs.
- `trace_data_flow 0x004ae170 backward max_depth 3`: only the start instruction node, no incoming edges.

The same checks produce positive-control successor routes:

- `xrefs_to 0x004ae1b0`: data xref at `0x00619e40`.
- `xrefs_to 0x004ae1c0`: data xref at `0x00619e48`.
- `find_bytes B0 E1 4A 00`: match at `0x00619e40`.
- `find_bytes C0 E1 4A 00`: match at `0x00619e48`.

Pointer-pattern searches for the raw helper remain negative:

- `find_bytes 70 E1 4A 00`: zero matches for raw start VA `0x004ae170`.
- `find_bytes 70 E1 0A 00`: zero matches for raw start RVA.
- `find_bytes 70 D5 0A 00`: zero matches for raw start file offset.
- `find_bytes AC E1 4A 00`: zero matches for raw end VA `0x004ae1ac`.
- `find_bytes AC E1 0A 00`: zero matches for raw end RVA.
- `find_bytes AC D5 0A 00`: zero matches for raw end file offset.

Focused route scans around the ExchangeDialog cluster were also negative:

- `search_text 0x004ac000-0x004af000 pattern 4AE170`: only the label line for the raw start itself.
- `search_text 0x004ac000-0x004af000 pattern 4AE1AC`: only the alignment label line itself.
- `insn_query 0x004ac000-0x004af000 op_any=4907376`: no immediate operand reference to `0x004ae170`.
- `insn_query 0x004ac000-0x004af000 op_any=4907436`: no immediate operand reference to `0x004ae1ac`.

I did not claim a current exhaustive whole-`.text` instruction-immediate scan. The current-session negative route proof rests on exact `xrefs_to` results, full-database VA/RVA/file-offset byte-pattern searches, focused `0x004ac000-0x004af000` immediate scans that completed over 3668 instructions, and positive-control vtable hits for the successor virtuals.

### Row Layout And Equivalent Live Source Path

Live MCP `analyze_function 0x004ae1c0` confirms successor draw code interprets each row as the same fixed layout documented on the class page:

- Key byte at row offset `+0`.
- Item id word at row offset `+2`.
- Color/style byte at row offset `+4` (`0x4` / 4, Verified with `int_convert.py`).
- Wide name buffer at row offset `+6`.
- Row size `0x206` / 518 (Verified with `int_convert.py`) from support documentation and sibling helper evidence.

Live MCP `analyze_function 0x004ad320` confirms the routed packet dispatcher has the live equivalent source behavior in opcode `0x42` subcommand `2`:

- Reads side/list selector from packet offset `+2`.
- Reads row key byte from packet offset `+3`.
- Reads item id from packet offset `+4`.
- Reads color from packet offset `+6`.
- Converts packet name bytes at packet offset `+8` into the row wide-name buffer.
- Chooses control/list id `8` for one side and `5` for the other.
- Gets row storage through the `ExchangeItemListPane` control.
- Calls `sub_4F3BD0` to get row count.
- Loops over rows, calls `sub_4F3DC0`, compares the row key byte, removes an existing matching row with `sub_4F3D60`, then inserts the replacement row with `sub_4F3C00`.

This proves the source-visible ExchangeDialog path already contains the row-key scan/update logic. It does not prove a call to the retained raw helper at `0x004ae170`.

### Support Pages Checked

I checked the required support pages:

- [by-class/ExchangeItemListPane.md](../../../../../by-class/ExchangeItemListPane.md): documents class score `87/89`, owner/emitter `0000J9`, row layout, constructor exception, and the current blank/no-route disposition for `00014R` and `00014S`.
- [by-file/ExchangeDialog.md](../../../../../by-file/ExchangeDialog.md): routes this class to `NexusTK/ui/dialogs/ExchangeDialog.cpp`, validates the `FindOfferItemRowByKey(unsigned char key) const` name/signature as class-local, and keeps raw helpers blank due no route.
- [by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md](../../../../../by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md): sibling raw helper with the same no-route retained-helper issue and blank formal C++ block.
- [by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md](../../../../../by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md): aggregate ExchangeDialog cluster context.
- [by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md](../../../../../by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md): emitted dispatcher source; case 2 is the exact routed live path that covers the row-key scan behavior.
- [by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md](../../../../../by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md): constructor exception; it emits C++ because constructor source shape and class declaration placement are solved, unlike `00014S`.
- [by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md](../../../../../by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md): positive-control vtable entries route `0x004ae1b0` and `0x004ae1c0`, not the raw helper.

I also checked generated `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`. It currently emits `UID00014L` dispatcher code and a comment-only covered-by marker for `UID00014N`, but `UID00014S` is still an empty generated marker with stale `80/86` metadata.

## Positive Evidence

- The raw helper body is exact, byte-bounded, unique-signature-backed, and instruction-complete.
- The helper's behavior is deterministic: scan rows by key byte and return the matching row index or `-1`.
- The ABI shape supports the source-facing signature `int ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const`.
- The owner is class-local: the helper only uses the list-pane row count/access helpers on `this`.
- The row layout is independently confirmed by draw code and packet-dispatcher row construction.
- The live dispatcher case 2 has equivalent row-key scan/update behavior in the routed source path.
- The successor virtuals at `0x004ae1b0` and `0x004ae1c0` provide positive controls showing MCP can find actual vtable routes in this region.
- The generated pipeline already accepts comment-only covered-by markers in this file family, demonstrated by `UID00014N`.

## Negative Evidence And Confidence Caps

- IDA still has no function object at `0x004ae170`.
- `xrefs_to 0x004ae170` and `xrefs_to 0x004ae1ac` are empty.
- VA/RVA/file-offset pointer-pattern searches for the raw helper start/end are empty.
- Focused instruction/immediate scans around the owning cluster do not find a branch/call/immediate route to the helper.
- No current support page proves a source callsite to `FindOfferItemRowByKey`; the live dispatcher implements the scan inline.
- The exact original source name is not recovered from symbols. The proposed name is source-facing reconstruction, not a demangled symbol.
- No claim depends on an exhaustive broad whole-`.text` immediate search. Current exact xrefs, full byte-pattern searches, focused immediate scans, and positive-control successor hits are sufficient to reject a current standalone source route to `0x004ae170`.

These negatives block a standalone first-draft C++ body. They do not justify leaving the formal C++ block blank because the routed dispatcher already covers the behavior and the generated output needs an explicit target-specific disposition.

## Heuristic Reanalysis

The old "blank because no xrefs" state is too weak for the current queue problem. The correct repair is not to turn this helper into an emitted method; it is to record an explicit no-standalone-emission disposition in the formal C++ block.

The constructor sibling [UID:00014Q] is not a precedent for emitting this helper. A constructor has class placement, object initialization, and source declaration semantics that can be reconstructed even with no raw-start route. This target is different: it is a retained private-ish helper whose source use is not proven, and the live source path in dispatcher case 2 performs the key scan inline.

The sibling upsert helper [UID:00014R] supports the same policy bucket: exact raw helper semantics, class-local owner, reconstructable true, but no separate source route. For `00014S`, the source-quality improvement is stronger than "remain blank" because a comment-only covered-by marker can map this exact raw helper to the emitted dispatcher behavior without inventing unreachable source.

## Ranked Source, Owner, Emitter, And C++ Disposition

1. **Keep direct owner/emitter [UID:00004S] `ExchangeItemListPane`.** The helper operates on item-list pane row storage and has a class-local signature.
2. **Represent emitted behavior through [UID:00014L] dispatcher case 2.** That is the routed source path that performs the row-key scan/update logic in generated `ExchangeDialog.cpp`.
3. **Insert a formal comment-only covered-by marker for [UID:00014S].** This should turn the current empty generated marker into an explicit non-standalone source disposition.
4. **Do not emit a standalone method body.** A source method body would imply a call/declaration route that MCP does not show.
5. **Do not change owner to [UID:0000J9] `ExchangeDialog` directly.** `ExchangeDialog` owns the routed dispatcher and source file route, but the helper itself is class-local to `ExchangeItemListPane`.

## Score And Metadata Recommendation

Recommended target metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00004S
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00004S
EMITTER_POSITION_OPTIONAL:
```

Rationale for `88/91`:

- Raise completion because this pass confirms the exact raw range, body, return semantics, route negatives, successor positive controls, live equivalent dispatcher path, and generated coverage failure mode.
- Raise confidence because MCP evidence now directly distinguishes no-route raw helper from routed successor virtuals and routed dispatcher behavior.
- Do not raise into final/high-90s because the original source name/callsite remains unproven and no standalone method emission is justified.

## Formal C++ Recommendation

The implementation should replace the target's blank formal block exactly as follows:

```text
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted code for this retained raw no-route helper is covered by [UID:00014L] by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is C++ only in the sense that it is a valid C++ comment for the generated source file. It is intentionally not a body for `ExchangeItemListPane::FindOfferItemRowByKey`.

Rejected first-draft body:

```cpp
int ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const
{
    const int rowCount = GetItemCount();
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        const ExchangeItemListRow *row = GetItem(rowIndex);
        if (row->key == key) {
            return rowIndex;
        }
    }

    return -1;
}
```

This body matches raw semantics, but it should stay out of the formal C++ block because the current binary/source evidence does not prove a retained source method with this call route. Keeping it as a rejected semantic sketch prevents future reviewers from redoing the same analysis.

## Rejected Alternatives

- `FindOfferItem`: rejected because the helper returns a row index, not an item object.
- `FindItem`: rejected as too broad; the compare key is the offer-row key byte at row offset `+0`, not item id.
- `FindSlot`: rejected because no slot abstraction is involved; the helper iterates list rows.
- `FindOfferItemRow`: rejected as incomplete because the key argument is the behavioral discriminator.
- `ExchangeDialog::FindOfferItemRowByKey`: rejected because the raw helper receives an `ExchangeItemListPane *this`, not an `ExchangeDialog *this`.
- Standalone first-draft method body: rejected because no xref, vtable slot, pointer, focused immediate, or dispatcher call route reaches `0x004ae170`.
- Blank formal C++ block: rejected because it leaves generated output in an empty not-covered state even though the exact target-specific no-standalone-emission disposition is now known.
- Metadata-only change: rejected because stale generated C++ would still contain no explicit target-specific covered-by marker.
- Owner change to `0000J9`: rejected because file/source routing goes through ExchangeDialog, but the helper's object owner is still `ExchangeItemListPane`.

## Generated And Coverage Repair Plan

Generated and coverage outputs should be refreshed by validators/generator after by-* implementation, not hand edited.

Expected generated result after implementation:

- `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` should contain a non-empty `UID00014S` comment-only marker.
- Generated target metadata should refresh from stale `80/86` toward the implemented by-* values `88/91`.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` should stop treating `00014S` as an empty not-covered reconstructable target if the generator recognizes comment-only markers the same way it already recognizes `UID00014N`.

Manual `by-memory/-coverage-report.md` is out of scope for B004 edits. If the supervisor owns a manual coverage sync, the recommended replacement row is:

```markdown
    - [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) 0x004ae170-0x004ae1ac | raw helper | ExchangeItemListPaneRawFindHelper : reconstructable : 88% : very strong : B004 2026-06-27 source-quality reanalysis confirms exact 0x3c/60-byte retained ExchangeItemListPane row-key scan helper, best source-facing signature int ExchangeItemListPane::FindOfferItemRowByKey(unsigned char key) const, row key compare at offset +0, -1 miss return, positive-control vtable routes for 0x004ae1b0 and 0x004ae1c0, no IDA function object, no inbound xrefs, no VA/RVA/file-offset pointer route, equivalent live row-key scan/update behavior covered by UID00014L dispatcher case 2, and formal comment-only covered-by marker instead of standalone no-route method emission.
```

## Implementation Callback Checklist

B004 implementation callback proof, completed 2026-06-27:

- [x] Acquired required leases before touching by-* pages.
  - Proof: `python .\tools\leaser\leaser.py B004 lease by-memory\0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md by-class\ExchangeItemListPane.md by-file\ExchangeDialog.md by-memory\0x004ac8a0-0x004ae4b6.ExchangeDialog.md by-memory\0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md` succeeded for the five edited by-* pages.
- [x] Edited [by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md](../../../../../by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md).
  - [x] Changed `COMPLETION` to `88`.
  - [x] Changed `CONFIDENCE` to `91`.
  - [x] Kept owner/emitter/reconstructable metadata as `CANONICAL_OWNER:00004S`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00004S`, and blank `EMITTER_POSITION_OPTIONAL:`.
  - [x] Populated the formal C++ block only with the comment-only covered-by marker. The scoped validator normalized the `[UID:00014L]` token into a markdown UID link in the header block, but the generated output remains only a C++ comment marker and no standalone helper body.
  - [x] Added the source-disposition marker and B004 current-session evidence.
  - [x] Refreshed raw boundary/body proof with MCP session `398b87c1`, exact `0x3c` / 60-byte range, unique signature, row-key compare at offset `+0`, found-index return, and `-1` miss return.
  - [x] Refreshed route proof with no function object, no xrefs, no VA/RVA/file-offset pointer-pattern hits, no focused immediate hits, and positive-control successor vtable routes.
  - [x] Added the dispatcher coverage link to [UID:00014L] case `2`.
  - [x] Preserved rejected alternatives and made clear the semantic standalone helper body is rejected for formal emission.
  - [x] Added a B004 2026-06-27 change-log entry.
- [x] Edited [by-class/ExchangeItemListPane.md](../../../../../by-class/ExchangeItemListPane.md).
  - Proof: the class C++ note and `FindOfferItemRowByKey` method row now say [UID:00014S] has a formal comment-only covered-by marker tied to [UID:00014L] case `2`, not a standalone emitted helper body.
  - Owner/emitter route and class score were left unchanged.
- [x] Edited [by-file/ExchangeDialog.md](../../../../../by-file/ExchangeDialog.md).
  - Proof: the file notes now state that `FindOfferItemRowByKey(unsigned char key) const` is represented by a covered-by marker tied to dispatcher case `2`, while preserving the source root `NexusTK/ui/dialogs/ExchangeDialog.cpp`.
- [x] Edited [by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md](../../../../../by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md).
  - Proof: the aggregate row and B004 boundary note now identify `00014S` as a retained no-route helper with formal dispatcher coverage through [UID:00014L] case `2`.
- [x] Edited [by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md](../../../../../by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md).
  - Proof: dispatcher status, subcommand `2`, source-quality notes, and the new cross-check section now explain that the inline row-key scan/update path covers the retained no-route `00014S` helper disposition.
- [x] Checked optional sibling [by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md](../../../../../by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md).
  - Proof: no edit was needed; the sibling wording did not directly contradict the accepted `00014S` marker policy.
- [x] Did not manually edit generated files, generated reports, manual `-coverage-report.md` files, validator/tool state, or IDA DB.
  - Proof: generated files and project-level projected stats changed only as validator/generator side effects from scoped validation. No manual coverage-report or IDA DB update was made.
- [x] Ran scoped validation from `source-3/project-documentation`.
  - Target validator: command `000000004330`, timestamp `2026-06-27T12:55:16-04:00`, exit `0`, `ok: 1`, generated refresh completed.
  - `by-class/ExchangeItemListPane.md`: command `000000004331`, timestamp `2026-06-27T12:55:27-04:00`, exit `0`, `ok: 1`.
  - `by-file/ExchangeDialog.md`: command `000000004332`, timestamp `2026-06-27T12:55:29-04:00`, exit `0`, `ok: 1`; pre-existing missing-ref warning remains for [UID:00014T] target path.
  - `by-memory/0x004ac8a0-0x004ae4b6.ExchangeDialog.md`: command `000000004333`, timestamp `2026-06-27T12:55:31-04:00`, exit `0`, `ok: 1`; validator inserted the missing [UID:00014S] link and repeated the pre-existing [UID:00014T] missing-ref warning.
  - `by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md`: command `000000004334`, timestamp `2026-06-27T12:55:37-04:00`, exit `0`, `ok: 1`; validator inserted the missing [UID:00014S] link/reference.
- [x] Inspected regenerated output for `00014S` after validator/generator refresh.
  - Proof: `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp` now has `UID:00014S` at `Completion:88 | Confidence:91` with a non-empty comment-only marker.
  - Proof: `auto-generated/-ag-memory-coverage.md` now lists [UID:00014S] as `coded`.
  - Proof: `auto-generated/-ag-coverage-report-by-memory.md` now lists [UID:00014S] as `emits_code:true`, `88%`, `very-strong`.
  - Proof: `auto-generated/-ag-research-tracker.md` now lists [UID:00014S] as `88/91`.
- [x] Released/cleared leases immediately after the edit/validator batch.
  - Proof: post-validation `python .\tools\leaser\leaser.py B004 unlease ...` returned `Rejected[No active lease]` for all five edited by-* pages, and `tools/leaser/Agents/current_leases.md` contains no matching B004 entries for the edited files.

## Final Implementation Status

Implementation is complete, validator-backed, and restricted to the accepted covered-by disposition. No standalone `ExchangeItemListPane::FindOfferItemRowByKey` body was emitted. All callback checklist items are checked with proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00014S-ExchangeItemListPaneRawFindHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00014S-ExchangeItemListPaneRawFindHelper-source-quality.md","timestamp":"2026-06-27T12:59:14","uid":"00014S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
