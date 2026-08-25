** TARGET-REPORT-UID:0002DM **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0002DM FittingRoomListPaneOnKeyScroll Source-Quality Report


Report status: Gate 1 passed; implementation callback applied and ready for supervisor execute verification.
Prepared: 2026-07-05T19:09:52-04:00.

## Finalized Report / Current Recommendation

UID0002DM is reconstructable and should remain owned/emitted by [UID:000053] `FittingRoomListPane`. The binary behavior is stable: this is the EventHandler-facet key-scroll handler for the fitting-room list pane, reached through the class vtable, handling translated page-up/page-down key bytes only when the key-state byte is zero, then updating the scrollbar and invalidating the owning pane.

Implemented target score after callback: `COMPLETION:90`, `CONFIDENCE:91`. The supervisor callback explicitly specified `90/91`, and that callback value was applied as the current target metadata.

Recommended metadata:

- Keep `CANONICAL_OWNER:000053`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:000053`.
- Leave `EMITTER_POSITION_OPTIONAL:` unchanged unless the supervisor wants a separate source-order placement policy for this class.

The post-callback target formal C++ now uses the supported pane key event spelling: `PaneKeyEvent`, `kPaneKeyDown`, `event->payload[0]`, `event->keyState`, `g_pEventMan->TranslateEventKey(...)`, and project-wide `kPaneKeyPageUp` / `kPaneKeyPageDown`. The stale `EventRecord`, `EventType_KeyDown`, `NarrowEventKeyByte`, `fallbackByte`, and FittingRoom-local page-key names are retained in this report only as historical/rejected alternatives, not as current target state.

## Supporting Research

Required support docs checked:

- `by-class/FittingRoomListPane.md`
- `by-file/FittingRoom.md`
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
- `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md`
- `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`
- `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md`
- `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`

Additional consistency docs checked because the user explicitly asked to re-evaluate EventRecord field names, key enum names, and ctype narrowing wrapper naming:

- `by-class/EventMan.md`
- `by-file/Event.md`
- `by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`
- `by-memory/0x004eee60-0x004eeedc.InventoryPane2OnKeyEvent.md`
- `by-memory/0x0057edb0-0x0057ee2c.SpellInventoryPane2OnKeyEvent.md`
- `by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md`
- `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`
- `by-memory/0x0066d888-0x0066da88.EventManKeyTranslationTables.md`

Current generated read-only state checked:

- Current post-callback generated output is `auto-generated/NexusTK/cashshop/FittingRoom.cpp`, validator command id `000000007345`, refreshed `2026-07-05T19:27:09-04:00`, refresh source `deferred-generated-refresh`.
- Current generated UID0002DM state is `Completion:90 | Confidence:91` and includes `PaneKeyEvent *event`, `g_pEventMan->TranslateEventKey`, `kPaneKeyPageUp`, and `kPaneKeyPageDown`.
- Historical report-only lead: pre-callback generated output at command id `000000007322`, refreshed `2026-07-05T18:54:51-04:00`, still reflected the old stale formal C++ names before the accepted implementation callback. That is no longer the current generated state.

## Target

- UID: `0002DM`
- Target doc: `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`
- Current address range: `0x0041fba0-0x0041fcc5`
- Current function in IDA: `sub_41FBA0`
- Current source placement: `NexusTK/cashshop/FittingRoom.cpp` through [UID:0000JE] and [UID:000053]

## Current Target State

Post-callback current metadata in the target:

- `COMPLETION:90`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:000053`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000053`

Post-callback target state:

- The target now has a formal C++ block for `FittingRoomListPane::OnKeyScroll(PaneKeyEvent *event)` using `kPaneKeyDown`, `payload[0]`, `keyState`, `g_pEventMan->TranslateEventKey`, `kPaneKeyPageUp`, and `kPaneKeyPageDown`.
- The Item Summary, Summary, Layout, Evidence, Reconstruction Notes, Score Rationale, and Changes now carry the callback evidence instead of the stale blank-parent / no-final-C++ wording.
- The old `EventRecord`, `EventType_KeyDown`, `NarrowEventKeyByte`, `fallbackByte`, `kFittingRoomKeyPageUp`, `kFittingRoomKeyPageDown`, and CRT `std::ctype<char>::do_narrow` source interpretations are no longer current target claims; they are preserved only as rejected/stale alternatives in this report.
- Remaining current limits are nonblocking source-spelling caps: exact original event field names and exact original method spelling remain inferred, and the IDA helper symbol still has stale ctype naming even though the target docs now use the project key-translation interpretation.

## Heuristic / Inference Reanalysis And Validation

### Receiver Adjustment

Live MCP disassembly confirms the incoming `ecx` is the EventHandler secondary facet pointer, not the complete `FittingRoomListPane` base:

- At `0x0041fba9`, `edi = ecx`.
- Display mode is read at `[edi+0x6c]`, which is complete-object `base+0x10c` if `base = edi - 0xa0`.
- Scroll position is updated at `[edi+0x68]`, which is complete-object `base+0x108`.
- `UpdateScrollBar` is called with `ecx = edi - 0xa0` at `0x0041fbfc-0x0041fc02`.
- The invalidate virtual call also uses `ecx = edi - 0xa0` at `0x0041fc11-0x0041fc17`.

The target formal C++ should continue to present a normal `FittingRoomListPane::OnKeyScroll(...)` member on the complete object. It should not expose the decompiler's secondary-facet `this` adjustment in source.

### Event Field Names

Live MCP confirms exact offsets:

- `event+0x04` is compared with `8` at `0x0041fbab`.
- `event+0x08` is loaded as the key byte at `0x0041fbc6`.
- `event+0x10a` is loaded before the helper call at `0x0041fbb8`; MCP `int_convert` verifies `0x10a` is decimal `266`.
- `event+0x10a` is then checked against zero before either page-up or page-down is accepted at `0x0041fbd4` and `0x0041fc2b`.

Current project support favors `PaneKeyEvent`-style names over the target's pre-callback `EventRecord` names:

- `ParcelPaneOnKeyDown` uses `PaneKeyEvent`, `eventKind`, `payload[0]`, and `keyState` for the same helper pattern.
- `InventoryPane2OnKeyEvent` and `SpellInventoryPane2OnKeyEvent` use `PaneKeyEvent` and `kPaneKeyDown` for the same page-key family.
- Event support documents type `8` as the key-down event.

Recommended and now-applied source names for this target:

- `PaneKeyEvent *event`
- `event->eventKind`
- `kPaneKeyDown`
- `event->payload[0]`
- `event->keyState`

Remaining cap: the exact original field spelling for `event+0x10a` is still not proven from symbols. `keyState` is the strongest local/project spelling because the byte is passed as the second argument to the project key translation helper; inventory pages sometimes describe a related zero/nonzero byte as `imeActive`.

### Key Translation / Ctype Narrowing Wrapper Naming

IDA still labels `0x004a8b10` as `?do_narrow@?$ctype@D@std@@MBEDDD@Z_0`, but live MCP and current EventMan support show this should not be documented as CRT ownership:

- UID0002DM loads `dword_67A754` into `ecx`, pushes `event+0x10a`, pushes `event+0x08`, and calls `0x004a8b10` at `0x0041fbcb`.
- MCP `analyze_function 0x004a8b10` shows the helper body is only `mov al, [ebp+arg_0]; retn 8`; it returns the first byte argument and ignores the second stack argument.
- MCP `xrefs_to 0x004a8b10` found `81` callers across pane/handler routes, including UID0002DM at `0x0041fbcb`.
- `EventMan.md` and `EventManAndEventFactoryHelpers.md` already resolve this helper as the project key translation adaptor, recommended as `EventMan::TranslateEventKey` / `TranslateEventKeyByte`, not real CRT `std::ctype` source ownership.

Recommended and now-applied formal C++ calls `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)` directly. A local target-only wrapper named `NarrowEventKeyByte` is rejected. If the project later centralizes event helpers, the wrapper spelling should align with existing project pages such as `NarrowInputEventByte` or `NarrowPaneKey`, but this target does not need to invent one.

### Key Enum Names For 0x93 / 0x94

Live MCP disassembly compares the translated byte with `0x93` at `0x0041fbd0` and `0x94` at `0x0041fc23`. MCP `int_convert` with 4-byte width confirms:

- `0x93` = decimal `147`
- `0x94` = decimal `148`

The constants should be project-wide pane key names:

- `kPaneKeyPageUp` for `0x93`
- `kPaneKeyPageDown` for `0x94`

The pre-callback target names `kFittingRoomKeyPageUp` and `kFittingRoomKeyPageDown` were behaviorally understandable but too local. Inventory and spell-inventory support use the shared pane page-key spelling, and `EventManKeyTranslationTables` owns the project-wide translated-key table.

### Page-Size Constants

Live MCP disassembly confirms:

- Row mode page size is `0x1a` / `26`; MCP `int_convert` verifies `0x1a` = decimal `26`.
- Grid mode page size is `3`.
- Grid column count is `6`.
- Display mode test uses `[secondary_this+0x6c]`, complete object `base+0x10c`.

The current page-size names are acceptable and should be kept:

- `kFittingRoomRowPageSize = 26`
- `kFittingRoomGridPageRows = 3`
- `kFittingRoomGridColumns = 6`

### Item-Count Route

Live MCP confirms page-down uses the total item count route, not enabled count:

- `0x0041fc38` loads `g_pFittingRoomDialog` from `dword_67A73C`.
- `0x0041fc3d` pushes the active category from `dialog+0x784`.
- `0x0041fc43` forms `dialog+0x504`.
- `0x0041fc49` calls `sub_422690`.
- MCP `analyze_function 0x00422690` shows `sub_422690` is a count helper returning `(end - begin) >> 2` or zero when the category lookup misses.
- `UpdateScrollBar` support also calls `sub_422690` for total count and separately computes enabled count, matching the target's page-down max clamp route.

The target should explicitly state that UID0002DM page-down clamps against total catalog entries for the active fitting-room category, while `UpdateScrollBar` owns the enabled-count recalculation.

### Boundary And Xrefs

Live MCP evidence:

- `lookup_funcs 0x0041fba0` returns `sub_41FBA0`, size `0x125` / decimal `293`.
- `lookup_funcs 0x0041fcc5` returns `Not a function`.
- `lookup_funcs 0x0041fcd0` returns successor `sub_41FCD0`, size `0xafe`.
- `get_bytes 0x0041fb9b size 319` returns five leading `0xcc` bytes before `0x0041fba0`, the complete function body, then eleven `0xcc` bytes before successor bytes begin at `0x0041fcd0`.
- `xrefs_to 0x0041fba0` returns exactly one data xref: `0x0060dd80`.
- `xrefs_to 0x0041fcd0` returns exactly one data xref: `0x0060dd7c`.
- `get_bytes 0x0060dd78 size 16` decodes adjacent vtable cells as `0x004213e2`, `0x0041fcd0`, `0x0041fba0`, `0x0041d6b0`.
- `get_int u32le 0x0060dd80` returns decimal `4324256`, and MCP `int_convert` verifies this is `0x0041fba0`.

No direct ordinary code caller exists. Vtable reachability is sufficient for method ownership under `FittingRoomListPane`; it is not evidence for EventMan, EventHandler, or generic Pane ownership.

## Evidence Standards Used

Evidence used in this report follows the project B-agent workflow:

- Live MCP evidence is mandatory and was collected from the active IDA MCP session before writing recommendations.
- Current by-* support docs were used to resolve source naming and ownership, but not as substitutes for live MCP facts.
- Generated files and tracker files were inspected read-only only for current state and consistency.
- During the original report-only pass, validators were not run and no by-* implementation edits were performed.
- During the accepted implementation callback, by-* edits were performed only in the accepted target/support scope, and scoped validators were run only for changed by-* docs.
- Lease/process note for the implementation callback: accepted by-* docs were edited, and final lease cleanup/inspection found no active B010 leases remaining. If an edit batch lacked an active recorded lease, that is a process note for supervisor review; it is not a claim that by-* edits did not happen.
- During the later report-text repair passes, no by-* docs were edited, no leases were needed, and no validators were run.
- Across report-only, callback, and repair passes, no `execute_report`, dry-run/probing execute variant, registry lifecycle command, manual report move, archive move, generated edit, coverage edit, validator-state hand edit, or supervisor-ledger edit was performed.

## Evidence Checked

Live MCP session:

- Session id: `supervisor_recovery_20260705`
- MCP health: `status=ok`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Auto analysis: ready
- Hex-Rays: ready
- Strings cache: ready, size `2067`

MCP calls and relevant results:

- `lookup_funcs`: `0x0041fba0` -> `sub_41FBA0` size `0x125`; `0x0041fcc5` not a function; `0x0041fcd0` -> `sub_41FCD0`; `0x0041ee10` -> `sub_41EE10`; `0x00422690` -> `sub_422690`; `0x004a8b10` -> stale IDA name `?do_narrow@?$ctype@D@std@@MBEDDD@Z_0`.
- `analyze_function 0x0041fba0 include_asm=true`: confirmed event guard, key helper call, page-up/page-down constants, receiver adjustment, item-count call, scrollbar call, invalidate call, vtable-only xref, no code callers.
- `xrefs_to`: `0x0041fba0` has one data xref at `0x0060dd80`; `0x0041fcd0` has one data xref at `0x0060dd7c`; `0x0041ee10` has nine code xrefs including UID0002DM at `0x0041fc02`; `0x00422690` has five code xrefs including UID0002DM at `0x0041fc49`; `0x004a8b10` has 81 code xrefs including UID0002DM at `0x0041fbcb`.
- `get_bytes 0x0041fb9b size 319`: confirmed five leading `0xcc`, function body, eleven trailing `0xcc`, and successor prologue.
- `get_bytes 0x0060dd78 size 16`: confirmed vtable dwords around the target slot.
- `get_int u32le`: `0x0060dd7c` = `4324560` / `0x0041fcd0`; `0x0060dd80` = `4324256` / `0x0041fba0`; `0x0060dd84` = `4314800` / `0x0041d6b0`.
- `analyze_function 0x004a8b10`: confirmed helper returns first argument and has no callees.
- `analyze_function 0x00422690`: confirmed count-helper route.
- `analyze_function 0x0041ee10`: confirmed support-side total-count route and row/grid page-size consistency.

## Claim And Incorporation Ledger

| Claim | Evidence | Verification State | Incorporation Recommendation |
|---|---|---|---|
| UID0002DM boundary is `0x0041fba0-0x0041fcc5`, size `0x125`. | MCP `lookup_funcs`, `get_bytes`; successor `0x0041fcd0`. | Applied in `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`; already supported by target raw evidence and refreshed B010 MCP section. | Target Boundary/Raw Evidence and score rationale updated. |
| The only xref to `0x0041fba0` is vtable data at `0x0060dd80`. | MCP `xrefs_to 0x0041fba0`; vtable bytes/int reads. | Applied in target and support notes. | Vtable-method ownership preserved; ordinary caller claims rejected. |
| The handler receives an EventHandler secondary-facet `this`; source should present normal complete-object method. | MCP disassembly: `edi=ecx`, `lea ecx,[edi-0xa0]` for calls. | Applied in target Reconstruction Status/Behavior and support notes. | Formal C++ uses normal `FittingRoomListPane::OnKeyScroll`. |
| `event+0x04` is key-down type 8. | MCP disassembly `cmp byte ptr [esi+4],8`; Event/EventMan support. | Applied in target formal C++ as `PaneKeyEvent` / `kPaneKeyDown`. | Stale `EventType_KeyDown` removed from formal C++. |
| `event+0x08` is the translated-key input byte and `event+0x10a` is the key-state byte. | MCP disassembly loads `[esi+8]` and `[esi+0x10a]`; support precedent. | Applied in target formal C++ and notes as `payload[0]` / `keyState`; exact spelling remains confidence cap. | Stale `keyByte/fallbackByte` removed from formal C++. |
| `0x004a8b10` should be documented as project key translation, not CRT `std::ctype` ownership. | MCP helper body returns first arg, 81 callers; EventMan support docs. | Applied in target formal C++ and support notes. | `g_pEventMan->TranslateEventKey` used; ctype kept only as stale IDA-name evidence/rejection. |
| Key bytes `0x93` and `0x94` are page-up/page-down translated pane keys. | MCP byte comparisons; EventMan tables and inventory/spell-inventory precedent. | Applied in target formal C++ and support notes. | `kPaneKeyPageUp` and `kPaneKeyPageDown` used; FittingRoom-local key names rejected. |
| Row page size is 26, grid page rows is 3, grid columns is 6. | MCP disassembly constants; MCP int conversion; UpdateScrollBar support. | Applied/already-present in target formal C++ and notes. | Fitting-room page-size constants preserved. |
| Page-down uses total active-category item count from `g_pFittingRoomDialog->m_itemState`, not enabled count. | MCP call at `0x0041fc49`; `sub_422690` analysis; UpdateScrollBar support. | Applied in target and UpdateScrollBar support note. | Total-count route documented; enabled-count route rejected for page-down clamp. |
| Owner/emitter should remain [UID:000053] under `cashshop/FittingRoom.cpp`. | Support docs and vtable/data ownership; no new owner evidence. | Applied/already-present. | Metadata kept `CANONICAL_OWNER:000053`, `EMITTER_UIDS:000053`; file/class support unchanged. |
| Pre-callback target summary/status prose was stale and contradicted the accepted formal C++ direction. | Target doc read. | Applied. | Item Summary/Summary/Reconstruction Status/Score Rationale/Changes updated. |
| Pre-callback support docs were mostly consistent, with small stale support wording around code-entry status. | Required support docs read. | Applied narrowly. | Updated `FittingRoomListPane.md`, `FittingRoom.md`, `FittingRoomUiCore.md`, and `FittingRoomListPaneUpdateScrollBar.md`; no other support edits needed. |

## Positive Evidence Summary

- Exact function boundary, vtable slot, successor boundary, and padding are live-confirmed.
- The behavior is simple and fully reconstructable: guard key-down, translate key byte, accept only page up/down with zero key-state byte, adjust scroll, refresh scrollbar, invalidate.
- Receiver adjustment is fully explained by the EventHandler secondary facet, and the source should keep a normal `FittingRoomListPane` method shape.
- Item-count route is live-confirmed and agrees with `UpdateScrollBar`.
- Event/key support docs provided stronger source names than the pre-callback target C++; those names are now applied in the target C++.
- Existing file/class ownership already points to `FittingRoomListPane` and `cashshop/FittingRoom.cpp`; no competing ownership evidence survived reanalysis.

## Negative Evidence Summary

- No ordinary code xrefs call `0x0041fba0`; it is a vtable method.
- The IDA symbol name at `0x004a8b10` is not enough to assign CRT source ownership; the helper's body, caller profile, and EventMan docs reject that.
- `EventMan`, EventHandler, generic Pane, ItemCatalog, ScrollBar, and `g_pFittingRoomDialog` are dependencies, not owners/emitters of UID0002DM.
- The active-category count route uses total catalog count; it is not the enabled-count value computed by `UpdateScrollBar`.
- The pre-callback target's FittingRoom-local page-key names are not supported as original/shared enum names; project-wide pane keys are now applied.
- The exact original method name and exact `event+0x10a` field spelling remain inferred; this prevents a 95+ confidence claim.

## Ranked Ownership Analysis

1. [UID:000053] `FittingRoomListPane` - strongest owner. The vtable slot sits in the class dispatch area, the receiver adjustment returns to the complete pane object, and all field accesses are `FittingRoomListPane` fields.
2. [UID:0000JE] `cashshop/FittingRoom.cpp` - source-file owner for the class and method family. This is the correct file-level placement, not a target-level owner replacement.
3. EventMan/Event/EventHandler - support dependencies only. They explain event/key names and helper semantics but do not own the fitting-room list-pane scroll method.
4. ItemCatalog/FittingRoomDialog/global dialog pointer - support dependencies only. They provide active category and count data for page-down clamp.
5. CRT `std::ctype<char>` - rejected. IDA naming is stale/misleading for source ownership and should not drive target reconstruction.

## Source Placement

Recommended source placement remains:

- File: `NexusTK/cashshop/FittingRoom.cpp`
- Class owner: `FittingRoomListPane`
- Method: `FittingRoomListPane::OnKeyScroll`

No evidence supports moving this target to EventMan, Event.cpp, ItemCatalog, ScrollBar, a generic Pane file, or a standalone helper source file.

Method-name caveat: `OnKeyScroll` remains the established local descriptive name. Related pane pages sometimes use `OnKeyEvent`/`OnKeyDown`, but there is no new live evidence strong enough to rename this target across file/class docs during this pass.

## First-Draft C++ Recommendation

Replace the target formal C++ block with this report-level source spelling:

```cpp
bool FittingRoomListPane::OnKeyScroll(PaneKeyEvent *event)
{
    if (event->eventKind != kPaneKeyDown) {
        return false;
    }

    const unsigned char key =
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);
    if (event->keyState != 0) {
        return false;
    }

    const bool rowMode = (m_displayMode == FittingRoomListDisplayMode_Rows);
    const short pageSize = static_cast<short>(
        rowMode ? kFittingRoomRowPageSize : kFittingRoomGridPageRows);

    if (key == kPaneKeyPageUp) {
        short nextPosition = static_cast<short>(m_scrollPosition - pageSize);
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    if (key == kPaneKeyPageDown) {
        FittingRoomDialog *dialog = g_pFittingRoomDialog;
        FittingRoomDialogItemState *itemState = &dialog->m_itemState;
        const unsigned char category =
            static_cast<unsigned char>(dialog->m_activeCategory);
        const short totalItems = itemState->GetItemCount(category);

        short nextPosition = static_cast<short>(m_scrollPosition + pageSize);
        const int maxPosition = rowMode
            ? (totalItems - pageSize)
            : (((totalItems + (kFittingRoomGridColumns - 1)) /
                    kFittingRoomGridColumns) - pageSize);

        if (nextPosition > maxPosition) {
            nextPosition = static_cast<short>(maxPosition);
        }
        if (nextPosition < 0) {
            nextPosition = 0;
        }

        m_scrollPosition = nextPosition;
        UpdateScrollBar();
        Invalidate();
        return true;
    }

    return false;
}
```

Notes for implementation:

- The helper call is deliberately before the zero key-state check to match the binary call order.
- `PaneKeyEvent`, `eventKind`, `payload[0]`, and `keyState` are source-quality recommendations from support consistency; exact original field spellings remain a confidence cap.
- Do not add a target-local `NarrowEventKeyByte` helper. If a shared wrapper is later required, reuse a project-consistent name from existing event support.
- Do not rename the owner or move this method out of `FittingRoomListPane`.

## Final Recommendation

Gate 1 passed and the implementation callback has been applied. The target graduated from stale 86/89 wording to `90/91` per the supervisor callback, with a formal C++ block that reflects current EventMan and pane-key support.

No MCP/tool-state blocker exists. Remaining uncertainties are nonblocking source-spelling caps:

- Exact original `PaneKeyEvent` field names are inferred from support, not symbols.
- Exact original method spelling `OnKeyScroll` remains descriptive/local rather than symbol-proven.
- The EventMan helper's IDA name remains stale until someone chooses to rename/type it in IDA or support docs, but target reconstruction should not wait on that.

## Recommended Target Doc Changes

Callback disposition for `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`:

1. Applied: target metadata is now `COMPLETION:90` and `CONFIDENCE:91` per supervisor callback metadata.
2. Already present / retained: `CANONICAL_OWNER:000053`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000053`.
3. Applied: the formal C++ block now matches the recommended block above.
4. Applied: Item Summary and Summary no longer present the stale "blank parent" / "final C++ intentionally blank until 95+" wording as current state.
5. Applied: live MCP evidence from session `supervisor_recovery_20260705` was added, including health OK, exact boundary, padding, vtable-only xref, receiver adjustment, key-event offsets, key helper, page-key constants, item-count route, and support-call route.
6. Applied: stale `std::ctype<char>::do_narrow` source wording was replaced with project key translation wording.
7. Applied: `EventRecord`, `EventType_KeyDown`, `keyByte`, `fallbackByte`, and `NarrowEventKeyByte` prose was replaced or rejected in favor of `PaneKeyEvent`, `kPaneKeyDown`, `payload[0]`, `keyState`, and `EventMan::TranslateEventKey` / `TranslateEventKeyByte` wording.
8. Applied: FittingRoom-local page-key names were replaced or rejected in favor of project-wide `kPaneKeyPageUp` and `kPaneKeyPageDown`.
9. Applied: page-down is documented as using total active-category item count from `ItemCatalog::GetItemCount`, not enabled count.
10. Applied: receiver-adjustment notes preserve the binary secondary facet `ecx` while keeping source as a complete-object method.
11. Applied: rejected owners are preserved/re-stated: EventMan/EventHandler/generic Pane/ItemCatalog/ScrollBar/global dialog/CRT ctype.
12. Applied: Score Rationale and Changes now carry the current report details and nonblocking source-spelling caps.

