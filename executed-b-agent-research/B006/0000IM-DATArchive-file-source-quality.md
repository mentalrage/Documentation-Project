# UID0000IM DATArchive Whole-File Source-Quality Report
** TARGET-REPORT-UID:0000IM **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

- Agent: `B006`
- Provenance: `CHATGPT | 5.6 | xHigh`
- Phase: accepted ordinary implementation callback complete; manual coverage, IDA, report execution/archive, audit, catalog, tracker, and lifecycle state remain supervisor-owned and were not changed by B006.
- Project context: local preservation and faithful source reconstruction of the unsupported NexusTK client.

## Finalized Report / Current Recommendation

UID0000IM is not a historical `DATArchive.cpp` or `DATArchive.h` compilation unit. It is a documentation umbrella that was created to collect archive and resource research before the concrete split stabilized. Current binary, type, xref, source-route, generated-output, and negative-symbol evidence supports exactly two authored archive compilation units: `DATFile.cpp/.h` and `DATFileMgr.cpp/.h`. The historical `DATIndexVector.cpp/.h` proposal is rejected as an old-MSVC/Dinkumware `stdext::hash_map` lowering family shared through identical COMDAT folding across unrelated consumers.

The accepted callback made the target a path-`NONE`, non-reconstructable, non-emitting archive-subsystem index. Its useful format, API, caller, package, and boundary research remains, while the three-file source hypothesis and statements that made adjacent render/audio/application consumers look like candidate DATArchive-owned code are explicit superseded history. No `DATArchive.cpp` or `DATArchive.h` is generated.

The dated pre-callback defects were three DATFile empty markers, fourteen missing authored bodies, DATFileMgr dependency ordering and synthetic `stdext::hash_map` lowering, an absent `FileError` declaration, and stale source-tree/DATIndex ownership prose. The accepted callback repaired those owning pages without transferring code to UID0000IM. Fresh physical readback after waited validator command `000000025893` found only `DATFile.cpp/.h` and `DATFileMgr.cpp/.h` in the generated archive directory, all eighteen DATFile authored bodies, dependency-complete manager source, no synthetic resolver/node helper definitions, the complete `FileError` declaration in `Error.h`, and no archive `Empty Emitter Marker`. The previously omitted canonical consumer [UID:0000QU] `g_pEPFLib` remains an ImageLib-owned render global under UID0000K2: DAT-backed resource loading is a dependency edge and does not transfer its storage, lifecycle, declaration, or source ownership to the archive subsystem.

## Supporting Research

- Live canonical IDA MCP session: `supervisor_uid0002ox_persistverify_20260817`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Public schema-1 `runtime_attestation`: `ok:true`, `errors:[]`, exact requested session/path matched, listener `127.0.0.1:13337`; dated nonce `73d07cb4763eb58dea98bd1980e04c2c`. Session/process identities are dated evidence only and confer no future mutation authority.
- Gate 1 repair recheck at `2026-08-17T22:16:33-04:00` used the same canonical session/path and a fresh public schema-1 attestation with `ok:true`, `errors:[]`; listener nonce `96cd7ccf26f8fabb79568398313b2c8b` and canonical worker nonce `05ff6e60bd3c8e2e7e7746efdb747f23` are dated read-only evidence only.
- Bounded current IDA queries covered the core `0x0049bd00-0x0049d700` island, DATIndex helper addresses, `0x0067ab40`, RTTI/type names, callers/callees/xrefs, function bodies, and exact current comments/items/bytes. One earlier broad text/type query timed out; subsequent bounded queries succeeded, so MCP remained available.
- The repair recheck additionally inspected [UID:0000QU] `g_pEPFLib`, exact storage [UID:0001OQ] at `0x0067a744`, ImageLib lifecycle functions, all 231 direct data xrefs, representative render consumers, and the DAT-backed `ResourceLayoutTable::LoadResourceIndex` path. Current IDA renders the four-byte data item as `ResourceLayoutTable *`; current source documentation resolves that as the compatibility facet over the one ImageLib-owned `extern ImageLib *g_pEPFLib` declaration.
- Current generated archive snapshot is command `000000025804`, refreshed `2026-08-17T19:52:18-04:00`. This is a dated research receipt; generated authority is dynamic and requires fresh supervisor readback.
- Generated files at that snapshot: `DATFile.cpp` `4B964D9ADEF0285DCCCC0A1710D35C6C34DA8EDC5A3B3EEF6EE494D63180E1D5` (5,026 bytes/123 lines), `DATFile.h` `64AA86D10F6A57D251D2496DD8D13D8548C1D6333F6A7CB7268C1771E0A0AF12` (1,443/48), `DATFileMgr.cpp` `63F1BF9A331095FBCA00BAFD5A6FB825B8E9BCAD5EE9B3A3F7B16F98F7214382` (12,399/376), and `DATFileMgr.h` `0B0C8EFC3F1F5CFD1BD39413EB21B724365152E2870A184437ED3FAF6182C2C8` (957/35).
- Accepted callback validators ran serially as commands `000000025831` through `000000025893`, all with exit `0` and `ok:1`; command `000000025893` was the final waited owning-file validation. Current generated identities are recorded under Validator Results. Generated command/hash authority remains dynamic and requires fresh supervisor Gate readback.
- No generated `DATArchive.cpp/.h` or `DATIndexVector.cpp/.h` exists in the current archive directory.
- Current package evidence retained from the target/support pages: 250 DAT archives parsed with monotonic bounded offsets; 1,038 non-empty exposed names were NUL-terminated within 13 bytes; three final boundary rows had nonzero name-area bytes. This resolves the record/boundary semantics without proving an umbrella source file.

## Target

- Primary: [UID:0000IM] `by-file/DATArchive.md`.
- Assignment-time metadata: completion `89`, confidence `87`, path `NexusTK/archive/`, canonical owner `FILE`, reconstructable field absent.
- Assignment question: genuine source unit versus umbrella/module index versus obsolete aggregate.
- Result: obsolete aggregate retained only as a non-emitting research index; no source artifact.
- Additional target UIDs declared: none. Concrete/support pages below are callback destinations, not additional report targets.

## Current Target State

- The page now identifies DATArchive as a non-emitting archive-subsystem index, rejects the historical three-source hypothesis, and places no `DATIndexVector.cpp` in the current source tree.
- The page links 70 distinct canonical by-* documents and names 28 additional textual candidate entities/ranges. After alias deduplication, the target-attributed inventory is 84 entities: 2 authored archive units, 31 archive-owned classes/functions/data/type/compiler items, 44 consumer/adjacent entities, and 7 third-party/runtime/codec exclusions. This pass also closed two compile-visible support dependencies, FileError and the StringBase count/character append overload, for 86 total reviewed logical dispositions.
- The added canonical disposition is [UID:0000QU] `g_pEPFLib`: its [UID:0001OQ] storage, UID00006E declaration, and constructor/destructor writes and clears route to [UID:0000K2] ImageLib. Its render consumers and ImageLib/ResourceLayout methods may call DATFile, but no DAT core function owns or mutates the singleton lifecycle.
- The target owns zero code ranges, zero data ranges, zero functions, zero globals, zero types, zero vtables/RTTI objects, zero imports/resources, and zero formal CPP/H fragments.
- Current generated output has no DATArchive/DATIndex artifact, contains all eighteen DATFile authored bodies and complete headers, places DATFileMgr dependencies before definitions, expresses manager containers through typed source, contains no unresolved invented helper or archive empty marker, and exposes the complete `FileError` declaration.
- Current manual coverage is stale for UID0000IM, UID0000IN, UID0000IO, UID0000IP, the DATIndex family, DATFile layout/vtable, DATEntryRecord, and `g_pDATFileMgr`.

## Executive Recommendation

1. Applied: UID0000IM is `97/98`, path `NONE`, canonical owner `NONE`, `RECONSTRUCTABLE:FALSE`, with blank formal code.
2. Applied: the current authored split is exactly `DATFile` and `DATFileMgr`; `DATIndexVector` is a path-`NONE` compiler-family evidence index.
3. Applied: valid DAT format/package/API and consumer evidence remains in the archive-subsystem map with explicit ownership boundaries.
4. Applied: DATFile source closure now uses the shared 17-byte record, typed class members, exact method children, and no-code compiler-product dispositions.
5. Applied: DATFileMgr dependencies precede use, and the typed `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>` plus vector replace the synthetic authored resolver/node-helper model.
6. Applied in ordinary docs: stale `DATIndexVector.cpp` source-tree/meta claims were historicalized. Manual coverage remains reserved for the supervisor.
7. Remaining supervisor work: independently verify/apply the bounded `g_pDATFileMgr` IDA data/comment handoff and manual coverage; UID0000IM itself has no IDA entity.

## Supervisor Active Recheck

- Recheck target metadata, all 70 canonical links, the complete core function island, current generated archive directory, current manual coverage, current proposed source tree, current DAT meta/container docs, and matching archived reports.
- Recheck UID0000QU/UID0001OQ/UID0000K2/UID00006E together: exact storage and ImageLib lifecycle/declaration ownership remain render-owned even though the non-virtual ResourceLayout API opens and reads DAT-backed resources.
- Recheck that no `DATArchive` or `DATIndexVector` UDT/RTTI/vtable/source symbol/string/export/global survives in the current IDB.
- Recheck that DAT RTTI strings are limited to `_DATFileMgr`, `DATFileContainer`, `DATFileMgr`, `Singleton<DATFileMgr>`, and `DATFile`.
- Recheck that only `DATFile.cpp/.h` and `DATFileMgr.cpp/.h` remain generated; DATFile has all sixteen class methods plus the two authored file helpers; DATFileMgr has only authored wrapper/private-manager/container/free-helper source; and neither output contains target-specific empty/stub/placeholder/compiler-lowering markers.
- Recheck all manual coverage replacement text before applying it; B006 did not edit coverage.

## Inference Research Guidance Check

- The historical imported/recovery filename `DATIndexVector.cpp` was treated as lead evidence, not authority.
- Broad caller fanout was not mistaken for one custom shared class; old MSVC template layout, no UDT/RTTI/constructor/global, and consumer-specific mapped types outweigh the recovery label.
- Human source shape uses ordinary `DATFile`/`DATFileMgr` classes, a packed DAT record, `StringBaseA`/`StringBaseW`, a typed old-MSVC `stdext::hash_map`, and compiler-covered vtables/deleting destructors/template internals. It does not reproduce decompiler labels, a synthetic `DATFileResolver`, bucket/list nodes, EH cleanup helpers, or static vtable arrays.
- Runtime behavior remains primary. Naming/style consistency is secondary and uses existing archive conventions (`DATFile`, `DATFileMgr`, `g_pDATFileMgr`, `m_` members).
- Wave2/Wave3 wording found in older source-tree/meta history was ignored as stale workflow material.

## Heuristic / Inference Reanalysis And Validation

| Hypothesis | Evidence for | Evidence against | Resolution |
| --- | --- | --- | --- |
| One historical `DATArchive.cpp` | Broad conceptual archive/resource relationship. | No symbol, type, string, RTTI, vtable, global, contiguous range, source output, or exclusive caller cluster; concrete split is coherent. | Rejected. |
| Folder/module umbrella | Existing page purpose and broad cross-links. | A folder is not a compilation unit and must not own code/emitters. | Accepted only as non-emitting documentation index. |
| Three authored files including DATIndexVector | Historical recovery filename and hash-like binary behavior. | No project UDT/vtable/RTTI/constructor; seven bodies are shared standard-container lowering across distinct mapped types. | Rejected; two authored units remain. |
| DATIndexVector private to DATFileMgr | DAT manager is one consumer. | MiniMap, FittingRoom, and MonsterImageLib use the same folded bodies. | Rejected; source consequences stay consumer-local. |
| EPF/image/audio/application code belongs to archive | They call DAT APIs. | Their state, callers, tables, literals, and behaviors are feature-owned; UID0000QU storage is written/cleared only by the ImageLib lifecycle and merely reaches DATFile through ImageLib/ResourceLayout methods. Dependency is not ownership. | Rejected. |
| 17-byte record is source-level | Repeated exact stride and next-row offset semantics in manager and reader; package audit. | Exact original spelling unavailable. | Accepted as inferred packed `DATEntryRecord`, owned by the shared manager header and consumed by DATFile. |
| `DATFileResolver` was handwritten | Recovery documentation grouped the embedded `+0x04` state under that descriptive name. | Default `1.0f` load factor/eight buckets, `hash = ch + 5 * hash`, two-direction range comparison, list sentinel, growth thresholds, automatic destruction, and shared Dinkumware helper bodies exactly match `stdext::hash_map` lowering. | Rejected as project source; retain as historical semantic overlay only. |
| `0x0049c570` is a DATFile-authored wide overload | It lies inside the DATFile island and has the same conversion behavior. | It is byte/behavior-identical to `File::ReadLine(StringBaseW&)` at `0x004b1340`, both have zero inbound callers, and live `ReadAllLines` contains the base helper inlined. | Compiler-retained COMDAT/inline duplicate; no DATFile declaration/body. |

## Evidence Standards Used

- Direct current IDA entity/type/xref/decompile/byte/comment evidence outranks historical recovery names.
- Repeated binary behavior plus current package data supports format/layout claims.
- Current by-* owner/emitter/formal channels support source routing but were checked against generated output and IDA.
- Cross-subsystem caller fanout is negative source-owner evidence unless one actual shared source abstraction is independently proven.
- Absence claims are bounded: current IDB regex/type/export/generated searches found no DATArchive entity and no DATIndex project type; they do not claim lost source symbols can never have existed.

## Evidence Checked

