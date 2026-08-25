*** UID:00009Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName,
                                           const wchar_t *paletteName,
                                           unsigned short overlayX,
                                           unsigned short overlayY)
    : OverlayEffecter(1, overlayX, overlayY)
{
    m_tileContext.Init();
    wcscpy_s(m_imageName, 0x10, imageName);
    wcscpy_s(m_paletteName, 0x10, paletteName);

    g_pEPFLib->LookupLayoutEntry(m_imageName, 0, &m_tileContext);
    m_isVisible = true;
}

void OverlayImageEffecter::ApplyOverlayImage()
{
    RectBounds viewportBounds;
    g_activeMapPane->GetBounds(&viewportBounds);

    g_activeMapPane->RenderTileFrame(&m_tileContext,
                                     &m_tileContext.bounds,
                                     &viewportBounds,
                                     1,
                                     m_paletteName,
                                     0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OverlayImageEffecter

## Status

- Confidence: very strong for class identity, Effects ownership, exact method boundaries, four-view vtable identity, adjusted `+0x04` render receiver mapping, constructor behavior, static overlay render path, and first-draft C++ readiness.
- Proposed source: [UID:0000IZ][Effects](by-file/Effects.md), emitted under `NexusTK/render/Effects.cpp`.
- Runtime aggregate: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md).
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md).
- Base class: [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md).
- C++ status: first-draft source-style C++ is populated for the source-authored constructor and render/apply virtual. The scalar deleting destructor, adjusted destructor thunks, vtable data, EH cleanup body, security cookie, and unwind scaffolding are compiler output and remain prose-only evidence.

## Responsibility

`OverlayImageEffecter` is the static image/name overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It resolves overlay metadata by image name through [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md), stores copied image and palette/overlay names, owns an embedded [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), and applies the overlay to the active viewport by rendering through [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) and the shared Surface/GrafPort `RenderTileFrame` path.

Recovered helper labels that mention fitting-room/download panes are caller-biased provenance from the shared render helper at `0x004b9980`. They are not source ownership evidence for this runtime effect class.

## Method And Boundary Inventory

| Range | Size | Source-facing role | Boundary notes |
| --- | ---: | --- | --- |
| `0x0055a3d0-0x0055a43e` | `0x6e` / 110 bytes | EH cleanup / non-deleting-destructor-shaped cleanup evidence | Resets the [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base views, calls inherited pane cleanup/destructor helpers `0x00544ce0` and `0x00544580` on `this+4`, resets the [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) primary base vtable, and returns. Local scans found table/EH-like references around `0x0060759c`, `0x006075da`, `0x00607618`, and `0x00607656`, not normal callers or vtable slots. Do not emit a source method for this body. |
| `0x0055a440-0x0055a499` | `0x59` / 89 bytes | `OverlayImageEffecter::ApplyOverlayImage()`; render/apply virtual body | Uses stack-cookie prologue/epilogue, obtains active viewport bounds, calls shared `RenderTileFrame`, and returns with live `EAX`; no source-level return value is consumed through the virtual route, so the source method is `void`. `0x0055a499-0x0055a4a0` is `int3` padding before the constructor. |
| `0x0055a4a0-0x0055a55e` | `0xbe` / 190 bytes | complete-object constructor | Calls `OverlayEffecter(1, overlayX, overlayY)`, installs four subclass vtable views, initializes the embedded tile context, copies two 16-wide names, performs an EPF layout lookup, sets the inherited active/visible byte, returns `this`, and ends with `ret 0x10`. `0x0055a55e-0x0055a560` is padding before the next sibling destructor. |
| `0x0055bd70-0x0055be0d` | `0x9d` / 157 bytes | compiler-generated scalar deleting destructor | Resets base views, runs inherited pane cleanup, resets the `ScreenEffecter` base vtable, and conditionally deletes storage according to MSVC scalar-delete flags. `0x0055be0d-0x0055be10` is padding before the next wrapper. |

No split child rows are required for this class page yet. If exact function-level children are later created, the natural children are the apply method, constructor, scalar deleting destructor, and EH cleanup body above. The current class page can carry the first-draft source because the source-owned constructor and apply body are small, contiguous, and well understood.

## Apply/Render Method

`0x0055a440-0x0055a499` is installed in the `+0x04` vtable view at `0x006236fc`, so the receiver is the embedded Pane/GrafPort adjusted view (`ecx = complete object + 4`). The offsets used inside the body must be normalized back to the complete object before naming fields:

| Render-body offset | Complete-object offset | Best current source role |
| --- | --- | --- |
| adjusted `+0x11c` | complete `+0x120` | `m_paletteName` / `m_overlayPaletteName`, copied by the constructor and passed as the palette/name argument to `RenderTileFrame`. |
| adjusted `+0x140` | complete `+0x144` | embedded `EPFTileContext`, best source name `m_tileContext`. |
| adjusted `+0x150` | complete `+0x154` | `m_tileContext.bounds` / source bounds record passed to the renderer. |

Observed render behavior:

- Loads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) from `0x0067a764`.
- Calls `0x004b8e00` with `ecx = g_activeMapPane` and an out local `RectBounds` to get the active viewport bounds.
- Calls shared Surface/GrafPort `RenderTileFrame` at `0x004b9980` with `ecx = g_activeMapPane`.
- Passes the embedded tile context, tile/source bounds, viewport bounds, mode `1`, copied palette/overlay name, and flags/options `0`.
- Returns with a live `EAX`, but the vtable route does not consume a source-level return value; the source method is `void`.

