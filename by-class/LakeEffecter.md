*** UID:000070 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class LakeEffecter : public PixelEffecter
{
public:
    explicit LakeEffecter(float blendFactor);
    virtual ~LakeEffecter();

    virtual void ApplyEffect(GrafPort *destination,
                             const RectBounds *sourceRect,
                             const RectBounds *destinationRect);

private:
    float m_blendFactor;
    unsigned int m_lastRenderTick;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LakeEffecter

## Status

- Confidence: strong for class identity, vtable slot ownership, constructor/destructor boundaries, and waterline/reflection behavior; medium-high for final field names and source-level parameter names.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_LakeEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- Exact memory pages: [UID:0003HA][0x0055b810-0x0055b851.LakeEffecterConstructor](by-memory/0x0055b810-0x0055b851.LakeEffecterConstructor.md), [UID:0003HC][0x0055b860-0x0055b866.LakeEffecterResetVtable](by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md), [UID:0003HB][0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect](by-memory/0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect.md), and [UID:0003HD][0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor](by-memory/0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor.md)
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md). Batch 304 raises this class to `86/88`, and the direct file parent is now `90/88`, so both sides clear the strict 85/85 gate. Formal C++ emits the class declaration; exact constructor/apply/destructor bodies remain owned by their exact child pages.

## Responsibility

`LakeEffecter` is a [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md) subclass that renders a waterline/reflection effect over the parcel/map pane. It clamps a blend factor during construction, captures a timer/base offset from `dword_67AB80 + 0x18`, computes a waterline between the visible top and bottom bounds, renders the source region above the waterline, then emits reflected one-line strips below it.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| [UID:0003HA][0x0055b810-0x0055b851.LakeEffecterConstructor](by-memory/0x0055b810-0x0055b851.LakeEffecterConstructor.md) | constructor | Raw non-function-object constructor bytes: clamps the caller float between constants at `0x00623d40` and [UID:0003CE][0x00620c68-0x00620c6c.SharedMinimumFloatConstant](by-memory/0x00620c68-0x00620c6c.SharedMinimumFloatConstant.md), stores the `LakeEffecter` vtable at `0x0055b829`, writes the clamped value at `this+4`, stores `*(dword_67AB80 + 0x18) - 0x3c` at `this+8`, returns `this`, and ends with `retn 4`. |
| [UID:0003HC][0x0055b860-0x0055b866.LakeEffecterResetVtable](by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md) | non-deleting destructor/reset helper | Modeled seven-byte helper resets the primary vtable to `ScreenEffecter` and returns; it is aligned before `ApplyLakeEffect`. |
| [UID:0003HB][0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect](by-memory/0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect.md) | `ApplyLakeEffect` | Uses parcel visible bounds, tile margins, and repeated `MapPane::RenderRegion` calls to draw/reflection rows. |
| [UID:0003HD][0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor](by-memory/0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor.md) | scalar deleting destructor | Resets to `ScreenEffecter` base vtable and conditionally deletes `0x0c`/12 bytes of storage when the scalar-deleting flag is set. |

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `88/80`, assigned to `NexusTK/render/`, and lists `LakeEffecter` as the waterline/reflection render effect in the runtime effecter module.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `78/82`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it places the lake constructor and apply body inside the water/lake effect span and records the `0x0055b870` callee check through `0x004ba250`.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the `LakeEffecter` vtable base at `0x00623cf8` and the constructor store at `0x0055b829`.
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md) records the raw constructor bytes at `0x0055b810-0x0055b851`: float clamp constants, vtable store, clamped blend/timer state, and `retn 4`.
- 2026-06-10 IDA MCP recheck against MD5 `4247e04e20b65d6414c7238aa8ff5515`:
  - `lookup_funcs` still reports `0x0055b810` as `Not a function`, while `0x0055b860`, `0x0055b870`, and `0x0055bbc0` are modeled as `sub_55B860` size `0x7`, `sub_55B870` size `0x1b2`, and `sub_55BBC0` size `0x24`.
  - `xrefs_to 0x00623cf8` reports the constructor vtable store at `0x0055b829`; `xrefs_to 0x0055b870` and `0x0055bbc0` come from the `LakeEffecter` vtable entries at `0x00623d14` and `0x00623d10`.
  - `callers 0x0055b870` and `callers 0x0055bbc0` are empty, matching virtual-only dispatch through the table; `callees 0x0055b870` are the render-region helper `0x004ba250` and the security-cookie check, while `0x0055bbc0` calls the delete helper `0x005c7526`.
  - `decompile 0x0055b870` confirms the visible-bounds query from `dword_67A764`, tile-margin adjustments through `word_66DA9C/word_66DAA0`, blend-driven waterline computation from `this+4`, an initial clipped render call, and the reflection loop that copies one-line source/destination rectangles while increasing the strip thickness by `0.25`.
