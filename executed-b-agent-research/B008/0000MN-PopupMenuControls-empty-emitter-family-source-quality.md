** TARGET-REPORT-UID:0000MN **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0000MN PopupMenuControls Empty-Emitter Family Source-Quality Report

Report date: 2026-06-30

Agent: B008

Mode: implementation callback complete. This report began as report-only research; on 2026-06-30 B008 applied the accepted implementation details into the listed `by-*` docs, ran scoped validators, and updated this ledger/checklist. No generated files, generated reports, manual coverage reports, validator/tool state, IDA state, executed archives, supervisor ledgers, archives, or lock files were edited by hand.

## Executive Disposition

[UID:0000MN] `by-file/PopupMenuControls.md` is the correct current source root for the generated `NexusTK/ui/menu/PopupMenuControls.cpp` family. The current empty-emitter markers are not evidence that the file route is wrong. They are a mixed set of:

- class/type declarations that now have enough evidence to emit declaration or layout C++;
- tiny `MenuItem` accessors/setters/copy helpers that can emit exact first-draft C++;
- compiler-generated scalar deleting destructor wrappers that should not receive handwritten wrapper bodies but can receive explicit no-standalone-source comment markers;
- aggregate/vtable/support pages that should emit only routing/provenance markers and `[[CHILDREN]]`, not duplicate child method bodies.

Recommended implementation is an immediate callback batch covering all 17 empty markers plus a short `by-file/PopupMenuControls.md` change-log/status note. Keep the by-file metadata at `COMPLETION:86`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`. The file-level confidence should remain capped because a later original-source review may still split `MenuPane.cpp`, `MenuItem.cpp`, or `PopupMenuControlPane.cpp` from the current consolidated source root.

MCP status: available and used. Callback verification state: all accepted implementation claims below are now marked `applied`; no accepted claim is blocked or excluded.

## Current Target State And Queue Row

Primary target:

- UID: `0000MN`
- Path: `by-file/PopupMenuControls.md`
- Current metadata: `COMPLETION:86`, `CONFIDENCE:85`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`, `CANONICAL_OWNER:FILE`
- Current generated file: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
- Current generated header observed read-only:
  - `validator-command-id: 000000002418`
  - `validator-refreshed-at: 2026-06-30T05:25:47-04:00`
  - `validator-refresh-source: foreground-generated-refresh`
  - `Source by-file UID: 0000MN`

Queue source:

- `auto-generated/-ag-research-tracker.md`, line 70: `[UID:0000MN] PopupMenuControls` has `28` total emitters, `11` filled, `17` empty, `39.3%`, generated file `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, path `by-file/PopupMenuControls.md`.
- `auto-generated/-ag-research-tracker.md`, line 974: `[UID:0000MN] PopupMenuControls` is `86/85`, average `85.5`, direct report coverage blank at the time of assignment.

Generated filled emitters observed read-only:

| UID | Page | Current emitted role |
| --- | --- | --- |
| `0002J3` | `by-memory/0x00516f00-0x00516f67.MenuItemConstructor.md` | `MenuItem::MenuItem()` |
| `0002J5` | `by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md` | `MenuItem::IsSelected() const` |
| `0002JB` | `by-memory/0x005171b0-0x0051721d.SeparatorMenuItemConstructor.md` | `SeparatorMenuItem::SeparatorMenuItem()` |
| `0002JC` | `by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md` | `SeparatorMenuItem::GetDefaultDimensions() const` |
| `0002JD` | `by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md` | `SeparatorMenuItem::GetStyleFlags() const` |
| `0002JE` | `by-memory/0x00517250-0x005172be.SeparatorMenuItemDrawSeparator.md` | `SeparatorMenuItem::DrawItem(GrafPort *port)` |
| `0002J6` | `by-memory/0x00516ff0-0x00517070.StringMenuItemConstructor.md` | `StringMenuItem::StringMenuItem(const wchar_t *text)` |
| `0002J7` | `by-memory/0x00517070-0x00517089.StringMenuItemCopyText.md` | `StringMenuItem::CopyText(...) const` |
| `0002J8` | `by-memory/0x00517090-0x005170d0.StringMenuItemMeasureText.md` | `StringMenuItem::GetItemSize(GrafPort *port) const` |
| `0002J9` | `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md` | `StringMenuItem::GetText(...) const` |
| `0002JA` | `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md` | `StringMenuItem::DrawItem(GrafPort *port)` |

## Evidence Checked

Instruction and schema evidence checked:

- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `ntk-b-agent-workflow/references/supervisor-rule26-review-and-incorporation-standard.md`
- `ntk-b-agent-workflow/references/score-blocker-audit-standard.md`
- `ntk-b-agent-workflow/references/b-agent-report-template.md`
- `source-3/project-documentation/by-structure.md`
- `by-file/-guidance.md`
- `by-memory/-guidance.md`
- `by-class/-guidance.md`
- `by-type/-guidance.md`
- `by-type/by-struct/-guidance.md`
- `by-type/by-vtable/-guidance.md`
- `tools/leaser/Agents/Agent-B008/goal.md`

Current docs read:

- `by-file/PopupMenuControls.md`
- `by-class/MenuItem.md`
- `by-class/MenuPane.md`
- `by-class/PopupMenuControlPane.md`
- `by-class/SeparatorMenuItem.md`
- `by-class/StringMenuItem.md`
- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`
- `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md`
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`
- `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`
- `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`
- `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`
- `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`
- `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`
- `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
- `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`
- `by-type/by-struct/MenuItemLayouts.md`
- `by-type/by-vtable/MenuItemVtables.md`

Generated output checked read-only:

- `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
- `auto-generated/-ag-research-tracker.md`

Old report/search evidence checked:

- Searched `executed-b-agent-research` and `tools/leaser/Agents` for `0000MN`, `PopupMenuControls`, every exact empty UID/name, `MenuItemLayouts`, `MenuItemVtables`, `PopupMenuControlPaneCore`, and scalar deleting destructor report names.
- Opened prior executed reports as leads, not as substitutes for current MCP:
  - B003 popup-menu-controls source-quality report for `0002J5`, `0002J9`, `0002JA`, `0002JC`, `0002JD`, `0002JF`, `0002JG`.
  - B003 `0002JF` scalar deleting destructor recheck.
  - B015 `0002JB` `SeparatorMenuItemConstructor`.
  - B010 `00011X` shared `PopupMenuSelectionCallbackInvoke`.
- Checked `tools/leaser/Agents/Supervisor_notes.md` lead entries for executed `0002JG` and B003/B010/B015 incorporation notes.

Negative checks:

- No direct `0000MN-PopupMenuControls-empty-emitter-family` report existed before this report.
- No raw pointer hits were found for the tiny nonvirtual `MenuItem` accessor/setter/copy helper starts (`0x00516f70`, `0x00516f80`, `0x00516fa0`, `0x00516fb0`, `0x00516fd0`), supporting ordinary source method bodies without separate vtable placement.
- No body-level source should be emitted for raw `.rdata` vtable bytes, scalar deleting wrapper lowering, or aggregate pages whose exact children already carry the actual source behavior.
- No evidence supports moving this whole family to `MenuDialogFactoryHelpers`, `RightButtonMenuPane`, `VoteMenuPane`, `MenuVarietyPanes`, or caller-specific dialog source files.

## MCP Provenance

MCP endpoint: `http://127.0.0.1:13337/mcp`

MCP initialize succeeded:

- Server: `ida-pro-mcp`
- Version: `1.0.0`

MCP active database:

- `session_id: supervisor_resume_20260629`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Worker PID: `17592`
- `is_analyzing:false`
- `is_active:true`

`server_health(database=supervisor_resume_20260629)` succeeded:

- `status:"ok"`
- Module: `NexusTK.exe`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Imagebase: `0x400000`
- `auto_analysis_ready:true`
- `hexrays_ready:true`
- `strings_cache_ready:true`
- Strings cache size: `2067`

Narrow schema-current MCP calls used:

- `lookup_funcs` for all current empty and adjacent PopupMenu/MenuItem/MenuPane function starts.
- `get_bytes` for tiny helper bodies, scalar deleting destructor wrappers, padding, and vtable runs.
- `insn_query` for the exact tiny `MenuItem` helper block at `0x00516f70-0x00516fe1`.
- `get_int` for vtable entries at `0x0061eb94-0x0061ebec`.
- `xrefs_to` for helper starts, destructor starts, vtable slots, and PopupMenuControlPane vtable references.
- `callees` for the constructor/destructor/layout/draw paths.
- `analyze_function` for `0x00498040`, `0x0049b3b0`, `0x00516400`, `0x00516790`, `0x00516f70`, and `0x00516f90`.
- `decompile` for `0x005172e0`, `0x00517400`, and `0x0049b3b0`.
- `find_bytes` for little-endian pointer hits to key helper/wrapper targets.

Representative MCP observations:

- `0x00516f70`: `mov al, [ecx+14h]; retn`, decompiles as `return this[20]`, no callers/callees/xrefs.
- `0x00516f80`: writes argument byte to `[ecx+14h]`, `retn 4`, no pointer hits.
- `0x00516f90`: existing emitted sibling, `mov al, [ecx+15h]; retn`, decompiles as `return this[21]`.
- `0x00516fa0`: writes argument byte to `[ecx+15h]`, `retn 4`, no pointer hits.
- `0x00516fb0`: copies 16 bytes from `[ecx+4]` to caller buffer with `movups`, `retn 4`.
- `0x00516fd0`: copies 16 bytes from caller buffer to `[ecx+4]` with `movups`, `retn 4`.
- `0x005172e0`: compiler scalar deleting wrapper for `MenuItem`, referenced by vtable slots at `0x0061eb98` and `0x0061ebd0`, not handwritten business logic.
- `0x00517400`: compiler scalar deleting wrapper for `StringMenuItem`, referenced by `0x0061ebb4`, not handwritten business logic.
- Menu item vtable run:
  - `0x0061eb98 -> 0x005172e0` (`MenuItem` destructor slot)
  - `0x0061ebb4 -> 0x00517400` (`StringMenuItem` destructor slot)
  - `0x0061ebc0 -> 0x00517090`, `0x0061ebc4 -> 0x005170d0`, `0x0061ebc8 -> 0x005170f0`
  - `0x0061ebd0 -> 0x005172e0` (`SeparatorMenuItem` destructor slot)
  - `0x0061ebe4 -> 0x00517250`, `0x0061ebe8 -> 0x00517220`, `0x0061ebec -> 0x00517240`
  - purecall slots at the unimplemented abstract-base positions remain `0x005ca28c`.
- `0x00498040`: `PopupMenuControlPane` constructor installs three vtable pointers, stores menu type in `this[68]`, allocates a 24-byte `PlainMemberFunctionObject` callback with bound target `0x00498220`, constructs a 268-byte `MenuPane`, stores it at `this[66]`, initializes selected index to `-1`, and marks dirty byte `this+255`.
- `0x0049b3b0`: `PopupMenuControlPane` scalar deleting destructor wrapper writes PopupMenuControlPane vtables, deletes owned `Block[66]` through its virtual destructor, calls `sub_544580`, and conditionally deletes the 0x114-byte object through `sub_4F4AC0`.
- `0x00516400`: `MenuPane` relayout iterates item list at `this[62]`, calls item metric virtual slot `+0x0c`, computes maximum width, initializes rectangles, and writes `*(_OWORD *)(item + 4)` into item bounds.
- `0x00516790`: `MenuPane` draw/layout path uses `MENUBACK.EPF`, reads each item bounds at `item+4`, and dispatches item virtual draw slot `+0x14`.
- `xrefs_to(0x00516290)` has a code xref from the `PopupMenuControlPane` constructor at `0x004980f6`, preserving the constructor/owned-menu relationship.

## Positive Evidence

The generated C++ already contains coherent emitted method bodies for the core `MenuItem`, `StringMenuItem`, and `SeparatorMenuItem` methods. The current empty markers line up with the missing declaration/support layer and with small exact helper methods around those emitted bodies, not with a broken source-root decision.

Current by-* docs already establish:

- `MenuItem +0x04` is a 16-byte bounds rectangle.
- `MenuItem +0x14` is the enabled byte; the constructor's `word [this+0x14]=1` is compiler-coalesced adjacent-byte initialization of enabled/selected.
- `MenuItem +0x15` is the selected/highlight byte used by existing `MenuItem::IsSelected()` and `StringMenuItem::DrawItem()`.
- `StringMenuItem +0x18` is inline `wchar_t m_text[0x80]`.
- `MenuItemMetrics` returns are height-first (`height`, then `width`) based on existing `SeparatorMenuItem::GetDefaultDimensions()` and `StringMenuItem::GetItemSize()`.
- `MenuItemStyleFlags` is a 16-bit wrapper used by `SeparatorMenuItem::GetStyleFlags()`.
- `StringMenuItem` and `SeparatorMenuItem` are concrete menu-entry subclasses for the current file family, with vtable and method evidence already routed through `0000MN`.
- The file page itself already records the possible later source split, which is a confidence cap, not a reason to leave current emitters empty.

The direct MCP evidence closes the most important empty-emitter holes:

- `0002J4`, `0002JH`, `0002JI`, `0002JJ`, and `0002JK` are exact tiny methods, not raw tables or ambiguous helper fragments.
- `0002JF`, `0002JG`, and `0002YA` are scalar deleting destructor wrappers. The proper source-level treatment is ordinary destructor/class semantics plus a no-handwritten-wrapper marker, not decompiler-shaped wrapper C++.
- `0001Y4` is concrete vtable layout evidence. MSVC should regenerate this from class declarations and virtual method bodies; raw `.rdata` bytes should not be emitted as C++.
- `0001BK` and `00011F` are aggregate/routing pages. They should not duplicate exact child C++ bodies.

## Negative And Counter-Evidence

The following alternatives were considered and rejected:

- Move the source root out of `PopupMenuControls.cpp`: rejected. Current docs, generated output, vtable/layout pages, constructor relationships, and prior accepted reports all support `0000MN` as the current source root. The later `MenuPane.cpp`/`MenuItem.cpp`/`PopupMenuControlPane.cpp` split remains a caveat only.
- Route tiny base methods directly to `0000MN` instead of `00007V`: rejected. `CANONICAL_OWNER:00007V` is the narrow class owner for `MenuItem` methods; `EMITTER_UIDS:00007V` then surfaces through the class to the file root.
- Treat `MenuItem +0x14` and `+0x15` as anonymous `stateFlag0` and `stateFlag1`: rejected for source-facing C++. Current executed evidence and draw/constructor use support `m_enabled` and `m_selected`.
- Emit scalar deleting destructor wrapper bodies in C++: rejected. The wrapper code is compiler lowering. Source-facing output should rely on normal virtual destructor semantics and include only explicit no-standalone-source comments for empty-marker accounting.
- Emit raw vtable data as C++: rejected. The vtables are compiler output and should be regenerated from class declarations and virtual method bodies.
- Invent complete `MenuPane` or `PopupMenuControlPane` class declarations now: rejected. Current evidence is strong enough for ownership and exact child methods, but not enough for final source-quality field/member declarations on those larger pane classes.
- Force a caller-feature owner for `StringMenuItem` construction/copy/measure/text/draw based on dialog xrefs: rejected. Those xrefs are consumers of reusable menu-item source, not owners.

## Heuristic And Inference Reanalysis

Active code-entry gate:

- Every proposed code-bearing page is currently `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route to `0000MN`, and has average score greater than `85`.
- The C++ recommendations below are still conservative: exact first-draft bodies are limited to tiny helpers whose raw instructions fully determine the behavior; declaration shells are used only where current evidence supports class/type source shape; comment-only markers are used where the binary range is compiler-generated or aggregate/vtable support.

Inference status:

- `m_enabled` and `m_selected` are source-facing names, not direct symbol recoveries. They are supported by constructor initialization, draw-path selected use, setter/accessor pairing, and current accepted docs. Keep a final-name caveat in affected pages.
- `RectBounds` is already used by emitted `SeparatorMenuItem::DrawItem()` output. This report does not recommend declaring `RectBounds` in `MenuItemLayouts` to avoid duplicating a broader geometry type owner.
- `MenuItemMetrics` and `MenuItemStyleFlags` are local menu item support types and should be emitted by `MenuItemLayouts`.
- `MenuPane` and `PopupMenuControlPane` remain below final declaration detail; use no-standalone/class-route markers with `[[CHILDREN]]`, not speculative field lists.

## Ranked Ownership And Source Placement

1. `by-file/PopupMenuControls.md` (`0000MN`) remains the current by-file source root for generated `NexusTK/ui/menu/PopupMenuControls.cpp`.
2. Class owners:
   - `MenuItem` methods route through `by-class/MenuItem.md` (`00007V`).
   - `StringMenuItem` methods route through `by-class/StringMenuItem.md` (`0000E8`).
   - `SeparatorMenuItem` methods route through `by-class/SeparatorMenuItem.md` (`0000CY`).
   - `MenuPane` support routes through `by-class/MenuPane.md` (`00007W`).
   - `PopupMenuControlPane` support routes through `by-class/PopupMenuControlPane.md` (`0000AN`).
3. Type support:
   - `MenuItemLayouts` (`0001V5`) owns the support type declarations for `MenuItemMetrics` and `MenuItemStyleFlags`.
   - `MenuItemVtables` (`0001Y4`) owns vtable evidence only; output should be a no-raw-vtable marker plus children.
4. Exact function/memory pages keep exact behavior or no-code proof:
   - tiny `MenuItem` helpers get exact first-draft method bodies;
   - scalar deleting wrappers get no-handwritten-wrapper comment markers;
   - aggregate ranges get no-standalone-body markers plus `[[CHILDREN]]`.

## Empty-Emitter Inventory And Per-UID Disposition

| UID | Path | Current state | Immediate disposition |
| --- | --- | --- | --- |
| `00007V` | `by-class/MenuItem.md` | `86/88`, class owner/emitter `0000MN`, empty C++ | Add declaration shell with fields, virtuals, and `[[CHILDREN]]`; raise to `88/90`; position `10`. |
| `0002J4` | `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md` | `85/91`, owner/emitter `00007V`, empty C++ | Emit exact `MenuItem::IsEnabled() const`; raise to `86/91`. |
| `0002JH` | `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md` | `85/90`, owner/emitter `00007V`, empty C++ | Emit exact `MenuItem::SetEnabled(bool)`; raise to `86/90`. |
| `0002JI` | `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md` | `85/90`, owner/emitter `00007V`, empty C++ | Emit exact `MenuItem::SetSelected(bool)`; raise to `86/90`. |
| `0002JJ` | `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md` | `85/91`, owner/emitter `00007V`, empty C++ | Emit exact `MenuItem::GetBounds(RectBounds *) const`; raise to `86/91`. |
| `0002JK` | `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md` | `85/91`, owner/emitter `00007V`, empty C++ | Emit exact `MenuItem::SetBounds(const RectBounds *)`; raise to `86/91`. |
| `0002JF` | `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md` | `86/92`, owner/emitter `00007V`, empty C++ | Do not emit wrapper body; add comment-only no-handwritten-wrapper marker; score unchanged. |
| `00007W` | `by-class/MenuPane.md` | `86/89`, class owner/emitter `0000MN`, empty C++ | Add class-route no-declaration marker with `[[CHILDREN]]`; score unchanged; position `20`. |
| `0000AN` | `by-class/PopupMenuControlPane.md` | `86/88`, class owner/emitter `0000MN`, empty C++ | Add class-route no-declaration marker with `[[CHILDREN]]`; score unchanged; position `21`. |
| `00011F` | `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md` | `86/90`, owner/emitter `0000AN`, empty C++ | Add aggregate no-standalone-body marker with `[[CHILDREN]]`; score unchanged. |
| `0002YA` | `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md` | `86/88`, owner/emitter `0000AN`, empty C++ and weak summary | Add no-handwritten-wrapper marker; update summary/evidence; raise to `87/89`. |
| `0000CY` | `by-class/SeparatorMenuItem.md` | `86/90`, class owner/emitter `0000MN`, empty C++ | Add declaration shell with `[[CHILDREN]]`; raise to `88/91`; position `12`. |
| `0000E8` | `by-class/StringMenuItem.md` | `88/90`, class owner/emitter `0000MN`, empty C++ | Add declaration shell with `[[CHILDREN]]`; raise to `89/91`; position `11`. |
| `0002JG` | `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` | `86/92`, owner/emitter `0000E8`, empty C++ | Do not emit wrapper body; add comment-only no-handwritten-wrapper marker; score unchanged. |
| `0001BK` | `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md` | `88/90`, owner/emitter `0000MN`, empty C++; stale Item Summary wording | Add aggregate no-standalone-body marker with `[[CHILDREN]]`; update stale "Unassigned/84/80" summary wording; score unchanged. |
| `0001V5` | `by-type/by-struct/MenuItemLayouts.md` | `85/89`, owner/emitter `0000MN`, empty C++ | Emit exact support structs for `MenuItemMetrics` and `MenuItemStyleFlags`; raise to `86/90`; position `1`. |
| `0001Y4` | `by-type/by-vtable/MenuItemVtables.md` | `86/91`, owner/emitter `0000MN`, empty C++ | Add no-raw-vtable marker with `[[CHILDREN]]`; score unchanged; position `13`. |

No empty marker is excluded from the immediate callback batch. The only non-body cases are resolved with explicit no-code/comment markers rather than left blank.

## Exact Formal Insertions

The following blocks are exact proposed formal `RECONSTRUCTION_CPP CODE` insertion text for the target pages. During implementation, replace the target page's current formal block with the matching block, including the same header/BEGIN/END sentinel lines. These are text blocks because the sentinel lines are documentation syntax, not C++.

### `0001V5` `by-type/by-struct/MenuItemLayouts.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `EMITTER_POSITION_OPTIONAL:1`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MenuItemMetrics
{
    int height;
    int width;
};

struct MenuItemStyleFlags
{
    unsigned short bits;
};

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `00007V` `by-class/MenuItem.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `EMITTER_POSITION_OPTIONAL:10`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MenuItem : public LObject
{
public:
    MenuItem();
    virtual ~MenuItem();

    bool IsEnabled() const;
    void SetEnabled(bool enabled);
    bool IsSelected() const;
    void SetSelected(bool selected);

    void GetBounds(RectBounds *bounds) const;
    void SetBounds(const RectBounds *bounds);

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const = 0;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const = 0;
    virtual void DrawItem(GrafPort *port) = 0;

protected:
    RectBounds m_bounds;
    bool m_enabled;
    bool m_selected;

    [[CHILDREN]]
};

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0000E8` `by-class/StringMenuItem.md`

Recommended metadata:

- `COMPLETION:89`
- `CONFIDENCE:91`
- `EMITTER_POSITION_OPTIONAL:11`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class StringMenuItem : public MenuItem
{
public:
    explicit StringMenuItem(const wchar_t *text);
    virtual ~StringMenuItem();

    errno_t CopyText(wchar_t *destination, size_t sizeInWords) const;

    virtual MenuItemMetrics GetItemSize(GrafPort *port) const;
    virtual errno_t GetText(wchar_t *destination, size_t sizeInWords) const;
    virtual void DrawItem(GrafPort *port);

protected:
    wchar_t m_text[0x80];

    [[CHILDREN]]
};

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0000CY` `by-class/SeparatorMenuItem.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:91`
- `EMITTER_POSITION_OPTIONAL:12`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SeparatorMenuItem : public MenuItem
{
public:
    SeparatorMenuItem();
    virtual ~SeparatorMenuItem();

    virtual void DrawItem(GrafPort *port);
    virtual MenuItemMetrics GetDefaultDimensions() const;
    virtual MenuItemStyleFlags GetStyleFlags() const;

    [[CHILDREN]]
};

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0001Y4` `by-type/by-vtable/MenuItemVtables.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`
- `EMITTER_POSITION_OPTIONAL:13`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001Y4] MenuItem/StringMenuItem/SeparatorMenuItem vtable layout evidence.
// MSVC regenerates this vtable data from the class declarations and exact virtual method implementations.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `00007W` `by-class/MenuPane.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:89`
- `EMITTER_POSITION_OPTIONAL:20`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MenuPane class declaration is intentionally withheld until its field layout,
// callback object ownership, and final method names are ready for source-quality declaration C++.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0000AN` `by-class/PopupMenuControlPane.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `EMITTER_POSITION_OPTIONAL:21`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// PopupMenuControlPane class declaration is intentionally withheld until its
// owned-menu/callback fields and ControlPane base layout are ready for source-quality declaration C++.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002J4` `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool MenuItem::IsEnabled() const
{
    return m_enabled != 0;
}

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JH` `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MenuItem::SetEnabled(bool enabled)
{
    m_enabled = enabled;
}

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JI` `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MenuItem::SetSelected(bool selected)
{
    m_selected = selected;
}

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JJ` `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MenuItem::GetBounds(RectBounds *bounds) const
{
    *bounds = m_bounds;
}

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JK` `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:91`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void MenuItem::SetBounds(const RectBounds *bounds)
{
    m_bounds = *bounds;
}

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JF` `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:92`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002JF] compiler-generated MenuItem scalar deleting destructor wrapper;
// rebuilt from ordinary virtual MenuItem destructor semantics, not handwritten source.

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `00011F` `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:00011F] PopupMenuControlPane compact method-family aggregate.
// Do not emit a standalone aggregate body; exact child ranges and class declarations provide the source coverage.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002YA` `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md`

Recommended metadata:

- `COMPLETION:87`
- `CONFIDENCE:89`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002YA] compiler-generated PopupMenuControlPane scalar deleting destructor wrapper;
// rebuilt from ordinary PopupMenuControlPane destructor semantics and owned MenuPane cleanup.

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002JG` `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:92`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0002JG] compiler-generated StringMenuItem scalar deleting destructor wrapper;
// rebuilt from ordinary/default StringMenuItem destructor semantics, not handwritten source.

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0001BK` `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`

Recommended metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0001BK] MenuPane/MenuItem aggregate range.
// Do not emit a standalone aggregate body; exact child methods, class declarations, and type pages provide the source coverage.
[[CHILDREN]]

*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### `0002YA` Item Summary Repair

Current problem: `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md` has an empty `Item Summary`.

Recommended summary text:

```text
Live MCP confirms a 0x67-byte compiler scalar deleting destructor wrapper for PopupMenuControlPane at 0x0049b3b0: the body reinstalls PopupMenuControlPane vtables, deletes owned MenuPane pointer Block[66] through its virtual destructor, calls sub_544580 for base cleanup, conditionally frees the 0x114-byte allocation through sub_4F4AC0 when deleting flag bit 1 is set, has code thunks at 0x0049af9b and 0x0049afa6 plus vtable-data xref 0x00617fb8, and has no evidence of handwritten business logic beyond ordinary destructor semantics.
```

### `0001BK` Item Summary Repair

Current problem: `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md` still has stale summary wording that mentions being unassigned under an old `84/80` parent blocker, while `0000MN` is now `86/85` and the page is attached.

Recommended summary edit:

```text
Replace stale "Unassigned under corrected 85/85 gate" and old "PopupMenuControls is 84/80" wording with current status: the aggregate is attached to [UID:0000MN][PopupMenuControls] at 86/85 after the raw helper split and current MenuPane/MenuItem child routing; it remains an aggregate/source-coverage page whose exact children and class/type pages carry emitted source.
```

### `0000MN` `by-file/PopupMenuControls.md`

Recommended metadata:

- `COMPLETION:86`
- `CONFIDENCE:85`
- `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`
- `CANONICAL_OWNER:FILE`

Recommended status/change-log addition:

```text
2026-06-30 B008 empty-emitter family report resolves the current 17 generated empty markers without changing this by-file source-root route. The batch should add MenuItem/StringMenuItem/SeparatorMenuItem declaration/type support, exact tiny MenuItem enabled/selected/bounds helpers, and no-standalone-source markers for compiler scalar deleting destructors, aggregate pages, and vtable evidence. Current source-root confidence remains capped at 85 because a later original-source review may still split MenuPane.cpp, MenuItem.cpp, or PopupMenuControlPane.cpp, but no current empty marker requires moving the family away from PopupMenuControls.cpp.
```

## Score And Metadata Disposition

Target `0000MN`:

- Keep `COMPLETION:86`.
- Keep `CONFIDENCE:85`.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
- Keep `CANONICAL_OWNER:FILE`.
- Rationale: the empty markers are repairable, but file-level source-placement and complete field-layout uncertainty remain. This is still a coherent source root, not a final-audit source file.

Support score recommendations:

| UID | Completion | Confidence | Metadata effect |
| --- | ---: | ---: | --- |
| `0001V5` | `86` | `90` | `EMITTER_POSITION_OPTIONAL:1`; emit `MenuItemMetrics` and `MenuItemStyleFlags`. |
| `00007V` | `88` | `90` | `EMITTER_POSITION_OPTIONAL:10`; class declaration with `[[CHILDREN]]`. |
| `0000E8` | `89` | `91` | `EMITTER_POSITION_OPTIONAL:11`; class declaration with `[[CHILDREN]]`. |
| `0000CY` | `88` | `91` | `EMITTER_POSITION_OPTIONAL:12`; class declaration with `[[CHILDREN]]`. |
| `0001Y4` | `86` | `91` | `EMITTER_POSITION_OPTIONAL:13`; no raw vtable marker. |
| `00007W` | `86` | `89` | `EMITTER_POSITION_OPTIONAL:20`; route marker with `[[CHILDREN]]`. |
| `0000AN` | `86` | `88` | `EMITTER_POSITION_OPTIONAL:21`; route marker with `[[CHILDREN]]`. |
| `0002J4` | `86` | `91` | exact method C++. |
| `0002JH` | `86` | `90` | exact method C++. |
| `0002JI` | `86` | `90` | exact method C++. |
| `0002JJ` | `86` | `91` | exact method C++. |
| `0002JK` | `86` | `91` | exact method C++. |
| `0002JF` | `86` | `92` | comment-only scalar deleting wrapper marker. |
| `00011F` | `86` | `90` | aggregate no-standalone marker with `[[CHILDREN]]`. |
| `0002YA` | `87` | `89` | comment-only scalar deleting wrapper marker plus summary repair. |
| `0002JG` | `86` | `92` | comment-only scalar deleting wrapper marker. |
| `0001BK` | `88` | `90` | aggregate no-standalone marker with `[[CHILDREN]]` plus stale summary repair. |