`ApplyOverlayImage` is the current best source-facing name. `render/apply virtual body` is an acceptable prose alias. A future family-wide pass may standardize all adjusted `+0x04` paint/render slots as `OnPaint()`, but no such rename is required for this target.

## Constructor Details

`0x0055a4a0-0x0055a55e` returns with `ret 0x10`, proving four explicit stack arguments. Best current source-facing shape:

```cpp
OverlayImageEffecter::OverlayImageEffecter(const wchar_t *imageName,
                                           const wchar_t *paletteName,
                                           unsigned short overlayX,
                                           unsigned short overlayY)
    : OverlayEffecter(1, overlayX, overlayY)
```

Observed constructor behavior:

- Calls [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) constructor `0x0055a2e0` with fixed kind/category `1` and the last two word-sized constructor arguments.
- Installs four `OverlayImageEffecter` vtable views: complete `+0x00 -> 0x00623694`, adjusted `+0x04 -> 0x006236b8`, adjusted `+0xa4 -> 0x00623704`, and adjusted `+0xa8 -> 0x00623734`.
- Calls [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) initializer `0x00457a60` with `ecx = complete + 0x144`, initializing embedded `m_tileContext`.
- Copies the first pointer argument to complete `+0x100` using helper `0x005cd657` with size/immediate `0x10`.
- Copies the second pointer argument to complete `+0x120` using the same helper and size/immediate `0x10`.
- Loads [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md) from `0x0067a744`.
- Calls [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md) with name `complete+0x100`, frame/index `0`, and output `complete+0x144`.
- Sets byte `complete+0xf9` to `1`, best current source name `m_isVisible` / inherited active byte.

Parameter confidence:

- `imageName` is high-confidence because it is copied to `+0x100` and then used as the resource-layout lookup name.
- `paletteName` / `overlayPaletteName` is high-probability because it is copied to `+0x120` and later passed as the palette/name argument to `RenderTileFrame`.
- `overlayX` / `overlayY` are descriptive names for the words forwarded to `OverlayEffecter(1, overlayX, overlayY)` and stored by the base at complete `+0xfc/+0xfe`; final source names could still be variant/index/placement names.
- `wchar_t` is high-probability because the surrounding resource-layout and string-copy ecosystem uses UTF-16/wide names.
- `0x005cd657` should be documented as bounded wide-string copy / likely `wcscpy_s`; the exact CRT/helper import identity is not symbol-proven locally.

## Destructor And Compiler Artifacts

`0x0055bd70-0x0055be0d` is the MSVC scalar deleting destructor wrapper:

- Resets the four [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) base vtable views: `0x006235e8`, `0x0062360c`, `0x00623658`, and `0x00623688`.
- Calls inherited pane cleanup/destructor helpers `0x00544ce0` and `0x00544580` on `this+4`.
- Resets the [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md) primary base vtable to `0x006235a4`.
- Checks scalar-delete flags and calls either [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) or guarded sized/vector-delete helper `0x0041b6a0(this, 0x16c)` depending on delete-mode bits.
- Confirms complete object size `0x16c` / 364 bytes on the deleting path.

