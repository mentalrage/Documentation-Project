*** UID:00001K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChangeMan

## Summary

`ChangeMan` is an application-wide change/message subscription router. It stores listener records sorted by owner pointer, dispatches [UID:000084][Message](by-class/Message.md) objects to matching listeners, and removes all records associated with an object during teardown.

## Likely Original Placement

- Source: [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- Proposed path: `app/ChangeMan.cpp`
- Layout: [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- Primary vtable: [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md) at `0x00614cd0`
- Exact vtable data: [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md)
- Confidence: strong for class behavior, medium for exact app/helper file split.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0047ec70-0x0047ed20` | [UID:0000ZT][0x0047ec70-0x0047ed20.ChangeManConstructor](by-memory/0x0047ec70-0x0047ed20.ChangeManConstructor.md) | Constructs `LObject`, stores [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md), and allocates `SortedList(0x10, CompareChangeEntries, 100)`. |
| `0x0047ed20-0x0047ed50` | [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) | Compiler-generated partial-construction cleanup; not a handwritten method. |
| `0x0047ed50-0x0047ed80` | [UID:0000ZW][0x0047ed50-0x0047ed80.ChangeManRegister](by-memory/0x0047ed50-0x0047ed80.ChangeManRegister.md) | Builds a [UID:0001TV][ChangeManEntry](by-type/by-struct/ChangeManEntry.md) and inserts it through `SortedList::InsertSorted`. |
| `0x0047ed80-0x0047ee18` | [UID:0000ZY][0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered](by-memory/0x0047ed80-0x0047ee18.ChangeManUnregisterFiltered.md) | Removes entries matching owner/listener/scope/message filters. |
| `0x0047ee20-0x0047ee95` | [UID:0000ZZ][0x0047ee20-0x0047ee95.ChangeManDispatchMessage](by-memory/0x0047ee20-0x0047ee95.ChangeManDispatchMessage.md) | Finds the owner lower-bound and calls matching listener handlers. |
| `0x0047eea0-0x0047eedf` | [UID:000100][0x0047eea0-0x0047eedf.ChangeManUnregisterObject](by-memory/0x0047eea0-0x0047eedf.ChangeManUnregisterObject.md) | Removes any entry where owner or listener equals the supplied object. |
| `0x0047ef20-0x0047ef3f` | [UID:000101][0x0047ef20-0x0047ef3f.CompareChangeEntries](by-memory/0x0047ef20-0x0047ef3f.CompareChangeEntries.md) | Compares records by owner pointer. |
| `0x0047ef40-0x0047ef4b` | [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md) | Clears [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md). |
| `0x0047ef50-0x0047efae` | [UID:000103][0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor](by-memory/0x0047ef50-0x0047efae.ChangeManScalarDeletingDestructor.md) | Releases the sorted list, clears the singleton, destroys `LObject`, and optionally frees storage. |

## Evidence

- IDA exposes MSVC RTTI and a `ChangeMan` vtable at `0x00614cd0`, plus RTTI for `Singleton<ChangeMan>`.
- 2026-05-31 IDA MCP direct `.rdata` inspection confirms the `0x00614cd0` vtable has three slots and stops before `ChattingPane` RTTI at `0x00614cdc`; the exact data slice is now documented as [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md).
- `Application::Initialize` is the only direct constructor caller found in IDA.
- Application wrapper methods at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` forward registration, filtered unregister, and dispatch requests to `g_pChangeMan`.
- 2026-05-25 IDA MCP recheck reconfirmed the missing pair and the wrapper call sites at `0x004f4b43` and `0x004f4b63`.
- 2026-05-26 IDA MCP recheck reconfirmed `0x0047ed50`, `0x0047ed80`, and `0x0047ee20` have the same Application wrapper callers, and identified `0x0047ef40` as a modeled singleton-clear helper in this class range.
- [UID:00000S][BackPane](by-class/BackPane.md) destructors call `ChangeMan::Unregister` before clearing `g_pBackPane`.

## Generated Data Caveats

Current `source-3/simroot_v2/class_ChangeMan.cpp` emits constructor, dispatch, broad unregister, scalar deleting destructor, and [UID:0000QI][g_pChangeMan](by-global/g_pChangeMan.md). It omits the IDA-confirmed register and filtered-unregister methods at `0x0047ed50` and `0x0047ed80`.

Current `source-3/simroot_v2/class_ChangeMan.meta_wave3` also reports `vtable_count: 0`, despite IDA-confirmed vtable data at `0x00614cd0`.

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
- [UID:00000D][Application](by-class/Application.md)
- [UID:00000S][BackPane](by-class/BackPane.md)
- [UID:0000DF][SortedList](by-class/SortedList.md)
- [UID:000084][Message](by-class/Message.md)

## Changes

- What existed before: the page documented layout, vtable, singleton, method map, Application wrappers, and Wave3 omissions, but metadata still read `0/0`.
- What it was changed to: scores were set to `82/86`.
- Summary and evidence: constructor, register/unregister/dispatch, comparator, singleton clear, destructor, layout, vtable, and wrapper callers are covered; exact file split and some final source names remain open.

- 2026-05-31: Grading changed from `82/86` to `84/88`, and `RECONSTRUCTABLE` was set to `TRUE`.
  - Before: the class page referenced the `0x00614cd0` vtable but did not link an exact by-memory data child.
  - After: the class page links [UID:0002M8][0x00614cd0-0x00614cdc.ChangeManVtableData](by-memory/0x00614cd0-0x00614cdc.ChangeManVtableData.md) as the exact vtable-data range.
  - Evidence: IDA MCP `py_eval` and `xrefs_to` on 2026-05-31 reconfirmed the vtable dwords, RTTI boundary, constructor/destructor vptr-store xrefs, and destructor slot data xref.
