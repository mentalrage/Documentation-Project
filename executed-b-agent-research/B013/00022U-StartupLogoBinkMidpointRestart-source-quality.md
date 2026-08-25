** TARGET-REPORT-UID:00022U **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00022U StartupLogoBinkMidpointRestart Source-Quality Report

Agent: Agent-B013  
Assignment id: B013-report-00022U-startup-logo-bink-midpoint-restart-20260625  
Mode: report-only research first  
Target: [UID:00022U] `by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md`  
Required report path: `tools/leaser/Agents/Agent-B013/research/00022U-StartupLogoBinkMidpointRestart-source-quality.md`

## Final Recommendation

Keep [UID:00022U] reconstructable, source-authored, owned by [UID:0000O4] `StartupLogoPanes`, and emitted through [UID:0000O4] to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`.

Recommended target metadata after implementation:

```text
COMPLETION:90
CONFIDENCE:94
CANONICAL_OWNER:0000O4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O4
```

Recommended source-facing function name:

```cpp
static void TryAdvanceStartupLogoBinkSegment();
```

Recommended documentation rename:

```text
from: by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md
to:   by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md
```

Rationale: the current name `StartupLogoBinkMidpointRestart` correctly describes the frame midpoint and close/open operation, but it reads like an automatic midpoint event. Current IDA MCP proves the helper is only reached from the temporary startup-logo WndProc on `WM_KEYDOWN` or `WM_LBUTTONDOWN`; it conditionally advances from the first memory-backed segment to the next segment while the active Bink stream is still before half of its total frame count. `TryAdvanceStartupLogoBinkSegment` better represents the source-level role without overclaiming "skip intro" semantics or original symbol proof.

First-draft C++ is now ready for the target's formal `RECONSTRUCTION_CPP CODE` block. The previous blank-code rationale relied on an older `95+` threshold and unresolved names. Current by-structure rules allow code when the item is reconstructable, has a confirmed emitter route, and `(COMPLETION + CONFIDENCE) / 2 > 85`; the current target is already `88/93`, has `EMITTER_UIDS:0000O4`, and the current pass resolves the target-local naming and behavior blockers enough for a source-shaped first draft.

## Current Target State

Source page state before this report:

```text
UID:00022U
COMPLETION:88
CONFIDENCE:93
CANONICAL_OWNER:0000O4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O4
RECONSTRUCTION_CPP CODE: blank
```

Current generated-report state is stale:

- `auto-generated/-ag-memory-coverage.md` line for [UID:00022U] routes to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`, but reports `emits_code:false`.
- `auto-generated/-ag-research-tracker.md` still shows [UID:00022U] as `72/88`.
- `auto-generated/-ag-coverage-report-by-memory.md` still shows [UID:00022U] as `72% : strong`.
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp`, refreshed by validator command `000000000980` at `2026-06-25T02:35:47-04:00`, contains an empty marker for [UID:00022U] with stale `Completion:72 | Confidence:88`.

Do not edit those generated files manually. Implementation should update the source by-* docs and run scoped validator/autogen refresh so validator-owned output catches up.

## Evidence Checked

Instructions and workflow:

- `tools/leaser/Agents/Agent-B013/goal.md`
- project-level `ntk-b-agent-workflow` skill
- `references/b-agent-research-and-implementation-workflow.md`
- `references/supervisor-rule26-review-and-incorporation-standard.md`
- `tools/leaser/Agents/Supervisor.md`
- `by-structure.md`
- `by-memory/-guidance.md`
- `tools/int_convert_readme.md`

Target and support docs:

- [UID:00022U] `by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md`
- [UID:0000O4] `by-file/StartupLogoPanes.md`
- [UID:00022T] `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md`
- [UID:0003K6] `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`
- [UID:0003K7] `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md`
- [UID:00029G] `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md`
- [UID:0002ZH] `by-global/StartupLogoBinkRestartFlag.md`
- [UID:0002ZM] `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`
- [UID:0001RN] `by-resource/startup-logo-media.md`
- [UID:0001NT] `by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md`
- [UID:0000P4] `by-file/VideoPlayerPane.md`
- [UID:0001QE] `by-meta/client_libraries.md`

Generated/read-only context:

- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `auto-generated/-ag-research-tracker.md`
- `project-level/-auto-completion-stats.md`
- `project-level/-unresolved.md`
- `auto-generated/NexusTK/app/StartupLogoPanes.cpp`

Prior reports were searched for context. Relevant executed reports included B003 [UID:0002PU] `LogoPlayerPaneAdvanceToNextSegment`, B004 [UID:0002PS] `LogoPlayerPaneConstructor`, B001 [UID:0002PV] `LogoPlayerPaneInputSkipHandlers`, and B003 [UID:0002PW] `LogoPlayerPaneOnClose`. This report does not rely on old/offline evidence for the target; it refreshes [UID:00022U] directly through current IDA MCP.

## IDA MCP Availability And Session

Current endpoint: `http://127.0.0.1:13337/mcp`

