** TARGET-REPORT-UID:0001DR **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B010 Report: UID0001DR MacroDialogs Source Quality

## Assignment And Scope

- Agent: B010
- Assignment: `B010-revise-report-0001DR-MacroDialogs-source-quality-20260628`
- Target: [UID:0001DR] `by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md`
- Phase: report-only research
- Restrictions honored for this report: no by-* doc edits, no generated/project/manual coverage/tool-state edits, no IDA DB edits or saves, no MCP start/stop/restart actions, no leases, and no validator runs. MCP was used read-only for inspection; the current revision opened the existing IDB through `idb_open` because `idb_list` initially had no active session.

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0001DR] from a reconstructable/emitting aggregate into a non-emitting split/container index, then create exact child by-memory pages for each method body in the range.
- Final disposition: [UID:0001DR] should keep source-family attachment to [UID:0000KY] `by-file/MacroDialogs.md`, but it should not itself emit source C++ because it spans three source classes and internal alignment padding.
- Required action after supervisor validation: create the exact child pages listed in this report, insert each child's formal C++ block from `CPP-1` through `CPP-13`, update the parent and support docs at report-level detail, record the internal padding spans, validate the changed files, and leave manual/generated coverage files to validator/supervisor ownership.
- Confidence: high for the split/container disposition and owner/source placement; medium-high for individual child scores because exact original source spelling remains inferred even though the behavior, ranges, command ids, storage offsets, and vtable evidence are now resolved.

## Supervisor Active Recheck

- Triggering instruction: B010 report-only checkpoint for [UID:0001DR] `MacroDialogs`, with IDA MCP evidence mandatory and no implementation edits until supervisor callback.
- Current assignment requires source-quality repair, not only an unchanged-score explanation. The previous blank-C++ blockers were investigated directly: constructor layout, command ids, row-control field/storage names, split disposition, destructor helper role, vtable evidence, and child/source placement.
- Every source-bearing child in this aggregate now has a concrete split recommendation and child-specific formal C++ block. No child is left as "needs later investigation" for the purpose of accepting this report.
- The only remaining work is implementation work after supervisor validation: child page creation/metadata assignment, by-* documentation incorporation, validation, and supervisor execution of the report.

## Inference Research Guidance Check

- Direct IDA facts in this report: function starts/sizes, xrefs, vtable references, internal padding bytes, caller/callee relationships, decompiled control flow, resource string references, and profile-storage offsets.
- Documentation evidence in this report: current target/support by-* docs, `RegistryConfigUserProfileBlock` layout, MacroDialogs source-family docs, edit-control class docs, vtable docs, scalar-destructor/thunk support docs, and generated tracker/coverage state as stale lead material.
- Inference in this report: source-facing member names and child filenames are inferred from current project style and `RegistryConfigUserProfileBlock` field names; they are not original-symbol proof. The inference is strong enough for documentation/source-quality repair because the storage offsets, access patterns, and consumers are already documented and IDA-backed.
- Stale Wave2/Wave3 material: no current recommendation depends on Wave2/Wave3. Any old batch notes in existing docs were treated only as historical lead context and rechecked against current docs/IDA evidence.

## MCP Evidence Status

IDA MCP evidence was available and used for this report.

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active session/database: `b001_000241_20260627`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Image base: `0x400000`
- Status: `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`

Evidence used: IDA function inventory, `lookup_funcs`, `analyze_component`, `analyze_function`, decompiler output for all functions in the range, `xrefs_to`, vtable/resource/string xrefs, targeted byte signatures, and offset conversions checked with `int_convert.py`.

Checkpoint revalidation after resume:

- Read-only MCP JSON-RPC initialize succeeded with session `4e5b9289-3239-40c1-b98e-6cda051994ad`.
- `idb_list` confirmed active database/session `b001_000241_20260627`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker pid `23132`, `is_analyzing=false`.
- Current MCP call schema required `database=b001_000241_20260627` on inspection calls; an initial `server_health`/`lookup_funcs` call without that argument returned a schema error, not an endpoint outage.
- `lookup_funcs` revalidated active modeled functions at `0x0053e520`, `0x0053e8f0`, `0x0053e960`, `0x0053ecf0`, `0x0053ed90`, `0x0053f0a0`, `0x0053f180`, and `0x0053f210`.
- `xrefs_to` revalidated OptionPane calls to `0x0053e520` and `0x0053e960`, vtable references to `0x0053e8f0`, `0x0053ecf0`, and `0x0053f0a0`, internal calls to `0x0053f180`/`0x0053f210`, and vtable-base references for `0x00620d10`, `0x00620dac`, and `0x00620e48`.

Revision revalidation for the 2026-06-28 rejection fix:

- JSON-RPC initialize/tools-list succeeded against the same endpoint. `idb_list` initially reported zero open sessions, then `idb_open` opened the existing IDB as session/database `b010_0001DR_20260628` without restarting MCP.
- Warmup health for `b010_0001DR_20260628`: IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input binary `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, image base `0x400000`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, `is_analyzing=false`.
- Current tool schema uses `database=b010_0001DR_20260628`; `decompile` uses singular `addr`, while `xrefs_to` uses `addrs`.
- Fresh `lookup_funcs` revalidated all thirteen proposed child starts and sizes: `0x0053e520` `0x3af`, `0x0053e8d0` `0x1f`, `0x0053e8f0` `0x69`, `0x0053e960` `0x370`, `0x0053ecd0` `0x1f`, `0x0053ecf0` `0x8a`, `0x0053ed80` `0x9`, `0x0053ed90` `0x2ef`, `0x0053f080` `0x1f`, `0x0053f0a0` `0xc6`, `0x0053f170` `0x9`, `0x0053f180` `0x83`, and `0x0053f210` `0xa6`.
- Fresh decompile output was reviewed for all thirteen child starts before writing the `CPP-1` through `CPP-13` formal C++ blocks.
- Fresh `xrefs_to` revalidated constructor calls at `0x0053e0f1 -> 0x0053e520` and `0x0053e0c6 -> 0x0053e960`; no xrefs to `0x0053ed90`; internal NewMacroDialog calls `0x0053f0ea/0x0053f127/0x0053f13a -> 0x0053f180` and `0x0053f0f3/0x0053f130 -> 0x0053f210`; and vtable-base refs for `0x00620d10`, `0x00620dac`, and `0x00620e48` from the corresponding constructor/destructor/scalar-destructor bodies.

## Current Target State

The target page currently presents `0x0053e520-0x0053f2b6` as one reconstructable emitting by-memory entry:

- `COMPLETION: 86`
- `CONFIDENCE: 88`
- `CANONICAL_OWNER: 0000KY`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 0000KY`
- Formal C++ block: blank

That state is source-quality blocked. The range is not one source body. It is an aggregate of exact method bodies for three dialog classes, separated by alignment bytes, with destructor/thunk support outside the target and a following FriendListDialog boundary at `0x0053f2c0`.

Related support docs checked:

- `by-file/MacroDialogs.md`
- `by-class/MacroDialog.md`
- `by-class/SpellMacroDialog.md`
- `by-class/NewMacroDialog.md`
- `by-class/NewMacroEditControlPane.md`
- `by-class/SpellMacroEditControlPane.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-type/by-struct/MacroHotkeyRecord.md`
- `by-type/by-vtable/MacroDialogFamilyVtables.md`
- `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`
- `by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md`
- `by-memory/-ignored.md`
- generated/tracker files were read only as state leads and were not edited.

