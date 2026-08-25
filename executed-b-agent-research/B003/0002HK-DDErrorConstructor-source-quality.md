** TARGET-REPORT-UID:0002HK **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Research Report: 0002HK DDErrorConstructor Source Quality

Assignment: `B003-report-0002HK-DDErrorConstructor-source-quality-20260627`

Agent: Agent-B003

Mode: report-only research first. No by-* target/support documents were edited in this pass.

Primary target: [UID:0002HK] `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md`

Required report path: `tools/leaser/Agents/Agent-B003/research/0002HK-DDErrorConstructor-source-quality.md`

## Verdict

`0002HK` is source-ready as an exact first-draft constructor and should receive formal C++ in the target page.

Recommended target metadata:

- `COMPLETION: 85 -> 90`
- `CONFIDENCE: 89 -> 92`
- `CANONICAL_OWNER: 00003L` unchanged
- `RECONSTRUCTABLE: TRUE` unchanged
- `EMITTER_UIDS: 00003L` unchanged
- `EMITTER_POSITION_OPTIONAL:` remains blank

Recommended exact formal C++:

```cpp
DDError::DDError(HRESULT result)
    : m_errorCode(result)
{
}
```

Rationale: live IDA MCP evidence confirms a 36-byte, one-block constructor that calls the `LObject` base constructor, stores the caller-supplied DirectDraw status at `this + 0x04`, installs the `DDError` vtable, and returns `this`. Current error hierarchy support docs already converge on the source-facing constructor spelling `DDError::DDError(HRESULT result)` and member name `HRESULT m_errorCode`. The vtable write and `sub_4F4A80` base setup are compiler output and should not be emitted as source statements.

## Current Documentation State

Target page state checked before this report:

- `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md` is currently `COMPLETION:85`, `CONFIDENCE:89`, `CANONICAL_OWNER:00003L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003L`.
- The target already records the main facts: caller HRESULT/status store at `+0x04`, `DDError` vtable installation, only shared base-setup callee, and DirectDraw/render caller refs.
- The target does not currently carry formal C++. Its blank-code reason is stale relative to the current support-doc state: it says hierarchy declaration, method names, and helper splits are not source-quality enough.
- `auto-generated/-ag-research-tracker.md` is stale for this UID. Its queue row still reports `78/88`, combined `83.0`, blank owner/emitter route, and no generated C++.
- `auto-generated/-ag-memory-coverage.md` already routes [UID:0002HK] through [UID:00003L] to `auto-generated/NexusTK/util/Error.cpp`, but still marks no generated code.
- `auto-generated/-ag-coverage-report-by-memory.md` is also stale at `78% : strong` / `emits_code:false`.

Generated reports must not be hand-edited. They should refresh only through the validator/generator in the supervisor implementation phase.

## Live IDA MCP Evidence

MCP availability was confirmed before finalizing this report.

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active IDB session: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- Server state: `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready

Function and boundary checks:

- `lookup_funcs 0x004a6260` reports `sub_4A6260`, size `0x24`.
- `lookup_funcs 0x004a6284` reports no function at the end boundary.
- `0x24` is decimal 36, verified with `tools/int_convert.py`.
- `get_bytes 0x004a6250` shows the predecessor ends before `0x004a6260`, five `0xcc` bytes precede the constructor, the constructor bytes occupy exactly `0x004a6260-0x004a6284`, and `0x004a6284` begins `0xcc` padding before the formatter successor.
- `get_bytes 0x004a6284` confirms padding bytes before the next function prologue.

Constructor decompile:

```cpp
sub_4F4A80(this);       /* 0x4a626a */
this[1] = a2;           /* 0x4a6272 */
result = this;          /* 0x4a6275 */
*this = &DDError::`vftable'; /* 0x4a6277 */
return result;          /* 0x4a627d */
```

Constructor assembly:

```asm
004a6260  push ebp
004a6261  mov ebp, esp
004a6263  push ecx
004a6264  push esi
004a6265  mov esi, ecx
004a6267  mov [ebp+var_4], esi
004a626a  call sub_4F4A80
004a626f  mov eax, [ebp+arg_0]
004a6272  mov [esi+4], eax
004a6275  mov eax, esi
004a6277  mov dword ptr [esi], offset ??_7DDError@@6B@
004a627d  pop esi
004a627e  mov esp, ebp
004a6280  pop ebp
004a6281  retn 4
```

