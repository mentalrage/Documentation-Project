** TARGET-REPORT-UID:0002IU **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 LightObjImageLib Source-Quality Audit

Assignment: `B003-goal2-lightobjimagelib-source-quality-0002IU-00017Q-0002IW-0002IX-0002IY-20260617`

Agent: B003

Date: 2026-06-17

Scope: report-only audit for [UID:0002IU], [UID:00017Q], [UID:0002IW], [UID:0002IX], and [UID:0002IY]. I did not edit by-memory docs, support by-* docs, generated files, source files, IDA databases, or `by-memory/-coverage-report.md`.

## Target Recommendations

| UID | Target | Current | Recommended | Owner / emitter | Reconstructable | C++ recommendation |
| --- | --- | ---: | ---: | --- | --- | --- |
| [UID:0002IU] | `0x004df7e0-0x004dfaa6.LightObjImageLibConstructor` | `82/90` | `88/92` | keep `CANONICAL_OWNER:0000KP`, `EMITTER_UIDS:0000KP` | keep `TRUE` | Populate first-draft constructor C++. |
| [UID:00017Q] | `0x004dfab0-0x004dfb36.LightObjImageLibDestructor` | `82/90` | `88/92` | keep `CANONICAL_OWNER:0000KP`, `EMITTER_UIDS:0000KP` | keep `TRUE` | Populate first-draft ordinary destructor C++. |
| [UID:0002IW] | `0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1` | `82/90` | `88/92` | keep `CANONICAL_OWNER:0000KP`, `EMITTER_UIDS:0000KP` | keep `TRUE` | Populate first-draft virtual draw C++ with blend mode `1`. |
| [UID:0002IX] | `0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2` | `82/90` | `88/92` | keep `CANONICAL_OWNER:0000KP`, `EMITTER_UIDS:0000KP` | keep `TRUE` | Populate first-draft virtual draw C++ with blend mode `2`. |
| [UID:0002IY] | `0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor` | `82/90` | `87/92` | keep `CANONICAL_OWNER:0000KP`, `EMITTER_UIDS:0000KP` | keep `TRUE` | Leave formal C++ blank by compiler-wrapper policy; source destructor emission belongs to [UID:00017Q]. |

The four source-authored targets should clear the active source gate now: they are reconstructable, have a nonblank emitter route to [UID:0000KP] `NexusTK/render/LightObjImageLib.cpp`, exceed the 85 combined score threshold, and no remaining source-shape blocker prevents a first draft. [UID:0002IY] also clears source-quality semantics, but it is a compiler-generated scalar deleting destructor wrapper; emitting a hand-written method for it would pollute the source model.

## Evidence Checked

- Existing primary pages:
  - `source-3/project-documentation/by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md`
  - `source-3/project-documentation/by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md`
  - `source-3/project-documentation/by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
  - `source-3/project-documentation/by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
  - `source-3/project-documentation/by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md`
- Support pages:
  - `by-file/LightObjImageLib.md`
  - `by-class/LightObjImageLib.md`
  - `by-type/by-struct/LightObjImageLibLayout.md`
  - `by-type/by-struct/LightInfo.md`
  - `by-type/by-vtable/LightObjImageLibVtable.md`
  - `by-global/g_pLightObjImageLib.md`
  - `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
  - `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
  - `by-item/DrawFrameWithBlendMode_00462E10.md`
  - `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md`
  - `by-class/DATFile.md`
  - `by-memory/0x0049c130-0x0049d2cc.DATFile.md`
  - `by-memory/0x004a5e60-0x004a609f.ParseEntries.md`
- Generated/source-lead context:
  - `source-3/project-documentation/auto-generated/NexusTK/render/LightObjImageLib.cpp`
  - `source-3/simroot_v2/class_LightObjImageLib.cpp`
  - `source-3/simroot_v2/class_AlphaMaskSurface.cpp`
- Coverage context:
  - `source-3/project-documentation/by-memory/-coverage-report.md`
