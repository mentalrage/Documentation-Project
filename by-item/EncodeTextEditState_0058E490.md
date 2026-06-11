*** UID:0000UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ON | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EncodeTextEditState 0x0058e490

## Status

- Confidence: strong for behavior, bounds, and TextEditPane owner; medium-high for final private member names.
- Likely owner: [UID:0000ON][TextEditPane](by-file/TextEditPane.md), not [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) or the wrapper [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md).
- Parent attachment: [UID:0000ON][TextEditPane](by-file/TextEditPane.md); the item and parent both clear the 80/80 attachment gate, and the only wrapper evidence is a forwarding stub.
- Main memory range: [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md)
- Evidence basis: IDA MCP function bounds, Hex-Rays output, raw TextEditControlPane forwarding disassembly, wrapper-core documentation, and `Encoder` writer xrefs checked on 2026-06-06.

## Role

This helper serializes several [UID:0000EO][TextEditPane](by-class/TextEditPane.md) internal list/table buffers into one heap-allocated byte buffer. It uses a stack [UID:00004F][Encoder](by-class/Encoder.md), writes table data and sizes into a temporary 32768-byte stack buffer, then allocates an exact output buffer and copies the encoded bytes into it.

The helper is a consumer of the codec utility. It should not be moved into `Encoder.cpp`: the object offsets and list access belong to the text-edit implementation.

The wrapper exposure is separate from helper ownership. The unpromoted [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md) stub at `0x00498c40-0x00498c4f` loads the embedded editor from wrapper offset `+0x10c`, restores `ebp`, and tail-jumps to this helper. That stub belongs to [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md); the target helper still reads [UID:0000EO][TextEditPane](by-class/TextEditPane.md) state at `+0x134` through `+0x140`.

## Behavior Notes

- Constructs an `Encoder` object at stack local `v17` and initializes it against a 32766-byte window inside a 32768-byte stack buffer.
- Reads table/list object pointers from `this[77]` through `this[80]` (`+0x134`, `+0x138`, `+0x13c`, `+0x140`) and obtains their raw data by virtual call at vtable offset `+0x10`.
- Derives payload sizes from each table object's word at `+0x0c`: first table raw byte count, second/third counts multiplied by `16`, and fourth count multiplied by `4`.
- Emits the first raw payload, a zero byte, the constant `0x6b6f6e67` (`"kong"` in little-endian), then three size-prefixed raw payloads.
- Calls the Encoder finalize/count helper, allocates an exact-size heap buffer through the shared memory allocator, copies the encoded stack bytes into that buffer, stores the final byte count through the caller-supplied output pointer, destroys the stack Encoder, and returns the heap buffer.

## Caller/Owner Evidence

IDA reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, with no ordinary function caller. `xrefs_to` shows one code xref at `0x00498c4a`, the tail jump inside a raw TextEditControlPane forwarding body. A 2026-06-06 bounded disassembly of `0x00498bf0-0x00498c72` shows the exact stub: `0x00498c40` `push ebp`, `0x00498c43` `mov ecx, [ecx+10Ch]`, `0x00498c49` `pop ebp`, and `0x00498c4a` `jmp sub_58E490`.

[UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md) classifies `0x00498c40-0x00498c4f` as one of the unpromoted aligned wrapper forwarding stubs inside the reusable TextEditControlPane core. That proves the wrapper can expose the export path, but it does not transfer ownership: the serialized offsets and table/list virtual calls belong to TextEditPane.

2026-05-30 IDA checks show the Encoder calls inside `0x0058e490`: constructor/init at `0x004a4e70`/`0x004a55c0`, raw-byte writes at `0x004a5480`, scalar writes at `0x004a4ec0`, `0x004a4ff0`, and `0x004a4f00`, finalize at `0x004a55e0`, and destructor at `0x004a4ea0`. Code xrefs to those writer/finalize helpers originate from this function, supporting TextEdit state serialization as the caller-owned behavior.

## Open Questions

- The wrapper stub at `0x00498c40-0x00498c4f` is not promoted to an IDA function and has no direct inbound xrefs today; keep final private wrapper method naming open.
- Variable names for the four TextEditPane table/list members are still descriptive rather than final; naming should wait for a broader sibling-method field pass.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001JM][0x0058dce0-0x005917c9.TextEditPaneCore](by-memory/0x0058dce0-0x005917c9.TextEditPaneCore.md)

## Changes

- 2026-06-06: Attached the item to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), raised completion/confidence to `84/88`, and replaced the broad raw-thunk owner caveat with TextEditControlPane forwarding evidence.
  - Before: parent attachment was blank because `0x00498c4a` was treated as an unresolved raw UI-control thunk.
  - After: the page records that `0x00498c40-0x00498c4f` is a TextEditControlPane wrapper stub that loads `+0x10c` and tail-jumps, while the target helper remains TextEditPane-owned because it serializes TextEditPane fields `+0x134` through `+0x140`.
  - Evidence: IDA MCP on 2026-06-06 reports `sub_58E490` at `0x0058e490-0x0058e691`, one code xref from `0x00498c4a`, no ordinary callers, and the same Encoder/memory-allocation callees; [UID:00011H][0x004988d0-0x00499020.TextEditControlPaneCore](by-memory/0x004988d0-0x00499020.TextEditControlPaneCore.md) documents the forwarding-stub family.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`; parent attachment remains blank.
  - Before: the text-edit serialization helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-authored TextEditPane serialization behavior, but not attached because the exact wrapper/caller owner remains unresolved around raw thunk `0x00498c4a`.
  - Evidence: live IDA MCP confirms `sub_58E490` at `0x0058e490`, size `0x201`, with Encoder writer/finalize/destructor callees matching the documented serialization behavior; the page's owner caveat remains active.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, older 2026-05-24/25 evidence, and an unresolved provenance caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`, current IDA function bounds, raw thunk evidence, Encoder call evidence, and explicit open questions for unresolved owner/member names.
- Summary/evidence: IDA MCP on 2026-05-30 reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, shows the only incoming xref as raw jump `0x00498c4a`, and shows the serialization call chain through Encoder write/finalize helpers inside this function.
