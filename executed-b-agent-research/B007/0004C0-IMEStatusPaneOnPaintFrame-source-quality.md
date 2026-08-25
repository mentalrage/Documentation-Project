** TARGET-REPORT-UID:0004C0 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0004C0] IMEStatusPaneOnPaintFrame Source-Quality Report

Agent: B007  
Assignment: `B007-implement-0004C0-IMEStatusPaneOnPaintFrame-20260630`  
Mode: implementation callback completed after supervisor validation.

## Current Target State

Target: [UID:0004C0][0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame](../../../../../by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md)

Current metadata:

| Field | Current value |
| --- | --- |
| `COMPLETION` | `80` |
| `CONFIDENCE` | `86` |
| `CANONICAL_OWNER` | `00006I` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | blank |
| Formal C++ | blank |

Tracker and generated-state leads:

- `auto-generated/-ag-research-tracker.md` row for [UID:0004C0] reports `80/86`, combined `83.0`, reconstructable `true`, reports `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` lists the target as `emits_code:false`, `reconstructable`, `80%`, `strong`, with summary "Exact IMEStatusPane paint-frame split child; paints compact mode/status label frame and text."
- `auto-generated/NexusTK/input/IMEPanes.cpp` is refreshed from [UID:0000K5] but does not contain the accepted child body because [UID:0004C0] has no emitter route or formal C++ yet.

Empty-emitter inventory for this report:

| UID | Path | Empty-emitter status | In-scope disposition |
| --- | --- | --- | --- |
| [UID:0004C0] | `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md` | `EMITTER_UIDS` blank, formal C++ blank | Repair in a callback by setting `EMITTER_UIDS:00006I` and inserting the first-draft formal body below. |

No sibling empty-emitter pages are included in this assignment. [UID:0004BW] `IMEStatusPaneSetText` remains a useful lead for `statusText[256]`, bounds placement, and class ownership, but this pass is scoped to the exact [UID:0004C0] paint-frame child.

## Evidence Checked

Current by-* docs:

- Target page [UID:0004C0], [UID:00006I] `IMEStatusPane`, [UID:0000K5] `IMEPanes`, [UID:000189] `IMEPaneFamily`, and [UID:00025J] `IMEPaneReadOnlyData`.
- GrafPort support pages: [UID:0000JR] `GrafPort`, [UID:00005V] `GrafPort`, [UID:000162] `GrafPortDrawStateAccessors`, [UID:000168] `GrafPortDrawRectFrame`, [UID:00016C] `GrafPortTextRunHelpers`, [UID:0000TN] `SurfaceRenderCallbackTable`, and [UID:0000QW] `g_pfnLockSurface`. Implementation callback note: the report-first draft used stale support UID `000167` for the draw-state accessors; current file evidence shows [UID:000162] is the actual accessor page and [UID:000167] is `SurfaceSpriteBlitHelper`, so the implemented target uses [UID:000162] while preserving the accepted helper behavior.

Prior report leads revalidated, not treated as direct coverage:

- B008 [UID:0000K5] `IMEPanes` empty-emitter report created this child from the aggregate split plan and identified the owner route, but left child-specific paint helper names/C++ unresolved.
- B015 `ChattingModifyHeightPaneOnPaint` and B001 `ControlPaneDrawActiveFrameHelper` reports are helper-name leads for `SetDrawColor`, slot-7 `FillRect`, inherited `m_bounds`, and `DrawRectFrame`.

Current IDA MCP evidence from session `supervisor_resume_20260629`:

- `idb_list` JSON-RPC id `111`: one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker, PID/worker PID `24256`, `is_analyzing:false`.
- `server_health` id `112`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, imagebase `0x400000`.
- `lookup_funcs` id `113`: `0x004e7300 -> sub_4E7300 size 0x7b`; `0x004e737b` is not a function; `0x004e7380 -> sub_4E7380 size 0xcd`; helper boundaries `0x004b9600 size 0x13`, `0x004b9660 size 0x0d`, `0x004b9680 size 0x0d`, `0x004ba450 size 0xeb`, and `0x004bab70 size 0x158`.
- `decompile 0x004e7300` id `114`: writes byte `this+112 = 0`, calls `sub_4B9660(this,143)`, calls `unk_69B3FC(this,this+68)`, calls `sub_4B9660(this,128)`, calls `sub_4BA450(this,this+68)`, calls `sub_4B9680(this,128)`, calls `sub_4B9600(this, *(this+68)+2, *(this+80)-2)`, counts UTF-16 words at `this+248`, and calls `sub_4BAB70(this,this+248,length)`.
- `get_bytes` id `115`: target bytes are a complete 123-byte function ending `5f 5e c3`; `0x004e737b-0x004e737f` is five `0xcc` bytes before the next function.
- `xrefs_to 0x004e7300` id `116`: one data xref at `0x0061c3a8`, no code callers, matching virtual-dispatch/vtable use rather than dead code.
- Helper decompiles ids `121`-`124`: `0x004b9600` stores draw cursor fields `this[27]`/`this[26]`; `0x004b9660` stores `this[29]`; `0x004b9680` stores `this[31]`; `0x004ba450` is the clipped rectangle-frame helper that draws four line deltas via `0x0069b3e4`.

## Positive Evidence

The target is an exact source-authored virtual method body, not padding, aggregate-only material, or a raw callback table:

- Current MCP confirms one modeled function at `0x004e7300` with size `0x7b` and confirms no function starts at the half-open end `0x004e737b`.
- The five bytes after the body are `0xcc` padding, and the next modeled function begins at `0x004e7380`, so no split is needed inside [UID:0004C0].
- The only xref to `0x004e7300` is the data xref at `0x0061c3a8`, in the `IMEStatusPane` vtable island documented by [UID:00025J]. That is expected for a virtual `OnPaintFrame` override.
- [UID:00006I] declares `virtual void OnPaintFrame();` and documents `statusText[256]` at `this+0xf8`, matching the target's final text draw from `this+248`.
- [UID:000189] already assigns `0x004e7300-0x004e737b` to `IMEStatusPane::OnPaintFrame` under source file [UID:0000K5] `IMEPanes`.

The child-specific draw behavior is now resolved:

| Address/effect | Source-facing role | Evidence |
| --- | --- | --- |
| `mov byte [this+0x70],0` | Clear inherited GrafPort draw/blit mode before painting. | Current target bytes/decompile and `GrafPortDrawStateAccessors` support treating `+0x70` as separate draw state from `SetDrawColor`. |
| `sub_4B9660(this,0x8f)` | `SetDrawColor(0x8f)` for the background fill. | Current helper decompile stores `this+0x74`; support docs identify `0x004b9660` as `GrafPort::SetDrawColor`. |
| `dword_69B3FC(this,this+0x44)` | `FillRect(&m_bounds)` or equivalent slot-7 rectangle fill/refresh wrapper. | `SurfaceRenderCallbackTable` documents `0x0069b3fc` as broad slot-7 fill/invalidation; B015 confirms `FillRect` wording for control-source prose. |
| `sub_4B9660(this,0x80)` | `SetDrawColor(0x80)` for the outline frame. | Same helper evidence; `GrafPortDrawRectFrame` support documents frame callers selecting draw color before frame draw. |
| `sub_4BA450(this,this+0x44)` | `DrawRectFrame(&m_bounds)`. | Current helper lookup/decompile and [UID:000168] name/signature support. |
| `sub_4B9680(this,0x80)` | `SetTextColor(0x80)` for the status label. | Current helper decompile stores `this+0x7c`; [UID:000162] and [UID:00016C] support primary text-color wording for text drawing paths. |
| `sub_4B9600(this, *(this+0x44)+2, *(this+0x50)-2)` | `MoveTo(m_bounds.left + 2, m_bounds.bottom - 2)`. | Current helper decompile stores draw cursor X/Y fields at `+0x6c/+0x68`; [UID:000162] names it `MoveTo`. |
| UTF-16 scan from `this+0xf8` and `sub_4BAB70(this,this+0xf8,length)` | Count `statusText` then `DrawWideText(statusText,length)`. | [UID:00016C] documents `0x004bab70` as `GrafPort::DrawWideText(const wchar_t *, int)`. |