- Local PE/resource context:
  - `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - `E:\2026\Resources\Read_Only\NexusTK\Data\misc.dat`
- IDA MCP was unavailable from this session (`127.0.0.1:13337` connection refused). I did not treat that as a blocker because the target pages already carry current IDA-derived decompilation/xref evidence, and the local PE/resource checks independently confirmed the byte, vtable, and padding facts that matter for this pass.

## Heuristic / Inference Reanalysis And Validation

### Source Placement, Ownership, And Emitter Route

The LightObjImageLib primary methods should remain owned and emitted by [UID:0000KP] `by-file/LightObjImageLib.md`, source path `NexusTK/render/LightObjImageLib.cpp`.

Evidence:

- The accepted [UID:0002IV] `LightObjImageLib::GetLightBounds` page already emits through [UID:0000KP], and the active generated file `auto-generated/NexusTK/render/LightObjImageLib.cpp` contains that method only.
- [UID:0000KP] owns the procedural light-image source file; [UID:000076] is the class/type aggregate and remains correct for class layout and type pages, but by-memory LightObjImageLib method pages in this cluster are consistently file-emitted.
- The constructor opens `LIGHT.TBL` and builds procedural alpha frames; it does not use EPF frame-table loader ownership. AlphaMaskSurface and DATFile helpers are dependencies, not source-placement owners.
- The draw methods are virtual slots in the `LightObjImageLib` vtable and call the shared alpha-mask blitter, but their selection/fallback/centering policy is LightObjImageLib-specific.

Rejected alternatives:

- Moving method ownership to [UID:000076] `by-class/LightObjImageLib` would be defensible as a semantic class owner in isolation, but it would diverge from the accepted [UID:0002IV] emitter precedent and current generated file route. Keep method owner/emitter `0000KP`.
- Placing constructor/draw source under `AlphaMaskSurface.cpp` is rejected. AlphaMaskSurface owns the pixel buffer, rectangle fill, gradient fill, and frame blitter helpers; LightObjImageLib owns the `LIGHT.TBL` schema, singleton, entry list, fallback row, and virtual draw dispatch.
- Treating `LIGHT.TBL` as an EPF/ImageLib table is rejected. The rows are procedural light-mask descriptors and produce `AlphaMaskSurface` frames at startup.

### Singleton / Global Naming And Lifetime

Use canonical global name `g_pLightObjImageLib`.

Evidence:

- `by-global/g_pLightObjImageLib.md` and `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md` agree on `g_pLightObjImageLib` as the canonical name.
- The constructor writes the singleton at `0x004df82b` and has a guarded clear on the constructor fallback path.
- The ordinary destructor and scalar deleting destructor both clear the singleton before base cleanup.
- The generated/Application-side alias `g_pLightObjectImageLib` is caller/generated pollution. It should not replace the canonical global spelling in LightObjImageLib support docs or emitted LightObjImageLib source.

Bounded note:

- Section mapping of `NexusTK.exe` places `0x0069b450` in zero-fill beyond initialized `.data` raw bytes, so raw disk-image reads do not corroborate any nonzero initial byte pattern for the global. This does not affect the source-level singleton policy: global storage is zero-initialized and runtime ownership is established by constructor/destructor writes.

### Vtable And Secondary Subobject Policy

The vtable evidence supports a normal `LightObjImageLib` object with an embedded `ProtectedArray<LightInfo>` subobject at `this + 0x04`, not a second independently allocated object.

Local PE vtable dwords around `0x0061b748-0x0061b768`:

```text
0x0061b748  ProtectedArray<LightInfo> RTTI
+0x0061b74c ProtectedArray<LightInfo> scalar deleting destructor
+0x0061b750 LightObjImageLib RTTI
+0x0061b754 LightObjImageLib scalar deleting destructor
+0x0061b758 inherited/shared virtual at 0x004f4b10
+0x0061b75c inherited nullsub at 0x0041b6c0
+0x0061b760 LightObjImageLib::DrawLightMode1
+0x0061b764 LightObjImageLib::DrawLightMode2
```

The constructor installs the LightObjImageLib vtable at `this + 0x00` and the adjacent `ProtectedArray<LightInfo>` vtable at `this + 0x04`. The destructors restore both vtables before freeing row storage and tail-calling base cleanup. This is compiler/layout behavior and should not be written as manual vtable assignment in first-draft C++.

### LightObjImageLib Layout

Recommended source-facing layout names:

```text
LightObjImageLib
  +0x00  LObject / LightObjImageLib vptr
  +0x04  ProtectedArray<LightInfo> lightInfoArray subobject / array vptr
  +0x08  int lightInfoCount
  +0x0c  LightInfo *lightInfoEntries
  +0x10  int lightInfoCapacity
  +0x14  LightInfo fallbackLightInfo
  sizeof at least 0x30
```

`lightInfoCapacity` is a better source-facing name than `initialOrGrowCapacity`. The constructor writes `10` there before loading `LIGHT.TBL`, and the field belongs to the embedded protected-array/list state. No current target uses it after construction, so the exact container API remains bounded; however, "capacity" is a high-probability source name and clearer than a temporal name.

### LightInfo / LIGHT.TBL Schema

Recommended `LightInfo` schema:

```text
LightInfo
  +0x00  int tableId
  +0x04  int innerRadius
  +0x08  int radiusX
  +0x0c  int radiusY
  +0x10  float brightness
  +0x14  float blendScale
  +0x18  AlphaMaskSurface *generatedFrame
  sizeof = 0x1c
