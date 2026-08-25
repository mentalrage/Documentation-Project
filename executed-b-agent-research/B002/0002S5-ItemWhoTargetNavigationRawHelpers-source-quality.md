** TARGET-REPORT-UID:0002S5 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002S5 ItemWhoTargetNavigationRawHelpers Source-Quality Research

## Report Scope And Current Recommendation

- Assignment: original report `B002-report-0002S5-ItemWhoTargetNavigationRawHelpers-source-quality-20260627`; rejected-report amendment `B002-rework-report-0002S5-item-who-target-navigation-raw-helpers-20260627`.
- Target: `[UID:0002S5]` `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md`.
- Report-only output: this file only. No by-* target/support pages were edited.
- Current source target metadata: `COMPLETION: 85`, `CONFIDENCE: 88`, `RECONSTRUCTABLE: TRUE`, `CANONICAL_OWNER: 00006X`, `EMITTER_UIDS: 00006X`.
- Queue source metadata is stale: `auto-generated/-ag-research-tracker.md` still lists `80/86`, combined `83.0`, reconstructable `true`, reports `0`.
- Recommendation: keep the target as a reconstructable source-authored ItemWho raw-helper island owned/emitted by `[UID:00006X] ItemWhoInputPane`, keep the current single-container shape for this implementation pass, and raise the target to `88/89` after adding the current MCP negative route proof and the active key-handler inline-duplicate proof.
- Formal C++ / no-code recommendation: do not add callable helper C++ bodies. Insert the exact formal marker comment `// Emitted code for this range is covered by [UID:0002S2].` between the target `RECONSTRUCTION_CPP CODE:BEGIN/END` lines, and keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value blank. This satisfies the current nonblank-emitter/no-empty-marker policy without inventing unrecovered helper call surfaces.
- Preferred implementation disposition: keep `RECONSTRUCTABLE:TRUE`, keep `CANONICAL_OWNER:00006X`, keep `EMITTER_UIDS:00006X`, do not split or downgrade the page, and insert only the covered-by marker in the multiline formal block. This is not an optional supervisor-choice branch; it is the amendment's implementation-ready recommendation.

## MCP Availability And Session

IDA MCP was available and used. I did not start, stop, or restart IDA MCP.

- Host probe: `127.0.0.1:13337` accepted connections.
- JSON-RPC `initialize`: server `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`.
- Required `idb_list` refresh was run first. Current active IDB session: `b001_000241_20260627`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path reported by health check: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- `server_health`: `status=ok`, `module=NexusTK.exe`, `auto_analysis_ready=true`, `hexrays_ready=true`, `strings_cache_ready=true`.
- Current `idb_list` state: one active owned/adopted worker session, `is_analyzing=false`, `pid=23132`, `worker_pid=23132`.
- The previous report's session `875bf182` is now treated only as historical provenance; this amendment relies on `b001_000241_20260627`.

### 2026-06-27 23:14 EDT Current Amendment Recheck

This amendment was rechecked against the same live MCP worker immediately before final report return. The recheck did not start, stop, restart, or modify MCP/IDA.

- `Test-NetConnection 127.0.0.1 -Port 13337`: `TcpTestSucceeded=True`.
- JSON-RPC `initialize`: server `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`.
- JSON-RPC `tools/list`: confirmed current schemas for `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `find`, `find_bytes`, `insn_query`, `get_bytes`, `decompile`, and `callees`.
- `idb_list`: one active session, `b001_000241_20260627`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing=false`, worker `pid=23132`.
- `server_health`: `status=ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- `lookup_funcs` reconfirmed `0x005aedd0` as `sub_5AEDD0` size `0x1df`, `0x005af050` as `sub_5AF050` size `0x297`, `0x005af390` as `sub_5AF390` size `0x1f`, `0x005af4f0` as `sub_5AF4F0` size `0x8b`, and `0x005af580` as `sub_5AF580` size `0x6a`; raw starts `0x005af3b0`, `0x005af430`, and `0x005af4b0` still return `Not a function`.
- `xrefs_to` reconfirmed zero xrefs to starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`; `xrefs_to 0x0069bf24` still reports 30 refs, including raw-island refs at `0x005af3bb`, `0x005af416`, `0x005af420`, `0x005af43b`, `0x005af496`, `0x005af4a0`, `0x005af4b7`, and `0x005af4e8`.
- `find` reconfirmed zero `code_ref`, zero `data_ref`, and zero `immediate` matches for all three raw starts.
- `find_bytes` reconfirmed zero absolute VA pointer byte matches for `B0 F3 5A 00`, `30 F4 5A 00`, and `B0 F4 5A 00`, and zero imagebase-relative RVA pointer matches for `B0 F3 1A 00`, `30 F4 1A 00`, and `B0 F4 1A 00`.
- `insn_query 0x005af3b0-0x005af4f0` reconfirmed 108 decoded instructions/alignment entries with no containing function, preserving the previous/up, next/down, and local-player helper interpretation.
- `get_bytes` reconfirmed `0x005af3af=0xcc`, first raw bytes at `0x005af3b0` start `55 8B EC 8B 0D 64 A7 67 00 56 57 FF 35 24 BF 69`, and `0x005af4ef=0xcc`.
- `decompile 0x005aedd0` and `callees 0x005aedd0` reconfirmed that `[UID:0002S2]` already contains active inline self/previous/next ItemWho target navigation using `sub_506970`, `sub_506B80`, `sub_506AE0`, `sub_506BD0`, `sub_506B30`, `sub_53B1B0`, `dword_67A764`, `dword_67A748`, and `unk_69BF24`.