## Negative Evidence And Rejected Alternatives

- Do not keep `EMITTER_UIDS` blank. The blank route is no longer justified because the exact body, helper names, receiver fields, virtual route, and source-file chain are now documented.
- Do not route [UID:0004C0] directly to [UID:0000K5] as the emitter. The method is class-owned by [UID:00006I], and [UID:00006I] already emits through [UID:0000K5] with `[[CHILDREN]]`; the correct child route is method -> class -> file.
- Do not assign the target to [UID:00005V] `GrafPort` or [UID:0000JR] `GrafPort.cpp`. The target consumes GrafPort helpers and inherited state, but it reads `IMEStatusPane::statusText` at `+0xf8` and is reached through the `IMEStatusPane` vtable.
- Do not assign the target to [UID:0000TN] `SurfaceRenderCallbackTable` or [UID:0000OC] `Surface`. The slot-7 callback is an infrastructure dependency; the method body is the IME pane paint routine.
- Do not split [UID:0004C0]. Current bytes prove one complete `ret`-terminated 123-byte function followed by five `0xcc` bytes, and current `lookup_funcs` confirms the successor function at `0x004e7380`.
- Do not use generated aliases such as `g_pfnLockSurface` or caller-biased helper names in final prose/C++. The current support pages explicitly reject those aliases for control/pane source and prefer `FillRect`, `SetDrawColor`, `SetTextColor`, `MoveTo`, `DrawRectFrame`, and `DrawWideText`.

## Heuristic And Source-Placement Reanalysis

Ranked placement:

1. [UID:00006I] `IMEStatusPane` class, emitted through [UID:0000K5] `IMEPanes`: best and recommended. It matches the vtable slot, class declaration, `statusText[256]` field, aggregate split plan, and the source-facing virtual method name.
2. [UID:0000K5] `IMEPanes` direct file bucket: acceptable only as the transitive file route, not as the direct `EMITTER_UIDS` for this method, because the class page is the correct narrow semantic owner.
3. [UID:00005V]/[UID:0000JR] `GrafPort`: rejected as helper ownership only.
4. [UID:0000TN]/[UID:0000OC] Surface render callback support: rejected as callback infrastructure only.

Field and offset roles:

- `this+0x44`: inherited `RectBounds`/`m_bounds` passed to fill and frame operations; the code reads `left` at `+0x44` and `bottom` at `+0x50`.
- `this+0x70`: inherited draw/blit mode byte, directly cleared before painting.
- `this+0x74`: active draw/fill color set by `SetDrawColor`.
- `this+0x7c`: primary text color set by `SetTextColor`.
- `this+0xf8`: `IMEStatusPane::statusText[256]`, already documented on [UID:00006I].

The source-level method is a compact status label repaint:

1. Clear draw mode.
2. Fill the pane bounds with color `0x8f`.
3. Draw a frame in color `0x80`.
4. Select text color `0x80`.
5. Move the text cursor to left inset `+2` and bottom baseline `-2`.
6. Count the null-terminated UTF-16 `statusText` string and draw that exact count with `DrawWideText`.

## Score And Metadata Recommendation

Target [UID:0004C0]:

| Field | Before | Recommended after callback | Rationale |
| --- | --- | --- | --- |
| `COMPLETION` | `80` | `88` | Exact range, padding, vtable route, helper calls, field roles, child-specific behavior, rejected alternatives, and first-draft formal C++ are now resolved. Keep below final because inherited member spelling (`m_bounds`, `m_drawMode`) and final slot-7 wrapper spelling may still be normalized by later GrafPort/Surface work. |
| `CONFIDENCE` | `86` | `90` | Current MCP confirms the body and helper boundaries; support pages confirm helper roles and owner route. Confidence remains below absolute certainty only because the original source names are stripped. |
| `CANONICAL_OWNER` | `00006I` | `00006I` | Correct narrow semantic owner is unchanged. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | This is live, vtable-routed source-authored code. |
| `EMITTER_UIDS` | blank | `00006I` | Emit through the owning class page; [UID:00006I] then emits through [UID:0000K5]. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | Address/order generation through the class child list is sufficient; no nonstandard insertion point is required. |

Support pages:

| UID | Page | Recommendation |
| --- | --- | --- |
| [UID:00006I] | `by-class/IMEStatusPane.md` | Keep owner/emitter route and `88/90`. Add a method note for `OnPaintFrame` if the supervisor wants support detail mirrored: colors `0x8f/0x80`, `FillRect`, `DrawRectFrame`, `SetTextColor`, `MoveTo(bounds.left+2,bounds.bottom-2)`, and `DrawWideText(statusText,length)`. No score change is required because the class already clears the gate. |
| [UID:0000K5] | `by-file/IMEPanes.md` | No metadata change required. This file already owns the IME pane family and will receive generated method output through [UID:00006I]. Optional method table/detail sync only. |
| [UID:000189] | `IMEPaneFamily` aggregate | No metadata change required. The aggregate already has `[[CHILDREN]]` and the exact split row; add only a note that [UID:0004C0] child-specific C++ is now implementation-ready if desired. |
| [UID:00025J] | `IMEPaneReadOnlyData` | No change required. It already documents the IMEStatusPane vtable island and supports the vtable route. |
| GrafPort/Surface support pages | `GrafPortDrawStateAccessors`, `GrafPortDrawRectFrame`, `GrafPortTextRunHelpers`, `SurfaceRenderCallbackTable` | No change required. They already contain sufficient helper-role evidence. Current implementation corrected the draw-state accessor support UID to [UID:000162]. |

## Exact Formal C++ Recommendation

For supervisor-approved insertion into [UID:0004C0] formal `RECONSTRUCTION_CPP CODE`:

```cpp
void IMEStatusPane::OnPaintFrame()
{
    m_drawMode = 0;

    SetDrawColor(0x8f);
    FillRect(&m_bounds);

    SetDrawColor(0x80);
    DrawRectFrame(&m_bounds);

    SetTextColor(0x80);
    MoveTo(m_bounds.left + 2, m_bounds.bottom - 2);

    int length = 0;
    while (statusText[length] != L'\0')
        ++length;

    DrawWideText(statusText, length);
}
```

Implementation caveat: if the existing codebase standardizes inherited field names differently, keep the same behavior and helper sequence but adapt only the member spelling. Do not replace `MoveTo` with `SetTextPosition`; current helper docs identify `0x004b9600` as `MoveTo`. Do not replace `DrawWideText` with a generic `DrawText`; current [UID:00016C] names `0x004bab70` as `GrafPort::DrawWideText(const wchar_t *, int)`.

## Implementation-Ready Target/Support Doc Changes

1. Update [UID:0004C0] `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md`:
   - Set `COMPLETION:88`.
   - Set `CONFIDENCE:90`.
   - Set `EMITTER_UIDS:00006I`.
   - Leave `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_POSITION_OPTIONAL` unchanged.
   - Replace the stale "helper names remain a child-specific C++ task" note with the resolved draw sequence and helper roles listed above.
   - Insert the exact formal C++ block from this report.
   - Add MCP evidence: ids `111`-`116`, `121`-`124`, exact function size, `0xcc` padding, one vtable data xref at `0x0061c3a8`, and helper roles.
   - Update score rationale with before/after reasoning.
