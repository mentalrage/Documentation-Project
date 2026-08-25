** TARGET-REPORT-UID:0002TK **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002TK] DecodeFpfToTileContext Source-Quality Report

Agent: Agent-B015  
Date: 2026-06-19  
Assignment: `B015-goal2-decode-fpf-to-tile-context-source-quality-0002TK-20260619`  
Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`  
Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0002TK-DecodeFpfToTileContext-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002TK] as a source-authored raw direct-`FPF` image decode helper owned and emitted by [UID:0000K3] `ImageLoaders`, raise the target from `85/87` to `88/90`, replace remaining raw helper placeholders with the best-supported descriptive names, and populate first-draft C++ in the target's formal `RECONSTRUCTION_CPP` block during the supervisor-approved implementation pass.
- Final disposition: no split, merge, range rename, or owner reroute is needed. The half-open range `0x004d0730-0x004d07a3` is exact and is bounded by thirteen `0xcc` bytes before and after.
- Owner/emitter recommendation: keep `CANONICAL_OWNER:0000K3`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000K3`. Leave `EMITTER_POSITION_OPTIONAL` blank unless the supervisor wants a larger ImageLoaders ordering pass.
- Source placement: `NexusTK/render/ImageLoaders.cpp`, immediately after `DecodeZpfFpfToTileContext` and before `DecodeJpfImageToTileContext`.
- C++ recommendation: populate formal C++ now. The active code-entry gate is met (`RECONSTRUCTABLE:TRUE`, valid nonblank emitter route, `(85+87)/2 = 86 > 85`), and the remaining caller/original-name gaps are now precise caveats rather than blockers. The C++ should use descriptive source names and documented `EPFTileContext` helper names, not raw `sub_` placeholders.
- I did not edit by-* docs, generated files, project-level reports, IDA, `by-memory/-coverage-report.md`, or any support docs. This assignment was report-only.

## Target

- Target UID: `0002TK`
- Current target path: `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000K3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K3`, blank formal C++.
- Recommended metadata after implementation: `COMPLETION:88`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000K3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000K3`, and blank `EMITTER_POSITION_OPTIONAL`.
- Current generated state: `auto-generated/NexusTK/render/ImageLoaders.cpp` includes [UID:0002TK] as an empty emitter marker.

## Evidence Checked

Primary target and direct support:

- [UID:0002TK] `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`
- [UID:0002TJ] `by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md`
- [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
- [UID:0000K3] `by-file/ImageLoaders.md`
- [UID:00004I] `by-class/EPFTileContext.md`
- [UID:0000XY] `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- [UID:000200] `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/render/ImageLoaders.cpp`
- `by-project-structure/proposed-source-tree.md`
- `project-level/-resolved.md`
- `project-level/-unresolved.md`

Prior work used as leads and rechecked:

- `Agent-B001/research/executed/older/000174-ResourceLayoutTable.md`
- `Agent-B001/validation-logs/B001-023-final/by-memory_0x004d0730-0x004d07a3.DecodeFpfToTileContext.md.log`
- `Agent-B001/validation-logs/B001-023-final/by-memory_0x004d0730-0x004d07a3.DecodeFpfToTileContext.md.rerun.log`

Raw executable:

- `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Size: `2679296`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Section map relevant to this target: `.text` VA `0x00401000`, raw `0x400`; `.rdata` VA `0x0060d000`, raw `0x20ba00`.

IDA MCP was not exposed as a callable tool in this session. The existing target/support pages record prior live IDA MCP checks from 2026-06-03, 2026-06-06, and 2026-06-10. This report reanalyzes those claims against current documentation, generated output, and a fresh read-only PE byte/pattern audit.

## Raw PE Facts

The raw executable maps `0x004d0730-0x004d07a3` to file offset `0x000cfb30-0x000cfba3`.

```text
VA range:  0x004d0730-0x004d07a3
Raw range: 0x000cfb30-0x000cfba3
Length:    0x73 / 115 bytes
SHA1:      1a7da272dfaebc6c0e5b5f7b3a4d0559e4f9ff94
```

Pre-padding:

```text
0x004d0723-0x004d0730:
cc cc cc cc cc cc cc cc cc cc cc cc cc
```

Target body:

```text
55 8b ec 56 57 8b 7d 0c 8b cf e8 c1 7d f8 ff 8b
75 08 b8 01 00 00 00 66 3b 46 04 75 52 6a 04 68 78
b8 61 00 56 e8 f6 eb 10 00 83 c4 0c 85 c0 75 3e 0f
b7 46 12 8b cf 50 0f b7 46 10 50 e8 be 7c f8 ff 8b
57 1c 8b 47 18 2b 47 10 2b 57 14 0f af d0 8b 46 18
03 c6 03 d2 52 50 ff 77 04 e8 1e 8e 0f 00 83 c4 0c
8b cf 5f 5e 5d e9 c1 7d f8 ff 5f 5e 5d c3
```

Post-padding:

```text
0x004d07a3-0x004d07b0:
cc cc cc cc cc cc cc cc cc cc cc cc cc
```

Adjacent literal island:

```text
raw 0x21a270:
c0 b6 41 00 5a 50 46 00 46 50 46 00 4a 50 46 00
54 00 49 00 4c 00 45 00 2e 00 45 00 50 00 46 00

