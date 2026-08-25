** TARGET-REPORT-UID:0002QH **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 MapPane Teardown/Object Packet Source-Quality Report

Assignment id: `B002-goal2-mappane-teardown-object-packet-source-quality-0002QH-0002QI-0002QO-0002QP-0002QQ-000231-20260618`

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md`

Report-only statement: I did not edit by-* documentation, generated reports, generated source, IDA databases, or `by-memory/-coverage-report.md`. This report contains supervisor-applied replacement text and first-draft C++ recommendations only.

## Summary Recommendations

| UID | Current target | Recommended source name | Owner / emitter | Score recommendation | Formal C++ |
| --- | --- | --- | --- | --- | --- |
| `0002QH` | `0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown` | `MapPane::ExitToMenu(bool notifyServer)` / `MapPane::ExitToMenu(bool sendLogoutPacket)` | keep `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q` | raise to `COMPLETION:88`, `CONFIDENCE:90` | populate first-draft C++ |
| `0002QI` | `0x00504b70-0x00504b8f.MapPaneTagDetachMessage` | `MapPane::OnTagDetachMessage(Pane *sender, const TaggedPaneMessage *message)` | keep `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q` | raise to `COMPLETION:88`, `CONFIDENCE:91` | populate first-draft C++ |
| `0002QO` | `0x005060f0-0x00506169.MapPaneRemoveObjectPaneById` | `MapPane::RemoveObjectPaneById(int objectId)` | keep `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q` | raise to `COMPLETION:88`, `CONFIDENCE:90` | populate first-draft C++ |
| `0002QP` | `0x00506170-0x005061d3.MapPaneDetachObjectPane` | `MapPane::DetachObjectPane(ObjectPane *objectPane)` | keep `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q` | raise to `COMPLETION:88`, `CONFIDENCE:90` | populate first-draft C++ |
| `0002QQ` | `0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect` | `MapPane::HasObjectIntersectingRect(const Rect *rect) const` | keep `CANONICAL_OWNER:00007Q`, `EMITTER_UIDS:00007Q` | raise to `COMPLETION:88`, `CONFIDENCE:90` | populate first-draft C++ |
| `000231` | `0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper` | file-static `SendObjectRefreshRequest(int objectId)` / `RequestMissingObjectById(int objectId)` | keep `CANONICAL_OWNER:0000L3`, `EMITTER_UIDS:0000L3` | raise to `COMPLETION:88`, `CONFIDENCE:90` | populate first-draft C++ as a `MapPane.cpp` static helper |

All six targets meet the active code-entry gate after reanalysis. The old "blank until 95/95" or "packet/helper names provisional" gate wording is stale for these targets. Remaining exact-spelling uncertainty caps confidence but does not block first-draft code because behavior, ownership, and source placement are now defensible.

## Evidence Checked

- Target pages:
  - [UID:0002QH] `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`
  - [UID:0002QI] `by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md`
  - [UID:0002QO] `by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md`
  - [UID:0002QP] `by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md`
  - [UID:0002QQ] `by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md`
  - [UID:000231] `by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md`
- Owner/support pages: [UID:00007Q] `by-class/MapPane.md`, [UID:0000L3] `by-file/MapPane.md`, [UID:0001AP] `MapPaneWeatherCoordinateObjectCore`, [UID:0002SQ] `MapPaneVtableData`.
- Object support pages: [UID:00009R] `by-class/ObjectPane.md`, [UID:0000M5] `ObjectPane`, [UID:0002SK] `ObjectPaneVtableData`, [UID:0003XN] `ObjectPane` constructor, [UID:0003XV] `ObjectPaneInvalidateObjectDataRect`, [UID:0003XZ] `ObjectPaneGetObjectData`, [UID:0002CA] `ObjectListTypeDispatchRemove`, [UID:0002CD] `ObjectListFindByObjectId`, [UID:0001D3] `ObjectList` accessors, [UID:00009Q] `ObjectList`.
- Object subtype evidence: `ItemObjectPane` update path using type `0`, `FlyingObjectPane` constructor/tick using type `1`, `LivingObjectPane` cleanup/type-3 branch and `DestroyAllLinkedObjects`, `StaticObjectPane` constructor using type `5`.
- Cleanup support: [UID:0003XC] `0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease`, [UID:0000Z1] `BlackHoleQueuePaneForDeferredDeletion`, [UID:0001G5] `ScreenPane`.
- Packet support: [UID:0001SO] `MapServerPacketOpcode`, [UID:0001HZ] `PacketBufferHelpers`, [UID:0003YM] `PacketBufferCursorAppendBigEndianHelpers`, [UID:0001HU] `QueueAndSendPacket`, [UID:0000Q5] `g_packetSender`, [UID:0001JY] `CashShopRequestWaitDispatch`.
- Caller/support context: [UID:0002H3] `ApplicationRequestExit`, [UID:00038L] `ReconnectDialogMethods`, [UID:0001KS] `QuitInputPaneCore`, [UID:0001KT] `QuitDialogCore`, [UID:0000YZ] `BalloonObjectPane`.
- Current coverage rows in `by-memory/-coverage-report.md` were checked for the six UIDs and replacement rows are supplied below.

## Heuristic / Inference Reanalysis And Validation

### [UID:0002QH] `MapPaneExitToMenuTeardown`

Evidence checked:

- The target page records one modeled function at `0x005047f0-0x00504b6b`, with padding before and before the next `MapPane` helper at `0x00504b70`.
- Current behavior is not just a destructor-like cleanup: it clears the active application/session byte, tears down map-owned panes, saves compressed map cache state, saves user settings, removes active gameplay singleton panes, optionally sends one-byte opcode `0x0b`, drains/locks the packet sender, and constructs a replacement main-menu pane.
- Direct caller set includes `ApplicationRequestExit`, `ReconnectDialog::OnButtonClick` at `0x00554271`, `QuitInputPaneCore`, and `QuitDialogCore`; the quit-dialog OK path passes `1`, matching the optional packet/send flag.
- `ReconnectDialogMethods` resolves the older unresolved `0x00554210` body as `ReconnectDialog::OnButtonClick`. That caller is a consumer of the MapPane exit path, not a MapPane ownership challenger.
- `MapServerPacketOpcode` documents inbound `0x0b` as an accepted no-op/ack case, while this function sends outbound opcode `0x0b`. The direction differs; these should be cross-referenced, not merged.
- `g_packetSender` support resolves the global as best current `Socket *`, not the stale generated `CashShopRequest *` alias.

Best defensible source direction:

- Source method name should be `MapPane::ExitToMenu(bool notifyServer)` or `MapPane::ExitToMenu(bool sendLogoutPacket)`. `ExitToMenu` is stronger than the current "Teardown" title because the method is reached from quit/reconnect/application exit UI flows and constructs the replacement main menu after teardown.
- The boolean parameter controls only the optional outbound opcode `0x0b` send. It does not control the general UI teardown, map save, user-settings save, or replacement menu construction.
- `MapPane +0x414` should be documented descriptively as a map-owned pane queued through `BlackHole` for deferred cleanup. Best current field name is `m_deferredCleanupPane` / `m_pendingCleanupPane`. Exact original spelling is not recoverable from current evidence, but behavior is strong and the field should not remain an unnamed offset.
- `MapPane +0x41c` should remain `m_auxiliaryPane` or `m_ownedAuxiliaryPane`; it is deleted through virtual cleanup with a delete/free flag and then cleared.
- `MapPane +0x420` should remain `m_activeScreenLayer`; QH removes it from `ScreenPane`, invokes virtual cleanup, and clears it.

Rejected alternatives:

- Reject "ordinary destructor" or "MapPane destructor tail": the function saves map/user state, optionally sends a protocol packet, and allocates a replacement menu pane. It is an explicit transition action.
- Reject assigning this to `ReconnectDialog`, `QuitDialog`, or `Application`: those are callers that trigger the transition. The body consumes MapPane fields and belongs to `MapPane`.
- Reject treating outbound `0x0b` as the inbound no-op/ack enum value. The byte is the same, but the direction and call path are different.
- Reject generated `g_pCashShopRequest` aliases for the packet sender. The current global support page resolves `g_packetSender` to `Socket *`.

Validation/contradiction of current docs:

- Current docs are behaviorally correct but under-name the source action and retain stale blank-C++ gate wording.
- The unresolved `0x00554210` caller caveat is stale; it is `ReconnectDialog::OnButtonClick`.
- The target is source-bearing and should emit through [UID:00007Q] `MapPane`.

Unresolved blockers and impact:

- Exact original helper names for the long singleton-pane destruction segment remain unavailable. This caps confidence at `90`, but does not block first-draft C++ because each helper is a local teardown dependency and the MapPane method behavior is stable.

### [UID:0002QI] `MapPaneTagDetachMessage`

Evidence checked:

- The target page records one modeled `0x1f` byte function at `0x00504b70-0x00504b8f`, immediately after QH.
- `MapPaneVtableData` places `0x00504b70` in the primary `MapPane` vtable family, so no direct code caller is expected.
- The body returns with `retn 8`, takes two explicit arguments, reads dword at the second argument plus `4`, compares against `0x676f6f67`, and queues `this` through `g_pApplicationCleanupQueue` / `BlackHole` on match.
- The constant `0x676f6f67` is ASCII/FOURCC bytes `67 6f 6f 67`, source-facing tag `'goog'`. AboveFrame and pane-registration docs also use the same `goog` notification/tag pattern.
- `BlackHoleQueuePaneForDeferredDeletion` is a well-modeled helper that detaches layer/event/timer registrations, deduplicates, and queues the pane.

Best defensible source direction:

- Source method should be modeled as a virtual pane-message callback:
  - `void MapPane::OnTagDetachMessage(Pane *sender, const TaggedPaneMessage *message)`
  - Acceptable alternate: `MapPane::OnPaneMessage(Pane *sender, const PaneMessage *message)` with a documented `tag` field at offset `+4`.
- The tag should be named `kPaneTagGoog` or `kRootPaneChangeTagGoog`, value `0x676f6f67`.
- The first explicit argument is unused in the body and should remain named `sender` or `source`; the second argument is the message/event payload.

Rejected alternatives:

- Reject "dead function" from no direct callers. Vtable placement is sufficient reachability for a virtual callback.
- Reject `ObjectPane` or `BlackHole` ownership. `BlackHole` is a cleanup queue dependency; it does not own the message callback.
- Reject treating the tag as a magic integer without a name; the ASCII/FOURCC interpretation is strong and corroborated by neighboring pane docs.

Validation/contradiction of current docs:

- Current docs correctly describe vtable/no-direct-caller behavior and the cleanup effect, but they should resolve the tag and callback signature instead of leaving generated/provisional wording.
- Formal C++ is ready as a short virtual callback under [UID:00007Q].

Unresolved blockers and impact:

- Exact original callback base type is still not known. This caps confidence at `91` instead of final-source quality, but the method signature shape, two explicit arguments, tag offset, and source owner are strong enough for C++.

### [UID:0002QO] `MapPaneRemoveObjectPaneById`

Evidence checked:

- The target page records one modeled `0x79` byte function at `0x005060f0-0x00506169`.
- It searches `MapPane +0x424` (`m_objectList`) through `ObjectListFindByObjectId` using object field `+0xfc`.
- If the found object type byte at `ObjectPane +0xf8` is `3`, the method follows the `LivingObjectPane` branch: it checks MapPane selected-object fields at `+0x108/+0x10c`, calls the living highlight toggle with `false` when the selected pointer equals the removed pane, clears the selected fields, and calls `0x0053ab40`.
- `LivingObjectPaneCore` documents `0x0053ab40` as `LivingObjectPane::DestroyAllLinkedObjects`.
- All found object panes are removed from the `ObjectList` through [UID:0002CA], invalidated through the object-pane virtual invalidation helper, then deleted through the scalar deleting destructor path.
- Caller evidence is packet/object-update and terminal object lifecycle cleanup: map packet handlers at `0x005082e3`/`0x005089d1`, unmodeled object/status update refs at `0x00511c83`/`0x00513d86`, `FlyingObjectPane` terminal tick, and `LivingObjectPane` animation/movement cleanup.

Best defensible source direction:

- Source method should be `void MapPane::RemoveObjectPaneById(int objectId)`.
- The decompiler's apparent return of `0` or the scalar deleting destructor result should be treated as an artifact. Returning a deleted object pointer would be source-hostile and no current caller evidence shows meaningful return consumption.
- `MapPane +0x108` should be named `m_selectedObjectActive` or `m_selectedLivingObjectActive`.
- `MapPane +0x10c` should be named `m_selectedObjectPane` or `m_selectedLivingObjectPane`.
- Because QO only tests and clears these fields in the living-object branch, the best documentation name is `m_selectedLivingObjectPane` with a broader alias `m_selectedObjectPane` until more UI selection producers are identified.
- Object type `3` should be documented as `ObjectPaneType::Living`.
- The object virtual invalidation should be represented as `objectPane->InvalidateObjectDataRect()`, backed by [UID:0003XV].

Rejected alternatives:

- Reject `ObjectList::RemoveById` ownership. The search and type-dispatch removal are dependencies; the method also clears MapPane selection state and living-object linked children.
- Reject source return type `ObjectPane *` unless a future IDA pass proves callers test the return. Current behavior is a side-effect removal/delete action.
- Reject final names such as `spriteIndex` for `+0xfc`; ObjectList search support resolves it as object id/serial.
- Reject leaving `+0x108/+0x10c` unnamed; the selected/highlighted living object semantics are directly visible.

Validation/contradiction of current docs:

- Current behavior notes are correct. The remaining "medium for final selected-object field names" caveat can be replaced by high-probability source field names.
- The current title is source-compatible if interpreted as void; formal code should avoid returning a deleted pointer.

Unresolved blockers and impact:

- Exact original noun may have been "target", "selected", "focused", or "highlighted". The branch action strongly ties it to selected/highlighted living-object state; exact spelling uncertainty caps confidence at `90` but does not block C++.

### [UID:0002QP] `MapPaneDetachObjectPane`

Evidence checked:

- The target page records one modeled `0x63` byte function at `0x00506170-0x005061d3`.
- The body calls object-pane virtual slot `+0x28` to copy a 16-byte rect-like record to the stack.
- [UID:0003XZ] resolves that virtual as `ObjectPane::GetObjectData(Rect *out) const`, copying `ObjectPane +0x108`.
- The method invalidates that old object-data rectangle through the MapPane/Pane invalidation path, removes the object pane from `m_objectList`, conditionally calls `0x004b97d0` when object type is not `5`, and deletes the object pane.
- [UID:0003XC] resolves `0x004b97d0` as `GrafPort::ReleaseBackingStore`: it frees software backing buffer state at `+0x94/+0x98` and releases DirectDraw backing surface at `+0x18`.
- `StaticObjectPane` constructor explicitly constructs `ObjectPane` with type `5`. This validates `ObjectPaneType::Static = 5`.
- QP callers are the create/update replacement path and `FlyingObjectPane` terminal cleanup, both MapPane object-lifecycle contexts.

Best defensible source direction:

- Source method should be `void MapPane::DetachObjectPane(ObjectPane *objectPane)`.
- The object-data virtual should be `objectPane->GetObjectData(&oldRect)`.
- The invalidation call should be `InvalidateRect(&oldRect)` or the local MapPane equivalent.
- The auxiliary cleanup helper should be documented as `GrafPort::ReleaseBackingStore(objectPane)` or `objectPane->ReleaseBackingStore()` if the final class layout exposes the inherited backing-store helper as a member.
- The type guard should use `ObjectPaneType::Static` for value `5`, with the note that static object panes skip this non-static backing-store release because their image resources are provider-owned through `StaticObjImageLib`.

Rejected alternatives:

- Reject naming `0x004b97d0` as an ObjectPane-only destructor helper. Its owner is GrafPort/graphics backing-store cleanup and it has broader cleanup/render callers.
- Reject treating type `5` as "special item" or unknown. StaticObjectPane constructor evidence is explicit.
- Reject `ObjectList` ownership: QP invalidates MapPane state and deletes the object pane after using ObjectList as an index dependency.

Validation/contradiction of current docs:

- Current docs are correct on behavior, but "non-type-5 auxiliary resources" should be sharpened to "non-static object-pane backing store through `GrafPort::ReleaseBackingStore`."
- Formal C++ is ready.

Unresolved blockers and impact:

- Exact source spelling of the inherited release helper remains uncertain. It is a dependency name, not a source-placement blocker. Confidence should cap at `90`.

### [UID:0002QQ] `MapPaneFindObjectIntersectingRect`

Evidence checked:

- The target page records one modeled `0x8a` byte function at `0x005062f0-0x0050637a`, with six `0xcc` bytes before the opcode `0x0c` helper at `0x00506380`.
- The method reads `MapPane +0x424`, obtains the visible object list through the ObjectList accessor at `0x00532610`, checks the list count, iterates entries through the list vtable accessor, asks each object pane for its object-data rect through [UID:0003XZ], and calls [UID:00015S] `IntersectRects`.
- It returns `1` on the first intersection and `0` otherwise; `retn 4` means one explicit rectangle pointer argument.
- Sole known caller is [UID:0000YZ] `BalloonObjectPane`, which adjusts a candidate balloon rectangle downward when it intersects visible object bounds.

Best defensible source direction:

- Source method should be `bool MapPane::HasObjectIntersectingRect(const Rect *rect) const` or `bool MapPane::AnyObjectIntersectsRect(const Rect *rect) const`.
- The current title `FindObjectIntersectingRect` is acceptable as a documentation alias only if the docs say it returns a boolean, not an object pointer.
- The visible-list dependency should be `m_objectList->GetVisibleObjectList()` or `m_objectList->GetPrimaryVisibleList()`. `GetVisibleObjectList` is best because [UID:0001D3] and traces already use that name.
- The list entry accessor should be documented as inherited `List::GetElementAt`.

Rejected alternatives:

- Reject `ObjectList::FindObjectAt` ownership: this query is driven by a caller-supplied arbitrary rectangle, not an object-list coordinate key lookup.
- Reject returning an `ObjectPane *`; the body returns a boolean and does not preserve the matching pointer.
- Reject emitting this as BalloonObjectPane code. BalloonObjectPane is the caller, but the method scans MapPane's object list.

Validation/contradiction of current docs:

- Current body documentation is accurate, but the source-facing name should change from "Find" to "Has/Any intersects" to avoid implying pointer return.
- Formal C++ is ready.

Unresolved blockers and impact:

- Exact original verb may have been "Check", "Has", or "Intersects". This only caps naming confidence; behavior is strong enough for first-draft C++.

### [UID:000231] `MapPaneOpcode0CObjectIdPacketHelper`

Evidence checked:

- The target page records one modeled `0x5b` byte helper at `0x00506380-0x005063db`, adjacent to QQQ and before profile sidecar helpers.
- The helper has no `this` receiver: it takes only an object id, initializes a packet cursor, writes opcode byte `0x0c`, writes a 32-bit object id through the PacketBuffer cursor big-endian writer, then queues exactly five bytes through `g_packetSender`.
- Direct callers live in the MapPane packet/object-update family:
  - inbound dispatcher branch at `0x00508142`,
  - unmodeled handler tail at `0x00511ab2`,
  - status/object update branch at `0x0051366f` after an object lookup miss.
- `MapServerPacketOpcode` documents inbound opcode `0x0c` as object action/animation update. That inbound handler requests a missing-object refresh when the object id cannot be resolved, which matches this helper's outbound request role.
- Packet support resolves the byte writer and uint32 big-endian appender through [UID:0003YM]; `QueueAndSendPacket` and `g_packetSender` are Socket-owned dependencies.

Best defensible source direction:

- Keep [UID:000231] attached to [UID:0000L3] `MapPane` file, not [UID:00007Q] class. It is a file-static helper in `NexusTK/map/MapPane.cpp`.
- Best source name: `static void SendObjectRefreshRequest(int objectId)`.
- Acceptable alternate: `static void RequestMissingObjectById(int objectId)`.
- Packet semantics: outbound opcode `0x0c`, five-byte client object-id refresh/missing-object request. It should be documented as an outbound cross-reference, not as a new inbound enum entry.
- Scratch/padding after the five bytes is local buffer hygiene and should not be represented as packet payload.

Rejected alternatives:

- Reject class ownership under [UID:00007Q]; there is no `this` receiver or MapPane field access.
- Reject Socket/PacketBuffer ownership. Those helpers serialize and send, but they do not own the map-object refresh semantics.
- Reject treating outbound `0x0c` as the same logical packet as inbound `0x0c` object action/animation update. It is a response/request triggered by missing object state in that handler.
- Reject leaving code blank because writer names were provisional. `PacketBufferAppendUInt8`, `PacketBufferAppendUInt32BE`, `QueueAndSendPacket`, and `g_packetSender` are now sufficiently documented for first-draft C++.

Validation/contradiction of current docs:

- Current byte-level docs are correct, but the "do not convert this page into final C++ yet" text is stale under the active gate.
- The owner/emitter route in current docs is correct: file root [UID:0000L3], not class [UID:00007Q].

Unresolved blockers and impact:

- Exact original helper spelling remains unknown. Confidence should cap at `90`, but a descriptive static helper is appropriate for formal first-draft C++.

### Cross-Target Object Type And Field Conclusions

Recommended `ObjectPaneType` values for support docs and target notes:

| Value | Recommended enum name | Evidence |
| --- | --- | --- |
| `0` | `ObjectPaneType::Item` / `GroundItem` | Item-object record/update branch tests `ObjectPane +0xf8 == 0`; ItemObjectPane constructor/state-update paths own ground item fields. |
| `1` | `ObjectPaneType::FlyingItem` / `FlyingObject` | `FlyingObjectPane` constructor sets `ObjectPane +0xf8` to `1`; terminal tick calls QO/QP cleanup paths. |
| `3` | `ObjectPaneType::Living` | QO type-3 branch calls LivingObjectPane highlight toggle and `DestroyAllLinkedObjects`. |
| `5` | `ObjectPaneType::Static` | `StaticObjectPane` constructor builds `ObjectPane` with type `5`; QP skips backing-store release for type `5`. |

Recommended `MapPane` selection fields:

| Offset | Recommended field name | Evidence |
| --- | --- | --- |
| `MapPane +0x108` | `m_selectedObjectActive` / `m_selectedLivingObjectActive` | QO tests it only in the type-3 living-object branch and clears it after disabling highlight on the selected object. |
| `MapPane +0x10c` | `m_selectedObjectPane` / `m_selectedLivingObjectPane` | QO compares it against the removed living object, then clears it with the active flag. |

Recommended QH UI/lifecycle fields:

| Offset | Recommended field name | Evidence |
| --- | --- | --- |
| `MapPane +0x414` | `m_deferredCleanupPane` / `m_pendingCleanupPane` | QH queues this pane through `BlackHole::QueuePaneForDeferredDeletion` and clears the field. Exact producer/name is still not recovered. |
| `MapPane +0x41c` | `m_auxiliaryPane` / `m_ownedAuxiliaryPane` | QH invokes virtual delete/free cleanup and clears it. Existing MapPane support already uses `m_auxiliaryPane`. |
| `MapPane +0x420` | `m_activeScreenLayer` | QH removes it from `ScreenPane`, invokes virtual cleanup, and clears it. Existing MapPane support already uses `m_activeScreenLayer`. |

## First-Draft C++ Recommendation

Populate formal C++ for all six target pages. These drafts intentionally use descriptive helper names where original source spelling is not known; those names are supported by current docs and should not block first-draft emission.

### [UID:0002QH] `MapPane::ExitToMenu`

```cpp
void MapPane::ExitToMenu(bool notifyServer)
{
    if (g_pApplication != nullptr) {
        g_pApplication->m_inMapSession = false;
    }

    SaveCompressedMapFile();
    SaveUserSettings();

    if (m_deferredCleanupPane != nullptr) {
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(m_deferredCleanupPane);
        m_deferredCleanupPane = nullptr;
    }

    if (m_auxiliaryPane != nullptr) {
        m_auxiliaryPane->DeletePane(true);
        m_auxiliaryPane = nullptr;
    }

    if (m_activeScreenLayer != nullptr) {
        g_pScreenPane->RemovePane(m_activeScreenLayer);
        m_activeScreenLayer->DeletePane(true);
        m_activeScreenLayer = nullptr;
    }

    DestroyGameplayPanesForExitToMenu(g_useEpfAssets);

    if (notifyServer) {
        PacketCursor packet = {};
        PacketBufferAppendUInt8(&packet, 0x0b);
        g_packetSender->QueueAndSendPacket(packet.data, 1);
    }

    g_packetSender->Lock();
    CashShopRequestWaitDispatch(g_packetSender);
    new MainMenuPane(0);
    g_packetSender->Unlock();
}
```

Notes for supervisor when applying:

- `DestroyGameplayPanesForExitToMenu` is a first-draft summary helper for the existing long singleton-pane teardown sequence. If formal style requires exact calls only, keep the sequence inline and retain the descriptive comment.
- `DeletePane(true)` represents the observed virtual cleanup/delete-flag call. Use the repository's accepted pane-delete spelling if already standardized.
- The raw function clears a local byte after opcode `0x0b` but sends length `1`; the zero byte is not payload.

### [UID:0002QI] `MapPane::OnTagDetachMessage`

```cpp
struct TaggedPaneMessage
{
    std::uint32_t unused0;
    std::uint32_t tag;
};