## Evidence Checked

Target and support by-* context checked:

- `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md`
- `by-class/ItemWhoInputPane.md`
- `by-file/TargetSelectionInputPanes.md`
- `by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md`
- `by-memory/0x005af050-0x005af2e7.ItemWhoInputPaneMouseInput.md`
- `by-memory/0x005afd50-0x005afe6f.SelectObjectWithKeyboardPaneNavigationRawHelpers.md`
- `by-memory/0x005b05d0-0x005b06ef.TargetObjectWithKeyboardPaneNavigationRawHelpers.md`
- `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`
- `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`
- `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`

Prior report context checked as support, not as a substitute for live MCP:

- B013 `0001L4-ItemWhoInputPane-source-quality.md`.
- B005 `0001L8-TargetSelectionInputPanes-source-quality.md`.
- B014 `00036T-TargetObjectWithKeyboardPaneNavigationRawHelpers-source-quality.md` was read only as current precedent/context. It reported MCP unavailability, so this report does not use it as hard proof for `0002S5`.

Current amendment MCP tools used against database `b001_000241_20260627`:

- `idb_list`, `server_health`, and `tools/list` before target evidence calls.
- `lookup_funcs` for `0x005aedd0`, `0x005af050`, `0x005af390`, `0x005af3b0`, `0x005af430`, `0x005af4b0`, `0x005af4f0`, and `0x005af580`.
- `insn_query` over `0x005af3b0-0x005af4f0`, returning 108 decoded instructions/align records and no containing function for the raw helper bodies.
- `decompile 0x005aedd0` and `callees 0x005aedd0` to recheck `[UID:0002S2] ItemWhoInputPaneKeyInput`.
- `xrefs_to`, `find type=code_ref`, `find type=data_ref`, `find type=immediate`, and `find_bytes` for raw starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`.
- `xrefs_to 0x0069bf24` and `get_bytes` for boundary/raw-byte confirmation.

## Live MCP Function And Boundary Facts

`lookup_funcs` around the target:

| Address | MCP result | Source-quality meaning |
|---|---|---|
| `0x005aedd0` | `sub_5AEDD0`, size `0x1df` | Modeled `ItemWhoInputPane` key handler before the raw island. |
| `0x005af050` | `sub_5AF050`, size `0x297` | Modeled `ItemWhoInputPane` mouse handler before the raw island. |
| `0x005af390` | `sub_5AF390`, size `0x1f` | Modeled clear-current-target helper immediately before the island. |
| `0x005af3b0` | Not a function | First raw helper start is not modeled as a function. |
| `0x005af430` | Not a function | Second raw helper start is not modeled as a function. |
| `0x005af4b0` | Not a function | Third raw helper start is not modeled as a function. |
| `0x005af4f0` | `sub_5AF4F0`, size `0x8b` | Next modeled ItemWho-related helper after one `cc` byte. |
| `0x005af580` | `sub_5AF580`, size `0x6a` | Next modeled ItemWho-related helper. |

Boundary byte checks:

- Byte at `0x005af3af`: `cc`.
- Bytes at `0x005af3b0` for `0x140` bytes contain the three helper bodies from `0x005af3b0` through `0x005af4ee`.
- Byte at `0x005af4ef`: `cc`.
- The target page range `0x005af3b0-0x005af4ef` is correct as an end-exclusive raw-code island ending before the trailing `cc` alignment byte. Future prose should consistently describe the second helper body as `0x005af430-0x005af4b0` end exclusive, not `0x005af430-0x005af4af`.

## Live MCP Instruction Facts

MCP instruction query over `0x005af3b0-0x005af4f0` confirms three compact helper bodies.

### Body 1: `0x005af3b0-0x005af430`

- Prologue: `push ebp; mov ebp, esp`.
- Reads active map pane from `dword_67A764`.
- Pushes `unk_69BF24` / `s_itemWhoTargetId` and calls `sub_506970` (`MapPane::FindObjectPaneById`).
- If a current target pane exists, selects a previous target:
  - `[ebp+8] != 0`: calls `sub_506B80`.
  - `[ebp+8] == 0`: calls `sub_506AE0`.
- If no current target pane exists, falls back to `dword_67A748` local-player object.
- Clears highlight on the old target with `sub_53B1B0(..., false)`.
- Sets highlight on the new target with `sub_53B1B0(..., true)`.
- Stores `[esi+0xfc]` into `unk_69BF24`.
- On no-target path, stores zero into `unk_69BF24`.
- Returns with `retn 4`.

Descriptive role: `SelectPreviousItemWhoTarget(bool useAlternateTraversal)` or `StepItemWhoTargetPrevious(bool alternateTraversal)`. The name is source-facing inference, not proven original spelling.

### Body 2: `0x005af430-0x005af4b0`

- Prologue: `push ebp; mov ebp, esp`.
- Reads active map pane from `dword_67A764`.
- Pushes `unk_69BF24` / `s_itemWhoTargetId` and calls `sub_506970`.
- If a current target pane exists, selects a next target:
  - `[ebp+8] != 0`: calls `sub_506BD0`.
  - `[ebp+8] == 0`: calls `sub_506B30`.
- If no current target pane exists, falls back to `dword_67A748` local-player object.
- Clears highlight on the old target, highlights the new target, and stores `[esi+0xfc]` into `unk_69BF24`.
- On no-target path, stores zero into `unk_69BF24`.
- Returns with `retn 4`.

Descriptive role: `SelectNextItemWhoTarget(bool useAlternateTraversal)` or `StepItemWhoTargetNext(bool alternateTraversal)`. The name is source-facing inference, not proven original spelling.

### Body 3: `0x005af4b0-0x005af4ef`

- No EBP frame.
- Reads active map pane from `dword_67A764`.
- Pushes `unk_69BF24` / `s_itemWhoTargetId`.
- Loads `dword_67A748` as the local-player object.
- Calls `sub_506970` to resolve the current saved target.
- If the saved target is not already the local-player object, clears old highlight, highlights local player, and stores `[esi+0xfc]` into `unk_69BF24`.
- Returns with plain `retn`.

Descriptive role: `SelectLocalPlayerItemWhoTarget()`. The name is source-facing inference, not proven original spelling.

## Direct Route And Xref Findings

The central source-quality blocker is not body interpretation. It is start reachability and source call-surface proof.

### Helper Start Queries

MCP route checks for starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`:

| Query | Result |
|---|---|
| `lookup_funcs` | All three starts are not IDA functions. |
| `xrefs_to` | Zero cross-references to all three starts. |
| `find type='code_ref'` | Count `0` for all three starts. |
| `find type='data_ref'` | Count `0` for all three starts. |
| `find type='immediate'` | Count `0` for all three starts. |
| `find_bytes` absolute VA pointers | No matches for `B0 F3 5A 00`, `30 F4 5A 00`, `B0 F4 5A 00`. |
| `find_bytes` imagebase-relative RVA pointers | No matches for `B0 F3 1A 00`, `30 F4 1A 00`, `B0 F4 1A 00`. |

### Saved Target Global Xrefs

`xrefs_to 0x0069bf24` returned 30 references. Relevant raw-island references are:

- `0x005af3bb`
- `0x005af416`
- `0x005af420`
- `0x005af43b`
- `0x005af496`
- `0x005af4a0`
- `0x005af4b7`
- `0x005af4e8`

Those references have no containing modeled function because IDA has not created functions for the raw helper starts. The same saved target global is also used by modeled ItemWho key, mouse, object-list, clear, and scalar-dtor pages, confirming state ownership but not start reachability.

## Positive Evidence

Evidence supporting `0002S5` as source-authored, reconstructable, and ItemWho-owned:

- The raw bytes decode into three normal helper-shaped bodies with standard traversal, highlight, target-id store, and return behavior. This is not padding, literal data, exception metadata, switch-table data, import glue, or CRT code.
- The island is bounded by `cc` alignment before `0x005af3b0` and at `0x005af4ef`, and by modeled neighboring functions at `0x005af390` and `0x005af4f0`.
- All three bodies operate on `0x0069bf24`, the ItemWho saved target slot documented by `[UID:0002AB] TargetSelectionSavedTargetGlobals`.
- The traversal callees match documented MapPane lookup/navigation helpers:
  - `0x00506970`: `MapPane::FindObjectPaneById`.
  - `0x00506ae0`: `MapPane::FindPreviousSelectableObject`.
  - `0x00506b30`: `MapPane::FindNextSelectableObject`.
  - `0x00506b80`: alternate previous/up traversal used by ItemWho navigation.
  - `0x00506bd0`: alternate next/down traversal used by ItemWho navigation.
- The highlight callee `0x0053b1b0` is used by the modeled ItemWho key/mouse/object-list/clear flows and by the raw island.
- The local-player fallback/retarget body uses `dword_67A748`, matching the active ItemWho key handler's self-targeting behavior.
- The modeled key handler `[UID:0002S2] ItemWhoInputPaneKeyInput` duplicates the same target navigation semantics inline:
  - previous path calls `0x00506b80` / `0x00506ae0`;
  - next path calls `0x00506bd0` / `0x00506b30`;
  - self path uses the local-player object and updates `s_itemWhoTargetId`;
  - all paths share the same target highlight idiom.