Constructor properties:

- One basic block.
- Cyclomatic complexity 1.
- One callee: `sub_4F4A80`.
- No strings.
- No constants beyond the vtable address and argument/member offsets.
- Prototype recovered as `_DWORD *__thiscall(_DWORD *this, int)`.
- ABI has one explicit stack argument and `retn 4`, matching `DDError::DDError(HRESULT result)`.

Base constructor check:

- `lookup_funcs 0x004f4a80` reports `sub_4F4A80`, size `0x9`.
- Decompile writes the `LObject` vtable to `this` and returns `this`.
- Assembly is `mov dword ptr [ecx], offset ??_7LObject@@6B@; mov eax, ecx; retn`.
- This is source-level `LObject` base construction, not a handwritten DDError source statement.

Vtable and hierarchy data:

- `xrefs_to 0x0061938c` reports one data write, at `0x004a6277` inside this constructor.
- `get_bytes 0x00619388` decodes the DDError RTTI/vtable data:
  - RTTI/COL dword: `0x00646c70`
  - Vtable base: `0x0061938c`
  - Destructor slot: `0x004a68a0`
  - Inherited runtime slot: `0x004f4b10`
  - No-op slot: `0x0041b6c0`
  - Message slot: `0x004a6290`
  - Name slot: `0x004a6a70`
- `xrefs_to 0x004a6290` reports the expected data ref at `0x00619398`, the DDError message slot.

Formatter string support:

- `xrefs_to 0x006194e8` reports use at `0x004a62ea` for `DirectDrawError: %s  0x%p`.
- `xrefs_to 0x0061951c` reports use at `0x004a630d` for `DirectDrawError: 0x%p`.
- These strings support the class identity and formatter sibling, but they are not constructor source statements.

## Caller and HRESULT Route

`xrefs_to 0x004a6260` reports 14 code xrefs, grouped into five caller functions:

- `0x004b8e20` / render-region update path: call at `0x004b94ba`; pushes a saved result local and throws with `__TI4PAVDDError@@`.
- `0x00556a60` / `ScreenPane` teardown path: calls at `0x00556c59`, `0x00556c8a`, and `0x00556cb4`; pushes `esi`, including the duplicate temporary-format-then-throw pattern.
- `0x00557470` / `SurfaceFlipSurfaces`: calls at `0x00557640` and `0x0055767c`; DirectDraw failure paths push `esi`.
- `0x005576a0` / `ScreenPane::RestoreDirectDrawState`: calls at `0x00557766`, `0x005577ab`, and `0x005577e9`; DirectDraw `RestoreDisplayMode` and `SetCooperativeLevel` HRESULTs are tested as signed failures before constructing `DDError`.
- `0x00558840` / minimap/surface initializer: calls at `0x00558a26`, `0x00558a86`, `0x00558ad6`, `0x00558b1a`, and `0x00558f3c`; DirectDraw vtable call return values are copied into locals, tested for negative HRESULT failure, then passed to the constructor.

Representative live decompile and disassembly facts:

- `analyze_function 0x005576a0` shows `g_pDirectX` / DirectDraw access, a `RestoreDisplayMode` result saved into `v3`, `v3 < 0` failure check, allocation of `0x08` bytes, `sub_4A6260(v4, v3)`, and `CxxThrowException`.
- The same function shows `SetCooperativeLevel` result `v6`, temporary `DDError(v6)`, virtual message-slot call with capacity `0x50`, then a second `DDError(v6)` throw. `0x50` is decimal 80, verified with `tools/int_convert.py`.
- `analyze_function 0x00558840` and local disassembly windows show DirectDraw vtable returns copied to `edi`, `esi`, or saved locals, tested with signed failure branches, then pushed to `sub_4A6260`.

This caller set proves the constructor parameter is not an arbitrary `int`: it is the DirectDraw `HRESULT`/status value later formatted by the DDError formatter.

## Related Support Documents Checked

The following support docs were checked and are consistent with source-ready constructor emission:

- `by-class/DDError.md`: DDError owns this constructor, wraps DirectDraw HRESULT-style failures, has vtable `0x0061938c`, and belongs under `Error.cpp`. It keeps class-level C++ blank because the formatter/declaration context is still broader than this exact constructor.
- `by-file/Error.md`: routes the error hierarchy to `NexusTK/util/Error.h` / `Error.cpp`; records `DDError::DDError(HRESULT result)` with field `HRESULT m_errorCode`; says exact child constructors can emit while broader error-wrapper aggregate C++ remains blank.
- `by-type/by-struct/ErrorObjectLayouts.md`: places DDError in the stored-status-code family with `+0x00` vtable and `+0x04` stored code; supports `HRESULT m_errorCode`.
- `by-type/by-vtable/ErrorHierarchyVtables.md`: maps DDError RTTI/vtable slots and records `FormatErrorMessage(wchar_t *destination, size_t destinationChars) const` as current best `+0x0c` formatter name and `Error::GetErrorName` for `+0x10`.
- `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`: strongest aggregate support; already names `DDError::DDError(HRESULT result)` and `HRESULT m_errorCode`, and keeps broad aggregate C++ blank only because mixed formatter/destructor/raw-helper ranges remain unresolved.
- `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`: confirms DDError vtable bytes and constructor store at `0x004a6277`.
- `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md`: confirms DDError formatter strings and xrefs.
- Caller docs checked: `SurfaceDirectDrawRestoreMaintenance`, `SurfaceMinimapRenderInitializer`, `SurfaceFlipSurfaces`, `ScreenPane`, and `g_pScreenPane` support the DirectDraw/ScreenPane/Surface call routes. They do not own the constructor.

## Blocker Reinvestigation

Field/member name:

- Accepted: `HRESULT m_errorCode`.
- Basis: `ErrorWrappers.md` and `Error.md` both use `m_errorCode` for DDError. `ErrorObjectLayouts.md` supports the `+0x04` stored status-code field. The formatter treats the field as the error code/HRESULT to resolve through DirectDraw message handling.
- Rejected: raw `this[1]`, `a2`, `m_hresult`, `m_status`, and `m_directDrawResult`. Raw names are decompiler artifacts; `m_hresult` and `m_status` are plausible but not the current support-doc convention; `m_directDrawResult` overfits the caller source and is less consistent with the shared error-wrapper family.

Constructor parameter name and type:

- Accepted: `HRESULT result`.
- Basis: all observed callers pass DirectDraw-style negative HRESULT values, and the support docs already choose `DDError::DDError(HRESULT result)`.
- Rejected: `int a2`, `DWORD`, `long`, `error`, and `hr`. `int a2` is decompiler ABI noise; `DWORD` loses HRESULT failure semantics; `long` is technically layout-compatible but less source-facing; `error`/`hr` are plausible but not the current documented spelling.

Source shape:

- Accepted: initializer-list constructor with an empty body.
- Basis: the source intent is one member initialization after base construction. The observed base constructor and vtable writes are compiler-emitted constructor mechanics, not source statements.
- Alternative body assignment:

```cpp
DDError::DDError(HRESULT result)
{
    m_errorCode = result;
}
```

This is source-equivalent but less precise than the initializer-list form already implied by the one-field constructor.

Owner/emitter route:

- Accepted: target owner/emitter remains [UID:00003L] `DDError`, routed through the error hierarchy source file [UID:0000J5] `Error.cpp` under `NexusTK/util/`.
- Rejected owners: `Surface`, `ScreenPane`, `GrafPort`, DirectX/DirectDraw helper docs, or no-owner treatment. Those pages provide caller evidence only; the vtable, class layout, formatter strings, and error hierarchy docs identify the constructor as DDError/Error.cpp code.

Split/range:

- Accepted: keep exact half-open range `0x004a6260-0x004a6284`.
- Basis: IDA reports the function size as `0x24`; no function exists at the endpoint; padding before and after is verified; the formatter starts after padding and must remain a separate child.
- Rejected: merging with formatter `0x004a6290`, widening to include padding, or treating `0x004a6284` as in-range code.

First-draft C++ readiness:

- Accepted: source C++ is safe for this exact constructor.
- The remaining hierarchy-wide blockers are not target-local blockers. The DDError formatter exact child and final header declaration still need work before class/file aggregate C++ can be broad, but this constructor is exact, reconstructable, owned, emitted, and has stable source-facing field/type/name support.

## Score Recommendation

Raise the target to `90/92`.

Reasons for the increase:

- Exact constructor range is verified live.
- End boundary and padding are verified live.
- Base constructor and vtable store are explained as compiler mechanics.
- DirectDraw HRESULT route is proven through live caller analysis.
- Field and parameter names are no longer speculative at target scope because current support docs converge on `HRESULT result` and `HRESULT m_errorCode`.
- Owner/emitter route is stable through `DDError` and `Error.cpp`.
- Formal first-draft C++ can now be emitted.

Do not raise higher than low-90s yet because original symbol spellings are not recovered, the DDError formatter exact child is still not source-final, and the broader hierarchy header/declaration context is not at final-audit quality.

## Recommended Support-Doc Sync

These are implementation recommendations for a later supervisor callback, not changes made by this report:

- Target `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md`: add the formal C++ block above, update score to `90/92`, update item summary and score rationale, and replace the stale blank-C++ reason.
- `by-class/DDError.md`: note that [UID:0002HK] is now source-ready and carries exact constructor C++; keep class-level C++ blank because formatter/declaration work remains open. Consider `86/88 -> 88/89`.
- `by-file/Error.md`: mark the DDError constructor exact child as source-ready; keep file-level aggregate C++ blank.
- `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`: update the DDError constructor row to say it emits formal constructor C++; keep aggregate score/C++ conservative.
- `by-type/by-struct/ErrorObjectLayouts.md`: sync that `HRESULT m_errorCode` is source-ready for [UID:0002HK], while broader family field-name finalization can remain open where not proven.
- `by-type/by-vtable/ErrorHierarchyVtables.md`: add current MCP session evidence and mark constructor source-readiness; no score change needed.
- `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`: add current session evidence for the constructor/vtable store; no score change needed.
- `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md`: no required edit unless the supervisor wants a cross-link; the formatter string evidence is already present.
- Caller docs do not require edits for ownership; they already carry the DirectDraw DDError throw routes at sufficient detail.

## Implementation Tracking Checklist

Implementation callback completed by Agent-B003 after supervisor acceptance.

- [x] Updated `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md` metadata to `COMPLETION:90`, `CONFIDENCE:92`, keeping `CANONICAL_OWNER:00003L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003L`, and blank `EMITTER_POSITION_OPTIONAL`. Proof: target validator command `000000003897` at `2026-06-27T06:20:56-04:00` exited `0` with `ok:1`.
- [x] Updated the target item summary to state that live MCP session `80de0a67` confirms the 36-byte one-block body, `LObject` base setup, caller-supplied HRESULT/result store at `+0x04` as `m_errorCode`, DDError vtable install, 14 DirectDraw/render throw-site refs, and clean padding before the formatter.
- [x] Replaced the target blank-C++ reason with a source-ready explanation, and added this exact formal block under `RECONSTRUCTION_CPP CODE`:

```cpp
DDError::DDError(HRESULT result)
    : m_errorCode(result)
{
}
```

