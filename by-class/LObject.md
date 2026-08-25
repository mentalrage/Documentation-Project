*** UID:00007D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_LOBJECT_H
#define NEXUSTK_UTIL_LOBJECT_H

typedef unsigned int MessageType;

class LObject;
class Message;

struct RuntimeClass
{
    typedef LObject *(*CreateObjectProc)();

    const wchar_t *m_className;
    unsigned int m_objectSize;
    CreateObjectProc m_createObject;
    const RuntimeClass *m_baseClass;

    LObject *CreateObject() const;
    bool IsDerivedFrom(const RuntimeClass *runtimeClass) const;
};

class LObject
{
public:
    static const RuntimeClass s_runtimeClass;

    LObject();
    virtual ~LObject();
    virtual const RuntimeClass *GetRuntimeClass() const;
    virtual void OnChangeMessage(LObject *owner, Message *message);

    bool IsKindOf(const RuntimeClass *runtimeClass) const;
    void RegisterChangeListener(LObject *listener,
                                MessageType messageType,
                                bool allMessages);
    void UnregisterChangeListener(LObject *listener,
                                  MessageType messageType,
                                  bool allMessages);
    void ForwardMessage(Message *message);
};

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# LObject

## Status

- Likely original source: [UID:0000KV][LObject](by-file/LObject.md)
- Confidence: strong for runtime/base-object identity, exact shell child ranges, source file placement, the `OnChangeMessage` callback slot, and the three ChangeMan wrapper methods; medium-high for the neighboring string-method split into [UID:0000OA][StringBase](by-file/StringBase.md).
- Autogen handling: attached to [UID:0000KV][LObject](by-file/LObject.md). The class block declares the confirmed callback and wrapper API, closes the class, then places `[[CHILDREN]]` at namespace scope so the exact child definitions emit outside the declaration.
- Import source file: `LObject.cpp`
- C134 compile closure: the canonical `LObject.h` declaration is protected by `NEXUSTK_UTIL_LOBJECT_H`. The generated dependency graph includes this base through Region, GrafPort, and LanguageMan more than once; the guard preserves one physical class definition and prevents both false `LObject` redefinition and downstream undefined-base cascades without changing ownership or layout.

## Responsibility

`LObject` is the runtime/base-object shell: a constructor that installs the vtable, a const four-field `RuntimeClass` descriptor and accessor, the `IsKindOf`/`CreateObject`/`IsDerivedFrom` runtime API, the two-argument virtual callback `OnChangeMessage(LObject *, Message *)`, one empty ordinary destructor source body, compiler-generated deleting support, and three source wrappers around global `ChangeMan` registration/dispatch. The declaration `virtual ~LObject();` and UID000370 empty definition are the complete human destructor contract. UID000373 is the non-emitting vtable deleting wrapper generated from that contract and the project delete route, not a second source method.

Historical recovered ownership also grouped a large reference-counted string implementation under `LObject`. That string code has real behavior and real IDA-confirmed boundaries, but its first field is used as a character-buffer pointer, not as the same vtable field used by the base-object shell. Treat the string methods as [UID:0000OA][StringBase](by-file/StringBase.md) / string-utility code until layout reconciliation is complete.

## Method Families

| Range | Current names | Assessment |
| --- | --- | --- |
| [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) | `OnChangeMessage(LObject *, Message *)` | Real base callback default body. The `retn 8` shape, ChangeMan dispatch call convention, and derived callback bodies resolve both arguments; 517 vtable references reflect inherited/default reuse and possible identical-body folding. |
| [UID:000198][0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md) | `RegisterChangeListener(LObject *, MessageType, bool)` | Member wrapper that forwards `this` as registration owner and the supplied listener/type/flag to global `ChangeMan`. |
| [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md) | `UnregisterChangeListener(LObject *, MessageType, bool)` | Member wrapper for the matching filtered unregister operation. |
| [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md) | `ForwardMessage(Message *)` | Member wrapper that dispatches a message through global `ChangeMan` using `this` as owner. |
| [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md) | wrapper pair/index container | Non-emitting range/index page that preserves the two registration wrappers, intervening pads, and `ForwardMessage` child without duplicating source. |
| [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md) | constructor | Writes the `LObject` vtable into `this[0]`. |
| [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) | ordinary destructor source anchor | Exact seven-byte body; the vptr store is compiler lowering, 366 inbound cleanup references establish ordinary reuse, and the managed empty `LObject::~LObject()` definition is the sole human body. |
| [UID:000371][0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor](by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md) | `GetRuntimeClass() const` | Exact six-byte definition returning `LObject::s_runtimeClass`; inherited through 489 vtable uses. |
| [UID:000375][0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim](by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md) | `IsKindOf(const RuntimeClass *) const` | Optimized body calls virtual `GetRuntimeClass` and tail-jumps to `RuntimeClass::IsDerivedFrom`. |
| [UID:000373][0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor](by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md) | non-emitting scalar deleting-destructor compiler support | Exact 125-byte vtable-only ABI wrapper. Flag `0x01` selects MemoryMan release; flag `0x04` selects a guarded size/no-free branch. It has no unique source cleanup, no vector-delete mechanics, and no formal output. |
| [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) | `RuntimeClass::CreateObject` and `RuntimeClass::IsDerivedFrom` | Exact optional factory dispatch and base-descriptor walk, separated by four `0xcc` alignment bytes. |
| [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) | ANSI/wide construction, conversion, assignment, allocation, COW, suffix checks | Ref-counted string implementation prefix; now a reviewed non-emitting `StringBase` aggregate/container, not true `LObject` class code. |
| `0x005832f0-0x00584d7e` | release, length/capacity, format, trim, append, find, splice, substring | Later string implementation family; see [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md). |
| `0x004b3400-0x004b3d41` | tree traversal/layout/search helpers | Misattributed; belongs with [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md). |

