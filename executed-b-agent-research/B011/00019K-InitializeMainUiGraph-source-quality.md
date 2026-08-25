** TARGET-REPORT-UID:00019K **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Report - [UID:00019K] InitializeMainUiGraph Source Quality

Assignment id: `B011-report-00019K-initialize-main-ui-graph-source-quality-20260626`
Agent: `B011`
Mode: report-only research
Report path: `tools/leaser/Agents/Agent-B011/research/00019K-InitializeMainUiGraph-source-quality.md`

## Target

- Target: [UID:00019K] `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`
- Queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`
- Current metadata:
  - `COMPLETION:87`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:0000L1`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000L1`
  - Formal `RECONSTRUCTION_CPP CODE`: blank
- Current owner/emitter: [UID:0000L1] `by-file/MainUiGraph.md`
- Related item view: [UID:0000UV] `by-item/InitializeMainUiGraph_004F7D10.md`

## Recommendation Summary

Raise [UID:00019K] from `87/89` to `90/91`, keep `CANONICAL_OWNER:0000L1`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000L1`, and keep formal C++ blank with a target-specific no-code proof.

This pass closes several previously documented blockers rather than deferring them:

- `off_61E100` and `off_61E114` are `FRAME.EPF` and `FRAME.EPD`.
- `sub_480AD0` is `ChattingModifyHeightPane::SetLineCount`.
- `sub_557820` is `ScreenPane::EnablePresentationMode`.
- `sub_57B370` is `SoundManager::RestartMusic(3000)`.
- `dword_69AE08` is `g_pScreenDimmer`.
- `dword_67A74C` is `g_pApplicationCleanupQueue`, with `0x00469180` as the BlackHole deferred-deletion queue helper.
- `dword_67AB1C + 0x840` is the Application active-map/session byte; [UID:0002QH] proves the teardown counterpart clears it, so this initializer sets it true.
- `dword_69B364`, `dword_69B368`, `dword_69B36C`, `dword_69B374`, `dword_69B378`, and `dword_69B37C` have accepted source-facing layer/context names in [UID:0000T6], though final declaration shape remains a cap.
- `word_66DA9C` and `word_66DAA0` are `g_mapTilePixelWidth` and `g_mapTilePixelHeight`, both `48`.

The remaining no-code reason is not "needs future investigation" in the ordinary sense. Current evidence shows that emitting source-shaped C++ for the entire 3611-byte bootstrap now would require inventing a full `MainUiGraph` concrete type/layout, many subobject member names, and broad pane allocation wrappers that are still not recovered at source quality. The report therefore recommends documentation/source-quality updates now and no formal C++ until the root graph object model and constructor/helper family are split or recovered enough to avoid decompiler-shaped output.

## Current Evidence Checked

### Current IDA MCP Session

MCP was available and used. I did not manage or restart MCP.

- Endpoint/listener check: `127.0.0.1:13337` listening.
- JSON-RPC `initialize`: success.
- JSON-RPC `tools/list`: success.
- Active IDB from `idb_list`: session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active, analysis not running.
- `server_health` for `80de0a67`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

MCP calls used for this report:

- `lookup_funcs` for `0x004f7d10`, `0x004f8b2a`, `0x004f8b2b`, `0x004f8b30`, `0x004fac9b`, and `0x0067aba4`.
- `xrefs_to` for `0x004f7d10`, `0x0067aba4`, `0x0061e100`, `0x0061e114`, `0x0067ab1c`, and `0x0069ae08`.
- `analyze_function` for `0x004f7d10`.
- `get_bytes` for `0x004f7d00`, `0x004f8b20`, `0x0061e100`, `0x0066da97`, and `0x0066da9c`.
- `find_bytes` for absolute VA patterns `10 7d 4f 00`, `2a 8b 4f 00`, `2b 8b 4f 00`, and `30 8b 4f 00`.
- `disasm` for `0x004fac90`, `0x004f8a80`, and `0x004f7d40`.
- `tools/int_convert.py` for `0xe1b`, `0x5d`, `0x128`, `0x910`, `0x104`, `0xbb8`, `0x840`, and `0x12c`.

