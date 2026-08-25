** TARGET-REPORT-UID:0003DB **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Report: [UID:0003DB] MacroEditControlPaneVtableData Empty Emitter

## Assignment

- Agent: B003
- Assignment id: `B003-report-0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-20260628`
- Target: [UID:0003DB][by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md](../../../../../by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md)
- Mode: report-only research first. I made no by-* edits, no leases, no generated/project/manual coverage/tool-state edits, no IDA DB edits, and spawned no subagents.
- Selection source: `auto-generated/-ag-research-tracker.md`, `Files With Empty Emitters`, where the current row reports [UID:0003DB] as `85/91`, reconstructable `true`, reports `0`.

## Recommendation

Implement after supervisor validation.

- Set [UID:0003DB] to `COMPLETION:88`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:0000KY`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000KY`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value blank.
- Insert the exact formal no-code/covered-by marker below into the target's multiline `RECONSTRUCTION_CPP CODE` block. This resolves the empty-emitter state without pretending that raw MSVC vtable bytes are handwritten source.

## Exact Formal RECONSTRUCTION_CPP CODE

```cpp
// [UID:0003DB] Compiler-generated MSVC vtable/RTTI data for SpellMacroEditControlPane,
// NewMacroEditControlPane, and IntegrateMacroEditControlPane is covered by the
// MacroDialogs.cpp class declarations and virtual method definitions; do not
// hand-emit raw .rdata vtable bytes.
```

This is intentionally comment-only formal C++. `tools/memory_ranges.py::parse_emits_code` treats any nonblank multiline reconstruction block as emitted code, and `tools/validator_background.py::is_empty_emitter_marker_candidate` emits an `Empty Emitter Marker` only when a reconstructable item has emitter UIDs and `metadata.code.strip()` is empty. A nonblank target-specific comment marker will therefore remove [UID:0003DB] from the generated empty-emitter queue while preserving the exact source-quality disposition.

## Current Target State

[UID:0003DB] currently has `COMPLETION:85`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000KY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY`, blank `EMITTER_POSITION_OPTIONAL`, blank inline/multiline `RECONSTRUCTION_CPP CODE`, a blank `Item Summary`, and `Nested:8`. The body already says the range is source-declared/generated-binary vtable data, should be assigned to [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md), and should not emit raw vtable bytes. The defect is that the formal code block and summary still leave a code-ready empty emitter.

Current generated evidence is consistent with that defect:

- `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` header `validator-command-id: 000000005127`, refreshed `2026-06-28T15:11:17-04:00`, currently contains `// UID:0003DB | by-memory\0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md | Completion:85 | Confidence:91 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` row `2646` places [UID:0003DB] in `Files With Empty Emitters`.
- `auto-generated/-ag-coverage-report-by-memory.md` row `2722` currently renders [UID:0003DB] as `emits_code:false` with a blank summary.

## Current MCP Session

MCP was available and current. I did not use a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`
- JSON-RPC flow used: `initialize`, `tools/list`, then `tools/call` with explicit `database` argument per the current schema.
- Required database/session: `supervisor_20260628_resume`
- `server_health(database=supervisor_20260628_resume)`: `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `idb_list`: one active adopted worker session `supervisor_20260628_resume`, backend `worker`, owned/adopted `true`, PID/worker PID `5124`, `is_analyzing:false`, created `2026-06-28T15:10:19.304678`, last accessed during this pass at `2026-06-28T15:16:49.478496`.

## Vtable And Boundary Evidence

Current MCP `entity_query(kind=names, min_addr=0x0062d1e0, max_addr=0x0062d3d0)` reports exactly ten named items in the target/successor window: the nine macro edit-control vtable views and `aCtrlD` at `0x0062d3cc`. The nine vtable names are:

| Address | IDA name |
| --- | --- |
| `0x0062d1e4` | `??_7SpellMacroEditControlPane@@6B@` |
| `0x0062d24c` | `??_7SpellMacroEditControlPane@@6B@_0` |
| `0x0062d27c` | `??_7SpellMacroEditControlPane@@6B@_1` |
| `0x0062d288` | `??_7NewMacroEditControlPane@@6B@` |
| `0x0062d2f0` | `??_7NewMacroEditControlPane@@6B@_0` |
| `0x0062d320` | `??_7NewMacroEditControlPane@@6B@_1` |
| `0x0062d32c` | `??_7IntegrateMacroEditControlPane@@6B@` |
| `0x0062d394` | `??_7IntegrateMacroEditControlPane@@6B@_0` |
| `0x0062d3c4` | `??_7IntegrateMacroEditControlPane@@6B@_1` |

