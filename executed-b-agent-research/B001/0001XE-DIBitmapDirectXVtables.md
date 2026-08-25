** TARGET-REPORT-UID:0001XE **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
## Finalized Report / Current Recommendation

- Target: [UID:0001XE] `by-type/by-vtable/DIBitmapDirectXVtables.md`.
- Source row: `tools/leaser/Agents/Supervisor_notes.md`, B001-010, current supervisor classification `reviewed-85-but-ownership-unknown-under-review`.
- Current recommendation: keep `DIBitmapDirectXVtables` as a reconstructable parent-blank split inventory. Do not assign the master to one owner.
- Recommended status/classification: `reviewed-85-ownership-split`.
- Confidence: high, `87/92`. IDA MCP reconfirmed all slot dwords, xrefs, and boundaries; the remaining uncertainty is only final source-level spelling/details, not ownership.
- Concrete next action for A-agents/supervisor: accept the existing split. Keep [UID:0002MC] assigned to [UID:00003V] `DIBitmap`, keep [UID:0002MD] assigned to [UID:00003Y] `DirectX`, and keep [UID:0001XE] unassigned as the inventory node.
- Report status: final for B001-010; no active blocker.
- Lease/collision note: temporary lease override was active; no leases were created or released. No collision risk observed.

## Supporting Research

### Split Outcome

The current split is correct and did not need new type child pages. The existing exact by-memory children are the right direct ownership model because they correspond to the actual binary objects that source declarations generate.

| Item | Before B001-010 | After B001-010 | Parent decision |
| --- | --- | --- | --- |
| [UID:0001XE] `DIBitmapDirectXVtables.md` | `87/92`, blank parent, effectively split/unknown | `87/92`, blank parent, `reviewed-85-ownership-split` | Parent remains blank because it spans `DIBitmap` and `DirectX`. |
| [UID:0002MC] `0x00618e50-0x00618e60.DIBitmapVtableData.md` | `86/92`, parent [UID:00003V] | `86/92`, parent [UID:00003V] | Assignment confirmed. |
| [UID:0002MD] `0x00618e60-0x00618e70.DirectXVtableData.md` | `86/92`, parent [UID:00003Y] | `86/92`, parent [UID:00003Y] | Assignment confirmed. |
| [UID:000255] `0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md` | `80/90`, `RECONSTRUCTABLE:FALSE` | `80/90`, `RECONSTRUCTABLE:FALSE` | Non-owner `.rdata` index confirmed. |

### IDA MCP Evidence

B001-010 live IDA MCP was run on 2026-06-10 against `NexusTK.exe`, base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

Facts:

- `list_globals *DIBitmap*` reports `??_7DIBitmap@@6B@` at `0x00618e54` and `??_R4DIBitmap@@6B@` at `0x006467d0`.
- `list_globals *DirectX*` reports `??_7DirectX@@6B@` at `0x00618e64` and `??_R4DirectX@@6B@` at `0x0064681c`.
- DIBitmap dwords: `0x00618e50 -> 0x006467d0`, `0x00618e54 -> 0x004a1b10`, `0x00618e58 -> 0x004f4b10`, `0x00618e5c -> 0x0041b6c0`.
- DirectX dwords: `0x00618e60 -> 0x0064681c`, `0x00618e64 -> 0x004a1cd0`, `0x00618e68 -> 0x004f4b10`, `0x00618e6c -> 0x0041b6c0`.
- `lookup_funcs` confirms `0x004a1b10` size `0x4e`, `0x004a1cd0` size `0x9a`, inherited/shared slot `0x004f4b10` size `0x6`, and `0x0041b6c0` `nullsub_18` size `0x3`.
- `xrefs_to 0x00618e54` returns DIBitmap-context refs at `0x004a1638`, raw `0x004a1746`, `0x004a195c`, and `0x004a1b19`.
- `xrefs_to 0x00618e64` returns DirectX-context refs at `0x004a1bbf`, `0x004a1c88`, and `0x004a1cf8`.
- `xrefs_to 0x00618e70` returns DirectX constructor string refs at `0x004a1bfb` and `0x004a1c31`.
- Byte decoding of `0x00618e70-0x00618efc` confirms the DirectX UTF-16 diagnostic text `DirectX not installed, or is corrupted. Please install DirectX again.`
- `0x00618efc -> 0x006468bc`, `??_R4EmployeeDialogPane@@6B@`, confirming the exclusive end of the DirectX/DIBitmap read-only-data island.

