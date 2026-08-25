*** UID:0000R9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JU | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ItemHelpPane *g_pItemHelpPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pItemHelpPane

## Status

- Address: [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- Symbol kind: externally linked process-wide singleton pointer definition.
- Direct owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md). A later source split could move the whole ItemHelpPane family to `ui/controls/ItemHelpPane.cpp`, but current code/read-only grouping and family routing rank HelpPanes first.
- Observed aliases: historical saved `g_pItemHelpPane`, older generated `dword_69AE04`, and current stripped IDB `unk_69AE04`.
- Confidence: very strong for exact storage, lifecycle writes/clears, complete reader inventory, external linkage, one-definition ownership, and current parent routing.

## Purpose

`g_pItemHelpPane` points to the active [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), the rich item-tooltip popup. This semantic page emits the sole source definition as `ItemHelpPane *g_pItemHelpPane = NULL;`. External linkage is required because documented readers belong to DialogPane, InventoryPane, ItemMenuDialogs, ArgumentedMenuDialogs, SelfLookPane, and HelpPanes source families. Exact physical storage child [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md) is false/non-emitting and must not duplicate the definition or add a child marker. The constructor publishes the live object, failure/destructor/unwind paths clear it, and replacement/dismissal paths read it before closing or reusing the active item tooltip.

## Evidence Notes

