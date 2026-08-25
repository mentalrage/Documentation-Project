** TARGET-REPORT-UID:000198 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID000198 ApplicationRegisterChangeListener Source-Quality Report


REPORT_UID: 000198
AGENT: Agent-B004
RUNTIME: CHATGPT | 5.5 | xHigh
ASSIGNMENT: implementation callback for accepted source-quality report on `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`
STATUS: READY_FOR_SUPERVISOR_EXECUTE

## Finalized Report / Current Recommendation

UID000198 is a real 0x1c-byte `__thiscall` forwarding wrapper at `0x004f4b30-0x004f4b4c`, but the current `Application::RegisterChangeListener` class-member reconstruction is source-placement stale. Current MCP evidence shows the wrapper is called with mixed owner receivers: three callers pass `g_pBackPane`, and one caller passes `g_pApplication`. That receiver mix is incompatible with a source-literal `Application::RegisterChangeListener` member because the wrapper forwards the incoming `ecx` receiver as ChangeMan's `owner` argument.

Best supported recommendation: keep UID000198 reconstructable, but reclassify it as a source-neutral owner-registration helper emitted through the Application file route `[UID:0000HG]`, not as an Application class method `[UID:00000D]`. Replace the target C++ with a free/helper wrapper that forwards an explicit owner pointer to `g_pChangeMan->Register(...)`. Treat sibling UID00019A as a support risk flag, not as a B004-directed metadata/C++ change: B004 observed same-family adjacency, same-size wrapper shape, and a stale Application-member pattern, but did not complete UID00019A caller-receiver decompilation. Because B007 has the parallel UID00019A report, UID00019A implementation must follow B007's caller-receiver reanalysis; if B007 confirms Application ownership, leave UID00019A Application-owned. Preserve UID000199 as a non-emitting aggregate/index and preserve UID00019B as Application-owned unless fresh evidence contradicts its currently Application-only callers.

## Supporting Research

This report uses the active MCP-backed IDA evidence gathered for UID000198 plus current by-* documentation and read-only generated-output checks. The implementation callback applied accepted facts to the target and scoped support by-* docs listed below, ran scoped file validators, and did not manually edit generated files, validator state, lifecycle files, queues, locks, ledgers, or archives. No `execute_report`, dry-run execute variant, lifecycle/archive command, manual report move, process control command, or `idb_open` was run.

Relevant support documents checked read-only:

- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md` `[UID:000198]`
- `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md` `[UID:00019A]`
- `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md` `[UID:000199]`
- `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md` `[UID:00019B]`
- `by-class/Application.md` `[UID:00000D]`
- `by-file/Application.md` `[UID:0000HG]`
- `by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md` `[UID:0000ZW]`
- `by-global/g_pChangeMan.md`
- `by-global/g_pApplication.md`
- `by-memory/0x0067a740-0x0067a744.g_pBackPane.md`
- `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md` `[UID:000195]`

Read-only generated output currently shows a mismatch: `auto-generated/NexusTK/app/Application.cpp` emits UID000198 as `Application::RegisterChangeListener(...)`, while generated callers in `auto-generated/NexusTK/ui/core/FrameChrome.cpp` and `auto-generated/NexusTK/map/MapPane.cpp` already use helper-style calls with BackPane or local wrapper receivers. Generated output was treated as freshness/context evidence only, not as authority over the source route.

## Target

Target document: `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`

Target UID: `[UID:000198]`

Address range: `0x004f4b30-0x004f4b4c`

Current title: `ApplicationRegisterChangeListener`

Function name in IDA: `sub_4F4B30`

Current callback scope: accepted implementation details applied to UID000198 and scoped support docs only; report is ready for supervisor execution.

## Current Target State

Pre-callback target metadata:

- `COMPLETION:85`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:00000D`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000D`
- blank optional emitter position

Current target formal C++ reconstructs a class method:

```cpp
void Application::RegisterChangeListener(ChangeListener *listener,
                                         unsigned int messageType,
                                         ChangeMessageScope scope)
{
    g_pChangeMan->Register(this, listener, messageType, scope);
}
```

That body is behaviorally close only when the receiver is `g_pApplication`; it is source-placement stale for the three current callsites where the receiver is `g_pBackPane`. The direct-report tracker count of `0` for UID000198 is resolved by this report and does not, by itself, imply bad binary evidence or bad target selection.

Current post-callback target state: UID000198 is now `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, with the blank optional emitter position preserved and formal source-neutral `RegisterChangeListener(void *owner, ...)` helper C++ inserted.

