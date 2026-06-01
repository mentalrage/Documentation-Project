*** UID:0001WF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UserStatusPane Summary Fields

## Status

- Confidence: strong for the listed offsets and `UserStatusPane` ownership; not final-source complete.
- Owner class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- Related generated alias: [UID:00001N][CharacterSummaryRecord](by-class/CharacterSummaryRecord.md)
- Evidence basis: IDA MCP decompilation of `0x005b83b0`, the covered accessors in [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md), [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md), and `0x005ba4a0`. Current `simroot_v2` is only a search lead for the stale `CharacterSummaryRecord` alias.

## Layout Slice

This is the field slice currently emitted as the pseudo-class `CharacterSummaryRecord`. Offsets are normalized to the `UserStatusPane` object base.

| Offset | Type | Evidence | Meaning |
| --- | --- | --- | --- |
| `+0x0fc` | `wchar_t[64]` | constructor, `0x005b85b0` | Primary character/name/title line copied out by `CopyNameLineA`. |
| `+0x17c` | `wchar_t[64]` | constructor, `0x005b8670` | Display line A set by callback-backed setter. |
| `+0x1fc` | `wchar_t[64]` | constructor, `0x005b85d0`, `0x005b86a0` | Secondary character/status line copied out and set by callback-backed setter. |
| `+0x27c` | `int8` | `0x005b8620` | Nation id. |
| `+0x27d` | `uint8` | constructor initializes word at `+0x27c` | Unknown adjacent byte, initialized with nation id as `0xff`. |
| `+0x27e` | `int8` | `0x005b8630` | Spirit/totem id. |
| `+0x27f` | `uint8` | [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) | Selected status icon id. |
| `+0x281` | `uint8` | `0x005b85f0` | Percent/stat byte A. |
| `+0x282` | `uint8` | `0x005b8600` | Percent/stat byte B. |
| `+0x283` | `uint8` | `0x005b8610` | Percent/stat byte C. |
| `+0x284` | `uint8` | constructor writes `52`; inventory/item-pane consumers validate against it | Inventory slot count / maximum item-slot selector byte for the active local user. |
| `+0x28c` | `uint32` | `0x005b8640` | Display value A. |
| `+0x294` | `uint32` | `0x005b8650` | Display value B. |
| `+0x298` | `uint32` | `0x005b8660` | Display value C; omitted by generated `CharacterSummaryRecord`. |

## Notes

- The constructor also clears several neighboring dwords from `+0x288` through `+0x2a4`. Only the fields with direct accessors or repeated IDA-confirmed external consumers are named here.
- `+0x284` is not just a default constructor byte: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), [UID:00001J][ChangeItemSlotInputPane](by-class/ChangeItemSlotInputPane.md), [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md), [UID:0000FG][UseInputPane](by-class/UseInputPane.md), [UID:000047][EatInputPane](by-class/EatInputPane.md), [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md), and [UID:0000G0][WearInputPane](by-class/WearInputPane.md) read it as the maximum valid item slot when mapping `a-z` to `1-26` and `A-Z` to `27-52`.
- `SetDisplayLineA` and `SetDisplayLineB` call the primary vtable slot at offset `+0x20` with `this+0x44`, matching a pane invalidation/refresh callback pattern.
- The generated name `CharacterSummaryRecord` is useful as search vocabulary, but the layout belongs to `UserStatusPane`.

## IDA Evidence

- 2026-05-31 IDA MCP decompilation of the constructor at `0x005b83b0` installs `UserStatusPane` vtables, stores `dword_69AE0C`, copies the first incoming string into object offset `+0x0fc`, clears the `+0x288` through `+0x2a4` region, writes `+0x284 = 52`, initializes bytes/words around `+0x27c`, and loads the same `9X11FONT.BIN` resource path used by the pane.
- 2026-05-31 IDA MCP decompilation of the accessor island confirms `+0x0fc`, `+0x1fc`, `+0x281`, `+0x282`, `+0x283`, `+0x27c`, `+0x27e`, `+0x28c`, `+0x294`, `+0x298`, and `+0x17c` as actual object offsets; [UID:0002LP][0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId](by-memory/0x005b86e0-0x005b86f8.UserStatusPaneSetStatusIconId.md) separately confirms `+0x27f`.
- 2026-05-31 IDA MCP decompilation of the status-payload updater at `0x005ba4a0` writes the same fields from packet-controlled flag groups: `+0x27e`, `+0x280`, `+0x281`, `+0x282`, `+0x283`, `+0x284`, `+0x288`, `+0x28c`, `+0x290`, `+0x294`, `+0x298`, and `+0x29c`.

## Remaining Caveats

- `+0x27d` remains unnamed beyond being the second byte of the constructor's word initialization at `+0x27c`.
- Several `+0x288` through `+0x2a4` values are packet-updated and invalidated by `0x005ba4a0`, but only the fields with direct accessors or clear consumer evidence are named here.
- No `RECONSTRUCTION_CPP CODE` is emitted yet. The item is reconstructable, but final source declarations should wait until the surrounding `UserStatusPane` field names, payload parser names, and source-file split are closer to the 95+ confidence/completion gate.

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

- 2026-05-31 completion/confidence and reconstructable update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, blank `RECONSTRUCTABLE`, and medium-confidence notes based partly on generated `simroot_v2` vocabulary.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP decompilation of the constructor, accessor island, and status-payload updater confirmed the listed offsets and `UserStatusPane` ownership. Scores remain below 95 because several neighboring payload fields still lack final source names and no final C++ declaration has been audited.