MCP was available and used. No IDA DB mutation tools were called.

Live session details:

```text
idb_list session_id: 80de0a67
input_path: E:\NTK\Resources\NexusTK\NexusTK.exe.i64
backend: worker
worker_pid: 26892
server_health: ok
module: NexusTK.exe
runtime input_path: C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
imagebase: 0x400000
auto_analysis_ready: true
hexrays_ready: true
strings_cache_ready: true
strings_cache_size: 2067
```

Active tool schema was checked with `tools/list`. The relevant read-only calls used required `database:80de0a67`.

## Current MCP Evidence

Target function:

- `lookup_funcs` reports `sub_4F5AE0` at `0x004f5ae0`, size `0x3e`; `0x3e` is 62 bytes (Verified with `tools/int_convert.py`).
- `analyze_function 0x004f5ae0` reports `prototype:"void()"`, size `62`, four basic blocks, cyclomatic complexity `3`, no strings, callers `[sub_4F59D0]`, callees `[_BinkClose@4, _BinkOpen@8]`.
- `decompile 0x004f5ae0` reports a no-argument helper that checks `byte_66DB42`, compares `*(unk_69B45C + 0x0c)` against `*(unk_69B45C + 0x08) >> 1`, clears `byte_66DB42`, calls `BinkClose(unk_69B45C)`, then stores `BinkOpen(unk_69B474, 67633152)` back to `unk_69B45C`.
- `disasm 0x004f5ae0` reports the exact instruction sequence:
  - `0x004f5ae0`: `cmp byte_66DB42, 0`
  - `0x004f5ae7`: branch to return if the flag is zero
  - `0x004f5ae9`: load active Bink handle from `0x0069b45c`
  - `0x004f5aef-0x004f5af4`: load BINK `+0x08`, divide by two via `shr`, compare BINK `+0x0c`
  - `0x004f5af7`: branch to return if current frame is not below half of total frames
  - `0x004f5afa`: clear `0x0066db42`
  - `0x004f5b01`: call `_BinkClose@4`
  - `0x004f5b07`: push `0x04080000`; `0x04080000` is 67633152 (Verified with `tools/int_convert.py`)
  - `0x004f5b0c`: push next-segment pointer from `0x0069b474`
  - `0x004f5b12`: call `_BinkOpen@8`
  - `0x004f5b18`: store reopened handle to `0x0069b45c`
  - `0x004f5b1d`: return
- `callees 0x004f5ae0` reports exactly `_BinkClose@4` at `0x0060d554` and `_BinkOpen@8` at `0x0060d564`, both external.
- `xrefs_to 0x004f5ae0` reports exactly one code xref: `0x004f5aaf` inside `sub_4F59D0`.
- `get_bytes` reports:
  - `0x004f5ad4-0x004f5ae0`: twelve `0xcc` bytes; `0xc` is 12 (Verified with `tools/int_convert.py`)
  - `0x004f5ae0-0x004f5b1e`: target bytes beginning `80 3d 42 db 66 00 00 74 34 ...` and ending `a3 5c b4 69 00 c3`
  - `0x004f5b1e-0x004f5b20`: two `0xcc` bytes; `0x2` is 2 (Verified with `tools/int_convert.py`)

Caller and component evidence:

- `lookup_funcs` reports `sub_4F59D0` at `0x004f59d0`, size `0xf7`; `0xf7` is 247 bytes (Verified with `tools/int_convert.py`).
- `decompile 0x004f59d0` reports a Win32 `LRESULT __stdcall(HWND, UINT, WPARAM, LPARAM)` WndProc. It calls `sub_4F5AE0()` only when `Msg == 256` or `Msg == 513`, matching `WM_KEYDOWN` and `WM_LBUTTONDOWN`.
- `disasm 0x004f59d0` confirms the input route at `0x004f5a80-0x004f5aaf`: compare `Msg` against `0x100` and `0x201`, then call `sub_4F5AE0`.
- `xrefs_to 0x004f59d0` reports one data xref from `0x004f585d` inside `sub_4F5710`, matching the `SetWindowLongA` WndProc install.
- `xrefs_to 0x004f5710` reports one direct code xref from `sub_4F5FB0` at `0x004f63b5`.
- `analyze_component 0x004f5710,0x004f59d0,0x004f5ae0` reports `0x004f5710` as the interface function, `0x004f59d0` and `0x004f5ae0` as internal-only functions, and the only internal edge as `0x004f59d0 -> 0x004f5ae0`.

