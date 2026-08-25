** TARGET-REPORT-UID:0000ST **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
## Finalized Report / Current Recommendation

- Target: [UID:0000ST] `by-global/g_screenHeight.md`
- Related sibling updated in same ownership decision: [UID:0000SU] `by-global/g_screenWidth.md`
- Source queue row: `tools/leaser/Agents/Supervisor_notes.md:60`, `reviewed-85-but-ownership-unknown-under-review`, B001-007.
- Current recommendation: assign the paired display-size globals `g_screenHeight` and `g_screenWidth` to existing [UID:0000HG] `by-file/Application.md` / `auto-generated/NexusTK/app/Application.cpp`.
- Recommended status/classification: resolved by global-to-file assignment; keep exact storage children [UID:0001OI] and [UID:0001OG] unassigned in generated memory coverage because the direct semantic parent is the by-global item and generated memory coverage rejects by-global parents.
- Confidence: high, 88/100 for `Application.cpp` as the best source-owner reconstruction; docs now score `g_screenHeight` `88/91`, `g_screenWidth` `88/91`, and parent `Application` remains above gate at `86/90`.
- Concrete next action: supervisor/A-agents can close B001-007 as assigned to `0000HG`; do not create a new display-globals source file. Future C++ emission should still audit exact type/signedness and source spelling before declaring the variables.
- Report state: final for B001-007. No lease operations were performed per temporary supervisor override. Collision risk observed: low; changed files were targeted to the assigned global, the paired sibling, exact storage pages, `Application`, and stale manual coverage rows.

## Supporting Research

### Scope

B001-007 asked for ownership inference for [UID:0000ST] `g_screenHeight`, treating existing documentation as hypotheses rather than proof. Because IDA shows `g_screenHeight` is inseparable from [UID:0000SU] `g_screenWidth`, I researched and updated the pair together.

The main question was whether the source owner is an existing file/class such as `Application`, `ScreenPane`, `RegistryConfig`, a render/UI module, or a new narrow globals source file.

### Binary Facts From IDA MCP

Fresh IDA MCP `py_eval` on 2026-06-10:

- `g_screenHeight`: IDA name `word_66DA98`, address `0x0066da98`, item head `0x0066da98`, item size `2`, initial word value `0x0300` / `768`.
- `g_screenWidth`: IDA name `word_66DA94`, address `0x0066da94`, item head `0x0066da94`, item size `2`, initial word value `0x0400` / `1024`.
- Xrefs: `word_66DA98` has `96` xrefs across `47` functions; `word_66DA94` has `98` xrefs across `48` functions.
- Writes: no write-like operand-zero xrefs were found for either word. The values behave like compile-time initialized `.data` defaults, not mutable runtime configuration.
- Local bytes around the pair: `0x0066da90` neighborhood includes `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00`.
- Nearby data heads confirm strict boundaries: `word_66DA94` at `0x0066da94`, `byte_66DA96`, `byte_66DA97`, `word_66DA98` at `0x0066da98`, zero padding at `0x0066da9a`, then `word_66DA9C` and `word_66DAA0` with value `48`.

Key Application instructions:

- `Application__Constructor` reads the pair at `0x004633b7` (`movsx eax, word_66DA98`) and `0x004633be` (`movsx ecx, word_66DA94`), then stores them into Application fields at `0x004633c9` (`[edi+0A60h]`) and `0x004633cf` (`[edi+0A64h]`).
- `Application::Initialize` (`sub_4639D0`) updates the same Application fields from current window dimensions at `0x004643fc` / `0x00464402` when available, but falls back to the globals at `0x0046440a` / `0x00464421` before `call sub_4F0350` at `0x00464434`.
- The same initialize path passes the pair into `ScreenPane::ScreenPane`: `0x004645d6` reads height, `0x004645dd` reads width, then pushes them at `0x004645e6` / `0x004645e7` before `call sub_556910` at `0x004645ea`.
- `ScreenPane::ScreenPane` (`sub_556910`) stores only constructor arguments into instance fields: `0x005569d4`/`0x005569d8`, `0x005569df`/`0x005569e3`, and `0x005569ea`/`0x005569ee`. This makes ScreenPane a consumer of Application-provided dimensions, not the strongest declaration owner.

Other important consumer clusters:

- Application coordinate helpers `sub_465690` and `sub_465730` read both globals and scale between logical screen coordinates and current Application fields.
- `RegistryConfig::InitializeDefaults` (`sub_48EED0`) reads both words many times and uses half-width/half-height centered defaults for rectangles. This is heavy use, but it is default-layout consumption.
- Render/screenshot/UI consumers read the pair for layout and surface sizing, including `sub_557140`, `sub_557AA0`, and other broad pane/layout helpers.

### Documentation Evidence

Existing docs were used as prior hypotheses only:

- `by-global/g_screenHeight.md` and `by-global/g_screenWidth.md` already documented the display-width/height role and sibling relationship, but previously stopped at "ownership unknown."
- `by-file/Application.md` already named Application as a plausible consumer/owner lead. IDA MCP now confirms the stronger ownership chain: constructor base-dimension field initialization, fallback main-window creation, ScreenPane construction, and coordinate helpers.
- `by-file/ScreenPane.md` and ScreenPane-related docs are useful leads, but IDA contradicts ScreenPane ownership because Application passes dimensions into ScreenPane instead of ScreenPane reading the globals itself at construction.
- `by-file/RegistryConfig.md` / `RegistryConfigInitializeDefaults` are useful leads because of many reads, but IDA leaves them as consumer/default-layout evidence rather than declaration evidence.
- Generated global coverage after validation now shows `0000ST` and `0000SU` assigned to `0000HG` / `auto-generated/NexusTK/app/Application.cpp`.
- Generated memory coverage still shows [UID:0001OI] and [UID:0001OG] unassigned, intentionally. Their by-memory pages keep blank `AUTOGEN_PARENT_UID` because generated memory coverage rejects by-global parents; the by-global docs now carry the source-file assignment.

### Neighboring Data And New-File Scope Test

A new `DisplayGlobals.cpp`, `ScreenDimensions.cpp`, or `ApplicationDisplayDefaults.cpp` was considered. The only items that would clearly belong in such a narrow grouping are:

- [UID:0000SU] `by-global/g_screenWidth.md`, `0x0066da94`, value `1024`.
- [UID:0000ST] `by-global/g_screenHeight.md`, `0x0066da98`, value `768`.
- Exact storage children [UID:0001OG] `0x0066da94-0x0066da96.g_screenWidth.md` and [UID:0001OI] `0x0066da98-0x0066da9a.g_screenHeight.md`.

Nearby items do not support a broader display-globals file:

- [UID:0002CF] `g_movementSubstepScale` / [UID:00027F] storage at `0x0066da96` is a one-byte movement substep scalar now assigned to [UID:0000L3] `MapPane`; IDA/documentation evidence separates it by role, xrefs, and owner.
- [UID:0000SW] `g_useEpfAssets` / [UID:0001OH] storage at `0x0066da97` is a broad EPF/current-layout selector with hundreds of xrefs and unresolved source ownership; it is not a screen dimension.
- [UID:00027G] `0x0066da9a-0x0066da9c.DisplayDimensionPadding` is ignored padding, not reconstructable source data.
- [UID:0000T7] `MapTilePixelDimensions`, with [UID:0001OJ] `word_66DA9C` and [UID:0001OK] `word_66DAA0`, is a 48x48 map-tile dimension pair used by map/render/object placement. It is adjacent but semantically distinct from 1024x768 screen defaults.
- [UID:00027I] `0x0066daa2-0x0066daec.MapPaneCoordinateClampConstants` starts after the tile-height word and belongs to map coordinate/clamp behavior, not display defaults.

Inference: a new file would be a narrow two-global grouping only. That is weaker than assigning the pair to existing `Application.cpp`, because IDA shows Application is the first lifecycle owner and the consumer that turns these compile-time defaults into Application base-dimension state.

### Ranked Candidate Owners

1. [UID:0000HG] `Application` / `Application.cpp` - accepted.
   Evidence for: Application constructor copies the global pair into Application fields; Application initialization uses the pair to create the fallback main window; Application passes the pair into ScreenPane; Application coordinate helpers use the pair as base logical dimensions. The parent file already clears the gate and is the narrowest existing lifecycle owner.
   Evidence against: no recovered PDB/source declaration; no write/initializer function names the variables; exact source spelling and signedness remain unresolved.
   Result: strongest defensible inference and now applied.

2. New narrow display-dimensions globals file - rejected.
   Evidence for: the pair is adjacent, same type/role, same 1024x768 default, and both are read together across the program.
   Evidence against: no broader file contents beyond the two globals; adjacent data belongs to other owners; Application has direct lifecycle and base-state evidence. Creating a file would add structure without IDA-backed module boundaries.
   Result: do not create a new owner/file.

