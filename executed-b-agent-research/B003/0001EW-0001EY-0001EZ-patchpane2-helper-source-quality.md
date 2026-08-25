** TARGET-REPORT-UID:0001EW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001EW]/[UID:0001EY]/[UID:0001EZ] PatchPane2 Helper Source-Quality Report

Assignment: `B003-goal2-patchpane2-helper-followup-source-quality-0001EW-0001EY-0001EZ-20260617`

Primary targets:

- [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](../../../by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md), starting `82/88`
- [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](../../../by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md), starting `82/88`
- [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](../../../by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md), starting `82/88`

## Executive Recommendation

| UID | Current | Recommended | Metadata recommendation | Formal C++ |
| --- | --- | --- | --- | --- |
| [UID:0001EW] | `82/88`, reconstructable, owner/emitter [UID:0000AA] | `86/91` | Keep `CANONICAL_OWNER:0000AA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AA`. | Do not populate; callback ABI/type is not source-final. |
| [UID:0001EY] | `82/88`, reconstructable, owner/emitter [UID:0000AA] | `86/90` | Keep `CANONICAL_OWNER:0000AA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AA`. | Do not populate; string/request API names are not source-final. |
| [UID:0001EZ] | `82/88`, reconstructable, owner/emitter [UID:0000AA] | `88/92` | Change to `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`. | Blank; constructor-EH cleanup glue, not handwritten source. |

The two live helper bodies [UID:0001EW] and [UID:0001EY] can clear the active 85/85 documentation gate because the current pass resolves the best source-facing role, caller/callee evidence, field directions, queue semantics, and generated-output pollution. They should stay exact PatchPane2 children under [UID:0000AA] / [UID:0000MH] but should not receive formal C++ yet.

[UID:0001EZ] should be reclassified. Current IDA shows it is reached only from the `PatchPane2` constructor unwind funclet at `0x00605eb1`; ordinary destruction clears `g_pPatchPane2` separately at `0x005493d0`. This matches the project treatment for constructor-EH singleton clear helpers such as `ClearTerminalPaneSingletonEH` and `MessageShowPaneClearSingletonEH`: keep the evidence page, but make it non-emitting compiler/EH cleanup glue rather than a source-authored PatchPane2 method.

## Scope And Evidence Checked

Docs checked:

- Primary target pages [UID:0001EW], [UID:0001EY], [UID:0001EZ].
- [UID:0000AA] `PatchPane2`, [UID:0000MH] `PatchPane`, [UID:0001EQ] `PatchPaneAndPatchPane2`, [UID:0001EV] `PatchPane2MainLoop`, [UID:0001VJ] `PatchPane2Layout`, [UID:00022D] `PatchPane2DownloadPathJoinHelper`.
- [UID:0000RQ] `g_pMiscWorkThread`, [UID:0001CJ] `MiscWorkThreadAndNotifications`, [UID:00008I] `MiscWorkThread`, [UID:0001SP] `MiscWorkThreadMessageId`, [UID:000069] `httpget::Notification`, [UID:0001SN] `HttpGetNotificationState`.
- [UID:0000RZ] `g_pPatchPane2`, [UID:0001YF] `PatchPaneVtableFamily`, [UID:0002OJ] `PatchPane2VtableData`.
- Existing executed B reports. Only relevant direct lead found: `Agent-B003/research/executed/0001EQ-patchpane-family-source-quality.md`; old singleton-slot report `executed/older/0002A0-ParcelAndPatchPaneSingletonSlots-memory-range-report.md` was used only as historical support.
- Current coverage rows in `by-memory/-coverage-report.md`.
- Current generated `source-3/simroot_v2/class_PatchPane2.cpp` and Wave2/Wave3 metadata only as non-authoritative generated-output leads.

Live IDA MCP checks in session `b003_00018a_ime_comp_20260617`:

