*** UID:0000I4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# CharacterSummaryRecord

## Status

- Confidence: strong that this is not a standalone original source file.
- Current recovered source: `source-3/simroot_v2/class_CharacterSummaryRecord.cpp`
- Correct owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Correct memory owner: [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- Exact accessor island: [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- Related layout: [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)

## File Decision

Do not create a separate original `CharacterSummaryRecord.cpp` file from this generated output. The emitted methods are accessors and setters for the newer [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md) object tail.

`CharacterSummaryRecord` appears to be a Wave2/Wave3 recovery abstraction over the receiver stored in `DAT_0069ae0c`. IDA confirms that address is the live `UserStatusPane` singleton `g_activeUserStatusPane`, and the surrounding constructor at `0x005b83b0` installs `UserStatusPane` vtables before initializing the exact fields used by these accessors.

## Emitted Methods

| Emitted method | Address | Correct owner |
| --- | --- | --- |
| `CopyNameLineA` | `0x005b85b0-0x005b85cb` | `UserStatusPane` title/name line copy helper. |
| `CopyNameLineB` | `0x005b85d0-0x005b85eb` | `UserStatusPane` secondary/status line copy helper. |
| `GetPercentStatA` | `0x005b85f0-0x005b85f6` | `UserStatusPane` byte-field getter. |
| `GetPercentStatB` | `0x005b8600-0x005b8606` | `UserStatusPane` byte-field getter. |
| `GetPercentStatC` | `0x005b8610-0x005b8616` | `UserStatusPane` byte-field getter. |
| `GetNationId` | `0x005b8620-0x005b8626` | `UserStatusPane` nation id getter. |
| `GetSpiritId` | `0x005b8630-0x005b8636` | `UserStatusPane` spirit/totem id getter. |
| `GetDisplayValueA` | `0x005b8640-0x005b8646` | `UserStatusPane` dword-field getter. |
| `GetDisplayValueB` | `0x005b8650-0x005b8656` | `UserStatusPane` dword-field getter. |
| omitted sibling | `0x005b8660-0x005b8666` | `UserStatusPane` third dword-field getter; missing from `class_CharacterSummaryRecord.cpp`. |
| `SetDisplayLineA` | `0x005b8670-0x005b8699` | `UserStatusPane` display-line setter plus invalidation callback. |
| `SetDisplayLineB` | `0x005b86a0-0x005b86c9` | `UserStatusPane` display-line setter plus invalidation callback. |

## Evidence Notes

- IDA decompilation of `0x005b83b0` shows the real `UserStatusPane` constructor storing `dword_69AE0C = this`, installing three `UserStatusPane` vtables, loading `9X11FONT.BIN`, and initializing fields at `+0x0fc`, `+0x17c`, `+0x1fc`, and `+0x27c` onward.
- IDA decompilation of the generated `CharacterSummaryRecord` methods reads/writes offsets inside that same `UserStatusPane` object.
- IDA callers include `ExchangeDialog`, `SelfLookPane`, `SelfLookPane2`, `AddItemDialog`, and status-pane update paths, but the receiver is still `g_activeUserStatusPane`, not a separate record allocation.
- Existing [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md) docs already place `0x005b85b0-0x005b86ca` in `UserStatusPane.cpp`.

## Source-Structure Decision

Fold this generated file into `ui/panels/UserStatusPane.cpp`. If a separate type name is useful during rewrite, model it as a private field-layout helper or comment block such as `UserStatusPaneSummaryFields`, not as an independently allocated class or source module.

## Cross-References

- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `86/90`.
  - Before: page documented that this generated file is not a standalone original source file but remained unevaluated.
  - After: score reflects strong negative placement evidence: the emitted accessors/setters are assigned to [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md), with exact memory/type/global anchors and generated-abstraction caveats.
  - Evidence: IDA decompilation ties the methods and `DAT_0069ae0c` receiver to `UserStatusPane` construction/vtables and `g_activeUserStatusPane`; the exact accessor island and layout are cross-linked.
