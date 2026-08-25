*** UID:0000PW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
SimpleUString g_emptySimpleUString;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
extern SimpleUString g_emptySimpleUString;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_emptySimpleUString

## UID0000IF Ordered Header Closure - 2026-08-24

- This global is StringUtil H emitter position `30`. It preserves the exact external declaration after the three class fragments and closes the sole `NEXUSTK_UTIL_STRINGUTIL_H` guard opened by UID0000D9.
- Formal CPP remains the one bare `SimpleUString g_emptySimpleUString;` definition. The exact 24-byte storage child, startup/cleanup compiler lowering, external linkage, owner UID0000OB, score `92/93`, and consumer-versus-owner evidence are unchanged.
- No second guard, duplicate definition, explicit empty-literal constructor, target-only overload, or child placeholder is introduced. Generated proof requires the extern once as the final declaration before the sole `#endif`.

## Status

- Address range: `0x0066daec-0x0066db04`
- Entity kind: process-wide empty `SimpleUString` fallback.
- Direct autogen parent: [UID:0000OB][StringUtil](by-file/StringUtil.md); [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer of the fallback, not the owner.
- Source placement: external definition in `NexusTK/util/StringUtil.cpp`; declaration in `StringUtil.h`.
- Confidence: very strong for storage shape, lifetime, fallback role, and shared string-utility ownership; strong for external linkage, source placement, and inferred source-facing spelling.
- Evidence basis: IDA MCP `xrefs_to` on `0x0066daec`, `0x0066dafc`, and `0x0066db00` plus metadata lookup decompilation.

## Role

This global is one externally linked 24-byte empty `SimpleUString` object used as a stable fallback return value. Metadata lookup helpers return it when a table, row, or value index is missing, while unrelated UI and shared-string consumers use the same address.

The object is also referenced outside `MetaMan`, so the direct source-root owner is shared string support rather than `metadata/MetaMan.cpp`. Metadata docs should treat it as a dependency/fallback rather than a table-owned buffer. [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) and [UID:00002X][CollectionPane](by-class/CollectionPane.md) are likewise consumers, not owners.

## Observed Layout

```text
0x0066daec  +0x00 inline wchar_t[8] / heap wchar_t* union
0x0066dafc  +0x10 unsigned m_length
0x0066db00  +0x14 unsigned m_capacity
```

The range matches the exact 24-byte UTF-16 SSO-7 `SimpleUString` layout: inline storage is active while capacity is at most seven, and the first union word becomes a heap pointer for longer strings. Live byte inspection reads twenty leading zero bytes followed by capacity `7`, matching zeroed inline storage, length `0`, and the canonical empty inline-capacity state. The representation is MSVC/Dinkumware-compatible ABI evidence; reconstructed project source retains the human-facing `SimpleUString` type.

## Evidence

- `MetaMan::FindEntry` and `MetaMan::LoadStatValues` return `0x0066daec` when a lookup fails.
- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md) return the same object from lower direct lookup helpers.
- IDA xrefs also show non-metadata UI/help paths reading the same storage, which argues against treating it as a private `MetaMan` field.
- 2026-06-07 IDA MCP `py_eval` recheck confirms the exact object bytes at `0x0066daec-0x0066db04`, the startup initializer xref at `0x00419f27`, cleanup refs from `0x0060c100`, and field users at `0x0066daec`, `0x0066dafc`, and `0x0066db00`.
- The same recheck identifies representative non-metadata user families: [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md) population at `0x004ccca0`, [UID:00002X][CollectionPane](by-class/CollectionPane.md) drawing/setup at `0x0056edc0`, and a later UI/string helper at `0x005adad0`. These users treat the object as shared fallback storage, not as an owner-specific private buffer.
- 2026-06-07 A003 Batch 074 parent-chain repair routes this global to [UID:0000OB][StringUtil](by-file/StringUtil.md), which is `85/88` and documents the shared `SimpleUString`, `SimpleUStringVector`, `StringIter`, sentinel/pool, and wide-string utility infrastructure. [UID:0000OA][StringBase](by-file/StringBase.md) is only `88/80`, so it does not clear the corrected parent confidence gate, and [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer-only fallback user.
- 2026-07-29 live reanalysis of the concrete [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) storage records 33 whole-object references, 12 length-field references, 12 capacity-field references, and no interior aliases inside the `0x10`-byte storage union. Hard predecessor/successor fences and negative VA/RVA pointer-pattern results exclude a hidden adjacent object or competing global identity.
- The matching [UID:0000Q2][g_metaAliasTableName](by-global/g_metaAliasTableName.md) / [UID:0001OL][0x0066de18-0x0066de30.g_metaAliasTableName](by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md) family uses the same shared-empty/count-zero startup lowering while retaining a bare source definition. That repeated pattern is positive source-shape evidence for the existing `SimpleUString g_emptySimpleUString;` definition.

## Static Lifetime And Source Declaration

The initialization/destruction pair is exact. [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) records the `0x00419f20` compiler startup wrapper, which applies the shared empty wide literal with count zero to this object and registers cleanup through `atexit`. [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) records the paired `0x0060c100` compiler cleanup body, which conditionally frees heap storage, validates the large aligned-allocation header path, and restores inline NUL, length zero, and capacity seven.

The source declaration is the existing bare definition:

```cpp
SimpleUString g_emptySimpleUString;
```

Its default constructor accounts for the observed compiler lowering. Do not overfit that lowering into `SimpleUString g_emptySimpleUString(L"");` or invent a target-only `const wchar_t *` constructor overload. Normal static construction/destruction should regenerate equivalent startup and cleanup glue.

## Linkage And Placement

- Linkage is external. One process-wide address is used from metadata, item-help, collection, and later UI/string source families; a file-local `static` object could not provide the documented cross-module declaration route.
- The definition belongs in `NexusTK/util/StringUtil.cpp`, and `StringUtil.h` carries `extern SimpleUString g_emptySimpleUString;`.
- A separate `SimpleUString.cpp` remains a plausible historical organization in the abstract, but no surviving path, string, RTTI, function neighborhood, or unique owner cluster supports it. The established StringUtil owner chain and broad shared use make StringUtil.cpp/.h the deterministic reconstruction placement.
- The exact concrete storage remains [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md), which must not emit a second definition.

## Parent Routing

`AUTOGEN_PARENT_UID` points to [UID:0000OB][StringUtil](by-file/StringUtil.md). The relationship is direct: `StringUtil` owns shared `SimpleUString` utility infrastructure, this page owns the process-wide semantic global and its CPP/H declaration pair, and the by-memory child owns the exact `.data` storage range without duplicate emission.

## Resolved Questions And Bounded Uncertainty

- External versus internal linkage is resolved to external by cross-module use and the required header route.
- `StringUtil.cpp` versus a dedicated `SimpleUString.cpp` is resolved to `StringUtil.cpp`/`.h` by current ownership, helper-family grouping, and the absence of separate-file evidence.
- Bare default construction versus an explicit empty literal is resolved to the bare definition by matching sibling lowering. The binary cannot recover the exact original token spelling, but this bounded lexical uncertainty is not a source or score blocker.
- `g_emptySimpleUString`, `m_inlineBuffer`, `m_heapBuffer`, `m_length`, and `m_capacity` are deterministic project-facing inferences, not recovered original symbols. Finalized source uses these human names rather than raw IDA labels.

## Historical Assumptions

- Earlier pages correctly established the shared fallback and source owner but left linkage and the StringUtil/SimpleUString file split open. The 2026-07-29 full source-quality pass resolves both while preserving the older evidence as historical context.
- Earlier text called the initialization/destruction pair only partially confirmed. Exact startup assignment, `atexit` registration, conditional heap release, aligned-allocation validation, and empty-state reset now close that question.

## 2026-07-29 Saved IDA Reconciliation

- Supervisor Gate 2B catalog entry `0360` created `SimpleUStringSso7Storage` as an exact `0x10` union and `SimpleUStringSso7` as an exact `0x18` struct with storage, unsigned length, and unsigned capacity at `+0x00/+0x10/+0x14`. The existing size-four IDA `SimpleUString` UDT was protected and remains unchanged; it is not this object's ABI type.
- IDA consolidated `[0x0066daec,0x0066db04)` into one typed data item. `make_data` automatically used the intermediate normalization name `stru_66DAEC`; the accepted final name is `g_emptySimpleUString`. Its exact repeatable address comment records the 24-byte UTF-16 SSO-7 layout, default-construction lowering, and paired cleanup; the regular address-comment channel remains blank.
- The exact wrappers are now `g_emptySimpleUString_StaticInitializer` at `[0x00419f20,0x00419f3d)` with live prototype `int __cdecl()` and `g_emptySimpleUString_StaticCleanup` at `[0x0060c100,0x0060c15d)` with its preserved no-change prototype `void __cdecl()`. Both have only the accepted function-repeatable source-quality comments; address regular/repeatable and function regular channels remain blank.
- Target/member xrefs remain `33/0/0/0/12/12`; target bytes, predecessor/successor fences, wrapper bytes/ranges/frames/xrefs, broad clear/assign helpers, shared empty literal, and unrelated entities were preserved. The startup/cleanup names are IDA navigation aids, not handwritten source emitters.
- Catalog0360's `idb_save` returned `ok:true` for active database `1da2b2ae`. The byte-identical prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B004-UID00027J-20260729-130145.i64` has SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`; the resulting UID00027J checkpoint `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, the unrelated UID0001HA checkpoint `0E0AF9383DE743CB91E076959498A0D9DAF906C5CA6E620F99425931A09AB481`, and the later `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69` checkpoint are historical. Bounded read-only MCP and byte/xref/type readback found no UID00027J drift after the newest shared save; the current authoritative shared IDB is SHA256 `296ED21C6665B7C0D8EFBC515B137101F8506FD945C6C7E14C3E6F655063CF8B`, 143,190,676 bytes, saved `2026-07-29T14:22:15.9735862-04:00`.

## 2026-07-01 B007 Source-Disposition

The formal declaration emits the accepted source-facing global. The exact original linkage spelling remains source-inferred, but the storage evidence, project-canonical name, and shared fallback role are strong enough for a normal declaration rather than a report-only note.

## Cross-References

- [UID:0001C9][0x00523a00-0x00523c99.MetaManLookupHelpers](by-memory/0x00523a00-0x00523c99.MetaManLookupHelpers.md)
- [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:0000OB][StringUtil](by-file/StringUtil.md)
- [UID:0001V6][MetaTableDecodedPayload](by-type/by-struct/MetaTableDecodedPayload.md)
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md)
- [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md)

