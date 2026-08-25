** TARGET-REPORT-UID:0002J8 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 B-Report: 0002J8 StringMenuItemMeasureText Source Quality

## Status

FINISHED.

## Assignment

- UID: `0002J8`
- Target: `source-3/project-documentation/by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0002J8-StringMenuItemMeasureText-source-quality.md`
- Scope: B-agent source-quality research report only. I did not edit the target doc, support docs, generated docs, or `by-memory/-coverage-report.md`.
- Prior B013 reports, including `00013E`, `00015H`, `00018U`, `00019T`, and `0001N3`, were preserved and not moved or overwritten.

## Executive Recommendation

`0002J8` should stay reconstructable, stay direct-owned/emitted through [UID:0000E8] `StringMenuItem`, and receive first-draft C++ under the current combined-score/emitter gate. The stale no-C++ caveat should be replaced: current metadata already has `RECONSTRUCTABLE:TRUE`, a valid emitter route through [UID:0000E8] to `NexusTK/ui/menu/PopupMenuControls.cpp`, and a combined score of `87.0`.

Recommended target metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000E8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000E8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended source-facing role:

```cpp
MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const;
```

Binary ABI mapping:

- IDA/Ghidra show an explicit result pointer plus `GrafPort *` because MSVC returns the two-dword `MenuItemMetrics` value through a hidden out/result pointer.
- Low-level prototype for IDA typing can be modeled as `MenuItemMetrics *__thiscall StringMenuItem_GetItemSize(StringMenuItem *this, MenuItemMetrics *outMetrics, GrafPort *port)`.
- Source should read as a normal value-returning virtual method, matching [UID:0002JC] `SeparatorMenuItem::GetDefaultDimensions()` and the `MenuItemMetrics { int height; int width; }` layout.

Recommended target C++:

```cpp
MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const
{
    const int textLength = static_cast<int>(wcslen(m_text));
    const short textWidth = port->GetTextWidth(m_text, textLength);

    MenuItemMetrics metrics = { 14, static_cast<int>(textWidth) + 24 };
    return metrics;
}
```

This draft intentionally uses source-level `wcslen`; the observed optimized body performs the equivalent inline UTF-16 scan before calling `GrafPort::GetTextWidth`.

## Evidence Checked

Required process and guidance docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and menu support docs:

- `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md`
- `by-class/StringMenuItem.md`
- `by-class/MenuItem.md`
- `by-class/MenuPane.md`
- `by-class/SeparatorMenuItem.md`
- `by-file/PopupMenuControls.md`
- `by-type/by-vtable/MenuItemVtables.md`
- `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`
- `by-type/by-struct/MenuItemLayouts.md`
- `by-memory/0x00516d00-0x00516dc2.MenuPaneRecomputeItemBoundsRaw.md`
- `by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md`
- `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md`
- `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`
- `by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md`
- `by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md`

GrafPort/text dependency docs:

- `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
- `by-class/GrafPort.md`
- `by-file/GrafPort.md`
- Prior executed report `tools/leaser/Agents/Agent-B001/research/executed/00016B-00016C-00016D-GrafPortTextHelpers-source-quality.md`

Generated/exported evidence:

- `resources/exported_data/functions/0x00517090.json`
- `resources/exported_data/functions/0x004ba9a0.json`
- `resources/exported_data/functions/0x00516d00.json`
- `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
- `source-3/simroot_v2/class_StringMenuItem.cpp` as a generated-output lead only, not authority
- `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and current `by-memory/-coverage-report.md` row for [UID:0002J8]

Tool status:

- Validator baseline passed:

> Executable block R001 was removed from this report and preserved verbatim in [0002J8-StringMenuItemMeasureText-source-quality-removed.md](0002J8-StringMenuItemMeasureText-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Output summary: scanned one markdown file; `ok 0002J8 ... UID header exists`; dry-run only.

- IDA MCP at `http://127.0.0.1:13337/mcp` was unavailable in this session: `Unable to connect to the remote server`. This report relies on existing IDA-backed docs, exported function JSON, generated coverage reports, and already-executed source-quality reports rather than adding fresh live-IDB claims.

Numeric conversions verified with `tools/int_convert.py`:

- `0x40` = 64 bytes (Verified with `int_convert.py`)
- `0x18` = 24 bytes (Verified with `int_convert.py`)
- `0x0e` = 14 (Verified with `int_convert.py`)
- `0x0c` = 12 bytes / vtable slot offset (Verified with `int_convert.py`)
- `0x14` = 20 (Verified with `int_convert.py`)
- `0x80` = 128 wide characters (Verified with `int_convert.py`)
- `0x118` = 280 bytes (Verified with `int_convert.py`)

