** TARGET-REPORT-UID:000276 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:000276] BalloonObjectPaneStaticMasks

## Assignment

- Agent: B004
- Assignment id: `B004-report-000276-balloon-object-pane-static-masks-20260625`
- Target: [UID:000276][by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md](../../../../../by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md)
- Required disposition for this turn: report only. No by-* docs, generated files, project-level files, coverage reports, validator/tool-state files, lock files, or IDA DB state were edited.

## Recommendation

Implement after supervisor validation.

- Target score recommendation: `COMPLETION:89`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:00000U`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00000U`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Replace the stale "95+ final-source gate" blocker. The active C++ gate is satisfied: reconstructable true, nonblank emitter route, and `(89 + 93) / 2 = 91`, above the current threshold.
- Update the target summary wording that still says "current AttachedObjectPane parent assignment"; the direct owner is already the class [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), while [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md) remains the source-file route.

Recommended formal insertion for the target page's `RECONSTRUCTION_CPP CODE` block:

```cpp
static unsigned char s_balloonFrameMasks[6][4] = {
    { 0xC6, 0x28, 0x10, 0x10 },
    { 0x10, 0x10, 0x28, 0xC6 },
    { 0x30, 0x40, 0x80, 0x80 },
    { 0xC0, 0x20, 0x10, 0x10 },
    { 0x80, 0x80, 0x40, 0x30 },
    { 0x10, 0x10, 0x20, 0xC0 },
};
```

Use a writable, non-`const` table because the target is initialized writable `.data`. I recommend byte rows instead of `uint32_t`/`DWORD` entries: the live consumer passes each entry address as a packed bitmask base into `dword_69B3F8`, and the slot-6 callback docs describe byte/bit traversal from the mask base. The current dword values remain useful documentation, but a byte-row initializer is less endian-dependent and matches the callback's mask-pointer role.

## Current Target State

The target page currently has `COMPLETION:86`, `CONFIDENCE:92`, owner/emitter [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), `RECONSTRUCTABLE:TRUE`, and a blank C++ block. Its evidence is strong, but its reconstruction notes still treat unresolved renderer helper names and original table symbol spelling as a C++ blocker. That is too broad for this 24-byte data target.

Generated/project artifacts are stale relative to the direct target page: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/map/AttachedObjectPane.cpp` still show `000276` as `72/88` with an empty marker. Those files must be refreshed by the validator after an authorized implementation, not edited by hand.

## Live IDA MCP Session

MCP was available and current. This is not a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- Session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`

## Direct MCP Evidence

### Bytes And Boundaries

Live MCP `get_bytes` confirms the exact local layout:

- `0x0066d408-0x0066d430`: `00 04 00 00 01 00 00 00 44 d5 00 00 c6 28 10 10 10 10 28 c6 30 40 80 80 c0 20 10 10 80 80 40 30 10 10 20 c0 3c 37 61 00`.
- `0x0066d412-0x0066d414`: `00 00`, matching [UID:00035O][PaddingBeforeBalloonObjectPaneMasks](../../../../../by-memory/0x0066d412-0x0066d414.PaddingBeforeBalloonObjectPaneMasks.md).
- `0x0066d414-0x0066d42c`: the target 24-byte table (`0x18` / 24 bytes, Verified with `int_convert.py`) containing six 4-byte entries (`0x4` / 4 bytes, Verified with `int_convert.py`).
- `0x0066d42c-0x0066d430`: `3c 37 61 00`, the little-endian `0x0061373c` AutoInit vptr successor value. `0x0061373c` / 6371132 and bytes `3c 37 61 00` were verified with `int_convert.py`.

Live MCP `make_signature_for_range(0x0066d414, 0x0066d42c, wildcard_operands=false)` returns `C6 28 10 10 10 10 28 C6 30 40 80 80 C0 20 10 10 80 80 40 30 10 10 20 C0` and marks it `unique: true`. Live `find_bytes` also found each four-byte entry pattern only at its expected table address.

### Table Values

