** TARGET-REPORT-UID:000410 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:000410] TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper Empty-Emitter Source-Quality Report

Agent: B003  
Assignment id: `B003-report-000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality-20260628`  
Mode: report-only research first  
Target: `[UID:000410] by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`  
Report path: `tools/leaser/Agents/Agent-B003/research/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep `[UID:000410]` as reconstructable source-authored TargetObject helper code owned by `[UID:0000ED] TargetObjectWithKeyboardPane`, set `EMITTER_UIDS:0000ED`, and emit only a formal covered-by marker to `[UID:0001LK] TargetObjectWithKeyboardPaneKeyboardEvent`.
- Final disposition: do not emit a callable `SelectLocalPlayerTargetObject` helper body. The raw helper start remains unmodeled and unreferenced; the active key handler implements the same self/local-player target-selection behavior inline.
- Required target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ED`, blank inline `RECONSTRUCTION_CPP CODE:[[[]]]`, and a multiline formal marker:

```cpp
// Emitted code for this range is covered by [UID:0001LK].
```

- Required support disposition: update the parent container `[UID:00036T]`, class `[UID:0000ED]`, file `[UID:0000OH]`, and key-handler `[UID:0001LK]` docs so they no longer say UID000410 is a blank emitter/C++ child. Sibling raw children `[UID:00040Y]` and `[UID:00040Z]` remain outside this recommendation and should stay blank unless separately accepted.
- Confidence: strong for exact byte behavior, range, owner/source route, active inline coverage, and negative route proof; medium-high for original helper spelling and original source retention shape.

## Supporting Research

## Target

- Target UID: `000410`.
- Target path: `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` currently lists `[UID:000410]` under `Files With Empty Emitters` with `85/88`, combined `86.5`, reconstructable `true`, report count `0`, blank executed report path.
- Current supervisor classification: report-only source-quality pass for a reconstructable by-memory empty-emitter row.
- Current scores and parent state:
  - Target: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000ED`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
  - Direct class parent `[UID:0000ED]`: `87/88`, `CANONICAL_OWNER:0000OH`, `EMITTER_UIDS:0000OH`.
  - Source file route `[UID:0000OH]`: `89/85`, `CANONICAL_OWNER:FILE`, file route for `NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
  - Split parent `[UID:00036T]`: `88/89`, non-emitting container over `[UID:00040Y]`, `[UID:00040Z]`, and `[UID:000410]`.

## Current Target State

- Existing metadata: `85/88`, owner `[UID:0000ED]`, reconstructable true, blank emitter, blank C++.
- Existing owner/source-route state: direct semantic owner `[UID:0000ED] TargetObjectWithKeyboardPane`; source module context `[UID:0000OH] TargetSelectionInputPanes`.
- Existing C++/emitter state: formal C++ is blank. The target currently says C++ should stay blank until a real entry route is recovered or the project accepts retained unreferenced helper emission.
- Existing open questions/blockers:
  - Whether blank `EMITTER_UIDS` is still correct.
  - Whether the class owner `[UID:0000ED]`, source file `[UID:0000OH]`, or both should emit.
  - Whether a covered-by marker is correct.
  - Whether a retained raw helper body can receive first-draft callable C++.
  - Whether current MCP evidence still supports no-xref/no-pointer/no-route.
- Related docs checked:
  - Target `[UID:000410]`.
  - Parent `[UID:00036T]`.
  - Sibling raw children `[UID:00040Y]` and `[UID:00040Z]`.
  - Active key handler `[UID:0001LK]`.
  - Neighbor helpers `[UID:00036S]` and `[UID:00036U]`.
  - Class `[UID:0000ED]`.
  - File `[UID:0000OH]`.
  - Saved globals `[UID:0002AB]`.
  - Active MapPane singleton `[UID:0001OW]`.
  - UserPane/local-player global `[UID:0001OR]`.
  - MapPane lookup/traversal helper page `[UID:00037Q]`.
  - Precedent raw-helper pages `[UID:0002S5]` ItemWho and `[UID:00048D]` SelectObject.
  - Executed reports `executed-b-agent-research/B014/00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md`, `executed-b-agent-research/B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md`, and `executed-b-agent-research/B005/0001L8-TargetSelectionInputPanes-source-quality.md`.

## Executive Recommendation

UID000410 should become an emitting, covered-by-marker target through the class route:

```text
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ED
RECONSTRUCTION_CPP multiline block:
// Emitted code for this range is covered by [UID:0001LK].
```

Use `[UID:0000ED]` as the direct emitter, not `[UID:0000OH]`, because the direct semantic owner and class route are already established. `[UID:0000OH]` remains the source file route through `[UID:0000ED]` and should be updated as support context, but adding it directly to UID000410's `EMITTER_UIDS` would bypass the class-level ownership model and would differ from the accepted ItemWho precedent `[UID:0002S5]`, which emits through its direct class owner `[UID:00006X]` rather than the file route.

The covered-by target should be `[UID:0001LK]`, not `[UID:00036T]` or `[UID:0000OH]`. UID0001LK is the active virtual key handler with vtable reachability and contains the equivalent self/local-player selection path inline. UID00036T is only the non-emitting split container. UID0000OH is a file/source-route owner, not the exact active behavior page.