- IDA MCP storage check reports a 4-byte `.data` item at `0x0069ae04` with 20 data references.
- IDA MCP decompilation on 2026-05-27 confirms [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md) closes this singleton through virtual slot `0` with flag `1` when it is non-null.
- 2026-05-28 IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearItemHelpPaneSingleton` at `0x004ce310`, which writes zero to this storage from constructor/destructor unwind cleanup.
- 2026-06-16 C001 safe IDA refresh saved `unk_69AE04 -> g_pItemHelpPane`; post-save `entity_query` confirmed the canonical data label at `0x0069ae04`.
- Live IDA MCP confirms constructor/destructor/clear-helper references, with the exact `0x0069ae04-0x0069ae08` storage claim coming from the IDA-backed by-memory/global documentation.
- 2026-06-13 live IDA MCP recheck on session `a001_goal2_0002UM` confirms the storage as four bytes (`0x4` / 4 bytes, verified with `tools/int_convert.py`) with current bytes/value `00 00 00 00` / `0`. This corrects the older storage-page note that had described the static image as `ff ff ff ff`.
- The same recheck reconfirms all 20 direct xrefs: constructor publish/fallback clear at `0x004c832e` and `0x004c8335`, non-deleting destructor clear at `0x004c8ba1`, `DismissItemHelp` read at `0x004ccc80`, unwind helper clear at `0x004ce310`, scalar deleting destructor clear at `0x004ce4b2`, close-helper read at `0x004a0d40`, one direct read at `0x0049da37`, and item/inventory/tooltip UI read/test paths at `0x004ed0a9`, `0x004ed8f4`, `0x0051af1d`, `0x0051b344`, `0x0051b39e`, `0x0051f39d`, `0x0051f7a4`, `0x0051f7fe`, `0x00520bd0`, `0x00520d00`, `0x00568df1`, and `0x00569885`.
- The complete inventory is five writes and fifteen reads. Writes are constructor publish `0x004c832e`, constructor fallback clear `0x004c8335`, ordinary-destructor clear `0x004c8ba1`, unwind clear `0x004ce310`, and scalar-wrapper clear `0x004ce4b2`. Reads are DialogPane teardown `0x0049da37`, close helper `0x004a0d40`, ItemHelpPane dismiss `0x004ccc80`, InventoryPane close/replace `0x004ed0a9`/`0x004ed8f4`, ServerItem menu teardown/create/no-hit `0x0051af1d`/`0x0051b344`/`0x0051b39e`, ArgumentedMenu teardown/create/no-hit/wrapper `0x0051f39d`/`0x0051f7a4`/`0x0051f7fe`/`0x00520bd0`, ServerItem wrapper close `0x00520d00`, and SelfLook close/test `0x00568df1`/`0x00569885`.
- Constructor disassembly at `0x004c82d0` shows `mov [0x0069ae04], eax` followed by fallback `mov [0x0069ae04], 0` before installing the three `ItemHelpPane` vtables. Non-deleting destructor disassembly frees the stat buffer table at `+0x62c`, then clears the singleton; scalar deleting destructor disassembly clears the singleton after owned-buffer cleanup and before base-pane teardown.
- `DismissItemHelp` (`0x004ccc80`, size `0x15` / 21 bytes, verified with `tools/int_convert.py`) loads `0x0069ae04`, null-checks it, pushes `1`, and calls virtual slot `0`, matching the singleton close-helper behavior.
- ItemHelpPane RTTI has seven descriptors and proves direct `Pane` plus direct empty `Singleton<ItemHelpPane>` inheritance, with Singleton PMD `+0xf8,-1,0` and EventHandler/TimerHandler views at `+0xa0/+0xa4`. Publication and clear stores are compiler lowering of that Singleton lifecycle, not evidence for handwritten raw assignments.
- The source-facing declaration belongs on [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md), while this page owns the one module definition. `NULL` is the strongest project-era initializer spelling; bare zero and `= 0` are behavior-equivalent runner-ups. Rejected forms are file-local `static`, C++11 `nullptr`, `-1`, tentative/duplicate definitions, raw IDA names, address casts, explicit storage placement, and a physical-storage `[[CHILDREN]]` marker.

## Parent And Support Rationale

Keep `CANONICAL_OWNER:0000JU`, `EMITTER_UIDS:0000JU`, and blank position. [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is the current source family; exact storage page [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md) is false/non-emitting and exists only as generated-binary storage evidence. [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) owns the type/declaration surface. The possible whole-family `ItemHelpPane.cpp` split remains unresolved at file-layout confidence only and does not weaken the externally linked one-definition contract.

## Cross-References

- [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md)
- [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:000228][0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers](by-memory/0x004a0d40-0x004a0d71.HelpPaneSingletonCloseHelpers.md)

## Changes

### 2026-05-30 completion/confidence evidence pass

- What existed before: the page had `0` completion/confidence header values despite documenting the storage address, singleton purpose, and IDA-backed close/clear behavior.
- What changed: completion/confidence were raised to `82/85`, and the evidence notes now include lifecycle writes/reads plus the IDA storage binding.
- Summary and evidence: by-memory docs provide IDA-backed `0x0069ae04-0x0069ae08` storage evidence and the singleton lifecycle. The score remains below near-complete because the page does not enumerate every one of the 20 IDA data references.
- 2026-06-05: Marked reconstructable under [UID:0000JU][HelpPanes](by-file/HelpPanes.md). Evidence: live IDA MCP reports 20 xrefs to `0x0069ae04`; decompilation confirms clear helper `0x004ce310` and scalar deleting destructor `0x004ce430` clear `dword_69AE04`, with constructor/close-helper xrefs in the item help pane cluster.
- 2026-06-13 A002 Goal 2 global-quality refresh:
  - Before: score was `82/85`, with storage and lifecycle evidence present but not enough direct xref enumeration or parent-gate rationale for the current `85/85` threshold.
  - Changed to: `86/88`; parent remains [UID:0000JU][HelpPanes](by-file/HelpPanes.md), reconstruction C++ remains blank, and the exact storage byte value is corrected through the storage page.
  - Evidence: live IDA MCP `get_bytes`/`get_int`, `xrefs_to`, `lookup_funcs`, and disassembly confirm a null-initialized four-byte singleton slot, all 20 direct xrefs, constructor publish/fallback clear, destructor/helper clears, close-helper reads, and item/inventory/tooltip UI readers. [UID:0000JU][HelpPanes](by-file/HelpPanes.md) is `90/86`, so the strict direct-parent gate is satisfied.
- 2026-06-16 C001 IDA label sync:
  - Score unchanged at `86/88`.
  - Evidence: C001 saved the evidence-backed IDA data label `g_pItemHelpPane` while refreshing [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md); no type/prototype/member edits were made.
- 2026-06-30 B004 HelpPanes empty-emitter first batch:
  - Added formal singleton declaration `static ItemHelpPane *g_pItemHelpPane = nullptr;` plus `[[CHILDREN]]`.
  - Preserved owner/emitter routing through [UID:0000JU][HelpPanes](by-file/HelpPanes.md) and recorded that exact storage child [UID:0001PD][0x0069ae04-0x0069ae08.g_pItemHelpPane](by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md) is a covered/no-duplicate route, not a second definition.
- 2026-07-21 B004 UID0001PD source-quality callback:
  - Raised the semantic global from `86/88` to `92/94`, retained owner/emitter UID0000JU and blank position, and replaced the historical file-local C++11 form plus child marker with the sole externally linked project-era definition `ItemHelpPane *g_pItemHelpPane = NULL;`.
  - Added exact five-write/fifteen-read roles, direct Pane plus Singleton RTTI/EBO lifecycle evidence, header/source declaration split, initializer ranking, one-definition/source-route reasoning, and rejected static/nullptr/raw/duplicate alternatives while preserving all earlier storage and helper evidence.
