** TARGET-REPORT-UID:00031O **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00031O] ScrollVolumePaneCanAdjustRaw Source-Quality Report

Assignment id: `B007-report-00031O-scroll-volume-pane-can-adjust-raw-source-quality-20260626`

Target: [UID:00031O][0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw](../../../by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md)

Report path: `tools/leaser/Agents/Agent-B007/research/00031O-ScrollVolumePaneCanAdjustRaw-source-quality.md`

Mode: report-only research, later accepted and implemented by Agent-B007 on 2026-06-26. During the report-only pass no by-* docs, generated files, project-level files, validator/tool state, IDA DB state, or coverage reports were edited. During the implementation callback, only accepted target/support by-* docs and this report checklist were manually edited; generated/coverage/tool-state/IDA DB files were not manually edited.

## Current Target State

Live by-* headers are authoritative for this pass. The generated tracker row is stale.

Pre-implementation live target metadata observed during the report pass:

- `COMPLETION:87`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0001H2`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001H2`
- Formal first-draft C++ is already populated as `bool ScrollVolumePane::CanAdjust() const`.

Stale generated context observed during the report pass:

- `auto-generated/-ag-research-tracker.md` still lists [UID:00031O] as `78/85`.
- `auto-generated/-ag-coverage-report-by-memory.md` still renders [UID:00031O] as `78%` with the stale summary "final source name remains open."
- `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` still annotates the emitted `CanAdjust` block as `Completion:78 | Confidence:85`, even though the live source page is `87/90`.

Current source-doc caveat needing cleanup:

- The target `Item Summary` says the final source name remains open. That is stale after B014 accepted `CanAdjust() const`, and after this B007 pass reconfirmed the predicate and field model with current MCP session `80de0a67`.
- The class page still has a broad old evidence sentence saying the three raw helpers at `0x005647c0`, `0x005647f0`, and `0x005648f0` have unresolved final names. That is now stale for all three helpers after B001, B002, B014, and this pass.
- The file page has current entries for B001/B002 but should add the matching current B007 `CanAdjust` source-quality evidence and generated-output stale-score caveat.

## MCP Session And Evidence Provenance

IDA MCP was available and used. No fallback-only report was produced.

Read-only MCP availability and session facts:

- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: True`.
- JSON-RPC `initialize` returned server `ida-pro-mcp` version `1.0.0`.
- `idb_list` returned active session `80de0a67`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, `is_active:true`, `is_analyzing:false`.
- `server_health` for `80de0a67` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- `tools/list` was checked in-session. Relevant read-only tools used were `lookup_funcs`, `xrefs_to`, `xref_query`, `get_bytes`, `insn_query`, `find_bytes`, `decompile`, `analyze_function`, `search_text`, and local `tools/int_convert.py`.

## Current MCP Body And Boundary Evidence

`lookup_funcs` in session `80de0a67`:

| Query | Result |
| --- | --- |
| `0x005648d0` | function `sub_5648D0`, size `0x1a` |
| `0x005648ea` | not a function |
| `0x005648f0` | not a function |
| `0x00564909` | not a function |
| `0x0056490a` | not a function |
| `0x00564910` | function `sub_564910`, size `0x1e1` |

Converted values:

- `0x1a` = 26 bytes (Verified with `tools/int_convert.py`).
- `0x1e1` = 481 bytes (Verified with `tools/int_convert.py`).
- `0x6` = 6 bytes (Verified with `tools/int_convert.py`).
- `0x100` = 256 (Verified with `tools/int_convert.py`).
- `0x102` = 258 (Verified with `tools/int_convert.py`).

`get_bytes` in session `80de0a67`:

| Range | Bytes | Meaning |
| --- | --- | --- |
| `0x005648ea-0x005648f0` | `cc cc cc cc cc cc` | Six-byte `Disable` to raw predicate alignment gap. |
| `0x005648f0-0x0056490a` | `80 b9 02 01 00 00 00 74 0e 33 c0 66 3b 81 00 01 00 00 7d 03 b0 01 c3 32 c0 c3` | Complete raw predicate body. |
| `0x0056490a-0x00564910` | `cc cc cc cc cc cc` | Six-byte raw predicate to `OnMouseEvent` alignment gap. |

`insn_query` over `0x005648d0-0x00564910` shows the predecessor, target, and successor boundary in one scoped scan:

```asm
0x005648d0  cmp byte ptr [ecx+102h], 1
0x005648d7  jnz short locret_5648E9
0x005648d9  mov edx, [ecx]
0x005648db  lea eax, [ecx+44h]
0x005648de  push eax
0x005648df  mov byte ptr [ecx+102h], 0
0x005648e6  call dword ptr [edx+20h]
0x005648e9  retn
0x005648ea  align 10h
0x005648f0  cmp byte ptr [ecx+102h], 0
0x005648f7  jz short loc_564907
0x005648f9  xor eax, eax
0x005648fb  cmp ax, [ecx+100h]
0x00564902  jge short loc_564907
0x00564904  mov al, 1
0x00564906  retn
0x00564907  xor al, al
0x00564909  retn
0x0056490a  align 10h
```

`decompile 0x005648f0` returned `code:null` and `error:"Decompilation failed at 0x5648f0"`, matching raw non-function status rather than a modeled method body.

`analyze_function 0x005648d0` confirms the predecessor `Disable` function is a distinct modeled helper with two direct callers from `sub_541A90` (`0x00541ac4` and `0x00541b0f`), writes byte `+0x102` to zero, invalidates `this+0x44`, and ends at `0x005648e9`. The target starts only after the six `0xcc` alignment bytes at `0x005648ea-0x005648f0`.

## Xref And Route Evidence

Current MCP xrefs:

- `xrefs_to 0x005648f0` returns zero xrefs and message `No cross-references to this address`.
- `xrefs_to 0x0056490a` returns zero xrefs.
- `xrefs_to 0x00564910` returns one data xref at `0x00624104`, the secondary vtable mouse-handler slot. This positive control confirms xref lookup sees normal data routes in the same class cluster.
- `xref_query` on `0x005648f0` with direction `both` finds no incoming raw-start route. The only target-range result is a raw internal code edge with `fn:null`; it is not an external caller or pointer route.

Current MCP byte-pattern checks:

- `find_bytes "f0 48 56 00"` for absolute VA `0x005648f0` returned zero matches.
- `find_bytes "f0 48 16 00"` for RVA `0x001648f0` returned zero matches.
- `find_bytes "0a 49 56 00"` for target end `0x0056490a` returned zero matches.
- Positive control `find_bytes "10 49 56 00"` for `OnMouseEvent` `0x00564910` returned one match at `0x00624104`, matching the vtable xref.

Read-only local PE route scan over `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`:

- Parsed imagebase `0x400000`.
- `.text` section starts at RVA `0x1000`, raw pointer `0x400`.
- `0x005648f0` maps to file offset `0x163cf0`.
- The scan found zero absolute-VA dword hits, zero RVA dword hits, zero file-offset dword hits, and zero direct `E8/E9` rel32 branch/call targets to `0x005648f0`.
- The same scan found zero VA/RVA/file-offset dword hits and zero direct `E8/E9` rel32 routes to `0x0056490a`.

Positive controls in the same PE scan:

| Target | Direct `E8/E9` hits |
| --- | --- |
| `0x00564820` `SetRange` | `0x005403c7`, `0x005403de` |
| `0x00564880` `SetValue` | `0x00540416`, `0x00540463` |
| `0x005648b0` `Enable` | `0x00541aa7`, `0x00541af3` |
| `0x005648d0` `Disable` | `0x00541ac4`, `0x00541b0f` |
| `0x00564910` `OnMouseEvent` | no direct calls, but one absolute-VA vtable slot at file offset `0x222b04` / VA `0x00624104` |
| `0x00565010` `GetPartRect` | 13 direct calls, including `0x00564987`, `0x00564a22`, `0x00564a3a`, `0x00564a59`, `0x00564d98`, `0x0056519c`, `0x005651b8`, `0x00565211`, `0x00565229`, `0x00565248`, `0x0056533a`, and `0x00565385` |
| `0x005652a0` `CommitInteraction` | `0x00564a83`, `0x00564b28`, `0x00565272` |
| `0x00565360` `NotifyValueChange` | `0x005652fb`, `0x00565324` |

Conclusion: no static ordinary route to the raw predicate start is visible. This remains a liveness/confidence cap only. It is not evidence against `ScrollVolumePane` ownership, not evidence that the bytes are padding, and not a reason to blank the formal C++ because the body is a complete source-shaped predicate in a valid emitter route.

## Field Use And Source Interpretation

The accepted field names remain correct.

`search_text "102h"` scoped to `0x00564710-0x005654ec` found 11 hits:

- Constructor initializes `+0x102/+0x103` through `mov word ptr [esi+102h], 0FF01h`, setting `m_enabled = 1` and `m_highlightPart = -1`.
- `Enable` compares and writes byte `+0x102` to `1`.
- `Disable` compares and writes byte `+0x102` to `0`.
- This raw predicate compares byte `+0x102` to zero.
- `OnPaint`, `HitTestPart`, and `GetPartRect` all test byte `+0x102` to decide enabled rendering/geometry behavior.

This supports `m_enabled` for `+0x102`. Rejected alternatives: `m_visible`, `m_hasFocus`, `m_activePart`, `m_highlightPart`, and drag-state names all contradict neighboring field roles and uses.

`search_text "100h"` scoped to `0x00564710-0x005654ec` found 11 hits:

- `SetRange` compares and writes word `+0x100`.
- This raw predicate compares word `+0x100` against zero.
- `OnPaint`, `HitTestPart`, `GetPartRect`, and `NotifyValueChange` use word `+0x100` as the slider maximum/range for geometry and value math.

This supports `m_range` for `+0x100`. Rejected alternatives: `m_value` belongs to `+0xfe`, `m_enabled` belongs to `+0x102`, `m_scrollStyle` belongs to `+0xfa`, part fields belong to `+0x103/+0x104`, and drag offset belongs to `+0x108/+0x10c`.

`search_text "0FEh"` found 10 hits and separates `+0xfe` as `m_value`: constructor clears it, `SetRange` clamps it, `SetValue` writes it, and paint/hit-test/geometry/notify paths read it as the current slider value.

The raw predicate implements:

- false when `m_enabled == false`;
- true only when `m_enabled != false` and `m_range > 0`;
- false when enabled but range is zero or negative in the signed compare sense.

The generated source-level expression `m_enabled && m_range > 0` preserves that runtime behavior for the documented unsigned-short field because all in-class writers clamp/set range as a non-negative short and the predicate's `xor eax, eax; cmp ax,[ecx+100h]; jge false` returns true exactly when zero is less than the range word.

## Source-Facing Name Decision

Retain `ScrollVolumePane::CanAdjust() const` as the best current human source-facing name.

Positive evidence:

- The body is a side-effect-free member predicate: it only reads `this + 0x102` and `this + 0x100`, returns AL, and has no calls or writes.
- It sits between `Disable` and `OnMouseEvent` in the ScrollVolumePane implementation island.
- It combines enabled state and positive range, exactly the gate that determines whether slider adjustment is possible.
- The class declaration already uses private `bool CanAdjust() const`.
- `HitTestPart` and generated output already use the same source expression `m_enabled && m_range > 0` for adjustable slider geometry.
- Neighboring raw helpers in this island use private member-style names after B001/B002/B005, not file-global helper names.

Rejected names:

- `IsEnabled() const`: too narrow because the method also requires `m_range > 0`.
- `HasRange() const`: too narrow because the method also requires `m_enabled`.
- `IsScrollable() const`: already belongs to modeled virtual `0x00564b00-0x00564b05`, which returns false.
- `CanScroll() const`: weaker source fit because this class is documented as a horizontal volume slider, and `IsScrollable` already has a separate false virtual meaning.
- `CanDrag() const` or `CanMoveThumb() const`: too specific; the same enabled/range gate applies to page regions, thumb geometry, hit testing, and paint, not only thumb drag.
- `IsActive() const`, `IsDragging() const`, or highlight/active-part names: contradicted by `+0x103`, `+0x104`, `+0xfb`, and `+0x108/+0x10c` roles.
- File-global/static helper: rejected because the body is thiscall-style member code using `ecx` object state and sits in the class implementation island.

The name remains inferred rather than original-symbol proof. That is a confidence cap, not a reason to keep stale "source name remains open" wording. The class/source family has accepted the name at current source-quality standard.

## Owner, Emitter, And Source Placement

Retain:

- `CANONICAL_OWNER:0001H2`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001H2`
- Source route through [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](../../../by-memory/0x00564710-0x005654ec.ScrollVolumePane.md), [UID:0000CO][ScrollVolumePane](../../../by-class/ScrollVolumePane.md), and [UID:0000NK][ScrollVolumePane](../../../by-file/ScrollVolumePane.md) / `NexusTK/ui/controls/ScrollVolumePane.cpp`.