2. Optionally update [UID:00006I] `by-class/IMEStatusPane.md`:
   - Add or refine the `OnPaintFrame` method note with the child-specific behavior and helper sequence.
   - No score/metadata change required.
3. Optional no-score sync for [UID:0000K5] and [UID:000189]:
   - Only if the supervisor wants mirrored support detail; the target page alone can carry the detailed implementation proof.

Scoped validators to run during an implementation callback:

- `python .\tools\validator.py --mode file --file by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md --apply --wait-generated --queue-timeout 240`
- If [UID:00006I] is edited: `python .\tools\validator.py --mode file --file by-class/IMEStatusPane.md --apply --wait-generated --queue-timeout 240`
- If [UID:0000K5] is edited or generated freshness matters: `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`

Generated freshness expectation after callback:

- `auto-generated/-ag-research-tracker.md` should move [UID:0004C0] above the `85` combined gate after validator refresh and later supervisor execution.
- `auto-generated/NexusTK/input/IMEPanes.cpp` should contain `IMEStatusPane::OnPaintFrame` or an equivalent emitted child method body after the file/class route refreshes through [UID:00006I] -> [UID:0000K5].

## Claim And Incorporation Ledger

| Claim | Evidence | Callback result |
| --- | --- | --- |
| [UID:0004C0] is one complete function at `0x004e7300-0x004e737b`. | MCP `lookup_funcs` id `113`, `get_bytes` id `115`, successor function at `0x004e7380`, five `0xcc` padding bytes. | `applied` to target Evidence and Reconstruction Notes; target records size `0x7b`, successor, and `0xcc` padding proof. |
| [UID:0004C0] is live virtual IMEStatusPane code, not padding/dead code. | MCP `xrefs_to` id `116` shows one vtable data xref at `0x0061c3a8`; [UID:00025J] documents IMEStatusPane vtables. | `applied` to target Evidence; target records the one data xref at `0x0061c3a8` and vtable-route interpretation. |
| Direct owner stays [UID:00006I]. | Target doc, class doc, aggregate split plan, vtable island, and status text field at `+0xf8`. | `applied`; target preserves `CANONICAL_OWNER:00006I` and sets `EMITTER_UIDS:00006I`. |
| Source file route is [UID:00006I] -> [UID:0000K5]. | [UID:00006I] emits through [UID:0000K5]; [UID:0000K5] owns IMEPanes source family. | `applied` to target Status/Reconstruction Notes; generated `auto-generated/NexusTK/input/IMEPanes.cpp` at latest observed header `000000003165` still emits the method through the class/file route. |
| Draw sequence is background fill `0x8f`, frame `0x80`, text color `0x80`, baseline left+2/bottom-2, `DrawWideText(statusText,length)`. | MCP decompile id `114`, bytes id `115`, helper pages [UID:000162], [UID:000168], [UID:00016C], [UID:0000TN]. | `applied` to target Behavior, Evidence, Reconstruction Notes, and formal C++ block. The support UID for draw-state accessors was corrected from stale report UID `000167` to current [UID:000162]. |
| `0x004b9600` should be `MoveTo`, not `SetTextPosition`. | MCP helper decompile id `121`; [UID:000162] names `MoveTo`. | `applied` to target Evidence/Reconstruction Notes and formal C++ block. |
| `0x004bab70` should be `DrawWideText`, not generic `DrawText`. | [UID:00016C] names `GrafPort::DrawWideText(const wchar_t *, int)` and current target passes wide text/count. | `applied` to target Evidence/Reconstruction Notes and formal C++ block. |
| Score should improve from `80/86` to `88/90`. | Current blockers resolved: emitter route, helper names, field roles, and first-draft C++. Remaining uncertainty is only exact stripped source spelling. | `applied`; target metadata is `COMPLETION:88` and `CONFIDENCE:90`; validator `000000003162` returned `ok: 1`. |
| No child split or new UID is needed. | Exact function size/padding and aggregate already has exact child page. | `applied`; target Reconstruction Notes explicitly rejects split/new UID. |

