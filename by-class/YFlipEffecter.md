*** UID:0000GD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class YFlipEffecter : public PixelEffecter
{
public:
    YFlipEffecter();
    virtual ~YFlipEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# YFlipEffecter

## Status

- Confidence: strong for role, source-module placement, vtable identity, and exact apply-method behavior; medium-high for constructor reachability because IDA does not currently model `0x0055b4a0` as a function object.
- Proposed source: `render/Effects.cpp`
- Current memory evidence: exact constructor child [UID:0003OA][0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor](by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md), exact apply child [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md), and parent cluster [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`YFlipEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that flips map rendering vertically by drawing source scanlines from bottom to top into the destination region. It uses `MapPane` scanline buffer state and per-line blit calls.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0003OA][0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor](by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md) | constructor | Raw IDA disassembly confirms the `YFlipEffecter` vtable store, return, and alignment before the IDA-modeled `ApplyEffect` body at `0x0055b4c0`. IDA still lacks a function object or direct caller for the start. |
| [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md) | `ApplyEffect` | Uses render context `dword_67A764` and per-scanline `sub_4ba250` calls to draw the source rectangle vertically flipped against the 384-pixel render height. |

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `89/85`, has proposed path `NexusTK/render/`, and lists `YFlipEffecter` in the runtime effecter module.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) records the map/pixel displacement block, the raw `YFlipEffecter` constructor bytes, and the modeled `sub_55B4C0` runtime effect body.
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records `0x0055b4a0-0x0055b4b3` as valid constructor-shaped raw code: install vtable `0x00623c2c`, return `this`, then align before the modeled `ApplyEffect` routine.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) tie the `YFlipEffecter` vtable at `0x00623c2c` to constructor store `0x0055b4a9` inside the ScreenEffecter family.
- [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md) documents the current apply-body evidence: modeled size `0x103`, vtable data ref at `0x00623c48`, `retn 0Ch` at `0x0055b5c0`, padding from `0x0055b5c3`, render-context use through `dword_67A764`, and per-scanline calls to `sub_4ba250`.
- The class remains below final-source quality because render helper names, rectangle type names, exact virtual signature, and the origin of the 384-pixel height constant are still provisional.

## Autogen Status

- Reconstructable: true for the runtime effecter class.
- Parent: [UID:0000IZ][Effects](by-file/Effects.md). The parent path and confidence are sufficient for attachment.
- Code: intentionally blank. Constructor identity and `ApplyEffect` behavior are strong enough for documentation and routing, but helper/type names and final source shape remain below the active `90/90+` code-entry gate.

## Score Rationale

- Completion is raised to 86 because ownership, exact constructor child, exact apply-method child, vtable evidence, parent attachment, boundary bytes, and C++ blockers are now documented on the class page.
- Confidence is raised to 88 because live IDA evidence agrees across the Effects file, runtime cluster, exact children, vtable family, and exact vtable-data child.
- Remaining gaps are final field/local names, render helper/type names, exact virtual signature, and final source spelling.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0003OA][0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor](by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md)
- [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the `YFlipEffecter : public PixelEffecter` declaration. Current MCP keeps the raw constructor at `0x0055b4a0-0x0055b4b3` as a non-function raw start with no direct xrefs, while exact apply child [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md) owns the modeled `0x0055b4c0-0x0055b5c3` vertical scanline flip behavior. The declaration is safe from the class/vtable/child evidence; constructor and apply bodies must remain exact-child output.

## Changes

- 2026-06-14 A001 exact-child/live-evidence refresh:
  - Before: scored `80/84`; the page had no focused exact by-memory child for `ApplyEffect`, used an old `0x0055b4c0-0x0055b5c2` range, and still referenced current recovered-source output.
  - After: scored `86/88`; added exact constructor child [UID:0003OA][0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor](by-memory/0x0055b4a0-0x0055b4b3.YFlipEffecterRawConstructor.md), exact apply child [UID:0003OB][0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect](by-memory/0x0055b4c0-0x0055b5c3.YFlipEffecterApplyEffect.md), and refreshed the boundary/behavior evidence.
  - Evidence: live IDA MCP `lookup_funcs`, `disasm`, `decompile`, `analyze_function`, `xrefs_to`, `get_int`, and `get_bytes` confirm no function/no direct refs at `0x0055b4a0`, constructor vtable store at `0x0055b4a9`, modeled `sub_55B4C0` size `0x103`, vtable slot `0x00623c48 -> 0x0055b4c0`, per-scanline flip behavior, `retn 0Ch` at `0x0055b5c0`, and padding from `0x0055b5c3`. B006 2026-06-30 now emits the class declaration while exact bodies remain with child pages.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the vertical flip effect responsibility, raw constructor/apply method map, effect/render cross-references, and the unresolved IDA function-object boundary for `0x0055b4a0`.
- 2026-06-02: Raised to `80/84`, marked reconstructable, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added parent, runtime-cluster, constructor-boundary, vtable-family, exact vtable-data, and score-rationale evidence. Formal output was withheld pending a focused `ApplyEffect` exact-range pass; B006 2026-06-30 supersedes that with declaration-only class output.
