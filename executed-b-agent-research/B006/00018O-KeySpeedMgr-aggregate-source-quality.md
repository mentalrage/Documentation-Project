** TARGET-REPORT-UID:00018O **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00018O KeySpeedMgr Aggregate Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:00018O] `0x004efea0-0x004f0008.KeySpeedMgr` from a reconstructable emitting aggregate into a reviewed non-emitting split/index page owned semantically by [UID:0000KJ] `KeySpeedMgr.cpp`; exact child pages should carry source C++.
- Final disposition: no range split is needed. The existing child inventory is exact, but the aggregate itself is not a source-authored function, class body, source file, table, or declaration. It is a physical contiguous executable island plus `0xcc` padding over multiple exact methods/helpers and one compiler scalar-deleting wrapper.
- Required action: update aggregate metadata to `88/91`, `CANONICAL_OWNER:0000KJ`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++; update child/source support pages so constructor, load, restore, raw setter, and fast-repeat emit first-draft C++ from exact child pages; leave scalar deleting destructor non-emitting/compiler-generated; update support docs with the class/member/global names and rejected alternatives below.
- Confidence: strong for boundaries, child inventory, `SystemParametersInfoW` behavior, `g_pKeySpeedMgr` lifecycle, `KeySpeedMgr.cpp` source route, and aggregate non-emitting policy; medium-high for the original spelling of `ApplyKeyboardRepeatSettings` because no symbol survives for the raw no-xref helper.

Recommended target metadata for [UID:00018O]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KJ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

## Target

- Target UID: [UID:00018O]
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004efea0-0x004f0008.KeySpeedMgr.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\00018O-KeySpeedMgr-aggregate-source-quality.md`
- Current target state: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Z`, blank C++.
- Current generated state: `auto-generated/NexusTK/input/KeySpeedMgr.cpp` contains only the accepted [UID:0002IQ] destructor body plus empty emitter markers for the aggregate, class, constructor, load, restore, scalar wrapper, layout/vtable/global pages, raw setter, and fast-repeat helper.
- Current manual coverage state: [UID:00018O] is listed as `reconstructable : 84% : strong` under the `0x004efea0-0x004f0008` class-method-cluster row and says blank final C++ is below the old source gate.

## Metadata / Score Rationale

| Field | Current | Recommended | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `84` | `88` | The aggregate now has revalidated direct PE bytes, exact child boundaries, padding, child owner/emitter policy, generated-output inspection, raw/fast helper correction, scalar-wrapper policy, and implementation instructions. It is still below final-audit completion because fresh IDA MCP was unavailable and several child pages still need implementation edits. |
| `CONFIDENCE` | `90` | `91` | Confidence improves modestly because direct PE/Capstone and manual xref scans independently confirm the current live-IDA documentation and reveal the fast-helper `ecx` ownership clue. It stays below `95` because original helper spellings, raw setter liveness, and final class/header integration remain inferred. |
| `CANONICAL_OWNER` | `00006Z` | `0000KJ` | The aggregate is a physical KeySpeedMgr.cpp executable-island index containing class methods, padding, and compiler wrapper evidence. Exact methods should use [UID:00006Z], but the non-emitting aggregate itself is best owned by the source file. |
| `RECONSTRUCTABLE` | `TRUE` | `FALSE` | The aggregate itself is not a source-level unit to emit. Exact children carry reconstructable source; scalar wrapper and padding carry non-source evidence. |
| `EMITTER_UIDS` | `00006Z` | blank | Emitting the aggregate currently produces only an empty marker and would either duplicate children or add no source. Child pages should emit through their own owners. |

## Supervisor Active Recheck

- User assignment: `B006-goal2-key-speed-mgr-aggregate-source-quality-00018O-20260619`.
- Report-only constraint observed: no target/support by-* docs, generated files, IDA DB, project-level files, or `by-memory/-coverage-report.md` were edited.
- Files edited: only this B006 research report.
- Split repair decision: do not split. The current child pages already cover every source-bearing and compiler-generated span inside the half-open aggregate range:
  - `0x004efea0-0x004efedd` constructor.
  - `0x004efedd-0x004efee0` `0xcc` padding.
  - `0x004efee0-0x004efef5` ordinary destructor.
  - `0x004efef5-0x004eff00` `0xcc` padding.
  - `0x004eff00-0x004eff25` load saved system keyboard settings.
  - `0x004eff25-0x004eff30` `0xcc` padding.
  - `0x004eff30-0x004eff5d` restore saved system keyboard settings.
  - `0x004eff5d-0x004eff60` `0xcc` padding.
  - `0x004eff60-0x004eff91` raw no-xref keyboard-repeat setter.
  - `0x004eff91-0x004effa0` `0xcc` padding.
  - `0x004effa0-0x004effbd` fast keyboard-repeat setter.
  - `0x004effbd-0x004effc0` `0xcc` padding.
  - `0x004effc0-0x004f0008` scalar deleting destructor wrapper.
  - `0x004f0008-0x004f0010` successor padding before `LanguageMan`.

## Evidence Standards Used

- Required guidance re-read: `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md` relevant `input/KeySpeedMgr.cpp` section.
- Documentation rechecked as leads, not proof: [UID:00018O] aggregate, [UID:0000KJ] file, [UID:00006Z] class, [UID:0001UV] layout, [UID:0001XX] vtable, [UID:0000RB] global, [UID:0001P7] singleton storage, all exact child pages, [UID:00032A] `DestroyKeySpeedMgr`, caller pages for Application/BaramApp/ExceptionHandler/WinMain, [UID:00031P] vtable data, [UID:0000K6] `InputMan`, [UID:0001QD] input meta, generated coverage, generated `KeySpeedMgr.cpp`, current manual coverage, and current unresolved/resolved reports.
- Prior B-agent reports rechecked as leads: B007 `00018P-KeySpeedMgrRestoreSystemKeyboardSettings-source-quality.md`, B001 executed `0000YU-ApplicationFunctionObject0Callbacks.md`, and B001 executed `00018T-LocalizationAdjacentZeroInitializer.md` for adjacent KeySpeedMgr/LanguageMan boundary reasoning.
- IDA MCP status: direct MCP request to `http://127.0.0.1:13337/mcp` failed with `Unable to connect to the remote server`. I therefore used direct PE byte inspection with Capstone against `E:\NTK\Resources\NexusTK\NexusTK.exe` plus existing live-IDA documentation. This limits fresh IDA-name confirmation but does not weaken the core byte/xref facts below.
- Direct binary inspected: `NexusTK.exe`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, image base `0x00400000`; sections include `.text` `0x00401000-0x0060c600`, `.rdata` `0x0060d000-0x0066c200`, `.data` `0x0066d000-0x0069ce24`.
- Number conversion support: `tools/int_convert.py` verified `0x1f` is decimal `31`, `0x0c` is decimal `12`, `0x17` is decimal `23`, `0x16` is decimal `22`, `0x0b` is decimal `11`, `0x0a` is decimal `10`, `0x04` is decimal `4`, and `0x08` is decimal `8`.

