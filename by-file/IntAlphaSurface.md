*** UID:0000K8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# IntAlphaSurface

## Final Historical File-Split Disposition

An independent `NexusTK/render/IntAlphaSurface.cpp` is rejected. Unique IntAlphaSurface RTTI, one vtable, the contiguous `[0x00462120,0x004632b1)` family, and all constructor/view/destructor stores prove that the concrete class is physically reconstructed in [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) as `AlphaMaskSurface.cpp/.h`. This page retains the earlier file-split investigation and exact destructor/vtable evidence, but no emitting class or child remains routed here.

The `95/95` score represents a final source-placement disposition, not a second source module. The old separate-file model is preserved below as historical reasoning and must not recreate `IntAlphaSurface.cpp` or `IntAlphaSurface.h`.

## Historical Pre-Callback Status

- Confidence: strong for destructor, buffer-release slot, vtable slots, and live IDA function-boundary evidence; medium-high for source placement; medium for the final class split.
- Proposed module: `NexusTK/render/IntAlphaSurface.cpp`, with possible merge into `NexusTK/render/AlphaMaskSurface.cpp` or `NexusTK/render/Surface.cpp` if later constructor/caller recovery proves it was not a standalone source file.
- Main address range: [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

## File Role

`IntAlphaSurface` appears to be an integer or per-pixel alpha surface related to the byte-mask `AlphaMaskSurface` family. Live IDA evidence proves two source-ready class methods: the scalar deleting destructor range [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md), whose formal source body frees `m_pixels` when `m_ownsBuffer` is set and leaves scalar-delete wrapper behavior to the compiler, and slot 1 [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md), which performs the same owned-buffer release without deleting object storage.

The concrete object offsets are recorded in [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), and the recovered vtable slots are recorded in [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md). The vtable's class/type owner is now [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) because RTTI names `IntAlphaSurface`; the same vtable is written by `AlphaMaskSurface` constructor/helper code, so the physical source-file split remains visible as a separate caveat. [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) is now resolved as AlphaMaskSurface-owned source code with an explicit `IntAlphaSurface *` destination parameter.

The source-file split is provisional. IDA shows the `IntAlphaSurface` vtable at `0x006112ec`, with the first slot pointing at the destructor and the next slot pointing at `0x00462260`. References to that vtable come from `AlphaMaskSurface` constructor/helper code as well as the destructor, so this may be a base/sibling surface implementation rather than a large independent file. The `0x004623c0` view initializer remains relevant here as vtable/layout construction evidence, but it should not be listed as an `IntAlphaSurface` member method.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `IntAlphaSurface::~IntAlphaSurface` | [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) | Formal ordinary destructor C++ frees owned pixel storage and clears `m_pixels`; scalar-delete wrapper/object delete remains compiler-generated. |
| `IntAlphaSurface::ReleaseOwnedPixels` | [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md) | Formal release-helper C++ frees owned pixel storage at `+0x14`, clears the pointer, and leaves object storage intact. |
| `InitAlphaSurfaceView` external use-site evidence | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | AlphaMaskSurface-owned helper that placement-initializes a caller-supplied full or clipped non-owning `IntAlphaSurface` view object. |
| Active alpha-surface owning constructor | `0x00462170-0x00462227` | Real IDA-modeled constructor/helper that writes `off_6112EC`, initializes bounds, allocates `width * height` bytes, and ties this vtable to live alpha-surface construction. |
| Raw default-constructor-shaped block | [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md) | Raw code only; writes the same vtable and zero/owning state, but IDA still has no function object or xrefs to the start. |
| `IntAlphaSurface` vtable | [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) | RTTI-backed class vtable; slot 0 points to `0x00463270`, slot 1 points to `0x00462260`, and the direct class owner is [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md). |

## Evidence Notes

- IDA MCP reports no direct code callers to `0x00463270`, which is normal for a virtual destructor reached through a vtable.
- IDA MCP reports no direct code callers to `0x00462260`, but `xrefs_to` shows it is vtable slot 1 at `0x006112f0`.
- 2026-07-03 B006 current MCP session `b010_00032w_20260703` reconfirmed `0x00463270` as size `0x41` / 65 and `0x00462260` as size `0x22` / 34 (both Verified with `int_convert.py`), exact bytes/padding for both methods, pointer-pattern uniqueness at `0x006112ec` and `0x006112f0`, vtable base refs at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`, and separate `0x004632c0` cleanup vtable `0x00612574`.
- IDA MCP reports `0x004623c0` writes `off_6112EC` and builds full/clipped view state. B009's 2026-06-28 implementation resolves that body as [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)-owned source code whose destination parameter is an `IntAlphaSurface *`; keep it here only as construction/use-site evidence for this type's vtable/layout, not as an `IntAlphaSurface` source-owned method.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that also write `off_6112EC`; keep that range near the alpha-surface family but do not treat it as an IDA-confirmed `IntAlphaSurface` constructor.
- 2026-05-26 IDA MCP raw-disassembly/xref recheck found [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) as compiler EH cleanup that restores `off_6112EC` and releases owned pixels. Its only observed caller is the EH funclet at `0x005fa593`.
- `0x004632c0` is not an `IntAlphaSurface` destructor. It uses vtable `0x00612574`, frees a different object/global payload, and belongs to application error-state cleanup.
- IDA MCP reports data references to `off_6112EC` from raw `0x0046212c`, `0x0046217b`, EH cleanup store `0x00462237`, `0x00462415`, and `0x0046327a`; all but the destructor reset are in the neighboring `AlphaMaskSurface` constructor/helper region.
- 2026-05-30 IDA MCP recheck confirms the destructor and release vtable slot both free pixel pointer offset `+0x14` only when ownership byte `+0x24` is set, and that both entries remain vtable-only with no direct code callers. This supports a surface class method reconstruction while leaving the exact original file split provisional.
- 2026-06-04 live IDA MCP recheck confirms `0x00462120` still has no function object and no xrefs; the surrounding functions are `sub_461FE0` ending at `0x00462114` and `sub_462170` starting at `0x00462170`. Raw disassembly still shows `0x00462120-0x00462161` writing `off_6112EC`, clearing `+0x14/+0x18/+0x1c/+0x20`, setting ownership byte `+0x24`, and calling `sub_4B7C50`.
- 2026-06-04 live IDA MCP `decompile 0x00462170` confirms the active owning constructor/helper writes `off_6112EC`, initializes bounds, calls the vtable release slot before reallocating, stores width/height/stride, and allocates `width * height` bytes. `callers 0x00462170` reports four callers at `0x004df9a9`, `0x0050442c`, `0x005a288d`, and `0x005a2b8e`.
- 2026-06-04 live IDA MCP confirms `sub_4623C0` is `0x004623c0-0x00462514` and owns tail chunks `0x00462230-0x00462258` and `0x005fa580-0x005fa5be`; `xrefs_to 0x00462230` reports the EH funclet xref at `0x005fa593`, so the cleanup remains compiler support rather than a source method.
- 2026-06-04 live IDA MCP reads the first four vtable dwords at `0x006112ec` as `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000`. `xrefs_to 0x006112ec` still reports the five data stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.
- 2026-06-07 Agent-A002 IDA MCP recheck confirms the direct parent-gate evidence for [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md): raw `0x00462120` still has no IDA function object or xrefs; `0x00462170-0x00462227` remains the active constructor/helper with four direct code xrefs from three unique caller functions; `0x00462260-0x00462282` and `0x00463270-0x004632b1` remain vtable-only virtual targets; and `off_6112EC` still contains `0x00463270`, `0x00462260`, `0x00000000`, and `0x00000000` with stores at `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.
- 2026-06-08 B001 ownership follow-up confirms the vtable RTTI chain `0x006112e8 -> 0x00641e9c -> 0x006744ec`, naming `IntAlphaSurface` through `??_R4IntAlphaSurface@@6B@` and `??_R0?AVIntAlphaSurface@@@8`. This supports assigning the vtable artifact to the class while keeping this file-level page cautious about original source colocation.

## Ownership Decision

Keep `IntAlphaSurface` in the render surface layer. Do not assign it to an image-library consumer such as `LightObjImageLib`; the only proven behavior is generic surface ownership and teardown. Keep the standalone `render/IntAlphaSurface.cpp` node in the proposed tree as a research anchor, but allow migration to fold it into `AlphaMaskSurface.cpp` or `Surface.cpp` if the constructor or full vtable later proves a smaller original source grouping.

[UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) is class-owned by [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) because the RTTI attached to the vtable names `IntAlphaSurface`. That assignment does not prove this by-file page was a standalone original `.cpp`; it only resolves the direct type-owner relationship for the vtable artifact.

The validator path is `NexusTK/render/` because [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/IntAlphaSurface.cpp` as a provisional node next to `AlphaMaskSurface.cpp`. That is a placement anchor, not proof that the original project had a separate source file.

## Cross-References

- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- 2026-07-03 B006 Gate 1 implementation:
  - Raised completion/confidence from `85/88` to `86/90`.
  - Summary/evidence: the IntAlphaSurface source route now records source-ready destructor [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md) and release helper [UID:0004FR][0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels](by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md). Current MCP `b010_00032w_20260703` reconfirmed exact function ranges, vtable-only reachability, field offsets, current `m_pixels`/`m_ownsBuffer` names, raw constructor/EH cleanup caveats, and `0x004632c0` exclusion while preserving the physical source-file colocation caveat.
- 2026-06-28 B009 [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) support refresh:
  - Score and metadata unchanged.
  - Summary/evidence: [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) is no longer treated as a provisional `IntAlphaSurface` source-owned method. Current MCP evidence proves `ECX` is the source `AlphaMaskSurface` object and the destination `IntAlphaSurface *` is an explicit out parameter, so this file records it only as construction/use-site evidence for the `IntAlphaSurface` vtable/layout.
- 2026-05-30: Raised completion/confidence from `0/0` to `74/84`. Previously the file page had recovered method/vtable evidence but no score and a stale note about the memory filename ending at `0x004632b0`; it now links the canonical `0x00463270-0x004632b1` page and records the current IDA MCP release/destructor recheck.
- 2026-06-04: Raised completion/confidence from `74/84` to `84/88` and filled `PROPOSED_RECONSTRUCTION_PATH` with `NexusTK/render/`.
  - Before: the page still had a blank validator path, stale one-method import wording, and older evidence that did not capture the live tail-chunk ownership for `sub_4623C0`.
  - After: the page records the provisional render placement, removes importer-derived evidence, links the canonical `0x004623c0-0x00462514` by-memory page, and documents the current IDA boundaries, vtable dwords, active constructor callers, raw-default-constructor caveat, and EH-only cleanup chunk.
  - Summary/evidence: live IDA MCP confirms the destructor/release slot behavior and vtable-only xrefs, proves the active `0x00462170` constructor/helper with four callers, proves `0x00462120` remains raw/no-xref code, and proves `0x00462230` is an EH tail chunk owned by `sub_4623C0`. Completion/confidence remain below final-code levels because the final source split between `IntAlphaSurface`, `AlphaMaskSurface`, and a broader surface module is still unresolved.
- 2026-06-07 Agent-A002 Batch 091 parent-gate refresh:
  - Before: `84/88`, just below the strict parent-side completion gate for [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md).
  - Changed to: `85/88`.
  - Summary/evidence: live IDA MCP reconfirmed the active constructor/helper, raw default-constructor caveat, release/destructor vtable-only dispatch, exact vtable dwords, and `0x004632c0` exclusion. The page now clears the direct file-parent gate for the class, but confidence and final C++ remain capped by the unresolved `IntAlphaSurface` versus `AlphaMaskSurface` source split.
- 2026-06-08 B001/supervisor RTTI ownership application:
  - Scores unchanged at `85/88`.
  - Summary/evidence: recorded that [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md) now attaches to [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md) on RTTI evidence. The file-level caveat remains: original source colocation with `AlphaMaskSurface.cpp` or a broader render surface file is still not proven.
