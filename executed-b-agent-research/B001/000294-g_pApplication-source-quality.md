** TARGET-REPORT-UID:000294 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000294 g_pApplication Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:000294] `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` from `86/86` to `90/92`, keep `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000HG`, set `EMITTER_POSITION_OPTIONAL:0`, and add declaration-only first-draft C++ for the Application singleton pointer.
- Final disposition: source-declared four-byte writable `.data` global storage for the process-level `Application` singleton. The best source placement is a module/global definition in `NexusTK/app/Application.cpp`, not a class static member, DirectX-adjacent owner, consumer-owned global, or no-owner/non-emitting item.
- Required action if accepted: update the target and listed support docs at report-level detail, supersede the stale "fresh live IDA MCP was not available" and old `95/95` code-gate wording, add the first-draft declaration, update the supervisor-owned memory coverage row, and run scoped validators for changed by-* docs.
- Confidence: very strong for exact range, zero initial bytes, direct operand route, constructor/destructor writes, Application source placement, and first-draft declaration readiness. Remaining uncertainty is limited to original spelling style for the zero initializer and exact header exposure.

## Target

- Target UID: `000294`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0067ab1c-0x0067ab20.g_pApplication.md`
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\000294-g_pApplication-source-quality.md`
- Assignment: `B001-report-g-p-application-source-quality-000294-mcp-20260623`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Parent/source route: [UID:0000HG] `by-file/Application.md`, currently `86/90`, generated source root `NexusTK/app/`.

## Current Target State

The page already records the correct high-level role: `0x0067ab1c-0x0067ab20` is the `g_pApplication` singleton pointer, constructor-stored, destructor-cleared, broadly consumed, and attached to [UID:0000HG] `Application`.

Stale or incomplete current target claims:

- The page says autogen assignment is justified by an old `80/80 parent gate` and by-file parent score `83/89`. The current parent is `86/90`, and current by-structure code entry uses the combined-score/emitter gate, not the old 80/80 or 95/95 C++ gate.
- The page says the C++ block is blank because the target is below the `95/95 final-source gate`. That policy is superseded.
- The page says confidence stays below 90 because the pass did not obtain fresh live IDA MCP output. This pass did obtain current MCP evidence from session `ff68e691`.
- The layout table calls `Application *g_pApplication;` only a candidate and withholds initializer/linkage decisions. Current evidence supports a first-draft definition, while still documenting `NULL` versus `0` versus implicit zero as not binary-distinguishable.

Support docs checked:

- `by-file/Application.md`
- `by-class/Application.md`
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`
- `by-memory/0x0066d000-0x0069d000.DataSection.md`
- `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`
- `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`
- `by-memory/-coverage-report.md` read-only row check
- Current generated output under `auto-generated/NexusTK/app/Application.cpp` and `auto-generated/NexusTK/app/MiscWorkThread.cpp` as lead material only.

## Supervisor Active Recheck

The supervisor assigned a report-only MCP-backed source-quality pass for [UID:000294]. No by-* docs, generated/project-level files, IDA DB, tool state, or coverage reports may be edited during this pass. IDA MCP was mandatory. Active MCP session `ff68e691` was used.

No split repair is required. The target is exactly one 32-bit pointer slot in `.data`, half-open `0x0067ab1c-0x0067ab20`, with the predecessor `0x0067ab18-0x0067ab1c` ATL runtime flag and successor `0x0067ab20-0x0067ab24` `g_pDirectX` slot remaining separate.

## Inference Research Guidance Check

I treated current docs and old reports as leads and rechecked address, range, bytes, xrefs, and write/read roles with MCP. The source-quality decision separates:

- IDA/MCP facts: segment, zero bytes/value, no-function state, xref counts, function boundaries, disassembly/decompilation lines, and operand byte-pattern counts.
- Documentation evidence: existing Application file/class/lifecycle pages and generated output already use `g_pApplication` as the process singleton and `extern Application* g_pApplication` in at least one consumer source draft.
- Inference: source definition spelling `Application *g_pApplication = NULL;`, non-static module global placement, and header exposure direction.

No Wave2/Wave3 evidence was used as authority. Old reports mentioning `g_pApplication` were used only as context for support-doc claims and stale assumptions.

## Evidence Standards Used

Evidence types used:

- IDA MCP `server_health`, `idb_list`, `survey_binary`, `lookup_funcs`, `get_bytes`, `get_global_value`, `entity_query`, `xrefs_to`, `xref_query`, `find_bytes`, `disasm`, and `decompile`.
- Exact disassembly/decompilation for the constructor write, destructor clear, and `GetApplicationSingleton` accessor.
- Representative consumer disassembly for ScreenPane DirectDraw restore, raw Surface copy helper, and `SendPositionUpdate`.
- Current by-* target/support docs and current generated source output.
- Negative route checks: no function at data addresses, no named global entity exposed by current MCP at the slot, no RVA-pattern hits, distinct adjacent `g_pDirectX` xrefs, consumer-only read routes rejected as owners.

MCP limitation: the available tool schema did not expose a PE relocation-table query. I therefore do not claim relocation-table proof. The current claim is narrower: initial slot bytes/value are zero, the slot is referenced by absolute VA operands in code, and no RVA byte-pattern hits were found by MCP `find_bytes`.

## Evidence Checked

MCP session/provenance:

- `idb_list`: session `ff68e691`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker, analysis not running.
- `server_health`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis and Hex-Rays ready.
- `survey_binary detail_level=minimal`: `.data` segment `0x0066d000-0x0069d000`, size `0x30000`, permissions `rw`; `.text` `0x00401000-0x0060d000`.

Address/range and bytes:

- `lookup_funcs` returned `Not a function` for `0x0067ab18`, `0x0067ab1c`, `0x0067ab20`, and `0x0067ab24`.
- `get_bytes` for `0x0067ab18` size `16` returned sixteen zero bytes. `get_bytes` for `0x0067ab1c` size `4` returned `00 00 00 00`. `get_bytes` for `0x0067ab20` size `4` also returned `00 00 00 00`.
- `get_global_value` returned `0x0` for `unk_67AB1C`, `dword_67AB1C`, `0x0067ab1c`, `unk_67AB20`, `dword_67AB20`, and `0x0067ab20`.
- `entity_query` for names/globals in `0x0067ab18-0x0067ab28` returned no named entities, while disassembly refs still render IDA labels such as `unk_67AB1C` / `unk_67AB20`.
- Boundary xrefs: `0x0067ab18` has one data xref at `0x005c8b53` in `sub_5C8B0B`; `0x0067ab1c` has 140 xrefs; `0x0067ab20` has 19 xrefs; `0x0067ab24` has 52 xrefs. This supports the exact half-open child boundaries and rejects merging adjacent slots.

Pointer/immediate routes:

- `find_bytes` for VA little-endian `1C AB 67 00` returned `140` matches, matching the `g_pApplication` xref count.
- `find_bytes` for VA little-endian `20 AB 67 00` returned `19` matches, matching the adjacent `g_pDirectX` xref count.
- `find_bytes` for RVA-style `1C AB 27 00` and `20 AB 27 00` returned `0` matches.
- A broad `search_text dword_67AB1C` request timed out once after the byte-pattern query had already succeeded. `server_health` immediately afterward was `ok`; the report therefore uses `xref_query`, `find_bytes`, and targeted `disasm` instead of the slow broad text query.

Writer/accessor evidence:

- `lookup_funcs 0x00463310`: `Application__Constructor`, size `0x65e`.
- Constructor disassembly: `0x00463368 mov dword ptr unk_67AB1C, eax`; null fallback `0x0046336f mov dword ptr unk_67AB1C, 0`.
- Constructor decompilation: after `sub_4F4A80`, if the adjusted object pointer is not the null/fallback value, `unk_67AB1C = (int)this; /*0x463368*/`; otherwise `unk_67AB1C = 0; /*0x46336f*/`.
- `lookup_funcs 0x00463970`: `sub_463970`, size `0x54`.
- Destructor disassembly: `0x004639b4 mov dword ptr unk_67AB1C, 0`.
- Destructor decompilation: after vtable restore, handle close/clear, string releases, and embedded `MSGHandler` destruction, `unk_67AB1C = 0; /*0x4639b4*/`, then base cleanup `sub_4F4A90`.
- `lookup_funcs 0x004673e0`: `sub_4673E0`, size `0x6`.
- Singleton accessor disassembly: `0x004673e0 mov eax, dword ptr unk_67AB1C`.
- Singleton accessor decompilation: `int sub_4673E0() { return unk_67AB1C; }`.

Representative consumer evidence:

- `xref_query 0x0067ab1c` total `140` xrefs grouped across Application lifecycle/startup, Baram activation/deactivation, browser/window/input, MSGHandler, render/surface, packet/session, server select, music/misc worker, and other app-state consumers. The largest grouped function in the MCP list is `0x00465f20` with eight refs; constructor has two refs; destructor has one; `SendPositionUpdate` has three.
- ScreenPane DirectDraw restore `0x005576a0` reads `g_pDirectX` at `0x005576d0`, reads `g_pApplication` at `0x0055770b`, and calls `0x004651d0` / `ApplicationGetMainWindowHandle`. This is dependency evidence only; the owner remains ScreenPane for that method and Application for this global.
- Raw Surface copy helper `0x00559a10` is not modeled as a function by MCP but disassembly at that address shows `0x00559a23 mov eax, dword ptr unk_67AB1C` and `0x00559a63 mov eax, dword ptr unk_67AB20`. This confirms distinct Application and DirectX dependency slots inside the raw helper.
- `SendPositionUpdate` `0x00574d40` reads `g_pApplication` at `0x00574d74`, `0x00574d98`, and `0x00574db1`, then calls version accessors `0x00465300` and `0x00465310` before queuing/sending packet data.
- Generated `auto-generated/NexusTK/app/MiscWorkThread.cpp` already contains `extern Application* g_pApplication;` and uses `g_pApplication->GetWindowHandle()` in browse-directory code. This confirms current generated consumers assume a definition elsewhere.

## IDA MCP Facts

| Item | MCP fact | Source-quality impact |
| --- | --- | --- |
| `.data` section | `0x0066d000-0x0069d000`, permissions `rw` | The slot is writable global storage, not code or read-only table data. |
| Target range | `0x0067ab1c-0x0067ab20`, four zero bytes | Source-declared zero-initialized pointer storage. |
| Adjacent predecessor | `0x0067ab18`, one xref, old docs identify ATL base-module flag | Boundary before target is exact; do not merge. |
| Adjacent successor | `0x0067ab20`, 19 xrefs, DirectX slot | Boundary after target is exact; do not merge with DirectX. |
| Current IDA label | refs render `unk_67AB1C`, not original symbol | `g_pApplication` is source-facing inferred/project canonical, not proven by IDA symbol metadata. |
| Constructor write | `0x00463368` stores `this`, `0x0046336f` stores zero fallback | First writer/lifetime owner is Application construction. |
| Destructor clear | `0x004639b4` stores zero | Teardown owner is Application destruction. |
| Accessor | `0x004673e0-0x004673e6` returns slot | Application file already owns helper exposing the singleton. |
| Direct xrefs | 140 to target, 19 to successor | Broad consumers do not change ownership; successor is separate DirectX global. |
| VA/RVA bytes | 140 VA operand matches for target, 0 RVA matches | Direct code operands account for all currently observed route hits. |

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct owner | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0067ab1c-0x0067ab20` | [UID:000294] target | `Application *g_pApplication` storage | TRUE | [UID:0000HG] Application file | current `86/86`, recommended `90/92` | Source-ready declaration-only global. |
| `0x00463310-0x0046396e` | [UID:0002GY] ApplicationConstructor | first writes target with `this`/zero fallback | TRUE | [UID:00000D] Application class | `86/91` | Support doc already has constructor phase; add current target-specific MCP note if accepted. |
| `0x00463970-0x004639c4` | [UID:0002GZ] ApplicationDestructor | clears target during teardown | TRUE | [UID:00000D] Application class | `88/91` | Support doc already has exact clear; replace old 95/95 no-code wording if touched. |
| `0x004673e0-0x004673e6` | [UID:00032B] GetApplicationSingleton | returns target | TRUE | [UID:0000HG] Application file | current docs identify it | Confirms Application-file route. |
| `0x0067ab20-0x0067ab24` | [UID:000295] g_pDirectX | adjacent DirectX singleton slot | TRUE | [UID:0000QS] g_pDirectX | `86/88` | Boundary support; current MCP zero bytes conflict with old support note saying `0xffffffff`. |

