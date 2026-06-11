## Finalized Report / Current Recommendation

- Target: [UID:000116] `by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md`.
- Assignment: B001-017.
- Report state: final.
- Current recommendation: keep [UID:000116] parent-blank as a non-emitting duplicate inventory/container. Do not assign or emit the aggregate.
- Recommended classification: `RECONSTRUCTABLE:FALSE`, ignored/non-emitting duplicate aggregate, `COMPLETION:86`, `CONFIDENCE:90`, parent blank.
- Confidence: high for the duplicate-container decision. IDA MCP confirms the range consists of two exact code-shaped ProgressBarControlPane helper bodies plus alignment; exact child pages carry the source ownership.
- Concrete next action for supervisor/A-agents: accept/archive B001-017. Future source work should happen on exact children [UID:000115] and [UID:000117] or the ProgressBarControlPane parent docs, not on the duplicate aggregate.
- New child files created: none. Exact split children [UID:000115] and [UID:000117] already existed and were audited/repaired.
- Collision/lease status: no leases were created per temporary supervisor override; no collision risk was observed.

## Exact Child Decisions

| UID | Range / page | Final B001-017 decision |
| --- | --- | --- |
| [UID:000115] | `0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter` | Repaired from `82/88` to `85/88`; remains reconstructable and attached to [UID:0000AW] `ProgressBarControlPane` class. |
| [UID:000117] | `0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter` | Repaired from `82/88` to `85/88`; remains reconstructable and attached to [UID:0000AW] `ProgressBarControlPane` class. |
| [UID:000116] | `0x00494a90-0x00494b4b.ProgressBarRangeSetters` | Converted from source-bearing aggregate to `RECONSTRUCTABLE:FALSE`, parent-blank non-emitting duplicate inventory over `000115`, padding, and `000117`. |
| ignored span | `0x00494ae7-0x00494af0` | Existing nine-byte `0xcc` alignment between children; remains ignored. |

## Supporting Research

### IDA MCP Evidence

- `lookup_funcs` reports `0x00494a90`, `0x00494ae7`, `0x00494af0`, and `0x00494b4b` as not IDA function starts.
- `lookup_funcs` confirms nearby anchors: `0x00494b50` is modeled as `sub_494B50` size `0x27`, `0x00494c80` is modeled as `sub_494C80` size `0x12a`, and `0x00494de0` is modeled as `sub_494DE0` size `0xd0`.
- `xrefs_to` and `callers` for raw helper starts `0x00494a90` and `0x00494af0` are empty, matching projected private helper status.
- Byte audit confirms `0x00494a90-0x00494ae7` is an 87-byte helper body ending in `retn 4`, followed by nine `0xcc` bytes at `0x00494ae7-0x00494af0`.
- Byte audit confirms `0x00494af0-0x00494b4b` is a 91-byte helper body ending in `retn 4`, followed by five `0xcc` bytes at `0x00494b4b-0x00494b50`.
- Disassembly of `0x00494a90` shows a `thiscall`-shaped lower-bound setter: clamps the short argument to `0..30000`, writes `this+0xf8`, raises current field `this+0xfa` if needed, and invalidates through vtable slot `+0x20`.
- Disassembly of `0x00494af0` shows the sibling upper-bound setter: clamps the short argument to `0..30000`, writes `this+0xfc`, lowers current field `this+0xfa` if needed, and invalidates through vtable slot `+0x20`.
- Constructor/vtable anchors confirm class ownership: `0x00494c80-0x00494daa` stores ProgressBarControlPane vtable bases at `0x00494cc5`, `0x00494ccb`, and `0x00494cd5`; draw virtual `0x00494de0` is referenced by vtable data at `0x00617b78`.
- Scratch evidence saved at `tools/leaser/Agents/Agent-B001/research/scratch/000116-ida-progressbar-range-setters.json`.

### Ownership Rationale

- The exact children are valid source-bearing ProgressBarControlPane helper pages. Both use the same field triplet `0xf8`/`0xfa`/`0xfc`, the same invalidation vtable slot, and the same constructor/draw/vtable anchors documented by [UID:0000AW] and [UID:0000MT].
- The master aggregate is not a valid direct source owner because assigning it would duplicate exact child ranges already attached to the ProgressBarControlPane class.
- A new owner/file is not justified. Existing [UID:0000MT] `ProgressBarControlPane` already covers the constructor, draw virtual, vtables, and projected helper family; IDA evidence supports that owner rather than a new `ProgressBarRangeSetters.cpp` style split.

### Documentation Changes Made

- `by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md`
  - Changed to `RECONSTRUCTABLE:FALSE`, `86/90`, parent blank.
  - Added B001-017 duplicate-aggregate rationale and live IDA evidence.
- `by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md`
  - Raised to `85/88` with B001-017 IDA evidence.
- `by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md`
  - Raised to `85/88` with B001-017 IDA evidence.
- `by-memory/-coverage-report.md`
  - Synced `000116` as ignored/non-emitting duplicate aggregate.
  - Synced `000115` and `000117` to `85%` reconstructable child rows.
- `by-memory/-ignored.md`
  - Added an ignored-ledger entry for `0x00494a90-0x00494b4b` as a duplicate aggregate, without ignoring exact children.
- `by-file/-coverage-report.md`
  - Updated ProgressBarControlPane row to reflect B001-017 exact-child ownership and non-emitting aggregate decision.
- `by-class/-coverage-report.md`
  - Updated ProgressBarControlPane row to reflect B001-017 exact-child ownership and non-emitting aggregate decision.
- `tools/leaser/Agents/Agent-B001/research/000116-ProgressBarRangeSetters.md`
  - Replaced checkpoint with this final report.

### Validation

Targeted validator command used for each touched documentation file:

`python source-3/project-documentation/tools/validator.py --mode file --file <path> --apply`

All targeted validations returned `ok: 1`. Logs were saved under:

`source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/validation-logs/B001-017/`

Validated files:

- `by-memory/0x00494a90-0x00494b4b.ProgressBarRangeSetters.md` - `ok: 1`
- `by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md` - `ok: 1`
- `by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md` - `ok: 1`
- `by-memory/-coverage-report.md` - `ok: 1`
- `by-memory/-ignored.md` - `ok: 1`
- `by-file/-coverage-report.md` - `ok: 1`
- `by-class/-coverage-report.md` - `ok: 1`

### Final Recommendation

Accept B001-017 as complete. [UID:000116] should remain a parent-blank, non-emitting duplicate inventory at `86/90`. Exact child pages [UID:000115] and [UID:000117] are the source-bearing ProgressBarControlPane range setters and now clear `85/88` under the existing ProgressBarControlPane class/file owner path.