## Direct PE / Disassembly Facts

### Aggregate Bytes And Child Ranges

Direct PE/Capstone disassembly confirms the existing child boundaries:

| Range | Role | Direct byte/disassembly facts |
| --- | --- | --- |
| `0x004efea0-0x004efedd` | `KeySpeedMgr::KeySpeedMgr` | Calls `0x004f4a80`, stores `g_pKeySpeedMgr` through `0x0067ab48`, writes `0xffffffff` to `this+0x04` and `this+0x08`, writes vptr `0x0061c9c8`, returns `this`. |
| `0x004efedd-0x004efee0` | padding | Three `0xcc` bytes. |
| `0x004efee0-0x004efef5` | `KeySpeedMgr::~KeySpeedMgr` ordinary destructor | Writes vptr `0x0061c9c8`, clears `g_pKeySpeedMgr`, tail-jumps to `0x004f4a90`; no explicit return. |
| `0x004efef5-0x004eff00` | padding | Eleven `0xcc` bytes. |
| `0x004eff00-0x004eff25` | `KeySpeedMgr::LoadSystemKeyboardSettings` | Uses `ecx` as `this`, calls `SystemParametersInfoW(0x16, 0, &this[+0x04], 0)` and `SystemParametersInfoW(0x0a, 0, &this[+0x08], 0)`. |
| `0x004eff25-0x004eff30` | padding | Eleven `0xcc` bytes. |
| `0x004eff30-0x004eff5d` | `KeySpeedMgr::RestoreSystemKeyboardSettings` | Reads `this+0x04`/`this+0x08`, checks delay `<= 3`, checks speed `<= 0x1f` decimal `31` (Verified with int_convert.py), calls `SystemParametersInfoW(0x17, value, 0, 1)` and `SystemParametersInfoW(0x0b, value, 0, 1)`. |
| `0x004eff5d-0x004eff60` | padding | Three `0xcc` bytes. |
| `0x004eff60-0x004eff91` | `KeySpeedMgr::ApplyKeyboardRepeatSettings` candidate | Complete frame-based two-argument body, checks first stack argument `<= 3`, second stack argument `<= 0x1f`, calls the same setter APIs, and ends `ret 8`. No refs found to the start. |
| `0x004eff91-0x004effa0` | padding | Fifteen `0xcc` bytes. |
| `0x004effa0-0x004effbd` | `KeySpeedMgr::ApplyFastKeyboardRepeatSettings` | No frame, calls `SystemParametersInfoW(0x17, 0, 0, 1)` then `SystemParametersInfoW(0x0b, 0x1f, 0, 1)`, plain `ret`. |
| `0x004effbd-0x004effc0` | padding | Three `0xcc` bytes. |
| `0x004effc0-0x004f0008` | scalar deleting destructor wrapper | Writes vptr, clears `g_pKeySpeedMgr`, calls `0x004f4a90`, tests delete flag byte, conditionally calls `0x004f4ac0` or guard/delete support, returns with `ret 4`. |
| `0x004f0008-0x004f0010` | padding | Eight `0xcc` bytes before the `LanguageMan` island. |

### Direct Reference Scan

Manual rel32 and absolute pointer scans of the PE confirm:

| Target | Direct rel32 refs | Absolute pointer/immediate refs |
| --- | --- | --- |
| `0x004efea0` constructor | `0x00463a9a` | none |
| `0x004efee0` ordinary destructor | none | none |
| `0x004eff00` load | `0x00463aae` | none |
| `0x004eff30` restore | `0x00464aff`, `0x00466adb`, `0x004ab844`, `0x004f5ee6` | none |
| `0x004eff60` raw setter | none | none |
| `0x004eff91` raw-setter end/alignment | none | none |
| `0x004effa0` fast-repeat | `0x00463ab5`, `0x00466a24` | none |
| `0x004effc0` scalar deleting destructor | none | `0x0061c9c8` vtable slot |
| `0x0061c9c8` vtable | none | immediates at `0x004efecd`, `0x004efee2`, `0x004effc8` |
| `0x0067ab48` `g_pKeySpeedMgr` | none | references at `0x00464af8`, `0x00464b06`, `0x00466a1c`, `0x00466ad3`, `0x004673c2`, `0x004ab835`, `0x004efebf`, `0x004efee8`, `0x004effce`, `0x004f5ede` |

### Caller Windows

Direct disassembly from function starts confirms the current caller/reachability claims and adds the class-member evidence for the fast-repeat helper:

- `Application::Initialize` window:
  - `0x00463a7d`: pushes allocation size `0x0c` decimal `12` (Verified with int_convert.py).
  - `0x00463a9a`: calls constructor with `ecx = allocated object`.
  - `0x00463aae`: calls load with `ecx = esi` (`KeySpeedMgr *`).
  - `0x00463ab5`: calls fast-repeat immediately after `mov ecx, esi`.
- `BaramAppOnActivate` window:
  - `0x00466a1a`: loads `ecx = [0x0067ab48]`.
  - `0x00466a20`: tests singleton for null.
  - `0x00466a24`: calls `0x004effa0` with `ecx` still carrying `g_pKeySpeedMgr`.
- `BaramAppOnDeactivate` window:
  - `0x00466ad1`: loads `ecx = [0x0067ab48]`.
  - `0x00466ad7`: tests singleton for null.
  - `0x00466adb`: calls restore.
- `TopLevelExceptionFilter` window:
  - `0x004ab833`: loads `ecx = [0x0067ab48]`.
  - `0x004ab840`: tests singleton for null.
  - `0x004ab844`: calls restore.
- `_WinMain@16` window:
  - `0x004f5edc`: loads `ecx = [0x0067ab48]`.
  - `0x004f5ee2`: tests singleton for null.
  - `0x004f5ee6`: calls restore.
  - `0x004f5eeb`: immediately calls [UID:00032A] `DestroyKeySpeedMgr`.