static constexpr std::uint32_t kPaneTagGoog = 0x676f6f67;

void MapPane::OnTagDetachMessage(Pane *sender, const TaggedPaneMessage *message)
{
    (void)sender;

    if (message->tag == kPaneTagGoog) {
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    }
}
```

Notes for supervisor when applying:

- Do not add a source null guard unless another pane-message helper in the same family shows one. The raw body directly reads `message + 4`.
- If the support docs standardize a message type name, replace `TaggedPaneMessage` with that type but keep the `tag` field at offset `+4`.

### [UID:0002QO] `MapPane::RemoveObjectPaneById`

```cpp
void MapPane::RemoveObjectPaneById(int objectId)
{
    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == nullptr) {
        return;
    }

    if (objectPane->m_objectType == ObjectPaneType::Living) {
        LivingObjectPane *livingPane = static_cast<LivingObjectPane *>(objectPane);

        if (m_selectedObjectActive && m_selectedObjectPane == livingPane) {
            livingPane->SetHighlighted(false);
            m_selectedObjectActive = false;
            m_selectedObjectPane = nullptr;
        }

        livingPane->DestroyAllLinkedObjects();
    }

    m_objectList->RemoveByType(objectPane);
    objectPane->InvalidateObjectDataRect();
    delete objectPane;
}
```

Notes for supervisor when applying:

- Use `void`, not a pointer return, unless a future caller audit proves the return value is consumed. The observed destructor-return value is a decompiler/compiler artifact.
- `SetHighlighted(false)` is the descriptive name for the living-object highlight toggle. If [UID:0001DE] has a stronger accepted name, use it.

### [UID:0002QP] `MapPane::DetachObjectPane`

```cpp
void MapPane::DetachObjectPane(ObjectPane *objectPane)
{
    Rect oldObjectRect;
    objectPane->GetObjectData(&oldObjectRect);
    InvalidateRect(&oldObjectRect);

    m_objectList->RemoveByType(objectPane);

    if (objectPane->m_objectType != ObjectPaneType::Static) {
        GrafPort::ReleaseBackingStore(objectPane);
    }

    delete objectPane;
}
```

Notes for supervisor when applying:

- If the final class layout exposes the backing-store release as an inherited member, `objectPane->ReleaseBackingStore()` is acceptable. The owner of the physical helper remains GrafPort, not ObjectPane.
- The raw body does not prove a null guard; do not add one unless the surrounding source style requires defensive checks.

### [UID:0002QQ] `MapPane::HasObjectIntersectingRect`

```cpp
bool MapPane::HasObjectIntersectingRect(const Rect *rect) const
{
    List *visibleObjects = m_objectList->GetVisibleObjectList();
    const int count = visibleObjects->GetCount();

    for (int index = 0; index < count; ++index) {
        ObjectPane *objectPane = static_cast<ObjectPane *>(visibleObjects->GetElementAt(index));
        Rect objectRect;
        objectPane->GetObjectData(&objectRect);

        if (IntersectRects(rect, &objectRect, nullptr)) {
            return true;
        }
    }

    return false;
}
```

Notes for supervisor when applying:

- The target title can stay as a compatibility alias, but the formal C++ should use `Has`/`Any` wording because the method returns a bool, not the matching object pointer.

### [UID:000231] file-static `SendObjectRefreshRequest`

```cpp
static void SendObjectRefreshRequest(int objectId)
{
    PacketCursor packet = {};
    PacketBufferAppendUInt8(&packet, 0x0c);
    PacketBufferAppendUInt32BE(&packet, static_cast<std::uint32_t>(objectId));
    g_packetSender->QueueAndSendPacket(packet.data, 5);
}
```

Notes for supervisor when applying:

- Place this in `NexusTK/map/MapPane.cpp` as a file-static helper near map packet/object update helpers.
- Acceptable name if the supervisor prefers caller-context wording: `RequestMissingObjectById`.
- Do not attach this as a `MapPane::` member unless a future pass finds a hidden receiver. Current evidence says no `this` receiver.

## Exact Supervisor Edits

### Target Metadata Replacements

Apply these metadata replacements to the six target pages:

```text
[UID:0002QH]
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q

