# Agent A001 Notes

## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

Keep this file concise. Current metadata terminology: `CANONICAL_OWNER` is semantic ownership, `EMITTER_UIDS` is output routing, and final C++ requires `RECONSTRUCTABLE:TRUE`, confirmed nonblank emitters without a dead end, and `(COMPLETION + CONFIDENCE) / 2 > 85` with source-quality evidence.

## 2026-06-16 A001 Report - A001-goal2-menuvariety-socket-rdata-refresh-0001NQ-00026G-20260616-74

- Changed target docs: `by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md` and `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`.
- Generated/tool-owned changes from scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`. `auto-generated/-ag-memory-coverage.md` was reported as `autogen_report_noop`/unchanged. A001 did not edit or lease `by-memory/-coverage-report.md`.
- Score changes: [UID:0001NQ] `MenuVarietySelectPaneHitTest` `82/86 -> 86/90`; [UID:00026G] `SocketReadOnlyData` `82/86 -> 86/90`. Both UIDs were removed from `project-level/-auto-completion-stats.md`.
- Owner/emitter decisions: unchanged. [UID:0001NQ] remains `CANONICAL_OWNER:0000L8`, `EMITTER_UIDS:0000L8`, routed to [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md); [UID:00026G] remains `CANONICAL_OWNER:0000NS`, `EMITTER_UIDS:0000NS`, routed to [UID:0000NS][Socket](by-file/Socket.md). Neither target received final C++.
- Leases used/status: A001 acquired and refreshed leases for both target docs and `tools/leaser/Agents/Agent-A001/notes.md` before edits. Final cleanup attempted `unlease`, but the target leases had already expired and the tool returned `Rejected[No active lease]`; a short notes-only lease was taken to record this status and released afterward. No lease was taken for `by-memory/-coverage-report.md`.
- [UID:0001NQ] evidence checked/resolved: live read-only IDA MCP database `701e9f0c` confirmed `sub_5BD9B0` size `0x8b`, no function at `0x005bda3b`, successor `sub_5BDA40` at `0x005bda40`, `0x005bda3b-0x005bda40` five `0xcc` bytes, and exact xrefs only at `0x005bd089`/`0x005bd338` inside `sub_5BD000` / `MenuVarietySelectPane::HandleMenuMouseEvent`. Decompilation/disassembly confirm the ten-row loop, `retn 8`, return byte semantics, and click/hover caller uses. `sub_4B7C50` and `sub_4B7E80` were decompiled to resolve the old inclusivity caveat: stored rectangle bounds are lower-inclusive and upper-exclusive. `xrefs_to 0x005bd960` remains empty and `0x005bd9ad-0x005bd9b0` is padding, so the adjacent raw row-rectangle helper stays a separate child and no range split/merge is needed.
- [UID:0001NQ] remaining blockers after investigation: original helper name, final point-parameter names, and source emission form remain unrecovered. `auto-generated/NexusTK/ui/menu/MenuVarietyPanes.cpp` is zero bytes and generated memory coverage reports code `no`, so the final C++ block stays blank despite numeric eligibility. No IDA comment/rename was applied.
- [UID:00026G] evidence checked/resolved: live IDA MCP confirmed no function objects at `0x00624f20` or `0x00625008`, `??_7Socket@@6B@` at `0x00624f20`, vtable base refs at `0x0057483f`, `0x00574a11`, and `0x005795d8`, and the full slot map through `0x00624f54`: Socket scalar destructor, inherited/common `LObject`/Thread/no-op slots, `Socket::PollAndReceive`, `Socket::HandleSocketCommand`, transport-state query, and receive-event dispatch. Literal byte/xref checks covered constructor seed `0x00624f58`, full wide `KRUCONN` start `0x00624f78`, delimiter/format strings at `0x00624f88`, `%c%c%c%c` at `0x00624f90`, wide `COM%d` at `0x00624f9c`, `CONNADDR` and parser delimiter pointer refs through [UID:000287], packet/frame error string at `0x00624fc8`, and successor table ref at `0x00625008`.
- [UID:00026G] label/split/source-quality decisions: `??_7Socket@@6B@` is compiler-generated binary ownership evidence, not raw source data. IDA literal labels are generated; `aUconn` is specifically partial because the xref and bytes show the wider string begins at `0x00624f78`, so it was not promoted as a source name. No split, merge, ignored row, or IDA DB edit is justified in this pass: the range is a clean Socket-owned `.rdata` island between [UID:00026F] and [UID:00026H], while vtable bytes should regenerate from class declarations and literals remain Socket source data. `auto-generated/NexusTK/network/Socket.cpp` is zero bytes/code `no`, so final C++ stays blank pending final literal names, inherited virtual order, field names, and declaration/linkage form.
- IDA DB changes: none. The pass used read-only lookup, decompile, disassembly, xrefs, bytes, signatures, global-list, generated-output, and support-doc evidence only.
- Validation commands/results: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-memory\0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md --apply --queue-timeout 240 --lock-timeout -1` and `python .\tools\validator.py --mode file --file by-memory\0x00624f20-0x00625008.SocketReadOnlyData.md --apply --queue-timeout 240 --lock-timeout -1`; both exited `0` with `ok:1`. The first run reported completion/confidence updates, one UID-link insert, one reference-index add, and stats-row removals for [UID:0001NQ]. The second run reported completion/confidence updates, one UID-link insert, three UID-link updates, and stats-row removals for [UID:00026G]. Both rebuilt validator metadata and reported `autogen_report_noop` for memory coverage.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: replace the existing [UID:0001NQ] row in the MenuVariety/UserStatus cluster after [UID:0001NP] `MenuVarietyPanes` and before [UID:0001NR] `OldUserStatusPane`; replace the existing [UID:00026G] row in the Socket `.rdata` cluster after [UID:00026F] `SimpleServerSelectReadOnlyData` and before [UID:00026H] `ServerPacketNameTable`.

```markdown
    - [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md) 0x005bd9b0-0x005bda3b | method | MenuVarietySelectPaneHitTest : reconstructable : 86% : very strong : A001 2026-06-16 live source-quality pass confirms exact `sub_5BD9B0` `0x8b` range, no function at `0x005bda3b`, `0x005bda3b-0x005bda40` five-byte `0xcc` padding before `OldUserStatusPane`, only two `HandleMenuMouseEvent` callers at `0x005bd089`/`0x005bd338`, ten-row loop and return-byte semantics, lower-inclusive/upper-exclusive row bounds through `sub_4B7C50`/`sub_4B7E80`, adjacent raw row-rectangle helper still no-xref/padding-separated, MenuVarietyPanes owner/emitter route, zero-byte generated `MenuVarietyPanes.cpp`, no IDA DB edits, no split/merge needed, and blank final C++ pending original helper/argument names and source emission form.
    - [UID:00026G][0x00624f20-0x00625008.SocketReadOnlyData](by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md) 0x00624f20-0x00625008 | vtable/string-data | SocketReadOnlyData : reconstructable : 86% : very strong : A001 2026-06-16 live source-quality pass confirms clean `.rdata` bounds between [UID:00026F] and [UID:00026H], Socket vtable base refs from constructor/destructor/scalar destructor, full slot map through `0x00624f54` separating Socket virtuals from inherited Thread/common no-op slots, constructor/protocol/serial/parser/error literal xrefs, `CONNADDR` and delimiter pointer refs through [UID:000287], partial generated `aUconn` label rejected as source name, no split/ignored row required, Socket owner/emitter route, zero-byte generated `Socket.cpp`, no IDA DB edits, and blank final C++ pending final literal names, inherited virtual order, field names, and declaration/linkage form.
```

## 2026-06-16 A001 Report - A001-goal2-quitprompt-groupmarkers-source-quality-0001KP-0001KR-20260616-73

- Changed target docs: `by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md` and `by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md`.
- Changed generated/tool-owned state from scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`. Validator reported `autogen_report_noop: 7`; the workspace already shows dirty `auto-generated/-ag-memory-coverage.md` and `by-memory/-coverage-report.md`, but A001 did not edit either file and did not lease the shared coverage report.
- Score changes: [UID:0001KP] `QuitPromptLauncher` `82/86 -> 86/90`; [UID:0001KR] `GroupMemberMarkers` `82/86 -> 86/90`. Both UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Owner/emitter decisions: unchanged. [UID:0001KP] remains `CANONICAL_OWNER:0000TD`, `EMITTER_UIDS:0000TD`, routing through [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) to [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md). [UID:0001KR] remains `CANONICAL_OWNER:0000JS`, `EMITTER_UIDS:0000JS`, owned by [UID:0000JS][Group](by-file/Group.md); [UID:0000M7][OptionPane](by-file/OptionPane.md) is only the caller/toggle owner and [UID:0000L3][MapPane](by-file/MapPane.md) owns downstream map side effects.
- Leases used: A001 acquired and refreshed leases for both target docs and `tools/leaser/Agents/Agent-A001/notes.md` before edits. No lease was taken for `by-memory/-coverage-report.md`.
- [UID:0001KP] evidence checked/resolved: live IDA MCP database `701e9f0c` reports `sub_5A94B0` size `0x122`, no function at `0x005a95d2`, successor `sub_5A95E0` at `0x005a95e0`, and `0x005a95d2-0x005a95e0` as fourteen `0xcc` bytes. `xrefs_to 0x005a94b0` reports only the 5-byte thunk/reference at `0x005a5a80` and real caller `0x005a5cc8` inside `sub_5A5BD0`. Decompilation of [UID:0003V9][UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md) shows case `0x51` calling `sub_5A94B0()` at `0x005a5cc2` and returning handled. Decompilation of the launcher confirms the [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / `byte_66DA97` branch, `0x270` modal `QuitDialog` setup, `0x108` typed `QuitInputPane` setup, localized id `3`, vtable stores, and [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) read/store/clear refs at `0x005a954d`, `0x005a9597`, and `0x005a959e`.
- [UID:0001KP] remaining blockers after investigation: original source spellings for the launcher and broad mode global, final class/helper declarations, and raw `QuitInputPane` constructor source shape remain unresolved. No split/merge/range repair is justified, final C++ remains blank despite numeric eligibility, and no IDA comment/rename was applied because it would duplicate docs or overstate original symbols.
- [UID:0001KR] evidence checked/resolved: live IDA MCP reports `sub_5ADC20` and `sub_5ADC70`, both size `0x43`, with no function at `0x005adc63`/`0x005adcb3`; `0x005adc63-0x005adc70` and bytes after `0x005adcb3` are `0xcc` padding. Decompiles confirm both helpers take `dword_67A748` as `this`, test signed count `this+0x3cb0 > 0`, return without MapPane calls for empty/non-positive counts, walk member ids at `this+0x218 + index * 0x12c`, re-read count each loop, and call `sub_50E4C0(dword_67A764, memberId)` or `sub_50E810(dword_67A764, memberId)`. `xrefs_to` reports exactly one caller to each helper from [UID:0001DW][NewOptionPane::OnMouseClick](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md), and decompilation of `0x00540910` shows option case `25` toggling the group-marker config flag, then calling refresh on true and clear on false. Downstream [UID:0003TB][MapPaneProcessMapEvent](by-memory/0x0050e4c0-0x0050e68d.MapPaneProcessMapEvent.md), [UID:0003TD][MapPaneActivateLinkedObjectById](by-memory/0x0050e810-0x0050e848.MapPaneActivateLinkedObjectById.md), [UID:0001OR][g_pCollectionData storage](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md), and [UID:0001OW][ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) docs were checked for owner/source routing.
- [UID:0001KR] remaining blockers after investigation: original helper names, final player-state/group-entry type, member id field name, group option flag name, and final MapPane method declarations remain role-based. No split/merge/range repair is justified beyond documenting the padding, final C++ remains blank despite numeric eligibility, and no IDA comment/rename was applied.
- Validation commands/results: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-memory\0x005a94b0-0x005a95d2.QuitPromptLauncher.md --apply --queue-timeout 240 --lock-timeout -1` and `python .\tools\validator.py --mode file --file by-memory\0x005adc20-0x005adcb3.GroupMemberMarkers.md --apply --queue-timeout 240 --lock-timeout -1`; the combined run exited `0`. The [UID:0001KP] validation reported `completion_update ... 86`, `confidence_update ... 90`, reference-index refresh, and `stats_row_remove` from `Low_Completion`, `Low_Both`, and `by-memory`; the [UID:0001KR] validation similarly completed with `ok:1` and removed the UID from refreshed stats. A filtered verification rerun for both commands exited `0` with `ok: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, and `autogen_report_noop: 7`.
- IDA DB changes: none. The pass used read-only lookup, decompile, xref, callee, byte, signature, and local documentation/source searches only.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: replace the existing [UID:0001KP] row in the UserPane/QuitDialogs neighborhood after [UID:0002RX] `OpenInputPaneForCurrentSayMode` and before [UID:0001KQ] `SelfSaveInputPaneFactory`; replace the existing [UID:0001KR] row after [UID:0001KQ] and before [UID:0001KS] `QuitInputPaneCore`.

```markdown
    - [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) 0x005a94b0-0x005a95d2 | function | QuitPromptLauncher : reconstructable : 86% : very strong : A001 2026-06-16 live source-quality pass confirms exact `sub_5A94B0` `0x122` range, no function at `0x005a95d2`, `0x005a95d2-0x005a95e0` fourteen-byte `0xcc` padding, only real caller case `0x51` in [UID:0003V9][UserPaneHandleKeyEvent](by-memory/0x005a5bd0-0x005a7422.UserPaneHandleKeyEvent.md) plus the 5-byte thunk/reference at `0x005a5a80`, [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) branch, `0x270` modal QuitDialog setup, `0x108` typed QuitInputPane setup, localized id `3`, `g_pQuitInputPane` read/store/clear refs, QuitDialogs owner/emitter route through [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md), no IDA DB edits, no split/merge needed, and blank final C++ pending original source spellings, class/helper declarations, and raw QuitInputPane constructor source shape.
    - [UID:0001KR][0x005adc20-0x005adcb3.GroupMemberMarkers](by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md) 0x005adc20-0x005adcb3 | helper pair | GroupMemberMarkers : reconstructable : 86% : very strong : A001 2026-06-16 live source-quality pass confirms two `0x43` modeled helpers at `0x005adc20` and `0x005adc70`, no functions at `0x005adc63`/`0x005adcb3`, `0x005adc63-0x005adc70` thirteen-byte `0xcc` padding, sole option-toggle callers at `0x00540c04`/`0x00540c0b` in [UID:0001DW][NewOptionPane::OnMouseClick](by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md), `dword_67A748` state argument, signed count `+0x3cb0`, member ids `+0x218 + index * 0x12c`, empty/non-positive no-op handling, downstream `sub_50E4C0`/`sub_50E810` calls through [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), Group owner/emitter [UID:0000JS][Group](by-file/Group.md), no IDA DB edits, no split/merge needed, and blank final C++ pending original helper names, final player-state/group-entry fields, group option flag name, and MapPane method declarations.
```

## 2026-06-16 A001 Report - A001-goal2-connectionclosed-constructor-source-quality-20260616

- Changed target doc: `by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md`.
- Changed support docs: `by-class/ConnectionClosedDialog.md` and `by-file/ReconnectDialog.md` only, to repair the constructor's direct class route and source-root wording.
- Changed generated/tool-owned state: scoped validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and `tools/validator.ini`. `by-memory/-coverage-report.md` was not edited by A001; it already had unrelated dirty worktree changes, and the final check shows the [UID:00023O] row now present there at `87%`.
- Score changes: [UID:00023O] `ConnectionClosedDialogConstructorVariant` `82/86 -> 87/89`. Support [UID:000036] `ConnectionClosedDialog` stayed `86/88`; [UID:0000N0] `ReconnectDialog` stayed `87/88`.
- Owner/emitter decision: [UID:00023O] was repaired from direct file owner/emitter [UID:0000N0] to direct class owner/emitter [UID:000036] at `EMITTER_POSITION_OPTIONAL:10`. Source placement still routes through [UID:000036] to [UID:0000N0] `auto-generated/NexusTK/network/ReconnectDialog.cpp`; no final C++ was emitted because that generated source remains blank and source-quality blockers remain.
- Leases used: fresh A001 leases were acquired for the target, [UID:000036], [UID:0000N0], and this notes file. No lease was taken for `by-memory/-coverage-report.md`.
- Caller/reachability evidence: live IDA MCP session `a001_goal2_00023O` confirms `0x00508ffc` is the only code xref to `0x00553c10`, inside `sub_508F60` / [UID:0000YW] MapPane notify-timer core. Decompile shows the runtime guard `Block[4] == 22`, `g_pUrlAlertPane` null test, allocation size `0x270`, and constructor call; this proves reachability but not MapPane ownership.
- Alternate constructor/split evidence: `lookup_funcs` confirms `sub_553C10` size `0xaf`, no function at `0x00553cbf`, and successor `sub_553CC0` size `0xae`. Xrefs to `0x00553cc0` at `0x004f6acb`, `0x005543e3`, and `0x005544a2` support the separate alternate constructor/method cluster [UID:00038J]. No split, merge, range extension, or rename is justified for [UID:00023O].
- Singleton/global and vtable evidence: xrefs to `0x0067ab54` show the `g_pConnectionClosedDialog` lifecycle across this constructor, the alternate constructor, replacement path, timeout/read path, clear helper, and destructor clear. Vtable stores to `0x00622d34`, `0x00622d9c`, and `0x00622dcc` occur in this constructor, the alternate constructor, and replacement constructor path, so the data remains under [UID:0003CT] and not owned by this method.
- Names/types/helper evidence: IDA string/name searches found only RTTI/vtable names for `ConnectionClosedDialog`, `ReconnectDialog`, and their singleton templates, with no `ReconnectDialog.cpp`, source method names, singleton global symbol, helper-name strings, or recovered local UDT. `type_query` found only the stale/incomplete `_anonymous_namespace_::dbg_eng_data` type; the stale `dbg_eng_data::source_line` name on `0x00553e60` was rejected as misapplied evidence. Full-range byte signature for [UID:00023O] is unique; VA/RVA raw pointer searches for `0x00553c10` and `0x00553cc0` found no table refs.
- Final-C++ blockers after investigation: constructor signature/overload spelling, class/header shape, base/alert initializer wrapper names, role member names, singleton declaration/linkage form, source form for helper `0x00553e60`, and blank generated `ReconnectDialog.cpp` are still unresolved. Numeric final-code eligibility is therefore intentionally not used to emit C++.
- IDA DB changes: none. The pass used read-only lookup, xref, callee, decompile, signature, string/name/type, and byte-search evidence only; no renames, comments, type changes, function creation, patches, or IDB saves were made. A low-risk comment on `sub_553C10` would be possible later, but no DB-only change was applied without final signature/source-name confidence.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-memory\0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ConnectionClosedDialog.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-file\ReconnectDialog.md --apply --queue-timeout 240`; each exited `0` with `ok: 1`. The target validation reported completion/confidence updates, canonical owner/emitter update `0000N0 -> 000036`, position update to `10`, reference-index refresh, and removal of [UID:00023O] from `Low_Completion`, `Low_Both`, and by-memory stats. A filtered rerun for all three files also exited `0` with `ok: 1`, and `rg` found no [UID:00023O] row in `project-level/-auto-completion-stats.md`.
- Supervisor-owned `by-memory/-coverage-report.md` row text: replace the existing [UID:00023O] row under [UID:0001FT], after [UID:0001FT] `0x00553c10-0x00554635.ConnectionClosedReconnectDialogs` and before [UID:00038J] `0x00553cc0-0x00553e5b.ConnectionClosedDialogMethods` if present. Final check shows this row already present in the shared report; no additional A001 coverage row remains pending if that shared change is retained.

```markdown
        - [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md) 0x00553c10-0x00553cbf | constructor | ConnectionClosedDialogConstructorVariant : reconstructable : 87% : strong : ConnectionClosedDialog no-parent/default constructor variant; A001 2026-06-16 live IDA confirms exact `0xaf` modeled range, no function at `0x00553cbf`, `0x00553cc0` alternate-constructor successor, unique full-range signature, single MapPane caller at `0x00508ffc`, `0x270` allocation/`Block[4] == 22`/`g_pUrlAlertPane` guard in `sub_508F60`, `g_pConnectionClosedDialog` publication, localized text id `154`, shared `Leave`/`Reconnect` initializer labels, three exact ConnectionClosedDialog vtable stores, post-construction helper call, RTTI/vtable-name-only evidence, no raw constructor-start pointer hits, repaired class owner/emitter [UID:000036][ConnectionClosedDialog](by-class/ConnectionClosedDialog.md), no IDA DB edits, and blank final C++ pending constructor signature, class/header/member names, singleton declaration linkage, and `0x00553e60` helper source form.
```

## 2026-06-16 Supervisor Correction - MemoryMan Stop

- Supervisor correction received during resumed A001 work: [UID:0001BA] `MemoryManAndAllocationHelpers` is B001-only heavy report work. A001 released the stale interrupted lease and did not continue, validate, or edit MemoryMan after the correction.
- The pre-existing dirty MemoryMan by-memory file and the stale A001 MemoryMan report section below are not part of the active A001 assignment. Do not apply the stale MemoryMan pending coverage row from this notes file as A001 current work unless the supervisor separately reconciles that interrupted state.

## 2026-06-16 A001 Report - A001-goal2-lowcompletion-simplelistpane-entry-helpers-20260616-70

- Changed target docs: `by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md`, `by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md`, `by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md`, and `by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md`.
- Changed support docs: `by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md` wording was refreshed for the active source-quality/final-C++ gate. `by-class/SimpleListPane.md` and `by-file/SimpleListPane.md` were leased and validated as support; they already carried the current SimpleListPane source-quality refresh from the prior class/file pass.
- Changed generated/tool-owned state: scoped validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and `tools/validator.ini`. `by-memory/-coverage-report.md` was not edited.
- Score changes: [UID:0002LF] `SimpleListPaneAppendCopiedText` `82/86 -> 86/88`; [UID:0002LG] `SimpleListPaneInsertCopiedText` `82/86 -> 86/88`; [UID:0002LH] `SimpleListPaneRemoveCopiedText` `82/86 -> 86/88`; [UID:0002LI] `SimpleListPaneReplaceCopiedText` `82/86 -> 86/88`. Support [UID:000241] stayed `85/89`; [UID:0000D8] stayed `87/87`; [UID:0000NQ] stayed `87/86`.
- Owner/emitter decisions: unchanged. All four target helpers remain `CANONICAL_OWNER:000241`, `EMITTER_UIDS:000241`, routed through [UID:000241] -> [UID:0000D8] `SimpleListPane` -> [UID:0000NQ] `SimpleListPane` file root in `NexusTK/ui/controls/`. [UID:000241] remains owner/emitter [UID:0000D8]. No final C++ was added.
- Leases used: A001 released an interrupted stale lease on B001-only [UID:0001BA] before resuming and made no further MemoryMan changes. Fresh A001 leases were acquired only for the four target pages, [UID:000241], [UID:0000D8], [UID:0000NQ], and this notes file; the first lease set expired during validation/checks and was reacquired for the same approved files before notes.
- Source-quality evidence checked: live IDA MCP evidence from session `a002_goal65_20260616` reconfirmed all four helper starts and ends are not modeled functions, the exact raw instruction ranges are unique, and VA/RVA little-endian start-pointer searches plus `xrefs_to` find no direct raw-start reachability. Outgoing ListPane edges were verified: append uses `sub_4F3BD0` then `sub_4F3C00`, insert uses caller index plus `sub_4F3C00`, remove uses `sub_4F3DC0` plus `sub_4F3D60`, and replace uses `sub_4F3DC0`, `sub_4F3D60`, and `sub_4F3C00`.
- Source-authored/helper status: the helpers are documented as source-authored raw method-shaped code because they contain meaningful copied UTF-16 allocation/free/list mutation logic, not compiler thunks or padding. Exact source-level method names remain role names because IDA string searches found no `SimpleListPane.cpp`, `ListPane.cpp`, or helper-name strings.
- Generated-output and owner-pollution checks: `auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` and `auto-generated/NexusTK/ui/controls/ListPane.cpp` are still zero bytes. Local Wave/simroot searches found only disabled/missing-code synthetic placements: append/insert under `ArticleListPane::meth_0x...` and remove/replace under `ChattingColorListPane::meth_0x...`. Those are treated as generated owner pollution, not source-quality owners or names.
- Remaining blockers after investigation: no direct callers or pointer-table refs to raw starts; final source method names are unrecovered; copied-entry field/member names remain role-based; source-file shape is still best routed through `SimpleListPane` but not final-audit proof against a compact `ListPane.cpp` fold; final C++ is eligible numerically but intentionally blank because emitting source would overstate reachability and naming.
- IDA DB changes: none. The pass used read-only IDA evidence already recorded for lookup/disassembly/xref/signature/string checks; no renames, comments, types, function creation, patches, or IDB saves were made.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` serially for all four target pages plus [UID:000241], [UID:0000D8], and [UID:0000NQ]. The loop exited `0`; validator reported `ok: 1` for each file, updated target completion/confidence rows, and removed the four target UIDs from `project-level/-auto-completion-stats.md`. Follow-up `rg` for `0002LF|0002LG|0002LH|0002LI` in `project-level/-auto-completion-stats.md` returned no matches.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows follow.

Placement context: replace the existing [UID:000241] row at the SimpleListPane memory cluster, after [UID:0000VN] padding `0x005739f6-0x00573a00` and before child [UID:0002LE].

```markdown
    - [UID:000241][0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers](by-memory/0x00573a00-0x00573c38.SimpleListPaneDestructorAndEntryHelpers.md) 0x00573a00-0x00573c38 | methods/helpers | SimpleListPaneDestructorAndEntryHelpers : reconstructable : 85% : strong : Aggregate over exact cleanup, append, insert, remove, and replace copied-text helper children; A001 2026-06-16 active-gate refresh keeps owner/emitter through [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md), confirms current modeled cleanup body, raw helper starts, internal padding, zero-byte generated output, and final-C++ blockers for raw reachability, source names, and role-based copied-entry fields.
```

Placement context: replace the existing [UID:0002LF] row under [UID:000241], after padding `0x00573a98-0x00573aa0` and before padding `0x00573b08-0x00573b10`.

```markdown
      - [UID:0002LF][0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText](by-memory/0x00573aa0-0x00573b08.SimpleListPaneAppendCopiedText.md) 0x00573aa0-0x00573b08 | raw helper | SimpleListPaneAppendCopiedText : reconstructable : 86% : strong : Raw SimpleListPane append helper; A001 2026-06-16 live IDA confirms non-function status, exact full-range body/signature, no raw-start xrefs or VA/RVA pointer hits, UTF-16 copy allocation through `sub_516030`/`sub_516050`, `_wcscpy_s`, append index from `ListPane::GetItemCount`, insertion through `ListPane::InsertItem`, generated-output omission, and unresolved source-name/reachability/field-name blockers.
```

Placement context: replace the existing [UID:0002LG] row under [UID:000241], after padding `0x00573b08-0x00573b10` and before padding `0x00573b6d-0x00573b70`.

```markdown
      - [UID:0002LG][0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText](by-memory/0x00573b10-0x00573b6d.SimpleListPaneInsertCopiedText.md) 0x00573b10-0x00573b6d | raw helper | SimpleListPaneInsertCopiedText : reconstructable : 86% : strong : Raw SimpleListPane insert helper; A001 2026-06-16 live IDA confirms non-function status, exact full-range body/signature, no raw-start xrefs or VA/RVA pointer hits, caller-supplied index and UTF-16 source arguments, allocation/init/copy through `sub_516030`/`sub_516050`/`_wcscpy_s`, insertion through `ListPane::InsertItem`, generated-output omission, and unresolved source-name/reachability/field-name blockers.
```

Placement context: replace the existing [UID:0002LH] row under [UID:000241], after padding `0x00573b6d-0x00573b70` and before padding `0x00573bac-0x00573bb0`.

```markdown
      - [UID:0002LH][0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText](by-memory/0x00573b70-0x00573bac.SimpleListPaneRemoveCopiedText.md) 0x00573b70-0x00573bac | raw helper | SimpleListPaneRemoveCopiedText : reconstructable : 86% : strong : Raw SimpleListPane remove helper; A001 2026-06-16 live IDA confirms non-function status, exact full-range body/signature, no raw-start xrefs or VA/RVA pointer hits, slot lookup through `ListPane` entry-slot helper, copied-buffer free/clear through `sub_516030`/`sub_516170`, single-item removal through `ListPane::RemoveItems`, generated-output omission, and unresolved source-name/reachability/field-name blockers.
```

Placement context: replace the existing [UID:0002LI] row under [UID:000241], after padding `0x00573bac-0x00573bb0` and before [UID:0001HQ] `0x00573c38-0x00573d15.SimpleListPaneDestructorThunks`.

```markdown
      - [UID:0002LI][0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText](by-memory/0x00573bb0-0x00573c38.SimpleListPaneReplaceCopiedText.md) 0x00573bb0-0x00573c38 | raw helper | SimpleListPaneReplaceCopiedText : reconstructable : 86% : strong : Raw SimpleListPane replace helper; A001 2026-06-16 live IDA confirms non-function status, exact full-range body/signature ending before the destructor thunk, no raw-start xrefs or VA/RVA pointer hits, existing slot free/clear, single-item removal, replacement UTF-16 allocation/copy, reinsertion through `ListPane::InsertItem`, generated-output omission, and unresolved source-name/reachability/field-name blockers.
```

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-lowcompletion-simplelistpane-entry-helpers-20260616-70` after reviewing the target/support docs and verifying the raw reachability/source-quality blockers were investigated. The exact [UID:000241], [UID:0002LF], [UID:0002LG], [UID:0002LH], and [UID:0002LI] `by-memory/-coverage-report.md` rows were applied, and scoped validators for all four targets, [UID:000241], [UID:0000D8], [UID:0000NQ], and the shared report exited `0` with `ok:1`. No A001 supervisor-owned memory coverage rows remain pending for this batch. The interrupted [UID:0001BA] MemoryMan edit remains unaccepted A001 work pending B001 review.

## 2026-06-16 A001 Report - A001-goal2-memoryman-source-quality-20260616

- Changed target doc: `by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md`.
- Changed generated/tool-owned state: scoped validator `--apply` refreshed `project-level/-auto-completion-stats.md`; autogen registry rebuilt and `auto-generated/-ag-*` reports were no-op for this target. `by-memory/-coverage-report.md` was not edited.
- Score change: [UID:0001BA] `MemoryManAndAllocationHelpers` `82/86 -> 86/88`.
- Owner/emitter decisions: unchanged. [UID:0001BA] remains `CANONICAL_OWNER:0000L7`, `EMITTER_UIDS:0000L7`, routed to [UID:0000L7] `MemoryMan` and `auto-generated/NexusTK/util/MemoryMan.cpp`. The scalar deleting destructor child [UID:0001BJ] remains class-owned by [UID:00007U] while the aggregate stays file-owned as the MemoryMan source-family island.
- Leases used: released stale A001 SimpleListPane leases left from a prior pass; acquired fresh leases for the target and this notes file before editing. The target/notes lease pair was refreshed once before patching because the earlier notes lease had expired.
- Evidence and blocker investigations:
  - MemoryMan/helper/API split: live IDA MCP session `a002_goal65_20260616` reconfirmed exact helper starts/sizes, the unrelated `0x00516290` MenuPane successor, full-range unique signature, and child ownership split. The contiguous island stays a MemoryMan source-family aggregate; no split/merge/rename is justified.
  - Global operators: [UID:000196] `operator new` and [UID:000197] `operator delete` were checked as non-contiguous support pages. IDA callees show only `GetMemoryMan` plus allocate/free helper calls; keep them routed to MemoryMan, but final declarations/source placement remain unresolved.
  - Static lifetime and globals: xrefs show exactly two refs to `0x0069b3a8`, four refs to `0x0069b4fc`, and three refs to `0x0061eb08`; this supports `g_pMemoryMan`, static object storage, constructor/reset/accessor/destructor lifecycle, and no feature-owner reassignment.
  - Raw starts/compiler artifacts: `0x00516040-0x00516045` bytes are `33 c0 c2 04 00`, with no IDA function object, zero xrefs, and a non-unique signature, so no child page was created. Static initializer [UID:0000WA] and atexit thunk [UID:0001O7] remain non-reconstructable compiler/static-lifetime glue; reset tail [UID:0001BB] is documented as a tail chunk, not an ordinary method.
  - Names/types/source placement: `find_regex` found only RTTI string `.?AVMemoryMan@@`; no `MemoryMan.cpp`, helper-name, global-operator, or allocator helper source strings were recovered. `search_structs` and `type_query` found no local MemoryMan UDT/type. Current helper names remain role names except the resolved `g_pMemoryMan`.
  - Final C++: no C++ was emitted. The route is valid but `auto-generated/NexusTK/util/MemoryMan.cpp` is still zero bytes, and the aggregate should not duplicate child bodies before final helper declarations, global operator declarations, static object declaration form, copy-wrapper placement, and scalar-deleting destructor/source-destructor representation are source-quality.
- IDA DB changes: none. All IDA work was read-only lookup/xref/callee/byte/signature/string/type evidence.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md --apply --queue-timeout 240` exited `0` with `ok: 1`; the first run reported completion/confidence updates and removed [UID:0001BA] from `Low_Completion`, `Low_Both`, and by-memory stats rows. A second focused rerun after wording cleanup also exited `0` with `ok: 1`. `rg "0001BA|MemoryManAndAllocationHelpers|0x00516000-0x0051628e" project-level/-auto-completion-stats.md` returns no matches.
- Pending supervisor-owned `by-memory/-coverage-report.md` row: replace the stale [UID:0001BA] row below; no other shared coverage rows are pending for this batch.

Placement context for [UID:0001BA]: replace the existing row after [UID:0000VN] `0x00515ff2-0x00516000` MD5-to-MemoryMan padding and before child [UID:0001B9] `MemoryManConstructor`.

```markdown
    - [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) 0x00516000-0x0051628e | source-family/helper island | MemoryManAndAllocationHelpers : reconstructable : 86% : strong : Compact MemoryMan singleton/allocation helper island; A001 2026-06-16 live IDA confirms exact child starts and `0x00516290` successor, unique full-range signature, singleton/static-object/vtable refs, broad helper reachability, global operator call edges, allocation/copy/delete callee sets, no-xref non-unique raw `0x00516040` return-zero stub, source-string/type search limits, unchanged [UID:0000L7] MemoryMan owner/emitter route, and blank final C++ pending final helper/API spellings, global-operator declarations, static-object declaration form, copy-wrapper source placement, and scalar-deleting destructor source representation.
```

## 2026-06-16 A001 Report - A001-goal2-lowcompletion-idle-patchpane-source-quality-20260616-69

- Changed target docs: `by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md` and `by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md`.
- Changed generated/tool-owned state: scoped validator `--apply` refreshed `project-level/-auto-completion-stats.md` and `auto-generated/-ag-memory-coverage.md`; `by-memory/-coverage-report.md` was not edited.
- Score changes: [UID:000142] `ApplicationIdleWorkScheduler` `82/86 -> 86/88`; [UID:0001EX] `PatchPane2CloseAndRenameDownloadedFile` `82/86 -> 86/88`.
- Owner/emitter decisions: [UID:000142] remains `CANONICAL_OWNER:0000J7`, `EMITTER_UIDS:0000J7`, routed to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`; [UID:0001EX] remains `CANONICAL_OWNER:0000AA`, `EMITTER_UIDS:0000AA`, routed through the PatchPane/PatchPane2 file chain to `auto-generated/NexusTK/patch/PatchPane.cpp`. No owner/emitter metadata changed.
- Leases used: A001 already held active leases for both target docs and this notes file; a renewal attempt returned `Rejected[Already has lease]` for all three paths because the current leases were still owned by A001.
- ApplicationIdleWorkScheduler evidence checked: live read-only IDA MCP session `a002_goal65_20260616` confirmed `sub_4A6C40` as the exact `0x9b` body, with two callers from `sub_464CD0` at `0x464df7`/`0x464e0e`, callees `sub_469200`, `sub_597E40`, `sub_5977B0`, `sub_4A7E70`, `sub_597E90`, and `sub_4B6F60`, three scheduler flag refs at `0x0066d880`, event traversal state refs through `0x0067ab80`, frame-registry ref `0x0069ae10`, role-named helper fields `+0x4`/`+0x2c`/`+0x30`, and a unique full-range signature. IDA string searches for `ApplicationHelper`, `MessageLoopScheduler`, `EventDispatcher.cpp`, and related helper/source names found no recovered source spelling.
- PatchPane2CloseAndRenameDownloadedFile evidence checked: live IDA confirmed `sub_549080` as the exact `0x194` body, with zero direct xrefs/callers, `+0x284` active `FILE*` close/clear, `+0x26c` final path delete/rename target, `+0x270` temp path rename source, `_rename`, `_fclose`, `__errno`, `errno == 2` tolerance, and Win32Error throw paths. Import/name searches did not resolve `sub_5DFD3B`, so it remains a behaviorally named delete/unlink helper; IDA string searches found no `PatchPane2.cpp`, `PatchPane.cpp`, helper-name, or finalization source-name string. Full-range signature is unique.
- Final C++ decision: both targets now clear the numeric eligibility gate with `RECONSTRUCTABLE:TRUE` and combined score above 85, but no C++ was emitted. The routed generated files remain zero bytes, and final-source blockers remain: scheduler helper type/source split and private offsets for [UID:000142]; no direct caller, duplicate inline main-loop sequence, unresolved delete/unlink symbol, and PatchPane/PatchPane2 source split for [UID:0001EX].
- IDA DB changes: none. The pass used read-only lookup, disassembly, xref, signature, import, and string/type-search evidence only.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md --apply --queue-timeout 240` exited `0` with `ok: 1`, score updates, UID-link inserts, and stats-row removals. `python .\tools\validator.py --mode file --file by-memory\0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md --apply --queue-timeout 240` exited `0`; the focused verification output reported `mode: file`, `scanned markdown files: 1`, and `ok: 1`. `rg "000142|0001EX" project-level/-auto-completion-stats.md` returned no matches, so both targets dropped from the low-score stats list.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: replace the two stale rows below; no other shared coverage rows are pending for this batch.

Placement context for [UID:000142]: replace the existing row under parent [UID:000141] `0x004a6a80-0x004a82a9.EventDispatcher`.

```markdown
    - [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md) 0x004a6c40-0x004a6cda | scheduler helper | ApplicationIdleWorkScheduler : reconstructable : 86% : strong : Source-authored idle/message-loop scheduler helper attached to `EventDispatcher`; A001 2026-06-16 live IDA confirms exact `0x9b` body, two `Application::RunMessageLoop` callers, cleanup/timer/traversal/frame callee chain, scheduler flag xrefs, TimerMgr and frame-registry state, helper offsets `+0x4`/`+0x2c`/`+0x30`, unique full-range signature, no recovered source/helper-name strings, and final C++ blocked by unresolved helper type/source split.
```

Placement context for [UID:0001EX]: replace the existing row under parent [UID:0001EQ] `0x005470b0-0x0054940f.PatchPaneAndPatchPane2`, after [UID:0002R7] and before [UID:0001EY].

```markdown
    - [UID:0001EX][0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile](by-memory/0x00549080-0x00549214.PatchPane2CloseAndRenameDownloadedFile.md) 0x00549080-0x00549214 | helper method | PatchPane2CloseAndRenameDownloadedFile : reconstructable : 86% : strong : PatchPane2 file-finalization helper; A001 2026-06-16 live IDA confirms exact `0x194` body, no direct caller/xref, `+0x284` active FILE close/clear, `+0x26c` final path delete/rename target, `+0x270` temp path rename source, `_rename`/`__errno == 2` tolerance, Win32Error throw paths, unique full-range signature, unresolved `sub_5DFD3B` delete/unlink symbol, no recovered helper/source-name strings, and final C++ blocked by reachability/naming/source-split issues.
```

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-lowcompletion-idle-patchpane-source-quality-20260616-69` after verifying blocker research, target scores, and owner/emitter routes. The exact [UID:000142] and [UID:0001EX] `by-memory/-coverage-report.md` replacement rows were applied, and scoped validators for both targets plus the shared report exited `0` with `ok:1`. No A001 supervisor-owned memory coverage rows remain pending for this batch.

## 2026-06-16 A001 Report - A001-goal2-lowcompletion-parcel-employee-data-20260616-68

- Changed target docs: `by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md`, `by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`, support `by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`, and new child `by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md`.
- Changed non-by-* report state: `tools/leaser/Agents/Agent-A001/notes.md`; validator-owned updates to `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and `auto-generated/-ag-memory-coverage.md`. `by-memory/-coverage-report.md` was not edited directly.
- Score changes: [UID:0002KN] `ClearParcelPaneSingleton` `80/90 -> 86/91`; [UID:000256] `EmployeeDialogReadOnlyData` `80/90 -> 86/91`; new [UID:0003V6] `EmployeeDialogResourceLiteralTail` `0/0 -> 85/91`; [UID:0002MH] `AddEmployeeItemDialogVtableData` remains `86/92`.
- Owner/emitter decisions: [UID:0002KN] remains owner/emitter [UID:0000MF] `ParcelPane`; [UID:000256] remains owner/emitter [UID:0000J0] `EmployeeDialogPane`; new [UID:0003V6] routes owner/emitter to [UID:0000J0]; [UID:0002MH] owner/emitter was repaired from [UID:0001XH] vtable-family routing to direct class [UID:000006] `AddEmployeeItemDialog` because the direct class now clears `85/89` and its file parent is `90/88`.
- Parcel source-quality evidence checked: live read-only IDA MCP session `a002_goal65_20260616` reconfirmed `0x00546e80-0x00546e8b` as the exact two-instruction helper body `mov dword ptr unk_69BA28, 0; retn`; no callees; sibling icon helper, five-byte padding, and successor thunk boundary; two constructor/EH-style xrefs to the helper start; nine `g_pParcelPane` xrefs; no extra VA/RVA pointer hits to `0x00546e80`; ParcelPane RTTI/source routing; generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` is still zero bytes. The descriptive helper name remains because original source spelling and source-level call-site form are not recovered.
- Employee source-quality evidence checked: live IDA confirmed exact tail bytes for `0x0061916c-0x0061929c` (`0x130` bytes, 304 decimal) from `Employee` through shared `DLGEXC3.EPF`; byte-backed string starts and per-start xrefs for `Employee`, `SELLER.EPF`, `SELLER.PAL`, `%u`, `(%d%%)`, `Property`, `SELLITEM.EPF`, `SELLITEM.PAL`, `Quantity`, and shared `DLGEXC3.EPF`; `Format`/`SubStr` data-flow for mixed fragments; predecessor/successor boundaries at the add-item vtable child and AddEmployee single-selection text; existing `employee-dialog-resources` resource provenance and `EmployeeDialogPane` source placement. The tail is a bounded child aggregate, not final per-string pages, because wide-versus-narrow/CP949 typing and exact source declarations still need a dedicated audit.
- Final C++ decision: no C++ blocks were emitted. Both `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` and `auto-generated/NexusTK/ui/dialogs/EmployeeDialogPane.cpp` remain zero bytes/no assembled code for these targets, so final C++ is still blocked by helper spelling/call-site form and literal/codepage/source-declaration details.
- IDA DB changes: none; all IDA work was read-only.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md --apply --queue-timeout 240` exited `0` with `ok: 1`; same command shape for `by-memory\0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md`, `by-memory\0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md`, and `by-memory\0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md` also exited `0` with `ok: 1`. Validator removed [UID:0002KN] and [UID:000256] from `project-level/-auto-completion-stats.md`; `rg "0002KN|000256" project-level\-auto-completion-stats.md` returns no matches.
- Leases used: success for the three existing by-memory docs, the new tail child after creation, and this notes file. Some initial leases expired during the long pass; A001 renewed the active edit/validation set before final validation and notes update.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows follow.

Placement context for [UID:0002KN]: replace the existing row under parent [UID:0001EH] `0x00545e40-0x005470ad.ParcelNotificationPanes`, after the ignored `0x00546e7b-0x00546e80` padding row and before `0x00546e8b-0x005470ad.ParcelNotificationAdjustorThunks`.

```text
    - [UID:0002KN][0x00546e80-0x00546e8b.ClearParcelPaneSingleton](by-memory/0x00546e80-0x00546e8b.ClearParcelPaneSingleton.md) 0x00546e80-0x00546e8b | file-scope helper | ClearParcelPaneSingleton : reconstructable : 86% : very strong : Exact parcel pane singleton clear helper; A001 2026-06-16 live IDA confirms the `0x0b` two-instruction body clears `g_pParcelPane`, exact bytes/padding/successor thunk boundary, no callees, two constructor/EH-style xrefs to the helper start, unchanged nine-ref singleton lifecycle fan-in, no extra VA/RVA pointer hits, ParcelPane source-file routing, and blank final C++ pending original helper spelling/call-site form.
```

Placement context for [UID:000256]: replace the existing aggregate row under `ReadOnlyDataSection`, after [UID:000255] `DirectXBitmapReadOnlyData` and before child [UID:0002ME].

```text
    - [UID:000256][0x00618efc-0x0061929c.EmployeeDialogReadOnlyData](by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md) 0x00618efc-0x0061929c | vtable/string-data | EmployeeDialogReadOnlyData : reconstructable : 86% : very strong : Employee dialog `.rdata` island attached to EmployeeDialogPane file parent, with exact main/property/quantity/add-item vtable-data children, new exact [UID:0003V6] resource-tail child, live A001 byte/xref/data-flow refresh for `Employee`, `SELLER.*`, `Property`, `SELLITEM.*`, `Quantity`, shared `DLGEXC3.EPF`, shared format fragments, source-declared/generated-binary handling, zero-byte generated output state, and remaining per-string/codepage/source-declaration blockers.
```

Placement context for [UID:0002MH]: replace the existing vtable child row under [UID:000256], after [UID:0002MG] and before the new [UID:0003V6] child row.

```text
      - [UID:0002MH][0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData](by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md) 0x006190d0-0x0061916c | vtable-data | AddEmployeeItemDialogVtableData : reconstructable : 86% : strong : Exact AddEmployeeItemDialog RTTI plus primary/secondary/tertiary vtable data with live IDA-verified COL pointers, slot spans/counts, inline/raw-constructor store xrefs, successor Employee string boundary, and A001 2026-06-16 owner-gate repair routing the child through direct class [UID:000006] now that AddEmployeeItemDialog clears `85/89`.
```

Placement context for new [UID:0003V6]: insert under [UID:000256] after [UID:0002MH] and before sibling [UID:0001OE] `AddEmployeeSingleSelectionAlertText`.

```text
      - [UID:0003V6][0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail](by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md) 0x0061916c-0x0061929c | string/resource-literal-data | EmployeeDialogResourceLiteralTail : reconstructable : 85% : very strong : Exact employee dialog resource/string tail from `Employee` through shared `DLGEXC3.EPF`; A001 live IDA confirms full `0x130` byte span, byte-backed starts, per-start xrefs, shared `%u`/`(%d%%)`/`DLGEXC3.EPF` caveats, `Format`/`SubStr` data-flow for mixed Korean/CP949 fragments, EmployeeDialogPane source routing, and per-string/codepage/source-declaration blockers.
```

## 2026-06-16 Supervisor Integration - A001-goal2-lowcompletion-parcel-employee-data-20260616-68

- Supervisor accepted the parcel/employee data pass after direct review. [UID:0002KN] clears the gate at `86/91`, [UID:000256] clears at `86/91`, support [UID:0002MH] remains `86/92` with owner/emitter repair, and new [UID:0003V6] clears at `85/91`.
- Source-quality blocker work was sufficient for this stage: singleton helper spelling/call-site form, EmployeeDialog resource tail boundaries, per-string/codepage/source-declaration gaps, direct owner/emitter routing, and blank final-C++ reasons are documented with live IDA/support evidence rather than merely deferred.
- Supervisor confirmed the exact [UID:0002KN], [UID:000256], [UID:0002MH], and [UID:0003V6] shared `by-memory/-coverage-report.md` rows are present, then reran scoped validators for the shared report plus all four target/support pages; all exited `0` with `ok:1`. No A001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - A001-goal2-fittingroom-cache-helper-20260616

- Supervisor accepted the returned cache-helper pass after direct review. [UID:0002EG] `FittingRoomDialogItemStateLoadEncodedCacheFile` clears the gate at `85/88`; support [UID:000051] `FittingRoomDialogItemState` remains `86/88` with refreshed helper inventory.
- The pending [UID:0002EG] `by-memory/-coverage-report.md` replacement row is already present in the shared report at `85%` with A001's source-quality evidence, and scoped validators for the target, support class page, and shared report exited `0` with `ok:1`.
- No A001 supervisor-owned `by-memory/-coverage-report.md` rows remain pending for this batch.

## 2026-06-16 Supervisor Integration - A001-goal2-file-confidence-maptile-myitem-parcel-photo-20260616-64

- Supervisor accepted the batch as complete after A001 raised [UID:0000L5] `MapTileImageLib`, [UID:0000LO] `MyItemListPane`, [UID:0000MF] `ParcelPane`, and [UID:0000MK] `PhotoPane` from `86/85` to `87/86`.
- Owner/path decisions stayed unchanged (`CANONICAL_OWNER:FILE`); IDA work was read-only, no DB edits were made, and no supervisor-owned `by-memory/-coverage-report.md` rows were pending.
- Scoped validators for the four target files and `by-file/-coverage-report.md` exited `0` with `ok:1`.

## 2026-06-16 Supervisor Integration - A001-goal2-file-confidence-pane-miscwork-motion-pool-20260616-65

- Supervisor accepted the batch as complete after A001 raised [UID:0000MC] `Pane` `88/84 -> 88/86`, [UID:0000LG] `MiscWorkThread` `86/85 -> 87/86`, [UID:0000LL] `Motion` `86/85 -> 87/86`, and [UID:0000MM] `PoolAllocator` `86/85 -> 87/86`.
- Owner/path routes stayed unchanged; live/read-only IDA evidence was used for source-quality blocker investigation, no IDA DB edits were made, and no supervisor-owned `by-memory/-coverage-report.md` rows were pending.
- Scoped validators for the four target files and `by-file/-coverage-report.md` exited `0` with `ok:1`.

## 2026-06-16 Assignment - A001-goal2-class-confidence-simplelistpane-20260616-66

- Assigned targets: [UID:0000D8] `by-class/SimpleListPane.md`; support [UID:0000NQ] `by-file/SimpleListPane.md`; related memory [UID:0001HP], [UID:000241], [UID:0002LE]-[UID:0002LI], [UID:0001HQ], and type [UID:0001W3] as needed.
- This is a bounded class-confidence batch from refreshed `project-level/-auto-completion-stats.md`, currently at `85/85`. It is not assigned as a heavy unknown-owner split job unless your evidence shows it has become one.
- Improve evidence/confidence and investigate the standalone `SimpleListPane.cpp` versus folded `ListPane.cpp` source shape, raw constructor reachability, vtable/layout evidence, generated-owner pollution, final helper/member names, and final-C++ blockers. Resolve supported issues or document the exact evidence checked; do not merely list unresolved blockers.
- If the target expands into heavy source-layout inference, document the evidence and recommend B-agent escalation instead of forcing a conclusion. Do not directly edit `by-memory/-coverage-report.md`; record exact supervisor-owned rows if support memory docs change.
- Execution status: queued/pending. Replacement worker `019ed0b4-f703-7df0-ad87-ad4e52ac6b6b` failed immediately with revoked refresh-token authentication, so no A001 work has started for this assignment yet.

## 2026-06-16 A001 Report - A001-goal2-class-confidence-simplelistpane-20260616-66

- Changed target docs: `by-class/SimpleListPane.md` and support `by-file/SimpleListPane.md`.
- Changed report docs: `by-class/-coverage-report.md` and `by-file/-coverage-report.md`.
- Score changes: [UID:0000D8] `SimpleListPane` class `85/85 -> 87/87`; [UID:0000NQ] `SimpleListPane` file `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. Class remains `CANONICAL_OWNER:0000NQ`, `EMITTER_UIDS:0000NQ`; file remains `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`. No by-memory/type owner or emitter metadata changed.
- Source-quality investigations: fresh read-only IDA MCP session `b001_0001KM_20260616` checked `lookup_funcs`, `xrefs_to`, `find_bytes`, `find_regex`, `search_structs`, `type_query`, `callees`, `decompile`, `get_bytes`, and `insn_query`. It reconfirmed no modeled function or direct xrefs/pointer hits for `0x005739a0`, `0x00573aa0`, `0x00573b10`, `0x00573b70`, or `0x00573bb0`; modeled cleanup/destructor/thunk starts at `0x00573a00`, `0x00573c38`, `0x00573c43`, and `0x00573c50`; vtable triad refs at constructor/cleanup/destructor stores; no local IDA struct/type; RTTI/type-name strings only, with no embedded `SimpleListPane.cpp`/`ListPane.cpp` source filename string.
- Generated-output investigations: local review found `project-documentation/auto-generated/NexusTK/ui/controls/SimpleListPane.cpp` and `ListPane.cpp` currently `0` bytes because docs C++ blocks remain blank. `simroot_v2/ui/controls/class_SimpleListPane.cpp` actively emits only the destructor with modern/decompiler artifacts; disabled companion output carries the raw constructor and compiler adjustor thunks. This supports current owner/emitter routing but not final-source C++ yet.
- Final-C++ decision: the target now clears the active minimum score/emitter gate, but C++ stays blank because source-quality blockers remain: raw/no-direct-xref constructor and helper bodies, unnamed unused constructor argument, provisional rectangle/member/helper names, generated `ClientItemMenuItemList` owner pollution, and unresolved standalone `SimpleListPane.cpp` versus folded `ListPane.cpp` final migration.
- IDA DB changes: none; all IDA work was read-only.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory docs or banned report were edited.

## 2026-06-14 Goal 2 AUTOBUF/ApplicationHelper/ChattingColorPane Class Batch

- Changed docs: `by-class/AUTOBUF_unsigned_char.md`, `by-class/ApplicationHelper_4A6C40.md`, `by-class/ChattingColorPane.md`, support `by-type/by-template/AUTOBUF_unsigned_char.md`, `by-class/-coverage-report.md`, `by-type/by-template/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, and validator registry/autogen state.
- Scores: `00000P AUTOBUF_unsigned_char` `78/88 -> 84/89`; `00000E ApplicationHelper_4A6C40` `80/86 -> 85/88`; `00001T ChattingColorPane` `80/86 -> 85/88`; support `0001WN AUTOBUF_unsigned_char` `78/88 -> 82/89`.
- Owner/emitter changes: none. Existing routes remain `00000P -> 0000HM`, `00001T -> 0000I5`, and `0001WN -> 0000HM`; `00000E` remains `RECONSTRUCTABLE:FALSE` with blank owner/emitter/code because it is a reviewed generated wrapper.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed AUTOBUF helper sizes, one-block constructor/resize bodies, direct caller sets, and 21-site vtable fan-out; ApplicationHelper idle-worker/tick-baseline sizes, message-loop call sites, no-callee baseline body, idle-worker callee set, and 20 ms slice gate; ChattingColorPane modeled local method sizes, raw-helper non-function status, constructor sole caller, local vtable refs, persisted color-byte import/save offsets, and virtual button-response slot. Numeric conversions for `0x14`/20 and `0x28DE82..0x28DE8D`/`2678402..2678413` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all six edited by-* docs/reports and exited `0` with `ok: 1` for each. `python .\tools\validator.py --mode rescore --apply --queue-timeout 240` exited `0` with `stats_update: 1`. The assigned UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: success for all six edited by-* docs/reports and this notes file.
- Blockers: none. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` replacement/insert/delete rows are needed for this batch.

## 2026-06-14 Goal 2 Scroll/Emotion/ChangeSpell/FrameChrome Resource Batch

- Changed docs: `by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md`, `by-memory/0x005b2f70-0x005b2fcb.SendEmotionPacket.md`, `by-memory/0x005b3260-0x005b32cc.ChangeSpellSlotInputPaneKeyInput.md`, renamed `by-memory/0x00610f60-0x00610fd4.AboveFrameResourceStrings.md` to `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md`, and support docs `by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md` and `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`.
- Scores: `0001GW ScrollCollectionPaneUpdateDragScroll` `76/86 -> 86/88`; `0001M4 SendEmotionPacket` `76/86 -> 86/88`; `0001M9 ChangeSpellSlotInputPaneKeyInput` `76/86 -> 86/88`; `0002SG` `76/86 -> 86/88` with range/name repair to `FrameChromeResourceStrings`. Support scores unchanged: `00024S` `80/88`, `0002NG` `87/93`.
- Owner/emitter changes: none. Existing routes remain `0001GW -> 0000NG`, `0001M4 -> 0000ID`, `0001M9 -> 00001M`, and `0002SG -> 0000JL`.
- Evidence: live IDA MCP database `b001_0003gy` on 2026-06-14 reconfirmed function sizes, xrefs, decompilation shape, caller/callee sets, raw boundary bytes, and FrameChrome string bytes/xrefs. Important repair: the old `0x00610fd4` endpoint split UTF-16 `NPAL5.PAL`; the exact string child is `0x00610f60-0x00610fe8`, ending immediately before the AES S-box bytes at `0x00610fe8`. Numeric conversions were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all six edited by-memory docs and exited `0` with `ok: 1`. A focused post-rename validation on `by-memory/0x00610f60-0x00610fe8.FrameChromeResourceStrings.md` also exited `0` with `ok: 1` and rebuilt the registry without a stale-path warning. The assigned UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: success for all edited docs and this notes file; the old and intermediate renamed string paths were also leased during the rename workflow.
- Blockers: none for target docs. Final C++ remains blank for all four targets because final source names/declarations remain below the active `90/90+` code-entry gate.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 Scroll/Emotion/ChangeSpell/FrameChrome shared `by-memory/-coverage-report.md` rows for [UID:0001GW], [UID:0001M4], [UID:0001M9], [UID:00024S], and [UID:0002SG] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Scroll/Emotion/ChangeSpell/FrameChrome supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 HierList/MonsterImageLib/StaticObjImageLib/VectorGrowMotion Batch

- Changed docs: `by-memory/0x004cec30-0x004ced0f.HierListFindNodeByData.md`, `by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md`, `by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md`, and `by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md`.
- Scores: `0002IK HierListFindNodeByData` `76/86 -> 86/88`; `00017D MonsterImageLibDestructor` `76/86 -> 86/88`; `00017J StaticObjImageLibRenderStaticObject` `76/86 -> 86/88`; `00017T VectorGrowMotion` `76/86 -> 86/88`.
- Owner/emitter changes: none. Existing direct owner/emitter routes remain `000065` HierList class, `0000LJ` MonsterImageLib file, `0000O7` StaticObjImageLib file, and `0000LR` NewHumanImageLib file.
- Evidence: live IDA MCP database `b001_0003gy` on 2026-06-14 confirmed target function sizes, neighboring starts/padding, callers/callees, decompilation shape, and boundary bytes. Specific repairs: HierList child-list recursion is proven by `ecx = [row+4]` before the recursive call; MonsterImageLib destructor final in-range bytes are the cold invalid-parameter call, not return padding; StaticObjImageLib renderer has two callers and the expected frame/palette/render/alpha helper set; VectorGrowMotion has the sole `LoadMotionTable` caller and `0x42`-byte motion-record vector growth shape. Numeric conversions were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all four edited by-memory docs; each command exited `0` with `ok: 1`. The validator updated projected stats/autogen state and removed the four assigned UIDs from `project-level/-auto-completion-stats.md` low-score rows.
- Leases used: success for all four edited by-memory docs and this notes file.
- Blockers: none for target documentation. Final C++ remains blank for all four targets because final source names, field names, and helper signatures remain below the active `90/90+` code-entry gate. Direct edit of `by-memory/-coverage-report.md` remains supervisor-owned; exact pending replacement rows follow.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 HierList/MonsterImageLib/StaticObjImageLib/VectorGrowMotion shared `by-memory/-coverage-report.md` rows for [UID:0002IK], [UID:00017D], [UID:00017J], and [UID:00017T] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- The validator also reported a pre-existing missing target path for [UID:0001GG] `by-memory/0x0055c1b0-0x0055c1c2.SystemMessageBooleanVirtuals.md`; that target is outside this completed A001 batch and is assigned to A002 for repair/review.
- No Goal 2 HierList/MonsterImageLib/StaticObjImageLib/VectorGrowMotion supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 Midi/PaneChildRegistry/AttachmentAnchor/Session Batch

- Changed docs: `by-file/MidiPlayer.md`, `by-file/PaneChildRegistry.md`, `by-file/AttachmentAnchorResolver.md`, `by-file/Session.md`, support docs `by-class/AttachmentAnchorResolver.md`, `by-memory/0x00525b10-0x0052664b.MidiPlayerAndWinMMHelpers.md`, `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`, `by-memory/0x00525920-0x00525b0d.MidiStreamOpenAndPrimeBuffers.md`, `by-memory/0x00525be0-0x00525dbb.MidiStreamCallback.md`, `by-memory/0x005270e0-0x005271a3.MidiDocumentRelease.md`, `by-memory/0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers.md`, `by-memory/0x0053c6b0-0x0053c6f7.AttachmentAnchorImageBoundsMetricRaw.md`, `by-memory/0x0053c700-0x0053c92e.AttachmentAnchorResolver.md`, `by-memory/0x0053c930-0x0053c97b.AttachmentAnchorScreenBoundsNotifyRaw.md`, `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`, `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, and validator registry/autogen state.
- Scores: `0000LD MidiPlayer` `80/86 -> 85/88`; `0000MD PaneChildRegistry` `80/86 -> 86/88`; `0000HL AttachmentAnchorResolver` `82/84 -> 85/86`; `0000NP Session` `82/84 -> 85/86`; support `00000O AttachmentAnchorResolver` `82/86 -> 85/87`; `0001CF` `78/84 -> 85/87`; `0001CH` `78/84 -> 85/87`; `0001CE` `82/88 -> 85/88`; `0001CG` `82/88 -> 85/88`; `0001CI` `84/90 -> 85/90`; `00023B` `84/90 -> 85/90`; `0002TX`, `0001DH`, `0002TY`, `0002TZ`, and `0002U0` each `82/86 -> 85/87`.
- Owner/emitter changes: none in document metadata. Coverage-only classification for `by-file/PaneChildRegistry.md` changed from reconstructable to ignored/non-standalone; its header remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed MidiPlayer WinMM starts/callback refs/reset fan-in/singleton refs/padding, BlackHole `0x00469180` pane-delete helper behavior and broad caller fan-in, AttachmentAnchorResolver modeled/raw sibling boundaries and no-xref raw starts, and the Session non-promotion boundary through DialogSession/BulletinSession versus Socket/request/Thread anchors. Final C++ remains blank for all touched docs because final source names, raw reachability, and source splits remain below the active `90/90+` code-entry gate.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all 18 edited by-* docs/reports; the loop exited `0` with `ok: 1` for each file. The validator removed the four assigned target UIDs and refreshed support UIDs from `project-level/-auto-completion-stats.md`.
- Leases used: success for all edited docs/reports and this notes file. Initial leases expired during the edit pass; A001 re-leased the complete edited file set before validation and notes finalization.
- Blockers: direct edit of `by-memory/-coverage-report.md` remains supervisor-owned; exact pending replacement rows follow.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 Midi/PaneChildRegistry/AttachmentAnchor/Session shared `by-memory/-coverage-report.md` rows for [UID:0001CE], [UID:0001CF], [UID:0001CG], [UID:0001CH], [UID:00023B], [UID:0001CI], [UID:0002TX], [UID:0001DH], [UID:0002TY], [UID:0002TZ], and [UID:0002U0] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Midi/PaneChildRegistry/AttachmentAnchor/Session supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 StaticCloud/WillBeChanged/YFlip/BinaryCodec Batch

- Changed docs: `by-class/StaticCloudFilterEffecter.md`, `by-class/WillBeChangedSpellPane.md`, `by-class/YFlipEffecter.md`, `by-file/BinaryCodec.md`, new children `by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md`, `by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md`, `by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md`, support docs `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`, `by-memory/0x004c78e0-0x004c82cf.WillBeChangedPreviewPanes.md`, `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`.
- Scores: `0000E0 StaticCloudFilterEffecter` `80/84 -> 86/87`; `0000G6 WillBeChangedSpellPane` `80/84 -> 86/87`; `0000GD YFlipEffecter` `80/84 -> 86/88`; `0000HQ BinaryCodec` `80/86 -> 86/88`; support `0001GE ScreenEffecterRuntimeCluster` `85/87 -> 86/88`; support `00016U WillBeChangedPreviewPanes` `84/90 -> 85/90`; support `00013M DecoderAndCodecVtableGlue` `78/88 -> 85/89`; new `0003O9 StaticCloudFilterEffecterRawConstructor` `0/0 -> 86/89`; new `0003OA YFlipEffecterRawConstructor` `0/0 -> 86/89`; new `0003OB YFlipEffecterApplyEffect` `0/0 -> 85/88`.
- Owner/emitter changes: new children route to direct class owners/emitters (`0003O9 -> 0000E0`, `0003OA/0003OB -> 0000GD`). `00013M` was changed from reconstructable/emitting index to `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`; `CANONICAL_OWNER:0000HQ` remains as semantic ownership for the shared codec index.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed StaticCloud raw constructor bytes/base call/vtable refs/padding, YFlip raw constructor bytes/apply body/vtable slot/reverse-Y blit behavior/padding, WillBeChangedSpellPane method boundaries/vtable refs/constructor caller/paint-input-destructor behavior, and BinaryCodec modeled Encoder/Decoder boundaries/raw Decoder no-function-no-xref status/vtables/DAT boundary/padding.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all twelve edited by-* docs/reports; every command exited `0` with `ok: 1` where shown, and the loop exited `0`.
- Leases used: success for all edited docs/reports and this notes file. Initial leases expired during a long edit pass; A001 re-leased the complete file set before further edits and validation. No conflicting leases were present on these docs.
- Blockers: direct edit of `by-memory/-coverage-report.md` remains supervisor-owned; exact pending rows follow. Final C++ remains blank for all touched targets because field/helper names, caller recovery, and exact source signatures remain below the active `90/90+` code-entry gate.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:00013M], [UID:00016U], [UID:0001GE], [UID:0003O9], [UID:0003OA], and [UID:0003OB] `by-memory/-coverage-report.md` rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 StaticCloud/WillBeChanged/YFlip/BinaryCodec supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 Quit/RingBuffer/Say/Scroll Batch

- Changed docs: `by-class/QuitInputPane.md`, `by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md`, `by-class/RingBufferIterator.md`, `by-memory/0x005563d0-0x005568c8.RingBuffer.md`, `by-class/SayToPlanMessageInputPane.md`, `by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md`, `by-file/ScrollCollectionPane.md`, `by-class/ScrollCollectionPane.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`.
- Scores: `0000BH QuitInputPane` `82/82 -> 85/86`; `0001KS QuitInputPaneCore` `78/84 -> 85/87`, owner/emitter `0000MX -> 0000BH`; `0000C2 RingBufferIterator` `82/82 -> 85/86`; `0001G4 RingBuffer` `82/86 -> 85/88`; `0000C5 SayToPlanMessageInputPane` `82/82 -> 85/86`; `0001LY SayTargetMessageInputPanes` `84/85 -> 85/86`; `0000NG ScrollCollectionPane` `82/82 -> 86/85`; `0000CG ScrollCollectionPane` score unchanged, synced file-parent score wording.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed Quit raw constructor/model handler/launcher/singleton/vtable refs, RingBufferIterator raw constructor/helper/vtable refs and no-direct-caller caveat, SayToPlan mode-4 `Clan => ` constructor plus opcode `0x19` submit path, and ScrollCollectionPane direct `CollectionPane` allocation/setter/vtable/helper boundary evidence.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all ten edited by-* docs/reports; every command exited `0` with `ok: 1`.
- Leases used: success for all edited docs/reports and this notes file. `by-class/ScrollCollectionPane.md` renewal reported `Rejected[Already has lease]` because A001 already held it.
- Blockers: none for documentation. Final C++ remains blank for all touched targets below the active `90/90+` code-entry gate.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:0001G4], [UID:0001KS], and [UID:0001LY] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 Quit/RingBuffer/Say/Scroll supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 User/CashShop/Thread Batch

- Changed docs: `by-memory/0x00596250-0x0059756e.ThreadAndThreadMan.md`, `by-memory/0x00596620-0x005969b0.CashShopRequestWaitDispatch.md`, `by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md`, `by-memory/0x005a2530-0x005b8395.UserPane.md`, and `by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md`.
- Scores: `0001JX` `84/84 -> 85/86`; `0001JY` `82/82 -> 85/86`; `0001KI` `82/82 -> 85/86`; `0001KL` `82/82 -> 85/86`; `0001KM` `82/82 -> 85/86`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed Thread dispatch starts/xrefs/raw sibling boundary, user-list function/vtable/singleton/show-hidden refs, UserPane constructor/name/vtable/name-buffer/pool refs and padding, and LivingObjectPane modeled/raw local-player/action-tail helper boundaries.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all five edited by-memory docs; every command exited `0` with `ok: 1`.
- Leases used: success for all five edited by-memory docs and this notes file. Final C++ remains blank for all touched docs because unresolved names/raw helpers keep them below the active `90/90+` code-entry gate.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:0001JX], [UID:0001JY], [UID:0001KI], [UID:0001KL], and [UID:0001KM] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 User/CashShop/Thread supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 CreateUser/Cursor/Earthquake/StringIter Batch

- Changed docs: `by-class/CreateUserDialogPane.md`, `by-class/CursorManager.md`, `by-class/EarthquakeEffecter.md`, `by-class/StringIter.md`, `by-memory/0x00584d80-0x00584e9e.StringIter.md`, `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`, `by-class/-coverage-report.md`, and validator-applied `project-level/-auto-completion-stats.md` projected stats updates.
- Scores: `00003B CreateUserDialogPane` `78/84 -> 85/86`; `00003E CursorManager` `78/84 -> 85/86` with `RECONSTRUCTABLE:FALSE` unchanged; `000046 EarthquakeEffecter` `78/84 -> 85/86`; `0000E7 StringIter` `78/84 -> 85/86`; support `0001J5 StringIter` `78/84 -> 85/86`; support `0001GE ScreenEffecterRuntimeCluster` `82/86 -> 85/87`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed CreateUser method starts/sizes, constructor callers, action/submit helper edges, vtable/singleton refs, and lifecycle-island boundary bytes; Cursor helper starts/callees/root-screen alias refs and no separate lifetime; Earthquake raw constructor bytes, vtable store/slot refs, modeled `ApplyEffect`/destructor sizes, and callees; StringIter promoted/raw helper boundaries, caller fan-in, scalar-deleting-destructor data ref, and byte-level helper/padding spans.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all seven edited by-* docs/reports; every command exited `0` with `ok: 1`. The validator also rebuilt `tools/validator.ini` as part of its normal registry update.
- Leases used: success for all edited docs/reports and this notes file. Final C++ remains blank for all touched docs because unresolved source names/raw helper boundaries/source splits keep them below the active `90/90+` code-entry gate.
- Blockers: none for the assigned docs. `by-memory/-coverage-report.md` remains supervisor-owned and was not edited directly.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:0001GE] and [UID:0001J5] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 CreateUser/Cursor/Earthquake/StringIter supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 EventHandler Tree/Error Wrapper Batch

- Changed docs: `by-class/TreeItor_near_class_EventHandler___.md`, `by-class/Tree_near_class_EventHandler___.md`, `by-class/WSAError.md`, `by-class/Win32Error.md`, `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`, `by-memory/0x004a60d0-0x004a60f5.Win32ErrorConstructor.md`, `by-memory/0x004a64a0-0x004a64c5.WSAErrorConstructor.md`, `by-class/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, and validator-applied `tools/validator.ini`.
- Scores: `0000FA TreeItor_near_class_EventHandler___` `78/84 -> 85/86`; `0000F8 Tree_near_class_EventHandler___` `78/84 -> 85/86`; `0000GB WSAError` `78/84 -> 85/86`; `0000G7 Win32Error` `78/84 -> 85/86`; support `00013X ErrorWrappers` `80/84 -> 85/86`; support `0002HJ Win32ErrorConstructor` `78/88 -> 85/89`; support `0002HM WSAErrorConstructor` `78/88 -> 85/89`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed EventDispatcher tree/iterator destructor and deleting-destructor starts, vtable refs, stack construction refs, callees, byte boundaries, and Error hierarchy Win32/WSA constructor/formatter starts, vtable stores/slot refs, caller sets, `FormatMessageW` formatter behavior, string refs, callees, and byte boundaries.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all eight edited by-* docs/reports; every command exited `0` with `ok: 1`. The validator also rebuilt `tools/validator.ini` and updated `project-level/-auto-completion-stats.md` as part of normal registry/stat maintenance.
- Leases used: success for all edited docs/reports and this notes file. Final C++ remains blank for all touched docs because exact declaration/source naming and broad support-page split caveats remain below the active `90/90+` code-entry gate.
- Blockers: none for assigned docs. `by-memory/-coverage-report.md` remains supervisor-owned and was not edited directly.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:00013X], [UID:0002HJ], and [UID:0002HM] `by-memory/-coverage-report.md` replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 EventHandler Tree/Error Wrapper supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 SimpleHelp/TransferServer/CheckBox Batch

- Changed docs: `by-class/SimpleHelpPane.md`, `by-class/TransferServerDialogPane.md`, `by-file/CheckBoxControlPane.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, and validator-applied `tools/validator.ini`.
- Scores: `0000D6 SimpleHelpPane` `84/82 -> 85/86`; `0000F7 TransferServerDialogPane` `84/82 -> 85/86`; `0000I7 CheckBoxControlPane` `84/82 -> 85/86`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed SimpleHelpPane method sizes, constructor xrefs, singleton data-flow sites, and vtable triplet; TransferServerDialogPane method sizes, nine constructor xrefs, singleton data-flow sites, and `TRANSSVR` vtable/resource island; and CheckBoxControlPane method sizes, constructor xrefs, constructor vtable/resource-state stores, paint behavior, and three vtable heads.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all five edited by-* docs/reports; every command exited `0` with `ok: 1`. The validator removed the three target rows from `project-level/-auto-completion-stats.md` low-confidence lists and rebuilt `tools/validator.ini`.
- Leases used: success for all edited docs/reports and this notes file. Final C++ remains blank for all touched targets because field/event names, source grouping, and thunk/source-shape caveats remain below the active `90/90+` code-entry gate.
- Blockers: none. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` replacement rows are pending for this batch.

## 2026-06-14 Goal 2 RequestSync/Filter/Fitting/Mail Batch

- Changed docs: `by-class/RequestSyncGate.md`, `by-class/FilterEffecter.md`, `by-class/FittingRoomUserImageControlPane.md`, `by-class/MailListDialog.md`, support `by-file/Monitor.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, and validator-applied `tools/validator.ini`.
- Scores: `0000BX RequestSyncGate` `78/86 -> 85/87`; `00004Y FilterEffecter` `80/84 -> 85/86`; `000056 FittingRoomUserImageControlPane` `80/84 -> 85/87`; `00007L MailListDialog` `80/84 -> 85/86`; support `0000LI Monitor` `84/86 -> 85/86`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed RequestSyncGate wait/release helper sizes, field offsets, and paired caller family; FilterEffecter constructor/destructor-reset sizes, four vtable-view data flow, and subclass base calls; FittingRoomUserImageControlPane local method sizes, constructor/rotate callers, vtable stores, adjustor thunks, deleting destructor, and `0x00495450` false-anchor exclusion; and MailListDialog method sizes, constructor callers, vtable stores, local action/request and packet/update call graph, request serialization, and delete-reply packet handling.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all seven edited by-* docs/reports; the validation loop exited `0` with `ok: 1` for each file. The validator removed all four target rows from the low-score stats list and rebuilt `tools/validator.ini`.
- Leases used: success for all edited docs/reports and this notes file. Final C++ remains blank for all touched docs because exact source declarations, field names, helper visibility, and file/source split details remain below the active `90/90+` code-entry gate.
- Blockers: none. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` replacement rows are pending for this batch.

## 2026-06-14 Goal 2 MailTransfer/NewMail/Callback/RecordVector Batch

- Changed docs: `by-class/MailTransferReplyAlert.md`, `by-class/NewMailDialog.md`, `by-class/PlainMemberFunctionObject_void____thiscall_PopupMenuControlPane_____long____class_PopupMenuControlPane_.md`, `by-class/RecordVector_4E57C0.md`, new child `by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md`, `by-memory/0x0049af00-0x0049af11.PopupMenuSelectionCallbackInvoke.md`, `by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md`, `by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md`, `by-file/BulletinReplyAlerts.md`, `by-file/MailDialogs.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, validator-applied `project-level/-auto-completion-stats.md`, validator-applied `auto-generated/-ag-memory-coverage.md`, and validator registry/cache files.
- Scores: `00007N MailTransferReplyAlert` `80/84 -> 86/88`; `000096 NewMailDialog` `80/84 -> 86/87`; `0000AK PlainMemberFunctionObject...PopupMenuControlPane` `80/84 -> 85/86`; `0000BS RecordVector_4E57C0` `80/84 -> 85/86`; new `0003O8 MailTransferReplyAlertRawConstructor` `0/0 -> 86/89`; support `00011X PopupMenuSelectionCallbackInvoke` `82/88 -> 85/89`; support `00017U RecordVectorInsert` `78/86 -> 85/88`; support `0000ZM BulletinMailAlertCompanions` `82/89 -> 84/90`; support `0000HW BulletinReplyAlerts` `85/86 -> 86/87`; support `0000KZ MailDialogs` `86/85 -> 86/86`.
- Evidence: live IDA MCP database `b001_0003gy` reconfirmed the `MailTransferReplyAlert` raw constructor bytes/no-function status/vtable stores/successor confirm action, `NewMailDialog` method boundaries/vtable stores/constructor caller/send and transfer-reply behavior, popup callback exact adjusted dispatch/no callers/seven data refs/stale `0x004d0050` rejection, and `RecordVector` insert growth/copy/free behavior plus `sub_4E6FF0` copy-helper evidence.
- Validation: `python .\tools\validator.py --mode file --file <edited by-* doc/report> --apply --queue-timeout 240` was run for all twelve edited by-* docs/reports; every command exited `0` with `ok: 1`.
- Leases used: initial and refreshed success for all edited by-* docs/reports, success for the new constructor child after creation, and success for this notes file. Final C++ remains blank for all touched docs because helper/resource/type names, field names, and source-split details remain below the active `90/90+` code-entry gate.
- Blockers: none for docs. `by-memory/-coverage-report.md` remains supervisor-owned and was not edited directly.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 [UID:0000ZM], [UID:0003O8], [UID:00011X], and [UID:00017U] `by-memory/-coverage-report.md` rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 MailTransfer/NewMail/Callback/RecordVector supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 CandidateStringQueue Helper Batch

- Changed docs: `by-memory/0x004e8450-0x004e85ae.CandidateStringQueueAssignRange.md`, `by-memory/0x004e8a00-0x004e8ae6.CandidateStringQueueClear.md`, and `by-memory/0x004e9710-0x004e97a3.CandidateStringQueueAppendOwnedString.md`.
- Scores: `0002MS CandidateStringQueueAssignRange` `76/88 -> 86/90`; `0002MU CandidateStringQueueClear` `76/88 -> 86/90`; `00018F CandidateStringQueueAppendOwnedString` `76/88 -> 86/90`.
- Owner/emitter changes: none. All three remain `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank final C++ because these are MSVC/Dinkumware standard-library deque/wstring helper materializations, not NexusTK-owned source. The source-facing container use remains with IMEPanes/InputMan callers.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed exact function starts/sizes/end non-functions, adjacent modeled starts/alignment boundaries, caller sites, helper-family internal call graph, `0x18` wide-string element allocation/move/reset behavior, SSO-7 and large-allocation validation, and absence of product-specific callees/strings in the helper bodies.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all three edited by-memory docs and exited `0`; the loop completed with `ok: 1` for each file. `rg -n "0002MS|0002MU|00018F" project-level/-auto-completion-stats.md` returned no matches after validation.
- Leases used: success for all three edited by-memory docs and this notes file.
- Blockers: none for target docs. Final C++ remains blank under the active gate because these pages are not reconstructable. Direct edit of `by-memory/-coverage-report.md` remains supervisor-owned; exact pending replacement rows follow.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 CandidateStringQueue shared `by-memory/-coverage-report.md` replacement rows for [UID:0002MS], [UID:0002MU], and [UID:00018F] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 CandidateStringQueue supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 ChangeItem/ChangeSpell/Chat Input Pane Memory Batch

- Changed docs: `by-memory/0x005b3010-0x005b3196.ChangeItemSlotInputPane.md`, `by-memory/0x005b3220-0x005b340e.ChangeSpellSlotInputPane.md`, and `by-memory/0x005b3940-0x005b3bba.ChatInputPane.md`.
- Scores: `0001M6 ChangeItemSlotInputPane` `78/84 -> 86/88`; `0001M8 ChangeSpellSlotInputPane` `78/84 -> 85/86`; `0001MC ChatInputPane` `78/84 -> 85/87`.
- Owner/emitter changes: `0001M6` changed from direct file route `0000KC` to direct class owner/emitter `00001J`, which routes to `0000KC` and `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`. `0001M8` and `0001MC` kept their existing direct class routes `00001M` and `00001Q`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed all modeled function starts/sizes, no-function raw constructor starts, vtable-only dispatch xrefs, handler/submit decompilation behavior, shared globals/callees, destructor anchor for ChatInputPane, and padding bytes. Numeric equivalences `408 == 0x198` and `14 == 0x0e` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all three edited memory docs and exited `0` with `ok: 1`; `project-level/-auto-completion-stats.md` no longer lists `0001M6`, `0001M8`, or `0001MC`; `auto-generated/-ag-memory-coverage.md` now shows `0001M6 -> 00001J -> auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp`.
- Leases used: success for all three edited by-memory docs and this notes file.
- Blockers: no documentation blocker. Final C++ remains blank for all three targets because helper/source names, event/input field names, player-state field names, and exact source-level signatures remain below final-source quality even though the minimum score/emitter route gate now clears.

## Supervisor-Applied Shared Rows

- The supervisor applied and validated the Goal 2 ChangeItem/ChangeSpell/Chat shared `by-memory/-coverage-report.md` replacement rows for [UID:0001M6], [UID:0001M8], and [UID:0001MC] on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 ChangeItem/ChangeSpell/Chat supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-14 Goal 2 NewHistory/NewMacro/ObjectImage/PictureView Class Batch

- Changed docs: `by-class/NewHistoryDialogPane.md`, `by-class/NewMacroEditControlPane.md`, `by-class/ObjectImageControlPane.md`, `by-class/PictureViewPane.md`, and support `by-memory/0x00549b00-0x00549b63.PictureViewPaneCloseHandlersAndThunks.md`.
- Scores: `000091 NewHistoryDialogPane` `82/84 -> 85/86`; `000095 NewMacroEditControlPane` `82/84 -> 85/87`; `00009O ObjectImageControlPane` `82/84 -> 85/86`; `0000AH PictureViewPane` `82/84 -> 85/86`; support `0001F3 PictureViewPaneCloseHandlersAndThunks` `82/88 -> 85/89`.
- Owner/emitter changes: target class owner/emitter routes unchanged (`000091 -> 0000LQ`, `000095 -> 0000KY`, `00009O -> 0000M3`, `0000AH -> 0000MK`). Support memory child `0001F3` was rerouted from file `0000MK` to direct class owner/emitter `0000AH` now that `PictureViewPane` clears the 85/85 child-attachment gate; generated output still surfaces through `0000MK`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed function sizes, constructor callers/xrefs, singleton/vtable refs, key/paint/close-handler decompilation behavior, destructor/thunk routing, and retained source-quality blockers for final C++.
- Validation: `python .\tools\validator.py --mode file --file <edited doc> --apply --queue-timeout 240` was run sequentially for all five edited docs and exited `0` with `ok: 1` for each. `rg -n "000091|000095|00009O|0000AH|0001F3" project-level/-auto-completion-stats.md` returned no matches, and `auto-generated/-ag-memory-coverage.md` now shows `0001F3` owner/emitter route `0000AH -> auto-generated/NexusTK/map/PhotoPane.cpp`.
- Leases used: success for all five edited docs and this notes file.
- Blockers: direct edits to `by-class/-coverage-report.md` and `by-memory/-coverage-report.md` are supervisor-owned/leased; exact pending replacement rows follow. Final C++ remains blank for all touched docs because source-quality helper names, field names, declarations, or adjusted containing-object type remain unresolved.

## Supervisor-Applied Shared Rows

- Supervisor applied and validated the Goal 2 NewHistory/NewMacro/ObjectImage/PictureView `by-class/-coverage-report.md` replacement rows for [UID:000091], [UID:000095], [UID:00009O], and [UID:0000AH] on 2026-06-14.
- Supervisor applied and validated the Goal 2 [UID:0001F3] `by-memory/-coverage-report.md` replacement row on 2026-06-14.
- Validation commands: `python .\tools\validator.py --mode file --file by-class/-coverage-report.md --apply --lock-timeout -1`; `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; results `ok: 1`.
- No Goal 2 NewHistory/NewMacro/ObjectImage/PictureView supervisor-owned shared-report rows remain pending.

## 2026-06-14 Goal 2 DAT/Blend/ImageFrame/PacketTransform Item Batch

- Changed docs: `by-item/DATEntryRecord.md`, `by-item/DrawFrameWithBlendMode_00462E10.md`, `by-item/LoadImageFrameTable_004D0F50.md`, `by-item/PacketTransformHelpers.md`, and `by-item/-coverage-report.md`.
- Scores: `0000UC DATEntryRecord` `80/86 -> 85/88`; `0000UI DrawFrameWithBlendMode_00462E10` `82/86 -> 85/88`; `0000UY LoadImageFrameTable_004D0F50` `82/86 -> 85/88`; `0000V3 PacketTransformHelpers` `82/86 -> 85/88`.
- Owner/emitter changes: none. Routes remain `0000UC -> 0000IN`, `0000UI -> 0000HF`, `0000UY -> 0000K1`, and `0000V3 -> 0000M9`; generated item coverage confirms these routes to `DATFile.cpp`, `AlphaMaskSurface.cpp`, `ImageFrameTable.cpp`, and `PacketTransform.cpp`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed function starts/sizes, xrefs/caller counts, DAT 17-byte record use, blend-mode dispatch, image-frame shard/record/sentinel behavior, packet transform helper boundaries/xrefs, and raw/no-function status for `0x00575b90`. Numeric conversions for `17 == 0x11`, `24 == 0x18`, `31 == 0x1f`, and `100 == 0x64` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-item doc/report> --apply --queue-timeout 240` was run sequentially for all five edited by-item docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000UC|0000UI|0000UY|0000V3" project-level/-auto-completion-stats.md` returned no matches.
- Leases used: success for all five edited by-item docs/reports and this notes file.
- Blockers: none for target documentation. Final C++ remains blank for all four items because field/type names, helper prototypes, sentinel/source declaration details, or raw-helper liveness remain below source-quality evidence. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` rows are pending for this batch.

## 2026-06-14 Goal 2 AddEmployee/ArgumentedPurchase/EffectArchive/Heartbeat Item Batch

- Changed docs: `by-item/AddEmployeeItemDialogInlineConstruction_004A339F.md`, `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`, `by-item/BuildEffectArchiveTable_004DE420.md`, `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`, and `by-item/-coverage-report.md`.
- Scores: `0000TT AddEmployeeItemDialogInlineConstruction_004A339F` `82/88 -> 85/90`; `0000TY ArgumentedItemPurchaseHelpers_51f450_51f640` `82/88 -> 85/89`; `0000U4 BuildEffectArchiveTable_004DE420` `82/88 -> 85/90`; `0000U8 CheckTimerSkewAndSendHeartbeat_466CA0` `82/88 -> 86/90`.
- Owner/emitter changes: `0000TT` changed from `CANONICAL_OWNER:NONE` to semantic owner `0003KY` and remains `RECONSTRUCTABLE:FALSE` with blank emitters as a non-standalone source-map anchor. `0000TY`, `0000U4`, and `0000U8` kept their routes `0000HH`, `0000IY`, and `0000HG`; generated item coverage confirms output paths through `ArgumentedItemInputDialogs.cpp`, `EffectObjImageLib.cpp`, and `Application.cpp`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed target function sizes, raw/no-function starts, direct xrefs, callees/strings, and decompile shapes for the inline AddEmployee construction, argumented item purchase helper family, effect archive shard table builder, and timer-skew/heartbeat helper. Numeric conversions for allocation/resource/opcode/packet constants including `628 == 0x274`, `644 == 0x284`, `636 == 0x27c`, `246 == 0xf6`, `57 == 0x39`, `14 == 0x0e`, `100 == 0x64`, `24 == 0x18`, `30000 == 0x7530`, and `11 == 0x0b` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-item doc/report> --apply --queue-timeout 240` was run for all five edited by-item docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000TT|0000TY|0000U4|0000U8" project-level/-auto-completion-stats.md` returned no matches; `auto-generated/-ag-item-coverage.md` shows `0000TT` as `not_reconstructable` owner `0003KY` and the other three as emitting through their unchanged owners.
- Leases used: success for all four target docs, `by-item/-coverage-report.md`, and this notes file; target/report leases expired after validation, and this notes lease was reacquired for finalization.
- Blockers: none for target documentation. Final C++ remains blank because `0000TT` is not reconstructable and the reconstructable items still lack source-quality declarations/field names/helper prototypes despite clearing the score gate. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` rows are pending for this batch.

## 2026-06-14 Goal 2 PCX/EPFMetadata/ItemGlyph Item Batch

- Changed docs: `by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md`, `by-item/DecodePcxToRgb565Buffer_00549410.md`, `by-item/EPFArchiveMetadataTable.md`, `by-item/GetItemGlyphBounds_004DF460.md`, and `by-item/-coverage-report.md`.
- Scores: `0000U9 CreateDIBitmapFromPcxBuffer_004A18B0` `82/88 -> 85/90`; `0000UD DecodePcxToRgb565Buffer_00549410` `82/88 -> 85/90`; `0000UN EPFArchiveMetadataTable` `82/88 -> 85/90`; `0000UQ GetItemGlyphBounds_004DF460` `82/88 -> 85/90`.
- Owner/emitter changes: none. Routes remain `0000U9 -> 0000K3`, `0000UD -> 0000K3`, `0000UN -> 0000K1`, and `0000UQ -> 0000KH`; generated item coverage confirms output paths through `ImageLoaders.cpp`, `ImageFrameTable.cpp`, and `ItemObjImageLib.cpp`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed target function sizes/endpoints, caller/xref counts, PCX DIB factory allocation/row-copy/decode flow, PCX validation/RLE/remap/RGB565 mechanics, EPF frame-table header/record/sentinel plus draw-record next-boundary projection, and item glyph remap/EPF-vs-EPD lookup/centering behavior. Numeric conversions including `604 == 0x25c`, `518 == 0x206`, `1653 == 0x675`, `153 == 0x99`, `60 == 0x3c`, `40 == 0x28`, `128 == 0x80`, `768 == 0x300`, `769 == 0x301`, `12 == 0x0c`, `100 == 0x64`, `24 == 0x18`, `16 == 0x10`, `20 == 0x14`, `16384 == 0x4000`, `16211 == 0x3f53`, and `2418 == 0x972` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-item doc/report> --apply --queue-timeout 240` was run for all five edited by-item docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000U9|0000UD|0000UN|0000UQ" project-level/-auto-completion-stats.md` returned no matches.
- Leases used: success for all four target docs, `by-item/-coverage-report.md`, and this notes file. Target/report leases expired during validation; this notes file was re-leased for finalization.
- Blockers: none for target documentation. Final C++ remains blank for all four items because source-level signatures, struct/field/global names, helper prototypes, or final file split details remain below source-quality evidence despite the score/emitter gate clearing. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` rows are pending for this batch.

## 2026-06-14 Goal 2 SpriteBounds/HalfBlend/FrameDraw/TileEpf Item Batch

- Changed docs: `by-item/GetSpriteBounds_004DE2A0.md`, `by-item/HalfBlendSpan16Blocks_00460C10.md`, `by-item/LoadFrameDrawRecord_004D1600.md`, `by-item/LoadTileEpfMetadata_004D1B80.md`, and `by-item/-coverage-report.md`.
- Scores: `0000UR GetSpriteBounds_004DE2A0` `82/88 -> 85/90`; `0000US HalfBlendSpan16Blocks_00460C10` `82/88 -> 85/90`; `0000UX LoadFrameDrawRecord_004D1600` `82/88 -> 85/90`; `0000V0 LoadTileEpfMetadata_004D1B80` `82/88 -> 85/90`.
- Owner/emitter changes: none. Routes remain `0000UR -> 0000IY`, `0000US -> 0000NT`, `0000UX -> 0000K1`, and `0000V0 -> 0000L5`; generated item coverage confirms output paths through `EffectObjImageLib.cpp`, `SoftwareBlend16.cpp`, `ImageFrameTable.cpp`, and `MapTileImageLib.cpp`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed function starts/sizes/endpoints, caller/xref counts, sprite bounds `g_useEpfAssets` EPF/EPD branch behavior, half-blend MMX body and qword mask constants, image-frame output field projection, tile EPF shard table load/merge/sentinel flow, and adjacent padding. Numeric conversions including `306 == 0x132`, `124 == 0x7c`, `93 == 0x5d`, `930 == 0x3a2`, `200 == 0xc8`, `100 == 0x64`, `12 == 0x0c`, `20 == 0x14`, `24 == 0x18`, `49 == 0x31`, `81 == 0x51`, `0x821082108210821`, and `0xf7def7def7def7de` were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-item doc/report> --apply --queue-timeout 240` was run for all five edited by-item docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000UR|0000US|0000UX|0000V0" project-level/-auto-completion-stats.md` returned no matches.
- Leases used: success for all four target docs, `by-item/-coverage-report.md`, and this notes file.
- Blockers: none for target documentation. Final C++ remains blank for all four items because source-level signatures, type/field names, helper prototypes, or exact source declarations remain below source-quality evidence despite the score/emitter gate clearing. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` rows are pending for this batch.

## 2026-06-14 Goal 2 PacketBuffer/PhoneBook/PopupMenu/ScreenEffecter Item Batch

- Changed docs: `by-item/PacketBufferHelpers.md`, `by-item/PhoneBookListHelpers_58cfa0_58dcb0.md`, `by-item/PopupMenuSelectionCallback_0049AF00.md`, `by-item/ScreenEffecterSmallConstructorBoundaries.md`, and `by-item/-coverage-report.md`.
- Scores: `0000V1 PacketBufferHelpers` `82/88 -> 85/90`; `0000V7 PhoneBookListHelpers_58cfa0_58dcb0` `82/88 -> 85/90`; `0000V8 PopupMenuSelectionCallback_0049AF00` `82/88 -> 85/89`; `0000VE ScreenEffecterSmallConstructorBoundaries` `82/90 -> 85/90`.
- Owner/emitter changes: none. Routes remain `0000V1 -> 0000M8`, `0000V7 -> 0000MJ`, `0000V8 -> 0000AK`, and `0000VE -> 0000IZ`; generated item coverage confirms output paths through `PacketBuffer.cpp`, `PhoneBookDialog.cpp`, `FunctionObjects.cpp`, and `Effects.cpp`.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed PacketBuffer helper starts/sizes, representative decompilation, high-traffic scalar xref shape, rare helper xref split, string-helper callees, and padding splits; phone-book helper starts/endpoints, xrefs, decompiled selected-entry copy and varargs write forwarding, and padding; popup invoke half-open boundary, adjacent sibling-thunk split, seven data-only refs, and stale `0x004d0050` rejection; and six ScreenEffecter-family raw constructor starts, no-direct-xref state, vtable-store refs, raw bytes, and padding. Numeric conversions were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-item doc/report> --apply --queue-timeout 240` was run for all five edited by-item docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000V1|0000V7|0000V8|0000VE" project-level/-auto-completion-stats.md` returned no matches.
- Leases used: success for all four target docs, `by-item/-coverage-report.md`, and this notes file.
- Blockers: none for target documentation. Final C++ remains blank for all four items because source-level names/signatures, cursor/storage or field types, template/source-header spelling, raw constructor call paths, or exact class-layout details remain below source-quality evidence. No `by-memory` docs were edited, and no supervisor-owned `by-memory/-coverage-report.md` rows are pending for this batch.

## 2026-06-14 Goal 2 Mixed Cleanup Item/Global/Struct Batch

- Changed docs: `by-item/BlendRgb555_004C0710.md`, `by-item/BuildClippedAlphaSurfaceView_00462320.md`, renamed `by-global/g_browserWindowCaption.md` to `by-global/g_browserWindowClassName.md`, `by-type/by-struct/ModelessDialogPaneLayout.md`, support docs `by-file/Browser.md`, `by-class/BrowserWindow.md`, `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`, and reports `by-item/-coverage-report.md`, `by-global/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md`.
- Scores: `0000TZ BlendRgb555_004C0710` `84/88 -> 85/90`; `0000U3 BuildClippedAlphaSurfaceView_00462320` `84/88 -> 85/90`; `0000PV g_browserWindowClassName` `84/88 -> 85/90`; `0001V9 ModelessDialogPaneLayout` `82/88 -> 85/90`.
- Owner/emitter changes: no UID route changes. Routes remain `0000TZ -> 0000NT -> SoftwareBlend16.cpp`, `0000U3 -> 0000HF -> AlphaMaskSurface.cpp`, `0000PV -> 0000HV -> Browser.cpp`, and `0001V9 -> 00008K -> ModelessDialogPane.cpp`. Identity repair: [UID:0000PV] was renamed from `g_browserWindowCaption` to `g_browserWindowClassName` after live IDA showed the string is a browser host class-name literal.
- Evidence: live IDA MCP database `a001_goal2_class_batch` on 2026-06-14 reconfirmed BlendRgb555 size/end padding, thirteen compatibility-render xrefs, no-callee one-block RGB555 formula; clipped alpha-view size/end padding, one StaticObjImageLib caller, rectangle-helper callees, and `0x00462320-0x004623b5` endpoint; BrowserWindow constructor string flow through `ClassName`, `RegisterClassA`, and `CreateWindowExA` class-name argument; and ModelessDialogPane constructor/IsModal/handler sizes, vtable refs, secondary-view `this - 0xa0` adjustment, and post-handler jump-table boundary. Numeric conversions were checked with `int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <changed doc/report> --apply --queue-timeout 240` was run for all ten changed docs/reports and exited `0` with `ok: 1` for each. `rg -n "0000TZ|0000U3|0000PV|0001V9" project-level/-auto-completion-stats.md` returned no matches; generated coverage shows the renamed global at `by-global/g_browserWindowClassName.md`.
- Leases used: success for all changed docs/reports and this notes file. Initial leases expired during the edit pass; A001 re-leased the complete edited set before validation and notes finalization.
- Blockers: none. Final C++ remains blank for all four targets because source-quality names/signatures/declarations or final source split details are still unresolved despite the minimum score/emitter gate clearing. `by-memory/-coverage-report.md` was not edited and no supervisor-owned memory coverage row is pending for this batch.

## 2026-06-14 Goal 2 DataSection Section Container

- Changed docs: `by-memory/0x0066d000-0x0069d000.DataSection.md` and this `notes.md`.
- Scores: [UID:0001Z8] `72/89 -> 85/90`.
- Owner/emitter/path changes: none. `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ remain correct because the `.data` section page is an audit/index container, not a source-level object.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 confirmed `NexusTK.exe` `.data` segment `0x0066d000-0x0069d000`, size `0x30000`, permissions `rw`, zero functions, 1,702 names/globals, and 952 strings. Current memory coverage block was reparsed as 227 immediate child rows, 63 nested rows, 187 reconstructable direct rows, 6 not-reconstructable direct rows, 34 ignored direct rows, and no immediate unknown/uncovered rows.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0066d000-0x0069d000.DataSection.md --apply --queue-timeout 240` exited `0` with `ok: 1`, `completion_update: 1`, `confidence_update: 1`, and removed [UID:0001Z8] from `Low_Completion`, `Low_Both`, and the `by-memory` low-score list. `rg -n "0001Z8|DataSection|0x0066d000-0x0069d000" project-level/-auto-completion-stats.md` returned no matches.
- Leases used: success for the DataSection page and this notes file.
- Blockers: none for the section container. Direct `.data` child-source follow-up remains useful for low-completion direct children such as [UID:00027B], [UID:00027W], [UID:000291], [UID:000293], [UID:0002AD], [UID:0002AQ], and [UID:0001Q4].

## Supervisor-Applied Shared Rows

- Supervisor applied and validated the Goal 2 [UID:0001Z8] `by-memory/-coverage-report.md` replacement row on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 DataSection supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## 2026-06-14 Goal 2 DataSection Child Score Batch

- Batch: `A001-goal2-datasection-child-score-20260614-1`.
- Changed docs: `by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md`, support `by-memory/0x0066d000-0x0069d000.DataSection.md`, and this `notes.md`.
- Scores: [UID:00027B] `78/86 -> 85/88`; [UID:00027W] remains `85/85`; [UID:000291] remains `87/91`; [UID:000293] remains `88/91`; support [UID:0001Z8] remains `85/90`.
- Owner/emitter/path changes: none. [UID:00027B] stays `CANONICAL_OWNER:0000J7`, `EMITTER_UIDS:0000J7`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_POSITION_OPTIONAL`, and blank final C++. [UID:00027W] stays routed to `0000KU`; [UID:000291] and [UID:000293] stay routed to `0000HG`. Support [UID:0001Z8] stays `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank final C++.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed [UID:00027B] initial bytes at `0x0066d880`, exact `0x8`/8-byte size, zero padding through `0x0066d887`, successor table bytes at `0x0066d888`, exactly three data xrefs inside `sub_4A6C40`, no xref to padding byte `0x0066d881`, successor boundary xref from `sub_4A8B40`, two callers to `sub_4A6C40` from `sub_464CD0`, and the timer-refresh/reset behavior in analyze/decompile/disasm output.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for [UID:00027B] and support [UID:0001Z8] and exited `0` with `ok: 1` for each. The validator reported `completion_update 00027B 85`, `confidence_update 00027B 88`, and `stats_incremental_noop` because [UID:00027B] was not present in generated stats lists; `rg -n "00027B|00027W|000291|000293|0001Z8" project-level/-auto-completion-stats.md` returned no matches.
- Validator-generated files changed: `project-level/-auto-completion-stats.md` and `auto-generated/-ag-memory-coverage.md`; generated memory coverage now shows [UID:00027B] as `emits` through `0000J7 -> auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.
- Leases used: success for [UID:00027B], support [UID:0001Z8], and this notes file. The first lease invocation also passed rejected reason tokens, but the two intended file leases were successfully recorded before editing.
- Blockers: no documentation blocker for [UID:00027B]. Final C++ remains blank because the variable name and exact `ApplicationHelper_4A6C40` versus future `MessageLoopScheduler` source split remain below source-quality evidence. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

- Supervisor applied and validated the [UID:00027B], [UID:00027W], [UID:000291], and [UID:000293] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A001 Goal 2 DataSection Child Score Batch `00027B/00027W/000291/000293` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied row text:

Replace the existing [UID:00027B] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) 0x0066d880-0x0066d888 | global flag plus padding | ApplicationIdleSchedulerStaticFlag : reconstructable : 85% : strong : One-byte timer/idle scheduler flag plus padding with live IDA-confirmed initial bytes, exact 0x8/8-byte span, three scheduler xrefs in sub_4A6C40, no padding-byte xrefs, successor EventMan table boundary at 0x0066d888, caller context from Application::RunMessageLoop, and owner/emitter route through EventDispatcher.
```

Replace the existing [UID:00027W] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027W][0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC](by-memory/0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md) 0x0066decc-0x0066dee0 | mutable word slots | LivingObjectPaneSharedWordSlots : reconstructable : 85% : strong : Child page now clears the 85 gate with IDA-backed evidence for five live 0x0050 word slots, two writer routines, five provisional 0x0028 tail words with no direct xrefs, exact predecessor/successor boundaries, LivingObjectPane parent-gate rationale, and source-declared/generated-binary rebuild handling while final slot names remain provisional.
```

Replace the existing [UID:000291] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:000291][0x0067a980-0x0067a998.ApplicationTimingBaselines](by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md) 0x0067a980-0x0067a998 | timing globals | ApplicationTimingBaselines : reconstructable : 87% : very strong : Application timer baselines and skew counter with constructor initialization, heartbeat/timer health-check use, live IDA-backed read/write evidence, and Application owner/emitter route; final C++ remains blank pending source-quality names and declarations.
```

Replace the existing [UID:000293] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:000293][0x0067a9c0-0x0067ab18.ApplicationOsVersionState](by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md) 0x0067a9c0-0x0067ab18 | application OS state | ApplicationOsVersionState : reconstructable : 88% : very strong : OSVERSIONINFOW storage plus formatted short OS label buffer initialized by the Application constructor, with field-level layout, initialization/use evidence, and Application owner/emitter route documented; final C++ remains blank pending exact declaration spelling.
```

## 2026-06-14 Goal 2 DataSection Child Score Batch 2

- Batch: `A001-goal2-datasection-child-score-20260614-2`.
- Changed docs: `by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md`, `by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md`, `by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md`, `by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md`, and this `notes.md`.
- Scores: [UID:00027I] `82/84 -> 85/85`; [UID:00027N] `82/90 -> 85/90`; [UID:00027O] `82/90 -> 85/90`; [UID:00027P] `84/90 -> 85/90`.
- Owner/emitter/path changes: none. [UID:00027I], [UID:00027N], and [UID:00027O] remain `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3`, routing to `auto-generated/NexusTK/map/MapPane.cpp`; [UID:00027P] remains `CANONICAL_OWNER:0000MS`, `EMITTER_UIDS:0000MS`, routing to `auto-generated/NexusTK/profile/ProfileStorage.cpp`. All four remain `RECONSTRUCTABLE:TRUE` with blank `EMITTER_POSITION_OPTIONAL` and blank final C++.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed exact bytes and xrefs for all four targets; current owner files [UID:0000L3] MapPane, [UID:0000MS] ProfileStorage, and [UID:0000KH] ItemObjImageLib clear the 85/85 support gate. [UID:00027I] still has mixed MapPane/item-image use and nine no-xref constants, so it only moves to `85/85`. [UID:00027N] has eight table-base refs, modeled and unmodeled checksum consumers, `0x100`/256 entries, and a `0x200`/512-byte table body. [UID:00027O] has exact two eight-byte mask tables, four refs, modeled movement/occupancy behavior, and two unmodeled accessor bodies. [UID:00027P] has five pointer entries, UTF-16 extension strings, one indexed table-base ref inside `sub_5063E0`, no direct refs to trailing entries/padding, and separate successor refs.
- Numeric conversions: `0x4a == 74`, `0x204 == 516`, `0x10 == 16`, `0x18 == 24`, `0x14 == 20`, `0x100 == 256`, and `0x200 == 512` were checked with `tools/int_convert.py`; the first multi-value invocation treated the full list as one invalid value, then each value was rerun individually and succeeded.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all four changed target docs and exited `0`; each run reported `ok: 1`. The first run reported `completion_update 00027I 85` and `confidence_update 00027I 85`; the later runs completed in the same validation loop. `rg -n "00027I|00027N|00027O|00027P" project-level/-auto-completion-stats.md` returned no matches. Generated memory coverage shows [UID:00027I]/[UID:00027N]/[UID:00027O] emitting through `0000L3 -> auto-generated/NexusTK/map/MapPane.cpp` and [UID:00027P] through `0000MS -> auto-generated/NexusTK/profile/ProfileStorage.cpp`.
- Leases used: success for all four target docs and this notes file.
- Blockers: no documentation blocker for reaching the 85 gate. Final C++ remains blank for all four because final symbol names, source declarations, algorithm/source-generation style, direction-index names, or MapPane versus item-image split details are not source-quality. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

- Supervisor applied and validated the [UID:00027I], [UID:00027N], [UID:00027O], and [UID:00027P] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A001 Goal 2 DataSection Child Score Batch `00027I/00027N/00027O/00027P` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied row text:

Replace the existing [UID:00027I] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027I][0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants](by-memory/0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants.md) 0x0066daa2-0x0066daec | initialized coordinate/constants data | MapPaneCoordinateClampConstants : reconstructable : 85% : strong : Current live IDA documents exact 0x4a/74-byte layout, MapPane coordinate xrefs in sub_50C120, item-image remap xrefs in sub_4DEFC0/sub_4DF2C0/sub_4DF460, no-xref leading/trailing constants, clean empty-string boundary, and MapPane owner/emitter route; final names and the mixed MapPane/item-image split remain open.
```

Replace the existing [UID:00027N] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027N][0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable](by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md) 0x0066db4c-0x0066dd50 | checksum lookup table | MapPaneChecksumLookupTable : reconstructable : 85% : strong : Four unreferenced leading zero bytes plus a 0x200/512-byte, 0x100/256-entry 16-bit checksum table; live IDA documents exact bytes, eight MapPane table-base refs, modeled sub_50C040 checksum-loop behavior, unmodeled 0x0050c100 helper, unmodeled 0x00513930 packet/status path, and clean direction-mask successor boundary.
```

Replace the existing [UID:00027O] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027O][0x0066dd50-0x0066dd60.MapObjectDirectionMasks](by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md) 0x0066dd50-0x0066dd60 | byte mask tables | MapObjectDirectionMasks : reconstructable : 85% : strong : Two eight-byte MapPane direction/mask tables with exact 0x10/16-byte layout, four direct table refs, sub_505430 movement/occupancy behavior, unmodeled accessors at 0x0050c430 and 0x0050c450, and clean checksum-table/profile-pointer boundaries.
```

Replace the existing [UID:00027P] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) 0x0066dd60-0x0066dd78 | pointer table | ImageExtensionPointerTable : reconstructable : 85% : strong : Five-entry ProfileStorage image-sidecar extension pointer table for bmp, pcx, jpg, jpeg, and pnm, with current live IDA evidence for exact 0x18/24-byte layout, 0x14/20-byte pointer list, UTF-16 target strings, indexed sub_5063E0 table-base ref, no direct refs to trailing entries/padding, and clean day/night-float successor boundary.
```

## 2026-06-14 Goal 2 DataSection Child Score Batch 3

- Batch: `A001-goal2-datasection-child-score-20260614-3`.
- Changed docs: `by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md`, `by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md`, `by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md`, `by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md`, and this `notes.md`.
- Scores: [UID:00027Q] `84/90 -> 85/90`; [UID:0001OL] `82/86 -> 85/88`; [UID:00027S] `82/88 -> 85/90`; [UID:00027U] `82/86 -> 85/88`.
- Owner/emitter/path changes: none. [UID:00027Q] remains `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3`, routing to `auto-generated/NexusTK/map/MapPane.cpp`; [UID:0001OL] remains `CANONICAL_OWNER:0000LC`, `EMITTER_UIDS:0000LC`, routing to `auto-generated/NexusTK/metadata/MetaMan.cpp`; [UID:00027S] remains `CANONICAL_OWNER:0000LG`, `EMITTER_UIDS:0000LG`, routing to `auto-generated/NexusTK/app/MiscWorkThread.cpp`; [UID:00027U] remains `CANONICAL_OWNER:0000LK`, `EMITTER_UIDS:0000LK`, routing to `auto-generated/NexusTK/render/MonsterImageLibTables.cpp`. All four remain `RECONSTRUCTABLE:TRUE` with blank `EMITTER_POSITION_OPTIONAL` and blank final C++.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed exact bytes and xrefs for all four targets; current owner files [UID:0000L3] MapPane, [UID:0000LC] MetaMan, [UID:0000LG] MiscWorkThread, and [UID:0000LK] MonsterImageLibTables clear the 85/85 support gate. [UID:00027Q] has the exact 24-float day/night curve, four direct refs, modeled dispatcher/map-state uses, duplicate unmodeled helper/body refs, and pointer-table/MD5 boundaries. [UID:0001OL] has the 24-byte static `SimpleUString` layout, construction/destruction wrappers, field refs, MetaMan alias lookup uses, and NCA URL successor boundary. [UID:00027S] has the 60-byte bitwise-not encoded URL, 59 printable decoded bytes plus terminator, two `ProcessNCAUpdate` refs, no interior xrefs, and padding/successor split. [UID:00027U] has the 12-byte fallback span, 10-byte active frame record plus two alignment bytes, two getter-helper refs, no interior xrefs, initializer match, and `RootPathName`/LivingObjectPane boundaries.
- Numeric conversions: `0x60 == 96`, `0x18 == 24`, `0x20 == 32`, `0x3c == 60`, `0x3b == 59`, `0x0c == 12`, `0x0a == 10`, and `0x44 == 68` were checked with `tools/int_convert.py`.
- Validation: `python .\tools\validator.py --mode file --file <edited by-memory doc> --apply --queue-timeout 240` was run for all four changed target docs and exited `0`; each run reported `ok: 1`. The runs reported `completion_update 00027Q 85`, `completion_update 0001OL 85`, `confidence_update 0001OL 88`, `completion_update 00027S 85`, `confidence_update 00027S 90`, `completion_update 00027U 85`, and `confidence_update 00027U 88`. The [UID:00027S] run also normalized one UID link label from `MiscWorkThreadAndNotifications` to `0x005277c0-0x005285dd.MiscWorkThreadAndNotifications`. Each run reported `stats_incremental_noop` for the target because the file was not present in generated stats lists and `projected_stats_update` for `project-level/-auto-completion-stats.md`.
- Leases used: success for all four target docs and this notes file.
- Blockers: no documentation blocker for reaching the 85 gate. Final C++ remains blank for all four because final symbol names, duplicate helper/source placement, source-authored encoded-vs-plain literal choice, frame-entry type names, or exact source declarations are not source-quality. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

- Supervisor applied and validated the [UID:00027Q], [UID:0001OL], [UID:00027S], and [UID:00027U] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A001 Goal 2 DataSection Child Score Batch `00027Q/0001OL/00027S/00027U` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied row text:

Replace the existing [UID:00027Q] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027Q][0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable](by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md) 0x0066dd78-0x0066ddd8 | float lookup table | MapPaneDayNightFloatTable : reconstructable : 85% : strong : 0x60/96-byte, 24-float MapPane day/night curve with exact bit patterns, four direct table refs, dispatcher/raw-body/modeled-handler contexts, unmodeled helper behavior, and clean pointer-table/MD5 boundaries; final symbol name and duplicate helper placement remain open.
```

Replace the existing [UID:0001OL] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) 0x0066de18-0x0066de30 | static SimpleUString object | g_metaAliasTableName : reconstructable : 85% : strong : 0x18/24-byte static SimpleUString metadata alias lookup key with exact layout, constructor/destructor wrappers, length/capacity refs, MetaMan alias lookup uses, and clean NCA URL successor boundary; final source spelling and alias key literal remain unresolved.
```

Replace the existing [UID:00027S] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md) 0x0066de30-0x0066de6c | obfuscated URL literal | NcauthConfirmUserUrlObfuscated : reconstructable : 85% : strong : 0x3c/60-byte bitwise-not encoded NCA confirm-user fallback URL, decoding to 59 printable bytes plus terminator, with two ProcessNCAUpdate refs, no interior xrefs, exact padding/successor boundaries, and MiscWorkThread owner/emitter route.
```

Replace the existing [UID:00027U] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) 0x0066deb0-0x0066debc | fallback frame record | MonsterImageLibDefaultFrameRecord : reconstructable : 85% : strong : 0x0c/12-byte monster/riding fallback frame span with 10-byte active record plus two alignment bytes, direct refs from sub_528B10 and sub_528D00, no interior xrefs, initializer match, and RootPathName/LivingObjectPane successor boundaries.
```

## 2026-06-14 Goal 2 DataSection Singleton Pointer Score Batch 4

- Batch: `A001-goal2-datasection-singleton-score-20260614-4`.
- Changed docs: `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`, `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`, `by-memory/0x0067a754-0x0067a758.g_pEventMan.md`, `by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md`, `by-global/g_pNewHumanImageLib.md`, and this `notes.md`.
- Scores: [UID:00028I] `84/88 -> 85/88`; [UID:00028J] `84/90 -> 85/90`; [UID:00028L] `84/90 -> 85/90`; [UID:0001OV] `84/90 -> 85/90`. [UID:0000RT] support page score unchanged at `85/88`.
- Owner/emitter/path changes: none. [UID:00028I] remains `CANONICAL_OWNER:0000JE`, `EMITTER_UIDS:0000JE`, routing to `auto-generated/NexusTK/cashshop/FittingRoom.cpp`; [UID:00028J] remains `CANONICAL_OWNER:0000HO`, `EMITTER_UIDS:0000HO`, routing to `auto-generated/NexusTK/map/BackPane.cpp`; [UID:00028L] remains `CANONICAL_OWNER:0000J6`, `EMITTER_UIDS:0000J6`, routing to `auto-generated/NexusTK/ui/core/Event.cpp`; [UID:0001OV] remains `CANONICAL_OWNER:0000RT`, `EMITTER_UIDS:0000RT`, routing through [UID:0000RT] to `auto-generated/NexusTK/render/NewHumanImageLib.cpp`. All four remain `RECONSTRUCTABLE:TRUE` with blank `EMITTER_POSITION_OPTIONAL` and blank final C++.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed active `NexusTK.exe.i64`, ready Hex-Rays/auto-analysis, all-zero `0x0067a738-0x0067a768` singleton window, target xref totals, representative lifecycle function ownership, and decompiled constructor publish/guard-clear behavior for FittingRoomDialog, BackPane, EventMan, and NewHumanImageLib. Numeric conversions including `0x4 == 4`, `0x30 == 48`, `16 == 0x10`, `106 == 0x6a`, `52 == 0x34`, `210 == 0xd2`, `1152 == 0x480`, `190 == 0xbe`, `979 == 0x3d3`, and `1338 == 0x53a` were checked with `tools/int_convert.py`.
- Validation: scoped file validation was run for all four changed target docs and the changed support doc; every command exited `0` with `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a73c-0x0067a740.g_pFittingRoomDialog.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 00028I ... 85`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a740-0x0067a744.g_pBackPane.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 00028J ... 85`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a754-0x0067a758.g_pEventMan.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 00028L ... 85`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067a760-0x0067a764.g_pNewHumanImageLib.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0001OV ... 85`.
  - `python .\tools\validator.py --mode file --file by-global\g_pNewHumanImageLib.md --apply --queue-timeout 240` -> `ok: 1`; support-text sync only, no score change.
  - Each run rebuilt the validator registry and updated projected stats as normal; auto-generated coverage reports were `noop`.
- Leases used: success for all four target docs, support [UID:0000RT], and this notes file.
- Blockers: no documentation blocker for reaching the 85 completion gate. Final C++ remains blank for all four targets because original declaration spelling, final pointer types, adjusted receiver/class-layout details, EventMan field names, or full consumer classification are not source-quality. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

- Supervisor applied and validated the [UID:00028I], [UID:00028J], [UID:00028L], and [UID:0001OV] replacement rows on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A001 Goal 2 DataSection Singleton Pointer Score Batch `00028I/00028J/00028L/0001OV` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

Applied row text:

Replace the existing [UID:00028I] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00028I][0x0067a73c-0x0067a740.g_pFittingRoomDialog](by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md) 0x0067a73c-0x0067a740 | global pointer | g_pFittingRoomDialog : reconstructable : 85% : strong : FittingRoomDialog singleton pointer with zeroed 0x4/4-byte storage, 16 direct xrefs, constructor publish/guard-clear decompilation in sub_41BDD0, cleanup/destructor clears, fitting-room request/list-pane readers, UserPane open-state check, and FittingRoom owner/emitter route.
```

Replace the existing [UID:00028J] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md) 0x0067a740-0x0067a744 | global pointer | g_pBackPane : reconstructable : 85% : strong : BackPane root/backdrop singleton pointer with zeroed 0x4/4-byte storage, 106 direct xrefs, constructor publish/guard-clear decompilation, destructor/reset clears, InitializeMainUiGraph constructor call sites, broad pane/dialog parent-context reads, and BackPane owner/emitter route.
```

Replace the existing [UID:00028L] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md) 0x0067a754-0x0067a758 | global pointer | g_pEventMan : reconstructable : 85% : strong : EventMan singleton pointer with zeroed 0x4/4-byte storage, 210 direct xrefs, constructor publish/guard-clear decompilation, destructor/helper/deleting-destructor clears, key-translation-table copies, Main_WndProc and UI/input consumers, and Event owner/emitter route.
```

Replace the existing [UID:0001OV] row under the [UID:0001Z8] `.data` section child list with:

```text
    - [UID:0001OV][0x0067a760-0x0067a764.g_pNewHumanImageLib](by-memory/0x0067a760-0x0067a764.g_pNewHumanImageLib.md) 0x0067a760-0x0067a764 | global pointer | g_pNewHumanImageLib : reconstructable : 85% : strong : NewHumanImageLib singleton pointer with zeroed 0x4/4-byte storage, 52 direct xrefs, constructor publish/guard-clear decompilation, destructor/helper clears, Application::Shutdown read, representative render/look/profile consumers, and g_pNewHumanImageLib owner/emitter route.
```

## 2026-06-14 Goal 2 DataSection Singleton Pointer Score Batch 5

- Batch: `A001-goal2-datasection-singleton-score-20260614-5`.
- Changed docs: `by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md`, `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`, `by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md`, `by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md`, `by-global/g_pMidiPlayer.md`, `by-global/g_pSimpleHelpPane.md`, and this `notes.md`.
- Scores: [UID:00029A] `84/88 -> 85/88`; [UID:0001P9] `82/84 -> 85/86`; [UID:0002B9] `84/90 -> 85/90`; [UID:0001PC] `84/88 -> 85/88`; support [UID:0000RM] `84/88 -> 85/88`; support [UID:0000S9] `84/88 -> 85/88`.
- Owner/emitter/path changes: none. [UID:00029A] remains `CANONICAL_OWNER:0000RM`, `EMITTER_UIDS:0000RM`, routing through [UID:0000RM] to `auto-generated/NexusTK/audio/MidiPlayer.cpp`; [UID:0001P9] remains `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, routing to `auto-generated/NexusTK/browser/Browser.cpp`; [UID:0002B9] remains `CANONICAL_OWNER:0000IF`, `EMITTER_UIDS:0000IF`, routing to `auto-generated/NexusTK/network/ConnStatusPane.cpp`; [UID:0001PC] remains `CANONICAL_OWNER:0000S9`, `EMITTER_UIDS:0000S9`, routing through [UID:0000S9] to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`. All four target docs remain `RECONSTRUCTABLE:TRUE` with blank `EMITTER_POSITION_OPTIONAL` and blank final C++.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed active `NexusTK.exe.i64`, imagebase `0x00400000`, ready auto-analysis/Hex-Rays/strings cache, current zero-filled singleton windows at `0x0067ab48-0x0067ab8c` and `0x0069adf0-0x0069ae10`, target xref totals, lifecycle function ownership, and decompiled constructor publish/guard-clear or destructor/read behavior for all four targets. Numeric conversions checked include `0x4 == 4`, `0x44 == 68`, `0x20 == 32`, `18 == 0x12`, `8 == 0x8`, `4 == 0x4`, `23 == 0x17`, `0xe6 == 230`, `0x8d == 141`, `0x46e == 1134`, `0x190 == 400`, `0xc0 == 192`, `0x29 == 41`, `0x5f == 95`, `0x37b == 891`, `0x2f7 == 759`, `0x77 == 119`, `0xb == 11`, `0xb8 == 184`, and `100 == 0x64`.
- Validation: scoped file validation was run for all four changed target docs and the two changed support docs; every command exited `0` with `ok: 1`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067ab4c-0x0067ab50.g_pMidiPlayer.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 00029A ... 85`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0067ab84-0x0067ab88.g_activeBrowserPane.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0001P9 ... 85`, `confidence_update 0001P9 ... 86`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0069adf4-0x0069adf8.g_pConnStatusPane.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0002B9 ... 85`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0001PC ... 85`.
  - `python .\tools\validator.py --mode file --file by-global\g_pMidiPlayer.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0000RM ... 85`.
  - `python .\tools\validator.py --mode file --file by-global\g_pSimpleHelpPane.md --apply --queue-timeout 240` -> `ok: 1`, `completion_update 0000S9 ... 85`.
  - Each run rebuilt the validator registry and updated projected stats as normal; auto-generated coverage reports were `noop`.
- Leases used: success for all four target docs, support [UID:0000RM], support [UID:0000S9], and this notes file.
- Blockers: no documentation blocker for reaching the 85 completion gate. Final C++ remains blank because final declaration spelling, header/source placement, browser active-owner static type and lifetime clear path, ConnStatusPane final `network/` versus `ui/status/` placement, or HelpPanes source split are still not source-quality. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; supervisor applied and validated the exact replacement rows below on 2026-06-14.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

Placement context: replaced the existing [UID:00029A], [UID:0001P9], [UID:0002B9], and [UID:0001PC] rows under the [UID:0001Z8] `.data` section child list. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.

```text
    - [UID:00029A][0x0067ab4c-0x0067ab50.g_pMidiPlayer](by-memory/0x0067ab4c-0x0067ab50.g_pMidiPlayer.md) 0x0067ab4c-0x0067ab50 | global pointer | g_pMidiPlayer : reconstructable : 85% : strong : MidiPlayer singleton pointer with current zero-filled 0x4/4-byte storage, 18 direct xrefs, constructor publish/guard-clear decompilation, destructor stream/event cleanup clear, representative Application/main-menu/SoundStatusPane/playback-helper consumers, and g_pMidiPlayer/MidiPlayer owner-emitter route.
    - [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md) 0x0067ab84-0x0067ab88 | global-data | g_activeBrowserPane : reconstructable : 85% : strong : Browser active owner/callback pointer with current zero-filled 0x4/4-byte storage, exactly 8 direct xrefs, BrowserControlPane constructor publication, accelerator/Escape and dispatch-event consumers, no direct clear xref found, and Browser owner-emitter route.
    - [UID:0002B9][0x0069adf4-0x0069adf8.g_pConnStatusPane](by-memory/0x0069adf4-0x0069adf8.g_pConnStatusPane.md) 0x0069adf4-0x0069adf8 | global-data pointer | g_pConnStatusPane : reconstructable : 85% : strong : ConnStatusPane singleton pointer with current zero-filled 0x4/4-byte storage, exact four-ref xref set, constructor publish, reset/destructor clears, main cleanup read, neighboring singleton-slot boundaries, and ConnStatusPane owner-emitter route.
    - [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) 0x0069ae00-0x0069ae04 | global pointer | g_pSimpleHelpPane : reconstructable : 85% : strong : SimpleHelpPane singleton pointer with current zero-filled 0x4/4-byte storage, 23 direct refs, constructor publish/guard-clear decompilation, ordinary/helper/scalar-destructor clears, close-helper read, tooltip feature consumers, and g_pSimpleHelpPane/HelpPanes owner-emitter route.
```

## 2026-06-14 Goal 2 DataSection Global Score Batch 6

- Batch: `A001-goal2-datasection-global-score-20260614-6`.
- Changed docs: `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`, `by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md`, `by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md`, `by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md`, `by-file/AesBlockCipher.md`, `by-global/AesBlockCipherStateAndTables.md`, and this `notes.md`.
- Scores: [UID:0001OR] `84/86 -> 85/86`; [UID:00028Y] `84/91 -> 85/91`; [UID:0002AZ] `84/88 -> 85/88`; [UID:00030A] remains `87/89`. Support [UID:00020J] remains `88/91`; support [UID:00020K] remains `84/92`.
- Owner/emitter/path changes: none. [UID:0001OR] remains `CANONICAL_OWNER:0000P1`, `EMITTER_UIDS:0000P1`, routing to `auto-generated/NexusTK/ui/panels/UserPane.cpp`; [UID:00028Y] remains `CANONICAL_OWNER:00020J`, `EMITTER_UIDS:00020J`, routing to `auto-generated/NexusTK/util/AesBlockCipher.cpp`; [UID:0002AZ] remains `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3`, routing to `auto-generated/NexusTK/map/MapPane.cpp`; [UID:00030A] remains `CANONICAL_OWNER:0000P1`, `EMITTER_UIDS:0000P1`, routing to `auto-generated/NexusTK/ui/panels/UserPane.cpp`. Final C++ remains blank for all four target docs.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed active `NexusTK.exe.i64`, imagebase `0x00400000`, ready auto-analysis/Hex-Rays/string cache, target bytes/integers, xrefs, and representative function ownership. Current bytes/integers read as zero for all four target storage windows; this supersedes older all-`0xff` / `0xffffffff` initializer wording for [UID:00028Y], [UID:0002AZ], and [UID:00030A]. Raw PE section-offset sanity checks confirm the AES, MapPane flag, and opcode-slot ranges are in the zero-filled virtual tail of `.data`. Xrefs remain strong: [UID:0001OR] has 505 refs and UserPane lifetime writers; [UID:00028Y] has the 10/3/3/6 AES mutable-state refs; [UID:0002AZ] has exactly two MapPane render refs plus no tail refs and clean MessageShowPane/MemoryMan boundaries; [UID:00030A] has the exact two-ref writer set per dword, no interior byte refs, and successor refs at `0x0069bf74`.
- Numeric conversions checked through IDA MCP `int_convert`: `0xbc == 188`, `0x30 == 48`, `0x10 == 16`, `0x2d == 45`, and `0x104d == 4173`.
- Validation: `python .\tools\validator.py --mode file --file <changed doc> --apply --queue-timeout 240` was run for all four changed target docs and both changed AES support docs, then rerun with filtered output for concise capture. Every validation exited `0` with `ok: 1`. The first pass reported completion updates for [UID:0001OR], [UID:00028Y], and [UID:0002AZ] to `85`; [UID:00030A], [UID:00020J], and [UID:00020K] were text/evidence syncs with no score change. Each run rebuilt the autogen registry, left generated reports unchanged, and updated projected stats as normal.
- Leases used: success for all four target docs, support [UID:00020J], support [UID:00020K], and this notes file.
- Blockers: no score/routing blocker for the three 84% target docs reaching 85 completion. Final C++ remains blank because final source-facing declaration names/types, AES static/context API shape, MapPane config-field/flag naming, and opcode helper/slot variable names are not source-quality. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; supervisor applied and validated the exact replacement rows below on 2026-06-14.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement Rows

Placement context: replaced the existing [UID:0001OR], [UID:00028Y], [UID:0002AZ], and [UID:00030A] rows under the [UID:0001Z8] `.data` section child list. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.

```text
    - [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md) 0x0067a748-0x0067a74c | global pointer | g_pCollectionData : reconstructable : 85% : strong : UserPane/local-player state pointer with zero-filled 0x4/4-byte storage, 505 direct xrefs, UserPane constructor/fallback/destructor/helper/deleting-destructor lifetime writes, typed collection/spell/item/gold/player-name views, clean neighboring pointer boundaries, and g_pCollectionData/UserPane owner-emitter route.
    - [UID:00028Y][0x0067a878-0x0067a934.AesMutableStateAndKeySchedule](by-memory/0x0067a878-0x0067a934.AesMutableStateAndKeySchedule.md) 0x0067a878-0x0067a934 | AES mutable state | AesMutableStateAndKeySchedule : reconstructable : 85% : strong : AES/CBC mutable state and expanded AES-128 key-schedule storage with exact 0xbc/188-byte .data range, current zero-filled bytes, xref-bounded range rationale, raw wrapper pointer/chaining writes, key-schedule read/write offsets, AES helper-island confinement, and AesBlockCipher owner-emitter route.
    - [UID:0002AZ][0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag](by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md) 0x0069b4f8-0x0069b4f9 | global-data flag | MapPaneRenderScratchFlag : reconstructable : 85% : strong : One-byte MapPane render cache flag with current zero-filled storage, exact compare/store refs in sub_5094B0, config-byte dependency, refresh/invalidation path, ignored tail bytes, MessageShowPane/MemoryMan boundaries, and MapPane owner-emitter route.
    - [UID:00030A][0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots](by-memory/0x0069bf6c-0x0069bf74.Opcode2dCommandExtraValueSlots.md) 0x0069bf6c-0x0069bf74 | global-data | Opcode2dCommandExtraValueSlots : reconstructable : 87% : strong : Paired opcode 0x2d extra-value dwords with current zero-filled storage, exact four write refs, helper 0x005a4f70 packet-send/store behavior, inline UserPane::OnKeyEvent duplicate stores, no interior byte xrefs, UserPane file-level owner-emitter route, and final helper/name split still open.
```

## 2026-06-14 Goal 2 DataSection Global Score Batch 7

- Batch: `A001-goal2-datasection-global-score-20260614-7`.
- Changed docs: `by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`, `by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md`, `by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md`, `by-memory/0x0069b8bc-0x0069b8e4.StaticObjectPanePoolStaticStorage.md`, `by-global/g_pVirusChecker.md`, `by-file/VirusChecker.md`, `by-memory/0x0069b894-0x0069ba24.ObjectPanePoolStaticStorage.md`, and this `notes.md`.
- Scores: [UID:00030B] remains `86/88`; [UID:0001Q3] `82/88 -> 85/88`; [UID:0002WL] remains `85/91`; [UID:0002WM] remains `85/91`. Support [UID:0000SO] remains `86/90`; support [UID:0000P5] remains `86/85`; support [UID:0002B4] remains `86/90`.
- Owner/emitter/path changes: none. [UID:00030B] remains `CANONICAL_OWNER:0000KU`, `EMITTER_UIDS:0000KU`, routing to `auto-generated/NexusTK/map/LivingObjectPane.cpp`; [UID:0001Q3] remains `CANONICAL_OWNER:0000SO`, `EMITTER_UIDS:0000SO`, routing through [UID:0000SO] to `auto-generated/NexusTK/security/VirusChecker.cpp`; [UID:0002WL] remains `CANONICAL_OWNER:00007B`, `EMITTER_UIDS:00007B`, routing through [UID:00007B]/[UID:0000KU] to `auto-generated/NexusTK/map/LivingObjectPane.cpp`; [UID:0002WM] remains `CANONICAL_OWNER:0000E1`, `EMITTER_UIDS:0000E1`, routing through [UID:0000E1]/[UID:0000O6] to `auto-generated/NexusTK/map/StaticObjectPane.cpp`. Final C++ remains blank for all four target docs.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed active `NexusTK.exe.i64`, imagebase `0x00400000`, ready auto-analysis/Hex-Rays/string cache, target bytes/integers, xrefs, and representative function ownership. Current bytes/integers read as zero for all four target storage windows, and raw PE section-offset sanity checks place all four ranges in the zero-filled virtual tail of `.data`; this supersedes older all-`ff` / `0xffffffff` sampled-byte wording. Xrefs remain strong: [UID:00030B] has the two read-only refs in the orphan `0x005a9250` helper plus no interior byte refs; [UID:0001Q3] has five VirusChecker lifecycle refs plus a separate successor at `0x0069bf98`; [UID:0002WL] and [UID:0002WM] each have exact five-ref constructor/allocation/unwind/destructor/cleanup sets and verified `0x28` / 40-byte pool item size.
- Numeric conversions checked through IDA MCP `int_convert`: `0x28 == 40`, `0x20c == 524`, `0x20 == 32`, `0x12c == 300`, `0x10 == 16`, `0x64 == 100`, and `0xff == 255`.
- Validation: `python .\tools\validator.py --mode file --file <changed doc> --apply --queue-timeout 240` was run for all four changed target docs and all three changed support docs, then rerun with filtered output for concise capture. Every validation exited `0` with `ok: 1`. The first pass applied [UID:0001Q3] completion `85`; the other changed docs were evidence/current-byte syncs with no score changes. Each filtered run reported `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, `autogen_registry_rebuild`, and unchanged generated coverage reports.
- Leases used: success for all four target docs, support [UID:0000SO], support [UID:0000P5], support [UID:0002B4], and this notes file.
- Blockers: no score/routing blocker for [UID:0001Q3] reaching 85 completion. [UID:00030B] remains capped by the missing write/update site and orphan helper entrypoint; [UID:0002WL]/[UID:0002WM] remain capped by unresolved final static declaration spelling. Final C++ remains blank for all four targets. Supervisor applied the exact `by-memory/-coverage-report.md` replacement rows below on 2026-06-14.

Supervisor validation: ran `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002WL], [UID:0002WM], [UID:00030B], and [UID:0001Q3] replacement rows on 2026-06-14. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-14 Goal 2 By-Item Score Batch 8

- Batch: `A001-goal2-score-byitem-20260614-8`.
- Changed docs: `by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md`, `by-item/AlphaBlendSpan16Blocks_00460B00.md`, `by-item/CurlWriteCallback_00581B80.md`, `by-item/DeserializePredefinedFormArticleEntries_478650.md`, `by-item/-coverage-report.md`, and this `notes.md`.
- Scores: [UID:0000UL] remains `85/88`; [UID:0000TW] `84/90 -> 85/90`; [UID:0000UA] `84/88 -> 85/88`; [UID:0000UE] `84/88 -> 85/88`.
- Owner/emitter/path changes: none. [UID:0000UL] remains `CANONICAL_OWNER:0000J0`, `EMITTER_UIDS:0000J0`; [UID:0000TW] remains `CANONICAL_OWNER:0000NT`, `EMITTER_UIDS:0000NT`; [UID:0000UA] remains `CANONICAL_OWNER:0000O5`, `EMITTER_UIDS:0000O5`; [UID:0000UE] remains `CANONICAL_OWNER:0000LT`, `EMITTER_UIDS:0000LT`. Final C++ remains blank for all four targets.
- Evidence: live IDA MCP session `a001_goal2_class_batch` on 2026-06-14 reconfirmed active `NexusTK.exe.i64`, imagebase `0x00400000`, ready auto-analysis/Hex-Rays/string cache, exact target function sizes and xrefs. [UID:0000TW] has exact `0x00460b00-0x00460c0a`, size `0x10a` / 266, one caller at `0x004605fd`, MMX scratch qwords, and RGB565 masks. [UID:0000UA] has exact `0x00581b80-0x00581ce6`, size `0x166` / 358, two libcurl callback setup data refs in `sub_580870`, and SSO append setup. [UID:0000UE] has exact `0x00478650-0x00478932`, size `0x2e3` / 739, two constructor-only xrefs, and parser stack/setup evidence. [UID:0000UL] has reconfirmed modeled helper sizes, parser/quantity-dialog refs, and the same raw-island blockers at `0x004a3650`, `0x004a3be0`, and `0x004a3ca0`.
- Numeric conversions checked through IDA MCP `int_convert`: `0xe1 == 225`, `0x2cc == 716`, `0x174 == 372`, `0x14f == 335`, `0x247 == 583`, `0x166 == 358`, `0x2e3 == 739`, `0x10a == 266`, `0x41c == 1052`, and `0x107 == 263`.
- Coverage report: `by-item/-coverage-report.md` was directly updated and validated; no supervisor-owned row remains pending for this batch.
- Validation: `python .\tools\validator.py --mode file --file <changed doc> --apply --queue-timeout 240` was run for all four changed target docs plus `by-item/-coverage-report.md`, then rerun with filtered output. Every validation exited `0` with `ok: 1`. The first pass applied completion updates for [UID:0000TW], [UID:0000UA], and [UID:0000UE] to `85`; [UID:0000UL] and [UID:0000TR] were evidence/report syncs with no score change. Each filtered run reported `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, `autogen_registry_rebuild`, and unchanged generated coverage reports.
- Leases used: success for all four target docs, `by-item/-coverage-report.md`, and this notes file.
- Blockers: no target blocker for the three 84% pages reaching 85 completion. [UID:0000UL] remains capped by unresolved raw helper function boundaries and final helper names; [UID:0000TW], [UID:0000UA], and [UID:0000UE] remain without final C++ because source-quality signatures, helper split, and integration details are not fully proven.
## 2026-06-15 Goal 2 NewPredefinedFormArticle Memory Batch

Assignment: `A001-goal2-newpredefinedformarticle-memory-20260615-1`.

- Changed docs: `by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md`, `by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md`, `by-memory/0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md`, and this `notes.md`.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`) plus current parent/class/file docs and local `int_convert.py` checks for documented decimal constants.
- Score changes: [UID:0002UK] `78/86 -> 87/88`; [UID:0002UQ] `78/86 -> 86/88`; [UID:0002UL] `78/86 -> 86/87`.
- Owner/emitter/path decisions: no metadata route changes. All three remain `CANONICAL_OWNER:0000LT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000LT`, final C++ blank. Route is defensible through [UID:0000LT] `by-file/NewPredefinedFormArticleDialog.md` at `88/85` and [UID:000098] `by-class/NewPredefinedFormArticleDialog.md` at `85/86`; final C++ remains withheld because source-quality control, field, packet-helper, alert-helper, and declaration names are still unresolved.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x00478be0-0x00478f8e.NewPredefinedFormArticleDialogSubmitArticle.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- Blockers: none for clearing the `85/85` documentation gate. Remaining follow-up is source-quality naming/declaration work before adding final C++ for these methods.
- Leases used: A001 leased the three target docs and this notes file before edits. Post-validation unlease returned `Rejected[No active lease]` for all four paths because the leases were no longer active by release time; `current_leases.md` should be the final authority and showed no active A001 target leases in the final check.

### Supervisor-applied `by-memory/-coverage-report.md` rows

Supervisor applied the exact [UID:0002UK], [UID:0002UQ], and [UID:0002UL] replacement rows under [UID:0000ZL] on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-15 Goal 2 Exchange/FolderTree Memory Batch

Assignment: `A001-goal2-exchange-foldertree-memory-20260615-1`.

- Changed docs: `by-memory/0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md`, `by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md`, `by-memory/0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md`, `by-memory/0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`) plus current ExchangeDialog/FolderTreePane parent/support docs and local `tools/int_convert.py` checks for documented decimal constants.
- Score changes: [UID:00014N] `78/86 -> 85/88`; [UID:00014R] `78/86 -> 85/87`; [UID:000156] `78/86 -> 86/88`; [UID:00022E] `78/86 -> 86/88`.
- Owner/emitter/path decisions: no metadata route changes. [UID:00014N] and [UID:00014R] remain `CANONICAL_OWNER:0000J9`, `EMITTER_UIDS:0000J9`, routing through `auto-generated/NexusTK/ui/dialogs/ExchangeDialog.cpp`. [UID:000156] and [UID:00022E] remain `CANONICAL_OWNER:0000JG`, `EMITTER_UIDS:0000JG`, routing through `auto-generated/NexusTK/ui/controls/FolderTreePane.cpp`. Final C++ remains blank for all four targets.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004adca0-0x004add33.ExchangeDialogRawMoneyUpdate.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004b3210-0x004b32c9.FolderTreePaneSetSelection.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004b5c40-0x004b5efc.FolderTreePaneVectorSupportHelpers.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits; initial leases expired during context compaction, then were refreshed successfully before validation/notes update.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:00014N] and [UID:00014R] by raw helper/function-boundary and source-shape uncertainty; final C++ remains blocked for [UID:000156] and [UID:00022E] by source-quality field/template/helper names and declaration placement. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:00014N], [UID:00014R], [UID:000156], and [UID:00022E] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-15 Goal 2 Icons/SimpleHelp Memory Batch

Assignment: `A001-goal2-icons-simplehelp-memory-20260615-1`.

- Changed docs: `by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md`, `by-memory/0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md`, `by-memory/0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md`, `by-memory/0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`, `insn_query`) plus current HelpPanes/SimpleHelpPane2 and IconsPane parent/support docs and local `tools/int_convert.py` checks for documented decimal constants.
- Score changes: [UID:00022O] `78/86 -> 85/88`; [UID:0002SY] `78/86 -> 86/88`; [UID:0002SZ] `78/86 -> 86/88`; [UID:0002T0] `78/86 -> 86/88`.
- Owner/emitter/path decisions: no metadata route changes. [UID:00022O] remains `CANONICAL_OWNER:0000JU`, `EMITTER_UIDS:0000JU`, routing through `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`. [UID:0002SY], [UID:0002SZ], and [UID:0002T0] remain `CANONICAL_OWNER:00006B`, `EMITTER_UIDS:00006B`, routing through [UID:0000JZ] to `auto-generated/NexusTK/ui/panels/IconsPane.cpp`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The live evidence was sufficient for documentation updates, and no safe database rename/comment/type change was necessary; the current MCP toolset also did not expose `py_eval`, so all IDA use stayed read-only inspection.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004cf290-0x004cf297.IconsPaneIsShowingAllIcons.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004cf2a0-0x004cf2c6.IconsPaneShowAllIcons.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004cf2d0-0x004cf2f6.IconsPaneShowReducedIcons.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits. A refresh attempt shortly before expiry returned `Rejected[Already has lease]`; the target leases then expired naturally, and A001 re-leased `notes.md` for this notes update.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:00022O] by raw helper-start/no-direct-xref evidence and unresolved final helper names/signatures/source visibility; final C++ remains blocked for the IconsPane methods by source-quality field/global declarations, invalidation helper naming, and class/header placement. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:00022O], [UID:0002SY], [UID:0002SZ], and [UID:0002T0] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## 2026-06-15 Goal 2 App/Browser/Employee Memory Batch

Assignment: `A001-goal2-app-browser-employee-memory-20260615-1`.

- Changed docs: `by-memory/0x00465300-0x00465308.ApplicationGetVersionMajor.md`, `by-memory/0x00465310-0x00465318.ApplicationGetVersionMinor.md`, `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md`, `by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `callees`, `get_bytes`) plus current Application/Browser/Employee parent/support docs and local `tools/int_convert.py` checks for documented decimal constants.
- Score changes: [UID:0002GP] `80/84 -> 85/88`; [UID:0002GQ] `80/84 -> 85/88`; [UID:0000Z5] `80/84 -> 85/87`; [UID:0002HF] `80/84 -> 86/88`.
- Owner/emitter/path decisions: no metadata route changes. [UID:0002GP] and [UID:0002GQ] remain `CANONICAL_OWNER:00000D`, `EMITTER_UIDS:00000D`, routing through [UID:0000HG] `Application`. [UID:0000Z5] remains `CANONICAL_OWNER:0000HV`, `EMITTER_UIDS:0000HV`, routing through [UID:0000HV] `Browser`. [UID:0002HF] remains `CANONICAL_OWNER:000138`, `EMITTER_UIDS:000138`, routing through [UID:000138] `EmployeeDialogPanes`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The live evidence was sufficient for documentation updates, no safe source-quality database rename/comment/type edit was necessary, and final names/declarations are still not proven.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00465300-0x00465308.ApplicationGetVersionMajor.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x00465310-0x00465318.ApplicationGetVersionMinor.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:0002GP]/[UID:0002GQ] by unresolved Application field/accessor names across license/version status and caller families; for [UID:0000Z5] by raw no-function/no-xref `0x0046a860` constructor handling and BrowserPane/BrowserDialog source split; and for [UID:0002HF] by unresolved helper/local/selected-record sprite field names. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002GP], [UID:0002GQ], [UID:0000Z5], and [UID:0002HF] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 App/Browser/Employee supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Low-Completion Memory Batch 2

Assignment: `A001-goal2-lowcompletion-memory-20260615-2`.

- Changed docs: `by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md`, `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`, `by-memory/0x00515310-0x00515375.Md5BytesHex.md`, `by-memory/0x00516000-0x0051600f.MemoryManConstructor.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `get_bytes`) plus current PlatformApi/Application/MD5/MemoryMan parent/support docs and local `tools/int_convert.py` checks for documented decimal constants.
- Score changes: [UID:00022V] `78/86 -> 85/87`; [UID:00019H] `78/86 -> 85/88`; [UID:0001B7] `78/86 -> 85/88`; [UID:0001B9] `78/86 -> 86/90`.
- Owner/emitter/path decisions: no metadata route changes. [UID:00022V] remains `CANONICAL_OWNER:0000ML`, `EMITTER_UIDS:0000ML`; [UID:00019H] remains `CANONICAL_OWNER:0000HG`, `EMITTER_UIDS:0000HG`; [UID:0001B7] remains `CANONICAL_OWNER:0000L6`, `EMITTER_UIDS:0000L6`; [UID:0001B9] remains `CANONICAL_OWNER:0000L7`, `EMITTER_UIDS:0000L7`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The live evidence was sufficient for documentation updates, and no safe database rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004f5b20-0x004f5c73.MapiSendMailHelper.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x00515310-0x00515375.Md5BytesHex.md --apply --queue-timeout 240` exited `0`, `ok: 1`; `python .\tools\validator.py --mode file --file by-memory\0x00516000-0x0051600f.MemoryManConstructor.md --apply --queue-timeout 240` exited `0`, `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits. The generated current-lease report was stale/empty after the initial lease, but `lease.json` showed active A001 leases and a second lease attempt returned `Rejected[Already has lease]`; A001 proceeded under those active leases.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:00022V] by raw no-function/no-caller status and unresolved caller/source-facing signature; for [UID:00019H] by mixed aggregate ownership across raw BaramApp constructor bytes, Application methods, thunk glue, and padding; for [UID:0001B7] by raw no-function/no-caller status and unproven final signature/liveness; and for [UID:0001B9] by broader MemoryMan source/header declaration placement. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:00022V], [UID:00019H], [UID:0001B7], and [UID:0001B9] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 Low-Completion Memory Batch 2 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Low-Completion Memory Batch 3

Assignment: `A001-goal2-lowcompletion-memory-20260615-3`.

- Changed docs: `by-memory/0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md`, `by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md`, `by-memory/0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md`, `by-memory/0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `get_bytes`) plus current direct owner docs and local `tools/int_convert.py` checks for documented decimal constants.
- Score changes: [UID:0002QU] `78/86 -> 85/88`; [UID:0001DP] `78/86 -> 86/88`; [UID:0002R5] `78/86 -> 85/88`; [UID:0001F7] `78/86 -> 85/88`.
- Owner/emitter/path decisions: no metadata route changes. [UID:0002QU] remains `CANONICAL_OWNER:0000IK`, `EMITTER_UIDS:0000IK`; [UID:0001DP] remains `CANONICAL_OWNER:0000M7`, `EMITTER_UIDS:0000M7`; [UID:0002R5] remains `CANONICAL_OWNER:000058`, `EMITTER_UIDS:000058`; [UID:0001F7] remains `CANONICAL_OWNER:0000MO`, `EMITTER_UIDS:0000MO`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type update was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0052f710-0x0052f94c.CreateUserDialogDestructorAndThunkIsland.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00546b80-0x00546bb5.FlyingParcelPaneCleanupDestructorBody.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x0054a480-0x0054a4b6.PowerDialogPaneSingletonHelpers.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits. Target leases were active during validation; `notes.md` was refreshed separately before this update.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:0002QU] by mixed destructor/thunk/deleting-destructor glue and source declaration shape; for [UID:0001DP] by unresolved packet wrapper/control field names and final source-facing signature; for [UID:0002R5] by raw no-function status and unresolved helper/base destructor names; and for [UID:0001F7] by retained-helper reachability/source-name uncertainty. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002QU], [UID:0001DP], [UID:0002R5], and [UID:0001F7] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 Low-Completion Memory Batch 3 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 TextBox/Living/BlockListen Memory Batch

Assignment: `A001-goal2-textbox-living-blocklisten-memory-20260615-4`.

- Changed docs: `by-memory/0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md`, `by-memory/0x00595390-0x005954b3.TextBoxPaneConstructor.md`, `by-memory/0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md`, `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `decompile`, `disasm`, `get_bytes`) plus current TextBoxPane/LivingObjectPane/BlockListenInputPanes parent docs and local `tools/int_convert.py` checks for documented decimal constants and offsets.
- Score changes: [UID:0002RU] `78/86 -> 85/88`; [UID:0002RV] `78/86 -> 86/88`; [UID:0002RW] `78/86 -> 85/88`; [UID:0001MW] `78/86 -> 85/88`.
- Owner/emitter/path decisions: no metadata route changes. [UID:0002RU] and [UID:0002RV] remain `CANONICAL_OWNER:0000OJ`, `EMITTER_UIDS:0000OJ`, routing through `auto-generated/NexusTK/ui/controls/TextBoxPane.cpp`. [UID:0002RW] remains `CANONICAL_OWNER:0000KU`, `EMITTER_UIDS:0000KU`, routing through `auto-generated/NexusTK/map/LivingObjectPane.cpp`. [UID:0001MW] remains `CANONICAL_OWNER:0000HS`, `EMITTER_UIDS:0000HS`, routing through `auto-generated/NexusTK/social/BlockListenInputPanes.cpp`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type update was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x00591300-0x005913f9.TextBoxPaneCursorInvalidationOverrides.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00595390-0x005954b3.TextBoxPaneConstructor.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x005b68c0-0x005b7354.BlockListenInputPanes.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits; the initial leases expired during context compaction, then A001 refreshed all five leases before validation/notes update.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:0002RU] by unresolved final-source field/helper signatures for cursor/line invalidation, for [UID:0002RV] by source-quality constructor parameter, flag, and helper names, for [UID:0002RW] by source-quality output-struct and field names, and for [UID:0001MW] because exact child pages/source-quality names must carry the final methods/helpers. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002RU], [UID:0002RV], [UID:0002RW], and [UID:0001MW] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 TextBox/Living/BlockListen supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Employee/Error Memory Batch

Assignment: `A001-goal2-employee-error-memory-20260615-5`.

- Changed docs: `by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md`, `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md`, `by-memory/0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md`, `by-memory/0x004a6480-0x004a6499.FileErrorCopyMessage.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`) plus current EmployeeDialogPane, EmployeeRecord, Error, DDError, FileError, ErrorObjectLayouts, ErrorHierarchyVtables, and ErrorWrappers docs. Local `tools/int_convert.py` verified all documented decimal conversions.
- Score changes: [UID:0002HD] `78/88 -> 86/89`; [UID:0002HK] `78/88 -> 85/89`; [UID:00013Y] `78/88 -> 85/89`; [UID:000140] `78/88 -> 85/89`.
- Owner/emitter/path decisions: no metadata route changes. [UID:0002HD] remains `CANONICAL_OWNER:000138`, `EMITTER_UIDS:000138`, routing through the EmployeeDialogPane source family. [UID:0002HK] remains `CANONICAL_OWNER:00003L`, `EMITTER_UIDS:00003L`, routing through DDError/Error.cpp. [UID:00013Y] remains `CANONICAL_OWNER:0000J5`, `EMITTER_UIDS:0000J5`, routing directly through Error.cpp. [UID:000140] remains `CANONICAL_OWNER:00004X`, `EMITTER_UIDS:00004X`, routing through FileError/Error.cpp. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type update was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x004a6260-0x004a6284.DDErrorConstructor.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x004a6400-0x004a640b.ErrorBaseCleanupHelper.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x004a6480-0x004a6499.FileErrorCopyMessage.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits. The target leases expired naturally after validation; A001 refreshed this notes file lease before recording supervisor rows.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:0002HD] by source-quality `EmployeeRecord` field/helper names and raw mutation helper shape; for [UID:0002HK] by shared error-header declaration, formatter sibling, and final member names; for [UID:00013Y] by no direct start xrefs and possible source folding into destructor cleanup; and for [UID:000140] by final virtual method name, inline buffer declaration, and hierarchy-wide declaration shape. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002HD], [UID:0002HK], [UID:00013Y], and [UID:000140] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 Employee/Error supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Password/Collection/Macro Memory Batch

Assignment: `A001-goal2-password-collection-macro-memory-20260615-6`.

- Changed docs: `by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md`, `by-memory/0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md`, `by-memory/0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md`, `by-memory/0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`) plus current ChangePasswordDialogPane, CollectionPane, CollectionPane class, MacroDialogs, SpellMacroEditControlPane, and NewMacroEditControlPane parent/support docs. Local `tools/int_convert.py` verified documented decimal conversions.
- Score changes: [UID:0002QC] `78/88 -> 85/89`; [UID:0001HF] `78/88 -> 85/89`; [UID:0001IL] `78/88 -> 85/89`; [UID:0001IM] `78/88 -> 85/89`.
- Owner/emitter/path decisions: no metadata route changes. [UID:0002QC] remains `CANONICAL_OWNER:0000I3`, `EMITTER_UIDS:0000I3`; [UID:0001HF] remains `CANONICAL_OWNER:0000IC`, `EMITTER_UIDS:0000IC`; [UID:0001IL] and [UID:0001IM] remain `CANONICAL_OWNER:0000KY`, `EMITTER_UIDS:0000KY`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type update was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0056fc80-0x0056fd61.CollectionPaneOpenOrRequestDetail.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0057f7b0-0x0057f7ce.SpellMacroEditControlPaneTeardownHelper.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x0057fa80-0x0057fa9e.NewMacroEditControlPaneTeardownHelper.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits, then refreshed all five leases before writing this notes entry.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:0002QC] by source-quality dialog field names and packet helper API names; for [UID:0001HF] by final helper and surrounding class field names; for [UID:0001IL] by possible source folding into destructor cleanup plus the direct class page being below strict `85/85`; and for [UID:0001IM] by unresolved destructor/helper source representation. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0002QC], [UID:0001HF], [UID:0001IL], and [UID:0001IM] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 Password/Collection/Macro supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Event/ItemMenu/ObjectImage Low-Confidence Batch

Assignment: `A001-goal2-event-itemmenu-objectimage-lowconfidence-20260615-7`.

- Changed docs: `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`, `by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`, `by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md`, `by-memory/0x00520540-0x00520816.ObjectImageControlPane.md`, and this `notes.md`. Validator also updated generated/project-level artifacts while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`) plus current EventDispatcher, ItemMenuDialogs, ServerItemMenuItemList, ObjectImageControlPane, and related parent/support docs. Local `tools/int_convert.py` verified documented decimal conversions.
- Score changes: [UID:000141] `82/84 -> 85/86`; [UID:0001BO] `82/84 -> 85/86`; [UID:0001BP] `82/84 -> 85/85`; [UID:0001BU] `82/84 -> 85/86`.
- Owner/emitter/path decisions: no metadata route changes. [UID:000141] remains `CANONICAL_OWNER:0000J7`, `EMITTER_UIDS:0000J7`; [UID:0001BO] and [UID:0001BP] remain `CANONICAL_OWNER:0000KF`, `EMITTER_UIDS:0000KF`; [UID:0001BU] remains `CANONICAL_OWNER:0000M3`, `EMITTER_UIDS:0000M3`. Final C++ remains blank for all four targets.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type update was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004a6a80-0x004a82a9.EventDispatcher.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0051a520-0x0051c46d.ItemMenuDialogs.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0051ae90-0x0051b87a.ServerItemMenuItemList.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x00520540-0x00520816.ObjectImageControlPane.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits. A pre-validation refresh attempt returned `Rejected[Already has lease]`, and the generated lease report showed A001 still held all five leases through validation/notes update.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blocked for [UID:000141] by unresolved source-quality helper names, handler-record fields, and scheduler source shape; for [UID:0001BO] by standalone-versus-`ItemDialogs.cpp` source split and raw/list helper names; for [UID:0001BP] by raw helper reachability and row-record/field names; and for [UID:0001BU] by descriptor field names and declaration shape. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:000141], [UID:0001BO], [UID:0001BP], and [UID:0001BU] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 Event/ItemMenu/ObjectImage supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 AUTOBUF/Runtime Glue Memory Batch

Assignment: `A001-goal2-autobuf-runtime-glue-memory-20260615-8`.

- Changed docs: `by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md`, `by-memory/0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md`, `by-memory/0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md`, `by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and this `notes.md`. Validator refreshed generated metadata while validating the target pages.
- Evidence used: current AUTOBUF/UserPane/PoolAllocator/client-library support docs plus live IDA MCP session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, and `analyze_function`). Local `tools/int_convert.py` verified new decimal conversions for `0x27` / 39, `0x1d` / 29, `0x83` / 131, `0x16` / 22, `0x0c` / 12, `0x2e` / 46, and `0x13eb84` / 1305476.
- Score changes: [UID:000188] `78/88 -> 85/90`; [UID:0000WE] `80/85 -> 85/91`; [UID:0000WF] `80/85 -> 85/90`; [UID:0000WO] `80/85 -> 85/91`.
- Owner/emitter/path decisions: [UID:000188] remains `CANONICAL_OWNER:00000P`, `EMITTER_UIDS:00000P`, routing through the AUTOBUF concrete class/utility template family. [UID:0000WE], [UID:0000WF], and [UID:0000WO] remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, with blank emitters and blank final C++ because they are compiler/static-initializer or CRT/UCRT glue. No source path changes were made.
- IDA DB changes: skipped. The live evidence was sufficient for documentation updates; no safe source-quality rename/comment/type edit was necessary, and compiler/CRT glue should not be forced into source ownership.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0041a4b0-0x0041a4cd.UserPanePoolStaticConstructorWrapper.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0041a4cd-0x0041a550.StaticRuntimeInitializerWrappersAfterUserPanePool.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blank for [UID:000188] because the source-quality AUTOBUF template/header contract and final spelling are still unresolved. Final C++ remains blank for [UID:0000WE], [UID:0000WF], and [UID:0000WO] by design because they are compiler/runtime/CRT glue and should be recreated by declarations plus toolchain/runtime behavior, not handwritten NexusTK source. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0000WE], [UID:0000WF], [UID:0000WO], and [UID:000188] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 AUTOBUF/Runtime Glue supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 LodePNG State Memory Batch

Assignment: `A001-goal2-lodepng-state-memory-20260615-9`.

- Changed docs: `by-class/LodePNGState.md`, `by-class/-coverage-report.md`, `by-file/LodePNG.md`, `by-memory/0x004460f0-0x004461f6.LodePngStateInit.md`, `by-memory/0x00448520-0x00448557.LodePNGStateDestructors.md`, renamed `by-memory/0x00450030-0x0045007b.LodePngLowerBoundHelper.md` to `by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md`, and this `notes.md`. Validator also refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated registry data while validating the target pages.
- Evidence used: live IDA MCP against session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`) plus staged third-party source under `source-3/third_party_embeds/lodepng` and current LodePNG/LodePNGState/helper-island/client-library docs. Local `tools/int_convert.py` verified documented decimal conversions including `0x106` / 262, `0x7` / 7, `0x27` / 39, `0x4c` / 76, and `0x128` / 296.
- Score changes: [UID:00007E] `84/84 -> 87/88`; [UID:0000XH] `80/85 -> 86/90`; [UID:0000XI] `80/85 -> 85/90`; [UID:0000XJ] `80/85 -> 86/90`.
- Path/range repair: [UID:0000XJ] was safely renamed because live IDA reconfirmed `sub_450030` size `0x4c` / 76 bytes, final `retn` at `0x0045007b`, four `0xcc` padding bytes at `0x0045007c-0x00450080`, and next function start at `0x00450080`; the old `0x00450030-0x0045007b` page name/range was an off-by-one exclusive-end error. Editable docs and `tools/validator.ini` now point to `by-memory/0x00450030-0x0045007c.LodePngLowerBoundHelper.md`, which accounts for the earlier shared-report `missing_ref_target` / `autogen_registry_stale` warning. A001 is still banned from directly editing `by-memory/-coverage-report.md`, so the remaining supervisor-owned row replacement below updates the shared report's range, score, and evidence text.
- Owner/emitter decisions: no owner/emitter route changes. All four target docs remain attached to [UID:0000KW][LodePNG](../../../by-file/LodePNG.md) with `CANONICAL_OWNER:0000KW`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000KW`. No NexusTK ownership was invented for the vendored third-party code. Final C++ remains blank because the source-quality route is the bundled `lodepng.cpp` / `lodepng.h` provenance rather than hand-authored per-helper decompiler output.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-class\LodePNGState.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x004460f0-0x004461f6.LodePngStateInit.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00448520-0x00448557.LodePNGStateDestructors.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x00450030-0x0045007c.LodePngLowerBoundHelper.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. `python .\tools\validator.py --mode file --file by-file\LodePNG.md --apply --queue-timeout 240` exited `0` and reported `ok: 1`. `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240` exited `0` and reported `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits; after the XJ rename, A001 leased the corrected XJ path; A001 also leased `by-file/LodePNG.md`, `by-class/-coverage-report.md`, and refreshed this notes lease before recording this entry. The first target lease attempt used wrong relative paths and was rejected for missing target files, then corrected leases succeeded.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains blank for all targets because vendored upstream source is the correct rebuild route. Direct edits to `by-memory/-coverage-report.md` remain supervisor-owned; exact pending replacement rows follow.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:0000XH], [UID:0000XI], and [UID:0000XJ] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 LodePNG supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 UI/Runtime Glue Memory Batch

Assignment: `A001-goal2-ui-runtime-glue-memory-20260615-10`.

- Changed docs: `by-memory/0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md`, `by-memory/0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md`, `by-memory/0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md`, `by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md`, and this `notes.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md` while validating the target pages.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`server_health`, `lookup_funcs`, `analyze_function`, `get_bytes`) plus current AlertPane, CheckBoxControlPane, FontStyle, RegistryConfig, ignored-ledger, vtable, and layout docs. Local `tools/int_convert.py` verified documented decimal conversions including `0xb` / 11, `0x16` / 22, `0xa0` / 160, `0xa4` / 164, `0x339` / 825, `0x1b6` / 438, `0x9f` / 159, `0x5a` / 90, `0x20` / 32, `0x27` / 39, `0x29` / 41, `0x114` / 276, `0x0fffffff` / 268435455, `0x1000` / 4096, and `0x1f` / 31.
- Score changes: [UID:00010V] `80/85 -> 85/90`; [UID:000221] `80/85 -> 86/90`; [UID:00011W] `80/85 -> 85/90`; [UID:00011Z] `80/85 -> 85/90`.
- Owner/emitter decisions: no route changes. All four targets remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++ because they are compiler-generated adjustor thunks, MSVC/COM/CRT/header glue, or compiler/template vector-growth support rather than handwritten NexusTK source.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no source-quality rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0048c315-0x0048c32b.AlertPaneAdjustorThunks.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x004941e0-0x00494519.MsvcComAndFormattingHelpers.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x0049ac60-0x0049ad74.FontStyleRuleVectorGrowth.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains intentionally blank for all four targets because normal inheritance/destructor declarations, CRT/COM support, and container append source should regenerate these binary helpers.

Supervisor applied the exact [UID:00010V], [UID:000221], [UID:00011W], and [UID:00011Z] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 UI/Runtime Glue supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Frame/IME/UserPane Thunks Memory Batch

Assignment: `A001-goal2-frame-ime-userpane-thunks-memory-20260615-11`.

- Changed docs: `by-memory/0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md`, `by-memory/0x004e85dc-0x004e8634.IMEAdjustorThunks.md`, `by-memory/0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md`, `by-memory/0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md`, and this `notes.md`. Validator refreshed `project-level/-auto-completion-stats.md` and `tools/validator.ini` while validating the target pages.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `analyze_function`, `disasm`, `trace_data_flow`, `int_convert`) plus current FrameChrome vtable, IMEPanes, UserPane, ScrolledPictureControlPane, ignored-ledger, and by-structure docs. Live IDA reconfirmed exact half-open ranges, data refs/vtable refs, target destructors, adjacent-boundary exclusions, and the `UserPane` pool-free EH wrapper role.
- Score changes: [UID:00015P] `80/85 -> 85/90`; [UID:00018D] `80/85 -> 85/90`; [UID:0001AA] `80/85 -> 85/90`; [UID:0001AD] `80/85 -> 85/90`.
- Owner/emitter decisions: no route changes. All four targets remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++ because they are compiler-generated adjustor thunks or constructor-failure EH cleanup glue rather than handwritten NexusTK source.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004b7590-0x004b75a6.FramePartPaneAdjustorThunks.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x004e85dc-0x004e8634.IMEAdjustorThunks.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00502420-0x0050245e.UserPanePoolFreeUnwindWrapper.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x00502550-0x00502566.ScrolledPictureControlPaneDestructorThunks.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains intentionally blank for all four targets because normal inheritance/destructor declarations and class pool policy should regenerate this compiler/EH glue.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied the exact [UID:00015P], [UID:00018D], [UID:0001AA], and [UID:0001AD] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Goal 2 frame/IME/UserPane thunk supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 Goal 2 Dialog/Pane Thunks Memory Batch

Assignment: `A001-goal2-dialog-pane-thunks-memory-20260615-12`.

- Changed target docs: `by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md`, renamed `by-memory/0x00544f2e-0x00544f43.PaneAdjustorThunks.md` to `by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md`, renamed `by-memory/0x005450ef-0x00545104.PanelPaneAdjustorThunks.md` to `by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md`, `by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md`, and this `notes.md`.
- Changed support docs for link/range repair: `by-memory/-ignored.md`, `by-type/by-vtable/PaneVtables.md`, `by-type/by-vtable/PaneCoreVtableFamily.md`, `by-type/by-struct/PaneLayout.md`, `by-file/Pane.md`, `by-class/Pane.md`, `by-memory/0x00544460-0x00545086.PaneCore.md`, `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`, `by-type/by-vtable/PanelPaneVtables.md`, `by-file/PanelPane.md`, `by-class/PanelPane.md`, `by-memory/0x00545090-0x00545165.PanelPane.md`, and `by-memory/0x00621a6c-0x00621af8.PanelPaneVtableData.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated memory coverage while validating the target/support pages.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `analyze_function`, `get_bytes`, `int_convert`) plus current vtable, class/file, ignored-ledger, and scalar-deleting-destructor island docs. Live IDA reconfirmed exact function sizes, thunk bodies, target destructors, data/vtable refs, padding bytes, and non-source-authored thunk roles.
- Score changes: [UID:00023J] `80/85 -> 86/90`; [UID:0001EB] `80/85 -> 86/90`; [UID:0001ED] `80/85 -> 86/90`; [UID:0001EF] `80/85 -> 85/90`.
- Path/range repairs: [UID:0001EB] corrected to `0x00544f2e-0x00544f44` because live IDA reports two `0xb` / 11-byte thunks at `0x00544f2e` and `0x00544f39`, and `get_bytes 0x00544f43` shows the final jump-operand byte followed by `0xcc` padding from `0x00544f44`. [UID:0001ED] corrected to `0x005450ef-0x00545105` by the same evidence pattern: two `0xb` starts at `0x005450ef` and `0x005450fa`, final jump-operand byte at `0x00545104`, padding from `0x00545105`.
- Owner/emitter decisions: no route changes. All four target docs remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++ because they are compiler-generated adjustor thunks, not handwritten NexusTK source.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh; no safe source-quality rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00544f2e-0x00544f44.PaneAdjustorThunks.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x005450ef-0x00545105.PanelPaneAdjustorThunks.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md --apply --queue-timeout 240`, and scoped validator runs for every edited support doc were run in sequence and exited `0`; each scoped run reported `ok: 1`. A post-validation `rg` check confirmed [UID:00023J], [UID:0001EB], [UID:0001ED], and [UID:0001EF] no longer appear in `project-level/-auto-completion-stats.md`, and generated memory coverage now points at the corrected renamed paths for [UID:0001EB] and [UID:0001ED].
- Leases used: A001 leased the four initial target docs and this notes file before edits; after live IDA proved the two range repairs, A001 also leased the directly affected support docs before link/range edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains intentionally blank for all four targets. A001 remained banned from directly editing `by-memory/-coverage-report.md`; supervisor applied and validated the shared-report rows below.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Supervisor applied these exact replacement rows on 2026-06-15 and validated `by-memory/-coverage-report.md` with result `ok: 1`. No A001 Goal 2 dialog/pane thunk supervisor-owned coverage rows remain pending.

Placement context: replace the current [UID:00023J] row between [UID:0001E2] `TargetOptionDialog` and the `0x0054267b-0x00542680` padding row:

```text
    - [UID:00023J][0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland](by-memory/0x0054259f-0x0054267b.DialogPaneAdjustorThunkIsland.md) 0x0054259f-0x0054267b | compiler thunk island | DialogPaneAdjustorThunkIsland : ignored : 86% : very-strong : Compiler/linker-generated adjustor thunk island for adjacent dialog scalar deleting destructors. Live 2026-06-15 IDA MCP reconfirms all 20 starts as exact `0xb` / 11-byte functions across the `0xdc` / 220-byte range, `0x0054267b-0x00542680` successor padding, two-instruction `sub ecx, 0xa0/0xa4; jmp target` bodies, vtable/data refs at `0x00621068`, `0x00621098`, `0x00620f44`, `0x00620f74`, `0x00621190`, `0x006211c0`, `0x00620d70`, `0x00620da0`, `0x00620ea8`, `0x00620ed8`, `0x006210f4`, `0x00621124`, `0x00620cd4`, `0x00620d04`, `0x00620fe0`, `0x00621010`, `0x00620e0c`, `0x00620e3c`, `0x0062122c`, and `0x0062125c`, and targets `0x00542680`, `0x005426e0`, `0x00542740`, `0x005427a0`, `0x00542800`, `0x00542860`, `0x00542940`, `0x005429a0`, `0x00542a00`, and `0x00542a60`; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001EB] row under [UID:0001EA] `PaneCore`, between [UID:0002V7] `PaneSetMode` and the `0x00545086-0x00545090` padding row. This replacement also updates the old path/range `0x00544f2e-0x00544f43` to corrected `0x00544f2e-0x00544f44`:

```text
    - [UID:0001EB][0x00544f2e-0x00544f44.PaneAdjustorThunks](by-memory/0x00544f2e-0x00544f44.PaneAdjustorThunks.md) 0x00544f2e-0x00544f44 | compiler thunk pair | PaneAdjustorThunks : ignored : 86% : very-strong : Compiler-generated secondary/tertiary `Pane` destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms `sub_544F2E` and `sub_544F39` as exact `0xb` / 11-byte starts, corrects the half-open extent to `0x00544f44` because `0x00544f43` is the final jump-operand byte and `0x00544f44` begins padding, confirms target scalar deleting destructor `0x00544f50` size `0x136` / 310 bytes, receiver adjustments `0xa0` / 160 and `0xa4` / 164, vtable data refs at `0x00621a34` and `0x00621a64`, and no ordinary callers; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001ED] row under [UID:0001EC] `PanelPane`, between [UID:0001EC] and the `0x00545165-0x00545170` padding row. This replacement also updates the old path/range `0x005450ef-0x00545104` to corrected `0x005450ef-0x00545105`:

```text
    - [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md) 0x005450ef-0x00545105 | compiler thunk pair | PanelPaneAdjustorThunks : ignored : 86% : very-strong : Compiler-generated secondary/tertiary `PanelPane` destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms `sub_5450EF` and `sub_5450FA` as exact `0xb` / 11-byte starts, corrects the half-open extent to `0x00545105` because `0x00545104` is the final jump-operand byte and `0x00545105` begins padding, confirms target scalar deleting destructor `0x00545110` size `0x55` / 85 bytes, receiver adjustments `0xa0` / 160 and `0xa4` / 164, vtable data refs at `0x00621ac0` and `0x00621af0`, and no ordinary callers; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001EF] row under [UID:0001EE] `EditablePaperPane`, between [UID:0001EE] and the `0x00545e3b-0x00545e40` padding row:

```text
    - [UID:0001EF][0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks](by-memory/0x00545ddd-0x00545df3.EditablePaperPaneAdjustorThunks.md) 0x00545ddd-0x00545df3 | compiler thunk pair | EditablePaperPaneAdjustorThunks : ignored : 85% : very-strong : Compiler-generated secondary/tertiary `EditablePaperPane` destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms `sub_545DDD` and `sub_545DE8` as exact `0xb` / 11-byte starts, `0x00545df3` as padding/not a function start, target scalar deleting destructor `0x00545e00` size `0x3b` / 59 bytes, receiver adjustments `0xa0` / 160 and `0xa4` / 164, vtable data refs at `0x00621b60` and `0x00621b90`, and no ordinary callers; keep ignored with no handwritten source emission.
```

## 2026-06-15 Goal 2 Forced/Terminal Thunks Memory Batch

Assignment: `A001-goal2-forced-terminal-thunks-memory-20260615-13`.

- Changed target docs: `by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md`, `by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md`, renamed `by-memory/0x0058dbe0-0x0058dbea.ClearTerminalPaneSingletonEH.md` to `by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md`, renamed `by-memory/0x0058dbeb-0x0058dc00.DialDialogAdjustorThunks.md` to `by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md`, and this `notes.md`.
- Changed support docs for the two path/range repairs: `by-memory/-ignored.md`, `by-class/DialDialog.md`, `by-file/PhoneBookDialog.md`, `by-file/TerminalPane.md`, `by-global/g_pTerminalPane.md`, `by-memory/0x0058d750-0x0058dc5b.DialDialog.md`, `by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md`, and `by-memory/0x0069bdf8-0x0069bdfc.g_pTerminalPane.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md`.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `analyze_function`, `trace_data_flow`, `int_convert`) plus current ForcedInformMessageDialog, DialDialog, TerminalPane, singleton global, and ignored-ledger docs. Live IDA reconfirmed exact function sizes, code/data/vtable refs, no ordinary callers, and compiler/EH/thunk roles.
- Score changes: [UID:0001J8] `80/85 -> 86/90`; [UID:0001J9] `80/85 -> 86/90`; [UID:0001JI] `80/85 -> 86/90`; [UID:0001JJ] `80/85 -> 86/90`.
- Path/range repairs: [UID:0001JI] corrected to `0x0058dbe0-0x0058dbeb` because live IDA reports `sub_58DBE0` size `0xb`, with `retn` at `0x0058dbea` and `0x0058dbeb` as the next function start. [UID:0001JJ] corrected to `0x0058dbeb-0x0058dc01` because live IDA reports two `0xb` thunks at `0x0058dbeb` and `0x0058dbf6`, with `0x0058dc00` inside the second thunk and `0x0058dc01` as the next function start.
- Owner/emitter decisions: no route changes. All four targets remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++ because they are compiler-generated constructor EH cleanup or destructor adjustor thunks rather than handwritten NexusTK source.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh and documentation/path repair; no safe source-quality rename/comment/type edit was necessary.
- Validation: ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for all four changed targets and every changed support doc listed above. The sequence exited `0`; scoped runs reported `ok: 1`. The first pass reported stale registry paths for [UID:0001JI] and [UID:0001JJ] because the rename had just occurred; later checks show `tools/validator.ini` and `auto-generated/-ag-memory-coverage.md` now point at `0x0058dbe0-0x0058dbeb` and `0x0058dbeb-0x0058dc01`.
- Leases used: A001 leased the four original target docs and this notes file before edits; after live IDA proved path repairs, A001 leased the directly affected support docs before updating links/ranges. Notes lease was renewed after validation because the original five-minute lease expired during the long validator run.
- Blockers: no target blocker for clearing the `85/85` documentation gate. Final C++ remains intentionally blank. A001 remained banned from directly editing `by-memory/-coverage-report.md`; supervisor applied and validated the shared-report replacement rows below.

### Supervisor-applied `by-memory/-coverage-report.md` Replacement Rows

Supervisor applied these exact replacement rows on 2026-06-15 and validated `by-memory/-coverage-report.md` with result `ok: 1`. No A001 Goal 2 forced/terminal thunk supervisor-owned coverage rows remain pending.

Placement context: replace the current [UID:0001J8] row under the ForcedInform/SystemMessage area, immediately before the current [UID:0001J9] row:

```text
    - [UID:0001J8][0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear](by-memory/0x0058aa90-0x0058aa9b.ForcedInformMessageDialogSingletonClear.md) : ignored : 86% : very-strong : Compiler-generated constructor EH singleton-clear helper for `ForcedInformMessageDialog`. Live 2026-06-15 IDA MCP reconfirms `sub_58AA90` as exact size `0xb`, `0x0058aa9b` as not a function start, the entire body as `mov dword ptr unk_69B4A0, 0; retn`, one constructor-unwind code ref at `0x00608f3b`, one data ref to `0x0069b4a0`, and no ordinary callers; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001J9] row immediately after [UID:0001J8]:

```text
    - [UID:0001J9][0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks](by-memory/0x0058aadb-0x0058aaf1.ForcedInformMessageDialogDestructorThunks.md) : ignored : 86% : very-strong : Compiler-generated secondary/tertiary `ForcedInformMessageDialog` destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms `sub_58AADB` and `sub_58AAE6` as exact `0xb` starts, `0x0058aaf1` as the next function start outside the page, receiver adjustments `0xa0` / 160 and `0xa4` / 164, tail jumps to scalar deleting destructor `0x0058abf0`, vtable data refs at `0x0062d778` and `0x0062d7a8`, and no ordinary callers; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001JI] row immediately after the existing [UID:0000VN] ignored-ledger summary row for `0x0058dbe0-0x0058dbeb`. This replacement also updates the stale old path/range `0x0058dbe0-0x0058dbea` to corrected `0x0058dbe0-0x0058dbeb`:

```text
    - [UID:0001JI][0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH](by-memory/0x0058dbe0-0x0058dbeb.ClearTerminalPaneSingletonEH.md) : ignored : 86% : very-strong : Compiler-generated `TerminalPane` constructor EH singleton-clear helper. Live 2026-06-15 IDA MCP reconfirms `sub_58DBE0` as exact size `0xb`, `0x0058dbea` as the `retn` byte inside the function, `0x0058dbeb` as the next function start, the entire body as `mov dword_69BC18+1E0h, 0; retn`, one constructor-unwind code ref at `0x00609241`, one data ref to `g_pTerminalPane` at `0x0069bdf8`, and no ordinary callers; keep ignored with no handwritten source emission.
```

Placement context: replace the current [UID:0001JJ] row immediately after [UID:0001JI]. This replacement also updates the stale old path/range `0x0058dbeb-0x0058dc00` to corrected `0x0058dbeb-0x0058dc01`:

```text
    - [UID:0001JJ][0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks](by-memory/0x0058dbeb-0x0058dc01.DialDialogAdjustorThunks.md) : ignored : 86% : very-strong : Compiler-generated secondary/tertiary `DialDialog` destructor adjustor thunks. Live 2026-06-15 IDA MCP reconfirms `sub_58DBEB` and `sub_58DBF6` as exact `0xb` starts, `0x0058dc00` as the final byte inside the second thunk, `0x0058dc01` as the next function start, receiver adjustments `0xa0` / 160 and `0xa4` / 164, tail jumps to scalar deleting destructor `0x0058dc20`, vtable data refs at `0x0062dda4` and `0x0062ddd4`, and no ordinary callers; keep ignored with no handwritten source emission.
```

## 2026-06-15 Goal 2 WorldMap/MSVC Runtime Memory Batch

Assignment: `A001-goal2-worldmap-msvc-runtime-memory-20260615-14`.

- Changed target docs: `by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md`, `by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md`, `by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md`, `by-memory/0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md`, and this `notes.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md`.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `entity_query`, `analyze_function`, `trace_data_flow`) plus current WorldMapPane file/class/helper, singleton, read-only-data, prior runtime-island, client-library, and by-structure docs.
- Score changes: [UID:0001O4] `80/85 -> 86/88`; [UID:0001O5] `80/85 -> 86/90`; [UID:00024C] `80/85 -> 86/90`; [UID:00024D] `80/85 -> 86/90`.
- Owner/emitter decisions: [UID:0001O4] remains `CANONICAL_OWNER:0000PB`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PB`, blank final C++. It clears the score gate but still lacks source-quality per-method child pages and final names for most individual methods, so no final C++ was added. [UID:0001O5], [UID:00024C], and [UID:00024D] remain `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank final C++ because they are CRT/runtime/toolchain or compiler-generated SEH support, not NexusTK handwritten source.
- Boundary/routing confirmations: live IDA reconfirmed [UID:0001O4] half-open end at `0x005c5c87` with `DirectDrawCreate` as the successor; [UID:0001O5] as exact `0x2a` wide `parse_integer` wrapper; [UID:00024C] as `1009` function starts from `0x005cea6d` through `_strrchr` ending at `0x005f66f7`; and [UID:00024D] as zero function starts in `0x005f66f7-0x0060c0a0` with dense `SEH_...` cleanup labels and successor function `0x0060c0a0`.
- IDA DB changes: skipped. The assignment only needed read-only evidence refresh and documentation updates; no safe source-quality rename/comment/type edit was necessary.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x005c2ac0-0x005c5c87.WorldMapPane.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x005cea43-0x005cea6d.CrtWtolWrapper.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md --apply --queue-timeout 240` were run in sequence and exited `0`; each scoped run reported `ok: 1`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and this notes file before edits.
- Blockers: no target blocker for clearing the `85/85` documentation gate. A001 remained banned from directly editing `by-memory/-coverage-report.md`; supervisor applied and validated the exact replacement rows below on 2026-06-15.

### Supervisor-applied `by-memory/-coverage-report.md` Replacement Rows

Supervisor application: applied exact rows to `by-memory/-coverage-report.md` on 2026-06-15; validation command `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1` returned `ok: 1`. No A001 WorldMap/MSVC runtime supervisor-owned rows remain pending.

Placement context: replace the current [UID:0001O4] row in address order immediately after the `0x005c2ab5-0x005c2ac0` alignment/ignored row and before [UID:00024B] `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport`:

```text
    - [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md) 0x005c2ac0-0x005c5c87 | class aggregate | WorldMapPane : reconstructable : 86% : very-strong : WorldMapPane executable aggregate attached to WorldMapPane.cpp, with live 2026-06-15 IDA MCP confirmation of the exact half-open boundary, 37 function starts inside the range, `DirectDrawCreate` successor at `0x005c5c87`, constructor callers and singleton writes, singleton external reads, private node-entry vector and reachability-bitset helper boundaries, read-only-data/singleton links, runtime successor boundary, and explicit final-C++ blockers pending exact child pages and source-quality method names.
```

Placement context: replace the current [UID:0001O5] row immediately after [UID:00024B] `0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport` and before [UID:00024C]:

```text
    - [UID:0001O5][0x005cea43-0x005cea6d.CrtWtolWrapper](by-memory/0x005cea43-0x005cea6d.CrtWtolWrapper.md) : ignored : 86% : very-strong : Microsoft Visual C universal runtime wide `_wtol` wrapper. Live 2026-06-15 IDA MCP reconfirms exact `0x2a` size, predecessor `__ischartype_l` ending at `0x005cea43`, successor narrow runtime parser wrapper at `0x005cea6d`, base-10 `__crt_strtox::parse_integer<unsigned long, c_string_character_source<wchar_t>>` behavior, broad non-owner caller fanout, and no project strings/data refs; keep ignored with no handwritten NexusTK source emission.
```

Placement context: replace the current [UID:00024C] row immediately after [UID:0001O5] and before [UID:00024D]:

```text
    - [UID:00024C][0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport](by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md) 0x005cea6d-0x005f66f7 | runtime | MsvcAcrtStdioLocaleMathSupport : ignored : 86% : very-strong : Statically linked MSVC/ACRT/STL support island. Live 2026-06-15 IDA MCP reconfirms `1009` function starts, first function `0x005cea6d sub_5CEA6D` as a narrow base-10 `parse_integer` wrapper, representative ACRT/stdio formatting names, last function `0x005f65c0 _strrchr` size `0x137`, and no function at the half-open successor `0x005f66f7`; rebuild from the selected runtime/toolchain model, not NexusTK source.
```

Placement context: replace the current [UID:00024D] row immediately after [UID:00024C] and before the next text-section range after `0x0060c0a0`:

```text
    - [UID:00024D][0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland](by-memory/0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md) 0x005f66f7-0x0060c0a0 | compiler-generated | MsvcSehFuncletIsland : ignored : 86% : very-strong : MSVC SEH/EH cleanup funclet island. Live 2026-06-15 IDA MCP reconfirms `_strrchr` ends at `0x005f66f7`, zero function starts in the half-open range, dense `SEH_...` cleanup labels including `SEH_41A670`, `SEH_41A6F0`, `SEH_41AA00`, `SEH_4F2DD0`, tail labels `??1_Fac_node@std@@QAE@XZ_SEH` and `SEH_5C8CB0`, and successor function `0x0060c0a0`; source semantics belong to owning functions and compiler regeneration, not handwritten source.
```

## 2026-06-15 Goal 2 Fitting/Board/Chat Memory Batch

Assignment: `A001-goal2-fitting-board-chat-memory-20260615-15`.

- Changed target docs: `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`, `by-memory/0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md`, `by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md`, `by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md`, and this `notes.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md`.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `entity_query`, `analyze_function`, `trace_data_flow`, `make_signature_for_range`, scoped `search_text`) plus current FittingRoom, FittingRoomDialogItemState, BoardDialogs, ChattingPane, Chatting, and ChattingUI docs.
- Score changes: [UID:0000WU] `80/86 -> 86/88`; [UID:0002EA] `80/86 -> 85/88`; [UID:0000ZJ] `80/86 -> 86/90`; [UID:0002EY] `80/86 -> 85/88`.
- Owner/emitter decisions: no route changes. [UID:0000WU] remains `CANONICAL_OWNER:0000JE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JE`; [UID:0002EA] remains `CANONICAL_OWNER:000051`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000051`; [UID:0000ZJ] remains `CANONICAL_OWNER:0000HT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HT`; [UID:0002EY] remains `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001X`. Final C++ stayed blank for all four because source-quality final names/types or raw reachability remain unresolved.
- IDA DB changes: skipped. The assignment needed read-only evidence refresh only; no safe source-quality rename/comment/type edit was justified.
- Validation: ran `python .\tools\validator.py --mode file --file by-memory\0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00472040-0x00472069.BoardDialogCommandOneVirtual.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md --apply --queue-timeout 240`. The sequence exited `0`; filtered reruns for each file reported `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
- Leases used: A001 leased the four target docs and this notes file before edits, and renewed the leases before writing after the IDA pass ran long.
- Blockers: no blocker for clearing the documentation score gate. Final C++ remains intentionally gated for [UID:0000WU] by unresolved `0xc0` entry layout, `ItemCatalog` source split, and helper liveness; for [UID:0002EA] by raw unmodeled/no-caller status and source helper naming; for [UID:0000ZJ] by provisional common interface/member/event names; and for [UID:0002EY] by raw unmodeled/no-caller status plus source-quality scroll helper names.
- Shared-report status: supervisor applied and validated the four replacement rows below on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 fitting/board/chat supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0000WU] row around the FittingRoom item-shop catalog area, immediately after the `0x004214f7-0x00421a40` padding/ignored row and before [UID:0002E4]:

```text
        - [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) 0x00421a40-0x00422e91 | aggregate | FittingRoomItemShopCatalogState : reconstructable : 86% : very-strong : Fitting-room item-shop cache/catalog aggregate attached to FittingRoom. Live 2026-06-15 IDA MCP reconfirms the exact twelve modeled functions in the range, no function at raw helper start `0x00422920` or aggregate end marker `0x00422e91`, constructor/parser/category-loader behavior, raw helper boundary, JsonCpp handoff, category-string switch table via `jpt_422BD7`, cache-path string sharing with the raw helper, and strong FittingRoom/FittingRoomDialogItemState support; final C++ remains blank pending `0xc0` entry layout, helper liveness, and ItemCatalog source-split resolution.
```

Placement context: replace the current [UID:0002EA] row nested under [UID:0000WU], immediately after the `0x00422919-0x00422920` padding row and before [UID:0002EG]:

```text
            - [UID:0002EA][0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw](by-memory/0x00422920-0x004229ef.FittingRoomDialogItemStateBuildCacheFilePathRaw.md) 0x00422920-0x004229ef | raw helper | FittingRoomDialogItemStateBuildCacheFilePathRaw : reconstructable : 85% : very-strong : Attached to `FittingRoomDialogItemState`; live 2026-06-15 IDA reconfirms the raw `0xd0` byte body through return byte `0x004229ef`, unique range signature for `0x00422920-0x004229f0`, no modeled function record, no incoming xrefs to `0x00422920`, seven `0xcc` bytes before the body, immediate cache-load helper adjacency, `SHGetFolderPathW` path build, wide `NexusTK`/`ItemShop`/`ItemShop.jbn` format strings with constructor duplicate refs, directory-create already-exists handling, and receiver cache-path field storage at offset `0x18`; final C++ remains blank pending reachability and source helper naming.
```

Placement context: replace the current [UID:0000ZJ] row in the board/article dialog area, immediately after the `0x0047203a-0x00472040` padding row and before [UID:0000ZK]:

```text
    - [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) 0x00472040-0x00472069 | shared secondary-interface command bridge virtual | BoardDialogCommandOneVirtual : reconstructable : 86% : very-strong : IDA-verified command `'1'` bridge installed in Bulletin, board/article, and mail secondary vtables. Live 2026-06-15 IDA MCP reconfirms exact modeled size `0x29`, no function at `0x00472069`, next function `0x00472070`, no ordinary callers, nine secondary-vtable data xrefs, secondary `this - 0xa0` adjustment, and primary vtable slot `+0x5c` tail-jump; final C++ remains blank because common interface/member names and event object type are still provisional.
```

Placement context: replace the current [UID:0002EY] row nested under [UID:000104] `ChattingUI`, immediately after the `0x0047fd3b-0x0047fd40` padding row and before `0x0047fd68-0x0047fd70` padding / [UID:0002EZ]:

```text
        - [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md) 0x0047fd40-0x0047fd68 | raw helper | ChattingPaneResetScrollRangeRaw : reconstructable : 85% : very-strong : Live IDA reconfirms exact raw ChattingPane reset-scroll helper body `0x0047fd40-0x0047fd68`, unique range signature, no IDA-modeled function at `0x0047fd40` or `0x0047fd68`, no incoming xrefs to the raw start, next modeled function `sub_47FD70` at `0x0047fd70`, exact bytes, five-byte and eight-byte `0xcc` padding spans, shared `sub_55E950`/`sub_55E910`/`sub_55EAE0` scroll-helper trio, ChattingPane parent attachment, no-call-surface caveat, and final C++ remains blank pending reachability and source-quality scroll helper names.
```

## 2026-06-15 Goal 2 ClanBank/Employee/Exchange/Field Memory Batch

Assignment: `A001-goal2-clanbank-employee-exchange-field-memory-20260615-16`.

- Changed target docs: `by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md`, `by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md`, `by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md`, and renamed `by-memory/0x004b1130-0x004b119a.FieldMapRectHelper.md` to `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md`.
- Changed support docs for the FieldMap endpoint repair: `by-file/FieldMapPane.md`, `by-class/FieldMapPane.md`, `by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md`, `by-memory/0x0061a3c4-0x0061a45c.FieldMapPaneReadOnlyData.md`, and `by-class/FittingRoomDownloadControlPane.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md`; scoped validation also normalized the [UID:000150] link path inside `by-memory/-coverage-report.md`, but the score/range row remains supervisor-owned and pending below.
- Evidence used: live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `entity_query`, `analyze_function`, `trace_data_flow`, `make_signature_for_range`) plus current ClanBank/ClanBankPane, EmployeeDialogPane/EmployeeItemPropertyDialogPane/layout/vtable, ExchangeDialog/ExchangeItemListPane, and FieldMapPane support docs.
- Score changes: [UID:00021Y] `80/86 -> 85/88`; [UID:0002HE] `80/86 -> 86/90`; [UID:00014S] `80/86 -> 85/88`; [UID:000150] `80/86 -> 85/88` with exact endpoint corrected from `0x004b119a` to `0x004b119d`.
- Owner/emitter decisions: no route changes. [UID:00021Y] remains `CANONICAL_OWNER:0000I9`, `EMITTER_UIDS:0000I9`; [UID:0002HE] remains `CANONICAL_OWNER:000138`, `EMITTER_UIDS:000138`; [UID:00014S] remains `CANONICAL_OWNER:0000J9`, `EMITTER_UIDS:0000J9`; [UID:000150] remains `CANONICAL_OWNER:0000JA`, `EMITTER_UIDS:0000JA`. Final C++ remains blank for all four because the raw helpers lack modeled callers/source-quality names, and the constructor still lacks source-quality control/helper names below the 95/95 emission gate.
- IDA DB changes: skipped. This was a read-only evidence/doc update; no safe source-quality rename/comment/type edit was needed.
- Validation: ran a scoped loop from `source-3/project-documentation` over the four target docs and five support docs with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`; the loop exited `0`. The first target pass reported `ok: 1`, score updates for [UID:00021Y], and a stale [UID:000150] path before the renamed file was validated; after validating the renamed FieldMap doc, `tools/validator.ini` maps [UID:000150] to `by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md` with scores `85/88`. The four UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased the four target docs and notes before the IDA/edit pass, leased the five direct FieldMap support docs before link edits, leased the renamed FieldMap doc after the move, and reacquired the three unchanged-path target docs plus notes after the initial short leases expired during the rename/validation window.
- Blockers: no blocker for the assigned 85/85 documentation gate. Remaining blockers are final-C++ gates only: raw no-function/no-caller status for [UID:00021Y], [UID:00014S], and [UID:000150], and source-quality control/helper naming for [UID:0002HE].
- Shared-report status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 clanbank/employee/exchange/field supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:00021Y] row immediately after the `0x0048b7dc-0x0048b7e0` padding row and before the `0x0048b8bc-0x0048b8c0` padding row:

```text
    - [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md) 0x0048b7e0-0x0048b8bc | raw helper cluster | ClanBankPaneRawPacketHelpers : reconstructable : 85% : very-strong : Two executable opcode `0x36` clan-bank packet helpers; live 2026-06-15 IDA MCP reconfirms no function starts at either raw helper, no incoming flow edges, only successor function `0x0048b8c0` in the local entity query, unique concrete range signature, ClanBankPane/ClanBank ownership, shared packet-sender use, adjacent padding, and final-C++ caveats pending caller/source-name evidence.
```

Placement context: replace the current [UID:0002HE] row nested under `EmployeeDialogPanes`, immediately after [UID:0003L3] `EmployeeDialogPaneUpdateEmployeeFields` and before [UID:0002HF] `EmployeeItemPropertyDialogPaneOnPaint`:

```text
        - [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md) 0x004a41c0-0x004a456b | method | EmployeeItemPropertyDialogPaneConstructor : reconstructable : 86% : very-strong : Property-dialog constructor; live 2026-06-15 IDA MCP reconfirms exact `0x3ab` function boundary, successor paint handler at `0x004a4570`, allocation/caller `0x004a3319`, `0x284` object size, property-dialog vtable stores, owner pointer `+0x26c`, icon rect `+0x270`, selected EmployeeRecord pointer `+0x280`, selected-record name/value reads, key control ids, back-pane attachment, EmployeeDialogPanes ownership, and blank final C++ pending source-quality control/helper names.
```

Placement context: replace the current [UID:00014S] row immediately after the `0x004ae167-0x004ae170` padding row and before the `0x004ae1ac-0x004ae1b0` padding row:

```text
    - [UID:00014S][0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper](by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md) 0x004ae170-0x004ae1ac | raw helper | ExchangeItemListPaneRawFindHelper : reconstructable : 85% : very-strong : Raw non-IDA ExchangeItemListPane find helper; live 2026-06-15 IDA MCP reconfirms no function object at the raw start, no incoming flow, successor `nullsub_29` and draw virtual boundaries, unique concrete range signature, key-byte scan returning row index or `-1`, row-layout corroboration from the upsert helper and draw virtual, ExchangeDialog ownership, and final-C++ caveats pending caller/source-name evidence.
```

Placement context: replace the current [UID:000150] row immediately after [UID:00014Z] `0x004b0bb0-0x004b129b.FieldMapPane` and before [UID:000151] `0x004b11a0-0x004b1242.FieldMapRequestHelper`:

```text
    - [UID:000150][0x004b1130-0x004b119d.FieldMapRectHelper](by-memory/0x004b1130-0x004b119d.FieldMapRectHelper.md) 0x004b1130-0x004b119d | raw helper | FieldMapRectHelper : reconstructable : 85% : very-strong : Raw FieldMap rectangle helper with corrected exclusive endpoint. Live 2026-06-15 IDA MCP reconfirms no function object or incoming flow at `0x004b1130`, successor request helper beginning at `0x004b11a0`, unique concrete signature for `0x004b1130-0x004b119d`, full inclusion of the final `retn 8` bytes at `0x004b119a-0x004b119c`, `0x004b119d-0x004b11a0` padding, text-measurement callees, `0x94`-stride row rectangle math, FieldMap mouse/render layout corroboration, FieldMapPane ownership, and final-C++ caveats pending caller/source-name evidence.
```

## 2026-06-15 Goal 2 Spell/Application/Fitting/Alpha Memory Batch

Assignment: `A001-goal2-spell-app-fitting-alpha-memory-20260615-17`.

- Changed target docs: `by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md`, `by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md`, `by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md`, and `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`.
- Changed support docs: `by-class/FittingRoomScrollPane.md` and `by-file/AlphaMaskSurface.md`. Validator refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and `auto-generated/-ag-memory-coverage.md`.
- Evidence used: Wave2 method-analysis from `source-2/core/wave2` where available, live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `entity_query`, `analyze_function`, `trace_data_flow`, `search_text`, `make_signature_for_range`), and current Application, ChangeSpellSlotInputPane, FittingRoomScrollPane, FittingRoom, AlphaMaskSurface, IntAlphaSurface, and alpha surface type docs.
- Score changes: [UID:0001MA] `80/86 -> 86/90`; [UID:0002JW] `80/87 -> 85/89`; [UID:0002DA] `80/88 -> 85/89`; [UID:0002NM] `80/88 -> 85/89`. Support score changes: [UID:000054] `82/88 -> 85/89`; [UID:0000HF] `84/90 -> 85/90`.
- Owner/emitter decisions: no route changes. [UID:0001MA] remains `CANONICAL_OWNER:00001M`, `EMITTER_UIDS:00001M`; [UID:0002JW] remains `CANONICAL_OWNER:00000D`, `EMITTER_UIDS:00000D`; [UID:0002DA] remains `CANONICAL_OWNER:000054`, `EMITTER_UIDS:000054`; [UID:0002NM] remains `CANONICAL_OWNER:0000HF`, `EMITTER_UIDS:0000HF`. Final C++ remains blank for all targets because source-quality field/helper names, raw reachability, or source-owner split details remain unresolved below the final code gate.
- IDA DB changes: skipped. The pass was read-only evidence/refinement; no safe source-quality rename/comment/type change was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` from `source-3/project-documentation` for the four target docs and two support docs. First full loop exited `0`; filtered rerun for each changed doc reported `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`. Each rerun also repeated an unrelated existing `autogen_registry_stale 00023W by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md registered file is missing` warning.
- Leases used: A001 leased the four target docs and this notes file before research, then leased `by-class/FittingRoomScrollPane.md` and `by-file/AlphaMaskSurface.md` before support edits.
- Blockers: no blocker for the assigned 85/85 documentation gate. Remaining blockers are final-C++ gates only: [UID:0001MA] needs source-quality player-data field and packet helper names; [UID:0002JW] remains raw/unreferenced and needs final Application member/method declaration proof; [UID:0002DA] remains raw/non-function at both helper starts and needs boundary repair plus source-quality enum/field names; [UID:0002NM] still lacks direct callers and the final `AlphaMaskSurface` versus `IntAlphaSurface` source split.
- Shared-report status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 spell/application/fitting/alpha supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0002DA] row nested under the FittingRoom UI core around `0x0041e780`, immediately after the `0x0041e777-0x0041e780` padding row and before [UID:0002D5]:

```text
        - [UID:0002DA][0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers](by-memory/0x0041e780-0x0041e8af.FittingRoomScrollPaneRawPartStateHelpers.md) 0x0041e780-0x0041e8af | raw helper pair | FittingRoomScrollPaneRawPartStateHelpers : reconstructable : 85% : very-strong : FittingRoomScrollPane raw hot/active part helper pair. Wave2 and live IDA confirm `0x0041e780` as a hot-part setter candidate and `0x0041e7f0` as a begin-press/thumb tracking helper candidate; live IDA reconfirms no functions or incoming xrefs at the raw starts, modeled successor `0x0041e8b0`, raw call site `0x0041e882`, GetPartRect invalidations, thumb drag-offset setup, active byte `this+0x104`, repeat timer start, FittingRoomScrollPane parent `85/89`, and blank final C++ pending boundary repair and source-quality field/enum names.
```

Placement context: replace the current [UID:0002NM] row in the AlphaMaskSurface helper cluster around `0x004623c0`, immediately after [UID:0000U3]/`0x00462320-0x004623b5` and before [UID:0000YN]:

```text
        - [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) 0x004623c0-0x00462514 | function/helper | InitAlphaSurfaceView : reconstructable : 85% : very-strong : InitAlphaSurfaceView full/clipped non-owning alpha-surface view initializer. Wave2 has no method record at `0x004623c0` and omits it from both AlphaMaskSurface and IntAlphaSurface method filters; live IDA reconfirms exact `sub_4623C0` boundary, no incoming xrefs, successor `0x00462520`, unique range signature, `off_6112EC` vtable store, `sub_4B7C50`/`sub_4B7CC0` rectangle helpers, full-view copy, clipped pointer math, final ownership-byte clear, AlphaMaskSurface support `85/90`, and blank final C++ pending caller evidence and final source split.
```

Placement context: replace the current [UID:0002JW] row in the Application lifecycle/helper area around `0x00465130`, immediately after [UID:0002JV] and before [UID:0002GM]:

```text
    - [UID:0002JW][0x00465130-0x004651b8.ApplicationReadProcessorName](by-memory/0x00465130-0x004651b8.ApplicationReadProcessorName.md) 0x00465130-0x004651b8 | raw method-shaped code | ApplicationReadProcessorName : reconstructable : 85% : very-strong : Raw Application-local processor-name reader. Wave2 has no method/global record at `0x00465130` and omits it from the modeled Application method set; live IDA reconfirms no function at `0x00465130`/`0x004651b8`, next accessor `0x004651c0`, unique range signature, duplicate `ProcessorNameString` hits in constructor and this raw body, registry read through `RegOpenKeyExW`/`RegQueryValueExW`/`RegCloseKey`, `0x00582d20` SimpleUString assignment, `Application +0x1c` writer versus `Application +0x428` copy-accessor caveat, Application ownership, and blank final C++ pending reachability and source declaration proof.
```

Placement context: replace the current [UID:0001MA] row nested under ChangeSpellSlotInputPane / SpellInputPanes around `0x005b32d0`, immediately after the aggregate [UID:0001M8] and before the following spell/say input pane neighborhood:

```text
    - [UID:0001MA][0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange](by-memory/0x005b32d0-0x005b340e.ChangeSpellSlotInputPaneSubmitSlotChange.md) 0x005b32d0-0x005b340e | method | ChangeSpellSlotInputPaneSubmitSlotChange : reconstructable : 86% : very-strong : Vtable-dispatched ChangeSpellSlotInputPane submitter. Wave2 identifies `ChangeSpellSlotInputPane::SubmitSpellSlotChange()` with sibling constructor/key-input context; live IDA reconfirms exact `0x13e` modeled boundary, vtable xref `0x0062fb18`, no ordinary callers, unique range signature, input read via `0x004f2300`, comma split, `a-z`/`A-Z` slot mapping to `1-52`, spell-record active-byte checks, `dword_67A748 + 0x13ead4` clear, four-byte opcode `0x30` packet through `0x00574bb0(dword_67A7EC, packet, 4)`, ChangeSpellSlotInputPane ownership, and blank final C++ pending source-quality player-data and packet-helper names.
```

## 2026-06-15 Goal 2 Chatting Compute/Packet Memory Batch

Assignment: `A001-goal2-chatting-compute-packet-memory-20260615-18`.

- Changed target docs: `by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`, `by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md`, `by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`, and `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md`.
- Changed support docs: `by-class/ChattingModifyHeightPane.md` and `by-class/-coverage-report.md`. Validator refreshed `project-level/-auto-completion-stats.md` projected stats and rebuilt `tools/validator.ini`; auto-generated coverage reports were reported as no-op.
- Evidence used: Wave2 method-analysis workflow (`method`, `decomp`, `struct`, and `filter --all-methods` where applicable), live IDA MCP session `a003_objectlist_dispatch_20260615` (`idb_list`, `lookup_funcs`, `entity_query`, `analyze_function`, xrefs/decompilation), plus current Chatting, ChattingPane, ChattingModifyHeightPane, ChattingVarietyPane, and owner-pollution docs.
- Score changes: [UID:0002EX] `80/88 -> 86/90`; [UID:0002F0] `80/88 -> 86/90`; [UID:0002F8] `80/88 -> 85/90`; [UID:0002FE] `80/88 -> 85/90`. Support [UID:00001W] `ChattingModifyHeightPane` changed `82/90 -> 85/90`, and the corresponding `by-class/-coverage-report.md` row now says `85%`.
- Owner/emitter decisions: no owner/emitter route changes. [UID:0002EX] remains `CANONICAL_OWNER:00001X`, `EMITTER_UIDS:00001X`; [UID:0002F0] remains `CANONICAL_OWNER:0000I5`, `EMITTER_UIDS:0000I5`; [UID:0002F8] remains `CANONICAL_OWNER:00001W`, `EMITTER_UIDS:00001W`; [UID:0002FE] remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`. Final C++ remains blank for all targets because source-quality field/global/protocol/helper names are still unresolved, and [UID:0002FE] is compiler-generated ABI glue.
- IDA DB changes: skipped. The pass was read-only evidence/refinement; no safe source-quality rename/comment/type edit was needed.
- Validation: ran `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` from `source-3/project-documentation` for the four target docs and `by-class/ChattingModifyHeightPane.md`; each scoped pass exited `0` with `ok: 1`. Ran the same validator command for `by-class/-coverage-report.md`; it exited `0` with `ok: 1`.
- Leases used: A001 held leases on the four target docs, `by-class/ChattingModifyHeightPane.md`, and this notes file before edits. `by-class/-coverage-report.md` was leased before the support coverage row edit.
- Blockers: no blocker for the assigned 85/85 documentation gate. Remaining blockers are final-C++/source-quality only: [UID:0002EX] needs final list/message field and mode-global names; [UID:0002F0] needs protocol subtype names and `dword_67A7C8` palette/config structure resolution; [UID:0002F8] needs final helper/global/field names; [UID:0002FE] should stay non-emitting compiler-generated forwarder evidence.
- Shared-report status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 chatting/packet supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0002EX] row nested under the Chatting UI range around `0x0047fc70`, immediately after [UID:0002EW] `ChattingPaneSetVisibleRowCount` and before [UID:0002EY] `ChattingPaneResetScrollRangeRaw`:

```text
        - [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md) 0x0047fc70-0x0047fd3b | method | ChattingPaneComputeLineCount : reconstructable : 86% : very-strong : ChattingPane line-count helper attached to ChattingPane. Wave2 identifies `ChattingPane::GetLineCount`; live IDA reconfirms exact `0xcb` boundary, six local scroll metric callers, no ordinary callees beyond virtual list/message dispatch, line-list pointer at `this+0x130`, count at `list+0x0c`, width constants `783` and `408` selected by `byte_66DA97`, ChattingPane parent `86/88`, and blank final C++ pending source-quality list/message field/type/global names.
```

Placement context: replace the current [UID:0002F0] row nested under the Chatting UI range around `0x0047ff80`, immediately after [UID:0002EZ] `ChatPacketType13Handler` and before [UID:0002F1] `ChattingBackPane...`:

```text
        - [UID:0002F0][0x0047ff80-0x00480640.ChatPacketType10Handler](by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md) 0x0047ff80-0x00480640 | packet handler plus switch table | ChatPacketType10Handler : reconstructable : 86% : very-strong : Chat packet opcode/type 10 handler routed from `0x0047f8c4`, attached to Chatting despite Wave2 FolderTreePane chat-message owner pollution. Wave2 identifies `HandleChatPacketType10`; live IDA reconfirms modeled body `0x0047ff80-0x004805d6`, switch/indirect-map tail `0x004805d6-0x00480632`, padding to successor `0x00480640`, subtype sets, MultiByteToWideChar conversion, bracket rewrites, subtype 18 extra dwords, AddChattingMessage calls, palette/global reads, and blank final C++ pending final protocol/global/palette names.
```

Placement context: replace the current [UID:0002F8] row nested under the ChattingModifyHeightPane method cluster around `0x00480ad0`, immediately after [UID:0002F7] `ChattingModifyHeightPaneCancelHotkeys` and before [UID:0002F9] `ChattingModifyHeightPaneOnPaint`:

```text
        - [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md) 0x00480ad0-0x00480ba3 | layout helper | ChattingModifyHeightPaneSetLineCount : reconstructable : 85% : very-strong : ChattingModifyHeightPane visible-line-count/layout helper. Wave2 identifies `SetLineCount`; live IDA reconfirms exact `0xd3` boundary, sole caller `0x004f7fd5`, successor paint method `0x00480bb0`, exact clamp behavior (`>50` falls back to 40, `<4` raises to 4), `dword_67ADD0` back-pane viewport rect, `dword_67ADCC` display-pane visible row update, handle rect `(792, 693-13*n, 807, 708-13*n)`, store at `this+0x100`, ChattingModifyHeightPane parent `85/90`, and blank final C++ pending source-quality helper/global/field names.
```

Placement context: replace the current [UID:0002FE] row nested under the ChattingVarietyPane cluster around `0x00481000`, immediately after [UID:0002FD] `ChattingVarietyPaneOnPaint` and before [UID:0002FF] `ChattingVarietyPane...RawHelper`:

```text
        - [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md) 0x00481000-0x0048100a | compiler-generated forwarder | ChattingVarietyPaneRefreshForwarder : ignored : 85% : very-strong : Non-reconstructable 10-byte secondary-subobject virtual forwarder. Wave2 explicitly excludes it as compiler-generated glue; live IDA reconfirms exact `0x0a` function, vtable data xref `0x00614ee8`, no code callers or callees, dispatch of vtable slot `+0x20` on `this+0x44`, adjacent padding, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters/C++.
```

## 2026-06-15 Goal 2 Chatting Compute/Packet Memory Source-Quality Resume

Continuation for assignment `A001-goal2-chatting-compute-packet-memory-20260615-18` after supervisor correction that `85/85` is not a stopping point.

- Changed target docs: `by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`, `by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md`, `by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`, and `by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md`.
- Score changes from the previously validated A001 pass: [UID:0002EX] `86/90 -> 87/90`; [UID:0002F0] `86/90 -> 87/90`; [UID:0002F8] `85/90 -> 86/91`; [UID:0002FE] `85/90 -> 86/91`.
- Evidence used: reran Wave2 method-analysis workflow (`method`, `decomp`, `xrefs`, `struct`, `filter --all-methods`) for `0x0047fc70`, `0x0047ff80`, `0x00480ad0`, and `0x00481000`; checked local docs for ChattingPane constructor/paint/measure, ColorStringChattingMessage, `g_useEpfAssets`, `g_pConfig`, `g_pMetaMan`, ChattingColorPane, RectBounds/BackPane helpers, and UI chat singleton slots; ran live IDA MCP against database `c001_clan_raw_ctor_20260615` with explicit `database` argument for `lookup_funcs` and `xrefs_to`.
- Resolved blockers: [UID:0002EX] message virtual target now supported as `ColorStringChattingMessage`-compatible and mode global normalized to [UID:0000SW] `g_useEpfAssets`; [UID:0002F0] `dword_67A7C8` corrected to [UID:00028Q] `g_pConfig`, not Wave2's conflicting `g_pMetaMan`, and chat color offsets tied to ChattingColorPane persisted bytes; [UID:0002F8] helper/global names resolved to BackPane `GetBounds`, `InitRectBounds`, `g_pChattingBackPane`, and `g_pChattingDisplayPane`; [UID:0002FE] compiler-generated forwarder evidence is closed with fresh Wave2 exclusion and live IDA vtable-only xref evidence.
- Remaining blockers: [UID:0002EX] still needs final source container/type/member spelling for the list at `this+0x130`; [UID:0002F0] still needs protocol subtype names and exact `RegistryConfig` chat color field names; [UID:0002F8] still needs final original method/member spelling for the `this+0x100` handle rectangle; [UID:0002FE] has no reconstruction blocker because the correct outcome is ignored/non-emitting compiler-generated ABI glue.
- B-agent handoff: target [UID:0002EX] and [UID:0002F0]. Question: infer original source structure/names where binary evidence stops. Evidence already checked: Wave2 names `m_chatLineList`, `ChatEntryList`, and `g_useHighResLayout`; local docs reject the global alias in favor of `g_useEpfAssets`; constructor proves `sub_4F3060(list, 4, 1000)` and vtable insert slot `+0x18`; paint/line-count prove fetch slot `+0x10`, count at `+0x0c`, and `ColorStringChattingMessage` measure/draw slots; packet docs prove subtype sets and text/extra-value layouts; config docs prove `g_pConfig + 0x28de82..0x28de8d` are chat color bytes. What remains for B-agent inference: whether the original list declaration used a project `List`/template/container type and what member name is defensible; whether packet subtype values `0/4/5/11/12/17/18` can be named from adjacent protocol/UI semantics; whether the twelve config bytes have stable original field names from broader RegistryConfig layout rather than local chat behavior.
- Validation: ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` for the four changed target docs from `source-3/project-documentation`; each pass exited `0` with `ok: 1`.
- Leases used: A001 re-leased the four target docs and this notes file before edits after the initial lease window expired. No by-memory coverage report lease/edit was attempted.
- Shared-report status: supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 chatting/packet continuation supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0002EX] row nested under the Chatting UI range around `0x0047fc70`, immediately after [UID:0002EW] `ChattingPaneSetVisibleRowCount` and before [UID:0002EY] `ChattingPaneResetScrollRangeRaw`:

```text
        - [UID:0002EX][0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount](by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md) 0x0047fc70-0x0047fd3b | method | ChattingPaneComputeLineCount : reconstructable : 87% : very-strong : ChattingPane line-count helper attached to ChattingPane. Wave2 identifies `ChattingPane::GetLineCount`; live IDA reconfirms exact `0xcb` boundary, six local scroll metric callers, no ordinary callees beyond virtual list/message dispatch, list pointer at `this+0x130`, count at `list+0x0c`, `ColorStringChattingMessage`-compatible measure virtual target, width constants `783` and `408` selected by [UID:0000SW] `g_useEpfAssets`, ChattingPane parent `86/88`, and blank final C++ pending final list container/member spelling.
```

Placement context: replace the current [UID:0002F0] row nested under the Chatting UI range around `0x0047ff80`, immediately after [UID:0002EZ] `ChatPacketType13Handler` and before [UID:0002F1] `ChattingBackPane...`:

```text
        - [UID:0002F0][0x0047ff80-0x00480640.ChatPacketType10Handler](by-memory/0x0047ff80-0x00480640.ChatPacketType10Handler.md) 0x0047ff80-0x00480640 | packet handler plus switch table | ChatPacketType10Handler : reconstructable : 87% : very-strong : Chat packet opcode/type 10 handler routed from `0x0047f8c4`, attached to Chatting despite Wave2 FolderTreePane chat-message owner pollution. Wave2 identifies `HandleChatPacketType10`; live IDA reconfirms modeled body `0x0047ff80-0x004805d6`, switch/indirect-map tail `0x004805d6-0x00480632`, padding to successor `0x00480640`, subtype sets, MultiByteToWideChar conversion, bracket rewrites, subtype 18 extra dwords, AddChattingMessage calls, and `g_pConfig + 0x28de84..0x28de8d` chat color reads tied to ChattingColorPane persisted bytes; blank final C++ pending final protocol subtype and RegistryConfig field names.
```

Placement context: replace the current [UID:0002F8] row nested under the ChattingModifyHeightPane method cluster around `0x00480ad0`, immediately after [UID:0002F7] `ChattingModifyHeightPaneCancelHotkeys` and before [UID:0002F9] `ChattingModifyHeightPaneOnPaint`:

```text
        - [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md) 0x00480ad0-0x00480ba3 | layout helper | ChattingModifyHeightPaneSetLineCount : reconstructable : 86% : very-strong : ChattingModifyHeightPane visible-line-count/layout helper. Wave2 identifies `SetLineCount`; live IDA reconfirms exact `0xd3` boundary, sole caller `0x004f7fd5`, successor paint method `0x00480bb0`, exact clamp behavior (`>50` falls back to 40, `<4` raises to 4), [UID:0002WZ] `g_pChattingBackPane` viewport rect, [UID:0002WX] `g_pChattingDisplayPane` visible row update, `BackPane::GetBounds`, `InitRectBounds`, handle rect `(792, 693-13*n, 807, 708-13*n)`, store at `this+0x100`, ChattingModifyHeightPane parent `85/90`, and blank final C++ pending final method/member spelling.
```

Placement context: replace the current [UID:0002FE] row nested under the ChattingVarietyPane cluster around `0x00481000`, immediately after [UID:0002FD] `ChattingVarietyPaneOnPaint` and before [UID:0002FF] `ChattingVarietyPane...RawHelper`:

```text
        - [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md) 0x00481000-0x0048100a | compiler-generated forwarder | ChattingVarietyPaneRefreshForwarder : ignored : 86% : very-strong : Non-reconstructable 10-byte secondary-subobject virtual forwarder. Wave2 explicitly excludes it as compiler-generated glue; live IDA reconfirms exact `0x0a` function, only vtable data xref `0x00614ee8`, no code callers or callees, dispatch of vtable slot `+0x20` on `this+0x44`, adjacent padding, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank emitters/C++.
```

## 2026-06-15 Goal 2 Clan Name Raw Constructors

Assignment: `A001-goal2-clan-name-raw-constructors-20260615-20`.

- Changed target docs: `by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md` and `by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md`.
- Changed support docs: `by-class/ClanSummonNameInputDialog.md`, `by-class/ClanChangeNameInputDialog.md`, and `by-class/-coverage-report.md`. Validator refreshed projected stats/autogen state; target UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Score changes: [UID:0002NX] `80/88 -> 85/90`; [UID:0002O1] `80/88 -> 85/90`; support [UID:00002M] `84/88 -> 85/89`; support [UID:000028] `84/88 -> 85/89`.
- Owner/emitter decisions: no route changes. [UID:0002NX] remains `CANONICAL_OWNER:00002M`, `EMITTER_UIDS:00002M`; [UID:0002O1] remains `CANONICAL_OWNER:000028`, `EMITTER_UIDS:000028`. The class pages now clear the strict direct-owner gate and still route through [UID:0000I8] `Clan`; [UID:0000IA] `ClanDialogs` remains a split candidate, not the stronger owner.
- Evidence used: Wave2 method-analysis workflow (`method`, `decomp`, `xrefs`, `struct`, `filter --all-methods`, `diff`) for `0x00489270` and `0x004894d0`; related Clan class/file/vtable/layout docs; C001/A003 neighboring clan raw-constructor notes; live IDA MCP database `b001_chatting_source_quality_20260615`; and local PE scans on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Evidence summary: Wave2 records both targets as included constructor candidates, each size `0x35` / 53 bytes and class wrapper size `0x269` / 617 bytes (Verified with `int_convert.py`), with zero callers and one callee to `0x00488b40`. Live IDA reconfirmed no functions at the raw starts/end padding, no xrefs to the raw starts, exact constructor bytes, `retn 4`, eleven-byte padding, and three vtable stores per target. Modeled opener sites inline the same base-call/vtable-store construction sequence at `0x00485227`/`0x0048828f` for summon and `0x00485332`/`0x00488429` for change-name. Local PE scans found zero absolute VA hits, zero RVA hits, and zero direct relative branch/call targets to either raw start.
- Disposition: both pages remain reconstructable raw constructor-shaped source-authored code. They were not reclassified to ignored because Wave2 records real constructor bodies, IDA bytes are coherent source-owned constructor bodies, vtable/store identity is strong, and the owning classes/submitters are real Clan modal-dialog classes. Final C++ remains blank because the raw standalone starts have no function object, xref, pointer hit, branch target, or proven source placement separate from the modeled inline construction routes.
- IDA DB changes: none. This pass was read-only; no raw function creation, rename, comment, or type edit was justified.
- B-agent handoff: recommended but not required for this A001 score pass. Question: using broader original-source/build heuristics, decide whether the unreferenced raw constructor-shaped bodies should ultimately remain as reconstructable standalone constructor evidence, be treated as dead/duplicate code caused by inlined construction paths, or be excluded from final source emission beyond the current blank-C++ rationale. Evidence already checked is listed above; binary evidence alone does not safely settle that final source-structure question.
- Validation: `python .\tools\validator.py --mode file --file <changed by-* doc> --apply --queue-timeout 240` was run for both target docs, both support class docs, and `by-class/-coverage-report.md`; each pass exited `0` with `ok: 1`. A concise revalidation loop also exited `0` with `ok: 1` for all five changed by-* files.
- Leases used: A001 leased the two targets and notes before edits; the initial memory/notes leases expired during the evidence pass, so A001 released/reacquired the full changed set before validation/final notes. A001 also leased both class support docs and `by-class/-coverage-report.md` before support edits. No `by-memory/-coverage-report.md` edit or lease was attempted.
- Shared-report status: supervisor applied and validated the two replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 clan-name raw-constructor supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0002NX] row nested under [UID:00010K] `ClanNameDialogSubmitters`, immediately after the [UID:0000VN] `0x0048926e-0x00489270` padding row and before the [UID:0000VN] `0x004892a5-0x004892b0` padding row:

```text
        - [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) 0x00489270-0x004892a5 | raw constructor | ClanSummonNameInputDialogRawConstructor : reconstructable : 85% : very strong : A001 2026-06-15 refresh raises to 85/90: Wave2 confirms an included `ClanSummonNameInputDialog` constructor record, size `0x35` / 53 bytes and wrapper size `0x269` / 617 bytes (Verified with `int_convert.py`), zero callers, one base-constructor callee, and only constructor/submitter methods for the class; live IDA reconfirms no function object at `0x00489270`/`0x004892a5`, no start xrefs, exact bytes, base-constructor call at `0x0048927d`, three vtable stores at `0x00489282`/`0x0048928a`/`0x00489294`, eleven-byte padding before the adjacent submitter, inline modeled open-site construction at `0x00485227`/`0x0048828f`, zero local PE VA/RVA/relative-branch hits to the raw start, owner/emitter route through [UID:00002M][ClanSummonNameInputDialog](by-class/ClanSummonNameInputDialog.md), and blank final C++ pending raw-constructor reachability/source-placement proof.
```

Placement context: replace the current [UID:0002O1] row nested under [UID:00010K] `ClanNameDialogSubmitters`, immediately after the [UID:0000VN] `0x004894ce-0x004894d0` padding row and before the [UID:0000VN] `0x00489505-0x00489510` padding row:

```text
        - [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) 0x004894d0-0x00489505 | raw constructor | ClanChangeNameInputDialogRawConstructor : reconstructable : 85% : very strong : A001 2026-06-15 refresh raises to 85/90: Wave2 confirms an included `ClanChangeNameInputDialog` constructor record, size `0x35` / 53 bytes and wrapper size `0x269` / 617 bytes (Verified with `int_convert.py`), zero callers, one base-constructor callee, and only constructor/submitter methods for the class; live IDA reconfirms no function object at `0x004894d0`/`0x00489505`, no start xrefs, exact bytes, base-constructor call at `0x004894dd`, three vtable stores at `0x004894e2`/`0x004894ea`/`0x004894f4`, eleven-byte padding before the adjacent submitter, inline modeled open-site construction at `0x00485332`/`0x00488429`, zero local PE VA/RVA/relative-branch hits to the raw start, owner/emitter route through [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md), and blank final C++ pending raw-constructor reachability/source-placement proof.
```

## 2026-06-15 Goal 2 Clan Item / Employee Quantity / AddEmployee Raw Constructor

Assignment: `A001-goal2-lowcompletion-clan-employee-20260615-22`.

- Changed target docs: `by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md`, `by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md`, and `by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md`.
- Score changes: [UID:00010N] `80/88 -> 85/90`; [UID:0002HI] `80/88 -> 85/90`; [UID:000139] `80/88 -> 85/90`.
- Owner/emitter decisions: [UID:00010N] remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters/C++ because it is a non-emitting aggregate/index whose exact child pages own the source behavior. [UID:0002HI] remains routed through [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md). [UID:000139] remains routed through [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md); final C++ stays blank pending raw-constructor source-placement proof.
- Evidence used: local by-memory/by-class/by-type/by-item support pages for ClanItemDialog, EmployeeQuantityInputDialogPane, AddEmployeeItemDialog, vtables, layout docs, inline construction item, and the parent EmployeeDialogPanes aggregate; live IDA MCP database `c001_midiplayer_rdata_20260615`; project `tools/int_convert.py` for `0xab` / 171, `0x9e` / 158, `0x40` / 64, `0x274` / 628, `0x270` / 624, and `0x26c` / 620 conversions.
- Evidence summary: live IDA reconfirmed [UID:00010N] as exactly the two child functions `0x0048a100` size `0x1f` and `0x0048a120` size `0x9e`, with boundary padding, EH refs to the vtable-reset tail, vtable-only refs to the confirm method, and no extra aggregate-owned code. [UID:0002HI] was reconfirmed as exact `0xab` / 171-byte vtable-only action method at `0x004a4a30`, with action id `1` submit, action id `2` close, control id `4`, text read/parse, owner/index offsets, `sub_5975E0(owner+0xa4, 5, 0, selectedIndex, parsedQuantity)`, and close helpers. [UID:000139] was reconfirmed as no function/no xrefs at `0x004a4ae0`, no absolute VA/RVA pointer-byte hits for the raw start, exact constructor-shaped bytes through `retn 4`, raw base-constructor xref with no containing function, raw vtable-store xrefs with no containing function, and a matching live inline construction path in `EmployeeDialogPane::OnButtonAction`.
- Source-quality blockers: [UID:00010N] has no aggregate-level final-C++ blocker because it is intentionally ignored/non-emitting; child pages still own final method/base/control names. [UID:0002HI] remains behaviorally ready but final C++ is blocked by original source names for action/control ids, close helpers, and the parent timer/event subobject. [UID:000139] remains blocked by raw-constructor source placement, not by lack of byte evidence.
- B-agent handoff: target [UID:000139]. Question: using broader original-source/build heuristics, should the retained but unreferenced raw constructor-shaped bytes at `0x004a4ae0-0x004a4b1f` be represented as a standalone out-of-line `AddEmployeeItemDialog` constructor in final source, treated as dead/duplicate retained code caused by an inline construction path, or excluded from final source emission while preserving the documentation evidence? Evidence already checked: no IDA function object at raw start/end, no xrefs to `0x004a4ae0`, no absolute VA/RVA pointer-byte hits for the raw start, exact constructor-shaped bytes with `retn 4`, base-constructor xref at `0x004a4aee` with no containing function, raw vtable-store xrefs with no containing function, live inline construction at `0x004a339f`, matching inline vtable stores at `0x004a33a4`/`0x004a33aa`/`0x004a33b4`, and matching owner store at `+0x270` / 624 (Verified with `int_convert.py`). Binary evidence alone does not prove original source placement for the unreferenced raw island.
- IDA DB changes: none. This pass was read-only; no function creation, rename, comment, patch, or type edit was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <target> --apply --queue-timeout 240` for the three changed by-memory docs from `source-3/project-documentation`; each pass exited `0` with `ok: 1`. Post-check `rg -n "00010N|0002HI|000139" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three target docs and this notes file before edits. No `by-memory/-coverage-report.md` edit or lease was attempted.
- Shared-report status: supervisor applied and validated the three replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 clan/employee supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:00010N] row nested under the ClanItemDialog area around `0x0048a100`, immediately after the [UID:0000VN] `0x0048a0fb-0x0048a100` padding row and before [UID:0002OC] `ClanItemDialogVtableResetDestructorTail`:

```text
    - [UID:00010N][0x0048a100-0x0048a1be.ClanItemDialogCore](by-memory/0x0048a100-0x0048a1be.ClanItemDialogCore.md) 0x0048a100-0x0048a1be | aggregate | ClanItemDialogCore : ignored : 85% : very-strong : Non-emitted aggregate/index for exact `ClanItemDialog` vtable-reset and confirm-validation child pages; A001 2026-06-15 live IDA refresh reconfirmed only the two exact child functions, `0x0048a100` size `0x1f` and `0x0048a120` size `0x9e`, boundary padding before/between/after the child functions, EH refs to the reset tail, vtable-only refs to the confirm method, no additional aggregate-owned executable code, and blank aggregate C++ because child pages own source behavior.
```

Placement context: replace the current [UID:0002HI] row nested under [UID:000138] `EmployeeDialogPanes`, immediately after [UID:0002HH] `EmployeeQuantityInputDialogPaneConstructor` and before [UID:000139] `AddEmployeeItemDialogRawConstructor`:

```text
        - [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) 0x004a4a30-0x004a4adb | method | EmployeeQuantityInputDialogPaneOnAction : reconstructable : 85% : very-strong : Exact `0xab` / 171-byte vtable-only quantity action handler (Verified with `int_convert.py`); A001 2026-06-15 live IDA reconfirmed padding at both edges, sole vtable xref `0x00619080`, action id `1` submit, action id `2` close, control id `4`, `L"%d"` parse path, owner/index offsets `+0x26c/+0x270`, `sub_5975E0(owner+0xa4, 5, 0, selectedIndex, parsedQuantity)`, close helpers, and blank final C++ pending final action/control/helper names.
```

Placement context: replace the current [UID:000139] row immediately after [UID:0002HI] `EmployeeQuantityInputDialogPaneOnAction` and before [UID:00013A] `AddEmployeeItemDialog`:

```text
    - [UID:000139][0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor](by-memory/0x004a4ae0-0x004a4b1f.AddEmployeeItemDialogRawConstructor.md) 0x004a4ae0-0x004a4b1f | raw constructor | AddEmployeeItemDialogRawConstructor : reconstructable : 85% : very-strong : Raw constructor-shaped `AddEmployeeItemDialog` byte island; A001 2026-06-15 source-placement pass reconfirmed no IDA function at `0x004a4adb`/`0x004a4ae0`/`0x004a4b1f`, no xrefs to `0x004a4ae0`, no absolute VA/RVA pointer-byte hits for the raw start, exact prologue/base-constructor call/owner store at `+0x270`/three vtable stores/`retn 4`/successor padding, raw `0x004ae4c0` and vtable xrefs with no containing function, matching live inline construction in [UID:0003KY][0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction](by-memory/0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction.md), owner/emitter route through [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md), and blank final C++ pending B-agent source-placement decision for the retained unreferenced raw island.
```

## 2026-06-16 Goal 2 Queue Raw Helpers

Assignment: `A001-goal2-lowconfidence-queue-raw-helpers-20260615-23`.

- Changed target docs: `by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md`, `by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md`, and `by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md`.
- Score changes: [UID:0001FP] `82/84 -> 85/88`; [UID:0001FQ] `82/84 -> 85/88`; [UID:0001FR] `82/85 -> 85/88`.
- Owner/emitter decisions: no route changes. All three remain `CANONICAL_OWNER:0000MW`, `EMITTER_UIDS:0000MW`, `RECONSTRUCTABLE:TRUE`, and blank final C++ pending source-emission naming/reachability proof. [UID:0000MW] `Queue` remains the owning modeled file; [UID:0001FR] now references the updated [UID:0002H5] `Queue` class support score.
- Evidence used: local `Queue` by-memory/by-class/by-file support pages, adjacent constructor/destructor/scalar-deleting-destructor docs, `MemoryMan` helper docs, `by-meta/client_containers.md`, live IDA MCP database `c001_midiplayer_rdata_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, and project `tools/int_convert.py` for `0x45` / 69, `0x0a` / 10, `0x0b` / 11, `0x07` / 7, `0x06` / 6, and `0x18` / 24 conversions.
- Evidence summary: live IDA reconfirmed no function objects at the raw helper starts/endpoints, no xrefs to `0x00553ac0`, `0x00553b10`, or `0x00553b60`, no absolute VA or RVA pointer-byte hits for any raw start, no modeled callees because the starts are not IDA functions, exact padding before/after the helpers, and exact bytes through each endpoint. [UID:0001FP] and [UID:0001FQ] each have complete `0x45` / 69-byte (Verified with `int_convert.py`) bodies ending in `retn 4`, use `GetMemoryMan` plus `MemmoveWrapper`, and update wrapped write/read indices respectively. [UID:0001FR] is the exact ten-byte empty predicate comparing read/write indices at `+0x10/+0x14` with no calls. Parent support was checked through Queue constructor/destructors, scalar-deleting destructor vtable evidence at `0x00622d24`, [UID:0002H5] `Queue` class, and [UID:0000MW] `Queue` file.
- Source-quality blockers: no score blocker remains. Final C++ remains blank because IDA has no normal function objects for these raw starts, no code callers, no pointer hits, no direct branch targets, and no proof of original method spelling or final source representation. `QueueWriteSlotRaw`, `QueueReadSlotRaw`, and `QueueIsEmptyRaw` are evidence-backed role names; original names such as push/pop/enqueue/dequeue/write/read were not proven.
- Source-emission handoff question, if needed later: should the retained raw Queue helper byte islands be emitted as out-of-line Queue methods with role names, mapped to original queue API spellings inferred from broader source conventions, or kept documented but blank in final C++ because no reachability/source-placement evidence points to the raw starts? Evidence already checked: no IDA functions at raw starts, no xrefs/callers, no VA/RVA pointer hits, exact padding/body bytes, Queue layout support, MemoryMan/copy helper calls for read/write helpers, and scalar-destructor/vtable evidence for the adjacent modeled Queue region.
- IDA DB changes: none. This pass was read-only; no function creation, rename, comment, patch, or type edit was justified because the helpers have no IDA function objects or discovered references and would risk overstating raw-start reachability.
- Validation: ran `python .\tools\validator.py --mode file --file by-memory\0x00553ac0-0x00553b05.QueueWriteSlotRaw.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-memory\0x00553b10-0x00553b55.QueueReadSlotRaw.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-memory\0x00553b60-0x00553b6a.QueueIsEmptyRaw.md --apply --queue-timeout 240` from `source-3/project-documentation`; each pass exited `0` with `ok: 1`. Post-checks confirmed each target has `COMPLETION:85` and `CONFIDENCE:88`; `rg -n "0001FP|0001FQ|0001FR" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three target docs and this notes file before edits. A refresh attempt for this notes lease was rejected because the same A001 lease was still active. No `by-memory/-coverage-report.md` edit or lease was attempted.
- Shared-report status: supervisor applied and validated the three `by-memory/-coverage-report.md` replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Queue raw-helper supervisor-owned rows remain pending.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0001FP] row nested under [UID:0000MW] `Queue`, immediately after the [UID:0000VN] `0x00553ab9-0x00553ac0` padding row and before the [UID:0000VN] `0x00553b05-0x00553b10` padding row:

```text
    - [UID:0001FP][0x00553ac0-0x00553b05.QueueWriteSlotRaw](by-memory/0x00553ac0-0x00553b05.QueueWriteSlotRaw.md) 0x00553ac0-0x00553b05 | raw helper | QueueWriteSlotRaw : reconstructable : 85% : very-strong : Raw Queue write-slot helper; A001 2026-06-16 live IDA reconfirmed no function object at `0x00553ac0`, no xrefs/callers, no absolute VA/RVA pointer-byte hits for the raw start, exact seven-byte pre-padding, complete `0x45` / 69-byte body (Verified with `int_convert.py`) through `retn 4`, eleven-byte post-padding, MemoryMan getter/copy-helper calls, slot-size/write-index/wrap behavior, Queue class/file parent support, and blank final C++ pending original method name/signature and raw-helper reachability representation.
```

Placement context: replace the current [UID:0001FQ] row nested under [UID:0000MW] `Queue`, immediately after the [UID:0000VN] `0x00553b05-0x00553b10` padding row and before the [UID:0000VN] `0x00553b55-0x00553b60` padding row:

```text
    - [UID:0001FQ][0x00553b10-0x00553b55.QueueReadSlotRaw](by-memory/0x00553b10-0x00553b55.QueueReadSlotRaw.md) 0x00553b10-0x00553b55 | raw helper | QueueReadSlotRaw : reconstructable : 85% : very-strong : Raw Queue read-slot helper; A001 2026-06-16 live IDA reconfirmed no function object at `0x00553b10`, no xrefs/callers, no absolute VA/RVA pointer-byte hits for the raw start, exact eleven-byte pre-padding, complete `0x45` / 69-byte body (Verified with `int_convert.py`) through `retn 4`, eleven-byte post-padding, MemoryMan getter/copy-helper calls, slot-size/read-index/wrap behavior, Queue class/file parent support, and blank final C++ pending original method name/signature and raw-helper reachability representation.
```

Placement context: replace the current [UID:0001FR] row nested under [UID:0000MW] `Queue`, immediately after the [UID:0000VN] `0x00553b55-0x00553b60` padding row and before the [UID:0000VN] `0x00553b6a-0x00553b70` padding row:

```text
    - [UID:0001FR][0x00553b60-0x00553b6a.QueueIsEmptyRaw](by-memory/0x00553b60-0x00553b6a.QueueIsEmptyRaw.md) 0x00553b60-0x00553b6a | raw helper | QueueIsEmptyRaw : reconstructable : 85% : very-strong : Raw Queue empty predicate; A001 2026-06-16 live IDA reconfirmed no function object at `0x00553b60`, no xrefs/callers/callees, no absolute VA/RVA pointer-byte hits for the raw start, exact eleven-byte pre-padding, ten-byte body (Verified with `int_convert.py`) comparing read/write indices at `+0x10/+0x14`, six-byte post-padding before scalar deleting destructor, Queue class/file parent support, and blank final C++ pending original method spelling and raw-helper reachability representation.
```

## 2026-06-16 Goal 2 Class Low-Confidence Macro / Interface / CreateUser

Assignment: `A001-goal2-class-lowconfidence-macro-interface-createuser-20260616-24`.

- Changed target docs: `by-class/SpellMacroEditControlPane.md`, `by-class/InterfaceEfx.md`, and `by-class/NewCreateUserDialogPane.md`.
- Changed support docs: `by-class/-coverage-report.md`, `by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md`, and `by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md`.
- Score changes: [UID:0000DQ] `84/84 -> 86/88`; [UID:00006N] `82/86 -> 85/88`; [UID:00008Z] `82/86 -> 85/88`; support [UID:00018G] `84/88 -> 85/89`; support [UID:0002QS] `84/88 -> 85/89`.
- Owner/emitter decisions: no route changes. [UID:0000DQ] remains `CANONICAL_OWNER:0000KY`, `EMITTER_UIDS:0000KY`; [UID:00006N] and [UID:00018G] remain routed through [UID:0000K9][InterfaceEfx](by-file/InterfaceEfx.md); [UID:00008Z] and [UID:0002QS] remain routed through [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md). All final C++ blocks stay blank.
- Evidence used: local by-class/by-file/by-memory/by-global/by-type/by-resource support pages; live IDA MCP database `c001_midiplayer_rdata_20260615`; project `tools/int_convert.py` conversions for newly cited function sizes; and a local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for `0x0052c360` reachability.
- Evidence summary: `SpellMacroEditControlPane` live IDA reconfirmed constructor/getter/paint/input/selectable/teardown/destructor sizes, constructor calls from `SpellMacroDialog`, sole getter caller, teardown-helper no-xref status, scalar-destructor adjustor/vtable refs, and three vtable-view globals. `InterfaceEfx` live IDA reconfirmed constructor/cleanup/play/render/tick/destructor sizes, seven constructor xrefs, seven play xrefs, vtable/resource-string refs, and 45 xrefs to the generic timer remove wrapper, preserving TimerMgr wrapper ownership. `NewCreateUserDialogPane` live IDA reconfirmed constructor/selector/command/submit/packet/payload/reply/destructor sizes, internal command/submit/packet/reply edges, shape-control construction at `0x0052c7aa`, singleton/vtable refs, and no constructor xrefs; local PE scans also found zero absolute VA pointer hits, zero RVA pointer hits, and zero direct `E8`/`E9` branch/call hits to `0x0052c360`.
- Blockers investigated: final destructor/helper representation for `SpellMacroEditControlPane` remains unresolved because the non-deleting teardown helper has no direct xrefs and adjustor thunks are ABI support, not user-facing source methods. `InterfaceEfx` field/base/callback names remain provisional despite strong behavior evidence; timer-wrapper ownership was rejected after broad xref review. `NewCreateUserDialogPane` direct constructor reachability remains a real blocker after IDA xrefs and PE pointer/branch scans; binary evidence supports retained newer create-user code but not final source-placement/emission shape. These blockers no longer limit documentation below 85/85, but they still block final C++.
- IDA DB changes: none. This pass was read-only; no IDA rename, comment, type, function creation, or patch was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc> --apply --queue-timeout 240` for all six changed by-* docs from `source-3/project-documentation`; each exited `0` with `ok: 1`. Validator updates removed [UID:0000DQ], [UID:00006N], and [UID:00008Z] from `project-level/-auto-completion-stats.md`; post-check `rg -n "0000DQ|00006N|00008Z" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three target class docs, `by-class/-coverage-report.md`, the two support memory docs, and this notes file before edits. No `by-memory/-coverage-report.md` edit or lease was attempted.
- Shared-report status: supervisor applied and validated the two `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; no A001 class-support supervisor-owned rows remain pending. The `by-class/-coverage-report.md` rows were edited directly by A001 and validated.

### Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows

Placement context: replace the current [UID:00018G] row immediately after the [UID:0000VN] `0x004e97a3-0x004e97b0` padding row and before [UID:00018H] `InterfaceEfxMgrTriggerInterfaceEffect`:

```text
    - [UID:00018G][0x004e97b0-0x004ea121.InterfaceEfxAndMgr](by-memory/0x004e97b0-0x004ea121.InterfaceEfxAndMgr.md) 0x004e97b0-0x004ea121 | class-method-cluster | InterfaceEfxAndMgr : reconstructable : 85% : very-strong : InterfaceEfx/InterfaceEfxMgr aggregate attached to InterfaceEfx.cpp; A001 2026-06-16 live IDA reconfirmed constructor/cleanup/play/render/tick/destructor/manager method sizes, seven InterfaceEfx constructor xrefs, seven Play xrefs, vtable/resource-string refs, g_pInterfaceEfxMgr lifecycle, 45-xref timer-wrapper non-ownership, trigger/spawner/helper children, and blank final C++ pending final field/base/callback names and source split.
```

Placement context: replace the current [UID:0002QS] row nested under [UID:0001CR] `CreateUserDialogVariants`, immediately after [UID:0002QR] `NewUserDialogPane2CreateUserVariant` and before [UID:0002QT] `CreateUserDialogPaneCore`:

```text
        - [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) 0x0052c360-0x0052dcf5 | executable child | NewCreateUserDialogPaneCore : reconstructable : 85% : very-strong : Exact newer create-user dialog child range; A001 2026-06-16 live IDA reconfirmed constructor/selector/command/submit/packet/payload/reply/destructor sizes, internal command-to-submit, submit-to-packet, reply-to-payload edges, shape-control construction at `0x0052c7aa`, singleton/vtable refs, and retained direct-constructor reachability blocker after zero xrefs, zero absolute VA/RVA pointer hits, and zero direct E8/E9 branch/call hits to `0x0052c360`; final C++ blank pending source-placement and field/helper names.
```

## 2026-06-16 Goal 2 Class Low-Confidence NewUserMisc / PixelEffecter / QuitDialog

Assignment: `A001-goal2-class-lowconfidence-newusermisc-effects-quit-20260616-25`.

- Changed target docs: `by-class/NewUserMiscDialogPane.md`, `by-class/PixelEffecter.md`, and `by-class/QuitDialog.md`.
- Changed support docs: `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`, `by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md`, and `by-class/-coverage-report.md`. Validator refreshed generated stats/autogen state. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:00009F] `82/86 -> 85/88`; [UID:0000AI] `82/86 -> 85/88`; [UID:0000BG] `82/86 -> 85/88`; support [UID:0002Q7] `82/88 -> 85/89`; support [UID:0001KT] `82/86 -> 85/89`.
- Owner/emitter decisions: no route changes. [UID:00009F] and [UID:0002Q7] remain routed through [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md). [UID:0000AI] remains routed through [UID:0000IZ][Effects](by-file/Effects.md). [UID:0000BG] remains routed through [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md). [UID:0001KT] remains routed through [UID:0000BG][QuitDialog](by-class/QuitDialog.md). All final C++ blocks remain blank.
- Evidence used: local by-class/by-file/by-memory/by-global/by-type/by-item support pages; live IDA MCP database `c001_midiplayer_rdata_20260615`; `tools/int_convert.py` for `0x45`, `0x50`, `0x9b`, `0x0e`, and `0x13` conversions; and a local read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` for raw-start VA/RVA/direct-branch hits.
- Evidence summary: NewUserMisc live IDA reconfirmed modeled function sizes, raw non-function starts at `0x004fbfd0`, `0x004fca20`, and `0x004fcac0`, constructor caller `sub_4FA5B0`, vtable refs through constructor/raw cleanup/scalar destructor paths, singleton refs at `0x004fb687`, `0x004fb68e`, `0x004fbfff`, `0x00502400`, and `0x00502a22`, unique raw-range signatures, and zero absolute-VA/RVA/direct `E8`/`E9` hits to all three raw starts.
- Evidence summary: PixelEffecter live IDA reconfirmed `0x0055a2a0` is still not an IDA function, the `0x0055a2a0-0x0055a2b3` constructor body has a unique exact signature, `0x006235c4` receives refs from raw store `0x0055a2a9` and derived/base store `0x0055a30b`, neighboring ScreenEffecter functions remain modeled, and local PE scanning found zero absolute-VA/RVA/direct `E8`/`E9` hits to the raw constructor start.
- Evidence summary: QuitDialog live IDA reconfirmed constructor/key/OK function sizes and decompilation, direct constructor callers `0x00507068` and `0x005bd202`, launcher inline modal setup rather than a direct `0x005addf0` call, key/OK vtable refs `0x0062f150` and `0x0062f13c`, `g_pBackPane` parent/context use, and `0x005adedb-0x005adf20` as a unique switch-data/alignment range rather than a hidden source method.
- Blockers investigated: NewUserMisc raw destructor/packet-helper source representation remains unresolved after no-function/no-xref/no-PE-hit checks; final standalone-vs-umbrella source split also remains open. PixelEffecter raw constructor remains unresolved after no-function/no-xref/no-PE-hit checks, so original constructor spelling/source representation remains a final-C++ blocker. QuitDialog's former interior-gap blocker is resolved; remaining blockers are final alert/dialog helper names, inherited key-event type names, and final `g_pBackPane` declaration context.
- IDA DB changes: none. This pass was read-only; no function creation, rename, comment, type, patch, or save was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc> --apply --queue-timeout 240` from `source-3/project-documentation` for all six changed by-* docs; each pass exited `0` with `ok: 1`. A filtered revalidation pass also returned `ok: 1` for all six files. Post-check `rg -n "00009F|0000AI|0000BG|0002Q7|0001KT" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three target class docs, `by-class/-coverage-report.md`, the two support memory docs, and this notes file before edits. No `by-memory/-coverage-report.md` edit or lease was attempted.
- Shared-report status: supervisor applied and validated the two `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 NewUserMisc/PixelEffecter/QuitDialog supervisor-owned rows remain pending.

### Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0002Q7] row nested under [UID:00019U] `NewUserMiscShapeAndPasswordDialogs`, immediately after the [UID:00019U] aggregate row and before [UID:00019V] `SelectBoxControlPane`:

```text
        - [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) 0x004fb630-0x004fccee | class method/helper cluster | NewUserMiscDialogPaneCoreAndPacketHelpers : reconstructable : 85% : very-strong : A001 2026-06-16 live IDA refresh reconfirmed modeled constructor/handler/reply/destructor-family sizes, raw non-function starts at `0x004fbfd0`, `0x004fca20`, and `0x004fcac0`, unique raw-range signatures, vtable refs through constructor/raw cleanup/scalar destructor paths, singleton lifecycle refs, local PE zero absolute-VA/RVA/direct `E8`/`E9` hits to all raw starts, exact attachment to [UID:0000LX][NewUserMiscDialogPane](by-file/NewUserMiscDialogPane.md), and blank final C++ pending raw-helper source representation and names.
```

Placement context: replace the current [UID:0001KT] row immediately after [UID:0001KS] `QuitInputPaneCore` and before [UID:0001KV] `SpellStringInputPane`:

```text
    - [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md) 0x005addf0-0x005adf2e | class method cluster | QuitDialogCore : reconstructable : 85% : very-strong : Modal QuitDialog constructor/key/OK-handler cluster attached to [UID:0000BG][QuitDialog](by-class/QuitDialog.md); A001 2026-06-16 live IDA refresh reconfirmed function sizes, constructor/key/OK decompilation, direct constructor callers `0x00507068` and `0x005bd202`, launcher inline modal setup distinction, key/OK vtable refs `0x0062f150` and `0x0062f13c`, `g_pBackPane` parent/context use, resolved `0x005adedb-0x005adf20` switch-data/alignment range, and blank final C++ pending alert/dialog helper and global declaration names.
```

## 2026-06-16 Goal 2 Class Low-Confidence IntegrateMacro / Staffs / Startup

Assignment: `A001-goal2-lowconfidence-integratemacro-staffs-startup-20260616-26`.

- Changed target docs: `by-class/IntegrateMacroEditControlPane.md`, `by-class/StaffsDialogPane.md`, and `by-class/StartupWindow.md`.
- Changed support docs/reports: `by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md`, `by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md`, `by-file/StartupWindow.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-item/-coverage-report.md`. Validator refreshed generated project stats/autogen state. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:00006M] `86/84 -> 87/88`; [UID:0000DY] `86/84 -> 87/87`; [UID:0000DZ] `86/84 -> 87/88`; support [UID:0001IN] `82/88 -> 85/90`; support [UID:00019Z] `82/88 -> 85/89`; support [UID:0000O5] `87/85 -> 88/86`; support [UID:0000VI] `85/87 -> 86/88`.
- Owner/emitter decisions: no route changes. IntegrateMacro remains routed through [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md); StaffsDialogPane remains routed through [UID:0000O3][StaffsDialogPane](by-file/StaffsDialogPane.md); StartupWindow remains routed through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). [UID:0001IN] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters/C++; the support thunk run is compiler/linker-generated ABI glue. All other final C++ blocks remain blank.
- Evidence used: local target/support docs; live IDA MCP database `c001_midiplayer_rdata_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; IDA `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_function`, `callees`, and `get_bytes`; and a corrected PE-section-mapped scan for absolute-VA, RVA, and direct `E8`/`E9` hits. A first raw file-offset scan was discarded because file offsets are not VAs in this PE; only section-mapped scan results were documented.
- IntegrateMacro evidence summary: live IDA reconfirmed all `IntegrateMacroEditControlPane` method records, the seven `0x00580640-0x00580686` thunk records, constructor caller `0x00541cc5`, `SetMacroData` caller `0x00542247`, vtable-only `SyncEditControl` at `0x0062d384`, vtable-only thunk refs at `0x0062d388/0x0062d394/0x0062d3c4/0x0062d2f0/0x0062d320/0x0062d24c/0x0062d27c`, current decompilation of `OnKeyEvent`, `SyncEditControl`, and the scalar deleting destructor, and bytes through the thunk run plus padding.
- Staffs evidence summary: live IDA reconfirmed constructor/action/clear-helper/thunk/destructor records, constructor decompilation building `STAFF.EPF`, `NPAL8.PAL`, close button id `14`, and `STAFFS`/`STAFFS2`; action id `1` close behavior; destructor clearing `g_pStaffsDialog`; action/destructor vtable refs; four singleton lifecycle xrefs; and PE-section-mapped zero VA/RVA/direct-branch hits to constructor `0x004ffaa0`.
- Startup evidence summary: live IDA reconfirmed constructor and `RunUpdateCheck` WinMain-only callers, WndProc data refs, callback refs, vtable/singleton refs, constructor/destructor decompilation, modeled helper/callback/string/destructor records, no IDA function objects or direct xrefs for raw starts `0x005815b0`, `0x005817e0`, `0x00581860`, `0x005818d0`, and `0x005819d0`, byte padding around raw/callback/successor boundaries, and PE-section-mapped zero VA/RVA/direct-branch hits to those raw starts.
- Blockers investigated: IntegrateMacro final source-facing helper/member names and class declarations that regenerate thunks remain unresolved, but behavior/ownership no longer block 85/85. Staffs constructor reachability remains a real blocker after live IDA xrefs and PE-mapped pointer/branch scans found no constructor hit; this blocks final C++/source-entry certainty, not current class/file ownership. Startup raw helper source shape remains unresolved after no-function/no-xref/no-PE-hit checks; exact child promotion or source-level inline/alternate setup proof is still needed before final C++.
- IDA DB changes: none. This pass was read-only; no rename, comment, type, function creation, patch, or save was justified. Function creation/comment candidates for Startup raw helpers were skipped because the raw starts still lack direct xrefs and final source-quality boundaries.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all ten changed by-* files. Each pass exited `0` with `ok: 1`. Validator output removed [UID:00006M], [UID:0000DY], [UID:0000DZ], and [UID:0000VI] from `project-level/-auto-completion-stats.md`; post-check `Select-String`/`rg` for those UIDs in the stats file returned no matches.
- Leases used: A001 leased the three target class docs, `by-class/-coverage-report.md`, two support memory docs, `by-file/StartupWindow.md`, `by-file/-coverage-report.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, `by-item/-coverage-report.md`, and this notes file before edits. No `by-memory/-coverage-report.md` lease/edit was attempted.
- Shared-report status: the two `by-memory/-coverage-report.md` replacement rows below are pending supervisor application. They are exact replacement rows; placement contexts are included.

### Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows retained for audit

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 IntegrateMacro/Staffs/Startup supervisor-owned rows remain pending.

Placement context: replace the current [UID:00019Z] row nested under the StaffsDialogPane/login dialog cluster around `0x004ffaa0`:

```text
    - [UID:00019Z][0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore](by-memory/0x004ffaa0-0x004ffd3d.StaffsDialogPaneCore.md) 0x004ffaa0-0x004ffd3d | class-method-cluster | StaffsDialogPaneCore : reconstructable : 85% : very-strong : A001 2026-06-16 live IDA reconfirmed constructor/action sizes, constructor decompilation building the `STAFF.EPF`/`NPAL8.PAL`/`STAFFS`/`STAFFS2` dialog, singleton writes, action id `1` slide/close behavior, action vtable ref, destructor/thunk support refs, four `g_pStaffsDialog` lifecycle xrefs, adjacent padding, and PE-section-mapped zero VA/RVA/direct `E8`/`E9` hits to the constructor; final C++ remains blank pending real constructor reachability/source-placement proof.
```

Placement context: replace the current [UID:0001IN] row nested under [UID:0001IK] `MacroEditControlPanes`, immediately after the integrated macro input/focus hooks and before `IntegrateMacroEditControlPane::ScalarDeletingDestructor`/the following destructor rows:

```text
    - [UID:0001IN][0x00580640-0x00580686.MacroEditControlPaneVtableThunks](by-memory/0x00580640-0x00580686.MacroEditControlPaneVtableThunks.md) 0x00580640-0x00580686 | compiler-thunk | MacroEditControlPaneVtableThunks : ignored : 85% : very-strong : A001 2026-06-16 live IDA reconfirmed seven function records (`0x00580640` 5-byte activate thunk plus six 11-byte adjustor thunks), exact vtable data xrefs at `0x0062d388`, `0x0062d394`, `0x0062d3c4`, `0x0062d2f0`, `0x0062d320`, `0x0062d24c`, and `0x0062d27c`, code refs from integrate adjustor thunks into `0x00580690`, byte sequence through the final thunk plus `0xcc` padding before the destructor, MacroDialogFamilyVtables ownership, compiler/linker-generated rebuild handling, and no hand-written source emission.
```

## 2026-06-16 Goal 2 Class Completion Chatting / Clan

Assignment: `A001-goal2-class-completion-chatting-clan-20260616-27`.

- Changed target docs: `by-class/ChattingBackPane.md`, `by-class/ChattingColorSelectPane.md`, and `by-class/ClanAttrInputDialog.md`.
- Changed support docs/reports: `by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md`, `by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md`, `by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md`, `by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md`, `by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md`, `by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md`, `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`, `by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md`, `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`, `by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md`, and `by-class/-coverage-report.md`.
- Score changes: [UID:00001R] `82/88 -> 86/89`; [UID:00001U] `82/88 -> 86/89`; [UID:000024] `82/88 -> 86/89`; support [UID:0002F3] `82/88 -> 85/89`; [UID:0002G2] `82/88 -> 85/89`; [UID:0002G3] `82/88 -> 85/89`; [UID:0002G4] `82/88 -> 85/89`; [UID:0002G5] `82/90 -> 85/90`; [UID:0002G6] `82/90 -> 85/90`; [UID:00010L] `84/90 -> 85/90`; [UID:00010F] `84/90 -> 85/90`; [UID:00010E] `84/90 -> 85/90`; [UID:0002O5] `84/90 -> 85/90`.
- Owner/emitter decisions: no route changes. `ChattingBackPane` and `ChattingColorSelectPane` remain `CANONICAL_OWNER/EMITTER_UIDS:0000I5` through [UID:0000I5][Chatting](by-file/Chatting.md). `ClanAttrInputDialog` remains `CANONICAL_OWNER/EMITTER_UIDS:0000I8` through [UID:0000I8][Clan](by-file/Clan.md). All changed by-memory support pages keep their existing owners/emitters. Final C++ remains blank in every changed page.
- Evidence used: local target/support docs, live IDA MCP database `c001_midiplayer_rdata_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDA `lookup_funcs`, `xrefs_to`, `callees`, `analyze_function`, `get_bytes`, and a corrected PE-section-mapped scan for absolute-VA, RVA, and direct `E8`/`E9` hits.
- ChattingBackPane evidence summary: live IDA reconfirmed constructor/destructor/update boundaries, `g_pChattingBackPane` lifecycle xrefs, `g_pChattingHandlePane` state reads at `+0x114/+0x118`, alpha writes at `this+0x90`, `PaneSetMode`, draw-color setter, final refresh callback, vtable-only update reachability, and byte padding. The PE scan found only the vtable absolute-VA hit at `0x00614dd4` for the update virtual and no direct branch hit.
- ChattingColorSelectPane evidence summary: live IDA reconfirmed constructor/draw/selection ranges, two raw helper byte islands, vtable slots `0x00615164/0x0061515c`, labels `Talk/Shout/Whisper/Group/Clan/System`, owner pointer `this+0x14c`, owner/list offsets `+0x26c/+0x270/+0x274/+0x2a8`, and raw helper bytes. PE scans found zero VA pointer, zero RVA pointer, and zero direct branch hits to `0x00482ca0`, `0x00482d40`, or `0x00482d50`.
- ClanAttr evidence summary: live IDA reconfirmed constructor/action/validation/input-event ranges, padding, three modeled constructor callers plus two raw derived-constructor calls, vtable-only action/validation/input slots, six packet string decodes, required controls `8/9/10`, submitted-field offsets `+0x26c/+0x46c/+0x66c/+0x86c`, `g_pClanStatusPane` event forwarding, derived submitter [UID:0002O5], and subtype `6`/`10` three-string packet helpers. PE scan matched five direct constructor branches and the sole helper direct branches at `0x00489fe3` and `0x0048a053`.
- Blockers investigated: BackPane final virtual/member names remain unresolved after live vtable and state-field checks; ColorSelect standalone constructor and raw helper source placement remains unresolved after no-xref and no-PE-hit checks; ClanAttr final widget/member/control names and `Clan.cpp` versus `ClanDialogs.cpp` split remain unresolved despite strong binary behavior evidence. These blockers no longer keep the assigned pages below 85/85, but they still block final C++.
- IDA DB changes: none. This pass was read-only; no rename, comment, type, function creation, patch, or save was justified because remaining names/source placement are not conclusive.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all 14 changed by-* files. Each pass exited `0` with `ok: 1`. Post-check `rg -n "00001R|00001U|000024|0002F3|0002G2|0002G3|0002G4|0002G5|0002G6|00010L|00010E|00010F|0002O5" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three target class docs, `by-class/-coverage-report.md`, ten support memory docs, and this notes file before edits. No `by-memory/-coverage-report.md` lease/edit was attempted.
- Shared-report status: the `by-class/-coverage-report.md` rows were edited directly by A001 and validated. The ten `by-memory/-coverage-report.md` replacement rows below are pending supervisor application.

### Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows retained for audit

Supervisor applied and validated these ten replacement rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 Chatting/Clan class-completion supervisor-owned memory rows remain pending.

Placement context: replace the current [UID:0002F3] row nested under [UID:000104] `ChattingUI`, immediately after [UID:000105] `BackPaneViewportRectHelper` and before the `0x004807aa-0x004807b0` padding row:

```text
        - [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) 0x00480740-0x004807aa | virtual method | ChattingBackPaneUpdateVisibility : reconstructable : 85% : strong : A001 2026-06-16 refresh reconfirmed exact ChattingBackPane update virtual bounds, vtable-only data xref at `0x00614dd4`, `g_pChattingHandlePane` state gates at `+0x114/+0x118`, alpha constants `0.7f`/`0.3f`, `this+0x90` alpha write, PaneSetMode mode `2`/`1`, GrafPort draw-color values `0x80`/`0`, SurfaceRenderCallbackTable refresh, byte padding, section-mapped PE no direct branch reachability beyond the vtable slot, ChattingBackPane parent attachment, and blank final C++ pending source-grade field/virtual names.
```

Placement context: replace the current [UID:0002G2] row nested under [UID:000104] `ChattingUI`, immediately after the [UID:0000VN] `0x00482c9f-0x00482ca0` padding row and before the [UID:0000VN] `0x00482d3c-0x00482d40` padding row:

```text
        - [UID:0002G2][0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor](by-memory/0x00482ca0-0x00482d3c.ChattingColorSelectPaneConstructor.md) 0x00482ca0-0x00482d3c | constructor | ChattingColorSelectPaneConstructor : reconstructable : 85% : strong : A001 2026-06-16 refresh reconfirmed exact standalone constructor bounds, no direct xrefs, ListPane args `4/60/60/20/0/1/3`, vtable stores, owner pointer `this+0x14c`, append loop entries `0..5`, inline duplicate construction inside ChattingColorPaneConstructor storing selector at owner `+0x26c`, post-constructor `0xcc` padding, section-mapped PE zero VA/RVA/direct-branch hits to `0x00482ca0`, ChattingColorSelectPane parent attachment, and blank final C++ pending source-placement proof.
```

Placement context: replace the current [UID:0002G3] row nested under [UID:000104] `ChattingUI`, immediately after the [UID:0000VN] `0x00482d3c-0x00482d40` padding row and before the [UID:0000VN] `0x00482d4a-0x00482d50` padding row:

```text
        - [UID:0002G3][0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw](by-memory/0x00482d40-0x00482d4a.ChattingColorSelectPaneRefreshHelperRaw.md) 0x00482d40-0x00482d4a | raw unmodeled helper | ChattingColorSelectPaneRefreshHelperRaw : reconstructable : 85% : strong : A001 2026-06-16 refresh reconfirmed no IDA function object or xrefs at the raw start, exact helper bytes `8b 11 8d 41 44 50 ff 52 20 c3`, surrounding padding, selector receiver rectangle at `+0x44`, virtual slot `+0x20`, section-mapped PE zero VA/RVA/direct-branch hits to `0x00482d40`, class parent routing, and blank final C++ pending source helper name/reachability proof.
```

Placement context: replace the current [UID:0002G4] row nested under [UID:000104] `ChattingUI`, immediately after the [UID:0000VN] `0x00482d4a-0x00482d50` padding row and before the [UID:0000VN] `0x00482d5a-0x00482d60` padding row:

```text
        - [UID:0002G4][0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw](by-memory/0x00482d50-0x00482d5a.ChattingColorSelectPaneSelectionNotifyHelperRaw.md) 0x00482d50-0x00482d5a | raw unmodeled helper | ChattingColorSelectPaneSelectionNotifyHelperRaw : reconstructable : 85% : strong : A001 2026-06-16 refresh reconfirmed no IDA function object or xrefs at the raw start, exact helper bytes `8b 01 6a 00 6a 00 ff 50 78 c3`, surrounding padding, two zero arguments to virtual slot `+0x78`, section-mapped PE zero VA/RVA/direct-branch hits to `0x00482d50`, class parent routing, and blank final C++ pending source helper name/reachability proof.
```

Placement context: replace the current [UID:0002G5] row nested under [UID:000104] `ChattingUI`, immediately after the [UID:0000VN] `0x00482d5a-0x00482d60` padding row and before the [UID:0000VN] `0x00482f4f-0x00482f50` padding row:

```text
        - [UID:0002G5][0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem](by-memory/0x00482d60-0x00482f4f.ChattingColorSelectPaneDrawItem.md) 0x00482d60-0x00482f4f | class method | ChattingColorSelectPaneDrawItem : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact vtable-owned row renderer, vtable data xref `0x00615164`, empty direct callers, category labels `Talk/Shout/Whisper/Group/Clan/System`, selected/unselected palette branches, owner color-byte reads through `*(this+0x14c) + 4*entry + 0x278/+0x290`, full callee set, tail padding, and blank final C++ pending source-grade UI helper/field names.
```

Placement context: replace the current [UID:0002G6] row nested under [UID:000104] `ChattingUI`, immediately after the [UID:0000VN] `0x00482f4f-0x00482f50` padding row and before the [UID:0000VN] `0x00482fa5-0x00482fb0` padding row:

```text
        - [UID:0002G6][0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged](by-memory/0x00482f50-0x00482fa5.ChattingColorSelectPaneOnSelectionChanged.md) 0x00482f50-0x00482fa5 | class method | ChattingColorSelectPaneOnSelectionChanged : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact vtable-only selection handler, vtable slot `0x0061515c`, empty direct callers, base selection call `sub_4F45B0`, two `sub_483210` color-list refresh calls, owner pointer `this+0x14c`, owner child offsets `+0x26c/+0x270/+0x274`, selected value copy from child `+0x134` to owner `+0x2a8`, exact bytes, eleven-byte tail padding, owner-side sync-helper match, and blank final C++ pending field/helper names.
```

Placement context: replace the current [UID:00010E] row in the Clan opcode `0x4b` helper cluster, immediately after [UID:00021K] `ClanSubtype6PacketHelpers` and before [UID:00021L] `ClanNameActionPacketHelpers`:

```text
    - [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md) 0x00485ac0-0x00485cbd | helper function | SendClanAttributePacket : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact helper range, sole caller `0x00489fe3`, opcode `0x4b` subtype `6` action `2`, three one-byte length-prefixed converted strings, final big-endian 16-bit value, packet-buffer/memmove/queue-send dependencies, adjacent helper boundaries, section-mapped PE one direct branch and zero VA/RVA pointer hits, Clan parent attachment, and blank final C++ pending final packet-helper/API/field names.
```

Placement context: replace the current [UID:00010F] row in the Clan opcode `0x4b` helper cluster, immediately after [UID:00021L] `ClanNameActionPacketHelpers` and before [UID:00021M] `ClanWithdrawAndNoticePacketHelpers`:

```text
    - [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) 0x00486330-0x0048652d | helper function | SubmitClanChangeHelper : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact helper range, sole caller `0x0048a053`, opcode `0x4b` subtype `10` action `2`, three one-byte length-prefixed converted strings, final 16-bit value, packet-buffer/memmove/queue-send dependencies, adjacent helper-family boundaries, section-mapped PE one direct branch and zero VA/RVA pointer hits, Clan parent attachment, and blank final C++ pending final packet-helper/API/field names.
```

Placement context: replace the current [UID:00010L] row in the Clan attribute dialog area, immediately after [UID:00010K] `ClanNameDialogSubmitters` and before [UID:00021W] `ClanEnlistInputDialogRawConstructor`:

```text
    - [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md) 0x00489600-0x00489f80 | class core | ClanAttrInputDialogCore : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact constructor/action/validation/input-event ranges, internal padding, three modeled constructor callers plus two raw derived-constructor calls, vtable-only handler slots, six length-prefixed packet string decodes, `DLGCLAN2.EPF` setup, submitted fields at `+0x26c/+0x46c/+0x66c/+0x86c`, controls `8/9/10`, derived confirmation dispatch, `g_pClanStatusPane` input-event forwarding, section-mapped PE five direct constructor branches and zero constructor pointer hits, Clan parent attachment, and blank final C++ pending source-grade member/control names and Clan/ClanDialogs split.
```

Placement context: replace the current [UID:0002O5] row nested under [UID:00010M] `ClanEnlistChangeLeaveSubmitters`, immediately after [UID:0002O4] `ClanChangeInputDialogRawConstructor` and before the [UID:0000VN] `0x0048a059-0x0048a060` padding row:

```text
        - [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md) 0x0048a030-0x0048a059 | function/method | ClanChangeInputDialogSubmitClanChange : reconstructable : 85% : very-strong : A001 2026-06-16 refresh reconfirmed exact vtable-only submitter, vtable slot `0x00615ef4`, no direct callers, sole `SubmitClanChangeHelper` callee, inherited field arguments at `+0x26c/+0x46c/+0x66c/+0x86c`, adjacent alignment, Clan parent attachment, and blank final C++ pending final field/helper names plus raw constructor source-placement cleanup.
```

## 2026-06-16 Goal 2 File/Class Completion Control/Deque/Attached

Assignment: `A001-goal2-file-class-completion-control-deque-attached-20260616-28`.

Assigned targets:
- [UID:00000N] `by-class/AttachedObjectPaneHelper_53AEC0.md`
- [UID:0000IG] `by-file/ControlPane.md`
- [UID:0000IR] `by-file/Deque.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the temporary `by-memory/-coverage-report.md` edit ban.
- Improve documentation, completion, confidence, evidence quality, parent/support pages, and non-banned coverage reports where justified. A target at or above 85/85 is not done if unresolved field/type/global/helper/protocol, ownership, source-placement, range/split, reachability, or final-C++ blockers have not been investigated.
- For every blocker mentioned in the final report, either resolve it, document exactly what evidence was checked and why it cannot currently be resolved safely, or keep/lower the score if it materially limits behavior, ownership, placement, or confidence.
- If [UID:00000N] still requires heavy source-structure inference after normal evidence review, document the checked evidence and recommend B-agent escalation rather than making a weak owner/source claim.
- Do not directly edit `by-memory/-coverage-report.md`. If by-memory support rows need updates, record exact replacement/insert/delete text and placement context here for supervisor application.
- Report changed files, leases used, validations, before/after score changes, owner/emitter decisions, IDA changes if any, blocker investigations, and any exact pending supervisor-owned coverage rows.

Completion checkpoint:
- Changed target docs: `by-class/AttachedObjectPaneHelper_53AEC0.md`, `by-file/ControlPane.md`, and `by-file/Deque.md`.
- Changed support docs/reports: `by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md`, `by-type/by-struct/AttachedObjectRegistryLayout.md`, `by-class/ControlPane.md`, `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`, `by-class/Deque.md`, `by-type/by-struct/DequeLayout.md`, `by-memory/0x00439e00-0x00439ea3.DequeDestroy.md`, `by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md`, `by-memory/0x004a88e0-0x004a8966.DequePushBack.md`, `by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md`, `by-memory/0x0054c160-0x0054c1f1.DequeClear.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md`. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:00000N] `82/88 -> 85/89`; [UID:0000IG] `85/86 -> 86/88` with stale report row `82% -> 86%`; [UID:0000IR] `85/86 -> 86/88`; support [UID:0001DF] `85/89 -> 86/89`; [UID:0001TR] `86/89 -> 87/90`; [UID:000038] `85/86 -> 86/88`; [UID:0003N9] remained `85/86`; [UID:00003P] `86/88 -> 87/89`; [UID:0001U2] `85/88 -> 86/89`; [UID:0000XA] `82/90 -> 85/90`; [UID:0000XB] `82/90 -> 85/90`; [UID:000149] remained `88/92`; [UID:0001FC] `84/88 -> 85/89`; [UID:0001FD] remained `86/90`.
- Owner/emitter decisions: [UID:00000N] remains `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and no emitter because it is a rejected pseudo-class grouping for the detach helper. [UID:0001DF] remains routed through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) for now because the sole modeled call is from `AttachedObjectPane::~AttachedObjectPane`, but final source shape is explicitly handed off. [UID:0001TR] moved owner/emitter from [UID:0000HJ] to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) because the receiver registry fields are initialized and maintained by LivingObjectPane constructor/setup evidence. [UID:0000IG]/[UID:000038]/[UID:0003N9] stay on the ControlPane class/file route. [UID:0000IR]/[UID:00003P]/[UID:0001U2]/Deque method pages now consistently route exact deque behavior through [UID:00003P][Deque](by-class/Deque.md) with file parent [UID:0000IR][Deque](by-file/Deque.md).
- Evidence used: local target/support docs, `by-structure.md`, by-class/by-file/by-memory/by-type guidance, supervisor notes, live IDA MCP database `c001_midiplayer_rdata_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDA `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_component`, `get_int`, `get_bytes`, and `search_text`, plus a section-mapped PE scan for absolute-VA, RVA, and direct `E8`/`E9` hits.
- Attached evidence summary: live IDA reconfirmed `sub_53AEC0` exact `0x152` body, sole destructor call at `0x005382b0` from `sub_538100`, zero callees, `AttachedObjectPane +0x128` registry pointer source, object type byte `+0xf8`, registry offsets `+0x170/+0x174/+0x1d8/+0x1dc/+0x1e0/+0x1e4`, many `g_useEpfAssets` mode-byte uses, PE zero pointer encodings to `0x0053aec0`, and LivingObjectPane constructor/setup writes at `0x0053a257`, `0x0053a27f`, `0x0053a287`, `0x0053a291`, `0x0053a29b`, plus the `sub_53A360` variant and cleanup helpers.
- ControlPane evidence summary: live IDA reconfirmed constructor `0x004949e0`, state helpers `0x00494b80/0x00494bb0/0x00494bd0/0x00494bf0/0x00494c00/0x00494c10/0x00494c30`, destructor/thunk/fixed virtual records, 52 constructor xrefs, vtable cells `0x00617ad8..0x00617af0`, raw helper bytes at `0x00494c50`, no IDA function object for the raw helper, zero raw-helper xrefs, six-byte `0xcc` pre-padding, and section-mapped PE zero VA/RVA/direct-branch hits to `0x00494c50`.
- Deque evidence summary: live IDA reconfirmed function ranges `0x00439e00`, `0x0043e0b0`, `0x004a88e0`, `0x0054c0c0`, `0x0054c160`, and `0x0057b9e0`, broad direct xrefs from event/folder-tree/map/world-map/prime/sound users, the sole internal edge `DequePushBack -> DequeEnsureCapacity`, the raw direct branch to `0x0054c0c0` from `0x0054bce1`, PE zero VA/RVA pointer encodings for `0x0054c0c0`, and the corrected `+0x00/+0x04/+0x08/+0x0c/+0x10` DequeLayout.
- Blockers investigated: [UID:00000N]/[UID:0001DF] still need B-agent source-structure inference because binary evidence supports both the current attached-pane destructor helper route and LivingObjectPane ownership of the underlying registry fields; exact B-agent question recorded in both docs is whether [UID:0001DF] should remain an `AttachedObjectPane.cpp` private helper or reroute as a `LivingObjectPane` registry method. ControlPane final C++ remains blocked by source-grade names for the state fields, fixed virtual, and raw active-frame helper after live vtable/xref/PE scans found no raw-helper reachability. Deque final C++ remains blocked by source-grade class/template/helper names and unresolved `+0x00` field semantics after caller, layout, branch, and PE pointer checks; the raw element-address helper has only the PrimeNumberGenerator raw branch and no pointer encodings.
- IDA DB changes: none. This pass was read-only; no rename, comment, type, function creation, patch, or save was justified because remaining names/source placement are not conclusive enough for database metadata.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all 17 changed by-* files/reports listed above. Each pass exited `0` with `ok: 1`. Post-check `rg -n "00000N|0000IG|0000IR|000038|00003P|0001TR|0001U2|0000XA|0000XB|000149|0001FC|0001FD|0001DF|0003N9" project-level\-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all changed docs/reports plus this notes file before edits/validation. `by-file/-coverage-report.md` was leased and edited directly after the earlier A002 conflict was gone. `by-memory/-coverage-report.md` was not leased or edited.
- Shared-report status: `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-type/by-struct/-coverage-report.md` were updated directly by A001 and validated. Supervisor applied the seven `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 and validated `by-memory/-coverage-report.md` with `ok:1`.

### Supervisor-applied supervisor-owned `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0000XA] row immediately after the padding row `0x00439df9-0x00439e00` and before the padding row `0x00439ea3-0x00439eb0`:

```text
    - [UID:0000XA][0x00439e00-0x00439ea3.DequeDestroy](by-memory/0x00439e00-0x00439ea3.DequeDestroy.md) 0x00439e00-0x00439ea3 | method | DequeDestroy : reconstructable : 85% : very-strong : Deque class-routed cleanup method; A001 2026-06-16 live IDA reconfirmed exact `0xa3` body, EventDispatcher/FolderTreePane/MapPane/WorldMapPane caller spread, count/front drain, block-map block frees, large-allocation guard, auxiliary `+0x00` free, DequeLayout offsets, direct owner/emitter route through [UID:00003P][Deque](by-class/Deque.md), and blank final C++ pending source-grade method names and first-field semantics.
```

Placement context: replace the current [UID:0000XB] row immediately after the padding row `0x0043e0a3-0x0043e0b0` and before the padding row `0x0043e241-0x0043e250`:

```text
    - [UID:0000XB][0x0043e0b0-0x0043e241.DequeEnsureCapacity](by-memory/0x0043e0b0-0x0043e241.DequeEnsureCapacity.md) 0x0043e0b0-0x0043e241 | method | DequeEnsureCapacity : reconstructable : 85% : very-strong : Deque class-routed block-map growth method; A001 2026-06-16 live IDA reconfirmed exact `0x191` boundary, adjacent padding, DequeLayout offsets, block-count doubling, wrapped block-map copy/zero paths, allocation/free guards, overflow/new/free/memmove/memset callees, sixteen direct xrefs across utility consumers, direct owner/emitter route through [UID:00003P][Deque](by-class/Deque.md), and blank final C++ pending source-grade class/template/helper names.
```

Placement context: replace the current [UID:0003N9] row nested under [UID:0002PD] `ControlFamilyStateVirtualHelpers`, immediately after [UID:0003N7] `ControlPaneActivate` and before the following ProgressBar/control boundary rows:

```text
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable : 85% : strong : ControlPane class-routed raw active-frame helper; A001 2026-06-16 recheck reconfirmed no IDA function object, zero xrefs, six-byte `0xcc` pre-padding, exact source-shaped bytes over `this+0x101`, `this+0x102`, `this+0x70`, and `this+0x44`, section-mapped PE zero VA/RVA/direct-branch hits to `0x00494c50`, owner/emitter route through [UID:000038][ControlPane](by-class/ControlPane.md), and blank final C++ because reachability/source representation and field/helper names are not final-source quality.
```

Placement context: replace the current [UID:000149] row immediately after the padding row `0x004a88d2-0x004a88e0` and before the padding row `0x004a8966-0x004a8970`:

```text
    - [UID:000149][0x004a88e0-0x004a8966.DequePushBack](by-memory/0x004a88e0-0x004a8966.DequePushBack.md) 0x004a88e0-0x004a8966 | method | DequePushBack : reconstructable : 88% : very-strong : Deque class-routed append method; A001 2026-06-16 live IDA reconfirmed exact `0x86` body, eight direct xrefs, one internal `PushBack -> EnsureCapacity` edge, append math over `+0x04/+0x08/+0x0c/+0x10`, 16-byte block allocation path, caller spread across EventDispatcher/FolderTreePane/PrimeNumberGenerator/WorldMapPane, direct owner/emitter route through [UID:00003P][Deque](by-class/Deque.md), and blank final C++ pending source-grade container names and `+0x00` semantics.
```

Placement context: replace the current [UID:0001DF] row at `0x0053aec0`, in the AttachedObjectPane/attached-registry helper area:

```text
    - [UID:0001DF][0x0053aec0-0x0053b011.AttachedObjectDetachRegistry](by-memory/0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md) 0x0053aec0-0x0053b011 | helper-method | AttachedObjectDetachRegistry : reconstructable : 86% : strong : AttachedObjectPane destructor-only detach-registry helper with current owner/emitter route through [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md); A001 2026-06-16 live IDA reconfirmed exact `0x152` helper, sole `0x005382b0` destructor caller, zero ordinary callees, `AttachedObjectPane +0x128` registry pointer source, object type byte `+0xf8`, registry list/slot offsets, g_useEpfAssets mode-byte normalization, LivingObjectPane constructor/setup writes for the same receiver fields, PE zero pointer encodings, and blank final C++ pending B-agent source-shape decision between attached-pane helper and LivingObjectPane registry method.
```

Placement context: replace the current [UID:0001FC] row immediately after the padding row `0x0054c0bc-0x0054c0c0` and before the padding row `0x0054c15a-0x0054c160`:

```text
    - [UID:0001FC][0x0054c0c0-0x0054c110.DequeElementAddressHelper](by-memory/0x0054c0c0-0x0054c110.DequeElementAddressHelper.md) 0x0054c0c0-0x0054c110 | helper | DequeElementAddressHelper : reconstructable : 85% : very-strong : Deque class-routed block-map address helper; A001 2026-06-16 live IDA/PE reconfirmed exact `0x50` body, pre-padding, no modeled callees, one raw direct branch at `0x0054bce1` from [UID:0001FA][0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt](by-memory/0x0054bcc0-0x0054bcec.PrimeNumberGeneratorGetPrimeAt.md), zero VA/RVA pointer encodings, `frontIndex`/`blockCount`/`blockMap` address calculation, direct owner/emitter route through [UID:00003P][Deque](by-class/Deque.md), and blank final C++ pending source-grade method names and `+0x00` pointer-chain semantics.
```

Placement context: replace the current [UID:0001FD] row immediately after the padding row `0x0054c15a-0x0054c160` and before the padding row `0x0054c1f1-0x0054c200`:

```text
    - [UID:0001FD][0x0054c160-0x0054c1f1.DequeClear](by-memory/0x0054c160-0x0054c1f1.DequeClear.md) 0x0054c160-0x0054c1f1 | method | DequeClear : reconstructable : 86% : very-strong : Deque class-routed non-owning clear method; A001 2026-06-16 live IDA reconfirmed exact `0x91` body, six PrimeNumberGenerator-neighborhood xrefs, DequeLayout offsets, count/front drain, block/map free path, large-allocation guard, `+0x08/+0x04` clears while `+0x00` remains untouched, direct owner/emitter route through [UID:00003P][Deque](by-class/Deque.md), and blank final C++ pending source-grade method/type names and `+0x00` semantics.
```

## 2026-06-16 Goal 2 File Completion Legend/Merchant/Monitor

Assignment: `A001-goal2-file-completion-legend-merchant-monitor-20260616-31`.

Assigned targets:
- [UID:0000KM] `by-file/LegendPane.md`
- [UID:0000L9] `by-file/MerchantDialogPane.md`
- [UID:0000LI] `by-file/Monitor.md`

Completion checkpoint:
- Changed target docs: `by-file/LegendPane.md`, `by-file/MerchantDialogPane.md`, and `by-file/Monitor.md`.
- Changed support docs/reports: `by-class/LegendPane.md`, `by-class/MerchantDialogPane.md`, `by-class/CriticalSectionLock.md`, `by-memory/0x0056c400-0x0056c493.LegendPane.md`, `by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md`, `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`, `by-memory/0x005285e0-0x00528929.MonitorAndConditions.md`, `by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md`, `by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md`, `by-type/by-vtable/LegendPaneVtables.md`, `by-type/by-vtable/MerchantDialogPaneVtables.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md`. `project-level/-auto-completion-stats.md` and `tools/validator.ini` were regenerated by validator `--apply`. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000KM] `85/86 -> 86/88`; [UID:0000L9] `85/86 -> 86/88`; [UID:0000LI] `85/86 -> 86/88`; support [UID:000074] `85/88 -> 86/89`; [UID:000083] `86/87 -> 87/88`; [UID:00003C] `84/86 -> 85/88`; [UID:0001HB] `82/88 -> 85/89`; [UID:0001BL] `85/87 -> 86/88`; [UID:0001BM] `85/88 -> 86/89`; [UID:0001CL] `82/88 -> 85/89`; [UID:000226] `82/90 -> 85/90`; [UID:00012A] `84/90 -> 85/90`; [UID:00038P] `87/91 -> 88/91`; [UID:00031W] `86/90 -> 87/90`.
- Owner/emitter decisions: LegendPane file remains the file source root; LegendPane class remains owned/emitted by [UID:0000KM]; [UID:0001HB] and [UID:00038P] now route through direct class [UID:000074] because that class clears the current gate. MerchantDialogPane file remains the source root; MerchantDialogPane class remains owned/emitted by [UID:0000L9]; [UID:0001BL], [UID:0001BM], and [UID:00031W] now route through direct class [UID:000083]. Monitor file remains owner/emitter for mixed Monitor/MonitorCondition/RequestSyncGate and low-level critical-section wrapper support; CriticalSectionLock class remains owned/emitted by [UID:0000LI], while [UID:00012A] routes through direct class [UID:00003C].
- Evidence used: local target/support docs, `by-structure.md`, by-file/by-class/by-memory/by-type guidance, proposed source tree, supervisor notes, live IDA MCP database `c001_midiplayer_rdata_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, IDA `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, `get_bytes`, and section-mapped PE scans for absolute-VA, RVA, and direct `E8`/`E9` hits.
- LegendPane evidence summary: live IDA/PE reconfirmed constructor `sub_56C400` size `0x93`, false-return stubs at `0x0056c4a0` and `0x0056c4b0`, successor `GroupPane` at `0x0056c4c0`, three direct constructor branches from self-look/self-look2/user-look callers, vtable-store refs to all three LegendPane views, no pointer hits to `0x0056c400`, PE direct branches exactly matching the three constructor xrefs, and false-stub reachability only through vtable pointer slots.
- MerchantDialogPane evidence summary: live IDA/PE reconfirmed raw constructor start `0x00517d30` is not an IDA function, has zero IDA xrefs, and has zero VA/RVA/direct-branch PE hits; shared virtual `0x00517d80` is `sub_517D80` size `0x13f`, has eight vtable-only refs and no direct branches; constructor bytes store the three owner-specific vtable views; action-string decompilation still shows slash-prefix and `0...` packet-helper branches.
- Monitor evidence summary: live IDA/PE reconfirmed Monitor/RequestSyncGate/MonitorCondition inventory, raw non-deleting destructor byte islands at `0x005286d0` and `0x005287f0` as non-function/no-xref/no-pointer-hit starts, vtable refs at `0x0061fbe8` and `0x0061fbf0`, Monitor constructor refs at `0x0055642c` and `0x0059632d`, MonitorCondition constructor refs at `0x00556456` and `0x00556480`, nine paired RequestSyncGate lock/unlock caller refs, and critical-section wrapper/RAII-lock companion evidence.
- Critical-section evidence summary: live IDA/PE reconfirmed `0x0049bcb0` modeled initialize wrapper, raw delete wrapper at `0x0049bcc0` reached only by static cleanup branch `0x0060c0e5`, raw enter/leave wrappers at `0x0049bcd0`/`0x0049bce0` with no xrefs or PE branch hits, `CriticalSectionLock` constructor `sub_49BCF0` size `0x19`, destructor `sub_49BD10` size `0x9`, and two constructor/destructor caller pairs in application message-loop/request-exit code.
- Blockers investigated: LegendPane final C++ remains blank after caller/xref/PE checks because source-grade helper/base names and standalone-versus-merged look-pane source shape remain unresolved. MerchantDialogPane final C++ remains blank after raw-start/xref/PE checks because the raw constructor has no direct reachability and source-grade packet helper names/virtual signature/source split remain unresolved. Monitor final C++ remains blank after raw destructor and critical-section support checks because Monitor/MonitorCondition/RequestSyncGate declarations, field names, helper names, and CriticalSectionLock original placement are not final-source quality. These blockers do not prevent the refreshed 85/85+ documentation gate, but they do cap confidence below final-source audit.
- IDA DB changes: none. This pass was read-only; no rename, comment, function creation, type change, patch, or save was justified because remaining issues are source-placement/helper-name questions, not local disassembly ambiguity.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for each changed by-* document/report listed above. All 17 validator runs exited `0`; the first target run showed `ok: 1`, `completion_update`, `confidence_update`, stats row removal, registry rebuild, and projected stats update, and subsequent runs completed without errors. Post-check `Select-String -Path .\project-level\-auto-completion-stats.md -Pattern '0000KM|0000L9|0000LI|000074|000083|00003C|0001HB|0001BL|0001BM|0001CL|000226|00012A|00038P|00031W'` returned no matches. `git diff --check` over edited docs/reports and `project-level/-auto-completion-stats.md` passed with only CRLF normalization warnings; full check including regenerated `tools/validator.ini` reports generated trailing-whitespace entries in blank registry values.
- Leases used: A001 leased all changed docs/reports plus this notes file before edits/validation. Leases expired during validation; A001 re-leased this notes file before recording this checkpoint. `by-memory/-coverage-report.md` was not leased or edited.
- Shared-report status: `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-type/by-vtable/-coverage-report.md` were updated directly by A001 and validated. Supervisor applied the `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 and validated the shared report with `ok: 1`; rows are retained for audit.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows

Placement context: replace the current [UID:0001HB] row for `0x0056c400-0x0056c493.LegendPane`, before [UID:00023W] and near the LegendPane/LookPane memory area:

```text
    - [UID:0001HB][0x0056c400-0x0056c493.LegendPane](by-memory/0x0056c400-0x0056c493.LegendPane.md) 0x0056c400-0x0056c493 | constructor | LegendPane : reconstructable : 85% : very-strong : LegendPane constructor now routed through direct class [UID:000074][LegendPane](by-class/LegendPane.md); A001 2026-06-16 live IDA/PE reconfirmed exact `0x93` body, three direct constructor branches from self-look/self-look2/user-look callers, `sub_4B60B0`/`sub_58DCE0` callees, `g_useEpfAssets` geometry branch, three vtable stores, `this+0x104 = 63`, adjacent false-stub/GroupPane boundaries, no VA/RVA pointer encodings, and blank final C++ pending source-grade helper/base names plus the standalone-versus-merged look-pane source split.
```

Placement context: replace the current [UID:0001BL] row at `0x00517d30-0x00517ebf`, immediately before nested child [UID:0001BM]:

```text
    - [UID:0001BL][0x00517d30-0x00517ebf.MerchantDialogPaneBase](by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md) 0x00517d30-0x00517ebf | class aggregate | MerchantDialogPaneBase : reconstructable : 86% : very-strong : MerchantDialogPane raw constructor plus shared action-string virtual now routed through direct class [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md); A001 2026-06-16 live IDA/PE reconfirmed raw constructor no-function/no-xref status, zero VA/RVA/direct-branch hits to `0x00517d30`, three constructor vtable-store refs, modeled `0x00517d80` size `0x13f`, eight shared-virtual vtable refs, `0x00517ec0` successor boundary, section-mapped PE pointer hits only at those eight vtable slots for the shared virtual, and blank final C++ pending raw constructor/source-split and helper/signature names.
```

Placement context: replace the nested [UID:0001BM] row immediately under [UID:0001BL]:

```text
      - [UID:0001BM][0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual](by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md) 0x00517d80-0x00517ebf | virtual method | MerchantDialogPaneActionStringVirtual : reconstructable : 86% : very-strong : Vtable-only shared virtual now routed through direct class [UID:000083][MerchantDialogPane](by-class/MerchantDialogPane.md); A001 2026-06-16 live IDA/PE reconfirmed `0x13f` modeled size, eight merchant/text/item/spell/argumented-menu vtable refs, zero direct branches, slash-prefix and `0...` action-string branches, packet parser/encoder callees, 10-byte queue/send path through `dword_67A7EC`, and blank final C++ pending source-grade packet helper names and virtual signature.
```

Placement context: replace the current [UID:0001CL] row at `0x005285e0-0x00528929`, after MiscWorkThread and before MonsterImageLibTables:

```text
    - [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) 0x005285e0-0x00528929 | helper island | MonitorAndConditions : reconstructable : 85% : very-strong : Monitor.cpp synchronization cluster; A001 2026-06-16 live IDA/PE reconfirmed exact Monitor/RequestSyncGate/MonitorCondition helper inventory, raw non-deleting destructor byte islands at `0x005286d0` and `0x005287f0`, zero xrefs and zero VA/RVA/direct-branch PE hits to those raw starts, vtable refs at `0x0061fbe8`/`0x0061fbf0`, nine paired RequestSyncGate lock/unlock caller refs, Win32 mutex/semaphore behavior, caller/callee sets, padding, direct owner/emitter route through [UID:0000LI][Monitor](by-file/Monitor.md), and blank final C++ pending source-grade field/helper/API names and raw destructor declaration shape.
```

Placement context: replace the current [UID:000226] row immediately after checksum helpers and before padding `0x0049bce8-0x0049bcf0`:

```text
    - [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) 0x0049bcb0-0x0049bce8 | helper family | CriticalSectionApiWrappers : reconstructable : 85% : very-strong : Monitor.cpp critical-section wrapper helper family; A001 2026-06-16 live IDA/PE reconfirmed `0x0049bcb0` modeled init wrapper, raw delete/enter/leave wrappers at `0x0049bcc0`, `0x0049bcd0`, and `0x0049bce0`, direct static-cleanup branch to delete wrapper at `0x0060c0e5`, zero PE VA/RVA pointer hits, zero direct branches to the enter/leave wrappers, exact bytes/padding, direct owner/emitter route through [UID:0000LI][Monitor](by-file/Monitor.md), and blank final C++ pending source-grade helper names and final Monitor-vs-platform placement.
```

Placement context: replace the current [UID:00012A] row immediately after padding row `0x0049bce8-0x0049bcf0` and before the DATFileMgr forwarder:

```text
    - [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md) 0x0049bcf0-0x0049bd19 | class method pair | CriticalSectionLock : reconstructable : 85% : very-strong : CriticalSectionLock RAII constructor/destructor pair routed through direct class [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md); A001 2026-06-16 live IDA reconfirmed constructor `0x19` and destructor `0x9` sizes, `EnterCriticalSection`/`LeaveCriticalSection` behavior, constructor refs `0x00464db7` and `0x00465666`, destructor refs `0x00464dc5` and `0x00465677`, adjacent wrapper/padding boundaries, direct class/file support, and blank final C++ pending header-only versus Monitor.cpp/platform helper placement.
```

## 2026-06-16 Goal 2 File Completion MiniMap/NewUser2/PrettyButton

Assignment: `A001-goal2-file-completion-minimap-newuser2-prettybutton-20260616-33`.

Assigned targets:
- [UID:0000LE] `by-file/MiniMap.md`
- [UID:0000LW] `by-file/NewUserDialogPane2.md`
- [UID:0000MP] `by-file/PrettyButtonControlPane.md`

Completion checkpoint:
- Changed target docs: `by-file/MiniMap.md`, `by-file/NewUserDialogPane2.md`, and `by-file/PrettyButtonControlPane.md`.
- Changed support docs/reports: `by-class/NewUserDialogPane2.md`, `by-class/PrettyButtonControlPane.md`, `by-class/PrettyButtonControlPane2.md`, `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`, `by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md`, `by-file/-coverage-report.md`, and `by-class/-coverage-report.md`. `project-level/-auto-completion-stats.md` and `tools/validator.ini` were regenerated by validator `--apply`. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000LE] `85/86 -> 86/88`; [UID:0000LW] `85/86 -> 86/88`; [UID:0000MP] `85/86 -> 86/88`; support [UID:00009E] `85/86 -> 86/88`; [UID:0000AR] `85/86 -> 86/88`; [UID:0000AS] `85/86 -> 86/88`; [UID:0000XO] `85/86 -> 86/88`; [UID:0001F9] `82/86 -> 85/88`; [UID:0002SH] `80/88 -> 85/89`.
- Owner/emitter decisions: MiniMap file remains `CANONICAL_OWNER:FILE`; [UID:0000XO] remains owner/emitter [UID:0000LE][MiniMap](by-file/MiniMap.md) after raw helper and renderer/control evidence refresh. NewUserDialogPane2 file remains `CANONICAL_OWNER:FILE`; class [UID:00009E] remains owner/emitter [UID:0000LW], and exact vtable child [UID:0002SH] was rerouted from umbrella [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) to direct class [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md). PrettyButtonControlPane file remains `CANONICAL_OWNER:FILE`; classes [UID:0000AR]/[UID:0000AS] and executable cluster [UID:0001F9] remain owner/emitter [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md).
- Evidence used: local target/support docs, `by-structure.md`, `by-file/-guidance.md`, proposed source tree snippets, supervisor notes, active IDA MCP database `b001_attached_object_0001DF_20260616` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, IDA `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_function`, `get_bytes`, `disasm`, and section-mapped PE scans for absolute-VA, RVA, and direct branch hits.
- MiniMap evidence summary: live IDA/PE reconfirmed `MiniMapDialog` constructor `0x00450ca0`, raw/generated starts `0x004517a0`, `0x00452ce0`, and `0x00454e30` as no-function/no-xref/no-pointer/no-branch starts, two direct constructor branches to `0x00450ca0`, eight `g_pMiniMapDialog` refs, MiniMap UI vtable refs, renderer/parser helper starts, `0x004543f0` `.mnm` parser/file-loader/image-decode/vector-helper callees, and raw `0x00454e30-0x00455040` WinINet/S3/`.mnm` download semantics.
- NewUserDialogPane2 evidence summary: live IDA/PE reconfirmed constructor-like `0x0052a540`, command/submit/packet helpers through `0x0052c325`, successor `0x0052c360`, two direct constructor branches at `0x004f7ad0` and `0x004f9041`, submit/packet decompilation over three edit fields, password validation, length-prefixed packet encoding and queue-send dependencies, vtable refs at `0x0061fd04`/`0x0061fd64`, no refs to `0x0061fd84`, singleton refs through `0x0069b4a4`, and PE pointer stores for `0x0061fd04`.
- PrettyButton evidence summary: live IDA/PE reconfirmed method starts from `0x0054b5e0` through `0x0054bc40`, 30 direct branches to `0x0054b5e0`, two direct branches to `0x0054b8c0`, zero constructor pointer encodings, `0x0054bcbd-0x0054bcc0` padding before PrimeNumberGenerator, vtable-store refs for all six three-view vtable bases, and constructor/paint decompilation over frame ids, resource strings, state bytes, and callback/object pointers.
- Blockers investigated: MiniMap final C++ remains blank after raw-start/xref/PE/disassembly checks because the compact `MiniMap.cpp` versus split `MiniMapDialog.cpp`/`MiniMapRenderer.cpp`/`MiniMapDownloader.cpp` shape, exact raw helper name, `.mnm`/hash-list format, and vector/string helper ownership remain unresolved. NewUserDialogPane2 final C++ remains blank after constructor/vtable/submit/packet/singleton checks because Wave3 still misnames the constructor row and source-grade field/helper names plus standalone-versus-umbrella create-user source placement remain unresolved. PrettyButton final C++ remains blank after constructor/vtable/PE/decompilation checks because source-grade field/resource/callback names and final declaration shape remain unresolved; current caller evidence is clustered in create-user constructors, so generic controls placement is supported by class role/base dependency/proposed tree rather than broad caller spread alone.
- IDA DB changes: none. This pass was read-only; no rename, comment, function creation, type change, patch, or save was justified because remaining issues are source-grade naming/source-placement questions or raw no-xref helper starts.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all 11 changed by-* docs/reports listed above. All validator runs exited `0`; the first run showed `ok: 1`, completion/confidence updates, stats row removal, registry rebuild, and projected stats update, and the final loop printed `ALL_VALIDATIONS_OK`. Post-check `Select-String -Path .\project-level\-auto-completion-stats.md -Pattern '0000LE|0000LW|0000MP|00009E|0000AR|0000AS|0000XO|0001F9|0002SH'` returned no matches. `git diff --check` over edited docs/reports passed with only CRLF normalization warnings.
- Leases used: A001 leased target/support docs and this notes file before edits. Initial leases for `by-file/-coverage-report.md` and `by-class/-coverage-report.md` were blocked by A002; A001 retried after expiry, successfully leased both shared reports, updated them directly, and validated them. Some original target/support leases expired during validation; reports and notes were re-leased as needed. `by-memory/-coverage-report.md` was not leased or edited.
- Shared-report status: `by-file/-coverage-report.md` and `by-class/-coverage-report.md` were updated directly by A001 and validated. Supervisor applied and validated the exact `by-memory/-coverage-report.md` replacement rows below on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 pending `by-memory/-coverage-report.md` rows remain for this batch.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Placement context: replace the current [UID:0000XO] row immediately after padding row `0x00453def-0x00453df0` and before padding row `0x004563b5-0x004563c0`:

```text
    - [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) 0x00453df0-0x004563b5 | class aggregate | MiniMapRendererAndControls : reconstructable : 86% : very-strong : MiniMap renderer/image-control/symbol-control aggregate attached to [UID:0000LE][MiniMap](by-file/MiniMap.md); A001 2026-06-16 live IDA/PE reconfirmed modeled image-control, renderer, support-helper, and symbol-control starts including `0x00453df0`, `0x00453f50`, `0x00454150`, `0x004543f0`, `0x00454d80`, `0x00455050`, `0x00455060`, `0x004550d0`, and `0x004563b0`, raw WinINet/minimap helper start `0x00454e30` as no-function/no-xref/no-pointer-or-branch-hit code, `.mnm`/S3/user-agent disassembly, renderer parser callee set, MiniMap UI vtable refs, aggregate ownership, and blank final C++ pending field names, record layouts, helper splits, and compact-vs-split source placement.
```

Placement context: replace the current [UID:0001F9] row immediately after padding row `0x0054b5d5-0x0054b5e0` and before padding row `0x0054bcbd-0x0054bcc0`:

```text
    - [UID:0001F9][0x0054b5e0-0x0054bcbd.PrettyButtonControls](by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md) 0x0054b5e0-0x0054bcbd | class-cluster | PrettyButtonControls : reconstructable : 85% : very-strong : PrettyButtonControlPane.cpp two-class styled-button executable cluster; A001 2026-06-16 live IDA/PE reconfirmed modeled method inventory for both classes, exact destructor/thunk endpoint and padding before PrimeNumberGenerator, 30 direct constructor branches to `0x0054b5e0`, two direct branches to `0x0054b8c0`, zero constructor pointer encodings, vtable store refs for both three-view vtable children, constructor/paint decompilation over frame ids, resource strings, callback/object pointers, and state bytes, and blank final C++ pending source-grade field/resource/callback names and final class/source declaration shape.
```

Placement context: replace the nested [UID:0002SH] row immediately under [UID:00025Z][0x0061fd04-0x00620284.CreateUserRegistrationReadOnlyData], after the parent aggregate row and before [UID:0002SJ] `NewCreateUserDialogPaneVtableData`:

```text
        - [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) 0x0061fd04-0x0061fd94 | vtable-data | NewUserDialogPane2VtableData : reconstructable : 85% : very-strong : Exact NewUserDialogPane2 vtable range now routed through direct class [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md); A001 2026-06-16 live IDA/PE reconfirmed constructor/submit/packet/reply function inventory, constructor callers `0x004f7ad0` and `0x004f9041`, vtable refs at `0x0052a5b2`, `0x0052b059`, `0x0052f8ec`, secondary-view refs at `0x0052a5b8`, `0x0052b05f`, `0x0052f8f2`, no refs to `0x0061fd84`, singleton refs through `0x0069b4a4`, PE vtable pointer hits only at the three text stores for `0x0061fd04`, successor `0x0061fda0` boundary, and blank final C++ pending field/helper names plus standalone-versus-umbrella create-user source split.
```

## 2026-06-16 Assignment - A001-goal2-item-completion-dat-palette-20260616-36

Assigned targets:

- [UID:0000UT] `by-item/HasDATEntry_0049C700.md`
- [UID:0000UW] `by-item/LoadDatFileBuffer_004BB120.md`
- [UID:0000V4] `by-item/PaletteSlotTable.md`

Instructions:

- Read and follow `Agent-A001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from `project-level/-auto-completion-stats.md`. Raise each target where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of merely repeating it. Resolve final signature/name/source-placement/C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why they remain unsafe.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## A001 Report - A001-goal2-item-completion-packet-path-20260616-40

Completion checkpoint:

- Changed target docs: `by-item/PacketDigest_00515380.md`, `by-item/PacketTransformHelpers.md`, and `by-item/PathExistsViaStat_00582460.md`.
- Changed support docs/reports: `by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md`, `by-memory/0x00575b90-0x00575caa.PacketTransformStringKeyHelpers.md`, `by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md`, `by-memory/0x00578e00-0x00578e94.XorTransformBuffer.md`, `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`, and `by-item/-coverage-report.md`. Validator `--apply` also refreshed `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, and `tools/validator.ini`. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000V2] `85/88 -> 86/89`; [UID:0000V3] `85/88 -> 87/89`; [UID:0000V6] `85/88 -> 87/89`; support [UID:0001I4] `84/87 -> 86/89`; [UID:000244] `82/90 -> 86/90`; [UID:0001I3] `82/86 -> 85/88`; [UID:0001I5] `82/88 -> 86/89`; [UID:0001IZ] `86/88 -> 87/89`.
- Owner/emitter decisions: [UID:0000V2] remains owner/emitter [UID:0000L6][MD5](by-file/MD5.md); Socket is the sole caller and PacketTransform is a dependency neighbor, not the hash owner. [UID:0000V3], [UID:000244], and [UID:0001I5] remain owner/emitter [UID:0000M9][PacketTransform](by-file/PacketTransform.md); Socket owns sequencing callers only. [UID:0001I3] and [UID:0001I4] remain owner/emitter [UID:0000NS][Socket](by-file/Socket.md). [UID:0000V6] and [UID:0001IZ] remain owner/emitter [UID:0000MI][PathUtil](by-file/PathUtil.md), with WideApiDispatchTable/PlatformApi owning the `_wstat64i32` dispatch slot, not the helper.
- Evidence used: IDA MCP active database `b001_selflookpane_0001H7_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_batch`, `analyze_function`, `disasm`, `get_bytes`, `insn_query`, existing target/support docs, `by-structure.md`, `by-item/-guidance.md`, supervisor notes, and read-only PE scans for rel32 calls/jumps plus VA/RVA pointer references.
- PacketDigest evidence summary: live IDA reconfirmed `sub_515380` at `0x00515380-0x005153dc`, one basic block, sole caller at `0x00578da5`, MD5 constants/callees `0x00515690` and `0x00515750`, stack-return `lea eax, [ebp+var_18]`, and adjacent `sub_5153E0` at `0x005153e0`. PE scan matched only the one direct call and found zero VA/RVA pointer hits to `0x00515380`; raw sibling starts `0x00515310` and `0x00515450` also had zero direct call/branch/pointer hits.
- PacketTransform evidence summary: live IDA confirmed current names/sizes for `PacketTransform_ExpandProcessArgKeyText` (`0x00575c30`, `0x7a`), `InitializePacketNonce` (`0x00575cb0`, `0xd3`), `BuildHandshakeBlock` (`0x00577030`, `0x10d`), and `XorTransformBuffer` (`0x00578e00`, `0x94`). `insn_query` decoded the raw `0x00575b90-0x00575c30` helper body ending in `retn 4`; `xrefs_to` and PE scan both found no direct reachability to raw `0x00575b90`, one call to `0x00575c30`, two calls to `0x00575cb0`, two calls to `0x00577030`, six calls to `0x00578e00`, eight calls to inbound Socket transform `0x00578b20`, and three calls to outbound builder `0x00578c40`.
- Path evidence summary: live IDA reconfirmed `sub_582460` at `0x00582460-0x00582495`, no function at the end byte, 48-byte stack stat buffer, indirect `unk_69BE18` call, `cmp eax, 0xffffffff`/`setnz al`, exact six caller sites, and stack-cookie callee. PE scan matched the same six direct calls and found zero VA/RVA pointer hits.
- Blockers investigated: final C++ remains blank for PacketDigest because the binary returns a pointer to stack digest storage and the docs cannot safely choose between preserving that source idiom and using the neighboring caller-buffer digest wrapper. PacketTransform final C++ remains blank because raw `0x00575b90` liveness remains negative in IDA and PE scans, helper/global source-facing names are not final, generated prototypes disagree, and original separate `PacketTransform.cpp` versus private `Socket.cpp` placement remains unresolved. Socket transform/builder final C++ remains blank because Socket field/buffer names, helper prototypes, and digest source representation remain source-quality blockers. PathExists final C++ remains blank because platform dispatch typedef/name and `PathUtil.cpp` versus compact `FileIO.cpp` placement remain inferred.
- IDA DB changes: none. This pass was read-only; no IDA renames, comments, function creation, type edits, patching, or save were made. Existing C001 PacketTransform helper names were observed and documented.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all changed by-* docs/reports listed above. The loop exited `0`; each validator invocation printed `ok: 1`. The first pass also normalized one UID link in `PacketDigest_00515380.md`. Post-validation `rg` for `0000V2|0000V3|0000V6|0001I4|000244|0001I3|0001I5|0001IZ` in `project-level/-auto-completion-stats.md` returned no matches, so the changed rows left the low-score list.
- Leases used: A001 leased the three by-item targets, `by-item/-coverage-report.md`, the five by-memory support docs listed above, and this notes file. A001 did not lease or edit `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Supervisor applied and validated the [UID:000244], [UID:0001I3], [UID:0001I4], [UID:0001I5], and [UID:0001IZ] replacement rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No A001 pending `by-memory/-coverage-report.md` rows remain for `A001-goal2-item-completion-packet-path-20260616-40`.

Completion checkpoint:

- Changed target docs: `by-item/DrawFrameWithBlendMode_00462E10.md`, `by-item/DrawTextRunCallback_00593DB0.md`, and `by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md`.
- Changed support docs/reports: `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`, `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`, `by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md`, `by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md`, `by-file/EmployeeDialogPane.md`, and `by-item/-coverage-report.md`. Validator `--apply` regenerated `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated outputs. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000UI] `85/88 -> 86/89`; [UID:0000UK] `85/88 -> 86/89`; [UID:0000UL] `85/88 -> 86/89`; support [UID:0000YN] `82/86 -> 86/89`; [UID:0001JR] `85/88 -> 86/89`; [UID:0003L0] `85/87 -> 86/88`; [UID:0003L2] `85/87 -> 86/88`. `by-file/EmployeeDialogPane.md` support text was refreshed with no score change.
- Owner/emitter decisions: `DrawFrameWithBlendMode` item and exact memory page remain owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md); LightObjImageLib pages are callers/consumers and byte-span row helpers remain adjacent render support. `DrawTextRunCallback` item and exact memory page remain owner/emitter [UID:0000ON][TextEditPane](by-file/TextEditPane.md); the callback is file-local/address-taken rather than a member method. `EmployeeDialogPacketAndRecordHelpers` remains owner/emitter [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md); modeled employee methods keep class/file child routes, while raw packet and record-mutation islands stay file-owned because no callable entry references were recovered.
- Evidence used: current target/support docs, `by-structure.md`, `by-item/-guidance.md`, supervisor notes, active IDA MCP database `b001_selflookpane_0001H7_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`, IDA `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_batch`, `get_bytes`, and a read-only section-mapped PE scan for absolute VA pointers, RVA pointers, and rel32 calls/jumps.
- DrawFrame evidence summary: live IDA reconfirmed `sub_462E10` size `0x10e`, two LightObjImageLib callers at `0x004dfc42` and `0x004dfcf2`, clip helper `0x004b7cc0`, row-helper callees `0x00460df0`/`0x00460e80`/`0x00460f10`, mode constants `0/1/2`, and alignment before/after the exact range. PE scan found zero VA/RVA pointer hits for `0x00462e10`, only the two rel32 callers, and only one rel32 call to each row helper from the mode dispatch.
- DrawText evidence summary: live IDA reconfirmed `sub_593DB0` size `0x146`, cdecl callback-shaped prototype, two data/address-taking xrefs at `0x005908e6` and raw/no-function `0x0059168c`, no function at `0x00593ef6` or `0x00593f00`, successor `sub_594040`, GrafPort/geometry/style/text-renderer callee set, three-byte pre-padding, ten-byte post-padding, and raw-neighbor prologue at `0x00593f00`. PE scan found exactly two absolute-VA immediate references at `0x005908e7` and `0x0059168d`, no RVA pointer hits, no rel32 calls to the callback, and no pointer/branch hits for raw neighbor `0x00593f00`.
- Employee evidence summary: live IDA reconfirmed modeled helper sizes for `0x004a2450`, `0x004a2f60`, `0x004a34d0`, `0x004a3a90`, and `0x004a3e10`; vtable/data xref to dispatcher `0x00618f70`; parser xrefs `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; full-load xrefs `0x004a1ff4` and `0x004a2fe0`; update-fields xref `0x004a313e`; no IDA functions or xrefs at raw starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, `0x004a3a30`, `0x004a3be0`, or `0x004a3ca0`. PE scan found no VA/RVA pointer hits or rel32 branches to those raw starts; byte reads confirmed raw prologues/alignment and modeled successors.
- Blockers investigated: DrawFrame final C++ remains blank after caller/xref/PE/byte checks because exact source-facing frame/rectangle/alpha-mask view type names and unsupported-mode source spelling remain unresolved. DrawText final C++ remains blank after callback xref/raw-neighbor/PE/byte checks because callback state layout, style payload type, and exact source signature are not source-quality. Employee final C++ remains blank after modeled-helper/raw-start/xref/PE/byte checks because raw helper callable boundaries and source-facing helper names remain unresolved; current evidence supports file-owned raw islands, not promotion to class methods or standalone final C++ bodies.
- IDA DB changes: none. This pass was read-only; no IDA rename, comment, function creation, type edit, patch, or save was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all nine changed by-* docs/reports listed above. Every validator run exited `0`; the first run showed `ok: 1`, completion/confidence updates, stats row removal, registry rebuild, and projected stats update. After a final wording cleanup, reran the same validator command for `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`; it exited `0` with `ok: 1` and `stats_incremental_noop`.
- Leases used: A001 successfully leased all edited target/support docs, `by-item/-coverage-report.md`, and this notes file before editing. A001 did not lease or edit `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 pending `by-memory/-coverage-report.md` rows remain for this batch.

Placement context: replace the current [UID:0000YN] row immediately after padding row `0x00462e03-0x00462e10` and before padding row `0x00462f1e-0x00462f20`:

```text
    - [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md) 0x00462e10-0x00462f1e | free helper | DrawFrameWithBlendMode : reconstructable : 86% : strong : AlphaMaskSurface frame blend helper; A001 2026-06-16 live IDA/PE reconfirmed `sub_462E10` size `0x10e`, two LightObjImageLib rel32 callers at `0x004dfc42` and `0x004dfcf2`, zero VA/RVA pointer hits, clip/intersect callee `0x004b7cc0`, mode dispatch to byte copy/add/subtract row helpers at `0x00462f03`/`0x00462eef`/`0x00462edb`, row-helper-only rel32 reachability, alignment-bounded endpoint, owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), and blank final C++ pending source-facing frame/rectangle/view type names and unsupported-mode spelling.
```

Placement context: replace the current [UID:0003L0] row nested under [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes], immediately after [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord] and before [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData]:

```text
        - [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) 0x004a3650-0x004a3a90 | raw-helper-island | EmployeeDialogRawPacketHelpers : reconstructable : 86% : strong : Raw employee packet helper island; direct parent [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), A001 2026-06-16 live IDA/PE reconfirmed record-field parser plus opcode `0x54` command writer bodies for command kinds `0..5`, no function objects or direct xrefs at raw starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, and `0x004a3a30`, zero VA/RVA pointer hits or rel32 branches to those starts, raw prologue/alignment bytes, and blank final C++ pending callable-boundary and source-facing helper-name proof.
```

Placement context: replace the current [UID:0003L2] row nested under [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes], immediately after [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData] and before [UID:0003L3][0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields]:

```text
        - [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) 0x004a3be0-0x004a3e10 | raw-helper-island | EmployeeDialogRawRecordMutationHelpers : reconstructable : 86% : strong : Corrected raw record mutation island; direct parent [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), A001 2026-06-16 live IDA/PE reconfirmed no function objects or direct xrefs at `0x004a3be0` and `0x004a3ca0`, zero VA/RVA pointer hits or rel32 branches to either raw start, upsert body calling `DeserializeEmployeeRecord` at raw `0x004a3c05`, removal body at `0x004a3ca0`, repaint/list rebuild behavior, raw prologues, `retn 4` tail, alignment before `0x004a3e10`, and blank final C++ pending callable-boundary and source-facing helper-name proof.
```

Placement context: replace the current [UID:0001JR] row immediately after padding row `0x00593dad-0x00593db0` and before padding row `0x00593ef6-0x00593f00`:

```text
    - [UID:0001JR][0x00593db0-0x00593ef5.DrawTextRunCallback](by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md) 0x00593db0-0x00593ef5 | callback | DrawTextRunCallback : reconstructable : 86% : strong : TextEditPane file-local draw callback assigned to [UID:0000ON][TextEditPane](by-file/TextEditPane.md); A001 2026-06-16 live IDA/PE reconfirmed `sub_593DB0` size `0x146`, prototype-shaped cdecl callback, two data/address-taking xrefs at `0x005908e6` and raw/no-function `0x0059168c`, exactly two absolute-VA immediate references at `0x005908e7` and `0x0059168d`, no RVA pointer hits or rel32 calls, GrafPort/geometry/style/text-render callee set, three-byte pre-padding, ten-byte post-padding, raw neighbor `0x00593f00` with no pointer/branch reachability, and blank final C++ pending callback-state layout and source-facing signature proof.
```

Completion checkpoint:

- Changed target docs: `by-item/HasDATEntry_0049C700.md`, `by-item/LoadDatFileBuffer_004BB120.md`, and `by-item/PaletteSlotTable.md`.
- Changed support docs/reports: `by-global/HasDATEntry_49C700.md`, `by-global/LoadDatFileBuffer_4BB120.md`, `by-memory/0x0049c700-0x0049c71d.HasDATEntry.md`, `by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md`, `by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md`, `by-class/PaletteLib.md`, `by-item/-coverage-report.md`, and `by-global/-coverage-report.md`. Validator `--apply` regenerated `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated outputs. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000UT] `84/90 -> 86/91`; [UID:0000UW] `84/90 -> 86/91`; [UID:0000V4] `84/90 -> 86/91`; support [UID:0000T0] `84/90 -> 86/91`; [UID:0000T4] `84/90 -> 86/91`; [UID:00012E] `84/90 -> 86/91`; [UID:00016G] `84/90 -> 86/91`; [UID:000262] `82/88 -> 85/90`. [UID:0000A1] `PaletteLib` content refreshed with no score change.
- Owner/emitter decisions: `HasDATEntry` item/global/memory remain direct owner/emitter [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md); rendering, palette, sound, and UI callers are consumers. `LoadDatFileBuffer` item/global/memory remain direct owner/emitter [UID:0000IN][DATFile](by-file/DATFile.md); UI/resource callers are consumers. `PaletteSlotTable` remains owner/emitter [UID:0000MA][Palette](by-file/Palette.md), with [UID:0000A1][PaletteLib](by-class/PaletteLib.md) as the direct class behavior support and [UID:000262][PaletteReadOnlyData](by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) as exact read-only data support.
- Evidence used: IDA MCP active database `b001_maildialogs_0000ZO_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `xrefs_to`, existing target/support docs, `by-structure.md`, `by-item/-guidance.md`, supervisor notes, and read-only section-mapped PE scans for VA pointers, RVA pointers, rel32 calls/jumps, and UTF-16LE `.rdata` strings.
- HasDATEntry evidence summary: live IDA reconfirmed `sub_49C700` size `0x1d`, next function `sub_49C720`, sole callee `sub_49CAD0`, singleton read at `0x0049c703`, decompiled `_DATFileMgr` lookup wrapper, 17 direct callers, and 24 total `g_pDATFileMgr` refs. PE scan matched all 17 rel32 calls and found zero VA/RVA pointer hits and zero jumps to the helper start.
- LoadDatFileBuffer evidence summary: live IDA reconfirmed `sub_4BB120` size `0xb2`, next function `sub_4BB1E0`, DATFile constructor/open/get-size/read/close/destructor and allocation/memset callees, `payloadSize + prefixSize` out-size behavior, ten direct callers, and broad consumer contexts. PE scan matched all ten rel32 calls and found zero VA/RVA pointer hits and zero jumps to the helper start.
- Palette evidence summary: live IDA reconfirmed `PaletteLib::PaletteLib` at `0x00543700-0x00543ae2` with one constructor caller, `LoadPaletteSet` at `0x00544210-0x0054439f` with exactly 25 constructor calls, source/runtime list writes at `this[slot + 420]` and `this[slot + 445]`, `HasDATEntry` super-palette probing, and exact `.rdata` UTF-16LE strings from `baram.pal` through `BACK.PAL`. PE scan matched one constructor call, 25 loader calls, VA-form refs for vtables/string starts, and no RVA refs.
- Blockers investigated: final C++ remains blank for `HasDATEntry` because the exact source-facing free-helper/API name and published signature are not proven beyond the documentation alias and Hex-Rays prototype. Final C++ remains blank for `LoadDatFileBuffer` because allocator wrapper/source name, returned-buffer ownership convention, and exact `prefixSize`/`outSize` typedefs are not source-grade. Final C++ remains blank for `PaletteSlotTable`/`PaletteReadOnlyData` because the slot enum/table variable names and compact `Palette.cpp` versus narrower `PaletteLib.cpp` split remain unresolved despite exact slot/file evidence.
- IDA DB changes: none. This pass was read-only; no IDA renames, comments, function creation, type edits, patching, or save were justified.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for all changed by-* docs/reports listed above. The loop exited `0` and printed `ALL_VALIDATIONS_OK`. First validator run showed `ok: 1`, completion/confidence updates for [UID:0000UT], stats row removal, projected stats update, and registry rebuild. Post-validation `Select-String` for `0000UT|0000UW|0000V4|0000T0|0000T4|00012E|00016G|000262|0000A1` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased the three by-item targets, two by-global pages, three by-memory support pages, `by-class/PaletteLib.md`, `by-item/-coverage-report.md`, `by-global/-coverage-report.md` after C001 lease expiry, and this notes file. A001 did not lease or edit `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

Supervisor applied and validated these rows on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 pending `by-memory/-coverage-report.md` rows remain for this batch.

Placement context: replace the current [UID:00012E] row at `0x0049c700-0x0049c71d`, immediately after [UID:00012D][0x0049c130-0x0049d2cc.DATFile] and before [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor]:

```text
    - [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) 0x0049c700-0x0049c71d | function | HasDATEntry : reconstructable : 86% : very-strong : Exact DATFileMgr public entry-existence helper; A001 2026-06-16 live IDA/PE reconfirmed `sub_49C700` size `0x1d`, `0xcc` padding before `sub_49C720`, singleton read at `0x0049c703`, sole `_DATFileMgr` lookup callee `sub_49CAD0`, decompiled boolean wrapper behavior, 17 direct rel32 callers, zero VA/RVA pointer hits or direct jumps to the helper start, direct owner/emitter route through [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), and blank final C++ pending source-facing helper name/signature proof.
```

Placement context: replace the current [UID:00016G] row at `0x004bb120-0x004bb1d2`, immediately after [UID:00016F][0x004bb070-0x004bb078.ConstantLineCountHelper] and before [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers]:

```text
    - [UID:00016G][0x004bb120-0x004bb1d2.LoadDatFileBuffer](by-memory/0x004bb120-0x004bb1d2.LoadDatFileBuffer.md) 0x004bb120-0x004bb1d2 | function | LoadDatFileBuffer : reconstructable : 86% : very-strong : DAT-backed buffer loader; A001 2026-06-16 live IDA/PE reconfirmed `sub_4BB120` size `0xb2`, padding before `sub_4BB1E0`, DATFile constructor/open/get-size/read/close/destructor lifecycle, allocator/prefix/outSize behavior, ten direct rel32 callers, zero VA/RVA pointer hits or direct jumps to the helper start, direct owner/emitter route through [UID:0000IN][DATFile](by-file/DATFile.md), and blank final C++ pending allocator wrapper/source name plus exact signature typedefs.
```

Placement context: replace the current [UID:000262] row at `0x0062179c-0x006219e8`, immediately after [UID:000261][0x00620c74-0x0062179c.OptionMacroProfileReadOnlyData] and before [UID:000263][0x006219e8-0x00621db8.PaneParcelReadOnlyData]:

```text
    - [UID:000262][0x0062179c-0x006219e8.PaletteReadOnlyData](by-memory/0x0062179c-0x006219e8.PaletteReadOnlyData.md) 0x0062179c-0x006219e8 | vtable/string-data | PaletteReadOnlyData : reconstructable : 85% : very-strong : DLPalette/PaletteLib vtables and exact wide palette filename literals attached to [UID:0000MA][Palette](by-file/Palette.md); A001 2026-06-16 live IDA/PE reconfirmed `DLPalette` vtable refs at `0x0062179c`, `PaletteLib` vtable refs at `0x006217ac`, `baram.pal` refs at `0x006217c4`, all 25 UTF-16LE slot filenames from `TILE.PAL` through `BACK.PAL`, constructor/loader linkage through `PaletteLib::PaletteLib` and `LoadPaletteSet`, source/runtime slot-list behavior, VA-form data refs with no RVA-form refs, successor `Pane` vtable boundary at `0x006219e8`, and blank final C++ pending enum/table spelling plus compact-vs-split Palette source placement.
```
## 2026-06-16 Assignment - A001-goal2-item-completion-alpha-text-employee-20260616-38

Assigned targets:
- [UID:0000UI] `by-item/DrawFrameWithBlendMode_00462E10.md`
- [UID:0000UK] `by-item/DrawTextRunCallback_00593DB0.md`
- [UID:0000UL] `by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- These are known-owner routine item pages. If any target becomes heavy source-structure inference or broad original-layout guessing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.
## 2026-06-16 Assignment - A001-goal2-item-completion-packet-path-20260616-40

Assigned targets:
- [UID:0000V2] `by-item/PacketDigest_00515380.md`
- [UID:0000V3] `by-item/PacketTransformHelpers.md`
- [UID:0000V6] `by-item/PathExistsViaStat_00582460.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current supervisor notes, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- These are known-owner item pages. If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous shared-owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - A001-goal2-item-completion-resource-scale-screenshot-20260616-41

Assigned targets:
- [UID:0000VB] `by-item/ResourceLayoutEntry.md`
- [UID:0000VC] `by-item/ScaleDirectionOffsetToPixels_00505100.md`
- [UID:0000VF] `by-item/ScreenshotProofPacket_00558240.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven by-item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- If any assigned target cannot be brought to or kept at `85/85+`, do additional research before returning; if it still cannot clear the gate, report the evidence and why the score must stay lower.
- These are known-owner item pages: [UID:0000VB] routes to [UID:0000K2][ImageLib](../../../by-file/ImageLib.md), [UID:0000VC] routes to [UID:0000L3][MapPane](../../../by-file/MapPane.md), and [UID:0000VF] routes to [UID:0000ND][ScreenshotCapture](../../../by-file/ScreenshotCapture.md). If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous shared-owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-item-completion-resource-scale-screenshot-20260616-41

- Changed target docs: `by-item/ResourceLayoutEntry.md`, `by-item/ScaleDirectionOffsetToPixels_00505100.md`, and `by-item/ScreenshotProofPacket_00558240.md`.
- Changed support docs/reports: `by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md` and `by-item/-coverage-report.md`. Validator `--apply` regenerated `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated outputs. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000VB] `84/90 -> 86/90`; [UID:0000VC] `84/90 -> 86/90`; [UID:0000VF] `84/90 -> 86/90`; support [UID:0001AQ] `84/90 -> 86/90`.
- Owner/emitter decisions: `ResourceLayoutEntry` remains owner/emitter [UID:0000K2][ImageLib](by-file/ImageLib.md) through the class/facet ResourceLayoutTable route; the row owner is [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md), while `ResourceLayoutBucket` is a non-emitting alias. `ScaleDirectionOffsetToPixels` remains owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md); callers are coordinate/movement consumers and do not prove a separate helper file. `ScreenshotProofPacket` remains owner/emitter [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md); MD5, PacketBuffer, CashShopRequest/queue-send, and Socket packet-sender state are dependencies, not owner routes.
- Evidence used: IDA MCP active database `b001_selflookpane_0001H7_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `server_health`, `lookup_funcs`, `analyze_function`, `analyze_component`, existing target/support docs, `project-level/-resolved.md`, `by-structure.md`, `by-item/-guidance.md`, current supervisor notes, and current lease report.
- ResourceLayout evidence summary: live IDA reconfirmed `sub_4D0120` size `0x1c5`, `sub_4D02F0` size `0xae`, `sub_4D03A0` size `0x130`, `sub_4D04D0` size `0x52`, `sub_4D0530` size `0x6b`, and `sub_4D05A0` size `0x46`. Decompilation reconfirmed `24 * (entryCount + 1)` row allocation, raw top/left/bottom/right plus two offset reads, absolute offset rebasing, sentinel row, lookup output mapping, raw record rectangle helper stride/copy behavior, and class/facet versus raw `__stdcall` helper split.
- Scale helper evidence summary: live IDA reconfirmed `sub_505100` as a one-basic-block `__stdcall` body, size `36` / `0x24`, no callees, seven direct callers (`sub_468520`, `sub_538600`, `sub_5386C0`, `sub_539B20`, `sub_53C700`, `sub_53C810`, and `sub_5A88D0`), `word_66DA9C` read/store to `pair[1]`, `word_66DAA0` read/store to `pair[0]`, and `retn 4`.
- Screenshot proof evidence summary: live IDA reconfirmed `sub_558240` size `0x151`, `0x00557840` still not a modeled function start, modeled callers from BMP/PNG, raw JPG xref at `0x00557a78`, MD5 stream helper call `0x00515570`, opcode `0x83` packet writer `0x00575380`, 13 masked digest bytes, 16 random pad bytes, 19 masked bytes, zero terminator, `0x00574bb0(dword_67A7EC, packet, 49)`, and digest free.
- Blockers investigated: ResourceLayout final C++ remains blank after IDA/support-page review because exact source declaration spelling, field names, and ImageLib-versus-ResourceLayoutTable placement policy are not final-source quality. Scale final C++ remains blank because original helper spelling, source-level pair type/order, and broader coordinate-helper split remain unresolved. Screenshot proof final C++ remains blank because helper spelling, local packet-buffer type, return type, class/free-helper shape, and raw JPG source placement remain unresolved.
- IDA DB changes: none. This pass was read-only; no IDA rename, comment, function creation, type edit, patch, or save was justified.
- Validation: ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` from `source-3/project-documentation` for `by-item/ResourceLayoutEntry.md`, `by-item/ScaleDirectionOffsetToPixels_00505100.md`, `by-item/ScreenshotProofPacket_00558240.md`, `by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md`, and `by-item/-coverage-report.md`. The full validation loop exited `0`; a concise rerun for the same files also exited `0` with `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1` for each file.
- Leases used: A001 leased all five changed by-* docs/reports and this notes file before editing. A001 did not lease or edit `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

Supervisor applied and validated the [UID:0001AQ] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 pending `by-memory/-coverage-report.md` rows remain for `A001-goal2-item-completion-resource-scale-screenshot-20260616-41`.

Placement context: replace the current [UID:0001AQ] row nested in the MapPane section, immediately after [UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect] and before [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper]:

```text
    - [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md) : reconstructable : 86% : strong : Small MapPane coordinate helper; A001 2026-06-16 live IDA reconfirmed exact span, one-basic-block `__stdcall` body, seven direct callers, no callees, in-place pair scaling through MapPane-owned tile width/height globals, post-return padding, owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md), and blank final C++ pending helper spelling, pair type/order, and source-split proof.
```

## 2026-06-16 Assignment - A001-goal2-file-item-completion-session-argumented-alpha-20260616-43

Assigned targets:
- [UID:0000NP] `by-file/Session.md`
- [UID:0000TY] `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`
- [UID:0000UH] `by-item/DrawEncodedAlphaFrame_00462F20.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven file/item completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not defer source-quality blockers to final C++ without investigating them during this evidence pass. The 85/85 gate is a minimum, not a stopping point.
- [UID:0000NP] is a reviewed `NONE` placeholder; do not promote it unless a distinct generic session source owner is proven. [UID:0000TY] and [UID:0000UH] are known-owner item pages. If any target becomes heavy source-structure inference, broad original-layout guessing, or ambiguous shared-owner routing, document the checked evidence and recommend B-agent escalation rather than forcing a route.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-file-item-completion-session-argumented-alpha-20260616-43

- Changed target docs: `by-file/Session.md`, `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`, and `by-item/DrawEncodedAlphaFrame_00462F20.md`.
- Changed support docs/reports: `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`, `by-file/-coverage-report.md`, and `by-item/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen coverage state. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0000NP] `85/86 -> 86/88`; [UID:0000TY] `85/89 -> 86/90`; [UID:0000UH] `85/89 -> 86/90`; support [UID:0000YO] `85/89 -> 86/90`.
- Owner/emitter decisions: `Session.md` remains `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`; no generic game-session owner was proven. `ArgumentedItemPurchaseHelpers` remains owner/emitter [UID:0000HH][ArgumentedItemInputDialogs](../../../by-file/ArgumentedItemInputDialogs.md); final C++ remains blank because the first two helper starts still have real reachability/name blockers. `DrawEncodedAlphaFrame` and exact support [UID:0000YO] remain owner/emitter [UID:0000HF][AlphaMaskSurface](../../../by-file/AlphaMaskSurface.md); final C++ remains blank because encoded-frame payload type names and three raw caller boundaries are not source-quality.
- Evidence used: IDA MCP active database `b001_selflookpane_0001H7_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `server_health`, `entity_query`, `find_regex`/string cache via entity query, `lookup_funcs`, `xrefs_to`, `analyze_component`, `analyze_function`, `get_bytes`, existing target/support docs, `by-project-structure/proposed-source-tree.md`, `by-meta/client_network.md`, `by-structure.md`, `by-file/-guidance.md`, `by-item/-guidance.md`, current supervisor notes, current lease report, and a section-mapped PE scanner for VA pointers, RVA pointers, and rel32 calls/jumps.
- Session evidence summary: live IDA found zero function names matching `Session`; matching globals are the existing `DialogSession`, `DialogInSession`, and `BulletinSession` vtable/RTTI objects plus `aWaitforsession`. The only `WaitForSession` xref is `0x004902bb` inside the large command-line/COM helper at `0x0048fca0`, not a game-session owner. IDA reconfirmed the UI/social session anchors at `0x004a0d80`, `0x004a1400`, `0x00471150`, `0x0047ea90`, and `0x005a50a0`, and the separate network transport/send anchors at `0x005747e0`, `0x00575e60`, `0x00574bb0`, `0x00576660`, and `0x00596960`.
- Argumented helper evidence summary: live IDA reconfirmed `sub_51F450` size `0xae`, `sub_51F510` size `0x95`, `SendArgumentedItemQuantityPacket` size `0xc6`, current named quantity/confirm constructor/action methods, zero xrefs to `0x0051f450` and `0x0051f510`, four refs to `0x0051f640`, quantity/confirm constructor refs, and handler vtable refs. PE scanning found zero VA/RVA pointer hits and zero rel32 calls/jumps to `0x0051f450` or `0x0051f510`, and exactly the four expected rel32 refs to `0x0051f640`.
- DrawEncodedAlphaFrame evidence summary: live IDA reconfirmed `sub_462F20` size `0x332`, prototype-shaped `__thiscall(int *this, int *, _DWORD *, _DWORD *, int, unsigned __int8, int, unsigned __int8, int)`, nine xrefs, six modeled image-library callers, three raw no-containing-function callsites, callees `sub_4B7CC0`, `_memset`, and security-cookie check, signed-run row decoding, vertical alpha ramp, alpha-surface pixel/stride use, and mode-specific replace/add/subtract loops. PE scanning found no VA/RVA pointer hits and exactly the nine documented rel32 callsites; byte reads reconfirmed `0xcc`-bounded function start/tail and raw caller neighborhoods.
- Blockers investigated: Session promotion remains blocked by lack of any distinct generic game-session source owner; the reviewed `NONE` placeholder is still correct. Argumented final C++ remains blank because `0x0051f450` and `0x0051f510` have no direct IDA refs, no PE pointer/rel32 refs, and still carry provisional helper names despite strong behavior. DrawEncoded final C++ remains blank because the encoded-frame payload/source type and three raw image-library caller function boundaries are not safely resolvable from current IDA/PE/docs evidence.
- IDA DB changes: none. This pass was read-only; no IDA rename, comment, function creation, type edit, patch, or save was justified. I skipped renaming `sub_51F450`, `sub_51F510`, and `sub_462F20` because their source-facing helper names remain provisional and/or reachability is still unresolved.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` for `by-file/Session.md`, `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`, `by-item/DrawEncodedAlphaFrame_00462F20.md`, `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`, `by-file/-coverage-report.md`, and `by-item/-coverage-report.md`. The full loop exited `0`; concise reruns for all six files exited `0` and printed `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`. The first full pass also printed completion/confidence updates and stats-row removals for the changed target/support UIDs. Post-validation `Select-String` for `0000NP|0000TY|0000UH|0000YO` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all six changed by-* docs/reports and this notes file before editing. A001 did not lease or edit `by-memory/-coverage-report.md`.

Supervisor-applied `by-memory/-coverage-report.md` replacement row:

Supervisor applied and validated the [UID:0000YO] replacement row on 2026-06-16 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A001 pending `by-memory/-coverage-report.md` rows remain for `A001-goal2-file-item-completion-session-argumented-alpha-20260616-43`.

Placement context: replace the current [UID:0000YO] row in the AlphaMaskSurface section, immediately after [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode] and before [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface]:

```text
    - [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) 0x00462f20-0x00463252 | render helper function | DrawEncodedAlphaFrame : reconstructable : 86% : strong : Shared AlphaMaskSurface encoded-frame blitter; A001 2026-06-16 live IDA/PE reconfirmed `sub_462F20` size `0x332`, prototype-shaped alpha-surface helper arguments, no VA/RVA pointer refs, exactly nine rel32 callsites, six modeled image-library callers, three raw no-function callsites, compact callee set, signed-run row decoding from `a3[9]`, alpha-surface pixel/stride writes, vertical alpha-ramp math, replace/add/subtract modes, `0xcc`-bounded function range, owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), and blank final C++ pending encoded-frame type names plus raw caller boundary recovery.
```

## 2026-06-16 Assignment - A001-goal2-type-layout-completion-alpha-dialog-gameserver-20260616-45

Assigned targets:
- [UID:0001TP] `by-type/by-struct/AlphaMaskSurfaceLayout.md`
- [UID:0001U4] `by-type/by-struct/DialogPaneLayout.md`
- [UID:0001UP] `by-type/by-struct/GameServerNationEntry.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/layout completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- [UID:0001U4] `DialogPaneLayout` has a direct parent-gate issue: [UID:00003T][DialogPane](../../../by-class/DialogPane.md) remains below `85/85`. Attempt to improve the direct parent or report exactly why it cannot be raised safely; do not treat child score alone as completion.
- If any target or required direct parent cannot be brought to or kept at `85/85+`, do additional research before returning. If it still cannot clear the gate, report the evidence and why the score must stay lower.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply. Non-memory coverage reports may be edited directly only under normal lease rules.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and any exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-type-layout-completion-alpha-dialog-gameserver-20260616-45

- Changed target docs: `by-type/by-struct/AlphaMaskSurfaceLayout.md`, `by-type/by-struct/DialogPaneLayout.md`, and `by-type/by-struct/GameServerNationEntry.md`.
- Changed support docs/reports: direct parent `by-class/AlphaMaskSurface.md`, `by-type/by-struct/-coverage-report.md`, and `by-class/-coverage-report.md`. Validator `--apply` refreshed project-level/autogen state as needed. No direct edit was made to `by-memory/-coverage-report.md`.
- Score changes: [UID:0001TP] `AlphaMaskSurfaceLayout` `84/88 -> 86/90`; [UID:0001U4] `DialogPaneLayout` `84/88 -> 86/90`; [UID:0001UP] `GameServerNationEntry` `84/88 -> 86/90`; support parent [UID:00000C] `AlphaMaskSurface` `84/89 -> 85/90`.
- Owner/emitter decisions: [UID:0001TP] remains owner/emitter [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md). [UID:0001U4] remains owner/emitter [UID:00003T][DialogPane](by-class/DialogPane.md); the assignment's parent-gate concern was rechecked and current [UID:00003T] is already `85/86` with file parent [UID:0000IT] at `86/85`. [UID:0001UP] remains owner/emitter [UID:00005O][GameServerConfig](by-class/GameServerConfig.md). [UID:00000C] remains owner/emitter [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md).
- Evidence used: IDA MCP active database `b001_selflookpane_0001H7_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, `lookup_funcs`, `xrefs_to`, `analyze_function`, existing target/support docs, current supervisor notes, current lease report, `tools/int_convert.py`, and a section-mapped PE scanner for VA/RVA pointer and rel32 call/jump references.
- Alpha layout evidence summary: live IDA reconfirmed `0x00462170` size `0xb7`, `0x00462260` size `0x22`, `0x00462300` size `0x17`, `0x00462320` size `0x95`, `0x004623c0` size `0x154`, `0x00462e10` size `0x10e`, `0x00462f20` size `0x332`, and `0x00463270` size `0x41`; raw `0x00462120` remains not a function with zero IDA refs. Constructor/view decompilation reconfirmed vtable, bounds, pixels, width/height/stride, and ownership byte at `+0x24`. PE scanning found no VA/RVA/rel32 refs to raw `0x00462120` or no-xref `0x004623c0`.
- Dialog layout evidence summary: live IDA reconfirmed constructor/destructor/control/repaint starts, constructor field writes, 84 direct constructor xrefs, 10 direct repaint-helper xrefs, vtable stores for `0x00618a64`, `0x00618ac4`, and `0x00618af4`, plus raw helper status for `0x0049dd70` and `0x0049de70`. PE scanning found no refs to raw `0x0049dd70`, but found nine rel32 jump refs to raw `0x0049de70`, so focused-control activation is reachable while source-boundary naming remains provisional.
- GameServerNationEntry evidence summary: live IDA reconfirmed raw/no-function status for `0x005039f0`, `0x00503a50`, and `0x00503b60`; modeled lookup/copy `0x00503a80` size `0xd8`, request `0x00503c70` size `0x93`, parser `0x00503d10` size `0x167`, resize `0x00514ee0` size `0x8b`; two copy-helper callers; one resize caller; and 18 xrefs to `g_gameServerNationTable`. Decompilation reconfirmed `0x44`/68-byte records, `0x21`/33-wide-character labels, full-record copy, parser writes, and resize first-word sentinel initialization. PE scanning found no refs to raw constructor/destructor/seeder starts.
- Blockers investigated: Alpha final C++/source declaration remains blocked by the `AlphaMaskSurface` versus `IntAlphaSurface` split and no-ref raw default/view-initializer starts. Dialog final C++ remains blocked by source-facing field names after `+0x208` and raw/control-helper names, not by parent eligibility. GameServer final C++ remains blocked by final record declaration spelling, packet field names, and raw constructor/destructor/seeder source placement. All assigned targets and the required Alpha parent now clear `85/85+`; no B-agent escalation is needed for this batch.
- IDA DB changes: none. This pass was read-only; no rename, comment, function creation, type edit, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <changed by-* doc/report> --apply --queue-timeout 240` for all six changed by-* docs/reports. Each command exited `0`. Post-validation `rg` for `0001TP|0001U4|0001UP|00000C` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all six changed by-* docs/reports and this notes file before editing. A001 did not lease or edit `by-memory/-coverage-report.md`.

Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. This batch did not change any by-memory docs or memory coverage rows.

## 2026-06-16 Assignment - A001-goal2-class-completion-protectedarray-acc-body-20260616-50

Assigned targets:
- [UID:0000AX] `by-class/ProtectedArray_struct_Acc1Info_.md`
- [UID:0000AY] `by-class/ProtectedArray_struct_Acc2Info_.md`
- [UID:0000AZ] `by-class/ProtectedArray_struct_BodyInfo_.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven class/template-instantiation completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Refresh exact destructor/accessor/vtable evidence, ProtectedArray template handling, HumanImageLib embedding evidence, owner/emitter decisions, final template/declaration/source-placement blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - A001-goal2-type-layout-completion-maptile-memory-protected-20260616-47

Assigned targets:
- [UID:0001V2] `by-type/by-struct/MapTileImageLibLayout.md`
- [UID:0001V4] `by-type/by-struct/MemoryManLayout.md`
- [UID:0001VM] `by-type/by-struct/ProtectedArrayLayout.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven type/layout completion pass from refreshed `project-level/-auto-completion-stats.md`. Raise each target and directly supporting page where evidence supports it, including support docs and coverage rows, without inflating scores beyond the evidence.
- Investigate every listed blocker instead of repeating it. Resolve field/type/global/helper-name, caller/reachability, ownership, source-placement, split/merge/range, and final-C++ blockers where supported; otherwise record the exact IDA/docs/metadata evidence checked and why the issue remains unsafe.
- If any target becomes heavy original-source structure inference rather than evidence-backed layout refresh, document the checked evidence and recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-type-layout-completion-maptile-memory-protected-20260616-47

- Changed target docs: `by-type/by-struct/MapTileImageLibLayout.md`, `by-type/by-struct/MemoryManLayout.md`, and `by-type/by-struct/ProtectedArrayLayout.md`.
- Changed support/report docs: `by-type/by-struct/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0001V2] `MapTileImageLibLayout` `84/88 -> 86/90`; [UID:0001V4] `MemoryManLayout` `84/88 -> 86/90`; [UID:0001VM] `ProtectedArrayLayout` `84/89 -> 86/90`.
- Owner/emitter decisions: unchanged. [UID:0001V2] remains owner/emitter [UID:00007T][MapTileImageLib](../../../by-class/MapTileImageLib.md), [UID:0001V4] remains owner/emitter [UID:00007U][MemoryMan](../../../by-class/MemoryMan.md), and [UID:0001VM] remains owner/emitter [UID:0000MU][ProtectedArray](../../../by-file/ProtectedArray.md). Support parents already cleared the strict gate, so no support page score edits were needed.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; IDA `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, and `search_structs`; local `tools/int_convert.py`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 call/jump references.
- MapTile evidence summary: live IDA/PE reconfirmed constructor `0x004d1860` size `0x13e`, destructor `0x004d19a0`, draw `0x004d1a20` size `0x152`, metadata helper `0x004d1b80`, singleton-clear helper `0x004e5bc0`, scalar deleting destructor `0x004e66a0`, one constructor caller, four draw callers, one metadata-helper caller, vtable refs at `0x0061b664`, singleton refs at `0x0067a75c`, constructor writes metadata at `+0x04` and `4 * tileCount` records at `+0x08`, draw reads the same fields, and destructor frees both fields.
- MemoryMan evidence summary: live IDA/PE reconfirmed the 4-byte one-vptr object, constructor `0x00516000` writing `MemoryMan::vftable` and `g_pMemoryMan`, atexit reset thunk `0x0060c260` writing static storage `0x0069b3a8` and clearing `0x0069b4fc`, scalar deleting destructor `0x00516260`, exactly three vtable refs to `0x0061eb08`, two static-storage refs, four singleton refs, and 612 rel32 calls to `GetMemoryMan` rather than object fields.
- ProtectedArray evidence summary: live IDA/PE reconfirmed accessor boundaries at `0x004e5f20`, `0x004e5f40`, and `0x004e5f70`, count at `+0x04`, entries at `+0x08`, fallback/default entry at `+0x10`, strides `0x10`, `0x14`, and `0x0c`, image-info scalar deleting destructors through vtable refs, NationEntry deleting destructor vtable ref at `0x0061e704`, resize helper `0x00514ee0` size `0x8b` with sole parser caller, and no VA/RVA/rel32 refs to raw GameServerConfig constructor/destructor/default-seeder starts `0x005039f0`, `0x00503a50`, or `0x00503b60`.
- Blockers investigated: IDA `search_structs` returned no local struct/type records for `MapTileImageLib`, `MemoryMan`, `ProtectedArray`, or `NationEntry`, so final source member spelling and template/header declarations remain unresolved. MapTile final C++ remains blank pending member/helper/DAT wrapper names. MemoryMan final C++ remains blank pending original source-only declarations and global operator/copy-helper placement. ProtectedArray final C++ remains blank pending the template declaration/header basename, final `+0x0c` member name, and the 12-byte old-human record name. These are real final-source blockers but do not limit the documented binary layouts below `86/90`.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-type/by-struct/MapTileImageLibLayout.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-type/by-struct/MemoryManLayout.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-type/by-struct/ProtectedArrayLayout.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-type/by-struct/-coverage-report.md --apply --queue-timeout 240`; all exited `0` with `ok: 1`. The three target validators reported completion/confidence updates and stats-row removals for `0001V2`, `0001V4`, and `0001VM`.
- Leases used: A001 leased all four changed by-* docs/reports and this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-class-completion-protectedarray-coat-effect-pixmap-20260616-53` as complete. Scores cleared the gate at [UID:0000B0] `86/90`, [UID:0000B1] `86/90`, and [UID:0000B2] `86/90`; owner/emitter routes remain through [UID:0000MU] `ProtectedArray`; no IDA DB or supervisor-owned `by-memory/-coverage-report.md` changes were required. Supervisor revalidated the three target pages and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`).

## 2026-06-16 Assignment - A001-goal2-class-completion-protectedarray-helmet-item-light-20260616-55

Assigned targets:
- [UID:0000B7] `by-class/ProtectedArray_struct_HelmetInfo_.md`
- [UID:0000B8] `by-class/ProtectedArray_struct_ItemInfo_.md`
- [UID:0000B9] `by-class/ProtectedArray_struct_LightInfo_.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven class/template-instantiation completion pass from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows the same coherent ProtectedArray instantiation pattern at `82/88`, known [UID:0000MU] `ProtectedArray` owner/emitter, and concrete embedder evidence through HumanImageLib, ItemObjImageLib, or LightObjImageLib.
- Refresh exact destructor/vtable evidence, ProtectedArray template handling, concrete image-library embedding evidence, owner/emitter decisions, final template/declaration/source-placement blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata/PE/Wave2 evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 Assignment - A001-goal2-class-completion-protectedarray-coat-effect-pixmap-20260616-53

Assigned targets:
- [UID:0000B0] `by-class/ProtectedArray_struct_CoatInfo_.md`
- [UID:0000B1] `by-class/ProtectedArray_struct_EffectInfo_.md`
- [UID:0000B2] `by-class/ProtectedArray_struct_EffectPixMapInfo_.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven class/template-instantiation completion pass from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows the same coherent ProtectedArray instantiation pattern at `82/88`, known [UID:0000MU] `ProtectedArray` owner/emitter, and concrete embedder evidence through HumanImageLib or EffectObjImageLib.
- Refresh exact destructor/vtable evidence, ProtectedArray template handling, concrete image-library embedding evidence, owner/emitter decisions, final template/declaration/source-placement blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata/PE/Wave2 evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-class-completion-protectedarray-face-hair-head-20260616-51

- Changed target docs: `by-class/ProtectedArray_struct_FaceInfo_.md`, `by-class/ProtectedArray_struct_HairInfo_.md`, and `by-class/ProtectedArray_struct_HeadInfo_.md`.
- Changed support/report docs: `by-class/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000B3] `ProtectedArray_struct_FaceInfo_` `82/88 -> 86/90`; [UID:0000B5] `ProtectedArray_struct_HairInfo_` `82/88 -> 86/90`; [UID:0000B6] `ProtectedArray_struct_HeadInfo_` `82/88 -> 86/90`.
- Owner/emitter decisions: unchanged. All three remain `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU` through [UID:0000MU][ProtectedArray](../../../by-file/ProtectedArray.md) as reusable template support. [UID:0000JY][HumanImageLib](../../../by-file/HumanImageLib.md) remains the concrete embedder/feature owner for old-human fields and table-loading integration, not the reusable template-source owner.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616`; IDA `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, and `search_structs`; local `tools/int_convert.py`; wave2 metadata JSON under `source-3/core/data/cache/wave2/classes`; generated-file search with `rg --files`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 references.
- Face evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5ad0` folded into broad `sub_4D2720`, one rel32 cleanup/unwind-style ref at `0x005ffba1`, exact deleting destructor `0x004e60c0` size `0x2f` / 47, vtable slot `0x0061b694`, HumanImageLib constructor/destructor embed xrefs at `0x004d28f1` and `0x004d4e75`, ordinary/deleting vtable resets at `0x004e5ad3` and `0x004e60c9`, and no direct rel32 calls/jumps to the deleting destructor.
- Hair evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5ae0`, one rel32 cleanup/unwind-style ref at `0x005ffbc3`, accessor `0x004e5f20` size `0x20` / 32 with fallback at `+0x10` and `0x10` / 16-byte stride, 105 direct code refs grouped as one constructor ref, 26 currently unmodeled old-human composition refs, and 78 refs in `sub_4D9180`, exact deleting destructor `0x004e60f0` size `0x2f` / 47, vtable slot `0x0061b6a4`, HumanImageLib constructor/destructor embed xrefs at `0x004d2947` and `0x004d4e4b`, and the blind PE rel32 candidate at `0x004f1166` was checked/rejected as a stack-byte store displacement rather than an instruction-start call/jump.
- Head evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5af0` folded into broad `sub_4D2720`, two rel32 cleanup/unwind-style refs at `0x005ffb00` and `0x005ffb0e`, exact deleting destructor `0x004e6120` size `0x2f` / 47, vtable slot `0x0061b674`, two HumanImageLib constructor embed refs at `0x004d2792` and `0x004d27ad`, two destructor cleanup refs at `0x004d4f23` and `0x004d4f35`, ordinary/deleting vtable resets at `0x004e5af3` and `0x004e6129`, and HumanImageLib layout fields `headArray` `+0x004` and `headSpecialArray` `+0x020`.
- Blockers investigated: final C++ remains blank for all three because `search_structs ProtectedArray`, `FaceInfo`, `HairInfo`, and `HeadInfo` returned no local IDA type records; wave2 metadata says `has_struct:false` and `has_vtables:false`; `rg --files` found no current `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp` generated files; and current docs/IDA/PE evidence do not prove the original template header basename, final member names, exact `FaceInfo`/`HairInfo`/`HeadInfo` source declarations, or Hair's final source-facing accessor method name. These are final-source blockers, not owner/emitter blockers.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_FaceInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_HairInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_HeadInfo_.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; all exited `0` with `ok: 1`. The first validation pass reported completion/confidence updates and stats-row removal for `0000B3`; subsequent passes removed `0000B5` and `0000B6` from low-score stats. A filtered rerun of the same four commands also exited `0` with `ok: 1` for every file.
- Leases used: A001 leased all four changed by-* docs/reports and this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-class-completion-protectedarray-face-hair-head-20260616-51` as complete. Scores cleared the gate at [UID:0000B3] `86/90`, [UID:0000B5] `86/90`, and [UID:0000B6] `86/90`; owner/emitter routes remain through [UID:0000MU] `ProtectedArray`; no IDA DB or supervisor-owned `by-memory/-coverage-report.md` changes were required.

## 2026-06-16 Assignment - A001-goal2-class-completion-protectedarray-face-hair-head-20260616-51

Assigned targets:
- [UID:0000B3] `by-class/ProtectedArray_struct_FaceInfo_.md`
- [UID:0000B5] `by-class/ProtectedArray_struct_HairInfo_.md`
- [UID:0000B6] `by-class/ProtectedArray_struct_HeadInfo_.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven class/template-instantiation completion pass from refreshed `project-level/-auto-completion-stats.md`. Targets are same-pattern ProtectedArray instantiation pages at `82/88` with known [UID:0000MU] `ProtectedArray` owner/emitter, HumanImageLib embedding evidence, and exact destructor/accessor/vtable support pages.
- Refresh exact destructor/accessor/vtable evidence, ProtectedArray template handling, HumanImageLib embedding evidence, owner/emitter decisions, final template/declaration/source-placement blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata/PE evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-class-completion-protectedarray-acc-body-20260616-50

- Changed target docs: `by-class/ProtectedArray_struct_Acc1Info_.md`, `by-class/ProtectedArray_struct_Acc2Info_.md`, and `by-class/ProtectedArray_struct_BodyInfo_.md`.
- Changed support/report docs: `by-class/-coverage-report.md`. Validator `--apply` refreshed project-level/autogen state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000AX] `ProtectedArray_struct_Acc1Info_` `82/88 -> 86/90`; [UID:0000AY] `ProtectedArray_struct_Acc2Info_` `82/88 -> 86/90`; [UID:0000AZ] `ProtectedArray_struct_BodyInfo_` `82/88 -> 86/90`.
- Owner/emitter decisions: unchanged. All three remain `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU` through [UID:0000MU][ProtectedArray](../../../by-file/ProtectedArray.md) as reusable template support. [UID:0000JY][HumanImageLib](../../../by-file/HumanImageLib.md) remains the concrete embedder/feature owner for the old-human fields and table-loading integration, not the reusable template-source owner.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616`; IDA `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, and `search_structs`; local `tools/int_convert.py`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 call/jump references.
- Acc1 evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5a70` folded into broad `sub_4D2720`, one rel32 cleanup/unwind-style ref at `0x005ffbb2`, exact deleting destructor `0x004e5fa0` size `0x2f`, vtable slot `0x0061b69c`, HumanImageLib constructor/destructor embed xrefs at `0x004d2919` and `0x004d4e60`, and no direct rel32 calls/jumps to the deleting destructor.
- Acc2 evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5a80`, accessor `0x004e5f40` size `0x25` with fallback at `+0x10` and `0x14` / 20-byte stride, 27 direct rel32 accessor callers, exact deleting destructor `0x004e5fd0` size `0x2f`, vtable slot `0x0061b6ac`, HumanImageLib constructor/destructor embed xrefs at `0x004d296e` and `0x004d4e36`, and no direct rel32 calls/jumps to the deleting destructor.
- Body evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5a90` folded into broad `sub_4D2720`, one rel32 cleanup/unwind-style ref at `0x005ffb1c`, exact deleting destructor `0x004e6000` size `0x2f`, vtable slot `0x0061b67c`, HumanImageLib constructor/destructor embed xrefs at `0x004d27c9` and `0x004d4f14`, and no direct rel32 calls/jumps to the deleting destructor.
- Blockers investigated: final C++ remains blank for all three because `search_structs ProtectedArray` returned no local IDA type record and current docs/IDA/PE evidence do not prove the original template header basename, final member names, exact `Acc1Info`/`Acc2Info`/`BodyInfo` source declarations, or the full source-facing integration declarations. These are final-source blockers, not owner/emitter blockers.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_Acc1Info_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_Acc2Info_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_BodyInfo_.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; the validation loop exited `0` and each queued command reported `ok: 1`. Post-validation `Select-String` for `0000AX|0000AY|0000AZ|ProtectedArray_struct_Acc1Info|ProtectedArray_struct_Acc2Info|ProtectedArray_struct_BodyInfo` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all four changed by-* docs/reports and this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 A001 Report - A001-goal2-class-completion-protectedarray-coat-effect-pixmap-20260616-53

- Changed target docs: `by-class/ProtectedArray_struct_CoatInfo_.md`, `by-class/ProtectedArray_struct_EffectInfo_.md`, and `by-class/ProtectedArray_struct_EffectPixMapInfo_.md`.
- Changed support/report docs: `by-class/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000B0] `ProtectedArray_struct_CoatInfo_` `82/88 -> 86/90`; [UID:0000B1] `ProtectedArray_struct_EffectInfo_` `82/88 -> 86/90`; [UID:0000B2] `ProtectedArray_struct_EffectPixMapInfo_` `82/88 -> 86/90`.
- Owner/emitter decisions: unchanged. All three remain `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU` through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) as reusable template support. [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) is the concrete embedder for `CoatInfo` (`coatArray` at `+0x05c`), and [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) is the concrete embedder for `EffectInfo` (`+0x04`, scratch `+0x14`) and `EffectPixMapInfo` (`+0x48`, fallback `+0x58`).
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; IDA `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, and `int_convert`; generated-file search with `rg --files`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 references.
- Coat evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5aa0` folded into broad `sub_4D2720` size `0x23aa`, one rel32 cleanup/unwind-style ref at `0x005ffb2a`, exact deleting destructor `0x004e6030` size `0x2f` / 47, vtable slot `0x0061b684`, HumanImageLib constructor/destructor embed xrefs at `0x004d27e5` and `0x004d4f05`, ordinary/deleting vtable resets at `0x004e5aa3` and `0x004e6039`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x24`.
- EffectInfo evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5ab0` folded into broad `sub_4DDF60` size `0xee`, one rel32 cleanup/unwind-style ref at `0x00600095`, exact deleting destructor `0x004e6060` size `0x2f` / 47, vtable slot `0x0061b714`, EffectObjImageLib constructor/destructor/scalar-deleting refs at `0x004ddfb6`, `0x004de158`, and `0x004e63ff`, ordinary/deleting vtable resets at `0x004e5ab3` and `0x004e6069`, constructor/destructor field evidence for `+0x04` and `+0x0c`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x44`.
- EffectPixMapInfo evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5ac0` folded into broad `sub_4DDF60` size `0xee`, one rel32 cleanup/unwind-style ref at `0x006000a0`, exact deleting destructor `0x004e6090` size `0x2f` / 47, vtable slot `0x0061b71c`, EffectObjImageLib constructor/destructor/scalar-deleting refs at `0x004ddfd9`, `0x004de149`, and `0x004e63f0`, ordinary/deleting vtable resets at `0x004e5ac3` and `0x004e6099`, constructor/destructor field evidence for `+0x48` and `+0x50`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x14`.
- Blockers investigated: final C++ remains blank for all three because `search_structs ProtectedArray`, `CoatInfo`, `EffectInfo`, `EffectPixMapInfo`, `HumanImageLib`, and `EffectObjImageLib` returned no local IDA type records; `rg --files` found no current `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp` generated files for these instantiations; the only non-doc generated-file matches were Wave2 JSON metadata, not used as authoritative source evidence; and current IDA/docs/PE evidence does not prove the original template header basename, final member declarations, exact `CoatInfo` / `EffectInfo` / `EffectPixMapInfo` source declarations, or whether `EffectPixMapInfo` was originally a typedef versus a one-field record.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_CoatInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_EffectInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_EffectPixMapInfo_.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; the full validation loop exited `0`. A filtered rerun of the same four commands also exited `0` with `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1` for every file. Post-validation `Select-String` for `0000B0|0000B1|0000B2|ProtectedArray_struct_CoatInfo|ProtectedArray_struct_EffectInfo|ProtectedArray_struct_EffectPixMapInfo` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all four changed by-* docs/reports and this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 A001 Report - A001-goal2-class-completion-protectedarray-helmet-item-light-20260616-55

- Changed target docs: `by-class/ProtectedArray_struct_HelmetInfo_.md`, `by-class/ProtectedArray_struct_ItemInfo_.md`, and `by-class/ProtectedArray_struct_LightInfo_.md`.
- Changed support/report docs: `by-class/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000B7] `ProtectedArray_struct_HelmetInfo_` `82/88 -> 86/90`; [UID:0000B8] `ProtectedArray_struct_ItemInfo_` `82/88 -> 86/90`; [UID:0000B9] `ProtectedArray_struct_LightInfo_` `82/88 -> 86/90`.
- Owner/emitter decisions: unchanged. All three remain `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU` through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) as reusable template support. [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) is the concrete embedder for `HelmetInfo` (`helmetArray` at `+0x1c0`), [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md) is the concrete embedder for `ItemInfo` (`+0x04`, fallback `+0x14`), and [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md) is the concrete embedder for `LightInfo` (`+0x04`, fallback `+0x14`).
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; IDA `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, and `int_convert`; generated-file search with `rg --files`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 references.
- Helmet evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b00` folded into broad `sub_4D2720` size `0x23aa`, one rel32 cleanup/unwind-style ref at `0x005ffbe5`, exact deleting destructor `0x004e6150` size `0x2f` / 47, vtable slot `0x0061b6b4`, HumanImageLib constructor/destructor embed xrefs at `0x004d298f` and `0x004d4e21`, ordinary/deleting vtable resets at `0x004e5b03` and `0x004e6159`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x20`.
- ItemInfo evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b10` folded into `ItemObjImageLibConstructor` size `0x1eb`, ordinary destructor start `0x004dee20` still not modeled as a function, one rel32 cleanup/unwind-style ref at `0x00600163`, exact deleting destructor `0x004e6180` size `0x2f` / 47, vtable slot `0x0061b734`, ItemObjImageLib constructor/destructor/scalar-deleting refs at `0x004dec92`, `0x004dee2c`, and `0x004e658f`, ordinary/deleting vtable resets at `0x004e5b13` and `0x004e6189`, constructor field evidence for `+0x04/+0x08/+0x0c/+0x10`, fallback row `+0x14`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x24`.
- LightInfo evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b20` folded into `LightObjImageLibConstructor` size `0x2c6`, ordinary destructor start `0x004dfab0` still not modeled as a function, one rel32 cleanup/unwind-style ref at `0x006001db`, exact deleting destructor `0x004e61b0` size `0x2f` / 47, vtable slot `0x0061b74c`, LightObjImageLib constructor/destructor/scalar-deleting refs at `0x004df842`, `0x004dfb14`, and `0x004e664e`, ordinary/deleting vtable resets at `0x004e5b23` and `0x004e61b9`, constructor field evidence for `+0x04/+0x08/+0x0c/+0x10`, fallback row `+0x14`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x2c`.
- Blockers investigated: final C++ remains blank for all three because `search_structs ProtectedArray`, `HelmetInfo`, `ItemInfo`, `LightInfo`, `HumanImageLib`, `ItemObjImageLib`, and `LightObjImageLib` returned no local IDA type records; `rg --files` found no current `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp` generated files for these instantiations; the only non-doc generated-file matches were Wave2 JSON metadata, not used as authoritative source evidence; and current IDA/docs/PE evidence does not prove the original template header basename, final member declarations, or exact `HelmetInfo` / `ItemInfo` / `LightInfo` source declarations.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_HelmetInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_ItemInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_LightInfo_.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; the full validation loop exited `0`. A filtered rerun of the same four commands also exited `0` with `ok: 1`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1` for every file. Post-validation `Select-String` for `0000B7|0000B8|0000B9|ProtectedArray_struct_HelmetInfo|ProtectedArray_struct_ItemInfo|ProtectedArray_struct_LightInfo` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all four changed by-* docs/reports and this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-class-completion-protectedarray-helmet-item-light-20260616-55` as complete. Scores cleared the gate at [UID:0000B7] `86/90`, [UID:0000B8] `86/90`, and [UID:0000B9] `86/90`; owner/emitter routes remain through [UID:0000MU] `ProtectedArray`; no IDA DB or supervisor-owned `by-memory/-coverage-report.md` changes were required. Supervisor revalidated the three target pages and `by-class/-coverage-report.md` with scoped validator passes (`ok:1`).

## 2026-06-16 Assignment - A001-goal2-class-completion-protectedarray-mantle-necklace-shoe-weapon-20260616-57

Assigned targets:
- [UID:0000BA] `by-class/ProtectedArray_struct_MantleInfo_.md`
- [UID:0000BB] `by-class/ProtectedArray_struct_NecklaceInfo_.md`
- [UID:0000BC] `by-class/ProtectedArray_struct_ShoeInfo_.md`
- [UID:0000BD] `by-class/ProtectedArray_struct_WeaponInfo_.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 stats-driven class/template-instantiation completion pass from refreshed `project-level/-auto-completion-stats.md`. Quick-peek shows the same coherent ProtectedArray instantiation pattern at `82/88`, known [UID:0000MU] `ProtectedArray` owner/emitter, and concrete old-human HumanImageLib embedder evidence.
- Refresh exact ordinary/deleting destructor evidence, vtable slots, ProtectedArray template handling, HumanImageLib embedding evidence, owner/emitter decisions, final template/declaration/source-placement blockers, and support docs/reports.
- Investigate every listed blocker instead of repeating it. Resolve blockers where supported; otherwise record exact IDA/docs/metadata/PE/Wave2 evidence checked and why the issue remains unsafe.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-class-completion-protectedarray-mantle-necklace-shoe-weapon-20260616-57

- Changed target docs: `by-class/ProtectedArray_struct_MantleInfo_.md`, `by-class/ProtectedArray_struct_NecklaceInfo_.md`, `by-class/ProtectedArray_struct_ShoeInfo_.md`, and `by-class/ProtectedArray_struct_WeaponInfo_.md`.
- Changed support/report docs: `by-class/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000BA] `ProtectedArray_struct_MantleInfo_` `82/88 -> 86/90`; [UID:0000BB] `ProtectedArray_struct_NecklaceInfo_` `82/88 -> 86/90`; [UID:0000BC] `ProtectedArray_struct_ShoeInfo_` `82/88 -> 86/90`; [UID:0000BD] `ProtectedArray_struct_WeaponInfo_` `82/88 -> 86/90`.
- Owner/emitter decisions: unchanged. All four remain `CANONICAL_OWNER:0000MU` and `EMITTER_UIDS:0000MU` through [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) as reusable template support. [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) remains the concrete embedder/feature owner for old-human fields and table-loading integration, not the reusable template-source owner.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; IDA `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, `search_structs`, and `int_convert`; generated-file search with `rg --files`; and a read-only section-mapped PE scan for absolute VA, RVA, and rel32 references.
- Mantle evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b30` folded into broad `sub_4D2720` size `0x23aa` / 9130 bytes, one rel32 cleanup/unwind-style ref at `0x005ffbf6`, exact deleting destructor `0x004e61e0` size `0x2f` / 47, vtable slot `0x0061b6bc`, HumanImageLib constructor/destructor embed xrefs at `0x004d29b7` and `0x004d4e0c`, ordinary/deleting vtable resets at `0x004e5b33` and `0x004e61e9`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x20` / 32 bytes.
- Necklace evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b40` folded into broad `sub_4D2720`, one rel32 cleanup/unwind-style ref at `0x005ffc07`, exact deleting destructor `0x004e6210` size `0x2f` / 47, vtable slot `0x0061b6c4`, HumanImageLib constructor/destructor embed xrefs at `0x004d29df` and `0x004d4df7`, ordinary/deleting vtable resets at `0x004e5b43` and `0x004e6219`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x20` / 32 bytes.
- Shoe evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b50` folded into broad `sub_4D2720`, one rel32 cleanup/unwind-style ref at `0x005ffc18`, exact deleting destructor `0x004e6240` size `0x2f` / 47, vtable slot `0x0061b6cc`, HumanImageLib constructor/destructor embed xrefs at `0x004d2a07` and `0x004d4de2`, ordinary/deleting vtable resets at `0x004e5b53` and `0x004e6249`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x20` / 32 bytes.
- Weapon evidence summary: live IDA/PE reconfirmed ordinary destructor `0x004e5b60` folded into broad `sub_4D2720`, six rel32 cleanup/unwind-style refs at `0x005ffb3b`, `0x005ffb4c`, `0x005ffb5d`, `0x005ffb6e`, `0x005ffb7f`, and `0x005ffb90`, exact deleting destructor `0x004e6270` size `0x2f` / 47, vtable slot `0x0061b68c`, six HumanImageLib constructor embed refs at `0x004d2801`, `0x004d2829`, `0x004d2851`, `0x004d2879`, `0x004d28a1`, and `0x004d28c9`, six destructor cleanup refs at `0x004d4e8a`, `0x004d4e9f`, `0x004d4eb4`, `0x004d4ec9`, `0x004d4ede`, and `0x004d4ef3`, ordinary/deleting vtable resets at `0x004e5b63` and `0x004e6279`, no direct rel32 calls/jumps to the deleting destructor, and delete-size immediate `0x20` / 32 bytes.
- Blockers investigated: final C++ remains blank for all four because `search_structs ProtectedArray`, `MantleInfo`, `NecklaceInfo`, `ShoeInfo`, `WeaponInfo`, and `HumanImageLib` returned no local IDA type records; `rg --files` found no current `source-3/simroot_v2/class_ProtectedArray_struct_*.cpp` generated files for these instantiations; the only non-doc generated-file matches were Wave2 JSON metadata, not used as authoritative source evidence; and current IDA/docs/PE evidence does not prove the original template header basename, final member declarations, exact `MantleInfo` / `NecklaceInfo` / `ShoeInfo` / `WeaponInfo` source declarations, or Weapon's final six weapon-family member names/order.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_MantleInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_NecklaceInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_ShoeInfo_.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\ProtectedArray_struct_WeaponInfo_.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`; all exited `0` with `ok: 1`. A final Shoe wording-only validator rerun also exited `0` with `ok: 1`. Post-validation `Select-String` for `0000BA|0000BB|0000BC|0000BD|ProtectedArray_struct_MantleInfo|ProtectedArray_struct_NecklaceInfo|ProtectedArray_struct_ShoeInfo|ProtectedArray_struct_WeaponInfo` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all five changed by-* docs/reports and this notes file before editing. `by-class/-coverage-report.md` was initially held by A002, then A001 obtained it and applied the row replacements directly.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

Supervisor integration update (2026-06-16): supervisor revalidated the four target class pages and `by-class/-coverage-report.md` with scoped `validator.py --mode file --apply --queue-timeout 240`; all passes exited `0` with `ok:1`. No A001 supervisor-owned memory rows remain pending for `A001-goal2-class-completion-protectedarray-mantle-necklace-shoe-weapon-20260616-57`.

## 2026-06-16 Assignment - A001-goal2-class-completion-desc-editablepaper-layer-textfilter-20260616-58

Assigned targets:
- [UID:00003Q] `by-class/DescPane.md`
- [UID:000048] `by-class/EditablePaperPane.md`
- [UID:000073] `by-class/Layer.md`
- [UID:0000EQ] `by-class/TextFilter.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 class-confidence/completion batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded class pages at `84/86`, with existing owner/emitter routes and clear support docs.
- Improve documentation, evidence quality, completion, and confidence where justified. Review associated by-file, by-memory, by-global, and by-type support pages if the class evidence depends on them.
- Investigate final source-quality blockers now: raw non-function starts, helper/provider/interface names, packet/text/layout field names, source-file placement, split/merge/range questions, vtable/layout evidence, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-class-completion-desc-editablepaper-layer-textfilter-20260616-58

- Changed target docs: `by-class/DescPane.md`, `by-class/EditablePaperPane.md`, `by-class/Layer.md`, and `by-class/TextFilter.md`.
- Changed support/report docs: `by-class/-coverage-report.md`, `by-file/EditablePaperPane.md`, and `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and autogen/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:00003Q] `DescPane` `84/86 -> 86/88`; [UID:000048] `EditablePaperPane` class `84/86 -> 86/88`; [UID:000073] `Layer` `84/86 -> 86/88`; [UID:0000EQ] `TextFilter` `84/86 -> 86/88`; direct support [UID:0000IX] `by-file/EditablePaperPane` `86/85 -> 86/87`.
- Owner/emitter decisions: unchanged. `DescPane` remains `CANONICAL_OWNER/EMITTER_UIDS:0000IS`; `EditablePaperPane` class remains `0000IX`; `Layer` remains `0000KL`; `TextFilter` remains `0000OO`; by-file `EditablePaperPane` remains `CANONICAL_OWNER:FILE` with projected route `NexusTK/ui/dialogs/`.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; MCP `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `func_profile`, `search_structs`, `type_query`, and `entity_query`. No Wave2/Wave3 source output was used as authority.
- DescPane evidence summary: live IDA reconfirmed raw/non-function starts at `0x0049d6f0` and `0x0049d780`, modeled child sizes (`0x0049d740` size `0x29`, `0x0049d770` size `0x6`, `0x0049d7c0` size `0x5e`, adjustors size `0xb`, deleting destructor size `0x5f`), four `g_pDescPane` refs, three-vtable ownership, refresh vtable ref at `0x00618a20`, destructor profile, and no IDA UDT/provider type evidence.
- EditablePaperPane evidence summary: live IDA reconfirmed constructor/action/setup/parser/save/draw/destructor sizes, constructor refs at `0x00508338`, `0x0050836b`, `0x005128e5`, and `0x00512945`, zero xrefs to wrapper starts `0x005128a0`/`0x00512900`, vtable stores at `0x00621afc`/`0x00621b60`/`0x00621b90`, `aLine001Epd` at `0x00621b98`, false `0x0045004e` LodePNG ownership, packet/draw profiles, and no IDA UDT/source-facing paper field names.
- Layer evidence summary: live IDA reconfirmed all 22 modeled functions in `0x004f0480-0x004f1bf6`, internal non-function gaps at `0x004f0b80`, `0x004f0c10`, and `0x004f0c70`, half-open end `0x004f1bf6`, successor `0x004f1c00`, constructor/render/dirty profiles, Pane caller routes, vtable refs at `0x0061ca48`, and no IDA `LayerNode` UDT/name evidence.
- TextFilter evidence summary: live IDA reconfirmed constructor `0x00595760` size `0x35`, non-deleting body `0x005957a0` size `0x11` with zero xrefs, sanitizer `0x005957c0` size `0x10a` with 14 code refs across 12 callers, scalar deleting destructor `0x005958d0` size `0x2e`, half-open end `0x005958fe`, successor `0x00595900`, 19 `g_pTextFilter` refs, four vtable refs, startup constructor caller `0x004f615f`, and no source-facing sanitizer type/name evidence.
- Blockers investigated: final C++ remains blank for all four class pages. DescPane is blocked by raw non-function constructor/setter starts and missing provider-interface/helper source names. EditablePaperPane is blocked by byte `+0x26d`, exact paper field names, and zero-ref wrapper source placement. Layer is blocked by `LayerNode` member/source declaration names. TextFilter is blocked by public declaration/folder-source placement and sanitizer helper spelling. These are real final-source blockers but no longer keep the assigned pages below `85/85`.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified because the unresolved names are source-facing rather than safe IDA metadata improvements.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file by-class\DescPane.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\EditablePaperPane.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\Layer.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\TextFilter.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 240`, `python .\tools\validator.py --mode file --file by-file\EditablePaperPane.md --apply --queue-timeout 240`, and `python .\tools\validator.py --mode file --file by-file\-coverage-report.md --apply --queue-timeout 240`; all exited `0` with `ok: 1`. The target/support UIDs no longer appear in `project-level/-auto-completion-stats.md`.
- Leases used: A001 leased all changed target docs, support docs, coverage reports, and this notes file before editing. `tools\leaser\Agents\Agent-A001\notes.md` was already leased when the later by-file support lease command ran, so that path reported `Rejected[Already has lease]` while `by-file\EditablePaperPane.md` and `by-file\-coverage-report.md` were successfully leased.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-class-completion-desc-editablepaper-layer-textfilter-20260616-58` as complete. Scores cleared the gate at [UID:00003Q] `86/88`, [UID:000048] `86/88`, [UID:000073] `86/88`, [UID:0000EQ] `86/88`, and support [UID:0000IX] `86/87`; owner/emitter routes remain unchanged. Supervisor revalidated the four class pages, `by-file/EditablePaperPane.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` with scoped validator passes (`ok:1`). No A001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A001-goal2-class-completion-itemcatalog-fitting-interface-statichelp-20260616-59

Assigned targets:
- [UID:00006T] `by-class/ItemCatalog.md`
- [UID:000055] `by-class/FittingRoomTextButtonControlPane.md`
- [UID:00006O] `by-class/InterfaceEfxMgr.md`
- [UID:0000E5] `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 class-confidence/completion batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows these are bounded class pages with known owner/emitter routes, not broad unknown-owner splits.
- Improve evidence quality, completion, and confidence where justified. Review direct support by-file, by-memory, by-global, by-resource, and by-type pages if the class evidence depends on them.
- Investigate final source-quality blockers now: ItemCatalog standalone-vs-embedded source placement and category-entry field/type names; FittingRoomTextButtonControlPane source placement versus RankingDialog reuse, inherited slots, paint constants, and field names; InterfaceEfxMgr singleton/effect/timer field names and source split from InterfaceEfx; StaticTextControlPane2 nested-class spelling, subobject names, and shared outlined/shadowed helper placement. Do not merely repeat blocker lists.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-class-completion-itemcatalog-fitting-interface-statichelp-20260616-59

- Changed target docs: `by-class/ItemCatalog.md`, `by-class/FittingRoomTextButtonControlPane.md`, `by-class/InterfaceEfxMgr.md`, and `by-class/StaticTextControlPane2__SimpleHelpTextPartPane.md`.
- Changed support/report docs: `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`, `by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md`, `by-file/InterfaceEfx.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md`. Validator `--apply` refreshed generated/projected state as needed. `by-memory/-coverage-report.md` was not edited.
- Score changes: [UID:00006T] `ItemCatalog` `82/88 -> 86/89`; [UID:000055] `FittingRoomTextButtonControlPane` `84/86 -> 86/88`; [UID:00006O] `InterfaceEfxMgr` `84/86 -> 86/88`; [UID:0000E5] `StaticTextControlPane2__SimpleHelpTextPartPane` `84/86 -> 86/88`; support [UID:0000WV] `ItemCatalogLookup` `84/88 -> 86/89`; support [UID:00011U] `SimpleHelpTextPartPaneCore` `84/90 -> 86/90`; support [UID:0000K9] `InterfaceEfx` file `87/85 -> 88/87`.
- Owner/emitter decisions: unchanged. `ItemCatalog` and `ItemCatalogLookup` remain `CANONICAL_OWNER/EMITTER_UIDS:0000KD`; `FittingRoomTextButtonControlPane` remains `0000JE`; `InterfaceEfxMgr` remains `0000K9`; `StaticTextControlPane2__SimpleHelpTextPartPane` remains `0000O8`; `SimpleHelpTextPartPaneCore` remains `0000E5`; `InterfaceEfx` file remains `CANONICAL_OWNER:FILE`.
- Evidence used: current target/support docs; live IDA MCP database `b001_mappane_0001AW_20260616` for read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; MCP `idb_list`, `lookup_funcs`, `xrefs_to`, `decompile`, `get_bytes`, and `search_structs`; and existing by-class/by-file/by-memory/by-global/by-resource docs. A raw `rg` search output included old Wave2 trace lines, but they were not used as evidence.
- ItemCatalog evidence summary: current IDA reconfirmed `sub_422690` size `0x3d`, `sub_4226D0` size `0x6f`, parser successor `0x00422740` size `0x1d9`, helper `0x00423810` size `0x50`, five callers per method, category lookup through `sub_423E40`, sentinel comparison against `this[137]`, vector count/index behavior, and corrected internal padding (`0x004226cc` is part of the first method's return instruction; padding starts at `0x004226cd`).
- FittingRoomTextButton evidence summary: current IDA reconfirmed seven local starts in `0x00424020-0x004242e5`, fourteen constructor refs including two RankingDialog uses, selected-state setter refs, primary/secondary/tertiary vtable refs, shared type-code helper `0x004242f0` with ten vtable refs across unrelated classes, and paint constants/state offsets (`208`, `216`, `212`, `128`, `134`; bytes `+0x101`, `+0x103`, `+0x110`; label pointer `+0x10c`).
- InterfaceEfxMgr evidence summary: current IDA reconfirmed manager method sizes, constructor caller `0x004f8ad8`, trigger caller `0x004b880b`, seven `g_pInterfaceEfxMgr` refs, manager vtables at `0x0061c63c/0x0061c688/0x0061c6b8`, persistent effect pointers at `+0xf8/+0xfc/+0x100`, timer scheduling at `+0xa4`, option gate `g_pConfig +0x28de5e`, resource refs, and `0x004ea130` as the `InventoryPane` successor.
- StaticHelp evidence summary: current IDA reconfirmed constructor `0x00499fe0` size `0xa0`, paint `0x0049a080` size `0x218`, raw starts `0x0049a2a0`/`0x0049a2d0` not modeled as functions, draw-line `0x0049a330` size `0xd3`, destructor `0x0049b560` size `0x48`, text-effect helpers `0x004bafa0`/`0x004bb080`, separate constant helper `0x004bb070`, draw-line caller refs, style-record dispatch, and GrafPort ownership for the shared outlined/shadowed helpers.
- Blockers investigated: final C++ remains blank for all targets/support pages. `search_structs` returned no local UDT records for `ItemCatalog`, `FittingRoomItem`, `Category`, `FittingRoomTextButtonControlPane`, `RankingDialog`, `InterfaceEfxMgr`, `InterfaceEfx`, `SimpleHelpTextPartPane`, `StaticTextControlPane2`, or `FontStyle`. Remaining blockers are source-facing: `ItemCatalog.cpp` versus embedded `FittingRoom.cpp`, category-entry field/type names, FittingRoomTextButton source placement versus RankingDialog reuse, final button field/paint-constant names, InterfaceEfxMgr member/timer names and one-file versus split-manager placement, StaticText2 nested class spelling, raw helper/member names, and shared text-effect declarations.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was justified because unresolved names are final source names rather than safe IDA metadata.
- Validation: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` for `by-class\ItemCatalog.md`, `by-class\FittingRoomTextButtonControlPane.md`, `by-class\InterfaceEfxMgr.md`, `by-class\StaticTextControlPane2__SimpleHelpTextPartPane.md`, `by-memory\0x00422690-0x0042273e.ItemCatalogLookup.md`, `by-memory\0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md`, `by-file\InterfaceEfx.md`, `by-class\-coverage-report.md`, and `by-file\-coverage-report.md`; all exited `0` with `ok: 1`. Post-validation `Select-String` for `00006T|000055|00006O|0000E5|0000WV|00011U|0000K9` in `project-level/-auto-completion-stats.md` returned no matches.
- Leases used: A001 leased all nine changed by-* docs/reports plus this notes file before editing.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows:
  - Replace the existing [UID:0000WV] row currently between `0x0042268f-0x00422690 | FittingRoomItemStateSaveAlignment` and `0x0042273f-0x00422740 | ItemCatalogLookupAlignment` with:
    `            - [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md) 0x00422690-0x0042273f | method pair | ItemCatalogLookup : reconstructable : 86% : strong : Current IDA-backed embedded ItemCatalog count/lookup methods with exact boundaries, corrected internal padding, fitting-room caller set, +0x504 placement evidence, category-vector behavior, parent attachment, and unresolved source-split/type-name blockers.`
  - Replace the existing [UID:00011U] row in the StaticTextControlPane/StaticText2 memory coverage section with:
    `    - [UID:00011U][0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore](by-memory/0x00499fe0-0x0049a402.SimpleHelpTextPartPaneCore.md) : reconstructable : 86% : strong : Current IDA confirms constructor, paint, draw-line, raw line-layout setter, raw opacity/state applier, style-record dispatch, vtable/draw-line refs, corrected half-open core boundary, raw helper padding, and unresolved nested/member-name blockers.`

Supervisor integration update (2026-06-16): supervisor accepted `A001-goal2-class-completion-itemcatalog-fitting-interface-statichelp-20260616-59` as complete. Scores cleared the gate at [UID:00006T] `86/89`, [UID:000055] `86/88`, [UID:00006O] `86/88`, [UID:0000E5] `86/88`, support [UID:0000WV] `86/89`, support [UID:00011U] `86/90`, and support [UID:0000K9] `88/87`; owner/emitter routes remain unchanged. Supervisor applied the exact [UID:0000WV] and [UID:00011U] `by-memory/-coverage-report.md` replacement rows and validated the shared report plus changed support memory pages (`ok:1`). No A001 supervisor-owned memory rows remain pending for this batch.

## 2026-06-16 Assignment - A001-goal2-file-confidence-swallow-cheat-config-cursor-20260616-60

Assigned targets:
- [UID:0000OD] `by-file/SwallowLayerPane.md`
- [UID:0000I6] `by-file/CheatDetector.md`
- [UID:0000IE] `by-file/Config.md`
- [UID:0000IL] `by-file/CursorManager.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence by-file batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded file/root pages with existing reviewed owner/path dispositions: SwallowLayerPane weather-overlay source split/raw helper questions, CheatDetector compact security singleton, Config/RegistryConfig split evidence already informed by prior B-agent work, and CursorManager as a reviewed non-standalone ScreenPane companion.
- Improve evidence quality, completion, and confidence where justified. Review direct by-class, by-memory, by-global, by-type, by-resource, and by-project-structure support pages when the file-page confidence depends on them.
- Investigate final source-quality blockers now: raw helper liveness, final source-file placement, base/helper/interface names, singleton/global declarations, layout/field names, source split/merge questions, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter/path decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Supervisor-Integrated Report - A001-goal2-file-confidence-swallow-cheat-config-cursor-20260616-60

- Changed target docs: `by-file/SwallowLayerPane.md`, `by-file/CheatDetector.md`, `by-file/Config.md`, and `by-file/CursorManager.md`.
- Changed support/report docs: `by-class/CheatDetector.md` and `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated/projected state as needed. No by-memory docs or `by-memory/-coverage-report.md` rows were edited.
- Score changes: [UID:0000OD] `SwallowLayerPane` `87/84 -> 88/86`; [UID:0000I6] `CheatDetector` file `86/85 -> 87/87`; [UID:0000IE] `Config` `86/85 -> 87/86`; [UID:0000IL] `CursorManager` `86/85 -> 87/87`; support [UID:00002Z] `CheatDetector` class remained at `85/86` with refreshed evidence.
- Owner/emitter/path decisions: unchanged. The file pages keep their current owner/path dispositions. `CursorManager` remains a reviewed non-standalone ScreenPane companion rather than a standalone source path. No assignment-only metadata change was made.
- Evidence and blockers: supervisor accepted the returned checkpoint because A001 investigated raw helper liveness, singleton/global declarations, Config/RegistryConfig split evidence, CursorManager non-standalone placement, support class evidence, and final-C++ blockers instead of merely listing them. Remaining blockers are source-facing names/layout/source-split questions, not current 85/85 gate blockers.
- IDA DB changes: none reported.
- Validation: supervisor reran scoped validator passes for the four by-file targets, `by-class/CheatDetector.md`, and `by-file/-coverage-report.md`; all exited `0` with `ok:1`.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 Assignment - A001-goal2-file-confidence-clanbank-datindex-framechrome-gameconfig-20260616-61

Assigned targets:
- [UID:0000I9] `by-file/ClanBank.md`
- [UID:0000IP] `by-file/DATIndexVector.md`
- [UID:0000JL] `by-file/FrameChrome.md`
- [UID:0000JP] `by-file/GameServerConfig.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence by-file batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded file/root pages with known source-route hypotheses: ClanBank social dialog cluster, standalone DATIndexVector archive helper, FrameChrome UI border/chrome file, and GameServerConfig map/nation-table helper.
- Improve evidence quality, completion, and confidence where justified. Review direct by-class, by-memory, by-global, by-type, by-resource, and by-project-structure support pages when the file-page confidence depends on them.
- Investigate final source-quality blockers now: source-file split/fold decisions, raw helper reachability, helper/base/interface names, packet subtype names, vtable/layout evidence, global declarations, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter/path decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Supervisor-Integrated Report - A001-goal2-file-confidence-clanbank-datindex-framechrome-gameconfig-20260616-61

- Changed target docs: `by-file/ClanBank.md`, `by-file/DATIndexVector.md`, `by-file/FrameChrome.md`, and `by-file/GameServerConfig.md`.
- Changed report docs: `by-file/-coverage-report.md`. Validator `--apply` refreshed generated/projected state as needed.
- Score changes: [UID:0000I9] `ClanBank` `86/85 -> 87/87`; [UID:0000IP] `DATIndexVector` `86/85 -> 87/87`; [UID:0000JL] `FrameChrome` `86/85 -> 87/86`; [UID:0000JP] `GameServerConfig` `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. `ClanBank`, `DATIndexVector`, `FrameChrome`, and `GameServerConfig` remain file-owned with their existing projected source paths; no emitter/owner metadata changes were justified.
- Evidence and blockers: supervisor accepted the returned checkpoint because A001 investigated raw start reachability, xref/pointer evidence, broad caller fanout, file split/fold decisions, helper/base/interface names, packet subtype names, vtable/layout evidence, global declarations, and final-C++ blockers instead of merely listing them. Remaining blockers are source-facing split/name/declaration questions, not current 85/85 gate blockers.
- IDA DB changes: none reported.
- Validation: supervisor reran scoped validator passes for the four by-file targets and `by-file/-coverage-report.md`; all exited `0` with `ok:1`. The refreshed stats no longer list [UID:0000I9], [UID:0000IP], [UID:0000JL], or [UID:0000JP].
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 Assignment - A001-goal2-file-confidence-clandialogs-dialogpane-icons-imagewriters-20260616-62

Assigned targets:
- [UID:0000IA] `by-file/ClanDialogs.md`
- [UID:0000IT] `by-file/DialogPane.md`
- [UID:0000JZ] `by-file/IconsPane.md`
- [UID:0000K4] `by-file/ImageWriters.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence by-file batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded file/root pages with known owner/path dispositions: `ClanDialogs` split-candidate modal dialog cluster, `DialogPane` common UI core base, `IconsPane` panel singleton/source-root, and `ImageWriters` render/image output support. These are not broad unknown-owner split jobs; if you discover one is actually a heavy heuristic ownership/split problem, record that explicitly and continue with the remaining bounded targets.
- Improve evidence quality, completion, and confidence where justified. Review direct by-class, by-memory, by-global, by-type, by-resource, and by-project-structure support pages when the file-page confidence depends on them.
- Investigate final source-quality blockers now: source-file split/fold decisions, raw helper/constructor reachability, field/layout/member names, base/helper/interface names, singleton/global declarations, codec/source-boundary ownership, generated-output omissions, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any assigned target does not return at least `85/85`, do additional research before reporting completion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter/path decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Supervisor-Integrated Report - A001-goal2-file-confidence-clandialogs-dialogpane-icons-imagewriters-20260616-62

- Changed target docs: `by-file/ClanDialogs.md`, `by-file/DialogPane.md`, `by-file/IconsPane.md`, and `by-file/ImageWriters.md`.
- Changed report docs: `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated/projected state as needed.
- Score changes: [UID:0000IA] `ClanDialogs` `86/85 -> 87/86`; [UID:0000IT] `DialogPane` `86/85 -> 87/86`; [UID:0000JZ] `IconsPane` `86/85 -> 87/86`; [UID:0000K4] `ImageWriters` `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. `ClanDialogs`, `DialogPane`, `IconsPane`, and `ImageWriters` retain their current file-owner/path dispositions; no assignment-only metadata changes were justified.
- Evidence and blockers: supervisor accepted the returned checkpoint because A001 investigated raw ClanDialogs constructor reachability, DialogPane constructor/slide/global/vtable evidence, IconsPane raw dispatch and shared action helper evidence, ImageWriters JPEG/PNG ownership boundaries, generated-output omissions, and final-C++ blockers instead of merely listing them. Remaining blockers are source-facing split/name/declaration questions, not current 85/85 gate blockers.
- IDA DB changes: none reported.
- Validation: supervisor reran scoped validator passes for the four by-file targets and `by-file/-coverage-report.md`; all exited `0` with `ok:1`.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 Assignment - A001-goal2-file-confidence-itemmenu-md5-msghandler-menuvariety-20260616-63

Assigned targets:
- [UID:0000KF] `by-file/ItemMenuDialogs.md`
- [UID:0000L6] `by-file/MD5.md`
- [UID:0000LM] `by-file/MSGHandler.md`
- [UID:0000L8] `by-file/MenuVarietyPanes.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence by-file batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded file/root pages with known owner/source-path hypotheses: item context-menu dialog/list grouping, MD5 utility module, MSGHandler app message-handler swapper, and MenuVariety pane/select source family.
- Improve evidence quality, completion, and confidence where justified. Review direct by-class, by-memory, by-global, by-type/by-vtable, by-resource, and by-project-structure support pages when the file-page confidence depends on them.
- Investigate final source-quality blockers now: standalone-vs-folded source placement, raw helper reachability, utility/module ownership, vtable/rdata/source anchors, final helper/type/member names, generated-output omissions, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any assigned target becomes heavy heuristic ownership/source-structure work, document the evidence and recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter/path decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Supervisor-Integrated Report - A001-goal2-file-confidence-itemmenu-md5-msghandler-menuvariety-20260616-63

- Changed target docs: `by-file/ItemMenuDialogs.md`, `by-file/MD5.md`, `by-file/MSGHandler.md`, and `by-file/MenuVarietyPanes.md`.
- Changed report docs: `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated/projected state as needed.
- Score changes: [UID:0000KF] `ItemMenuDialogs` `86/85 -> 87/86`; [UID:0000L6] `MD5` `86/85 -> 87/86`; [UID:0000LM] `MSGHandler` `86/85 -> 87/86`; [UID:0000L8] `MenuVarietyPanes` `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. `ItemMenuDialogs`, `MD5`, `MSGHandler`, and `MenuVarietyPanes` retain their current file-owner/path dispositions; no assignment-only metadata changes were justified.
- Evidence and blockers: supervisor accepted the returned checkpoint because A001 investigated raw start/call-target reachability, packet MD5 callers, menu-variety helper callers, standalone-vs-folded placement, utility/module ownership, vtable/rdata/source anchors, helper/type/member names, generated-output omissions, and final-C++ blockers instead of merely listing them. Remaining blockers are source-facing split/name/declaration questions, not current 85/85 gate blockers.
- IDA DB changes: none reported.
- Validation: supervisor reran scoped validator passes for the four by-file targets and `by-file/-coverage-report.md`; all exited `0` with `ok:1`.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none.

## 2026-06-16 Assignment - A001-goal2-file-confidence-maptile-myitem-parcel-photo-20260616-64

Assigned targets:
- [UID:0000L5] `by-file/MapTileImageLib.md`
- [UID:0000LO] `by-file/MyItemListPane.md`
- [UID:0000MF] `by-file/ParcelPane.md`
- [UID:0000MK] `by-file/PhotoPane.md`

Instructions:
- Read and follow `Agent-A001/goal.md`, current `Supervisor.md`, `Supervisor_notes.md`, lease rules, by-structure rules, validator requirements, and the active source-quality investigation policy.
- This is a Goal 2 low-confidence by-file batch from refreshed `project-level/-auto-completion-stats.md`. Supervisor quick-peek shows bounded file/root pages with known owner/source-path hypotheses: terrain tile image library, reusable item-picker dialog list, parcel notification pane family, and map photo/viewer pane family.
- Improve evidence quality, completion, and confidence where justified. Review direct by-class, by-memory, by-global, by-type/by-vtable, by-resource, and by-project-structure support pages when the file-page confidence depends on them.
- Investigate final source-quality blockers now: exact original filename/folder, standalone-vs-folded placement, raw helper/constructor/destructor reachability, utility/module ownership, vtable/layout/resource anchors, final helper/type/member names, generated-output omissions, and final-C++ eligibility. Do not merely repeat blocker lists; resolve supported items, document exact evidence checked for unresolved blockers, or keep/lower scores if unresolved issues materially limit confidence.
- If any assigned target becomes heavy heuristic ownership/source-structure work, document the evidence and recommend B-agent escalation rather than forcing a conclusion.
- Do not directly edit `by-memory/-coverage-report.md`. Record exact replacement/insert/delete text and placement context here for any memory coverage rows the supervisor must apply.
- Report changed files, leases, validations, before/after score changes, owner/emitter/path decisions, blocker investigations, IDA DB changes if any, and exact pending supervisor-owned report rows.

## 2026-06-16 A001 Report - A001-goal2-file-confidence-maptile-myitem-parcel-photo-20260616-64

- Changed target docs: `by-file/MapTileImageLib.md`, `by-file/MyItemListPane.md`, `by-file/ParcelPane.md`, and `by-file/PhotoPane.md`.
- Changed report docs: `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md` and `tools/validator.ini` as generated/tool-owned state.
- Score changes: [UID:0000L5] `MapTileImageLib` `86/85 -> 87/86`; [UID:0000LO] `MyItemListPane` `86/85 -> 87/86`; [UID:0000MF] `ParcelPane` `86/85 -> 87/86`; [UID:0000MK] `PhotoPane` `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. All four targets remain `CANONICAL_OWNER:FILE`; projected paths remain `NexusTK/render/`, `NexusTK/ui/dialogs/`, `NexusTK/ui/panels/`, and `NexusTK/map/`. No by-class/by-memory owner or emitter metadata changes were made.
- Leases used: acquired `by-file/MapTileImageLib.md`, `by-file/MyItemListPane.md`, `by-file/ParcelPane.md`, `by-file/PhotoPane.md`, `by-file/-coverage-report.md`, and `tools/leaser/Agents/Agent-A001/notes.md` under `Agent-A001` before editing; final cleanup found no active target/report leases remaining, and `tools/leaser/Agents/current_leases.md` has no `Agent-A001` or touched-path entries.
- Validation commands/results: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` for each changed by-file page and `by-file/-coverage-report.md`; the loop exited `0`. The first pass reported `completion_update`/`confidence_update` and `stats_row_remove` for [UID:0000L5], and the completed loop removed all four assigned targets from the refreshed low-score stats list.
- Blocker investigations:
  - `MapTileImageLib`: live IDA MCP `lookup_funcs` and `xrefs_to` reconfirmed all six method/helper starts, startup-only constructor, constructor-only metadata helper, four `DrawTile` call sites including raw/no-function `0x0050c3d7`, ten singleton refs, and clean `0x0061b664` vtable stores. `find_regex` found RTTI names but no `MapTileImageLib.cpp`; `search_structs` found no local class struct. Generated output now covers ctor/draw/scalar/global but still omits ordinary destructor `0x004d19a0` and singleton clear `0x004e5bc0`.
  - `MyItemListPane`: live IDA MCP reconfirmed constructor/helper/draw starts, four constructor xrefs, two selected-slot helper xrefs, vtable-only `DrawListEntry` dispatch, and EPF/legacy item-image/text draw dependencies. Generated-output review found active `class_MyItemListPane.cpp` now emits `DrawListEntry`, resolving the old missing-body caveat; source split and row/API/inventory field names remain provisional. IDA has RTTI but no source filename or local struct.
  - `ParcelPane`: live IDA MCP reconfirmed ParcelIcon/Parcel/FlyingParcel modeled starts, MainUiGraph construction xrefs, `0x005461c0` secondary-vtable callback, parcel singleton refs, and PatchPane successor `0x005470b0`. Raw disassembly for `0x00546b80`/`0x00546bc0` proves real FlyingParcel cleanup/start bodies; `lookup_funcs` still says `Not a function`, and `find_bytes` found no absolute/RVA refs to those raw starts. Active generated output still omits those raw bodies and ParcelIcon ctor/callback; private-helper/source-name blockers remain.
  - `PhotoPane`: live IDA MCP reconfirmed PhotoPane/PictureViewPane modeled starts, exactly two constructor xrefs, `sub_5143C0` payload-reader/allocation behavior, raw `0x00549920` cleanup disassembly, vtable refs, and close-handler vtable slots. Active generated output still omits raw cleanup; IDA has RTTI but no `PhotoPane.cpp`/`PictureViewPane.cpp` string or local structs. Source split and helper/member names remain final-source blockers.
- IDA DB changes: none. All IDA work was read-only; no renames, comments, type declarations, patches, or saves were made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory docs were changed and the banned report was not edited.

## 2026-06-16 Assignment - A001-goal2-file-confidence-pane-miscwork-motion-pool-20260616-65

Assigned targets:
- [UID:0000MC] `by-file/Pane.md`
- [UID:0000LG] `by-file/MiscWorkThread.md`
- [UID:0000LL] `by-file/Motion.md`
- [UID:0000MM] `by-file/PoolAllocator.md`

## 2026-06-16 A001 Report - A001-goal2-file-confidence-pane-miscwork-motion-pool-20260616-65

- Changed target docs: `by-file/Pane.md`, `by-file/MiscWorkThread.md`, `by-file/Motion.md`, and `by-file/PoolAllocator.md`.
- Changed report docs: `by-file/-coverage-report.md`. Validator `--apply` refreshed `project-level/-auto-completion-stats.md` and `tools/validator.ini` as generated/tool-owned state.
- Score changes: [UID:0000MC] `Pane` `88/84 -> 88/86`; [UID:0000LG] `MiscWorkThread` `86/85 -> 87/86`; [UID:0000LL] `Motion` `86/85 -> 87/86`; [UID:0000MM] `PoolAllocator` `86/85 -> 87/86`.
- Owner/emitter/path decisions: unchanged. All four targets remain `CANONICAL_OWNER:FILE`; projected paths remain `NexusTK/ui/core/`, `NexusTK/app/`, `NexusTK/render/`, and `NexusTK/util/`. No by-class/by-memory owner or emitter metadata changes were made.
- Leases used: acquired `by-file/Pane.md`, `by-file/MiscWorkThread.md`, `by-file/Motion.md`, `by-file/PoolAllocator.md`, `by-file/-coverage-report.md`, and `tools/leaser/Agents/Agent-A001/notes.md` under `Agent-A001` before editing; released all target/report/notes leases after validation, and `tools/leaser/Agents/current_leases.md` has no `Agent-A001` or touched-path entries.
- Validation commands/results: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` for each changed by-file page and `by-file/-coverage-report.md`; the loop exited `0`. Validator removed [UID:0000MC], [UID:0000LG], [UID:0000LL], and [UID:0000MM] from the refreshed low-score stats output.
- Blocker investigations:
  - `Pane`: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed core starts/sizes, `95` constructor refs, `14` destructor refs, vtable base stores at `0x006219e8`, `0x00621a34`, and `0x00621a64`, dirty/motion helper caller clusters through Layer/surface presentation, six shared layer-membership helper refs, `Pane` RTTI at `0x006739a8`, no embedded `Pane.cpp` filename string, and no local IDA UDT. Remaining blockers are final helper/member names, generated-owner cleanup, and final C++ body quality.
  - `MiscWorkThread`: live IDA MCP reconfirmed modeled method/helper sizes, constructor caller `0x00464715`, `ProcessWorkItem` vtable ref, request-wrapper callers, eight `g_pMiscWorkThread` refs, vtable writes, RTTI strings for `MiscWorkThread`/`Singleton<MiscWorkThread>`, raw `0x005283b0` bytes, and no `0x005283b0` function/xrefs/VA/RVA pointer hits. Remaining blockers are final source path spelling, wrapper/helper names, notification-class nesting, and raw wrapper promotion.
  - `Motion`: live IDA MCP reconfirmed exact animation function sizes, primary constructor caller, zero direct refs to the alternate constructor, timer/destructor vtable refs, five Motion pool refs, animation callees, Region/Dialog/NewHumanImageLib exclusions, alignment bytes, Motion RTTI, no embedded `Motion.cpp` filename string, and no local UDT. Remaining blockers are final animation filename, alternate-constructor source shape, and member names.
  - `PoolAllocator`: live IDA MCP reconfirmed saved allocator names, exact six method/helper bounds, `19` static constructor callers, `33` allocation callers, `30` free callers, `19` destructor callers, private helper edges, decompiled field transitions, no local UDT, no embedded `PoolAllocator.cpp` source filename, and no RTTI string. Remaining blockers are standalone `PoolAllocator.cpp` versus private string/container support and final public/private API names.
- IDA DB changes: none. This pass was read-only; no rename, comment, type edit, function creation, patch, or IDB save was made.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: none. No by-memory docs were changed and the banned report was not edited.

## 2026-06-16 A001 Report - A001-goal2-midi-source-helper-completion-batch-20260616-67

- Changed target docs: `by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md`, `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md`, `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md`, `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md`, and `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md`.
- Generated/tool-owned changes: scoped validator `--apply` refreshed `project-level/-auto-completion-stats.md` and `tools/validator.ini`. The banned `by-memory/-coverage-report.md` was not edited.
- Score changes: [UID:0002C1] `MidiSourceSeekHelper` `80/88 -> 86/89`; [UID:0002C2] `MidiSourceRawReadHelper` `80/88 -> 86/89`; [UID:0002C3] `MidiSourceSizeReadyHelper` `80/88 -> 86/89`; [UID:0002C4] `MidiReaderConstructorInit` `80/88 -> 86/89`; [UID:0002C5] `MidiParseSuccessWrapper` `80/88 -> 86/89`.
- Owner/emitter decisions: unchanged. All five targets remain `CANONICAL_OWNER:0000LD`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LD`; no final C++ was added because the local source-quality gate still lacks defensible original MIDI document/helper type names and exact source file/class placement.
- Leases used: acquired the five target docs and `tools/leaser/Agents/Agent-A001/notes.md` under `Agent-A001` before edits; refreshed lease state before this notes update; target and notes leases were released after final verification.
- Evidence and blocker investigations:
  - Adapter/source abstraction: resolved from vague adapter wording to embedded `DATFile` at `this+0x18`, supported by `sub_527080 -> sub_49C130(this+6)`, DATFile layout size `0x14`, and FileStream/DATFile vtable slots.
  - Seek-origin constants: documented the branch mapping to Win32 `FILE_BEGIN`, `FILE_CURRENT`, and `FILE_END`; DATFile-backed seek also uses the same translated origin values through vtable slot `+0x18`.
  - Static MIDI document/storage naming: documented `0x0069b828` as role-named static MIDI document/source state and `0x0069b840` as the embedded DATFile tail cleaned by `sub_60C300 -> sub_49C160`; IDA string/type searches found no original MIDI document class/type/source filename.
  - Wrapper naming: documented stream-open caller `0x0052599d`, callee `sub_5273A0`, and exact equality-to-one transform for `MidiParseSuccessWrapper`; original source spelling remains unresolved.
  - Raw no-xref reachability: documented `lookup_funcs`/xref state for raw `0x00526fa0` and `0x00527040`, including exact raw bytes/padding and internal callers to DATFile helpers. `MidiSourceRawReadHelper`, constructor init, and parse wrapper have modeled function/caller evidence.
  - Final source file/class placement: researched `by-file/MidiPlayer.md`, parent helper island [UID:0000LD], DATFile support docs, type/vtable support docs, IDA strings, and IDA local type searches. Evidence supports `NexusTK/audio/` routing under the MidiPlayer helper island, but not final source file/class names or C++ declarations.
- IDA DB changes: none. Existing read-only IDA MCP session `a002_goal65_20260616` was used for lookup/decompile/xref/bytes/string/type checks only; no rename, comment, type edit, function creation, patch, or IDB save was made.
- Validation commands/results: from `source-3/project-documentation`, ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 240` for each of the five changed target docs. Verification pass results were:
  - `by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md`: mode file, apply True, scanned 1, `autogen_registry_rebuild: 1`, `autogen_report_noop: 7`, `ok: 1`, `projected_stats_update: 1`, exit 0.
  - `by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md`: mode file, apply True, scanned 1, `autogen_registry_rebuild: 1`, `autogen_report_noop: 6`, `ok: 1`, `projected_stats_update: 1`, exit 0.
  - `by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md`: mode file, apply True, scanned 1, `autogen_registry_rebuild: 1`, `autogen_report_noop: 7`, `ok: 1`, `projected_stats_update: 1`, exit 0.
  - `by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md`: mode file, apply True, scanned 1, `autogen_registry_rebuild: 1`, `autogen_report_noop: 7`, `ok: 1`, `projected_stats_update: 1`, exit 0.
  - `by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md`: mode file, apply True, scanned 1, `autogen_registry_rebuild: 1`, `autogen_report_noop: 7`, `ok: 1`, `projected_stats_update: 1`, exit 0.
- Refreshed stats check: `rg` against `project-level/-auto-completion-stats.md` for all five UIDs/names returned no matches, so the targets dropped from the low-score stats output.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: replace the existing five child rows for [UID:0002C1] through [UID:0002C5] under parent [UID:00023B] `0x00526650-0x005270d5.MidiFileReaderAndSMFParserHelpers` with the following exact rows:

```markdown
        - [UID:0002C1][0x00526fa0-0x00526ff6.MidiSourceSeekHelper](by-memory/0x00526fa0-0x00526ff6.MidiSourceSeekHelper.md) 0x00526fa0-0x00526ff6 | raw function-shaped body | MidiSourceSeekHelper : reconstructable : 86% : strong : Seeks DATFile-backed or Win32 file-backed MIDI sources; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, DATFile seek/tell vtable slots +0x18/+0x14, Win32 SetFilePointer argument order, seek-origin mapping to FILE_BEGIN/FILE_CURRENT/FILE_END values, and remaining role-based MIDI document/helper naming blockers.
        - [UID:0002C2][0x00527000-0x00527039.MidiSourceRawReadHelper](by-memory/0x00527000-0x00527039.MidiSourceRawReadHelper.md) 0x00527000-0x00527039 | function | MidiSourceRawReadHelper : reconstructable : 86% : strong : Raw MIDI source read primitive; current IDA confirms exact modeled body, SMF loader caller at 0x0052763b, embedded DATFile Read vtable slot +0x20, out-count behavior, Win32 ReadFile argument order, and remaining role-based MIDI document/helper naming blockers.
        - [UID:0002C3][0x00527040-0x00527078.MidiSourceSizeReadyHelper](by-memory/0x00527040-0x00527078.MidiSourceSizeReadyHelper.md) 0x00527040-0x00527078 | raw function-shaped body | MidiSourceSizeReadyHelper : reconstructable : 86% : strong : Checks DATFile-backed source readiness or caches Win32 file size; current IDA confirms exact raw bytes/padding, no function object or entry xrefs, sub_49C540 DATFile active-entry check, Win32 GetFileSize path, cached-size write, success/failure returns, and remaining role-based MIDI document/helper naming blockers.
        - [UID:0002C4][0x00527080-0x005270b5.MidiReaderConstructorInit](by-memory/0x00527080-0x005270b5.MidiReaderConstructorInit.md) 0x00527080-0x005270b5 | function | MidiReaderConstructorInit : reconstructable : 86% : strong : Initializes MIDI reader/document source state; current IDA confirms exact modeled body, static-initializer caller 0x0041a015, embedded DATFile construction at this+0x18 via sub_49C130, default writes to this+0x14/0x2c/0x34/0x3c, static document state 0x0069b828, paired DATFile tail cleanup at 0x0069b840, and remaining enclosing document-type naming blockers.
        - [UID:0002C5][0x005270c0-0x005270d5.MidiParseSuccessWrapper](by-memory/0x005270c0-0x005270d5.MidiParseSuccessWrapper.md) 0x005270c0-0x005270d5 | function | MidiParseSuccessWrapper : reconstructable : 86% : strong : Boolean wrapper around the SMF document loader; current IDA confirms exact modeled body, stream-open caller 0x0052599d using static document state 0x0069b828, callee sub_5273A0, equality-to-one transform, padding, and unresolved original wrapper/source spelling.
```

## 2026-06-16 A001 Report - A001-goal2-fittingroom-cache-helper-20260616

- Changed docs: `by-memory/0x004229f0-0x00422b25.FittingRoomDialogItemStateLoadEncodedCacheFile.md`, support `by-class/FittingRoomDialogItemState.md`, and this notes file. Validator `--apply` also refreshed generated/tool-owned `project-level/-auto-completion-stats.md` and `tools/validator.ini`.
- Score changes: [UID:0002EG] `FittingRoomDialogItemStateLoadEncodedCacheFile` `82/86 -> 85/88`. [UID:000051] `FittingRoomDialogItemState` stayed `86/88`; only its confirmed-method inventory and cache-helper note changed.
- Evidence searched: read the target, FittingRoomDialogItemState class, FittingRoom file, constructor, raw cache-path builder, catalog transform, encoded state parser, wide dispatch pointer/table docs, save/action route docs, small-string/MSVC string support docs, and local/exported metadata. Repo searches covered `004229f0`, `4229f0`, `sub_4229F0`, `meth_0x4229f0`, `LoadEncodedCacheFile`, `LoadCacheFile`, `BuildCacheFilePath`, `ItemShop.jbn`, `0x0069be14`, and `_wfopen`.
- Resolved or narrowed blockers: exported Ghidra/IDA JSON and hooks-generation records match the modeled `0x135` body and record zero callers/xrefs/data refs; unrefined source/audit output has only synthetic `cls_0x427990::meth_0x4229f0`-style names; wide dispatch docs and `_wfopen` metadata support `0x0069be14` as the `_wfopen` slot; small-string docs identify the decoded-text temporary as the 24-byte SSO-15 byte-string family.
- Remaining blockers with evidence: no direct caller, data xref, literal function-pointer route, vtable/static-table route, exported-metadata route, source-quality helper name, or final source-facing cache/string wrapper declaration was found. The local workspace lacks a raw PE/image dump, so the prior 2026-06-05 live IDA segment-wide literal-pointer scan remains the byte-level pointer-route evidence. Final C++ stays blank.
- Validation: `python .\tools\validator.py --mode file --file by-memory\0x004229f0-0x00422b25.FittingRoomDialogItemStateLoadEncodedCacheFile.md --apply --queue-timeout 240` exited `0` with `ok:1`; after correcting two stale UID links, the final target pass added references to `0000WN`/`0002CZ` and removed the bad `0000ST`/`0000W0` refs. `python .\tools\validator.py --mode file --file by-class\FittingRoomDialogItemState.md --apply --queue-timeout 240` exited `0` with `ok:1`.
- Pending supervisor-owned `by-memory/-coverage-report.md` row: replace the existing [UID:0002EG] row under parent [UID:0000WU] `0x00421a40-0x00422e91.FittingRoomItemShopCatalogState`, between [UID:0002EA] `FittingRoomDialogItemStateBuildCacheFilePathRaw` and [UID:0002E8] `FittingRoomCatalogTransformPersistedBuffer`, with this exact row:

```markdown
            - [UID:0002EG][0x004229f0-0x00422b25.FittingRoomDialogItemStateLoadEncodedCacheFile](by-memory/0x004229f0-0x00422b25.FittingRoomDialogItemStateLoadEncodedCacheFile.md) 0x004229f0-0x00422b25 | helper method | FittingRoomDialogItemStateLoadEncodedCacheFile : reconstructable : 85% : strong : A001 2026-06-16 cache-helper refresh confirms exact modeled `0x135` body, exported Ghidra/IDA metadata with zero callers/xrefs/data refs and only synthetic names, prior live literal-pointer scan/no direct route evidence, `_wfopen` dispatch slot `0x0069be14`/`rb`, SSO-15 temp-string helper family, constructor duplicate cache-load logic, transform/parser handoff, success flag at `+0x24c`, cleanup, and remaining no-route/source-name/final-type blockers.
```

## 2026-06-16 A001 Report - A001-goal2-lowcompletion-stdiofile-aggregate-source-quality-0001IR-20260616-72

- Changed target docs: `by-memory/0x00582070-0x005824f6.StdioFile.md` and this `notes.md`.
- Generated/tool-owned changes from scoped validator: `project-level/-auto-completion-stats.md` and `tools/validator.ini`. `auto-generated/-ag-memory-coverage.md` was checked by validator as `autogen_report_noop`/unchanged for this pass. `by-memory/-coverage-report.md` was not edited directly.
- Score change: [UID:0001IR] `0x00582070-0x005824f6.StdioFile` `82/86 -> 86/89`.
- Owner/emitter decisions: unchanged. The aggregate remains `CANONICAL_OWNER:0000O9` and `EMITTER_UIDS:0000O9` for `by-file/StdioFile.md`; [UID:0000E6] `by-class/StdioFile.md` owns class semantics, vtable/layout contract, and constructor-level class evidence; [UID:0000JD] `by-file/FileIO.md` remains an umbrella file-I/O grouping only; [UID:00004V] `by-class/File.md` remains the abstract base; [UID:0001IZ] `PathExistsViaStat` stays excluded to [UID:0000MI] `by-file/PathUtil.md`.
- Evidence checked: target page, all exact child pages [UID:0001IQ], [UID:0001IS], [UID:0001IT], [UID:0001IU], [UID:0001IV], [UID:0001IW], [UID:0001IX], [UID:0002RH], [UID:0001IY], [UID:0001IZ], [UID:0001J0], non-contiguous [UID:00019F], class/file/FileIO/File/PathUtil support docs, [UID:0003I1] `StdioFileVtable`, [UID:0003H2] `StdioFileLayout`, [UID:0001XK] `FileStreamVtables`, [UID:0001UG] `FileStreamLayouts`, [UID:00026L] mixed StdioFile/StringIter rdata, proposed source-tree `util/File.cpp`/`util/StdioFile.cpp`/`util/PathUtil.cpp`, simroot active and disabled `class_StdioFile.cpp`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/util/StdioFile.cpp`, and the current stale shared coverage row.
- Blocker investigations and resolutions: no split/merge/rename is justified for the exact StdioFile children; non-contiguous `GetSize` remains attached by vtable slot; `PathExistsViaStat` is a utility neighbor because it has broad shared callers and no object/vtable/field use; helper `0x00582380` remains a StdioFile line-read wrapper because it is padding-bounded, has no direct broader utility reachability, and delegates through the `ReadLine` virtual slot; read-only data ownership is limited to the StdioFile vtable/layout support, while StringIter/whitespace/sentinel data in [UID:00026L] are not StdioFile source.
- Generated-output/final-C++ decision: `auto-generated/NexusTK/util/StdioFile.cpp` is zero bytes and generated memory coverage reports `code no` for the aggregate and children. Final C++ stays blank because exact standalone `StdioFile.cpp` versus compact `FileIO.cpp` placement, final `File`/`StdioFile` declarations, private field names, CRT stat-buffer type/name, string helper names around `0x00582380`, duplicate-free source treatment in `ReadRemaining`, and `GetPosition` versus `Tell` source-facing naming are not yet final-source quality.
- IDA DB changes: none. This pass used existing IDA-backed docs/current generated coverage/local source-tree and simroot outputs; no live IDA write, rename, comment, type edit, patch, or save was made.
- Leases used: acquired `by-memory/0x00582070-0x005824f6.StdioFile.md` and `tools/leaser/Agents/Agent-A001/notes.md` under `Agent-A001` before edits; a refresh attempt while active returned `Rejected[Already has lease]`; both leases were reacquired before the final notes update and released after validation/final checks.
- Validation commands/results: from `source-3/project-documentation`, `python tools\validator.py --mode file --file by-memory\0x00582070-0x005824f6.StdioFile.md --apply --queue-timeout 240` exited `0` with `ok:1`, `completion_update 0001IR ... 86`, `confidence_update 0001IR ... 89`, `stats_row_remove` from `Low_Completion`, `Low_Both`, and `by-memory`, `projected_stats_update:1`, `autogen_registry_rebuild:1`, `autogen_cpp_noop 0000O9 ... StdioFile.cpp no assembled code for root`, and `autogen_report_noop` for memory coverage. A notes-path validator check, `python tools\validator.py --mode file --file tools\leaser\Agents\Agent-A001\notes.md --apply --queue-timeout 240`, exited `1` with `file is outside direct by-* folders`; the scoped validator does not validate agent notes.
- Supervisor-applied `by-memory/-coverage-report.md` row: supervisor replaced the existing [UID:0001IR] row in `by-memory/-coverage-report.md`, in the StdioFile cluster between the padding row `0x0058206e-0x00582070 | StartupWindowUpdateCheck to StdioFile alignment` and [UID:0001IQ] `StdioFileConstructor`, with this exact row and validated the shared report plus target page with `ok:1`:

```markdown
    - [UID:0001IR][0x00582070-0x005824f6.StdioFile](by-memory/0x00582070-0x005824f6.StdioFile.md) 0x00582070-0x005824f6 | aggregate | StdioFile : reconstructable : 86% : strong : A001 2026-06-16 source-quality pass confirms this StdioFile source-bearing executable island and aggregate index; reviewed all exact StdioFile children plus non-contiguous GetSize, kept direct file owner/emitter [UID:0000O9][StdioFile](by-file/StdioFile.md) with class semantics under [UID:0000E6][StdioFile](by-class/StdioFile.md), kept [UID:0000JD][FileIO](by-file/FileIO.md) as umbrella only, excluded adjacent [UID:0001IZ][PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) to [UID:0000MI][PathUtil](by-file/PathUtil.md), recorded [UID:0002RH] `0x00582380` as a StdioFile line-read wrapper despite no direct xrefs, bounded StringIter/read-only ownership to the source-local StdioFile vtable/layout support, verified generated `StdioFile.cpp` remains zero bytes/code `no`, made no IDA DB edits, and left final C++ blank pending exact File/StdioFile declarations, member/helper names, stat/string helper types, duplicate-free source treatment, and final standalone `StdioFile.cpp` versus compact `FileIO.cpp` split.
```

- No pending A001 supervisor-owned `by-memory/-coverage-report.md` rows remain for `A001-goal2-lowcompletion-stdiofile-aggregate-source-quality-0001IR-20260616-72`.

## 2026-06-16 A001 Report - A001-goal2-msvc-cashshop-bounded-compiler-raw-refresh-00024L-0002CH-0002CI-20260616-75

- Changed target docs: `by-memory/0x0060d670-0x0060d794.MsvcRdataStartupTables.md`, `by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md`, and `by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md`.
- Changed support docs: `by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md` for the directly adjacent padding count correction. Validator `--apply` also refreshed generated/tool-owned `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`. `by-memory/-coverage-report.md` was not edited.
- Score changes: [UID:00024L] `MsvcRdataStartupTables` `82/87 -> 86/90`; [UID:0002CH] `CashShopRequestConstructorRaw` `82/88 -> 86/90`; [UID:0002CI] `CashShopRequestNonDeletingDestructorRaw` `82/88 -> 86/90`. Support [UID:0000WH] `CashShopRequestRawLifecycle` stayed `86/90`.
- Owner/emitter decisions: [UID:00024L] remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank final C++ because the range is compiler/linker/CRT startup data. [UID:0002CH] and [UID:0002CI] remain direct `CashShopRequest` owner/emitter children under [UID:00001H], with final C++ blank because final class declaration, field names, embedded-string type, and downloader/request source split remain provisional. [UID:0000WH] remains parentless/non-emitting split inventory.
- Evidence checked: live IDA MCP session `701e9f0c` with `NexusTK.exe` and Hex-Rays ready; target/support docs for CashShopRequest, CashShopVersionRequest, FileDownloader, vtables, global `g_pCashShopRequest`, ignored padding, and generated memory coverage; raw bytes/disassembly for `0x0041a5c0-0x0041a670`; decompilation/callees for `0x0041b570`, `0x0041b5e0`, `0x0041b200`, and `0x0041b270`; `.rdata` bytes/function-pointer targets/xrefs for `0x0060d670-0x0060d7a4`; `int_convert.py` for `0x37`, `0x52`, `0x124`, `0x9`, and `0xe`; active generated `CashShopRequest.cpp` and `CashShopVersionRequest.cpp` zero-byte output; and `auto-generated/-ag-memory-coverage.md` status rows.
- Blocker investigations and resolutions:
  - [UID:00024L]: confirmed exact `0x0060d670-0x0060d794` half-open range, `0x124` / 292-byte length, MSVC guard pointer, static-initializer array, CRT pre-C/init and termination entries, TLS/load-config xref at `0x0064033c`, runtime `"string too long"` xref at `0x0041b6d0`, and successor [UID:0003FR] vtable boundary at `0x0060d794`; rejected source owner/emitter, split into source data, or final C++ because the range is compiler/linker/runtime output.
  - [UID:0002CH]: confirmed no IDA function at `0x0041a5d0`, no start xrefs, no VA/RVA pointer hits to the raw start, unique raw-body signature, exact constructor return at `0x0041a606`, nine-byte padding to `0x0041a610`, vtable write at `0x0041a5e8`, and paired vtable evidence through the raw destructor, catalog payload setup, scalar destructor, and [UID:0003FS] vtable page; no split/merge with the previous `nullsub_16` or successor raw destructor is justified.
  - [UID:0002CI]: confirmed no IDA function at `0x0041a610`, no start xrefs, no VA/RVA pointer hits to the raw start, unique raw-body signature, normal return at `0x0041a65c`, invalid-parameter tail through `0x0041a661`, fourteen-byte padding to `FileDownloader_Constructor`, vtable restore at `0x0041a613`, and scalar-destructor pairing; no merge with the scalar deleting wrapper or FileDownloader aggregate is justified.
  - Remaining final-source blockers are specific, not ignored: no reliable source-facing class declaration, no final field names for offsets `+0x04`, `+0x08`, `+0x0c`, `+0x10`, `+0x20`, and `+0x24`, no final embedded string typedef/member name, no original raw constructor/destructor source spelling, and no final decision on compact request/download source placement.
- IDA DB changes: none. The IDA work was read-only; no rename, comment, type edit, function creation, byte patch, or IDB save was made.
- Leases used: target/support docs and this notes file were leased under `Agent-A001` before the documentation edits. The original lease window expired before final notes closeout, so the same target/support docs and notes were reacquired successfully before this final notes write; release is performed after this notes entry is saved.
- Validation commands/results: from `source-3/project-documentation`, the following scoped validators all exited `0` with `ok:1`:
  - `python .\tools\validator.py --mode file --file by-memory\0x0060d670-0x0060d794.MsvcRdataStartupTables.md --apply --queue-timeout 240 --lock-timeout -1`: `completion_update 00024L ... 86`, `confidence_update 00024L ... 90`, removed [UID:00024L] from `Low_Completion`, `Low_Both`, and `by-memory`, and updated generated memory coverage.
  - `python .\tools\validator.py --mode file --file by-memory\0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md --apply --queue-timeout 240 --lock-timeout -1`: `completion_update 0002CH ... 86`, `confidence_update 0002CH ... 90`, removed [UID:0002CH] from `Low_Completion`, `Low_Both`, and `by-memory`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md --apply --queue-timeout 240 --lock-timeout -1`: `completion_update 0002CI ... 86`, `confidence_update 0002CI ... 90`, removed [UID:0002CI] from `Low_Completion`, `Low_Both`, and `by-memory`.
  - `python .\tools\validator.py --mode file --file by-memory\0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md --apply --queue-timeout 240 --lock-timeout -1`: `ok:1`; support file was not present in generated stats lists.
- Refreshed stats check: `rg -n "00024L|0002CH|0002CI|0000WH" project-level/-auto-completion-stats.md` returned no target rows, confirming the three assigned targets dropped from the low-score stats output.
- Pending supervisor-owned `by-memory/-coverage-report.md` rows: replace the existing [UID:0000WH] row and its current nested [UID:0002CH]/[UID:0002CI] rows in the CashShopRequest early cluster, between the padding row `Confirmed 0xcc alignment padding before CashShopRequest item setup` and [UID:0000WI] `0x0041a670-0x0041b69f.FileDownloaderDispatch`, with the following exact rows:

```markdown
    - [UID:0000WH][0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle](by-memory/0x0041a5d0-0x0041a662.CashShopRequestRawLifecycle.md) 0x0041a5d0-0x0041a662 | aggregate | CashShopRequestRawLifecycle : ignored : 86% : very strong : Non-emitting split inventory over the early raw CashShopRequest constructor/destructor bytes; A001 2026-06-16 support refresh keeps `CANONICAL_OWNER:NONE` and `RECONSTRUCTABLE:FALSE`, confirms raw constructor `0x0041a5d0-0x0041a607`, nine-byte `0xcc` padding `0x0041a607-0x0041a610` (Verified with `int_convert.py`), raw non-deleting destructor/invalid-parameter tail `0x0041a610-0x0041a662`, fourteen-byte padding before `FileDownloader_Constructor`, no split/merge change, and exact child pages carry the reconstructable CashShopRequest source route.
        - [UID:0002CH][0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw](by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md) 0x0041a5d0-0x0041a607 | raw-method | CashShopRequestConstructorRaw : reconstructable : 86% : very strong : A001 2026-06-16 raw/source-quality refresh confirms no IDA function object or start xrefs at `0x0041a5d0`, exact `0x37` / 55-byte body (Verified with `int_convert.py`) through `0x0041a606`, nine-byte padding before the sibling destructor, unique raw-body signature, no VA/RVA pointer hits to the raw start, vtable write at `0x0041a5e8`, paired destructor/scalar-destructor/vtable child evidence, owner/emitter [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), zero-byte generated `CashShopRequest.cpp`, no IDA DB edits, and blank final C++ pending final class declaration, field names, embedded-string type, and downloader/request source split.
        - [UID:0002CI][0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw](by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md) 0x0041a610-0x0041a662 | raw-method | CashShopRequestNonDeletingDestructorRaw : reconstructable : 86% : very strong : A001 2026-06-16 raw/source-quality refresh confirms no IDA function object or start xrefs at `0x0041a610`, exact raw destructor body with normal return at `0x0041a65c` and invalid-parameter tail through `0x0041a661`, fourteen-byte padding before `FileDownloader_Constructor`, unique raw-body signature, no VA/RVA pointer hits to the raw start, vtable restore at `0x0041a613`, scalar destructor pairing, owner/emitter [UID:00001H][CashShopRequest](by-class/CashShopRequest.md), zero-byte generated `CashShopRequest.cpp`, no IDA DB edits, and blank final C++ pending final class declaration, field names, embedded-string type, and downloader/request source split.
```

- Pending supervisor-owned `by-memory/-coverage-report.md` delete/move note: delete this stale nested [UID:0002CM] row from under [UID:0000WH]; [UID:0002CM] is physically inventoried under [UID:0000WI] and already documents that physical inventory relationship, so it should not remain nested under the narrowed raw-lifecycle parent:

```markdown
        - [UID:0002CM][0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor](by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md) 0x0041b570-0x0041b5db | method | CashShopRequestScalarDeletingDestructor : reconstructable : 84% : strong : Modeled vtable-only scalar deleting destructor for `CashShopRequest`; IDA MCP confirms function `sub_41B570`, data xref from `0x0060d7a0`, no direct code callers, callees `sub_5C7526` and `__invalid_parameter_noinfo_noreturn`, and autogen attachment to CashShopRequest.
```

- Pending supervisor-owned `by-memory/-coverage-report.md` rows: in the `.rdata` cluster under [UID:0001Z7] `0x0060d670-0x0066d000.ReadOnlyDataSection`, replace the existing [UID:00024L] row between [UID:0001Z7] and [UID:00024M] with this exact row:

```markdown
    - [UID:00024L][0x0060d670-0x0060d794.MsvcRdataStartupTables](by-memory/0x0060d670-0x0060d794.MsvcRdataStartupTables.md) 0x0060d670-0x0060d794 | compiler/linker | MsvcRdataStartupTables : ignored : 86% : very strong : A001 2026-06-16 compiler/raw refresh confirms exact `0x124` / 292-byte (Verified with `int_convert.py`) MSVC `.rdata` startup-table prelude, guard pointer, static-initializer function-pointer array, CRT pre-C/initializer entries, TLS callback/load-config ref at `0x0064033c`, CRT termination entries, `"string too long"` runtime literal xref at `0x0041b6d0`, no function/source owner, successor [UID:0003FR] vtable boundary at `0x0060d794`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitters, no IDA DB edits, and blank final C++ because compiler/linker/CRT should regenerate the bytes.
```

- Pending supervisor-owned adjacent stale row observed: [UID:00024M] was not edited for this assignment, but the current shared report row still starts at `0x0060d798` while the current file and [UID:00024L] boundary prove it starts at `0x0060d794`. If the supervisor refreshes the adjacent row while applying [UID:00024L], replace the existing [UID:00024M] row immediately after [UID:00024L] with this exact row:

```markdown
    - [UID:00024M][0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData](by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md) 0x0060d794-0x0060e174 | vtable/string-data | CashShopFittingRoomReadOnlyData : ignored : 89% : very strong : Mixed non-emitting read-only-data index spanning CashShopVersionRequest/CashShopRequest/FileDownloader vtables, downloader/itemshop literals, and FittingRoom vtables/resources; exact children carry source ownership, A003/A001 evidence moves the first RTTI pointer to `0x0060d794`, and no single direct source owner or emitter covers the aggregate.
```