- `[UID:00006X] ItemWhoInputPane` already owns the surrounding key/mouse/object-list/clear/scalar ItemWho behavior and documents this raw island as an ItemWho helper group.
- `[UID:0000OH] TargetSelectionInputPanes` is the appropriate source-file route, with ItemWho as the direct class owner.
- `[UID:00048D] SelectObjectWithKeyboardPaneNavigationRawHelpers` remains useful precedent for keeping a same-owner raw navigation island as one container, but this amendment does not use its blank formal C++ state as policy authority because the current supervisor no-empty-marker rule requires an exact disposition for nonblank emitters.

## Negative Evidence

Evidence blocking higher confidence and callable helper C++:

- IDA does not model `0x005af3b0`, `0x005af430`, or `0x005af4b0` as functions.
- Live MCP found no code references, data references, immediates, absolute VA pointers, or imagebase-relative RVA pointers to any of the three starts.
- No vtable entry, function-pointer table, jump table, switch table, command dispatch array, or static callback route to the helper starts was recovered in this pass.
- The active key handler already implements equivalent self/previous/next behavior inline; there is no live caller proof that these raw helpers are the source implementation behind that behavior.
- Exact original source spellings are not proven. Proposed helper names must remain descriptive role aliases.
- There is no evidence that `MapPane`, `UserPane`, `SelectObjectWithKeyboard`, or `TargetObjectWithKeyboard` owns this island. Those systems provide callees or parallel precedent, while this island mutates the ItemWho saved-target slot.
- There is no evidence that aggregate `[UID:0000OH] TargetSelectionInputPanes` should become the direct owner/emitter. It should remain the source-file route, not the direct owner.
- There is no proof that splitting this island into three child pages would increase source fidelity now. The helper starts all share the same owner, target state, no-route blocker, and contiguous raw island context.

## Heuristic And Source-Quality Reanalysis

| Claim | Evidence class | Reanalysis |
|---|---|---|
| The bytes are source-authored helper code. | Direct MCP disassembly plus normal prologues/calls/returns. | Strong. Keep `RECONSTRUCTABLE: TRUE`. |
| The direct owner is `ItemWhoInputPane`. | Direct state usage plus surrounding modeled ItemWho methods. | Strong. Keep `CANONICAL_OWNER: 00006X`. |
| The source-file route is `TargetSelectionInputPanes`. | Support docs and neighboring target-selection classes. | Strong. Keep source route through `[UID:0000OH]`, but not as direct owner. |
| The helper body roles are previous, next, and local-player target selection. | Direct instruction behavior and key-handler comparison. | Strong for behavior; names remain inferred. |
| The `bool` parameter on the first two bodies selects alternate traversal. | Direct `[ebp+8]` branch choosing alternate/non-alternate MapPane traversal callees. | Strong for behavior; parameter name and original type are inferred. |
| The target should emit callable helper C++ now. | No caller/start route; active behavior already exists inline in key handler. | Not supported. Do not emit helper bodies or invented static declarations. |
| The target should have formal `RECONSTRUCTION_CPP` content despite no helper bodies. | Nonblank `EMITTER_UIDS: 00006X`, current no-empty-marker policy, and `[UID:0002S2]` already emits equivalent active key-handler behavior. | Supported. Insert the exact covered-by marker comment in the formal block. |
| The island should be split into child UIDs now. | Three bodies exist, but same owner/state/blocker, contiguous no-internal-padding range, and `[UID:0002S2]` covers the active emitted behavior. | Not required. Keep single container for this implementation callback. |
| Current `85/88` target page score is complete enough. | Core facts are right, but the target page still lacks the current MCP route proof and exact covered-by marker proof. | Improve to `88/89` after implementation. |

## Inference Claim Ledger

| Item | Recommended wording | Quality |
|---|---|---|
| `dword_69BF24` | `s_itemWhoTargetId` / `s_itemWhoSavedTargetId`; legacy alias `g_savedItemWhoTargetObjectId` acceptable in historical notes. | Direct support-page and MCP xref evidence. |
| `dword_67A764` | `g_activeMapPane`. | Direct support-page evidence; used as active MapPane pointer. |
| `dword_67A748` | local-player object pointer / `g_pCollectionData` consumer context. | Strong behavioral evidence; exact source-facing global name should follow existing support docs. |
| `0x00506970` | `MapPane::FindObjectPaneById`. | Support-page evidence. |
| `0x00506ae0` | `MapPane::FindPreviousSelectableObject`. | Support-page evidence. |
| `0x00506b30` | `MapPane::FindNextSelectableObject`. | Support-page evidence. |
| `0x00506b80` | `MapPane::FindPreviousSelectableObjectAlternate` / item-target previous/up traversal. | Strong descriptive alias; exact original name inferred. |
| `0x00506bd0` | `MapPane::FindNextSelectableObjectAlternate` / item-target next/down traversal. | Strong descriptive alias; exact original name inferred. |
| `0x0053b1b0` | `LivingObjectPane::SetTargetHighlight(bool)` or current accepted local equivalent. | Strong use-pattern evidence; final spelling should match existing docs. |
| object `+0xfc` | object id / `ObjectId()`. | Strong use-pattern evidence. |

