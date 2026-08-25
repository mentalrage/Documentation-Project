** TARGET-REPORT-UID:0004CZ **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **

# UID0004CZ StartupNoticeInvalidateButtons Source-Quality Report

## Finalized Report / Current Recommendation

UID0004CZ remains a reconstructable StartupWindow source child emitted through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). The implementation callback has been applied: the target is now `COMPLETION:88`, `CONFIDENCE:91`, keeps owner/emitter `0000O5`, and preserves the formal helper body exactly. The raw `__thiscall`-shaped body at `0x005817e0-0x00581854` walks two `0x20`-stride notice-button rectangles from `this+0x20`, copies each RECT into a stack temporary, and calls `InvalidateRect(this+0x0c, &rect, FALSE)`.

Applied target disposition:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank `EMITTER_POSITION_OPTIONAL:`.
- Preserve the current formal C++ body, with the formal header/block intact.
- Replace the stale "accepted by prior reports" proof emphasis with current MCP session `13191102` evidence: exact bytes, exact range, no IDA function object, no direct code/data/immediate references to the raw start, decompile failure at the raw start, predecessor/successor padding, and the no-local-UDT type-query result.

The confidence cap is not ownership. It is the combination of raw no-function/no-direct-start-route evidence and missing recovered original private helper/field spellings. Those are documentation caveats, not blockers to source-ready file-local helper emission.

## Supporting Research

Local documentation reviewed:

- Target: `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`.
- Source route: `by-file/StartupWindow.md`.
- Class route: `by-class/StartupWindow.md`.
- Parent split index: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`.
- Raw-helper tracker: `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`.
- Sibling helpers: `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`, `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`, and `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`.
- Generated output: `auto-generated/NexusTK/app/StartupWindow.cpp`, refreshed by validator command `000000006384` at `2026-07-04T17:49:11-04:00`.
- Coverage/tracker rows: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-memory-coverage.md`.
- Historical reports used only as leads: `executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md`, `executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md`, and sibling draft/report references for UID0004CW/UID0004CX.

Search terms used before finalizing: `0004CZ`, `0x005817e0`, `0x00581854`, `StartupNoticeInvalidateButtons`, `sub_5817e0`, `sub_5817E0`, and `StartupNotice`.

MCP availability history for this pass: initial `idb_list` JSON-RPC id `3` returned `count:0`; bounded retry id `11` briefly failed to connect; retry ids `12` and `13` then returned active NexusTK session `13191102`. All target evidence below uses session `13191102`, not the transient unavailable state.

## Target

- UID: `0004CZ`.
- Target doc: `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`.
- Address range: `0x005817e0-0x00581854`, half-open.
- Pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- Current post-callback metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- Current formal C++: non-empty helper body for `static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)`.
- Current generated state: validator command `000000006393` completed the scoped validation and generated refresh; a later validator-owned generated header refresh shows `auto-generated/NexusTK/app/StartupWindow.cpp` at `validator-command-id: 000000006394`, `validator-refreshed-at: 2026-07-04T18:03:36-04:00`, with concrete UID0004CZ C++ at `Completion:88 | Confidence:91`, not a bare empty marker.

## Current Target State

The target now emits a source-shaped helper body and carries the accepted score/evidence refresh. Pre-callback, it relied on prior B008/B010 acceptance language and showed `86/88`; post-callback, the target records current MCP session `13191102` proof at report-level detail and is scored `88/91`.

Current generated output after scoped validation:

```cpp
// UID:0004CZ | by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md | Completion:88 | Confidence:91
static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[index].rect, FALSE);
    }
}
```

The generated output proves the helper is coded through [UID:0000O5][StartupWindow](by-file/StartupWindow.md). The callback did not invent a new source body; it synchronized metadata, proof, and stale caveat wording.

## IDA MCP Facts

MCP session: `13191102` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.

Health:

- JSON-RPC id `20`, tool `server_health`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.

Function lookup:

- JSON-RPC id `21`, tool `lookup_funcs`.
- `0x005817a0` is `sub_5817A0`, size `0x3d`.
- `0x005817dd` is not a function.
- `0x005817e0` is not a function.
- `0x00581854` is not a function.
- `0x00581860` is not a function.
- `0x00581100` is `sub_581100`, size `0x4aa`.
- `0x00581670` is `sub_581670`, size `0xb4`.
- `0x00581730` is `sub_581730`, size `0x70`.

Exact bytes:

- JSON-RPC id `30`, tool `get_bytes`.
- Predecessor padding `0x005817dd-0x005817e0`: `0xcc 0xcc 0xcc`.
- Target bytes `0x005817e0-0x00581854`, size `0x74` / 116:

```text
55 8b ec 83 ec 14 a1 24 2f 67 00 33 c5 89 45 fc
53 8b d9 56 57 bf 02 00 00 00 8d 73 20 0f 1f 00
0f 10 0e 6a 00 8d 45 ec 0f 28 c1 66 0f 7e 4d ec
66 0f 73 d8 08 66 0f 7e 45 f4 0f 28 c1 50 ff 73
0c 66 0f 73 d8 04 66 0f 73 d9 0c 66 0f 7e 45 f0
66 0f 7e 4d f8 ff 15 d0 d3 60 00 8d 76 20 83 ef
01 75 bd 8b 4d fc 5f 5e 33 cd 5b e8 df 5e 04 00
8b e5 5d c3
```

- Successor padding `0x00581854-0x00581860`: twelve `0xcc` bytes.
- Successor one-button helper bytes `0x00581860-0x005818c3`, size `0x63` / 99, begin with the same security-cookie prologue and end in `ret 4`.

Instruction query:

- JSON-RPC id `31`, tool `insn_query`, scoped exactly to `0x005817e0-0x00581854`, returned 40 instructions, `truncated:false`.
- The body starts with a normal prologue/security-cookie frame, saves `ecx` as `this` in `ebx`, sets `edi = 2`, and initializes `esi = this + 0x20`.
- Loop body at `0x00581800` copies the current RECT from `[esi]` into locals, pushes `FALSE`, pushes the local RECT pointer, pushes `dword ptr [ebx+0Ch]`, and calls `ds:InvalidateRect` at `0x00581835`.
- Loop step `0x0058183b-0x00581841` advances `esi += 0x20`, decrements `edi`, and jumps back while nonzero.
- The epilogue checks the security cookie through `@__security_check_cookie@4` and returns at `0x00581853`.

Sibling comparison:

- JSON-RPC id `31`, same tool, scoped to `0x00581860-0x005818c3`, returned 30 instructions, `truncated:false`.
- The one-button sibling takes an index from `[ebp+8]`, computes `(buttonIndex + 1) << 5`, reads the same RECT layout from `[ecx + computed_offset]`, pushes `dword ptr [ecx+0Ch]`, calls `InvalidateRect`, and returns `ret 4`.
- This confirms the all-buttons helper's `this+0x20`, `0x20` stride, and `this+0x0c` HWND interpretation.

Xrefs and reachability:

- JSON-RPC id `32`, tool `xrefs_to`.
- `xrefs_to 0x005817e0`: `xref_count:0`, no cross-references.
- `xrefs_to 0x00581860`: `xref_count:0`, no cross-references.
- Modeled sibling refs remain anchored to WndProc: `0x00581730` has five xrefs (`0x5813ad`, `0x5813bd`, `0x5814e5`, `0x581542`, and raw `0x581632`); `0x005817a0` has three WndProc xrefs (`0x58138c`, `0x581465`, `0x581533`); `0x00581670` has two WndProc xrefs (`0x5813c6`, `0x5814fd`).
- JSON-RPC ids `33`, `34`, and `35`, tool `find`: exact `code_ref`, `data_ref`, and `immediate` searches for `0x005817e0` and `0x00581860` returned zero matches.

Type/decompile checks:

- JSON-RPC id `36`, tool `type_query`: filters `StartupWindow` and `StartupNotice` returned no local types/UDTs. Field names such as `m_noticeWindow` and `m_buttons` remain documentation-level names inferred from layout, not recovered IDA type members.
- JSON-RPC id `37`, tool `decompile`: `0x005817e0` failed decompilation because the raw start is not an IDA function. This is expected and should remain documented as a confidence cap.

## Function / Child Inventory

| Span | Current IDA state | Source disposition | Evidence |
| --- | --- | --- | --- |
| `0x005817a0-0x005817dd` | IDA function `sub_5817A0`, size `0x3d` | Sibling hit-test helper [UID:0004CY] | Modeled predecessor; three WndProc xrefs. |
| `0x005817dd-0x005817e0` | No function | Padding | Current bytes are `cc cc cc`. |
| `0x005817e0-0x00581854` | No IDA function; decompile fails | Target [UID:0004CZ] source-ready raw helper | Current bytes/disassembly prove two-rectangle invalidation loop and final `ret`. |
| `0x00581854-0x00581860` | No function | Padding | Current bytes are twelve `cc` bytes. |
| `0x00581860-0x005818c3` | No IDA function; no direct start refs | Sibling [UID:0004D0] one-button invalidation helper | Same RECT/HWND layout, indexed one-button variant, `ret 4`. |

## Direct Xref / Caller Inventory

| Address | Current xref state | Interpretation |
| --- | --- | --- |
| `0x005817e0` | `xrefs_to`, `find code_ref`, `find data_ref`, and `find immediate` all return zero. | No direct binary start route is proven. This is a confidence cap, not padding/no-owner proof. |
| `0x00581860` | Same zero-ref result. | The sibling one-button helper has the same raw no-direct-start-route status. |
| `0x00581730` | Five code xrefs, four from WndProc and one raw helper site. | Confirms the surrounding button-state family is WndProc/startup-notice code. |
| `0x005817a0` | Three WndProc xrefs. | Confirms the adjacent hit-test helper is WndProc/startup-notice code. |
| `0x00581670` | Two WndProc xrefs. | Confirms reset-state sibling remains in StartupWindow notice UI family. |

No direct caller should be invented for UID0004CZ. The report should preserve the accepted statement: raw helper bytes are valid and source-shaped, but IDA has no direct function/xref route to the start.

## Documentation Evidence And IDA Status

The support docs already carry the correct high-level split:

- `by-file/StartupWindow.md` names the notice button helper span `0x005815b0-0x005818c3` and lists UID0004CZ as an exact child created by the B008 split implementation.
- `by-class/StartupWindow.md` says exact method/helper bodies emit from by-memory children and lists the invalidation helper spans `0x005817e0-0x00581854` and `0x00581860-0x005818c3`.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` is a non-emitting split/index and lists UID0004CZ as a raw helper-shaped body invalidating both notice button rectangles, with corrected half-open range and no direct start refs.
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` is now a non-emitting tracker and says UID0004CZ is an exact child whose body lives on the by-memory page.
- Generated coverage marks UID0004CZ as `coded`, emitter `0000O5`, generated file `auto-generated/NexusTK/app/StartupWindow.cpp`.

The remaining stale state is mostly target-local: target score `86/88` and evidence text that cites B008/B010 acceptance but does not yet include the current MCP evidence pass.

## Heuristic / Inference Reanalysis And Validation

The old blocker was not "can we write source C++"; the target already has a plausible formal body. The reanalysis tests whether current MCP still supports that body at source-quality level.

Validated facts:

- The range is exactly `0x74` bytes and ends at `0x00581854`, before twelve bytes of `0xcc` padding.
- The target body contains a real function-shaped frame and security-cookie epilogue, not padding or data.
- `ecx` is the receiver pointer; the helper uses `this+0x0c` as the notice HWND.
- The button RECT array starts at `this+0x20` and advances by `0x20` bytes.
- The loop count is exactly two.
- The only visible side effect is two `InvalidateRect` calls with `FALSE`.
- The raw start still has no IDA function object, no direct xrefs, and no decompilation; this remains a documented confidence cap.
- No local `StartupWindow` or `StartupNotice` UDT exists in IDA, so field/type spellings remain inferred from documented layout and sibling helper behavior.

