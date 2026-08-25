*** UID:0000UM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0001JN | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000EO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Canonical source for this serialization item is owned by [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EncodeTextEditState 0x0058e490

## Status

- Confidence: very strong for behavior, exact bounds and bytes, TextEditPane ownership, the raw wrapper route, all four List fields and record types, Encoder staging, stream layout, allocation/copy ownership, and the public output-size contract.
- Canonical source body: [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md); this by-item page is its non-emitting canonical prose mirror.
- Class owner/emitter and source route: [UID:0000EO][TextEditPane](by-class/TextEditPane.md) is the accepted class owner/emitter, while [UID:0000ON][TextEditPane](by-file/TextEditPane.md) is only the translation-unit source route. Neither [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) nor wrapper file [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md) owns the lower body.
- Main memory range: [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md)
- Evidence basis: exact target bytes and SHA256, bounded IDA MCP function/disassembly/xref evidence, the raw TextEditControlPane forwarding body, the inverse decoder, current TextEditPane constructor/destructor/copy/class declarations, and exact Encoder/List/MemoryMan contracts.
- Current disposition: this by-item page is the non-emitting prose mirror for source-ready [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md). The complete managed body exists only on that canonical by-memory page; this mirror intentionally retains only the canonical-source comment.

## Role

This helper serializes several [UID:0000EO][TextEditPane](by-class/TextEditPane.md) internal list/table buffers into one heap-allocated byte buffer. It uses a stack [UID:00004F][Encoder](by-class/Encoder.md), writes table data and sizes into a temporary 32768-byte stack buffer, then allocates an exact output buffer and copies the encoded bytes into it.

This is the sole live authored BinaryCodec-family route. It constructs one `0x14` Encoder stack object, initializes one `0x8000` stack buffer with `0x7ffe` usable capacity, writes text bytes, one zero byte, marker `0x6b6f6e67`, and three size-prefixed table payloads, then finalizes and heap-copies exactly the reported byte count through `MemoryMan::MemmoveWrapper`. The one-buffer flow is TextEdit state serialization, not network-packet ownership.

The helper is a consumer of the codec utility. It should not be moved into `Encoder.cpp`: the object offsets and list access belong to the text-edit implementation.

The wrapper exposure is separate from helper ownership. The unpromoted [UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md) stub at `0x00498c40-0x00498c4f` loads the embedded editor from wrapper offset `+0x10c`, restores `ebp`, and tail-jumps to this helper. That stub belongs to [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md); the target helper still reads [UID:0000EO][TextEditPane](by-class/TextEditPane.md) state at `+0x134` through `+0x140`.

## Behavior Notes

- Constructs an `Encoder` object at stack local `v17` and initializes it against a 32766-byte window inside a 32768-byte stack buffer.
- Reads the exact List pointers `m_textStorage` at `+0x134`, `m_lineTable` at `+0x138`, `m_formatTable` at `+0x13c`, and `m_formatRuns` at `+0x140`, and obtains each base element through `GetElementAt(0)`.
- The current constructor, class declaration, destructor/private cleanup helper, record declarations, and inverse decoder close these field roles and element widths: `wchar_t`/2, `TextEditLineRecord`/16, `TextEditFormatRecord`/16, and `TextEditFormatRun`/4. Historical `m_styleRuns +0x13c` and `m_formatRecords +0x140` spellings are superseded.
- Reads only the low 16 bits of each List count. The 16/16/4 multiplications occur in 16-bit arithmetic and can wrap; each stored `short` is then sign-extended before `WriteBytes`, so a wrapped negative value becomes a large unsigned byte count at the accepted API boundary.
- Emits the first raw payload, a zero byte, then writes integer marker value `0x6b6f6e67` through `Encoder::WriteInt`; the emitted byte order is governed by the current Encoder state and has been observed as `"kong"` under the constructor-default big-endian scalar write. It then calls [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) at `0x0058e59a`, `0x0058e5c9`, and `0x0058e5f8` for the three later length prefixes: `this+0x138` count times `16`, `this+0x13c` count times `16`, and `this+0x140` count times `4`. These prefixes are high-byte-first under the default Encoder byte-order flag.
- Calls `Encoder::Finalize(unsigned int *outBytesWritten)` with the address of dword local `[ebp-0x8018]`, allocates an exact-size heap buffer through the shared memory allocator using that full dword count, copies the encoded stack bytes into that buffer, stores the low 16 bits of the final byte count through the caller-supplied output pointer, destroys the stack Encoder, and returns the heap buffer. The later 16-bit public size store is caller-side behavior and does not make the Encoder finalize output pointer 16-bit.
- Calls `GetMemoryMan()` twice exactly as observed: the first result is retained for `MemmoveWrapper`, while the second performs `AllocateBufferMemory`. The returned byte pointer is caller-owned through the shared allocator contract.
- Preserves legacy negative behavior: there is no null guard for `outSize`, any List pointer, or `GetElementAt(0)`; no capacity/overflow check; no normalization of the one-byte text payload count; no allocation failure branch; no check of the boolean Finalize result; and no rejection of signed-short lengths before `WriteBytes`.
- [UID:0000OQ][TextPad](by-file/TextPad.md) stores/loads this encoded stream as the optional rich payload in its local `Open`/`Save` command format through `TextEditScrap`. That makes TextPad a consumer; canonical body UID0001JN remains owned/emitted by class UID0000EO and routed through file UID0000ON.

## Caller/Owner Evidence

IDA reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, with no ordinary function caller. `xrefs_to` shows one code xref at `0x00498c4a`, the tail jump inside a raw TextEditControlPane forwarding body. A 2026-06-06 bounded disassembly of `0x00498bf0-0x00498c72` shows the exact stub: `0x00498c40` `push ebp`, `0x00498c43` `mov ecx, [ecx+10Ch]`, `0x00498c49` `pop ebp`, and `0x00498c4a` `jmp sub_58E490`.

[UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md) classifies `0x00498c40-0x00498c4f` as one of the unpromoted aligned wrapper forwarding stubs inside the reusable TextEditControlPane core. That proves the wrapper can expose the export path, but it does not transfer ownership: the serialized offsets and table/list virtual calls belong to TextEditPane.

2026-05-30 IDA checks show the Encoder calls inside `0x0058e490`: constructor/init at `0x004a4e70`/`0x004a55c0`, raw-byte writes at `0x004a5480`, scalar writes at `0x004a4ec0`, `0x004a4ff0`, and `0x004a4f00`, finalize at `0x004a55e0`, and destructor at `0x004a4ea0`. Code xrefs to those writer/finalize helpers originate from this function, supporting TextEdit state serialization as the caller-owned behavior.

2026-06-16 A002 live IDA MCP refresh on session `b001_maildialogs_0000ZO_20260616` again reports `sub_58E490` as `0x0058e490-0x0058e691`, size `0x201`, with exactly one xref at raw jump site `0x00498c4a` and no ordinary modeled callers. `lookup_funcs 0x00498c40` still reports no function, while `make_signature_for_range 0x00498c40-0x00498c4f` returns the unique bytes `55 8B EC 8B 89 0C 01 00 00 5D E9 41 58 0F 00`, matching `push ebp; mov ebp, esp; mov ecx, [ecx+0x10c]; pop ebp; jmp 0x0058e490`.

The current decompilation and accepted constructor/class/record/decoder union confirm the serialization details used for source placement: `m_textStorage`, `m_lineTable`, `m_formatTable`, and `m_formatRuns` are read as the four TextEditPane-owned List pointers; the helper initializes a stack `Encoder` over a 32766-byte window inside a 32768-byte stack buffer; it writes raw table bytes, delimiter byte `0`, marker value `0x6b6f6e67` through `Encoder::WriteInt`, three length-prefixed secondary payloads, finalizes, allocates an exact heap buffer, copies the stack output, stores the byte count through the output pointer, and destroys the stack Encoder. Older `m_styleRuns`/`m_formatRecords` names remain only in explicitly dated historical entries below and are not current field identities.

B008's [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) reanalysis refines the count width: the finalize call at `0x0058e624` writes a 32-bit cursor count into `[ebp-0x8018]`, the helper uses that dword for allocation and copy, and only afterward stores `word ptr [outSize] = word ptr [ebp-0x8018]`. This supports `bool Encoder::Finalize(unsigned int *outBytesWritten)` while preserving this item's 16-bit external size output.

Historically, the 2026-06-16 A002 refresh left field spellings and source shape open even though it reconfirmed `sub_58E490` size `0x201`, sole raw jump `0x00498c4a`, unique wrapper bytes, and the Encoder/allocation callee set. The current constructor/class/record/decoder union resolves those former documentation blockers without changing that binary evidence.

## Open Questions

- No source-quality blocker remains for the canonical UID0001JN body. The retained TextEditControlPane wrapper has no inbound xref and its private lexical wrapper name remains unavailable, but its already-managed forwarding body and lower API are exact and do not block this target.
- Original local-variable spellings and method visibility are not recovered. The destination uses descriptive locals and the existing class declaration while preserving exact ABI, layout, stream, allocation, and negative behavior.

## Cross-References

- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md)
- [UID:00004F][Encoder](by-class/Encoder.md)
- [UID:0000ON][TextEditPane](by-file/TextEditPane.md)
- [UID:0001JM][0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane](by-memory/0x0058dce0-0x00591300.TextEditPaneCoreBeforeTextBoxPane.md)

