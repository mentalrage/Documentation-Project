** TARGET-REPORT-UID:000168 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000168 GrafPortDrawRectFrame Source-Quality Research

Assignment: `B002-goal2-grafport-draw-rect-frame-source-quality-000168-20260618`  
Agent: `Agent-B002`  
Target: [UID:000168] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`  
Report-only output: this report is the only file produced by the assignment.

## Final Recommendation

[UID:000168] should stay an exact one-function source-bearing target for `GrafPort::DrawRectFrame`. The best current source route is the direct `GrafPort` class owner [UID:00005V], emitted through the `GrafPort` file [UID:0000JR]. The historical/generated `RankingEventListPane` owner is caller pollution and should be explicitly marked stale. The `Surface` route is not the best owner for this function: the function uses the global software-render line callback slot, but its receiver, state fields, clipping helper, cursor save/restore, and public caller shape are all `GrafPort`.

Recommended target state after supervisor application:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005V
EMITTER_UIDS: 00005V
```

The target is above the active draft-code gate and has no remaining range, owner, or source-shape blocker. Populate first-draft C++ with descriptive names. Remaining uncertainty is limited to exact original spelling of names such as `DrawRectFrame`, `RectBounds` versus `RECT`, and the line-callback wrapper name; that uncertainty should not block formal draft C++.

## Evidence Checked

- Read target [UID:000168] and required support docs [UID:0000JR] `GrafPort`, [UID:00005V] `GrafPort`, [UID:0000OC] `Surface`, [UID:000164] `GrafPortClipRectHelper`, [UID:000162] `GrafPortDrawStateAccessors`, [UID:0000TN] / [UID:0001PI] `SurfaceRenderCallbackTable`, [UID:000167] `SurfaceSpriteBlitHelper`, [UID:000169] `CompositePixels16`, and [UID:00016A] `GrafPortDrawTiledBackground`.
- Read nearby support docs [UID:000165] `SurfacePaintHelpers`, [UID:0002PG] `SoftwareRenderCompatLineCallback`, [UID:0002PJ] `SoftwareRenderRgb565LineCallback`, [UID:00015S] `RectGeometryHelpers`, [UID:0000N2] `RectBounds`, and [UID:0000BU] `RectBounds`.
- Checked generated coverage rows, generated `auto-generated/NexusTK/render/GrafPort.cpp`, and current `simroot_v2/render/class_GrafPort.cpp`.
- Checked prior executed GrafPort ownership reports, including `000160-00022M-grafport-source-quality.md` and `0003XE-0003XF-grafport-raw-island-ownership-reanalysis.md`.
- Attempted live IDA/MCP reachability check on `127.0.0.1:13337`; no listener was available. Raw PE evidence below is from the read-only `NexusTK.exe` and Capstone disassembly, not live IDA.

## Raw Boundary And Body Evidence

