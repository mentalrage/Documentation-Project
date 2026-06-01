*** UID:0000QI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChangeMan

## Status

- Storage: `0x0067ab2c`
- Exact memory page: [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- Owner: [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- Confidence: strong for storage and owner, medium for final linkage spelling.
- Current generated owner file: `source-3/simroot_v2/class_ChangeMan.cpp`

## Observed Evidence

- `ChangeMan::ChangeMan` at `0x0047ec70` writes `dword_67AB2C = this`.
- The compiler-generated [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) clears `dword_67AB2C` during partial-construction rollback.
- `ChangeMan::ScalarDeletingDestructor` at `0x0047ef50` writes `dword_67AB2C = 0`.
- Application wrappers at [UID:000199][0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md) and [UID:00019B][0x004f4b70-0x004f4b86.ApplicationForwardMessage](by-memory/0x004f4b70-0x004f4b86.ApplicationForwardMessage.md) read this pointer before forwarding into [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- 2026-05-26 IDA MCP recheck also shows the singleton-clear helper at `0x0047ef40` writes this pointer to zero. Xrefs still include constructor writes, BackPane teardown reads, Application wrapper reads, and destructor cleanup.
- 2026-05-25 IDA MCP recheck also found reads at `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`, matching the Application wrapper bodies.
- [UID:0000HO][BackPane](by-file/BackPane.md) teardown uses this global to unregister pane-related change records.
- IDA lists RTTI for `ChangeMan` and `Singleton<ChangeMan>`, supporting singleton ownership.

## Type Hypothesis

Likely declaration:

```cpp
static ChangeMan* g_pChangeMan;
```

The `static` qualifier is provisional until final source linkage is known.

## Cross-References

- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:000199][0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.ApplicationChangeManRegisterWrappers.md)
- [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents storage, exact memory page, owner, constructor/destructor/cleanup writes, application wrapper reads, BackPane teardown use, RTTI singleton support, type hypothesis, and refs; final linkage spelling remains provisional.
