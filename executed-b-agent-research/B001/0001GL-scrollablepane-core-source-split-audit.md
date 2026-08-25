** TARGET-REPORT-UID:0001GL **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-scrollablepane-core-source-split-0001GL-20260616

## Target

- Target: [UID:0001GL] `by-memory/0x0055e660-0x0055f242.ScrollablePaneCore.md`
- Current score/route: `82/86`, `CANONICAL_OWNER:0000NF`, `EMITTER_UIDS:0000NF`
- Assignment: report-only B-agent source-structure/source-quality audit for `ScrollablePaneCore`.
- Evidence used: current target page, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, [UID:0001GJ] `TextEditPaneScrollbarVariants`, [UID:0001H6] `ScrollablePaneVirtualDefaults`, [UID:0000CF] `ScrollablePane`, [UID:0000NF] `ScrollBar`, [UID:0000CE]/[UID:0000NE] `ScrollableControlPane`, [UID:00026D]/[UID:0003CL]/[UID:0003CQ] read-only data pages, live IDA MCP session `701e9f0c`, and raw PE scans of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

No by-* documentation, generated report, IDA DB, or coverage report was edited.

## Executive Recommendation

Do not create new child pages for this pass. The current problem is not mixed ownership inside `0x0055e660-0x0055f44f`; it is a stale/incomplete `0001GL` range and function inventory.

Recommended supervisor action:

1. Rename and expand [UID:0001GL] from `by-memory/0x0055e660-0x0055f242.ScrollablePaneCore.md` to `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`.
2. Keep UID `0001GL`; no new UID allocation is needed for the recommended no-split repair.
3. Change direct owner/emitter from file [UID:0000NF] `ScrollBar` to class [UID:0000CF] `ScrollablePane`.
4. Raise target to `87/90`.
5. Add one ignored padding row for `0x0055f44f-0x0055f450`.
6. Do not ignore internal raw helpers at `0x0055e8a0`, `0x0055e8d0`, or `0x0055edf0`; they are real reachable code or real class helper code.

Reason: live IDA and raw PE evidence show a coherent `ScrollablePane` class cluster from `0x0055e660` through `0x0055f44f`. The current page omits six modeled functions, three raw helper bodies, and the internal helper `0x0055f250-0x0055f44f`. All belong to `ScrollablePane`; the next unrelated feature pane starts at `0x0055f450`.

## Live IDA Facts