The read-only PE at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` maps `.text` at image base `0x00400000`. The target bytes at `0x004ba450-0x004ba53b` decode as one complete function:

```asm
004ba450  push ebp
004ba451  mov ebp, esp
004ba453  sub esp, 0x28
004ba456  mov eax, dword ptr [0x672f24]
004ba45b  xor eax, ebp
004ba45d  mov dword ptr [ebp-4], eax
004ba460  push ebx
004ba461  mov ebx, ecx
004ba463  push esi
004ba464  mov esi, dword ptr [ebp+8]
004ba467  mov dword ptr [ebp-0x28], esi
004ba46a  cmp byte ptr [ebx+0x71], 0
004ba46e  je 0x004ba529
004ba474  lea eax, [ebp-0x24]
004ba477  push eax
004ba478  call 0x004b96c0
004ba47d  movups xmm0, xmmword ptr [esi]
004ba480  lea eax, [ebp-0x14]
004ba483  push eax
004ba484  lea eax, [ebp-0x24]
004ba487  push eax
004ba488  lea eax, [ebp-0x14]
004ba48b  push eax
004ba48c  movups xmmword ptr [ebp-0x14], xmm0
004ba490  call 0x004b7cc0
004ba495  lea eax, [ebp-0x14]
004ba498  push eax
004ba499  call 0x004b7eb0
004ba49e  add esp, 0x10
004ba4a1  test al, al
004ba4a3  jne 0x004ba529
004ba4ac  mov esi, dword ptr [ebx+0x6c]
004ba4af  push edi
004ba4b0  mov edi, dword ptr [ebx+0x68]
004ba4b3  mov ecx, dword ptr [eax+4]
004ba4b6  mov edx, dword ptr [eax]
004ba4b8  mov dword ptr [ebx+0x68], ecx
004ba4bb  mov dword ptr [ebx+0x6c], edx
004ba4be  mov eax, dword ptr [eax+4]
004ba4c1  sub eax, ecx
004ba4c3  mov ecx, ebx
004ba4c5  push eax
004ba4c6  mov eax, dword ptr [ebp-0x28]
004ba4c9  mov eax, dword ptr [eax+8]
004ba4cc  sub eax, edx
004ba4ce  dec eax
004ba4cf  push eax
004ba4d0  call dword ptr [0x69b3e4]
004ba4d6  mov ecx, dword ptr [ebp-0x28]
004ba4d9  mov eax, dword ptr [ecx+0xc]
004ba4dc  sub eax, dword ptr [ebx+0x68]
004ba4df  dec eax
004ba4e0  push eax
004ba4e1  mov eax, dword ptr [ecx+8]
004ba4e4  mov ecx, ebx
004ba4e6  sub eax, dword ptr [ebx+0x6c]
004ba4e9  dec eax
004ba4ea  push eax
004ba4eb  call dword ptr [0x69b3e4]
004ba4f1  mov ecx, dword ptr [ebp-0x28]
004ba4f4  mov eax, dword ptr [ecx+0xc]
004ba4f7  sub eax, dword ptr [ebx+0x68]
004ba4fa  dec eax
004ba4fb  push eax
004ba4fc  mov eax, dword ptr [ecx]
004ba4fe  mov ecx, ebx
004ba500  sub eax, dword ptr [ebx+0x6c]
004ba503  push eax
004ba504  call dword ptr [0x69b3e4]
004ba50a  mov ecx, dword ptr [ebp-0x28]
004ba50d  mov eax, dword ptr [ecx+4]
004ba510  sub eax, dword ptr [ebx+0x68]
004ba513  push eax
004ba514  mov eax, dword ptr [ecx]
004ba516  mov ecx, ebx
004ba518  sub eax, dword ptr [ebx+0x6c]
004ba51b  push eax
004ba51c  call dword ptr [0x69b3e4]
004ba522  mov dword ptr [ebx+0x68], edi
004ba525  mov dword ptr [ebx+0x6c], esi
004ba528  pop edi
004ba529  mov ecx, dword ptr [ebp-4]
004ba52c  pop esi
004ba52d  xor ecx, ebp
004ba52f  pop ebx
004ba530  call 0x005c772f
004ba535  mov esp, ebp
004ba537  pop ebp
004ba538  ret 4
```

The body draws four line deltas from the original rectangle after a clipped-rectangle visibility test. The function has a normal security-cookie prologue/epilogue and returns with `ret 4`, so the source signature has one explicit pointer argument and `this` in `ecx`.

Boundary evidence is strong:

- `0x004ba444-0x004ba450` is `0xcc` padding after [UID:000167].
- `0x004ba450` starts a standard frame setup.
- `0x004ba53b-0x004ba540` is `0xcc` padding before [UID:000169].
- There is no internal branch target outside `0x004ba450-0x004ba53b`.
- Raw `.text` rel32 scan found 49 direct code references to `0x004ba450`, matching the target doc's broader 49-code-reference evidence and consistent with the modeled direct-caller count after IDA function-boundary grouping.

## Behavior Summary For Incorporation

`GrafPort::DrawRectFrame` takes a four-integer rectangle pointer. If the draw-enabled byte at `this+0x71` is clear, it returns immediately. Otherwise it obtains the current clip rectangle via `GrafPort::GetClipRect` at `0x004b96c0`, copies the caller rectangle into a stack `RectBounds`, intersects the copy with the clip rectangle via `0x004b7cc0`, and tests the intersection via `0x004b7eb0`. If the clipped rectangle is empty or invalid, it returns without disturbing the current draw cursor.

If the visibility test succeeds, it saves the current cursor fields, sets the draw cursor to the caller rectangle's top-left corner, emits four line-delta callback calls through `dword_69B3E4`, and restores the saved cursor fields. The clipped rectangle is used only as an accept/reject test; the actual edge deltas are computed from the original caller rectangle.

The callback sequence is:

- top edge: `(right - left - 1, 0)`;
- right edge: `(right - currentX - 1, bottom - currentY - 1)` after the top callback has advanced the cursor;
- bottom edge: `(left - currentX, bottom - currentY - 1)`;
- left edge: `(left - currentX, top - currentY)`.

The subtraction from the live cursor is deliberate. [UID:000165] `LineTo` at `0x004b98f0` uses the same cursor fields and jumps through `dword_69B3E4`; the callback target owns cursor advancement. Therefore the second through fourth deltas are not equivalent to simple constant deltas unless the line callback's cursor updates are modeled.

## Heuristic / Inference Reanalysis And Validation

### Receiver, Signature, And Name

Best source-facing method signature:

```cpp
void GrafPort::DrawRectFrame(const RectBounds *rect);
```

Evidence:

- `ecx` is copied to `ebx` and used as the receiver throughout.
- The receiver fields match documented `GrafPort` draw state and helpers.
- `ret 4` proves exactly one explicit argument.
- The argument is copied as 16 bytes with `movups xmm0, [esi]`, and offsets `+0`, `+4`, `+8`, and `+0xc` are consumed as `left`, `top`, `right`, and `bottom`.
- Broad callers from panes and draw code use the function as a generic rectangle-frame primitive, not as a `RankingEventListPane` method.

Rejected alternatives:

- `Surface::DrawRectFrame`: rejected because no `Surface` receiver fields are used. The only Surface-like evidence is the render callback table, which is shared renderer infrastructure used by `GrafPort`.
- `RankingEventListPane::DrawRectFrame`: rejected as caller-biased generated pollution. The function has 49 code references across UI/render callers and no feature-pane-specific state.
- File-static helper taking `GrafPort *`: possible at the ABI level but weaker than a member method. Neighbor draw-state helpers and current source docs consistently model this receiver as `GrafPort`.

### Rectangle Type

Best source type is `RectBounds` or the project typedef/class that is layout-compatible with Win32 `RECT`.

Evidence:

- [UID:00015S], [UID:0000N2], and [UID:0000BU] document the four-int `left`, `top`, `right`, `bottom` layout.
- The helper `0x004b7cc0` is documented as `IntersectRects`, and `0x004b7eb0` is documented as an empty/invalid rectangle predicate.
- The frame body treats `right` and `bottom` as exclusive bounds by subtracting one for the visible edge endpoints.

Rejected alternatives:

- Raw `int *` or anonymous stack struct: rejected because the RectBounds support docs already give the semantic type.
- `SpriteRect` or resource rectangle: rejected because no sprite/resource fields, handles, or Surface blit state are used in [UID:000168].

### GrafPort Fields

Best source-facing field recommendations:

```text
this+0x68 = m_currentY
this+0x6c = m_currentX
this+0x71 = m_drawEnabled
```

Evidence:

- [UID:000162] `GetDrawPosition` at `0x004b95e0` writes `[ecx+0x68]` then `[ecx+0x6c]` to the output point, consistent with the project's point-layout order rather than contradicting the X/Y field names.
- [UID:000162] `MoveTo` at `0x004b9600` stores the first coordinate into `this+0x6c` and the second into `this+0x68`.
- [UID:000162] `OffsetDrawPosition` at `0x004b9620` adds the first delta to `this+0x6c` and the second delta to `this+0x68`.
- [UID:000165] `LineTo` at `0x004b98f0` subtracts `this+0x6c` from the target x and `this+0x68` from the target y before dispatching to `dword_69B3E4`.
- [UID:000168] saves `this+0x6c` in `esi`, saves `this+0x68` in `edi`, seeds `this+0x6c` from `rect.left`, seeds `this+0x68` from `rect.top`, then restores both after the callback sequence.

Rejected alternatives:

- Swapping `+0x68` and `+0x6c`: rejected by `MoveTo` and `LineTo`.
- Naming `+0x71` as visibility, active, or clip-enabled: weaker. The byte gates drawing before clip fetch, intersection, cursor mutation, or callback dispatch, so `m_drawEnabled` is the strongest descriptive name.

### Callees And Callback Slot

Best source-facing names:

```text
0x004b96c0 = GrafPort::GetClipRect(RectBounds *outClip)
0x004b7cc0 = IntersectRects(RectBounds *out, const RectBounds *a, const RectBounds *b)
0x004b7eb0 = IsRectEmptyOrInvalid(const RectBounds *rect)
0x0069b3e4 = g_pfnDrawLineDelta / SurfaceLineDeltaCallbackTable::lineDelta
```

Evidence:

- [UID:000164] models the `0x004b96c0` helper as the `GrafPort` clip-rectangle helper.
- [UID:00015S] models the rectangle helpers and supports the intersection/empty predicate roles.
- [UID:0000TN] and [UID:0001PI] place `0x0069b3e4` in the Surface render callback table.
- [UID:0002PG] and [UID:0002PJ] are no-direct-caller line callback bodies selected through that table.
- [UID:000165] `LineTo` computes target deltas and jumps through `dword_69B3E4`; [UID:000168] computes four deltas and calls the same slot.

Rejected alternatives:

- Naming `dword_69B3E4` as `DrawRectFrameCallback`: rejected because the slot is also used by generic line drawing and receives only deltas, not a rectangle.
- Naming it as a `SurfaceSpriteBlit` callback: rejected because [UID:000167] is adjacent but uses sprite/blit state, while `0x0069b3e4` points at line render callbacks.
- Treating `0x004b7cc0` as a clipping mutator owned by `GrafPort`: rejected because the helper is a generic rectangle helper used outside this method.

### Source Placement

Recommended source placement:

- Method owner: [UID:00005V] `by-class/GrafPort.md`.
- File/emission context: [UID:0000JR] `by-file/GrafPort.md`.
- Shared callback table documentation: [UID:0000TN] / [UID:0001PI] should name slot `0x0069b3e4` as a line-delta callback used by `LineTo` and `DrawRectFrame`.
- `Surface` [UID:0000OC] should keep ownership of shared software renderer callbacks and sprite/blit helpers, but not own [UID:000168].

Rejected source-placement alternatives:

- [UID:0000OC] `Surface`: rejected because the function does not operate on a `Surface` receiver or Surface resource state.
- [UID:000167] `SurfaceSpriteBlitHelper` family: rejected because adjacency is only layout adjacency; [UID:000167] is a blit helper ending at `0x004ba444`, followed by `0xcc` padding before [UID:000168].
- Pane or feature owners such as `RankingEventListPane`: rejected because the function is a shared draw primitive with many callers. Generated caller-biased ownership should be marked stale or pollution.

Relationship to B003's pending [UID:000167] work: this recommendation does not depend on any future [UID:000167] decision. [UID:000167] and [UID:000168] are adjacent in `.text`, and both interact with software-render infrastructure, but their receivers and source roles differ. [UID:000167] can remain Surface/shared-blit while [UID:000168] is a GrafPort rectangle-frame method.

### Range, Split, And Merge Decision

Keep [UID:000168] as a single exact by-memory page. There is no evidence for child splits:

- The target covers one function and one method body.
- The helper calls are already documented elsewhere and should not be absorbed.
- Security-cookie setup/teardown belongs to the compiled body and should not be split.
- The four callback dispatches are one coherent frame-drawing operation, not separable source functions.

Reject merge with [UID:000167], [UID:000169], or [UID:00016A]. The padding before and after [UID:000168] is exact, and the adjacent targets have different helper roles and source owners.

### Generated Output Pollution

The target doc's current wording that the generated owner is `RankingEventListPane` is stale or should be narrowed to historical pollution. Current generated formal output for `auto-generated/NexusTK/render/GrafPort.cpp` does not contain the formal [UID:000168] body because the target C++ block is blank. The simroot recovery copy contains a `GrafPort::DrawRectFrame(const RECT* rect)` body, but it uses generated artifacts such as `GrafPortState_004ba450` and modern fixed-width types. That generated body is useful as a recovery lead only; it is not suitable source C++ for the by-memory formal block.

Supervisor should replace the stale generated-owner statement with:

```text
Historical/generated owner pollution: older recovery output and caller-biased grouping associated this shared draw primitive with feature-pane callers such as RankingEventListPane, but the current source-quality route is the GrafPort class. The formal autogen path is empty only because this target's reconstruction C++ block is blank; once populated, [UID:000168] should emit through GrafPort rather than through a caller pane or Surface.
```

### Remaining Uncertainty And Impact

The remaining uncertainty is source spelling, not source shape:

- The original rectangle type may have been spelled `RECT`, `Rect`, or `RectBounds`. The documented project type and helper family support `RectBounds`; `RECT` is layout-compatible but less project-specific.
- The original field spelling for `this+0x71` is not proven. `m_drawEnabled` is the strongest descriptive name.
- The original callback global name is not proven. `g_pfnDrawLineDelta` or `lineDeltaCallback` is the strongest descriptive name because the callback receives deltas and is shared by line drawing and frame drawing.

Impact: these uncertainties cap confidence below final-source certainty, but they do not block score lift, owner correction, support-doc updates, or first-draft C++.

## First-Draft C++ Recommendation

Populate [UID:000168] formal C++ with a descriptive, source-like body. This draft intentionally does not include a null check because the compiled function does not test the rectangle pointer before reading it.

Recommended formal block:

```cpp
void GrafPort::DrawRectFrame(const RectBounds *rect)
{
    if (!m_drawEnabled)
        return;

    RectBounds clipRect;
    GetClipRect(&clipRect);

    RectBounds visibleRect = *rect;
    IntersectRects(&visibleRect, &clipRect, &visibleRect);
    if (IsRectEmptyOrInvalid(&visibleRect))
        return;

    const int oldX = m_currentX;
    const int oldY = m_currentY;

    m_currentX = rect->left;
    m_currentY = rect->top;

    DrawLineDelta(rect->right - rect->left - 1, 0);
    DrawLineDelta(rect->right - m_currentX - 1,
                  rect->bottom - m_currentY - 1);
    DrawLineDelta(rect->left - m_currentX,
                  rect->bottom - m_currentY - 1);
    DrawLineDelta(rect->left - m_currentX,
                  rect->top - m_currentY);

    m_currentX = oldX;
    m_currentY = oldY;
}
```

Notes for supervisor/source integration:

- `DrawLineDelta(dx, dy)` is a descriptive wrapper over callback slot `dword_69B3E4`. If support docs prefer the global pointer spelling, use `g_pfnDrawLineDelta(this, dx, dy)` with an appropriate `__thiscall` callback typedef in the callback-table support page.
- `RectBounds` may be replaced with the project spelling if later evidence proves a different name, but the layout must remain `left, top, right, bottom`.
- The body uses `visibleRect` only for the clip/empty gate, matching the binary. It does not draw the clipped rectangle.

## Exact Supervisor Edits

### Target Metadata Replacement

In `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`, replace the metadata lines for completion, confidence, canonical owner, and emitter with:

```text
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00005V
EMITTER_UIDS: 00005V
```

If the supervisor intentionally keeps legacy file-level emission for GrafPort methods, keep `EMITTER_UIDS:0000JR` only as a file-emission compatibility route, but the canonical owner should still be the `GrafPort` class [UID:00005V].

### Target Notes Insert

Insert under the target's analysis/status section, or replace the existing open-question bullets with:

```text
2026-06-18 B002 source-quality reanalysis: raw PE/Capstone evidence confirms [UID:000168] is one exact `GrafPort::DrawRectFrame` body at `0x004ba450-0x004ba53b`, with `0xcc` padding at both boundaries and 49 direct rel32 code references. The receiver is `GrafPort *` in `ecx`, the explicit argument is a 16-byte `RectBounds`/RECT-layout pointer, and the function returns with `ret 4`. The draw gate at `this+0x71` should be named `m_drawEnabled`; `this+0x6c` is current X and `this+0x68` is current Y by cross-check against `MoveTo`, `OffsetDrawPosition`, `GetDrawPosition`, and `LineTo`. The body gets the clip rectangle through `0x004b96c0`, intersects a stack copy of the input rect through `0x004b7cc0`, rejects empty/invalid intersections through `0x004b7eb0`, then draws the original rectangle edges through four `dword_69B3E4` line-delta callback calls while preserving/restoring the current draw cursor. The clipped rectangle is a visibility gate only; the edge deltas come from the original caller rectangle.
```

### Target Ownership Replacement

Replace stale generated-owner/caller-pollution wording with:

```text
Ownership/source placement: caller-biased generated ownership such as `RankingEventListPane` is stale pollution. [UID:000168] should be owned by [UID:00005V] `GrafPort` and emitted through the GrafPort source file [UID:0000JR]. The `Surface` relationship is support-only: `dword_69B3E4` is a shared software-render line-delta callback slot documented by the Surface render callback table, but this method operates only on `GrafPort` draw state and calls the callback as a drawing primitive. Adjacent [UID:000167] SurfaceSpriteBlitHelper work does not affect this classification.
```

### Target Formal C++ Replacement

Replace the blank `RECONSTRUCTION_CPP` block with the draft in `## First-Draft C++ Recommendation`, preserving the repository's exact formal-block delimiter format.

