** TARGET-REPORT-UID:0002EP **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 ChattingPane Core Source-Quality Research

Assignment: `B003-goal2-chatting-pane-core-source-quality-0002EP-0002EU-0002EW-20260617`  
Agent: `Agent-B003`  
Date: 2026-06-17  
Scope: report-only B-agent research for `0002EP`, `0002EU`, and `0002EW`.

## Finalized Report / Current Recommendation

All three assigned targets should remain reconstructable, should keep `CANONICAL_OWNER:00001X`, and should keep `EMITTER_UIDS:00001X`. The route is still `ChattingPane` -> [UID:0000I5][Chatting] -> `auto-generated/NexusTK/social/Chatting.cpp`.

The old blank-C++ state is no longer the best recommendation. These targets already clear the active combined-score code gate (`82/90`, average `86.0`) and the remaining source-name uncertainty is bounded enough to use role-based first-draft names. The formal blocks should be populated with first-draft C++ for all three targets, with the names marked as source-facing/provisional where original spelling is not proven.

Recommended before/after summary:

| UID | Target | Current | Recommended | Owner | Emitter | Reconstructable | Formal C++ |
| --- | --- | ---: | ---: | --- | --- | --- | --- |
| `0002EP` | `ChattingPaneDestructor` | `82/90` | `86/90` | keep `00001X` | keep `00001X` | keep `TRUE` | populate |
| `0002EU` | `ChattingPaneChatPacketRouter` | `82/90` | `86/90` | keep `00001X` | keep `00001X` | keep `TRUE` | populate |
| `0002EW` | `ChattingPaneSetVisibleRowCount` | `82/90` | `86/90` | keep `00001X` | keep `00001X` | keep `TRUE` | populate |

No split-first workflow is required. Each target is already an exact child function page, and none mixes unrelated functions or data that must be split before a supervisor edit.

## Supporting Research

Primary target docs rechecked:

- [UID:0002EP] `by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md`
- [UID:0002EU] `by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md`
- [UID:0002EW] `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`

Required related pages rechecked:

- [UID:0002EO] `ChattingPaneConstructor`
- [UID:0002EQ] `ChattingPaneAddChattingMessage`
- [UID:0002ER] `ChattingPaneAddIncomingMessage`
- [UID:0002ES] `ChattingPaneScrollMetricVirtuals`
- [UID:0002EV] `ChattingPaneOnPaint`
- [UID:0002EX] `ChattingPaneComputeLineCount`
- [UID:0002F0] `ChatPacketType10Handler`
- [UID:0002EZ] `ChatPacketType13Handler`
- [UID:000104] `ChattingUI`
- [UID:00001X] `ChattingPane`
- [UID:0000I5] `Chatting`
- Chatting singleton/global docs: `g_pChattingDisplayPane`, `g_pChattingBackPane`, `g_pChattingModifyHeightPane`, `g_pChattingVarietyPane`, `g_pChattingVarietySelectPane`, `g_pChattingHandlePane`, `g_pChatInputPane`, and the mixed UI singleton-slot aggregate.
- `ChattingVtableData`
- `ColorStringChattingMessage` and its constructor.
- Current coverage rows in `by-memory/-coverage-report.md`.
- Generated coverage route rows in `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, and `auto-generated/-ag-file-coverage.md`.
- Current generated file `auto-generated/NexusTK/social/Chatting.cpp`.

Prior B-agent reports rechecked as historical research, not copied forward:

- B001 `0002EO-0002ES-chatting-message-ingress-source-quality.md`
- B001 `0002EX-0002F0-chatting-source-quality-20260615.md`
- B003 variety-pane source-quality report
- B002 raw-helper/source-placement report

Live IDA MCP was attempted but unavailable from this session. The local read-only PE evidence below was checked directly against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` and was used to validate boundaries, padding, and relative call/jump targets. Existing target docs still carry previous live IDA MCP facts, including xref and vtable-slot observations.

## Supervisor Active Recheck

Active project-level rows still list the assigned targets at `82/90`, average `86.0`, with nonblank emitter route through `00001X` to `Chatting.cpp`. Current generated output does not contain these function bodies; it only contains unrelated partial class declarations for the Chatting variety panes. Therefore this report recommends source-quality upgrades and formal C++ blocks, but no generated-file edit.

`by-memory/-coverage-report.md` currently records all three as reconstructable with `strong` confidence and notes blank final C++ for `0002EP` and `0002EU`. Those row notes are now stale because the source-quality blockers have been resolved to bounded role-name choices.

## Inference Research Guidance Check

The governing inference guidance says not to carry old uncertainty forward when a high-probability name or source shape is defensible from behavior, cross-references, field use, and sibling functions. The same guidance also distinguishes:

- Original-proof names, which require direct source/symbol evidence.
- High-probability source-facing names, which are acceptable when they preserve behavior and are explicitly marked as inferred.
- Unsafe formal C++, which should stay blank only when source shape, owner, dependencies, or exact range boundaries are too unclear.

The three assigned targets are not unsafe for formal C++:

- Function boundaries and padding are exact.
- Owner and emitter route are stable.
- Field roles are corroborated across constructor, destructor, add-message, paint, line-count, scroll-metric, and resize callers.
- The router's packet types and tail targets are exact.
- The only remaining uncertainty is spelling of original method/member/helper names, not source shape.

## Heuristic / Inference Reanalysis And Validation

### Source-facing member names

`this + 0x130` is the ChattingPane-owned message list. The best source-facing member name is `m_pChatMessageList`; `m_chatMessageList` is also acceptable if the project style avoids Hungarian-style pointer prefixes. The type should be documented as the project's generic `List *` containing owned `ColorStringChattingMessage *` entries.

Evidence:

- [UID:0002EO] allocates a `0x14` byte list with `sub_4F4AA0`, initializes it with `sub_4F3060(list, 4, 1000)`, stores it at `this + 0x130`, and seeds it with blank `ColorStringChattingMessage` entries.
- [UID:0002EQ] and [UID:0002ER] create/clone `ColorStringChattingMessage` values and insert owned pointers into this list.
- [UID:0002EP] reads count from list offset `+0x0c`, fetches each element through list vslot `+0x10`, calls each message deleting destructor with flag `1`, deletes the list object through list vslot `+0x00`, and clears `this + 0x130`.
- [UID:0002EV] and [UID:0002EX] iterate the same list for paint and line-count measurement.

Rejected alternatives:

- `m_chatLineList`: rejected because stored elements are message objects, not line fragments. Line count is computed by each message's measurement virtual and current width.
- `m_chatEntryList` / `ChatEntryList`: rejected because the documented concrete element class is `ColorStringChattingMessage`, and the allocated container is the existing generic `List`, not a bespoke chat-entry container.
- Leaving the member unnamed as `field_130`: no longer necessary for first-draft C++; the role is proven across all core ChattingPane methods.

`this + 0x134` is the visible chat pixel height, not a row-count field. Recommended name: `m_visibleChatPixelHeight`.

Evidence:

- [UID:0002EO] writes `0x68` during current-layout construction, which is `8 * 13`.
- [UID:0002EW] writes `13 * visibleRows` to `this + 0x134`.
- [UID:0002ES] scroll metric virtuals use `this + 0x134` as a pixel extent in line-height math.
- [UID:0002F6] and [UID:0002F8] compute/clamp a visible line count externally and pass it into [UID:0002EW].

Rejected alternatives:

- `m_visibleRowCount`: rejected for the field because the stored value is pixels. It remains valid for the parameter and method behavior.
- `m_lineCount`: rejected because [UID:0002EX] computes total content line count dynamically from message measurements; this field is not total content lines.

### Message-list/list type

The message list should be represented as the project's generic `List *`, not as `std::vector`, `std::list`, or a custom source container, unless later source-style research proves a higher-level wrapper. The list vtable operations are stable enough for first-draft names:

- `+0x00`: deleting destructor / delete object.
- `+0x10`: indexed fetch, source-facing `GetAt`.
- `+0x18`: append/insert, source-facing `Insert` or `Add`.
- `+0x1c`: remove by index, source-facing `RemoveAt`.
- member `+0x0c`: count, source-facing `GetCount()`.

The formal C++ should use normal container-style method names and not expose vtable offsets.

### Singleton/global naming

`dword_67ADCC` should be named `g_pChattingDisplayPane`.

Evidence:

- The dedicated global doc identifies address `0x0067adcc` as `ChattingPane * g_pChattingDisplayPane`, owned/emitted by [UID:0000I5].
- [UID:0002EO] assigns this singleton when constructing the display pane.
- [UID:0002EP] clears it during display-pane destruction.
- Sibling singleton docs place the back pane, modify-height pane, variety panes, handle pane, and input pane in the same `Chatting.cpp` family.

Rejected alternatives:

- Mixed aggregate `UiChatClanSingletonSlots` ownership: rejected for source emission. It is useful as data-layout context only; exact child globals carry source ownership.
- `g_pChatPane`: rejected because the global specifically points to the display/message list pane, not the entire Chatting UI aggregate.

### Packet subtype/router names for packet types 10 and 13