Current MCP `list_globals` finds the same nine decorated vtable globals plus the nine matching RTTI complete-object-locator globals at `0x006507a0`, `0x00650800`, `0x00650814`, `0x00650828`, `0x00650888`, `0x0065089c`, `0x006508b0`, `0x00650910`, and `0x00650924`. Current `get_global_value` confirms the locator pointer immediately before each table:

| Locator pointer slot | Value |
| --- | --- |
| `0x0062d1e0` | `0x006507a0` |
| `0x0062d248` | `0x00650800` |
| `0x0062d278` | `0x00650814` |
| `0x0062d284` | `0x00650828` |
| `0x0062d2ec` | `0x00650888` |
| `0x0062d31c` | `0x0065089c` |
| `0x0062d328` | `0x006508b0` |
| `0x0062d390` | `0x00650910` |
| `0x0062d3c0` | `0x00650924` |

Current `get_bytes` at `0x0062d3c0` shows the final tertiary locator pointer, tertiary destructor thunk slot, `0x00544e90` base helper slot, and then UTF-16 `Ctrl+%d` beginning at `0x0062d3cc`. Current `xrefs_to 0x0062d3cc` reports string/data refs from `0x0057fb80` in `sub_57FAA0` and `0x00580095`/`0x005800a1` in `sub_57FFB0`. This keeps the target end exactly before the macro hotkey literal tail; do not extend the vtable-data page into strings.

## Table-Base Xref Evidence

Current `xrefs_to` for the nine vtable bases reports exactly three refs per base, matching constructor/setup, complete-object teardown/destructor artifact, and scalar-deleting destructor store families:

| Table base | Xrefs |
| --- | --- |
| `0x0062d1e4` | `0x0057f781`, `0x0057f7b0`, `0x00580776` |
| `0x0062d24c` | `0x0057f787`, `0x0057f7b6`, `0x0058077c` |
| `0x0062d27c` | `0x0057f791`, `0x0057f7c0`, `0x00580786` |
| `0x0062d288` | `0x0057fa03`, `0x0057fa80`, `0x00580716` |
| `0x0062d2f0` | `0x0057fa09`, `0x0057fa86`, `0x0058071c` |
| `0x0062d320` | `0x0057fa13`, `0x0057fa90`, `0x00580726` |
| `0x0062d32c` | `0x0057fd82`, raw/setup ref `0x0057ff09`, `0x0058069c` |
| `0x0062d394` | `0x0057fd88`, raw/setup ref `0x0057ff0f`, `0x005806a2` |
| `0x0062d3c4` | `0x0057fd92`, raw/setup ref `0x0057ff19`, `0x005806ac` |

The only oddity is already documented and should be preserved: the `IntegrateMacroEditControlPane` middle ref cluster at `0x0057ff09/0x0057ff0f/0x0057ff19` is not modeled as a separate IDA function. It is still vtable-store/layout evidence, not a new source function body for this `.rdata` target.

## Slot Evidence

Current MCP `get_global_value` for key slots confirms the existing [UID:0001Y1][MacroDialogFamilyVtables](../../../../../by-type/by-vtable/MacroDialogFamilyVtables.md) map:

| Class/view | Key values |
| --- | --- |
| `SpellMacroEditControlPane` primary | `0x0062d1e4 -> 0x00580770` scalar deleting destructor; `0x0062d228 -> 0x0057f7d0` `OnPaint`. |
| `SpellMacroEditControlPane` secondary | `0x0062d24c -> 0x00580671` adjustor thunk; `0x0062d250 -> 0x0057f9a0` `IsSelectable`; `0x0062d254 -> 0x0057f930` `OnKeyEvent`. |
| `SpellMacroEditControlPane` tertiary | `0x0062d27c -> 0x0058067c` adjustor thunk; `0x0062d280 -> 0x00544e90` shared base helper. |
| `NewMacroEditControlPane` primary | `0x0062d288 -> 0x00580710` scalar deleting destructor; `0x0062d2cc -> 0x0057faa0` `OnPaint`. |
| `NewMacroEditControlPane` secondary | `0x0062d2f0 -> 0x0058065b` adjustor thunk; `0x0062d2f4 -> 0x0057fd00` `IsSelectable`; `0x0062d2f8 -> 0x0057fc80` `OnKeyEvent`. |
| `NewMacroEditControlPane` tertiary | `0x0062d320 -> 0x00580666` adjustor thunk; `0x0062d324 -> 0x00544e90` shared base helper. |
| `IntegrateMacroEditControlPane` primary | `0x0062d32c -> 0x00580690` scalar deleting destructor; `0x0062d35c -> 0x00580550` attach hook; `0x0062d364 -> 0x005805c0` hide hook; `0x0062d370 -> 0x0057ffb0` `OnPaint`; `0x0062d384 -> 0x005805e0` sync hook; `0x0062d388 -> 0x00580640` activate thunk. |
| `IntegrateMacroEditControlPane` secondary | `0x0062d394 -> 0x00580645` adjustor thunk; `0x0062d398 -> 0x00580460` mouse forwarder; `0x0062d39c -> 0x00580320` key handler; `0x0062d3a0 -> 0x00580490` focus forwarder. |
| `IntegrateMacroEditControlPane` tertiary | `0x0062d3c4 -> 0x00580650` adjustor thunk; `0x0062d3c8 -> 0x00544e90` shared base helper. |

Current `lookup_funcs` confirms all key slot targets are modeled functions with the expected sizes, including `0x0057f7d0` size `0x157`, `0x0057f930` size `0x68`, `0x0057faa0` size `0x1d6`, `0x0057fc80` size `0x7f`, `0x0057ffb0` size `0x363`, `0x00580320` size `0x13d`, `0x00580460` size `0x24`, `0x00580490` size `0x24`, `0x00580550` size `0x63`, `0x005805c0` size `0x1a`, `0x005805e0` size `0x5e`, scalar deleting destructors `0x00580690` size `0x71`, `0x00580710` size `0x55`, and `0x00580770` size `0x55`.

Current `lookup_funcs` also confirms the thunk run:

| Address | Size | Role |
| --- | ---: | --- |
| `0x00580640` | `0x5` | vtable thunk to `RadioGroupControlPane::Activate` |
| `0x00580645` | `0xb` | `IntegrateMacroEditControlPane` secondary adjustor thunk |
| `0x00580650` | `0xb` | `IntegrateMacroEditControlPane` tertiary adjustor thunk |
| `0x0058065b` | `0xb` | `NewMacroEditControlPane` secondary adjustor thunk |
| `0x00580666` | `0xb` | `NewMacroEditControlPane` tertiary adjustor thunk |
| `0x00580671` | `0xb` | `SpellMacroEditControlPane` secondary adjustor thunk |
| `0x0058067c` | `0xb` | `SpellMacroEditControlPane` tertiary adjustor thunk |

Current `xrefs_to` for the thunk starts reports each thunk has a single data xref from the corresponding vtable slot. Current `xrefs_to` for `0x00580690`, `0x00580710`, and `0x00580770` reports the two adjustor code refs plus the primary vtable data ref for each scalar deleting destructor. This is ABI/vtable support evidence, not handwritten macro-dialog row behavior.

## Source-Quality Disposition

[UID:0003DB] is not a source-authored function, object definition, literal owner, or hand-maintained vtable array. It is exact compiler-generated MSVC `.rdata` for three `ControlPane`-derived classes in the MacroDialogs source family. The source-facing reconstruction work is the class declarations, inheritance, virtual method declarations, constructors/destructors, and virtual overrides recorded in [UID:0000KY][MacroDialogs](../../../../../by-file/MacroDialogs.md), the three edit-control class pages, and the method children. The binary vtable bytes are regenerated by the compiler from that class shape.

