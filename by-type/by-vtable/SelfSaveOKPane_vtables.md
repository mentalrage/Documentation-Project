*** UID:0001YV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// SelfSaveOKPane vtables are compiler-generated from SelfSaveOKPane.h;
// no hand-authored vtable array belongs in SelfSaveOKPane.cpp.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SelfSaveOKPane vtables

## Status

- Entity kind: vtable group and construction evidence.
- Owner: [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md)
- Address group: `0x0061e7a4`, `0x0061e81c`, `0x0061e84c`
- Exact by-memory child: [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md)
- Confidence: very strong for all three facet bases, physical extents, construction stores, target equality with `TextBoxPane`, the sole differing timer slot, and compiler-generation disposition.
- Evidence basis: IDA MCP `list_globals`, `xrefs_to`, `py_eval`, and decompile checks refreshed on 2026-06-01, 2026-06-07, and B002 MCP session `80de0a67` on 2026-06-26.

## Vtable Bases

| Address | IDA name | Role |
| --- | --- | --- |
| `0x0061e7a4` | `??_7SelfSaveOKPane@@6B@` | Primary SelfSaveOKPane vtable installed at object offset `+0x0`. |
| `0x0061e81c` | `??_7SelfSaveOKPane@@6B@_0` | Secondary SelfSaveOKPane vtable installed at object offset `+0xa0`. |
| `0x0061e84c` | `??_7SelfSaveOKPane@@6B@_1` | Timer-handler facet vtable installed at object offset `+0xa4`. |

## Known Slots

| Vtable | Slot address | Target | Notes |
| --- | --- | --- | --- |
| `0x0061e84c` | `0x0061e850` | `0x005148e0` | `SelfSaveOKPane::OnTimer`; IDA `xrefs_to 0x005148e0` reports this data xref, and B002 MCP bytes at `0x0061e850` are `e0 48 51 00`. |

The full inherited slot names are not resolved yet. Do not use nearby RTTI/data after the short timer facet as additional SelfSave virtual slots until the vtable extent is verified.

2026-05-26 IDA `py_eval` recheck confirms the timer facet slot at `0x0061e850` points to `0x005148e0`, and the next dword at `0x0061e854` is `??_R4MapRefreshDimmer@@6B@`, not another SelfSaveOKPane timer-facet slot.

2026-06-26 B002 MCP session `80de0a67` rechecked the source-facing name and behavior: `0x005148e0` is the timer callback now documented as `bool SelfSaveOKPane::OnTimer(int timerId, int, int)`. The callback subtracts the `+0xa4` timer-facet adjustment to reach the owner, calls owner primary slot `+0x38` (`0x0061e7dc -> 0x0055ef10`) for removal/detach when `timerId == 0`, scalar-deletes the owner, and returns `true`.

## UID0000NN Complete Facet Comparison - 2026-08-17

- The physical child `[0x0061e7a0,0x0061e854)` is exactly 180 bytes with SHA256 `2894048A9A4AE2A43C30267310E79B9EB409094DD400BBA006A2DB91714259E1`.
- Primary, secondary, and TimerHandler facet bases occupy `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`; their preceding COL cells are `0x0061e7a0`, `0x0061e818`, and `0x0061e848`.
- Target-by-target comparison with `TextBoxPane` shows the primary and secondary facets are inherited unchanged. The timer facet differs only at `0x0061e850`, which points to `SelfSaveOKPane::OnTimer` at `0x005148e0`. Therefore the human class declares one override and no other method or field solely to explain ABI data.
- Each facet base has exactly three constructor-store refs: MapPane `0x0050855b/61/6b`, factory `0x00513871/77/81`, and standalone constructor `0x00514829/2f/39`.
- The timer slot has one outbound target and `0x005148e0` has that sole inbound data xref. The following dword at `0x0061e854` is MapRefreshDimmer RTTI, so the timer facet cannot extend farther.
- Source emits no raw COL, RTTI, or vtable array. The exact `SelfSaveOKPane` declaration and virtual `OnTimer` regenerate this compiler data; the formal CPP marker makes that disposition explicit without duplicating bytes.
- `94/95` reflects complete facets, slots, refs, boundaries, class cause, and non-empty covered-by handling. Completion remains below 95 for final-project audit only.

