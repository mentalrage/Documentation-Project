*** UID:0001XS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// The InputPane base-family vtables are compiler/linker output generated from
// the class declarations in this file. See [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) for the concrete
// 0x0061ca54-0x0061ce28 data range; do not hand-author fixed vtable dwords here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# InputPane Base Vtable Family

## Status

- Entity kind: file-level vtable family inventory for the reusable input-pane base classes.
- Confidence: very strong for vtable bases, constructor/destructor stores, RTTI locator boundaries, concrete `.rdata` child coverage, and slot boundaries; still below final-audit confidence because exact source-level virtual names and every inherited slot declaration are not fully reconstructed.
- Direct parent/source owner: [UID:0000K7][InputPanes](by-file/InputPanes.md)
- Rebuild handling: `source-declared/generated-binary`; the rebuilt class declarations should emit these vtables, while the `.rdata` bytes should not be hand-authored.
- Concrete data child: [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) documents the exact input-pane `.rdata` subrange `0x0061ca54-0x0061ce28`; containing mixed aggregate [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md) remains an unassigned index across Layer/Input/List/ListPane/`LObject` data.
- Memory range: [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- Destructor adjustors: [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)

## Vtable Bases

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Constructor / owner stores |
| --- | --- | --- | --- | --- |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | `0x0061ca58` | `0x0061caa8` | `0x0061cad8` | Constructor `0x004f1c00`; setup/helper `0x004f2010`; destructors `0x004f2dd0` and `0x004f2ea0`. |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | `0x0061cae4` | `0x0061cb34` | `0x0061cb64` | Constructor `0x004f27a0`. |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | `0x0061cb70` | `0x0061cbc0` | `0x0061cbf0` | Constructor `0x004f28a0`. |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | `0x0061cbfc` | `0x0061cc4c` | `0x0061cc7c` | Raw/inline stores near `0x004f29d9`; scalar deleting destructor `0x004f2fb0`; late constructor `0x005b75d0`. |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | `0x0061cc88` | `0x0061ccd8` | `0x0061cd08` | Constructor `0x004f2a60`. |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | `0x0061cd14` | `0x0061cd64` | `0x0061cd94` | Constructor `0x004f2b80`. |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | `0x0061cda0` | `0x0061cdf0` | `0x0061ce20` | Constructor `0x004f2c90`. |

## Key Slots

| Class | Primary slot notes | Secondary slot notes | Tertiary slot notes |
| --- | --- | --- | --- |
| `LineInputPane` | `+0x00 -> 0x004f2ea0` scalar deleting destructor; `+0x0c -> 0x004f2320`; `+0x30 -> 0x004f2430`; `+0x38 -> 0x004f24c0`; `+0x44 -> 0x004f2790` distinct `OnNoOpInputPaneSlot`; `+0x48 -> 0x0041b6a0` inline empty default `OnSubmitInput`. [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md) overrides the matching primary `+0x48` cell at `0x0062f744 -> 0x005b1640`. | `+0x00 -> 0x004f2e59` adjustor; `+0x04 -> 0x004f24f0`; `+0x08 -> 0x004f25a0` canonical `HandleKeyOrTextEvent(Event *)`; `+0x0c -> 0x004f2580`; `+0x10 -> 0x004f2760`. | `+0x00 -> 0x004f2e64` adjustor; `+0x04 -> 0x00544e90` default/update slot. |
| `NumberInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2820` numeric key filter. | Same tertiary shape as `LineInputPane`. |
| `CharInputPane` | `+0x00 -> 0x004f2f70` scalar deleting destructor; inherited primary behavior otherwise. | `+0x00 -> 0x004f2e6f` adjustor; overrides `+0x08 -> 0x004f2920` with `HandleKeyOrTextEvent(Event *)`, including translation, Event rewrite, cleanup queue, pending-target clear, inherited dispatch, and acceptance callback. | `+0x00 -> 0x004f2e7a` adjustor; `+0x04 -> 0x00544e90`. |
| `ConfirmInputPane` | `+0x00 -> 0x004f2fb0` scalar deleting destructor; `+0x48 -> 0x004f2a10` yes/no confirmation action. | `+0x00 -> 0x004f2e85` adjustor; inherits `CharInputPane` key acceptor at `+0x08 -> 0x004f2920`. | `+0x00 -> 0x004f2e90` adjustor; `+0x04 -> 0x00544e90`. |
| `CharArgsInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2ae0` as canonical `HandleKeyOrTextEvent(Event *)` with its independent alphabetic/comma/space argument filter and LineInputPane fallback. | Same tertiary shape as `LineInputPane`. |
| `NumberArgsInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2c00` digit/comma/space argument filter. | Same tertiary shape as `LineInputPane`. |
| `MultiLineInputPane` | Inherits the `LineInputPane` primary behavior and scalar destructor. | Overrides secondary `+0x08 -> 0x004f2cd0` multi-line submit/close key handler. | Same tertiary shape as `LineInputPane`. |

## Boundary Notes

## B003 2026-07-20 Shared Event Slot Synchronization

- The `+0x08` secondary slot is the shared source virtual `bool HandleKeyOrTextEvent(Event *event)` across LineInputPane-derived views. UID000364 at `0x004f2920` is the complete CharInputPane override, while `0x004f2ae0` is the independent CharArgsInputPane filter; normal base calls and adjusted receivers are source/ABI views of this one signature, not distinct `OnKeyInput`, `HandleInputEvent`, or raw-helper declarations.
- The managed R23 compiler-data disposition remains byte-for-byte unchanged. Vtable/RTTI/locator dwords stay compiler/linker output and are not handwritten source.

- These are MSVC-style vtables with a complete-object-locator dword immediately before each vtable start. Do not treat the dword after each primary or secondary slot span as a virtual slot; it is the next table's locator.
- The exact input-pane RTTI/vtable band is half-open `0x0061ca54-0x0061ce28`: `0x0061ca54` is the `LineInputPane` primary complete-object-locator pointer, immediately after the final `Layer` slot at `0x0061ca50`, and `0x0061ce28` is the following `List` locator pointer.
- Primary tables have valid slots through `+0x48`, secondary tables through `+0x28`, and tertiary tables through `+0x04`.
- Secondary and tertiary destructor slots point at compiler-generated this-adjustor thunks in `0x004f2e59-0x004f2e9b`; these wrappers subtract `0xa0` or `0xa4` from `ecx` and tail-jump to the real scalar deleting destructor. The corrected endpoint is required because the final `0x004f2e90` thunk is `0x0b` bytes and ends at exclusive address `0x004f2e9b`.
- The dword at `0x0061ce28` after the `MultiLineInputPane` tertiary table is the locator for the neighboring `List` vtable, not another input-pane slot.
- `ConfirmInputPane` has two construction patterns: raw/inline vtable stores in the base cluster near `0x004f29d9`, and the IDA-defined constructor at `0x005b75d0` that calls `CharInputPane` and installs the same three vtables.

## Adjustor Thunk Slot Mapping

| Thunk | Descriptive ABI role | Vtable refs |
| --- | --- | --- |
| `0x004f2e59` | LineInputPane-family secondary scalar deleting destructor adjustor, subtracts `0xa0`, jumps to `0x004f2ea0`. | `0x0061caa8`, `0x0061cb34`, `0x0061ccd8`, `0x0061cd64`, `0x0061cdf0` |
| `0x004f2e64` | LineInputPane-family tertiary scalar deleting destructor adjustor, subtracts `0xa4`, jumps to `0x004f2ea0`. | `0x0061cad8`, `0x0061cb64`, `0x0061cd08`, `0x0061cd94`, `0x0061ce20` |
| `0x004f2e6f` | `CharInputPane` secondary scalar deleting destructor adjustor, subtracts `0xa0`, jumps to `0x004f2f70`. | `0x0061cbc0` |
| `0x004f2e7a` | `CharInputPane` tertiary scalar deleting destructor adjustor, subtracts `0xa4`, jumps to `0x004f2f70`. | `0x0061cbf0` |
| `0x004f2e85` | `ConfirmInputPane` secondary scalar deleting destructor adjustor, subtracts `0xa0`, jumps to `0x004f2fb0`. | `0x0061cc4c` |
| `0x004f2e90` | `ConfirmInputPane` tertiary scalar deleting destructor adjustor, subtracts `0xa4`, jumps to `0x004f2fb0`. | `0x0061cc7c` |

These are descriptive ABI labels for documentation/IDA use only. They should not appear as source-level virtual method names, and generated names such as `virt_meth_0x4f2e59` should remain data-pollution aliases rather than final source.

## Evidence

- IDA MCP `list_globals` reports all bases above with MSVC decorated vtable names plus matching RTTI locator names. The 2026-05-31 check specifically confirmed `CharArgsInputPane`, `NumberArgsInputPane`, `MultiLineInputPane`, and `ConfirmInputPane`; earlier IDA-backed rows already covered `LineInputPane`, `NumberInputPane`, and `CharInputPane`.
- IDA MCP `xrefs_to` on 2026-05-31 confirms constructor/destructor stores for every listed vtable. `LineInputPane` vtables are stored by `0x004f1c00`, restored by `0x004f2010`, and restored during destructors `0x004f2dd0` / `0x004f2ea0`; the derived input panes store their three-table families from `0x004f27a0`, `0x004f28a0`, raw stores near `0x004f29d9`, `0x004f2a60`, `0x004f2b80`, `0x004f2c90`, `0x004f2fb0`, and `0x005b75d0`.
- IDA MCP `py_eval` dword reads on 2026-05-31 confirm the slot values listed above, including the shared scalar destructor/adjustor targets, derived key-filter overrides, and `0x0061ce28 -> ??_R4List@@6B@` boundary after the `MultiLineInputPane` tertiary table.
- IDA MCP function lookup through the read slot values confirms the relevant executable targets lie inside the documented `0x004f1c00-0x004f3017` input-pane cluster, with the adjustor thunks in [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md).
- Current `simroot_v2` metadata reports `vtable_count: 0` for `LineInputPane`, `NumberInputPane`, `CharInputPane`, `ConfirmInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane`; this page is the IDA-backed replacement anchor until generated vtable inventory is repaired.
- 2026-06-11 Agent-A002 IDA MCP `py_eval` rechecked the backing `.rdata` band: `0x0061ca44 -> ??_R4Layer@@6B@`, `0x0061ca48 -> ??_7Layer@@6B@`, `0x0061ca50 -> nullsub_18`, `0x0061ca54 -> ??_R4LineInputPane@@6B@`, `0x0061ca58 -> ??_7LineInputPane@@6B@`, `0x0061ce20 -> ??_7MultiLineInputPane@@6B@_1`, `0x0061ce24 -> 0x00544e90`, and `0x0061ce28 -> ??_R4List@@6B@`.
- The same 2026-06-11 pass reconfirmed constructor/store xrefs for all table triples: four refs each for the `LineInputPane` tables from construction/cleanup/destruction, one constructor-store ref for the `NumberInputPane`, `CharInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` triples, and three refs for the `ConfirmInputPane` triple from the raw complete-destructor body, scalar deleting destructor, and late constructor.
- B001-042 has already split the executable [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) cluster into exact class-owned child method pages. This type page therefore records the shared declaration/vtable layout and does not duplicate those method children.
- UID000401 source-quality closure resolves the formerly generic LineInputPane primary `+0x48` guard/default as `OnSubmitInput`. Base target `0x0041b6a0` is a one-instruction `retn` with folded/runtime/no-op uses, while inherited Enter dispatch calls primary `+0x48` and the legacy direct-message class overrides it through `0x0062f744 -> 0x005b1640`. This evidence does not rename distinct `+0x44 -> 0x004f2790`, does not create a standalone body for `0x0041b6a0`, and does not alter the source-declared/generated-binary vtable policy.

## Assignment Gate

`CANONICAL_OWNER` and `EMITTER_UIDS` attach this vtable-family page to [UID:0000K7][InputPanes](by-file/InputPanes.md). The page spans seven sibling class vtable triples, so assigning it to any one class would be inaccurate; however, the current `InputPanes` file page owns all seven source declarations as one reusable typed input-pane module and clears the strict gate at `91/88`. The child page now clears the gate at `88/93`, exact concrete data child [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) clears `88/92`, and the seven direct class pages also attach to `InputPanes` and clear `85/85`.

The exact executable method children remain attached to their direct class parents, and the compiler-generated adjustor thunk island remains non-reconstructable. This page is assigned at file scope only as the shared source-declaration layout anchor for the vtables that the compiler emits from the `InputPanes` classes. The formal reconstruction block intentionally emits a no-duplicate generated-binary comment, not fixed vtable dwords.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `89` | The page records the exact RTTI/vtable band, all seven table triples, slot/adjustor boundaries, constructor-store xrefs, B001's exact executable child split, the direct file-parent assignment decision, exact concrete data child [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md), a formal no-duplicate source comment, and the now-resolved distinction between `OnNoOpInputPaneSlot` at `+0x44` and inline default `OnSubmitInput` at `+0x48` with UID000401 override evidence. It remains below final-audit quality because inherited virtual declarations and final source names for every other unresolved slot are not complete. |
| Confidence `94` | Live IDA MCP reconfirmed boundary dwords, decorated RTTI/vtable names, representative slot targets, xrefs for each table triple, exact concrete data child [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md), related class/file parents clearing the strict gate, and the source-declared/generated-binary policy. Base `0x0041b6a0` one-byte behavior, inherited Enter dispatch, and UID000401 `0x0062f744 -> 0x005b1640` independently converge on `OnSubmitInput`; confidence remains below `95+` because some other source-level virtual names and declaration ordering are inferred. |

## Cross-References

- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md)
- [UID:00025N][0x0061ca44-0x0061cf68.LayerInputListReadOnlyData](by-memory/0x0061ca44-0x0061cf68.LayerInputListReadOnlyData.md)
- [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md)
- [UID:000077][LineInputPane](by-class/LineInputPane.md)
- [UID:00009L][NumberInputPane](by-class/NumberInputPane.md)
- [UID:00001P][CharInputPane](by-class/CharInputPane.md)
- [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md)
- [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md)
- [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md)
- [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md)
- [UID:000401][0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods](by-memory/0x005b1570-0x005b1812.SayToUserMessageInputPaneMethods.md)
- [wave3 data issues](../../wave3_data_issues.md)