Global and payload evidence:

- `xref_query` for `0x0066db42` reports exactly two refs, both in [UID:00022U]: read/compare at `0x004f5ae0` and write-clear at `0x004f5afa`.
- `xref_query` for `0x0066db43` reports zero xrefs.
- `get_global_value` reports `0x0066db42 = 0x1` and `0x0066db43 = 0x0`.
- `xref_query` for `0x0069b45c` reports 11 refs: nine inside `sub_4F5710` and two inside [UID:00022U] at `0x004f5ae9` and `0x004f5b18`.
- `xref_query` for `0x0069b474` reports two refs: store/setup at `0x004f57e4` in `sub_4F5710` and read at `0x004f5b0c` in [UID:00022U].
- `xref_query` for `0x0069b478` reports one store at `0x004f57f2` in `sub_4F5710`; [UID:00022U] does not consume the remaining-size dword.
- `decompile 0x004f5710` shows `unk_69B474 = (int)Block + firstSegmentSize + 4`, `unk_69B478 = payloadSize - firstSegmentSize - 4`, the first stream open as `BinkOpen(buffer + 4, 67633152)`, the WndProc install as `SetWindowLongA(..., sub_4F59D0)`, and the frame-loop end check comparing BINK `+0x0c` against BINK `+0x08`.
- `imports_query` confirms `_BinkOpen@8` and `_BinkClose@4` come from import module `binkw32`. The same query lists the current Bink import family from `binkw32`.

Local support search:

- `rg --files` across `source-3` and `C:\Users\admin\Desktop\CTools` found the copied runtime `by-meta/obtained_thirdparty_files/runtime_from_local_client/binkw32.dll`, but no local Bink SDK header. Exact original SDK member spelling remains not symbol/header-proven.
- Current docs already record accepted source-facing BINK field interpretations: BINK `+0x08` is total `Frames`; BINK `+0x0c` is current `FrameNum`; `0x04080000` is `BINKFROMMEMORY | BINKNOSKIP`.

## Behavior Decision

Observed target behavior:

1. Return immediately if the one-shot restart/advance flag at `0x0066db42` is clear.
2. Load the active startup-logo Bink stream from `0x0069b45c`.
3. Return if `activeStream->FrameNum >= activeStream->Frames / 2`.
4. Clear the one-shot flag.
5. Close the current Bink stream.
6. Open the next memory-backed startup-logo Bink segment from `0x0069b474` with flags `0x04080000`.
7. Store the new handle back to `0x0069b45c`.

This is not a generic video player method and not a Bink runtime function. It is file-local startup media glue for the standalone `LOGO.PAK`/`LOGO.PAD` path. It mirrors the object-pane `LogoPlayerPane::AdvanceToNextSegment()` concept, but the storage is global/file-local and the cutoff is half of the active stream's total frames rather than the object-pane fixed frame `100` cutoff.

## Heuristic / Inference Reanalysis And Validation

Issue: direct owner/source placement.

- Best candidate: [UID:0000O4] `StartupLogoPanes`.
- Evidence: the only caller is [UID:0003K7] `StartupLogoBinkWndProc`; that WndProc is installed only by [UID:0003K6] `PlayStartupLogoBinkFile`; the touched globals live in [UID:00029G] `StartupLogoBinkPlaybackGlobals`; the flag lives in [UID:0002ZH]/[UID:0002ZM] `StartupLogoBinkRestartFlag`; the resource contract is `LOGO.PAK`/`LOGO.PAD` in [UID:0001RN].
- Rejected [UID:0000P4] `VideoPlayerPane`: reusable object playback owns `VideoPlayerPane::OpenBinkVideo`, base Bink frame pump, and object field `m_binkHandle`, but [UID:00022U] is standalone/global startup media state and has no `this` parameter or class vtable route.
- Rejected [UID:00007H] `LogoPlayerPane`: the object-pane path has a similar segment-advance concept, but it uses object AUTOBUF fields and a protected base helper. [UID:00022U] is reached through a temporary raw WndProc and global Bink state.
- Rejected Bink runtime/library ownership: the target calls Bink imports but is NexusTK-authored wrapper/control logic.
- Impact: keep `CANONICAL_OWNER:0000O4` and `EMITTER_UIDS:0000O4`.

Issue: source-facing helper name.