## Heuristic / Inference Reanalysis And Validation

The decisive heuristic issue is not whether UID000198 exists or whether it forwards to ChangeMan; both are strongly proven. The issue is which source route should own a wrapper whose receiver is an arbitrary owner object.

The current class-member route fails the receiver test. A C++ `Application::RegisterChangeListener(...)` member would receive an Application object as `this`; MCP decompilation shows callers pass `g_pBackPane` in three of four direct calls. Those calls are valid for a helper whose first semantic argument is an owner pointer, but not for an Application member reconstruction.

A common LObject/base-class route is plausible because UID000198 sits in the `LObjectRuntimeShell` memory island and the instruction form is a compact `__thiscall` owner-forwarding wrapper. It is not the best current recommendation because the checked documentation does not provide exact target-specific proof that every observed receiver route, including BackPane and Application receivers, is source-declared through the same base method at this wrapper. The prior UID000195 context also treated this island as mixed runtime shell material rather than proving one emitting LObject class owner for every helper in the island.

The best supported route is therefore source-neutral/common helper placement through the Application file route `[UID:0000HG]`. This route preserves the current by-file/generated route for the ChangeMan notification helper family while removing the false Application class-member receiver. It is also compatible with the helper-style generated callsites already present in FrameChrome and MapPane output.

## Evidence Standards Used

Primary evidence standard:

- Current MCP/IDA facts for function boundaries, bytes, disassembly, decompilation, xrefs, callees, and caller decompilation.

Secondary evidence standard:

- Existing by-* documents for accepted ownership, sibling context, global types, and source-route vocabulary.
- Read-only generated output for freshness/mismatch analysis.

Rejected evidence shortcuts:

- Do not rely on the target filename alone as proof of Application class ownership.
- Do not treat generated `Application.cpp` class-member output as authoritative when current caller evidence contradicts it.
- Do not treat tracker direct-report count `0` as negative ownership evidence after current MCP facts identify the function and callers.

## Evidence Checked

MCP session evidence:

- MCP endpoint responded with `ida-pro-mcp 1.0.0` and protocol `2025-06-18`.
- `idb_list` showed active NexusTK database session `2cb2455b`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, not analyzing.
- `server_health(database=2cb2455b)` returned `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, and `hexrays_ready:true`.

Function and range evidence:

- `lookup_funcs` identified `0x004f4b30` as `sub_4F4B30`, size `0x1c`.
- `0x004f4b4c` is not a function, matching the end of UID000198 and the padding before UID00019A.
- Neighbor checks identified `0x004f4b50` as UID00019A, size `0x1c`, and `0x004f4b70` as UID00019B, size `0x16`.

Raw-byte evidence for `0x004f4b20-0x004f4b90`:

```text
55 8b ec 8b 01 ff 50 04 8b c8 5d e9 b0 1d 06 00
55 8b ec ff 75 10 ff 75 0c ff 75 08 51 8b 0d 2c ab 67 00
e8 08 a2 f8 ff 5d c2 0c 00
cc cc cc cc
55 8b ec ff 75 10 ff 75 0c ff 75 08 51 8b 0d 2c ab 67 00
e8 18 a2 f8 ff 5d c2 0c 00
cc cc cc cc
55 8b ec ff 75 08 51 8b 0d 2c ab 67 00
e8 9e a2 f8 ff 5d c2 04 00
cc cc cc cc cc cc cc cc cc cc
```

UID000198 disassembly:

```asm
004f4b30 push ebp
004f4b31 mov ebp, esp
004f4b33 push [ebp+arg_8]
004f4b36 push [ebp+arg_4]
004f4b39 push [ebp+arg_0]
004f4b3c push ecx
004f4b3d mov ecx, dword ptr unk_67AB2C
004f4b43 call sub_47ED50
004f4b48 pop ebp
004f4b49 retn 0Ch
```

UID000198 decompilation:

```cpp
int __thiscall sub_4F4B30(void *this, int a2, int a3, char a4)
{
  return sub_47ED50((_DWORD *)unk_67AB2C, (int)this, a2, a3, a4); /*0x4f4b48*/
}
```

Callee and global evidence:

- `callees(0x004f4b30)` returned exactly one internal callee: `0x0047ed50 sub_47ED50`.
- `xrefs_to(0x0047ed50)` returned the call at `0x004f4b43` from UID000198.
- `xrefs_to(0x0067ab2c)` included UID000198 read `0x004f4b3d`, sibling reads `0x004f4b5d` and `0x004f4b77`, ChangeMan constructor/publish/clear sites, and Application/BackPane cleanup reads.
- `get_bytes(0x0067ab2c, 4)` returned `00 00 00 00`, matching a global pointer storage slot initialized to zero.

Direct caller receiver table:

| Caller address | Caller function | Receiver passed to UID000198 | Listener | Message type | Scope | Source implication |
|---|---|---|---|---|---|---|
| `0x00461275` | `sub_4610F0` | `dword_67A740` / `g_pBackPane` | `this` | `1735356263` / `0x676f6f67` | `0` | BackPane owner, not Application `this` |
| `0x004b74fc` | `sub_4B7480` | `dword_67A740` / `g_pBackPane` | `this` | `1735356263` / `0x676f6f67` | `0` | BackPane owner, not Application `this` |
| `0x005043bb` | `sub_504110` | `dword_67A740` / `g_pBackPane` | `this` | `1735356263` / `0x676f6f67` | `0` | BackPane owner, not Application `this` |
| `0x005c0151` | `sub_5C0110` | `unk_67AB1C` / `g_pApplication` | `this` | `1952805485` / `0x7465726d` | `0` | Application owner for this one caller only |

Return-use evidence:

- Current caller decompilations ignore UID000198's returned `EAX`.
- The source-facing reconstruction should be `void`, even though Hex-Rays renders an `int` because the callee returns a value register.

Generated-output mismatch evidence:

- `auto-generated/NexusTK/app/Application.cpp` currently emits a class-member `Application::RegisterChangeListener(...)`.
- `auto-generated/NexusTK/ui/core/FrameChrome.cpp` currently emits helper-style `RegisterChangeListener(g_pBackPane, this, kFramePartNotificationTag, 0);`.
- `auto-generated/NexusTK/map/MapPane.cpp` currently emits helper/local-wrapper style registration and unregistration calls.

## Positive Evidence Summary

- UID000198 has exact raw bytes, exact function boundary, and exact sibling padding.
- The wrapper pushes three stack arguments plus incoming `ecx`, loads `g_pChangeMan` into `ecx`, and calls `ChangeMan::Register` at `0x0047ed50`.
- `ChangeMan::Register` already has accepted source semantics: `owner`, `listener`, `messageType`, and `scope`.
- All direct callers use UID000198 as a notification registration wrapper.
- Mixed receiver values prove the wrapper's semantic receiver is an owner pointer, not necessarily an Application instance.
- Generated caller output already contains helper-style registrations that are compatible with a source-neutral wrapper.

## Negative Evidence Summary

- There is no current MCP evidence that all UID000198 callers pass an Application object.
- Three direct callers pass `g_pBackPane`, which contradicts the current `Application::RegisterChangeListener` member body.
- The current target title and existing generated `Application.cpp` class-member output are stale relative to current caller receiver evidence.
- LObject/base ownership remains plausible but not proven enough for this report to recommend a class/base method owner.
- ChangeMan ownership is incorrect for UID000198 because the target is a wrapper that calls ChangeMan, not the ChangeMan implementation itself.

## Ranked Ownership Analysis

1. Source-neutral owner-registration helper emitted through `by-file/Application.md` `[UID:0000HG]` - best supported. This route preserves the Application-file ChangeMan notification helper family while expressing the observed owner pointer explicitly and accommodating both `g_pBackPane` and `g_pApplication` receivers.

2. LObject/common base method - plausible but not selected. The memory island and `__thiscall` form support a common wrapper hypothesis, but the current by-* evidence does not prove a single class/base owner for all observed receivers.

3. Application class `[UID:00000D]` - rejected as stale for UID000198. It fits only the `g_pApplication` caller and contradicts the three `g_pBackPane` callers.

4. ChangeMan class `[UID:00001K]` - rejected. UID000198 is a caller-side wrapper around `ChangeMan::Register`, while UID0000ZW owns the ChangeMan implementation.

5. BackPane, AboveFrame, FramePartPane, or MapPane consumer classes - rejected. They are callsite owners/listeners or owner arguments, not the shared wrapper's emitting source route.

6. Non-emitting aggregate/no-code ownership - rejected for UID000198. The function has real reconstructable source behavior and should not be collapsed into UID000199.

## Source Placement

Recommended source placement is a source-neutral/common helper in the Application file route `[UID:0000HG]`, with `CANONICAL_OWNER:0000HG` and `EMITTER_UIDS:0000HG`.

This recommendation deliberately preserves the broader Application/ChangeMan notification helper route without retaining the invalid Application class-member receiver. It also explains the mixed receiver evidence: `g_pBackPane` and `g_pApplication` are compatible because they are explicit owner arguments to a helper, not implicit `Application::this` values.

UID00019A is not an active B004 implementation directive. The exact evidence basis for flagging it is limited to same-family structural evidence: `0x004f4b50` is the adjacent 0x1c-byte unregister sibling, `xrefs_to(0x004f4b50)` shows seven direct callers, it reads the same `g_pChangeMan` storage at `0x004f4b5d`, and current docs use the same Application-member wrapper pattern that proved stale for UID000198. That is enough to require support caution, but not enough to override B007's parallel UID00019A caller-receiver report. Before any UID00019A metadata/C++ change, use B007's caller-receiver reanalysis; if B007's current evidence supports Application ownership, preserve UID00019A as Application-owned and treat B004's note as only sibling-risk context. UID000199 should remain a non-emitting aggregate/index over the pair, with wording updated only as far as accepted UID000198/UID00019A evidence allows. UID00019B can remain Application-owned because its observed direct callers are Application cleanup/shutdown paths and no current evidence shows mixed non-Application receivers for that sibling.

## First-Draft C++ Recommendation

Recommended UID000198 `RECONSTRUCTION_CPP CODE` replacement:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegisterChangeListener(void *owner,
                            ChangeListener *listener,
                            unsigned int messageType,
                            ChangeMessageScope scope)
{
    g_pChangeMan->Register(owner, listener, messageType, scope);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

UID00019A disposition: no B004 formal `RECONSTRUCTION_CPP CODE` replacement is recommended for UID00019A from this report alone. The sibling note is a support-risk flag that must be resolved by B007's UID00019A caller-receiver reanalysis before implementation.

## Final Recommendation

Update UID000198 from an Application class-member wrapper to a source-neutral owner-registration helper emitted by the Application file route. This is the best supported current route because it matches exact MCP caller receivers, preserves the accepted ChangeMan callee semantics, and avoids making `g_pBackPane` pretend to be an Application instance.

The implementation callback should update UID000198 at report-level detail. UID00019A should not be changed from this B004 report alone; any UID00019A metadata/C++ route must follow B007's parallel caller-receiver reanalysis. No generated files should be manually edited.

## Recommended Target Doc Changes

For `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:91` to `CONFIDENCE:90`.
- Change `CANONICAL_OWNER:00000D` to `CANONICAL_OWNER:0000HG`.
- Preserve `RECONSTRUCTABLE:TRUE`.
- Change `EMITTER_UIDS:00000D` to `EMITTER_UIDS:0000HG`.
- Preserve the blank optional emitter position.
- Replace the formal C++ block with the UID000198 helper block in this report.
- Replace stale "application object pointer" wording with "owner/receiver pointer" wording.
- Add the current MCP evidence: healthy MCP session, exact bytes, exact function boundary, disassembly, decompilation, caller receiver table, `g_pChangeMan` xrefs, ChangeMan callee, sibling boundaries, no xrefs to `0x004f4b4c`, and generated-output mismatch.
- Add a queue-resolution note that the direct-report count `0` is resolved by this report and does not imply bad ownership.
- Do not add a manual byte-array reconstruction beyond evidence tables; the target is source-reconstructable as a helper.

## Recommended Support Doc Changes

Recommended support updates during implementation callback:

- `by-memory/0x004f4b50-0x004f4b6c.ApplicationUnregisterChangeListener.md` `[UID:00019A]`: do not update from B004 evidence alone. B004 only flags same-family risk from adjacency, same-size wrapper shape, same `g_pChangeMan` access family, seven direct xrefs, and stale matching Application-member wording. Apply no UID00019A metadata/C++ change unless B007's caller-receiver reanalysis rejects Application ownership; if B007 supports Application ownership, preserve UID00019A and use this report only as UID000198 context.
- `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md` `[UID:000199]`: preserve non-emitting aggregate metadata, but update wording from Application class-wrapper pair to common ChangeMan register/unregister wrapper pair.
- `by-class/Application.md` `[UID:00000D]`: remove or qualify wording that treats UID000198 as an Application class method. For UID00019A, defer to B007's report; preserve Application ownership if B007's caller-receiver evidence supports it. Preserve Application ownership for UID00019B unless new evidence contradicts it.
- `by-file/Application.md` `[UID:0000HG]`: update wording to record that UID000198 is a source-neutral owner helper wrapper routed through the Application file. For UID00019A, follow B007's caller-receiver recommendation rather than this report's sibling-risk flag.
- `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md` `[UID:000195]`: if touched for consistency, describe `0x004f4b30-0x004f4b6c` as common ChangeMan register/unregister helper material, not Application class-member proof.
- ChangeMan and global pointer docs do not require metadata changes. A concise evidence note is optional if stale wording is discovered during implementation.

## Score And Metadata Recommendation

Recommended UID000198 metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000HG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HG`
- blank optional emitter position

