# Agent A005 Notes

## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A005\current_leases.md`; do not edit it.

## Pending Follow-Ups

- Batch 133 split follow-up: repair the `MapTileImageLib` exact vtable memory split when deliberately assigned. Re-range `by-memory/0x0061b344-0x0061b664.HourIconsIdleReadOnlyData.md` to end at `0x0061b660`, re-range `by-memory/0x0061b664-0x0061c360.ImageLibraryReadOnlyData.md` to start at `0x0061b660`, create exact child `by-memory/0x0061b660-0x0061b670.MapTileImageLibVtableData.md`, assign it to [UID:00007T] if the child reaches `85/85`, and update report/UID references through validator. Evidence already recorded in [UID:0001Y3]: `0x0061b660 -> ??_R4MapTileImageLib@@6B@`, vtable slots at `0x0061b664/0x0061b668/0x0061b66c`, and successor `0x0061b670 -> ??_R4?$ProtectedArray@UHeadInfo@@@@6B@`.
- Re-run live IDA MCP for `FriendListDialog::OnOkButton` when responsive to settle the `0x0053f920` vs `0x0053f921` endpoint discrepancy. A005 retry on 2026-06-06 timed out three times.
- Re-run live IDA MCP for `by-memory/0x005adc20-0x005adcb3.GroupMemberMarkers.md` when responsive. A005 retry on 2026-06-07 failed three connection attempts; needed checks are `lookup_funcs`/`disasm`/`decompile`/`callers`/`callees` for `0x005adc20` and `0x005adc70`, especially the `dword_67A748 + 0x3cb0`, `+0x218`, stride `0x12c`, and `0x005adc63-0x005adc70` padding questions.
- Resolved-name cleanup broad follow-up: remaining by-memory rows for `g_pEPFLib`, `g_pCollectionData`, `g_pApplicationCleanupQueue`, `g_pBackPane`, `ImageLibraryLoadErrorFlag`, and `crc_table` still need target review plus matching by-memory coverage/update workflow. These are not simple exact report-row replacements.

## 2026-06-11 Supervisor Cleanup

- Applied the valid pending exact report rows from A005 Batches 001, 011, 012, 013, 019, 059, 071, 079, 095, and 110.
- Confirmed stale/superseded and left intact: `g_movementSubstepScale`, `g_screenHeight`, `ScreenFadeOut`, `BackPaneAndBackGroundPane`, `BrowserWindowDocHostUiHandlerStubs`, `RegionVtableData`, and rows already improved by newer B001/A-agent work.

## 2026-06-11 Agent-A005 Batch 152

- Targets completed:
  - [UID:0001V8] `by-type/by-struct/MiniMapVersionNode.md`: `76/88` -> `85/90`; `AUTOGEN_PARENT_UID` blank -> `00008H`; no final C++ emitted.
  - [UID:0001Y8] `by-type/by-vtable/MyItemListPaneVtables.md`: `86/90` -> `87/91`; `AUTOGEN_PARENT_UID` blank -> `00008W`; no final C++ emitted.
- Direct parents improved to clear the strict gate:
  - [UID:00008H] `by-class/MiniMapVersionManager.md`: `84/86` -> `85/87`.
  - [UID:00008W] `by-class/MyItemListPane.md`: `82/82` -> `85/86`.
- Evidence used:
  - Live IDA MCP `py_eval` on 2026-06-11 rechecked MiniMapVersionManager node update/allocation/lookup/destructor instructions, `CreateListNodeWithPayload` `+0x08/+0x0c` payload writes, `DATIndexVectorFindNodeByKey` caller spread, MyItemListPane constructor vptr stores, MyItemListPane RTTI/vtable bases, table slot counts, neighboring vtable boundaries, and the sole `DrawListEntry` data xref at `0x00619fa8`.
  - `int_convert.py` verified `0x21 == 33`, `0x42 == 66`, `0x80 == 128`, `0xa0 == 160`, and `0xa4 == 164`.
- Changed files:
  - `by-type/by-struct/MiniMapVersionNode.md`
  - `by-class/MiniMapVersionManager.md`
  - `by-class/MyItemListPane.md`
  - `by-type/by-vtable/MyItemListPaneVtables.md`
  - `by-type/by-vtable/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - Validator also reported generated updates/noops for `project-level/-auto-completion-stats.md` and `auto-generated/-ag-type-coverage.md`, with validator backup folders created under `tools/validator_autogen_backup/`.
- Leases used:
  - Leased and edited `MiniMapVersionNode.md`, `MiniMapVersionManager.md`, `MyItemListPane.md`, `MyItemListPaneVtables.md`, `by-type/by-vtable/-coverage-report.md`, `by-type/by-struct/-coverage-report.md`, `by-class/-coverage-report.md`, and this `notes.md`.
  - Initial leases for `by-type/by-struct/-coverage-report.md` and `by-class/-coverage-report.md` were rejected due to active leases; retried after expiration and applied the rows directly. No pending coverage rows remain for these two reports.
- Validation commands/results:
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-struct\MiniMapVersionNode.md --apply`: OK; completion/confidence updated; autogen parent updated to `00008H`; stats rescore recommended due stats row removal.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\MiniMapVersionManager.md --apply`: OK; completion/confidence updated.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\MyItemListPane.md --apply`: OK; completion/confidence updated; generated `-ag-type-coverage.md` refreshed.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-vtable\MyItemListPaneVtables.md --apply`: OK; completion/confidence updated; autogen parent updated to `00008W`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-vtable\-coverage-report.md --apply`: OK.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-struct\-coverage-report.md --apply`: OK; generated `-ag-type-coverage.md` refreshed.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\-coverage-report.md --apply`: OK.
- Blockers:
  - No documentation blocker remains for the two Batch 152 targets.
  - `git status` could not be used because neither `E:\NTK\GhidraBridge` nor `E:\NTK\GhidraBridge\source-3` is a Git repository in this environment.
- Pending `by-memory/-coverage-report.md` rows:
  - None. This run did not edit by-memory docs and the supervisor-banned by-memory coverage report was not modified.

## 2026-06-11 Agent-A005 Batch 164

- Targets completed:
  - [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`: `82/88` -> `85/89`; `AUTOGEN_PARENT_UID` remains blank. Reason: live IDA proved the broad physical span contains the exact ProfileStorage child [UID:0001AV], so by-structure blocks direct MapPane attachment even though MapPane parents now clear scores.
  - [UID:0001AV] `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`: `83/88` -> `86/90`; `AUTOGEN_PARENT_UID` blank -> `0000MS`.
- Direct related docs:
  - [UID:0000MS] `by-file/ProfileStorage.md`: `86/80` -> `87/85`, enough for the strict direct-parent gate.
  - [UID:0000VN] `by-memory/-ignored.md`: added padding evidence for `0x0050ab95-0x0050aba0` and `0x0050b078-0x0050b080`.
  - `by-file/-coverage-report.md`: updated the `ProfileStorage` row to `87%`.
- Evidence used:
  - Live IDA MCP `py_eval` on 2026-06-11 reconfirmed `sub_50AB70` ending at `0x0050ab95`, eleven `0xcc` bytes before `sub_50ABA0`, `SaveUserSettings` at `0x0050aba0-0x0050b078`, eight `0xcc` bytes before `sub_50B080`, and the MapPane modeled-function inventory through `0x0050e320`.
  - Live IDA MCP reconfirmed the ProfileStorage helper set: `0x004f9280-0x004f95a2`, `0x004f95b0-0x004f9d28`, `0x005063e0-0x00506962`, and `0x0050aba0-0x0050b078`.
  - `SaveUserSettings` xrefs: `0x00504850`, raw/no-function `0x0053dd8c`, `0x0053dfb8`, `0x0053ed6e`, `0x0053f15c`, `0x0053f8f8`, `0x005420a7`, `0x0054252a`.
  - `SaveUserSettings` decompilation evidence includes `SHGetFolderPathW`, `%s\\NexusTK`, `%s\\NexusTK\\users`, `%s/%s.usr`, repeated `_fwrite`/`_fputwc`, `_fclose`, and macro type writes `T`/`S`/`I`.
  - `int_convert.py` verified `0x4d8 == 1240`, `0x108 == 264`, `0x1e == 30`, `0x28f2f0 == 2683632`, and `0x28f2f4 == 2683636`.
- Changed files:
  - `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
  - `by-memory/0x0050aba0-0x0050b078.SaveUserSettings.md`
  - `by-memory/-ignored.md`
  - `by-file/ProfileStorage.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased and edited the two target by-memory docs, `by-memory/-ignored.md`, `by-file/ProfileStorage.md`, `by-file/-coverage-report.md`, and this `notes.md`.
  - `by-memory/-coverage-report.md` was not leased or edited because the supervisor ban remains active.
- Validation commands/results:
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\ProfileStorage.md --apply`: OK; completion/confidence updated to `87/85`; generated reports no-op except projected stats.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x0050aba0-0x0050b078.SaveUserSettings.md --apply`: OK; completion/confidence updated to `86/90`; parent updated to `0000MS`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md --apply`: OK; completion/confidence updated to `85/89`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\-ignored.md --apply`: OK; existing unrelated missing ref warnings for deleted/stale `by-memory/0x00500640-0x00502754.SpecializedButtonPanes.md`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\-coverage-report.md --apply`: OK.
- Blockers:
  - The broad MapPane aggregate is still pending supervisor continuation because exact MapPane child pages are needed before attachment or C++ emission.
  - `git status` could not be used because `E:\NTK\GhidraBridge` is not a Git repository in this environment.
- Pending `by-memory/-coverage-report.md` rows:
  - None. Batch 164 rows for `0001AT`, `0001AV`, and adjacent padding were applied and validated by the supervisor on 2026-06-11. If continuation work changes the MapPane split, record fresh exact replacement rows here.

## 2026-06-11 Agent-A005 Batch 164 Continuation

- Target completed:
  - [UID:0001AT] `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`: `85/89`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank. The page is now a reviewed non-emitting mixed-owner container, not a source-emitting MapPane item.
- Exact child pages created and attached to [UID:00007Q] `MapPane`:
  - [UID:00037Q] `0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`: new `85/88`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037R] `0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md`: new `85/88`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037S] `0x00507150-0x00507c90.MapPaneMouseEventCore.md`: new `85/89`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037T] `0x00507c90-0x00508f60.MapPanePacketDispatcher.md`: new `86/89`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037U] `0x00508f60-0x00509470.MapPaneNotifyTimerCore.md`: new `85/87`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037V] `0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`: new `85/88`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037W] `0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`: new `86/90`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037X] `0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`: new `85/89`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
  - [UID:00037Y] `0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`: new `86/88`, `RECONSTRUCTABLE:TRUE`, parent `00007Q`.