- IDA MCP `server_health` reports `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- IDA MCP `entity_query` over `0x0055e600-0x0055f460` reports these modeled functions:

| Range | IDA name | Classification | Source role |
| --- | --- | --- | --- |
| `0x0055e660-0x0055e77e` | `sub_55E660` | modeled | `ScrollablePane` constructor. Calls base `Pane` constructor, installs three `ScrollablePane` vtables, creates `ScrollPane(1)` at `+0xf8` and `ScrollPane(0)` at `+0xfc`, initializes rects at `+0x110` and `+0x120`. |
| `0x0055e780-0x0055e7d9` | `sub_55E780` | modeled | Non-deleting destructor/cleanup body. Resets vtables, deletes owned scrollbars at `+0xf8/+0xfc`, then chains base teardown. This was missing from the current `0001GL` table. |
| `0x0055e7e0-0x0055e83c` | `sub_55E7E0` | modeled | Propagates a word state/range value to both scrollbar children at child offset `+0xf8`, with notify callback. |
| `0x0055e840-0x0055e897` | `sub_55E840` | modeled | Propagates a byte visibility/enabled state to both scrollbar children at child offset `+0xfa`, with notify callback. |
| `0x0055e8a0-0x0055e8c7` | raw body | unmodeled code | Selects horizontal or vertical child and calls `ScrollWidget::SetScrollTargetValue` (`0x0055c310`). Reached by a `ScrollableControlPane` wrapper thunk at `0x004986aa`. |
| `0x0055e8d0-0x0055e90c` | raw body | unmodeled code | Selects horizontal or vertical child, updates child offset `+0xfe`, and fires callback slot `+0x20`. Reached by a `ScrollableControlPane` wrapper thunk at `0x004986ba`. |
| `0x0055e910-0x0055e949` | `sub_55E910` | modeled | Reads selected child word at `+0x100`; 27 IDA xrefs and one `ScrollableControlPane` wrapper jump. |
| `0x0055e950-0x0055e989` | `sub_55E950` | modeled | Reads selected child word at `+0xfe`; 52 IDA xrefs and one `ScrollableControlPane` wrapper jump. |
| `0x0055e990-0x0055ead5` | `sub_55E990` | modeled | Synchronizes both child scroll target/current values from `ScrollablePane` virtual slots `+0x48/+0x4c`, clamps to `0..30000`, calls `0x0055c310`, and calls internal helper `0x0055f250`. |
| `0x0055eae0-0x0055ec00` | `sub_55EAE0` | modeled | Applies scroll movement for one axis, updates child current state, recomputes/clips rect state, and refreshes rendering. |
| `0x0055ec00-0x0055edeb` | `sub_55EC00` | modeled | Layout/update-bounds virtual. Uses `byte_66DA97` and scrollbar constant tables, sets child bounds, updates `+0x110`, then calls `0x0055f250` and `0x0055e990`. |
| `0x0055edf0-0x0055ee04` | raw body | unmodeled code | Copies the 16-byte rect at `this+0x110` to an output pointer. No xrefs in IDA; source-shaped `ScrollablePane` getter body, not padding. |
| `0x0055ee10-0x0055ef08` | `sub_55EE10` | modeled | Layer/add or move/attach virtual. Calls base helper `0x00544c70`, adjusts child positions, then delegates child virtual slots `+0x28/+0x30`. |
| `0x0055ef10-0x0055ef43` | `sub_55EF10` | modeled | Remove/detach virtual. Calls child virtual slot `+0x38` for enabled bars, then base `0x00544ce0`. |
| `0x0055ef50-0x0055f0ca` | `sub_55EF50` | modeled | Input dispatch virtual. Lets child scrollbars process input first; mouse-wheel path over content rect calls `0x0055eae0`; fallback dispatches to owner/base virtual slot `+0x60`. |
| `0x0055f0d0-0x0055f128` | `sub_55F0D0` | modeled | Key-down style virtual. Gives child scrollbar panes first chance, then falls back to owner/base slot `+0x64`. |
| `0x0055f130-0x0055f188` | `sub_55F130` | modeled | Key-up style virtual. Gives child scrollbar panes first chance, then falls back to owner/base slot `+0x68`. |
| `0x0055f190-0x0055f243` | `sub_55F190` | modeled | Update scroll region/hook virtual. Builds temporary rect/region state from `+0x110`, calls virtual slot `+0x6c`, and restores temporary objects. The current page is one byte short here. |
| `0x0055f250-0x0055f44f` | `sub_55F250` | modeled | Internal viewport/content rect recompute helper. Called only from `0x0055e990` and `0x0055ec00`; updates `+0x120` based on `+0x110`, content size virtual `+0x58`, scroll offsets, and `byte_66DA97`. |
| `0x0055f450-0x0055f4f1` | `sub_55F450` | modeled successor | First `ScrollSpellInventoryPane` function. This is the correct next non-`ScrollablePane` boundary. |

The current target table only lists nine functions and stops at `0x0055f242`. The correct source cluster is `0x0055e660-0x0055f44f`.

## Byte And Gap Audit

Live IDA MCP `get_bytes`/`insn_query` and raw PE reads agree on the following internal layout. Padding ranges are safe compiler/linker alignment only; raw helper ranges are code and must not be ignored.

| Range | Bytes / disassembly evidence | Classification |
| --- | --- | --- |
| `0x0055e65c-0x0055e660` | four `0xcc`; already recorded in `-ignored.md` as prior `ScrollPaneInputGeometryHelpers` to `ScrollablePane` padding | Existing safe padding before target |
| `0x0055e77e-0x0055e780` | `cc cc` | Padding inside aggregate |
| `0x0055e7d9-0x0055e7e0` | seven `0xcc` | Padding inside aggregate |
| `0x0055e83c-0x0055e840` | four `0xcc` | Padding inside aggregate |
| `0x0055e897-0x0055e8a0` | nine `0xcc` | Padding before raw helper |
| `0x0055e8a0-0x0055e8c7` | `push ebp; mov ebp, esp; ... call sub_55C310; pop ebp; retn 8` | Raw `ScrollablePane` helper, reachable |
| `0x0055e8c7-0x0055e8d0` | nine `0xcc` | Padding between raw helpers |
| `0x0055e8d0-0x0055e90c` | `push ebp; ... mov [ecx+0feh], ax; ... call dword ptr [edx+20h]; retn 8` | Raw `ScrollablePane` helper, reachable |
| `0x0055e90c-0x0055e910` | four `0xcc` | Padding before getter |
| `0x0055e949-0x0055e950` | seven `0xcc` | Padding |
| `0x0055e989-0x0055e990` | seven `0xcc` | Padding |
| `0x0055ead5-0x0055eae0` | eleven `0xcc` | Padding |
| `0x0055edeb-0x0055edf0` | five `0xcc` | Padding before raw getter |
| `0x0055edf0-0x0055ee04` | `push ebp; mov ebp, esp; mov eax, [ebp+8]; movups xmm0, [ecx+110h]; movups [eax], xmm0; pop ebp; retn 4` | Raw `ScrollablePane` rect-copy helper |
| `0x0055ee04-0x0055ee10` | twelve `0xcc` | Padding after raw getter |
| `0x0055ef08-0x0055ef10` | eight `0xcc` | Padding |
| `0x0055ef43-0x0055ef50` | thirteen `0xcc` | Padding |
| `0x0055f0ca-0x0055f0d0` | six `0xcc` | Padding |
| `0x0055f128-0x0055f130` | eight `0xcc` | Padding |
| `0x0055f188-0x0055f190` | eight `0xcc` | Padding |
| `0x0055f243-0x0055f250` | thirteen `0xcc` | Padding after corrected `sub_55F190` end; current page is one byte short |
| `0x0055f44f-0x0055f450` | one `0xcc` | Boundary padding before `ScrollSpellInventoryPane`; add ignored row |

Only the final boundary `0x0055f44f-0x0055f450` needs a shared ignored row under the no-split recommendation. Internal padding stays covered by the expanded aggregate page.

## Raw PE Cross-Check

The raw PE scan independently supports the IDA xref classification:

- Direct `call rel32` hits to constructor/destructor/state helpers:
  - `0x0055e660`: six call sites.
  - `0x0055e780`: eight ordinary call sites plus IDA's extra exception/unwind references.
  - `0x0055e7e0`: five call sites.
  - `0x0055e840`: two call sites.
  - `0x0055e910`: 26 raw direct calls; IDA reports 27 including a raw/no-function site.
  - `0x0055e950`: 51 raw direct calls; IDA reports 52 including a raw/no-function site.
  - `0x0055e990`: 43 direct calls.
  - `0x0055eae0`: 52 direct calls.
  - `0x0055ec00`: two direct calls plus 33 absolute `.rdata` pointer hits.
  - `0x0055ee10`: three direct calls plus 42 absolute `.rdata` pointer hits.
  - `0x0055ef50`: three direct calls plus 39 absolute `.rdata` pointer hits.
  - `0x0055f0d0`: two direct calls plus 31 absolute `.rdata` pointer hits.
  - `0x0055f250`: four direct calls and one tail `jmp rel32` from inside `0x0055e990`.
- Absolute `.rdata` function-pointer hits identify virtual/table-dispatched methods at `0x0055ec00`, `0x0055ee10`, `0x0055ef10`, `0x0055ef50`, `0x0055f0d0`, `0x0055f130`, and `0x0055f190`.
- Raw `jmp rel32` hits identify the `ScrollableControlPane` wrapper thunks:
  - `0x004986aa -> 0x0055e8a0`
  - `0x004986ba -> 0x0055e8d0`
  - `0x004986ca -> 0x0055e910`
  - `0x004986da -> 0x0055e950`

This confirms that the `0x0055e8a0` and `0x0055e8d0` raw starts are reachable helper bodies, not dead bytes or padding.

## Ownership Analysis

### Accepted: [UID:0000CF] `ScrollablePane` as direct owner

Facts:

- Constructor stores `ScrollablePane` vtables at `this+0x0`, `this+0xa0`, and `this+0xa4`.
- Destructor body at `0x0055e780` restores the same vtables and deletes owned child `ScrollPane` objects at `+0xf8/+0xfc`.
- Every modeled/raw function in `0x0055e660-0x0055f44f` uses `ScrollablePane` object offsets and child scrollbar pointers.
- [UID:0003CL] `ScrollablePaneVtableData` already uses direct owner/emitter [UID:0000CF] and records stores at `0x0055e69f`, `0x0055e789`, and `0x0056551c`.
- [UID:0000CF] is already above the `85/85` direct-parent gate (`85/86`) and emits through [UID:0000NF] `ScrollBar`.

Inference:

The canonical owner for the executable method cluster should be the class [UID:0000CF], not the source file [UID:0000NF]. The file remains the source-file ancestor through the class.

### Accepted As Ancestor: [UID:0000NF] `ScrollBar`

Facts:

- [UID:0000NF] owns the generic scroll infrastructure family: `ScrollPane`, `ScrollWidget`, `ScrollablePane`, `CScrollBarBackPane`, vtable/data constants, and scrollbar tables.
- [UID:0003CQ] `ScrollPaneScrollbarConstantData` is file-owned and is referenced by `0x0055ec00` at `0x0055ecc0`.

Inference:

`ScrollBar.cpp` remains the output file ancestor. It should not be the direct canonical owner for class methods now that the class page and vtable page both clear the gate.

### Rejected Direct Owner: [UID:0000CE]/[UID:0000NE] `ScrollableControlPane`

Facts:

- `ScrollableControlPane` wrapper thunks at `0x004986a0-0x004986df` load the embedded child pointer at `+0x108` and jump into `ScrollablePane` helpers.
- Those wrapper bytes are inside [UID:00011G] `ScrollableControlPaneCore`, whose direct owner is [UID:0000CE].
- The destination helpers at `0x0055e8a0`, `0x0055e8d0`, `0x0055e910`, and `0x0055e950` operate on `ScrollablePane` child pointers at `+0xf8/+0xfc`.

Inference:

The wrapper thunks belong to `ScrollableControlPane`; the destination helpers belong to `ScrollablePane`. This is an adapter relationship, not evidence that `0001GL` should route to `ScrollableControlPane`.

### Rejected Direct Owner: [UID:0001GJ] `TextEditPaneScrollbarVariants` / `TextEditPane`

Facts:

- [UID:0001GJ] is already documented as a non-emitting mixed corridor map.
- `0x0055e660-0x0055f44f` is the generic `ScrollablePane` class body inside that corridor.
- `TextEditPane` and other controls call or override these class methods, but the vtable stores, child scrollbar fields, and generic class offsets are not TextEdit-local.

Inference:

Keep [UID:0001GJ] as a non-emitting corridor/index. Do not attach `0001GL` to TextEditPane.

### Rejected Direct Owner: `ScrollPane`, `ScrollWidget`, and `CScrollBarBackPane`

Facts:

- `ScrollPane` and `ScrollWidget` methods are child dependencies called by `ScrollablePane`.
- `CScrollBarBackPane` is a separate sibling class in the same `ScrollBar` file family.

Inference:

These pages are relationship evidence only. They are not the direct owner for `0001GL`.

## Split Decision

Do not split `0001GL` into exact child pages in this pass.

Rationale:

- The full `0x0055e660-0x0055f44f` span is one coherent class method/helper cluster with the same direct owner [UID:0000CF].
- The omitted `0x0055f250-0x0055f44f` function is called only by `0x0055e990` and `0x0055ec00` and shares the same state (`byte_66DA97`, `+0x110`, `+0x120`, scroll virtuals).
- The raw starts at `0x0055e8a0`, `0x0055e8d0`, and `0x0055edf0` are small source-shaped methods/helpers, not independent source owners.
- Existing comparable docs keep coherent class clusters together: [UID:00011G] `ScrollableControlPaneCore` and [UID:0001GH] `ScrollPaneInputCore` are aggregate pages with internal helper/padding inventories.
- Exact child pages would require at least 18 new pages plus many internal ignored rows without improving ownership or source routing. The actionable defect is stale range/inventory, not ownership mixing.

If a later supervisor wants per-method pages for final C++ work, allocate UIDs from the then-current project UID state. I do not recommend allocating new UIDs for this target now.

## Exact Supervisor Edits

### 1. Rename/update target page

Rename:

```text
by-memory/0x0055e660-0x0055f242.ScrollablePaneCore.md
to
by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md
```

Recommended metadata:

```text
*** UID:0001GL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Recommended title:

```text
# 0x0055e660-0x0055f44f ScrollablePane Core
```

Recommended status text:

```text
- Disposition: reconstructable NexusTK project code.
- Rebuild handling: source-authored `ScrollablePane` constructor/destructor, child-scrollbar state propagation, layout, layer/input/key dispatch, update-region, and internal viewport recompute helpers. The later scalar deleting destructor and default virtual island remains documented separately in [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md).
- Covered class/direct owner: [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md).
- Source file ancestor: [UID:0000NF][ScrollBar](by-file/ScrollBar.md).
- Containing aggregate context: [UID:0001GJ][0x0055d960-0x005654ec.TextEditPaneScrollbarVariants](by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md) remains a non-emitting mixed corridor map; this exact class cluster should emit through `ScrollablePane`/`ScrollBar`, not through TextEditPane.
- Final C++ gate: leave `RECONSTRUCTION_CPP CODE` blank. The route now clears the active score/emitter gate, but final source is still blocked by unresolved source-facing names for member fields, virtual slots, helper names, and high/low-resolution scrollbar tables.
```

Recommended function table rows:

```markdown
| Range | Function | Notes |
| --- | --- | --- |
| `0x0055e660-0x0055e77e` | `ScrollablePane::ScrollablePane` | Constructs the base `Pane`, stores three `ScrollablePane` vtables, creates horizontal `ScrollPane(1)` at `+0xf8` and vertical `ScrollPane(0)` at `+0xfc`, and initializes rects at `+0x110` and `+0x120`. |
| `0x0055e780-0x0055e7d9` | non-deleting destructor/cleanup body | Restores `ScrollablePane` vtables, deletes the two owned scrollbar children, and chains base teardown. |
| `0x0055e7e0-0x0055e83c` | child scrollbar range/state propagation | Writes the same word value to child offset `+0xf8` on enabled children and fires the child notify callback. |
| `0x0055e840-0x0055e897` | child scrollbar visibility/enabled propagation | Writes a byte value to child offset `+0xfa` on enabled children and fires the child notify callback. |
| `0x0055e8a0-0x0055e8c7` | raw selected-child target setter | Selects the horizontal or vertical child from `+0xf8/+0xfc` and calls `ScrollWidget::SetScrollTargetValue` (`0x0055c310`). Reached by a `ScrollableControlPane` wrapper thunk. |
| `0x0055e8d0-0x0055e90c` | raw selected-child current setter | Selects the horizontal or vertical child, updates child offset `+0xfe`, and fires callback slot `+0x20`. Reached by a `ScrollableControlPane` wrapper thunk. |
| `0x0055e910-0x0055e949` | selected-child target/range getter | Returns child word at `+0x100`, or zero if the selected child is missing. |
| `0x0055e950-0x0055e989` | selected-child current/offset getter | Returns child word at `+0xfe`, or zero if the selected child is missing. |
| `0x0055e990-0x0055ead5` | synchronize scrollbar state from content virtuals | Reads virtual slots `+0x48/+0x4c`, clamps values to `0..30000`, updates child target/current state, and calls `0x0055f250`. |
| `0x0055eae0-0x0055ec00` | apply selected-axis scroll movement | Updates selected child current state, invokes the virtual rect helper at slot `+0x5c`, and refreshes/clips the content/render regions. |
| `0x0055ec00-0x0055edeb` | layout/update scrollbar bounds | Uses `byte_66DA97` and `0x00624138-0x00624168` scrollbar constants to place enabled scrollbars, update `+0x110`, then call `0x0055f250` and `0x0055e990`. |
| `0x0055edf0-0x0055ee04` | raw content-rect copy helper | Copies the 16-byte rect at `this+0x110` to caller output. No current IDA xrefs; keep as raw source-shaped helper. |
| `0x0055ee10-0x0055ef08` | layer/add or move/attach virtual | Calls base `0x00544c70`, adjusts child positions, and delegates child virtual slots `+0x28/+0x30`. |
| `0x0055ef10-0x0055ef43` | remove/detach virtual | Detaches enabled scrollbar children via child virtual slot `+0x38`, then calls base `0x00544ce0`. |
| `0x0055ef50-0x0055f0ca` | input dispatch virtual | Gives child scrollbars first chance to handle input; mouse-wheel/content-rect path calls `0x0055eae0`; fallback dispatches to owner/base slot `+0x60`. |
| `0x0055f0d0-0x0055f128` | key-down dispatch virtual | Lets child scrollbar panes consume the key event before fallback to owner/base slot `+0x64`. |
| `0x0055f130-0x0055f188` | key-up dispatch virtual | Lets child scrollbar panes consume the key event before fallback to owner/base slot `+0x68`. |
| `0x0055f190-0x0055f243` | update scroll region/hook virtual | Builds temporary region state from `+0x110`, calls virtual slot `+0x6c`, and restores temporary objects. |
| `0x0055f250-0x0055f44f` | internal viewport/content rect recompute helper | Called only from `0x0055e990` and `0x0055ec00`; updates `+0x120` from `+0x110`, content size virtual `+0x58`, scroll offsets, and `byte_66DA97`. |
```