One MCP `get_bytes` attempt used a stale `addr`/`size` schema and returned `missing required parameters: ['regions']`; the schema-correct retry with `regions` succeeded. One disassembly attempt used stale `addrs` and returned `missing required parameters: ['addr']`; schema-correct `addr` retries succeeded. These were request-shape corrections, not MCP unavailability.

### Current Docs Checked

- [UID:00019K] target by-memory page.
- [UID:0000UV] by-item `InitializeMainUiGraph_004F7D10.md`.
- [UID:0000L1] by-file `MainUiGraph.md`.
- [UID:0000RF] `g_pMainUiGraph.md`.
- [UID:0000T6] `MainUiLayerSlots.md`.
- [UID:0000T7] `MapTilePixelDimensions.md`.
- [UID:0001R7] `backpane-background-resources.md`.
- [UID:000294] `g_pApplication.md`.
- [UID:0002QH] `MapPaneExitToMenuTeardown.md`.
- [UID:00029D] `g_pScreenDimmer.md`.
- [UID:0000Q8] `g_pApplicationCleanupQueue.md`.
- [UID:0001OX] `g_pScreenPane.md`.
- [UID:00039S] `ScreenPanePresentationModeFlagSetters.md`.
- [UID:0003ZI] `SoundManagerRestartMusic.md`.
- [UID:0002F8] `ChattingModifyHeightPaneSetLineCount.md`.
- Existing executed B reports used as leads only, then checked against current docs/MCP: B005 BackPane construction, B009 ScreenPane presentation setters, B013 profile load/import, B001 Chatting modify-height, B002 MapPane lifecycle, and several pane-constructor support reports.

## IDA MCP Findings

### Function Boundary And Caller

- `lookup_funcs 0x004f7d10` reports `sub_4F7D10`, size `0xe1b` / decimal `3611` (Verified with `int_convert.py`).
- `lookup_funcs 0x004f8b2a` still resolves inside `sub_4F7D10`.
- `lookup_funcs 0x004f8b2b` reports `Not a function`.
- `lookup_funcs 0x004f8b30` reports successor `sub_4F8B30`, size `0x5d` / decimal `93` (Verified with `int_convert.py`).
- `get_bytes 0x004f8b20 size 32` shows the stack-cookie check, `mov esp, ebp`, `pop ebp`, `retn` at `0x004f8b2a`, then five `0xcc` bytes before the successor prologue at `0x004f8b30`.
- `get_bytes 0x004f7d00 size 32` shows pre-function padding before the prologue at `0x004f7d10`.
- `xrefs_to 0x004f7d10` reports one code xref: `0x004fac9b` inside `sub_4FAB10`.
- `disasm 0x004fac90` shows `0x004fac95 mov ecx, dword ptr unk_67ABA4` immediately before `0x004fac9b call sub_4F7D10`. This confirms the caller passes `g_pMainUiGraph` as the `this`/receiver context.
- `xrefs_to 0x0067aba4` reports 31 refs and includes the same `0x004fac95` caller-side load.

The target docs already preserve the essential range evidence, but the target filename uses `0x004f8b2a` as the last covered byte while the modeled half-open range is `0x004f7d10-0x004f8b2b`. The implementation should clarify this explicitly in the range table and, if the supervisor wants strict half-open filenames, plan a separate rename/link update. I do not recommend silently renaming during the implementation callback unless the supervisor explicitly approves the broader link churn.

### Branch Structure And Key Data