- Live MCP: attestation; bounded regex/type queries; core entity/function inventory; DATIndex callers; DAT manager/data xrefs; decompiles for DATFile constructor/destructor/Open/Close/Seek/GetPosition/GetSize/Read/ReadLineChars/ANSI ReadLine/IsOpen/GetDataPointer/wide-line duplicate/ReadAllLines/OpenByIndex; byte/behavior comparison with `File::ReadLine(StringBaseW&)`; manager constructor/load/find/hash insert/hash find; mapped-container constructor; exact container error literals; StringBase count/character append at `0x00584200`; `0x0067ab40` item/comments/bytes/xrefs; and UID0000QU storage/item/type/bytes, all 231 data xrefs, ImageLib constructor/destructor, and `ResourceLayoutTable::LoadResourceIndex` DATFile use.
- Documentation: UID0000IM, concrete DATFile/DATFileMgr/DATIndexVector file and class pages, `_DATFileMgr`, DATFileContainer, DATFileResolver, exact manager node/hash/destructor children, DATFile aggregate/layout/vtable/record/global pages, UID0000QU/UID0001OQ/UID0000K2/UID00006E ImageLib global/storage/file/class pages, File/StringBase/FileError/Error supports, client DAT/container meta pages, proposed source tree, current manual coverage rows, generated tracker/coverage lead pages, and current generated archive/Error/ImageLib CPP/H.
- Matching executed reports: DATFileMgr family, DAT managers, DATIndexVector class/method family, DecodeTableValue, LoadDatFileBuffer, and manager forwarder reports.
- Negative checks: no DATArchive/DATIndex type or RTTI/string/export; no generated umbrella/index file; no exclusive DATIndex owner; no code/data range attributable to UID0000IM.
- Failed check: one broad text/type query timed out. It was replaced by bounded current queries that succeeded; no fallback-only conclusion was used.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| CIM-001 | 0000IM | DATArchive is a non-emitting documentation index, not a compilation unit. | Very high | Zero binary/source identity and coherent concrete split. | UID0000IM Status/Disposition | reject-stale | applied |
| CIM-002 | 0000IM | Set metadata to 97/98, path NONE, owner NONE, reconstructable false. | Very high | Complete negative and ownership proof. | UID0000IM metadata | incorporate | applied |
| CIM-003 | 0000IM | Keep both formal source dispositions blank; generate no DATArchive CPP/H. | Very high | Zero owned source entities. | UID0000IM source disposition | incorporate | applied |
| CIM-004 | 0000IN | DATFile is the first authored archive unit and owns reader/helper source. | Very high | RTTI/vtable/method island and broad API use. | UID0000IN file role | incorporate | applied |
| CIM-005 | 0000IO | DATFileMgr is the second authored archive unit and owns wrapper/private-manager/container/global source plus typed standard-container consequences. | Very high | RTTI/type/layout/core island and old-MSVC container lowering. | UID0000IO file role | incorporate | applied |
| CIM-006 | 0000IP | DATIndexVector is compiler/template-family evidence, not source. | Very high | Seven folded bodies and cross-consumer mapped types. | UID0000IM/UID0000IP split | reject-stale | applied |
| CIM-007 | 0000IM | Reconcile 70 canonical links and 28 textual candidates into 84 target dispositions plus two compile-closure supports, 86 total. | High | Exhaustive target/link/table/generated/IDA audit. | UID0000IM Complete Inventory | incorporate | applied |
| CIM-008 | 00012D | Preserve complete DATFile method map but split source-bearing methods from the non-emitting mixed aggregate. | Very high | Exact ranges and live bodies. | UID00012D inventory/split | incorporate | applied |
| CIM-009 | 00003G | Complete DATFile H with typed container/record pointers, `StringBaseW` vector support, and all sixteen authored class methods. | Very high | Exact layout, live method bodies, base helper identity, and callers. | UID00003G formal CPP/H | incorporate | applied |
| CIM-010 | 0000UC | Emit packed 17-byte DATEntryRecord in DATFileMgr H at position 5. | Very high | Code and 250-file package audit. | UID0000UC formal H/metadata | incorporate | applied |
| CIM-011 | 00003H | Move DATFileContainer declaration to H, add DATFile and `_DATFileMgr` friendship, keep implementations in CPP, and replace invented error helpers with direct exact formatting/MessageBox/`throw new Win32Error`. | Very high | Direct field consumers and live constructor literals/control flow. | UID00003H and exact constructor formal CPP/H | incorporate | applied |
| CIM-012 | 00003I | Make DATFileMgr CPP preamble include its two archive headers plus File/Error/PathUtil and standard dependencies before children. | Very high | Dated pre-callback generated include occurred after definitions and left required APIs/types unresolved. | UID00003I formal CPP | incorporate | applied |
| CIM-013 | 0003H3 | Reclass DATFileLayout as non-emitting semantic overlay; class H is sole layout source. | Very high | Current empty marker duplicates UID00003G. | UID0003H3 metadata/no-code | reject-stale | applied |
| CIM-014 | 0003I0 | Reclass DATFileVtable as compiler-generated/non-emitting evidence. | Very high | Vtable arises from class virtuals. | UID0003I0 metadata/no-code | reject-stale | applied |
| CIM-015 | 0000IN | Add exact DATFile core/line/accessor/OpenByIndex source children; scalar deleting destructor and duplicate wide-line COMDAT remain compiler-covered. | Very high | Live decompile, exact duplicate proof, callers, and vtable map. | New exact by-memory children/UID0000IN inventory | incorporate | applied |
| CIM-016 | 0000IN | Generated DATFile must contain sixteen authored class methods plus DecodeTableValue and LoadDatFileBuffer, with all eighteen bodies and zero empty/compiler markers. | Very high | Dated command 000000025804 emitted four authored bodies, omitted fourteen, and had three markers. | UID0000IN Generated Audit | incorporate | applied |
| CIM-017 | 0000IO | Replace the dated pre-callback 23-item mixed DATFileMgr output with source-closed authored wrapper/private-manager/container/free-helper code and no synthetic resolver/node/hash lowering. | Very high | Dated pre-callback physical output plus live compiler-pattern proof. | UID0000IO Generated Audit | incorporate | applied |
| CIM-018 | 0000QQ | Keep g_pDATFileMgr source owner/definition in DATFileMgr. | Very high | 24 xrefs and wrapper/internal split. | UID0000QQ Ownership | already-present | already-present |
| CIM-019 | 0000T0 | HasDATEntry remains DATFileMgr API support. | Very high | Sole manager lookup call and broad consumers. | UID0000IM API Boundary | incorporate | applied |
| CIM-020 | 0000T4 | LoadDatFileBuffer remains DATFile source support. | Very high | Complete DATFile lifecycle wrapper. | UID0000IM API Boundary | incorporate | applied |
| CIM-021 | 0000TH | DecodeTableValue remains file-local DATFile support. | Very high | Exactly two typed DATFile wrapper callers. | UID0000IM API Boundary | incorporate | applied |
| CIM-022 | 0000T5 | LoadIndexedDATSeries remains Application startup policy. | Very high | Nineteen startup call sites and numbered archive formatting. | UID0000IM Exclusions | incorporate | applied |
| CIM-023 | 0000UF | DestroyDATFileMgr remains Application/fatal cleanup code, not manager-owned source. | High | App cleanup/EH placement and global deletion. | UID0000IM Exclusions | incorporate | applied |
| CIM-024 | 0000IM | Render/image/palette/audio entities are consumers, not archive owners. | Very high | Feature-specific state/tables/callers. | UID0000IM Consumer Matrix | incorporate | applied |
| CIM-025 | 0000IM | LodePNG/Zlib/image writers are third-party or render codec exclusions. | Very high | Current vetted third-party ownership. | UID0000IM Exclusions | incorporate | applied |
| CIM-026 | 0001R1 | Remove DATIndexVector.cpp tree node and describe exactly two authored archive units. | Very high | Current compiler-family reclassification. | proposed-source-tree archive sections | reject-stale | applied |
| CIM-027 | 0001QC | Replace three-module DAT model and all standalone DATIndexVector prose. | Very high | Current owner pages and live IDA. | client_dat_specifications | reject-stale | applied |
| CIM-028 | 0001QA | Retain current path-NONE DATIndex standard-container explanation. | Very high | Page already matches current proof. | client_containers | already-present | already-present |
| CIM-029 | 0000IM | Preserve package audit and 17-byte boundary-row semantics without claiming an always-empty sentinel. | Very high | 250-file physical audit. | UID0000IM Format Evidence | incorporate | applied |
| CIM-030 | 0000IM | Historical DATIndex custom class/folder assumptions remain as explicitly superseded history. | High | Useful provenance, contradicted source conclusion. | UID0000IM Historical Assumptions | historicalize | applied |
| CIM-031 | 0000IM | Replace stale by-file manual coverage row with non-emitting 97% index row. | Very high | Current row says reconstructable umbrella. | by-file/-coverage-report.md | reject-stale | proposed |
| CIM-032 | 0000IN | Replace DATFile manual row after source closure with exact 94% row. | High | Full inventory and formal repair plan. | by-file/-coverage-report.md | incorporate | proposed |
| CIM-033 | 0000IO | Replace stale 89% DATFileMgr row with exact 94% row. | High | Current metadata 92/92 plus compile-closure repair. | by-file/-coverage-report.md | reject-stale | proposed |
| CIM-034 | 0000IP | Replace standalone reconstructable DATIndex row with 96% compiler-index row. | Very high | Current 96/95 path-NONE page. | by-file/-coverage-report.md | reject-stale | proposed |
| CIM-035 | 00003G | Replace DATFile class manual row after complete H/source routing. | High | Exact layout/method inventory. | by-class/-coverage-report.md | incorporate | proposed |
| CIM-036 | 00003H | Replace stale 80% DATFileContainer manual row. | High | Current 88/90 plus exact H/CPP route. | by-class/-coverage-report.md | reject-stale | proposed |
| CIM-037 | 00003I | Replace stale 78% DATFileMgr class manual row. | High | Current 91/94 and complete H. | by-class/-coverage-report.md | reject-stale | proposed |
| CIM-038 | 00003K | Replace stale custom/reconstructable DATIndex class manual row. | Very high | Current 95/95 non-reconstructable overlay. | by-class/-coverage-report.md | reject-stale | proposed |
| CIM-039 | 0000UC | Replace DATEntryRecord manual row after packed H emission. | Very high | Exact size/offset/package semantics. | by-item/-coverage-report.md | incorporate | proposed |
| CIM-040 | 0003H3 | Replace layout manual row with non-emitting 95% overlay. | Very high | Sole class-H ownership. | by-type/by-struct/-coverage-report.md | reject-stale | proposed |
| CIM-041 | 0003I0 | Replace vtable manual row with non-emitting 95% compiler evidence. | Very high | Exact vtable/compiler disposition. | by-type/by-vtable/-coverage-report.md | reject-stale | proposed |
| CIM-042 | 0000QQ | Replace stale 86% global coverage row with current 90% row. | Very high | Current page 90/94 and fresh 24 xrefs. | by-global/-coverage-report.md | reject-stale | proposed |
| CIM-043 | 0002U7 | Replace stale reconstructable custom fill coverage with 92% compiler lowering. | Very high | Current page false/no emitter. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-044 | 0000WW | Refresh manual row score/detail to 95% compiler lowering. | Very high | Current page 95/97. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-045 | 0004HG | Insert absent manual row for 92% capacity lowering. | Very high | Current exact page and one folded caller. | by-memory/-coverage-report.md | incorporate | proposed |
| CIM-046 | 0000XS | Replace custom InsertNode row with 94% compiler lowering. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-047 | 0000XT | Replace custom remove-helper row with 92% compiler unwind cleanup. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-048 | 0000XU | Replace custom destructor row with 94% automatic-container destruction. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-049 | 0000XX | Replace custom find row with 94% iterator/result lowering. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-050 | 0000QQ | Gate 2B A01 defines/names/types the four-byte singleton and adds exact repeatable comment. | Very high | Current one-byte unk head, zero bytes, 24 xrefs. | Supervisor Gate 2B A01-D/A01-C | incorporate | proposed |
| CIM-051 | 0000IM | No IDA entity is created or named DATArchive; all concrete functions/types remain with their owner reports. | Very high | Negative entity proof. | Supervisor Gate 2B protection | incorporate | proposed |
| CIM-052 | 0000IM | Scoped validators and generated physical reread completed under the accepted callback; lifecycle remains supervisor-owned. | Very high | Exact callback/lifecycle role boundary. | Validator Results/Changed Files | incorporate | applied |
| CIM-053 | 0000IN | Emit exact CR/LF behavior for ReadLineChars and ANSI ReadLine and exact `File::ReadLine(StringBaseW&)` loop for ReadAllLines. | Very high | Live decompiles and three direct ReadAllLines callers. | Exact DATFile line-method children | incorporate | applied |
| CIM-054 | 0000IN | Classify `0x0049c570-0x0049c5fe` as a non-emitting retained duplicate of `File::ReadLine(StringBaseW&)`. | Very high | Byte/behavior identity and zero inbound xrefs at both copies. | Exact duplicate child and UID00012D split | reject-stale | applied |
| CIM-055 | 0000IO | Define complete eight-byte DATEntryLocation in DATFileMgr H as container pointer plus entry index. | Very high | Public/private lookup ABI and Open/OpenByIndex consumers. | UID0000IO/UID00003I formal H | incorporate | applied |
| CIM-056 | 00003J | Reclass DATFileResolver as path-NONE, non-reconstructable, non-emitting historical semantic overlay with blank formal code. | Very high | Exact Dinkumware hash-map physical state and no standalone project identity. | UID00003J metadata/formal/history | reject-stale | applied |
| CIM-057 | 000004 | Replace synthetic resolver member with `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>`. | Very high | Constructor defaults, hash loop, ordering comparisons, insertion/find/destruction lowering. | UID000004 formal CPP/layout/source shape | reject-stale | applied |
| CIM-058 | 00043F/00043G/00012H/00043H/00043I | Reclass manager node allocation, insert/rehash, destruction, and find bodies as non-emitting compiler/template lowering. | Very high | Exact node/list/bucket mechanics arise from the typed hash-map member. | Five exact pages metadata/formal/history | reject-stale | applied |
| CIM-059 | 0000IO | Emit exact source-facing `_DATFileMgr` load/find/destructor behavior through typed map/vector operations, never bucket/list internals. | Very high | Live load/find decompiles and compiler lowering correspondence. | UID000004 and exact authored manager children | incorporate | applied |
| CIM-060 | 00043B | Preserve exact mapped-container Win32 behavior and literals while removing undefined `ShowDATFileError`/`ShowDATFileMapError`. | Very high | Live constructor decompile and exact UTF-16 bytes. | UID00043B formal CPP/behavior/history | reject-stale | applied |
| CIM-061 | 00004X/0000J5 | Add complete `FileError` declaration to Error H so DATFile's exact `throw new FileError(path)` source closes. | Very high | Exact constructor/copy-message/vtable/layout evidence and dated pre-callback generated omission. | UID00004X/UID0000J5 formal H/dependency | incorporate | applied |
| CIM-062 | 0000IO | Require generated DATFileMgr CPP/H to order dependencies before use and contain no unresolved invented helpers or template-lowering definitions. | Very high | Command 25804 physical readback and accepted source model. | UID0000IO generated acceptance contract | incorporate | applied |
| CIM-063 | 00003J | Replace stale reconstructable DATFileResolver manual row with a 96% non-emitting compiler-overlay row. | Very high | Typed hash-map source consequence. | by-class/-coverage-report.md | reject-stale | proposed |
| CIM-064 | 00043F | Replace authored CreateDATEntryNode coverage with compiler list-node construction lowering. | Very high | Node layout/allocator/insertion call shape. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-065 | 00043G | Replace authored resolver insert coverage with compiler hash-map insert/rehash lowering. | Very high | Exact Dinkumware insert mechanics. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-066 | 00012H | Replace authored resolver destructor coverage with automatic hash-map member destruction lowering. | Very high | Reverse-member teardown and container internals. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-067 | 00043H | Replace authored node allocator coverage with compiler list-node allocation lowering. | Very high | Sentinel/node size and no independent API. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-068 | 00043I | Replace authored resolver find coverage with compiler hash-map find lowering. | Very high | Exact hash/bucket/two-direction compare and iterator result. | by-memory/-coverage-report.md | reject-stale | proposed |
| CIM-069 | 0001WS/0000OA | Add the confirmed `StringBase& append(unsigned int count, CharT character)` template declaration required by DATFile ANSI ReadLine. | Very high | Live `0x00584200` body returns `this`, appends `count` copies, and is called as `(1, current)`. | StringBase template/file formal H | incorporate | applied |
| CIM-070 | 0000QU/0001OQ/0000K2/00006E | Preserve `g_pEPFLib` as the ImageLib-owned render global; DAT-backed ResourceLayout/ImageLib methods are consumers of DATFile and do not transfer singleton ownership to DATArchive. | Very high | Exact four-byte storage, five lifecycle xrefs, 231 direct data xrefs, UID00006E declaration, broad render fanout, and direct DATFile use from ResourceLayout/ImageLib methods. | UID0000IM consumer matrix; UID0000QU ownership boundary | already-present | already-present |