Recommended score rationale:

```text
The page is scored `87/90` because the live IDA pass now records the complete `0x0055e660-0x0055f44f` function/raw-helper inventory, corrected half-open ends, byte-level padding audit, raw helper reachability through `ScrollableControlPane` wrappers, constructor/destructor/vtable evidence, internal `0x0055f250` ownership, scrollbar constant-table refs, class/file owner route, and exact successor boundary. Completion remains below final-source quality because source-facing names for fields, virtual slots, helper signatures, and high/low-resolution scrollbar tables are still unresolved.
```

### 2. Coverage-report replacement row

Replace the current [UID:0001GL] row in `by-memory/-coverage-report.md` with:

```markdown
      - [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md) 0x0055e660-0x0055f44f | method cluster | ScrollablePaneCore : reconstructable : 87% : strong : Expanded/corrected ScrollablePane class cluster with live IDA and raw PE evidence for constructor, non-deleting destructor, child scrollbar state propagation, raw selected-child setters/getters, state synchronization, layout, layer attach/detach, input/key dispatch, update-region hook, internal viewport recompute helper `0x0055f250-0x0055f44f`, raw helper reachability from ScrollableControlPane wrappers, exact padding audit, direct class owner [UID:0000CF], source-file ancestor [UID:0000NF], and final-C++ blockers for field/table/virtual-slot names.
      - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0055f44f-0x0055f450 | padding | ScrollablePaneCore to ScrollSpellInventoryPane alignment : ignored : 100% : strong : Live IDA MCP and raw bytes confirm a single `0xcc` byte after `sub_55F250` and before the `ScrollSpellInventoryPane` successor at `0x0055f450`; no source replacement needed.
```

