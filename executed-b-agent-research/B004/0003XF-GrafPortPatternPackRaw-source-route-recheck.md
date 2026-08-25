** TARGET-REPORT-UID:0003XF **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003XF GrafPortPatternPackRaw Source-Route Recheck

## Finalized Report / Current Recommendation

- Current recommendation: raise [UID:0003XF] `0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw` from `84/88` to `85/88`, keep `CANONICAL_OWNER:NONE`, keep `RECONSTRUCTABLE:TRUE`, keep blank `EMITTER_UIDS`, and keep formal C++ blank.
- Final disposition: retained source-shaped raw helper evidence, no-owner/non-emitting, not ignored, not non-reconstructable, and not safe for a GrafPort/Surface/NumericString/FontImageLib/EPFTileContext/LineClip emitter route.
- Strongest source-family inference: GrafPort glyph/text support. The current pass adds direct local PE evidence that live GrafPort text-run helpers build the same six-byte two-color pattern inline before calling `GrafPortDrawGlyph`.
- Gate outcome: the target can clear the documentation gate at `85/88` because exact boundary, bytes, padding, behavior, source-family, generated-state, and rejected-owner/no-route evidence are now report-level complete. It still cannot receive an owner, emitter, or C++ because liveness/source-use remains unproven.
- Coverage/support action: Rule 26 incorporation is required. Exact target-page, support-doc, and coverage-row replacement text is included below; no by-* or coverage files were edited by B004.

## Target

- Target UID: `0003XF`.
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0003XF-GrafPortPatternPackRaw-source-route-recheck.md`.
- Assignment id: `B004-goal2-grafport-pattern-pack-raw-source-route-recheck-0003XF-20260618`.
- Current metadata: `84/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, blank formal C++.
- Recommended metadata: `85/88`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank emitters, blank formal C++.
- Active instruction note: Agent-B004 `goal.md` and `notes.md` were read at the start of this pass but still referenced the previous `0001AZ` assignment. I treated the supervisor assignment in the current user message as the active override.
- IDA MCP status: `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded : False`; this pass used local PE bytes plus existing IDA-backed docs and executed B-agent reports as leads.

## Executive Recommendation

[UID:0003XF] is a real source-shaped helper body, not padding and not compiler glue. It is exactly a three-argument `ret 0x0c` byte packer that writes a six-byte pattern to an output pointer. The best source-facing name remains `PackTwoColorSixPixelPattern`, and the strongest semantic source family is GrafPort glyph/text drawing.

The new evidence in this pass is that the live GrafPort text helpers at `0x004bab20` and `0x004bab70` build the same final byte pattern inline from `m_textColor` and `m_textBackColor` before calling [UID:00016I] `GrafPortDrawGlyph`. With `firstByte = m_textColor` and `secondByte = m_textBackColor`, [UID:0003XF] writes:

```text
{ secondByte, firstByte, secondByte, firstByte, firstByte, secondByte }
```

The live inline pattern is:

```text
{ m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor }
```

That validates the helper interpretation and rejects generic line, surface, font-library, or compiler-artifact descriptions. It still does not prove an emitter. The live GrafPort functions do not call `0x004bb5b0`; they duplicate the store pattern inline and call `0x004bb5e0` directly. Emitting an unused static helper in GrafPort would make the reconstructed source more certain than the binary evidence supports, and it could require artificial retention tricks if the compiler/linker would otherwise discard it.

Therefore the target should move to `85/88` as a completed no-owner/non-emitting raw-helper audit, with blank formal C++. The remaining blocker is not behavior, boundary, source family, or rejected-owner analysis; it is specifically source-use/liveness. The concrete evidence that would change the no-owner/no-emitter recommendation is one of: a direct caller, a valid rel32/short-branch route, a callback/vtable/pointer-table entry, an unwind/registration/source-use route, or a source-level sibling cluster proving that the original source emitted this helper intentionally even though the visible callers inline the pattern.

## Raw Boundary, Bytes, Padding, And File Offset

Local PE input:

- Executable: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- `.text`: RVA `0x00001000`, virtual size `0x0020b4ac`, raw file pointer `0x00000400`, raw size `0x0020b600`.
- Target VA: `0x004bb5b0`.
- Target RVA: `0x000bb5b0`.
- Target raw file offset: `0x000ba9b0`.
- File offset formula: `0x00000400 + ((0x004bb5b0 - 0x00400000) - 0x00001000) = 0x000ba9b0`.

Raw ranges:

| Range | Meaning | Length | Raw offset | SHA-256 |
| --- | --- | ---: | ---: | --- |
| `0x004bb5a5-0x004bb5b0` | pre-target padding | `0x0b` / 11 bytes | `0x000ba9a5` | `3682c0a62515050101266cc639bf81f5d8c5395f49e7da93fcc22603018e0943` |
| `0x004bb5b0-0x004bb5d1` | target body | `0x21` / 33 bytes | `0x000ba9b0` | `bba67603719aefc29d4a587922384e46f62e552ffbc24703451d25ea87dbeb4b` |
| `0x004bb5d1-0x004bb5e0` | post-target padding | `0x0f` / 15 bytes | `0x000ba9d1` | `54cc9dd9593316e80ccaf5d10856e6502a0d75f20473a92fa01d63228ef1624c` |
| `0x004bb5a5-0x004bb5e0` | full padding/body envelope | `0x3b` / 59 bytes | `0x000ba9a5` | `9592833a02309fceecf90b3b45a83c26dbb0cb05cf8d69008cb8ddd3b85c3758` |

Body bytes:

```text
004bb5b0: 55 8b ec 8b 55 10 8a 4d 0c 8a 45 08 88 0a 88 4a
004bb5c0: 05 88 42 04 88 42 01 88 4a 02 88 42 03 5d c2 0c
004bb5d0: 00
```

Padding bytes:

```text
004bb5a5: cc cc cc cc cc cc cc cc cc cc cc
004bb5d1: cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
```

Capstone disassembly:

```asm
004bb5b0: 55                      push ebp
004bb5b1: 8b ec                   mov ebp, esp
004bb5b3: 8b 55 10                mov edx, dword ptr [ebp + 0x10]
004bb5b6: 8a 4d 0c                mov cl, byte ptr [ebp + 0xc]
004bb5b9: 8a 45 08                mov al, byte ptr [ebp + 8]
004bb5bc: 88 0a                   mov byte ptr [edx], cl
004bb5be: 88 4a 05                mov byte ptr [edx + 5], cl
004bb5c1: 88 42 04                mov byte ptr [edx + 4], al
004bb5c4: 88 42 01                mov byte ptr [edx + 1], al
004bb5c7: 88 4a 02                mov byte ptr [edx + 2], cl
004bb5ca: 88 42 03                mov byte ptr [edx + 3], al
004bb5cd: 5d                      pop ebp
004bb5ce: c2 0c 00                ret 0xc
```

Instruction-shape conclusion:

- `arg1` at `[ebp+8]` is loaded into `al`.
- `arg2` at `[ebp+0x0c]` is loaded into `cl`.
- `arg3` at `[ebp+0x10]` is loaded into `edx` as the output pointer.
- `ret 0x0c` consumes exactly three 32-bit stack arguments.
- Output order is `out[0] = arg2`, `out[1] = arg1`, `out[2] = arg2`, `out[3] = arg1`, `out[4] = arg1`, `out[5] = arg2`.

Best descriptive signature, still not for formal C++ emission:

```cpp
static void PackTwoColorSixPixelPattern(
    unsigned char firstByte,
    unsigned char secondByte,
    unsigned char *outPattern);
```

## Raw-Start Status And Reachability

IDA MCP was unavailable in this pass. Existing IDA-backed target and support docs report:

- `lookup_funcs` finds no IDA function at `0x004bb5b0`.
- [UID:00016H] `LineClipHelpers` ends at `0x004bb5a5`.
- [UID:00016I] `GrafPortDrawGlyph` starts at `0x004bb5e0`.
- `xrefs_to 0x004bb5b0` reports zero direct references.
- Prior IDA/PE rechecks found no raw-start route, no caller, and no pointer-table entry.

Fresh local PE route scans:

| Check | Result |
| --- | --- |
| Exact target body pattern in full file | 1 hit, at `0x004bb5b0` |
| Load/store subpattern `0x004bb5b9-0x004bb5cc` in full file | 1 hit, at `0x004bb5b9` |
| VA dwords for every address in `0x004bb5b0-0x004bb5d1` | 0 hits |
| RVA dwords for every address in `0x004bb5b0-0x004bb5d1` | 0 hits |
| Raw-offset dwords for every byte in `0x004bb5b0-0x004bb5d1` | 0 hits |
| `E8`/`E9` rel32 target into `0x004bb5b0-0x004bb5d1` | 0 hits |
| `0F 80-8F` long conditional branch target into `0x004bb5b0-0x004bb5d1` | 0 hits |
| Broad short-branch byte scan into helper range | 1 candidate at `0x004bb604`, rejected as false positive |

The broad short-branch candidate:

```text
004bb604 byte 7d, computed target 0x004bb5b2
context: 45 b0 8d 4d c4 89 7d ac e8 55 c4 f9 ff 80 7f 71
```

This is not an instruction-boundary branch. In `GrafPortDrawGlyph`, `0x004bb604` is the ModRM byte in:

```asm
004bb600: 8d 4d c4                lea ecx, [ebp - 0x3c]
004bb603: 89 7d ac                mov dword ptr [ebp - 0x54], edi
004bb606: e8 55 c4 f9 ff          call 0x458a60
```

Positive controls from the same PE scan:

- `0x004bb2e0` has two direct rel32 call hits at `0x004bbc81` and `0x004c0b71`.
- `0x004bb5e0` has two direct rel32 call hits at `0x004bab57` and `0x004bac8a`.
- `0x004b99f0` has three direct rel32 call hits at `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- Callback target VA dword `0x004bc090` has two loaded `.text` hits at `0x00558741` and `0x00558b9a`.
- Callback target VA dword `0x004c0f80` has two loaded `.text` hits at `0x0055882f` and `0x00558eb6`.
- Callback-table slot dword `0x0069b3e8` has 114 loaded `.text` hits.

Reachability conclusion: the scan can detect neighboring live direct calls and callback target literals, but it finds no equivalent entry route for `0x004bb5b0`. No direct, indirect, pointer-table, vtable, callback-table, rel32, or validated short-branch route is currently defensible.

## Live Inline Pattern Validation

The target's output order exactly matches the live pattern built by GrafPort text helpers when `firstByte = m_textColor` and `secondByte = m_textBackColor`.

[UID:00016C] `DrawGlyphWithTextColors` at `0x004bab20` stores:

```asm
004bab30: 8b 41 7c                mov eax, dword ptr [ecx + 0x7c]
004bab33: 8b 91 80 00 00 00       mov edx, dword ptr [ecx + 0x80]
004bab39: 88 45 f8                mov byte ptr [ebp - 8], al
004bab3c: 88 45 f5                mov byte ptr [ebp - 0xb], al
004bab3f: 88 45 f7                mov byte ptr [ebp - 9], al
004bab42: 8d 45 f4                lea eax, [ebp - 0xc]
004bab45: 50                      push eax
004bab46: 6a 00                   push 0
004bab48: ff 75 0c                push dword ptr [ebp + 0xc]
004bab4b: 88 55 f4                mov byte ptr [ebp - 0xc], dl
004bab4e: ff 75 08                push dword ptr [ebp + 8]
004bab51: 88 55 f9                mov byte ptr [ebp - 7], dl
004bab54: 88 55 f6                mov byte ptr [ebp - 0xa], dl
004bab57: e8 84 0a 00 00          call 0x4bb5e0
```

Final local buffer `[ebp-0x0c]..[ebp-0x07]`:

```text
{ m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor }
```

[UID:00016C] `DrawWideText` at `0x004bab70` stores:

```asm
004babb6: 8b 87 80 00 00 00       mov eax, dword ptr [edi + 0x80]
004babbc: 8b 4f 7c                mov ecx, dword ptr [edi + 0x7c]
004babbf: 88 45 e8                mov byte ptr [ebp - 0x18], al
004babc2: 88 45 ed                mov byte ptr [ebp - 0x13], al
004babc5: 88 45 ea                mov byte ptr [ebp - 0x16], al
004babc8: 8a 87 88 00 00 00       mov al, byte ptr [edi + 0x88]
004babce: 88 4d ec                mov byte ptr [ebp - 0x14], cl
004babd1: 88 4d e9                mov byte ptr [ebp - 0x17], cl
004babd4: 88 4d eb                mov byte ptr [ebp - 0x15], cl
```

Final local buffer `[ebp-0x18]..[ebp-0x13]`:

```text
{ m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor }
```

This validates the `PackTwoColorSixPixelPattern` interpretation and the GrafPort glyph/text source-family inference. It also explains why the target remains non-emitting: the two known live uses build the pattern inline and do not call `0x004bb5b0`.

## Generated / Unresolved / Source-Route Recheck

Generated and project-state checks:

- `project-level/-auto-completion-stats.md` lists `0003XF` twice as `84/88`, average `86.0`, pointing to `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`. That row is stale after this recheck and should become `85/88` after supervisor incorporation.
- `auto-generated/-ag-memory-coverage.md` lists [UID:0003XF] as `no-owner`, `CANONICAL_OWNER:NONE`, blank generated source path, and no emitted source. This validates that the current generator does not emit a hidden source body for this raw helper.
- Narrow generated/source-output searches under `source-3/simroot_v2`, `project-documentation/auto-generated/NexusTK`, and `project-documentation/project-level` found no generated source occurrence of `004bb5b0`, `004BB5B0`, `GrafPortPatternPackRaw`, or `PackTwoColorSixPixelPattern`; only project-level stats mention the UID. A full `source-3` tree search timed out after about 14 seconds, so it is recorded as a failed broad check rather than positive evidence.
- Existing by-file/by-class support docs already carry the no-owner/no-emitter conclusion for [UID:0003XF], but they do not yet include the current raw offset/hash and inline GrafPort pattern validation. Those are valid Rule 26 details and must be incorporated, not treated as optional.

Source-route implication:

- The generated state supports no hidden emitter route.
- The target can be raised to `85` as a no-owner documentation state because its only remaining blocker is now narrow and concrete: no source-use route to the raw body.
- A non-emitting canonical owner is still rejected. Setting `CANONICAL_OWNER:00005V` or `0000JR` while keeping emitters blank would imply a proven original source placement. The evidence proves source family, not source ownership. `NONE` is therefore more accurate than a non-emitting GrafPort owner.
- `RECONSTRUCTABLE:FALSE`/ignored is also rejected. The body is valid project code with a live semantic match in GrafPort text rendering; it is not padding, CRT, or compiler-generated glue.

## Heuristic / Inference Reanalysis And Validation

### Helper name and role

- Raw-byte fact: [UID:0003XF] has one output pointer and two byte inputs; it writes six bytes in a fixed order and returns with `ret 0x0c`.
- New validation: live GrafPort text helpers build the same final six-byte text/back-color pattern inline.
- Best descriptive name: `PackTwoColorSixPixelPattern`.
- Status: descriptive/inferred, not proven original.
- Rejected names: `GrafPortDrawGlyph` child, line clip helper, pixel format packer, RGB555/RGB565 channel packer, callback dispatcher, and compiler thunk.
- Score impact: behavior confidence is now strong enough for a `85` completion audit when combined with the exact boundary/padding and no-route proof. It still does not prove a source route, so it blocks owner, emitter, and C++ rather than blocking all `85/85+` documentation state.

### Three-argument calling convention

- Raw-byte fact: `[ebp+8]` and `[ebp+0x0c]` are byte inputs; `[ebp+0x10]` is the output pointer; `ret 0x0c` consumes three stack arguments.
- Best signature: `static void PackTwoColorSixPixelPattern(unsigned char firstByte, unsigned char secondByte, unsigned char *outPattern)`.
- Rejected alternatives: `thiscall` method and two-argument helper are contradicted by `ret 0x0c` and absence of `ecx` receiver use.
- Score impact: signature is source-quality descriptive, but not formal-C++ ready because no emitter route exists.

### Raw start and liveness

- Existing IDA-backed docs: no IDA function object at `0x004bb5b0`; zero xrefs/callers; neighboring live function starts are known.
- Fresh PE facts: zero VA/RVA/raw-offset dword hits into every byte of the helper range; zero rel32 call/jump/jcc hits into the helper range; broad short-branch candidate is a non-instruction ModRM byte.
- Positive controls: live calls to `0x004bb2e0`, `0x004bb5e0`, and `0x004b99f0`; callback target dwords for `0x004bc090` and `0x004c0f80`; 114 dword hits for `0x0069b3e8`.
- Decision: no direct or indirect reachability route is defensible.
- Score impact: this is the decisive blocker to owner, emitter, formal C++, and completion above `85`; it no longer blocks the `85/88` no-owner documentation state.

### GrafPort / GrafPortDrawGlyph source-family candidate

- Evidence for: immediate adjacency to [UID:00016I] `GrafPortDrawGlyph`; live `DrawGlyphWithTextColors` and `DrawWideText` construct the exact same pattern; `GrafPortDrawGlyph` receives that pattern pointer as an argument at both live call sites.
- Evidence against: neither `GrafPortDrawGlyph` nor text-run callers call `0x004bb5b0`; the known live code inlines the stores; no pointer/table route exists.
- Best inference: GrafPort glyph/text support is the strongest source-family direction and the best forced owner if a future route appears.
- Final decision: still not enough for `CANONICAL_OWNER:00005V`, `0000JR`, or `EMITTER_UIDS`.

### Surface candidate

- Evidence for: two-color byte patterns and glyph blits ultimately feed Surface render callbacks; Surface owns callback-table context and low-level render callback families.
- Evidence against: [UID:0003XF] has no `Surface` receiver, no palette, no rectangle, no pixel stride, no callback slot, and no table reference. In contrast, Surface-owned callback targets are visible through callback target dwords as positive controls.
- Decision: Surface is a dependency context only, weaker than GrafPort glyph/text and not an owner/emitter.

### NumericString candidate

- Evidence for: another glyph-related split child [UID:0003XD] sits nearby.
- Evidence against: [UID:0003XD] has a live NumericString caller, fixed `9x11` constants, `9X11FONT.BIN` resource relationship, and owner [UID:0000M2]; [UID:0003XF] has none of those. NumericString rendering has no edge to `0x004bb5b0`.
- Decision: reject NumericString owner/emitter.

### FontImageLib candidate

- Evidence for: GrafPort glyph/text rendering depends on FontImageLib metrics/decode.
- Evidence against: [UID:0003XF] has no font slot, glyph index, `g_pFontImageLib` read, `BARAM%02d.EFT` resource, metrics call, decode call, or FontImageLib layout access. FontImageLib is a dependency of `GrafPortDrawGlyph`, not the owner of this standalone pattern body.
- Decision: reject FontImageLib owner/emitter.

### EPFTileContext candidate

- Evidence for: `GrafPortDrawGlyph` and FontImageLib use EPFTileContext-style decoded tile records.
- Evidence against: [UID:0003XF] has no EPFTileContext fields, bounds, stride, pixel pointer, mode, mask, allocator/free, or context initializer call. It only writes a six-byte color pattern.
- Decision: reject EPFTileContext owner/emitter.

### LineClip candidate

- Evidence for: [UID:0003XF] sits immediately after [UID:00016H] `LineClipHelpers`.
- Evidence against: line clipping is Liang-Barsky geometry over rectangles and endpoints; [UID:0003XF] does no math, no endpoint mutation, no rectangle access, and no call to `0x004bb520`. The eleven bytes before [UID:0003XF] are `0xcc` padding after the line-clip range.
- Decision: reject LineClip owner/emitter.

### New file / static helper candidate

- Evidence for: a file-local static helper in `GrafPort.cpp` is plausible because the live text helpers build the same byte sequence inline, and unreferenced source functions can remain in non-function-level-linked builds.
- Evidence against: no caller, no pointer, no sibling cluster, no symbol/string/type boundary, and no source-use evidence proves the original file intentionally retained an out-of-line helper. Emitting an unused helper could add a source function that no reconstructed code references and may not survive compilation/linking without artificial retention.
- Decision: do not create a new file and do not assign an emitter. The best forced context remains GrafPort, but it is not safe enough to act on.

### Compiler/linker artifact candidate

- Evidence for: the body is orphaned and unreferenced, which can happen to retained source artifacts.
- Evidence against: the body is not padding, a thunk, an adjustor, a scalar deleting destructor, exception/unwind glue, RTTI glue, security-cookie helper, CRT wrapper, or import stub. It is ordinary source-shaped byte stores.
- Decision: classify as retained source-shaped raw helper evidence, not compiler-generated glue and not ignored.

### Old B002/B003 claim validation

- Validated: exact boundary `0x004bb5b0-0x004bb5d1`, pre/post padding, no IDA function/xrefs/callers from existing docs, zero PE pointer/rel32 route, rejected short-branch candidate, no owner/emitter, blank C++, and GrafPort glyph/text as best forced family.
- Refined: the current pass independently dumps the bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, gives file offset and hashes, scans every VA/RVA/raw-offset dword into the helper range, and validates the six-byte pattern against live inline GrafPort text-helper code.
- Superseded: any wording that leaves `PackTwoColorSixPixelPattern` merely as a visual guess is now too weak. The pattern is byte-validated against live GrafPort text-color setup.

## Ranked Ownership / Emitter Analysis

### 1. GrafPort glyph/text support - best source family, rejected for metadata assignment

- Candidate UIDs: [UID:00005V] `GrafPort` class and [UID:0000JR] `GrafPort` file.
- Evidence for: adjacency to `GrafPortDrawGlyph`; live text helpers build the same pattern from `m_textColor`/`m_textBackColor`; [UID:00016I] consumes the pattern pointer.
- Evidence against: no call/pointer/branch/table route to [UID:0003XF]; visible live callers inline the same logic; no receiver or class state inside [UID:0003XF].
- Decision: source family only. Do not set `CANONICAL_OWNER` or `EMITTER_UIDS`.

### 2. GrafPortDrawGlyph child code - rejected

- Evidence for: immediate successor and semantic dependency.
- Evidence against: `GrafPortDrawGlyph` starts at `0x004bb5e0`; target is separated by fifteen bytes of padding; successor has its own direct callers at `0x004bab57` and `0x004bac8a`; no branch from successor to target exists.
- Decision: do not merge into [UID:00016I].

### 3. Surface - rejected

- Evidence for: render callback ecosystem and eventual blit/fill context.
- Evidence against: no callback slot, Surface receiver, palette, rect, stride, or table route. Surface callback target controls are detectable but do not include `0x004bb5b0`.
- Decision: dependency context only.

### 4. NumericStringControlPane - rejected

- Evidence for: nearby glyph helper [UID:0003XD].
- Evidence against: no fixed `9x11` numeric font constants, no NumericString caller, no `9X11FONT.BIN` resource relationship.
- Decision: no ownership/emitter route.

### 5. FontImageLib - rejected

- Evidence for: text rendering depends on FontImageLib.
- Evidence against: target has no FontImageLib data, globals, resources, metrics, or decode behavior.
- Decision: dependency of live glyph drawing only.

### 6. EPFTileContext - rejected

- Evidence for: glyph blit paths use tile contexts.
- Evidence against: target has no tile-context structure access or lifecycle behavior.
- Decision: no ownership/emitter route.

### 7. LineClip - rejected

- Evidence for: preceding physical neighbor.
- Evidence against: behavior mismatch and padding separation.
- Decision: no ownership/emitter route.

### 8. New static helper/source file - rejected for current metadata

- Evidence for: plausible unreferenced file-local helper.
- Evidence against: no route or sibling cluster proves a source file boundary; creating a new source owner would overfit one orphan.
- Decision: do not create a new source file or emitter.

### 9. Ignored/non-reconstructable - rejected

- Evidence for: no liveness.
- Evidence against: valid code body, unique source-shaped byte stores, live semantic match in GrafPort text code.
- Decision: keep `RECONSTRUCTABLE:TRUE`, but no-owner and non-emitting.

## First-Draft C++ Recommendation

Do not populate [UID:0003XF] formal `RECONSTRUCTION_CPP`.

Illustrative source model only:

```cpp
static void PackTwoColorSixPixelPattern(unsigned char firstByte,
                                        unsigned char secondByte,
                                        unsigned char *outPattern)
{
    outPattern[0] = secondByte;
    outPattern[1] = firstByte;
    outPattern[2] = secondByte;
    outPattern[3] = firstByte;
    outPattern[4] = firstByte;
    outPattern[5] = secondByte;
}
```

No-code proof:

- no modeled IDA function at raw start in existing IDA-backed docs;
- no direct xrefs/callers in existing IDA-backed docs;
- no VA/RVA/raw-offset pointer into any byte of the helper range in fresh PE scans;
- no rel32 call/jump/jcc route into the helper range;
- no valid short-branch route after false-positive review;
- no vtable/callback/pointer-table route;
- the known live GrafPort text helpers inline the same pattern and call `GrafPortDrawGlyph` directly.

## Score And Metadata Recommendation

Recommended metadata:

```text
*** UID:0003XF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Why completion should rise to `85`:

- The target now has exact local PE boundary, bytes, file offset, body hash, pre/post padding hashes, instruction shape, unique body/subpattern checks, whole-range VA/RVA/raw-offset pointer scans, rel32 and broad short-branch route checks, positive controls, generated-state checks, source-family ranking, and no-code proof.
- The behavior is no longer merely a guess: live GrafPort text helpers build the identical six-byte text/back-color pattern inline before calling `GrafPortDrawGlyph`.
- The only remaining blocker is not documentation incompleteness; it is absence of a source-use route. That blocker prevents ownership/emission/C++ but does not justify leaving the documentation completion below `85`.

Why confidence stays `88`:

- Confidence in the byte behavior and GrafPort glyph/text family is higher after the inline-pattern validation.
- Confidence is still capped below `90` by missing liveness, offline IDA MCP for a fresh live IDB query, and no source-retention proof for an unreferenced helper.

Metadata alternatives rejected:

- `CANONICAL_OWNER:00005V` or `0000JR`: rejected because source family is not source route.
- `EMITTER_UIDS:00005V` or `0000JR`: rejected because no emitted code should be added for an unreferenced helper.
- `RECONSTRUCTABLE:FALSE` or ignored: rejected because the target is valid source-shaped project code and semantically matches live GrafPort text rendering.