## Function And Boundary Inventory

IDA reports these exact functions inside the target range:

| Range | Size | Current IDA name | Source-facing role |
|---|---:|---|---|
| `0x0053e520-0x0053e8cf` | `0x3af` / 943 | `sub_53E520` | `MacroDialog::MacroDialog` |
| `0x0053e8d0-0x0053e8ef` | `0x1f` / 31 | `sub_53E8D0` | `MacroDialog::~MacroDialog` non-deleting body |
| `0x0053e8f0-0x0053e959` | `0x69` / 105 | `sub_53E8F0` | `MacroDialog::SaveMacros` / command-confirm save handler |
| `0x0053e960-0x0053ecd0` | `0x370` / 880 | `sub_53E960` | `SpellMacroDialog::SpellMacroDialog` |
| `0x0053ecd0-0x0053ecef` | `0x1f` / 31 | `sub_53ECD0` | `SpellMacroDialog::~SpellMacroDialog` non-deleting body |
| `0x0053ecf0-0x0053ed7a` | `0x8a` / 138 | `sub_53ECF0` | `SpellMacroDialog::OnConfirm` |
| `0x0053ed80-0x0053ed89` | `0x09` / 9 | `sub_53ED80` | `SpellMacroDialog::SetVisible` |
| `0x0053ed90-0x0053f07f` | `0x2ef` / 751 | `sub_53ED90` | `NewMacroDialog::NewMacroDialog` |
| `0x0053f080-0x0053f09f` | `0x1f` / 31 | `sub_53F080` | `NewMacroDialog::~NewMacroDialog` non-deleting body |
| `0x0053f0a0-0x0053f166` | `0xc6` / 198 | `sub_53F0A0` | `NewMacroDialog::OnCommand` |
| `0x0053f170-0x0053f179` | `0x09` / 9 | `sub_53F170` | `NewMacroDialog::SetActiveControl` |
| `0x0053f180-0x0053f203` | `0x83` / 131 | `sub_53F180` | `NewMacroDialog::SaveMacroEntries` |
| `0x0053f210-0x0053f2b6` | `0xa6` / 166 | `sub_53F210` | `NewMacroDialog::LoadMacroPage` |

Internal alignment spans that should not remain hidden inside an emitting aggregate:

- `0x0053e8cf-0x0053e8d0`
- `0x0053e8ef-0x0053e8f0`
- `0x0053e959-0x0053e960`
- `0x0053ecef-0x0053ecf0`
- `0x0053ed7a-0x0053ed80`
- `0x0053ed89-0x0053ed90`
- `0x0053f07f-0x0053f080`
- `0x0053f09f-0x0053f0a0`
- `0x0053f166-0x0053f170`
- `0x0053f179-0x0053f180`
- `0x0053f203-0x0053f210`

The next function starts at `0x0053f2c0` (`sub_53F2C0`, FriendListDialog constructor). The signature for `0x0053f2b5-0x0053f2c0` is `00 CC CC CC CC CC CC CC CC CC CC`, confirming the last byte of `LoadMacroPage` followed by padding before FriendListDialog. The existing `by-memory/-ignored.md` already lists external padding `0x0053f2b6-0x0053f2c0`; implementation should preserve that and add the internal spans above.

## Evidence Checked

- IDA MCP:
  - Active database `b001_000241_20260627`.
  - `lookup_funcs` for every modeled function start in the aggregate.
  - `xrefs_to` for function starts, method vtable slots, vtable bases, and internal save/load targets.
  - Prior live MCP decompilation/body review for constructors, non-deleting destructors, command handlers, page save/load methods, tiny base forwarders, scalar deleting wrappers, and the OptionPane command opener.
  - Targeted byte checks for internal `0xcc` padding and the corrected `0x0053f2b6` endpoint.
- Local tool support:
  - `int_convert.py` conversions for profile offsets and object/control offsets, recorded below as verified conversions.
- by-* documentation:
  - Target page, MacroDialogs file page, three class pages, two edit-control class pages, registry profile layout, macro hotkey record, macro dialog vtable page, destructor/thunk support pages, ignored-padding ledger, and generated state reports.
- Negative checks:
  - No direct current constructor xref to `NewMacroDialog::NewMacroDialog` at `0x0053ed90`.
  - OptionPane caller evidence reaches only MacroDialog and SpellMacroDialog constructors in this pass; it does not prove OptionPane ownership.
  - `MacroHotkeyRecord` table at `+0x28f2ec` is not the direct storage used by UID0001DR's `NewMacroDialog` page save/load methods.
  - The aggregate parent has no single source-level function/class declaration shape suitable for broad parent C++.
- Failed/unavailable checks:
  - A read-only MCP `server_health`/`lookup_funcs` call without the required `database` argument returned a schema error. The corrected database-qualified calls succeeded, so MCP was not unavailable.

## Positive Evidence Summary

- Direct function boundary evidence maps this target into thirteen exact modeled functions and eleven internal padding spans, with no unresolved function-start ambiguity inside the range.
- Vtable evidence maps method bodies to three concrete classes: `MacroDialog`, `SpellMacroDialog`, and `NewMacroDialog`.
- Caller/callee evidence explains the two live OptionPane constructor routes, the virtual handler slots, and the internal `NewMacroDialog` save/load calls.
- Decompilation/body review resolves the prior source-quality blockers: resource/layout branch, OK/page command ids, row-control child ids, `NewMacroDialog` current-page field, and profile-storage offsets.
- Existing support docs already contain the profile layout and source-family placement needed to use human-readable inferred names instead of raw `dword_`/`sub_` labels.

## Negative Evidence Summary

- Contiguous address range is not sufficient evidence for a single emitting source body.
- Existing UID0001DR parent ownership by [UID:0000KY] is valid only as source-family/container placement; it is too broad for direct method emission.
- `OptionPane` caller xrefs do not transfer ownership of the macro dialog implementations to `OptionPane.cpp`.
- `RegistryConfigUserProfileBlock` and `MacroHotkeyRecord` explain storage, not source ownership of dialog methods.
- The `NewMacroDialog` constructor has no direct current xref; this must be preserved as a liveness caveat on the child/class docs, but the vtable, destructor, command, row-control, and storage evidence are strong enough to keep the class documented rather than ignored.
- The decompiler's `boost::exception::~exception` rendering on destructor tails is type pollution. It is not evidence for Boost ownership.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| UID0001DR should become a non-emitting split/container index. | High | Thirteen exact function bodies, three class vtable families, internal padding, and mixed class ownership inside one memory span. | Considered broad parent C++, `[[CHILDREN]]`, and direct MacroDialogs emission; all would conflate class/method boundaries. | Implementation must create exact child pages and validate parent/source metadata. |
| Source-family owner remains UID0000KY `MacroDialogs`. | High | Existing file/class docs, source-tree placement, related IntegrateMacroDialog split precedent, vtable family, resource names, and macro edit-control cluster. | Rejected OptionPane, RegistryConfig, MacroHotkeyRecord, and destructor-island ownership for method bodies. | None for source-family placement; child links need assigned UIDs after creation. |
| `MacroDialog` text rows use `m_profileTextSlots[10][0x80]` at `g_pConfig+0x28de9c`. | High for role, inferred for exact name | Constructor/save offsets, `int_convert.py`, and `RegistryConfigUserProfileBlock` field table. | Checked `MacroHotkeyRecord`; it starts later at `+0x28f2ec` and is not this storage. | Exact original spelling remains unavailable, but current source-facing name is role-accurate. |
| `SpellMacroDialog` writes `m_legacyShortcutText[10][0x80]` at `g_pConfig+0x28e89c`. | High for role, inferred for exact name | Constructor and confirm handler offsets, `GetSpellKey`, zero word at `+2`, and registry profile docs. | Checked runtime consumers and integrated macro table; this slice is legacy shortcut text, not integrated macro hotkeys. | Exact original spelling remains inferred. |
| `NewMacroDialog` save/load uses `m_compactShortcutRecords[20]` at `g_pConfig+0x28f29c`. | High for role, inferred for exact name | Constructor, save, load methods, `NewMacroEditControlPane` getters/setters, two-page command handling, registry profile docs. | Rejected direct `MacroHotkeyRecord` dependency for this exact range; integrated macro table begins at `+0x28f2ec`. | Preserve no-direct-constructor-xref caveat until a caller/registration route is found. |
| Non-deleting destructor helpers should be child pages but may keep no broad parent C++. | High | Vtable reset patterns, scalar deleting wrapper support docs, and base-dialog teardown tailcall. | Rejected deleting-wrapper import into UID0001DR and rejected Boost ownership from decompiler type pollution. | This revision supplies empty source-level destructor bodies for the exact children and documents that the compiler regenerates vtable reset/base teardown glue. |

