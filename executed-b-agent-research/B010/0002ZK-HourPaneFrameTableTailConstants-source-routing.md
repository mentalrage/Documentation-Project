** TARGET-REPORT-UID:0002ZK **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002ZK HourPaneFrameTableTailConstants Source Routing Report

Status: FINISHED report-only checkpoint for [UID:0002ZK] `HourPaneFrameTableTailConstants`.

Assignment id: `B010-goal2-hourpane-frame-table-tail-constants-source-routing-0002ZK-20260619`

Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants.md`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\0002ZK-HourPaneFrameTableTailConstants-source-routing.md`

## Current Recommendation

- Keep [UID:0002ZK] as reviewed non-emitting orphan initialized `.data`.
- Recommended metadata: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal `RECONSTRUCTION_CPP`.
- Do not fold this range into [UID:00027K] `g_hourFrameTable` / `HourPane`.
- Do not route this range to [UID:00027L] / `ImageLoaders` / JPEG decode.
- Do not mark it as compiler/linker padding. The values are real initialized bytes, but current evidence does not prove a source-level owner, type, name, or consumer.
- Do not emit first-draft C++ for this target. A standalone `static const` array would invent source shape and ownership for a no-xref, no-name, untyped data tail.

The source-quality disposition is resolved, not deferred: the best-supported rebuild policy is "preserve/review as orphan initialized data in the data-section audit, but do not generate source from this page unless later live evidence proves a real consumer or source owner."

## Evidence Checked

- Read required workflow instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B010/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
  - `source-3/project-documentation/by-project-structure/proposed-source-tree.md`
- Read target [UID:0002ZK] and neighbors:
  - [UID:00027K] `by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md`
  - [UID:0002ZK] `by-memory/0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants.md`
  - [UID:00027L] `by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md`
- Read support docs:
  - `by-global/g_hourFrameTable.md`
  - `by-file/HourPane.md`
  - `by-class/HourPane.md`
  - `by-memory/0x004cee60-0x004cf1ef.HourPane.md`
  - `by-resource/hourpane-time-resources.md`
  - `by-file/ImageLoaders.md`
  - `by-global/ImageDecodeJpegEoiMarker.md`
  - `by-memory/-ignored.md`
  - `by-memory/-coverage-report.md`
  - `auto-generated/-ag-memory-coverage.md`
  - `project-level/-auto-completion-stats.md`
- Attempted live IDA MCP at `127.0.0.1:13337`; the server was unavailable (`Unable to connect to the remote server`). New statements below therefore distinguish local export/doc checks from prior live IDA evidence already recorded in target/support pages.
- Searched local export/docs for address and value routes:
  - `rg` for `0x0066db1c`, `0066db1c`, `0x66db1c`, `66db1c`, `DAT_0066db1c`, `DAT_0066DB1C`, `66DB1C` across `exports` and scoped project docs.
  - `rg` for `0xfe7f`, `0xFE7F`, `FE7F`, `fe7f`, `0x0240`, `0x240` across `exports` and scoped project docs.
  - `rg --files -g "*.exe" -g "*.dll" -g "*.bin" -g "*.idb" -g "*.i64" -g "*.map" -g "*.pdb"` from the workspace root found no local PE/IDA/map/PDB image to independently reread raw section bytes.
- Checked local IDA export JSON:
  - `exports/004cf010.json` (`HourPane::OnPaint`): confirms `&DAT_0066db04 + (((hour / 2) % 0xc) * 2)` for both `TIME.EPF` and `TIME.EPD` paths.
  - `exports/004e4e70.json` (image decode callback): confirms fallback output `&DAT_0066db3c` and length `2`.
  - `exports/005adad0.json`: contains one address-like immediate `(cls_0x427990 *)0x66db1c`, but `data_refs` is empty and the helper actually reads/copies [UID:00027J] `g_emptySimpleUString` through `DAT_0066daec`, `DAT_0066dafc`, and `DAT_0066db00`.
  - `exports/00514640.json`: only ordinary caller of `0x005adad0`; it is a UI/collection update path and has `data_refs: []`, so it does not make the `0x66db1c` immediate a tail-byte consumer.
- Rechecked constants with `tools/int_convert.py`:
  - `0x0240` is decimal `576`.
  - `0xfe7f` is decimal `65151`.

