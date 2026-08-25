*** UID:0004X5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "MD5.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MD5_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | (~z)))
#define MD5_ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

#define MD5_FF(a, b, c, d, x, s, ac) \
    { (a) += MD5_F((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_GG(a, b, c, d, x, s, ac) \
    { (a) += MD5_G((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_HH(a, b, c, d, x, s, ac) \
    { (a) += MD5_H((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }
#define MD5_II(a, b, c, d, x, s, ac) \
    { (a) += MD5_I((b), (c), (d)) + (x) + (unsigned int)(ac); \
      (a) = MD5_ROTATE_LEFT((a), (s)); \
      (a) += (b); }

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_MD5_H
#define NEXUSTK_UTIL_MD5_H

#include <stdio.h>

class MD5
{
public:
    MD5()
    {
        Init();
    }

    void Update(unsigned char *input, unsigned int inputLen);
    void Final();

private:
    void Init();
    void Transform(const unsigned char block[64]);
    void Encode(unsigned char *output, const unsigned int *input, unsigned int length);
    void Decode(unsigned int *output, const unsigned char *input, unsigned int length);

    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];

public:
    unsigned char digest[16];
};

[[CHILDREN]]

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Non-range source container and exact 0x68-byte class model for the project MD5 implementation, including source/header framing, class layout, member-method declarations, free-wrapper children, writable PADDING data, and deterministic class-level emitter ordering. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MD5

## Status

- Confidence is very strong for the algorithm family, exact `0x68` object layout, method set, source-file placement, and class-level child order; it is strong for the inferred original class and private-member spellings.
- Source owner: [UID:0000L6][MD5](by-file/MD5.md), projected as `NexusTK/util/MD5.cpp` and `NexusTK/util/MD5.h`.
- Main in-range implementation aggregate: [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md).
- Adjacent member helpers: [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md).
- Writable padding data: [UID:00027R][0x0066ddd8-0x0066de18.Md5PaddingBlock](by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md).

## Class Purpose

`MD5` is the project-owned streaming MD5 implementation used by packet construction, registry persistence, startup/update hashing, screenshot proof generation, file hashing, stream hashing, and one-shot byte/string wrappers. The class owns the incremental hash state and block transform; file-scope `Md5...` wrappers construct a local `MD5`, call its methods, and expose the exact return or output-buffer contracts observed in the executable.

The source model is intentionally conventional late-1990s through mid-2000s C++ rather than decompiler-shaped code. `MD5` replaces the historical descriptive placeholder `MD5Context`. `Md5...` remains the wrapper naming family, while the conventional writable static data name is `PADDING` and the round operations remain macros. No evidence establishes third-party source provenance, so this remains project-integrated source rather than a `third_party_embeds` import.

## Exact Layout

| Offset | Size | Source field | Evidence and role |
| --- | ---: | --- | --- |
| `+0x00` | `0x10` | `unsigned int state[4]` | Four standard MD5 state words initialized to `0x67452301`, `0xefcdab89`, `0x98badcfe`, and `0x10325476`. |
| `+0x10` | `0x08` | `unsigned int count[2]` | Low/high bit count updated by `MD5::Update` and encoded by `MD5::Final`. |
| `+0x18` | `0x40` | `unsigned char buffer[64]` | Partial 64-byte input block accumulated between transforms. |
| `+0x58` | `0x10` | `unsigned char digest[16]` | Final digest storage read directly by file-scope wrappers. |
| total | `0x68` | `sizeof(MD5)` | Repeated wrapper stack layouts and every member offset agree on this size. |

The trailing `public` section for `digest` is deliberate. It preserves the observed offset and permits the wrappers to read `md5.digest` without inventing an accessor absent from the executable. `state`, `count`, and `buffer` remain private. No vtable, base object, hidden padding member, or endian-mode field is supported.

## Method And Wrapper Model

| Source entity | Exact body range | Role |
| --- | --- | --- |
| `MD5::Init` | `0x00515660-0x00515684` | Clears the bit count and initializes the four state words; its stores are also inlined into one-shot wrappers. |
| `MD5::Update` | `0x00515690-0x00515744` | Updates bit counts, fills the partial block, and transforms complete 64-byte blocks. |
| `MD5::Final` | `0x00515750-0x00515831` | Encodes bit length, appends `PADDING`, writes `digest`, and clears state/count/buffer. |
| `MD5::Transform` | `0x00515840-0x00515f48` | Performs all 64 MD5 compression rounds and accumulates the result into `state`. |
| `MD5::Encode` | `0x00515f50-0x00515f9c` | Converts words to little-endian bytes. |
| `MD5::Decode` | `0x00515fa0-0x00515ff2` | Converts little-endian bytes to words. |
| `Md5DigestToHexString` | `0x005151f0-0x00515284` | Formats a 16-byte digest as a heap-allocated lowercase hexadecimal string. |
| `Md5StringHex` | `0x00515290-0x0051530a` | Hashes a NUL-terminated ANSI string. |
| `Md5BytesHex` | `0x00515310-0x00515375` | Hashes a byte range and returns a heap hexadecimal string. |
| `Md5BytesRaw` | `0x00515380-0x005153dc` | Returns the local object's digest pointer, preserving the observed transient-pointer contract. |
| `Md5BytesToBuffer` | `0x005153e0-0x00515445` | Copies the 16-byte digest to caller-provided storage. |
| `Md5FilePathHex` | `0x00515450-0x00515569` | Opens a binary file path, hashes 1024-byte chunks, and returns hex or the shared fallback literal. |
| `Md5StreamHex` | `0x00515570-0x0051565b` | Hashes an existing stream in 1024-byte chunks and returns hex or the shared fallback literal. |

`Encode` and `Decode` are private member functions, not unrelated free helpers. Their callee-cleaned three-stack-argument bodies, placement beside the class methods, and inlined equivalents inside `Final`/`Transform` support the member model even though they do not read `this` directly.

## Source And Emitter Placement

This non-range class page provides the only top-level CPP/H framing and emits through UID0000L6 at position `0`. Its direct children are deliberately not all inside one by-memory range:

| Child | Position | Reason |
| --- | ---: | --- |
| UID00027R `PADDING` | `0` | File-scope writable data must appear before `MD5::Final` and lies outside UID0001B6. |
| UID0001B6 in-range aggregate | `10` | Inserts only the exact `0x005151f0-0x00515f48` function children. |
| UID000237 endian methods | `20` | Adjacent member bodies lie after UID0001B6 and remain a separate exact memory page. |

This topology prevents UID0001B6 from claiming out-of-range bytes and prevents duplicate body emission. UID0001B6 owns fixed in-range child positions in ascending address order; method declarations remain on this class page, while free-wrapper declarations live on their exact by-memory children.

## Runtime Contracts And Callers

- `Md5StringHex` is used by PacketTransform/startup paths.
- `Md5BytesRaw` has one packet-builder caller that immediately samples digest indices `13`, `3`, `11`, and `7` before the transient local storage is overwritten.
- `Md5BytesToBuffer` writes the RegistryConfig digest to a caller-owned 16-byte output.
- `Md5StreamHex` serves screenshot proof generation.
- `Md5FilePathHex` and `Md5StreamHex` return the shared literal `000011112222333344445555666677778888` on their observed failure conditions.
- Heap strings produced by `Md5DigestToHexString` use `_strdup`; callers retain the corresponding `free` ownership contract.

The transient `Md5BytesRaw` return is unsafe by modern C++ standards but is intentional here. Replacing it with stable storage, an output argument, or a safe container would alter observed behavior and is therefore rejected.

## Boundary And Negative Evidence

Modeled and raw bodies are separated by exact compiler `0xcc` fences of 12, 6, 11, 4, 11, 7, 5, 12, 12, 15, and 8 bytes through the main island, plus a four-byte fence between `Encode` and `Decode` and a fourteen-byte fence before the unrelated `0x00516000` successor. These bytes are alignment, not authored source entities, and must never be consumed by function creation or emitted as C++.

No direct xref, absolute pointer, RVA pointer, or direct relative branch route was found for raw starts `0x00515310`, `0x00515450`, `0x00515660`, `0x00515f50`, or `0x00515fa0`. Positive controls recovered expected modeled calls. The complete bounded bodies, family adjacency, exact member accesses, and inline duplicates establish source roles despite the no-route state. No-route remains a liveness/confidence caveat; it is not a reason to omit executable source.

No original class, field, function, local, or data symbols survive except the existing source-quality `Md5StringHex` name. The final source therefore uses evidence-backed human names rather than `sub_`, `dword_`, or `MD5Context`. Exact original spellings, comments, and compiler flags remain unrecoverable and keep this page below `95/95` until compile/behavior/binary comparison is available.

## Historical Assumptions And Rejected Alternatives

- Earlier documentation used `MD5Context` as a descriptive placeholder and manually initialized it in wrappers. The repeated `0x68` layout, thiscall methods, raw `Init`, and conventional method family supersede that model with class `MD5` and an inline constructor calling `Init`.
- Earlier aggregate output remained blank because raw helper routes, class spelling, and the transient digest return were unresolved. Bounded body analysis and the exact caller contract resolve those blockers without modernizing behavior.
- A pure-C context/functions model is rejected by the thiscall member methods and source organization.
- Ownership by PacketTransform, RegistryConfig, StartupWindow, or ScreenshotCapture is rejected because each is only a consumer of the same cross-subsystem utility.
- Merging UID000237 or UID00027R into UID0001B6 is rejected because their exact addresses lie outside that aggregate's half-open range.
- Third-party source import is rejected because no exact vetted staged source or provenance match was established.

## Cross-References

- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0001B6][0x005151f0-0x00515f48.MD5HashHelpers](by-memory/0x005151f0-0x00515f48.MD5HashHelpers.md)
- [UID:0001B7][0x00515310-0x00515375.Md5BytesHex](by-memory/0x00515310-0x00515375.Md5BytesHex.md)
- [UID:0001B8][0x00515450-0x00515568.Md5FilePathHex](by-memory/0x00515450-0x00515568.Md5FilePathHex.md)
- [UID:000237][0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers](by-memory/0x00515f50-0x00515ff2.MD5EndianEncodeDecodeHelpers.md)
- [UID:00027R][0x0066ddd8-0x0066de18.Md5PaddingBlock](by-memory/0x0066ddd8-0x0066de18.Md5PaddingBlock.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0003J1][0x0061ead4-0x0061eadc.Md5HexFormatString](by-memory/0x0061ead4-0x0061eadc.Md5HexFormatString.md)
- [UID:0003C4][0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData](by-memory/0x0061eadc-0x0061eb08.MapPaneDigitPatternBoundaryTailData.md)

## Changes

### 2026-07-26 - B001 UID0001B6 class/source callback

- Created the non-range `MD5` source container with exact `0x68` layout, method declarations, CPP/H framing, and deterministic sibling routing through UID0000L6.
- Preserved raw no-route evidence, every boundary fence, the transient digest-pointer behavior, and historical rejected source models while replacing decompiler-shaped `MD5Context` output with human source-facing class `MD5`.
