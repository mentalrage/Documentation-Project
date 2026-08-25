** TARGET-REPORT-UID:0002JE **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0002JE] SeparatorMenuItemDrawSeparator source-quality report

Report-only B-agent pass for:

- Target: `source-3/project-documentation/by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md`
- Required coverage note target: `source-3/project-documentation/by-memory/-coverage-report.md`
- Status: report created only. No target/support by-* docs were edited. `by-memory/-coverage-report.md` was not edited.

## Recommendation

Implement this target as a reconstructable `SeparatorMenuItem` virtual draw override and populate first-draft C++.

Recommended target metadata:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000CY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CY
```

The current `84/90` page already has the correct direct owner/emitter route through [UID:0000CY] `SeparatorMenuItem` and source root [UID:0000MN] `NexusTK/ui/menu/PopupMenuControls.cpp`. The stale "no C++ until source-quality pass" reasoning should be replaced with the current 85/85 gate analysis:

- [UID:0002JE] is reconstructable.
- Its emitter route is live through [UID:0000CY] `SeparatorMenuItem`, whose canonical owner/emitter is [UID:0000MN] `PopupMenuControls`.
- The combined target score is above the current first-draft threshold, and this pass raises the recommended score to `88/92`.
- The source signature, owner, vtable slot, bounds fields, draw-state helper, and render callback role are resolved enough for a mid-2000s source-style first draft.

Preferred source name/signature:

```cpp
void SeparatorMenuItem::DrawItem(GrafPort *port)
```

The current filename and title use `DrawSeparator`, which is acceptable as a descriptive documentation label, but the source-facing virtual should be `DrawItem`. This aligns the separator slot with sibling [UID:0002JA] `StringMenuItem::DrawItem` and the `MenuItem` vtable slot `+0x14`.

Implementation readiness: ready. No split is needed.

## Evidence checked

- Read current target [UID:0002JE] `0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md`.
- Read support docs:
  - [UID:0000CY] `by-class/SeparatorMenuItem.md`
  - [UID:0000MN] `by-file/PopupMenuControls.md`
  - [UID:00007V] `by-class/MenuItem.md`
  - [UID:0001V5] `by-type/by-struct/MenuItemLayouts.md`
  - [UID:0001Y4] `by-type/by-vtable/MenuItemVtables.md`
  - [UID:0002JA] `StringMenuItemDrawItem`
  - [UID:0002JB] `SeparatorMenuItemConstructor`
  - [UID:0002JC] `SeparatorMenuItemGetDefaultDimensions`
  - [UID:0002JD] `SeparatorMenuItemGetStyleFlags`
  - [UID:0001BK] `MenuPaneAndItems`
  - [UID:00007W] `by-class/MenuPane.md`
  - [UID:000162] `GrafPortDrawStateAccessors`
  - [UID:0000AO] `by-class/GrafPort.md`
  - [UID:0000TL] `by-file/GrafPort.md`
  - [UID:0000TN] `SurfaceRenderCallbackTable`
  - [UID:0001PI] `0x0069b3e0-0x0069b424.SurfaceRenderCallbackTable`
- Read `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Searched executed prior B-agent reports for `SeparatorMenuItem`, `DrawSeparator`, `PopupMenuControls`, `dword_69B3FC`, and `0x004b9660`.
- Performed read-only PE checks against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- IDA MCP was attempted at `127.0.0.1:13337` and was unavailable in this run. Conclusions below use the current docs plus local PE/Capstone evidence.

## Binary and range findings

Exact target range:

```text
0x00517250-0x005172be
```

No split or merge is recommended.

- The function body starts at `0x00517250`.
- The function returns at `0x005172bd` with `ret 4`.
- The successor adjustor thunk starts at `0x005172be`; it must remain separate.
- The predecessor byte before the function is padding/alignment, not source body.
- Local PE absolute-reference scan found exactly one absolute reference to `0x00517250`: the SeparatorMenuItem vtable word at `0x0061ebe4`.
- Local PE rel32 scan found no direct `call`/`jmp` references to `0x00517250`.

Relevant SeparatorMenuItem vtable words from the local image:

```text
0x0061ebe0 +0x10 -> 0x005ca28c
0x0061ebe4 +0x14 -> 0x00517250  // DrawItem
0x0061ebe8 +0x18 -> 0x00517220  // GetDefaultDimensions
0x0061ebec +0x1c -> 0x00517240  // GetStyleFlags
```