ASCII view:
..A.ZPF.FPF.JPF.T.I.L.E...E.P.F.
```

This confirms contiguous `ZPF`, `FPF`, and `JPF` string literals at `0x0061b874`, `0x0061b878`, and `0x0061b87c`, matching the wrapper-family interpretation.

## Instruction-Level Behavior

The target has a normal source-shaped prologue and callee-saved register use:

```asm
004d0730  push ebp
004d0731  mov  ebp, esp
004d0733  push esi
004d0734  push edi
004d0735  mov  edi, [ebp+0x0c]     ; destination EPFTileContext*
004d0738  mov  ecx, edi
004d073a  call 0x00458500          ; EPFTileContext::ReleaseBuffers
004d073f  mov  esi, [ebp+0x08]     ; const unsigned char* fpfBuffer
004d0742  mov  eax, 1
004d0747  cmp  [esi+0x04], ax      ; version == 1
004d074b  jne  0x004d079f
004d074d  push 4
004d074f  push 0x0061b878          ; "FPF"
004d0754  push esi
004d0755  call _strncmp
004d075d  test eax, eax
004d075f  jne  0x004d079f
004d0761  movzx eax, word [esi+0x12]
004d0767  push eax                 ; height
004d0768  movzx eax, word [esi+0x10]
004d076c  push eax                 ; width
004d076d  call 0x00458430          ; EPFTileContext::AllocateWordPixels
004d0772  mov  edx, [edi+0x1c]     ; bounds.bottom
004d0775  mov  eax, [edi+0x18]     ; bounds.right
004d0778  sub  eax, [edi+0x10]     ; width from bounds
004d077b  sub  edx, [edi+0x14]     ; height from bounds
004d077e  imul edx, eax            ; pixel count
004d0781  mov  eax, [esi+0x18]     ; pixel data offset
004d0784  add  eax, esi            ; source pixels
004d0786  add  edx, edx            ; byte count for 16-bit pixels
004d0788  push edx
004d0789  push eax
004d078a  push [edi+0x04]          ; destination pixelData
004d078d  call _memmove
004d0795  mov  ecx, edi
004d0797  pop  edi
004d0798  pop  esi
004d0799  pop  ebp
004d079a  jmp  0x00458560          ; EPFTileContext::NormalizePostDecodePixels
004d079f  pop  edi
004d07a0  pop  esi
004d07a1  pop  ebp
004d07a2  ret
```

The failure path returns after `ReleaseBuffers` but before allocation/copy/finalization. The success path tail-jumps to the shared post-decode normalization method after restoring the saved registers and `ebp`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| Entity kind | Target bytes, pre/post padding, prior IDA MCP no-function notes, raw PE body SHA1, body shape. | Source-authored raw helper body that IDA did not promote to a function. Keep page kind `raw-helper`, but document that it is real code. | Reject padding/gap: normal prologue, calls, branches, and `ret` prove code. Reject compiler/runtime helper: behavior is project image decode logic. |
| Function name | Existing target title, wrapper-family docs, literal island `ZPF`/`FPF`/`JPF`, sibling names `DecodeZpfFpfToTileContext` and `DecodeJpfImageToTileContext`. | Use `DecodeFpfToTileContext`. This is descriptive/inferred, not proven original symbol spelling, but it is the strongest source-facing name. | Reject `sub_4D0730`: raw generated placeholder only. Reject `DecodeRawFpfToTileContext` for formal title because the sibling naming style already uses format names directly. Reject `LoadFpf` because the helper decodes an already supplied buffer into an existing destination context, not a file/resource path. |
| Signature | Stack accesses `[ebp+0x08]` and `[ebp+0x0c]`; plain `ret`; `ecx` loaded only for destination method calls; no return value. | `void DecodeFpfToTileContext(const unsigned char* fpfBuffer, EPFTileContext* destination)`. Calling convention is caller-cleaned/free-function source shape. | Reject `EPFTileContext::DecodeFpf(...)`: `this` is not the implicit receiver on entry; destination is a stack argument. Reject `__stdcall`: plain `ret`, not `ret 8`. Reject returning success/failure: no value is set for a source return result. |
| FPF header type and fields | Offsets read in the body, ZPF sibling inner branch, FPF literal at `0x0061b878`. | Recommended descriptive support type: `FpfHeader` or `FpfImageHeader`, with `signature[4]` at `+0x00`, `version` at `+0x04`, `width` at `+0x10`, `height` at `+0x12`, and `pixelDataOffset` at `+0x18`. Unknown/reserved bytes at `+0x06..+0x0f` and `+0x14..+0x17` should stay unnamed or `reserved` until another parser proves their meaning. | Reject assigning meaning to unknown header gaps. Reject a packed BMP/JPEG-like header: the only validated format fields are FPF magic/version/dimensions/pixel offset. |
| `aFpf` placeholder | Literal bytes and prior resolved report. | Replace references to raw `aFpf` with `"FPF"` / `kFpfSignature` only as descriptive source text. | Do not create a global owner for `"FPF"`; it is a pooled/static literal within the wrapper family. |
| `sub_458500` | EPFTileContext aggregate and class docs; caller/callee role. | Use `EPFTileContext::ReleaseBuffers`. In this target it is a destination reset/release step. | Reject generic `Clear` as too broad: the support docs say it frees primary, auxiliary, and encoded-mask buffers and clears pointers. |
| `sub_458430` | EPFTileContext aggregate docs and image-loader caller set. | Use `EPFTileContext::AllocateWordPixels(width, height)`. | Reject `AllocateTileContext`: the helper sets 16-bit/word-pixel mode and allocates only the primary pixel buffer. |
| `sub_458560` | [UID:000200] source-quality update and first-draft C++. | Use `EPFTileContext::NormalizePostDecodePixels`. | Reject leaving `sub_458560`: [UID:000200] has resolved helper/global names and formal C++. |
| Destination fields | EPFTileContext layout docs, target offset reads. | Use `pixelData` at `+0x04`; `bounds.left/top/right/bottom` at `+0x10/+0x14/+0x18/+0x1c`. | Do not rename broader class fields like `pixelMode`, `auxiliaryData`, or mask fields from this target; this body does not touch them. |
| Pixel byte count | Target arithmetic and `AllocateWordPixels` caller convention. | Source computes byte count as `((right-left) * (bottom-top)) * sizeof(unsigned short)`. Since allocation creates zero-origin bounds, this is equivalent to `width * height * 2`, but the binary uses bounds fields after allocation. | Reject direct `width * height * 2` in formal C++ if exact source-shape fidelity is preferred; using bounds preserves the observed dependency and matches the shared finalizer style. |
| Caller/reachability | Existing IDA no-xref checks; fresh PE rel32-to-start scan; pointer pattern scan; branch/pointer-looking candidate inspection. | No confirmed direct caller, jump, function pointer, absolute VA pointer, or dispatch-table reference to `0x004d0730`. Best interpretation: retained legacy/direct FPF helper compiled with the ImageLoaders object but apparently not statically reachable in the current executable. | Reject table/dispatch ownership: no table/pointer evidence. Reject "not real" because no callers: code body and sibling equivalence prove a real source helper. Reject assigning to a known feature caller: there is no caller. |
| IDA non-function status | Target/support docs and raw range evidence. | IDA likely did not promote the body because no known xref or entry point reaches `0x004d0730`; this should be recorded as a tooling/reachability caveat, not as behavior uncertainty. | Do not keep "why does IDA not model it" as a blocking open question after this pass. Exact IDA heuristic internals are not provable from the docs, but the practical cause is no recognized entry xref. |
| Source owner | ImageLoaders page, wrapper aggregate, proposed source tree, literal island, shared `EPFTileContext` helper calls. | Keep [UID:0000K3] `ImageLoaders` / `NexusTK/render/ImageLoaders.cpp`. | Reject [UID:00004I] `EPFTileContext`: destination is a consumer object argument, not the source owner. Reject `ResourceLayoutTable`: address adjacency only; semantics are image decoding. Reject `ImageFrameTable`, `ImageLib`, `LibJPEG`, `LodePNG`, `ProfileStorage`, `UserLookPane`, `MiniMap`, and `MainMenuPane`: they are neighboring consumers/dependencies or unrelated wrappers, not the direct owner. |
| Formal C++ readiness | Active by-structure code gate, valid emitter route, current scores, support helper names, exact body behavior. | Populate first-draft C++ under [UID:0000K3]. Missing direct caller and original symbol spelling cap score below final audit but do not block source-shaped body emission. | Reject the current blanket "leave C++ blank" wording as stale for this target. It was reasonable before [UID:000200] and helper names were improved, but the target now has enough source-quality support for a first draft. |
| Score impact | Current target, raw audit, support names, first-draft C++ readiness. | Raise to `88/90` after implementation. | Do not raise to `95+`: original symbol spelling, direct reachability, full FPF header layout, and final wrapper-family source declarations are not fully proven. |

## Caller / Reachability Reanalysis

Confirmed positive facts:

- Direct rel32 scan for call/jump to `0x004d0730`: none.
- Little-endian absolute VA pattern for `0x004d0730` (`30 07 4d 00`): zero hits.
- `FPF` literal address pattern `78 b8 61 00`: two hits, at raw `0x000cfaab` / VA `0x004d06ab` and raw `0x000cfb50` / VA `0x004d0750`. These correspond to the ZPF wrapper inner `FPF` branch and this raw helper.
- Text pattern `FPF\0`: one hit at raw `0x0021a278` / VA `0x0061b878`.
- Text pattern `ZPF\0`: one hit at raw `0x0021a274` / VA `0x0061b874`.
- Direct rel32 scan for `0x00458560` finds the expected image-decode finalizer sites: `0x004d06f2` (`call`), `0x004d079a` (`jmp` tail from this target), `0x004d0991` (`call`), `0x004d0c42` (`call`), `0x004d0d7d` (`call`), and `0x004d0f29` (`call`).

Rejected reachability candidates from a broader byte-pattern scan:

- A branch-looking byte at `0x004d070d` is the second byte of the call immediate in `e8 7f 43 02 00`, not an aligned conditional branch into this target.
- A branch-looking byte at `0x004d07cf` is part of the `push 0x0061b87c` immediate for the neighboring `JPF` literal, not an aligned branch into this target.
- Dword-looking values at raw `0x000b17e8`, `0x000f6414`, and `0x000f6453` are rel32 call operands (`e8 84 07 0d 00`, `e8 78 07 0d 00`, and `e8 39 07 0d 00`), not VA/RVA/raw pointers to the helper.

Conclusion: the helper is real code but currently has no proven static caller or dispatch-table route. This should be documented as retained/unreferenced legacy support rather than ownership uncertainty.

## Ranked Ownership Analysis

### 1. [UID:0000K3] ImageLoaders

Evidence for:

- The body decodes an `FPF` image buffer into `EPFTileContext`, matching `ImageLoaders` responsibility for `ZPF`/`FPF`, `JPF`, BMP, raw JPEG, and PNG wrappers.
- It sits between `DecodeZpfFpfToTileContext` and `DecodeJpfImageToTileContext` with `0xcc` alignment on both sides.
- It shares the same `FPF` literal and inner FPF copy/finalization behavior as [UID:0002TJ].
- It calls only `EPFTileContext` buffer helpers, `_strncmp`, and `_memmove`; no ResourceLayout/ImageFrameTable-specific state is touched.
- [UID:0000K3] already has a valid source root path `NexusTK/render/` and autogen route to `auto-generated/NexusTK/render/ImageLoaders.cpp`.

Evidence against:

- No direct caller or function pointer reference to the raw helper start is known.
- Original source filename could theoretically have been `ImageDecode.cpp` or similar rather than the current `ImageLoaders.cpp` grouping.

Decision:

- Accept [UID:0000K3]. The missing caller affects reachability confidence, not source-family ownership.

### 2. [UID:00004I] EPFTileContext

Evidence for:

- The helper calls `EPFTileContext::ReleaseBuffers`, `AllocateWordPixels`, and `NormalizePostDecodePixels`.
- It writes into the `EPFTileContext` primary pixel buffer.

Evidence against:

- The function is not a receiver method. `EPFTileContext* destination` is stack argument `[ebp+0x0c]`, not implicit entry `ecx`.
- The function owns image-format parsing policy (`FPF` magic, version, header offsets, pixel-body offset), not generic tile-context behavior.
- Multiple image-loader wrappers call the `EPFTileContext` helpers without becoming `EPFTileContext` methods.

Decision:

- Reject as canonical owner. Keep `EPFTileContext` as dependency/support.

### 3. ResourceLayoutTable / ImageFrameTable / feature consumers

Evidence for:

- The address neighborhood around `0x004d0120-0x004d182f` contains ResourceLayout and ImageFrameTable code.
- Other image-wrapper children have feature callers such as profile/look/minimap/main-menu code.

Evidence against:

- This helper has no feature caller.
- It does not parse ResourceLayout rows, frame tables, DAT paths, image library records, or UI state.
- Address adjacency alone is weak and is contradicted by literal/behavior/callee clustering with the image decode wrappers.

Decision:

- Reject.

### 4. `CANONICAL_OWNER:NONE` / no-emitter

Evidence for:

- No direct caller/reachability route is known.

Evidence against:

- The owner family, source role, byte range, and destination behavior are all strong.
- [UID:0000K3] direct parent clears the source-owner gate and has valid generated output.
- The helper is reconstructable project source even if retained/unreferenced.

Decision:

- Reject. Keep both `CANONICAL_OWNER` and `EMITTER_UIDS` as `0000K3`.

## Open Question Closure

Current target open questions and recommended closure:

1. `Determine why IDA does not model this span as a function and whether an indirect caller exists.`
   - Close the first half as a tooling/reachability caveat: IDA most likely did not create a function because no recognized xref/entry reaches the start. The body is still source-authored code.
   - Keep only a narrow residual caveat: no confirmed static caller/indirect pointer exists in the current executable. Record the PE checks and false-positive rejections instead of leaving the broad question open.

2. `Confirm final source name and signature.`
   - Resolve to best-supported descriptive source name/signature: `void DecodeFpfToTileContext(const unsigned char* fpfBuffer, EPFTileContext* destination)`.
   - Preserve a caveat that exact original symbol spelling is not proven. This caps final-audit confidence but should not block first-draft C++.

3. `Confirm whether this was a local helper used only by table/dispatch code that IDA has not typed.`
   - Reject current table/dispatch hypothesis. No dispatch-table, absolute pointer, rel32 caller, or literal start reference is known.
   - Best inference: retained legacy/direct FPF helper linked with the ImageLoaders object and currently unreferenced by static analysis.

4. `Leave RECONSTRUCTION_CPP blank` / final-C++ blocker in current source placement text.
   - Treat as stale after this source-quality pass. Missing direct caller does not change the function body or source owner. The target is eligible and first-draft C++ can be populated with descriptive names.

## Best-Supported Names

| Raw/current name | Recommended source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x004d0730-0x004d07a3` / no IDA function | `DecodeFpfToTileContext` | Strong descriptive | Inferred from format, behavior, sibling naming. Original spelling unproven. |
| `[ebp+0x08]` | `fpfBuffer` | Very strong | Base pointer for magic/version/dimension/pixel-offset reads. |
| `[ebp+0x0c]` | `destination` / `EPFTileContext* destination` | Very strong | Passed in `ecx` to destination methods and used for `pixelData`/bounds. |
| `aFpf` / `0x0061b878` | `"FPF"` / `kFpfSignature` | Very strong | Single literal bytes and two wrapper references. |
| `sub_458500` | `EPFTileContext::ReleaseBuffers` | Strong | Already documented by EPFTileContext aggregate/class. |
| `sub_458430` | `EPFTileContext::AllocateWordPixels` | Strong | Allocates primary 16-bit pixels and zero-origin bounds. |
| `sub_458560` | `EPFTileContext::NormalizePostDecodePixels` | Very strong | [UID:000200] has formal C++ and source-quality update. |
| `[destination+0x04]` | `pixelData` | Strong | EPFTileContext documented layout. |
| `[destination+0x10..0x1c]` | `bounds.left/top/right/bottom` | Strong | EPFTileContext documented layout. |
| FPF header | `FpfHeader` or `FpfImageHeader` | Medium-high descriptive | Field offsets are proven; unknown gap fields should remain reserved/unnamed. |
| `[fpfBuffer+0x04]` | `version` | Strong | Compared to literal `1`. |
| `[fpfBuffer+0x10]` | `width` | Strong | Zero-extended and passed as first width arg to `AllocateWordPixels`. |
| `[fpfBuffer+0x12]` | `height` | Strong | Zero-extended and passed as second height arg. |
| `[fpfBuffer+0x18]` | `pixelDataOffset` | Strong | Added to base pointer before `_memmove`. |