## Layout Notes

The string-buffer family uses a shared 12-byte header before the character data:

- `refCount` at data pointer minus `0x0c`;
- `length` at data pointer minus `0x08`;
- `capacity` at data pointer minus `0x04`;
- ANSI buffers terminate with one byte; wide buffers terminate with one UTF-16 element.

The string-buffer docs include empty sentinels (`g_emptyAnsiBuffer`, `g_emptyAnsiString`, `g_emptyWideBuffer`, `g_emptyWideString`) and fixed-size pool allocators for 64/128/256/512 byte or character capacities. See [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md) and [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md).

## Open Questions

- Whether the original project used a separate `StringBase.cpp` source file or kept `mystr::StringBase` inline/near `StringUtil.cpp`.
- Whether `SimpleUString` is a typedef/facade over `mystr::StringBase<wchar_t>` or a separate sibling string type.
- Exact declaration ownership for the empty string sentinels and pool globals; current docs place them with string utilities, not the base-object shell.
- Exact original macro and member spelling for the runtime-class facility is unrecoverable. The formal H uses the evidence-backed human `RuntimeClass`, `s_runtimeClass`, `CreateObject`, `IsDerivedFrom`, and `IsKindOf` vocabulary; this is a provenance cap, not an unresolved source blocker.

## Live IDA Evidence

- 2026-06-04 IDA MCP reports exact runtime-shell functions at `0x004f4a80-0x004f4a89`, `0x004f4a90-0x004f4a97`, `0x004f4b10-0x004f4b16`, and `0x004f4b90-0x004f4c0d`; the `0x004f4b20-0x004f4b30` membership shim remains raw bytes, not an IDA function object.
- The constructor and destructor-body stores at `0x004f4a80` and `0x004f4a90`, plus the scalar deleting destructor store at `0x004f4bb8`, are the only IDA xrefs to the `LObject` vtable address `0x0061cf68`.
- The `0x0061cf68` vtable entries are `0x004f4b90` (scalar deleting destructor), `0x004f4b10` (runtime-class accessor), and [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) (default no-op virtual), followed by the next class's RTTI pointer at `0x0061cf74`.
- The ChangeMan dispatch loop loads owner and listener as `LObject *`, then invokes vtable slot `+8` with `(owner, message)`. That slot is the same `0x0041b6c0` default body in the base vtable and is overridden by source-authored derived `OnChangeMessage` implementations.
- The wrappers at `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` use `this` as the ChangeMan owner. Their exact argument flow establishes `LObject *listener`, `MessageType`, `bool`, and `Message *` source types; false Application ownership came from inherited call sites, not from wrapper implementation ownership.
- 2026-06-19 B005 source-quality pass confirms [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) as the direct class-owned/emitted default no-op virtual: exact bytes `C2 08 00` / `retn 8`, SHA1 `a4f5248d9b7df8d573608c34e4228e45f2367748`, no callees, no direct code callers, 517 `DATA_OFFSET` vtable refs, base `LObject` vtable slot at `0x0061cf70`, and descriptive source shape `void LObject::VirtualNoop(int, int)`. The 517 derived/feature refs are inherited/default slot reuse and possible identical-empty-body folding, not evidence for feature ownership or per-class duplicate source emission.
- The runtime-class record at `0x0061cf44` points to the wide string `LObject`, records size `4`, and is referenced only by the `0x004f4b10` accessor.
- The record is exactly four dwords: class-name pointer, object size, optional create callback, and base descriptor. It occupies read-only `.rdata`, has no writes, and is emitted as `static const RuntimeClass s_runtimeClass`.
- A complete ordinary/generated source and live IDA audit found no derived `GetRuntimeClass` implementation. Pane's redundant declaration is removed; all derived tables inherit `0x004f4b10`, so the const base signature is compile-consistent repository-wide.
- 2026-07-15 B004 target-specific reanalysis confirms UID000373's exact 125-byte SHA-256 `4CC926D8C6805AB575B009BA7B4B8162C0B44ECF3991D9558318C2BBB26B0891`, one inbound vtable-data reference, no ordinary/pointer route, and no field/base/resource cleanup. UID000370 is exact bytes `C7 01 68 CF 61 00 C3`, SHA-256 `7C2D427E3C2FE8AF5F5F264CEEDAB8F33D0E4E8B8A157D3E3BDC642443DC7DAA`, with 366 inbound cleanup references. These controls close the destructor source/compiler split without changing the complete class block.
- UID000373's flag-`0x04` callee at `0x0041b6a0` is a one-byte no-op reached with object size `4`; no element count, stride, loop, cookie, repeated destructor, or array free exists. Historical generic vector-delete/proof-comment wording is superseded, while its history remains recorded on the target and aggregate pages.
- The raw `0x004f4b20` membership shim calls vtable slot `+4` and tail-jumps to [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), whose live disassembly walks the runtime-class base chain through offset `+0x0c`; the sibling `0x005568d0` helper jumps through optional callback pointer `+0x8`.
- IDA xrefs for the string helpers (`0x00582500`, `0x00582d80`, `0x00583210`, `0x00583280`, `0x005832f0`, `0x00583720`, `0x00583840`, `0x005845b0`) are ordinary string/format/copy-on-write callers and do not use the `LObject` vtable/runtime-class shell.
- IDA xrefs for `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` all come from the local FolderTreePane helper cluster, supporting their exclusion from `LObject`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 93 | The class page records the exact runtime shell, complete four-field RuntimeClass API, static descriptor, const accessor, IsKindOf/helper methods, callback and wrappers, destructor/compiler split, vtable/RTTI regeneration, string-family split, and namespace-scope child routing. |
| Confidence | 93 | Live instruction, descriptor, vtable, caller, RTTI, destructor-source, and override-audit evidence agree. The cap preserves inferred original macro/member spellings rather than treating them as recovered symbols. |
| Reconstructable | true | The accepted declaration is source-authored and structurally safe: the class closes before `[[CHILDREN]]`, while exact member bodies remain in their child pages. |