## Positive Evidence Summary

- Five surviving DAT RTTI/name strings map directly to DATFile/DATFileMgr/container/internal-wrapper identities; none maps to DATArchive, DATIndexVector, or DATFileResolver.
- The core address island has separable reader and manager/resolver function families with explicit calls across their API boundary.
- `DATFile` vtable and 20-byte layout prove one concrete reader class/source family.
- `_DATFileMgr`/DATFileMgr/container types and vtables prove one concrete manager source family; the embedded `+0x04` resolver shape independently matches the period `stdext::hash_map` implementation rather than another authored class.
- DATIndex helper bodies have shared callers across four unrelated owner families and match standard hash/list/vector lowering.
- Current generated output independently converged to exactly two archive source stems.
- UID0000QU independently proves the consumer boundary: one ImageLib-owned singleton supplies EPF/layout services to broad render/UI code, while its DATFile calls are ordinary archive-API consumption rather than archive ownership.

## IDA MCP Facts

- Core modeled island: 43 functions over `0x0049bd00-0x0049d700`, ending before `DescPane` at `0x0049d6f0`.
- DATFile has sixteen authored class methods: constructor `0x0049c130-0x0049c15a`, destructor `0x0049c160-0x0049c179`, Open `0x0049c180-0x0049c23b`, Close `0x0049c240-0x0049c260`, Seek `0x0049c260-0x0049c2cc`, GetPosition `0x0049c2d0-0x0049c2e7`, GetSize `0x0049c2f0-0x0049c304`, Read `0x0049c310-0x0049c362`, ReadLineChars `0x0049c370-0x0049c3df`, ANSI ReadLine `0x0049c3e0-0x0049c499`, encoded wrappers `0x0049c4a0-0x0049c53f`, IsOpen `0x0049c540-0x0049c548`, GetDataPointer `0x0049c550-0x0049c567`, ReadAllLines `0x0049c600-0x0049c6f2`, and OpenByIndex `0x0049c720-0x0049c74b`. `0x0049c570-0x0049c5fe` is a compiler-retained duplicate of base `File::ReadLine(StringBaseW&)`; scalar deleting destructor `0x0049d280-0x0049d2cc` is compiler-covered.
- Manager-authored source ranges are the public wrapper methods, mapped-container constructor/destructor, `_DATFileMgr` destructor/load/find, and HasDATEntry. `0x0049cbb0`, `0x0049ce50`, `0x0049d190`, `0x0049d490`, and `0x0049d5e0` are list/hash-map construction, insert/rehash, destruction, allocation, and find lowering generated from the typed map member.
- `_DATFileMgr` allocation is `0x30`: vptr at `+0x00`, a 0x20 old-MSVC hash map at `+0x04`, and `std::vector<DATFileContainer *>` begin/end/capacity at `+0x24/+0x28/+0x2c`. The map default constructor establishes a list sentinel, `1.0f` load factor, and eight buckets.
- Hash lookup/insertion computes `hash = ch + 5 * hash`, masks by the bucket mask, compares `StringBaseW` ranges in both directions, grows below 0x200 buckets by 8x and thereafter by 2x, and uses automatic list/bucket teardown. These are deterministic `stdext::hash_map` consequences, not source helper APIs.
- DATIndex caller facts: `0x00423b00` has fourteen callers across FittingRoom, MiniMap, DAT manager, and MonsterImageLib; `0x00457100`, `0x004573d0`, and `0x00457580` likewise cross owner/type boundaries.
- `0x0067ab40` current item: head `0x67ab40`, end `0x67ab41`, size 1, name `unk_67AB40`, type absent, not code/data; AR absent; AP absent. Bytes `0x0067ab3c-0x0067ab47` are twelve zero bytes. Neighbor at `0x0067ab3c` has `CheatDetector *`; next at `0x0067ab44` has `InputMan *`.
- `0x0067ab40` has 24 exact data xrefs: `0x4637b3`, `0x463e3f`, `0x463e5e`, `0x463e76`, `0x463e8e`, `0x463ea6`, `0x463ebe`, `0x463f97`, `0x46402f`, `0x46403f`, `0x46405f`, `0x4640b0`, `0x4640d3`, `0x464c99`, `0x467380`, `0x467482`, `0x49bd67`, `0x49bd6e`, `0x49be63`, `0x49c1a8`, `0x49c703`, `0x49d180`, `0x49d36d`, `0x4f5e1c`.
- `0x0067a744` current item is four-byte data `[0x0067a744,0x0067a748)`, name `g_pEPFLib`, IDA type `ResourceLayoutTable *`; twelve bytes at `0x0067a740-0x0067a74b` are zero in the canonical image. The accepted human-source route remains `extern ImageLib *g_pEPFLib` with `typedef ImageLib ResourceLayoutTable`, owned by UID0000K2/UID00006E rather than by DATArchive.
- UID0000QU has exactly 231 direct data xrefs across 169 containing functions plus 13 functionless references. Lifecycle xrefs are constructor writes/zero-path at `0x004cffef` and `0x004cfff6`, ordinary-destructor clear at `0x004d00fa`, singleton-clear helper at `0x004e5b90`, and scalar-wrapper clear at `0x004e652c`. Representative reads include EPFImageControlPane paint `0x00499341`, ItemObjImageLib draws `0x004deed8`/`0x004df090`, NewUserShapeSelectControlPane paint `0x004fdae1`, and SelfLookPane paint `0x005674a3`; no direct xref lies in the DAT core island `[0x0049bd00,0x0049d700)`.
- DAT dependency is explicit but non-owning: `ResourceLayoutTable::LoadResourceIndex` at `0x004d0120` constructs DATFile, opens at `0x004d016d`, reads/seeks/gets data, closes, and destroys it. Of 67 direct code xrefs to DATFile::Open, 47 call sites in 21 ImageLib/resource-family functions lie in `[0x004cffb0,0x004e7000)`. Calls into DATFile do not alter UID0000QU storage/declaration/lifecycle ownership.

## Function / Child Inventory

The inventory contains 84 deduplicated target-attributed logical entities plus two compile-visible support dependencies discovered by closure testing, for 86 reviewed dispositions. Each row names every canonical page or unlinked target-table candidate in that group; no row means sampled remainder.

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| DATArchive concept | UID0000IM | Documentation index; owns no binary/source item | false | NONE | 89/87 -> 97/98 | Reclassify, no code |
| DATFile source unit | UID0000IN, UID00003G, UID00012D | Authored reader file/class/mixed index | true at exact children | FILE | 89/92, 89/92, 88/92 | Keep concrete owner; complete output |
| DATFile core methods | sixteen authored class methods plus `0x0049c570` duplicate and scalar wrapper | 16 authored methods; wide helper duplicate and scalar destructor compiler-covered | mixed | UID00003G/0000IN | aggregate 88/92 | Create/repair exact children; two compiler products no-code |
| DATFile encoded helpers | UID00013W, 0004IY, 0004IZ, 0000TH, 0000V5 | File-local decoder, two typed methods, aliases | true only exact bodies | UID0000IN | 90+ | Already source-routed |
| DATFile buffer helper | UID00016G, 0000T4, 0000UW | Authored convenience loader plus covered aliases | true exact body | UID0000IN | 88+ | Already source-routed |
| DATFile source types | UID0000UC, 0003H3, 0003I0, 0003B7 | Packed record, layout overlay, compiler vtable evidence/data | mixed | UID00003G/0000IN | 88-90 | Emit record H only; other three no-code |
| DATFileMgr source unit | UID0000IO, 00003I, 000004, 00003H, 00003J, 00012B | Authored manager/wrapper/container file plus typed standard-container consequences | mixed | FILE | 88-92 | Keep concrete owner; reclass resolver overlay; repair exact source closure |
| Manager API/global | UID00012C, 00012E, 0000T0, 0000QQ, 0001P6 | Load forwarder, HasDATEntry, singleton storage | true source/covered storage | UID0000IO | 88-90 | Keep manager owner |
| Manager construction/destruction/helpers | UID000439, 00043A-00043I, 00012F, 00012H, 000227, 0002MA, 0002MB | Authored wrapper/container/private-manager bodies plus compiler map/node/vtable/deleting products | mixed | UID0000IO | 86-92 | Emit authored methods only; reclass map/node products no-code |
| FileError source support | UID00004X, 0000J5, 0002HL, 000140 | Error-owned declaration and exact constructor/message behavior used by DATFile::Open | true in Error owner | UID0000J5 | 87-92 | Add missing H declaration; keep implementation in Error.cpp |
| StringBase source support | UID0001WS, 0000OA, body `0x00584200` | Existing count/character append implementation and missing template declaration used by ANSI ReadLine | true in StringBase owner | UID0000OA | 88-91 | Add declaration only; keep implementation owner |
| DATIndex compiler family | UID0000IP, 00003K, 0002U7, 0000WW, 0004HG, 0000XS, 0000XT, 0000XU, 0000XX, 0001U0, 0001U1 | Folded standard hash/list/vector lowering | false | NONE | 92-96 | No CPP/H, retain evidence only |
| Application archive startup/cleanup | UID0000HG, 0000T5, 0000YX, 0000UF, 0000YV, 0001R6 | Startup policy, numbered DAT loops, cleanup | true in app owner | Application | varied | Excluded from archive source |
| Render/image file consumers | UID0000J3, 0000J4, 0000K1, 0000K2, 0000K3, 0000IV, 0000JH, 0000L5, 0000O7, 0000IY, 0000KH, 0000JY, 0000LR, 0000LJ, 0000LK, 0000N6, 0000KP | Feature-owned EPF/image/resource consumers | true in own files | own files | varied | Excluded |
| ImageLib render global | UID0000QU, storage UID0001OQ, declaration UID00006E, owner UID0000K2 | `g_pEPFLib` singleton/resource-layout service; ImageLib lifecycle owns writes/clears and render clients consume it | true in ImageLib owner | UID0000K2 | 89/88 global; 87/91 storage | Already correct; excluded from DATArchive ownership |
| Palette/surface consumers | UID0000MA, 0000MB, 0000V4, 0000HF, 0000K8, 0000OC, 0000UI, 0000YO | Render-owned palette/surface state and blitters | true in own files | own files | varied | Excluded |
| Resource-layout consumers | UID0000N5, 0000VB, 0000UN, 0000UX, 0000UQ, 0000VK | Render/resource tables and helpers | true in own files | own files | varied | Excluded |
| Audio evidence | UID0000UB plus SoundManager textual candidate | DAT-backed audio consumers | true in audio owner | audio | varied | Excluded |
| PCX/DIB textual helpers | LoadPcxImage, CreateDIBitmapFromPcxBuffer, DecodePcxToRgb565Buffer | Image loading/decoding | true in ImageLoaders/DIBitmap | render | n/a | Excluded |
| EPF textual helpers | LoadImageFrameTable, LoadTileEpfMetadata, BuildTilecArchiveTable, BuildEffectArchiveTable, GetSpriteBounds, GetItemGlyphBounds, ResolveSpritePartPath | Resource metadata consumers | true in named render owners | render | n/a | Excluded |
| Monster/riding textual tables | `0x00528930-0x00528d51` initializer/table cluster | MonsterImageLibTables | true in own owner | UID0000LK | n/a | Excluded |
| Compression/codec helpers | Uncompress, Crc32, Adler32, UID0000PC | zlib 1.1.4 | third-party import | Zlib | n/a | Excluded |
| Image writer codec | UID0000K4, UID0000KW | Render wrapper and LodePNG | own/third-party | own files | varied | Excluded |
| Documentation supports | UID0001QC, 0001QA, 0001R1 | DAT spec, container model, proposed tree | no source | NONE | n/a | Update stale placement prose |

