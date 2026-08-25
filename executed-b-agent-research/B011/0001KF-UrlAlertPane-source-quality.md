** TARGET-REPORT-UID:0001KF **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KF UrlAlertPane Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0001KF] from a documented-but-blank aggregate to a source-bearing `UrlAlertPane` method cluster with first-draft C++ for the constructor, ordinary destructor, and primary-button/confirm handler.
- Final disposition: keep the existing aggregate range `0x00599a40-0x00599cb3`; do not split before implementation. The page should explicitly mark `0x00599bd0`, `0x00599bdb-0x00599bf1`, and `0x00599c00-0x00599cb3` as compiler-generated cleanup/thunk/deleting-destructor glue regenerated from source declarations/destructor behavior, not handwritten C++.
- Required action: update the target and support docs; do not edit `by-memory/-coverage-report.md` directly. Exact replacement rows are included below.
- Metadata recommendation for target: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000FF`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FF`, blank `EMITTER_POSITION_OPTIONAL`.
- Score change: `84/90 -> 88/91`.
- Confidence: very strong for behavior, range, source owner, field roles, caller routing, and compiler glue classification. Remaining uncertainty is helper API spelling and exact original class/field spelling, not behavior or source placement.

## Target

- Target UID: `0001KF`
- Target name: `UrlAlertPane`
- Primary doc: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00599a40-0x00599cb3.UrlAlertPane.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B011\research\0001KF-UrlAlertPane-source-quality.md`
- Current target metadata: `84/90`, `CANONICAL_OWNER:0000HE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HE`, formal C++ blank.
- Current generated route: `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`.
- Direct source owner recommendation: [UID:0000FF] `UrlAlertPane` class, which already emits through [UID:0000HE] `AlertPanes`.

## Supervisor Active Recheck

- The supervisor assigned a B-agent report-only pass for [UID:0001KF] `UrlAlertPane`.
- No by-* target/support docs were edited.
- No coverage report was edited.
- No leases were needed because this report is inside Agent-B011's own research folder.
- This target does not require immediate split execution during the report phase. It is a coherent class method/destructor cluster with mixed source-authored and compiler-generated subranges. The correct implementation is to document the subrange source/no-code factoring and emit only the source-authored methods from the aggregate.

## Evidence Checked

- Required instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Target/support docs:
  - [UID:0001KF] `by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md`
  - [UID:0000FF] `by-class/UrlAlertPane.md`
  - [UID:0000HE] `by-file/AlertPanes.md`
  - [UID:0000SM] `by-global/g_pUrlAlertPane.md`
  - [UID:0001TO] `by-type/by-struct/AlertPaneLayout.md`
  - [UID:0001YZ] `by-type/by-vtable/UrlAlertPaneVtables.md`
  - [UID:0002P0] `by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md`
  - [UID:0002WC] `by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md`
  - [UID:00026S] `by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md`
  - [UID:00022Y] `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`
  - [UID:00037T] `by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md`
  - [UID:00037U] `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md`
  - [UID:00012W] `by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md`
  - [UID:00000B] `by-class/AlertPane.md`
  - [UID:00012R] `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
  - [UID:000196] `by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md`
  - [UID:000197] `by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md`
  - [UID:0001BC] `by-memory/0x00516030-0x00516036.GetMemoryMan.md`
  - [UID:0001BD] `by-memory/0x00516050-0x005160ce.AllocateBufferMemory.md`
  - [UID:0001BF] `by-memory/0x00516170-0x00516184.FreeBufferMemory.md`
  - [UID:0002H3] `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
  - [UID:000294] `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`
  - [UID:0001OC] `by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md`
- Generated/project docs:
  - `auto-generated/-ag-memory-coverage.md`
  - `auto-generated/-ag-class-coverage.md`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-global-coverage.md`
  - `auto-generated/-ag-type-coverage.md`
  - `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`
  - `auto-generated/NexusTK/login/MainMenuPane.cpp`
  - `project-level/-auto-completion-stats.md`
  - `project-level/-resolved.md`
  - `project-level/-unresolved.md`
  - `wave3_data_issues.md`
- Prior B-agent research search:
  - Searched `source-3/project-documentation/tools/leaser/Agents/Agent-B*/research` recursively for `0001KF`, `UrlAlertPane`, and `0x00599a40`.
  - No prior B-agent report for this target was found.
- IDA MCP:
  - Attempted `tools/list` against `http://127.0.0.1:13337/mcp`.
  - Result: `Unable to connect to the remote server`.
  - Impact: no fresh live IDA MCP decompile/xref output was available in this session. I used existing IDA-backed docs plus direct raw PE and Capstone checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Raw PE / Capstone evidence:
  - Parsed PE sections locally. Image base `0x00400000`; `.text` starts at `0x00401000`.
  - Verified raw bytes, boundaries, vtable dwords, data refs, and direct rel32 caller sets.

