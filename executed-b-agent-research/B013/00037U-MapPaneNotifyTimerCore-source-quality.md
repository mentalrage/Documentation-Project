** TARGET-REPORT-UID:00037U **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00037U MapPaneNotifyTimerCore Source-Quality Reanalysis

Agent: Agent-B013
Assignment: B013-goal2-map-pane-notify-timer-core-source-quality-00037U-20260619
Target: [UID:00037U] `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md`
Current target score: `COMPLETION:85`, `CONFIDENCE:87`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`
Report status: report-only. No by-* documentation or coverage report edits were made.

## Final Recommendation

`00037U` is MapPane-owned, but it is not source-quality as one emitting by-memory page. Current IDA/export evidence shows two separate vtable-reached MapPane methods plus internal/tail bytes:

- `0x00508f60-0x0050902b`: secondary-subobject MapPane notify/message handler. Data xref from `0x0061e77c`.
- `0x00509030-0x00509439`: tertiary-subobject MapPane timer handler. Data xref from `0x0061e79c`.
- `0x0050902b-0x00509030`: alignment between functions.
- `0x00509439-0x00509470`: no modeled function start in the IDA function export before successor `0x00509470`; this remains byte/padding/table verification work.
- `0x00509470`: successor method, not part of `00037U`; current export decompiles it as an 8-byte `MapPane` map-id getter.

The best source-quality action is to convert `00037U` to a non-emitting split index/container and create exact child pages for the two method bodies. Keep `CANONICAL_OWNER:00007Q`, set `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, leave formal C++ blank, and document the no-code proof. The exact child pages should route through [UID:00007Q] `MapPane` and the `map/MapPane.cpp` source-placement convention.

Recommended parent metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:00007Q
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Recommended child split:

```text
0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md
  owner/emitter: 00007Q
  reconstructable: TRUE after field-name cleanup
  best method name: MapPane::OnNotifyMessage or MapPane::HandleNotifyMessage

0x00509030-0x00509439.MapPaneMovementTimerHandler.md
  owner/emitter: 00007Q
  reconstructable: TRUE after field-name cleanup
  best method name: MapPane::OnTimerEvent or MapPane::HandleMovementTimerEvent
```

The child file names above are source-quality recommendations, not assigned UIDs. A validator-backed implementation pass must create exact child pages and use the assigned UIDs.

## Evidence Base Used

High-confidence sources used:

- Current target page `by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md`.
- Current parent/class/file pages: `by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md`, `by-class/MapPane.md`, `by-file/MapPane.md`, and `by-project-structure/proposed-source-tree.md`.
- Current vtable page `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md`.
- IDA function export JSON under `hooks-generation/tests/function_data/ida/` for `0x00508f60`, `0x00509030`, and `0x00509470`.
- Support by-memory/by-global pages for TimerHandler wrappers, `g_pUrlAlertPane`, `ConnectionClosedDialogConstructorVariant`, `g_pInputBlockerPane`, MapPane weather/state helpers, MapPane tile/object/path helpers, LivingObjectPane local-player helpers, object lookup helpers, sprite config helpers, and cursor helpers.
- Project inference guidance: `by-structure.md`, `by-memory/-guidance.md`, and `inference_research.md`.

Evidence deliberately not used as proof:

- Wave/generated source aliases and Hex-Rays placeholder type names were treated only as leads.
- The current `auto-generated` emitter route was not treated as proof that a one-page formal C++ body is source-quality.
- Nearby address adjacency was not treated as ownership proof without vtable/data-flow corroboration.

## Direct Binary Facts

### `0x00508f60`

IDA export:

```text
address: 0x00508f60
name: sub_508F60
size: 0xcb
decompiled signature: char __thiscall sub_508F60(_BYTE *this, _BYTE *Block)
xrefs_to: data offset 0x0061e77c
xrefs_from:
  0x00597610 TimerHandler cancel wrapper
  0x005449f0 unresolved refresh/side-effect helper
  0x004f4aa0 allocator
  0x00553c10 ConnectionClosedDialog constructor variant
```

