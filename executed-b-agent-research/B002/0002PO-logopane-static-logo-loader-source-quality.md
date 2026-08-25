** TARGET-REPORT-UID:0002PO **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002PO] LogoPaneStaticLogoLoaderHelpers Source-Quality Report

Assignment: `B002-goal2-logopane-static-logo-loader-source-quality-0002PO-20260617`

Primary target: [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](../../../../../by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md)

## Recommendation

Keep [UID:0002PO] reconstructable and owned/emitted by [UID:00007G][LogoPane](../../../../../by-class/LogoPane.md), routed through [UID:0000O4][StartupLogoPanes](../../../../../by-file/StartupLogoPanes.md). Raise the target from `82/88` to `86/90`.

Recommended metadata:

```text
COMPLETION:86
CONFIDENCE:90
CANONICAL_OWNER:00007G
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00007G
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP: leave formal block blank for now
```

The best current source explanation is a retained out-of-line `LogoPane` helper pair that the constructor also inlines: one path loads the static `.LGO` payload, and the second attaches the decoded surface to the startup/UI layer. This is source-authored project code, not padding and not compiler thunk glue. The no-xref state is real, but it is not a blocker for ownership because the helper bodies duplicate the constructor's live static-logo load/attach sequence exactly enough to explain them as inlined-and-retained private helpers.

Do not populate the formal target C++ block yet. The body is source-authored and reconstructable, but the formal source block should wait until the supervisor chooses a class-level policy for retained helper definitions versus constructor-only emission, and until the final virtual slot names and `MainUiLayerSlots` slot name are stabilized.

## Evidence Checked

Existing report search: `rg -n "0002PO|0x004f50b0|LogoPaneStaticLogoLoaderHelpers|NEXON\.LGO"` across B001/B002/B003 `research` and `research/executed` found no prior B-agent report for this exact UID. Existing by-memory/class/file/resource docs were used as leads only.

Generated route check: `auto-generated/-ag-memory-coverage.md` routes [UID:0002PO] as emitting through [UID:00007G] to `auto-generated/NexusTK/app/StartupLogoPanes.cpp`. The current generated `StartupLogoPanes.cpp` file is zero bytes, so there is no generated source body to use as evidence for this target; source-tree placement is therefore taken from the owner/file docs and the coverage route, not generated C++ contents.

Live IDA MCP session `b003_00018a_ime_comp_20260617` is healthy on `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready. `lookup_funcs` reports no functions at `0x004f50a1`, `0x004f50b0`, `0x004f521e`, `0x004f5220`, or `0x004f5246`; the next function is `sub_4F5250` at `0x004f5250`, size `0x8e`.

IDA `entity_query` over `0x004f50a0-0x004f5255` lists only `0x004f5250`. This confirms that the target is an unpromoted helper island, not an IDA-modeled method with a missing name.

IDA `xrefs_to` reports zero xrefs to `0x004f50b0`, zero to `0x004f5220`, and zero to `0x004f5246`. As a control, it reports four refs to `0x004f5250`: raw jump `0x004f4f53`, calls `0x004f4fc6`, `0x004f5012`, and `0x004f5036`.

PE-aware scan of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

```text
imagebase=0x400000
.text rva=0x1000 raw=0x400 raw_size=0x20b600
0x004f50b0 file=0xf44b0
0x004f5220 file=0xf4620
0x004f5246 file=0xf4646
0x004f5250 file=0xf4650

rel32 call/jmp edges:
0x004f50b0: 0
0x004f5220: 0
0x004f5246: 0
0x004f5250: 4, at 0x004f4f53 jmp, 0x004f4fc6 call, 0x004f5012 call, 0x004f5036 call

