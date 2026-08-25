** TARGET-REPORT-UID:0002NQ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 source-quality report: 0002NQ ClanStringListPaneDrawItem

Agent: Agent-B001  
Date: 2026-06-19  
Target: `source-3/project-documentation/by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`  
UID: `0002NQ`  
Assignment: source-quality / heuristic research before implementation

## Scope and result

This is a B-agent research report only. I did not edit the target by-memory doc, support by-* docs, or `by-memory/-coverage-report.md`.

Recommendation: promote the source-facing method to `ClanStringListPane::DrawItem` with a first-draft typed row renderer signature:

```cpp
void ClanStringListPane::DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds);
```

The implementation is first-draft C++ ready under the active gate. Current target metadata already has `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00002L`, and `(84 + 90) / 2 = 87`, which clears the current >85 threshold. The old target wording that blocks C++ until a 95/95 final-source gate is stale.

Recommended target score: `COMPLETION:87`, `CONFIDENCE:91`.

Keep metadata:

```yaml
CANONICAL_OWNER:00002L
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002L
```

Do not move canonical ownership to `ClanJoinListPane`, `ClanEnlistListPane`, `ListPane`, or `GrafPort`. The shared vtable use is inherited/reused behavior, but the implementation owner remains `ClanStringListPane`, emitted through `Clan.cpp`.

## Evidence checked

Live IDA MCP: unavailable in this session. A JSON-RPC `tools/list` request to `http://127.0.0.1:13337/mcp` failed with connection refused/unable to connect. All conclusions below are based on cached/exported function JSON and local documentation, not a fresh live IDA query.

Checked local evidence:

- Target doc: `by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`
- Cached/exported function record: `core/data/cache/prewave/functions/0x004887d0.json`
- Exported function record: `core/data/readonly/prewave/exported-functions/0x004887d0.json`
- `ListPane::OnPaint` dispatch evidence: `core/data/readonly/prewave/exported-functions/0x004f43e0.json`
- Rename registry lead: `core/data/readonly/wave2/metadata/rename_registry.json`
- Generated Wave2 C++ lead: `core/data/readonly/wave2/metadata/report-0.json`
- Related class docs: `ClanStringListPane.md`, `ClanJoinListPane.md`, `ClanEnlistListPane.md`, `ListPane.md`, `GrafPort.md`
- Related memory docs: `ClanPaneListVtableData.md`, `ClanListPaneVirtuals.md`, `ListPane.md`, `GrafPortDrawStateAccessors.md`, `TextFitAndSuffixHelpers.md`, `GrafPortTextRunHelpers.md`
- Related global docs: `SurfaceRenderCallbackTable.md`, `g_pfnLockSurface.md`
- Related file docs: `Clan.md`, `ListPane.md`, `GrafPort.md`
- Generated source route: `auto-generated/NexusTK/social/Clan.cpp`
- Coverage rows: `auto-generated/-ag-memory-coverage.md` and `by-memory/-coverage-report.md`
- Prior B-agent reports search: no previous `0002NQ` / `ClanStringListPaneDrawItem` report found

## Binary facts

Cached/exported target function facts:

- Address range: `0x004887d0-0x004888c1`
- Size: `0xf1` bytes
- ABI: `__thiscall`, returns `void`, ends with `ret 0xc`
- Cached signature lead: `void __thiscall(int this, int row, wchar_t *Source, _DWORD *rect)`
- Ghidra signature lead: `undefined __thiscall virt_meth_0x4887d0(ClanStringListPane *this, undefined4 param_1, wchar_t *param_2, int param_3)`
- Direct code callers: none
- Vtable/data refs: `0x0061572c`, `0x006157f0`, `0x006158b4`
- Callees: `0x00457a60`, `0x004f3f00`, `0x004b9660`, `0x004b9680`, `0x004b9690`, `wcscpy_s`, `0x004ba820`, `0x004b9600`, `0x004bab70`, `__security_check_cookie`
- String literal: `L"..."` at `0x0061066c`

The exported decompilation is:

```cpp
void __thiscall sub_4887D0(int this, int a2, wchar_t *Source, _DWORD *a4)
{
  __int64 v5;
  int v6;
  _DWORD v7[10];
  wchar_t Destination[256];

  sub_457A60(v7);
  if ( sub_4F3F00((_DWORD **)this, a2) )
  {
    sub_4B9660((_DWORD *)this, 128);
    dword_69B3FC(this, a4);
  }
  sub_4B9680((_DWORD *)this, 143);
  *(_BYTE *)(this + 136) = 1;
  sub_4B9690((_DWORD *)this, 0);
  wcscpy_s(Destination, 0x100u, Source);
  v5 = a4[1] + a4[3];
  v6 = (((int)v5 - HIDWORD(v5)) >> 1) + 6;
  sub_4BA820((__int16 *)this, Destination, 0x100u, (wchar_t *)L"...", a4[2] - 50);
  sub_4B9600((_DWORD *)this, 50, v6);
  sub_4BAB70(this, (int)Destination, wcslen(Destination));
}
```