- Best name: `TryAdvanceStartupLogoBinkSegment`.
- Evidence: the helper is called only after input messages, checks a one-shot guard, requires the active stream before midpoint, and opens the next segment pointer. The action is conditional and may be a no-op.
- Rejected `StartupLogoBinkMidpointRestart`: acceptable descriptive documentation name, but it implies a midpoint-triggered restart. The helper actually runs on input and advances only while before midpoint.
- Rejected `HandleStartupLogoBinkInput`: the WndProc handles input; the helper handles the conditional segment transition.
- Rejected `SkipStartupLogoBinkIntro`: too semantic; binary evidence proves "advance to next memory-backed segment," not the user-visible meaning of that segment.
- Rejected `OpenNextStartupLogoBinkSegment`: too narrow because the guard and frame cutoff are essential behavior.
- Impact: recommend renaming the by-memory page and using `TryAdvanceStartupLogoBinkSegment` in formal C++.

Issue: global/source-facing names required by the target C++.

Recommended names for this target's used storage:

| Address | Current docs | Recommended source-facing name | Confidence |
| --- | --- | --- | --- |
| `0x0066db42` | startup-logo Bink restart flag | `g_startupLogoBinkRestartPending` | strong, inferred |
| `0x0069b45c` | active Bink stream handle | `g_startupLogoBinkHandle` | strong, inferred |
| `0x0069b474` | next in-memory Bink segment pointer | `g_startupLogoBinkNextSegment` | strong, inferred |

Rejected raw labels `byte_66DB42`, `unk_69B45C`, and `unk_69B474` for final source: they are IDA labels and the roles are now directly proven by current MCP xrefs, decompilation, and support docs.

Rejected over-specific `g_logoPakNextSegment` / `g_logoPadNextSegment`: [UID:0003K6] selects `LOGO.PAK` or `LOGO.PAD`, and the helper only knows it has the stored next segment pointer.

Rejected `g_startupLogoBinkSecondSegmentSize` for this target: `0x0069b478` stores the remaining size, but [UID:00022U] does not read it.

Issue: BINK fields.

- Best source-facing fields: `Frames` at BINK `+0x08`, `FrameNum` at BINK `+0x0c`.
- Evidence: [UID:00022U] compares `FrameNum < Frames / 2`; [UID:0003K6] checks `FrameNum == Frames` for playback end; [UID:0001NT]/VideoPlayerPane support docs already record the same interpretation with [UID:0002PU].
- Rejected "percent progress": the field is compared to total frames and half total frames, not to a percentage scale.
- Rejected keeping raw offsets in formal C++: source-shaped code should use the Bink struct fields once the field roles are this strong.
- Remaining uncertainty: no local Bink SDK header was found, so exact SDK member spelling remains inferred/high-probability rather than symbol-proven. This does not block this first draft because the role is cross-validated by three code paths.

Issue: C++ readiness.

- Evidence for readiness: exact one-function range, exact caller, exact callees, exact global refs, exact branch condition, no hidden indirect call, no local variable/type complexity, no mixed range, no split needed, confirmed owner/emitter route, and current score gate already cleared.
- Rejected no-code policy: the old blank-code note cites unresolved names and a `95+` threshold. The active rule no longer requires `95+`, and this pass resolves source-facing names enough for a formal first draft.
- Remaining nonblocking uncertainties: exact original spelling for the helper/global names, exact SDK header spelling, global declaration ordering, callback type at `0x0069b470`, and unused remaining-size storage at `0x0069b478`. None changes the target's behavior or ownership.

## Exact `RECONSTRUCTION_CPP CODE` For [UID:00022U]

If the supervisor accepts this report, insert the following exact content into the target's formal `RECONSTRUCTION_CPP CODE` block:

```cpp
static void TryAdvanceStartupLogoBinkSegment()
{
    if (!g_startupLogoBinkRestartPending)
        return;

    BINK *bink = g_startupLogoBinkHandle;
    if (bink->FrameNum >= bink->Frames / 2)
        return;

    g_startupLogoBinkRestartPending = false;

    BinkClose(bink);
    g_startupLogoBinkHandle =
        BinkOpen(g_startupLogoBinkNextSegment, BINKFROMMEMORY | BINKNOSKIP);
}
```

Code notes:

- No null check is added for `g_startupLogoBinkHandle`; the binary dereferences the active handle unconditionally once the flag is set.
- The guard is cleared before `BinkClose`, matching `0x004f5afa` before the import call at `0x004f5b01`.
- `bink->Frames / 2` expresses the source-level condition that compiled to `shr eax, 1`.
- The flags are the source-level equivalent of literal `0x04080000` / 67633152 (Verified with `tools/int_convert.py`).
- The code intentionally references global declarations that belong to [UID:00029G] and [UID:0002ZH]/[UID:0002ZM], rather than redefining outside-range storage in this by-memory function page.