This supports source-ready C++ but caps confidence below near-perfect original-source recovery.

## Evidence Standards Used

- Current IDA MCP evidence must be live, session-specific, bounded, and schema-current.
- Existing by-* docs and executed reports are leads and consistency checks, not sufficient proof by themselves.
- Raw no-function code must be proven by bytes/instruction ranges, padding boundaries, and negative xref/decompile evidence.
- A formal C++ recommendation must be supplied as exact `RECONSTRUCTION_CPP CODE` header/block text.
- Ownership must be a source route, not just physical proximity. Here the source route is [UID:0000O5][StartupWindow](by-file/StartupWindow.md), supported by class/file/parent split docs and generated output.

## Evidence Checked

MCP calls used:

- `initialize`: JSON-RPC id `1`.
- `tools/list`: ids `2`, `22`, `23`, `24`, and `25` for schema/tool availability, read-only selection, and input schemas.
- `idb_list`: id `3` returned no sessions, retry id `11` connection failed, retry ids `12` and `13` returned active NexusTK session `13191102`.
- `server_health`: id `20`, session `13191102`, `status:"ok"`.
- `lookup_funcs`: id `21`, target and neighbors.
- `get_bytes`: id `30`, target, predecessor padding, successor padding, and one-button sibling.
- `insn_query`: id `31`, target and one-button sibling, scoped by start/end.
- `xrefs_to`: id `32`, target/sibling raw starts and modeled button helpers.
- `find`: ids `33` to `35`, exact code/data/immediate refs to `0x005817e0` and `0x00581860`.
- `type_query`: id `36`, `StartupWindow` and `StartupNotice`.
- `decompile`: id `37`, expected failure at raw `0x005817e0`.

Local documentation checks used:

- Direct `Get-Content` reads of target, source file, class route, parent split index, raw-helper tracker, and sibling helpers.
- `rg` searches for UID/address/name across executed reports, active B-agent research folders, generated output, and coverage/tracker files.
- Generated output audit of `auto-generated/NexusTK/app/StartupWindow.cpp` command `000000006384`.

Implementation-callback checks:

- Scoped validator command: `python .\tools\validator.py --mode file --file by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md --apply --queue-timeout 240 --wait-generated`.
- Validator `command_id: 000000006393`, `command_timestamp: 2026-07-04T18:02:37-04:00`, exit code `0`, `ok:1`, `generated_refresh: completed`.
- No IDA mutating tools were used.
- No lifecycle/archive/execute_report command was run.

## Positive Evidence Summary