| Address | Bytes | Dword value | Decimal/source | Direct xrefs |
| --- | --- | --- | --- | --- |
| `0x0066d414` | `C6 28 10 10` | `0x101028C6` | 269494470 from MCP `get_int`; bytes verified with `int_convert.py` | `0x00467e58` |
| `0x0066d418` | `10 10 28 C6` | `0xC6281010` | 3324514320 from MCP `get_int`; bytes verified with `int_convert.py` using signed 32-bit equivalent `-970452976` | `0x00467ef6` |
| `0x0066d41c` | `30 40 80 80` | `0x80804030` | 2155888688 from MCP `get_int`; bytes verified with `int_convert.py` using signed 32-bit equivalent `-2139078608` | `0x00467c24`, `0x00467cce` |
| `0x0066d420` | `C0 20 10 10` | `0x101020C0` | 269492416 from MCP `get_int`; bytes verified with `int_convert.py` | `0x00467c59`, `0x00467d03` |
| `0x0066d424` | `80 80 40 30` | `0x30408080` | 809533568 from MCP `get_int`; bytes verified with `int_convert.py` | `0x00467c8d`, `0x00467d34` |
| `0x0066d428` | `10 10 20 C0` | `0xC0201010` | 3223326736 from MCP `get_int`; bytes verified with `int_convert.py` using signed 32-bit equivalent `-1071640560` | `0x00467d66` |

`lookup_funcs` reports `0x0066d414` and `0x0066d42c` are not functions. The table is compact initialized data, not code.

### Xrefs And PaintBubble Consumer

Live MCP `xrefs_to` and `xref_query` confirm all nine table-entry xrefs are data refs from `sub_467B30`, size `0x711` / 1809 bytes (Verified with `int_convert.py`), documented as `BalloonObjectPane::PaintBubble`:

- `0x0066d414`: `0x00467e58`
- `0x0066d418`: `0x00467ef6`
- `0x0066d41c`: `0x00467c24`, `0x00467cce`
- `0x0066d420`: `0x00467c59`, `0x00467d03`
- `0x0066d424`: `0x00467c8d`, `0x00467d34`
- `0x0066d428`: `0x00467d66`

Live MCP `analyze_function(0x00467b30)` decompiles `sub_467B30` as `int __thiscall(int this, int, int *)`, with callees including `sub_4B7C50`, `unk_69B3E4`, `unk_69B3F8`, and `unk_69B3FC`. It reads `this + 0x1d8` / 472 (Verified with `int_convert.py`) for the tail/orientation branch, builds rectangles with `sub_4B7C50`, and passes table entries to the slot-6 packed-bitmask callback.

Representative live `insn_query` callsite slices:

- `0x00467c24`: `push offset unk_66D41C`; `0x00467c29`: `call dword ptr unk_69B3F8`.
- `0x00467c59`: `push offset unk_66D420`; `0x00467c5e`: `call dword ptr unk_69B3F8`.
- `0x00467c8d`: `push offset unk_66D424`; `0x00467c92`: `call dword ptr unk_69B3F8`.
- The alternate orientation branch uses the same entry set at `0x00467cce`, `0x00467d03`, and `0x00467d34`.
- The shared follow-up calls use `0x0066d428` at `0x00467d66`, `0x0066d414` at `0x00467e58`, and `0x0066d418` at `0x00467ef6`.

Live callback-slot filtering shows PaintBubble is a consumer of shared Surface/GrafPort infrastructure, not the owner of those globals:

- `0x0069b3e4` has 26 total data refs, with 8 in `sub_467B30`.
- `0x0069b3f8` has 12 total data refs, with 9 in `sub_467B30`; these are the mask-table draw calls.
- `0x0069b3fc` has 206 total data refs, with 2 in `sub_467B30`.

[UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md) already documents slot 6 (`0x0069b3f8`) as a packed-bitmask blit/composition callback and records PaintBubble as a concrete consumer only. The exact public callback typedef remains open, but it is not needed to declare this static table.

## Heuristic And Source-Quality Reanalysis

Best direct owner remains [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md). Every table-entry xref is in `BalloonObjectPane::PaintBubble`; no evidence points to reuse by `Surface`, `GrafPort`, `AttachedObjectPane`, or a broader data-section owner. [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md) is still the source-file route (`NexusTK/map/AttachedObjectPane.cpp`), but it is not the narrowest semantic owner.

Best source-facing name is `s_balloonFrameMasks`. `s_balloonTailMasks` is too narrow: four entries are corner/frame pieces on both orientation branches, and the first two entries are tail/frame follow-up pieces. Raw `unk_66D414` names should remain evidence labels only.