## Changes

- 2026-07-19 B001 UID0001JN accepted implementation callback:
  - Raised this canonical mirror from `87/90` to `91/93`, changed its emitter route from file UID0000ON to class UID0000EO, and retained canonical owner UID0001JN plus the comment-only managed block so no duplicate body emits.
  - Synchronized the exact four fields and record widths, low-word count reads, 16-bit scaling wrap, signed-short widening, 32768/32766 Encoder staging, text/zero/`kong`/16-16-4 stream, full-width allocation/copy, low-16 public size, allocator ownership, inverse-decoder corroboration, and all no-guard negatives.
  - Historicalized the former blank-body, unresolved-field, and member-versus-free blockers; the complete source body now resides once on UID0001JN.

- 2026-06-30 B004 corrected TextEditPane implementation callback:
  - Before: `86/90`, canonical owner [UID:0000ON][TextEditPane](by-file/TextEditPane.md), and formal C++ blank.
  - Changed to: `87/90`, canonical owner [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md), with a covered canonical-source comment. This does not claim the serializer body is first-draft ready.
  - Evidence: the revised B004 [UID:0000ON][TextEditPane](by-file/TextEditPane.md) report treats UID0001JN as the exact canonical memory page for the serializer while preserving the remaining blockers: exact Encoder/local-buffer spellings, private table/list names at `+0x138/+0x13c/+0x140`, and raw TextEditControlPane wrapper naming.

