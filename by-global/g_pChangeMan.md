*** UID:0000QI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
ChangeMan *g_pChangeMan = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pChangeMan

## Status

- Storage: `0x0067ab2c`
- Exact memory page: [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- Owner: [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- Confidence: strong for storage, owner, lifecycle writes/clears, wrapper consumers, singleton class/vtable context, and the current first-draft source definition. The final header declaration/export spelling remains a source-integration caveat.

## Observed Evidence

- `ChangeMan::ChangeMan` at `0x0047ec70` writes `dword_67AB2C = this`.
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md) clears `dword_67AB2C` during partial-construction rollback.
- `ChangeMan::ScalarDeletingDestructor` at `0x0047ef50` writes `dword_67AB2C = 0`.
- Application wrappers at [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md) and [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md) read this pointer before forwarding into [UID:00001K][ChangeMan](by-class/ChangeMan.md).
- 2026-05-26 IDA MCP recheck also shows the singleton-clear helper at `0x0047ef40` writes this pointer to zero. Xrefs still include constructor writes, BackPane teardown reads, Application wrapper reads, and destructor cleanup.
- 2026-05-25 IDA MCP recheck also found reads at `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`, matching the Application wrapper bodies.
- [UID:0000HO][BackPane](by-file/BackPane.md) teardown uses this global to unregister pane-related change records.
- IDA lists RTTI for `ChangeMan` and `Singleton<ChangeMan>`, supporting singleton ownership.

## 2026-07-28 B007 Historical IDA Prestate And Supervisor-Applied Gate 2B

The semantic source declaration, four-byte address interval, zero bytes, and 11-reference role are unchanged. Before supervisor Gate 2B, live IDB `5a570ede` reported four separate one-byte items across `[0x0067ab2c,0x0067ab30)`; this table is preserved as the explicit historical supervisor prestate:

| Queried address | Current head/end | Width | Name | Type | Classification/comments |
| --- | --- | ---: | --- | --- | --- |
| `0x0067ab2c` | `0x0067ab2c-0x0067ab2d` | 1 | `unk_67AB2C` | `ChangeMan *` | `is_code:false`, `is_data:false`; regular/repeatable comments absent |
| `0x0067ab2d` | `0x0067ab2d-0x0067ab2e` | 1 | absent | absent | `is_code:false`, `is_data:false`; regular/repeatable comments absent |
| `0x0067ab2e` | `0x0067ab2e-0x0067ab2f` | 1 | absent | absent | `is_code:false`, `is_data:false`; regular/repeatable comments absent |
| `0x0067ab2f` | `0x0067ab2f-0x0067ab30` | 1 | absent | absent | `is_code:false`, `is_data:false`; regular/repeatable comments absent |

The historical prestate bytes were `00 00 00 00`. Its exact 11 refs were `0x00464c3e`, `0x0046792f`, `0x00467abf`, `0x0047ecb2`, `0x0047ecb9`, `0x0047ed3f`, `0x0047ef40`, `0x0047ef72`, `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`, covering Application cleanup, BackPane teardown, ChangeMan publication/clear lifecycle, and the three LObject forwarding wrappers. The separate protected prestate item at `0x0067ab28` was one byte typed `BrowserControlPane *`; the separate protected prestate item at `0x0067ab30` was one byte typed `EventDispatcher *`; both had blank names/comments.

Supervisor Gate 2B is now `APPLIED_VERIFIED` in active IDB/session `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` / `5a570ede`. The verified pre-mutation backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID00019A-20260728_1615.i64`, size `143190107` bytes, SHA256 `6DEB6CF617A6461568CA19BF32AFB8980BA876F27D1A1102F82E4A9FAED95F19`, byte-identical to the packed pre-mutation IDB.

The supervisor's `make_data` operation replaced only the four historical one-byte heads over `[0x0067ab2c,0x0067ab30)` with one size-4 `is_data:true` item named `g_pChangeMan` and typed `ChangeMan *`. Its regular comment is exactly `Process-wide ChangeMan singleton pointer used by LObject registration, unregistration, and dispatch wrappers.` and its repeatable comment is exactly `ChangeMan *g_pChangeMan;`. Queries at `0x0067ab2c`, `0x0067ab2d`, `0x0067ab2e`, and `0x0067ab2f` all resolve to head `0x0067ab2c`, end `0x0067ab30`, size 4, and those exact name/type/comments.

Current bytes remain `00 00 00 00`, and the exact 11 refs remain unchanged at `0x00464c3e`, `0x0046792f`, `0x00467abf`, `0x0047ecb2`, `0x0047ecb9`, `0x0047ed3f`, `0x0047ef40`, `0x0047ef72`, `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`. Protected `0x0067ab28` remains separate, typed `BrowserControlPane *`, with blank name/comments; protected `0x0067ab30` remains separate, typed `EventDispatcher *`, with blank name/comments. `0x004f4b50` remains the exact no-change `LObject_UnregisterChangeListener`, size `0x1c`, with its exact member prototype and function comment; `[0x004f4b6c,0x004f4b70)` remains `cc cc cc cc` padding and a non-function.

Final `idb_save` returned `ok:true`. The packed IDB is `143190108` bytes with SHA256 `4BC619B7E9B9D2866DB15B1A5DF260AACAD08A520CDD2BDFB9D4776DA975512E`; post-save health and all bounded readbacks passed. B007 performed no IDA mutation. This verified IDA normalization does not change this page's sole semantic source definition, owner/emitter, or `91/90` score.

## 2026-06-14 C001 IDA Recheck

The current live IDA MCP session is active on `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` reconfirmed `0x0067ab2c` is not a function; `0x0047ec70` is the constructor body; `0x0047ef40` is the singleton-clear helper; `0x0047ef50` is the scalar deleting destructor; and the Application wrappers at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` are small forwarding functions. `0x0047ed20` remains an unmodeled constructor-cleanup fragment rather than a modeled function start.

Current `xrefs_to 0x0067ab2c` reports exactly 11 refs and no additional pages: Application cleanup at `0x00464c3e`, BackPane teardown reads at `0x0046792f` and `0x00467abf`, constructor write/null-clear at `0x0047ecb2` / `0x0047ecb9`, constructor cleanup clear at `0x0047ed3f`, clear helper at `0x0047ef40`, scalar deleting destructor clear at `0x0047ef72`, and wrapper reads at `0x004f4b3d`, `0x004f4b5d`, and `0x004f4b77`. `analyze_component` reconfirmed the `ChangeMan` vtable at `0x00614cd0` is shared by the constructor and destructor, and that the three wrappers forward to `ChangeMan` register/unregister/dispatch helpers.

## Type Hypothesis

Current first-draft definition:

```cpp
ChangeMan *g_pChangeMan = NULL;
```

The previous `static` qualifier hypothesis is rejected under the current separated `Application.cpp` / `ChangeMan.cpp` route because Application wrapper leaves read the same global from a different source context. The final header declaration spelling remains open, but the source definition should be external-linkage in `ChangeMan.cpp`.

## Score Rationale

Completion is `91` because the page now records exact storage, owner, memory page, lifecycle write/clear set, Application and BackPane consumers, wrapper forwarding behavior, vtable context, RTTI/singleton context, current xref counts, and the first-draft formal source definition. Confidence is `90` because singleton ownership and source-definition route are strongly verified, while final header declaration spelling remains provisional.

## 2026-07-01 B009 Empty-Emitter Implementation

B009's accepted empty-emitter report populated the formal source definition `ChangeMan *g_pChangeMan = NULL;` and raised the score to `91/90`. Live MCP session `supervisor_resume_20260629` reconfirmed zero-initialized storage at `0x0067ab2c`, exactly 11 xrefs, constructor publish/null-adjustment writes, constructor-cleanup/helper/destructor clears, Application wrapper reads, BackPane teardown reads, and ordered Application cleanup read. The semantic source definition belongs here; [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md) documents exact storage and should not duplicate the definition.

## Cross-References

- [UID:0000I2][ChangeMan](by-file/ChangeMan.md)
- [UID:00001K][ChangeMan](by-class/ChangeMan.md)
- [UID:0001P4][0x0067ab2c-0x0067ab30.g_pChangeMan](by-memory/0x0067ab2c-0x0067ab30.g_pChangeMan.md)
- [UID:0001TW][ChangeManLayout](by-type/by-struct/ChangeManLayout.md)
- [UID:0000ZU][0x0047ec70-0x0047efae.ChangeMan](by-memory/0x0047ec70-0x0047efae.ChangeMan.md)
- [UID:0001X7][ChangeManVtable](by-type/by-vtable/ChangeManVtable.md)
- [UID:0000ZV][0x0047ed20-0x0047ed50.ChangeManConstructorCleanup](by-memory/0x0047ed20-0x0047ed50.ChangeManConstructorCleanup.md)
- [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md)
- [UID:000102][0x0047ef40-0x0047ef4b.ClearChangeManSingleton](by-memory/0x0047ef40-0x0047ef4b.ClearChangeManSingleton.md)
- [UID:0000HG][Application](by-file/Application.md)

## Changes

- 2026-07-28 B007 UID00019A support callback:
  - Preserved `91/90`, owner/emitter UID0000I2, and the sole semantic source definition. Added the literal current four-item IDA prestate, all 11 refs, protected neighbor state, and the exact pending supervisor Gate 2B action/readback without claiming that IDA has already changed.
- 2026-07-28 B007 post-Gate2B ordinary reconciliation:
  - Preserved the four-head state as historical supervisor prestate and recorded the verified backup, bounded `make_data` operation, exact size-4 item/name/type/comments, four-address containing-item readback, unchanged bytes/xrefs/neighbors/target/padding, successful IDB save, packed-IDB size/hash, and post-save health. B007 performed no IDA mutation.

- 2026-06-14 C001 low-confidence global refresh:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: current IDA MCP reconfirmed active IDB health, exact 11-ref storage xref set, constructor/cleanup/helper/destructor writes and clears, Application and BackPane reads, Application wrapper forwarding functions, and `ChangeMan` vtable sharing. Owner/emitter remain [UID:0000I2][ChangeMan](by-file/ChangeMan.md); no C++ or IDA database edits were made because final linkage spelling remains open.
- 2026-07-01 B009 empty-emitter implementation:
  - Changed score from `89/86` to `91/90`.
  - Summary/evidence: populated formal external-linkage source definition, replaced the stale private-static hypothesis under the current source split, and preserved the 11-xref storage/lifecycle evidence.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents storage, exact memory page, owner, constructor/destructor/cleanup writes, application wrapper reads, BackPane teardown use, RTTI singleton support, type hypothesis, and refs; final linkage spelling remains provisional.
- 2026-06-05: Marked reconstructable under [UID:0000I2][ChangeMan](by-file/ChangeMan.md). Evidence: live IDA MCP reports xrefs to `0x0067ab2c` from cleanup/application wrappers and `ChangeMan` lifecycle code; decompilation confirms `0x0047ec70` writes `dword_67AB2C`, `0x0047ef40` clears it, and `0x0047ef50` clears it during scalar deleting teardown.