## Ranked Owner And Source-Disposition Analysis

| Rank | Candidate | Recommendation | Reason |
|---|---|---|---|
| 1 | `[UID:00006X] ItemWhoInputPane` | Keep canonical owner and current emitter route. | The island mutates ItemWho saved-target state, matches ItemWho key-handler semantics, and sits among ItemWho methods. |
| 2 | `[UID:0000OH] TargetSelectionInputPanes` | Keep as source-file route/support context only. | This is the file-level aggregation route, not the direct behavioral owner. |
| 3 | `[UID:00037Q] MapPaneObjectLookupHelpers` / MapPane | Reject as owner. | MapPane provides traversal callees; the island consumes them for ItemWho state. |
| 4 | `[UID:0000CT] SelectObjectWithKeyboardPane` / `[UID:0000ED] TargetObjectWithKeyboardPane` | Reject as owner. | Similar raw-helper pattern, different saved-target globals and owner classes. |
| 5 | No owner / compiler artifact | Reject. | The bodies are coherent source-authored target-selection helper code. |

Emitter disposition:

- Implementation-ready recommendation: keep `EMITTER_UIDS: 00006X` and add this exact formal marker comment between the target `RECONSTRUCTION_CPP CODE:BEGIN/END` lines:

```cpp
// Emitted code for this range is covered by [UID:0002S2].
```

- Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` header value blank.
- Do not clear `EMITTER_UIDS`: the raw island is source-authored ItemWho behavior, the owner/emitter route is valid, and the current blocker is only the lack of a direct helper-start call surface.
- Do not mark `RECONSTRUCTABLE:FALSE`: unlike the broad `[UID:0001L4]` parent, this page covers executable source-authored helper bodies, not an index over unrelated exact children or padding.
- Do not emit callable helper bodies yet: the helper starts still have no recovered call/jump/pointer/vtable route, and adding named helpers would invent an unproven source surface.

## Range, Split, And Reclassification Analysis

Recommended shape for this pass: keep `[UID:0002S5]` as one raw-helper island container.

Reasons:

- The island is contiguous from `0x005af3b0` through `0x005af4ee`.
- The trailing `0x005af4ef` byte is `cc` alignment before the modeled `0x005af4f0` function.
- The three helper starts share the same direct owner, saved-target global, MapPane/highlight dependencies, and no-direct-route blocker.
- There is no internal `cc` padding separating the helper bodies.
- Creating three new child pages would improve body granularity but would not solve the source-call-surface or C++ blocker.
- `[UID:00048D] SelectObjectWithKeyboardPaneNavigationRawHelpers` is a same-owner single-container precedent for raw-helper-island shape, but its blank formal C++ state should not be copied for this target under the current no-empty-marker rule.

Rejected-for-now split alternative:

- Child 1: `0x005af3b0-0x005af430`, previous/up ItemWho target traversal.
- Child 2: `0x005af430-0x005af4b0`, next/down ItemWho target traversal.
- Child 3: `0x005af4b0-0x005af4ef`, local-player ItemWho retarget helper.
- Padding: `0x005af4ef-0x005af4f0`, one `cc` byte outside helper code.

This split is a rejected alternative for the current implementation callback. It would add bookkeeping but would not recover a call surface, would create three separate no-route/no-code children, and would not improve over the exact single formal covered-by marker on the current container.

## First-Draft C++ / No-Code Proof

No callable helper-body C++ should be added to `[UID:0002S5]` in the next implementation pass. The target should still receive exact formal `RECONSTRUCTION_CPP` content because it is reconstructable, has `EMITTER_UIDS:00006X`, and the active emitted behavior is already represented by `[UID:0002S2]`.

Exact formal content to insert between the target page's `RECONSTRUCTION_CPP CODE:BEGIN/END` lines:

```cpp
// Emitted code for this range is covered by [UID:0002S2].
```

Keep the inline header value as:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Proof:

- Current MCP `lookup_funcs` reports `[UID:0002S2]` `0x005aedd0` as `sub_5AEDD0`, size `0x1df`, and reports raw starts `0x005af3b0`, `0x005af430`, and `0x005af4b0` as `Not a function`.
- Current MCP route checks found zero `xrefs_to`, zero `code_ref`, zero `data_ref`, zero `immediate`, and zero absolute-VA/RVA pointer byte matches for all three raw starts.
- Current MCP `insn_query` over `0x005af3b0-0x005af4f0` confirms the raw island implements previous/up, next/down, and local-player ItemWho retargeting using `dword_69BF24`, `dword_67A764`, `dword_67A748`, traversal callees `0x00506b80`/`0x00506ae0`/`0x00506bd0`/`0x00506b30`, highlight callee `0x0053b1b0`, and object id offset `+0xfc`.
- Current MCP `decompile 0x005aedd0` confirms `[UID:0002S2] ItemWhoInputPaneKeyInput` contains the active self/previous/next implementation inline: self target uses `dword_67A748`, clears old highlight, highlights local player, and stores `unk_69BF24`; previous/up uses `sub_506B80` or `sub_506AE0` according to modifier bit `0x04`; next/down uses `sub_506BD0` or `sub_506B30`; the shared tail clears old highlight, highlights the new target, stores `[new+0xfc]`, or writes zero.
- Current MCP `callees 0x005aedd0` returns the same dependency family needed by the raw island: `sub_506970`, `sub_506B80`, `sub_506AE0`, `sub_506BD0`, `sub_506B30`, `sub_53B1B0`, plus key-handler-specific `std::ctype<char>::do_narrow`, `sub_5AF390`, `sub_5AF580`, and `sub_4F25A0`.
- The raw helper bodies are therefore behaviorally covered by the active key handler for generated-source purposes, but they are not proven callable source helpers. Adding `SelectPreviousItemWhoTarget`, `SelectNextItemWhoTarget`, or `SelectLocalPlayerItemWhoTarget` bodies would invent declarations/call sites not recovered from the checked binary.
- The formal covered-by comment is a no-code marker, not a helper-body implementation. It prevents a plain blank emitted target while preserving exact traceability to the source page that carries the active emitted behavior.

## Score And Metadata Recommendation

Target page after accepted implementation:

- `COMPLETION`: `85 -> 88`.
- `CONFIDENCE`: `88 -> 89`.
- `RECONSTRUCTABLE`: keep `TRUE`.
- `CANONICAL_OWNER`: keep `00006X`.
- `EMITTER_UIDS`: keep `00006X`.
- `EMITTER_POSITION_OPTIONAL`: keep blank.
- Inline `RECONSTRUCTION_CPP CODE:[[[]]]`: keep blank.
- `C++`: insert only `// Emitted code for this range is covered by [UID:0002S2].` in the formal multiline block; do not add callable helper bodies.