- Existing child repaired to clear the same gate:
  - [UID:0001AU] `0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md`: `74/84`, parent `0000L3` -> `85/88`, parent `00007Q`; live IDA reconfirmed exact range, padding fences, external callees `0x004b7e80` and `0x0050c470`, and four target-selection callers.
- Evidence used:
  - Live IDA MCP `py_eval` on 2026-06-11 confirmed modeled starts and caller/callee families across the MapPane object lookup, resize/command, mouse, packet, notify/timer, render, paint/lighting, interaction/map-change, and tile/object-grid child ranges.
  - Live IDA MCP raw-byte checks confirmed `0x0050a4fd-0x0050a500` is three `0xcc` bytes and `0x0050bcd8-0x0050bce0` is eight `0xcc` bytes.
  - Live IDA MCP rechecked [UID:0001AU] as `0x00506ce0-0x00506d15`, with three `0xcc` bytes before it and eleven after it.
- Changed files:
  - `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`
  - `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
  - `by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md`
  - `by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md`
  - `by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md`
  - `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
  - `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md`
  - `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
  - `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`
  - `by-memory/0x0050b080-0x0050bcd8.MapPaneInteractionMapChangeCore.md`
  - `by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased and edited the parent `0001AT`, nine new child pages, existing child `0001AU`, and this `notes.md`.
  - Attempted to lease `by-memory/-ignored.md`; rejected because A001 currently owned the lease. The supervisor later applied the exact ignored-row insertions.
  - Did not lease or edit banned `by-memory/-coverage-report.md`.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\<new-child>.md --apply` immediately after each new file creation: OK for all nine files; validator assigned UIDs `00037Q` through `00037Y`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\<new-child>.md --apply` after metadata updates: OK for all nine files; completion/confidence and autogen parent `00007Q` accepted.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md --apply`: OK; parent container validated at `88/90`, `RECONSTRUCTABLE:FALSE`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md --apply`: OK; completion/confidence updated to `85/88`; autogen parent updated `0000L3 -> 00007Q`.
- Blockers:
  - No Batch 164 continuation shared rows remain pending; the supervisor applied the ignored-row padding cleanup and banned `by-memory/-coverage-report.md` replacement block on 2026-06-11.
  - `git status` could not be used because `E:\NTK\GhidraBridge` is not a Git repository in this environment.

### Supervisor-Applied Shared Rows

- `by-memory/-ignored.md`: padding entries for `0x0050a4fd-0x0050a500` and `0x0050bcd8-0x0050bce0` were applied and validated by the supervisor on 2026-06-11.
- `by-memory/-coverage-report.md`: the Batch 164 continuation replacement block for [UID:0001AT], [UID:0001AU], [UID:0001AV], [UID:00037Q]-[UID:00037Y], and exposed padding rows was applied and validated by the supervisor on 2026-06-11.

## 2026-06-11 Agent-A005 Batch 174

