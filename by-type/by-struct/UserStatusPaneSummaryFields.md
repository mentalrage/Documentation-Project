*** UID:0001WF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane Summary Fields

## Status

- Current state: `91/94` non-reconstructable/non-emitting layout support with complete `UserStatusPane` tail offsets and source-facing roles; no standalone source type.
- Direct owner class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- Owner file route: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Related generated alias: [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md)
- Output route: none; this page documents offsets used by `UserStatusPane` source, while class/method pages emit source.
- Evidence basis: IDA MCP decompilation of `0x005b83b0`, the covered accessors in [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md), and `0x005ba4a0`. Current `simroot_v2` is only a search lead for the stale `CharacterSummaryRecord` alias.

## Layout Slice

This is the field slice currently emitted as the pseudo-class `CharacterSummaryRecord`. Offsets are normalized to the `UserStatusPane` object base.

| Offset | Type | Evidence | Meaning |
| --- | --- | --- | --- |
| `+0x0fc` | `wchar_t[64]` | constructor, `0x005b85b0` | Primary character/name/title line copied out by `CopyNameLineA`. |
| `+0x17c` | `wchar_t[64]` | constructor, `0x005b8670` | Display line A set by callback-backed setter. |
| `+0x1fc` | `wchar_t[64]` | constructor, `0x005b85d0`, `0x005b86a0` | Secondary character/status line copied out and set by callback-backed setter. |
| `+0x27c` | `uint16` | constructor, `0x005b8620`, payload parser | Nation id; accessor returns the low byte while legacy/EPF payload paths establish word storage. |
| `+0x27e` | `int8` | `0x005b8630` | Spirit/totem id. |
| `+0x27f` | `uint8` | [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) | Selected status icon id. |
| `+0x280` | `uint8` | constructor, `0x005ba4a0` | Class id. |
| `+0x281` | `uint8` | `0x005b85f0` | Percent/stat byte A. |
| `+0x282` | `uint8` | `0x005b8600` | Percent/stat byte B. |
| `+0x283` | `uint8` | `0x005b8610` | Percent/stat byte C. |
| `+0x284` | `uint8` | constructor writes `52`; inventory/item-pane consumers validate against it | Inventory slot count / maximum item-slot selector byte for the active local user. |
| `+0x285` | `uint8[3]` | alignment between slot count and dwords | Natural/explicit tail padding; never a semantic field. |
| `+0x288` | `uint32` | constructor, flag `0x20`, paint | Status row 8 partial/current value. |
| `+0x28c` | `uint32` | accessor, flag `0x40`, paint | Status row 8 full/maximum value. |
| `+0x290` | `uint32` | constructor, flag `0x20`, paint | Status row 9 partial/current value. |
| `+0x294` | `uint32` | accessor, flag `0x40`, paint | Status row 9 full/maximum value. |
| `+0x298` | `uint32` | accessor, flag `0x10`, paint | Status row 10 value. |
| `+0x29c` | `uint32` | flag `0x10`, paint | Status row 11 value. |
| `+0x2a0` | `int32` | legacy position/movement helpers, paint | Position X. |
| `+0x2a4` | `int32` | legacy position/movement helpers, paint | Position Y. |
| `+0x2a8` | `uint16` | EPF payload offsets 26-27 | EPF status tail word 0. |
| `+0x2aa` | `uint16` | EPF payload offsets 28-29 | EPF status tail word 1; class size closes at `0x2ac`. |

## Notes

- Constructor, accessor, payload, movement, and paint evidence now resolves every slot from `+0x288` through the `0x2ac` class end. Earlier opaque/display-pair/reserved-tail labels are historical decompiler-era assumptions and are rejected by complete cross-method use.
- `+0x284` is not just a default constructor byte: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md), [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md), [UID:0000FG][UseInputPane](by-class/UseInputPane.md), [UID:000047][EatInputPane](by-class/EatInputPane.md), [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md), and [UID:0000G0][WearInputPane](by-class/WearInputPane.md) read it as the maximum valid item slot when mapping `a-z` to `1-26` and `A-Z` to `27-52`.
- `SetDisplayLineA` and `SetDisplayLineB` call the primary vtable slot at offset `+0x20` with `this+0x44`, matching a pane invalidation/refresh callback pattern.
- The generated name `CharacterSummaryRecord` is useful as search vocabulary, but the layout belongs to `UserStatusPane`.
- B004's 2026-06-20 local PE recheck keeps the source-facing names provisional: `+0x0fc` may be final `m_nameText`/`m_characterName`, `+0x17c` is mutable display line A/title line, `+0x1fc` may be final `m_secondaryLine`/`m_displayLineB`, `+0x27d` remains the unresolved high byte of the constructor word at `+0x27c`, and `+0x288`, `+0x290`, `+0x29c`, `+0x2a0`, and `+0x2a4` should not receive forced final names until payload/paint consumers are source-quality.
- Current receiver evidence is class-wide: representative callers pass [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) itself as `ecx`, not an embedded record pointer. This reinforces the layout-slice classification and rejects a standalone `CharacterSummaryRecord` type.
- The adjacent raw signed getter at `0x005b86d0-0x005b86d8` reads `+0x27e` with sign extension and has no local rel32 or absolute refs in the B004 local PE scan. Keep it as a future exact-child/split caveat, not part of the generated alias.

## IDA Evidence