## Score And Metadata Rationale

Recommended target score: `88/93 -> 90/94`.

Completion rises to `90` because the report adds a current MCP-backed evidence pass, resolves the source-facing helper name, resolves target-used global names, replaces the stale blank-code rationale with exact formal C++ content, and documents rejected alternatives. It does not go higher because supporting global declaration C++ and sibling WndProc/playback-helper C++ remain separate implementation work.

Confidence rises to `94` because current MCP reconfirmed the exact range, bytes, caller, callee imports, global refs, initial flag value, no-ref trailing flag byte, WndProc input route, next-segment setup route, and Bink frame-field semantics through target and support paths. It remains below `95` because no original symbols or local Bink SDK header prove exact original helper/global/member spellings, and broader startup media source-file split caveats still exist.

Owner/emitter metadata should not change:

```text
CANONICAL_OWNER:0000O4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000O4
EMITTER_POSITION_OPTIONAL:
```

## Recommended Target Doc Changes

For [UID:00022U]:

1. Rename the file to `by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md` while preserving UID `00022U`.
2. Change the H1/title and working source name to `TryAdvanceStartupLogoBinkSegment`.
3. Set `COMPLETION:90` and `CONFIDENCE:94`.
4. Replace the `Item Summary` with a concise summary that the helper is an input-triggered, one-shot startup-logo Bink segment advance: it checks `g_startupLogoBinkRestartPending`, advances only while `FrameNum < Frames / 2`, closes the active memory-backed stream, and opens `g_startupLogoBinkNextSegment` with `BINKFROMMEMORY | BINKNOSKIP`.
5. Preserve the current range, boundary, direct-caller, Bink import, global-ref, and padding evidence, but update it with current MCP session `80de0a67` facts from this report.
6. Replace the old "C++ remains blank pending final names and Bink field labels" text with the formal C++ block above and the remaining nonblocking caveats.
7. Add the source-facing name table for `g_startupLogoBinkRestartPending`, `g_startupLogoBinkHandle`, `g_startupLogoBinkNextSegment`, BINK `Frames`, and BINK `FrameNum`.
8. Add rejected alternatives for helper name, owner, global names, and no-code policy.
9. Add a change-log entry for this B013 report.

## Recommended Support-Doc Changes

[UID:0000O4] `by-file/StartupLogoPanes.md`:

- Update the proposed contents row and evidence notes from "startup Bink midpoint/restart helper" to the accepted source-facing `TryAdvanceStartupLogoBinkSegment`.
- Add that [UID:00022U] is now first-draft C++ ready and uses file-local/global startup Bink state, while the similar object-pane `LogoPlayerPane::AdvanceToNextSegment()` remains a separate class method.
- Keep `StartupLogoPanes.cpp` as the direct source route. No score change is required; if the supervisor wants score movement, confidence may move `86 -> 87`, but the broader static-logo versus video split caveat still caps the file page.

[UID:0003K7] `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md`:

- Update behavior and reconstruction notes so `WM_KEYDOWN` and `WM_LBUTTONDOWN` call `TryAdvanceStartupLogoBinkSegment`.
- Preserve the current evidence that the WndProc consumes close/destroy/input messages but does not directly clear the playback loop flag.
- Keep C++ blank for [UID:0003K7] unless a separate WndProc source-quality callback accepts its full body.

[UID:0003K6] `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md`:

- Update the touched-state table to use `g_startupLogoBinkHandle` and `g_startupLogoBinkNextSegment` as source-facing names where the target consumes them.
- Add that `0x0069b478` stores remaining payload size at `0x004f57f2`, but [UID:00022U] consumes only the next-segment pointer.
- Keep [UID:0003K6] C++ blank; its return type, callback object, message-pump helpers, and broader playback body still need their own formal source-quality pass.

[UID:00022T] `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md`:

- Update child references/text to the new [UID:00022U] title/path after rename.
- Keep the aggregate `RECONSTRUCTABLE:FALSE`, parentless, and non-emitting.

[UID:00029G] `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md`:

- Fix the stale header `Item Summary` wording that still says all-`0xff`; the body correctly documents zero-initialized storage.
- Add source-facing names for target-used slots:
  - `0x0069b45c`: `g_startupLogoBinkHandle`
  - `0x0069b474`: `g_startupLogoBinkNextSegment`
  - `0x0069b478`: remaining-size storage, not used by [UID:00022U]
- Preserve unresolved callback typing at `0x0069b470` and reserved dword caveats.
- Optional score direction after incorporation: `85/91 -> 86/92`, because a stale summary is fixed and target-used names are now resolved, but callback/reserved field questions remain.