Observed behavior:

- Tests global byte `byte_66DA97 == 1`.
- Tests and clears `this[765]`.
- Calls `0x00597610` twice with event ids `6` and `8`.
- Calls `0x005449f0`.
- Checks `Block[4] == 22`.
- Reads `dword_69B4DC` (`g_pUrlAlertPane` guard).
- Allocates `624` bytes through `0x004f4aa0`.
- Calls `0x00553c10`, documented as `ConnectionClosedDialogConstructorVariant`.
- Returns `1` only for the handled message path; otherwise returns `0`.

The data xref from `0x0061e77c` is inside the MapPane secondary vtable slice. The method is virtual/notify reached; lack of direct code callers is expected and is not negative evidence.

### `0x00509030`

IDA export:

```text
address: 0x00509030
name: sub_509030
size: 0x409
decompiled signature: char __thiscall sub_509030(int this, int, int, int)
xrefs_to: data offset 0x0061e79c
xrefs_from:
  0x00505de0 secondary map-state refresh clearer
  0x005a58c0 LivingObjectPane action helper
  0x005975e0 TimerHandler schedule wrapper
  0x00505cc0 queued map-state refresh clearer
  0x0050d010 MapPane path scan variant
  0x0050c6e0 MapPane path-step helper
  0x005a2e00 LivingObjectPane movement helper
  0x004a70b0 unresolved application/session predicate
  0x005374d0 ObjectPane map-position getter
  0x0050c790 MapPane path scan variant
  0x00532370 ObjectList object-id lookup
  0x0053a8c0 LivingObjectPane sprite-config getter
  0x00505080 MapPane direction-to-tile-offset helper
  0x005573f0 Screen/cursor helper
  0x005a5820 LivingObjectPane action helper variant
  0x005a5870 LivingObjectPane action helper variant
  0x005a57a0 LivingObjectPane action helper variant
```

Observed behavior by event id:

- `5`: clears a byte at normalized MapPane state and returns handled.
- `6`: movement/path timer. Requires queued state, clears state if an input blocker is active, processes movement through path helpers and `LivingObjectPane::ProcessMovement`, and either clears state or reschedules event `6` at 44 ms.
- `7`: left-button/action polling timer. If the pending click/action flag is set and `GetAsyncKeyState(1)` is still active, it calls the local-player action helper and reschedules event `7` at 500 ms. If the button is no longer active, it calls the secondary map-state clearer. If the flag is not set, it falls into the movement path.
- `8`: path/auto-action timer. Requires queued movement state, uses target coordinates and object id state, scans a path, optionally issues action helpers, changes cursor state, and either clears state or reschedules event `8` at 44 ms.
- Default: returns `0`.

The data xref from `0x0061e79c` is inside the MapPane tertiary vtable slice. The `this` pointer is best interpreted as a timer-handler subobject at `MapPane + 0xa4`; repeated `this - 164` recoveries point back to the `MapPane` base.

### `0x00509470`

IDA export:

```text
address: 0x00509470
name: sub_509470
size: 0x8
decompiled behavior: return this[505]
```

With a `MapPane` base, `this[505]` is byte offset `0x3f2`, which matches the documented `MapPane::m_mapId` field. This successor is not part of `00037U`. It supports the target's exclusive end address at `0x00509470` and should remain with the successor exact page/range.

## Heuristic / Inference Reanalysis And Validation

### Placeholder method names

`sub_508F60` should not remain as a source-facing name. The best-supported name is `MapPane::OnNotifyMessage` or `MapPane::HandleNotifyMessage`. The evidence is the secondary vtable slot at `0x0061e77c`, a message-like second argument tested at `Block[4]`, and the handled-code return shape. The method has two responsibilities: cancel active MapPane movement timers when queued movement state exists, and handle notify/message code `22` by opening the currently documented connection-closed alert path if the alert guard is clear.

`sub_509030` should not remain as a source-facing name. The best-supported name is `MapPane::OnTimerEvent` or `MapPane::HandleMovementTimerEvent`. The evidence is the tertiary vtable slot at `0x0061e79c`, the timer-handler subobject adjustment, repeated TimerHandler schedule calls, and the event-id switch over `5`, `6`, `7`, and `8`.