- [x] Updated the target notes/score rationale to explain why constructor C++ is now safe and why the score remains below final-audit level pending formatter/header/declaration finalization. The target preserves rejected alternatives for raw `this[1]` / `a2`, raw `sub_4A6260`, `DWORD`, `long`, caller ownership, formatter merge, padding widening, and aggregate emission.
- [x] Synced `by-class/DDError.md` to note that [UID:0002HK] now emits exact constructor C++; kept class-level aggregate C++ blank. Score updated from `86/88` to `88/89`; validator command `000000003906` at `2026-06-27T06:26:28-04:00` exited `0` with `ok:1`.
- [x] Synced `by-file/Error.md` to mark the DDError constructor exact child source-ready and still keep broad `Error.cpp` aggregate C++ blank. Score stayed `87/85`; validator command `000000003907` at `2026-06-27T06:26:35-04:00` exited `0` with `ok:1`.
- [x] Synced `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md` so the DDError constructor row says source-ready exact child with formal constructor C++; aggregate C++ remains blank and score stayed `87/89`. Validator command `000000003919` at `2026-06-27T06:38:01-04:00` exited `0` with `ok:1`.
- [x] Synced `by-type/by-struct/ErrorObjectLayouts.md` so `HRESULT m_errorCode` is recorded as source-ready for [UID:0002HK] while broader stored-status-code family names remain open where still unproven. Score stayed `86/88`; validator command `000000003908` at `2026-06-27T06:27:26-04:00` exited `0` with `ok:1`.
- [x] Synced `by-type/by-vtable/ErrorHierarchyVtables.md` with current MCP session `80de0a67` constructor evidence and source-ready status; score stayed `86/90`; validator command `000000003909` at `2026-06-27T06:27:33-04:00` exited `0` with `ok:1`.
- [x] Synced `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md` with the current constructor/vtable-store evidence; score stayed `87/91`. Validator command `000000003910` at `2026-06-27T06:27:49-04:00` exited `0` with `ok:1`; final rerun command `000000003913` at `2026-06-27T06:28:32-04:00` exited `0` with `ok:1`.
- [x] Left `by-memory/0x00619448-0x00619628.ErrorHierarchyMessageStrings.md` unchanged and made no constructor-only score change there.
- [x] Did not edit generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB by hand. Generated files were refreshed only by validator.
- [x] Ran `python .\tools\validator.py --mode file --file by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md --apply --queue-timeout 240 --wait-generated`: command `000000003897`, timestamp `2026-06-27T06:20:56-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Ran scoped validators with `--apply --queue-timeout 240` for every edited support doc: commands `000000003906`, `000000003907`, `000000003908`, `000000003909`, `000000003910`, `000000003913`, and `000000003919`, all exit `0` with `ok:1`.
- [x] Verified generated refresh without manual patching: `auto-generated/NexusTK/util/Error.cpp`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md` all carry validator-command-id `000000003919`, validator-refreshed-at `2026-06-27T06:38:01-04:00`, and show [UID:0002HK] as coded/emitting through `auto-generated/NexusTK/util/Error.cpp`.
- [x] Supervisor Rule 26 handoff is ready. Agent-B003 did not run supervisor-only `execute_report`; the accepted edits, validators, generated freshness checks, and lease release checks are complete for this implementation callback.

## Implementation Callback Notes

- Changed by-* files: `by-memory/0x004a6260-0x004a6284.DDErrorConstructor.md`, `by-class/DDError.md`, `by-file/Error.md`, `by-memory/0x004a60d0-0x004a6a76.ErrorWrappers.md`, `by-type/by-struct/ErrorObjectLayouts.md`, `by-type/by-vtable/ErrorHierarchyVtables.md`, and `by-memory/0x00619340-0x00619448.ErrorHierarchyVtableData.md`.
- Score/metadata deltas: target `85/89 -> 90/92`; `by-class/DDError.md` `86/88 -> 88/89`; all other edited support docs kept their existing scores. Target owner/emitter metadata remained `CANONICAL_OWNER:00003L`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00003L`, with blank emitter position.
- Lease proof: Agent-B003 leased and released the target. Agent-B003 then leased support docs as they became available, waited through B002/B005 shared Error-doc lease conflicts, rechecked ownership before editing, released explicit leases where still active, and final lease-report review showed no active Agent-B003 leases. B005's unrelated leases were not edited through.
- Validator diagnostics proof: all required scoped validators returned `ok:1` with exit code `0`. Some validators still printed pre-existing stale missing-reference diagnostics for legacy generated/coverage paths or validator-owned reverse mappings; Agent-B003 did not edit validator state, and source text checks confirmed the B003-touched docs use the repaired/current paths.
- MCP proof: live IDA MCP session `80de0a67` remained available during the implementation evidence pass; no fallback-only work was finalized.
- No manual generated edits, manual coverage-report edits, validator/tool-state edits, IDA DB edits, or subagent use occurred.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002HK-DDErrorConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0002HK-DDErrorConstructor-source-quality.md","timestamp":"2026-06-27T08:33:04","uid":"0002HK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