The function body is normal source code plus compiler security-cookie instrumentation. The security-cookie prologue/epilogue is not source-level logic.

## Caller and virtual-slot evidence

The separator draw function has no direct code callers because it is reached by the `MenuItem` virtual draw slot.

The shared menu draw/render helper inside [UID:0001BK] dispatches item rendering through the same slot:

```text
0x005168eb  mov eax, [edi]        ; item vtable
0x005168ed  mov ecx, edi          ; item this
0x005168ef  push esi              ; MenuPane/GrafPort draw context
0x005168f0  call dword ptr [eax+0x14]
```

The return value is ignored after this call, which supports source signature `void DrawItem(GrafPort *port)` even though the binary leaves the render callback's EAX value live at the end of [UID:0002JE].

Sibling [UID:0002JA] uses the same vtable slot and is already modeled as:

```cpp
void StringMenuItem::DrawItem(GrafPort *port)
```

This is the strongest naming/signature evidence. `DrawSeparator` is a behavior label, not the best source virtual name.

## Function behavior

Read-only Capstone disassembly confirms the target behavior:

```text
0x00517262  mov edi, [ebp+8]       ; port/draw context
0x00517265  mov esi, ecx           ; this
0x00517267  push 0x80
0x0051726c  mov ecx, edi
0x0051726e  mov byte ptr [edi+0x70], 0
0x00517272  call 0x004b9660
0x00517277  mov eax, [esi+0x10]    ; m_bounds.bottom
0x0051727a  add eax, [esi+0x08]    ; + m_bounds.top
0x0051727d  cdq
0x0051727e  sub eax, edx
0x00517280  sar eax, 1             ; signed /2, C++ int division shape
0x00517282  lea ecx, [eax-1]       ; separatorRect.top
0x00517285  add eax, 2             ; separatorRect.bottom
0x00517288  mov [ebp-0x08], eax
0x0051728b  mov eax, [esi+0x04]    ; m_bounds.left
0x0051728e  add eax, 3
0x00517291  mov [ebp-0x10], ecx
0x00517294  mov [ebp-0x14], eax
0x00517297  mov ecx, edi
0x00517299  mov eax, [esi+0x0c]    ; m_bounds.right
0x0051729c  sub eax, 3
0x0051729f  mov [ebp-0x0c], eax
0x005172a2  lea eax, [ebp-0x14]
0x005172a5  push eax
0x005172a6  call dword ptr [0x0069b3fc]
```

Resolved source behavior:

- Takes `this` as a `SeparatorMenuItem *`.
- Takes one explicit parameter, the menu draw context, best typed as `GrafPort *port`.
- Clears `port+0x70`, the active draw/blit mode byte. Recommended source field spelling is `m_drawMode`; if GrafPort support docs standardize on `m_renderMode`, use that project spelling instead.
- Calls `0x004b9660(port, 0x80)`, the shared GrafPort active draw/fill color setter storing into `port+0x74`. Source-facing name should be `GrafPort::SetDrawColor(0x80)` or, less specifically, `SetFillColor(0x80)`. `SetDrawColor` is preferred for this report because existing B-agent support for `0x004b9660` describes active draw/fill state rather than text color.
- Builds a stack `RectBounds separatorRect` from inherited `MenuItem::m_bounds` at `this+0x04`.
- Computes `centerY = (m_bounds.top + m_bounds.bottom) / 2` using signed integer division by two.
- Sets the separator rectangle:
  - `left = m_bounds.left + 3`
  - `top = centerY - 1`
  - `right = m_bounds.right - 3`
  - `bottom = centerY + 2`
- Calls `dword_69B3FC` with `ECX=port` and one stack argument, `&separatorRect`.

The render callback result is not source-visible here. The source function should be `void`.

## Helper, global, and field names

Recommended source-facing names:

| Binary name/address | Recommended name | Confidence | Evidence |
|---|---|---:|---|
| `sub_517250` / current `DrawSeparator` label | `SeparatorMenuItem::DrawItem` | High | Vtable slot `+0x14`, sibling `StringMenuItem::DrawItem`, caller dispatches generic item draw slot and ignores return. |
| explicit argument `[ebp+8]` / `a2` | `GrafPort *port` | High | Same argument shape as StringMenuItem draw slot; MenuPane draw helper pushes the pane/draw context; target calls GrafPort draw-state helper and surface render callback. |
| `0x004b9660` | `GrafPort::SetDrawColor` | High | Existing GrafPort draw-state support identifies `this+0x74` active draw/fill color. This target passes color `0x80`. |
| `dword_69B3FC` | `g_surfaceRenderCallbacks.fillOrInvalidate` or `g_pfnFillOrInvalidateRect` | Medium-high | Existing surface callback support labels slot 7 as fill/invalidate/present rect callback; target calls it with `GrafPort *` and `RectBounds *`. Exact original typedef/name remains unproven. |
| `port+0x70` | `m_drawMode` / project-spelling `m_renderMode` | Medium-high | Multiple GrafPort users treat `+0x70` as active draw/blit mode. Exact original field spelling is not proven. |
| `port+0x74` | `m_drawColor` / active draw color | High | `0x004b9660` stores the pushed color there. |
| `this+0x04..0x10` | `m_bounds` (`RectBounds`) | High | MenuItem layout support and all menu item drawing/metrics docs agree on inherited bounds at `+0x04`. |
| stack local `[ebp-0x14..-0x08]` | `RectBounds separatorRect` | High | Four contiguous ints passed to the rect render callback. |

Rejected generated/raw names:

- Reject `sub_517250` as a final source name.
- Reject `DrawSeparator(FittingRoomListPane *)` as source-quality naming. The behavior draws a separator, but the source virtual slot is the same `DrawItem(GrafPort *)` slot as other menu items.
- Reject `FittingRoomListPane::SetTextColor` for `0x004b9660`. That generated name is stale/out-of-context for this target; the helper operates on `GrafPort` draw state.
- Reject `g_pfnLockSurface` or similar lock-only names for `dword_69B3FC`. The reviewed call sites and support docs show rect fill/invalidate/presentation behavior.

## Source ownership and placement

Keep:

```text
CANONICAL_OWNER:0000CY
EMITTER_UIDS:0000CY
```

Source placement remains:

```text
NexusTK/ui/menu/PopupMenuControls.cpp
```

Reasoning:

- The body is class-specific vtable method code for `SeparatorMenuItem`.
- The direct vtable word is inside the `SeparatorMenuItem` vtable region.
- Sibling separator methods [UID:0002JC] and [UID:0002JD] are owned by [UID:0000CY].
- [UID:0000CY] emits through [UID:0000MN] `PopupMenuControls`.

Rejected owner alternatives:

- `PopupMenuControls` file root as direct owner: valid source root, but the source construct is a class method and should be routed through [UID:0000CY].
- `MenuItem`: base class declares/provides the virtual contract, but this body is the SeparatorMenuItem override.
- `MenuPane`: caller/draw context only; it does not own the item method.
- `StringMenuItem`: sibling slot evidence only.
- `GrafPort`: draw-state dependency only.
- `SurfaceRenderCallbackTable`: callback dependency only.

## First-draft C++

Recommended first-draft C++ for the target:

```cpp
void SeparatorMenuItem::DrawItem(GrafPort *port)
{
    port->m_drawMode = 0;
    port->SetDrawColor(0x80);

    const int centerY = (m_bounds.top + m_bounds.bottom) / 2;

    RectBounds separatorRect;
    separatorRect.left = m_bounds.left + 3;
    separatorRect.top = centerY - 1;
    separatorRect.right = m_bounds.right - 3;
    separatorRect.bottom = centerY + 2;

    g_surfaceRenderCallbacks.fillOrInvalidate(port, &separatorRect);
}
```

Notes for implementation:

- If current GrafPort support uses `m_renderMode` as the canonical spelling for `+0x70`, use `port->m_renderMode = 0;` instead of introducing a competing field name.
- If current surface support prefers global function-pointer spelling, the final call may be written as `g_pfnFillOrInvalidateRect(port, &separatorRect);`.
- Do not add an explicit return value; the virtual caller ignores it and the source-facing sibling slot is `void`.
- Do not include security-cookie logic in C++.

## Recommended target doc changes

Recommended exact target changes:

- Change metadata to:

```text
COMPLETION:88
CONFIDENCE:92
CANONICAL_OWNER:0000CY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000CY
```

