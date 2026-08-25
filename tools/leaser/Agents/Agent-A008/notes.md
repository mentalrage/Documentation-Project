## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A008\current_leases.md`
Do not edit `current_leases.md`; read it for current lease status.

## Retired-Agent Status

- Agent-A008 is stopped/offline for the current supervisor workflow. No open pending implementation entries remain in this note file.

## Supervisor-Applied Follow-Ups

- A008 Batch 171 `by-memory/-coverage-report.md` rows were applied and validated by the supervisor on 2026-06-11; no Batch 171 by-memory report rows remain open.

## 2026-06-11 A008 Batch 155 Notes

- Batch targets:
  - [UID:0001W0] `by-type/by-struct/ScrollInventoryPaneLayout.md`
  - [UID:00006R] `by-class/InventoryPane.md`
- Leases used:
  - `by-type/by-struct/ScrollInventoryPaneLayout.md`
  - `by-class/InventoryPane.md`
  - `by-class/ScrollInventoryPane.md`
  - `by-file/InventoryPane.md`
  - `by-file/InventoryScrollPane.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A008/notes.md`
- Changed files:
  - `by-type/by-struct/ScrollInventoryPaneLayout.md`
  - `by-class/InventoryPane.md`
  - `by-class/ScrollInventoryPane.md`
  - `by-file/InventoryPane.md`
  - `by-file/InventoryScrollPane.md`
  - `by-class/-coverage-report.md`
  - `by-file/-coverage-report.md`
  - `by-type/by-struct/-coverage-report.md`
  - `tools/leaser/Agents/Agent-A008/notes.md`
- Score and assignment changes:
  - [UID:0001W0] `ScrollInventoryPaneLayout`: `78/84` -> `85/88`; `AUTOGEN_PARENT_UID` blank -> `0000CK`.
  - [UID:00006R] `InventoryPane` class: `76/86` -> `85/88`; `AUTOGEN_PARENT_UID` blank -> `0000KA`.
  - [UID:0000CK] `ScrollInventoryPane` class parent: `82/82` -> `85/86`; retained direct file parent `0000KB`.
  - [UID:0000KA] `InventoryPane` file parent: `84/84` -> `85/86`.
  - [UID:0000KB] `InventoryScrollPane` file parent: `84/80` -> `85/85`.
- Evidence added:
  - Live IDA MCP `lookup_funcs`, `decompile`, `callers`, and `xrefs_to` rechecked legacy `InventoryPane` methods, vtable stores/restores, page/view/effect fields, list/grid render paths, navigation buttons, slot mapping, drag opcode `0x66`, tooltip opcode `0x59`, and scalar-delete cleanup.
  - Live IDA MCP rechecked `ScrollInventoryPane` sole constructor caller at `0x004eb4e4`, `NewInventoryPane` allocation of `272` bytes / `0x110`, constructor vtable stores to `0x0062402c/0x00624078/0x006240a8`, constructor tail field writes, and existing raw helper/reset caveats.
  - Numeric conversions for `272`, `348`, `248`, `249`, `252`, `256`, `102`, `89`, `10000`, and `15` were checked with `tools/int_convert.py` before documentation use.
- Validation commands/results:
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\InventoryPane.md --apply` -> exit 0; updated completion/confidence and autogen parent for UID `00006R`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\InventoryPane.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\InventoryScrollPane.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\ScrollInventoryPane.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-struct\ScrollInventoryPaneLayout.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\-coverage-report.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\-coverage-report.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-type\by-struct\-coverage-report.md --apply` -> exit 0.
- Blockers:
  - None remaining. `by-type/by-struct/-coverage-report.md` and `by-class/-coverage-report.md` were initially leased by another agent, but became available and were synced/validated before return.
  - `git status` was unavailable from `E:\NTK\GhidraBridge`, `E:\NTK\GhidraBridge\source-3`, and `C:\FastStorage\NTK_Sources\source-3` because those paths are not Git repositories in this workspace.