## First-Draft C++ Recommendation

Populate the target's formal C++ block with this first-draft body:

```cpp
void DecodeFpfToTileContext(const unsigned char* fpfBuffer, EPFTileContext* destination)
{
    destination->ReleaseBuffers();

    if (*reinterpret_cast<const unsigned short*>(fpfBuffer + 0x04) != 1) {
        return;
    }

    if (strncmp(reinterpret_cast<const char*>(fpfBuffer), "FPF", 4) != 0) {
        return;
    }

    const int width = *reinterpret_cast<const unsigned short*>(fpfBuffer + 0x10);
    const int height = *reinterpret_cast<const unsigned short*>(fpfBuffer + 0x12);
    destination->AllocateWordPixels(width, height);

    const unsigned char* pixels =
        fpfBuffer + *reinterpret_cast<const unsigned int*>(fpfBuffer + 0x18);

    const int pixelCount =
        (destination->bounds.right - destination->bounds.left) *
        (destination->bounds.bottom - destination->bounds.top);

    memmove(destination->pixelData, pixels, pixelCount * sizeof(unsigned short));
    destination->NormalizePostDecodePixels();
}
```

Implementation notes:

- This code intentionally preserves the observed validation order: `ReleaseBuffers`, version check, signature check, allocation, copy, normalization.
- It preserves the binary's bounds-derived pixel count instead of simplifying to `width * height`.
- The `reinterpret_cast` raw-offset style is acceptable for the target-only first draft because no project-wide `FpfHeader` type is currently documented. If a support `FpfHeader`/`FpfImageHeader` declaration is later created, the body can be rewritten to use field names without changing behavior.
- The code should include normal C/C++ headers or surrounding declarations at the `ImageLoaders.cpp` support layer (`strncmp`, `memmove`, `EPFTileContext`) when the broader file emits real source.