Do not add callable helper-body C++. Live MCP confirms the raw start `0x005b06b0` is not an IDA function, has zero `xrefs_to`, zero code refs, zero data refs, zero immediate hits, and zero absolute-VA/RVA pointer byte hits. A callable helper body would invent a source call surface not present in the checked binary. The marker is intentional no-code C++ content that makes generated output trace the retained range to the active implementation page without overclaiming a standalone helper.

## Supervisor Active Recheck

- Current user instruction resumes B003's report-only assignment for `[UID:000410]`; no by-* docs may be edited until supervisor validation and callback.
- I did not edit target/support by-* docs, generated reports, generated C++ files, project-level generated files, manual coverage reports, validator/tool state, or IDA DB.
- I did not run `execute_report`.
- I did not spawn subagents.
- No lease was needed or used because the only write is this report in B003's own `research/` folder.
- IDA MCP was available and used; this is not fallback-only research.

## MCP Availability And Session

MCP was checked with the project JSON-RPC flow `initialize -> tools/list -> tools/call`. I did not start, stop, restart, or otherwise manage the MCP process.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- JSON-RPC `initialize`: server `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`.
- Session header observed: `cb314c68-9ba3-4808-8b66-4160990f8530`.
- Current open IDB session from `idb_list`: `agent_b009_0002my_20260628`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path reported by `server_health`: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module/imagebase: `NexusTK.exe`, `0x400000`.
- Health: `status=ok`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`, strings cache size `2067`, `is_analyzing=false`.
- Active tool schema checked: `server_health`, `idb_list`, `lookup_funcs`, `xrefs_to`, `find`, `find_bytes`, `insn_query`, `get_bytes`, `decompile`, and `callees` were available with required `database` arguments.

## Evidence Checked

MCP checks performed:

- `server_health` for live IDB readiness.
- `lookup_funcs` for `0x005b0010`, `0x005b0290`, `0x005b0510`, `0x005b05b0`, `0x005b05d0`, `0x005b0640`, `0x005b06b0`, `0x005b06f0`, and `0x005b077a`.
- `xrefs_to` for raw starts `0x005b05d0`, `0x005b0640`, `0x005b06b0`, neighboring routed helpers `0x005b05b0` and `0x005b06f0`, active key handler `0x005b0010`, and saved target state `0x0069bf2c`.
- `find type=code_ref`, `find type=data_ref`, and `find type=immediate` for raw starts `0x005b05d0`, `0x005b0640`, and `0x005b06b0`.
- `find_bytes` for raw-start absolute VA pointer patterns `D0 05 5B 00`, `40 06 5B 00`, `B0 06 5B 00` and imagebase-relative RVA pointer patterns `D0 05 1B 00`, `40 06 1B 00`, `B0 06 1B 00`.
- `insn_query` over `0x005b06b0-0x005b06f0` for UID000410 instruction facts.
- `insn_query` over `0x005b0100-0x005b0150` for UID0001LK self/local-player inline branch facts.
- `callees 0x005b0010` for active key-handler dependency set.
- `get_bytes` for `0x005b06a8`, `0x005b06b0`, `0x005b06ef`, and `0x005b06f0`.
- `decompile 0x005b0010` for active key-handler sanity check.
- `decompile 0x005b06b0` to confirm the raw start is not decompilable as a modeled function.

Documentation/generated checks performed:

- Target/support docs listed in `Current Target State`.
- `auto-generated/-ag-research-tracker.md` row for `[UID:000410]`.
- `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` current generated output. It contains the ItemWho covered-by marker for `[UID:0002S5]` and currently does not contain a separate UID000410 marker because UID000410 has blank `EMITTER_UIDS`.
- Executed B reports listed above. B014's UID00036T report is treated as a lead only because it recorded MCP unavailability; this report redoes the target route evidence with current live MCP.

## Live MCP Function And Boundary Facts

`lookup_funcs` results:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x005b0010` | `sub_5B0010`, size `0x1ca` | Active TargetObject key handler. |
| `0x005b0290` | `sub_5B0290`, size `0x27d` | Active TargetObject mouse handler. |
| `0x005b0510` | `sub_5B0510`, size `0x93` | Object-list helper. |
| `0x005b05b0` | `sub_5B05B0`, size `0x1f` | Routed clear-current-target helper. |
| `0x005b05d0` | Not a function | Previous/up retained raw helper start. |
| `0x005b0640` | Not a function | Next/down retained raw helper start. |
| `0x005b06b0` | Not a function | UID000410 local-player retained raw helper start. |
| `0x005b06f0` | `sub_5B06F0`, size `0x8a` | Routed dispatch-forward helper. |
| `0x005b077a` | Not a function | End boundary/alignment after dispatch helper. |

Byte checks:

- `0x005b06a8-0x005b06b0`: eight `0xcc` bytes before UID000410.
- First 32 bytes at `0x005b06b0`: `8b 0d 64 a7 67 00 56 ff 35 2c bf 69 00 8b 35 48 a7 67 00 e8 a8 62 f5 ff 3b c6 74 21 85 c0 74 09`.
- `0x005b06ef`: one `0xcc` byte.
- `0x005b06f0`: starts with `55 8b ec 53 56 8b 75 08`, matching the modeled successor helper prologue.

Instruction facts for UID000410 `0x005b06b0-0x005b06ef`:

| Address | Instruction | Source-facing meaning |
| --- | --- | --- |
| `0x005b06b0` | `mov ecx, dword_67A764` | Load `g_activeMapPane`. |
| `0x005b06b7` | `push dword ptr unk_69BF2C` | Push `s_targetObjectTargetId`. |
| `0x005b06bd` | `mov esi, dword_67A748` | Load `g_pUserPane` / local-player object view. |
| `0x005b06c3` | `call sub_506970` | `MapPane::FindObjectPaneById`. |
| `0x005b06c8` | `cmp eax, esi`; `jz 0x005b06ed` | Already targeting local player means no state change. |
| `0x005b06d0-0x005b06d4` | `push 0`; `mov ecx, eax`; `call sub_53B1B0` | Clear old target highlight when present. |
| `0x005b06d9-0x005b06dd` | `push 1`; `mov ecx, esi`; `call sub_53B1B0` | Highlight the local player. |
| `0x005b06e2` | `mov eax, [esi+0FCh]` | Load local-player object id. |
| `0x005b06e8` | `mov dword ptr unk_69BF2C, eax` | Store `s_targetObjectTargetId`. |
| `0x005b06ee` | `retn` | End of helper body. |
| `0x005b06ef` | `align 10h` | One-byte `0xcc` alignment before `0x005b06f0`. |

`decompile 0x005b06b0` returned `code:null` with `error:"Decompilation failed at 0x5b06b0"`, matching the raw non-function status. This is not a behavioral contradiction; `insn_query` decodes the bytes normally.

## Direct Route And Xref Findings

MCP route checks for raw starts:

| Raw start | `lookup_funcs` | `xrefs_to` | `find code_ref` | `find data_ref` | `find immediate` | VA pointer bytes | RVA pointer bytes |
| --- | --- | ---: | ---: | ---: | ---: | ---: | ---: |
| `0x005b05d0` | Not a function | 0 | 0 | 0 | 0 | 0 | 0 |
| `0x005b0640` | Not a function | 0 | 0 | 0 | 0 | 0 | 0 |
| `0x005b06b0` | Not a function | 0 | 0 | 0 | 0 | 0 | 0 |

Neighbor positive controls:

| Address | MCP xrefs | Meaning |
| --- | --- | --- |
| `0x005b05b0` | code refs from `0x005b0082`, `0x005b0422`, `0x005b0495` | Neighbor clear helper is actively routed from key/mouse handlers. |
| `0x005b06f0` | code refs from `0x005b00ce`, `0x005b00f4` | Neighbor dispatch-forward helper is actively routed from key handler. |
| `0x005b0010` | data ref from `0x0062f40c` | Active key handler has vtable reachability. |

The negative route result is meaningful because MCP found normal route refs for both neighbors and the active key handler. The raw starts are not merely missed because the tool is broken.

Saved target state xrefs:

`xrefs_to 0x0069bf2c` returned 31 direct refs. Target-selection refs relevant to this report include:

- Constructor refs: `0x5aff72`, `0x5affba`.
- Active key-handler refs: `0x5b0065`, `0x5b010b`, `0x5b0147`, `0x5b0159`, `0x5b0186`, `0x5b01cc`.
- Mouse-handler refs: `0x5b02fe`, `0x5b0335`, `0x5b037c`, `0x5b03fc`.
- Object-list helper refs: `0x5b054b`, `0x5b0586`.
- Clear helper ref: `0x5b05b0`.
- Raw previous/next/local-player helper refs without containing functions: `0x5b05d8`, `0x5b0624`, `0x5b062b`, `0x5b0648`, `0x5b0694`, `0x5b069b`, `0x5b06b7`, `0x5b06e8`.
- Dispatch-forward refs: `0x5b0701`, `0x5b0740`.

The UID000410 refs at `0x5b06b7` and `0x5b06e8` prove the raw helper reads and writes the same file-scope TargetObject saved target id, but they are not xrefs to the raw start.

## Active Keyboard Handler Coverage

`insn_query 0x005b0100-0x005b0150` and `decompile 0x005b0010` both confirm the active self/local-player branch:

| Address | Instruction / decompile fact | Meaning |
| --- | --- | --- |
| `0x005b0101` | `cmp byte ptr [esi+4], 8` | Self-target key requires event subtype `8`. |
| `0x005b010b` | `push dword ptr unk_69BF2C` | Uses `s_targetObjectTargetId`. |
| `0x005b0111` | `mov ecx, dword_67A764` | Uses `g_activeMapPane`. |
| `0x005b0117` | `mov esi, dword_67A748` | Loads local-player/UserPane object view. |
| `0x005b011d` | `call sub_506970` | Resolves old saved target. |
| `0x005b0122-0x005b0124` | compare with local player and return unchanged if equal | Same no-change condition as UID000410. |
| `0x005b012e-0x005b0132` | `sub_53B1B0(old, 0)` | Clears old highlight. |
| `0x005b0137-0x005b013b` | `sub_53B1B0(localPlayer, 1)` | Highlights local player. |
| `0x005b0140` | `mov eax, [esi+0FCh]` | Loads object id. |
| `0x005b0147` | `mov dword ptr unk_69BF2C, eax` | Stores target id. |

`callees 0x005b0010` includes the same dependency set required for the raw helper family: `sub_506970`, `sub_506AE0`, `sub_506B30`, `sub_53B1B0`, plus key-handler-specific calls `std::ctype<char>::do_narrow`, `sub_5B05B0`, `sub_5B06F0`, `sub_469180`, and `sub_4F25A0`.

The decompiler's switch case `-111` is the self-target key path. It sets `v6 = dword_67A748`, resolves `unk_69BF2C`, clears the previous highlight if needed, then falls through to the shared highlight/store block that writes `unk_69BF2C = *(v6 + 252)`.