## Source-facing method name and signature

Recommended source name:

```cpp
ClanStringListPane::DrawItem
```

Rejected names:

- `ClanStringListPaneDrawItem`: useful doc slug, not a source method spelling.
- `virt_meth_0x4887d0`: generated placeholder; rename registry already maps it to `DrawItem`.
- `sub_4887D0`: raw address name only.

Recommended signature:

```cpp
void ClanStringListPane::DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds)
```

Reasoning:

- `ListPane::OnPaint` calls vtable slot `+0x80` with `(this, rowIndex, itemPayload, rowRect)`.
- The target uses the second explicit argument only as the selected-row index.
- The target copies the third explicit argument with `wcscpy_s` into a 256-wide-character buffer, so this derived override's row payload is a UTF-16 string pointer.
- The fourth explicit argument is indexed as `rect[1]`, `rect[2]`, and `rect[3]`, matching `top`, `right`, and `bottom` of the row bounds. Existing docs use `RectBounds`.
- A typed derived signature is consistent with the already reconstructed `ChattingColorListPane::DrawItem(int row, const ChattingColorSwatchItem *item, const RectBounds *drawBounds)`.

Open signature caveat: the base `ListPane` virtual declaration may historically have used a generic payload type such as `const void *` or an untyped item pointer. If implementation needs to match a generic base declaration, keep the body typed by casting the row payload to `const wchar_t *` at entry. The binary still proves the source-facing row data consumed here is wide text.

## Owner and emitter routing

Recommended route:

- Canonical owner: `ClanStringListPane` (`00002L`)
- Emitter: `ClanStringListPane` through `Clan.cpp` (`00002L`)
- Generated path: `auto-generated/NexusTK/social/Clan.cpp`

Evidence:

- `ClanStringListPane` vtable slot ref: `0x0061572c`
- `ClanJoinListPane` reused slot ref: `0x006157f0`
- `ClanEnlistListPane` reused slot ref: `0x006158b4`
- `ClanPaneListVtableData.md` identifies this as the shared draw slot at vtable `+0x80`.
- `ClanListPaneVirtuals.md` places the exact target between padding ranges and confirms it as the shared row renderer.
- `Clan.md` places the three clan list pane classes in `social/Clan.cpp`.
- Generated `auto-generated/NexusTK/social/Clan.cpp` already contains the `0002NQ` empty emitter marker and is no longer an empty generated root.

Do not route this implementation to `ClanJoinListPane` or `ClanEnlistListPane`. Those classes inherit/reuse this renderer in their vtables; they do not own the implementation. Do not route it to `ListPane` or `GrafPort`; those are dependencies providing dispatch and drawing helpers.

## Row behavior

Resolved behavior:

1. Construct/init a 10-dword local graphics/context helper through `0x00457a60`.
2. Check row selection with `ListPane::IsItemSelected(row)` at `0x004f3f00`.
3. If selected:
   - Set active draw/fill color or palette index to `128` through `0x004b9660`.
   - Fill/invalidate/draw the row bounds using callback slot `0x0069b3fc` / `dword_69B3FC(this, rowBounds)`.
4. Set the text/foreground color or palette index to `143` through `0x004b9680`.
5. Set GrafPort text draw/background mode byte at `this + 0x88` to `1`.
6. Clear the secondary/background/outline text color to `0` through `0x004b9690`.
7. Copy `rowText` into a local `wchar_t text[256]` buffer with `wcscpy_s`.
8. Compute vertical draw position as `((rowBounds->top + rowBounds->bottom) / 2) + 6`.
9. Fit/truncate the buffer with `GrafPort::FitTextAndAppendSuffix(text, 256, L"...", rowBounds->right - 50)`.
10. Move the text cursor to `(50, computedY)` through `GrafPort::MoveTo`.
11. Draw the fitted text with `GrafPort::DrawWideText(text, wcslen(text))`.

Important source-quality correction: target text currently describes `this + 0x88` as a byte flag. Related GrafPort docs support a more specific label: this is GrafPort's text draw/background mode byte, not a generic dirty flag.