## Body-Level Findings

### MacroDialog

`0x0053e520` constructs the older macro dialog and installs the MacroDialog vtables at `this+0`, `this+0xa0`, and `this+0xa4`. It initializes a dialog with class/resource tag `aMa_5`, mode `4`, and EPF/EPD layout branches gated by `byte_66DA97`.

The constructor uses:

- EPF path: `DLGMACRO.EPF`, `DLGMACRO.PAL`, image rectangle `(0,0,289,399)`, OK button id `14` at `(118,362,181,386)`, ten edit controls at ids `2..11`, row y-step `29`, and dialog bounds `(130,10,419,409)`.
- EPD path: `DLGMACRO.EPD`, palette `aNp`, image rectangle `(0,0,407,391)`, OK button id `14` at `(168,341,240,357)`, ten edit controls at ids `2..11`, row y-step `21`, and dialog bounds `(130,10,537,401)`.
- Direct profile storage: `g_pConfig + 0x28de9c + row*0x100`, matching `RegistryConfigUserProfileBlock::m_profileTextSlots[10][0x80]`.

`0x0053e8d0` is the non-deleting destructor body. It resets the three vtable pointers back to MacroDialog vtables and calls the base dialog teardown. The decompiler currently renders the base teardown as `boost::exception::~exception`; that is type pollution and should be documented as base-dialog teardown, not Boost source ownership.

`0x0053e8f0` is the save/confirm command path. When command id `1` is received, it loops child controls `2..11`, reads text through the text-control helper, writes 64 wide units into `g_pConfig + 0x28de9c + row*0x100`, then closes/removes the dialog through `sub_49EB90` and `sub_469180(dword_67A74C, this)`.

### SpellMacroDialog

`0x0053e960` constructs the spell macro dialog and installs the SpellMacroDialog vtables at `this+0`, `this+0xa0`, and `this+0xa4`. It shares the same broad resource family as MacroDialog but creates `SpellMacroEditControlPane` rows with `sub_57F760`.

The constructor uses:

- EPF/EPD layout branches with `DLGMACRO.EPF`, `DLGMACRO.EPD`, `DLGMACRO.PAL`, and `aNp`.
- Ten spell edit-control rows at ids `2..11`.
- Direct legacy shortcut storage: `g_pConfig + 0x28e89c + row*0x100`, matching `RegistryConfigUserProfileBlock::m_legacyShortcutText[10][0x80]`.

`0x0053ecd0` is the non-deleting destructor body, with the same vtable reset plus base-dialog teardown pattern as MacroDialog.

`0x0053ecf0` is the confirm handler. For command id `1`, it loops controls `2..11`, calls `SpellMacroEditControlPane::GetSpellKey` (`0x0057f750`), writes the key word into `g_pConfig + 0x28e89c + row*0x100`, writes a trailing zero word at `+2`, closes/removes the dialog, and calls the user-settings save path when `dword_67A764` is set.

`0x0053ed80` is a 9-byte visibility forwarder to the base dialog visibility helper `sub_49FC00(this, state)`. The signature for `0x0053ed80-0x0053ed90` is `55 8B EC 5D E9 77 0E F6 FF CC CC CC CC CC CC CC`, confirming the tiny body and padding before NewMacroDialog.

### NewMacroDialog

`0x0053ed90` constructs the newer paged macro shortcut dialog and installs the NewMacroDialog vtables at `this+0`, `this+0xa0`, and `this+0xa4`. It initializes `this+0x26c` to zero as the current page field.

The constructor uses:

- Resource path: `DLGMAC2.EPF`, `DLGMACRO.PAL`, and `DLGMACRO.EPF`.
- OK button id `14`.
- Ten `NewMacroEditControlPane` rows at ids `2..11`, constructed by `sub_57F9D0`.
- Initial row data from `g_pConfig + 0x28f29c + row*4`, matching `RegistryConfigUserProfileBlock::m_compactShortcutRecords[20]`; key word at `+0`, mode/modifier byte at `+2`.
- Page button/control ids `12` and `13`, with image/resource ids `18` and `19`.

`0x0053f080` is the non-deleting destructor body. It resets the NewMacroDialog vtables and calls the same base-dialog teardown pattern.

`0x0053f0a0` is the command handler:

- command id `1`: `SaveMacroEntries`, close/remove dialog, and save user settings when dirty.
- command id `12`: toggle page controls, save current page, then `LoadMacroPage(0)`.
- command id `13`: toggle page controls, save current page, then `LoadMacroPage(1)`.

`0x0053f170` is a 9-byte base forwarder through `sub_49FC00(this, state)`.

`0x0053f180` saves the visible ten rows. It reads each row's key and modifier through `NewMacroEditControlPane` helpers (`0x0057f9b0`, `0x0057f9c0`) and writes them to `g_pConfig + 0x28f29c + (currentPage*10 + row)*4`.

`0x0053f210` loads a page. When the requested page differs from `this+0x26c`, it updates the current page and loops the ten row controls, setting index, key binding, modifier, and refresh state through `NewMacroEditControlPane` setters (`0x0057fa30`, `0x0057fa70`, `0x0057fa60`, `0x0057fa40`).

## Storage And Type Reanalysis

The target page's current broad wording around MacroHotkeyRecord should be corrected. UID0001DR directly manipulates three profile slices:

- `MacroDialog`: `g_pConfig + 0x28de9c`, `m_profileTextSlots[10][0x80]`
- `SpellMacroDialog`: `g_pConfig + 0x28e89c`, `m_legacyShortcutText[10][0x80]`
- `NewMacroDialog`: `g_pConfig + 0x28f29c`, `m_compactShortcutRecords[20]`

`MacroHotkeyRecord` at `g_pConfig + 0x28f2ec` is not the direct storage for UID0001DR's NewMacroDialog. It belongs to the integrated macro/hotkey table used by `IntegrateMacroDialog` outside this target range. It can remain a related comparison dependency in support docs, but implementation should not describe UID0001DR's NewMacroDialog rows as direct `MacroHotkeyRecord` rows.