[UID:0002QI]
COMPLETION: 88
CONFIDENCE: 91
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q

[UID:0002QO]
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q

[UID:0002QP]
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q

[UID:0002QQ]
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00007Q
EMITTER_UIDS: 00007Q

[UID:000231]
COMPLETION: 88
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000L3
EMITTER_UIDS: 0000L3
```

### Target Notes Replacement Text

Insert the following paragraphs in each target page under the source-quality/reconstruction-notes section, replacing old "blank final C++", "95/95", or "provisional name" blocker text.

[UID:0002QH] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Treat `0x005047f0` as source method `MapPane::ExitToMenu(bool notifyServer)` / `MapPane::ExitToMenu(bool sendLogoutPacket)`. The boolean controls only the optional outbound one-byte opcode `0x0b` packet. `ApplicationRequestExit`, `ReconnectDialog::OnButtonClick`, `QuitInputPaneCore`, and `QuitDialogCore` are callers/consumers, not owners. `0x00554210` is resolved by [UID:00038L] as `ReconnectDialog::OnButtonClick`, making the previous unresolved-caller caveat stale. The outbound `0x0b` send is a client exit/logout/menu notification and must be kept distinct from inbound `MapServerPacketOpcode 0x0b` accepted-no-op/ack. `MapPane +0x414` is best documented as `m_deferredCleanupPane` / `m_pendingCleanupPane`, `+0x41c` as `m_auxiliaryPane`, and `+0x420` as `m_activeScreenLayer`. Exact singleton-teardown helper spelling remains a confidence cap, but owner/emitter and first-draft C++ are ready under the active code-entry gate.
```