- Replace the stale source-quality/no-C++ blocker with the gate analysis from this report.
- Change the source-facing method name/signature in prose from `DrawSeparator`/raw `sub_517250` to `SeparatorMenuItem::DrawItem(GrafPort *port)`.
- Keep a note that the documentation filename still says `DrawSeparator` because that is the visible behavior label, unless the supervisor elects to rename the page.
- Add the first-draft C++ block above.
- Correct any statement that the source method returns the callback result. The binary leaves the callback result in EAX, but the vtable caller ignores it; the source method is `void`.
- Preserve exact half-open range `0x00517250-0x005172be`.
- Preserve no-split evidence: successor adjustor thunk starts at `0x005172be`; predecessor padding stays outside the range.
- Replace generated helper/global names with descriptive names:
  - `0x004b9660` -> `GrafPort::SetDrawColor` / active draw-color setter.
  - `dword_69B3FC` -> `g_surfaceRenderCallbacks.fillOrInvalidate` / `g_pfnFillOrInvalidateRect`.
  - `a2+0x70` -> `port->m_drawMode` or existing project `m_renderMode` spelling.
- Add the owner/emitter rejection summary if the target still mentions file-root, GrafPort, or callback-table alternatives as unresolved direct-owner candidates.

## Recommended support-doc changes

These are implementation-ready support changes if the supervisor includes support docs in the callback.

### `by-class/SeparatorMenuItem.md`

Recommended changes:

- Update method map/source summary for `0x00517250-0x005172be` to `void SeparatorMenuItem::DrawItem(GrafPort *port)`.
- Note that the method draws a centered 3-pixel-tall separator rectangle inside inherited `m_bounds`, inset horizontally by 3 pixels.
- Keep statement that `SeparatorMenuItem` has no unique data fields beyond inherited `MenuItem` layout.
- Note first-draft C++ is ready on [UID:0002JE].

### `by-type/by-vtable/MenuItemVtables.md`

Recommended changes:

- Update the `+0x14` slot description to a generic menu-item draw virtual:

```text
+0x14: DrawItem(GrafPort *port)
```

- Identify the SeparatorMenuItem entry at `0x0061ebe4` as [UID:0002JE] `SeparatorMenuItem::DrawItem`, not a separate `DrawSeparator` virtual contract.
- Preserve sibling [UID:0002JA] as `StringMenuItem::DrawItem`.

### `by-type/by-struct/MenuItemLayouts.md`

No mandatory update if it already names `m_bounds` at `MenuItem+0x04`. Optional addition:

- Add [UID:0002JE] as another evidence row for `m_bounds.left/top/right/bottom`: it reads all four fields to build `separatorRect`.

### `by-file/PopupMenuControls.md`

Recommended changes if the file summary has a method inventory:

- Add or update the SeparatorMenuItem draw method entry to `SeparatorMenuItem::DrawItem(GrafPort *port)`.
- Keep file root `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Keep confidence caveat about possible source file splitting, but do not let it block this target's first-draft C++.

### `by-class/MenuPane.md` and [UID:0001BK] `MenuPaneAndItems`

Optional support cleanup:

- The helper at `0x00516790` is more than layout initialization; it draws/renders the popup/menu pane and dispatches `item->DrawItem(this)` through vtable slot `+0x14` at `0x005168f0`.
- If support docs still call it only `InitializeLayout`, add a caveat or rename direction such as `DrawMenuItems`/`RenderMenuItems`/`UpdateLayoutAndDraw`.

### GrafPort and surface callback support

No mandatory support edit if current pages already contain the B-agent conclusions. If touched:

- Ensure `0x004b9660` is not documented solely as `FittingRoomListPane::SetTextColor`; for this target it is the `GrafPort` active draw-color setter.
- Ensure `dword_69B3FC`/slot 7 is described as a rect fill/invalidate/presentation callback taking a `GrafPort *` receiver and `const RectBounds *` argument.

## Open questions and attempted resolution

Resolved or high-confidence:

- Method source name/signature: `SeparatorMenuItem::DrawItem(GrafPort *port)`.
- Direct owner/emitter: [UID:0000CY] `SeparatorMenuItem`.
- Source root: [UID:0000MN] `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Range/split: exact half-open `0x00517250-0x005172be`; no split/merge.
- Bounds fields: inherited `MenuItem::m_bounds` at `+0x04`.
- Helper `0x004b9660`: active draw-color setter, not a FittingRoomListPane text helper.
- Direct construction/caller question is not applicable to this vtable method; local PE scan confirms vtable-only reachability.

Remaining below-final caveats:

- Exact original global/typedef name for `dword_69B3FC` is not recoverable from the current docs/local binary alone. Best source-facing direction is `g_surfaceRenderCallbacks.fillOrInvalidate` or `g_pfnFillOrInvalidateRect`.
- Exact original `GrafPort+0x70` field spelling remains open between `m_drawMode` and support-doc spelling `m_renderMode`. The role is resolved as the active draw/blit mode byte.
- Exact doc filename rename policy is open. Source content should use `DrawItem`; the current page path may stay `SeparatorMenuItemDrawSeparator` until the supervisor chooses a rename.