Historical generated completion audit at command `000000025804`: DATFile emitted only DecodeTableValue, two encoded methods, and LoadDatFileBuffer plus aliases, then three empty markers; of eighteen authored DATFile.cpp bodies, four were present and fourteen were absent. DATFileMgr routed 23 items but was not source-closed: it defined types before includes, left DATEntryLocation incomplete, called undefined `ShowDATFileError`/`ShowDATFileMapError`, and emitted `DATFileResolver`/node/hash internals that should arise from `stdext::hash_map`. Error.h omitted `FileError`. The accepted callback superseded those defects. Fresh post-callback physical readback after command `000000025893` proves all eighteen DATFile bodies, complete DATFile/DATFileMgr headers, dependencies before manager definitions, typed source-level containers, no synthetic helper definitions, complete FileError H, and zero archive `Empty Emitter Marker`; no DATArchive or DATIndex artifact exists.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0049c130` DATFile ctor | 83 xrefs / 51 caller functions; base ctor callee | Broad shared reader API, not umbrella ownership. |
| `0x0049c180` Open | 68 xrefs / 38 caller functions; manager lookup `0x0049cad0` | Exact reader-to-manager boundary. |
| `0x0049c240` Close | 32 xrefs / 23 caller functions | Shared reader lifecycle. |
| `0x0049c260` Seek | 6 xrefs / 4 caller functions and vtable | Virtual stream behavior. |
| `0x0049c2d0` GetPosition | one direct caller plus vtable | Virtual stream behavior. |
| `0x0049c2f0` GetSize | nine code uses plus vtable, six callers | Shared reader API. |
| `0x0049c310` Read | 132 xrefs / 23 callers; `_memmove` | Shared payload read. |
| `0x0049c370` ReadLineChars | 12 xrefs / six callers | Raw line API. |
| `0x0049c3e0` ReadLine | vtable-only static xref; string helpers | Virtual line API. |
| `0x0049c4a0/0x0049c4f0` | 87 integer and six float uses; both call `0x004a5e60` | DATFile-owned encoded scalar methods. |
| `0x0049c540/550/600/720` | accessor/vector/index consumers; `0x0049c600` has calls from `0x005772c3`, `0x00586581`, and `0x00589de7` | DATFile-owned non-vtable helpers. |
| `0x0049c570` / `0x004b1340` | each has zero inbound xrefs and only its own first-instruction flow edge; bodies are identical | DAT-TU retained duplicate of base `File::ReadLine(StringBaseW&)`; one human base helper, no DATFile method. |
| `0x0049be70` | 14 refs from startup/constructor paths; calls `0x0049c800` | Public manager load forwarder. |
| `0x0049cad0` | four refs from forwarder, Open, HasDATEntry, loader | Shared internal lookup. |
| `0x0049c700` | 17 caller families | Manager API consumed across resource systems. |
| `0x00467410` | 19 call sites within Application startup | Application policy, not archive implementation. |
| `0x004bb120` | ten UI/resource callers; complete DATFile lifecycle | DATFile convenience helper. |
| DATIndex seven-body family | callers span FittingRoom, MiniMap, DAT manager, MonsterImageLib | Compiler/template folding, not custom file. |
| `0x0067ab40` | 24 exact data xrefs listed above | DATFileMgr singleton storage. |
| `0x0067a744` `g_pEPFLib` | 231 direct data xrefs; five exact lifecycle writes/clears; broad render/UI reads; zero xrefs in `[0x0049bd00,0x0049d700)` | ImageLib-owned render singleton, not DATArchive/global manager storage. |
| `0x004d0120` ResourceLayout load path | Direct DATFile ctor/Open/Read/Seek/GetDataPointer/Close/dtor calls; DATFile::Open has 47 image-family call sites in 21 functions | DAT-backed consumption by ImageLib/ResourceLayout code does not transfer source ownership. |

## Documentation Evidence And IDA Status

- Historical pre-callback evidence: although `client_containers` and the DATIndex pages already contained the 2026-08-17 standard-container correction, the DATFileMgr pages still preserved a synthetic authored `DATFileResolver` and node-helper model contradicted by bounded reanalysis. The accepted callback superseded that defect: current DATFileMgr documentation classifies the resolver/node/hash bodies as compiler-generated standard-container lowering and expresses the authored manager state through typed `stdext::hash_map`/vector source.
- The callback preserved the already-correct DATIndexVector file/class/exact disposition: path `NONE`, false reconstruction, no emitters, and superseded custom-source history retained explicitly as history.
- Historical pre-callback evidence: UID0000IM, `client_dat_specifications`, and `proposed-source-tree` still retained the rejected standalone DATIndex and/or three-file umbrella model. The accepted callback repaired those ordinary pages to the two authored `DATFile`/`DATFileMgr` unit disposition; only the collision-prone manual coverage rows remain stale, unapplied, and supervisor-owned.
- Historical pre-callback evidence: DATFile generated output was materially incomplete, and manager include/type order, typed map source shape, the direct container error path, and the `Error.h` dependency were not source-closed. The accepted callback repaired the owning ordinary documentation, and fresh physical readback after waited command `000000025893` found all eighteen DATFile authored bodies, complete DATFile/DATFileMgr headers, dependencies before manager definitions, typed source-level containers, no synthetic resolver/node helper definitions, and the complete `FileError` declaration; later generated identity remains dynamic and requires fresh supervisor readback.
- IDA has source-quality function names on much of the core island but retains `unk_67AB40` as one-byte untyped storage. No DATArchive IDA mutation is warranted.
- UID0000QU, UID0001OQ, UID0000K2, and UID00006E already agree on ImageLib ownership, sole declaration, lifecycle writes/clears, and no duplicate global definition. Live IDA's `ResourceLayoutTable *` spelling is the compatibility-facet view, not evidence for DATArchive ownership or a second resource object.

## Ranked Ownership Analysis

### 1. Two concrete authored units: DATFile and DATFileMgr
- Evidence for: independent RTTI/vtables/types, coherent method clusters, direct API boundary, current generated stems, human source roles.
- Evidence against: original private-header spelling and exact member names are inferred.
- Decision: accepted.

### 2. DATArchive folder/module umbrella
- Evidence for: useful conceptual map and broad dependencies.
- Evidence against: no source identity or owned entity.
- Decision: retain only as path-NONE documentation index.

### 3. Standalone DATIndexVector
- Evidence for: historical recovery label and shared address family.
- Evidence against: exact standard-container layout and broad differently typed consumer fanout; no source identity.
- Decision: rejected and historicalized.

### Proposed new file/grouping, if applicable
- No new authored file. Repair existing `DATFile.cpp/.h` and `DATFileMgr.cpp/.h` formal routes.
- Proposed exact by-memory child splits under UID0000IN are implementation artifacts, not new historical source files.

## Source Placement

- `NexusTK/archive/DATFile.cpp/.h`: DATFile's sixteen authored class methods, packed-record/container use, DecodeTableValue, and LoadDatFileBuffer. Base `File::ReadLine(StringBaseW&)` remains in File source even though the DAT translation unit retained an identical compiler copy.
- `NexusTK/archive/DATFileMgr.cpp/.h`: DATFileMgr, `_DATFileMgr`, DATFileContainer, DATEntryRecord, DATEntryLocation, typed `stdext::hash_map`/vector members, singleton, and HasDATEntry. `DATFileResolver` and node/hash helpers are not authored declarations/functions.
- `NexusTK/util/Error.cpp/.h`: FileError declaration and implementation remain Error-owned; DATFile only includes Error.h and throws the existing class.
- `NexusTK/render/ImageLib.cpp/.h`: `g_pEPFLib` declaration/lifecycle/resource-layout behavior remains ImageLib-owned. DATFile is an included/called dependency for resource loading; no UID0000QU source moves into `archive/`.
- No `DATArchive.*` and no `DATIndexVector.*`.
- Application numbered-load/cleanup logic stays in `app/Application.cpp`; audio/render/palette/image code stays with its feature owner; codec source stays in vetted third-party routes.
- Exact original private-header split is not recoverable. Using existing public `DATFileMgr.h` for the shared packed record/container declaration is the least-inventive source-closed route and does not create an evidence-free third source file.

## Range / Split / Padding / Reclassification Analysis

- UID00012D remains a non-emitting mixed aggregate; exact DATFile method ranges must route through exact children. Do not emit the broad aggregate. The `0x0049c570` retained wide-line copy receives an exact no-code child/covered-by disposition tied to `File::ReadLine(StringBaseW&)`.
- `0x0049d280-0x0049d2cc` is scalar deleting-destructor lowering and emits no authored source.
- DATFileLayout and DATFileVtable are source-semantic/compiler evidence already expressed by the class H and virtual methods; clear their emitters rather than emitting comments/markers.
- DATIndex exact bodies and DAT manager-local `0x0049cbb0`, `0x0049ce50`, `0x0049d190`, `0x0049d490`, `0x0049d5e0` retain exact ranges/bytes/xrefs as non-emitting compiler products. Source uses typed owner-local standard containers.
- The DAT record remains exactly 17 bytes with `startOffset` at `+0x00` and `name[13]` at `+0x04`; payload length uses the next row's `startOffset`.
- Adjacent DescPane starts at `0x0049d6f0`; it is not archive code.

## Negative Evidence Summary

- No current `DATArchive` function, UDT, vtable, RTTI, string, symbol, export, global, resource, import, or generated artifact.
- No current `DATIndexVector` or `DATFileResolver` project UDT, constructor identity, RTTI, standalone vtable, global, export, or unique source owner.
- Consumer calls to DAT APIs do not transfer source ownership.
- In particular, UID0000QU's 231-xref render singleton remains ImageLib-owned: DATFile calls made by ResourceLayout/ImageLib methods do not transfer its global storage, lifecycle, declaration, or resource-table state into DATArchive.
- Recovery filenames are not original-symbol proof.
- The broad target range cannot be made one source unit without merging unrelated render/audio/application/third-party code.
- A new `DATArchiveInternal.h` was rejected because there is no evidence for a third archive source artifact; existing DATFileMgr H can carry the shared record/container/location declarations, while `_DATFileMgr` and its map comparator remain CPP-local.
- Undefined generated helpers `ShowDATFileError` and `ShowDATFileMapError` are rejected: live code directly formats `L"UNICreateFileMapping : %s"` or `L"MapViewOfFile : %s Err %d"`, calls `MessageBoxW` with the pooled error caption and `0x30`, then throws a heap-allocated `Win32Error *`.

## IDA Rename / Type / Comment Recommendations

UID0000IM has no actionable IDA entity. The only high-confidence cross-page correction exposed by this pass is the manager singleton storage.

| ID | Classification | Public endpoint and literal action | Literal prestate | Protected state | Deterministic expected poststate / hard stop |
| --- | --- | --- | --- | --- | --- |
| A01-D | apply | `make_data`, one item `{addr:"0x0067ab40", type:"DATFileMgr *g_pDATFileMgr", name:"g_pDATFileMgr", delete_existing:true}` | Head `0x67ab40`, end `0x67ab41`, size 1, name `unk_67AB40`, type absent, AR absent, AP absent, four target bytes `00 00 00 00` | Preserve bytes `0x0067ab3c-0x0067ab47` as twelve zero bytes; preserve all 24 exact xrefs; preserve preceding `CheatDetector *` at `0x0067ab3c` and next `InputMan *` at `0x0067ab44`; no function/segment/boundary change | Head `0x67ab40`, end `0x67ab44`, size 4, name `g_pDATFileMgr`, type `DATFileMgr *`, AR absent, AP absent, same 24 xrefs/bytes/neighbors. Stop without save on any mismatch. |
| A01-C | apply | `set_address_repeatable_comments` at `0x0067ab40` to exactly `Global DATFileMgr singleton pointer; source definition and lifecycle belong to archive/DATFileMgr.cpp.` | A01-D exact poststate; AR absent; AP absent | Preserve A01-D name/type/size/bytes/xrefs/neighbors | Same complete item state, AR absent, AP exact proposed text. Stop without save on any other delta. |
| P01 | no change recommended | No DATArchive or DATIndexVector entity creation/rename/type/comment | No such project entity exists | Preserve all concrete owner functions/types/ranges and DATIndex compiler bodies | No new entity; source correction remains documentation-only. |

Supervisor Gate 2B must use a fresh canonical session selected immediately before action, public schema-1 runtime attestation, backup, staged readbacks, durable save, and fresh post-save readback under the supervisor workflow. This report provides semantic handoff only, not an executable transaction package.

## First-Draft C++ Recommendation

UID0000IM exact target disposition: no CPP block, no H block, no header, no source file. The following are formal insertion texts for owning support pages; they are not DATArchive code.

UID0000UC `RECONSTRUCTION_H CODE` in DATFileMgr H, position 5:

```cpp
#pragma pack(push, 1)
struct DATEntryRecord
{
    unsigned int startOffset;
    char name[13];
};
#pragma pack(pop)

typedef char DATEntryRecordSizeMustBe0x11[
    sizeof(DATEntryRecord) == 0x11 ? 1 : -1];
```

UID00003H formal channel replacement: CPP contains only `[[CHILDREN]]`; H contains the shared declaration:

```cpp
#include <windows.h>

class DATFile;
class _DATFileMgr;

class DATFileContainer
{
    friend class DATFile;
    friend class _DATFileMgr;

public:
    DATFileContainer(const wchar_t *path);
    virtual ~DATFileContainer();

private:
    HANDLE m_fileHandle;
    HANDLE m_mappingHandle;
    void *m_mappedView;
    unsigned int m_finalPayloadOffset;
    unsigned int m_entryCount;
    DATEntryRecord *m_entries;
};

struct DATEntryLocation
{
    DATFileContainer *archive;
    unsigned int index;
};

typedef char DATEntryLocationSizeMustBe0x08[
    sizeof(DATEntryLocation) == 0x08 ? 1 : -1];
```

UID00003I formal CPP preamble before all manager children:

```cpp
#include "DATFileMgr.h"
#include "DATFile.h"
#include "../util/Error.h"
#include "../util/File.h"
#include "../util/PathUtil.h"
#include <hash_map>
#include <stdio.h>
#include <vector>
#include <wchar.h>

[[CHILDREN]]
```

UID000004 private class formal CPP replacement. UID00003J and the five node/hash helper pages receive blank formal channels because this standard-container source generates their lowering:

```cpp

namespace
{
struct DATEntryNameHashCompare
{
    enum { bucket_size = 4, min_buckets = 8 };

    size_t operator()(const StringBaseW &name) const
    {
        size_t hash = 0;
        const wchar_t *current = name.c_str();
        while (*current != L'\0') {
            hash = *current++ + 5 * hash;
        }
        return hash;
    }

    bool operator()(const StringBaseW &left,
                    const StringBaseW &right) const
    {
        return mystr::WideRangeCompare(
                   left.c_str(), left.c_str() + left.length(),
                   right.c_str(), right.c_str() + right.length()) < 0;
    }
};
}

class _DATFileMgr
{
public:
    virtual ~_DATFileMgr();

    bool LoadDATFileIndex(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName,
                         DATEntryLocation *outLocation);

private:
    typedef stdext::hash_map<
        StringBaseW,
        DATEntryLocation,
        DATEntryNameHashCompare> EntryMap;

    EntryMap m_entriesByName;
    std::vector<DATFileContainer *> m_archiveContainers;
};

[[CHILDREN]]
```

Exact formal CPP bodies for UID00043B/UID00043C and the authored `_DATFileMgr` destructor/load/find children follow. These fragments belong on those exact children and expand through the UID000004 marker; they are not duplicated in the by-file preamble:

```cpp

DATFileContainer::DATFileContainer(const wchar_t *path)
    : m_fileHandle(INVALID_HANDLE_VALUE),
      m_mappingHandle(NULL),
      m_mappedView(NULL),
      m_finalPayloadOffset(0),
      m_entryCount(0),
      m_entries(NULL)
{
    wchar_t retryPath[80] = L"..\\";

    m_fileHandle = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ,
                               NULL, OPEN_EXISTING,
                               FILE_ATTRIBUTE_NORMAL, NULL);
    if (m_fileHandle == NULL || m_fileHandle == INVALID_HANDLE_VALUE) {
        wcscat_s(retryPath, 80, path);
        m_fileHandle = CreateFileW(retryPath, GENERIC_READ,
                                   FILE_SHARE_READ, NULL, OPEN_EXISTING,
                                   FILE_ATTRIBUTE_NORMAL, NULL);
    }

    if (m_fileHandle == NULL || m_fileHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    m_mappingHandle = CreateFileMappingW(
        m_fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
    if (m_mappingHandle == NULL) {
        wchar_t message[176];
        swprintf_s(message, 176, L"UNICreateFileMapping : %s", path);
        MessageBoxW(NULL, message, L"\xC624\xB958", MB_ICONWARNING);
        throw new Win32Error();
    }

    m_mappedView = MapViewOfFile(
        m_mappingHandle, FILE_MAP_READ, 0, 0, 0);
    if (m_mappedView == NULL) {
        DWORD error = GetLastError();
        wchar_t message[256];
        swprintf_s(message, 256,
                   L"MapViewOfFile : %s Err %d", path, error);
        MessageBoxW(NULL, message, L"\xC624\xB958", MB_ICONWARNING);
        throw new Win32Error();
    }

    m_entryCount = *static_cast<unsigned int *>(m_mappedView);
    m_entries = reinterpret_cast<DATEntryRecord *>(
        static_cast<unsigned char *>(m_mappedView) + 4);
    m_finalPayloadOffset = m_entries[m_entryCount - 1].startOffset;
}

DATFileContainer::~DATFileContainer()
{
    if (m_mappedView != NULL) UnmapViewOfFile(m_mappedView);
    if (m_mappingHandle != NULL) CloseHandle(m_mappingHandle);
    if (m_fileHandle != NULL && m_fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(m_fileHandle);
    }
}

_DATFileMgr::~_DATFileMgr()
{
    for (std::vector<DATFileContainer *>::iterator current =
             m_archiveContainers.begin();
         current != m_archiveContainers.end(); ++current) {
        delete *current;
    }
}

bool _DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)
{
    wchar_t retryPath[80] = L"../";
    wcscat_s(retryPath, 80, archivePath);
    if (!FileExists(archivePath) && !FileExists(retryPath)) {
        return false;
    }

    DATFileContainer *archive = new DATFileContainer(archivePath);
    m_archiveContainers.push_back(archive);

    for (unsigned int index = 0; index < archive->m_entryCount; ++index) {
        StringBaseA narrowName(archive->m_entries[index].name);
        if (narrowName.empty()) {
            continue;
        }

        _strupr_s(narrowName.data(), narrowName.length() + 1);
        StringBaseW normalizedName(narrowName);
        if (m_entriesByName.find(normalizedName) ==
            m_entriesByName.end()) {
            DATEntryLocation location;
            location.archive = archive;
            location.index = index;
            m_entriesByName.insert(
                EntryMap::value_type(normalizedName, location));
        }
    }
    return true;
}

