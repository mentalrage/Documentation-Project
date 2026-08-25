*** UID:0000KV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# LObject

## Status

- Proposed module: `util/LObject.cpp`
- Proposed header: `util/LObject.h`
- Confidence: strong for the runtime/base-object source, exact shell/callback/wrapper child ranges, and `NexusTK/util/` placement; medium-high for the neighboring [UID:0000OA][StringBase](by-file/StringBase.md) source-file split.
- Primary class: [UID:00007D][LObject](by-class/LObject.md)
- Evidence basis: live IDA MCP boundary, vtable, runtime-class, xref, caller checks, and B005 2026-06-19 source-quality evidence for the default no-op virtual through [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md).

## File Role

Historical recovered ownership is not a clean original-source unit. Current IDA evidence separates three implementation families that were previously grouped under the `LObject` owner:

- a virtual/runtime shell around `0x004f4a80-0x004f4c0d`, including the three ChangeMan member wrappers at `0x004f4b30-0x004f4b86` and the inherited two-argument `OnChangeMessage` callback;
- a reference-counted ANSI/UTF-16 copy-on-write string buffer implementation starting at `0x00582500`;
- folder-tree traversal callbacks at `0x004b3400-0x004b3d41` that are already documented as [UID:0000JG][FolderTreePane](by-file/FolderTreePane.md) helpers.

For source reconstruction, keep `util/LObject.cpp` as the owner candidate for the true base/runtime shell only. The string-buffer family should move to the [UID:0000OA][StringBase](by-file/StringBase.md) / [UID:0000OB][StringUtil](by-file/StringUtil.md) utility-string family. The folder-tree helpers should not migrate with `LObject.cpp`.

## Likely Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `LObject::OnChangeMessage(LObject *, Message *)` | [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) | Base no-op callback resolved by ChangeMan dispatch ABI and derived overrides; the 517 vtable references remain inherited/default reuse and possible identical-body folding. |
| `LObject::LObject` | [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md) | Sets the `LObject` vtable. |
| `LObject::~LObject` body | [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) | Sole human destructor definition. Exact seven-byte binary body only restores the vptr as compiler lowering; 366 inbound cleanup references establish the ordinary source anchor. |
| `LObject::RegisterChangeListener` | [UID:000198][0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md) | Exact member wrapper around `ChangeMan::Register(this, listener, messageType, allMessages)`. |
| `LObject::UnregisterChangeListener` | [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md) | Exact member wrapper around filtered ChangeMan unregister. |
| `LObject::ForwardMessage` | [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md) | Exact member wrapper around ChangeMan dispatch with `this` as owner. |
| `LObject::GetRuntimeClass` | [UID:000371][0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor](by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md) | Returns the `0x0061cf44` runtime-class record. |
| runtime-class membership shim/helpers | [UID:000375][0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim](by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md), [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) | Calls vtable slot `+4`, checks runtime-class base-chain membership through offset `+0x0c`, and invokes an optional callback/create pointer at `+0x8`; final declaration owner/name remains open. |
| scalar deleting-destructor compiler support | [UID:000373][0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor](by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md) | Non-emitting 125-byte vtable ABI wrapper generated from `virtual ~LObject()` and project deletion support. Flag `0x01` uses MemoryMan release; flag `0x04` is guarded size/no-free handling, not a source method or vector-delete body. |
| string-buffer helpers | [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) and `0x005832f0+` | ANSI/wide constructors, assign, release, format, append, find, splice, and substring helpers formerly grouped under `LObject`; preferred source owner is [UID:0000OA][StringBase](by-file/StringBase.md). The `0001J1` prefix is now a reviewed non-emitting container, not an `LObject` source item. |
| empty string and pool globals | `0x00670278`, `0x00670290`, `0x0069bacc-0x0069bbe4` | Shared sentinels and bucket allocators for the ref-counted string implementation. |

## Source-Structure Decision

Use `util/LObject.cpp` only as the home for the base-object/runtime-class surface. Do not bulk-migrate the broader recovered owner as-is: the string-family and FolderTreePane evidence have stronger owners elsewhere.

The current working model is:

- `util/LObject.cpp`: real base `LObject` constructor/runtime/destructor shell, `OnChangeMessage` default body, and ChangeMan member wrappers.
- Destructor boundary: `util/LObject.h` declares `virtual ~LObject();` and UID000370 emits the sole empty `LObject::~LObject()` definition. UID000373 has no standalone source placement, declaration, marker, or body; compiler/toolchain output supplies the deleting vtable entry.
- `util/StringBase.cpp`: preferred owner for the ref-counted ANSI/UTF-16 string implementation and shared string-buffer globals.
- `util/PoolAllocator.cpp`: fixed-size block pool mechanics used by the small string-buffer buckets.
- `ui/controls/FolderTreePane.cpp`: tree traversal callbacks and helper cluster currently misattributed to `LObject`.

[UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) is class-owned by [UID:00007D][LObject](by-class/LObject.md), not file-owned, but its generated `OnChangeMessage` body belongs in this `NexusTK/util/LObject.cpp` route. The three UID-preserving wrapper pages are also class-owned children routed here; their former Application names are historical false ownership derived from inherited call sites.

## Owner-Split Caveats

- The string methods use the first field as a data pointer, not a vtable, even though older recovered names describe it as `vftptr_0x0` or `m_vtable`.
- Methods at `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` are FolderTreePane traversal/search callbacks by caller evidence.
- 2026-06-01 IDA MCP disassembly of `0x004f4b20` and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) confirms a runtime-class membership shim/helper relationship, but final source declaration placement remains open because the `LObject` page still has polluted string ownership.

## Live IDA Evidence

- 2026-06-04 IDA MCP reports exact base/runtime functions at `0x004f4a80-0x004f4a89`, `0x004f4a90-0x004f4a97`, `0x004f4b10-0x004f4b16`, and `0x004f4b90-0x004f4c0d`, plus the exact [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) at `0x0041b6c0-0x0041b6c3`.
- The `LObject` vtable at `0x0061cf68` contains the scalar deleting destructor, runtime-class accessor, and default no-op virtual. Its only xrefs are the constructor store, destructor-body store, and scalar deleting destructor reset inside the runtime shell.
- ChangeMan dispatch invokes the vtable `+8` callback as `(owner, message)`, which resolves the default slot as `OnChangeMessage(LObject *, Message *)`; confirmed AboveFrame, FramePartPane, and MapPane overrides independently use the same ABI.
- `0x004f4b30`, `0x004f4b50`, and `0x004f4b70` forward `this` to ChangeMan as the owner. The register/unregister pair preserves `LObject *listener`, `MessageType`, and `bool`; the dispatch wrapper preserves `Message *`.
- 2026-06-19 B005 source-quality pass confirms [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) as descriptive `LObject::VirtualNoop(int, int)`: exact `.text` bytes `C2 08 00` / `retn 8`, raw offset `0x1aac0`, SHA1 `a4f5248d9b7df8d573608c34e4228e45f2367748`, thirteen-byte `0xcc` padding before and after, no callees, no direct code callers, 517 `DATA_OFFSET` vtable refs, and base `LObject` vtable slot `0x0061cf70`. The file remains the route for generated `LObject.cpp`, while direct semantic ownership/emission is the class page.
- The runtime-class record at `0x0061cf44` is returned only by `0x004f4b10`; its first dword points at the `LObject` string and its size dword is `4`, matching the one-vptr base shell.
- 2026-07-15 B004 live target reanalysis records UID000373 as one exact 125-byte function, SHA-256 `4CC926D8C6805AB575B009BA7B4B8162C0B44ECF3991D9558318C2BBB26B0891`, with one inbound vtable reference and no ordinary/pointer route. It repeats UID000370's vptr lowering, then adds hidden deleting flags, return-this ABI, MemoryMan release, a one-byte guarded size/no-free branch, and compiler SEH/security-cookie scaffolding. No unique human cleanup or array mechanics exist.
- UID000370 is exact bytes `C7 01 68 CF 61 00 C3`, SHA-256 `7C2D427E3C2FE8AF5F5F264CEEDAB8F33D0E4E8B8A157D3E3BDC642443DC7DAA`, with 366 inbound cleanup references. Current generated-source expectation is one class and one UID000370 destructor definition, with zero UID000373 marker/body/Empty Emitter Marker and no handwritten vptr/flags/guard/MemoryMan ABI.
- The raw runtime-class shim `0x004f4b20-0x004f4b30` is not an IDA function object; disassembly shows it calls vtable slot `+4` and tail-jumps to the [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) at `0x005568e0`.
- IDA function/xref checks keep `0x00582500+` string routines with [UID:0000OA][StringBase](by-file/StringBase.md): representative functions include `0x00582500-0x00582552`, `0x00582d80-0x00582e2c`, `0x00583210-0x00583273`, `0x00583280-0x005832e3`, `0x00583720-0x00583832`, `0x00583840-0x00583968`, and `0x005845b0-0x005845ec`.
- IDA function/xref checks keep `0x004b3400`, `0x004b3650`, `0x004b3850`, and `0x004b3af0` with the local FolderTreePane helper cluster rather than `LObject`.

## RuntimeClass Source Inventory