Converted decimal offsets were checked with `int_convert.py`, including:

- `2678428 == 0x28de9c`
- `2680988 == 0x28e89c`
- `2683548 == 0x28f29c`
- `2683550 == 0x28f29e`
- `2683628 == 0x28f2ec`
- `508 == 0x1fc`
- `620 == 0x26c`

## Vtable, Caller, And Liveness Evidence

Vtable evidence supports three distinct classes under the same source file owner:

- MacroDialog primary vtable `0x00620d10-0x00620d6c`
  - slot `+0x00`: scalar deleting destructor `0x005427a0`
  - slot `+0x48`: `0x0053e8f0`
  - constructor/destructor references: `0x0053e561`, `0x0053e8d0`, `0x005427a6`
- SpellMacroDialog primary vtable `0x00620dac-0x00620e08`
  - slot `+0x00`: scalar deleting destructor `0x00542a00`
  - slot `+0x48`: `0x0053ecf0`
  - slot `+0x58`: `0x0053ed80`
  - constructor/destructor references: `0x0053e9a1`, `0x0053ecd0`, `0x00542a06`
- NewMacroDialog primary vtable `0x00620e48-0x00620ea4`
  - slot `+0x00`: scalar deleting destructor `0x00542800`
  - slot `+0x48`: `0x0053f0a0`
  - slot `+0x58`: `0x0053f170`
  - constructor/destructor references: `0x0053edd3`, `0x0053f080`, `0x00542806`

Caller evidence:

- `0x0053e520` is called from OptionPane command handling at `0x0053e0f1`.
- `0x0053e960` is called from OptionPane command handling at `0x0053e0c6`.
- `0x0053ed90` has no direct code xref in the current IDA pass.
- `0x0053f180` is called from NewMacroDialog command handling at `0x0053f0ea`, `0x0053f127`, and `0x0053f13a`.
- `0x0053f210` is called from NewMacroDialog command handling at `0x0053f0f3` and `0x0053f130`.

The no-direct-xref result for `NewMacroDialog::NewMacroDialog` is negative evidence that must be preserved. It does not justify ignoring the function: the constructor, destructor, vtable slots, row-control helpers, compact profile records, and page command handlers form a coherent source-shaped dialog class. It does mean implementation should avoid overstating confirmed runtime instantiation.

## Heuristic And Inference Reanalysis

The current aggregate page was probably accepted because the full memory span is contiguous and all functions belong to `MacroDialogs.cpp`. That heuristic is insufficient for code emission:

- The target contains methods for three classes, not one function or one class declaration.
- Exact function starts and ends are known.
- Internal alignment padding is present between method bodies.
- Source-facing storage roles are now separable by class.
- Vtable evidence maps virtual methods to class-specific pages.
- NewMacroDialog has a liveness caveat that belongs on its constructor/destructor docs, not hidden in a broad parent.

Source placement remains `NexusTK/ui/dialogs/MacroDialogs.cpp` under file owner UID0000KY, but ownership and emission should be routed through class-specific by-memory children and support class pages.

## Ownership And Source Disposition

Ranked ownership disposition:

1. `by-file/MacroDialogs.md` / UID0000KY remains canonical source file owner for the full family.
2. `by-class/MacroDialog.md` / UID00007I owns MacroDialog method children.
3. `by-class/SpellMacroDialog.md` / UID0000DP owns SpellMacroDialog method children.
4. `by-class/NewMacroDialog.md` / UID000094 owns NewMacroDialog method children.
5. `RegistryConfigUserProfileBlock` owns profile storage fields but not the dialog method bodies.
6. OptionPane is only a caller for MacroDialog and SpellMacroDialog constructors in the current evidence.

Recommended parent target disposition:

- Change UID0001DR to a non-emitting split/container index.
- `COMPLETION: 90`
- `CONFIDENCE: 91`
- `CANONICAL_OWNER: 0000KY`
- `RECONSTRUCTABLE: FALSE`
- `EMITTER_UIDS:` blank
- Keep the formal C++ section blank.
- Replace the broad source claim with an exact child index and support evidence summary.

The parent should not emit `[[CHILDREN]]`. UID0001DR is not a single class declaration or a stable source insertion point. It is a memory aggregate covering methods from three classes plus alignment. Method C++ should route through exact by-memory children; this revised report supplies exact first-draft formal C++ content for every proposed source-bearing child page so the split no longer depends on a later child-source pass.

## Required New Child Pages

Implementation should split the parent into exact by-memory child pages. UID assignment must be left to the validator during implementation; the report intentionally uses filenames/ranges rather than invented UIDs.

| New page | Owner | Reconstructable | Emitter | Recommended score | Required content | Formal C++ disposition |
|---|---|---|---|---:|---|---|
| `by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md` | UID00007I | TRUE | UID00007I | 87/90 | EPF/EPD layouts, vtable writes, controls `2..11`, OK image id `14`, profile text slots `+0x28de9c` | Insert child C++ block `CPP-1` below. |
| `by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md` | UID00007I | TRUE | UID00007I | 86/90 | vtable reset and base-dialog teardown; mark Boost label as decompiler pollution | Insert child C++ block `CPP-2` below. |
| `by-memory/0x0053e8f0-0x0053e959.MacroDialogSaveMacros.md` | UID00007I | TRUE | UID00007I | 88/91 | command id `1`, controls `2..11`, text copy to `m_profileTextSlots`, close/remove | Insert child C++ block `CPP-3` below. |
| `by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md` | UID0000DP | TRUE | UID0000DP | 87/90 | spell rows, EPF/EPD layouts, `m_legacyShortcutText`, `SpellMacroEditControlPane` construction | Insert child C++ block `CPP-4` below. |
| `by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md` | UID0000DP | TRUE | UID0000DP | 86/90 | vtable reset and base-dialog teardown | Insert child C++ block `CPP-5` below. |
| `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md` | UID0000DP | TRUE | UID0000DP | 88/91 | command id `1`, `GetSpellKey`, write key plus terminator into legacy shortcut text, dirty-save path | Insert child C++ block `CPP-6` below. |
| `by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetVisible.md` | UID0000DP | TRUE | UID0000DP | 86/90 | base visibility forwarder, vtable slot `+0x58` | Insert child C++ block `CPP-7` below. |
| `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` | UID000094 | TRUE | UID000094 | 87/89 | paged compact shortcut dialog, current page field `+0x26c`, rows `2..11`, ids `12/13/14`, compact records `+0x28f29c`, no-direct-xref caveat | Insert child C++ block `CPP-8` below. |
| `by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md` | UID000094 | TRUE | UID000094 | 86/89 | vtable reset, base-dialog teardown, no direct xref but vtable/scalar destructor support | Insert child C++ block `CPP-9` below. |
| `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md` | UID000094 | TRUE | UID000094 | 89/91 | command ids `1`, `12`, `13`; save/close, page toggles, page load calls | Insert child C++ block `CPP-10` below. |
| `by-memory/0x0053f170-0x0053f179.NewMacroDialogSetActiveControl.md` | UID000094 | TRUE | UID000094 | 86/90 | base active/visibility forwarder, vtable slot `+0x58` | Insert child C++ block `CPP-11` below. |
| `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` | UID000094 | TRUE | UID000094 | 88/91 | save ten visible rows into `m_compactShortcutRecords[currentPage*10+row]` | Insert child C++ block `CPP-12` below. |
| `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` | UID000094 | TRUE | UID000094 | 88/91 | update current page, set row index/key/modifier/refresh from compact records | Insert child C++ block `CPP-13` below. |

