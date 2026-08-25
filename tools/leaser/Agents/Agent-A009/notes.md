## Standing A-Agent Source-Quality Policy (2026-06-15)

- Investigate source-quality blockers during normal documentation work regardless of current score. Do not stop at 85/85 if field/type/global/protocol/helper-name, caller/reachability, ownership, source-placement, split/merge/range, or final-C++ blockers remain.
- For each blocker you mention, either resolve it with supported documentation, metadata, IDA, or Wave2/Wave3 changes; record the exact evidence checked and why it cannot be safely resolved yet; or keep/lower the score if the unresolved issue limits behavior, ownership, source placement, or confidence.
- Do not defer an issue to "final C++" just because C++ has not yet been written. These issues must be investigated before C++ emission and throughout the score/evidence pass.

## Metadata Terminology Note (2026-06-13)

- Older entries in this log may use pre-migration `AUTOGEN_PARENT_UID`, `AUTOGEN_PARENT_POSITION`, `parent`, `parent blank`, `parentless`, or `unassigned` wording.
- Current validator metadata uses `CANONICAL_OWNER` for semantic/documentation ownership and `EMITTER_UIDS` plus `EMITTER_POSITION_OPTIONAL` for generated-output routing.
- Interpret old `AUTOGEN_PARENT_UID` entries as legacy combined owner/emitter context; do not copy them into new edits without mapping them to the current fields.
- Current generated report terms are `no-owner`, `emits`, `non-emits`, `multiple-emitters`, and `dead-ends`.