The router at [UID:0002EU] should be source-facing `ChattingPane::OnChatPacketMessage`, `ChattingPane::HandleChatPacketEvent`, or an equivalent packet-message callback name. `OnChatPacketMessage` is the best first-draft name because it matches the observed callback shape: a secondary-view event/message method that extracts a packet pointer from argument offset `+0x0c` and dispatches by the first packet byte.

Packet handler helper names should be descriptive file-local names:

- `HandleChatPacketType10`
- `HandleChatPacketType13`

The type 10 role names are the best available subtype names from [UID:0002F0]:

- subtype `0`: Whisper
- subtype `4`: Shout
- subtype `5`: System
- subtype `11`: Group
- subtype `12`: Clan
- subtype `17`: SystemNotice
- subtype `18`: CustomColor

The type 13 helper is still less semantically named at the subtype level, but it is not a blocker for [UID:0002EU]. [UID:0002EZ] proves packet byte `13`, subtypes `0`, `1`, `3`, and `4`, UTF-16 conversion, local-state gates, a custom-color subtype `4` path, and forwarding into `AddChattingMessage`. A source-facing file helper name `HandleChatPacketType13` is defensible even if later work improves individual subtype names.

Rejected alternatives:

- Making [UID:0002EU] the owner of [UID:0002F0] or [UID:0002EZ]: rejected. The router tail-calls those helpers, but their larger packet-decoding bodies are documented as file-level Chatting helpers emitted by [UID:0000I5].
- Naming the router after packet type 10 or type 13: rejected because it dispatches both opcodes.
- Keeping `sub_47F890`: rejected for first-draft C++; behavior and callback position support a readable source-facing name.

### Secondary-view/vtable callback naming

[UID:0002EU] is a secondary-view callback, not a primary ChattingPane method reached by ordinary direct calls.

Evidence:

- `ChattingVtableData` places a data xref at `0x00614d64` inside the ChattingPane secondary vtable region.
- The function adjusts `ecx` by `-0xa0` before tail-jumping to the file-level packet helpers. This is the compiler's multiple-inheritance/secondary-subobject `this` adjustment; source should pass `this` as a `ChattingPane *` and should not spell the adjustment manually.
- Previous live IDA reports no ordinary direct callers, consistent with virtual callback reachability.

The source-facing name remains inferred, but the uncertainty is only spelling. `OnChatPacketMessage`/`HandleChatPacketEvent` are high-probability role names; blank C++ is no longer justified by this uncertainty.

### Generated owner pollution

Generated owner pollution from `FolderTreePane` and other unrelated generated names should stay rejected. The assigned target docs and support docs show a stable ChattingPane/Chatting family:

- Constructor, destructor, message ingestion, paint, line-count, scroll metrics, and resize callers all share the same `ChattingPane` object layout.
- [UID:000104] `ChattingUI` is the correct aggregate parent range.
- [UID:00001X] `ChattingPane` is the correct class owner for these targets.
- [UID:0000I5] `Chatting` is the correct source-file route.

Any generated route that points these methods at `FolderTreePane` or another UI class is a stale artifact, not a source fact.

### Source placement under Chatting.cpp

All three assigned target bodies should surface under [UID:0000I5] `Chatting`, proposed path `NexusTK/social/Chatting.cpp`.

Evidence:

- [UID:0000I5] already aggregates the Chatting UI classes and helper functions.
- [UID:00001X] emits to [UID:0000I5].
- Generated coverage rows show no emitter dead end for the assigned targets.
- Related singleton globals are owned/emitted by the Chatting file.
- Packet helpers [UID:0002F0] and [UID:0002EZ] are file-level Chatting helpers in the same source file, not separate class owners.

Rejected alternatives:

- Splitting these methods into a separate `ChattingPane.cpp`: possible future organization, but not supported by current by-file routing.
- Emitting packet handlers under `ChattingPane`: rejected for [UID:0002F0]/[UID:0002EZ] specifically; they are helper callees, while [UID:0002EU] remains the ChattingPane vtable callback.
- Emitting resize interaction under `ChattingModifyHeightPane`: rejected for [UID:0002EW]; modify-height methods are callers, not owners.

### Historical-assumption reanalysis

Historical docs kept first-draft C++ blank mostly because final names were not proven. That was appropriate before the adjacent ChattingPane and message-ingress pages were researched, but it is now overly conservative for these three functions.

Resolved historical assumptions:

- The message-list member no longer needs to remain `field_130`.
- The visible-height member no longer needs to remain `field_134`, and it should not be misnamed as a row-count field.
- `dword_67ADCC` is not an anonymous global; it is `g_pChattingDisplayPane`.
- Packet helpers can be referenced by descriptive file-local names even if exact original names are unknown.
- The secondary-view adjustment in [UID:0002EU] is compiler glue, not a source-level `reinterpret_cast` or manual pointer arithmetic requirement.

