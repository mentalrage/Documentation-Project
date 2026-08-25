** TARGET-REPORT-UID:0002J5 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002J5/0002J9/0002JA/0002JC/0002JD/0002JF/0002JG Popup Menu Controls Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep the whole target family under the existing reusable popup-menu source root [UID:0000MN] `PopupMenuControls`, but route source-bearing methods through their actual direct classes instead of the file root where the class pages already clear the gate.
- Final disposition: no split is required for the assigned target pages. The executable ranges are already precise. The main repairs are source-quality naming, class-owner/emitter metadata, coverage text, and formal C++ policy.
- Required action: update metadata for `StringMenuItem` and `SeparatorMenuItem` target methods to class owners/emitters; keep `MenuItem` targets on `MenuItem`; add first-draft C++ to non-compiler-wrapper targets; keep scalar deleting-destructor target C++ blank with explicit compiler-wrapper proof.
- Confidence: high for target behavior, class ownership, vtable slot placement, and source-file grouping from existing IDA-backed docs; medium-high for final source spelling because live IDA MCP was unavailable in this session and the original names are inferred/descriptive.

## Supporting Research

## Target

- Target UID(s): `0002J5`, `0002J9`, `0002JA`, `0002JC`, `0002JD`, `0002JF`, `0002JG`.
- Target path(s):
  - `by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md`
  - `by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md`
  - `by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md`
  - `by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md`
  - `by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md`
  - `by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md`
  - `by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md`
- Source queue/report row: supervisor-assigned B003 goal 2 source-quality batch `B003-goal2-popup-menu-controls-source-quality-0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-20260617`.
- Current supervisor classification: report-only B-agent heuristic/source-quality and ownership-routing review.
- Current scores and parent state:

| UID | Current score | Current owner/emitter | Recommended owner/emitter | Score recommendation |
| --- | ---: | --- | --- | --- |
| `0002J5` | `82/90` | `00007V` / `00007V` | keep `00007V` / `00007V` | raise to `85/91` after source-name and C++ draft are recorded. |
| `0002J9` | `82/90` | `0000MN` / `0000MN` | `0000E8` / `0000E8` | raise to `86/91`. |
| `0002JA` | `84/88` | `0000MN` / `0000MN` | `0000E8` / `0000E8` | raise to `86/89`. |
| `0002JC` | `82/92` | `0000MN` / `0000MN` | `0000CY` / `0000CY` | raise to `86/92`. |
| `0002JD` | `82/92` | `0000MN` / `0000MN` | `0000CY` / `0000CY` | raise to `86/92`. |
| `0002JF` | `82/90` | `00007V` / `00007V` | keep `00007V` / `00007V` | keep `82/90` or at most `84/90` after no-code proof; do not treat wrapper C++ as handwritten source. |
| `0002JG` | `82/90` | `0000MN` / `0000MN` | `0000E8` / `0000E8` | raise to `84/90` after class routing and no-code proof. |

## Executive Recommendation

The best direct semantic owners are the concrete classes:

- `0002J5` and `0002JF` are `MenuItem` methods/glue and should remain direct children of [UID:00007V] `MenuItem`.
- `0002J9`, `0002JA`, and `0002JG` are `StringMenuItem` methods/glue and should route through [UID:0000E8] `StringMenuItem`, not directly through `PopupMenuControls`.
- `0002JC` and `0002JD` are `SeparatorMenuItem` virtual helpers and should route through [UID:0000CY] `SeparatorMenuItem`.

[UID:0000MN] `PopupMenuControls` remains the source-file root for all of those classes and currently clears `86/85`. The class pages also clear the gate: `MenuItem` is `86/88`, `StringMenuItem` is `88/90`, and `SeparatorMenuItem` is `86/90`. Therefore class-level routing satisfies the current by-structure direct-owner gate and still surfaces to `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`.

Do not create a new file. The existing `ui/menu/PopupMenuControls.cpp` grouping remains the strongest current source-file inference. A later source-tree pass may split `MenuItem.cpp`, `MenuPane.cpp`, or `PopupMenuControlPane.cpp`, but current docs and proposed-source-tree evidence support the consolidated file now.

## Supervisor Active Recheck