- `DestroyKeySpeedMgr` window:
  - `0x004673c0`: loads `ecx = [0x0067ab48]`.
  - `0x004673c8`: skips on null.
  - `0x004673cc`: pushes delete flag `1`.
  - `0x004673ce`: calls vtable slot zero, which [UID:0001XX]/[UID:00031P] tie to scalar deleting destructor `0x004effc0`.

### Import Evidence

Direct PE import-table parsing confirms `SystemParametersInfoW` is imported from `USER32.dll` at IAT address `0x0060d3f8`. Every KeySpeedMgr load/restore/raw/fast helper call in this cluster uses that same import pointer. No project-local wrapper is visible inside these ranges.

## Heuristic / Inference Reanalysis And Validation

### Aggregate Emission Policy

- Current docs say the aggregate is reconstructable and emitted through [UID:00006Z]. Current generated output proves the result is an empty emitter marker for [UID:00018O], not useful source.
- Best inference: [UID:00018O] is a non-emitting split/index page. It is useful as a physical code-island inventory and boundary proof, but exact child pages are the source units.
- Evidence: the range contains multiple independent exact functions, multiple padding spans, class methods, class lifecycle methods, file/source helper candidates now better modeled as class methods, and a compiler scalar-deleting wrapper. No source-level C++ construct should be emitted for the whole half-open range.
- Rejected: keep aggregate as an emitting class method cluster. It would either emit no code or duplicate child method bodies, both of which violate the by-memory C++ rule that C++ must be limited to the page's own source unit.
- Rejected: aggregate should receive a `[[CHILDREN]]` parent shell. The class page [UID:00006Z] is the correct shell for class declarations and method insertion; [UID:0000KJ] is the source file root. A by-memory executable island should not become another generated C++ nesting layer between class/file and exact child methods.
- Rejected: aggregate should be class-owned by [UID:00006Z]. The island contains the raw/fast setter family and the overall file-level module boundary; the class owns the member methods, but the by-file [UID:0000KJ] is the better owner for the physical index if an owner is kept.
- Decision: change [UID:00018O] to `RECONSTRUCTABLE:FALSE`, blank emitter, semantic owner [UID:0000KJ], and keep all child rows as reconstructable or ignored according to their own source shape.

### Source File Placement

- Accepted route: `NexusTK/input/KeySpeedMgr.cpp` under [UID:0000KJ].
- Evidence for `input/`: `proposed-source-tree.md` lists `input/KeySpeedMgr.cpp`; [UID:0001QD] treats KeySpeedMgr as input-adjacent keyboard repeat state; [UID:0000K6] explicitly keeps KeySpeedMgr separate from InputMan but in the same top-level input/platform area; Application startup constructs the singleton and then the keyboard-repeat setup is used by activation/deactivation paths.
- Rejected `platform/KeySpeedMgr.cpp` for this pass: the implementation uses Win32 `SystemParametersInfoW`, but the documented project tree and current source-root page already use `NexusTK/input/`; no broader PlatformApi owner or shared platform keyboard-settings module is evidenced.
- Rejected `InputMan.cpp`: [UID:0000K6] owns Win32/IMM message routing, IME context, input target tracking, and message/event production. KeySpeedMgr only saves/restores system keyboard repeat settings and has a separate singleton, vtable, class layout, and source root.
- Rejected `Application.cpp` and `WinMain.cpp` for the KeySpeedMgr methods: Application/WinMain are callers/cleanup consumers, not owners of the `KeySpeedMgr` object fields or vtable. [UID:00032A] remains WinMain-owned cleanup glue, not KeySpeedMgr method source.
- Rejected `ExceptionHandler.cpp`: the top-level filter calls restore during crash handling, but that is a crash-path consumer of `KeySpeedMgr`, not source ownership.

### KeySpeedMgr Field Names And Types

- Recommended class fields:
  - `m_savedKeyboardDelay` at `+0x04`.
  - `m_savedKeyboardSpeed` at `+0x08`.
- Recommended field type: `UINT` or project-equivalent unsigned 32-bit integer. If the implementation avoids requiring `<windows.h>` in the class shell, `unsigned int` is acceptable, but the docs should preserve the Win32 `UINT` role.
- Evidence:
  - Constructor writes `0xffffffff` to both fields.
  - Load uses `SPI_GETKEYBOARDDELAY` (`0x16`, decimal `22`, Verified with int_convert.py) into `+0x04` and `SPI_GETKEYBOARDSPEED` (`0x0a`, decimal `10`, Verified with int_convert.py) into `+0x08`.
  - Restore accepts delay only through `<= 3` and speed only through `<= 0x1f` decimal `31` (Verified with int_convert.py), then calls the corresponding set actions.
  - Layout page [UID:0001UV] already records the same offsets and semantics.
- Rejected names: `mbr_0x4`, `mbr_0x8`, `field_4`, `field_8`, `delay`/`speed` without "saved" in documentation. Shorter source spellings such as `m_keyboardDelay`/`m_keyboardSpeed` remain possible if the class declaration already standardized them, but "saved" is higher quality because the values are the user's original system settings to restore.

### Constructor [UID:0002IP]

- Best source-facing name/signature: `KeySpeedMgr::KeySpeedMgr()`.
- Owner/emitter: keep [UID:00006Z].
- Recommended score: `87/91`.
- First-draft C++ should be entered on the exact constructor page, not on the aggregate.
- Best draft:

```cpp
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}
```

- Reasoning: base `LObject` constructor and vptr installation are compiler C++ construction mechanics; the handwritten source body is singleton publication plus saved-field initialization. A member-initializer list is plausible, but the observed body order is closer to body assignments after base construction, so body assignments are the better first draft.
- Rejected stale no-code wording: current "below 95/95 source gate" text is obsolete. This page has `RECONSTRUCTABLE:TRUE`, valid emitter route, and current average score `87`; after source-quality cleanup it should carry C++.

### Ordinary Destructor [UID:0002IQ]

- Best source-facing name/signature: `KeySpeedMgr::~KeySpeedMgr()`.
- Owner/emitter: keep [UID:00006Z].
- Current formal C++ is already correct as first draft:

```cpp
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}
```