[UID:0002QI] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Treat `0x00504b70` as a vtable-routed `MapPane` pane-message callback, best named `MapPane::OnTagDetachMessage(Pane *sender, const TaggedPaneMessage *message)` or `MapPane::OnPaneMessage`. The second explicit argument contains a tag dword at offset `+4`; value `0x676f6f67` is ASCII/FOURCC `goog`, corroborated by neighboring pane notification docs. On match, the callback queues `this` through `BlackHole::QueuePaneForDeferredDeletion`. No direct code caller is expected because the route is the `MapPane` vtable entry recorded in [UID:0002SQ]. Formal C++ should be populated with a named `kPaneTagGoog` constant; only the exact callback base type remains a confidence cap.
```

[UID:0002QO] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Treat `0x005060f0` as `void MapPane::RemoveObjectPaneById(int objectId)`. The decompiler's apparent return of `0` or a scalar-deleting-destructor result is a compiler/decompiler artifact; no current caller evidence supports a meaningful returned deleted pointer. The method searches `m_objectList` by `ObjectPane +0xfc` object id, treats object type `3` as `ObjectPaneType::Living`, clears `MapPane +0x108/+0x10c` as `m_selectedObjectActive` / `m_selectedObjectPane` when they identify the removed living object, disables the living-object highlight, calls `LivingObjectPane::DestroyAllLinkedObjects`, removes the object from `ObjectList`, invalidates the object-data rect, and deletes the object pane. Exact "selected" versus "highlighted" original field spelling remains a confidence cap, but source placement and first-draft C++ are ready.
```

