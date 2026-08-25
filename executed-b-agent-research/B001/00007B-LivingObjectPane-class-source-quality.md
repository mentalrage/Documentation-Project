** TARGET-REPORT-UID:00007B **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00007B LivingObjectPane Class Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00007B] `by-class/LivingObjectPane.md` as the direct semantic class owner for the main `LivingObjectPane` declaration and keep [UID:0000KU] `by-file/LivingObjectPane.md` as the source file/emitter root. Update the class page from `85/85` to `86/88` after incorporating the evidence in this report.
- Final disposition: report-only. Do not edit target/support by-* docs until the supervisor sends an implementation callback. Do not edit `by-memory/-coverage-report.md`.
- Source placement: `NexusTK/map/LivingObjectPane.cpp` remains the best source file. The class is not `UserPane`, `MapPane`, `ObjectPane`, `EffectObjectPane`, or `TimerHandler`, but it depends on all of those documented owners.
- Owner/emitter metadata: keep `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, blank emitter position. The class remains a reconstructable class source item.
- Formal C++ recommendation: do not populate the class `RECONSTRUCTION_CPP` block in this callback. A class declaration is the only valid class-level C++ here, and the declaration would still freeze unresolved base/subobject layout, adjusted `UserPane`/local-player offsets, packet-tail structs, slot-buffer types, render helper signatures, and vtable slot prototypes. Exact method bodies belong in child by-memory pages, not in the class page.
- Coverage-report recommendation: no `by-memory/-coverage-report.md` replacement row is required for this class report. If target score metadata changes, generated class coverage should be refreshed by validator/autogen, not hand-edited.
- Confidence in recommendation: high for source/file/class ownership and boundary exclusions; medium-high for class-level field names and local-player adjusted-layout interpretation; medium for exact local-player raw helper original source names because the binary is stripped and several starts have zero live routes.

## Target

- Target UID: `00007B`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\LivingObjectPane.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00007B-LivingObjectPane-class-source-quality.md`
- Current target state: `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, formal C++ blank.
- Primary support docs inspected:
  - `by-file/LivingObjectPane.md` [UID:0000KU], `88/85`, source root `NexusTK/map/LivingObjectPane.cpp`.
  - `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md` [UID:0001DE], `88/90`, non-emitting split/index.
  - `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` [UID:0001KM], `88/88`, non-emitting split/index.
  - `by-class/UserPane.md` [UID:0000FQ], `86/86`.
  - `by-class/MapPane.md` [UID:00007Q], `88/87`.
  - `by-class/ObjectPane.md` [UID:00009R], `87/90`.
  - `by-class/EffectObjectPane.md` [UID:000049], `85/86`.
  - `by-class/TimerHandler.md` [UID:0000F0], `85/86`.
  - `by-class/TimerMgr.md` [UID:0000F1], `87/86`.
  - LivingObjectPane child by-memory pages in the core and local-player clusters.
  - Prior executed B-agent reports for [UID:0001DE], [UID:00023H], [UID:0003VB]/[UID:0003US], and [UID:00027W].

## Executive Recommendation

`LivingObjectPane` is a source-authored gameplay map-object class rooted in `map/LivingObjectPane.cpp`. The current class page is correct to attach to the file root, but it should be upgraded from a method-family index into a source-quality class inventory that records:

- the core exact child method split;
- the local-player exact child method split;
- the raw/no-route helper-shaped bodies and their best source-facing names;
- direct exclusions for stale `EffectObjectPane`, `ItemObjectPane`, `OptionPane`, and timer-generated labels;
- the class-field glossary that is strong enough for documentation but not yet strong enough for a formal class declaration;
- the vtable/static-storage/source-declared-generated-binary handling;
- why final C++ remains blank despite the class being reconstructable and an emitter.

Do not split the class page. Do not demote it to non-reconstructable. Do not move local-player method ownership to `UserPane`: the live `UserPane` class wraps or adjusts into the living-object subobject, but the movement, animation, slot-dispatch, linked-object, and packet helper bodies still use `LivingObjectPane` state and are documented under the LivingObjectPane file/class family.

Recommended score after incorporation: `86/88`.

- `86` completion: the class can now document the source-family map, raw-route audit, stale ownership corrections, and class-field/source-quality direction in more detail than the current page. Completion should not rise higher because no final declaration, no vtable prototype list, no full local-player packet struct layout, and no formal class-level C++ are ready.
- `88` confidence: source/file/class routing is strongly supported by existing by-file/by-memory pages, vtable data, constructor/destructor vptr stores, static pool evidence, and fresh PE route scans. Confidence should stay below final-source level because several raw helper original names are inferred/descriptive and the local-player adjusted layout still needs direct class/`UserPane` declaration work.

## Supervisor Active Recheck

- Assignment is a report-only B-agent source-quality pass for [UID:00007B] `by-class/LivingObjectPane.md`.
- The task does not authorize editing by-* docs yet. This report is the durable output for supervisor review and later callback.
- This is a class page, not a split-capable by-memory parent. No child pages were created.
- Current active C++ gate from `by-structure.md`: code may be entered only for reconstructable items with confirmed emitters and average score greater than `85`, but the gate is a minimum eligibility rule, not permission to add weak or misleading code. A class-level declaration remains unsafe for this target.
- Current temporary coverage rule: B agents must not edit `by-memory/-coverage-report.md`; this report includes exact coverage outcome text instead.

## Evidence Checked

### Documentation Evidence

- `by-class/LivingObjectPane.md`: current class purpose, method-family inventory, boundary caveats, `00023H` correction, `0003US` user-list caveat, timer-name correction, raw local-player start list, and current score rationale.
- `by-file/LivingObjectPane.md`: file-level source root, likely source path, contents list, boundary notes, and local-player raw helper policy.
- `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`: non-emitting core split/index, core method inventory, exact children, raw/no-xref helper handling, and non-Living sibling exclusions.
- `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`: non-emitting local-player split/index, exact child list, mixed UserPane/Say/Chat/Quit/SelfSave exclusions, raw helper starts, and no-code policy.
- `by-class/UserPane.md`: separate local user UI class, constructor/destructor relationship to `LivingObjectPane`, `MapPane + 0x418` relation, and `UserPane::HandleServerMessage` ownership.
- `by-class/MapPane.md`: spatial/rendering owner, active object/local player pointers, map object list ownership, and object type values.
- `by-class/ObjectPane.md`: base object-pane fields at `+0xf8`, `+0xfc`, `+0x100`, `+0x104`, `+0x108`, `+0x118`, `+0x11c`, `+0x120`, `+0x124`.
- `by-class/EffectObjectPane.md`: [UID:00023H] `EffectObjectPane::IsLooping` correction, `+0x148` effect id and `+0x14c` loop/reuse-active flag.
- `by-class/TimerHandler.md`, `by-class/TimerMgr.md`, `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`, `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`: generic scheduler/wrapper names replacing stale `SoundManager::*` labels.
- `by-memory/0x00620978-0x00620a38.LivingObjectPaneVtableData.md`: RTTI/vtable range, constructor/destructor vptr evidence, adjusted vtable views, source-declared/generated-binary handling.
- `by-memory/0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md`: nested `LivingObjectPane::BoxRotator` RTTI/vtable range, owner pointer, advance callback evidence.
- `by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md`: static pool storage, `0x20c` object block size, allocation/free/destructor xrefs.
- `by-memory/0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`: orphan function-key debounce global, `0x005a9250` raw helper linkage, no write/update caveat.
- `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, `auto-generated/-ag-memory-coverage.md`: current generated routing and blank-code rows.
- Prior reports:
  - `Agent-B001/research/executed/0001DE-LivingObjectPaneCore-source-quality.md`
  - `Agent-B003/research/executed/00023H-LivingObjectPaneGetEntityId-source-quality.md`
  - `Agent-B001/research/executed/0003VB-0003US-UserPaneUserListDispatchSourceShape-source-quality.md`
  - `Agent-B001/research/executed/00027W-LivingObjectPaneWordSlots-source-quality.md`

### Fresh Binary/PE Evidence Checked On 2026-06-19

Local PE scanned: `E:\NTK\Resources\NexusTK\NexusTK.exe`

- Image base: `0x00400000`.
- `.text`: `0x00401000-0x0060c4ac`, raw file offset `0x400`, raw size `0x20b600`.
- Search method: direct local PE byte scan for rel32 `call`/`jmp` targets, absolute VA dwords, and RVA dwords. This was used as a route/liveness audit, not as a replacement for IDA.

Raw local-player helper starts with zero routes:

| Target | rel32 refs | abs VA refs | RVA refs | Decision |
| --- | ---: | ---: | ---: | --- |
| `0x005a3a20` | 0 | 0 | 0 | Raw helper-shaped retained body, no proven live route. |
| `0x005a9250` | 0 | 0 | 0 | Raw function-key debounce helper, no proven live route. |
| `0x005aaff0` | 0 | 0 | 0 | Raw movement-correction packet helper, no proven live route. |
| `0x005ac1b0` | 0 | 0 | 0 | Raw position-sync packet helper, no proven live route. |
| `0x005ac7e0` | 0 | 0 | 0 | Raw waypoint packet helper, no proven live route. |
| `0x005ac9a0` | 0 | 0 | 0 | Raw facing/linked-record packet helper, no proven live route. |
| `0x005acae0` | 0 | 0 | 0 | Raw direction packet helper, no proven live route. |
| `0x005acb20` | 0 | 0 | 0 | Raw auto-face direction packet helper, no proven live route. |
| `0x005a87b0` | 0 | 0 | 0 | Raw linked-record getter, no proven live route. |
| `0x005abb20` | 0 | 0 | 0 | Retained duplicate user-list packet body, no proven live route. |

Positive controls from the same scan prove the scan finds real direct calls when present:

| Target | rel32 refs | rel32 sites found |
| --- | ---: | --- |
| `0x005a4530` | 8 | `0x005a3ab8`, `0x005a3bf2`, `0x005a3c28`, `0x005a3c4e`, `0x005a92c6`, `0x005a92eb`, `0x005a92ff`, `0x005b62bd` |
| `0x005a3e30` | 8 | `0x004eab81`, `0x004ed711`, `0x004ed7fc`, `0x004ef0e1`, `0x005070c1`, `0x005a3ac6`, `0x005a3ba1`, `0x005b5e51` |
| `0x005a58c0` | 2 | `0x00509092`, `0x005a5f87` |
| `0x005acc30` | 1 | `0x005a5956` |
| `0x005a5a90` | 12 | `0x005a79ea`, `0x005a820a`, `0x005a8572`, `0x005a874e`, `0x005ab047`, `0x005ab133`, `0x005ab29c`, `0x005ab3b9`, `0x005ab4b1`, `0x005ab5ff`, `0x005ab706`, `0x005ac221` |

Raw byte boundary samples:

| Range | Boundary evidence |
| --- | --- |
| `0x005a3a20-0x005a3ad4` | Preceded by `cc` fill; starts `55 8b ec 51`; ends `5d c2 08 00`; followed by `cc` fill and next prologue at `0x005a3ae0`. |
| `0x005a9250-0x005a9307` | Preceded by `cc` fill after a small prior wrapper; starts `55 8b ec`; post-range bytes include `c2 08 00` then `cc` fill and next prologue at `0x005a9310`. Existing page range should be reviewed for whether the `c2 08 00` epilogue is intended inside the child end boundary. |
| `0x005aaff0-0x005ab084` | Preceded by `cc` fill; starts `55 8b ec 51`; ends `5d c2 04 00`; followed by `cc` fill and next prologue at `0x005ab090`. |
| `0x005ac1b0-0x005ac27c` | Preceded by `cc` fill; starts `55 8b ec 83 ec 08`; ends `5d c2 04 00`; followed by `cc` fill and next prologue at `0x005ac280`. |
| `0x005ac7e0-0x005ac99b` | Preceded by `cc` fill; starts `55 8b ec 83 ec 24`; has security-cookie setup; followed by `cc` fill and next prologue at `0x005ac9a0`. |
| `0x005ac9a0-0x005acad5` | Starts after `cc` fill; starts `55 8b ec 83 ec 18`; ends `5d c2 04 00`; followed by `cc` fill and next prologue at `0x005acae0`. |
| `0x005acae0-0x005acb1f` | Preceded by `cc` fill; starts `55 8b ec 83 ec 10`; ends `5d c2 04 00`; followed by one `cc` then next prologue at `0x005acb20`. |
| `0x005acb20-0x005acc23` | Starts after one `cc`; starts `55 8b ec 83 ec 18`; ends `8b e5 5d c3`; followed by `cc` fill and next prologue at `0x005acc30`. |
| `0x005a87b0-0x005a87d5` | Starts after previous return/fill; starts `55 8b ec`; ends `5d c2 04 00`; followed by `cc` fill and inline/prologue-shaped successor logic. |
| `0x005abb20-0x005abc6f` | Starts after prior return/fill; starts SEH-style prologue `55 8b ec 6a ff`; ends `5d c2 04 00`; followed by one `cc` and next SEH-style prologue. |

## Heuristic / Inference Reanalysis And Validation

### 1. Source File And Class Ownership

Best direction: keep source placement in `NexusTK/map/LivingObjectPane.cpp`, with class owner [UID:00007B] and file root [UID:0000KU].

Evidence:

- The by-file root already clears `88/85` and projects to `NexusTK/map/`.
- Core constructor/destructor, vtable, nested `BoxRotator`, linked-object, sprite, movement, render, and local-player helpers cluster around two large LivingObjectPane source neighborhoods: `0x0053a110-0x0053d818` and `0x005a2de0-0x005ad441`.
- [UID:000358] is the main `LivingObjectPane` RTTI/vtable span. Constructor variants and scalar-deleting destructor restore/reference its primary and adjusted vtable views.
- [UID:0002WL] is a `LivingObjectPane` static pool instance with `0x20c` object block size and allocation/free/destructor xrefs. This supports a concrete class allocation model.
- [UID:000357] and [UID:0003Z9]/[UID:0002T6] show `LivingObjectPane::BoxRotator` as a nested helper, not a separate source module.

Rejected alternatives:

- `UserPane` as primary owner: rejected. `UserPane` owns local UI event surface and the opcode `0x36` live inline server-message path, but many local-player helpers operate on the `LivingObjectPane` adjusted subobject and movement/packet state. Moving the whole family to `UserPane` would lose the core constructor/vtable/static-pool evidence.
- `MapPane` as owner: rejected. MapPane owns spatial lookup, active object pointers, and object list/render orchestration; the actor state transitions, linked-object sync, movement prediction, and packets remain LivingObjectPane-side.
- `ObjectPane` as owner: rejected. ObjectPane owns inherited generic fields and object type/data rect basics; the sprite/effect/nameplate/local-player behavior is living-specific.
- `EffectObjectPane` as owner: rejected except for [UID:00023H], which is now correctly documented as `EffectObjectPane::IsLooping`.
- `TimerHandler`/`TimerMgr` as owner: rejected. They own scheduler mechanics and wrappers; LivingObjectPane is a scheduler consumer.

### 2. Core Split And Class Boundary

Best direction: keep [UID:0001DE] `LivingObjectPaneCore` as `RECONSTRUCTABLE:FALSE` split/index and keep exact children as source-bearing method pages.

Evidence:

- The core span contains coherent LivingObjectPane method clusters but is not itself an original source item. It is an audit/index over exact methods.
- Exact core children already own reconstruction responsibilities:
  - [UID:0002R0] constructors/cleanup.
  - [UID:0003Z3] sprite config and file-local direction helpers.
  - [UID:0003Z4] linked-object setup.
  - [UID:0001DF] attached object detach/registry interaction.
  - [UID:0003Z5] effect/movement/action helpers.
  - [UID:0002R1] animation/timer methods.
  - [UID:0003Z6] nameplate/special-effect helpers.
  - [UID:0002R2] render aggregate, itself non-emitting split/index.
  - [UID:0003NU]/[UID:0003NV]/[UID:0003NW] render exact children.
  - [UID:0003Z7] linked position/mode helpers.
  - [UID:0003Z8] try-step-forward.
  - [UID:0003Z9]/[UID:0002T6] nested BoxRotator methods.
  - [UID:0003ZA] name visibility vtable methods.
  - [UID:0002R3] scalar deleting destructor wrapper.

Rejected alternative: emit a broad class-level or core-level source block for `0x0053a110-0x0053d818`. This would duplicate child ownership, flatten method boundaries, and incorrectly treat an address-contiguous audit span as an original source unit.

### 3. Local-Player Split And Adjusted Layout

Best direction: keep [UID:0001KM] `LivingObjectPaneLocalPlayerExtensions` as `RECONSTRUCTABLE:FALSE` split/index. Keep source-bearing children routed to [UID:00007B] or [UID:0000KU] according to whether the child is a class method or file-level support, while explicitly documenting the UserPane-adjusted layout caveat.

Evidence:

- [UID:0001KM] mixes at least five source families: LivingObjectPane movement/action/server-packet helpers, actual `UserPane` virtual/event methods, chat/say-input helpers, quit/self-save factories, and raw no-route helper-shaped bodies.
- The exact child split already prevents the aggregate from becoming an overbroad emitter.
- The local-player/user packet tail uses large offsets such as `+0x13eb14`, `+0x13eb18`, `+0x13eb20`, `+0x13eb24`, `+0x13eb28`, `+0x13eb2c`, and `+0x13eb30`. These should be treated as fields on the local player/UserPane aggregate viewed through a LivingObjectPane-adjusted pointer, not as proven fields in a standalone `LivingObjectPane` allocation layout.
- Prior [UID:0003US]/[UID:0003VB] source-shape work shows `UserPane::HandleServerMessage` converts/adjusts into a LivingObjectPane subobject in at least one inline packet path. That explains why some local-player offsets are huge relative to the standalone `0x20c` pool size.

Best field names for the large local-player packet tail:

| Offset | Best descriptive name | Confidence | Evidence/impact |
| --- | --- | --- | --- |
| `+0x13eb14` | `m_linkedRecordArray` or `m_localLinkedRecordArray` | Medium-high | Used by linked-record getter/clear/update helpers. Raw getter at `0x005a87b0` reads pointer/count style state. |
| `+0x13eb18` | `m_linkedRecordCount` | High | Paired count with `+0x13eb14`; raw getter bounds-checks against it. |
| `+0x13eb20` | `m_deferredUserListPacket` or `m_pendingUserListPacket` | Medium-high | Used by [UID:0003US] and [UID:0003UK] copy-buffer path. |
| `+0x13eb24` | `m_deferredUserListPacketSize` | Medium-high | Size paired with pending packet pointer/buffer. |
| `+0x13eb28` | `m_userListPacketTick` | Medium | Packet timing/debounce style field near pending user-list state. |
| `+0x13eb2c` | `m_nextUserListPacketTick` or `m_userListDeferUntilTick` | Medium | Timing/defer field; exact lifecycle should remain open in child docs. |
| `+0x13eb30` | `m_skipNextUserListPacket` | Medium-high | Boolean skip/defer flag from user-list packet handling. |

Rejected alternative: freeze these fields in `class LivingObjectPane` now. This contradicts [UID:0002WL]'s `0x20c` standalone block size and would probably encode a `UserPane` aggregate or adjusted-this layout as a standalone living actor layout.

### 4. Raw Helper Liveness

Best direction: document raw helper-shaped bodies as source-authored or retained source-shaped code where behavior is known, but do not treat the zero-route starts as ordinary live called methods until an indirect route, pointer table, or source-retained-dead-code policy is proven.

Evidence:

- Fresh PE route scan found zero rel32/absVA/RVA routes to every raw start listed above.
- The same scan found ordinary rel32 call sites for live neighbors such as `0x005a4530`, `0x005a3e30`, `0x005a58c0`, `0x005acc30`, and `0x005a5a90`.
- Raw bodies have function-shaped prologues/epilogues and alignment fill. They are not random padding.
- Prior docs already show IDA lacks modeled functions for multiple raw starts.

Best descriptive names:

| UID/range | Current title | Recommended source-facing name direction | Liveness decision |
| --- | --- | --- | --- |
| [UID:0003UA] `0x005a3a20-0x005a3ad4` | `LivingObjectPaneRawConfigHotkeyHelper` | `DispatchConfiguredHotkeySlotRaw` or `HandleConfiguredHotkeySlotRaw` | Raw retained helper, no proven route. Calls command/inventory slot dispatchers by config/hotkey state. |
| [UID:0003UJ] `0x005a9250-0x005a9307` | `LivingObjectPaneRawFunctionKeyDebounceHelper` | `DispatchFunctionKeyCommandWithDebounceRaw` | Raw retained helper, no proven route. Reads `g_lastFunctionKeyTick`, gates on `0x64`, calls command-slot dispatch. |
| [UID:0003UO] `0x005aaff0-0x005ab084` | `LivingObjectPaneRawMovementCorrectionPacketHelper` | `ApplyMovementCorrectionPacketRaw` | Raw retained packet helper, no proven route. Best modeled as movement-correction ack/correction handler. |
| [UID:0003UV] `0x005ac1b0-0x005ac27c` | `LivingObjectPaneRawPositionSyncPacketHelper` | `HandlePositionSyncPacketRaw` | Raw retained packet helper, no proven route. Parses/syncs position state and calls/relates to warp path. |
| [UID:0003UX] `0x005ac7e0-0x005ac99b` | `LivingObjectPaneRawWaypointPacketHelper` | `SendWaypointPacketRaw` | Raw retained send helper, no proven route. Stack-cookie body sends waypoint-like packet data. |
| [UID:0003UY] `0x005ac9a0-0x005acad5` | `LivingObjectPaneRawFacingPacketHelper` | `SendFacingOrLinkedRecordPacketRaw` | Raw retained send helper, no proven route. Name should preserve uncertainty between facing-only and linked-record payload. |
| [UID:0003H4] `0x005acae0-0x005acb1f` | `LivingObjectPaneSendDirectionPacketRawHelper` | `SendDirectionPacketRaw` | Raw retained helper, no proven route. Sends direction opcode path, documented as source-shaped but not live-proven. |
| [UID:0003H5] `0x005acb20-0x005acc23` | `LivingObjectPaneAutoFaceDirectionPacketRawHelper` | `SendAutoFaceDirectionPacketRaw` | Raw retained helper, no proven route. Auto-face/direction-send helper paired with live [UID:0003UZ]. |
| [UID:0003VE] `0x005a87b0-0x005a87d5` | `LivingObjectPaneGetActiveLinkedRecordByIndexRaw` | `GetLinkedRecordByIndexRaw` or `GetActiveLinkedRecordByIndexRaw` | Raw getter, no proven route. Behavior is exact enough; liveness is not. |
| [UID:0003US] `0x005abb20-0x005abc6f` | `LivingObjectPaneHandleUserListPacket` | `HandleUserListPacketRetainedDuplicate` if renamed in prose | Retained duplicate/no-route body. Live opcode `0x36` is inline in `UserPane::HandleServerMessage`, not a call to this function. |

Open issue resolved to best probability: these are source-shaped retained helper bodies in the LivingObjectPane local-player neighborhood, but the class page must not claim they are all reachable live methods. Each exact child should keep source-authored/reconstructable status only if its own page documents behavior and no-route policy; the aggregate page should explain this as a source-quality caveat.

### 5. Command Slot, Inventory Slot, Hotkey Contract

Best direction:

- Keep [UID:0001KN] title/name `UseInventorySlotDispatch` for `0x005a3e30-0x005a3ff3`.
- Keep [UID:0003UC] title/name `LivingObjectPaneUseCommandSlotDispatch` for `0x005a4530-0x005a4908`, but prose should explain that it is the spell/command-slot dispatch path and older generated names may call it spell-slot selection.
- Keep [UID:0003UB] `ExecuteHotkeyAction` as the live macro/hotkey executor.
- Keep [UID:0003UA] raw config hotkey body as no-route retained helper.

Evidence:

- Current docs resolve [UID:0001V1] `MacroHotkeyRecord` state `2` / `.usr` `S` from the spell-inventory tab and state `3` / `.usr` `I` from the inventory tab.
- [UID:0001KN] has callers from use-input/item use paths and can open `ItemWhoInputPane`, supporting inventory-slot dispatch rather than a generic spell manager name.
- Fresh PE scan found `0x005a3e30` live direct calls at eight rel32 sites and `0x005a4530` live direct calls at eight rel32 sites. The raw `0x005a3a20` and `0x005a9250` bodies also call into those dispatchers but have no direct route themselves.
- `0x005b62bd` calls `0x005a4530`, consistent with SpellSpellInputPane/supporting command-slot usage.

Rejected alternatives:

- Do not rename `0x005a3e30` back to `UseSpellSlot` only because older generated output did. Its strongest caller evidence is inventory/item slot dispatch.
- Do not attach slot helper ownership to the input panes. Input panes are callers/consumers; the receiving state and command packet path remain LivingObjectPane/local-player source.

### 6. User List Packet Routing

Best direction: class page should keep [UID:0003US] in the local-player packet inventory but label it as a retained duplicate/no-route body. The live opcode `0x36` behavior belongs to [UID:0003VB] `UserPaneHandleServerMessage`, inline in `UserPane`.

Evidence:

- Prior B001 report for [UID:0003VB]/[UID:0003US] found matching logic inline in `UserPane::HandleServerMessage`.
- Fresh PE scan found zero rel32/absVA/RVA routes to `0x005abb20`.
- Fresh scan found live routes to `0x005a9310`, the buffer-copy helper used by the user-list path, from both `UserPane::HandleServerMessage` and the retained duplicate. This supports shared helper behavior but not a call from the live UserPane path into `0x005abb20`.

Recommended source-facing direction:

- `0x005a9310` should be described in prose as `CopyDeferredPacketBuffer` or `CopyLocalPacketBuffer`, not only `SetMovementBuffer`. Its current title can remain until a direct child callback, but its behavior is broader than movement because it supports deferred user-list packet buffering.
- `0x005abb20` can keep the filename/title for stable UID references, but prose should use `retained duplicate` and warn against final C++ emission as a normally called method.