## Exact Bytes And Data-Item State

Prior live IDA evidence recorded in the target page remains the controlling byte evidence:

- Range: `0x0066db1c-0x0066db3c`, 32 bytes.
- Bytes: `00 00 7f fe` followed by twelve `40 02` words, then `7f fe 00 00`.
- Little-endian word view: `0x0000`, `0xfe7f`, twelve `0x0240` words, `0xfe7f`, `0x0000`.
- IDA item state from A002/A007: no name at `0x0066db1c`; untyped one-byte `.data` items; adjacent labels are `word_66DB04` at `0x0066db04`, `unk_66DB3C` at `0x0066db3c`, and `unk_66DB40` at `0x0066db40`.
- Prior live IDA xref state: byte-level `XrefsTo` over every byte in `0x0066db1c-0x0066db3c` found no references. Earlier even-address scans from `0x0066db1c` through `0x0066db3a` were also empty.

This target should not be typed as source `uint16_t[16]`. The word view is a useful audit interpretation, but IDA has no source name/type and there is no live consumer that proves 16 words, 14 meaningful words, a sentinel layout, coordinates, dimensions, or any other source-facing structure.

## Boundary Recheck

### Lower Boundary: [UID:00027K] `HourPaneFrameTable`

[UID:00027K] covers `0x0066db04-0x0066db1c` and has exact bytes for twelve little-endian words: `10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9`.

Prior live IDA records exactly two data refs to `word_66DB04`, both inside `HourPane::OnPaint` at `0x004cf060` and `0x004cf0f7`. Local export `exports/004cf010.json` independently shows both branches compute:

```c
*(short *)(&DAT_0066db04 + (((int)(char)this->mbr_0xf8 / 2) % 0xc) * 2)
```

The maximum index is `11`, so the last reachable word starts at `0x0066db1a`. The next address, `0x0066db1c`, is outside the proven HourPane table extent. The physical adjacency is not enough to make the tail part of `g_hourFrameTable`.

### Upper Boundary: [UID:00027L] `ImageDecodeJpegEoiMarkerSlot`

[UID:00027L] starts exactly at `0x0066db3c` and covers `ff d9 00 00`. Prior live IDA records one data ref at `0x004e4e92`; local export `exports/004e4e70.json` shows:

```c
*puVar1 = &DAT_0066db3c;
puVar1[1] = 2;
```

The image-decode callback starts from `0x0066db3c` and returns a 2-byte EOI marker. It does not read or address the preceding tail at `0x0066db1c-0x0066db3c`.

## Value-Consumer Scan Result

The only new suspicious lead is `exports/005adad0.json`, where the decompiler prints a pointer-identity guard against `(cls_0x427990 *)0x66db1c`. This is rejected as a consumer for [UID:0002ZK]:

- The export has `data_refs: []`.
- The expression is a pointer comparison, not a load from `0x0066db1c`.
- The helper's actual data source is [UID:00027J] `g_emptySimpleUString`: it selects `&DAT_0066daec` or `DAT_0066daec` depending on `DAT_0066db00`, then copies `DAT_0066dafc` bytes.
- The only caller export checked, `exports/00514640.json`, is a UI/collection reset/update route and also has `data_refs: []`.
- The same helper also prints a guard against `&DAT_0066db04`, which is the start of the HourPane table, reinforcing that these are decompiler pointer-bound artifacts around an object/array walk rather than real reads of the tail constants.

The scoped value scan for `0xfe7f`/`0x0240` did not reveal a meaningful documented consumer. Generated struct-field-name noise such as `field_0xfe7f` or common offset `field_0x240` hits is not evidence of value use.

## Heuristic / Inference Reanalysis And Validation

Ownership candidates ranked:

1. Accepted: `NONE`, reviewed orphan initialized data.
   - Evidence: no name, no source type, no direct xrefs to any byte in prior live IDA, no local export/documented consumer after value scan, and both live neighbors have exact separate owners and exact boundaries.
   - Source-routing consequence: no owner/emitter, no source C++.

2. Rejected: [UID:0000JX] `HourPane` / [UID:0002ZE] `g_hourFrameTable`.
   - Evidence for consideration: physical adjacency after the HourPane frame table and repeated word-like constants.
   - Rejection: the only proven HourPane consumer uses base `0x0066db04` with `(hour / 2) % 12`; the last reachable word is at `0x0066db1a`; target starts at `0x0066db1c`.

