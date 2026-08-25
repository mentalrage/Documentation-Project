*** UID:0001Z2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer Vtable

## Status

- Entity kind: MSVC vtable inventory.
- Owner class: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md).
- Owner module/source root: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md).
- Rebuild handling: source-declared/generated-binary. The source class declaration/destructor shape should regenerate the table; do not hand-port table bytes.
- Exact memory child: [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md).

## Table

IDA names the table `??_7WaitableTimer@@6B@` at `0x00631188`. The complete-object-locator pointer is immediately before it at `0x00631184` and resolves to `??_R4WaitableTimer@@6B@`.

| Slot | Target | Notes |
| --- | --- | --- |
| `+0x00` | `0x005c1210` | `WaitableTimer` scalar deleting destructor. |

Observed vptr stores:

- `0x005c1020`: constructor store.
- `0x005c10a8`: cleanup body store.
- `0x005c121b`: scalar deleting destructor store.

The dword at `0x0063118c` is the complete-object locator for `WeatherLayerPane`, followed by `WeatherLayerPane`'s vtable at `0x00631190`. Do not read those adjacent records as extra `WaitableTimer` slots.

## Current MCP Evidence

- The accepted 2026-08-04 B005 report used sole healthy read-only session `b002-uid0004hs-persist-reopen`, PID `20412`, and canonical IDB disk snapshot SHA-256 `CE0222E87E1A569A73EB43DD72BF53412B103DD9281A535EEC2BCC01DE0932FA` (`143196420` bytes). This is dated evidence; current IDA authority remains a fresh-gate readback concern.
- B005 2026-06-23 accepted report uses IDA MCP session `ff68e691`.
- `get_bytes 0x00631184 size 12` returned `a4 3f 65 00 10 12 5c 00 ec 3f 65 00`, meaning `0x00631184 -> 0x00653fa4` (`WaitableTimer` COL), `0x00631188 -> 0x005c1210`, and `0x0063118c -> 0x00653fec` (`WeatherLayerPane` COL).
- `xrefs_to 0x00631188` reports the three vtable stores from `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- `xrefs_to 0x005c1210` reports the destructor data xref from this vtable slot.
- The accepted fresh pass reconfirmed that the table has exactly one method slot and exactly three stores to `0x00631188`; neither the six-byte internal UID0001NY fence nor the following WeatherLayerPane locator is part of this table.

## Parent Rationale

Attach this vtable page to [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md), the narrow class owner. [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md) remains the source root. The vtable identity supports class ownership for [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md) and its raw helper children, but this vtable page itself emits no C++.

[UID:0001NY][0x005c1120-0x005c11b5.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b5.WaitableTimerRawStartStop.md) is now a reviewed false/non-emitting split inventory. The one-slot vtable and three class stores strengthen class ownership for its exact source-bearing children without creating an aggregate source body.

## Reconstruction And Score Rationale

- Completion/confidence `92/95` reflects the exact locator/slot/successor dwords, scalar deleting destructor target, complete three-store inventory, one-slot boundary, class/file route, and source-generation disposition.
- Keep CPP/H blank here. A human class declaration and virtual destructor shape should regenerate the table; hand-porting RTTI/vtable dwords would be compiler-artifact source.
- Exact original class access/spelling is not PDB-proven, but the binary table identity and boundaries are direct evidence. Historical Wave2/Wave3 statements do not control this page.

## Cross-References

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md)

## Changes

- 2026-08-04 B005 UID0001NY Rule 26 support implementation:
  - Raised from `86/90` to `92/95`, synchronized the table with UID0001NY's non-emitting split status, and preserved the exact one-slot/WeatherLayerPane boundary.
  - Added current report-time provenance, exact store/count scope, reconstruction handling, owner/source route, score rationale, and historical evidence treatment.
- 2026-06-23 B005 implementation:
  - Added current MCP session `ff68e691` byte/xref confirmation and preserved the one-slot vtable / WeatherLayerPane boundary.