`sub_509470` is not part of this page. Its best-supported name is `MapPane::GetMapId` or `MapPane::GetCurrentMapId`, based on `this[505] == MapPane + 0x3f2`. This validates the successor boundary and should not be folded into `00037U`.

### Subobject and `this` interpretation

`0x00508f60` is reached from the secondary MapPane vtable slice. The `this - 160` and `this + 4` arithmetic is consistent with a secondary facet at approximately `MapPane + 0xa0` and a TimerHandler-compatible facet at `MapPane + 0xa4`.

`0x00509030` is reached from the tertiary MapPane vtable slice. The repeated `this - 164` arithmetic is consistent with the timer-handler facet at `MapPane + 0xa4`. This explains why raw decompiler offsets look high while normalized offsets align with existing MapPane state fields.

### Best-supported field names and interpretations

The following names are source-facing recommendations, not proof of original symbols:

```text
MapPane + 0x39d
  Best current meaning: queued movement/map-state timer flag.
  Suggested prose name: m_queuedMapStateRefresh or m_movementTimerQueued.
  Evidence: tested and cleared by 0x00508f60; required by timer ids 6 and 8;
  documented clear helper 0x00505cc0 clears this state and invalidates events 6 and 8.

MapPane + 0x39e
  Best current meaning: pending left-button/action polling flag.
  Suggested prose name: m_pendingActionPoll or m_leftButtonActionPending.
  Evidence: event id 7 checks it, polls GetAsyncKeyState(1), schedules event 7 at 500 ms,
  and 0x00505de0 is documented as the secondary map-state refresh clearer.

MapPane + 0x3f2
  Best current meaning: m_mapId.
  Evidence: successor 0x00509470 returns byte offset 0x3f2 and class glossary already names it.

MapPane + 0x418
  Best current meaning: active/local player object pane.
  Evidence: current class glossary and movement/action calls using object state.

MapPane + 0x424
  Best current meaning: m_objectList.
  Evidence: current class glossary and object-id lookup through 0x00532370.

MapPane + 0x8ec / +0x8f0
  Best current meaning: saved target tile or action target tile coordinates.
  Evidence: event id 8 compares object/current coordinates against these fields before issuing actions.
  Keep as descriptive prose until adjacent action-state structure is resolved.

MapPane + 0x8f4 / +0x8f8
  Best current meaning: current path destination coordinates for the event-8 path scan.
  Evidence: passed to 0x0050c790 from event id 8.
  Keep as descriptive prose pending structure cleanup.

MapPane + 0x904
  Best current meaning: pending action mode/state.
  Evidence: event id 8 checks modes 5, 6, and 15 and writes mode 6.

MapPane + 0x908
  Best current meaning: pending action target object id.
  Evidence: passed to ObjectList lookup at 0x00532370.

MapPane + 0x90d
  Best current meaning: pending action flags.
  Evidence: bits 4 and 2 select action helper variants.

MapPane + 0x90e
  Best current meaning: auto-action/path follow pending flag.
  Evidence: event id 8 uses it to decide whether to continue movement/action sequencing.
```

Do not promote the `+0x8ec` through `+0x90e` names to final class fields without a nearby structure pass. The role is clear enough for behavior notes and child first-draft logic, but not enough for a stable header declaration.

### Best-supported helper names