This confirms that `[UID:0001LK]` is a valid formal coverage target for UID000410. It does not prove UID0001LK calls UID000410.

## Positive Evidence Summary

- UID000410 is real source-authored NexusTK logic: normal instructions, MapPane lookup call, LivingObjectPane highlight calls, local-player object id load, saved target store, and ordinary `retn`.
- The half-open target range is exact: eight `0xcc` bytes before it, executable body from `0x005b06b0` through `0x005b06ee`, and one `0xcc` byte at `0x005b06ef` before modeled `sub_5B06F0`.
- The helper mutates `s_targetObjectTargetId` / `dword_69BF2C`, which is TargetObject-specific saved target state documented by `[UID:0002AB]`.
- The body consumes `g_activeMapPane` and `g_pUserPane` as dependencies; support docs already resolve these as MapPane/UserPane globals rather than TargetObject-owned storage.
- The direct semantic owner `[UID:0000ED] TargetObjectWithKeyboardPane` clears the gate and already routes to `[UID:0000OH] TargetSelectionInputPanes`.
- UID0001LK has vtable reachability and implements the same active behavior inline. It is the correct coverage target for generated-source traceability.
- `[UID:0002S5] ItemWhoTargetNavigationRawHelpers` is accepted precedent for a reconstructable raw helper island with no helper-start route that emits only a formal covered-by marker to its active key handler.

## Negative Evidence Summary

- MCP does not model `0x005b06b0` as a function.
- MCP found zero xrefs, code refs, data refs, immediates, absolute VA pointer byte matches, and RVA pointer byte matches to `0x005b06b0`.
- No vtable entry, callback table, function-pointer table, switch table, registration table, or direct call route to `0x005b06b0` was recovered.
- `decompile 0x005b06b0` fails because there is no function at that raw start.
- The active key handler duplicates the behavior inline, so a callable helper body here would duplicate emitted behavior and invent an unproven source call surface.
- Exact original helper spelling is not recoverable. `SelectLocalPlayerTargetObject()` is a strong source-facing descriptive role, not original symbol proof.
- Exact original source retention shape is not recoverable. The body could be a private static helper, file-static helper, or retained dead helper clone. The report should not encode one of those as a callable source body.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported conclusion | Rejected alternatives / uncertainty |
| --- | --- | --- | --- |
| Raw helper role | MCP `insn_query`, saved-target xrefs, support docs. | `SelectLocalPlayerTargetObject()` / self-target retarget helper. It selects local player as `TargetObjectWithKeyboardPane` saved target. | Reject padding/compiler glue. Reject a generic UserPane or MapPane helper because the only owned state mutation is TargetObject saved-target state. |
| Raw helper liveness | MCP `lookup_funcs`, `xrefs_to`, `find`, `find_bytes`, neighbor positive controls. | Retained/unreferenced raw helper body; no active route recovered. | Reject active keyboard-handler callee wording. Reject helper-body emission until a route appears or an explicit retained-helper-body policy is accepted. |
| Covered-by marker | Active key-handler disassembly/decompile and ItemWho precedent. | Correct formal disposition is a comment marker covered by `[UID:0001LK]`. | Reject leaving blank after setting an emitter; reject callable helper body; reject clearing reconstructable. |
| Owner/emitter route | Class/file docs, saved target state, neighbor helpers, ItemWho precedent. | Keep owner `[UID:0000ED]`; set emitter `[UID:0000ED]`; file `[UID:0000OH]` remains indirect source route. | Reject direct `[UID:0000OH]` emitter on this child because it bypasses the established class owner and differs from class-owned raw helper precedent. Reject dual `0000ED,0000OH` because it would duplicate the route. |
| Source-facing names | Saved globals, MapPane helper page, UserPane global page, active handler docs. | Use `s_targetObjectTargetId`, `g_activeMapPane`, `g_pUserPane` local-player object view, `MapPane::FindObjectPaneById`, `LivingObjectPane::SetTargetHighlight(bool)`, and object id / `GetObjectId()` for `+0xfc`. | Keep raw labels only as search aliases in evidence. Do not use `dword_`/`sub_` names in final C++ marker or source-facing prose except when quoting MCP facts. |
| Score movement | Current target lacks current-MCP proof and a formal no-empty-marker disposition. | Raise `85/88` to `88/89` after implementation. | Do not raise above 90-level confidence because no direct route, original helper spelling, or original retained-helper source shape is proven. |
| Split/range | Existing exact child page already covers `0x005b06b0-0x005b06ef`; MCP byte checks confirm boundaries. | No split/merge/rename needed. Parent `[UID:00036T]` remains the non-emitting container. | Do not fold UID000410 back into parent aggregate. Do not create smaller children. |

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| UID000410 is source-authored TargetObject self-target helper logic. | Strong | MCP instruction facts, saved-target xrefs at `0x5b06b7`/`0x5b06e8`, MapPane/highlight calls. | Not padding, not switch data, not compiler thunk, not MapPane-owned state. | Exact original helper symbol unavailable. |
| UID000410 has no active direct route in the checked IDB. | Strong | `xrefs_to`, `find code_ref/data_ref/immediate`, `find_bytes` VA/RVA all zero; neighbor helpers have positive refs. | Checked raw starts and positive controls. | Only future symbols/map/source or runtime-only indirection could change this. |
| UID0001LK covers emitted behavior. | Strong | Disassembly and decompile show self key branch with same lookup, compare, highlight, and store operations. | Behavior match is not caller proof; it is coverage proof only. | Future key-handler first-draft C++ can provide richer emitted body. |
| Direct emitter should be UID0000ED. | Strong | Target mutates TargetObject saved state; class parent clears gate; ItemWho precedent emits through direct class owner. | Direct file emitter and dual emitter would bypass/duplicate class route. | None for marker-level emission. |
| Callable helper C++ should not be emitted. | Strong | No route, no modeled function, active inline duplicate, raw decompile failure. | Body semantics are known, but source call surface is not. | Direct caller/pointer route or explicit retained-helper-body policy would be needed. |

