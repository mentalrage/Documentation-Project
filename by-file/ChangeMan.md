*** UID:0000I2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ChangeMan

## Status

- Proposed module: `app/ChangeMan.cpp`
- Proposed header: `app/ChangeMan.h` or a private application message header.
- Confidence: strong for class/module ownership, concrete type model, emitter routing, and first-draft source coverage; exact original header split remains inferred.
- Documentation basis: IDA-confirmed ChangeMan method ranges plus the by-class, by-memory, by-global, and by-type anchors below.
- Type/storage anchors: [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md), [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md), and [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)

## File Role

`ChangeMan.cpp` is the client-wide change notification router. It lets `LObject` owners register `LObject` listeners for either all messages or one [UID:000084][Message](by-class/Message.md) type, keeps those registrations sorted by owner pointer, and dispatches forwarded messages to matching listeners. The source field is `bool allMessages`: exact true means all message types, exact false means `MessageType` match, and invalid non-boolean bytes remain documented binary negative evidence.

The class is application infrastructure, not a map or UI pane implementation. [UID:0000HG][Application](by-file/Application.md) constructs the singleton; inherited LObject methods forward registration, unregister, and dispatch from `NexusTK/util/LObject.cpp`. Application, [UID:0000HO][BackPane](by-file/BackPane.md), and other UI/map classes consume the router but do not own it.

## Likely Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00001K][ChangeMan](by-class/ChangeMan.md) | `0x0047ec70-0x0047efae` | Singleton router and sorted registration list. The class page now emits the ordinary `ChangeMan::~ChangeMan()` source and documents constructor/register/filtered-unregister/dispatch/broad-unregister/comparator coverage. |
| [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) | `0x0047ee20-0x0047ee95` | First-draft emitting `void ChangeMan::DispatchMessage(LObject *owner, Message *message)` through class owner [UID:00001K][ChangeMan](by-class/ChangeMan.md). |
| [UID:000100][0x0047eea0-0x0047eedf.ChangeManUnregisterObject](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md) | `0x0047eea0-0x0047eedf` | First-draft broad object unregister method, modeled as `void ChangeMan::UnregisterObject(LObject *object)`. |
| [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md) | `0x0047eee0-0x0047ef1f` | First-draft retained membership predicate; reverse-scans rows and returns true for owner or listener equality. Name and visibility are descriptive because no route or symbol survives. |
| [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) | `0x0047ef50-0x0047efae` | Non-reconstructable, blank-formal scalar deleting destructor wrapper; source-level teardown is emitted by the ordinary destructor on [UID:00001K][ChangeMan](by-class/ChangeMan.md). |
| [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md) | object size `0x08` | First-draft class declaration: `LObject` base plus `SortedList *m_changeList` at `+0x04`, constructor/destructor, register/unregister/dispatch/broad-unregister method family. |
| [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) | 16-byte sorted-list record | First-draft `ChangeManEntry { LObject *owner, LObject *listener, bool allMessages, MessageType messageType }`; bytes `+0x09..+0x0b` are natural x86 padding, not a source member. |
| [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md) / [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) | `0x00614cd0-0x00614cdc` | Formal generated-binary marker for the three-slot primary vtable; exact bytes stay evidence rather than handwritten source. |
| [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) | [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md) | Emitting process singleton pointer definition, `ChangeMan *g_pChangeMan = NULL;`; raw storage page is covered-by-global evidence. |
| [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) | `0x0047ef20-0x0047ef3f` | File-local/static owner-pointer comparator for `SortedList`, already emitted as source support. |
| [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md) | broad method range | Non-reconstructable, blank-formal physical index over exact source children, compiler support, and alignment. |
| [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md) | pair range | Non-reconstructable, blank-formal pair index; `Register` and filtered `Unregister` remain on exact child pages. |
| [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md) | `0x0047ef40-0x0047ef4b` | Tiny singleton-clear helper adjacent to the destructor; still compiler/lifecycle support rather than a public source API. |

The three adjacent forwarding methods [UID:000198][0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md), [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md), and [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md) are inherited LObject members routed through LObject.cpp. Mixed BackPane/Application receivers establish the common base. They are consumers, not ChangeMan ownership evidence.

The [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) is compiler-generated partial-construction cleanup. It belongs to binary documentation and the ignored ledger, not to a handwritten source function.

