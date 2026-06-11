## Finalized Report / Current Recommendation

- Target: [UID:0000YV] `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`
- Current recommendation: assign the exact helper to [UID:0000HG] `by-file/Application.md` as Application/startup fatal-load cleanup glue.
- Recommended status/classification: reconstructable, assigned, source-authored global/helper function; parent [UID:0000HG] `Application`.
- Confidence: high, 91/100 for the exact helper assignment. Behavior/range are stronger than the original-source spelling; source-file ownership is an evidence-backed reconstruction inference rather than recovered symbol proof.
- Concrete next action for A-agents/supervisor: accept the B001-012 parent change for [UID:0000YV]; keep [UID:0000QQ] `g_pDATFileMgr` and DAT manager implementation under [UID:0000IO] `DATFileMgr`; schedule a focused follow-up for paired [UID:0000YW] `DestroyExceptionHandler` and the unsplit `0x004673c0` KeySpeedMgr deletion helper.
- Report status: final.

## Supporting Research

### Target Summary

[UID:0000YV] covers `0x00467380-0x00467391`, IDA `sub_467380`, a `0x11` byte helper. Before B001-012 it was `87/90`, reconstructable, and parent-blank because prior docs stopped at "DATFileMgr object owner versus Application fatal-load cleanup" uncertainty.

B001-012 changed the page to `88/91` and set `AUTOGEN_PARENT_UID:0000HG`.

### Binary Facts From IDA MCP

- `lookup_funcs` confirms `sub_467380` at `0x00467380`, size `0x11`; sibling helpers are `sub_4673A0` at `0x004673a0`, `sub_4673C0` at `0x004673c0`, `sub_4673E0` at `0x004673e0`, `sub_4673F0` at `0x004673f0`, and `sub_467410` at `0x00467410`.
- Exact disassembly of `0x00467380` loads `dword_67AB40`, null-checks it, loads vtable slot zero, pushes delete flag `1`, calls the indirect deleting destructor, and returns.
- The helper does not clear `g_pDATFileMgr`. Normal singleton writes/clears are in DAT manager code at `0x0049bd67`, `0x0049bd6e`, `0x0049be63`, `0x0049d180`, and `0x0049d36d`.
- `callers 0x00467380` reports 22 direct call sites. Every site is paired with `sub_4673A0` five bytes later, except the shared HumanImageLib tail also has the expected nearby second pair.
- Caller functions are image/resource startup constructors/loaders: `0x004d1860` MapTileImageLib constructor, `0x004d2720` HumanImageLib constructor, `0x004dcf60` StaticObjImageLib constructor, `0x004ddf60` EffectObjImageLib constructor, and `0x004e1800` NewHumanImageLib accessory table loader.
- Representative caller strings immediately after the paired cleanup calls include `Error on Tile File!`, `Error on Body File!`, `Error on Sword File!`, `Error on Spear File!`, `Error on Bow File!`, `Error on Fan File!`, `Error on Shield File!`, `Error on Arrow File!`, `Error on Face File!`, `Error on Hair File!`, `Error on TileC File!`, `Error on Effect File!`, and `Error on ACC2DRW table!`.
- Neighbor audit: `0x004673c0` is the same delete-wrapper shape over `dword_67AB48` / `g_pKeySpeedMgr`, with one direct caller in [UID:00019G] `WinMain` at `0x004f5eeb` after `KeySpeedMgrRestoreSystemKeyboardSettings`. `0x004673e0` returns `dword_67AB1C` / `g_pApplication`. [UID:0000YX] `0x00467410-0x004674ed.LoadIndexedDATSeries` is already Application-owned startup DAT policy.

IDA evidence artifact saved at:
`tools/leaser/Agents/Agent-B001/research/scratch/0000YV-ida-evidence.json`

### Documentation Evidence Treated As Hypotheses

- [UID:0000YV] target page already documented the delete behavior, 22 paired callers, and DATFileMgr/Application ambiguity. B001-012 confirms the behavior and caller facts but rejects the passive unassigned conclusion.
- [UID:0000HG] `Application` already listed the paired cleanup helpers as likely file contents if final evidence kept them near application/resource failure logic. B001-012 confirms this for [UID:0000YV].
- [UID:0000IO] `DATFileMgr` previously listed `DestroyDATFileMgr` in proposed contents as cleanup glue. B001-012 treats that as a stale ownership inference: DATFileMgr owns the object/global, not the external fatal-cleanup helper body.
- [UID:0000YX] `LoadIndexedDATSeries` is Application-owned and calls the DAT manager load wrapper while keeping archive parsing under DATFileMgr. That ownership split is consistent with the B001-012 split for `DestroyDATFileMgr`.
- B001-011 assigned [UID:0002VI] `FatalErrorDialogAndBreak` to Application because it uses `g_pApplication`, the main-window accessor, and Application/startup callers. `DestroyDATFileMgr` is not the same function family, but it participates in the same startup/fatal-failure policy layer.

### Ranked Ownership Analysis