## Raw PE / Disassembly Facts

### Boundary and Subrange Facts

Raw PE byte checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` confirm:

| Range | Role | Raw evidence summary |
| --- | --- | --- |
| `0x00599a34-0x00599a40` | predecessor padding | twelve `0xcc` bytes before target start. |
| `0x00599a40-0x00599b19` | source constructor | modeled method body ending in `ret 0x14`. |
| `0x00599b19-0x00599b20` | alignment | seven `0xcc` bytes. |
| `0x00599b20-0x00599b92` | ordinary non-deleting destructor body | source-authored cleanup shape ending in `ret`. |
| `0x00599b92-0x00599ba0` | alignment | fourteen `0xcc` bytes. |
| `0x00599ba0-0x00599bcf` | primary-button confirm handler | vtable-only handler ending in `ret`, followed by `0xcc`. |
| `0x00599bd0-0x00599bda` | constructor cleanup helper | `mov [g_pUrlAlertPane], 0; ret`; rel32 reference from compiler cleanup area only. |
| `0x00599bdb-0x00599bf1` | adjustor thunks | `sub ecx, 0xa0; jmp 0x00599c00` and `sub ecx, 0xa4; jmp 0x00599c00`. |
| `0x00599bf1-0x00599c00` | alignment | fifteen `0xcc` bytes. |
| `0x00599c00-0x00599cb3` | scalar deleting destructor wrapper | duplicates destructor cleanup, accepts delete flags, optionally frees object storage, then `ret 4`. |
| `0x00599cb3-0x00599cc0` | successor padding | thirteen `0xcc` bytes before `UserInfoDialogPane`. |

No split is required for the report phase because the aggregate page can correctly describe these subranges, but the source/no-code distinction must be made explicit.

### Constructor Facts

Disassembly of `0x00599a40` shows:

- Saves first argument byte at `[ebp+8]` into `this+0x274`.
- Calls [UID:00012W] `AlertPane::AlertPane` at `0x0049feb0` with:
  - message text from `[ebp+0x10]`,
  - layout/reference pane from `[ebp+0x0c]`,
  - primary button label at `0x00613a18` (`L"OK"`),
  - null secondary button.
- Publishes [UID:0000SM] `g_pUrlAlertPane` at `0x0069b4dc`.
- Installs three `UrlAlertPane` vtables:
  - `0x0062e584` at `this+0x00`,
  - `0x0062e5ec` at `this+0xa0`,
  - `0x0062e61c` at `this+0xa4`.
- Initializes `this+0x270` to null, allocates `urlLength + 1` bytes through `GetMemoryMan` / `AllocateBufferMemory`, copies `urlLength` bytes through the copy helper at `0x005de74a`, and writes a NUL terminator at `m_url[urlLength]`.
- Returns `this` and pops five stack arguments with `ret 0x14`.

Recommended source signature:

```cpp
UrlAlertPane::UrlAlertPane(bool exitAfterOpen,
                           Pane *layoutReference,
                           const wchar_t *messageText,
                           const char *urlText,
                           unsigned int urlLength);