- The supervisor/user explicitly instructed B003 to create exactly one research report and not edit target by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md`.
- The assigned items do not require split repair. Each target is already an exact function/helper range with adjacent padding documented.
- Source-bearing children in this scope have sufficient evidence for direct class routing. The direct class parents and source-file root clear the assignment gate. The remaining source-quality issues are names/signatures, hidden-return/result types, and destructor-wrapper policy.

## Inference Research Guidance Check

`inference_research.md` and `by-structure.md` were applied as follows:

- Existing docs are treated as evidence, not authority. Several target pages already say the class owner in body text while the metadata still points to [UID:0000MN] `PopupMenuControls`; the report recommends the narrower class owner when class evidence and scores support it.
- IDA fact and documentation evidence are separated. Live IDA MCP could not be reached from this session, so IDA facts below are taken from existing by-* pages that record prior live IDA MCP sessions.
- Source names are inferred descriptively when original proof is unavailable. The report rejects `Flag1`, `sub_5170D0`, `dword_69B3FC`-style generated labels as final source names where contextual evidence supports stronger descriptive names.
- The current C++ gate is used: every target is reconstructable, has an emitter route, and has `(completion + confidence) / 2 > 85`. Therefore the report supplies first-draft C++ for source-authored method bodies and explicit no-code proof for compiler-generated deleting destructors.

## Heuristic / Inference Reanalysis And Validation

| Issue | Best defensible inference | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| `MenuItem +0x14` low state byte | `m_enabled` / `IsEnabled` / `SetEnabled` style source role. | `MenuItem` and `StringMenuItem` constructors write state word `1`; `SeparatorMenuItem` writes `0`; raw previous/next helpers test `item+0x14`; low-byte accessor/setter pages now score `85/91` and `85/90`. | Generic `stateFlag0`; selected/highlighted role; style flags. | Supports sibling naming and confirms `+0x15` is not the enabled byte. |
| `MenuItem +0x15` high state byte | `m_selected` or `m_highlighted`; prefer `m_selected` as semantic field with documentation alias "highlighted draw state." | `0002J5` reads byte `+0x15`; `0002JI` writes it; constructors seed high byte to zero; `StringMenuItem::DrawItem` branches on it before highlighted rendering. | Generic `stateFlag1`; enabled/interactable byte. | `0002J5` can receive a first-draft `MenuItem::IsSelected()` body. |
| `StringMenuItem +0x18` label field | inline `wchar_t m_text[0x80]`. | Constructor copies into `this+0x18` with `_wcscpy_s(..., 0x80, source)`; direct helper `0002J7`, virtual helper `0002J9`, measure helper `0002J8`, and draw helper `0002JA` all read the same field. | Heap label pointer; caller-owned label pointer; string object member. | Supports final C++ for `GetText` and `DrawItem`. |
| Bounds field | `MenuItemBounds` / rectangle `{left, top, right, bottom}` at `MenuItem +0x04`. | Constructors initialize through `InitRectBounds`; raw copy/set helpers use `movups` 16-byte copies; `MenuPane` writes item bounds; draw helpers read left/bottom/right/top. | Separate x/y/width/height field layout. | Supports draw C++ and source layout structure naming. |
| Size/result structure | `MenuItemMetrics { int height; int width; }`; the hidden/out result stores height first, width second. | `StringMenuItemMeasureText` writes `[0]=14`, `[1]=measuredWidth+24`; `SeparatorMenuItemGetDefaultDimensions` writes `[0]=6`, `[1]=20`. | Windows `SIZE {cx, cy}` ordering; two independent output integers with no structure. | Use `MenuItemMetrics`, not `SIZE`, in first-draft C++. |
| `0002J9` virtual name/signature | `errno_t StringMenuItem::GetText(wchar_t *destination, size_t sizeInWords) const`. | `_wcscpy_s(destination, sizeInWords, this+0x18)`, `retn 8`, vtable slot `StringMenuItem +0x10`, no mutation. | `GetString` or `CopyText` as final original spelling; direct helper owner. | Recommend class owner/emitter `0000E8` and first-draft C++. |
| `0002JA` virtual name/signature | `void StringMenuItem::DrawItem(GrafPort *port)` or `Draw` in the `MenuItem` interface. | Vtable slot `+0x14`; one explicit draw-context argument; calls GrafPort state/text helpers and selected fill callback. | Free drawing helper; Surface-owned callback method; feature-dialog local draw function. | Recommend class owner/emitter `0000E8` and first-draft C++ with provisional helper names. |
| `0002JC` result signature | Best source shape: `MenuItemMetrics SeparatorMenuItem::GetDefaultDimensions() const` or equivalent hidden-return UDT. | Body ignores `this`, writes caller-provided result buffer, returns with `retn 4`, consistent with MSVC hidden return pointer for small UDT or an explicit out param. | Primitive integer return; global constant table. | Recommend class owner/emitter `0000CY`; C++ draft uses UDT return. |
| `0002JD` style signature | Best source shape: `MenuItemStyleFlags SeparatorMenuItem::GetStyleFlags() const`, where `MenuItemStyleFlags` is a 16-bit UDT/wrapper. | Body writes 16-bit zero to caller-provided result pointer and uses `retn 4`, matching hidden return or out-param behavior rather than primitive `uint16_t` in `AX`. | Primitive `uint16_t GetStyleFlags()` as final binary-shape match; generic flag setter. | Recommend class owner/emitter `0000CY`; C++ draft uses a 16-bit UDT to preserve hidden-return plausibility. |
| Separator vtable tension | `SeparatorMenuItem` has draw at `+0x14` and extra fixed-dimension/style slots at `+0x18/+0x1c`; `+0x0c/+0x10` are documented as `__purecall`. | `MenuItemVtables`, `MenuItemVtableData`, `SeparatorMenuItem`, `0002JC`, `0002JD`, and `MenuPaneRecomputeItemBoundsRaw` docs. | Claiming separator implements the same `+0x0c` metric slot as `StringMenuItem`; treating current evidence as proof of final interface shape. | Must be documented as a remaining source-interface caveat. It does not block class ownership of `0002JC/0002JD`, but it should cap scores below final-audit and warrants a future live MCP call-site audit. |
| Destructor wrappers | `0002JF` and `0002JG` are MSVC scalar deleting destructors generated from ordinary virtual destructors and object sizes. | Wrappers reset base vtable, call `0x004f4a90`, conditionally call `0x004f4ac0`, include flag-4 path through `0x0041b6a0`; `0002JG` uses object size `0x118`; `0002JF` is reused by `MenuItem` and `SeparatorMenuItem` vtable slots. | Handwritten source method named `ScalarDeletingDestructor`; emitting wrapper C++ in target pages. | Keep formal target C++ blank; put ordinary destructor declarations/bodies on class pages or class-level draft source, letting MSVC regenerate wrappers. |
| Source placement | Existing `NexusTK/ui/menu/PopupMenuControls.cpp` remains best source root. | `PopupMenuControls` file page, proposed source tree, `MenuPaneAndItems`, class pages, vtable/layout pages, adjacent `MenuDialogFactoryHelpers` boundary. | New standalone `MenuItem.cpp`; `ui/controls/PopupMenuControls.cpp`; feature-menu owners such as `RightButtonMenuPane` or dialog files. | No new file recommended. Current generated file is `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` and is length `0` because formal C++ blocks are blank. |
| Generated-output pollution | Target rows route to a valid file but output file is empty. | `auto-generated/-ag-memory-coverage.md` rows show emitted route; filesystem shows `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` length `0`. | Treating "emits" rows as proof C++ already exists. | Adds urgency to populate first-draft C++ for source-authored methods and no-code proof for wrappers. |

Remaining blocker: live IDA MCP was unavailable, so I could not re-run `lookup_funcs`, `xrefs_to`, or decompilation for the separator interface tension. Existing pages record enough prior IDA evidence for ownership and behavior, but final interface spelling should remain below `95`.

## Evidence Standards Used

- Documentation evidence: current by-memory target pages, [UID:0001BK] `MenuPaneAndItems`, [UID:0000MN] `PopupMenuControls`, [UID:00007V] `MenuItem`, [UID:0000E8] `StringMenuItem`, [UID:0000CY] `SeparatorMenuItem`, [UID:0001V5] `MenuItemLayouts`, [UID:0001Y4] `MenuItemVtables`, [UID:00036I] `MenuItemVtableData`, GrafPort/Surface dependency pages, coverage reports, and proposed source tree.
- Existing IDA-backed facts: prior recorded `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `callers`, `callees`, byte reads, and vtable dword reads from the target/support docs.
- Negative evidence: no live MCP listener on `127.0.0.1:13337`; current generated `PopupMenuControls.cpp` has length `0`; target method direct callers are absent or vtable-only in existing docs.
- No Wave3/simroot source bodies were used as authority. Generated reports were used only for current routing/coverage state.