```

The key correction is `+0x04 innerRadius`, not `lightSource`.

Evidence:

- The constructor reads four integer fields and two float fields for each `LIGHT.TBL` row, then stores a pointer at `+0x18`. The allocation stride is `0x1c`.
- Positive `radiusX` and `radiusY` allocate a generated frame of `(2 * radiusX + 1)` by `(2 * radiusY + 1)`.
- The constructor calls `AlphaMaskSurface::GetCenterPoint`, then passes the returned center coordinates into `AlphaMaskSurface::FillEllipticGradient`.
- The call to `FillEllipticGradient` receives the row fields in this semantic order after the computed center: `+0x04`, `+0x08`, `+0x0c`, converted `+0x10`, literal outer alpha `0`, `+0x14`, literal mode `0`.
- Existing AlphaMaskSurface source-lead naming and docs identify `0x00462870` as `FillEllipticGradient(centerX, centerY, innerRadius, xRadius, yRadius, innerAlpha, outerAlpha, blendScale, blendMode)`.
- [UID:0002IV] `GetLightBounds` uses only `radiusX` and `radiusY` to return local bounds `[-radiusX, -radiusY, radiusX + 1, radiusY + 1]`.
- The draw methods consume only `generatedFrame`, frame dimensions, and blend mode; they do not reinterpret the first two integer fields.
- Destructors iterate rows and delete `generatedFrame` at `+0x18`; they do not use the scalar row fields.

Rejected alternatives:

- `+0x04 lightSource`: rejected. The binary passes this field to `FillEllipticGradient` in the `innerRadius` position; no source/source-file selector, asset ID, or external table lookup uses it.
- `+0x04 centerX` or `+0x04 centerY`: rejected. Center is computed from the allocated surface by `GetCenterPoint`; no table field supplies the generated-frame center.
- `+0x00 lightId` as a fully proven name: not fully proven. The first integer is read and preserved but has no recovered runtime consumer in constructor, destructor, bounds, or draw paths. `tableId` is the best high-probability source-facing name because it is the row key/identifier from `LIGHT.TBL`, but the report should preserve the evidence boundary: its exact original spelling is not known.
- `+0x14 blendValue`: too vague. The float flows into `FillEllipticGradient` as the scale controlling the elliptical falloff after the inner radius; `blendScale` matches the AlphaMaskSurface helper's recovered argument name and is the better source-facing name.

Fallback row:

- The constructor copies four dwords from `0x00619660`; local PE bytes confirm the seed is four `0xffffffff` dwords.
- The constructor then zeros both float fields and the frame pointer.
- Because `fallbackLightInfo.generatedFrame` is null, bounds and draw calls for invalid indices return empty/no-op behavior despite negative scalar fallback fields.

Resource-package check:

- `LIGHT.TBL` is present in `E:\2026\Resources\Read_Only\NexusTK\Data\misc.dat` as a raw member of size `3080` bytes in the local resource package.
- A direct attempt to decode the raw member bytes with the documented `ParseEntries` algorithm did not validate (`allValid=False` and nonsensical first scalar), which means the archive member bytes need the normal `DATFile` open/read path or another archive-layer transform before scalar decoding. I therefore do not use raw decoded row values as evidence.
- The schema recommendation does not depend on that failed raw-member decode. It is based on constructor dataflow into the AlphaMaskSurface helper, established DATFile read ordering, row stride, and downstream consumers.

### DATFile Helper Names

For LightObjImageLib-facing first-draft C++, use local wrapper names:

```cpp
ReadEncodedTableInt(&lightTable, &value);
ReadEncodedTableFloat(&lightTable, &value);
```

Evidence:

- Current DATFile docs name `0x0049c4a0` as `ReadAllEntries` and `0x0049c4f0` as `ReadAllEntriesAlt`.
- Image-library constructors consistently use `0x0049c4a0` for integer-like scalar table fields and `0x0049c4f0` for float scalar table fields.
- Both wrappers read eight bytes, pass `GetSize() >> 1` to `ParseEntries`, and output one decoded scalar into the caller-supplied location. The global DATFile names are not ideal for consumer-level C++ because they sound bulk/table-wide rather than scalar.

Rejected alternative:

- Do not globally rename DATFile helpers in this LightObjImageLib report. A DATFile owner pass should decide final DATFile method names. For this file, `ReadEncodedTableInt` and `ReadEncodedTableFloat` can be documented as source-facing local/helper aliases used to express the constructor.

### AlphaMaskSurface And Draw Helper Names

Use these dependency names in first-draft C++ and support docs:

```text
0x00462170  AlphaMaskSurface::AlphaMaskSurface(int width, int height)
0x004622d0  AlphaMaskSurface::GetCenterPoint(int *outCenter)
0x00462520  AlphaMaskSurface::ApplyRectAlpha(const RectBounds *rect, unsigned char alpha, int blendMode)
0x00462870  AlphaMaskSurface::FillEllipticGradient(int centerX, int centerY, int innerRadius, int radiusX, int radiusY, unsigned char innerAlpha, unsigned char outerAlpha, float blendScale, int blendMode)
0x00462e10  DrawFrameWithBlendMode(AlphaMaskSurface *target, const RectBounds *destinationRect, AlphaMaskSurface *sourceFrame, const RectBounds *sourceRect, int blendMode)
0x004b7c50  InitRectBounds(RectBounds *rect, int left, int top, int right, int bottom)
```

Evidence:

- `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md` names the constructor, `GetCenterPoint`, `ApplyRectAlpha`, and `FillEllipticGradient` ranges.
- `by-item/DrawFrameWithBlendMode_00462E10.md` and `by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md` name the shared frame blitter and document mode `0` copy/replace, mode `1` add, and mode `2` subtract.
- The draw-mode methods have exactly two rel32 calls to `0x00462e10`, one from each mode wrapper, and pass literal blend modes `1` and `2`.

### Constructor Behavior And Cleanup Chunks

[UID:0002IU] is source-ready.

Validated behavior:

- Constructs the base `LObject`.
- Sets `g_pLightObjImageLib = this`, with a guarded clear path if the embedded array pointer setup fails.
- Installs the LightObjImageLib and embedded `ProtectedArray<LightInfo>` vtables as compiler output.
- Initializes the embedded list state: count `0`, entries `0`, capacity `10`.
- Seeds `fallbackLightInfo` as `{-1, -1, -1, -1, 0.0f, 0.0f, nullptr}`.
- Constructs a local `DATFile`, opens `LIGHT.TBL`, reads the row count, and grows the entry buffer to `count * sizeof(LightInfo)` when count is positive and different from the current count.
- Preserves existing rows with `memmove` before freeing the old entry buffer, matching a protected-array resize/grow implementation rather than a pure one-shot allocation.
- Reads each row as four encoded integers, then two encoded floats.
- Allocates an `AlphaMaskSurface` only when `radiusX > 0 && radiusY > 0`.
- Initializes the generated frame as a full rect with alpha `0`, obtains the center from the generated frame, then calls `FillEllipticGradient` with `innerRadius`, `radiusX`, `radiusY`, `innerAlpha = int(brightness * 32.0f + 0.5f)`, `outerAlpha = 0`, `blendScale`, and mode `0`.
- Writes the completed `LightInfo` record into the entry slot. The fallback slot remains only for out-of-range access and exception/fallback paths; normal constructor loop indices are in range after resize.
- Destroys the local `DATFile`.
- External cleanup chunks at `0x004e5b20-0x004e5b30` and `0x006001c2-0x0060021c` represent compiler exception-unwind/cleanup support. The latter reaches the singleton-clear helper at `0x004e5bb0`. These are not hand-authored source methods.

Remaining uncertainty bounded:

- Exact original helper spelling for DAT scalar reads is not known. This affects source polish but not source readiness; local aliases are defensible.
- Exact original member spelling for `tableId` and `lightInfoCapacity` is inferred. Their semantics are bounded enough for first-draft C++.

Score impact: raise [UID:0002IU] to `88/92` and populate formal C++.

### Ordinary Destructor Behavior

[UID:00017Q] is source-ready despite the raw start not being an IDA function object.

Validated behavior:

- Exact raw range is `0x004dfab0-0x004dfb36`, followed by ten `0xcc` bytes.
- Restores the LightObjImageLib vtable and embedded `ProtectedArray<LightInfo>` vtable as compiler output.
- Iterates `lightInfoEntries` by `lightInfoCount` with stride `0x1c`.
- Deletes each non-null `generatedFrame` through its virtual destructor with delete flag `1`.
- Frees the entry buffer with the CRT free helper.
- Clears `g_pLightObjImageLib`.
- Tail-calls the base cleanup at `0x004f4a90`.
- Does not apply an optional delete to `this`; that work belongs to [UID:0002IY].

Rejected alternatives:

- Leaving [UID:00017Q] blank because IDA does not model it as a function is rejected. The raw bytes, scalar deleting destructor parity, padding, and source destructor semantics are sufficiently established.
- Emitting explicit vtable resets or a base destructor tail call in source C++ is rejected. Those are compiler artifacts; source should express `~LightObjImageLib()` cleanup.

Score impact: raise [UID:00017Q] to `88/92` and populate formal C++.

### Draw Mode 1 And Draw Mode 2 Behavior

[UID:0002IW] and [UID:0002IX] are source-ready.

Common behavior:

- Select `fallbackLightInfo` by default.
- If `lightIndex >= 0 && lightIndex < lightInfoCount`, select `lightInfoEntries[lightIndex]`.
- Return immediately if `generatedFrame == 0`.
- Read source frame dimensions from the generated frame.
- Build a source rect `0, 0, width, height`.
- Build a destination rect centered at the caller-provided point.
- Call `DrawFrameWithBlendMode(target, &destinationRect, generatedFrame, &sourceRect, mode)`.

Differences:

- [UID:0002IW] passes blend mode `1`, which the shared helper documents as additive byte-mask/frame blending.
- [UID:0002IX] passes blend mode `2`, which the shared helper documents as subtractive byte-mask/frame blending.

Rejected alternatives:

- Collapsing both methods into one emitted helper is not recommended for the by-memory first draft. The binary has two separate vtable slots and two separate `0xaa` bodies. A later source cleanup can factor a private helper if the source style calls for it, but each formal block should be explicit.
- Treating the draw target as an EPF frame or generic surface is rejected. The dependency path is `AlphaMaskSurface` and the callee is `DrawFrameWithBlendMode`, which clips and blends byte alpha masks.

Score impact: raise [UID:0002IW] and [UID:0002IX] to `88/92` and populate formal C++.

### Scalar Deleting Destructor Policy

[UID:0002IY] is source-understood but should not receive hand-authored formal C++.

Evidence:

- Exact range is `0x004e65e0-0x004e669d`, followed by three `0xcc` bytes.
- The vtable slot at `0x0061b754` points to this wrapper.
- No direct code caller was found; dispatch is vtable-mediated.
- Body duplicates the ordinary destructor cleanup, then conditionally calls the delete helper according to scalar-deleting-destructor flags.
- It has the expected compiler-wrapper shape: restore vtables, delete owned row frames, free entry storage, clear singleton, run base cleanup, inspect delete flags, optionally call delete.

Recommendation:

- Raise score to `87/92` because behavior, range, vtable role, delete flags, and source impact are resolved.
- Keep `RECONSTRUCTABLE:TRUE` because the wrapper semantics are reconstructable.
- Leave formal C++ blank. The source-authored C++ is `LightObjImageLib::~LightObjImageLib()` from [UID:00017Q]; the compiler should synthesize the scalar deleting wrapper.

Rejected alternative:

- Emitting `LightObjImageLib::ScalarDeletingDestructor(unsigned int flags)` is rejected. That would create generated-owner pollution and represent compiler output as source.

### Range And Padding Validation

Local PE section mapping confirmed image base `0x00400000` and executable section coverage for these ranges. The following padding bytes were checked from `NexusTK.exe`:

```text
0x004dfaa6-0x004dfab0  10 bytes of cc
0x004dfb36-0x004dfb40  10 bytes of cc
0x004dfc5a-0x004dfc60   6 bytes of cc
0x004dfd0a-0x004dfd10   6 bytes of cc
0x004e669d-0x004e66a0   3 bytes of cc
0x004e5bbb-0x004e5bc0   5 bytes of cc
```

The target ranges and coverage padding rows are stable. No split-first workflow is needed.

## First-Draft C++ Recommendation

### [UID:0002IU] `LightObjImageLib::LightObjImageLib`

Recommended formal C++:

```cpp
LightObjImageLib::LightObjImageLib()
{
    g_pLightObjImageLib = this;

    lightInfoCount = 0;
    lightInfoEntries = 0;
    lightInfoCapacity = 10;

    fallbackLightInfo.tableId = -1;
    fallbackLightInfo.innerRadius = -1;
    fallbackLightInfo.radiusX = -1;
    fallbackLightInfo.radiusY = -1;
    fallbackLightInfo.brightness = 0.0f;
    fallbackLightInfo.blendScale = 0.0f;
    fallbackLightInfo.generatedFrame = 0;

    DATFile lightTable;
    lightTable.Open(L"LIGHT.TBL");

    int lightCount = 0;
    ReadEncodedTableInt(&lightTable, &lightCount);

    if (lightCount > 0 && lightInfoCount != lightCount) {
        LightInfo *newEntries =
            static_cast<LightInfo *>(operator new(sizeof(LightInfo) * lightCount));

        if (lightInfoEntries != 0) {
            int copyCount = lightCount;
            if (lightInfoCount < copyCount) {
                copyCount = lightInfoCount;
            }

            memmove(newEntries, lightInfoEntries, sizeof(LightInfo) * copyCount);
            free(lightInfoEntries);
        }

        lightInfoCount = lightCount;
        lightInfoEntries = newEntries;
    }

    for (int index = 0; index < lightCount; ++index) {
        LightInfo lightInfo;
        ReadEncodedTableInt(&lightTable, &lightInfo.tableId);
        ReadEncodedTableInt(&lightTable, &lightInfo.innerRadius);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusX);
        ReadEncodedTableInt(&lightTable, &lightInfo.radiusY);
        ReadEncodedTableFloat(&lightTable, &lightInfo.brightness);
        ReadEncodedTableFloat(&lightTable, &lightInfo.blendScale);
        lightInfo.generatedFrame = 0;

        if (lightInfo.radiusX > 0 && lightInfo.radiusY > 0) {
            const int width = lightInfo.radiusX * 2 + 1;
            const int height = lightInfo.radiusY * 2 + 1;

            lightInfo.generatedFrame = new AlphaMaskSurface(width, height);
            if (lightInfo.generatedFrame != 0) {
                RectBounds frameRect;
                InitRectBounds(&frameRect, 0, 0, width, height);
                lightInfo.generatedFrame->ApplyRectAlpha(&frameRect, 0, 0);

                int center[2];
                lightInfo.generatedFrame->GetCenterPoint(center);

                const int innerAlpha =
                    static_cast<int>(lightInfo.brightness * 32.0f + 0.5f);

                lightInfo.generatedFrame->FillEllipticGradient(
                    center[1],
                    center[0],
                    lightInfo.innerRadius,
                    lightInfo.radiusX,
                    lightInfo.radiusY,
                    static_cast<unsigned char>(innerAlpha),
                    0,
                    lightInfo.blendScale,
                    0);
            }
        }

        LightInfo *slot = &fallbackLightInfo;
        if (index >= 0 && index < lightInfoCount) {
            slot = &lightInfoEntries[index];
        }

        *slot = lightInfo;
    }
}
```

Notes for supervisor:

- `ReadEncodedTableInt` and `ReadEncodedTableFloat` are recommended source-facing aliases for the current DATFile scalar readers at `0x0049c4a0` and `0x0049c4f0`. If the DATFile owner later renames these methods, update this constructor spelling accordingly.
- The source block intentionally omits compiler vtable writes, security-cookie checks, and exception cleanup chunk jumps.
- If project style avoids `operator new` in constructor source, the allocation line may be replaced with the project's recovered protected-array grow helper once that helper has a final name. The behavior is fixed as `sizeof(LightInfo) * lightCount`, preserve min(old,new) rows, free old rows, update count and pointer.

### [UID:00017Q] `LightObjImageLib::~LightObjImageLib`

Recommended formal C++:

```cpp
LightObjImageLib::~LightObjImageLib()
{
    for (int index = 0; index < lightInfoCount; ++index) {
        AlphaMaskSurface *frame = lightInfoEntries[index].generatedFrame;
        if (frame != 0) {
            delete frame;
        }
    }

    free(lightInfoEntries);
    g_pLightObjImageLib = 0;
}
```

Notes for supervisor:

- The binary restores vtables, clears the singleton, and tail-calls base cleanup. The source destructor should express only owned-frame deletion, entry-buffer release, and singleton clear; base cleanup is implicit in C++ destructor emission.
- Do not add optional `delete this`; that belongs only to the scalar deleting wrapper.
- Do not delete `fallbackLightInfo.generatedFrame`; constructor seeds it as null and no recovered path populates it.

### [UID:0002IW] `LightObjImageLib::DrawLightMode1`

Recommended formal C++:

```cpp
void LightObjImageLib::DrawLightMode1(AlphaMaskSurface *targetSurface,
                                      int centerX,
                                      int centerY,
                                      int lightIndex)
{
    const LightInfo *lightInfo = &fallbackLightInfo;
    if (lightIndex >= 0 && lightIndex < lightInfoCount) {
        lightInfo = &lightInfoEntries[lightIndex];
    }

    AlphaMaskSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0) {
        return;
    }

    const int width = sourceFrame->width;
    const int height = sourceFrame->height;

    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);

    RectBounds destinationRect;
    InitRectBounds(&destinationRect,
        centerX - width / 2,
        centerY - height / 2,
        centerX - width / 2 + width,
        centerY - height / 2 + height);

    DrawFrameWithBlendMode(targetSurface, &destinationRect, sourceFrame, &sourceRect, 1);
}
```

### [UID:0002IX] `LightObjImageLib::DrawLightMode2`

Recommended formal C++:

```cpp
void LightObjImageLib::DrawLightMode2(AlphaMaskSurface *targetSurface,
                                      int centerX,
                                      int centerY,
                                      int lightIndex)
{
    const LightInfo *lightInfo = &fallbackLightInfo;
    if (lightIndex >= 0 && lightIndex < lightInfoCount) {
        lightInfo = &lightInfoEntries[lightIndex];
    }

    AlphaMaskSurface *sourceFrame = lightInfo->generatedFrame;
    if (sourceFrame == 0) {
        return;
    }

    const int width = sourceFrame->width;
    const int height = sourceFrame->height;

    RectBounds sourceRect;
    InitRectBounds(&sourceRect, 0, 0, width, height);

    RectBounds destinationRect;
    InitRectBounds(&destinationRect,
        centerX - width / 2,
        centerY - height / 2,
        centerX - width / 2 + width,
        centerY - height / 2 + height);

    DrawFrameWithBlendMode(targetSurface, &destinationRect, sourceFrame, &sourceRect, 2);
}
```

### [UID:0002IY] Scalar Deleting Destructor

Recommended formal C++: leave blank.

Do not emit a hand-authored C++ block for [UID:0002IY]. The source-authored destructor is [UID:00017Q]. [UID:0002IY] is the compiler-generated vtable deleting destructor wrapper, and its delete-flag branch should be documented as compiler output rather than represented as a source method.

## Target Doc Change Recommendations

These are exact by-memory doc changes recommended for supervisor execution. B003 did not apply them.

### `by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md`

- Metadata:
  - Change `COMPLETION:82` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:0000KP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000KP`.