[UID:0002ZH] `by-global/StartupLogoBinkRestartFlag.md` and [UID:0002ZM] `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md`:

- Add `g_startupLogoBinkRestartPending` as the preferred source-facing name for the one-shot flag.
- Preserve that exact original spelling is inferred, not symbol-proven.
- Preserve `0x0066db43` as no-ref trailing storage/alignment.
- No owner/emitter change is needed.

[UID:0001RN] `by-resource/startup-logo-media.md`:

- Update the standalone segmented Bink paragraph to reference `TryAdvanceStartupLogoBinkSegment`, the half-total-frame cutoff, and `g_startupLogoBinkNextSegment`.
- Keep the package provenance score unchanged; missing original media payload provenance is outside this target.

[UID:0001QE] `by-meta/client_libraries.md`:

- No required change. It already records `BINKFROMMEMORY | BINKNOSKIP` and the Bink runtime procurement decision.

## Generated/Coverage Refresh Expectations

Do not manually edit:

- `auto-generated/*`
- `project-level/*`
- `by-memory/-coverage-report.md`
- any other `-coverage-report.md`
- validator state/cache

After accepted by-* implementation and scoped validation, expected generated side effects are:

- `auto-generated/NexusTK/app/StartupLogoPanes.cpp` should contain the new [UID:00022U] first-draft helper instead of an empty marker.
- `auto-generated/-ag-memory-coverage.md` should show [UID:00022U] with emitted code through `0000O4`.
- `auto-generated/-ag-coverage-report-by-memory.md` should reflect the source page's updated score and summary after validator refresh.
- `auto-generated/-ag-research-tracker.md` will be finalized by the supervisor-owned `execute_report` lifecycle command after implementation verification, not by manual row edits.

No explicit manual legacy `by-memory/-coverage-report.md` replacement text is supplied because the current assignment did not grant permission for manual coverage-report edits and validator-owned generated coverage should be refreshed from source metadata.

## Validator Commands Expected After Implementation

Run from `source-3/project-documentation` after accepted edits. If the target is renamed, validate the new path.