## Recommended Support Doc Changes

Implementation callback support-doc disposition:

- Applied: `by-class/FittingRoomListPane.md` now carries the UID0002DM row/note with `PaneKeyEvent`, `kPaneKeyDown`, `kPaneKeyPageUp`, `kPaneKeyPageDown`, and `EventMan::TranslateEventKey`; class owner/source placement stayed unchanged.
- Applied: `by-file/FittingRoom.md` now includes the source-context note that UID0002DM's key-scroll method uses the project EventMan key translation helper and shared pane page-key names; [UID:0000JE] ownership stayed unchanged.
- Applied: `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` now refreshes the relevant covered-range/source-quality row with translated pane keys and the total-count page-down clamp; no score change was required.
- Applied: `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md` now removes stale blank-parent/no-final-C++ wording and records the consistency distinction that UID0002DM uses the total-count route for page-down clamp while UpdateScrollBar owns enabled-count refresh.
- Already present / no edit required: `by-memory/0x0041fcd0-0x004207ce.FittingRoomListPaneOnInputEvent.md` already routes key-down handling to UID0002DM.
- Already present / no edit required: `by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md` already documents the count helper and includes the UID0002DM caller.
- Already present / no edit required: `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md` already documents the global pointer used by UID0002DM.
- Already present / excluded with reason: Event/EventMan support docs already contain the current helper interpretation, so the callback did not broaden into those support docs.