The unresolved original symbol spelling is not a blocker. The B-agent standard allows defensible descriptive names when original names are not recoverable, and this table has a single, exact consumer plus unique bytes. Per-entry symbolic names are not needed; array indices preserve the source order and let later `PaintBubble` code pass `s_balloonFrameMasks[n]`.

The unresolved `dword_69B3F8` callback typedef is also not a blocker. It affects the future `PaintBubble` method body and Surface callback documentation, not the binary-exact declaration of this 24-byte source data table. The target page should say the callback signature remains support context rather than using it to keep C++ blank.

I do not recommend a new `by-type/by-static-member` page for this pass. The exact storage and direct owner are already represented by this by-memory page and the BalloonObjectPane class page. A separate static-member page would duplicate evidence without improving source placement.

## Ranked Alternatives

1. `BalloonObjectPane` class UID `00000U`: accept. It owns the only consumer, the speech-balloon rendering role, and the source-file emission route through `AttachedObjectPane.cpp`.
2. `AttachedObjectPane.cpp` file UID `0000HJ`: keep as route only. It groups attached overlay classes but is broader than the actual table owner.
3. `SurfaceRenderCallbackTable` / `Surface` UID `0000TN` / `0000OC`: reject for table ownership. The table is an argument to Surface callbacks, not callback-table storage or callback implementation.
4. Enclosing `.data` section or neighboring globals: reject. The predecessor is non-source padding and the successor is an unrelated AutoInit vptr; the mask table is a self-contained 24-byte declaration.

## Score And Metadata Recommendation

- Before: direct target page `86/92`; stale generated rows still show `72/88`.
- After implementation: `89/93`.
- Reason completion should rise: the stale no-code rationale is resolved, current MCP evidence reconfirms unique bytes/xrefs/boundaries, and a formal binary-exact static initializer is now available.
- Reason confidence should rise slightly: current MCP independently rechecked the table and consumer, and the byte-row source type matches the slot-6 bitmask callback role.
- Reason not to go higher: original symbol spelling, future `PaintBubble` body naming, and final Surface callback typedefs remain unresolved outside this target.

## Implementation Tracking Checklist

- [x] After supervisor callback, lease only the target page and any support pages explicitly edited; report-only work used no leases.
  - Proof: implementation pass confirmed B004 leases in `tools/leaser/Agents/current_leases.md` for the three edited by-* pages only: target [UID:000276], class [UID:00000U], and method island [UID:0000YZ], created `2026-06-25T10:58:06Z` and expiring `2026-06-25T11:03:06Z`. After the validator batch, `python .\tools\leaser\leaser.py B004 unlease ...` reported no active lease, and a fresh `current_leases.md` read showed no B004 rows.
- [x] In [UID:000276][target page](../../../../../by-memory/0x0066d414-0x0066d42c.BalloonObjectPaneStaticMasks.md), update `COMPLETION` to `89` and `CONFIDENCE` to `93`.
  - Proof: target header now reads `COMPLETION:89` and `CONFIDENCE:93`; validator command `000000001423` confirmed `completion_update 000276 ... 89`, `confidence_update 000276 ... 93`, and `ok: 1`.
- [x] Keep target `CANONICAL_OWNER:00000U`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000U`.
  - Proof: target metadata still carries `CANONICAL_OWNER:00000U`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000U`; validator command `000000001423` confirmed `canonical_owner_update 000276 ... 00000U`.