Still-unproven but bounded:

- Exact original spelling of `m_pChatMessageList` versus `m_chatMessageList`.
- Exact original spelling of `m_visibleChatPixelHeight`.
- Exact original source callback name for [UID:0002EU].
- Exact base UI helper names around `SetBounds`, `SyncScrollbars`, `GetScrollPosition`, `GetScrollMax`, `SetScrollRange`, and `InvalidateRect`.

Those bounded spelling uncertainties should be stated in docs, but they do not block first-draft C++.

### First-draft C++ readiness

All three targets are first-draft C++ ready.

- [UID:0002EP] has exact destructor behavior, exact owned-resource model, exact singleton clear, and compiler-generated vtable/base teardown that should be left to C++ destructor emission.
- [UID:0002EU] has exact packet-byte dispatch and exact tail targets. The function body can be represented as a callback using a message/event payload pointer and file-local helper calls.
- [UID:0002EW] has exact rectangle constants, line-height multiplication, scroll synchronization, and caller context. Helper names can be role-based.

No concrete source-shape/naming/dependency reason was found that would make code entry unsafe.

## IDA / PE Evidence Recheck

Live IDA MCP was unavailable from this session. The existing target pages preserve prior live IDA MCP facts. I additionally checked the local read-only executable:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2,679,296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Image base: `0x00400000`
- `.text`: VA `0x00401000-0x0060c4ac`, raw `0x400`, size `0x20b600`
- `.rdata`: VA `0x0060d000-0x0066c0be`, raw `0x20ba00`, size `0x5f200`
- `.data`: VA `0x0066d000-0x0069ce24`, raw `0x26ac00`, size `0xd800`
- `.rsrc`: VA `0x0069d000-0x006b2c38`, raw `0x278400`, size `0x15e00`

Boundary and call/jump observations:

- [UID:0002EP] `0x0047f1d0-0x0047f27e`
  - Leading alignment at `0x0047f1ce`: `cc cc`
  - First bytes at `0x0047f1d0`: `55 8b ec 6a ff 68 8d c1 5f 00 64 a1 00 00 00 00`
  - Tail bytes at `0x0047f26e`: `f4 64 89 0d 00 00 00 00 59 5f 5e 5b 8b e5 5d c3`
  - Trailing alignment at `0x0047f27e`: `cc cc`
  - Relative call: `0x0047f267 -> 0x0055e780`
- [UID:0002EU] `0x0047f890-0x0047f8c9`
  - First bytes at `0x0047f890`: `55 8b ec 8b 45 08 8b 40 0c 8a 10 80 fa 0a 74 1a`
  - Full body confirms byte checks for `0x0a` and `0x0d`, false return for other packets, `ecx -= 0xa0`, and tail jumps.
  - Tail jump: `0x0047f8b5 -> 0x0047fd70` for packet byte `13`
  - Tail jump: `0x0047f8c4 -> 0x0047ff80` for packet byte `10`
  - Trailing alignment at `0x0047f8c9`: seven `cc` bytes before [UID:0002EV]
- [UID:0002EW] `0x0047fbd0-0x0047fc6b`
  - Leading alignment at `0x0047fbc5`: eleven `cc` bytes
  - First bytes at `0x0047fbd0`: `55 8b ec 83 ec 24 a1 24 2f 67 00 33 c5 89 45 fc`
  - Tail bytes at `0x0047fc5b`: `fc 5f 33 cd 5e e8 ca 7a 14 00 8b e5 5d c2 04 00`
  - Trailing alignment at `0x0047fc6b`: five `cc` bytes
  - Relative calls:
    - `0x0047fbe8 -> 0x004b8e00`
    - `0x0047fc0f -> 0x004b7c50`
    - `0x0047fc26 -> 0x0055e990`
    - `0x0047fc2f -> 0x0055e950`
    - `0x0047fc3b -> 0x0055e910`
    - `0x0047fc49 -> 0x0055eae0`
    - `0x0047fc60 -> 0x005c772f` security-cookie/check support

The local PE observations support the documented exact ranges and do not reveal any split boundary or non-source thunk issue.

## Function / Child Inventory

| UID | Range | Kind | Behavior | Source-owner result |
| --- | --- | --- | --- | --- |
| `0002EP` | `0x0047f1d0-0x0047f27e` | destructor | Deletes every owned `ColorStringChattingMessage *`, deletes list, clears list member and `g_pChattingDisplayPane`, then base teardown | `ChattingPane` |
| `0002EU` | `0x0047f890-0x0047f8c9` | secondary-view callback/router | Reads packet pointer from event/message `+0x0c`, dispatches packet byte `10` or `13`, false otherwise | `ChattingPane` callback, file-local helper callees |
| `0002EW` | `0x0047fbd0-0x0047fc6b` | layout method | Converts visible rows to pixel height, applies viewport rectangle, syncs scroll/range, invalidates pane | `ChattingPane` |