## Supervisor Action Plan

These changes are required for Rule 26 incorporation. B004 did not edit these by-* or coverage files.

### Target Page

In [UID:0003XF] `by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md`, replace the header score line:

```text
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep these header lines unchanged:

```text
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the [UID:0003XF] `## Score Rationale` section with:

```markdown
Recommended score is `85/88`.

Completion rises to `85` because the page now has exact PE-derived body bytes, raw file offset, pre/post padding hashes, instruction-level signature, three-argument `ret 0x0c` calling convention, validated output order, live GrafPort text-helper inline-pattern match, generated-state/no-source-output checks, whole-range VA/RVA/raw-offset pointer scans, rel32 and short-branch route checks with positive controls, source-family ranking, rejected owner alternatives, and target-specific no-code proof.

Confidence remains `88` because exact behavior and GrafPort glyph/text family are strong, but liveness/source-use is still unproven. Existing IDA-backed docs and fresh PE scans still find no modeled function, no direct xrefs/callers, no pointer-table/vtable/callback route, and no valid branch route to `0x004bb5b0`. This blocks owner/emitter/C++ but no longer blocks an `85/85+` documentation state.
```

Add this to the [UID:0003XF] `## Evidence` section:

```markdown
- 2026-06-18 B004 source-route recheck: local PE scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` maps `0x004bb5b0` to RVA `0x000bb5b0` and raw file offset `0x000ba9b0`; body bytes hash to `bba67603719aefc29d4a587922384e46f62e552ffbc24703451d25ea87dbeb4b`, with eleven `0xcc` bytes at `0x004bb5a5-0x004bb5b0` and fifteen `0xcc` bytes at `0x004bb5d1-0x004bb5e0`.
- The helper's output order is now validated against live GrafPort text helpers: `DrawGlyphWithTextColors` at `0x004bab20` and `DrawWideText` at `0x004bab70` build the same final six-byte pattern `{m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor}` inline before calling [UID:00016I][GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md).
- Fresh scans find no VA/RVA/raw-offset dword into any byte of `0x004bb5b0-0x004bb5d1`, no `E8`/`E9` rel32 route, no `0F 80-8F` long conditional branch route, and no callback/vtable/pointer-table route. Positive controls find live calls to `0x004bb2e0`, `0x004bb5e0`, and `0x004b99f0`, callback target dwords for `0x004bc090` and `0x004c0f80`, and 114 loaded `.text` dword hits for callback-table slot `0x0069b3e8`.
- The broad short-branch byte candidate at `0x004bb604` is rejected as a ModRM byte in `mov dword ptr [ebp-0x54], edi` inside [UID:00016I][GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md), not an instruction-boundary branch into this helper.
- Generated-state recheck: `auto-generated/-ag-memory-coverage.md` lists [UID:0003XF] as `no-owner` with blank generated source path; narrowed generated/source-output searches found no `004bb5b0`, `004BB5B0`, `GrafPortPatternPackRaw`, or `PackTwoColorSixPixelPattern` source-output occurrence.
```

Replace the [UID:0003XF] `## Ownership Decision` section with:

```markdown
No canonical owner or emitter is safe now. GrafPort glyph/text support is the best source-family inference because live `DrawGlyphWithTextColors` and `DrawWideText` build the same six-byte text/back-color pattern inline before calling `GrafPortDrawGlyph`, but source family is not source route. Keep `CANONICAL_OWNER:NONE` and blank `EMITTER_UIDS`.

Rejected owner alternatives:

- [UID:00005V][GrafPort](by-class/GrafPort.md) / [UID:0000JR][GrafPort](by-file/GrafPort.md): best forced family, but no call, pointer-table, vtable, callback, or branch route reaches `0x004bb5b0`; visible GrafPort text helpers inline the pattern instead.
- [UID:00016I][GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md): successor function has live callers and does not branch backward to the raw island.
- [UID:0000OC][Surface](by-file/Surface.md): render callback context only; the body has no Surface receiver, no callback slot, no palette, no rectangle, and no stride/pixel-buffer access.
- [UID:0000M2][NumericStringControlPane](by-file/NumericStringControlPane.md): neighboring glyph helper [UID:0003XD] has a live NumericString caller and `9X11FONT.BIN` constants; this helper has no NumericString caller or numeric-glyph constants.
- [UID:0000JH][FontImageLib](by-file/FontImageLib.md): no font slot, `g_pFontImageLib`, `BARAM%02d.EFT`, metrics, or decode behavior.
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md): no tile-context layout, pixel pointer, stride, bounds, mode, or mask behavior.
- [UID:00016H][LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md): preceding physical neighbor only; line clipping is geometry, while this body only packs bytes.
- New static helper/source file: plausible only as an unreferenced source artifact, but no source-use route or sibling cluster proves original retention. Do not create a new owner solely for this orphan.
- Ignored/non-reconstructable: rejected because the bytes decode as valid project helper code and semantically match live GrafPort text rendering.
```