Adjusted scalar deleting destructor thunks:

```text
0x0055ba7c-0x0055ba84: sub ecx, 4;    jmp 0x0055bd70
0x0055ba84-0x0055ba8f: sub ecx, 0xa4; jmp 0x0055bd70
0x0055ba8f-0x0055ba9a: sub ecx, 0xa8; jmp 0x0055bd70
```

Do not emit source C++ for the scalar deleting destructor, adjusted thunks, vtable bytes, vtable stores, stack cookies, SEH, or the `0x0055a3d0` cleanup body. Source declarations should model the constructor and render/apply virtual and let the compiler regenerate the wrappers and table data.

## Vtable And Reachability

`OverlayImageEffecter` has the standard four-view pane-backed effecter shape:

| View | Address range | Evidence |
| --- | --- | --- |
| Primary complete-object view | `0x00623694-0x006236b4` | Constructor store at `0x0055a4e7`; scalar-destructor/reset evidence in the destructor strip. |
| Embedded `+0x04` Pane/GrafPort view | `0x006236b8-0x00623700` | Constructor store at `0x0055a4ed`; render/apply slot `0x006236fc -> 0x0055a440`; receiver is complete object plus four. |
| `+0xa4` adjusted view | `0x00623704-0x00623730` | Constructor store at `0x0055a4f4`; secondary destructor adjustment subtracts `0xa4`. |
| `+0xa8` adjusted view | `0x00623734-0x0062373c` | Constructor store at `0x0055a4fe`; secondary destructor adjustment subtracts `0xa8`. |

The local PE scan found `ApplyOverlayImage` as a vtable-only pointer through `0x006236fc`. It found no direct constructor call, absolute pointer, RVA pointer, or raw-offset pointer route to `0x0055a4a0` despite checking rel32 code refs, absolute dword refs, RVA-style dword refs, vtable stores, sibling constructor callers, base-constructor callers, and generated class metadata. The best current interpretation is a retained/dead or metadata-gap class path inside the Effects runtime family. This is a final-confidence limiter, not a source-readiness blocker, because the constructor body, vtables, render route, and sibling family context are coherent.

## Field And Helper Direction

| Complete offset | Best name/type direction | Evidence and caveat |
| --- | --- | --- |
| `+0x100` | `wchar_t m_imageName[16]` | Constructor copies first name argument with size `0x10`; lookup uses it as the `ResourceLayoutTable::LookupLayoutEntry` key. |
| `+0x120` | `wchar_t m_paletteName[16]` / `m_overlayPaletteName[16]` | Constructor copies second name argument with size `0x10`; adjusted render body passes this field to `RenderTileFrame`. |
| `+0x144` | `EPFTileContext m_tileContext` | Constructor calls `EPFTileContext::Init` here and passes it as the lookup output. |
| `+0x154` | `m_tileContext.bounds` / `m_tileContext.m_bounds` | Adjusted render body passes this source-bounds pointer to the renderer. |
| `+0xf9` | inherited active/visible byte, best current name `m_isVisible` | Constructor writes `1`; same inherited Pane/GrafPort flag area appears across overlay/filter subclasses. |
| `+0xfc/+0xfe` | inherited overlay words from `OverlayEffecter(1, overlayX, overlayY)` | Base constructor stores the last two word arguments; final names remain inherited-base semantics. |

Helper/global names to use:

- `0x0067a764`: [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md).
- `0x0067a744`: [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md).
- `0x004b8e00`: active MapPane/BackPane/GrafPort bounds getter used to produce a viewport `RectBounds`.
- `0x004b9980`: shared Surface/GrafPort `RenderTileFrame` helper. Existing docs reject recovered `FittingRoomDownloadControlPane` ownership because this wrapper has broad shared use and dispatches through the [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3E8`.
- `0x004d02f0`: [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md).
- `0x00457a60`: `EPFTileContext::Init`.
- `0x005cd657`: bounded wide-string copy / likely `wcscpy_s`; exact import/helper spelling remains below final-source confidence.

Rejected alternatives:

- Do not route this class, `0x004b9980`, or `ApplyOverlayImage` through `FittingRoomDownloadControlPane`. The fitting-room/download name is helper provenance, not class ownership.
- Do not read adjusted render offsets `this+0x11c/+0x140/+0x150` as complete-object fields.
- Do not treat the no-direct-constructor-route scan as a no-code proof.
- Do not handwrite the scalar deleting destructor, adjusted thunks, vtable data, or EH cleanup body as source C++.
- Do not move ownership to the runtime aggregate, vtable family, or a no-owner/non-emitting route. [UID:0000IZ][Effects](by-file/Effects.md) remains the narrowest source owner/emitter.

## Open Questions And Current Resolution

- Direct construction site: no direct construction route for `0x0055a4a0` was found by local PE scans. Preserve this caveat as a confidence limiter, not a draft-C++ blocker.
- Final source names: `m_imageName`, `m_paletteName`, `RenderTileFrame`, `LookupLayoutEntry`, `m_isVisible`, `overlayX`, and `overlayY` are source-quality descriptive names, not symbol-proven final names.
- Helper signatures: docs may later choose member-call or free-helper spelling for `RenderTileFrame`, `LookupLayoutEntry`, and `EPFTileContext::Init`. The draft C++ preserves the argument semantics and accepted family style.
- Source split: split child rows remain optional future cleanup. The class itself is reconstructable at `88/91` through the [UID:0000IZ][Effects](by-file/Effects.md) emitter route.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | Source placement, exact apply/constructor/scalar-destructor/EH-cleanup ranges, padding, adjusted receiver mapping, constructor field setup, viewport render route, helper/global naming, compiler-artifact policy, rejected owner alternatives, and first-draft C++ are now documented. |
| Confidence `91` | Local PE disassembly/ref scans, vtable slots, runtime aggregate, vtable-data docs, helper/global docs, and sibling overlay effecter pages agree. Confidence stays below final-source territory because no direct constructor route was found, final helper/field spellings are inferred, and the last two constructor argument names are inherited-base semantics. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md)
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md)
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0000QU][g_pEPFLib](by-global/g_pEPFLib.md)
- [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:0002KP][0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry](by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- 2026-06-20 B004 Rule 26 source-quality incorporation:
  - Before: `84/88`, blank C++, stale final-source/no-code gate wording, and adjusted render offsets recorded only as raw `this` fields.
  - After: `88/91`, owner/emitter still [UID:0000IZ][Effects](by-file/Effects.md), reconstructable, and first-draft constructor/render C++ populated.
  - Summary/evidence: incorporated local PE reanalysis from B004: exact apply/constructor/scalar-destructor ranges and padding, `0x0055a3d0-0x0055a43e` EH cleanup evidence, `0x006236fc -> 0x0055a440` adjusted `+0x04` render slot, complete-offset mapping for `m_paletteName`/`m_tileContext`/bounds, `OverlayEffecter(1, overlayX, overlayY)` constructor shape, vtable stores, `EPFTileContext::Init`, bounded wide-string copies, `g_pEPFLib->LookupLayoutEntry`, inherited visible byte, `g_activeMapPane` viewport/render route, scalar deleting destructor flag/object-size proof, helper/source-name caveats, rejected fitting-room/download ownership, no-direct-constructor-route caveat, and compiler-artifact no-code policy.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: constructor resource evidence used only historical `dword_67A744`.
  - After: the page records canonical `g_pEPFLib` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A744` to `g_pEPFLib`; existing IDA-backed evidence already ties the reference to EPF resource metadata lookup.
- 2026-06-04: Raised completion/confidence from `72/78` to `84/88`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Summary/evidence: live IDA MCP verified exclusive function endpoints, constructor base call and four-view vtable stores, two copied resource names, metadata lookup through `0x004d02f0`, viewport-bound render flow through `0x004b8e00`/`0x004b9980`, and scalar-destructor teardown. Completion remains below final-source quality because final field names and all creator/caller contexts still need reconstruction.
- Before: completion/confidence metadata were `0/0` despite role, method, helper-label caveat, and overlay-family documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: apply/constructor/destructor methods, static image overlay responsibility, base/subclass relationships, and helper-label pollution are documented; confidence stays medium-high because helper names and detailed field/source split still need verification.