## First-Draft C++ Recommendation / No-Code Disposition

No broad C++ should be added to UID0001DR. Implementation should leave the parent formal C++ blank and mark it non-reconstructable. Exact parent no-code proof: UID0001DR is a memory split/container over three class method groups plus alignment padding, not a source-level function, class declaration, table, or stable insertion point. Emitting a parent `[[CHILDREN]]` block would incorrectly make the aggregate look like one original source unit and would hide the exact child method ownership. The source-authored behavior is covered by the child formal C++ blocks below.

All proposed source-bearing children remain reconstructable, keep their class owner/emitter route, and now have exact first-draft formal `RECONSTRUCTION_CPP CODE` content for the implementation callback. The inline `RECONSTRUCTION_CPP CODE:[[[]]]` value should remain blank for these children; insert the C++ between the formal BEGIN/END lines. The source-facing helper names below are inferred/descriptive replacements for current IDA labels and are meant to be normalized with the existing `DialogPane`, image-button, edit-control, `RegistryConfig`, and `MacroDialogs.cpp` support docs during implementation. They avoid raw `sub_`, `dword_`, `byte_`, and decompiler temporary names in emitted source.

Destructor-source distinction for `CPP-2`, `CPP-5`, and `CPP-9`: each exact non-deleting destructor helper is the compiler-emitted complete-object destructor body for a source-level class destructor. The source-authored C++ should be an ordinary destructor definition; the compiler regenerates the vtable restore and base-dialog teardown, while the scalar deleting destructor wrappers remain in the separate destructor island and are not copied into these children.

### CPP-1 `MacroDialog::MacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md`:

```cpp
MacroDialog::MacroDialog()
    : DialogPane(kMacroDialogCaption, 4, true)
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;
    Rect dialogBounds;

    if (UseEpfMacroDialogLayout())
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 59 + row * 29;
            AddControl(new TextEditControlPane(
                g_pConfig->m_profileTextSlots[row],
                true,
                0x80,
                0x8f,
                Rect(49, y, 251, y + 12),
                true));
        }

        SetBackgroundResource(L"DLGMACRO.EPF");
        dialogBounds = Rect(130, 10, 419, 409);
    }
    else
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPD", Rect(0, 0, 407, 391), kNpPaletteName));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(168, 341, 240, 357)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 94 + row * 21;
            AddControl(new TextEditControlPane(
                g_pConfig->m_profileTextSlots[row],
                true,
                0x80,
                0x8f,
                Rect(134, y, 291, y + 12),
                true));
        }

        SetBackgroundResource(L"DLGMACRO.EPD");
        dialogBounds = Rect(130, 10, 537, 401);
    }

    SetActiveControl(kFirstRowControlId);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBounds(dialogBounds);
    SetLayer(g_pDialogLayer);
    Show();
}
```

### CPP-2 `MacroDialog::~MacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md`:

```cpp
MacroDialog::~MacroDialog()
{
}
```

### CPP-3 `MacroDialog::SaveMacros`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053e8f0-0x0053e959.MacroDialogSaveMacros.md`:

```cpp
void MacroDialog::SaveMacros(int commandId, int /*controlId*/)
{
    if (commandId != kDialogCommandOk)
        return;

    for (int row = 0; row < 10; ++row)
    {
        TextEditControlPane *edit = GetChild<TextEditControlPane>(2 + row);
        edit->CopyTextTo(g_pConfig->m_profileTextSlots[row], 64);
    }

    Close();
    g_pGeneralPurposePanel->RemoveDialog(this);
}
```

### CPP-4 `SpellMacroDialog::SpellMacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md`:

```cpp
SpellMacroDialog::SpellMacroDialog()
    : DialogPane(kMacroDialogCaption, 5, true)
{
    const int kRowCount = 10;
    const int kFirstRowControlId = 2;
    Rect dialogBounds;

    if (UseEpfMacroDialogLayout())
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 54 + row * 29;
            AddControl(new SpellMacroEditControlPane(
                g_pConfig->m_legacyShortcutText[row][0],
                Rect(49, y, 250, y + 20)));
        }

        SetBackgroundResource(L"DLGMACRO.EPF");
        dialogBounds = Rect(130, 10, 419, 409);
    }
    else
    {
        AddControl(new ResourceImagePane(L"DLGMACRO.EPD", Rect(0, 0, 407, 391), kNpPaletteName));
        AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(168, 341, 240, 357)));

        for (int row = 0; row < kRowCount; ++row)
        {
            const int y = 94 + row * 21;
            AddControl(new SpellMacroEditControlPane(
                g_pConfig->m_legacyShortcutText[row][0],
                Rect(134, y, 291, y + 12)));
        }

        SetBackgroundResource(L"DLGMACRO.EPD");
        dialogBounds = Rect(130, 10, 537, 401);
    }

    SetActiveControl(kFirstRowControlId);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBounds(dialogBounds);
    SetLayer(g_pDialogLayer);
    Show();
}
```

### CPP-5 `SpellMacroDialog::~SpellMacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md`:

```cpp
SpellMacroDialog::~SpellMacroDialog()
{
}
```

### CPP-6 `SpellMacroDialog::OnConfirm`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md`:

```cpp
void SpellMacroDialog::OnConfirm(int commandId, int /*controlId*/)
{
    if (commandId != kDialogCommandOk)
        return;

    for (int row = 0; row < 10; ++row)
    {
        SpellMacroEditControlPane *edit = GetChild<SpellMacroEditControlPane>(2 + row);
        g_pConfig->m_legacyShortcutText[row][0] = edit->GetSpellKey();
        g_pConfig->m_legacyShortcutText[row][1] = 0;
    }

    Close();
    g_pGeneralPurposePanel->RemoveDialog(this);

    if (g_userSettingsDirty)
        SaveUserSettings();
}
```

### CPP-7 `SpellMacroDialog::SetVisible`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetVisible.md`:

```cpp
void SpellMacroDialog::SetVisible(int state)
{
    DialogPane::SetVisible(state);
}
```

### CPP-8 `NewMacroDialog::NewMacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md`:

```cpp
NewMacroDialog::NewMacroDialog()
    : DialogPane(kMacroDialogCaption, 6, true),
      m_currentPage(0)
{
    g_pGeneralPurposePanel->SwitchActiveChild(3, false);
    PrepareMacroDialogPalette(g_pMacroDialogPalette, 0x198, 100);

    AddControl(new ResourceImagePane(L"DLGMAC2.EPF", Rect(0, 0, 289, 399), L"DLGMACRO.PAL"));
    AddControl(new ImageButtonControlPane(kMacroOkImageId, Rect(118, 362, 181, 386)));

    for (int row = 0; row < 10; ++row)
    {
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[row];
        const int y = 54 + row * 29;
        AddControl(new NewMacroEditControlPane(
            record.key,
            row,
            record.mode,
            Rect(19, y, 268, y + 20)));
    }

    ImageButtonControlPane *previous = new ImageButtonControlPane(kMacroPreviousImageId, Rect(30, 362, 93, 386));
    previous->Disable();
    AddControl(previous);

    AddControl(new ImageButtonControlPane(kMacroNextImageId, Rect(200, 362, 263, 386)));

    SetActiveControl(2);
    SetModal(true);
    SetCloseOnEscape(true);
    SetBackgroundResource(L"DLGMACRO.EPF");
    SetBounds(Rect(130, 10, 419, 409));
    SetLayer(g_pDialogLayer);
}
```