## Direct Xref / Caller Inventory

Current MCP `xref_query` to `0x0067ab1c` returned `140` total xrefs. Representative grouped function routes:

| Function / route | Xref addresses | Meaning |
| --- | --- | --- |
| `Application__Constructor` `0x00463310` | `0x00463368`, `0x0046336f` | Constructor publishes active singleton or zero fallback. |
| `Application` destructor body `0x00463970` | `0x004639b4` | Clears singleton after subobject/string cleanup. |
| Application startup/lifecycle `0x00465f20` | `0x00465f4e`, `0x00465fc1`, `0x004662b1`, `0x004662d1`, `0x004662db`, `0x00466417`, `0x00466466`, `0x00466620` | Application lifecycle/startup consumer cluster, not a separate global owner. |
| `BaramApp::OnActivate` / `OnDeactivate` modeled functions | `0x004669f0`, `0x00466a07`, `0x00466a96`, `0x00466aa4` | Activation state writes/read via Application object; still Application-owned state. |
| `GetApplicationSingleton` `0x004673e0` | `0x004673e0` | File-local/global accessor returns the slot. |
| ScreenPane restore `0x005576a0` | `0x0055770b` | Reads Application to get main HWND for DirectDraw cooperative-level restore. |
| Raw Surface copy helper `0x00559a10` | `0x00559a23` | Render/surface dependency on Application, paired with `g_pDirectX` read. |
| `SendPositionUpdate` `0x00574d40` | `0x00574d74`, `0x00574d98`, `0x00574db1` | Packet-state consumer of Application version accessors. |
| Misc worker `StartAddress` `0x00596af0` | `0x00596b70` | Worker/background consumer route; generated `MiscWorkThread.cpp` already declares `extern Application* g_pApplication`. |

The full xref set was not semantically named one by one because the target question is storage ownership/source declaration, not every consumer's implementation. The grouped count and representative routes are enough to prove broad external readers while the write/accessor set proves Application ownership.

## Positive Evidence Summary