full-file VA/RVA dword literal hits:
0x004f50b0 VA/RVA: 0/0
0x004f5220 VA/RVA: 0/0
0x004f5246 VA/RVA: 0/0
0x004f5250 VA/RVA: 0/0
```

The PE scan independently validates the no-direct-caller/no-pointer state for the raw helper starts. It also validates the scan by finding the four expected direct edges into the live successor method.

## Exact Range And Bytes

The target should remain the half-open aggregate `0x004f50b0-0x004f5246`, with local split:

| Range | Size | Role |
| --- | ---: | --- |
| `0x004f50a1-0x004f50b0` | `0x0f` | predecessor padding after [UID:0003LL] `LogoPaneAdvanceToNextScreen` |
| `0x004f50b0-0x004f521e` | `0x16e` | unpromoted static-logo loader, `__thiscall`, stack arg `const wchar_t *path`, returns with `ret 4` |
| `0x004f521e-0x004f5220` | `0x02` | internal `0xcc` padding |
| `0x004f5220-0x004f5246` | `0x26` | unpromoted attach helper, `__thiscall`, no explicit args, returns with `ret` |
| `0x004f5246-0x004f5250` | `0x0a` | successor padding before [UID:0002PP] `LogoPaneQueueAdvanceToNextScreen` |

Byte hashes and bytes:

```text
0x004f50a1-0x004f50b0 sha256=54cc9dd9593316e80ccaf5d10856e6502a0d75f20473a92fa01d63228ef1624c
cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc

0x004f50b0-0x004f521e sha256=f160575596df6b2ad14919f2e296dff9adc8122e86d3d8044c6bcc45a907c8af
55 8b ec 83 ec 08 53 8b d9 57 8d 8b f8 00 00 00 e8 3b 34 f6 ff 68 20 df 60 00 ff 75 08 ff 15 14
be 69 00 8b f8 83 c4 08 85 ff 0f 84 36 01 00 00 57 6a 01 8d 45 fc 6a 04 50 e8 ca d7 0d 00 83 c4
10 83 f8 01 0f 85 1c 01 00 00 ff 75 fc e8 8e 26 0d 00 57 ff 75 fc 89 45 08 6a 01 50 e8 a7 d7 0d
00 83 c4 14 39 45 fc 0f 85 f9 00 00 00 0f bf 0d 98 da 66 00 0f bf 05 94 da 66 00 0f af c8 56 51
e8 5b 26 0d 00 ff 75 fc 0f bf 15 98 da 66 00 8b f0 0f bf 0d 94 da 66 00 8d 45 f8 ff 75 08 0f af
d1 50 56 89 55 f8 e8 35 f2 f1 ff ff 75 08 e8 36 26 0d 00 83 c4 18 89 b3 fc 00 00 00 c7 83 1c 01
00 00 00 00 00 00 8d 8b 08 01 00 00 0f bf 05 94 da 66 00 89 83 04 01 00 00 c7 83 18 01 00 00 00
00 00 00 0f bf 05 98 da 66 00 50 0f bf 05 94 da 66 00 50 6a 00 6a 00 e8 24 27 fc ff 8b 03 8b cb
6a 00 ff 50 20 57 6a 01 8d 45 fc 6a 04 50 e8 f5 d6 0d 00 83 c4 10 83 f8 01 75 4a ff 75 fc e8 bd
25 0d 00 57 ff 75 fc 8b f0 6a 01 56 e8 d7 d6 0d 00 8b 4d fc 83 c4 14 3b c8 75 2a 51 56 8d 8b 20
01 00 00 e8 a8 de 04 00 56 e8 9b 25 0d 00 83 c4 04 8d 8b f8 00 00 00 e8 a4 28 f6 ff 57 e8 5a d4
0d 00 83 c4 04 5e 5f 5b 8b e5 5d c2 04 00

0x004f521e-0x004f5220 sha256=e3966e3275be536a16092ec0cadf1638f718218e616fbbe8ff1c5e67fff4def2
cc cc

0x004f5220-0x004f5246 sha256=3ea59a2930744745ff076d03f1ccf4502e7a303ff8874e693763cf4ae94d708b
56 ff 35 6c b3 69 00 8b f1 6a 00 6a 00 8b 16 8d 86 08 01 00 00 50 ff 52 30 8b 06 8b ce 6a 00 6a
00 ff 50 3c 5e c3

0x004f5246-0x004f5250 sha256=22e52bba61da8ad6732be550205a10b89a1bb3b0ea491be07de9294f0eb6f045
cc cc cc cc cc cc cc cc cc cc
```

IDA unique signatures:

```text
0x004f50b0-0x004f521e: unique
55 8B EC 83 EC 08 53 8B D9 57 8D 8B ? ? ? ? E8 ? ? ? ? 68 20 DF 60 00 FF 75 ? FF 15 ? ? ? ? ...