- Current MCP session `13191102` is healthy and points at the NexusTK IDB.
- Exact bytes prove `0x005817e0-0x00581854` is executable helper-shaped code with a security-cookie frame and final `ret`.
- The scoped instruction query proves a two-iteration loop over `0x20`-stride rectangles starting at `this+0x20`.
- The helper calls `InvalidateRect` with HWND at `this+0x0c`, a stack RECT copy, and `FALSE`.
- The one-button sibling at `0x00581860-0x005818c3` uses the same HWND/RECT layout, strengthening the field interpretation.
- Predecessor padding is exactly three `0xcc` bytes and successor padding is exactly twelve `0xcc` bytes.
- Generated output already emits UID0004CZ source code through `StartupWindow.cpp`.
- Source route is supported by `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, parent split index, and raw-helper tracker.

## Negative Evidence Summary

- `0x005817e0` is not an IDA function and does not decompile.
- `xrefs_to`, exact `code_ref`, exact `data_ref`, and exact `immediate` searches find zero refs to `0x005817e0`.
- No local `StartupWindow` or `StartupNotice` type exists, so the final original field/helper spellings are not recovered.
- The helper should not be recast as padding, a no-owner orphan, a generic Win32 helper, Browser/ImageLoaders-owned code, a broad parent aggregate body, or a range extension into the one-button successor.

## Ranked Ownership Analysis

| Rank | Candidate | Disposition | Evidence |
| ---: | --- | --- | --- |
| 1 | [UID:0000O5][StartupWindow](by-file/StartupWindow.md) | Keep as owner/emitter | File/class/parent docs route all startup notice helper children through `StartupWindow.cpp`; generated output already emits UID0004CZ there; sibling helpers and WndProc context are StartupWindow-local. |
| 2 | [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) | Parent split/index only | The physical range inventory belongs here, but the page is non-emitting and should not duplicate exact child source. |
| 3 | [UID:0000VI][StartupWindowUnmodeledNoticeHelpers](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md) | Tracker only | It records raw-helper debt and links exact child pages, but remains non-emitting. |
| 4 | Generic Win32/UI helper | Reject | The body uses `StartupWindow` instance layout and notice button slots, not generic state. |
| 5 | Browser, ImageLoaders, MiniMapVersionManager, MD5, Application, Config | Reject | These are dependencies or adjacent startup systems. None owns the notice button RECT invalidation helper. |
| 6 | No-owner/padding | Reject | Bytes and instructions prove a real source-shaped helper body with side effects. |

## Source Placement

UID0004CZ should remain a direct by-memory child emitted through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), not through the non-emitting parent split or by-item tracker. The formal C++ should stay file-local helper style, matching the existing StartupNotice helper family.

The raw ABI uses `ecx` as the receiver. Because IDA lacks a local `StartupWindow` UDT and the original source spelling is unknown, the current source-facing helper declaration with an explicit `StartupWindow *startupWindow` remains the least disruptive representation. Do not promote it to a public class method or invent an original member name without stronger source evidence.

## First-Draft C++ Recommendation

Use this exact formal block in the target. It is the current target body and should be preserved during implementation, while metadata/evidence text is refreshed.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[index].rect, FALSE);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Recommended Target Doc Changes

For `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`, these accepted changes were applied:

- Set `COMPLETION:88`.
- Set `CONFIDENCE:91`.
- Preserve `CANONICAL_OWNER:0000O5`.
- Preserve `RECONSTRUCTABLE:TRUE`.
- Preserve `EMITTER_UIDS:0000O5`.
- Preserve blank `EMITTER_POSITION_OPTIONAL:`.
- Preserve the formal C++ block exactly as shown above.
- Update the item summary to call this a source-ready StartupWindow notice helper that invalidates both notice button rectangles through the StartupWindow file route.
- Replace target-local stale evidence that leans only on previous B008/B010 acceptance with the current MCP session `13191102` proof: exact `0x74` size, bytes, 40-instruction scoped listing, `this+0x0c` HWND, `this+0x20` first RECT, `0x20` stride, two-iteration loop, `InvalidateRect(..., FALSE)`, no IDA function object, decompile failure, zero xrefs/find refs, predecessor/successor padding, sibling one-button layout proof, and no local UDT.
- Preserve the confidence cap: no direct start route, no IDA function object, no recovered original helper/field spelling.

## Recommended Support Doc Changes

Support docs were inspected during callback and found already-present at same-or-greater detail:

- `by-file/StartupWindow.md`: mark already-present unless adding a narrow score/source-quality note. It already lists UID0004CZ as an exact child and routes StartupNotice helper bodies through `StartupWindow.cpp`.
- `by-class/StartupWindow.md`: mark already-present. It already says exact method/helper bodies emit from by-memory children and lists the invalidation helpers with corrected ranges.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`: mark already-present. It already lists UID0004CZ as a raw helper-shaped body invalidating both notice button rectangles, with corrected half-open range, no function object, and no direct refs.
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`: mark already-present. It already treats UID0004CZ as an exact child and keeps the tracker non-emitting.
- `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`: no edit required unless an implementation callback wants a sibling note; the one-button helper already contains the same layout and no-xref caveat.
- No Browser, ImageLoaders, MiniMapVersionManager, MD5, Application, Config, generic Win32, or padding/no-owner docs should be edited for this target.

## Score And Metadata Recommendation

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | `86` | `88` applied | Target already has formal C++ and source route. Callback added current MCP range, byte, disassembly, xref, type, generated-output, and support-doc proof. It remains below 90 because no direct start route/function object exists and original names are inferred. |
| `CONFIDENCE` | `88` | `91` applied | Exact bytes/instructions, generated output, sibling-layout proof, support docs, and negative ref checks support source-ready helper C++. Confidence is capped by no IDA function/decompile/direct refs and absent local UDTs. |
| `CANONICAL_OWNER` | `0000O5` | `0000O5` preserved | StartupWindow file route remains strongest. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` preserved | The helper has a concrete source body and generated output. |
| `EMITTER_UIDS` | `0000O5` | `0000O5` preserved | Keep emitting through `StartupWindow.cpp`. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank preserved | Existing format was preserved. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004CZ-01 | UID0004CZ is real helper-shaped code over exact range `0x005817e0-0x00581854`, size `0x74`. | High | MCP ids `21`, `30`, `31`; target bytes and 40-instruction listing. | Target `Status` / `Evidence` | incorporate | applied |
| C-0004CZ-02 | The body invalidates both notice button rectangles by looping exactly two times. | High | `mov edi, 2`, `lea esi, [ebx+20h]`, `esi += 0x20`, `jnz 0x581800`. | Target formal C++ and evidence | incorporate | applied |
| C-0004CZ-03 | The helper uses StartupWindow HWND at `this+0x0c` and button RECTs from `this+0x20` with `0x20` stride. | High | Target disasm plus one-button sibling disasm at `0x00581860`. | Target evidence | incorporate | applied |
| C-0004CZ-04 | Preserve the formal C++ block as `static void StartupNoticeInvalidateButtons(StartupWindow *startupWindow)`. | High | Current target formal block; MCP behavior matches source shape. | Target `RECONSTRUCTION_CPP CODE` | incorporate | applied |
| C-0004CZ-05 | Set target metadata to `COMPLETION:88`, `CONFIDENCE:91`. | Medium-high | Source-ready body plus current evidence; capped by no function/no refs/no UDT. | Target metadata | incorporate | applied |
| C-0004CZ-06 | Preserve owner/emitter route `0000O5`, reconstructable true, blank optional position. | High | Support docs and generated output route through StartupWindow file. | Target metadata | incorporate | applied |
| C-0004CZ-07 | Preserve no-function/no-direct-start-route caveat as a confidence cap. | High | `lookup_funcs`, `decompile`, `xrefs_to`, `find code_ref/data_ref/immediate` all negative for `0x005817e0`. | Target evidence / score rationale | incorporate | applied |
| C-0004CZ-08 | The range boundary is exact: three `0xcc` bytes before and twelve `0xcc` bytes after. | High | MCP `get_bytes` id `30`. | Target boundary evidence | incorporate | applied |
| C-0004CZ-09 | Generated output is coded, not a bare empty marker, and now carries `88/91` metadata. | High | `auto-generated/NexusTK/app/StartupWindow.cpp`, command `000000006393`, UID0004CZ section. | Target/generated evidence note | incorporate | applied |
| C-0004CZ-10 | Support docs already route UID0004CZ through StartupWindow and keep parent/tracker non-emitting. | High | Reviewed by-file, by-class, parent split, by-item tracker, and sibling UID0004D0. | Support docs | already-present | already-present |
| C-0004CZ-11 | Reject padding/no-owner/range-extension alternatives. | High | Real prologue/epilogue, side-effect call, exact padding after target, successor starts at `0x00581860`. | Target negative evidence | incorporate | applied |
| C-0004CZ-12 | Reject generic Win32/Browsers/ImageLoaders/Application ownership. | High | Layout-specific StartupWindow fields and source-route support. | Target/support negative evidence | incorporate | applied |
| C-0004CZ-13 | Do not perform IDA rename/type changes in this callback. | High | Assignment boundaries; raw no-function target lacks local UDT. | Report `IDA Rename / Type / Comment Recommendations` | not-applicable | excluded-with-reason |

