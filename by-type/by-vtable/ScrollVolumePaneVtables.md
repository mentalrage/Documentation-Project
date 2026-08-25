*** UID:0001YT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScrollVolumePane Vtables

## Status

- Entity kind: vtable cluster.
- Covered class: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md).
- Likely source file: [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md).
- Exact data child: [UID:0003CP][0x006240b0-0x00624138.ScrollVolumePaneVtableData](by-memory/0x006240b0-0x00624138.ScrollVolumePaneVtableData.md).
- Confidence: very strong for all three vtable bases, complete locator/function extents, constructor installation, Pane/EventHandler/TimerHandler view identities, corrected virtual names, and successor exclusion.
- Autogen parent: attach this vtable cluster to [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), now `93/94`; reconstruction C++/H remain blank because these are compiler-emitted table records rather than standalone source declarations.
- Inheritance interpretation: `ScrollVolumePane` directly derives from `Pane`. The secondary EventHandler and tertiary TimerHandler views are inherited Pane facets, not additional direct bases in the human declaration.

## Vtable Bases

| Class view | Base | Constructor evidence | Notes |
| --- | --- | --- | --- |
| primary Pane | `0x006240b4` | `0x00564761` | Installed at object offset `+0x00`; includes `OnPaint` at primary slot `+0x44`. |
| inherited EventHandler view `+0xa0` | `0x00624100` | `0x00564767` | Pointer/mouse and key/text callbacks at slots `+0x04` and `+0x08`. |
| inherited TimerHandler view `+0xa4` | `0x00624130` | `0x00564771` | Timer callback at slot `+0x04`. |

The exact table-data child spans `0x006240b0-0x00624138` (`0x88` / 136 bytes, verified with `tools/int_convert.py`). Complete-object-locator dwords sit at `0x006240b0`, `0x006240fc`, and `0x0062412c`; the constructor stores the three following vtable starts into the object.

## Verified Layout Extents

| View | Locator dword | Function-pointer span | Installed object offset | Notes |
| --- | --- | --- | --- | --- |
| primary | `0x006240b0 -> 0x0064fb9c` | half-open `0x006240b4-0x006240fc` | `+0x00` | Eighteen function entries through paint slot `+0x44`. |
| secondary | `0x006240fc -> 0x0064fbf8` | half-open `0x00624100-0x0062412c` | `+0xa0` | Eleven function entries through `+0x28`; `0x0062412c` is the tertiary locator, not a secondary slot. |
| tertiary | `0x0062412c -> 0x0064fc0c` | half-open `0x00624130-0x00624138` | `+0xa4` | Two entries: adjustor deleting-destructor thunk and `OnTimer`. |

## Notable Slots

| Vtable | Slot | Target | Notes |
| --- | --- | --- | --- |
| primary `0x006240b4` | `+0x44` | `0x00564b50` | `OnPaint`, drawing the volume slider track/thumb. |
| secondary `0x00624100` | `+0x00` | `0x004213f8` | Adjustor deleting-destructor thunk subtracting `0xa0` before jumping to the shared deleting-destructor body at `0x00421480`. |
| secondary `0x00624100` | `+0x04` | `0x00564910` | `HandlePointerOrMouseEvent(Event *)`. |
| secondary `0x00624100` | `+0x08` | `0x00564b00` | `HandleKeyOrTextEvent(Event *)`; exact body returns false. |
| tertiary `0x00624130` | `+0x00` | `0x00421403` | Adjustor deleting-destructor thunk subtracting `0xa4` before jumping to the shared deleting-destructor body at `0x00421480`. |
| tertiary `0x00624130` | `+0x04` | `0x00564b10` | `OnTimer(int,int,int)`; tests timer id, commits/repeats state, and schedules the 30 ms follow-up. |

Do not read `0x00624134` as secondary `+0x34`: live dword reads show `0x0062412c` is the tertiary locator and `0x00624130` is the tertiary table start, so the `0x00564b10` dword at `0x00624134` is tertiary `+0x04` only. Do not read past `tertiary +0x04` as `ScrollVolumePane` slots. The following dwords are unrelated data, not part of the vtable.

The adjacent `0x005654ec` and `0x005654f7` thunks are not evidence for a `ScrollVolumePane` destructor. Current memory docs keep those thunks with [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md) because they forward into `ScrollablePane::ScalarDeletingDestructor` at `0x00565510`; the canonical `ScrollablePaneVirtualDefaults` range now starts at `0x005654ec`.

## Evidence Notes

