*** UID:0000I2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ChangeMan

## Status

- Proposed module: `app/ChangeMan.cpp`
- Proposed header: `app/ChangeMan.h` or a private application message header.
- Confidence: strong for class/module ownership, medium for exact original folder.
- Current recovered source: `source-3/simroot_v2/class_ChangeMan.cpp`
- Type/storage anchors: [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md), [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md), and [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)

## File Role

`ChangeMan.cpp` is the client-wide change notification router. It lets owners register listener objects for either all messages or one [UID:000084][Message](by-class/Message.md) type, keeps those registrations sorted by owner pointer, and dispatches application-forwarded messages to matching listeners.

The class is application infrastructure, not a map or UI pane implementation. [UID:0000HG][Application](by-file/Application.md) constructs the singleton and exposes small wrapper methods around registration, unregister, and dispatch. UI/map classes such as [UID:0000HO][BackPane](by-file/BackPane.md) consume the router but should not own it.

## Likely Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00001K][ChangeMan](by-class/ChangeMan.md) | `0x0047ec70-0x0047efae` | Singleton router and sorted registration list, including [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md). |
| [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md) | object size `0x08` | `LObject` vtable/base plus `SortedList*` at `+0x04`. |
| [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md) / [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) | `0x00614cd0-0x00614cdc` | Three-slot primary vtable with scalar deleting destructor and inherited `LObject` slots. |
| [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) | 16-byte sorted-list record | Owner/listener/scope/message tuple. |
| [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md) | [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md) | Process singleton pointer. |
| [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) | `0x0047ef20-0x0047ef3f` | Owner-pointer comparator for `SortedList`. |
| [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md) | `0x0047ef40-0x0047ef4b` | Tiny singleton-clear helper adjacent to the destructor. |

The application wrappers at [UID:000199][0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md) and [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md) belong with [UID:0000HG][Application](by-file/Application.md), but they are the public call surface for this router.

The [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) is compiler-generated partial-construction cleanup. It belongs to binary documentation and the ignored ledger, not to a handwritten source function.

## Evidence

- IDA confirms `Application::Initialize` allocates `0x08` bytes and calls `ChangeMan::ChangeMan` at `0x004644c1`.
- IDA confirms the `ChangeMan` vtable at `0x00614cd0` through constructor, constructor-cleanup, and destructor vptr stores; 2026-05-31 IDA MCP direct `.rdata` inspection captures the exact `0x00614cd0-0x00614cdc` vtable-data child range.
- The constructor allocates a [UID:0000NU][SortedList](by-file/SortedList.md) with element size `0x10`, comparator `0x0047ef20`, and initial capacity `100`.
- `DispatchChangeMessage` at `0x0047ee20` lower-bounds the sorted list by owner pointer, scans same-owner records, checks scope/message type, and calls the listener virtual slot at `+0x08`.
- `Unregister` at `0x0047eea0` walks the list backward so it can remove all owner/listener matches without invalidating later indices.
- `Application::ForwardMessage` at `0x004f4b70` directly forwards to `g_pChangeMan`.
- `BackPane` destructor paths call `ChangeMan::Unregister(this)` through `g_pChangeMan`.
- 2026-05-25 IDA MCP recheck reconfirmed `0x0047ed50` and `0x0047ed80` as real omitted methods and reconfirmed their only callers as Application wrappers.
- 2026-05-26 IDA MCP recheck reconfirmed all ChangeMan method boundaries, the Application wrapper callers for `0x0047ed50`, `0x0047ed80`, and `0x0047ee20`, and the tiny singleton-clear helper at `0x0047ef40`.

## Generated Output Caveats

Current `simroot_v2` output omits `0x0047ed50` and `0x0047ed80`, even though IDA confirms both as ChangeMan methods and direct callees of application wrapper methods. Do not migrate active `class_ChangeMan.cpp` without adding those two methods or preserving an explicit omission note.

Current `class_ChangeMan.meta_wave3` also reports `vtable_count: 0` and carries a misleading active summary about character transformations; IDA evidence supports an application change/message router with primary vtable `0x00614cd0`.

## Source-Structure Decision

Use `app/ChangeMan.cpp` as the working file. The class is created by `Application` and provides process-level message routing, but keeping it as a small adjacent app helper is cleaner than absorbing it into the already large `Application.cpp`. If later original-source evidence shows it was private to `Application.cpp`, the class and type docs should still remain separate for reverse-engineering clarity.

## Cross-References

- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:0000ZX][0x0047ed50-0x0047ee18.ChangeManRegistrationMethods](by-memory/0x0047ed50-0x0047ee18.ChangeManRegistrationMethods.md)
- [UID:000199][0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md)
- [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md)
- [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:0000NU][SortedList](by-file/SortedList.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `84/88`.
  - Before: page documented the application change router, singleton, layout/vtable/type anchors, registration/dispatch methods, Application wrappers, and generated-output caveats but remained unevaluated.
  - After: score reflects documented module ownership, constructor/destructor behavior, sorted-list registration model, dispatch filtering, unregister behavior, singleton/global storage, and exact Application wrapper surface.
  - Evidence: IDA notes confirm construction from `Application::Initialize`, vtable stores, omitted registration methods, dispatch wrapper callers, singleton clear helper, and BackPane unregister callers.

- 2026-05-31: Grading changed from `84/88` to `86/89`, and `PROPOSED_RECONSTRUCTION_PATH` was set to `NexusTK/app/`.
  - Before: the page named `app/ChangeMan.cpp` in prose but the validator-managed reconstructed path was blank, and the vtable had no exact by-memory data child.
  - After: the page uses `NexusTK/app/` for staged source placement and links [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) as the exact source-declared vtable data.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ChangeMan.cpp` under `app`, and IDA MCP `py_eval`/`xrefs_to` on 2026-05-31 reconfirmed the exact vtable-data range and slot xrefs.