## Evidence

- IDA confirms `Application::Initialize` allocates `0x08` bytes and calls `ChangeMan::ChangeMan` at `0x004644c1`.
- IDA confirms the `ChangeMan` vtable at `0x00614cd0` through constructor, constructor-cleanup, and destructor vptr stores; 2026-05-31 IDA MCP direct `.rdata` inspection captures the exact `0x00614cd0-0x00614cdc` vtable-data child range.
- The constructor allocates a [UID:0000NU][SortedList](by-file/SortedList.md) with element size `0x10`, comparator `0x0047ef20`, and initial capacity `100`.
- `DispatchChangeMessage` at `0x0047ee20` lower-bounds the sorted list by LObject owner, scans same-owner records, checks bool allMessages/MessageType, and calls `LObject::OnChangeMessage` at primary virtual slot `+0x08`.
- `Unregister` at `0x0047eea0` walks the list backward so it can remove all owner/listener matches without invalidating later indices.
- Inherited `LObject::ForwardMessage` at `0x004f4b70` directly forwards to `g_pChangeMan`.
- `BackPane` destructor paths call `ChangeMan::Unregister(this)` through `g_pChangeMan`.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0047ed50` and `0x0047ed80` as real omitted methods and reconfirmed their only callers as Application wrappers.
- 2026-05-26 IDA MCP recheck reconfirmed all ChangeMan method boundaries, the Application wrapper callers for `0x0047ed50`, `0x0047ed80`, and `0x0047ee20`, and the tiny singleton-clear helper at `0x0047ef40`.
- 2026-07-12 bounded raw disassembly added [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md). It is a complete 63-byte member body between alignment bytes, has no modeled function/xref/pointer route, and checks both registration owner and listener fields.

## 2026-07-13 B003 UID0000ZW Source Route Synchronization

- `NexusTK/app/ChangeMan.cpp` remains the single source route for ChangeMan, its ordinary destructor, exact class methods, file-local owner comparator, and singleton definition. UID0000ZU/UID0000ZX remain blank non-emitting indexes; UID000103 and cleanup helpers remain compiler-generated/no-code.
- ChangeMan remains eight bytes with `SortedList *m_changeList` at `+0x04`; its list contains 16-byte LObject/LObject/bool/MessageType records with natural x86 padding.
- Register ignores the genuine `int SortedList::InsertSorted(const void *)` return. Filtered unregister preserves null-listener wildcard and exact true/false filtering; dispatch calls `LObject::OnChangeMessage`; broad unregister and retained predicate use `LObject *object`.
- The public forwarding trio moves to `NexusTK/util/LObject.cpp` as inherited LObject members. Application constructs/uses ChangeMan and BackPane participates as owner/listener, but neither consumes source ownership.
- Original private names and header split remain inferred. Rejected routes remain Application.cpp absorption, BackPane ownership, SortedList ownership of ChangeMan methods, duplicate aggregate bodies, explicit source padding, a separate listener interface/scope enum, and handwritten compiler artifacts.

## Method Inventory And Alias Caveats

Do not treat a ChangeMan source candidate as complete unless it includes both registration methods at `0x0047ed50` and `0x0047ed80`. IDA confirms both as ChangeMan methods and direct callees of application wrapper methods, and [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md) is the durable inventory for that pair. The source-facing forms are `void ChangeMan::Register(...)` and filtered `void ChangeMan::Unregister(...)`; the document file names may retain `ChangeManRegister` and `ChangeManUnregisterFiltered`, and exact overload spelling remains a header-recovery question.

Any alias or summary that describes character transformations conflicts with the IDA-backed role. The documented owner is an application change/message router with primary vtable `0x00614cd0`, exact vtable-data child [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md), and process singleton [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md).

## Historical 2026-06-22 B002 Method Rule 26 Closeout

The archived B002 method audit is incorporated into this source-file route without changing the existing file score. The accepted API family remains `Register(owner, listener, messageType, scope)`, filtered `Unregister(owner, listener, messageType, scope)`, `DispatchMessage(owner, Message *)`, and broad `UnregisterObject(object)` / overload-style `Unregister(object)`. `ChangeListener::OnChangeMessage(owner, Message *)` is the best current descriptive callback name for listener virtual slot `+0x08`, but the exact interface name, callback spelling, owner/source parameter type, public return types, scope enum name, and public SortedList method names remain final-source blockers.

B002's inference recheck confirms Application wrappers are public caller surfaces, BackPane teardown is a lifecycle consumer of the broad unregister method, and neither should take ownership from this file. The owning evidence is still ChangeMan-local: the singleton [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), 8-byte object layout, sorted `ChangeManEntry` list, owner-only comparator, and `0x00614cd0` vtable. Keep [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md), [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md), and [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) documented as compiler/lifecycle support rather than independent source APIs unless stronger source evidence appears.

## Source-Structure Decision

Use `app/ChangeMan.cpp` as the working file. The class is created by `Application` and provides process-level message routing, but keeping it as a small adjacent app helper is cleaner than absorbing it into the already large `Application.cpp`. If later original-source evidence shows it was private to `Application.cpp`, the class and type docs should still remain separate for reverse-engineering clarity.

## Historical 2026-06-19 B010 Implementation Source-Quality Sync

- Constructor/source layout: `ChangeMan` has `SortedList*` at `+0x04`; construction allocates a `0x18` / 24-byte `SortedList`, uses `ChangeManEntry` element size `0x10` / 16, passes file-local `CompareChangeEntries`, and seeds capacity `0x64` / 100.
- Registration source shape: `Register` builds `ChangeManEntry { owner, listener, scope, messageType }` and calls `SortedList::InsertSorted`; source-facing return is `void`, not insert-index or boolean.
- Filtered unregister source shape: `Unregister` finds the first equal owner entry, scans contiguous owner records with `GetElementAt`, applies listener/scope/message matching, removes one matching entry at a time, and compensates index/count after removal; source-facing return is `void`.
- Sorted-list helper names in this file are descriptive API roles owned by [UID:0000NU][SortedList](by-file/SortedList.md) / [UID:0000DF][SortedList](by-class/SortedList.md): `InsertSorted`, `FindFirstEqual`, `GetElementAt`, and remove/remove-at semantics.
- [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) is private/file-local/static support that compares only `ChangeManEntry::owner` and returns `-1`, `0`, or `1`.
- [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) remains compiler-generated wrapper documentation: the vtable slot at `0x00614cd0` references it, no direct ordinary code callers were found, and final source should define normal `~ChangeMan()` for `m_changeList`/singleton teardown.
- Stale B002 optional split endpoints `0x0047ed73`, `0x0047ee1c`, and `0x0047ef33` remain rejected; no ChangeMan range changes are implied.

## Historical 2026-07-01 B009 Empty-Emitter Implementation

B009's accepted empty-emitter implementation raises this file root to `90/91` and records `ChangeMan.cpp` as the emitting owner for the completed first-batch source set. The source-emitting route is intentionally split: exact method pages emit constructor/register/filtered-unregister/dispatch/broad-unregister/comparator first drafts, [UID:00001K][ChangeMan](by-class/ChangeMan.md) emits the ordinary destructor, [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) and [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md) emit type declarations, and [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) emits the singleton definition.

At the 2026-07-01 stage, generated-binary and aggregate targets used formal markers to avoid blank emitters. The 2026-07-12 callback supersedes the three affected marker routes: UID000103 is non-reconstructable compiler output, and UID0000ZU/UID0000ZX are non-reconstructable indexes, all with blank formal blocks. Vtable and raw singleton marker handling is unchanged.

The implementation preserves the accepted MCP evidence from `supervisor_resume_20260629`: `idb_open`/`server_health` were OK, function sizes and bounds were current, the Application wrapper callers reach register/filtered-unregister/dispatch through `g_pChangeMan`, BackPane teardown reaches broad unregister, `0x00614cd0` vtable and `0x0067ab2c` singleton xrefs match the ChangeMan route, and padding/boundary bytes keep the existing split stable. Application, BackPane, SortedList, no-owner/no-emitter, duplicate aggregate-body, hand-authored vtable, hand-authored scalar deleting wrapper, and private-static singleton-only routes remain rejected.

Scope-byte and return-type decisions remain the same as the earlier source-quality sync. Scope value `1` matches all message types, exact `0` requires message-type equality, and other nonzero scope values do not match. `Register`, filtered `Unregister`, dispatch, and broad unregister are modeled as `void` first-draft APIs because wrapper/caller evidence proves side effects but does not prove consumed indices, booleans, or removal counts.

Expected generated result after scoped validation: `auto-generated/NexusTK/app/ChangeMan.cpp` is fresh for the final waited validator command; class-owned exact methods, including UID0004I6, appear once; ordinary destructor, comparator, singleton, and unaffected generated-binary markers remain correctly placed; UID0000ZU/UID0000ZX aggregate comments and UID000103 compiler-wrapper source do not emit.

## Historical 2026-07-12 B001 Complete Route Sync

- Added retained predicate UID0004I6 and its direct behavior/negative-route evidence to the file inventory.
- UID00001K now inserts class-owned exact children; existing exact method bodies remain unchanged.
- Reclassified UID0000ZU/UID0000ZX as non-emitting indexes and UID000103 as compiler output while retaining this file as source placement.
- At that stage registration/unregister wrappers were modeled as source-neutral helpers and UID00019B as `Application::ForwardMessage`; the 2026-07-13 complete-family pass supersedes all three with inherited LObject methods.
- File score remains `90/91`; the callback completes child routing without changing the established module path.

## Cross-References

- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md)
- [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md)
- [UID:0004I6][0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject](by-memory/0x0047eee0-0x0047ef1f.ChangeManHasRegistrationForObject.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the application change router, singleton, layout/vtable/type anchors, registration/dispatch methods, Application wrappers, and omitted-method caveats but remained unevaluated.
  - After: score reflects documented module ownership, constructor/destructor behavior, sorted-list registration model, dispatch filtering, unregister behavior, singleton/global storage, and exact Application wrapper surface.
  - Evidence: IDA notes confirm construction from `Application::Initialize`, vtable stores, omitted registration methods, dispatch wrapper callers, singleton clear helper, and BackPane unregister callers.

- 2026-05-31: Grading changed from `84/88` to `86/89`, and `PROPOSED_RECONSTRUCTION_PATH` was set to `NexusTK/app/`.
  - Before: the page named `app/ChangeMan.cpp` in prose but the validator-managed reconstructed path was blank, and the vtable had no exact by-memory data child.
  - After: the page uses `NexusTK/app/` for staged source placement and links [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) as the exact source-declared vtable data.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ChangeMan.cpp` under `app`, and IDA MCP `py_eval`/`xrefs_to` on 2026-05-31 reconfirmed the exact vtable-data range and slot xrefs.