## Cross-References

- [UID:0000KV][LObject](by-file/LObject.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md)
- [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md)
- [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md)
- [UID:000371][0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor](by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md)
- [UID:000375][0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim](by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md)
- [UID:000373][0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor](by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md)
- [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md)
- [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md)
- [UID:000198][0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md)
- [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md)
- [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md)
- [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md)
- [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## 2026-07-29 UID0002MZ Header Dependency Reconciliation

- The complete `LObject` declaration now emits through formal H while constructor, ordinary-destructor, runtime-class, listener, message-forwarding, and other method definitions remain in formal CPP children. This provides a complete base before [UID:0000F9][Tree_struct_FolderTreePane__TreeElem_](by-class/Tree_struct_FolderTreePane__TreeElem_.md) declares `Tree<T> : public LObject` in the shared [UID:0004YK][Tree](by-file/Tree.md) header route.
- Layout and runtime behavior are unchanged. The relocation is source-topology work: the prior CPP-only class declaration is retained as superseded reconstruction history, not discarded evidence.
- Score, owner, emitter, and reconstructability remain `90/92`, [UID:0000KV][LObject](by-file/LObject.md), and true. Generated `LObject.h`/dependent compile readback remains a later supervisor closure gate rather than an implementation claim here.

## Historical Assumption Superseded By UID0002MZ

- Earlier reconstruction placed the full class declaration in the CPP channel. That shape could describe behavior but could not legally provide the complete base required before a shared header declares `Tree<T> : public LObject`; the accepted H/CPP split supersedes only that placement assumption.

## Changes

- 2026-08-01 Agent-B004 UID0003OO support callback:
  - Raised `90/92 -> 93/93` and replaced the forward-only RuntimeClass surface with the exact `0x10` four-field declaration, `LObject::s_runtimeClass`, const virtual accessor, and `IsKindOf` API.
  - Preserved the listener/message surface and namespace-scope `[[CHILDREN]]` placement. Added descriptor/helper ownership, no-derived-override closure, constness, and exact source/compiler regeneration responsibilities.
- 2026-07-15 Agent-B004 UID000373 callback:
  - Score, owner/emitter, reconstructable state, and exact complete managed class block remain unchanged at `90/92`, UID0000KV, true.
  - Added the exact UID000370 ordinary-source versus UID000373 compiler-wrapper distinction, 7/125-byte hashes, 366-versus-one-reference liveness, no-vector proof, and blank target-emission decision while preserving all unrelated runtime, callback, wrapper, and string-family content.
- 2026-07-13 Agent-B003 UID0000ZW callback:
  - Changed `86/87` to `90/92` and supplied the accepted managed class declaration.
  - Reclassified the two-argument base virtual as `OnChangeMessage(LObject *, Message *)` from the ChangeMan dispatch ABI and confirmed derived overrides; retained broad vtable reuse/identical-body folding as compiler history.
  - Added the three UID-preserving, validator-renamed LObject wrapper children and their non-emitting pair/index page. Exact wrapper flow proves LObject ownership, `MessageType`, `bool`, and `Message *`; inherited Application call sites do not own these definitions.
  - Preserved the independent runtime-class naming and string-family split questions. `[[CHILDREN]]` is deliberately after the complete class `};`, so emitted child definitions remain at namespace scope.

- 2026-06-20 B004 support update:
  - Changed support wording only; score unchanged.
  - Summary/evidence: [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) was renamed to [0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) and reclassified as a reviewed non-emitting StringBase aggregate. This preserves the class decision that the true `LObject` runtime shell is separate from the ref-counted string-buffer family.
- Completion/confidence score update: existed before as `0/0`; changed to `78/76`. Summary: the page had documented evidence to remove it from unevaluated work, with strong base-object and string-buffer family mapping but capped confidence because recovered ownership was still polluted. Evidence: documented runtime shell, no-op virtual, string construction/COW ranges, string mutation range, buffer header layout, sentinel/pool globals, and FolderTreePane misattribution.
- 2026-06-01: Added runtime-class callback/membership helper evidence from the low-score by-memory pass.
  - Evidence: IDA MCP disassembly shows the `0x004f4b20` shim calls vtable slot `+4` and tail-jumps to [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md), where raw helpers call a create/callback pointer at `+0x8` and walk a base-list chain through `+0x0c`.
- 2026-06-04 live IDA refinement:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:76`, reconstructability/parent fields blank, and the confidence cap was described in terms of recovered-owner pollution.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000KV`, while keeping C++ blank.
  - Summary/evidence: live IDA MCP now records exact runtime-shell functions, the raw membership shim and helper island, the `0x0061cf68` vtable entries/xrefs, the `0x0061cf44` runtime-class record, separate string-helper caller patterns, and FolderTreePane-only false-owner xrefs. The score rises because the source file placement and class identity are now current IDA-backed, but it remains capped by unresolved final declarations and string utility split details.
- 2026-06-11 Agent-A001 Batch 158 exact-child split:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:84`, and the runtime shell was referenced mostly through the mixed aggregate page.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`; added exact child pages for the constructor, destructor body, runtime-class accessor, raw membership shim, and scalar deleting destructor. The child pages attach directly to this class after both the children and parent clear the strict 85/85 gate.
  - Summary/evidence: live IDA MCP reconfirmed the exact shell function boundaries, vtable writes at `0x004f4a80`, `0x004f4a90`, and `0x004f4bb8`, unique `0x0061cf44` runtime-class accessor xref, and raw `0x004f4b20` tail-jump shim. Final C++ remains blank because source-facing runtime-class helper declarations and string-family boundaries are not yet final-audit quality.
- 2026-06-19 B005 support update:
  - Changed support wording without changing the class score.
  - Summary/evidence: [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) is now `88/91`, direct owner/emitter [UID:00007D], and emits first-draft `void LObject::VirtualNoop(int, int) {}`. The support page records the accepted descriptive-name policy, two-argument `retn 8` source shape, broad vtable reuse caveat, rejected feature/no-owner/per-class duplicate alternatives, and retained class-level declaration blockers.
## FolderSelectDialog Shared RTTI Dependencies R11/R17

These existing LObject-owned compiler RTTI records are reached from the FolderSelectDialog base array. The shared edge does not transfer ownership or authorize handwritten RTTI data.

| ID | Exact record and fields | Exact xrefs | Ownership boundary |
| --- | --- | --- | --- |
| R11 | `0x640348-0x640364` BCD: TD `0x6738c0`, contained `0`, PMD `0/-1/0`, attrs `0x40`, CHD `0x640364` | `xref_query.total=481`; FolderSelectDialog graph edge `0x647840`; outgoing TD `0x6738c0` and CHD `0x640364` | LObject-owned compiler RTTI; FolderSelectDialog only references it. |
| R17 | `0x6738c0-0x6738d8` TypeDescriptor `??_R0?AVLObject@@@8`: vfptr `0x635078`, spare `0`, decorated `.?AVLObject@@` | `xref_query.total=3`, including BCD edge `0x640348`; outgoing vfptr `0x635078` | LObject-owned shared TypeDescriptor; no FolderSelectDialog CPP/H storage. |