## Dword-Level Slot Inventory

2026-06-07 A008 IDA MCP `py_eval` enumerated the exact by-memory child:

| Range | Role | Evidence |
| --- | --- | --- |
| `0x0061e7a0-0x0061e7a4` | primary COL/RTTI-adjacent word | `0x0064b31c`, named `??_R4SelfSaveOKPane@@6B@`. |
| `0x0061e7a4-0x0061e818` | primary vtable | `??_7SelfSaveOKPane@@6B@`; includes inherited `TextBoxPane`/pane-family targets and starts at `0x0048c4d0`. |
| `0x0061e818-0x0061e81c` | secondary COL/RTTI-adjacent word | `0x0064b3d4`, named `??_R4SelfSaveOKPane@@6B@_0`. |
| `0x0061e81c-0x0061e848` | secondary vtable | `??_7SelfSaveOKPane@@6B@_0`; starts at `0x0048c2e9` and carries adjusted pane/interface slots. |
| `0x0061e848-0x0061e84c` | timer-facet COL/RTTI-adjacent word | `0x0064b3e8`, named `??_R4SelfSaveOKPane@@6B@_1`. |
| `0x0061e84c-0x0061e854` | timer-facet vtable | `??_7SelfSaveOKPane@@6B@_1`; starts at `0x0048c2f4`, then owns only `0x0061e850 -> 0x005148e0`. |

## Boundary Evidence

- IDA MCP on 2026-06-01 shows `0x0061e7a0 -> 0x0064b31c`, followed by the primary `SelfSaveOKPane` vtable at `0x0061e7a4`.
- The secondary and tertiary RTTI-adjacent words are `0x0061e818 -> 0x0064b3d4` and `0x0061e848 -> 0x0064b3e8`; the vtables start at `0x0061e81c` and `0x0061e84c`.
- The timer-facet table has one owned slot at `0x0061e850 -> 0x005148e0`. The next dword `0x0061e854 -> 0x0064b3fc` belongs to `MapRefreshDimmer`, whose primary table starts at `0x0061e858`.
- 2026-06-07 A008 IDA MCP `py_eval` reconfirmed the predecessor `MapPane` tertiary table ending at `0x0061e7a0` and the successor `MapRefreshDimmer` RTTI word at `0x0061e854`.
- 2026-06-26 B002 evidence preserves [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) as factory/trigger support and `MapPane::HandlePacket` packet case `0x21` as a sibling inline construction route; neither changes the vtable owner.

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

- 2026-08-17 B007 UID0000NN accepted callback: raised `88/92` to `94/95`, populated the compiler-generated covered-by marker, and added exact physical hash, complete facet comparison, construction refs, sole-override proof, and no-raw-array disposition.
- 2026-06-26 B002 implementation sync for [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md): corrected the timer slot name from stale `OnTimerExpired` to source-facing `SelfSaveOKPane::OnTimer`, recorded live MCP slot bytes and owner-removal behavior, and preserved the factory/MapPane inline-construction boundaries.
- Previous: validator scores were `0/0`, and the page had vtable bases but no exact by-memory vtable-data child.
- Changed to: exact child [UID:0002OU][0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData](by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md) added, reconstruction flag set true, and scores raised conservatively below final-audit level.
- Evidence: IDA MCP on 2026-06-01 confirms the three RTTI/vtable view starts, store xrefs from standalone/inline/factory construction paths, the one-slot timer facet, and the neighboring `MapPane`/`MapRefreshDimmer` boundaries.
- 2026-06-07 A008 Batch 013: Raised `84/90` to `88/92` and attached to [UID:0000CX][SelfSaveOKPane](by-class/SelfSaveOKPane.md). Evidence: live IDA enumerated the exact dword-level primary/secondary/timer-facet layout, reconfirmed the construction store xrefs, and the class page now clears the corrected 85/85 direct-parent gate.
