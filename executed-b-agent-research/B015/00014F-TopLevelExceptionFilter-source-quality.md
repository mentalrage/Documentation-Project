** TARGET-REPORT-UID:00014F **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B015 Source-Quality Report: [UID:00014F] TopLevelExceptionFilter

## Assignment Scope

- Target: [UID:00014F] `TopLevelExceptionFilter`
- Target doc: `source-3/project-documentation/by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/00014F-TopLevelExceptionFilter-source-quality.md`
- Mode: B-agent source-quality / heuristic research report only.

No `by-*` target/support documentation, generated output, or `by-memory/-coverage-report.md` was edited for this report. The earlier B015 report `00013G-EncoderWriteShort-source-quality.md` remains in place and was not overwritten or moved.

Current-session IDA MCP at `127.0.0.1:13337` was unavailable, so this report relies on current documentation, prior IDA-backed target/support pages, and accepted/executed B-agent research already incorporated into the docs. Generated output was checked only as an owner/emitter route consequence, not as behavioral evidence.

## Short Recommendation

[UID:00014F] is first-draft C++ ready on its exact child page. Keep the current owner/emitter route through [UID:00014D] `ExceptionHandler` aggregate, because that route already lands in [UID:00004P] `ExceptionHandler` and [UID:0000J8] `NexusTK/platform/ExceptionHandler.cpp`.

Recommended metadata after implementation:

```text
COMPLETION:85
CONFIDENCE:91
CANONICAL_OWNER:00014D
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00014D
```

Rationale: the exact callback range, callback installation site, no-direct-caller reachability, field offsets, crash writer callee, KeySpeedMgr restore callee, and previous-filter chain are already documented with IDA-backed evidence. The remaining caps are exact original helper spellings and the fact that current-session MCP was not live for a fresh check.

## Evidence Checked

- Target doc [UID:00014F] currently records `84/90`, owner/emitter [UID:00014D], blank C++ block, no ordinary code callers, constructor data xref `0x004ab49e`, callee set `sub_4AB870` and `sub_4EFF30`, `g_pCrashTarget + 4` suppress flag, previous-filter offset `+8`, and one-byte padding before [UID:00014G].
- Parent aggregate [UID:00014D] now records `86/90`, exact aggregate range `0x004ab480-0x004ac89a`, byte-level child map, constructor callback pointer to `0x004ab830`, `m_skipCrashReport`, `m_previousFilter`, ImageHlp pointer fields, and `platform/ExceptionHandler.cpp` placement.
- Class/file docs [UID:00004P] and [UID:0000J8] now describe `TopLevelExceptionFilter` as a file-static callback in `ExceptionHandler.cpp`; [UID:0000J8] explicitly keeps `KeySpeedMgr` and `Crasher` as dependencies/companions, not direct owners.
- [UID:0000QN] and [UID:000297] confirm `g_pCrashTarget` at `0x0067ab34`; TopLevelExceptionFilter reads it at `0x004ab83a/0x004ab83c`; Crasher writes byte offset `+4`, now best named `m_skipCrashReport`.
- [UID:00018P] and [UID:0000RB] confirm `g_pKeySpeedMgr` / `KeySpeedMgr::RestoreSystemKeyboardSettings` as the source-facing name for raw callee `sub_4EFF30`.
- [UID:00014G], [UID:00014H], [UID:00014I], [UID:00014J], and [UID:000259] confirm the crash-report writer, exception-code string helper, logical-address helper, ImageHlp stack helper, and diagnostic `.rdata` are all part of the same `ExceptionHandler.cpp` crash-reporting family.
- [UID:0001QB] confirms the crash diagnostics integration: `TopLevelExceptionFilter` writes `BCrash.nfo` through [UID:00014G], while [UID:00014E] and the stored report sender are adjacent diagnostics paths, not direct filter callees.
- Executed B005 report `Agent-B005/research/executed/00014D-ExceptionHandler-source-quality.md` explicitly recommends `LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)`, file-level callback placement, `m_skipCrashReport`, `m_previousFilter`, and child-level first-draft C++ readiness for [UID:00014F].
- Current coverage row still says `84% : strong` and "final C++ remains pending exact child-body source entry"; current auto stats list `00014F` at `84/90`.
- Generated `auto-generated/NexusTK/platform/ExceptionHandler.cpp` currently contains only an empty marker for `00014F`; this verifies routing but not source behavior.

