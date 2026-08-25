*** UID:0001V4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// MemoryMan's source class declaration is emitted on [UID:00007U][MemoryMan](by-class/MemoryMan.md).
// This page documents the observed 4-byte one-vptr binary layout and must
// not emit a duplicate struct/class declaration.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MemoryManLayout

## Status

- Confidence: very strong for observed binary size, vtable field, singleton storage, static-object lifecycle, and allocation-helper separation; medium-high for whether additional source-only members existed.
- Likely owner header: `util/MemoryMan.h`
- Related class: [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- Autogen parent: attached to [UID:00007U][MemoryMan](by-class/MemoryMan.md); after the B009 empty-emitter implementation the class scores `91/91`, the owning file scores `91/89`, and this layout scores `89/91`, so the direct class and file support clear the strict gate. The formal block is a no-duplicate marker because the source declaration emits on the class page.

## Layout

Current binary layout is minimal:

```text
MemoryMan
  +0x00  MemoryMan vptr
```

Observed size: `4` bytes.

The process-global static object storage is `dword_69B3A8` / `0x0069b3a8`. Live IDA shows [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) constructing that storage and registering an atexit reset thunk at [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md). The singleton pointer [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) lives at `0x0069b4fc`.

## Evidence Notes

- IDA `list_globals *MemoryMan*` reports `??_7MemoryMan@@6B@` at `0x0061eb08` and RTTI complete-object locator `??_R4MemoryMan@@6B@` at `0x0064b5bc`.
- IDA `get_u32` shows `0x0061eb04 -> 0x0064b5bc`, `0x0061eb08 -> 0x00516260`, and `0x0061eb0c` begins the next RTTI pointer, so the binary vtable has one confirmed slot: the scalar deleting destructor.
- IDA decompile for [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) writes `MemoryMan::vftable` to `this + 0x00` and stores `this` into `dword_69B4FC`.
- IDA decompile for [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) writes the same vtable to `dword_69B3A8` and clears `dword_69B4FC`.
- IDA decompile for [UID:0001BJ][0x00516260-0x0051628e.MemoryManScalarDeletingDestructor](by-memory/0x00516260-0x0051628e.MemoryManScalarDeletingDestructor.md) writes the same vtable to `this + 0x00`, clears `dword_69B4FC`, and conditionally deletes `this`.
- IDA `xrefs_to 0x0069b3a8` lands only in the static initializer and reset thunk/tail; `xrefs_to 0x0069b4fc` lands in constructor, reset tail, accessor, and scalar deleting destructor.
- Allocation policy state is not stored in the object in current evidence; the helper family wraps CRT allocation calls directly.
- `source-3/simroot_v2/class_MemoryMan.meta_wave3` is consistent with the 4-byte one-vptr layout, but is only a generated lead. The IDA evidence above is the authority for the score.

## 2026-06-16 A001 Evidence Refresh

- Live IDA MCP database `b001_mappane_0001AW_20260616` reconfirmed the constructor at `0x00516000` size `0x0f`, `GetMemoryMan` at `0x00516030` size `0x06`, allocation/free/copy helpers through `0x00516050-0x00516258`, the scalar deleting destructor at `0x00516260` size `0x2e`, and the neighboring menu-pane function start at `0x00516290`.
- Querying `0x00516010` resolves to the `0x0060c260` atexit thunk chunk, matching the documented reset-tail model rather than an ordinary independent method. Decompilation of `0x0060c260` writes the [UID:00007U][MemoryMan](by-class/MemoryMan.md) vtable to `0x0069b3a8` and clears [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md) / `0x0069b4fc`.
- Constructor decompilation writes `MemoryMan::vftable` at `this + 0x00` and publishes `this` to `0x0069b4fc`; the scalar deleting destructor decompilation restores the same vtable, clears `0x0069b4fc`, conditionally deletes `this`, and touches no other object fields.
- `xrefs_to` and the section-mapped PE scan agree on the lifecycle: `0x0061eb08` has exactly constructor/reset/destructor refs, `0x0069b3a8` has exactly static-initializer and atexit-reset refs, and `0x0069b4fc` has exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear refs. The PE scan also found 612 rel32 calls to `GetMemoryMan`, confirming allocator policy is routed through the global accessor rather than stored as fields inside the object.
- `search_structs` for `MemoryMan` returned no local IDA struct/type record. This supports the 4-byte binary layout but does not prove whether the original header had source-only declarations, inline wrappers, or comments around the global operator/copy helpers.
- B001 2026-06-16 source-split audit confirms the constructor and ordinary destructor route through [UID:00007U][MemoryMan](by-class/MemoryMan.md); `0x00516040-0x00516045` is ignored no-xref stub [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) and does not imply an extra `MemoryMan` field or method.

## 2026-06-26 B006 Constructor Layout Check

B006 current MCP session `80de0a67` reconfirmed the layout facts that matter to [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md):

- The constructor is a 15-byte (`0x0f`, Verified with `int_convert.py`) class lifecycle body that stores the `MemoryMan` vptr at object offset `+0x00`, publishes `this` to singleton pointer storage `0x0069b4fc`, and returns through the constructor ABI.
- The constructor has exactly one code xref, from [UID:0000WA][0x00419f70-0x00419f86.MemoryManStaticInitializer](by-memory/0x00419f70-0x00419f86.MemoryManStaticInitializer.md) at `0x00419f75`, where static object storage `0x0069b3a8` is passed as `this`.
- Vtable `0x0061eb08` still has exactly constructor, ordinary reset/destructor, and scalar deleting destructor refs; static object storage `0x0069b3a8` still has exactly static-initializer and atexit-thunk refs; singleton pointer storage `0x0069b4fc` still has exactly constructor write, reset clear, accessor read, and scalar deleting destructor clear refs.
- Current MCP `list_globals` returns the `MemoryMan` vtable/RTTI family but no recovered global symbol for [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md); `search_structs MemoryMan` and `type_query *MemoryMan*` still return no local IDA UDT/type record.
- No allocation-policy state is observed inside the 4-byte object. The allocator policy still routes through [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md) and nearby file-level helpers rather than through fields on `MemoryMan`.

These facts preserve the one-vptr binary layout and also explain why [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) can now emit constructor method-body C++: the source body does not need an exact static-object variable name and does not need a recovered IDA UDT. The remaining open header question is source-only declaration shape, not the observed binary layout or constructor behavior.

## 2026-06-26 B009 Destructor Layout Check

B009 current MCP session `80de0a67` reconfirmed the layout facts that matter to [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md):

- The ordinary destructor/reset tail is exactly 17 bytes (`0x11`, Verified with `int_convert.py`) at `0x00516010-0x00516021`, reached only after [UID:0001O7][0x0060c260-0x0060c26a.MemoryManAtexitResetThunk](by-memory/0x0060c260-0x0060c26a.MemoryManAtexitResetThunk.md) loads static storage `0x0069b3a8` / `g_staticMemoryManObject` as `this` in `ecx`.
- The target writes the `MemoryMan` vptr at object offset `+0x00` through `mov dword ptr [ecx], offset ??_7MemoryMan@@6B@`, clears singleton pointer storage `0x0069b4fc` / `g_pMemoryMan` at `0x00516016`, and returns at `0x00516020`.
- The destructor does not read or write any additional object offsets. It adds no observed fields beyond the one vptr already documented for the four-byte binary layout.
- Current xrefs remain layout-local lifecycle evidence: vtable `0x0061eb08` has constructor, ordinary destructor, and scalar deleting destructor refs; static object storage `0x0069b3a8` has static-initializer and atexit-thunk refs; `g_pMemoryMan` has constructor write, ordinary destructor clear, accessor read, and scalar deleting destructor clear refs.
- `search_structs MemoryMan` and `type_query *MemoryMan*` still return no local IDA UDT/type record. The accepted destructor C++ on [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md) is therefore a method-body decision, not a new recovered layout/type declaration.

## 2026-06-26 B009 MoveBufferMemory Layout Check

B009 current MCP session `80de0a67` resolves [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as the nonvirtual `MemoryMan::MoveBufferMemory(void *destination, const void *source, size_t size)` method body without adding any observed object fields:

- The target is the exact 24-byte (`0x18`, Verified with `int_convert.py`) wrapper at `0x00516240-0x00516258`, with eight `0xcc` padding bytes at `0x00516258-0x00516260`.
- The body pushes the three explicit buffer arguments, calls internal `_memmove_0` at `0x005c9b30`, adjusts the stack by `0x0c` / 12 bytes (Verified with `int_convert.py`), and returns with `retn 0Ch`.
- Representative callers obtain [UID:0001BC][0x00516030-0x00516036.GetMemoryMan](by-memory/0x00516030-0x00516036.GetMemoryMan.md), move or reload the singleton into `ECX`, push destination/source/size, and call `0x00516240`. The method's implicit `this` is supplied by caller convention but remains unused by the body.
- No instruction reads or writes an offset other than the implicit unused `this` receiver. The method therefore contributes no new fields beyond the existing one-vptr four-byte binary layout.
- [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) is already B006-accepted as sibling method `MemoryMan::MemmoveWrapper`; [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) is now the semantic overlap/tail-move sibling `MemoryMan::MoveBufferMemory`. Future method-name unification should preserve this no-new-field result and the distinct exact child ranges.

## Open Questions

- Whether the original source used `MemoryMan` as a nominal manager class with most behavior in free/static helper functions, or whether optimization removed source-level members.
- Exact recovered header spelling and whether a future name-unification pass should rename `MemoryMan::MemmoveWrapper` / `MemoryMan::MoveBufferMemory`. The direct MemoryMan placement for both exact copy/move wrappers is no longer open: [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) is B006-accepted as `MemoryMan::MemmoveWrapper`, and [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) is B009-accepted as `MemoryMan::MoveBufferMemory`; neither method adds fields to the one-vptr binary layout.

## 2026-07-01 B009 Empty-Emitter Family Implementation

B009 resolves the layout empty marker with a formal no-duplicate marker. The accepted report rechecked that the observed binary layout is still a four-byte one-vptr object, with vtable `0x0061eb08`, static object storage `0x0069b3a8`, singleton pointer storage `0x0069b4fc`, and no recovered IDA UDT/type record or allocation-policy fields. Source class declaration/prototypes now emit on [UID:00007U][MemoryMan](by-class/MemoryMan.md), so this layout page should document the exact binary shape and must not emit a second `struct` or `class` declaration.

## Cross-References

- [UID:0000L7][MemoryMan](by-file/MemoryMan.md)
- [UID:00007U][MemoryMan](by-class/MemoryMan.md)
- [UID:0000RH][g_pMemoryMan](by-global/g_pMemoryMan.md)
- [UID:0000T8][MemoryAllocationHelpers](by-global/MemoryAllocationHelpers.md)
- [UID:0001BA][0x00516000-0x0051628e.MemoryManAndAllocationHelpers](by-memory/0x00516000-0x0051628e.MemoryManAndAllocationHelpers.md)

## Changes

- 2026-07-01 B009 MemoryMan empty-emitter family implementation:
  - Score changed from `COMPLETION:86`, `CONFIDENCE:90` to `COMPLETION:89`, `CONFIDENCE:91`.
  - Inserted a formal no-duplicate marker pointing to [UID:00007U][MemoryMan](by-class/MemoryMan.md) for the source class declaration.
  - Preserved exact layout evidence: 4-byte one-vptr object, vtable `0x0061eb08`, static object storage `0x0069b3a8`, singleton pointer storage `0x0069b4fc`, and no recovered extra fields or UDT.
- 2026-06-26 B009 Memmove0Wrapper implementation callback:
  - Score remains `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter remain [UID:00007U][MemoryMan](by-class/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` resolves [UID:0001BI][0x00516240-0x00516258.Memmove0Wrapper](by-memory/0x00516240-0x00516258.Memmove0Wrapper.md) as `MemoryMan::MoveBufferMemory(void *destination, const void *source, size_t size)`. The exact 24-byte wrapper calls internal `_memmove_0`, returns with `retn 0Ch`, has 19 direct callers, and representative callers pass the MemoryMan singleton in `ECX`; because the body never reads or writes object offsets, it adds no fields beyond the existing vptr-only layout. B006's [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md) sibling remains the accepted `MemoryMan::MemmoveWrapper` method.
- 2026-06-26 B009 implementation callback:
  - Score remains `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter remain [UID:00007U][MemoryMan](by-class/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md)'s ordinary destructor writes only the vptr at `+0x00`, clears `g_pMemoryMan`, returns before fifteen bytes of padding, and adds no observed fields. Vtable/static-object/global xrefs and the absence of a local `MemoryMan` UDT/type record preserve the one-vptr layout and keep source-only declaration shape as the remaining confidence cap.
- 2026-06-26 B006 implementation callback:
  - Score remains `COMPLETION:86`, `CONFIDENCE:90`; owner/emitter remain [UID:00007U][MemoryMan](by-class/MemoryMan.md); formal C++ remains blank.
  - Summary/evidence: current MCP session `80de0a67` reconfirmed [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md)'s constructor vptr store at `+0x00`, 15-byte size, static-initializer caller `0x00419f75`, static object storage `0x0069b3a8`, vtable `0x0061eb08`, singleton pointer `0x0069b4fc`, no local `MemoryMan` UDT/type record, and no observed allocation-policy fields. The accepted constructor C++ on [UID:0001B9][0x00516000-0x0051600f.MemoryManConstructor](by-memory/0x00516000-0x0051600f.MemoryManConstructor.md) is not blocked by the source-only header/member question; that question remains a layout/header confidence cap.
- 2026-06-16 B001 source-split audit: updated the ordinary destructor/reset link to [UID:0001BB][0x00516010-0x00516021.MemoryManDestructor](by-memory/0x00516010-0x00516021.MemoryManDestructor.md), confirmed constructor/destructor class routing through [UID:00007U][MemoryMan](by-class/MemoryMan.md), and excluded no-xref stub [UID:0003VP][0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub](by-memory/0x00516040-0x00516045.MemoryManNoXrefReturnZeroStub.md) from the layout.
- 2026-06-16 A001 layout evidence refresh: Raised completion/confidence from `84/88` to `86/90`.
  - Before: the layout page lagged behind the 2026-06-15 MemoryMan constructor/reset/destructor/static-storage support pages.
  - After: synced the current parent scores, added live IDA constructor/reset/destructor/accessor evidence, added section-mapped PE reachability counts, and recorded the negative local-type search and remaining source-only-member/global-operator split caveat.
  - Evidence: live IDA `lookup_funcs`, `decompile`, `xrefs_to`, `get_bytes`, `search_structs`, current MemoryMan support docs, and the read-only PE scan.
- 2026-06-06: Attached the static singleton layout to [UID:00007U][MemoryMan](by-class/MemoryMan.md). Scores remain `84/88`; this parent sync follows the already documented one-vptr object and class ownership.
- Completion/confidence metadata:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and blank `RECONSTRUCTABLE`.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA confirms a 4-byte one-vptr `MemoryMan` static singleton object, one-slot vtable, constructor/reset/destructor writes, static storage at `0x0069b3a8`, singleton pointer at `0x0069b4fc`, and no observed allocation-policy fields inside the object. Parent UID and C++ reconstruction remain blank because final source shape is below the `95+` final-source gate.