## Range / Split / Padding / Reclassification Analysis

The target range should not be expanded or contracted.

- The predecessor modeled helper ends at `0x005817dd`; bytes `0x005817dd-0x005817e0` are `cc cc cc`.
- The target begins at `0x005817e0` with `push ebp` and ends with `ret` at `0x00581853`; half-open end `0x00581854` includes the return byte.
- Bytes `0x00581854-0x00581860` are twelve `0xcc` alignment bytes.
- The one-button raw helper begins at `0x00581860`, has its own security-cookie frame, and ends at `0x005818c3`.

The target is not padding and not part of the successor. The successor is a separate one-button invalidation helper.

## IDA Rename / Type / Comment Recommendations

Report-only pass: no IDA rename, type, comment, function-definition, or other database mutation is recommended.

If a future supervisor-authorized IDA cleanup pass defines the raw function, the safe documentation-level name is `StartupNoticeInvalidateButtons`. A possible raw ABI type would need to account for `ecx` as receiver, but the current formal source output should stay file-local helper style until original source/member naming is proven.

Do not create or apply a `StartupWindow` UDT from this target alone. MCP `type_query` found no `StartupWindow` or `StartupNotice` local type, and the target only proves a small subset of the layout.

## Open Questions With Attempted Resolution

| Question | Evidence checked | Resolution | Score/C++ impact | Future evidence needed |
| --- | --- | --- | --- | --- |
| Is `0x005817e0` an IDA function? | `lookup_funcs`, `decompile`, `insn_query`. | No. It is raw code with no function object; scoped instruction query still proves the body. | Caps confidence; does not block formal C++. | Supervisor-authorized IDA function definition or recovered original source. |
| Is there any direct caller or pointer ref to the raw start? | `xrefs_to`, `find code_ref`, `find data_ref`, `find immediate`. | No direct refs found for `0x005817e0`. | Preserve no-direct-start-route caveat; do not invent caller. | Broader binary/source recovery could prove source route, but current result is enough for helper ownership. |
| Are field names original? | `type_query` for `StartupWindow` and `StartupNotice`; sibling helper layout comparison. | No local UDT/original names recovered. Field names are documentation-level source names. | Caps confidence; formal code can keep established names. | Original source/imported headers or accepted UDT reconstruction. |
| Should this be a class member instead of file-local helper? | ABI uses `ecx`, but support docs and generated output use file-local helper family. | Keep file-local helper style for consistency and to avoid inventing class API. | No C++ blocker. | Original source or class UDT/member-function evidence. |
| Should support docs be edited? | File/class/parent/by-item support pages reviewed. | They are already sufficient; target doc needs the main update. | Support rows can be marked already-present. | Implementation callback may add narrow score/source-quality notes if desired. |