- 2026-05-31 IDA MCP decompilation of the constructor at `0x005b83b0` installs `UserStatusPane` vtables, stores `dword_69AE0C`, copies the first incoming string into object offset `+0x0fc`, clears the `+0x288` through `+0x2a4` region, writes `+0x284 = 52`, initializes bytes/words around `+0x27c`, and loads the same `9X11FONT.BIN` resource path used by the pane.
- 2026-05-31 IDA MCP decompilation of the accessor island confirms `+0x0fc`, `+0x1fc`, `+0x281`, `+0x282`, `+0x283`, `+0x27c`, `+0x27e`, `+0x28c`, `+0x294`, `+0x298`, and `+0x17c` as actual object offsets; [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) separately confirms `+0x27f`.
- 2026-05-31 IDA MCP decompilation of the status-payload updater at `0x005ba4a0` writes the same fields from packet-controlled flag groups: `+0x27e`, `+0x280`, `+0x281`, `+0x282`, `+0x283`, `+0x284`, `+0x288`, `+0x28c`, `+0x290`, `+0x294`, `+0x298`, and `+0x29c`.
- 2026-06-11 IDA MCP refresh reconfirmed modeled starts and sizes for the constructor, accessor island, status-icon setter, packet router, and payload updater. `0x005b86d0` is still not an IDA function, but raw disassembly from existing memory docs shows it as a sibling signed getter for `+0x27e`.
- 2026-06-11 IDA MCP decompilation reconfirmed constructor writes at `+0x0fc`, `+0x17c`, `+0x1fc`, `+0x27c`, `+0x27e`, `+0x282`, `+0x284`, and cleared dwords from `+0x288` through `+0x2a4`; accessors return byte offsets `+0x281/+0x282/+0x283/+0x27c/+0x27e`, dwords `+0x28c/+0x294/+0x298`, and text setters copy to `+0x17c/+0x1fc` before invalidating through vtable slot `+0x20`.
- 2026-06-11 IDA MCP caller refresh confirms the constructor is called from `InitializeMainUiGraph` at `0x004f837a`, the text/display accessors are consumed by user/status/inventory UI callers, the status icon setter has one direct caller at `0x005aad65`, and the payload updater is called by the `UserStatusPane` router at `0x005b8736`.

## Layout-Support Decision

`CANONICAL_OWNER` remains [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) as semantic layout ownership, but B009 changes this page to `RECONSTRUCTABLE:FALSE` with blank `EMITTER_UIDS`. This is a class-owned layout slice, not a standalone `CharacterSummaryRecord` source file: the constructor initializes these fields in the `UserStatusPane` object, the accessor methods are assigned to the same class, and the packet updater mutates the same offsets.

B004 and B009 both reject a separate source type. The generated `CharacterSummaryRecord` name remains search vocabulary for a pseudo-class alias, while actual source declarations and method bodies belong to [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md), [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), and [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md).

## Remaining Caveats

- No source-emission blocker remains. This page intentionally keeps blank formal C++ because the exact fields are declared once by UID0000FS, while this page is non-reconstructable layout evidence.
- Original variable spellings are unavailable, but each current semantic role is supported by at least two of constructor/accessor/payload/paint/movement evidence. The generated `CharacterSummaryRecord`, signed nation byte, unknown `+0x27d`, display-pair, and reserved-tail descriptions survive only as rejected historical search vocabulary.

## Cross-References

- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0001PE][0x0069ae0c-0x0069ae10.g_activeUserStatusPane](by-memory/0x0069ae0c-0x0069ae10.g_activeUserStatusPane.md)
- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md)

## Changes

- 2026-07-20 B001 UID0001NM callback: raised to `91/94`; resolved the `uint16` nation field, class id, three-byte alignment, row 8/9 partial/full values, row 10/11 values, x/y positions, EPF tail words, and exact `0x2ac` closure. Preserved non-reconstructable/blank-emitter status and historicalized all opaque/pseudo-record assumptions.
- 2026-06-30 B009 implementation callback:
  - Changed `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE` and cleared `EMITTER_UIDS`.
  - Summary/evidence: accepted B009 report applies B004's `CharacterSummaryRecord` rejection at source-output level. This page preserves field-layout evidence under [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) but no longer appears as an empty source emitter.
- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and medium-confidence notes based partly on generated `simroot_v2` vocabulary.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP decompilation of the constructor, accessor island, and status-payload updater confirmed the listed offsets and `UserStatusPane` ownership. Scores remain below 95 because several neighboring payload fields still lack final source names and no final C++ declaration has been audited.
- 2026-06-11 A005 assignment refresh:
  - What existed before: `COMPLETION:76`, `CONFIDENCE:88`, and blank `AUTOGEN_PARENT_UID`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, and `AUTOGEN_PARENT_UID:0000FS`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/accessor/setter/payload function boundaries, direct callers, field offsets, constructor clearing through `+0x2a4`, packet-updated provisional slots, and the direct class-parent gate through [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md). Final C++ remained blank under the older 95/95 wording; B009 later converted this page to non-reconstructable layout support with blank emitters.
- 2026-06-20 B004 source-routing support sync:
  - What existed before: the layout already rejected standalone `CharacterSummaryRecord` ownership.
  - Changed to: no score, owner, emitter, or C++ change.
  - Summary/evidence: incorporated local PE receiver evidence, provisional naming caveats for the summary-tail fields, and the adjacent no-xref signed `+0x27e` getter caveat.
