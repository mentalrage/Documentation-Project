** TARGET-REPORT-UID:0000ZZ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 ChangeMan Method Source-Quality Audit

Assignment: `B002-goal2-changeman-method-source-quality-0000ZZ-000100-20260616`

Scope:
- [UID:0000ZZ] `by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md`
- [UID:000100] `by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md`
- Supporting context: ChangeMan class/file, ChangeManEntry/Layout/Vtable, `g_pChangeMan`, Application wrapper leaves, SortedList, Message, BackPane teardown, and adjacent ChangeMan methods where they constrain source signatures.

Report-only note: no by-* docs, generated reports, source files, or IDA database content were edited for this audit.

## Recommendation

Both primary targets should pass the current 85/85 source-quality gate after a targeted supervisor refresh, but neither should receive final C++ yet.

- [UID:0000ZZ] `ChangeManDispatchMessage`: raise from `82/88` to `86/90`.
- [UID:000100] `ChangeManUnregisterObject`: raise from `82/90` to `86/91`.

The score increase is justified by fresh IDA confirmation of method boundaries, exact control flow, container helper use, caller reachability, field semantics, and owner/emitter placement. The final-C++ blocker is no longer behavior; it is exact source-interface naming and declaration quality: listener interface/method spelling, source return types, and the message-scope enum spelling are still not source-proven.

## Evidence Read