Add this `## First-Draft C++ / No-Code Proof` section or replace the existing C++ note with it:

````markdown
Do not populate formal `RECONSTRUCTION_CPP`.

Illustrative source model only:

```cpp
static void PackTwoColorSixPixelPattern(unsigned char firstByte,
                                        unsigned char secondByte,
                                        unsigned char *outPattern)
{
    outPattern[0] = secondByte;
    outPattern[1] = firstByte;
    outPattern[2] = secondByte;
    outPattern[3] = firstByte;
    outPattern[4] = firstByte;
    outPattern[5] = secondByte;
}
```

Formal C++ is forbidden for this target because it has no owner/emitter route and no proven liveness. The known live GrafPort text helpers inline the identical pattern and call `GrafPortDrawGlyph` directly; emitting an extra helper would add unreferenced source that the current binary does not prove is source-used. A future direct caller, pointer-table/vtable/callback route, valid branch route, or source-retention proof would be required before C++ can be emitted.
````

### Coverage Row

Replace the current [UID:0003XF] row in `by-memory/-coverage-report.md` under [UID:000160], after [UID:00016H] and before [UID:00016I], with:

```markdown
    - [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) 0x004bb5b0-0x004bb5d1 | raw code | GrafPortPatternPackRaw : reconstructable : 85% : strong : B004 2026-06-18 source-route recheck raises completion to the no-owner documentation gate after confirming the exact 33-byte stdcall-like helper at PE raw offset `0x000ba9b0`, SHA-256 `bba67603719aefc29d4a587922384e46f62e552ffbc24703451d25ea87dbeb4b`, with eleven leading and fifteen trailing `0xcc` padding bytes; it writes the six-byte pattern `{second, first, second, first, first, second}` and returns with `retn 0x0c`. Fresh scans find no VA/RVA/raw-offset dword into any byte of the helper range, no rel32 call/jump/jcc route, no pointer/vtable/callback route, and the only broad short-branch candidate is a ModRM-byte false positive inside `GrafPortDrawGlyph`; positive controls find live calls to `0x004bb2e0`, `0x004bb5e0`, and `0x004b99f0`, callback target dwords for `0x004bc090`/`0x004c0f80`, and 114 loaded `.text` refs to callback slot `0x0069b3e8`. Live GrafPort text helpers build the identical text/back-color pattern inline before calling `GrafPortDrawGlyph`, validating GrafPort glyph/text as the best forced family, but owner remains `NONE`, emitters blank, and formal C++ blank because no source-use route is proven.
```