```

This matches all three constructor call sites.

### Ordinary Destructor Facts

Disassembly of `0x00599b20` shows:

- Restores the same three `UrlAlertPane` vtables at `this+0x00`, `this+0xa0`, and `this+0xa4`.
- Calls `GetMemoryMan`, pushes `this+0x270`, and calls [UID:0001BF] `FreeBufferMemory`.
- Clears [UID:0000SM] `g_pUrlAlertPane`.
- Calls [UID:00012R] `DialogPane` cleanup at `0x0049d9f0`, which is inherited/base teardown and should not be hand-written in the derived destructor source.

Recommended source body is:

```cpp
UrlAlertPane::~UrlAlertPane()
{
    GetMemoryMan()->FreeBufferMemory(m_url);
    g_pUrlAlertPane = NULL;
}
```

If the project later standardizes `char[]` allocation wrappers as `new[]` / `delete[]`, this can be mechanically converted. For this report, the MemoryMan helper spelling is safer because the binary calls `GetMemoryMan` / `AllocateBufferMemory` / `FreeBufferMemory` directly rather than the scalar `operator new` / `operator delete` wrapper pair.

### Confirm Handler Facts

Disassembly of `0x00599ba0` shows:

- Pushes `SW_SHOWNORMAL` (`1`), null parameters, and `this+0x270`, then calls `ShellExecuteA` through the import slot at `0x0060d344`.
- Tests byte `this+0x274`.
- If the byte is nonzero, loads [UID:000294] `g_pApplication` from `0x0067ab1c` and jumps to [UID:0002H3] `Application::RequestExit` at `0x00464e40`.
- The only raw data reference to this method is vtable slot `0x0062e5e0`.

Source-facing name decision:

- Existing docs call this `UrlAlertPane::OnConfirm`, which is behaviorally descriptive.
- [UID:00000B] `AlertPane` now emits the base callback slots as `OnPrimaryButton()` and `OnSecondaryButton()`.
- In C++ source, an override must use the base virtual function name. Therefore the recommended formal source name is `UrlAlertPane::OnPrimaryButton()`, with "confirm handler" retained as prose/alias text.

### Compiler Glue Facts

`0x00599bd0-0x00599bda`:

- Body is only `g_pUrlAlertPane = 0; ret`.
- Raw scan found only a rel32 reference from `0x00609c51`, consistent with compiler EH/unwind cleanup, not an ordinary source call site.
- Recommendation: name/document as `UrlAlertPaneConstructorClearSingletonOnUnwind` or `ClearUrlAlertPaneSingletonOnConstructorUnwind`; no formal C++ body.

`0x00599bdb-0x00599bf1`:

- Contains two MSVC adjustor thunks:
  - `0x00599bdb`: `this -= 0xa0; jmp 0x00599c00`
  - `0x00599be6`: `this -= 0xa4; jmp 0x00599c00`
- Only vtable data refs at `0x0062e5ec` and `0x0062e61c`.
- Recommendation: compiler/linker-generated, not handwritten C++.

`0x00599c00-0x00599cb3`:

- Primary vtable slot `0x0062e584` points here.
- The wrapper duplicates the destructor cleanup, then reads delete flags from `[ebp+8]`.
- If `flags & 1` and not `flags & 4`, it frees object storage through [UID:000197] `OperatorDeleteWrapper` at `0x004f4ac0`.
- If `flags & 4`, it calls the guard/helper path at `0x0041b6a0` with size `0x278`.
- Recommendation: MSVC scalar deleting destructor glue generated from `virtual ~UrlAlertPane()`, not handwritten C++. The source destructor body belongs to `0x00599b20`; the wrapper itself should remain formal-C++ blank in prose if split later.

### Vtable/Data Facts

Raw dword checks confirm:

| Address | Dword | Meaning |
| --- | --- | --- |
| `0x0062e584` | `0x00599c00` | primary scalar deleting destructor slot. |
| `0x0062e5e0` | `0x00599ba0` | primary callback slot `+0x5c`; formal source override `OnPrimaryButton`. |
| `0x0062e5ec` | `0x00599bdb` | secondary destructor adjustor thunk. |
| `0x0062e61c` | `0x00599be6` | tertiary destructor adjustor thunk. |

Raw dword refs to vtable bases:

- `0x0062e584` referenced by stores at `0x00599aae`, `0x00599b47`, and `0x00599c2e`.
- `0x0062e5ec` referenced by stores at `0x00599ab8`, `0x00599b51`, and `0x00599c38`.
- `0x0062e61c` referenced by stores at `0x00599ac2`, `0x00599b5b`, and `0x00599c42`.

Raw dword refs to `g_pUrlAlertPane`:

- `0x00508fd8` duplicate-open guard read.
- `0x00599a95` constructor publish.
- `0x00599a9d` constructor null/fallback path.
- `0x00599b75` ordinary destructor clear.
- `0x00599bd2` constructor-unwind helper clear.
- `0x00599c5c` scalar deleting destructor clear.

### Caller / Reachability Facts

Raw PE rel32 scan found exactly three direct calls to the constructor:

| Call site | Owner/context | Meaning |
| --- | --- | --- |
| `0x00503034` | [UID:00022Y] MainMenu ANSI text URL dialog packet helper | Pre-login opcode `0x66` subtype `1`/`2` URL prompt; first argument `1` for subtype `1`. |
| `0x00513f7e` | MapPane packet handler region | In-game/map opcode `0x66` URL alert path; first argument `1`. |
| `0x0051402f` | MapPane packet handler region | In-game/map opcode `0x66` URL alert path; first argument `0`. |

The constructor has no direct source ownership in MainMenu or MapPane. Those are packet adapters/consumers. `UrlAlertPane` remains the reusable dialog implementation under `AlertPanes.cpp`.

Raw PE scan found no ordinary direct call to:

- `0x00599b20` ordinary destructor,
- `0x00599ba0` confirm handler,
- `0x00599bdb` or `0x00599be6` adjustor thunks,
- `0x00599c00` scalar deleting destructor except the two thunk jumps.

This is expected for virtual method/destructor dispatch and does not block source C++.

## Function / Child Inventory

| Range / Item | Role | Reconstructable | Direct parent recommendation | Source/C++ policy | Score/status |
| --- | --- | --- | --- | --- | --- |
| `0x00599a40-0x00599b19` | `UrlAlertPane::UrlAlertPane` | yes | [UID:0000FF] `UrlAlertPane` | source-authored; include first-draft C++ | ready |
| `0x00599b20-0x00599b92` | `UrlAlertPane::~UrlAlertPane` ordinary destructor | yes | [UID:0000FF] `UrlAlertPane` | source-authored; include first-draft C++ | ready |
| `0x00599ba0-0x00599bcf` | primary-button confirm handler | yes | [UID:0000FF] `UrlAlertPane` | source-authored; formal name `OnPrimaryButton`, prose alias `OnConfirm` | ready |
| `0x00599bd0-0x00599bda` | constructor singleton-clear unwind helper | no independent source body | [UID:0000FF] `UrlAlertPane` as compiler cleanup context | document no-code compiler EH cleanup; formal C++ blank | resolved |
| `0x00599bdb-0x00599bf1` | secondary/tertiary destructor adjustor thunks | compiler-generated | [UID:0000FF] `UrlAlertPane` as vtable context | no handwritten C++ | resolved |
| `0x00599c00-0x00599cb3` | scalar deleting destructor wrapper | compiler-generated | [UID:0000FF] `UrlAlertPane` as vtable context | no handwritten C++; generated from destructor declaration/body | resolved |

## Heuristic / Inference Reanalysis And Validation

### Source Placement

- Best direction: [UID:0000HE] `AlertPanes.cpp` through direct class parent [UID:0000FF] `UrlAlertPane`.
- Evidence: constructor derives from [UID:00000B] `AlertPane`, uses shared `DialogOkButtonString`, installs `UrlAlertPane` vtables, and has consumers from both MainMenu and MapPane packet paths.
- Rejected alternatives:
  - `MainMenuPane`: owns only the pre-login opcode adapter at `0x00503034`, not the reusable URL alert class.
  - `MapPane`: owns only the in-game/map opcode adapter call sites at `0x00513f7e` and `0x0051402f`, not the reusable URL alert class.
  - `Browser`: rejected because `ShellExecuteA` is a simple external URL launch from an alert, with no browser-pane COM/OLE state.
  - `Application`: owns `RequestExit`, not URL alert storage/dispatch.
- Impact: change target direct owner/emitter from file `0000HE` to class `0000FF`; the generated source still lands in `AlertPanes.cpp`.

### Range / Split / Merge

- Best direction: keep one aggregate page for this implementation pass, with exact subrange source/no-code classification.
- Evidence: all subranges are one compact `UrlAlertPane` constructor/destructor/vtable-tail island; no unrelated source owner appears inside `0x00599a40-0x00599cb3`.
- Rejected split-now alternative: splitting the clear helper/thunks/scalar wrapper into exact children would improve granularity but is not required before correcting source-quality, because the current page already has exact subrange rows and the aggregate is a real class method cluster.
- Impact: no file rename/split recommended for this report. If future supervisor policy requires exact destructor glue pages, split `0x00599bd0-0x00599bda`, `0x00599bdb-0x00599bf1`, and `0x00599c00-0x00599cb3` as non-emitting compiler-glue children while preserving this aggregate as the source method cluster.

### Inherited Virtual Names

- Best direction: formal source override name should be `OnPrimaryButton()`, not `OnConfirm()`, because [UID:00000B] `AlertPane` now emits the base slot as `OnPrimaryButton`.
- Evidence: primary vtable slot `+0x5c` points to `0x00599ba0`; base `AlertPane::DismissDialog(int buttonId, int unused)` dispatches button id `1` to the no-argument primary slot.
- Rejected alternative: keeping formal C++ as `OnConfirm()` would not override the current base declaration unless the base is also renamed. It can remain as a semantic alias in prose.
- Impact: resolves the inherited slot-name blocker for first-draft C++.

### Fields / Types

- `this+0x270`: best source field `char *m_url`.
  - Evidence: constructor allocates `urlLength + 1`, copies raw `char` bytes, writes NUL terminator; `ShellExecuteA` consumes the pointer directly; destructor frees it.
  - Rejected alternatives: wide-string field (rejected by ANSI copy and `ShellExecuteA` `LPCSTR` call), borrowed pointer (rejected by allocation/free), `StringBase` (rejected by raw byte allocation/copy/free shape).
- `this+0x274`: best source field `bool m_exitAfterOpen`.
  - Evidence: constructor stores first argument byte; confirm handler tests it and calls `Application::RequestExit` only when nonzero.
  - Rejected alternatives: mode enum with more cases (only zero/nonzero branch observed), URL length tail storage (length is not stored after copy).
- `g_pUrlAlertPane`: best source declaration `UrlAlertPane *g_pUrlAlertPane = NULL;`.
  - Evidence: constructor publishes `this`, destructor/scalar wrapper/unwind cleanup clear it, MapPane duplicate-open guard reads it, exact storage child is one zero-initialized dword.
  - Linkage caveat: final `static` versus external spelling is not proven. Since the global has a documented public by-global page and cross-module guard read, keep the declaration non-static in first draft unless a later source-layout pass proves internal linkage.

### Helper Names

- `0x00516030`: use [UID:0001BC] `GetMemoryMan`.
- `0x00516050`: use [UID:0001BD] `AllocateBufferMemory`.
- `0x00516170`: use [UID:0001BF] `FreeBufferMemory`.
- `0x005de74a`: use ordinary `memcpy`/copy helper in source; the call copies `urlLength` bytes.
- `0x00464e40`: use [UID:0002H3] `Application::RequestExit`.
- `0x0049d9f0`: use inherited/base `DialogPane` destructor cleanup; do not write a direct call in `UrlAlertPane::~UrlAlertPane`.
- `0x004f4ac0`: use [UID:000197] `OperatorDeleteWrapper` only in scalar deleting destructor proof; no source call in target C++.
- `0x0041b6a0`: compiler guard/helper path for delete flag `4`; no source call in target C++.

### Constructor Exception Cleanup

- Best direction: no handwritten source helper.
- Evidence: `0x00599bd0` only clears `g_pUrlAlertPane` and has no ordinary direct caller; existing vtable docs already separate it from the adjustor thunks.
- Source-level interpretation: after the constructor publishes `g_pUrlAlertPane`, compiler EH cleanup clears the singleton if later URL-buffer allocation/copy throws.
- Impact: resolves the "exception-cleanup source shape" blocker without adding bogus C++.

### Thunks / Scalar Deleting Destructor

- Best direction: compiler-generated no-code glue.
- Evidence: thunks are pure `this` adjust-and-jump; scalar wrapper is vtable slot target with delete-flags parameter and duplicated destructor body; optional object free through `0x004f4ac0` when bit `1` is set and bit `4` is clear.
- Impact: do not emit the scalar wrapper or thunks as source bodies. They are regenerated from `virtual ~UrlAlertPane()` and multiple-inheritance class layout.

### Caller / Owner Routing

- Best direction: `MainMenuPane` and `MapPane` own packet parsers; `AlertPanes` owns reusable alert class.
- Evidence: direct constructor calls from `0x00503034`, `0x00513f7e`, and `0x0051402f` all allocate a `0x278`-sized object and pass packet-derived URL/message bytes to the same constructor. The callers differ by subsystem, but the constructed class and vtables are identical.
- Impact: support docs should say caller packet adapters construct `UrlAlertPane` but do not own the class implementation.

### Current-Stale Wording

- Stale blocker: target/class/vtable docs still say final C++ remains blank because inherited virtual names, signatures, exception cleanup, or a historical `95/95` gate are unresolved.
- Current status: inherited callback slot names, constructor signature, fields, helper roles, source placement, and compiler cleanup policy are now resolved enough for first-draft C++ under the active combined-score/emitter gate.
- Impact: replace stale wording with current gate reasoning and any remaining narrow caveats.

## Ranked Ownership Analysis

### 1. [UID:0000FF] UrlAlertPane Class

- Evidence for:
  - All source-authored target methods are `UrlAlertPane` methods.
  - Exact vtable data [UID:0002P0] is already assigned to [UID:0000FF].
  - [UID:0000FF] is `88/90` and emits through [UID:0000HE] `AlertPanes`.
  - The target's current file-level owner bypasses the narrower direct semantic owner.
- Evidence against:
  - The page currently uses file-level owner `0000HE`.
  - Class C++ is still blank in current docs.
- Decision:
  - Accept as direct canonical owner and emitter. Update target to `CANONICAL_OWNER:0000FF`, `EMITTER_UIDS:0000FF`. Also populate class declaration support so generated output has a coherent source shape.

### 2. [UID:0000HE] AlertPanes File

- Evidence for:
  - Correct source file/root for shared alert family.
  - Current generated output lands in `auto-generated/NexusTK/ui/dialogs/AlertPanes.cpp`.
  - Owns `AlertPane`, `VersatileAlertPane`, `BlueAlertPane`, `UrlAlertPane`, and `g_pUrlAlertPane`.
- Evidence against:
  - It is broader than the direct method owner.
- Decision:
  - Keep as source root through class/global pages, but do not keep as direct owner for the method cluster.

### 3. MainMenuPane / MapPane

- Evidence for:
  - Direct constructor call sites are packet parser consumers.
- Evidence against:
  - They do not own the vtables, fields, destructor, or reusable alert behavior.
  - The same class is constructed from both MainMenu and MapPane packet paths.
- Decision:
  - Reject as class/method owner. Keep packet helpers in their own files.

## Recommended Exact Doc Changes

### Target: [UID:0001KF] `0x00599a40-0x00599cb3.UrlAlertPane.md`

Header:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended prose changes:

- Replace "Current Wave3 owner" / file-level owner wording with direct class owner [UID:0000FF] and source root [UID:0000HE].
- Replace stale "final C++ remains blank because inherited virtual names/signatures/exception cleanup need audit" wording.
- Add current gate analysis: after this pass the target is `88/91`, reconstructable, and emits through the class-to-file route, so first-draft C++ is eligible.
- Rename formal source method `0x00599ba0` to `UrlAlertPane::OnPrimaryButton`; keep "confirm handler" / `OnConfirm` as semantic alias.
- Add a "Source / Compiler Glue Factoring" section:
  - `0x00599a40-0x00599b19`: source constructor.
  - `0x00599b20-0x00599b92`: source ordinary destructor.
  - `0x00599ba0-0x00599bcf`: source primary-button confirm handler.
  - `0x00599bd0-0x00599bda`: compiler EH cleanup helper that clears singleton.
  - `0x00599bdb-0x00599bf1`: compiler adjustor thunks.
  - `0x00599c00-0x00599cb3`: MSVC scalar deleting destructor wrapper.
- Add raw PE facts from this report: padding counts, three constructor calls, vtable dword refs, six `g_pUrlAlertPane` refs, and no ordinary direct refs to the destructor/thunks/scalar wrapper.
- Replace helper names:
  - `this+0x270` -> `m_url`
  - `this+0x274` -> `m_exitAfterOpen`
  - `0x00516030` -> `GetMemoryMan`
  - `0x00516050` -> `AllocateBufferMemory`
  - `0x00516170` -> `FreeBufferMemory`
  - `0x00464e40` -> `Application::RequestExit`
  - `0x0049d9f0` -> inherited `DialogPane` cleanup/base destructor
- Add first-draft C++ shown below.

### Support: [UID:0000FF] `by-class/UrlAlertPane.md`

Recommended metadata:

- Raise from `88/90` to `89/91`.
- Keep `CANONICAL_OWNER:0000HE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HE`.

Recommended C++ declaration:

```cpp
class UrlAlertPane : public AlertPane
{
public:
    UrlAlertPane(bool exitAfterOpen,
                 Pane *layoutReference,
                 const wchar_t *messageText,
                 const char *urlText,
                 unsigned int urlLength);
    virtual ~UrlAlertPane();

protected:
    virtual void OnPrimaryButton();

private:
    char *m_url;
    bool m_exitAfterOpen;