Placement: keep these immediately before the existing [UID:0001GM] `0x0055f450-0x005608fc.ScrollSpellInventoryPane` row.

### 3. Ignored-row text for `by-memory/-ignored.md`

Add:

```markdown
- `0x0055f44f-0x0055f450` - `ScrollablePaneCore` to `ScrollSpellInventoryPane` alignment padding.
  - Why ignored: single `0xcc` compiler/linker alignment byte after the internal `ScrollablePane` viewport recompute helper and before the first `ScrollSpellInventoryPane` modeled function.
  - Evidence: 2026-06-16 B001 live IDA MCP `entity_query` reports `sub_55F250` as `0x0055f250-0x0055f44f` and successor `sub_55F450` at `0x0055f450`; `get_bytes` returns one `0xcc` byte for `0x0055f44f-0x0055f450`.
  - Replacement/procurement: no source-level replacement; compiler/linker alignment.
  - Owner docs: [UID:0001GL][0x0055e660-0x0055f44f.ScrollablePaneCore](by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md), [UID:0001GM][0x0055f450-0x005608fc.ScrollSpellInventoryPane](by-memory/0x0055f450-0x005608fc.ScrollSpellInventoryPane.md).
```

Do not add ignored rows for `0x0055e8a0-0x0055e8c7`, `0x0055e8d0-0x0055e90c`, or `0x0055edf0-0x0055ee04`.