Lease report symlink: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-A009\current_leases.md`
Do not edit `current_leases.md`; read it for current lease status.

## Retired-Agent Status

- Agent-A009 is stopped/offline for the current supervisor workflow. No open pending implementation entries remain in this note file.
- The old SpellInputPane and ApplicationReadProcessorName IDA retry notes were pruned as retired-agent context only. They did not contain exact pending edits, and no documentation changes should be applied from those notes without fresh research.

## 2026-06-11 Supervisor Cleanup

- Applied and validated A009 blocked report rows for Batch117 FolderTree, Batch111 Clan, Batch050 UserPane split/report synchronization, Batch038 EventDispatcher/FpsPane and singleton split rows, Batch007 Motion/ObjectPane, Batch008 Look/Group, Batch009 WaitableTimer/CashShop/JsonCpp, Batch010 File/DAT, Batch011 Crasher/DAT/SoftwareRender, and Batch012 CreateUser.
- Confirmed stale/superseded and left current newer rows intact:
  - Batch073 `0001OJ` now intentionally routes through `MapTilePixelDimensions`/`MapPane`; do not clear that parent based on the older note.
  - Batch063 FittingRoom rows and `0002OJ PatchPane2VtableData` were already reflected by newer rows.
  - Batch050 `000260`/`0002SO` ObjectPane aggregate rows are superseded by B001 non-emitting inventory decisions; UserPane split child rows were applied.
  - Batch038 `0000J9 ExchangeDialog` and `0000KE ItemDialogs` already had newer stronger A007 rows, so they were not downgraded.
  - Batch012 `0002OF ObjectListVtableData` already has a newer stronger A005/ObjectList assignment row, so it was not downgraded to the older blank-parent text.
  - The old SoftwareRender new-file follow-up is complete: all listed callback split pages exist and are represented in `by-memory/-coverage-report.md`.

## 2026-06-11 A009 Batch 156

- Changed files:
  - `by-type/by-struct/FontSlotStorage.md`
  - `by-type/by-struct/-coverage-report.md`
  - `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`
  - Validator-owned generated refresh observed during validation: `auto-generated/-ag-class-coverage.md`
- Leases used:
  - Leased `by-type/by-struct/FontSlotStorage.md`: success.
  - Leased `by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md`: success.
  - Initial lease of `by-type/by-struct/-coverage-report.md`: rejected because Agent-A001 held it; retried after expiration and leased successfully, then applied the row.
  - Did not lease or edit `by-memory/-coverage-report.md` because the Batch 156 supervisor override bans edits to that file.
- Score changes:
  - UID `0001UM` `FontSlotStorage`: `78/88` -> `85/90`; `AUTOGEN_PARENT_UID` blank -> `00005B` (`FontImageLib`). Evidence: live IDA MCP reconfirmed loader/measurement/decoder/destructor bounds, `0x40008` stride, archive pointer loaded flag, two metric reads, second-metric minus-four adjustment, `0x10000` glyph-offset loop, and measurement consumer path.
  - UID `00018M` `BackPaneHelpPacketDisplayV3`: `84/88` -> `86/90`; `AUTOGEN_PARENT_UID` blank -> `00000S` (`BackPane`). Evidence: live IDA MCP reconfirmed exact `0x11e` bounds, non-function exclusive end, next `0x004ef630` boundary, empty caller/xref set, callee set, `thiscall` decompilation, BackPane `this` passed to `GetBounds`, `g_pSimpleHelpPane` close, `0xfc` allocation, `0x2710` timeout, and sibling singleton-read alignment.
- Validation:
  - `python ...\validator.py --mode file --file ...\by-type\by-struct\FontSlotStorage.md --apply`: `ok: 1`; final concise rerun showed `scanned markdown files: 1`, `autogen_report_update` for validator-owned `auto-generated/-ag-class-coverage.md`.
  - `python ...\validator.py --mode file --file ...\by-memory\0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md --apply`: `ok: 1`; final concise rerun showed `scanned markdown files: 1`, all autogen reports unchanged.
  - `python ...\validator.py --mode file --file ...\by-type\by-struct\-coverage-report.md --apply`: `ok: 1`; final concise rerun showed `scanned markdown files: 1`, all autogen reports unchanged.
- Blockers/open caveats:
  - V3 still has no direct `callers` or `xrefs_to` result for `0x004ef510`; packet dispatch table/reachability remains open even though the class parent gate now clears.
  - `FontSlotStorage` metric field names remain behavior names until resource-level confirmation.
- Supervisor applied the blocked banned `by-memory/-coverage-report.md` row for `00018M` after Batch156 returned.

## 2026-06-11 A009 Batch 162

- Changed files:
  - `by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md`
  - `by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md`
  - `by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md`
  - `by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md`
  - `tools/leaser/Agents/Agent-A009/notes.md`
  - Validator-owned generated refresh observed during continuation validation: `auto-generated/-ag-memory-coverage.md`
- Leases used:
  - Leased all four Batch162 by-memory targets and `tools/leaser/Agents/Agent-A009/notes.md`: success.
  - Final unlease attempt for those five paths returned `Rejected[No active lease]`; the leases had expired before release.
  - Re-leased `tools/leaser/Agents/Agent-A009/notes.md` only to record the lease-expiration fact, then released it.
  - Continuation leased the same four Batch162 by-memory targets plus `notes.md`: success.
  - Continuation final unlease attempt again returned `Rejected[No active lease]` for those five paths because the leases had expired before release.
  - Re-leased `tools/leaser/Agents/Agent-A009/notes.md` only to record the continuation lease-expiration fact, then released it.
  - Did not lease or edit `by-memory/-coverage-report.md` because the supervisor override bans edits to that file.
- Score changes:
  - UID `0002BD` `UiAssetModeRectVirtualDispatchHelper`: `82/86` -> `86/90`; `AUTOGEN_PARENT_UID` remains blank.
  - UID `00022Z` `UnreferencedUiResourceTextHelpers`: `82/86` -> `86/90`; `RECONSTRUCTABLE:TRUE` -> `FALSE` because the aggregate is a non-emitting split inventory; `AUTOGEN_PARENT_UID` remains blank.
  - UID `0002BE` `UiAssetModeRectWriteHelper`: `82/86` -> `86/90`; `AUTOGEN_PARENT_UID` remains blank.
  - UID `0002BF` `WideGlyphResourceTextRendererRaw`: `82/86` -> `86/90`; `AUTOGEN_PARENT_UID` remains blank.
- Evidence added:
  - Live IDA MCP IDB identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - `lookup_funcs` and `py_eval` reconfirmed no function objects, empty `XrefsTo`, and no raw little-endian pointer hits for `0x00503060`, `0x005030c0`, and `0x00503110`.
  - Exact byte windows and padding reconfirmed: helpers at `0x00503060-0x005030bc`, `0x005030c0-0x00503104`, and `0x00503110-0x005031e1`; `0xcc` padding at `0x0050305c-0x00503060`, `0x005030bc-0x005030c0`, `0x00503104-0x00503110`, and `0x005031e1-0x005031f0`.
  - Neighboring modeled functions reconfirmed: `sub_502E30` at `0x00502e30-0x0050305c`, `sub_5031F0` at `0x005031f0-0x005032c3`, `sub_503350` at `0x00503350-0x0050349f`, and `sub_5034A0` at `0x005034a0-0x00503574`.
  - Instruction walks reconfirmed the `g_useEpfAssets`/`sub_4B7C50` rectangle helpers, the vtable slot `+0x20` dispatch in `0002BD`, the dual `retn 8` output-write helper in `0002BE`, and the UTF-16 glyph renderer in `0002BF` using `dword_69B3E8` and `sub_4B7E10`.
  - Continuation PE scan of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` found no absolute-VA, RVA, `E8/E9 rel32`, or `0F 8x rel32` references to `0x00503060`, `0x005030c0`, or `0x00503110`.
  - Continuation PE vtable dump showed `MapNamePane` vtables at `0x0061e5b4`, `0x0061e600`, and `0x0061e630` contain known MapName slots such as `0x00503840`, `0x00503350`, `0x0050380b`, `0x005034a0`, and `0x00503816`, but none of the raw helper starts.
  - Exported decompilation ties `0002BF` to the `MapNamePane` font field: `0x00503110` reads `this + 0x220`, while `MapNamePane` constructor `0x005031f0` loads `9X11FONT.BIN` into `this + 0x220` and destructor `0x005032d0` frees that field. This is association evidence, not enough for parent assignment without a direct ref.
  - `0002BD`/`0002BE` rectangle width `0xad` matches the documented `MapNamePane` 173-pixel map-name clamp; `0xa6` is the EPF/current narrower variant. This is association evidence, not enough for parent assignment without a direct ref.
  - One initial `py_eval` attempt failed due an `ida_ua.generate_disasm_line` API mismatch; the re-run using `idc.generate_disasm_line` succeeded and supplied the evidence above.