- `lookup_funcs` for `0x00548f30`, `0x00549220`, `0x00549340`, `0x00528290`, `0x004b32d0`, `0x00548a80`, `0x00548690`, and `0x00549370`.
- `decompile` / `disasm` for the three target bodies, `PatchPane2::PatchPane2`, `PatchPane2::HandleDownloadWorkEvent`, `PatchPane2DownloadPathJoinHelper`, and `MiscWorkThread` request wrapper `0x00528290`.
- `xrefs_to` for target starts, `0x004b32d0`, `0x00528290`, `0x0069ba2c`, `0x0067ab50`, and the request-format object at `0x00621ff8`.
- `find_regex` for patcher/request strings.

## Target Findings

### [UID:0001EW] Work-Event Predicate

Best source-facing name: `PatchPane2::AcceptsDownloadWorkEvent`.

Best source-facing signature direction: a secondary callback-interface predicate taking a work-event/notification pointer and returning `bool`. IDA's exact ABI is `bool __stdcall sub_548F30(int event)`, with one stack argument and `retn 4`; a normal C++ member-function signature is therefore not safe to enter as formal code.

Evidence:

- `lookup_funcs 0x00548f30` reports `sub_548F30`, size `0x11`.
- Decompile: `return *(_BYTE *)(event + 4) == 22;`.
- Disassembly is seven instructions: load stack argument, compare byte `[eax+4]` to `0x16`, `setz al`, `retn 4`.
- `xrefs_to 0x00548f30` reports one data reference at `0x00621fb4`, the secondary `PatchPane2` vtable slot immediately before the main work-event callback slot at `0x00621fb8`.
- `analyze_function 0x00548f30` reports no callees and no ordinary callers.
- [UID:0001EV] confirms the paired handler accepts events whose channel at `event + 0x08` is `0x68747470` (`http`) and switches on payload state `0-4`.

Rejected alternatives:

- `static` file-local filter: rejected because the only xref is a vtable slot in the `+0xa0` callback subobject.
- `PatchPane2::IsHttpWorkEvent`: rejected as too broad. The predicate checks byte `+4 == 0x16`, not the `http` channel; the main handler does the `0x68747470` channel check.
- Treating the no-direct-caller state as dead code: rejected because vtable-only reachability is expected for this callback.

Score impact: raise to `86/91`. The remaining uncertainty is ABI/type declaration, not behavior, ownership, range, or source placement. It caps formal C++ but does not cap documentation completion below 85.

### [UID:0001EY] Send Download Request

Best source-facing name/signature: `void PatchPane2::SendDownloadRequest()`.

Best field/source directions:

- `+0x26c`: request leaf/final patcher path string used as the third component in the formatted request suffix.
- `+0x270`: temporary download path string (`Patcher.exe.new` side), not directly used by this helper.
- `+0x274/+0x278/+0x27c`: vector of download path/file entries; `+0x274 + 4 * currentIndex` selects the base entry copied into the outgoing request.
- `+0x280`: current download entry index.
- `+0x28c/+0x290`: two numeric patch/download version components copied from the constructor input descriptor and formatted into the request suffix.
- [UID:00022D] is best described as `CopyAndAppendDownloadRequestPath` / path-join support: it copies the selected vector entry into a temporary string and appends the formatted suffix.

Behavior:

1. Reads `this + 0x26c` through the string `c_str`/view helper.
2. Formats a suffix from the request-format object at `0x00621ff8`, fields `+0x28c/+0x290`, and the `+0x26c` string.
3. Selects the current vector entry from `+0x274 + 4 * [this + 0x280]`.
4. Calls [UID:00022D] at `0x004b32d0` to copy the selected entry and append the suffix.
5. Reads [UID:0000RQ] `g_pMiscWorkThread` at `0x0067ab50` and calls `0x00528290`.
6. `0x00528290` allocates one `SimpleUString` payload and posts MiscWorkThread message `0x47654874` (`GeHt` / `GetHttp`) through `Thread` queue helper `0x00596960`.

Evidence:

- `lookup_funcs 0x00549220` reports `sub_549220`, size `0xaf`.
- `xrefs_to 0x00549220` reports constructor call `0x005489e0` and main-loop calls `0x00548c71`, `0x00548c9b`, `0x00548cc1`.
- Disassembly confirms `lea ecx, [esi+26Ch]`, pushes `[esi+290h]`, `[esi+28Ch]`, `off_621FF8`, then selects `[esi+274h] + [esi+280h] * 4`.
- `xrefs_to 0x004b32d0` reports only `0x0054928d` from this helper; `decompile 0x004b32d0` copies `arg1` into `arg0`, measures `arg2`, then appends all of `arg2`.
- `xrefs_to 0x00528290` reports only `0x005492aa` from this helper.
- `decompile 0x00528290` posts message decimal `1197820020` / hex `0x47654874`, matching [UID:0001SP] `GetHttp`.
- `xrefs_to 0x0067ab50` includes `0x00549295` inside this helper, proving MiscWorkThread ownership of the queue API and rejecting `CashShopRequest` generated-owner pollution.

Rejected alternatives:

- Generated `CashShopRequest::SendRequest`: rejected by live xrefs and `g_pMiscWorkThread` read; `0x00528290` is the `MiscWorkThread::RequestHTTPGet`-style wrapper.
- FolderTree ownership for [UID:00022D]: rejected because the helper's only caller is `PatchPane2::SendDownloadRequest`.
- Treating the visible rdata tail at `0x00621ffc` as the full raw C format: rejected because the actual argument is the string object at `0x00621ff8`. The safe semantic statement is "two version numbers plus one request leaf/path string", not a fully recovered original literal spelling.

Score impact: raise to `86/90`. The exact behavior, call graph, field roles, queue message, and owner/source placement are now sufficient above the gate. Formal C++ remains unsafe because the final `SimpleUString`/`LObject` API names, format helper spelling, and original field names are still descriptive rather than recovered.

### [UID:0001EZ] Clear PatchPane2 Singleton

Best classification: non-emitting constructor-unwind/EH cleanup helper for the `PatchPane2` singleton publish step.

Evidence:

- `lookup_funcs 0x00549340` reports `sub_549340`, size `0x0b`.
- Decompile and disassembly: one write, `g_pPatchPane2` / `dword_69BA2C = 0`, followed by `retn`.
- `xrefs_to 0x00549340` reports a single code reference at `0x00605eb1`, inside the `PatchPane2::PatchPane2` constructor unwind/cleanup funclet region.
- Constructor disassembly shows the surrounding funclet chain at `0x00605ea0-0x00605edb`: cleanup of constructor state, the `jmp sub_549340`, and string/vector destructor funclets for `+0x26c`, `+0x270`, and `+0x274`.
- `xrefs_to 0x0069ba2c` reports constructor publish/fallback writes at `0x005486f4` and `0x005486fb`, this EH clear at `0x00549340`, and ordinary scalar-destructor clear at `0x005493d0`.
- Sibling docs `ClearTerminalPaneSingletonEH`, `MessageShowPaneClearSingletonEH`, and `BulletinSessionConstructorUnwindSingletonClear` classify the same shape as non-emitting compiler/EH cleanup, not handwritten source.

Rejected alternatives:

- Keep as a normal `PatchPane2` method: rejected because there are no ordinary callers and no `this` argument; the only function xref is constructor EH cleanup glue.
- Emit a file-local `ClearPatchPane2Singleton()` function: rejected because final handwritten source should express constructor/destructor singleton lifetime normally. The compiler may emit an equivalent cleanup funclet, but source reconstruction should not force a standalone helper.
- Ignore the range entirely: rejected because it is important lifecycle evidence for `g_pPatchPane2` and for constructor-failure cleanup.

Score impact: raise to `88/92`, but change to non-reconstructable/non-emitting with `CANONICAL_OWNER:NONE`. This closes the stale "helper spelling/unwind role" caveat by deciding the role is EH cleanup glue.

## Heuristic / Inference Reanalysis And Validation