- `analyze_function 0x004f7d10` reports prototype-shaped decompiler output as `int __thiscall(wchar_t *this)`, size 3611, one caller `sub_4FAB10`, 39 callees, 139 basic blocks, cyclomatic complexity 5.
- The decompiler and `disasm 0x004f7d40` both show the top branch on `byte_66DA97 == 1`.
- `get_bytes 0x0066da97 size 1` returns `0x01`, matching current EPF/current-layout mode in the loaded image.
- `get_bytes 0x0066da9c size 6` returns `30 00 00 00 30 00`; [UID:0000T7] documents the exact two-byte children as `g_mapTilePixelWidth = 48` and `g_mapTilePixelHeight = 48`.
- `disasm 0x004f7d40` shows the EPF branch:
  - `0x004f7d76 push offset off_61E100`
  - `0x004f7d7d call sub_467830`
  - `0x004f7ddb` allocates `0x910` / decimal `2320` bytes (Verified with `int_convert.py`) for the MapPane constructor path.
  - `0x004f7dfa call sub_504110` with arguments `17` and `15`.
  - `0x004f7e11` and `0x004f7e18` read `word_66DAA0` / `word_66DA9C` and build the playfield rectangle before attaching through `unk_69B364`.
- `get_bytes 0x0061e100 size 64` decodes as UTF-16 `FRAME.EPF`, `FRAME.EPD`, and the next resource literal. `xrefs_to 0x0061e100` reports the EPF branch data xref at `0x004f7d76`; `xrefs_to 0x0061e114` reports the legacy branch data xref at `0x004f856c`.

### Common Tail

`disasm 0x004f8a80` confirms the common tail:

- `0x004f8a83 call sub_4F95B0`: current docs/B013 resolve this as `LoadUserProfileData`.
- `0x004f8a88 mov ecx, dword_67A7CC`; `0x004f8a8e call sub_557820`: [UID:00039S] resolves this as `g_pScreenPane->EnablePresentationMode()`, field offset `0x12c` / decimal `300` (Verified with `int_convert.py`).
- `0x004f8a93 mov ecx, dword_67A74C`; `0x004f8a9a call sub_469180`: [UID:0000Q8] and [UID:0000Z1] resolve this as BlackHole deferred cleanup queue use through `g_pApplicationCleanupQueue`.
- `0x004f8a9f mov ecx, dword ptr unk_69AE08`; optional virtual call with argument `1`: [UID:00029D] resolves this storage as `g_pScreenDimmer`.
- Old-layout only after `byte_66DA97 != 1`: allocate `0x104` / decimal `260` bytes (Verified with `int_convert.py`) and call `sub_4E9D00`, documented as `InterfaceEfxMgr`.
- `0x004f8ae4 mov ecx, dword ptr unk_67AB44`; push `0`, push `0`, call `sub_4E8CF0`: current docs identify this as the InputMan target-retarget path.
- `0x004f8af3 mov ecx, dword_67A7D0`; push `0xbb8` / decimal `3000` (Verified with `int_convert.py`), call `sub_57B370`: [UID:0003ZI] resolves this as `SoundManager::RestartMusic(3000)`.
- `0x004f8b03 mov eax, dword ptr unk_67AB1C`; `0x004f8b08 mov byte ptr [eax+840h], 1`: [UID:000294] proves this is `g_pApplication`; [UID:0002QH] proves the matching teardown clears `Application + 0x840`. The best source-facing interpretation is `g_pApplication->m_inMapSession = true` / active map-session flag set, not a vague "main-UI-ready byte." Offset `0x840` is decimal `2112` (Verified with `int_convert.py`).

### Pointer/Route Negative Evidence

`find_bytes` found no absolute little-endian VA patterns for:

- `10 7d 4f 00` (`0x004f7d10`, target start)
- `2a 8b 4f 00` (`0x004f8b2a`, last covered byte)
- `2b 8b 4f 00` (`0x004f8b2b`, half-open end)
- `30 8b 4f 00` (`0x004f8b30`, successor)

This supports the existing live-route model: the initializer is reached through the sole direct call from the login-success function, not through a data table or pointer dispatch route.

## Heuristic / Inference Reanalysis And Validation

### Ownership And Source Placement

Accepted owner remains [UID:0000L1] `MainUiGraph.cpp`.

Positive evidence:

- Sole executable caller is login success, but the caller passes `g_pMainUiGraph`, not a login-dialog object.
- The callee constructs persistent in-game UI graph layers and panes, not transient login UI.
- It touches MainUiGraph-owned layer slots, `g_pMainUiGraph`, BackPane, MapPane, Chatting, UserPane, status panes, InputMan, ProfileStorage, SoundManager, ScreenDimmer, ScreenPane presentation mode, and Application active-session state.
- [UID:0000L1], [UID:0000RF], [UID:0000T6], and [UID:0000UV] already agree on the MainUiGraph source route.

Rejected alternatives:

- `LoginDialogPane`: rejected because login success is only the trigger; it loads `g_pMainUiGraph` into `ecx` before calling the initializer.
- `Application`: rejected because Application owns the global singleton and process lifecycle, but this body constructs the live UI graph after authentication.
- `BackPane`, `MapPane`, `Chatting`, `UserPane`, ScreenPane, SoundManager, and pane-specific source files: rejected because they are constructed or called by this initializer and own their own subranges, not the overall graph bootstrap.
- `ScreenDimmer` or `BlackHole`: rejected because they are tail consumers/dependencies.

No ownership/emitter route change is recommended.

### Range / Split / Padding

The function body is a single modeled function from `0x004f7d10` through last byte `0x004f8b2a`, half-open end `0x004f8b2b`, then five `0xcc` bytes before successor `0x004f8b30`.

No by-memory split is recommended for this target during the report-only phase. The body is broad, but IDA models it as one function and the branch/tail structure is internally coherent. Smaller exact callee pages already carry their own code ownership, and this page should remain the bootstrap function/index rather than absorbing callee C++.

The target docs should clarify the half-open range versus filename last-byte convention. This is a documentation precision issue, not a reason to split or lower the score.

### Placeholder And Generated Name Resolution

Resolved now:

- `sub_480AD0` -> `ChattingModifyHeightPane::SetLineCount`
- `sub_557820` -> `ScreenPane::EnablePresentationMode`
- `sub_57B370` -> `SoundManager::RestartMusic`
- `dword_67A7CC` -> `g_pScreenPane`
- `dword_67A74C` -> `g_pApplicationCleanupQueue`
- `unk_69AE08` -> `g_pScreenDimmer`
- `unk_67AB1C` -> `g_pApplication`
- `word_66DA9C` / `word_66DAA0` -> `g_mapTilePixelWidth` / `g_mapTilePixelHeight`
- `off_61E100` / `off_61E114` -> `FRAME.EPF` / `FRAME.EPD`
- first two most-used layer contexts can use [UID:0000T6] names: `effectPaneLayerContext`, `rootPaneLayerContext`, plus the other four slot names when referenced.

Still provisional but investigated:

- `sub_467830` is strongly `BackPane::BackPane(const wchar_t*)`; B005 and [UID:0001R7] close the resource-name blocker, but final constructor C++ belongs to BackPane, not this target.
- `sub_504110` is the MapPane constructor/initialize path. B002 supports treating it as `MapPane::MapPane`/constructor behavior, but exact parameter ordering and constructor source shape remain a MapPane-family cap.
- `sub_588E30` is the `OldSystemMessagePane` constructor inside the `SystemMessagePanes` aggregate.
- `sub_5BAB00` is the `UserStatusPane2` constructor family.
- `sub_5BC610` is adjacent to UserStatusPane2 and is currently best treated as the `MenuVarietyPane` constructor/boundary family, but this target should not finalize its body.
- `sub_5A2530` is the `UserPane` constructor family, with its own large class documentation.
- `sub_4E9D00` remains `InterfaceEfxMgr` old-layout construction.
- `sub_4E8CF0` remains the InputMan target-retarget path.

These remaining provisional labels do not block raising this page to `90/91` because the target's own ownership, branch role, caller, boundary, and major globals are now source-quality. They do block formal C++ for this full initializer because source-shaped code would need to name and type all of them coherently in one large emitted body.

### Open Questions With Attempted Resolution

