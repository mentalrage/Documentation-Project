## FINAL REPORT / CURRENT RECOMMENDATION

- Target: [UID:000225] `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`
- Assignment: B001-019, supervisor status `reviewed-85-but-ownership-unknown-under-review`
- Final recommendation: split the old helper-family page into exact children, create/assign a narrow [UID:00032J] `by-file/Crc16.md` source owner, attach the exact helper children and backing table page to `Crc16`, and keep [UID:000225] as a parent-blank non-emitting aggregate/index.
- Recommended classification for [UID:000225]: `ignored` / `RECONSTRUCTABLE:FALSE` non-emitting aggregate; exact children are reconstructable.
- Confidence: high, `88/91` for the aggregate decision; `86/88` for the new `Crc16` source owner. The remaining uncertainty is exact original filename/function spelling, not ownership scope.
- Concrete next action: supervisor can accept B001-019 as repaired. Optional project-structure follow-up: add `NexusTK/util/Crc16.cpp` / `.h` to `by-project-structure/proposed-source-tree.md`; I did not edit project-level files under B001 scope.
- Report state: final.

## Exact Child Decisions

| UID | Path | Final state |
| --- | --- | --- |
| [UID:000225] | `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md` | `88/91`, `RECONSTRUCTABLE:FALSE`, parent blank; non-emitting aggregate/index. |
| [UID:00032K] | `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md` | `85/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00032J] `Crc16`. |
| [UID:00032L] | `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md` | `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00032J] `Crc16`. |
| [UID:00032M] | `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md` | `85/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00032J] `Crc16`. |
| [UID:00032N] | `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md` | `86/90`, `RECONSTRUCTABLE:TRUE`, parent [UID:00032J] `Crc16`. |
| [UID:00027A] | `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` | `88/92`, `RECONSTRUCTABLE:TRUE`, parent [UID:00032J] `Crc16`. |
| [UID:00032J] | `by-file/Crc16.md` | new `86/88` source owner, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`. |

No additional helper child files are missing for the `0x0049bbf0-0x0049bca9` range. Internal padding spans `0x0049bc0d-0x0049bc10` and `0x0049bc47-0x0049bc50` are recorded in `by-memory/-ignored.md` and nested coverage rows.

## Supporting Research

### Binary Evidence

- IDB: `NexusTK.exe`, base `0x400000`, md5 `4247e04e20b65d6414c7238aa8ff5515`, sha256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA MCP `lookup_funcs` reports `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, and `0x0049bc70` are not modeled function starts; `0x0049bcb0` is the next modeled function.
- IDA MCP `callers` and `xrefs_to` report no direct callers or entrypoint refs to the four helper starts.
- Raw loaded-segment scan found no little-endian pointer constants, direct `E8` calls, or direct `E9` jumps to `0x0049bbf0`, `0x0049bc10`, `0x0049bc50`, or `0x0049bc70`.
- Table refs are exact: `word_66D480` at `0x0066d480` is referenced at `0x0049bbff` and `0x0049bc2c`; `word_66D680` at `0x0066d680` is referenced at `0x0049bc5f` and `0x0049bc92`.
- Byte checks confirm code/padding split: code bodies at `0x0049bbf0-0x0049bc0d`, `0x0049bc10-0x0049bc47`, `0x0049bc50-0x0049bc70`, `0x0049bc70-0x0049bca9`; padding at `0x0049bc0d-0x0049bc10`, `0x0049bc47-0x0049bc50`, and `0x0049bca9-0x0049bcb0`.
- Table sampling confirms `0x0066d480`, `0x0066d680`, and MapPane table body `0x0066db50` all use the `0x1021` CRC-CCITT opening sequence; only `0x0066d480`/`0x0066d680` are referenced by this helper island.

### Ownership Ranking

1. [UID:00032J] `Crc16` new narrow util source file: accepted. The code/table pair is internally coherent, all exact helper children and table data clear `85/85`, the parent page clears `85/85`, and no stronger existing owner has caller/xref evidence.
2. Keep source items parent-blank: rejected as too passive after split. It would leave four reconstructable helper bodies and their exclusive tables unattached despite a defensible narrow source owner.
3. [UID:0000L3] `MapPane`: rejected. Its separate table [UID:00027N] has MapPane packet/tile xrefs, but there is no caller bridge to these helper starts or tables.
4. [UID:0000PC] `Zlib` / [UID:0000KW] `LodePNG`: rejected. Those are stock third-party CRC-32/Adler/PNG families at unrelated ranges; this is a 16-bit CRC-CCITT-style utility pair.
5. [UID:0000II] `Crasher`: rejected. Address adjacency only; the Crasher range ends before `0x0049bbef` padding and shares no xrefs/state.
6. [UID:0000LI] `Monitor` / critical-section helpers: rejected. Address adjacency only after `0x0049bca9-0x0049bcb0` padding; no CRC/table semantics.

### Proposed File Scope

`Crc16` should stay narrow:

- Include the four exact helper functions [UID:00032K] through [UID:00032N].
- Include the two-table data page [UID:00027A].
- Keep [UID:000225] only as a non-emitting index.
- Exclude [UID:00027N] MapPane checksum table despite identical bytes because its direct xrefs are MapPane-specific.
- Exclude zlib/LodePNG checksum code and tables because those are third-party and algorithmically/source-wise separate.

This is likely a small utility file, not a broad checksum subsystem.

## Changed Files

- Created: `by-file/Crc16.md`
- Created: `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`
- Created: `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`
- Created: `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`
- Created: `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`
- Updated: `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`
- Updated: `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`
- Updated: `by-memory/-coverage-report.md`
- Updated: `by-memory/-ignored.md`
- Updated: `by-file/-coverage-report.md`
- Updated: this report.

Validator also refreshed validator-owned generated/autogen state during normal file scans. No leases were created per the active temporary lease override, and I saw no collision risk.

## Validation

Targeted `validator.py --mode file --file <path> --apply` scans returned `ok: 1` for:

- `by-file/Crc16.md`
- `by-memory/0x0049bbf0-0x0049bc0d.Crc16WordStep.md`
- `by-memory/0x0049bc10-0x0049bc47.Crc16WordBuffer.md`
- `by-memory/0x0049bc50-0x0049bc70.Crc16ByteStep.md`
- `by-memory/0x0049bc70-0x0049bca9.Crc16ByteBuffer.md`
- `by-memory/0x0049bbf0-0x0049bca9.ChecksumTableHelpers.md`
- `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `by-file/-coverage-report.md`

After a final stale-wording patch, `by-memory/0x0066d47c-0x0066d880.ChecksumLookupTablesData.md` was rerun and again returned `ok: 1`.

## Remaining Issues

- Exact original filename and helper names are inferred as `Crc16`, not debug-proven.
- No direct runtime call path is present in the current IDA database; the helper island appears retained/unreferenced.
- Optional supervisor/project-structure action: add the new `Crc16` util source root to proposed source-tree documentation if desired.