### 4. Support doc edits

Recommended `by-class/ScrollablePane.md` updates:

```text
Change main address ranges to:
- Main address ranges: `0x0055e660-0x0055f44f`, `0x005654ec-0x00565608`.

Add evidence note:
- 2026-06-16 B001 live IDA MCP and raw PE audit correct the core method cluster to `0x0055e660-0x0055f44f`: constructor, non-deleting destructor body, child scrollbar state propagation, raw selected-child setters at `0x0055e8a0`/`0x0055e8d0`, selected-child getters, synchronization/layout/input/key/update methods, raw content-rect copy at `0x0055edf0`, and internal viewport recompute helper `0x0055f250-0x0055f44f`. Direct class ownership is supported by vtable stores, child scrollbar offsets, vtable data [UID:0003CL], and source-file ancestor [UID:0000NF].
```

Optional score update for `by-class/ScrollablePane.md`: `85/86` to `87/89`, justified by the corrected class inventory and class-owned vtable/data consistency. This optional class score is not required for assigning `0001GL` because the current class page already clears `85/85`.

Recommended `by-file/ScrollBar.md` update:

```text
Change the proposed contents row for `ScrollablePane` to include `0x0055e660-0x0055f44f` and `0x005654ec-0x00565608`.

Add evidence note:
- 2026-06-16 B001 confirms `ScrollablePaneCore` should route through the class [UID:0000CF] and then this source file. `0x0055f250-0x0055f44f` is not a spell-inventory predecessor or TextEditPane fragment; it is an internal helper called from `ScrollablePane` synchronization/layout paths.
```