### GrafPort Class Support Insert

In [UID:00005V] `by-class/GrafPort.md`, add this support note near the draw-state/rectangle drawing method inventory:

```text
[UID:000168] `0x004ba450-0x004ba53b` is the class-owned `DrawRectFrame(const RectBounds *rect)` method. It gates on `m_drawEnabled` (`this+0x71`), uses `GetClipRect`, `IntersectRects`, and `IsRectEmptyOrInvalid` as a visibility test, seeds `m_currentX`/`m_currentY` from the caller rectangle, emits four `DrawLineDelta` callback calls through `dword_69B3E4`, and restores the saved cursor. The frame is drawn from the original rectangle after clipping acceptance, not from the clipped rectangle.
```

### GrafPort File Support Insert

In [UID:0000JR] `by-file/GrafPort.md`, add this support note near the [UID:000168] row or GrafPort drawing helper list:

```text
[UID:000168] is now source-quality routed through the GrafPort class rather than caller-biased generated owners. It should emit as `GrafPort::DrawRectFrame(const RectBounds *rect)` with support dependency on the Surface render line-delta callback table at `0x0069b3e4`.
```

### Surface Support Insert

In [UID:0000OC] `by-file/Surface.md`, add or update the support note for the callback-table boundary:

```text
[UID:000168] `GrafPort::DrawRectFrame` uses the Surface render line-delta callback slot `0x0069b3e4`, but it is not a Surface-owned helper. Keep Surface ownership for the callback table and software renderer callback bodies; keep [UID:000168] under GrafPort.
```