- Targets completed:
  - [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`: `85/90` -> `86/91`; parent remains [UID:0000NY] `SpecializedButtonPanes`.
  - [UID:0001XR] `by-type/by-vtable/ImageLibVtable.md`: `86/91` -> `87/92`; parent remains [UID:00006E] `ImageLib`.
  - [UID:0001SP] `by-type/by-enum/MiscWorkThreadMessageId.md`: `74/88`, parent blank -> `86/90`, parent [UID:00008I] `MiscWorkThread`.
- Direct related document repaired for the strict gate:
  - [UID:00008I] `by-class/MiscWorkThread.md`: `84/82` -> `85/85`; parent remains [UID:0000LG] `MiscWorkThread`, which is already `86/85`.
- Evidence used:
  - Live IDA MCP `py_eval` on 2026-06-11 rechecked `GenderButtonControlPane`, `DirectionButtonControlPane`, and `CheckBoxTextControlPane` RTTI/vtable dwords, primary/secondary/tertiary table heads, slot target ranges, and store/reset xrefs.
  - Live IDA MCP rechecked `ImageLib` vtable dwords at `0x0061b650-0x0061b660`, target function ranges, vptr-store/reset xrefs from constructor/destructor/scalar-delete paths, and adjacent `MapTileImageLib` / `ProtectedArray<HeadInfo>` boundaries.
  - Live IDA MCP decompiled `MiscWorkThread::ProcessWorkItem` at `0x00527fe0`, `RequestHTTPGet` at `0x00528290`, and `RequestNCAUpdate` at `0x00528310`; disassembly of raw/no-function `0x005283b0-0x005283d5` confirmed `__strdup`, `push 42446972h`, and `Thread` queue helper `0x00596960`.
  - `int_convert.py` verified `0x42446972 == 1111779698`, `0x47654874 == 1197820020`, `0x4e434175 == 1313030517`, `0x68747470 == 1752462448`, and `0x4e634175 == 1315127669`.
- Changed files:
  - `by-type/by-vtable/SpecializedButtonPaneVtables.md`
  - `by-type/by-vtable/ImageLibVtable.md`
  - `by-type/by-enum/MiscWorkThreadMessageId.md`
  - `by-class/MiscWorkThread.md`
  - `by-type/by-enum/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased and edited the three assigned type docs, `by-class/MiscWorkThread.md`, `by-type/by-enum/-coverage-report.md`, `by-class/-coverage-report.md`, and this `notes.md`.
  - Attempted to lease `by-type/by-vtable/-coverage-report.md`; rejected due to active A003 lease, retried after a short wait, and it was still locked. Exact pending replacement rows are recorded below.
  - Did not edit banned `by-memory/-coverage-report.md`; no by-memory docs changed in this batch, so no pending by-memory coverage rows are required.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-type\by-enum\MiscWorkThreadMessageId.md --apply`: OK; completion/confidence updated to `86/90`; autogen parent updated blank -> `00008I`; generated reports refreshed/no-op as applicable.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-class\MiscWorkThread.md --apply`: OK; completion/confidence updated to `85/85`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-type\by-vtable\SpecializedButtonPaneVtables.md --apply`: OK; completion/confidence updated to `86/91`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-type\by-vtable\ImageLibVtable.md --apply`: OK; completion/confidence updated to `87/92`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-type\by-enum\-coverage-report.md --apply`: OK.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-class\-coverage-report.md --apply`: OK.
- Blockers:
  - `by-type/by-vtable/-coverage-report.md` remained leased by A003 through the retry window; the supervisor later applied and validated the exact replacement rows.
  - `git status` could not be used because `E:\NTK\GhidraBridge` is not a Git repository in this environment.

### Supervisor-Applied `by-type/by-vtable/-coverage-report.md` Rows

- The supervisor applied and validated the Batch 174 replacement rows for [UID:0001XR] and [UID:0001YW] on 2026-06-11. No pending `by-type/by-vtable/-coverage-report.md` rows remain for this batch.

## 2026-06-11 Agent-A005 Batch 177

- Targets completed:
  - [UID:0002YH] `by-memory/0x004bedb0-0x004bedde.SoftwareRenderCompatRgb555PackCallback.md`: `86/90` -> `88/91`; parent remains [UID:0000OC] `Surface`.
  - [UID:0002YI] `by-memory/0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md`: `86/90` -> `88/91`; parent remains [UID:0000OC] `Surface`.
  - [UID:0002YJ] `by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md`: `85/88` -> `87/90`; parent remains [UID:0000OC] `Surface`.
- Direct parent gate:
  - [UID:0000OC] `by-file/Surface.md` was already `88/85`, so the strict child plus direct-parent `85/85` gate remains satisfied for all three targets.
  - [UID:0000NT] `by-file/SoftwareBlend16.md` remains rejected as direct parent because these exact targets are callback-table implementations selected through Surface dispatch, while SoftwareBlend16 is scoped to stateless blend/math helpers.
- Evidence used:
  - Live IDA MCP `py_eval` on 2026-06-11 reconfirmed exact target ranges, target-address refs, slot refs, basic block counts, callee sets, and boundary bytes for all three functions.
  - `0x004bedb0`: `sub_4BEDB0`, `0x2e` / 46 bytes, one basic block, no code callers, no external code targets, target refs `0x00558705` and `0x00558be4`, slot `dword_69B404`, and decompiled RGB555 pack expression.
  - `0x004bede0`: `sub_4BEDE0`, `0x55` / 85 bytes, one basic block, no code callers, no external code targets, target refs `0x0055871e` and `0x00558bd0`, direct data refs to `dword_69B3DC` and `dword_69B3D8`, slot `dword_69B408`, and decompiled RGB555 lookup/repack expression.
  - `0x004bee40`: `sub_4BEE40`, `0x185e` / 6238 bytes, 219 basic blocks, no code callers, target refs `0x005586f9` and `0x00558bee`, slot `dword_69B40C`, mode clamp to `0..24`, `a2 >> 1` in-place RGB555 word loop, RGB555 constant refs through `0x0061a950-0x0061a9e0`, and corrected `case 24` CRT `memset(a1, 0, 2 * a2)` callee at `_memset` `0x005ca0b0`.
  - Live IDA raw-byte check confirmed `0x004bedaa-0x004bedb0` is six `0xcc` bytes, `0x004bedde-0x004bede0` is two `0xcc` bytes, `0x004bee35-0x004bee40` is eleven `0xcc` bytes, `0x004c069e-0x004c06a0` is `66 90`, `0x004c06a0-0x004c0704` is the final jump table, and `0x004c0704-0x004c0710` is twelve `0xcc` bytes.
  - `int_convert.py` verified `0x2e == 46`, `0x55 == 85`, `0x185e == 6238`, `0x18 == 24`, `0x19 == 25`, `0x64 == 100`, `0x6 == 6`, `0x2 == 2`, `0xb == 11`, and `0xc == 12`.
- Changed files:
  - `by-memory/0x004bedb0-0x004bedde.SoftwareRenderCompatRgb555PackCallback.md`
  - `by-memory/0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md`
  - `by-memory/0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased and edited the three assigned target by-memory docs and this `notes.md`.
  - The initial target leases expired after edits during validation; no further target edits were made after expiration.
  - Took a fresh lease on this `notes.md` before writing the final Batch 177 report.
  - Did not lease or edit banned `by-memory/-coverage-report.md`.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004bedb0-0x004bedde.SoftwareRenderCompatRgb555PackCallback.md --apply`: OK; completion/confidence updated to `88/91`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004bede0-0x004bee35.SoftwareRenderCompatRgb555PaletteTransformCallback.md --apply`: OK; completion/confidence updated to `88/91`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004bee40-0x004c069e.SoftwareRenderCompatBlockTransferCallback.md --apply`: OK; completion/confidence updated to `87/90`; validator added the UID reference index for [UID:00016K].
- Blockers:
  - No Batch 177 target documentation blocker remains. Final C++ emission is still intentionally blank because none of the three targets reaches the `95/95` final-source gate.
  - `git status --short` could not be used because `E:\NTK\GhidraBridge\source-3` is not a Git repository in this environment.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows

- The supervisor applied and validated the Batch 177 replacement rows for [UID:0002YH], [UID:0002YI], [UID:0002YJ], the corrected two-byte alignment row at `0x004c069e-0x004c06a0`, and the final jump-table row at `0x004c06a0-0x004c0704` on 2026-06-11. No pending `by-memory/-coverage-report.md` rows remain for this batch.

## 2026-06-11 Agent-A005 Batch 182

- Targets completed:
  - [UID:0002TF] `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md`: `85/86` -> `87/89`; parent remains [UID:0000OC] `Surface`; final C++ remains blank because the item is below the `95/95` source-emission gate.
  - [UID:0002TG] `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`: `85/86` -> `87/90`; parent remains [UID:0000OC] `Surface`; final C++ remains blank because the callback typedef/RLE layout is not final-source quality.
  - [UID:0002TH] `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`: `85/86` -> `87/90`; parent remains [UID:0000OC] `Surface`; final C++ remains blank because the source-level helper names and parameter roles remain provisional.
- Direct parent gate:
  - [UID:0000OC] `by-file/Surface.md` was already `88/85`, so the strict child plus direct-parent `85/85` gate remains satisfied for all three targets.
  - No by-structure split was required for the three exact function pages. Adjacent non-function islands remain represented as ignored switch-data/padding rows; `SaveUserSettings` remains excluded from MapPane ownership from the prior batch.
- Evidence used:
  - Live IDA MCP `py_eval` / decompile evidence from 2026-06-11 reconfirmed exact ranges, target refs, slot refs, direct-caller absence, CFG sizes, callee sets, data refs, and boundary bytes for all three RGB565 callbacks.
  - `0x004c3190`: `sub_4C3190`, `0x8b0` / 2224 bytes (Verified with int_convert.py), zero direct callers, target refs `0x00558816` and `0x00558eba`, eleven `dword_69B3EC` slot refs, 88 blocks / 653 instructions, clip/rectangle/palette/security-cookie callees, `switch(a6)` modes `0..3`, RLE zero-token termination, `memset32` fill path, RGB565 SIMD constants, and local switch table `0x004c3a40-0x004c3a50`.
  - `0x004c3a50`: `sub_4C3A50`, `0x291` / 657 bytes (Verified with int_convert.py), zero direct callers, target refs `0x00558829` and `0x00558ec4`, twenty-one `dword_69B3F0` slot refs, 25 blocks / 212 instructions, one product callee `0x004b96c0`, `a5 == 3` mode gate, `0x7F` token mask, zero-terminated row scan, RGB565 lookup refs, tint constants, and 15-byte `0xcc` padding after the function (Verified with int_convert.py).
  - `0x004c3cf0`: `sub_4C3CF0`, `0x1a3` / 419 bytes (Verified with int_convert.py), zero direct callers, target refs `0x005587ec` and `0x00558ece`, four `dword_69B3F4` slot refs, 9 blocks / 150 instructions, clip/setup/bulk/security-cookie callees, draw guard, RGB565 lookup scalar tail, and 13-byte `0xcc` padding after the function (Verified with int_convert.py).
  - `int_convert.py` verified `0x8b0 == 2224`, `0x291 == 657`, `0x1a3 == 419`, `0x10 == 16`, `0xf == 15`, and `0xd == 13`.
- Changed files:
  - `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md`
  - `by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md`
  - `by-memory/0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased the three assigned target by-memory docs and this `notes.md` as A005 before edits. A renewal attempt was rejected with `Already has lease` while A005 still held them, so edits proceeded under the existing A005 leases.
  - The original target leases expired during validation; no target pages were edited after expiration. Took a fresh A005 lease on this `notes.md` before writing this final Batch 182 report.
  - Did not lease or edit banned `by-memory/-coverage-report.md`.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md --apply`: OK; completion/confidence updated to `87/89`; autogen registry rebuilt; generated C++ unchanged/no-op.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md --apply`: OK; completion/confidence updated to `87/90`; autogen registry rebuilt; generated C++ unchanged/no-op.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x004c3cf0-0x004c3e93.SoftwareRenderRgb565AlphaLookupBlitCallback.md --apply`: OK; completion/confidence updated to `87/90`; autogen registry rebuilt; generated C++ unchanged/no-op.
- Blockers:
  - No Batch 182 target documentation blocker remains. These are improved exact function pages, not C++ emission candidates yet.
  - No pending supervisor coverage rows remain for Batch 182.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows

- The Batch 182 rows for `0002TF`, `0002TG`, `0002TH`, and their adjacent ignored switch-data/padding rows were merged into the RGB565 callback block and validated by the supervisor on 2026-06-11.

## 2026-06-11 Agent-A005 Batch 189

- Targets completed:
  - [UID:0001HW] `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`: `84/87` -> `86/88`; parent blank -> [UID:0001HT].
  - [UID:0001HX] `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md`: `84/88` -> `86/89`; parent blank -> [UID:0001HT].
  - [UID:0001HY] `by-memory/0x00575370-0x00575377.GetConnectionStatus.md`: `85/88` -> `86/89`; parent blank -> [UID:0001HT].
- Direct parent repaired for the strict gate:
  - [UID:0001HT] `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`: `84/86` -> `85/87`; it is now only the direct containing send/status aggregate for the three exact children. It remains unassigned above itself because the higher `CashShopRequest` class/file context is still `82/86` and the request-sender/socket/thread split is unresolved.
- Evidence used:
  - Live IDA MCP `py_eval` / `decompile` on 2026-06-11 reconfirmed `sub_574D40` as `0x00574d40-0x00574e44`, `sub_574E50` as `0x00574e50-0x0057536b`, `sub_575370` as `0x00575370-0x00575377`, raw `0x00574d00-0x00574d40` still not being an IDA-modeled function, and `sub_575380` starting at `0x00575380`.
  - Current xrefs remain: `SendPositionUpdate` callers `0x005542a9` / `sub_554210` and `0x0058b42f` / `sub_58B130`; `BuildAndSendFriendNameListSync` refs `0x00508b14` / `sub_507C90`, raw island `0x005143ad`, and `0x0053f8ed` / `sub_53F830`; `GetConnectionStatus` refs `0x005080b1` / `sub_507C90`, `0x0051147e` / `sub_511440`, and raw island `0x00511a3c`.
  - Live byte checks reconfirmed twelve `0xcc` bytes after `SendPositionUpdate`, five `0xcc` bytes after `BuildAndSendFriendNameListSync`, and getter bytes `8a 81 4f aa 03 00 c3` followed by nine `0xcc` bytes through `0x00575380`.
  - `int_convert.py` verified `0x104 == 260`, `0x51b == 1307`, `0x7 == 7`, `0x0c == 12`, `0x77 == 119`, `0x1fff == 8191`, `0x3aa4e == 240206`, `0x3aa4f == 240207`, `0x2911e0 == 2691552`, `0x291230 == 2691632`, and `0x2918f8 == 2693368`.
- Changed files:
  - `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md`
  - `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`
  - `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md`
  - `by-memory/0x00575370-0x00575377.GetConnectionStatus.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased the four by-memory docs and this `notes.md` as Agent-A005 before editing.
  - The initial leases expired before validation; took fresh leases on the same five files before running validator.
  - Did not lease or edit banned `by-memory/-coverage-report.md`.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00574b90-0x00575377.CashShopRequestSendQueue.md --apply`: OK; completion/confidence updated to `85/87`; autogen registry rebuilt; generated C++ unchanged/no-op.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00574d40-0x00574e44.SendPositionUpdate.md --apply`: OK; completion/confidence updated to `86/88`; autogen parent updated to `0001HT`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md --apply`: OK; completion/confidence updated to `86/89`; autogen parent updated to `0001HT`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00575370-0x00575377.GetConnectionStatus.md --apply`: OK; completion/confidence updated to `86/89`; autogen parent updated to `0001HT`.
- Blockers:
  - No Batch 189 target documentation blocker remains. Final C++ remains blank because the request-sender source owner, field names, and helper/local names are below the `95/95` source-emission gate.
  - `by-memory/-coverage-report.md` was not edited due supervisor override. Exact pending replacement rows are below.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows

- The supervisor applied and validated the Batch 189 rows for [UID:0001HT], [UID:0001HW], [UID:0001HX], and [UID:0001HY] on 2026-06-11.
- No Batch189 `by-memory/-coverage-report.md` rows remain pending. [UID:0001HT] remains a possible later B001 ownership/split research candidate because its higher source owner is still unresolved.

## 2026-06-11 Agent-A005 Batch 192

- Targets completed:
  - [UID:0002KX] `by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md`: `84/89`, parent blank -> `86/90`, parent [UID:0001KA].
  - [UID:0002KY] `by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md`: `86/91`, parent blank -> `87/92`, parent [UID:0001KA].
  - [UID:0002KZ] `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`: `88/92`, parent blank -> `89/93`, parent [UID:0001KA].
- Direct parent repairs:
  - [UID:0001KA] `by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`: `82/86` -> `85/87`; stale inclusive-looking function-map ends corrected.
  - [UID:0001K6] `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`: `84/86` -> `85/87`; stale child table ends corrected.
- Evidence used:
  - Live IDA MCP on 2026-06-11 reconfirmed `sub_597DC0`, `sub_597E40`, and `sub_597E90` starts/sizes, decompilation, disassembly, callers/callees, code refs, and padding bytes.
  - IDB metadata: `NexusTK.exe`, `md5 4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `0x00597dc0`: size `0x7f` / 127 bytes, 61 instructions, caller `0x0050ebf1`, no callees, one `0xcc` byte at `0x00597e3f`.
  - `0x00597e40`: size `0x4a` / 74 bytes, 25 instructions, caller `0x004a6c5e`, callees `timeGetDevCaps`, `timeBeginPeriod`, and `timeGetTime`, writes TimerMgr `+0x1c`, `+0x18`, `dword_69BE10`, and `dword_69BE0C`, six `0xcc` bytes at `0x00597e8a-0x00597e90`.
  - `0x00597e90`: size `0x13` / 19 bytes, seven instructions, callers `0x004a6c86` and `0x004f63c0`, sole callee `timeGetTime`, writes TimerMgr `+0x18` and `dword_69BE10`, thirteen `0xcc` bytes at `0x00597ea3-0x00597eb0`.
  - `int_convert.py` verified `0x7f == 127`, `0x4a == 74`, `0x13 == 19`, `0x1c == 28`, `0x18 == 24`, `0x8 == 8`, `0xd == 13`, `0x6 == 6`, and `0x1 == 1`.
- Changed files:
  - `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
  - `by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md`
  - `by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md`
  - `by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md`
  - `by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased the five edited by-memory docs and this `notes.md` as Agent-A005 before editing.
  - Did not lease or edit banned `by-memory/-coverage-report.md`.
- Validation commands/results:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md --apply`: OK; completion/confidence updated to `85/87`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00597dc0-0x005986da.TimerMgrQueueHelpers.md --apply`: OK; completion/confidence updated to `85/87`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md --apply`: OK; completion/confidence updated to `86/90`; autogen parent updated to `0001KA`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md --apply`: OK; completion/confidence updated to `87/92`; autogen parent updated to `0001KA`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md --apply`: OK; completion/confidence updated to `89/93`; autogen parent updated to `0001KA`.
- Blockers:
  - No Batch 192 target documentation blocker remains. Final C++ remains blank because exact original helper names, declaration shape, and broader queue/source signatures are below the `95/95` final-source gate.
  - No Batch 192 coverage-report rows remain pending; the supervisor applied and validated the `by-memory/-coverage-report.md` replacements for `0001K6`, `0001KA`, `0002KX`, `0002KY`, and `0002KZ` on 2026-06-11.

## 2026-06-11 Agent-A005 Batch 197

- Targets completed:
  - [UID:0001KN] `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`: `84/88`, parent blank -> `86/90`, parent [UID:00007B].
  - [UID:0001KO] `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`: `84/86`, `RECONSTRUCTABLE:TRUE` -> `86/88`, `RECONSTRUCTABLE:FALSE`, parent blank as a mixed non-emitting index.
  - [UID:0001KV] `by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md`: `82/88`, `RECONSTRUCTABLE:TRUE` -> `86/90`, `RECONSTRUCTABLE:FALSE`, parent blank as a non-emitting exact-method index.
- Related strict-gate repairs:
  - [UID:0000KU] `LivingObjectPane` file `88/80` -> `88/85`; [UID:00007B] `LivingObjectPane` class `84/80` -> `85/85`.
  - [UID:0000N9] `SayInputPanes` file `87/84` -> `87/85`; [UID:0002RX] dispatcher `78/86` -> `85/88`.
  - [UID:0000O0] `SpellInputPanes` file `88/80` -> `88/85`; [UID:0000DU] `SpellStringInputPane` class `84/82` -> `86/86`.
  - [UID:0001KU] constructor `84/90` -> `85/91`; [UID:0001KW] confirm handler `80/85` -> `86/89`; new [UID:0003AG] direct destructor `85/90`.
- Evidence used:
  - Live IDA MCP on 2026-06-11 reconfirmed `sub_5A3E30` size `0x1c3` / 451, seven modeled callers plus raw xref `0x005a3ac6`, and item packet/target-pane callees.
  - Live IDA MCP reconfirmed the `SayModeHelpers` 19-function map and `sub_5A5110` size `0x227` / 551 with five refs including raw `0x004cf937`.
  - Live IDA MCP reconfirmed `SpellStringInputPane` constructor size `0x8d` / 141, direct destructor size `0x83` / 131, confirm handler size `0x144` / 324, direct destructor callees, confirm vtable ref `0x0062f1cc`, packet/convert/send callees, and padding/raw-gap boundaries.
  - `int_convert.py` verified all hex/decimal values recorded in changed pages, including `0x1c3 == 451`, `0x227 == 551`, `0x144 == 324`, `0x83 == 131`, `0x8d == 141`, `0xd == 13`, `0xc == 12`, and `0x108 == 264`.
- Changed files:
  - `by-memory/0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md`
  - `by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md`
  - `by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md`
  - `by-memory/0x005adf40-0x005ae1a4.SpellStringInputPane.md`
  - `by-memory/0x005adf40-0x005adfcd.SpellStringInputPaneConstructor.md`
  - `by-memory/0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md`
  - `by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md`
  - `by-class/LivingObjectPane.md`, `by-class/SpellStringInputPane.md`, `by-class/-coverage-report.md`
  - `by-file/LivingObjectPane.md`, `by-file/SayInputPanes.md`, `by-file/SpellInputPanes.md`, `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Validation:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x005adfd0-0x005ae053.SpellStringInputPaneDirectDestructor.md --apply`: OK; validator assigned [UID:0003AG].
  - Validated with `--apply` in dependency order: `by-file\LivingObjectPane.md`, `by-class\LivingObjectPane.md`, `by-file\SayInputPanes.md`, `by-file\SpellInputPanes.md`, `by-class\SpellStringInputPane.md`, [UID:0001KN], [UID:0002RX], [UID:0001KU], [UID:0003AG], [UID:0001KW], [UID:0001KO], and [UID:0001KV]. All exited 0.
  - Validated `by-file\-coverage-report.md` and `by-class\-coverage-report.md` with `--apply`: OK.
- Blockers:
  - No Batch 197 assigned target remains below the strict 85/85 documentation gate.
  - `by-memory/-ignored.md` was leased by A002, so exact padding ignored rows are pending below.
  - Final C++ remains blank because these pages remain below the `95/95` source-emission gate.

### Supervisor-Applied Coverage Report Rows for Batch 236

- The supervisor applied and validated the Batch 236 `by-memory/-coverage-report.md` replacement rows for [UID:00029Y], [UID:0002W7], [UID:0002W8], [UID:0002W9], and [UID:0002WA] on 2026-06-11.
- The supervisor applied and validated the Batch 236 `by-global/-coverage-report.md` additions/replacements for [UID:0003ED], [UID:0003EE], [UID:0000RX], and [UID:0000SB] on 2026-06-11.
- The supervisor applied and validated the Batch 236 `by-file/-coverage-report.md` replacement row for [UID:0000NX] and the `by-class/-coverage-report.md` replacement row for [UID:0000DJ] on 2026-06-11.
- No Batch 236 coverage-report rows remain pending.

## 2026-06-11 Agent-A005 Batch 239

- Targets completed:
  - [UID:0002WC] `by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md`: `84/90`, parent blank -> `87/92`, parent [UID:0000SM].
  - [UID:0002WD] `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md`: `84/88`, parent blank -> `86/90`, parent new [UID:0003EI].
  - [UID:0002WF] `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`: `84/90`, parent blank -> `87/92`, parent [UID:0000RI].
  - [UID:0002WG] `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`: `84/90`, parent blank -> `87/92`, parent [UID:0000RV].
- Related parent repairs:
  - [UID:0000SM] `by-global/g_pUrlAlertPane.md`: `82/90` -> `86/91`, parent remains [UID:0000HE].
  - New [UID:0003EI] `by-global/g_pUserListDialogPane.md`: created at `86/90`, parent [UID:0000OZ].
  - [UID:0000RI] `by-global/g_pMenuVarietyPane.md`: `84/88` -> `86/90`, parent remains [UID:0000L8].
  - [UID:0000RV] `by-global/g_pOldUserStatusPane.md`: `84/88` -> `86/90`, parent remains [UID:0000P2].
  - [UID:00029Y] `by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md`: `86/93` -> `87/93`, remains `RECONSTRUCTABLE:FALSE` and unassigned as a mixed non-emitting split index.
- Evidence used:
  - Existing IDA-backed docs report initialized `ff ff ff ff` storage and exact direct xref families for all four one-dword singleton slots.
  - `int_convert.py` verified `0x4 == 4`, and all four targets now record the verified `0x4` / 4-byte slot size.
  - Current parent documents were rechecked: [UID:0000HE] `AlertPanes` is `85/88`, [UID:0000OZ] `UserListDialogPane` is `86/85`, [UID:0000L8] `MenuVarietyPanes` is `86/85`, and [UID:0000P2] `UserStatusPane` is `88/85`; related classes also clear or support the gate.
- Changed files:
  - `by-global/g_pUrlAlertPane.md`
  - `by-global/g_pUserListDialogPane.md`
  - `by-global/g_pMenuVarietyPane.md`
  - `by-global/g_pOldUserStatusPane.md`
  - `by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md`
  - `by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md`
  - `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md`
  - `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`
  - `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased the eight existing by-* docs and `notes.md` before editing; created `by-global/g_pUserListDialogPane.md`, then leased it before validation/further edits.
  - The long validation pass ran past the short lease window; the release attempt reported `Rejected[No active lease]` for the batch files, and the final `current_leases.md` check showed no active leases. Took a fresh A005 lease on this `notes.md` only to record that final lease state.
  - Did not edit `by-memory/-coverage-report.md` or other coverage reports directly.
- Validation commands/results:
  - Initial `python source-3\project-documentation\tools\validator.py ...` invocation from the project-documentation working directory failed because the relative path duplicated `source-3\project-documentation`; reran with `python tools\validator.py ...`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-global\g_pUserListDialogPane.md --apply`: OK; inserted [UID:0003EI] and metadata.
  - Validated with `--apply` in file mode: `by-global\g_pUserListDialogPane.md`, `by-global\g_pUrlAlertPane.md`, `by-global\g_pMenuVarietyPane.md`, `by-global\g_pOldUserStatusPane.md`, the four assigned exact by-memory children, and [UID:00029Y] aggregate. All exited 0.
  - `auto-generated/-ag-memory-coverage.md` now reports [UID:0002WC], [UID:0002WD], [UID:0002WF], and [UID:0002WG] as assigned to `0000SM`, `0003EI`, `0000RI`, and `0000RV`; [UID:00029Y] remains not reconstructable.
- Blockers:
  - No Batch 239 documentation/routing blocker remains. Final C++ remains blank because these singleton declaration pages are below the `95/95` source-emission bar.
  - `git status --short` could not be used because `E:\NTK\GhidraBridge` is not a Git repository in this environment.

### Supervisor-Applied Coverage Report Rows for Batch 239

- The supervisor applied and validated the Batch 239 `by-memory/-coverage-report.md` replacement rows for [UID:00029Y], [UID:0002WC], [UID:0002WD], [UID:0002WF], and [UID:0002WG].
- The supervisor applied and validated the Batch 239 `by-global/-coverage-report.md` replacements for [UID:0000RI], [UID:0000RV], and [UID:0000SM], plus the inserted [UID:0003EI] `g_pUserListDialogPane` row.
- No Batch 239 coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 244

- Targets completed:
  - [UID:000239] `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`: `76/82`, parent blank -> `86/86`, parent [UID:0000ER] `TextInputMenuDialog`.
  - [UID:000381] `by-memory/0x0053d060-0x0053d0f7.DamageNumberObjectPaneScalarDeletingDestructor.md`: `88/92`, parent blank -> `89/93`, parent [UID:00003F] `DamageNumberObjectPane`.
  - [UID:000386] `by-memory/0x0053d620-0x0053d65b.ObjectInfoObjectPaneScalarDeletingDestructor.md`: `88/92`, parent blank -> `89/93`, parent [UID:00009P] `ObjectInfoObjectPane`.
  - [UID:00038E] `by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md`: `88/91`, parent blank -> `89/92`, parent [UID:000097] `NewOptionPane`.
- Related parent and aggregate repairs:
  - [UID:000097] `by-class/NewOptionPane.md`: `84/82` -> `85/85`; documents the exact scalar deleting destructor child, vtable/xref evidence, four owned pointer releases, and [UID:0000M7] `OptionPane` direct-parent gate.
  - [UID:0001DL] `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`: remains `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank; refreshed child rows for [UID:000381] and [UID:000386].
  - [UID:00023K] `by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md`: remains `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank; refreshed [UID:00038E] child routing now that `NewOptionPane` clears the strict gate.
- Evidence used:
  - Live IDA MCP on 2026-06-12 confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `0x0051a420-0x0051a51c` is raw helper code, not an IDA function; evidence includes opcode `0x39`, `0x208` local packet frame, field reads at `this+0x278/+0x270/+0x27a/+0x27c`, optional `this+0x280` text, `g_packetSender`, no direct xrefs, and padding boundaries.
  - `0x0053d060` is `sub_53D060`, size `0x97`, refs `0x0053cec0/0x0053cecb` plus vtable ref `0x006207ec`, calls `0x004b14c0`, `0x00538100`, and guard `0x0041b6a0`, with class vtable stores at `+0xa0/+0xa4`.
  - `0x0053d620` is `sub_53D620`, size `0x3b`, refs `0x0053cf62/0x0053cf6d` plus vtable ref `0x006208a0`, calls `0x00538100`, guard `0x0041b6a0`, and generic free `0x004f4ac0`.
  - `0x00542860` is `sub_542860`, size `0xd3`, refs `0x00542613/0x0054261e` plus vtable ref `0x006210a4`, calls `0x00544690` four times, `0x005450d0`, `0x004f4ac0`, and guard `0x0041b6a0`, with class vtable stores at `+0xa0/+0xa4`.
  - `int_convert.py` verified `0xfc == 252`, `0x208 == 520`, `0x278 == 632`, `0x270 == 624`, `0x27a == 634`, `0x27c == 636`, `0x280 == 640`, `0x97 == 151`, `0x3b == 59`, `0xd3 == 211`, `0xa0 == 160`, and `0xa4 == 164`.
- Changed files:
  - `by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md`
  - `by-memory/0x0053d060-0x0053d0f7.DamageNumberObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d620-0x0053d65b.ObjectInfoObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md`
  - `by-class/NewOptionPane.md`
  - `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`
  - `by-memory/0x005426e0-0x00542ab5.DialogPaneScalarDeletingDestructorIsland.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Leases used:
  - Leased the four target docs, [UID:000097] `NewOptionPane`, the two aggregate/split inventory docs, and this `notes.md` before editing.
  - After restart recovery, no Agent-A005 leases were active; took a fresh lease on `notes.md` only to record this Batch 244 completion and pending coverage rows.
  - Did not edit `by-memory/-coverage-report.md` or `by-class/-coverage-report.md`.
- Validation commands/results:
  - Validated with `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for `by-class\NewOptionPane.md`, all four target by-memory docs, and both aggregate/split-inventory docs. All exited 0.
  - Post-validation headers show [UID:000239] `86/86` parent `0000ER`, [UID:000381] `89/93` parent `00003F`, [UID:000386] `89/93` parent `00009P`, [UID:00038E] `89/92` parent `000097`, [UID:000097] `85/85` parent `0000M7`, [UID:0001DL] `90/92` parent blank, and [UID:00023K] `90/92` parent blank.
  - `auto-generated/-ag-memory-coverage.md` reports [UID:000239], [UID:000381], [UID:000386], and [UID:00038E] assigned to `0000ER`, `00003F`, `00009P`, and `000097`; [UID:0001DL] and [UID:00023K] remain not reconstructable.
- Blockers:
  - No Batch 244 target documentation or strict-gate blocker remains.
  - Final C++ remains blank because all four targets are below the `95/95` source-emission bar.
  - `by-memory/-coverage-report.md` and `by-class/-coverage-report.md` are supervisor-owned/stale under the current override; exact pending rows are below.

### Supervisor-Applied Coverage Report Rows for Batch 244

- The supervisor applied and validated the Batch 244 `by-memory/-coverage-report.md` replacement rows for [UID:000239], [UID:0001DL], [UID:000381], [UID:000386], [UID:00023K], and [UID:00038E].
- The supervisor applied and validated the Batch 244 `by-class/-coverage-report.md` replacement row for [UID:000097] `NewOptionPane`.
- No Batch 244 coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 245

- Targets completed:
  - [UID:00023Q] `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`: `78/82`, parent blank -> `85/86`, parent [UID:0000C0] `RightButtonMenuPane`.
  - [UID:0003A5] `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md`: `85/88`, parent blank -> `86/89`, parent [UID:0000CM] `ScrollPane`, position `40`.
  - [UID:00031M] `by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md`: `76/84`, parent blank -> `85/88`, parent [UID:0001H2], position `20`.
  - [UID:00031N] `by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md`: `76/84`, parent blank -> `85/88`, parent [UID:0001H2], position `30`.
- Related repairs:
  - [UID:0001GK] renamed from `0x0055d9e0-0x0055de98.ScrollPaneGetScrollPartRect.md` to `0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`, `82/86` parent [UID:0000NF] -> `85/88` parent [UID:0003A5], position `20`.
  - [UID:0000CM] `by-class/ScrollPane.md`: `85/86` -> `86/87`; now documents the full generic ScrollPane input/geometry span through `0x0055e65c`.
  - [UID:0000NF] `by-file/ScrollBar.md`: score unchanged `89/85`; fixed the stale generic ScrollPane span and [UID:0001GK] links.
  - [UID:0001H2] `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`: score unchanged `85/88`; refreshed child rows/evidence after [UID:00031M] and [UID:00031N] cleared the strict gate.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - RightButton raw starts `0x00555780` and `0x005557e0` are not IDA functions, have no direct xrefs or pointer-pattern hits, and contain opcode `0x4a` packet send bodies with exact internal/trailing padding.
  - ScrollPane helper cluster `0x0055d960-0x0055e65c` has seven modeled functions, generic ScrollPane input callers, internal `GetScrollPartRect` calls, stable padding, and [UID:0001GK] corrected to IDA size `0x4b9` / 1209 bytes.
  - ScrollVolume raw starts `0x005647c0` and `0x005647f0` are not IDA functions, have no direct xrefs or pointer-pattern hits, write `+0xf8`/`+0xfa`, invalidate `this+0x44` through vtable slot `+0x20`, and sit inside the `85/88` [UID:0001H2] aggregate.
  - `int_convert.py` verified all recorded decimal conversions, including `0x142`, `0x5a`, `0xe2`, `0xcfc`, `0x4b9`, `0x27`, `0x24`, `0x9`, `0xc`, `0xf8`, `0xfa`, `0x44`, and `0x20`.
- Changed files:
  - `by-memory/0x00555780-0x005558c2.RightButtonMenuPacketHelpers.md`
  - `by-class/RightButtonMenuPane.md`
  - `by-file/RightButtonMenuPane.md`
  - `by-memory/0x0055d960-0x0055e65c.ScrollPaneInputGeometryHelpers.md`
  - `by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md`
  - `by-class/ScrollPane.md`
  - `by-file/ScrollBar.md`
  - `by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md`
  - `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`
  - `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md`
  - `by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md`
  - `by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetLowStateWordRaw.md`
  - `by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetStateByteRaw.md`
  - `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Validation:
  - Validated with `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for all changed by-* files listed above. All exited 0.
  - First validation pass rebuilt stale validator metadata for the renamed [UID:0001GK] file; `auto-generated/-ag-memory-coverage.md` now reports [UID:00023Q], [UID:0003A5], [UID:0001GK], [UID:00031M], and [UID:00031N] assigned to `0000C0`, `0000CM`, `0003A5`, `0001H2`, and `0001H2`.
  - `by-memory/-coverage-report.md` remains supervisor-owned/stale and needs the exact replacement rows below. Validator normalized the [UID:0001GK] link target during validation, but the row text/range/score still require supervisor replacement.
- Blockers:
  - No Batch 245 target remains below the strict `85/85` documentation/routing gate.
  - Final C++ remains blank for these targets because they are below the `95/95` source-emission gate and still have final helper-name/field-name caveats.

### Supervisor-Applied Coverage Report Rows for Batch 245

- The supervisor applied and validated the Batch 245 `by-memory/-coverage-report.md` replacement rows for [UID:00023Q], [UID:0003A5], [UID:0001GK], [UID:0001H2], [UID:00031M], and [UID:00031N] on 2026-06-12.
- The supervisor applied and validated the Batch 245 `by-class/-coverage-report.md` replacement row for [UID:0000CM] `ScrollPane`.
- The supervisor applied and validated the Batch 245 `by-file/-coverage-report.md` replacement row for [UID:0000NF] `ScrollBar`.
- No Batch 245 coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 249

- Target completed:
  - [UID:00031O] `by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md`: `78/85`, parent blank -> `85/88`, parent [UID:0001H2] `ScrollVolumePane`, position `50`.
- Related parent repair:
  - [UID:0001H2] `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`: score unchanged `85/88`, parent unchanged [UID:0000CO] at position `10`; refreshed child row/evidence after [UID:00031O] cleared the strict child/direct-parent assignment gate.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `lookup_funcs` reports `0x005648f0` is not an IDA function; surrounding modeled functions are `sub_5648D0` size `0x1a` and `sub_564910` size `0x1e1`.
  - `xrefs_to`, `callers`, `callees`, and little-endian pointer-pattern search for `0x005648f0` all returned empty, matching the raw/no-dispatch caveat.
  - Byte-level IDA check confirms exact body bytes `80 b9 02 01 00 00 00 74 0e 33 c0 66 3b 81 00 01 00 00 7d 03 b0 01 c3 32 c0 c3`, size `0x1a` / 26 bytes, with `0x6` / 6-byte `0xcc` padding before and after.
  - Disassembly proves the predicate reads enabled byte `+0x102`, compares word `+0x100` against zero, returns `1` only when enabled and positive, otherwise returns `0`.
  - `int_convert.py` verified `0x1a == 26`, `0x6 == 6`, `0x102 == 258`, `0x100 == 256`, `0x20 == 32`, `0x1e1 == 481`, `0x005648f0 == 5654768`, and `0x0056490a == 5654794`.
- Changed files:
  - `by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md`
  - `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Validation:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md --apply` exited 0 and updated [UID:00031O] to `85/88`, parent `0001H2`, position `50`.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00564710-0x005654ec.ScrollVolumePane.md --apply` exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:00031O] assigned to `0001H2` at position `50`.