[UID:0002QP] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Treat `0x00506170` as `void MapPane::DetachObjectPane(ObjectPane *objectPane)`. Object virtual slot `+0x28` is [UID:0003XZ] `ObjectPane::GetObjectData(Rect *out) const`, and the copied `ObjectPane +0x108` rectangle is invalidated through the MapPane/Pane invalidation path before `m_objectList` removal. The conditional helper `0x004b97d0` is [UID:0003XC] `GrafPort::ReleaseBackingStore`, not an ObjectPane-only destructor helper. The type guard `objectType != 5` means all non-static object panes release per-pane backing store; type `5` is `ObjectPaneType::Static` from `StaticObjectPane` constructor evidence. Formal C++ should be populated; only exact inherited helper spelling remains a confidence cap.
```

[UID:0002QQ] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Treat `0x005062f0` as `bool MapPane::HasObjectIntersectingRect(const Rect *rect) const` / `AnyObjectIntersectsRect`. It reads `m_objectList`, obtains the visible object list through `ObjectList::GetVisibleObjectList`, iterates entries through `List::GetElementAt`, obtains each object's `ObjectPane::GetObjectData` rectangle, and returns true on the first `IntersectRects` hit. The current "FindObjectIntersectingRect" title is a compatibility alias only; the method returns a boolean, not an object pointer. Source placement under [UID:00007Q] is confirmed by MapPane object-list ownership and the BalloonObjectPane caller is only a consumer.
```