Rationale: completion should rise because the function boundary, body, callee, callers, globals, and sibling context are now current and target-specific. Confidence should be corrected from `91` to `90` because the old class-member source placement was overconfident; the source-neutral Application-file route is strongly supported by current evidence but still does not prove an exact original helper declaration name beyond `RegisterChangeListener`.

UID00019A metadata disposition: no B004 metadata change is recommended without B007's caller-receiver reanalysis. If B007 supports Application ownership, preserve UID00019A's Application route. If B007 rejects Application ownership with caller evidence comparable to UID000198's mixed-receiver table, then a later implementation may consider the source-neutral Application-file helper route for UID00019A.

Recommended UID000199 metadata: preserve existing non-emitting aggregate metadata unless implementation discovers a concrete contradiction.

Recommended UID00019B metadata: preserve current Application ownership unless implementation discovers mixed non-Application receivers for `0x004f4b70`.

## Open Questions With Attempted Resolution

Question: Should UID000198 remain an Application class method because one caller passes `g_pApplication`?

Resolution: No. One Application receiver does not outweigh three current `g_pBackPane` receivers. The wrapper's semantics are owner registration, not Application-only registration.

Question: Should UID000198 move to an LObject/base-class route?

Resolution: Not on current evidence. The route is plausible, but this report did not find exact target-specific proof that all observed receivers share a source-declared base wrapper at this address. The safer current correction is source-neutral helper placement through the Application file route.