- The target is exactly one 32-bit writable global slot in `.data`; current bytes/value are zero.
- MCP confirms no function at the target or adjacent data addresses.
- Constructor and destructor write set is Application-owned and direct: publish at `0x00463368`, fallback zero at `0x0046336f`, teardown zero at `0x004639b4`.
- The Application-owned accessor at `0x004673e0` returns the slot.
- 140 direct VA operand matches/xrefs prove the global is not dead or padding.
- Current support docs and generated consumers already use `g_pApplication` as the canonical source-facing name.
- Application file [UID:0000HG] is a valid source root at `86/90`; the target already has nonblank emitter `0000HG` and is reconstructable. Current code-entry policy is satisfied if the source-quality name/source placement is strong enough.
- The recommended declaration is behaviorally exact: static storage starts zero, constructor publishes `this`, destructor clears it, and all consumers load the same pointer.

## Negative / Counter-Evidence Summary

- No original PDB/source symbol proves the exact spelling `g_pApplication`; current IDA label is `unk_67AB1C`. The name is still the best source-facing project canonical because all Application support docs and generated consumers use it consistently.
- `NULL`, `0`, and an omitted static initializer are not distinguishable from zero bytes alone. `Application *g_pApplication = NULL;` is recommended because old target history used `NULL`, generated `Application.cpp` uses `NULL` for pointer locals, and late-1990s/early-2000s Windows C++ commonly used `NULL`. This is source-quality inference, not original-token proof.
- The exact header exposure is not recovered. Cross-file consumers require an `extern Application *g_pApplication;` declaration somewhere, and current generated `MiscWorkThread.cpp` already uses one, but the four-byte storage target should emit only the single definition.
- A class-owned static member is not supported: the slot is a free absolute global with broad external consumers and no evidence of an `Application::s_*` static member declaration.
- A DirectX-adjacent owner is rejected: successor `0x0067ab20` has a separate 19-xref DirectX lifetime/consumer set, while `0x0067ab1c` has the 140-xref Application set and Application constructor/destructor writers.
- Consumer-owned placement is rejected: render, packet, worker, browser, and ServerSelect paths read the pointer but do not own its lifetime.
- No-owner/non-emitting is rejected: source-owned global storage and a valid Application emitter are both proven.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| `0x0067ab1c-0x0067ab20` is `g_pApplication` storage | Very strong | zero `.data` slot, 140 xrefs, constructor/destructor writes, Application accessor, support docs | no original symbol; current IDA label is `unk_67AB1C` | No blocker; name is project-canonical/inferred. |
| Source owner/emitter should remain `Application.cpp` / [UID:0000HG] | Very strong | Application constructor first writer, destructor clear, Application accessor, by-file source root | by-class, DirectX adjacency, consumer-owned, no-owner alternatives rejected | No blocker; no separate by-global page required for this pass. |
| First-draft C++ should be emitted | Strong | current combined-score/emitter gate clears after score raise; declaration-only global exactly represents storage | initializer/header exposure not original-proof | Emit definition only; document initializer/header caveat. |
| `Application *g_pApplication = NULL;` is the best first-draft line | Strong | zero initial value; old target history used `NULL`; generated `Application.cpp` pointer locals use `NULL`; mid-2000s style | `= 0`, `nullptr`, or implicit zero cannot be ruled out by bytes | Use as first draft, keep exact initializer style below final-audit proof. |
| Adjacent `g_pDirectX` remains separate | Very strong | target xrefs 140 vs successor xrefs 19; separate DirectX writer/consumer set; exact boundary xrefs | old g_pDirectX support doc says `0xffffffff` but current bytes read zero | Recommend support-doc correction for initializer mismatch. |

## Heuristic / Inference Reanalysis And Validation

Source-facing name:

- `g_pApplication` should remain the canonical source-facing name. It is not original-symbol proof, but it is already the stable name across Application, MSGHandler, Surface, ServerSelect, worker, and generated-source docs. Reverting to `unk_67AB1C` or `dword_67AB1C` would violate the source-quality mandate.

Type:

- `Application *` is the right source type. The constructor stores the current Application object pointer, `Application` methods are called through the loaded value, and generated consumers invoke Application methods. There is no evidence for a base-class pointer, `void *`, or integer global in source.

Initializer:

- Current MCP proves zero static storage. It does not prove whether the original source wrote `= NULL`, `= 0`, or left the initializer implicit. The best first-draft source is `Application *g_pApplication = NULL;` because the target itself historically emitted `Application* g_pApplication = NULL;`, current generated Application source uses `NULL` for pointer locals, and older Windows C++ style makes `NULL` plausible. This remains an inferred style choice.

Linkage and header exposure:

- The definition should not be `static`: the global is used across multiple subsystem source families, and current generated `MiscWorkThread.cpp` already contains `extern Application* g_pApplication;`.
- The exact original header is not proven. Best current direction is a single definition in `Application.cpp` plus an extern declaration in `Application.h` or an app-global header. This does not block the storage page from emitting the definition.

Emitter ordering:

- Set `EMITTER_POSITION_OPTIONAL:0` so the declaration appears before Application method bodies in generated `Application.cpp`. Existing declaration/data pages use position `0` when downstream helper bodies depend on them.

Generated-output pollution:

- Adding only the global definition does not force the overbroad constructor/destructor bodies into C++. It is a declaration-only storage item and is separate from the still-blank large Application constructor/destructor pages.

## Ownership / Source-Placement Alternatives

