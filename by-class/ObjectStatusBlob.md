*** UID:00009S | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000M6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectStatusBlob

## Status

- Confidence: strong for shared parser role, exact parser boundaries, byte counts, caller families, and field-offset evidence; medium for final member names.
- Likely source file: [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- Reconstruction status: reconstructable class attached to [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md); C++ remains blank because source-quality member names are not at the final 95/95 bar.

## Class Purpose

`ObjectStatusBlob` is a shared 68-byte object appearance/status packet parser. It is used by map entity updates, user-look/profile flows, and object image preview/dialog code. It should be treated as reusable object packet state, not as a menu-command or one-dialog helper.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ParseTaggedStatus` | `0x004d1f30-0x004d1f99` | Reads a leading mode byte, delegates to full parsing for mode `0`, or parses compact tagged appearance ids for modes `1` and `2`. |
| `ParseFullStatus` | `0x004d1fa0-0x004d2637` | Parses the full appearance/status payload, normalizes title metadata, palette remaps, profile values, equipment, object type, and status/effect bytes. |
| `ParsePartialStatus` | `0x004d2640-0x004d2697` | Parses reduced direction/posture/appearance data and marks the blob as compact status. |

## Layout Notes

- `ObjectStatusBlobFields` is a 68-byte packet-state layout. Live decompilation writes through offset `+64`; the remaining tail remains layout padding or an unresolved trailing field.
- The full parser consumes 43 payload bytes, the partial parser consumes 5 bytes, and tagged compact modes consume 4 bytes after the leading mode.
- Compact modes set `+0` to mode `1` or `2`, write a 16-bit appearance id at `+4`, write one status/palette byte at `+6`, and return `4`.
- Partial parsing sets mode `1`, default state `+36 = 11`, default byte `+40 = 0x50`, then writes bytes at `+33`, `+34`, `+6` and a 16-bit id at `+4`.
- Full parsing sets mode `0`, default state `+36 = 11`, writes initial direction/posture/title fields at `+33`, `+34`, `+42`, and `+40`, then fills the appearance/equipment/status run from `+4` through `+64`.
- Title metadata lookup writes derived words at `+44`, `+46`, and `+48` when the title id is nonzero.
- Global dependencies include `g_displayMode`, `g_pAppearanceRemapTable`, `g_pMetaMan`, and `kStatusTitleMetaTableName`.

## Live IDA Evidence

- IDA MCP on 2026-06-05 confirms function sizes `0x69`, `0x697`, and `0x57` for `0x004d1f30`, `0x004d1fa0`, and `0x004d2640`; the internal gaps at `0x004d1f99-0x004d1fa0` and `0x004d2637-0x004d2640` are not function starts.
- `ParseTaggedStatus` decompilation switches on the leading byte, delegates mode `0` to `0x004d1fa0(input + 1) + 1`, stores mode `1` or `2` for compact cases, and returns `4` for compact payloads.
- `ParsePartialStatus` decompilation writes offsets `+0`, `+36`, `+40`, `+33`, `+34`, `+4`, and `+6`, then returns `5`.
- `ParseFullStatus` decompilation confirms the 43-byte read shape, title metadata table lookups through `dword_69B410`, display-mode gating through `byte_66DA97`, palette remapping through `dword_67A760`, equipment sentinel handling, and a final `43` return.
- Direct callers span map/object update handlers, user-look/profile paths, and object dialog/image preview code, with representative calls from `0x0050fb00`, `0x00513310`, `0x005693d0`, `0x00572120`, and `0x0059f610`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now records reconstructable ownership, parent file attachment, exact parser boundaries, byte counts, field-offset writes for compact/partial/full modes, global dependencies, caller families, and internal padding boundaries. Completion remains capped by unresolved final member names and the exact trailing bytes of the 68-byte layout. |
| Confidence `90` | Confidence is backed by current live IDA function enumeration, decompilation of all three parsers, caller/callee checks, global references, and padding verification. It remains below final reconstruction confidence because the layout member names are still descriptive rather than source-proven. |

## Cross-References

- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- [UID:000179][0x004d1f30-0x004d2697.ObjectStatusBlobParsers](by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)

## Changes

- 2026-06-05: Raised completion/confidence from `72/80` to `86/90`, marked reconstructable, and attached the class to [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md). Evidence: live IDA MCP revalidated the three parser functions, byte-count returns, compact/partial/full field-offset writes, broad map/object/profile caller families, metadata/remap globals, and internal padding boundaries. C++ remains blank because the 68-byte layout's source-level member names are not final.
- Before: completion/confidence metadata were `0/0` despite parser role, method ranges, layout-size notes, and subsystem references.
- Changed to: `COMPLETION:72` and `CONFIDENCE:80`.
- Evidence: the page documents the three parser modes, consumed byte counts, 68-byte field blob, global dependencies, and shared use across map/look/object-image code; remaining gaps are exact field-by-field naming and raw parser data-flow detail.