- `RECONSTRUCTION_CPP`: replace the blank block with the [UID:0002IU] constructor C++ from this report.
- In the summary/evidence text, replace references to unresolved first two fields or `lightSource` with:

```text
The `LIGHT.TBL` row schema is now source-bounded as `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`. The former `lightSource` label for row `+0x04` is rejected because constructor dataflow passes that field to `AlphaMaskSurface::FillEllipticGradient` as the `innerRadius` argument after the generated frame center has already been computed from the frame dimensions.
```

### `by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md`

- Metadata:
  - Change `COMPLETION:82` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:0000KP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000KP`.
- `RECONSTRUCTION_CPP`: replace the blank block with the [UID:00017Q] ordinary destructor C++ from this report.
- Add to source-readiness or score rationale:

```text
The ordinary destructor is source-ready despite the raw start not being an IDA function object. The raw bytes, scalar-deleting-destructor parity, frame-delete loop, entry-buffer free, singleton clear, base cleanup tail, and padding establish the source destructor; explicit vtable restores and base tail-call remain compiler output and are intentionally omitted from formal C++.
```

### `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`

- Metadata:
  - Change `COMPLETION:82` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:0000KP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000KP`.
- `RECONSTRUCTION_CPP`: replace the blank block with the [UID:0002IW] draw C++ from this report.
- Add to behavior summary:

```text
Blend mode `1` is the additive byte-mask mode of `DrawFrameWithBlendMode`; the method is a real vtable slot and should be emitted separately from mode 2 even though the bodies differ only by the final blend-mode literal.
```

### `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`

- Metadata:
  - Change `COMPLETION:82` to `COMPLETION:88`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:0000KP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000KP`.
- `RECONSTRUCTION_CPP`: replace the blank block with the [UID:0002IX] draw C++ from this report.
- Add to behavior summary:

```text
Blend mode `2` is the subtractive byte-mask mode of `DrawFrameWithBlendMode`; the method is a real vtable slot and should be emitted separately from mode 1 even though the bodies differ only by the final blend-mode literal.
```

### `by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md`

- Metadata:
  - Change `COMPLETION:82` to `COMPLETION:87`.
  - Change `CONFIDENCE:90` to `CONFIDENCE:92`.
  - Keep `CANONICAL_OWNER:0000KP`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000KP`.
- Keep `RECONSTRUCTION_CPP` blank.
- Add to source-readiness or score rationale:

```text
This target is behavior-complete but remains a compiler-generated scalar deleting destructor wrapper. The source-authored cleanup is emitted through `LightObjImageLib::~LightObjImageLib` at [UID:00017Q]; the vtable wrapper's delete-flag branch is documented here but should not be hand-authored into `LightObjImageLib.cpp`.
```