| Rank | Candidate | Decision | Evidence for | Evidence against / reason rejected |
| ---: | --- | --- | --- | --- |
| 1 | Application module global in [UID:0000HG] `by-file/Application.md` | Accepted | Constructor publishes, destructor clears, Application-owned accessor returns it, broad consumers need an external singleton, file root is valid `NexusTK/app/` route | Exact header exposure not proven, but definition belongs in the Application module. |
| 2 | New `by-global/g_pApplication.md` semantic page | Not required for this pass | by-structure often uses by-global for process globals; could be useful as an index later | Creating a new page now is churn; the exact storage page can emit the single definition through Application.cpp, and no by-global page currently exists. If created later, it should avoid duplicate C++ emission. |
| 3 | [UID:00000D] `by-class/Application.md` class-owned static | Rejected as direct canonical owner for this storage | The pointer type is Application and lifecycle writes are in class methods | Binary uses absolute global storage and generated consumers use `extern`; no evidence of an `Application::s_*` class static member. Keep class as type/context owner, not canonical storage owner. |
| 4 | DirectX / adjacent global route | Rejected | Physical successor is `g_pDirectX` | Separate address, xref count, writer set, and consumer set. Current target is Application-owned. |
| 5 | Consumer-owned routes such as ScreenPane, Surface, SendPositionUpdate, MiscWorkThread, ServerSelect | Rejected | These readers demonstrate broad use | They read or call through the singleton but do not publish or clear it. Consumer evidence cannot move ownership away from Application. |
| 6 | `CANONICAL_OWNER:NONE`, blank emitters | Rejected | Would avoid unresolved header-style choice | Too weak: source-owned storage, Application write set, valid emitter, and source declaration are all established. |

## Range / Split / Padding / Reclassification Analysis

No split or merge is recommended.

- Target half-open range stays `0x0067ab1c-0x0067ab20`.
- Predecessor `0x0067ab18-0x0067ab1c` remains the ignored ATL base-module flag range; current MCP found one xref to `0x0067ab18`.
- Successor `0x0067ab20-0x0067ab24` remains the separate `g_pDirectX` slot; current MCP found 19 xrefs and zero initial bytes.
- The following `0x0067ab24` slot remains a separate FontImageLib/global consumer region with 52 xrefs.
- `find_bytes` confirms the target and successor VA operand routes are distinct: 140 matches for `1C AB 67 00` and 19 matches for `20 AB 67 00`.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are recommended during this report-only pass.

If an IDA-side rename is later authorized by the supervisor, `unk_67AB1C` / `dword_67AB1C` should be renamed to `g_pApplication` and typed as `Application *`. That is not required to implement the by-* report and should not be done by B001 without explicit IDA DB permission.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The page is reconstructable, has a nonblank emitter route to [UID:0000HG], clears the current combined-score gate after the recommended score update, and represents a declaration-only storage item with exact bytes/range/lifetime evidence.
- Recommended code:

```cpp
class Application;

Application *g_pApplication = NULL;
```

- Reason it preserves exact behavior: static global pointer storage starts as zero; constructor publishes the active Application object; destructor clears it; consumers load the same storage. The declaration emits one four-byte pointer definition in the Application module.
- Reason it matches plausible original source shape: a process-level Windows C++ application singleton commonly appears as a module global in the application source file, with external declarations for consumers. `NULL` is consistent with current generated `Application.cpp` pointer style and the old target history.
- Names/types used instead of IDA labels: `Application *g_pApplication` replaces `unk_67AB1C` / `dword_67AB1C`.
- Remaining style caveat: `= NULL`, `= 0`, and implicit zero are binary-equivalent. The report recommends `NULL` as the best first draft, not as original-token proof.

## Score And Metadata Recommendation

Current metadata:

- `COMPLETION:86`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000HG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HG`
- blank `EMITTER_POSITION_OPTIONAL`
- blank `RECONSTRUCTION_CPP CODE`

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000HG` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000HG` unchanged
- `EMITTER_POSITION_OPTIONAL:0`
- formal C++ block populated with the declaration above.

Score rationale:

- Completion should rise to `90` because the previous live-MCP and final-C++ blockers are closed for this storage item: the report records current bytes/value, exact half-open boundaries, no-function state, xref count, VA/RVA byte route checks, constructor/destructor/accessor disassembly/decompilation, representative consumers, ownership alternatives, source declaration shape, and target/support edit plan.
- Confidence should rise to `92` because independent MCP routes agree with existing docs: bytes, xrefs, writer set, accessor, generated extern use, and Application source root all align. It should not reach `95+` because the exact original initializer token, exact header exposure, and all 140 consumer semantics are not final-audit complete.

## Open Questions With Attempted Resolution

- Exact initializer style: unresolved at original-token level. Current bytes prove zero; `NULL`, `0`, and implicit zero are equivalent. Recommended first draft uses `NULL`.
- Exact header exposure: unresolved. Consumers need an extern declaration, and generated `MiscWorkThread.cpp` already has one. The storage target should emit only the definition; header placement can be handled by Application support/source-layout work.
- Whether to create `by-global/g_pApplication.md`: not needed for this pass. A future by-global semantic index could be useful, but it must not duplicate the emitted definition. Current by-file owner/emitter is sufficient and less disruptive.
- Adjacent `g_pDirectX` initializer mismatch: current MCP reads zero, while the adjacent page says an old pass saw `0xffffffff`. This report recommends a narrow support-doc correction if accepted.

## Recommended Target Doc Changes

Target path: `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`

Required changes if accepted:

- Update metadata to `COMPLETION:90`, `CONFIDENCE:92`, keep `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, set `EMITTER_POSITION_OPTIONAL:0`.
- Populate the formal C++ block:

```cpp
class Application;

Application *g_pApplication = NULL;
```

- Replace old autogen/source gate text:
  - remove or supersede the old `80/80 parent gate`, stale parent `83/89`, and `95/95 final-source gate` language;
  - state current policy: the target is reconstructable, has a valid Application emitter, and the recommended `90/92` score clears the current combined-score code gate.
- Replace the no-live-MCP score rationale with current MCP session `ff68e691` evidence.
- Add a current evidence section with:
  - `.data` range and zero bytes/value for `0x0067ab1c`;
  - no function at `0x0067ab18`, `0x0067ab1c`, `0x0067ab20`, `0x0067ab24`;
  - constructor writes `0x00463368` / `0x0046336f`;
  - destructor clear `0x004639b4`;
  - `GetApplicationSingleton` `0x004673e0`;
  - 140 direct xrefs and 140 `1C AB 67 00` VA matches, zero `1C AB 27 00` RVA matches;
  - exact adjacent boundaries and distinct successor `g_pDirectX` xref set;
  - representative render/packet/worker/ServerSelect consumers.
- Preserve the historical 2026-06-05 note but mark the old 95/95/no-live-MCP rationale as superseded by the 2026-06-23 MCP-backed pass.
- Keep the `Application+0x858` current-server-name field note; it remains valid consumer/field evidence and does not move ownership.

## Recommended Support Doc Changes

Support path: `by-file/Application.md`

- Add a source-quality note that [UID:000294] is now MCP-backed and source-ready as the Application module global definition:

```cpp
class Application;

Application *g_pApplication = NULL;
```

- Record session `ff68e691` facts: zero bytes/value, constructor publish/fallback zero, destructor clear, `0x004673e0` accessor, 140 xrefs, and broad consumers.
- Clarify that the global is a module-level Application singleton definition in `Application.cpp`; class [UID:00000D] provides the type and lifecycle methods but the storage is not a class static member.
- Mention exact header exposure remains inferred; consumers such as `MiscWorkThread.cpp` need `extern Application *g_pApplication`.

Support path: `by-class/Application.md`

- Add or strengthen the `Fields And Globals` note for `g_pApplication`: exact storage [UID:000294], zero-initialized `.data`, constructor/destructor writer sites, and source-facing module global definition.
- Clarify that `Application` owns lifecycle writes and object type, but canonical storage ownership/emission remains with [UID:0000HG] `Application.cpp`, not a class static.

Support path: `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`

- Add a concise current-target support note that `g_pApplication` [UID:000294] is now MCP-backed by session `ff68e691` and source-ready as a declaration-only Application module global.
- Do not add aggregate C++; this support update only records the exact global declaration dependency.
- If touching nearby old `95/95` wording, replace it only where directly connected to the target/global declaration or clearly mark it historical. Larger lifecycle no-code blockers still stand on source-quality grounds, not old policy.

Support path: `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`

- Add current MCP proof for [UID:000294]: `0x00463368 mov dword ptr unk_67AB1C, eax`, fallback `0x0046336f mov dword ptr unk_67AB1C, 0`, decompiler `unk_67AB1C = (int)this`.
- Preserve that constructor formal C++ remains blank due larger method rewrite blockers; the global declaration readiness does not make constructor body C++ ready.

Support path: `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`

- Add current MCP proof for [UID:000294]: `0x004639b4 mov dword ptr unk_67AB1C, 0`, decompiler `unk_67AB1C = 0`.
- Replace the stale phrase "below the 95/95 final-source gate" with current no-code rationale for the destructor body: final member names, class declaration layout, `MSGHandler` embedding, and destructor factoring remain source-quality blockers despite the minimum code gate.

Support path: `by-memory/0x0066d000-0x0069d000.DataSection.md`

- Add a child-work/support note that [UID:000294] has current session `ff68e691` evidence, zero bytes, source-ready `Application *g_pApplication = NULL;`, and exact predecessor/successor boundaries.
- Preserve this page as a non-emitting section container.

Support path: `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`

- Narrow correction recommended because current MCP directly contradicts an adjacent-boundary fact used by this report: replace/supersede the old `0xffffffff` initializer statement with current session `ff68e691` result `00 00 00 00` / `0x0` for `0x0067ab20`.
- Preserve DirectX ownership, xref count `19`, and separate successor/predecessor boundaries. Mark the old `0xffffffff` read as historical/stale unless another current MCP check proves otherwise.