- Blockers:
  - No Batch 249 documentation or strict-gate blocker remains.
  - Final C++ remains blank because [UID:00031O] is below the `95/95` source-emission bar and still has source-name/dispatch caveats.
  - `by-memory/-coverage-report.md` remains supervisor-owned/stale under the current override; exact pending replacement rows are below.

### Supervisor-Applied Coverage Report Rows for Batch 249

- The supervisor applied and validated the Batch 249 `by-memory/-coverage-report.md` replacement rows for [UID:0001H2] and [UID:00031O] on 2026-06-12.
- No Batch 249 coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 253

- Target completed:
  - [UID:0001MG] `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`: `78/82`, parent blank -> `86/88`, parent [UID:0000KC] `ItemActionInputPanes`.
- New exact child pages created and validated:
  - [UID:0003FK] `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md`: new `0/0` -> `85/88`, parent [UID:0000KC].
  - [UID:0003FL] `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md`: new `0/0` -> `85/88`, parent [UID:0000KC].
  - [UID:0003FM] `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`: new `0/0` -> `85/88`, parent [UID:0000KC].
  - [UID:0003FN] `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md`: new `0/0` -> `85/88`, parent [UID:0000KC].
  - [UID:0003FO] `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md`: new `0/0` -> `85/88`, parent [UID:0000KC].