```text
0x00597610
  TimerHandler::CancelTimer or TimerHandler::CancelTimerEvent.
  Used by 0x00508f60 for event ids 6 and 8.

0x005975e0
  TimerHandler::ScheduleTimer or TimerHandler::ScheduleTimerEvent.
  Used by 0x00509030 for event ids 6, 7, and 8.

0x00505cc0
  MapPane queued map-state refresh clearer.
  Clears queued movement state and invalidates events 6 and 8.

0x00505de0
  MapPane secondary map-state/action-poll clearer.
  Clears pending event-7 action-poll state.

0x0050c6e0
  MapPane path-step candidate/validation helper.
  Used by timer movement path logic.

0x0050c790
  MapPane path scan to current event-8 destination.
  Used at 0x005091d0.

0x0050d010
  MapPane path scan from object/configured coordinates.
  Used at 0x0050910c.

0x005a2e00
  LivingObjectPane::ProcessMovement.
  Receives the selected movement direction from timer logic.

0x005a58c0
  LivingObjectPane local-player action helper.
  Used by event id 7 while left mouse button remains down.

0x00532370
  ObjectList::FindByObjectId.
  Used to resolve the pending action target object.

0x005374d0
  ObjectPane::GetMapPosition.
  Used before coordinate/action checks.

0x0053a8c0
  LivingObjectPane::GetSpriteConfig.
  Used to inspect target sprite/action state before auto-action.

0x005573f0
  Screen/cursor helper, likely cursor selection or cursor-mode setter.
  Used with cursor/state id 7.

0x004a70b0
  Unresolved application/session guard predicate.
  It controls whether to clear MapPane state instead of rescheduling timers.
  Do not assign a final source name from this page alone.
```

### Global names

`dword_69B4DC` is best kept as `g_pUrlAlertPane` for the global storage slot, but `0x00508f60` should be described as using it as an alert/open guard. It should not be used as proof that the constructed object in this method is a `UrlAlertPane`; the direct constructor call is currently documented as `ConnectionClosedDialogConstructorVariant`.

`dword_69B4CC` is best kept as `g_pInputBlockerPane`. In `0x00509030`, a non-null blocker suppresses movement/action work and forces MapPane state clear paths.

`dword_67A748` is the active/local `LivingObjectPane` pointer in this context. Do not rename it from this page alone, but behavior notes can say local-player object pane.

`dword_67AB30` remains unresolved here. The call to `0x004a70b0` is clearly a guard that prevents rescheduling and forces a state clear, but the underlying owner/name needs a separate caller cluster.

### Rejected stale or weak inferences

- Reject treating Hex-Rays `_anonymous_namespace_::dbg_eng_data` on the `0x004f4aa0` allocation result as a real type. It is a decompiler artifact in this context.
- Reject describing the `0x00508f60` constructed object as definitely `UrlAlertPane` merely because `g_pUrlAlertPane` is read. The stronger direct callee evidence is `0x00553c10`, currently owned by `ConnectionClosedDialog`.
- Reject using generated source output as proof that the entire `0x00508f60-0x00509470` range can emit as one C++ function.
- Reject keeping `0x00509470` in this range. It has its own function export and an independent getter behavior.
- Reject final source names for the `+0x8ec` through `+0x90e` action-state fields until a structure pass ties them to surrounding writers/readers.

## Caller, Reachability, And Owner Placement

The two real method bodies in this target have no ordinary direct code callers in the current export. That is expected:

- `0x00508f60` is reachable from a MapPane secondary vtable slot at `0x0061e77c`.
- `0x00509030` is reachable from a MapPane tertiary vtable slot at `0x0061e79c`.

This is virtual callback reachability, not dead code. The vtable page already identifies these slots as part of MapPane vtable data. The local field offsets, MapPane helper calls, path helpers, object-list lookup, and TimerHandler subobject arithmetic all reinforce MapPane ownership.

Source placement remains `map/MapPane.cpp` through [UID:0000L3] `by-file/MapPane.md` and [UID:00007Q] `by-class/MapPane.md`. The methods should be documented on exact child pages as MapPane-owned methods. Support callees remain in their own owners:

- Timer scheduling/canceling stays with TimerHandler/TimerMgr docs.
- Dialog construction stays with ConnectionClosedDialog/alert-pane docs.
- LivingObjectPane movement/action helpers stay with LivingObjectPane.
- Object lookup stays with ObjectList.
- Cursor state helper stays with screen/cursor docs.

## Behavior Reconstruction

### `0x00508f60` notify/message handler