No additional support-doc edit remains pending from the accepted report.

## Score And Metadata Recommendation

Recommended target metadata:

```text
COMPLETION:90
CONFIDENCE:91
CANONICAL_OWNER:000053
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:000053
```

Rationale:

- Completion rises because behavior, boundary, owner, vtable reachability, receiver adjustment, item-count route, and formal C++ are all reconstructable with live evidence.
- Confidence rises because the stale ctype/helper issue is now resolved by current EventMan support and live helper analysis.
- Confidence stays below 95 because exact source spelling for the event structure fields and method name is still inferred from support rather than symbol evidence.

## Open Questions With Attempted Resolution

- Exact event field names: attempted by checking Event, EventMan, inventory, spell-inventory, chatting, and parcel key-handler support. Best recommendation is `PaneKeyEvent`, `eventKind`, `payload[0]`, and `keyState`; exact original spelling remains a cap.
- Exact key enum names: attempted by checking EventMan key tables and pane key-handler support. Best recommendation is project-wide `kPaneKeyPageUp` / `kPaneKeyPageDown`, not fitting-room-local names.
- Exact ctype/narrow helper name: attempted by live helper decompile, xref inventory, and EventMan support. Best recommendation is `EventMan::TranslateEventKey` / `TranslateEventKeyByte`; target should not invent `NarrowEventKeyByte`.
- Exact method name: checked local class/file support and sibling handlers. `OnKeyScroll` should remain for now; no stronger symbol evidence supports a rename.
- Support consistency: checked required support docs; the callback applied narrow wording cleanup where needed, found several support docs already consistent, and did not require any support ownership or source-file split change.