- 2026-06-12 Batch 304 IDA MCP refresh:
  - `lookup_funcs` reports `0x0055b810` and `0x0055b829` as `Not a function`, while `0x0055b860`, `0x0055b870`, and `0x0055bbc0` are modeled as `sub_55B860` size `0x7`/7, `sub_55B870` size `0x1b2`/434, and `sub_55BBC0` size `0x24`/36.
  - `make_signature_for_range 0x0055b810-0x0055b851` returns a unique 65-byte constructor signature, and `trace_data_flow 0x00623cf8` ties the class vtable to the raw store at `0x0055b829`.
  - `trace_data_flow 0x00623d10` and `0x00623d14` confirm the scalar deleting destructor and apply body slots as `dd offset sub_55BBC0` and `dd offset sub_55B870`.
  - `xrefs_to` reports no direct xrefs to the raw constructor or reset helper, and only vtable/data refs to the apply body and scalar deleting destructor, matching virtual-only dispatch.
  - Exact child pages now cover the constructor, reset helper, apply body, and scalar deleting destructor, so the class no longer depends only on the broad runtime cluster for method evidence.

## Parent-Chain Decision

The actual direct parent is [UID:0000IZ][Effects](by-file/Effects.md). The file page already clears `89/85` and groups the runtime `ScreenEffecter`/`PixelEffecter` hierarchy under `render/Effects.cpp`. Batch 304 raises `LakeEffecter` to `86/88` with exact by-memory children and current IDA vtable/method evidence, so the class now routes to the file parent. The exact Lake memory pages route to this class because they are class-specific methods and the class clears the strict gate.

## Score Rationale

Completion is 86 because the class has exact memory pages for every known method body, vtable slot evidence, raw constructor uniqueness, destructor/reset coverage, waterline/reflection behavior, source parent, and stale generated-data caveats. Confidence is 88 because IDA confirms the important boundaries and slot ownership, while final field names, rectangle parameter names, and the exact original `Effects.cpp` versus subfolder split remain below final-source certainty.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0003HA][0x0055b810-0x0055b851.LakeEffecterConstructor](by-memory/0x0055b810-0x0055b851.LakeEffecterConstructor.md)
- [UID:0003HC][0x0055b860-0x0055b866.LakeEffecterResetVtable](by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md)
- [UID:0003HB][0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect](by-memory/0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect.md)
- [UID:0003HD][0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor](by-memory/0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor.md)

## 2026-06-30 B006 Empty-Emitter Callback

Formal C++ now emits the `LakeEffecter : public PixelEffecter` class declaration with `m_blendFactor` and `m_lastRenderTick`. Current evidence keeps the executable details on exact child pages: raw constructor [UID:0003HA][0x0055b810-0x0055b851.LakeEffecterConstructor](by-memory/0x0055b810-0x0055b851.LakeEffecterConstructor.md) clamps the blend factor and stores the `0x00623cf8` vtable; reset helper [UID:0003HC][0x0055b860-0x0055b866.LakeEffecterResetVtable](by-memory/0x0055b860-0x0055b866.LakeEffecterResetVtable.md) is the modeled seven-byte vtable reset; apply body [UID:0003HB][0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect](by-memory/0x0055b870-0x0055ba21.LakeEffecterApplyLakeEffect.md) owns the waterline/reflection loop; scalar deleting destructor [UID:0003HD][0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor](by-memory/0x0055bbc0-0x0055bbe3.LakeEffecterScalarDeletingDestructor.md) is compiler-generated cleanup. The class page declaration is safe, but method bodies remain exact-child output rather than duplicate class-page output.

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/76`. Summary: the water/reflection effect role and major methods are documented, but the page remains below high completion because the constructor boundary and final source placement still need more confirmation. Evidence: IDA-backed method address table, PixelEffecter relationship, parcel/map rendering behavior, and ScreenEffecter cluster references.
- 2026-06-03 parent attachment pass:
  - What existed before: the page documented the lake/reflection role and method ranges but remained unattached with blank reconstructable metadata and `72/76` scoring.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime aggregate, vtable-family page, and small-constructor boundary page all support `render/Effects.cpp` ownership and the `LakeEffecter` identity. At that time formal output was withheld because the constructor was still a raw/non-modeled body and final field/local names were below the 95+ reconstruction gate; B006 2026-06-30 supersedes that with declaration-only output.
- 2026-06-10 IDA evidence and gate repair:
  - What existed before: the page was scored `76/82`, attached to [UID:0000IZ][Effects](by-file/Effects.md), and summarized only the constructor, apply body, and scalar deleting destructor.
  - Changed to: raised the page to `82/86`, documented the reset helper at `0x0055b860`, added current IDA lookup/xref/caller/callee/decompile evidence, and cleared `AUTOGEN_PARENT_UID` because this child and the Effects file parent do not both satisfy the strict `85/85` assignment gate.
  - Summary/evidence: 2026-06-10 IDA MCP confirms the raw constructor bytes, `LakeEffecter` vtable-store/xref chain, virtual-only dispatch entries, render-region/reflection loop behavior, and scalar-deleting destructor semantics. Method bodies remain withheld because field and parameter names still need a final-source audit.
- 2026-06-12 Agent-A001 Batch 304:
  - What existed before: the page was `82/86`, parentless, and depended on the broad runtime cluster plus item-level constructor notes rather than exact Lake method children.
  - Changed to: raised to `86/88`, attached to [UID:0000IZ][Effects](by-file/Effects.md), and added exact memory children for the constructor, reset helper, apply body, and scalar deleting destructor.
  - Summary/evidence: live IDA MCP confirms unique raw constructor bytes, vtable store `0x0055b829`, modeled helper/body/destructor sizes, vtable slots `0x00623d10` and `0x00623d14`, virtual-only xrefs, render-region/reflection-loop behavior, and scalar-delete storage size.
