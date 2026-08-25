** TARGET-REPORT-UID:0002TJ **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002TJ DecodeZpfFpfToTileContext Source-Quality Report

Agent: Agent-B006  
Assignment: B-only source-quality / heuristic research for [UID:0002TJ] `DecodeZpfFpfToTileContext`  
Target: `source-3/project-documentation/by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md`  
Required output path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0002TJ-DecodeZpfFpfToTileContext-source-quality.md`  
Status: report-only. No target/support by-* docs, generated files, or `by-memory/-coverage-report.md` were edited.

## Bottom Line

[UID:0002TJ] should stay source-authored under [UID:0000K3] `ImageLoaders` / `NexusTK/render/ImageLoaders.cpp`, and it is first-draft C++ ready.

Recommended source-facing shape:

```cpp
void DecodeZpfFpfToTileContext(
    const unsigned char* zpfBuffer,
    unsigned int zpfBufferSize,
    EPFTileContext* destination);
```

The middle argument is present in the modeled `__cdecl` function and sibling wrapper convention, but this body does not read it. A two-argument signature is not source-quality for this target.

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale: the main open blockers are now resolved or bounded. `sub_414390` is zlib `Uncompress`, the EPFTileContext callees have source-quality names, the local object is a stack `_AUTOBUF<unsigned char>` temporary initialized inline, and the no-caller status has been rechecked through function exports, docs, generated output, and PE byte scans. Confidence should remain below final/perfect because the exact original helper name is inferred and no indirect/data-driven caller has been found.

## Evidence Checked

- Target doc `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md`.
- Parent/support docs:
  - `by-file/ImageLoaders.md`
  - `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
  - `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`
  - `by-class/EPFTileContext.md`
  - `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
  - `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`
  - `by-type/by-template/AUTOBUF_unsigned_char.md`
  - `by-class/AUTOBUF_unsigned_char.md`
  - `by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md`
  - `by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md`
  - `by-memory/0x004142c0-0x00419e56.ZlibCore.md`
  - `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`
  - `by-file/Zlib.md`
- Exported function data:
  - `resources/exported_data/functions/0x004d05f0.json`
  - `resources/exported_data/functions/0x00414390.json`
  - sibling signatures for `0x004d07b0`, `0x004d09b0`, and `0x004d0a90`
  - allocation/free helper exports for `0x005c7790` and `0x005c7799`
- Generated/staged output:
  - `auto-generated/NexusTK/render/ImageLoaders.cpp`
  - `auto-generated/-ag-memory-coverage.md`
  - `simroot_v2/recovered/Uncompress_00414390.cpp`
  - `simroot_v2` rg checks for `DecodeZpf`, `ZPF`, `FPF`, and `Uncompress`
- Coverage/project indexes:
  - `by-memory/-coverage-report.md`
  - `project-level/-resolved.md`
  - `project-level/-unresolved.md`
  - `project-level/-auto-completion-stats.md`
- Resource/meta checks:
  - `by-meta/client_dat_specifications.md`
  - `by-meta/client_libraries.md`
  - `by-resource/*` targeted rg for image-loader/ZPF/FPF mentions
- PE byte scans on both available `NexusTK.exe` copies:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - searched little-endian `0x004d05f0`, `0x000d05f0`, and `0x004d0730` pointer patterns plus `ZPF`/`FPF` ASCII magic strings.
- `source-3/project-documentation/tools/int_convert.py` conversions:
  - `0x133` = 307 decimal
  - `0x0d` = 13 decimal
  - `0x04` = 4 decimal
  - `0x08` = 8 decimal
  - `0x10` = 16 decimal
  - `0x12` = 18 decimal
  - `0x14` = 20 decimal
  - `0x18` = 24 decimal
  - `0x1c` = 28 decimal
  - `0x28` = 40 decimal
  - `0x9c` = 156 decimal

Live IDA MCP is not exposed in this Codex toolset. This pass used the current exported IDA/Ghidra JSON, existing live-IDA documentation, generated files, and local PE byte scans.

## Function Facts

Exported function data for `0x004d05f0` reports:

- address `0x004d05f0`;
- size 307 bytes (`0x133`);
- IDA name `sub_4D05F0`;
- IDA prototype shape `void __cdecl(char *Str1, int, int)`;
- Ghidra prototype shape `undefined __cdecl FUN_004d05f0(char * param_1, undefined4 param_2, void * param_3)`;
- zero callers / zero `xrefs_to`;
- ten callees.

The function starts by resetting the destination, checks `strncmp(zpfBuffer, "ZPF", 4)`, and on a match:

1. Reads the 32-bit field at `zpfBuffer + 4`.
2. Constructs a stack `_AUTOBUF<unsigned char>`-compatible object by calling the `LObject` shell constructor, writing the `_AUTOBUF<unsigned char>` vtable, and clearing fields.
3. Allocates a buffer of that size through the CRT/operator-new helper at `0x005c7790`.
4. Sets both the AUTOBUF count/capacity field and local zlib output-size variable to that same size.
5. Calls zlib `Uncompress(output, &decodedSize, zpfBuffer + 8, zpfPayloadSize)`.
6. Resets the destination again.
7. Validates inner `FPF`: version word `1` at `+0x04`, then `strncmp(fpfBuffer, "FPF", 4)`.
8. Calls `EPFTileContext::AllocateWordPixels(width, height)` with width at inner `+0x10` and height at inner `+0x12`.
9. Copies `2 * (right-left) * (bottom-top)` bytes from `fpfBuffer + *(uint32_t *)(fpfBuffer + 0x18)` to `destination->pixelData`.
10. Calls `EPFTileContext::NormalizePostDecodePixels()`.
11. Restores the AUTOBUF vtable, frees the local byte buffer, and calls the `LObject` destructor shell.

The 32-bit ZPF field at `+0x04` should not be documented strictly as either only compressed length or only uncompressed length. The binary uses it for both output allocation/capacity and zlib input byte limit. Recommended source-facing field name in docs: `zpfPayloadSize` or `payloadSize`. Rejected names:

- `compressedLength`: incomplete, because the same value is used to allocate decompression output capacity.
- `uncompressedLength`: incomplete, because the same value is passed to zlib as the compressed input length.
- `bufferLength`: too broad and confuses it with the unused second formal parameter.

## Raw Names Resolved

| Raw/current name | Recommended source-quality name or role | Confidence | Evidence |
| --- | --- | --- | --- |
| `sub_4D05F0` | `DecodeZpfFpfToTileContext` | High | Exact behavior is outer `ZPF` plus inner `FPF` to `EPFTileContext`; existing target/parent docs already use this name. |
| `sub_414390` / `FUN_00414390` | `Uncompress` | Very high | zlib docs map `0x00414390-0x0041442c` to zlib 1.1.4 `uncompress`; exported decomp calls inflate init/run/end. |
| `sub_458500` | `EPFTileContext::ReleaseBuffers` | Very high | EPFTileContext docs identify reset/release method at `0x00458500`. |
| `sub_458430` | `EPFTileContext::AllocateWordPixels` | Very high | EPFTileContext docs identify word-pixel allocator at `0x00458430`; image wrappers call it for 16-bit decode output. |
| `sub_458560` | `EPFTileContext::NormalizePostDecodePixels` | Very high | [UID:000200] has first-draft method C++ and caller row for `0x004d06f2`. |
| `sub_4F4A80` / `sub_4F4A90` | `LObject` constructor/destructor shell | High | `LObjectRuntimeShell` documents the bodies; target uses them around a local AUTOBUF object. |
| `_AUTOBUF<unsigned char>::vftable` | `_AUTOBUF<unsigned char>` / `AUTOBUF<unsigned char>` temporary | High | Exact vtable refs at `0x004d0651` and `0x004d06fa`; support docs map vtable data and layout. |
| `unknown_libname_19` / `0x005c7790` | `operator new` allocation helper | High | Exported decompilation is `return operator new(size)`, 163 callers. |
| `j_j_j___free_base` / `0x005c7799` | CRT/free helper | High | Exported decompilation is a `free`/`HeapFree` wrapper, 250 callers. |
| `aZpf` / `aFpf` | `"ZPF"` / `"FPF"` magic strings | High | PE scans find one copy each at raw offsets `0x21a274` and `0x21a278`, matching documented VAs `0x0061b874` and `0x0061b878`. |

## Name And Signature Resolution

Recommended name: `DecodeZpfFpfToTileContext`.

Rejected alternatives:

- `DecodeZpfToTileContext`: plausible original shorthand because the caller supplies a ZPF buffer, but it hides the inner FPF-specific validation/header layout and is not strong enough to justify a file rename. Keep as an alias note if desired.
- `DecodeCompressedFpfToTileContext`: behaviorally accurate but less anchored to the observed outer magic string.
- `LoadZpfImage` / `LoadZpfResource`: rejected because there is no file/DAT access and no known resource caller inside this function.
- `EPFTileContext::LoadZpf`: rejected because the function is `__cdecl` global wrapper code, not a `thiscall` method; the destination is an explicit third argument.

Recommended signature:

```cpp
void DecodeZpfFpfToTileContext(
    const unsigned char* zpfBuffer,
    unsigned int zpfBufferSize,
    EPFTileContext* destination);
```

Rejected signature alternatives:

- `void DecodeZpfFpfToTileContext(const unsigned char*, EPFTileContext*)`: rejected because both IDA/Ghidra exports show three arguments, and sibling modeled decoders such as `DecodeJpfImageToTileContext` and `DecodeJpegBufferToTileContext` use the same `(buffer, size, destination)` convention.
- `bool` or `int` return status: rejected because the binary is void and ignores the `Uncompress` status; failure leaves the destination reset.
- `char*` first argument: keep only as a decompiler artifact. The function treats bytes and magic headers, not mutable text.
- signed `int zpfBufferSize`: acceptable ABI-wise, but `unsigned int` better matches the sibling buffer-size usage and zlib `inputSize` type. It is unused either way.

## First-Draft C++

This is suitable for the target `RECONSTRUCTION_CPP` block after the supervisor accepts implementation. It uses source-facing helper names already supported by the referenced docs. The AUTOBUF field/accessor spelling is the least certain part; if the AUTOBUF owner standardizes on different accessors, substitute that mechanically without changing target behavior.

```cpp
void DecodeZpfFpfToTileContext(
    const unsigned char* zpfBuffer,
    unsigned int zpfBufferSize,
    EPFTileContext* destination)
{
    (void)zpfBufferSize;

    destination->ReleaseBuffers();

    if (strncmp(reinterpret_cast<const char*>(zpfBuffer), "ZPF", 4) != 0) {
        return;
    }

    const unsigned int zpfPayloadSize =
        *reinterpret_cast<const unsigned int*>(zpfBuffer + 4);

    _AUTOBUF<unsigned char> decompressedFpf;
    decompressedFpf.Resize(zpfPayloadSize);

    unsigned int decodedSize = zpfPayloadSize;
    Uncompress(decompressedFpf.data, &decodedSize, zpfBuffer + 8, zpfPayloadSize);

    const unsigned char* const fpfBuffer = decompressedFpf.data;
    destination->ReleaseBuffers();

    if (*reinterpret_cast<const unsigned short*>(fpfBuffer + 4) != 1 ||
        strncmp(reinterpret_cast<const char*>(fpfBuffer), "FPF", 4) != 0) {
        return;
    }

    const unsigned int width =
        *reinterpret_cast<const unsigned short*>(fpfBuffer + 0x10);
    const unsigned int height =
        *reinterpret_cast<const unsigned short*>(fpfBuffer + 0x12);
    destination->AllocateWordPixels(width, height);

    const unsigned int pixelOffset =
        *reinterpret_cast<const unsigned int*>(fpfBuffer + 0x18);
    memmove(
        destination->pixelData,
        fpfBuffer + pixelOffset,
        2 * (destination->bounds.right - destination->bounds.left) *
            (destination->bounds.bottom - destination->bounds.top));

    destination->NormalizePostDecodePixels();
}
```

Binary-specific notes for implementation:

- The binary ignores the `Uncompress` return value and does not compare `decodedSize`; the draft intentionally does the same.
- The binary validates the version word before the `FPF` signature. Keep that order if preserving optimized branch shape matters.
- The binary calls `ReleaseBuffers` before the ZPF check and again after decompression before validating the inner FPF. Failure after a valid ZPF leaves the destination reset.
- The binary computes copy size from destination bounds after allocation, not directly from the FPF width/height locals.

## Caller And Reachability Recheck

Current best conclusion: no direct or function-pointer caller is known; retained legacy image-loader support remains the best explanation.

Evidence checked:

- Exported function data for `0x004d05f0` reports `num_callers` zero and empty IDA `xrefs_to`.
- Existing target and aggregate docs record prior IDA caller/xref checks with no direct callers.
- `ImageDecodeWrappers` documents ordinary direct callers for adjacent `JPF`, BMP, and raw JPEG wrappers, but not for this target or the raw `FPF` sibling.
- `auto-generated/NexusTK/render/ImageLoaders.cpp` contains only empty emitter markers for this wrapper family. No generated dispatch table or direct call was found there.
- `simroot_v2` search finds `Uncompress` users and the direct JPF profile call, but no `DecodeZpf*`, `ZPF`, or `FPF` source callsite.
- Project docs targeted search finds only format-magic/support documentation for `ZPF`/`FPF`, no asset extension or resource-name caller.
- PE byte scan on both available `NexusTK.exe` copies found:
  - `0x004d05f0` VA pointer bytes: zero hits.
  - `0x000d05f0` RVA pointer bytes: zero hits.
  - `0x004d0730` raw FPF helper VA pointer bytes: zero hits.
  - `ZPF` ASCII: one hit at raw `0x21a274`.
  - `FPF` ASCII: one hit at raw `0x21a278`.

Rejected explanations:

- Hidden static function-pointer table: no VA/RVA pointer bytes were found for the target in the PE scans.
- Feature-owned private loader: no direct caller, asset extension, or resource doc ties the target to one feature.
- Dead padding/glue: rejected because this is a modeled 307-byte function with normal callees, SEH/AUTOBUF cleanup, zlib use, EPFTileContext writes, and a clean return.
- Third-party decompression code: rejected because only the callee `Uncompress` is zlib; this wrapper owns NexusTK-specific ZPF/FPF and tile-context policy.

Open reachability question after this pass:

- It remains possible that a data-driven loader dispatches by format magic and the dispatch target is computed without storing the function VA directly, or that this is retained compatibility code for legacy assets not present in current package docs. No safe caller can be named from the available evidence.

## Source Ownership

Keep owner/emitter [UID:0000K3] `ImageLoaders`.

Evidence:

- The function is part of the contiguous image decode wrapper island `0x004d05f0-0x004d0f4a`.
- It uses the same destination type and post-decode finalizer as raw `FPF`, `JPF`, raw JPEG, and PNG decode wrappers.
- The source responsibility is project image-format staging and tile-context conversion.
- It depends on zlib `Uncompress` but is not zlib.
- It depends on `EPFTileContext` methods but is not an EPFTileContext method.
- It has no feature caller strong enough to move it to profile, main menu, minimap, startup, or DAT/archive source.

Recommended owner/emitter: unchanged.

## Support Doc Changes Needed

### Target by-memory doc

Recommended exact changes:

- Raise metadata to `COMPLETION:88`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000K3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K3`.
- Keep page/file name `DecodeZpfFpfToTileContext`; add alias note that `DecodeZpfToTileContext` is plausible shorthand but not recommended as a rename.
- Replace source role with:
  - `Source-facing role: DecodeZpfFpfToTileContext(const unsigned char* zpfBuffer, unsigned int zpfBufferSize, EPFTileContext* destination).`
- Replace callee raw names:
  - `sub_414390` -> `Uncompress`
  - `sub_458500` -> `EPFTileContext::ReleaseBuffers`
  - `sub_458430` -> `EPFTileContext::AllocateWordPixels`
  - `sub_458560` -> `EPFTileContext::NormalizePostDecodePixels`
  - `sub_4F4A80` / `sub_4F4A90` -> `LObject` constructor/destructor shell used by `_AUTOBUF<unsigned char>`
  - `unknown_libname_19` / `j_j_j___free_base` -> allocation/free runtime helpers
- Clarify the `+0x04` ZPF length/size field:
  - "The 32-bit field at `+0x04` is used both as the temporary output allocation/capacity and as zlib input byte limit for bytes at `+0x08`; call it `zpfPayloadSize` unless a later asset-format source proves a narrower name."
- Add first-draft C++ from this report.
- Replace passive open questions with attempted-resolution notes:
  - final original spelling inferred as `DecodeZpfFpfToTileContext`;
  - no-direct-caller rechecked via export/xref/docs/generated/PE pointer scans;
  - temporary buffer is `_AUTOBUF<unsigned char>` with support-type field/accessor spelling still owned by AUTOBUF docs.

### `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`

- Update the target row to include the three-argument signature and zlib helper name:
  - `DecodeZpfFpfToTileContext(const unsigned char* zpfBuffer, unsigned int zpfBufferSize, EPFTileContext* destination)`.
- Add evidence bullet:
  - B006 source-quality pass checked exported `0x004d05f0` signature, local PE pointer scans, single `ZPF`/`FPF` literal copies, zlib `Uncompress` route, and AUTOBUF/EPFTileContext support docs.
- Keep aggregate C++ blank. The aggregate still spans multiple wrappers including raw/no-code helper cases; this pass only makes the exact child C++ ready.

### `by-file/ImageLoaders.md`

- Update proposed contents row for [UID:0002TJ]:
  - "First-draft C++ ready. Three-argument source wrapper; the second byte-count argument is unused in the binary. Uses zlib `Uncompress` and a stack `_AUTOBUF<unsigned char>` temporary, then validates/copies inner `FPF` pixels."
- Add evidence bullet for the no-caller recheck and PE pointer scan.
- No path/owner change.

### EPFTileContext docs

Docs to touch only lightly:

- `by-class/EPFTileContext.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`

Recommended additions:

- Note that [UID:0002TJ] now uses source-facing method names `ReleaseBuffers`, `AllocateWordPixels`, and `NormalizePostDecodePixels` in first-draft child C++.
- No metadata change required.

### AUTOBUF docs

Docs to update:

- `by-type/by-template/AUTOBUF_unsigned_char.md`
- `by-class/AUTOBUF_unsigned_char.md`
- `by-file/AUTOBUF.md`
- `by-memory/0x0061b864-0x0061b874.AUTOBUFUnsignedCharVtableData.md`

Recommended additions:

- Add [UID:0002TJ] as an image decode usage site with inline construction/allocation:
  - vtable writes at target offsets reflected by xrefs `0x004d0651` and `0x004d06fa`;
  - local `_AUTOBUF<unsigned char>` stack object;
  - buffer pointer at `+0x04` and count/capacity at `+0x08`;
  - target inlines the constructor/resize-like allocation rather than calling the out-of-line `AUTOBUFUnsignedCharConstructor` or `AUTOBUFUnsignedCharResize`.
- No metadata change required unless the AUTOBUF owner also resolves final field/accessor names.

### Zlib docs

Docs to update:

- `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`
- `by-memory/0x004142c0-0x00419e56.ZlibCore.md`
- `by-file/Zlib.md`

Recommended addition:

- Add [UID:0002TJ] as a documented `Uncompress` consumer in the image/resource wrapper group.
- No metadata change required.

### Project-level generated issue docs

- `project-level/-unresolved.md` references for this target's `sub_414390`, `sub_458500`, and `sub_458430` should clear after target/support regeneration.
- `aZpf` remains in unresolved because it is a raw IDA string label used as a boundary marker in support docs; do not hand-edit project-level generated files in this report-only pass.

## Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts the report, replace the existing [UID:0002TJ] row with:

```text
        - [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) 0x004d05f0-0x004d0723 | function | DecodeZpfFpfToTileContext : reconstructable : 88% : strong : B006 source-quality pass; source-authored ImageLoaders ZPF/FPF wrapper with signature `void DecodeZpfFpfToTileContext(const unsigned char* zpfBuffer, unsigned int zpfBufferSize, EPFTileContext* destination)`, using the `+0x04` ZPF size field for both AUTOBUF output capacity and zlib `Uncompress` input limit over bytes at `+0x08`, validating inner FPF version/signature, allocating/copying 16-bit pixels into `EPFTileContext`, normalizing through the shared post-decode method, retaining no-direct-caller/no-function-pointer evidence after export/xref/generated/PE byte scans, and now first-draft C++ ready.
```

After validator/autogen regeneration, the corresponding generated memory coverage row should move from `emits/no` to `coded/yes`:

```text
| [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) | coded | `0000K3` | `0000K3` |  | yes | `auto-generated/NexusTK/render/ImageLoaders.cpp` | `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md` |  |
```

No aggregate [UID:000175] row replacement is required solely for this child C++ update unless the supervisor wants to mention B006 in the aggregate row.

## Validator Needs

Recommended validation commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002TJ-DecodeZpfFpfToTileContext-source-quality-removed.md](0002TJ-DecodeZpfFpfToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator script name differs in this workspace, use the supervisor's current scoped validator command for the same paths. Also regenerate/check:

> Executable block R002 was removed from this report and preserved verbatim in [0002TJ-DecodeZpfFpfToTileContext-source-quality-removed.md](0002TJ-DecodeZpfFpfToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

Recommended IDA changes, all report-only until an implementation callback:

| Address / item | Recommendation | Confidence |
| --- | --- | --- |
| `0x004d05f0` | Rename `sub_4D05F0` to `DecodeZpfFpfToTileContext`. | High |
| `0x004d05f0` type | Apply `void __cdecl DecodeZpfFpfToTileContext(const unsigned char *zpfBuffer, unsigned int zpfBufferSize, EPFTileContext *destination);`. | High |
| arg 1 | Name `zpfBuffer`. | High |
| arg 2 | Name `zpfBufferSize` and comment `unused by this optimized body; kept for wrapper-family signature`. | High |
| arg 3 | Name `destination` / type `EPFTileContext*`. | High |
| stack local AUTOBUF | Type as `_AUTOBUF<unsigned char>` if local types are available. | Medium-high |
| `0x00414390` | Ensure name/type `Uncompress(unsigned char*, unsigned int*, const unsigned char*, unsigned int)`. | Very high |
| `0x00458500` | Ensure name `EPFTileContext::ReleaseBuffers`. | Very high |
| `0x00458430` | Ensure name `EPFTileContext::AllocateWordPixels`. | Very high |
| `0x00458560` | Ensure name `EPFTileContext::NormalizePostDecodePixels`. | Very high |
| `0x005c7790` | Prefer library/helper comment `operator new allocation helper`; avoid feature-specific rename. | High |
| `0x005c7799` | Prefer library/helper comment `free/HeapFree wrapper`; avoid feature-specific rename. | High |
| `0x0061b874` / `0x0061b878` | Comment as `ZPF` and `FPF` magic strings used by ImageLoaders ZPF/FPF wrappers. | High |

Suggested function comment:

```text
ImageLoaders ZPF wrapper. Validates "ZPF", uses header +4 size as both zlib input limit and output capacity, inflates bytes at +8 through zlib Uncompress into a stack AUTOBUF<unsigned char>, then validates/copies inner FPF 16-bit pixels into EPFTileContext and normalizes post-decode pixels. No direct/function-pointer caller currently known.
```

## Open Questions With Attempted Resolution

| Question | Result |
| --- | --- |
| Exact original function name? | Best-supported doc/source name is `DecodeZpfFpfToTileContext`; `DecodeZpfToTileContext` is plausible shorthand but not strong enough to rename the target. |
| Is it source-authored or compiler glue? | Source-authored function. It has format validation, zlib call, destination allocation/copy, and explicit cleanup; compiler glue is limited to local AUTOBUF/SEH lowering. |
| Is it an EPFTileContext method? | No. It is global `__cdecl` wrapper code with explicit destination argument. |
| Is it zlib-owned? | No. zlib ownership applies only to `Uncompress` at `0x00414390`. |
| Does the second argument matter? | It is an unused formal parameter. Keep it in signature because the modeled function and sibling wrappers use the buffer-size convention. |
| What does the ZPF `+4` field mean? | The binary uses it as both allocation/output-capacity and zlib input byte limit. Use `zpfPayloadSize` until source/resource evidence proves a narrower name. |
| Does no direct caller block C++? | No. The function is modeled, source-authored, exact, and routed; no-caller status caps confidence but does not block first-draft C++ for this child. |
| Is there an indirect table? | No evidence found. Exported xrefs are empty; PE byte scans found no VA/RVA pointer to `0x004d05f0`; generated/source docs show no dispatch table. |
| Are resource/assets known? | No ZPF/FPF asset extension or resource-name route was found in targeted docs/generated/staged searches. Retained legacy support remains the best explanation. |

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

1. Update only the target and named support docs; do not broaden to raw FPF or PNG C++.
2. Populate target first-draft C++.
3. Update target score to `88/89`.
4. Update support docs with the resolved names/signature/no-caller evidence.
5. Update supervisor-owned `by-memory/-coverage-report.md` only if explicitly authorized by supervisor, using the exact row above.
6. Run scoped validation and generated-output checks.

Do not split the target range. `0x004d05f0-0x004d0723` is one modeled function; `0x004d0723-0x004d0730` remains padding; raw `FPF` starts at `0x004d0730` and remains its own child.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0002TJ-DecodeZpfFpfToTileContext-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0002TJ"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TJ-DecodeZpfFpfToTileContext-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0002TJ-DecodeZpfFpfToTileContext-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TJ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