Required docs read:
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Agent-B002/goal.md`
- `tools/leaser/Agents/Agent-B002/notes.md`
- both target by-memory pages
- `by-class/ChangeMan.md`
- `by-file/ChangeMan.md`
- `by-type/by-struct/ChangeManEntry.md`
- `by-type/by-struct/ChangeManLayout.md`
- `by-type/by-vtable/ChangeManVtable.md`
- `by-global/g_pChangeMan.md`
- `by-file/Application.md`
- `by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md`
- `by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md`
- `by-file/SortedList.md`
- `by-class/Message.md`

Additional supporting docs checked:
- adjacent ChangeMan leaves [UID:0000ZT], [UID:0000ZW], [UID:0000ZY], [UID:000101], [UID:000103]
- `by-class/SortedList.md`
- `by-memory/0x00520e30-0x00521d94.MessageCore.md`
- BackPane class/file and exact constructor/destructor/deleting-destructor pages
- exact Application wrapper leaves [UID:000198], [UID:00019A], [UID:00019B]
- AboveFrame, FramePartPane, MapPane, and VideoPlayerPane references to the Application ChangeMan wrappers

IDA/MCP checks were run against the loaded `NexusTK.exe.i64` database. The IDA session reported Hex-Rays available.

## Heuristic / Inference Reanalysis And Validation

### Owner And Emitter Placement

Keep both primary targets owned by the ChangeMan class and emitted through the ChangeMan source unit.

Evidence:
- `ChangeManLayout` is a real class layout with an LObject base/vtable at `+0x00` and `SortedList *changeList` at `+0x04`.
- `ChangeManVtable` is a distinct table at `0x00614cd0`.
- `g_pChangeMan` is constructed and cleared by ChangeMan lifecycle code, then consumed by Application wrappers and BackPane teardown.
- `ChangeManDispatchMessage` is reached only through `ApplicationForwardMessage`, but the wrapper loads `g_pChangeMan` into `ECX` and tail-calls the ChangeMan method shape.
- `ChangeManUnregisterObject` is reached from BackPane teardown, but those callers also load `g_pChangeMan` and call the ChangeMan instance method.

Rejected alternative:
- Do not move either target to Application or BackPane. Those classes are consumers. The owning state, comparator, list layout, singleton, and vtable are ChangeMan-local.

### ChangeManDispatchMessage At 0x0047ee20

Fresh IDA disassembly and decompilation confirm this source-level behavior:

1. Build a stack key whose first dword is the supplied owner/source object.
2. Call `SortedListFindFirstEqual`-like helper at `0x004f3780` on `this->changeList`.
3. If no entry is found, return.
4. Walk forward while `index < changeList->count`.
5. Fetch each entry through the SortedList virtual slot at `+0x10`.
6. Stop when `entry->owner != owner`.
7. Dispatch when `entry->scope == 1`.
8. If `entry->scope == 0`, dispatch only when `entry->messageType == message->m_type`.
9. For matching entries, call the listener object's virtual slot `+0x08` with `(owner, message)`.

Specific instructions checked:
- `0x0047ee33` loads `this->changeList`.
- `0x0047ee37` calls `sub_4F3780`.
- `0x0047ee4a` reads `changeList->count` at `+0x0c`.
- `0x0047ee5b` calls vtable slot `+0x10` to fetch an entry by index.
- `0x0047ee67` reads `entry+0x08` as the scope byte.
- `0x0047ee70` compares `entry+0x0c` with `message+0x04`.
- `0x0047ee7a` calls listener vtable slot `+0x08` with owner and message arguments.

Call reachability:
- The sole code xref to `0x0047ee20` is `ApplicationForwardMessage` at `0x004f4b7d`.
- `ApplicationForwardMessage` pushes the message argument, pushes Application `this` as the owner/source, loads `g_pChangeMan`, and calls `ChangeManDispatchMessage`.
- Known wrapper callers include Application cleanup/shutdown message sites that construct `Message` objects with FourCC-like type constants.

Best reconstructed source signature:

```cpp
void ChangeMan::DispatchMessage(void *owner, Message *message);
```

This is source-quality as a behavioral signature, not final-source quality as a declaration. `void *owner` may later become an Application/source-specific base type if a source header is recovered. The decompiler's `char` or integer return is a residual callback/register artifact; no checked caller uses a returned value.

Best reconstructed listener callback:

```cpp
class ChangeListener {
public:
    virtual void OnChangeMessage(void *owner, Message *message);
};
```

Evidence limit:
- The slot is definitely listener vtable `+0x08`.
- The argument order is definitely `(owner, message)`.
- AboveFrame and FramePartPane docs describe related slot `+0x08` handlers as notification handlers, and wrapper names use "ChangeListener".
- The exact source spelling is not proven. `OnChangeMessage` is the best descriptive reconstruction for now.

Rejected callback names:
- `MessageHandler` is too likely to collide with Win32/message-pump naming in Application and does not encode ChangeMan listener ownership.
- `OnNotify` is plausible from pane documentation, but the module and wrapper naming use ChangeMan/ChangeListener.
- A raw `func_` or `slot8` name is no longer defensible after wrapper, vtable, and pane-notification evidence.

### ChangeManUnregisterObject At 0x0047eea0

Fresh IDA disassembly and decompilation confirm this source-level behavior:

1. Read `this->changeList->count`.
2. Start at `count - 1`.
3. Iterate backward while the index is non-negative.
4. Fetch each entry through the SortedList virtual slot at `+0x10`.
5. Remove the entry if either `entry->owner == object` or `entry->listener == object`.
6. Remove through the SortedList virtual slot at `+0x1c` with `(index, 1)`.
7. Continue the reverse scan until the list is exhausted.

Specific instructions checked:
- `0x0047eea7` to `0x0047eead` derive `count - 1` from `this->changeList->count`.
- `0x0047eeb6` to `0x0047eebc` call the SortedList get slot `+0x10`.
- `0x0047eebf` compares the entry owner against the supplied object.
- `0x0047eec3` compares the entry listener against the supplied object.
- `0x0047eecb` pushes count `1`.
- `0x0047eed0` calls the SortedList remove slot `+0x1c`.
- `0x0047eed3` decrements the index and continues the reverse walk.

Call reachability:
- The two code xrefs to `0x0047eea0` are BackPane teardown callers.
- `sub_4678f0` restores BackPane vtables, calls `ChangeManUnregisterObject(g_pChangeMan, this)`, clears `g_pBackPane`, then runs base cleanup.
- `sub_467a80` is the scalar deleting BackPane destructor shape and performs the same broad unregister before optional delete.

Best reconstructed source signature:

```cpp
void ChangeMan::UnregisterObject(void *object);
```

This is the safest descriptive source name for the exact binary behavior. A recovered source may instead use an overload such as `ChangeMan::Unregister(void *object)`, especially because the filtered unregister method is also present. `UnregisterListener` is not precise enough because the method removes entries where the object appears as either owner/source or listener.

Rejected alternatives:
- Do not model this as a filtered unregister. It ignores message type and scope entirely.
- Do not model this as listener-only cleanup. It explicitly checks both `entry+0x00` and `entry+0x04`.
- Do not mark it dead or compiler-generated. BackPane destructor reachability is exact and source-relevant.

### ChangeManEntry Fields And Scope Semantics

The existing `ChangeManEntry` layout is correct and should be retained:

```cpp
struct ChangeManEntry {
    void *owner;          // +0x00
    ChangeListener *listener; // +0x04
    uint8_t scope;        // +0x08
    uint32_t messageType; // +0x0c
};
```

Better source-facing names:
- `owner` or `source` for `+0x00`: both are defensible. Current docs use owner, and Application wrappers pass Application `this`, so keep `owner` for consistency unless a source header proves `source`.
- `listener` for `+0x04`: strongly supported by wrapper naming and the callback call.
- `scope` or `messageScope` for `+0x08`: use an enum/byte, not a bool.
- `messageType` for `+0x0c`: strongly supported by `Message::m_type` at `+0x04`.

Scope semantics:
- `scope == 1`: wildcard/all messages for the owner.
- `scope == 0`: message-type-specific registration; compare `entry->messageType` to `message->m_type`.
- other nonzero values: skipped by current dispatch logic, because the code only has the exact `1` wildcard path and the exact `0` message-type path.

Recommended enum names:

```cpp
enum ChangeMessageScope : uint8_t {
    ChangeMessageScope_MatchType = 0,
    ChangeMessageScope_AllTypes = 1,
};
```

Rejected alternative:
- A simple `bool allMessages` is not final-source quality. It would imply every nonzero value behaves as true, but the binary only treats exactly `1` as wildcard.

### Message API Names And Type Semantics

`Message::m_type` at `+0x04` is source-quality:
- `MessageCore` constructor stores the constructor argument at `this+0x04`.
- `ChangeManDispatchMessage` compares `entry->messageType` against `message+0x04`.
- Application cleanup/shutdown call paths construct local `Message` objects with constants such as `0x7465726d` and `0x676f6f67`.
- IDA `int_convert` confirms these are FourCC-like byte sequences, including `mret` and `goog` in little-endian memory order.

Keep the source type as `uint32_t` or an equivalent project typedef until an enum or FourCC typedef is source-proven.

### SortedList Helper And Callback Usage

ChangeMan's list usage is now sufficiently proven for source-quality text:
- Constructor allocates `SortedList(0x10, CompareChangeEntries, 100)`.
- `CompareChangeEntries` compares only the first dword, so list equality groups by `owner`.
- `SortedListFindFirstEqual` at `0x004f3780` uses bsearch and scans backward to the first equal comparator result.
- ChangeMan dispatch and filtered unregister rely on that lower-bound behavior, then walk same-owner entries forward.
- Virtual slot `+0x10` is `GetElementAt(index)`-like.
- Virtual slot `+0x1c` is `RemoveRange(index, count)` or `RemoveAt(index, count)`-like; ChangeMan always passes count `1`.

Evidence limit:
- The exact public SortedList method names are not source-proven. Descriptive names are acceptable in audit text, but final C++ should not depend on exact names until the SortedList API declaration is settled.

### Application Wrapper Reachability

Application wrapper leaves are a strong route-to-source signal, not target owners.

`ApplicationRegisterChangeListener` at `0x004f4b30`:
- pushes wrapper args plus Application `this`;
- loads `g_pChangeMan`;
- calls `ChangeMan_Register`.

`ApplicationUnregisterChangeListener` at `0x004f4b50`:
- pushes wrapper args plus Application `this`;
- loads `g_pChangeMan`;
- calls `ChangeMan_UnregisterFiltered`.

`ApplicationForwardMessage` at `0x004f4b70`:
- pushes the `Message *`;
- pushes Application `this` as owner/source;
- loads `g_pChangeMan`;
- calls `ChangeManDispatchMessage`.

Observed wrapper consumers include AboveFrame, FramePartPane, MapPane, and VideoPlayerPane setup/teardown paths. That supports a listener API and a pane-notification callback model, but it does not prove exact source spellings.

### BackPane Teardown Reachability

BackPane teardown proves the broad unregister method's source role:
- BackPane non-deleting destructor calls `ChangeManUnregisterObject(g_pChangeMan, this)`.
- BackPane scalar deleting destructor calls the same method before clearing `g_pBackPane` and optionally deleting.

This validates the broad cleanup method as a real source-authored lifecycle helper. It should not be dismissed as unused, compiler-generated, or a false split.

### Generated And Compiler-Helper Boundaries

Keep these boundaries explicit:
- [UID:0000ZZ] `ChangeManDispatchMessage` is source-authored method logic.
- [UID:000100] `ChangeManUnregisterObject` is source-authored method logic.
- [UID:000101] `CompareChangeEntries` is a file-local/source-local comparator callback passed to SortedList construction.
- [UID:000103] `ChangeMan_ScalarDeletingDestructor` is a compiler-generated deleting destructor wrapper around source destructor semantics. Its binary body is still useful for destructor behavior, but final source should not reproduce scalar-deleting wrapper details.
- `ClearChangeManSingleton`-style helper and constructor cleanup fragments should remain binary/lifecycle support, not independent source APIs unless source proof appears.
- [UID:000199] `ApplicationChangeManRegisterWrappers` is a no-emission aggregate/index; exact wrapper leaves carry source ownership.

## Final-C++ Blockers

The two primary targets can pass 85/85 without final C++ because their remaining blockers are exact-source declarations, not behavior.

Open blockers:
- Exact listener interface name is still not source-proven.
- Exact listener virtual method name for slot `+0x08` is still not source-proven.
- Exact owner/source parameter type is still not source-proven; `void *` is behaviorally safe but may not be the recovered source type.
- Exact public return types are still not source-proven. The methods naturally leave values in `EAX` due helper/callback calls, but checked callers do not require returned values.
- Exact message-scope enum/type name is still not source-proven.
- Exact SortedList public API names for find/get/remove are still descriptive reconstructions.

These blockers are narrow and documented. They should not hold the targets below 85, but they should continue to block pasted final C++.

## Target Text Summaries For Supervisor

### [UID:0000ZZ] Target Summary

Replace or extend the summary with:

`ChangeManDispatchMessage` dispatches a Message from a supplied owner/source object through ChangeMan's sorted registration list. It lower-bounds the list by owner with the SortedList first-equal helper, walks same-owner `ChangeManEntry` records, accepts entries whose scope byte is exactly `1` or whose scope byte is `0` and whose registered `messageType` equals `Message::m_type` at `+0x04`, and calls the listener object's vtable slot `+0x08` with `(owner, message)`. The sole direct caller is `ApplicationForwardMessage`, which supplies Application `this` as the owner/source and forwards the Message pointer through `g_pChangeMan`. Listener interface and callback source names remain descriptive, not source-proven.

Recommended metadata:
- `COMPLETION:86`
- `CONFIDENCE:90`
- `OWNER_UID:00001K`
- `EMITTER_UID:0000I2`
- `RECONSTRUCTABLE:TRUE`
- Keep final C++ blank or candidate-only; do not promote exact C++ yet.

### [UID:000100] Target Summary

Replace or extend the summary with:

`ChangeManUnregisterObject` performs broad object cleanup for ChangeMan registrations. It walks `changeList` backward from `count - 1`, fetches each `ChangeManEntry` through the SortedList get slot `+0x10`, and removes entries through the remove slot `+0x1c` with count `1` when the supplied object matches either `entry->owner` or `entry->listener`. The two direct callers are BackPane teardown paths, which pass BackPane `this` through `g_pChangeMan`; this confirms the method is a source-authored lifecycle cleanup helper rather than a filtered unregister or compiler artifact. Exact public overload/name remains source-inferred.

Recommended metadata:
- `COMPLETION:86`
- `CONFIDENCE:91`
- `OWNER_UID:00001K`
- `EMITTER_UID:0000I2`
- `RECONSTRUCTABLE:TRUE`
- Keep final C++ blank or candidate-only; do not promote exact C++ yet.

## Support-Doc Updates Recommended

Minimum support updates:
- `by-class/ChangeMan.md`: add a B002 source-quality note recording the best reconstructed API family:
  - `Register(owner, listener, messageType, scope)`
  - filtered unregister by owner/listener/messageType/scope
  - `DispatchMessage(owner, Message *)`
  - broad `UnregisterObject(object)` or overload-style `Unregister(object)`
  - callback slot `ChangeListener::OnChangeMessage(owner, Message *)` as descriptive, not source-proven
- `by-type/by-struct/ChangeManEntry.md`: strengthen the scope-byte note: exact `1` means all messages, exact `0` means type-filtered, other nonzero values do not match dispatch.
- `by-class/Message.md` or `MessageCore`: link `Message::m_type` at `+0x04` to ChangeMan dispatch and identify the type as a 32-bit/FourCC-like value, without inventing enum names.
- `by-class/SortedList.md` or `by-file/SortedList.md`: no score change required, but ChangeMan references can use descriptive names `FindFirstEqual`, `GetElementAt`, and `RemoveRange(index, 1)` with the caveat that exact source names remain pending.
- `by-file/Application.md` and exact Application wrapper leaves: refresh stale final-code-gate wording from the older 95/95 rule to the current combined-score/source-quality gate if those pages are opened by the supervisor.

Optional adjacent ChangeMan refresh if the supervisor wants coordinated rows:
- [UID:0000ZW] can reasonably move from `84/90` to `85/90` after the same listener/message/scope wording is added.
- [UID:0000ZY] can reasonably move from `84/90` to `85/90` after the same filtered-unregister wording is added.
- [UID:000101] can reasonably move from `84/90` to `85/90` because the comparator data xref from ChangeMan construction and first-dword comparison semantics are exact.
- [UID:0000ZT] and [UID:000103] can remain unchanged unless the supervisor is already refreshing the ChangeMan class page.

## Exact Coverage Report Replacement Rows

Primary replacement rows:

```text
- [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) 0x0047ee20-0x0047ee95 | method | ChangeManDispatchMessage : reconstructable : 86% : strong : B002 source-quality recheck confirms the owner lower-bound scan through SortedListFindFirstEqual, same-owner walk, `ChangeManEntry` scope semantics (`1` all messages, `0` message-type match, other nonzero values skip), `Message::m_type` read at `+0x04`, listener callback virtual slot `+0x08`, sole ApplicationForwardMessage caller, and valid ChangeMan class owner/emitter route; final C++ remains blank until the listener interface name, exact public return type, and message-scope enum spelling are final-source quality.
- [UID:000100][0x0047eea0-0x0047eedf.ChangeManUnregisterObject](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md) 0x0047eea0-0x0047eedf | method | ChangeManUnregisterObject : reconstructable : 86% : strong : B002 source-quality recheck confirms the reverse count-1 walk, SortedList get slot `+0x10`, owner-or-listener comparison against the supplied object, remove slot `+0x1c` with count `1`, two BackPane destructor callers through `g_pChangeMan`, and valid ChangeMan class owner/emitter route; final C++ remains blank until the broad unregister overload name and exact source return type are final-source quality.
```

Optional adjacent ChangeMan rows if those pages are refreshed:

```text
- [UID:0000ZW][0x0047ed50-0x0047ed73.ChangeManRegister](by-memory/0x0047ed50-0x0047ed73.ChangeManRegister.md) 0x0047ed50-0x0047ed73 | method | ChangeManRegister : reconstructable : 85% : strong : B002 source-quality recheck confirms stack construction of a 0x10-byte ChangeManEntry, Application wrapper reachability, SortedList insertion, owner/listener/messageType/scope field placement, and ChangeMan class owner/emitter route; final C++ remains blank until listener interface spelling, message-scope enum spelling, and exact return type are source-proven.
- [UID:0000ZY][0x0047ed80-0x0047ee1c.ChangeManUnregisterFiltered](by-memory/0x0047ed80-0x0047ee1c.ChangeManUnregisterFiltered.md) 0x0047ed80-0x0047ee1c | method | ChangeManUnregisterFiltered : reconstructable : 85% : strong : B002 source-quality recheck confirms lower-bound same-owner scan, listener wildcard handling, scope/message-type match semantics, SortedList get/remove usage, Application unregister-wrapper reachability, and ChangeMan owner/emitter route; final C++ remains blank until exact overload name, listener interface spelling, and message-scope enum spelling are source-proven.
- [UID:000101][0x0047ef20-0x0047ef33.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef33.CompareChangeEntries.md) 0x0047ef20-0x0047ef33 | comparator | CompareChangeEntries : reconstructable : 85% : strong : B002 source-quality recheck confirms this file-local SortedList comparator compares only the first dword of 0x10-byte ChangeManEntry records, grouping registrations by owner/source for lower-bound scans; final source should keep it local to ChangeMan until the exact comparator declaration style is recovered.
```

Coverage sync notes outside the primary target:
- The current report rows for [UID:000198], [UID:00019A], [UID:00019B], and [UID:000199] appear stale relative to their by-memory pages. If the supervisor edits coverage while applying this audit, sync those rows to the already-documented wrapper scores and metadata.
- [UID:000199] is a no-emission aggregate/index and should not be treated as final source body.

## Validation Commands

Suggested after supervisor applies accepted doc edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000ZZ-000100-changeman-method-source-quality-removed.md](0000ZZ-000100-changeman-method-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Optional search checks:

> Executable block R002 was removed from this report and preserved verbatim in [0000ZZ-000100-changeman-method-source-quality-removed.md](0000ZZ-000100-changeman-method-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## No-85 Decision

No no-85 decision is recommended for either primary target. The unresolved items are exact source spelling/declaration blockers, not behavioral or ownership blockers. The evidence is sufficient for 85/85+ documentation quality and still insufficient for final C++ promotion.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000ZZ-000100-changeman-method-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"0000ZZ"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000ZZ-000100-changeman-method-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0000ZZ-000100-changeman-method-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000ZZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
