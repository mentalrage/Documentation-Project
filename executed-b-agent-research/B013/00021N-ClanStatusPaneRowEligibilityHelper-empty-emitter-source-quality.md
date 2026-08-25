** TARGET-REPORT-UID:00021N **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B013 Report - [UID:00021N] ClanStatusPaneRowEligibilityHelper Empty Emitter Source Quality

Assignment: `B013-report-00021N-ClanStatusPaneRowEligibilityHelper-empty-emitter-source-quality-20260628`

Target: [UID:00021N] `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`

Required disposition: resolve the empty-emitter state for the raw `ClanStatusPane` row helper.

## Recommendation

Make [UID:00021N] a code-emitting `ClanStatusPane` child with a nonblank first-draft helper body. Keep `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00002K`.

The current `IsRowActionAllowed` wording is polarity-wrong. Live MCP decompilation of `ClanStatusPane::OnMouseEvent` at `0x00484db0` shows the live click path proceeds only when the inverse of this raw helper is false. The helper at `0x004872e0` returns `true` for rows that are currently blocked/disabled, including defaulting to `true` for rows outside the handled `2..15` action/tab range. The best source-facing inferred name for the formal body is:

`bool ClanStatusPane::IsRowActionBlocked(short rowIndex)`

This is inferred, not recovered from original symbols, but it is a better source name than `IsRowActionAllowed` because it matches the return value and the live `OnMouseEvent` gate.

Recommended score after incorporation: `COMPLETION:88`, `CONFIDENCE:91`. Completion rises because the empty emitter gets a formal body and the polarity/name issue is resolved. Confidence rises slightly because current MCP confirms exact bytes, table ownership, negative direct-route evidence, and the inverse live click predicate. Keep it below a higher final-source band because the raw helper still has no direct caller/xref and the exact original spelling is not recovered.

## MCP Evidence Used

Current MCP pass was completed after supervisor resume.

- JSON-RPC `initialize`: `ida-pro-mcp` `1.0.0`, protocol `2025-06-18`.
- `tools/list`: 65 tools exposed, including `server_health`, `idb_list`, `lookup_funcs`, `entity_query`, `insn_query`, `get_bytes`, `xrefs_to`, `find_bytes`, `decompile`, and `analyze_component`.
- `idb_list`: used active session `b009_0001Q4_20260628`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, active `true`, pid/worker_pid `22092`.
- `server_health(database='b009_0001Q4_20260628')`: status `ok`, imagebase `0x400000`, Hex-Rays ready, strings cache ready. The health result reports `idb_path` as `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; its original `input_path` field is `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.

MCP tool facts:

- `lookup_funcs` reports `0x004872d8`, `0x004872e0`, `0x00487335`, `0x00487336`, and `0x00487338` are not functions. The predecessor row hit-test function is `sub_486F90` at `0x00486f90`, size `0x302`; the next modeled helper is `sub_487370` at `0x00487370`, size `0x46`; the row-action packet helper is `sub_487600` at `0x00487600`, size `0x1a0`.
- `entity_query(functions, 0x00484a00..0x00487850)` lists no function object at `0x004872e0`; the surrounding class island contains `sub_484A60`, `sub_484CD0`, `sub_484DB0`, `sub_486800`, `sub_486D20`, `sub_486F90`, `sub_487370`, `sub_487600`, and `sub_4877D0`.
- `insn_query(0x004872d0..0x00487380)` shows the raw helper body:
  - `0x004872e0`: `push ebp`
  - `0x004872e3`: `movsx eax, word ptr [ebp+8]`
  - `0x004872e7`: subtracts `2` and switches over 14 cases.
  - `0x004872ef`: `jmp ds:jpt_4872EF[eax*4]`, table operand points at `0x00487338`.
  - case bodies read `byte ptr [ecx+0f9h]` and `byte ptr [ecx+0f8h]`.
  - `0x00487308`: true return path, `mov al, 1; pop ebp; retn 4`.
  - `0x00487332`: false return path, `xor al, al; pop ebp; retn 4`.
  - `0x00487338`: first switch-table dword; `0x00487370` is the next function.
- `get_bytes` confirms the helper bytes and the table:
  - Entry bytes begin `55 8b ec 0f bf 45 08 83 c0 fe 83 f8 0d 77 19 ff 24 85 38 73 48 00`.
  - The switch table at `0x00487338` has 14 dwords for rows `2..15`: `0x4872f6`, `0x4872ff`, `0x4872f6`, `0x4872f6`, `0x4872f6`, `0x48730e`, `0x48730e`, `0x48730e`, `0x48730e`, `0x48730e`, `0x48730e`, `0x48730e`, `0x487320`, `0x48730e`.
  - Bytes at `0x00487336-0x00487337` are `04 00`, the immediate operand of the terminal `retn 4`, not standalone alignment. The table starts immediately at `0x00487338`.