Do not include a return value, null checks, extra format validation, allocation failure handling, or a caller/registration table in this target's C++ block; none of those behaviors exist in the binary range.

## Score Recommendation

Recommended after implementation:

| Metric | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| Completion | 85 | 88 | Add raw PE hash/offset evidence, instruction-level interpretation, source-quality helper/field/type names, reachability false-positive rejection, open-question closure, and first-draft C++. |
| Confidence | 87 | 90 | Raw bytes, padding, literal island, finalizer rel32 control, support-helper naming, and owner route are now independently validated. Confidence remains below final-audit range because original source spelling, full FPF header layout, and a real caller route are still unproven. |

Do not raise to `95+`. The page will still depend on descriptive names and a retained/unreferenced reachability conclusion.

## Supervisor-Owned Coverage Row Text

Do not edit `by-memory/-coverage-report.md` directly as B015. If the supervisor accepts this report and the target implementation is applied, replace the current [UID:0002TK] row with exactly:

```text
        - [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) 0x004d0730-0x004d07a3 | raw-helper | DecodeFpfToTileContext : reconstructable : 88% : very strong : B015 2026-06-19 source-quality reanalysis confirms the exact 0x73-byte raw helper at PE raw offset `0xcfb30` (SHA1 `1a7da272dfaebc6c0e5b5f7b3a4d0559e4f9ff94`), thirteen-byte `0xcc` padding before and after, version-1 and `FPF` literal validation, `EPFTileContext::ReleaseBuffers`, `AllocateWordPixels`, `pixelData`/bounds byte-count, `_memmove`, and tail `NormalizePostDecodePixels` flow; no direct rel32 call/jump or absolute pointer to the helper start is present, branch/pointer-looking range hits are rejected as operand bytes, and the best source placement remains [UID:0000K3] `ImageLoaders` with first-draft C++ readiness.
```

