** TARGET-REPORT-UID:0002F9 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002F9] ChattingModifyHeightPaneOnPaint source-quality report

Status: FINISHED B-agent report-only research.

Agent: B011
Date: 2026-06-19
Assignment: source-quality / heuristic research for [UID:0002F9] `ChattingModifyHeightPaneOnPaint`

## Target Paths

- Primary target: `source-3/project-documentation/by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md`
- Current coverage row owner, not edited by this report: `source-3/project-documentation/by-memory/-coverage-report.md`
- Prior related B011 cluster report preserved and not overwritten: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`

## Executive Recommendation

[UID:0002F9] should stay source-bearing as `ChattingModifyHeightPane::OnPaint()`. It is not compiler glue and it is not a no-code row. The body is an ordinary virtual paint method reached through the `ChattingModifyHeightPane` vtable, with no direct modeled callers, which is normal for UI paint entries.

Recommended metadata:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `84` | `87` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `00001W` | `00001W` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00001W` | `00001W` |
| Formal C++ | blank | populate first-draft C++ |

The active source-emission gate is met: `RECONSTRUCTABLE:TRUE`, nonblank emitter route, and `(87 + 92) / 2 = 89.5`, above the current 85/85 combined-score gate. The old below-95 blank-C++ rationale should be replaced with a current gate analysis and the target-specific helper-name caveat described below.

The most important wording correction is that the paint and disabled refresh target is the inherited pane rectangle at `this+0x44` (`m_rect` / `m_bounds`), not the `ChattingModifyHeightPane` geometry field at `this+0x100` (`m_handleRect`). Neighboring constructor/set-line-count/cancel paths use `m_handleRect` to drive the pane bounds, but this method reads `this+0x44` directly.

## Evidence Checked

### Local binary evidence

Checked local PE bytes and decoded instructions from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.

- `.text` base: `0x00401000`
- Function body: `0x00480bb0-0x00480c45`, size `0x95`
- Preceding bytes: `0x00480ba3-0x00480bb0`, thirteen `0xcc` bytes
- Trailing bytes: `0x00480c45-0x00480c50`, eleven `0xcc` bytes
- No direct rel32 call/jump references to `0x00480bb0`
- One absolute pointer-table reference to `0x00480bb0` at `0x00614e5c`, the `ChattingModifyHeightPane` primary vtable paint slot
- Stack cookie prologue and two stack-cookie exits are compiler instrumentation, not source behavior

Decoded body:

```asm
00480bb0 push ebp
00480bb1 mov ebp, esp
00480bb3 sub esp, 0x2c
00480bb6 mov eax, dword ptr [0x672f24]
00480bbb xor eax, ebp
00480bbd mov [ebp-4], eax
00480bc0 mov eax, dword ptr [0x67ade0]
00480bc5 push esi
00480bc6 mov esi, ecx
00480bc8 push edi
00480bc9 cmp byte ptr [eax+0x118], 0
00480bd0 lea edi, [esi+0x44]
00480bd3 je 0x480c1c
00480bd5 lea ecx, [ebp-0x2c]
00480bd8 call 0x457a60
00480bdd mov ecx, dword ptr [0x67a744]
00480be3 lea eax, [ebp-0x2c]
00480be6 push eax
00480be7 push 0
00480be9 push 0x615300
00480bee call 0x4d02f0
00480bf3 push 0
00480bf5 push 0x615318
00480bfa push 0
00480bfc push edi
00480bfd lea eax, [ebp-0x1c]
00480c00 mov ecx, esi
00480c02 push eax
00480c03 lea eax, [ebp-0x2c]
00480c06 push eax
00480c07 call 0x4b9980
00480c0c pop edi
00480c0d pop esi
00480c0e mov ecx, [ebp-4]
00480c11 xor ecx, ebp
00480c13 call 0x5c772f
00480c18 mov esp, ebp
00480c1a pop ebp
00480c1b ret
00480c1c push 1
00480c1e call 0x5446b0
00480c23 push 0
00480c25 mov ecx, esi
00480c27 call 0x4b9660
00480c2c push edi
00480c2d mov ecx, esi
00480c2f call dword ptr [0x69b3fc]
00480c35 mov ecx, [ebp-4]
00480c38 pop edi
00480c39 xor ecx, ebp
00480c3b pop esi
00480c3c call 0x5c772f
00480c41 mov esp, ebp
00480c43 pop ebp
00480c44 ret
```

