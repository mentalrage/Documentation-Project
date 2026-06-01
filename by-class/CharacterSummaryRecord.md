*** UID:00001N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CharacterSummaryRecord

## Status

- Confidence: strong that this is a generated pseudo-class, not an original class boundary.
- Generated source: `source-3/simroot_v2/class_CharacterSummaryRecord.cpp`
- Correct owner class: [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- Correct owner file: [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- Exact accessor island: [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)

## Classification

`CharacterSummaryRecord` is a recovery label for a cluster of `UserStatusPane` accessors over `g_activeUserStatusPane` at `0x0069ae0c`. It should not become a separate migrated C++ class unless later evidence finds an independently allocated object.

The methods in this generated class read and write the same `UserStatusPane` offsets initialized by `UserStatusPane::UserStatusPane` at `0x005b83b0`.

## Correct Ownership

| Address | Generated name | Correct interpretation |
| --- | --- | --- |
| `0x005b85b0` | `CopyNameLineA` | `UserStatusPane` copy helper for wide string at `+0x0fc`. |
| `0x005b85d0` | `CopyNameLineB` | `UserStatusPane` copy helper for wide string at `+0x1fc`. |
| `0x005b85f0` | `GetPercentStatA` | `UserStatusPane` byte getter at `+0x281`. |
| `0x005b8600` | `GetPercentStatB` | `UserStatusPane` byte getter at `+0x282`. |
| `0x005b8610` | `GetPercentStatC` | `UserStatusPane` byte getter at `+0x283`. |
| `0x005b8620` | `GetNationId` | `UserStatusPane` nation id getter at `+0x27c`. |
| `0x005b8630` | `GetSpiritId` | `UserStatusPane` spirit/totem getter at `+0x27e`. |
| `0x005b8640` | `GetDisplayValueA` | `UserStatusPane` dword getter at `+0x28c`. |
| `0x005b8650` | `GetDisplayValueB` | `UserStatusPane` dword getter at `+0x294`. |
| `0x005b8660` | omitted | `UserStatusPane` third dword getter at `+0x298`. |
| `0x005b8670` | `SetDisplayLineA` | `UserStatusPane` setter for wide string at `+0x17c`, then invalidates via vtable slot `+0x20`. |
| `0x005b86a0` | `SetDisplayLineB` | `UserStatusPane` setter for wide string at `+0x1fc`, then invalidates via vtable slot `+0x20`. |

## Evidence Notes

- IDA decompilation names the surrounding constructor and cleanup as `UserStatusPane` vtable code.
- Existing UserStatusPane memory docs already cover this method cluster in the `0x005b85b0-0x005b86ca` subrange.
- The generated pseudo-class still omits sibling getter `0x005b8660`, so it is not even a complete accessors view of the status-pane tail.

## Cross-References

- [UID:0000I4][CharacterSummaryRecord](by-file/CharacterSummaryRecord.md)
- [UID:0000FS][UserStatusPane](by-class/UserStatusPane.md)
- [UID:0000P2][UserStatusPane](by-file/UserStatusPane.md)
- [UID:0001NM][0x005b83b0-0x005baafe.UserStatusPane](by-memory/0x005b83b0-0x005baafe.UserStatusPane.md)
- [UID:0001NN][0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors](by-memory/0x005b85b0-0x005b86ca.UserStatusPaneSummaryAccessors.md)
- [UID:0001WF][UserStatusPaneSummaryFields](by-type/by-struct/UserStatusPaneSummaryFields.md)

## Changes

- What existed before: the page clearly classified this as a generated pseudo-class over `UserStatusPane` accessors, but metadata still read `0/0`.
- What it was changed to: scores were set to `82/90`.
- Summary and evidence: the correct owner, accessor island, offset meanings, and missing sibling getter are documented; final field names belong in the UserStatusPane/layout pages rather than as a separate original class.