## IDA MCP Facts

Live IDA MCP status for this B003 session:

- `Invoke-WebRequest` to `http://127.0.0.1:13337/mcp` for `initialize` failed with "Unable to connect to the remote server".
- A retry using `tools/list` also failed.
- `http://127.0.0.1:13337/config.html` also failed.
- `Get-NetTCPConnection -LocalPort 13337` returned no listener.

IDA facts used below are therefore not new session facts; they are prior recorded facts from current by-* documents:

- Function/range facts: `0002J5` is `0x00516f90-0x00516f94`; `0002J9` is `0x005170d0-0x005170e9`; `0002JA` is `0x005170f0-0x005171a2`; `0002JC` is `0x00517220-0x00517237`; `0002JD` is `0x00517240-0x0051724f`; `0002JF` is `0x005172e0-0x0051731e`; `0002JG` is `0x00517400-0x00517441`.
- Data/table facts: `StringMenuItem` vtable base `0x0061ebb4`, `SeparatorMenuItem` vtable base `0x0061ebd0`, `MenuItem` vtable base `0x0061eb98`. Exact `.rdata` vtable child is `0x0061eb94-0x0061ebf0`.
- Xref facts: `0002J9` data xref from `0x0061ebc4`; `0002JA` from `0x0061ebc8`; `0002JC` from `0x0061ebe8`; `0002JD` from `0x0061ebec`; `0002JF` from `0x0061eb98` and `0x0061ebd0`; `0002JG` from `0x0061ebb4`; `0002J5` has no direct xrefs or pointer hits in recorded checks.
- Vtable/global/type facts: `MenuItemLayouts` documents `+0x04` bounds, `+0x14` state low byte, `+0x15` state high byte, and `StringMenuItem +0x18` label buffer.
- Negative IDA facts: target virtuals generally have no direct code callers because calls go through vtables; raw state/bounds sibling helper starts have no modeled function objects or pointer hits in existing docs.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00516f90-0x00516f94` | `0002J5` | `MenuItem` selected/highlighted accessor | true | `00007V` | `85/91` | populate first-draft C++. |
| `0x005170d0-0x005170e9` | `0002J9` | `StringMenuItem` virtual text copy | true | `0000E8` | `86/91` | reroute from file root, populate first-draft C++. |
| `0x005170f0-0x005171a2` | `0002JA` | `StringMenuItem` virtual draw method | true | `0000E8` | `86/89` | reroute from file root, populate first-draft C++. |
| `0x00517220-0x00517237` | `0002JC` | `SeparatorMenuItem` fixed metrics | true | `0000CY` | `86/92` | reroute from file root, populate first-draft C++. |
| `0x00517240-0x0051724f` | `0002JD` | `SeparatorMenuItem` style flags | true | `0000CY` | `86/92` | reroute from file root, populate first-draft C++. |
| `0x005172e0-0x0051731e` | `0002JF` | `MenuItem` scalar deleting destructor wrapper | true/source-declared compiler output | `00007V` | keep `82/90`, optional `84/90` after no-code proof | formal target C++ should remain blank. |
| `0x00517400-0x00517441` | `0002JG` | `StringMenuItem` scalar deleting destructor wrapper | true/source-declared compiler output | `0000E8` | `84/90` | reroute from file root; formal target C++ should remain blank. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061eb98` | `MenuItem` vtable slot `+0x00` to `0x005172e0` | `0002JF` is base deleting destructor entry. |
| `0x0061ebb4` | `StringMenuItem` vtable slot `+0x00` to `0x00517400` | `0002JG` is string deleting destructor entry. |
| `0x0061ebc4` | `StringMenuItem` vtable slot `+0x10` to `0x005170d0` | `0002J9` is virtual text-copy/get-text slot. |
| `0x0061ebc8` | `StringMenuItem` vtable slot `+0x14` to `0x005170f0` | `0002JA` is virtual draw slot. |
| `0x0061ebd0` | `SeparatorMenuItem` vtable slot `+0x00` to `0x005172e0` | separator reuses `MenuItem` deleting destructor wrapper. |
| `0x0061ebe8` | `SeparatorMenuItem` vtable slot `+0x18` to `0x00517220` | `0002JC` fixed dimensions slot. |
| `0x0061ebec` | `SeparatorMenuItem` vtable slot `+0x1c` to `0x00517240` | `0002JD` style flags slot. |
| `0x004b9600`, `0x004b9660`, `0x004b9680`, `0x004bab70` | callees from `0002JA` | shared `GrafPort` draw-state/text helpers, not menu-owned helpers. |
| `0x0069b3fc` / `dword_69B3FC` | indirect callback from `0002JA` selected path | shared Surface render callback slot, not a popup-menu global. |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:0000MN] `PopupMenuControls` is `86/85`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`, and lists `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, `MenuPane`, `PopupMenuControlPane`, vtables, layouts, and the popup selection callback as proposed contents.
- [UID:00007V] `MenuItem` is `86/88` and maps the base constructor/accessors/raw helpers/destructor to `MenuItem`, with `PopupMenuControls` as source file.
- [UID:0000E8] `StringMenuItem` is `88/90` and maps constructor/copy/measure/get-text/draw/destructor pages to the class.
- [UID:0000CY] `SeparatorMenuItem` is `86/90` and maps constructor/dimensions/style/draw pages to the class.
- [UID:0001V5] `MenuItemLayouts` is `85/89` and documents the exact field offsets.
- [UID:0001Y4] `MenuItemVtables` is `86/91` and documents the vtable slots.
- [UID:00036I] `MenuItemVtableData` is `86/91` and documents every vtable dword plus COL pointers.

