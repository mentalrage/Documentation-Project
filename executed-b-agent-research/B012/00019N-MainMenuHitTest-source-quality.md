** TARGET-REPORT-UID:00019N **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00019N MainMenuHitTest Source-Quality Research

## Final Recommendation

- Target: [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](../../../../by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md)
- Final disposition: source-bearing file-local `MainMenuPane` hit-test helper. This page should not stay blank under stale below-95 wording.
- Recommended metadata: keep `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L0`; raise score from `84/90` to `87/91`.
- Recommended source name/signature: `static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)`.
- Recommended source route: private/static helper in `login/MainMenuPane.cpp`, next to `ComputeMenuItemRect`.

First-draft source C++ for the target:

```cpp
static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)
{
    if (pane->m_menuItemCount <= 0)
        return -1;

    for (signed char itemIndex = 0; itemIndex < pane->m_menuItemCount; ++itemIndex)
    {
        RectBounds itemRect;
        ComputeMenuItemRect(itemIndex, &itemRect);
        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}
```

`HitTestMenuItem` is preferred over `FindMenuItemAtPoint`: it matches the existing global/page artifact, the repository's other `HitTest...` helpers, and the function's role of returning a small menu index or `-1`. `FindMenuItemAtPoint` remains a descriptive fallback if a later symbol pass recovers that spelling, but it is not strong enough to block first-draft C++.

## Evidence Checked

- Required project rules: `by-structure.md`, `inference_research.md`, `.codex/AGENTS.md`, `Supervisor.md`, and B012 `goal.md`.
- Target/support docs:
  - `by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md`
  - `by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md`
  - `by-global/HitTestMenuItem_4F8C10.md`
  - `by-global/ComputeMenuItemRect_4F8B90.md`
  - `by-file/MainMenuPane.md`
  - `by-class/MainMenuPane.md`
  - `by-memory/0x004f6700-0x004f7d10.MainMenuPaneCore.md`
  - `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`
  - `by-global/g_useEpfAssets.md`
  - `by-memory/0x0066da97-0x0066da98.g_useEpfAssets.md`
  - `by-memory/0x004b7c30-0x004b7f87.RectGeometryHelpers.md`
  - `by-type/by-struct/RectBoundsLayout.md`
  - `by-file/RectBounds.md`
- Comparable hit-test/helper pages used as naming leads: `GetChatButtonAtPoint`, `ChattingVarietySelectPaneHitTest`, and `MenuVarietySelectPaneHitTest`.
- Local exported function evidence:
  - `resources/exported_data/functions/0x004f8c10.json`
  - `resources/exported_data/functions/0x004f8b90.json`
  - `resources/exported_data/functions/0x004f6af0.json`
  - `resources/exported_data/functions/0x004f6bf0.json`
  - `resources/exported_data/functions/0x004f6700.json`
  - `resources/exported_data/functions/0x004f76d0.json`
  - `resources/exported_data/functions/0x004f7a10.json`
  - `resources/exported_data/functions/0x004b7c50.json`
  - `resources/exported_data/functions/0x004b7e80.json`
- Active generated output `auto-generated/NexusTK/login/MainMenuPane.cpp`.
- Current generated-memory coverage row in `auto-generated/-ag-memory-coverage.md`, current manual coverage row in `by-memory/-coverage-report.md`, and current project-level stats row.
- `tools/int_convert.py` verified key values: `0xf9 = 249`, `0xfa = 250`, `0xea = 234`, `0x5a = 90`, `0x59 = 89`, `0x106 = 262`, `0x29 = 41`, `0x1e = 30`, `0x30d = 781`, `0x3cc = 972`, `0x1ed = 493`, `0x214 = 532`, `0x1d3 = 467`, `0x280 = 640`, `0x149 = 329`, and `0xa0 = 160`.
- Current IDA MCP check was attempted through `http://127.0.0.1:13337/mcp`; result: `MCP_ERROR: Unable to connect to the remote server`. This report therefore relies on existing live-MCP page notes plus local exported IDA/Ghidra data.

## Direct Binary Facts

`00019N` is one exact modeled helper:

- IDA name: `sub_4F8C10`.
- Ghidra name: `FUN_004f8c10`.
- Range/size: `0x004f8c10-0x004f8cfa`, size `0xea` / 234 bytes.
- IDA ABI: `char __thiscall sub_4F8C10(char *this, int a2, int a3)`.
- Ghidra ABI: `char __thiscall FUN_004f8c10(void *this, int param_1, int param_2)`.
- Xrefs to target: exactly two call sites, `0x004f6b37` and `0x004f6b6f`, both inside `MainMenuPane::OnMouseEvent` at `0x004f6af0`.
- Callees: `sub_4B7C50` / `InitRectBounds`, `sub_4B7E80` / point-in-rect, and security-cookie checking.
- Reads `this[249]` as the signed menu-item count. If the count is non-positive, returns `-1`.
- Loops with a signed byte item index and returns the first matching index. If no rectangle contains the point, returns `-1`.
- Reads `byte_66DA97` / `g_useEpfAssets` to choose EPF/current layout vs legacy layout.

The target decompile materializes the same rectangle formula as `ComputeMenuItemRect`:

| Branch | Rectangle |
| --- | --- |
| `g_useEpfAssets == 1` | left `781`, top `493 + 41 * index`, right `972`, bottom `532 + 41 * index` |
| legacy | left `467`, top `299 + 30 * index`, right `640`, bottom `329 + 30 * index` |

The otherwise odd `index == -1` rectangle branch in the target body is good evidence that the original source shared or called the menu-rectangle helper. A loop starting at `0` does not need that branch by itself; it appears because the compiler expanded `ComputeMenuItemRect`, whose public contract handles index `-1` by producing a zero rectangle. That makes a source-style `HitTestMenuItem` calling `ComputeMenuItemRect` more plausible than hand-duplicating all constants in the hit-test body.

## Heuristic / Inference Reanalysis And Validation

The current target text has a stale blocker: final C++ is blank because helper spelling and nearby source names are below the old `95/95` final-source gate. Under the active gate, this is no longer sufficient:

- The target is `RECONSTRUCTABLE:TRUE`.
- It has nonblank `EMITTER_UIDS:0000L0`.
- Its current average `(84 + 90) / 2 = 87` is already above 85.
- The parent file [UID:0000L0] is already routed to `NexusTK/login/MainMenuPane.cpp`; the class/file support also clears the current strict 85/85 routing expectation.

This is not no-code compiler glue. It is a source-authored UI helper with hardcoded menu geometry, caller-restricted `MainMenuPane::OnMouseEvent` use, and ordinary project helper callees. The correct resolution is first-draft C++, not a comment-only no-code marker.

Inference result:

- Source-bearing status: yes.
- Direct owner/emitter: keep [UID:0000L0][MainMenuPane](../../../../by-file/MainMenuPane.md).
- Helper source form: file-local `static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)`.
- Score recommendation: `87/91`, capped below final because original symbol names, final event-struct field names, and full `MainMenuPane` header layout are still inferred.

## Helper Name, Signature, And Placement

Recommended name: `HitTestMenuItem`.

Reasons:

- Existing support/global artifact already uses `HitTestMenuItem_4F8C10`.
- The body performs UI hit testing and returns a small index, matching repository naming such as `ChattingVarietySelectPaneHitTest`, `MenuVarietySelectPaneHitTest`, `WorldMapPaneHitTestNode`, and similar pages.
- `FindMenuItemAtPoint` is a reasonable descriptive alternative but less aligned with current docs and could imply an object/pointer search rather than a signed byte index.

Recommended signature:

```cpp
static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX);
```

Use `signed char` rather than `unsigned char` or plain `int` in the first draft. IDA and Ghidra both infer a `char` return, the caller stores the result into a byte selection field, and `-1` is a real sentinel compared by `OnMouseEvent`, `OnKeyEvent`, and paint/activation logic. If final code style uses plain `char`, the docs should still state that the value is signed.

Placement should stay in `login/MainMenuPane.cpp` as a private/static helper beside `ComputeMenuItemRect`. It should not become a standalone `HitTestMenuItem.cpp`, a generic rectangle helper, or a class virtual method. The raw helper takes a `MainMenuPane *` but has no vtable slot and no evidence of a member-function symbol.

## Field And State Resolution

The byte at base `this + 0xf9` should be named `m_menuItemCount`:

- The constructor `0x004f6700` writes `*(_WORD *)(this + 249) = 262`; `0x0106` in little-endian initializes byte `+0xf9` to `6` and byte `+0xfa` to `1`.
- `HitTestMenuItem` reads `this[249]` as the loop bound and empty-menu guard.
- `OnKeyEvent` receives the secondary facet pointer at base `+0xa0`; its `this[89]` is therefore base `+0xf9`, and it uses that byte as the modulo count for up/down navigation.
- `OnPaint` draws six EPF title buttons and uses the selected byte at `+0xfa` for the selection overlay.
- `ActivateMenuItem` switches over base `this[250]`, with cases `0..5`, matching the six menu items.

The byte at base `this + 0xfa` should be named `m_selectedMenuItemIndex` or `m_currentMenuItemIndex`; prefer `m_selectedMenuItemIndex` because it drives `ActivateMenuItem`, keyboard navigation, hover update, and selection rendering. `OnMouseEvent` stores the hit-test return in this byte and restores the old value if hit testing returns `-1`.

`byte_66DA97` should be named `g_useEpfAssets` in this target. The alternate generated aliases `g_useHighResLayout`, `g_uiLayoutMode`, and `g_attachmentModeFlag` are weaker. The storage/global docs identify `g_useEpfAssets` as the current project alias, with `== 1` selecting current EPF/high-layout assets and the legacy branch using EPD-style coordinates.

## Coordinate And Rectangle Semantics

Do not preserve the target page's old `mouseX, mouseY` wording as authoritative. The rectangle layout docs and the point helper decompile are decisive:

- `InitRectBounds` writes `[left, top, right, bottom]`.
- `PointInRect_4B7E80` compares `left <= second_arg < right` and `top <= first_arg < bottom`.
- Therefore the direct helper ABI order must be vertical coordinate first and horizontal coordinate second when calling the raw point helper.

The target decompile calls `sub_4B7E80(a2, a3, rect)`. With the documented rectangle layout, that only works when `a2` is `mouseY` and `a3` is `mouseX`. Otherwise a normal menu point such as x `800`, y `500` would be tested as x `500`, y `800` and miss every EPF button rectangle.

Recommended source names are therefore `mouseY, mouseX` for the helper parameters. If a later project-wide `MouseEvent` struct proves fields named `x` and `y`, the caller should pass them in this helper's proven ABI order. That naming uncertainty is not a C++ blocker.

## Caller Context

Both direct target callers are inside `MainMenuPane::OnMouseEvent`:

- `0x004f6b37`
- `0x004f6b6f`

The caller handles only mouse event kinds `0` and `3`; other kinds return handled. In both layout branches, it:

- normalizes the secondary event-handler `this` pointer by subtracting `0xa0` / 160 to get the `MainMenuPane` base;
- saves old base `+0xfa` selected index;
- calls `HitTestMenuItem(base, event + 8 coordinate, event + 0x0c coordinate)`;
- writes the signed byte result back to `+0xfa`;
- if the result is `-1`, restores the old selected index;
- if the selected index changes, invalidates the old and new rectangles through `ComputeMenuItemRect`;
- on event kind `3`, calls `ActivateMenuItem`.

No keyboard, paint, packet, resource, or non-main-menu callers reach `00019N`. Keyboard and paint use only the sibling `ComputeMenuItemRect`.

## ComputeMenuItemRect Relationship

`ComputeMenuItemRect` is not just a loose cross-reference. It is the source-facing rectangle primitive this hit-test helper should use:

- `ComputeMenuItemRect` has the exact same EPF/current and legacy coordinates.
- It has the `-1` zero-rectangle path that appears expanded inside the target body.
- It is called from `OnMouseEvent`, `OnKeyEvent`, and `OnPaint`, so it is the established source helper for menu item geometry.
- A mid-2000s source body that calls `ComputeMenuItemRect(index, &rect)` is cleaner and explains the binary expansion better than duplicating all constants in two helpers.

If final byte-for-byte-oriented reconstruction rejects the call form, the fallback C++ can expand the same branch constants inline. That fallback is not the preferred source-quality direction.

## Global-Page Reframe

[UID:0000T1][HitTestMenuItem_4F8C10](../../../../by-global/HitTestMenuItem_4F8C10.md) should be reframed as a binary-symbol/source-name index for the memory target, not as a second source-body emitter. Current generated output has both `0000T1` and `00019N` empty markers in `MainMenuPane.cpp`; emitting bodies from both pages would duplicate the helper.

Recommended support handling:

- Keep the file name `HitTestMenuItem_4F8C10.md` for traceability.
- Change prose title/status toward source name `HitTestMenuItem`, with `HitTestMenuItem_4F8C10` retained as the page/raw alias.
- State that [UID:00019N] carries the implementation body.
- If this page remains routed with `EMITTER_UIDS:0000L0`, use a comment-only alias marker rather than a duplicate C++ body:

```cpp
// File-local MainMenuPane helper; implementation is emitted by [UID:00019N] MainMenuHitTest.
```

The same duplicate-emitter caution applies to [UID:0000PI][ComputeMenuItemRect_4F8B90](../../../../by-global/ComputeMenuItemRect_4F8B90.md) if the sibling memory page later receives the real `ComputeMenuItemRect` body.

## Recommended Support Updates

Apply only if the supervisor sends an implementation callback.

For [UID:00019M][0x004f8b90-0x004f8c07.ComputeMenuItemRect](../../../../by-memory/0x004f8b90-0x004f8c07.ComputeMenuItemRect.md):

- Replace stale below-95 wording with the current combined-score/emitter gate.
- Prefer source signature `static void ComputeMenuItemRect(signed char itemIndex, RectBounds *rect)`.
- First-draft support C++:

```cpp
static void ComputeMenuItemRect(signed char itemIndex, RectBounds *rect)
{
    if (itemIndex == -1)
    {
        InitRectBounds(rect, 0, 0, 0, 0);
        return;
    }

    if (g_useEpfAssets == 1)
    {
        const int top = 493 + 41 * itemIndex;
        InitRectBounds(rect, 781, top, 972, top + 39);
    }
    else
    {
        const int top = 299 + 30 * itemIndex;
        InitRectBounds(rect, 467, top, 640, top + 30);
    }
}
```

For [UID:00007O][MainMenuPane](../../../../by-class/MainMenuPane.md):

- Add/strengthen field names:
  - base `+0xf9`: `m_menuItemCount`, signed byte/char, constructor-initialized to `6`;
  - base `+0xfa`: `m_selectedMenuItemIndex`, signed byte/char, constructor-initialized to `1`, set by mouse hit testing, wrapped by keyboard navigation, read by paint and activation.
- Note that `OnMouseEvent` passes the coordinate pair in the target helper's proven raw order and stores the signed result at `+0xfa`.

For [UID:0000L0][MainMenuPane](../../../../by-file/MainMenuPane.md):

- List `HitTestMenuItem` and `ComputeMenuItemRect` as private/static helpers in `login/MainMenuPane.cpp`.
- Replace address-suffixed global names in prose with source names plus raw aliases.
- State that `g_useEpfAssets == 1` selects the current EPF menu geometry and the legacy branch selects the older EPD geometry.

For `by-global/HitTestMenuItem_4F8C10.md`:

- Reframe as alias/index page; do not emit a duplicate helper body.
- Keep behavior/caller/callee evidence, but direct final C++ readers to [UID:00019N].

## Open Questions / Score Caps

- Exact original source spelling is not symbol-proven. `HitTestMenuItem` is the best-supported spelling and should be used for first draft; this is not a passive blocker.
- Exact `MainMenuPane` header field names are inferred from behavior. `m_menuItemCount` and `m_selectedMenuItemIndex` are strong descriptive names but not symbol recoveries.
- The project-wide mouse event struct has conflicting historical docs around x/y field names. This target's raw helper ABI is settled as vertical coordinate first, horizontal coordinate second for `PointInRect`; final event field names can be reconciled later.
- The full `MainMenuPane` source file still has unrelated raw/blank helpers. That caps final class/file confidence, but it does not block this helper's first-draft C++.
- Current IDA MCP was unavailable in this pass. Existing live-MCP notes and local exported data agree on target bounds/callers/callees.

## Recommended Exact Target Doc Changes

Header metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Target C++ block:

```cpp
static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)
{
    if (pane->m_menuItemCount <= 0)
        return -1;

    for (signed char itemIndex = 0; itemIndex < pane->m_menuItemCount; ++itemIndex)
    {
        RectBounds itemRect;
        ComputeMenuItemRect(itemIndex, &itemRect);
        if (PointInRect(mouseY, mouseX, &itemRect))
            return itemIndex;
    }

    return -1;
}
```

Replace the stale final-C++ note with:

```text
- Reconstruction C++ should be populated under the active combined-score/emitter gate: this page is `RECONSTRUCTABLE:TRUE`, emits through [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and the recommended `87/91` score gives a combined value above 85. The emitted source should be a private/static `HitTestMenuItem` helper; the old below-95 no-code wording is stale.
```