## Source Shape And Signature

Best source-facing signature:

```cpp
static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo);
```

This is a Windows unhandled-exception-filter callback installed by `ExceptionHandler::ExceptionHandler` through `SetUnhandledExceptionFilter`. It should be modeled as a file-level/static callback in `platform/ExceptionHandler.cpp`, not a class virtual method, Crasher method, KeySpeedMgr method, CRT helper, or generic exception-runtime stub.

The callback has no ordinary direct code callers. Reachability is by pointer: the constructor passes `0x004ab830` to `SetUnhandledExceptionFilter` and stores the returned previous filter at object offset `+8`.

## Behavior Resolution

Resolved source behavior:

1. Restore saved keyboard-repeat settings when `g_pKeySpeedMgr` is live.
2. Read the active `ExceptionHandler *` from `g_pCrashTarget`.
3. If no active handler exists, return `EXCEPTION_CONTINUE_SEARCH` / `0`.
4. If `m_skipCrashReport` at handler offset `+0x04` is set, return `EXCEPTION_CONTINUE_SEARCH` / `0` without writing the normal crash report.
5. Otherwise call the crash-report writer, source-facing `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)`, documented by [UID:00014G].
6. If `m_previousFilter` at handler offset `+0x08` is non-null, call it and return its result.
7. If no previous filter exists, return `EXCEPTION_CONTINUE_SEARCH` / `0`.

The filter itself does not parse `ExceptionRecord` or `ContextRecord`; it preserves and forwards the full `EXCEPTION_POINTERS *` to the writer. Helper names for the downstream exception/context work should stay with those child pages:

- `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)` for [UID:00014G].
- `GetExceptionCodeText(DWORD exceptionCode)`-style helper for [UID:00014H].
- `GetLogicalAddress(...)`-style helper for [UID:00014I].
- `ExceptionHandler::WriteImageHlpStackWalk(...)` for [UID:00014J].

## Owner And Emitter Route

| Candidate | Rank | Decision |
| --- | --- | --- |
| [UID:00014D] `ExceptionHandler` aggregate | Best current direct route | Keep. The callback is an exact executable child of the aggregate; the aggregate now has `86/90`, owns the constructor that installs the pointer, and emits through the class/file route. |
| [UID:00004P] `ExceptionHandler` class | Valid parent route | Do not switch this child directly unless the supervisor coordinates a broader child-owner cleanup. The callback is file-static/free-shaped, not a class virtual, but class ownership is already reached through [UID:00014D]. |
| [UID:0000J8] `ExceptionHandler.cpp` file | Final source file | Correct file destination, reached through [UID:00014D] -> [UID:00004P] -> [UID:0000J8]. |
| [UID:0000II]/[UID:000129] `Crasher` | Consumer only | Reject as direct owner. Crasher sets `m_skipCrashReport` before an intentional null write; it does not install the filter or write `BCrash.nfo`. |
| [UID:0000KJ] `KeySpeedMgr` | Callee only | Reject as direct owner. The filter calls keyboard restore as crash cleanup, but KeySpeedMgr owns only the restore method. |
| Application / generic runtime / ImageHlp / packet code | Dependency only | Reject as direct owner. Application constructs the handler, ImageHlp and packet helpers are downstream diagnostics dependencies, and the callback is not compiler/runtime-generated. |

## Raw And Generated Name Cleanup

Recommended source-facing names in the target doc:

| Current/raw form | Recommended source-facing form | Notes |
| --- | --- | --- |
| `dword_67AB34` | `g_pCrashTarget` | Active `ExceptionHandler *` global. |
| byte `[g_pCrashTarget + 4]` | `ExceptionHandler::m_skipCrashReport` or `ShouldSkipCrashReport()` | Draft field name is closed enough for first-draft source. |
| object offset `+8` | `ExceptionHandler::m_previousFilter` or `PreviousFilter()` | Type `LPTOP_LEVEL_EXCEPTION_FILTER`. |
| `sub_4AB870` | `ExceptionHandler::WriteCrashReport` | Exact child [UID:00014G]. |
| `dword_67AB48` | `g_pKeySpeedMgr` | Active KeySpeedMgr singleton. |
| `sub_4EFF30` | `KeySpeedMgr::RestoreSystemKeyboardSettings` | Exact child [UID:00018P]. |
| return `0` | `EXCEPTION_CONTINUE_SEARCH` | Source constant improves Windows callback readability; binary value remains `0`. |

The target page should also stop describing final C++ as merely pending under stale threshold wording. The active `85/85` combined-score/emitter gate is met by route even before the recommended metadata bump, and the page is source-authored executable code, not no-code/generated ABI material.

## First-Draft C++ Readiness

This is not a no-code page. Formal C++ should be placed on the exact [UID:00014F] child page, not on the monolithic [UID:00014D] aggregate. A parent `[[CHILDREN]]` insertion point is optional only if the generator needs it later.

Recommended first-draft body:

```cpp
static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)
{
    if (g_pKeySpeedMgr != 0) {
        g_pKeySpeedMgr->RestoreSystemKeyboardSettings();
    }

    ExceptionHandler *target = g_pCrashTarget;
    if (target == 0 || target->ShouldSkipCrashReport()) {
        return EXCEPTION_CONTINUE_SEARCH;
    }

    target->WriteCrashReport(exceptionInfo);

    LPTOP_LEVEL_EXCEPTION_FILTER previousFilter = target->PreviousFilter();
    if (previousFilter != 0) {
        return previousFilter(exceptionInfo);
    }

    return EXCEPTION_CONTINUE_SEARCH;
}
```

The accessor names `ShouldSkipCrashReport()` and `PreviousFilter()` are preferred in first-draft source because a file-static callback cannot access private fields unless the original class used public fields, friendship, or a static member callback. Inline accessors compile down to the documented field reads and keep the draft source idiomatic. If the later declaration pass proves the original source used public fields or a friend/static member, the body can be mechanically changed to direct `m_skipCrashReport` and `m_previousFilter` access without changing behavior.

## Recommended Exact Target Changes

Metadata:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00014D | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the stale parent/status language with:

```text
- Parent attachment: attached to [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md), now `86/90`; this child remains an exact callback body routed through the aggregate to [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) and [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).
- Final C++ is ready for first-draft entry on this exact child page under the active combined-score/emitter route gate. Do not place the callback body in the monolithic [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md) aggregate except through a valid child insertion route.
```

Add a source-shape/signature subsection:

```text
## Source Shape / Signature

Best current source signature is `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *exceptionInfo)`. The constructor installs this callback through `SetUnhandledExceptionFilter`, and no ordinary code callers are expected. It is file-static/free-helper shaped inside `platform/ExceptionHandler.cpp`, not a class virtual method, Crasher method, KeySpeedMgr method, CRT helper, or generic runtime exception function.
```

Replace or augment the behavior bullets to use source-facing names:

```text
- restores saved keyboard-repeat settings through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) / `g_pKeySpeedMgr->RestoreSystemKeyboardSettings()` when that singleton is live;
- reads [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) as the active `ExceptionHandler *`;
- returns `EXCEPTION_CONTINUE_SEARCH` / `0` when no active target exists;
- skips normal `BCrash.nfo` generation and returns `EXCEPTION_CONTINUE_SEARCH` / `0` when `m_skipCrashReport` at handler offset `+0x04` is set;
- otherwise calls [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md), source-facing `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)`;
- chains to `m_previousFilter` at handler offset `+0x08` when present and returns the previous filter's result.
```

Add a score rationale:

```text
## Score Rationale

`85/91` reflects exact callback bounds, constructor callback-pointer evidence, no ordinary direct callers, current source-facing field names `m_skipCrashReport` and `m_previousFilter`, resolved KeySpeedMgr/report-writer callees, crash-diagnostics ownership through `platform/ExceptionHandler.cpp`, and first-draft C++ readiness. Completion remains capped at `85` because exact original helper spellings and class-access style are still inferred rather than source-proven, and current-session IDA MCP was unavailable for a fresh check.
```

Add a change entry:

```text
- 2026-06-19 B015 source-quality report:
  - Recommended `84/90 -> 85/91`; owner/emitter remain [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md).
  - Source shape resolved to `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` in `platform/ExceptionHandler.cpp`, installed by `SetUnhandledExceptionFilter`.
  - Replaced raw-name wording with `g_pCrashTarget`, `g_pKeySpeedMgr`, `KeySpeedMgr::RestoreSystemKeyboardSettings`, `ExceptionHandler::WriteCrashReport`, `m_skipCrashReport`, `m_previousFilter`, and `EXCEPTION_CONTINUE_SEARCH`.
  - First-draft child C++ is recommended on the exact [UID:00014F] page; monolithic aggregate C++ remains rejected.
```

## Validator Needs

After a later implementation callback updates the target page, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [00014F-TopLevelExceptionFilter-source-quality-removed.md](00014F-TopLevelExceptionFilter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If coverage text is changed by the supervisor, run the normal documented/full validation path used by that incorporation pass so `project-level/-auto-completion-stats.md`, unresolved/resolved indexes, and auto-generated markers refresh together.

Expected unresolved-name improvements in the target doc after implementation:

- Remove target references to raw `sub_4AB870` in favor of [UID:00014G] / `ExceptionHandler::WriteCrashReport`.
- Remove target references to raw `sub_4EFF30` in favor of [UID:00018P] / `KeySpeedMgr::RestoreSystemKeyboardSettings`.
- Replace raw `dword_67AB48` wording with [UID:0000RB] / `g_pKeySpeedMgr`.
- Preserve address evidence where useful, but do not leave raw names as the source-facing names.

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` during the report pass. If the supervisor implements this recommendation, replace the current [UID:00014F] row with:

```text
    - [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) : reconstructable : 85% : very strong : B015 source-quality review confirms `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)` as the file-level Windows unhandled-exception callback installed by [UID:00014D] `ExceptionHandler` construction through `SetUnhandledExceptionFilter`; no ordinary code callers, constructor pointer xref `0x004ab49e/0x004ab49f`, KeySpeedMgr restore via `g_pKeySpeedMgr->RestoreSystemKeyboardSettings`, active [UID:0000QN] `g_pCrashTarget` read, `m_skipCrashReport` gate at handler offset `+0x04`, [UID:00014G] `ExceptionHandler::WriteCrashReport(EXCEPTION_POINTERS *)` call, optional previous-filter chain through `m_previousFilter` at `+0x08`, return `EXCEPTION_CONTINUE_SEARCH`/0 when no target, suppressed, or no previous filter exists, exact `0x3f` body bounded by padding before [UID:00014G], owner/emitter route through [UID:00014D] -> [UID:00004P] -> [UID:0000J8] `platform/ExceptionHandler.cpp`, and first-draft child C++ readiness under the active combined-score/emitter gate.
```

Projected auto-stats row after validation:

```text
| `00014F` | 85 | 91 | 88.0 | `by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md` |
```

## Open Questions

- Exact original source spelling for `WriteCrashReport`, `ShouldSkipCrashReport`, and `PreviousFilter` is still inferred. The names are source-quality ready as descriptive draft names, not proven original symbols.
- Exact class-access style is not proven: file-static helper with accessors is the safest first draft; direct private-field access would require a friend/static-member/public-field declaration decision in the class pass.
- Current-session live IDA MCP was unavailable, so the report does not claim a fresh 2026-06-19 live disassembly/decompilation check.
- The broader raw helper bodies inside [UID:00014D] remain child-page work; they do not block [UID:00014F] first-draft C++.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/00014F-TopLevelExceptionFilter-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"00014F"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00014F-TopLevelExceptionFilter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/00014F-TopLevelExceptionFilter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00014F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