### 7. Render Split And C++ Readiness

Best direction: keep [UID:0002R2] non-emitting; keep [UID:0003NU], [UID:0003NV], and [UID:0003NW] as exact emitting children but do not enter formal C++ in this class callback. Update stale child text that says code is blocked only by the old `90/90` gate.

Evidence:

- [UID:0002R2] is already `RECONSTRUCTABLE:FALSE` and functions as a render-method split/index.
- The exact children [UID:0003NU]/[UID:0003NV]/[UID:0003NW] clear the active score/emitter gate and route to [UID:00007B], but their current C++ blocks are blank.
- Their source implementation depends on not-yet-final render context, object-image helper signatures, sprite frame table names, bounds struct spelling, linked object/overlay fields, and vtable prototype names.

Recommended exact child policy:

- Do not add guessed C++ to the class page.
- Do not add render child C++ until each render child page gets a targeted source-quality pass or callback that resolves helper signatures and field names.
- Replace old "below 90/90" no-code wording with active gate language: the active 85/85+ gate is met, but final-output code remains unsafe because render helper signatures and fields are not source-quality.

### 8. Vtables, RTTI, Static Pool, And Generated-Binary Handling

Best direction:

- [UID:000358] `LivingObjectPaneVtableData`: keep direct owner [UID:00007B], emitter [UID:00007B], source-declared/generated-binary. Do not hand-author vtable data as C++ table bytes. It should regenerate from the eventual class declaration.
- [UID:000357] `LivingObjectPaneBoxRotatorVtableData`: keep direct owner [UID:00007C], source-declared/generated-binary.
- [UID:0002WL] `LivingObjectPanePoolStaticStorage`: keep direct owner [UID:00007B], source-declared/generated-binary static storage. Best source-level declaration is likely a file/class static `PoolAllocator` instance for `LivingObjectPane` objects with block size `0x20c` and chunk count `0x20`, but exact declaration spelling remains provisional.
- [UID:0003EB] action `-1.0f` constant: keep file owner [UID:0000KU]. Best descriptive source name is `kInvalidActionDistance`, `kNoActionDistance`, or `kNoTargetDistance`; do not freeze until the action/auto-face packet helper source pass.
- [UID:00030B] `g_lastFunctionKeyTick`: keep file owner [UID:0000KU] as legacy/orphan function-key debounce state. Do not invent a write/update site.

Open issue resolved to best probability:

- The vtable and pool pages are not "no code" because they are unimportant. They are source-declared/generated-binary: the final rebuild needs declarations and class/static objects that cause compiler/linker output, not hand-coded binary data.

### 9. Stale/Historical Assumptions To Preserve And Mark Superseded

The target/support docs should keep these as historical assumptions but explicitly mark them superseded:

- [UID:00023H] was once considered a `LivingObjectPane` scattered accessor. It is now `EffectObjectPane::IsLooping() const`, reading `EffectObjectPane + 0x14c` after callers compare `+0x148` effect id. It remains a LivingObjectPane dependency/callee context only.
- `0x00537bc0` was once considered a scattered LivingObjectPane accessor. It belongs to [UID:00006V] `ItemObjectPane`, based on caller branch behavior where `object+0xf8 == 0` reaches ItemObjectPane and `object+0xf8 == 3` takes the LivingObjectPane branch.
- `0x005a8b80-0x005a8c5c` setters and live `0x005a8c60` option packet helper were once suspected LivingObjectPane word-slot helpers. [UID:00027W] resolved this island to OptionPane/NewOptionPane support, not LivingObjectPane.
- Generated `SoundManager::CancelTimer` and similar names for `0x00597610`/`0x00597630` are stale. The wrappers forward through `g_pTimerMgr` and belong to [UID:0000F0]/[UID:0000F1].
- Older generated local struct/class redeclarations in LivingObjectPane output are artifacts and should not be used as original header evidence.
- Older `90/90` or `95/95` code-entry text is stale. Current active gate is average score greater than `85` with valid emitter route, plus source-quality readiness.

## Function / Child Inventory

### Core, Vtable, Data, And Scattered Support

| UID | Path / range | Role | Current state | Source-quality/C++ direction |
| --- | --- | --- | --- | --- |
| [UID:000233] | `0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md` | GM suffix/wide-string check | `84/92`, owner/emitter [UID:0000KU], blank C++ | File-level helper; below active code gate because completion is 84. Keep as file-owned support. |
| [UID:0001DE] | `0x0053a110-0x0053d818.LivingObjectPaneCore.md` | Core split/index | `88/90`, owner `NONE`, `RECONSTRUCTABLE:FALSE` | Non-emitting index. No class/core C++. Exact children carry source. |
| [UID:0002R0] | `0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md` | Constructor variants and cleanup | `86/88`, owner/emitter [UID:00007B], blank C++ | Eligible but class declaration/field layout and allocator/source signature still block safe final C++. Add no-code proof, not guessed code. |
| [UID:0003Z3] | `0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md` | Sprite config/file-local direction helpers | `86/88`, owner/emitter [UID:0000KU], C++ present | Keep file owner because this includes file-local helper material. |
| [UID:0003Z4] | `0x0053aaf0-0x0053aeb4.LivingObjectPaneLinkedObjectSetupHelpers.md` | Linked object setup | `86/88`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:0001DF] | `0x0053aec0-0x0053b011.AttachedObjectDetachRegistry.md` | Attached object detach/deregister support | `88/91`, owner/emitter [UID:00007B], blank C++ | Eligible but support doc should explain exact call route from AttachedObjectPane and why final helper C++ needs attached-registry type declarations. |
| [UID:0003Z5] | `0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md` | Effects, movement start, action animation | `86/88`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:0002R1] | `0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md` | Animation/timer callbacks | `86/88`, owner/emitter [UID:00007B], blank C++ | Eligible but timer callback declarations, event ids, and fields still block safe final C++. Replace stale gate wording if present. |
| [UID:0003Z6] | `0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md` | Nameplate/special effect helpers | `86/88`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:0002R2] | `0x0053bb20-0x0053beb6.LivingObjectPaneRenderFrameMethods.md` | Render split/index | `88/90`, owner [UID:00007B], `RECONSTRUCTABLE:FALSE` | Keep non-emitting split/index. |
| [UID:0003NU] | `0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md` | RenderFrame exact child | `86/88`, owner/emitter [UID:00007B], blank C++ | Eligible but render context/helper/field names block safe final C++. |
| [UID:0003NV] | `0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md` | DrawSpriteFrame exact child | `85/88`, owner/emitter [UID:00007B], blank C++ | Eligible but sprite image helper signatures and frame fields block safe final C++. |
| [UID:0003NW] | `0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md` | ComputeRenderBounds exact child | `86/88`, owner/emitter [UID:00007B], blank C++ | Eligible but bounds struct/field/helper names block safe final C++. |
| [UID:0003Z7] | `0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md` | Position/mode propagation | `86/89`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:0003Z8] | `0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md` | Step-forward helper | `86/88`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:0002T6] | `0x0053d030-0x0053d053.LivingObjectPaneBoxRotatorScalarDeletingDestructor.md` | Nested helper scalar deleting destructor | `85/89`, owner/emitter [UID:00007C], blank C++ | Compiler-generated wrapper. Source responsibility is nested class destructor declaration, not hand-coded wrapper body. |
| [UID:0002R3] | `0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md` | LivingObjectPane scalar deleting destructor | `86/88`, owner/emitter [UID:00007B], blank C++ | Compiler-generated wrapper. Do not write source body; document destructor/free path. |
| [UID:0003Z9] | `0x0053d7c0-0x0053d7f4.LivingObjectPaneBoxRotatorAdvance.md` | BoxRotator advance callback | `87/91`, owner/emitter [UID:00007C], C++ present | Keep nested helper. |
| [UID:0003ZA] | `0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md` | ShowName/HideName | `86/90`, owner/emitter [UID:00007B], C++ present | Keep. |
| [UID:000357] | `0x0062096c-0x00620978.LivingObjectPaneBoxRotatorVtableData.md` | Nested RTTI/vtable | `88/92`, owner/emitter [UID:00007C], blank C++ | Source-declared/generated-binary. No hand-authored table. |
| [UID:000358] | `0x00620978-0x00620a38.LivingObjectPaneVtableData.md` | Main RTTI/vtables | `87/91`, owner/emitter [UID:00007B], blank C++ | Source-declared/generated-binary. No hand-authored table. |
| [UID:0003EB] | `0x00630c24-0x00630c28.LivingObjectPaneActionNegativeOneFloatConstant.md` | `-1.0f` action/auto-face sentinel | `88/92`, owner/emitter [UID:0000KU], blank C++ | File-level constant; exact source name still provisional. |
| [UID:0002WL] | `0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md` | Static pool storage | `85/91`, owner/emitter [UID:00007B], blank C++ | Source-declared/generated-binary static `PoolAllocator` storage. Final declaration spelling unresolved. |
| [UID:00030B] | `0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md` | Function-key debounce global | `86/88`, owner/emitter [UID:0000KU], blank C++ | File-level legacy/orphan state. No write site; do not invent update. |