0x004f5220-0x004f5246: unique
56 FF 35 ? ? ? ? 8B F1 6A 00 6A 00 8B 16 8D 86 ? ? ? ? 50 FF 52 ? 8B 06 8B CE 6A 00 6A 00 FF 50 ? 5E C3

0x004f50b0-0x004f5246 combined range: unique
```

## Helper Shape And Field Meanings

Recommended source-facing helper names:

| Range | Best source-facing shape | Evidence |
| --- | --- | --- |
| `0x004f50b0-0x004f521e` | `void LogoPane::LoadStaticLogoFromFile(const wchar_t *path)` | `this` in `ecx`, one stack argument, `ret 4`, `_wfopen(path, L"rb")`, reads the `.LGO` image/palette payload, stores object fields, and returns void. |
| `0x004f5220-0x004f5246` | `void LogoPane::AttachStaticLogoSurface()` | `this` in `ecx`, no explicit args, pushes layer slot `0x0069b36c`, passes `this + 0x108`, calls virtual slots `+0x30` and `+0x3c`, returns void. |

Recommended field names and types:

| Offset | Best source-facing field/type | Evidence |
| --- | --- | --- |
| `this + 0xf8` | `EPFTileContext m_logoTileContext` | Constructor calls `EPFTileContext` init at `0x00457a60`; destructor/scalar destructor release it via `0x00458500`; loader resets it via `0x00458500` and builds its RLE mask via `0x00457ab0`. |
| `this + 0xfc` | `m_logoTileContext.primaryPixels`, `uint8_t *` | Loader stores decoded `g_screenWidth * g_screenHeight` byte buffer here after zlib `uncompress`. |
| `this + 0x104` | `m_logoTileContext.rowStride`, `int` | Loader writes `g_screenWidth`. This is `EPFTileContext + 0x0c`. |
| `this + 0x108` | `m_logoTileContext.bounds`, `RectBounds` | Loader calls `RectBounds::SetLTRB(0, 0, g_screenWidth, g_screenHeight)` with `ecx=this+0x108`; attach helper and blit helper both pass this address as the logo rectangle/image state. |
| `this + 0x118` | `m_logoTileContext.encodedMaskByteCount`, `uint32_t` | Cleared before `EPFTileContext::BuildRleMask8`. This is `EPFTileContext + 0x20`. |
| `this + 0x11c` | `m_logoTileContext.encodedMaskBytes`, `uint8_t *` | Cleared before `EPFTileContext::BuildRleMask8`. This is `EPFTileContext + 0x24`. |
| `this + 0x120` | `DLPalette m_logoPalette` | Constructor constructs it with `0x00542bb0`; destructor frees/destroys via `0x00542cd0`/`0x00542ca0`; loader calls `DLPalette::LoadFromBitmapPalette` at `0x005430a0`. |

The loader's `.LGO` format contract is:

```text
uint32_t compressedImageSize
uint8_t compressedImage[compressedImageSize]
uint32_t paletteSize
uint8_t paletteBlob[paletteSize]
```

The image payload inflates through zlib `uncompress` at `0x00414390` into exactly `g_screenWidth * g_screenHeight` bytes. The palette blob is handed to `DLPalette::LoadFromBitmapPalette` at `0x005430a0`. This is startup-logo media handling, not DAT archive parsing or a generic image-loader format.

The exact binary only closes the file on the fully successful palette path. Early read/allocation mismatch paths jump to the epilogue without full cleanup. Reconstructed source should not silently "fix" that if the target is used for binary-shape validation.

## Globals And Dependencies

Use these names/types in support docs and first-draft prose:

| Binary item | Recommended source-facing role | Owner |
| --- | --- | --- |
| `dword_69BE14` / `0x0069be14` | `g_pfnWideOpenFile` or `WideApiDispatchTable::wfopen`, type `FILE *(__cdecl *)(const wchar_t *, const wchar_t *)` | [UID:0000TQ][WideApiDispatchTable](../../../../../by-global/WideApiDispatchTable.md) / [UID:0000ML][PlatformApi](../../../../../by-file/PlatformApi.md). The loader consumes the platform dispatch slot; it does not own it. |
| `word_66DA94` / `0x0066da94` | `g_screenWidth`, 16-bit display width promoted to `int` | [UID:0000SU][g_screenWidth](../../../../../by-global/g_screenWidth.md). |
| `word_66DA98` / `0x0066da98` | `g_screenHeight`, 16-bit display height promoted to `int` | [UID:0000ST][g_screenHeight](../../../../../by-global/g_screenHeight.md). |
| `dword_69B36C` / `0x0069b36c` | `g_mainUiLayerSlots.overlayPaneLayerContext` is the best descriptive name; keep address-backed slot wording until final per-slot names are proven. Type is a pointer to the 8-byte UI layer/context object consumed by pane attach virtuals. | [UID:0000T6][MainUiLayerSlots](../../../../../by-global/MainUiLayerSlots.md), not LogoPane. |

Rejected global alternatives:

- `LogoPane`-owned file callback: rejected. `0x0069be14` is initialized by WideApiDispatchInit and has broad file-open consumers.
- `LogoPane`-owned layer pointer: rejected. `0x0069b36c` has 101 refs across 92 functions and is startup/shutdown managed by MainUiGraph/MainUiLayerSlots.
- `g_startupLogoLayer` as a final declaration: too narrow. The slot is used broadly by UI/dialog/pane creation; within this target it can be described as the startup/static-logo attach context.

## Duplicate And Liveness Treatment

The raw helper pair is live code in the PE image, but currently dormant by direct-edge evidence.

Best interpretation:

- The source likely had private `LogoPane` helper definitions for static-logo load and surface attach.
- The constructor source likely called those helpers.
- The compiler/linker emitted the out-of-line helper bodies and also inlined their bodies into `LogoPane::LogoPane`, leaving no direct call from constructor to the helper starts in the final binary.
- The helpers survived because the object file containing `LogoPane` was linked and the build did not discard these unreferenced out-of-line definitions.

Rejected alternatives:

- Padding: rejected by instruction bodies, prologue/epilogue, calls, and unique signatures.
- Compiler thunk/destructor glue: rejected by full application-level file I/O, decompression, palette, geometry, and virtual attach behavior.
- Function pointer or vtable callback liveness: rejected by IDA xrefs and full-file VA/RVA pointer scans.
- Feature-local image loader ownership: rejected because the path and format are startup-logo-specific and duplicate the `LogoPane` constructor, while lower image/palette/zlib systems are dependencies.
- Direct constructor caller missed by IDA: rejected by PE rel32 scan, which finds no direct call/jump to `0x004f50b0` or `0x004f5220` but does find the expected four edges to `0x004f5250`.

## Heuristic / Inference Reanalysis And Validation

Best defensible names and directions:

- `LogoPane::LoadStaticLogoFromFile(const wchar_t *path)` for `0x004f50b0-0x004f521e`.
- `LogoPane::AttachStaticLogoSurface()` for `0x004f5220-0x004f5246`.
- `m_logoTileContext` for the `EPFTileContext` at `+0xf8`.
- `m_logoPalette` for the `DLPalette` at `+0x120`.
- `g_screenWidth` and `g_screenHeight` for the display-size operands.
- `WideApiDispatchTable::wfopen` or `g_pfnWideOpenFile` for `0x0069be14`.
- `g_mainUiLayerSlots.overlayPaneLayerContext` or address-backed `slot69B36C` for `0x0069b36c`; this remains the weakest final-name inference and is one reason formal C++ should stay blank.

Evidence checked:

- Target page, LogoPane class page, StartupLogoPanes file page, startup-logo media page, LogoPane aggregate, constructor, destructor, blit helper, queue helper, EPFTileContext, DLPalette, Zlib public wrapper, RectBounds, WideApiDispatchTable, MainUiLayerSlots, screen width/height globals, and generated memory coverage route.
- Live IDA `lookup_funcs`, `entity_query`, bounded `insn_query`, `get_bytes`, `decompile 0x004f4c10`, `decompile 0x004f50b0` failure, `xrefs_to`, and `make_signature_for_range`.
- PE section mapping, file offsets, rel32 call/jump scan, and VA/RVA dword literal scan.
- Existing B-agent reports for this UID and contained/sibling strings; no exact prior B report was found.

Existing documentation validated:

- The current target page is correct that `0x004f50b0` and `0x004f5220` are unpromoted, source-bearing helper bodies and not padding.
- The current target page is correct about no direct IDA xrefs to helper starts.
- The current target page is correct about the main dependency set: `_wfopen`, `g_screenWidth`, `g_screenHeight`, zlib `uncompress`, `DLPalette::LoadFromBitmapPalette`, `EPFTileContext::BuildRleMask8`, and `dword_69B36C`.
- The constructor page is correct that the same static-logo load/attach flow is inlined in `LogoPane::LogoPane`.
- The startup-logo resource page is correct that `.LGO` is a startup-specific container and the current audited package lacks a found payload, without weakening the binary loader contract.

Existing documentation rejected or refined:

- The old "final C++ deferred because exact helper names/call linkage need deeper pass" should be replaced with the more specific retained-out-of-line/inlined-into-constructor model.
- Treating no direct xrefs as a liveness blocker is too vague; the PE scan validates true dormant direct reachability and gives a concrete retained-helper policy.
- Treating `+0x108` as a standalone logo rectangle field is incomplete. It is the `RectBounds` subfield inside the embedded `EPFTileContext` at `+0xf8`.
- Treating `dword_69B36C` as a LogoPane/startup-private global is rejected by MainUiLayerSlots evidence.

Score/source-placement/final-C++ impact:

- Completion can rise to `86` because range, bytes, liveness, duplicate relationship, field layout, globals, and source placement are now resolved enough for supervisor action.
- Confidence can rise to `90` because IDA, PE, and support docs agree on the body and owner. It should not rise higher because exact original helper names, virtual slot names, and the emitted-vs-inlined source declaration policy remain below final-source quality.
- Source placement remains [UID:00007G] `LogoPane`, emitted through [UID:0000O4] `StartupLogoPanes.cpp`. Do not move to ImageLoaders, Palette, Zlib, PlatformApi, or MainUiGraph.
- Formal target C++ should remain blank even though the target remains reconstructable/emitting and clears the `85/85` gate.

## First-Draft C++ Recommendation

Do not populate the target's formal `RECONSTRUCTION_CPP CODE` block from this draft. This is review-only first-draft C++ for the supervisor because the retained-helper/inlined-constructor policy and virtual slot names are not final.

```cpp
// Review-only draft. Names are source-facing recommendations, not final proof.
void LogoPane::LoadStaticLogoFromFile(const wchar_t* logoPath)
{
    m_logoTileContext.ReleaseBuffers();

    FILE* file = g_pfnWideOpenFile(logoPath, L"rb");
    if (file == nullptr) {
        return;
    }

    uint32_t compressedSize = 0;
    if (fread(&compressedSize, sizeof(compressedSize), 1, file) != 1) {
        return; // Matches the legacy helper's success-only cleanup shape.
    }

    auto* compressed = static_cast<uint8_t*>(std::malloc(compressedSize));
    if (fread(compressed, 1, compressedSize, file) != compressedSize) {
        return;
    }

    uLongf decodedSize =
        static_cast<uLongf>(static_cast<int>(g_screenWidth) * static_cast<int>(g_screenHeight));
    auto* decoded = static_cast<uint8_t*>(std::malloc(decodedSize));
    Uncompress(decoded, &decodedSize, compressed, compressedSize);
    std::free(compressed);

    m_logoTileContext.primaryPixels = decoded;
    m_logoTileContext.encodedMaskBytes = nullptr;
    m_logoTileContext.rowStride = g_screenWidth;
    m_logoTileContext.encodedMaskByteCount = 0;
    m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    OnBoundsChangedOrInvalidate(0); // vslot +0x20, name not final.

    uint32_t paletteSize = 0;
    if (fread(&paletteSize, sizeof(paletteSize), 1, file) == 1) {
        auto* paletteBlob = static_cast<uint8_t*>(std::malloc(paletteSize));
        if (fread(paletteBlob, 1, paletteSize, file) == paletteSize) {
            m_logoPalette.LoadFromBitmapPalette(paletteBlob, paletteSize);
            std::free(paletteBlob);
            m_logoTileContext.BuildRleMask8();
            fclose(file);
        }
    }
}

