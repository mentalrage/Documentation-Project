*** UID:0000RH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static MemoryMan *g_pMemoryMan = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pMemoryMan

## Status

- Confidence: strong for storage address, singleton lifecycle, accessor, and allocator bootstrap role; medium-high for final source spelling/placement.
- Address: `0x0069b4fc` (`dword_69B4FC` / `DAT_0069b4fc`)
- Working id: `g_pMemoryMan`
- Likely owner: [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- Memory storage page: [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)

## Role

`g_pMemoryMan` stores the process-wide `MemoryMan` singleton pointer. Most allocation call sites do not use the object directly; they touch it through `GetMemoryMan` and then call allocation/free helper functions.

Accepted first-draft declaration during reconstruction:

```cpp
static MemoryMan *g_pMemoryMan = NULL;
```

The source-facing name `g_pMemoryMan` remains inferred rather than recovered from a debug/global symbol. B006 2026-06-26 current MCP `list_globals` did not return a symbol for this storage or for the name `g_pMemoryMan`; IDA still renders the storage as an unknown/raw dword in decompiler output. B009 2026-07-01 accepts the first-draft source declaration because the current xref set is exactly the MemoryMan singleton lifecycle and accessor path, current bytes are zero, and no unrelated feature consumers or neighboring-owner evidence exists.

## Lifecycle

- [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructs the static `MemoryMan` object at `dword_69B3A8` and registers the atexit reset thunk.
- [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) installs the `MemoryMan` vtable and stores `this` into `g_pMemoryMan`.
- [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) loads the static object and jumps to [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), the ordinary MemoryMan destructor/reset body that clears `g_pMemoryMan` without freeing static storage.
- [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) returns `g_pMemoryMan`.
- [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) clears `g_pMemoryMan` in the scalar deleting destructor and optionally frees the object.

## Evidence

- Live IDA MCP decompilation for `0x00516000` writes `dword_69B4FC = this`.
- Live IDA MCP decompilation for `0x00516030` returns `dword_69B4FC`.
- Live IDA MCP decompilation for `0x00516260` clears `dword_69B4FC`.
- Live IDA MCP disassembly for `0x00419f70` and `0x0060c260` confirms the static object initialization and atexit reset path.
- `operator_new` at `0x004f4aa0` and `operator_delete` at `0x004f4ac0` call `GetMemoryMan` before forwarding to allocation/free helpers, so this singleton is part of the global allocation bootstrap path.
- 2026-05-26 IDA MCP `xrefs_to 0x0069b4fc` still ties this storage to the constructor, reset/accessor, and destructor paths, not to a feature module.
- 2026-06-26 B006 MCP session `80de0a67` reconfirmed the exact lifecycle refs: constructor write at `0x00516008`, reset clear at `0x00516016`, accessor read at `0x00516030`, and scalar deleting destructor clear at `0x00516270`. The same pass reconfirmed [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) as a 15-byte (`0x0f`, Verified with `int_convert.py`) class constructor that publishes `this` through this pointer, and [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) as the single caller that passes static object storage `0x0069b3a8`.
- B006 also reconfirmed that vtable `0x0061eb08` has exactly constructor/reset/deleting-destructor refs and that static object storage `0x0069b3a8` has exactly static-initializer and atexit-thunk refs. Those two supporting xref sets keep this pointer inside the MemoryMan lifecycle rather than a caller-owned or feature-owned global.
- `list_globals *MemoryMan*` in the current IDB returned the `MemoryMan` vtable/RTTI family but no recovered symbol for this pointer. That negative evidence is why the exact original global spelling remains a confidence cap even though [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) now legitimately uses the project source-facing `g_pMemoryMan` name in formal constructor C++.
- 2026-06-26 B007 MCP session `80de0a67` reconfirmed the accessor-specific use of this storage: [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) is a six-byte function whose disassembly is `mov eax, dword ptr unk_69B4FC; retn` and whose raw bytes are `a1 fc b4 69 00 c3`. The following bytes are ten `0xcc` bytes, the ignored no-xref return-zero child [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md), and padding before `0x00516050`.
- B007 also reconfirmed that `xrefs_to 0x0069b4fc` remains exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear. `xrefs_to 0x00516030` returns at least 120 code xrefs with `more:true`, and accepted B001 raw PE evidence remains the exact count lead at 612 rel32 callers. Operator-wrapper decompilation/callees show [UID:000196][0x004f4aa0-0x004f4ab4.OperatorNewWrapper](by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md) calling `GetMemoryMan` then `AllocateBufferMemory`, and [UID:000197][0x004f4ac0-0x004f4b00.OperatorDeleteWrapper](by-memory/0x004f4ac0-0x004f4b00.OperatorDeleteWrapper.md) calling `GetMemoryMan` then `FreeBufferMemory`.
- B007 negative symbol/type checks found no recovered `g_pMemoryMan` global, no recovered `GetMemoryMan` symbol, no source-file string, no local `MemoryMan` UDT, and no `MemoryMan` type record. The name `g_pMemoryMan` therefore remains inferred rather than proven original text, but it is now accepted for [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)'s formal accessor C++ because every current xref belongs to the MemoryMan singleton lifecycle/access path.
- 2026-06-26 B009 MCP session `80de0a67` reconfirmed the ordinary destructor clear proof: [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) is the exact 17-byte (`0x11`, Verified with `int_convert.py`) destructor tail whose `mov dword ptr unk_69B4FC, 0` executes at `0x00516016`, followed by `retn` at `0x00516020` and fifteen `0xcc` bytes before the accessor.
- B009 `xrefs_to 0x0069b4fc` again reports the exact lifecycle quartet: constructor write at `0x00516008`, ordinary destructor clear at `0x00516016`, accessor read at `0x00516030`, and scalar deleting destructor clear at `0x00516270`. Current `get_bytes 0x0069b4fc size 4` reads `00 00 00 00` in the IDB view.
- B009 negative symbol/type checks again found no recovered `g_pMemoryMan` global symbol and no local `MemoryMan` UDT/type record. The source-facing name remains inferred, but it is accepted for [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md)'s formal destructor C++ because the destructor's only source-visible effect is this storage clear and every current xref belongs to the MemoryMan lifecycle/access path.

## 2026-07-01 B009 Empty-Emitter Family Implementation

B009 resolves this global page's empty marker with the formal source declaration `static MemoryMan *g_pMemoryMan = NULL;`. The accepted report rechecked current live MCP data: `get_bytes` and `get_int` read `00 00 00 00` / integer `0` at `0x0069b4fc`, and `xrefs_to 0x0069b4fc` returns exactly four refs: constructor write `0x00516008`, ordinary destructor/reset clear `0x00516016`, accessor read `0x00516030`, and scalar deleting destructor clear `0x00516270`. The exact storage page [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md) now carries a no-duplicate marker pointing back here.

This declaration is a first-draft source-facing reconstruction. It does not claim recovered original symbol/linkage proof, and exact original spelling remains a final-audit confidence cap.

## Source Migration Caveats

Keep rewrite work grounded in [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) because this utility island mixes the singleton, static initializer/reset path, operator wrappers, allocation/free/realloc helpers, and copy wrappers.

The B006 constructor callback does not change this global's owner/emitter or blank formal C++ disposition. It narrows the constructor-specific blocker: [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md)'s source body can publish through `g_pMemoryMan` because the pointer role is strongly supported, while this global page still caps confidence for exact declaration spelling and linkage because no original symbol text was recovered.

The B007 accessor callback similarly does not change this global page's metadata or blank formal C++ disposition. It narrows the accessor-specific blocker: [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)'s source body can return `g_pMemoryMan` because the read at `0x00516030` is the only accessor read of this singleton storage, while this global page still preserves the unresolved exact declaration spelling/linkage question.

The B009 destructor callback narrowed the ordinary-destructor blocker: [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md)'s source body can assign `g_pMemoryMan = 0;` because the clear at `0x00516016` is part of the exact MemoryMan lifecycle quartet. The 2026-07-01 B009 empty-emitter callback now also accepts this page's own first-draft declaration while preserving exact original spelling/linkage as a confidence cap.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001V4][MemoryManLayout](by-type/by-struct/MemoryManLayout.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)
- [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md)

## Changes

- 2026-07-01 B009 MemoryMan empty-emitter family implementation:
  - Score changed from `COMPLETION:88`, `CONFIDENCE:86` to `COMPLETION:90`, `CONFIDENCE:90`.
  - Inserted formal singleton pointer declaration `static MemoryMan *g_pMemoryMan = NULL;`.
  - Preserved exact evidence: zero-initialized current bytes at `0x0069b4fc`, constructor write, ordinary destructor clear, accessor read, scalar deleting destructor clear, and no recovered original global symbol.
- 2026-06-26 B009 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:86`; owner/emitter remain [UID:0000L7][MemoryMan](by-file/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md)'s direct clear of storage `0x0069b4fc` at `0x00516016`, the exact lifecycle xref quartet, current zero bytes for the storage, scalar deleting destructor separation, and the absence of a recovered `g_pMemoryMan` symbol or local type record. The source-facing name remains inferred but is accepted for the destructor child C++; this global page keeps declaration spelling/linkage as its confidence cap.
- 2026-06-26 B007 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:86`; owner/emitter remain [UID:0000L7][MemoryMan](by-file/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md)'s direct read from storage `0x0069b4fc`, the exact six-byte body/bytes, the preserved padding/ignored-stub boundary, the exact four storage xrefs, broad accessor caller fanout, operator-wrapper use, and the absence of recovered `g_pMemoryMan`/`GetMemoryMan` symbols or local type records. The source-facing name remains inferred but is accepted for the accessor child C++; this global page keeps declaration spelling/linkage as its confidence cap.
- 2026-06-26 B006 implementation callback:
  - Score remains `COMPLETION:88`, `CONFIDENCE:86`; owner/emitter remain [UID:0000L7][MemoryMan](by-file/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed exact lifecycle refs for storage `0x0069b4fc`, [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md)'s constructor publication of `this`, static initializer caller `0x00419f75`, static object storage `0x0069b3a8`, vtable `0x0061eb08`, and the absence of a recovered `g_pMemoryMan` global symbol. The source-facing name is accepted for constructor C++ because all current evidence ties the pointer to MemoryMan singleton lifetime/access; original declaration spelling remains the reason confidence does not rise.
- 2026-06-16 B001 source-split audit: updated the reset-body link to [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md). The `g_pMemoryMan` lifecycle is unchanged; the destructor/reset body now routes through [UID:00007U][MemoryMan](by-class/MemoryMan.md) while this global remains in [UID:0000L7][MemoryMan](by-file/MemoryMan.md).
- 2026-05-30 completion/confidence review:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and stale caveat text around omitted constructor/accessor lifecycle functions.
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`, exact storage-page link, and corrected source migration caveats.
  - Summary/evidence: exact storage page [UID:0002B0][0x0069b4fc-0x0069b500.g_pMemoryMan](by-memory/0x0069b4fc-0x0069b500.g_pMemoryMan.md), `MemoryMan` file/class docs, and [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md) support the singleton lifecycle and allocator-bootstrap role. Confidence is capped because final original source placement/spelling remains reconstructed.
- 2026-06-05: Marked reconstructable under [UID:0000L7][MemoryMan](by-file/MemoryMan.md). Evidence: live IDA MCP reports four xrefs to `0x0069b4fc`; decompilation confirms constructor `0x00516000`, atexit reset tail `0x0060c260`, accessor `0x00516030`, and scalar deleting destructor `0x00516260` write/clear/read `dword_69B4FC`.
