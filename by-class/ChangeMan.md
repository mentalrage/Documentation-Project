*** UID:00001K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ChangeMan::~ChangeMan()
{
    delete m_changeList;
    m_changeList = NULL;
    g_pChangeMan = NULL;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ChangeMan

## Summary

`ChangeMan` is an application-wide change/message subscription router. It stores listener records sorted by owner pointer, dispatches [UID:000084][Message](by-class/Message.md) objects to matching listeners, and removes all records associated with an object during teardown.

## Likely Original Placement

- Source: [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- Proposed path: `app/ChangeMan.cpp`
- Layout: [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- Primary vtable: [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md) at `0x00614cd0`
- Exact vtable data: [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- Confidence: strong for class behavior, layout, complete method/type surface, and `ChangeMan.cpp` placement.
- Parent/C++ status: reconstructable and attached to [UID:0000I2][ChangeMan](by-file/ChangeMan.md). This page emits the ordinary destructor and inserts class-owned exact children through `[[CHILDREN]]`: constructor, register, filtered unregister, dispatch, broad object unregister, and retained membership predicate. The file-local comparator emits through UID0000I2. UID000103 is non-reconstructable/blank-formal compiler output regenerated from the ordinary destructor.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0047ec70-0x0047ed20` | [UID:0000ZT][0x0047ec70-0x0047ed20.ChangeManConstructor](by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md) | Constructs `LObject`, stores [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), and allocates `SortedList(0x10, CompareChangeEntries, 100)` into the `SortedList*` member at `+0x04`. |
| `0x0047ed20-0x0047ed50` | [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) | Compiler-generated partial-construction cleanup; not a handwritten method. |
| `0x0047ed50-0x0047ed80` | [UID:0000ZW][0x0047ed50-0x0047ed80.ChangeManRegister](by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md) | Builds a [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) and inserts it through `SortedList::InsertSorted`; source-facing return is `void`. |
| `0x0047ed80-0x0047ee18` | [UID:0000ZY][0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered](by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md) | Filtered `ChangeMan::Unregister` removes entries matching LObject owner/listener and bool allMessages/MessageType filters; source-facing return is `void`. |
| `0x0047ee20-0x0047ee95` | [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) | Finds the LObject owner lower-bound and calls matching `LObject::OnChangeMessage` listeners. |
| `0x0047eea0-0x0047eedf` | [UID:000100][0x0047eea0-0x0047eedf.ChangeManUnregisterObject](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md) | Removes any entry where owner or listener equals the supplied object. |
| `0x0047eee0-0x0047ef1f` | [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md) | Retained/no-route method that returns whether an object is a registration owner or listener; source name and API visibility are descriptive. |
| `0x0047ef20-0x0047ef3f` | [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) | File-local/static comparator that compares records by owner pointer only. |
| `0x0047ef40-0x0047ef4b` | [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md) | Clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md). |
| `0x0047ef50-0x0047efae` | [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) | Compiler-generated scalar deleting destructor wrapper: releases the sorted list, clears the singleton, destroys `LObject`, and optionally frees storage. |

## Evidence

- IDA exposes MSVC RTTI and a `ChangeMan` vtable at `0x00614cd0`, plus RTTI for `Singleton<ChangeMan>`.
- 2026-05-31 IDA MCP direct `.rdata` inspection confirms the `0x00614cd0` vtable has three slots and stops before `ChattingPane` RTTI at `0x00614cdc`; the exact data slice is now documented as [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md).
- `Application::Initialize` is the only direct constructor caller found in IDA.
- Inherited LObject methods at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` forward registration, filtered unregister, and dispatch to `g_pChangeMan`; their mixed BackPane/Application receivers are consumers, not ChangeMan owners.
- 2026-05-25 IDA MCP recheck reconfirmed the missing pair and the wrapper call sites at `0x004f4b43` and `0x004f4b63`.
- 2026-05-26 IDA MCP recheck reconfirmed `0x0047ed50`, `0x0047ed80`, and `0x0047ee20` have the same Application wrapper callers, and identified `0x0047ef40` as a modeled singleton-clear helper in this class range.
- [UID:00000S][BackPane](by-class/BackPane.md) destructors call `ChangeMan::Unregister` before clearing `g_pBackPane`.
- Raw bounded disassembly at `0x0047eee0-0x0047ef1f` proves [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md). It has no modeled IDA function, external xref, VA/RVA pointer, or recovered source name.

## 2026-06-16 C001 IDA Refresh

Live IDA MCP `lookup_funcs` reconfirmed the current method family and sizes: constructor `0x0047ec70-0x0047ed20`, register `0x0047ed50-0x0047ed80`, filtered unregister `0x0047ed80-0x0047ee18`, dispatch `0x0047ee20-0x0047ee95`, broad unregister `0x0047eea0-0x0047eedf`, comparator `0x0047ef20-0x0047ef3f`, singleton clear `0x0047ef40-0x0047ef4b`, and scalar deleting destructor `0x0047ef50-0x0047efae`.

`xrefs_to` reconfirmed one Application wrapper caller for each register/filtered-unregister/dispatch method, one constructor data reference to the comparator, and the current 11-reference [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) set spanning Application cleanup, BackPane teardown, constructor/cleanup/destructor writes, the singleton-clear helper, and Application wrappers. Decompilation rechecked the 8-byte object layout, `+0x04` sorted-list pointer, `SortedList(16, CompareChangeEntries, 100)` construction, `ChangeManEntry` stack stores, wildcard unregister rules, dispatch callback slot, and destructor list/global cleanup.

Safe IDA names were applied and saved for `ChangeMan_Constructor`, `ChangeMan_Register`, `ChangeMan_UnregisterFiltered`, `ChangeMan_DispatchMessage`, `ChangeMan_UnregisterObject`, `CompareChangeEntries`, `ClearChangeManSingleton`, `ChangeMan_ScalarDeletingDestructor`, `ApplicationRegisterChangeListener`, `ApplicationUnregisterChangeListener`, `ApplicationForwardMessage`, and `g_pChangeMan`. IDA member/prototype edits were skipped because the final `ChangeListener`/`Message` API names, `SortedList` declaration shape, and public method signatures are still provisional.

## 2026-07-13 B003 UID0000ZW Complete API Synchronization

- The class remains an eight-byte `LObject` derivative with only `SortedList *m_changeList` at `+0x04`. Constructor allocation size, list construction arguments `(0x10, CompareChangeEntries, 100)`, singleton lifecycle, ordinary destructor, vtable, and compiler-wrapper evidence are unchanged.
- `ChangeManEntry` is `{LObject *owner; LObject *listener; bool allMessages; MessageType messageType;}`, size 16 with natural x86 padding at `+0x09..+0x0b`. No separate listener interface, source enum, or explicit padding member remains.
- The complete class API is `Register(LObject *, LObject *, MessageType, bool)`, filtered `Unregister(...)`, `DispatchMessage(LObject *, Message *)`, `UnregisterObject(LObject *)`, and retained `HasRegistrationForObject(LObject *)`. UID0004I6 spelling/access/const remain inferred because no route or symbol survives.
- Primary LObject slot `+0x08` is `OnChangeMessage(LObject *, Message *)`. Dispatch, the base no-op, and confirmed AboveFrame, FramePartPane, MapPane, and VideoPlayerPane overrides establish the common callback.
- `SortedList::InsertSorted(const void *)` returns an insertion index, but Register and all wrapper callers intentionally discard it. The manager/wrapper source API remains `void` and preserves EAX residue without inventing a contract.
- UID000198/19A/19B are inherited LObject wrappers emitted from LObject.cpp. Application and BackPane are caller/receiver surfaces only. The ChangeMan class/file route remains UID00001K -> UID0000I2 -> `NexusTK/app/ChangeMan.cpp`.
- The existing destructor and `[[CHILDREN]]` formal block are unchanged. UID000103, constructor cleanup, singleton clear, broad indexes, vtable bytes, and padding remain non-emitting compiler/index/data support.

## Historical 2026-06-16 B002 API Source-Quality Recheck

B002 rechecked the ChangeMan dispatch and broad-unregister methods after the C001 IDA refresh. The best current API family is:

- `Register(owner, listener, messageType, scope)` for stack-building a 16-byte [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) and inserting it into the sorted list.
- filtered unregister by owner/listener/messageType/scope for the `0x0047ed80` method.
- `DispatchMessage(owner, Message *)` for the `0x0047ee20` method.
- broad `UnregisterObject(object)` or overload-style `Unregister(object)` for the `0x0047eea0` cleanup method.
- `ChangeListener::OnChangeMessage(owner, Message *)` as the current descriptive listener callback name for virtual slot `+0x08`, not source-proven spelling.

The recheck confirms the class/file route: Application wrappers and BackPane destructors are caller surfaces through [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), while the owning state, sorted-list layout, comparator, singleton, and vtable remain ChangeMan-local. Scope semantics are exact enough for documentation: `scope == 1` dispatches all messages for the owner, `scope == 0` dispatches only when `messageType == Message::m_type`, and other nonzero values are skipped by the current dispatch logic. Final class-level C++ remains blank because the listener interface name, callback spelling, exact public signatures, scope enum spelling, and complete `SortedList` declaration are still descriptive reconstructions.

## Historical 2026-06-19 B010 Implementation Source-Quality Sync

- `ChangeManEntry` is a `0x10` / 16-byte sorted-list record: `owner` at `+0x00`, `listener` at `+0x04`, `scope` at `+0x08`, and `messageType` at `+0x0c`.
- `ChangeMan` is an 8-byte object with `LObject` base/vptr followed by `SortedList* m_changeList` at `+0x04`; constructor evidence allocates a `0x18` / 24-byte `SortedList`, constructs it for `0x10`-byte elements, passes `CompareChangeEntries`, and uses initial capacity `0x64` / 100.
- Source-facing registration names are `void ChangeMan::Register(...)` and filtered `void ChangeMan::Unregister(...)`. The by-memory file names may remain `ChangeManRegister` and `ChangeManUnregisterFiltered`; exact overload spelling is still a non-blocking header question.
- Scope semantics are exact byte behavior, not a boolean-only flag: `1` means all message types, `0` means message-type match, and other nonzero values skip the match branch.
- Sorted-list helper roles remain [UID:0000DF][SortedList](by-class/SortedList.md) responsibilities: `InsertSorted`, `FindFirstEqual`, `GetElementAt`, count access, and remove/remove-at-one-element semantics.
- [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) is file-local/private/static support that compares only `ChangeManEntry::owner` and returns `-1`, `0`, or `1`; it is passed by the constructor to `SortedList`.
- [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) is a vtable-slot-only wrapper at `0x00614cd0`, with no direct ordinary code callers. It destroys `m_changeList` with delete flag `1`, clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), runs `LObject` cleanup, and handles optional delete flags, but final source should define normal `~ChangeMan()` elsewhere.
- Old optional split rows/endpoints `0x0047ed73`, `0x0047ee1c`, and `0x0047ef33` are rejected; current exact ranges remain unchanged.

## Historical 2026-07-01 B009 Empty-Emitter Implementation

B009's accepted ChangeMan empty-emitter report is incorporated. The class carries the ordinary `ChangeMan::~ChangeMan()` first-draft source body. At that stage [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) used a no-code/generated-wrapper marker; the 2026-07-12 callback supersedes that marker with non-reconstructable/blank-formal metadata while preserving the source/runtime split.

The same B009 pass promotes first-draft method/source support for dispatch and broad unregister while keeping exact ownership unchanged. [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) now emits `void ChangeMan::DispatchMessage(void *owner, Message *message)`, and [UID:000100][0x0047eea0-0x0047eedf.ChangeManUnregisterObject](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md) now emits `void ChangeMan::UnregisterObject(void *object)`. The class/type support pages provide the accepted first-draft `ChangeManEntry`, `ChangeMessageScope`, `ChangeListener` callback vocabulary, and `SortedList *m_changeList` declaration shape.

## Historical 2026-07-12 B001 Complete-Child Emission

- Added `[[CHILDREN]]` after the existing ordinary destructor so accepted class-owned method pages emit through this class.
- Added [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md) to the method map. Its range and owner/listener predicate behavior are direct; name, visibility, and non-const declaration remain inferred.
- Existing exact constructor, register, filtered unregister, dispatch, broad unregister, comparator, and destructor first-draft bodies are unchanged.
- UID000103 is now explicitly non-reconstructable compiler output; ordinary destructor source remains here.
- Score `90/92` reflects complete inventory and working child insertion while retaining source-name/interface confidence caps.

Rejected alternatives remain explicit: Application and BackPane are caller surfaces, not owners; [UID:0000DF][SortedList](by-class/SortedList.md) owns list mechanics but not ChangeMan records or source methods; broad aggregate pages should not duplicate exact child bodies; no separate listener interface/source enum/explicit padding member is needed; and stale optional split endpoints `0x0047ed73`, `0x0047ee1c`, and `0x0047ef33` stay rejected.

## Score Rationale

Completion is `93` and confidence is `94` because the class page has current function/xref evidence, complete method inventory including retained UID0004I6, concrete LObject/Message/MessageType/bool types, exact layout/global anchors, inherited wrapper and BackPane reachability, file-parent routing through [UID:0000I2][ChangeMan](by-file/ChangeMan.md), accepted exact method bodies, ordinary destructor source, and explicit `[[CHILDREN]]` insertion. Remaining caps are exact original private spellings and retained-predicate visibility/const policy.

## Generated Output Routing

Current reconstruction uses `auto-generated/NexusTK/app/ChangeMan.cpp`. The class formal block provides the ordinary destructor and `[[CHILDREN]]`; exact member children provide constructor/register/filtered-unregister/dispatch/broad-unregister/predicate bodies. UID000101 provides the file-local comparator, and UID0000QI provides `g_pChangeMan`. Broad indexes and compiler wrappers remain blank-formal/non-emitting.

## Cross-References

- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md)
- [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md)
- [UID:00000D][Application](by-class/Application.md)
- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-06-06 A008:
  - Before: the class was reconstructable and scored `84/88` but remained unassigned, leaving child type pages such as [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) and [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md) with an unknown autogen parent chain.
  - After: set `AUTOGEN_PARENT_UID` to [UID:0000I2][ChangeMan](by-file/ChangeMan.md) and documented why final class C++ remains blank.
  - Evidence: the file root [UID:0000I2][ChangeMan](by-file/ChangeMan.md) is valid at `NexusTK/app/` and scored `86/89`, while this class page already records the constructor, registration/unregister/dispatch methods, comparator, singleton clear, destructor, exact vtable-data child, layout, and wrapper evidence at `84/88`.

- What existed before: the page documented layout, vtable, singleton, method map, Application wrappers, and Wave3 omissions, but metadata still read `0/0`.
- What it was changed to: scores were set to `82/86`.
- Summary and evidence: constructor, register/unregister/dispatch, comparator, singleton clear, destructor, layout, vtable, and wrapper callers are covered; exact file split and some final source names remain open.

- 2026-05-31: Grading changed from `82/86` to `84/88`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the class page referenced the `0x00614cd0` vtable but did not link an exact by-memory data child.
  - After: the class page links [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) as the exact vtable-data range.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` on 2026-05-31 reconfirmed the vtable dwords, RTTI boundary, constructor/destructor vptr-store xrefs, and destructor slot data xref.
- 2026-06-16 C001 type/layout support refresh:
  - Changed score from `84/88` to `85/89`.
  - Evidence: live IDA reconfirmed all ChangeMan function boundaries, wrapper callers, singleton xrefs, layout/list/entry behavior, and vtable/global support. Safe IDA function/global names were applied and saved. Final C++ remains blank because the listener/message API names, method signatures, and `SortedList` declaration are still provisional.
- 2026-06-16 B002 method source-quality recheck:
  - Scores unchanged.
  - Evidence: report-only audit refined the best descriptive API family, confirmed Application and BackPane as caller surfaces rather than owners, documented exact scope-byte behavior including skipped nonzero values, and kept final class C++ blank until listener/interface/signature names are source-proven.
- 2026-06-19 B010 implementation sync:
  - Scores unchanged.
  - Evidence: accepted B010 source-quality report populated first-draft method C++ in the five target pages where appropriate, preserved the scalar deleting destructor as formal-no-code wrapper mechanics, and synchronized class-level layout, helper ownership, scope semantics, source-name caveats, and stale endpoint rejection.
- 2026-07-01 B009 empty-emitter implementation:
  - Changed score from `85/89` to `88/91`.
  - Evidence: accepted B009 report added ordinary `ChangeMan::~ChangeMan()` formal source, kept scalar-deleting-wrapper handling as an explicit no-code/generated-wrapper marker on [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md), populated dispatch and broad-unregister exact children, and synchronized empty-emitter disposition for class/type/global/vtable/aggregate support while preserving source-name caveats.
- 2026-07-12 B001 accepted UID0000ZU callback:
  - Changed score `88/91 -> 90/92`, appended `[[CHILDREN]]`, added retained predicate UID0004I6, removed stale generated-data provenance, and aligned compiler-wrapper disposition without changing existing exact source bodies.
- 2026-07-13 B003 UID0000ZW implementation:
  - Changed `90/92 -> 93/94`, synchronized the complete LObject/MessageType/bool/natural-padding API and inherited wrapper route, and preserved the exact destructor/`[[CHILDREN]]` block, method ranges, and compiler/index exclusions.