The method first handles pending MapPane movement state. If global mode byte `byte_66DA97` equals `1` and the queued movement/map-state flag is set, it clears that flag, cancels TimerHandler event `6`, cancels TimerHandler event `8`, and calls `0x005449f0`.

It then handles message code `22` only when `g_pUrlAlertPane` is null. In that case it allocates `624` bytes and calls `0x00553c10`, currently documented as `ConnectionClosedDialogConstructorVariant`. If the message code differs or the alert guard is already set, it returns unhandled.

This behavior reads like a MapPane notify/message callback that cancels movement/path timers during a global state transition and opens a connection/session alert for message code `22`.

### `0x00509030` timer handler

The method is a timer callback on the MapPane timer facet. It is not a generic TimerMgr method; it uses TimerHandler wrappers only to schedule and remove its own events.

Event `5` clears one MapPane state byte and returns handled. The exact user-facing meaning of this byte is not resolved by this page alone.

Events `6` and the fallthrough portion of `7` run the movement/path timer. The method checks queued state, clears state when a modal input blocker is active, checks the local object busy flag, chooses between two MapPane path scan variants based on `byte_66DA97` and a config byte under `dword_67A7C8`, calls `LivingObjectPane::ProcessMovement` for valid directions, then either clears state or reschedules event `6` for 44 ms.

Event `7` also serves as the left-button/action poll. If the pending action-poll flag is set and `GetAsyncKeyState(1)` reports the button still down, the method calls the local-player action helper and reschedules event `7` for 500 ms. If the button is no longer down, it calls the secondary clearer. If the pending flag is not set, it falls into the movement timer path.

Event `8` handles path-follow/auto-action sequencing. It checks queued state, clears state under input blocker, reads the active object position, scans toward stored destination coordinates, resolves target objects by id, uses pending action mode/flags to select action helper variants, changes cursor state on failed target/action checks, and either clears state or reschedules event `8` for 44 ms.

The default path returns unhandled.

## Open-Question Closure

Closed: Is this MapPane-owned?

Yes. Vtable slots, subobject adjustment, MapPane helper calls, object-list fields, and class/file docs all agree. No competing owner explains the evidence better.

Closed: Are `0x00508f60` and `0x00509030` direct-call dead code?

No. They are vtable-reached callback methods. The data xrefs are the expected reachability path.

Closed: Does `0x00509470` belong to `00037U`?

No. It has an independent IDA function export and getter behavior for `MapPane + 0x3f2` (`m_mapId`). Keep it outside the target range.

Closed: Should `0x00508f60` be documented as constructing a `UrlAlertPane`?

No, not as a final fact. It reads `g_pUrlAlertPane` as an alert/open guard, but the direct constructor call is documented as `ConnectionClosedDialogConstructorVariant`. Support docs should say the guard is `g_pUrlAlertPane`; the constructed class should follow the `0x00553c10` owner evidence.

Open: What exactly is `0x00509439-0x00509470`?

The current IDA function list does not show a function start there, and `0x00509470` is the next function. The target page describes this as raw table/helper-like tail bytes. Without byte-level inspection, the defensible wording is "tail/alignment or raw data pending byte verification." This open question blocks parent C++ emission but does not weaken ownership of the two function bodies.

Open: What is the final original symbol for `0x004a70b0(dword_67AB30)`?

This page proves only that it is an application/session guard consulted before rescheduling movement/path timers. It should remain unresolved until its broader caller cluster is reviewed.

Open: What are final source field names for the `+0x8ec` through `+0x90e` action-state block?

This page supports behavior-level names, but not stable header-level field names. A later structure pass should review adjacent writers/readers before promoting final names.

## First-Draft C++ Eligibility And No-Code Proof

The current parent page is not eligible for a single formal C++ body after source-quality reanalysis, despite the current `RECONSTRUCTABLE:TRUE` metadata.

Exact no-code proof for parent `00037U`:

1. The range contains two separate source methods reached from different vtable slots, not one source function.
2. The first method uses a secondary MapPane facet; the second uses the timer-handler facet at a different adjusted `this`.
3. There is internal alignment at `0x0050902b-0x00509030`.
4. There is unresolved tail/alignment/raw data at `0x00509439-0x00509470`.
5. `0x00509470` is the next independent method and must remain outside the target.
6. Emitting one formal C++ block on the parent would either merge unrelated callbacks or omit bytes inside the documented range.
7. Several action-state field names are behaviorally understood but not stable enough for a final class declaration on a broad aggregate page.

Therefore:

```text
Parent 00037U formal C++: keep blank.
Parent RECONSTRUCTABLE: FALSE after split-index conversion.
Child C++: allowed only on exact child method pages after validator-assigned UIDs and field-name cleanup.
```

Recommended child C++ policy:

- `0x00508f60-0x0050902b` can carry a first-draft `MapPane::OnNotifyMessage(...)` body once the page states the secondary-subobject adjustment and documents the `g_pUrlAlertPane` guard versus `ConnectionClosedDialog` constructor distinction.
- `0x00509030-0x00509439` can carry a first-draft `MapPane::OnTimerEvent(...)` body once the page defines the timer-handler facet and uses descriptive names for unresolved action-state fields.
- Both child drafts should be final-output style C++, not copied decompiler text. They should call documented helpers by best-supported names and leave unresolved globals/helpers as named placeholders only where this report marks them unresolved.

## Score Rationale

Current `85/87` understates the direct vtable and behavior evidence but overstates single-body reconstructability.

Recommended parent after split-index conversion:

```text
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:FALSE
```

Completion improves because function boundaries, vtable reachability, helper roles, owner placement, and no-code proof are now explicit. Confidence improves because the major ownership/open-question risks are closed. The parent remains non-reconstructable because it is an aggregate over two methods and non-function bytes.

Suggested child scores after implementation:

```text
0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md
  COMPLETION:87
  CONFIDENCE:89
  RECONSTRUCTABLE:TRUE

0x00509030-0x00509439.MapPaneMovementTimerHandler.md
  COMPLETION:88
  CONFIDENCE:89
  RECONSTRUCTABLE:TRUE
```

Those child scores assume the implementation page includes vtable evidence, adjusted-this notes, helper/global names, and first-draft method C++ with unresolved field names documented rather than hidden.

## Exact Supervisor-Owned Coverage Row Text

Preferred coverage row for `by-memory/-coverage-report.md` after converting `00037U` to a non-emitting split index. Insert it under the `0001AT` aggregate in address order. This report does not edit the supervisor-owned coverage file.

```text
        - [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md) 0x00508f60-0x00509470 | split-index | MapPaneNotifyTimerCore : not_reconstructable : 88% : very-strong : Non-emitting split index for the MapPane secondary notify/message helper at `0x00508f60-0x0050902b`, timer-handler vtable method at `0x00509030-0x00509439`, internal `0x0050902b-0x00509030` alignment, and pre-`GetCurrentMapId` `0x00509439-0x00509470` tail/alignment; exact child method pages carry MapPane owner/emitter routing through [UID:00007Q][MapPane](by-class/MapPane.md), while this parent remains blank-C++ because it is not a single source function.
```

If the supervisor defers child-page creation and only wants a current-state coverage repair, use this temporary row instead. It is inferior to the split-index row above.

```text
        - [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md) 0x00508f60-0x00509470 | class-method aggregate | MapPaneNotifyTimerCore : not_reconstructable : 87% : strong : MapPane-owned secondary notify/message helper and tertiary movement timer handler; current IDA exports confirm `sub_508F60` size `0xcb` from vtable slot `0x0061e77c`, `sub_509030` size `0x409` from vtable slot `0x0061e79c`, timer ids `5/6/7/8`, generic TimerHandler cancel/schedule wrappers, `g_pInputBlockerPane` and `g_pUrlAlertPane` guards, MapPane path helpers `0x0050c6e0`/`0x0050c790`/`0x0050d010`, LivingObjectPane movement/action callees, and successor `0x00509470` as `MapPane::GetCurrentMapId`; formal C++ remains blank because this row should be split into exact method children and the `0x00509439-0x00509470` tail still needs byte/padding verification.
```