> Executable block R001 was removed from this report and preserved verbatim in [00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md](00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If validator output does not refresh generated C++/coverage for the accepted code insertion, run the validator-owned autogen refresh:

> Executable block R002 was removed from this report and preserved verbatim in [00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md](00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The supervisor should execute the report only after claim-by-claim implementation verification:

> Executable block R003 was removed from this report and preserved verbatim in [00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md](00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No validators were run during this report-only pass.

## Remaining Questions And Impact

Remaining nonblocking uncertainties:

- No original symbol proves `TryAdvanceStartupLogoBinkSegment`, `g_startupLogoBinkRestartPending`, `g_startupLogoBinkHandle`, or `g_startupLogoBinkNextSegment`. Names are inferred from current binary behavior and project style.
- No local Bink SDK header was found. `Frames`, `FrameNum`, `BINKFROMMEMORY`, and `BINKNOSKIP` are accepted/high-probability source-facing names from current docs and behavior, but exact original header spelling is still not local-header-proven.
- The broader global cluster still has unresolved callback type at `0x0069b470` and reserved/no-ref dwords at `0x0069b464` and `0x0069b47c`.
- [UID:0003K6] playback helper and [UID:0003K7] WndProc are still blank-C++ because they are larger bodies with separate return type, callback, message-pump, and Windows API source-shape questions.

Impact:

- These uncertainties do not block [UID:00022U] owner/emitter, score movement, rename, or first-draft C++.
- They do block `95+` final-audit scoring for this target and the support global cluster.

## Implementation Tracking Checklist

Implementation callback status:

- [x] Rename [UID:00022U] from `by-memory/0x004f5ae0-0x004f5b1e.StartupLogoBinkMidpointRestart.md` to `by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md`, preserving UID `00022U`.
  - Proof: `Test-Path` after implementation returned `False` for the old path and `True` for the new path; validator command `000000001045` applied the UID path update.
- [x] Update [UID:00022U] metadata to `COMPLETION:90`, `CONFIDENCE:94`, `CANONICAL_OWNER:0000O4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O4`.
  - Proof: target header now contains `90/94`, owner/emitter `0000O4`, `RECONSTRUCTABLE:TRUE`, and a nonblank `Item Summary`; validator command `000000001045` reported `completion_update`, `confidence_update`, and `canonical_owner_update` for `00022U`. Supervisor correction command `000000001163` revalidated the target with `--uid-only --no-generated-refresh`, and final header readback kept the summary nonblank.
- [x] Update [UID:00022U] title, signature/source name, behavior, raw MCP evidence, source-facing names, rejected alternatives, score rationale, and change log with the B013 current-session facts.
  - Proof: target page now has H1/source name `TryAdvanceStartupLogoBinkSegment`, B013 MCP session `80de0a67` evidence, source-facing name and rejected-alternative sections, updated score rationale, and a 2026-06-25 B013 change entry.
- [x] Insert the exact formal `RECONSTRUCTION_CPP CODE` block from this report into [UID:00022U].
  - Proof: target formal block exactly emits `static void TryAdvanceStartupLogoBinkSegment()` with `g_startupLogoBinkRestartPending`, `g_startupLogoBinkHandle`, `FrameNum >= Frames / 2`, `BinkClose`, and `BinkOpen(g_startupLogoBinkNextSegment, BINKFROMMEMORY | BINKNOSKIP)`.
- [x] Update [UID:0000O4] `StartupLogoPanes` with the accepted `TryAdvanceStartupLogoBinkSegment` name, C++ readiness, and standalone-global versus LogoPlayerPane object-path distinction.
  - Proof: `by-file/StartupLogoPanes.md` proposed contents, evidence notes, cross-reference, and 2026-06-25 B013 change entry now record the accepted helper name and standalone-global/object-path distinction.
- [x] Update [UID:0003K7] `StartupLogoBinkWndProc` to name the callee `TryAdvanceStartupLogoBinkSegment` for `WM_KEYDOWN` and `WM_LBUTTONDOWN`.
  - Proof: both behavior-table input rows link to [UID:00022U] `TryAdvanceStartupLogoBinkSegment`, and the reconstruction notes preserve WndProc blank-C++ status.
- [x] Update [UID:0003K6] `PlayStartupLogoBinkFile` touched-state/source-name text for `g_startupLogoBinkHandle`, `g_startupLogoBinkNextSegment`, and `0x0069b478` remaining-size non-consumption by [UID:00022U].
  - Proof: touched-state rows now name `g_startupLogoBinkHandle`, `g_startupLogoBinkNextSegment`, and record that `0x0069b478` is not read by [UID:00022U].
- [x] Update [UID:00022T] split index references/text to the renamed [UID:00022U] helper while keeping the aggregate non-emitting and `RECONSTRUCTABLE:FALSE`.
  - Proof: split-index behavior/cross-reference text links to `TryAdvanceStartupLogoBinkSegment`; metadata remains `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, and blank-C++.
- [x] Update [UID:00029G] `StartupLogoBinkPlaybackGlobals`: fix stale all-`0xff` Item Summary text, add accepted source-facing slot names, preserve callback/reserved-slot caveats, and consider `85/91 -> 86/92` if the supervisor accepts score movement.
  - Proof: header summary now says zero-initialized bytes, layout names `g_startupLogoBinkHandle` and `g_startupLogoBinkNextSegment`, `0x0069b478` remains remaining-size storage not read by [UID:00022U], callback/reserved caveats remain, and metadata is now `86/92`.
- [x] Update [UID:0002ZH] and [UID:0002ZM] with `g_startupLogoBinkRestartPending` as preferred source-facing flag name, preserving inferred-name caveat and no-ref trailing byte evidence.
  - Proof: both flag pages now name `g_startupLogoBinkRestartPending`, state the name is inferred/not symbol-proven, and preserve `0x0066db43` no-ref trailing storage.
- [x] Update [UID:0001RN] startup-logo media text with the accepted helper name and half-total-frame standalone cutoff; keep score unchanged.
  - Proof: startup-logo media text now contrasts object path `FrameNum < 100` with standalone `FrameNum < Frames / 2` through [UID:00022U], and validator command `000000001066` preserved `87/94`.
- [x] Do not edit generated files, project-level reports, validator state/cache, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.
  - Proof: no manual `apply_patch` edits targeted generated/project-level/coverage/validator/IDA files. Validator-owned generated refresh ran once in command `000000001045` as part of scoped validation and generated-output verification.
- [x] Run the scoped validator commands listed above and report command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state.
  - Proof: see validator table in the implementation callback log below. All scoped validators exited `0` with `ok: 1`.
- [x] Verify generated `auto-generated/NexusTK/app/StartupLogoPanes.cpp` has a current [UID:00022U] helper body and no stale empty marker after validator/autogen refresh.
  - Proof: `rg` / `Select-String` found `// UID:00022U | by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md | Completion:90 | Confidence:94` at line 108 and the full helper body at lines 109-123; stale `StartupLogoBinkMidpointRestart` / empty marker text was absent.
- [ ] Supervisor only: after implementation verification, run `python .\tools\validator.py execute_report B013 00022U-StartupLogoBinkMidpointRestart-source-quality.md 00022U --apply`.
  - Exclusion proof: B013 did not run the supervisor-only execute-report lifecycle command.

## Report-Only Work Log

Changed files:

```text
tools/leaser/Agents/Agent-B013/research/00022U-StartupLogoBinkMidpointRestart-source-quality.md
```

Leases used: none. Report-only work does not require leases.

Validators run: none. Report-only work did not edit by-* docs.

IDA MCP writes: none. Only read-only inspection tools were used.

## Implementation Callback Work Log

Implementation changed source docs:

```text
by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md
by-file/StartupLogoPanes.md
by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md
by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md
by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md
by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md
by-global/StartupLogoBinkRestartFlag.md
by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md
by-resource/startup-logo-media.md
by-memory/-ignored.md
by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md
by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md
by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md
```

The last four files received only direct link/name synchronization required by the [UID:00022U] rename. The old target path no longer exists; the new target path exists.

Validator proof:

| File | command_id | command_timestamp | exit | ok | generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md` | `000000001045` | `2026-06-25T03:47:18-04:00` | 0 | 1 | completed |
| `by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md` final recheck | `000000001125` | `2026-06-25T03:54:07-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md` summary correction | `000000001163` | `2026-06-25T03:59:09-04:00` | 0 | 1 | skipped, `--uid-only --no-generated-refresh` |
| `by-file/StartupLogoPanes.md` | `000000001058` | `2026-06-25T03:48:17-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-file/StartupLogoPanes.md` final recheck | `000000001126` | `2026-06-25T03:54:08-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md` | `000000001060` | `2026-06-25T03:48:21-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md` | `000000001061` | `2026-06-25T03:48:24-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f5710-0x004f5ac7.StartupLogoBinkPlaybackLoop.md` | `000000001062` | `2026-06-25T03:48:26-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md` | `000000001063` | `2026-06-25T03:48:27-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-global/StartupLogoBinkRestartFlag.md` | `000000001064` | `2026-06-25T03:48:29-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x0066db42-0x0066db44.StartupLogoBinkRestartFlag.md` | `000000001065` | `2026-06-25T03:48:35-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-resource/startup-logo-media.md` | `000000001066` | `2026-06-25T03:48:37-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/-ignored.md` | `000000001067` | `2026-06-25T03:48:38-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md` | `000000001068` | `2026-06-25T03:48:47-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x004f5ad0-0x004f5ad4.StdioFileGetSize.md` | `000000001070` | `2026-06-25T03:48:53-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |
| `by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md` | `000000001071` | `2026-06-25T03:48:58-04:00` | 0 | 1 | skipped, `--no-generated-refresh` |

Supervisor correction note: verification found the target `Item Summary` blank after the earlier implementation. B013 leased only the target page, set the summary to `Input-triggered one-shot startup-logo Bink segment advance; checks restart-pending state, advances only before the active stream midpoint, closes the active memory-backed stream, and opens the stored next segment.`, ran `python .\tools\validator.py --mode file --file by-memory\0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md --uid-only --apply --no-generated-refresh --queue-timeout 240`, and released the target lease. Command `000000001163` exited `0` with `ok: 1`; final header readback after validation showed the summary stayed nonblank.

Generated output check:

```text
auto-generated/NexusTK/app/StartupLogoPanes.cpp:108 // UID:00022U | by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md | Completion:90 | Confidence:94
auto-generated/NexusTK/app/StartupLogoPanes.cpp:109 static void TryAdvanceStartupLogoBinkSegment()
auto-generated/NexusTK/app/StartupLogoPanes.cpp:111     if (!g_startupLogoBinkRestartPending)
auto-generated/NexusTK/app/StartupLogoPanes.cpp:114     BINK *bink = g_startupLogoBinkHandle;
auto-generated/NexusTK/app/StartupLogoPanes.cpp:122         BinkOpen(g_startupLogoBinkNextSegment, BINKFROMMEMORY | BINKNOSKIP);
```

Leases:

- B013 leased the target and support docs before editing.
- B013 released all active by-* leases after the validator batch.
- `current_leases.md` check after release found no `B013` entries.

IDA MCP writes: none during implementation callback. No IDA DB mutation tools were used.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00022U-StartupLogoBinkMidpointRestart-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/00022U-StartupLogoBinkMidpointRestart-source-quality.md","timestamp":"2026-06-25T04:25:09","uid":"00022U"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022U-StartupLogoBinkMidpointRestart-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00022U-StartupLogoBinkMidpointRestart-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
