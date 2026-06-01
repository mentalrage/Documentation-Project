*** UID:0000UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EncodeTextEditState 0x0058e490

## Status

- Confidence: medium for exact caller/owner, strong for behavior and function bounds.
- Likely owner: [UID:0000ON][TextEditPane](by-file/TextEditPane.md), not [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- Main memory range: [UID:0001JN][0x0058e490-0x0058e690.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e690.TextEditPaneSerialization.md)
- Evidence basis: IDA MCP function bounds, Hex-Rays output, raw thunk xref, and `Encoder` writer xrefs checked on 2026-05-30.

## Role

This helper serializes several [UID:0000EO][TextEditPane](by-class/TextEditPane.md) internal list/table buffers into one heap-allocated byte buffer. It uses a stack [UID:00004F][Encoder](by-class/Encoder.md), writes table data and sizes into a temporary 32768-byte stack buffer, then allocates an exact output buffer and copies the encoded bytes into it.

The helper is a consumer of the codec utility. It should not be moved into `Encoder.cpp`: the object offsets and list access belong to the text-edit implementation.

## Behavior Notes

- Constructs an `Encoder` object at stack local `v17` and initializes it against a 32766-byte window inside a 32768-byte stack buffer.
- Reads table/list object pointers from `this[77]` through `this[80]` (`+0x134`, `+0x138`, `+0x13c`, `+0x140`) and obtains their raw data by virtual call at vtable offset `+0x10`.
- Derives payload sizes from each table object's word at `+0x0c`: first table raw byte count, second/third counts multiplied by `16`, and fourth count multiplied by `4`.
- Emits the first raw payload, a zero byte, the constant `0x6b6f6e67` (`"kong"` in little-endian), then three size-prefixed raw payloads.
- Calls the Encoder finalize/count helper, allocates an exact-size heap buffer through the shared memory allocator, copies the encoded stack bytes into that buffer, stores the final byte count through the caller-supplied output pointer, destroys the stack Encoder, and returns the heap buffer.

## Caller/Owner Evidence

IDA reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, but no formal function caller. `xrefs_to` shows a code xref at raw thunk address `0x00498c4a`, where the surrounding disassembly loads `[ecx+0x10c]` and jumps to `sub_58E490`. The thunk neighborhood sits in the UI control/text-edit wrapper area, so the safest current owner is [UID:0000ON][TextEditPane](by-file/TextEditPane.md) or a text-edit control adapter rather than `SelfSaveOKPane`.

2026-05-30 IDA checks show the Encoder calls inside `0x0058e490`: constructor/init at `0x004a4e70`/`0x004a55c0`, raw-byte writes at `0x004a5480`, scalar writes at `0x004a4ec0`, `0x004a4ff0`, and `0x004a4f00`, finalize at `0x004a55e0`, and destructor at `0x004a4ea0`. Code xrefs to those writer/finalize helpers originate from this function, supporting TextEdit state serialization as the caller-owned behavior.

## Open Questions

- The raw thunk at `0x00498c40-0x00498c4a` is not currently an IDA function, so the exact wrapper class or adapter method that forwards `this+0x10c` remains medium confidence.
- Variable names for the four table/list members are still descriptive rather than final; naming should wait for stronger evidence from sibling TextEditPane methods.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001JM][0x0058dce0-0x005917c8.TextEditPaneCore](by-memory/0x0058dce0-0x005917c8.TextEditPaneCore.md)

## Changes

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, older 2026-05-24/25 evidence, and a generated-data caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`, current IDA function bounds, raw thunk evidence, Encoder call evidence, and explicit open questions for unresolved owner/member names.
- Summary/evidence: IDA MCP on 2026-05-30 reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, shows the only incoming xref as raw jump `0x00498c4a`, and shows the serialization call chain through Encoder write/finalize helpers inside this function.