bool _DATFileMgr::FindEntryByName(
    const wchar_t *entryName, DATEntryLocation *outLocation)
{
    StringBaseW normalizedName(entryName);
    _wcsupr_s(normalizedName.data(), normalizedName.length() + 1);

    EntryMap::const_iterator found = m_entriesByName.find(normalizedName);
    if (found == m_entriesByName.end()) {
        return false;
    }
    if (outLocation != NULL) {
        *outLocation = found->second;
    }
    return true;
}
```

The comparator name is inferred source-facing spelling, but its two operations are not speculative: live bodies prove the `ch + 5 * hash` loop and the same wide-range comparison used in both directions by Dinkumware `hash_compare`. The default map construction exactly explains the 0x20 subobject, `1.0f` load factor, list sentinel, and eight buckets. Do not emit `CreateDATEntryNode`, `AllocateDATEntryNode`, `DATFileResolver::InsertOrFindEntry`, `DATFileResolver::FindNodeByKey`, or `DATFileResolver::~DATFileResolver`; those are the compiler's implementation of this declaration.

UID00003G complete formal H replacement; the accepted exact child pages supply bodies. There is no DATFile declaration for `0x0049c570`, because the source declaration already exists on `File`:

```cpp
#ifndef NEXUSTK_ARCHIVE_DAT_FILE_H
#define NEXUSTK_ARCHIVE_DAT_FILE_H

#include "../util/File.h"
#include <vector>

class DATFileContainer;
struct DATEntryRecord;

class DATFile : public File
{
public:
    DATFile();
    virtual ~DATFile();

    virtual void Open(const wchar_t *path);
    virtual bool Close();
    virtual int GetPosition();
    virtual bool Seek(int offset, int origin);
    virtual int GetSize();
    virtual size_t Read(void *buffer, int count);
    virtual bool ReadLine(StringBaseA &line);
    virtual int ReadLineChars(char *buffer, int limit);

    int ReadEncodedTableInt(int *outValue);
    int ReadEncodedTableFloat(float *outValue);
    bool IsOpen() const;
    void *GetDataPointer() const;
    void ReadAllLines(std::vector<StringBaseW> &lines);
    int OpenByIndex(DATFileContainer *archive, int index);

private:
    DATFileContainer *m_archive;
    const DATEntryRecord *m_entry;
    int m_position;
    int m_size;
};

typedef char DATFileSizeMustBe0x14[
    sizeof(DATFile) == 0x14 ? 1 : -1];

char *__stdcall LoadDatFileBuffer(
    const wchar_t *path, int prefixSize, int *outSize);

#endif
```

UID00003G exact CPP preamble:

```cpp
#include "DATFile.h"
#include "DATFileMgr.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"
#include <string.h>

[[CHILDREN]]
```

Exact formal CPP bodies for the missing authored DATFile child pages follow in physical order. They expand through the UID00003G marker and are not duplicated in its class-level channel:

```cpp

DATFile::DATFile()
    : m_archive(0), m_entry(0)
{
}

DATFile::~DATFile()
{
    m_entry = 0;
    m_archive = 0;
}

void DATFile::Open(const wchar_t *path)
{
    DATEntryLocation location;
    if (!g_pDATFileMgr->FindEntryByName(path, &location)) {
        throw new FileError(path);
    }

    m_archive = location.archive;
    m_entry = m_archive->m_entries + location.index;
    m_position = m_entry->startOffset;
    m_size = (m_entry + 1)->startOffset - m_entry->startOffset;
}

bool DATFile::Close()
{
    if (m_archive == 0 || m_entry == 0) {
        return false;
    }
    m_entry = 0;
    m_archive = 0;
    return true;
}

bool DATFile::Seek(int offset, int origin)
{
    if (m_archive == 0 || m_entry == 0) {
        return false;
    }

    int position;
    if (origin == 0) {
        if (offset < 0 || offset >= m_size) return false;
        position = m_entry->startOffset + offset;
    } else if (origin == 1) {
        position = m_position + offset;
        if (position < static_cast<int>(m_entry->startOffset) ||
            position >= static_cast<int>((m_entry + 1)->startOffset)) return false;
    } else if (origin == 2) {
        if (offset < 0 || offset >= m_size) return false;
        position = (m_entry + 1)->startOffset - offset;
    } else {
        return false;
    }

    m_position = position;
    return true;
}

int DATFile::GetPosition()
{
    return m_archive != 0 && m_entry != 0
        ? m_position - m_entry->startOffset : -1;
}

int DATFile::GetSize()
{
    return m_archive != 0 && m_entry != 0 ? m_size : -1;
}

size_t DATFile::Read(void *buffer, int count)
{
    if (m_archive == 0 || m_entry == 0) return 0;
    size_t readSize = count < 0 ? m_size : static_cast<size_t>(count);
    if (m_position + readSize > (m_entry + 1)->startOffset) return 0;
    memmove(buffer,
            static_cast<unsigned char *>(m_archive->m_mappedView) + m_position,
            readSize);
    m_position += readSize;
    return readSize;
}

bool DATFile::IsOpen() const
{
    return m_entry != 0;
}

void *DATFile::GetDataPointer() const
{
    if (m_archive == 0 || m_entry == 0) return 0;
    return static_cast<unsigned char *>(m_archive->m_mappedView) + m_position;
}

int DATFile::ReadLineChars(char *buffer, int limit)
{
    if (m_archive == 0 || m_entry == 0) {
        return -1;
    }

    int scan = m_position;
    const int end = (m_entry + 1)->startOffset;
    if (scan < end) {
        while (true) {
            const char current = static_cast<const char *>(
                m_archive->m_mappedView)[scan];
            if (current == '\r') {
                ++scan;
                break;
            }
            if (current == '\n') {
                break;
            }
            if (++scan >= end) {
                break;
            }
        }
    }

    const int count = scan - m_position + 1;
    if (count <= 0 || count > limit) {
        return -1;
    }
    memmove(buffer,
            static_cast<const char *>(m_archive->m_mappedView) + m_position,
            count);
    m_position += count;
    return count;
}

bool DATFile::ReadLine(StringBaseA &line)
{
    StringBaseA result;
    if (m_archive == 0 || m_entry == 0) {
        return false;
    }

    const int end = (m_entry + 1)->startOffset;
    if (m_position >= end) {
        return false;
    }

    int scan = m_position;
    while (true) {
        const char current = static_cast<const char *>(
            m_archive->m_mappedView)[scan];
        if (current == '\r') {
            ++scan;
            break;
        }
        if (current == '\n') {
            break;
        }
        result.append(1, current);
        if (++scan >= end) {
            break;
        }
    }

    const int count = scan - m_position + 1;
    if (count <= 0) {
        return false;
    }
    m_position += count;
    line = result;
    return true;
}

void DATFile::ReadAllLines(std::vector<StringBaseW> &lines)
{
    lines.clear();
    StringBaseW line;
    while (File::ReadLine(line)) {
        lines.push_back(line);
    }
}

int DATFile::OpenByIndex(DATFileContainer *archive, int index)
{
    m_archive = archive;
    m_entry = archive->m_entries + index;
    m_position = m_entry->startOffset;
    m_size = (m_entry + 1)->startOffset - m_entry->startOffset;
    return m_size;
}
```

The CR/LF increments above deliberately preserve the observed binary behavior, including the extra consumed byte after CR and the inclusive `+1` count. `ReadAllLines` deliberately calls the inherited nonvirtual wide helper, which dispatches through the ANSI virtual slot; that explains the inlined conversion in `0x0049c600`. The identical `0x0049c570` and `0x004b1340` bodies have zero inbound callers and receive no second authored body.

UID00004X/UID0000J5 formal H addition required by the exact `DATFile::Open` source body:

```cpp
class FileError : public Error
{
public:
    FileError(const wchar_t *path);
    virtual int FormatErrorMessage(
        wchar_t *destination,
        size_t destinationChars) const;

private:
    wchar_t m_message[80];
};

typedef char FileErrorSizeMustBe0xA4[
    sizeof(FileError) == 0xA4 ? 1 : -1];