## Ranked Ownership Analysis

### 1. `[UID:0000ED] TargetObjectWithKeyboardPane` - accepted direct owner/emitter

- Evidence for:
  - UID000410 reads/writes `s_targetObjectTargetId`, the TargetObject saved target slot.
  - It sits between TargetObject-specific modeled helpers `[UID:00036S]` and `[UID:00036U]`.
  - Active TargetObject key handler `[UID:0001LK]` contains the equivalent self-target branch.
  - Class page `[UID:0000ED]` clears the 85/85 gate and already routes to `[UID:0000OH]`.
  - ItemWho precedent uses the direct class owner/emitter for the covered-by marker.
- Evidence against:
  - The raw helper takes no `this` pointer, so it is not an ordinary non-static instance method.
- Decision:
  - Keep `CANONICAL_OWNER:0000ED`; set `EMITTER_UIDS:0000ED` for marker emission. Treat source shape as class-family static/file-local support under the TargetObject source family, but do not emit a callable helper body.

### 2. `[UID:0000OH] TargetSelectionInputPanes` - accepted source file route, rejected direct child emitter

- Evidence for:
  - The target-selection input pane source file owns the broader source module and is the generated output root.
  - `[UID:0000ED]` emits through this file.
- Evidence against:
  - UID000410's direct behavior belongs to TargetObject state, not to a file-level standalone source item.
  - Direct file emission would bypass the established class owner and duplicate the class route.
- Decision:
  - Update `[UID:0000OH]` as support context. Do not put `0000OH` directly in UID000410's `EMITTER_UIDS`.

### 3. `[UID:0001LK] TargetObjectWithKeyboardPaneKeyboardEvent` - accepted covered-by target, rejected owner

- Evidence for:
  - Active vtable-routed handler implements equivalent self/local-player branch inline.
  - It is the only exact active behavior page that should cover generated-source output for the self-target path.
- Evidence against:
  - It does not own the raw bytes at `0x005b06b0`; it is not a parent in the by-structure sense.
- Decision:
  - Use UID0001LK only in the formal covered-by marker and support relationship note.

### 4. `MapPane`, `UserPane`, or `LivingObjectPane` - rejected owners

- Evidence for:
  - UID000410 calls MapPane lookup, consumes `g_pUserPane` as local-player object, and calls LivingObjectPane highlight setter.
- Evidence against:
  - None of those dependencies owns the saved target state. They are callees/data providers, not declaration owners.
- Decision:
  - Keep as dependency/source-facing name support only.

## Source Placement

Recommended placement is TargetObject class-family support inside `TargetSelectionInputPanes.cpp`:

- Direct semantic owner: `[UID:0000ED] TargetObjectWithKeyboardPane`.
- Generated source route: `[UID:0000OH] TargetSelectionInputPanes`.
- Formal coverage target: `[UID:0001LK] TargetObjectWithKeyboardPaneKeyboardEvent`.
- Final source shape for this exact page: marker-only, not a helper declaration/body.

This placement is consistent with:

- TargetObject constructor, key handler, mouse handler, object-list helper, clear helper, raw navigation helpers, and dispatch helper using the same `s_targetObjectTargetId` state.
- The accepted ItemWho raw-helper marker pattern.
- The existing class/file source-tree route.

## Range / Split / Padding / Reclassification Analysis

No new split is recommended. UID000410 is already the exact child:

- Previous sibling body `[UID:00040Z]` ends at `0x005b06a8`.
- `0x005b06a8-0x005b06b0` is eight `0xcc` bytes.
- UID000410 executable body is `0x005b06b0-0x005b06ef`.
- `0x005b06ef-0x005b06f0` is one `0xcc` byte.
- Successor `[UID:00036U]` starts as modeled `sub_5B06F0`, size `0x8a`.

Parent `[UID:00036T]` remains a non-reconstructable/non-emitting split container. If this report is accepted, that parent should be updated to say UID000410 emits a covered-by marker while siblings UID00040Y and UID00040Z remain blank under the older retained-helper-body policy.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested or allowed for this assignment.

If a future IDA-maintenance pass is explicitly authorized, a comment on `0x005b06b0` could say that it is a retained TargetObject self-target helper with no xrefs and active behavior covered by `sub_5B0010`. Do not create functions, rename symbols, apply types, or add comments as part of this B003 report-only task.

Source-facing documentation names to preserve:

| Binary item | Source-facing role |
| --- | --- |
| `dword_69BF2C` / `unk_69BF2C` | `s_targetObjectTargetId` / `s_targetObjectSavedTargetId` |
| `dword_67A764` | `g_activeMapPane` |
| `dword_67A748` | `g_pUserPane` / local-player object view |
| `0x00506970` | `MapPane::FindObjectPaneById` |
| `0x0053b1b0` | `LivingObjectPane::SetTargetHighlight(bool)` |
| object offset `+0xfc` | object id / `GetObjectId()` role |