1. [UID:0000HG] `Application` - accepted.
   - For: helper is in the Application lifecycle/startup neighborhood; neighbors include `g_pApplication` accessor and Application-owned `LoadIndexedDATSeries`; all 22 call sites are startup/resource fatal-load exits; every call pairs with `DestroyExceptionHandler`; Application already owns process startup/shutdown/fatal UX policy and clears `86/90`.
   - Against: the direct callers are image-library constructors/table loaders rather than `Application::Initialize` itself; the helper body does not read `g_pApplication`.
   - Conclusion: strongest direct source parent. The caller set proves shared fatal-startup cleanup policy, and the address/neighborhood evidence places that policy with Application rather than the individual consumers.

2. [UID:0000IO] `DATFileMgr` - rejected as direct helper owner, retained as object/singleton owner.
   - For: helper deletes `g_pDATFileMgr`; `DATFileMgr` owns the class, singleton pointer, vtables, archive wrappers, and manager lifecycle.
   - Against: no DAT manager callers; helper is outside DAT manager text cluster; normal singleton clearing is in DAT manager constructors/destructors; the helper does not clear the pointer; every use is paired with unrelated exception-handler cleanup at fatal resource-load exits.
   - Conclusion: assigning this helper to DATFileMgr would confuse "object being deleted" with "source file that owns fatal cleanup policy."

3. New `ApplicationFatalCleanup.cpp` / `FatalLoadCleanup.cpp` grouping - rejected for now.
   - Likely contents if created: `0x00467380` DestroyDATFileMgr, `0x004673a0` DestroyExceptionHandler, and `0x004673c0` DestroyKeySpeedMgr-like helper. Possibly no broader contents.
   - Evidence for: the three helper bodies are same-shaped deleting wrappers over process singletons.
   - Evidence against: the immediate cluster also includes `0x004673e0` `g_pApplication` accessor, `0x004673f0` callback constant helper, [UID:0002VL] PasswordError descriptor helper at `0x00467400`, and Application-owned [UID:0000YX] `LoadIndexedDATSeries`. That is not a clean standalone fatal cleanup translation unit. B001-011 already rejected a broader fatal-dialog source file for the nearby fatal helper.
   - Conclusion: no new file should be created for this target. Application is the stronger existing source root.

4. Image-library owners - rejected as consumers.
   - For: the direct call sites live in MapTileImageLib, HumanImageLib, StaticObjImageLib, EffectObjImageLib, and NewHumanImageLib resource loaders.
   - Against: the helper is shared across several image-library modules, deletes global manager singletons they do not own, and pairs with crash-handler cleanup before fatal error reporting.
   - Conclusion: image libraries consume the shared cleanup helper on fatal load failure; they do not own it.

5. [UID:0000PA] `WinMain` - rejected for this target.
   - For: neighboring `0x004673c0` KeySpeedMgr deletion helper has a WinMain caller.
   - Against: [UID:0000YV] itself has no WinMain caller, while the 22-call fatal resource-load pattern is broader Application startup policy. WinMain is an entry-point source, not the best parent for shared image-resource failure cleanup.

### Files Updated

- `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`: assigned to [UID:0000HG] Application, score raised to `88/91`, ranked ownership evidence added.
- `by-file/Application.md`: added [UID:0000YV] as Application-owned fatal-load cleanup helper, with B001-012 evidence and migration note.
- `by-file/DATFileMgr.md`: removed the helper from proposed contents and clarified object/singleton ownership versus helper-body ownership.
- `by-memory/-coverage-report.md`: synced [UID:0000YV] row to `88%`, Application assigned wording.
- `by-file/-coverage-report.md`: synced Application and DATFileMgr summaries.
- `by-item/DestroyDATFileMgr_467380.md`: synced source-family note to Application while keeping the canonical autogen assignment on the by-memory page.
- `by-item/-coverage-report.md`: synced [UID:0000UF] row wording.

### Validation

Targeted validator scans were run with `python tools/validator.py --mode file --file <path> --apply` from `source-3/project-documentation` on:

- `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`
- `by-file/Application.md`
- `by-file/DATFileMgr.md`
- `by-memory/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-item/DestroyDATFileMgr_467380.md`
- `by-item/-coverage-report.md`

All scans exited `0`. The first scan updated [UID:0000YV] completion/confidence to `88/91`, changed autogen parent from blank to `0000HG`, rebuilt validator autogen registry state, and normalized several UID link labels in the target page. `auto-generated/-ag-memory-coverage.md` now reports [UID:0000YV] as `assigned`, parent `0000HG`, destination `auto-generated/NexusTK/app/Application.cpp`.

### Final Recommendation

Accept [UID:0000YV] as Application-owned. The best reconstruction is a shared Application/startup fatal-load cleanup helper, probably declared so image-library startup code can call it. Do not move `g_pDATFileMgr` or the DAT manager implementation out of [UID:0000IO] `DATFileMgr`. The only follow-up is to review [UID:0000YW] and unsplit `0x004673c0` with the same evidence pattern; neither blocks this assignment.