## Support Doc Recommendations

These are exact support-doc recommendations for supervisor execution. B003 did not apply them.

### `by-type/by-struct/LightInfo.md`

Recommended metadata:

- Change `COMPLETION:85` to `COMPLETION:88`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:000076`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:000076`.

Replace the `## Status` first bullet with:

```text
- Confidence: strong for size, offsets, constructor/destructor/draw usage, generated-frame lifetime, and source-facing names for all runtime-used fields; bounded for the exact original spelling of the first table identifier field.
```

Replace the `## Layout` block with:

```text
LightInfo
  +0x00  int tableId
  +0x04  int innerRadius
  +0x08  int radiusX
  +0x0c  int radiusY
  +0x10  float brightness
  +0x14  float blendScale
  +0x18  AlphaMaskSurface* generatedFrame
  sizeof = 0x1c
```

Add these bullets under `## Field Evidence` after the constructor-read bullet:

```text
- The former `lightSource` label for `+0x04` is rejected. Constructor dataflow passes `+0x04` to `AlphaMaskSurface::FillEllipticGradient` as the `innerRadius` argument after `GetCenterPoint` has computed the generated frame center from frame dimensions.
- The second float at `+0x14` flows into `FillEllipticGradient` as the falloff/blend scale parameter, so `blendScale` is a better source-facing name than `blendValue`.
- The first integer at `+0x00` is preserved from `LIGHT.TBL` but has no recovered runtime consumer in constructor, bounds, draw, or destructor paths. `tableId` is the best bounded source-facing name; exact original spelling remains unknown.
```

Replace the `## Score Rationale` paragraph with:

```text
Completion is raised to `88` because the row size, constructor read order, generated-frame allocation, AlphaMaskSurface argument mapping, bounds behavior, both draw modes, ordinary/scalar destructor cleanup, fallback row, and class/file route are now documented. Confidence is raised to `92` because constructor dataflow into `FillEllipticGradient` resolves the historical `+0x04` ambiguity as `innerRadius`; confidence remains below final because the exact original spelling of `tableId` is inferred rather than symbol-proven.
```

Add a `## Changes` bullet:

```text
- 2026-06-17 B003 source-quality audit: rejected the historical `lightSource` field name for `+0x04` and renamed the source-facing schema to `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame` based on constructor dataflow into `AlphaMaskSurface::FillEllipticGradient`, downstream bounds/draw/destructor usage, and LightObjImageLib first-draft C++ readiness.
```

### `by-type/by-struct/LightObjImageLibLayout.md`

Recommended metadata:

- Current score may stay as-is if the supervisor wants a narrow update, or be raised to `87/91` after applying the field-name cleanup below.

Under the layout table, replace `initialOrGrowCapacity` with `lightInfoCapacity`:

```text
  +0x10  int lightInfoCapacity
```

Add this evidence bullet:

```text
- The constructor initializes the embedded list/protected-array count to `0`, entry pointer to `0`, and capacity to `10`. `lightInfoCapacity` is the best source-facing name for `+0x10`; the older `initialOrGrowCapacity` label is descriptive but less source-like.
```

Add or update the fallback evidence:

```text
- The fallback row at `+0x14` is seeded from four `-1` integer constants and zeroed float/pointer fields, producing `{-1, -1, -1, -1, 0.0f, 0.0f, nullptr}` under the resolved `LightInfo` schema.
```

### `by-class/LightObjImageLib.md`

Add a method-family note near the method table:

```text
2026-06-17 B003 source-quality audit resolves the LightObjImageLib method cluster above the first-draft C++ gate: constructor, ordinary destructor, and both virtual draw modes should emit through [UID:0000KP] `NexusTK/render/LightObjImageLib.cpp`. The scalar deleting destructor remains documented but formal C++ stays blank by compiler-wrapper policy.
```

Update any `LightInfo` field references to use:

```text
`tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`
```

### `by-file/LightObjImageLib.md`

Add to the status or notes section:

```text
2026-06-17 B003 source-quality audit resolves the remaining first-draft blockers for the constructor, ordinary destructor, and two draw-mode vtable slots. The source file should emit `LightObjImageLib::LightObjImageLib`, `LightObjImageLib::~LightObjImageLib`, `DrawLightMode1`, `DrawLightMode2`, and the already accepted `GetLightBounds`; the scalar deleting destructor remains compiler output and should not be hand-authored.
```

Replace any old `lightSource` / `blendValue` wording with:

```text
The `LIGHT.TBL` row is `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`. `innerRadius` is passed to `AlphaMaskSurface::FillEllipticGradient`; `blendScale` is the falloff/scale float for that gradient.
```

### `by-global/g_pLightObjImageLib.md` and `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`

Keep canonical name `g_pLightObjImageLib`. Add this note only if the pages discuss initial raw bytes:

```text
B003 local PE section mapping shows `0x0069b450` lies in zero-fill past initialized `.data` raw bytes in `NexusTK.exe`; source-level initial state should therefore be treated as normal zero-initialized global storage unless live IDA memory evidence deliberately records a post-load/runtime value. Constructor and destructor writes remain the authoritative ownership evidence.
```

### DATFile Support Docs

Recommended narrow wording for `by-class/DATFile.md` and `by-memory/0x0049c130-0x0049d2cc.DATFile.md`:

```text
Consumer-facing image-library constructors use `0x0049c4a0` as an encoded integer/scalar table read and `0x0049c4f0` as an encoded float/scalar table read. Existing names `ReadAllEntries` and `ReadAllEntriesAlt` are retained pending a DATFile owner pass, but LightObjImageLib first-draft C++ may use local aliases `ReadEncodedTableInt` and `ReadEncodedTableFloat` to express the caller semantics.
```

## Supervisor-Owned Coverage Row Replacements

B003 is banned from editing `by-memory/-coverage-report.md`; apply the following replacement block for the LightObjImageLib cluster rows currently beginning at [UID:00017P].