## Implementation Tracking Checklist

- [x] Lease only the files selected for the immediate callback edit batch; release leases after validation. Proof: leased only `by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md` as B007 before editing; later `unlease` returned `Rejected[No active lease]`, and current lease reports show no active B007 lease for the target.
- [x] Update [UID:0004C0] metadata to `88/90`, `EMITTER_UIDS:00006I`, owner/reconstructable unchanged, position blank. Proof: target header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006I`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006I`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Replace stale target notes that say helper names remain open with the resolved MCP-backed draw sequence. Proof: target Behavior/Evidence/Reconstruction Notes now record the six-step paint sequence and helper roles.
- [x] Insert the exact formal `IMEStatusPane::OnPaintFrame` C++ block from this report into [UID:0004C0]. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains the accepted method body; generated `IMEPanes.cpp` command `000000003162` emits the same [UID:0004C0] body.
- [x] Add target evidence for MCP ids `111`-`116` and `121`-`124`, including session health, function size, padding, vtable xref, helper boundary/decompile proof, and rejected alternatives. Proof: target Evidence/Reconstruction Notes include all listed MCP ids and the negative ownership/split evidence.
- [x] Update target score rationale with the exact before/after rationale from this report. Proof: target Score Rationale now explains `88/90`; target Changes section records before `80/86` and after `88/90`.
- [x] If edited, sync [UID:00006I] `IMEStatusPane.md` with a concise `OnPaintFrame` method note; otherwise record that existing owner/class support was already sufficient. Proof: not edited; current class page already has route, `[[CHILDREN]]`, `statusText[256]`, and `OnPaintFrame` declaration. Target page carries the accepted child-specific detail at report-level specificity.
- [x] If edited, sync [UID:0000K5] and/or [UID:000189] only with support detail accepted by supervisor; otherwise record no support edit needed. Proof: not edited; [UID:0000K5] and [UID:000189] already establish IMEPanes source ownership and exact split route, while the target page now carries the implementation detail.
- [x] Run `python .\tools\validator.py --mode file --file by-memory/0x004e7300-0x004e737b.IMEStatusPaneOnPaintFrame.md --apply --wait-generated --queue-timeout 240` and record command id, timestamp, exit code, ok count, warnings, and generated freshness. Proof: first run `000000003161` at `2026-06-30T15:56:18-04:00` exited `0`, `ok: 1`; final corrected-link run `000000003162` at `2026-06-30T15:57:17-04:00` exited `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Run additional scoped validators for any support pages edited. Proof: no support by-* pages were edited, so no additional support validator was required.
- [x] Inspect `auto-generated/NexusTK/input/IMEPanes.cpp` after the validator wait to confirm the generated output is equal/newer than the validator command and contains the accepted `IMEStatusPane::OnPaintFrame` cleanup. Proof: B007 validator `000000003162` refreshed generated output; later concurrent validator refreshes made the current header newer (`validator-command-id: 000000003165`, `validator-refreshed-at: 2026-06-30T16:01:13-04:00`). The latest observed file contains `// UID:0004C0` followed by `void IMEStatusPane::OnPaintFrame()` and no `Empty Emitter Marker` hit.
- [x] Release/confirm expiration of all leases and report final changed files, validator results, generated freshness, score/metadata before/after, and any exact blockers. Proof: B007 no longer has an active lease on the target; no blockers remain.

## Blockers

No implementation blocker remains for [UID:0004C0]. MCP was available and healthy, the exact function body is modeled, helper names have current doc and MCP support, no split/new UID is needed, and the owner/emitter/source route is implementation-ready.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0004C0-IMEStatusPaneOnPaintFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004C0-IMEStatusPaneOnPaintFrame-source-quality.md","timestamp":"2026-06-30T16:04:58","uid":"0004C0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