1. Exact concrete type/layout of `g_pMainUiGraph`.
   - Checked: [UID:0000RF], [UID:0002AF], target caller, xrefs, target decompilation, MainUiGraph file docs.
   - Result: role is confirmed, but the root object type and field layout beyond the provisional login-name cache are not recovered. Current report cannot safely invent a complete `MainUiGraph` class definition.
   - Impact: no owner change; C++ remains blank.

2. Exact MainUiLayerSlots declaration shape.
   - Checked: [UID:0000T6], startup/shutdown docs, current xrefs and target use.
   - Result: current source-facing names are strong enough to replace raw `dword_69B36x` labels in docs and future caller code, but exact original global-vs-field declaration shape remains unresolved.
   - Impact: no code for the broad initializer yet; source-facing names should still be used in documentation.

3. `Application +0x840` byte meaning.
   - Checked: current target tail, [UID:000294] `g_pApplication`, [UID:0002QH] `MapPane::ExitToMenu`.
   - Result: best interpretation is active map/session state. InitializeMainUiGraph sets it true; MapPane exit-to-menu clears it false.
   - Impact: replace stale "main-UI-ready byte" wording with active map/session byte wording.

4. Frame resource pointer names.
   - Checked: `get_bytes 0x0061e100`, `xrefs_to 0x0061e100`, `xrefs_to 0x0061e114`, [UID:0001R7].
   - Result: resolved as `FRAME.EPF` and `FRAME.EPD`; `FRAME.EPD` payload provenance remains a packaging/resource question but not a source-name blocker.
   - Impact: remove target caveat saying filenames are not decoded.

5. Formal C++ readiness.
   - Checked: full decompilation shape, 39-callee inventory, range boundary, support docs for major raw callees/globals, root graph/global docs, and by-structure code gate.
   - Result: eligible emitter gate is cleared, but source-quality code is not safe for the whole target. The body is too broad and would currently require decompiler-shaped temporary locals, raw allocation scaffolding, many unresolved constructor signatures, and unproven `MainUiGraph` fields.
   - Impact: keep formal C++ blank with exact no-code proof below.

## Score And Metadata Recommendation

### [UID:00019K] Target

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000L1`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000L1`
- `EMITTER_POSITION_OPTIONAL:` unchanged
- Formal C++: blank

Reason for raising:

- The current MCP session reconfirms exact range, sole caller, graph-pointer handoff, branch selector, resource strings, major tail side effects, no pointer-table route, and common tail.
- Current support docs resolve multiple formerly raw/generated blockers.
- The target docs can now replace several stale caveats with source-facing names and rejected alternatives.

Reason not higher:

- The concrete `MainUiGraph` root type/layout is still not recovered.
- The six layer-slot names are accepted as source-facing support names but final declaration shape is not proven.
- Several constructor/helper callees remain owned by their own class/file pages and are not all formal-C++ ready.
- The whole initializer would still produce decompiler-shaped code if emitted now.
- The current page does not yet include the new support conclusions; it must be updated before the score is applied.

Reason not lower:

- Boundary, caller, handoff, branch/tail behavior, main globals, major resources, and major tail callees are independently confirmed by current MCP and support docs.
- The remaining uncertainty is source-shape/code readiness, not runtime behavior or ownership.

### Support Metadata Recommendations

- [UID:0000UV] `by-item/InitializeMainUiGraph_004F7D10.md`: raise or sync to `90/91`, keep owner/emitter [UID:0000L1], C++ blank.
- [UID:0000L1] `by-file/MainUiGraph.md`: optional modest raise from `86/86` to `88/88` after incorporating the same support evidence and correcting stale resource/session-byte wording. Do not raise higher until the root object type/layout and layer-slot declarations are source-quality.
- [UID:0000RF] `g_pMainUiGraph.md`: no score change required; optionally add a cross-reference to this B011 pass and preserve the concrete-type/layout open questions.
- [UID:0000T6] `MainUiLayerSlots.md`: no score change required; current slot names are sufficient support.
- [UID:0001R7], [UID:00039S], [UID:0003ZI], [UID:0002F8], [UID:0002QH], [UID:000294], [UID:00029D], [UID:0000Q8], and [UID:0001OX]: no score changes required from this pass.