- Evidence: direct bytes write vptr, clear `g_pKeySpeedMgr`, then tail-jump to `LObject` cleanup; B003 raw PE/Capstone recheck and this PE pass agree.
- Source treatment: keep the vptr store and base cleanup out of explicit source. The destructor child carries source C++; scalar deleting wrapper remains non-emitting compiler output.
- Score can stay `87/92` unless the implementation callback updates surrounding class-shell consistency, in which case `88/92` is also defensible.

### Load Saved Settings [UID:0002IR]

- Best source-facing name/signature: `void KeySpeedMgr::LoadSystemKeyboardSettings()`.
- Owner/emitter: keep [UID:00006Z].
- Recommended score: `87/91`.
- First-draft C++:

```cpp
void KeySpeedMgr::LoadSystemKeyboardSettings()
{
    ::SystemParametersInfoW(SPI_GETKEYBOARDDELAY, 0, &m_savedKeyboardDelay, 0);
    ::SystemParametersInfoW(SPI_GETKEYBOARDSPEED, 0, &m_savedKeyboardSpeed, 0);
}
```

- Evidence: direct PE bytes and existing docs agree on the two getter API calls through import `0x0060d3f8`.
- Rejected stale no-code wording: this is source-authored, live, exact, and code-gate eligible. It should not remain an empty marker.

### Restore Saved Settings [UID:00018P]

- Best source-facing name/signature: `void KeySpeedMgr::RestoreSystemKeyboardSettings()`.
- Owner/emitter: keep [UID:00006Z].
- Recommended score: `88/92`, matching B007's report after B006 direct PE revalidation.
- First-draft C++:

```cpp
void KeySpeedMgr::RestoreSystemKeyboardSettings()
{
    if (m_savedKeyboardDelay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, m_savedKeyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (m_savedKeyboardSpeed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, m_savedKeyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}
```

- Evidence: direct PE bytes agree with B007 and current docs: four callers, saved-field reads, direct `SystemParametersInfoW`, and side-effect-only call sites.
- Rejected return type: any decompiler `UINT` return is an ignored-register artifact. Callers treat the method as void.
- Rejected ownership alternatives: WinMain/Application/ExceptionHandler are callers; scalar deleting destructor/delete-wrapper behavior is separate.

### Raw No-Xref Setter [UID:0002IS]

- Current docs treat this as a file-local raw helper because no `this` access is visible and no xrefs exist. That is no longer the best inference.
- Best source-facing name/signature: `void KeySpeedMgr::ApplyKeyboardRepeatSettings(UINT keyboardDelay, UINT keyboardSpeed)` or `void KeySpeedMgr::SetKeyboardRepeatSettings(UINT keyboardDelay, UINT keyboardSpeed)`. Recommendation: use `ApplyKeyboardRepeatSettings` because it pairs directly with the saved `ApplyFastKeyboardRepeatSettings` label/name family and describes both delay and speed side effects.
- Recommended metadata: `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Z`.
- First-draft C++:

```cpp
void KeySpeedMgr::ApplyKeyboardRepeatSettings(UINT keyboardDelay, UINT keyboardSpeed)
{
    if (keyboardDelay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, keyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (keyboardSpeed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, keyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}
```

- Evidence for class ownership:
  - The body ends in `ret 8`, matching MSVC thiscall cleanup for a member method with two explicit stack arguments when `this` in `ecx` is not used.
  - It is address-adjacent to other `KeySpeedMgr` class methods and implements the same setter semantics as restore/fast-repeat.
  - The following fast-repeat helper has callers that load `ecx = g_pKeySpeedMgr` before calling even though the body itself does not use `ecx`; that proves "no field access" is not enough to classify the setter family as file-local.
- Remaining caveat: no direct rel32 refs, no absolute pointer refs, no IDA function object, and no original symbol are known for `0x004eff60`. That caps confidence and should remain documented, but it does not make the helper compiler-generated or non-source. It is a complete source-shaped method body retained in the linked object.
- Rejected file-local ownership: a file helper would not explain the `ret 8` thiscall-compatible epilogue as cleanly, and the fast helper's `ecx` call sites contradict the current no-this heuristic.
- Rejected compiler/runtime artifact: direct calls to `SystemParametersInfoW`, clean frame, ordinary range checks, and source-neighborhood placement are project source, not CRT/compiler support.
- Rename policy: a later implementation may keep the filename suffix `Raw` to preserve the no-IDA-function caveat, but prose and C++ should use the source-facing method name without "Raw".

### Fast Repeat Setter [UID:00018Q]