Existing docs that are stale, incomplete, or contradicted:

- `0002J9`, `0002JA`, `0002JC`, `0002JD`, and `0002JG` body text already says the class owner, but metadata still uses `CANONICAL_OWNER:0000MN` and `EMITTER_UIDS:0000MN`. This is overbroad now that the class pages clear the gate.
- Several pages still cite older `95/95` C++ policy language. Current policy allows first-draft C++ when reconstructable, emitted, and average score is greater than `85`, but the code must still be source-quality.
- `by-memory/-coverage-report.md` descriptions still say "PopupMenuControls parent" for target rows that should now route through class parents.
- The generated output path specified in the prompt as `auto-generated/NexusTK/ui/controls/PopupMenuControls.cpp` is not the current file path. Current generated route is `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp`, and that file currently has length `0`.

Generated/coverage report state:

- `auto-generated/-ag-memory-coverage.md` shows all target rows as `emits`, but no C++ is emitted because their formal code blocks are blank.
- Current `auto-generated/NexusTK/ui/menu/PopupMenuControls.cpp` length is `0`.

## Ranked Ownership Analysis

### 1. Direct class owner with PopupMenuControls source root

- Evidence for: class pages clear the gate; vtable slots and constructor/destructor vptr writes prove method ownership; layout pages tie fields to the class family; the source-file page owns the family and clears the gate.
- Evidence against: exact original source split could later become `MenuItem.cpp`/`MenuPane.cpp`/`PopupMenuControlPane.cpp`; original method names are inferred.
- Decision: accepted. This is the best current ownership model.