void LogoPane::AttachStaticLogoSurface()
{
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext); // vslot +0x30.
    SetSurfaceOriginOrVisibleState(0, 0); // vslot +0x3c, name not final.
}
```

If the supervisor later chooses to populate formal C++, preserve the exact binary failure behavior or explicitly document any intentional source cleanup improvement. The above semantic draft is intentionally not exact enough for formal target entry.

## Support Docs To Update

Recommended target page updates:

- Add the live IDA MCP session facts, exact function absence, helper split, byte hashes, unique signatures, and PE rel32/VA/RVA scan results.
- Replace the vague no-xref blocker with the retained out-of-line helper plus constructor-inlining model.
- Add the field table mapping `+0xf8` through `+0x120` to `EPFTileContext` and `DLPalette`.
- Add explicit source-facing helper names/signatures as recommendations, with final C++ blank.

Recommended support updates:

- [UID:00007G] `LogoPane`: add the raw retained helper pair to Method Notes, with no direct xrefs and constructor-inlined duplicate treatment.
- [UID:00019C] `LogoPane` memory aggregate: update the [UID:0002PO] child row from raw helper cluster to retained static-logo loader/attach helper pair and reference this liveness decision.
- [UID:0000O4] `StartupLogoPanes`: add [UID:0002PO] as retained static-logo helper bodies under `LogoPane`; keep `StartupLogoPanes.cpp` as source placement and retain the two-file split caveat.
- [UID:0001RN] `startup-logo-media`: add [UID:0002PO] as a second binary confirmation of the `.LGO` `[imageSize][compressedImage][paletteSize][paletteBlob]` contract.
- [UID:0000T6] `MainUiLayerSlots`: optional consumer note that `0x004f5221` in [UID:0002PO] pushes `0x0069b36c` into LogoPane's attach virtual.
- [UID:0000TQ] `WideApiDispatchTable`: optional consumer note that `0x004f50cd` in [UID:0002PO] is another direct `_wfopen` dispatch use.

No by-* docs were edited by this report.

## Supervisor-Owned Coverage Row

Replace the current [UID:0002PO] row in `by-memory/-coverage-report.md` under the `LogoPane` children, between [UID:0002PN] and [UID:0002PP], with:

```text
    - [UID:0002PO][0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers](by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md) 0x004f50b0-0x004f5246 | raw helper pair | LogoPane retained static-logo loader/attach helpers : reconstructable : 86% : strong : Live IDA/PE audit confirms unpromoted code bodies at `0x004f50b0-0x004f521e` and `0x004f5220-0x004f5246`, exact `0xcc` padding at `0x004f50a1-0x004f50b0`, `0x004f521e-0x004f5220`, and `0x004f5246-0x004f5250`, zero direct xrefs/rel32/VA/RVA pointer hits to helper starts, constructor-inlined duplicate relationship to `LogoPane::LogoPane`, `_wfopen`/zlib/EPFTileContext/RectBounds/DLPalette/MainUiLayerSlots dependencies, `EPFTileContext` field mapping at `+0xf8`, and final C++ intentionally blank pending retained-helper naming and source/inline emission policy.
