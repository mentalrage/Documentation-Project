*** UID:0001YV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SelfSaveOKPane vtables

## Status

- Entity kind: vtable group and construction evidence.
- Owner: [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- Address group: `0x0061e7a4`, `0x0061e81c`, `0x0061e84c`
- Exact by-memory child: [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md)
- Confidence: strong for the three vtable bases and timer virtual slot; medium for full slot naming.
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `py_eval`, and decompile checks refreshed on 2026-06-01.

## Vtable Bases

| Address | IDA name | Role |
| --- | --- | --- |
| `0x0061e7a4` | `??_7SelfSaveOKPane@@6B@` | Primary SelfSaveOKPane vtable installed at object offset `+0x0`. |
| `0x0061e81c` | `??_7SelfSaveOKPane@@6B@_0` | Secondary SelfSaveOKPane vtable installed at object offset `+0xa0`. |
| `0x0061e84c` | `??_7SelfSaveOKPane@@6B@_1` | Timer-handler facet vtable installed at object offset `+0xa4`. |

## Known Slots

| Vtable | Slot address | Target | Notes |
| --- | --- | --- | --- |
| `0x0061e84c` | `0x0061e850` | `0x005148e0` | `SelfSaveOKPane::OnTimerExpired`; IDA `xrefs_to 0x005148e0` reports this data xref. |

The full inherited slot names are not resolved yet. Do not use nearby RTTI/data after the short timer facet as additional SelfSave virtual slots until the vtable extent is verified.

2026-05-26 IDA `py_eval` recheck confirms the timer facet slot at `0x0061e850` points to `0x005148e0`, and the next dword at `0x0061e854` is `??_R4MapRefreshDimmer@@6B@`, not another SelfSaveOKPane timer-facet slot.

## Boundary Evidence

- IDA MCP on 2026-06-01 shows `0x0061e7a0 -> 0x0064b31c`, followed by the primary `SelfSaveOKPane` vtable at `0x0061e7a4`.
- The secondary and tertiary RTTI-adjacent words are `0x0061e818 -> 0x0064b3d4` and `0x0061e848 -> 0x0064b3e8`; the vtables start at `0x0061e81c` and `0x0061e84c`.
- The timer-facet table has one owned slot at `0x0061e850 -> 0x005148e0`. The next dword `0x0061e854 -> 0x0064b3fc` belongs to `MapRefreshDimmer`, whose primary table starts at `0x0061e858`.

## Xrefs

IDA `xrefs_to` for the three vtable bases reports the same construction writes from three places:

| Ref group | Meaning |
| --- | --- |
| `0x00514829`, `0x0051482f`, `0x00514839` | Standalone [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md). |
| `0x0050855b`, `0x00508561`, `0x0050856b` | Inline construction inside [UID:0000L3][MapPane](by-file/MapPane.md) packet case `0x21`. |
| `0x00513871`, `0x00513877`, `0x00513881` | Standalone [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md). |

## Cross-References

- [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md)
- [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md)
- [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md)
- [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)

## Changes

- Previous: validator scores were `0/0`, and the page had vtable bases but no exact by-memory vtable-data child.
- Changed to: exact child [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) added, reconstruction flag set true, and scores raised conservatively below final-audit level.
- Evidence: IDA MCP on 2026-06-01 confirms the three RTTI/vtable view starts, store xrefs from standalone/inline/factory construction paths, the one-slot timer facet, and the neighboring `MapPane`/`MapRefreshDimmer` boundaries.