The `NexusTK/util/LObject` source route now includes the complete runtime-class facility needed to regenerate the observed code and read-only data:

| UID / range | Source role | Binary/source disposition |
| --- | --- | --- |
| UID0003ON, `0x0061cf44-0x0061cf68` | `const RuntimeClass LObject::s_runtimeClass` | Four-field descriptor, UTF-16 `LObject`, and LObject COL tail; descriptor/name are source-declared, RTTI is compiler-generated. |
| UID000371, `0x004f4b10-0x004f4b16` | `LObject::GetRuntimeClass() const` | Exact source definition returning `&s_runtimeClass`; inherited through 489 table uses. |
| UID00023R, `0x005568d0-0x00556907` | `RuntimeClass::CreateObject` and `RuntimeClass::IsDerivedFrom` | Optional factory dispatch and base-descriptor traversal with internal `0xcc` alignment. |
| UID000375, `0x004f4b20-0x004f4b30` | `LObject::IsKindOf` | Human source method whose optimized body calls the virtual accessor and tail-jumps into `IsDerivedFrom`. |
| UID0003OO, `0x0061cf68-0x0061cf74` | LObject primary vtable | Compiler-generated from the virtual destructor, const accessor, and `OnChangeMessage`; no raw table array. |
| UID000373 | scalar deleting support | Compiler-generated/non-emitting; regenerated from the virtual destructor and project delete route. |

The corresponding header route is [UID:00007D][LObject](by-class/LObject.md): a `0x10` four-field `RuntimeClass`, static const descriptor, const accessor, `IsKindOf`, callback, and ChangeMan wrapper declarations. Constructor UID00036Z, ordinary destructor UID000370, default callback UID0000WM, and the listener/message child definitions remain in their existing source-owned pages.

Source placement is therefore one coherent `LObject.h`/`LObject.cpp` utility module. A separate `RuntimeClass.cpp`, raw vtable/COL arrays, handwritten scalar deleting wrapper, or LogoPane ownership is not supported. Exact original macro/member spelling remains inferred, but the accepted human names preserve behavior and avoid IDA-shaped output.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 92 | The file page records the `NexusTK/util/` route, complete RuntimeClass descriptor/helper source inventory, exact runtime shell, callback/wrapper family, ordinary destructor, non-emitting deleting support, vtable/RTTI regeneration, and unrelated string/FolderTreePane exclusions. |
| Confidence | 93 | Instruction, descriptor, vtable, RTTI, destructor-liveness, ChangeMan dispatch, helper, and override evidence fixes the API and file route. Inferred original macro/member spelling remains the cap. |

## Cross-References

- [UID:00007D][LObject](by-class/LObject.md)
- [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md)
- [UID:000198][0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener](by-memory/0x004f4b30-0x004f4b4c.LObjectRegisterChangeListener.md)
- [UID:00019A][0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener](by-memory/0x004f4b50-0x004f4b6c.LObjectUnregisterChangeListener.md)
- [UID:00019B][0x004f4b70-0x004f4b86.LObjectForwardMessage](by-memory/0x004f4b70-0x004f4b86.LObjectForwardMessage.md)
- [UID:000199][0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers](by-memory/0x004f4b30-0x004f4b6c.LObjectChangeManRegisterWrappers.md)
- [UID:000195][0x004f4a80-0x004f4c0d.LObjectRuntimeShell](by-memory/0x004f4a80-0x004f4c0d.LObjectRuntimeShell.md)
- [UID:00036Z][0x004f4a80-0x004f4a89.LObjectConstructor](by-memory/0x004f4a80-0x004f4a89.LObjectConstructor.md)
- [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md)
- [UID:000371][0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor](by-memory/0x004f4b10-0x004f4b16.LObjectRuntimeClassAccessor.md)
- [UID:000375][0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim](by-memory/0x004f4b20-0x004f4b30.LObjectRuntimeClassMembershipShim.md)
- [UID:000373][0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor](by-memory/0x004f4b90-0x004f4c0d.LObjectScalarDeletingDestructor.md)
- [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md)
- [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md)
- [UID:0001J3][0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation](by-memory/0x005832f0-0x00584d7e.StringBaseReleaseFormatAndMutation.md)
- [UID:0001VQ][RefCountedStringBufferHeader](by-type/by-struct/RefCountedStringBufferHeader.md)
- [UID:0000TM][StringBufferSentinelsAndPools](by-global/StringBufferSentinelsAndPools.md)
- [UID:0000MM][PoolAllocator](by-file/PoolAllocator.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0000OA][StringBase](by-file/StringBase.md)
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:000157][0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers](by-memory/0x004b3350-0x004b5c3f.FolderTreePaneTreeAndSortHelpers.md)