### Local-Player Exact Children

| UID | Range/title | Current state | Best source-quality direction |
| --- | --- | --- | --- |
| [UID:0001KM] | `0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md` | `88/88`, owner `NONE`, `RECONSTRUCTABLE:FALSE` | Non-emitting split/index; exact children own source. |
| [UID:0002RW] | `0x005a2de0-0x005a2dfb.LivingObjectPaneGetViewportPosition.md` | `85/88`, owner/emitter [UID:0000KU], blank C++ | File-level helper/accessor. Formal code should wait until viewport/global names are source-quality. |
| [UID:0003U6] | `0x005a2e00-0x005a36de.LivingObjectPaneProcessMovement.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | LivingObjectPane local movement state machine. Packet/state fields block code. |
| [UID:0003U7] | `0x005a36f0-0x005a3766.LivingObjectPaneInitializeWalkAnimation.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Walk animation setup. Timer/walk state field names block code. |
| [UID:0003U8] | `0x005a3770-0x005a386a.LivingObjectPaneStartDirectionalAnimation.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Directional animation start. Source field names block code. |
| [UID:0003U9] | `0x005a3870-0x005a3889.LivingObjectPaneGetInventorySlotAddress.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Small slot accessor. Needs inventory slot type/prototype. |
| [UID:0003UA] | `0x005a3a20-0x005a3ad4.LivingObjectPaneRawConfigHotkeyHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw retained configured-hotkey helper, no proven route. |
| [UID:0003UB] | `0x005a3ae0-0x005a3d39.LivingObjectPaneExecuteHotkeyAction.md` | `86/89`, owner/emitter [UID:00007B], blank C++ | Live hotkey executor. Macro/config record names still block final code. |
| [UID:0001KN] | `0x005a3e30-0x005a3ff3.UseInventorySlotDispatch.md` | `86/90`, owner/emitter [UID:00007B], blank C++ | Inventory-slot dispatch. Needs slot/input-pane prototypes before final code. |
| [UID:0003UC] | `0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Command/spell-slot dispatch. Needs command slot table and prompt/input helper names. |
| [UID:0003UD] | `0x005a58c0-0x005a5983.LivingObjectPaneTryPerformAction.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Action gate/packet helper. Target/facing/packet layout block code. |
| [UID:0003UE] | `0x005a5a90-0x005a5b79.LivingObjectPaneWarpToPosition.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Warp/local position transition. Needs final field names and MapPane helper prototypes. |
| [UID:0003VE] | `0x005a87b0-0x005a87d5.LivingObjectPaneGetActiveLinkedRecordByIndexRaw.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw linked-record getter, no proven route. |
| [UID:0003UF] | `0x005a87e0-0x005a8809.LivingObjectPaneClearAllLinkedRecords.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Linked-record cleanup. |
| [UID:0003UG] | `0x005a8810-0x005a8832.LivingObjectPaneClearLinkedRecordByIndex.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Linked-record indexed cleanup. |
| [UID:0003UH] | `0x005a88d0-0x005a89c9.LivingObjectPaneUpdateScreenPosition.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Screen position update. Needs viewport/MapPane types. |
| [UID:0003UI] | `0x005a8cf0-0x005a8e67.LivingObjectPaneSendMovementPacket.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Movement packet send. Packet writer names block code. |
| [UID:0003UJ] | `0x005a9250-0x005a9307.LivingObjectPaneRawFunctionKeyDebounceHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route function-key debounce helper. Paired global [UID:00030B]. |
| [UID:0003UK] | `0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Best prose name `CopyDeferredPacketBuffer`; broader than movement. |
| [UID:0003UL] | `0x005aa480-0x005aa702.LivingObjectPaneParsePlayerSettingsPacket.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Settings packet parse. Packet struct names block code. |
| [UID:0003UM] | `0x005aa710-0x005aaa2c.LivingObjectPaneParseSpellSlotUpdatePacket.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Spell-slot update packet. Slot table/type names block code. |
| [UID:0003UN] | `0x005aac80-0x005aafe3.LivingObjectPaneHandleServerEntryPacket.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Server-entry/login-state packet. Account/login context should be documented but not moved to Login/UserPane. |
| [UID:0003UO] | `0x005aaff0-0x005ab084.LivingObjectPaneRawMovementCorrectionPacketHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route movement correction helper. |
| [UID:0003UP] | `0x005ab090-0x005ab410.LivingObjectPaneHandleMovementPacketA.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Movement packet handler A. Packet layout block. |
| [UID:0003UQ] | `0x005ab410-0x005ab75d.LivingObjectPaneHandleMovementPacketB.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Movement packet handler B. Packet layout block. |
| [UID:0003UR] | `0x005ab860-0x005aba7b.LivingObjectPaneHandleChatMessagePacket.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | Chat message packet handler; Chatting/SayInput are consumers/support, not owner. |
| [UID:0003US] | `0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md` | `88/88`, owner/emitter [UID:00007B], blank C++ | Retained duplicate/no-route body; live opcode `0x36` is inline in UserPane. Do not emit as normal called method. |
| [UID:0003UT] | `0x005abda0-0x005abee8.LivingObjectPaneHandleUIPanelSwitchPacket.md` | `85/87`, owner/emitter [UID:00007B], blank C++ | UI panel switch packet handler. |
| [UID:0003UU] | `0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Message show packet handler. |
| [UID:0003UV] | `0x005ac1b0-0x005ac27c.LivingObjectPaneRawPositionSyncPacketHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route position sync helper. |
| [UID:0003UW] | `0x005ac280-0x005ac69b.LivingObjectPaneParseLinkedObjectsPacket.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Linked-object packet parse. |
| [UID:0003UX] | `0x005ac7e0-0x005ac99b.LivingObjectPaneRawWaypointPacketHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route waypoint send helper. |
| [UID:0003UY] | `0x005ac9a0-0x005acad5.LivingObjectPaneRawFacingPacketHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route facing/linked-record send helper. |
| [UID:0003H4] | `0x005acae0-0x005acb1f.LivingObjectPaneSendDirectionPacketRawHelper.md` | `85/86`, owner/emitter [UID:00007B], blank C++ | Raw no-route direction packet helper. |
| [UID:0003H5] | `0x005acb20-0x005acc23.LivingObjectPaneAutoFaceDirectionPacketRawHelper.md` | `86/88`, owner/emitter [UID:00007B], blank C++ | Raw no-route auto-face direction helper. |
| [UID:0003UZ] | `0x005acc30-0x005acd85.LivingObjectPaneSendActionPacketWithAutoFace.md` | `86/89`, owner/emitter [UID:00007B], blank C++ | Live action packet helper with auto-face. Packet writer/type names block code. |
| [UID:0003V0] | `0x005ad360-0x005ad441.LivingObjectPaneSendAttackTargetPacket.md` | `86/89`, owner/emitter [UID:00007B], blank C++ | Attack target packet helper. Packet writer/type names block code. |

## Field / Type / Global Name Recommendations

These names are recommendations for target/support prose and IDA comments/types. They are descriptive best guesses unless marked confirmed by existing page evidence. Do not freeze a formal header from this table yet.

### Core Object Layout

| Offset | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `+0xa4` | `m_timerHandler` or `m_timerFacet` | Medium-high | LivingObjectPane animation/movement methods schedule/cancel timer callbacks through TimerHandler/TimerMgr. Exact inheritance vs embedded subobject remains declaration blocker. |
| `+0xf8` | `m_objectType` | High | Inherited ObjectPane field; object type `3` is living. |
| `+0xfc` | `m_objectId` / `m_serial` | High | Inherited ObjectPane id/serial field. |
| `+0x100` | `m_mapX` | High | Inherited ObjectPane map coordinate. |
| `+0x104` | `m_mapY` | High | Inherited ObjectPane map coordinate. |
| `+0x108` | `m_objectDataRect` | High | Inherited ObjectPane data rect. |
| `+0x118` | `m_attachedObject` | Medium-high | Inherited attached-object pointer. |
| `+0x11c` | `m_attachmentHeight` / `m_elevationOffset` | Medium | Inherited render/attachment height style field; exact source spelling unresolved. |
| `+0x120` | `m_objectImage` / `m_imageState` | Medium | Inherited/embedded object image state. Exact type unresolved. |
| `+0x124` | `m_transientObjectFlag` | Medium | Inherited flag; exact semantics still broad. |

### LivingObjectPane-Specific Fields

| Offset | Recommended name | Confidence | Evidence |
| --- | --- | --- | --- |
| `+0x170` | `m_type2AttachedObjects` | Medium-high | Attached object/list family; exact enum/source name unknown. |
| `+0x174` | `m_type4AttachedObjects` | Medium-high | Attached object/list family; exact enum/source name unknown. |
| `+0x178..+0x1bc` | `m_spriteConfig` / `m_livingSpriteConfig` | Medium-high | Sprite/config helper cluster covers a 68-byte style block. Exact struct layout remains unresolved. |
| `+0x1bc` | `m_activeEffectList` or `m_effectListHead` | Medium | Effect helpers manipulate active effects near this area; exact list/counter split not final. |
| `+0x1c0` | `m_activeEffectCount` or `m_effectState` | Medium-low | Paired with effect/list state; exact role needs child-level field pass. |
| `+0x1c4` | `m_isMoving` / `m_movementActive` | Medium-high | Movement/position sync paths test or set movement-active state. |
| `+0x1c5` | `m_facing` | High | Facing byte used by movement/render/action paths. |
| `+0x1c6` | `m_moveFrame` / `m_stepFrame` | Medium-high | Movement/forward-step frame state. |
| `+0x1c8` | `m_animationFrame` | Medium-high | Animation frame index. |
| `+0x1cc` | `m_animationGroup` / `m_animationId` | Medium | Animation frame group/id; exact source enum unresolved. |
| `+0x1d0` | `m_terminalAnimation` / `m_deadAnimationFlag` | Medium | Death/terminal animation behavior. Exact name unresolved. |
| `+0x1d1` | `m_nameVisible` | High | [UID:0003ZA] ShowName/HideName paths. |
| `+0x1d4` | `m_boxRotationStep` or `m_rotationFrame` | Medium | Rotation/box frame step counter; exact relation to `+0x1ec` needs declaration pass. |
| `+0x1d8` | `m_groundObject` | Medium-high | Linked ground object pointer. |
| `+0x1dc` | `m_shadowObject` | Medium-high | Linked shadow object pointer. |
| `+0x1e0` | `m_epfObject` / `m_effectObject` | Medium | Linked EPF/effect object pointer. Exact source spelling unresolved. |
| `+0x1e4` | `m_nameplateObject` | Medium-high | Linked nameplate object pointer. |
| `+0x1e8` | `m_markerOverlayEnabled` / `m_selectionOverlayMode` | Medium-low | Render methods read overlay/selection-style state. Exact semantics still not source-quality. |
| `+0x1ec` | `m_boxRotationPhase` | High | [UID:0003Z9] advances owner state modulo four. |
| `+0x1f0` | `m_boxRotator` | High | Nested helper subobject with BoxRotator vtable. |
| `+0x1f4` | `m_boxRotator.m_owner` | High | Owner pointer inside nested helper. |
| `+0x1f8` | `m_cachedRenderRect` / `m_refreshRectState` | Medium | Cached refresh/render state near object tail; exact type unresolved. |

### File-Level Globals/Data

| Item | Recommended source-facing name | Confidence | Notes |
| --- | --- | --- | --- |
| [UID:00030B] `0x0069bf74` | `g_lastFunctionKeyTick` | Medium-high for name, medium for lifecycle | Reads only in raw `0x005a9250`; no write site proven. |
| [UID:0003EB] `0x00630c24` | `kInvalidActionDistance`, `kNoTargetDistance`, or `kNoActionDistance` | Medium | `-1.0f` sentinel used by action/auto-face helpers; exact source name open. |
| [UID:0002WL] `0x0069b894` | `s_livingObjectPanePool` or `g_livingObjectPanePool` | Medium-high | Static PoolAllocator storage; block size `0x20c`, chunk count `0x20`. Exact static/global spelling open. |

## Ranked Ownership Analysis

### 1. [UID:0000KU] by-file/LivingObjectPane.md and [UID:00007B] by-class/LivingObjectPane.md

Evidence for:

- Source root exists and clears gate.
- Main class vtable, static pool, constructors/destructor, nested helper, core methods, and local-player movement/packet methods all cluster under the LivingObjectPane documentation family.
- Existing child pages already route exact methods to [UID:00007B] or file-level helpers to [UID:0000KU].
- Stale alternatives have been individually rejected by prior reports and current support pages.

Evidence against:

- Class declaration still incomplete.
- Local-player tail has adjusted `UserPane`-aggregate offsets and several raw no-route starts.
- Many exact emitting children still lack formal C++.

Decision: accepted. These limitations cap score and C++ readiness, but they do not defeat ownership/source placement.

### 2. [UID:0000FQ] UserPane

Evidence for:

- UserPane constructor/destructor wraps or owns a local living-object subobject.
- UserPane owns live input/server-message event methods, including the inline opcode `0x36` user-list path.
- Some local-player packet offsets likely belong to the UserPane aggregate viewed through an adjusted LivingObjectPane pointer.

Evidence against:

- Core LivingObjectPane vtable/static pool/constructor/destructor evidence is independent of UserPane.
- Movement, linked-object, animation, and command/packet helpers use living-object actor state.
- Prior [UID:0003VB]/[UID:0003US] report specifically separates live UserPane dispatcher ownership from retained LivingObjectPane duplicate/no-route body.

Decision: support/consumer/aggregate context only, not the canonical class owner.

### 3. [UID:00007Q] MapPane

Evidence for:

- MapPane renders and locates ObjectPane/LivingObjectPane instances and stores local player/active object pointers.
- LivingObjectPane calls MapPane APIs for position, bounds, and visibility work.

Evidence against:

- MapPane owns map spatial state and object list, not actor sprite/effect/local-player packet state.
- LivingObjectPane has its own vtable, constructors, pool, nested helper, and method clusters.

Decision: dependency/consumer only.

### 4. [UID:00009R] ObjectPane

Evidence for:

- LivingObjectPane inherits generic ObjectPane fields and behavior.
- Some offsets and render data are inherited.

Evidence against:

- ObjectPane does not own living-specific sprite, effect, nameplate, movement prediction, command-slot, or packet helper behavior.
- LivingObjectPane has a distinct vtable and static pool.

Decision: base class only.

### 5. [UID:000049] EffectObjectPane

Evidence for:

- LivingObjectPane scans effect-child collections and calls `EffectObjectPane::IsLooping`.

Evidence against:

- [UID:00023H] is now proven to read `EffectObjectPane +0x14c`, not a LivingObjectPane field.
- Consumers/callers do not transfer ownership.

Decision: dependency only. Keep [UID:00023H] excluded from the LivingObjectPane method family.

### 6. TimerHandler / TimerMgr

Evidence for:

- LivingObjectPane schedules/cancels animation/movement/timer events.

Evidence against:

- Timer wrapper bodies are generic scheduler helpers forwarding through `g_pTimerMgr`.
- Old `SoundManager::*` labels are generated artifacts.

Decision: dependency only. Update stale timer call labels if any support docs still include them.

## Open Questions And Attempted Resolution

| Issue | Evidence checked | Best current resolution | Score/C++ impact |
| --- | --- | --- | --- |
| Are raw local-player starts real functions? | Raw bytes, padding/prologues, PE route scan, support docs. | They are function-shaped source-authored or retained code bodies, but several have zero proven live routes. Keep exact child docs; do not treat as normal live methods. | Caps class completion and blocks broad final C++. |
| Should local-player tail fields be in `LivingObjectPane` class declaration? | [UID:0002WL] `0x20c` object pool size, [UID:0001KM], UserPane docs, packet child pages. | No. Treat `+0x13ebxx` fields as local-player/UserPane aggregate fields viewed through adjusted LivingObjectPane pointer until declaration is resolved. | Hard blocker for class declaration. |
| Should the class emit C++ now? | Active gate, class page role, child docs, unresolved fields, vtables, local-player tail. | No. Formal class declaration would be misleading. Exact method children own method bodies. | Keep class C++ blank. |
| Are stale generated `SoundManager` timer names valid dependencies? | TimerHandler/TimerMgr docs and wrapper pages. | No. Use TimerHandler/TimerMgr names. | Documentation cleanup only. |
| Is [UID:00023H] a LivingObjectPane method? | Prior B003 report, EffectObjectPane page, current class caveat. | No. It is `EffectObjectPane::IsLooping() const`. | Keep as dependency/historical correction. |
| Are `0x005a8b80-0x005a8c60` LivingObjectPane word-slot helpers? | Prior [UID:00027W] report. | No. Route to OptionPane/NewOptionPane. | Historical correction only. |
| Is `0x005abb20` a live handler? | Prior [UID:0003VB]/[UID:0003US] report and fresh PE route scan. | No live route proven. Live opcode `0x36` is inline in UserPane. | Do not emit [UID:0003US] as normal called method. |
| Is [UID:0003UK] only movement buffer setup? | [UID:0003US] and UserPane route docs, rel32 calls to `0x005a9310`. | Best prose name is `CopyDeferredPacketBuffer`; filename can stay until direct child pass. | Support doc rename-in-prose recommended. |
| Can vtable pages emit tables? | Vtable docs and by-structure generated-binary policy. | No hand-coded table; declarations should regenerate vtables. | No formal C++ in vtable pages until declaration. |

## C++ Readiness And Exact No-Code Proof

### Primary Class Page

Do not populate `by-class/LivingObjectPane.md` `RECONSTRUCTION_CPP` in the supervisor callback.

Target-specific no-code proof:

- A by-class page should emit class-level declarations, not method bodies. Exact method bodies already belong in child by-memory pages.
- The class declaration would need to decide whether `TimerHandler` is inherited, embedded, or an adjusted subobject at `+0xa4`. Current docs support timer dependency and state use, but not declaration spelling.
- The declaration would need to freeze base class stack and adjusted vtable views from [UID:000358]. Current vtable page records primary and adjusted views but not final virtual method prototypes/inheritance layout.
- The declaration would need to define the `0x178..0x1bc` sprite/config block and effect/list fields. Existing children document behavior but not final struct field list.
- The declaration would need to reconcile [UID:0002WL]'s `0x20c` LivingObjectPane pool block with local-player packet fields at `+0x13ebxx`. These large offsets almost certainly belong to a local UserPane/player aggregate viewed through an adjusted pointer, not the standalone LivingObjectPane object.
- The declaration would need to define packet-buffer, linked-record, command-slot, inventory-slot, movement-history, render-context, and object-image helper types. These remain spread across child pages and are not source-quality.
- Raw/no-route children such as `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`, `0x005acb20`, `0x005a87b0`, and `0x005abb20` should not be represented as normal live virtual/member methods without retained-dead-source policy.

Because of these blockers, a formal class skeleton would be more misleading than useful. The correct callback action is to document the blockers and best names in prose, not to write a placeholder class declaration.

### Exact Child Pages

No new child formal C++ should be inserted as part of this class report callback unless the supervisor separately accepts a direct child implementation checklist. Existing C++ in [UID:0003Z3], [UID:0003Z4], [UID:0003Z5], [UID:0003Z6], [UID:0003Z7], [UID:0003Z8], [UID:0003Z9], [UID:0003ZA], and [UID:00023H] should remain.

For blank eligible children, update no-code reasoning rather than add guessed C++:

- Constructors/destructors/scalar deleting destructors: block on class declaration or compiler-generated wrapper policy.
- Render children: block on render context/helper/field names, not old `90/90` policy.
- Local-player packet children: block on protocol structs, adjusted local-player layout, packet writer/helper signatures, and raw-route policy.
- Vtable/static storage/constant children: source-declared/generated-binary or source-declared data; need declaration spelling, not binary table bytes.

## Score / Metadata Recommendation

Target before: `85/85`, owner [UID:0000KU], reconstructable true, emitter [UID:0000KU], C++ blank.

Target after supervisor callback: `86/88`, owner [UID:0000KU], reconstructable true, emitter [UID:0000KU], C++ blank.

Rationale:

- Completion should rise by one point because the class page can now record the raw-route audit, local-player adjusted-layout interpretation, source-facing helper names, stale ownership rejections, generated-binary handling, and exact child C++ readiness policy.
- Confidence should rise to `88` because ownership/source placement is supported by class/file/core/local/vtable/static-pool evidence and fresh negative route scans. It should not rise higher because class declaration and local-player protocol types remain unresolved.
- Do not set either score above `90`. The class still lacks a final declaration, vtable prototype map, and source-quality local-player packet field/type model.
- Do not change `CANONICAL_OWNER`, `RECONSTRUCTABLE`, or `EMITTER_UIDS`.

Support metadata:

- No support doc score changes are required for the first implementation callback. If the implementing agent finds a support page still contains stale claims directly contradicted here, update prose first and keep score unchanged unless the supervisor explicitly accepts a support score change.
- [UID:0001DE], [UID:0001KM], and [UID:0002R2] should remain `RECONSTRUCTABLE:FALSE` split/index pages.
- [UID:000357], [UID:000358], [UID:0002WL], [UID:0003EB], and [UID:00030B] should keep current ownership/emitter routing.

## Implementation Instructions For Supervisor Callback

These are the exact edits I recommend applying if the supervisor accepts this report.

### Target Doc: `by-class/LivingObjectPane.md`

1. Update header scores:
   - `COMPLETION:85` -> `COMPLETION:86`
   - `CONFIDENCE:85` -> `CONFIDENCE:88`
   - Leave `CANONICAL_OWNER:0000KU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KU`, and blank `EMITTER_POSITION_OPTIONAL`.
   - Leave `RECONSTRUCTION_CPP` blank.

2. Add a `2026-06-19 B001 Rule 26 source-quality pass` status/change entry with these exact facts:
   - Source placement remains `NexusTK/map/LivingObjectPane.cpp`.
   - The class remains reconstructable and emitted through [UID:0000KU].
   - Formal class C++ remains blank with target-specific no-code proof because base/subobject layout, adjusted local-player fields, packet structs, render helper prototypes, vtable slot prototypes, and static declarations are not source-quality.
   - Fresh local PE route scan found zero rel32/absVA/RVA routes to `0x005a3a20`, `0x005a9250`, `0x005aaff0`, `0x005ac1b0`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`, `0x005acb20`, `0x005a87b0`, and `0x005abb20`; the same scan found live direct rel32 routes to `0x005a4530`, `0x005a3e30`, `0x005a58c0`, `0x005acc30`, and `0x005a5a90`.