### Support Docs

In [UID:0000JR] `by-file/GrafPort.md` and [UID:00005V] `by-class/GrafPort.md`, replace the current [UID:0003XF] paragraph/note with:

```markdown
[UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) remains no-owner/non-emitting after B004's 2026-06-18 source-route recheck, but its behavior is now stronger than a visual guess: local PE bytes prove the 33-byte `ret 0x0c` body at raw offset `0x000ba9b0`, and live `DrawGlyphWithTextColors` / `DrawWideText` build the identical `{m_textBackColor, m_textColor, m_textBackColor, m_textColor, m_textColor, m_textBackColor}` pattern inline before calling `GrafPortDrawGlyph`. This validates GrafPort glyph/text support as the best forced family. Do not assign it to GrafPort or emit C++ because scans still find no caller, VA/RVA/raw-offset pointer, pointer-table/vtable/callback route, or valid branch route to `0x004bb5b0`; the known live text helpers inline the pattern instead.
```

In [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`, replace the [UID:0003XF] child inventory/source-placement note with:

```markdown
| `0x004bb5b0-0x004bb5d1` | [UID:0003XF][0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw](by-memory/0x004bb5b0-0x004bb5d1.GrafPortPatternPackRaw.md) | Raw two-color six-byte text/back-color pattern pack helper; B004 validates the output order against live GrafPort text helpers, but the child stays no-owner/non-emitting until a caller, pointer-table/vtable/callback route, or other source-use proof is found. |
```

In [UID:00016I] `by-memory/0x004bb5e0-0x004bb7e0.GrafPortDrawGlyph.md`, add:

```markdown
- 2026-06-18 B004 [UID:0003XF] recheck: the adjacent raw helper at `0x004bb5b0-0x004bb5d1` writes the same six-byte text/back-color pattern built inline by this function's two direct callers, [UID:00016C] `DrawGlyphWithTextColors` and `DrawWideText`. The match validates the pattern semantics but not a call edge; `GrafPortDrawGlyph` still begins at `0x004bb5e0`, and no branch/pointer route to the raw helper is proven.
```

In [UID:00016C] `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`, add:

```markdown
- 2026-06-18 B004 [UID:0003XF] recheck: the inline `colors[0..5]` construction in `DrawGlyphWithTextColors` and `DrawWideText` exactly matches the adjacent raw helper's `{second, first, second, first, first, second}` output when `first = m_textColor` and `second = m_textBackColor`. Keep the inline construction in the emitted text helpers; do not replace it with a call to [UID:0003XF] unless a source-use route to `0x004bb5b0` is later proven.
```

## Validator And Command Results

Commands/results used in this pass:

- `Test-NetConnection 127.0.0.1 -Port 13337`: `TcpTestSucceeded : False`.
- Read target and support docs: [UID:0003XF], [UID:000160], [UID:00016H], [UID:00016I], [UID:00005V], [UID:0000JR], [UID:0000OC], [UID:0003XD], [UID:0000M2], [UID:0000JH], [UID:0000J4], and current coverage row.
- Read executed prior reports as leads only: B002 `0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md` and B001 `00016B-00016C-00016D-GrafPortTextHelpers-source-quality.md`.
- Local PE parser/Capstone scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`: produced raw bytes, hashes, disassembly, padding, file offsets, uniqueness checks, whole-range pointer scans, rel32 scans, short-branch false-positive review, and positive controls.
- Generated/source-output searches under `source-3\simroot_v2`, `project-documentation\auto-generated\NexusTK`, and `project-documentation\project-level`: no generated source hit for `004bb5b0`, `004BB5B0`, `GrafPortPatternPackRaw`, or `PackTwoColorSixPixelPattern`; project-level stats still list [UID:0003XF] as stale `84/88`.
- Broad whole-`source-3` `rg` search timed out after approximately fourteen seconds; treated as a failed broad check, not as positive no-hit evidence.
- No validator command was run because this was report-only and no by-* files were edited.

## Changed Files

- Modified in this revision: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0003XF-GrafPortPatternPackRaw-source-route-recheck.md`.
- Modified outside the required Agent-B004 report: none.
- Created: none in this revision.
- Renamed: none.
- Coverage/generated/by-* edits: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0003XF-GrafPortPatternPackRaw-source-route-recheck.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0003XF"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