## First-Draft C++ / No-Code Disposition

Do not insert formal C++ into [UID:00019K] in this callback.

Exact no-code proof:

- The target is a 3611-byte UI graph bootstrap with two layout branches, a shared tail, 39 direct callees, 139 basic blocks, and SEH cleanup records.
- It is reached through one direct login-success call, but it operates as a full MainUiGraph/root bootstrap rather than a small leaf method.
- Current evidence supports the runtime behavior and owner, but not a complete human-written `MainUiGraph` class layout or source-level constructor/helper abstraction set.
- Several child constructors and helpers are now named at a source-facing documentation level, but many are still not safe enough to place inside one copy/paste-ready mid-2000s C++ body without raw locals, raw `operator new` wrappers, vtable-call scaffolding, and generated labels.
- By-structure requires code in formal blocks to look like plausible original source and to preserve exact runtime behavior. A formal body today would either omit material runtime setup or look like decompiler output. Both would violate the code standard.

The correct action is to raise documentation/source-quality coverage, replace stale raw labels, record exact no-code proof, and defer formal C++ until the graph object model and constructor/helper families are recovered enough that the function can be emitted as human-written source. This is not an excuse to leave blockers uninvestigated; the major current blockers were chased and either resolved into source-facing names or narrowed to exact source-shape gaps.

## Target And Support Documentation Changes Needed

### `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`

Required updates if supervisor accepts this report:

- Update metadata to `COMPLETION:90`, `CONFIDENCE:91`; keep owner/emitter/reconstructable unchanged.
- Keep formal C++ blank; add the no-code proof above to the score/C++ rationale.
- Clarify the covered range as IDA half-open `0x004f7d10-0x004f8b2b`, last covered byte `0x004f8b2a`, five `0xcc` bytes at `0x004f8b2b-0x004f8b30`, successor `0x004f8b30`.
- Replace the unresolved resource-pointer caveat with `FRAME.EPF` at `0x0061e100` and `FRAME.EPD` at `0x0061e114`, one xref each from the target.
- Replace `dword_67AB1C` "main-UI-ready byte" wording with `g_pApplication->m_inMapSession = true` / active map-session byte wording, with [UID:0002QH] as teardown counterpart evidence.
- Rename direct-call/tail evidence:
  - `0x00557820` -> `ScreenPane::EnablePresentationMode()`
  - `0x0057b370` -> `SoundManager::RestartMusic(3000)`
  - `0x00480ad0` -> `ChattingModifyHeightPane::SetLineCount`
  - `0x00469180` -> `BlackHoleQueuePaneForDeferredDeletion` / BlackHole deferred-deletion queue helper
  - `dword_69AE08` -> `g_pScreenDimmer`
  - `dword_67A7CC` -> `g_pScreenPane`
  - `dword_67A74C` -> `g_pApplicationCleanupQueue`
- Use the accepted [UID:0000T6] source-facing layer names where the doc currently says only `dword_69B364`, `dword_69B368`, or `dword_69B36x`.
- Preserve negative evidence: one caller, no absolute pointer hits to start/end/successor, resource-string xrefs, and boundary padding.
- Add a B011 change note with MCP session `80de0a67`, current calls used, score rationale, and no-code proof.

### `by-item/InitializeMainUiGraph_004F7D10.md`

Required updates:

- Sync metadata and prose with target recommendation (`90/91`, owner/emitter unchanged, C++ blank).
- Replace stale raw helper/global names with the source-facing names listed above.
- Replace `off_61E100` / `off_61E114` caveat with `FRAME.EPF` / `FRAME.EPD`.
- Replace "application main-UI-ready flag" with active map/session byte wording.
- Preserve the current caller and range evidence.

### `by-file/MainUiGraph.md`

Required updates:

- Update the proposed contents/range wording to state `0x004f7d10-0x004f8b2b` half-open / `0x004f8b2a` last byte.
- Replace "filenames still need decoding" for frame resource pointers with `FRAME.EPF` / `FRAME.EPD`, linked to [UID:0001R7].
- Replace "sets the application main-UI-ready flag" with active map/session byte wording.
- Add a concise no-code/source-shape cap: MainUiGraph owns the bootstrap, but final body emission waits on concrete root object layout and full constructor/helper source shape.
- Optional: raise to `88/88` after these additions.

### `by-global/g_pMainUiGraph.md`

Optional support update:

- Add that current B011 MCP session `80de0a67` reconfirmed the sole caller handoff (`0x004fac95` load, `0x004fac9b` call) while preserving open questions for concrete type/layout and root pointer initialization.
- No score change required.

### Coverage Reports / Generated Files

B011 must not edit coverage reports or generated/project-level files. If manual coverage-report rows still exist for these targets and need score text changes, the supervisor should apply those after implementation and validation. Validator-owned generated reports should refresh through validator commands, not manual edits.

## Implementation Tracking Checklist

- [x] `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`: updated metadata to `90/91`, kept `CANONICAL_OWNER:0000L1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L1`, kept formal C++ blank, and added the exact no-code proof in Status, B011 Source-Quality Implementation, Score Rationale, Disposition, and Changes.
- [x] Target page: clarified exact half-open range `0x004f7d10-0x004f8b2b`, last byte `0x004f8b2a`, five-byte `0xcc` gap, and successor `0x004f8b30`; file was not renamed.
- [x] Target page: replaced unresolved `off_61E100` / `off_61E114` caveat with `FRAME.EPF` / `FRAME.EPD` evidence, live xref sites, and [UID:0001R7] `by-resource/backpane-background-resources.md` link.
- [x] Target page: replaced stale `dword_67AB1C + 0x840` wording with `g_pApplication->m_inMapSession = true` / active map-session state; linked [UID:000294] and [UID:0002QH].
- [x] Target page: updated direct-call/tail evidence for `ScreenPane::EnablePresentationMode`, `SoundManager::RestartMusic(3000)`, `ChattingModifyHeightPane::SetLineCount`, `g_pScreenDimmer`, `g_pScreenPane`, `g_pApplicationCleanupQueue`, and the BlackHole deferred-deletion queue helper.
- [x] Target page: used [UID:0000T6] accepted source-facing layer/context names for `effectPaneLayerContext`, `rootPaneLayerContext`, `overlayPaneLayerContext`, `layoutPaneLayerContext`, `statusPaneLayerContext`, and `fpsOverlayLayerContext`, while preserving the final declaration-shape cap.
- [x] Target page: preserved MCP evidence and negative evidence at report-level detail, including session `80de0a67`, `lookup_funcs`/`xrefs_to`/`get_bytes`/`find_bytes`/`disasm` coverage, pointer-route negatives, and B011 change note.
- [x] `by-item/InitializeMainUiGraph_004F7D10.md`: synced score to `90/91`, preserved owner/emitter and blank C++, replaced helper/global/resource/session-byte wording, preserved range/caller evidence, and added the no-code proof.
- [x] `by-file/MainUiGraph.md`: updated frame resource names, active-session-byte wording, half-open range wording, source-facing layer names, and final C++/source-shape cap; raised support metadata to `88/88` because the additions now justify the modest support-file increase.
- [x] `by-global/g_pMainUiGraph.md`: added current B011 MCP handoff recheck (`0x004fac95` load, `0x004fac9b` call) and pointer-route negatives; kept score at `86/88` and preserved concrete type/layout/open-storage questions.
- [x] No manual B011 edits were made to generated files, project-level reports, validator/tool state, IDA DB, or any `-coverage-report.md` files. Scoped validators did make their normal validator-owned registry/projection updates; those are reported below.
- [x] Scoped validators from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory\0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md --apply --queue-timeout 240`
    - `command_id: 000000002822`
    - `command_timestamp: 2026-06-26T15:30:36-04:00`
    - exit code `0`, `ok: 1`
    - generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000002822`, `generated_refresh_timestamp: 2026-06-26T15:30:36-04:00`
    - validator-owned effects included `completion_update`, `confidence_update`, `canonical_owner_update`, `autogen_registry_update`, `projected_stats_update`, link/index updates, and `missing_ref_uid` warnings for [UID:00039S]/[UID:0003ZI] even though their current files contain those UIDs.
  - `python .\tools\validator.py --mode file --file by-item\InitializeMainUiGraph_004F7D10.md --apply --queue-timeout 240`
    - `command_id: 000000002823`
    - `command_timestamp: 2026-06-26T15:30:57-04:00`
    - exit code `0`, `ok: 1`
    - generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000002823`, `generated_refresh_timestamp: 2026-06-26T15:30:57-04:00`
    - validator-owned effects included metadata updates, link/index updates, projected stats update, `stats_row_remove`, `stats_rescore_recommended`, and the same scoped-registry `missing_ref_uid` warnings for [UID:00039S]/[UID:0003ZI].
  - `python .\tools\validator.py --mode file --file by-file\MainUiGraph.md --apply --queue-timeout 240`
    - `command_id: 000000002824`
    - `command_timestamp: 2026-06-26T15:31:03-04:00`
    - exit code `0`, `ok: 1`
    - generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000002824`, `generated_refresh_timestamp: 2026-06-26T15:31:03-04:00`
    - validator-owned effects included metadata updates, link/index updates, projected stats update, and scoped-registry `missing_ref_uid` warnings for [UID:00039S]/[UID:0003ZI].
  - `python .\tools\validator.py --mode file --file by-global\g_pMainUiGraph.md --apply --queue-timeout 240`
    - `command_id: 000000002828`
    - `command_timestamp: 2026-06-26T15:31:11-04:00`
    - exit code `0`, `ok: 1`
    - generated refresh state: `generated_refresh: deferred`, `generated_refresh_command_id: 000000002828`, `generated_refresh_timestamp: 2026-06-26T15:31:11-04:00`
    - validator-owned effects included `canonical_owner_update`, `autogen_registry_update`, projected stats update, and no validation failure.
