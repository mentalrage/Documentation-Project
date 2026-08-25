*** UID:0001U7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct EffectFrameRecord
{
    int frameResourceId;
    int timerDelayAndRenderArg;
    float renderScalar;
    int lightingAndRenderArg;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EffectFrameRecord

## Status

- Confidence: strong for size, read pattern, ownership lifecycle, and runtime consumption; medium for final source-facing field names.
- Owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
- Autogen parent: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), emitted before dependent descriptor and method code at position `1`.
- Source resource: `EFFECT.TBL`.
- Size: `0x10` bytes.
- Rebuild handling: `resource-derived` source declaration/POD layout owned by the effect image-library module.

## Layout

```text
EffectFrameRecord
  +0x00  int frameResourceId
  +0x04  int timerDelayAndRenderArg
  +0x08  float renderScalar
  +0x0c  int lightingAndRenderArg
```

## Notes

- `EffectObjImageLib::LoadEffectTables` allocates one array for the primary frame sequence and one array for the secondary frame sequence in each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor.
- The loader reads each `EffectFrameRecord` as four fields: integer, integer, float, integer. IDA names the float read helper separately from the integer read helper.
- Destructors free these arrays through the owning [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) pointers. The record does not appear to own further heap data.
- Field names above are provisional documentation names. They are based on runtime use, not recovered original symbols: `+0x00` selects the effect frame resource, `+0x04` participates in both render calls and next-frame timer scheduling, `+0x08` is passed as the render float, and `+0x0c` participates in render calls plus lighting/effect-update behavior.

## Ownership And Consumers

- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) is the producer for both descriptor-owned frame arrays. Its frame-read table shows the same four-read `0x10` entry shape for both arrays and latches the image-library load/error byte when any integer/float read fails.
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) stores the two array pointers and their counts/ranges. The current `primary` and `secondary` labels are documentation names that follow the two independent loader/destructor families, not final authoring-tool terms.
- [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) frees the secondary pointer at descriptor `+0x1c`, clears its count/ranges at `+0x28/+0x2c/+0x30`, then frees the primary pointer at `+0x04` and clears `+0x10/+0x14/+0x18`.
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) copies the containing descriptor by value. That accessor preserves these frame-array pointers in the copied descriptor; it does not copy or reinterpret individual `EffectFrameRecord` entries.
- Live IDA MCP on 2026-06-11 shows `GetEffectInfo` is called from the map/effect-object setup paths at `0x0050e320`, `0x0050e850`, and `0x005a2e00`. The first two paths copy an `EffectInfo` descriptor, pass it through the create/apply helper at `0x0050ea30`, and construct an `EffectObjectPane`.
- The `EffectObjectPane` constructor at `0x005387b0` receives a copied descriptor and selects one of the two 24-byte frame-sequence headers. It copies the chosen `EffectFrameRecord *`, count, and range/loop fields into the runtime object at offsets `+0x12c..+0x143`, initializes current-frame state at `+0x144`, and records the descriptor id at `+0x148`.
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) EffectObjectPane core methods consume the copied frame sequence by indexing `frameBase + currentFrame * 0x10`. Bounds methods at `0x005388c0` and `0x00538960` pass all four record fields to [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md). The render method at `0x00538af0` passes the same four fields to [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md), preserving the float at `+0x08`.
- The update method at `0x005389d0` uses the current record's `+0x04` value when scheduling the next timer and the `+0x0c` value for lighting/effect update behavior. That closes the prior gap that the array entries were only known from loader/destructor evidence.
- 2026-06-16 live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the consumer chain: `EffectObjectPane` construction at `0x005387b0` copies either descriptor header into `+0x12c..+0x143`; `0x00538af0` indexes `base + currentFrame * 0x10` and forwards `*entry`, `entry[1]`, `entry[2]`, and `entry[3]` to `RenderEffectFrame`; `0x005389d0` reads the same stride and uses `+0x04` for the timer/sound scheduling path and `+0x0c` for lighting/effect behavior.

## Boundary And Naming Caveats

- Keep this record distinct from [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md). `EffectFrameRecord` comes from variable-length arrays embedded in `EFFECT.TBL` descriptors, while `EffectPixMapInfo` is the separate four-byte `EFFECT.FRM` remap consumed by [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md).
- The third field is strongly typed as a float by the loader helper and is passed to `RenderEffectFrame` as the draw/render float. Its original source name is still open, so avoid final names such as alpha, scale, or speed until the renderer signature itself is fully rewritten.
- `timerDelayAndRenderArg` and `lightingAndRenderArg` intentionally carry dual-role names because both values are also forwarded into render/bounds helpers. Do not collapse them to pure animation timing or pure lighting names until the complete `RenderEffectFrame` parameter contract is final.
- Generated-output check: active `source-3/simroot_v2/class_EffectObjImageLib.cpp` now contains `RenderEffectFrame`, destructor, `GetEffectInfo`, and `LoadEffectTables`, but it still does not provide a durable source-quality `EffectFrameRecord` declaration. It uses helper names such as `ReadEffectFrameArray` / `AllocateEffectFrameArray` without proving original member names, so the documentation names above remain conservative.
- No nested ownership has been observed inside the record. Cleanup is array-level through [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), so each entry should remain a plain four-scalar POD layout for now.
- Direct parent gate: this is a file-level `EFFECT.TBL` resource POD owned by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), not an `EffectObjImageLib` object-layout field and not a standalone runtime class. The by-file parent is `89/86`, and this child is now `86/89`, so the strict `85/85` assignment gate clears without bypassing a narrower semantic owner.