- Current docs treat this as file-local/global helper because no `this` access is visible. Direct call-site inspection changes the best inference.
- Best source-facing name/signature: `void KeySpeedMgr::ApplyFastKeyboardRepeatSettings()`.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006Z`.
- First-draft C++:

```cpp
void KeySpeedMgr::ApplyFastKeyboardRepeatSettings()
{
    ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, 0, 0, SPIF_UPDATEINIFILE);
    ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, 31, 0, SPIF_UPDATEINIFILE);
}
```

- Evidence for class method ownership:
  - `Application::Initialize` executes `mov ecx, esi` then calls `0x004effa0`.
  - `BaramAppOnActivate` loads `ecx = g_pKeySpeedMgr`, null-checks it, then calls `0x004effa0`.
  - The body does not read fields, but the callers still pass `this`; this is a member method whose current body happens to use only global system APIs.
- Rejected file-local/free helper: the two live call sites would not need to preserve/load `ecx` for a free helper. The existing "no this access means file-local" note is a stale heuristic.
- Rejected source names: `SetFastKeyboardRepeat` is plausible, but `ApplyFastKeyboardRepeatSettings` is already the saved/current label family and matches the raw helper recommendation.

### Scalar Deleting Destructor [UID:0002IT]

- Best source-facing treatment: compiler-generated scalar deleting destructor wrapper, not handwritten C++.
- Recommended metadata: `COMPLETION:86`, `CONFIDENCE:92`, `CANONICAL_OWNER:00006Z`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Evidence: vtable slot `0x0061c9c8` points to `0x004effc0`; body duplicates vptr/global/base cleanup and adds delete-flag/free/guard behavior; no direct code callers; runtime deletion dispatches through the vtable from [UID:00032A].
- Source consequence: a virtual destructor declaration plus [UID:0002IQ] ordinary destructor source is the source-level input that produces this wrapper. Hand-emitting the wrapper as C++ would be decompiler/compiler artifact pollution.
- Rejected current "reconstructable source-declared/generated-binary method" metadata: the class declaration is reconstructable, but this exact by-memory function is compiler-generated destructor support and should be non-emitting after review.

### `g_pKeySpeedMgr`

- Best global name: `g_pKeySpeedMgr`; [UID:0000RB] and [UID:0001P7] are consistent and direct PE absolute refs confirm ten uses.
- Direct owner: [UID:0000RB] global page with source root [UID:0000KJ].
- Recommended support C++ on [UID:0000RB] when implementing the source family:

```cpp
KeySpeedMgr *g_pKeySpeedMgr = 0;
```

- Recommended class/file shell should include an `extern KeySpeedMgr *g_pKeySpeedMgr;` declaration before method bodies if the global definition is emitted later in file order.
- Rejected owner: [UID:0000PA] WinMain. WinMain owns [UID:00032A] cleanup wrapper only; the storage is KeySpeedMgr-owned and shared by Application/BaramApp/ExceptionHandler/WinMain consumers.
- Rejected stale initial-value conflict as blocker: existing docs record older `0xffffffff` and current zero-filled IDB observations. Source-level singleton pointer should initialize to null/zero; constructor/destructor code supplies runtime values.

### `SystemParametersInfoW` Constants And Calls

- Use `SystemParametersInfoW`, not `SystemParametersInfoA`.
- Use constants rather than raw action numbers:
  - `SPI_GETKEYBOARDDELAY` for `0x16` decimal `22` (Verified with int_convert.py).
  - `SPI_GETKEYBOARDSPEED` for `0x0a` decimal `10` (Verified with int_convert.py).
  - `SPI_SETKEYBOARDDELAY` for `0x17` decimal `23` (Verified with int_convert.py).
  - `SPI_SETKEYBOARDSPEED` for `0x0b` decimal `11` (Verified with int_convert.py).
  - `SPIF_UPDATEINIFILE` for `fWinIni == 1`.
- No code in the KeySpeedMgr children passes `SPIF_SENDCHANGE`.
- No project-local wrapper is visible; all calls go through USER32 import pointer `0x0060d3f8`.

### Compiler / Generated Name Cleanup

- Replace source-facing `sub_4EFEA0` with `KeySpeedMgr::KeySpeedMgr`.
- Replace `sub_4EFEE0` with `KeySpeedMgr::~KeySpeedMgr`.
- Replace `sub_4EFF00` with `KeySpeedMgr::LoadSystemKeyboardSettings`.
- Replace `sub_4EFF30` with `KeySpeedMgr::RestoreSystemKeyboardSettings`.
- Replace source-facing `sub_4EFF60` / `KeySpeedMgrApplyKeyboardRepeatSettingsRaw` with `KeySpeedMgr::ApplyKeyboardRepeatSettings`, keeping "raw/no-xref" only as an evidence caveat.
- Replace `sub_4EFFA0` / free-helper treatment with `KeySpeedMgr::ApplyFastKeyboardRepeatSettings`.
- Replace `sub_4EFFC0` with "KeySpeedMgr scalar deleting destructor wrapper" and mark non-emitting/compiler-generated.
- Replace `dword_67AB48` with `g_pKeySpeedMgr` when the prose is source-facing.
- Leave `nullsub_18`, `off_61CF44`, `sub_4F4A80`, `sub_4F4A90`, `sub_4F4AC0`, and guard/delete helper names unresolved on their own owner pages. For this report, they are inherited/base/runtime support evidence, not KeySpeedMgr source statements.

### Stale 95/95 No-Code Wording

- Current target and several children still use old "below 95/95 source gate" wording. Active `by-structure.md` policy says C++ may be entered when `RECONSTRUCTABLE:TRUE`, emitter route is valid, and `(COMPLETION + CONFIDENCE) / 2 > 85`, subject to source-quality readiness.
- Constructor, load, restore, raw setter, and fast-repeat satisfy the active gate after this source-quality pass.
- Aggregate [UID:00018O] should not use either old-gate wording or first-draft C++; it should explicitly say it is non-emitting because exact child pages own code.
- Scalar deleting destructor [UID:0002IT] should not use old-gate wording; it should explicitly say no C++ because the exact page is compiler-generated wrapper output.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Recommended owner/emitter | Recommended score | Recommended source/C++ policy |
| --- | --- | --- | --- | --- | --- |
| `0x004efea0-0x004f0008` | [UID:00018O] aggregate | physical split/index | owner [UID:0000KJ], no emitter | `88/91` | Non-emitting index; blank C++. |
| `0x004efea0-0x004efedd` | [UID:0002IP] constructor | class constructor | [UID:00006Z] / [UID:00006Z] | `87/91` | Emit constructor body. |
| `0x004efee0-0x004efef5` | [UID:0002IQ] ordinary destructor | class destructor | [UID:00006Z] / [UID:00006Z] | keep `87/92` or raise `88/92` | Existing C++ correct. |
| `0x004eff00-0x004eff25` | [UID:0002IR] load | class method | [UID:00006Z] / [UID:00006Z] | `87/91` | Emit getter calls. |
| `0x004eff30-0x004eff5d` | [UID:00018P] restore | class method | [UID:00006Z] / [UID:00006Z] | `88/92` | Emit restore body; B007 report validated. |
| `0x004eff60-0x004eff91` | [UID:0002IS] raw setter | inferred class method, no xrefs | [UID:00006Z] / [UID:00006Z] | `87/90` | Emit method body; document no-xref/original-name caveat. |
| `0x004effa0-0x004effbd` | [UID:00018Q] fast setter | class method | [UID:00006Z] / [UID:00006Z] | `88/92` | Emit method body; call sites pass `this`. |
| `0x004effc0-0x004f0008` | [UID:0002IT] scalar deleting destructor | compiler wrapper | owner [UID:00006Z], no emitter | `86/92` | Non-emitting wrapper evidence; blank C++. |

## Ranked Ownership Analysis

### 1. [UID:0000KJ] KeySpeedMgr File For The Aggregate - Accepted

- Evidence for:
  - The aggregate is the compact executable island for the KeySpeedMgr source module.
  - All exact children either belong directly to [UID:00006Z] `KeySpeedMgr` or are compiler output generated from that class.
  - The by-file page has the active source root `NexusTK/input/` and the proposed source tree lists `input/KeySpeedMgr.cpp`.
  - The aggregate contains both class methods and index/padding/compiler-wrapper evidence, so by-file ownership is a better semantic umbrella than by-class ownership for the aggregate page itself.
- Evidence against:
  - Exact class methods should still attach to [UID:00006Z], not bypass the class.
- Decision: use [UID:0000KJ] as aggregate owner, but keep aggregate non-emitting and route exact child source through the class/source root.

### 2. [UID:00006Z] KeySpeedMgr Class For Exact Methods - Accepted

- Evidence for:
  - Constructor/load/restore/destructor use `this`, object layout, vptr, and saved fields.
  - Fast-repeat call sites pass `ecx = g_pKeySpeedMgr`.
  - Raw setter has thiscall-compatible `ret 8` and belongs to the same member family despite no xrefs.
  - Class/layout/vtable pages clear the source route to [UID:0000KJ].
- Evidence against:
  - The aggregate includes padding and compiler wrapper, so class should not own/emits the aggregate as if it were one source method.
- Decision: class owns exact methods and declaration shell; aggregate demotes to source-file index.

### 3. [UID:0000K6] InputMan - Rejected

- Evidence for:
  - Same top-level `input/` area and keyboard-related behavior.
- Evidence against:
  - InputMan owns Win32/IMM input message routing and IME state, not system keyboard repeat delay/speed persistence.
  - KeySpeedMgr has its own class, vtable, singleton, and source module.
- Decision: keep as neighboring input subsystem only.

### 4. [UID:0000HG] Application / [UID:0000PA] WinMain / [UID:00014D] ExceptionHandler - Rejected As KeySpeedMgr Owners

- Evidence for:
  - Application constructs/loads/restores; WinMain restores then destroys; ExceptionHandler restores in crash callback.
- Evidence against:
  - These are call/cleanup contexts. They do not own the object fields or keyboard-repeat method bodies.
  - [UID:00032A] `DestroyKeySpeedMgr` is separately WinMain-owned cleanup glue and should remain outside the KeySpeedMgr method family.
- Decision: cite as caller evidence only.

### 5. Non-Emitting Aggregate With Child-Only Code - Accepted

- Evidence for:
  - Mirrors B001's [UID:0000YU] mixed-container policy: parent page documents a physical interval; exact children carry source ownership.
  - Current generated output proves aggregate emission adds only an empty marker.
  - Exact children now have enough source-quality evidence for first-draft C++ or wrapper exclusion.
- Evidence against:
  - Aggregate is compact and all children belong to one source module, so a non-emitting index should keep a semantic owner rather than become ownerless.
- Decision: [UID:00018O] should be non-emitting `RECONSTRUCTABLE:FALSE`, owner [UID:0000KJ], child-only source code.

## Negative Evidence Summary

- IDA MCP was unavailable, so no fresh IDA `lookup_funcs`/`xrefs_to` could be collected; direct PE bytes, Capstone disassembly, import parsing, manual rel32 scans, and existing live-IDA docs agree on the relevant facts.
- No rel32 or pointer refs to `0x004eff60` were found. This prevents proving a live caller or original source name for `ApplyKeyboardRepeatSettings`, but it does not prove compiler/runtime output.
- No source/debug breadcrumb or original symbol was used as proof. Source names are descriptive/inferred except saved current labels such as `g_pKeySpeedMgr` and the documented `ApplyFastKeyboardRepeatSettings` family.
- No evidence supports treating fast-repeat as file-local after call-site inspection; callers pass `this`.
- No evidence supports putting delete/free logic into ordinary source. Delete flag handling belongs to compiler scalar deleting destructor output and WinMain cleanup glue.
- No evidence supports putting all child bodies into [UID:00018O]. The aggregate is a documentation index, not a source function.

## First-Draft C++ Policy

### Aggregate [UID:00018O]

Do not populate aggregate formal C++. Set `RECONSTRUCTABLE:FALSE` and blank emitter. The target should document:

- exact children;
- exact padding;
- child ownership/emission policy;
- raw setter no-xref caveat;
- scalar deleting destructor compiler-wrapper caveat;
- generated-output reason for demotion.

### Class Shell [UID:00006Z]

The class page should carry a declaration shell and `[[CHILDREN]]` insertion point so exact method children emit after the declaration. Recommended first-draft class C++:

```cpp
#include <windows.h>