- [x] Lease proof: B011 acquired immediate edit leases for the four edited by-* files before patching. After validators, `python .\leaser.py B011 unlease ...` returned `Rejected[No active lease]` for all four paths; current generated `tools/leaser/Agents/current_leases.md` then showed no active B011 leases. No B011 leases remain.
- [x] Supervisor-owned after implementation: B011 did not edit any manual coverage report. If manual coverage rows need score text changes for [UID:00019K], [UID:0000UV], or [UID:0000L1], supervisor should apply them.

## Final Implementation Status

- Target/support by-* docs changed: `by-memory/0x004f7d10-0x004f8b2a.InitializeMainUiGraph.md`, `by-item/InitializeMainUiGraph_004F7D10.md`, `by-file/MainUiGraph.md`, `by-global/g_pMainUiGraph.md`.
- Generated/project-level/coverage-report files manually changed by B011: none.
- Validator-owned generated/project-level/tool-state effects: scoped validators reported projected stats/autogen registry/reference-index updates and deferred generated refresh as listed above.
- IDA DB changes: none.
- Leases used: immediate B011 edit leases acquired before by-* edits; no active B011 leases remain after validation/release attempt.
- Validators run: four scoped validators, all exit `0` with `ok: 1`.
- Target score applied: [UID:00019K] `87/89 -> 90/91`.
- Support score changes applied: [UID:0000UV] `87/89 -> 90/91`; [UID:0000L1] `86/86 -> 88/88`; [UID:0000RF] unchanged at `86/88`.
- Owner/emitter changes: none.
- Split/rename/new-child action: none; half-open range clarified while preserving filename last-byte convention.
- C++ status: formal C++ remains blank for [UID:00019K] and [UID:0000UV] under the accepted no-code proof.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00019K-InitializeMainUiGraph-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/00019K-InitializeMainUiGraph-source-quality.md","timestamp":"2026-06-26T15:46:04","uid":"00019K"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