    [[CHILDREN]]
};
```

Recommended prose:

- State that `OnConfirm` is the semantic role, but formal source name should follow the base `OnPrimaryButton()` virtual slot.
- State that the class owns `m_url` and frees it in the destructor.
- State that `m_exitAfterOpen` controls the optional `g_pApplication->RequestExit()` after `ShellExecuteA`.
- State that scalar deleting destructor and adjustor thunks are compiler-generated from the virtual destructor.
- State that MainMenu and MapPane opcode `0x66` helpers are consumers/packet adapters.

### Support: [UID:0000HE] `by-file/AlertPanes.md`

Recommended prose:

- Update the `UrlAlertPane` row to say it is now source-ready at method-body draft level.
- Keep file score unchanged or at most raise to `86/89` only if the supervisor also incorporates the class/global declaration changes. Do not over-raise: `BlueAlertPane` reachability and original filename caveats still cap the file.
- Clarify that target [UID:0001KF] emits through class [UID:0000FF], while [UID:0000SM] owns the singleton declaration.

### Support: [UID:0001TO] `by-type/by-struct/AlertPaneLayout.md`

Recommended prose:

- Replace `heap-owned URL buffer` at `+0x270` with `UrlAlertPane::m_url`.
- Replace `exit-after-open flag` at `+0x274` with `UrlAlertPane::m_exitAfterOpen`.
- Add that the object allocation and scalar wrapper guard path show an observed `UrlAlertPane` object size of `0x278`, but final class `sizeof` spelling remains source-layout dependent.
- Keep inherited field-name caveats for `DialogPane` fields; they no longer block [UID:0001KF] C++.

### Support: [UID:0001YZ] and [UID:0002P0] vtable docs

Recommended prose:

- Rename the primary `+0x5c` target as `UrlAlertPane::OnPrimaryButton` with semantic alias "confirm handler".
- Explicitly state the secondary/tertiary destructor entries point to compiler-generated adjustor thunks and must not emit handwritten C++.
- Replace any old `95/95` final-C++ wording with active current gate/no-code proof wording.
- Keep [UID:0002P0] C++ blank because the vtable data is source-declared/generated-binary, not hand-authored dwords.

### Support: [UID:0000SM] `by-global/g_pUrlAlertPane.md`

Recommended metadata:

- Raise from `86/91` to `87/92` if declaration C++ is added.
- Keep `CANONICAL_OWNER:0000HE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HE`.

Recommended C++:

```cpp
UrlAlertPane *g_pUrlAlertPane = NULL;
```

Recommended prose:

- Replace old `95/95` emission-bar wording with current combined-score/emitter gate.
- State that the declaration is file/global source state under `AlertPanes.cpp`; exact `static` linkage is not proven and should stay non-static unless later source evidence proves internal linkage.
- Mention the six exact data refs listed in this report.

### Support: [UID:0002WC] `0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md`

Recommended prose only:

- Keep direct owner [UID:0000SM].
- Cross-link to the target update and record that the target now supplies source C++ using `g_pUrlAlertPane`.
- Do not add duplicate C++ here unless the global parent remains blank; the direct global page [UID:0000SM] is the better source declaration home.

### Support: [UID:00022Y] MainMenu and MapPane packet docs

Recommended prose:

- No ownership changes.
- In MainMenu docs, the first-draft call to `new UrlAlertPane(subtype == 1, g_pMainUiGraph, messageText, urlText, urlLength);` remains valid.
- For MapPane support, record when convenient that the two additional constructor calls at `0x00513f7e` and `0x0051402f` are in-game/map opcode `0x66` analogs with exit flag `1` and `0`; they construct the reusable alert and do not own it.

## First-Draft C++ Recommendation

Populate the target [UID:0001KF] formal C++ block with source-authored methods only:

```cpp
UrlAlertPane::UrlAlertPane(bool exitAfterOpen,
                           Pane *layoutReference,
                           const wchar_t *messageText,
                           const char *urlText,
                           unsigned int urlLength)
    : AlertPane(messageText, layoutReference, L"OK", NULL),
      m_url(NULL),
      m_exitAfterOpen(exitAfterOpen)
{
    g_pUrlAlertPane = this;

    m_url = static_cast<char *>(GetMemoryMan()->AllocateBufferMemory(urlLength + 1));
    memcpy(m_url, urlText, urlLength);
    m_url[urlLength] = '\0';
}