class KeySpeedMgr : public LObject {
public:
    KeySpeedMgr();
    virtual ~KeySpeedMgr();

    void LoadSystemKeyboardSettings();
    void RestoreSystemKeyboardSettings();
    void ApplyKeyboardRepeatSettings(UINT keyboardDelay, UINT keyboardSpeed);
    void ApplyFastKeyboardRepeatSettings();

private:
    UINT m_savedKeyboardDelay;
    UINT m_savedKeyboardSpeed;
};

extern KeySpeedMgr *g_pKeySpeedMgr;

[[CHILDREN]]
```

Implementation note: if the project later centralizes declarations in headers, this shell can migrate to the proper header/class declaration owner. For this pass, it is the minimum source-facing declaration needed to make child method C++ coherent.

### Global [UID:0000RB]

Recommended global C++:

```cpp
KeySpeedMgr *g_pKeySpeedMgr = 0;
```

This should be emitted by the global page or a later accepted global implementation pass. The exact storage [UID:0001P7] should avoid duplicating the declaration if [UID:0000RB] emits it.

### Exact Child Methods

Populate first-draft C++ on:

- [UID:0002IP] constructor.
- [UID:0002IQ] ordinary destructor already populated.
- [UID:0002IR] load.
- [UID:00018P] restore.
- [UID:0002IS] apply keyboard repeat settings.
- [UID:00018Q] apply fast keyboard repeat settings.

Do not populate first-draft C++ on:

- [UID:00018O] aggregate.
- [UID:0002IT] scalar deleting destructor wrapper.

## Exact Implementation Checklist For Supervisor Callback

1. Lease/edit [UID:00006Z] `by-class/KeySpeedMgr.md`.
   - Change metadata to `COMPLETION:89`, `CONFIDENCE:91` if the class shell and method ownership corrections are accepted.
   - Add the class declaration shell above with `[[CHILDREN]]`.
   - Update method inventory: raw setter and fast-repeat are `KeySpeedMgr` methods, not file-local helpers.
   - Add call-site evidence: `0x00463ab3/0x00463ab5` and `0x00466a1a/0x00466a24` pass `g_pKeySpeedMgr` in `ecx` to fast-repeat.
   - Add rejected alternatives: InputMan, Application, WinMain, ExceptionHandler, file-local fast helper, scalar wrapper as source.

2. Lease/edit [UID:0000KJ] `by-file/KeySpeedMgr.md`.
   - Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/"`.
   - Change score to `91/90` if accepted.
   - Replace file-local raw/fast helper language with class-method language.
   - Keep `NexusTK/input/KeySpeedMgr.cpp` over `platform/KeySpeedMgr.cpp`; document platform as rejected/weaker.
   - Record that [UID:00018O] is a non-emitting executable-island index, while exact children emit.
   - Note [UID:00032A] remains WinMain-owned cleanup glue.