- Constructor disassembly at `0x00564761`, `0x00564767`, and `0x00564771` installs `0x006240b4`, `0x00624100`, and `0x00624130`.
- `xrefs_to` each vtable base reports the matching constructor store as the direct data reference.
- IDA vtable dumping maps the primary paint slot to `0x00564b50`, EventHandler pointer/mouse and key/text slots to `0x00564910`/`0x00564b00`, and TimerHandler `OnTimer` to `0x00564b10`.
- Historical/superseded Wave3 metadata reported `vtable_count: 0`; the current ordinary vtable inventory instead uses the confirmed IDA symbols and corrected method identities below.
- 2026-06-13 live IDA MCP recheck on session `a001_goal2_0002UM` confirmed the function targets and sizes. Later slot-family reconciliation corrects the descriptive names to `HandlePointerOrMouseEvent` at `0x00564910`, false-return `HandleKeyOrTextEvent` at `0x00564b00`, and `OnTimer` at `0x00564b10`; the earlier `IsScrollable` and focus-loss interpretations were stale.
- The same pass read every dword in `0x006240b0-0x00624138`, confirmed locator dwords at `0x006240b0`, `0x006240fc`, and `0x0062412c`, and confirmed data xrefs from `0x006240f8`, `0x00624104`, `0x00624108`, and `0x00624134` to the paint, pointer/mouse, key/text, and timer targets.
- Tail-exclusion evidence remains stable: `0x005654ec` has a vtable data ref from `0x00623e58` and subtracts `0xa0`; `0x005654f7` has a vtable data ref from `0x00623e88` and subtracts `0xa4`; both jump to `0x00565510`, which has its own `ScrollablePane` table ref at `0x00623de4`.
- Verified with `tools/int_convert.py`: `0x4c` is 76 bytes, `0x30` is 48 bytes, `0x44` is 68 bytes, `0xa0` is 160 bytes, `0xa4` is 164 bytes, `0x88` is 136 bytes, and `0x110` is 272 bytes.

## Reconstruction Notes

Model `ScrollVolumePane` as a direct `Pane`-derived control with primary, inherited EventHandler, and inherited TimerHandler views at `+0x00`, `+0xa0`, and `+0xa4`. Keep the source in `ui/controls/ScrollVolumePane.cpp`; the vtable cluster strengthens class layout evidence but does not add direct multiple-inheritance bases or move option-policy callbacks into the slider source.

B014 class source-quality sync: declaration-level C++ now belongs on [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), while this vtable page remains generated-binary support with no standalone C++ body. The slot data supports the horizontal volume-slider class shape and exact child method routes; it should not be used to import the neighboring `ScrollablePane` destructor thunks into `ScrollVolumePane`.

## Parent And Slot Rationale

Attach this type page to [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), reconstructable at `93/94` and attached to [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) at `92/93`. The class page records the same primary/EventHandler/TimerHandler view layout, nineteen-method map, and excluded-tail boundary. The slot identities are now source-ready; this vtable page remains blank-code support because the compiler emits the tables from the class declaration and exact method definitions.

## Cross-References

- [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md)
- [UID:0001W2][ScrollVolumePaneLayout](by-type/by-struct/ScrollVolumePaneLayout.md)
- [UID:0003CP][0x006240b0-0x00624138.ScrollVolumePaneVtableData](by-memory/0x006240b0-0x00624138.ScrollVolumePaneVtableData.md)
- [UID:0001H2][0x00564710-0x005654ec.ScrollVolumePane](by-memory/0x00564710-0x005654ec.ScrollVolumePane.md)
- [UID:0001H3][0x00564e30-0x00565006.ScrollVolumePaneHitTestPart](by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md)
- [UID:0002LB][0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw](by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md)
- [UID:0002LC][0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw](by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md)
- [UID:0001H4][0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction](by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md)
- [UID:0001H5][0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange](by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md)
- [UID:0002LD][0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw](by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md)
- [UID:0001H6][0x005654ec-0x00565608.ScrollablePaneVirtualDefaults](by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md)
- [UID:0001YQ][ScrollInventoryPaneVtables](by-type/by-vtable/ScrollInventoryPaneVtables.md)

## Changes

- 2026-05-31: Changed completion/confidence from `0/0` to `70/86` and marked the vtable cluster reconstructable.
  - Before: The page had IDA vtable evidence but ungraded validator metadata and no links to the newly split raw helper pages.
  - After: The page records the verified vtable state as reconstructable type data while keeping source reconstruction code blank below the 95+ gate.
  - Evidence: Constructor stores at `0x00564761`, `0x00564767`, and `0x00564771`, xrefs to `0x006240b4`, `0x00624100`, and `0x00624130`, and the current split `ScrollVolumePane` memory pages.
- 2026-06-07: Raised completion from `70` to `74` and set `AUTOGEN_PARENT_UID:0000CO`.
  - Before: The vtable cluster was reconstructable and cross-linked to `ScrollVolumePane`, but it had no autogen parent despite the class and file already clearing the 80/80+ attachment threshold.
  - After: The page is attached to the reconstructable class while leaving reconstruction C++ blank and confidence unchanged.
  - Evidence: [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md) and [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) document the same three vtable views, slider method map, raw helper caveats, and excluded `ScrollablePane` tail.
- 2026-06-13 A002 Goal 2 type-quality refresh:
  - Before: score was `74/86`; the page had correct base addresses and key slots but still used the older parent-gate language and overstated `0x00624134` as a secondary `+0x34` slot.
  - Changed to: `86/89`; parent remains direct class parent [UID:0000CO][ScrollVolumePane](by-class/ScrollVolumePane.md), reconstruction C++ remains blank, and the slot table now treats `0x00624134` as tertiary `+0x04`.
  - Evidence: live IDA MCP `lookup_funcs`, constructor disassembly, `get_int` dword reads across `0x006240b0-0x00624138`, vtable-base/slot-target `xrefs_to`, tail-thunk disassembly, and `tools/int_convert.py` conversions confirm the exact locator dwords, installed vptr offsets, core virtual targets, shared adjustor-thunk entries, and `ScrollablePane` successor boundary.