The current metadata route should remain reconstructable with [UID:0000KY] as emitter because this page belongs to the generated source view as declaration/layout evidence. But the target must not be blank formal C++. A comment-only covered-by marker is the correct implementation-ready disposition because it satisfies the generator's nonblank code requirement while explicitly forbidding raw `.rdata` emission.

Rejected alternatives:

- Hand-written C++ vtable arrays: rejected. The entries are MSVC ABI output, include complete-object locators and adjustor thunks, and should come from class declarations, not manually maintained arrays.
- Set `RECONSTRUCTABLE:FALSE` and clear emitters: rejected for this exact child. The range is source-declared/generated-binary data under MacroDialogs, and current docs/tracker intentionally route it through [UID:0000KY] after the strict gate clears.
- Leave `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY`, and blank C++: rejected. It preserves the assigned empty-emitter defect and loses the formal no-code proof.
- Move ownership to the mixed parent [UID:00026J][SpellInventoryMacroReadOnlyData](../../../../../by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md): rejected. That parent deliberately spans spell inventory plus macro data and is non-emitting; [UID:0003DB] is the exact MacroDialogs-owned child.
- Split the target further into one page per class/view: rejected for this pass. Current MCP confirms one contiguous macro edit-control vtable island with no unrelated data before the `0x0062d3cc` string boundary; finer split would duplicate the same no-code compiler-output disposition without improving the empty-emitter resolution.

## Support Doc Changes Required

If the supervisor accepts this report, update these by-* docs only; do not edit generated reports, generated C++ files, project-level generated files, manual coverage reports, tool state, or IDA DB.

### Target: `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`

Required edits:

- Change `COMPLETION:85` to `88`.
- Change `CONFIDENCE:91` to `93`.
- Keep owner/emitter/reconstructable metadata unchanged.
- Replace blank `Item Summary` with:

```text
Exact MacroDialogs-owned MSVC `.rdata` vtable island for Spell/New/Integrate MacroEditControlPane; current MCP confirms nine decorated vtable views, nine RTTI locator pointers, constructor/teardown/scalar-destructor xrefs, thunk/override slot values, and the `0x0062d3cc` `Ctrl+%d` successor boundary. Formal C++ is a nonblank covered-by marker because the bytes are compiler-generated from class declarations and virtual methods, not handwritten raw vtable arrays.
```

- Insert the exact `RECONSTRUCTION_CPP CODE` block from this report, keeping the inline code value blank.
- Add a `2026-06-28 B003 empty-emitter source-quality pass` evidence subsection or change note with the current MCP session, table names, locator pointers, xrefs, key slot values, generated marker state, and no-code proof.
- Update `Reconstruction Notes` to state that the formal comment-only marker is the intended generated output for this exact range; the source-bearing class/method bodies remain in MacroDialogs class/method pages.

### Support: `by-file/MacroDialogs.md`

Required edits:

- Add a concise `UID0003DB` support sync in `Evidence` or `Caveats`: current MCP session `supervisor_20260628_resume` reconfirmed the exact macro edit-control vtable island, and [UID:0003DB] should now contain a formal covered-by marker rather than an empty emitter.
- Preserve the existing MacroDialogs source grouping and do not add raw vtable array C++ to this by-file page.

### Support: `by-type/by-vtable/MacroDialogFamilyVtables.md`

Required edits:

- Add [UID:0003DB][by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md](../../../../../by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md) to `Cross-References`.
- Add a current evidence note that B003 2026-06-28 MCP `entity_query`, `list_globals`, `get_global_value`, `xrefs_to`, and `lookup_funcs` reconfirmed the nine edit-control vtable names, RTTI locator pointers, table-base xref triads, key override slots, thunk-only data references, and `Ctrl+%d` successor boundary.
- Clarify that [UID:0003DB] carries the formal no-code/covered-by marker for the exact `.rdata` child; this type page remains slot/declaration evidence and should not hand-emit vtable arrays.

No support edits are required for [UID:00026J][SpellInventoryMacroReadOnlyData](../../../../../by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md), [UID:0000DQ][SpellMacroEditControlPane](../../../../../by-class/SpellMacroEditControlPane.md), [UID:000095][NewMacroEditControlPane](../../../../../by-class/NewMacroEditControlPane.md), [UID:00006M][IntegrateMacroEditControlPane](../../../../../by-class/IntegrateMacroEditControlPane.md), or [UID:0001IN][MacroEditControlPaneVtableThunks](../../../../../by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md). Those pages already contain same-or-greater facts for ownership, class behavior, thunk classification, or compiler-generated rebuild handling. They can be left untouched unless the supervisor wants a broader support synchronization.