### 2. Direct file owner `PopupMenuControls`

- Evidence for: current file page owns the whole source family and routes to a valid generated file root.
- Evidence against: by-structure says canonical owner should be the narrowest direct semantic owner. `StringMenuItem` and `SeparatorMenuItem` class pages now clear the gate, so the file root is too broad for method-level targets.
- Decision: keep as source-file root only; reject as direct owner for `0002J9`, `0002JA`, `0002JC`, `0002JD`, and `0002JG`.

### 3. New `MenuItem.cpp` / `MenuItem.h` owner

- Evidence for: all menu item classes form a tight source family; class-specific routing could later justify a file split.
- Evidence against: proposed source tree and current by-file evidence use the consolidated `PopupMenuControls.cpp`; `PopupMenuControlPane`/`MenuPane`/items have strong cross-construction relationships; no direct source metadata proves a split.
- Decision: rejected for this pass. Record as future source-tree caveat only.

### 4. Feature-menu/dialog owners

- Evidence for: `StringMenuItem` constructor has many feature/dialog callers.
- Evidence against: broad constructor fan-in proves reuse, not feature ownership. Vtables/layouts/source family are generic popup-menu controls.
- Decision: rejected.

### 5. GrafPort or Surface owners for draw helpers

- Evidence for: draw methods call GrafPort and Surface helpers.
- Evidence against: those are dependencies. Receiver and vtable slots are `StringMenuItem`/`SeparatorMenuItem`; helper pages already own GrafPort/Surface dependencies separately.
- Decision: rejected as target owners.

## Proposed Source/File Grouping

- Proposed owner/name/path: keep [UID:0000MN] `PopupMenuControls`, generated as `NexusTK/ui/menu/PopupMenuControls.cpp`.
- Likely full contents: `PopupMenuControlPane`, `MenuPane`, `MenuItem`, `StringMenuItem`, `SeparatorMenuItem`, popup selection callback consumer side, menu item layout declarations, and menu item vtable declarations/source effects.
- Candidate related items that belong:
  - [UID:00011F] `PopupMenuControlPaneCore`
  - [UID:0001BK] `MenuPaneAndItems`
  - [UID:00007W] `MenuPane`
  - [UID:00007V] `MenuItem`
  - [UID:0000E8] `StringMenuItem`
  - [UID:0000CY] `SeparatorMenuItem`
  - [UID:0001V5] `MenuItemLayouts`
  - [UID:0001Y4] `MenuItemVtables`
  - [UID:00036I] `MenuItemVtableData`
- Candidate related items rejected:
  - [UID:000238] `MenuDialogFactoryHelpers`: begins after padding at `0x00517450` and is a merchant/dialog factory island.
  - `RightButtonMenuPane`, `VoteMenuPane`, `MenuVarietyPanes`: related UI/menu idioms but feature-specific source files.
  - `GrafPort` and `Surface` helpers: draw dependencies, not popup-menu owners.