Support path: `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`

- No required change. Current generated/support C++ already contains `extern Application* g_pApplication;`, which is sufficient consumer evidence. If touched later, style may be synchronized to `extern Application *g_pApplication;`, but that is cosmetic and not required.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the existing [UID:000294] row under the `.data` block between the `0x0067ab18-0x0067ab1c` ignored ATL flag row and [UID:000295] `g_pDirectX`.

Exact replacement row:

```text
        - [UID:000294][0x0067ab1c-0x0067ab20.g_pApplication](by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md) 0x0067ab1c-0x0067ab20 | global pointer | g_pApplication : reconstructable : 90% : very-strong : B001 2026-06-23 MCP session ff68e691 confirms this exact four-byte zero-initialized `.data` Application singleton slot, with no function at the data address, predecessor `0x0067ab18` ATL flag and successor `0x0067ab20` g_pDirectX boundaries kept separate, 140 direct xrefs and 140 `1C AB 67 00` VA operand hits with zero RVA-pattern hits, constructor publish/fallback writes at `0x00463368`/`0x0046336f`, destructor clear at `0x004639b4`, Application-owned accessor `0x004673e0`, broad window/input/render/timer/packet/ServerSelect/worker consumers, Application-file owner/emitter [UID:0000HG], and first-draft `Application *g_pApplication = NULL;` declaration readiness.
```

Reason B001 must not apply it directly: B-agent report-only pass; all `-coverage-report.md` files are supervisor-owned unless explicitly overridden.

## Validators Expected After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc. Expected commands if all recommended non-coverage docs are changed:

> Executable block R001 was removed from this report and preserved verbatim in [000294-g_pApplication-source-quality-removed.md](000294-g_pApplication-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor narrows callback scope, run only the validators for docs actually changed. Do not run a validator on `by-memory/-coverage-report.md` from B001 unless explicitly authorized.

## Final Recommendation

- Raise target from `86/86` to `90/92`.
- Keep owner/emitter/reconstructable: `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`.
- Set `EMITTER_POSITION_OPTIONAL:0`.
- Add first-draft declaration-only C++:

```cpp
class Application;

Application *g_pApplication = NULL;
```

- Do not split or rename the target file.
- Do not create a new by-global page in this pass.
- Apply exact support-doc updates above if supervisor accepts the report.
- Supervisor should update the coverage row after implementation verification.

## Confidence

- Recommendation confidence: very strong.
- Score confidence: strong for `90/92`; not higher because exact initializer token, original header exposure, and every one of the 140 consumers are not final-audit complete.
- Remaining uncertainty: source spelling/style only, not behavior or ownership.

## Validator Results

- Commands run: none. This was report-only research and no by-* docs were edited.
- Results: not applicable.
- MCP timeout note: one broad `search_text dword_67AB1C` request timed out once. MCP health immediately afterward was `ok`; narrower MCP evidence succeeded and is used in this report.

## Changed Files

Report-only pass:

- Created: `tools/leaser/Agents/Agent-B001/research/000294-g_pApplication-source-quality.md`.
- Modified during report-only pass: none outside this report.
- Renamed: none.
- Moved to executed: none.

Implementation callback pass:

- Modified target/support docs:
  - `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`
  - `by-file/Application.md`
  - `by-class/Application.md`
  - `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
  - `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
  - `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`
  - `by-memory/0x0066d000-0x0069d000.DataSection.md`
  - `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`
- Validator/autogen side effects from scoped `--apply` file validators:
  - `auto-generated/NexusTK/app/Application.cpp`
  - `auto-generated/-ag-file-coverage.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
  - `tools/validator.ini`
- Inspected but not edited by this B001 callback: `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md`. Proof lines already sufficient: `extern Application* g_pApplication;` and `browseInfo.hwndOwner = g_pApplication->GetWindowHandle();`.
- `*-coverage-report.md` files edited by this B001 callback: none. Final status still shows unrelated dirty supervisor-owned coverage-report entries in the worktree; they were not edited, validated, or applied by this pass. Supervisor-owned coverage text remains supplied in this report for supervisor application.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: current Agent-B001 `goal.md` assigns implementation callback `B001-implement-g-p-application-source-quality-000294-mcp-20260623` for accepted [UID:000294].
- [x] Target doc `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md` updated with current implementation MCP refresh `80de0a67` evidence, accepted report provenance `ff68e691`, stale no-MCP/95-gate supersession, first-draft declaration C++, score `90/92`, and `EMITTER_POSITION_OPTIONAL:0`.
- [x] Support doc `by-file/Application.md` updated with module-global source placement, current MCP write/read evidence, declaration readiness, and non-static/header-exposure caveat.
- [x] Support doc `by-class/Application.md` updated with exact storage/lifecycle writer note and class-static rejection.
- [x] Support doc `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` updated with target-specific source-ready global support note.
- [x] Support doc `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` updated with current constructor write/fallback proof for [UID:000294].
- [x] Support doc `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md` updated with current destructor clear proof for [UID:000294]; formal destructor C++ remains blank and no unrelated destructor blockers were changed.
- [x] Support doc `by-memory/0x0066d000-0x0069d000.DataSection.md` updated with child work/support note for current zero bytes, exact boundaries, and source-ready declaration.
- [x] Support doc `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md` corrected/superseded stale `0xffffffff` initializer wording with current `00 00 00 00` / `0x0` result while preserving DirectX ownership.
- [x] Confirmed `by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md` is already sufficient. Proof: page has `extern Application* g_pApplication;` and uses `g_pApplication->GetWindowHandle()` for `browseInfo.hwndOwner`; no stale contradiction was found, so it was not edited by this callback.
- [x] Metadata/score changes applied: target is `COMPLETION:90`, `CONFIDENCE:92`; owner/emitter/reconstructable retained; `EMITTER_POSITION_OPTIONAL:0` set.
- [x] Owner/emitter/reconstructable changes applied: no route change; kept Application file route with `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`.
- [x] Split/rename/new-child changes applied: none; split, rename, and new by-global page creation rejected.
- [x] Source-placement/range/padding/reclassification changes applied: exact half-open range `0x0067ab1c-0x0067ab20` preserved; predecessor `0x0067ab18`, successor `g_pDirectX` at `0x0067ab20`, and `0x0067ab24` successor separation recorded.
- [x] First-draft C++ applied: `class Application;` plus `Application *g_pApplication = NULL;`.
- [x] Exact target/support facts incorporated at report-level detail: zero bytes/value, no-function state, 140 xrefs, byte-pattern route checks, constructor/destructor/accessor disassembly/decompilation, representative consumers, rejected alternatives, initializer/header caveat, and adjacent `g_pDirectX` mismatch.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old no-live-MCP pass, old 95/95 gate, old `g_pDirectX` `0xffffffff` note as stale/historical, class-static/DirectX/consumer/no-owner rejections, and no original-symbol proof.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: no current Wave2/Wave3 evidence used as authority; generated output used only as lead/context.
- [x] Open questions closed or documented as evidence-backed unresolved: initializer spelling and header exposure remain unresolved but non-blocking; by-global page creation remains not required.
- [x] Validators run: scoped file validators for every changed by-* doc listed in "Validators Expected After Implementation"; no `*-coverage-report.md` validator/edit was performed by B001.
- [x] Supervisor-owned coverage-report/tracker text to apply: exact [UID:000294] replacement row remains supplied above and unchanged for supervisor-owned application.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: proof is current Agent-B001 assignment for [UID:000294] `g_pApplication`.
- [x] Current MCP evidence refreshed through required session `80de0a67`: `idb_list`/`server_health` confirmed active `NexusTK.exe.i64`, `.data` `0x0066d000-0x0069d000`, target bytes/value `00 00 00 00` / `0x0`, no function at `0x0067ab18`, `0x0067ab1c`, `0x0067ab20`, or `0x0067ab24`, 140 target xrefs/VA operand hits, zero target RVA-pattern hits, constructor stores at `0x00463368`/`0x0046336f`, destructor clear at `0x004639b4`, accessor `0x004673e0`, and adjacent `g_pDirectX` zero-value check.
- [x] All accepted target/support doc details incorporated at report-level detail: target doc and seven support docs updated; MiscWorkThread checked and left as sufficient.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: `86/86 -> 90/92`, owner/emitter/reconstructable unchanged, `EMITTER_POSITION_OPTIONAL:0`, declaration C++ applied, no split/rename/new by-global.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: accepted-report provenance `ff68e691` retained where relevant; current implementation evidence names `80de0a67`; stale `0xffffffff` DirectX initializer marked historical until reproduced by a current pass.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: exact initializer token and header exposure remain inferred/non-blocking; no original symbol proof; source placement remains Application module global.
- [x] Validators run and results recorded: command shape was `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240` for each changed by-* doc. Proof pass results:
  - `by-memory/0x0067ab1c-0x0067ab20.g_pApplication.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-file/Application.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-class/Application.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-memory/0x00463970-0x004639c4.ApplicationDestructor.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-memory/0x0066d000-0x0069d000.DataSection.md`: scanned `1`, `ok: 1`, exit `0`
  - `by-memory/0x0067ab20-0x0067ab24.g_pDirectX.md`: scanned `1`, `ok: 1`, exit `0`
- [x] Leases scoped and no active lease remains: leased the eight edited by-* docs immediately before patching, validators ran under that scoped window, `unlease` later returned `Rejected[No active lease]` for all eight because the short leases had expired, and `current_leases.md` search for the assigned paths/Agent-B001 returned no matches.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact row remains in "Coverage / Tracker Text"; no `*-coverage-report.md` file was edited by this callback. Final status still shows unrelated dirty supervisor-owned coverage-report entries in the worktree, left untouched by B001.
- [x] Remaining unapplied accepted items listed with exact blocker: none for B001-owned docs. Supervisor-owned coverage application is deferred to supervisor ownership by instruction.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000294-g_pApplication-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"000294"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000294-g_pApplication-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000294-g_pApplication-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000294"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