## Final Recommendation

Final disposition: UID0004CZ is source-ready as a StartupWindow notice helper, not a no-owner/raw-padding problem. The target has been promoted from `86/88` to `88/91`, keeps ownership and emission through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), keeps `RECONSTRUCTABLE:TRUE`, and preserves the blank emitter position.

Exact target changes recommended: keep the formal C++ body as the active `RECONSTRUCTION_CPP CODE` block; add current MCP session `13191102` evidence for range, bytes, two-rectangle `InvalidateRect` loop, no-function/no-xref/decompile-failure status, padding, sibling layout proof, and no local UDTs.

Parent assignment disposition: [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) remains a non-emitting split/index. [UID:0000VI][StartupWindowUnmodeledNoticeHelpers](by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md) remains a non-emitting tracker. Neither should absorb or duplicate UID0004CZ source C++.

No-owner/non-emitting disposition: reject no-owner and padding classifications for UID0004CZ. The exact child emits; only parent/tracker pages stay non-emitting.

Future work outside this target: original source or authorized IDA function/UDT work could refine member/helper and field names, but no additional evidence is required before applying this target-level source-quality update.

## Validator Results

Scoped validator run after target edit:

> Executable block R001 was removed from this report and preserved verbatim in [0004CZ-StartupNoticeInvalidateButtons-source-quality-removed.md](0004CZ-StartupNoticeInvalidateButtons-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000006393`
- `command_timestamp`: `2026-07-04T18:02:37-04:00`
- Exit code: `0`
- `ok`: `1`
- Target updates: `completion_update 0004CZ ... 88`; `confidence_update 0004CZ ... 91`
- Generated refresh: `generated_refresh: completed`, `generated_refresh_command_id: 000000006393`, `generated_refresh_timestamp: 2026-07-04T18:02:37-04:00`
- Generated output: the scoped validator reported `generated_refresh: completed` for command `000000006393`. A final post-validation freshness check found `auto-generated/NexusTK/app/StartupWindow.cpp` with newer validator-owned header `validator-command-id: 000000006394`, `validator-refreshed-at: 2026-07-04T18:03:36-04:00`, `validator-refresh-source: deferred-generated-refresh`; UID0004CZ emits concrete C++ at `Completion:88 | Confidence:91`.
- Validator side effects reported: `autogen_cpp_update: 1`, `completion_update: 1`, `confidence_update: 1`, `research_tracker_update: 1`, `memory_auto_coverage_update: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, `generated_metadata_refresh: 280`, `autogen_backup_create: 3`, plus unrelated existing generated warnings/notices including `autogen_children_marker_missing`, `autogen_children_fallback_insert`, and `autogen_emitter_has_no_code`.

## Changed Files

Callback-changed source docs:

- `tools/leaser/Agents/Agent-B008/research/0004CZ-StartupNoticeInvalidateButtons-source-quality.md`
- `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`

Support docs inspected and not edited because accepted facts were already present at same-or-greater detail:

- `by-file/StartupWindow.md`
- `by-class/StartupWindow.md`
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
- `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`

Validator-owned generated side effects were produced by command `000000006393`; B008 did not manually edit generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.

## Implementation Tracking Checklist

Callback implementation state:

- [x] Target metadata updated to `COMPLETION:88`, `CONFIDENCE:91`.
- [x] Target owner/emitter/reconstructable fields preserved: `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- [x] Target formal C++ body preserved exactly as accepted.
- [x] Target evidence refreshed with MCP session `13191102`: exact range/size, bytes, 40-instruction listing, two-iteration loop, `this+0x0c` HWND, `this+0x20` first RECT, `0x20` stride, `InvalidateRect(..., FALSE)`, no IDA function/decompile/xrefs/find refs, sibling UID0004D0 layout support, no local UDT, padding, score rationale, and rejected alternatives.
- [x] Stale target-local prior-report-only proof wording replaced with current MCP proof.
- [x] Support docs reviewed; by-file/by-class/parent/by-item/sibling support pages were already-present at same-or-greater detail and did not need edits.
- [x] Scoped validator ran on the changed by-memory target: command `000000006393`, timestamp `2026-07-04T18:02:37-04:00`, exit `0`, `ok:1`, generated refresh completed.
- [x] Lease used and released: B008 leased `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`, validator ran while leased, release returned `Success`, and the current lease report has no active B008/UID0004CZ lease entries.
- [x] No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, registry lifecycle command, manual report move, generated-file edit, coverage-report edit, validator-state edit, or supervisor-ledger edit was run by B008.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000006398","destination_path":"executed-b-agent-research/B008/0004CZ-StartupNoticeInvalidateButtons-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0004CZ-StartupNoticeInvalidateButtons-source-quality.md","timestamp":"2026-07-04T18:12:34-04:00","uid":"0004CZ"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004CZ-StartupNoticeInvalidateButtons-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0004CZ-StartupNoticeInvalidateButtons-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004CZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