### CPP-9 `NewMacroDialog::~NewMacroDialog`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md`:

```cpp
NewMacroDialog::~NewMacroDialog()
{
}
```

### CPP-10 `NewMacroDialog::OnCommand`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md`:

```cpp
void NewMacroDialog::OnCommand(int commandId, int controlId)
{
    switch (commandId)
    {
    case kDialogCommandOk:
        SaveMacroEntries();
        Close();
        g_pGeneralPurposePanel->RemoveDialog(this);
        if (g_userSettingsDirty)
            SaveUserSettings();
        break;

    case kMacroFirstPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Disable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Enable();
        SaveMacroEntries();
        LoadMacroPage(0);
        break;

    case kMacroSecondPageCommand:
        GetChild<ImageButtonControlPane>(kMacroFirstPageCommand)->Enable();
        GetChild<ImageButtonControlPane>(kMacroSecondPageCommand)->Disable();
        SaveMacroEntries();
        LoadMacroPage(1);
        break;

    default:
        (void)controlId;
        break;
    }
}
```

### CPP-11 `NewMacroDialog::SetActiveControl`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053f170-0x0053f179.NewMacroDialogSetActiveControl.md`:

```cpp
void NewMacroDialog::SetActiveControl(int controlId)
{
    DialogPane::SetActiveControl(controlId);
}
```

### CPP-12 `NewMacroDialog::SaveMacroEntries`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md`:

```cpp
void NewMacroDialog::SaveMacroEntries()
{
    const int baseIndex = m_currentPage * 10;

    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        record.key = edit->GetKey();
        record.mode = edit->GetMode();
    }
}
```

### CPP-13 `NewMacroDialog::LoadMacroPage`

Formal child `RECONSTRUCTION_CPP CODE` content for `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`:

```cpp
void NewMacroDialog::LoadMacroPage(int page)
{
    if (m_currentPage == page)
        return;

    m_currentPage = page;

    const int baseIndex = page * 10;
    for (int row = 0; row < 10; ++row)
    {
        NewMacroEditControlPane *edit = GetChild<NewMacroEditControlPane>(2 + row);
        const CompactShortcutRecord &record = g_pConfig->m_compactShortcutRecords[baseIndex + row];

        edit->SetRecordIndex(baseIndex + row);
        edit->SetKey(record.key);
        edit->SetMode(record.mode);
        edit->Refresh();
    }
}
```

## Target And Support Doc Edit Plan

During the implementation callback, edit only the target/support docs listed here and any exact new child pages required by the split.

Target parent:

- `by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md`
  - Convert to non-emitting split/container index.
  - Update metadata as recommended above.
  - Replace the current single-range source summary with an exact child table and padding/boundary evidence.
  - Correct direct profile dependencies to `m_profileTextSlots`, `m_legacyShortcutText`, and `m_compactShortcutRecords`.
  - Preserve the NewMacroDialog no-direct-constructor-xref caveat.

Padding ledger:

- `by-memory/-ignored.md`
  - Add the internal alignment spans listed in this report.
  - Preserve existing `0x0053f2b6-0x0053f2c0` external padding before FriendListDialog.

Primary support docs:

- `by-file/MacroDialogs.md`
  - Add UID0001DR as a non-emitting split/container with exact child pages.
  - Distinguish direct UID0001DR storage from `IntegrateMacroDialog`'s `MacroHotkeyRecord` table.
  - Record NewMacroDialog's no-direct-instantiation-xref caveat.
  - Record or normalize the source-facing helper/constant names used by the child C++ blocks, including `kMacroDialogCaption`, `UseEpfMacroDialogLayout`, `kNpPaletteName`, `kDialogCommandOk`, `kMacroFirstPageCommand`, `kMacroSecondPageCommand`, and the dialog/image-button helper classes.
- `by-class/MacroDialog.md`
  - Link the three MacroDialog child pages.
  - Replace unresolved source-quality notes with the resolved layout/save evidence.
  - Keep class-level declaration C++ blank unless a separate accepted declaration-level implementation is assigned; do not omit the child method C++ blocks supplied in this report.
- `by-class/SpellMacroDialog.md`
  - Link the constructor/destructor/confirm/visibility child pages.
  - Add `m_legacyShortcutText` and `GetSpellKey` save evidence.
- `by-class/NewMacroDialog.md`
  - Link the six NewMacroDialog child pages.
  - Correct the direct storage dependency from `MacroHotkeyRecord` to `m_compactShortcutRecords`.
  - Add command ids `1`, `12`, and `13`, current page field `+0x26c`, and no-direct-constructor-xref caveat.
- `by-class/NewMacroEditControlPane.md`
  - Add or verify support note that NewMacroDialog save/load uses its getters/setters for compact shortcut records, not `MacroHotkeyRecord`.
- `by-class/SpellMacroEditControlPane.md`
  - Add or verify support note that SpellMacroDialog confirm writes `GetSpellKey` into legacy shortcut text.

Secondary support docs to verify after child UIDs exist:

- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
  - Already has the required profile-field layout; only add child cross-links if the implementation standard requires them.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
  - Verify profile slice references remain accurate; add child cross-links only if needed.
- `by-type/by-vtable/MacroDialogFamilyVtables.md`
  - Already has the three vtable groups and slot mappings; add exact child links if not already present after new UIDs are assigned.
- `by-project-structure/proposed-source-tree.md`
  - No source-placement change expected; `MacroDialogs.cpp` is already the correct source file placement.

Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB.

## Rejected Alternatives

- Keep UID0001DR as one reconstructable/emitting page: rejected because it merges three classes, many method bodies, and alignment padding into one source unit.
- Emit broad parent C++: rejected for the same reason; it would obscure method ownership and NewMacroDialog liveness caveats.
- Put `[[CHILDREN]]` on UID0001DR: rejected because the parent is not a single class declaration or source insertion point.
- Move ownership to OptionPane: rejected; OptionPane calls MacroDialog and SpellMacroDialog constructors but does not own the dialog implementations.
- Move ownership to RegistryConfig or MacroHotkeyRecord: rejected; those docs own storage structures, not the UI method bodies.
- Treat NewMacroDialog as dead and ignore it: rejected; no direct constructor xref is real negative evidence, but vtable, destructor, command, row-control, and storage evidence prove a coherent source-shaped class.
- Import scalar deleting destructors or adjustor thunks into the target: rejected; ABI thunk/destructor support belongs in separate support docs or existing vtable/thunk coverage, not this aggregate target.

## Open Questions With Attempted Resolution