- `xrefs_to(0x004872e0)`: no inbound references.
- `xrefs_to(0x00487338)`: one local data xref from `0x004872ef`.
- `xrefs_to` for case bodies shows only the local switch/table and local branches. No external xref targets a case label.
- `find_bytes` finds no little-endian VA/RVA pointer encodings for `0x004872e0` (`e0 72 48 00` or `e0 72 08 00`). The only `38 73 48 00` hit is the local table operand at `0x004872f2`.
- `decompile(0x00484db0)` shows `ClanStatusPane::OnMouseEvent` hit-tests through `sub_486F90`, then enforces row/view/version checks inline before calling `sub_487600` at `0x00484e91`. Those inline checks are the inverse of the raw helper's return value.
- `decompile(0x00487600)` confirms the row-action packet helper sends opcode `0x4b` subtypes for rows `2..13`, delegates row `7` to `0x00485960`, and is called only from `0x00484e91`.
- `analyze_component(0x00484a60,0x00484cd0,0x00484db0,0x00486f90,0x00487370,0x00487600)` reports internal edges `0x00484db0 -> 0x00486f90`, `0x00484db0 -> 0x00487600`, and `0x00484cd0 -> 0x00487370`. There is no edge to `0x004872e0`.

## Behavior And Polarity

The helper takes a signed 16-bit row index (`movsx eax, word ptr [ebp+8]`) and returns a boolean in `AL`. It reads only the `ClanStatusPane` receiver state:

- `m_currentClanStatusView` at full-object offset `+0xf8`
- `m_statusDataVersion` at full-object offset `+0xf9`

The helper returns `true` for blocked/disabled rows, not allowed rows:

| Rows | Helper return expression | Live `OnMouseEvent` proceeds when |
| --- | --- | --- |
| outside `2..15` | `true` | not applicable to row action helper |
| `2`, `4`, `5`, `6` | `m_statusDataVersion < 1 || m_currentClanStatusView != 0` | `m_statusDataVersion >= 1 && m_currentClanStatusView == 0` |
| `3` | `m_statusDataVersion != 0 || m_currentClanStatusView != 0` | `m_statusDataVersion == 0 && m_currentClanStatusView == 0` |
| `7..13`, `15` | `m_statusDataVersion < 2 || m_currentClanStatusView != 1` | `m_statusDataVersion >= 2 && m_currentClanStatusView == 1` |
| `14` | `m_statusDataVersion < 2 || m_currentClanStatusView != 0` | `m_statusDataVersion >= 2 && m_currentClanStatusView == 0` |

This table explains why current docs that say "allowed" are misleading. They preserved the branch conditions correctly but assigned them the wrong positive meaning. The function is better documented and emitted as a blocked/disabled predicate.

## Formal C++ Disposition

Use nonblank first-draft C++ for [UID:00021N]. Do not use a covered-by marker: the helper has its own source-shaped bytes and no other by-memory page emits this range. Do not make it non-emitting: `EMITTER_UIDS:00002K` is the right route through `ClanStatusPane`, and the empty emitter can be resolved with an exact small body.

Exact formal `RECONSTRUCTION_CPP CODE:BEGIN/END` body to insert:

```cpp
bool ClanStatusPane::IsRowActionBlocked(short rowIndex)
{
    switch (rowIndex) {
    case 2:
    case 4:
    case 5:
    case 6:
        return m_statusDataVersion < 1 || m_currentClanStatusView != 0;

    case 3:
        return m_statusDataVersion != 0 || m_currentClanStatusView != 0;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
        return m_statusDataVersion < 2 || m_currentClanStatusView != 1;

    case 14:
        return m_statusDataVersion < 2 || m_currentClanStatusView != 0;

    default:
        return true;
    }
}
```

Signature rationale:

- `short rowIndex` is required by the `movsx` load from `[ebp+8]`.
- `bool` matches the `AL` `0`/`1` returns.
- No `const` qualifier is recommended because the surrounding late-1990s/early-2000s class docs do not prove const member style for these private helpers.
- Field names are already accepted across `ClanStatusPane`, `ClanStatusPaneFrameAndInput`, and `ClanStatusPaneRows`.

## Ownership, Source Placement, And Reachability

Keep direct owner/emitter [UID:00002K] `ClanStatusPane`.

Keep file route [UID:0000I8] `Clan` / `social/Clan.cpp`.

Rejected alternatives:

- Do not move this to `ClanDialogs.cpp`: it has no dialog receiver, no dialog vtable, and no modal construction behavior.
- Do not move this to `ClanBank.cpp`: it reads `ClanStatusPane` row view/version state and sits in the status-pane row/view island.
- Do not leave it as broad file-local code: receiver state offsets, adjacency to `HitTestStatusRow` and child-view helpers, and class support docs all point to `ClanStatusPane`.
- Do not mark it covered by `ClanStatusPane::OnMouseEvent`: the mouse handler duplicates the inverse predicate inline for the live click path, but it does not cover or emit the separate raw helper bytes.

Reachability remains negative:

- No IDA function object at `0x004872e0`.
- No xref to the raw helper start.
- No little-endian VA/RVA pointer encoding for the raw helper start found by MCP `find_bytes`.
- No component call edge into the helper.

That negative reachability should stay in the docs as a confidence cap, not as a reason to preserve an empty emitter. The body is self-contained, exact, and source-shaped; the no-route fact only means the original call route or dead-code status is still unknown.

## Support-Doc Changes Needed

Target [UID:00021N]:

- Raise metadata to `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00002K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002K`.
- Replace the blank formal reconstruction body with the exact `ClanStatusPane::IsRowActionBlocked(short rowIndex)` body above.
- Update item summary, status, covered-range function name, behavior, reconstruction notes, MCP evidence, ownership decision, and score rationale to say the helper returns blocked/disabled state, not allowed state.
- Preserve negative xref/reachability facts, but state they cap confidence rather than blocking first-draft source.
- Fix boundary wording: `0x00487336-0x00487337` are the terminal `retn 4` immediate bytes and the jump table starts at `0x00487338`.

[UID:00002K] `by-class/ClanStatusPane.md`:

- Change the method row from `IsRowActionAllowed` to `IsRowActionBlocked`.
- Update the row-eligibility heuristic table: best name is `ClanStatusPane::IsRowActionBlocked`; C++ is now safe in [UID:00021N]; no direct route remains as a confidence cap.
- Update the class C++ decision so [UID:00021N] is no longer listed among raw/no-route children that must stay C++-blank. The class page itself should remain C++-blank as an emitting-children container.

[UID:0000I8] `by-file/Clan.md`:

- Update the proposed-contents row for [UID:00021N] from `ClanStatusPaneRowEligibilityHelper` / action availability wording to `ClanStatusPane::IsRowActionBlocked`, a status-row blocked/disabled predicate in `social/Clan.cpp`.
- Preserve the broader Clan source route and do not move the helper to `ClanDialogs` or `ClanBank`.

[UID:00010G] `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md`:

- Replace the B002 note that called [UID:00021N] `IsRowActionAllowed` / `IsStatusRowActionAllowed`.
- State that current MCP proves the helper returns the inverse blocked predicate, best named `IsRowActionBlocked`, and that [UID:00021N] can now carry first-draft C++.

[UID:00010C] `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`:

- Add a cross-note in the `OnMouseEvent` evidence/source-quality section that the live click path enforces the inverse predicate inline before calling `0x00487600`; this resolves the [UID:00021N] polarity/name issue.
- No metadata change is required for [UID:00010C].

[UID:00010H] `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md`:

- Optional but useful: add one sentence that `OnMouseEvent` applies the inverse of [UID:00021N] before calling the packet helper, so `0x00487600` remains the packet dispatcher and not the eligibility/disabled predicate.
- No metadata change is required for [UID:00010H].

[UID:0000VN] `by-memory/-ignored.md`:

- Update the `0x00487336-0x00487338` wording. These bytes are the `retn 4` immediate operand, not alignment. The ignored/non-source treatment is still right, but the explanation should say "terminal `retn 4` immediate bytes plus local switch table" rather than "alignment and jump-table data".
- Rename "row-eligibility switch data" wording to "row-action blocked/disabled helper switch data" or equivalent.

Generated files:

- Do not manually edit `auto-generated/NexusTK/social/Clan.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, or project-level generated reports.
- After the by-* implementation and scoped validators, generated `Clan.cpp` should stop showing the [UID:00021N] empty-emitter marker once the supervisor later executes/archives the report through the normal validator lifecycle.

## Rule 26 Empty-Emitter Decision

This target should not remain in an empty-emitter state. It currently has `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00002K`, and no formal C++ body, so generated output emits an empty marker. Current MCP evidence gives enough exact source shape to resolve that.

Why first-draft C++ is safer than no-code:

- The range is a complete small helper with no unresolved callees, no strings, and only two accepted member fields.
- The switch table is local and compiler-generated; the source body is a normal grouped `switch`.
- The live mouse handler confirms the row predicate semantics by using the inverse conditions before packet dispatch.
- The remaining uncertainty is original spelling/reachability, not behavior.

Why a covered-by marker is wrong:

- No other child emits this exact raw range.
- `OnMouseEvent` duplicates the inverse predicate inline, but it is not this helper's emitted code.

Why non-emitting metadata is wrong:

- The target is reconstructable source-authored logic, not padding, vtable data, thunk-only ABI glue, or a pure table.
- It already has the correct class emitter route; the problem is only the missing formal body and wrong helper polarity name.

## Implementation Tracking Checklist

Leave these unchecked during report-only review. If the supervisor accepts this report, B013 should perform only the by-* implementation callback items, under short leases, and then release those leases immediately after the scoped validator batch. B013 should not run `execute_report`.

- [x] Edit [UID:00021N] `by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md`: set `COMPLETION:88`, `CONFIDENCE:91`; keep owner/reconstructable/emitter metadata; insert the exact `ClanStatusPane::IsRowActionBlocked(short rowIndex)` formal C++ body; update item summary, title/status/function row, behavior table, MCP evidence, boundary note, score rationale, and changes log. Proof: applied in-place during the 2026-06-28 B013 implementation callback; validator command `000000005031` at `2026-06-28T14:00:10-04:00` exited `0` with `ok: 1`.
- [x] Edit [UID:00002K] `by-class/ClanStatusPane.md`: rename the method/support wording from `IsRowActionAllowed` to `IsRowActionBlocked`; update the heuristic row and class no-code decision so [UID:00021N] is a child with its own first-draft body while the class container remains C++-blank. Proof: applied in-place; validator command `000000005032` at `2026-06-28T14:00:23-04:00` exited `0` with `ok: 1`.
- [x] Edit [UID:0000I8] `by-file/Clan.md`: update the [UID:00021N] contents row to describe `ClanStatusPane::IsRowActionBlocked` as the status-row blocked/disabled predicate in `social/Clan.cpp`. Proof: applied in-place; validator command `000000005033` at `2026-06-28T14:00:34-04:00` exited `0` with `ok: 1` and retained only known unrelated missing-ref warnings.
- [x] Edit [UID:00010G] `by-memory/0x00486800-0x00487291.ClanStatusPaneRows.md`: replace the stale allowed/eligibility cross-note with the blocked-predicate conclusion and first-draft readiness note. Proof: applied in-place; validator command `000000005034` at `2026-06-28T14:00:46-04:00` exited `0` with `ok: 1`.
- [x] Edit [UID:00010C] `by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md`: add the inverse-predicate cross-note in the `OnMouseEvent` evidence/source-quality prose. Proof: applied in-place; validator command `000000005035` at `2026-06-28T14:00:57-04:00` exited `0` with `ok: 1`.
- [x] Edit [UID:00010H] `by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md`: note that `OnMouseEvent` applies the inverse [UID:00021N] predicate before packet dispatch. Proof: applied in-place; validator command `000000005036` at `2026-06-28T14:01:11-04:00` exited `0` with `ok: 1` and retained only known unrelated [UID:00021K] missing-target warnings.
- [x] Edit [UID:0000VN] `by-memory/-ignored.md`: correct the `0x00487336-0x00487338` explanation from alignment to terminal `retn 4` immediate bytes and update row-eligibility wording to blocked/disabled helper switch data. Proof: applied in-place; validator command `000000005037` at `2026-06-28T14:01:23-04:00` exited `0` with `ok: 1`.
- [x] Run scoped validators for every touched by-* file from `source-3/project-documentation`, for example `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240 --wait-generated`; record command id, timestamp, exit code, and `ok` count for each. Proof: all seven commands above ran sequentially with `--wait-generated` and exited `0`; final `auto-generated/NexusTK/social/Clan.cpp` header is `validator-command-id: 000000005039`, `validator-refreshed-at: 2026-06-28T14:03:43-04:00`; `rg` confirms [UID:00021N] now emits `bool ClanStatusPane::IsRowActionBlocked(short rowIndex)` and no [UID:00021N] `Empty Emitter Marker` remains.
- [x] Confirm no manual edits were made to generated reports, project-level reports, manual coverage reports, tool files, or IDA/MCP process state. Proof: B013 edited only accepted target/support by-* docs plus this report checklist; generated `Clan.cpp` was validator-refreshed only; no MCP process-control commands were run.
- [x] After supervisor verification only, supervisor-owned lifecycle work may archive/execute the report and refresh generated tracker/source output. This is not a B013 implementation action. Proof: B013 did not run `execute_report`; this report remains in `tools/leaser/Agents/Agent-B013/research/` for supervisor-owned verification/execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00021N-ClanStatusPaneRowEligibilityHelper-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/00021N-ClanStatusPaneRowEligibilityHelper-empty-emitter-source-quality.md","timestamp":"2026-06-28T14:12:50","uid":"00021N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