Why not higher than `88/89`:

- Body semantics and owner/source route are strong.
- The missing start route remains a material source-quality limitation.
- Exact original names and source helper shape are not proven.
- Callable helper C++ remains unsafe; the covered-by marker is safe because `[UID:0002S2]` already carries the active emitted behavior.

Why higher than current `85/88`:

- This pass adds live MCP-backed negative route checks across xrefs, code refs, data refs, immediates, and VA/RVA pointer byte patterns.
- It confirms exact instruction-level body behavior and range boundaries.
- It resolves the no-code blocker with exact formal marker content rather than a plain blank emitted block.
- It reconciles stale generated tracker/coverage data with the current target page.

## Recommended Target Page Edits For Implementation Callback

Do not perform these edits until supervisor validation and implementation callback.

Target: `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md`

- Update the item summary to mention B002 current MCP session `b001_000241_20260627`, zero direct route evidence for all three starts, exact helper roles, key-handler inline duplicate, and the formal covered-by marker.
- Add a `B002 source-quality amendment` section or equivalent.
- Add a direct `Reachability And Negative Route Evidence` subsection listing:
  - zero `xrefs_to` for `0x005af3b0`, `0x005af430`, `0x005af4b0`;
  - zero code/data/immediate refs;
  - zero absolute VA pointer byte matches;
  - zero imagebase-relative RVA pointer byte matches.
- Add a `No-Code Proof / Covered-By Marker` subsection with the proof above.
- Insert this exact formal content between `RECONSTRUCTION_CPP CODE:BEGIN/END`:

```cpp
// Emitted code for this range is covered by [UID:0002S2].
```

- Keep the inline `RECONSTRUCTION_CPP CODE:[[[]]]` value blank.
- Correct second body wording to `0x005af430-0x005af4b0` end exclusive.
- Keep the single-island container and document rejected split alternative only if useful.
- Update metadata to `88/89` after the evidence is incorporated.

Suggested replacement summary text:

> B002 MCP session `b001_000241_20260627` reconfirmed the three unmodeled ItemWho target-navigation raw helpers, no code/data/immediate/VA/RVA route to starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`, exact `s_itemWhoTargetId` updates, MapPane traversal/local-player fallback/highlight behavior, and the formal covered-by marker tying emitted behavior to `[UID:0002S2]`.

## Recommended Support Doc Edits For Implementation Callback

Do not perform these edits until supervisor validation and implementation callback.

Recommended support updates:

- `by-class/ItemWhoInputPane.md`
  - Update the `0002S5` method/raw-helper row to mention B002's no-route proof, that the active key handler already implements equivalent behavior inline, and that `0002S5` uses a formal covered-by marker rather than callable helper C++.
  - No class score change required.
- `by-file/TargetSelectionInputPanes.md`
  - Update stale wording that describes the ItemWho raw helper as missing active owner.
  - State that direct owner is `[UID:00006X] ItemWhoInputPane`, source route is `[UID:0000OH] TargetSelectionInputPanes`, and `0002S5` emits only the covered-by marker because `[UID:0002S2]` carries the active inline behavior while raw helper starts have no direct route.
  - No score change required.
- `by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md`
  - Add a relationship note that this key handler contains the active inline implementation equivalent to `0002S5`'s self/previous/next raw helper behavior and is the formal covered-by target for `0002S5`.
  - No score change required.
- No edit is required for `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`; the target page already preserves the reconfirmed raw-island `s_itemWhoTargetId` refs, and this amendment does not change the saved-global ownership/name.

Generated files and reports:

- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, generated C++ files, generated reports, or any `-coverage-report.md` files.
- After accepted by-* edits and validator runs, generated tracker/coverage output should refresh from the source pages. Current generated entries remain stale at `80/86` and should no longer depend on an empty-emitter marker once the formal covered-by comment is inserted.

## Validators To Run After Implementation Callback

No validators were run in this report-only pass because no by-* docs were edited.

Expected validator commands after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002S5-ItemWhoTargetNavigationRawHelpers-source-quality-removed.md](0002S5-ItemWhoTargetNavigationRawHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated freshness matters to the supervisor callback, run the project-approved generated refresh path after source validators complete. Do not hand-edit generated outputs.

Implementation callback validator results:

- Target validator: `command_id: 000000004769`, `command_timestamp: 2026-06-27T23:14:12-04:00`, `ok: 1`, `autogen_cpp_update: 2`, `autogen_registry_update: 4`, `research_tracker_update: 1`, `projected_stats_update: 1`, `memory_auto_coverage_update: 1`, `generated_refresh: completed`.
- Class support validator: `command_id: 000000004771`, `command_timestamp: 2026-06-27T23:14:30-04:00`, `ok: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- File support validator: `command_id: 000000004774`, `command_timestamp: 2026-06-27T23:14:41-04:00`, `ok: 1`, `uid_link_insert: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- Key-handler support validator: `command_id: 000000004777`, `command_timestamp: 2026-06-27T23:14:50-04:00`, `ok: 1`, `projected_stats_update: 1`, `generated_refresh: deferred`.
- Final target exact-marker checks: target `--uid-only --no-generated-refresh` command `000000004785` returned `ok: 1` after the full validator auto-expanded the formal marker UID into a Markdown link; target `--uid-only --wait-generated` command `000000004786` returned `ok: 1` but skipped generated refresh because `--uid-only` disables it; validator-owned autogen command `000000004787` then returned `generated_refresh: completed`, `autogen_cpp_update: 1`, `research_tracker_update: 1`, and `memory_auto_coverage_update: 1`. The final target formal block and generated `TargetSelectionInputPanes.cpp` block both contain the accepted exact marker text.
- Target run included the required `--wait-generated` and completed generated refresh. Known unrelated stale/missing registry and by-memory coverage metadata warnings were emitted during the generated refresh, but the scoped target validation completed with `ok: 1`.

## Open Questions And Attempted Resolution

- Why do the raw helper starts exist with no references?
  - Attempted resolution: direct xrefs, code/data refs, immediates, and VA/RVA pointer bytes were searched and all were negative. The safest documentation answer is retained/source-authored raw helper code with no recovered source call surface.
- Should this be split into three child UIDs?
  - Attempted resolution: body boundaries are clear, but same owner/state/no-route context, no internal padding, and the formal covered-by marker support keeping one container now. Splitting is rejected for this implementation callback because it would create three no-route children without improving emitted source fidelity.
- Should `EMITTER_UIDS` be cleared because callable helper C++ remains unsafe?
  - Attempted resolution: no. Keep `EMITTER_UIDS:00006X` because the raw island is source-authored ItemWho behavior with a valid class/file route. The blank-block problem is resolved by the exact covered-by marker, not by metadata downgrade.
- Can exact original helper names be recovered?
  - Attempted resolution: no direct source route or symbol evidence was found. Use descriptive aliases only.

## Report-Only Changed Files

Amended:

- `tools/leaser/Agents/Agent-B002/research/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md`

No leases were requested or used for this report-only pass.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validated this B002 source-quality report. Proof: user callback stated the amended report was accepted for implementation.
- [x] Supervisor issued an implementation callback before any by-* target/support docs were edited. Proof: user callback authorized applying the accepted report details to the target/support by-* docs for `[UID:0002S5]`.

Target implementation callback:

- [x] Updated `by-memory/0x005af3b0-0x005af4ef.ItemWhoTargetNavigationRawHelpers.md` with B002 MCP session evidence. Proof: target section `2026-06-27 B002 Source-Quality Implementation` records MCP session `b001_000241_20260627`, health, function lookup, route checks, instruction evidence, and key-handler duplicate evidence.
- [x] Added direct negative route proof for starts `0x005af3b0`, `0x005af430`, and `0x005af4b0`. Proof: target B002 section states zero `xrefs_to`, zero code refs, zero data refs, zero immediate refs, zero absolute VA pointer byte hits, and zero imagebase-relative RVA pointer byte hits.
- [x] Added the formal no-code/covered-by proof and inserted exactly `// Emitted code for this range is covered by [UID:0002S2].` between the target `RECONSTRUCTION_CPP CODE:BEGIN/END` lines. Proof: target header multiline block contains only that marker; final target `--uid-only` validator command `000000004785` returned `ok:1` after restoring the marker from the full validator's UID-link expansion, and autogen command `000000004787` refreshed generated C++ with the same exact marker.
- [x] Kept the target inline `RECONSTRUCTION_CPP CODE:[[[]]]` value blank. Proof: target header still has `*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***`.
- [x] Corrected second-body range wording to `0x005af430-0x005af4b0` end exclusive. Proof: target active `Covered Raw Bodies`, B002 evidence, and changed-to line use `0x005af430-0x005af4b0`; the stale `0x005af430-0x005af4af` spelling remains only in the historical `Before` changelog proof.
- [x] Kept single-container raw-helper island shape; no child pages were created in this callback. Proof: target remains `[UID:0002S5]` covering `0x005af3b0-0x005af4ef`, and no new child page paths were added.
- [x] Updated target score to `88/89`. Proof: target header is `COMPLETION:88` and `CONFIDENCE:89`.
- [x] Confirmed target metadata/header state exactly: `COMPLETION:88`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006X`, blank `EMITTER_POSITION_OPTIONAL`, blank inline `RECONSTRUCTION_CPP CODE:[[[]]]`, and multiline formal block containing only `// Emitted code for this range is covered by [UID:0002S2].`. Proof: post-correction target `--uid-only` validator command `000000004785` returned `ok:1`, and generated refresh command `000000004787` preserved the exact marker in `auto-generated/NexusTK/ui/dialogs/TargetSelectionInputPanes.cpp`.
- [x] Did not clear `EMITTER_UIDS`, mark `RECONSTRUCTABLE:FALSE`, create child pages, or add callable helper-body C++ for this accepted callback. Proof: target metadata is unchanged for owner/reconstructable/emitter, and formal C++ is the single marker comment.