## Behavior Resolution

Observed `0x00517090-0x005170d0` behavior:

- Receives `StringMenuItem *this` in `ecx`.
- Scans the inline UTF-16 label beginning at byte offset `this + 0x18` until the NUL terminator.
- Computes the code-unit count from the byte delta.
- Loads the second stack argument as the active text-measure receiver and calls `0x004ba9a0`.
- Writes result dword `[0] = 14`.
- Writes result dword `[1] = measuredTextWidth + 24`.
- Returns the result pointer in `eax` and uses `retn 8`.

The source-quality interpretation is:

- `StringMenuItem + 0x18` is `wchar_t m_text[0x80]`. Constructor, `GetText`, direct copy helper, metric helper, and draw helper all use the same inline buffer. Heap-pointer, caller-owned pointer, and string-object-member alternatives are rejected.
- The text-measure receiver is `GrafPort *port`, not `FittingRoomDownloadControlPane *`. The exported raw names are generated owner pollution; accepted GrafPort docs and B001 report prove `0x004ba9a0` is `short GrafPort::GetTextWidth(const wchar_t *text, int charCount)`.
- The result type is `MenuItemMetrics { int height; int width; }`, not Win32 `SIZE { cx, cy }`. The order is proven by this helper writing `[0]=14`, `[1]=width+24`, and by [UID:0002JC] writing separator metrics `[0]=6`, `[1]=20`.
- `24` is the full horizontal padding. [UID:0002JA] `StringMenuItem::DrawItem` positions text at `m_bounds.left + 12`, so the metric width accounts for left and right insets of 12 each.
- `14` is the fixed text-row height for string menu entries.

## Source-Quality Reanalysis

### Function Name And Signature

Best source name: `StringMenuItem::GetItemSize`.

Evidence:

- [UID:0000E8] `StringMenuItem` method map already names the vtable slot role `GetItemSize(...)`.
- [UID:0001Y4] maps `StringMenuItem` vtable slot `+0x0c` at `0x0061ebc0` to `0x00517090`.
- [UID:000379] `MenuPaneRecomputeItemBoundsRaw` calls each item's vtable slot `+0x0c`, reads returned `[1]` as the max width, then reads returned `[0]` as the row height while assigning bounds. This is item sizing, not drawing and not text copying.
- The target body does not mutate object state and returns dimensions, so `const` is appropriate at source level.

Rejected alternatives:

- `StringMenuItem::MeasureText`: descriptive but too narrow; the function returns full menu item metrics, not only raw text width.
- `void GetItemSize(MenuItemMetrics *out, GrafPort *port)`: matches the ABI display but hides the likely source C++ value-return form. The neighboring separator metric helper already uses a value-returning `MenuItemMetrics` draft.
- `SIZE GetItemSize(...)`: rejected because result dword order is height then width; Win32 `SIZE` is width then height.
- Generated `virt_meth_0x517090`, `sub_517090`, and feature-owner signatures are search-only names and should not remain as source-facing names.

### Helper Names And Dependencies

`0x004ba9a0` should be cited as:

```cpp
short GrafPort::GetTextWidth(const wchar_t *text, int charCount);
```

Evidence:

- The accepted [UID:00016C] page has first-draft C++ for the counted overload.
- B001's executed source-quality report found 117 direct `E8 rel32` refs to `0x004ba9a0`, rejected feature-pane ownership, and resolved the receiver as `GrafPort`.
- The function iterates through `StringIter`, uses `g_pFontImageLib->MeasureGlyphWidth`, reads GrafPort font/style state, and returns a summed 16-bit width.

Rejected names:

- `FittingRoomDownloadControlPane::meth_0x4ba9a0`: raw generated/Ghidra owner pollution.
- `sub_4BA9A0` or `MeasureTextWidth` as final source names: useful historic aliases, but superseded by accepted `GrafPort::GetTextWidth`.

### Range, Split, And Reachability

No split or merge is recommended.

Evidence:

- Current target range is exactly `0x00517090-0x005170d0`, size `0x40` / 64 bytes (Verified with `int_convert.py`).
- Current docs record the preceding `0x00517089-0x00517090` `0xcc` padding and the next function [UID:0002J9] beginning exactly at `0x005170d0`.
- The raw export and target doc agree on one callee, `0x004ba9a0`.
- Direct callers are absent because this is a vtable-only virtual method. `xrefs_to(0x00517090)` has the data xref from `0x0061ebc0`, the `StringMenuItem` slot `+0x0c`.
- The actual layout caller is indirect: [UID:000379] calls item vtable slot `+0x0c` during two-pass menu layout.