3. Rejected: [UID:0000K3] `ImageLoaders` / JPEG decode.
   - Evidence for consideration: immediate successor [UID:00027L] is JPEG EOI marker storage.
   - Rejection: the image callback uses exact address `0x0066db3c` and length `2`; no xref or callback path reaches the preceding `0x0066db1c-0x0066db3c` range.

4. Rejected: compiler/linker padding.
   - Evidence for consideration: no xrefs and placement between unrelated initialized data items.
   - Rejection: bytes are patterned non-fill initialized data (`0x0000`, `0xfe7f`, repeated `0x0240`, `0xfe7f`, `0x0000`), not a normal alignment fill pattern.

5. Possible but unprovable: stale source-authored constants, dead table data, or object-file/data-section packing residue.
   - Evidence for consideration: real patterned values and no current consumers.
   - Limitation: no source name, relocation, symbol, map/PDB/object-file evidence, or live consumer. This is not enough to assign a hidden owner or emit a source declaration.

Best defensible source-level inference: this is real initialized data retained in the executable image, probably from a source/object data neighborhood or stale constant table, but current evidence cannot name it or attach it to HourPane/ImageLoaders. Treat it as orphan initialized data in documentation, not as final source.

## No-Code Proof And First-Draft C++ Readiness

Formal C++ should remain blank.

Target-specific no-code proof:

- No function reads, addresses, or indexes this range in prior live IDA evidence.
- Local exports show the live HourPane consumer stops before the range and the live image-decode consumer starts after the range.
- The only address-like local export hit is a non-deref immediate in a string/UI reset helper with no data ref.
- IDA has no source name/type at `0x0066db1c`.
- Emitting a declaration such as `static const uint16_t s_unknownTail[] = {...};` would create an unsupported source object and could falsely imply ownership, meaningful element type, or intentional source reachability.

If future evidence proves a consumer, this page should be reopened and routed to that consumer's direct source owner. Until then, this target is `RECONSTRUCTABLE:FALSE` with no emitter.

## Recommended Target And Support Updates

### Target Doc

Update `by-memory/0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants.md`:

- Change metadata from `COMPLETION:82`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank C++.
- Add the local B010 value-consumer scan result, especially the rejected `0x005adad0` immediate `0x66db1c` false positive.
- Clarify that the word view is diagnostic only and should not be treated as source `uint16_t[16]`.
- Clarify that the range is not padding and not part of the HourPane frame table, but still has no source owner/emitter.
- Add a change entry for the B010 2026-06-19 source-routing pass.

### Support Docs

Recommended if implementation is accepted:

- Update `by-memory/-ignored.md` entry for `0x0066db1c-0x0066db3c` with the B010 false-positive value-consumer scan, explicit non-HourPane/non-ImageLoaders routing, and new `88/91` recommendation.
- Update the supervisor-owned `by-memory/-coverage-report.md` row using the exact replacement row below. B010 must not edit this file directly.
- No required changes to [UID:00027K] `HourPaneFrameTable`, `by-global/g_hourFrameTable.md`, `by-file/HourPane.md`, `by-class/HourPane.md`, or `by-resource/hourpane-time-resources.md`; these already exclude the tail. Optional implementation wording can add that B010 rechecked the value-consumer lead and still keeps the tail outside HourPane ownership.
- No required changes to [UID:00027L] `ImageDecodeJpegEoiMarkerSlot`, `by-global/ImageDecodeJpegEoiMarker.md`, or `by-file/ImageLoaders.md`; these already prove the `0x0066db3c` start boundary. Optional implementation wording can add that B010 rechecked and rejects routing the preceding tail to ImageLoaders/JPEG decode.
- No range split/merge correction is recommended. Keep [UID:00027K] `0x0066db04-0x0066db1c`, [UID:0002ZK] `0x0066db1c-0x0066db3c`, and [UID:00027L] `0x0066db3c-0x0066db40`.

## Exact Pending Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` as B010. Supervisor-owned exact replacement row:

```text
    - [UID:0002ZK][0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants](by-memory/0x0066db1c-0x0066db3c.HourPaneFrameTableTailConstants.md) 0x0066db1c-0x0066db3c | orphan initialized data / value-scan negative tail constants | HourPaneFrameTableTailConstants : ignored/non-emitting : 88% : very strong : B010 2026-06-19 source-routing recheck keeps this as reviewed non-emitting orphan `.data`, not HourPane, ImageLoaders/JPEG, or padding. Exact bytes remain `00 00 7f fe` + twelve `40 02` words + `7f fe 00 00` (`uint16_t` audit view: `0x0000`, `0xfe7f`, twelve `0x0240` words, `0xfe7f`, `0x0000`). Prior live IDA byte-level `XrefsTo` scan found no refs to any byte; current local export/doc value scan found only a rejected `0x005adad0` immediate `0x66db1c` false positive with no data ref/deref, while actual consumers still use `g_emptySimpleUString`. [UID:00027K] ends at `0x0066db1c` because `HourPane::OnPaint` indexes only `word_66DB04[((hour / 2) % 12)]`, and [UID:00027L] starts at `0x0066db3c` because image decode writes `&DAT_0066db3c` length `2`. Keep `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitter/C++; reopen only if live IDA/relocation/runtime evidence proves a real consumer or source owner.
```

## Validation Commands Needed If Accepted

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` for every edited file:

> Executable block R001 was removed from this report and preserved verbatim in [0002ZK-HourPaneFrameTableTailConstants-source-routing-removed.md](0002ZK-HourPaneFrameTableTailConstants-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If optional support docs are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0002ZK-HourPaneFrameTableTailConstants-source-routing-removed.md](0002ZK-HourPaneFrameTableTailConstants-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

No validator was run for this report-only checkpoint because no target/support by-* docs were edited.

## IDA Rename / Type / Comment Recommendations

- `0x0066db1c`: do not assign a source-quality global name. Confidence: high.
- `0x0066db1c`: do not type as source `uint16_t[16]`. At most, use a local analysis/comment view of the bytes/words. Confidence: high.
- `0x0066db1c`: optional repeatable comment: `Unreferenced initialized data tail after g_hourFrameTable; no xrefs to any byte; not HourPane table, not JPEG marker, not padding; keep non-emitting unless a consumer is found.` Confidence: high.
- `0x0066db04`: keep/rename toward `g_hourFrameTable` for [UID:00027K]. Confidence: high.
- `0x0066db3c`: keep/rename toward `g_imageDecodeJpegEoiMarker` or equivalent image-decode fallback marker name for [UID:00027L]. Confidence: high.
- `0x005adad0`: optional analysis comment that the immediate `0x66db1c` printed by decompilation is not a data ref and should not be treated as a [UID:0002ZK] consumer. Confidence: medium.

## Open Questions And Attempted Resolution

- Why do the bytes exist in the executable?
  - Best answer: real orphan initialized `.data`, likely from retained object/data-section neighborhood or stale constants.
  - Evidence checked: exact bytes, no xrefs, no name/type, neighbors, local export value scan, no local PE/map/PDB, live IDA unavailable.
  - Remaining limitation: no source symbol, map, object file, relocation record, or live runtime consumer proves original source intent.
- Could the repeated `0x0240` values be screen-width or coordinate constants?
  - Possible as a raw value pattern, but unsafe. No consumer proves dimensions, coordinates, or element semantics.
- Could this be compiler/linker padding?
  - No. The non-fill pattern makes padding unlikely; the correct disposition is orphan initialized data, not padding.
- Could this be hidden HourPane source data?
  - Rejected. The only HourPane xrefs and local decompilation prove a 12-word modulo table ending before this range.
- Could this be hidden ImageLoaders/JPEG data?
  - Rejected. The image callback addresses exactly `0x0066db3c` and length `2`; the target ends before that marker begins.

## Implementation Readiness

Ready for supervisor review and, if accepted, a narrow documentation implementation:

- Target doc metadata/prose update.
- `by-memory/-ignored.md` update.
- Supervisor-owned coverage row update only by supervisor or later authorized implementation path.
- Optional neighbor/support one-liners only if the supervisor wants the value-scan result duplicated outside the target and ignored pages.

No target/support files were edited for this report-only checkpoint.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002ZK-HourPaneFrameTableTailConstants-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002ZK"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002ZK-HourPaneFrameTableTailConstants-source-routing-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0002ZK-HourPaneFrameTableTailConstants-source-routing.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002ZK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