- Standalone, narrow, or broad source-file inference: broad but coherent small framework file. Current evidence does not justify creating a new file.

## Negative Evidence Summary

- Live IDA MCP was unavailable; no fresh disassembly could be added.
- No direct code callers are recorded for most virtual targets. This is expected for vtable-dispatched methods and does not imply dead code.
- No direct xrefs or pointer hits are recorded for `0002J5`; it remains a source-shaped accessor paired with a setter and a downstream draw read.
- `SeparatorMenuItem` constructor and extra slots have weak direct caller evidence. This does not block class ownership of the documented vtable slots, but it does keep final interface confidence below final-audit level.
- The current generated output is empty, so "emits" coverage rows do not prove code is present.

## First-Draft C++ Recommendation

These drafts are intended for the target pages that are source-authored methods. The names are inferred/descriptive, not proven original spellings. The surrounding declarations should live with the `MenuItem` class family, most likely in the popup menu controls source/header pair.

```cpp
struct MenuItemBounds {
    int left;
    int top;
    int right;
    int bottom;
};

struct MenuItemMetrics {
    int height;
    int width;
};

struct MenuItemStyleFlags {
    unsigned short bits;
};

bool MenuItem::IsSelected() const
{
    return m_selected != 0;
}

errno_t StringMenuItem::GetText(wchar_t* destination, size_t sizeInWords) const
{
    return wcscpy_s(destination, sizeInWords, m_text);
}

void StringMenuItem::DrawItem(GrafPort* port)
{
    port->m_textRunDirty = true;

    if (IsSelected()) {
        port->SetTextColor(0x80);
        g_surfaceRenderCallbacks.fillOrInvalidate(port, &m_bounds);
        port->SetBackgroundColor(0x8f);
    } else {
        port->SetBackgroundColor(0x80);
    }

    port->MoveTo(m_bounds.left + 12, m_bounds.bottom - 1);
    port->DrawWideText(m_text, static_cast<int>(wcslen(m_text)));
}

MenuItemMetrics SeparatorMenuItem::GetDefaultDimensions() const
{
    MenuItemMetrics metrics = { 6, 20 };
    return metrics;
}

MenuItemStyleFlags SeparatorMenuItem::GetStyleFlags() const
{
    MenuItemStyleFlags flags = { 0 };
    return flags;
}
```

Per-target C++ policy:

- `0002J5`: populate formal C++ with the `MenuItem::IsSelected()` body after the page records that `m_selected` is inferred from draw-state use. If the supervisor prefers `IsHighlighted`, use that name consistently with `0002JI`.
- `0002J9`: populate formal C++ with `StringMenuItem::GetText`.
- `0002JA`: populate formal C++ with `StringMenuItem::DrawItem`, but keep helper names marked inferred/descriptive until GrafPort/Surface callback names are final.
- `0002JC`: populate formal C++ with `SeparatorMenuItem::GetDefaultDimensions`. `MenuItemMetrics` is deliberately not Win32 `SIZE` because observed order is height then width.
- `0002JD`: populate formal C++ with `SeparatorMenuItem::GetStyleFlags` using a 16-bit wrapper struct. Do not convert it to a primitive `unsigned short` unless a later ABI check proves the original source returned a primitive.
- `0002JF`: do not populate target formal C++. Source-level class draft should declare/define an ordinary virtual destructor, for example `MenuItem::~MenuItem() {}` or `virtual ~MenuItem() {}` in the class declaration. The scalar deleting destructor wrapper itself is compiler-generated.
- `0002JG`: do not populate target formal C++. Source-level class draft should declare/define `StringMenuItem::~StringMenuItem() {}` or default it. The wrapper is compiler-generated and no label cleanup is needed because `m_text` is inline.

## Destructor Wrapper Versus Ordinary Source Destructor Policy

`0002JF` and `0002JG` should remain reconstructable because the rebuilt binary needs equivalent vtable/destructor semantics, but the formal by-memory C++ blocks for these exact ranges should remain blank. The source-level C++ should express ordinary destructors on the classes. MSVC will regenerate scalar deleting destructors with flag checks, object-size paths, vtable resets, base destructor calls, and conditional deletes.

Reasons:

- The target ranges are vtable entries for compiler deleting-destructor wrappers, not human-authored functions named `ScalarDeletingDestructor`.
- The wrappers call allocator/runtime helpers and contain scalar-delete flag handling. Handwriting those in final source would be decompiler-shaped and would duplicate compiler responsibility.
- `0002JF` is shared by `MenuItem` and `SeparatorMenuItem`; source should not duplicate a separate `SeparatorMenuItem` deleting destructor if it inherits the base destructor wrapper.
- `0002JG` only differs by `StringMenuItem` object size `0x118`; its source destructor can be empty/default because the inline label buffer needs no explicit cleanup.