- 2026-06-22 Rule 26 incorporation of B013 [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) report:
  - Score unchanged at `86/90`.
  - Confirmed the marker call at `0x0058e58b`: the helper pushes `0x6b6f6e67`, then `Encoder::WriteInt` emits `6b 6f 6e 67` (`"kong"`) because the stack Encoder preserves its constructor-default big-endian scalar flag. This item remains a TextEditPane serializer consumer of the Encoder utility, not an Encoder source owner.

- 2026-06-21 Rule 26 incorporation of B012 [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) report:
  - Score unchanged at `86/90`.
  - Added exact `Encoder::WriteShort` callsite semantics for the three later length prefixes: `count * 16`, `count * 16`, and `count * 4`, written high-byte-first because the stack Encoder keeps its constructor-default byte-order flag.

- 2026-06-16 A002 item/resource completion refresh:
  - Before: `85/89`.
  - Changed to: `86/90`; owner/emitter remain [UID:0000ON][TextEditPane](by-file/TextEditPane.md); final C++ remains blank.
  - Evidence: active IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed exact range, single raw wrapper jump, no function or xrefs at `0x00498c40`, the unique wrapper bytes, `Encoder`/allocation callee set, no ordinary callers, and the current decompiler prototype. Sibling TextEditPane constructor/destructor/copy docs prove `+0x134` is text storage; the remaining `+0x138`/`+0x13c`/`+0x140` source names and the private wrapper method name remain real blockers, so no reconstruction C++ was entered.