## Validator Expectations

After implementation, run scoped validators from `source-3/project-documentation` for each changed by-* file.

Target validator should wait for generated output:

> Executable block R001 was removed from this report and preserved verbatim in [0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-removed.md](0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Support validators:

> Executable block R002 was removed from this report and preserved verbatim in [0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-removed.md](0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected generated check after target validator: `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp` should have a generated header with command metadata equal to or newer than the target validator command. The [UID:0003DB] line should no longer contain `Empty Emitter Marker`; it should emit the four-line comment marker under the target UID.

## Implementation Tracking Checklist

Implementation callback status checked by B003 on 2026-06-28 after applying the accepted report. Supervisor still owns `execute_report`.

- [x] Target metadata in `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`: set `COMPLETION:88`, `CONFIDENCE:93`; preserved `CANONICAL_OWNER:0000KY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KY`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Target formal C++ block: inserted exactly the four-line comment-only `RECONSTRUCTION_CPP CODE` marker from this report; inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank.
- [x] Target summary/body: added the nonblank Item Summary, current `supervisor_20260628_resume` MCP evidence for names/RTTI pointers/xref triads/slot and thunk facts, the `Ctrl+%d` successor boundary, source-owner route, and rejected raw-vtable-array alternatives.
- [x] `by-file/MacroDialogs.md`: added UID0003DB support sync, current-session evidence, locator/xref details, and formal covered-by marker policy; no raw vtable array C++ was added.
- [x] `by-type/by-vtable/MacroDialogFamilyVtables.md`: added UID0003DB cross-reference, current-session view/RTTI/xref/slot/thunk evidence, parent assignment update, and no-raw-vtable-array clarification.
- [x] Confirmed no edits were needed for `by-memory/0x0062cfd8-0x0062d418.SpellInventoryMacroReadOnlyData.md`, the three edit-control class pages, or `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md`; accepted support changes were fully covered by the target, `MacroDialogs.md`, and `MacroDialogFamilyVtables.md`.
- [x] Ran target scoped validator with `--wait-generated`: `python .\tools\validator.py --mode file --file by-memory\0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md --apply --queue-timeout 240 --wait-generated`; `command_id: 000000005188`, `command_timestamp: 2026-06-28T18:14:41-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran support validator for `by-file/MacroDialogs.md`: `python .\tools\validator.py --mode file --file by-file\MacroDialogs.md --apply --queue-timeout 240`; `command_id: 000000005189`, `command_timestamp: 2026-06-28T18:14:57-04:00`, exit code `0`, `ok: 1`.
- [x] Ran support validator for `by-type/by-vtable/MacroDialogFamilyVtables.md`: `python .\tools\validator.py --mode file --file by-type\by-vtable\MacroDialogFamilyVtables.md --apply --queue-timeout 240`; `command_id: 000000005190`, `command_timestamp: 2026-06-28T18:15:02-04:00`, exit code `0`, `ok: 1`.
- [x] Checked generated `auto-generated/NexusTK/ui/dialogs/MacroDialogs.cpp`: header now reports `validator-command-id: 000000005190` and `validator-refreshed-at: 2026-06-28T18:15:02-04:00`, which is newer than/equal after the target command. UID0003DB appears at lines `321-325` with completion/confidence `88/93` and the accepted four-line comment marker; the UID0003DB line no longer contains `Empty Emitter Marker`.
- [x] Leases used/released immediately after edit/validator batch: B003 leased the three changed by-* docs at `2026-06-28T22:11:31Z` and released `by-memory/0x0062d1e0-0x0062d3cc.MacroEditControlPaneVtableData.md`, `by-file/MacroDialogs.md`, and `by-type/by-vtable/MacroDialogFamilyVtables.md` successfully after validators and generated check.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-06-28T18:17:27","uid":"0003DB"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0003DB-MacroEditControlPaneVtableData-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003DB"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