### Surface Render Callback Table Support Insert

In [UID:0000TN] or [UID:0001PI], strengthen the slot note for `0x0069b3e4`:

```text
`0x0069b3e4` is the line-delta draw callback slot used by `GrafPort::LineTo` and `GrafPort::DrawRectFrame`. The callback receives the active `GrafPort` receiver and signed `dx, dy` deltas, advances the current draw cursor, and dispatches to the selected software renderer implementation such as [UID:0002PG] or [UID:0002PJ].
```

If the callback docs avoid naming `GrafPort` in the typedef, use this neutral wording instead:

```text
`0x0069b3e4` is the line-delta draw callback slot used by GrafPort line/frame drawing. The caller supplies the active draw receiver and signed `dx, dy` deltas; selected software renderer implementations consume the deltas and update draw position.
```

### Generated Output Policy Note

Add to the target or GrafPort support doc:

```text
Do not copy the current simroot recovery body directly. Its `GrafPortState_004ba450` temporary and fixed-width generated types are recovery artifacts. The formal C++ should use the GrafPort class fields and RectBounds helper names documented by the by-* pages.
```

## Coverage Row Recommendation

Replace the [UID:000168] row in `by-memory/-coverage-report.md` with:

```text
    - [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) 0x004ba450-0x004ba53b | class method | GrafPort::DrawRectFrame : reconstructable : 88% : very-strong : B002 2026-06-18 source-quality reanalysis confirms exact `0xeb`-byte body, padded boundaries, 49 direct rel32 code references, draw-enabled byte `this+0x71`, cursor fields `this+0x6c` current X and `this+0x68` current Y, RectBounds visibility gate through `GetClipRect`, `IntersectRects`, and `IsRectEmptyOrInvalid`, four `dword_69B3E4` line-delta callback dispatches over the original rectangle edges, stale RankingEventListPane/Surface owner rejection, GrafPort class owner/emitter recommendation [UID:00005V], and first-draft C++ readiness.
```

If the supervisor keeps file-level emitter compatibility, change the phrase `GrafPort class owner/emitter recommendation [UID:00005V]` to `GrafPort class owner [UID:00005V] with file emission through [UID:0000JR]`.

## Validator Commands

Run after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [000168-GrafPortDrawRectFrame-source-quality-removed.md](000168-GrafPortDrawRectFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If validator names differ in the local toolchain, use the repository's standard single-file validation command for the same paths plus the coverage report and autogen/rescore passes.

## Changed Files / Direct-Edit Statement

Created this report only:

```text
tools/leaser/Agents/Agent-B002/research/000168-GrafPortDrawRectFrame-source-quality.md
```

No by-* docs, generated reports/source, IDA database, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/000168-GrafPortDrawRectFrame-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:24","uid":"000168"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000168-GrafPortDrawRectFrame-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/000168-GrafPortDrawRectFrame-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000168"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