3. Add or expand a `Source-Quality Class Declaration Readiness` section:
   - State that no formal class declaration should be emitted now.
   - Include the exact no-code proof from the C++ readiness section above.
   - State that method bodies belong to exact by-memory pages and should not be pasted into the class page.

4. Add or expand a `Source-Facing Field And Helper Name Direction` section:
   - Include the core object field table from this report.
   - Include the local-player `+0x13ebxx` field table and explicitly warn these likely belong to a UserPane/local-player aggregate viewed through an adjusted LivingObjectPane pointer.
   - Include file-level globals/data names: `g_lastFunctionKeyTick`, `s_livingObjectPanePool`/`g_livingObjectPanePool`, `kInvalidActionDistance`/`kNoTargetDistance`.

5. Add or expand a `Raw / Retained Local-Player Helpers` section:
   - Include the raw helper table and route scan result.
   - Mark all zero-route helper starts as raw retained/source-shaped bodies, not normal live methods.
   - Label [UID:0003US] as retained duplicate/no-route; live opcode `0x36` is inline in [UID:0003VB].

6. Add or expand `Historical Assumptions Superseded`:
   - [UID:00023H] is `EffectObjectPane::IsLooping`, not a LivingObjectPane accessor.
   - `0x00537bc0` is ItemObjectPane, not LivingObjectPane.
   - `0x005a8b80-0x005a8c60` is OptionPane/NewOptionPane support, not LivingObjectPane word-slot state.
   - `SoundManager::*` timer labels are stale TimerHandler/TimerMgr wrappers.
   - Old `90/90`/`95/95` C++ gate wording is stale.