- [x] Replace the blank target `RECONSTRUCTION_CPP CODE` block with the exact `static unsigned char s_balloonFrameMasks[6][4]` initializer above.
  - Proof: target lines 9-18 contain the accepted initializer exactly, and generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` now emits the same block at its UID `000276` entry.
- [x] Update target summary/status to say direct class owner `00000U`, file route `0000HJ`, current 2026-06-25 MCP evidence, and generated rows stale until validation.
  - Proof: target summary now names direct [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), file route [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md), current 2026-06-25 MCP evidence, and the stale-generated-row state before the accepted scoped validator refresh.
- [x] Replace the reconstruction note that says "leave C++ blank" with the current-gate rationale: renderer callback typedef and original symbol spelling are support caps, not target blockers.
  - Proof: target Reconstruction Notes now say to emit writable file-local `static unsigned char s_balloonFrameMasks[6][4]` and explicitly classify original symbol spelling plus `unk_69B3F8` callback typedef as support confidence caps.
- [x] Update target table notes to keep dword values as documentation while making the formal source declaration byte-row based.
  - Proof: target Summary, Table Entries, and Reconstruction Notes now preserve all dword values while stating the accepted source declaration is byte-row based.
- [x] In [UID:00000U][BalloonObjectPane](../../../../../by-class/BalloonObjectPane.md), update the static mask bullet to name `s_balloonFrameMasks` and note that the child data page now has formal C++; no class score change is required.
  - Proof: class Status now names `s_balloonFrameMasks` and formal writable byte-row child C++; class score remains `85/90`. Validator command `000000001424` completed with `ok: 1` and generated refresh completed.
- [x] In [UID:0000YZ][BalloonObjectPane method island](../../../../../by-memory/0x00467b30-0x0046904e.BalloonObjectPane.md), replace "s_balloonFrameMasks or s_balloonTailMasks" with `s_balloonFrameMasks`; keep the aggregate C++ blank.
  - Proof: method-island Static Masks section now says to reference `s_balloonFrameMasks` and rejects `s_balloonTailMasks` as too narrow; the page's formal C++ block remains blank. Validator command `000000001426` completed with `ok: 1` and generated refresh completed.
- [x] Optional support note only if already editing nearby prose: [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md) can mention that the static mask child has source-ready data, but no score change is required.
  - Proof: not applicable for this implementation batch; [UID:0000HJ][AttachedObjectPane](../../../../../by-file/AttachedObjectPane.md) was not edited because the accepted required edits were satisfied by the target, class support page, and method-island support page.
- [x] Do not edit [UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md); it already records PaintBubble as a consumer and correctly keeps callback ownership in Surface/GrafPort infrastructure.
  - Proof: [UID:0000TN][SurfaceRenderCallbackTable](../../../../../by-global/SurfaceRenderCallbackTable.md) was not edited.
- [x] Do not hand-edit generated files, project-level stats, manual coverage reports, validator state, or tool-state files. Let the validator refresh stale `72/88` generated rows.
  - Proof: only by-* pages and this B004 research report were manually edited. The generated/project-level/tool-state changes were validator-owned side effects from file-mode commands `000000001423`, `000000001424`, and `000000001426`; no manual `-coverage-report.md` files were edited.
- [x] From `source-3/project-documentation`, run validator on the target after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [000276-BalloonObjectPaneStaticMasks-source-quality-removed.md](000276-BalloonObjectPaneStaticMasks-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- [x] Target validator proof: command `000000001423`, timestamp `2026-06-25T07:02:18-04:00`, exit code `0`, `ok: 1`, `generated_refresh: completed`, `generated_refresh_command_id: 000000001423`.
- [x] If support pages are edited, validate each edited file with the same file-mode validator command.
  - Proof: class support page validator command `000000001424`, timestamp `2026-06-25T07:02:40-04:00`, exit code `0`, `ok: 1`, generated refresh completed. Method-island support page validator command `000000001426`, timestamp `2026-06-25T07:03:02-04:00`, exit code `0`, `ok: 1`, generated refresh completed. The validators reported pre-existing reference warnings (`000163` missing target on the class page; `0003TN`/`0003Z4` missing from `validator.ini` on the method-island page) but did not fail.
- [x] After validation, confirm `auto-generated/NexusTK/map/AttachedObjectPane.cpp` no longer shows UID `000276` as an empty `72/88` marker and that project/generated trackers reflect the direct page score.
  - Proof: generated `auto-generated/NexusTK/map/AttachedObjectPane.cpp` header now reads `validator-command-id: 000000001427`, `validator-refreshed-at: 2026-06-25T07:03:24-04:00`, and UID `000276` as `Completion:89 | Confidence:93`, immediately followed by the emitted `s_balloonFrameMasks[6][4]` initializer. It no longer appears as an empty `72/88` marker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/000276-BalloonObjectPaneStaticMasks-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/000276-BalloonObjectPaneStaticMasks-source-quality.md","timestamp":"2026-06-25T07:11:12","uid":"000276"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000276-BalloonObjectPaneStaticMasks-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/000276-BalloonObjectPaneStaticMasks-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000276"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