Question: Does mixed `g_pBackPane` and `g_pApplication` receiver evidence break the Application file route?

Resolution: No. It breaks Application class-member ownership, not Application file placement. A free/helper wrapper emitted through the Application file route can accept either receiver as an explicit `owner` argument.

Question: Does generated `Application.cpp` prove the old class-member route?

Resolution: No. Generated output is stale relative to current MCP caller evidence. It should be refreshed by normal authorized generation/validation after by-* docs are updated, not hand-edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---:|---|---|---|---|
| C01 | UID000198 is an exact 0x1c-byte function at `0x004f4b30-0x004f4b4c`. | High | `lookup_funcs` size `0x1c`; raw bytes show function followed by `cc` padding; `0x004f4b4c` not a function. | UID000198 / Evidence and range notes | incorporate | applied |
| C02 | UID000198 forwards owner, listener, message type, and scope to `ChangeMan::Register`. | High | Disassembly pushes `arg_8`, `arg_4`, `arg_0`, incoming `ecx`, loads `g_pChangeMan`, and calls `0x0047ed50`. | UID000198 / Behavior and C++ block | incorporate | applied |
| C03 | The current `Application::RegisterChangeListener` source route is stale. | High | Direct callers pass `g_pBackPane` in three of four observed calls; class member would require Application receiver. | UID000198 / Status, reconstruction notes, score rationale; Application class/file support | reject-stale | applied |
| C04 | Best current source route is a source-neutral helper emitted through `by-file/Application.md` `[UID:0000HG]`. | Medium-High | Mixed receivers fit explicit owner helper; generated FrameChrome/MapPane callers already use helper-style registrations; Application file owns current notification wrapper family. | UID000198 metadata; by-file/Application.md; by-class/Application.md | incorporate | applied |
| C05 | UID000198 should use a free/helper C++ body with explicit `void *owner`. | High | Hex-Rays decompilation forwards `this` as the second callee argument, and caller receiver table shows arbitrary owner values. | UID000198 / `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C06 | UID00019A has sibling source-placement risk but should not be changed from B004 evidence alone. | Medium | UID00019A is the adjacent same-size unregister wrapper, reads the same ChangeMan global family, has seven direct xrefs, and current docs use the same member-wrapper pattern; B004 did not complete UID00019A caller-receiver decompilation, and B007 owns the parallel UID00019A route decision. | UID000198 sibling note; UID000199, Application class/file support | incorporate | applied |
| C07 | UID000199 should remain non-emitting but should stop implying Application class-member ownership for UID000198. | High | UID000199 is an aggregate/index over UID000198 and UID00019A; no new emitting bytes are recommended, and UID00019A wording must follow B007's evidence. | UID000199 aggregate wording | incorporate | applied |
| C08 | UID00019B can remain Application-owned on current evidence. | Medium | `xrefs_to(0x004f4b70)` shows two Application cleanup/shutdown callers; no mixed receiver evidence was found for UID00019B in this report. | Application support wording | already-present | already-present |
| C09 | Generated `Application.cpp` mismatch was report-time evidence and should refresh through validator/generator flow. | High | Report-time output emitted `Application::RegisterChangeListener`; validator refresh now emits source-neutral `void RegisterChangeListener(void *owner, ...)` for UID000198. | UID000198 generated freshness note; Validator Results | historicalize | applied |
| C10 | Tracker direct-report count `0` is resolved by this report and does not imply bad ownership. | High | Current MCP evidence proves exact target bytes, function, caller list, and callee; tracker row count is a queue signal, not source proof. | UID000198 / Queue-resolution note | incorporate | applied |

## Validator Results

Scoped file validators were run from `source-3/project-documentation` for every edited by-* file:

| File | Command metadata | Exit | Result | Notes |
|---|---|---:|---|---|
| `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md` | `python .\tools\validator.py --mode file --file by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md --apply --queue-timeout 240`; `command_id: 000000007997`; `command_timestamp: 2026-07-08T17:07:19-04:00` | 0 | `ok: 1` | Applied completion/confidence/owner updates, UID link canonicalization, registry/reference updates; `generated_refresh: deferred`. |
| `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md --apply --queue-timeout 240`; `command_id: 000000007998`; `command_timestamp: 2026-07-08T17:07:29-04:00` | 0 | `ok: 1` | `generated_refresh: deferred`. |
| `by-class/Application.md` | `python .\tools\validator.py --mode file --file by-class/Application.md --apply --queue-timeout 240`; `command_id: 000000007999`; `command_timestamp: 2026-07-08T17:07:38-04:00` | 0 | `ok: 1` | `generated_refresh: deferred`. |
| `by-file/Application.md` | `python .\tools\validator.py --mode file --file by-file/Application.md --apply --queue-timeout 240`; `command_id: 000000008000`; `command_timestamp: 2026-07-08T17:07:48-04:00` | 0 | `ok: 1` | Reported two `missing_ref_uid 0003OY` diagnostics already present in this file; `generated_refresh: deferred`. |
| `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md` | `python .\tools\validator.py --mode file --file by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md --apply --queue-timeout 240`; `command_id: 000000008001`; `command_timestamp: 2026-07-08T17:07:58-04:00` | 0 | `ok: 1` | `generated_refresh: deferred`. |

Generated freshness: `auto-generated/NexusTK/app/Application.cpp` header now shows `validator-command-id: 000000008000`, `validator-refreshed-at: 2026-07-08T17:07:48-04:00`, and includes UID000198 as `void RegisterChangeListener(void *owner, ChangeListener *listener, unsigned int messageType, ChangeMessageScope scope)`. Generated files were not manually edited.

## Changed Files

Changed in this callback:

- `tools/leaser/Agents/Agent-B004/research/000198-ApplicationRegisterChangeListener-source-quality.md`
- `by-memory/0x004f4b30-0x004f4b4c.ApplicationRegisterChangeListener.md`
- `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`

Validator-owned side effects reported by scoped validators: generated refresh was deferred for each command; `project-level/-auto-completion-stats.md` projected path completion was updated by validator commands; UID/reference/registry updates were reported for UID000198. No generated files, coverage reports, supervisor ledgers, validator state, queues, locks, archives, lifecycle headers/footers, or unrelated docs were manually edited.

Leases used/released: B004 lease command succeeded for all five edited by-* docs before editing. Cleanup `unlease` command after validators returned `Rejected[No active lease]` for each file; the current lease report then showed no active B004 leases, so the leases were already absent by cleanup time.

## Implementation Tracking Checklist

- [x] UID000198 metadata updated to `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HG`, `EMITTER_UIDS:0000HG`, preserving `RECONSTRUCTABLE:TRUE` and blank optional emitter position.
- [x] UID000198 formal C++ replaced with the source-neutral `RegisterChangeListener(void *owner, ...)` helper block.
- [x] UID000198 prose refreshed with current MCP function boundary, bytes, disassembly/decompilation, caller receiver table, `g_pChangeMan` xrefs, and queue-resolution note.
- [x] UID00019A handled as excluded from B004 metadata/C++ changes with exact reason: B004 only added sibling-risk/defer-to-B007 wording; no UID00019A route change was applied.
- [x] UID000199 aggregate wording reviewed and refreshed so it does not imply Application class-member ownership for UID000198; UID00019A wording follows B007's evidence.
- [x] Application class/file support docs reviewed and corrected so UID000198 is not represented as an Application class method; UID00019A follows B007's caller-receiver recommendation, and UID00019B remains Application-owned on current evidence.
- [x] LObjectRuntimeShell support wording refreshed so the region is helper material, not Application class-member proof.
- [x] Scoped file validators run for every edited by-* file during the implementation callback.
- [x] Generated freshness handled only by authorized validator/generation behavior, not by manual generated-file edits; `auto-generated/NexusTK/app/Application.cpp` refreshed at command `000000008000` and now contains the UID000198 source-neutral helper.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008015","destination_path":"executed-b-agent-research/B004/000198-ApplicationRegisterChangeListener-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000198-ApplicationRegisterChangeListener-source-quality.md","timestamp":"2026-07-08T17:34:39-04:00","uid":"000198"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