Recommended `by-memory/0x004985a0-0x004988cc.ScrollableControlPaneCore.md` support note:

```text
- 2026-06-16 B001 notes that the wrapper thunk bytes at `0x004986a0-0x004986df` delegate selected scroll metrics/state through the embedded child pointer at `+0x108`: `0x004986aa -> 0x0055e8a0`, `0x004986ba -> 0x0055e8d0`, `0x004986ca -> 0x0055e910`, and `0x004986da -> 0x0055e950`. These wrapper thunks remain `ScrollableControlPane` support code, while the destinations remain `ScrollablePane` class helpers.
```

Recommended `by-memory/0x0055d960-0x005654ec.TextEditPaneScrollbarVariants.md` support note:

```text
- 2026-06-16 B001 corrects the generic `ScrollablePane` child interval to [UID:0001GL] `0x0055e660-0x0055f44f`; the corridor remains a non-emitting mixed map and should not own the exact class methods.
```

## Final C++ Decision

Keep `RECONSTRUCTION_CPP CODE` blank for `0001GL`.

The corrected page would clear the active average-score/emitter gate, but final C++ is not yet safe because these names remain unresolved after current evidence:

- `ScrollablePane` field names at `+0xf8`, `+0xfc`, `+0x100`, `+0x104`, `+0x108`, `+0x10c`, `+0x10d`, `+0x110`, and `+0x120`. Behavior is known; source-facing names are still inferred.
- Virtual slot names around `+0x48`, `+0x4c`, `+0x54`, `+0x58`, `+0x5c`, `+0x60`, `+0x64`, `+0x68`, and `+0x6c`.
- Helper names for base pane operations `0x00544460`, `0x00544580`, `0x00544c70`, `0x00544ce0`, rectangle/region helpers, and render update helpers.
- High/low-resolution table identities for `0x00624138`, `0x00624144`, `0x00624150`, and `0x0062415c`; behavior and xrefs are known, but original table names are not.
- Source representation for raw helper bodies `0x0055e8a0`, `0x0055e8d0`, and `0x0055edf0`; they are source-shaped helper bodies, but exact declaration names/signatures are not final.