Inference:

- `0x00618e50-0x00618e60` is a complete `DIBitmap` RTTI/vtable record and directly belongs to the `DIBitmap` class declaration.
- `0x00618e60-0x00618e70` is a complete `DirectX` RTTI/vtable record and directly belongs to the `DirectX` class declaration.
- The master type page is useful as an inventory because the records are adjacent, but adjacency is linker layout evidence only and does not imply one source owner.

### Candidate Ranking

1. Keep the split and use exact children: selected. It matches IDA facts and by-structure direct-parent rules.
2. Assign the master to `DIBitmap`: rejected. It would incorrectly own the `DirectX` vtable and DirectX diagnostic string boundary.
3. Assign the master to `DirectX`: rejected. It would incorrectly own the `DIBitmap` vtable.
4. Assign the master to `DirectXBitmapReadOnlyData`: rejected. [UID:000255] is a non-reconstructable `.rdata` index, not a source owner.
5. Create a new combined `DIBitmapDirectX` source owner: rejected. No IDA evidence supports a combined source unit; class/file docs already provide gate-cleared owners.

### Documentation Evidence

Existing docs mostly matched the binary evidence:

- [UID:00003V] `DIBitmap` is `86/87` and assigned to [UID:0000IV] `DIBitmap`, which is `86/86`.
- [UID:00003Y] `DirectX` is `85/88` and assigned to [UID:0000IW] `DirectX`, which is `85/88`.
- Generated memory coverage already showed [UID:0002MC] assigned to `00003V` and [UID:0002MD] assigned to `00003Y`.
- Generated type coverage already showed [UID:0001XE] unassigned, which is correct for the split inventory.

Stale or weak documentation repaired:

- The master page still used nonstandard active wording `reviewed-85-but-ownership-split`; it now uses `reviewed-85-ownership-split`.
- The child pages had old audit text and duplicated generated link text in change logs; this was clarified without changing scores or parents.
- [UID:000255] still implied the class/file parent gates were unresolved; it now says the exact children have resolved gates and the remaining gap is the DirectX string child.
- Manual coverage rows for [UID:0000IV] and [UID:00003V] still showed stale `84%` and `78%` values; they now match the actual docs.

### Files Changed

- `by-type/by-vtable/DIBitmapDirectXVtables.md`: added B001-010 audit evidence and active split classification.
- `by-memory/0x00618e50-0x00618e60.DIBitmapVtableData.md`: added B001-010 assignment audit and fixed stale link text.
- `by-memory/0x00618e60-0x00618e70.DirectXVtableData.md`: added B001-010 assignment audit and fixed stale link text.
- `by-memory/0x00618e50-0x00618efc.DirectXBitmapReadOnlyData.md`: updated child gate wording and B001 audit note.
- `by-type/by-vtable/-coverage-report.md`: updated the [UID:0001XE] row to show B001-010 verified split status.
- `by-file/-coverage-report.md`: updated [UID:0000IV] row from stale `84%` to `86%`.
- `by-class/-coverage-report.md`: updated [UID:00003V] row from stale `78%` to `86%`.

### Validation

Targeted validator commands were run with `--apply`; each returned `ok: 1`:

_Executable command block removed from the research report; preserved in [0001XE-DIBitmapDirectXVtables-removed.md](0001XE-DIBitmapDirectXVtables-removed.md)._

Generated reports remained in the intended state: [UID:0002MC] assigned to `00003V`, [UID:0002MD] assigned to `00003Y`, [UID:000255] not reconstructable, and [UID:0001XE] unassigned.

### Remaining Follow-Up

- No new ownership split work is required for [UID:0001XE].
- Optional future work: create or improve an exact DirectX string/data child for `0x00618e70-0x00618efc` under the DirectX owner if `.rdata` string coverage is later prioritized.
- Optional future work: final C++ reconstruction for `DIBitmap` and `DirectX` still needs final source spelling and private field names; this does not block the vtable ownership decision.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001XE-DIBitmapDirectXVtables.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001XE"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001XE-DIBitmapDirectXVtables-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001XE-DIBitmapDirectXVtables.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001XE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