- Related child/class repairs:
  - [UID:0001MH] `DropGoldInputPaneRawConstructor`: `74/84` -> `85/88`, parent remains [UID:000043].
  - [UID:0001MI] `GiveGoldInputPaneRawConstructor`: `74/84` -> `85/88`, parent remains [UID:00005T].
  - [UID:000043] `DropGoldInputPane`: `80/84` -> `85/86`, parent remains [UID:0000KC].
  - [UID:00005T] `GiveGoldInputPane`: `80/84` -> `85/86`, parent remains [UID:0000KC].
  - [UID:00005S] `GiveAllInputPane`: `80/87` -> `85/88`, parent remains [UID:0000KC].
  - [UID:00005U] `GiveInputPane`: `80/87`, parent blank -> `85/88`, parent [UID:0000KC].
  - [UID:0000KC] `ItemActionInputPanes`: score unchanged `90/85`; refreshed proposed contents/boundary notes for the exact Drop/Give raw helper split.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `lookup_funcs` reports all five new raw helper starts `0x005b4760`, `0x005b4af0`, `0x005b4c50`, `0x005b4ef0`, `0x005b5230`, plus constructor starts `0x005b4b70` and `0x005b52b0`, as `Not a function`.
  - IDA `CodeRefsTo`/`DataRefsTo` and `find_bytes` pointer-pattern checks found no direct xrefs/pointer hits for those seven raw starts.
  - Byte audit split prior broad raw gaps into exact `0xcc` padding and non-`0xcc` helper bodies: five `0x7c` / 124-byte item packet helpers except `0x005b4c50-0x005b4cb9` at `0x69` / 105 bytes, plus two `0x40` / 64-byte gold constructors.
  - Disassembly confirms packet opcodes/modes: drop-all `0x08` mode `1`, drop-item `0x08` mode `0`, drop-gold `0x24` with `0x005753f0` amount encoding, give-all `0x29` mode `1`, give-item `0x29` mode `0`, all behind busy gate `dword_67A748 + 0x3ec0` and packet sender `dword_67A7EC`.
  - `int_convert.py` verified recorded conversions including `0xeda == 3802`, `0x7c == 124`, `0x69 == 105`, `0x40 == 64`, `0x84 == 132`, `0x3ec0 == 16064`, `0x108 == 264`, `0xa0 == 160`, `0xa4 == 164`, `0x2b == 43`, and padding/packet sizes.