Best defensible names/types/source directions:

- `0x00548f30`: `PatchPane2::AcceptsDownloadWorkEvent`.
  - Evidence checked: exact function, one secondary-vtable xref at `0x00621fb4`, predicate byte test, no callees/callers, paired main handler at `0x00621fb8`.
  - Rejected alternatives: `static` filter, dead code, or `IsHttpWorkEvent`.
  - Remaining blocker: original callback interface type and ABI are not recovered. The function is vtable-installed but decompiles as `__stdcall(event)` with no `this`.
  - Impact: score can clear 85; formal C++ remains blank.

- `0x00549220`: `PatchPane2::SendDownloadRequest`.
  - Evidence checked: constructor and main-loop callers, field-offset uses, [UID:00022D] only-caller path join, `g_pMiscWorkThread` read, `0x00528290` `GetHttp` queue wrapper, generated Wave3 pollution.
  - Rejected alternatives: `CashShopRequest` ownership, FolderTree helper ownership, generic network/source owner.
  - Best field names: `requestLeafPath` / `patcherExePath` for `+0x26c`, `tempDownloadPath` for `+0x270`, `downloadPathEntries` for vector `+0x274`, `currentDownloadIndex` for `+0x280`, `downloadVersionMajor` / `downloadVersionMinor` or neutral `requestVersion0/1` for `+0x28c/+0x290`.
  - Remaining blocker: original string wrapper API and field spellings are not final, and the string object at `0x00621ff8` prevents safely claiming the raw literal spelling.
  - Impact: score can clear 85; formal C++ remains blank.

- `0x00549340`: constructor-EH cleanup helper, not a normal method.
  - Evidence checked: exact body, one code xref at `0x00605eb1`, surrounding constructor funclets, `g_pPatchPane2` lifecycle refs, scalar destructor counterpart.
  - Rejected alternatives: class method, public/global source helper, deletion/ignore.
  - Impact: target should become non-reconstructable/non-emitting at high confidence; support docs should call it constructor-unwind cleanup.

Source placement:

- Keep [UID:0001EW] and [UID:0001EY] under [UID:0000AA] `PatchPane2`, routed through [UID:0000MH] `NexusTK/patch/PatchPane.cpp`.
- Do not route [UID:0001EY] to `MiscWorkThread.cpp`; MiscWorkThread owns the queue service and `GetHttp` worker, while PatchPane2 owns the request content and state.
- Do not route [UID:00022D] to FolderTree despite physical adjacency; only PatchPane2 calls it.
- [UID:0001EZ] should have no emitter/owner as an exact EH-glue page, while semantic lifecycle evidence remains cross-linked from PatchPane2 and `g_pPatchPane2`.

Generated-output validation:

- Wave3 `class_PatchPane2.cpp` omits `0x00548f30` and `0x00549340`.
- Wave3 emits `0x00549220`, but with fidelity/source score `44`, wrong `CashShopRequest::SendRequest` owner, and incomplete string/request semantics.
- Wave2 says `PatchPane2.cpp`; accepted source docs route current reconstruction through `patch/PatchPane.cpp`. Treat `PatchPane2.cpp` as an optional original-file hint, not a current owner blocker.

Final-C++ impact:

- [UID:0001EW] and [UID:0001EY] are reconstructable/emitting and clear the documentation gate, but formal C++ should remain blank under rule 20 because the proposed code would require guessed ABI/type/API names.
- [UID:0001EZ] should not be reconstructable/emitting, so formal C++ remains blank by classification.

## Exact Target-Doc Changes For Supervisor

### [UID:0001EW] Header

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000AA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000AA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `## Reconstruction Notes` replacement:

```markdown
## Reconstruction Notes

Mark this page reconstructable because the body, range, ownership, and vtable reachability are exact. Best source-facing name is `PatchPane2::AcceptsDownloadWorkEvent`: the helper is the secondary callback-interface predicate paired with `PatchPane2::HandleDownloadWorkEvent` and accepts events whose byte at `+0x04` is `0x16`.

Leave formal C++ blank. IDA's exact ABI is `bool __stdcall(int event)` with a single stack argument and `retn 4`, while the slot is still stored in the `PatchPane2` secondary vtable. Until the original callback interface declaration is recovered, a normal C++ member-function signature would likely encode the wrong ABI.
```

Append to `## Changes`:

```markdown
- 2026-06-17 B003 follow-up source-quality reanalysis:
  - Before: `82/88`, with final source-level callback type/name left medium.
  - After: `86/91`; owner/emitter remain [UID:0000AA][PatchPane2](by-class/PatchPane2.md), formal C++ remains blank.
  - Summary/evidence: live IDA reconfirmed the exact `0x11` body, single secondary-vtable xref at `0x00621fb4`, no direct callers/callees, and paired handler at `0x00621fb8`. Best source-facing name is `PatchPane2::AcceptsDownloadWorkEvent`; final C++ is held because the callback ABI/interface type is not recovered.
```

### [UID:0001EY] Header

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000AA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000AA | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `## Reconstruction Notes` replacement:

```markdown
## Reconstruction Notes

Mark this page reconstructable as `PatchPane2::SendDownloadRequest`. The helper has exact constructor/main-loop callers, exact field use, and a resolved queue path: it formats a request suffix from `+0x28c/+0x290` and the `+0x26c` request leaf string, joins that suffix to the selected vector entry at `+0x274 + 4 * currentIndex` through [UID:00022D][0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper](by-memory/0x004b32d0-0x004b3344.PatchPane2DownloadPathJoinHelper.md), then posts a `GetHttp` (`0x47654874`) request through [UID:0000RQ][g_pMiscWorkThread](by-global/g_pMiscWorkThread.md) wrapper `0x00528290`.

Leave formal C++ blank. The active generated body is polluted by `CashShopRequest::SendRequest`, and the final `SimpleUString`/format/path-join API names plus original field spellings are not source-final.
```

Append to `## Changes`:

```markdown
- 2026-06-17 B003 follow-up source-quality reanalysis:
  - Before: `82/88`, with final request queue/string/vector names left provisional.
  - After: `86/90`; owner/emitter remain [UID:0000AA][PatchPane2](by-class/PatchPane2.md), formal C++ remains blank.
  - Summary/evidence: live IDA reconfirmed the `0xaf` boundary, constructor/main-loop callers, request-format object at `0x00621ff8`, field use at `+0x26c/+0x274/+0x280/+0x28c/+0x290`, only-caller path-join helper [UID:00022D], `g_pMiscWorkThread` read at `0x00549295`, and `GetHttp` queue wrapper `0x00528290`. Generated `CashShopRequest` ownership is rejected.
```

### [UID:0001EZ] Header

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended `## Status` replacement:

```markdown
## Status

- Disposition: non-emitting constructor-EH cleanup glue over project singleton state.
- Entity kind: tiny constructor-unwind singleton clear helper.
- Source-facing context: [UID:0000AA][PatchPane2](by-class/PatchPane2.md) constructor/lifecycle cleanup in [UID:0000MH][PatchPane](by-file/PatchPane.md).
- Ownership/emission: `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:FALSE` are intentional because this is compiler/unwind cleanup rather than a handwritten PatchPane2 method.
- Confidence: very strong for exact range, data write, constructor-unwind reference, and scalar-destructor counterpart.
```

Recommended `## Reconstruction Notes` replacement:

```markdown
## Reconstruction Notes

Do not model this as a normal public or file-local `PatchPane2` source method. The final handwritten source should express normal `g_pPatchPane2` constructor/destructor lifetime ownership; the compiler can emit equivalent constructor-failure cleanup if needed.

Keep the page because the side effect is important evidence: constructor publish/fallback writes occur at `0x005486f4` and `0x005486fb`, this EH helper clears the singleton at `0x00549340`, and the scalar deleting destructor clears the same slot at `0x005493d0`.
```

