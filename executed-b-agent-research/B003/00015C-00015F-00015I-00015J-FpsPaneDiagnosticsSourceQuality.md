** TARGET-REPORT-UID:00015C **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00015C-00015F-00015I-00015J FpsPane Diagnostics Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep all four primary targets owned by [UID:00005F] FpsPane and emitted through [UID:00005F] to [UID:0000JK] FpsPane.cpp. Raise the raw constructor and raw logging pages enough to reflect the source-quality findings below, and populate first-draft C++ for all four primary targets.
- Final disposition: the raw starts are not padding, ParcelPane code, MapPane code, or arbitrary dead bytes. They are FpsPane source-authored constructor/logging bodies. The `0x004b69b0` and `0x004b6ae0` helpers are best treated as retained private helper implementations whose logic was also inlined or duplicated inside `UpdateFpsLogSession`.
- Required action: supervisor/A-agent should update the target docs, support docs, and `by-memory/-coverage-report.md` rows with the details below. B003 did not edit by-* docs or generated files.
- Confidence: strong for FpsPane ownership, source placement, field meanings, string meanings, and C++ readiness; medium for original helper liveness because no direct xref, function object, literal pointer, or caller path reaches the raw helper starts.

| Target | Current score | Recommended score | Owner / emitter / reconstructable | C++ policy |
| --- | ---: | ---: | --- | --- |
| [UID:00015C] `0x004b6410-0x004b646b.FpsPaneConstructorRaw` | `82/90` | `86/90` | `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F` | Populate constructor draft. Raw no-caller status caps score below final-audit, but does not justify blank C++ under the active combined-score rule. |
| [UID:00015F] `0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw` | `85/85` | `88/88` | `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F` | Populate source-shaped draft using `StartLogSession()` and `WriteLogSummary()` helper calls. The binary has inlined/duplicated helper bodies, but the helper-call source shape is the most plausible human C++. |
| [UID:00015I] `0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw` | `85/85` | `86/87` | `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F` | Populate private-helper draft. Mark as retained/no-xref helper, not proven runtime-called. |
| [UID:00015J] `0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw` | `85/85` | `86/87` | `CANONICAL_OWNER:00005F`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00005F` | Populate private-helper draft. Mark as retained/no-xref helper, not proven runtime-called. |
| [UID:00015D] `FpsPaneDiagnostics` aggregate | `85/86` | `87/87` | `CANONICAL_OWNER:0000JK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JK` | Keep aggregate C++ blank. It is a container/source island and should not duplicate child method bodies. |
| [UID:00005F] `FpsPane` class | `85/86` | `87/88` | `CANONICAL_OWNER:0000JK`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JK` | Do not paste child method bodies into class page. Add field/method/source-quality details and, if class declarations are emitted later, use the field names below. |
| [UID:0000JK] `FpsPane` file | `87/85` | `88/87` | `CANONICAL_OWNER:FILE`, path `NexusTK/ui/diagnostics/` | Keep as generated source root. Add global declarations and source-placement corrections; do not duplicate target method bodies in the file page. |

Support C++ recommendation for eligible FpsPane globals, if the supervisor chooses to populate those by-global C++ blocks:

```cpp
FpsPane* g_pFpsPane;
int g_fpsDebugActive = 1;
bool g_fpsLogEnabled;
```

`g_pFpsPane` and `g_fpsLogEnabled` are `dd ?` / `db ?` in the local IDA listing and should be modeled as zero-initialized static storage, not as fixed `0xffffffff` or `0xff` initialized bytes. `g_fpsDebugActive` is explicitly `dd 1`.

## Supporting Research

## Target

- Target UIDs: [UID:00015C], [UID:00015F], [UID:00015I], [UID:00015J]
- Target paths:
  - `source-3/project-documentation/by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md`
  - `source-3/project-documentation/by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md`
  - `source-3/project-documentation/by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md`
  - `source-3/project-documentation/by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md`
- Source queue/report row: direct user assignment recorded in `Supervisor_notes.md` line matching "Agent-B003 received the FpsPane diagnostics source-quality assignment".
- Current supervisor classification: B-preferred heuristic/source-inference and final-C++ readiness research.
- Current scores and parent state: all four target pages already route to [UID:00005F] FpsPane; [UID:00015C] is below the strict `85/85` child gate by completion only, while [UID:00015F], [UID:00015I], and [UID:00015J] are exactly `85/85` and therefore not yet over the active final-C++ combined-score gate until raised.

## Supervisor Active Recheck

- The assignment explicitly requires one report only under `Agent-B003/research` and forbids direct edits to by-* docs, generated files, IDA DB, source files, and coverage reports.
- No split repair is needed for the four primary text ranges. The range boundaries are already exact: constructor `0x004b6410-0x004b646b`, session method `0x004b64a0-0x004b67a7`, start helper `0x004b69b0-0x004b6adc`, and summary helper `0x004b6ae0-0x004b6c2b`.
- The necessary repair is source-quality and policy repair: close stale "blank C++ under 95/95" wording, correct log-string and field semantics, and document the best helper/source-shape inference.

## Inference Research Guidance Check

- I treated generated Wave3/simroot output as lead evidence only.
- IDA MCP was attempted first, as required by `by-structure.md`, but the endpoint was unavailable in this session.
- Local IDA export files under `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS` were used as the strongest available binary-derived evidence after MCP failed.
- I separated direct facts from inference:
  - Direct facts: local IDA listing/proc labels, assembly bytes, string definitions, vtable slots, `.data` declarations, and existing by-* page metadata.
  - Inference: likely original field names, helper names, source-level helper-call shape, source placement, and whether no-xref helpers are retained private methods.