- Changed files:
  - `by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md`
  - `by-memory/0x005b4760-0x005b47dc.SendDropAllItemPacketRaw.md`
  - `by-memory/0x005b4af0-0x005b4b6c.SendDropItemPacketRaw.md`
  - `by-memory/0x005b4c50-0x005b4cb9.SendDropGoldPacketRaw.md`
  - `by-memory/0x005b4ef0-0x005b4f6c.SendGiveAllItemPacketRaw.md`
  - `by-memory/0x005b5230-0x005b52ac.SendGiveItemPacketRaw.md`
  - `by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md`
  - `by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md`
  - `by-class/DropGoldInputPane.md`
  - `by-class/GiveGoldInputPane.md`
  - `by-class/GiveAllInputPane.md`
  - `by-class/GiveInputPane.md`
  - `by-file/ItemActionInputPanes.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Validation:
  - Created new split pages, then ran `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for the five new child pages so validator assigned [UID:0003FK] through [UID:0003FO].
  - After metadata/body edits, validated with the same command for all changed by-* files listed above. All exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:0001MG], [UID:0003FK], [UID:0003FL], [UID:0003FM], [UID:0003FN], and [UID:0003FO] assigned to [UID:0000KC]; [UID:0001MH] remains assigned to [UID:000043] and [UID:0001MI] remains assigned to [UID:00005T].
  - Post-validation `auto-generated/-ag-class-coverage.md` reports [UID:000043], [UID:00005S], [UID:00005T], and [UID:00005U] assigned to [UID:0000KC].