3. Lease/edit [UID:0001UV] `by-type/by-struct/KeySpeedMgrLayout.md`.
   - Change score to `88/91` if accepted.
   - Standardize fields to `m_savedKeyboardDelay` at `+0x04` and `m_savedKeyboardSpeed` at `+0x08`.
   - Preserve evidence from constructor/load/restore and the `0x0c` decimal `12` allocation (Verified with int_convert.py).
   - Update fast/raw setter notes to class-method status based on `ecx` and `ret 8` evidence.

4. Lease/edit [UID:0000RB] `by-global/g_pKeySpeedMgr.md` if implementation includes global support.
   - Recommended score `89/91`.
   - Add formal C++ `KeySpeedMgr *g_pKeySpeedMgr = 0;`.
   - Preserve object/global owner split: WinMain owns [UID:00032A] cleanup wrapper; KeySpeedMgr owns the singleton storage.
   - Do not duplicate this definition in [UID:0001P7] if the global page emits it.

5. Lease/edit [UID:00018O] target aggregate.
   - Apply target metadata `88/91`, owner [UID:0000KJ], `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
   - Replace "reconstructable class-method-cluster" wording with "reviewed non-emitting KeySpeedMgr executable-island split/index".
   - Add child-only C++ policy and generated-output inspection note.
   - Add raw/fast ownership correction and scalar wrapper non-emitting decision.
   - Keep exact child table and padding, updating child names/owners/scores as below.

6. Lease/edit [UID:0002IP] constructor.
   - Metadata `87/91`, owner/emitter [UID:00006Z].
   - Add constructor C++ from this report.
   - Replace stale 95/95 no-code wording with active gate/source-ready explanation.
   - Use `m_savedKeyboardDelay` and `m_savedKeyboardSpeed`.

7. Lease/edit [UID:0002IR] load.
   - Metadata `87/91`, owner/emitter [UID:00006Z].
   - Add load C++ from this report.
   - Replace stale 95/95 no-code wording.
   - Use Win32 constants and field names.

8. Lease/edit [UID:00018P] restore.
   - Metadata `88/92`, owner/emitter [UID:00006Z].
   - Add B007/B006-confirmed restore C++ from this report.
   - Preserve B007 rejected alternatives and void-return rationale.
   - Update coverage row text using the B006 aggregate row set below, or B007's row if supervisor has already accepted it separately.

9. Lease/edit [UID:0002IS] raw setter.
   - Metadata `87/90`, owner/emitter changed from [UID:0000KJ] to [UID:00006Z].
   - Add C++ for `KeySpeedMgr::ApplyKeyboardRepeatSettings`.
   - Preserve no-IDA-function/no-xref/no-original-name caveat.
   - Reject file-local ownership using `ret 8` and fast-helper `ecx` evidence.
   - Do not rename the file unless supervisor explicitly wants filename cleanup; if renamed, use `0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettings.md`.

10. Lease/edit [UID:00018Q] fast-repeat.
   - Metadata `88/92`, owner/emitter changed from [UID:0000KJ] to [UID:00006Z].
   - Add C++ for `KeySpeedMgr::ApplyFastKeyboardRepeatSettings`.
   - Replace file-local/no-this rationale with class-method rationale from call-site evidence.

11. Lease/edit [UID:0002IT] scalar deleting destructor.
   - Metadata `86/92`, owner [UID:00006Z], `RECONSTRUCTABLE:FALSE`, blank emitter, blank C++.
   - Preserve exact wrapper behavior as evidence.
   - State source is generated from virtual destructor declaration and ordinary destructor body; do not hand-author delete/free/guard logic.

12. Optional small cleanup on [UID:0002IQ] ordinary destructor.
   - Keep existing C++.
   - If touched, update stale wording to active gate and link scalar wrapper as non-emitting compiler output.

13. Validation commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00018O-KeySpeedMgr-aggregate-source-quality-removed.md](00018O-KeySpeedMgr-aggregate-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

14. Generated-output inspection after implementation:
   - Inspect `auto-generated/NexusTK/input/KeySpeedMgr.cpp`.
   - Confirm the class shell appears before child method bodies or at least that child method bodies have declarations available.
   - Confirm constructor/load/restore/raw setter/fast-repeat method bodies appear.
   - Confirm ordinary destructor still appears exactly once.
   - Confirm [UID:00018O] aggregate no longer appears as an empty emitter marker.
   - Confirm [UID:0002IT] scalar deleting destructor no longer appears as an emitted marker/body.
   - Confirm raw/fast helpers are no longer file-local markers; they should be class methods under [UID:00006Z].
   - Confirm no source manually emits vptr writes, `LObject` cleanup calls, `operator delete`, or guard-check wrapper logic for [UID:0002IT].

## Validator Baseline

Command run during this report-only pass:

> Executable block R002 was removed from this report and preserved verbatim in [00018O-KeySpeedMgr-aggregate-source-quality-removed.md](00018O-KeySpeedMgr-aggregate-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- `apply: False`.
- `scanned markdown files: 1`.
- `ok: 1`.
- Target line: `ok 00018O by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md UID header exists`.
- Dry-run side observations: `stats_incremental_skip` for target stats because no `--apply`; autogen reported many existing empty emitters, including the current KeySpeedMgr family state; generated reports were `autogen_report_noop`.
- No by-* docs or generated files were edited by this validator dry run.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from B006. If supervisor accepts the full B006 aggregate recommendation, replace the current [UID:00018O] row and the affected child rows with the following text while preserving the existing padding rows and nesting.

Replace [UID:00018O] row with:

```text
    - [UID:00018O][0x004efea0-0x004f0008.KeySpeedMgr](by-memory/0x004efea0-0x004f0008.KeySpeedMgr.md) 0x004efea0-0x004f0008 | executable-island split index | KeySpeedMgr method/helper island : ignored : 88% : strong : B006 aggregate source-quality pass converts this from an emitting class-method-cluster into a reviewed non-emitting KeySpeedMgr.cpp split/index owned semantically by [UID:0000KJ]; direct PE/Capstone recheck confirms every exact child boundary, internal 0xcc padding, SystemParametersInfoW import 0x0060d3f8, constructor/load/restore/raw/fast/scalar bytes, g_pKeySpeedMgr refs, vtable refs, and restore/fast caller sites. Exact children carry source C++: constructor/load/restore/raw setter/fast-repeat should emit through [UID:00006Z], ordinary destructor already emits, and the scalar deleting destructor becomes non-emitting compiler wrapper evidence. Aggregate formal C++ stays blank; no split is needed.