If the supervisor rejects first-draft C++ population, keep the current coverage row and scores rather than applying only the score/row uplift.

## Target / Support Implementation Checklist

Target doc:

- Update [UID:0002TK] metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter/reconstructable fields unchanged.
- Populate the formal `RECONSTRUCTION_CPP CODE` block with the first-draft C++ body above.
- Update `Status` to say the helper is source-authored raw/unmodeled code with a descriptive, not proven-original, source-facing name.
- Add or update raw PE evidence: executable SHA256, raw offset `0xcfb30`, body SHA1 `1a7da272dfaebc6c0e5b5f7b3a4d0559e4f9ff94`, pre/post `0xcc` padding, and literal island `ZPF`/`FPF`/`JPF`.
- Replace raw placeholder callee wording with `EPFTileContext::ReleaseBuffers`, `EPFTileContext::AllocateWordPixels`, `EPFTileContext::NormalizePostDecodePixels`, `pixelData`, and `bounds`.
- Add a source-quality section that records the best-supported `FpfHeader` field map and rejected unknown/reserved field interpretations.
- Replace the current open questions with the closure decisions in this report.
- Update the score rationale to explain why `88/90` is justified and why `95+` is not.
- Add a change-log entry for B015 2026-06-19 source-quality reanalysis.