Append to `## Changes`:

```markdown
- 2026-06-17 B003 follow-up source-quality reanalysis:
  - Before: `82/88`, `CANONICAL_OWNER:0000AA`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AA`, with helper spelling and unwind role left unresolved.
  - After: `88/92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, formal C++ blank.
  - Summary/evidence: live IDA reconfirmed the exact `0x0b` body (`g_pPatchPane2 = 0; ret`), one code xref at constructor-unwind funclet `0x00605eb1`, no ordinary callers/callees, and scalar deleting destructor clear at `0x005493d0`. This matches sibling constructor-EH singleton clear pages and should be non-emitting compiler cleanup glue.
```

## Exact Support-Doc Changes For Supervisor

No support-doc score changes are required. Recommended text-only clarifications:

### [UID:0000AA] `by-class/PatchPane2.md`

Replace the `0x00549220` row note with:

```markdown
| `0x00549220-0x005492cf` | [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) | Formats the version/request suffix, joins it to the selected download vector entry, and queues a `MiscWorkThread::RequestHTTPGet` / `GetHttp` work item. |
```

Replace the `0x00549340` row note with:

```markdown
| `0x00549340-0x0054934b` | [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) | Constructor-EH cleanup helper that clears `g_pPatchPane2`; document but do not emit as a PatchPane2 source method. |
```

### [UID:0001EQ] `PatchPaneAndPatchPane2`

Replace the `0x00549340-0x0054934b` covered-function note with:

```markdown
| `0x00549340-0x0054934b` | no handwritten owner / [UID:0000AA][PatchPane2](by-class/PatchPane2.md) lifecycle context | [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md), constructor-EH cleanup glue that clears [UID:0000RZ][g_pPatchPane2](by-global/g_pPatchPane2.md); non-emitting. |
```

Replace the boundary note for the same range with:

```markdown
| `0x00549340-0x0054934b` | [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) is exact constructor-unwind cleanup for `g_pPatchPane2`; keep documented but non-emitting. |
```

### [UID:0000RZ] `g_pPatchPane2`

In the Purpose paragraph, replace "the clear helper at `0x00549340`" with:

```markdown
the constructor-EH clear helper at `0x00549340`
```

## First-Draft C++ Recommendation

Do not populate formal C++ for any of the three target pages from this report.

[UID:0001EW] clears the score gate, but formal C++ is unsafe because IDA shows a `__stdcall` one-argument ABI while vtable evidence shows callback-interface placement. A normal member signature would likely be wrong. Review-only shape:

```cpp
// Review-only; do not enter as formal C++ until the callback interface ABI is named.
bool __stdcall PatchPane2_AcceptsDownloadWorkEvent(const WorkEventHeader* event)
{
    return event->kind == 0x16;
}
```

[UID:0001EY] clears the score gate, but formal C++ is unsafe because the active generated output uses the wrong owner/API (`CashShopRequest`) and the final string/request helper names are still unresolved. Review-only shape:

```cpp
// Review-only; do not enter as formal C++ until string and queue APIs are source-final.
void PatchPane2::SendDownloadRequest()
{
    SimpleUString suffix;
    suffix.Format(kPatchDownloadRequestFormat,
                  m_requestVersion0,
                  m_requestVersion1,
                  m_requestLeafPath.c_str());

    SimpleUString requestPath(m_downloadPathEntries[m_currentDownloadIndex]);
    requestPath.Append(suffix);
    g_pMiscWorkThread->RequestHTTPGet(requestPath.c_str());
}
```

[UID:0001EZ] should be non-reconstructable/non-emitting. No C++ should be entered. If the semantic action is needed during a constructor rewrite, it belongs inside `PatchPane2::PatchPane2` failure cleanup/lifetime handling, not as a standalone source function.

## Supervisor-Owned Coverage Row Text