## Changes

### 2026-08-13 B006 - UID000401 submit-slot synchronization

- Raised `88/93 -> 89/94` while preserving UID0000K7 owner/emitter, reconstructable state, blank optional position, the exact RTTI/vtable band, every table/adjustor boundary, and the no-handwritten-vtable formal policy.
- Resolved LineInputPane primary `+0x48 -> 0x0041b6a0` as inline empty `OnSubmitInput`, linked UID000401 primary `0x0062f744 -> 0x005b1640` as the matching derived override, and kept primary `+0x44 -> 0x004f2790` as the distinct `OnNoOpInputPaneSlot`.
- No vtable dword, standalone folded body, IDA entity, or unrelated virtual name was changed.

### 2026-07-01 Agent-B011 - Empty-emitter no-duplicate implementation

- Changed to: `COMPLETION:88`, `CONFIDENCE:93`, with a formal no-duplicate generated-binary comment in `RECONSTRUCTION_CPP CODE`.
- Evidence/disposition: B011 report [UID:0000K7][InputPanes](by-file/InputPanes.md) confirmed this type page should not hand-author MSVC vtable dwords; the compiler/linker regenerate these bytes from the `InputPanes` class declarations, while [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) remains the concrete data evidence page. The stale "leave C++ blank" outcome is superseded by this target-specific no-duplicate comment.