The fixed x coordinate `50` and fit width `rowBounds->right - 50` indicate a left-side reserved margin or icon/gutter area. The function does not use `rowBounds->left`.

## Shared helper names

Recommended helper spellings for target prose and first-draft C++:

| Address | Recommended source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x004f3f00` | `ListPane::IsItemSelected` | high | Confirmed by ListPane docs and use pattern. |
| `0x004b9660` | `GrafPort::SetDrawColor` / active fill color setter | medium-high | Sets active draw/fill palette used before the row background callback. Exact historic spelling may differ. |
| `0x004b9680` | `GrafPort::SetTextColor` / primary text color setter | medium-high | Sets text/foreground palette to `143`; related docs call this primary text color. |
| `0x004b9690` | `GrafPort::SetTextBackColor` / secondary text color setter | medium | Stores the secondary/background/outline text color at `+0x80`; exact historic spelling open. |
| `0x004b9600` | `GrafPort::MoveTo` | high | Confirmed by draw-state docs. |
| `0x004ba820` | `GrafPort::FitTextAndAppendSuffix` | high | Confirmed by reconstructed helper doc and C++ block. |
| `0x004bab70` | `GrafPort::DrawWideText` | high | Confirmed by text-run helper doc and C++ block. |
| `0x00457a60` | graphics/context local init, likely `EPFTileContext` init/constructor | medium | Target allocates 10 dwords and calls it once; source name not fully settled. Preserve as an initialized local context in C++. |
| `0x0069b3fc` | `g_pfnFillOrInvalidateRect` / Surface render callback slot 7 | medium | The old `g_pfnLockSurface` alias is rejected. Exact callback typedef and final source name remain open. |

## Vtable and caller evidence

There are no direct code callers. This is expected for a virtual row renderer.

The function is referenced from three clan list pane vtable slots:

- `0x0061572c`: `ClanStringListPane` draw slot
- `0x006157f0`: `ClanJoinListPane` draw slot
- `0x006158b4`: `ClanEnlistListPane` draw slot

`ListPane::OnPaint` supplies the source-level call shape. It iterates visible rows, obtains each row rectangle through vtable slot `+0x74`, fetches item payload from the list storage, intersects with the content rect, then calls vtable slot `+0x80` as the draw hook with row index, item payload, and row bounds. This is the strongest source-facing evidence for the method name/signature.

## First-draft C++ recommendation

Recommended target C++ body:

```cpp
void ClanStringListPane::DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds)
{
    EPFTileContext drawContext;
    wchar_t text[256];

    drawContext.Init();

    if (IsItemSelected(row)) {
        SetDrawColor(128);
        g_pfnFillOrInvalidateRect(this, rowBounds);
    }

    SetTextColor(143);
    m_textDrawMode = 1;
    SetTextBackColor(0);

    wcscpy_s(text, _countof(text), rowText);

    const int y = ((rowBounds->top + rowBounds->bottom) / 2) + 6;
    FitTextAndAppendSuffix(text, _countof(text), L"...", rowBounds->right - 50);
    MoveTo(50, y);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}
