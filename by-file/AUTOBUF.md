*** UID:0000HM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AUTOBUF

## Status

- Confidence: strong for utility ownership and byte-buffer role; medium for exact original filename/casing.
- Proposed source artifact: `util/AUTOBUF.h`, `util/AutoBuf.h`, or an adjacent buffer utility header.
- Primary concrete instantiation: [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- Current generated source: `source-3/simroot_v2/class_AUTOBUF_unsigned_char.cpp`

## File Role

`AUTOBUF<T>` is a small owning buffer wrapper. The concrete `_AUTOBUF<unsigned char>` instantiation appears in map `.cmp` loading, startup-logo video loading, and self-look/profile packet parsing, where it owns raw byte payloads read from files or packets.

The generated `class_AUTOBUF_unsigned_char.cpp` file currently emits only the resize helper at `0x004e6ab0`. The constructor at `0x004f5640` is physically emitted near `LogoPlayerPane`, but IDA confirms it is `_AUTOBUF<unsigned char>` construction rather than a pane method. A 2026-05-26 IDA recheck reports the direct code caller as [UID:0000L3][MapPane](by-file/MapPane.md) at `0x00504d49`; `LogoPlayerPane` still uses an embedded AUTOBUF layout but initializes it inline in its constructor.

## Known Concrete Code

| Range | Role |
| --- | --- |
| `0x004e6ab0-0x004e6ad7` | `AUTOBUF<unsigned char>::Resize`; frees old storage, allocates a new byte buffer, stores pointer and byte count. |
| `0x004f5640-0x004f566a` | `_AUTOBUF<unsigned char>` constructor; calls `LObject` setup, installs vtable, clears pointer/count fields. Used by `MapPane::LoadMapFromFile` for a stack/local compressed-map payload buffer. |

## Source-Structure Decision

Use this as shared utility/header support. Do not migrate the constructor as `LogoPlayerPane` behavior, and do not treat `class_AUTOBUF_unsigned_char.cpp` as a feature-specific source file.

## Proposed Placement

- Projected reconstruction folder: `NexusTK/util/`.
- Likely source artifact: `util/AUTOBUF.h` or a nearby utility template header.
- Validator handling: this page uses the `by-file` root as the autogen owner bucket even though the original artifact was probably header/template support rather than a standalone `.cpp` implementation.

The `util/` placement is supported by [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md), [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md), and the proposed source-tree utility-container section. The concrete instantiation is used by map loading, startup media, and profile/look parsing, so feature-specific ownership would be misleading.

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) | Confirms the concrete resize helper frees old storage, allocates the requested byte count, updates pointer/count fields, and ends before nine bytes of alignment padding. |
| [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) | Confirms constructor helper behavior and MapPane caller evidence, excluding LogoPlayerPane-only ownership. |
| [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) | Confirms RTTI/vtable data for `_AUTOBUF<unsigned char>`, recreated through declarations rather than copied as source data. |
| [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) | Consolidates field layout, caller spread, and template/header uncertainty. |

## Cross-References

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- What existed before: the page documented shared buffer ownership and constructor/resize evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `64/78`.
- Summary and evidence: byte-buffer role and two concrete code ranges are well supported, but exact original filename/header placement remains medium confidence.
- 2026-06-02:
  - Before: projected reconstruction path was blank, leaving the file root in generated coverage error state.
  - After: scored as `72/86` and assigned `NexusTK/util/`.
  - Summary/evidence: proposed source-tree utility-container rationale, concrete constructor/resize/vtable child pages, and cross-feature caller evidence support utility ownership. C++ remains absent because the likely original artifact is template/header support and exact spelling/casing is not final-audit quality.
- 2026-06-03:
  - Before: the concrete helper rows used stale exclusive-end labels for both AUTOBUF child pages.
  - After: corrected `Resize` to `0x004e6ab0-0x004e6ad7` and constructor to `0x004f5640-0x004f566a` from live IDA function bounds.
  - Summary/evidence: IDA MCP reports `Resize` size `0x27`, constructor size `0x2a`, a nine-byte alignment gap after `Resize`, and 21 vtable references proving this is shared template support.
