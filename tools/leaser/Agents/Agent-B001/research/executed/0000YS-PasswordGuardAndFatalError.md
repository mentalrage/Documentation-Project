# 0000YS PasswordGuardAndFatalError

## Finalized Report / Current Recommendation

- Target: [UID:0000YS] `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`
- Assignment: B001-011 from `Supervisor_notes.md`, classification `reviewed-85-but-ownership-unknown-under-review`
- Current recommendation: keep `0000YS` as a reviewed non-reconstructable/non-emitting mixed address container with blank parent. Exact children and neighboring exact pages carry the real source ownership; [UID:0002VI] `FatalErrorDialogAndBreak` is now assigned to [UID:0000HG] `Application`.
- Recommended status/classification: `COMPLETION:87`, `CONFIDENCE:90`, `RECONSTRUCTABLE:FALSE`, blank `AUTOGEN_PARENT_UID`.
- Confidence: high, 90/100 for the aggregate/container decision. IDA MCP confirms the child functions, additional physically contained owners, fatal-helper caller/callee chain, and absence of one direct source owner for the whole interval.
- Concrete next action for A-agents/supervisor: accept the aggregate as a split/index container; use the exact child ownership map below. No new broad `PasswordGuardAndFatalError.cpp` or `FatalError.cpp` source owner is recommended.
- Report state: final for B001-011 after targeted validator scans.

Key recommendations:

- [UID:0002VG] `0x004657d0-0x00465827.SetProtectedPasswordToken` remains assigned to [UID:0000MG] `PasswordGuard`.
- [UID:0002VH] `0x00465890-0x00465ae2.ValidateChatInputOrThrowPasswordError` remains assigned to [UID:0000MG] `PasswordGuard`.
- [UID:0002VI] `0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak` is assigned to [UID:0000HG] `Application`, not left unresolved.
- [UID:0002VJ], [UID:0002VK], and [UID:0002VL] remain direct [UID:0000A8] `PasswordError` children, with [UID:0000J5] `Error` as the class/file parent chain. `0002VK` was raised to `85/88`.
- No new `FatalError.cpp` or broad `PasswordGuardAndFatalError.cpp` owner is recommended.

## Supporting Research

### Scope

B001-011 audited the mixed physical interval `0x004657d0-0x00467406` and exact child pages `0002VG`, `0002VH`, `0002VI`, `0002VJ`, `0002VK`, and `0002VL`. Existing docs were treated as hypotheses. IDA MCP evidence was used as the primary basis for ownership inference.

No lease commands were used because the user explicitly kept the temporary lease override active.

### Documentation Repairs Performed

- Repaired [UID:0000YS] `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md` to `87/90`, `RECONSTRUCTABLE:FALSE`, blank parent, and non-emitting mixed-container language.
- Repaired [UID:0002VI] `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md` to `87/90` and `AUTOGEN_PARENT_UID:0000HG`.
- Raised [UID:0002VK] `by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md` from `84/88` to `85/88` with explicit score rationale.
- Updated [UID:0000HG] `Application` to list `FatalErrorDialogAndBreak` as an Application-local/global fatal startup helper.
- Updated [UID:0000J5] `Error` to reject `FatalErrorDialogAndBreak` as Error-owned and record the B001-011 Application decision.
- Updated `by-memory/-coverage-report.md` and `by-memory/-ignored.md` so the manual rows match the pages and generated coverage.
- Audit follow-up: updated `by-file/-coverage-report.md` rows for [UID:0000HG] `Application` and [UID:0000J5] `Error` so the file-level coverage summaries also reflect the B001-011 fatal-helper ownership decision.

### Current IDA MCP Facts

Fresh IDA MCP checks during B001-011 confirmed:

- `sub_4657D0` is `0x004657d0-0x00465827`, one direct caller at `0x004fb60b` in `sub_4FB2D0`, and only `_wcsncpy_s` as an external callee.
- `sub_465890` is `0x00465890-0x00465ae2`, with 13 outbound-input callers, `PASS_ENG.STR` at `0x00612e8c`, DAT line-reader helper calls, `PasswordError` construction at `0x00467160`, and `_CxxThrowException`.
- `sub_465CB0` is `0x00465cb0-0x00465ce0`, a fatal dialog helper that calls `sub_4673E0`, `sub_4651D0`, `MessageBoxW`, `PostQuitMessage`, and `__loaddll`, then hits `int 3`.
- `sub_4673E0` is `0x004673e0-0x004673e6` and returns `dword_67AB1C`, documented as [UID:000294] `g_pApplication`.
- `sub_4651D0` is `0x004651d0-0x004651d7` and returns `Application + 0x828`, documented as [UID:0002GN] `ApplicationGetMainWindowHandle`.
- The fatal caption at `0x00612ea8` decodes as `Aborted` and has one data xref at `0x00465cb5` inside `sub_465CB0`.
- `sub_467160` is `0x00467160-0x00467181`, called once from `sub_465890` at `0x00465abe`, calls `MyError` constructor `0x004a67a0`, and stores `PasswordError::vftable` at `0x006125a8`.
- `sub_467300` is `0x00467300-0x00467338`, has no direct code callers, is referenced by the first slot of `PasswordError` vtable data at `0x006125a8`, calls `0x004a6860`, delete helper `0x004f4ac0`, and guard-check no-op.
- `sub_467400` is `0x00467400-0x00467406`, has no direct code callers, and returns descriptor data at `0x006125bc`, which decodes as `Password Warning`.

### Fatal Helper Caller Evidence

IDA MCP reports 15 direct call sites to `0x00465cb0`:

- `0x00463964` in `Application__Constructor`.
- Nine sites inside `Application::Initialize` / `sub_4639D0`: `0x004647b2`, `0x0046488a`, `0x004648b7`, `0x004648e4`, `0x00464911`, `0x0046493e`, `0x0046496b`, `0x00464998`, and `0x004649c5`.
- `0x004674e8` inside [UID:0000YX] `LoadIndexedDATSeries`, which is itself attached to [UID:0000HG] `Application` and has 19 callers all inside `Application::Initialize`.
- Four sites inside [UID:0002BR] `StructuredHostPortIdLauncherParser`: `0x00491961`, `0x004919c9`, `0x00491a35`, and `0x00491ac1`.

### Ranked Ownership Analysis For FatalErrorDialogAndBreak

1. [UID:0000HG] `Application` / `app/Application.cpp` - selected.
   - For: `FatalErrorDialogAndBreak` loads `g_pApplication` through `sub_4673E0`, gets the main window through `ApplicationGetMainWindowHandle`, has ten direct Application constructor/Initialize callers, and has one more caller through Application-owned `LoadIndexedDATSeries`. The behavior is application-fatal UX and shutdown control, not error-hierarchy object formatting.
   - Against: four `RegistryConfig` launcher parser call sites use it as a shared fatal utility, so it is not exclusive to Application callers. This is normal for a file-local/global fatal helper exposed to startup/config code and is weaker counter-evidence than the callee/data dependency on `Application`.

2. New tiny `FatalError.cpp` / fatal-dialog source file - rejected for now.
   - For: the helper is a free function, has cross-module consumers, and the source-facing name could have been `FatalError`.
   - Against: likely contents are too narrow. B001-011 did not find a broader fatal-dialog family; the helper depends directly on `g_pApplication` and `ApplicationGetMainWindowHandle`, and nearby fatal-load cleanup helpers already fit Application/resource-failure handling. Creating a new file would add structure without improving the source-owner model.
   - Proposed contents if created anyway: only `0x00465cb0-0x00465ce0` and possibly declarations for fatal-load cleanup helpers `0x00467380`, `0x004673a0`, and `0x004673c0`; those helpers already have stronger Application/resource-failure adjacency and are not a coherent independent fatal-dialog module.

3. [UID:0000J5] `Error` / `util/Error.cpp` - rejected.
   - For: the helper displays an error/fatal message and old docs listed it as an app/error split candidate.
   - Against: the body does not construct or use the `Error` hierarchy; it calls Win32 `MessageBoxW`, `PostQuitMessage`, and application singleton/window helpers. The `Error` file owns `PasswordError` and generic wrapper classes, not application shutdown UI.

4. [UID:0000MG] `PasswordGuard` - rejected.
   - For: physical address proximity inside the historical aggregate.
   - Against: no password-token globals, no `PasswordError` throw path, and no PasswordGuard callers. Its callers are Application startup/resource/config failure paths.