These caveats justify staying below final-audit confidence, but they do not block first-draft C++.

## Exact pending coverage replacement row

Do not edit `by-memory/-coverage-report.md` in the B-agent report-only pass. If the implementation is accepted, replace the current [UID:0002JE] row with:

```text
        - [UID:0002JE][0x00517250-0x005172be.SeparatorMenuItemDrawSeparator](by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md) 0x00517250-0x005172be | method | SeparatorMenuItemDrawItem : reconstructable : 88% : very strong : B004 source-quality pass resolves the separator draw slot as `void SeparatorMenuItem::DrawItem(GrafPort *port)` rather than generated `DrawSeparator(FittingRoomListPane*)`; local PE/Capstone and existing IDA evidence confirm exact half-open body, no split before successor adjustor thunk at 0x005172be, vtable-only reachability through `SeparatorMenuItem` slot 0x0061ebe4, shared MenuPane draw caller at 0x005168ef/0x005168f0 pushing the MenuPane/GrafPort draw context and ignoring the return value, draw/blit mode clear at `port+0x70`, `GrafPort::SetDrawColor`/active draw-color helper 0x004b9660 storing color 0x80 at `port+0x74`, centered `RectBounds` from `m_bounds` with horizontal inset 3 and vertical span `centerY-1..centerY+2`, SurfaceRenderCallbackTable slot 7 `dword_69B3FC` as descriptive `fillOrInvalidate`, compiler security-cookie code excluded from source, direct owner/emitter [UID:0000CY] with source root [UID:0000MN], and first-draft C++ readiness with exact callback typedef/name still below final-audit certainty.
```

## Validation commands needed

No validator was run in this report-only pass because no by-* docs were edited.

If accepted for implementation, run scoped validation from `source-3/project-documentation` for every touched doc. Minimum expected commands:

> Executable block R001 was removed from this report and preserved verbatim in [0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md](0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Run these only if the corresponding support docs are edited:

> Executable block R002 was removed from this report and preserved verbatim in [0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md](0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Coverage validation is supervisor/implementation-only after applying the row:

> Executable block R003 was removed from this report and preserved verbatim in [0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md](0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If formal C++ output or projected stats change, also run the relevant autogen/stat validator modes used by the project workflow.

## IDA rename/type/comment recommendations

Recommended IDA names and types:

| Target | Recommendation | Confidence |
|---|---|---:|
| `0x00517250` | Rename to `SeparatorMenuItem::DrawItem` or IDA-safe `SeparatorMenuItem_DrawItem` | High |
| `0x00517250` type | `void __thiscall SeparatorMenuItem::DrawItem(SeparatorMenuItem *this, GrafPort *port)` in IDA C-style, or method form `void __thiscall SeparatorMenuItem::DrawItem(GrafPort *port)` | High |
| `0x004b9660` | Rename/type as `GrafPort::SetDrawColor(unsigned int color)` or `GrafPort_SetDrawColor` | High |
| `0x0069b3fc` | Rename to `g_pfnFillOrInvalidateRect` or table member `g_surfaceRenderCallbacks.fillOrInvalidate` | Medium-high |
| `0x0069b3fc` callback type | `void (__thiscall *)(GrafPort *port, const RectBounds *rect)` | Medium-high |
| `MenuItem+0x04` | Field/comment `RectBounds m_bounds` | High |
| `GrafPort+0x70` | Field/comment `m_drawMode` / `m_renderMode` active draw mode | Medium-high |
| `GrafPort+0x74` | Field/comment `m_drawColor` active draw/fill color | High |
| stack local `[ebp-0x14]` | `RectBounds separatorRect` | High |

Recommended comments:

- At `0x0051726e`: `Clear active draw/blit mode before drawing separator.`
- At `0x00517272`: `Set separator draw color to palette/index 0x80.`
- At `0x00517277-0x005172a5`: `Build centered separator rectangle from inherited MenuItem bounds.`
- At `0x005172a6`: `Render/fill/invalidate separator rectangle through surface callback slot 7.`
- At `0x005168f0`: `Dispatch MenuItem::DrawItem(port) virtual slot; return value ignored.`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002JE-SeparatorMenuItemDrawSeparator-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0002JE"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002JE-SeparatorMenuItemDrawSeparator-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002JE-SeparatorMenuItemDrawSeparator-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002JE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