- Constructor layout: resolved enough for split/source-quality documentation. The report identifies class vtable writes, resource branches, control ids, row positions, storage offsets, and the `NewMacroDialog` current-page field. Exact original constructor parameter names remain unavailable and should be treated as inferred in future C++.
- Command ids: resolved. `1` is OK/save/confirm; `12` loads page 0; `13` loads page 1. Button/resource ids `18` and `19` correspond to the two page controls created by `NewMacroDialog`.
- Row-control field/storage names: resolved at source-quality level by tying each slice to `RegistryConfigUserProfileBlock`: `m_profileTextSlots`, `m_legacyShortcutText`, and `m_compactShortcutRecords`. Exact original spelling remains inferred, but no raw labels are needed in recommended docs.
- `NewMacroDialog` liveness: partially unresolved but score-accounted. Current IDA xrefs show no direct constructor call to `0x0053ed90`; however, the method cluster, vtable stores, scalar destructor support, command handlers, edit-control interaction, and compact record storage show a coherent class that should be documented. Implementation must preserve the no-direct-xref caveat instead of hiding it.
- Parent C++ eligibility: resolved. UID0001DR should not emit because it is a memory aggregate over multiple classes plus padding. The correct current repair is split/container handling with child pages, not broad parent C++.
- Internal padding coverage: resolved as an implementation item. Exact spans are listed and should be added to `by-memory/-ignored.md` during the accepted implementation callback.
- Source placement: resolved. `MacroDialogs.cpp` remains the source-family placement; class-specific method children should route through `MacroDialog`, `SpellMacroDialog`, and `NewMacroDialog`.

## Score And Metadata Recommendation

Current parent metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:0000KY`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KY`
- Formal C++ blank.

Recommended parent metadata after accepted implementation:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000KY`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- Formal C++ blank.

Rationale:

- Completion should rise because the report resolves the score-limiting blockers named in the current page: constructor layout, command ids, row-control/storage names, source-placement route, and aggregate C++ disposition.
- Confidence should rise because the function boundaries, vtable refs, caller/callee routes, padding bytes, and storage offsets are IDA-backed and cross-checked against support docs.
- The parent becomes non-reconstructable not because the code is third-party/runtime/non-source, but because the parent is a split/container over reconstructable child method pages. Reconstructable emission should move to the children.
- Reason not higher: child-level C++ is now supplied as first-draft formal source, but exact original spelling for helper APIs, layout flag constants, and dialog support fields remains inferred rather than final-audit proven. The parent is a non-emitting container and should not cross the 95/95 code barrier.
- Reason not lower: the live MCP evidence and support docs are sufficient to make the split/container plan implementation-ready now.

Recommended support metadata after accepted implementation:

- [UID:00007I] `by-class/MacroDialog.md`: raise from `85/88` to approximately `88/90` if implementation incorporates constructor/save/storage details.
- [UID:0000DP] `by-class/SpellMacroDialog.md`: raise from `85/89` to approximately `88/91` if implementation incorporates spell-row/confirm/storage details.
- [UID:000094] `by-class/NewMacroDialog.md`: raise from `85/88` to approximately `89/91` if implementation incorporates page command ids, current-page field, compact storage, and no-direct-xref caveat.
- [UID:0000KY] `by-file/MacroDialogs.md`: raise from `88/85` to approximately `90/88` after child split summary and storage distinctions are incorporated.
- `RegistryConfigUserProfileBlock` and `MacroHotkeyRecord`: no required score change from this report; only cross-link/support edits if supervisor wants exact child links after UID assignment.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- No manual `-coverage-report.md` text is required from B010 for this report-only phase.
- Do not manually edit validator-owned `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++ files, or project-level generated reports.
- Expected tracker/coverage correction path: implement source by-* changes, run scoped validators, then supervisor executes the report through `tools/validator.py execute_report B010 0001DR-MacroDialogs-source-quality.md 0001DR --apply`.

## Implementation Callback Results

Supervisor accepted this report for implementation. B010 applied the split/container implementation in the by-* docs and updated this checklist only; the report was not executed or archived.

Changed by-* files:

- Parent/padding/file docs: `by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md`, `by-memory/-ignored.md`, `by-file/MacroDialogs.md`.
- New child pages: `by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md`, `by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md`, `by-memory/0x0053e8f0-0x0053e959.MacroDialogSaveMacros.md`, `by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md`, `by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md`, `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md`, `by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetVisible.md`, `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md`, `by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md`, `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md`, `by-memory/0x0053f170-0x0053f179.NewMacroDialogSetActiveControl.md`, `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md`, and `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md`.
- Support docs: `by-class/MacroDialog.md`, `by-class/SpellMacroDialog.md`, `by-class/NewMacroDialog.md`, `by-class/NewMacroEditControlPane.md`, `by-class/SpellMacroEditControlPane.md`, `by-type/by-vtable/MacroDialogFamilyVtables.md`, and `by-type/by-struct/RegistryConfigUserProfileBlock.md`.
- Report checklist: `tools/leaser/Agents/Agent-B010/research/0001DR-MacroDialogs-source-quality.md`.

Assigned child UIDs:

- `00049C` `0x0053e520-0x0053e8cf.MacroDialogConstructor`
- `00049D` `0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor`
- `00049E` `0x0053e8f0-0x0053e959.MacroDialogSaveMacros`
- `00049F` `0x0053e960-0x0053ecd0.SpellMacroDialogConstructor`
- `00049G` `0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor`
- `00049H` `0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm`
- `00049I` `0x0053ed80-0x0053ed89.SpellMacroDialogSetVisible`
- `00049J` `0x0053ed90-0x0053f07f.NewMacroDialogConstructor`
- `00049K` `0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor`
- `00049L` `0x0053f0a0-0x0053f166.NewMacroDialogOnCommand`
- `00049M` `0x0053f170-0x0053f179.NewMacroDialogSetActiveControl`
- `00049N` `0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries`
- `00049O` `0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage`

Scoped validators from `C:\FastStorage\NTK_Sources\source-3\project-documentation`:

- Child validators `000000004988` through `000000004999` and `000000005001`, timestamps `2026-06-28T03:48:36-04:00` through `2026-06-28T03:49:04-04:00`, exit `0`, each `ok: 1`.
- Parent/support validators `000000005002` through `000000005011`, timestamps `2026-06-28T03:49:06-04:00` through `2026-06-28T03:49:30-04:00`, exit `0`, each `ok: 1`. `by-memory/-ignored.md`, `by-class/SpellMacroDialog.md`, `by-class/NewMacroEditControlPane.md`, `by-type/by-vtable/MacroDialogFamilyVtables.md`, and `by-type/by-struct/RegistryConfigUserProfileBlock.md` reported pre-existing missing-ref warnings but still returned `ok: 1`.
- Generated-refresh wait validator `000000005013`, timestamp `2026-06-28T03:49:58-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.

Lease results:

- B010 acquired a short lease on the edited by-* file set at `2026-06-28T07:44:28Z`, expiring `2026-06-28T07:49:28Z`.
- The lease expired during validation/generated-refresh wait. B010 attempted release immediately after the batch; leaser returned `Rejected[No active lease]` for each file. `current_leases.md` then showed no active leases.
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` was not edited; existing storage references were sufficient. `by-project-structure` was not edited.

## Implementation Tracking Checklist

