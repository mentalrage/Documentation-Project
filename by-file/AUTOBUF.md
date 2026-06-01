*** UID:0000HM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AUTOBUF

## Status

- Confidence: medium for exact original filename, strong for byte-buffer ownership role.
- Proposed source artifact: `util/AUTOBUF.h`, `util/AutoBuf.h`, or an adjacent buffer utility header.
- Primary concrete instantiation: [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- Current generated source: `source-3/simroot_v2/class_AUTOBUF_unsigned_char.cpp`

## File Role

`AUTOBUF<T>` is a small owning buffer wrapper. The concrete `_AUTOBUF<unsigned char>` instantiation appears in map `.cmp` loading, startup-logo video loading, and self-look/profile packet parsing, where it owns raw byte payloads read from files or packets.

The generated `class_AUTOBUF_unsigned_char.cpp` file currently emits only the resize helper at `0x004e6ab0`. The constructor at `0x004f5640` is physically emitted near `LogoPlayerPane`, but IDA confirms it is `_AUTOBUF<unsigned char>` construction rather than a pane method. A 2026-05-26 IDA recheck reports the direct code caller as [UID:0000L3][MapPane](by-file/MapPane.md) at `0x00504d49`; `LogoPlayerPane` still uses an embedded AUTOBUF layout but initializes it inline in its constructor.

## Known Concrete Code

| Range | Role |
| --- | --- |
| `0x004e6ab0-0x004e6adf` | `AUTOBUF<unsigned char>::Resize`; frees old storage, allocates a new byte buffer, stores pointer and byte count. |
| `0x004f5640-0x004f5669` | `_AUTOBUF<unsigned char>` constructor; calls `LObject` setup, installs vtable, clears pointer/count fields. Used by `MapPane::LoadMapFromFile` for a stack/local compressed-map payload buffer. |

## Source-Structure Decision

Use this as shared utility/header support. Do not migrate the constructor as `LogoPlayerPane` behavior, and do not treat `class_AUTOBUF_unsigned_char.cpp` as a feature-specific source file.

## Cross-References

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)
- [UID:000188][0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- What existed before: the page documented shared buffer ownership and constructor/resize evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `64/78`.
- Summary and evidence: byte-buffer role and two concrete code ranges are well supported, but exact original filename/header placement remains medium confidence.