- 2026-06-06 provenance cleanup:
  - Scores and projected path unchanged.
  - Summary/evidence: replaced stale recovered-output and active-output wording with the current IDA/by-* evidence basis. The file still records the two required registration methods, vtable-data child, singleton, Application wrapper surface, and character-transformation alias conflict without depending on old output provenance.
- 2026-06-19 B010 implementation sync:
  - Scores and projected path unchanged.
  - Summary/evidence: synchronized accepted source-quality details for constructor/list layout, `ChangeManEntry` field offsets, `void` register/unregister source shape, exact scope-byte semantics, file-local comparator ownership, scalar-deleting-destructor wrapper policy, and rejected stale split endpoints.
- 2026-07-01 B009 empty-emitter implementation:
  - Scores changed from `86/89` to `90/91`.
  - Summary/evidence: incorporated accepted first-batch source and formal-marker coverage for destructor, dispatch, broad unregister, entry/layout declarations, vtable markers, semantic singleton definition, raw singleton storage coverage, broad range index, registration-pair index, and generated-output expectations. Owner/emitter route remains [UID:0000I2][ChangeMan](by-file/ChangeMan.md) through `NexusTK/app/ChangeMan.cpp`; rejected routes are Application, BackPane, SortedList, no-owner/no-emitter, duplicate aggregate body, hand-authored vtable, hand-authored scalar deleting wrapper, and private-static singleton-only ownership.
- 2026-07-12 B001 accepted UID0000ZU callback:
  - Added UID0004I6, synchronized class-child insertion, aggregate/compiler non-emitting dispositions, forwarding-helper classifications, and current generated-route expectations. Score/path remain `90/91` and `NexusTK/app/`.
- 2026-07-13 B003 UID0000ZW implementation:
  - Changed `90/91 -> 93/94`, synchronized the concrete LObject/MessageType/bool/natural-padding model and inherited LObject wrapper route, and preserved `NexusTK/app/`, exact child/index/compiler dispositions, and unrelated source contents.