## Direct Xref / Caller Inventory

- [UID:0002EP]: no ordinary direct callers in prior live IDA; expected for destructor body reached through vtable/scalar-deleting destructor glue.
- [UID:0002EU]: vtable-only data xref at `0x00614d64` in ChattingPane secondary vtable; no ordinary direct callers.
- [UID:0002EW]: called from Chatting modify-height/resize interaction:
  - `0x0048094a`
  - `0x00480b4f`
  These are caller/use-site evidence, not ownership transfer to `ChattingModifyHeightPane`.

## Per-Target Reanalysis

### [UID:0002EP] ChattingPaneDestructor

Recommendation:

- `COMPLETION`: change `82` -> `86`
- `CONFIDENCE`: keep `90`
- `CANONICAL_OWNER`: keep `00001X`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `00001X`
- Formal C++: populate

Behavior resolved:

- Restores ChattingPane vtables and uses compiler destructor glue.
- Iterates list at `this + 0x130` using count at list `+0x0c`.
- Fetches entries through list vslot `+0x10`.
- Deletes each non-null/owned `ColorStringChattingMessage *` with deleting flag `1`.
- Deletes the list object through list vslot `+0x00` with deleting flag `1`.
- Clears `this + 0x130`.
- Clears `g_pChattingDisplayPane`.
- Calls base teardown `0x0055e780`.

Source-facing conclusions:

- `this + 0x130`: `m_pChatMessageList`, type `List *`, entries `ColorStringChattingMessage *`.
- `dword_67ADCC`: `g_pChattingDisplayPane`.
- The destructor body should be explicit source, not merely generated, because it manually deletes list-owned message objects and clears the singleton.
- Vtable stores, EH state, and base teardown are compiler/destructor mechanics and should not be manually written in the formal source block.

Rejected alternatives:

- Keeping final C++ blank: rejected because owner, route, field roles, and deletion behavior are now sufficient.
- Emitting low-level vtable writes in C++: rejected because source destructor declaration/body should let the compiler emit vtable restore/base teardown.
- Adding a defensive null guard around `m_pChatMessageList`: not recommended for exact first-draft C++; the observed destructor assumes the constructor-created list exists.

### [UID:0002EU] ChattingPaneChatPacketRouter

Recommendation:

- `COMPLETION`: change `82` -> `86`
- `CONFIDENCE`: keep `90`
- `CANONICAL_OWNER`: keep `00001X`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `00001X`
- Formal C++: populate

Behavior resolved:

- Takes one event/message argument.
- Loads packet pointer from argument offset `+0x0c`.
- Reads first packet byte.
- If byte is `10`, adjusts `ecx` from secondary subobject to ChattingPane and tail-jumps to `0x0047ff80`.
- If byte is `13`, adjusts `ecx` from secondary subobject to ChattingPane and tail-jumps to `0x0047fd70`.
- Returns false for every other packet type.

Source-facing conclusions:

- Best method name for first draft: `ChattingPane::OnChatPacketMessage`.
- Acceptable alternate doc wording: `HandleChatPacketEvent`.
- Helper names: `HandleChatPacketType10` and `HandleChatPacketType13`.
- The `ecx -= 0xa0` adjustment is a compiler artifact of secondary-vtable dispatch and should not be expressed in source.
- The helper bodies are not owned by [UID:0002EU]; they are separate Chatting file helpers.

Rejected alternatives:

- Treating the function as a free packet router: rejected because vtable xref and `ecx` adjustment prove a ChattingPane secondary-view callback.
- Treating helper tail jumps as ordinary local inline logic: rejected because they target separate documented functions.
- Requiring exact original callback spelling before formal C++: rejected because behavior and route are exact, and a role-based callback name is sufficient for first draft.

### [UID:0002EW] ChattingPaneSetVisibleRowCount

Recommendation:

- `COMPLETION`: change `82` -> `86`
- `CONFIDENCE`: keep `90`
- `CANONICAL_OWNER`: keep `00001X`
- `RECONSTRUCTABLE`: keep `TRUE`
- `EMITTER_UIDS`: keep `00001X`
- Formal C++: populate

Behavior resolved:

- Computes `13 * visibleRows`.
- Stores the result at `this + 0x134`.
- Builds viewport rectangle `(23, 710 - 13 * visibleRows, 806, 710)`.
- Applies bounds through pane virtual slot `+0x2c`.
- Calls scroll synchronization helper `0x0055e990`.
- Reads current scroll via `0x0055e950`.
- Reads max scroll via `0x0055e910`.
- Calls range setter `0x0055eae0`.
- Invalidates/updates the pane rectangle through virtual slot `+0x20`.
- Uses security-cookie support at `0x005c772f`, which is not source logic.

Source-facing conclusions:

- Method name `SetVisibleRowCount` remains good because the parameter is a count of visible rows.
- Field `this + 0x134` should be named for pixel height: `m_visibleChatPixelHeight`.
- The line height literal is `13`.
- The rectangle constants are stable current-layout constants.
- Callers from modify-height pane prove this is the display pane resize/update method, not a modify-height pane method.

Rejected alternatives:

- Naming `this + 0x134` `m_visibleRowCount`: rejected because the stored unit is pixels.
- Leaving rectangle helper names as raw calls: rejected for first draft; `InitRectBounds`, `SetBounds`, and scroll helper role names are defensible.
- Reassigning owner to `ChattingModifyHeightPane`: rejected because callers are resize controls; the callee mutates ChattingPane layout.

## First-Draft C++ Recommendation

The following blocks are suitable for supervisor insertion into the formal C++ regions. Names are source-facing role names, not claimed original spellings.

### [UID:0002EP] replacement formal C++

```cpp
ChattingPane::~ChattingPane()
{
    const int count = m_pChatMessageList->GetCount();

    for (int index = 0; index < count; ++index) {
        ColorStringChattingMessage *message =
            static_cast<ColorStringChattingMessage *>(m_pChatMessageList->GetAt(index));
        delete message;
    }

    delete m_pChatMessageList;
    m_pChatMessageList = nullptr;
    g_pChattingDisplayPane = nullptr;
}
```

Notes for supervisor:

- Do not include vtable restoration, SEH state, scalar-deleting wrapper logic, or base teardown calls in the source block.
- If local source style uses `m_chatMessageList`, that spelling can replace `m_pChatMessageList`, but the member role/type should remain the same.

### [UID:0002EU] replacement formal C++

```cpp
bool ChattingPane::OnChatPacketMessage(const Message *message)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(message->m_payload);

    if (packet[0] == 10)
        return HandleChatPacketType10(this, packet);

    if (packet[0] == 13)
        return HandleChatPacketType13(this, packet);

    return false;
}
```

Notes for supervisor:

- `Message` and `m_payload` are role names for the event/message object and its `+0x0c` packet pointer field. If the surrounding project already has a better documented event type/field name, use that spelling without changing behavior.
- Do not spell the `ecx -= 0xa0` secondary-view adjustment manually.
- `HandleChatPacketType10` and `HandleChatPacketType13` are file-local helper names for [UID:0002F0] and [UID:0002EZ].

### [UID:0002EW] replacement formal C++

```cpp
void ChattingPane::SetVisibleRowCount(int visibleRows)
{
    m_visibleChatPixelHeight = 13 * visibleRows;

    RectBounds viewport;
    InitRectBounds(&viewport, 23, 710 - m_visibleChatPixelHeight, 806, 710);
    SetBounds(viewport, false);

    SyncScrollbars();

    const unsigned short currentPosition = GetScrollPosition(0);
    const unsigned short maximumPosition = GetScrollMax(0);
    SetScrollRange(0, currentPosition, maximumPosition);

    InvalidateRect(m_rect);
}
```

Notes for supervisor:

- `RectBounds`, `InitRectBounds`, `SetBounds`, `SyncScrollbars`, `GetScrollPosition`, `GetScrollMax`, `SetScrollRange`, and `InvalidateRect` are role names aligned to the observed helper calls and pane virtuals.
- `m_rect` should be replaced by the exact inherited pane rectangle member name if already standardized elsewhere.
- If the project style uses a line-height constant, replace literal `13` with that constant; the binary behavior remains `13 * visibleRows`.

## Exact Supervisor Doc Edits Recommended

Do not edit by-* docs from this B-agent report. The following is exact supervisor text for later execution.

### [UID:0002EP] `by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md`

Metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank `RECONSTRUCTION_CPP CODE:BEGIN/END` body with:

```cpp
ChattingPane::~ChattingPane()
{
    const int count = m_pChatMessageList->GetCount();

    for (int index = 0; index < count; ++index) {
        ColorStringChattingMessage *message =
            static_cast<ColorStringChattingMessage *>(m_pChatMessageList->GetAt(index));
        delete message;
    }

    delete m_pChatMessageList;
    m_pChatMessageList = nullptr;
    g_pChattingDisplayPane = nullptr;
}
```

Add under the current score/source-status section, after the existing paragraph that explains `82/90`:

```text
2026-06-17 B003 source-quality reanalysis recommends raising this page to `86/90` and populating first-draft C++. The remaining open naming questions are now bounded to original spelling rather than source shape: `this + 0x130` is the ChattingPane-owned generic `List *` of `ColorStringChattingMessage *` entries (`m_pChatMessageList` / `m_chatMessageList`), and `dword_67ADCC` is the display-pane singleton `g_pChattingDisplayPane`. The destructor should be represented as an explicit source destructor deleting every owned message, deleting the list, clearing the member, and clearing the singleton; vtable restoration, SEH state, scalar-deleting wrapper behavior, and base teardown are compiler-generated destructor mechanics and should not be manually written in the formal C++.
```

Replace the stale `Open Questions` bullets with:

```text
- Original source spelling of the message-list member is still not directly proven; use `m_pChatMessageList` as the best source-facing first-draft name, with `m_chatMessageList` acceptable if project style avoids pointer prefixes.
- No source-level blocker remains for first-draft C++; exact vtable/base-dtor mechanics are compiler output and not part of the source body.
```

### [UID:0002EU] `by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md`

Metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank `RECONSTRUCTION_CPP CODE:BEGIN/END` body with:

```cpp
bool ChattingPane::OnChatPacketMessage(const Message *message)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(message->m_payload);

    if (packet[0] == 10)
        return HandleChatPacketType10(this, packet);

    if (packet[0] == 13)
        return HandleChatPacketType13(this, packet);

    return false;
}
```

Add under the current score/source-status section, after the existing paragraph that explains `82/90`:

```text
2026-06-17 B003 source-quality reanalysis recommends raising this page to `86/90` and populating first-draft C++. The source shape is now sufficiently resolved: this is a ChattingPane secondary-view packet/message callback, best first-draft name `OnChatPacketMessage` or `HandleChatPacketEvent`, that loads the packet pointer from event/message offset `+0x0c`, checks packet bytes `10` then `13`, returns false for other opcodes, and tail-calls file-local helpers for packet type 10 and packet type 13 after the compiler-generated secondary-subobject `this` adjustment. The helper bodies remain separate Chatting file helpers ([UID:0002F0] and [UID:0002EZ]) rather than inline router-owned code.
```

Replace any stale final-name blocker text with:

```text
- Exact original spelling of the secondary-view callback is still not proven. Use `OnChatPacketMessage` as the best source-facing first-draft name, with `HandleChatPacketEvent` acceptable if surrounding event naming standardizes that form.
- The `ecx -= 0xa0` adjustment is compiler multiple-inheritance glue and should not be written manually in the source body.
- Packet type helper names should remain descriptive (`HandleChatPacketType10`, `HandleChatPacketType13`) until exact original symbols are recovered.
```

### [UID:0002EW] `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`

Metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00001X | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the blank `RECONSTRUCTION_CPP CODE:BEGIN/END` body with:

```cpp
void ChattingPane::SetVisibleRowCount(int visibleRows)
{
    m_visibleChatPixelHeight = 13 * visibleRows;

    RectBounds viewport;
    InitRectBounds(&viewport, 23, 710 - m_visibleChatPixelHeight, 806, 710);
    SetBounds(viewport, false);

    SyncScrollbars();

    const unsigned short currentPosition = GetScrollPosition(0);
    const unsigned short maximumPosition = GetScrollMax(0);
    SetScrollRange(0, currentPosition, maximumPosition);

    InvalidateRect(m_rect);
}
```

Add under the current score/source-status section or before `## Cross-References`:

```text
2026-06-17 B003 source-quality reanalysis recommends raising this page to `86/90` and populating first-draft C++. `this + 0x134` should be named for its stored unit, visible chat pixel height (`m_visibleChatPixelHeight`), not row count. The method name and argument remain visible-row/count semantics because the input is multiplied by the 13-pixel chat line height before storing. The viewport rectangle constants, scroll synchronization sequence, and modify-height callers are all stable enough for first-draft source with role-based pane/helper names.
```

Add or update the field note:

```text
- `this + 0x134`: visible chat pixel height, recommended source-facing name `m_visibleChatPixelHeight`; do not name this field `m_visibleRowCount` because [UID:0002EW] stores `13 * visibleRows` and [UID:0002ES] consumes it as pixels.
```

## Exact Coverage Report Row Replacements

Replace only the following rows in `by-memory/-coverage-report.md`; this B-agent report did not edit the file directly.

### [UID:0002EP]