### Owner, Emitter, And Source File

Keep direct owner/emitter [UID:0000E8] `StringMenuItem`.

Evidence:

- The receiver fields and vtable slot are specific to `StringMenuItem`.
- The class page is `88/90` and direct file root [UID:0000MN] `PopupMenuControls` is `86/85`, so the current class-to-file source chain clears the gate.
- `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` already emits sibling `StringMenuItem::GetText` and `StringMenuItem::DrawItem` bodies from [UID:0002J9] and [UID:0002JA].

Do not route this target directly to [UID:0000MN] `PopupMenuControls` unless the implementation policy deliberately flattens all menu-item methods. The current class route is narrower and already accepted for sibling `StringMenuItem` methods.

### Open Questions Rechecked

- Exact historical virtual spelling remains not symbol-proven. `GetItemSize` is still the best high-probability source-facing name because class maps and `MenuPane` layout behavior both support it.
- Exact type spelling `MenuItemMetrics` is descriptive. It is still the best current type name because it captures the height-first/width-second ABI and avoids the wrong `SIZE` order.
- The separator interface remains a broader final-audit caveat: `SeparatorMenuItem` has fixed dimensions at slot `+0x18` while its `+0x0c/+0x10` slots are purecall in the current vtable docs. That tension should stay recorded in support docs, but it does not block `StringMenuItem` slot `+0x0c` C++ because `MenuPane` layout directly uses that slot for ordinary item metrics.
- Current-session live IDA MCP was unavailable. The existing docs contain prior live IDA evidence for function extents, vtable slots, and layout consumers; exported function JSON independently matches the target body.

## Recommended Target Doc Changes

Apply these changes to `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md` only after supervisor accepts this report:

1. Update metadata to `87/90`, keeping owner/emitter [UID:0000E8], `RECONSTRUCTABLE:TRUE`, and nonblank `EMITTER_UIDS:0000E8`.
2. Populate `RECONSTRUCTION_CPP CODE` with:

```cpp
MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const
{
    const int textLength = static_cast<int>(wcslen(m_text));
    const short textWidth = port->GetTextWidth(m_text, textLength);

    MenuItemMetrics metrics = { 14, static_cast<int>(textWidth) + 24 };
    return metrics;
}
```

3. Replace the stale formal-C++ caveat with the current 85/85 gate analysis: the target is reconstructable, has a valid emitter route, and average score is greater than 85; source-quality names and signature are now resolved enough for first draft.
4. Add a source signature/ABI note:

```text
Source-facing signature: `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const`.
IDA/Ghidra expose the hidden return pointer as the first explicit stack argument; source should return `MenuItemMetrics` by value.
```

5. Add or update `Touched State` / `Behavior` with:

- `m_text[0x80]` at byte offset `+0x18`.
- Calls `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` at `0x004ba9a0`.
- Writes height-first `MenuItemMetrics`: `height = 14`, `width = textWidth + 24`.
- `24` is full horizontal padding; [UID:0002JA] shows the draw inset is 12 pixels from the left, implying matching right padding.

6. Update score rationale:

```text
Raised to `87/90` after source-quality reanalysis resolved the virtual role as `GetItemSize`, the hidden-return ABI as value-returned `MenuItemMetrics`, the text helper as `GrafPort::GetTextWidth`, the label field as inline `m_text[0x80]`, and the constants as fixed height 14 plus 24 pixels of horizontal padding. Remaining gaps are exact historical spelling for the virtual/type names and the broader separator-interface audit.
```

7. File rename is optional, not required. If the supervisor wants filename/source-role consistency, the better name is `0x00517090-0x005170d0.StringMenuItemGetItemSize.md`; if not renaming, keep the current path but make the title/status clearly state "GetItemSize / measure text".

## Recommended Support Doc Changes

Apply only after supervisor accepts this report:

- `by-class/StringMenuItem.md`
  - Change the method-map row for [UID:0002J8] from `GetItemSize(...)` to `MenuItemMetrics GetItemSize(GrafPort *port) const`.
  - Add a B013 source-quality note that the method now has first-draft C++, returns height-first `MenuItemMetrics`, uses `m_text[0x80]`, calls `GrafPort::GetTextWidth`, and uses `24` as total horizontal padding.

- `by-type/by-struct/MenuItemLayouts.md`
  - Keep `MenuItemMetrics { int height; int width; }`.
  - Extend the evidence row to name `StringMenuItem::GetItemSize` explicitly and add that string item width is `GrafPort::GetTextWidth(m_text, length) + 24`, where the draw helper's `left + 12` supports the padding interpretation.