- Banned report handling:
  - Did not edit `by-memory/-coverage-report.md`.
  - Open `by-memory/-coverage-report.md` rows/changes: none; no by-memory documents were changed in this batch.
  - Supervisor-applied rows for `by-memory/-coverage-report.md`: none.

## 2026-06-11 Supervisor Cleanup

- Cleared the old new-file workflow follow-up because the exact pages now exist and are represented in `by-memory/-coverage-report.md`:
  - [UID:00031T] `by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md`
  - [UID:00031U] `by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md`
  - [UID:0002YP] `by-memory/0x005b6760-0x005b67c0.SendWearPacket.md`

## 2026-06-11 A008 Batch 165 Notes

- Batch targets:
  - [UID:0001B4] `by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md`
  - [UID:0001B5] `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`
- Leases used:
  - `by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md`
  - `by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md`
  - `by-memory/0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md`
  - `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`
  - `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`
  - `by-class/GameServerConfig.md`
  - `by-file/GameServerConfig.md`
  - `tools/leaser/Agents/Agent-A008/notes.md`
- Changed files:
  - `by-memory/0x00514d50-0x00514ddc.GameServerNationTableDelete.md`
  - `by-memory/0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md`
  - `by-memory/0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md`
  - `by-memory/0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md`
  - `by-class/ProtectedArray_struct_GameServerConfig__NationEntry_.md`
  - `by-class/GameServerConfig.md`
  - `by-file/GameServerConfig.md`
  - `tools/leaser/Agents/Agent-A008/notes.md`
  - Validator-owned generated outputs refreshed: `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md`.
- Score, classification, and assignment changes:
  - [UID:0001B4] `GameServerNationTableDelete`: `88/92` -> `90/93`; `RECONSTRUCTABLE:TRUE` -> `FALSE`; `AUTOGEN_PARENT_UID` remains blank because it is now a reviewed mixed-owner aggregate/index.
  - [UID:000372] `GameServerNationEntryProtectedArrayDeletingDestructor`: new split child `0/0` -> `90/93`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID:0000B4`.
  - [UID:000374] `GameServerConfigScalarDeletingDestructor`: new split child `0/0` -> `90/93`; `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID:00005O`.
  - [UID:0001B5] `SystemMessageMarkerScalarDeletingDestructor`: `86/90` -> `88/92`; parent remains blank because the body is shared across dialog-creator and system-message marker vtable slots. Parallel A001 work now raises `LObject` above `85/85`, but that still does not prove `LObject` is this shared derived-slot body's direct source owner.
  - [UID:0000B4] `ProtectedArray_struct_GameServerConfig__NationEntry_`: `84/88` -> `85/88`; parent remains `0000JP`; now clears the direct-parent gate for [UID:000372].
  - [UID:00005O] `GameServerConfig` and [UID:0000JP] `GameServerConfig` file: no score changes; references/endpoints synced to [UID:000372] and [UID:000374].
- Evidence added:
  - Live IDA MCP `idb_meta`, `lookup_funcs`, `decompile`, `disasm`, `callees`, `xrefs_to`, and `py_eval` byte-window checks on `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.
  - `0x00514d50` rechecked as `sub_514D50` size `0x2f`, one direct vtable-slot ref at `0x0061e704`, callee pair `j_j_j___free_base`/`sub_5C7526`, protected-array vtable-store refs, one trailing `0xcc`, and direct parent [UID:0000B4].
  - `0x00514d80` rechecked as `sub_514D80` size `0x5c`, one direct vtable-slot ref at `0x0061e70c`, callees `free`, `sub_4F4A90`, `sub_4F4AC0`, guarded path `0x0041b6a0`, `dword_69B4C4` clear at `0x00514d9e`, four trailing `0xcc` bytes, and direct parent [UID:00005O].
  - `0x00514e60` rechecked as `sub_514E60` size `0x38`, four data-only vtable refs `0x0061e8e0/0x0061e8f0/0x0062d6ac/0x0062d6d0`, callees `0x004f4a90/0x004f4ac0/0x0041b6a0`, no function at `0x00514e98`, next function at `0x00514ea0`, and exact padding.