- [x] Acquire implementation leases only during the implementation callback, not during report-only research. Proof: B010 leased the 23 edited by-* files at `2026-06-28T07:44:28Z`; no report-only leases were used.
- [x] Create exact child page `by-memory/0x0053e520-0x0053e8cf.MacroDialogConstructor.md` with MacroDialog constructor evidence/proof from IDA `0x0053e520`, metadata `87/90`, owner/emitter UID00007I, and formal C++ block `CPP-1`. Proof: created as UID `00049C`; validator `000000004988` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053e8d0-0x0053e8ef.MacroDialogNonDeletingDestructor.md` with vtable-reset/base-teardown proof from IDA `0x0053e8d0`, metadata `86/90`, owner/emitter UID00007I, destructor compiler/source distinction, and formal C++ block `CPP-2`. Proof: created as UID `00049D`; validator `000000004989` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053e8f0-0x0053e959.MacroDialogSaveMacros.md` with command id `1`, control loop, and `m_profileTextSlots` proof from IDA `0x0053e8f0`, metadata `88/91`, owner/emitter UID00007I, and formal C++ block `CPP-3`. Proof: created as UID `00049E`; validator `000000004990` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053e960-0x0053ecd0.SpellMacroDialogConstructor.md` with spell row construction and `m_legacyShortcutText` proof from IDA `0x0053e960`, metadata `87/90`, owner/emitter UID0000DP, and formal C++ block `CPP-4`. Proof: created as UID `00049F`; validator `000000004991` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053ecd0-0x0053ecef.SpellMacroDialogNonDeletingDestructor.md` with vtable-reset/base-teardown proof from IDA `0x0053ecd0`, metadata `86/90`, owner/emitter UID0000DP, destructor compiler/source distinction, and formal C++ block `CPP-5`. Proof: created as UID `00049G`; validator `000000004992` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053ecf0-0x0053ed7a.SpellMacroDialogOnConfirm.md` with `GetSpellKey`, key write, terminator write, and dirty-save proof from IDA `0x0053ecf0`, metadata `88/91`, owner/emitter UID0000DP, and formal C++ block `CPP-6`. Proof: created as UID `00049H`; validator `000000004993` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053ed80-0x0053ed89.SpellMacroDialogSetVisible.md` with base visibility forwarder proof from IDA `0x0053ed80`, metadata `86/90`, owner/emitter UID0000DP, and formal C++ block `CPP-7`. Proof: created as UID `00049I`; validator `000000004994` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053ed90-0x0053f07f.NewMacroDialogConstructor.md` with compact-record, current-page, row-control, page-button, and no-direct-xref proof from IDA `0x0053ed90`, metadata `87/89`, owner/emitter UID000094, and formal C++ block `CPP-8`. Proof: created as UID `00049J`; validator `000000004995` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053f080-0x0053f09f.NewMacroDialogNonDeletingDestructor.md` with vtable-reset/base-teardown proof from IDA `0x0053f080`, metadata `86/89`, owner/emitter UID000094, destructor compiler/source distinction, and formal C++ block `CPP-9`. Proof: created as UID `00049K`; validator `000000004996` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053f0a0-0x0053f166.NewMacroDialogOnCommand.md` with command ids `1`, `12`, and `13` proof from IDA `0x0053f0a0`, metadata `89/91`, owner/emitter UID000094, and formal C++ block `CPP-10`. Proof: created as UID `00049L`; validator `000000004997` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053f170-0x0053f179.NewMacroDialogSetActiveControl.md` with base forwarder proof from IDA `0x0053f170`, metadata `86/90`, owner/emitter UID000094, and formal C++ block `CPP-11`. Proof: created as UID `00049M`; validator `000000004998` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053f180-0x0053f203.NewMacroDialogSaveMacroEntries.md` with compact-record write proof from IDA `0x0053f180`, metadata `88/91`, owner/emitter UID000094, and formal C++ block `CPP-12`. Proof: created as UID `00049N`; validator `000000004999` returned `ok: 1`.
- [x] Create exact child page `by-memory/0x0053f210-0x0053f2b6.NewMacroDialogLoadMacroPage.md` with compact-record read/page-load proof from IDA `0x0053f210`, metadata `88/91`, owner/emitter UID000094, and formal C++ block `CPP-13`. Proof: created as UID `00049O`; validator `000000005001` returned `ok: 1`.
- [x] Run validator `--apply` on each new child page to assign UIDs, then update all parent/support links with the assigned UIDs. Proof: child validators `000000004988`-`000000004999` and `000000005001` assigned UIDs `00049C`-`00049O`; parent/support validators `000000005002`-`000000005011` updated links.
- [x] Convert parent UID0001DR to a non-emitting split/container index with `RECONSTRUCTABLE: FALSE`, blank `EMITTER_UIDS`, and blank C++. Proof: `by-memory/0x0053e520-0x0053f2b6.MacroDialogs.md` metadata updated and validator `000000005002` returned `ok: 1`.
- [x] Add internal alignment padding spans to `by-memory/-ignored.md` and preserve existing external padding `0x0053f2b6-0x0053f2c0`. Proof: `by-memory/-ignored.md` updated with the eleven internal spans; validator `000000005003` returned `ok: 1`.
- [x] Update `by-file/MacroDialogs.md` with the exact split, direct storage dependencies, and NewMacroDialog xref caveat. Proof: `by-file/MacroDialogs.md` contains child table/storage/no-direct-xref notes; validator `000000005004` returned `ok: 1`.
- [x] Update `by-class/MacroDialog.md` with exact child links and resolved constructor/save evidence. Proof: class page links UIDs `00049C`-`00049E` and `m_profileTextSlots`; validator `000000005005` returned `ok: 1`.
- [x] Update `by-class/SpellMacroDialog.md` with exact child links and resolved spell shortcut evidence. Proof: class page links UIDs `00049F`-`00049I` and `m_legacyShortcutText`/`GetSpellKey`; validator `000000005006` returned `ok: 1`.
- [x] Update `by-class/NewMacroDialog.md` with exact child links, compact-record dependency, command ids, current-page field, and no-direct-constructor-xref caveat. Proof: class page links UIDs `00049J`-`00049O`, `m_compactShortcutRecords`, commands `1/12/13`, `+0x26c`, and caveat; validator `000000005007` returned `ok: 1`.
- [x] Update or verify `by-class/NewMacroEditControlPane.md` support note for compact-record getters/setters. Proof: support page links UIDs `00049N`/`00049O` and maps accepted getter/setter names to existing row-control roles; validator `000000005008` returned `ok: 1`.
- [x] Update or verify `by-class/SpellMacroEditControlPane.md` support note for `GetSpellKey` storage. Proof: support page links UID `00049H` and `m_legacyShortcutText`; validator `000000005009` returned `ok: 1`.
- [x] Verify `RegistryConfigUserProfileBlock`, `g_pConfig`, vtable, and proposed-source-tree support docs need no unsupported source-placement changes. Proof: `RegistryConfigUserProfileBlock` and `MacroDialogFamilyVtables` were updated/validated by `000000005011` and `000000005010`; `g_pConfig` and `by-project-structure` required no edits because existing storage/source-placement detail was sufficient.
- [x] Run scoped file validators from `source-3/project-documentation` for all edited files and record command/output proof in the implementation callback. Proof: 23 scoped validators plus generated wait validator are recorded in `Implementation Callback Results`, all exit `0` with `ok: 1`.
- [x] Release all implementation leases immediately after the edit/validator batch. Proof: release attempt found no active B010 leases because the short lease expired during validation; `current_leases.md` showed no active leases afterward.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0001DR-MacroDialogs-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0001DR-MacroDialogs-source-quality.md","timestamp":"2026-06-28T04:00:07","uid":"0001DR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