Support docs:

- [UID:000175] `ImageDecodeWrappers`: update the raw FPF row and ownership/C++ wording so it no longer says the raw FPF child is blocked from first-draft C++ solely because of the missing caller/function-object evidence. Keep the aggregate's own C++ blank unless a separate aggregate-source pass decides otherwise.
- [UID:0000K3] `ImageLoaders`: update the [UID:0002TK] proposed-contents note to say the raw helper now has raw PE revalidation and first-draft C++ readiness, while its direct caller route remains absent.
- [UID:00004I] / [UID:0000XY] `EPFTileContext`: no required change. Existing docs already supply `ReleaseBuffers`, `AllocateWordPixels`, `NormalizePostDecodePixels`, `pixelData`, and bounds names.
- `by-memory/-coverage-report.md`: supervisor-owned replacement row above after implementation.
- `auto-generated/*` and `project-level/*`: do not edit manually. Run validator with `--apply` on changed by-* docs so generated coverage/source/stats refresh through the normal tool.

Recommended validation commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002TK-DecodeFpfToTileContext-source-quality-removed.md](0002TK-DecodeFpfToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row directly, also validate the coverage report:

> Executable block R002 was removed from this report and preserved verbatim in [0002TK-DecodeFpfToTileContext-source-quality-removed.md](0002TK-DecodeFpfToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Validator Results

Read-only validation baseline run during this report:

> Executable block R003 was removed from this report and preserved verbatim in [0002TK-DecodeFpfToTileContext-source-quality-removed.md](0002TK-DecodeFpfToTileContext-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `apply: False`
- Scanned markdown files: `1`
- `ok: 1`
- Target-specific result: `ok 0002TK by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md UID header exists`
- No files were modified. The long dry-run autogen warnings are existing generated-output state, not target validation failures.

## Changed Files

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B015\research\0002TK-DecodeFpfToTileContext-source-quality.md`

Modified:

- None.

Renamed:

- None.

Moved to executed:

- None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000004165","destination_path":"executed-b-agent-research/B015/0002TK-DecodeFpfToTileContext-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:37","uid":"0002TK"} -->
<!-- {"agent":"B015","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002TK-DecodeFpfToTileContext-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B015/0002TK-DecodeFpfToTileContext-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002TK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