These are source-quality blockers, not ownership blockers. The page can be routed and scored above the gate while C++ remains blank.

## Validation Plan

After supervisor applies the report:

> Executable block R001 was removed from this report and preserved verbatim in [0001GL-scrollablepane-core-source-split-audit-removed.md](0001GL-scrollablepane-core-source-split-audit-removed.md). The archived block is non-authoritative and must not be executed.

Expected outcome:

- Validator accepts the renamed [UID:0001GL] path and updates UID references.
- `project-level/-auto-completion-stats.md` no longer lists `0001GL` under `Low_Completion` or `Low_Both`.
- `auto-generated/-ag-memory-coverage.md` routes [UID:0001GL] through [UID:0000CF] to [UID:0000NF].
- `auto-generated/by-memory-tool-report.md` has no new Barrier Crossings, General Errors, Filename Errors, or Advanced-Error-Scan findings for `ScrollablePaneCore`.
- The exact gap between `0x0055f44f` and `0x0055f450` is ignored, and `0x0055f250-0x0055f44f` no longer remains only as unsplit generic code under the broad [UID:0001GJ] corridor.

## Remaining Uncertainty

- The behavior of each method is understood well enough for routing and score repair, but final source names are not fully recovered.
- `0x0055edf0` has no IDA xrefs or raw call/jump hits; it is still real code because it cleanly decodes as a rect-copy helper between padding islands. Its source owner is inferred from object offset `+0x110` and adjacency inside the class cluster, not from a recovered caller.
- The exact original names of the high/low-resolution scrollbar constants are still unresolved. [UID:0003CQ] proves the table address range and xref at `0x0055ecc0`, but not the source symbol names.

## Confidence

- Recommendation confidence: high.
- Score confidence: `87/90`.
- Split confidence: high no-split recommendation; exact child pages are not needed to fix ownership or memory coverage.
- Final C++ confidence: medium-low; leave blank.

## Final B001 Result

Recommend: **no new child split**, **expand/rename existing [UID:0001GL] to `0x0055e660-0x0055f44f`**, **reroute direct owner/emitter to [UID:0000CF] `ScrollablePane`**, **raise to `87/90`**, and **add one ignored boundary padding row `0x0055f44f-0x0055f450`**.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001GL-scrollablepane-core-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:19","uid":"0001GL"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001GL-scrollablepane-core-source-split-audit-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001GL-scrollablepane-core-source-split-audit.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001GL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