## IDA Evidence

- 2026-05-31 IDA MCP `decompile 0x004de7d0` confirms both descriptor frame loops allocate `16 * count` bytes.
- The same decompilation shows four reads per frame record: integer at `+0x00`, integer at `+0x04`, float at `+0x08`, and integer at `+0x0c`.
- IDA destructor decompilation at `0x004de050` and `0x004e62f0` frees both frame-array pointers from each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor.
- 2026-06-11 live IDA MCP `callers 0x004de3e0` confirms descriptor-copy callers at `0x0050e320`, `0x0050e850`, and `0x005a2e00`.
- 2026-06-11 live IDA MCP decompilation of `0x0050e320`, `0x0050e850`, `0x0050ea30`, and `0x005387b0` confirms descriptor copies flow into `EffectObjectPane` construction and that the constructor copies one of the two frame-sequence headers into runtime fields.
- 2026-06-11 live IDA MCP decompilation of `0x005388c0`, `0x00538960`, `0x005389d0`, and `0x00538af0` confirms per-frame indexing with `0x10` stride and downstream use of all four fields in bounds/render/update behavior.
- 2026-06-16 live IDA MCP `analyze_function` reconfirmed `RenderEffectFrame` at `0x004de190-0x004de29f`, `EffectObjectPane` construction at `0x005387b0-0x0053887c`, update at `0x005389d0-0x00538aef`, and render at `0x00538af0-0x00538baa`. The render decompilation still forwards the four `0x10`-stride fields into the effect image-library renderer, while the update decompilation still reads `entry+0x04` and `entry+0x0c` through the same active-frame index.

## Score Rationale

- Completion is `88` because the page records the producer, descriptor ownership, accessor behavior, destructor lifecycle, runtime descriptor-copy flow, `EffectObjectPane` frame-sequence copy, per-frame bounds/render/update consumers, explicit `EFFECT.FRM` boundary, generated-output check, emitter order, and formal first-draft POD declaration.
- Confidence is `90` because the record size, read helpers, array stride, cleanup ownership, constructor copy path, runtime field use, and active generated-output limitations are cross-confirmed by loader/destructor/accessor pages plus live IDA MCP checks of the effect-object setup and animation/render methods. Confidence remains capped by unresolved original source-facing field names.

## Cross-References

- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md) EffectObjectPane core runtime consumer aggregate
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)

## Changes

- 2026-06-30 B008 empty-emitter implementation callback:
  - Before: `86/89`, blank formal block and no emitter position.
  - After: `88/90`, formal `EffectFrameRecord` POD declaration attached at emitter position `1` under [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: accepted report used current MCP session `supervisor_resume_20260629`, server-health call id `3`, loader/deconstructor/accessor/consumer evidence, `0x10` stride, integer/integer/float/integer read order, bounds/render/update consumers, and `EFFECT.TBL` ownership to make this the first emitted support type. Field names remain documentation names rather than recovered original symbols.

- 2026-06-16 A002 Goal2 type-confidence refresh:
  - Before: `85/88`.
  - After: `86/89`; owner/emitter remain [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), with final C++ still blank.
  - Summary/evidence: live IDA MCP session `b001_mappane_0001AW_20260616` reconfirmed the `0x10`-stride consumer path through `EffectObjectPane` construction, update, and render into `RenderEffectFrame`. Active generated `class_EffectObjImageLib.cpp` was checked and now includes the relevant methods, but it still lacks a durable source-quality `EffectFrameRecord` declaration or original member names.
- 2026-06-11 A002 assigned coverage pass:
  - Before: the page was `78/86`, reconstructable but unassigned, and stopped at loader/destructor/accessor evidence.
  - After: raised to `85/88` and attached to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md).
  - Summary/evidence: live IDA MCP traced `GetEffectInfo` copies through map/effect setup into `EffectObjectPane` construction, then into bounds/render/update consumers that index `EffectFrameRecord` entries by `0x10` stride. The direct file parent is already `89/86`, so the child/direct-parent `85/85` gate clears for the file-level `EFFECT.TBL` POD declaration. B008's 2026-06-30 callback later attached the formal POD declaration with conservative field names.
- 2026-05-31 IDA evidence and scoring update:
  - Before: metadata was unevaluated (`0/0`) and reconstructability was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`, with completion/confidence set to `72/84`.
  - Summary/evidence: IDA MCP loader and destructor checks confirm the 16-byte record size, read pattern, owning arrays, and lack of nested heap ownership; final semantic names for the four fields remain provisional.
- 2026-06-07 A006 documentation pass:
  - Before: the page was `72/84` and focused on size/read/destructor evidence.
  - After: raised to `78/86`.
  - Summary/evidence: added the loader producer relationship, `EffectInfo` pointer/count ownership, `GetEffectInfo` descriptor-copy behavior, destructor cleanup offsets for both frame-array families, explicit `EFFECT.FRM` remap boundary, and naming caveats for the unresolved scalar fields.
