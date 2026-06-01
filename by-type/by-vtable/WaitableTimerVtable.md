*** UID:0001Z2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer Vtable

## Status

- Entity kind: MSVC vtable inventory
- Owner class: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- Owner module: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- Confidence: confirmed
- Evidence: 2026-05-26 IDA MCP `py_eval` over `.rdata` entries and vtable data xrefs.
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

The dword at `0x0063118c` is the complete-object locator for `WeatherLayerPane`, and `0x00631190` begins `WeatherLayerPane`'s vtable. Do not read those adjacent records as extra `WaitableTimer` slots.

## Boundary Evidence

- IDA MCP `py_eval` on 2026-06-01 reads `0x00631184` as the `WaitableTimer` RTTI-adjacent word pointing to `??_R4WaitableTimer@@6B@`.
- `0x00631188` is named `??_7WaitableTimer@@6B@` and has constructor/cleanup/destructor store xrefs at `0x005c1020`, `0x005c10a8`, and `0x005c121b`.
- `0x0063118c` points to `??_R4WeatherLayerPane@@6B@`, followed by `??_7WeatherLayerPane@@6B@` at `0x00631190`, proving that the waitable timer table is a one-slot vtable and ends before `0x0063118c`.

## Cross-References

- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- What existed before: this page listed the one-slot vtable, but kept completion/confidence at `0/0`, cited generated Wave3 metadata caveats, and did not have a precise by-memory child range.
- What changed: completion/confidence is now `84/90`, `RECONSTRUCTABLE` is marked `TRUE`, the generated-data caveat was replaced with IDA MCP boundary evidence, and the exact child range [UID:0002P2][0x00631184-0x0063118c.WaitableTimerVtableData](by-memory/0x00631184-0x0063118c.WaitableTimerVtableData.md) was added.
- Evidence: IDA MCP `py_eval` on 2026-06-01 read the RTTI/vtable dwords and xrefs at `0x00631184-0x0063118c`, with `WeatherLayerPane` RTTI beginning at `0x0063118c`.