Add/update source-quality prose:

```text
Source-facing helper shape: `static signed char HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)`. The return is a signed byte menu index (`0..m_menuItemCount-1`) or `-1`. The helper loops over `m_menuItemCount` at base `+0xf9`, builds each candidate rectangle through the same source helper as [UID:00019M] `ComputeMenuItemRect`, and tests containment through the shared `PointInRect` helper in raw order `mouseY, mouseX, rect`. The selected/current menu byte at base `+0xfa` is written by `OnMouseEvent`, keyboard navigation, paint, and activation code, but this helper only reads the count and returns the hit result.
```

Recommended change-log entry:

```markdown
### 2026-06-19 B012 source-quality recheck

- Recommended score change from `84/90` to `87/91`, owner/emitter unchanged at [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md), and first-draft `HitTestMenuItem` C++ populated.
- Evidence: local exported IDA/Ghidra data confirms `sub_4F8C10` size `0xea` / 234 bytes, two callers in `MainMenuPane::OnMouseEvent`, callees `InitRectBounds` and `PointInRect`, signed byte `-1` fallback, `this+0xf9` count read, and `g_useEpfAssets` layout branch. Constructor/OnKey/OnPaint/Activate evidence resolves base `+0xf9` as `m_menuItemCount` and base `+0xfa` as `m_selectedMenuItemIndex`.
- Source decision: use file-local `HitTestMenuItem(MainMenuPane *pane, int mouseY, int mouseX)` in `login/MainMenuPane.cpp`; the global page is an alias/index and should not emit a duplicate body.
```

## Validator Needs

No validator was run because this is a report-only B-agent pass.

After an implementation callback edits the accepted docs, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00019N-MainMenuHitTest-source-quality-removed.md](00019N-MainMenuHitTest-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support pages are edited in the same callback, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [00019N-MainMenuHitTest-source-quality-removed.md](00019N-MainMenuHitTest-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After the supervisor applies the coverage row, validate `by-memory/-coverage-report.md` through the normal supervisor flow.

Expected generated-memory coverage row after target implementation/validation:

```text
| [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) | coded | `0000L0` | `0000L0` |  | yes | `auto-generated/NexusTK/login/MainMenuPane.cpp` | `by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md` |  |
```

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` from B012. Supervisor should replace the current `00019N` row with:

```text
    - [UID:00019N][0x004f8c10-0x004f8cfa.MainMenuHitTest](by-memory/0x004f8c10-0x004f8cfa.MainMenuHitTest.md) 0x004f8c10-0x004f8cfa | helper | MainMenuHitTest : reconstructable : 87% : strong : B012 source-quality review resolves this as source-bearing file-local `HitTestMenuItem` in `login/MainMenuPane.cpp`, not stale blank C++. First-draft source should return signed byte menu index or `-1`, loop over `m_menuItemCount` at `this+0xf9`, pass coordinates in the raw point-test order `mouseY, mouseX`, call or inline `ComputeMenuItemRect` for the `g_useEpfAssets` EPF/current and legacy rectangle families, and keep direct owner/emitter [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). Local exported evidence confirms `sub_4F8C10` size `0xea`, exactly two `MainMenuPane::OnMouseEvent` callers, `InitRectBounds`/`PointInRect` callees, `-1` no-hit fallback, constructor initialization of `+0xf9/+0xfa` as `6/1`, keyboard/paint/activation use of the selected-index byte, and no heap/packet/resource side effects.
```

## First-Draft Readiness

- `00019N` is ready for first-draft source C++ now.
- The target should not wait for a full `MainMenuPane` rewrite; its helper name, route, return type, field names, point order, and geometry relationship are sufficiently resolved for the active gate.
- Support `00019M` should preferably receive its own first-draft `ComputeMenuItemRect` body before or alongside this target so the target's call form has a concrete local declaration.
- The global alias pages should avoid duplicate body emission.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/00019N-MainMenuHitTest-source-quality.md`
- Modified: none outside B012 research.
- Preserved: existing B012 reports `00013C`, `00015L`, and `0002IT`.
- Coverage report edits: none; exact pending row is included above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00019N-MainMenuHitTest-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00019N"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00019N-MainMenuHitTest-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00019N-MainMenuHitTest-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00019N"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