Absolute and rel32 reference checks from the local PE:

- `0x0067ade0` (`g_pChattingHandlePane`) has 15 absolute refs, including the read at `0x00480bc1`.
- `0x0067a744` (`g_pEPFLib`) has 231 absolute refs, including the read at `0x00480bdd`.
- `0x00615300` resolves to wide string `CHATSC.EPF`; the local ref check found the target callsite as its only absolute use.
- `0x00615318` resolves to wide string `invenbut.pal`; it is shared and includes the target callsite.
- `0x0069b3fc` (`dword_69B3FC`) has 206 absolute refs, including the target indirect call at `0x00480c2f`.
- `0x0069b3e8` (`dword_69B3E8`) has 114 absolute refs and is the lower render-blit slot used by shared `RenderTileFrame`.
- Direct target callees are `0x00457a60`, `0x004d02f0`, `0x004b9980`, `0x005446b0`, `0x004b9660`, indirect `0x0069b3fc`, and security-cookie check `0x005c772f`.

### Live disassembler availability

Attempted live IDA MCP at `http://127.0.0.1:13337/mcp` during this pass. It timed out, so no live rename/type operation was performed. This report relies on local PE bytes/Capstone-style decoding and existing IDA-backed project documentation.

### Project documentation checked

- `by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`
- `by-class/ChattingModifyHeightPane.md`
- `by-file/Chatting.md`
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`
- `by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md`
- `by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md`
- `by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md`
- `by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md`
- `by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md`
- `by-class/ChattingHandlePane.md`
- `by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md`
- `by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`
- `by-global/g_pEPFLib.md`
- `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`
- `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
- `by-memory/0x005446b0-0x005446d4.PaneSetMode.md`
- `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- `by-global/SurfaceRenderCallbackTable.md`
- `by-memory/0x00615284-0x00615460.ChattingStringResourceData.md`
- `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`
- Prior B011 cluster report `0002F9-0002G8-0002GA-0002GE-0002GF-0002GG-ChattingPaintColorMessage-source-quality.md`

## Boundary, Reachability, and Split/Merge Decision

The exact half-open range should remain `0x00480bb0-0x00480c45`.

The preceding padding `0x00480ba3-0x00480bb0` and following padding `0x00480c45-0x00480c50` prove there is no hidden fallthrough fragment. The body has a normal MSVC stack-cookie prologue and two return sites. There is no tail merge with the next body and no embedded raw helper.

Reachability should be documented as vtable-only:

- Primary `ChattingModifyHeightPane` vtable pointer at `0x00614e5c` references `0x00480bb0`.
- Constructor installs the class vtable family around `0x00614e18`, `0x00614e64`, and `0x00614e94`.
- Neighboring support docs place the `OnPaint` entry in the `ChattingModifyHeightPane` primary vtable.
- No direct code callers are expected for this virtual paint method.

Rejected split/merge alternatives:

- Do not merge this with [UID:000104] `ChattingUI`; that aggregate may summarize it but should not own the emitted C++ body.
- Do not route it to `Surface`, `ImageLib`, `ResourceLayoutTable`, or `GrafPort`; those are shared dependencies.
- Do not split the enabled and disabled branches into child rows; both are source branches of one virtual method.
- Do not reclassify it as compiler-generated glue. It has real branch logic, resource strings, global state gating, and rendering calls.

## Source Behavior

Source-facing shape:

```cpp
void ChattingModifyHeightPane::OnPaint()
```

Enabled branch:

1. Reads `g_pChattingHandlePane->m_secondaryChatEnabled` at global `0x0067ade0`, object offset `+0x118`.
2. Computes the destination rectangle as `this + 0x44`, the inherited pane bounds / rectangle.
3. Initializes a stack `EPFTileContext` at `[ebp-0x2c]` through `0x00457a60`.
4. Calls `g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tile)` through `0x004d02f0`.
5. Calls shared `RenderTileFrame` at `0x004b9980` with:
   - receiver: `this`
   - tile/context pointer: `[ebp-0x2c]`
   - frame/draw record scratch: `[ebp-0x1c]`
   - destination: `this + 0x44`
   - frame/flag parameter: `0`
   - palette: `L"invenbut.pal"`
   - trailing flag: `0`

Disabled branch:

1. Calls `Pane::SetMode(1)` at `0x005446b0`.
2. Calls the shared GrafPort draw-state setter at `0x004b9660` with color/state value `0`.
3. Calls `dword_69B3FC(this, this + 0x44)`, the shared surface refresh/fill/invalidation callback-table slot.

The disabled branch should be described as an inactive/clear refresh path. It is not safely just "hidden state" and not safely just "transparent state." The code does not write a visibility byte, alpha field, or transparency flag. It sets Pane mode `1`, clears the active draw/color state to `0`, and asks the surface callback to refresh/fill the current pane bounds. The sibling [UID:0002F3] `ChattingBackPaneUpdateVisibility` uses the same `Pane::SetMode(1)` plus color `0` plus `dword_69B3FC(this, this+0x44)` pattern for the inactive path, which supports the source-level interpretation as disabled/inactive clear redraw.

## Fields, Globals, Helpers, and Name Recommendations

| Address / offset | Recommended source-facing role | Evidence and caveat |
| --- | --- | --- |
| `0x00480bb0` | `ChattingModifyHeightPane::OnPaint` | Vtable-only virtual paint method; class page and vtable docs already route the slot to this class. |
| `0x00614e5c` | `ChattingModifyHeightPane` primary vtable paint slot | Sole absolute function-pointer ref to the body. |
| `0x0067ade0` | `g_pChattingHandlePane` | Global page and class support docs already use this name; target reads through it once. |
| `g_pChattingHandlePane + 0x118` | `m_secondaryChatEnabled` | Neighboring mouse/visibility docs and `ChattingHandlePane` support map this byte to secondary-chat enabled state. |
| `this + 0x44` | inherited `Pane::m_rect` / `Pane::m_bounds` | Target loads this address into `edi` before the branch and passes it to both render/refresh paths. This is not the `m_handleRect` field at `+0x100`. |
| `this + 0x100` | `m_handleRect` | Used by constructor/set-line-count/cancel paths to track handle geometry; not read directly by this paint body. |
| `0x00457a60` | `EPFTileContext::Initialize` / `InitEPFTileContext` | Aggregate docs show a 0x28-byte context initializer; target uses it on the local tile context. |
| `0x0067a744` | `g_pEPFLib` | Global docs already name the image/resource library pointer. |
| `0x004d02f0` | `ResourceLayoutTable::LookupLayoutEntry` | Resource layout lookup docs show receiver-style call with resource name, frame index, and optional context output. |
| `0x00615300` | `L"CHATSC.EPF"` | `ChattingStringResourceData` documents the string and target xref. Local ref check found the target as its specific absolute use. |
| `0x00615318` | `L"invenbut.pal"` | Shared UI palette string; target passes it to the tile-frame render helper. |
| `0x004b9980` | shared `RenderTileFrame` | Surface paint-helper docs show broad shared use and reject generated `FittingRoomDownloadControlPane` ownership pollution. |
| `[ebp-0x1c]` | `FrameDrawRecord` / tile-frame scratch | Same style as populated `TotemFrame::OnPaint`; exact original type name remains provisional. |
| `0x005446b0` | `Pane::SetMode(unsigned char)` | Dedicated Pane docs define this helper; mode values remain project-specific. |
| `0x004b9660` | `SetGrafPortColorState` / `SetDrawColor` | Shared GrafPort draw-state setter. Use `SetGrafPortColorState(0)` in Chatting paint C++ for consistency with `ChattingPane::OnPaint`; `SetDrawColor` remains acceptable in control constructors. |
| `0x0069b3fc` | `g_surfaceRenderCallbacks->RefreshPaneRegion` / slot `dword_69B3FC` | Surface callback-table docs record 206 xrefs and warn that generated alias `g_pfnLockSurface` is suspect. Target call shape is `(this, this+0x44)`. |

## Open Questions Closed

### Shared EPF/render helper names

Best supported names:

- `EPFTileContext::Initialize()` or `InitEPFTileContext(&tile)` for `0x00457a60`.
- `g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tile)` for `0x004d02f0`.
- `RenderTileFrame(&tile, &drawRecord, &m_rect, 0, L"invenbut.pal", 0)` for `0x004b9980`.
- `SetGrafPortColorState(0)` for `0x004b9660`.
- `g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect)` for `0x0069b3fc`.

These are descriptive source-facing names already supported by neighboring docs. The exact original typedefs and wrapper spellings are still not fully proven, so the confidence should remain below 95. This caveat does not block first-draft C++.

### Disabled branch meaning

Resolved as disabled/inactive clear refresh. It is not enough to call it a hidden branch, because no hidden/visible field is written. It is not enough to call it a transparent branch, because no alpha or transparency flag is written. The binary sequence is specifically:

```cpp
SetMode(1);
SetGrafPortColorState(0);
g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);
```

Sibling `ChattingBackPaneUpdateVisibility` supports the same state model: inactive mode plus zero color plus surface refresh clears/redraws the pane's region.

### Source placement

Resolved to class owner [UID:00001W] `ChattingModifyHeightPane` and file route [UID:0000I5] `Chatting`. The method is part of the `ChattingModifyHeightPane` class range `0x004807b0-0x00480c45` and the larger [UID:000104] `ChattingUI` aggregate, but the direct emitter should stay with the class page.

### Vtable-only liveness

Resolved. Vtable-only reachability is expected and sufficient for a virtual paint method. The absence of direct calls is not a blocker and should not be worded as suspicious liveness.

### Formal C++ readiness

Resolved as ready. The helper names are still role names, but they are not compiler-generated garbage names and they match adjacent first-draft paint C++ style. This is enough for the current emission gate.

## First-Draft C++ Recommendation

Populate the target formal C++ block with:

```cpp
void ChattingModifyHeightPane::OnPaint()
{
    if (!g_pChattingHandlePane->m_secondaryChatEnabled) {
        SetMode(1);
        SetGrafPortColorState(0);
        g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect);
        return;
    }

    EPFTileContext tile;
    FrameDrawRecord drawRecord;

    tile.Initialize();
    g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tile);
    RenderTileFrame(&tile, &drawRecord, &m_rect, 0, L"invenbut.pal", 0);
}
```

Notes for implementation:

- `m_rect` is the inherited `this+0x44` bounds. Do not replace it with `m_handleRect` in this method.
- `FrameDrawRecord` is the best current role name for the `[ebp-0x1c]` scratch record. It follows the nearby populated `TotemFrame::OnPaint` style and is preferable to raw `char scratch[24]`.
- `SetGrafPortColorState` follows the already-populated `ChattingPane::OnPaint` vocabulary. If the project later standardizes this helper as `SetDrawColor`, the call can be mechanically renamed.
- The direct binary call to `dword_69B3FC` is intentionally expressed through the documented surface callback-table role.

## Score Rationale

Recommended `87/92`.

Completion increases from `84` to `87` because the target now has:

- exact boundary and padding proof,
- route-confirmed vtable-only virtual reachability,
- resolved class/file owner and emitter,
- resolved `g_pChattingHandlePane + 0x118` field role,
- resolved render asset/palette/global dependencies,
- resolved disabled branch semantics,
- corrected destination rectangle field,
- first-draft C++ ready under the active gate.

Confidence increases from `90` to `92` because local PE bytes, support docs, string refs, vtable data, and sibling paint/update behavior agree. It should remain below 95 because exact original names for `FrameDrawRecord`, the final public spelling of `0x004b9660`, and the exact callback-table typedef for `dword_69B3FC` are still role-level rather than source-header proven.

## Recommended Target Doc Changes

In `by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md`:

1. Update metadata:
   - `COMPLETION:87`
   - `CONFIDENCE:92`
   - keep `CANONICAL_OWNER:00001W`
   - keep `RECONSTRUCTABLE:TRUE`
   - keep `EMITTER_UIDS:00001W`
2. Populate the formal C++ block with the draft above.
3. Replace stale below-95 blank-C++ text with current combined-score/emitter gate wording.
4. State that this is a source-authored virtual paint method, not no-code glue.
5. Record exact boundary and padding:
   - body `0x00480bb0-0x00480c45`
   - prepad `0x00480ba3-0x00480bb0`, 13 `0xcc`
   - postpad `0x00480c45-0x00480c50`, 11 `0xcc`
6. State vtable-only reachability through `0x00614e5c`; no direct code callers expected.
7. Add or correct field wording:
   - enabled flag: `g_pChattingHandlePane->m_secondaryChatEnabled` at `+0x118`
   - render/refresh destination: inherited `m_rect`/`m_bounds` at `this+0x44`
   - do not describe the direct destination as `m_handleRect` at `+0x100`
8. Document enabled branch helper sequence:
   - `EPFTileContext::Initialize`
   - `g_pEPFLib->LookupLayoutEntry(L"CHATSC.EPF", 0, &tile)`
   - `RenderTileFrame(..., &m_rect, 0, L"invenbut.pal", 0)`
9. Document disabled branch as inactive/clear refresh:
   - `Pane::SetMode(1)`
   - `SetGrafPortColorState(0)` / shared `0x004b9660`
   - `g_surfaceRenderCallbacks->RefreshPaneRegion(this, &m_rect)` / `dword_69B3FC(this,this+0x44)`
10. Remove any active language that says final C++ is blocked solely by a 95/95 threshold.

## Recommended Support Doc Changes

These should be applied only if the supervisor sends an implementation callback.

### `by-class/ChattingModifyHeightPane.md`

Recommended updates:

- Update the `OnPaint` row to say it is first-draft C++ ready at `87/92`.
- State that it gates on `g_pChattingHandlePane->m_secondaryChatEnabled` (`+0x118`).
- State that enabled paint draws `CHATSC.EPF` frame `0` with `invenbut.pal`.
- Correct the rectangle wording: the method passes inherited `this+0x44` bounds to the render/refresh helpers; `m_handleRect` remains the class-local geometry field maintained by constructor/set-line-count/cancel.
- State the disabled branch is inactive/clear refresh via `Pane::SetMode(1)`, `SetGrafPortColorState(0)`, and `dword_69B3FC`.
- Preserve class-wide caveats only for final helper typedef/original spelling; do not let those block [UID:0002F9].

### `by-file/Chatting.md`

Recommended updates:

- Add a B011 2026-06-19 note that [UID:0002F9] is source-ready in `ChattingModifyHeightPane`.
- Keep it under `Chatting` / `social/Chatting.cpp`; do not route it to `Surface`, `ImageLib`, `ResourceLayoutTable`, or a ChatColor-specific split.
- Mention the helper dependencies as shared renderer/resource dependencies, not Chatting-owned helpers.
- Mention that the disabled branch is inactive/clear refresh, not a direct hide/transparent setter.

### `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`

Recommended updates:

- Update the [UID:0002F9] child summary to include first-draft C++ readiness and the exact branch roles.
- Correct the destination wording to inherited `this+0x44` bounds.
- Preserve aggregate ownership as summary only; the emitted body remains with [UID:00001W].

### Optional support notes

`by-memory/0x00615284-0x00615460.ChattingStringResourceData.md` and `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md` are already sufficient, but implementation may add one-line cross-reference improvements if touched:

- `CHATSC.EPF` at `0x00615300` is the `ChattingModifyHeightPane::OnPaint` enabled-branch art resource.
- `invenbut.pal` at `0x00615318` is the shared UI palette used by this target.
- `0x00614e5c` is the primary vtable paint slot for [UID:0002F9].

No required edits are recommended for `PaneSetMode`, `GrafPortDrawStateAccessors`, `SurfacePaintHelpers`, `SurfaceRenderCallbackTable`, or `g_pEPFLib`; those docs already contain enough shared-helper evidence.

## Rejected Alternatives

- No-code compiler glue: rejected. The method has source-facing branch logic, reads a class/global UI state field, loads named art, and paints or clears a pane region. Stack cookie code is compiler output, but the function is not.
- Direct `m_handleRect` paint: rejected. The instruction at `0x00480bd0` computes `esi + 0x44`; no instruction reads `esi + 0x100`.
- Hidden-only disabled state: rejected. The binary does not set a hidden/visible field.
- Transparent-only disabled state: rejected. The binary does not set alpha or transparency; it sets mode `1`, color/state `0`, and refreshes/fills through the surface callback.
- Source owner `Surface`, `ImageLib`, `ResourceLayoutTable`, or `GrafPort`: rejected. Those are callees/dependencies, not the method owner.
- Generated helper owner `FittingRoomDownloadControlPane::RenderTileFrame`: rejected as known shared-helper owner pollution.
- Generated alias `g_pfnLockSurface` for `0x0069b3fc`: rejected for this target; the call shape and support docs make the broad surface refresh/fill callback role more accurate.

## IDA Rename, Type, and Comment Recommendations

No live IDA edits were performed. Suggested future names/comments:

- Function `0x00480bb0`: `ChattingModifyHeightPane::OnPaint`.
- Vtable slot comment at `0x00614e5c`: `ChattingModifyHeightPane::OnPaint`.
- `ChattingHandlePane + 0x118`: `bool m_secondaryChatEnabled`.
- `ChattingModifyHeightPane` inherited offset `+0x44`: `RectBounds m_rect` / `m_bounds`; comment that OnPaint uses this field directly.
- `ChattingModifyHeightPane + 0x100`: `RectBounds m_handleRect`; comment that it is geometry source for bounds but not the direct OnPaint destination.
- `0x00457a60`: `EPFTileContext::Initialize` or `InitEPFTileContext`.
- `0x004d02f0`: `ResourceLayoutTable::LookupLayoutEntry`.
- `0x004b9980`: `RenderTileFrame`; comment "shared Surface/render wrapper, not FittingRoom-owned."
- `0x004b9660`: `SetGrafPortColorState` / `SetDrawColor`; comment "writes active GrafPort draw/color state at `this+0x74`."
- `0x0069b3fc`: comment "Surface render callback-table slot 7, refresh/fill/invalidation callback, target call shape `(GrafPortOrPane*, const RectBounds*)`."
- `0x00615300`: resource string `L"CHATSC.EPF"`.
- `0x00615318`: resource string `L"invenbut.pal"`.

## Exact Pending Coverage Row

Do not edit `by-memory/-coverage-report.md` during report-only work. If the implementation callback is accepted, replace the existing [UID:0002F9] row with:

```text
        - [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) 0x00480bb0-0x00480c45 | virtual paint method | ChattingModifyHeightPaneOnPaint : reconstructable : 87% : very strong : B011 2026-06-19 source-quality reanalysis confirms exact `0x95` body, 13-byte prepad and 11-byte postpad, vtable-only entry at `0x00614e5c`, no direct code callers, `g_pChattingHandlePane->m_secondaryChatEnabled` gate at `+0x118`, enabled branch `EPFTileContext` init, `g_pEPFLib`/`ResourceLayoutTable::LookupLayoutEntry("CHATSC.EPF",0,&tile)`, `RenderTileFrame` with `invenbut.pal` into inherited Pane bounds `this+0x44`, disabled inactive/clear branch `Pane::SetMode(1)`, shared GrafPort color state `0`, and `dword_69B3FC(this,this+0x44)` surface refresh; first-draft C++ ready with shared helper names descriptive.
```

## Implementation Checklist for Later Callback

If supervisor accepts this report, implementation should:

1. Edit only the accepted target/support docs and keep unrelated concurrent edits intact.
2. Update target metadata to `87/92`, owner/emitter unchanged.
3. Insert the recommended formal C++ block.
4. Replace stale below-95 wording with active 85/85 gate analysis.
5. Add exact range, padding, vtable-only reachability, strings, globals, field offsets, and helper roles to the target.
6. Correct any `m_handleRect`-as-paint-target wording to inherited `m_rect`/`m_bounds` at `this+0x44`.
7. Add the support-doc notes listed above.
8. Do not edit `by-memory/-coverage-report.md` unless supervisor explicitly owns that change; use the exact row above.
9. Run scoped validation from `source-3/project-documentation`.

Expected validation commands after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional string/vtable support notes are touched, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because this recommendation populates formal C++ where it was previously blank, run autogen validation/refresh if the validator does not do it implicitly:

> Executable block R003 was removed from this report and preserved verbatim in [0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md](0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validation was not run for this report-only pass because no by-* documentation was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002F9"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002F9-ChattingModifyHeightPaneOnPaint-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002F9-ChattingModifyHeightPaneOnPaint-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002F9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