### 2026-06-11 Agent-A002 - Exact vtable-data child split

- Before: the page was `86/91` with exact vtable-family evidence but no standalone by-memory child for the concrete `.rdata` range.
- Changed to: `COMPLETION:87`, `CONFIDENCE:92`, and a direct link to exact child [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md) covering `0x0061ca54-0x0061ce28`.
- Evidence: live IDA MCP `idb_meta` and `py_eval` reconfirmed the current IDB hash, the `Layer` final slot at `0x0061ca50`, `LineInputPane` locator/table start at `0x0061ca54/0x0061ca58`, all seven primary/secondary/tertiary table bases and locator pointers, representative slot target function sizes, store xrefs for each table triple, and the `List` successor locator at `0x0061ce28`.

### 2026-06-11 Agent-A002 - Parent-gate assignment refresh

- Before: the page was `84/88`, reconstructable, and parent-blank even though B001-042 had since raised [UID:0000K7][InputPanes](by-file/InputPanes.md) and all seven class parents over the strict gate.
- Changed to: `COMPLETION:86`, `CONFIDENCE:91`, and `AUTOGEN_PARENT_UID:0000K7`, with an assignment-gate section, rebuild-handling note, exact `0x0061ca54-0x0061ce28` backing-band boundary, and current B001 split context.
- Evidence: 2026-06-11 IDA MCP `py_eval` reconfirmed the `Layer` to `LineInputPane` transition at `0x0061ca54`, every input-pane RTTI/vtable triple, the `0x0061ce28` `List` successor locator, slot target functions, and constructor/destructor store xrefs for each class family.

### 2026-05-31 - Scored IDA-verified vtable family

- Before: validator metadata still marked this page `COMPLETION:0`, `CONFIDENCE:0`, and left `RECONSTRUCTABLE` blank despite an already documented vtable inventory.
- Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`. No parent attachment or C++ reconstruction code was added because the exact source-level declaration shape and every virtual slot name are not final-audit complete.
- Evidence: IDA MCP `list_globals`, `xrefs_to`, and `py_eval` checks on 2026-05-31 confirmed the decorated vtable names, constructor/destructor stores, slot target dwords, function boundaries for selected slot targets, and the `0x0061ce28` transition into the neighboring `List` RTTI locator.