[UID:000231] replacement paragraph:

```text
2026-06-18 B002 source-quality resolution: Keep `0x00506380` as a [UID:0000L3] `MapPane.cpp` file-static helper, not a [UID:00007Q] `MapPane` member, because the body has no `this` receiver and consumes only an object-id argument. Best source name is `static void SendObjectRefreshRequest(int objectId)`; acceptable alternate is `RequestMissingObjectById`. The helper writes outbound opcode `0x0c`, appends the 32-bit object id in big-endian order, and queues exactly five bytes through `g_packetSender`. It is triggered when MapPane packet/object-update paths cannot resolve an expected object id. Do not merge it with inbound `MapServerPacketOpcode 0x0c` except as an outbound cross-reference. PacketBuffer writer and Socket queue-send names are now documented well enough for first-draft formal C++.
```

### Support Doc Insertions

#### [UID:00007Q] `by-class/MapPane.md`

Placement context: insert into the field table near the existing `+0xf8/+0xfc/+0x100` and `+0x418/+0x41c/+0x420/+0x424` rows.

```markdown
| `+0x108`, `+0x10c` | `m_selectedObjectActive` / `m_selectedLivingObjectActive`, `m_selectedObjectPane` / `m_selectedLivingObjectPane` | High-probability source names from [UID:0002QO]: when removing a type-3 `LivingObjectPane`, MapPane checks the active flag and pointer, disables the living-object highlight if the pointer equals the removed pane, then clears both fields. Exact original "selected" versus "highlighted" spelling remains open, but the fields are MapPane selection/highlight state, not ObjectPane fields. |
| `+0x414` | `m_deferredCleanupPane` / `m_pendingCleanupPane` | [UID:0002QH] queues this map-owned pane through `BlackHole::QueuePaneForDeferredDeletion` during exit-to-menu teardown, then clears the field. Exact producer and original field spelling remain open. |
```