7. Add or expand `Child Source Inventory`:
   - Incorporate the core/local-player child inventory above at report-level factual detail.
   - Do not prune blank-C++ children from the inventory; include their no-code reason.

### Support Doc Updates

Apply only content edits; no support score/metadata changes are required unless the supervisor explicitly asks.

1. `by-file/LivingObjectPane.md`:
   - Add a 2026-06-19 B001 note mirroring source placement, raw-route scan, stale exclusions, and class C++ no-code policy.
   - Add or update a file-level support list for `g_lastFunctionKeyTick`, `LivingObjectPaneActionNegativeOneFloatConstant`, and `LivingObjectPanePoolStaticStorage`.
   - Add the local-player adjusted-layout warning so `+0x13ebxx` fields are not mistaken for standalone `LivingObjectPane` object-size fields.

2. `by-memory/0x0053a110-0x0053d818.LivingObjectPaneCore.md`:
   - Add a short cross-reference to this class report direction.
   - Reaffirm non-emitting split/index role and exact child ownership.
   - No score/metadata change.

3. `by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md`:
   - Add the fresh PE route scan table for raw starts.
   - Add the positive-control live-call evidence for `0x005a4530`, `0x005a3e30`, `0x005a58c0`, `0x005acc30`, and `0x005a5a90`.
   - Add the adjusted local-player/UserPane aggregate field warning.
   - No score/metadata change.

