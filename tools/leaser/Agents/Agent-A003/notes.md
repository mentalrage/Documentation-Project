# Agent A003 Notes

## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A003\current_leases.md`
Do not edit `current_leases.md`; read it for current lease status.

Compacted 2026-06-06: active follow-ups only. Detailed evidence belongs in the target pages and coverage rows; use those pages as authority when applying pending report/validator work.

## Recently Completed Shared Rows

- Manual `by-memory/-coverage-report.md` rows updated for `00016M`, `000168`, `000169`, `00018U`, `00018V`, `000191`, `00019M`, and `00019N`.
- `00016M` was coverage-only pending, so its detailed note was completed and removed.
- `00019M` and `00019N` were refreshed and attached to [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md); coverage rows are current, validator/generated state is not.
- Manual `by-memory/-coverage-report.md` rows are also current for `00022K`, `000167`, `000236`, `00019L`, and `00019J`; any remaining shared work for those UIDs is validator/generated-only.
- Manual `by-memory/-coverage-report.md` rows are current for `00019F` and `00023T`; remaining `00023T` shared work is validator/generated-only.
- Manual `by-memory/-coverage-report.md` rows are current for `0001FR`, `0001FS`, and `0001OQ`.
- 2026-06-06 applied shared validator/generated refreshes for `00022K`, `000167`, `000191`, `00019M`, `00019N`, `00018U`, `00018V`, `000169`, `000168`, `000236`, `00019L`, `00019J`, `00023T`, `0001FR`, `0001FS`, and the [UID:0000ND][ScreenshotCapture](../../../by-file/ScreenshotCapture.md) backlink. Queue rows are assigned to [UID:0000MW][Queue](../../../by-file/Queue.md) positions `50` and `60` in generated coverage.
- 2026-06-06 applied validator/generated refreshes for `0000WM` and `0000ZG`: `0000WM` now points at parent [UID:0000KV][LObject](../../../by-file/LObject.md) in generated state, and `0000ZG` now resolves to `by-memory/0x00470300-0x0047032a.AutoInit.md` with UID links refreshed by the validator.
- 2026-06-06 applied manual `by-memory/-coverage-report.md` rows for `0000WM`, `0001B5`, `000223`, `000239`, `0001FC`, `00012S`, `00012T`, and `00012U`.
- 2026-06-06 applied validator/generated refresh for `00012Y`; generated state now has the `76/84` page completion refresh and UID link cleanup.
- 2026-06-06 applied manual `by-memory/-coverage-report.md` rows for `000153`, `00012V`, `00012Y`, and `0001OC`.
- 2026-06-06 updated and validated `00024V` BrowserCloseScriptString to `78/88`.
- 2026-06-06 applied manual `by-memory/-coverage-report.md` rows for `00024V`, `00027A`, and `0002KD`.
- 2026-06-06 applied validator/generated refreshes for `0002KD` and `000249`; `000249` now points at parent [UID:0000ML][PlatformApi](../../../by-file/PlatformApi.md) in generated state.
- 2026-06-06 applied manual `by-memory/-coverage-report.md` row for `000249`.
- 2026-06-06 updated and validated `0001IF` SoundPathVectorClear to `82/86`, applied its manual coverage row, and ran `python tools\validator.py --mode file --file by-memory\-coverage-report.md --apply`.
- 2026-06-06 applied and validated the early singleton/global coverage-report batch: `00028L`, `00028P`, `00028Q`, `0001OX`, `00028R`, `00028T`, `00028U`, `00028V`, and `00028X`.
- 2026-06-06 verified the mid singleton/global, frame/image singleton, main-menu/UI singleton, and FittingRoom manual coverage batches were already current in `by-memory/-coverage-report.md`.
- 2026-06-06 applied and validated AES coverage-report rows for `0002JU` and `00028Y`.
- 2026-06-06 applied and validated ItemWho/target-selection coverage rows for `0001LB`, `0001LC`, `0001LF`, `0001LG`, `0001LH`, `0001LI`, `0001LJ`, and `0001LK`; the related queued ItemWho, QuitInputPane, SpellWho, and scalar-destructor rows were already current.
- 2026-06-06 updated and validated `0001KV` SpellStringInputPane aggregate to `78/87`, applied its manual coverage row, and verified `0001KU` was already current in `by-memory/-coverage-report.md`.
- 2026-06-06 applied and validated stale manual coverage rows for `000130`, `00013A`, `000142`, and `000143`.
- 2026-06-06 renamed and validated `000143` to `by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md`; validator refreshed UID link annotations and generated state.
- 2026-06-07 applied and validated manual `by-memory/-coverage-report.md` rows for `00014A`, `000144`, `000145`, `000147`, `00014W`, `00015C`, `0001KV`, `0001KU`, and `0001NH`; the completed pending row notes were removed.
- 2026-06-07 renamed and validated `0001N4`, `0001AM`, and `0001AN` to their corrected half-open filenames, updated `by-memory/-coverage-report.md`, and removed the completed blocked rename notes.
- 2026-06-07 updated and validated `0002RY` SendBlockListenModePacket to `76/84`, applied manual coverage rows for `000110`, `000141`, `0001AO`, `000238`, and `0002RY`, and removed the completed pending coverage note.
- 2026-06-07 applied and validated pending manual `by-memory/-coverage-report.md` rows for `0002RZ`, `00023G`, `0001NP`, and `0001NQ`; `000259` was already advanced in the report by another agent and its stale pending note was removed without downgrading it.
- 2026-06-07 applied the pending manual `by-memory/-coverage-report.md` row for `00025I` while processing Batch 012 target rows for `0002MK`, `0002ML`, and `0002MR`.
- 2026-06-08 applied and validated Batch 102 manual `by-memory/-coverage-report.md` rows for `0002U7`, `0000XX`, and `0000XY`.
- 2026-06-11 applied and validated Batch 169 manual `by-class/-coverage-report.md` rows for `00003F` and `00009P`.

## Supervisor-Applied Manual Coverage Rows

- Batch 163 `by-memory/-coverage-report.md` rows for `0001AL` and `0001AO` were applied and validated by the supervisor on 2026-06-11.
- Batch 169 `by-memory/-coverage-report.md` rows for `0001DB` and `0002QW` were applied and validated by the supervisor on 2026-06-11.
## Supervisor-Applied Shared Report Rows

- None. The supervisor applied and validated the Batch 150 `by-class/-coverage-report.md` row for `00007Y` and the `by-type/by-vtable/-coverage-report.md` row for `0001XV` on 2026-06-11.

## Batch 150 A003 Report

- Changed files:
  - `by-class/MenuQuestionDialogLarger.md`
  - `by-type/by-vtable/ItemDialogVtableFamily.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects:
  - `python tools\validator.py --mode file --file by-class\MenuQuestionDialogLarger.md --apply --queue-timeout 180` reported `ok: 1`, `completion_update 00007Y ... 85`, `confidence_update 00007Y ... 87`, and `autogen_registry_update 00007Y ... -> 0000LA`.
  - `python tools\validator.py --mode file --file by-type\by-vtable\ItemDialogVtableFamily.md --apply --queue-timeout 180` was run; a filtered confirmation rerun reported `mode: file`, `scanned markdown files: 1`, and `ok: 1`.
- Leases used:
  - Successfully leased `by-class/MenuQuestionDialogLarger.md` and `by-type/by-vtable/ItemDialogVtableFamily.md` as A003 before editing.
  - Attempted to lease `by-class/-coverage-report.md`; rejected because Agent-A005 had the active lease. `by-type/by-vtable/-coverage-report.md` was also leased by Agent-A005; the supervisor later applied and validated both shared report rows.
- Exact score changes:
  - [UID:00007Y] `MenuQuestionDialogLarger`: `82/85` -> `85/87`; `AUTOGEN_PARENT_UID` blank -> `0000LA`.
  - [UID:0001XV] `ItemDialogVtableFamily`: `86/89` -> `88/91`; `AUTOGEN_PARENT_UID` remains blank as a reviewed ownership-split vtable inventory.
- Blockers:
  - No Batch 150 shared report rows remain pending; the supervisor applied and validated them on 2026-06-11.
  - No by-memory documents changed. Pending `by-memory/-coverage-report.md` rows: none.

## Batch 163 A003 Report

- Changed files:
  - `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md`
  - `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`
  - `by-class/MiniMapButtonPane.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Leases used:
  - Successfully leased `by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md`, `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`, `by-class/MiniMapButtonPane.md`, `by-class/-coverage-report.md`, and `tools/leaser/Agents/Agent-A003/notes.md` as A003 before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remained active; the supervisor later applied and validated the exact replacement rows.
- Exact score/status changes:
  - [UID:0001AL] `MapNameAndMiniMapButtonPanes`: `84/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `86/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - [UID:0001AO] `GameServerNationAndMapInit`: `80/88`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - [UID:00008B] `MiniMapButtonPane`: `82/82` -> `85/86`; `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000LE` unchanged.
  - `by-class/-coverage-report.md` row for [UID:00008B] updated from `82%` to `85%`.
- Validation commands/results:
  - `python tools\validator.py --mode file --file by-memory\0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 0001AL ... 86`, `confidence_update 0001AL ... 92`, `autogen_registry_update 0001AL ... true -> false`.
  - `python tools\validator.py --mode file --file by-memory\0x005039f0-0x00504521.GameServerNationAndMapInit.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 0001AO ... 88`, `confidence_update 0001AO ... 92`, `autogen_registry_update 0001AO ... true -> false`.
  - `python tools\validator.py --mode file --file by-class\MiniMapButtonPane.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 00008B ... 85`, `confidence_update 00008B ... 86`.
  - `python tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 180`: `ok: 1`, `reference_index_add 0000LE by-class/-coverage-report.md by-class/-coverage-report.md`.
- Blockers:
  - No assignment was made for `0001AL` or `0001AO`: both clear 85/85 as documentation inventories, but by-structure ownership is mixed and no single direct parent covers either aggregate.

## Batch 169 A003 Report

- Changed files:
  - `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`
  - `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`
  - `by-class/DamageNumberObjectPane.md`
  - `by-class/ObjectInfoObjectPane.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Leases used:
  - Successfully leased `by-memory/0x00538bc0-0x00539bb2.ObjectOverlayPanes.md`, `by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md`, `by-class/DamageNumberObjectPane.md`, `by-class/ObjectInfoObjectPane.md`, and `tools/leaser/Agents/Agent-A003/notes.md` as A003 before editing.
  - Initial attempt to lease `by-class/-coverage-report.md` was rejected while another agent had the active lease; after the report became free, A003 leased it and applied the `00003F`/`00009P` row replacements. Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remained active; the supervisor later applied and validated those banned-report rows.
- Exact score/status/parent changes:
  - [UID:0001DB] `ObjectOverlayPanes`: `82/88`, `RECONSTRUCTABLE:TRUE`, parent blank -> `86/91`, `RECONSTRUCTABLE:FALSE`, parent blank. No assignment because the range is a non-emitting mixed-owner inventory spanning BowGauge HUD and AttachedObjectPane overlay families.
  - [UID:0002QW] `MotionAnimationConstructor`: `82/86`, parent blank -> `86/89`, `AUTOGEN_PARENT_UID:00008R`, `RECONSTRUCTABLE:TRUE` unchanged. Assignment is allowed because the child (`86/89`), direct class parent [UID:00008R][Motion](../../../by-class/Motion.md) (`85/85`), and file parent [UID:0000LL][Motion](../../../by-file/Motion.md) (`86/85`) clear the strict gate and ownership is single Motion constructor code.
  - [UID:00003F] `DamageNumberObjectPane`: `82/88` -> `85/89`; parent `0000HJ` retained under the strict gate.
  - [UID:00009P] `ObjectInfoObjectPane`: `82/88` -> `85/89`; parent `0000HJ` retained under the strict gate.
- Validation commands/results:
  - `python tools\validator.py --mode file --file by-memory\0x00538bc0-0x00539bb2.ObjectOverlayPanes.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 0001DB ... 86`, `confidence_update 0001DB ... 91`, `autogen_registry_update 0001DB ... true -> false`.
  - `python tools\validator.py --mode file --file by-memory\0x00539bc0-0x00539d43.MotionAnimationConstructor.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 0002QW ... 86`, `confidence_update 0002QW ... 89`, `autogen_registry_update 0002QW ... -> 00008R`.
  - `python tools\validator.py --mode file --file by-class\DamageNumberObjectPane.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 00003F ... 85`, `confidence_update 00003F ... 89`.
  - `python tools\validator.py --mode file --file by-class\ObjectInfoObjectPane.md --apply --queue-timeout 180`: `ok: 1`, `completion_update 00009P ... 85`, `confidence_update 00009P ... 89`.
  - `python tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 180`: `ok: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, generated coverage reports unchanged.
- Blockers:
  - `by-memory/-coverage-report.md` rows for `0001DB` and `0002QW` were applied and validated by the supervisor on 2026-06-11.

## Supervisor Rows A003 Report - 2026-06-11

- Assigned rows: `0001TN` `AddEmployeeItemDialogLayout`, `0001TY` `ClanInputDialogLayouts`, `0001VT` `ResourceLayoutNameRecord`, `0001Y6` `ModelessDialogPaneVtables`, `0001TO` `AlertPaneLayout`.
- Changed files:
  - `by-type/by-struct/AddEmployeeItemDialogLayout.md`
  - `by-class/AddEmployeeItemDialog.md`
  - `by-type/by-struct/ClanInputDialogLayouts.md`
  - `by-type/by-struct/AlertPaneLayout.md`
  - `by-file/AlertPanes.md`
  - `by-type/by-struct/ResourceLayoutNameRecord.md`
  - `by-type/by-vtable/ModelessDialogPaneVtables.md`
  - `by-type/by-struct/-coverage-report.md`
  - `by-type/by-vtable/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Leases used:
  - Successfully leased `by-type/by-struct/AddEmployeeItemDialogLayout.md`, `by-type/by-struct/ClanInputDialogLayouts.md`, `by-type/by-struct/ResourceLayoutNameRecord.md`, `by-type/by-struct/AlertPaneLayout.md`, `by-type/by-vtable/ModelessDialogPaneVtables.md`.
  - Successfully leased associated docs/reports `by-class/AddEmployeeItemDialog.md`, `by-file/AlertPanes.md`, `by-type/by-struct/-coverage-report.md`, `by-type/by-vtable/-coverage-report.md`, `by-file/-coverage-report.md`, `by-class/-coverage-report.md`, and this `notes.md`.
  - Initial `by-class/-coverage-report.md` lease attempt was rejected while another agent held it; after it became free, A003 leased it and applied the `000006` row update.
  - No A006-A010 work folders were used.
- Score, parent, and evidence changes:
  - `0001TN` `AddEmployeeItemDialogLayout`: `76/86`, parent blank -> `85/89`, parent `000006`. Added live IDA evidence for `0x004a3240`, hidden constructor bytes at `0x004a4ae0`, vtable stores at `0x006190d4/0x00619134/0x00619164`, adjustor thunks, destructor, and owner pointer layout.
  - Related `000006` `AddEmployeeItemDialog`: `82/88`, parent `0000J0` -> `85/89`, parent `0000J0`. Added live IDA evidence and layout-child gate rationale.
  - `0001TY` `ClanInputDialogLayouts`: `76/88`, parent blank -> `85/90`, parent `0000I8`. Added live IDA constructor/function bounds, ClanName/ClanAttr/ClanChange vtable stores, and cross-reference evidence; direct file parent `0000I8` clears gate while the narrower split candidate still does not clear confidence.
  - `0001VT` `ResourceLayoutNameRecord`: `85/89`, parent `0000BY` -> `86/90`, parent `0000BY`. Added live IDA recheck of `ImageLib::ImageLib`, `LoadResourceIndex`, accessors, `FindResourceIndex`, `g_pEPFLib`, and resource vtable refs.
  - `0001Y6` `ModelessDialogPaneVtables`: `85/90`, parent `00008K` -> `86/91`, parent `00008K`. Added live IDA recheck of constructor/event methods, three vtable stores, secondary-slot dispatch evidence, and tertiary handoff at `0x00618ce0`.
  - `0001TO` `AlertPaneLayout`: `78/87`, parent blank -> `85/89`, parent `0000HE`. Added live IDA evidence for AlertPane, VersatileAlertPane, BlueAlertPane, and UrlAlertPane constructors/destructors/vtable stores/callers.
  - Related `0000HE` `AlertPanes`: `82/86`, path unchanged -> `85/88`, path unchanged. Added live IDA evidence and readiness rationale for the alert-pane family.
- Validation:
  - Ran one file-mode validation loop from `source-3/project-documentation` over all changed documentation and coverage rows: `AddEmployeeItemDialogLayout.md`, `AddEmployeeItemDialog.md`, `ClanInputDialogLayouts.md`, `AlertPaneLayout.md`, `AlertPanes.md`, `ResourceLayoutNameRecord.md`, `ModelessDialogPaneVtables.md`, `by-type/by-struct/-coverage-report.md`, `by-type/by-vtable/-coverage-report.md`, `by-file/-coverage-report.md`, and `by-class/-coverage-report.md`.
  - Result: exit code 0; all 11 file-mode validations completed successfully. The first target reported `ok: 1`, `completion_update 0001TN ... 85`, `confidence_update 0001TN ... 89`, and `autogen_registry_update 0001TN ... -> 000006`; subsequent files completed successfully in the same loop.
  - Post-validation `rg` checks confirmed updated metadata headers and coverage rows for `0001TN`, `0001TY`, `0001VT`, `0001Y6`, `0001TO`, related `000006`, and related `0000HE`.
- Blockers and pending supervisor rows:
  - No remaining blockers. All five assigned items now clear the strict 85/85 documentation gate with evidence-backed direct parent choices.
  - `by-memory/-coverage-report.md` was not edited.
  - No associated by-memory docs were changed in this run, so there are no pending by-memory coverage-report replacement, insert, or delete rows for the supervisor to apply.

## Batch 179 A003 Report - 2026-06-11

- Assigned rows:
  - `0001FY` `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`
  - `0001FZ` `by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md`
  - `00023R` `by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md`
- Changed files:
  - `by-memory/0x005558d0-0x0055606d.VoteMenuPaneCore.md`
  - `by-memory/0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md`
  - `by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Leases used:
  - Successfully leased all three assigned by-memory pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
  - The initial edit leases expired before the final release command; a final notes-only lease was taken to record validation/release status.
- Exact score/status/parent changes:
  - [UID:0001FY] `VoteMenuPaneCore`: `85/88`, parent `0000P6` -> `86/89`, parent `0000P6`. Live IDA MCP reconfirmed raw constructor boundary, exact child function starts/sizes, `0xcc` boundary padding, vtable install/restore refs, singleton refs, and VoteMenu-only call edges.
  - [UID:0001FZ] `VoteMenuPaneHitTestAndSubmit`: `85/90`, parent `0000P6` -> `86/91`, parent `0000P6`. Live IDA MCP reconfirmed the two exact helper bodies, internal and post-submit padding, only-caller edges from `OnMouseEvent`, and hit-test/packet callee sets.
  - [UID:00023R] `CallbackAndListMembershipHelpers`: `82/88`, parent blank -> `85/90`, parent `0000KV`. Live IDA MCP reconfirmed raw helper bodies, exact padding, no modeled function starts, no pointer-table hits, the optional callback helper at `+0x8`, the base-chain walk through `+0x0c`, and the sole `0x004f4b2b` `LObject` runtime-shell tail jump. Direct file parent [UID:0000KV][LObject](../../../by-file/LObject.md) is `86/87`, and supporting class [UID:00007D][LObject](../../../by-class/LObject.md) is `86/87`, so the strict child/direct-parent gate clears.
- Validation commands/results:
  - Ran one file-mode validation loop from `source-3/project-documentation` over:
    - `by-memory\0x005558d0-0x0055606d.VoteMenuPaneCore.md`
    - `by-memory\0x00556070-0x00556211.VoteMenuPaneHitTestAndSubmit.md`
    - `by-memory\0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md`
  - Result: exit code 0. The first target reported `ok: 1`, `completion_update 0001FY ... 86`, and `confidence_update 0001FY ... 89`; the same loop completed successfully for the other two targets.
  - Post-validation `rg` checks confirmed headers: `0001FY` `86/89` parent `0000P6`, `0001FZ` `86/91` parent `0000P6`, and `00023R` `85/90` parent `0000KV`. `auto-generated/-ag-memory-coverage.md` now shows `00023R` assigned to `0000KV`.
- Supervisor-applied `by-memory/-coverage-report.md` replacements:
  - The supervisor applied and validated the Batch 179 replacement rows for [UID:0001FY], [UID:0001FZ], and [UID:00023R] on 2026-06-11. No pending `by-memory/-coverage-report.md` rows remain for this batch.

- Blockers:
  - No target blockers remain. All three assigned items clear at least `85/85`.
  - No pending supervisor coverage rows remain for this batch.

## Batch 183 A003 Report - 2026-06-11

- Assigned rows:
  - `0002TI` `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`
  - `0002YK` `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`
  - `0002YL` `by-memory/0x004c46d0-0x004c46fa.SoftwareRenderRgb565ExpandCallback.md`
- Changed files:
  - `by-memory/0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`
  - `by-memory/0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`
  - `by-memory/0x004c46d0-0x004c46fa.SoftwareRenderRgb565ExpandCallback.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after `--apply`:
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Leases used:
  - Successfully leased all three assigned by-memory pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
  - A005 had active leases on the immediately preceding RGB565 callback pages; A003 did not edit those leased files.
- Exact score/status/parent changes:
  - [UID:0002TI] `SoftwareRenderRgb565BitmaskBlitCallback`: `85/86`, parent `0000OC` -> `86/88`, parent `0000OC`. Live IDA MCP reconfirmed exact `sub_4C3EA0` bounds, no code callers, two target refs, twelve `dword_69B3F8` slot refs, 49 blocks / 445 instructions, clip/color/blend callees, `dword_67A7E0`, and the four-dword local switch island plus `0xcc` alignment.
  - [UID:0002YK] `SoftwareRenderRgb565FillCallback`: `85/88`, parent `0000OC` -> `86/90`, parent `0000OC`. Live IDA MCP reconfirmed exact `sub_4C4380` bounds, no code callers, two target refs, 206 `dword_69B3FC` slot refs, 47 blocks / 281 instructions, clip/color/blend-pair callees, `dword_67A7E0`, and the local switch island at `0x004c46c0-0x004c46d0`.
  - [UID:0002YL] `SoftwareRenderRgb565ExpandCallback`: `86/90`, parent `0000OC` -> `87/91`, parent `0000OC`. Live IDA MCP reconfirmed exact `sub_4C46D0` bounds, no callers/callees, two target refs, four `dword_69B400` slot refs, one block / eighteen instructions, exact channel-expansion disassembly, and six-byte `0xcc` padding before the adjacent pack callback.
  - Strict gate: all three children clear `85/85`, and direct parent [UID:0000OC][Surface](../../../by-file/Surface.md) remains `88/85`.
- Validation commands/results:
  - Ran one file-mode validation loop from `source-3/project-documentation` over:
    - `by-memory\0x004c3ea0-0x004c4364.SoftwareRenderRgb565BitmaskBlitCallback.md`
    - `by-memory\0x004c4380-0x004c46c0.SoftwareRenderRgb565FillCallback.md`
    - `by-memory\0x004c46d0-0x004c46fa.SoftwareRenderRgb565ExpandCallback.md`
  - Result: exit code 0. The first target reported `ok: 1`, `completion_update 0002TI ... 86`, and `confidence_update 0002TI ... 88`; the same loop completed successfully for the other two targets.
  - Post-validation `rg` checks confirmed headers: `0002TI` `86/88` parent `0000OC`, `0002YK` `86/90` parent `0000OC`, and `0002YL` `87/91` parent `0000OC`. `auto-generated/-ag-memory-coverage.md` still shows all three assigned to `0000OC`.
- Supervisor-applied `by-memory/-coverage-report.md` rows:
  - The Batch 183 rows for `0002TI`, `0002YK`, and `0002YL` were merged into the RGB565 callback block and validated by the supervisor on 2026-06-11.

- Blockers:
  - No target blockers remain. All three assigned items clear at least `85/85`.
  - No pending supervisor coverage rows remain for Batch 183.

## Batch 188 A003 Report - 2026-06-11

- Assigned rows:
  - `000242` `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`
  - `0001HU` `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `0001HV` `by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md`
- Changed files:
  - `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
  - `by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md`
  - `by-class/Socket.md`
  - `by-file/Socket.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased all three assigned by-memory pages, `by-class/Socket.md`, `by-file/Socket.md`, and this notes file before editing.
  - `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md` was leased by Agent-A005, so A003 did not edit it.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- Exact score/status/parent changes:
  - [UID:000242] `SocketEventDispatchHelpers`: `84/88`, parent blank -> `86/90`, `AUTOGEN_PARENT_UID:0000DD`, `RECONSTRUCTABLE:TRUE` unchanged.
  - [UID:0001HU] `QueueAndSendPacket`: `87/88`, parent blank -> `89/91`, `AUTOGEN_PARENT_UID:0000DD`, `RECONSTRUCTABLE:TRUE` unchanged.
  - [UID:0001HV] `SendRawDataRaw`: `85/88`, parent blank -> `86/89`, parent remains blank, `RECONSTRUCTABLE:TRUE` unchanged.
- IDA MCP evidence added:
  - Live 2026-06-11 `py_eval` reconfirmed exact starts/sizes, raw `0x00574b70` and `0x00574d00` non-function status, direct call targets, exact `0xcc` padding, no direct `.text` calls or loaded-segment dword pointers to the raw starts, and the 416-code-ref / 197-modeled-caller fan-in for `0x00574bb0`.
  - Live 2026-06-11 `decompile` of `0x00575e60` confirmed `Socket::HandleSocketCommand` consumes command IDs `3`, `4`, `5`, `6`, `8`, `13`, and `14`, matching the nearby queue-posting wrappers and supporting Socket ownership for `000242` and `0001HU`.
- Parent decisions:
  - `000242` and `0001HU` now attach to [UID:0000DD][Socket](../../../by-class/Socket.md): the children clear 85/85, direct parent Socket is `86/85`, and Socket file parent [UID:0000NS][Socket](../../../by-file/Socket.md) is `88/85`.
  - `0001HV` stays unassigned despite likely Socket semantics because there are still no caller/table/data/direct-call refs proving reachability of the unmodeled raw start.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Validation commands/results:
  - Ran one file-mode validation loop from `source-3/project-documentation` over:
    - `by-memory\0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`
    - `by-memory\0x00574bb0-0x00574c13.QueueAndSendPacket.md`
    - `by-memory\0x00574d00-0x00574d3f.SendRawDataRaw.md`
    - `by-class\Socket.md`
    - `by-file\Socket.md`
  - Result: exit code 0. The first target reported `ok: 1`, `completion_update 000242 ... 86`, `confidence_update 000242 ... 90`, and `autogen_registry_update 000242 ... -> 0000DD`; the same loop completed successfully for the other four files.
  - Post-validation checks confirmed headers: `000242` `86/90` parent `0000DD`, `0001HU` `89/91` parent `0000DD`, and `0001HV` `86/89` parent blank. `auto-generated/-ag-memory-coverage.md` now shows `000242` and `0001HU` assigned to `0000DD`, with `0001HV` still unassigned.

## Supervisor-Applied Batch 188 Shared Updates

- The supervisor applied and validated the `by-memory/-coverage-report.md` replacement rows for [UID:000242], [UID:0001HU], and [UID:0001HV] on 2026-06-11.
- The supervisor updated and validated `by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md` after A005 released it. The aggregate now records [UID:0001HU] as Socket-owned, [UID:0001HV] as likely Socket-semantic but unassigned due negative raw-start reachability, and the broad corridor as unresolved rather than settled CashShopRequest ownership.
- No Batch188 coverage-report or locked aggregate rows remain pending.

## Batch 191 A003 Report - 2026-06-11

- Assigned rows:
  - `0002LK` `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md`
  - `0002LN` `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
  - `0002LO` `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`
- Changed files:
  - `by-memory/0x00583280-0x005832e3.StringBaseWideFormatCtor.md`
  - `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
  - `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`
  - `by-memory/0x00583210-0x005845eb.SimpleUStringPointerBacked.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Supervisor-applied `by-memory/-coverage-report.md` replacements:
  - The supervisor applied and validated the Batch 191 replacement rows for `0002LK`, `0002LN`, and `0002LO` on 2026-06-11.
  - Supervisor rechecked the applied `0002LN` coverage row on 2026-06-13; it already uses "normalized `-1/0/1` return behavior", so no pending wording cleanup remains.
- IDA MCP evidence added:
  - Live 2026-06-11 read-only `py_eval`, `callees`, and `decompile` reconfirmed exact function bounds, padding, start-xref counts, caller-function counts, sentinel references, and callee/decompile behavior for all three assigned pages.
  - `StringBase` [UID:0000OA] is now `88/86`, so it clears the corrected parent gate for exact file-level helpers. The lower-completion `0001J2` aggregate remains an inventory page and was not used as the direct autogen parent.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` for all four changed by-memory pages.
  - Result: exit code 0 for the loop. The first target reported `ok: 1`, `completion_update 0002LK ... 85`, `confidence_update 0002LK ... 89`, and `autogen_registry_update 0002LK ... -> 0000OA`; subsequent files completed successfully in the same loop.
  - Post-validation checks confirmed headers: `0002LK` `85/89` parent `0000OA`, `0002LN` `87/91` parent `0000OA`, and `0002LO` `85/89` parent `0000OA`. `auto-generated/-ag-memory-coverage.md` now shows all three assigned to `0000OA`.

## Batch 195 A003 Report - 2026-06-11

- Assigned rows:
  - `0002L0` `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`
  - `0002L1` `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`
  - `0002L3` `by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md`
- Changed files:
  - `by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md`
  - `by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md`
  - `by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased all three assigned by-memory pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
  - The initial by-memory page leases expired before the final release command; a final notes-only lease was taken to complete this report block.
- IDA MCP evidence added:
  - Live 2026-06-11 read-only `py_eval` and `decompile` reconfirmed the exact function bounds, instruction/block counts, `0xcc` padding, caller/callee sets, and queue-slot field use for all three assigned pages.
  - The direct owner is [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md), not the broader queue-helper aggregate: `0002L0` is only called by `0002L1`, `0002L1` is only called by TimerMgrTimerQueue insert, and `0002L3` is the queue destructor called from TimerMgr teardown paths.
- Exact score/status/parent changes:
  - [UID:0002L0] `TimerQueueReverseRange`: `82/88`, parent blank -> `85/90`, parent `0000F2`.
  - [UID:0002L1] `TimerQueueRotateRange`: `82/88`, parent blank -> `85/90`, parent `0000F2`.
  - [UID:0002L3] `TimerMgrTimerQueueDestructor`: `84/90`, parent blank -> `86/91`, parent `0000F2`.
  - Strict gate: all three children clear 85/85, direct parent [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md) is `85/85`, context aggregate [UID:0001KA][TimerMgrQueueHelpers](../../../by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) is `85/87`, and file parent [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md) is `90/86`.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Validation:
  - Ran one file-mode validation loop from `source-3/project-documentation` over:
    - `by-memory\0x00597eb0-0x00597f17.TimerQueueReverseRange.md`
    - `by-memory\0x00597f20-0x00597fc9.TimerQueueRotateRange.md`
    - `by-memory\0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md`
  - Result: exit code 0. The first target reported `ok: 1`, `completion_update 0002L0 ... 85`, `confidence_update 0002L0 ... 90`, and `autogen_registry_update 0002L0 ... -> 0000F2`; the same loop completed successfully for the other two targets.
  - Post-validation checks confirmed headers: `0002L0` `85/90` parent `0000F2`, `0002L1` `85/90` parent `0000F2`, and `0002L3` `86/91` parent `0000F2`. `auto-generated/-ag-memory-coverage.md` now shows all three assigned to `0000F2`.
- Pending supervisor `by-memory/-coverage-report.md` replacements:
  - None. The supervisor applied and validated the Batch 195 `by-memory/-coverage-report.md` replacements for `0002L0`, `0002L1`, and `0002L3` on 2026-06-11.


## Batch 200 A003 Report - 2026-06-11

- Assigned rows:
  - `0001NU` `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
  - `0001NV` `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`
  - `0001NW` `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
- Changed files:
  - `by-memory/0x005c0460-0x005c0fe1.VirusChecker.md`
  - `by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`
  - `by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased all three assigned by-memory pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- IDA MCP evidence added:
  - Live 2026-06-11 read-only `tools/list`, `py_eval`, and `decompile` reconfirmed the exact VirusChecker modeled starts/extents, instruction/block counts, padding, raw non-function reset helper at `0x005c0770-0x005c07af`, callback refs, V3 DLL/export strings, V3 dynamic-library globals, vtable refs, and absence of direct runtime caller xrefs.
  - Direct owner is [UID:0000FW][VirusChecker](../../../by-class/VirusChecker.md), not the broad by-memory aggregate or file page: the target ranges are class-local singleton lifecycle, scanner load/scan, process/module callback, process-tree, and destructor helpers. [UID:0000FW] and source file [UID:0000P5][VirusChecker](../../../by-file/VirusChecker.md) both clear `86/85`.
- Exact score/status/parent changes:
  - [UID:0001NU] `VirusChecker`: `84/88`, parent blank -> `86/89`, parent `0000FW`.
  - [UID:0001NV] `VirusCheckerV3LoadAndScan`: `85/88`, parent blank -> `86/89`, parent `0000FW`.
  - [UID:0001NW] `VirusCheckerProcessTreeHelpers`: `84/90`, parent blank -> `85/91`, parent `0000FW`.
  - Strict gate: all three children clear 85/85, direct class parent [UID:0000FW][VirusChecker](../../../by-class/VirusChecker.md) is `86/85`, and source file parent [UID:0000P5][VirusChecker](../../../by-file/VirusChecker.md) is `86/85`.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Validation:
  - Ran one file-mode validation loop from `source-3/project-documentation` over:
    - `by-memory\0x005c0460-0x005c0fe1.VirusChecker.md`
    - `by-memory\0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md`
    - `by-memory\0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md`
  - Result: exit code 0. The first target reported `ok: 1`, `completion_update 0001NU ... 86`, `confidence_update 0001NU ... 89`, `autogen_registry_update 0001NU ... -> 0000FW`, and UID link insertions for `0000FW`/`0000P5`; the same loop completed successfully for the other two targets.
  - Post-validation checks confirmed headers: `0001NU` `86/89` parent `0000FW`, `0001NV` `86/89` parent `0000FW`, and `0001NW` `85/91` parent `0000FW`. `auto-generated/-ag-memory-coverage.md` now shows all three assigned to `0000FW`.
- Pending supervisor `by-memory/-coverage-report.md` replacements:
  - None. The supervisor applied and validated the Batch 200 `by-memory/-coverage-report.md` replacements for `0001NU`, `0001NV`, and `0001NW` on 2026-06-11.


## Batch 203 A003 Report - 2026-06-11

- Assigned rows:
  - `00024R` `by-memory/0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData.md`
  - `0002ON` `by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md`
  - `0002NG` `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
- Changed files:
  - `by-memory/0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData.md`
  - `by-memory/0x006104f4-0x00610980.MiniMapReadOnlyData.md`
  - `by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md`
  - `by-memory/0x00610ed8-0x00610f60.AboveFrameVtableData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased the three assigned by-memory pages and this `notes.md` before editing.
  - Leased new child `by-memory/0x006104f4-0x00610980.MiniMapReadOnlyData.md` after creation/validator UID assignment, before setting its metadata and score.
  - Took a final notes-only lease to preserve the exact coverage-row text as fenced literal blocks after the initial notes lease expired.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- IDA MCP evidence added:
  - Live 2026-06-11 `tools/list` and read-only `py_eval` reconfirmed the MiniMap-left `0x006104f4-0x00610980` child as size `0x48c`, with 40 names, 17 strings, MiniMapDialog/Downloader/ImageControlPane/SymbolControlPane/VersionManager vtable xrefs, the prior-page `0x006104f0` RTTI caveat, and the Ranking boundary at `0x00610980`.
  - The same pass reconfirmed `0002ON` as exact range `0x00610980-0x00610e38`, size `0x4b8`, with 28 names, five Ranking vtable families, constructor/destructor store xrefs, `Name`/`Score` at `0x00610e20`/`0x00610e2c`, and SoftwareBlend16 constants beginning at `0x00610e38`.
  - The same pass reconfirmed `0002NG` as exact range `0x00610ed8-0x00610f60`, size `0x88`, with three AboveFrame vtable bases, repeated vptr-store xrefs, no strings before the boundary, and UTF-16 `FRMPART.EPF` starting at `0x00610f60`.
- Exact score/status/parent decisions:
  - [UID:00024R] `MiniMapRankingReadOnlyData`: `80/88`, parent blank -> `85/90`, parent blank. This remains an unassigned mixed physical container over MiniMap, RankingDialog, and SoftwareBlend16 direct owners.
  - [UID:0003AS] new `MiniMapReadOnlyData`: created at `84/90`, parent blank. It is a nested child for the MiniMap-left portion but still spans MiniMap and MiniMapVersionManager source pages; the next precise split is at `0x006108d4`.
  - [UID:0002ON] `RankingDialogReadOnlyData`: `86/90`, parent blank -> `87/91`, parent `0000MZ`. Child and direct file parent [UID:0000MZ][RankingDialog](../../../by-file/RankingDialog.md) now clear the strict `85/85` gate.
  - [UID:0002NG] `AboveFrameVtableData`: `86/92`, parent `000005` -> `87/93`, parent `000005`. The direct class route is settled through [UID:000005][AboveFrame](../../../by-class/AboveFrame.md); only final declaration-shape audit remains.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` over all four changed by-memory pages.
  - Initial validation assigned new UID `0003AS` to `by-memory/0x006104f4-0x00610980.MiniMapReadOnlyData.md`; after leasing the new child, a second validation recorded `completion_update 0003AS ... 84`, `confidence_update 0003AS ... 90`, and `autogen_registry_update 0003AS ... blank -> true`.
  - Final validation recorded `completion_update 00024R ... 85`; all subsequent file validations returned `ok: 1`.
  - Post-validation generated coverage confirms `0002ON` assigned to `0000MZ`, `0002NG` assigned to `000005`, and `00024R`/`0003AS` unassigned.
- Supervisor-applied `by-memory/-coverage-report.md` edits:
  - The supervisor applied and validated the Batch 203 replacement/insert rows for [UID:00024R], [UID:0003AS], [UID:0002ON], and [UID:0002NG] on 2026-06-11.
  - No Batch 203 by-memory coverage rows remain pending.
- Next useful follow-up:
  - Split [UID:0003AS][0x006104f4-0x00610980.MiniMapReadOnlyData](../../../by-memory/0x006104f4-0x00610980.MiniMapReadOnlyData.md) at `0x006108d4` into assignable MiniMap and MiniMapVersionManager children, and consider later boundary repair that moves the `0x006104f0` MiniMapDialog RTTI locator out of the preceding LodePNG page.


## Blocked Rename Follow-Up

- None currently queued.

## Blocked IDA MCP Follow-Up

- Retry live IDA MCP for `0x005ae060` (`lookup_funcs`, `disasm`, `decompile`, `callers`, `callees`, `xrefs_to`, or a read-only `py_eval`) before editing [UID:0001KW][0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput](../../../by-memory/0x005ae060-0x005ae1a4.SpellStringInputPaneConfirmInput.md); `tools/list` returned 200 but `tools/call` probes timed out on 2026-06-06 and again on 2026-06-07.
- Retry live IDA MCP for `0x005b6c30` (`lookup_funcs`, `disasm`, `xrefs_to`, `callers`, `callees`, or read-only `py_eval`) before any confidence increase for [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](../../../by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md); `tools/list` returned 200 but `tools/call` `lookup_funcs` and minimal `py_eval` probes timed out on 2026-06-07.
- Retry live IDA MCP for `0x005b7360` (`lookup_funcs`, `disasm`, `xrefs_to`, `callers`, `callees`, or read-only `py_eval`) before any confidence increase for [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](../../../by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md); `tools/list` and `lookup_funcs` probes failed with `Unable to connect to the remote server` on 2026-06-07.
- Retry live IDA MCP for `0x00537ac0` (`lookup_funcs`, `disasm`, `xrefs_to`, `callers`, `callees`, or read-only `py_eval`) before any confidence increase beyond `82` for [UID:00023G][0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket](../../../by-memory/0x00537ac0-0x00537b39.StaticObjectPaneSendInteractionPacket.md); the MCP endpoint failed with `Unable to connect to the remote server` on 2026-06-07.

## Next Useful Work

- If new shared validator/generated follow-ups are added, apply only those completed items and remove their notes.
- If new `by-memory/-coverage-report.md` row follow-ups are added, apply them in address order when the report is free, then remove only completed row bullets.
- If shared files are leased, choose another unleased low-score by-memory page from `by-memory/-coverage-report.md`, gather IDA MCP evidence, update the page under lease, and add only the blocked shared follow-up here.


## Batch 209 A003 Report - 2026-06-11

- Assigned rows:
  - `000254` `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md`
  - `0002MC` `by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md`
  - `0002MD` `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md`
- Changed files:
  - `by-class/DialogPane.md`
  - `by-memory/0x006189dc-0x00618e50.DialogCoreReadOnlyData.md`
  - `by-memory/0x00618a60-0x00618b00.DialogPaneVtableData.md`
  - `by-memory/0x00618ce0-0x00618d2c.DialogFrameResourceStrings.md`
  - `by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md`
  - `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md`
  - `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md`
  - `by-memory/0x00618e70-0x00618efc.DirectXDiagnosticString.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased the three assigned by-memory pages, the containing DirectX/bitmap aggregate, [UID:00003T][DialogPane](../../../by-class/DialogPane.md), and this `notes.md` before editing.
  - Created missing child pages only after leasing the containing parent, then validated them to assign UIDs `0003AW`, `0003AX`, and `0003AY`.
  - Leased the new child pages after UID assignment before final metadata/content edits.
  - Took a final notes-only lease after the initial notes lease expired.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- IDA MCP evidence added:
  - Live 2026-06-11 read-only `tools/list` and `py_eval` reconfirmed `000254` as size `0x474` with 24 named items, exact DialogPane vtable data at `0x00618a60-0x00618b00`, exact DialogPane frame strings at `0x00618ce0-0x00618d2c`, the `0x00618d2c` DialogSession RTTI caveat, and `0x00618e50` DIBitmap boundary.
  - The same pass confirmed `0003AW` bases `0x00618a64`, `0x00618ac4`, and `0x00618af4`, constructor/cleanup vptr-store xrefs, and `0x00618afc` AlertPane RTTI boundary.
  - The same pass decoded `DLGFRAME.EPF`, `GFRAME.EPF`, `L01.PAL`, and `GFRAME.EPD` for `0003AX`, with DialogPane-frame xrefs from `0x0049f20d` through `0x0049f5ec`.
  - The same pass reconfirmed `0002MC` dwords `0x00618e50 -> 0x006467d0`, `0x00618e54 -> 0x004a1b10`, four DIBitmap-context vptr-store xrefs, and `0x00618e60` DirectX RTTI boundary.
  - The same pass reconfirmed `0002MD` dwords `0x00618e60 -> 0x0064681c`, `0x00618e64 -> 0x004a1cd0`, three DirectX-context vptr-store xrefs, and `0x00618e70` diagnostic-string boundary.
  - The same pass decoded `0003AY` as `DirectX not installed, or is corrupted. Please install DirectX again.`, confirmed xrefs at `0x004a1bfb` and `0x004a1c31`, and bounded it before `0x00618efc` EmployeeDialogPane RTTI.
- Exact score/status/parent decisions:
  - [UID:00003T] `DialogPane`: `82/84`, parent `0000IT` -> `85/86`, parent `0000IT`; parent gate repair for the new DialogPane vtable child.
  - [UID:000254] `DialogCoreReadOnlyData`: `84/90`, reconstructable true, parent blank -> `87/91`, reconstructable false, parent blank. This is now a reviewed non-reconstructable mixed `.rdata` index; exact children carry reconstructable ownership.
  - [UID:0003AW] new `DialogPaneVtableData`: created at `86/91`, parent `00003T`; strict child/direct-class gate clears `85/85`.
  - [UID:0003AX] new `DialogFrameResourceStrings`: created at `85/90`, parent `0000IT`; strict child/direct-file gate clears `85/85`.
  - [UID:000255] `DirectXBitmapReadOnlyData`: `80/90`, reconstructable false, parent blank -> `86/91`, reconstructable false, parent blank. This is a reviewed non-reconstructable mixed `.rdata` index over exact DIBitmap/DirectX children.
  - [UID:0002MC] `DIBitmapVtableData`: `86/92`, parent `00003V` -> `87/93`, parent `00003V`; strict child/direct-class gate remains clear.
  - [UID:0002MD] `DirectXVtableData`: `86/92`, parent `00003Y` -> `87/93`, parent `00003Y`; strict child/direct-class gate remains clear.
  - [UID:0003AY] new `DirectXDiagnosticString`: created at `85/91`, parent `0000IW`; strict child/direct-file gate clears `85/85`.
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` over `DialogPane`, the three new children, the three assigned rows, and `DirectXBitmapReadOnlyData`.
  - Result: every validation returned `ok: 1`.
  - Validator assigned UIDs `0003AW`, `0003AX`, and `0003AY`, applied the score/parent/reconstructable/reference-index updates listed above, and regenerated `auto-generated/-ag-memory-coverage.md`.
  - Post-validation generated coverage shows `0003AW` assigned to `00003T`, `0003AX` assigned to `0000IT`, `0002MC` assigned to `00003V`, `0002MD` assigned to `00003Y`, `0003AY` assigned to `0000IW`, and both aggregate rows `000254`/`000255` non-reconstructable.
- Blockers:
  - None for the assigned Batch 209 rows. The only residual boundary follow-up is optional: consider whether [UID:0002NB][DialogSessionVtableData](../../../by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) should later be widened or paired with a tiny boundary child for the `0x00618d2c-0x00618d30` DialogSession RTTI locator, because `0003AX` now ends exactly before that locator.
- Supervisor-applied `by-memory/-coverage-report.md` replacements/inserts:
  - The supervisor applied and validated the Batch 209 coverage rows for `000254`, `0003AW`, `0003AX`, `000255`, `0002MC`, `0002MD`, and `0003AY` on 2026-06-11.
  - No Batch 209 by-memory coverage rows remain pending.

## Batch 213 - Supervisor Coverage Rows Applied

- The supervisor applied and validated the Batch 213 `by-memory/-coverage-report.md` replacement/insert rows for [UID:00025C], [UID:0003BF], [UID:0003BG], [UID:00025D], [UID:0003BH], [UID:0003BI], [UID:00025E], [UID:0002MJ], [UID:0003BJ], [UID:00025F], and [UID:0002V3] on 2026-06-11.
- No Batch 213 by-memory coverage-report rows remain pending.text
    - [UID:00025C][0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData](by-memory/0x0061a45c-0x0061a5c4.FolderSelectTreeReadOnlyData.md) 0x0061a45c-0x0061a5c4 | mixed-rdata index | FolderSelectTreeReadOnlyData : ignored : 86% : strong : A003 Batch213 reclassifies this as a reviewed non-reconstructable physical `.rdata` index over exact FolderSelectDialog and FolderTreePane children; live IDA reconfirmed the `0x0061a45c-0x0061a4f4` FolderSelectDialog vtable child, `0x0061a4f4-0x0061a4fc` UTF-16 `X:\` child, existing Tree/TreeItor/FolderTreePane children, and `0x0061a5c4` TREEICON.EPF successor boundary.
        - [UID:0003BF][0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData](by-memory/0x0061a45c-0x0061a4f4.FolderSelectDialogVtableData.md) 0x0061a45c-0x0061a4f4 | vtable-data | FolderSelectDialogVtableData : reconstructable : 86% : strong : Exact FolderSelectDialog primary/secondary/tertiary vtable child; A003 2026-06-11 live IDA confirmed bases `0x0061a45c`/`0x0061a4bc`/`0x0061a4ec`, constructor/cleanup/destructor vptr-store refs, and `0x0061a4f4` string boundary; assigned to [UID:000059][FolderSelectDialog](by-class/FolderSelectDialog.md) after the class parent reached `85/86`.
        - [UID:0003BG][0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString](by-memory/0x0061a4f4-0x0061a4fc.FolderSelectDriveRootString.md) 0x0061a4f4-0x0061a4fc | string-data | FolderSelectDriveRootString : reconstructable : 85% : strong : Exact UTF-16 `X:\` drive-root literal; A003 2026-06-11 live IDA confirmed bytes `58 00 3a 00 5c 00 00 00`, constructor xref `0x004b173a`, and `0x0061a4fc` Tree RTTI boundary; assigned to [UID:0000JF][FolderSelectDialog](by-file/FolderSelectDialog.md).
    - [UID:00025D][0x0061a5dc-0x0061a61c.FontImageLibReadOnlyData](by-memory/0x0061a5dc-0x0061a61c.FontImageLibReadOnlyData.md) 0x0061a5dc-0x0061a61c | mixed-rdata index | FontImageLibReadOnlyData : ignored : 86% : strong : A003 Batch213 reclassifies this as a reviewed non-reconstructable physical `.rdata` index; live IDA split exact FolderTreePane path fragments [UID:0003BH][0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings](by-memory/0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings.md), existing FontImageLib vtable [UID:00031Q][0x0061a5f0-0x0061a600.FontImageLibVtableData](by-memory/0x0061a5f0-0x0061a600.FontImageLibVtableData.md), and FontImageLib `BARAM%02d.EFT` string [UID:0003BI][0x0061a600-0x0061a61c.FontImageLibResourcePatternString](by-memory/0x0061a600-0x0061a61c.FontImageLibResourcePatternString.md), with `0x0061a61c` FpsPane RTTI successor.
        - [UID:0003BH][0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings](by-memory/0x0061a5e0-0x0061a5ec.FolderTreePathFragmentStrings.md) 0x0061a5e0-0x0061a5ec | string-data | FolderTreePathFragmentStrings : reconstructable : 85% : strong : Exact FolderTreePane path/wildcard fragments; A003 2026-06-11 live IDA decoded `\`, `*.*`, and separator bytes, confirmed xrefs at `0x004b1f7a`, `0x004b1f95`, `0x004b1fa7`, and `0x004b278d`, and bounded the child between zero padding and FontImageLib RTTI; assigned to [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md).
        - [UID:0003BI][0x0061a600-0x0061a61c.FontImageLibResourcePatternString](by-memory/0x0061a600-0x0061a61c.FontImageLibResourcePatternString.md) 0x0061a600-0x0061a61c | string-data | FontImageLibResourcePatternString : reconstructable : 85% : strong : Exact UTF-16 `BARAM%02d.EFT` FontImageLib resource pattern; A003 2026-06-11 live IDA confirmed loader xref `0x004b6113`, previous FontImageLib vtable boundary, and `0x0061a61c` FpsPane RTTI successor; assigned to [UID:0000JH][FontImageLib](by-file/FontImageLib.md).
    - [UID:00025E][0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData](by-memory/0x0061a61c-0x0061a7dc.FpsPaneReadOnlyData.md) 0x0061a61c-0x0061a7dc | mixed-rdata index | FpsPaneReadOnlyData : ignored : 86% : strong : A003 Batch213 narrows this reviewed non-reconstructable index to the FpsPane-owned RTTI/vtable and diagnostic-string run, ending before the `0x0061a7dc` FrameHandler RTTI locator; exact children [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) and [UID:0003BJ][0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData](by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md) carry reconstructable ownership.
        - [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) 0x0061a61c-0x0061a6a4 | vtable-data | FpsPaneVtableData : reconstructable : 87% : strong : Exact FpsPane RTTI/vtable child; A003 2026-06-11 live IDA reconfirmed primary/secondary/timer bases, lifecycle-store xrefs, `0x0061a6a4` string boundary, and parent [UID:00005F][FpsPane](by-class/FpsPane.md) now clears `85/86`, so this child is assigned to the class.
        - [UID:0003BJ][0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData](by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md) 0x0061a6a4-0x0061a7dc | string-data | FpsPaneDiagnosticStringData : reconstructable : 86% : strong : Exact FpsPane diagnostic filename/mode/header/summary/object-count and overlay string data; A003 2026-06-11 live IDA decoded all strings, confirmed logging xrefs and `%5.1f FPS` xref `0x004b67f7`, and ended before `0x0061a7dc` FrameHandler RTTI; assigned to [UID:0000JK][FpsPane](by-file/FpsPane.md).
    - [UID:00025F][0x0061a7dc-0x0061aad4.FrameGrafPortReadOnlyData](by-memory/0x0061a7dc-0x0061aad4.FrameGrafPortReadOnlyData.md) 0x0061a7dc-0x0061aad4 | mixed-rdata index | FrameGrafPortReadOnlyData : ignored : 83% : strong : A003 Batch213 widens this reviewed non-reconstructable frame/GrafPort index to include the `0x0061a7dc` FrameHandler RTTI locator and reclassifies it as a non-emitting mixed `.rdata` container; exact children carry FrameMgr, FramePartPane, panel/GrafPort, Surface, and CachedHashTable ownership.
        - [UID:0002V3][0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData](by-memory/0x0061a7dc-0x0061a7f8.FrameHandlerFrameMgrVtableData.md) 0x0061a7dc-0x0061a7f8 | vtable-data | FrameHandlerFrameMgrVtableData : reconstructable : 87% : strong : Exact FrameHandler RTTI/vtable plus FrameMgr RTTI/vtable child; A003 2026-06-11 live IDA confirmed `0x0061a7dc -> 0x00647b28`, vtable bases `0x0061a7e0` and `0x0061a7ec`, FrameHandler/FrameMgr xrefs, and `0x0061a7f8` FramePartPane successor; assigned to [UID:0000JM][FrameMgr](by-file/FrameMgr.md).
```

## Batch 220 - Supervisor-Applied Coverage Rows

- The supervisor applied and validated the Batch 220 `by-memory/-coverage-report.md` replacement/insert rows for [UID:0002SK], [UID:0002SO], [UID:0002YS], [UID:0002YT], [UID:0003CC], [UID:0003CD], [UID:0003CE], and [UID:0003CB] on 2026-06-11.
- No Batch 220 by-memory coverage-report rows remain pending.


## Batch 226 A003 Report - 2026-06-11

- Assigned rows:
  - `00026M` `by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md`
  - `00026N` `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
  - `00026O` `by-memory/0x0062df94-0x0062e26c.TextEditReadOnlyData.md`
  - `00026Q` `by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md`
- Changed files:
  - `by-class/TimerHandler.md`
  - `by-memory/0x0062d5fc-0x0062da10.SystemMessageReadOnlyData.md`
  - `by-memory/0x0062d5fc-0x0062d6ac.SystemMessagePaneVtableData.md`
  - `by-memory/0x0062d6ac-0x0062d718.SystemMessageEntryVtableData.md`
  - `by-memory/0x0062d718-0x0062d7b4.ForcedInformMessageDialogVtableData.md`
  - `by-memory/0x0062d7b4-0x0062d8c8.NewSystemMessagePaneVtableData.md`
  - `by-memory/0x0062d8c8-0x0062d974.OldSystemMessagePaneVtableData.md`
  - `by-memory/0x0062d974-0x0062da10.SystemMessageResourceStrings.md`
  - `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`
  - `by-memory/0x0062da10-0x0062daac.TerminalPaneVtableData.md`
  - `by-memory/0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md`
  - `by-memory/0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md`
  - `by-memory/0x0062dbe4-0x0062dca8.PhoneBookListPaneVtableData.md`
  - `by-memory/0x0062dca8-0x0062dd44.PhoneEntryDialogVtableData.md`
  - `by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md`
  - `by-memory/0x0062dddc-0x0062df94.TerminalPhoneResourceStringsAndCallbackData.md`
  - `by-memory/0x0062df94-0x0062e26c.TextEditReadOnlyData.md`
  - `by-memory/0x0062df94-0x0062e048.TextEditPaneVtableData.md`
  - `by-memory/0x0062e048-0x0062e124.TextEditObjectTextBoxVtableData.md`
  - `by-memory/0x0062e124-0x0062e184.EPFTextEditObjectAndResourceStrings.md`
  - `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md`
  - `by-memory/0x0062e228-0x0062e26c.TextEditCommandStrings.md`
  - `by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md`
  - `by-memory/0x0062e338-0x0062e344.TimerHandlerVtableData.md`
  - `by-memory/0x0062e344-0x0062e354.TimerMgrVtableData.md`
  - `by-memory/0x0062e354-0x0062e3dc.TimerPaneVtableData.md`
  - `by-memory/0x0062e3dc-0x0062e460.TotemFrameVtableData.md`
  - `by-memory/0x0062e460-0x0062e480.TotemFrameResourceStringData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before editing and again after restart; no other agent leased Batch 226 target files.
  - Leased the four assigned broad by-memory pages, [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md), the existing [UID:0002OZ][TextFilterVtableData](../../../by-memory/0x0062e184-0x0062e18c.TextFilterVtableData.md) for possible supporting work, and this `notes.md` before edits.
  - Created missing child pages only after leasing the containing broad parents, then leased the new child pages after creation and before validation/follow-up edits.
  - Refreshed A003 leases after the long validator run and after the system restart before further edits.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- IDA MCP evidence added:
  - Live 2026-06-11 read-only `tools/list` and `py_eval` reconfirmed named heads, dwords/first slots, representative xrefs, string decoding, and successor boundaries for all assigned `.rdata` islands.
  - `00026M`: confirmed SystemMessagePane, header/footer/color entry, ForcedInformMessageDialog, NewSystemMessageModifyHeightPane/NewSystemMessagePane, OldSystemMessagePane vtable subranges, `MSGBORD.EPD`, `GBORD.EPD`, `HELP.RES`, `DLGSTAFF.*`, `SYSBAR.EPF`, `SBAR.EPF`, and `TerminalPane` successor.
  - `00026N`: confirmed TerminalPane, TerminalSetupPane, PhoneBookDialog, PhoneBookListPane, PhoneEntryDialog, DialDialog vtable children, `ATZ`, setup COM/speed strings, `DLGSETUP.EPD`, `PHONE.CFG`, `DLGTEL*.EPD`, `DLGDIAL.EPD`, `ATX3DT`, and `TextEditPane` successor.
  - `00026O`: confirmed TextEditPane, TextEditObject/TextEditScrap/TextBoxPane, EPFTextEditObject, existing TextFilter, TextPad, text-edit command/resource fragments, and `Thread` successor.
  - `00026Q`: confirmed TimerHandler, TimerMgr, TimerPane, TotemFrame vtable children, `TOTFRAME.EPD` xref, and `TransferServerDialogPane` successor.
- Exact score/status/parent decisions:
  - [UID:00026M] `SystemMessageReadOnlyData`: `88/91`, reconstructable true, parent blank -> `89/92`, reconstructable false, parent blank. It is a reviewed non-emitting mixed `.rdata` index.
  - [UID:0003DI] new `SystemMessagePaneVtableData`: `85/91`, parent blank; direct class [UID:0000EA] remains below `85/85`.
  - [UID:0003DJ] new `SystemMessageEntryVtableData`: `85/91`, parent blank; mixed over header/footer/color entry classes.
  - [UID:0003DK] new `ForcedInformMessageDialogVtableData`: `85/91`, parent blank; direct class [UID:00005E] is `86/84`, below gate.
  - [UID:0003DL] new `NewSystemMessagePaneVtableData`: `85/91`, parent blank; mixed over modify-height/new pane classes below gate.
  - [UID:0003DM] new `OldSystemMessagePaneVtableData`: `85/91`, parent blank; direct class [UID:00009T] remains below gate.
  - [UID:0003DN] new `SystemMessageResourceStrings`: `85/90`, parent blank; mixed system-message/forced-inform/status-bar string tail.
  - [UID:00026N] `TerminalPhoneReadOnlyData`: `84/90`, reconstructable true, parent blank -> `86/91`, reconstructable false, parent blank. It is a reviewed non-emitting mixed `.rdata` index.
  - [UID:0003DO] through [UID:0003DU] new terminal/phone children: all at least `85/90`, all parent blank because their direct class/file owners are either below gate or mixed.
  - [UID:00026O] `TextEditReadOnlyData`: `84/90`, reconstructable true, parent blank -> `86/91`, reconstructable false, parent blank. It is a reviewed non-emitting mixed `.rdata` index.
  - [UID:0003DV] new `TextEditPaneVtableData`: `86/91`, parent `0000EO`; child and direct class parent both clear `85/85`.
  - [UID:0003DW], [UID:0003DX], [UID:0003DY], and [UID:0003DZ]: new exact text-edit helper/textpad/string children, at least `85/90`, parent blank due mixed ownership or below-gate direct parents. Existing [UID:0002OZ] remains assigned to [UID:0001YY].
  - [UID:0000F0] `TimerHandler`: `84/86` -> `85/86`, parent `0000OT`; raised only enough to clear the exact vtable child gate using already documented method/vtable evidence plus the new exact child.
  - [UID:00026Q] `TimerTotemReadOnlyData`: `85/92`, reconstructable true, parent blank -> `87/93`, reconstructable false, parent blank. It is a reviewed non-emitting mixed `.rdata` index.
  - [UID:0003E0] new `TimerHandlerVtableData`: `86/92`, parent `0000F0`.
  - [UID:0003E1] new `TimerMgrVtableData`: `86/92`, parent `0000F1`.
  - [UID:0003E2] new `TimerPaneVtableData`: `86/92`, parent `0000F3`.
  - [UID:0003E3] new `TotemFrameVtableData`: `86/92`, parent `0000F4`.
  - [UID:0003E4] new `TotemFrameResourceStringData`: `85/92`, parent blank because direct resource/file parents remain below gate.
- Validator-owned generated/state side effects observed after `--apply`:
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - validator UID/autogen state updated by `tools/validator.py`
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` over all 23 new child pages, then over `TimerHandler`, `TimerHandlerVtableData`, and the four edited broad target pages.
  - Validator assigned UIDs `0003DI` through `0003E4`.
  - Post-restart header check confirmed all assigned targets and exact children have the score/reconstructable/parent states listed above.
  - Post-restart generated memory coverage check confirmed `00026M`, `00026N`, `00026O`, and `00026Q` are `not_reconstructable`; `0003DV`, `0002OZ`, `0003E0`, `0003E1`, `0003E2`, and `0003E3` are assigned to their direct parents; the below-gate/mixed children remain unassigned.
- Blockers:
  - No blocker for the four assigned Batch 226 targets; all assigned rows now clear `85/85` and are properly reclassified as non-emitting mixed indexes.
  - Several exact children intentionally remain unassigned because their direct class/file/resource parents are below the strict `85/85` gate or because the child itself is mixed over multiple direct owners.

### Supervisor-Applied `by-memory/-coverage-report.md` Replacement

- The supervisor applied and validated the Batch 226 replacement rows for [UID:00026M], [UID:0003DI], [UID:0003DJ], [UID:0003DK], [UID:0003DL], [UID:0003DM], [UID:0003DN], [UID:00026N], [UID:0003DO], [UID:0003DP], [UID:0003DQ], [UID:0003DR], [UID:0003DS], [UID:0003DT], [UID:0003DU], [UID:00026O], [UID:0003DV], [UID:0003DW], [UID:0003DX], [UID:0002OZ], [UID:0003DY], [UID:0003DZ], [UID:00026P], [UID:00026Q], [UID:0003E0], [UID:0003E1], [UID:0003E2], [UID:0003E3], and [UID:0003E4] on 2026-06-11.
- No Batch 226 by-memory coverage-report rows remain pending.

## Batch 231 A003 Report - 2026-06-11

- Assigned rows:
  - `0002ZN` `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`
  - `000289` `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md`
  - `00029Q` `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`
  - `00029T` `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
  - `00029J` `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md`
- Changed files:
  - `by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md`
  - `by-memory/0x00670268-0x00670294.StringBufferSentinelHeadersAndWhitespacePointer.md`
  - `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`
  - `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
  - `by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `current_leases.md` before editing; no Batch 231 target was leased by another agent.
  - Leased the five assigned target pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- IDA MCP evidence:
  - Live read-only `tools/list` and `py_eval` ran on 2026-06-11.
  - `0002ZN`: reconfirmed `0x0066db48 -> 0x0061e6f0`, bytes `f0 e6 61 00`, `aCmap` target bytes `43 4d 41 50 00`, only refs `0x00504ccf`/`0x00504f41`, and empty `0x0066db4c` refs.
  - `000289`: reconfirmed exact `0x00670260-0x006702a0` bytes, `0x00670278 -> 0x00670274`, `0x0067027c -> 0x0062d5d8`, `0x00670290 -> 0x0067028c`, `23`/`16` sentinel refs, `8` whitespace refs, UTF-16 `" \t\n\r"`, and `aNumberEpf` successor.
  - `00029Q`: reconfirmed all-`0xffffffff` storage, cleanup-only `3/2/2` refs inside `0x0060c160-0x0060c241`, no refs at `0x0069b381`/`0x0069b398`, separate `0x0069b3a8` MemoryMan refs, and `0x00419f40` cleanup-registration wrapper only.
  - `00029T`: reconfirmed bytes `ff ff ff ff`, six refs across initializer, main-menu writer, MapPane writer, auth/update reader, and cleanup, empty predecessor refs, and separate `0x0069b3d4` surface-flag successor.
  - `00029J`: reconfirmed all-`0xff` bytes from `0x0069b418-0x0069b430`, per-byte counts `4/6/132/0/0/0/4/0/4`, and the same cross-module loader/render grouping.
- Score/status/parent decisions:
  - [UID:0002ZN] `MapPaneCmapSignaturePointer`: `87/92`, parent `0000L3` -> `88/93`, parent `0000L3`; prior global/file repair remains current.
  - [UID:000289] `StringBufferSentinelHeadersAndWhitespacePointer`: `86/90`, parent blank -> `88/91`, parent `0000OA`; direct [UID:0000OA][StringBase](../../../by-file/StringBase.md) parent is `88/86`, and [UID:0000TM][StringBufferSentinelsAndPools](../../../by-global/StringBufferSentinelsAndPools.md) is the `92/89` semantic anchor.
  - [UID:00029Q] `StaticStringVectorStorage_69B39C`: `82/91`, parent blank -> `85/92`, parent blank; child now clears the local score gate, but no direct source owner is proven beyond compiler/static-lifetime cleanup glue.
  - [UID:00029T] `MainMenuTextUrlStaticString`: `85/91`, parent blank -> `86/92`, parent blank; split direct ownership remains MainMenuPane/MapPane/auth-update.
  - [UID:00029J] `ImageLibraryLoadErrorFlag`: `86/91`, parent blank -> `87/92`, parent blank; cross-module image-library flag remains without a single proven direct source owner.
- Validation:
  - Ran `tools/validator.py --mode file --file ... --apply --queue-timeout 180` for each of the five edited target pages.
  - Filtered confirmation after apply: all five returned `ok: 1`.
- Blockers:
  - None for the assigned documentation updates.
  - `00029Q`, `00029T`, and `00029J` remain intentionally unassigned because no single direct parent is justified, not because their child scores are below gate.

### Batch 231 Supervisor-Applied `by-memory/-coverage-report.md` Replacements

- The supervisor applied and validated the Batch 231 `by-memory/-coverage-report.md` replacement rows for [UID:0002ZN], [UID:000289], [UID:00029Q], [UID:00029T], and [UID:00029J] on 2026-06-11.
- No Batch 231 by-memory coverage-report rows remain pending.

## Batch 235 A003 Report - 2026-06-11

- Assigned rows:
  - `00029K` `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`
  - `00029H` `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`
  - `00029W` `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`
  - `00029X` `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`
- Changed files:
  - `by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md`
  - `by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md`
  - `by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md`
  - `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md`; no Batch 235 target was leased by another agent.
  - Leased the four assigned target pages and this `notes.md` before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- Live IDA MCP evidence:
  - `00029K`: 2026-06-11 `py_eval` reconfirmed all-`0xff` bytes over `0x0069b420-0x0069b43c`, refs `4/0/4` for `0x0069b424/0x0069b428/0x0069b42c`, `132` refs to the preceding flag, `11` refs to the riding table successor, and unchanged initializer/loader/fallback/cleanup sites.
  - `00029H`: reconfirmed all-`0xff` bytes over `0x0069b47c-0x0069b498`, zero predecessor refs, exact slot refs `5/12/5/5`, and Staffs/History successor refs `4/6`.
  - `00029W`: reconfirmed all-`0xff` bytes over `0x0069b4a0-0x0069b4c8`, predecessor refs `6`, target slot refs `6/6/7/20`, and successor start refs `6`.
  - `00029X`: reconfirmed all-`0xff` bytes over `0x0069b4a0-0x0069b4c8`, predecessor transfer-server refs `20`, exact target refs `6/6/5/6/18`, and successor refs `7`.
- Score/status/parent decisions:
  - [UID:00029K] `ImageLibraryFallbackRecord`: `85/90`, parent blank -> `86/91`, parent `0000LJ`. This is now assigned to direct [UID:0000LJ][MonsterImageLib](../../../by-file/MonsterImageLib.md) because the parent is `86/86` and explicitly documents the concrete storage; [UID:0000LK][MonsterImageLibTables](../../../by-file/MonsterImageLibTables.md) remains helper/type-shape context.
  - [UID:00029H] `MainMenuAccountDialogSingletons`: `88/91`, parent blank -> `89/92`, parent blank. It remains a mixed-owner account-dialog aggregate; exact children already carry direct parent assignments.
  - [UID:00029W] `MainMenuDialogSingletonSlots`: `88/91`, parent blank -> `89/92`, parent blank. It remains a mixed-owner pre-login dialog singleton aggregate; exact children carry direct parent assignments.
  - [UID:00029X] `MapNameMiniMapAndGameServerGlobals`: `88/90`, parent blank -> `89/91`, parent blank. It remains a mixed map UI/game-server data aggregate; exact five-slot children carry direct parent assignments.
- Validation:
  - Ran `tools/validator.py --mode file --file ... --apply --queue-timeout 180` for each of the four edited by-memory pages.
  - Filtered confirmation after apply: all four returned `ok: 1`; the first attempted multi-`--file` command processed only the final file, so each page was rerun individually.
- Blockers:
  - None for the assigned documentation updates.
  - `00029H`, `00029W`, and `00029X` intentionally remain unassigned because each aggregate is mixed-owner, not because any direct child gate is blocked.

### Batch 235 Supervisor-Applied `by-memory/-coverage-report.md` Replacements

- The supervisor applied and validated the Batch 235 `by-memory/-coverage-report.md` replacement rows for [UID:00029K], [UID:00029H], [UID:00029W], and [UID:00029X] on 2026-06-11.
- No Batch 235 by-memory coverage-report rows remain pending.

## Batch 242 A003 Report - 2026-06-12

- Assigned rows:
  - `00031V` `by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md`
  - `0002SU` `by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md`
  - `0002SV` `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`
  - `0001B2` `by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md`
- Changed files:
  - `by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md`
  - `by-memory/0x004ee6b0-0x004ef3fc.InventoryPane2CoreAndHelpers.md`
  - `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`
  - `by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md`
  - `by-class/InventoryPane2.md`
  - `by-class/UInt32Vector.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md`; no Batch 242 target or repaired parent was leased by another agent.
  - Leased the four assigned by-memory pages, `by-class/InventoryPane2.md`, `by-class/UInt32Vector.md`, and this `notes.md` before editing.
  - Did not edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- Live IDA MCP evidence:
  - Reconfirmed `0x004ee650` has no IDA function and no `xrefs_to`; bytes `0x004ee643-0x004ee650` are thirteen `0xcc`, bytes `0x004ee650-0x004ee6a7` are the complete constructor-shaped body, and bytes `0x004ee6a7-0x004ee6b0` are nine `0xcc`.
  - Reconfirmed `InventoryPane2` vtable refs at `0x0061c870`, `0x0061c8c0`, and `0x0061c8f0` from the raw constructor, `sub_4EE6B0`, and `sub_4EFA40`.
  - Reconfirmed modeled `InventoryPane2` core starts/ends for `sub_4EE6B0`, `sub_4EE6D0`, `nullsub_35`, `sub_4EE6F0`, `sub_4EEE60`, `sub_4EEEE0`, and `sub_4EF290`; decompile evidence documents paint list/grid behavior, mouse/event handling, opcode `0x66` drag packet construction, and opcode `0x59` popup packet handling.
  - Reconfirmed tail helper/thunk boundaries from `0x004ef630` through `0x004efa95`, no-function/no-xref raw starts at `0x004ef720` and `0x004ef7a0`, jump-table/padding bytes, helper caller/callee sets, and legacy/NewInventoryPane adjustor thunks at `0x004efa0a-0x004efa36`.
  - Reconfirmed `sub_514A10` at `0x00514a10-0x00514ab7`, map/world-map callers `0x00511f00` and `0x005c4df3`, callees `operator new`, `0x00421500`, and `__invalid_parameter_noinfo_noreturn`, plus header zeroing, count guard, small/large allocation split, 0x20-aligned large allocation metadata, fill loop, and end/capacity pointer updates.
- Score/status/parent decisions:
  - [UID:00031V] `InventoryPane2RawConstructor`: `82/88`, parent blank -> `85/89`, parent `00006S`.
  - [UID:0002SU] `InventoryPane2CoreAndHelpers`: `80/86`, parent blank -> `85/89`, parent `00006S`.
  - [UID:0002SV] `InventoryPane2TailHelpersAndDestructor`: `86/90`, parent blank -> `87/91`, parent blank. Child and class now clear `85/85`, but the broad range remains mixed over `InventoryPane2`, legacy `InventoryPane`, and `NewInventoryPane` thunk support, so assignment remains blocked until exact child splits.
  - [UID:00006S] `InventoryPane2`: `85/87`, parent `0000KA` -> `86/88`, parent `0000KA`.
  - [UID:0000FD] `UInt32Vector`: `82/86`, parent blank -> `85/87`, parent `0000P3`.
  - [UID:0001B2] `UInt32VectorConstructor`: `80/88`, parent blank -> `85/90`, parent `0000FD`.
- Validation:
  - Ran `tools/validator.py --mode file --file <edited by-* page> --apply --queue-timeout 180` sequentially over the four assigned by-memory pages plus `by-class/InventoryPane2.md` and `by-class/UInt32Vector.md`.
  - The validator command exited `0`; each file-mode validation returned `ok: 1`.
  - Validator-owned generated/state side effects were expected from `--apply`, including autogen registry/report/stat updates for the changed metadata. No generated/tool state file was manually edited.
- Blockers:
  - No blocker for the constructor/core `InventoryPane2` assignments or the `UInt32Vector` assignment chain.
  - `0002SV` remains intentionally unassigned because the page is a mixed broad island. Next useful repair is exact child pages for `0x004ef630-0x004ef702`, `0x004ef720-0x004ef792`, `0x004ef7a0-0x004ef86b`, `0x004ef890-0x004ef962`, `0x004ef970-0x004ef9f4`, `0x004ef9f4-0x004efa0a`, `0x004efa0a-0x004efa20`, `0x004efa20-0x004efa36`, and `0x004efa40-0x004efa95`.

### Batch 242 Supervisor-Applied `by-memory/-coverage-report.md` Replacements

- The supervisor applied and validated the Batch 242 replacement rows for [UID:00031V], [UID:0002SU], [UID:0002SV], and [UID:0001B2].
- No Batch 242 coverage-report rows remain pending.
- Follow-up remains active for [UID:0002SV]: it is `87/91` but still a mixed broad island, so A003 was instructed to continue exact split/repair work before taking a new batch.

## Stale `0x00593d00-0x00593e6b` Split Recheck - 2026-06-12

- Supervisor nudge named `0002SV` but gave path `by-memory/0x00593d00-0x00593e6b.FittingRoomPreviewOwnerTableAndTail.md`. Current docs/reports still identify [UID:0002SV][0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor](../../../by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md); the requested `0x00593d00-0x00593e6b` page does not exist and is a stale generated FittingRoom projection inside the TextEditPane callback neighborhood.
- Changed files:
  - `by-memory/0x00593c20-0x00593ce4.TextRunMeasureCallback.md`
  - `by-memory/0x00593cf0-0x00593dad.TextRunMeasureCallbackThiscallRaw.md`
  - `by-memory/0x00593db0-0x00593ef5.DrawTextRunCallback.md`
  - `by-memory/0x00593f00-0x0059403b.DrawTextRunCallbackThiscallRaw.md`
  - `by-memory/0x00594040-0x00594e11.TextEditPaneInputNavigationAndWrap.md`
  - `by-memory/-ignored.md`
  - `by-file/TextEditPane.md`
  - `by-class/TextEditPane.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Leased the two existing callback pages, the TextEditPane file/class pages, `TextEditPaneFormattingRuns` for context, `TextEditPaneInputNavigationAndWrap`, `by-memory/-ignored.md`, and this `notes.md`.
  - Created the missing raw callback children only after the containing neighborhood was leased, then leased the new child files before validation/follow-up.
  - Did not edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- Live IDA MCP evidence:
  - `lookup_funcs` confirms `sub_593C20` at `0x00593c20-0x00593ce5`, `sub_593DB0` at `0x00593db0-0x00593ef6`, and `sub_594040` at `0x00594040`; no function exists at `0x00593cf0`, `0x00593d00`, `0x00593f00`, `0x00594035`, or `0x00594036`.
  - `xrefs_to 0x00593d00` reports only a local branch from `0x00593cfc` inside the raw measurement body; `xrefs_to 0x00593cf0` and `0x00593f00` report no direct raw-start references.
  - Disassembly proves `0x00593cf0-0x00593dad` is a raw TextEditPane measurement callback variant using `ecx` as the editor object and ending with `retn 1Ch`; `0x00593f00-0x0059403b` is a raw TextEditPane draw callback variant using `ecx`, GrafPort/text-render/style dispatch helpers, and ending with `retn 1Ch`.
  - Byte audit confirmed padding as `0x00593ce5-0x00593cf0` eleven `0xcc`, `0x00593dad-0x00593db0` three `0xcc`, `0x00593ef6-0x00593f00` ten `0xcc`, and `0x0059403b-0x00594040` five `0xcc`.
- Score/status/parent decisions:
  - [UID:0001JQ] `TextRunMeasureCallback`: `76/84` -> `85/88`, parent kept `0000ON`; child and direct file parent [UID:0000ON][TextEditPane](../../../by-file/TextEditPane.md) `88/85` clear the strict gate.
  - [UID:0003FC] new `TextRunMeasureCallbackThiscallRaw`: `85/88`, parent `0000EO`; child and direct class parent [UID:0000EO][TextEditPane](../../../by-class/TextEditPane.md) `88/85` clear the strict gate.
  - [UID:0001JR] `DrawTextRunCallback`: `78/86` -> `85/88`, parent kept `0000ON`; child and direct file parent `88/85` clear the strict gate.
  - [UID:0003FD] new `DrawTextRunCallbackThiscallRaw`: `85/88`, parent `0000EO`; child and direct class parent `88/85` clear the strict gate.
  - [UID:0001JS] `TextEditPaneInputNavigationAndWrap`: score/parent unchanged at `82/86`, parent `0000ON`; evidence now records the exact raw draw child and five-byte padding before this range.
  - `by-memory/-ignored.md` records the four exact `0xcc` padding spans.
- Validation:
  - Ran `tools/validator.py --mode file --file ... --apply --queue-timeout 180` on the two new child pages; validator assigned UIDs `0003FC` and `0003FD`.
  - Ran file-mode validation with `--apply --queue-timeout 180` over the two existing callback pages, `by-file/TextEditPane.md`, `by-class/TextEditPane.md`, `TextEditPaneInputNavigationAndWrap`, and `by-memory/-ignored.md`.
  - Each validation command exited `0`; follow-up `rg` confirmed no `TMP` references remain in the edited pages.
  - Validator-owned generated/state side effects were expected from `--apply` (`auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and validator UID/autogen state). No generated/tool state file was manually edited.
- Blockers:
  - No valid FittingRoom split exists for `0x00593d00-0x00593e6b`; that stale slice starts inside the raw TextEditPane measurement variant and ends inside the cdecl draw callback.
  - No direct blocker remains for the exact TextEditPane split. Final C++ is intentionally blank because the source-facing callback signatures and callback-state layouts remain below the 95/95 code-emission bar.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows

- The supervisor applied and validated the stale TextEditPane split replacement block for [UID:0001JQ], [UID:0003FC], [UID:0001JR], [UID:0003FD], [UID:0001JS], and the related padding rows on 2026-06-12.
- No stale TextEditPane split coverage-report rows remain pending.

## Batch 248 A003 Report - 2026-06-12

- Assigned row:
  - `0002SV` `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`
- Changed files:
  - `by-memory/0x004ef630-0x004efa95.InventoryPane2TailHelpersAndDestructor.md`
  - `by-class/InventoryPane2.md`
  - `by-file/InventoryPane.md`
  - `by-memory/0x004ea130-0x004efbb7.InventoryPanes.md`
  - `by-memory/-ignored.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md`; no active leases were present before editing.
  - Leased the target broad page, `InventoryPane2` class, `InventoryPane` file, `InventoryPanes` aggregate, `by-memory/-ignored.md`, and this `notes.md` before edits.
  - Did not edit `by-memory/-coverage-report.md` because the supervisor ban remains active.
- Live IDA MCP evidence:
  - `lookup_funcs` reconfirmed `sub_4EF630` `0x004ef630-0x004ef702`, no functions at `0x004ef702`, `0x004ef720`, `0x004ef794`, `0x004ef7a0`, `0x004ef86d`, `sub_4EF890` `0x004ef890-0x004ef962`, `sub_4EF970` `0x004ef970-0x004ef9f4`, six `0xb` adjustor thunks through `0x004efa36`, `sub_4EFA40` `0x004efa40-0x004efa95`, and successor `sub_4EFAA0` at `0x004efaa0`.
  - `xrefs_to` reconfirmed five callers for `0x004ef630`, no direct xrefs to raw starts `0x004ef720`/`0x004ef7a0`, three callers for `0x004ef890`, two callers for `0x004ef970`, vtable-slot refs for the six adjustor thunks, and `0x004efa40` refs from the two `InventoryPane2` adjustors plus the primary vtable.
  - Byte audit confirmed the switch-table/padding spans: `0x004ef702-0x004ef720`, `0x004ef794-0x004ef7a0`, `0x004ef86d-0x004ef890`, `0x004ef962-0x004ef970`, `0x004efa36-0x004efa40`, and `0x004efa95-0x004efaa0`.
- Score/status/parent decisions:
  - [UID:0002SV] `InventoryPane2TailHelpersAndDestructor`: `87/91`, reconstructable true, parent blank -> `89/92`, reconstructable false, parent blank. It is now a reviewed non-emitting split-audit container.
  - [UID:00006S] `InventoryPane2`: `86/88` -> `87/89`, parent `0000KA`; exact source-bearing tail children now route to this direct class parent.
  - [UID:0000KA] `InventoryPane`: unchanged `85/86`, parent metadata not applicable; updated to reference exact `InventoryPane2` tail children.
  - [UID:00018J] `InventoryPanes`: unchanged `85/88`, reconstructable false, parent blank; updated aggregate/source-map wording for the completed `InventoryPane2` tail split and corrected raw constructor assignment status.
  - `by-memory/-ignored.md`: added grouped ignored-ledger entry for the InventoryPane2 tail switch tables, ABI adjustor thunks, and padding spans.
  - Existing exact child score/parent states were preserved: source-bearing [UID:0003EJ], [UID:0003EL], [UID:0003EM], [UID:0003EO], [UID:0003EP], and [UID:0003ER] stay assigned to [UID:00006S][InventoryPane2](../../../by-class/InventoryPane2.md); non-emitting [UID:0003EK], [UID:0003EN], [UID:0003EQ], [UID:0003ES], and [UID:0003ET] stay parent blank.
- Validation:
  - Ran `tools/validator.py --mode file --file ... --apply --queue-timeout 180` over the target page, `InventoryPane2`, `InventoryPane`, `InventoryPanes`, and `by-memory/-ignored.md`; each returned `ok: 1`.
  - Re-ran the validator on the target page after a wording correction; it returned `ok: 1`.
  - Validator recorded `0002SV` completion/confidence `89/92`, `RECONSTRUCTABLE true -> false`, and `00006S` completion/confidence `87/89`.
  - Validator-owned generated/state side effects were expected from `--apply`, including autogen registry/report/stat updates. No generated/tool state file was manually edited.
- Blockers:
  - No split blocker remains for [UID:0002SV]; exact child pages already exist and were integrated into the parent/supporting docs.
  - Final C++ remains blocked by final field/helper names, source-level destructor shape, and raw-helper source-retention/reachability decisions, not by by-structure split state.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows

- The supervisor applied and validated the Batch 248 replacement block for [UID:0002SV] and its exact child/padding rows on 2026-06-12.
- No Batch 248 `by-memory/-coverage-report.md` rows remain pending.

## Batch 255 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003AK] `by-memory/0x0060d798-0x0060d7e0.CashShopDownloaderVtables.md`
- Changed files:
  - Renamed `by-memory/0x0060d798-0x0060d7e0.CashShopDownloaderVtables.md` -> `by-memory/0x0060d794-0x0060d7e0.CashShopDownloaderVtables.md`
  - Renamed `by-memory/0x0060d798-0x0060e174.CashShopFittingRoomReadOnlyData.md` -> `by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md`
  - Renamed `by-memory/0x0060d670-0x0060d798.MsvcRdataStartupTables.md` -> `by-memory/0x0060d670-0x0060d794.MsvcRdataStartupTables.md`
  - Created `by-memory/0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md`
  - Created `by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md`
  - Created `by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md`
  - Updated `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
  - Updated `by-memory/0x0060d7e0-0x0060d9c4.CashShopDownloaderLiterals.md`
  - Updated `by-memory/0x0060d9c4-0x0060e174.FittingRoomReadOnlyData.md`
  - Updated `by-memory/-ignored.md`
  - Updated `by-class/CashShopVersionRequest.md`, `by-file/CashShopVersionRequest.md`
  - Updated `by-class/CashShopRequest.md`, `by-file/CashShopRequest.md`
  - Updated `by-class/FileDownloader.md`, `by-file/FileDownloader.md`
  - Updated this `notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Leased the assigned target, containing `.rdata` aggregate, adjacent MSVC prelude, `.rdata` section page, literal/FittingRoom siblings, CashShop/FileDownloader class/file parents, `by-memory/-ignored.md`, and this `notes.md`.
  - Created the three child pages only after leasing the containing broad page; validator assigned UIDs [UID:0003FR], [UID:0003FS], and [UID:0003FT].
  - Did not manually edit `by-memory/-coverage-report.md`; validator path maintenance did update some UID link annotations while applying renamed UID paths, and the supervisor later applied and validated the needed replacement rows.
- Live IDA MCP evidence:
  - `idb_meta` confirmed `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` / sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `lookup_funcs` confirmed `sub_41B5E0` size `0x24`, `sub_41B570` size `0x6b`, `sub_41B610` size `0x8f`, `sub_41B110` size `0x70`, raw non-function `0x0041a5d0`, and modeled `sub_41A6F0` size `0x51`.
  - Read-only `py_eval` dword/xref scan proved `0x0060d794 -> ??_R4CashShopVersionRequest@@6B@`, `0x0060d798 -> sub_41B5E0`, `0x0060d79c -> ??_R4CashShopRequest@@6B@`, `0x0060d7a0 -> sub_41B570`, `0x0060d7a4 -> ??_R4FileDownloader@@6B@`, `0x0060d7a8 -> sub_41B610`, inherited `FileDownloader` slots through `0x0060d7dc`, and `0x0060d7e0` as `szAgent`.
  - Xrefs reconfirmed two refs to the `CashShopVersionRequest` slot, four refs to the `CashShopRequest` slot, three refs to the `FileDownloader` slot, and `0x0060d7d4` as the `FileDownloader::OnMessage` slot.
- Score/status/parent decisions:
  - [UID:0003AK] `CashShopDownloaderVtables`: `85/90`, `RECONSTRUCTABLE:TRUE`, range `0x0060d798-0x0060d7e0`, parent blank -> `88/92`, `RECONSTRUCTABLE:FALSE`, corrected range `0x0060d794-0x0060d7e0`, parent blank. It is now a non-emitting split-audit container.
  - [UID:0003FR] new `CashShopVersionRequestVtableData`: `86/92`, parent [UID:00001I][CashShopVersionRequest](../../../by-class/CashShopVersionRequest.md).
  - [UID:0003FS] new `CashShopRequestVtableData`: `86/92`, parent [UID:00001H][CashShopRequest](../../../by-class/CashShopRequest.md).
  - [UID:0003FT] new `FileDownloaderVtableData`: `88/93`, parent [UID:00004W][FileDownloader](../../../by-class/FileDownloader.md).
  - [UID:00001I] `CashShopVersionRequest`: `82/88` -> `85/89`; [UID:0000I1] `CashShopVersionRequest` file: `82/86` -> `85/87`.
  - [UID:00001H] `CashShopRequest`: `82/86` -> `85/88`; [UID:0000I0] `CashShopRequest` file: `82/86` -> `85/87`.
  - [UID:00004W] `FileDownloader`: `84/88` -> `85/89`; [UID:0000JC] `FileDownloader` file remains `85/88` with exact vtable evidence added.
  - [UID:00024L] `MsvcRdataStartupTables`: `80/85`, range `0x0060d670-0x0060d798` -> `82/87`, range `0x0060d670-0x0060d794`.
  - [UID:00024M] `CashShopFittingRoomReadOnlyData`: `87/91`, range `0x0060d798-0x0060e174` -> `88/92`, range `0x0060d794-0x0060e174`.
- Validation:
  - Ran `tools/validator.py --mode file --file ... --apply --queue-timeout 180` first on the three new child pages to allocate UIDs.
  - Ran the same file-mode validator over the renamed broad pages, new children, section page, literal/FittingRoom siblings, ignored ledger, and CashShop/FileDownloader class/file parents.
  - Each validator invocation exited `0`; edited file-mode passes returned `ok: 1`.
  - Validator-owned generated/state side effects were expected from `--apply`; no tool/config/state file was manually edited.
- Blockers:
  - No split blocker remains for [UID:0003AK]. Exact vtable children exist and route to direct class parents that clear the strict `85/85` gate.
  - Final C++ remains blank for all new vtable pages because final source-facing class/base declarations, inherited `FileDownloader` virtual names, and downloader/request singleton naming remain below the final-code threshold.

### Supervisor-Applied Coverage Report Rows For Batch 255

- The supervisor applied and validated the Batch 255 `by-memory/-coverage-report.md` replacement block for [UID:00024L], [UID:00024M], [UID:0003AK], and new children [UID:0003FR]-[UID:0003FT] on 2026-06-12.
- The supervisor applied and validated the Batch 255 `by-class/-coverage-report.md` rows for [UID:00001H], [UID:00001I], and [UID:00004W] on 2026-06-12.
- The supervisor applied and validated the Batch 255 `by-file/-coverage-report.md` rows for [UID:0000I0], [UID:0000I1], and [UID:0000JC] on 2026-06-12.
- No Batch 255 supervisor-owned coverage/report rows remain pending.

## Batch 261 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003AL] `by-memory/0x0060d7e0-0x0060d9c4.CashShopDownloaderLiterals.md`
- Changed files:
  - Renamed `by-memory/0x0060d7e0-0x0060d9c4.CashShopDownloaderLiterals.md` -> `by-memory/0x0060d7e0-0x0060d9c0.CashShopDownloaderLiterals.md`
  - Renamed `by-memory/0x0060d9c4-0x0060e174.FittingRoomReadOnlyData.md` -> `by-memory/0x0060d9c0-0x0060e174.FittingRoomReadOnlyData.md`
  - Created `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`
  - Created `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
  - Created `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md`
  - Created `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`
  - Created `by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md`
  - Updated `by-memory/0x0060d794-0x0060e174.CashShopFittingRoomReadOnlyData.md`
  - Updated `by-file/FileDownloader.md`
  - Updated `by-file/FittingRoom.md`
  - Updated this `notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before editing; no active conflicting lease covered the Batch 261 files.
  - Leased the assigned literal page, containing mixed `.rdata` aggregate, FittingRoom suffix sibling, FileDownloader/FittingRoom file parents, and this `notes.md`.
  - Created the five exact child pages after leasing the containing broad page, then leased the new paths once they existed. Validator assigned UIDs [UID:0003FY], [UID:0003FZ], [UID:0003G0], [UID:0003G1], and [UID:0003G2].
  - Did not manually edit `by-memory/-coverage-report.md`. Validator path maintenance updated UID link paths for renamed `0003AL`/`0003AM`; the supervisor later applied and validated the needed replacement rows.
- Live IDA MCP evidence:
  - `idb_meta` confirmed `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` / sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - The literal block decodes as UTF-16LE `HTTPTEST`, minimap `000`/`%03d`/`.mnm`/S3 URL/format/progress strings, KRU `itemshop.ver`, item-shop progress text, narrow ASCII `version`, and KRU `itemshop.json`.
  - Xrefs split ownership: `HTTPTEST` has FileDownloader, MiniMapDownloader, and raw MiniMap-side refs; minimap literals have FileDownloader message `10000` and MiniMapDownloader refs; `itemshop.ver` and `itemshop.json` land in `DownloadCashShopVersion` / `DownloadCashShopCatalog`; the narrow `version` key has FileDownloader, FittingRoom item-state, and StartupWindow refs.
  - Boundary audit proved `0x0060d958-0x0060d9be` is the wide `itemshop.json` literal, `0x0060d9be-0x0060d9c0` is zero alignment, and `0x0060d9c0 -> ??_R4FittingRoomDownloadControlPane@@6B@`. Therefore the downloader literal container ends at `0x0060d9c0`, and the FittingRoom suffix starts at `0x0060d9c0`.
- Score/status/parent decisions:
  - [UID:0003AL] `CashShopDownloaderLiterals`: `85/90`, reconstructable true, range `0x0060d7e0-0x0060d9c4`, parent blank -> `89/92`, reconstructable false, range `0x0060d7e0-0x0060d9c0`, parent blank. It is now a non-emitting split-audit container.
  - [UID:0003FY] new `SharedDownloaderUserAgentWideString`: `86/92`, parent blank because direct refs span FileDownloader, MiniMapDownloader, and raw MiniMap-side code.
  - [UID:0003FZ] new `MinimapDownloadWideLiterals`: `87/92`, parent blank because both FileDownloader message `10000` and MiniMapDownloader worker paths consume the literals.
  - [UID:0003G0] new `CashShopVersionDownloadWideLiterals`: `86/91`, parent [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md); child and direct parent `85/88` clear the strict gate.
  - [UID:0003G1] new `SharedVersionJsonKey`: `87/92`, parent blank because refs span FileDownloader item-shop parsing, FittingRoom encoded catalog-state parsing, and StartupWindow update parsing.
  - [UID:0003G2] new `CashShopCatalogDownloadWideUrl`: `86/92`, parent [UID:0000JC][FileDownloader](../../../by-file/FileDownloader.md); sole direct code ref is the FileDownloader-dispatched catalog helper and the successor boundary is FittingRoom RTTI data.
  - [UID:0003AM] `FittingRoomReadOnlyData`: `86/90`, range `0x0060d9c4-0x0060e174` -> `87/91`, range `0x0060d9c0-0x0060e174`, parent remains [UID:0000JE][FittingRoom](../../../by-file/FittingRoom.md).
  - [UID:00024M] `CashShopFittingRoomReadOnlyData`: `88/92` -> `89/92`, parent blank, reconstructable false. It remains a mixed non-emitting index and now links the exact literal children plus the corrected FittingRoom suffix.
  - [UID:0000JC] `FileDownloader` and [UID:0000JE] `FittingRoom` file scores remain `85/88` and `85/87`; both were updated only for supporting evidence and cross-links.
- Validation:
  - Ran `python source-3/project-documentation/tools/validator.py --mode file --file ... --apply --queue-timeout 180` over `0003AL`, the five new child pages, `00024M`, `0003AM`, `by-file/FileDownloader.md`, and `by-file/FittingRoom.md`.
  - Each invocation exited `0` with `ok: 1`. The first `0003AL` pass updated the registered path from `0x0060d7e0-0x0060d9c4` to `0x0060d7e0-0x0060d9c0` and recorded the expected stale coverage-report rows; a follow-up `rg` found no stale old-range links in edited by-* docs.
  - Remaining stale `0x0060d9c4` range text is limited to historical Batch 255 notes and the supervisor-owned `by-memory/-coverage-report.md` rows listed below.
  - Validator-owned generated/state side effects were expected from `--apply`, including autogen registry/report/stat updates. No generated/tool config/state file was manually edited.
- Blockers:
  - No Batch 261 split blocker remains. The supervisor later applied and validated the coverage-report replacement block recorded below.
  - Final C++ remains blank because these are source data literals/vtables and final source-facing string ownership/layout decisions remain below the final-code threshold for the shared literals.

### Supervisor-Applied `by-memory/-coverage-report.md` Rows For Batch 261

- The supervisor applied and validated the Batch 261 replacement block for [UID:00024M], [UID:0003AL], new children [UID:0003FY]-[UID:0003G2], and corrected [UID:0003AM] on 2026-06-12.
- No Batch 261 supervisor-owned coverage-report rows remain pending.

## Batch 268 A003 Report - 2026-06-12

- Assigned row:
  - [UID:000355] `by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`
- Changed files:
  - `by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md`
  - `by-class/ObjectInfoObjectPane.md`
  - `by-file/AttachedObjectPane.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; no active conflicting lease covered the target/support files.
  - Leased the target vtable child, direct class parent, owning file root, containing ObjectPane read-only-data aggregate, and this `notes.md`.
  - Did not manually edit `by-memory/-coverage-report.md`; exact pending replacement row is below.
- Live IDA MCP evidence:
  - `idb_meta` confirmed `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` / sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` rechecked the three `ObjectInfoObjectPane` RTTI/vtable views: primary `0x0062089c-0x00620914`, adjusted view `0x00620914-0x00620944`, and adjusted view `0x00620944-0x00620950`.
  - Constructor `sub_5395B0` stores the vtable bases at `0x005395df`, `0x005395e5`, and `0x005395ef`. First slots target `sub_53D620`, `sub_53CF5C`, and `sub_53CF67`.
  - Primary-table ObjectInfo override slots include `0x00539760`, `0x005398e0`, `0x00539b20`, and `0x00539700`.
  - Boundary audit confirms predecessor [UID:000354] ends at `0x0062089c` and successor [UID:000356] starts at `0x00620950 -> ??_R4Motion@@6B@`.
- Score/status/parent decisions:
  - [UID:000355] `ObjectInfoObjectPaneVtableData`: `85/88`, parent blank -> `88/92`, parent [UID:00009P][ObjectInfoObjectPane](../../../by-class/ObjectInfoObjectPane.md).
  - [UID:00009P] `ObjectInfoObjectPane`: unchanged `85/89`; evidence updated to record the exact vtable child now routing directly to the class.
  - [UID:0000HJ] `AttachedObjectPane`: unchanged `86/86`; evidence updated to include exact ObjectInfo vtable child/source-root support.
  - [UID:000260] `ObjectPaneReadOnlyData`: unchanged `90/92`, non-emitting aggregate; exact child table now records [UID:000355] as assigned to [UID:00009P].
  - No split/rename was needed. The exact range remains `0x0062089c-0x00620950`.
- Validation:
  - Ran `python source-3/project-documentation/tools/validator.py --mode file --file ... --apply --queue-timeout 180` over the target, `ObjectInfoObjectPane`, `AttachedObjectPane`, and `ObjectPaneReadOnlyData`.
  - Each validator invocation exited `0` with `ok: 1`.
  - Validator recorded `000355` completion/confidence `88/92` and `AUTOGEN_PARENT_UID` blank -> `00009P`.
  - Validator-owned generated/state side effects were expected from `--apply`; no generated/project-level/report/tool state file was manually edited.
- Blockers:
  - No Batch 268 documentation/routing blocker remains.
  - Final C++ remains blank because the class declaration, inherited virtual names, field layout, label/config names, and draw-state details remain below the final-code threshold.

### Supervisor-Applied `by-memory/-coverage-report.md` Row For Batch 268

- The supervisor applied and validated the Batch 268 `by-memory/-coverage-report.md` replacement row for [UID:000355][ObjectInfoObjectPaneVtableData](by-memory/0x0062089c-0x00620950.ObjectInfoObjectPaneVtableData.md) on 2026-06-12.
- No Batch 268 supervisor-owned coverage-report rows remain pending.

## Batch 270 A003 Report - 2026-06-12

- Assigned row:
  - [UID:000357] `by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md`
- Changed files:
  - `by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md`
  - `by-class/LivingObjectPane__BoxRotator.md`
  - `by-memory/0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md`
  - `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`
  - `by-class/LivingObjectPane.md`
  - `by-file/LivingObjectPane.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, nested class parent, owning class/file, related destructor, adjacent LivingObjectPane vtable child, aggregate `.rdata` inventory, and this `notes.md`.
  - Did not manually edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, or generated/project-level report files.
- Live IDA MCP evidence:
  - `idb_meta` confirmed `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` / sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `0x0062096c -> ??_R4BoxRotator@LivingObjectPane@@6B@`, `0x00620970 -> ??_7BoxRotator@LivingObjectPane@@6B@` slot to `0x0053d030`, `0x00620974` slot to `0x0053d7c0`, and `0x00620978 -> ??_R4LivingObjectPane@@6B@`.
  - Constructors `sub_53A110` and `sub_53A360` store the `BoxRotator` vtable at `LivingObjectPane + 0x1f0`, store the owner pointer at `+0x1f4`, and initialize the owner rotation state at `+0x1ec`.
  - `sub_53D030` is exactly `0x0053d030-0x0053d053` and is the scalar deleting destructor reached from the first BoxRotator vtable slot.
  - `sub_53D7C0` is exactly `0x0053d7c0-0x0053d7f4`, uses `[this+4]` as the owner pointer, advances owner state modulo four, calls `sub_4B6D30(this, 10)`, and refreshes/invalidates the owner through the owner vtable.
  - The adjacent main `LivingObjectPane` vtable child starts at `0x00620978`, has primary/adjusted vtable refs from constructor/destructor paths, and ends before `0x00620a38 -> ??_R4LightingObjectPane@@6B@`.
- Score/status/parent decisions:
  - [UID:000357] `LivingObjectPaneBoxRotatorVtableData`: `85/88`, parent blank -> `88/92`, parent [UID:00007C][LivingObjectPane__BoxRotator](../../../by-class/LivingObjectPane__BoxRotator.md).
  - [UID:00007C] `LivingObjectPane__BoxRotator`: `82/84`, parent [UID:0000KU][LivingObjectPane](../../../by-file/LivingObjectPane.md) -> `86/89`, parent [UID:00007B][LivingObjectPane](../../../by-class/LivingObjectPane.md).
  - [UID:0002T6] `LivingObjectPaneBoxRotatorScalarDeletingDestructor`: `78/86` -> `85/89`, parent [UID:00007C][LivingObjectPane__BoxRotator](../../../by-class/LivingObjectPane__BoxRotator.md) retained.
  - [UID:000358] `LivingObjectPaneVtableData`: `85/88`, parent blank -> `87/91`, parent [UID:00007B][LivingObjectPane](../../../by-class/LivingObjectPane.md).
  - [UID:00007B] `LivingObjectPane` stayed `85/85`; evidence/cross-links updated for the vtable children.
  - [UID:0000KU] `LivingObjectPane` stayed `88/85`; source-module evidence/cross-links updated for the vtable children.
  - [UID:000260] `ObjectPaneReadOnlyData` stayed `90/92`, non-emitting aggregate; exact child table now records `000357` and `000358` assigned.
- Validation:
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` from `source-3/project-documentation` over the seven edited by-* files.
  - Each invocation exited `0` with `ok: 1`. The first target pass recorded `completion_update 000357 ... 88`, `confidence_update 000357 ... 92`, and `autogen_registry_update 000357 ... -> 00007C`; subsequent passes refreshed the related score/parent metadata and generated state.
  - Validator-owned generated/state side effects were expected from `--apply`; no generated/project-level/report/tool state file was manually edited.
- Blockers:
  - No Batch 270 split or parent-gate blocker remains.
  - Final C++ remains blank because the final `LivingObjectPane::BoxRotator` declaration, base/helper type names, adjusted vtable method names, and full `LivingObjectPane` field layout remain below the 95/95 code gate.

### Supervisor-Applied Coverage Report Rows For Batch 270

- The supervisor applied and validated the Batch 270 `by-class/-coverage-report.md` replacement row for [UID:00007C] on 2026-06-12.
- The supervisor applied and validated the Batch 270 `by-memory/-coverage-report.md` replacement rows for [UID:0002T6], [UID:000357], and [UID:000358] on 2026-06-12.
- No Batch 270 supervisor-owned coverage-report rows remain pending.

## Batch 274 A003 Report - 2026-06-12

- Assigned row:
  - [UID:000359] `by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md`
- Changed files:
  - `by-memory/0x00620a38-0x00620ae4.LightingObjectPaneVtableData.md`
  - `by-class/LightingObjectPane.md`
  - `by-file/LightingObjectPane.md`
  - `by-memory/0x0053c5e0-0x0053c6a1.LightingObjectPaneLifecycle.md`
  - `by-memory/0x0053c980-0x0053c9b5.LightingObjectPaneSetIntensity.md`
  - `by-memory/0x0053d380-0x0053d422.LightingObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, LightingObjectPane class/file parents, three exact method children, ObjectPane read-only-data aggregate, and this `notes.md`.
  - Did not manually edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, or generated/project-level/tool-owned files.
- Live IDA MCP evidence:
  - Direct JSON-RPC `idb_meta` confirmed `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` / sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `py_eval` resolved the target table dwords: `0x00620a38 -> ??_R4LightingObjectPane@@6B@`, primary slot `0x00620a3c -> 0x0053d380`, adjusted slots `0x00620aac -> 0x0053cf28` and `0x00620adc -> 0x0053cf33`, and successor `0x00620ae4 -> ??_R4SoundObjectPane@@6B@`.
  - `xrefs_to` reconfirmed constructor/destructor/scalar-destructor vptr refs at `0x0053c61f`, `0x0053c625`, `0x0053c62f`, `0x0053c66b`, `0x0053c671`, `0x0053c67b`, `0x0053d3ab`, `0x0053d3b1`, and `0x0053d3bb`.
  - `lookup_funcs`, `decompile`, and `disasm` reconfirmed constructor `0x0053c5e0-0x0053c640`, ordinary destructor `0x0053c640-0x0053c6a1`, `SetIntensity` `0x0053c980-0x0053c9b5`, scalar deleting destructor `0x0053d380-0x0053d422`, and adjustor thunks `0x0053cf28-0x0053cf33` / `0x0053cf33-0x0053cf3e`.
- Score/status/parent decisions:
  - [UID:000359] `LightingObjectPaneVtableData`: `85/88`, parent blank -> `88/92`, parent [UID:000075][LightingObjectPane](../../../by-class/LightingObjectPane.md).
  - [UID:000075] `LightingObjectPane`: `84/88` -> `86/90`, parent [UID:0000KO][LightingObjectPane](../../../by-file/LightingObjectPane.md) retained.
  - [UID:0000KO] `LightingObjectPane`: `84/86` -> `85/88`, path `NexusTK/map/` retained.
  - [UID:0001DG] `LightingObjectPaneLifecycle`: `84/88`, parent [UID:0000KO][LightingObjectPane](../../../by-file/LightingObjectPane.md) -> `86/90`, parent [UID:000075][LightingObjectPane](../../../by-class/LightingObjectPane.md).
  - [UID:0001DI] `LightingObjectPaneSetIntensity`: `84/88`, parent [UID:0000KO][LightingObjectPane](../../../by-file/LightingObjectPane.md) -> `86/90`, parent [UID:000075][LightingObjectPane](../../../by-class/LightingObjectPane.md).
  - [UID:0001DM] `LightingObjectPaneScalarDeletingDestructor`: `84/88`, parent [UID:0000KO][LightingObjectPane](../../../by-file/LightingObjectPane.md) -> `86/90`, parent [UID:000075][LightingObjectPane](../../../by-class/LightingObjectPane.md).
  - [UID:000260] `ObjectPaneReadOnlyData` stayed `90/92`, non-emitting aggregate; exact child table now records [UID:000359] assigned to [UID:000075].
- Validation:
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` from `source-3/project-documentation` over the seven edited by-* files.
  - Each invocation exited `0` with `ok: 1`. The first target pass recorded `completion_update 000359 ... 88`, `confidence_update 000359 ... 92`, and `autogen_registry_update 000359 ... -> 000075`; subsequent passes refreshed the related score/parent metadata and generated state.
  - Validator-owned generated/state side effects were expected from `--apply`; no generated/project-level/report/tool state file was manually edited.
- Blockers:
  - No Batch 274 split or parent-gate blocker remains.
  - Final C++ remains blank because attached object/light-binding interface type, virtual slot names, inherited vtable method names, and final field names are below the 95/95 code gate.

### Applied Coverage Report Rows For Batch 274

- The supervisor applied and validated the Batch 274 `by-memory/-coverage-report.md` replacement rows for [UID:0001DG], [UID:0001DI], [UID:0001DM], and nested [UID:000359] on 2026-06-12.
- A003 applied and validated the Batch 274 `by-class/-coverage-report.md` row for [UID:000075] and `by-file/-coverage-report.md` row for [UID:0000KO] on 2026-06-12 after the shared-report lease conflict cleared.
- No Batch 274 supervisor-owned coverage-report rows remain pending.

## Batch 279 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00035A] `by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md`
- Changed files:
  - `by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md`
  - `by-class/SoundObjectPane.md`
  - `by-file/SoundObjectPane.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, SoundObjectPane class/file parents, ObjectPane read-only-data aggregate, and this `notes.md`.
  - Did not manually edit `by-memory/-coverage-report.md`, `by-class/-coverage-report.md`, `by-file/-coverage-report.md`, generated/project-level files, or tool-owned state files.
- Evidence basis and limitations:
  - IDA MCP was unavailable during the 2026-06-12 Batch 279 resume pass: `tools/list` timed out twice and `initialize` then returned "Unable to connect to the remote server".
  - Routing and score changes therefore use the existing written live-IDA evidence in the target and related docs: 2026-06-10 `py_eval` table data for `0x00620ae4 -> ??_R4SoundObjectPane@@6B@`, primary/adjusted vtable bases at `0x00620ae8`, `0x00620b58`, and `0x00620b88`, slot targets `0x0053d660`, `0x0053cf72`, and `0x0053cf7d`, constructor/destructor/scalar-destructor vptr refs, and the `0x00620b90` BowGauge successor boundary.
  - Parent-gate evidence comes from 2026-06-11 SoundObjectPane parent/scalar-destructor refresh: [UID:0000DH] is `85/89`, [UID:0000NW] is `85/87`, and exact scalar destructor child [UID:000387] is assigned at `88/92`.
- Score/status/parent decisions:
  - [UID:00035A] `SoundObjectPaneVtableData`: `85/88`, parent blank -> `87/90`, parent [UID:0000DH][SoundObjectPane](../../../by-class/SoundObjectPane.md).
  - [UID:0000DH] `SoundObjectPane`: stayed `85/89`; evidence/cross-links updated for the exact vtable child.
  - [UID:0000NW] `SoundObjectPane`: stayed `85/87`; evidence/cross-links updated for the exact vtable child.
  - [UID:000260] `ObjectPaneReadOnlyData`: stayed `90/92`, non-emitting aggregate; exact child table now records [UID:00035A] assigned to [UID:0000DH].
- Validation:
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` from `source-3/project-documentation` over the four edited by-* files.
  - Each invocation exited `0` with `ok: 1`. The first target pass recorded `completion_update 00035A ... 87`, `confidence_update 00035A ... 90`, and `autogen_registry_update 00035A ... -> 0000DH`.
  - Validator reported unrelated stale registry entries for `000108` and A002 SystemMessage/ForcedInform boundary work (`0003DJ`-`0003DM`); no Batch 279 documentation error was reported.
- Blockers:
  - No Batch 279 split or parent-gate blocker remains.
  - Final C++ remains blank because field names, inherited virtual slot names, final timer/sound interface names, and source-ready method signatures remain below the 95/95 code gate.

### Supervisor-Applied `by-memory/-coverage-report.md` Row For Batch 279

- The supervisor applied the Batch 279 `by-memory/-coverage-report.md` replacement row for [UID:00035A][SoundObjectPaneVtableData](../../../by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md) on 2026-06-12.

## Batch 281 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00035B] `by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md`
- Changed files:
  - `by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md`
  - `by-class/OptionPane.md`
  - `by-file/OptionPane.md`
  - `by-memory/0x00620284-0x00620c74.ObjectPaneReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, OptionPane class/file parents, ObjectPane read-only-data aggregate, and this `notes.md`.
  - Attempted to lease `by-class/-coverage-report.md`; rejected because another agent held the lease. The supervisor later applied and validated the replacement row.
  - Did not manually edit `by-memory/-coverage-report.md`, generated/project-level files, or tool-owned state files.
- Live IDA MCP evidence:
  - The current MCP server uses database/session IDs. `idb_list` showed active `c001_nexustk`; `py_eval` is not exposed in this schema.
  - `xrefs_to` on `0x00620c70` returned no direct xrefs, as expected for the RTTI pointer dword.
  - `xrefs_to` on `0x00620c74` returned exactly three data refs: `0x0053d861` inside `sub_53D820` (`0x52f` bytes), `0x0053dd50` inside `sub_53DD50` (`0x1f` bytes), and `0x00542946` inside `sub_542940` (`0x55` bytes).
  - `lookup_funcs` reconfirmed the same constructor, non-deleting destructor/reset helper, and scalar deleting destructor anchors at `0x0053d820`, `0x0053dd50`, and `0x00542940`.
- Score/status/parent decisions:
  - [UID:00035B] `OptionPaneRttiBoundaryData`: `85/88`, parent blank -> `87/90`, parent [UID:00009V][OptionPane](../../../by-class/OptionPane.md).
  - [UID:00009V] `OptionPane`: stayed `86/87`; evidence/cross-links updated for the exact RTTI boundary child.
  - [UID:0000M7] `OptionPane`: stayed `91/85`; evidence/cross-links updated for the exact RTTI boundary child.
  - [UID:000260] `ObjectPaneReadOnlyData`: stayed `90/92`, non-emitting aggregate; exact child table now records [UID:00035B] assigned to [UID:00009V].
- Validation:
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` from `source-3/project-documentation` over the four edited by-* files.
  - Each invocation exited `0` with `ok: 1`. The first target pass recorded `completion_update 00035B ... 87`, `confidence_update 00035B ... 90`, and `autogen_registry_update 00035B ... -> 00009V`.
  - Validator-owned generated/state side effects were expected from `--apply`; no generated/project-level/report/tool state file was manually edited.
- Blockers:
  - No Batch 281 split or parent-gate blocker remains.
  - Final C++ remains blank because old option-control field names, inherited virtual slot names, raw helper source names, and final old/new option-pane grouping remain below the 95/95 code gate.
  - `by-class/-coverage-report.md` row for [UID:00009V] was later applied and validated by the supervisor; no pending class coverage row remains.

### Supervisor-Applied `by-memory/-coverage-report.md` Row For Batch 281

- The supervisor applied and validated the Batch 281 `by-memory/-coverage-report.md` replacement row for [UID:00035B][OptionPaneRttiBoundaryData](../../../by-memory/0x00620c70-0x00620c74.OptionPaneRttiBoundaryData.md) on 2026-06-12.

### Supervisor-Applied `by-class/-coverage-report.md` Row For Batch 281

- The supervisor applied and validated the Batch 281 `by-class/-coverage-report.md` replacement row for [UID:00009V][OptionPane](../../../by-class/OptionPane.md) on 2026-06-12.

## Batch 285 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003DF] `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
- Changed files:
  - `by-memory/0x00622cf0-0x00622d08.NexonclubProxyCallbackVtableData.md`
  - `by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md`
  - `by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md`
  - `by-class/NexonclubProxyDialog.md`
  - `by-file/NexonclubProxyDialog.md`
  - `by-type/by-template/FunctionObjectTemplates.md`
  - `by-file/FunctionObjects.md`
  - `by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, constructor, direct class/file parents, FunctionObjects template/file owners, mixed read-only-data aggregate, new concrete callback class page, and this `notes.md`.
  - Did not manually edit `by-memory/-coverage-report.md` under the supervisor override.
  - Did not manually edit `by-class/-coverage-report.md` or `by-file/-coverage-report.md` because another agent held shared-report leases.
  - Did not manually edit generated/project-level files or tool-owned state files; validator-owned generated/state side effects came only from `--apply`.
- Live IDA MCP evidence:
  - Used active `c001_nexustk` MCP session.
  - `decompile 0x00553610` resolved the callback allocation in `sub_553610`: 24-byte allocation, base setup call, vptr store to `??_7?$PlainMemberFunctionObjectT@P8NexonclubProxyDialog@A0x885cb488@@AEXABV?$StringBase@_WU?$mychar_traits@_W@mystr@@@mystr@@@...@@6B@` at `0x0055388f`, member-function target store `0x005534a0` at `+8`, zero adjustment at `+0xc`, bound dialog object at `+0x10`, and handoff to the registration/proxy-dialog allocation path.
  - `xrefs_to 0x00622cf4` returned the sole vtable-base store at `0x0055388f`; `xrefs_to 0x005534a0` returned the sole construction-site data reference at `0x00553895`.
  - Slot targets were checked: `0x0052f7c0` destructor, `0x004f4b10` base callback helper, `0x0041b6c0` null callback, `0x0049af00` invoke stub, `0x004673f0` 24-byte size helper.
  - `xrefs_to 0x00622cf0` had no direct base xrefs, matching the RTTI-leading dword; `xrefs_to 0x00622d08` was not needed for ownership because it is the successor boundary after the callback table.
- Score/status/parent decisions:
  - [UID:0003DF] `NexonclubProxyCallbackVtableData`: `85/90`, parent blank -> `88/92`, parent [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](../../../by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md).
  - [UID:0003GK] `PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback`: new exact concrete callback class page at `86/91`, parent [UID:0000JO][FunctionObjects](../../../by-file/FunctionObjects.md).
  - [UID:0001FK] `NexonclubProxyDialogConstructor`: `78/86` -> `85/90`, parent stayed [UID:00009H][NexonclubProxyDialog](../../../by-class/NexonclubProxyDialog.md).
  - [UID:00009H] `NexonclubProxyDialog`: `80/84` -> `86/88`, parent stayed [UID:0000LZ][NexonclubProxyDialog](../../../by-file/NexonclubProxyDialog.md).
  - [UID:0000LZ] `NexonclubProxyDialog`: `82/82` -> `85/87`, path stayed `NexusTK/ui/dialogs/`.
  - [UID:0000JO] `FunctionObjects`: stayed `87/85`; content updated for the new concrete callback class and NexonclubProxy consumer evidence.
  - [UID:000268] `MessageDialogReadOnlyData`: stayed `87/93`, non-emitting aggregate; child table now records [UID:0003DF] assigned to [UID:0003GK].
  - [UID:0003DE] `NexonclubProxyDialogVtableData` was not edited by A003 because it is Agent-A001 Batch 284 work. Its direct class parent [UID:00009H] now clears `86/88`, so the existing row's parent-gate rationale is stale and needs A001/supervisor follow-up before routing.
- Routing decision:
  - Routed [UID:0003DF] to [UID:0003GK] because the exact child is `88/92` and the actual direct parent is `86/91`, with [UID:0003GK] itself routed to [UID:0000JO] (`87/85`).
  - Did not route [UID:0003DF] to `NexonclubProxyDialog`; the vtable belongs to the concrete `PlainMemberFunctionObjectT` callback wrapper, while the dialog owns the bound `this` object and member target.
- Validation:
  - Ran `python tools\validator.py --mode file --file by-class\PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md --apply --queue-timeout 180`; validator assigned [UID:0003GK] and exited `0`.
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` over the eight edited by-* files listed above.
  - Each invocation exited `0`; validator output included expected `completion_update`, `confidence_update`, and `autogen_registry_update` entries for [UID:0003GK], [UID:0003DF], [UID:0001FK], [UID:00009H], [UID:0000LZ], and [UID:000268].
  - Follow-up generated checks confirmed [UID:0003DF] assigned to [UID:0003GK] in `auto-generated/-ag-memory-coverage.md`, [UID:0003GK] assigned to [UID:0000JO] in `auto-generated/-ag-class-coverage.md`, and [UID:00009H] assigned to [UID:0000LZ].
- Blockers:
  - No Batch 285 split or parent-gate blocker remains for [UID:0003DF].
  - Final C++ remains blank because the concrete callback wrapper, dialog callback member name, and registration-dialog source names remain below the 95/95 final-code gate.

### Supervisor-Applied Shared Report Rows For Batch 285

- The supervisor applied and validated the Batch 285 `by-memory/-coverage-report.md` rows for [UID:0001FK], [UID:000268], [UID:0003DF], and coordinated [UID:0003DE] on 2026-06-12.
- The supervisor applied and validated the shared `by-class/-coverage-report.md` rows for [UID:00009H] and [UID:0003GK], plus `by-file/-coverage-report.md` rows for [UID:0000LZ] and [UID:0000JO].
- No Batch 285 supervisor-owned report rows remain pending.

## Batch 290 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003DR] `by-memory/0x0062dbe4-0x0062dca8.PhoneBookListPaneVtableData.md`
- Changed files:
  - `by-memory/0x0062dbe4-0x0062dca8.PhoneBookListPaneVtableData.md`
  - `by-class/PhoneBookListPane.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, direct class parent, and this `notes.md`.
  - Attempted to lease `by-file/PhoneBookDialog.md`, `by-memory/0x0062da10-0x0062df94.TerminalPhoneReadOnlyData.md`, and `by-class/-coverage-report.md`; each was already leased by Agent-A001.
  - Did not manually edit `by-memory/-coverage-report.md` under the active supervisor override.
  - Did not manually edit generated/project-level files or tool-owned state files; validator-owned generated/state side effects came only from `--apply`.
- Live IDA MCP evidence:
  - Used active `c001_nexustk` MCP session.
  - `entity_query` over `0x0062dbe4-0x0062dca8` reconfirmed the three `PhoneBookListPane` vtable heads at `0x0062dbe4`, `0x0062dc6c`, and `0x0062dc9c`, followed by successor `PhoneEntryDialog` vtable head `0x0062dca8`.
  - `xrefs_to` reported primary/secondary/tertiary list-pane vtable stores at `0x0058c443`, `0x0058c449`, and `0x0058c453` inside `PhoneBookDialog::PhoneBookDialog`, plus setup-helper stores at `0x0058cefe`, `0x0058cf04`, and `0x0058cf0e`.
  - Constructor disassembly shows embedded list-pane allocation size `0x150` / 336 bytes, geometry setup, vptr stores at `+0`, `+0xa0`, and `+0xa4`, and owner back-pointer store `mov [esi+14Ch], edi`; values were verified with `int_convert.py`.
  - `disasm 0x0058d110` shows activation forwarding through `[this+0x14c]` to `0x0058cb60`.
  - `decompile 0x0058d120` shows row rendering from `entry+0x02` and `entry+0x82`, ellipsis truncation, selected-row highlight, and two text columns.
  - `decompile 0x0058cfa0` reconfirmed selected-entry extraction from list row fields and the single direct caller at `PhoneBookDialog::OnCommand`.
- Score/status/parent decisions:
  - [UID:0003DR] `PhoneBookListPaneVtableData`: `85/91`, parent blank -> `87/92`, parent [UID:0000AE][PhoneBookListPane](../../../by-class/PhoneBookListPane.md).
  - [UID:0000AE] `PhoneBookListPane`: `82/86` -> `85/88`, parent stayed [UID:0000MJ][PhoneBookDialog](../../../by-file/PhoneBookDialog.md).
  - [UID:0000MJ] `PhoneBookDialog` file was read but not edited because Agent-A001 held the lease; current file score remains `86/80`, and the target route does not assign the vtable directly to the file page.
  - [UID:00026N] `TerminalPhoneReadOnlyData` was read but not edited because Agent-A001 held the lease; its child table needs the exact [UID:0003DR] row update below.
- Routing decision:
  - Routed [UID:0003DR] to [UID:0000AE] because the exact child is `87/92` and the actual direct class parent is `85/88`.
  - Did not route [UID:0003DR] to [UID:0000MJ] or [UID:0000AD]; the file/dialog own the containing feature, but the vtable bytes directly belong to `PhoneBookListPane`.
- Validation:
  - Ran `python tools\validator.py --mode file --file by-memory\0x0062dbe4-0x0062dca8.PhoneBookListPaneVtableData.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0003DR ... 87`, `confidence_update 0003DR ... 92`, and `autogen_registry_update 0003DR ... -> 0000AE`.
  - Ran `python tools\validator.py --mode file --file by-class\PhoneBookListPane.md --apply --queue-timeout 180`; exited `0` with `ok: 1`.
  - Ran the class validator a second time after tightening one parent-status sentence; exited `0` with `ok: 1`.
  - Follow-up generated checks confirmed [UID:0003DR] assigned to [UID:0000AE] in `auto-generated/-ag-memory-coverage.md` and [UID:0000AE] assigned to [UID:0000MJ] in `auto-generated/-ag-class-coverage.md`.
- Blockers:
  - No Batch 290 target parent-gate blocker remains.
  - Related aggregate/report updates were blocked by supervisor override or Agent-A001 leases during the batch; the supervisor later applied and validated the still-needed rows.
  - Final C++ remains blank because source-quality list-base API names, adjusted-base hierarchy names, contact-row field names, and render helper names remain below the 95/95 code gate.

### Batch 290 Supervisor-Applied Shared Rows

- The supervisor applied and validated the Batch 290 shared rows for [UID:0003DR], [UID:00026N], and [UID:0000AE] on 2026-06-12.
- The final applied split uses the repaired [UID:0003DR] path `by-memory/0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md`.
- No Batch 290 supervisor-owned shared rows remain pending.

## Batch 293 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003DY] `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md`
- Changed files:
  - `by-memory/0x0062e18c-0x0062e228.TextPadVtableData.md`
  - `by-class/TextPad.md`
  - `by-file/TextPad.md`
  - `by-memory/0x0062df94-0x0062e26c.TextEditReadOnlyData.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, direct class parent, file parent, mixed read-only-data aggregate, executable TextPad aggregate, shared class/file reports, and this `notes.md`.
  - Refreshed the `notes.md` lease before adding this durable report.
  - Did not manually edit `by-memory/-coverage-report.md` under the active supervisor override.
  - Did not manually edit generated/project-level files or tool-owned state files; validator-owned generated/state side effects came only from `--apply`.
- Live IDA MCP evidence:
  - Used active `c001_nexustk` MCP session.
  - `entity_query` over `0x0062e18c-0x0062e228` reconfirmed `TextPad` RTTI/vtable labels at `0x0062e190`, `0x0062e1f0`, and `0x0062e220`, followed by successor `Open ` command string at `0x0062e228`.
  - Vtable-table disassembly shows the RTTI locator pointer at `0x0062e18c`, primary vtable head at `0x0062e190`, adjusted vtable heads at `0x0062e1f0` and `0x0062e220`, `OnClose` slot `0x00595bb0` at `0x0062e1e0`, empty slot `0x00595bd0` at `0x0062e1e4`, and `OnKeyInput` slot `0x00595af0` at `0x0062e1f8`.
  - `xrefs_to` confirmed constructor stores to the three vtable heads at `0x00595940`, `0x00595946`, and `0x00595950`.
  - Constructor disassembly shows vptr stores at object offsets `+0`, `+0xa0`, and `+0xa4`, then embedded text-edit control setup with limits `0x7d0` / 2000 lines and `0x7530` / 30000 characters.
  - `decompile 0x00595af0` confirmed the Enter-key input path, bottom input control at `+0x15c`, mode flag at `+0x174`, text extraction, call to command helper `0x00595be0`, and selection reset.
  - `decompile 0x00595bb0` confirmed close/hide behavior and screen invalidation.
  - `decompile 0x00595be0` confirmed private command-helper ownership for `Open `, save, font, color, file I/O, and text-format insertion commands.
- Score/status/parent decisions:
  - [UID:0003DY] `TextPadVtableData`: `85/90`, parent blank -> `87/92`, parent [UID:0000EU][TextPad](../../../by-class/TextPad.md).
  - [UID:0000EU] `TextPad` class: `82/80` -> `85/86`, parent stayed [UID:0000OQ][TextPad](../../../by-file/TextPad.md).
  - [UID:0000OQ] `TextPad` file: `84/80` -> `85/85`, reconstruction path stayed `NexusTK/ui/dialogs/`.
  - [UID:00026O] `TextEditReadOnlyData`: stayed `86/91`, non-emitting aggregate; child/source mapping now records [UID:0003DY] assigned to [UID:0000EU].
- Routing decision:
  - Routed [UID:0003DY] to [UID:0000EU] because the exact child is `87/92` and the actual direct class parent is `85/86`.
  - Did not route [UID:0003DY] directly to [UID:0000OQ] or generic `TextEditPane`; the file owns the source module, but the vtable bytes directly belong to `TextPad`.
  - No split was required for [UID:0003DY]; the successor boundary at `0x0062e228` is the `Open ` command string, not part of the vtable child.
  - Kept [UID:00026O] parent blank because the physical `.rdata` aggregate spans TextEditPane/TextFilter/TextPad command children and no single owner covers the whole range.
- Validation:
  - Ran `python tools\validator.py --mode file --file by-memory\0x0062e18c-0x0062e228.TextPadVtableData.md --apply --queue-timeout 180`; exited `0` with expected `completion_update 0003DY ... 87`, `confidence_update 0003DY ... 92`, and `autogen_registry_update 0003DY ... -> 0000EU`.
  - Ran the same validator command over `by-class\TextPad.md`, `by-file\TextPad.md`, `by-memory\0x0062df94-0x0062e26c.TextEditReadOnlyData.md`, `by-class\-coverage-report.md`, and `by-file\-coverage-report.md`; each invocation exited `0`.
  - Follow-up generated checks confirmed [UID:0003DY] assigned to [UID:0000EU] in `auto-generated/-ag-memory-coverage.md` and [UID:0000EU] assigned to [UID:0000OQ] in `auto-generated/-ag-class-coverage.md`.
- Blockers:
  - No Batch 293 target parent-gate blocker remains.
  - Final C++ remains blank because source-quality activation names, helper names, and final field declarations remain below the 95/95 code gate.

### Batch 293 Supervisor-Applied Shared Rows

- The supervisor applied and validated the Batch 293 `by-memory/-coverage-report.md` rows for [UID:00026O] and [UID:0003DY] on 2026-06-12.
- No Batch 293 supervisor-owned shared rows remain pending.

## Batch 295 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003E4] `by-memory/0x0062e460-0x0062e480.TotemFrameResourceStringData.md`
- Changed files:
  - `by-memory/0x0062e460-0x0062e480.TotemFrameResourceStringData.md`
  - `by-resource/totem-frame-resources.md`
  - `by-file/TotemFrame.md`
  - `by-class/TotemFrame.md`
  - `by-memory/0x0062e338-0x0062e480.TimerTotemReadOnlyData.md`
  - `by-resource/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, TotemFrame resource page, TotemFrame file page, TotemFrame class page, mixed timer/totem read-only-data aggregate, resource coverage report, and this `notes.md`.
  - Attempted to lease `by-file/-coverage-report.md`; it was already leased by C001, so the supervisor later applied the shared report row.
  - Did not manually edit `by-memory/-coverage-report.md` under the active supervisor override.
  - Did not manually edit generated/project-level files or tool-owned state files; validator-owned generated/state side effects came only from `--apply`.
- Live IDA MCP evidence:
  - Used MCP session `a001-b276`.
  - `entity_query` and `disasm` reconfirmed IDA name `aTotframeEpd` at `0x0062e460`, rendered as UTF-16LE `TOTFRAME.EPD`.
  - `xrefs_to 0x0062e460` returned exactly one data xref: `0x00598e05` inside `sub_598DD0` / `TotemFrame::OnPaint`.
  - `lookup_funcs` confirmed `0x00598dd0` as a `0x6b`-byte function and `0x00598e05` inside that function.
  - `decompile 0x00598dd0` showed `TotemFrame::OnPaint` reading `g_pOldUserStatusPane`, calling `0x005bdc60` / `OldUserStatusPane::GetSpiritId`, loading `L"TOTFRAME.EPD"` with that frame index, then drawing with `NPAL7.PAL`.
  - `xrefs_to 0x006152ec` returned ten palette refs including `0x00598e11`, confirming `NPAL7.PAL` is shared old-HUD/status palette data and not part of the exact TotemFrame literal child.
  - `xrefs_to 0x0062e480` returned only successor `TransferServerDialogPane` refs, confirming the target's exclusive end boundary.
  - Ran `tools/int_convert.py` for `0x20`, `0xc`, and `0x44`; `0x20` is 32 bytes and `0x44` is 68 decimal.
- Score/status/parent decisions:
  - [UID:0003E4] `TotemFrameResourceStringData`: `85/92`, parent blank -> `87/93`, parent [UID:0000F4][TotemFrame](../../../by-class/TotemFrame.md).
  - [UID:0001RR] `totem-frame-resources`: `78/90` -> `85/91`; resource page remains evidence/packaging documentation, not the autogen source parent.
  - [UID:0000OV] `TotemFrame` file: `84/80` -> `85/85`, path stayed `NexusTK/ui/panels/`.
  - [UID:0000F4] `TotemFrame` class: stayed `88/90`, parent [UID:0000OV][TotemFrame](../../../by-file/TotemFrame.md); content now references the exact source-literal child.
  - [UID:00026Q] `TimerTotemReadOnlyData`: stayed `87/93`, non-emitting mixed aggregate; child/source mapping now records [UID:0003E4] assigned to [UID:0000F4].
- Routing decision:
  - Routed [UID:0003E4] to [UID:0000F4] because the exact child is `87/93`, the actual direct class parent is `88/90`, and the sole code xref is `TotemFrame::OnPaint`.
  - Did not route [UID:0003E4] to [UID:0001RR] because `by-resource` pages document resource evidence/packaging contracts and are excluded from reconstruction autogen; source ownership follows the class-local `OnPaint` operand.
  - Did not route [UID:0003E4] directly to [UID:0000OV]; the file is the source root, while the class is the narrower direct owner.
  - Kept [UID:00026Q] parent blank because the physical `.rdata` aggregate crosses TimerMgr, TimerPane, TotemFrame vtables, and the TotemFrame resource literal.
- Validation:
  - Ran `python tools\validator.py --mode file --file ... --apply --queue-timeout 180` on the six edited by-* files listed above.
  - Each invocation exited `0`.
  - Target validator output included `completion_update 0003E4 ... 87`, `confidence_update 0003E4 ... 93`, and `autogen_registry_update 0003E4 ... -> 0000F4`.
  - Follow-up generated checks confirmed [UID:0003E4] assigned to [UID:0000F4] in `auto-generated/-ag-memory-coverage.md`, [UID:0000F4] assigned to [UID:0000OV] in `auto-generated/-ag-class-coverage.md`, and [UID:0000OV] staged under `auto-generated/NexusTK/ui/panels/TotemFrame.cpp`.
- Blockers:
  - No Batch 295 target parent-gate blocker remains.
  - `by-file/-coverage-report.md` was leased by C001, so the supervisor later applied the shared report row.
  - Final C++ remains blank because exact field names, helper names, resource loader API names, and final status/totem grouping are below the 95/95 final-code gate.

### Supervisor-Applied Batch 295 Shared Rows

- The supervisor applied and validated the Batch 295 `by-memory/-coverage-report.md` rows for [UID:00026Q] and [UID:0003E4] on 2026-06-12.
- The supervisor applied and validated the shared `by-file/-coverage-report.md` row for [UID:0000OV][TotemFrame](../../../by-file/TotemFrame.md) on 2026-06-12.
- No Batch 295 supervisor-owned report rows remain pending.

## Batch 296 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0000U2] `by-item/BuildAboveFrameBorder_00461310.md`
- Changed files:
  - `by-item/BuildAboveFrameBorder_00461310.md`
  - `by-file/FrameChrome.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target item page, `by-file/FrameChrome.md`, `by-item/-coverage-report.md`, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Live IDA MCP evidence:
  - Used MCP session `b001_nexustk`.
  - `lookup_funcs 0x00461310` confirmed `sub_461310`, size `0x29a`, exact range `0x00461310-0x004615aa`.
  - `analyze_function` and `decompile 0x00461310` confirmed branch control on `byte_66DA97`, repeated `operator_new(0x134)` allocations, calls to `AboveFrame::AboveFrame`, and all slot writes.
  - New-mode branch stores four `AboveFrame` pointers at `0x0067a834`, `0x0067a83c`, `0x0067a838`, and `0x0067a840`.
  - Legacy branch stores fixed pointers at `0x0067a848`, `0x0067a834`, and `0x0067a838`, then fills five entries each in `0x0067a84c[]` and `0x0067a860[]`.
  - Caller xrefs remain two calls from `sub_4F7D10`, at `0x004f802c` and `0x004f8670`.
  - Ran `tools/int_convert.py` for `0x29a`, `0x134`, `0x328`, `0x5c`, `0x3f`, `0x197`, `0x1a4`, `0x4f`, `0x7d`, and `0x17a` before recording decimal constants.
- Score/status/parent decisions:
  - [UID:0000U2] `BuildAboveFrameBorder_00461310`: `80/86`, parent blank -> `85/90`, parent [UID:0000JL][FrameChrome](../../../by-file/FrameChrome.md).
  - [UID:0000JL] `FrameChrome`: stayed `86/85`; content now records that [UID:0000U2] is a routed file-level chrome factory.
- Routing decision:
  - Routed [UID:0000U2] to [UID:0000JL] because the item now clears `85/90`, the actual direct file parent clears `86/85`, and the helper owns global frame-border construction rather than an `AboveFrame` instance method.
  - Did not route [UID:0000U2] directly to [UID:000005][AboveFrame](../../../by-class/AboveFrame.md) because `AboveFrame` is the constructed pane class, not the owner of this free global slot factory.
  - No split was required; the documented exact range already ends before the dynamic `AboveFrame` refresh helper.
- Validation:
  - Ran `python tools\validator.py --mode file --file by-item\BuildAboveFrameBorder_00461310.md --apply --queue-timeout 180`; exited `0` with `completion_update 0000U2 ... 85`, `confidence_update 0000U2 ... 90`, and `autogen_registry_update 0000U2 ... -> 0000JL`.
  - Ran `python tools\validator.py --mode file --file by-file\FrameChrome.md --apply --queue-timeout 180`; exited `0`.
  - Ran `python tools\validator.py --mode file --file by-item\-coverage-report.md --apply --queue-timeout 180`; exited `0`.
  - Follow-up generated check confirmed [UID:0000U2] is assigned to [UID:0000JL] in `auto-generated/-ag-item-coverage.md` and staged under `auto-generated/NexusTK/ui/core/FrameChrome.cpp`.
- Pending supervisor-owned rows:
  - None for `by-memory/-coverage-report.md`; no by-memory page was changed in Batch 296.

## Batch 299 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0000UF] `by-item/DestroyDATFileMgr_467380.md`
- Changed files:
  - `by-item/DestroyDATFileMgr_467380.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target item page, `by-item/-coverage-report.md`, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Live IDA MCP evidence:
  - Used MCP session `b001_nexustk`.
  - `lookup_funcs` confirmed `sub_467380` at `0x00467380`, size `0x11`, non-function end at `0x00467391`, and sibling `sub_4673A0` at `0x004673a0`, size `0x11`.
  - `analyze_function 0x00467380` confirmed the seven-instruction `g_pDATFileMgr` null-check/vtable deleting-destructor wrapper, no direct callees, and 22 code xrefs.
  - `xrefs_to 0x00467380 0x004673a0` confirmed the same 22 caller sites pair `DestroyDATFileMgr` with `DestroyExceptionHandler` five bytes later.
  - Ran `tools/int_convert.py 0x11`; `0x11` is 17 decimal.
- Score/status/parent decisions:
  - [UID:0000UF] `DestroyDATFileMgr_467380`: `84/88`, `RECONSTRUCTABLE:TRUE`, parent blank -> `-1/-1`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - Canonical child [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](../../../by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md) remains `88/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HG][Application](../../../by-file/Application.md).
  - Direct parent [UID:0000HG] `Application` remains `86/90`, so the real code-bearing child and actual direct parent already clear the strict gate.
- Routing decision:
  - Did not route the by-item [UID:0000UF] to Application because that would duplicate the exact by-memory reconstruction item.
  - Repaired the by-structure issue by treating [UID:0000UF] as a promoted/non-emitting by-item index; the source-owning route remains [UID:0000YV] -> [UID:0000HG].
- Validation:
  - Ran `python tools\validator.py --mode file --file by-item\DestroyDATFileMgr_467380.md --apply --queue-timeout 180`; exited `0` with `completion_update 0000UF ... -1`, `confidence_update 0000UF ... -1`, and `autogen_registry_update 0000UF ... true -> false`.
  - Ran `python tools\validator.py --mode file --file by-item\-coverage-report.md --apply --queue-timeout 180`; exited `0`.
  - Follow-up generated check confirmed [UID:0000UF] is `not_reconstructable` in `auto-generated/-ag-item-coverage.md`; canonical [UID:0000YV] remains assigned to [UID:0000HG] in `auto-generated/-ag-memory-coverage.md`.
- Supervisor review:
  - No supervisor-owned `by-memory/-coverage-report.md` rows were needed for Batch 299.

## Batch 302 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0000UG] `by-item/DestroyExceptionHandler_4673A0.md`
- Changed files:
  - `by-item/DestroyExceptionHandler_4673A0.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target item page, `by-item/-coverage-report.md`, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Live IDA MCP evidence:
  - Used MCP session `b001_nexustk`.
  - `lookup_funcs` confirmed `sub_4673A0` at `0x004673a0`, size `0x11`, non-function end at `0x004673b1`, and sibling `sub_467380` at `0x00467380`, size `0x11`.
  - `analyze_function 0x004673a0` confirmed the seven-instruction `g_pCrashTarget` null-check/vtable deleting-destructor wrapper, no direct callees, and 22 code xrefs.
  - Ran `tools/int_convert.py 0x11`; `0x11` is 17 decimal.
- Score/status/parent decisions:
  - [UID:0000UG] `DestroyExceptionHandler_4673A0`: `85/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `-1/-1`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - Canonical child [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](../../../by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) remains `88/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000HG][Application](../../../by-file/Application.md).
  - Direct parent [UID:0000HG] `Application` remains `86/90`, so the real code-bearing child and actual direct parent already clear the strict gate.
- Routing decision:
  - Did not route the by-item [UID:0000UG] to Application because that would duplicate the exact by-memory reconstruction item.
  - Repaired the by-structure issue by treating [UID:0000UG] as a promoted/non-emitting by-item index; the source-owning route remains [UID:0000YW] -> [UID:0000HG].
- Validation:
  - Ran `python tools\validator.py --mode file --file by-item\DestroyExceptionHandler_4673A0.md --apply --queue-timeout 180`; exited `0` with `completion_update 0000UG ... -1`, `confidence_update 0000UG ... -1`, and `autogen_registry_update 0000UG ... true -> false`.
  - Ran `python tools\validator.py --mode file --file by-item\-coverage-report.md --apply --queue-timeout 180`; exited `0`.
  - Follow-up generated check confirmed [UID:0000UG] is `not_reconstructable` in `auto-generated/-ag-item-coverage.md`; canonical [UID:0000YW] remains assigned to [UID:0000HG] in `auto-generated/-ag-memory-coverage.md`.
- Pending supervisor-owned rows:
  - None expected; no by-memory page was changed in Batch 302.

## Batch 305 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0000UJ] `by-item/DrawTextInRect_004BAD70.md`
- Changed files:
  - `by-item/DrawTextInRect_004BAD70.md`
  - `by-item/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target item page, `by-item/-coverage-report.md`, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Evidence reviewed:
  - [UID:0000UJ] was a duplicate by-item reconstruction entry for exact memory child [UID:00016D][0x004bad70-0x004baf92.DrawTextInRect](../../../by-memory/0x004bad70-0x004baf92.DrawTextInRect.md).
  - [UID:00016D] already documents exact bounds, 130 direct callers, callee list, GrafPort receiver fields, bounded line-copy/range-check behavior, and A004 Batch 119 parent review.
  - [UID:00016D] is already assigned to actual direct parent [UID:00005V][GrafPort](../../../by-class/GrafPort.md); that class is assigned to [UID:0000JR][GrafPort](../../../by-file/GrafPort.md).
- Score/status/parent decisions:
  - [UID:0000UJ] `DrawTextInRect_004BAD70`: `80/86`, `RECONSTRUCTABLE:TRUE`, parent blank -> `-1/-1`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - Canonical child [UID:00016D] remains `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00005V][GrafPort](../../../by-class/GrafPort.md).
  - Direct parent [UID:00005V] remains `85/87`, and file parent [UID:0000JR] remains `88/85`, so the real code-bearing child and actual direct parent already clear the strict gate.
- Routing decision:
  - Did not route the by-item [UID:0000UJ] to GrafPort because that would duplicate the exact by-memory reconstruction item.
  - Repaired the by-structure issue by treating [UID:0000UJ] as a promoted/non-emitting by-item index; the source-owning route remains [UID:00016D] -> [UID:00005V] -> [UID:0000JR].
- Validation:
  - Ran `python tools\validator.py --mode file --file by-item\DrawTextInRect_004BAD70.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0000UJ ... -1`, `confidence_update 0000UJ ... -1`, `autogen_registry_update 0000UJ ... true -> false`, and `stats_row_remove 0000UJ`.
  - Ran `python tools\validator.py --mode file --file by-item\-coverage-report.md --apply --queue-timeout 180`; exited `0` with `ok: 1`.
  - Follow-up generated check confirmed [UID:0000UJ] is `not_reconstructable` in `auto-generated/-ag-item-coverage.md`; canonical [UID:00016D] remains assigned to [UID:00005V] in `auto-generated/-ag-memory-coverage.md`.
- Pending supervisor-owned rows:
  - None expected; no by-memory page was changed in Batch 305.

## Batch 307 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002BD] `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
- Changed files:
  - `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
  - `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target by-memory page, its non-emitting aggregate parent, and this `notes.md`.
  - Final cleanup: initial unlease found the target and notes leases had already expired; reacquired target, aggregate, and notes leases before final release.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` `lookup_funcs` reports `0x00503060`, `0x005030bc`, `0x005030c0`, and `0x00503110` as not functions, with neighbors `sub_502E30` at `0x00502e30` size `0x22c` and `sub_5031F0` at `0x005031f0` size `0xd3`.
  - MCP `xrefs_to` reports zero xrefs to `0x00503060`, `0x005030c0`, and `0x00503110`.
  - Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no absolute-VA, RVA, `E8/E9`, `0F 8x`, or short conditional-branch references to the three raw starts.
  - Expanded vtable dump across MapName/MiniMapButton-adjacent heads found real nearby slots including `0x00503840`, `0x00503350`, `0x005034a0`, `0x0050380b`, `0x00503816`, `0x00503900`, `0x00503650`, `0x00503821`, `0x005036a0`, and `0x0050382c`, but no slot to `0x00503060`.
- Score/status/parent decisions:
  - [UID:0002BD] `UiAssetModeRectVirtualDispatchHelper`: `86/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `87/91`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - [UID:00022Z] `UnreferencedUiResourceTextHelpers`: stayed `86/90`, `RECONSTRUCTABLE:FALSE`, parent blank; only the target child matrix/evidence was synced.
  - No parent assignment was made. The target child clears `85/85`, but no actual direct source parent is proven; [UID:00022Z] is a non-emitting split inventory, and MapName/MiniMapButton candidate parents lack call, pointer, branch, or vtable-slot evidence for this raw start.
- Validation:
  - Ran `python tools\validator.py --mode file --file by-memory\0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0002BD ... 87`, and `confidence_update 0002BD ... 91`.
  - Ran `python tools\validator.py --mode file --file by-memory\0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md --apply --queue-timeout 180`; exited `0` with `ok: 1`.
  - Follow-up generated check confirmed [UID:0002BD] remains `unassigned` in `auto-generated/-ag-memory-coverage.md`, with `AUTOGEN_PARENT_UID` still blank by design.
- Supervisor-applied `by-memory/-coverage-report.md` row:
  - The supervisor applied and validated the Batch 307 replacement row for [UID:0002BD] on 2026-06-12.
  - No Batch 307 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 311 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002BF] `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
- Changed files:
  - `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
  - `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target by-memory page, its non-emitting aggregate parent, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` `lookup_funcs` reports `0x00503110` and `0x005031e1` as not functions, with neighbors `sub_5031F0` at `0x005031f0` size `0xd3`, `sub_5032D0` at `0x005032d0` size `0x7d`, `sub_503350` at `0x00503350` size `0x14f`, and `sub_5034A0` at `0x005034a0` size `0xd4`.
  - MCP `xrefs_to` reports zero xrefs to `0x00503110`; MapName vtable heads `0x0061e5b4`, `0x0061e600`, and `0x0061e630` only have normal constructor/destructor/scalar-destructor vtable store refs.
  - MCP `xrefs_to` for `9X11FONT.BIN` at `0x0061682c` found nine xrefs across multiple UI/status consumers, so the resource is shared and does not prove MapName ownership by itself.
  - Local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found no absolute-VA, RVA, `E8/E9`, `0F 8x`, or short conditional-branch references to `0x00503110`.
  - Byte comparison against assigned [UID:0003AF][0x005ba020-0x005ba0f1.UserStatusPaneGlyphTextDraw](../../../by-memory/0x005ba020-0x005ba0f1.UserStatusPaneGlyphTextDraw.md) confirms the same 9x11 UTF-16 glyph-renderer behavior, but not ownership because [UID:0003AF] has direct paint callers and this target does not.
- Score/status/parent decisions:
  - [UID:0002BF] `WideGlyphResourceTextRendererRaw`: `86/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `87/91`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - [UID:00022Z] `UnreferencedUiResourceTextHelpers`: stayed `86/90`, `RECONSTRUCTABLE:FALSE`, parent blank; only the target child matrix/evidence was synced.
  - No parent assignment was made. The child clears `85/85`, but no actual direct source parent is proven; [UID:00022Z] is a non-emitting split inventory, and MapName/MiniMapButton candidates lack call, pointer, branch, or vtable-slot evidence for this raw start.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0002BF ... 87`, `confidence_update 0002BF ... 91`, `autogen_report_update ... auto-generated/-ag-memory-coverage.md`, and `reference_index_add 0003AF`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md --apply --queue-timeout 180`; exited `0` with `ok: 1` and `auto-generated/-ag-memory-coverage.md unchanged`.
  - Reran both file validators after final parent-gate prose cleanup; both exited `0` with `ok: 1` and no further score/report changes.
- Supervisor-applied `by-memory/-coverage-report.md` row:
  - The supervisor applied and validated the Batch 311 replacement row for [UID:0002BF] on 2026-06-12.
  - No Batch 311 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 316 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00023P] `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
- Changed files:
  - `by-memory/0x00554640-0x00554675.WordRefCountHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits; no active leases were present.
  - Leased the target by-memory page and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` `server_health` reports `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reports `sub_554640` at `0x00554640` size `0x0b`, no functions at `0x00554635`, `0x0055464b`, `0x00554650`, `0x00554654`, `0x00554660`, or `0x00554675`, next function `sub_554680` at `0x00554680` size `0x61`, and free wrapper `sub_5C7526` at `0x005c7526` size `0x0e`.
  - MCP `xrefs_to` reports zero xrefs to `0x00554640`, `0x00554650`, and `0x00554660`.
  - MCP `decompile` and `disasm` reconfirm `_WORD *__thiscall sub_554640(_WORD *this) { *this = 1; return this; }` and the four-instruction initializer.
  - MCP `make_signature` reports unique helper signatures: `B8 01 00 00 00 66 89 01`, `66 FF 01`, and `66 FF 09 66 83 39 00`.
  - MCP `entity_query` found no name/string matches for `refcount`, `ref count`, `word ref`, or `intrusive`.
  - Local read-only PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` reconfirmed exact bytes/padding, zero absolute-VA/RVA/relative-branch references to the three starts, unique full helper patterns, and only three `push 2` free-wrapper sites: `0x004564b6`, `0x004574b6`, and `0x00554669`.
- Score/status/parent decisions:
  - [UID:00023P] `WordRefCountHelpers`: `87/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/92`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - No parent assignment was made. The child clears `85/85`, but no actual direct source parent is proven; a new `util/WordRefCountHelpers` by-file parent remains a plausible placement inference, not a justifiable `85/85` true direct parent.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00554640-0x00554675.WordRefCountHelpers.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 00023P ... 88`, `confidence_update 00023P ... 92`, and `autogen_report_noop ... auto-generated/-ag-memory-coverage.md unchanged`.
  - Follow-up generated check confirmed [UID:00023P] remains `unassigned` in `auto-generated/-ag-memory-coverage.md`, with `AUTOGEN_PARENT_UID` still blank by design.
- Supervisor-applied `by-memory/-coverage-report.md` row:
  - The supervisor applied and validated the Batch 316 replacement row for [UID:00023P] on 2026-06-12.
  - No Batch 316 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 318 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0001GJ] `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md`
- Changed files:
  - `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before edits.
  - Leased the target by-memory page and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` `server_health` reports `NexusTK.exe`, input path `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed no function at `0x0055d957`, key starts `0x0055d960`, `0x0055e660`, `0x0055f450`, `0x00560900`, `0x00561db0`, `0x00563260`, `0x00564710`, and `0x00565360`, and the tail state where `0x00565480` is inside `sub_565360` but `0x00565488` and `0x00565490` are not functions.
  - MCP `entity_query` over `0x0055d960-0x00565488` returned `84` modeled functions, matching the seven-cluster split already documented.
  - MCP `xrefs_to` reconfirmed mixed ownership: generic scroll input/internal callers for `0x0055d960`, six shared constructor callers for `0x0055e660` including TextEditPane, spell/group/collection/inventory constructor callers for the middle families, and option/volume callers for the volume family.
  - MCP `make_signature_for_range 0x00565488-0x00565490` returned eight `0xcc` bytes before the following raw reset helper.
- Score/status/parent decisions:
  - [UID:0001GJ] `TextEditPaneScrollbarVariants`: `85/88`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/90`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - No parent assignment was made. This page is a mixed physical map over exact reconstructable children, not a true direct source parent. TextEditPane and ScrollBar contexts are useful related docs but do not own the full generic/spell/group/collection/inventory/volume scrollbar corridor.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0001GJ ... 88`, `confidence_update 0001GJ ... 90`, `autogen_registry_update 0001GJ ... true -> false`, `reference_index_add 0001FT`, `reference_index_add 00026O`, and `autogen_report_update ... auto-generated/-ag-memory-coverage.md`.
  - Follow-up generated check confirmed [UID:0001GJ] is `not_reconstructable` in `auto-generated/-ag-memory-coverage.md`, with `AUTOGEN_PARENT_UID` still blank by design.
- Supervisor-applied `by-memory/-coverage-report.md` row:
  - The supervisor applied and validated the Batch 318 replacement row for [UID:0001GJ] on 2026-06-12.
  - No Batch 318 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 320 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003FZ] `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
- Changed files:
  - `by-memory/0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before edits.
  - Leased the target by-memory page and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `xrefs_to` reconfirmed the modeled FileDownloader and MiniMapDownloader consumers for every literal head in `0x0060d7f4-0x0060d8b8`, plus raw MiniMap-side refs at `0x00454e6f`, `0x00454e7b`, and `0x00454fcc` for `.mnm`, the S3 URL, and `Downloading : %d\n`.
  - MCP `lookup_funcs` confirmed the raw refs and raw helper start/end are not modeled functions, while the following modeled starts are `0x00455050`, `0x00455060`, and `0x004550d0`.
  - MCP `xrefs_to 0x00454e30` reported no incoming refs; `make_signature_for_range 0x00454e30-0x00455040` produced a unique function-shaped signature containing the same minimap download literals.
  - MCP `analyze_component` for `0x0041a750` and `0x00453aa0` reported matching WinINet/file API callee sets and shared globals for `szAgent`, `000`, `%03d`, `.mnm`, the S3 URL, `%s%s/%s%s`, and `Downloading : %d\n`.
  - Read-only PE byte audit decoded `0x0060d7f4-0x0060d8b8` as UTF-16LE `000`, `%03d`, `.mnm`, `https://s3.amazonaws.com/kru-downloads/tk/minimaps/`, `%s%s/%s%s`, and `Downloading : %d\n`; `0x0060d8b8` starts the next UTF-16LE `https://` child.
- Score/status/parent decisions:
  - [UID:0003FZ] `MinimapDownloadWideLiterals`: `87/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `89/93`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - No parent assignment was made. The child clears `85/85`, and [UID:0000JC] `FileDownloader` plus [UID:0000LE] `MiniMap` both clear `85/85`, but neither is the true direct owner of the whole pooled literal range. The evidence still supports FileDownloader message `10000`, MiniMapDownloader, and an unmodeled/raw MiniMap-side helper as separate consumers.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0003FZ ... 89`, `confidence_update 0003FZ ... 93`, and `autogen_report_noop ... auto-generated/-ag-memory-coverage.md unchanged`.
  - Generated coverage remains `unassigned` for [UID:0003FZ] by design because `AUTOGEN_PARENT_UID` is still blank.
- Supervisor-applied `by-memory/-coverage-report.md` row:
  - The supervisor applied and validated the Batch 320 replacement row for [UID:0003FZ] on 2026-06-12.
  - No Batch 320 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 322 A003 Report - 2026-06-12

- Assigned row:
  - [UID:000258] `by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md`
- Changed files:
  - `by-memory/0x00619344-0x006196c0.ErrorEventReadOnlyData.md`
  - `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md`
  - `by-memory/0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md`
  - `by-memory/0x00619670-0x006196a0.EventHandlerVtableData.md`
  - `by-memory/0x006196a0-0x006196b0.EventVtableData.md`
  - `by-memory/0x006196b0-0x006196bc.EventManVtableData.md`
  - `by-class/EventHandler.md`
  - `by-class/Event.md`
  - Validator-updated generated/index files: `auto-generated/-ag-memory-coverage.md`, `tools/validator.ini`, and `project-level/-auto-completion-stats.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before edits.
  - Leased the assigned aggregate, the two class gate pages, the five new exact child pages, and this `notes.md` before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
  - Did not edit `by-memory/-ignored.md` because A002 held an active lease while this batch was closing; the supervisor later applied and validated the ignored entry.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `entity_query names 0x00619448-0x006196c0` reported Error string labels and vtables at `0x0061962c`, `0x0061963c`, `0x00619648`, `0x00619650`, `0x00619674`, `0x006196a4`, and `0x006196b4`, with `0x006196c0` as the ExceptionHandler successor vtable.
  - MCP `lookup_funcs` confirmed the split addresses in the assigned `.rdata` range are data, not functions.
  - MCP `xrefs_to` reconfirmed string xrefs for `Win32Error` and `WININET.DLL`, EventDispatcher handler-tree table refs, EventHandler constructor/destructor/scalar-deleting-destructor refs, 79 refs to the Event vtable, and EventMan constructor/destructor refs.
  - Local PE byte/dword audit decoded the full Error UTF-16 literal run and the exact COL/vtable dwords through EventMan.
- Score/status/parent decisions:
  - [UID:000258] `ErrorEventReadOnlyData`: `85/90`, `RECONSTRUCTABLE:TRUE`, parent blank -> `89/92`, `RECONSTRUCTABLE:FALSE`, parent blank. No parent assignment: the aggregate is a reviewed non-emitting mixed Error/Event/EventDispatcher container.
  - [UID:0003I4] `ErrorHierarchyMessageStrings`: new exact child `86/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000J5] `Error` (`87/85`).
  - [UID:0003I5] `EventDispatcherHandlerTreeVtableData`: new exact child `86/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000J7] `EventDispatcher` (`89/85`).
  - [UID:0003I6] `EventHandlerVtableData`: new exact child `85/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:00004N] `EventHandler`; raised [UID:00004N] `82/88 -> 85/89`.
  - [UID:0003I7] `EventVtableData`: new exact child `85/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:00004L] `Event`; raised [UID:00004L] `84/88 -> 85/89`.
  - [UID:0003I8] `EventManVtableData`: new exact child `86/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:00004O] `EventMan` (already above gate).
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00619344-0x006196c0.ErrorEventReadOnlyData.md --apply --queue-timeout 180` and the same command for all five new child pages plus `by-class\EventHandler.md` and `by-class\Event.md`; combined loop exited `0`.
  - Validator applied `completion_update 000258 ... 89`, `confidence_update 000258 ... 92`, `autogen_registry_update 000258 ... true -> false`, inserted/generated UID links for [UID:0003I4]-[UID:0003I8], updated generated memory coverage, and accepted the class score updates.
  - Residual validator warnings: `missing_ref_target` / `autogen_registry_stale` for [UID:000257] and [UID:0002ND] were observed while A002 was actively repairing the neighboring `0x006192c6-0x00619448` boundary; A003 did not edit those leased pages.
- Supervisor-applied shared-file updates:
  - The supervisor merged this with A002 Batch 321, repaired [UID:000258]'s start boundary to `0x00619340`, applied and validated the `by-memory/-coverage-report.md` block for [UID:000257], [UID:000258], [UID:0002ND], and new children [UID:0003I4]-[UID:0003IC] on 2026-06-12.
  - The supervisor applied and validated the `by-memory/-ignored.md` entry for [UID:000258] on 2026-06-12.
  - No Batch 322 supervisor-owned shared-file updates remain pending.

## Batch 326 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002SP] `by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md`
- Changed files:
  - `by-memory/0x0061e704-0x0061e71c.GameServerConfigVtableData.md`
  - `by-memory/0x0061e704-0x0061e708.GameServerNationEntryProtectedArrayVtableData.md`
  - `by-memory/0x0061e708-0x0061e718.GameServerConfigClassVtableData.md`
  - `by-memory/0x0061e718-0x0061e71c.MapPaneRttiBoundaryData.md`
  - `by-memory/0x0061e704-0x0061eb08.MapPaneGameServerReadOnlyData.md`
  - `by-class/GameServerConfig.md`
  - `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`
  - `by-memory/-ignored.md`
  - Validator-updated generated/index files: `auto-generated/-ag-memory-coverage.md`, `tools/validator.ini`, and `project-level/-auto-completion-stats.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, aggregate parent, related class parents, three new child pages, `by-memory/-ignored.md`, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` confirmed `0x0061e700`, `0x0061e704`, `0x0061e708`, `0x0061e70c`, `0x0061e718`, and `0x0061e71c` are data addresses.
  - MCP `xrefs_to` reconfirmed five refs to `0x0061e704`, four refs to `0x0061e70c`, no refs to `0x0061e718`, and two `MapPane` vtable-store refs to `0x0061e71c`.
  - Local PE dword audit decoded `0x0061e704 -> 0x00514d50`, `0x0061e708 -> 0x0064b234`, `0x0061e70c -> 0x00514d80`, `0x0061e710 -> 0x004f4b10`, `0x0061e714 -> 0x0041b6c0`, and `0x0061e718 -> 0x0064b15c`.
- Score/status/parent decisions:
  - [UID:0002SP] `GameServerConfigVtableData`: `86/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/93`, `RECONSTRUCTABLE:FALSE`, parent blank. No parent assignment: the page is a reviewed split container across protected-array vtable, `GameServerConfig` class vtable, and trailing `MapPane` RTTI boundary ownership.
  - [UID:0003II] `GameServerNationEntryProtectedArrayVtableData`: new exact child `86/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000B4] `ProtectedArray_struct_GameServerConfig__NationEntry_` (`85/88`).
  - [UID:0003IJ] `GameServerConfigClassVtableData`: new exact child `87/93`, `RECONSTRUCTABLE:TRUE`, parent [UID:00005O] `GameServerConfig` (`85/86`).
  - [UID:0003IK] `MapPaneRttiBoundaryData`: new exact child `85/92`, `RECONSTRUCTABLE:FALSE`, parent blank; it is an unreferenced compiler/linker RTTI boundary dword before [UID:0002SQ] `MapPaneVtableData`.
  - [UID:00025S] `MapPaneGameServerReadOnlyData`: `86/93 -> 87/93`, remains `RECONSTRUCTABLE:FALSE`, parent blank.
  - [UID:0000B4] and [UID:00005O] scores unchanged; both gained exact vtable-child cross-references.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for the assigned target, aggregate parent, two class parents, three new child pages, and `by-memory\-ignored.md`; combined loop exited `0`.
  - Validator applied `completion_update 0002SP ... 88`, `confidence_update 0002SP ... 93`, `autogen_registry_update 0002SP ... true -> false`, accepted the new children [UID:0003II]-[UID:0003IK], and generated memory coverage now shows [UID:0003II] assigned to `0000B4`, [UID:0003IJ] assigned to `00005O`, [UID:0002SP]/[UID:00025S]/[UID:0003IK] as `not_reconstructable`.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Batch 326 `by-memory/-coverage-report.md` replacement block for [UID:00025S], [UID:0002SP], and children [UID:0003II]-[UID:0003IK] on 2026-06-12.
  - No Batch 326 supervisor-owned shared-file updates remain pending.

## Batch 329 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003G4] `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`
- Changed files:
  - `by-memory/0x00622f28-0x00622f3c.SharedReconnectWideString.md`
  - `by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md`
  - Validator-updated generated/index files: `tools/validator.ini` and `project-level/-auto-completion-stats.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits; no active leases were present.
  - Leased the target, containing string-tail map, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Local PE audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` decoded `0x00622f28-0x00622f3c` as UTF-16LE `Reconnect`, bytes `52 00 65 00 63 00 6f 00 6e 00 6e 00 65 00 63 00 74 00 00 00`.
  - The same audit found UTF-16 `Reconnect` spellings at `0x00622f28` and `0x006288b0`; the latter is outside the current child.
  - Pointer/immediate scan for `0x00622f28` found exactly four hits: `0x00553c45`, `0x00553cf5`, `0x0055435f`, and `0x0058b5b2`, matching the documented IDA xrefs at `0x00553c44`, `0x00553cf4`, `0x0055435e`, and `0x0058b5b1`.
- Score/status/parent decisions:
  - [UID:0003G4] `SharedReconnectWideString`: `86/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/93`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - No parent assignment was made. [UID:0000N0] `ReconnectDialog` is `87/88` and [UID:0000OI] `TerminalPane` is `87/85`; both clear `85/85`, but neither is the true direct owner of all observed uses of the pooled label.
  - [UID:0003CW] `ReconnectTerminalCopyStringTailMap` score unchanged at `89/93`; it gained updated child/evidence wording for [UID:0003G4].
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00622f28-0x00622f3c.SharedReconnectWideString.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0003G4 ... 88`, `confidence_update 0003G4 ... 93`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md --apply --queue-timeout 180`; exited `0` with `ok: 1`; generated memory coverage remained unchanged.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Batch 329 `by-memory/-coverage-report.md` nested replacement row for [UID:0003G4] under [UID:0003CW] on 2026-06-12.
  - No Batch 329 supervisor-owned shared-file updates remain pending.

## Batch 332 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003G7] `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`
- Changed files:
  - `by-memory/0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md`
  - `by-memory/0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md`
  - Validator-updated generated/index files: `tools/validator.ini` and `project-level/-auto-completion-stats.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the target, containing string-tail map, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Local PE audit against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` decoded `0x00622f4c-0x00622f54` as ANSI `baram` plus padding, bytes `62 61 72 61 6d 00 00 00`.
  - The same audit found ANSI `baram\0` only at `0x00622f4c`.
  - Pointer/immediate scan for `0x00622f4c` found exactly two hits: `0x00554277` and `0x0058b3fd`, matching the documented IDA xrefs at `0x00554276` and `0x0058b3fc`.
- Score/status/parent decisions:
  - [UID:0003G7] `SharedBaramPacketLiteral`: `86/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> `88/93`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - No parent assignment was made. [UID:0000N0] `ReconnectDialog` is `87/88` and [UID:0000OI] `TerminalPane` is `87/85`; both clear `85/85`, but neither is the true direct owner of both observed uses of the pooled packet literal.
  - [UID:0003CW] `ReconnectTerminalCopyStringTailMap` score unchanged at `89/93`; it gained updated child/evidence wording for [UID:0003G7].
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `completion_update 0003G7 ... 88`, `confidence_update 0003G7 ... 93`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00622f1c-0x00622f54.ReconnectTerminalCopyStringTailMap.md --apply --queue-timeout 180`; exited `0` with `ok: 1`; generated memory coverage remained unchanged.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Batch 332 `by-memory/-coverage-report.md` nested replacement row for [UID:0003G7] under [UID:0003CW] on 2026-06-12.
  - No Batch 332 supervisor-owned shared-file updates remain pending.

## Batch 334 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002YV] `by-memory/0x006307ec-0x00630a78.UserPaneOptionAndSocialPromptStrings.md`
- Changed files:
  - `by-memory/0x006307ec-0x00630a78.UserPaneOptionAndSocialPromptStrings.md`
  - `by-memory/0x006307ec-0x006309d0.UserPaneOptionStatusStrings.md`
  - `by-memory/0x006309d0-0x00630a78.UserPaneSocialPromptFragments.md`
  - `by-memory/0x006307ec-0x00630bd8.UserPaneInputStrings.md`
  - `by-file/UserPane.md`
  - `by-memory/-ignored.md`
  - Validator-updated generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator autogen backups.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, aggregate parent, direct `UserPane` parent page, `by-memory/-ignored.md`, this `notes.md`, and the two new child pages after creation.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `xrefs_to` reconfirmed every literal head from `0x006307ec` through `0x00630a6c`, including the previously omitted `!!`, `!`, `>`, `To `, and `! ` prompt fragments, and reconfirmed `0x00630a78` as the callback-vtable successor referenced from `0x005b7495`.
  - Read-only PE byte decoding confirmed UTF-16LE text for all literals, including Korean `화살이 부족합니다.` at `0x006309dc`.
- Score/status/parent decisions:
  - [UID:0002YV] `UserPaneOptionAndSocialPromptStrings`: `87/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `89/93`, `RECONSTRUCTABLE:FALSE`, parent blank. No parent assignment: the page is now a non-emitting split container.
  - [UID:0003J2] `UserPaneOptionStatusStrings`: new exact child `87/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:0000P1] `UserPane` (`89/85`). Assignment is allowed because all child xrefs are `UserPane` option/status handlers and both child and direct parent clear `85/85`.
  - [UID:0003J3] `UserPaneSocialPromptFragments`: new exact child `88/92`, `RECONSTRUCTABLE:TRUE`, parent blank. It clears `85/85`, but remains unassigned because direct ownership is mixed across `UserPane`, say/group/clan/shout, direct-message, and prompt helper families.
  - [UID:00026X] `UserPaneInputStrings` score remains `89/93`, still `RECONSTRUCTABLE:FALSE`, parent blank; it now documents the nested split under [UID:0002YV].
  - [UID:0000P1] `UserPane` score remains `89/85`; it gained the exact option/status string child.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Batch 334 `by-memory/-coverage-report.md` replacement block for [UID:00026X], [UID:0002YV], [UID:0003J2], [UID:0003J3], [UID:0002YW], and [UID:0002YX] on 2026-06-12.
  - No Batch 334 supervisor-owned shared-file updates remain pending.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for the two new child pages, assigned target, aggregate parent, `by-file\UserPane.md`, and `by-memory\-ignored.md`; combined loop exited `0`.
  - Validator applied `completion_update 0003J2 ... 87`, `confidence_update 0003J2 ... 92`, `autogen_registry_update 0003J2 ... -> 0000P1`, `completion_update 0003J3 ... 88`, `confidence_update 0003J3 ... 92`, and `autogen_registry_update 0002YV ... true -> false`.
  - Follow-up generated check confirmed [UID:0003J2] is assigned to `0000P1`, [UID:0002YV] is `not_reconstructable`, and [UID:0003J3] remains `unassigned` in `auto-generated/-ag-memory-coverage.md`.

## Batch 337 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00027Z] `by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md`
- Changed files:
  - `by-memory/0x0066df00-0x0066ed20.HeadSelectDialogLayoutTablePrimary.md`
  - `by-class/HeadSelectDialog.md`
  - `by-file/HeadSelectDialog.md`
  - `by-memory/0x00551030-0x005520e5.HeadSelectDialogCore.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator autogen backups.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, direct class parent, source-file parent, core memory evidence page, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `xrefs_to` reconfirmed primary-table refs at `0x00551145`, `0x005513f7`, and `0x00551b9e`, plus runtime tail-slot writes at `0x00551b29`, `0x00551b33`, and `0x00551b3d`; all are inside [UID:0001FI] `HeadSelectDialogCore`.
  - MCP decompilation of `0x00551030`, `0x00551350`, and `0x00551520` showed the normal-resolution branch uses `dword_66DF00[index]` when `byte_66DA97 != 1`, consumes only the low byte as a head-offset adjustment, and patches tail slots `900..902` to `-5`, `-8`, and `-2` in the constructor.
  - Read-only PE audit decoded the target as `0xe20` / 3616 bytes (Verified with `int_convert.py`) = `0x388` / 904 signed dwords (Verified with `int_convert.py`), with the first `0x384` / 900 dwords (Verified with `int_convert.py`) static and the final image dwords zero.
- Score/status/parent decisions:
  - [UID:00027Z] `HeadSelectDialogLayoutTablePrimary`: `72/88`, `RECONSTRUCTABLE:TRUE`, parent blank -> `86/91`, `RECONSTRUCTABLE:TRUE`, parent [UID:000062] `HeadSelectDialog`.
  - Assignment is allowed because the child is now `86/91`, the direct class parent is `86/87`, and every direct xref is inside the class core methods/constructor.
  - [UID:000062] `HeadSelectDialog` remains `86/87`; [UID:0000JT] `HeadSelectDialog` remains `87/86`; [UID:0001FI] `HeadSelectDialogCore` remains `84/86`.
  - Companion [UID:000281] `HeadSelectDialogLayoutTableSecondary` remains unassigned at `72/88`; it was not the assigned target and still needs a separate focused table review before routing.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for the assigned target, [UID:000062] class parent, [UID:0000JT] file parent, and [UID:0001FI] core memory evidence page; combined loop exited `0`.
  - Validator applied `completion_update 00027Z ... 86`, `confidence_update 00027Z ... 91`, `autogen_registry_update 00027Z ... -> 000062`, and `stats_row_remove 00027Z Low_Completion`.
  - Follow-up generated check confirmed [UID:00027Z] is `assigned` to `000062` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Batch 337 replacement row for [UID:00027Z] on 2026-06-12.
  - No Batch 337 supervisor-owned shared-file updates remain pending.

## Batch 339 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00029Q] `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`
- Changed files:
  - `by-memory/0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator autogen backups.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits; it had no active leases.
  - Leased the assigned target and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `xrefs_to` reconfirmed `0x0069b39c` refs only at `0x0060c161`, `0x0060c1d3`, and `0x0060c21c`; `0x0069b3a0` refs only at `0x0060c170` and `0x0060c226`; and `0x0069b3a4` refs only at `0x0060c1d9` and `0x0060c230`.
  - MCP decompiled `0x0060c160` as a static cleanup body for `0x18` / 24-byte string elements (Verified with int_convert.py), and decompiled `0x00419f40` as only `atexit(sub_60C160)`.
  - MCP `xrefs_to(0x00419f40)` reported only the startup initializer table entry at `0x0060d6b0`; nearby `0x0069b370-0x0069b3e0` IDA name query found no names.
  - Raw `NexusTK.exe` scan found VA immediates for `0x0069b39c`, `0x0069b3a0`, and `0x0069b3a4` only at the same seven cleanup-body sites, and found zero RVA-style hits for `0x0029b39c`, `0x0029b3a0`, or `0x0029b3a4`.
- Score/status/parent decisions:
  - [UID:00029Q] `StaticStringVectorStorage_69B39C`: `85/92`, `RECONSTRUCTABLE:TRUE`, parent blank -> `87/93`, `RECONSTRUCTABLE:TRUE`, parent blank.
  - No parent assignment was made. The child clears `85/85`, but the only proven refs are compiler/static-lifetime cleanup/registration refs; no direct source owner, normal-use path, constructor path, pointer table, source metadata, or semantic purpose clears the parent gate.
- Validation:
  - Ran `python .\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0069b39c-0x0069b3a8.StaticStringVectorStorage_69B39C.md --apply --queue-timeout 180`; exited `0`.
  - Validator applied `completion_update 00029Q ... 87`, `confidence_update 00029Q ... 93`, and `autogen_report_update ... auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Batch 339 replacement row for [UID:00029Q] `StaticStringVectorStorage_69B39C` on 2026-06-12.
  - No Batch 339 supervisor-owned shared-file updates remain pending.

## Batch 342 A003 Report - 2026-06-12

- Assigned row:
  - [UID:00029X] `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`
- Changed files:
  - `by-memory/0x0069b4b4-0x0069b4c8.MapNameMiniMapAndGameServerGlobals.md`
  - `by-memory/0x0069b4b4-0x0069b4b8.g_pMapNamePane.md`
  - `by-memory/0x0069b4b8-0x0069b4bc.g_pMiniMapButtonPane.md`
  - `by-memory/0x0069b4bc-0x0069b4c0.g_objectRecordCount.md`
  - `by-memory/0x0069b4c0-0x0069b4c4.g_objectNationMap.md`
  - `by-memory/0x0069b4c4-0x0069b4c8.g_gameServerNationTable.md`
  - `by-global/g_pMapNamePane.md`
  - `by-global/g_pMiniMapButtonPane.md`
  - `by-global/g_objectRecordCount.md`
  - `by-global/g_objectNationMap.md`
  - `by-global/g_gameServerNationTable.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator autogen backups.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, five exact child memory pages, five direct global parent pages, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `get_bytes` on 2026-06-12 A003 Batch342 reports zero bytes for `0x0069b4b4-0x0069b4c8` and for the wider `0x0069b4a0-0x0069b4c8` predecessor/target window.
  - MCP `xrefs_to` reconfirmed predecessor [UID:0002XO] at 20 refs, target counts `6/6/5/6/18`, and successor [UID:00029Y] begins with 7 refs at `0x0069b4c8`.
  - MCP decompilation reconfirmed `0x005031f0` publishes `dword_69B4B4`, `0x00503580` publishes `dword_69B4B8`, `0x00504110` reads/writes `dword_69B4BC`/`dword_69B4C0` and constructs/stores `dword_69B4C4`, `0x00504530` frees/clears `dword_69B4C0` and tears down `dword_69B4C4`, and `0x00514d80` clears `dword_69B4C4`.
  - Verified `0x14` / 20-byte aggregate size and `0x4` / 4-byte child-slot size with `int_convert.py`.
- Score/status/parent decisions:
  - [UID:00029X] `MapNameMiniMapAndGameServerGlobals`: `89/91`, `RECONSTRUCTABLE:TRUE`, parent blank -> `90/93`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - No aggregate parent assignment was made. The page is now a non-emitting mixed-owner split index: exact child/global pages carry the source declarations and valid direct-parent routing.
  - Child memory pages [UID:0002XD], [UID:0002XP], [UID:0002XQ], [UID:0002XR], and [UID:0002XS] kept their scores/parents and gained corrected active-IDB zero-initialization evidence.
  - Direct global parent pages [UID:0002XC], [UID:0000RN], [UID:0000Q4], [UID:0000Q3], and [UID:0000Q1] kept their scores/parents and gained the same byte correction.
- Validation:
  - Ran `python .\source-3\project-documentation\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for the assigned target, five child memory pages, and five direct global parent pages; combined loop exited `0`.
  - Validator applied `completion_update 00029X ... 90`, `confidence_update 00029X ... 93`, `autogen_registry_update 00029X ... true -> false`, and follow-up generated check confirmed [UID:00029X] is `not_reconstructable` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Batch 342 replacement block for [UID:00029X] and children [UID:0002XD], [UID:0002XP], [UID:0002XQ], [UID:0002XR], and [UID:0002XS] on 2026-06-12.
  - No Batch 342 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Batch 344 A003 Report - 2026-06-12

- Assigned row:
  - [UID:0003IB] `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md`
- Changed files:
  - `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md`
  - `by-class/Decoder.md`
  - `by-file/Decoder.md`
  - `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and validator autogen backups.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits; it had no active leases.
  - Leased the assigned target, Decoder class parent, Decoder source-root parent, containing read-only-data map, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active MCP session `b001_nexustk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `get_bytes` reconfirmed `0x006192d4-0x006192e0` as `74 6b 64 00 00 5e 4a 00 f0 5d 4a 00`, and the wider `0x006192c8-0x006192e0` window as adjacent Encoder vtable data followed by Decoder vtable data.
  - MCP `xrefs_to` reconfirmed zero refs to `0x006192d4`, three refs to vtable base `0x006192d8` at `0x004a5640`, `0x004a5670`, and `0x004a5e0a`, zero refs to no-op slot dword `0x006192dc`, and one successor DAT-table ref to `0x006192e0` from `0x004a5e9e`.
  - MCP `decompile` reconfirmed `0x004a5640` installs the Decoder vtable and clears stream fields, `0x004a5670` restores the vtable, `0x004a5dd0` clears stream state while returning prior valid state, and `0x004a5e00` restores the vtable before optional delete.
  - MCP `lookup_funcs` and `xrefs_to` reconfirmed every raw Decoder reader start from `0x004a5680` through `0x004a5db0` remains `Not a function` with no direct xrefs.
  - Verified the observed Decoder stream-state footprint `0x12` / 18 bytes and the vtable record size `0xc` / 12 bytes with `int_convert.py`.
- Score/status/parent decisions:
  - [UID:0003IB] `DecoderVtableData`: `88/91`, parent blank -> `90/93`, parent [UID:00003M] `Decoder`.
  - [UID:00003M] `Decoder` class: `80/82 -> 85/86`, existing parent [UID:0000IQ] `Decoder` retained.
  - [UID:0000IQ] `Decoder` source root: `83/84 -> 85/86`, reconstruction path unchanged at `NexusTK/util/`.
  - [UID:000257] `BinaryCodecDatReadOnlyData`: score unchanged `88/92`, remains `RECONSTRUCTABLE:FALSE`, parent blank; it now records that the Decoder vtable child routes to the Decoder class while the container remains mixed/non-emitting.
- Validation:
  - Ran `python .\source-3\project-documentation\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for `by-class/Decoder.md`, `by-file/Decoder.md`, the assigned target, and the containing read-only-data map; combined loop exited `0`.
  - Validator applied `completion_update 00003M ... 85`, `confidence_update 00003M ... 86`, and generated checks confirmed [UID:0003IB] is assigned to `00003M` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Batch 344 replacement block for [UID:000257], [UID:0003I9], [UID:0003IA], [UID:0003IB], and [UID:0003IC] on 2026-06-12.
  - No Batch 344 supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 0002RT A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002RT] `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`
- Changed files:
  - `by-memory/0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md`
  - Validator-owned generated/index files after validation: `project-level/-auto-completion-stats.md`, `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits; it had no active leases.
  - Leased the assigned target and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reconfirmed exact starts/sizes for `0x005832f0` (`0xa2`), `0x005833a0` (`0xa2`), `0x00583450` (`0x6`), `0x00583460` (`0x57`), `0x005834c0` (`0xf3`), `0x005835c0` (`0xa0`), `0x00583660` (`0x97`), and `0x00583700` (`0x14`); `0x00583714` is not a function and `0x00583720` starts the next ANSI format worker.
  - MCP `get_bytes` confirmed `0xcc` padding at `0x005832e3-0x005832f0`, `0x00583392-0x005833a0`, `0x00583442-0x00583450`, `0x00583456-0x00583460`, `0x005834b7-0x005834c0`, `0x005835b3-0x005835c0`, and `0x00583714-0x00583720`.
  - MCP `analyze_function` documented ANSI/wide release through `InterlockedDecrement(data - 0x0c)`, pool/heap return based on `data[-1]` capacity, `0x00583450` returning `*this - 12`, wide copy/share behavior, ANSI/wide detach paths, and the `0x00583700` wide varargs wrapper forwarding to `0x00583840`.
  - MCP `xrefs_to` reconfirmed `23` refs to wide sentinel `0x00670278`, `16` refs to ANSI sentinel `0x00670290`, and exactly four refs to each string pool global from `0x0069bacc` through `0x0069bbe4`.
- Score/status/parent decisions:
  - [UID:0002RT] `StringBaseReleaseAndCapacity`: `74/84`, parent [UID:0000OA] -> `87/90`, parent [UID:0000OA] retained.
  - Assignment remains allowed because the child is now `87/90`, the direct source-file parent [UID:0000OA][StringBase](../../../by-file/StringBase.md) is `88/86`, and all substantive helpers manipulate the same ref-counted `StringBase` header, sentinel, and pool storage. The `0x00583700` wrapper also stays in `StringBase` because it delegates directly to the wide vformat worker at `0x00583840`.
  - No repair to adjacent `SimpleUStringPointerBacked` / `LObjectStringReleaseFormatAndMutation` / `StringBaseCompareWideLiteral` barrier docs was made in this scoped pass. The target can route directly to `StringBase`; the broader overlap remains a separate aggregate/barrier cleanup issue.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x005832f0-0x00583714.StringBaseReleaseAndCapacity.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0002RT ... 87`, `confidence_update 0002RT ... 90`, `reference_index_add 0001J2`, `reference_index_add 0002LM`, `stats_row_remove 0002RT Low_Both`, `stats_row_remove 0002RT by-memory`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`. Generated `-ag-*` coverage reports were unchanged/no-op.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Goal 2 [UID:0002RT] `by-memory/-coverage-report.md` replacement row on 2026-06-12.
  - No Goal 2 [UID:0002RT] supervisor-owned shared-file updates remain pending.

## Goal 2 UID 0002RS A003 Report - 2026-06-12

- Assigned row:
  - [UID:0002RS] `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
- Changed files:
  - `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
  - Validator-owned generated/index files after validation: `project-level/-auto-completion-stats.md`, `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
  - Did not edit `by-memory/-ignored.md` because Agent-C001 held the active lease; exact pending ledger entry is below.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `entity_query` reconfirmed functions at `0x00584160`, `0x00584200`, `0x00584280`, `0x00584320`, `0x005843d0`, `0x00584470`, `0x00584540`, and `0x00584550`, with sibling `0x005845b0` immediately after the one-byte padding gap.
  - MCP `get_bytes` confirmed `0xcc` internal padding at `0x005841fc-0x00584200`, `0x00584278-0x00584280`, `0x0058431f-0x00584320`, `0x005843c8-0x005843d0`, `0x00584462-0x00584470`, `0x00584531-0x00584540`, and `0x00584543-0x00584550`, plus successor padding `0x005845af-0x005845b0`.
  - MCP `analyze_function` documented the ANSI/wide append fast paths over `data[-0x0c]` ref/share state, `data[-0x08]` length, and `data[-0x04]` capacity; slow paths call `0x00582ef0` for ANSI and `0x00582fa0` for UTF-16.
  - MCP `xref_query` reconfirmed small caller sets for append/fill/compare helpers and 171 code xrefs from 94 functions for the `0x00584540` data-pointer accessor.
- Score/status/parent decisions:
  - [UID:0002RS] `StringBaseAppendAndFind`: `74/84`, parent [UID:0000OA] -> `86/89`, parent [UID:0000OA] retained.
  - Assignment remains allowed because the child is now `86/89`, direct source-file parent [UID:0000OA][StringBase](../../../by-file/StringBase.md) is `88/86`, and every substantive helper manipulates the same ref-counted `StringBase` buffer/header or delegates to adjacent `StringBase` helpers.
  - No reconstruction C++ was emitted because final source names and the `StringBase`/`SimpleUString` facade relationship remain below the 95/95 final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00584160-0x005845af.StringBaseAppendAndFind.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0002RS ... 86`, `confidence_update 0002RS ... 89`, `stats_row_remove 0002RS Low_Both`, `stats_row_remove 0002RS by-memory`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, and generated `-ag-*` coverage reports unchanged/no-op.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Goal 2 [UID:0002RS] `by-memory/-coverage-report.md` replacement row and inserted the `0x005845af-0x005845b0` ignored padding row on 2026-06-13.
  - The supervisor applied and validated the matching `by-memory/-ignored.md` ledger entry on 2026-06-13.
  - Validation commands returned `ok: 1`; no Goal 2 [UID:0002RS] supervisor-owned shared-file updates remain pending.

## Goal 2 UID 0001CP A003 Supervisor-Applied by-memory Coverage - 2026-06-13

- Supervisor applied the exact `by-memory/-coverage-report.md` replacement block for [UID:0001CP] `MusicControlDialog` and its nested child split rows on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`.
- Result: `ok: 1`; validator added reference-index rows for [UID:0003MB]-[UID:0003MR] and refreshed generated memory coverage.
- No Goal 2 [UID:0001CP] supervisor-owned `by-memory/-coverage-report.md` updates remain pending.

## Supervisor-Applied by-memory Coverage Row - Goal 2 UID 0002U7

- The supervisor applied and validated the Goal 2 [UID:0002U7] `DATIndexVectorFillValueRangeHelper` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:0002U7] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 0002SA A003 Report - 2026-06-13

- Assigned row:
  - [UID:0002SA] `by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md`
- Changed files:
  - `by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md`
  - Validator-owned generated/index files after validation: `project-level/-auto-completion-stats.md`, `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - A003 held active leases for the assigned target and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reconfirmed no IDA function object at `0x005b4219`, `0x005b4220`, `0x005b4254`, or `0x005b4255`; the next function is `sub_5B4260` at `0x005b4260`, size `0x15c` / 348 bytes (Verified with `int_convert.py`).
  - MCP `get_bytes` reconfirmed seven predecessor `0xcc` bytes, the `0x35` / 53-byte constructor-shaped body (Verified with `int_convert.py`), and eleven tail `0xcc` bytes before `0x005b4260`.
  - MCP `xrefs_to` reconfirmed no direct refs to raw start `0x005b4220`; prompt/vtable refs for `0x00630a6c`, `0x0062fd00`, `0x0062fd50`, and `0x0062fd80` are limited to creator `0x005a5710` and this raw body.
  - MCP `analyze_function(0x005a5710)` reconfirmed allocation of `0x108` / 264 bytes (Verified with `int_convert.py`), the same prompt/base-constructor/vtable store sequence, and callers from `sub_4811C0`, `sub_5A5110`, and `sub_5A5BD0`.
  - MCP `analyze_function(0x004f1c00)` and existing parent docs identify the base constructor as `LineInputPane`; the submit vtable slot `0x0062fd48 -> 0x005b4260` ties the body to `ShoutInputPane`.
- Score/status/parent decisions:
  - [UID:0002SA] `ShoutInputPaneRawConstructor`: `74/84`, parent [UID:0000D5] -> `86/90`, parent [UID:0000D5] retained.
  - Assignment remains allowed because the child is now `86/90`, the direct class parent [UID:0000D5][ShoutInputPane](../../../by-class/ShoutInputPane.md) is `85/86`, and source-file parent [UID:0000N9][SayInputPanes](../../../by-file/SayInputPanes.md) is `88/87`.
  - No split, rename, or range change was made; `tools/memory_ranges.py report` was therefore not required.
  - No reconstruction C++ was emitted because the raw body lacks an IDA function object/direct caller and final source names/layout remain below the 95/95 gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0002SA ... 86`, `confidence_update 0002SA ... 90`, `stats_row_remove 0002SA Low_Completion`, `stats_row_remove 0002SA Low_Both`, `stats_row_remove 0002SA by-memory`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Follow-up checks confirmed `0002SA` is absent from `project-level/-auto-completion-stats.md` and remains assigned to `0000D5` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Goal 2 [UID:0002SA] `ShoutInputPaneRawConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:0002SA] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 0001MM A003 Report - 2026-06-13

- Assigned row:
  - [UID:0001MM] `by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md`
- Changed files:
  - `by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md` -> `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`
  - `by-class/ThrowReallyInputPane.md`
  - `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`
  - `by-file/ItemActionInputPanes.md`
  - `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`
  - Validator/tool-owned generated/index files after validation and range report: `auto-generated/-ag-memory-coverage.md`, `auto-generated/by-memory-tool-report.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before edits.
  - Leased the assigned target old/new path, class parent page, containing memory aggregate, source-file parent, vtable-family page, and this `notes.md`.
  - Did not directly edit `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, or `by-class/-coverage-report.md`. The validator performed a UID-link-only refresh in `by-memory/-coverage-report.md`; the score/range/body row replacement remains supervisor-owned below.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reconfirmed no IDA function object at `0x005b5b30`; successor `0x005b5b80` is `sub_5B5B80`, size `0xa0` / 160 bytes (Verified with `int_convert.py`).
  - MCP `get_bytes` reconfirmed the exact `0x4e` / 78-byte raw constructor body (Verified with `int_convert.py`) from `0x005b5b30` through the `retn 4` ending at `0x005b5b7e`, followed by two `0xcc` padding bytes at `0x005b5b7e-0x005b5b80`.
  - MCP `xrefs_to` reconfirmed no direct refs to raw start `0x005b5b30`; vtable store refs for `0x00630278`, `0x006302c8`, and `0x006302f8` appear in the raw body, `UserPane` inline construction at `0x005a7b87/0x005a7b8d/0x005a7b97`, and helper `0x005aba80` at `0x005abae5/0x005abaeb/0x005abaf5`.
  - MCP `analyze_function(0x005aba80)` reconfirmed allocation of `0x10c` / 268 bytes (Verified with `int_convert.py`), prompt id `0xa5`, `CharInputPane` base construction, and the item-slot copy to `+0x108`.
  - MCP `analyze_function(0x005b5b80)` reconfirmed `y`/`Y` acceptance and packet send through `g_packetSender` with opcode `0x17`, mode byte `1`, and the stored slot.
- Score/status/parent decisions:
  - [UID:0001MM] `ThrowReallyInputPaneRawConstructor`: `74/84`, range `0x005b5b30-0x005b5b80`, parent [UID:0000EZ] -> `86/90`, range `0x005b5b30-0x005b5b7e`, parent [UID:0000EZ] retained.
  - [UID:0000EZ] `ThrowReallyInputPane`: `82/84` -> `85/87`, parent [UID:0000KC] retained.
  - Assignment remains allowed because the child is now `86/90`, direct class parent [UID:0000EZ][ThrowReallyInputPane](../../../by-class/ThrowReallyInputPane.md) is `85/87`, and source-file parent [UID:0000KC][ItemActionInputPanes](../../../by-file/ItemActionInputPanes.md) is `90/85`.
  - No C++ reconstruction was emitted because the raw constructor still lacks an IDA function object/direct start xref and final source naming/layout remains below the 95/95 code gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 180` for the corrected target, `by-class/ThrowReallyInputPane.md`, `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`, `by-file/ItemActionInputPanes.md`, and `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`; combined loop exited `0`.
  - The target validation reported `ok: 1`, `path_update 0001MM ... 0x005b5b80... -> 0x005b5b7e...`, `completion_update 0001MM ... 86`, `confidence_update 0001MM ... 90`, `stats_row_remove 0001MM Low_Both`, `stats_row_remove 0001MM by-memory`, `autogen_registry_rebuild: 1`, and `autogen_report_update: 1`.
  - Follow-up checks confirmed [UID:0001MM] is absent from `project-level/-auto-completion-stats.md`, maps to `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md` in `tools/validator.ini`, and remains assigned to `0000EZ` in `auto-generated/-ag-memory-coverage.md`.
  - Ran `python .\tools\memory_ranges.py report`; exited `0` and wrote `auto-generated/by-memory-tool-report.md`.
- Supervisor-applied shared-file rows:
  - The supervisor applied and validated the Goal 2 [UID:0001MM] `ThrowReallyInputPaneRawConstructor` `by-memory/-coverage-report.md` replacement row, the `0x005b5b7e-0x005b5b80` padding row, the matching `by-memory/-ignored.md` ledger entry, and the [UID:0000EZ] `ThrowReallyInputPane` `by-class/-coverage-report.md` row on 2026-06-13.
  - Validation commands: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`, `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1`, and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --lock-timeout -1`; each returned `ok: 1`.
  - No Goal 2 [UID:0001MM] supervisor-owned shared-file rows remain pending.

## Goal 2 UID 0002JR A003 Report - 2026-06-13

- Assigned row:
  - [UID:0002JR] `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
- Changed files:
  - `by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md`
  - `by-class/NewHumanImageLib.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, direct class parent, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reconfirmed `sub_4DFD10` at `0x004dfd10`, size `0x53a` / 1338 bytes (Verified with `int_convert.py`), `0x004e024a` as not a function, and successor destructor `sub_4E0250` at `0x004e0250`.
  - MCP `analyze_function` recorded 61 basic blocks, cyclomatic complexity 6, 389 disassembly instructions including EH tails, one constructor xref at `0x004f60a1`, and callees covering `LObject` construction, DAT read/open/close helpers, `LoadMotionTable`, `LoadPartSpriteDescriptors`, `LoadAcc2DrwTable`, `ResolveSpritePartPath`, `MultiByteToWideChar`, vector growth helpers, integer conversion, and compiler/runtime helpers.
  - MCP `disasm` documented singleton writes at `0x004dfd67/0x004dfd6e`, vtable store at `0x004dfd78`, vector/list initialization through `+0x5c`, table load call sites, and constructor EH cleanup tails at `0x00600230` through `0x006002ad`.
  - MCP `get_bytes` confirmed `0x004e024a-0x004e0250` as six `0xcc` bytes and confirmed the UTF-16 resource-name bytes for `Motion.tbl`, `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, `.DSC`, `%s.EPF`, and `HAIRCOL.TBL`.
  - `tools/int_convert.py` verified constants used in the page: `0x17` = 23, `0x20` = 32, `0x44` = 68, `0x188` = 392, `0x1a8` = 424, and `0x5c` = 92. This repaired the stale `0x188` decimal value previously written as `528`.
  - MCP `trace_data_flow 0x0067a760` reconfirmed constructor writes, destructor clear, singleton-helper clear, and representative render/look/UI consumer reads for `g_pNewHumanImageLib`.
- Score/status/parent decisions:
  - [UID:0002JR] `NewHumanImageLibConstructor`: `74/86` -> `86/90`; `RECONSTRUCTABLE:TRUE` and direct parent [UID:000092][NewHumanImageLib](../../../by-class/NewHumanImageLib.md) retained.
  - [UID:000092] `NewHumanImageLib` class: score unchanged `85/85`; added an explicit parent-gate note tying the constructor to the class through `LObject` construction, vtable store, singleton publish, layout initialization, resource-family ownership, and the page's existing source-file parent [UID:0000LR][NewHumanImageLib](../../../by-file/NewHumanImageLib.md) at `87/85`.
  - Assignment remains allowed because the child is now `86/90`, direct class parent [UID:000092][NewHumanImageLib](../../../by-class/NewHumanImageLib.md) is `85/85`, and source-file parent [UID:0000LR][NewHumanImageLib](../../../by-file/NewHumanImageLib.md) is `87/85`.
  - No range, split, or rename was needed; `tools/memory_ranges.py --advanced-scan report` was therefore not required.
  - No reconstruction C++ was emitted because final field names, exact row type names, helper names, and source-level constructor form remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0002JR ... 86`, `confidence_update 0002JR ... 90`, `reference_index_add 000182`, `reference_index_add 000185`, `stats_row_remove 0002JR Low_Completion`, `stats_row_remove 0002JR Low_Both`, `stats_row_remove 0002JR by-memory`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-class\NewHumanImageLib.md --apply --queue-timeout 180`; compact confirmation returned `ok: 1`, `stats_incremental_noop 000092 ... file is not present in generated stats lists`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Follow-up checks confirmed [UID:0002JR] is absent from `project-level/-auto-completion-stats.md` and remains assigned to `000092` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Goal 2 [UID:0002JR] `NewHumanImageLibConstructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:0002JR] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 00023A A003 Report - 2026-06-13

- Assigned row:
  - [UID:00023A] `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
- Changed files:
  - `by-memory/0x00524590-0x005245b1.MetaManNodeDestroyHelper.md`
  - `by-class/MetaMan.md`
  - `by-class/-coverage-report.md`
  - Validator-owned generated/index files after validation: `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, direct class parent, class coverage report, and this `notes.md`.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override; exact replacement row is pending below.
- Fresh evidence:
  - Active IDA MCP session `a002_batch_clear_timer` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reported `0x00524590` as a `0x21` / 33-byte function (Verified with `int_convert.py`), `0x005245b1` as not a function, and successor [UID:0001CA] beginning at `0x005245c0`.
  - MCP `analyze_function(0x00524590)` reported one basic block, callers at `0x00523f3e`, `0x0052418c`, and `0x005243a3`, and callees at `0x00524400` and `0x005c7526`.
  - MCP disassembly/raw bytes show the helper computes node `+0x10`, calls the `0x00524400` small-string cleanup helper, then pushes `0x2c` / 44 bytes (Verified with `int_convert.py`) and calls the sized free routine for the node.
  - MCP `get_bytes` confirmed all-`0xcc` padding at `0x00524581-0x00524590` and `0x005245b1-0x005245c0`.
- Score/status/parent decisions:
  - [UID:00023A] `MetaManNodeDestroyHelper`: `74/86`, parent [UID:0000LC] -> `87/90`, parent [UID:000088].
  - [UID:000088] `MetaMan` class: `86/80` -> `86/85`, parent [UID:0000LC] retained.
  - Assignment/reroute is allowed because the child is now `87/90`, direct class parent [UID:000088][MetaMan](../../../by-class/MetaMan.md) is `86/85`, and source-file parent [UID:0000LC][MetaMan](../../../by-file/MetaMan.md) is `88/86`.
  - No split or rename was needed; the exact half-open function range and both adjacent padding spans were reconfirmed.
  - No reconstruction C++ was emitted because final helper spelling and whether the original source used a local tree wrapper or standard-library map/set instantiation remain below the 95/95 code gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00524590-0x005245b1.MetaManNodeDestroyHelper.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 00023A ... 87`, `confidence_update 00023A ... 90`, `autogen_registry_update 00023A ... 0000LC -> 000088`, `stats_row_remove 00023A Low_Completion`, `stats_row_remove 00023A Low_Both`, and `stats_row_remove 00023A by-memory`.
  - Ran `python .\tools\validator.py --mode file --file by-class\MetaMan.md --apply --queue-timeout 180` and `python .\tools\validator.py --mode file --file by-class\-coverage-report.md --apply --queue-timeout 180`; combined validation loop exited `0`.
  - Follow-up checks confirmed [UID:00023A] is absent from `project-level/-auto-completion-stats.md` and assigned to parent `000088` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement:
  - The supervisor applied and validated the Goal 2 [UID:00023A] `MetaManNodeDestroyHelper` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:00023A] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 00024E A003 Report - 2026-06-13

- Assigned row:
  - [UID:00024E] `by-memory/0x0060c0a0-0x0060c0f0.StaticCleanupThunksBeforeAutoInit.md`
- Changed files:
  - `by-memory/0x0060c0a0-0x0060c0f0.StaticCleanupThunksBeforeAutoInit.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/current_leases.md` before edits.
  - Leased the assigned target and this `notes.md`; refreshed both leases before editing.
  - Did not directly edit `by-memory/-coverage-report.md` per supervisor instruction.
  - Did not edit `by-memory/-ignored.md` because Agent-C001 held an active lease on that ledger; its row still says `stru_67A9A4` and should be updated later to `dword_67A998+0x0c` after that lease is clear.
- Fresh evidence:
  - Wave2 status refresh succeeded: 582 classes, 4167 total methods, 196 globals, average grade 96.9.
  - Active IDA MCP session `a001_goal2_collectionpane2_thunk` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` confirms exactly three function objects inside `0x0060c0a0-0x0060c0f0`: `sub_60C0A0` size `0xa` / 10 bytes (Verified with int_convert.py), `sub_60C0B0` size `0x22` / 34 bytes (Verified with int_convert.py), and `sub_60C0E0` size `0xa` / 10 bytes (Verified with int_convert.py); padding starts `0x0060c0aa`, `0x0060c0d2`, and `0x0060c0ea` are not functions; successor `sub_60C0F0` begins at `0x0060c0f0`.
  - MCP `get_bytes` confirms the `0x50` / 80-byte range size (Verified with int_convert.py), all thunk bytes, and three all-`0xcc` padding islands: `0x6` / 6 bytes, `0xe` / 14 bytes, and `0x6` / 6 bytes (Verified with int_convert.py), totaling `0x1a` / 26 padding bytes (Verified with int_convert.py).
  - MCP `disasm`/`decompile` confirm `sub_60C0A0` loads `unk_67A780` and tail-jumps to `sub_425200`; `sub_424850` lazily initializes/returns `unk_67A780` and registers the thunk through `_atexit`.
  - MCP `disasm`/`decompile` confirm `sub_60C0B0` pushes `Block` at `dword_67A998+4`, restores `dword_67A998` to `off_612574`, frees `Block`, and tail-jumps to `sub_4F4A90`; `sub_419E80` constructs/initializes the backing object and registers the thunk through `_atexit`.
  - MCP `disasm`/`decompile` confirm `sub_60C0E0` loads `dword_67A998+0x0c` / 12-byte offset (Verified with int_convert.py), tail-jumps to `loc_49BCC0`, and reaches `DeleteCriticalSection`; `sub_419EC0` initializes that same critical-section slot through `sub_49BCB0` / `InitializeCriticalSection` and registers the thunk through `_atexit`.
  - MCP `xrefs_to` confirms sole registration data xrefs to the three thunks at `0x004248c2`, `0x00419e8a`, and `0x00419eca`, plus backing-data refs for `unk_67A780`, `dword_67A998`, `Block`, and `dword_67A998+0x0c`.
  - MCP `entity_query 0x0067a780-0x0067a9f0` reports only `Block` at `0x0067a99c` and `VersionInformation` at `0x0067a9c0` as named globals, so final source names for `unk_67A780`/`dword_67A998` remain unresolved.
- Score/status/parent decisions:
  - [UID:00024E] `StaticCleanupThunksBeforeAutoInit`: `75/85` -> `86/90`.
  - `RECONSTRUCTABLE:FALSE`, blank `AUTOGEN_PARENT_UID`, and blank reconstruction C++ retained because the range is compiler/linker-generated `atexit` cleanup glue, not a source-level standalone item.
  - No split or rename was needed; the exact half-open range already matches live IDA function starts, padding islands, and successor `AutoInit` boundary.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0060c0a0-0x0060c0f0.StaticCleanupThunksBeforeAutoInit.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 00024E ... 86`, `confidence_update 00024E ... 90`, `reference_index_add 0000W7`, `stats_row_remove 00024E Low_Completion`, `stats_row_remove 00024E Low_Both`, `stats_row_remove 00024E by-memory`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Validator also reported pre-existing `autogen_registry_stale 0001I1 by-memory/0x00575d90-0x005796c7.SocketTransportCore.md registered file is missing`; this is unrelated to UID 00024E.
- Supervisor-owned `by-memory/-coverage-report.md` replacement row:
  - The supervisor applied and validated the [UID:00024E] `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:00024E] supervisor-owned `by-memory/-coverage-report.md` row remains pending.
- Supervisor-applied `by-memory/-ignored.md` wording cleanup:
  - The supervisor updated `by-memory/-ignored.md` from stale `stru_67A9A4` wording to `dword_67A998+0x0c` on 2026-06-13 after C001's lease cleared.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:00024E] supervisor-owned shared-file updates remain pending.

## Goal 2 UID 00028G A003 Report - 2026-06-13

- Assigned row:
  - [UID:00028G] `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md`
- Changed files:
  - `by-memory/0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned target and this `notes.md`.
  - Attempted to lease `by-memory/-ignored.md`; rejected because Agent-A001 held the active lease. Exact pending replacement text is below.
  - Did not directly edit `by-memory/-coverage-report.md` under the active supervisor override. Exact pending replacement row is below.
- Fresh evidence:
  - Active IDA MCP session `a003_goal2_rtti_type_descriptors` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `entity_query(kind=names, min_addr=0x006738c0, max_addr=0x0067a730)` reports `1508` named addresses in the half-open range, beginning with `??_R0?AVLObject@@@8`, `aAvlobject`, `??_R0?AVCashShopVersionRequest@@@8`, and `aAvcashshopvers`.
  - MCP `get_bytes` and `get_int` confirm the descriptor lead dword `0x00635078` at representative descriptors `0x006738c0`, `0x006738d8`, `0x0067a6c8`, and `0x0067a70c`; `tools/int_convert.py` verified the range size `0x6e70` / 28272 bytes.
  - MCP `get_string` confirms representative decorated names `.?AVLObject@@`, `.?AVCashShopVersionRequest@@`, `.?AV?$Singleton@VFileDownloader@@@@`, `.?AVbad_array_new_length@std@@`, `.?AV_com_error@@`, and `.?AVbad_exception@std@@`.
  - MCP bounded name queries confirm JsonCpp descriptors including `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, and `BuiltStyledStreamWriter`; standard-library/runtime descriptors including `runtime_error`, `basic_istream`, `bad_alloc`, `bad_array_new_length`, and `bad_exception`; and 282 singleton/template-related named anchors.
  - MCP `xrefs_to` confirms representative data xrefs from RTTI/class-hierarchy metadata to `0x006738c0`, `0x00673974`, `0x0067a6c8`, and `0x0067a70c`, including a runtime exception-handler reference to `0x0067a70c` from `??$FindHandler@V__FrameHandler3@@@@...`.
  - MCP `get_bytes(0x0067a70c, 36)`, `get_bytes(0x0067a72f, 1)`, and `get_bytes(0x0067a730, 32)` confirm the final `std::bad_exception` descriptor/name terminates before `0x0067a730`, and the successor bytes are zeroed CRT/global storage. Neighbor pages [UID:00028F] and [UID:00028H] already document the predecessor and successor boundaries.
- Score/status/parent decisions:
  - [UID:00028G] `CppRttiTypeDescriptorData`: `75/85` -> `88/91`.
  - `RECONSTRUCTABLE:FALSE`, blank `AUTOGEN_PARENT_UID`, and blank reconstruction C++ retained because the range is compiler/linker-generated RTTI/type-name data spanning many project classes, JsonCpp classes, STL/Dinkumware templates, COM/error records, and standard exceptions.
  - No assignment was made. The item is not a source-level object and has no single direct semantic parent; exact source-owned classes and third-party/runtime libraries should carry their own declarations.
  - No split or rename was needed; this is a coherent compiler-generated type-descriptor/string pool with documented predecessor and successor boundaries.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x006738c0-0x0067a730.CppRttiTypeDescriptorData.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 00028G ... 88`, `confidence_update 00028G ... 91`, `reference_index_add 00028F`, `reference_index_add 00028H`, `stats_row_remove 00028G Low_Completion`, `stats_row_remove 00028G Low_Both`, `stats_row_remove 00028G by-memory`, `projected_stats_update: 1`, and `autogen_registry_rebuild: 1`.
  - Validator also reported pre-existing `autogen_registry_stale` entries for [UID:0001I8] `by-memory/0x005797b0-0x0057bc58.SoundManager.md` and [UID:0001IC] `by-memory/0x0057b490-0x0057bc58.SoundManagerDriverAndDestructor.md`; these are unrelated to UID 00028G.
- Supervisor-applied shared-file updates:
  - The supervisor applied and validated the Goal 2 [UID:00028G] `CppRttiTypeDescriptorData` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - The supervisor applied and validated the matching `by-memory/-ignored.md` ignored-ledger replacement entry on 2026-06-13.
  - Validation commands:
    - `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
    - `python .\tools\validator.py --mode file --file by-memory\-ignored.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:00028G] supervisor-owned shared-file updates remain pending.

## Goal 2 UID 0000C9 Supervisor-Applied by-memory/-coverage-report.md Cleanup

- The supervisor applied and validated the Goal 2 ScreenEffecter read-only-data replacement rows for [UID:00026C] and [UID:0002OR] on 2026-06-13.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:0000C9] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 00007V A003 Supervisor-applied by-memory/-coverage-report.md Rows - 2026-06-13

- The supervisor applied and validated the replacement rows for `0002J3`, `0002J4`, `0002JH`, `0002J5`, `0002JI`, `0002JJ`, `0002JK`, and `0002JF` inside `by-memory/-coverage-report.md` under the `0x00516290-0x00517441.MenuPaneAndItems` block.
- Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No Goal 2 [UID:00007V] supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 UID 00007V A003 Report - 2026-06-13

- Assigned row:
  - [UID:00007V] `by-class/MenuItem.md`
- Changed files:
  - `by-class/MenuItem.md`
  - `by-type/by-struct/MenuItemLayouts.md`
  - `by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md`
  - `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`
  - `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`
  - `by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md`
  - `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`
  - `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`
  - `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`
  - `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
  - `by-class/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Validator-owned generated/state side effects observed after validation:
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Fresh evidence:
  - Active IDA MCP session `a003_goal2_rtti_type_descriptors` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - MCP `lookup_funcs` reconfirmed the `MenuItem` modeled base functions: `0x00516f00` size `0x67` / 103 bytes, `0x00516f70` and `0x00516f90` size `0x04` / 4 bytes, `0x005172e0` size `0x3e` / 62 bytes, and successor `0x00517450`. Decimal values were verified with `tools/int_convert.py`.
  - MCP `get_bytes` and `insn_query` reconfirmed the raw helper-shaped bodies at `0x00516f80`, `0x00516fa0`, `0x00516fb0`, and `0x00516fd0`, including state-byte writes and bounds `movups` copies.
  - MCP `xrefs_to` reconfirmed base/string/separator vtable writes at `0x00516f41`, `0x00517031`, `0x005171f1`, `0x005172e6`, `0x00517406`, `0x0051704e`, and `0x00517205`.
  - MCP `analyze_function 0x00516400` and `insn_query 0x00516c40-0x00516cf3` confirmed `MenuPane` bounds and enabled-state consumers; `insn_query 0x005170f0-0x005171a2` confirmed `StringMenuItem` highlight-state consumption.
- Score/status/parent decisions:
  - [UID:00007V] `MenuItem`: `76/84` -> `86/88`; `RECONSTRUCTABLE:TRUE` and source-file parent [UID:0000MN][PopupMenuControls](../../../by-file/PopupMenuControls.md) retained.
  - [UID:0001V5] `MenuItemLayouts`: `84/88` -> `85/89`; parent [UID:0000MN][PopupMenuControls](../../../by-file/PopupMenuControls.md) retained because the layout page spans `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem`.
  - Eight base-owned by-memory children were rerouted from file parent [UID:0000MN][PopupMenuControls](../../../by-file/PopupMenuControls.md) to direct class parent [UID:00007V][MenuItem](../../../by-class/MenuItem.md): `0002J3`, `0002J4`, `0002JH`, `0002J5`, `0002JI`, `0002JJ`, `0002JK`, and `0002JF`.
  - No final C++ was emitted because final flag names, exact source method names for the raw helpers, and possible `MenuItem.cpp` split remain below the `95/95` final-source gate.
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` over the changed class, layout, eight by-memory method pages, and both coverage reports. The final `by-type/by-struct/-coverage-report.md` job timed out while queued behind concurrent work, then succeeded when rerun with `--queue-timeout 600`.
  - Observed validator success included `ok: 1`, `completion_update 00007V ... 86`, `confidence_update 00007V ... 88`, `completion_update 0001V5 ... 85`, `confidence_update 0001V5 ... 89`, autogen registry rebuilds, and generated coverage refreshes.
  - Follow-up checks confirmed [UID:00007V] is absent from `project-level/-auto-completion-stats.md`, [UID:00007V] remains assigned to [UID:0000MN][PopupMenuControls](../../../by-file/PopupMenuControls.md) in `auto-generated/-ag-class-coverage.md`, and the eight base method children are now assigned to parent `00007V` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-owned pending rows:
  - None. The supervisor applied and validated the Goal 2 [UID:00007V] `by-memory/-coverage-report.md` replacement rows for `0002J3`, `0002J4`, `0002JH`, `0002J5`, `0002JI`, `0002JJ`, `0002JK`, and `0002JF` on 2026-06-13.

## Goal 2 UID 00012Y A003 Report - 2026-06-13

- Assigned row:
  - [UID:00012Y] `by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md`
- Changed files:
  - Renamed `by-memory/0x004a06e0-0x004a0714.VersatileAlertPaneRawCleanup.md` -> `by-memory/0x004a06e0-0x004a0715.VersatileAlertPaneRawCleanup.md`
  - `by-class/VersatileAlertPane.md`
  - `by-class/-coverage-report.md`
  - `by-memory/0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md`
  - `by-file/AlertPanes.md`
  - `by-type/by-vtable/VersatileAlertPaneVtables.md`
  - `by-type/by-struct/AlertPaneLayout.md`
  - Validator-owned/generated side effects observed: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `by-memory/-coverage-report.md` UID link annotation, `by-project-structure/proposed-source-tree.md` UID link annotations, and validator registry/autogen refresh output.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before edits.
  - Leased the assigned target, corrected renamed target path, direct class parent, class coverage report, support docs, and this notes file as A003 before editing.
  - Did not manually edit `by-memory/-coverage-report.md`; validator file-mode updated only the UID link annotation after the target rename, and the exact row replacement remains pending below for supervisor application.
- Fresh evidence:
  - Active IDA MCP session targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, and Hex-Rays ready.
  - `lookup_funcs` reports `0x004a06e0`, `0x004a0710`, and `0x004a0714` as not functions; surrounding functions are constructor `0x004a0690` size `0x47` / 71 bytes, `OnAccept` `0x004a0720` size `0x12` / 18 bytes, `OnCancel` `0x004a0740` size `0x12` / 18 bytes, `ModelessDialogPane` successor `0x004a0760` size `0xc7` / 199 bytes, and deleting destructor `0x004a0cd0` size `0x67` / 103 bytes. Decimal values were verified with `tools/int_convert.py`.
  - `insn_query 0x004a06d0-0x004a0720` shows constructor return through `0x004a06d4`, `0xcc` alignment at `0x004a06d7-0x004a06df`, cleanup code at `0x004a06e0-0x004a0715`, and `0xcc` alignment beginning at `0x004a0715`.
  - `get_bytes(0x004a06e0, 0x34)` showed the 52-byte read still ends inside the tail-jump immediate, while `get_bytes(0x004a0714, 12)` showed byte `0xff` at `0x004a0714` followed by `0xcc` padding. This proves the exact half-open range is `0x004a06e0-0x004a0715`.
  - `xrefs_to 0x004a06e0` and `xref_query direction=to` report zero entry references. `xref_query direction=from 0x004a0710` resolves the tail jump to `0x0049d9f0`, currently polluted as `boost::exception::~exception`.
  - `xrefs_to` the vtable bases `0x00618ba4`, `0x00618c0c`, and `0x00618c3c` shows constructor stores, cleanup-body stores, and deleting-destructor stores for all three tables.
  - Constructor/callback/destructor analysis confirms callback/control storage at `+0x270` / 624 bytes and accept/cancel callback dispatch through slot `+0x0c` / 12 bytes. Decimal values were verified with `tools/int_convert.py`.
- Score/status/parent decisions:
  - [UID:00012Y] `VersatileAlertPaneRawCleanup`: `76/84` -> `86/89`; range corrected to half-open `0x004a06e0-0x004a0715`; `RECONSTRUCTABLE:TRUE` retained; direct parent [UID:0000FU] retained.
  - [UID:0000FU] `VersatileAlertPane`: `86/82` -> `86/86`; direct file parent [UID:0000HE] retained.
  - The assignment gate now clears: child `86/89`, direct class parent `86/86`, source-file parent [UID:0000HE] `AlertPanes` already `85/88`.
  - No reconstruction C++ was emitted because the unreferenced cleanup source representation, callback interface spelling, and shared alert base teardown name remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x004a06e0-0x004a0715.VersatileAlertPaneRawCleanup.md --apply --queue-timeout 180`; exited `0`, `ok: 1`, `path_update 00012Y ... 0x004a0714... -> 0x004a0715...`, `completion_update 00012Y ... 86`, `confidence_update 00012Y ... 89`, `stats_row_remove 00012Y Low_Completion`, `stats_row_remove 00012Y Low_Both`, and `stats_row_remove 00012Y by-memory`.
  - Ran file-mode validation with `--apply --queue-timeout 180` for `by-class\VersatileAlertPane.md`, `by-class\-coverage-report.md`, `by-memory\0x004a0690-0x004a0752.VersatileAlertPaneCallbacks.md`, `by-file\AlertPanes.md`, `by-type\by-vtable\VersatileAlertPaneVtables.md`, and `by-type\by-struct\AlertPaneLayout.md`; loop exited `0`.
  - Validator reported an unrelated pre-existing stale/missing target [UID:0001NP] `by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md`, currently leased by C001. No action taken for this target.
  - Follow-up checks confirmed [UID:00012Y] is absent from `project-level/-auto-completion-stats.md` and assigned to parent `0000FU` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None. The supervisor applied and validated the [UID:00012Y] `VersatileAlertPaneRawCleanup` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. The validator also reported the unrelated C001-owned [UID:0001NP] MenuVariety path while that barrier repair was active.
- Non-editable historical follow-ups:
  - `wave3_data_issues.md` still mentions the old `0x004a06e0-0x004a0714` range/path in historical notes. A future allowed pass should update those references or add a follow-up note that the corrected half-open by-memory page is `0x004a06e0-0x004a0715`.

## Goal 2 UID 000163 A003 Report - 2026-06-13

- Assigned row:
  - [UID:000163] `by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md`
- Changed files:
  - Renamed `by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md` -> `by-memory/0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md`
  - `by-class/GrafPort.md`
  - `by-class/UserFaceColorSelectListPane.md`
  - `by-class/UserHairColorSelectListPane.md`
  - `by-file/UserCreateAppearanceControls.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
  - Validator-owned/generated side effects observed: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, UID link annotations for references to UID `000163`, and validator registry/autogen refresh output.
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the old target path, renamed target path, `by-class/GrafPort.md`, `by-class/UserFaceColorSelectListPane.md`, `by-class/UserHairColorSelectListPane.md`, `by-file/UserCreateAppearanceControls.md`, and this `notes.md` as Agent-A003.
  - Did not manually edit `by-memory/-coverage-report.md` under the active supervisor override; the supervisor-applied row is recorded below.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, and Hex-Rays ready.
  - MCP `lookup_funcs` reconfirmed `sub_4B96A0` size `0x7` / 7 bytes and `sub_4B96B0` size `0x10` / 16 bytes (Verified with int_convert.py); `0x004b96a7` is not a function and successor helper `sub_4B96C0` starts at `0x004b96c0`.
  - MCP `make_signature_for_range 0x004b96a0-0x004b96c0` returned unique bytes for the full `0x20` / 32-byte range (Verified with int_convert.py), including the nine-byte `0xcc` padding island.
  - MCP `analyze_function`, `decompile`, and `disasm` confirmed `GetBrushHandle` is a no-callee leaf load from `[ecx+84h]`, and `SetBrushHandle` stores its argument to `[ecx+84h]`, returns it, has no callees, and uses `retn 4`.
  - Direct caller evidence remains `sub_467B30`, `sub_4836A0`, `sub_501F30`, and `sub_5021F0`; linked docs identify these as balloon paint, color-string chat drawing, hair-color swatch drawing, and face-color swatch drawing consumers.
- Score/status/parent decisions:
  - [UID:000163] `DrawContextBrushHandleHelpers`: `76/84` -> `86/90`.
  - Corrected stale inclusive-style range/path to half-open `0x004b96a0-0x004b96c0`.
  - Rerouted `AUTOGEN_PARENT_UID` from file parent [UID:0000JR][GrafPort](../../../by-file/GrafPort.md) to direct class parent [UID:00005V][GrafPort](../../../by-class/GrafPort.md). The child clears `86/90`, the class parent is already `85/87`, and the file parent is already `88/85`.
  - `RECONSTRUCTABLE:TRUE` retained. Final reconstruction C++ remains blank because the final public method names and `this + 0x84` field name are below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x004b96a0-0x004b96c0.DrawContextBrushHandleHelpers.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `path_update 000163 ... 0x004b96bf... -> 0x004b96c0...`, `completion_update 000163 ... 86`, `confidence_update 000163 ... 90`, `autogen_registry_update 000163 ... 0000JR -> 00005V`, `stats_row_remove 000163 Low_Completion`, `stats_row_remove 000163 Low_Both`, `stats_row_remove 000163 by-memory`, `reference_source_path_update` rows, and UID link updates for references to UID `000163`.
  - Ran `python .\tools\validator.py --mode file --file by-class\GrafPort.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `stats_incremental_noop 00005V ... file is not present in generated stats lists`, and autogen/generated coverage no-ops for the class support page.
  - Ran `python .\tools\validator.py --mode file --file by-class\UserFaceColorSelectListPane.md --apply --queue-timeout 180`; exited `0`, `ok: 1`, `reference_index_add 00005V`, and stats/autogen no-op aside from projected stats refresh.
  - Ran `python .\tools\validator.py --mode file --file by-class\UserHairColorSelectListPane.md --apply --queue-timeout 180`; exited `0`, `ok: 1`, `reference_index_add 00005V`, and stats/autogen no-op aside from projected stats refresh.
  - Ran `python .\tools\validator.py --mode file --file by-file\UserCreateAppearanceControls.md --apply --queue-timeout 180`; exited `0`, `ok: 1`, `reference_index_add 00005V`, and stats/autogen no-op aside from projected stats refresh.
- Supervisor-applied `by-memory/-coverage-report.md` replacement row:
  - The supervisor applied and validated the [UID:000163] `DrawContextBrushHandleHelpers` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:000163] supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## Goal 2 UID 00018S A003 Report - 2026-06-13

- Assigned row:
  - [UID:00018S] `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`
- Changed files:
  - `by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md`
  - `by-class/LanguageMan.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the target, `by-class/LanguageMan.md`, and this notes file as Agent-A003 before editing.
  - Did not manually edit `by-memory/-coverage-report.md` under the active supervisor override; supervisor applied and validated the replacement row after review.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed `0x004f0290` as a function named `??1exception@boost@@MAE@XZ_3` with size `0x80` / 128 bytes (Verified with int_convert.py), ending at `0x004f0310`; neighboring starts are constructor `0x004f0010`, adjacent zero-initializer `0x004f0310`, scalar deleting destructor `0x004f03d0`, and successor `0x004f0480`.
  - MCP `analyze_function`, `decompile`, and `disasm` confirmed zero direct callers, three callees (`sub_516030`, `sub_516170`, `sub_4F4A90`), LanguageMan vtable write at `0x004f02b7`, per-string free loop over `this + 0x4` with count at `this + 0x8`, table free, `g_pLanguageMan` clear at `0x004f02ef`, and `LObject` base teardown.
  - MCP `analyze_component 0x004f0290,0x004f03d0` reports shared globals `off_61C9E0`, `___security_cookie`, and `dword_67A750`, proving state parity with the vtable-referenced scalar deleting destructor.
  - MCP `make_signature_for_range 0x004f0290-0x004f0310` returned a unique full-range byte signature.
- Score/status/parent decisions:
  - [UID:00018S] `LanguageManCleanupDestructor`: `76/84` -> `86/90`.
  - `RECONSTRUCTABLE:TRUE` retained and `RECONSTRUCTION_CPP CODE` left blank because helper names and final source-level destructor spelling are below the `95/95` final-source gate.
  - `AUTOGEN_PARENT_UID` rerouted from file parent [UID:0000KK][LanguageMan](../../../by-file/LanguageMan.md) to direct class parent [UID:000071][LanguageMan](../../../by-class/LanguageMan.md). The child clears `86/90`, direct class parent clears `86/88`, and source-file parent clears `88/85`.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x004f0290-0x004f0310.LanguageManCleanupDestructor.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 00018S ... 86`, `confidence_update 00018S ... 90`, `autogen_registry_update 00018S ... 0000KK -> 000071`, `stats_row_remove 00018S Low_Completion`, `stats_row_remove 00018S Low_Both`, `stats_row_remove 00018S by-memory`, `autogen_report_update: 1`, and an unrelated pre-existing stale registry entry for [UID:0001JM] `by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md`.
  - Ran `python .\tools\validator.py --mode file --file by-class\LanguageMan.md --apply --queue-timeout 180`; exited `0`.
  - Filtered confirmation rerun for `by-class\LanguageMan.md` reported `mode: file`, `scanned markdown files: 1`, `ok: 1`, `stats_incremental_noop 000071 ... file is not present in generated stats lists`, and `autogen_report_noop: 7`.
  - Follow-up checks confirmed [UID:00018S] is absent from `project-level/-auto-completion-stats.md` and assigned to parent `000071` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement row:
  - Supervisor applied and validated the [UID:00018S] `LanguageManCleanupDestructor` `by-memory/-coverage-report.md` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 [UID:00018S] supervisor-owned `by-memory/-coverage-report.md` row remains pending.

## Goal 2 UID 00019O A003 Report - 2026-06-13

- Assigned row:
  - [UID:00019O] `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md`
- Changed files:
  - `by-memory/0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md`
  - `by-global/HandleLegacyMainMenuPacket_4F8D00.md`
  - `by-global/-coverage-report.md`
  - Validator-owned/generated side effects observed: `auto-generated/-ag-global-coverage.md`, `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned memory target, support global page, `by-global/-coverage-report.md`, and this notes file as Agent-A003 before editing.
  - Also leased `by-memory/-coverage-report.md` only to document the current owner state; did not edit it under the active supervisor override. Exact pending row is below.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` confirmed `sub_4F8D00` size `0x202` / 514 bytes, sole caller inside `sub_4F6D80` at `0x004f74b7`, and successor `sub_4F8F10` at `0x004f8f10`; decimal values were verified with `tools/int_convert.py`.
  - MCP `analyze_function 0x004f8d00` confirmed the packet helper parses payload fields at `+1`, `+5`, `+7`, and `+8`, copies the inbound message into a 256-byte local buffer, raises AlertPane/exit on failed status, and otherwise builds an outbound opcode `0x10` packet with a 1023-byte text tail and `g_useEpfAssets` append before queueing it through `g_packetSender`.
  - MCP xrefs confirmed `sub_5228F0(unk_69B410)` is shared only with the earlier same-dispatch path at `0x004f711b`, and `dword_69AE08` is an optional callback/global dispatch used by modal menu code.
  - MCP `get_bytes` proved the function ends with `retn 4` at `0x004f8ef8-0x004f8f02`, followed by fourteen bytes of `0xcc` padding before `OpenTransferServerDialog`; `make_signature_for_range 0x004f8d00-0x004f8f02` returned a unique full-range signature.
- Score/status/parent decisions:
  - [UID:00019O] `LegacyMainMenuPacket`: `76/84` -> `87/90`.
  - `RECONSTRUCTABLE:TRUE` retained; no final C++ emitted because opcode semantics, packet field names, and exact source helper names remain below the `95/95` final-source gate.
  - Direct parent retained as [UID:0000L0][MainMenuPane](../../../by-file/MainMenuPane.md), which already clears `89/86`. The helper is a standalone file-local packet routine with no `this`-typed class ownership, so class parent [UID:00007O][MainMenuPane](../../../by-class/MainMenuPane.md) is supporting context rather than the direct parent.
  - [UID:0000SZ] `HandleLegacyMainMenuPacket_4F8D00`: `84/88` -> `86/90`; parent [UID:0000L0] retained.
  - `by-global/-coverage-report.md` row for [UID:0000SZ] updated from `84%` to `86%`.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x004f8d00-0x004f8f02.LegacyMainMenuPacket.md --apply --queue-timeout 180`; exited `0` and reported `ok: 1`, `completion_update 00019O ... 87`, `confidence_update 00019O ... 90`, `stats_row_remove 00019O Low_Completion`, `stats_row_remove 00019O Low_Both`, `stats_row_remove 00019O by-memory`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-global\HandleLegacyMainMenuPacket_4F8D00.md --apply --queue-timeout 180`; filtered confirmation reported `mode: file`, `scanned markdown files: 1`, `ok: 1`, `stats_incremental_noop 0000SZ`, `projected_stats_update`, and generated coverage no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-global\-coverage-report.md --apply --queue-timeout 180`; filtered confirmation reported `mode: file`, `scanned markdown files: 1`, `ok: 1`, `stats_incremental_noop 0000PD`, `projected_stats_update`, and generated coverage no-ops.
  - Follow-up checks confirmed [UID:00019O] is absent from `project-level/-auto-completion-stats.md`, [UID:00019O] remains assigned to parent `0000L0` in `auto-generated/-ag-memory-coverage.md`, and [UID:0000SZ] remains assigned to parent `0000L0` in `auto-generated/-ag-global-coverage.md`.
- Supervisor-owned `by-memory/-coverage-report.md` replacement row:
  - None. Supervisor applied and validated the [UID:00019O] `LegacyMainMenuPacket` replacement row on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.

## Goal 2 UID 0001C9 A003 Report - 2026-06-13

- Assigned row:
  - [UID:0001C9] `by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md`
- Changed files:
  - `by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md`
  - `by-memory/0x005227d0-0x00524581.MetaMan.md`
  - Validator-owned/generated side effects observed: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned memory target, containing `MetaMan` memory aggregate, and this notes file as Agent-A003 before editing.
  - Did not lease or edit `by-memory/-coverage-report.md` under the active supervisor override. Exact pending replacement rows are below.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` confirmed `sub_523A00` size `0x65` / 101 bytes, `sub_523A70` size `0xc9` / 201 bytes, `sub_523B40` size `0x159` / 345 bytes, and successor `sub_523CA0` at `0x00523ca0`; decimal values were verified with `tools/int_convert.py`.
  - MCP `analyze_function` confirmed the direct row-count helper, indexed row-value helper, and multi-value copy helper all call `FindTableByName`, lazy materializer `0x00524870`, and row-tree lookup `0x005245c0` before reading row value spans.
  - MCP `analyze_function 0x00523120` and `0x005231f0` confirmed alias-aware `FindEntry`/`LoadStatValues` caller behavior, including `g_metaAliasTableName` enumeration and fallback to the caller-provided table name.
  - MCP `disasm 0x00523020` exposed an IDA-unmodeled `0x00523030-0x00523114` alias-aware value-count wrapper that calls `sub_523A00` at `0x00523108`.
  - MCP `get_bytes` confirmed internal `0xcc` padding at `0x00523a65-0x00523a70` and `0x00523b39-0x00523b40`, plus post-range padding at `0x00523c99-0x00523ca0`; `make_signature_for_range 0x00523a00-0x00523c99` returned a unique full-range signature.
- Score/status/parent decisions:
  - [UID:0001C9] `MetaManLookupHelpers`: `76/84` -> `87/90`; `RECONSTRUCTABLE:TRUE` retained.
  - `AUTOGEN_PARENT_UID` remains [UID:0000LC][MetaMan](../../../by-file/MetaMan.md), which already clears `88/86`, because these are source-local/static-style lookup helpers shared by MetaMan methods rather than proven emitted class methods.
  - [UID:0001C8] `MetaMan` memory aggregate: `82/86` -> `85/88`; parent [UID:0000LC] retained. This containing/support page now clears the strict `85/85` gate.
  - No reconstruction C++ was emitted because final helper names, exact row/value-vector field names, and the final split/name for `0x00523030-0x00523114` remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00523a00-0x00523c99.MetaManLookupHelpers.md --apply --queue-timeout 180`; exited `0` and reported `ok: 1`, `completion_update 0001C9 ... 87`, `confidence_update 0001C9 ... 90`, `stats_row_remove 0001C9 Low_Completion`, `stats_row_remove 0001C9 Low_Both`, `stats_row_remove 0001C9 by-memory`, `uid_link_update 0001OL`, `reference_index_add 0001OL`, and generated coverage no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x005227d0-0x00524581.MetaMan.md --apply --queue-timeout 180`; exited `0`.
  - Filtered confirmation reruns for both changed pages reported `mode: file`, `scanned markdown files: 1`, `ok: 1`, `stats_incremental_noop` for the relevant UID, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage no-ops.
  - Follow-up checks confirmed [UID:0001C9] and [UID:0001C8] are absent from `project-level/-auto-completion-stats.md` and both remain assigned to parent `0000LC` in `auto-generated/-ag-memory-coverage.md`.
- Supervisor-owned `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:0001C8] `MetaMan` and nested [UID:0001C9] `MetaManLookupHelpers` replacement rows on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No Goal 2 MetaManLookupHelpers supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## Goal 2 Type-Quality UID 0001YQ A003 Report - 2026-06-13

- Assigned row:
  - [UID:0001YQ] `by-type/by-vtable/ScrollInventoryPaneVtables.md`
- Changed files:
  - `by-type/by-vtable/ScrollInventoryPaneVtables.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned vtable page and this notes file as Agent-A003 before editing.
  - Attempted to lease `by-type/by-vtable/-coverage-report.md`, but it was already leased by Agent-A001 for `ScrollCollectionPaneVtables`; no direct edit was made to the shared report. Exact pending replacement row is below.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` confirmed constructor `0x00563260-0x00563301` size `0xa1` / 161 bytes, mouse handler `0x00563460-0x00563641` size `0x1e1` / 481 bytes, false-return helper `0x00563650-0x00563655` size `0x5` / 5 bytes, timer handler `0x00563660-0x00563693` size `0x33` / 51 bytes, paint handler `0x005636a0-0x00563d80` size `0x6e0` / 1760 bytes, and neighboring `ScrollVolumePane` constructor `0x00564710`.
  - MCP `xrefs_to` confirmed single constructor-store xrefs to `0x0062402c`, `0x00624078`, and `0x006240a8`; `0x006240b4` is separately stored by the neighboring `ScrollVolumePane` constructor at `0x00564761`.
  - MCP `get_bytes` mapped the primary paint slot at `0x00624070`, secondary mouse/false-return slots at `0x0062407c` and `0x00624080`, tertiary timer slot at `0x006240ac`, and the handoff at `0x006240b0-0x006240b4`.
  - MCP `analyze_function 0x00563260` reconfirmed constructor writes the primary/secondary/tertiary vptrs at object offsets `+0x00`, `+0xa0`, and `+0xa4`; offsets and sizes were verified with `tools/int_convert.py`.
- Score/status/parent decisions:
  - [UID:0001YQ] `ScrollInventoryPaneVtables`: `74/86` -> `86/90`; `RECONSTRUCTABLE:TRUE` retained.
  - `AUTOGEN_PARENT_UID` remains [UID:0000CK][ScrollInventoryPane](../../../by-class/ScrollInventoryPane.md). The child clears `86/90`; the direct class parent already clears `85/86`; file parent [UID:0000KB][InventoryScrollPane](../../../by-file/InventoryScrollPane.md) clears `85/85`.
  - C++ remains blank because this is source-declared/generated-binary vtable layout evidence; the rebuilt class declaration should regenerate the table, and inherited pane-interface slot names plus standalone-vs-folded source placement remain below the final-source gate.
- Shared report row:
  - Supervisor applied and validated the [UID:0001YQ] `ScrollInventoryPaneVtables` row in `by-type/by-vtable/-coverage-report.md` on 2026-06-13.
  - Validation command: `python .\tools\validator.py --mode file --file by-type\by-vtable\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No `ScrollInventoryPaneVtables` shared report row remains pending.

## Goal 2 Class-Quality UID 0000DG A003 Report - 2026-06-13

- Assigned row:
  - [UID:0000DG] `by-class/SoundManager.md`
- Changed files:
  - `by-class/SoundManager.md`
  - Validator-owned/generated side effects expected after validation: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-class-coverage.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Used existing Agent-A003 leases on the assigned class page and this notes file before editing.
  - Did not edit `by-class/-coverage-report.md`; it was leased by Agent-C001 in the lease report, so the exact pending replacement row is recorded below for supervisor/shared-report application.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed SoundManager method anchors from `0x005797b0` through `0x0057bf40`, including constructor, destructor/vtable helpers, music selection, playback controls, local music scan, Redbook helpers, Miles driver callback setup, and SoundPathVector helpers.
  - MCP `xrefs_to 0x0062ce7c` confirmed the `SoundManager` vtable is written only by constructor/destructor/deleting-destructor paths at `0x00579a86`, `0x00579cdb`, and `0x0057bb62`.
  - MCP `analyze_function` confirmed DAT-backed playlist loading at `0x005797b0`, constructor singleton/vtable/Miles/DAT WAV setup at `0x00579a30`, zone music selection at `0x0057a0b0`, SoundManager timer event dispatch at `0x0057a800`, local music-directory scanning at `0x0057a890`, Miles file-open callback bridging at `0x0057b630`, and path-vector clear at `0x0057bf40`.
  - MCP `analyze_function 0x00525b10` confirmed WinMM MIDI cleanup belongs with MidiPlayer, not SoundManager.
  - MCP `analyze_function 0x00597610` confirmed generic TimerMgr wrapper behavior rather than SoundManager class ownership.
  - `tools/int_convert.py` verified key offsets and sizes: `0x1028` / 4136, `0x1098` / 4248, `0x109c` / 4252, `0x10a4` / 4260, `0x10a9` / 4265, `0x73e` / 1854, `0x2e` / 46, and `0x16` / 22.
- Score/status/parent decisions:
  - [UID:0000DG] `SoundManager`: `86/80` -> `86/86`; `RECONSTRUCTABLE:TRUE` retained.
  - Direct parent retained as [UID:0000NV][SoundManager](../../../by-file/SoundManager.md), which already clears `90/85`.
  - Related support docs checked: [UID:0000DI] `SoundPathVector` clears `85/86`; [UID:0001I8] `SoundManagerAudioHelperCluster` clears `85/88`; [UID:0000LD] `MidiPlayer` remains a separate file owner for MIDI/WinMM; [UID:0001K9] `TimerHandlerWrappers` remains a TimerMgr exclusion.
  - No reconstruction C++ was emitted because final field names, source-facing Miles/sample names, and exact helper folding remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-class\SoundManager.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `confidence_update 0000DG ... 86`, `stats_row_remove 0000DG ... Low_Confidence`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
  - Follow-up checks confirmed [UID:0000DG] is absent from `project-level/-auto-completion-stats.md` and remains assigned to parent `0000NV` in `auto-generated/-ag-class-coverage.md`.
- Shared-report update:
  - Supervisor applied and validated the [UID:0000DG] `by-class/-coverage-report.md` replacement row on 2026-06-13.
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None.

## Supervisor-Applied Rows - 2026-06-14 A003 by-resource score batch 3

- The supervisor applied and validated the [UID:000256] `by-memory/-coverage-report.md` replacement row on 2026-06-14.
- Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- No supervisor-owned `by-memory/-coverage-report.md` rows remain pending from this batch.

## Goal 2 Dialog/Pane Memory Batch A003 Report - 2026-06-14

- Assigned rows:
  - [UID:0001A2] `by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md`
  - [UID:0001AY] `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md`
  - [UID:0001B0] `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md`
- Supervisor-owned `by-memory/-coverage-report.md` replacements:
  - Supervisor applied and validated the Goal 2 Dialog/Pane Memory Batch replacement rows for [UID:0001A2], [UID:0001AY], and [UID:0001B0] on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No supervisor-owned `by-memory/-coverage-report.md` rows remain pending from this batch.

## Goal 2 ScrollPane By-Memory Batch A003 Report - 2026-06-14

- Assigned rows:
  - [UID:0001GH] `by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md`
  - [UID:0001GQ] `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`
  - [UID:0001GR] `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`
  - [UID:0001GS] `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
- Changed files:
  - `by-memory/0x0055c200-0x0055c643.ScrollPaneInputCore.md`
  - `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
  - `by-memory/0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`
  - `by-memory/0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`
  - `by-memory/0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`
  - `by-memory/-ignored.md`
  - `by-class/ScrollWidget.md`
  - `by-class/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
  - Validator-owned/generated side effects observed after validation: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, and `tools/validator.ini`.
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased all changed docs as Agent-A003 before editing.
  - Refreshed the active target/support leases before validation. `by-class/-coverage-report.md` was released and re-leased to keep an active report lease.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `b001_0003gy` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed ScrollPaneInputCore modeled starts at `0x0055c200`, `0x0055c310`, `0x0055c3a0`, `0x0055c3c0`, `0x0055c3e0`, `0x0055c400`, `0x0055c600`, and `0x0055c610`; raw starts `0x0055c2b0`, `0x0055c2e0`, and `0x0055c370` remain non-functions.
  - MCP `insn_query`/`get_bytes` corrected ScrollPaneInputCore raw setter tails: `0x0055c2b0-0x0055c2d7`, `0x0055c2e0-0x0055c304`, and `0x0055c370-0x0055c397`; internal padding in `by-memory/-ignored.md` now starts at `0x0055c2d7`, `0x0055c304`, and `0x0055c397`.
  - MCP `xref_query` confirmed ScrollWidget direct callsites from ScrollablePane synchronization (`0x0055e8be`, `0x0055e9d0`, `0x0055ea14`) and ChattingHandlePane enable/disable paths (`0x00481cda`, `0x00481e43`, `0x00481ce1`, `0x00481e4a`); raw setter starts still have no direct xrefs.
  - `tools/int_convert.py 0x7530` verified the ScrollWidget clamp constant as decimal `30000`.
  - MCP `lookup_funcs`, `xref_query`, `analyze_batch`, `insn_query`, and `get_bytes` reconfirmed ScrollNewGroupPane modeled helper boundaries, raw no-function helper starts, raw helper field effects at `+0x103/+0x104/+0x108/+0xa4`, part-rect/hit-test/update call graph, NewGroupPane scroll callback `0x0056df00`, exact padding, and `ScrollCollectionPane` successor boundary at `0x00561db0`.
- Score/status/parent decisions:
  - [UID:0001GH] `ScrollPaneInputCore`: `76/86` -> `86/88`; `CANONICAL_OWNER`/`EMITTER_UIDS` remain [UID:0000NF][ScrollBar](../../../by-file/ScrollBar.md) because this mixed aggregate spans `ScrollPane` and `ScrollWidget`.
  - [UID:0001GP] `ScrollNewGroupPaneCore`: `78/86`, owner/emitter [UID:0000JS][Group](../../../by-file/Group.md) -> `85/88`, owner/emitter [UID:0000CL][ScrollNewGroupPane](../../../by-class/ScrollNewGroupPane.md), emitter position `40`.
  - [UID:0001GQ] `ScrollNewGroupPaneHitTestPart`: `76/86`, owner/emitter [UID:0000JS][Group](../../../by-file/Group.md) -> `86/89`, owner/emitter [UID:0000CL][ScrollNewGroupPane](../../../by-class/ScrollNewGroupPane.md), emitter position `50`.
  - [UID:0001GR] `ScrollNewGroupPanePartRect`: `76/86`, owner/emitter [UID:0000JS][Group](../../../by-file/Group.md) -> `86/89`, owner/emitter [UID:0000CL][ScrollNewGroupPane](../../../by-class/ScrollNewGroupPane.md), emitter position `60`.
  - [UID:0001GS] `ScrollNewGroupPaneRawAndInteractionHelpers`: `76/86`, owner/emitter [UID:0000JS][Group](../../../by-file/Group.md) -> `87/89`, owner/emitter [UID:0000CL][ScrollNewGroupPane](../../../by-class/ScrollNewGroupPane.md), emitter position `70`.
  - [UID:0000CP] `ScrollWidget`: `82/84` -> `85/86`; parent route [UID:0000NF][ScrollBar](../../../by-file/ScrollBar.md) retained. Updated leased `by-class/-coverage-report.md` row to `85% : strong`.
  - C++ remains blank for all changed reconstruction pages because final source-facing field/helper names and class/source declarations remain below the active `90/90+` code-entry gate.
- Validation:
  - Ran one file-mode validation loop from `source-3/project-documentation` over all changed files:
    `by-memory\0x0055c200-0x0055c643.ScrollPaneInputCore.md`,
    `by-memory\0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`,
    `by-memory\0x00561420-0x0056173d.ScrollNewGroupPaneHitTestPart.md`,
    `by-memory\0x00561740-0x005619c7.ScrollNewGroupPanePartRect.md`,
    `by-memory\0x005619d0-0x00561db0.ScrollNewGroupPaneRawAndInteractionHelpers.md`,
    `by-memory\-ignored.md`,
    `by-class\ScrollWidget.md`, and
    `by-class\-coverage-report.md`.
  - Command shape: `python .\tools\validator.py --mode file --file <file> --apply --queue-timeout 180`.
  - Result: exit code `0`; the loop completed successfully. The first target reported `ok: 1`, `completion_update 0001GH ... 86`, `confidence_update 0001GH ... 88`, and stats-row removals. Follow-up checks confirmed `0001GH`, `0001GP`, `0001GQ`, `0001GR`, `0001GS`, and `0000CP` are absent from `project-level/-auto-completion-stats.md`.
  - Follow-up checks confirmed `auto-generated/-ag-memory-coverage.md` now routes `0001GP/0001GQ/0001GR/0001GS` through owner/emitter `0000CL` with positions `40/50/60/70`, while `0001GH` remains routed through `0000NF`.
- Supervisor-applied shared rows:
  - Supervisor applied and validated the `by-memory/-coverage-report.md` replacement rows for [UID:0001GH], [UID:0001GP], [UID:0001GQ], [UID:0001GR], and [UID:0001GS] on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory/-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No supervisor-owned by-memory rows remain pending from this batch.

## Goal 2 by-global low-score batch UID 0000T3/0000PH/0000PJ A003 Report - 2026-06-14

- Assigned rows:
  - [UID:0000T3] `by-global/InitializeOleSupport.md`
  - [UID:0000PH] `by-global/CloseMainMenuDialogSingletons_4F69A0.md`
  - [UID:0000PJ] `by-global/CreateScreenDimmer_4A12B0.md`
- Changed files:
  - `by-global/InitializeOleSupport.md`
  - `by-global/CloseMainMenuDialogSingletons_4F69A0.md`
  - `by-global/CreateScreenDimmer_4A12B0.md`
  - `by-global/-coverage-report.md`
  - Validator-owned/generated side effects from validation: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-global-coverage.md` (no content change reported), and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; no active leases were present initially.
  - Successfully leased the three assigned by-global docs, `by-global/-coverage-report.md`, and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `idb_list` reported the worker session active and analysis not running.
  - MCP `analyze_function 0x00419ee0` reconfirmed `sub_419EE0`, prototype `int()`, size `0x14` / 20 decimal bytes (Verified with int_convert.py), one basic block, data xref from `0x0060d6a4`, callees `OleInitialize` and `_atexit`, no ordinary callers, and the exact `OleInitialize(0); return atexit(sub_60C0F0);` body.
  - MCP `analyze_function 0x004f69a0` reconfirmed `sub_4F69A0`, size `0x91` / 145 decimal bytes (Verified with int_convert.py), 20 basic blocks, complexity `10`, direct callees `sub_49DAD0` and `sub_544690`, direct callers `sub_4F6910`, `sub_4F6A60`, and `sub_502850`, and the singleton read order from `g_pScreenDimmer` through EPF-gated old/new create-user slots.
  - MCP `analyze_function 0x004a12b0` reconfirmed `sub_4A12B0`, size `0xb0` / 176 decimal bytes (Verified with int_convert.py), 15 basic blocks, direct callees `sub_4F4AA0` and `sub_559B90`, 11 containing caller functions, 19 code xrefs/call sites, allocation size `0xfc` / 252 decimal bytes (Verified with int_convert.py), and parent selection through `dword_67A748 + 0x214`, `dword_67A7CC`, or `dword_67A764`.
  - Existing docs resolved `dword_67A7CC` to [UID:0000S7] `g_pScreenPane` and `dword_67A764` to [UID:0000PR] `g_activeMapPane`; the dimmer factory page now links those canonical globals instead of leaving the host-pane fallbacks raw.
- Score/status/parent decisions:
  - [UID:0000T3] `InitializeOleSupport`: `80/90` -> `84/91`; owner/emitter retained as [UID:0000HN] `AutoInit`. C++ remains blank because final standalone `AutoInit.cpp` vs `PlatformApi.cpp` fold and source-facing object spelling remain unresolved.
  - [UID:0000PH] `CloseMainMenuDialogSingletons_4F69A0`: `82/88` -> `86/90`; owner/emitter retained as [UID:0000L0] `MainMenuPane`.
  - [UID:0000PJ] `CreateScreenDimmer_4A12B0`: `82/88` -> `87/90`; owner/emitter retained as [UID:0000NA] `ScreenDimmer`.
  - All three now exceed the prior `85.0` average low-score threshold; no final C++ was added because final source declarations/spelling remain below final-source quality despite emitter routes.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-global\InitializeOleSupport.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0000T3 ... 84`, `confidence_update 0000T3 ... 91`, `stats_row_remove 0000T3`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-global\CloseMainMenuDialogSingletons_4F69A0.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0000PH ... 86`, `confidence_update 0000PH ... 90`, `reference_index_add` for `0000S5`, `0002X3`, and `0002X7`, `stats_row_remove 0000PH`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-global\CreateScreenDimmer_4A12B0.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0000PJ ... 87`, `confidence_update 0000PJ ... 90`, `reference_index_add` for `0000PR` and `0000S7`, `stats_row_remove 0000PJ`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-global\-coverage-report.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `stats_incremental_noop 0000PD`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Follow-up `rg` found [UID:0000T3], [UID:0000PH], and [UID:0000PJ] absent from `project-level/-auto-completion-stats.md`; `auto-generated/-ag-global-coverage.md` still lists all three as emitting through `0000HN`, `0000L0`, and `0000NA`.
- Shared-report updates:
  - Updated leased `by-global/-coverage-report.md` rows for [UID:0000T3], [UID:0000PH], and [UID:0000PJ].
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None.

## Goal 2 Type-Quality UID 0001TR A003 Report - 2026-06-13

- Assigned row:
  - [UID:0001TR] `by-type/by-struct/AttachedObjectRegistryLayout.md`
- Changed files:
  - `by-type/by-struct/AttachedObjectRegistryLayout.md`
  - `by-type/by-struct/-coverage-report.md`
  - Validator-owned/generated side effects expected after validation: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-type-coverage.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned struct layout page, `by-type/by-struct/-coverage-report.md`, and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed `AttachedObjectPane` destructor `0x00538100` size `0x1f8` / 504 bytes, detach helper `0x0053aec0` size `0x152` / 338 bytes, `0x0053b011` inside that helper, and `0x0053b012` as not a function.
  - MCP `analyze_function 0x00538100` reconfirmed the destructor call shape `sub_53AEC0(v12, this)` at `0x005382b0`, where `v12` is loaded from `this + 0x128`.
  - MCP `xrefs_to 0x0053aec0` reported exactly one code xref, the destructor call at `0x005382b0`; `analyze_function 0x0053aec0` reported no ordinary helper callees because list operations dispatch through list-object vtables.
  - MCP `analyze_function 0x0053aec0` reconfirmed the detached-object null check, signed type-byte gate at detached object offset `+0xf8`, type `2` list pointer at registry `+0x170`, type `4` list pointer at registry `+0x174`, vtable slot `+0x0c` list data fetches, and vtable slot `+0x1c` remove operations with remove flag `1`.
  - The helper analysis reconfirmed singleton offsets `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4` for detached-object types `6`, `7`, `8`, and `9`; type `8` clear remains gated by `byte_66DA97 == 1` / [UID:0000SW] `g_useEpfAssets`.
  - MCP `xrefs_to 0x0066da97` returned broad UI/rendering consumers beyond attached-object code, supporting the existing decision that the byte is the global EPF/legacy asset-mode selector rather than an attachment-specific flag.
  - `tools/int_convert.py` verified key sizes and offsets: `0x152` / 338, `0x1f8` / 504, `0x128` / 296, `0xf8` / 248, `0x170` / 368, `0x174` / 372, `0x1d8` / 472, `0x1dc` / 476, `0x1e0` / 480, and `0x1e4` / 484.
- Score/status/parent decisions:
  - [UID:0001TR] `AttachedObjectRegistryLayout`: `76/88` -> `86/89`; `RECONSTRUCTABLE:TRUE` retained.
  - Direct parent retained as [UID:0000HJ][AttachedObjectPane](../../../by-file/AttachedObjectPane.md), which clears `86/86`.
  - Support pages checked: [UID:0001DF] `AttachedObjectDetachRegistry` clears `85/89`; [UID:00000M] `AttachedObjectPane` clears `85/88`.
  - C++ remains blank because this is source-level layout/type evidence; final registry owner/setup routine and source-facing field/type names remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-type\by-struct\AttachedObjectRegistryLayout.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0001TR ... 86`, `confidence_update 0001TR ... 89`, `stats_row_remove 0001TR ... by-type`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-type\by-struct\-coverage-report.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `stats_incremental_noop 0001TK`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
- Shared-report updates:
  - Updated leased `by-type/by-struct/-coverage-report.md` row for [UID:0001TR] to `86% : strong`.
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None.

## Goal 2 Type-Quality UID 0001VI A003 Report - 2026-06-13

- Assigned row:
  - [UID:0001VI] `by-type/by-struct/ParcelNotificationPaneLayouts.md`
- Changed files:
  - `by-type/by-struct/ParcelNotificationPaneLayouts.md`
  - `by-class/ParcelIconPane.md`
  - `by-type/by-struct/-coverage-report.md`
  - Validator-owned/generated side effects expected after validation: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-type-coverage.md`, `auto-generated/-ag-class-coverage.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the assigned struct layout page, `by-type/by-struct/-coverage-report.md`, related support page `by-class/ParcelIconPane.md`, and this notes file as Agent-A003 before editing.
  - Did not edit `by-class/-coverage-report.md`; it was leased by Agent-A001 in the lease report, so the exact pending replacement row for [UID:0000A5] is recorded below for supervisor/shared-report application.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_0002UM` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - MCP `lookup_funcs` reconfirmed layout-bearing anchors and sizes: `0x00545e40` size `0x22a` / 554 bytes, `0x005461c0` size `0xcd` / 205 bytes, `0x00546290` size `0x1a6` / 422 bytes, `0x005464b0` size `0xc5` / 197 bytes, `0x00546810` size `0x78` / 120 bytes, `0x00546890` size `0xdf` / 223 bytes, `0x00546ac0` size `0xb4` / 180 bytes, `0x00546d70` size `0x7e` / 126 bytes, `0x00546df0` size `0x7b` / 123 bytes, and `0x00547000` size `0xad` / 173 bytes.
  - MCP `xrefs_to` reconfirmed lifecycle vtable-store xrefs for `ParcelIconPane` tables `0x00621bb4`, `0x00621c00`, and `0x00621c30`; `ParcelPane` table `0x00621c3c`; and `FlyingParcelPane` tertiary table `0x00621d48`.
  - MCP `analyze_function 0x00545e40` reconfirmed outer `ParcelIconPane` ownership, `g_pParcelIconPane` publication, `+0xf8..+0xfa` clears, 292-byte child `ParcelPane` allocation, child vtable initialization, child field/rectangle setup, timer setup, and child pointer storage at `+0xfc`.
  - MCP `analyze_function 0x005461c0` reconfirmed the `ParcelIconPane` secondary callback at vtable slot `0x00621c10`, packet byte `8` check, parcel-count nibble decoding, owner-normalized writes at `+0xf8..+0xfa`, child pointer access at owner `+0xfc`, and forwarding to `ParcelPane::SetParcelSlotData`.
  - MCP `analyze_function 0x00546290` and `0x005464b0` reconfirmed standalone `ParcelPane` slot bytes, button rectangles, timer view, and `SetParcelSlotData` field updates.
  - MCP `analyze_function 0x00546d70` and `0x00546df0` reconfirmed `FlyingParcelPane` tertiary callback normalization, payload bytes, helper pointer normalization, `g_pParcelPane` update, and `+0xfc` parcel-vs-letter draw-mode switch.
  - `tools/int_convert.py` verified key sizes and offsets, including `0x124` / 292, `0xf8` / 248, `0xfc` / 252, `0xa0` / 160, `0xa4` / 164, and `0x1e` / 30.
- Score/status/parent decisions:
  - [UID:0001VI] `ParcelNotificationPaneLayouts`: `78/84` -> `86/88`; `RECONSTRUCTABLE:TRUE` retained.
  - Direct parent retained as [UID:0000MF][ParcelPane](../../../by-file/ParcelPane.md), which already clears `86/85`.
  - Covered/support classes checked: [UID:0000A6] `ParcelPane` clears `86/86`; [UID:000058] `FlyingParcelPane` clears `85/86`; [UID:0000A5] `ParcelIconPane` was raised from `84/82` to `85/86` to clear the support gate.
  - Vtable companion [UID:0001YE] `ParcelNotificationVtableFamily` already clears `86/92` and remains attached to parent `0000MF`.
  - C++ remains blank because this is layout/type evidence; final source-facing field names and private-helper exposure remain below the `95/95` final-source gate.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-type\by-struct\ParcelNotificationPaneLayouts.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0001VI ... 86`, `confidence_update 0001VI ... 88`, `stats_row_remove 0001VI ... by-type`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-class\ParcelIconPane.md --apply --queue-timeout 180`; exited `0`.
  - Validator reported `ok: 1`, `completion_update 0000A5 ... 85`, `confidence_update 0000A5 ... 86`, `stats_incremental_noop 0000A5`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
  - Ran `python .\tools\validator.py --mode file --file by-type\by-struct\-coverage-report.md --apply --queue-timeout 180`; exited `0` with `ok: 1`, `stats_incremental_noop 0001TK`, `projected_stats_update`, `autogen_registry_rebuild`, and generated coverage report no-ops.
  - Follow-up checks confirmed [UID:0001VI] is absent from `project-level/-auto-completion-stats.md`, [UID:0001VI] remains assigned to parent `0000MF` in `auto-generated/-ag-type-coverage.md`, and [UID:0000A5] remains assigned to parent `0000MF` in `auto-generated/-ag-class-coverage.md`.
- Shared-report updates:
  - Updated leased `by-type/by-struct/-coverage-report.md` row for [UID:0001VI] to `86% : strong`.
  - Supervisor applied and validated the [UID:0000A5] `by-class/-coverage-report.md` replacement row on 2026-06-13. No shared class-report row remains pending for this item.
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None.

## Goal 2 by-resource score batch 0001RF/0001RG/0001RS/0001RR A003 Report - 2026-06-14

- Assignment: `A003-goal2-score-byresource-20260614-4`; targets [UID:0001RF] `main-menu-history-resources`, [UID:0001RG] `main-menu-story-resources`, [UID:0001RS] `user-status-resources`, and [UID:0001RR] `totem-frame-resources`.
- Changed files:
  - `by-resource/totem-frame-resources.md`
  - `by-resource/-coverage-report.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased all four target by-resource docs, `by-resource/-coverage-report.md`, and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor override.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` reconfirmed TotemFrame constructor `0x00598cc0` size `0xde` / 222 bytes, paint helper `0x00598dd0` size `0x6b` / 107 bytes, and `OldUserStatusPane::GetSpiritId` helper `0x005bdc60` size `0x8` / 8 bytes (Verified with `int_convert.py`).
  - `analyze_function 0x00598dd0` reconfirmed the one-block `TotemFrame::OnPaint` path: initialize a tile context, read `g_pOldUserStatusPane`, call `0x005bdc60`, load `L"TOTFRAME.EPD"`, and render from the pane rectangle at `this+0x44` / 68 bytes with `NPAL7.PAL` (Verified with `int_convert.py`).
  - `analyze_function 0x005bdc60` reconfirmed the frame selector returns `this[0x13e]` / byte offset 318 from `OldUserStatusPane` (Verified with `int_convert.py`) and is called by `TotemFrame::OnPaint`.
  - `xrefs_to` reconfirmed one `TOTFRAME.EPD` xref at `0x00598e05`, ten shared `NPAL7.PAL` refs including `0x00598e11`, and nine `g_pOldUserStatusPane` refs including the TotemFrame paint read at `0x00598dec`.
  - `get_bytes` with MCP `regions` decoded `0x0062e460` as UTF-16 `TOTFRAME.EPD` and `0x006152ec` as UTF-16 `NPAL7.PAL`.
- Score/status/owner decisions:
  - [UID:0001RF] `main-menu-history-resources`: target doc already `87/90`; coverage row corrected from `85%` to `87%`. `CANONICAL_OWNER:NONE` unchanged; by-resource pages have no emitter metadata.
  - [UID:0001RG] `main-menu-story-resources`: target doc already `87/90`; coverage row corrected from `85%` to `87%`. `CANONICAL_OWNER:NONE` unchanged; by-resource pages have no emitter metadata.
  - [UID:0001RS] `user-status-resources`: target doc already `88/90`; coverage row corrected from `86%` to `88%`. `CANONICAL_OWNER:NONE` unchanged; by-resource pages have no emitter metadata.
  - [UID:0001RR] `totem-frame-resources`: `85/91` -> `87/92`; coverage row corrected from `85%` to `87%`. `CANONICAL_OWNER:NONE` unchanged; by-resource pages have no emitter metadata.
- Validation:
  - Ran file-mode validation with `--apply --queue-timeout 180` for all four target docs and `by-resource/-coverage-report.md`; loop exited `0`.
  - The first validation reported `ok: 1`, `completion_update 0001RF ... 87`, `confidence_update 0001RF ... 90`, `stats_row_update 0001RF`, `projected_stats_update`, and `autogen_registry_rebuild`; the full loop completed successfully.
  - Follow-up checks confirmed `project-level/-auto-completion-stats.md` now lists [UID:0001RF] `87/90`, [UID:0001RG] `87/90`, and [UID:0001RS] `88/90`; [UID:0001RR] is absent from the checked low-score slice after the `87/92` refresh.
- Supervisor-owned `by-memory/-coverage-report.md` rows:
  - None.
- Next useful follow-up:
  - A focused asset/DAT pass should map `TOTFRAME.EPD` frame ids to `OldUserStatusPane::GetSpiritId` values and decide whether shared `NPAL7.PAL` deserves its own old-HUD palette resource page.

## Goal 2 DataSection child score batch 0002AD/0002AQ/0001Q4 A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-child-score-20260614-1`; targets [UID:0002AD] `BrowserThreadHostGlobals`, [UID:0002AQ] `TerminalAndTextEditGlobals`, and [UID:0001Q4] `SnowLookupDescriptorStorage`.
- Changed files:
  - `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`
  - `by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md`
  - `by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the three target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0002AD] live IDA reconfirmed eight zero bytes at `0x0067ab88-0x0067ab90`, 11 `g_pBrowserThread` xrefs, three `g_pCurrentBrowserHost` xrefs, `BrowserThreadInitializeBrowserHost` writing and clearing `0x0067ab8c`, and the host window procedure falling back to `0x0067ab8c` before `SetWindowLongA` installs the real owner pointer.
  - [UID:0002AQ] live IDA reconfirmed 16 zero bytes at `0x0069bdf8-0x0069be08`, nine TerminalPane singleton refs, six TextEdit clipboard-format refs, eight active TextEditPane refs, eight mouse-selection scratch refs, no xrefs to padding at `0x0069be06`, and successor ThreadMan/TimerMgr refs starting at `0x0069be08`.
  - [UID:0001Q4] live IDA corrected stale byte evidence to zero-filled virtual `.data`, reconfirmed descriptor bases `0x0069bf98` and `0x0069bff0`, guards `0x0069bfe8` and `0x0069c040`, no-xref padding at `0x0069bfec`, successor refs at `0x0069c044`, two-record `0x28` / 40-byte descriptor initialization, pattern pointer targets, frame counts `4` and `3`, and `4x4` / `3x3` source rectangles.
- Score/status/owner decisions:
  - [UID:0002AD] `BrowserThreadHostGlobals`: `80/85` -> `86/89`; `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HV` retained. Final C++ remains blank because final declaration spelling and linkage placement are not ready.
  - [UID:0002AQ] `TerminalAndTextEditGlobals`: `87/90` -> `88/91`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, and blank C++ retained because the full range is a mixed coverage index over TerminalPane, TextEditPane, and padding children.
  - [UID:0001Q4] `SnowLookupDescriptorStorage`: `80/88` -> `86/90`; `CANONICAL_OWNER:0000NR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NR` retained. Final C++ remains blank because local-static names and exact declaration shape are still provisional.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002AD ... 86`, `confidence_update 0002AD ... 89`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md --apply --queue-timeout 180`; result `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`. The initial validation applied the score refresh; the filtered confirmation pass found the page already current.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md --apply --queue-timeout 180`; result `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`. The initial validation applied the score refresh; the filtered confirmation pass found the page already current.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:0002AD], [UID:0002AQ], and [UID:0001Q4] replacement rows on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No A003 Goal 2 DataSection child score batch `0002AD/0002AQ/0001Q4` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
  - Applied row text:
  - Placement context: replace the [UID:0002AD] row currently between [UID:0001P9] `g_activeBrowserPane` and [UID:0002AE] `BrowserAndWebBoardDialogSingletons`.
    - `    - [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) 0x0067ab88-0x0067ab90 | global-data pair | BrowserThreadHostGlobals : reconstructable : 86% : strong : Browser thread singleton and current browser-host bridge with zero-initialized pointer storage, 11 g_pBrowserThread xrefs, three g_pCurrentBrowserHost setup-bridge xrefs, BrowserThread initialize write/clear evidence, host window procedure fallback read, Browser owner/emitter route, and final C++ blank until declaration/linkage spelling is final.`
  - Placement context: replace the [UID:0002AQ] row currently between [UID:0002ZW] `OldSystemMessagePaneResourcePointerTable` and [UID:0002AR] `ThreadTimerSingletonAndTickGlobals`.
    - `    - [UID:0002AQ][0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals](by-memory/0x0069bdf8-0x0069be08.TerminalAndTextEditGlobals.md) 0x0069bdf8-0x0069be08 | mixed global-data coverage index | TerminalAndTextEditGlobals : not_reconstructable : 88% : strong : Reviewed mixed coverage index over TerminalPane singleton, TextEdit clipboard format, active TextEditPane pointer, mouse-selection scratch word, and padding; live IDA confirms zero-filled bytes, per-slot xref counts, no-xref padding at 0x0069be06, successor ThreadMan/TimerMgr boundary at 0x0069be08, and no single owner/emitter for the full range.`
  - Placement context: replace the [UID:0001Q4] row currently between [UID:0001Q3] `g_pVirusChecker` and [UID:0002AJ] `MsvcRuntimeMutableDataTail`.
    - `    - [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) 0x0069bf98-0x0069c044 | static local descriptor storage | SnowLookupDescriptorStorage : reconstructable : 86% : strong : SnowingLayerPane local-static descriptor storage with current zero-filled virtual .data evidence, two 80-byte descriptor sets made of 40-byte records, _Init_thread_* guards at 0x0069bfe8 and 0x0069c040, no-xref alignment gap, successor boundary, WeatherLayerDataLayouts descriptor support, SnowingLayerPane owner/emitter route, and blank final C++ pending final local-static names/source declaration shape.`
- Next useful follow-up:
  - Apply and validate the three pending `by-memory/-coverage-report.md` rows. Later source-quality work should focus on final browser global declaration spelling, TextEdit private static names, and SnowingLayerPane local-static descriptor declaration shape before adding final C++.

## Goal 2 DataSection child score batch 000277/000278/000279/00027E A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-child-score-20260614-2`; targets [UID:000277] `AutoInitStaticObjectVptr`, [UID:000278] `BrowserUrlEscapeCharacterSets`, [UID:000279] `CommandLineAndConfigStringPointers`, and [UID:00027E] `g_fpsDebugActive`.
- Changed files:
  - `by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md`
  - `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`
  - `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`
  - `by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing, then renewed the same leases before validation/notes updates.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:000277] current IDA MCP reconfirmed bytes `3c 37 61 00`, the sole direct slot xref from `0x0060c0f0`, vtable xrefs from destructor/scalar-deleting destructor/shutdown/data slot, and the 16-byte shutdown thunk body (sizes verified with `int_convert.py`).
  - [UID:000278] current IDA MCP reconfirmed the exact 56-byte duplicate active/old URL-escape table contents, two xrefs per table start, modeled active/old WebBoard response handlers, and non-function raw helper ranges (size verified with `int_convert.py`).
  - [UID:000279] current IDA MCP reconfirmed the exact 20-byte five-pointer table, per-slot xref counts, `sub_4918E0` and `sub_4926A0` modeled parser/config boundaries, and the continuing no-direct-code-xref result for the `0x0066d470` / `grcframe.exe` slot (size verified with `int_convert.py`).
  - [UID:00027E] current IDA MCP reconfirmed the four-byte initialized value `01 00 00 00`, exact neighborhood bytes, exactly four raw rendered references to `dword_66DA90`, and backward data-flow nodes for the compare/clear paths (size verified with `int_convert.py`).
- Score/status/owner decisions:
  - [UID:000277] `AutoInitStaticObjectVptr`: `82/90` -> `86/92`; `CANONICAL_OWNER:0000HN`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HN` retained. Final C++ remains blank because final source declaration spelling for the static object is unresolved.
  - [UID:000278] `BrowserUrlEscapeCharacterSets`: `84/93` -> `86/93`; `CANONICAL_OWNER:0000P9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P9` retained. Final C++ remains blank because final static names and helper-local placement are unresolved.
  - [UID:000279] `CommandLineAndConfigStringPointers`: `84/88` -> `86/89`; `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000N4` retained. Final C++ remains blank because final static names and possible finer-grained declaration split are unresolved.
  - [UID:00027E] `g_fpsDebugActive`: `82/86` -> `86/88`; `CANONICAL_OWNER:0000JK`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JK` retained. Final C++ remains blank because exact declaration type/name and raw helper boundaries are unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 000277 ... 86`, `confidence_update 000277 ... 92`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 000278 ... 86`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 000279 ... 86`, `confidence_update 000279 ... 89`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0066da90-0x0066da94.g_fpsDebugActive.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 00027E ... 86`, `confidence_update 00027E ... 88`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:000277], [UID:000278], [UID:000279], and [UID:00027E] replacement rows on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No A003 Goal 2 DataSection child score batch `000277/000278/000279/00027E` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
  - Applied row text:
  - Placement context: replace the [UID:000277] row currently between [UID:000276] `BalloonObjectPaneStaticMasks` and [UID:000278] `BrowserUrlEscapeCharacterSets`.
    - `    - [UID:000277][0x0066d42c-0x0066d430.AutoInitStaticObjectVptr](by-memory/0x0066d42c-0x0066d430.AutoInitStaticObjectVptr.md) 0x0066d42c-0x0066d430 | static object field | AutoInitStaticObjectVptr : reconstructable : 86% : strong : Parent-attached AutoInit static object vptr slot; current IDA confirms exact four-byte data range, initial AutoInit vtable pointer 0x0061373c, sole direct slot xref from the 0x0060c0f0 shutdown thunk, complete vtable xref set, 16-byte shutdown thunk body, predecessor/successor data boundaries, and generated-binary source handling.`
  - Placement context: replace the [UID:000278] row currently between [UID:000277] `AutoInitStaticObjectVptr` and [UID:000279] `CommandLineAndConfigStringPointers`.
    - `    - [UID:000278][0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets](by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md) 0x0066d430-0x0066d468 | character-set data | BrowserUrlEscapeCharacterSets : reconstructable : 86% : strong : Parent-attached WebBoardDialog URL escape character-set table pairs; current IDA confirms exact 56-byte duplicated active/old tables, two xrefs per table start from active/old response handlers and raw URL-escape helper sites, guard/table state behavior, WebBoardDialog owner/emitter route, and adjacent data boundaries.`
  - Placement context: replace the [UID:000279] row currently between [UID:000278] `BrowserUrlEscapeCharacterSets` and [UID:00027A] `ChecksumLookupTablesData`.
    - `    - [UID:000279][0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers](by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md) 0x0066d468-0x0066d47c | pointer table | CommandLineAndConfigStringPointers : reconstructable : 86% : strong : Five writable startup/config string pointers attached to RegistryConfig; current IDA confirms the exact 20-byte table, Unitel and HITEL2000 wide-message targets, parser/load xrefs, modeled parser/config function boundaries, split boundaries, and the grcframe.exe slot still lacking a direct code xref.`
  - Placement context: replace the [UID:00027E] row currently between [UID:00027D] `FolderSelectDriveRootBuffer` and [UID:0001OG] `g_screenWidth`.
    - `    - [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) 0x0066da90-0x0066da94 | initialized global flag | g_fpsDebugActive : reconstructable : 86% : strong : FpsPane diagnostics startup/restart flag with current IDA-confirmed four-byte value 1, exact adjacent FolderSelect/screen-width boundaries, four raw FpsPane compare/clear refs, backward data-flow confirmation, FpsPane source-file parent attachment, stale generated ParcelPane owner caveat, and blank final C++ while declaration type/raw helper boundaries remain open.`
- Next useful follow-up:
  - Supervisor should apply and validate the four pending `by-memory/-coverage-report.md` rows. Later source-quality work should focus on final static object spelling for AutoInit, WebBoard URL helper names/static placement, RegistryConfig string-pointer split/name decisions, and FpsPane `g_fpsDebugActive` declaration type before adding final C++.

## Goal 2 DataSection child score batch 00027V/0001ON/0001OO/0001OP A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-child-score-20260614-3`; targets [UID:00027V] `MusicControlDriveRootBuffers`, [UID:0001ON] `RainCoordinateTables`, [UID:0001OO] `SnowPatternByteTables`, and [UID:0001OP] `g_pCashShopRequest`.
- Changed files:
  - `by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md`
  - `by-memory/0x006702c8-0x00670784.RainCoordinateTables.md`
  - `by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md`
  - `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; no active leases were present.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:00027V] current IDA MCP reconfirmed the 16-byte initialized drive-buffer/tail bytes, four ANSI root-buffer refs, four UTF-16 label-buffer refs, no refs to `0x0066dec8`, and the `sub_52A010` CD-ROM enumeration/control id `8` insertion loop (size verified with `int_convert.py`).
  - [UID:0001ON] current IDA MCP reconfirmed rain table start/boundary bytes, all table-start xrefs, no xref at the snow boundary byte `0x00670784`, and the target/main-view rain draw formulas in `sub_5C1810` and `sub_5C1460` (span size verified with `int_convert.py`).
  - [UID:0001OO] current IDA MCP reconfirmed the 76-byte snow-pattern span, sentinel/no-xref behavior, all threshold/size-offset/pattern xrefs, descriptor initialization in `sub_5C1C80` and `sub_5C20E0`, and the no-xref padding boundary at `0x006707d0` (span size verified with `int_convert.py`).
  - [UID:0001OP] current IDA MCP reconfirmed zero-initialized storage, exactly nine xrefs, FileDownloader constructor/destructor/application-cleanup behavior, and the categorized FileDownloader write plus fitting-room/item-shop read roles (slot size verified with `int_convert.py`).
- Score/status/owner decisions:
  - [UID:00027V] `MusicControlDriveRootBuffers`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000LN`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000LN` retained. Final C++ remains blank because final storage form and the `0x0066dec8-0x0066decc` tail role remain unresolved.
  - [UID:0001ON] `RainCoordinateTables`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000MY`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MY` retained. Final C++ remains blank because final table names and source declarations remain provisional.
  - [UID:0001OO] `SnowPatternByteTables`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000NR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NR` retained. Final C++ remains blank because final byte-table names and declaration grouping remain provisional.
  - [UID:0001OP] `g_pCashShopRequest`: `82/86` -> `86/89`; `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000JC` retained. Final C++ remains blank because final downloader/request-dispatcher type/name remains unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 00027V ... 86`, `confidence_update 00027V ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x006702c8-0x00670784.RainCoordinateTables.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001ON ... 86`, `confidence_update 0001ON ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00670784-0x006707d0.SnowPatternByteTables.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001OO ... 86`, `confidence_update 0001OO ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a738-0x0067a73c.g_pCashShopRequest.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001OP ... 86`, `confidence_update 0001OP ... 89`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:00027V], [UID:0001ON], [UID:0001OO], and [UID:0001OP] replacement rows on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No A003 Goal 2 DataSection child score batch `00027V/0001ON/0001OO/0001OP` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
  - Applied row text:
  - Placement context: replace the [UID:00027V] row currently between [UID:00027U] `MonsterImageLibDefaultFrameRecord` and [UID:00027W] `LivingObjectPaneWordSlots_66DECC`.
    - `    - [UID:00027V][0x0066debc-0x0066decc.MusicControlDriveRootBuffers](by-memory/0x0066debc-0x0066decc.MusicControlDriveRootBuffers.md) 0x0066debc-0x0066decc | mutable drive-root buffers | MusicControlDriveRootBuffers : reconstructable : 86% : strong : MusicControlDialog drive-root buffers with current IDA-confirmed 16-byte initialized range, four ANSI root-buffer refs, four UTF-16 label-buffer refs, no refs to the trailing initialized dword at 0x0066dec8, GetDriveTypeA CD-ROM filtering, control id 8 insertion behavior, MusicControlDialog owner/emitter route, and clean neighboring data boundaries.`
  - Placement context: replace the [UID:0001ON] row currently between [UID:00028B] `UniAPIInitVtablePointerSlot` and [UID:0001OO] `SnowPatternByteTables`.
    - `    - [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) 0x006702c8-0x00670784 | static weather data | RainCoordinateTables : reconstructable : 86% : strong : RainingLayerPane three-frame rain streak/splash coordinate tables with current IDA-confirmed table-start xrefs, target/minimap and main-view draw formulas, start and rain-to-snow boundary bytes, no xref at 0x00670784, exact 1212-byte span, RainingLayerPane owner/emitter route, and blank final C++ while original table names remain inferred.`
  - Placement context: replace the [UID:0001OO] row currently between [UID:0001ON] `RainCoordinateTables` and [UID:00028C] `SnowToLibJpegDataPadding`.
    - `    - [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md) 0x00670784-0x006707d0 | static weather data | SnowPatternByteTables : reconstructable : 86% : strong : SnowingLayerPane threshold sentinels, size offsets, and descriptor pattern bytes with current IDA-confirmed 76-byte span, sentinel/no-xref behavior, all threshold/size-offset/pattern xrefs, descriptor initialization paths, no-xref padding boundary at 0x006707d0, SnowingLayerPane owner/emitter route, and blank final C++ while byte-table names remain inferred.`
  - Placement context: replace the [UID:0001OP] row currently between [UID:00028H] `CrtStdioOptionsStorage` and [UID:00028I] `g_pFittingRoomDialog`.
    - `    - [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md) 0x0067a738-0x0067a73c | global pointer | g_pCashShopRequest : reconstructable : 86% : strong : FileDownloader/download-request dispatcher singleton pointer attached to FileDownloader, with current IDA-confirmed zero storage, exactly nine xrefs, FileDownloader constructor/destructor/application-cleanup lifetime behavior, fitting-room/item-shop consumer reads, alias-pollution caveat, neighboring pointer boundaries, and blank final C++ pending final downloader/request-dispatcher type/name.`
- Next useful follow-up:
  - Later source-quality work should focus on final MusicControl buffer storage form, weather table source names/declaration grouping, and the FileDownloader versus CashShopRequest request-dispatcher type boundary before adding final C++.

## Goal 2 DataSection singleton score batch 0001OW/0001OY/0001OZ/0001P0 A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-singleton-score-20260614-4`; targets [UID:0001OW] `ActiveMapPaneSingleton`, [UID:0001OY] `g_pSimpleHelpPane2`, [UID:0001OZ] `g_pMiniMapVersionManager`, and [UID:0001P0] `g_packetSender`.
- Changed files:
  - `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`
  - `by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md`
  - `by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md`
  - `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; only unrelated C001 leases were active.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - A renewal attempt while leases were still active was rejected as `Already has lease`; validation completed successfully. Before this notes update, the lease had expired, so A003 leased only this notes file for the report.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0001OW] current IDA MCP reconfirmed zeroed `0x0067a75c-0x0067a77c` bytes, four-byte slot size, 360 direct xrefs, MapPane constructor publish/guard clear, MapPane teardown/helper clears, and representative map/minimap/application/weather consumers.
  - [UID:0001OY] current IDA MCP reconfirmed zeroed surrounding bytes, the exact 9-reference set, SimpleHelpPane2 constructor/factory publish/fallback behavior, destructor/support/deleting-destructor clears, and UI dismissal read.
  - [UID:0001OZ] current IDA MCP reconfirmed zeroed surrounding bytes, 12 direct xrefs, renderer/application/startup/update-check consumers, constructor publish/guard clear, and teardown/helper/deleting-destructor clears.
  - [UID:0001P0] current IDA MCP reconfirmed zeroed `0x0067a7e0-0x0067a800` bytes, 489 direct xrefs, all five Socket-family lifecycle writes, Socket lifecycle/send-helper function boundaries, and adjacent `g_pRankingRewardInfoDialog` / `MmxBlendWeightScratchData` boundaries.
- Score/status/owner decisions:
  - [UID:0001OW] `ActiveMapPaneSingleton`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000PR`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000PR` retained. Final C++ remains blank because final source spelling and some MapPane field names remain provisional.
  - [UID:0001OY] `g_pSimpleHelpPane2`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000SA`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000SA` retained. Final C++ remains blank because private helper visibility and field names remain provisional.
  - [UID:0001OZ] `g_pMiniMapVersionManager`: `84/90` -> `86/91`; `CANONICAL_OWNER:0000RP`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000RP` retained. Final C++ remains blank because internal list/vector field names remain provisional.
  - [UID:0001P0] `g_packetSender`: `84/86` -> `86/89`; `CANONICAL_OWNER:0000NS`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000NS` retained. Final C++ remains blank because final sender/request type and Socket-vs-request-helper boundary remain unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a764-0x0067a768.ActiveMapPaneSingleton.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001OW ... 86`, `confidence_update 0001OW ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001OY ... 86`, `confidence_update 0001OY ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001OZ ... 86`, `confidence_update 0001OZ ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a7ec-0x0067a7f0.g_packetSender.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001P0 ... 86`, `confidence_update 0001P0 ... 89`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:0001OW], [UID:0001OY], [UID:0001OZ], and [UID:0001P0] replacement rows on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No A003 Goal 2 DataSection singleton score batch `0001OW/0001OY/0001OZ/0001P0` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
  - Applied row text:
  - Placement context: replace the [UID:0001OW] row currently between [UID:0001OV] `g_pNewHumanImageLib` and [UID:00028M] `CrtStdioScanOptionsStorage`.
    - `    - [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) 0x0067a764-0x0067a768 | global pointer | ActiveMapPaneSingleton : reconstructable : 86% : strong : Active MapPane singleton pointer with current IDA-confirmed zero storage, 360 xrefs, constructor publish/guard clear, destructor/helper clears, alias cleanup, representative map/minimap/application/weather consumers, parent global/emitter route, and blank final C++ while source spelling and some MapPane field names remain provisional.`
  - Placement context: replace the [UID:0001OY] row currently between [UID:00028R] `g_pSoundManager` and [UID:00028S] `g_pMiniMapDownloader`.
    - `    - [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md) 0x0067a7d4-0x0067a7d8 | global pointer | g_pSimpleHelpPane2 : reconstructable : 86% : strong : SimpleHelpPane2 tooltip singleton with current IDA-confirmed zero storage, exact 9-reference set, UI dismissal read, constructor/factory publish and guard clears, destructor/support/deleting-destructor clears, parent global/emitter route, and blank final C++ while helper visibility and private field names remain provisional.`
  - Placement context: replace the [UID:0001OZ] row currently between [UID:00028S] `g_pMiniMapDownloader` and [UID:00028T] `g_pPaletteLib`.
    - `    - [UID:0001OZ][0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager](by-memory/0x0067a7dc-0x0067a7e0.g_pMiniMapVersionManager.md) 0x0067a7dc-0x0067a7e0 | global pointer | g_pMiniMapVersionManager : reconstructable : 86% : strong : MiniMapVersionManager singleton pointer with current IDA-confirmed zero storage, 12 direct xrefs, constructor publish/guard clear, destructor/helper/deleting-destructor clears, renderer/application/startup/update-check consumers, parent global/emitter route, and blank final C++ while internal list/vector field names remain provisional.`
  - Placement context: replace the [UID:0001P0] row currently between [UID:00028V] `g_pRankingRewardInfoDialog` and [UID:00028W] `MmxBlendWeightScratchData`.
    - `    - [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) 0x0067a7ec-0x0067a7f0 | global pointer | g_packetSender : reconstructable : 86% : strong : Socket-owned outbound packet sender pointer with current IDA-confirmed zero storage, 489 xrefs, all five Socket-family lifecycle writes, broad feature/UI reads, QueueAndSendPacket dependency, adjacent pointer/render-data boundaries, Socket owner/emitter route, and blank final C++ while final sender/request type remains unresolved.`
- Next useful follow-up:
  - Later source-quality work should focus on source names/types for the singleton declarations and on the packet sender interface boundary before adding final C++.

## Goal 2 DataSection singleton/static score batch 00028Z/000292/0001P3/0001P4 A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-singleton-score-20260614-5`; targets [UID:00028Z] `ApplicationLifecycleFlags`, [UID:000292] `ApplicationErrorAndCriticalSectionStatics`, [UID:0001P3] `g_activeBrowserControlPane`, and [UID:0001P4] `g_pChangeMan`.
- Changed files:
  - `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`
  - `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`
  - `by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md`
  - `by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:00028Z] current IDA MCP confirmed exact 8-byte zero-initialized `.data` storage, five phase-state xrefs, eighteen active-gate xrefs, and decompiled `Application::Initialize` phase/gate assignment behavior.
  - [UID:000292] current IDA MCP confirmed exact 40-byte zero-initialized `.data` storage, field-level xref counts, startup/cleanup/error-text replacement behavior, window-procedure `Error #%03d` replacement path, and critical-section enter/leave users.
  - [UID:0001P3] current IDA MCP confirmed zeroed surrounding pointer storage, 24 xrefs, constructor publish/null-adjustment behavior, destructor/deleting-destructor clears, writer function bounds, and active-surface/app/browser consumer set.
  - [UID:0001P4] current IDA MCP confirmed zeroed surrounding pointer storage, 11 xrefs, constructor publish/null-adjustment behavior, singleton clear helper, destructor clear, Application wrapper forwarding behavior, and ChangeMan owner route.
- Score/status/owner decisions:
  - [UID:00028Z] `ApplicationLifecycleFlags`: `82/88` -> `86/90`; `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HG` retained. Final C++ remains blank because final phase enum/value names and declarations remain provisional.
  - [UID:000292] `ApplicationErrorAndCriticalSectionStatics`: `82/88` -> `86/91`; `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HG` retained. Final C++ remains blank because final static variable names and wrapper type shape remain unresolved.
  - [UID:0001P3] `g_activeBrowserControlPane`: `84/86` -> `86/89`; `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HV` retained. Final C++ remains blank because exported declaration/accessor shape remains unresolved.
  - [UID:0001P4] `g_pChangeMan`: `84/88` -> `86/90`; `CANONICAL_OWNER:0000I2`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000I2` retained. Final C++ remains blank because linkage spelling and source/header declaration shape remain unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a938-0x0067a940.ApplicationLifecycleFlags.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 00028Z ... 86`, `confidence_update 00028Z ... 90`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 000292 ... 86`, `confidence_update 000292 ... 91`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001P3 ... 86`, `confidence_update 0001P3 ... 89`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067ab2c-0x0067ab30.g_pChangeMan.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0001P4 ... 86`, `confidence_update 0001P4 ... 90`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the [UID:00028Z], [UID:000292], [UID:0001P3], and [UID:0001P4] replacement rows on 2026-06-14.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - No A003 Goal 2 DataSection singleton/static score batch `00028Z/000292/0001P3/0001P4` supervisor-owned `by-memory/-coverage-report.md` rows remain pending.
  - Applied row text:
  - Placement context: replace the [UID:00028Z] row currently between [UID:0000VN] `AesLookupTablesAndPadding` and [UID:000290] `PasswordGuardProtectedToken`.
    - `    - [UID:00028Z][0x0067a938-0x0067a940.ApplicationLifecycleFlags](by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md) 0x0067a938-0x0067a940 | application flags | ApplicationLifecycleFlags : reconstructable : 86% : strong : Application phase/state and active-gate globals with current IDA-confirmed eight-byte zero-initialized storage, five phase-state xrefs, phase writer values 1/2/3/4, diagnostics read, eighteen active-gate xrefs across initialization/window/input/activation/UI/server fanout, Application owner/emitter route, and blank final C++ while enum-like value names remain provisional.`
  - Placement context: replace the [UID:000292] row currently between [UID:000291] `ApplicationTimingBaselines` and [UID:000293] `ApplicationOsVersionState`.
    - `    - [UID:000292][0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics](by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md) 0x0067a998-0x0067a9c0 | application static data | ApplicationErrorAndCriticalSectionStatics : reconstructable : 86% : strong : Application error-state object and static critical-section storage with current IDA-confirmed 40-byte zero-initialized layout, startup initializer, cleanup thunks, field-level xref counts, helper/window-procedure error-text replacement allocation/copy behavior, Application cleanup display path, message-loop/request-exit critical-section use, Application owner/emitter route, and blank final C++ while variable names and wrapper type shape remain unresolved.`
  - Placement context: replace the [UID:0001P3] row currently between [UID:0001P2] `g_pFontImageLib` and [UID:0001P4] `g_pChangeMan`.
    - `    - [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) 0x0067ab28-0x0067ab2c | global pointer | g_activeBrowserControlPane : reconstructable : 86% : strong : Active BrowserControlPane pointer attached to Browser, with current IDA-confirmed four-byte zero-initialized storage, 24 xrefs, constructor publish/guard clear, destructor/helper/deleting-destructor clears, app/browser consumers, presentation active-surface/redraw consumers, Browser owner/emitter route, and blank final C++ while exported declaration/accessor shape remains unresolved.`
  - Placement context: replace the [UID:0001P4] row currently between [UID:0001P3] `g_activeBrowserControlPane` and [UID:000296] `g_pEventDispatcher`.
    - `    - [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md) 0x0067ab2c-0x0067ab30 | global pointer | g_pChangeMan : reconstructable : 86% : strong : ChangeMan singleton pointer attached to ChangeMan, with current IDA-confirmed four-byte zero-initialized storage, 11 xrefs, constructor publish/guard clear/cleanup clear, singleton clear helper, scalar deleting destructor clear, Application register/unregister/dispatch wrapper reads, BackPane unregister reads, cleanup teardown read, ChangeMan owner/emitter route, and blank final C++ while linkage/header declaration shape remains unresolved.`
- Next useful follow-up:
  - Later source-quality work should focus on naming the Application phase/gate enum values, deciding whether the error critical section used a wrapper type, and resolving header/export declaration shape for the BrowserControlPane and ChangeMan singleton pointers before adding final C++.

## Goal 2 DataSection global/static score batch 0002AG/0002B7/0001PE/0001PT A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-global-score-20260614-6`; targets [UID:0002AG] `WebBoardDialogUrlEscapeState`, [UID:0002B7] `WideCharStrGlobalBuffer`, [UID:0001PE] `g_activeUserStatusPane`, and [UID:0001PT] `g_pStaffsDialog`.
- Changed files:
  - `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`
  - `by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md`
  - `by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md`
  - `by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and validator state refresh.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; only unrelated A001 leases were active.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0002AG] current IDA MCP confirmed exact 264-byte zero-initialized `.data` storage, four guard xrefs, 24 table xrefs, raw helper guard-table disassembly start, and full `sub_46D580` table initialization / `%XX` escape behavior.
  - [UID:0002B7] current IDA MCP confirmed sampled zero-initialized start/tail bytes for the 131,072-byte buffer, only three real base code xrefs in `sub_4877D0`, decompiled `0x10000` wide-character capacity and terminator flow, and the `sub_484F70` clan packet subtype caller.
  - [UID:0001PE] current IDA MCP confirmed zero-initialized pointer storage, stable 67 xrefs, UserStatusPane lifecycle function bounds, constructor publish/null-adjustment behavior, cleanup/helper/destructor clears, and representative inventory-slot consumer decompilation.
  - [UID:0001PT] current IDA MCP confirmed zero-initialized pointer storage, stable four-xref lifecycle set, StaffsDialogPane constructor/helper/destructor function bounds, constructor publish/null-adjustment behavior, and destructor clear behavior.
- Score/status/owner decisions:
  - [UID:0002AG] `WebBoardDialogUrlEscapeState`: `84/88` -> `86/90`; `CANONICAL_OWNER:0000P9`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P9` retained. Final C++ remains blank because final static names/linkage remain unresolved.
  - [UID:0002B7] `WideCharStrGlobalBuffer`: `84/86` -> `86/88`; `CANONICAL_OWNER:0000I8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000I8` retained. Final C++ remains blank because final symbol name and linkage remain unresolved.
  - [UID:0001PE] `g_activeUserStatusPane`: `84/86` -> `86/89`; `CANONICAL_OWNER:0000P2`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000P2` retained. Final C++ remains blank because final linkage and field naming remain unresolved.
  - [UID:0001PT] `g_pStaffsDialog`: `84/88` -> `86/90`; `CANONICAL_OWNER:0000SC`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000SC` retained. Final C++ remains blank because declaration linkage/placement remain unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md --apply --queue-timeout 180`; first pass result `ok: 1`, `completion_update 0002AG ... 86`, `confidence_update 0002AG ... 90`; final pass after wording cleanup also returned `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md --apply --queue-timeout 180`; first pass result `ok: 1`, `completion_update 0002B7 ... 86`, `confidence_update 0002B7 ... 88`; final pass after wording cleanup also returned `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md --apply --queue-timeout 180`; first pass result `ok: 1`, `completion_update 0001PE ... 86`, `confidence_update 0001PE ... 89`; final pass after wording cleanup also returned `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b490-0x0069b494.g_pStaffsDialog.md --apply --queue-timeout 180`; first pass result `ok: 1`, `completion_update 0001PT ... 86`, `confidence_update 0001PT ... 90`; final pass also returned `ok: 1`, `stats_incremental_noop`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the four rows on 2026-06-14 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`.
  - Placement context: replaced the [UID:0002AG] row currently between [UID:0002AF] `g_pMainUiGraph` and [UID:0002AH] `WebBoardDialogOldUrlEscapeState`.
    - `    - [UID:0002AG][0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState](by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md) 0x0067aba8-0x0067acb0 | global-data table | WebBoardDialogUrlEscapeState : reconstructable : 86% : strong : Active WebBoardDialog URL escape guard/table storage with current IDA-confirmed 264-byte zero-initialized range, four guard xrefs, 24 table xrefs, response-handler table initialization and percent-escape behavior, raw helper guard-table evidence, corrected character-set dependency, WebBoardDialog owner/emitter route, and blank final C++ while static names/linkage remain unresolved.`
  - Placement context: replaced the [UID:0002B7] row currently between [UID:0002B6] `UnreferencedInitializedDword_67ADEC` and [UID:0002B8] `g_pCollectionDialogPane`.
    - `    - [UID:0002B7][0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer](by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md) 0x0067adf0-0x0069adf0 | global-data buffer | WideCharStrGlobalBuffer : reconstructable : 86% : strong : 65536-wide-character Clan scratch buffer with current IDA-confirmed 131072-byte range, sampled zero-initialized start/tail bytes, only real base code xrefs in `sub_4877D0`, decompiled 0x10000-capacity conversion/termination/dispatch flow, clan packet subtype caller, false-positive interior data-xref triage, Clan owner/emitter route, and blank final C++ while symbol/linkage remain unresolved.`
  - Placement context: replaced the [UID:0001PE] row currently between [UID:00029D] `g_pScreenDimmer` and [UID:0002AT] `g_frameRegistry`.
    - `    - [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md) 0x0069ae0c-0x0069ae10 | global pointer | g_activeUserStatusPane : reconstructable : 86% : strong : Active UserStatusPane singleton pointer with current IDA-confirmed four-byte zero-initialized storage, neighboring boundaries, stable 67 xrefs, constructor publish/null-adjustment behavior, cleanup/helper/destructor clears, representative item/status consumer decompilation, alias caveats, UserStatusPane owner/emitter route, and blank final C++ while linkage and field naming remain unresolved.`
  - Placement context: replaced the [UID:0001PT] row currently between [UID:0002XM] `g_pChangePasswordDialogPane` and [UID:0001PU] `g_pHistoryViewingPane`.
    - `    - [UID:0001PT][0x0069b490-0x0069b494.g_pStaffsDialog](by-memory/0x0069b490-0x0069b494.g_pStaffsDialog.md) 0x0069b490-0x0069b494 | global pointer | g_pStaffsDialog : reconstructable : 86% : strong : StaffsDialogPane singleton pointer with current IDA-confirmed four-byte zero-initialized storage, exact four lifecycle xrefs, constructor publish/null-adjustment behavior, clear-helper and scalar deleting destructor clears, STAFF/STAFFS resource-owner context, StaffsDialog global owner/emitter route, and blank final C++ while declaration linkage/placement remain unresolved.`
- Next useful follow-up:
  - Later source-quality work should resolve WebBoard static variable names/linkage, the Clan scratch-buffer symbol/linkage, UserStatusPane high-fanout field names, and StaffsDialog singleton declaration placement before adding final C++.

## Goal 2 DataSection cluster score batch 00029Y/0002W7/0002W8/0002W9 A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-cluster-score-20260614-7`; targets [UID:00029Y] `MessageStatusAndMenuPaneGlobals`, [UID:0002W7] `g_pOldSystemMessagePane`, [UID:0002W8] `InputBlockerPaneSingleton`, and [UID:0002W9] `g_pParcelIconPane`.
- Changed files:
  - `by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md`
  - `by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md`
  - `by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md`
  - `by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md`
  - Validator-owned generated/state side effects from validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; active leases were unrelated to these target docs.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - After validation, `current_leases.md` showed no active Agent-A003 leases; explicit `unlease` for the five paths returned `Rejected[No active lease]` for each path.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, and Hex-Rays ready.
  - [UID:00029Y] current IDA MCP confirmed exact 40-byte zero-initialized `.data` storage, stable xref counts for all ten one-dword pane singleton slots, decompiled first-three lifecycle paths, and broad UI teardown fanout.
  - [UID:0002W7] current IDA MCP confirmed four-byte zero-initialized storage, seven xrefs, constructor publish/null-adjustment, cleanup/helper/scalar-deleting-destructor clears, UI teardown read, and old-mode EmotionInputPane consumer.
  - [UID:0002W8] current IDA MCP confirmed four-byte zero-initialized storage, sixteen xrefs, `0xf8` / 248-byte input-blocker allocation, vtable installation, packet/UI create/destroy behavior, clear helper, and scalar deleting destructor clear.
  - [UID:0002W9] current IDA MCP confirmed four-byte zero-initialized storage, six xrefs, constructor publish/null-adjustment, embedded ParcelPane creation context, non-deleting/helper/scalar-deleting-destructor clears, and UI teardown read.
- Score/status/owner decisions:
  - [UID:00029Y] `MessageStatusAndMenuPaneGlobals`: `87/93` -> `88/94`; `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and empty `EMITTER_UIDS` retained because the aggregate is a mixed non-emitting split index over unrelated pane owners.
  - [UID:0002W7] `g_pOldSystemMessagePane`: `86/91` -> `87/92`; [UID:0003ED][g_pOldSystemMessagePane](../../../by-global/g_pOldSystemMessagePane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002W8] `InputBlockerPaneSingleton`: `86/90` -> `87/91`; [UID:0003EE][g_pInputBlockerPane](../../../by-global/g_pInputBlockerPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002W9] `g_pParcelIconPane`: `87/92` -> `88/93`; [UID:0000RX][g_pParcelIconPane](../../../by-global/g_pParcelIconPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 00029Y ... 88`, `confidence_update 00029Y ... 94`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002W7 ... 87`, `confidence_update 0002W7 ... 92`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002W8 ... 87`, `confidence_update 0002W8 ... 91`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002W9 ... 88`, `confidence_update 0002W9 ... 93`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied and validated the four rows on 2026-06-14 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result: `ok: 1`. Child rows were applied under [UID:00029Y] using the existing coverage-report nesting.
  - Placement context: replaced the [UID:00029Y] row currently between [UID:0002AL] `FriendChatViewStatics` and [UID:0002W7] `g_pOldSystemMessagePane`.
    - `    - [UID:00029Y][0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals](by-memory/0x0069b4c8-0x0069b4f0.MessageStatusAndMenuPaneGlobals.md) 0x0069b4c8-0x0069b4f0 | mixed global-data cluster | MessageStatusAndMenuPaneGlobals : not_reconstructable : 88% : very strong : Reviewed non-emitting mixed singleton cluster over ten one-dword pane globals with current IDA-confirmed 40-byte zero-initialized range, stable per-slot xref counts, decompiled first-three lifecycle paths, broad UI teardown fanout, exact child split routing, and explicit no owner/emitter because the aggregate crosses unrelated pane owners.`
  - Placement context: replaced the [UID:0002W7] row currently immediately after [UID:00029Y] `MessageStatusAndMenuPaneGlobals`.
    - `    - [UID:0002W7][0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane](by-memory/0x0069b4c8-0x0069b4cc.g_pOldSystemMessagePane.md) 0x0069b4c8-0x0069b4cc | global pointer | g_pOldSystemMessagePane : reconstructable : 87% : strong : Exact old-system-message singleton slot with current IDA-confirmed four-byte zero-initialized storage, seven xrefs, constructor publish/null-adjustment, cleanup/helper/deleting-destructor clears, broad UI teardown read, old-mode EmotionInputPane consumer, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
  - Placement context: replaced the [UID:0002W8] row currently between [UID:0002W7] `g_pOldSystemMessagePane` and [UID:0002W9] `g_pParcelIconPane`.
    - `    - [UID:0002W8][0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton](by-memory/0x0069b4cc-0x0069b4d0.InputBlockerPaneSingleton.md) 0x0069b4cc-0x0069b4d0 | global pointer | InputBlockerPaneSingleton : reconstructable : 87% : strong : Exact modal input-blocker singleton slot with current IDA-confirmed four-byte zero-initialized storage, 16 xrefs, 248-byte allocation path, InputBlockerPane vtable installation, packet/UI create/destroy behavior, clear-helper/deleting-destructor clears, direct global owner/emitter route, and blank final C++ while declaration placement remains unresolved.`
  - Placement context: replaced the [UID:0002W9] row currently between [UID:0002W8] `InputBlockerPaneSingleton` and [UID:0002WA] `g_pSoundStatusPane`.
    - `    - [UID:0002W9][0x0069b4d0-0x0069b4d4.g_pParcelIconPane](by-memory/0x0069b4d0-0x0069b4d4.g_pParcelIconPane.md) 0x0069b4d0-0x0069b4d4 | global pointer | g_pParcelIconPane : reconstructable : 88% : strong : Exact ParcelIconPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, six xrefs, constructor publish/null-adjustment, nested ParcelPane creation context, non-deleting/helper/scalar-destructor clears, UI teardown read, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
- Next useful follow-up:
  - Later source-quality work should resolve declaration placement/linkage and final symbol spelling for the old system message, input blocker, and parcel icon singleton globals before adding final C++.

## Goal 2 DataSection cluster score batch 0002WA/0002WC/0002WD/0002WF A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-cluster-score-20260614-8`; targets [UID:0002WA] `g_pSoundStatusPane`, [UID:0002WC] `g_pUrlAlertPane`, [UID:0002WD] `g_pUserListDialogPane`, and [UID:0002WF] `g_pMenuVarietyPane`.
- Changed files:
  - `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md`
  - `by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md`
  - `by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md`
  - `by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; active leases were unrelated to these target docs.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0002WA] current IDA MCP confirmed four-byte zero-initialized storage, six xrefs, constructor publish/null-adjustment, SoundStatusPane vtable installs, cleanup/helper/scalar-deleting-destructor clears, and broad UI teardown read.
  - [UID:0002WC] current IDA MCP confirmed four-byte zero-initialized storage, six xrefs, UrlAlertPane constructor publish/null-adjustment, URL text-buffer allocation/copy, cleanup/helper/scalar-deleting-destructor clears, and duplicate-open guard allocation behavior.
  - [UID:0002WD] current IDA MCP confirmed four-byte zero-initialized storage, twelve xrefs, UserListDialogPane constructor publish/null-adjustment, `"Users Dialog Pane"` setup, active-list consumers, lazy packet/UI creation, clear helper, and scalar deleting destructor clear.
  - [UID:0002WF] current IDA MCP confirmed four-byte zero-initialized storage, nine xrefs, MenuVarietyPane constructor publish/null-adjustment, cleanup/destructor clears, menu-option dispatch, and broad UI teardown read.
- Score/status/owner decisions:
  - [UID:0002WA] `g_pSoundStatusPane`: `87/92` -> `88/93`; [UID:0000SB][g_pSoundStatusPane](../../../by-global/g_pSoundStatusPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002WC] `g_pUrlAlertPane`: `87/92` -> `88/93`; [UID:0000SM][g_pUrlAlertPane](../../../by-global/g_pUrlAlertPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002WD] `g_pUserListDialogPane`: `86/90` -> `87/92`; [UID:0003EI][g_pUserListDialogPane](../../../by-global/g_pUserListDialogPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002WF] `g_pMenuVarietyPane`: `87/92` -> `88/93`; [UID:0000RI][g_pMenuVarietyPane](../../../by-global/g_pMenuVarietyPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WA ... 88`, `confidence_update 0002WA ... 93`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WC ... 88`, `confidence_update 0002WC ... 93`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WD ... 87`, `confidence_update 0002WD ... 92`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WF ... 88`, `confidence_update 0002WF ... 93`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor validation: ran `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - Placement context: replaced the [UID:0002WA] row currently between [UID:0002W9] `g_pParcelIconPane` and [UID:0002WB] `g_pTimerPane`.
    - `        - [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) 0x0069b4d4-0x0069b4d8 | global pointer | g_pSoundStatusPane : reconstructable : 88% : strong : Exact SoundStatusPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, six xrefs, constructor publish/null-adjustment, SoundStatusPane vtable installation, cleanup/helper/scalar-destructor clears, broad UI teardown read, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
  - Placement context: replaced the [UID:0002WC] row currently between [UID:0002WB] `g_pTimerPane` and [UID:0002WD] `g_pUserListDialogPane`.
    - `        - [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md) 0x0069b4dc-0x0069b4e0 | global pointer | g_pUrlAlertPane : reconstructable : 88% : strong : Exact UrlAlertPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, six xrefs, constructor publish/null-adjustment, URL text-buffer allocation/copy, cleanup/helper/scalar-destructor clears, duplicate-open guard allocation behavior, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
  - Placement context: replaced the [UID:0002WD] row currently between [UID:0002WC] `g_pUrlAlertPane` and [UID:0002WE] `g_pUserStatusPane2`.
    - `        - [UID:0002WD][0x0069b4e0-0x0069b4e4.g_pUserListDialogPane](by-memory/0x0069b4e0-0x0069b4e4.g_pUserListDialogPane.md) 0x0069b4e0-0x0069b4e4 | global pointer | g_pUserListDialogPane : reconstructable : 87% : strong : Exact UserListDialogPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, twelve xrefs, constructor publish/null-adjustment, Users Dialog Pane setup, active-list consumers, lazy packet/UI creation path, clear-helper/scalar-destructor clears, direct global owner/emitter route, and blank final C++ while declaration placement remains unresolved.`
  - Placement context: replaced the [UID:0002WF] row currently between [UID:0002WE] `g_pUserStatusPane2` and [UID:0002WG] `g_pOldUserStatusPane`.
    - `        - [UID:0002WF][0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane](by-memory/0x0069b4e8-0x0069b4ec.g_pMenuVarietyPane.md) 0x0069b4e8-0x0069b4ec | global pointer | g_pMenuVarietyPane : reconstructable : 88% : strong : Exact MenuVarietyPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, nine xrefs, constructor publish/null-adjustment, cleanup/helper/scalar-destructor clears, menu-option dispatch through the singleton, broad UI teardown read, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
- Next useful follow-up:
  - Later source-quality work should resolve declaration placement/linkage and final symbol spelling for the sound status, URL alert, user-list dialog, and menu-variety singleton globals before adding final C++.

## Goal 2 DataSection cluster/static-storage score batch 0002WG/0002WN/0002WO/0002WP A003 Report - 2026-06-14

- Assignment: `A003-goal2-datasection-cluster-score-20260614-9`; targets [UID:0002WG] `g_pOldUserStatusPane`, [UID:0002WN] `SoundObjectPanePoolStaticStorage`, [UID:0002WO] `EffectObjectPanePoolStaticStorage`, and [UID:0002WP] `HitBarObjectPanePoolStaticStorage`.
- Changed files:
  - `by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md`
  - `by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md`
  - `by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md`
  - `by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md`
  - Validator-owned generated/state side effects from validation: `project-level/-auto-completion-stats.md` and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; active leases were unrelated to these target docs.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Active IDA MCP session `a001_goal2_class_batch` targets `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0002WG] current IDA MCP confirmed four-byte zero-initialized storage, nine xrefs, constructor publish/null-adjustment behavior, `OldUserStatusPane` vtable/resource setup, cleanup/helper/scalar-deleting-destructor clears, TotemFrame paint consumer, user-list status initialization, and living-object status logic.
  - [UID:0002WN] current IDA MCP confirmed 40-byte zero-initialized SoundObjectPane pool storage, eight xrefs, startup wrapper `0x0041a140` with 344-byte blocks in 32-block chunks, cleanup wrapper `0x0060c3a0`, allocation/unwind/free-helper paths, and scalar-deleting-destructor pool release.
  - [UID:0002WO] current IDA MCP confirmed 40-byte zero-initialized EffectObjectPane pool storage, five xrefs, startup wrapper `0x0041a080` with 336-byte blocks in 16-block chunks, cleanup wrapper `0x0060c340`, allocation/free-helper paths, and scalar-deleting-destructor pool release.
  - [UID:0002WP] current IDA MCP confirmed 40-byte zero-initialized HitBarObjectPane pool storage, seven xrefs, startup wrapper `0x0041a0c0` with 312-byte blocks in 4-block chunks, cleanup wrapper `0x0060c360`, allocation/update/free-helper paths, and scalar-deleting-destructor pool release.
- Score/status/owner decisions:
  - [UID:0002WG] `g_pOldUserStatusPane`: `87/92` -> `88/93`; [UID:0000RV][g_pOldUserStatusPane](../../../by-global/g_pOldUserStatusPane.md) owner/emitter retained. Final C++ remains blank because declaration placement/linkage remains unresolved.
  - [UID:0002WN] `SoundObjectPanePoolStaticStorage`: `85/91` -> `86/92`; [UID:0000DH][SoundObjectPane](../../../by-class/SoundObjectPane.md) owner/emitter retained. Final C++ remains blank because static declaration spelling/linkage/placement remains unresolved.
  - [UID:0002WO] `EffectObjectPanePoolStaticStorage`: `85/91` -> `86/92`; [UID:000049][EffectObjectPane](../../../by-class/EffectObjectPane.md) owner/emitter retained. Final C++ remains blank because static declaration spelling/linkage/placement remains unresolved.
  - [UID:0002WP] `HitBarObjectPanePoolStaticStorage`: `85/91` -> `86/92`; [UID:000067][HitBarObjectPane](../../../by-class/HitBarObjectPane.md) owner/emitter retained. Final C++ remains blank because static declaration spelling/linkage/placement remains unresolved.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WG ... 88`, `confidence_update 0002WG ... 93`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WN ... 86`, `confidence_update 0002WN ... 92`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WO ... 86`, `confidence_update 0002WO ... 92`, `projected_stats_update`, and `autogen_registry_rebuild`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md --apply --queue-timeout 180`; result `ok: 1`, `completion_update 0002WP ... 86`, `confidence_update 0002WP ... 92`, `projected_stats_update`, and `autogen_registry_rebuild`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor validation: ran `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
  - Supervisor preserved the existing nested indentation for [UID:0002WN]/[UID:0002WO]/[UID:0002WP] under [UID:0002B4] `ObjectPanePoolStaticStorage`.
  - Placement context: replaced the [UID:0002WG] row currently after [UID:0002WF] `g_pMenuVarietyPane` under [UID:00029Y] `MessageStatusAndMenuPaneGlobals`.
    - `        - [UID:0002WG][0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane](by-memory/0x0069b4ec-0x0069b4f0.g_pOldUserStatusPane.md) 0x0069b4ec-0x0069b4f0 | global pointer | g_pOldUserStatusPane : reconstructable : 88% : strong : Exact OldUserStatusPane singleton slot with current IDA-confirmed four-byte zero-initialized storage, nine xrefs, constructor publish/null-adjustment, OldUserStatusPane vtable installation, resource/text setup, cleanup/helper/scalar-destructor clears, TotemFrame/user-list/living-object consumers, direct global owner/emitter route, and blank final C++ while declaration linkage remains unresolved.`
  - Placement context: replaced the [UID:0002WN] row under [UID:0002B4] `ObjectPanePoolStaticStorage`, after the active A001 [UID:0002WM] row and before [UID:0002WO] `EffectObjectPanePoolStaticStorage`.
    - `    - [UID:0002WN][0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage](by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md) 0x0069b8e4-0x0069b90c | static PoolAllocator storage | SoundObjectPanePoolStaticStorage : reconstructable : 86% : strong : Exact SoundObjectPane PoolAllocator static storage with current IDA-confirmed 40-byte zero-initialized range, eight xrefs, constructor wrapper `sub_41A140` initializing 344-byte blocks in 32-block chunks and registering `sub_60C3A0`, allocation/unwind/free-helper paths, scalar-destructor pool release, direct class owner/emitter route, and blank final C++ while static declaration spelling/linkage remains unresolved.`
  - Placement context: replaced the [UID:0002WO] row under [UID:0002B4] `ObjectPanePoolStaticStorage`, between [UID:0002WN] `SoundObjectPanePoolStaticStorage` and [UID:0002WP] `HitBarObjectPanePoolStaticStorage`.
    - `    - [UID:0002WO][0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage](by-memory/0x0069b90c-0x0069b934.EffectObjectPanePoolStaticStorage.md) 0x0069b90c-0x0069b934 | static PoolAllocator storage | EffectObjectPanePoolStaticStorage : reconstructable : 86% : strong : Exact EffectObjectPane PoolAllocator static storage with current IDA-confirmed 40-byte zero-initialized range, five xrefs, constructor wrapper `sub_41A080` initializing 336-byte blocks in 16-block chunks and registering `sub_60C340`, allocation/free-helper paths, scalar-destructor pool release, direct class owner/emitter route, and blank final C++ while static declaration spelling/linkage remains unresolved.`
  - Placement context: replaced the [UID:0002WP] row under [UID:0002B4] `ObjectPanePoolStaticStorage`, after [UID:0002WO] `EffectObjectPanePoolStaticStorage`.
    - `    - [UID:0002WP][0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage](by-memory/0x0069b934-0x0069b95c.HitBarObjectPanePoolStaticStorage.md) 0x0069b934-0x0069b95c | static PoolAllocator storage | HitBarObjectPanePoolStaticStorage : reconstructable : 86% : strong : Exact HitBarObjectPane PoolAllocator static storage with current IDA-confirmed 40-byte zero-initialized range, seven xrefs, constructor wrapper `sub_41A0C0` initializing 312-byte blocks in 4-block chunks and registering `sub_60C360`, allocation/update/free-helper paths, scalar-destructor pool release, direct class owner/emitter route, and blank final C++ while static declaration spelling/linkage remains unresolved.`
- Next useful follow-up:
  - Resolve source-quality declaration placement/linkage and final static/global spellings for `g_pOldUserStatusPane` and the three object-pane pool statics before adding final C++.

## Goal 2 ObjectList dispatch memory batch 0002C8/0002C9/0002CA/0002CB A003 Report - 2026-06-15

- Assignment: `A003-goal2-objectlist-dispatch-memory-20260615-1`; targets [UID:0002C8] `ObjectListOriginInitializedCheck`, [UID:0002C9] `ObjectListTypeDispatchInsertCategorize`, [UID:0002CA] `ObjectListTypeDispatchRemove`, and [UID:0002CB] `ObjectListEncodedKeyResolve`.
- Changed files:
  - `by-memory/0x00531480-0x00531498.ObjectListOriginInitializedCheck.md`
  - `by-memory/0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md`
  - `by-memory/0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md`
  - `by-memory/0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md`
  - `by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md`
  - Validator-owned generated/state side effects from validation: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; no active leases were present.
  - Successfully leased the four target by-memory docs, the direct aggregate parent, and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Opened live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; server health reported image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - [UID:0002C8] live MCP confirmed `sub_531480` as a 0x18-byte `bool __thiscall(_DWORD *this)` predicate comparing `[ecx+8]` and `[ecx+4]` against `-30000`, one caller at `0x00505955`, and `0x00531498-0x005314a0` as eight `0xcc` bytes.
  - [UID:0002C9] live MCP confirmed `sub_5314A0` size `0x73c`, 12-case switch on `object+0xf8`, callees `sub_5374D0`/`sub_4B7C50`/`sub_4B7E80` plus security-cookie check, 18 code callers, one data xref to `jpt_5314D0`, and table bytes followed by padding to `0x00531c10`.
  - [UID:0002CA] live MCP confirmed `sub_531C10` size `0x532`, 12-case switch on `object+0xf8`, selected-list scans comparing virtual-accessor results against the object pointer before removal, callees `sub_5374D0`/`sub_4B7C50`/`sub_4B7E80`/`sub_537210` plus security-cookie check, 12 code xrefs, one data xref to `jpt_531C43`, and table/alignment bytes through `0x00532180`.
  - [UID:0002CB] live MCP confirmed `sub_532180` size `0x11e`, `sub_535CE0` decode of encoded key into type/selector/index outputs, 10-case ObjectList field/list selection across fields `+0x14` through `+0x38`, six MapPane traversal callers, one data xref to `jpt_5321AA`, and table/alignment bytes through `0x005322d0`.
- Score/status/owner decisions:
  - [UID:00023E] `ObjectListCategorizeLookupHelpers`: `82/86`, owner/emitter `0000M4` -> `85/88`, owner/emitter `00009Q`. Direct aggregate parent now routes through the ObjectList class because [UID:00009Q] and [UID:0000M4] both clear `85/85`.
  - [UID:0002C8] `ObjectListOriginInitializedCheck`: `80/84`, owner/emitter `0000M4` -> `85/90`, owner/emitter `00009Q`.
  - [UID:0002C9] `ObjectListTypeDispatchInsertCategorize`: `80/84`, owner/emitter `0000M4` -> `85/88`, owner/emitter `00009Q`.
  - [UID:0002CA] `ObjectListTypeDispatchRemove`: `80/84`, owner/emitter `0000M4` -> `85/88`, owner/emitter `00009Q`.
  - [UID:0002CB] `ObjectListEncodedKeyResolve`: `80/84`, owner/emitter `0000M4` -> `86/90`, owner/emitter `00009Q`.
  - Final C++ blocks remain blank for all five changed memory pages because final method names, object-type labels, row/global tier names, and source-facing parameter/return names are not final-source quality yet.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00531480-0x00531498.ObjectListOriginInitializedCheck.md --apply --queue-timeout 180`; result `ok: 1`, completion/confidence `0002C8 ... 85/90`, canonical owner and autogen registry `0000M4 -> 00009Q`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x005314a0-0x00531c10.ObjectListTypeDispatchInsertCategorize.md --apply --queue-timeout 180`; result `ok: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00531c10-0x00532180.ObjectListTypeDispatchRemove.md --apply --queue-timeout 180`; result `ok: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00532180-0x005322d0.ObjectListEncodedKeyResolve.md --apply --queue-timeout 180`; result `ok: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md --apply --queue-timeout 180`; result `ok: 1`.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied the exact [UID:00023E], [UID:0002C8], [UID:0002C9], [UID:0002CA], and [UID:0002CB] replacement rows on 2026-06-15.
  - Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- Blockers:
  - No target blockers remain. All four assigned targets and the direct aggregate support page now clear `85/85`.
  - Only pending shared action is supervisor application/validation of the five `by-memory/-coverage-report.md` replacement rows above.

## Goal 2 ObjectList dispatch memory batch 0002CC/0002CD/0002CE/0002BA A003 Report - 2026-06-15

- Assignment: `A003-goal2-objectlist-dispatch-memory-20260615-2`; targets [UID:0002CC] `ObjectListTypeSpecificIndexDispatch`, [UID:0002CD] `ObjectListFindByObjectId`, [UID:0002CE] `ObjectListTypeIndexExistsSwitchHelper`, and [UID:0002BA] `ObjectListEncodedKeyAndRectHelpers`.
- Changed files:
  - `by-memory/0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md`
  - `by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md`
  - `by-memory/0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md`
  - `by-memory/0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md`
  - `tools/leaser/Agents/Agent-A003/notes.md`
- Leases used:
  - Read `tools/leaser/Agents/Agent-A003/current_leases.md` before editing; no active target leases were present.
  - Successfully leased the four target by-memory docs and this notes file as Agent-A003 before editing.
  - Did not edit `by-memory/-coverage-report.md` under the active supervisor ban.
- Fresh evidence:
  - Reused live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - [UID:0002CC] live MCP reconfirmed `sub_5322D0` at `0x005322d0`, size `0x71`, switch over `object+0xf8` cases `0..8`, dispatch to the type-specific encoded-key lookup family, default `-1`, six MapPane traversal xrefs, table data ref from `0x005322e2`, and table/alignment bytes through `0x00532370`.
  - [UID:0002CD] live MCP reconfirmed `sub_532370` at `0x00532370`, size `0xd3`, list traversal through ObjectList fields `this[9]`, `this[5]`, and `this[6]`, vtable-slot entry fetches, comparison against object field `+0xfc`, 33 code xrefs, and `0x00532443-0x00532450` as `0xcc` alignment.
  - [UID:0002CE] live MCP reconfirmed `0x00532450` is not an IDA function, but `insn_query` shows a complete raw prologue/switch/retn helper over `object+0xf8`, nine type-specific lookup calls, compare-against-`0xffffffff`/`setnz` boolean returns, no direct code xrefs to the helper start, a data xref from `0x00532466` to table `0x0053250c`, and raw bytes through the successor at `0x00532530`.
  - [UID:0002BA] live MCP reconfirmed raw helper starts at `0x00535b10`, `0x00535b50`, `0x00535b90`, and `0x00535bd0`; modeled decoder `sub_535CE0` size `0xd8`; three raw rectangle helpers calling `sub_4B7C50`; raw key encoder compare chain for type bytes `0..0x0b`; decoder switch on `key >> 28`; seven code xrefs to `sub_535CE0`; no direct code xrefs to the raw helper starts; table `0x00535db8-0x00535de8`; and final alignment to `0x00535df0`.
- Score/status/owner decisions:
  - [UID:0002CC] `ObjectListTypeSpecificIndexDispatch`: `80/84`, owner/emitter `0000M4` -> `86/90`, owner/emitter `00009Q`.
  - [UID:0002CD] `ObjectListFindByObjectId`: `80/84`, owner/emitter `0000M4` -> `85/88`, owner/emitter `00009Q`.
  - [UID:0002CE] `ObjectListTypeIndexExistsSwitchHelper`: `80/84`, owner/emitter `0000M4` -> `85/86`, owner/emitter `00009Q`. Score remains capped by missing IDA function object and zero direct caller xrefs.
  - [UID:0002BA] `ObjectListEncodedKeyAndRectHelpers`: `80/84`, owner/emitter `0000M4` -> `85/88`, owner/emitter `00009Q`. Score remains capped by final helper names and unresolved raw rectangle-helper reachability.
  - Final C++ blocks remain blank for all four targets because final method/helper names, exact return/field names, and private-method versus file-static structure are not final-source quality yet.
- Supervisor-applied `by-memory/-coverage-report.md` replacement rows:
  - Supervisor applied the exact [UID:0002CC], [UID:0002CD], [UID:0002CE], and [UID:0002BA] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
- Validation:
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x005322d0-0x00532370.ObjectListTypeSpecificIndexDispatch.md --apply --queue-timeout 180`; result `ok: 1`, completion/confidence `0002CC ... 86/90`, canonical owner and autogen registry `0000M4 -> 00009Q`, and low-confidence stats row removed.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00532370-0x00532443.ObjectListFindByObjectId.md --apply --queue-timeout 180`; result `ok: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00532450-0x00532530.ObjectListTypeIndexExistsSwitchHelper.md --apply --queue-timeout 180`; result `ok: 1`.
  - Ran `python .\tools\validator.py --mode file --file by-memory\0x00535b10-0x00535df0.ObjectListEncodedKeyAndRectHelpers.md --apply --queue-timeout 180`; result `ok: 1`.
  - Re-ran the same four file-mode validator commands after notes update with filtered output; each target again returned `ok: 1`.
  - Validator-managed generated/state side effects: `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and `tools/validator.ini`.
- Blockers:
  - No target blockers remain for the 85/85 assignment gate. [UID:0002CE] remains capped at `85/86` because IDA still does not model `0x00532450` as a function and direct caller xrefs remain unresolved; [UID:0002BA] remains capped at `85/88` because raw rectangle-helper reachability and final helper names remain unresolved.
  - Required shared action remains supervisor application/validation of the four `by-memory/-coverage-report.md` replacement rows above.
- Lease cleanup:
  - The initial target/notes leases expired during the final validator rerun before explicit release; no by-memory target edits were made after expiration. `python leaser.py Agent-A003 unlease` purged the expired leases and reported no active leases.
  - Took a fresh notes-only lease to record this cleanup note, then released it after editing.
## 2026-06-15 - A003-goal2-download-cashshop-memory-20260615-1 completion report

Assignment: Goal 2 download/cash-shop low-confidence memory batch.

Targets changed and validated:

- [UID:0002TR] `by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md`: `80/84` -> `85/88`.
- [UID:0002TS] `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`: `80/84` -> `85/89`.
- [UID:0000WJ] `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`: `80/84` -> `85/88`.
- [UID:0002TT] `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`: `80/84` -> `85/88`.

Route changes:

- No owner/emitter route changes.
- All four targets retain canonical owner/emitter [UID:0000JC] `FileDownloader`.
- Rationale: 2026-06-15 live IDA MCP still shows the only direct download-helper callers are `sub_41B110` dispatcher branches at `0x0041b168`, `0x0041b13c`, and `0x0041b156`; cash-shop/fitting-room/minimap pages remain feature or payload context rather than corrected emitters.

IDA/local evidence used:

- Live IDA MCP `server_health` confirmed the NexusTK.exe IDB session was ready.
- `lookup_funcs` confirmed `sub_41A750` size `0x2ae`, `sub_41AA00` size `0x41c`, `sub_41AE20` size `0x2ec`, `sub_41B110` size `0x70`, `sub_41B180` size `0x75`, `sub_41B200` size `0x6d`, `sub_41B270` size `0x59`, and no function at `0x0041b2c9`.
- `xref_query` confirmed direct calls from `sub_41B110` to the three helpers and submit-helper callers at `0x451d18`, `0x41cd0f`, and `0x41c21b`.
- `decompile` confirmed message `10000` -> minimap `.mnm` S3 download/free, `10001` -> `itemshop.json` catalog download, `10002` -> `itemshop.ver` version download/destruct; WinINet status/content-length/progress handling; JsonCpp `version` parse; `dword_67A73C + 1936` and `+1960` fitting-room state interactions.
- `get_bytes` confirmed `cc` padding at `0x0041a9fe`, `0x0041ae1c`, `0x0041b10c`, and `0x0041b2c9`.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0041a750-0x0041a9fe.DownloadMinimapFile.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; `0002TR` removed from `project-level/-auto-completion-stats.md` low-confidence list by validator.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; `0002TS` removed from low-confidence list by validator.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; `0000WJ` removed from low-confidence list by validator.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; `0002TT` removed from low-confidence list by validator.

IDA DB changes:

- Skipped. Existing local names are still generic `sub_*`, and the docs do not yet justify source-quality helper/payload names strongly enough for safe IDA renames.

Remaining blockers:

- Final payload struct names and field names remain provisional.
- Final original source split between FileDownloader-local helpers, CashShopVersionRequest payload support, FittingRoom state/UI code, and MiniMap feature code remains below a source-quality C++ gate.
- C++ reconstruction blocks intentionally remain blank for all four target pages.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0002TR], [UID:0000WJ], [UID:0002TS], and [UID:0002TT] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`.
## 2026-06-15 - A003-goal2-ui-input-memory-20260615-1 completion report

Assignment: Goal 2 UI/input low-confidence memory batch.

Targets changed and validated:

- [UID:0002QT] `by-memory/0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md`: `80/84` -> `85/88`; owner/emitter `0000IK` -> `00003B`.
- [UID:0002KE] `by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md`: `80/84` -> `85/88`; owner/emitter unchanged `0000A6`.
- [UID:0001KY] `by-memory/0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md`: `80/84` -> `85/88`; owner/emitter `0000OH` -> `0000DX`.
- [UID:0001L4] `by-memory/0x005aec60-0x005af2e7.ItemWhoInputPane.md`: `80/84` -> `85/87`; owner/emitter `0000OH` -> `00006X`.

Route decisions:

- [UID:0002QT] now routes through the direct class owner [UID:00003B] `CreateUserDialogPane`, which clears `85/85` and emits through [UID:0000IJ] `CreateUserDialogPane`; [UID:0000IK] `CreateUserDialogs` remains the umbrella family page.
- [UID:0002KE] remains directly owned by [UID:0000A6] `ParcelPane`; current parent class/file pages already clear the gate.
- [UID:0001KY] now routes through direct class owner [UID:0000DX] `SpellWhoInputPane`; [UID:0000OH] `TargetSelectionInputPanes` remains the emitting file route.
- [UID:0001L4] now routes through direct class owner [UID:00006X] `ItemWhoInputPane`; [UID:0000OH] `TargetSelectionInputPanes` remains the emitting file route.

IDA/local evidence used:

- IDA MCP session `a003_objectlist_dispatch_20260615` remained available for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `idb_list` reported the session not actively analyzing, and `server_health` reported Hex-Rays/strings ready.
- [UID:0002QT] live `lookup_funcs`, `xrefs_to`, `analyze_component`, `decompile`, and `get_bytes` reconfirmed old-dialog function sizes, constructor callers at `0x004f7a82`/`0x004f8ff8`, command-submit-packet/reply edges, vtable refs through `0x0061fe3c`, singleton refs through `0x0069b890`, appearance-control constructor callees, submit validation behavior, and post-core jump-table/alignment bytes at `0x0052f6e5`.
- [UID:0002KE] live IDA reconfirmed `sub_546610` size `0x1f7`, secondary-vtable xref `0x00621c94`, decompiled move/press/release state machine, packet action byte `0x41`, `dword_67A7EC` send path, `unk_67ADC0` bulletin-session gate, `sub_471150` BulletinSession constructor call, and nine `0xcc` bytes at `0x00546807-0x00546810`.
- [UID:0001KY] live IDA reconfirmed SpellWhoInputPane child starts/sizes, three constructor callers at `0x0057cade`/`0x0057e3f8`/`0x0057f109`, 32 refs to saved spell target global `0x0069bf20`, vtable refs through `0x0062f210`, key-handler decompilation, switch-table bytes at `0x005ae68a-0x005ae730`, and successor padding at `0x005aeb1f`.
- [UID:0001L4] live IDA reconfirmed ItemWhoInputPane child starts/sizes, 30 refs to saved item target global `0x0069bf24`, vtable refs through `0x0062f2ec`, mouse-handler decompilation with map hit-test/highlight/dispatch flow, switch-table bytes at `0x005aefaf-0x005af050`, and nine `0xcc` bytes at `0x005af2e7-0x005af2f0`.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0052dd30-0x0052f6e5.CreateUserDialogPaneCore.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; canonical owner changed `0000IK -> 00003B`; `0002QT` removed from low-confidence stats.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00546610-0x00546807.ParcelPaneOnMouseEvent.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; `0002KE` removed from low-confidence stats.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x005ae2a0-0x005aeb1f.SpellWhoInputPane.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; canonical owner changed `0000OH -> 0000DX`; `0001KY` removed from low-confidence stats.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x005aec60-0x005af2e7.ItemWhoInputPane.md --apply --queue-timeout 180` -> ok; completion/confidence metadata applied; canonical owner changed `0000OH -> 00006X`; `0001L4` removed from low-confidence stats.

IDA DB changes:

- Skipped. The evidence supports documentation route/score changes, but final source-quality method/helper/field names are still not strong enough for safe IDA renames.

Remaining blockers:

- Final C++ remains blank for all four targets.
- [UID:0002QT] still needs final field/helper names and the exact old appearance-control source split before source reconstruction.
- [UID:0002KE] still needs final event/helper/action names before source reconstruction.
- [UID:0001KY] and [UID:0001L4] still need final member/helper names, event layout names, and packet/helper names before source reconstruction; [UID:0001L4] remains slightly capped because the current IDB has no direct ordinary constructor xref and inline construction/use paths require careful source-shape handling.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0002QT], [UID:0002KE], [UID:0001KY], and [UID:0001L4] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 UI/input supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-memoryman-tail-lowcompletion-20260615-2 completion report

Assignment: Goal 2 MemoryMan tail low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 10:52.

Targets changed and validated:

- [UID:0001BF] `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`: `78/86` -> `85/89`; owner/emitter unchanged `0000L7`.
- [UID:0001BG] `by-memory/0x00516190-0x00516210.ReallocateOrThrow.md`: `78/86` -> `85/88`; owner/emitter unchanged `0000L7`.
- [UID:0001BH] `by-memory/0x00516220-0x00516238.MemmoveWrapper.md`: `78/86` -> `85/86`; owner/emitter unchanged `0000L7`.
- [UID:0001BI] `by-memory/0x00516240-0x00516258.Memmove0Wrapper.md`: `78/86` -> `85/86`; owner/emitter unchanged `0000L7`.
- [UID:0001BJ] `by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md`: `78/86` -> `86/90`; owner/emitter `0000L7` -> `00007U`.

Route decisions:

- [UID:0001BF], [UID:0001BG], [UID:0001BH], and [UID:0001BI] retain canonical owner/emitter [UID:0000L7] `MemoryMan`; the file page is already `89/86` and owns the adjacent allocation/copy utility island.
- [UID:0001BJ] now routes through [UID:00007U] `MemoryMan`; the class page is `86/88`, emits to [UID:0000L7], and current IDA confirms this body is the MemoryMan vtable-slot scalar deleting destructor rather than a file-level free helper.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0001BF] live IDA confirmed `sub_516170` size `0x14`, `j___free_base(Block); return 0`, at least 100 caller xrefs with more available, operator-delete wrapper edge from `0x004f4ac0`, and padding after `0x00516184`.
- [UID:0001BG] live IDA confirmed `sub_516190` size `0x80`, 10 caller xrefs, `realloc(Block, newSize)` success path, matching 8-byte `Win32Error` allocation/construction and `_CxxThrowException` failure path, and padding after `0x00516210`.
- [UID:0001BH] live IDA confirmed `sub_516220` size `0x18`, at least 100 caller xrefs with more available, single `_memmove` wrapper body, one-basic-block shape, and padding after `0x00516238`.
- [UID:0001BI] live IDA confirmed `sub_516240` size `0x18`, 19 caller xrefs, single `_memmove_0` wrapper body, one-basic-block shape, and padding after `0x00516258`.
- [UID:0001BJ] live IDA confirmed `sub_516260` size `0x2e`, vtable slot xref at `0x0061eb08`, vtable reset, `g_pMemoryMan` clear, conditional delete through `sub_5C7526` when the flag low bit is set, return `this`, `0x0051628e` not-a-function, and two `0xcc` alignment bytes before the neighboring `0x00516290` function prologue.

Validation:

- Ran `python source-3\project-documentation\tools\validator.py --mode file --file <target> --apply --queue-timeout 180` for all five changed target files. Each returned `ok: 1`.
- Initial validator pass applied the completion/confidence metadata and removed the five UIDs from the refreshed low-completion stats; a follow-up `Select-String` check against `project-level/-auto-completion-stats.md` returned no matches for `0001BF/0001BG/0001BH/0001BI/0001BJ`.
- Re-ran the same five validator commands with tighter output filtering after the noisy autogen rebuild; each again returned `ok: 1` with `autogen_registry_rebuild: 1` and `projected_stats_update: 1`.

IDA DB changes:

- Skipped. The evidence supports documentation scores and the destructor route correction, but final helper names, copy-wrapper source factoring, destructor source representation, and declaration forms are still not source-quality enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All five assigned targets now honestly clear the assignment gate.
- Final C++ remains blank for all five target pages. [UID:0001BH]/[UID:0001BI] remain capped at `85/86` because the MemoryMan-versus-runtime-support copy-wrapper source split remains unresolved. [UID:0001BJ] remains blank because the final source should likely be an ordinary destructor/source declaration that lets the compiler emit the scalar deleting wrapper, not a hand-written scalar deleting destructor.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0001BF], [UID:0001BG], [UID:0001BH], [UID:0001BI], and [UID:0001BJ] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 MemoryMan tail supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-memoryman-lowcompletion-20260615-1 completion report

Assignment: Goal 2 MemoryMan low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 10:39.

Targets changed and validated:

- [UID:0001BB] `by-memory/0x00516010-0x00516021.MemoryManGlobalResetTail.md`: `78/86` -> `85/88`; owner/emitter unchanged `0000L7`.
- [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`: `78/86` -> `85/90`; owner/emitter unchanged `0000L7`.
- [UID:0001BD] `by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md`: `78/86` -> `85/88`; owner/emitter unchanged `0000L7`.
- [UID:0001BE] `by-memory/0x005160d0-0x00516162.ZeroAllocateBufferMemory.md`: `78/86` -> `85/88`; owner/emitter unchanged `0000L7`.

Route decisions:

- No owner/emitter route changes. All four targets retain canonical owner/emitter [UID:0000L7] `MemoryMan`.
- Rationale: the direct [UID:0000L7] `MemoryMan` file page is already `89/86`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`, and owns this file-level singleton/allocation utility family. [UID:00007U] `MemoryMan` class is valid support, but the target helpers are file-level static-lifetime/accessor/allocation support rather than narrowed class methods with final-source signatures.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0001BB] live IDA confirmed the reset body is modeled as the `sub_60C260` atexit thunk chunk, with the code edge from `0x0060c265` to `0x00516010`, static initializer registration from `0x00419f70`, `0x0069b3a8` vtable reset, `0x0069b4fc` clear, vtable/global xrefs, and `0xcc` padding after `0x00516021`.
- [UID:0001BC] live IDA confirmed `sub_516030` size `0x06`, decompiled single return of `unk_69B4FC`, broad accessor fanout, operator-wrapper calls through `0x004f4aa0`/`0x004f4ac0`, and local padding after `0x00516036`.
- [UID:0001BD] live IDA confirmed `sub_516050` size `0x7e`, at least 100 caller xrefs, `malloc(size)` success return, failure allocation of an 8-byte object through `sub_4F4AA0(8)`, `sub_4A60D0` Win32Error construction, `_CxxThrowException` with `__TI4PAVWin32Error@@`, and padding after `0x005160ce`.
- [UID:0001BE] live IDA confirmed `sub_5160D0` size `0x92`, 13 caller xrefs, `malloc(Size)`, `memset(block, 0, Size)`, matching 8-byte Win32Error construction/throw path, and padding after `0x00516162`.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00516010-0x00516021.MemoryManGlobalResetTail.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0001BB` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00516030-0x00516036.GetMemoryMan.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0001BC` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00516050-0x005160ce.AllocateBufferMemory.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0001BD` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x005160d0-0x00516162.ZeroAllocateBufferMemory.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0001BE` removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The documentation evidence supports score/route confirmation, but final source-quality names, declaration forms, static-object emission shape, and global-operator placement are still not strong enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All four targets now honestly clear the assignment gate.
- Final C++ remains blank for all four target pages because final static-object cleanup emission, accessor declaration form, allocator API spelling, exception object declaration shape, and global operator/source placement remain unresolved.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0001BB], [UID:0001BC], [UID:0001BD], and [UID:0001BE] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 MemoryMan low-completion supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-scroll-deque-string-lowcompletion-20260615-3 completion report

Assignment: Goal 2 low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 11:03.

Targets changed and validated:

- [UID:0001GI] `by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md`: `78/86` -> `85/88`; owner/emitter `0000NF` -> `0000CM`.
- [UID:0001GX] `by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md`: `78/86` -> `85/88`; owner/emitter `0000NG` -> `0000CG`.
- [UID:0001IE] `by-memory/0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md`: `78/86` -> `85/88`; owner/emitter `0000IR` -> `00003P`.
- [UID:0002RO] `by-memory/0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md`: `78/86` -> `85/89`; owner/emitter `0000OA` -> `0001WS`.

Route decisions:

- [UID:0001GI] now routes through [UID:0000CM] `ScrollPane`, which is `86/87` and emits to [UID:0000NF] `ScrollBar`; current IDA confirms this is the `ScrollPane` vtable draw virtual.
- [UID:0001GX] now routes through [UID:0000CG] `ScrollCollectionPane`, which is `85/85` and emits to [UID:0000NG] `ScrollCollectionPane`; current IDA confirms this is a class cursor-to-position helper.
- [UID:0001IE] now routes through [UID:00003P] `Deque`, which is `86/88` and emits to [UID:0000IR] `Deque`; current IDA confirms this method uses the Deque layout directly despite the SoundManager caller.
- [UID:0002RO] now routes through [UID:0001WS] `StringBaseTemplate`, which is `86/90` and emits to [UID:0000OA] `StringBase`; current IDA confirms this range is a StringBase template allocation/grow/COW helper group.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0001GI] live IDA reconfirmed `sub_55C650` size `0x1307`, no function at `0x0055d957`, successor `0x0055d960`, vtable-only xref at `0x00623da0`, draw/clip/geometry callee set, resource/global refs including `0x0060ddb0`, `0x0060ddc8`, `0x0060dde0`, `0x0060ddf8`, `0x006187cc`, `0x0061879c`, `dword_624144`, `dword_62415C`, and nine `0xcc` padding bytes after the method.
- [UID:0001GX] live IDA reconfirmed `sub_563070` size `0x18d`, caller pair from `sub_562FB0`, no function at `0x005631fd`/`0x00563200`, cursor invalid-point checks, orientation/range/drag-offset fields, vertical/horizontal scaling branches, owner callback `sub_56FA90`, and three-byte padding before the next raw helper.
- [UID:0001IE] live IDA reconfirmed `sub_57B9E0` size `0xc3`, SoundManager caller plus `0x0057bab0` thunk, Deque layout offsets, `sub_582B30` owned-slot release loop, block/map/auxiliary frees through `sub_5C7526`, large-allocation guard, and padding after `0x0057baa3`.
- [UID:0002RO] live IDA reconfirmed contained functions `0x00582d80`, `0x00582e30`, `0x00582ef0`, `0x00582fa0`, `0x00583050`, and `0x005830c0`, ANSI/wide sentinel and pool/heap allocation behavior, grow helpers, detach-on-share helpers, internal allocator/release/memmove calls, and padding after `0x00583132`.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0055c650-0x0055d957.ScrollPaneOnDraw.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000NF -> 0000CM`; `0001GI` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000NG -> 0000CG`; `0001GX` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0057b9e0-0x0057baa3.DequeDestroyOwnedEntries.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000IR -> 00003P`; `0001IE` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00582d80-0x00583132.StringBaseAllocationGrowAndCow.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000OA -> 0001WS`; `0002RO` removed from Low_Completion/Low_Both/by-memory stats rows.
- Follow-up `Select-String` against `project-level/-auto-completion-stats.md` found no remaining `0001GI/0001GX/0001IE/0002RO` rows.

IDA DB changes:

- Skipped. The evidence supports documentation scores and owner/emitter route corrections, but final helper names, field names, source declarations, and source split decisions are not source-quality enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Final C++ remains blank for all four pages. Scroll targets still need final render/cursor/field names; Deque still needs final owned-entry/payload naming and thunk source shape; StringBase still needs final public API names and pool/header declaration spelling.

Supervisor-applied by-memory/-coverage-report.md replacement rows:

Supervisor applied the exact [UID:0001GI], [UID:0001GX], [UID:0001IE], and [UID:0002RO] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 scroll/deque/string supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-sharedlist-thrunet-control-dat-memory-20260615-4 completion report

Assignment: Goal 2 shared-list/thrunet/control/DAT low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 11:14.

Targets changed and validated:

- [UID:0000ZR] `by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md`: `78/88` -> `85/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0002BJ] `by-memory/0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md`: `78/88` -> `85/89`; owner/emitter remain [UID:0000N4] `RegistryConfig` file.
- [UID:0002PB] `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`: `78/88` -> `85/90`; owner/emitter changed [UID:0000IG] `ControlPane` file -> [UID:000038] `ControlPane` class.
- [UID:000227] `by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md`: `78/88` -> `85/89`; owner/emitter changed [UID:0000IO] `DATFileMgr` file -> [UID:00003I] `DATFileMgr` class.

Route decisions:

- [UID:0000ZR] remains ownerless/ignored compiler glue because current IDA confirms it is shared scalar deleting destructor support referenced by six list-pane vtables, plus secondary/tertiary adjustor thunks. No single source owner route is defensible.
- [UID:0002BJ] remains routed to the [UID:0000N4] `RegistryConfig` file. [UID:0000BW] `RegistryConfig` class clears the gate, but the function evidence is a launcher/auth parser helper in the config module, not a proven `RegistryConfig::` instance method.
- [UID:0002PB] now routes through [UID:000038] `ControlPane` because both the constructor child and class parent clear the corrected `85/85` gate, and current IDA confirms the ControlPane vtable stores and broad shared-control caller fanout.
- [UID:000227] now routes through [UID:00003I] `DATFileMgr` because both the raw public wrapper child and class parent clear the corrected `85/85` gate, and current IDA confirms the wrapper loads public-wrapper offset `+4` and tail-jumps into the private manager lookup target.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0000ZR] live IDA reconfirmed `sub_47EA50` size `0x3b`, no function at `0x0047ea8b`, `0xcc` end padding, direct callees `sub_4F3B60`, `sub_4F4AC0`, and current IDA runtime target `@_guard_check_icall_nop@4`, adjustor-thunk code xrefs from `0x0047e8ad`/`0x0047e8b8`, and vtable xrefs at `0x00613ce8`, `0x006156ac`, `0x00615770`, `0x00615834`, `0x00619dc8`, and `0x00619f28`.
- [UID:0002BJ] live IDA reconfirmed `sub_48FCA0` size `0x550`, `0xcc` alignment after `0x004901f0`, cleanup/unwind chunks at `0x00493f00` and `0x005fccc2` still assigned to the same IDA function, no direct caller xrefs to the start, the `thrunet.clsURLCHK` string reference, and command-line/file/DNS/COM callees including `GetCommandLineW`, `_fgetc`, `_fclose`, `WideCharToMultiByte`, `gethostbyname`, `CoInitialize`, `MessageBoxW`, and `PostQuitMessage`.
- [UID:0002PB] live IDA reconfirmed `sub_4949E0` size `0xa1`, `0xcc` end padding, direct callees `sub_544460` and `sub_544BD0`, ControlPane vtable refs at `0x00617a90`, `0x00617af8`, and `0x00617b28`, vtable-store xrefs at `0x00494a23`, `0x00494a29`, and `0x00494a33`, packed field writes, and 52 direct constructor caller xrefs.
- [UID:000227] live IDA reconfirmed no function object at `0x0049bd20` or `0x0049bd2c`, exact raw bytes `55 8b ec 8b 49 04 5d e9 a4 0d 00 00`, `0xcc` successor padding, raw tail jump at `0x0049bd27` into `sub_49CAD0`, four refs to `0x0049cad0`, and target helper behavior: byte return, sentinel/no-hit compare against `this[2]`, and optional two-dword output-buffer writes from node offsets `+0x0c` and `+0x10`.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0000ZR` removed from Low_Completion.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0048fca0-0x004901f0.ThrunetStartupAuthFileParser.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0002BJ` removed from Low_Completion.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004949e0-0x00494a81.ControlPaneConstructor.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000IG -> 000038`; `0002PB` removed from Low_Completion.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000IO -> 00003I`; `000227` removed from Low_Completion.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and the two owner/emitter route corrections, but final source-quality names, field names, source declarations, and runtime-helper names are not strong enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Final C++ remains blank for all four metadata blocks. [UID:0000ZR] is non-reconstructable compiler glue; [UID:0002BJ] still lacks final startup-state and COM interface names; [UID:0002PB] still lacks final member/bounds argument names; [UID:000227] still lacks final public method spelling and output record type.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000ZR], [UID:0002BJ], [UID:0002PB], and [UID:000227] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 SharedList/Thrunet/Control/DAT supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-imagelib-cluster-memory-20260615-5 completion report

Assignment: Goal 2 ImageLib cluster low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 11:29.

Targets changed and validated:

- [UID:000173] `by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md`: `78/88` -> `85/90`; owner/emitter remain [UID:00006E] `ImageLib`.
- [UID:00017A] `by-memory/0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md`: `78/88` -> `85/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:00017E] `by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md`: `78/88` -> `85/90`; owner/emitter changed [UID:0000LJ] `MonsterImageLib` file -> [UID:00008N] `MonsterImageLib` class.
- [UID:00017N] `by-memory/0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md`: `78/88` -> `85/89`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- [UID:000173] remains routed through [UID:00006E] `ImageLib`, which clears the direct-parent gate and emits through [UID:0000K2] `ImageLib`; current IDA confirms this is the ordinary ImageLib destructor.
- [UID:00017A] remains ownerless/non-emitting because current IDA confirms it is a large local HumanImageLib method cluster whose source-owned children and raw helper islands are not represented by this aggregate page.
- [UID:00017E] now routes through [UID:00008N] `MonsterImageLib` because both child and class parent clear the corrected `85/85` gate, and current IDA confirms the lazy archive-bounds bucket loader is a MonsterImageLib instance method.
- [UID:00017N] remains ownerless/non-emitting because current IDA confirms it is a contiguous ItemObjImageLib local method cluster with child/source ownership split across exact constructor/destructor/draw helper pages.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:000173] live IDA reconfirmed `sub_4D0070` size `0xab`, no function at `0x004d011b`, five `0xcc` bytes after the method, ImageLib vtable refs from constructor/destructor/scalar-deleting-destructor code, MemoryMan accessor/free calls, list-row payload cleanup at record `+0x28`, virtual list deletion, `g_pEPFLib` clear, and base cleanup chain into `sub_4F4A90`.
- [UID:00017A] live IDA reconfirmed `sub_4D2720` constructor size `0x23aa`, `sub_4D4AD0` destructor size `0x497`, lower HumanImageLib local functions through `0x004da850`, `0xcc` padding at internal boundaries, successor MonsterImageLib boundary at `0x004dac40`, table-name strings such as `headtable.txt`, `headsptable.txt`, `swordtable.txt`, `speartable.txt`, and `bowtable.txt`, and ProtectedArray/HumanImageLib vtable touches.
- [UID:00017E] live IDA reconfirmed `sub_4DBE60` size `0x315`, padding through successor `0x004dc180`, caller refs from `sub_4DB5C0` and `sub_4DC180`, lazy `DATA/MON%d.DAT` loading, archive handle/index fields at `+0x1c`/`+0x3c`, `0x0c` bucket records, `0x18` entry rows, bounds initialization through `sub_4B7C50`, payload-base rebasing, and zero-bounds sentinel row.
- [UID:00017N] live IDA reconfirmed the contained ItemObjImageLib local functions at `0x004dec30`, `0x004dee50`, `0x004defc0`, `0x004df1e0`, `0x004df2c0`, and `0x004df460`, padding after each function, successor table-loader boundary at `0x004df500`, startup constructor caller at `0x004f602f`, broad draw/glyph refs to `0x004df460`, and shared EPF/resource/palette/render callees.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d0070-0x004d011b.ImageLibDestructor.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `000173` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004d2720-0x004dac40.HumanImageLibLocalMethodCluster.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `00017A` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; canonical owner `0000LJ -> 00008N`; `00017E` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004dec30-0x004df500.ItemObjImageLibLocalMethodCluster.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `00017N` removed from Low_Completion stats rows.
- Follow-up `rg` against `project-level/-auto-completion-stats.md` found no remaining `000173/00017A/00017E/00017N` rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and the MonsterImageLib owner/emitter route correction, but final source-quality names, field names, declaration forms, and source split decisions are not strong enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Final C++ remains blank for all four pages. [UID:000173] still lacks final destructor/source spelling; [UID:00017A] and [UID:00017N] are non-emitting aggregate pages; [UID:00017E] still lacks final field/type names and source declaration quality.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:000173], [UID:00017A], [UID:00017E], and [UID:00017N] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 ImageLib cluster supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-newhuman-motion-imagelib-memory-20260615-6 completion report

Assignment: Goal 2 NewHuman/motion/ImageLib low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 11:40.

Targets changed and validated:

- [UID:00017R] `by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md`: `78/88` -> `85/89`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:000185] `by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md`: `78/88` -> `86/89`; owner/emitter remain [UID:0000LR] `NewHumanImageLib` file.
- [UID:0002IO] `by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md`: `78/88` -> `85/90`; owner/emitter remain [UID:00006E] `ImageLib` class.
- [UID:00017Y] `by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md`: `78/90` -> `85/90`; owner/emitter remain [UID:0000KH] `ItemObjImageLib` file.

Route decisions:

- [UID:00017R] remains ownerless/non-emitting because it is a reviewed local-method-cluster audit. Exact child pages and surrounding helper pages carry source ownership; the aggregate itself is not a separate source item.
- [UID:000185] remains routed to [UID:0000LR] `NewHumanImageLib` as a file-local Motion.tbl vector cleanup helper. Current IDA shows one executable destructor caller plus a constructor-associated cleanup-table reference, and [UID:0000LL] `Motion` remains explicitly rejected.
- [UID:0002IO] remains routed through [UID:00006E] `ImageLib`, which emits through [UID:0000K2] `ImageLib`; current IDA confirms the vtable slot and ImageLib destructor/list cleanup behavior.
- [UID:00017Y] remains routed to [UID:0000KH] `ItemObjImageLib` as static-lifetime singleton cleanup glue. It has no `this` parameter and no ordinary callers, so a class-method route is not appropriate.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:00017R] live IDA reconfirmed 29 modeled functions in `0x004dfd10-0x004e4d79`, no function at `0x004e4d79`/`0x004e4d80`, constructor/destructor/draw/load/build/render internal edges, NewHumanImageLib singleton and vtable refs, classifier helpers at `0x004e05d0`/`0x004e0630`, composition rect/frame helpers at `0x004e4140`/`0x004e4210`, and the post-cluster split from later vector/list/singleton/scalar-destructor helper islands.
- [UID:000185] live IDA reconfirmed `sub_4E5DD0` size `0x69`, prototype shape, seven basic blocks, complexity `3`, destructor caller `0x004e0547`, constructor-associated reference `0x0060025a`, checked-free and invalid-parameter callees, `0x42` record-span math, large-allocation guard, vector triplet reset, and seven `0xcc` bytes before `0x004e5e40`.
- [UID:0002IO] live IDA reconfirmed `sub_4E64A0` size `0xd2`, exclusive end `0x004e6572`, only direct xref from the ImageLib vtable slot at `0x0061b654`, list payload cleanup at record `+0x28`, `g_pEPFLib` clear, base cleanup, scalar-delete and guard-check branches, and `0xcc` padding before `0x004e6580`.
- [UID:00017Y] live IDA reconfirmed `sub_4E5BA0` size `0xb`, exact `mov dword_67A758, 0; retn` bytes, no function at `0x004e5bab`, five-byte alignment before `0x004e5bb0`, one cleanup-table xref at `0x00600158` tied to `sub_4DEC30`, one basic block, no callees, and the `g_pItemObjImageLib` singleton lifecycle/consumer evidence.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `00017R` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004e5dd0-0x004e5e39.DestroyMotionVector.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `000185` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0002IO` removed from Low_Completion stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md --apply --queue-timeout 180` -> `ok: 1`; completion applied; `00017Y` removed from Low_Completion stats rows.
- Follow-up `rg` against `project-level/-auto-completion-stats.md` found no remaining `00017R/000185/0002IO/00017Y` rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and route preservation, but final source-quality helper names, field names, declaration forms, and deleting-destructor/static-cleanup source expressions are not strong enough for safe IDA renames.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Final C++ remains blank for all four pages. [UID:00017R] is a non-emitting aggregate; [UID:000185] still lacks final `MotionEntry` names/signature; [UID:0002IO] still needs final deleting-destructor source representation; [UID:00017Y] still needs final static-lifetime source expression.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:00017R], [UID:00017Y], [UID:000185], and [UID:0002IO] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 NewHuman/motion/ImageLib supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-jsoncpp-reader-writer-memory-20260615-8 completion report

Assignment: Goal 2 JsonCpp reader/writer low-completion memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 12:02.

Targets changed and validated:

- [UID:0000X7] `by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md`: `80/85` -> `85/88`; owner/emitter remain [UID:0000KI] `JsonCpp`.
- [UID:0001ZS] `by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md`: `80/85` -> `85/88`; owner/emitter remain [UID:0000KI] `JsonCpp`.
- [UID:0000XC] `by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md`: `80/85` -> `86/89`; owner/emitter remain [UID:0000KI] `JsonCpp`.
- [UID:0000XD] `by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md`: `80/85` -> `86/89`; owner/emitter remain [UID:0000KI] `JsonCpp`.

Route decisions:

- All four targets remain routed to [UID:0000KI] `JsonCpp` under `third_party/jsoncpp/`.
- No target was reassigned to NexusTK product modules. These are statically embedded third-party JsonCpp internals used by product code, not product-owned cash-shop/fitting-room/downloader/parser wrappers.
- Final C++ remains blank for all four pages. The honest reconstruction route is the vendored JsonCpp source snapshot; emitting partial hand-rewritten method bodies would overstate source-quality ownership and names.
- Version wording is capped: local source and docs support official JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802` as the best current source candidate between release tags, while `version.h` still reports `1.7.4`; no exact release-tag claim was made.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0000X7] live IDA reconfirmed `sub_431D50` size `0x1cc`, exclusive end `0x00431f1c`, direct caller `sub_4426E0+0x2c` at `0x0044270c`, sole `Extra non-whitespace after JSON value.` xref from `0x00431e25`, value-parser call to `0x00432f10`, token-skip call to `0x00435040`, `failIfExtra` trailing-token check without the later strict-root term, independent strict-root array/object validation, and `0xcc` successor padding.
- [UID:0001ZS] live IDA reconfirmed the modeled function starts from `sub_434890` at `0x00434890` through `sub_436010` at `0x00436010`, the raw no-function `BuiltStyledStreamWriter::hasCommentForValue` body at `0x00436180-0x004361ae`, no function at `0x004361ae`, and successor `sub_4361B0` at `0x004361b0`.
- [UID:0000XC] live IDA reconfirmed `sub_4417E0` size `0x544`, direct caller `sub_42D7F0+0x7c` at `0x0042d86c`, reader setting-string xrefs beginning at `0x0060e75c`, and decompiled set clear/insert behavior for `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, and `allowSpecialFloats`.
- [UID:0000XD] live IDA reconfirmed `sub_441D30` size `0x354`, direct caller `sub_42EE10+0x7c` at `0x0042ee8c`, writer setting-string xrefs beginning at `0x0060ef98`, and decompiled set clear/insert behavior for `indentation`, `commentStyle`, `enableYAMLCompatibility`, `dropNullPlaceholders`, `useSpecialFloats`, and `precision`.
- Local source evidence used only staged third-party source/docs: `source-3/third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp`, `source-3/third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp`, `source-3/third_party_embeds/jsoncpp/include/json/version.h`, [UID:0000KI] `by-file/JsonCpp.md`, and [UID:0001QX] `by-meta/obtained_thirdparty_files/README.md`. No Wave2/Wave3 source data was used.

Validation:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00431d50-0x00431f1c.JsonCppOurReaderParse.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0000X7` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0001ZS` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x004417e0-0x00441d24.JsonCppValidReaderKeys.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0000XC` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x00441d30-0x00442084.JsonCppValidWriterKeys.md --apply --queue-timeout 180` -> `ok: 1`; completion/confidence applied; `0000XD` removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and route preservation, but no source-quality final IDA renames or type changes were necessary. Current IDA `sub_` names remain acceptable for these docs.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Residual caps: exact upstream release tag is not proven; [UID:0001ZS] still includes one raw no-function helper body and some best-fit per-helper names; final C++ blocks remain intentionally blank in favor of vendored JsonCpp source.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000X7], [UID:0001ZS], [UID:0000XC], and [UID:0000XD] replacement rows and deleted the stale overlapping [UID:0000VN] ignored aggregate row for `0x004417e0-0x00442084` on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 JsonCpp reader/writer supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-runtime-cleanup-memory-20260615-9 completion report

Assignment: Goal 2 compiler/runtime cleanup low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 12:21.

Targets changed and validated:

- [UID:0000YJ] `by-memory/0x004616c8-0x004616de.AboveFrameAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0000YM] `by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md`: `80/85` -> `85/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:000219] `by-memory/0x00471110-0x00471141.CrtWideVsnprintfWrapper.md`: `80/85` -> `86/91`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0000ZV] `by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md`: `80/85` -> `85/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- [UID:0000YJ] remains non-owned/non-emitting because it is a compiler-generated AboveFrame destructor adjustor thunk pair. Source-facing ownership stays on the AboveFrame class/vtable/inheritance documentation, not on handwritten thunk functions.
- [UID:0000YM] remains non-owned/non-emitting because it is an EH/unwind cleanup chunk associated with IntAlphaSurface view initialization and lifetime cleanup, not a standalone source method.
- [UID:000219] remains non-owned/non-emitting because it is CRT/runtime wide-format varargs glue around `___stdio_common_vsnwprintf_s`, not NexusTK product logic.
- [UID:0000ZV] remains non-owned/non-emitting because it is MSVC constructor partial-cleanup for ChangeMan, not a handwritten ChangeMan method.
- Final C++ remains blank for all four pages. The correct source route is normal class declarations/lifetime code plus CRT/toolchain generation, not explicit source for thunks, EH cleanup, or CRT wrappers.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0000YJ] live IDA reconfirmed two 11-byte modeled functions at `0x004616c8` and `0x004616d3`, no function at `0x004616de`, scalar deleting destructor `sub_4616E0` at `0x004616e0`, exact two-instruction thunk bodies (`sub ecx, 0A0h`/`sub ecx, 0A4h`; jump to `sub_4616E0`), vtable xrefs from `0x00610f28` and `0x00610f58`, and `0xcc` padding at `0x004616de-0x004616e0`.
- [UID:0000YM] live IDA reconfirmed cleanup chunk bytes at `0x00462230-0x00462258`, sole EH jump xref from `0x005fa593`, vtable store to `0x006112ec` at `0x00462237`, ownership byte `+0x24`, pixel pointer `+0x14`, free call, cleared pixel pointer, return, eight `0xcc` bytes through `0x00462260`, and no standalone source-method route.
- [UID:000219] live IDA reconfirmed `sub_471110` size `0x31`, successor `sub_471150` at `0x00471150`, two callers from `sub_470A00+0xa1` and `sub_4A6430+0x25`, callees `sub_41B9A0` and `___stdio_common_vsnwprintf_s`, decompiled wide varargs signature, `va_start`, stdio-option forwarding, and negative-result normalization to `-1`.
- [UID:0000ZV] live IDA reconfirmed no function at `0x0047ed20`, no ordinary xrefs to the cleanup start, successor `sub_47ED50` at `0x0047ed50`, ChangeMan vtable store at `0x0047ed26`, sorted-list member cleanup, singleton clear at `0x0047ed3f`, tail jump to `0x004f4a90`, and one `0xcc` padding byte at `0x0047ed4f`.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x004616c8-0x004616de.AboveFrameAdjustorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0000YJ` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0000YM` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00471110-0x00471141.CrtWideVsnprintfWrapper.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `000219` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0000ZV` removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and route preservation only; no source-quality IDA rename/type changes were needed for compiler-generated or CRT/runtime glue.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Residual caps: these pages intentionally stop below final-audit scoring because related class/source declarations and broader vtable/lifetime provenance live in supporting docs, and none of the four ranges should emit handwritten C++.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

Supervisor applied the exact [UID:0000YJ], [UID:0000YM], [UID:000219], and [UID:0000ZV] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 runtime cleanup supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-dialog-runtime-thunks-memory-20260615-10 completion report

Assignment: Goal 2 dialog/runtime thunk low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 12:32.

Targets changed and validated:

- [UID:000134] `by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:00013B] `by-memory/0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:000229] `by-memory/0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md`: `80/85` -> `85/88`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:00015K] `by-memory/0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- [UID:000134] remains non-owned/non-emitting because it is a compiler-generated DialogInSession/DialogSession destructor adjustor thunk group. Source-facing ownership stays on the class hierarchy, destructors, and vtable layout.
- [UID:00013B] remains non-owned/non-emitting because it is a compiler-generated employee-dialog destructor adjustor thunk group. Source-facing ownership stays on AddEmployeeItemDialog, EmployeeDialogPane, EmployeeItemPropertyDialogPane, and their vtable layout.
- [UID:000229] remains non-owned/non-emitting because it is MSVC integer runtime/helper glue, not NexusTK product source.
- [UID:00015K] remains non-owned/non-emitting because it is a compiler-generated FpsPane destructor adjustor thunk pair. Source-facing ownership stays on FpsPane inheritance/destructor/vtable layout.
- Final C++ remains blank for all four pages. The correct source route is normal class declarations/lifetime code plus CRT/toolchain generation, not explicit source for thunks or runtime helper stubs.

IDA/local evidence used:

- Live IDA MCP session for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:000134] live IDA reconfirmed four 11-byte functions at `0x004a146f`, `0x004a147a`, `0x004a1485`, and `0x004a1490`, no function at `0x004a149b`, successor destructors at `0x004a14a0` and `0x004a1500`, vtable refs at `0x00618e18`, `0x00618e48`, `0x00618d7c`, and `0x00618dac`, jump refs into the destructors, primary destructor slots at `0x00618db8` and `0x00618d30`, and five `0xcc` padding bytes before `0x004a14a0`.
- [UID:00013B] live IDA reconfirmed six 11-byte functions at `0x004a4cb1`, `0x004a4cbc`, `0x004a4cc7`, `0x004a4cd2`, `0x004a4cdd`, and `0x004a4ce8`, no function at `0x004a4cf3`, successor destructor/helper starts at `0x004a4d00`, `0x004a4d40`, and `0x004a4e30`, vtable refs for AddEmployeeItemDialog, EmployeeDialogPane, and EmployeeItemPropertyDialogPane, jump refs into the three scalar deleting destructors, and thirteen `0xcc` padding bytes before `0x004a4d00`.
- [UID:000229] live IDA reconfirmed no function at `0x004a60a0`, modeled Microsoft Visual C runtime helper `unknown_libname_12` at `0x004a60c0-0x004a60cb`, no function at `0x004a60cb`, successor `sub_4A60D0` at `0x004a60d0`, no direct xrefs to either helper start, one `0xcc` byte before the helper pair, five `0xcc` bytes after it, and `HIDWORD(a1) | a1` behavior for the modeled helper.
- [UID:00015K] live IDA reconfirmed two 11-byte functions at `0x004b6c2b` and `0x004b6c36`, no function at `0x004b6c41`, scalar deleting destructor `sub_4B6C50` at `0x004b6c50`, vtable refs at `0x0061a66c` and `0x0061a69c`, primary destructor slot at `0x0061a620`, jump refs into the destructor, and fifteen `0xcc` padding bytes before `0x004b6c50`.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `000134` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x004a4cb1-0x004a4cf3.EmployeeDialogAdjustorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `00013B` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x004a60a0-0x004a60cb.MsvcInt64RuntimeHelpers.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `000229` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x004b6c2b-0x004b6c41.FpsPaneAdjustorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `00015K` removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and route preservation only; no source-quality IDA rename/type changes were needed for compiler-generated thunks or CRT/runtime glue.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Residual caps: [UID:000229] remains capped at `85/88` because the raw `0x004a60a0-0x004a60c0` helper body is unmodeled and has no direct xrefs; all four ranges intentionally remain non-reconstructable with blank final C++.

Supervisor applied the exact [UID:000134], [UID:00013B], [UID:000229], and [UID:00015K] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 dialog/runtime thunk supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-objectpane-message-thunks-memory-20260615-11 completion report

Assignment: Goal 2 object-pane/message thunk low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 12:45.

Targets changed and validated:

- [UID:0001B3] `by-memory/0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:000235] `by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md`: `80/85` -> `86/88`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001BW] `by-memory/0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001BY] `by-memory/0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- [UID:0001B3] remains non-owned/non-emitting because it is a strip of compiler-generated constructor-failure EH pool-free wrappers. Source-facing ownership stays with the object-pane constructors and pool allocation/delete policy.
- [UID:000235] remains non-owned/non-emitting because it is MSVC STL/container support for MapPane path-scanning deque/queue logic. Source-facing ownership stays with MapPane pathfinding logic, not the low-level helper bodies.
- [UID:0001BW] remains non-owned/non-emitting because it is shared compiler-generated dialog destructor adjustor glue referenced by many vtables.
- [UID:0001BY] remains non-owned/non-emitting because it is compiler-generated destructor adjustor glue shared by item/spell menu-list classes.
- Final C++ remains blank for all four pages. The correct source route is normal class/container usage and compiler/toolchain output, not handwritten NexusTK source for these helper/thunk bodies.

IDA/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` reported Hex-Rays and strings ready.
- [UID:0001B3] live IDA reconfirmed nine `0x3e` functions from `0x00514ae0` through `0x00514ce0`, half-open non-start boundaries ending at `0x00514d1e`, successor thunk `sub_514D1E`, EH/code xrefs from object construction paths, sole callee `0x004b14c0` for every wrapper, pool-address loads for all nine object-pane pools, and `0xcc` alignment before/between the wrappers.
- [UID:000235] live IDA reconfirmed `sub_514F70` size `0x190`, no function at `0x00515100`, `sub_515110` size `0x99`, no function at `0x005151a9`, successor `sub_5151B0`, caller fan-in from MapPane path-scan functions `0x0050c790` and `0x0050d010`, deque growth/append behavior, allocator/memmove/memset/free/invalid-parameter callees, and padding before, between, and after the helpers.
- [UID:0001BW] live IDA reconfirmed adjacent `0xb` thunks at `0x00520aa5` and `0x00520ab0`, `this` deltas `-0xa0` and `-0xa4`, jump target `0x00520b70`, broad vtable-only refs across `0x0061ec70-0x0061f4b8` and `0x00622488-0x006229e8`, and successor thunk start `0x00520abb`.
- [UID:0001BY] live IDA reconfirmed adjacent `0xb` thunks at `0x00520ad1` and `0x00520adc`, `this` deltas `-0xa0` and `-0xa4`, jump target `0x00520c20`, secondary/tertiary vtable refs at `0x0061f12c`, `0x0061f15c`, `0x0061f28c`, `0x0061f2bc`, `0x0061f3ec`, and `0x0061f41c`, primary scalar-destructor vtable refs at `0x0061f0a4`, `0x0061f204`, and `0x0061f364`, and successor thunk start `0x00520ae7`.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x00514ae0-0x00514d1e.ObjectPanePoolFreeUnwindWrappers.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0001B3` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00514f70-0x005151a9.MapPathDequeSupport.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `000235` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00520aa5-0x00520abb.SharedDialogDefaultDestructorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0001BW` removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00520ad1-0x00520ae7.SharedClientSpellMenuListDestructorThunks.md --apply --queue-timeout 240` from `source-3/project-documentation` -> `ok: 1`; completion/confidence applied; `0001BY` removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and route preservation only; no source-quality IDA rename/type changes were needed for compiler-generated EH cleanup, runtime/container support, or destructor adjustor thunks.

Remaining blockers:

- No 85/85 target blockers remain. All four assigned targets now honestly clear the assignment gate.
- Residual caps: [UID:000235] remains below `90` confidence because the exact original source-level container spelling is still inferred from STL-like codegen rather than a recovered source declaration; all four ranges intentionally remain non-reconstructable with blank final C++.

Supervisor applied the exact [UID:0001B3], [UID:000235], [UID:0001BW], and [UID:0001BY] replacement rows on 2026-06-15. Validation command: `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 Goal 2 ObjectPane/message thunk supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-parcel-patch-power-thunks-memory-20260615-12 supervisor-applied shared-report rows

Assignment: Goal 2 parcel/patch/power thunk low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 12:54.

Targets changed:

- [UID:0001EM] `by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001EU] `by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md`: corrected from stale path/range `0x005484db-0x005484f0`, `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001F0] `by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md`: corrected from stale path/range `0x0054934b-0x00549360`, `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001F8] `by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- All four target ranges remain non-owned/non-emitting because they are compiler-generated destructor adjustor thunk strips. Source-facing ownership stays on the class declarations, destructor bodies, and vtable layout; final C++ remains blank.
- Support link-only repairs were applied to `PatchPane`, `PatchPane2`, `PatchPaneAndPatchPane2`, `PatchPaneVtableFamily`, `ClearPatchPane2Singleton`, and exact PatchPane/PatchPane2 vtable data pages so they no longer point at stale [UID:0001EU]/[UID:0001F0] paths.

IDA/local evidence used:

- Live IDA MCP evidence from the active A003 session confirmed the exact function starts, xrefs, and byte boundaries.
- [UID:0001EM] has six `0xb` functions at `0x00546e8b`, `0x00546e96`, `0x00546ea1`, `0x00546eac`, `0x00546eb7`, and `0x00546ec2`; no function at `0x00546ecd`; vtable refs at `0x00621d18`, `0x00621d48`, `0x00621c00`, `0x00621c30`, `0x00621c90`, and `0x00621cc0`; jumps to `0x00546ed0`, `0x00546f40`, and `0x00547000`.
- [UID:0001EU] has two `0xb` functions at `0x005484db` and `0x005484e6`; `0x005484f0` is inside the second thunk, `0x005484f1` is not a function start, and padding begins at `0x005484f1`; vtable refs are `0x00621e2c` and `0x00621e5c`, and both thunks jump to `0x00548560`.
- [UID:0001F0] has two `0xb` functions at `0x0054934b` and `0x00549356`; `0x00549360` is inside the second thunk, `0x00549361` is not a function start, and padding begins at `0x00549361`; vtable refs are `0x00621fa0` and `0x00621fd0`, and both thunks jump to `0x00549370`.
- [UID:0001F8] has four `0xb` functions at `0x0054b4f0`, `0x0054b4fb`, `0x0054b506`, and `0x0054b511`; no function at `0x0054b51c`; vtable refs at `0x006221b8`, `0x006221e8`, `0x0062227c`, and `0x006222ac`; jumps to `0x0054b520` and `0x0054b580`.

IDA DB changes:

- Skipped. The documentation evidence supports score increases and endpoint repairs only; no source-quality IDA rename/type changes were needed for compiler-generated adjustor thunks.

Supervisor-applied `by-memory/-coverage-report.md` replacements:

Supervisor applied and validated these replacement rows in the shared coverage report on 2026-06-15 (`ok: 1`). They are retained below for audit only and are no longer pending.

- Placement context: replace the existing [UID:0001EM] row currently under the parcel notification panes block.
  - [UID:0001EM][0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks](by-memory/0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md) 0x00546e8b-0x00546ecd | compiler thunk | ParcelNotificationAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms six `0xb` parcel notification destructor adjustor thunks, `this` deltas `-0xa0`/`-0xa4`, secondary/tertiary vtable refs at `0x00621d18`, `0x00621d48`, `0x00621c00`, `0x00621c30`, `0x00621c90`, and `0x00621cc0`, jumps to scalar deleting destructors `sub_546ED0`, `sub_546F40`, and `sub_547000`, primary destructor slots `0x00621ccc`, `0x00621bb4`, and `0x00621c3c`, and padding before `0x00546ed0`; source should define parcel pane inheritance/destructors and let the compiler emit thunks.
- Placement context: replace the existing [UID:0001EU] row and immediately following stale padding row before [UID:0003OC].
  - [UID:0001EU][0x005484db-0x005484f1.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md) 0x005484db-0x005484f1 | compiler thunk | PatchPaneAdjustorThunks : ignored : 86% : strong : Live IDA corrects the half-open endpoint from `0x005484f0` to `0x005484f1` and reconfirms two `0xb` PatchPane destructor adjustor thunks, `this` deltas `-0xa0`/`-0xa4`, vtable refs at `0x00621e2c` and `0x00621e5c`, jumps to `sub_548560`, primary destructor slot `0x00621dcc`, and padding beginning at `0x005484f1`; source should define PatchPane inheritance/destructor layout and let the compiler emit thunks.
  - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x005484f1-0x00548500 | padding | PatchPane adjustor thunks to PatchFileData scalar deleting destructor alignment : ignored : 100% : strong : Live IDA corrects the padding start from stale `0x005484f0` to `0x005484f1`; bytes at `0x005484f1-0x00548500` are `0xcc` before [UID:0003OC][0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor](by-memory/0x00548500-0x00548555.PatchFileDataScalarDeletingDestructor.md).
- Placement context: replace the existing [UID:0001F0] row and insert the padding row immediately after it, before existing `0x0054940f-0x00549410` padding.
  - [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md) 0x0054934b-0x00549361 | compiler thunk | PatchPane2AdjustorThunks : ignored : 86% : strong : Live IDA corrects the half-open endpoint from `0x00549360` to `0x00549361` and reconfirms two `0xb` PatchPane2 destructor adjustor thunks, `this` deltas `-0xa0`/`-0xa4`, vtable refs at `0x00621fa0` and `0x00621fd0`, jumps to `sub_549370`, primary destructor slot `0x00621f40`, and padding beginning at `0x00549361`; source should define PatchPane2 inheritance/destructor layout and let the compiler emit thunks.
  - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x00549361-0x00549370 | padding | PatchPane2 adjustor thunks to PatchPane2 scalar deleting destructor alignment : ignored : 100% : strong : Live IDA bytes show `0xcc` padding after corrected `0x0054934b-0x00549361` thunk range and before `sub_549370` at `0x00549370`.
- Placement context: replace the existing [UID:0001F8] row in the PowerDialogPane block.
  - [UID:0001F8][0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks](by-memory/0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md) 0x0054b4f0-0x0054b51c | compiler thunk | PowerDialogPaneAndPowerListPaneAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms four `0xb` PowerDialogPane/PowerListPane destructor adjustor thunks, `this` deltas `-0xa0`/`-0xa4`, vtable refs at `0x006221b8`, `0x006221e8`, `0x0062227c`, and `0x006222ac`, jumps to `sub_54B520` and `sub_54B580`, primary destructor slots `0x00622158` and `0x006221f4`, and padding before `0x0054b520`; source should define power dialog/list inheritance/destructors and let the compiler emit thunks.

Supervisor-applied `by-memory/-ignored.md` cleanup:

Supervisor applied and validated this ignored-ledger cleanup on 2026-06-15 (`ok: 1`).

- Replace the old `0x005484db-0x005484f0` PatchPane adjustor-thunk entry with `0x005484db-0x005484f1`, and replace its link with [UID:0001EU][0x005484db-0x005484f1.PatchPaneAdjustorThunks](by-memory/0x005484db-0x005484f1.PatchPaneAdjustorThunks.md).
- Replace old padding `0x005484f0-0x00548500` with `0x005484f1-0x00548500`.
- Replace the old `0x0054934b-0x00549360` PatchPane2 adjustor-thunk entry with `0x0054934b-0x00549361`, and replace its link with [UID:0001F0][0x0054934b-0x00549361.PatchPane2AdjustorThunks](by-memory/0x0054934b-0x00549361.PatchPane2AdjustorThunks.md).
- Add or adjust padding `0x00549361-0x00549370` if the ignored ledger wants explicit coverage of that alignment gap.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x00546e8b-0x00546ecd.ParcelNotificationAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001EM] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x005484db-0x005484f1.PatchPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; path updated from stale `0x005484db-0x005484f0`, completion/confidence applied; [UID:0001EU] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x0054934b-0x00549361.PatchPane2AdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; path updated from stale `0x0054934b-0x00549360`, completion/confidence applied; [UID:0001F0] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x0054b4f0-0x0054b51c.PowerDialogPaneAndPowerListPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001F8] removed from Low_Completion/Low_Both/by-memory stats rows.
- Link-only support validations all returned `ok: 1`: `by-memory\0x005470b0-0x0054940f.PatchPaneAndPatchPane2.md`, `by-type\by-vtable\PatchPaneVtableFamily.md`, `by-file\PatchPane.md`, `by-class\PatchPane.md`, `by-class\PatchPane2.md`, `by-memory\0x00549340-0x0054934b.ClearPatchPane2Singleton.md`, `by-memory\0x00621db8-0x00621e64.PatchPaneVtableData.md`, and `by-memory\0x00621f40-0x00621fd8.PatchPane2VtableData.md`.
- Validator side effect: the file-mode validations for the renamed target pages auto-updated UID link paths in `by-memory/-coverage-report.md` and `by-memory/-ignored.md`. A003 did not manually edit those shared ledgers; supervisor has now applied and validated the exact score/evidence and padding-range replacements.

Remaining blockers:

- No assigned target remains below `85/85`.
- Residual shared-ledger blockers: none for this batch after supervisor application and validation.

## 2026-06-15 - A003-goal2-input-spell-thunks-memory-20260615-13 supervisor-applied rows

Assignment: Goal 2 input/spell thunk low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 13:15.

Targets changed and validated:

- [UID:0001N8] `by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001N9] `by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001NA] `by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001NB] `by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md`: `80/85` -> `86/90`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- All four target ranges remain non-owned/non-emitting because they are compiler-generated destructor adjustor thunks. Source-facing ownership stays on the input-pane class declarations, destructor bodies, and vtable layout; final C++ remains blank.

IDA/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `ok` with Hex-Rays and strings ready.
- [UID:0001N8] live IDA reconfirmed two `0xb` functions at `0x005b7862` and `0x005b786d`, successor function `0x005b7878`, `sub ecx, 0A0h`/`sub ecx, 0A4h` then jump to `sub_5B7BC0`, and vtable-only refs at `0x0062f378` and `0x0062f3a8`.
- [UID:0001N9] live IDA reconfirmed twelve `0xb` functions from `0x005b7878` through `0x005b78f1`, successor function `0x005b78fc`, paired `sub ecx, 0A0h`/`sub ecx, 0A4h` tail jumps to scalar deleting destructors `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, and `0x005b8030`, and one vtable data ref for each start at `0x0062f490`, `0x0062f4c0`, `0x0062f634`, `0x0062f664`, `0x0062f6c0`, `0x0062f6f0`, `0x0062f1d4`, `0x0062f204`, `0x0062f51c`, `0x0062f54c`, `0x0062f5a8`, and `0x0062f5d8`.
- [UID:0001NA] live IDA reconfirmed two `0xb` functions at `0x005b78fc` and `0x005b7907`, successor function `0x005b7912`, `sub ecx, 0A0h`/`sub ecx, 0A4h` then jump to `sub_5B8100`, and vtable-only refs at `0x0062f260` and `0x0062f290`.
- [UID:0001NB] live IDA reconfirmed two `0xb` functions at `0x005b7912` and `0x005b791d`, successor function `0x005b7928`, `sub ecx, 0A0h`/`sub ecx, 0A4h` then jump to `sub_5B81D0`, and vtable-only refs at `0x0062f404` and `0x0062f434`.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001N8] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001N9] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001NA] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001NB] removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The evidence supports documentation score increases and route preservation only; no source-quality IDA rename/type changes were needed for compiler-generated adjustor thunks.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows:

- Placement context: replace the four existing consecutive [UID:0001N8], [UID:0001N9], [UID:0001NA], and [UID:0001NB] rows after [UID:0001N7] `QuitInputPaneDestructorThunks` and before [UID:0002S4] `ItemWhoInputPaneScalarDeletingDestructor`.
  - [UID:0001N8][0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7862-0x005b7878.SelectObjectWithKeyboardPaneAdjustorThunks.md) 0x005b7862-0x005b7878 | compiler thunk | SelectObjectWithKeyboardPaneAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms two `0xb` `SelectObjectWithKeyboardPane` destructor adjustor thunks, exact half-open endpoint before successor `0x005b7878`, `this` deltas `-0xa0`/`-0xa4`, jumps to `sub_5B7BC0`, vtable-only refs at `0x0062f378` and `0x0062f3a8`, and no source-style call sites; source should define the class/destructor layout and let the compiler emit thunks.
  - [UID:0001N9][0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks](by-memory/0x005b7878-0x005b78fc.SpellInputPaneAdjustorThunks.md) 0x005b7878-0x005b78fc | compiler thunk | SpellInputPaneAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms twelve `0xb` spell argument input-pane destructor adjustor thunks, exact half-open endpoint before successor `0x005b78fc`, paired `this` deltas `-0xa0`/`-0xa4`, jumps to scalar deleting destructors `0x005b7c20`, `0x005b7cf0`, `0x005b7dc0`, `0x005b7e90`, `0x005b7f60`, and `0x005b8030`, and one vtable-only data ref for each thunk start; source should define the six spell input pane destructor layouts and let the compiler emit thunks.
  - [UID:0001NA][0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks](by-memory/0x005b78fc-0x005b7912.SpellWhoInputPaneAdjustorThunks.md) 0x005b78fc-0x005b7912 | compiler thunk | SpellWhoInputPaneAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms two `0xb` `SpellWhoInputPane` destructor adjustor thunks, exact half-open endpoint before successor `0x005b7912`, `this` deltas `-0xa0`/`-0xa4`, jumps to `sub_5B8100`, vtable-only refs at `0x0062f260` and `0x0062f290`, and no source-style call sites; source should define the class/destructor layout and let the compiler emit thunks.
  - [UID:0001NB][0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks](by-memory/0x005b7912-0x005b7928.TargetObjectWithKeyboardPaneAdjustorThunks.md) 0x005b7912-0x005b7928 | compiler thunk | TargetObjectWithKeyboardPaneAdjustorThunks : ignored : 86% : strong : Live IDA reconfirms two `0xb` `TargetObjectWithKeyboardPane` destructor adjustor thunks, exact half-open endpoint before successor `0x005b7928`, `this` deltas `-0xa0`/`-0xa4`, jumps to `sub_5B81D0`, vtable-only refs at `0x0062f404` and `0x0062f434`, and no source-style call sites; source should define the class/destructor layout and let the compiler emit thunks.

Remaining blockers:

- No assigned target remains below `85/85`.
- Shared-ledger status: supervisor applied the four replacement rows above on 2026-06-15 and validated `by-memory/-coverage-report.md` with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 input/spell thunk supervisor-owned rows remain pending.

## 2026-06-15 - A003-goal2-static-cleanup-thunks-memory-20260615-14

Assignment: Goal 2 static cleanup thunk low-score batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 13:25.

Targets changed and validated:

- [UID:0001O6] `by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md`: `80/85` -> `86/91`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001O8] `by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md`: `80/85` -> `86/91`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001O9] `by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md`: `80/85` -> `86/91`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.
- [UID:0001OA] `by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md`: `80/85` -> `86/91`; owner/emitter remain `NONE`/blank; `RECONSTRUCTABLE:FALSE`.

Route decisions:

- All four target ranges remain non-owned/non-emitting because they are compiler/static-lifetime cleanup wrappers registered by startup code. Source-facing ownership stays on the underlying static objects and startup/constructor policy; final C++ remains blank.

IDA/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `ok` with Hex-Rays and strings ready.
- [UID:0001O6] live IDA reconfirmed `sub_60C0F0` as a 0x10-byte function ending at successor `sub_60C100`, one `_atexit` registration/data ref at `0x00419ee8`, body `mov off_66D42C, offset ??_7AutoInit@?A0xbc51848c@@6B@; jmp ds:OleUninitialize`, sole direct static-slot xref to `0x0066d42c`, and vtable refs through AutoInit destructor/scalar destructor/static slot.
- [UID:0001O8] live IDA reconfirmed eighteen 0x0a wrapper functions from `0x0060c320` through `0x0060c430`, no functions at the intermediate `+0x0a` endpoints, successor padding at `0x0060c43a-0x0060c440`, bodies `mov ecx,<pool>; jmp sub_4B1520`, one paired `_atexit` registration ref from `0x0041a040-0x0041a27d` for each wrapper, and backing pool xrefs through constructor/allocation/free/cleanup users.
- [UID:0001O9] live IDA reconfirmed `sub_60C440` as a 0x0b wrapper before padding, sole `_atexit` registration/data ref at `0x0041a48d` inside the `0x0041a280` initializer, body `mov off_6702C4, offset ??_7UniAPIInit@@6B@; retn`, sole direct static-slot xref to `0x006702c4`, and vtable refs through UniAPIInit bodies/static slot.
- [UID:0001OA] live IDA reconfirmed `sub_60C450` as a 0x0a wrapper after padding with successor `sub_60C45A`, body `mov ecx, offset unk_69BF34; jmp sub_4B1520`, sole `_atexit` registration/data ref at `0x0041a4c1`, and UserPane pool refs from constructor, allocation, unwind/free, scalar destructor, and cleanup.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001O6] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001O8] removed from Low_Completion/Low_Both/by-memory stats rows; validator added reference-index entry for `by-global/PoolAllocatorStaticInstances.md`.
- `python .\tools\validator.py --mode file --file by-memory\0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001O9] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0001OA] removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The evidence supports documentation score increases and route preservation only; no source-quality IDA rename/type changes were needed for compiler/static cleanup wrappers.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace the existing [UID:0001O6] row after [UID:00024E] `StaticCleanupThunksBeforeAutoInit` and before [UID:00024F] `StaticStringContainerCleanupThunks`.
  - [UID:0001O6][0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk](by-memory/0x0060c0f0-0x0060c100.AutoInitStaticShutdownThunk.md) 0x0060c0f0-0x0060c100 | compiler-generated static cleanup | AutoInitStaticShutdownThunk : ignored : 86% : strong : Live IDA reconfirms `sub_60C0F0` as a 0x10-byte static shutdown thunk with exact successor `0x0060c100`, one `_atexit` registration ref at `0x00419ee8`, body `off_66D42C = AutoInit vftable; jmp OleUninitialize`, sole direct static-slot xref to `0x0066d42c`, and vtable refs from the AutoInit destructor/scalar destructor/static slot; source should express the AutoInit/OLE static lifetime policy and let the compiler emit cleanup glue.
- Placement context: replace the existing [UID:0001O8] row after [UID:00024G] `StaticDestructorWrappersBeforePoolAllocators` and before [UID:00024H] `AlignmentPaddingBeforeUniAPIInitCleanup`.
  - [UID:0001O8][0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers](by-memory/0x0060c320-0x0060c43a.PoolAllocatorStaticDestructorWrappers.md) 0x0060c320-0x0060c43a | compiler-generated static cleanup | PoolAllocatorStaticDestructorWrappers : ignored : 86% : strong : Live IDA reconfirms eighteen 0x0a PoolAllocator static destructor wrappers, intermediate padding/non-function endpoints, successor boundary before `0x0060c43a-0x0060c440` padding and `sub_60C440`, bodies `mov ecx,<pool>; jmp sub_4B1520`, one paired `_atexit` registration ref from `0x0041a040-0x0041a27d` for each wrapper, and backing pool xrefs through constructor/allocation/free/cleanup users; source should declare concrete pools and let compiler emit cleanup wrappers.
- Placement context: replace the existing [UID:0001O9] row after [UID:00024H] `AlignmentPaddingBeforeUniAPIInitCleanup` and before [UID:00024I] `AlignmentPaddingBeforeUserPanePoolCleanup`.
  - [UID:0001O9][0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper](by-memory/0x0060c440-0x0060c44b.UniAPIInitStaticCleanupWrapper.md) 0x0060c440-0x0060c44b | compiler-generated static cleanup | UniAPIInitStaticCleanupWrapper : ignored : 86% : strong : Live IDA reconfirms `sub_60C440` as 0x0b wrapper between padding rows, sole `_atexit` registration ref at `0x0041a48d` inside `WideApiDispatchInit`, body `off_6702C4 = UniAPIInit vftable; retn`, sole direct static-slot xref to `0x006702c4`, and vtable refs from UniAPIInit bodies/static slot; source should retain UniAPIInit static lifetime and let compiler emit cleanup wrapper.
- Placement context: replace the existing [UID:0001OA] row after [UID:00024I] `AlignmentPaddingBeforeUserPanePoolCleanup` and before [UID:00024J] `StaticRuntimeCleanupWrappersAfterUserPanePool`.
  - [UID:0001OA][0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper](by-memory/0x0060c450-0x0060c45a.UserPanePoolStaticDestructorWrapper.md) 0x0060c450-0x0060c45a | compiler-generated static cleanup | UserPanePoolStaticDestructorWrapper : ignored : 86% : strong : Live IDA reconfirms `sub_60C450` as 0x0a wrapper after padding, exact successor `0x0060c45a`, body `mov ecx,0x0069bf34; jmp sub_4B1520`, sole `_atexit` registration ref at `0x0041a4c1`, and UserPane pool refs from constructor, allocation, unwind/free, scalar destructor, and cleanup; source should declare the UserPane static pool and let compiler emit cleanup wrapper.

Remaining blockers:

- No assigned target remains below `85/85`.
- Shared-ledger status: supervisor applied the four replacement rows above on 2026-06-15 and validated `by-memory/-coverage-report.md` with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 static-cleanup thunk supervisor-owned rows remain pending.

## 2026-06-15 - A003-goal2-launcher-parser-tail-memory-20260615-15

Assignment: Goal 2 launcher/parser tail low-completion batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 13:36.

Targets changed and validated:

- [UID:0002BO] `by-memory/0x004910d0-0x00491445.BixelLauncherParser.md`: `80/86` -> `85/88`; owner/emitter remain `0000N4`/`0000N4`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002BP] `by-memory/0x00491450-0x0049178d.KwgLauncherParser.md`: `80/86` -> `85/88`; owner/emitter remain `0000N4`/`0000N4`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002BQ] `by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md`: `80/86` -> `85/88`; owner/emitter remain `0000N4`/`0000N4`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002BR] `by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md`: `80/86` -> `86/90`; owner/emitter remain `0000N4`/`0000N4`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.

Route decisions:

- All four target ranges remain source-authored RegistryConfig launcher/parser helpers routed to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md). The direct parent/file route already clears the corrected gate, and the aggregate [UID:000220][0x0048f400-0x00491b28.RegistryCommandLineParsers](by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md) remains the parser-island evidence page.
- Final C++ remains blank for all four despite clearing the numeric minimum on some pages because the dispatch caller, final source-facing helper names, helper-call names, and startup-state field names are not source-quality enough.

IDA/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `ok`, imagebase `0x400000`, Hex-Rays and strings ready.
- [UID:0002BO] live IDA reconfirmed `0x004910d0`, `0x00491445`, `0x00491446`, and `0x00491450` are not modeled function starts; `0x004910c0-0x004910d0` is sixteen `0xcc` bytes, `0x00491445-0x00491450` is eleven `0xcc` bytes, `xrefs_to 0x004910d0` is empty, raw pointer pattern `d0 10 49 00` has no matches, raw disassembly shows the real stack-frame command-line parser prologue, and literal refs are `/Bixel` from `0x004911a5`, generic failure text from `0x00491394`, and host-specific failure text from `0x004913f3`.
- [UID:0002BP] live IDA reconfirmed `0x00491450`, `0x0049178d`, `0x0049178e`, and `0x00491790` are not modeled function starts; `0x00491445-0x00491450` is eleven `0xcc` bytes, `0x0049178d-0x00491790` is three `0xcc` bytes, `xrefs_to 0x00491450` is empty, raw pointer pattern `50 14 49 00` has no matches, raw disassembly shows the real stack-frame command-line parser prologue, and literal refs are `/KWG` from `0x00491525`, `game.kornetworld.com` from `0x00491540`, generic KornetWorld failure text from `0x004916e1`, and host-specific failure text from `0x00491735`.
- [UID:0002BQ] live IDA reconfirmed `0x00491790`, `0x004918dc`, and `0x004918dd` are not modeled function starts; successor [UID:0002BR] is `sub_4918E0`; `0x0049178d-0x00491790` is three `0xcc` bytes, `0x004918dc-0x004918e0` is four `0xcc` bytes, `xrefs_to 0x00491790` is empty, raw pointer pattern `90 17 49 00` has no matches, raw disassembly shows the real stack-frame command-line parser prologue, and literal refs are `/GameBill` from `0x00491852` and failure text from `0x00491889`.
- [UID:0002BR] live IDA reconfirmed `sub_4918E0` as `0x004918e0-0x00491b28`, predecessor and successor padding at `0x004918dc-0x004918e0` and `0x00491b28-0x00491b30`, zero xrefs to `0x004918e0`, no raw pointer pattern `e0 18 49 00`, full 197-instruction disassembly including cleanup chunk `0x005fcdc2-0x005fcdfd`, decompiled `/host:`/`/portno:`/`/id:` extraction and success writes, the expected callee set, and marker/failure refs at `0x00491947`, `0x004919a8`, `0x00491a14`, and `0x00491abc`.

Validation:

- `python .\tools\validator.py --mode file --file by-memory\0x004910d0-0x00491445.BixelLauncherParser.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002BO] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00491450-0x0049178d.KwgLauncherParser.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002BP] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x00491790-0x004918dc.GameBillLauncherGate.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002BQ] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file by-memory\0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002BR] removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The evidence supports documentation score increases and route preservation only; no source-quality IDA rename/type changes were needed.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace the four existing consecutive child rows after [UID:0002BN] `ComBackedLauncherAuthenticationParser` and before the [UID:0000VN] `0x00491b28-0x00491b30` padding row under [UID:000220] `RegistryCommandLineParsers`.
  - [UID:0002BO][0x004910d0-0x00491445.BixelLauncherParser](by-memory/0x004910d0-0x00491445.BixelLauncherParser.md) 0x004910d0-0x00491445 | function | BixelLauncherParser : reconstructable : 85% : strong : RegistryConfig-routed raw `/Bixel` launcher parser; live IDA reconfirms raw non-function boundary, sixteen-byte predecessor padding and eleven-byte successor padding, real stack-frame command-line/token prologue, zero start xrefs, no raw VA pointer hits, one selector/failure-literal ref each, numeric IPv4/DNS host handling, port/payload writes, and remaining dispatch/name/field blockers.
  - [UID:0002BP][0x00491450-0x0049178d.KwgLauncherParser](by-memory/0x00491450-0x0049178d.KwgLauncherParser.md) 0x00491450-0x0049178d | function | KwgLauncherParser : reconstructable : 85% : strong : RegistryConfig-routed raw `/KWG` launcher parser; live IDA reconfirms raw non-function boundary, eleven-byte predecessor padding and three-byte successor padding, real stack-frame command-line/token prologue, zero start xrefs, no raw VA pointer hits, one selector/fixed-host/failure-literal ref each, fixed `game.kornetworld.com` DNS path, four payload conversions, fixed port `9000`, and remaining dispatch/name/field blockers.
  - [UID:0002BQ][0x00491790-0x004918dc.GameBillLauncherGate](by-memory/0x00491790-0x004918dc.GameBillLauncherGate.md) 0x00491790-0x004918dc | function | GameBillLauncherGate : reconstructable : 85% : strong : RegistryConfig-routed raw `/GameBill` launcher gate; live IDA reconfirms raw non-function boundary, three-byte predecessor padding and four-byte successor padding before modeled `sub_4918E0`, real stack-frame command-line/token prologue, zero start xrefs, no raw VA pointer hits, one selector/failure-literal ref each, ready/state writes only, and remaining dispatch/name/field blockers.
  - [UID:0002BR][0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser](by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md) 0x004918e0-0x00491b28 | function | StructuredHostPortIdLauncherParser : reconstructable : 86% : strong : RegistryConfig-routed structured `/host:`/`/portno:`/`/id:` launcher parser; live IDA reconfirms modeled `sub_4918E0`, predecessor/successor padding, zero start xrefs, no raw VA pointer hits, full 197-instruction disassembly including SEH cleanup chunk `0x005fcdc2-0x005fcdfd`, decompiled marker extraction and state writes to `+0x2915b4`, `+0x2916c4`, `+0x2918f0`, `+0x2916ca`, and `+0x28de28`, expected callee set, one marker/failure-literal ref each, and remaining dispatch/name/field blockers.

Remaining blockers:

- No assigned target remains below `85/85`.
- Shared-ledger status: supervisor applied the four replacement rows above on 2026-06-15 and validated `by-memory/-coverage-report.md` with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 launcher parser tail supervisor-owned rows remain pending.

## 2026-06-15 - A003-goal2-parcel-icon-pane-memory-20260615-16

Assignment: Goal 2 parcel icon pane memory batch from refreshed `project-level/-auto-completion-stats.md` generated 2026-06-15 13:44.

Targets changed and validated:

- [UID:0001EG] `by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md`: `80/86` -> `86/90`; owner/emitter changed `0000MF`/`0000MF` -> `0000A5`/`0000A5`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0001EI] `by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md`: `80/86` -> `86/90`; owner/emitter changed `0000MF`/`0000MF` -> `0000A5`/`0000A5`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002KD] `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`: `80/86` -> `86/90`; owner/emitter remain `0000A6`/`0000A6`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002R6] `by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md`: `80/86` -> `85/88`; owner/emitter remain `000058`/`000058`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.

Route decisions:

- [UID:0001EG] and [UID:0001EI] now attach directly to [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md) because the class page now clears `85/86`; [UID:0000A5] remains under [UID:0000MF][ParcelPane](by-file/ParcelPane.md) for source-file grouping.
- [UID:0002KD] remains attached to [UID:0000A6][ParcelPane](by-class/ParcelPane.md), which clears `86/86`.
- [UID:0002R6] remains attached to [UID:000058][FlyingParcelPane](by-class/FlyingParcelPane.md), which clears `85/86`. Completion is intentionally capped at `85` because IDA still does not model `0x00546bc0` as a function and there are no direct xrefs to the raw start.

IDA/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `ok`, imagebase `0x400000`, Hex-Rays and strings ready.
- [UID:0001EG] live IDA reconfirmed `sub_545E40` size `0x22a`, exclusive end `0x0054606a` not a function, two callers from `sub_4F7D10`, ParcelIconPane vtable stores to `0x00621bb4/0x00621c00/0x00621c30`, child ParcelPane vtable writes, `g_pParcelIconPane` and `g_pParcelPane` writes, 292-byte child allocation, pane/timer callees, and source-family parent support.
- [UID:0001EI] live IDA reconfirmed `sub_546070` size `0x78`, exclusive end `0x005460e8` not a function, no direct xrefs to the non-deleting entry, vtable restores, child pointer at `+0xfc`, pane-manager dismissal, pane cleanup, `g_pParcelIconPane` clear, base destructor tail call, and the expected callee set.
- [UID:0002KD] live IDA reconfirmed `sub_5465E0` size `0x2a`, exclusive end `0x0054660a` not a function, sole vtable data xref at `0x00621c98`, one callee `0x004a8b10`, and the decompiled event-byte gate with always-false return.
- [UID:0002R6] live IDA reconfirmed `0x00546bc0` and `0x00546d64` are not function starts, successor `sub_546D70` at `0x00546d70`, no direct xrefs to `0x00546bc0`, padding before/after the raw body, security-cookie-framed `thiscall` body ending in `retn 0x10`, payload writes at `+0xf8..+0xfc`, branch on `byte_66DA97`, timer scheduling through `sub_5975E0`, and surrounding FlyingParcelPane vtable-store refs.

Validation:

- `python .\tools\validator.py --mode file --file .\by-memory\0x00545e40-0x0054606a.ParcelIconPaneConstructor.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence/owner applied; [UID:0001EG] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file .\by-memory\0x00546070-0x005460e8.ParcelIconPaneDestructor.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence/owner applied; [UID:0001EI] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file .\by-memory\0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002KD] removed from Low_Completion/Low_Both/by-memory stats rows.
- `python .\tools\validator.py --mode file --file .\by-memory\0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md --apply --queue-timeout 240` -> `ok: 1`; completion/confidence applied; [UID:0002R6] removed from Low_Completion/Low_Both/by-memory stats rows.

IDA DB changes:

- Skipped. The evidence supports documentation score increases and two route corrections only; no source-quality IDA rename/type changes were needed.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace the existing [UID:0001EG] row after [UID:0001EH] `ParcelNotificationPanes` and before [UID:0001EI] `ParcelIconPaneDestructor`.
  - [UID:0001EG][0x00545e40-0x0054606a.ParcelIconPaneConstructor](by-memory/0x00545e40-0x0054606a.ParcelIconPaneConstructor.md) 0x00545e40-0x0054606a | constructor | ParcelIconPane constructor : reconstructable : 86% : very strong : Live IDA reconfirms exact `0x22a` constructor boundary, exclusive-end non-function, two `sub_4F7D10` callers, `ParcelIconPane` vtable stores, child `ParcelPane` vtable writes and 292-byte allocation/setup, `g_pParcelIconPane` and `g_pParcelPane` publication, timer setup, corrected direct owner/emitter [UID:0000A5] after class page cleared `85/86`, source grouping under `ParcelPane.cpp`, and blank final C++ pending source-quality field/helper names.
- Placement context: replace the existing [UID:0001EI] row after [UID:0001EG] `ParcelIconPaneConstructor` and before [UID:0001EJ] `ParcelIconPaneParcelUpdateCallback`.
  - [UID:0001EI][0x00546070-0x005460e8.ParcelIconPaneDestructor](by-memory/0x00546070-0x005460e8.ParcelIconPaneDestructor.md) 0x00546070-0x005460e8 | destructor | ParcelIconPane non-deleting destructor : reconstructable : 86% : very strong : Live IDA reconfirms exact `0x78` destructor boundary, exclusive-end non-function, no direct xrefs to the non-deleting entry, `ParcelIconPane` vtable restores, child pointer at `+0xfc`, pane-manager child dismissal, pane cleanup, `g_pParcelIconPane` clear, base destructor tail call, corrected direct owner/emitter [UID:0000A5] after class page cleared `85/86`, source grouping under `ParcelPane.cpp`, and blank final C++ pending source-quality field/helper names.
- Placement context: replace the existing [UID:0002KD] row after [UID:0002KC] `ParcelPaneSetParcelSlotData` and before [UID:0002KE] `ParcelPaneOnMouseEvent`.
  - [UID:0002KD][0x005465e0-0x0054660a.ParcelPaneOnKeyDown](by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md) 0x005465e0-0x0054660a | class method | ParcelPaneOnKeyDown : reconstructable : 86% : very strong : Live IDA reconfirms exact `0x2a` function boundary, exclusive-end non-function, sole vtable data xref at `0x00621c98`, one callee `0x004a8b10`, `event[4] == 8` gate, key-normalization bytes `event[8]` and `event[0x10a]`, ignored return, always-false result, retained ParcelPane owner/emitter route, and blank final C++ pending final event type/source method names.
- Placement context: replace the existing [UID:0002R6] row after the [UID:0000VN] `0x00546bb5-0x00546bc0` padding row and before the [UID:0000VN] `0x00546d64-0x00546d70` padding row.
  - [UID:0002R6][0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation](by-memory/0x00546bc0-0x00546d64.FlyingParcelPaneStartAnimation.md) 0x00546bc0-0x00546d64 | raw class method | FlyingParcelPane start animation : reconstructable : 85% : strong : Live IDA reconfirms raw non-function start/end, successor `sub_546D70` at `0x00546d70`, no direct xrefs, padding before/after the raw body, security-cookie-framed `thiscall` body ending in `retn 0x10`, branch on `byte_66DA97`, payload writes at `+0xf8..+0xfc`, helper detach/rectangle/pane virtual calls, 10/100 ms timer scheduling through `sub_5975E0`, retained FlyingParcelPane owner/emitter route, and completion cap because manager/scheduler/field names remain provisional.

Remaining blockers:

- No assigned target remains below `85/85`.
- Shared-ledger status: supervisor applied the four replacement rows above on 2026-06-15 and validated `by-memory/-coverage-report.md` with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. The validator normalized the shared-report [UID:0000A5] owner links. No A003 parcel-icon supervisor-owned rows remain pending.

## 2026-06-15 - A003-goal2-parcel-group-macro-item-memory-20260615-17

Assignment: Goal 2 parcel/group/macro/item memory batch selected from refreshed `project-level/-auto-completion-stats.md`.

Targets changed and validated:

- [UID:0001EO] `by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md`: `80/86` -> `86/90`; owner/emitter changed `0000MF`/`0000MF` -> `0000A5`/`0000A5`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:00023W] moved from `by-memory/0x0056c4a0-0x0056c4b5.GroupPaneFalseVirtualStubs.md` to `by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md`: `80/86` -> `86/90`; owner/emitter changed `0000JS`/`0000JS` -> `000074`/`000074`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0001IK] `by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md`: `80/86` -> `85/88`; owner/emitter remain `0000KY`/`0000KY`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002S5] `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md`: `80/86` -> `85/88`; owner/emitter changed `0000OH`/`0000OH` -> `00006X`/`00006X`; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.

Support docs changed with scores unchanged:

- `by-class/LegendPane.md`, `by-file/LegendPane.md`, `by-memory/0x0056c400-0x0056c493.LegendPane.md`, `by-memory/0x00624384-0x00624438.LegendPaneVtableData.md`, and `by-memory/0x0056c4c0-0x0056e939.GroupPanes.md` updated for the [UID:00023W] route correction.
- `by-memory/-ignored.md`, `by-file/Group.md`, `by-class/GroupPane.md`, `by-class/GroupPane2.md`, and `by-memory/0x00624188-0x00624c64.LookGroupCollectionReadOnlyData.md` updated only to remove stale old-path links after the [UID:00023W] rename.

Route decisions:

- [UID:0001EO] now attaches directly to [UID:0000A5][ParcelIconPane](by-class/ParcelIconPane.md), with [UID:0000MF][ParcelPane](by-file/ParcelPane.md) retained as source-file grouping.
- [UID:00023W] corrected from GroupPane/Group.cpp to [UID:000074][LegendPane](by-class/LegendPane.md). Live IDA shows the only data refs are `LegendPane` vtable slots `0x00624408` and `0x006243e8`, both inside [UID:0002V0][LegendPaneVtableData](by-memory/0x00624384-0x00624438.LegendPaneVtableData.md).
- [UID:0001IK] remains attached to [UID:0000KY][MacroDialogs](by-file/MacroDialogs.md); aggregate completion is capped because most methods are still summarized rather than split into final-source child pages.
- [UID:0002S5] now attaches directly to [UID:00006X][ItemWhoInputPane](by-class/ItemWhoInputPane.md), with [UID:0000OH][TargetSelectionInputPanes](by-file/TargetSelectionInputPanes.md) retained as the source-file grouping.

IDA/Wave2/local evidence used:

- Live IDA MCP session `a003_objectlist_dispatch_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`; `server_health` returned `ok`, imagebase `0x400000`, Hex-Rays and strings ready.
- [UID:0001EO] live IDA reconfirmed `sub_546F40` size `0xb9`, exclusive-end non-function, code refs at `0x00546ea7`/`0x00546eb2`, primary vtable data ref `0x00621bb4`, vtable restores `0x00621bb4`/`0x00621c00`/`0x00621c30`, child pane pointer at `+0xfc`, `g_pParcelIconPane` clear, base cleanup, and optional delete. Wave2 method-analysis independently named the wrapper `ParcelIconPane::ScalarDeletingDestructor(int flags)`.
- [UID:00023W] live IDA reconfirmed two leaf functions `0x0056c4a0-0x0056c4a5` and `0x0056c4b0-0x0056c4b5`, each `xor al, al; retn 4`, no callees, padding before/between/after, `GroupPane` constructor start at `0x0056c4c0`, and data refs only from `LegendPane` slots `0x00624408` and `0x006243e8`. Wave2 method-analysis independently labels both as `LegendPane` trivial virtual stubs.
- [UID:0001IK] live IDA refreshed representative boundaries and behavior: `GetSpellKey` `0x0057f750` size `0x8` called from `0x0053ed27`, `SyncEditControl` `0x005805e0` size `0x5e` and vtable ref `0x0062d384`, `OnKeyEvent` `0x00580320` semicolon/text-mode and alpha binding states, and `SpellMacroEditControlPane` scalar destructor `0x00580770` size `0x55` with thunk refs `0x00580677`/`0x00580682` plus vtable ref `0x0062d1e4`. Wave2 method-analysis agrees on `GetSpellKey` and `SyncEditControl`.
- [UID:0002S5] live IDA reconfirmed raw non-function starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`, modeled neighbors `ClearItemWhoTarget` and `SendTargetedActionPacket`, no direct xrefs to raw starts, `dword_69BF24` refs/stores inside the island, traversal callees `0x00506b80`/`0x00506ae0` and `0x00506bd0`/`0x00506b30`, local-player fallback `dword_67A748`, and highlight calls through `0x0053b1b0`. Wave2 does not model the raw starts but supports the surrounding `ItemWhoInputPane` class inventory.

Validation:

- Ran sequential validator with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for all changed files listed above.
- Result: all validator runs exited `0` with `ok: 1`; first target run also rebuilt stale registry metadata after the [UID:00023W] file move. The four target UIDs were removed from generated Low_Completion/Low_Both/by-memory stats rows where applicable.

IDA DB changes:

- Skipped. The evidence supports documentation route/score changes only; no source-quality IDA rename/type changes were needed.

Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit:

- Placement context: replace the existing [UID:0001EO] row after [UID:0001EN] `FlyingParcelPaneScalarDeletingDestructor` and before [UID:0001EP] `ParcelPaneScalarDeletingDestructor`.
  - [UID:0001EO][0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor](by-memory/0x00546f40-0x00546ff9.ParcelIconPaneScalarDeletingDestructor.md) 0x00546f40-0x00546ff9 | scalar deleting destructor | ParcelIconPane scalar deleting destructor : reconstructable : 86% : very strong : Live IDA and Wave2 method-analysis reconfirm exact `0xb9` modeled function boundary, adjustor-thunk code xrefs at `0x00546ea7`/`0x00546eb2`, primary vtable data xref `0x00621bb4`, vtable restores to `0x00621bb4`/`0x00621c00`/`0x00621c30`, child-pane dismissal through `+0xfc`, `g_pParcelIconPane` clear, base cleanup, optional operator delete, corrected direct owner/emitter [UID:0000A5], and blank final C++ pending source-quality destructor/helper names.
- Placement context: replace the padding row immediately before [UID:00023W].
  - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056c493-0x0056c4a0 | padding | LegendPane constructor to LegendPaneFalseVirtualStubs alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment bytes before the separate `LegendPane` false virtual stubs.
- Placement context: replace the existing [UID:00023W] row after the `0x0056c493-0x0056c4a0` padding row and before the `0x0056c4b5-0x0056c4c0` padding row.
  - [UID:00023W][0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs](by-memory/0x0056c4a0-0x0056c4b5.LegendPaneFalseVirtualStubs.md) 0x0056c4a0-0x0056c4b5 | method stubs | LegendPane false virtual stubs : reconstructable : 86% : very strong : Live IDA and Wave2 method-analysis correct prior GroupPane route: both `0x5`-byte leaf bodies return false with `retn 4`, xrefs are LegendPane vtable slots `0x00624408` and `0x006243e8` inside the `0x00624384-0x00624438` LegendPane vtable-data span, predecessor/successor padding and GroupPane constructor at `0x0056c4c0` are confirmed, owner/emitter changed to [UID:000074], and final C++ remains blank until source virtual names are final.
- Placement context: replace the padding row immediately after [UID:00023W].
  - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0056c4b5-0x0056c4c0 | padding | LegendPaneFalseVirtualStubs to GroupPanes alignment : ignored : 100% : strong : IDA confirms `0xcc` alignment bytes before the `GroupPane` constructor at `0x0056c4c0`.
- Placement context: replace the existing [UID:0001IK] row after the `SpellInventoryPanes to MacroEditControlPanes` padding row and before [UID:0001IL] `SpellMacroEditControlPaneTeardownHelper`.
  - [UID:0001IK][0x0057f750-0x005807c5.MacroEditControlPanes](by-memory/0x0057f750-0x005807c5.MacroEditControlPanes.md) 0x0057f750-0x005807c5 | class-method aggregate | MacroEditControlPanes : reconstructable : 85% : strong : Live IDA and Wave2 method-analysis refresh representative macro edit-control methods and boundaries: GetSpellKey `0x0057f750` size `0x8` returns `+0x108` and is called from SpellMacroDialog confirm, SyncEditControl `0x005805e0` size `0x5e` is vtable-referenced at `0x0062d384` and copies text-mode macro data through edit-control helpers, OnKeyEvent `0x00580320` handles semicolon/text mode and alpha item/spell binding states, SpellMacroEditControlPane scalar destructor `0x00580770` size `0x55` has thunk/vtable refs, aggregate end `0x005807c5` remains padding before StartupWindow, owner/emitter retained [UID:0000KY], and final C++ remains blank because many methods still need exact child pages/source-quality names.
- Placement context: replace the existing [UID:0002S5] row after the `ClearItemWhoTarget to raw helper alignment` padding row and before the `Raw helper to SendTargetedActionPacket alignment` padding row.
  - [UID:0002S5][0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers](by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md) 0x005af3b0-0x005af4ef | raw class helpers | ItemWhoTargetNavigationRawHelpers : reconstructable : 85% : strong : Live IDA reconfirms raw non-function starts at `0x005af3b0`/`0x005af430`/`0x005af4b0`, no direct xrefs to those starts, modeled neighbors ClearItemWhoTarget `0x005af390` and SendTargetedActionPacket `0x005af4f0`, exact disassembly for previous/next/local-player target navigation, `dword_69BF24` refs/stores, traversal callees `0x00506b80`/`0x00506ae0`/`0x00506bd0`/`0x00506b30`, local-player fallback `dword_67A748`, highlight toggles `0x0053b1b0`, corrected direct owner/emitter [UID:00006X], and completion cap because raw call-surface/helper names remain provisional.

Remaining blockers:

- No assigned target remains below `85/85`.
- Shared-report status: supervisor applied and validated the six rows above on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 parcel/group/macro/item supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

## 2026-06-15 - A003-goal2-clan-status-list-memory-20260615-18

Assignment: Goal 2 clan/status/list memory batch from Supervisor_notes row `A003-goal2-clan-status-list-memory-20260615-18`.

Targets changed and validated:

- [UID:00021M] `by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md`: `80/88` -> `85/90`; owner/emitter remain [UID:0000I8]; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:00021N] `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`: `80/88` -> `85/90`; owner/emitter remain [UID:0000I8]; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:00021T] `by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md`: `80/88` -> `85/90`; owner/emitter remain [UID:00002E]; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.
- [UID:0002NP] `by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md`: `80/88` -> `85/90`; owner/emitter remain [UID:00002L]; `RECONSTRUCTABLE:TRUE`; final C++ remains blank.

Support docs changed:

- [UID:00002E] `by-class/ClanInfoListPane.md`: `82/88` -> `85/89` to clear the direct parent confidence gate for [UID:00021T]. Added Wave2 inactive-constructor, struct-layout, and local PE no-reference evidence.
- `by-class/-coverage-report.md`: replaced the [UID:00002E] row with the new `85%` completion score and validated it. This was not the banned `by-memory/-coverage-report.md`.

IDA/Wave2/local evidence used:

- Live IDA MCP session `c001_clan_raw_ctor_20260615` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`; `server_health` returned `ok`, imagebase `0x400000`, Hex-Rays and strings ready.
- Live IDA `lookup_funcs` reconfirmed the target starts/endpoints are raw no-function addresses: `0x00486530`/`0x004865a0`/`0x00486620`/`0x00486690`/`0x00486710`/`0x004867f2`, `0x004872e0`/`0x00487335`/`0x00487338`, `0x004885a0`/`0x00488602`, and `0x00488630`/`0x00488674`. Successor modeled functions remain `0x00486800`, `0x00487370`, `0x00488610`, and `0x00488680`.
- The IDA MCP stopped responding before the final live xref retry, so reachability was cross-checked with local PE scans of `NexusTK.exe`. Full-file little-endian VA/RVA scans and `.text` relative branch/call scans found zero hits to `0x00486530`, `0x004865a0`, `0x00486620`, `0x00486690`, `0x00486710`, `0x004872e0`, `0x004885a0`, or `0x00488630`.
- Wave2 has no imported method records for [UID:00021M] or [UID:00021N]. That supports keeping both as raw helper/list-memory documentation rather than promoted class methods.
- Wave2 confirms [UID:00021T] as an inactive canonical zero-caller `ClanInfoListPane` constructor with size `99`, callees `0x004b60b0`/`0x0058dce0`, and `ClanInfoListPane` struct size `372` with `TextEditPane` at offset `0`.
- Wave2 confirms [UID:0002NP] as an inactive canonical zero-caller `ClanStringListPane` constructor with size `68`, callee `0x004f3a50`, fixed `ListPane` layout/vtable notes, method grade `88`, and `ClanStringListPane` struct size `330`.
- Documentation searches found no stronger source name for the opcode `0x4b` subtype `13` clan notice/string-payload helper and no stronger field names for `ClanStatusPane` bytes `+0xf8`/`+0xf9`; these remain explicit final-C++ blockers rather than hidden assumptions.

Validation:

- Ran sequential validator with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for all four target memory pages, `by-class/ClanInfoListPane.md`, and `by-class/-coverage-report.md`.
- Result: all validator runs exited `0` with `ok: 1`. Target UIDs [UID:00021M], [UID:00021N], [UID:00021T], and [UID:0002NP] were removed from generated Low_Completion rows where applicable. [UID:00002E] was also removed from the generated by-class low-completion row after the support-doc update.

IDA DB changes:

- Skipped. Current evidence supports documentation boundary/ownership/score improvements only; no source-quality IDA rename/type change was justified.

### Supervisor-applied `by-memory/-coverage-report.md` replacement rows retained for audit

Supervisor applied and validated the four replacement rows below on 2026-06-15 with `python .\tools\validator.py --mode file --file by-memory\-coverage-report.md --apply --lock-timeout -1`; result `ok: 1`. No A003 clan/status/list supervisor-owned `by-memory/-coverage-report.md` rows remain pending.

- Placement context: replace the existing [UID:00021M] row after [UID:00010F] and before the [UID:0000VN] `0x004867f2-0x00486800` padding row.
  - [UID:00021M][0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers](by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md) 0x00486530-0x004867f2 | packet helper cluster | ClanWithdrawAndNoticePacketHelpers : reconstructable : 85% : very strong : A003 2026-06-15 refresh raises to 85/90: Wave2 has no imported method record for the raw strip, live IDA reconfirms the five raw no-function starts and modeled `0x00486800` successor, local PE scans find no absolute VA/RVA pointer or relative branch/call targets to the helper starts, existing packet evidence covers opcode `0x4b` subtype `11-13` withdraw-money/withdraw-item/string-payload layouts and mirrored submitter context, owner/emitter remain [UID:0000I8], and final C++ remains blank because subtype `13` and source helper names remain provisional.
- Placement context: replace the existing [UID:00021N] row after the [UID:0000VN] `0x004872d8-0x004872e0` padding row and before the [UID:0000VN] `0x00487336-0x00487338` padding row.
  - [UID:00021N][0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper](by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md) 0x004872e0-0x00487335 | raw helper | ClanStatusPaneRowEligibilityHelper : reconstructable : 85% : very strong : A003 2026-06-15 refresh raises to 85/90: Wave2 has no imported method record, live IDA reconfirms the raw no-function helper/switch-table addresses and modeled `0x00487370` successor, local PE scans find no VA/RVA pointer or relative branch/call target to `0x004872e0`, behavior remains a signed row-index action gate through table `0x00487338` using `ClanStatusPane` bytes `+0xf8`/`+0xf9`, owner/emitter remain [UID:0000I8], and final C++ remains blank because source-facing helper and field names remain provisional.
- Placement context: replace the existing [UID:00021T] row after the [UID:0000VN] `0x00488594-0x004885a0` padding row and before the [UID:0000VN] `0x00488603-0x00488610` padding row.
  - [UID:00021T][0x004885a0-0x00488602.ClanInfoListPaneRawConstructor](by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md) 0x004885a0-0x00488602 | raw constructor | ClanInfoListPaneRawConstructor : reconstructable : 85% : very strong : A003 2026-06-15 refresh raises to 85/90 and refreshes parent [UID:00002E] to 85/89: Wave2 confirms an inactive canonical zero-caller `ClanInfoListPane` constructor record with size `99`, `TextEditPane` class size `372`, and callees `0x004b60b0`/`0x0058dce0`; live IDA reconfirms raw no-function start/end and modeled `0x00488610` successor; local PE scans find no VA/RVA pointer or relative branch/call target to `0x004885a0`; class owner/emitter remain [UID:00002E]; final C++ remains blank because inline `ClanStatusPane` construction is still the source-quality construction anchor.
- Placement context: replace the existing nested [UID:0002NP] row under [UID:00010I], after the [UID:0000VN] `0x00488625-0x00488630` padding row and before the [UID:0000VN] `0x00488674-0x00488680` padding row.
  - [UID:0002NP][0x00488630-0x00488674.ClanStringListPaneRawConstructor](by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md) 0x00488630-0x00488674 | raw constructor | ClanStringListPaneRawConstructor : reconstructable : 85% : very strong : A003 2026-06-15 refresh raises to 85/90: Wave2 confirms an inactive canonical zero-caller `ClanStringListPane` constructor record with size `68`, fixed `ListPane` layout/vtable notes, grade `88`, and class size `330`; live IDA reconfirms raw no-function start/end and modeled `0x00488680` successor; local PE scans find no VA/RVA pointer or relative branch/call target to `0x00488630`; class owner/emitter remain [UID:00002L]; final C++ remains blank pending final class declaration and raw-constructor reachability decisions.

Remaining blockers:

- No assigned target remains below `85/85`.
- `by-memory/-coverage-report.md` was not edited directly by A003. The supervisor applied and validated the four exact replacement rows above; no shared rows remain pending for this batch.
- B-agent handoff: none required for this row. Remaining uncertainty is narrow source-facing naming/placement finalization, already documented on each page; no heavy heuristic source-structure inference is blocking the current Goal 2 score targets.