UrlAlertPane::~UrlAlertPane()
{
    GetMemoryMan()->FreeBufferMemory(m_url);
    g_pUrlAlertPane = NULL;
}

void UrlAlertPane::OnPrimaryButton()
{
    ShellExecuteA(NULL, NULL, m_url, NULL, NULL, SW_SHOWNORMAL);

    if (m_exitAfterOpen)
        g_pApplication->RequestExit();
}
```

Notes for implementation:

- Do not include vtable restores, `DialogPane` destructor calls, scalar deleting destructor flags, object storage free, or constructor-unwind helper calls in handwritten source.
- The MemoryMan method names are descriptive and based on current helper pages. If a later MemoryMan pass standardizes array allocation as `new[]` / `delete[]`, convert the allocation/free pair then.
- `OnPrimaryButton` is recommended over `OnConfirm` for formal C++ because the current emitted base declaration uses `OnPrimaryButton`.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts this report, replace the existing target row with:

```text
    - [UID:0001KF][0x00599a40-0x00599cb3.UrlAlertPane](by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md) 0x00599a40-0x00599cb3 | class method/destructor cluster | UrlAlertPane : reconstructable : 88% : very strong : B011 2026-06-19 source-quality recheck raises the executable cluster from `84/90` to `88/91`, reroutes direct ownership/emission through [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md) while preserving generated output under [UID:0000HE][AlertPanes](by-file/AlertPanes.md), resolves formal source naming as constructor, ordinary destructor, and `UrlAlertPane::OnPrimaryButton` confirm handler, names `this+0x270` as `m_url` and `this+0x274` as `m_exitAfterOpen`, confirms direct constructor callers at `0x00503034`, `0x00513f7e`, and `0x0051402f`, confirms `ShellExecuteA` plus optional [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md), confirms singleton lifecycle through [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md), uses `GetMemoryMan`/`AllocateBufferMemory`/`FreeBufferMemory` for the owned ANSI URL buffer, and records target-specific no-code proof for constructor-unwind clear helper `0x00599bd0`, adjustor thunks `0x00599bdb/0x00599be6`, and scalar deleting destructor wrapper `0x00599c00-0x00599cb3`; first-draft C++ should include only source-authored methods and not hand-write vtable stores, base destructor calls, delete-wrapper flags, or thunk bodies.