4. Render child pages:
   - `by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md`
   - `by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md`
   - `by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md`
   - Replace any stale "below 90/90" no-code rationale with current active gate language: active gate is met, but formal C++ remains unsafe due render context/helper/field names.

5. `by-memory/0x005a9310-0x005a934a.LivingObjectPaneSetMovementBuffer.md`:
   - Add prose that the best source-facing name is `CopyDeferredPacketBuffer` or `CopyLocalPacketBuffer`; current filename can remain until a direct rename callback.
   - Explain it is used by user-list/deferred packet buffering as well as movement-adjacent local-player code.

6. `by-memory/0x005abb20-0x005abc6f.LivingObjectPaneHandleUserListPacket.md`:
   - Add the fresh zero-route PE scan result.
   - Keep retained duplicate/no-route policy.
   - Reaffirm live opcode `0x36` is inline in [UID:0003VB].

7. `by-class/UserPane.md`:
   - Add or confirm a note that UserPane owns the live UI dispatcher and opcode `0x36` inline user-list path, but this does not make the whole LivingObjectPane local-player helper family UserPane-owned.

8. `by-class/MapPane.md`, `by-class/ObjectPane.md`, `by-class/EffectObjectPane.md`, `by-class/TimerHandler.md`, `by-class/TimerMgr.md`:
   - No mandatory edits if the current relationships are already present.
   - If stale text is encountered during callback, add concise cross-notes preserving the exact owner/consumer boundaries described in this report.

### Generated/Source Output Expectations

- Do not edit `auto-generated/*` manually.
- Do not edit generated coverage reports manually.
- After accepted by-* edits validate, generated class coverage should still show [UID:00007B] as an emitter to `auto-generated/NexusTK/map/LivingObjectPane.cpp` with `has code: no` unless the supervisor chooses a separate tracker-comment policy. This report recommends blank formal C++, not a placeholder declaration.
- Do not insert method C++ into `by-class/LivingObjectPane.md`.

### Exact Coverage Text

For `by-memory/-coverage-report.md`: no replacement, insertion, or deletion is required by this class report.

Exact supervisor-owned pending coverage text:

```text
No by-memory/-coverage-report.md replacement row is required for [UID:00007B] LivingObjectPane class source-quality report. This task changes class/support prose and target class score metadata only; by-memory row changes are not needed unless a later implementation callback separately edits/renames by-memory child pages.
```

Generated class coverage row expected after validation/autogen if no formal C++ is inserted:

```text
| [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) | emits | `0000KU` | `0000KU` |  | no | `auto-generated/NexusTK/map/LivingObjectPane.cpp` | `by-class/LivingObjectPane.md` |  |
```

Do not hand-edit this generated row; it is included only to state the expected generated outcome.

### Validation Commands Needed After Implementation

Run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [00007B-LivingObjectPane-class-source-quality-removed.md](00007B-LivingObjectPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the optional support validators below if those pages are changed:

> Executable block R002 was removed from this report and preserved verbatim in [00007B-LivingObjectPane-class-source-quality-removed.md](00007B-LivingObjectPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After all accepted scoped validators pass, refresh generated output if the supervisor wants to inspect coverage/source-output state:

> Executable block R003 was removed from this report and preserved verbatim in [00007B-LivingObjectPane-class-source-quality-removed.md](00007B-LivingObjectPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

Use these for future IDA comments/renames or documentation prose. Do not force IDA edits during the report-only pass.

### Function Names

| Address | Recommended name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x0053a110` | `LivingObjectPane::LivingObjectPane(...)` constructor variant | Medium-high | Exact signature still unresolved. |
| `0x0053a360` | `LivingObjectPane::LivingObjectPane(...)` second constructor variant | Medium-high | Exact parameter differences unresolved. |
| `0x0053a5a0` | `LivingObjectPane::~LivingObjectPane` / cleanup body | Medium-high | Source destructor body distinct from scalar deleting wrapper. |
| `0x0053d430` | `LivingObjectPane::scalar_deleting_destructor` | High | Compiler-generated wrapper; document, do not source-port as handwritten method. |
| `0x0053d030` | `LivingObjectPane::BoxRotator::scalar_deleting_destructor` | High | Compiler-generated wrapper. |
| `0x0053d7c0` | `LivingObjectPane::BoxRotator::Advance` | High | Existing page has C++ and owner-pointer behavior. |
| `0x0053d800` | `LivingObjectPane::ShowName` | High | Name-visible byte set. |
| `0x0053d810` | `LivingObjectPane::HideName` | High | Name-visible byte clear. |
| `0x005a3a20` | `LivingObjectPane::DispatchConfiguredHotkeySlotRaw` | Medium | Function-shaped, no route. |
| `0x005a3ae0` | `LivingObjectPane::ExecuteHotkeyAction` | Medium-high | Live macro/hotkey executor. |
| `0x005a3e30` | `LivingObjectPane::UseInventorySlotDispatch` | High | Inventory/item use evidence. |
| `0x005a4530` | `LivingObjectPane::UseCommandSlotDispatch` | Medium-high | Command/spell slot dispatch. |
| `0x005a87b0` | `LivingObjectPane::GetActiveLinkedRecordByIndexRaw` | Medium-high behavior, low liveness | Raw no-route getter. |
| `0x005a9250` | `LivingObjectPane::DispatchFunctionKeyCommandWithDebounceRaw` | Medium | Raw no-route helper tied to `g_lastFunctionKeyTick`. |
| `0x005a9310` | `LivingObjectPane::CopyDeferredPacketBuffer` | Medium-high | Better prose name than `SetMovementBuffer`; title rename should be a direct child pass. |
| `0x005aaff0` | `LivingObjectPane::ApplyMovementCorrectionPacketRaw` | Medium | Raw no-route packet helper. |
| `0x005abb20` | `LivingObjectPane::HandleUserListPacketRetainedDuplicate` | Medium-high | Behavior known, no live route. |
| `0x005ac1b0` | `LivingObjectPane::HandlePositionSyncPacketRaw` | Medium | Raw no-route packet helper. |
| `0x005ac7e0` | `LivingObjectPane::SendWaypointPacketRaw` | Medium | Raw no-route send helper. |
| `0x005ac9a0` | `LivingObjectPane::SendFacingOrLinkedRecordPacketRaw` | Medium-low | Exact original role ambiguous; preserve uncertainty. |
| `0x005acae0` | `LivingObjectPane::SendDirectionPacketRaw` | Medium | Raw no-route helper. |
| `0x005acb20` | `LivingObjectPane::SendAutoFaceDirectionPacketRaw` | Medium | Raw no-route helper paired with live action helper. |
| `0x005acc30` | `LivingObjectPane::SendActionPacketWithAutoFace` | Medium-high | Live helper, one direct rel32 call from `0x005a5956`. |
| `0x005ad360` | `LivingObjectPane::SendAttackTargetPacket` | Medium-high | Existing child title. |

### Data Names

| Address | Recommended name | Confidence | Notes |
| --- | --- | --- | --- |
| `0x00620978` | `LivingObjectPane::vftable` / generated MSVC vtable | High | Source-declared/generated-binary; do not hand-author bytes. |
| `0x0062096c` | `LivingObjectPane::BoxRotator::vftable` | High | Source-declared/generated-binary. |
| `0x0069b894` | `s_livingObjectPanePool` or `g_livingObjectPanePool` | Medium-high | Static PoolAllocator instance; exact source spelling open. |
| `0x0069bf74` | `g_lastFunctionKeyTick` | Medium-high | No write site known; keep legacy/orphan caveat. |
| `0x00630c24` | `kInvalidActionDistance` / `kNoTargetDistance` | Medium | `-1.0f` action sentinel. |

### IDA Comments To Add If/When Editing IDA

- At each raw no-route start listed above: "Function-shaped retained LivingObjectPane local-player helper; 2026-06-19 PE scan found zero rel32/absVA/RVA routes. Keep as raw child until an indirect route or retained-dead-source policy is proven."
- At `0x005abb20`: "Retained duplicate/no-route user-list packet body. Live opcode 0x36 path is inline in UserPane::HandleServerMessage."
- At `0x005a9310`: "Copies deferred/local packet buffer; used by user-list/deferred packet paths; title `SetMovementBuffer` is too narrow."
- At `0x0069bf74`: "Legacy function-key debounce tick read only by raw no-route helper 0x005a9250; no write site proven."

## Validator Results

- No by-* docs were modified in this report-only pass.
- No validator commands were run because the only changed file is this B001 research report.
- Validator commands required after implementation are listed above.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00007B-LivingObjectPane-class-source-quality.md`
- Modified: none outside the report file.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"00007B"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00007B-LivingObjectPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00007B-LivingObjectPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00007B"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