## Validator Results

Scoped validators run from `source-3/project-documentation` during the implementation callback:

| File | Command ID | Timestamp | Exit | ok | Notes |
|---|---:|---|---:|---:|---|
| `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md` | `000000007341` | `2026-07-05T19:26:39-04:00` | 0 | 1 | Ran with `--wait-generated`; generated refresh completed; target score updated to `90/91`; `FittingRoom.cpp` updated. |
| `by-class/FittingRoomListPane.md` | `000000007342` | `2026-07-05T19:26:58-04:00` | 0 | 1 | Generated refresh deferred; no target-specific warnings. |
| `by-file/FittingRoom.md` | `000000007343` | `2026-07-05T19:26:59-04:00` | 0 | 1 | Existing `missing_ref_uid 0003AM` warnings x4 remain unrelated to UID0002DM. |
| `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md` | `000000007344` | `2026-07-05T19:27:01-04:00` | 0 | 1 | Generated refresh deferred; no target-specific warnings. |
| `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md` | `000000007345` | `2026-07-05T19:27:09-04:00` | 0 | 1 | Generated refresh deferred; no target-specific warnings. |

Generated refresh/freshness:

- Queue status command `000000007348` at `2026-07-05T19:27:40-04:00` showed queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, and processing generated refresh jobs `0`.
- `auto-generated/NexusTK/cashshop/FittingRoom.cpp` is read-only inspected with header `validator-command-id: 000000007345`, `validator-refreshed-at: 2026-07-05T19:27:09-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Generated UID0002DM now shows `Completion:90 | Confidence:91`, `PaneKeyEvent *event`, `g_pEventMan->TranslateEventKey`, `kPaneKeyPageUp`, and `kPaneKeyPageDown`.
- Read-only generated search found no remaining `NarrowEventKeyByte`, `EventRecord`, `kFittingRoomKeyPage*`, or `fallbackByte` in `auto-generated/NexusTK/cashshop/FittingRoom.cpp`.

No `execute_report`, dry-run/probing execute variant, lifecycle/archive command, manual report move, generated hand edit, coverage hand edit, validator-state hand edit, or supervisor-ledger edit was run.

## Changed Files

Implementation-callback changed files:

- `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`
- `by-class/FittingRoomListPane.md`
- `by-file/FittingRoom.md`
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
- `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`
- `tools/leaser/Agents/Agent-B010/research/0002DM-FittingRoomListPaneOnKeyScroll-source-quality.md`

Validator-owned side effects were produced by scoped validators, including refreshed generated reports/source and validator registry metadata. No generated files, coverage reports, validator state files, lifecycle/archive files, or supervisor ledgers were edited by hand.

## Implementation Tracking Checklist

- [x] Read updated `goal.md` and project-level `ntk-b-agent-workflow` instructions.
- [x] Read target doc.
- [x] Read required support docs.
- [x] Re-evaluate receiver adjustment/source spelling.
- [x] Re-evaluate EventRecord field names.
- [x] Re-evaluate key enum names for `0x93` / `0x94`.
- [x] Re-evaluate ctype/key-translation helper naming.
- [x] Re-evaluate page-size constants and item-count route.
- [x] Re-evaluate support consistency and owner/emitter/source placement.
- [x] Collect mandatory live MCP evidence from current session.
- [x] Produce report-only Gate 1 report.
- [x] Apply target by-* edits. Applied to `by-memory/0x0041fba0-0x0041fcc5.FittingRoomListPaneOnKeyScroll.md`: metadata `90/91`, formal C++ replacement, receiver-adjustment/source-shape evidence, key-event/helper analysis, score rationale, rejected alternatives, open-question caps, and changes note.
- [x] Apply support doc edits. Applied narrowly to `by-class/FittingRoomListPane.md`, `by-file/FittingRoom.md`, `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`, and `by-memory/0x0041ee10-0x0041f0b0.FittingRoomListPaneUpdateScrollBar.md`; no edits needed for OnInputEvent, ItemCatalogLookup, g_pFittingRoomDialog, or Event/EventMan support because they were already consistent or explicitly not required.
- [x] Run validators. Scoped validators `000000007341` through `000000007345` exited 0 with `ok: 1` for each changed by-* file.
- [x] Inspect generated output after validation. `auto-generated/NexusTK/cashshop/FittingRoom.cpp` refreshed at command `000000007345`, includes updated UID0002DM C++, and contains no stale target key-helper names.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000007376","destination_path":"executed-b-agent-research/B010/0002DM-FittingRoomListPaneOnKeyScroll-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0002DM-FittingRoomListPaneOnKeyScroll-source-quality.md","timestamp":"2026-07-05T20:03:56-04:00","uid":"0002DM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
