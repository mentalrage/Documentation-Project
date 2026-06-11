## Finalized Report / Current Recommendation

- Target: [UID:0000YW] `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`
- Current recommendation: assign the exact helper to [UID:0000HG] `by-file/Application.md` as the paired Application/startup fatal-load cleanup wrapper for the active exception handler.
- Recommended status/classification: reconstructable, assigned, source-authored global/helper function; parent [UID:0000HG] `Application`.
- Confidence: high, 91/100 for the exact helper assignment. The behavior/range/caller pattern are IDA-confirmed; exact original helper spelling remains inferred.
- Concrete next action for A-agents/supervisor: accept the B001-013 parent change for [UID:0000YW]; keep [UID:0000QN] `g_pCrashTarget`, the `ExceptionHandler` class, and normal crash-handler lifecycle under [UID:0000J8] `ExceptionHandler`; schedule follow-up for the adjacent unsplit `0x004673c0` KeySpeedMgr deletion helper.
- Report status: final. No leases were created per the active temporary lease override. No collision risk was observed.

## Supporting Research

### Target Summary

[UID:0000YW] covers `0x004673a0-0x004673b1`, IDA `sub_4673A0`, a `0x11` byte helper. Before B001-013 it was `87/90`, reconstructable, and parent-blank because prior docs stopped at "ExceptionHandler object owner versus Application fatal-load cleanup" uncertainty.

B001-013 changed the page to `88/91` and set `AUTOGEN_PARENT_UID:0000HG`.

### Binary Facts From IDA MCP

- IDB: `NexusTK.exe`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- `lookup_funcs` confirms `sub_4673A0` at `0x004673a0`, size `0x11`. Neighbor helpers are `0x00467380`, `0x004673c0`, `0x004673e0`, `0x004673f0`, `0x00467400`, and `0x00467410`.
- Exact disassembly of `0x004673a0`: load `dword_67AB34`, null-check it, load vtable slot zero, push delete flag `1`, call the indirect deleting destructor, and return.
- The helper does not clear `g_pCrashTarget`. Normal singleton lifecycle xrefs remain in ExceptionHandler code: constructor write `0x004ab499`, raw destructor/reset clear `0x004ab4ff`, `TopLevelExceptionFilter` read `0x004ab83a`, and scalar deleting destructor clear `0x004ac879`.
- `xrefs_to 0x0067ab34` reports nine data refs: Application cleanup `0x00464c5e`, timer/crash-text path `0x00466e70`, this helper `0x004673a0`, `Crasher` flag write `0x0049bb60`, the ExceptionHandler lifecycle refs above, and startup/account dialog crash-report sender path `0x005101e2`.
- Read-only IDAPython xref audit confirms 22 direct calls to `0x004673a0`: `0x004d197e`, `0x004d43ac`, `0x004d43f0`, `0x004d4434`, `0x004d4478`, `0x004d44bc`, `0x004d4500`, `0x004d4544`, `0x004d4583`, `0x004d45cb`, `0x004d4613`, `0x004d465b`, `0x004d46a3`, `0x004d46e7`, `0x004d472b`, `0x004d476f`, `0x004d47b0`, `0x004d4a92`, `0x004d4aaa`, `0x004dd1b8`, `0x004de02e`, and `0x004e19a5`.
- Every `0x004673a0` caller immediately follows a [UID:0000YV] `DestroyDATFileMgr` call five bytes earlier.
- The 22 callers collapse to five fatal image/resource loader functions: `0x004d1860`, `0x004d2720`, `0x004dcf60`, `0x004ddf60`, and `0x004e1800`.
- Representative strings in those caller functions include `Error on Tile File!`, `Error on Body File!`, `Error on Sword File!`, `Error on Spear File!`, `Error on Bow File!`, `Error on Fan File!`, `Error on Shield File!`, `Error on Arrow File!`, `Error on Face File!`, `Error on Hair File!`, `Error on Acc1 File!`, `Error on Acc2 File!`, `Error on Helmet File!`, `Error on Mantle File!`, `Error on Necklace File!`, `Error on Shoe File!`, `Error on Coat File!`, `Error on Head File!`, `Error on TileC File!`, `Error on Effect File!`, and `Error on ACC2DRW table!`.
- Neighbor audit: `0x00467380` is the paired DAT manager delete wrapper assigned to Application by B001-012; `0x004673c0` is a same-shaped `g_pKeySpeedMgr` delete wrapper with only a WinMain/updater early-exit caller; `0x004673e0` returns `g_pApplication`; `0x00467400` is a PasswordError descriptor helper; [UID:0000YX] `0x00467410-0x004674ed.LoadIndexedDATSeries` is Application-owned startup DAT policy.

IDA evidence artifact:
`tools/leaser/Agents/Agent-B001/research/scratch/0000YW-ida-callsite-evidence-raw.json`

### Documentation Evidence Treated As Hypotheses

- [UID:0000YW] already documented the delete behavior, 22 paired callers, and ExceptionHandler/Application ambiguity. B001-013 confirms the behavior and caller facts but rejects the passive unassigned conclusion.
- [UID:0000HG] `Application` already accepted the sibling [UID:0000YV] as Application-owned fatal-load cleanup in B001-012. B001-013 confirms [UID:0000YW] is the immediate paired call in the same 22 failure sites.
- [UID:0000J8] `ExceptionHandler` and [UID:0000QN] `g_pCrashTarget` correctly own the class/global lifecycle. B001-013 confirms that ownership but treats it as object ownership, not direct ownership of this external fatal-unwind helper.
- Image-library docs are caller/consumer evidence only. The shared helper is used by several render/image loader modules and is not local to any one of them.