Placement context: append to the MapPane lifecycle/message routing notes near the existing `0x005047f0` and `0x00504b70` rows.

```markdown
- 2026-06-18 B002 source-quality pass resolves [UID:0002QH] as `MapPane::ExitToMenu(bool notifyServer)` and [UID:0002QI] as a vtable-routed `MapPane::OnTagDetachMessage` callback for tag `0x676f6f67` (`goog`). `0x00554210` is now resolved as `ReconnectDialog::OnButtonClick`, a caller of `ExitToMenu`, not an owner.
- 2026-06-18 B002 source-quality pass resolves object teardown helpers [UID:0002QO], [UID:0002QP], and [UID:0002QQ] as class-owned MapPane methods: `RemoveObjectPaneById`, `DetachObjectPane`, and `HasObjectIntersectingRect`. [UID:000231] remains a `MapPane.cpp` file-static outbound object-refresh helper because it has no `this` receiver.
```

#### [UID:0000L3] `by-file/MapPane.md`

Placement context: insert near the existing [UID:000231] entry or MapPane packet/helper notes.

```markdown
- 2026-06-18 B002 source-quality pass keeps [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) as a file-static `MapPane.cpp` helper, best named `SendObjectRefreshRequest(int objectId)` / `RequestMissingObjectById(int objectId)`. It has no `this` receiver, writes outbound opcode `0x0c` plus a big-endian object id, and is called from MapPane packet/object-update paths when an expected object id is missing.
```

#### [UID:00009R] `by-class/ObjectPane.md`

Placement context: insert after the field table row for `+0xf8 m_objectType` or as a short `ObjectPaneType` table under field directions.

```markdown
Recommended `ObjectPaneType` values from current constructor and MapPane teardown evidence:

| Value | Source-facing enum direction | Evidence |
| --- | --- | --- |
| `0` | `Item` / `GroundItem` | Item-object update paths branch on `ObjectPane +0xf8 == 0` before using ItemObjectPane state. |
| `1` | `FlyingItem` / `FlyingObject` | `FlyingObjectPane` constructor sets `+0xf8` to `1`, and terminal flying-object cleanup calls MapPane object removal/detach helpers. |
| `3` | `Living` | [UID:0002QO] treats type `3` as `LivingObjectPane`, disables living-object highlight, and calls `LivingObjectPane::DestroyAllLinkedObjects`. |
| `5` | `Static` | `StaticObjectPane::StaticObjectPane` constructs the base `ObjectPane` with type `5`; [UID:0002QP] skips non-static backing-store release for type `5`. |
```