Placement context: replace the existing rows in `by-memory/-coverage-report.md` under [UID:0001EQ] `0x005470b0-0x0054940f.PatchPaneAndPatchPane2`, after the `0x00548f1a-0x00548f30` generated-data row for [UID:0001EW], and after the `0x00549214-0x00549220` padding row for [UID:0001EY]/[UID:0001EZ].

```markdown
    - [UID:0001EW][0x00548f30-0x00548f41.PatchPane2WorkEventPredicate](by-memory/0x00548f30-0x00548f41.PatchPane2WorkEventPredicate.md) 0x00548f30-0x00548f41 | virtual callback predicate | PatchPane2::AcceptsDownloadWorkEvent : reconstructable : 86% : strong : Exact secondary-vtable predicate returning `event+4 == 0x16`, paired with `PatchPane2::HandleDownloadWorkEvent`; live IDA confirms exact `0x11` body, only vtable xref at `0x00621fb4`, no callees/direct callers, best callback name, and remaining ABI/interface-type C++ blocker.
```

```markdown
    - [UID:0001EY][0x00549220-0x005492cf.PatchPane2SendDownloadRequest](by-memory/0x00549220-0x005492cf.PatchPane2SendDownloadRequest.md) 0x00549220-0x005492cf | helper method | PatchPane2::SendDownloadRequest : reconstructable : 86% : strong : PatchPane2 request helper with exact boundary, constructor/main-loop callers, request suffix built from fields `+0x28c/+0x290/+0x26c`, current vector-entry selection at `+0x274/+0x280`, [UID:00022D] path-copy/append helper, `g_pMiscWorkThread` read, `GetHttp` queue wrapper `0x00528290`, and remaining string/API-name C++ blocker.
```

```markdown
    - [UID:0001EZ][0x00549340-0x0054934b.ClearPatchPane2Singleton](by-memory/0x00549340-0x0054934b.ClearPatchPane2Singleton.md) 0x00549340-0x0054934b | constructor-EH cleanup helper | ClearPatchPane2Singleton : non-reconstructable : 88% : very strong : Exact `0x0b` constructor-unwind helper that clears `g_pPatchPane2` at `dword_69BA2C`; live IDA confirms one code xref from constructor EH funclet `0x00605eb1`, no ordinary callers/callees, constructor publish/fallback refs, scalar-destructor counterpart at `0x005493d0`, and non-emitting compiler-cleanup classification.
```

## Validation Commands

Recommended supervisor validation:

> Executable block R001 was removed from this report and preserved verbatim in [0001EW-0001EY-0001EZ-patchpane2-helper-source-quality-removed.md](0001EW-0001EY-0001EZ-patchpane2-helper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/MCP checks to reproduce:

```text
lookup_funcs 0x00548f30 0x00549220 0x00549340 0x004b32d0 0x00528290 0x00548a80 0x00548690 0x00549370
decompile 0x00548f30
decompile 0x00549220
decompile 0x00549340
decompile 0x004b32d0
decompile 0x00528290
decompile 0x00548a80
xrefs_to 0x00548f30
xrefs_to 0x00549220
xrefs_to 0x00549340
xrefs_to 0x004b32d0
xrefs_to 0x00528290
xrefs_to 0x0069ba2c
xrefs_to 0x0067ab50
disasm 0x00549220
disasm 0x00605eb0
```

## Changed / No-Change Scope

Changed by this assignment: this report file only.

No by-* docs, generated reports, generated source, IDA DB, source files, or `by-memory/-coverage-report.md` were edited. No split was performed; [UID:0001EZ] needs metadata/source-classification repair, not a new child page.

## Blockers And Follow-Up

No blocker remains for supervisor review. The useful follow-up after this report is a dedicated final-C++ pass for `PatchPane2::HandleDownloadWorkEvent` / `SendDownloadRequest` after the callback interface, `SimpleUString` API names, and final PatchPane2 field names are source-final.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001EW-0001EY-0001EZ-patchpane2-helper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001EW"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001EW-0001EY-0001EZ-patchpane2-helper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001EW-0001EY-0001EZ-patchpane2-helper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001EW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