5. [UID:0002BR] `RegistryConfig` / launcher parser - rejected as owner.
   - For: four fatal-helper call sites are in the structured launcher parser.
   - Against: RegistryConfig is a consumer only. The fatal helper uses Application singleton/window state and is also called heavily by Application initialization.

### Aggregate Ownership Analysis

The physical interval cannot be assigned to one owner:

- Password token helper code and token globals belong to `PasswordGuard`.
- `PasswordError` constructor/destructor/descriptor belong to `PasswordError` and the shared `Error` hierarchy.
- `FatalErrorDialogAndBreak` belongs to `Application`.
- The same interval also physically contains other Application methods, Application/window helpers, FunctionObject callback support, and fatal-load cleanup glue documented by neighboring pages.

Therefore `0000YS` is best modeled like other reviewed mixed address containers: non-reconstructable/non-emitting, parent blank, with exact children and neighboring owner pages carrying the direct ownership.

### Child Map

| Item | Before / stale state | Final state | Direct owner |
| --- | --- | --- | --- |
| [UID:0000YS] aggregate | Manual coverage row still said `reconstructable : 86%` and unresolved fatal ownership; page state was inconsistent during the resumed pass. | `87/90`, `RECONSTRUCTABLE:FALSE`, parent blank, ignored/non-emitting mixed container. | None; split/index container only. |
| [UID:0002VG] setter | Page already `85/90`; manual coverage row still said `84%`. | `85/90`, assigned. | [UID:0000MG] `PasswordGuard`. |
| [UID:0002VH] validator | Page already `85/88`; manual coverage row still said `84%`. | `85/88`, assigned. | [UID:0000MG] `PasswordGuard`. |
| [UID:0002VI] fatal helper | `86/88`, parent blank, ownership unresolved between Application/Error/tiny fatal helper. | `87/90`, assigned. | [UID:0000HG] `Application`. |
| [UID:0002VJ] constructor | `86/90`, assigned. | Unchanged. | [UID:0000A8] `PasswordError`. |
| [UID:0002VK] scalar deleting destructor | `84/88`, assigned but below completion gate. | `85/88`, assigned, score rationale added. | [UID:0000A8] `PasswordError`. |
| [UID:0002VL] descriptor accessor | `88/92`, assigned. | Unchanged. | [UID:0000A8] `PasswordError`. |

### Files Changed

Project documentation changed by B001-011:

- `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`
- `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`
- `by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md`
- `by-file/Application.md`
- `by-file/Error.md`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`

Validator-managed side effects observed after `--apply`:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-file-coverage.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`

### Validation

Ran targeted validator scans with `--apply` for:

- `by-memory/0x004657d0-0x00467406.PasswordGuardAndFatalError.md`
- `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`
- `by-memory/0x00467300-0x00467338.PasswordErrorScalarDeletingDestructor.md`
- `by-file/Application.md`
- `by-file/Error.md`
- `by-file/-coverage-report.md`
- `by-memory/-coverage-report.md`
- `by-memory/-ignored.md`

B001-011 audit follow-up additionally reran targeted validator scans with `--apply` for:

- `by-file/-coverage-report.md`
- `by-file/Application.md`
- `by-file/Error.md`

All scans exited `0`. Generated memory coverage now confirms:

- [UID:0000YS] is `not_reconstructable`, parent blank.
- [UID:0002VI] is `assigned` to `0000HG`, output path `auto-generated/NexusTK/app/Application.cpp`.
- [UID:0002VK] is `assigned` to `0000A8`, output path `auto-generated/NexusTK/util/Error.cpp`.

### Remaining Follow-Up

No blocker remains for B001-011. Optional future split work: if the supervisor wants to retire the broad physical island completely, create exact pages for remaining in-range Application/window/callback helper starts such as `0x00465af0`, `0x00465ce0`, `0x00465d30`, `0x00465ee0`, `0x00465f20`, `0x00467190`, `0x004673c0`, `0x004673e0`, and `0x004673f0`. This does not block the current aggregate decision because the reviewed container is non-emitting and the requested exact children now carry direct owners.