#### [UID:0001SO] `by-type/by-enum/MapServerPacketOpcode.md`

Placement context: insert immediately after the existing outbound opcode note for `0x05`.

```markdown
Outbound opcode note: `0x0b` is sent by [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) as a one-byte client exit/logout/menu notification when its boolean argument is true. It is outbound and should remain distinct from inbound `0x0b` accepted-no-op/ack in the `MapPane::HandlePacket` switch.

Outbound opcode note: `0x0c` is sent by [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) as a five-byte client object-id refresh/missing-object request. It is outbound and should remain distinct from inbound `0x0c` object action/animation update, although inbound object-update routes call the outbound helper when an expected object id is missing.
```

#### [UID:0003XC] `0x004b9770-0x004b981e.GrafPortEffectiveClipAndBackingRelease.md`

Placement context: append to the evidence/cross-reference section.

```markdown
- 2026-06-18 B002 cross-reference: [UID:0002QP][0x00506170-0x005061d3.MapPaneDetachObjectPane](by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md) calls `0x004b97d0` for non-static object panes before deleting them. This supports the existing `GrafPort::ReleaseBackingStore` interpretation: the call releases per-pane backing storage, while type `5` `StaticObjectPane` instances skip it because their static image resources are provider-owned.
```

## Coverage Row Recommendation

Replace the six current rows in `by-memory/-coverage-report.md` with these exact rows. Keep existing indentation/parent grouping.

```markdown
        - [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) 0x005047f0-0x00504b6b | method | MapPane::ExitToMenu : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves this as `MapPane::ExitToMenu(bool notifyServer)` / exit-to-menu session teardown, confirms Application/ReconnectDialog/Quit callers, resolves stale `0x00554210` as `ReconnectDialog::OnButtonClick`, distinguishes outbound opcode `0x0b` from inbound no-op/ack, names `+0x414/+0x41c/+0x420` teardown fields, and recommends first-draft C++ with only exact singleton-helper spelling below final audit.
        - [UID:0002QI][0x00504b70-0x00504b8f.MapPaneTagDetachMessage](by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md) 0x00504b70-0x00504b8f | virtual callback | MapPane::OnTagDetachMessage : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves the vtable-only route as a `MapPane` pane-message callback with two explicit args, tag field at message `+4`, FOURCC `0x676f6f67` / `goog`, BlackHole deferred cleanup of `this`, no-direct-caller interpretation through MapPane vtable data, and first-draft C++ readiness with only exact callback base type unresolved.
        - [UID:0002QO][0x005060f0-0x00506169.MapPaneRemoveObjectPaneById](by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md) 0x005060f0-0x00506169 | method | MapPane::RemoveObjectPaneById : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves this as a void MapPane object-removal method, names selected living-object fields `+0x108/+0x10c`, validates object type `3` as LivingObjectPane, links highlight clear and `DestroyAllLinkedObjects`, rejects decompiler destructor-return as source return, and recommends first-draft C++.
        - [UID:0002QP][0x00506170-0x005061d3.MapPaneDetachObjectPane](by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md) 0x00506170-0x005061d3 | method | MapPane::DetachObjectPane : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves object-data rect invalidation through `ObjectPane::GetObjectData`, ObjectList removal, type `5` as StaticObjectPane, non-static backing-store release through `GrafPort::ReleaseBackingStore` at `0x004b97d0`, and first-draft C++ readiness with inherited helper spelling as the only cap.
        - [UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md) 0x005062f0-0x0050637a | method | MapPane::HasObjectIntersectingRect : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass resolves the method as a boolean visible-object intersection query, validates `ObjectList::GetVisibleObjectList`, `List::GetElementAt`, `ObjectPane::GetObjectData`, and `IntersectRects`, identifies BalloonObjectPane as a consumer rather than owner, and recommends first-draft C++ under MapPane.
    - [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) 0x00506380-0x005063db | packet helper | SendObjectRefreshRequest : reconstructable : 88% : very strong : B002 2026-06-18 source-quality pass keeps this as a `MapPane.cpp` file-static helper with no `this` receiver, resolves outbound opcode `0x0c` as a five-byte object-id refresh/missing-object request, validates PacketBuffer UInt8/UInt32BE writers and `g_packetSender` queue-send dependency, distinguishes it from inbound opcode `0x0c`, and recommends first-draft C++ under file owner [UID:0000L3].
```

## Validator Commands

Run after supervisor application:

> Executable block R001 was removed from this report and preserved verbatim in [0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality-removed.md](0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the documentation toolchain has a targeted validator, run it against the six UIDs plus the touched support docs:

> Executable block R002 was removed from this report and preserved verbatim in [0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality-removed.md](0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If that exact validator entry point is not present, the `rg` checks above are sufficient smoke checks for this report-only handoff.

## Changed Files / No Direct Edit Statement

Created exactly one Agent-B002 research report:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md
```

No by-* docs, generated reports, generated source, IDA DB, or `by-memory/-coverage-report.md` were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002QH"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002QH-0002QI-0002QO-0002QP-0002QQ-000231-MapPaneTeardownObjectPacket-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002QH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