```

Implementation notes:

- If the local helper at `0x00457a60` is ultimately a constructor rather than an explicit `Init()`, change the first two lines to the local object form that emits the call. Do not drop the local init; the binary has a real call before selection handling.
- If the base virtual declaration uses generic item data, use `const void *rowData` in the override declaration and assign `const wchar_t *rowText = static_cast<const wchar_t *>(rowData);` at the top of the body.
- Keep `g_pfnFillOrInvalidateRect` as a descriptive callback name until the Surface render callback table has a final historic typedef/name. Do not use the rejected `g_pfnLockSurface` alias.
- `SetDrawColor`, `SetTextColor`, and `SetTextBackColor` are source-quality descriptive names. Exact historic helper spellings are still open, but raw names are no longer needed in the target C++.

## Remaining raw/generated names

Names that should be removed from target source-facing prose or relegated to evidence-only aliases:

- `sub_4887D0`
- `virt_meth_0x4887d0`
- `param_1`, `param_2`, `param_3`
- `Source`, `Destination`, `a4`
- `dword_69B3FC` as the only prose name
- `sub_4B9660`, `sub_4B9680`, `sub_4B9690`, `sub_4BA820`, `sub_4B9600`, `sub_4BAB70`

Acceptable evidence-only phrasing: "the binary call at `0x004b9680` maps to the source-facing `SetTextColor` helper candidate."

## Open questions

These do not block first-draft C++ but should cap the score below final-source quality:

- Exact historic source spelling for the `0x00457a60` stack graphics/context helper and whether it was a constructor, `Init()`, or local RAII object.
- Exact historic source spelling and typedef for Surface callback slot `0x0069b3fc`.
- Exact helper names for the draw-state accessors at `0x004b9660`, `0x004b9680`, and `0x004b9690`.
- Whether the base `ListPane` virtual declaration used typed row payloads per derived class or a generic payload type.
- Exact field name for GrafPort byte `+0x88`; current best label is text draw/background mode, not a generic byte flag.

## Recommended exact doc changes

For the target by-memory doc, after supervisor implementation callback:

1. Change the source-facing title/prose from "ClanStringListPaneDrawItem" as a method name to `ClanStringListPane::DrawItem`.
2. Raise metadata to:

```yaml
COMPLETION:87
CONFIDENCE:91
CANONICAL_OWNER:00002L
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00002L
```

3. Replace the stale no-code/final gate text with active-gate readiness language:

```text
The function is first-draft C++ ready under the active reconstruction gate: `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:00002L`, and `(COMPLETION + CONFIDENCE) / 2 > 85`. Remaining uncertainty is limited to historic helper spellings and the Surface callback typedef/name, not behavior or routing.
```

4. Add or replace the source signature with:

```cpp
void ClanStringListPane::DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds)
```

5. Add the first-draft C++ body from this report's "First-draft C++ recommendation" section.
6. Correct `this + 0x88` wording to "GrafPort text draw/background mode byte" rather than a generic byte flag.
7. Replace `g_pfnLockSurface` if it appears with a neutral callback label such as `g_pfnFillOrInvalidateRect` or "Surface render callback slot 7".
8. Add explicit `ListPane::OnPaint` evidence that vtable slot `+0x80` receives `(row, itemPayload, rowBounds)`.
9. Keep vtable evidence for all three slot refs: `0x0061572c`, `0x006157f0`, `0x006158b4`.

Optional support doc updates if supervisor wants surrounding cleanup:

- `by-class/ClanStringListPane.md`: update the draw method row to use `DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds)` and note the first-draft target C++ route.
- `by-class/ClanJoinListPane.md` and `by-class/ClanEnlistListPane.md`: clarify that their draw slot reuses `ClanStringListPane::DrawItem`, not a separate class-owned implementation.
- `by-memory/0x00488610-0x004888f1.ClanListPaneVirtuals.md`: update the child summary for `0002NQ` to say first-draft C++ ready under the active >85 gate.
- No score changes are required for the support docs unless those docs are edited materially.

## Validator needs

After implementation edits, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md](0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, run the same file-mode validator for each touched support doc. Then run the project autogen/coverage update path used by the supervisor workflow, for example:

> Executable block R002 was removed from this report and preserved verbatim in [0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md](0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Do not hand-edit `by-memory/-coverage-report.md`; use the exact replacement row below for supervisor notes or generated coverage reconciliation.

## Exact pending coverage text

Current row in `by-memory/-coverage-report.md` should be replaced with:

```text
        - [UID:0002NQ][0x004887d0-0x004888c1.ClanStringListPaneDrawItem](by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md) 0x004887d0-0x004888c1 | method | ClanStringListPane::DrawItem : reconstructable : 87% : very strong : B001 2026-06-19 source-quality reanalysis confirms exact 0xf1-byte vtable-only row renderer, inherited `ListPane` draw-slot signature `DrawItem(int row, const wchar_t *rowText, const RectBounds *rowBounds)`, shared slot refs for ClanStringListPane/ClanJoinListPane/ClanEnlistListPane at `0x0061572c`, `0x006157f0`, and `0x006158b4`, selected-row background palette `128`, text/foreground palette `143`, text draw/background mode reset through GrafPort, 256-wide-character copy/truncate with `GrafPort::FitTextAndAppendSuffix(..., L"...", rowBounds->right - 50)`, cursor move to `x=50` and vertical center `((top + bottom) / 2) + 6`, final `GrafPort::DrawWideText`, stable `ClanStringListPane` owner/emitter route through `Clan.cpp`, and first-draft C++ readiness with remaining caveats limited to exact historic helper/typedef spellings.
```

## Changed files

Changed by this B-agent pass:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/research/0002NQ-ClanStringListPaneDrawItem-source-quality.md`

Intentionally not changed:

- `source-3/project-documentation/by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md`
- support by-* docs
- `source-3/project-documentation/by-memory/-coverage-report.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0002NQ-ClanStringListPaneDrawItem-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"0002NQ"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002NQ-ClanStringListPaneDrawItem-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0002NQ-ClanStringListPaneDrawItem-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002NQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