```

The current coverage report also has stale sibling scores for some nearby LogoPane rows compared with their live pages. I am not recommending unrelated row repairs in this report; supervisor should refresh coverage after applying accepted docs.

## Validation Commands

Recommended after supervisor applies target/support docs:

> Executable block R001 was removed from this report and preserved verbatim in [0002PO-logopane-static-logo-loader-source-quality-removed.md](0002PO-logopane-static-logo-loader-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA/PE revalidation commands used for this report were read-only MCP `server_health`, `lookup_funcs`, `entity_query`, `insn_query`, `get_bytes`, `decompile`, `xrefs_to`, `make_signature_for_range`, plus a local read-only PE byte/edge scan of `NexusTK.exe`.

## Changed Files, Leases, Blockers, Follow-Up

Changed files:

- `tools/leaser/Agents/Agent-B002/research/0002PO-logopane-static-logo-loader-source-quality.md`

Leases used:

- None. Report-only work stayed in the assigned B002 research folder.

Blockers:

- No execution blocker. Formal C++ is intentionally blocked by retained-helper versus constructor-inline emission policy, final helper names, and final virtual slot names.

Useful follow-up:

- A LogoPane class-layout/source-name pass should settle `m_logoTileContext`, `m_logoPalette`, `AttachSurface`, `OnBoundsChangedOrInvalidate`, and `MainUiLayerSlots` slot `0x0069b36c` names before any formal C++ is entered for [UID:0002PO] or the constructor.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002PO-logopane-static-logo-loader-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002PO"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002PO-logopane-static-logo-loader-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002PO-logopane-static-logo-loader-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002PO"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
