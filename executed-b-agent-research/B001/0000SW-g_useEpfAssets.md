** TARGET-REPORT-UID:0000SW **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000SW g_useEpfAssets Ownership Research

Task: B001-043  
Date: 2026-06-11  
Agent: B001

## Finalized Report / Current Recommendation

READY FOR SUPERVISOR REVIEW.

Final action applied: assign [UID:0000SW] `by-global/g_useEpfAssets.md` upward to [UID:0000O5] `by-file/StartupWindow.md` as the best defensible existing source-file owner, and assign exact storage child [UID:0001OH] `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` to the semantic by-global parent [UID:0000SW].

This is a source-owner inference, not recovered source metadata. Live IDA MCP evidence shows `0x0066da97` is a one-byte `.data` global initialized to `1`, has `366` direct data xrefs, has `365` reads and exactly one observed write, and the sole write is `0x005807f3` inside `StartupWindow__Constructor`. Candidate Application, Config/Registry, and WinMain ranges have zero direct refs to the byte. StartupWindow is therefore the strongest existing source-file owner for the declaration/policy byte, while broad UI, renderer, weather, input, and pane references are consumers.

No split page was needed. [UID:0001OH] is already the exact one-byte storage item, [UID:0000SW] is the semantic global page, and the surrounding initialized data island contains unrelated neighboring globals with their own owners.

Confidence: `90/100` for exact storage and behavior, `88/100` for StartupWindow as best existing source-owner inference, `80/100` that the original source spelling was literally `g_useEpfAssets`. Final C++ remains blank until source spelling/type are recovered.

## Scope / Current State

| UID | Path | Before | After | Parent decision |
| --- | --- | --- | --- | --- |
| `0000SW` | `by-global/g_useEpfAssets.md` | `86/90`, reconstructable, parent blank | `88/90`, reconstructable | `AUTOGEN_PARENT_UID:0000O5` |
| `0001OH` | `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md` | `86/90`, exact storage, source owner unresolved | `88/90`, exact storage | `AUTOGEN_PARENT_UID:0000SW` |
| `0000O5` | `by-file/StartupWindow.md` | `87/85` | `87/85` | Gate-clearing direct source-file parent; evidence note repaired |

Relevant manual coverage rows were updated in `by-global/-coverage-report.md` and `by-memory/-coverage-report.md`. Generated coverage now agrees: `0000SW` is assigned to `0000O5`, and `0001OH` is assigned to `0000SW`.

## Evidence Basis

Existing documentation was treated as hypothesis. Live IDA MCP checks used `tools/list`, focused `py_eval`, `xrefs_to`, function lookup, and disassembly snippets.

One transient `py_eval` attempt failed because of the IDA MCP eval/exec fallback scope behavior. Retried focused calls succeeded, so no live-evidence blocker remains.

Live IDA MCP facts:

| Fact | Result |
| --- | --- |
| Address | `0x0066da97` |
| IDA name | `byte_66DA97` |
| Segment | `.data`, `0x0066d000-0x0069d000` |
| Item size/value | one byte, initial value `1` |
| Nearby bytes `0x0066da90-0x0066daa8` | `01 00 00 00 00 04 01 01 00 03 00 00 30 00 00 00 30 00 00 00 68 02 00 00` |
| Direct data xrefs | `366` |
| Reads/writes/unknown operand refs | `365` reads, `1` write, `0` unknown |
| Sole write | `0x005807f3`, `StartupWindow__Constructor`, `mov byte_66DA97, 1` |
| Application lifecycle/startup direct refs | `0` in documented candidate ranges |
| Config/Registry direct refs | `0` in documented candidate ranges |
| WinMain direct refs | `0` to the byte |
| MainUiGraph direct refs | `2` reads at `0x004f7d40` and `0x004f8aaf` |
| StartupWindow direct refs | `1` write at `0x005807f3` |

Startup order evidence:

| Address | Instruction / call | Ownership implication |
| --- | --- | --- |
| `0x004f5cca` | calls `Application__Constructor` | Application is constructed before the startup window path |
| `0x004f5d3a` | calls `StartupWindow__Constructor` | reaches the only observed write to the byte |
| `0x004f5d52` | calls `StartupWindow__RunUpdateCheck` | write occurs before update-check UI/control flow |
| `0x004f5e78` | calls `sub_4F5FB0` / Application startup path | later startup path, no direct byte ref found in documented Application ranges |
| `0x004f5e83` | calls message loop helper | consumer phase follows startup policy setup |

Neighboring data confirms this is not a single source-owned island:

| Address | Existing lead | B001-043 interpretation |
| --- | --- | --- |
| `0x0066da90` | `g_fpsDebugActive` / FpsPane | unrelated adjacent diagnostic flag |
| `0x0066da94` | `g_screenWidth` / Application | display dimension global |
| `0x0066da96` | `g_movementSubstepScale` / MapPane inference | separate movement-scale byte |
| `0x0066da97` | `g_useEpfAssets` | current target |
| `0x0066da98` | `g_screenHeight` / Application | display dimension global |
| `0x0066da9c`, `0x0066daa0` | `MapTilePixelDimensions` | MapPane tile dimensions |

## Xref / Caller Inventory

The full direct xref population is broad, so only ownership-relevant buckets are listed here.