## Changes

- 2026-08-01 Agent-B004 UID0003OO support callback:
  - Raised `90/92 -> 92/93` and added the complete RuntimeClass/LObject source inventory covering UID0003ON, UID000371, UID00023R, UID000375, UID0003OO, and non-emitting UID000373.
  - Resolved the former runtime-helper declaration/source-placement question into one coherent `NexusTK/util/LObject.h` and `LObject.cpp` route while preserving unrelated string-family and FolderTreePane exclusions.
- 2026-07-15 Agent-B004 UID000373 callback:
  - Score/path and all unrelated source-family detail remain unchanged at `90/92` and `NexusTK/util/`.
  - Replaced the source-looking `LObject::ScalarDeletingDestructor` treatment with non-emitting compiler support, identified UID000370 as the sole empty destructor body, and added exact hashes, liveness, flag/no-vector, source placement, and generated-output expectations.
- 2026-07-13 Agent-B003 UID0000ZW callback:
  - Changed `86/87` to `90/92` and synchronized the LObject source route with the accepted callback/wrapper class declaration.
  - Added exact wrapper children at `0x004f4b30-0x004f4b86`, their non-emitting pair/index page, and the dispatch-derived `OnChangeMessage(LObject *, Message *)` interpretation of the base no-op slot.
  - Historicalized former Application wrapper ownership: the Application-family xrefs are inherited member calls, while implementation flow and validator-preserving renames place the definitions under LObject.
  - Preserved the separate string-family, FolderTreePane, and runtime-class-helper dispositions and their open naming/source-boundary caps.

- 2026-06-20 B004 support update:
  - Changed support wording only; score unchanged.
  - Summary/evidence: renamed the stale [UID:0001J1][0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) link to [0x00582500-0x00583206.StringBaseConstructionAndCow](by-memory/0x00582500-0x00583206.StringBaseConstructionAndCow.md) and recorded that the range is a non-emitting StringBase aggregate, preserving the existing rejection of string-buffer helpers as true `LObject.cpp` ownership.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:76`.
  - Summary/evidence: true base-object shell, polluted string-buffer helpers, folder-tree false ownership, source-structure decision, owner-split caveats, and cross-references are documented; confidence is capped by unresolved final split between `LObject`, `StringBase`, `StringUtil`, and pool/string helper ownership.
- 2026-06-01 runtime-class helper update:
  - What existed before: the file contents named `GetRuntimeClass` but did not include the raw membership/callback helper island reached from the runtime shell.
  - Changed to: added the `0x004f4b20` shim and [UID:00023R][0x005568d0-0x00556907.CallbackAndListMembershipHelpers](by-memory/0x005568d0-0x00556907.CallbackAndListMembershipHelpers.md) as likely runtime-class support with final declaration owner still open.
  - Evidence: IDA MCP disassembly shows the shim calls vtable slot `+4` and tail-jumps to a helper that walks a `+0x0c` base chain; the sibling raw helper invokes an optional pointer at `+0x8`.
- 2026-06-04 live IDA refinement:
  - What existed before: `COMPLETION:80`, `CONFIDENCE:76`, blank projected path, and confidence held down by recovered-owner pollution.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: live IDA now verifies the exact base/runtime shell, `0x0061cf68` vtable contents and limited xrefs, `0x0061cf44` runtime-class record, raw membership shim/helper behavior, and separate caller patterns for the string and FolderTreePane families. The score increase reflects a stronger `LObject.cpp` source boundary, while final C++ remains blank under the 95+ gate.
- 2026-06-11 Agent-A001 Batch 158 exact-child split:
  - What existed before: `COMPLETION:84`, `CONFIDENCE:84`, and the file page described the base shell through the mixed aggregate.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`; added exact runtime-shell child references for the constructor, destructor body, runtime-class accessor, raw membership shim, and scalar deleting destructor.
  - Summary/evidence: live IDA MCP reconfirmed exact function boundaries, vtable stores, unique runtime-class data xref, and the raw `0x004f4b20` shim. The source-file parent now clears the strict 85/85 gate for exact `LObject` child pages, but final C++ remains blank below the 95+ code gate.
- 2026-06-19 B005 support update:
  - Changed support wording without changing the file score.
  - Summary/evidence: [UID:0000WM][0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual](by-memory/0x0041b6c0-0x0041b6c3.LObjectDefaultNoOpVirtual.md) now emits first-draft class-owned C++ through [UID:00007D][LObject](by-class/LObject.md) while this file remains the source route. Generated output should now contain the empty `VirtualNoop(int, int)` body instead of only an empty emitter marker after validator/autogen refresh.