No support doc should be downgraded. No page should be raised to `95+`.

## Callback Implementation And Validation

Callback applied on 2026-06-30.

Changed by-* docs:

- `by-file/PopupMenuControls.md`
- `by-type/by-struct/MenuItemLayouts.md`
- `by-class/MenuItem.md`
- `by-class/StringMenuItem.md`
- `by-class/SeparatorMenuItem.md`
- `by-class/MenuPane.md`
- `by-class/PopupMenuControlPane.md`
- `by-type/by-vtable/MenuItemVtables.md`
- `by-memory/0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md`
- `by-memory/0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md`
- `by-memory/0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md`
- `by-memory/0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md`
- `by-memory/0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md`
- `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
- `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`
- `by-memory/0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md`
- `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`
- `by-memory/0x00516290-0x00517441.MenuPaneAndItems.md`

Lease state:

- Lease command: `python .\tools\leaser\leaser.py B008 lease <18 accepted by-* paths>` returned `Success` for all 18 paths immediately before editing.
- Release command after validation: `python .\tools\leaser\leaser.py B008 unlease <18 accepted by-* paths>` returned `Rejected[No active lease]` for each path, meaning no B008 lease remained active by cleanup time.
- Lease report recheck after release attempt showed no active B008 entries; only old expired unrelated Supervisor FittingRoom rows were listed.

Manual generated/coverage/tool-state edits:

- None. `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` and generated reports were refreshed only by validator-owned generated refresh during scoped validator runs. No manual `auto-generated/*`, generated report, manual `-coverage-report.md`, validator/tool state, IDA DB, executed archive, supervisor ledger, archive, or lock-file edit was made.

Scoped validators were run from `E:/NTK/GhidraBridge/source-3/project-documentation` with this command shape:

> Executable block R001 was removed from this report and preserved verbatim in [0000MN-PopupMenuControls-empty-emitter-family-source-quality-removed.md](0000MN-PopupMenuControls-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

| Path | command_id | command_timestamp | Exit | ok | generated_refresh | Warnings |
| --- | --- | --- | ---: | ---: | --- | --- |
| `by-type\by-struct\MenuItemLayouts.md` | `000000002440` | `2026-06-30T05:43:05-04:00` | `0` | `1` | `completed` (`000000002440`) | none |
| `by-class\MenuItem.md` | `000000002441` | `2026-06-30T05:43:17-04:00` | `0` | `1` | `completed` (`000000002441`) | none |
| `by-class\StringMenuItem.md` | `000000002442` | `2026-06-30T05:43:27-04:00` | `0` | `1` | `completed` (`000000002442`) | none |
| `by-class\SeparatorMenuItem.md` | `000000002443` | `2026-06-30T05:43:37-04:00` | `0` | `1` | `completed` (`000000002443`) | none |
| `by-type\by-vtable\MenuItemVtables.md` | `000000002444` | `2026-06-30T05:43:48-04:00` | `0` | `1` | `completed` (`000000002444`) | none |
| `by-class\MenuPane.md` | `000000002445` | `2026-06-30T05:43:59-04:00` | `0` | `1` | `completed` (`000000002445`) | none |
| `by-class\PopupMenuControlPane.md` | `000000002446` | `2026-06-30T05:44:09-04:00` | `0` | `1` | `completed` (`000000002446`) | none |
| `by-memory\0x00516f70-0x00516f74.MenuItemStateFlag0Accessor.md` | `000000002447` | `2026-06-30T05:44:20-04:00` | `0` | `1` | `completed` (`000000002447`) | none |
| `by-memory\0x00516f80-0x00516f8d.MenuItemSetStateFlag0.md` | `000000002449` | `2026-06-30T05:44:30-04:00` | `0` | `1` | `completed` (`000000002449`) | none |
| `by-memory\0x00516fa0-0x00516fad.MenuItemSetStateFlag1.md` | `000000002450` | `2026-06-30T05:44:41-04:00` | `0` | `1` | `completed` (`000000002450`) | none |
| `by-memory\0x00516fb0-0x00516fc1.MenuItemCopyBoundsRect.md` | `000000002451` | `2026-06-30T05:44:51-04:00` | `0` | `1` | `completed` (`000000002451`) | none |
| `by-memory\0x00516fd0-0x00516fe1.MenuItemSetBoundsRect.md` | `000000002452` | `2026-06-30T05:45:02-04:00` | `0` | `1` | `completed` (`000000002452`) | none |
| `by-memory\0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md` | `000000002453` | `2026-06-30T05:45:12-04:00` | `0` | `1` | `completed` (`000000002453`) | none |
| `by-memory\0x00498040-0x00498599.PopupMenuControlPaneCore.md` | `000000002454` | `2026-06-30T05:45:23-04:00` | `0` | `1` | `completed` (`000000002454`) | none |
| `by-memory\0x0049b3b0-0x0049b417.PopupMenuControlPaneScalarDeletingDestructor.md` | `000000002455` | `2026-06-30T05:45:33-04:00` | `0` | `1` | `completed` (`000000002455`) | none |
| `by-memory\0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md` | `000000002456` | `2026-06-30T05:45:44-04:00` | `0` | `1` | `completed` (`000000002456`) | none |
| `by-memory\0x00516290-0x00517441.MenuPaneAndItems.md` | `000000002457` | `2026-06-30T05:45:54-04:00` | `0` | `1` | `completed` (`000000002457`) | none |
| `by-file\PopupMenuControls.md` | `000000002458` | `2026-06-30T05:46:05-04:00` | `0` | `1` | `completed` (`000000002458`) | none |

Generated freshness:

- Refreshed generated file: `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`
- Header after final validator:
  - `validator-command-id: 000000002458`
  - `validator-refreshed-at: 2026-06-30T05:46:05-04:00`
  - `validator-refresh-source: foreground-generated-refresh`
- Freshness disposition: current for final by-file validator command `000000002458`.
- Former empty-marker check: `Select-String` for `Empty Emitter Marker` in `PopupMenuControls.cpp` returned count `0`; the 17 accepted UIDs now emit formal code/comment markers instead of empty markers.

## Callback Coordination Note

Before implementation, re-read current contents because other B-agents may have landed accepted edits after this report. B007/B009/B010/B011 may be touching shared popup-menu, UI menu, class, type, vtable, or support docs. Respect active leases. If a support file is leased, wait for expiry and recheck, or mark that specific support edit blocked with exact lease owner, file, and expiry. Do not overwrite newer accepted support edits; adapt this report's proposed text to same-or-greater current detail.

## Claim And Incorporation Ledger

| Claim ID | Claim | Target docs | Verification state | Evidence / Confidence | Callback incorporation requirement |
| --- | --- | --- | --- | --- | --- |
| C01 | `0000MN` is the current source root for generated `NexusTK/ui/menu/PopupMenuControls.cpp`. | `by-file/PopupMenuControls.md` | applied | `by-file/PopupMenuControls.md` keeps `86/85`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`; B008 change entry records the source-root and split-caveat rationale. | Validated by command `000000002458`; generated header is current for `0000MN`. |
| C02 | The 17 empty markers are exactly the queue family to repair. | All 17 listed support docs | applied | All 17 support docs received accepted C++/comment markers or declaration/type blocks; generated `PopupMenuControls.cpp` now has `Empty Emitter Marker` count `0`. | Proof: generated header command `000000002458`; validators `000000002440`-`000000002458`. |
| C03 | `MenuItem +0x14` is source-facing `m_enabled`; `0x00516f70` and `0x00516f80` are getter/setter. | `00007V`, `0002J4`, `0002JH`, `0001V5` | applied | `MenuItem.md` declaration contains `m_enabled`, `IsEnabled`, `SetEnabled`; `0002J4` and `0002JH` formal blocks emit exact methods; change entries preserve MCP byte/xref proof. | Validators `000000002441`, `000000002447`, `000000002449`, `000000002440`. |
| C04 | `MenuItem +0x15` is source-facing `m_selected`; `0x00516fa0` is setter. | `00007V`, `0002JI`, `0001V5` | applied | `MenuItem.md` declaration contains `m_selected` and `SetSelected`; `0002JI` formal block emits exact setter; change entries preserve draw-path/paired accessor evidence. | Validators `000000002441`, `000000002450`, `000000002440`. |
| C05 | `MenuItem +0x04` is a 16-byte bounds rectangle copied by `0x00516fb0` and `0x00516fd0`. | `00007V`, `0002JJ`, `0002JK`, `0001V5` | applied | `MenuItem.md` declaration contains `RectBounds m_bounds`, `GetBounds`, and `SetBounds`; `0002JJ` and `0002JK` emit exact formal methods; `MenuItemLayouts` preserves bounds evidence without duplicating `RectBounds`. | Validators `000000002441`, `000000002451`, `000000002452`, `000000002440`. |
| C06 | `MenuItemMetrics` and `MenuItemStyleFlags` are menu-item support types ready for emitted layout C++. | `0001V5`, `0000CY`, `0000E8`, `00007V` | applied | `MenuItemLayouts.md` now emits `MenuItemMetrics` and `MenuItemStyleFlags` at position `1`; class declarations reference those types. | Validators `000000002440`, `000000002441`, `000000002442`, `000000002443`. |
| C07 | `MenuItem` class declaration can be emitted as declaration shell with fields and `[[CHILDREN]]`. | `00007V` | applied | `MenuItem.md` now has `88/90`, position `10`, and the accepted declaration shell with `[[CHILDREN]]`; change entry documents source-placement caveat. | Validator `000000002441`. |
| C08 | `StringMenuItem` class declaration can be emitted with inline `m_text[0x80]` and `[[CHILDREN]]`. | `0000E8` | applied | `StringMenuItem.md` now has `89/91`, position `11`, and the accepted declaration shell with inline label buffer and `[[CHILDREN]]`. | Validator `000000002442`. |
| C09 | `SeparatorMenuItem` class declaration can be emitted with separator virtual declarations and `[[CHILDREN]]`. | `0000CY` | applied | `SeparatorMenuItem.md` now has `88/91`, position `12`, and the accepted declaration shell; inherited purecall/abstract caveat preserved in change entry. | Validator `000000002443`. |
| C10 | `MenuPane` and `PopupMenuControlPane` larger class declarations are not ready for field-complete source C++. | `00007W`, `0000AN` | applied | `MenuPane.md` and `PopupMenuControlPane.md` now emit no-declaration route markers plus `[[CHILDREN]]` with positions `20` and `21`; change entries explain why fields are withheld. | Validators `000000002445`, `000000002446`. |
| C11 | `0002JF` and `0002JG` are compiler scalar deleting destructor wrappers, not handwritten source methods. | `0002JF`, `0002JG` | applied | Both destructor pages now emit formal comment-only no-handwritten-wrapper markers; no executable wrapper body was added. | Validators `000000002453`, `000000002456`. |
| C12 | `0002YA` is a compiler scalar deleting destructor wrapper with owned `MenuPane` cleanup. | `0002YA`, `0000AN` | applied | `0002YA` now has `87/89`, accepted marker, filled Item Summary, and change entry with owned `Block[66]` MenuPane cleanup proof; `0000AN` route marker remains class-level. | Validators `000000002455`, `000000002446`. |
| C13 | `00011F` and `0001BK` are aggregate/routing pages and should not duplicate child bodies. | `00011F`, `0001BK` | applied | Both pages now emit aggregate no-standalone-body markers plus `[[CHILDREN]]`; `0001BK` summary now says attached to PopupMenuControls after the split. | Validators `000000002454`, `000000002457`. |
| C14 | `0001Y4` should not emit raw vtable data. | `0001Y4` | applied | `MenuItemVtables.md` now emits the no-raw-vtable marker plus `[[CHILDREN]]` at position `13`; score unchanged. | Validator `000000002444`. |
| C15 | No current evidence supports moving this file family to dialog-specific/caller-specific source owners. | `0000MN`, child class/memory pages | applied | Owners/emitters were preserved; `PopupMenuControls.md` B008 entry states the source root remains `PopupMenuControls.cpp` and caller-specific/dialog ownership is not adopted. | Final by-file validator `000000002458`. |
| C16 | Existing `0001BK` summary contains stale old-gate wording. | `0001BK` | applied | `0001BK` Item Summary now removes "Unassigned" and old `84/80` parent-blocker wording and records current attached source coverage. | Validator `000000002457`. |
| C17 | Implementation must use validators and generated refresh; report-only did not. | Report and callback checkpoint | applied | Callback section records every validator command ID/timestamp/exit/ok/warnings, generated header freshness, and lease state. | Final generated header `validator-command-id: 000000002458`; all validators exit `0`, ok `1`, warnings none. |

## Implementation Tracking Checklist

Report-only evidence checklist:

- [x] Loaded project-level B-agent workflow skill and B008 goal.
- [x] Read current target, current support docs, generated `PopupMenuControls.cpp`, and tracker rows.
- [x] Verified MCP availability and used narrow schema-current MCP calls.
- [x] Searched/opened prior executed B-agent reports and supervisor notes as leads.
- [x] Inventoried all 17 empty markers and classified every marker.
- [x] Wrote exact proposed formal insertion text for every included empty marker.

Implementation callback checklist:

- [x] Re-read every changed by-* file immediately before editing and adapt to any newer accepted edits. Proof: current metadata/formal blocks and summary/changelog areas were read before the lease/edit batch; no same-detail accepted callback edits were already present.
- [x] Check active leases immediately before editing; take leases only for files in the immediate edit batch. Proof: current lease report had no active conflicting accepted-path leases; lease command returned `Success` for all 18 accepted paths.
- [x] Update `by-type/by-struct/MenuItemLayouts.md` with support structs, score/position, and supporting notes. Proof: now `86/90`, position `1`, emits `MenuItemMetrics` and `MenuItemStyleFlags`; validator `000000002440`.
- [x] Update `by-class/MenuItem.md` with class declaration shell, score/position, and supporting notes. Proof: now `88/90`, position `10`, emits accepted declaration shell; validator `000000002441`.
- [x] Update `0002J4`, `0002JH`, `0002JI`, `0002JJ`, and `0002JK` with exact tiny `MenuItem` helper C++ and score changes. Proof: each formal block emits accepted `IsEnabled`, `SetEnabled`, `SetSelected`, `GetBounds`, or `SetBounds`; validators `000000002447`, `000000002449`, `000000002450`, `000000002451`, `000000002452`.
- [x] Update `0002JF` with the scalar deleting destructor no-handwritten-wrapper marker. Proof: formal comment marker added; validator `000000002453`.
- [x] Update `by-class/StringMenuItem.md` and `by-class/SeparatorMenuItem.md` with declaration shells, scores, positions, and notes. Proof: `StringMenuItem` now `89/91` position `11`; `SeparatorMenuItem` now `88/91` position `12`; validators `000000002442`, `000000002443`.
- [x] Update `0002JG` with the scalar deleting destructor no-handwritten-wrapper marker. Proof: formal comment marker added; validator `000000002456`.
- [x] Update `by-class/MenuPane.md` and `by-class/PopupMenuControlPane.md` with route markers and positions. Proof: `MenuPane` position `20`, `PopupMenuControlPane` position `21`, both emit accepted no-declaration markers plus `[[CHILDREN]]`; validators `000000002445`, `000000002446`.
- [x] Update `00011F` and `0001BK` with aggregate no-standalone markers; repair `0001BK` stale summary. Proof: both formal blocks emit aggregate markers plus `[[CHILDREN]]`; `0001BK` summary no longer says unassigned/84/80; validators `000000002454`, `000000002457`.
- [x] Update `0002YA` with scalar deleting destructor marker, score, and Item Summary repair. Proof: now `87/89`, marker added, summary filled with owned MenuPane cleanup proof; validator `000000002455`.
- [x] Update `by-type/by-vtable/MenuItemVtables.md` with no-raw-vtable marker and position. Proof: position `13`, formal no-raw-vtable marker plus `[[CHILDREN]]`; validator `000000002444`.
- [x] Update `by-file/PopupMenuControls.md` with the B008 empty-emitter-family change-log/status note while keeping metadata unchanged. Proof: B008 change entry added; metadata remains `86/85`, `CANONICAL_OWNER:FILE`, `NexusTK/ui/menu/`; validator `000000002458`.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`. Proof: 18 validators listed in `Callback Implementation And Validation`, all exit `0`, ok `1`.
- [x] Use `--wait-generated` for source-root/generator freshness and verify `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` refreshed. Proof: every validator used `--wait-generated`; final generated header is command `000000002458` at `2026-06-30T05:46:05-04:00`.
- [x] Confirm no manual generated files, coverage reports, validator state, IDA DB, executed archives, supervisor ledgers, or lock files were edited. Proof: only listed by-* docs and this B008 report were manually edited; generated freshness came from validator-owned refresh.
- [x] Release leases immediately after validation. Proof: release command reported no active leases for all accepted paths; lease report recheck showed no active B008 entries.
- [x] Update this report during callback with applied/already-present/excluded-with-reason/blocked ledger states and proof, validator command IDs/timestamps/exits/ok/warnings, generated freshness, changed files, and lease status. Proof: this callback section, ledger, and checklist are updated; no rows remain `proposed`.

Unchecked blockers: none.

## Callback Closure

The accepted implementation callback is complete. All accepted report details are incorporated into the target/support by-* docs at report-level detail, all changed by-* docs validated successfully with generated refresh, no manual generated/coverage/tool-state edits were made, and no B008 leases remain active.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000MN-PopupMenuControls-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000MN-PopupMenuControls-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T05:52:55","uid":"0000MN"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000MN-PopupMenuControls-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000MN-PopupMenuControls-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000MN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