Rejected owners and placements:

- Not `OptionPane` or `NewOptionPane`: those construct/configure volume sliders and receive callbacks, but this body reads only ScrollVolumePane fields and belongs in the reusable control implementation.
- Not `ScrollBar` or `ScrollableControlPane`: the field offsets, vtables, resources, and class docs identify this as the volume slider, not a generic scrollbar implementation.
- Not `TextEditPane`: stale generated signatures affected other helpers historically, but current class/file/docs reject that generated-owner pollution for this source island.
- Not a vtable/data item: the bytes are executable predicate instructions with `retn`, not table data.
- Not compiler padding: both sides are `0xcc` alignment; the target range itself has executable comparisons and returns.
- Not a no-owner/non-emitting item: the direct parent, class, and file emitters all clear the current gate and already route child method code.

## Split And Boundary Decision

Keep the target as exact half-open range `0x005648f0-0x0056490a`.

Rejected split/merge candidates:

- Do not merge backward with `Disable`: `sub_5648D0` is a modeled 26-byte function ending at `0x005648ea`; `0x005648ea-0x005648f0` is six bytes of `0xcc`.
- Do not include `0x005648ea-0x005648f0`: it is alignment padding, not source logic.
- Do not split the predicate internally: `0x005648f0-0x00564909` is one complete branch-and-return method body with a false label at `0x00564907`; both returns belong to the same predicate.
- Do not include `0x0056490a-0x00564910`: it is six bytes of `0xcc`.
- Do not merge forward with `OnMouseEvent`: `0x00564910` is modeled `sub_564910`, size `0x1e1`, and is referenced by the secondary vtable slot at `0x00624104`.
- Do not mark the target as covered by `OnMouseEvent`: no direct call is found, but the raw predicate has its own distinct executable bytes and formal child C++ already routes through the ScrollVolumePane source.