```text
    - [UID:00017P][0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster](by-memory/0x004df7e0-0x004dfd0a.LightObjImageLibLocalMethodCluster.md) 0x004df7e0-0x004dfd0a | class-method-cluster/index | LightObjImageLib local method cluster : not_reconstructable : 83% : strong : Non-emitting local split/index for the LightObjImageLib constructor, raw ordinary destructor, GetLightBounds, and two virtual draw-mode methods before NewHumanImageLib begins at 0x004dfd10; exact child pages and separate tail pages carry source ownership/emission, while this cluster only records boundaries, padding, vtable/global anchors, and aggregate policy.
        - [UID:0002IU][0x004df7e0-0x004dfaa6.LightObjImageLibConstructor](by-memory/0x004df7e0-0x004dfaa6.LightObjImageLibConstructor.md) 0x004df7e0-0x004dfaa6 | constructor | LightObjImageLib::LightObjImageLib : reconstructable : 88% : very-strong : Source-ready constructor for the light-image singleton; B003 reanalysis resolves `LIGHT.TBL` rows as `tableId`, `innerRadius`, `radiusX`, `radiusY`, `brightness`, `blendScale`, and `generatedFrame`, rejects the historical `lightSource` label, confirms exact 0x2c6 body, startup caller at 0x004f6139, singleton/vtable writes, fallback row, DAT scalar-read helpers, protected-array resize, generated AlphaMaskSurface frame creation through `FillEllipticGradient`, cleanup chunks, ten-byte cc padding, [UID:0000KP] owner/emitter, and first-draft C++ readiness.
        - [UID:00017Q][0x004dfab0-0x004dfb36.LightObjImageLibDestructor](by-memory/0x004dfab0-0x004dfb36.LightObjImageLibDestructor.md) 0x004dfab0-0x004dfb36 | destructor | LightObjImageLib::~LightObjImageLib : reconstructable : 88% : very-strong : Source-ready raw ordinary destructor; B003 reanalysis confirms exact non-modeled 0x86-byte body, no direct refs to the raw start, generated-frame delete loop over 0x1c LightInfo rows, `ProtectedArray<LightInfo>`/LightObj vtable restoration as compiler output, record-buffer free, singleton clear, base tail-call, scalar-wrapper parity, ten-byte cc padding, [UID:0000KP] owner/emitter, and first-draft C++ readiness.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004dfaa6-0x004dfab0, 0x004dfb36-0x004dfb40, 0x004dfc5a-0x004dfc60, 0x004dfd0a-0x004dfd10, 0x004e669d-0x004e66a0 | padding | LightObjImageLib internal alignment : ignored : 100% : strong : Confirmed `0xcc`/alignment bytes around exact LightObjImageLib child functions.
        - [UID:0002IV][0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds](by-memory/0x004dfb40-0x004dfbb0.LightObjImageLibGetLightBounds.md) 0x004dfb40-0x004dfbb0 | method | LightObjImageLib::GetLightBounds : reconstructable : 88% : very-strong : Fresh 2026-06-17 IDA MCP evidence validates the exact 0x70 `thiscall` body, source-facing `void GetLightBounds(int lightIndex, RectBounds *outBounds)` signature, one `AttachmentAnchorResolver::ComputeScreenBounds` caller at 0x0053c82b, singleton `this` load from g_pLightObjImageLib, LightInfo/fallback selection, generated-frame gate, local `[-radiusX,-radiusY,radiusX+1,radiusY+1]` bounds semantics, empty fallback/default behavior, RectBounds initializer dependency, and LightObjImageLib.cpp emission readiness with formal C++ populated.
        - [UID:0002IW][0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1](by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md) 0x004dfbb0-0x004dfc5a | virtual method | LightObjImageLib::DrawLightMode1 : reconstructable : 88% : very-strong : Source-ready virtual draw method; B003 reanalysis confirms exact 0xaa body, vtable-only ref at 0x0061b760, no direct callers, fallback/entry selection, generated-frame null gate, centered source/destination rect math, `DrawFrameWithBlendMode` dependency, additive blend mode 1, six-byte cc padding, [UID:0000KP] owner/emitter, and first-draft C++ readiness.
        - [UID:0002IX][0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2](by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md) 0x004dfc60-0x004dfd0a | virtual method | LightObjImageLib::DrawLightMode2 : reconstructable : 88% : very-strong : Source-ready virtual draw method; B003 reanalysis confirms exact 0xaa body, vtable-only ref at 0x0061b764, no direct callers, fallback/entry selection, generated-frame null gate, centered source/destination rect math, `DrawFrameWithBlendMode` dependency, subtractive blend mode 2, six-byte cc padding before NewHumanImageLib, [UID:0000KP] owner/emitter, and first-draft C++ readiness.
        - [UID:0002IY][0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor](by-memory/0x004e65e0-0x004e669d.LightObjImageLibScalarDeletingDestructor.md) 0x004e65e0-0x004e669d | deleting destructor | LightObjImageLib scalar deleting destructor : reconstructable : 87% : very-strong : Behavior-complete compiler deleting wrapper; B003 reanalysis confirms exact 0xbd body, vtable-only ref at 0x0061b754, no direct callers, parity with ordinary destructor cleanup, generated-frame deletion, record-buffer free, singleton clear, base cleanup, delete-flag branch, three-byte cc padding, [UID:0000KP] owner/emitter, and blank formal C++ by scalar-deleting-destructor wrapper policy.
```

## Residual Risks And Bounds

- Exact original spelling for `tableId`, `lightInfoCapacity`, `ReadEncodedTableInt`, and `ReadEncodedTableFloat` is inferred rather than symbol-proven. The semantics are bounded tightly enough for first-draft C++; later owner passes may rename them without changing behavior.
- The raw `misc.dat` member was not directly decodable with the scalar `ParseEntries` algorithm, so no decoded `LIGHT.TBL` row values are claimed in this report. The constructor dataflow is sufficient for field names.
- The destructor first draft uses source-level `delete frame;` and `free(lightInfoEntries);`. If the source project later wraps AlphaMaskSurface deletion or protected-array cleanup in named helpers, the body should be mechanically updated to those recovered helper names.
- The draw first drafts name `sourceFrame->width` and `sourceFrame->height` based on AlphaMaskSurface layout use at `+0x18/+0x1c`. If the AlphaMaskSurface type page later finalizes different field spelling, update only those member names.

## Validation Notes

- Confirmed active generated file only contains [UID:0002IV] `LightObjImageLib::GetLightBounds`; constructor, ordinary destructor, both draw modes, and scalar deleting destructor are still blank in generated output.
- Confirmed current coverage rows list the primary targets at `82% : strong` and need supervisor-owned row updates if these recommendations are accepted.
- Confirmed current `LightInfo.md` still carries `lightSource` and `blendValue`; this report supplies exact replacement text.
- Confirmed local PE vtable and padding bytes for the LightObjImageLib targets and adjacent `ProtectedArray<LightInfo>` vtable.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002IU-00017Q-0002IW-0002IX-0002IY-lightobjimagelib-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002IU"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