- 2026-06-20 B005 Rule 26 source-quality incorporation:
  - Score unchanged at `86/90`.
  - Synced the item page with the class/source field map: `m_textStorage`, inferred `m_lineTable`, inferred `m_styleRuns`, and inferred `m_formatRecords`; clarified that `0x6b6f6e67` is written by `Encoder::WriteInt` with Encoder-controlled byte order.
  - Evidence: B005 report matched this item to [UID:0001JN][0x0058e490-0x0058e691.TextEditPaneSerialization](by-memory/0x0058e490-0x0058e691.TextEditPaneSerialization.md) and rejected TextEditControlPane, Encoder, and BinaryCodec ownership.
- 2026-06-21 Rule 26 incorporation of B008 [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) report:
  - Score unchanged at `86/90`.
  - Added the dword finalize-count path and the later 16-bit out-size truncation so this item no longer implies a 16-bit Encoder finalize parameter.

- 2026-06-21 B008 TextPad source-quality sync:
  - Score unchanged at `86/90`.
  - Added TextPad `Open`/`Save` as consumers of the encoded rich-state payload while keeping this item owned by TextEditPane rather than TextPad.

- 2026-06-16 A002 file/item completion refresh:
  - Before: `84/88`.
  - Changed to: `85/89`; owner/emitter remain [UID:0000ON][TextEditPane](by-file/TextEditPane.md); final C++ remains blank.
  - Evidence: live IDA reconfirmed the exact range, single raw wrapper jump, no modeled function at `0x00498c40`, unique wrapper bytes loading `+0x10c` before jumping to `0x0058e490`, Encoder callee set, table/list offset data flow, `"kong"` marker, output allocation/copy path, and the continuing field-name/wrapper-method blockers.

- 2026-06-06: Attached the item to [UID:0000ON][TextEditPane](by-file/TextEditPane.md), raised completion/confidence to `84/88`, and replaced the broad raw-thunk owner caveat with TextEditControlPane forwarding evidence.
  - Before: parent attachment was blank because `0x00498c4a` was treated as an unresolved raw UI-control thunk.
  - After: the page records that `0x00498c40-0x00498c4f` is a TextEditControlPane wrapper stub that loads `+0x10c` and tail-jumps, while the target helper remains TextEditPane-owned because it serializes TextEditPane fields `+0x134` through `+0x140`.
  - Evidence: IDA MCP on 2026-06-06 reports `sub_58E490` at `0x0058e490-0x0058e691`, one code xref from `0x00498c4a`, no ordinary callers, and the same Encoder/memory-allocation callees; [UID:00011H][0x004988d0-0x00498dd0.TextEditControlPaneCore](by-memory/0x004988d0-0x00498dd0.TextEditControlPaneCore.md) documents the forwarding-stub family.

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`; parent attachment remains blank.
  - Before: the text-edit serialization helper was documented but unclassified in autogen coverage.
  - After: it is marked as source-authored TextEditPane serialization behavior, but not attached because the exact wrapper/caller owner remains unresolved around raw thunk `0x00498c4a`.
  - Evidence: live IDA MCP confirms `sub_58E490` at `0x0058e490`, size `0x201`, with Encoder writer/finalize/destructor callees matching the documented serialization behavior; the page's owner caveat remains active.

- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, older 2026-05-24/25 evidence, and an unresolved provenance caveat.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`, current IDA function bounds, raw thunk evidence, Encoder call evidence, and explicit open questions for unresolved owner/member names.
- Summary/evidence: IDA MCP on 2026-05-30 reports `sub_58E490` as `0x0058e490-0x0058e691` size `513`, shows the only incoming xref as raw jump `0x00498c4a`, and shows the serialization call chain through Encoder write/finalize helpers inside this function.