3. [UID:0000NB] `ScreenPane` / `ScreenPane.cpp` - rejected.
   Evidence for: ScreenPane construction receives width/height and stores screen backing fields.
   Evidence against: IDA shows ScreenPane receives constructor arguments from Application rather than reading the globals; ownership signal points upstream.
   Result: consumer/instance owner only.

4. [UID:0000N4] `RegistryConfig` / `RegistryConfig.cpp` - rejected.
   Evidence for: many reads in `RegistryConfig::InitializeDefaults`; visible centered default rectangle computations.
   Evidence against: use is default layout/config consumption; no startup declaration/initialization evidence; not the first lifecycle point.
   Result: consumer only.

5. Render, screenshot, pane, and UI files - rejected.
   Evidence for: broad read xrefs across UI/render/screenshot paths.
   Evidence against: read-only consumption, no writes, no early lifecycle field initialization, no evidence of declaration ownership.
   Result: consumers only.

### Documentation Changes Executed

Updated:

- `by-global/g_screenHeight.md`: completion/confidence raised to `88/91`, `AUTOGEN_PARENT_UID:0000HG`, Application owner evidence and assignment gate added.
- `by-global/g_screenWidth.md`: completion/confidence raised to `88/91`, `AUTOGEN_PARENT_UID:0000HG`, paired owner evidence and assignment gate added.
- `by-memory/0x0066da98-0x0066da9a.g_screenHeight.md`: kept blank parent, clarified by-global-to-Application path and generated memory limitation.
- `by-memory/0x0066da94-0x0066da96.g_screenWidth.md`: kept blank parent, clarified by-global-to-Application path and generated memory limitation.
- `by-file/Application.md`: upgraded the display-dimension declaration note from a plausible lead to a B001-007 IDA-backed file-level ownership decision.
- `by-global/-coverage-report.md`: rows for `0000ST` and `0000SU` now show `88%` and Application owner inference.
- `by-memory/-coverage-report.md`: rows for `0001OI` and `0001OG` now match their blank-parent exact-storage behavior while documenting the by-global-to-Application source path.

Validator performed:

- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-global\g_screenHeight.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-global\g_screenWidth.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0066da98-0x0066da9a.g_screenHeight.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\0x0066da94-0x0066da96.g_screenWidth.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-file\Application.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-global\-coverage-report.md --apply`
- `python source-3\project-documentation\tools\validator.py --mode file --file source-3\project-documentation\by-memory\-coverage-report.md --apply`

Post-resume verification on 2026-06-10:

- Confirmed this report exists at `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\0000ST-g_screenHeight.md`.
- Cleaned stale historical wording in `g_screenHeight` and `g_screenWidth` that still described the pages as unassigned, while preserving the intended blank-parent behavior for exact memory children.
- Re-ran targeted validator `--apply` scans for `by-global/g_screenHeight.md` and `by-global/g_screenWidth.md`; both completed with `ok: 1` and generated coverage no-op.

Post-validation generated evidence:

- `auto-generated/-ag-global-coverage.md` lists [UID:0000ST] and [UID:0000SU] as assigned to `0000HG` with path `auto-generated/NexusTK/app/Application.cpp`.
- `auto-generated/-ag-memory-coverage.md` still lists [UID:0001OI] and [UID:0001OG] as unassigned, matching the intended exact-storage behavior.

### Remaining Uncertainty

The remaining uncertainties are not blockers to source-owner assignment:

- Original source spelling is not proven. `g_screenHeight` and `g_screenWidth` remain descriptive project names based on role and use.
- Exact C++ type is not proven. Use sites promote as signed and unsigned words; final code should choose a source-compatible type after a broader declaration/type audit.
- The declaration may have been in `Application.cpp` or a header/companion included by Application. IDA cannot distinguish that without debug/source metadata. The best source-owner reconstruction is still `Application.cpp` because the existing by-file model needs a concrete owner and Application is the direct lifecycle owner.

### Final Recommendation

Keep the executed assignment: [UID:0000ST] `g_screenHeight` and [UID:0000SU] `g_screenWidth` should be owned by [UID:0000HG] `Application`. Do not create a new source file for these globals. Keep the exact by-memory children unassigned in generated memory coverage until by-global memory parenting is supported; the by-global pages are now the assigned source-level objects.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000ST-g_screenHeight.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0000ST"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