```text
        - [UID:0002EP][0x0047f1d0-0x0047f27e.ChattingPaneDestructor](by-memory/0x0047f1d0-0x0047f27e.ChattingPaneDestructor.md) 0x0047f1d0-0x0047f27e | destructor | ChattingPaneDestructor : reconstructable : 86% : strong : B003 2026-06-17 reanalysis resolves the former destructor source-quality blockers: `this+0x130` is the `List *` chat-message list (`m_pChatMessageList` / `m_chatMessageList`) with `ColorStringChattingMessage *` entries, `dword_67ADCC` is `g_pChattingDisplayPane`, and the explicit source destructor should delete every owned message, delete the list, null the member, and clear the singleton while leaving vtable restores/base teardown to the compiler; local PE MD5 `4247e04e20b65d6414c7238aa8ff5515` reconfirms boundary/padding and call to base teardown `0x0055e780`; first-draft C++ is ready for the formal block with role-based names.
```

### [UID:0002EU]

```text
        - [UID:0002EU][0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter](by-memory/0x0047f890-0x0047f8c9.ChattingPaneChatPacketRouter.md) 0x0047f890-0x0047f8c9 | method | ChattingPaneChatPacketRouter : reconstructable : 86% : strong : B003 2026-06-17 reanalysis resolves this as a secondary-view `ChattingPane` packet/message callback, best source-facing name `OnChatPacketMessage` / `HandleChatPacketEvent`: it extracts the packet pointer from event/message offset `+0x0c`, checks packet bytes `10` then `13`, returns false for other packets, and tail-jumps after compiler `ecx -= 0xa0` adjustment to file-local `HandleChatPacketType10` and `HandleChatPacketType13`; local PE reconfirms full body bytes, seven-byte padding, and exact tail jumps to `0x0047fd70`/`0x0047ff80`; first-draft C++ is ready with descriptive callback/helper names.
```

### [UID:0002EW]

```text
        - [UID:0002EW][0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount](by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md) 0x0047fbd0-0x0047fc6b | method | ChattingPaneSetVisibleRowCount : reconstructable : 86% : strong : B003 2026-06-17 reanalysis resolves `this+0x134` as visible chat pixel height (`13 * visibleRows`), keeps parameter/method semantics as visible-row count, validates callers from `ChattingModifyHeightPane`, and names the helper dependencies as BackPane bounds, `InitRectBounds`, ScrollablePane sync/current/max/range setters, and pane invalidation; local PE reconfirms 11-byte leading padding, five-byte trailing padding, and direct calls to `0x004b8e00`, `0x004b7c50`, `0x0055e990`, `0x0055e950`, `0x0055e910`, and `0x0055eae0`; first-draft C++ is ready with role-based field/helper names.
```

## Final Recommendation

`0002EP`, `0002EU`, and `0002EW` should be promoted from blank-C++ reconstructable pages to first-draft source pages at `86/90`. No ownership, emitter, reconstructable, source-file, or split changes are recommended.

Exact recommendations:

- [UID:0002EP] keep `CANONICAL_OWNER:00001X`, keep `EMITTER_UIDS:00001X`, keep `RECONSTRUCTABLE:TRUE`, set `86/90`, populate destructor C++.
- [UID:0002EU] keep `CANONICAL_OWNER:00001X`, keep `EMITTER_UIDS:00001X`, keep `RECONSTRUCTABLE:TRUE`, set `86/90`, populate packet-callback/router C++.
- [UID:0002EW] keep `CANONICAL_OWNER:00001X`, keep `EMITTER_UIDS:00001X`, keep `RECONSTRUCTABLE:TRUE`, set `86/90`, populate visible-row layout C++.

Residual risk is limited to original spelling of source names. That risk should be documented, not allowed to suppress code generation for these exact blocks.

## Follow-Up Actions

- Supervisor should apply the exact by-memory metadata/C++/text edits above if accepting this report.
- Supervisor should replace the three exact `by-memory/-coverage-report.md` rows above.
- Later source-style work can standardize names such as `Message::m_payload`, `m_pChatMessageList`, `m_visibleChatPixelHeight`, and pane helper method names across the full `Chatting.cpp` output.
- No B-agent edit to by-* docs, generated files, or coverage reports was performed.

## Validation

Validation performed after report creation:

- Confirmed the report exists under Agent-B003's research folder.
- Confirmed the required heading `## Heuristic / Inference Reanalysis And Validation` is present exactly.
- Confirmed the report contains the assignment id, first-draft C++ for all three targets, exact owner/emitter/reconstructable recommendations, and exact coverage-row replacement text.
- `git status` was not available because `E:\NTK\GhidraBridge` is not a Git repository in this workspace. No by-* docs, coverage report files, generated files, or project-level files were edited by this task; the only file created by this B-agent work is this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002EP-0002EU-0002EW-chatting-pane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002EP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