| Bucket | Live result | Decision |
| --- | --- | --- |
| StartupWindow | one write at `0x005807f3` in `StartupWindow__Constructor` | accepted best owner signal |
| MainUiGraph | two reads | consumer only |
| Application lifecycle/startup | zero direct refs in checked ranges | rejected as direct owner |
| Config / RegistryConfig | zero direct refs in checked ranges | rejected as owner |
| WinMain | no direct refs to `0x0066da97`; only constructs/calls owner candidates | orchestrator only |
| UI/render/pane/weather/input readers | many reads across the 365-read population | consumers of a process-wide mode byte |

## Ranked Ownership Analysis

1. [UID:0000O5] `StartupWindow` / `NexusTK/app/StartupWindow.cpp` - accepted. It owns the only live-observed write and forces the process into EPF/current-layout mode before `StartupWindow__RunUpdateCheck`. The file already cleared the parent gate at `87/85`, and B001 repaired its notes to clarify that this is process-wide global ownership, not instance-field ownership.

2. Application / display startup ownership - rejected as primary owner for this byte. Neighboring screen-dimension globals belong to Application-like startup/display state, but live IDA found zero direct refs to `0x0066da97` in documented Application lifecycle/startup ranges. Address adjacency alone is weaker than the sole observed write.

3. Config / RegistryConfig - rejected. No direct refs appeared in the checked config/registry ranges, and no load/save/registry parser write was observed. The byte behaves like a startup policy value already fixed to `1`, not an option loaded from persisted config.

4. MainUiGraph, panes, render/resource/weather/input helpers - rejected as owners. They account for broad read traffic and explain the semantic spread of the mode byte, but they do not write or initialize it.

5. New `ClientAssetModeGlobals.cpp` / `DisplayModeGlobals.cpp` style owner - rejected for this pass. The surrounding bytes are already better explained by existing owners, and no additional coherent declaration set was identified beyond this one byte. Creating a one-global source file would be weaker than assigning to the existing writer file.

## Split / Child Decision

| Item | Decision | Rationale |
| --- | --- | --- |
| [UID:0000SW] by-global | keep as semantic global and assign to `0000O5` | reconstructable process-wide mode byte, exact storage and source-owner inference clear enough for gate |
| [UID:0001OH] by-memory | keep exact one-byte child and assign to `0000SW` | already exact `0x0066da97-0x0066da98` storage; by-global is now rooted upward |
| Surrounding initialized bytes | do not group or split under this task | neighboring items are owned by FpsPane, Application, MapPane, or other existing docs |

## Negative Evidence

- No live IDA evidence found a direct Application writer, config parser, registry loader, or WinMain assignment for `0x0066da97`.
- No direct refs were found in the documented Application lifecycle/startup or Config/Registry candidate ranges.
- MainUiGraph has only two reads and therefore cannot explain declaration ownership.
- Broad renderer/pane/weather/input xrefs are read-only consumers and are too distributed to be a direct source owner.
- The original source spelling is not recovered. `g_useEpfAssets` remains the normalized reconstruction alias; `byte_66DA97` remains the historical IDA alias.

## Changed Files

Manual edits made by B001-043:

- `by-global/g_useEpfAssets.md`
- `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
- `by-file/StartupWindow.md`
- `by-global/-coverage-report.md`
- `by-memory/-coverage-report.md`

Report created:

- `tools/leaser/Agents/Agent-B001/research/0000SW-g_useEpfAssets.md`

Validator-driven side effects from `--apply` included generated registry/coverage/stat refreshes. B001 did not manually edit generated or project-level files. Verified generated rows:

- `auto-generated/-ag-global-coverage.md`: `0000SW` assigned to `0000O5`, output path `auto-generated/NexusTK/app/StartupWindow.cpp`.
- `auto-generated/-ag-memory-coverage.md`: `0001OH` assigned to `0000SW`, output path `auto-generated/NexusTK/app/StartupWindow.cpp`.

## Validation

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000SW-g_useEpfAssets-removed.md](0000SW-g_useEpfAssets-removed.md). The archived block is non-authoritative and must not be executed.

Result: all five targeted file-mode validator `--apply` scans exited `0`. The first scan reported `ok: 1`, `completion_update 0000SW ... 88`, and `autogen_registry_update 0000SW ... -> 0000O5`; subsequent scans completed in the same batch with exit code `0`. Post-validation coverage readback confirmed:

- `auto-generated/-ag-global-coverage.md`: [UID:0000SW] assigned to `0000O5`.
- `auto-generated/-ag-memory-coverage.md`: [UID:0001OH] assigned to `0000SW`.
- `by-global/-coverage-report.md`: manual row now records `88%`, StartupWindow routing, and exact child evidence.
- `by-memory/-coverage-report.md`: manual row now records `88%`, `AUTOGEN_PARENT_UID:0000SW`, and StartupWindow upstream ownership.

## Lease Handling

- Read `tools/leaser/Agents/Agent-B001/current_leases.md` before shared edits.
- Acquired leases with exact AgentID `B001` for the five shared documentation files edited in this task.
- Released B001 leases after validation using `python .\leaser.py B001 unlease`.
- Final lease check reports `B001: No active leases`.

## Remaining Caveats / Follow-up

No blocker remains for supervisor review. The only caveat is epistemic: IDA does not preserve the original source declaration spelling or type, so this report recommends the best existing owner from binary evidence rather than claiming recovered source text. Future source-map/PDB evidence could refine the spelling or prove a smaller startup asset-mode module, but current live evidence supports the applied StartupWindow ownership.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0000SW-g_useEpfAssets.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"0000SW"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000SW-g_useEpfAssets-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0000SW-g_useEpfAssets.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000SW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