### Ranked Ownership Analysis

1. [UID:0000HG] `Application` - accepted.
   - For: exact caller pattern matches Application-owned [UID:0000YV]; every caller is a fatal resource/image load exit; Application owns startup/shutdown/fatal UX policy; surrounding helper island includes `g_pApplication` accessor and Application-owned `LoadIndexedDATSeries`.
   - Against: direct callers are image-library loader functions rather than `Application::Initialize` itself; the helper body does not read `g_pApplication`.
   - Conclusion: strongest direct source parent. The helper is shared fatal-startup cleanup policy, not ordinary crash-handler teardown.

2. [UID:0000J8] `ExceptionHandler` - rejected as direct helper owner, retained as object/global owner.
   - For: helper deletes `g_pCrashTarget`; ExceptionHandler owns the class, singleton pointer, top-level filter, crash-report helpers, and destructor lifecycle.
   - Against: no ExceptionHandler-cluster callers; helper lives outside the `0x004ab480-0x004ac89a` diagnostics range; it does not clear the singleton; every use is paired with unrelated DAT manager cleanup at fatal image/resource-load exits.
   - Conclusion: assigning this helper to ExceptionHandler would confuse "object being deleted" with "source file that owns fatal cleanup policy."

3. New `ApplicationFatalCleanup.cpp` / `FatalLoadCleanup.cpp` grouping - rejected for now.
   - Likely contents if created: `0x00467380` DestroyDATFileMgr, `0x004673a0` DestroyExceptionHandler, and possibly `0x004673c0` DestroyKeySpeedMgr-like helper.
   - Evidence for: the three helper bodies are same-shaped deleting wrappers over process singletons.
   - Evidence against: the immediate cluster also includes `0x004673e0` `g_pApplication` accessor, `0x004673f0` callback constant helper, [UID:0002VL] PasswordError descriptor helper at `0x00467400`, and Application-owned [UID:0000YX] `LoadIndexedDATSeries`. That is not a clean standalone fatal cleanup translation unit.
   - Conclusion: no new file should be created for this target. Application is the stronger existing source root.

4. Image-library owners - rejected as consumers.
   - For: the direct call sites live in MapTileImageLib, HumanImageLib, StaticObjImageLib, EffectObjImageLib, and NewHumanImageLib resource loaders.
   - Against: the helper is shared across several image-library modules, deletes a global diagnostics singleton they do not own, and pairs with DAT manager cleanup before fatal error reporting.
   - Conclusion: image libraries consume the shared cleanup helper on fatal load failure; they do not own it.

### Files Updated

- `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`: assigned to [UID:0000HG] Application, score raised `87/90 -> 88/91`, ranked ownership evidence added.
- `by-item/DestroyExceptionHandler_4673A0.md`: score raised `84/88 -> 85/90`, synced to Application source-family wording while leaving canonical autogen attachment on the by-memory page.
- `by-file/Application.md`: added [UID:0000YW] as the paired Application-owned fatal-load cleanup helper.
- `by-file/ExceptionHandler.md`: removed [UID:0000YW] from direct likely contents and documented it as related Application cleanup while keeping class/global lifecycle here.
- `by-global/g_pCrashTarget.md`: clarified that the helper deletes the active object but does not move the global's source ownership out of ExceptionHandler.
- `by-memory/-coverage-report.md`: synced [UID:0000YW] row to `88%`, Application assigned wording.
- `by-file/-coverage-report.md`: synced Application and ExceptionHandler summaries.
- `by-item/-coverage-report.md`: synced [UID:0000UG] row wording.
- `by-global/-coverage-report.md`: synced [UID:0000QN] row wording and stale score text.

### Validation

Targeted validator scans were run with `python tools/validator.py --mode file --file <path> --apply` from `source-3/project-documentation` on:

- `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`
- `by-item/DestroyExceptionHandler_4673A0.md`
- `by-file/Application.md`
- `by-file/ExceptionHandler.md`
- `by-global/g_pCrashTarget.md`
- `by-memory/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-item/-coverage-report.md`
- `by-global/-coverage-report.md`

All scans exited `0`. The first scan updated [UID:0000YW] completion/confidence to `88/91`, changed autogen parent from blank to `0000HG`, rebuilt validator autogen registry state, and refreshed generated autogen coverage. `auto-generated/-ag-memory-coverage.md` now reports [UID:0000YW] as `assigned`, parent `0000HG`, destination `auto-generated/NexusTK/app/Application.cpp`.

### Final Recommendation

Accept [UID:0000YW] as Application-owned. The best reconstruction is a shared Application/startup fatal-load cleanup helper, probably declared near the sibling [UID:0000YV] helper so image-library startup code can call both. Do not move `g_pCrashTarget`, `ExceptionHandler`, or crash-report implementation out of [UID:0000J8] `ExceptionHandler`. The main remaining follow-up is the adjacent `0x004673c0` `g_pKeySpeedMgr` delete wrapper, which likely needs its own exact documentation and Application/WinMain ownership review.