## Formal RECONSTRUCTION_CPP CODE Disposition

The existing formal target C++ is correct and should be retained unchanged. If implementation updates the target page, keep this exact formal block content:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollVolumePane::CanAdjust() const
{
    return m_enabled && m_range > 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

This is exact formal block content, not an illustrative body-only snippet.

## Positive Evidence Summary

- MCP session `80de0a67` is health-ready against the NexusTK IDB.
- The raw body bytes and instructions exactly implement an enabled-and-positive-range predicate.
- The target has exact pre/post `0xcc` padding and stable modeled neighbors: `Disable` before it and `OnMouseEvent` after it.
- The direct field-use census supports `m_enabled` at `+0x102` and `m_range` at `+0x100`.
- `CanAdjust() const` is already in the accepted class declaration and generated source.
- Owner/emitter/source placement through `ScrollVolumePane` is already valid and gate-cleared.
- Route scans include positive controls, so the no-route finding is meaningful rather than a broken scan.

## Negative Evidence Summary

- No IDA function exists at `0x005648f0`, `0x00564909`, or `0x0056490a`.
- Hex-Rays decompile fails for `0x005648f0` because there is no function object.
- `xrefs_to 0x005648f0` and `xrefs_to 0x0056490a` return zero xrefs.
- MCP `find_bytes` and local PE scanning find no absolute VA, RVA, file-offset pointer, or direct `E8/E9` route to `0x005648f0`.
- Exact original symbol spelling is not proven by PDB/source metadata. The source-facing name is inferred, but strongly supported.
- Generated tracker/coverage/source comments remain stale until source by-* docs are updated and validators refresh generated output.

## Score Recommendation

Recommended target metadata:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0001H2`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0001H2`

Rationale:

| Metric | Recommendation | Reason |
| --- | ---: | --- |
| Completion | `89` | The target now has current MCP-backed boundary, bytes, disassembly, xrefs, decompile failure, field-use census, route scan with positive controls, source-name decision, exact formal C++ retention, owner/emitter proof, split rejection, and stale generated-context analysis. It remains below final-audit quality because IDA still has no function object and no live static route to the raw start. |
| Confidence | `91` | Behavior, fields, owner, split, and source C++ are strongly supported by current MCP and existing source-family docs. Confidence remains capped by the absent route/function object and by lack of original symbol/debug proof for the exact `CanAdjust` spelling. |

Support pages can stay at current scores unless the supervisor wants score churn for minor support cleanup:

- [UID:0001H2] `ScrollVolumePane` aggregate: keep `87/90`; add current B007 child evidence, no aggregate C++.
- [UID:0000CO] `ScrollVolumePane` class: keep `89/89`; replace stale unresolved-name wording, retain declaration C++.
- [UID:0000NK] `ScrollVolumePane` file: keep `89/88`; add B007 child evidence and generated-output stale-score caveat.
- [UID:0001W2] `ScrollVolumePaneLayout`: keep `88/89`; add current B007 `+0x100/+0x102` field-census note if implementation wants the freshest proof in the layout page.

## Implementation Tracking Checklist

Implementation callback completed 2026-06-26 by Agent-B007. All accepted items below are applied, already present at equal-or-greater detail, or explicitly excluded with proof.

- [x] Edit `by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md`.
  - Applied metadata `COMPLETION:89`, `CONFIDENCE:91`; preserved `CANONICAL_OWNER:0001H2`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0001H2`, and blank `EMITTER_POSITION_OPTIONAL`.
  - Replaced stale `Item Summary` wording about final source name remaining open with source-ready/inferred-name wording and retained no-static-route as a liveness/confidence cap.
  - Preserved the formal `RECONSTRUCTION_CPP CODE` block unchanged at the top of the target page; no duplicate C++ body remains in prose.
  - Added report-level B007 details: MCP session `80de0a67`, health-ready IDB, `lookup_funcs`, exact bytes, bounded disassembly, decompile failure, xrefs/positive controls, local PE route scan with positive controls, field census, source-name decision, rejected names, rejected owners, split/boundary proof, positive/negative evidence, and `89/91` score rationale.
  - Validator command from `E:\NTK\GhidraBridge\source-3\project-documentation`: `python .\tools\validator.py --mode file --file by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002477`, `command_timestamp: 2026-06-26T06:17:05-04:00`, exit code `0`, `ok: 1`. Validator updates included `completion_update 89`, `confidence_update 91`, `canonical_owner_update 0001H2`, registry updates, and `insert_header_blank`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000002477`.

- [x] Edit `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md`.
  - Kept score `87/90`, owner/emitter [UID:0000CO], and blank aggregate C++.
  - Updated the [UID:00031O] covered row, evidence notes, no-code policy, and changes with B007 current MCP session `80de0a67`: exact bytes, raw non-function status, no raw-start/end xrefs, six-byte pre/post padding, field-use census, retained child formal C++, and PE route scan with positive controls.
  - Stated that `CanAdjust() const` is accepted/inferred and no longer open; route absence remains only a liveness/confidence cap.
  - Validator command: `python .\tools\validator.py --mode file --file by-memory/0x00564710-0x005654ec.ScrollVolumePane.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002479`, `command_timestamp: 2026-06-26T06:17:17-04:00`, exit code `0`, `ok: 1`. Warnings: two pre-existing `missing_ref_target` diagnostics for stale `by-memory/0x0055d960-0x00565488.TextEditPaneScrollbarVariants.md`; not changed for this callback. `generated_refresh: deferred`, `generated_refresh_command_id: 000000002479`.

- [x] Edit `by-class/ScrollVolumePane.md`.
  - Kept score `89/89`, owner/emitter [UID:0000NK], and declaration-level C++.
  - Replaced stale text saying raw helpers `0x005647c0`, `0x005647f0`, and `0x005648f0` all have unresolved final names. Current state now says [UID:00031M] is inferred `SetTrackStateWord`, [UID:00031N] is inferred `SetScrollStyle`, and [UID:00031O] is accepted inferred `CanAdjust() const`, with exact raw-start routes still unrecovered.
  - Added B007 evidence and rejected alternatives for [UID:00031O] while keeping method body C++ on the exact child page only.
  - Validator command: `python .\tools\validator.py --mode file --file by-class/ScrollVolumePane.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002482`, `command_timestamp: 2026-06-26T06:17:32-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000002482`.

- [x] Edit `by-file/ScrollVolumePane.md`.
  - Kept score `89/88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, and file-level source route.
  - Updated `Status`, `Proposed Contents`, `Evidence Notes`, `Generated Output Caveats`, `Source-Quality Sync`, and `Changes` so [UID:00031O] is current source-ready inferred `CanAdjust() const`, not merely a stale raw/projected helper with old generated scores.
  - Recorded that `auto-generated/NexusTK/ui/controls/ScrollVolumePane.cpp` emitted the correct [UID:00031O] body at report time but had stale `78/85` generated UID comments; generated output remains validator-owned.
  - Preserved the distinction between `ScrollVolumePane` control ownership and `OptionPane`/`NewOptionPane` construction/callback policy.
  - Validator command: `python .\tools\validator.py --mode file --file by-file/ScrollVolumePane.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002485`, `command_timestamp: 2026-06-26T06:17:44-04:00`, exit code `0`, `ok: 1`. Validator normalized three missing UID links for `00031O`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000002485`.

- [x] Edit `by-type/by-struct/ScrollVolumePaneLayout.md`.
  - Kept score `88/89`, owner/emitter [UID:0000CO], field names/offsets, and blank layout C++.
  - Added B007 current MCP session `80de0a67` field-census proof: 11 `100h` hits supporting `m_range`, 11 `102h` hits supporting `m_enabled`, and 10 `0FEh` hits separating `m_value`; [UID:00031O] correctly reads `m_enabled` and `m_range`.
  - Validator command: `python .\tools\validator.py --mode file --file by-type/by-struct/ScrollVolumePaneLayout.md --apply --queue-timeout 240`
  - Validator result: `command_id: 000000002488`, `command_timestamp: 2026-06-26T06:17:54-04:00`, exit code `0`, `ok: 1`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000002488`.

- [x] Excluded edit for callback-named `by-memory/0x005647c0-0x0056490a.ScrollVolumePaneRawStateHelpers.md`.
  - Concrete reason: the page does not exist in the current tree and was not in this report's accepted checklist. Proof checked during implementation: `Test-Path E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005647c0-0x0056490a.ScrollVolumePaneRawStateHelpers.md` returned `False`, and `rg --files ... | rg "ScrollVolumePane.*(RawState|StateHelpers|0x005647c0)"` returned no matching raw-state aggregate page.
  - Applied the accepted support facts to the existing aggregate [UID:0001H2] `by-memory/0x00564710-0x005654ec.ScrollVolumePane.md` instead, as listed above.

- [x] No edit required for `by-type/by-vtable/ScrollVolumePaneVtables.md`.
  - Proof: current page already routes `0x00564910` through secondary vtable slot `0x00624104`; no vtable slot targets `0x005648f0`, matching B007 no-route evidence. Vtable data remains generated-binary/no-code support.

- [x] No edit required for `by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md`.
  - Proof: current page already has `88/90`, formal `SetTrackStateWord` C++, inferred `m_trackStateWord`, no-function/no-route caveat, constructor/field-census evidence, and rejected alternatives. [UID:00031O] does not change this page.

- [x] No edit required for `by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md`.
  - Proof: current page already has `88/90`, formal `SetScrollStyle` C++, inferred `m_scrollStyle`, scoped field census, no-function/no-route caveat, and exact-original-spelling caveat. [UID:00031O] does not change this page.

- [x] No edit required for `by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md`.
  - Proof: current formal hit-test C++ already uses the same `m_enabled && m_range > 0` geometry predicate and is not stale with respect to [UID:00031O].

- [x] Do not edit `auto-generated/*`, project-level generated files, validator/tool state, IDA DB state, `by-memory/-coverage-report.md`, or any `-coverage-report.md`.
  - Proof: B007 made no manual edits to generated files, coverage reports, validator/tool state, or IDA DB. Scoped validator commands reported `generated_refresh: deferred` for all five edited by-* files and `projected_stats_update` side effects through validator-owned lifecycle output; generated/projected outputs were not hand-edited.

- [x] Lease discipline and release proof.
  - Leased only the immediate edit batch: target page, existing ScrollVolumePane aggregate, class page, file page, and layout page.
  - Release proof: `python .\leaser.py B007 unlease` from `tools\leaser` returned `B007: No active leases` after validation, and `tools/leaser/Agents/current_leases.md` had no B007 rows when checked.

## Report-Only Checklist

- [x] Read B007 `goal.md`.
- [x] Used the project-level `ntk-b-agent-workflow` skill.
- [x] Used mandatory IDA MCP; session `80de0a67` was available and health-ready.
- [x] Read target and support docs: target by-memory page, ScrollVolumePane aggregate, class, file, layout, vtable support, sibling raw helper pages, generated tracker/coverage/source state, and executed B014 context.
- [x] Rechecked exact range, bytes, padding, modeled neighbors, decompile failure, xrefs, pointer/route state, and field-use evidence.
- [x] Verified documented conversions with `tools/int_convert.py`.
- [x] Wrote report only in the Agent-B007 research folder.
- [x] Did not edit by-* docs, generated files, project-level files, validator/tool state, IDA DB, or coverage reports.
- [x] Did not spawn subagents.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00031O-ScrollVolumePaneCanAdjustRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00031O-ScrollVolumePaneCanAdjustRaw-source-quality.md","timestamp":"2026-06-26T06:21:16","uid":"00031O"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