## IDA MCP / Local Evidence Status

- IDA MCP command attempted:

> Executable block R001 was removed from this report and preserved verbatim in [00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md](00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: `MCP_ERROR: Unable to connect to the remote server`.
- Local executable was searched but not found with:

> Executable block R002 was removed from this report and preserved verbatim in [00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md](00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: no local executable path found.
- Local IDA export used:
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.lst`
  - `C:\Users\admin\Desktop\CTools\CPlusPlusSim\core\extra-sources\IDA-EXPORTS\NexusTK.exe.asm`

## IDA Export Facts

- `rg` over `NexusTK.exe.lst` finds raw starts only as definitions, not as references:
  - `305588:.text:004B6410 push ebp`
  - `305630:.text:004B64A0 push ebp`
  - `306026:.text:004B69B0 push ebp`
  - `306100:.text:004B6AE0 push ebp`
- The modeled FpsPane virtual/destructor entries appear as proc labels and vtable targets:
  - `0x004b67b0` is `sub_4B67B0`; vtable slot at `0x0061a664`.
  - `0x004b68b0` is `sub_4B68B0`; timer/update slot at `0x0061a6a0`.
  - `0x004b6c2b` and `0x004b6c36` are adjustor thunks.
  - `0x004b6c50` is scalar deleting destructor; primary vtable slot at `0x0061a620`.
- The constructor assembly writes the three FpsPane vtable views, sets `g_pFpsPane`, writes `this + 0xf5`, and clears `this + 0x100`.
- The `0x004b64a0` body contains both the start/reset logic and the summary/finalize logic. The start portion is duplicated at `0x004b69b0`; the summary portion is duplicated at `0x004b6ae0`.
- The show path in `0x004b64a0` uses `dword_69B37C`, one of [UID:0000T6] MainUiLayerSlots. This is a dependency, not FpsPane-owned storage.
- Data definitions from the local IDA listing:
  - `.data:0066DA90 dword_66DA90 dd 1`
  - `.data:0069B334 dword_69B334 dd ?`
  - `.data:0069B338 byte_69B338 db ?`
- The current exact-storage pages that still describe `0xffffffff` or `0xff` for `g_pFpsPane` / `g_fpsLogEnabled` should be corrected to the IDA export's uninitialized-storage wording unless a later raw PE byte check contradicts the listing.

## Heuristic / Inference Reanalysis And Validation

### Raw Reachability And Liveness

- Issue: current target pages repeatedly say the raw starts have no function objects or xrefs. The assignment required not stopping there.
- Evidence checked:
  - Existing by-memory pages record multiple live IDA MCP xref/literal-pointer sweeps with zero refs.
  - Local `NexusTK.exe.lst` text search found the raw addresses only at their definitions.
  - Vtable slots confirm nearby `OnPaint`, `UpdateStatistics`, thunks, and scalar destructor are live class entries, but no vtable points at constructor/session/start/summary raw starts.
- Accepted inference: `0x004b6410` and `0x004b64a0` are source-authored FpsPane method bodies recovered by Wave3/pre-existing metadata but not recognized by the current IDA function model. `0x004b69b0` and `0x004b6ae0` are real retained private helper bodies or old helper implementations; no evidence proves runtime calls.
- Rejected alternatives:
  - Padding/data: rejected because each raw start has a normal prologue, coherent control flow, API calls, field accesses, and returns.
  - ParcelPane: rejected because all touched globals, strings, fields, vtables, and neighboring methods are FpsPane diagnostics.
  - MapPane/ObjectList ownership: rejected because those are read-only diagnostic dependencies from `UpdateStatistics`, not owners of the FPS log code.
  - Compiler-generated thunks: rejected for the four primary targets; only `0x004b6c2b-0x004b6c41` is thunk glue.
- Score impact: no-xref status caps confidence below `90-92` for helper liveness and below final-audit, but does not block owner/emitter or first-draft C++ after combined score clears `>85`.

### Constructor Source Shape

- Issue: constructor page had raw vtable/global writes but no modeled constructor call path.
- Evidence:
  - `0x004b641c` calls `sub_544460` with argument `1`, matching base Pane construction.
  - `0x004b6434` writes `g_pFpsPane` after the compiler's subobject-normalization pattern.
  - `0x004b643b`, `0x004b6441`, and `0x004b644b` write the primary, secondary, and timer/update vtables.
  - `0x004b6455` writes byte `+0xf5`; `0x004b645c` clears float field `+0x100`.
- Accepted source shape: original C++ should be a normal `FpsPane::FpsPane()` constructor that calls/initializes the Pane base, sets the module singleton, marks inherited pane visibility/enabled state, and clears `m_currentFps`. It should not manually write vtable pointers.
- Rejected source shape: raw C++ with `reinterpret_cast`, synthetic vtable arrays, and `this == -248` checks. Those are decompiler artifacts from MSVC multiple-inheritance/subobject normalization.
- Score impact: raise [UID:00015C] to `86/90`; no caller path remains a real caveat, but the source body is clear enough for draft C++.

### Logging Method / Helper Shape

- Issue: `UpdateFpsLogSession` duplicates the standalone start and summary helper bodies.
- Evidence:
  - `0x004b64df-0x004b65f5` and `0x004b69b7-0x004b6acd` perform the same reset, `timeGetTime`, `g_fpsDebugActive`, `g_fpsLogEnabled`, `GetLocalTime`, filename, header, and flag-clear sequence.
  - `0x004b6645-0x004b6781` and `0x004b6ae4-0x004b6c23` perform the same append-mode summary writer sequence.
  - `0x004b64a0` additionally builds a display rectangle, shows/hides the pane, and schedules/removes the timer/update subobject.
- Best source inference: source likely had private helpers similar to `StartLogSession()` and `WriteLogSummary()`, and `UpdateFpsLogSession(bool startNew)` either called them and MSVC inlined them, or the developer retained older helper implementations after copying the logic into the public/toggle method. The helper-call shape is more plausible mid-2000s C++ than three copy-pasted raw decompiler blocks.
- Rejected alternatives:
  - Leave helpers blank forever: rejected because the exact helper bodies are source-authored, field-complete, and currently emitted.
  - Merge helper pages into `UpdateFpsLogSession`: rejected because they are separate executable byte ranges and already have exact pages.
  - Rename helpers to generic `sub_4B69B0` / `sub_4B6AE0`: rejected because their roles are clear from the duplicated log-start and summary behavior.
- C++ impact: populate [UID:00015F] with helper-call source, and populate [UID:00015I] / [UID:00015J] with the private helper bodies.

### Field Names And Types

Recommended source-facing names are inferred/descriptive, not original-proof:

| Offset | Best source-facing name | Type | Evidence |
| --- | --- | --- | --- |
| `+0xf5` | inherited `m_visible` / `m_isVisible` | `bool` or byte | Constructor writes `1`; show/hide virtuals manage pane state. |
| `+0xf8` | `m_frameCount` | `DWORD` or `int` | `OnPaint` increments; session start resets; `UpdateStatistics` samples and clears once per second. |
| `+0x100` | `m_currentFps` | `float` | Constructor clears; `UpdateStatistics` writes; `OnPaint` formats `%5.1f FPS`. |
| `+0x104` | `m_logFileName` | `char[50]` | `sprintf_s` size argument `0x32`; passed to `fopen_s`. |
| `+0x136` | `m_logStartTime` | `SYSTEMTIME` | `GetLocalTime(this + 0x136)`; month/day/hour/minute/second fields read. |
| `+0x148` | `m_logStartTick` | `DWORD` | `timeGetTime()` stored; summary subtracts and divides by `1000`. |
| `+0x14c` | `m_minFps` | `float` | Initialized to `300.0f`; summary writes `minFPS`. |
| `+0x150` | `m_maxFps` | `float` | Initialized to `0.0f`; summary writes `maxFPS`. |
| `+0x154` | `m_sampleCount` | `unsigned int` | Initialized to `1`; incremented each statistics tick; divisors for averages. |
| `+0x158` | `m_totalFps` | `double` | Accumulates FPS as double; summary divides by sample count. |
| `+0x160` | `m_totalLivingObjects` | `unsigned int` | Front row bucket accumulator; summary label `aveLivingObject`. |
| `+0x164` | `m_totalBalloonObjects` | `unsigned int` | Visible object-list accumulator; summary label `aveBalloonObject`. |
| `+0x168` | `m_totalStaticObjects` | `unsigned int` | Back row bucket accumulator; summary label `aveStaticObject`. |

Rejected field names:

- `m_tickCounter` for `+0xf8`: too generic and contradicts `OnPaint` frame increments.
- `m_avgLivingObjects` / `m_avgBalloonObjects` / `m_avgStaticObjects` for `+0x160-+0x168`: those fields store totals, not averages; averages are computed at write time.
- Year-based timestamp fields for filename: rejected. The assembly reads `wMonth`, `wDay`, `wHour`, `wMinute`, and `wSecond`; it does not read `wYear`.

### Log Strings And Placeholder Labels

- `aFpsdataDDDDDTx` is source string `"FPSDATA-%d-%d-%d-%d-%d.txt"`.
- `aW` is file mode `"w"`.
- `unk_61A700` is file mode `"a"`.
- `unk_61A6D8` is CP949 Korean bytes for a test-start timestamp line. ASCII-safe byte literal:

```cpp
"\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xC0\xDB %d\xBF\xF9 %d\xC0\xCF %d\xBD\xC3 %d\xBA\xD0 %d\xC3\xCA\n\n\n"
```

- `unk_61A720` is CP949 Korean bytes for elapsed test time. ASCII-safe byte literal:

```cpp
"\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xB0\xA3 : %dsec\n"
```

- Decoding command used:

> Executable block R003 was removed from this report and preserved verbatim in [00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md](00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md). The archived block is non-authoritative and must not be executed.

- Result meaning: test-start month/day/hour/minute/second line, and test-time seconds line. The report stays ASCII-safe, so the Korean text is represented by byte escapes and English meaning.
- Support-doc impact: [UID:0003BJ] `FpsPaneDiagnosticStringData` should add rows for `0x0061a6d8` and `0x0061a720`. The current table skips them even though both are used by [UID:00015F], [UID:00015I], and [UID:00015J].

### Globals And Initializers

- `g_pFpsPane` is FpsPane-owned singleton storage. Local IDA export says `dword_69B334 dd ?`, so source should be `FpsPane* g_pFpsPane;` with static zero initialization.
- `g_fpsDebugActive` is a dword initialized to `1`. Current name is acceptable as a stable IDA/doc name, but source semantics are closer to "pending FPS debug/log session start banner". If renamed later, recommended descriptive name is `g_fpsDebugSessionPending` or `g_fpsLogStartPending`.
- `g_fpsLogEnabled` is a byte flag with `byte_69B338 db ?`, so source should be zero-initialized by default. Current exact-memory docs that say initialized `0xff` should be corrected unless later raw PE bytes prove otherwise. Recommended source type is `bool` because MSVC `bool` storage is one byte and all code uses byte compares; `BYTE` remains an acceptable conservative type if the project avoids `bool` globals.
- No direct writes to `g_fpsLogEnabled` were found in docs or local export. Treat it as externally toggled, debug-only, config-patched, or currently default-off until another writer is proven.

### Main UI Layer Dependency

- `UpdateFpsLogSession` pushes `dword_69B37C` when showing the pane.
- Existing docs identify `dword_69B37C` as part of [UID:0000T6] `MainUiLayerSlots`, not as `g_pScreenPane`.
- Source-quality recommendation: do not call it `g_pScreenPane` in FpsPane docs. Use a descriptive unresolved dependency name such as `g_pFpsPaneParentPane` only in draft code, and link the real ownership to [UID:0000T6] until MainUiLayerSlots names are finalized.

### Source Placement

- Accepted: [UID:0000JK] `FpsPane.cpp` under `NexusTK/ui/diagnostics/`.
- Evidence: Wave3 import source file `FpsPane.cpp`, proposed source tree already places `ui/diagnostics/FpsPane.cpp`, all vtable/global/string/method evidence is FpsPane diagnostics, and ParcelPane pollution is stale.
- Rejected:
  - `ParcelPane.cpp`: no FPS strings/fields belong to parcel UI.
  - `MapPane.cpp` / `ObjectList.cpp`: `UpdateStatistics` consumes object counts only for diagnostics.
  - `MainUiGraph.cpp`: owns the parent layer pointer dependency but not the FpsPane class or log session.

### Final C++ Gate

- Active gate from supervisor/by-structure: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS` reaching generated source, and `(COMPLETION + CONFIDENCE) / 2 > 85`.
- [UID:00015C] already has average `86`; after raising completion to `86`, it clearly clears.
- [UID:00015F], [UID:00015I], and [UID:00015J] are currently exactly `85/85`, which is not enough. The evidence above justifies raising them over the gate.
- The old "blank under 95/95" text on target/support pages is stale policy and should be replaced with the active combined-score rule.

## First-Draft C++ Recommendation

These snippets are source-shaped drafts, not raw decompiler output. Names marked as descriptive are not original-proof. The supervisor should adapt helper/member names to the final class declaration, but the logic, argument order, timestamp fields, and globals should be preserved.

### [UID:00015C] FpsPane Constructor

```cpp
FpsPane::FpsPane()
    : Pane(1)
{
    g_pFpsPane = this;
    m_visible = true;
    m_currentFps = 0.0f;
}
```

Notes:

- `m_visible` is inferred/descriptive for inherited byte `+0xf5`.
- Do not write vtable pointers in C++; those are compiler-generated from the class declaration.
- The raw `lea this+0xf8; add -0xf8` pattern should be represented as `g_pFpsPane = this`.

### [UID:00015F] FpsPane UpdateFpsLogSession

Preferred source-quality draft:

```cpp
void FpsPane::UpdateFpsLogSession(bool startNew)
{
    Rect rect(10, 10, 490, 22);

    if (startNew && !IsVisible()) {
        StartLogSession();
        SetFrameRect(&rect, 0, 0, g_pFpsPaneParentPane);
        m_frameCount = 0;
        m_updateTimer.StartTimer(0, 1000, 0, 0);
        return;
    }

    WriteLogSummary();
    Hide();
    m_updateTimer.RemoveTimer();
}
```

Notes:

- `IsVisible`, `SetFrameRect`, `Hide`, `m_updateTimer.StartTimer`, and `m_updateTimer.RemoveTimer` are descriptive names for calls through `sub_544c50`, primary vtable slots `+0x30/+0x38`, `sub_5975e0`, and `sub_597600`.
- `g_pFpsPaneParentPane` is descriptive for `dword_69B37C`, which belongs to [UID:0000T6] MainUiLayerSlots. Replace with the finalized MainUiLayerSlots name when known.
- The binary `0x004b64a0` body contains inlined/duplicated start and summary helper logic. Source-level helper calls are recommended because the standalone helper bodies exist at [UID:00015I] and [UID:00015J].

### [UID:00015I] FpsPane StartLogSession

```cpp
void FpsPane::StartLogSession()
{
    m_logStartTick = timeGetTime();
    m_minFps = 300.0f;
    m_maxFps = 0.0f;
    m_sampleCount = 1;
    m_totalFps = 0.0;
    m_totalLivingObjects = 0;
    m_totalBalloonObjects = 0;
    m_totalStaticObjects = 0;

    if (g_fpsDebugActive != 0) {
        if (g_fpsLogEnabled) {
            FILE* file;

            GetLocalTime(&m_logStartTime);
            sprintf_s(m_logFileName, sizeof(m_logFileName),
                      "FPSDATA-%d-%d-%d-%d-%d.txt",
                      m_logStartTime.wMonth,
                      m_logStartTime.wDay,
                      m_logStartTime.wHour,
                      m_logStartTime.wMinute,
                      m_logStartTime.wSecond);

            fopen_s(&file, m_logFileName, "w");
            fprintf(file, "***NEW_CLIENT***\n");
            fprintf(file,
                    "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xC0\xDB %d\xBF\xF9 %d\xC0\xCF %d\xBD\xC3 %d\xBA\xD0 %d\xC3\xCA\n\n\n",
                    m_logStartTime.wMonth,
                    m_logStartTime.wDay,
                    m_logStartTime.wHour,
                    m_logStartTime.wMinute,
                    m_logStartTime.wSecond);
            fclose(file);
        }

        g_fpsDebugActive = 0;
    }
}
```

Notes:

- No `fopen_s` failure check is shown because the binary does not branch on the return value before writing/closing.
- The date/time arguments are month/day/hour/minute/second. Do not use year in this method unless later evidence contradicts the assembly.
- The CP949 byte-escaped string preserves the source literal bytes while keeping this report ASCII-only.

### [UID:00015J] FpsPane WriteLogSummary

```cpp
void FpsPane::WriteLogSummary()
{
    if (!g_fpsLogEnabled) {
        return;
    }

    FILE* file;
    fopen_s(&file, m_logFileName, "a");

    fprintf(file, "------------------------\n");
    fprintf(file,
            "\xC5\xD7\xBD\xBA\xC6\xAE\xBD\xC3\xB0\xA3 : %dsec\n",
            (timeGetTime() - m_logStartTick) / 1000);
    fprintf(file, "minFPS : %5.1f\n", (double)m_minFps);
    fprintf(file, "maxFPS : %5.1f\n", (double)m_maxFps);
    fprintf(file, "aveFPS : %5.1f\n", m_totalFps / (double)m_sampleCount);
    fprintf(file, "aveLivingObject  : %d\n", m_totalLivingObjects / m_sampleCount);
    fprintf(file, "aveBalloonObject : %d\n", m_totalBalloonObjects / m_sampleCount);
    fprintf(file, "aveStaticObject  : %d\n", m_totalStaticObjects / m_sampleCount);
    fprintf(file, "------------------------\n\n");

    fclose(file);
}
```

Notes:

- The elapsed-time calculation is integer seconds: `(timeGetTime() - m_logStartTick) / 1000`.
- `m_sampleCount` is initialized to `1`, so the original code has no zero-divisor guard here.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004b6410-0x004b646b` | [UID:00015C] | Constructor | TRUE | [UID:00005F] | `86/90` | Populate C++ |
| `0x004b64a0-0x004b67a7` | [UID:00015F] | Session toggle/start-finalize method | TRUE | [UID:00005F] | `88/88` | Populate C++ |
| `0x004b69b0-0x004b6adc` | [UID:00015I] | Retained private start helper | TRUE | [UID:00005F] | `86/87` | Populate C++ |
| `0x004b6ae0-0x004b6c2b` | [UID:00015J] | Retained private summary helper | TRUE | [UID:00005F] | `86/87` | Populate C++ |
| `0x004b6410-0x004b6caf` | [UID:00015D] | FpsPane diagnostics aggregate | TRUE | [UID:0000JK] | `87/87` | Keep C++ blank |
| `0x004b6c2b-0x004b6c41` | [UID:00015K] | Adjustor thunks | FALSE | NONE | unchanged | Keep ignored/non-emitting |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004b6410` | no local listing refs except definition | Constructor-shaped raw body, no proven caller |
| `0x004b64a0` | no local listing refs except definition | Session method raw body, no proven caller |
| `0x004b69b0` | no local listing refs except definition | Retained start helper, no proven caller |
| `0x004b6ae0` | no local listing refs except definition | Retained summary helper, no proven caller |
| `0x0061a664 -> 0x004b67b0` | vtable data | `OnPaint` virtual entry |
| `0x0061a6a0 -> 0x004b68b0` | vtable data | Timer/update virtual entry |
| `0x0061a620 -> 0x004b6c50` | vtable data | Scalar deleting destructor |
| `0x0069b37c` | pushed in `UpdateFpsLogSession` show path | MainUiLayerSlots parent/layer dependency |

## Ranked Ownership Analysis

### 1. [UID:00005F] FpsPane Class - Accepted For Primary Target Methods

- Evidence for: vtable stores, FpsPane RTTI/vtable data, `g_pFpsPane`, FpsPane-only diagnostic globals, FPS strings, owner-relative FpsPane layout offsets, and sibling FpsPane methods.
- Evidence against: raw starts lack modeled function/caller xrefs.
- Decision: accepted. The class is the narrow direct semantic owner for all four primary method ranges.

### 2. [UID:0000JK] FpsPane File - Accepted As Source Root And Aggregate Owner

- Evidence for: imported source name `FpsPane.cpp`, proposed source tree `ui/diagnostics/FpsPane.cpp`, FpsPane globals/string data, and no stronger competing source module.
- Evidence against: exact methods should attach to the class, not bypass it to the file.
- Decision: use as class/file/global/string source root; do not make it direct owner of class methods.

### 3. [UID:0000T6] MainUiLayerSlots - Dependency Only

- Evidence for: `dword_69B37C` is passed when showing the FpsPane rectangle.
- Evidence against: it owns the parent/layer pointer, not FpsPane methods, fields, strings, globals, or vtables.
- Decision: mention as dependency and unresolved naming issue. Do not assign FpsPane methods to it.

### 4. ParcelPane / MapPane / ObjectList - Rejected

- ParcelPane is stale generated pollution. No target behavior is parcel-specific.
- MapPane/ObjectList are read-only diagnostic data sources for [UID:00015H] and do not own the logging session.

## Negative Evidence Summary

- No direct callers, xrefs, or literal pointers to raw starts were found in existing MCP notes or local IDA export searches.
- No local executable was available to perform a fresh PE byte check.
- No preserved FpsPane UDT or original field names were available; field names above are descriptive.
- No writer to `g_fpsLogEnabled` was found. The flag remains an externally toggled/default-off diagnostic gate until another writer is found.
- No proof that `0x004b69b0` or `0x004b6ae0` execute at runtime. They should be documented as retained private helper bodies, not as proven live callbacks.

## Exact Supervisor-Owned Replacement Rows For `by-memory/-coverage-report.md`

Placement context: replace the existing FpsPane diagnostics rows at the `0x004b6409-0x004b6cb0` block. The unchanged sibling rows [UID:00015E], [UID:00015G], [UID:00015H], [UID:00015K], and [UID:00015L] can remain as-is unless the supervisor chooses to refresh stale "95/95" C++ wording separately.

```text
    - [UID:00015D][0x004b6410-0x004b6caf.FpsPaneDiagnostics](by-memory/0x004b6410-0x004b6caf.FpsPaneDiagnostics.md) 0x004b6410-0x004b6caf | class-cluster | FpsPaneDiagnostics : reconstructable : 87% : strong : B003 source-quality pass confirms the FpsPane diagnostics source island, modeled child functions, four raw source-authored starts, vtable/global/string ownership, retained helper-body inference for 0x004b69b0 and 0x004b6ae0, corrected logging field/string semantics, MainUiLayerSlots dependency through dword_69B37C, and child-level C++ readiness; aggregate C++ remains blank to avoid duplicating child method bodies.
        - [UID:00015C][0x004b6410-0x004b646b.FpsPaneConstructorRaw](by-memory/0x004b6410-0x004b646b.FpsPaneConstructorRaw.md) 0x004b6410-0x004b646b | raw constructor | FpsPaneConstructorRaw : reconstructable : 86% : strong : Raw FpsPane constructor attached to [UID:00005F] FpsPane; local IDA export confirms base Pane construction, g_pFpsPane write, compiler-generated vtable stores, inherited visible byte set, current-FPS clear, no direct call/xref, and source-shaped constructor C++ readiness.
        - [UID:00015F][0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw](by-memory/0x004b64a0-0x004b67a7.FpsPaneUpdateFpsLogSessionRaw.md) 0x004b64a0-0x004b67a7 | raw method | FpsPaneUpdateFpsLogSessionRaw : reconstructable : 88% : strong : FpsPane log-session toggle method attached to [UID:00005F]; local IDA export confirms start/finalize branches, duplicated/inlined StartLogSession and WriteLogSummary logic, month/day/hour/minute/second filename ordering, CP949 start/elapsed log strings, show/hide scheduler calls, MainUiLayerSlots dependency through dword_69B37C, no direct xref, and first-draft C++ readiness.
        - [UID:00015I][0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw](by-memory/0x004b69b0-0x004b6adc.FpsPaneStartLogSessionRaw.md) 0x004b69b0-0x004b6adc | raw helper | FpsPaneStartLogSessionRaw : reconstructable : 86% : strong : Retained FpsPane private start-log helper attached to [UID:00005F]; exact body resets tick/min/max/sample/FPS/object totals, optionally writes FPSDATA header/start timestamp from month/day/hour/minute/second when g_fpsDebugActive and g_fpsLogEnabled allow it, clears g_fpsDebugActive, has no proven caller/xref, and should receive helper-body draft C++ with liveness caveat.
        - [UID:00015J][0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw](by-memory/0x004b6ae0-0x004b6c2b.FpsPaneWriteLogSummaryRaw.md) 0x004b6ae0-0x004b6c2b | raw helper | FpsPaneWriteLogSummaryRaw : reconstructable : 86% : strong : Retained FpsPane private summary helper attached to [UID:00005F]; exact body gates on g_fpsLogEnabled, opens the current FPS log in append mode, writes divider, elapsed seconds, min/max/average FPS, average living/balloon/static object counts, closes the file, has no proven caller/xref, and should receive helper-body draft C++ with liveness caveat.
```

Placement context: under [UID:00025E] `FpsPaneReadOnlyData`, replace the stale vtable child row and insert the string child row immediately after it.

```text
        - [UID:0002MJ][0x0061a61c-0x0061a6a4.FpsPaneVtableData](by-memory/0x0061a61c-0x0061a6a4.FpsPaneVtableData.md) 0x0061a61c-0x0061a6a4 | vtable data | FpsPaneVtableData : reconstructable : 87% : strong : Exact FpsPane RTTI/vtable data assigned to [UID:00005F] FpsPane; live/local evidence confirms primary/secondary/timer vtable bases, paint/update/scalar-delete slots, lifecycle-store xrefs, adjustor-thunk slots, and the 0x0061a6a4 FPS string boundary; vtable bytes remain compiler-generated from class declarations.
        - [UID:0003BJ][0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData](by-memory/0x0061a6a4-0x0061a7dc.FpsPaneDiagnosticStringData.md) 0x0061a6a4-0x0061a7dc | diagnostic-string-data | FpsPaneDiagnosticStringData : reconstructable : 88% : very-strong : Exact FpsPane diagnostic string child routed to [UID:0000JK] FpsPane.cpp; B003 local IDA export adds the previously omitted CP949 start timestamp at 0x0061a6d8 and elapsed-time format at 0x0061a720, confirms filename/header/mode/summary/overlay string xrefs, and fixes timestamp ordering to month/day/hour/minute/second.
```

Placement context: under the `0x0066da90` initialized global row, replace the stale row.

```text
    - [UID:00027E][0x0066da90-0x0066da94.g_fpsDebugActive](by-memory/0x0066da90-0x0066da94.g_fpsDebugActive.md) 0x0066da90-0x0066da94 | initialized global flag | g_fpsDebugActive : reconstructable : 86% : strong : FpsPane diagnostics dword flag explicitly listed as `dword_66DA90 dd 1` in the local IDA export, used only by FpsPane start-session paths at 0x004b64e5/0x004b65f5/0x004b69bd/0x004b6acd, best described as a pending debug/log-session start flag, with owner/emitter [UID:0000JK] and final declaration `int g_fpsDebugActive = 1`.
```

Placement context: under [UID:0002AY] `ItemExchangeAndFpsSingletonGlobals`, insert these exact FpsPane child rows if the supervisor chooses to expose the already-created split children in coverage.

```text
        - [UID:0002W0][0x0069b334-0x0069b338.g_pFpsPane](by-memory/0x0069b334-0x0069b338.g_pFpsPane.md) 0x0069b334-0x0069b338 | global pointer storage | g_pFpsPane : reconstructable : 88% : strong : Exact FpsPane singleton storage assigned to [UID:0000JK]; local IDA export lists `dword_69B334 dd ?`, so model as zero-initialized `FpsPane* g_pFpsPane`, with constructor write at 0x004b6434 and ordinary/scalar destructor clears at 0x004b648a/0x004b6c70.
        - [UID:0002W1][0x0069b338-0x0069b339.g_fpsLogEnabled](by-memory/0x0069b338-0x0069b339.g_fpsLogEnabled.md) 0x0069b338-0x0069b339 | global flag storage | g_fpsLogEnabled : reconstructable : 88% : strong : Exact FpsPane log-enable byte assigned to [UID:0000JK]; local IDA export lists `byte_69B338 db ?`, so model as zero-initialized `bool g_fpsLogEnabled`, with compare refs at 0x004b653f/0x004b6645/0x004b6a17/0x004b6ae4 and no proven writer.
```

Recommended [UID:0002AY] parent-row note if it is edited later: remove or qualify the old "all-0xff initial bytes" statement for the FpsPane child slots because the local IDA export shows `dd ?` and `db ?` at `0x0069b334` and `0x0069b338`.

## Class/File/Type/Global Coverage Row Recommendations

These are not `by-memory/-coverage-report.md` rows, but they keep support coverage consistent.

```text
by-class/-coverage-report.md:
- [UID:00005F][FpsPane](by-class/FpsPane.md) : reconstructable : 87% : strong : B003 FpsPane source-quality pass resolves constructor/logging source shape, field names, helper names, timestamp semantics, global initializers, MainUiLayerSlots dependency, C++ policy, and stale ParcelPane pollution while preserving no-xref caveats for retained raw helpers.

by-file/-coverage-report.md:
- [UID:0000JK][FpsPane](by-file/FpsPane.md) : reconstructable : 88% : strong : `NexusTK/ui/diagnostics/FpsPane.cpp` FPS diagnostics overlay/logging module with class, globals, vtables, strings, constructor/session/helper source shape, corrected month/day/hour/minute/second log timestamp semantics, zero-initialized g_pFpsPane/g_fpsLogEnabled storage, explicit g_fpsDebugActive initializer, MainUiLayerSlots parent-layer dependency, and final child-method C++ routing.

by-type/by-struct/-coverage-report.md:
- [UID:0001UO][FpsPaneLayout](by-type/by-struct/FpsPaneLayout.md) : reconstructable : 88% : strong : FpsPane diagnostic layout attached to FpsPane; B003 source-quality pass confirms field names/types through +0x168, distinguishes totals from averages, resolves filename timestamp ordering, records g_fpsLogEnabled/g_fpsDebugActive semantics, and keeps raw-helper liveness as the remaining score cap.

by-global/-coverage-report.md:
- [UID:0000PY][g_fpsDebugActive](by-global/g_fpsDebugActive.md) : reconstructable : 88% : strong : FpsPane diagnostic-session start-pending dword with explicit `dd 1` initializer, four FpsPane compare/clear refs, stale ParcelPane owner rejection, and final source declaration `int g_fpsDebugActive = 1`.
- [UID:0000PZ][g_fpsLogEnabled](by-global/g_fpsLogEnabled.md) : reconstructable : 89% : strong : FpsPane log-write gate byte with local IDA export `db ?` zero-initialized storage, four FpsPane compare refs, no proven writer, stale `0xff` initializer correction, and final source declaration candidate `bool g_fpsLogEnabled`.
- [UID:0000QZ][g_pFpsPane](by-global/g_pFpsPane.md) : reconstructable : 87% : strong : FpsPane singleton with local IDA export `dd ?` zero-initialized storage, constructor write, ordinary/scalar destructor clears, and final source declaration `FpsPane* g_pFpsPane`.
```

## Support Docs Supervisor Should Update

Apply all valid details at report-level specificity, not as short summaries:

- [UID:00015C] `FpsPaneConstructorRaw`: raise to `86/90`; replace stale "keep C++ blank until caller path" wording with active C++ gate; add constructor source-shape notes; note vtable stores are compiler-generated and should not be in C++.
- [UID:00015F] `FpsPaneUpdateFpsLogSessionRaw`: raise to `88/88`; add helper-call source-shape inference; document `dword_69B37C` as MainUiLayerSlots dependency; correct timestamp fields to month/day/hour/minute/second; add first-draft C++.
- [UID:00015I] `FpsPaneStartLogSessionRaw`: raise to `86/87`; classify as retained private helper with no proven caller; add CP949 start-line byte literal and month/day/hour/minute/second ordering; add first-draft C++.
- [UID:00015J] `FpsPaneWriteLogSummaryRaw`: raise to `86/87`; classify as retained private helper with no proven caller; add CP949 elapsed-time byte literal and `/1000` elapsed seconds; add first-draft C++.
- [UID:00015D] `FpsPaneDiagnostics`: raise to `87/87`; aggregate C++ blank; incorporate helper-retention inference, field/global/string corrections, and child C++ policy.
- [UID:00005F] `FpsPane`: raise to `87/88`; replace open question "decide whether raw helpers are dead duplicate/private/boundary artifacts" with the best current inference: retained private helpers or old helpers, no proven caller; list final descriptive fields.
- [UID:0000JK] `FpsPane` file: raise to `88/87`; add global declarations, `MainUiLayerSlots` dependency, and source-placement reasoning. Keep separate from ParcelPane, MapPane, ObjectList, and MainUiGraph.
- [UID:0001UO] `FpsPaneLayout`: raise to `88/90`; update field names to totals vs averages; add filename timestamp field order; add `g_fpsLogEnabled` zero-initialized source-storage correction.
- [UID:0003BJ] `FpsPaneDiagnosticStringData`: add the omitted `0x0061a6d8` and `0x0061a720` rows and xrefs. Use ASCII-safe byte escapes in this report or actual CP949/Korean text if the target file supports it.
- [UID:0002MJ] `FpsPaneVtableData` and [UID:0001XN] `FpsPane_vtables`: no major score change required, but remove stale coverage text saying unassigned/parent below gate.
- [UID:0000QZ] `g_pFpsPane` and [UID:0002W0] exact storage: correct initializer language to `dd ?` / zero-initialized source storage.
- [UID:0000PZ] `g_fpsLogEnabled` and [UID:0002W1] exact storage: correct initializer language to `db ?` / zero-initialized source storage; do not say `0xff` unless later raw PE evidence proves the local listing wrong.
- [UID:0000PY] `g_fpsDebugActive` and [UID:00027E] exact storage: keep explicit dword initializer `1`; add semantic alias "debug/log session start pending" as descriptive, not original-proof.
- [UID:0000T6] `MainUiLayerSlots`: add that FpsPane `UpdateFpsLogSession` uses `dword_69B37C` as the parent/layer pointer for the FPS overlay; do not rename it from FpsPane evidence alone.
- [UID:00025E] `FpsPaneReadOnlyData`: add/reflect exact string child [UID:0003BJ], correct stale parent-gate/unassigned text for [UID:0002MJ], and preserve aggregate/mixed-tail caveats separately.
- `wave3_data_issues.md`: update the FpsPane section to include the helper-call source-shape inference, the CP949 string labels, `g_fpsLogEnabled db ?`, and the fact that the old 95/95 C++ blocker is stale policy.

## Final Recommendation

- Assignments: keep all four targets attached to [UID:00005F] FpsPane with `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00005F`.
- Scores: raise [UID:00015C] to `86/90`, [UID:00015F] to `88/88`, [UID:00015I] to `86/87`, and [UID:00015J] to `86/87`.
- C++: populate all four target C++ blocks using the first-draft code above. Keep aggregate/class/file pages from duplicating child bodies.
- Remaining blocker: only original caller/liveness for raw starts remains unresolved. This is a score cap and historical caveat, not an ownership or first-draft C++ blocker under the active combined-score/emitter policy.
- Future work outside this assignment: recover final names for `dword_69B37C` and the Pane/timer helper methods, and locate any hidden writer/config path for `g_fpsLogEnabled`.

## Confidence

- Recommendation confidence: strong.
- Score confidence: medium-strong. The page bodies can justifiably clear the active code gate, but no target should approach `95+` until live IDA MCP/raw PE checks and final class declarations are complete.
- Remaining uncertainty: raw helper runtime liveness, final inherited method names, final MainUiLayerSlots slot name, and exact global declaration type for `g_fpsLogEnabled`.

## Validator Results

- No validator was run before creating this report because no by-* documentation was edited.
- IDA MCP was unavailable as recorded above.
- Local IDA export commands used:

> Executable block R004 was removed from this report and preserved verbatim in [00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md](00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md). The archived block is non-authoritative and must not be executed.

- Key results:
  - raw start addresses appear only as definitions in the local listing.
  - `dword_66DA90 dd 1`.
  - `dword_69B334 dd ?`.
  - `byte_69B338 db ?`.

## Changed Files

- Created:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:26","uid":"00015C"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00015C-00015F-00015I-00015J-FpsPaneDiagnosticsSourceQuality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00015C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