```

`FileError` remains Error-owned. DATFile.cpp only includes Error.h and uses the already proven `throw new FileError(path)` path; it does not duplicate the constructor or message-copy method.

UID0001WS/UID0000OA exact declaration addition inside the existing `StringBase` template's public section, required by the live ANSI line body:

```cpp
StringBase& append(unsigned int count, CharT character);
```

This overload is not invented convenience syntax. Live `0x00584200` takes `(size_t count, char character)`, fills exactly `count` bytes, updates length/NUL state, and returns `this`; DATFile's call is exactly `(1, current)`. On the 32-bit target, `size_t` and `unsigned int` share the observed four-byte ABI.

DATFileLayout, DATFileVtable, scalar deleting destructor, the duplicate wide-line body, DATFileResolver, manager node/hash helpers, all DATIndex bodies/types, RTTI/vtable data, and alias pages remain blank/no-code. Their behavior is represented by human class declarations/methods or typed standard-container consumer source.

## Final Recommendation

- Applied: UID0000IM is a no-source index without pruning valid evidence.
- Applied: concrete DATFile/DATFileMgr documentation and formal routing now carries eighteen authored DATFile.cpp bodies, source-facing manager/container/map code, and no authored duplicate wide helper, synthetic resolver, node/hash internals, or invented error helpers.
- Applied: the existing Error-owned `FileError` class declaration closes DATFile.cpp without transferring Error implementation ownership into archive source.
- Applied: the exact two-unit source split and all consumer exclusions are preserved.
- Preserve UID0000QU/UID0001OQ/UID0000K2/UID00006E as the already-correct ImageLib global/storage/file/class chain; DAT-backed resource loads remain consumer edges only.
- Applied in ordinary docs: DATIndex standalone source references were removed from the current source tree, DAT spec, and umbrella while superseded history remains. Manual coverage is still supervisor-owned.
- Remaining supervisor action: apply only the accepted singleton IDA handoff; never create a DATArchive IDA entity.
- No unresolved ownership, range, compiler/source, dependency, or umbrella-source question remains. Original lexical spellings remain inferred but have high-probability human-source resolutions.

## Recommended Target Doc Changes

The following accepted target package is now applied and physically reread; it remains here as the exact callback record rather than future work.

- Path: `by-file/DATArchive.md`.
- Metadata: `COMPLETION:97`, `CONFIDENCE:98`, path `NONE`, owner `NONE`, add `RECONSTRUCTABLE:FALSE`.
- Replace Status/Hypothesis/Current File Split/Proposed Split/Open Questions with the proven non-emitting index, exact two-unit split, compiler DATIndex disposition, generated audit, and resolved ownership matrix.
- Preserve the 17-byte record/package evidence, exact API boundaries, helper ranges, render/audio/application exclusions, historical corrections, and cross-references.
- Keep no formal CPP/H and explicitly state no DATArchive source/header/generated artifact.

## Recommended Support Doc Changes

The following accepted support package is now applied or, where explicitly labeled already correct, verified unchanged. Imperative wording records the accepted action rather than an outstanding B006 task.

- `by-file/DATFile.md`: exhaustive sixteen-method/three-compiler-product inventory, fourteen missing generated bodies, packed record/shared-header route, exact line semantics, generated acceptance contract, 94/95 provisional metadata.
- `by-class/DATFile.md`: complete typed H and declarations with `std::vector<StringBaseW>`; retain exact 0x14 layout; no redundant wide ReadLine declaration; position 10.
- `by-item/DATEntryRecord.md`: close spelling/placement blocker with inferred packed declaration, owner/emitter UID0000IO, position 5, 94/96.
- `by-class/DATFileContainer.md`: H declaration plus DATFile/private-manager friends; exact direct formatting/MessageBox/heap Win32Error behavior; CPP children only; score 92/94.
- `by-class/DATFileMgr.md`: complete `DATEntryLocation`, CPP preamble/includes before children, public wrapper/source behavior; 94/95.
- `by-class/_DATFileMgr.md`: replace synthetic resolver declaration with typed `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>` and vector; keep only destructor/load/find authored children; 94/96.
- `by-class/DATFileResolver.md`: historical semantic overlay only; set path/owner/emitter none, reconstructable false, blank formal code, 96/97.
- Exact manager node/hash pages `UID00043F`, `UID00043G`, `UID00012H`, `UID00043H`, and `UID00043I`: preserve complete binary behavior/history but set non-reconstructable/no owner/no emitter/blank formal because typed map source generates them.
- `by-type/by-struct/DATFileLayout.md`: false/no emitter/no formal, 95/97.
- `by-type/by-vtable/DATFileVtable.md`: false/no emitter/no formal, 95/97.
- `by-memory/0x0049c130-0x0049d2cc.DATFile.md`: complete split map and exact planned children; retain aggregate false/no emitter; classify `0x0049c570` as covered compiler duplicate.
- New exact DATFile child pages for core methods, line/accessor methods, and OpenByIndex using ranges above; add an exact no-code child for the duplicate wide helper; no additional report target credit until each receives its own UID/evidence/validation.
- `by-file/DATFileMgr.md`: exact shared dependency, typed map source/compiler split, direct container errors, and generated compile-closure notes; 94/95.
- `by-class/FileError.md` and `by-file/Error.md`: add complete 0xa4 `FileError` H declaration while preserving Error ownership and exact existing constructor/copy-message children.
- `by-type/by-template/StringBaseTemplate.md` and `by-file/StringBase.md`: add the exact count/character `append` declaration needed by the already-implemented `0x00584200` template body; preserve all current ownership and other overloads.
- `by-file/DATIndexVector.md`, `by-class/DATIndexVector.md`, seven exact pages, bucket/node overlays: verify current no-source state; preserve history, no semantic rollback.
- `by-global/g_pEPFLib.md`, `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md`, `by-file/ImageLib.md`, and `by-class/ImageLib.md`: already correct; preserve UID0000K2 ownership, UID00006E sole `extern ImageLib *g_pEPFLib` declaration, UID0001OQ storage route, lifecycle writes/clears, broad render fanout, and compatibility-facet history. No score, emitter, formal-source, or ownership change is recommended.
- `by-meta/client_dat_specifications.md`: replace all standalone DATIndex/current three-module claims.
- `by-meta/client_containers.md`: already correct; verify only.
- `by-project-structure/proposed-source-tree.md`: remove tree node/section and update archive rationale/research priorities.
- Manual coverage pages: supervisor applies exact text below.

## Score And Metadata Recommendation

- UID0000IM assignment-time state: 89/87, path archive, owner FILE, reconstructable absent.
- UID0000IM applied/current state: 97/98, path NONE, owner NONE, reconstructable false.
- Reason not higher: exact original documentation/file nomenclature is unrecoverable and the umbrella was created by reconstruction work, not proven original source metadata.
- Reason not lower: exhaustive binary/type/xref/generated/source-route evidence proves zero owned entities, exactly two concrete source units, and compiler DATIndex disposition; every linked candidate has a destination/exclusion.
- Score-improvement attempts: symbol/type/string/export search, full core range inventory, generated output audit, historical report search, DATIndex fanout/type reanalysis, package evidence, manual coverage/source-tree comparison. Each former blocker is resolved to source, compiler/no-code, or explicit consumer ownership.
- Support provisional scores after callback: DATFile file/class 94/95; DATFileMgr file/class 94/95; `_DATFileMgr` 94/96; DATEntryRecord 94/96; DATFileContainer 92/94; FileError/Error scores retained unless their owning pass justifies a change; DATFileResolver 96/97 false/no emitter; DATFileLayout and DATFileVtable 95/97 false/no emitter. Keep DATIndex current scores.

## Open Questions With Attempted Resolution

- Did a literal `DATArchive.cpp` exist? Bounded current symbol/type/generated/range searches found no evidence; concrete files fully explain the archive code. Resolution: high-probability no.
- Was DATIndexVector handwritten? Complete seven-body/caller/type analysis rejects it. Resolution: compiler/template lowering.
- Where did the shared record/container declaration live? Existing two-file constraint, direct cross-use, and no evidence for a third header favor `DATFileMgr.h`; exact original private/public header spelling is lexical uncertainty only and does not block source closure.
- Exact DATFile field/method spellings? Current names are consistent with File/DAT manager conventions and behavior. Original spellings are not recoverable; use realistic inferred names, never raw labels.
- Was `DATFileResolver` an original helper class? Fresh constructor/load/find/insert/destroy reanalysis resolves every field and helper as Dinkumware `stdext::hash_map` lowering. Resolution: no authored resolver class; retain historical label only as an analysis overlay.
- Is `0x0049c570` a second source overload? It is identical to base `File::ReadLine(StringBaseW&)`, both copies have zero inbound xrefs, and `ReadAllLines` inlines the same base helper. Resolution: compiler-retained duplicate, no DATFile declaration/body.
- How are mapped-container errors expressed? Exact UTF-16 bytes and live control flow prove direct formatting of `UNICreateFileMapping`/`MapViewOfFile` messages, `MessageBoxW(..., L"\xC624\xB958", 0x30)`, and `throw new Win32Error()`. Resolution: remove invented helper calls.
- Older package final-row bytes? Current 250-file audit proves executable behavior needed for this build. Older-package variation does not alter code-side next-offset semantics or source disposition.
- Render grouping questions in the old umbrella are outside DAT ownership and already have concrete owner pages; they are not unresolved UID0000IM blockers.
- Does DAT-backed use make UID0000QU archive-owned? No. Live evidence gives ImageLib lifecycle-only writes/clears, 231 render/UI data xrefs, no direct DAT-core xref, and a separate call boundary where ImageLib/ResourceLayout methods instantiate and drive DATFile. Resolution: preserve ImageLib ownership with very high confidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

`by-file/-coverage-report.md` replace UID0000IM-0000IP rows with:

- `[UID:0000IM][DATArchive](by-file/DATArchive.md) : non-reconstructable : 97% : very-strong : Reviewed path-NONE archive-subsystem documentation index; exhaustive current IDA/type/xref/generated audit proves no DATArchive source unit or owned entity, exactly two authored archive files DATFile/DATFileMgr, compiler-folded DATIndex standard-container support, complete consumer exclusions, and blank source disposition.`
- `[UID:0000IN][DATFile](by-file/DATFile.md) : reconstructable : 94% : very-strong : Concrete archive reader source owner with complete method/range inventory, packed 17-byte record dependency, exact DATFile class/header and source-child plan, encoded scalar and buffer helpers, compiler/no-code products, broad caller evidence, and generated zero-empty-marker acceptance contract.`
- `[UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) : reconstructable : 94% : very-strong : Concrete archive manager source owner for DATFileMgr, _DATFileMgr, DATFileContainer, singleton, HasDATEntry, packed record/location declarations, exact authored core ranges, typed stdext::hash_map/vector source consequences, compiler-covered node/hash internals, direct mapped-file error behavior, and source-closed CPP/H dependency order.`
- `[UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) : non-reconstructable : 96% : very-strong : Path-NONE non-emitting old-MSVC/Dinkumware stdext::hash_map compiler-family index; seven exact folded helper ranges, 0x20 semantic overlay, consumer-specific typed source consequences, broad FittingRoom/MiniMap/DAT/Monster fanout, and rejected standalone DATIndexVector.cpp/.h hypothesis documented.`

`by-class/-coverage-report.md` replacement rows:

- `[UID:00003G][DATFile](by-class/DATFile.md) : reconstructable : 94% : very-strong : Complete 0x14 File-derived DAT reader declaration with typed archive/record fields, exact virtual and nonvirtual method inventory, signed-count read behavior, packed-record use, source children, and compiler-covered vtable/deleting-wrapper disposition.`
- `[UID:00003H][DATFileContainer](by-class/DATFileContainer.md) : reconstructable : 92% : very-strong : Complete mapped DAT container declaration in DATFileMgr.h with 0x1c layout, packed record pointer, DATFile friend access, exact constructor/destructor behavior, source placement, and CPP child route.`
- `[UID:00003I][DATFileMgr](by-class/DATFileMgr.md) : reconstructable : 94% : very-strong : Public Singleton<DATFileMgr> wrapper with exact 0x08 layout, complete DATEntryLocation-aware H, dependency-complete DATFileMgr CPP preamble, internal manager ownership, singleton declaration, and exact method/source route.`
- `[UID:00003J][DATFileResolver](by-class/DATFileResolver.md) : non-reconstructable : 96% : very-strong : Historical non-emitting semantic overlay for the 0x20 old-MSVC/Dinkumware stdext::hash_map member at _DATFileMgr+0x04; default sentinel/load-factor/eight-bucket state, hash/compare, insert/find/rehash and destruction lowering are preserved, while source is the typed owner-local map declaration and all owner/emitter/formal channels are blank.`
- `[UID:00003K][DATIndexVector](by-class/DATIndexVector.md) : non-reconstructable : 95% : very-strong : Non-emitting 0x20 standard hash-container semantic/compiler overlay with seven exact folded bodies, consumer-specific mapped types, no project UDT/vtable/RTTI/constructor/global, and blank owner/emitter/formal channels.`

Other exact rows:

- `by-item/-coverage-report.md`: `[UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md) : reconstructable : 94% : very-strong : Source-ready packed 17-byte record declared through DATFileMgr.h with uint32 startOffset at +0x00 and char name[13] at +0x04; DATFileContainer mapping, DATFile next-row payload sizing, manager indexing, and 250-file package audit prove layout and boundary-row semantics.`
- `by-type/by-struct/-coverage-report.md`: `[UID:0003H3][DATFileLayout](by-type/by-struct/DATFileLayout.md) : non-reconstructable : 95% : very-strong : Non-emitting semantic layout overlay for the exact 0x14 DATFile class; UID00003G H is the sole human source declaration, while constructor/Open/read/vtable/deleting-wrapper evidence remains preserved here.`
- `by-type/by-vtable/-coverage-report.md`: `[UID:0003I0][DATFileVtable](by-type/by-vtable/DATFileVtable.md) : non-reconstructable : 95% : very-strong : Non-emitting compiler vtable evidence for DATFile; exact 0x00618920-0x00618950 locator/slot record, constructor install, targets, and signature are preserved, while source is generated only from UID00003G virtual declarations/definitions.`
- `by-global/-coverage-report.md`: `[UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) : reconstructable : 90% : very-strong : DATFileMgr singleton pointer at 0x0067ab40 with exact zero initializer, 24-xref lifecycle, public-wrapper/internal-manager distinction, source definition/extern route, startup/shutdown and DAT API consumers, and deterministic supervisor IDA data/comment handoff.`

`by-memory/-coverage-report.md` replace stale DATIndex rows and insert UID0004HG adjacent to UID0000WW:

- `[UID:0002U7][0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper](by-memory/0x004233f0-0x00423465.DATIndexVectorFillValueRangeHelper.md) 0x004233f0-0x00423465 | compiler-generated fill lowering | paired bucket-range value fill : non-reconstructable : 92% : very-strong : Exact bounds, two internal resize/fill call sites, no standalone owner/API, and blank owner/emitter/formal channels; source is represented by typed owner-local standard-container construction.`
- `[UID:0000WW][0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill](by-memory/0x00423b00-0x00423c3d.DATIndexVectorResizeAndFill.md) 0x00423b00-0x00423c3d | compiler-generated hash-container lowering | bucket-vector resize/fill : non-reconstructable : 95% : very-strong : Fourteen cross-subsystem callers, exact paired-slot behavior, allocator paths and mask/count writes prove old-MSVC/Dinkumware folded template support rather than custom DAT source.`
- `[UID:0004HG][0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity](by-memory/0x00423c50-0x00423cf6.DATIndexVectorEnsureBucketStorageCapacity.md) 0x00423c50-0x00423cf6 | compiler-generated vector lowering | bucket storage capacity helper : non-reconstructable : 92% : very-strong : Exact one-caller allocation/copy/free/commit body is compiler support for the folded hash bucket vector; no source owner/emitter/formal code.`
- `[UID:0000XS][0x00457100-0x0045730f.DATIndexVectorInsertNode](by-memory/0x00457100-0x0045730f.DATIndexVectorInsertNode.md) 0x00457100-0x0045730f | compiler-generated hash-map lowering | insert/rehash result lowering : non-reconstructable : 94% : very-strong : Exact FNV traversal, list/bucket repair, rehash and hidden result-slot behavior shared by differently typed MiniMap/Monster consumers; no custom project method emission.`
- `[UID:0000XT][0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper](by-memory/0x00457310-0x004573b3.DATIndexVectorRemoveNodeHelper.md) 0x00457310-0x004573b3 | compiler-generated unwind cleanup | insert-failure node cleanup : non-reconstructable : 92% : very-strong : Sole EH caller, exact unlink/bucket repair/free behavior, and no public erase route prove compiler cleanup rather than authored helper.`
- `[UID:0000XU][0x004573d0-0x00457429.DATIndexVectorDestructor](by-memory/0x004573d0-0x00457429.DATIndexVectorDestructor.md) 0x004573d0-0x00457429 | compiler-generated destructor lowering | automatic stdext::hash_map member destruction : non-reconstructable : 94% : very-strong : Exact bucket storage cleanup and folded list teardown across typed consumers; represented by ordinary source member lifetime, not a DATIndexVector destructor.`
- `[UID:0000XX][0x00457580-0x00457613.DATIndexVectorFindNodeByKey](by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md) 0x00457580-0x00457613 | compiler-generated lookup lowering | find iterator/result lowering : non-reconstructable : 94% : very-strong : Exact key lookup/result-slot ABI and MiniMap/Monster caller split prove folded standard-container find behavior; no custom project API or emitter.`
- `[UID:00043F][0x0049cbb0-0x0049cc39.CreateDATEntryNode](by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md) 0x0049cbb0-0x0049cc39 | compiler-generated list-node construction | stdext::hash_map value-node copy/insert lowering : non-reconstructable : 94% : very-strong : Exact key/container/index node layout, neighbor linkage, allocator route and sole manager insertion context arise from typed stdext::hash_map insertion; no authored helper, owner, emitter or formal source.`
- `[UID:00043G][0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry](by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md) 0x0049ce50-0x0049d0c2 | compiler-generated hash-map lowering | insert, duplicate removal and rehash : non-reconstructable : 96% : very-strong : Exact ch+5*hash, bucket-mask traversal, list relink, load-factor test, 8x/2x growth and recursive rehash are Dinkumware stdext::hash_map implementation, not a DATFileResolver method.`
- `[UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) 0x0049d190-0x0049d26c | compiler-generated member destruction | automatic stdext::hash_map teardown : non-reconstructable : 95% : very-strong : Bucket storage, StringBaseW keys, list nodes and sentinel are destroyed through reverse member lifetime; typed _DATFileMgr map source replaces the synthetic resolver destructor.`
- `[UID:00043H][0x0049d490-0x0049d4bd.AllocateDATEntryNode](by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md) 0x0049d490-0x0049d4bd | compiler-generated list-node allocation | sentinel/value-node allocation lowering : non-reconstructable : 94% : very-strong : Exact 0x14 allocation, next/previous initialization and only map/list construction callers prove compiler container support rather than an authored DAT helper.`
- `[UID:00043I][0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey](by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md) 0x0049d5e0-0x0049d6ed | compiler-generated hash-map lookup | hash bucket and iterator-result lowering : non-reconstructable : 96% : very-strong : Exact ch+5*hash, bucket mask, sentinel termination and two-direction wide-range compare implement stdext::hash_map::find; no project resolver API or emitter.`

B006 must not apply these collision-prone manual coverage edits; supervisor owns them after report acceptance and ordinary callback verification.

## Follow-Up Actions

- B006 ordinary callback is complete: target/support details, exact DATFile authored/no-code child pages, manager compiler/source dispositions, FileError/StringBase dependencies, serial validators, waited owner refresh, and physical generated readback are recorded below.
- Supervisor: perform fresh post-callback Gate 1/Gate 2A, apply and validate the reserved manual coverage text, then perform A01 Gate 2B with fresh attestation/backup/readback/save.
- B006: never run execute_report or move/archive the report.
- No future B-agent research is required to decide UID0000IM source disposition. Later evidence-backed lexical refinements do not reopen ownership.

## Confidence

- Source-disposition confidence: very high (`98`).
- Inventory/ownership confidence: very high.
- Formal support-source confidence: very high for binary behavior and source/compiler boundaries, high for inferred private-header/comparator/member spellings.
- Remaining lexical uncertainty does not justify raw IDA names, an umbrella source file, a DATIndex or DATFileResolver custom class, invented mapped-file error helpers, or blank generated DATFile methods.

## Validator Results

- Dated pre-callback read-only audit: command `000000025804`; its identities remain historical evidence only.
- Every accepted ordinary page was scoped-validated serially with `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240`. All listed commands exited `0` with `ok:1`.

| Command(s) | Validated scope/result |
| --- | --- |
| `000000025831`-`000000025846` | Sixteen exact DATFile children in source order: constructor, destructor, Open, Close, Seek, GetPosition, GetSize, Read, ReadLineChars, ANSI ReadLine, IsOpen, GetDataPointer, retained wide duplicate, ReadAllLines, OpenByIndex, scalar deleting destructor. |
| `000000025847`-`000000025848` | Existing encoded-int and encoded-float children reread and validated. |
| `000000025851`-`000000025855` | DATArchive, DATFile, DATFile class, DATEntryRecord, and the mixed DATFile aggregate. |
| `000000025856`-`000000025865` | DATFileMgr file/class, `_DATFileMgr`, DATFileContainer, DATFileResolver, container constructor/destructor, private-manager destructor/load/find. |
| `000000025869`-`000000025875` | DATFile layout/vtable overlays and five manager hash/list compiler-lowering pages. |
| `000000025876`-`000000025877` | Exact DATFileContainer/DATFile vtable-data pages registered and validated. |
| `000000025878`-`000000025883` | FileError, Error, StringBase template/file, proposed source tree, and client DAT specification. |
| `000000025884`-`000000025885` | Initial waited DATFile and DATFileMgr owner refreshes. |
| `000000025886`-`000000025890` | Header-only/no-code marker closure, exact vtable pages, DATFile owner reread, and waited manager refresh. |
| `000000025892`-`000000025893` | Earliest manager dependency preamble validation and final waited DATFileMgr owner refresh. |

- Final physical archive directory contains exactly `DATFile.cpp`, `DATFile.h`, `DATFileMgr.cpp`, and `DATFileMgr.h`; `DATArchive` and `DATIndexVector` artifacts are absent.
- `DATFile.cpp` physically contains the sixteen authored class methods (`DATFile`, destructor, Open, Close, Seek, GetPosition, GetSize, Read, ReadLineChars, ANSI ReadLine, both encoded readers, IsOpen, GetDataPointer, ReadAllLines, OpenByIndex) plus `DecodeTableValue` and `LoadDatFileBuffer`, all eighteen bodies. `DATFile.h` contains the complete 0x14 class, typed members, declarations, and loader prototype.
- `DATFileMgr.cpp` places its complete dependency preamble before the first definition, emits authored container/private-manager/public-wrapper/global/HasDATEntry source, and contains no `DATFileResolver`, node allocation/insertion/find helper, `ShowDATFile*`, or `NormalizeDAT` definition. `DATFileMgr.h` contains packed `DATEntryRecord`, complete `DATFileContainer`, eight-byte `DATEntryLocation`, public manager wrapper, and global declaration.
- `Error.h` contains the complete 0xa4 `FileError` declaration. No current archive output contains `Empty Emitter Marker`, `stub`, or `placeholder` text.

| Generated physical readback | Current identity after final callback refresh |
| --- | --- |
| `auto-generated/NexusTK/archive/DATFile.cpp` | command `000000025893`; SHA256 `A4EC11B29038D4AD4C4FA72E7495CFC576975FCA4293F1804CA66408949B9487`; 10,409 bytes / 287 lines |
| `auto-generated/NexusTK/archive/DATFile.h` | command `000000025893`; SHA256 `3CF649FDA4FCEC0F96F3C692ECC52105F297ADCBEFE50FF6ECB47D281373FCCD`; 1,696 / 56 |
| `auto-generated/NexusTK/archive/DATFileMgr.cpp` | command `000000025892`; SHA256 `D0A40D38230E7A23A79B3873A938062EAB53F6AE4C6FDC175B42DE4502BCA478`; 8,464 / 226 |
| `auto-generated/NexusTK/archive/DATFileMgr.h` | command `000000025892`; SHA256 `A9199825412CDD9E79744F0BB8A93C0356097BDF23A3EDF8184457294B242894`; 1,907 / 80 |
| `auto-generated/NexusTK/util/Error.h` | command `000000025893`; SHA256 `46687A25F7C9651A921441D4C67F8622586048537EF3C7AC41996B6305FA0038`; 2,011 / 86 |

- Generated command/hash authority is dynamic; these are dated callback receipts, and fresh supervisor Gate readback is final authority.
- `proposed-source-tree.md` validation retained unrelated pre-existing missing-reference warnings for UIDs `0003LP`, `0003WL`, `0003WM`, `0003WN`, and `0003WO`; all callback target validations passed.
- Manual coverage remains supervisor-owned and was not changed.

## Changed Files

- The same report was updated additively after the accepted callback. Its final identity is reported externally because embedding its own hash would be self-referential.
- Current ordinary-file identities after validation:

| Ordinary path | SHA256 | Bytes / lines |
| --- | --- | --- |
| `by-file/DATArchive.md` | `5496CB801C722F716FFFFC66F33349D5A08E3C7C1A00F62035A4761A08290654` | 36,471 / 286 |
| `by-file/DATFile.md` | `417ED4DDD7B9EB356D2DA58E966C9512B0EF2BCAFBACACBF9F137FDF6EFC4F00` | 20,209 / 152 |
| `by-class/DATFile.md` | `12B8DF8E0D5069C19C8C3FDD536E002AA07A78D9DAEAB927A68F5E88895A676B` | 20,354 / 221 |
| `by-item/DATEntryRecord.md` | `ED5B8945A0112F7219B724E6FBBDC95E54DE0EE0675DD20837BF1117215C2827` | 17,640 / 160 |
| `by-memory/0x0049c130-0x0049d2cc.DATFile.md` | `401545E21489A75C46E79D973570680E01F5A50B1F9E888A217402CBF23C6BFE` | 17,177 / 144 |
| `by-memory/0x0049c130-0x0049c15a.DATFileConstructor.md` | `81FF46F496F5C3F1E741B1A82A83FD8E44F53A87DD7DC873F0E93555DC168904` | 2,082 / 38 |
| `by-memory/0x0049c160-0x0049c179.DATFileDestructor.md` | `078D6390961D3CFC97F9C7780018C7EF83A593C70EDB77270548E6F8AF02BD50` | 1,795 / 38 |
| `by-memory/0x0049c180-0x0049c23b.DATFileOpen.md` | `E34BCBF65B55798AD2AFA557BB70D79E480B044997502C7D108D1980B91D805A` | 2,395 / 47 |
| `by-memory/0x0049c240-0x0049c260.DATFileClose.md` | `464F7CE6CEB662D60F625F8C0C84C5DD23784225F89404ACA55C9FD32AC97FB9` | 1,579 / 37 |
| `by-memory/0x0049c260-0x0049c2cc.DATFileSeek.md` | `43E130488B6FE659BE39FBE2708CC03D38453DE030A4D37AEFDCCCC64FEEFC57` | 2,233 / 53 |
| `by-memory/0x0049c2d0-0x0049c2e7.DATFileGetPosition.md` | `76AAAE781010988854FC1FDEB52D91D9EB478BC7FD0D09739AF2C591194BC7D4` | 1,409 / 29 |
| `by-memory/0x0049c2f0-0x0049c304.DATFileGetSize.md` | `189DFC8E60DE310EEF92C9B6F2788FD9EEC394B951E6791E168718B09A9E626D` | 1,397 / 29 |
| `by-memory/0x0049c310-0x0049c362.DATFileRead.md` | `B7FD9B7599D7F54D56F16CBB0D1382FB0B66485E398EB2000B91E743FF88F8A5` | 2,066 / 40 |
| `by-memory/0x0049c370-0x0049c3df.DATFileReadLineChars.md` | `4C05753A81E042287813D48C188B5FD183FB87CAC0A5BA3C1D6899DCF3344DE6` | 2,147 / 44 |
| `by-memory/0x0049c3e0-0x0049c499.DATFileReadLine.md` | `7BAEB515BB417F8FDC2D6796150E32F33176BF299204AC4834C4D0939E4F866F` | 2,298 / 49 |
| `by-memory/0x0049c540-0x0049c548.DATFileIsOpen.md` | `9781A21CCB6EC50153D675A11B0E9D6EFDC258A4B9DF19573031527F1140FB1E` | 1,317 / 28 |
| `by-memory/0x0049c550-0x0049c567.DATFileGetDataPointer.md` | `F46049FA475911653AB27BDBF1C9DC1E0E2817AAAF0051E0059B040C63604C17` | 1,502 / 30 |
| `by-memory/0x0049c570-0x0049c5fe.DATFileRetainedWideReadLineDuplicate.md` | `9D54E1653168EB94E91D638B194D82CE3E33C0F196DF498837F619A3A469228F` | 1,905 / 30 |
| `by-memory/0x0049c600-0x0049c6f2.DATFileReadAllLines.md` | `D4E64077E6C296FDA0A69449798A5B2E9C837E124282A6BCA767488BAB6E3AFA` | 1,779 / 37 |
| `by-memory/0x0049c720-0x0049c74b.DATFileOpenByIndex.md` | `943606EFF4DA15501418A3871BADB7EEF712D4D96B2E9BE86A817C996D3A1334` | 1,713 / 34 |
| `by-memory/0x0049d280-0x0049d2cc.DATFileScalarDeletingDestructor.md` | `F1B758E756736220AD20294EACED895228CED6351F3F8E21122348EFEFF033BD` | 1,760 / 30 |
| `by-file/DATFileMgr.md` | `424CF82114BDE97CD62C033A5EE4B586C00771764DD23A6E032050D2B0CB9284` | 41,046 / 260 |
| `by-class/DATFileMgr.md` | `2A60DA6FE93D54CBDEF0E8812523E1EC7D17B3EA33915B2C5EC8C78890F0ADFA` | 25,846 / 227 |
| `by-class/_DATFileMgr.md` | `E31D7CDED1F1A9F138913167D1EB57E426E7AD4DCC76E26761E7F9643E6165E5` | 22,105 / 182 |
| `by-class/DATFileContainer.md` | `30C655007EEC086148B6E41F9AE4818C0EA8930C50853332B294883B5474C387` | 11,652 / 149 |
| `by-class/DATFileResolver.md` | `387B9F74FE6DC051738F48853D10CF7942D79611A6F85AAA4338E2ADCB8C2D50` | 16,704 / 134 |
| `by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md` | `C164519A82F01C7EA54A025B3654C19DE8EC2F3ED14DEFA1F1E237A3691EFEA3` | 4,808 / 86 |
| `by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md` | `A673E135A0120F7D203D80EE4B0DF9DD86DB2E5B647DD176E142BB445F601951` | 3,124 / 55 |
| `by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md` | `B3214B2157532A9A4564B3A3ED2A01BD05E1906250BC0A8847D1C1DE115C6D62` | 11,031 / 120 |
| `by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md` | `1D12FABC868EF45EB0806E94D4B682C2B828667572F33103F1DE26971CD79072` | 5,722 / 77 |
| `by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md` | `81B543FD868B32993EF71A4B4936C362E222405FF92DF17F7A88C76574EA0D03` | 3,172 / 51 |
| `by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md` | `AE06F65DF52B38535B7C391B08B446E62A88E0FBBFF35EFD8EDA87746B58C589` | 2,696 / 41 |
| `by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md` | `F5BD4C59ECB96F42CFC17F9B753FD74EAC7D501E75DE4B4848B2302B2BA4496B` | 2,884 / 40 |
| `by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md` | `16B923A9FC4144AB764D80EB5B254BC8B5D75023AB5E2558A5EF1A201F407117` | 9,474 / 112 |
| `by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md` | `D0B9FF15BEC61C450439CEB543CFD139FB958B9C52B8ACF02C625C813A598CA9` | 2,707 / 41 |
| `by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md` | `6DB4FD309AEA59C761FA9C1585CAF0AB9821AED0AFBA6B5ABDE8BBD3A0176E22` | 2,623 / 40 |
| `by-type/by-struct/DATFileLayout.md` | `A1E4FBA1E8EC3877CDCB8896C1F392E877CF6AE610B00807119A0D4A93857FD6` | 6,107 / 77 |
| `by-type/by-vtable/DATFileVtable.md` | `2E50DBFF9A556D1B3D22E6197C3B55FBF9645F83BAE4D96C6A16052E23DC7EF8` | 5,815 / 84 |
| `by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md` | `902E67FA15E24BDCE5D4ED94B09FC4655D3742620B23274C09FD3147E6DB0CBC` | 4,307 / 67 |
| `by-memory/0x00618920-0x00618950.DATFileVtableData.md` | `7062476A3B9756980E45D87538257D2221720EC595FD398353C04793BC948607` | 5,547 / 80 |
| `by-class/FileError.md` | `D7C17C3471C0F6AE5634AC7850AEFD9DAD2E0C2559D915906911338D109890A2` | 21,671 / 140 |
| `by-file/Error.md` | `F714464C658C384E660E6BB256597F66577ECBFD9E099EBECEFC57D476AB9759` | 76,390 / 344 |
| `by-type/by-template/StringBaseTemplate.md` | `8B0D51F10B2D9B2C23B4CF8A3D5FE4994B8EAE92CE11F155FD34F4BBECD7DD25` | 52,729 / 295 |
| `by-file/StringBase.md` | `099F3B5ED6C791AE6EB1E401FA92EDD1D2F072F80630D2330080D3F605AACF36` | 59,116 / 245 |
| `by-project-structure/proposed-source-tree.md` | `BBBD61308600A7191CFCCE742F812864FFCFA13141FA6A20CB677CE55DA65195` | 327,903 / 2,156 |
| `by-meta/client_dat_specifications.md` | `9348CB3D713940B80FD4BABC9CD44C9DB287DE887BF39E3929F45750FAA23B79` | 37,869 / 365 |

- Verified unchanged/retained for CIM-028/CIM-070: `by-meta/client_containers.md` SHA256 `08961BA3784DA62E63C5D5C87C5F5CF4274FB44E83105D3B6910967EE2ED0694`; `by-global/g_pEPFLib.md` `062026F9BE866239C9958E01CC15240F289F34B47EB416165A3AA5E003FFC2E1`; `by-memory/0x0067a744-0x0067a748.g_pEPFLib.md` `5ACB12AFC87A6230A2C4C0D44B640001CA336E35BB6D475C9534F2DAE5280646`; `by-file/ImageLib.md` `26347C3FEA85491413A19D2C3EFE162E1363E95D420EAD2C715DAF6187F7B070`; `by-class/ImageLib.md` `DB81D10738532FC1F78087ED7C083E390A0BCB0145922621E73356102D241114`.
- No file was renamed. B006 did not edit manual coverage, IDA, generated files by hand, tracker, audit, catalog, goal, notes, validator lifecycle state, or report lifecycle state. Validator-owned generated/statistical side effects came only from the scoped ordinary validation commands above.
- Report execution/archive remains supervisor-owned and authoritative only from the current report path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Exact ledger twin. Callback allocation is 43 checked / 27 unchecked. Fields after Done are identical to the Claim And Incorporation Ledger in the same order.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | CIM-001 | 0000IM | DATArchive is a non-emitting documentation index, not a compilation unit. | Very high | Zero binary/source identity and coherent concrete split. | UID0000IM Status/Disposition | reject-stale | applied |
| [x] | CIM-002 | 0000IM | Set metadata to 97/98, path NONE, owner NONE, reconstructable false. | Very high | Complete negative and ownership proof. | UID0000IM metadata | incorporate | applied |
| [x] | CIM-003 | 0000IM | Keep both formal source dispositions blank; generate no DATArchive CPP/H. | Very high | Zero owned source entities. | UID0000IM source disposition | incorporate | applied |
| [x] | CIM-004 | 0000IN | DATFile is the first authored archive unit and owns reader/helper source. | Very high | RTTI/vtable/method island and broad API use. | UID0000IN file role | incorporate | applied |
| [x] | CIM-005 | 0000IO | DATFileMgr is the second authored archive unit and owns wrapper/private-manager/container/global source plus typed standard-container consequences. | Very high | RTTI/type/layout/core island and old-MSVC container lowering. | UID0000IO file role | incorporate | applied |
| [x] | CIM-006 | 0000IP | DATIndexVector is compiler/template-family evidence, not source. | Very high | Seven folded bodies and cross-consumer mapped types. | UID0000IM/UID0000IP split | reject-stale | applied |
| [x] | CIM-007 | 0000IM | Reconcile 70 canonical links and 28 textual candidates into 84 target dispositions plus two compile-closure supports, 86 total. | High | Exhaustive target/link/table/generated/IDA audit. | UID0000IM Complete Inventory | incorporate | applied |
| [x] | CIM-008 | 00012D | Preserve complete DATFile method map but split source-bearing methods from the non-emitting mixed aggregate. | Very high | Exact ranges and live bodies. | UID00012D inventory/split | incorporate | applied |
| [x] | CIM-009 | 00003G | Complete DATFile H with typed container/record pointers, `StringBaseW` vector support, and all sixteen authored class methods. | Very high | Exact layout, live method bodies, base helper identity, and callers. | UID00003G formal CPP/H | incorporate | applied |
| [x] | CIM-010 | 0000UC | Emit packed 17-byte DATEntryRecord in DATFileMgr H at position 5. | Very high | Code and 250-file package audit. | UID0000UC formal H/metadata | incorporate | applied |
| [x] | CIM-011 | 00003H | Move DATFileContainer declaration to H, add DATFile and `_DATFileMgr` friendship, keep implementations in CPP, and replace invented error helpers with direct exact formatting/MessageBox/`throw new Win32Error`. | Very high | Direct field consumers and live constructor literals/control flow. | UID00003H and exact constructor formal CPP/H | incorporate | applied |
| [x] | CIM-012 | 00003I | Make DATFileMgr CPP preamble include its two archive headers plus File/Error/PathUtil and standard dependencies before children. | Very high | Dated pre-callback generated include occurred after definitions and left required APIs/types unresolved. | UID00003I formal CPP | incorporate | applied |
| [x] | CIM-013 | 0003H3 | Reclass DATFileLayout as non-emitting semantic overlay; class H is sole layout source. | Very high | Current empty marker duplicates UID00003G. | UID0003H3 metadata/no-code | reject-stale | applied |
| [x] | CIM-014 | 0003I0 | Reclass DATFileVtable as compiler-generated/non-emitting evidence. | Very high | Vtable arises from class virtuals. | UID0003I0 metadata/no-code | reject-stale | applied |
| [x] | CIM-015 | 0000IN | Add exact DATFile core/line/accessor/OpenByIndex source children; scalar deleting destructor and duplicate wide-line COMDAT remain compiler-covered. | Very high | Live decompile, exact duplicate proof, callers, and vtable map. | New exact by-memory children/UID0000IN inventory | incorporate | applied |
| [x] | CIM-016 | 0000IN | Generated DATFile must contain sixteen authored class methods plus DecodeTableValue and LoadDatFileBuffer, with all eighteen bodies and zero empty/compiler markers. | Very high | Dated command 000000025804 emitted four authored bodies, omitted fourteen, and had three markers. | UID0000IN Generated Audit | incorporate | applied |
| [x] | CIM-017 | 0000IO | Replace the dated pre-callback 23-item mixed DATFileMgr output with source-closed authored wrapper/private-manager/container/free-helper code and no synthetic resolver/node/hash lowering. | Very high | Dated pre-callback physical output plus live compiler-pattern proof. | UID0000IO Generated Audit | incorporate | applied |
| [x] | CIM-018 | 0000QQ | Keep g_pDATFileMgr source owner/definition in DATFileMgr. | Very high | 24 xrefs and wrapper/internal split. | UID0000QQ Ownership | already-present | already-present |
| [x] | CIM-019 | 0000T0 | HasDATEntry remains DATFileMgr API support. | Very high | Sole manager lookup call and broad consumers. | UID0000IM API Boundary | incorporate | applied |
| [x] | CIM-020 | 0000T4 | LoadDatFileBuffer remains DATFile source support. | Very high | Complete DATFile lifecycle wrapper. | UID0000IM API Boundary | incorporate | applied |
| [x] | CIM-021 | 0000TH | DecodeTableValue remains file-local DATFile support. | Very high | Exactly two typed DATFile wrapper callers. | UID0000IM API Boundary | incorporate | applied |
| [x] | CIM-022 | 0000T5 | LoadIndexedDATSeries remains Application startup policy. | Very high | Nineteen startup call sites and numbered archive formatting. | UID0000IM Exclusions | incorporate | applied |
| [x] | CIM-023 | 0000UF | DestroyDATFileMgr remains Application/fatal cleanup code, not manager-owned source. | High | App cleanup/EH placement and global deletion. | UID0000IM Exclusions | incorporate | applied |
| [x] | CIM-024 | 0000IM | Render/image/palette/audio entities are consumers, not archive owners. | Very high | Feature-specific state/tables/callers. | UID0000IM Consumer Matrix | incorporate | applied |
| [x] | CIM-025 | 0000IM | LodePNG/Zlib/image writers are third-party or render codec exclusions. | Very high | Current vetted third-party ownership. | UID0000IM Exclusions | incorporate | applied |
| [x] | CIM-026 | 0001R1 | Remove DATIndexVector.cpp tree node and describe exactly two authored archive units. | Very high | Current compiler-family reclassification. | proposed-source-tree archive sections | reject-stale | applied |
| [x] | CIM-027 | 0001QC | Replace three-module DAT model and all standalone DATIndexVector prose. | Very high | Current owner pages and live IDA. | client_dat_specifications | reject-stale | applied |
| [x] | CIM-028 | 0001QA | Retain current path-NONE DATIndex standard-container explanation. | Very high | Page already matches current proof. | client_containers | already-present | already-present |
| [x] | CIM-029 | 0000IM | Preserve package audit and 17-byte boundary-row semantics without claiming an always-empty sentinel. | Very high | 250-file physical audit. | UID0000IM Format Evidence | incorporate | applied |
| [x] | CIM-030 | 0000IM | Historical DATIndex custom class/folder assumptions remain as explicitly superseded history. | High | Useful provenance, contradicted source conclusion. | UID0000IM Historical Assumptions | historicalize | applied |
| [ ] | CIM-031 | 0000IM | Replace stale by-file manual coverage row with non-emitting 97% index row. | Very high | Current row says reconstructable umbrella. | by-file/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-032 | 0000IN | Replace DATFile manual row after source closure with exact 94% row. | High | Full inventory and formal repair plan. | by-file/-coverage-report.md | incorporate | proposed |
| [ ] | CIM-033 | 0000IO | Replace stale 89% DATFileMgr row with exact 94% row. | High | Current metadata 92/92 plus compile-closure repair. | by-file/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-034 | 0000IP | Replace standalone reconstructable DATIndex row with 96% compiler-index row. | Very high | Current 96/95 path-NONE page. | by-file/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-035 | 00003G | Replace DATFile class manual row after complete H/source routing. | High | Exact layout/method inventory. | by-class/-coverage-report.md | incorporate | proposed |
| [ ] | CIM-036 | 00003H | Replace stale 80% DATFileContainer manual row. | High | Current 88/90 plus exact H/CPP route. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-037 | 00003I | Replace stale 78% DATFileMgr class manual row. | High | Current 91/94 and complete H. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-038 | 00003K | Replace stale custom/reconstructable DATIndex class manual row. | Very high | Current 95/95 non-reconstructable overlay. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-039 | 0000UC | Replace DATEntryRecord manual row after packed H emission. | Very high | Exact size/offset/package semantics. | by-item/-coverage-report.md | incorporate | proposed |
| [ ] | CIM-040 | 0003H3 | Replace layout manual row with non-emitting 95% overlay. | Very high | Sole class-H ownership. | by-type/by-struct/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-041 | 0003I0 | Replace vtable manual row with non-emitting 95% compiler evidence. | Very high | Exact vtable/compiler disposition. | by-type/by-vtable/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-042 | 0000QQ | Replace stale 86% global coverage row with current 90% row. | Very high | Current page 90/94 and fresh 24 xrefs. | by-global/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-043 | 0002U7 | Replace stale reconstructable custom fill coverage with 92% compiler lowering. | Very high | Current page false/no emitter. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-044 | 0000WW | Refresh manual row score/detail to 95% compiler lowering. | Very high | Current page 95/97. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-045 | 0004HG | Insert absent manual row for 92% capacity lowering. | Very high | Current exact page and one folded caller. | by-memory/-coverage-report.md | incorporate | proposed |
| [ ] | CIM-046 | 0000XS | Replace custom InsertNode row with 94% compiler lowering. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-047 | 0000XT | Replace custom remove-helper row with 92% compiler unwind cleanup. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-048 | 0000XU | Replace custom destructor row with 94% automatic-container destruction. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-049 | 0000XX | Replace custom find row with 94% iterator/result lowering. | Very high | Current false/no-emitter page. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-050 | 0000QQ | Gate 2B A01 defines/names/types the four-byte singleton and adds exact repeatable comment. | Very high | Current one-byte unk head, zero bytes, 24 xrefs. | Supervisor Gate 2B A01-D/A01-C | incorporate | proposed |
| [ ] | CIM-051 | 0000IM | No IDA entity is created or named DATArchive; all concrete functions/types remain with their owner reports. | Very high | Negative entity proof. | Supervisor Gate 2B protection | incorporate | proposed |
| [x] | CIM-052 | 0000IM | Scoped validators and generated physical reread completed under the accepted callback; lifecycle remains supervisor-owned. | Very high | Exact callback/lifecycle role boundary. | Validator Results/Changed Files | incorporate | applied |
| [x] | CIM-053 | 0000IN | Emit exact CR/LF behavior for ReadLineChars and ANSI ReadLine and exact `File::ReadLine(StringBaseW&)` loop for ReadAllLines. | Very high | Live decompiles and three direct ReadAllLines callers. | Exact DATFile line-method children | incorporate | applied |
| [x] | CIM-054 | 0000IN | Classify `0x0049c570-0x0049c5fe` as a non-emitting retained duplicate of `File::ReadLine(StringBaseW&)`. | Very high | Byte/behavior identity and zero inbound xrefs at both copies. | Exact duplicate child and UID00012D split | reject-stale | applied |
| [x] | CIM-055 | 0000IO | Define complete eight-byte DATEntryLocation in DATFileMgr H as container pointer plus entry index. | Very high | Public/private lookup ABI and Open/OpenByIndex consumers. | UID0000IO/UID00003I formal H | incorporate | applied |
| [x] | CIM-056 | 00003J | Reclass DATFileResolver as path-NONE, non-reconstructable, non-emitting historical semantic overlay with blank formal code. | Very high | Exact Dinkumware hash-map physical state and no standalone project identity. | UID00003J metadata/formal/history | reject-stale | applied |
| [x] | CIM-057 | 000004 | Replace synthetic resolver member with `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>`. | Very high | Constructor defaults, hash loop, ordering comparisons, insertion/find/destruction lowering. | UID000004 formal CPP/layout/source shape | reject-stale | applied |
| [x] | CIM-058 | 00043F/00043G/00012H/00043H/00043I | Reclass manager node allocation, insert/rehash, destruction, and find bodies as non-emitting compiler/template lowering. | Very high | Exact node/list/bucket mechanics arise from the typed hash-map member. | Five exact pages metadata/formal/history | reject-stale | applied |
| [x] | CIM-059 | 0000IO | Emit exact source-facing `_DATFileMgr` load/find/destructor behavior through typed map/vector operations, never bucket/list internals. | Very high | Live load/find decompiles and compiler lowering correspondence. | UID000004 and exact authored manager children | incorporate | applied |
| [x] | CIM-060 | 00043B | Preserve exact mapped-container Win32 behavior and literals while removing undefined `ShowDATFileError`/`ShowDATFileMapError`. | Very high | Live constructor decompile and exact UTF-16 bytes. | UID00043B formal CPP/behavior/history | reject-stale | applied |
| [x] | CIM-061 | 00004X/0000J5 | Add complete `FileError` declaration to Error H so DATFile's exact `throw new FileError(path)` source closes. | Very high | Exact constructor/copy-message/vtable/layout evidence and dated pre-callback generated omission. | UID00004X/UID0000J5 formal H/dependency | incorporate | applied |
| [x] | CIM-062 | 0000IO | Require generated DATFileMgr CPP/H to order dependencies before use and contain no unresolved invented helpers or template-lowering definitions. | Very high | Command 25804 physical readback and accepted source model. | UID0000IO generated acceptance contract | incorporate | applied |
| [ ] | CIM-063 | 00003J | Replace stale reconstructable DATFileResolver manual row with a 96% non-emitting compiler-overlay row. | Very high | Typed hash-map source consequence. | by-class/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-064 | 00043F | Replace authored CreateDATEntryNode coverage with compiler list-node construction lowering. | Very high | Node layout/allocator/insertion call shape. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-065 | 00043G | Replace authored resolver insert coverage with compiler hash-map insert/rehash lowering. | Very high | Exact Dinkumware insert mechanics. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-066 | 00012H | Replace authored resolver destructor coverage with automatic hash-map member destruction lowering. | Very high | Reverse-member teardown and container internals. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-067 | 00043H | Replace authored node allocator coverage with compiler list-node allocation lowering. | Very high | Sentinel/node size and no independent API. | by-memory/-coverage-report.md | reject-stale | proposed |
| [ ] | CIM-068 | 00043I | Replace authored resolver find coverage with compiler hash-map find lowering. | Very high | Exact hash/bucket/two-direction compare and iterator result. | by-memory/-coverage-report.md | reject-stale | proposed |
| [x] | CIM-069 | 0001WS/0000OA | Add the confirmed `StringBase& append(unsigned int count, CharT character)` template declaration required by DATFile ANSI ReadLine. | Very high | Live `0x00584200` body returns `this`, appends `count` copies, and is called as `(1, current)`. | StringBase template/file formal H | incorporate | applied |
| [x] | CIM-070 | 0000QU/0001OQ/0000K2/00006E | Preserve `g_pEPFLib` as the ImageLib-owned render global; DAT-backed ResourceLayout/ImageLib methods are consumers of DATFile and do not transfer singleton ownership to DATArchive. | Very high | Exact four-byte storage, five lifecycle xrefs, 231 direct data xrefs, UID00006E declaration, broad render fanout, and direct DATFile use from ResourceLayout/ImageLib methods. | UID0000IM consumer matrix; UID0000QU ownership boundary | already-present | already-present |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000025975","destination_path":"executed-b-agent-research/B006/0000IM-DATArchive-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000IM-DATArchive-file-source-quality.md","timestamp":"2026-08-18T03:12:54-04:00","uid":"0000IM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