```

If support coverage is being synchronized in the same supervisor pass, also replace stale support rows:

```text
        - [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) 0x0062e580-0x0062e624 | vtable-data | UrlAlertPaneVtableData : reconstructable : 85% : very strong : Exact three-view `UrlAlertPane` RTTI-adjacent vtable-data cluster attached to [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md); current page is `85/91` and records primary scalar deleting destructor slot `0x0062e584 -> 0x00599c00`, formal primary callback slot `0x0062e5e0 -> 0x00599ba0` / `UrlAlertPane::OnPrimaryButton`, secondary and tertiary adjustor thunk slots `0x0062e5ec -> 0x00599bdb` and `0x0062e61c -> 0x00599be6`, constructor/destructor/scalar-wrapper vtable store refs, boundary before `UserInfoDialogPane` RTTI at `0x0062e624`, and source-declared/generated-binary handling rather than hand-authored dword C++.
```

```text
        - [UID:0002WC][0x0069b4dc-0x0069b4e0.g_pUrlAlertPane](by-memory/0x0069b4dc-0x0069b4e0.g_pUrlAlertPane.md) 0x0069b4dc-0x0069b4e0 | global pointer | g_pUrlAlertPane : reconstructable : 88% : very strong : Exact zero-initialized one-dword `UrlAlertPane` singleton storage child attached to [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md); current page is `88/93` and records constructor publish/null refs `0x00599a94/0x00599a9b`, destructor/scalar/unwind clears `0x00599b73/0x00599c5a/0x00599bd0`, duplicate-open guard read at `0x00508fd6`, source declaration recommendation `UrlAlertPane *g_pUrlAlertPane = NULL;`, and source ownership under [UID:0000HE][AlertPanes](by-file/AlertPanes.md) while the surrounding singleton-slot aggregate remains non-emitting.