- Leases:
  - Initial leases expired during the long edit pass; no other agent held these files afterward. Reacquired all changed files and `notes.md` before validation/notes updates.
  - Did not edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, or `by-file/-coverage-report.md` directly.
- Blockers:
  - No Batch 253 strict-gate blocker remains.
  - Final C++ remains blank because helper/source names, callback type names, local/prompt field names, and source-quality method bodies remain below the `95/95` source-emission gate.

### Supervisor-Applied Coverage Report Rows for Batch 253

- The supervisor applied and validated the Batch 253 rows for `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, and `by-file/-coverage-report.md` on 2026-06-12.
- No Batch 253 supervisor-owned coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 259

- Target completed:
  - [UID:00034X] `by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md`: `85/88`, parent blank -> `86/90`, parent [UID:0000E1] `StaticObjectPane`.
- Related parent/report repairs:
  - [UID:0000E1] `by-class/StaticObjectPane.md`: `85/87` -> `86/88`, parent remains [UID:0000O6] `StaticObjectPane`.
  - [UID:0000O6] `by-file/StaticObjectPane.md`: `85/87` -> `86/88`, projected path remains `NexusTK/map/`.
  - [UID:000260] `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`: score unchanged `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank; refreshed [UID:00034X] child routing from stale below-gate/blank to assigned to [UID:0000E1].
  - `by-class/-coverage-report.md`: synced [UID:0000E1] row directly under lease.
  - `by-file/-coverage-report.md`: synced [UID:0000O6] row directly under lease.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` verified the exact child anchors: `0x00620340 -> ??_R4StaticObjectPane@@6B@`, `0x00620344 -> ??_7StaticObjectPane@@6B@`, `0x006203b0 -> ??_R4StaticObjectPane@@6B@_0`, `0x006203b4 -> ??_7StaticObjectPane@@6B@_0`, `0x006203e0 -> ??_R4StaticObjectPane@@6B@_1`, `0x006203e4 -> ??_7StaticObjectPane@@6B@_1`, and successor boundary `0x006203ec -> ??_R4ItemObjectPane@@6B@`.
  - `xrefs_to` reports constructor vptr-store refs at `0x00537926`, `0x0053792c`, and `0x00537936`, all inside `sub_537900`.
  - `lookup_funcs` reports `sub_537900` size `0x47`, scalar deleting destructor `sub_53D740` size `0x7d`, and adjusted thunks `sub_53CF88`/`sub_53CF93` size `0x0b`.
  - Constructor disassembly shows `ObjectPane` base construction with type `5`, static-object id storage at `this+0x128`, and vtable writes at `this+0x00`, `this+0xa0`, and `this+0xa4`.
  - `int_convert.py` verified `0xac == 172`, `0x70 == 112`, `0x30 == 48`, and `0x0c == 12`.
- Changed files:
  - `by-memory/0x00620340-0x006203ec.StaticObjectPaneVtableData.md`
  - `by-class/StaticObjectPane.md`
  - `by-file/StaticObjectPane.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A005/notes.md`
- Validation:
  - Ran `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for the four changed by-* documentation pages. All exited 0.
  - Ran the same validator command for `by-class/-coverage-report.md` and `by-file/-coverage-report.md`. Both exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:00034X] assigned to [UID:0000E1] with generated output root `auto-generated/NexusTK/map/StaticObjectPane.cpp`.
- Leases:
  - Leased the target, StaticObjectPane class/file pages, ObjectPane read-only aggregate, class/file coverage reports, and this `notes.md` before editing.
  - Did not edit `by-memory/-coverage-report.md` due to the active supervisor ban.
- Blockers:
  - No Batch 259 strict-gate blocker remains.
  - Final C++ remains blank because the vtable bytes are compiler-emitted from source declarations and the class body still lacks final-audit field/layout/source-ready naming.

### Supervisor-Applied Coverage Report Rows for Batch 259

- The supervisor applied and validated the Batch 259 `by-memory/-coverage-report.md` replacement row for [UID:00034X] on 2026-06-12.
- `by-class/-coverage-report.md` and `by-file/-coverage-report.md` were updated directly by A005 and validated by the supervisor.
- No Batch 259 supervisor-owned coverage-report rows remain pending.

## 2026-06-12 Agent-A005 Batch 264

- Target completed:
  - [UID:000354] `by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md`: `85/88`, parent blank -> `86/91`, parent [UID:00003F] `DamageNumberObjectPane`.
- Related parent/report repairs:
  - [UID:00003F] `by-class/DamageNumberObjectPane.md`: `85/89` -> `86/90`, parent remains [UID:0000HJ] `AttachedObjectPane`.
  - [UID:0000HJ] `by-file/AttachedObjectPane.md`: `85/85` -> `86/86`, projected path remains `NexusTK/map/`.
  - [UID:000260] `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`: score unchanged `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank; refreshed [UID:000354] child routing from stale below-gate/blank to assigned to [UID:00003F].
  - `by-class/-coverage-report.md` and `by-file/-coverage-report.md` were updated directly under lease and validated.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` verified exact anchors: `0x006207e8 -> ??_R4DamageNumberObjectPane@@6B@`, `0x006207ec -> ??_7DamageNumberObjectPane@@6B@`, `0x00620860 -> ??_R4DamageNumberObjectPane@@6B@_0`, `0x00620864 -> ??_7DamageNumberObjectPane@@6B@_0`, `0x00620890 -> ??_R4DamageNumberObjectPane@@6B@_1`, `0x00620894 -> ??_7DamageNumberObjectPane@@6B@_1`, and successor boundary `0x0062089c -> ??_R4ObjectInfoObjectPane@@6B@`.
  - `xrefs_to` confirmed constructor vptr stores at `0x0053927d`, `0x00539283`, and `0x0053928d`; unwind restores at `0x00539360`, `0x00539366`, and `0x00539370`; scalar-destructor restores at `0x0053d085`, `0x0053d08b`, and `0x0053d095`.
  - `lookup_funcs` and disassembly tied the range to constructor `sub_539230`, unwind cleanup `sub_539360`, scalar deleting destructor `sub_53D060`, and adjusted thunks `sub_53CEBA` / `sub_53CEC5`.
  - `int_convert.py` verified `0xb4 == 180`, `0x78 == 120`, `0x30 == 48`, `0x0c == 12`, `0x12e == 302`, `0x1f == 31`, `0x97 == 151`, `0x128 == 296`, `0xa0 == 160`, `0xa4 == 164`, `0x12c == 300`, `0x130 == 304`, and `0x136 == 310`.