- Validation commands/results:
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x00514d50-0x00514d7f.GameServerNationEntryProtectedArrayDeletingDestructor.md --apply` -> exit 0; assigned UID `000372` on first pass, then recorded `90/93`, reconstructable true, parent `0000B4`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x00514d80-0x00514ddc.GameServerConfigScalarDeletingDestructor.md --apply` -> exit 0; assigned UID `000374` on first pass, then recorded `90/93`, reconstructable true, parent `00005O`.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x00514d50-0x00514ddc.GameServerNationTableDelete.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-memory\0x00514e60-0x00514e98.SystemMessageMarkerScalarDeletingDestructor.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\ProtectedArray_struct_GameServerConfig__NationEntry_.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-class\GameServerConfig.md --apply` -> exit 0.
  - `python tools/validator.py --queue-timeout 120 --mode file --file by-file\GameServerConfig.md --apply` -> exit 0.
- Blockers:
  - No documentation blockers remain for the Batch 165 targets.
  - Batch 165 `by-memory/-coverage-report.md` rows for `0001B4`, `000372`, `000374`, and `0001B5` were applied and validated by the supervisor on 2026-06-11.

## 2026-06-11 A008 Batch 171 Notes

- Batch targets:
  - [UID:0001DL] `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`
  - [UID:0002QZ] `by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md`
  - [UID:0001DN] `by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md`
- Leases used:
  - `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`
  - `by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md`
  - `by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md`
  - `by-class/SoundObjectPane.md`
  - `by-file/SoundObjectPane.md`
  - `by-class/StaticObjectPane.md`
  - `by-file/StaticObjectPane.md`
  - New exact split pages `00037Z`, `000380`, `000381`, `000382`, `000383`, `000384`, `000385`, `000386`, `000387`, `000388`
  - `tools/leaser/Agents/Agent-A008/notes.md`
  - Note: first lease set expired while validator was running; A008 reacquired all edited files before final validation/notes. No conflicting lease appeared on reacquire.
  - Final `python leaser.py A008 unlease` reported `A008: No active leases`; the reacquired five-minute leases expired before final release, so no A008 leases remained active.
- Changed files:
  - `by-memory/0x0053cfa0-0x0053d65b.ObjectPaneCompanionDestructors.md`
  - `by-memory/0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md`
  - `by-memory/0x0053d660-0x0053d7bd.SoundAndStaticObjectPaneDestructors.md`
  - `by-memory/0x0053cfa0-0x0053cfdb.AttachedObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053cfe0-0x0053d025.BowGaugeObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d060-0x0053d0f7.DamageNumberObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d100-0x0053d197.EffectObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d1a0-0x0053d237.FlyingObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d240-0x0053d2d7.HitBarObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d2e0-0x0053d377.ItemObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d620-0x0053d65b.ObjectInfoObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d660-0x0053d739.SoundObjectPaneScalarDeletingDestructor.md`
  - `by-memory/0x0053d740-0x0053d7bd.StaticObjectPaneScalarDeletingDestructor.md`
  - `by-class/SoundObjectPane.md`
  - `by-file/SoundObjectPane.md`
  - `by-class/StaticObjectPane.md`
  - `by-file/StaticObjectPane.md`
  - `tools/leaser/Agents/Agent-A008/notes.md`
  - Validator-owned generated outputs refreshed: `auto-generated/-ag-memory-coverage.md` and `project-level/-auto-completion-stats.md`.
- Score, classification, and assignment changes:
  - [UID:0001DL] `ObjectPaneCompanionDestructors`: `85/90` -> `90/92`; `RECONSTRUCTABLE:TRUE` -> `FALSE`; parent remains blank as non-emitting mixed split inventory.
  - [UID:0002QZ] `MotionAnimationScalarDeletingDestructor`: `82/88` -> `88/92`; `AUTOGEN_PARENT_UID` blank -> `00008R`.
  - [UID:0001DN] `SoundAndStaticObjectPaneDestructors`: `84/89` -> `90/92`; `RECONSTRUCTABLE:TRUE` -> `FALSE`; parent remains blank as non-emitting mixed split inventory.
  - New children [UID:00037Z], [UID:000380], [UID:000381], [UID:000382], [UID:000383], [UID:000384], [UID:000385], [UID:000386], [UID:000387], [UID:000388]: `0/0` -> `88/92`, `RECONSTRUCTABLE:TRUE`.
  - Assigned new children: [UID:00037Z] -> `00000M`, [UID:000380] -> `000011`, [UID:000383] -> `000057`, [UID:000384] -> `000067`, [UID:000385] -> `00006V`, [UID:000387] -> `0000DH`, [UID:000388] -> `0000E1`.
  - Left unassigned by strict gate: [UID:000381] because direct parent [UID:00003F] was `82/88` and leased by A003; [UID:000382] because direct parent [UID:000049] was `80/84`; [UID:000386] because direct parent [UID:00009P] was `82/88` and leased by A003.
  - [UID:0000DH] `SoundObjectPane` class: `84/88` -> `85/89`; parent remains `0000NW`.
  - [UID:0000NW] `SoundObjectPane` file: `82/86` -> `85/87`.
  - [UID:0000E1] `StaticObjectPane` class: `84/86` -> `85/87`; parent remains `0000O6`.
  - [UID:0000O6] `StaticObjectPane` file: `82/86` -> `85/87`.
- Evidence added:
  - Live IDA MCP `idb_meta` confirms `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515`.
  - Live IDA MCP `lookup_funcs`, `callees`, `xrefs_to`, `decompile`, and `py_eval` byte-window checks reconfirmed exact bounds and padding for `0x0053cfa0`, `0x0053cfe0`, `0x0053d060`, `0x0053d100`, `0x0053d1a0`, `0x0053d240`, `0x0053d2e0`, `0x0053d590`, `0x0053d620`, `0x0053d660`, and `0x0053d740`.
  - `0001DL` now documents exact child splits and excludes already-owned BoxRotator, LightingObjectPane, LivingObjectPane, Motion, Sound, and Static spans.
  - `0002QZ` now documents 2026-06-11 Motion wrapper boundary/padding/callee evidence and direct class parent gate.
  - `0001DN` now documents exact SoundObjectPane and StaticObjectPane child splits and keeps the mixed aggregate non-emitting.
- Validation commands/results:
  - `python tools/validator.py --mode file --file <new child> --apply --queue-timeout 120` for all 10 new child pages -> exit 0; assigned UIDs `00037Z` through `000388`.
  - `python tools/validator.py --mode file --file <each edited by-* file> --apply --queue-timeout 120` for 17 edited docs -> exit 0; validator updated completion/confidence, autogen registry, references, and generated autogen coverage. No validation errors reported.
- Blockers:
  - No Batch 171 `by-memory/-coverage-report.md` rows remain open; the supervisor applied and validated them on 2026-06-11.
  - Did not edit `by-memory/0x00539bc0-0x0053d614.MotionAnimation.md`, `by-class/Motion.md`, or `by-file/Motion.md` because Agent-A006 held those at the initial lease check. `0002QZ` could still clear the direct class gate from current docs and live evidence.
  - Did not edit [UID:00003F] `DamageNumberObjectPane` or [UID:00009P] `ObjectInfoObjectPane` because A003 held leases at the initial lease check; exact children remain unassigned despite child `88/92`.
  - [UID:000049] `EffectObjectPane` direct parent remained below `85/85` (`80/84`), so [UID:000382] remains unassigned awaiting future parent research.
  - `git status` was unavailable from `E:\NTK\GhidraBridge` because it is not a Git repository in this workspace.
  - Supervisor application: Batch 171 `by-memory/-coverage-report.md` replacement/insert rows for [UID:0001DL], [UID:00037Z], [UID:000380], [UID:000381], [UID:000382], [UID:000383], [UID:000384], [UID:000385], [UID:0002QZ], [UID:000386], [UID:0001DN], [UID:000387], and [UID:000388] were applied and validated on 2026-06-11.