## Changes

- 2026-07-29 B004 UID00027J ordinary implementation callback:
  - Raised `89/88 -> 92/93`; owner/emitter `0000OB` and reconstructable state remain unchanged.
  - Preserved the accepted bare CPP definition, added the exact external H declaration, and resolved source placement to `NexusTK/util/StringUtil.cpp` plus `StringUtil.h`.
  - Added the exact SSO-7 ABI, 33/12/12 xref evidence, default-constructor lowering, static cleanup, external-linkage rationale, consumer-versus-owner distinctions, rejected explicit-`L""`/new-overload alternative, and historical split/lifetime assumptions.
- 2026-07-01 B007 [UID:0000OB][StringUtil](by-file/StringUtil.md) implementation callback: raised score to `89/88`, inserted `SimpleUString g_emptySimpleUString;`, and preserved the source-linkage caveat.
- 2026-06-07 A003 Batch 074 coverage-error repair:
  - Changed to: `AUTOGEN_PARENT_UID:0000OB`; scores unchanged at `88/86`.
  - Summary/evidence: generated memory coverage for [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) reported `autogen_parent_unknown` because this global parent had no source-root assignment. Routing to [UID:0000OB][StringUtil](by-file/StringUtil.md) is justified because the global is a shared `SimpleUString` fallback, `StringUtil` is `85/88`, [UID:0000OA][StringBase](by-file/StringBase.md) fails the confidence gate at `88/80`, and [UID:0000LC][MetaMan](by-file/MetaMan.md) is a consumer-only fallback user.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents range, empty `SimpleUString` fallback role, observed layout, metadata and non-metadata users, initializer/cleanup evidence, and open source-owner questions.

- Before: the page listed the `0x00419f20` and `0x0060c100` startup/cleanup pair as an open question.
- After: the page records that IDA/MCP evidence confirms the pair initializes and destroys `dword_66DAEC`, while final source ownership remains open.
- Evidence: [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) documents the `0x0060c100` cleanup body, and [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) documents the `0x00419f20` initializer wrapper.
- 2026-06-05: Marked as reconstructable and intentionally left unassigned. Evidence: live IDA MCP xrefs show 33 references to `0x0066daec`, 12 to `0x0066dafc`, and 12 to `0x0066db00`; decompilation confirms `0x00419f20` initializes `dword_66DAEC` and registers `0x0060c100`, while `0x0060c100` resets the string layout. The object is recoverable, but source ownership remains split between metadata lookup helpers and broader string fallback users.
- 2026-06-07 A008 Batch 029 refresh:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP rechecked exact bytes, initializer/cleanup refs, field refs, and representative metadata plus non-metadata consumers. Confidence now clears the parent gate for exact storage parenting, while final source-file ownership remains open.