- Validation:
  - Ran `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for the four changed by-* documentation pages and the two shared class/file coverage reports. All exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:000354] assigned to [UID:00003F] with output root `auto-generated/NexusTK/map/AttachedObjectPane.cpp`.
  - Validator also reported unrelated stale registry warnings for [UID:0003AL] and [UID:0003AM] renamed/missing registered files; those files are outside Batch 264 scope.
- Blockers:
  - No Batch 264 strict-gate blocker remains.
  - Final C++ remains blank because the vtable bytes are compiler-emitted from source declarations and the class body still lacks final-audit field/source-ready naming.

### Supervisor-Applied Coverage Report Row for Batch 264

- The supervisor applied and validated the Batch 264 `by-memory/-coverage-report.md` replacement row for [UID:000354][DamageNumberObjectPaneVtableData](by-memory/0x006207e8-0x0062089c.DamageNumberObjectPaneVtableData.md) on 2026-06-12.
- No Batch 264 supervisor-owned report rows remain pending.

## 2026-06-12 Agent-A005 Batch 267

- Target completed:
  - [UID:0003D9] `by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md`: `85/90`, parent blank -> `86/91`, parent [UID:0000D1] `ServerSelectMenuItemList`.
- Related parent/report repairs:
  - [UID:0000D1] `by-class/ServerSelectMenuItemList.md`: `82/84` -> `85/88`, parent remains [UID:0000NO] `ServerSelectPane`.
  - [UID:0000NO] `by-file/ServerSelectPane.md`: `85/86` -> `86/87`, projected path remains `NexusTK/login/`.
  - [UID:00026F] `by-memory/0x00624c64-0x00624f20.SimpleServerSelectReadOnlyData.md`: score unchanged `85/91`, `RECONSTRUCTABLE:FALSE`, parent blank; refreshed [UID:0003D9] child routing from stale below-gate/blank to assigned to [UID:0000D1].
  - [UID:0001HR] `by-memory/0x00573d20-0x005747df.ServerSelectPane.md`: score unchanged `78/84`; removed stale `84/80` file-parent and old 80% gate wording, documenting that this broad executable cluster is not used as precedent for new strict-gate routing.
  - `by-class/-coverage-report.md` and `by-file/-coverage-report.md` were updated directly under lease and validated.
- Evidence used:
  - Live IDA MCP confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` verified `.rdata` anchors: `0x00624dc0 -> ??_R4ServerSelectMenuItemList@@6B@`, `0x00624dc4 -> ??_7ServerSelectMenuItemList@@6B@`, slot dwords `0x00624e40 -> 0x00574660` and `0x00624e44 -> 0x00574670`, adjusted RTTI/table heads at `0x00624e48/0x00624e4c` and `0x00624e78/0x00624e7c`, and successor string head `0x00624e84`.
  - `xrefs_to` reconfirmed table-base refs from parent constructor/list-building stores `0x00573f0b/0x00573f11/0x00573f1b` and `0x005741c8/0x005741ce/0x005741d8`, plus raw constructor stores `0x005744d7/0x005744dd/0x005744e7`.
  - `lookup_funcs` reconfirmed `0x005744a0` is not an IDA function, while modeled helpers/methods include `0x00574510` size `0x3e`, `0x005745b0` size `0xae`, `0x00574660` size `0x0b`, and `0x00574670` size `0xd8`.
  - `disasm` reconfirmed raw constructor behavior: `ListPane` base construction, owner pointer stored at `+0x14c`, primary vtable written at `[this]`, and adjusted vtables written at `+0xa0` and `+0xa4`.
  - `decompile` reconfirmed `0x00574660` owner-forwarding activation behavior and `0x00574670` selected-row drawing, selected-name copy, and `"%s : %s"` formatting from entry fields `+4` and `+8`.
  - `int_convert.py` verified `0xc4 == 196`, `0x88 == 136`, `0x30 == 48`, `0x08 == 8`, `0x58 == 88`, `0xd8 == 216`, `0x14c == 332`, `0xa0 == 160`, `0xa4 == 164`, `0x0b == 11`, `0xae == 174`, `0x3e == 62`, `0x12f == 303`, `0x0e == 14`, `0x10 == 16`, and `0x04 == 4`.
- Validation:
  - Ran `python tools\validator.py --queue-timeout 120 --mode file --file <path> --apply` for the five changed by-* documentation pages and the two shared class/file coverage reports. All exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:0003D9] assigned to [UID:0000D1] with output root `auto-generated/NexusTK/login/ServerSelectPane.cpp`.
  - Post-validation `auto-generated/-ag-class-coverage.md` reports [UID:0000D1] assigned to [UID:0000NO]; `auto-generated/-ag-file-coverage.md` reports [UID:0000NO] as the `NexusTK/login/ServerSelectPane.cpp` file root.
- Blockers:
  - No Batch 267 strict-gate blocker remains.
  - Final C++ remains blank because the vtable bytes are compiler-emitted from source declarations and the class/source body still has final-audit blockers for owner pointer, row-entry type, helper ownership, and application/session field names.

### Supervisor-Applied Coverage Report Row for Batch 267

- The supervisor applied and validated the Batch 267 `by-memory/-coverage-report.md` replacement row for [UID:0003D9][ServerSelectMenuItemListVtableData](by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md) on 2026-06-12.
- No Batch 267 supervisor-owned report rows remain pending.

## 2026-06-12 Agent-A005 Batch 273

- Target completed:
  - [UID:0003C3] `by-memory/0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md`: `86/92`, parent blank -> `87/93`, parent [UID:00005O] `GameServerConfig`.
- Related docs refreshed without score changes:
  - [UID:00025S] `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`: still `86/93`, `RECONSTRUCTABLE:FALSE`, parent blank; child table now records [UID:0003C3] as `87/93` assigned to [UID:00005O].
  - [UID:0002HX] `by-memory/0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md`: still `85/90`, parent [UID:00005O]; now cross-links the exact fallback literal child.
  - [UID:00005O] `by-class/GameServerConfig.md`: still `85/86`, parent [UID:0000JP]; now includes the exact fallback literal child.
  - [UID:0000JP] `by-file/GameServerConfig.md`: still `86/85`; now includes the exact fallback literal in proposed contents/evidence.
- Evidence used:
  - IDA MCP JSON-RPC `tools/list` confirmed live inspection tools.
  - IDA MCP `idb_meta` confirmed IDB `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - IDA MCP `py_eval` read `0x0061e8fc-0x0061e908` as `.rdata` bytes `3f 00 3f 00 3f 00 3f 00 00 00 00 00`, decoded UTF-16LE `????`, and confirmed adjacent boundary names `asc_61E8FC` and successor `aNe_2`.
  - IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and `decompile` tied the literal to `0x00503ac7` inside `sub_503A80` (`0xd8` bytes), with callers `0x005b9318`/`0x005be746`, callees `_wcscpy_s`/`@__security_check_cookie@4`, fallback id `0`, `0x21` wide-copy capacity, and `0x44` / 68-byte record copy shape.
  - `int_convert.py` verified `0x0c == 12`, `0xd8 == 216`, `0x44 == 68`, `0x21 == 33`, `0x40 == 64`, and `0x30 == 48`.
- Validation:
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x0061e8fc-0x0061e908.GameServerConfigNationFallbackString.md --apply`: exited 0; updated score to `87/93`, parent `00005O`, and autogen registry.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md --apply`: exited 0.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-memory\0x00503a80-0x00503b58.GameServerConfigCopyNationEntryOrFallback.md --apply`: exited 0.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-class\GameServerConfig.md --apply`: exited 0.
  - `python tools\validator.py --queue-timeout 120 --mode file --file by-file\GameServerConfig.md --apply`: exited 0.
  - Post-validation `auto-generated/-ag-memory-coverage.md` reports [UID:0003C3] assigned to `00005O` with output root `auto-generated/NexusTK/map/GameServerConfig.cpp`.
- Leases:
  - Leased the target, mixed read-only aggregate, fallback method, GameServerConfig class/file pages, and this notes file. Initial leases expired during editing; no other agent took the files, and A005 reacquired them before validation/notes.
  - Did not edit banned `by-memory/-coverage-report.md`.
- Blockers:
  - No Batch 273 strict-gate blocker remains. Final C++ remains blank because this is source literal data below the final source-emission bar and the surrounding GameServerConfig/MapPane split caveat remains.

### Supervisor-Applied Coverage Report Row For Batch 273

- The supervisor applied and validated the Batch 273 `by-memory/-coverage-report.md` replacement row for [UID:0003C3] on 2026-06-12.
- No Batch 273 supervisor-owned coverage-report rows remain pending.
