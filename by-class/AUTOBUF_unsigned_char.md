*** UID:00000P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AUTOBUF_unsigned_char

## Status

- Confidence: strong for concrete behavior, medium for final template declaration name.
- Source-level name: `_AUTOBUF<unsigned char>` or `AUTOBUF<unsigned char>`
- Likely source artifact: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- Current generated file: `source-3/simroot_v2/class_AUTOBUF_unsigned_char.cpp`

## Responsibility

`AUTOBUF<unsigned char>` is a small owning byte-buffer wrapper used by several unrelated client features. The concrete instantiation owns raw byte payloads for compressed map loading/saving, startup-logo media, login-screen image loading, image decode helpers, profile sidecar refresh, and user/profile look packet parsing. It should be treated as shared utility or template support, not as a feature-specific class owned by any one caller.

## Binary Shape

| Offset | Meaning |
| --- | --- |
| `+0x00` | `_AUTOBUF<unsigned char>` vtable / `LObject`-compatible object header |
| `+0x04` | owned byte buffer pointer |
| `+0x08` | byte count/capacity field |

Exact vtable data is now documented at [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x004e6ab0-0x004e6ad7` | `Resize(uint32_t byteCount)` | Frees existing byte storage, allocates `byteCount` bytes, stores new pointer at `+0x04`, and stores byte count at `+0x08`. |
| `0x004f5640-0x004f566a` | constructor | Calls `LObject` construction, installs the `_AUTOBUF<unsigned char>` vtable, clears pointer/count fields. |

## Ownership Notes

`0x004f5640` is physically near `LogoPlayerPane`, but it is type support. A 2026-05-26 IDA caller check reports the standalone constructor's direct code caller as `MapPane::LoadMapFromFile` at `0x00504d49`, where a local AUTOBUF receives a compressed `.cmp` map payload before decompression. `LogoPlayerPane` still embeds the same layout and initializes it inline for segmented Bink data, so physical neighborhood alone should not drive ownership.

IDA callers for `0x004e6ab0` come from `UserLookPane` profile/look packet parsing. A 2026-06-03 IDA vtable-reference pass also finds 21 writes/references to `??_7?$_AUTOBUF@E@@6B@` across image decode wrappers, logo playback, main-menu `LEVEL.BMP` loading, map load/save helpers, profile sidecar refresh, and `UserLookPane` construction/destruction. That broader vtable fan-out confirms the concrete instantiation is shared utility/template support rather than belonging to one feature file.

## Instantiation Evidence

| Evidence site | Interpretation |
| --- | --- |
| `0x004e6ab0-0x004e6ad7` | Concrete resize helper for `_AUTOBUF<unsigned char>`; frees current storage, allocates the requested byte count, updates pointer/count fields, and is called from `UserLookPane` profile/look parsing at `0x0059ffc1` and `0x0059fffe`. |
| `0x004f5640-0x004f566a` | Concrete constructor helper; initializes the `LObject` shell, installs vtable `0x0061b868`, clears fields, and is directly called by `MapPane::LoadMapFromFile` at `0x00504d49` for a local compressed-map payload buffer. |
| `0x0061b864-0x0061b874` | Exact RTTI/vtable slice for `??_R4?$_AUTOBUF@E@@6B@` / `??_7?$_AUTOBUF@E@@6B@`; the next bytes are string data, so the vtable boundary is tight. |
| 21 vtable references to `0x0061b868` | Cross-feature usage spans image decode wrappers, logo playback, main-menu media, map load/save, profile refresh, and user-look paths, which supports utility/template ownership instead of a pane-specific source file. |

The class page therefore tracks the concrete emitted instantiation, while [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) remains the source-owner bucket for likely header/template support.

## Reconstruction Notes

- Reconstructable: true as the concrete emitted `_AUTOBUF<unsigned char>` support type.
- Parent: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), now assigned to `NexusTK/util/`.
- C++: intentionally blank. The field layout and two concrete helpers are documented, but the final template spelling, header/source split, and full template contract are not source-quality yet.

## Evidence

- IDA MCP `py_eval` on 2026-06-03 confirms exact function bounds `0x004e6ab0-0x004e6ad7` for resize and `0x004f5640-0x004f566a` for the constructor.
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) documents the resize helper freeing the old buffer, allocating the requested byte count, updating fields `+0x04`/`+0x08`, and moving the trailing `0x004e6ad7-0x004e6ae0` padding into [UID:0000VN][-ignored](by-memory/-ignored.md).
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) documents the constructor calling `LObject` setup, installing the vtable, and clearing fields `+0x04`/`+0x08`.
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) documents the exact RTTI locator and three-slot concrete vtable data. IDA MCP callers/disassembly on 2026-05-31 also confirms the constructor caller at `0x00504d49` and resize callers at `0x0059ffc1`/`0x0059fffe`.
- The companion [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) page records the same field layout and caller evidence from map, logo-media, and profile/look code paths.

## Open Questions

- Confirm the exact original spelling and header location: `_AUTOBUF`, `AUTOBUF`, `AutoBuf`, or another project-specific casing.
- Confirm whether the concrete instantiation existed as explicit template code in source or only as compiler-emitted helpers from inline template use.

## Cross-References

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md)
- [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md)
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)

## Changes

- 2026-05-31: Raised scoring from `60/75` to `68/82` and marked the class reconstructable after adding the exact vtable-data page. Evidence: IDA MCP verified the concrete vtable range, constructor helper, resize helper, and MapPane/UserLookPane caller evidence. Scores remain below final-audit levels because the exact original template spelling/header location and full template contract are not yet settled.
- 2026-06-02: Attached the concrete class to [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) after the file page was assigned to `NexusTK/util/`. C++ remains blank pending final template/header audit.
- 2026-06-03: Raised `COMPLETION` from `68` to `74` and `CONFIDENCE` from `82` to `86` after live IDA MCP corrected both helper exclusive ranges, confirmed the `0x004e6ad7-0x004e6ae0` alignment gap, and expanded vtable-write evidence to 21 cross-feature references. C++ remains blank because exact original template spelling and header/source split are still unresolved.
- 2026-06-06: Raised grading from `74/86` to `78/88`.
  - Before: the class page listed the helper methods and ownership rationale, but the cross-feature instantiation evidence was spread across the file/type/memory pages.
  - After: added an instantiation evidence table tying the resize helper, constructor helper, exact vtable slice, 21-reference vtable fan-out, and `AUTOBUF` file owner together.
  - Evidence: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) is now `84/88`, the vtable data page is `84/88`, and the helper pages record exact IDA-backed ranges and callers. Final C++ remains blank because original template spelling/header placement and the full template contract are still below the 95/95 gate.
