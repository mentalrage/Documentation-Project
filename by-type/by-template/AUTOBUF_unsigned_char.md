*** UID:0001WN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HM | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AUTOBUF<unsigned char>

## Status

- Confidence: medium; local constructor behavior is clear, full template contract is not.
- Current entity kind: compiler-emitted template/support type
- Known helper addresses: `0x004e6ab0-0x004e6adf`, `0x004f5640-0x004f5669`
- Exact vtable data: [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- Likely source artifact: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- Exact helper memory doc: [UID:00019E][0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor.md)
- Current physical neighborhood: [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- Related class: [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)

## Declaration Hypothesis

`AUTOBUF<unsigned char>` is an `LObject`-derived or `LObject`-compatible auto-buffer wrapper used to own byte buffers loaded by file and packet helpers. Known uses include a stack/local compressed map payload in `MapPane::LoadMapFromFile`, an embedded segmented Bink payload buffer in `LogoPlayerPane`, and profile/look payload storage in `UserLookPane`.

Likely fields from the local constructor:

| Offset | Meaning |
| --- | --- |
| `+0x00` | vtable pointer for `_AUTOBUF<unsigned char>`; concrete vtable at `0x0061b868` with RTTI locator at `0x0061b864` |
| `+0x04` | buffer pointer, initialized to null |
| `+0x08` | count/capacity/state field, initialized to zero |

## Evidence Notes

- IDA decompilation of `0x004f5640` calls `LObject` construction, writes the `_AUTOBUF<unsigned char>` vtable, clears fields `+0x04` and `+0x08`, and returns `this`.
- IDA disassembly of `0x004e6ab0` frees the existing pointer at `+0x04`, allocates the requested byte count, stores the byte count at `+0x08`, and stores the new pointer at `+0x04`.
- IDA MCP callers on 2026-05-31 show `0x004e6ab0` called twice from `sub_59F610` at `0x0059ffc1` and `0x0059fffe`; the surrounding disassembly uses `UserLookPane`-sized offsets `+0xb88/+0xb90`, copies packet/profile bytes into the resized buffer, and then decodes or draws the look/profile payload.
- 2026-05-26 IDA caller checks for `0x004f5640` show the direct code caller at `0x00504d49` inside `MapPane::LoadMapFromFile`, immediately before `StdioFile::ReadAll`-style compressed block loading and map-data decompression.
- IDA MCP callers on 2026-05-31 reconfirm `0x004f5640` is called from `sub_504B90` at `0x00504d49`; disassembly shows it constructing a stack/local `_AUTOBUF<unsigned char>` object at `var_63C`, passing it to `sub_582410`, and later restoring the vtable/freeing its buffer during cleanup.
- IDA MCP `py_eval` on 2026-05-31 identifies the exact `_AUTOBUF<unsigned char>` vtable range at `0x0061b864-0x0061b874`: RTTI locator `??_R4?$_AUTOBUF@E@@6B@`, vtable `??_7?$_AUTOBUF@E@@6B@`, slots `0x004e62a0`, `0x004f4b10`, and `0x0041b6c0`, followed by `aZpf` string data at `0x0061b874`.
- The constructor helper is physically adjacent to `LogoPlayerPane` methods, but the visible `LogoPlayerPane` constructor initializes its embedded AUTOBUF at offset `+0x100` inline in current generated source and passes it to `StdioFile::ReadAll`.

## Ownership Notes

Do not migrate `0x004f5640` as a `LogoPlayerPane` member. It should become template support, an inline emitted constructor, or a type-support helper once Wave3 can represent template-owned routines cleanly.

## Reconstruction Notes

- Reconstructable: true as a concrete template-instantiation documentation record.
- Parent: [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md), now assigned to `NexusTK/util/`.
- C++: intentionally blank. The field layout and concrete helpers are known, but the full template declaration and original spelling/header split remain open.

## Cross-References

- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md)
- [UID:00019D][0x004f53b0-0x004f570c.LogoPlayerPane](by-memory/0x004f53b0-0x004f570c.LogoPlayerPane.md)
- [UID:000188][0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6adf.AUTOBUFUnsignedCharResize.md)
- [UID:00019E][0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f5669.AUTOBUFUnsignedCharConstructor.md)
- [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000FP][UserLookPane](by-class/UserLookPane.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)

## Changes

- 2026-05-31: Replaced unevaluated `0/0` scoring with IDA-backed `76/86` and marked the type reconstructable. Evidence: IDA MCP verified the constructor, resize helper, direct callers, and exact `_AUTOBUF<unsigned char>` vtable data; completion remains below high-final levels because exact original spelling/header placement and the full template contract are still open.
- 2026-06-02: Attached the template-instantiation documentation to [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) after the file page was assigned to `NexusTK/util/`. No C++ emitted because the final source declaration is not at the 95+ gate.