```

Replace [UID:0002IP] row with:

```text
        - [UID:0002IP][0x004efea0-0x004efedd.KeySpeedMgrConstructor](by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md) 0x004efea0-0x004efedd | constructor | KeySpeedMgr::KeySpeedMgr : reconstructable : 87% : strong : B006 source-quality pass confirms exact constructor bytes, Application::Initialize caller 0x00463a9a after 0x0c allocation, LObject base-constructor call, g_pKeySpeedMgr publication, saved keyboard delay/speed initialization to UINT(-1), vptr compiler emission, and source-ready first-draft C++ on the exact child page; stale 95/95 blank-C++ wording should be removed.
```

Replace [UID:0002IR] row with:

```text
        - [UID:0002IR][0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings](by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md) 0x004eff00-0x004eff25 | method | KeySpeedMgr::LoadSystemKeyboardSettings : reconstructable : 87% : strong : B006 source-quality pass confirms exact load-method bytes, startup caller 0x00463aae, saved fields m_savedKeyboardDelay at +0x04 and m_savedKeyboardSpeed at +0x08, direct SystemParametersInfoW getter calls using SPI_GETKEYBOARDDELAY and SPI_GETKEYBOARDSPEED, owner/emitter [UID:00006Z], and first-draft void method C++ readiness.
```

Replace [UID:00018P] row with:

```text
        - [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md) 0x004eff30-0x004eff5d | method | KeySpeedMgr::RestoreSystemKeyboardSettings : reconstructable : 88% : strong : B006 revalidates B007 source-quality direction: exact 0x2d body, callers 0x00464aff/0x00466adb/0x004ab844/0x004f5ee6, saved keyboard delay/speed reads, delay <= 3 and speed <= 31 range checks, direct SystemParametersInfoW calls with SPI_SETKEYBOARDDELAY/SPI_SETKEYBOARDSPEED and SPIF_UPDATEINIFILE, ignored return-register artifact supporting void source signature, destructor/delete wrappers kept separate, stale 95/95 blank-C++ wording removed, and first-draft C++ ready on the exact child page.
```

Replace [UID:0002IS] row with:

```text
        - [UID:0002IS][0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw](by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md) 0x004eff60-0x004eff91 | method/raw no-xref | KeySpeedMgr::ApplyKeyboardRepeatSettings : reconstructable : 87% : strong : B006 source-quality pass keeps the exact raw no-function/no-xref caveat but resolves the best source-facing owner/name as a KeySpeedMgr member method: the body is a complete two-argument keyboard-repeat setter ending ret 8, applies delay <= 3 and speed <= 31 through SystemParametersInfoW, pairs with the fast-repeat member, and the fast-helper callers prove no-this-access is not sufficient for file-local ownership. Owner/emitter should change from [UID:0000KJ] to [UID:00006Z]; first-draft C++ is ready, with original helper spelling and liveness still capped below final-audit confidence.
```

Replace [UID:00018Q] row with:

```text
        - [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md) 0x004effa0-0x004effbd | method | KeySpeedMgr::ApplyFastKeyboardRepeatSettings : reconstructable : 88% : strong : B006 direct call-site recheck shows Application::Initialize sets ecx to the constructed KeySpeedMgr before caller 0x00463ab5 and BaramAppOnActivate loads/tests g_pKeySpeedMgr before caller 0x00466a24, so the helper is a KeySpeedMgr member method despite not reading fields. Body applies fast repeat with SystemParametersInfoW(SPI_SETKEYBOARDDELAY,0,0,SPIF_UPDATEINIFILE) and SystemParametersInfoW(SPI_SETKEYBOARDSPEED,31,0,SPIF_UPDATEINIFILE); owner/emitter should change from [UID:0000KJ] to [UID:00006Z] and first-draft C++ is ready.
```

Replace [UID:0002IT] row with:

```text
        - [UID:0002IT][0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor](by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md) 0x004effc0-0x004f0008 | scalar-deleting-destructor | KeySpeedMgr scalar deleting destructor wrapper : ignored : 86% : strong : B006 source-quality pass confirms vtable slot 0x0061c9c8 -> 0x004effc0, duplicated vptr/global/base-cleanup sequence, delete-flag/free/guard handling, no direct code callers, and DestroyKeySpeedMgr vtable dispatch. This exact page is compiler-generated destructor wrapper output from the virtual destructor declaration and ordinary destructor body, so it should be non-emitting with blank formal C++; do not hand-author vptr writes, LObject cleanup, operator delete, or guard-check logic.
```

If [UID:0002IQ] row is touched for consistency, this replacement is optional:

```text
        - [UID:0002IQ][0x004efee0-0x004efef5.KeySpeedMgrDestructor](by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md) 0x004efee0-0x004efef5 | destructor | KeySpeedMgr::~KeySpeedMgr : reconstructable : 87% : strong : Raw PE/Capstone recheck confirms exact ordinary destructor body, vptr store, g_pKeySpeedMgr clear, tail jump to LObject cleanup, no direct refs to the ordinary destructor start, and scalar deletion through vtable slot 0x0061c9c8 -> 0x004effc0. Formal source body remains KeySpeedMgr::~KeySpeedMgr() { g_pKeySpeedMgr = 0; }, leaving vptr/base cleanup/delete-wrapper mechanics to compiler emission.
```

## Changed Files

- Created: `tools/leaser/Agents/Agent-B006/research/00018O-KeySpeedMgr-aggregate-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Generated/project/by-* files edited: none.
- `by-memory/-coverage-report.md` edited: no.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/00018O-KeySpeedMgr-aggregate-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00018O"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00018O-KeySpeedMgr-aggregate-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/00018O-KeySpeedMgr-aggregate-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00018O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