## Final Recommendation

- Update `0002J5` to score `85/91`, keep `CANONICAL_OWNER:00007V`, keep `EMITTER_UIDS:00007V`, and add first-draft accessor C++.
- Update `0002J9` to score `86/91`, set `CANONICAL_OWNER:0000E8`, set `EMITTER_UIDS:0000E8`, and add first-draft text-copy C++.
- Update `0002JA` to score `86/89`, set `CANONICAL_OWNER:0000E8`, set `EMITTER_UIDS:0000E8`, and add first-draft draw C++.
- Update `0002JC` to score `86/92`, set `CANONICAL_OWNER:0000CY`, set `EMITTER_UIDS:0000CY`, and add first-draft metrics C++.
- Update `0002JD` to score `86/92`, set `CANONICAL_OWNER:0000CY`, set `EMITTER_UIDS:0000CY`, and add first-draft style-flags C++.
- Keep `0002JF` direct owner/emitter `00007V`; add destructor-wrapper no-code proof; do not populate target C++.
- Update `0002JG` to score `84/90`, set `CANONICAL_OWNER:0000E8`, set `EMITTER_UIDS:0000E8`, add destructor-wrapper no-code proof, and do not populate target C++.
- Recommended support metadata cleanup outside the primary targets: reroute adjacent `StringMenuItem` pages `0002J6`, `0002J7`, and `0002J8` from direct file owner/emitter `0000MN` to class owner/emitter `0000E8`; reroute adjacent `SeparatorMenuItem` pages `0002JB` and `0002JE` to class owner/emitter `0000CY`.

## Supervisor-Owned Coverage Row Updates

Placement context: replace the existing rows inside the `0x00516290-0x00517441.MenuPaneAndItems` nested region of `source-3/project-documentation/by-memory/-coverage-report.md`, preserving low-to-high address order.

Replacement rows:

```text
        - [UID:0002J5][0x00516f90-0x00516f94.MenuItemStateFlag1Accessor](by-memory/0x00516f90-0x00516f94.MenuItemStateFlag1Accessor.md) 0x00516f90-0x00516f94 | method | MenuItemStateFlag1Accessor : reconstructable : 85% : very-strong : Prior IDA evidence reconfirms exact four-byte accessor returning MenuItem state byte +0x15, modeled function sub_516F90 size 0x04, direct return-this[21] decompilation, no xrefs or little-endian pointer hits, exact padding, paired setter/constructor state-word evidence, StringMenuItem draw-path read, direct MenuItem class parent/emitter, and inferred `IsSelected`/highlighted-state first-draft C++ with original spelling still provisional.
        - [UID:0002J9][0x005170d0-0x005170e9.StringMenuItemGetText](by-memory/0x005170d0-0x005170e9.StringMenuItemGetText.md) 0x005170d0-0x005170e9 | method | StringMenuItemGetText : reconstructable : 86% : very-strong : Prior IDA evidence reconfirms exact 0x19 vtable text-copy helper, `_wcscpy_s` callee, inline `StringMenuItem +0x18` label source, stack `Destination`/`SizeInWords` contract, StringMenuItem vtable slot `0x0061ebc4`, no direct code callers, trailing alignment, direct StringMenuItem class parent/emitter with PopupMenuControls source root, and source-quality `GetText` first-draft C++.
        - [UID:0002JA][0x005170f0-0x005171a2.StringMenuItemDrawItem](by-memory/0x005170f0-0x005171a2.StringMenuItemDrawItem.md) 0x005170f0-0x005171a2 | method | StringMenuItemDrawItem : reconstructable : 86% : strong : Prior IDA evidence reconfirms exact 0xb2 vtable draw method, selected/normal branch split on StringMenuItem/MenuItem +0x15, draw-context byte +0x88 write, bounds-based cursor at left+12/bottom-1, inline `StringMenuItem +0x18` UTF-16 label scan, shared GrafPort draw-state/text helpers, `dword_69B3FC` selected-branch render callback, StringMenuItem vtable slot `0x0061ebc8`, no direct code callers, direct StringMenuItem class parent/emitter with PopupMenuControls source root, and first-draft C++ with GrafPort/Surface helper names still inferred.
        - [UID:0002JC][0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions](by-memory/0x00517220-0x00517237.SeparatorMenuItemGetDefaultDimensions.md) 0x00517220-0x00517237 | method | SeparatorMenuItemGetDefaultDimensions : reconstructable : 86% : very-strong : Prior IDA evidence reconfirms exact 0x17 vtable fixed-dimensions method, no object-state reads, hidden/out result dword[0]=6 and dword[1]=20, no callees, no direct code callers, SeparatorMenuItem vtable slot `0x0061ebe8`, surrounding padding, direct SeparatorMenuItem class parent/emitter with PopupMenuControls source root, and first-draft `MenuItemMetrics` C++ while final separator interface call-site shape remains below final-audit.
        - [UID:0002JD][0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags](by-memory/0x00517240-0x0051724f.SeparatorMenuItemGetStyleFlags.md) 0x00517240-0x0051724f | method | SeparatorMenuItemGetStyleFlags : reconstructable : 86% : very-strong : Prior IDA evidence reconfirms exact 0x0f vtable style-flags method, no object-state reads, zero 16-bit style/flag hidden/out result write, no callees, no direct code callers, SeparatorMenuItem vtable slot `0x0061ebec`, surrounding padding, direct SeparatorMenuItem class parent/emitter with PopupMenuControls source root, and first-draft 16-bit `MenuItemStyleFlags` C++ while final primitive-vs-UDT result spelling remains provisional.
        - [UID:0002JF][0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor](by-memory/0x005172e0-0x0051731e.MenuItemScalarDeletingDestructor.md) 0x005172e0-0x0051731e | compiler-generated destructor wrapper | MenuItemScalarDeletingDestructor : reconstructable : 82% : strong : Prior IDA evidence reconfirms exact 0x3e MenuItem scalar deleting destructor wrapper, base vtable reset at 0x005172e6, cleanup/delete callees, flag-4 helper path, vtable slot xrefs from MenuItem and SeparatorMenuItem, no direct code callers, exact padding, direct MenuItem class parent/emitter with PopupMenuControls source root, and explicit no-formal-C++ policy because the source should declare an ordinary virtual destructor and let MSVC regenerate this wrapper.
        - [UID:0002JG][0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor](by-memory/0x00517400-0x00517441.StringMenuItemScalarDeletingDestructor.md) 0x00517400-0x00517441 | compiler-generated destructor wrapper | StringMenuItemScalarDeletingDestructor : reconstructable : 84% : strong : Prior IDA evidence reconfirms exact 0x41 StringMenuItem scalar deleting destructor wrapper, base vtable reset at 0x00517406, cleanup/delete callees, flag-4 helper path with 0x118 size, StringMenuItem vtable slot xref, no direct callers, inline-label no-extra-cleanup context, exact padding before MenuDialogFactoryHelpers, direct StringMenuItem class parent/emitter with PopupMenuControls source root, and explicit no-formal-C++ policy because the source should declare an ordinary/default StringMenuItem destructor and let MSVC regenerate this wrapper.
```

## Follow-Up Actions

- Supervisor actions:
  - Apply the metadata, scores, source-quality notes, C++ drafts, and no-code proofs to the target by-memory pages.
  - Apply the coverage-row replacements above because agents are currently banned from editing `by-memory/-coverage-report.md`.
  - Run targeted validator scans for edited by-memory pages and autogen refresh afterward.
- A-agent actions:
  - Apply the same class-routing cleanup to adjacent support pages `0002J6`, `0002J7`, `0002J8`, `0002JB`, and `0002JE` if assigned.
  - Update class pages to include the inferred layout/member names and destructor-wrapper policy if not already present.
- B003 future research actions:
  - When IDA MCP is available, re-audit `MenuPaneRecomputeItemBoundsRaw` and separator vtable call sites to resolve why `SeparatorMenuItem` leaves `+0x0c/+0x10` pure while adding `+0x18/+0x1c`.
  - Run a focused signature/name pass over `dword_69B3FC` and draw-context bytes `+0x70/+0x88` for better final C++ helper names.

## Confidence

- Recommendation confidence: high for class owner/emitter changes and source-file root; medium-high for exact source-facing method names.
- Score confidence: high for the proposed modest score increases on source-authored leaf methods; medium for destructor wrapper score increases because no formal C++ should be populated on those exact target ranges.
- Remaining uncertainty: exact original names, separator extra-slot interface shape, and GrafPort/Surface callback final API names.

## Validator Results

- Commands run: none.
- Results: not applicable; this assignment is report-only and no validator-managed by-* docs were edited.
- Unresolved validator warnings/errors: not checked.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-popup-menu-controls-source-quality.md`
- Modified: none.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002J5-0002J9-0002JA-0002JC-0002JD-0002JF-0002JG-popup-menu-controls-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002J5"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