Support implementation callback:

- [x] Updated `by-class/ItemWhoInputPane.md` with the B002 no-route/formal-covered-by relationship note. Proof: the `0002S5` row, emission policy, evidence notes, and changes section state that `0002S5` stays directly owned by `ItemWhoInputPane` and emits only the covered-by marker to `0002S2`.
- [x] Updated `by-file/TargetSelectionInputPanes.md` to remove stale "missing active owner" wording for this island and record the covered-by marker route. Proof: the `ItemWhoTargetNavigationRawHelpers` row now lists `[UID:00006X] ItemWhoInputPane` and formal coverage by `[UID:0002S2]`, and the B002 change log records removal of the stale disposition.
- [x] Updated `by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md` with the inline-duplicate/formal-covered-by relationship note. Proof: reconstruction notes, evidence notes, cross-references, and changes now state this key handler is the formal covered-by target for `0002S5`.
- [x] Did not edit `by-memory/0x0069bf20-0x0069bf34.TargetSelectionSavedTargetGlobals.md`. Proof: accepted report did not require a saved-global metadata/name change; implementation edits were scoped to the target, three support pages, and this report checklist.

Validation callback:

- [x] Ran validator for the target page with `--wait-generated` so generated output reflects the formal covered-by marker. Proof: `command_id: 000000004769`, `command_timestamp: 2026-06-27T23:14:12-04:00`, `ok: 1`, `generated_refresh: completed`.
- [x] Ran validators for updated support pages. Proof: `by-class/ItemWhoInputPane.md` command `000000004771` `ok: 1`; `by-file/TargetSelectionInputPanes.md` command `000000004774` `ok: 1`; `by-memory/0x005aedd0-0x005aefaf.ItemWhoInputPaneKeyInput.md` command `000000004777` `ok: 1`.
- [x] Confirmed generated tracker/coverage refreshes from source pages instead of manual generated edits. Proof: target validator `000000004769` reported `autogen_cpp_update: 2`, `autogen_registry_update: 4`, `research_tracker_update: 1`, `projected_stats_update: 1`, `memory_auto_coverage_update: 1`, and `generated_refresh: completed`; support validators reported `generated_refresh: deferred`; final autogen command `000000004787` reported `autogen_cpp_update: 1`, `research_tracker_update: 1`, `memory_auto_coverage_update: 1`, and `generated_refresh: completed`, and generated `TargetSelectionInputPanes.cpp` now contains `// Emitted code for this range is covered by [UID:0002S2].`.
- [x] Confirmed no `-coverage-report.md` files or generated reports were manually edited. Proof: all manual source changes were scoped to the target/support by-* docs plus this B002 report checklist; generated/project files changed only through `validator.py --apply` / validator autogen.
- [x] Confirmed no B002 leases remain. Proof: the four-file B002 unlease after scoped validators returned `Success` for all four by-* files, the target-only B002 unlease after exact-marker correction/autogen refresh returned `Success`, and `tools/leaser/Agents/current_leases.md` no longer lists B002.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md","timestamp":"2026-06-27T23:23:35","uid":"0002S5"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002S5-ItemWhoTargetNavigationRawHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002S5-ItemWhoTargetNavigationRawHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002S5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