Child rows require validator-assigned UIDs and therefore cannot be exact in this report. The implementation callback for this target should write final child rows with actual UIDs after validator assignment, mirroring the implementation pattern used for other split-index conversions.

## Target Implementation Checklist

For a future implementation pass on this target:

1. Acquire normal leases for `00037U`, proposed child pages, MapPane class/file docs, vtable docs, and touched support pages.
2. Create exact child page `by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md` with validator-assigned UID.
3. Create exact child page `by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md` with validator-assigned UID.
4. Convert parent `00037U` to a non-emitting split index:
   - `COMPLETION:88`
   - `CONFIDENCE:90`
   - `CANONICAL_OWNER:00007Q`
   - `RECONSTRUCTABLE:FALSE`
   - blank `EMITTER_UIDS`
   - blank formal C++
   - `[[CHILDREN]]` links to both child pages
   - explicit no-code proof copied from this report
5. Add or preserve ignored/alignment coverage for `0x0050902b-0x00509030` and `0x00509439-0x00509470` if the supervisor/validator model requires exact coverage rows.
6. Keep `0x00509470` out of `00037U`; it belongs to the successor map-id getter page/range.
7. Put first-draft C++ only on exact child method pages, not on the parent.
8. Run scoped validators for the parent, child pages, and every support doc touched.
9. Leave final supervisor-owned coverage rows with actual child UIDs in `Agent-B013/notes.md` if instructed not to edit `by-memory/-coverage-report.md`.

## Support Documentation Checklist

Update support docs only in a later implementation pass, not during this report-only pass.

Recommended support updates:

- `by-class/MapPane.md`: add method-map entries for `MapPane::OnNotifyMessage` and `MapPane::OnTimerEvent`; document timer events `5`, `6`, `7`, and `8`; add normalized field notes for `+0x39d`, `+0x39e`, and the `+0x8ec` through `+0x90e` action-state block as provisional.
- `by-file/MapPane.md`: state that exact child pages, not `00037U`, own emission for these callback methods.
- `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md`: record `0x0061e77c -> 0x00508f60` as the notify/message child and `0x0061e79c -> 0x00509030` as the timer-handler child.
- TimerHandler wrapper docs: add callers from `0x00508f60` to `0x00597610` for event ids `6` and `8`, and from `0x00509030` to `0x005975e0` for timer ids `6`, `7`, and `8`.
- `g_pUrlAlertPane` docs: change wording from "constructs UrlAlertPane-shaped object" to "uses `g_pUrlAlertPane` as alert/open guard; direct constructor evidence currently points to `ConnectionClosedDialogConstructorVariant`."
- `ConnectionClosedDialogConstructorVariant` docs: keep `0x00508f60` as the sole direct caller and describe the caller as MapPane notify/message code `22`.
- `g_pInputBlockerPane` docs: record `0x00509030` as a movement/action suppressor that forces MapPane state clear paths when the blocker exists.
- `MapPaneWeatherCoordinateObjectCore` or exact child helpers: cross-reference `0x00505cc0` and `0x00505de0` as state clear helpers used by the timer handler.
- `MapPaneTileObjectGridRenderCore`: preserve `0x0050c6e0`, `0x0050c790`, and `0x0050d010` as MapPane path helpers used by the timer child; do not move ownership into the timer child.
- `LivingObjectPaneLocalPlayerExtensions`: add callers from `0x00509030` to movement/action helpers if absent.
- Object lookup and sprite config docs: add `0x00509030` as a path/action caller where scoped update is appropriate.
- Cursor/screen helper docs: add `0x00509030` as a caller of cursor id/state `7` only if the helper page already tracks caller lists.

## Validation Performed

No by-* validators were run because this was a report-only task and no by-* documentation was edited.

Filesystem verification before writing the report confirmed the report path did not already exist.

## Changed Files

This report-only pass creates:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B013\research\00037U-MapPaneNotifyTimerCore-source-quality.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00037U-MapPaneNotifyTimerCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"00037U"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