- `by-type/by-vtable/MenuItemVtables.md`
  - In the slot-map or B003 note, change `String item size/metrics slot` to `StringMenuItem::GetItemSize` candidate with source signature `MenuItemMetrics (GrafPort *) const`.
  - Keep the caveat that final historical spelling is inferred and the separator extra-slot interface still needs later audit.

- `by-memory/0x0061eb94-0x0061ebf0.MenuItemVtableData.md`
  - Under B003/B013 notes, update the `0x0061ebc0` row/note from generic text measurement to `StringMenuItem::GetItemSize` / `MenuItemMetrics` value-return source role.

- `by-file/PopupMenuControls.md`
  - Add one sentence to the ownership notes that [UID:0002J8] now has first-draft source-quality C++ through `StringMenuItem`, and that `PopupMenuControls.cpp` remains the source-file root.

No support-doc score change is required. The existing `StringMenuItem` class `88/90`, `MenuItemLayouts` `85/89`, `MenuItemVtables` `86/91`, and `PopupMenuControls` `86/85` scores are already compatible with this target update.

## IDA Rename / Type / Comment Recommendations

High-confidence:

- Rename/comment `sub_517090` as `StringMenuItem::GetItemSize` or `StringMenuItem_GetItemSize`.
- Type low-level ABI as `MenuItemMetrics *__thiscall StringMenuItem_GetItemSize(StringMenuItem *this, MenuItemMetrics *outMetrics, GrafPort *port)`.
- Record source-level declaration as `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const`.
- Name `StringMenuItem + 0x18` as `m_text`, type `wchar_t[128]`.
- Name/comment `0x0061ebc0` as `StringMenuItem` vtable slot `+0x0c`, `GetItemSize`.

Medium-high confidence:

- Ensure `0x004ba9a0` is named/commented as `GrafPort::GetTextWidth(const wchar_t *text, int charCount)`, returning `short`.
- Add type `struct MenuItemMetrics { int height; int width; };`.
- Comment the target constants as fixed row height `14` and total horizontal padding `24`.

Do not use:

- `FittingRoomDownloadControlPane::meth_0x4ba9a0`
- `virt_meth_0x517090`
- `sub_517090`
- `SIZE`
- `std::uint32_t *size` as source-facing API

## Coverage Report Replacement Row

Do not edit `by-memory/-coverage-report.md` during this report pass. If accepted, replace the current [UID:0002J8] row with:

```text
        - [UID:0002J8][0x00517090-0x005170d0.StringMenuItemMeasureText](by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md) 0x00517090-0x005170d0 | method | StringMenuItemMeasureText : reconstructable : 87% : strong : Source-quality pass resolves this vtable metric helper as `MenuItemMetrics StringMenuItem::GetItemSize(GrafPort *port) const` with MSVC hidden-return/out-buffer ABI, exact 0x40 range, StringMenuItem vtable slot 0x0061ebc0 (+0x0c), inline `m_text[0x80]` label at byte +0x18, manual UTF-16 length scan, shared `GrafPort::GetTextWidth(const wchar_t *, int)` dependency at 0x004ba9a0 returning 16-bit width, height-first metrics `[0]=14`, `[1]=textWidth+24`, 24-pixel horizontal padding matching the 12-pixel draw inset, no direct code callers because reached through virtual dispatch, direct StringMenuItem class parent/emitter with PopupMenuControls source root, and first-draft C++ ready; remaining caveats are exact historical method/type spelling and separator-interface tension.
```

If the target file is renamed to `StringMenuItemGetItemSize`, update the link text and path in the row accordingly.

## Validation Commands Needed After Implementation

Run after accepted by-* edits:

> Executable block R002 was removed from this report and preserved verbatim in [0002J8-StringMenuItemMeasureText-source-quality-removed.md](0002J8-StringMenuItemMeasureText-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the target file is renamed, run the validator on the renamed path and let it repair UID references.

## Implementation Readiness

Ready for implementation after supervisor review.

The target is code-emitting and clears the current gate. The remaining issues are final-audit spelling confidence, not blockers for a first-draft C++ body. The only broad unresolved item is the separator extra-slot/interface tension, which should remain documented but does not prevent source-quality completion for `StringMenuItem::GetItemSize`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0002J8-StringMenuItemMeasureText-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0002J8"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002J8-StringMenuItemMeasureText-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0002J8-StringMenuItemMeasureText-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002J8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