- Validation:
  - Initial validation at `84/88` passed, then supervisor required continuation because completion was still below gate.
  - Continuation `python tools/validator.py --mode file --file by-memory/0x00503060-0x005030bc.UiAssetModeRectVirtualDispatchHelper.md --apply`: `ok: 1`; `completion_update 0002BD ... 86`; `confidence_update 0002BD ... 90`; validator-owned `auto-generated/-ag-memory-coverage.md` refreshed.
  - Continuation `python tools/validator.py --mode file --file by-memory/0x00503060-0x005031e1.UnreferencedUiResourceTextHelpers.md --apply`: `ok: 1`; `completion_update 00022Z ... 86`; `confidence_update 00022Z ... 90`; `autogen_registry_update 00022Z ... true -> false`; validator-owned `auto-generated/-ag-memory-coverage.md` refreshed.
  - Continuation `python tools/validator.py --mode file --file by-memory/0x005030c0-0x00503104.UiAssetModeRectWriteHelper.md --apply`: `ok: 1`; `completion_update 0002BE ... 86`; `confidence_update 0002BE ... 90`; all seven autogen reports unchanged.
  - Continuation `python tools/validator.py --mode file --file by-memory/0x00503110-0x005031e1.WideGlyphResourceTextRendererRaw.md --apply`: `ok: 1`; `completion_update 0002BF ... 86`; `confidence_update 0002BF ... 90`; all seven autogen reports unchanged.
- Blockers/open caveats:
  - The cluster now clears `85/85` documentation status, but still cannot be assigned after serious research because there are no IDA function objects, direct caller xrefs, raw pointer/table hits, PE-level absolute/RVA/relative references, vtable entries, or source-file owner evidence for the three helper starts.
  - MapNamePane file/class clear 85/85 and have useful field/size associations, but lack direct owner evidence; MiniMap/MiniMapButton and MainMenu candidates likewise lack direct references. The by-memory aggregate is now explicitly non-emitting and not a source owner.
  - C++ reconstruction remains intentionally blank because owner type, source parent, caller contract, field names, and live reachability are unresolved.
  - No Batch 162 `by-memory/-coverage-report.md` rows remain open; the supervisor applied and validated the rows for [UID:00022Z], [UID:0002BD], [UID:0002BE], and [UID:0002BF] on 2026-06-11.
