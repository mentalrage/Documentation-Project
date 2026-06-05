*** UID:0000HM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AUTOBUF

## Status

- Confidence: high for utility ownership, byte-buffer role, helper boundaries, and cross-feature call evidence; medium-high for exact original filename/casing.
- Proposed source artifact: `util/AUTOBUF.h`, `util/AutoBuf.h`, or an adjacent buffer utility header.
- Primary concrete instantiation: [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md)

## File Role

`AUTOBUF<T>` is a small owning buffer wrapper. The concrete `_AUTOBUF<unsigned char>` instantiation appears in map `.cmp` loading, startup-logo video loading, login-screen image loading, image decode wrappers, and self-look/profile packet parsing, where it owns raw byte payloads read from files or packets.

The concrete support rows currently documented here are the resize helper at `0x004e6ab0`, the constructor helper at `0x004f5640`, and the exact `_AUTOBUF<unsigned char>` vtable-data slice at `0x0061b864-0x0061b874`. The constructor is physically near `LogoPlayerPane`, but IDA confirms it is `_AUTOBUF<unsigned char>` construction rather than a pane method. Its direct code caller is [UID:0000L3][MapPane](by-file/MapPane.md) at `0x00504d49`; `LogoPlayerPane` still uses an embedded AUTOBUF layout but initializes it inline in its constructor.

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
- Validator handling: this page uses the `by-file` root as the owner bucket even though the original artifact was probably header/template support rather than a standalone `.cpp` implementation.

The `util/` placement is supported by [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md), [UID:00000P][AUTOBUF_unsigned_char](by-class/AUTOBUF_unsigned_char.md), and the proposed source-tree utility-container section. The concrete instantiation is used by map loading, startup media, and profile/look parsing, so feature-specific ownership would be misleading.

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:000188][0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize](by-memory/0x004e6ab0-0x004e6ad7.AUTOBUFUnsignedCharResize.md) | Confirms the concrete resize helper frees old storage, allocates the requested byte count, updates pointer/count fields, and ends before nine bytes of alignment padding. |
| [UID:00019E][0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor](by-memory/0x004f5640-0x004f566a.AUTOBUFUnsignedCharConstructor.md) | Confirms constructor helper behavior and MapPane caller evidence, excluding LogoPlayerPane-only ownership. |
| [UID:0002MR][0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData](by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md) | Confirms RTTI/vtable data for `_AUTOBUF<unsigned char>`, recreated through declarations rather than copied as source data. |
| [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) | Consolidates field layout, caller spread, and template/header uncertainty. |

## Live IDA Evidence

- IDA MCP confirms `sub_4E6AB0` at `0x004e6ab0-0x004e6ad7`, size `0x27`. Decompilation frees `*(this+4)`, allocates the requested byte count through `0x005c7790`, stores the count at `+0x08`, stores the new pointer at `+0x04`, and returns it. The trailing `0x004e6ad7-0x004e6ae0` bytes are nine `0xcc` alignment bytes.
- IDA MCP confirms `sub_4F5640` at `0x004f5640-0x004f566a`, size `0x2a`. Decompilation calls `sub_4F4A80`, installs `_AUTOBUF<unsigned char>` vtable `0x0061b868`, clears fields `+0x04` and `+0x08`, and returns `this`.
- Direct code xrefs place `sub_4E6AB0` only at `sub_59F610` call sites `0x0059ffc1` and `0x0059fffe`, matching `UserLookPane` profile/look payload buffer resizing.
- The direct code xref to `sub_4F5640` is `0x00504d49` inside `sub_504B90` / `MapPane::LoadMapFromFile`, where a stack/local `_AUTOBUF<unsigned char>` object receives a `.cmp` file payload before decompression.
- Vtable data at `0x0061b864-0x0061b874` contains RTTI locator `0x00649194`, first slot `0x004e62a0`, inherited `0x004f4b10`, and `nullsub_18` at `0x0041b6c0`; `0x0061b874` begins adjacent string data and is not part of the vtable.
- IDA MCP reports 21 xrefs to `0x0061b868`: `0x004d0651`, `0x004d06fa`, `0x004e5c16`, `0x004e62a9`, `0x004f5419`, `0x004f5544`, `0x004f564f`, `0x004f56b7`, `0x004f57a6`, `0x004f5995`, `0x004f6884`, `0x004f68c5`, `0x00504da4`, `0x00504f7f`, `0x00505031`, `0x0050673b`, `0x005068a5`, `0x00527a37`, `0x0059f2c9`, `0x0059f5cf`, and `0x005a24c6`. This fan-out spans image decode, logo playback, main-menu media, map load/save, profile refresh, and user-look paths.

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
  - Before: projected reconstruction path was blank, leaving the file root without a source placement.
  - After: scored as `72/86` and assigned `NexusTK/util/`.
  - Summary/evidence: proposed source-tree utility-container rationale, concrete constructor/resize/vtable child pages, and cross-feature caller evidence support utility ownership. C++ remains absent because the likely original artifact is template/header support and exact spelling/casing is not final-audit quality.
- 2026-06-03:
  - Before: the concrete helper rows used stale exclusive-end labels for both AUTOBUF child pages.
  - After: corrected `Resize` to `0x004e6ab0-0x004e6ad7` and constructor to `0x004f5640-0x004f566a` from live IDA function bounds.
  - Summary/evidence: IDA MCP reports `Resize` size `0x27`, constructor size `0x2a`, a nine-byte alignment gap after `Resize`, and 21 vtable references proving this is shared template support.
- 2026-06-04 live IDA refresh:
  - Before: the page was scored `72/86` and still had stale source-output wording despite strong child evidence.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, with C++ still blank.
  - Summary/evidence: live IDA reconfirms exact helper ranges, resize and constructor bodies, the direct MapPane and UserLookPane call sites, exact vtable data through `0x0061b874`, and the 21-reference vtable fan-out across unrelated feature paths. The score remains below final because the exact original spelling/casing and header/template split are not proven to source-quality confidence.