```

```text
    - [UID:00026S][0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData](by-memory/0x0062e57c-0x0062e624.UniApiUrlAlertReadOnlyData.md) 0x0062e57c-0x0062e624 | mixed vtable-data aggregate | UniApiUrlAlertReadOnlyData : ignored : 85% : very strong : Reviewed mixed-owner `.rdata` aggregate is `RECONSTRUCTABLE:FALSE` in current generated coverage because exact children carry source ownership: [UID:0003E5][0x0062e57c-0x0062e580.UniAPIInitVtableData](by-memory/0x0062e57c-0x0062e580.UniAPIInitVtableData.md) belongs to `UniAPIInit` / PlatformApi context and [UID:0002P0][0x0062e580-0x0062e624.UrlAlertPaneVtableData](by-memory/0x0062e580-0x0062e624.UrlAlertPaneVtableData.md) belongs to [UID:0000FF][UrlAlertPane](by-class/UrlAlertPane.md); do not emit or hand-port this aggregate as source code.
```

## Validator Needs After Implementation

Run from `source-3/project-documentation` after accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0001KF-UrlAlertPane-source-quality-removed.md](0001KF-UrlAlertPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the pending manual coverage rows:

> Executable block R002 was removed from this report and preserved verbatim in [0001KF-UrlAlertPane-source-quality-removed.md](0001KF-UrlAlertPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because the implementation changes emitter routing and C++ output:

> Executable block R003 was removed from this report and preserved verbatim in [0001KF-UrlAlertPane-source-quality-removed.md](0001KF-UrlAlertPane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validators run during this report phase: none. This was report-only.

## IDA Rename / Type / Comment Recommendations

No IDA database edits were made. Recommended names/comments if an IDA rename pass is later performed:

| Address / Item | Recommendation | Confidence |
| --- | --- | --- |
| `0x00599a40` | `UrlAlertPane::UrlAlertPane(bool, Pane *, wchar_t const *, char const *, unsigned int)` | very strong |
| `0x00599b20` | `UrlAlertPane::~UrlAlertPane()` ordinary non-deleting destructor | very strong |
| `0x00599ba0` | `UrlAlertPane::OnPrimaryButton()`; comment "confirm handler opens m_url and may request exit" | strong |
| `0x00599bd0` | `UrlAlertPaneConstructorClearSingletonOnUnwind` / compiler EH cleanup helper | strong |
| `0x00599bdb` | `UrlAlertPaneScalarDeletingDestructorThunk_a0` | very strong |
| `0x00599be6` | `UrlAlertPaneScalarDeletingDestructorThunk_a4` | very strong |
| `0x00599c00` | `UrlAlertPane::scalar deleting destructor` / compiler wrapper | very strong |
| `this+0x270` | `char *m_url` | very strong |
| `this+0x274` | `bool m_exitAfterOpen` | very strong |
| `0x0069b4dc` | `UrlAlertPane *g_pUrlAlertPane` | very strong |
| `0x0062e5e0` | `UrlAlertPane::OnPrimaryButton` vtable slot, semantic confirm | strong |

## Remaining Open Questions

- Exact original spelling of `m_url` and `m_exitAfterOpen`: not recoverable from binary evidence. The proposed names are source-quality descriptive names supported by use.
- Exact MemoryMan API spelling: current helper pages name `GetMemoryMan`, `AllocateBufferMemory`, and `FreeBufferMemory`; final project source may later wrap these as `new[]` / `delete[]` or shorter MemoryMan methods. This does not block first-draft C++ because the behavior and helper roles are known.
- Exact `static` versus external linkage for `g_pUrlAlertPane`: binary cannot prove original linkage. Cross-module guard reads and existing by-global documentation favor a non-static declaration in first draft.
- Fresh live IDA MCP decompilation was unavailable in this session. Existing IDA-backed docs plus raw PE/Capstone checks agree, so this limits only final-audit confidence, not the recommendation.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0001KF-UrlAlertPane-source-quality.md`
- Modified: none outside Agent-B011 research.
- Renamed: none.
- Moved to executed: none.
- Leases used: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0001KF-UrlAlertPane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0001KF"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KF-UrlAlertPane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0001KF-UrlAlertPane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