## First-Draft C++ Recommendation

Eligible for formal C++ after this report: yes, but marker-only. The target is reconstructable, will have a nonblank emitter route through `[UID:0000ED]`, and the combined score after implementation is `88.5`. The formal content must be a no-code covered-by marker, not a helper implementation.

Exact formal target content to insert:

```cpp
// Emitted code for this range is covered by [UID:0001LK].
```

Keep the inline header value blank:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Reason helper-body C++ remains unsafe:

- The raw start is not an IDA function.
- There is no direct call/jump/data/immediate/VA/RVA route to `0x005b06b0`.
- The active vtable-routed key handler already implements the same behavior inline.
- Exact original helper declaration, helper name, and retention shape are not recoverable.
- Emitting a callable helper body would either duplicate active behavior or imply a source call surface not proven by the binary.

Reason the marker is safe:

- It does not add behavior.
- It gives generated output a nonblank, traceable representation for the retained raw range.
- It points to the exact active page that covers the behavior.
- It follows accepted project precedent from `[UID:0002S5]`.

## Recommended Target Doc Changes

Target path: `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`.

Apply these details after supervisor callback:

- Metadata:
  - `COMPLETION:85 -> 88`.
  - `CONFIDENCE:88 -> 89`.
  - Keep `CANONICAL_OWNER:0000ED`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - `EMITTER_UIDS: -> 0000ED`.
  - Keep `EMITTER_POSITION_OPTIONAL:` blank.
  - Keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank.
  - Insert only `// Emitted code for this range is covered by [UID:0001LK].` in the multiline formal block.
- Item summary:
  - Replace the no-formal-cpp wording with marker/covered-by wording.
  - Mention B003 current MCP session `agent_b009_0002my_20260628`, exact no-route proof, active key-handler coverage, and target state update.
- Status / Formal C++ policy:
  - Replace "blank until route/policy" with "formal marker covered by UID0001LK; no callable helper body until a real route or retained-helper-body policy appears."
- Evidence:
  - Add the MCP function/boundary facts, exact instruction facts, route-negative table, `0x0069bf2c` xref details for `0x5b06b7` and `0x5b06e8`, and active key-handler comparison.
- No-code proof:
  - Convert to "No-Code Proof / Covered-By Marker" and preserve rejected alternatives: callable helper body, direct file emitter, clearing reconstructable, MapPane/UserPane/LivingObjectPane owner, and treating UID0001LK behavior match as caller proof.
- Changes:
  - Add a B003 2026-06-28 source-quality report entry with before/after score, emitter/marker disposition, and current MCP evidence.

Suggested replacement summary:

```text
0x005b06b0-0x005b06ef | retained raw helper | SelectLocalPlayerTargetObject : reconstructable/covered-by-marker : 88% : strong : B003 live MCP session `agent_b009_0002my_20260628` reconfirmed the unmodeled raw start, exact local-player retarget behavior, `s_targetObjectTargetId` reads/writes at `0x5b06b7`/`0x5b06e8`, zero xref/code/data/immediate/VA/RVA route to `0x005b06b0`, and active inline coverage by `[UID:0001LK]`; emits only `// Emitted code for this range is covered by [UID:0001LK].`.
```

## Recommended Support Doc Changes

### `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`

- Update the covered raw bodies table row for UID000410 to say "reconstructable raw child, emits covered-by marker to `[UID:0001LK]`" rather than "blank emitter/C++."
- Update the no-code proof to preserve the parent container no-code disposition while noting UID000410's marker-only exception. Keep UID00040Y and UID00040Z blank unless separately accepted.
- Add B003 live MCP current-route evidence for UID000410 and a note that B014's earlier PE/Capstone findings are now rechecked by current IDA MCP for this child.
- No metadata change required for the parent container.

### `by-class/TargetObjectWithKeyboardPane.md`

- Update the method/helper row for the target navigation raw helper split:
  - Parent UID00036T remains a non-emitting container.
  - UID000410 now emits a formal marker covered by UID0001LK.
  - UID00040Y and UID00040Z remain retained blank children.
- Add evidence note that B003 live MCP `agent_b009_0002my_20260628` found no direct route to UID000410 but confirmed the active self-target branch in UID0001LK.
- Keep class score unchanged at `87/88`; class-level C++ remains declaration/header work.

### `by-file/TargetSelectionInputPanes.md`

- Update the TargetObject source-route row and raw-helper table/changes:
  - UID000410 emits only a formal covered-by marker to UID0001LK.
  - UID000410 should route through direct class emitter UID0000ED, while the file UID0000OH remains the source output route through the class.
  - Do not say all TargetObject raw children are blank after implementation; say previous/next siblings remain blank while local-player child uses the marker.
- Add a short comparison to the accepted ItemWho `[UID:0002S5]` covered-by marker precedent.
- No file score change required.

### `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`

- Add a relationship/reconstruction note that UID0001LK is the formal covered-by target for UID000410's retained self/local-player raw helper.
- Preserve that UID000410 is not called by this handler; the relationship is inline behavior coverage, not caller proof.
- No score change required.

### Already Sufficient / No Edit Required

- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`: already documents UID000410 raw-helper use of `s_targetObjectTargetId`.
- `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`: already documents UID000410 as a consumer of `g_activeMapPane`.
- `by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md`: already documents UID000410 as a local-player/UserPane consumer and source-facing `g_pUserPane`.
- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`: already documents `MapPane::FindObjectPaneById`, `FindPreviousSelectableObject`, and `FindNextSelectableObject`.
- `auto-generated/*`, `project-level/*`, and manual `-coverage-report.md` files: do not edit manually.

## Score And Metadata Recommendation

Current:

```text
COMPLETION:85
CONFIDENCE:88
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
RECONSTRUCTION_CPP: blank
```

Recommended:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000ED
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ED
RECONSTRUCTION_CPP multiline marker:
// Emitted code for this range is covered by [UID:0001LK].
```

Why higher than current:

- Adds current live MCP proof rather than relying on old B014 offline PE/Capstone evidence.
- Resolves the empty-emitter disposition with exact formal marker content.
- Confirms target body, boundaries, saved target state refs, active inline key-handler equivalence, and all checked negative route forms.
- Aligns target policy with accepted ItemWho raw-helper marker precedent.

Why not higher:

- No direct route to `0x005b06b0` exists in current MCP evidence.
- IDA still does not model `0x005b06b0` as a function.
- Original helper spelling and whether the original source kept this as file-static, private static, or dead retained helper code cannot be proven.
- Callable helper-body C++ remains unsafe.

## Open Questions With Attempted Resolution

- Should UID000410 have blank `EMITTER_UIDS`?
  - Resolution: no. With a formal covered-by marker, `EMITTER_UIDS:0000ED` is justified and avoids the reconstructable empty-emitter state without inventing helper code.
- Should UID000410 emit through `[UID:0000ED]`, `[UID:0000OH]`, or both?
  - Resolution: emit through `[UID:0000ED]` only. `[UID:0000OH]` remains the generated source route through the class, not a direct child emitter.
- Is a covered-by marker correct?
  - Resolution: yes. UID0001LK has active vtable reachability and implements the same self-target behavior inline. The marker is generated traceability, not caller proof.
- Can a retained raw helper body receive first-draft callable C++?
  - Resolution: no for this assignment. All current route forms are negative, and source call surface is unrecovered.
- Does the active keyboard handler call the raw helper?
  - Resolution: no. MCP found no route to the raw start; the handler duplicates the logic inline.
- Do target-selection global/helper names need new source names?
  - Resolution: no new names. Current support docs already support `s_targetObjectTargetId`, `g_activeMapPane`, `g_pUserPane`, `MapPane::FindObjectPaneById`, and `LivingObjectPane::SetTargetHighlight(bool)`.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual coverage-report or tracker text is required. The implementation should update source by-* docs and rely on scoped validator/generated refreshes. Do not manually edit:

- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `by-memory/-coverage-report.md`
- generated C++ under `auto-generated/NexusTK/**`

## Validators Expected After Implementation Callback

No validators were run in this report-only pass because no by-* docs were edited.

Expected implementation validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality-removed.md](000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the target validator with `--wait-generated`, inspect `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` only as generated output. Expected generated result: UID000410 should surface with the marker comment and no longer be absent from generated output because of blank `EMITTER_UIDS`; it must not appear as an `Empty Emitter Marker` for this target.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B003/research/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md`

Modified:

- None outside B003's research folder.

Leases:

- None used; report-only research in own folder does not require leases.

Validator results:

- None run; no by-* files were edited.

## Final Recommendation

Implement the covered-by-marker disposition:

1. Update UID000410 metadata to `88/89`, `EMITTER_UIDS:0000ED`.
2. Add formal marker `// Emitted code for this range is covered by [UID:0001LK].`.
3. Preserve no callable helper-body C++.
4. Update UID00036T, UID0000ED, UID0000OH, and UID0001LK so the docs explain current MCP route-negative proof, active inline coverage, and why UID000410 is marker-only.
5. Do not change sibling raw helpers UID00040Y/UID00040Z in this callback except where support docs need to distinguish their still-blank state from UID000410's marker state.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation.
  - Proof: supervisor accepted this report and issued the implementation callback through `tools/leaser/Agents/Agent-B003/goal.md`; no by-* docs were edited during the report-only phase.
- [x] Target doc `by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md`: apply metadata `85/88 -> 88/89`, `EMITTER_UIDS: -> 0000ED`, item summary update, B003 MCP evidence, route-negative table, active key-handler coverage, and no-code/covered-by proof.
  - Proof: target header now has `COMPLETION:88`, `CONFIDENCE:89`, `EMITTER_UIDS:0000ED`, retained `CANONICAL_OWNER:0000ED`, retained `RECONSTRUCTABLE:TRUE`, and updated item summary/status/no-code sections. The doc now records B003 MCP endpoint `http://127.0.0.1:13337/mcp`, server `ida-pro-mcp` `1.0.0`, session `agent_b009_0002my_20260628`, IDB/input paths, no-function/no-xref/no-code-ref/no-data-ref/no-immediate/no-VA/RVA-pointer proof for `0x005b06b0`, neighbor controls `0x005b05b0`/`0x005b06f0`/`0x005b0010`, saved-target xrefs, and active UID0001LK coverage.
- [x] Target doc formal C++: keep inline `RECONSTRUCTION_CPP CODE:[[[]]]` blank and insert exactly `// Emitted code for this range is covered by [UID:0001LK].` between `RECONSTRUCTION_CPP CODE:BEGIN/END`.
  - Proof: inline `RECONSTRUCTION_CPP CODE:[[[]]]` remains blank, and after the full validator link-expanded the marker, the formal block was restored to the exact accepted line. Follow-up UID-only validator `command_id 000000000196`, timestamp `2026-06-28T23:17:13-04:00`, returned `ok: 1` with generated refresh skipped.
- [x] Parent doc `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`: update UID000410 row and no-code proof to reflect marker-only emission to UID0001LK while UID00040Y/UID00040Z remain blank.
  - Proof: parent status/table/no-code proof now distinguish UID000410 as the marker-only exception covered by UID0001LK, while UID00040Y and UID00040Z remain blank-emitter/no-code. It also preserves current MCP no-route proof, bytes, neighboring positive controls, active inline coverage, and ItemWho marker precedent.
- [x] Class doc `by-class/TargetObjectWithKeyboardPane.md`: update method/helper row and evidence notes with UID000410 marker-only disposition, current MCP no-route proof, and active inline coverage; no score change.
  - Proof: class method row and evidence notes now state UID000410 directly emits through UID0000ED as marker-only to UID0001LK, with score unchanged at `87/88`, class-level C++ blank, UID00040Y/UID00040Z still blank, and rejected owner/emitter alternatives preserved.
- [x] File doc `by-file/TargetSelectionInputPanes.md`: update TargetObject raw-helper source-route wording so UID000410 is not described as blank; record direct emitter UID0000ED, indirect file route UID0000OH, and ItemWho marker precedent; no score change.
  - Proof: file role, TargetObject proposed-content row, findings, and changelog now say UID0000OH remains the indirect `TargetSelectionInputPanes.cpp` route while UID000410 directly emits through UID0000ED as a covered-by marker to UID0001LK. Score remains `89/85`, and the UID0002S5 ItemWho precedent is preserved.
- [x] Key-handler doc `by-memory/0x005b0010-0x005b01da.TargetObjectWithKeyboardPaneKeyboardEvent.md`: add relationship note that UID0001LK is the formal covered-by target for UID000410 and that this is inline coverage, not a caller route.
  - Proof: UID0001LK evidence notes now include the marker relationship, the no-route proof for `0x005b06b0`, the vtable data route at `0x0062f40c`, and the exact self/local-player branch operations at `0x005b0101` through `0x005b0147`.
- [x] Confirm already-sufficient support docs require no edits: target-selection saved globals, active MapPane singleton, UserPane/global storage, and MapPane lookup helper page.
  - Proof: no edits were made to [UID:0002AB] target-selection saved globals, [UID:0001OW] active MapPane singleton, [UID:0001OR] UserPane/global storage, or MapPane lookup helper pages. Existing docs already support the dependency facts; this callback only needed target/support relationship updates.
- [x] Preserve rejected alternatives and negative evidence: no helper-body C++, no direct UID0000OH emitter, no dual emitter, no MapPane/UserPane/LivingObjectPane ownership, no caller-proof wording, no IDA DB edits.
  - Proof: target/support docs now explicitly reject standalone `SelectLocalPlayerTargetObject` body C++, direct file-UID emission, dual emission, clearing reconstructable state, MapPane/UserPane/LivingObjectPane ownership, caller-proof wording, and IDA DB edits. No MCP write or IDA DB edit was performed.
- [x] Run scoped validators listed in `Validators Expected After Implementation Callback`, with `--wait-generated` on the target validator.
  - Proof: required validators returned `ok: 1`: target `command_id 000000000190`, timestamp `2026-06-28T23:15:25-04:00`, `--wait-generated`, generated refresh completed; parent `000000000191`, timestamp `2026-06-28T23:15:42-04:00`; class `000000000192`, timestamp `2026-06-28T23:15:48-04:00`; file `000000000193`, timestamp `2026-06-28T23:15:59-04:00`; key-handler `000000000194`, timestamp `2026-06-28T23:16:09-04:00`. Additional UID-only exact-marker check `000000000196`, timestamp `2026-06-28T23:17:13-04:00`, returned `ok: 1`.
- [x] Inspect generated `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp` after generated refresh only as output; confirm UID000410 surfaces with the covered-by marker and is not an `Empty Emitter Marker`.
  - Proof: generated file inspection after `000000000190` found line `827` `// UID:000410 | by-memory/0x005b06b0-0x005b06ef.TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper.md | Completion:88 | Confidence:89` and line `828` covered-by marker for UID0001LK. A targeted `Empty Emitter Marker` scan showed UID000410 is not an Empty Emitter Marker; later Empty Emitter Marker entries begin with other UIDs such as UID00006X at line `857`.
- [x] Do not edit generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, or IDA DB.
  - Proof: manual edits were limited to the five accepted by-* docs and this B003 research report checklist. Generated C++, generated/project-level metadata, and validator-owned files were touched only by the required validator `--apply`/generated-refresh side effects. No generated report, manual `-coverage-report.md`, lock file, or IDA DB was manually edited.
- [x] After implementation, update this checklist with checked items and proof for each accepted item before returning `FINISHED_IMPLEMENTATION`.
  - Proof: this checklist was updated after validators, generated-output inspection, and lease release. B003 leases were released successfully for all five by-* docs after the validator batch.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md","timestamp":"2026-06-28T23:26:43","uid":"000410"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/000410-TargetObjectWithKeyboardPaneSelectLocalPlayerTargetRawHelper-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000410"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
