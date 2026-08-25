# UID0000HQ BinaryCodec Whole-File Source Quality
** TARGET-REPORT-UID:0000HQ **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: reconstruct the complete historical codec family as one `NexusTK/util/BinaryCodec.cpp` compilation unit with one required `NexusTK/util/BinaryCodec.h`, containing the adjacent `Encoder` and `Decoder` classes in executable/source order.
- Direct owners: UID00004F owns Encoder declarations and methods; UID00003M owns Decoder declarations and methods. Both classes should be owned/emitted by file UID0000HQ. Existing file UIDs 0000J1 and 0000IQ remain useful historical/support aliases but cease to be source roots.
- Complete authored inventory: 36 source methods, 18 per class. Thirteen already have modeled source-function objects and 23 begin at raw IDA code items. Nine Encoder raw methods need new exact by-memory children; all 14 Decoder raw methods already have exact children.
- Compiler consequences: the two scalar deleting destructors, two RTTI locators, two compact vtables, and all alignment bytes are compiler/linker output. They remain documented and protected but receive no hand-authored body or data initializer.
- Liveness: only the modeled Encoder subset is live, through `TextEditPane_EncodeState` at `0x0058E490`. The nine Encoder raw methods and all 18 Decoder source methods have no surviving code callers, constructor routes, address/RVA/raw-offset pointers, or project data references. They are coherent retained project source, not runtime-reachable retail paths.
- Formal source: Section 22 supplies complete CPP/H insertion text for every source-bearing item and preserves the binary's signed cursor checks, endian handling, conversion calls, zlib behavior, reserve-byte rules, and observed allocation leaks.
- Metadata after implementation: UID0000HQ `94/93`; class UIDs 00004F and 00003M `94/93`. The score remains below 95 because stripped symbols cannot prove retail lexical spellings or the original source filename split, and no runtime Decoder route survives.
- Dated callback record: the accepted-report implementation callback applied and checked 69 ordinary/generated claims; report-local rows C67-C69 were left proposed and unchecked. During that dated callback B002 did not directly edit manual coverage, generated source, audit/catalog, IDA, or lifecycle files and did not run a report lifecycle command. These table states and dated exclusions make no assertion about current external Gate, coverage, IDA, execution, archive, or lifecycle status.

## Supporting Research

- Assignment authority: `tools/leaser/Agents/Agent-B002/goal.md`, SHA256 `002E831285F6B5F7E31FD4A711ED976C3E785DDC4434464DAB1CAF80434915A0`, 3,812 bytes, 36 physical lines.
- Accepted callback authority: updated `tools/leaser/Agents/Agent-B002/goal.md`, SHA256 `413BECA0C6BCC007B3BFF86D1B672295F86CA958FD1D03BAF92A84C88F2DFAB4`; accepted Gate 1 report SHA256 `D9E9895AB75EE96E03F9059EDB596B2D35AF06B7B253E4071A72AC7835C31FBB`, 203,718 bytes / 1,676 lines.
- Target snapshot: `by-file/BinaryCodec.md`, SHA256 `D8718F7E308D49AAAD29619717DFBD338B049FDA80DF69AB264CB94E6EEC4748`, 30,389 bytes, 166 physical lines, score `86/88`, owner `FILE`, path `NexusTK/util/`.
- Mandatory live IDA was read only from `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`. Dated evidence snapshots on 2026-08-14/15 used ephemeral session IDs `supervisor-uid0000KZ-gate2b-20260814`, `supervisor-uid0004HE-rollback-20260815`, and `supervisor-uid0000IA-rollback-20260815`; those IDs record only read-only collection contexts and make no current, active, sole, or canonical-session claim. The 2026-08-15 repair snapshot returned `status=ok`, Hex-Rays ready, `auto_analysis_ready=false`, and a ready 2,068-entry string cache; bounded item/comment/xref/name/instruction queries succeeded. Current IDB and Gate 2B authority are external to this report and authoritative only from the current supervisor audit and current bounded IDB readback. No mutation or save endpoint was called during report research.
- Raw executable receipt: `E:\NTK\Resources\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- Dated pre-callback generated snapshots from command `000000023750` at `2026-08-14T21:40:13-04:00`: `BinaryCodec.cpp` SHA256 `58DAC9DF5C08DEE027F030B67CA19FCA35ECB6E1F5EF3BA3230F50FF9204FD21`, 538 bytes/9 lines; `Encoder.cpp` SHA256 `9F5C0581DD7AA30F64CADD8E207426FBC5206AB39A0E2AB5E28F1FD2822FCDDC`, 3,953 bytes/139 lines; `Decoder.cpp` SHA256 `36762ED437727F6B2086FD740D39B486424EE6D666B65122D2FD22EF38C119CC`, 12,272 bytes/493 lines. No corresponding header existed in that dated prestate.
- Existing class snapshots: `by-class/Encoder.md` SHA256 `0E34428C47C0A2FAC08D673FAE76087F3DA4D235AF2B00B212817EAFC7C8ADF9`, 41,051 bytes/206 lines; `by-class/Decoder.md` SHA256 `164ED3FFD0004230CA2DB5CAAC70669299650DDECAD994E1F83BDD4E02683E9A`, 39,484 bytes/218 lines.
- Existing provisional file snapshots: `by-file/Encoder.md` SHA256 `0C9FB6A4556AC0C33458998C32A56A028ABCEFD57B91DF5066D67F295A777619`, 45,141 bytes/194 lines; `by-file/Decoder.md` SHA256 `A56C65F2ED15CDDDF4B3FC1090356C7DB764D7D1FDDC4A746E2A425B8778DB3D`, 39,351 bytes/178 lines.
- In the dated assignment-time search, matching archived and active reports were leads only and no duplicate UID0000HQ report was found. No Wave2/Wave3 authority was used.
- Callback implementation created permanent Encoder child UIDs `000512/000514/000513/000515/000516/000517/00051A/000518/000519`, routed all 36 authored definitions through the direct classes into UID0000HQ, converted compiler/layout support to false/non-emitting, and preserved every broad aggregate and historical fact.
- Final validator-generated physical readback after deferred command `000000023890` is `BinaryCodec.cpp` SHA256 `88245DBBD8DD50E29B71F0D78FD70D918CC9E36B013A27285F188A94634927C9`, 22,508 bytes / 897 lines, and `BinaryCodec.h` SHA256 `A213F61279BFE5034A61DBE40B1FFB45FE6CDC0CA4A43CB869C6F77D26AA19AC`, 2,680 bytes / 78 lines. Embedded provenance is command `000000023890`, timestamp `2026-08-15T02:40:28-04:00`, `deferred-generated-refresh`; physical last-write was `2026-08-15T02:41:41-04:00`.

## Target

- Primary target UID: `0000HQ`.
- Additional target UIDs: none.
- Primary path: `by-file/BinaryCodec.md`.
- Queue source: `auto-generated/-ag-research-tracker.md`, by-file uncovered queue after duplicate/active exclusions.
- Inferred final root: `NexusTK/util/BinaryCodec.cpp` and required sibling `NexusTK/util/BinaryCodec.h`.
- Whole-file code island: `[0x004A4E70,0x004A5E54)` plus CC alignment, followed by unrelated code at `0x004A5E60`; paired RTTI/vtable records are `[0x006192C8,0x006192E0)`, followed by unrelated ParseEntries constant data at `0x006192E0`.
- Declared target role: final file coordinator. By-file pages intentionally lack `RECONSTRUCTABLE`; the source family is reconstructable through class/method emitters rather than by adding invalid by-file metadata.

## Current Target State

- At the dated 2026-08-15 callback freeze, UID0000HQ was `94/93`, owner `FILE`, projected to `NexusTK/util/`, and the sole ordinary source root for `BinaryCodec.cpp` plus required `BinaryCodec.h`.
- At that callback freeze, UID00004F Encoder and UID00003M Decoder were each `94/93`, reconstructable true, owned/emitted by UID0000HQ at positions 1 and 2. Their exact formal CPP/H channels provided one preamble/child stream and two complete standalone 20-byte declarations.
- At that callback freeze, UID0001TS was `94/94` and UID0001X1 was `94/95`; both were reconstructable false with blank emitters. Scalar wrappers UID00013U/00013V and vtable data UID0003IA/0003IB were likewise false/non-emitting compiler consequences with direct class owners preserved.
- The dated callback readback found all 18 Encoder and all 18 Decoder authored method pages source-emitting in exact address order. Permanent raw Encoder UIDs were `000512/000514/000513/000515/000516/000517/00051A/000518/000519`; all ordinary counts/cursors used signed `int`, endian state used `bool`, and all six Win32 conversion calls used `CP_ACP`.
- Dated validator readback after command `000000023890` found `BinaryCodec.cpp` with exactly 36 authored definitions in Encoder-then-Decoder order, seven `MemoryMan::MemmoveWrapper` calls, six `CP_ACP` arguments, zlib `compress`/`uncompress`, and the accepted leaks/finalize asymmetry. It found `BinaryCodec.h` with both complete declarations and two 20-byte size assertions.
- That dated generated readback found old `Encoder.cpp` and `Decoder.cpp` absent and found no generated empty marker, stub, placeholder, TODO, duplicate authored definition/declaration, handwritten scalar wrapper, RTTI, or vtable initializer.
- At the dated callback freeze, UID00013D, UID00013Q, UID00013M, and UID000257 were false/non-emitting complete indexes, and UID000257 excluded the `0x006192E0` ParseEntries successor table.
- B002 made no IDA mutation during the dated research or callback. Section 21 records inert A01-A40 recommendations and P01-P03 protections against a dated prestate; whether any recommendation is reflected in the current IDB is external to this report.
- Current Gate, manual-coverage, IDA, by-* implementation, execution/archive, and lifecycle status is external to this report. It is authoritative only from the current supervisor audit, current physical IDB/by-* readback, and validator-owned status/history metadata; this body asserts none of those mutable states.

## Executive Recommendation

Use one historical codec file, not three generated roots. The exact code order is all Encoder source, all Decoder source, then the two compiler deleting wrappers. Both classes have independent vptrs and identical 20-byte cursor-state shapes; neither derives from a common codec base. Their mirrored method names, identical SetByteOrder/SkipBytes/Initialize/Noop bodies, uninterrupted address adjacency, paired RTTI/vtables, and grouped deleting wrappers are strong compilation-unit evidence.

The accepted callback physically implemented this ordinary-document/source topology. The imperative text below is retained as the dated accepted design specification and does not assert any current external Gate, coverage, IDA, execution, archive, or lifecycle state.

Create nine exact Encoder children for the currently raw methods, preserve the 14 exact Decoder raw children, and route every authored method through its direct class. UID00004F emits first and supplies the CPP preamble plus Encoder H declaration; UID00003M emits second and supplies Decoder definitions/declaration. Reclassify layout/vtable/scalar-wrapper support items as non-reconstructable, non-emitting evidence. Preserve broad aggregates as non-emitting indexes.

The separate `Encoder.cpp` and `Decoder.cpp` roots are a prior documentation inference, not original-path evidence. Keep those pages as historical support aliases with `PROPOSED_RECONSTRUCTION_PATH:"NONE"`; do not delete their research. Update `project-level/proposed-source-tree.md` only at accepted callback to replace the provisional three-root topology with the one-root result.

## Supervisor Active Recheck

- Artifact-audit contract: the current supervisor audit is authoritative for Gate 1 and Gate 2A status and rechecks the exact artifact hash, 33 headings, 72/72 twin, receipt inventory, and current physical support readbacks.
- Dated callback receipt: the accepted callback created the nine Encoder child pages first, substituted their permanent validator UIDs everywhere, then updated routing/formal fragments in dependency order.
- Dated validation receipt: every changed by-* page was scoped-validated, and the command `000000023890` physical readback found the coherent `BinaryCodec.cpp`/`BinaryCodec.h` pair and no old Encoder/Decoder generated roots.
- IDA contract: Section 21 requires fresh literal prestate, database-bound structured public requests, exact endpoint readback, collision checks, body/range/xref protection, and stop-on-delta behavior for any externally authorized action. Nineteen raw rows deliberately omit `set_type` because read-only evidence cannot prove one complete literal physical post-type frame; their final IDA type remains absent. A24-A27 retain deterministic no-argument type requests with an exact unchanged frame. Current Gate 2B and IDB status is authoritative only from the current supervisor audit and current IDB readback; B002's dated work was read-only.
- Coverage/lifecycle contract: current manual-coverage, execution/archive, and lifecycle status is authoritative only from the current supervisor audit, current physical by-* and coverage readback, and validator-owned status/history metadata.

## Inference Research Guidance Check

- Binary fact, documentation fact, generated-output fact, and inference are separated. Raw IDA labels and decompiler field names are evidence only.
- The source-placement decision follows whole-island structure rather than the dated pre-callback page topology. The then-current Encoder/Decoder by-file separation was explicitly treated as uncertain and re-tested against address order, identical mirrored bodies, RTTI adjacency, compiler-wrapper grouping, imports, and caller boundaries.
- Human names use the established Encoder/Decoder vocabulary already corroborated by RTTI and exact child docs. `SetByteOrder`, `WriteTriByte`, `ReadTriByte`, string width suffixes, `Initialize`, `Finalize`, and `NoopVirtual` are descriptive source-quality names, not claims of recovered PDB spelling.
- Signed cursor/capacity state is inferred from signed `JL/JGE` bounds tests. Scalar payloads remain unsigned because loads are zero-extended and shifts are logical. The endian flag is source-facing `bool`: constructors write canonical `1`, every test is zero/nonzero, and the setter copies a one-byte bool parameter.
- Liveness is not inferred from body quality. The dated 2026-08-15 xref and pointer-pattern scans prove retained dead methods separately from their source-authored status.
- No stale Wave2/Wave3 instruction was found or used.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence and reanalysis | Final disposition |
| --- | --- | --- |
| One file versus separate roots | Encoder and Decoder occupy one uninterrupted mirrored island; identical paired bodies occur at 0x4A4EB0/0x4A5680, 0x4A5590/0x4A5D80, 0x4A55C0/0x4A5DB0, and 0x4A5630/0x4A5DF0; RTTI/vtables and wrappers are adjacent. No original file-path string or object boundary supports the dated pre-callback split. | One `BinaryCodec.cpp/.h`; retain separate file pages only as aliases/history. |
| Common base class | Both 20-byte objects have independent vptrs and RTTI, and neither constructor calls a shared base constructor. | Two standalone classes with mirrored fields; no invented base. |
| Encoder UDT unsigned fields | Capacity/write cursor checks branch signed; unsigned source comparisons would produce unsigned conditions absent explicit casts. | Source-facing `int m_capacity`, `int m_writePos`; IDA member-type correction recommended. |
| Decoder layout | Constructor/finalize/readers use the same offsets as Encoder, and scalar deletion passes size 0x14. | Exact 20-byte Decoder UDT with signed size/cursor and two trailing alignment bytes. |
| Endian state | One-byte constructor store `0x0101`, direct one-byte setter, zero/nonzero tests, selected prefix/integer order. | `bool m_useBigEndian`; true means network/big-endian, false means host little-endian. |
| String count signedness | `-1` invokes `wcslen`; capacity/count tests are signed. | `int charCount`, `int capacityChars`, `int *outChars`. |
| Blob count signedness | Cursor additions are followed by signed bounds branches; zlib's lengths alone are unsigned. | Ordinary byte counts and buffer sizes are `int`; compressed output sizes remain `unsigned int`/`unsigned long`. |
| Encoder raw liveness | All nine starts have zero xrefs and no VA/RVA/raw-offset pointer hits, while modeled writer calls all originate in one TextEdit function. | Retained dead Encoder API; reconstruct, document zero reachability, do not fabricate callers. |
| Decoder liveness | Constructor, destructor, all 14 raw starts, and Finalize have zero inbound code/data xrefs. Only deleting-wrapper/noop vtable slots remain. | Entire Decoder authored API is retained dead source in this executable. |
| Encoder live caller | One stack object, one 32,768-byte local buffer, Initialize capacity 0x7FFE, writes text/state tables, magic `0x6B6F6E67`, Finalize, heap copy. | Exact `TextEditPane_EncodeState` consumer only; no packet/network claim. |
| WriteBytes helper | Dated pre-callback generated source said `MoveMemory`; accepted MemoryMan declaration is `MemmoveWrapper`. | Use `GetMemoryMan()->MemmoveWrapper`. |
| String conversion | Encoder calls `WideCharToMultiByte(CP_ACP)`; Decoder calls `MultiByteToWideChar(CP_ACP)`. | Preserve Win32 ACP conversion and exact explicit lengths, clamping, and termination. |
| WriteCString allocation | Allocates a temporary, converts/copies, and has no observed delete route before any return. | Preserve the historical leak; do not silently improve it. |
| WriteCompressed failure | Allocates/compresses before capacity validation; the overflow path marks invalid and returns without freeing, while success frees. | Preserve both ignored zlib status and overflow leak. |
| Decoder compressed read | Calls `uncompress`, ignores its return status, advances by compressed length, then validates produced size. | Preserve order and status omission. |
| Finalize semantics | Encoder always writes one terminator at current cursor, detaches/reset state, returns prior writable flag; Decoder only detaches/reset state and returns prior valid flag. | Preserve asymmetry and no full-consumption check. |
| Scalar wrappers/vtables | Wrappers are addressed only by vtable cells; RTTI/vtable bytes follow MSVC ABI. | Compiler-covered no-code; ordinary virtual destructors regenerate them. |
| Adjacent DAT table | `0x6192E0` is referenced by ParseEntries and is outside the Decoder vtable record. | Explicitly exclude from BinaryCodec ownership. |
| Original lexical spelling | RTTI proves class names but no symbols prove every method/field/file spelling. | Use consistent descriptive names and cap confidence at 93. |

Rejected alternatives: delete unreachable methods, retain three source roots, invent a shared base, use unsigned cursor fields, model endian as an enum without evidence, replace ACP conversion with UTF-8, replace MemoryMan with direct CRT copies, add zlib error handling, fix the two observed Encoder leaks, hand-author scalar deleting destructors/vtables, or absorb ParseEntries data.

## Evidence Standards Used

- Primary evidence: live read-only IDA function/item/type/frame/comment/xref queries, decompilation/disassembly, exact raw bytes, and raw-executable SHA256 ranges.
- Corroboration: all related by-file/by-class/by-type/by-memory pages, dated callback generated CPP and manual-coverage snapshots, MemoryMan formal API, TextEdit caller docs, proposed source tree, and matching historical reports.
- Negative evidence: zero xrefs, absent function objects, absent comments/types, VA/RVA/raw-offset pointer scans, no source-path strings, no globals/statics/resources, and exact neighboring boundary checks.
- Source standard: preserve observable behavior and mid-2000s MSVC C++ shape while excluding compiler-generated ABI scaffolding.
- Confidence limitation: stripped symbols and dead Decoder routes prevent original lexical/path proof but do not prevent complete behavioral reconstruction.

## Evidence Checked

| Evidence area | Concrete result |
| --- | --- |
| Modeled functions | 15 function objects: eight modeled Encoder source methods plus Encoder no-op, Decoder ctor/dtor/finalize/no-op, and two scalar wrappers. Exact names/types/comments/frames/xrefs were reread live. |
| Raw starts | 23 source bodies begin at IDA code items with no function object, name, type, or comment channels: nine Encoder and 14 Decoder. Every exact body/range is listed below. |
| UDTs | Encoder exists at size 20 with seven members; Decoder is absent. Constructor/destructor/field-touch evidence proves both exact layouts. |
| Caller set | All live authored calls are from `TextEditPane_EncodeState` to eight modeled Encoder methods; the destructor also has its same-function EH cleanup tail at 0x60970C. |
| Dead routes | Every raw start, Decoder ctor/dtor/finalize, and both class vtable bases were checked for ordinary xrefs; raw starts also had no VA/RVA/raw-offset pointer pattern. |
| Vtables | Encoder record 0x6192C8-0x6192D4 and Decoder record 0x6192D4-0x6192E0 are exact 12-byte RTTI+two-slot records; 0x6192E0 is unrelated. |
| Imports/callees | `WideCharToMultiByte`, `MultiByteToWideChar`, `compress`, `uncompress`, MemoryMan accessor/memmove, operator new/delete, compiler stack probing, cookie, and range-check support. |
| Data/resources | No codec-owned mutable global, static, string literal, resource, enum, lookup table, or constant was found. Only compiler RTTI/vtables are owned consequences. |
| Dated pre-callback generated snapshot | Command `000000023750` at `2026-08-14T21:40:13-04:00` found two BinaryCodec empty markers, partial/stale Encoder output, body-complete but declaration-incomplete Decoder output, and no BinaryCodec header. This is historical defect evidence only, not current generated truth. |
| Dated completed post-callback generated readback | After deferred command `000000023890`, physical readback found `BinaryCodec.cpp` SHA256 `88245DBBD8DD50E29B71F0D78FD70D918CC9E36B013A27285F188A94634927C9`, 22,508 bytes/897 lines, with all 36 authored definitions exactly once, and `BinaryCodec.h` SHA256 `A213F61279BFE5034A61DBE40B1FFB45FE6CDC0CA4A43CB869C6F77D26AA19AC`, 2,680 bytes/78 lines, with both complete declarations; old Encoder/Decoder roots and empty/stub/TODO/placeholder defects were absent. Current generated truth remains subject to supervisor gate-time physical reread. |
| Docs | Primary target, both provisional files/classes, all exact/broad memory pages, shared type/vtable pages, TextEdit caller, MemoryMan, source tree, coverage rows, and report searches were read. |
| Dated B002 research exclusions | During report research B002 performed no IDA mutation/save, ordinary/generated/coverage/tracker/audit edit, validator, report lifecycle action, or report move. |

## Claim And Incorporation Ledger

Every row is independently actionable. Section 33 repeats these exact eight non-`Done` fields verbatim and adds only `Done`. Report-local allocation is 69 checked/applied and C67-C69 unchecked/proposed; those fixed row states do not assert current external coverage, IDA, Gate, execution/archive, or lifecycle status.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 0000HQ | BinaryCodec is one retained historical compilation unit containing Encoder then Decoder, not three independent source roots. | High | Contiguous mirrored island, paired RTTI/wrappers, absent path evidence | UID0000HQ placement/status | incorporate | applied |
| C02 | 00004F | Encoder is a standalone 0x14 class directly owned/emitted by UID0000HQ. | High | RTTI, ctor fields, vtable, stack object size | UID00004F metadata/H | incorporate | applied |
| C03 | 00003M | Decoder is a standalone 0x14 class directly owned/emitted by UID0000HQ. | High | RTTI, ctor fields, vtable, scalar delete size | UID00003M metadata/H | incorporate | applied |
| C04 | 0000J1 | Encoder by-file becomes a non-root historical/support alias with path NONE; preserve its evidence. | Medium-high | One-file placement analysis | UID0000J1 metadata/status | incorporate | applied |
| C05 | 0000IQ | Decoder by-file becomes a non-root historical/support alias with path NONE; preserve its evidence. | Medium-high | One-file placement analysis | UID0000IQ metadata/status | incorporate | applied |
| C06 | 0001TS | Shared layout page becomes non-reconstructable/non-emitting ABI evidence; class H fragments own declarations. | High | Duplicate layout consequence and empty marker | UID0001TS metadata | incorporate | applied |
| C07 | 0001X1 | Shared vtable page becomes non-reconstructable/non-emitting compiler evidence. | High | MSVC vtable/RTTI consequence and empty marker | UID0001X1 metadata | incorporate | applied |
| C08 | 0000HQ | Required final files are BinaryCodec.cpp and BinaryCodec.h; no headerless result is valid. | High | Member definitions need two complete class declarations | UID0000HQ/generated topology | incorporate | applied |
| C09 | 0000HQ | Cursor/capacity fields and ordinary byte counts are signed int; scalar values and zlib lengths retain unsigned types. | High | Signed bounds branches and zero-extension/logical shifts | class/child types/formal source | incorporate | applied |
| C10 | 0000HQ | Endian state is a one-byte bool where true selects big-endian and false little-endian. | High | Canonical ctor writes, direct setter, all branch uses | class fields/SetByteOrder docs | incorporate | applied |
| C11 | 0000HQ | The only live authored route is TextEditPane_EncodeState to the modeled Encoder subset. | High | Exhaustive live xrefs | target/classes/caller inventory | incorporate | applied |
| C12 | 0000HQ | Nine Encoder raw methods and the entire Decoder authored API are retained dead source, not removable compiler debris. | High | Coherent bodies plus exhaustive zero routes | target/classes/children | incorporate | applied |
| C13 | 00013C | Encoder constructor initializes null buffer, zero capacity/cursor, big-endian true, writable true. | High | 0x4A4E70 body/hash | constructor child/formal CPP | already-present | applied |
| C14 | 00013E | Encoder ordinary destructor is empty source; virtual declaration generates ABI teardown. | High | 0x4A4EA0 body/hash | destructor child/formal CPP | already-present | applied |
| C15 | 000512 | Create exact Encoder SetByteOrder child 0x4A4EB0-0x4A4EBD and direct-store bool behavior. | High | Raw body/hash, mirrored Decoder method | new by-memory child | incorporate | applied |
| C16 | 00013F | Encoder WriteByte reserves one trailing terminator byte and marks failure on signed overflow. | High | 0x4A4EC0 body/hash | WriteByte child/formal CPP | incorporate | applied |
| C17 | 00013G | Encoder WriteShort writes selected-endian unsigned 16-bit value and reserves terminator capacity. | High | 0x4A4F00 body/hash | WriteShort child/formal CPP | incorporate | applied |
| C18 | 000514 | Create exact Encoder WriteTriByte child 0x4A4F60-0x4A4FE3 with selected 24-bit byte order. | High | Raw body/hash, Decoder mirror | new by-memory child | incorporate | applied |
| C19 | 00013H | Encoder WriteInt writes selected-endian unsigned 32-bit value and reserves terminator capacity. | High | 0x4A4FF0 body/hash | WriteInt child/formal CPP | incorporate | applied |
| C20 | 000513 | Create exact WriteWideString8 child with signed -1 length, one-byte count, native wchar payload, and reserve byte. | High | 0x4A5070 body/hash | new by-memory child | incorporate | applied |
| C21 | 000515 | Create exact WriteWideString16 child with selected-endian 16-bit count and native wchar payload. | High | 0x4A50F0 body/hash | new by-memory child | incorporate | applied |
| C22 | 000516 | Create exact WriteAnsiString8 child with CP_ACP conversion, 255 clamp, and one-byte count. | High | 0x4A5190 body/hash/imports | new by-memory child | incorporate | applied |
| C23 | 000517 | Create exact WriteAnsiString16 child with 64K scratch, 65535 clamp, and selected-endian count. | High | 0x4A52A0 body/hash/imports | new by-memory child | incorporate | applied |
| C24 | 00051A | Create exact WriteCString child and preserve its observed temporary-allocation leak. | High | 0x4A53D0 body/hash/no delete route | new by-memory child | incorporate | applied |
| C25 | 00013I | Encoder WriteBytes uses signed count/cursor checks and MemoryMan::MemmoveWrapper. | High | 0x4A5480 body plus accepted MemoryMan API | WriteBytes child/formal CPP | incorporate | applied |
| C26 | 000518 | Create exact WriteCompressedBytes child; preserve ignored compress status and overflow-path leak. | High | 0x4A54D0 body/hash/callees | new by-memory child | incorporate | applied |
| C27 | 000519 | Create exact Encoder SkipBytes child with reserve-byte bounds and no write. | High | 0x4A5590 body/hash | new by-memory child | incorporate | applied |
| C28 | 00013J | Encoder Initialize attaches caller storage with signed capacity and resets writable state. | High | 0x4A55C0 body/hash | Initialize child/formal CPP | incorporate | applied |
| C29 | 00013K | Encoder Finalize reports prior state/count, writes terminator, detaches, and resets. | High | 0x4A55E0 body/hash | Finalize child/formal CPP | already-present | applied |
| C30 | 00013L | Encoder NoopVirtual is empty virtual source and only vtable-referenced. | High | 0x4A5630 one-byte body/xref | noop child/formal CPP | incorporate | applied |
| C31 | 00013N | Decoder constructor initializes null input, zero size/cursor, big-endian true, valid true. | High | 0x4A5640 body/hash | constructor child/formal CPP | incorporate | applied |
| C32 | 00013O | Decoder ordinary destructor is empty source. | High | 0x4A5670 body/hash | destructor child/formal CPP | incorporate | applied |
| C33 | 0003K8 | Decoder SetByteOrder directly stores a bool endian selector. | High | 0x4A5680 body/hash | exact child/formal CPP | incorporate | applied |
| C34 | 0003K9 | ReadByte checks signed bounds, advances one, or invalidates and returns zero. | High | 0x4A5690 body/hash | exact child/formal CPP | already-present | applied |
| C35 | 0003KA | ReadShort performs selected-endian unsigned 16-bit read with signed bounds. | High | 0x4A56C0 body/hash | exact child/formal CPP | already-present | applied |
| C36 | 0003KB | ReadTriByte performs selected-endian unsigned 24-bit read. | High | 0x4A5710 body/hash | exact child/formal CPP | already-present | applied |
| C37 | 0003KC | ReadInt performs selected-endian unsigned 32-bit read. | High | 0x4A5770 body/hash | exact child/formal CPP | already-present | applied |
| C38 | 0003L6 | ReadWideString8 reads one-byte count and native wchar payload with exact output reset. | High | 0x4A57E0 body/hash | exact child/formal CPP | already-present | applied |
| C39 | 0003L7 | ReadWideString16 reads selected-endian count and native wchar payload. | High | 0x4A5870 body/hash | exact child/formal CPP | already-present | applied |
| C40 | 0003L8 | ReadAnsiString8 copies counted bytes, converts CP_ACP, and enforces output capacity after conversion. | High | 0x4A5930 body/hash/imports | exact child/formal CPP | already-present | applied |
| C41 | 0003L9 | ReadAnsiString16 preserves 64K scratch, selected-endian count, ACP conversion, and checks. | High | 0x4A5A40 body/hash/imports | exact child/formal CPP | already-present | applied |
| C42 | 0003LA | ReadCString scans through NUL, allocates/copies/converts/frees, advances through terminator. | High | 0x4A5BB0 body/hash/callees | exact child/formal CPP | already-present | applied |
| C43 | 0003LB | ReadBytes uses signed count and advances only after a successful copy. | High | 0x4A5C80 body/hash | exact child/formal CPP | incorporate | applied |
| C44 | 0003LC | ReadCompressedBytes preserves selected count, ignored uncompress status, advance, produced-size check. | High | 0x4A5CD0 body/hash/callee | exact child/formal CPP | already-present | applied |
| C45 | 0003LD | Decoder SkipBytes uses signed count and requires one remaining byte. | High | 0x4A5D80 body/hash | exact child/formal CPP | incorporate | applied |
| C46 | 0003LE | Decoder Initialize attaches const input with signed size and resets valid state. | High | 0x4A5DB0 body/hash | exact child/formal CPP | incorporate | applied |
| C47 | 00013S | Decoder Finalize returns prior validity and detaches/resets without consumption validation. | High | 0x4A5DD0 body/hash | exact child/formal CPP | incorporate | applied |
| C48 | 00013T | Decoder NoopVirtual is empty virtual source and only vtable-referenced. | High | 0x4A5DF0 one-byte body/xref | exact child/formal CPP | incorporate | applied |
| C49 | 00013U | Decoder scalar deleting destructor is compiler-covered, non-reconstructable, non-emitting. | High | 0x4A5E00 flags wrapper/vtable xref | scalar child metadata/no-code | incorporate | applied |
| C50 | 00013V | Encoder scalar deleting destructor is compiler-covered, non-reconstructable, non-emitting. | High | 0x4A5E30 flags wrapper/vtable xref | scalar child metadata/no-code | incorporate | applied |
| C51 | 0003IA | Encoder RTTI/vtable data is compiler-covered, non-reconstructable, non-emitting. | High | Exact 12 bytes and ABI slots | vtable child metadata/no-code | incorporate | applied |
| C52 | 0003IB | Decoder RTTI/vtable data is compiler-covered, non-reconstructable, non-emitting. | High | Exact 12 bytes and ABI slots | vtable child metadata/no-code | incorporate | applied |
| C53 | 000257 | The 0x6192E0 successor table belongs to ParseEntries and remains excluded. | High | Boundary/xref at 0x4A5E9E | DAT aggregate/target negatives | already-present | applied |
| C54 | 0000HQ | All 38 internal/terminal gaps are CC alignment and own no authored source. | High | Exact bytes/xrefs/boundaries | target range analysis | incorporate | applied |
| C55 | 0000UM | Preserve the sole TextEdit caller's one-buffer 0x7FFE-capacity serialization evidence without claiming network packet ownership. | High | 0x58E490 decompile/xrefs | caller support/target | incorporate | applied |
| C56 | SUPPORT | Preserve broad aggregates as false/non-emitting indexes and update them with complete exact-child inventory. | High | Overlap and child coverage | UIDs 00013D/00013Q/00013M/000257 | incorporate | applied |
| C57 | 00004F | Encoder formal CPP supplies includes plus CHILDREN; formal H supplies complete class declaration. | High | Final source topology | class formal channels | incorporate | applied |
| C58 | 00003M | Decoder formal CPP supplies CHILDREN only; formal H supplies complete class declaration. | High | Final source topology | class formal channels | incorporate | applied |
| C59 | SUPPORT | Existing authored children route to their direct class in exact address/source order; nine new Encoder children fill positions. | High | Complete 36-method inventory | all exact child metadata | incorporate | applied |
| C60 | SUPPORT | Remove stale MoveMemory, unsigned cursor/count, provisional split, and unresolved-liveness prose without losing history. | High | Dated pre-callback docs versus dated live evidence | affected support docs | reject-stale | applied |
| C61 | SOURCE-TREE | Replace provisional BinaryCodec/Encoder/Decoder three-root tree with one BinaryCodec.cpp/.h family. | Medium-high | Ranked placement result | proposed-source-tree.md | incorporate | applied |
| C62 | GENERATED | Fresh BinaryCodec.cpp must contain 36 authored definitions exactly once and no empty markers/stubs/TODOs. | High | Resolved emitter graph and formal CPP | supervisor generated readback | incorporate | applied |
| C63 | GENERATED | Fresh BinaryCodec.h must contain two complete 0x14 class declarations exactly once. | High | Formal H and compile requirement | supervisor generated readback | incorporate | applied |
| C64 | GENERATED | No manual scalar-wrapper/vtable/RTTI definitions may appear in generated source. | High | Compiler-covered classification | supervisor generated readback | incorporate | applied |
| C65 | 0000HQ | Raise target to 94/93 after complete ordinary implementation and physical generated readback. | Medium-high | Full closure with lexical/path/liveness caps | target metadata | incorporate | applied |
| C66 | SUPPORT | Apply item-specific support scores from Section 26 without crossing the 95 completion barrier. | Medium-high | Resolved source and remaining caps | affected support metadata | incorporate | applied |
| C67 | COVERAGE | Section 28 records exact manual-coverage replacement/insert proposals from the dated callback freeze; current coverage disposition is external to this report. | High | Dated callback-freeze stale/absent rows; current authority requires current supervisor audit and physical by-*/coverage readback | manual coverage reports | incorporate | proposed |
| C68 | IDA | Section 21 records the database-bound structured A01-A40 handoff, including 23 explicit-bound `define_func` chains: 19 raw rows omit `set_type` and preserve exact observed D frames with type absent because no literal post-type frame is read-only provable; A24-A27 retain exact no-argument type requests with unchanged frames; current IDB and Gate 2B disposition is external to this report. | High | Dated live state, exact body/frame evidence, deterministic row-local contracts; current authority requires current supervisor audit and IDB readback | IDA handoff | incorporate | proposed |
| C69 | IDA | Section 21 records byte-for-byte and exact-xref protections for two vtable records and the unrelated successor table; current IDB disposition is external to this report. | High | Dated item/byte/xref evidence; current authority requires current supervisor audit and IDB readback | IDA protections | incorporate | proposed |
| C70 | 0000HQ | External dependencies remain MemoryMan, Win32 ACP conversion, zlib, CRT allocation/memmove, and compiler support; no duplication. | High | Complete callee/import inventory | target/classes/formal CPP | incorporate | applied |
| C71 | 0000HQ | No codec-owned global/static/string/resource/enum/table exists beyond compiler RTTI/vtables. | High | Listing/string/data/import negative searches | target inventory/negative evidence | incorporate | applied |
| C72 | 0000HQ | By-file reconstructable blank is schema-correct; source reconstruction is expressed through class/method metadata. | High | by-structure/by-file guidance | target metadata/status | already-present | applied |

## Positive Evidence Summary

- The 36 authored bodies form a complete paired API: construction/destruction, byte order, four integer widths, four counted string variants, C strings, raw bytes, compressed bytes, skip, initialize/finalize, and one virtual no-op for each side.
- Exact repeated hashes establish intentional mirroring: SetByteOrder `A2FE...0D48`, SkipBytes `B3DC...BB49`, Initialize `9F50...B36F`, and NoopVirtual `AE3F...359E` are byte-identical pairs.
- Both constructors establish independent RTTI-backed vptrs and the same offsets; both scalar wrappers delete 0x14-byte objects; the paired vtable records are adjacent.
- Source ordering and all CC gaps are deterministic. No unrelated code interrupts `[0x4A4E70,0x4A5E54)`.
- The dated 2026-08-15 TextEdit caller evidence proves Encoder's live source-facing API and 20-byte stack object. Zero-route evidence classifies the remaining coherent methods as retained rather than invented.
- Existing exact Decoder children and modeled Encoder children already corroborate nearly all behavior; live MCP and raw-byte checks close the prior liveness/type/source-placement blockers.

## IDA MCP Facts

- Dated read-only evidence snapshots: ephemeral IDs `supervisor-uid0000KZ-gate2b-20260814`, `supervisor-uid0004HE-rollback-20260815`, and `supervisor-uid0000IA-rollback-20260815` were observed on 2026-08-14/15 against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. They are historical collection receipts only, not current/active/sole/canonical authority. The 2026-08-15 repair snapshot reconfirmed every affected raw head, empty comment/xref state, collision-free default/final names, and bounded prologue/stack accesses without mutation. Current IDB and Gate 2B status is external and authoritative only from the current supervisor audit and current bounded IDB readback. The unrelated disposable UID000403 snapshot was excluded from target evidence.
- Dated 2026-08-15 Encoder UDT prestate: size 20; `vtable@0/4 void *`, `m_outputBuffer@4/4 unsigned char *`, `m_capacity@8/4 unsigned int`, `m_writePos@C/4 unsigned int`, `m_useBigEndian@10/1 bool`, `m_isWritable@11/1 bool`, `_alignment12@12/2 unsigned char[2]`. Decoder type was absent.
- Dated 2026-08-15 function prestate: the exact 15-object list and sizes appears in Section 14. Every observed AR/AP/FR/FP channel was literal `absent`.
- Dated 2026-08-15 raw-start prestate: all 23 were code items with name `absent`, type `absent`, AR `absent`, AP `absent`, and no function object, hence function regular/repeatable channels were absent because no function existed.
- Exact live call xrefs: ctor `{0x58E4E4}`; dtor `{0x58E66C,0x60970C}`; WriteByte `{0x58E57B}`; WriteShort `{0x58E59A,0x58E5C9,0x58E5F8}`; WriteInt `{0x58E58B}`; WriteBytes `{0x58E56E,0x58E5BA,0x58E5E3,0x58E612}`; Initialize `{0x58E54B}`; Finalize `{0x58E624}`.
- Vtable-only data xrefs: Encoder Noop `{0x6192D0}`, Encoder scalar wrapper `{0x6192CC}`, Decoder Noop `{0x6192DC}`, Decoder scalar wrapper `{0x6192D8}`. Every Decoder authored nonvirtual method and every raw start has code/data xref set `{}`.
- Physical data caveat: `0x6192C8` is currently interior to IDA item `word_61929C [0x61929C,0x6192CC)`; `0x6192D4` is an unnamed dword; `0x6192E0` begins `xmmword_6192E0`. No data-shaping mutation is recommended.

## Function / Child Inventory

Source order is exact. `Authored` rows require formal CPP; `compiler` rows require no code. Hashes are SHA256 over each half-open executable range.

| # | Exact range | UID/path | Dated 2026-08-15 IDA prestate | Role / exact source disposition | SHA256 |
| --- | --- | --- | --- | --- | --- |
| 1 | 004A4E70-004A4E94 | 00013C EncoderConstructor | function Encoder_Encoder, 0x24 | Authored ctor; existing child, route position 1 | FE3668345EABC48140C8F539CDE1C9E18D33A8D0BF140F6C31F01E336C471A9B |
| 2 | 004A4EA0-004A4EA7 | 00013E EncoderDestructor | function Encoder_destructor, 0x7 | Authored dtor; existing child, position 2 | 43D6BA2B81AD5A55D655D6F8CA8A9C0947909B3654085B8CE11282A490160660 |
| 3 | 004A4EB0-004A4EBD | 000512 | raw code, no function | Authored SetByteOrder; permanent child, position 3 | A2FE89792C8975BE6A2349700822252976FD564B5B0C077D48560917D87E0D48 |
| 4 | 004A4EC0-004A4EF1 | 00013F EncoderWriteByte | function Encoder_WriteByte, 0x31 | Authored; existing child, position 4 | 9916B00E72DBAF929858612BBB6AF6473167CF6F9B060873BFEB733991DE98D9 |
| 5 | 004A4F00-004A4F59 | 00013G EncoderWriteShort | function Encoder_WriteShort, 0x59 | Authored; existing child, position 5 | 321549037C4A4C8209BB3F2AB060AEBE4A360EC4FAC24BDD1A495C741D96EBDA |
| 6 | 004A4F60-004A4FE3 | 000514 | raw code, no function | Authored WriteTriByte; permanent child, position 6 | 8802E155DEDAB3F3B232B32F08091C16C68B6D1209792E07301A2CC1B8074BF5 |
| 7 | 004A4FF0-004A506B | 00013H EncoderWriteInt | function Encoder_WriteInt, 0x7B | Authored; existing child, position 7 | F42557F72905AF98F51C245BEBC41A24B5EC0EDFCFEB4ED0369E00A08567009A |
| 8 | 004A5070-004A50E3 | 000513 | raw code, no function | Authored WriteWideString8; permanent child, position 8 | 03815E4EC890DEBD9FB1FA0583AC2C69F0E22463B2AAA70DAC3F5D8CE92C270F |
| 9 | 004A50F0-004A5189 | 000515 | raw code, no function | Authored WriteWideString16; permanent child, position 9 | F490A878C7E0A00CBD265FF46C16979C4E1B14FD096D96AEA1C4F842D764FD23 |
| 10 | 004A5190-004A5293 | 000516 | raw code, no function | Authored WriteAnsiString8; permanent child, position 10 | D55474F050D231B41DBFE4C97206E6D4A0CCC4DBBC70F22AF0B01488E63BE3B6 |
| 11 | 004A52A0-004A53CA | 000517 | raw code, no function | Authored WriteAnsiString16; permanent child, position 11 | 033BC29EC38BE57420C4AE5DA12FB8D92C1EEA79AD8FE2F347D35118755FF496 |
| 12 | 004A53D0-004A5472 | 00051A | raw code, no function | Authored WriteCString; permanent child, position 12 | 54301901D5C98FA5D370E0A143F767AE1EE8D540B429BB18E7712B0B8492D5DB |
| 13 | 004A5480-004A54C6 | 00013I EncoderWriteBytes | function Encoder_WriteBytes, 0x46 | Authored; existing child, position 13 | BB508128120674A83ECA58226F4096FEFA5785EA5F79CB4BBF821DAB96290856 |
| 14 | 004A54D0-004A558D | 000518 | raw code, no function | Authored WriteCompressedBytes; permanent child, position 14 | 8E5EA6DF5A3B434796234EFB7EE334E8033D6AEE2E66DBD0291D25A738C1DD3D |
| 15 | 004A5590-004A55B6 | 000519 | raw code, no function | Authored SkipBytes; permanent child, position 15 | B3DC6A177447875CA0F54DA480148C27A4375C7C0803420381A2705D300CBB49 |
| 16 | 004A55C0-004A55DE | 00013J EncoderInitialize | function Encoder_Initialize, 0x1E | Authored; existing child, position 16 | 9F509287A9B2A77B12FED5F4ADA5FB266638A1252A73414EB646B2C4D16BB36F |
| 17 | 004A55E0-004A5621 | 00013K EncoderFinalize | function Encoder_Finalize, 0x41 | Authored; existing child, position 17 | B369A15463BE97B8431FCD7ACF70AEAD2404EBEB1B768F7C9B66ACCBD1C7DE0D |
| 18 | 004A5630-004A5631 | 00013L EncoderNoopVirtual | function nullsub_27, 0x1 | Authored virtual no-op; existing child, position 18 | AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E |
| 19 | 004A5640-004A5664 | 00013N DecoderConstructor | function sub_4A5640, 0x24 | Authored ctor; existing child, position 1 under Decoder | A3F766040A4434E78A7809E7F1A0274D9F3DEBC5615D5CBAF3F0E6FAD628F7F5 |
| 20 | 004A5670-004A5677 | 00013O DecoderDestructor | function sub_4A5670, 0x7 | Authored dtor; existing child, position 2 | 87462F0D1EBF8954054E712492052FB8100DB16589EFB02FD6CFCDB924033D3F |
| 21 | 004A5680-004A568D | 0003K8 DecoderSetByteOrder | raw code, no function | Authored; existing child, position 3 | A2FE89792C8975BE6A2349700822252976FD564B5B0C077D48560917D87E0D48 |
| 22 | 004A5690-004A56B8 | 0003K9 DecoderReadByte | raw code, no function | Authored; existing child, position 4 | BAF03660E923A1924A90C067811ACF940444A85F0CED85E270E5657162F9252B |
| 23 | 004A56C0-004A570F | 0003KA DecoderReadShort | raw code, no function | Authored; existing child, position 5 | FB47FEEDA9865B6AE923F0ED60F51EBFBE13BBDB893B34FEEBE491FC26462D38 |
| 24 | 004A5710-004A576F | 0003KB DecoderReadTriByte | raw code, no function | Authored; existing child, position 6 | 26779C287791079333467DABBE58525AA30B5C149A260F199C7F2ECB503175CE |
| 25 | 004A5770-004A57DC | 0003KC DecoderReadInt | raw code, no function | Authored; existing child, position 7 | 7B023D4EC16DFCF6935989818390FE5C58B27C5B0E3B4E6205B6E87C21FF37E6 |
| 26 | 004A57E0-004A5861 | 0003L6 DecoderReadWideString8 | raw code, no function | Authored; existing child, position 8 | 0BB75D14A28AEEE9C078D1B226071FBDE26D3E9751F12834C1D632048342979C |
| 27 | 004A5870-004A5925 | 0003L7 DecoderReadWideString16 | raw code, no function | Authored; existing child, position 9 | A3106DA0E4873D838E1DDCFB4A44635C72D5EC275DEC7C5A7BBA9FE8F06F7EF0 |
| 28 | 004A5930-004A5A3A | 0003L8 DecoderReadAnsiString8 | raw code, no function | Authored; existing child, position 10 | F0A914175E65757319469DF7D8C4293D129C34CA20604DE0D109D4CFEB53308C |
| 29 | 004A5A40-004A5BA7 | 0003L9 DecoderReadAnsiString16 | raw code, no function | Authored; existing child, position 11 | D435773AD4D6C644E817C408BD05F30FDC7B0BAE9D9FA8EDE706EBF589D30EB9 |
| 30 | 004A5BB0-004A5C7E | 0003LA DecoderReadCString | raw code, no function | Authored; existing child, position 12 | 6E89188B9F706DEB409B850A36CDA023409650E7E4699C50C74792561CE145D0 |
| 31 | 004A5C80-004A5CC4 | 0003LB DecoderReadBytes | raw code, no function | Authored; existing child, position 13 | 9781C8B449DC75AD42B5B89082F5FFE2BB31C19713F818C34F48ED936BE1E54D |
| 32 | 004A5CD0-004A5D79 | 0003LC DecoderReadCompressedBytes | raw code, no function | Authored; existing child, position 14 | 8B6CECC175A9C30BCA4C3069389ADAA01A5D11F6E1F1CE6693E9DDA27A32FCDC |
| 33 | 004A5D80-004A5DA6 | 0003LD DecoderSkipBytes | raw code, no function | Authored; existing child, position 15 | B3DC6A177447875CA0F54DA480148C27A4375C7C0803420381A2705D300CBB49 |
| 34 | 004A5DB0-004A5DCE | 0003LE DecoderInitialize | raw code, no function | Authored; existing child, position 16 | 9F509287A9B2A77B12FED5F4ADA5FB266638A1252A73414EB646B2C4D16BB36F |
| 35 | 004A5DD0-004A5DED | 00013S DecoderFinalize | function sub_4A5DD0, 0x1D | Authored; existing child, position 17 | 867F1089E1E889E60520EAE61EA2427DF6578DA949B211045309FE5BA87F2050 |
| 36 | 004A5DF0-004A5DF1 | 00013T DecoderNoopVirtual | function nullsub_28, 0x1 | Authored virtual no-op; existing child, position 18 | AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E |
| 37 | 004A5E00-004A5E24 | 00013U DecoderScalarDeletingDestructor | function sub_4A5E00, 0x24 | Compiler wrapper; no code/emitter | 4106387B929618A5D9FB042DBDFFBE4326C7F4C1CFE46A2F35677EDE5B598584 |
| 38 | 004A5E30-004A5E54 | 00013V EncoderScalarDeletingDestructor | function sub_4A5E30, 0x24 | Compiler wrapper; no code/emitter | 7DB36FB166B1026C178B8C61EC94CA734E9A2B71C0662FE3F4089F6FDA3E520B |

Non-code inventory:

| Exact item | UID/path | Role | Source disposition |
| --- | --- | --- | --- |
| Encoder class/layout | 00004F plus 0001TS | 0x14 standalone class; shared layout evidence | Complete H declaration on class; layout support false/non-emitting |
| Decoder class/layout | 00003M plus 0001TS | 0x14 standalone class; shared layout evidence | Complete H declaration on class; layout support false/non-emitting |
| 006192C8-006192D4 | 0003IA / 0001X1 | Encoder COL pointer + scalar dtor + no-op slots | Compiler-covered no-code; hash 0E91CE3E9F354AFFDD2CBF246347BADF0141C5B47DB2C388709A7F1CD0413BEB |
| 006192D4-006192E0 | 0003IB / 0001X1 | Decoder COL pointer + scalar dtor + no-op slots | Compiler-covered no-code; hash 032E8FF96E6CB81A8D901158A937532B489CBC0DC4BC07BC5A92C1114B62FFFE |
| 006192E0 successor | 000257 / ParseEntries support | unrelated constant table beginning with 0x1A | Excluded; no source ownership |
| Aggregates | 00013D, 00013Q, 00013M, 000257 | overlapping audit/index containers | False/non-emitting; retain exact inventories |
| Imports/dependencies | MemoryMan, Kernel32 conversion APIs, zlib, CRT allocation/memmove, MSVC support | external support | Include/use declarations only; no duplicate source |
| Globals/statics/strings/resources/enums | none | exhaustive negative result | No source fragment |

Count reconciliation: 36 authored methods, two compiler code wrappers, 23 raw starts, 15 modeled functions, two exact vtable records, two class declarations, four broad aggregates, 38 CC gaps, five external dependency families, and one explicitly excluded successor table. Every source-bearing item has a formal disposition in Section 22.

## Direct Xref / Caller Inventory

| Address/item | Exact inbound set | Principal callees / meaning |
| --- | --- | --- |
| 4A4E70 Encoder ctor | code `{58E4E4}` | TextEdit stack-object construction; vptr store |
| 4A4EA0 Encoder dtor | code `{58E66C,60970C}` | ordinary and EH cleanup exits of same TextEdit function |
| 4A4EB0 SetByteOrder | `{}` | no callees; retained dead |
| 4A4EC0 WriteByte | code `{58E57B}` | no calls; live TextEdit byte write |
| 4A4F00 WriteShort | code `{58E59A,58E5C9,58E5F8}` | no calls; three live table-size writes |
| 4A4F60 WriteTriByte | `{}` | no calls; retained dead |
| 4A4FF0 WriteInt | code `{58E58B}` | no calls; live magic/state write |
| 4A5070 WriteWideString8 | `{}` | GetMemoryMan, MemmoveWrapper; retained dead |
| 4A50F0 WriteWideString16 | `{}` | GetMemoryMan, MemmoveWrapper; retained dead |
| 4A5190 WriteAnsiString8 | `{}` | WideCharToMultiByte, range-check/cookie support; retained dead |
| 4A52A0 WriteAnsiString16 | `{}` | stack probe, WideCharToMultiByte, range-check/cookie support; retained dead |
| 4A53D0 WriteCString | `{}` | operator new, WideCharToMultiByte, MemoryMan copy; no delete route |
| 4A5480 WriteBytes | code `{58E56E,58E5BA,58E5E3,58E612}` | GetMemoryMan, MemmoveWrapper; four live TextEdit copies |
| 4A54D0 WriteCompressedBytes | `{}` | operator new, compress, MemoryMan copy, success-only delete |
| 4A5590 Encoder SkipBytes | `{}` | no calls; retained dead |
| 4A55C0 Encoder Initialize | code `{58E54B}` | live caller attaches 0x8000 stack buffer with 0x7FFE capacity |
| 4A55E0 Encoder Finalize | code `{58E624}` | live caller receives byte count then heap-copies output |
| 4A5630 Encoder Noop | data `{6192D0}` | vtable slot only |
| 4A5640 / UID00013N / `DecoderConstructor.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead construction, with only the local Decoder vptr/state stores and no surviving construction route. |
| 4A5670 / UID00013O / `DecoderDestructor.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead empty ordinary destructor with no surviving destruction route. |
| 4A5680 / UID0003K8 / `DecoderSetByteOrder.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead direct bool-endian store. |
| 4A5690 / UID0003K9 / `DecoderReadByte.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead primitive reader with no address-pointer route. |
| 4A56C0 / UID0003KA / `DecoderReadShort.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead selected-endian 16-bit reader. |
| 4A5710 / UID0003KB / `DecoderReadTriByte.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead selected-endian 24-bit reader. |
| 4A5770 / UID0003KC / `DecoderReadInt.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead selected-endian 32-bit reader. |
| 4A57E0 / UID0003L6 / `DecoderReadWideString8.md` | code count 0 `{}`; data count 0 `{}` | Callees `{GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220}`; retained-dead one-byte-count wide reader. |
| 4A5870 / UID0003L7 / `DecoderReadWideString16.md` | code count 0 `{}`; data count 0 `{}` | Callees `{GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220}`; retained-dead selected-endian wide reader. |
| 4A5930 / UID0003L8 / `DecoderReadAnsiString8.md` | code count 0 `{}`; data count 0 `{}` | Callees `{GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220, KERNEL32!MultiByteToWideChar, __security_check_cookie, __report_rangecheckfailure}`; retained-dead 0x100-scratch ACP reader. |
| 4A5A40 / UID0003L9 / `DecoderReadAnsiString16.md` | code count 0 `{}`; data count 0 `{}` | Callees `{__alloca_probe, GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220, KERNEL32!MultiByteToWideChar, __security_check_cookie, __report_rangecheckfailure}`; retained-dead 0x10000-scratch ACP reader. |
| 4A5BB0 / UID0003LA / `DecoderReadCString.md` | code count 0 `{}`; data count 0 `{}` | Callees `{operator-new wrapper@5C7790, GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220, KERNEL32!MultiByteToWideChar, free wrapper@5C7799}`; retained-dead NUL-scanning ACP reader. |
| 4A5C80 / UID0003LB / `DecoderReadBytes.md` | code count 0 `{}`; data count 0 `{}` | Callees `{GetMemoryMan@516030, MemoryMan_MemmoveWrapper@516220}`; retained-dead raw span reader. |
| 4A5CD0 / UID0003LC / `DecoderReadCompressedBytes.md` | code count 0 `{}`; data count 0 `{}` | Callees `{zlib uncompress wrapper@414390}`; retained-dead compressed span reader with ignored helper status. |
| 4A5D80 / UID0003LD / `DecoderSkipBytes.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead signed cursor skip. |
| 4A5DB0 / UID0003LE / `DecoderInitialize.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead input attachment/reset method. |
| 4A5DD0 / UID00013S / `DecoderFinalize.md` | code count 0 `{}`; data count 0 `{}` | Callees `{}`; retained-dead detach/reset method. |
| 4A5DF0 / UID00013T / `DecoderNoopVirtual.md` | code count 0 `{}`; data count 1 `{6192DC}` | Callees `{}`; compiler-vtable-referenced empty source method, unreachable without a surviving Decoder object route. |
| 4A5E00 Decoder scalar wrapper | data `{6192D8}` | compiler vtable slot, delete helper |
| 4A5E30 Encoder scalar wrapper | data `{6192CC}` | compiler vtable slot, delete helper |
| 6192C8 Encoder record | no ordinary inbound to locator cell; slot refs as above | COL 646B2C, wrapper 4A5E30, noop 4A5630 |
| 6192D4 Decoder record | no ordinary inbound to locator cell; slot refs as above | COL 646B74, wrapper 4A5E00, noop 4A5DF0 |
| 6192E0 successor | non-code data user at 4A5E9E | ParseEntries constant; exclusion proof |

Decoder authored-method row reconciliation: 18 exact rows above, comprising constructor, destructor, all 14 raw methods, Finalize, and NoopVirtual. The sole live caller uses one `Encoder` at 20-byte stack size and one 32,768-byte buffer. It writes a text payload, NUL, literal `0x6B6F6E67` (`kong` in little-endian bytes), and three 16-bit-size-prefixed tables, then finalizes and copies exactly the returned count. This is state serialization, not evidence of a network packet protocol.

## Documentation Evidence And IDA Status

- Valid existing evidence: exact Decoder child boundaries and behavior, modeled Encoder child behavior, 20-byte shared layout, paired compact vtables, TextEdit caller, DAT boundary, and non-emitting aggregate intent.
- Stale/incomplete evidence: provisional separate source roots, unresolved Decoder liveness, missing nine Encoder children, unsigned cursor/count source types, stale `MoveMemory`, reconstructable compiler-data emitters, blank class CPP/H, missing header, and dated pre-callback generated empty markers.
- The dated 2026-08-15 IDA snapshot improved only Encoder names/types; Decoder UDT and most source functions were unmodeled. This report supplies a complete inert handoff without claiming that any recommendation was applied.
- Dated pre-callback generated source is evidence of routing state, not proof of source completeness.

## Ranked Ownership Analysis

### 1. UID0000HQ BinaryCodec one-file root

- Evidence for: uninterrupted mirrored method island, exact paired hashes, two classes with identical shape, adjacent RTTI/vtables, grouped scalar wrappers, common dependencies, and no original-path evidence for a split.
- Evidence against: dated pre-callback documentation emitted separate roots, and no retail source path survives.
- Decision: strongest defensible historical compilation-unit inference; accept one CPP/H.

### 2. Separate Encoder.cpp and Decoder.cpp roots

- Evidence for: classes are semantically independent and could compile separately; dated pre-callback docs used this topology.
- Evidence against: that dated topology was provisional, code/data/compiler products are tightly grouped in one island, and no object/path boundary corroborates it.
- Decision: retain pages as aliases/history only; reject as final source placement.

### 3. Shared BinaryCodec base or namespace-only helper file

- Evidence for: mirrored fields and API.
- Evidence against: independent RTTI/vptrs, no base construction, no shared base object, and the target is not source-empty once both classes are placed there.
- Decision: reject invented base/namespace abstraction.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: existing UID0000HQ, `NexusTK/util/BinaryCodec.cpp` and `.h`.
- Likely full contents: two class declarations; 36 authored definitions; external includes only.
- Included compiler consequences: two scalar wrappers and two RTTI/vtables, generated by compiler/linker rather than authored.
- Rejected candidate: successor data at 0x6192E0 and ParseEntries code at 0x4A5E60.

## Source Placement

- Final placement: UID00004F Encoder first, UID00003M Decoder second, both emitted through UID0000HQ.
- CPP topology: Encoder class formal CPP emits the six exact includes and `[[CHILDREN]]`; Decoder formal CPP emits only `[[CHILDREN]]`. This guarantees one preamble and address/source order.
- H topology: Encoder class H begins with `#pragma once` and its declaration; Decoder class H appends its declaration. No split include guard is required.
- Exact child positions: Encoder 1-18 and Decoder 1-18 as Section 14. The class emitter positions under UID0000HQ are Encoder 1, Decoder 2.
- Existing file pages UID0000J1/UID0000IQ move to path `NONE`; no authored child remains emitted through them.
- Rejected placements: UI/TextEdit because it is only a consumer; network because no packet caller exists; third-party because the classes are project-authored wrappers; headerless because member definitions require declarations.

## Range / Split / Padding / Reclassification Analysis

- Exact authored/ABI boundary: `[0x4A4E70,0x4A5E54)`; terminal CC pad `[0x4A5E54,0x4A5E60)`; unrelated ParseEntries starts `0x4A5E60`.
- Nine Encoder raw children to create:
  - `0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md`
  - `0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md`
  - `0x004a5070-0x004a50e3.EncoderWriteWideString8.md`
  - `0x004a50f0-0x004a5189.EncoderWriteWideString16.md`
  - `0x004a5190-0x004a5293.EncoderWriteAnsiString8.md`
  - `0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md`
  - `0x004a53d0-0x004a5472.EncoderWriteCString.md`
  - `0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md`
  - `0x004a5590-0x004a55b6.EncoderSkipBytes.md`
- Exact CC padding gaps, all source-free and zero-xref: `4E94-4EA0(0C)`, `4EA7-4EB0(09)`, `4EBD-4EC0(03)`, `4EF1-4F00(0F)`, `4F59-4F60(07)`, `4FE3-4FF0(0D)`, `506B-5070(05)`, `50E3-50F0(0D)`, `5189-5190(07)`, `5293-52A0(0D)`, `53CA-53D0(06)`, `5472-5480(0E)`, `54C6-54D0(0A)`, `558D-5590(03)`, `55B6-55C0(0A)`, `55DE-55E0(02)`, `5621-5630(0F)`, `5631-5640(0F)`, `5664-5670(0C)`, `5677-5680(09)`, `568D-5690(03)`, `56B8-56C0(08)`, `570F-5710(01)`, `576F-5770(01)`, `57DC-57E0(04)`, `5861-5870(0F)`, `5925-5930(0B)`, `5A3A-5A40(06)`, `5BA7-5BB0(09)`, `5C7E-5C80(02)`, `5CC4-5CD0(0C)`, `5D79-5D80(07)`, `5DA6-5DB0(0A)`, `5DCE-5DD0(02)`, `5DED-5DF0(03)`, `5DF1-5E00(0F)`, `5E24-5E30(0C)`, `5E54-5E60(0C)`.
- Reclassify UID0001TS, UID0001X1, UID00013U, UID00013V, UID0003IA, and UID0003IB as false/non-emitting support/compiler evidence. Preserve their exact bytes, roles, and links.
- Preserve UID00013D, UID00013Q, UID00013M, and UID000257 as false/non-emitting aggregate indexes; do not duplicate exact child source.

## Negative Evidence Summary

- No Decoder constructor, destructor, reader, finalize, or raw-start caller survives. Vtable cells prove class linkage but not runtime construction.
- No raw Encoder method caller or address pointer survives. Modeled Encoder xrefs all collapse to one TextEdit source function.
- No separate object/source path, feature-local consumer, source string, or build artifact supports the dated pre-callback Encoder.cpp/Decoder.cpp split.
- No base-constructor call, shared RTTI base, or extra vptr supports a BinaryCodec base class.
- No mutable global/static, string literal, resource, enum, codec lookup table, or standalone data definition belongs to the authored file.
- `0x6192E0` is outside the Decoder record and has a ParseEntries use, so proximity does not establish codec ownership.
- Compiler scalar wrappers, RTTI, vtables, stack probes, security cookies, and range-check helpers do not justify hand-authored source fragments.
- Improved safety, RAII, UTF-8 conversion, zlib status handling, or leak fixes would contradict observed behavior and are rejected.

## IDA Rename / Type / Comment Recommendations

B002 made no IDA mutation during the dated research or callback. `AR`, `AP`, `FR`, and `FP` mean regular address, repeatable address, regular function, and repeatable function comments. A01-A40 are inert conditional recommendations, not assertions about current Gate 2B or IDB status. Current authority is external to this report and comes only from the current supervisor audit and current bounded IDB readback. If an externally authorized recommendation is applicable to that readback, it uses only the named public semantic endpoint and hard-stops on any unexpected name/type/frame/range/body/xref/comment delta.

### Type actions

| ID | Classification | Dated 2026-08-15 literal prestate | Conditional public endpoint and exact expected readback |
| --- | --- | --- | --- |
| A01 | apply | Non-address UDT `Encoder` exists, size 20, members exactly `vtable@0/4 void *`, `m_outputBuffer@4/4 unsigned char *`, `m_capacity@8/4 unsigned int`, `m_writePos@C/4 unsigned int`, `m_useBigEndian@10/1 bool`, `m_isWritable@11/1 bool`, `_alignment12@12/2 unsigned char[2]`. As a non-address UDT it has no AR/AP/FR/FP channels. | Exact request `declare_type({database:"b002_uid0000hq_rollback_20260815",decls:"struct Encoder { void *vtable; unsigned char *m_outputBuffer; int m_capacity; int m_writePos; bool m_useBigEndian; bool m_isWritable; unsigned char _alignment12[2]; };"})`. Expected readback is size 20 with members exactly `vtable@0/4 void *`, `m_outputBuffer@4/4 unsigned char *`, `m_capacity@8/4 int`, `m_writePos@C/4 int`, `m_useBigEndian@10/1 bool`, `m_isWritable@11/1 bool`, `_alignment12@12/2 unsigned char[2]`; change only the two signed member types and preserve name, size, offsets, widths, other types, ordinal/reference identity, and deterministic no-comment disposition. Hard-stop on database mismatch, declaration error, or any other delta. |
| A02 | apply | Non-address UDT `Decoder` is literally absent. As a nonexistent non-address type it has no address/function comment channels. | Exact request `declare_type({database:"b002_uid0000hq_rollback_20260815",decls:"struct Decoder { void *vtable; const unsigned char *m_inputBuffer; int m_inputSize; int m_readPos; bool m_useBigEndian; bool m_isValid; unsigned char _alignment12[2]; };"})`. Expected readback is a new size-20 `Decoder` with members exactly `vtable@0/4 void *`, `m_inputBuffer@4/4 const unsigned char *`, `m_inputSize@8/4 int`, `m_readPos@C/4 int`, `m_useBigEndian@10/1 bool`, `m_isValid@11/1 bool`, `_alignment12@12/2 unsigned char[2]` and deterministic no-comment disposition. Hard-stop on database mismatch, pre-existing type, declaration error, or any size/name/offset/width/type delta. |

### Function action contract

There are 15 deterministic existing-function apply rows and 23 deterministic explicit-bound raw-definition apply rows; with A01-A02, all 40 A rows apply. Every row below is a complete local contract; no row inherits a prestate, frame, comment, xref, endpoint, protection, or stop condition from another row. Every exact request binds the dated attested database `b002_uid0000hq_rollback_20260815`; a fresh supervisor attempt must first confirm that exact database identity and canonical path or stop before mutation.

The 23 immediate-D frames are literal endpoint contracts. Dated 2026-08-15 supervisor attempts physically observed A05/A24/A25/A26/A27 exactly as retained and observed A08/A10-A14/A16-A17/A23/A28-A36 with only the saved-register and return-address rows now written in their actions. None of those 18 D endpoints produced a local or argument row. A05 and those 18 rows now omit `set_type` entirely because no public read-only endpoint proves one exact complete physical post-type frame; their deterministic final frame is the unchanged D frame and their deterministic final function type is absent. A24-A27 have no explicit stack parameters and retain exact `set_type` requests whose required poststate leaves their complete D frames unchanged. Gate 2B stops on any member, gap, name, offset, width, type, range, channel, or request-envelope difference.

Bounded read-only repair evidence, dated 2026-08-15: `idb_list` returned sole active, adopted, non-analyzing session `b002_uid0000hq_rollback_20260815` for canonical `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` returned `status=ok`, image base `0x400000`, `hexrays_ready=true`, and `auto_analysis_ready=false`; bounded IDB-backed calls succeeded, so the workflow does not treat that analysis flag alone as MCP failure. `runtime_attestation(expected_database="b002_uid0000hq_rollback_20260815",expected_canonical_path="E:\NTK\Resources\NexusTK\NexusTK.exe.i64")` returned `ok=true`. At all 18 repaired starts, `inspect_items` returned raw code with empty name/type, `stack_frame` returned `vars=null`/`No function found`, `get_comments` returned AR/AP empty, and inbound `xref_query` returned total 0/`{}`; Encoder remained the exact seven-member 20-byte UDT and Decoder remained absent, preserving A01/A02. Exact 16-byte head reads matched the documented bodies, including the local-allocation prologues at A12/A13/A30/A31. Complete range-bounded instruction scans were non-truncated. The following literal scan receipts establish only stack-use/cleanup and the finite argument slots; local references are evidence of machine behavior, not permission to promise a physical local row after D or T.

| Action | Scanned instructions | Literal EBP stack references from bounded scan | Literal returns | Source-level argument-layout evidence; not an IDA poststate or mutation |
| --- | ---: | --- | --- | --- |
| A08 | 51 | `[ebp+8]` | `retn 4` | `value@+0x14/0x4` |
| A10 | 46 | `[ebp+8]`, `[ebp+0Ch]` | `retn 8` | `text@+0xC/0x4`, `charCount@+0x10/0x4` |
| A11 | 61 | `[ebp+8]`, `[ebp+0Ch]` | `retn 8` | `text@+0xC/0x4`, `charCount@+0x10/0x4` |
| A12 | 93 | `[ebp-4]`, `[ebp+8]` | `retn 8` | `text@+0x110/0x4`, `charCount@+0x114/0x4` |
| A13 | 106 | `[ebp-4]`, `[ebp+8]` | `retn 8` | `text@+0x10010/0x4`, `charCount@+0x10014/0x4` |
| A14 | 65 | `[ebp+0Ch]` | `retn 8` | `text@+0xC/0x4`, `charCount@+0x10/0x4` |
| A16 | 73 | `[ebp+0Ch]` | `retn 8` | `data@+0x10/0x4`, `byteCount@+0x14/0x4` |
| A17 | 15 | `[ebp+8]` | `retn 4` | `byteCount@+0x8/0x4` |
| A23 | 6 | `[ebp+8]` | `retn 4` | `useBigEndian@+0x8/0x1` |
| A28 | 56 | `[ebp+8]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x10/0x4`, `capacityChars@+0x14/0x4`, `outChars@+0x18/0x4` |
| A29 | 76 | `[ebp-4]`, `[ebp+8]`, `[ebp+0Ch]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x14/0x4`, `capacityChars@+0x18/0x4`, `outChars@+0x1C/0x4` |
| A30 | 93 | `[ebp-4]`, `[ebp-104h]`, `[ebp-108h]`, `[ebp-10Ch]`, `[ebp+8]`, `[ebp+0Ch]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x11C/0x4`, `capacityChars@+0x120/0x4`, `outChars@+0x124/0x4` |
| A31 | 118 | `[ebp-4]`, `[ebp-10004h]` through `[ebp-10018h]`, `[ebp+8]`, `[ebp+0Ch]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x10028/0x4`, `capacityChars@+0x1002C/0x4`, `outChars@+0x10030/0x4` |
| A32 | 90 | `[ebp-4]`, `[ebp+8]`, `[ebp+0Ch]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x10/0x4`, `capacityChars@+0x14/0x4`, `outChars@+0x18/0x4` |
| A33 | 30 | `[ebp+8]`, `[ebp+0Ch]` | `retn 8` | `out@+0xC/0x4`, `byteCount@+0x10/0x4` |
| A34 | 70 | `[ebp-4]`, `[ebp+8]`, `[ebp+0Ch]`, `[ebp+10h]` | `retn 0Ch` | `out@+0x14/0x4`, `outCapacity@+0x18/0x4`, `outBytes@+0x1C/0x4` |
| A35 | 15 | `[ebp+8]` | `retn 4` | `byteCount@+0x8/0x4` |
| A36 | 10 | `[ebp+8]`, `[ebp+0Ch]` | `retn 8` | `buffer@+0x8/0x4`, `size@+0xC/0x4` |

The public read-only surface is exhausted for post-type prediction: `inspect_items` and `stack_frame` report only current objects, `insn_query` reports machine instructions, and `type_query` reports current types; none accepts a hypothetical function signature or predicts the physical frame rendered by `set_type`. No mutating endpoint was invoked. Therefore A05 and A08/A10-A14/A16-A17/A23/A28-A36 contain no type endpoint and make no typed-frame claim: definition, pure rename, and both comment requests preserve the exact observed D frame, and function type remains absent. The table's argument facts remain source-reconstruction evidence only. A24-A27 are the only raw rows retaining `set_type`, with exact no-argument prototypes and exact unchanged complete frames.

| ID / classification | Dated 2026-08-15 literal prestate | Conditional public endpoint sequence and mandatory immediate readbacks | Final literal poststate, protected fields, and hard stop |
| --- | --- | --- | --- |
| A03 / apply | Existing function range `[0x004A4E70,0x004A4E94)`, size `0x24`, body SHA256 `FE3668345EABC48140C8F539CDE1C9E18D33A8D0BF140F6C31F01E336C471A9B`; name `Encoder_Encoder`; type `void __thiscall(Encoder *this)`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 1 exact set `{0x0058E4E4}`; inbound data xref count 0 exact set `{}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4E70",name:"Encoder_Constructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must be range/hash/size above, name `Encoder_Constructor`, same type and complete frame, AR/AP/FR/FP absent, code count/set 1/`{0x0058E4E4}`, data count/set 0/`{}`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4E70",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat that complete state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4E70",comment:"Initializes Encoder buffer/cursor state and the Encoder vtable."}})`. Immediate readback must repeat that complete state with both exact comments. | Final: same range, size, SHA256, type, complete frame, AR absent, AP absent, and exact xref counts/sets; name `Encoder_Constructor`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Initializes Encoder buffer/cursor state and the Encoder vtable.`. Owned fields are name, FR, FP only. Protect bytes/body identity, range, size, type, every frame row/offset/size/type, AR, AP, xrefs, and neighboring padding. Hard-stop before or after any endpoint on any literal prestate/readback mismatch, collision, endpoint failure, range growth, byte change, frame/type/xref/address-comment change, or other unowned delta. |
| A04 / apply | Existing function range `[0x004A4EA0,0x004A4EA7)`, size `0x7`, body SHA256 `43D6BA2B81AD5A55D655D6F8CA8A9C0947909B3654085B8CE11282A490160660`; name `Encoder_destructor`; type `void __thiscall(Encoder *this)`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 2 exact set `{0x0058E66C,0x0060970C}`; inbound data xref count 0 exact set `{}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4EA0",name:"Encoder_Destructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must be the same range/hash/size/type/frame/comments/xrefs with name `Encoder_Destructor`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EA0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EA0",comment:"Ordinary empty Encoder destructor; virtual source declaration generates deleting teardown."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A4EA0,0x004A4EA7)`, size `0x7`, the full SHA256 above, name `Encoder_Destructor`, type `void __thiscall(Encoder *this)`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 2/`{0x0058E66C,0x0060970C}`, data count/set 0/`{}`. Owned: name, FR, FP. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any prestate/readback mismatch, collision, endpoint failure, or unowned delta. |
| A05 / apply | Dated 2026-08-15 restored raw-code prestate `[0x004A4EB0,0x004A4EBD)`, size `0xD`, SHA256 `A2FE89792C8975BE6A2349700822252976FD564B5B0C077D48560917D87E0D48`, bytes `55 8B EC 8A 45 08 88 41 10 5D C2 04 00`; name/type/frame absent; AR/AP absent; FR/FP absent because no function; code xrefs count/set 0/`{}`, data xrefs count/set 0/`{}`; names `sub_4A4EB0` and `Encoder_SetByteOrder` absent globally. A01 exact poststate is required first. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",end:"0x004A4EBD"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A4EB0` and frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4EB0",name:"Encoder_SetByteOrder"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_SetByteOrder`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_SetByteOrder(Encoder *this, bool useBigEndian)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",comment:"Stores the one-byte Encoder endian selector."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_SetByteOrder`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Stores the one-byte Encoder endian selector.`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",end:"0x004A4EBD"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4EB0",name:"Encoder_SetByteOrder"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EB0",comment:"Stores the one-byte Encoder endian selector."}})`. |
| A06 / apply | Existing function range `[0x004A4EC0,0x004A4EF1)`, size `0x31`, body SHA256 `9916B00E72DBAF929858612BBB6AF6473167CF6F9B060873BFEB733991DE98D9`; name `Encoder_WriteByte`; type `void __thiscall(Encoder *this, unsigned __int8 value)`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *; value@+0x8/0x1/unsigned __int8]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 1 exact set `{0x0058E57B}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EC0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4EC0",comment:"Writes one byte while reserving final terminator capacity."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete frame, AR absent, AP absent, code count/set 1/`{0x0058E57B}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes one byte while reserving final terminator capacity.`. Owned: FR and FP only. Protect bytes/hash/range/size/name/type/every frame field/AR/AP/xrefs/padding. Hard-stop on any prestate/readback mismatch, endpoint failure, or unowned delta. |
| A07 / apply | Existing function range `[0x004A4F00,0x004A4F59)`, size `0x59`, body SHA256 `321549037C4A4C8209BB3F2AB060AEBE4A360EC4FAC24BDD1A495C741D96EBDA`; name `Encoder_WriteShort`; type `void __thiscall(Encoder *this, unsigned __int16 value)`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *; value@+0xC/0x2/unsigned __int16]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 3 exact set `{0x0058E59A,0x0058E5C9,0x0058E5F8}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F00",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F00",comment:"Writes one selected-endian 16-bit value while reserving a terminator."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete frame, AR absent, AP absent, code count/set 3/`{0x0058E59A,0x0058E5C9,0x0058E5F8}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes one selected-endian 16-bit value while reserving a terminator.`. Owned: FR and FP only. Protect bytes/hash/range/size/name/type/every frame field/AR/AP/xrefs/padding. Hard-stop on any prestate/readback mismatch, endpoint failure, or unowned delta. |
| A08 / apply | Dated 2026-08-15 raw-code prestate `[0x004A4F60,0x004A4FE3)`, size `0x83`, SHA256 `8802E155DEDAB3F3B232B32F08091C16C68B6D1209792E07301A2CC1B8074BF5`; name/type/frame absent; AR/AP absent; FR/FP absent because no function; code/data xrefs 0/`{}` and 0/`{}`; names `sub_4A4F60`/`Encoder_WriteTriByte` absent. A01 is required first. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",end:"0x004A4FE3"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A4F60` and frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4F60",name:"Encoder_WriteTriByte"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteTriByte`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteTriByte(Encoder *this, unsigned int value)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",comment:"Writes the low 24 bits in selected byte order."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteTriByte`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes the low 24 bits in selected byte order.`; frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",end:"0x004A4FE3"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A4F60",name:"Encoder_WriteTriByte"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4F60",comment:"Writes the low 24 bits in selected byte order."}})`. |
| A09 / apply | Existing function range `[0x004A4FF0,0x004A506B)`, size `0x7B`, body SHA256 `F42557F72905AF98F51C245BEBC41A24B5EC0EDFCFEB4ED0369E00A08567009A`; name `Encoder_WriteInt`; type `void __thiscall(Encoder *this, unsigned int value)`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *; value@+0xC/0x4/unsigned int]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 1 exact set `{0x0058E58B}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4FF0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A4FF0",comment:"Writes one selected-endian 32-bit value while reserving a terminator."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete frame, AR absent, AP absent, code count/set 1/`{0x0058E58B}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes one selected-endian 32-bit value while reserving a terminator.`. Owned: FR and FP only. Protect bytes/hash/range/size/name/type/every frame field/AR/AP/xrefs/padding. Hard-stop on any prestate/readback mismatch, endpoint failure, or unowned delta. |
| A10 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5070,0x004A50E3)`, size `0x73`, SHA256 `03815E4EC890DEBD9FB1FA0583AC2C69F0E22463B2AAA70DAC3F5D8CE92C270F`; name/type/frame absent; AR/AP absent; FR/FP absent because no function; code/data xrefs both 0 exact `{}`; `sub_4A5070`/`Encoder_WriteWideString8` absent. A01 first. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",end:"0x004A50E3"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5070` and frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5070",name:"Encoder_WriteWideString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteWideString8`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteWideString8(Encoder *this, const wchar_t *text, int charCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",comment:"Writes an 8-bit wchar count and native wide payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteWideString8`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes an 8-bit wchar count and native wide payload.`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",end:"0x004A50E3"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5070",name:"Encoder_WriteWideString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5070",comment:"Writes an 8-bit wchar count and native wide payload."}})`. |
| A11 / apply | Dated 2026-08-15 raw-code prestate `[0x004A50F0,0x004A5189)`, size `0x99`, SHA256 `F490A878C7E0A00CBD265FF46C16979C4E1B14FD096D96AEA1C4F842D764FD23`; no function/name/type/frame/comments; AR/AP absent; code/data xrefs 0/`{}`; `sub_4A50F0`/`Encoder_WriteWideString16` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",end:"0x004A5189"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A50F0` and frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A50F0",name:"Encoder_WriteWideString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteWideString16`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteWideString16(Encoder *this, const wchar_t *text, int charCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",comment:"Writes a selected-endian 16-bit wchar count and native wide payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteWideString16`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Writes a selected-endian 16-bit wchar count and native wide payload.`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",end:"0x004A5189"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A50F0",name:"Encoder_WriteWideString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A50F0",comment:"Writes a selected-endian 16-bit wchar count and native wide payload."}})`. |
| A12 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5190,0x004A5293)`, size `0x103`, SHA256 `D55474F050D231B41DBFE4C97206E6D4A0CCC4DBBC70F22AF0B01488E63BE3B6`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5190`/`Encoder_WriteAnsiString8` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",end:"0x004A5293"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5190` and frame exactly `[__saved_registers@+0x108/0x4/_DWORD; __return_address@+0x10C/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5190",name:"Encoder_WriteAnsiString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteAnsiString8`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteAnsiString8(Encoder *this, const wchar_t *text, int charCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",comment:"Converts CP_ACP text into a clamped 8-bit-length payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteAnsiString8`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Converts CP_ACP text into a clamped 8-bit-length payload.`; frame exactly `[__saved_registers@+0x108/0x4/_DWORD; __return_address@+0x10C/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",end:"0x004A5293"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5190",name:"Encoder_WriteAnsiString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5190",comment:"Converts CP_ACP text into a clamped 8-bit-length payload."}})`. |
| A13 / apply | Dated 2026-08-15 raw-code prestate `[0x004A52A0,0x004A53CA)`, size `0x12A`, SHA256 `033BC29EC38BE57420C4AE5DA12FB8D92C1EEA79AD8FE2F347D35118755FF496`; function/name/type/frame/comments absent; AR/AP absent; xrefs 0/`{}`; `sub_4A52A0`/`Encoder_WriteAnsiString16` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",end:"0x004A53CA"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A52A0` and frame exactly `[__saved_registers@+0x10008/0x4/_DWORD; __return_address@+0x1000C/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A52A0",name:"Encoder_WriteAnsiString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteAnsiString16`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteAnsiString16(Encoder *this, const wchar_t *text, int charCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",comment:"Converts CP_ACP text into a clamped selected-endian 16-bit-length payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteAnsiString16`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Converts CP_ACP text into a clamped selected-endian 16-bit-length payload.`; frame exactly `[__saved_registers@+0x10008/0x4/_DWORD; __return_address@+0x1000C/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",end:"0x004A53CA"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A52A0",name:"Encoder_WriteAnsiString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A52A0",comment:"Converts CP_ACP text into a clamped selected-endian 16-bit-length payload."}})`. |
| A14 / apply | Dated 2026-08-15 raw-code prestate `[0x004A53D0,0x004A5472)`, size `0xA2`, SHA256 `54301901D5C98FA5D370E0A143F767AE1EE8D540B429BB18E7712B0B8492D5DB`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A53D0`/`Encoder_WriteCString` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",end:"0x004A5472"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A53D0` and frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A53D0",name:"Encoder_WriteCString"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteCString`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteCString(Encoder *this, const wchar_t *text, int charCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",comment:"Converts and writes NUL-terminated CP_ACP text; historical temporary leak is preserved."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteCString`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Converts and writes NUL-terminated CP_ACP text; historical temporary leak is preserved.`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",end:"0x004A5472"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A53D0",name:"Encoder_WriteCString"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A53D0",comment:"Converts and writes NUL-terminated CP_ACP text; historical temporary leak is preserved."}})`. |
| A15 / apply | Existing function range `[0x004A5480,0x004A54C6)`, size `0x46`, body SHA256 `BB508128120674A83ECA58226F4096FEFA5785EA5F79CB4BBF821DAB96290856`; name `Encoder_WriteBytes`; type `void __thiscall(Encoder *this, const void *data, unsigned int byteCount)`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *; Src@+0xC/0x4/void *; Size@+0x10/0x4/size_t]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 4 exact set `{0x0058E56E,0x0058E5BA,0x0058E5E3,0x0058E612}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5480",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5480",comment:"Copies bytes through MemoryMan after signed reserve-byte bounds validation."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete four-row frame, AR absent, AP absent, code count/set 4/`{0x0058E56E,0x0058E5BA,0x0058E5E3,0x0058E612}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Copies bytes through MemoryMan after signed reserve-byte bounds validation.`. Owned: FR and FP only. Preserve the dated 2026-08-15 unsigned prototype and physical `Src/Size` frame while formal source records the signed interpretation. Protect bytes/hash/range/size/name/type/all frame fields/AR/AP/xrefs/padding. Hard-stop on any prestate/readback mismatch, endpoint failure, or unowned delta. |
| A16 / apply | Dated 2026-08-15 raw-code prestate `[0x004A54D0,0x004A558D)`, size `0xBD`, SHA256 `8E5EA6DF5A3B434796234EFB7EE334E8033D6AEE2E66DBD0291D25A738C1DD3D`; function/name/type/frame/comments absent; AR/AP absent; code/data xrefs 0/`{}`; `sub_4A54D0`/`Encoder_WriteCompressedBytes` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",end:"0x004A558D"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A54D0` and frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A54D0",name:"Encoder_WriteCompressedBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_WriteCompressedBytes`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_WriteCompressedBytes(Encoder *this, const void *data, int byteCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",comment:"Compresses, writes a 16-bit length/payload, and preserves ignored status and overflow leak."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_WriteCompressedBytes`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Compresses, writes a 16-bit length/payload, and preserves ignored status and overflow leak.`; frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",end:"0x004A558D"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A54D0",name:"Encoder_WriteCompressedBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A54D0",comment:"Compresses, writes a 16-bit length/payload, and preserves ignored status and overflow leak."}})`. |
| A17 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5590,0x004A55B6)`, size `0x26`, SHA256 `B3DC6A177447875CA0F54DA480148C27A4375C7C0803420381A2705D300CBB49`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5590`/`Encoder_SkipBytes` absent; A01 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",end:"0x004A55B6"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5590` and frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5590",name:"Encoder_SkipBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Encoder_SkipBytes`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Encoder_SkipBytes(Encoder *this, int byteCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",comment:"Advances output cursor without writing while reserving a terminator."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Encoder_SkipBytes`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Advances output cursor without writing while reserving a terminator.`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",end:"0x004A55B6"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5590",name:"Encoder_SkipBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5590",comment:"Advances output cursor without writing while reserving a terminator."}})`. |
| A18 / apply | Existing function range `[0x004A55C0,0x004A55DE)`, size `0x1E`, body SHA256 `9F509287A9B2A77B12FED5F4ADA5FB266638A1252A73414EB646B2C4D16BB36F`; name `Encoder_Initialize`; type `void __thiscall(Encoder *this, unsigned __int8 *buffer, unsigned int capacity)`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *; buffer@+0x8/0x4/unsigned __int8 *; capacity@+0xC/0x4/unsigned int]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 1 exact set `{0x0058E54B}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A55C0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A55C0",comment:"Attaches caller storage and resets Encoder cursor/writable state."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete four-row frame, AR absent, AP absent, code count/set 1/`{0x0058E54B}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Attaches caller storage and resets Encoder cursor/writable state.`. Owned: FR and FP only. Preserve the dated 2026-08-15 unsigned prototype/frame while formal source records signed capacity. Protect bytes/hash/range/size/name/type/all frame fields/AR/AP/xrefs/padding. Hard-stop on any mismatch, endpoint failure, or unowned delta. |
| A19 / apply | Existing function range `[0x004A55E0,0x004A5621)`, size `0x41`, body SHA256 `B369A15463BE97B8431FCD7ACF70AEAD2404EBEB1B768F7C9B66ACCBD1C7DE0D`; name `Encoder_Finalize`; type `bool __thiscall(Encoder *this, unsigned int *outBytesWritten)`; frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *; outBytesWritten@+0x10/0x4/unsigned int *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 1 exact set `{0x0058E624}`; inbound data xref count 0 exact set `{}`. | 1. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A55E0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete range/hash/size/name/type/frame/AR/AP/xref state with FR exactly that text and FP absent. 2. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A55E0",comment:"Reports prior state/count, writes terminator, detaches storage, and resets."}})`. Immediate readback must repeat that complete literal state with both exact comments. | Final: the full prestate range, size, hash, name, type, complete three-row frame, AR absent, AP absent, code count/set 1/`{0x0058E624}`, data count/set 0/`{}`; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reports prior state/count, writes terminator, detaches storage, and resets.`. Owned: FR and FP only. Protect bytes/hash/range/size/name/type/all frame fields/AR/AP/xrefs/padding. Hard-stop on any mismatch, endpoint failure, or unowned delta. |
| A20 / apply | Existing function range `[0x004A5630,0x004A5631)`, size `0x1`, body SHA256 `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`; name `nullsub_27`; type `void()`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 1 exact set `{0x006192D0}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5630",name:"Encoder_NoopVirtual"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Encoder_NoopVirtual`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5630",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5630",comment:"Empty Encoder virtual hook; vtable referenced only."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5630,0x004A5631)`, size `0x1`, full SHA256 above, name `Encoder_NoopVirtual`, type `void()`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 1/`{0x006192D0}`. Owned: name, FR, FP. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A21 / apply | Existing function range `[0x004A5640,0x004A5664)`, size `0x24`, body SHA256 `A3F766040A4434E78A7809E7F1A0274D9F3DEBC5615D5CBAF3F0E6FAD628F7F5`; name `sub_4A5640`; type `_DWORD *__thiscall(_DWORD *this)`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 0 exact set `{}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5640",name:"Decoder_Constructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Decoder_Constructor`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5640",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5640",comment:"Initializes Decoder input/cursor state and returns the constructed object."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5640,0x004A5664)`, size `0x24`, full SHA256 above, name `Decoder_Constructor`, type `_DWORD *__thiscall(_DWORD *this)`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 0/`{}`. Owned: name, FR, FP; preserve the dated generic type/frame because no deterministic type endpoint is authorized. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A22 / apply | Existing function range `[0x004A5670,0x004A5677)`, size `0x7`, body SHA256 `87462F0D1EBF8954054E712492052FB8100DB16589EFB02FD6CFCDB924033D3F`; name `sub_4A5670`; type `void __thiscall(_DWORD *this)`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 0 exact set `{}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5670",name:"Decoder_Destructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Decoder_Destructor`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5670",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5670",comment:"Ordinary empty Decoder destructor."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5670,0x004A5677)`, size `0x7`, full SHA256 above, name `Decoder_Destructor`, type `void __thiscall(_DWORD *this)`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 0/`{}`. Owned: name, FR, FP; preserve the dated generic type/frame. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A23 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5680,0x004A568D)`, size `0xD`, SHA256 `A2FE89792C8975BE6A2349700822252976FD564B5B0C077D48560917D87E0D48`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5680`/`Decoder_SetByteOrder` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",end:"0x004A568D"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5680` and frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5680",name:"Decoder_SetByteOrder"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_SetByteOrder`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_SetByteOrder(Decoder *this, bool useBigEndian)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",comment:"Stores the one-byte Decoder endian selector."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_SetByteOrder`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Stores the one-byte Decoder endian selector.`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",end:"0x004A568D"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5680",name:"Decoder_SetByteOrder"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5680",comment:"Stores the one-byte Decoder endian selector."}})`. |
| A24 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5690,0x004A56B8)`, size `0x28`, SHA256 `BAF03660E923A1924A90C067811ACF940444A85F0CED85E270E5657162F9252B`; function/name/type/frame/comments absent; AR/AP absent; xrefs 0/`{}`; `sub_4A5690`/`Decoder_ReadByte` absent; A02 prerequisite. | D explicit `0x004A5690:0x004A56B8`. Immediate: same body/range/xrefs; `sub_4A5690`; type absent; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]` because the ESI save is path-conditional after an early return; comments absent. R pure rename `Decoder_ReadByte`. T `unsigned char __thiscall Decoder_ReadByte(Decoder *this)`; frame must remain the single return row. C FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads one byte or invalidates on signed bounds failure.`. | Final name/type/comments exact; frame single return row; AR/AP/xrefs absent; bytes/hash/range/gaps exact. D creates only function/default name/frame; R only name; T only prototype; C only comments. Stop on any added saved/argument/local row, collision, range/byte/xref/comment delta, boundary consumption, or endpoint failure. Dated 2026-08-15 literal prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Immediate D literal channel tuple: AR absent; AP absent; FR absent; FP absent. Endpoint payloads: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5690",end:"0x004A56B8"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5690",name:"Decoder_ReadByte"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_type({database:"b002_uid0000hq_rollback_20260815",edits:{addr:"0x004A5690",kind:"function",signature:"unsigned char __thiscall Decoder_ReadByte(Decoder *this)"}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5690",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5690",comment:"Reads one byte or invalidates on signed bounds failure."}})`. |
| A25 / apply | Dated 2026-08-15 raw-code prestate `[0x004A56C0,0x004A570F)`, size `0x4F`, SHA256 `FB47FEEDA9865B6AE923F0ED60F51EBFBE13BBDB893B34FEEBE491FC26462D38`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A56C0`/`Decoder_ReadShort` absent; A02 prerequisite. | D explicit `0x004A56C0:0x004A570F`. Immediate: same body/range/xrefs; `sub_4A56C0`; type absent; frame `[__return_address@+0x4/0x4/_UNKNOWN *]`, with the unconditional saved-ESI slot below it remaining an unrepresented protected gap; comments absent. R pure rename `Decoder_ReadShort`. T `unsigned short __thiscall Decoder_ReadShort(Decoder *this)`; no frame delta. C FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads one selected-endian unsigned 16-bit value.`. | Final exact name/type/comments and one-row frame at +4; AR/AP/xrefs absent; saved-register gap, bytes/hash/range/boundaries protected. D/R/T/C own only function/frame, name, prototype, comments. Stop on any added row, shifted return, collision, byte/range/xref/comment delta, gap consumption, or error. Dated 2026-08-15 literal prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Immediate D literal channel tuple: AR absent; AP absent; FR absent; FP absent. Endpoint payloads: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A56C0",end:"0x004A570F"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A56C0",name:"Decoder_ReadShort"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_type({database:"b002_uid0000hq_rollback_20260815",edits:{addr:"0x004A56C0",kind:"function",signature:"unsigned short __thiscall Decoder_ReadShort(Decoder *this)"}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A56C0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A56C0",comment:"Reads one selected-endian unsigned 16-bit value."}})`. |
| A26 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5710,0x004A576F)`, size `0x5F`, SHA256 `26779C287791079333467DABBE58525AA30B5C149A260F199C7F2ECB503175CE`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5710`/`Decoder_ReadTriByte` absent; A02 prerequisite. | D explicit `0x004A5710:0x004A576F`. Immediate: same body/range/xrefs; `sub_4A5710`; type absent; frame `[__return_address@+0x4/0x4/_UNKNOWN *]`, saved-ESI gap protected; comments absent. R pure rename `Decoder_ReadTriByte`. T `unsigned int __thiscall Decoder_ReadTriByte(Decoder *this)`; frame unchanged. C FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads one selected-endian unsigned 24-bit value.`. | Final exact R/T/C state and +4 return frame; AR/AP/xrefs absent; bytes/hash/range/saved gap/CC boundaries protected. Only D/R/T/C owned deltas allowed. Stop on added/shifted frame rows, collision, byte/range/xref/comment change, padding consumption, or endpoint error. Dated 2026-08-15 literal prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Immediate D literal channel tuple: AR absent; AP absent; FR absent; FP absent. Endpoint payloads: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5710",end:"0x004A576F"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5710",name:"Decoder_ReadTriByte"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_type({database:"b002_uid0000hq_rollback_20260815",edits:{addr:"0x004A5710",kind:"function",signature:"unsigned int __thiscall Decoder_ReadTriByte(Decoder *this)"}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5710",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5710",comment:"Reads one selected-endian unsigned 24-bit value."}})`. |
| A27 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5770,0x004A57DC)`, size `0x6C`, SHA256 `7B023D4EC16DFCF6935989818390FE5C58B27C5B0E3B4E6205B6E87C21FF37E6`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5770`/`Decoder_ReadInt` absent; A02 prerequisite. | D explicit `0x004A5770:0x004A57DC`. Immediate: same body/range/xrefs; `sub_4A5770`; type absent; frame `[__return_address@+0x4/0x4/_UNKNOWN *]`, saved-ESI gap protected; comments absent. R pure rename `Decoder_ReadInt`. T `unsigned int __thiscall Decoder_ReadInt(Decoder *this)`; frame unchanged. C FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads one selected-endian unsigned 32-bit value.`. | Final exact name/type/comments/frame; AR/AP/xrefs absent; bytes/hash/range/gaps exact. D/R/T/C own only function/frame, name, prototype, comments. Stop on any unexpected frame member/offset, collision, boundary/byte/xref/comment change, or endpoint failure. Dated 2026-08-15 literal prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Immediate D literal channel tuple: AR absent; AP absent; FR absent; FP absent. Endpoint payloads: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5770",end:"0x004A57DC"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5770",name:"Decoder_ReadInt"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_type({database:"b002_uid0000hq_rollback_20260815",edits:{addr:"0x004A5770",kind:"function",signature:"unsigned int __thiscall Decoder_ReadInt(Decoder *this)"}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5770",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5770",comment:"Reads one selected-endian unsigned 32-bit value."}})`. |
| A28 / apply | Dated 2026-08-15 raw-code prestate `[0x004A57E0,0x004A5861)`, size `0x81`, SHA256 `0BB75D14A28AEEE9C078D1B226071FBDE26D3E9751F12834C1D632048342979C`; no function/name/type/frame/comments; AR/AP absent; code/data xrefs 0/`{}`; `sub_4A57E0`/`Decoder_ReadWideString8` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",end:"0x004A5861"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A57E0` and frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A57E0",name:"Decoder_ReadWideString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadWideString8`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadWideString8(Decoder *this, wchar_t *out, int capacityChars, int *outChars)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",comment:"Reads an 8-bit count and native wide payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadWideString8`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads an 8-bit count and native wide payload.`; frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",end:"0x004A5861"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A57E0",name:"Decoder_ReadWideString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A57E0",comment:"Reads an 8-bit count and native wide payload."}})`. |
| A29 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5870,0x004A5925)`, size `0xB5`, SHA256 `A3106DA0E4873D838E1DDCFB4A44635C72D5EC275DEC7C5A7BBA9FE8F06F7EF0`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5870`/`Decoder_ReadWideString16` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",end:"0x004A5925"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5870` and frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5870",name:"Decoder_ReadWideString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadWideString16`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadWideString16(Decoder *this, wchar_t *out, int capacityChars, int *outChars)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",comment:"Reads a selected-endian 16-bit count and native wide payload."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadWideString16`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads a selected-endian 16-bit count and native wide payload.`; frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",end:"0x004A5925"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5870",name:"Decoder_ReadWideString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5870",comment:"Reads a selected-endian 16-bit count and native wide payload."}})`. |
| A30 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5930,0x004A5A3A)`, size `0x10A`, SHA256 `F0A914175E65757319469DF7D8C4293D129C34CA20604DE0D109D4CFEB53308C`; function/name/type/frame/comments absent; AR/AP absent; xrefs 0/`{}`; `sub_4A5930`/`Decoder_ReadAnsiString8` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",end:"0x004A5A3A"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5930` and frame exactly `[__saved_registers@+0x114/0x4/_DWORD; __return_address@+0x118/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5930",name:"Decoder_ReadAnsiString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadAnsiString8`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadAnsiString8(Decoder *this, wchar_t *out, int capacityChars, int *outChars)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",comment:"Reads counted ACP bytes and converts them to wide text."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadAnsiString8`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads counted ACP bytes and converts them to wide text.`; frame exactly `[__saved_registers@+0x114/0x4/_DWORD; __return_address@+0x118/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",end:"0x004A5A3A"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5930",name:"Decoder_ReadAnsiString8"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5930",comment:"Reads counted ACP bytes and converts them to wide text."}})`. |
| A31 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5A40,0x004A5BA7)`, size `0x167`, SHA256 `D435773AD4D6C644E817C408BD05F30FDC7B0BAE9D9FA8EDE706EBF589D30EB9`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5A40`/`Decoder_ReadAnsiString16` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",end:"0x004A5BA7"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5A40` and frame exactly `[__saved_registers@+0x10020/0x4/_DWORD; __return_address@+0x10024/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5A40",name:"Decoder_ReadAnsiString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadAnsiString16`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadAnsiString16(Decoder *this, wchar_t *out, int capacityChars, int *outChars)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",comment:"Reads selected-endian counted ACP bytes and converts them to wide text."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadAnsiString16`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads selected-endian counted ACP bytes and converts them to wide text.`; frame exactly `[__saved_registers@+0x10020/0x4/_DWORD; __return_address@+0x10024/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",end:"0x004A5BA7"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5A40",name:"Decoder_ReadAnsiString16"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5A40",comment:"Reads selected-endian counted ACP bytes and converts them to wide text."}})`. |
| A32 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5BB0,0x004A5C7E)`, size `0xCE`, SHA256 `6E89188B9F706DEB409B850A36CDA023409650E7E4699C50C74792561CE145D0`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5BB0`/`Decoder_ReadCString` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",end:"0x004A5C7E"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5BB0` and frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5BB0",name:"Decoder_ReadCString"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadCString`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadCString(Decoder *this, wchar_t *out, int capacityChars, int *outChars)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",comment:"Reads one NUL-terminated ACP string and advances through its terminator."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadCString`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads one NUL-terminated ACP string and advances through its terminator.`; frame exactly `[__saved_registers@+0x8/0x4/_DWORD; __return_address@+0xC/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",end:"0x004A5C7E"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5BB0",name:"Decoder_ReadCString"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5BB0",comment:"Reads one NUL-terminated ACP string and advances through its terminator."}})`. |
| A33 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5C80,0x004A5CC4)`, size `0x44`, SHA256 `9781C8B449DC75AD42B5B89082F5FFE2BB31C19713F818C34F48ED936BE1E54D`; no function/name/type/frame/comments; AR/AP absent; code/data xrefs 0/`{}`; `sub_4A5C80`/`Decoder_ReadBytes` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",end:"0x004A5CC4"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5C80` and frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5C80",name:"Decoder_ReadBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadBytes`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadBytes(Decoder *this, void *out, int byteCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",comment:"Copies a signed byte count and advances after success."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadBytes`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Copies a signed byte count and advances after success.`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",end:"0x004A5CC4"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5C80",name:"Decoder_ReadBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5C80",comment:"Copies a signed byte count and advances after success."}})`. |
| A34 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5CD0,0x004A5D79)`, size `0xA9`, SHA256 `8B6CECC175A9C30BCA4C3069389ADAA01A5D11F6E1F1CE6693E9DDA27A32FCDC`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5CD0`/`Decoder_ReadCompressedBytes` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",end:"0x004A5D79"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5CD0` and frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5CD0",name:"Decoder_ReadCompressedBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_ReadCompressedBytes`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_ReadCompressedBytes(Decoder *this, void *out, unsigned int outCapacity, unsigned int *outBytes)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",comment:"Reads selected compressed length, ignores zlib status, then validates produced size."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_ReadCompressedBytes`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Reads selected compressed length, ignores zlib status, then validates produced size.`; frame exactly `[__saved_registers@+0xC/0x4/_DWORD; __return_address@+0x10/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",end:"0x004A5D79"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5CD0",name:"Decoder_ReadCompressedBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5CD0",comment:"Reads selected compressed length, ignores zlib status, then validates produced size."}})`. |
| A35 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5D80,0x004A5DA6)`, size `0x26`, SHA256 `B3DC6A177447875CA0F54DA480148C27A4375C7C0803420381A2705D300CBB49`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5D80`/`Decoder_SkipBytes` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",end:"0x004A5DA6"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5D80` and frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5D80",name:"Decoder_SkipBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_SkipBytes`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_SkipBytes(Decoder *this, int byteCount)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",comment:"Advances read cursor only when one byte remains beyond the skip."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_SkipBytes`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Advances read cursor only when one byte remains beyond the skip.`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",end:"0x004A5DA6"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5D80",name:"Decoder_SkipBytes"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5D80",comment:"Advances read cursor only when one byte remains beyond the skip."}})`. |
| A36 / apply | Dated 2026-08-15 raw-code prestate `[0x004A5DB0,0x004A5DCE)`, size `0x1E`, SHA256 `9F509287A9B2A77B12FED5F4ADA5FB266638A1252A73414EB646B2C4D16BB36F`; no function/name/type/frame/comments; AR/AP absent; xrefs 0/`{}`; `sub_4A5DB0`/`Decoder_Initialize` absent; A02 prerequisite. | D: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",end:"0x004A5DCE"}})`. Immediate D readback must repeat the exact prestate range/size/SHA256/bytes and code/data xref counts/sets, create only name `sub_4A5DB0` and frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`, leave function type absent, and leave AR/AP/FR/FP absent; this is the exact D frame physically observed by the supervisor on 2026-08-15. R: only after that complete D tuple, run `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5DB0",name:"Decoder_Initialize"},pure:true,allow_overwrite:false,stop_on_error:true}})`; immediate R readback must repeat the complete D tuple with only the name changed to `Decoder_Initialize`. No `set_type` request is authorized: bounded read-only APIs cannot prove one literal complete physical post-type frame for reconstructed source signature `void __thiscall Decoder_Initialize(Decoder *this, const unsigned char *buffer, int size)`, so IDA function type must remain absent. C1: only after the exact R readback, run `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; immediate readback must repeat the complete R tuple and exact frame with only FR changed. C2: run `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",comment:"Attaches input storage and resets Decoder cursor/valid state."}})`; immediate readback must repeat the complete C1 tuple and exact frame with only FP changed. | Final name `Decoder_Initialize`; function type absent; FR `BinaryCodec retained source method; see UID0000HQ whole-file reconstruction.`; FP `Attaches input storage and resets Decoder cursor/valid state.`; frame exactly `[__saved_registers@+0x0/0x4/_DWORD; __return_address@+0x4/0x4/_UNKNOWN *]`; AR/AP absent; code/data xref counts/sets 0/`{}` and 0/`{}`; exact prestate range/size/SHA256/bytes, body identity, boundaries, and adjacent gaps unchanged. Owned deltas: D function object/default name/exact two-row frame; R name only; C1 FR only; C2 FP only. Protect function type as absent and every D frame row/name/type/offset/width byte-for-byte. Hard-stop before every successor on database/session mismatch, collision, range/size/SHA256/byte/xref/address-comment mismatch, any frame addition/removal/rename/retype/reorder, any function-type creation, boundary consumption, comment-channel drift, or endpoint error. Dated raw prestate tuple: function name absent; function type absent; frame absent because no function object; AR absent; AP absent; FR absent because no function object; FP absent because no function object. Exact public requests: `define_func({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",end:"0x004A5DCE"}})`; `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5DB0",name:"Decoder_Initialize"},pure:true,allow_overwrite:false,stop_on_error:true}})`; `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`; `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DB0",comment:"Attaches input storage and resets Decoder cursor/valid state."}})`. |
| A37 / apply | Existing function range `[0x004A5DD0,0x004A5DED)`, size `0x1D`, body SHA256 `867F1089E1E889E60520EAE61EA2427DF6578DA949B211045309FE5BA87F2050`; name `sub_4A5DD0`; type `char __thiscall(int this)`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 0 exact set `{}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5DD0",name:"Decoder_Finalize"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Decoder_Finalize`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DD0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DD0",comment:"Returns prior validity, detaches input, and resets without consumption check."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5DD0,0x004A5DED)`, size `0x1D`, full SHA256 above, name `Decoder_Finalize`, type `char __thiscall(int this)`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 0/`{}`. Owned: name, FR, FP; preserve the dated generic type/frame. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A38 / apply | Existing function range `[0x004A5DF0,0x004A5DF1)`, size `0x1`, body SHA256 `AE3F4619B0413D70D3004B9131C3752153074E45725BE13B9A148978895E359E`; name `nullsub_28`; type `void()`; frame exactly `[__return_address@+0x0/0x4/_UNKNOWN *]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 1 exact set `{0x006192DC}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5DF0",name:"Decoder_NoopVirtual"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Decoder_NoopVirtual`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DF0",comment:"BinaryCodec retained source method; see UID0000HQ whole-file reconstruction."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5DF0",comment:"Empty Decoder virtual hook; vtable referenced only."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5DF0,0x004A5DF1)`, size `0x1`, full SHA256 above, name `Decoder_NoopVirtual`, type `void()`, frame `[__return_address@+0x0/0x4/_UNKNOWN *]`, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 1/`{0x006192DC}`. Owned: name, FR, FP. Protect bytes/hash/range/size/type/frame/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A39 / apply | Existing function range `[0x004A5E00,0x004A5E24)`, size `0x24`, body SHA256 `4106387B929618A5D9FB042DBDFFBE4326C7F4C1CFE46A2F35677EDE5B598584`; name `sub_4A5E00`; type `_DWORD *__thiscall(_DWORD *Block, char)`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *; arg_0@+0xC/0x1/char]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 1 exact set `{0x006192D8}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5E00",name:"Decoder_ScalarDeletingDestructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Decoder_ScalarDeletingDestructor`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5E00",comment:"Compiler-generated BinaryCodec ABI wrapper; no authored source body."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5E00",comment:"Compiler-generated Decoder deleting wrapper; source is the ordinary virtual destructor."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5E00,0x004A5E24)`, size `0x24`, full SHA256 above, name `Decoder_ScalarDeletingDestructor`, type `_DWORD *__thiscall(_DWORD *Block, char)`, complete three-row frame above, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 1/`{0x006192D8}`. Owned: name, FR, FP; preserve the dated generic type and `Block/arg_0` frame. Protect bytes/hash/range/size/type/all frame fields/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |
| A40 / apply | Existing function range `[0x004A5E30,0x004A5E54)`, size `0x24`, body SHA256 `7DB36FB166B1026C178B8C61EC94CA734E9A2B71C0662FE3F4089F6FDA3E520B`; name `sub_4A5E30`; type `_DWORD *__thiscall(_DWORD *Block, char)`; frame exactly `[__saved_registers@+0x4/0x4/_DWORD; __return_address@+0x8/0x4/_UNKNOWN *; arg_0@+0xC/0x1/char]`; AR absent; AP absent; FR absent; FP absent; inbound code xref count 0 exact set `{}`; inbound data xref count 1 exact set `{0x006192CC}`. | 1. `rename({database:"b002_uid0000hq_rollback_20260815",batch:{func:{addr:"0x004A5E30",name:"Encoder_ScalarDeletingDestructor"},pure:true,allow_overwrite:false,stop_on_error:true}})`. Immediate readback must repeat the complete range/hash/size/type/frame/comments/xrefs with name `Encoder_ScalarDeletingDestructor`. 2. `set_function_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5E30",comment:"Compiler-generated BinaryCodec ABI wrapper; no authored source body."}})`. Immediate readback must repeat the complete literal state with FR exactly that text and FP absent. 3. `set_repeatable_comments({database:"b002_uid0000hq_rollback_20260815",items:{addr:"0x004A5E30",comment:"Compiler-generated Encoder deleting wrapper; source is the ordinary virtual destructor."}})`. Immediate readback must repeat the complete literal state with both exact comments. | Final: range `[0x004A5E30,0x004A5E54)`, size `0x24`, full SHA256 above, name `Encoder_ScalarDeletingDestructor`, type `_DWORD *__thiscall(_DWORD *Block, char)`, complete three-row frame above, AR absent, AP absent, exact FR/FP above, code count/set 0/`{}`, data count/set 1/`{0x006192CC}`. Owned: name, FR, FP; preserve the dated generic type and `Block/arg_0` frame. Protect bytes/hash/range/size/type/all frame fields/AR/AP/xrefs/padding. Hard-stop on any mismatch, collision, endpoint failure, or unowned delta. |

### Protected data rows

| ID | Classification | Dated 2026-08-15 literal state and required conditional unchanged readback |
| --- | --- | --- |
| P01 | no change recommended | Encoder record `[0x6192C8,0x6192D4)`, bytes/hash `0E91CE3E9F354AFFDD2CBF246347BADF0141C5B47DB2C388709A7F1CD0413BEB`, values `{0x646B2C,0x4A5E30,0x4A5630}`. At 0x6192C8 dated 2026-08-15 containing item is `word_61929C [0x61929C,0x6192CC)`, type `unsigned short[24]`; AR absent, AP absent, FR absent because data, FP absent because data; no inbound xrefs to 0x6192C8. Do not reshape, rename, type, or comment this interior range. |
| P02 | no change recommended | Decoder record `[0x6192D4,0x6192E0)`, bytes/hash `032E8FF96E6CB81A8D901158A937532B489CBC0DC4BC07BC5A92C1114B62FFFE`, values `{0x646B74,0x4A5E00,0x4A5DF0}`. At 0x6192D4 dated 2026-08-15 item was unnamed data dword with type absent; AR absent, AP absent, FR absent because data, FP absent because data; no inbound xrefs to 0x6192D4. Preserve exact item boundaries/bytes/slots and do not consume 0x6192E0. |
| P03 | no change recommended | Successor 0x6192E0 was the dated 2026-08-15 data head `xmmword_6192E0 [0x6192E0,0x6192F0)`, type absent, AR absent, AP absent, FR absent because data, FP absent because data, with project use at 0x4A5E9E. Preserve it as non-codec ParseEntries data. |

No endpoint call is authorized for P01-P03. These protections are independent of the 40 apply A rows.

## First-Draft C++ Recommendation

Eligible: all 36 authored methods and both complete class declarations. Compiler wrappers, RTTI/vtables, aggregate ranges, alignment, and the successor table are no-code. The following two fences are the complete expected assembled `BinaryCodec.cpp` and `BinaryCodec.h`; implementation distributes method bodies to exact children and declarations/preamble to the two class formal channels without changing text.

**Formal RECONSTRUCTION_CPP CODE assembled result:**

```cpp
#include "BinaryCodec.h"
#include "MemoryMan.h"
#include "../third_party/zlib/zlib.h"
#include <windows.h>
#include <memory.h>
#include <wchar.h>

Encoder::Encoder()
    : m_outputBuffer(NULL),
      m_capacity(0),
      m_writePos(0),
      m_useBigEndian(true),
      m_isWritable(true)
{
}

Encoder::~Encoder()
{
}

void Encoder::SetByteOrder(bool useBigEndian)
{
    m_useBigEndian = useBigEndian;
}

void Encoder::WriteByte(unsigned char value)
{
    if (!m_isWritable)
        return;

    int writePos = m_writePos;
    if (m_capacity < writePos + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[writePos] = value;
    m_writePos = writePos + 1;
}

void Encoder::WriteShort(unsigned short value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) = value;
        m_writePos += 2;
    }
}

void Encoder::WriteTriByte(unsigned int value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 4)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        m_outputBuffer[m_writePos++] = (unsigned char)value;
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
    }
}

void Encoder::WriteInt(unsigned int value)
{
    if (!m_isWritable)
        return;

    if (m_capacity < m_writePos + 5)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 24);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 16);
        m_outputBuffer[m_writePos++] = (unsigned char)(value >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)value;
    }
    else
    {
        *(unsigned int *)(m_outputBuffer + m_writePos) = value;
        m_writePos += 4;
    }
}

void Encoder::WriteWideString8(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    int byteCount = charCount + charCount;
    if (m_capacity < m_writePos + byteCount + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[m_writePos++] = (unsigned char)charCount;
    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        text,
        byteCount);
    m_writePos += byteCount;
}

void Encoder::WriteWideString16(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    int byteCount = charCount + charCount;
    if (m_capacity < m_writePos + byteCount + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(charCount >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)charCount;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)charCount;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        text,
        byteCount);
    m_writePos += byteCount;
}

void Encoder::WriteAnsiString8(const wchar_t *text, int charCount)
{
    char scratch[0x100];

    if (!m_isWritable)
        return;

    int actualChars = (int)wcslen(text);
    if (charCount == -1 || actualChars < charCount)
        charCount = actualChars;

    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        0x100,
        NULL,
        NULL);

    if (0xFF < byteCount)
        byteCount = 0xFF;
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 2)
    {
        m_isWritable = false;
        return;
    }

    m_outputBuffer[m_writePos++] = (unsigned char)byteCount;
    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
}

void Encoder::WriteAnsiString16(const wchar_t *text, int charCount)
{
    char scratch[0x10000];

    if (!m_isWritable)
        return;

    int actualChars = (int)wcslen(text);
    if (charCount == -1 || actualChars < charCount)
        charCount = actualChars;

    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        0x10000,
        NULL,
        NULL);

    if (0xFFFF < byteCount)
        byteCount = 0xFFFF;
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(byteCount >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)byteCount;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)byteCount;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
}

void Encoder::WriteCString(const wchar_t *text, int charCount)
{
    if (!m_isWritable)
        return;

    if (charCount == -1)
        charCount = (int)wcslen(text);

    char *scratch = new char[charCount + charCount + 1];
    int byteCount = WideCharToMultiByte(
        CP_ACP,
        0,
        text,
        charCount,
        scratch,
        charCount + charCount,
        NULL,
        NULL);
    scratch[byteCount] = 0;

    if (m_capacity < m_writePos + byteCount + 1)
    {
        m_isWritable = false;
        return;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        scratch,
        byteCount);
    m_writePos += byteCount;
    m_outputBuffer[m_writePos++] = 0;
}

void Encoder::WriteBytes(const void *data, int byteCount)
{
    if (!m_isWritable)
        return;

    int writePos = m_writePos;
    if (m_capacity < writePos + byteCount + 1)
    {
        m_isWritable = false;
        return;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + writePos,
        data,
        byteCount);
    m_writePos = writePos + byteCount;
}

void Encoder::WriteCompressedBytes(const void *data, int byteCount)
{
    if (!m_isWritable)
        return;

    int bufferSize = ((byteCount + 12) * 11) / 10;
    unsigned char *compressed = new unsigned char[bufferSize];
    unsigned long compressedSize = bufferSize;
    compress(compressed, &compressedSize, (const unsigned char *)data, byteCount);

    if (m_capacity < m_writePos + (int)compressedSize + 3)
    {
        m_isWritable = false;
        return;
    }

    if (m_useBigEndian)
    {
        m_outputBuffer[m_writePos++] = (unsigned char)(compressedSize >> 8);
        m_outputBuffer[m_writePos++] = (unsigned char)compressedSize;
    }
    else
    {
        *(unsigned short *)(m_outputBuffer + m_writePos) =
            (unsigned short)compressedSize;
        m_writePos += 2;
    }

    GetMemoryMan()->MemmoveWrapper(
        m_outputBuffer + m_writePos,
        compressed,
        compressedSize);
    m_writePos += compressedSize;
    delete[] compressed;
}

void Encoder::SkipBytes(int byteCount)
{
    if (!m_isWritable)
        return;

    int nextWritePos = m_writePos + byteCount;
    if (m_capacity < nextWritePos + 1)
    {
        m_isWritable = false;
        return;
    }

    m_writePos = nextWritePos;
}

void Encoder::Initialize(unsigned char *buffer, int capacity)
{
    m_outputBuffer = buffer;
    m_capacity = capacity;
    m_writePos = 0;
    m_isWritable = true;
}

bool Encoder::Finalize(unsigned int *outBytesWritten)
{
    bool wasWritable = m_isWritable;

    if (outBytesWritten != NULL)
        *outBytesWritten = m_writePos;

    m_outputBuffer[m_writePos] = 0;
    m_outputBuffer = NULL;
    m_capacity = 0;
    m_writePos = 0;
    m_isWritable = true;
    return wasWritable;
}

void Encoder::NoopVirtual()
{
}

Decoder::Decoder()
    : m_inputBuffer(NULL),
      m_inputSize(0),
      m_readPos(0),
      m_useBigEndian(true),
      m_isValid(true)
{
}

Decoder::~Decoder()
{
}

void Decoder::SetByteOrder(bool useBigEndian)
{
    m_useBigEndian = useBigEndian;
}

unsigned char Decoder::ReadByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    unsigned char value = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    return value;
}

unsigned short Decoder::ReadShort()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        m_readPos = nextReadPos;
        return (unsigned short)(((unsigned short)high << 8) | low);
    }

    m_readPos = nextReadPos;
    return *(const unsigned short *)src;
}

unsigned int Decoder::ReadTriByte()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 3;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    unsigned int b0 = *src++;
    m_readPos = ++readPos;
    unsigned int b1 = *src++;
    m_readPos = ++readPos;
    unsigned int b2 = *src;
    m_readPos = nextReadPos;

    if (m_useBigEndian)
        return (b0 << 16) | (b1 << 8) | b2;
    return b0 | (b1 << 8) | (b2 << 16);
}

unsigned int Decoder::ReadInt()
{
    if (!m_isValid)
        return 0;

    int readPos = m_readPos;
    int nextReadPos = readPos + 4;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return 0;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    if (m_useBigEndian)
    {
        unsigned int b0 = *src++;
        m_readPos = ++readPos;
        unsigned int b1 = *src++;
        m_readPos = ++readPos;
        unsigned int b2 = *src++;
        m_readPos = ++readPos;
        unsigned int b3 = *src;
        m_readPos = nextReadPos;
        return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
    }

    m_readPos = nextReadPos;
    return *(const unsigned int *)src;
}

void Decoder::ReadWideString8(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;

    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    int charCount = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    int byteCount = charCount + charCount;
    if (m_inputSize < nextReadPos + byteCount || capacityChars < charCount)
    {
        m_isValid = false;
        return;
    }

    if (outChars != NULL)
        *outChars = charCount;
    memmove(out, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    out[charCount] = 0;
}

void Decoder::ReadWideString16(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;

    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int charCount;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        charCount = ((int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        charCount = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    int byteCount = charCount + charCount;
    if (m_inputSize < nextReadPos + byteCount || capacityChars < charCount)
    {
        m_isValid = false;
        return;
    }

    if (outChars != NULL)
        *outChars = charCount;
    memmove(out, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    out[charCount] = 0;
}

void Decoder::ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars)
{
    char scratch[0x100];

    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 1;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    int byteCount = m_inputBuffer[readPos];
    m_readPos = nextReadPos;
    if (m_inputSize < nextReadPos + byteCount)
    {
        m_isValid = false;
        return;
    }

    memmove(scratch, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

void Decoder::ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars)
{
    char scratch[0x10000];

    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int byteCount;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        byteCount = ((int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        byteCount = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    if (m_inputSize < nextReadPos + byteCount)
    {
        m_isValid = false;
        return;
    }

    memmove(scratch, m_inputBuffer + m_readPos, byteCount);
    m_readPos += byteCount;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

void Decoder::ReadCString(wchar_t *out, int capacityChars, int *outChars)
{
    out[0] = 0;
    if (outChars != NULL)
        *outChars = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int inputSize = m_inputSize;
    if (inputSize < readPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    int byteCount = 0;
    while (src[byteCount] != 0)
    {
        ++byteCount;
        if (inputSize < readPos + byteCount)
        {
            m_isValid = false;
            return;
        }
    }

    char *scratch = new char[byteCount + 1];
    memmove(scratch, src, byteCount);
    m_readPos += byteCount + 1;
    scratch[byteCount] = 0;

    int convertedChars = MultiByteToWideChar(
        CP_ACP, 0, scratch, byteCount, out, capacityChars + 1);
    delete[] scratch;

    if (capacityChars < convertedChars)
    {
        out[0] = 0;
        m_isValid = false;
        return;
    }

    out[convertedChars] = 0;
    if (outChars != NULL)
        *outChars = convertedChars;
}

void Decoder::ReadBytes(void *out, int byteCount)
{
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + byteCount;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    memmove(out, m_inputBuffer + readPos, byteCount);
    m_readPos = nextReadPos;
}

void Decoder::ReadCompressedBytes(
    void *out,
    unsigned int outCapacity,
    unsigned int *outBytes)
{
    if (outBytes != NULL)
        *outBytes = 0;
    if (!m_isValid)
        return;

    int readPos = m_readPos;
    int nextReadPos = readPos + 2;
    if (m_inputSize < nextReadPos)
    {
        m_isValid = false;
        return;
    }

    const unsigned char *src = m_inputBuffer + readPos;
    unsigned int compressedLength;
    if (m_useBigEndian)
    {
        unsigned char high = *src++;
        m_readPos = ++readPos;
        unsigned char low = *src;
        compressedLength = ((unsigned int)high << 8) | low;
        m_readPos = nextReadPos;
    }
    else
    {
        compressedLength = *(const unsigned short *)src;
        m_readPos = nextReadPos;
    }

    if (m_inputSize < nextReadPos + (int)compressedLength)
    {
        m_isValid = false;
        return;
    }

    unsigned long producedSize = outCapacity;
    uncompress(
        (unsigned char *)out,
        &producedSize,
        m_inputBuffer + m_readPos,
        compressedLength);
    m_readPos += compressedLength;

    if (outCapacity < producedSize)
    {
        m_isValid = false;
        return;
    }

    if (outBytes != NULL)
        *outBytes = (unsigned int)producedSize;
}

void Decoder::SkipBytes(int byteCount)
{
    if (!m_isValid)
        return;

    int nextReadPos = m_readPos + byteCount;
    if (m_inputSize < nextReadPos + 1)
    {
        m_isValid = false;
        return;
    }

    m_readPos = nextReadPos;
}

void Decoder::Initialize(const unsigned char *buffer, int size)
{
    m_inputBuffer = buffer;
    m_inputSize = size;
    m_readPos = 0;
    m_isValid = true;
}

bool Decoder::Finalize()
{
    bool wasValid = m_isValid;
    m_inputBuffer = NULL;
    m_inputSize = 0;
    m_readPos = 0;
    m_isValid = true;
    return wasValid;
}

void Decoder::NoopVirtual()
{
}
```

**Formal RECONSTRUCTION_H CODE assembled result:**

```cpp
#pragma once

class Encoder
{
public:
    Encoder();
    virtual ~Encoder();

    void SetByteOrder(bool useBigEndian);
    void WriteByte(unsigned char value);
    void WriteShort(unsigned short value);
    void WriteTriByte(unsigned int value);
    void WriteInt(unsigned int value);
    void WriteWideString8(const wchar_t *text, int charCount = -1);
    void WriteWideString16(const wchar_t *text, int charCount = -1);
    void WriteAnsiString8(const wchar_t *text, int charCount = -1);
    void WriteAnsiString16(const wchar_t *text, int charCount = -1);
    void WriteCString(const wchar_t *text, int charCount = -1);
    void WriteBytes(const void *data, int byteCount);
    void WriteCompressedBytes(const void *data, int byteCount);
    void SkipBytes(int byteCount);
    void Initialize(unsigned char *buffer, int capacity);
    bool Finalize(unsigned int *outBytesWritten);
    virtual void NoopVirtual();

private:
    unsigned char *m_outputBuffer;
    int m_capacity;
    int m_writePos;
    bool m_useBigEndian;
    bool m_isWritable;
};
typedef char EncoderSizeMustBe20[(sizeof(Encoder) == 20) ? 1 : -1];

class Decoder
{
public:
    Decoder();
    virtual ~Decoder();

    void SetByteOrder(bool useBigEndian);
    unsigned char ReadByte();
    unsigned short ReadShort();
    unsigned int ReadTriByte();
    unsigned int ReadInt();
    void ReadWideString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadWideString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString8(wchar_t *out, int capacityChars, int *outChars);
    void ReadAnsiString16(wchar_t *out, int capacityChars, int *outChars);
    void ReadCString(wchar_t *out, int capacityChars, int *outChars);
    void ReadBytes(void *out, int byteCount);
    void ReadCompressedBytes(
        void *out,
        unsigned int outCapacity,
        unsigned int *outBytes);
    void SkipBytes(int byteCount);
    void Initialize(const unsigned char *buffer, int size);
    bool Finalize();
    virtual void NoopVirtual();

private:
    const unsigned char *m_inputBuffer;
    int m_inputSize;
    int m_readPos;
    bool m_useBigEndian;
    bool m_isValid;
};

typedef char DecoderSizeMustBe20[(sizeof(Decoder) == 20) ? 1 : -1];
```

Formal-channel mapping:

- UID00004F CPP: the six includes above, blank line, then `[[CHILDREN]]`; H: `#pragma once`, complete Encoder declaration, and Encoder size typedef.
- UID00003M CPP: `[[CHILDREN]]`; H: complete Decoder declaration and Decoder size typedef.
- Each of the 36 exact authored method children owns exactly its definition above. Existing child source must be replaced where signedness/helper spelling differs; no method is duplicated at class level.
- UID0001TS, UID0001X1, UID00013U, UID00013V, UID0003IA, and UID0003IB have blank formal CPP/H and no emitter.
- Third-party import directive: not applicable. BinaryCodec calls the separately reconstructed zlib API; it is not a static third-party source embed.

Behavioral fidelity notes: no added null checks, range normalization, endian abstraction, conversion error handling, zlib status handling, full-consumption validation, or leak cleanup is permitted. C++03-compatible syntax and existing project helper names are used.

## Final Recommendation

- Accept UID0000HQ as the one final BinaryCodec source root and retain all 36 authored methods.
- Create nine Encoder exact children, route every authored child through its direct class, and route both classes to UID0000HQ in address order.
- Emit complete CPP/H through Section 22 formal channels. The final generated source contains two standalone classes and no BinaryCodec base class.
- Reclassify six compiler/layout/vtable support items false/non-emitting; preserve four broad aggregates as false/non-emitting indexes.
- Preserve dead-code findings as liveness history, not as a deletion rationale.
- Leave unrelated ParseEntries data/code, TextEdit implementation, MemoryMan implementation, Win32, zlib, and compiler runtime outside source ownership.
- No source-reconstruction or IDA-handoff research blocker was left by the dated report repair. Section 21 records 40 deterministic conditional A rows with database-bound public requests. All 23 raw rows have explicit-bound definitions; A05 plus the 18 rows whose physical typed frames are not read-only provable stop at pure rename and comments, preserve their exact observed D frames, and leave function type absent. A24-A27 alone retain deterministic no-argument type requests with exact unchanged frames. Current Gate 2B and IDB disposition is external and authoritative only from the current supervisor audit and current bounded IDB readback. Retail lexical spellings and the original object-file split remain inherently unprovable and are reflected only in the confidence cap.

## Recommended Target Doc Changes

Callback status: applied to `by-file/BinaryCodec.md` at full report depth and scoped-validated. The accepted specification below is retained for Gate 2A comparison.

- Target: `by-file/BinaryCodec.md`.
- Raise `86/88` to `94/93`; preserve path `NexusTK/util/` and owner `FILE`; do not add invalid by-file reconstructable/emitter metadata.
- Replace the coordinator-only/separate-root recommendation with the one-file CPP/H result, exact 36+2 code inventory, nine new Encoder children, complete padding/data boundaries, one live caller, dead retained API, signed types, bool endian state, dependencies, formal topology, and generated defects/expected readback.
- Preserve useful historical statements about the earlier three-root hypothesis but label them superseded by this dated whole-file analysis.
- Add links to every new child and all affected support pages; preserve exact range/hash facts and ParseEntries exclusion.

## Recommended Support Doc Changes

Callback status: every ordinary disposition in this table is applied and scoped-validated; MemoryMan remained a verified no-change dependency. Compiler/layout/aggregate pages preserve their direct owners and evidence while emitting no source. The source-tree destination is the actual `by-project-structure/proposed-source-tree.md`.

| Support path/UID | Exact callback disposition |
| --- | --- |
| by-file/Encoder.md 0000J1 | Set path `NONE`; retain evidence as historical/support alias; remove source-root/emitter claims; score 93/92. |
| by-file/Decoder.md 0000IQ | Set path `NONE`; retain evidence as historical/support alias; record entire authored API dead in current retail; score 93/92. |
| by-class/Encoder.md 00004F | Owner/emitter 0000HQ, emitter position 1, 94/93; complete layout/API/liveness; exact CPP/H fragments from Section 22. |
| by-class/Decoder.md 00003M | Owner/emitter 0000HQ, emitter position 2, 94/93; complete layout/API/liveness; exact CPP/H fragments from Section 22. |
| by-type/by-struct/BinaryCodecCursorLayout.md 0001TS | Set reconstructable false, emitter blank, owner 0000HQ; preserve 0x14 paired layout and signed/bool correction; 94/94. |
| by-type/by-vtable/BinaryCodecVtables.md 0001X1 | Set reconstructable false, emitter blank, owner 0000HQ; compiler consequence/no-code; 94/95. |
| Nine new Encoder paths in Section 19 | Create reconstructable true, owner/emitter 00004F, exact positions 3/6/8/9/10/11/12/14/15, scores 91/92 or stronger, complete formal bodies and dead-route evidence. |
| Existing Encoder authored children 00013C/13E/13F/13G/13H/13I/13J/13K/13L | Keep direct owner/emitter 00004F; assign exact positions; correct signed/helper/source details and caller sets; preserve all valid hashes/history. |
| Existing Decoder authored children 00013N/13O/3K8/3K9/3KA/3KB/3KC/3L6/3L7/3L8/3L9/3LA/3LB/3LC/3LD/3LE/13S/13T | Keep direct owner/emitter 00003M; assign positions 1-18; correct bool/signed types, complete zero-route finding, and preserve formal bodies/hashes/history. |
| Scalar wrappers 00013U/00013V | Set reconstructable false, emitter blank, preserve direct class owner, compiler/no-code evidence, exact vtable refs. |
| Vtable data 0003IA/0003IB | Set reconstructable false, emitter blank, preserve direct class owner and exact bytes/slots/boundaries. |
| Aggregates 00013D/00013Q/00013M/000257 | Remain false/non-emitting; update exact complete child/source placement and liveness inventory; preserve unrelated-data exclusion. |
| by-item/EncodeTextEditState_0058E490.md 0000UM | Preserve caller source; add exact sole-consumer conclusion and reject packet/network ownership wording. |
| by-class/MemoryMan.md and exact MemmoveWrapper support | No metadata/code change; preserve accepted `MemmoveWrapper` spelling as external dependency. |
| project-level/proposed-source-tree.md | Replace provisional three roots with `BinaryCodec.cpp` and `BinaryCodec.h`; preserve dated superseded history. |

No other ordinary page is required. If implementation reveals a concrete contradiction in an unlisted page, stop and report it rather than broadening silently.

## Score And Metadata Recommendation

Callback status: all ordinary score/metadata changes below are physically applied. Remaining score uncertainty is the accepted lexical/original-object-name cap, not incomplete ordinary work.

| UID/family | Pre-callback | Recommended | Rationale/cap |
| --- | --- | --- | --- |
| 0000HQ BinaryCodec | 86/88 | 94/93 | Whole file/source/header complete; original filename split and lexical spelling unproved. |
| 00004F Encoder | 88/91 | 94/93 | Complete API/layout/live caller/source; nine names inferred and dead. |
| 00003M Decoder | 87/88 | 94/93 | Complete API/layout/source; entire runtime route absent. |
| 0000J1 / 0000IQ aliases | 87/89, 87/88 | 93/92 each | Evidence complete; no longer standalone source roots. |
| 0001TS layout | 87/91 | 94/94 | Exact offsets/types/size; compiler/source declaration consequence. |
| 0001X1 vtables | 88/92 | 94/95 | Exact bytes/slots/boundaries; compiler-generated. |
| Existing authored children | 87-89 / 90-92 | 92-94 / 93-94 | Exact bodies, formal source, ranges, liveness; lexical cap. |
| New Encoder children | absent | 91/92 minimum | Exact ranges/bodies/source; zero-call and lexical caps. |
| Compiler children | 89-90 / 92-93 | 94/95, false/non-emitting | Exact ABI proof and no-code disposition. |

Score-improvement research resolved the specification blockers: complete raw-body inventory, pointer/xref liveness, one-file placement, class size, signedness, endian representation, helper names, source/header topology, missing Encoder children, compiler classifications, generated omissions, adjacent data exclusion, and deterministic safe IDA action bounds for all 23 authored raw methods. A05 plus 18 rows omit IDA type mutation rather than guessing a physical frame; this narrows IDA presentation work without changing the source reconstruction or its scores. A24-A27 retain exact no-argument type poststates. The recommended scores are supported by the dated ordinary implementation and generated readback and remain below the retail-symbol/object-path cap. These score findings make no assertion about current Gate 2B or IDB status, which is external and authoritative only from the current supervisor audit and current bounded IDB readback.

## Open Questions With Attempted Resolution

| Question | Evidence exhausted | Resolution / impact |
| --- | --- | --- |
| Were Encoder and Decoder historically separate files? | Address/data adjacency, identical pairs, wrappers, RTTI, imports, docs, generated roots, report/path/string searches. | One BinaryCodec file is strongest; separate roots rejected. Lexical certainty caps confidence only. |
| Are dead raw readers removable? | Function/xref/pointer scans, vtables, constructors, callers, dated callback docs. | No. Coherent complete project APIs are retained source; liveness is documented separately. |
| Is there a shared base? | Constructors, RTTI, vptrs, layouts, base-call scan. | No; standalone classes. |
| Are cursor fields unsigned? | Every bounds branch and arithmetic use. | No; signed int. Scalar payloads/zlib sizes remain unsigned. |
| Is endian state enum/byte/bool? | Constructor canonical writes, direct setter width, zero/nonzero tests, class size. | Source bool with one-byte ABI. No enum values beyond false/true are supported. |
| Should Encoder leak paths be repaired? | Complete allocation/free control flow. | No; preserving both observed leaks is required behavioral fidelity. |
| Is 0x6192E0 codec data? | Exact record boundary and ParseEntries xref. | No; excluded. |
| Does BinaryCodec own globals/resources? | Global/string/resource/import/data scans. | No project-authored items found. |
| Can the 23 authored raw methods be safely function-defined despite zero inbound routes? | Exact heads/ends/hashes, complete non-truncated instruction scans, prologue/return cleanup, internal control-flow containment, adjacent CC gaps, dated 2026-08-15 item/comment/xref state, supervisor-observed D frames, and global default/final-name collision queries. | Yes. Every method has a database-bound explicit-range `define_func` contract and exact immediate D frame. A05 plus 18 rows intentionally omit `set_type`; A24-A27 retain exact no-argument type poststates. Zero xrefs affects liveness only. No method requires a no-definition exception. |

The dated investigation left no implementation-blocking source question. Public read-only APIs cannot predict physical post-type frames for A05 and the 18 affected rows, so Section 21 removes those type mutations instead of depending on an unprovable readback after mutation. Their source signatures remain preserved in the formal reconstruction while IDA type stays absent. Unavailable retail symbols/build files could improve lexical/path confidence but would not change behavior or the recommended source topology on the assembled evidence.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

At the dated 2026-08-15 callback freeze, manual files were physically reread read-only after ordinary validation; the listed existing rows were stale at the recorded line contexts and the nine new Encoder rows were absent. The following are literal replacement/insert proposals from that dated comparison. Current manual-coverage disposition is external and authoritative only from the current supervisor audit and current physical by-*/coverage readback; validator-owned generated coverage is not a substitute for that authority.

Physical read-only identities at the callback freeze were: `by-file/-coverage-report.md` SHA256 `5C971E910F83278C34AA30FE28D145BFCEFB9E8AA59A13BC447F8B2C81803DCF`, 170,481 bytes / 320 lines; `by-class/-coverage-report.md` `F409AD0A56FE3AD00196AF3FB7ED01048FEA15446D607A4F4C35117F9BD871C1`, 278,634 / 627; `by-type/by-struct/-coverage-report.md` `CB2D9816D4517A2878C85731014CA8ABA5F8D228D906C07CD0F950445407DAED`, 59,633 / 139; `by-type/by-vtable/-coverage-report.md` `1B8B55639E76519A18F3A3D6EFE6375B74AC44371A414016FA405261AF4BFC25`, 66,384 / 147; `by-memory/-coverage-report.md` `27DF1146E33A8898F68EA55EB209AF5482533A243798BEAD7C04350C0EBA84CC`, 2,225,955 / 4,962; and `by-item/-coverage-report.md` `20CF58FE2A02C1F30D0C76023EABDDD3D7F87FA22F3550AB854F85BFD571C4F0`, 29,613 / 87. Existing target rows were physically observed at by-file lines 35/72/83, by-class 157/186, by-struct 23, by-vtable 27, by-memory 1359-1379 and 4379, and by-item 44; exact raw Decoder and nine new Encoder rows were absent in that dated readback. Current applicability of C67 is determined only by the external current supervisor audit and current physical by-*/coverage readback.

**`by-file/-coverage-report.md` exact replacements:**

- `- [UID:0000HQ][BinaryCodec](by-file/BinaryCodec.md) : reconstructable : 94% : very strong : Complete NexusTK/util/BinaryCodec.cpp/.h reconstruction contains adjacent 18-method Encoder and 18-method Decoder classes, exact 0x14 signed-cursor/bool-endian layouts, one live TextEdit Encoder route, retained-dead remaining API, compiler-covered wrappers/vtables, complete ranges/padding/dependencies, and formal source.`
- `- [UID:0000J1][Encoder](by-file/Encoder.md) : support alias : 93% : strong : Historical Encoder source-root research is preserved, but final authored source routes through UID00004F into UID0000HQ BinaryCodec.cpp/.h; the page has path NONE and records nine live-modeled/retained methods plus nine retained-dead raw methods.`
- `- [UID:0000IQ][Decoder](by-file/Decoder.md) : support alias : 93% : strong : Historical Decoder source-root research is preserved, but final authored source routes through UID00003M into UID0000HQ BinaryCodec.cpp/.h; all 18 authored methods are retained-dead in the current executable while compiler vtable slots remain.`

**`by-class/-coverage-report.md` exact replacements:**

- `- [UID:00004F][Encoder](by-class/Encoder.md) : reconstructable : 94% : very strong : Complete standalone 0x14 Encoder declaration and 18 authored methods route to BinaryCodec.cpp/.h with signed cursor state, bool endian selection, exact reserve-byte behavior, Win32/zlib/MemoryMan dependencies, one TextEdit caller, and nine retained-dead raw methods.`
- `- [UID:00003M][Decoder](by-class/Decoder.md) : reconstructable : 94% : very strong : Complete standalone 0x14 Decoder declaration and 18 authored methods route to BinaryCodec.cpp/.h with signed cursor state, bool endian selection, exact primitive/string/blob/zlib behavior, and exhaustive retained-dead current-runtime evidence.`

**Type coverage exact replacements:**

- `- [UID:0001TS][BinaryCodecCursorLayout](by-type/by-struct/BinaryCodecCursorLayout.md) : not independently reconstructable : 94% : very strong : Exact paired 0x14 Encoder/Decoder ABI has vptr, buffer pointer, signed size/cursor dwords, bool endian/state bytes, and two-byte tail alignment; complete source declarations live on the class H emitters.`
- `- [UID:0001X1][BinaryCodecVtables](by-type/by-vtable/BinaryCodecVtables.md) : not independently reconstructable : 94% : very strong : Exact adjacent Encoder/Decoder RTTI-plus-two-slot vtable records are compiler/linker consequences of virtual destructors and NoopVirtual declarations; no handwritten table data or emitter remains.`

**`by-memory/-coverage-report.md` nine exact permanent-UID inserts:**

- `    - [UID:000512][0x004a4eb0-0x004a4ebd.EncoderSetByteOrder](by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md) 0x004a4eb0-0x004a4ebd | method | EncoderSetByteOrder : reconstructable : 91% : strong : Exact retained-dead one-byte bool endian setter, byte-identical to Decoder SetByteOrder, owned/emitted by Encoder into BinaryCodec.cpp.`
- `    - [UID:000514][0x004a4f60-0x004a4fe3.EncoderWriteTriByte](by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md) 0x004a4f60-0x004a4fe3 | method | EncoderWriteTriByte : reconstructable : 91% : strong : Exact retained-dead selected-endian 24-bit writer with signed reserve-byte capacity checks and complete formal source.`
- `    - [UID:000513][0x004a5070-0x004a50e3.EncoderWriteWideString8](by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md) 0x004a5070-0x004a50e3 | method | EncoderWriteWideString8 : reconstructable : 91% : strong : Exact retained-dead 8-bit wchar-count writer with -1 length discovery, native wide payload, MemoryMan copy, and reserve-byte bounds.`
- `    - [UID:000515][0x004a50f0-0x004a5189.EncoderWriteWideString16](by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md) 0x004a50f0-0x004a5189 | method | EncoderWriteWideString16 : reconstructable : 91% : strong : Exact retained-dead selected-endian 16-bit wchar-count writer with native wide payload, MemoryMan copy, and inline prefix emission.`
- `    - [UID:000516][0x004a5190-0x004a5293.EncoderWriteAnsiString8](by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md) 0x004a5190-0x004a5293 | method | EncoderWriteAnsiString8 : reconstructable : 91% : strong : Exact retained-dead CP_ACP writer with 256-byte scratch, 255 clamp, one-byte count, compiler range/cookie consequences, and MemoryMan copy.`
- `    - [UID:000517][0x004a52a0-0x004a53ca.EncoderWriteAnsiString16](by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md) 0x004a52a0-0x004a53ca | method | EncoderWriteAnsiString16 : reconstructable : 91% : strong : Exact retained-dead CP_ACP writer with 64K stack scratch, 65535 clamp, inline selected-endian count, compiler probe/range/cookie consequences, and MemoryMan copy.`
- `    - [UID:00051A][0x004a53d0-0x004a5472.EncoderWriteCString](by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md) 0x004a53d0-0x004a5472 | method | EncoderWriteCString : reconstructable : 91% : strong : Exact retained-dead NUL-terminated CP_ACP writer preserving allocation, signed bounds, MemoryMan copy, output terminator, and the observed missing temporary release.`
- `    - [UID:000518][0x004a54d0-0x004a558d.EncoderWriteCompressedBytes](by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md) 0x004a54d0-0x004a558d | method | EncoderWriteCompressedBytes : reconstructable : 91% : strong : Exact retained-dead zlib writer preserving bound formula, ignored compress status, inline 16-bit length, MemoryMan copy, success free, and overflow-path leak.`
- `    - [UID:000519][0x004a5590-0x004a55b6.EncoderSkipBytes](by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md) 0x004a5590-0x004a55b6 | method | EncoderSkipBytes : reconstructable : 91% : strong : Exact retained-dead signed cursor advance with one-byte reserve requirement and no output write.`

**Existing authored-child row replacement rule and literal row text:** replace each same-UID row with the following exact line for that UID; all link paths are the existing paths named in Section 14.

- `    - [UID:00013C][0x004a4e70-0x004a4e94.EncoderConstructor](by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md) 0x004a4e70-0x004a4e94 | method | EncoderConstructor : reconstructable : 93% : very strong : Exact live Encoder construction for the sole TextEdit stack object, initializing the 0x14 standalone layout and virtual state before BinaryCodec.cpp use.`
- `    - [UID:00013E][0x004a4ea0-0x004a4ea7.EncoderDestructor](by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md) 0x004a4ea0-0x004a4ea7 | method | EncoderDestructor : reconstructable : 93% : very strong : Exact empty ordinary virtual destructor with normal and same-function EH cleanup TextEdit routes; compiler wrapper remains no-code.`
- `    - [UID:00013F][0x004a4ec0-0x004a4ef1.EncoderWriteByte](by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md) 0x004a4ec0-0x004a4ef1 | method | EncoderWriteByte : reconstructable : 93% : very strong : Exact live one-byte writer with signed bounds, trailing-byte reserve, cursor advance, and failure invalidation.`
- `    - [UID:00013G][0x004a4f00-0x004a4f59.EncoderWriteShort](by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md) 0x004a4f00-0x004a4f59 | method | EncoderWriteShort : reconstructable : 93% : very strong : Exact live selected-endian unsigned 16-bit writer with three TextEdit calls and trailing-byte reserve.`
- `    - [UID:00013H][0x004a4ff0-0x004a506b.EncoderWriteInt](by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md) 0x004a4ff0-0x004a506b | method | EncoderWriteInt : reconstructable : 93% : very strong : Exact live selected-endian unsigned 32-bit writer with signed capacity check and TextEdit magic/state call.`
- `    - [UID:00013I][0x004a5480-0x004a54c6.EncoderWriteBytes](by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md) 0x004a5480-0x004a54c6 | method | EncoderWriteBytes : reconstructable : 93% : very strong : Exact live signed-count writer using GetMemoryMan and MemoryMan::MemmoveWrapper at four TextEdit call sites.`
- `    - [UID:00013J][0x004a55c0-0x004a55de.EncoderInitialize](by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md) 0x004a55c0-0x004a55de | method | EncoderInitialize : reconstructable : 93% : very strong : Exact live attachment of TextEdit's stack buffer with signed 0x7ffe capacity and reset cursor/writable state.`
- `    - [UID:00013K][0x004a55e0-0x004a5621.EncoderFinalize](by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md) 0x004a55e0-0x004a5621 | method | EncoderFinalize : reconstructable : 93% : very strong : Exact live prior-state/count return, terminator write, detach, reset, and TextEdit heap-copy handoff.`
- `    - [UID:00013L][0x004a5630-0x004a5631.EncoderNoopVirtual](by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md) 0x004a5630-0x004a5631 | method | EncoderNoopVirtual : reconstructable : 93% : very strong : Exact empty virtual source method referenced only by the Encoder vtable and emitted into BinaryCodec.cpp.`
- `    - [UID:00013N][0x004a5640-0x004a5664.DecoderConstructor](by-memory/0x004a5640-0x004a5664.DecoderConstructor.md) 0x004a5640-0x004a5664 | method | DecoderConstructor : reconstructable : 93% : very strong : Exact retained-dead 0x14 Decoder construction with null input, signed zero size/cursor, bool endian/valid state, and Decoder vptr.`
- `    - [UID:00013O][0x004a5670-0x004a5677.DecoderDestructor](by-memory/0x004a5670-0x004a5677.DecoderDestructor.md) 0x004a5670-0x004a5677 | method | DecoderDestructor : reconstructable : 93% : very strong : Exact retained-dead empty ordinary virtual destructor; compiler deleting wrapper remains no-code.`
- `    - [UID:0003K8][0x004a5680-0x004a568d.DecoderSetByteOrder](by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md) 0x004a5680-0x004a568d | method | DecoderSetByteOrder : reconstructable : 93% : very strong : Exact retained-dead one-byte bool endian setter, byte-identical to Encoder SetByteOrder.`
- `    - [UID:0003K9][0x004a5690-0x004a56b8.DecoderReadByte](by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md) 0x004a5690-0x004a56b8 | method | DecoderReadByte : reconstructable : 93% : very strong : Exact retained-dead unsigned-byte reader with signed bounds, cursor advance, zero failure result, and validity invalidation.`
- `    - [UID:0003KA][0x004a56c0-0x004a570f.DecoderReadShort](by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md) 0x004a56c0-0x004a570f | method | DecoderReadShort : reconstructable : 93% : very strong : Exact retained-dead selected-endian unsigned 16-bit reader with signed bounds and cursor updates.`
- `    - [UID:0003KB][0x004a5710-0x004a576f.DecoderReadTriByte](by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md) 0x004a5710-0x004a576f | method | DecoderReadTriByte : reconstructable : 93% : very strong : Exact retained-dead selected-endian unsigned 24-bit reader with signed bounds and three byte/cursor steps.`
- `    - [UID:0003KC][0x004a5770-0x004a57dc.DecoderReadInt](by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md) 0x004a5770-0x004a57dc | method | DecoderReadInt : reconstructable : 93% : very strong : Exact retained-dead selected-endian unsigned 32-bit reader with signed bounds and four byte/cursor steps.`
- `    - [UID:0003L6][0x004a57e0-0x004a5861.DecoderReadWideString8](by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md) 0x004a57e0-0x004a5861 | method | DecoderReadWideString8 : reconstructable : 93% : very strong : Exact retained-dead 8-bit wchar-count/native-payload reader with output reset, signed capacity checks, copy, cursor advance, and termination.`
- `    - [UID:0003L7][0x004a5870-0x004a5925.DecoderReadWideString16](by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md) 0x004a5870-0x004a5925 | method | DecoderReadWideString16 : reconstructable : 93% : very strong : Exact retained-dead selected-endian 16-bit wchar-count/native-payload reader with output reset, signed checks, copy, cursor advance, and termination.`
- `    - [UID:0003L8][0x004a5930-0x004a5a3a.DecoderReadAnsiString8](by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md) 0x004a5930-0x004a5a3a | method | DecoderReadAnsiString8 : reconstructable : 93% : very strong : Exact retained-dead 8-bit-length ACP reader with 256-byte scratch, memmove, MultiByteToWideChar, signed output checks, and compiler cookie/range consequences.`
- `    - [UID:0003L9][0x004a5a40-0x004a5ba7.DecoderReadAnsiString16](by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md) 0x004a5a40-0x004a5ba7 | method | DecoderReadAnsiString16 : reconstructable : 93% : very strong : Exact retained-dead selected-endian 16-bit-length ACP reader with 64K scratch, conversion, signed checks, and compiler probe/cookie/range consequences.`
- `    - [UID:0003LA][0x004a5bb0-0x004a5c7e.DecoderReadCString](by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md) 0x004a5bb0-0x004a5c7e | method | DecoderReadCString : reconstructable : 93% : very strong : Exact retained-dead NUL scan, allocation/copy, ACP conversion, temporary release, signed output checks, and cursor advance through terminator.`
- `    - [UID:0003LB][0x004a5c80-0x004a5cc4.DecoderReadBytes](by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md) 0x004a5c80-0x004a5cc4 | method | DecoderReadBytes : reconstructable : 93% : very strong : Exact retained-dead signed-count raw copy with bounds invalidation and success-only cursor advance.`
- `    - [UID:0003LC][0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes](by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md) 0x004a5cd0-0x004a5d79 | method | DecoderReadCompressedBytes : reconstructable : 93% : very strong : Exact retained-dead selected-endian compressed length, uncompress call with ignored status, compressed cursor advance, produced-capacity check, and optional output count.`
- `    - [UID:0003LD][0x004a5d80-0x004a5da6.DecoderSkipBytes](by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md) 0x004a5d80-0x004a5da6 | method | DecoderSkipBytes : reconstructable : 93% : very strong : Exact retained-dead signed cursor skip with one-byte remaining-input requirement, byte-identical to the Encoder cursor helper.`
- `    - [UID:0003LE][0x004a5db0-0x004a5dce.DecoderInitialize](by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md) 0x004a5db0-0x004a5dce | method | DecoderInitialize : reconstructable : 93% : very strong : Exact retained-dead const-input attachment with signed size and reset cursor/valid state, byte-identical in field pattern to Encoder initialization.`
- `    - [UID:00013S][0x004a5dd0-0x004a5ded.DecoderFinalize](by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md) 0x004a5dd0-0x004a5ded | method | DecoderFinalize : reconstructable : 93% : very strong : Exact retained-dead prior-validity return, detach/reset behavior, and deliberate absence of full-input consumption validation.`
- `    - [UID:00013T][0x004a5df0-0x004a5df1.DecoderNoopVirtual](by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md) 0x004a5df0-0x004a5df1 | method | DecoderNoopVirtual : reconstructable : 93% : very strong : Exact empty virtual source method referenced only by the Decoder vtable and emitted into BinaryCodec.cpp.`

**Compiler/aggregate by-memory exact replacements:**

- `    - [UID:00013U][0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor](by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md) 0x004a5e00-0x004a5e24 | compiler wrapper | DecoderScalarDeletingDestructor : not independently reconstructable : 94% : very strong : Exact Decoder scalar deleting wrapper referenced only by its vtable; regenerated by the ordinary virtual destructor and never emitted as source.`
- `    - [UID:00013V][0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor](by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md) 0x004a5e30-0x004a5e54 | compiler wrapper | EncoderScalarDeletingDestructor : not independently reconstructable : 94% : very strong : Exact Encoder scalar deleting wrapper referenced only by its vtable; regenerated by the ordinary virtual destructor and never emitted as source.`
- `    - [UID:0003IA][0x006192c8-0x006192d4.EncoderVtableData](by-memory/0x006192c8-0x006192d4.EncoderVtableData.md) 0x006192c8-0x006192d4 | compiler data | EncoderVtableData : not independently reconstructable : 94% : very strong : Exact Encoder COL pointer and two-slot vtable record, compiler-generated from the complete class declaration and protected from handwritten emission.`
- `    - [UID:0003IB][0x006192d4-0x006192e0.DecoderVtableData](by-memory/0x006192d4-0x006192e0.DecoderVtableData.md) 0x006192d4-0x006192e0 | compiler data | DecoderVtableData : not independently reconstructable : 94% : very strong : Exact Decoder COL pointer and two-slot vtable record ending before unrelated 0x006192e0 data, compiler-generated from the complete class declaration.`
- `    - [UID:00013D][0x004a4e70-0x004a5621.EncoderCore](by-memory/0x004a4e70-0x004a5621.EncoderCore.md) 0x004a4e70-0x004a5621 | aggregate index | EncoderCore : not independently reconstructable : 93% : very strong : Complete non-emitting index for all 18 exact Encoder authored methods, nine new raw children, signed/bool layout, one live TextEdit route, retained-dead remainder, and every CC gap.`
- `    - [UID:00013Q][0x004a5680-0x004a5dce.DecoderRawReaderFamily](by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md) 0x004a5680-0x004a5dce | aggregate index | DecoderRawReaderFamily : not independently reconstructable : 94% : very strong : Complete non-emitting index for all 14 exact raw Decoder methods, formal source, signed/bool types, dependencies, gaps, and exhaustive retained-dead route proof.`
- `    - [UID:00013M][0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue](by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md) 0x004a5630-0x004a5e54 | aggregate index | DecoderAndCodecVtableGlue : not independently reconstructable : 93% : very strong : Non-emitting lifecycle/vtable/compiler index covering exact Decoder source children, both no-op slots, both scalar wrappers, all padding, and final BinaryCodec.cpp ownership.`
- `    - [UID:000257][0x006192c6-0x00619340.BinaryCodecDatReadOnlyData](by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md) 0x006192c6-0x00619340 | aggregate index | BinaryCodecDatReadOnlyData : not independently reconstructable : 93% : very strong : Non-emitting data index preserving two exact compiler vtable records, preceding padding, and the excluded 0x006192e0 ParseEntries successor table boundary.`

**Caller coverage exact replacement:**

- `- [UID:0000UM][EncodeTextEditState_0058E490](by-item/EncodeTextEditState_0058E490.md) : reconstructable : 93% : very strong : Sole live BinaryCodec-family consumer constructs a 0x14 Encoder on the stack, attaches one 0x8000 buffer at 0x7ffe usable capacity, serializes text, NUL, 0x6b6f6e67, and three size-prefixed tables, finalizes, and heap-copies the exact byte count; this is state serialization rather than a network-packet route.`

Under the dated callback authority, B002 did not manually edit `auto-generated/-ag-research-tracker.md` or manual coverage; the tracker refreshes from ordinary docs and validator-owned history. Section 28 preserves the exact dated proposals without asserting their current disposition. Current coverage and tracker status is external and authoritative only from the current supervisor audit, current physical by-*/coverage readback, and validator-owned status/history metadata.

## Follow-Up Actions

- Gate 1/Gate 2A audit contract: status is external and authoritative only from the current supervisor audit of the exact artifact, ordinary hashes, receipts, generated identities, formal source, inventory completeness, fixed enums, and IDA handoff.
- Dated accepted-callback receipt: on 2026-08-15 the callback created nine permanent children, updated every listed ordinary page, ran the recorded scoped validators, and obtained the 36-definition/two-declaration generated readback in Sections 31-32.
- IDA contract: current Gate 2B and IDB status is external and authoritative only from the current supervisor audit and current bounded IDB readback; Section 21 supplies database-bound conditional A01-A40/P01-P03 contracts for any action that external authority finds applicable. A05 plus 18 affected rows preserve exact observed D frames and type-absent state through definition, pure rename, and comments only; A24-A27 retain exact no-argument type requests with unchanged frames.
- Coverage contract: current C67/manual-coverage status is external and authoritative only from the current supervisor audit and current physical by-*/coverage readback; Section 28 preserves the dated proposed text.
- Research disposition: this report records no additional B002 source-research recommendation for UID0000HQ absent a concrete contradiction or new original-source artifact.

## Confidence

- Recommendation confidence: high (`93`) for behavior, ownership, boundaries, source topology, layout, and liveness.
- Score confidence: high for the applied 94/93 after callback and physical generated readback.
- Remaining uncertainty: retail lexical spellings, exact access labels, original object filename, and physical typed-frame presentation for A05 plus 18 raw methods are not recoverable from read-only state. Section 21 does not mutate those function types, so this uncertainty creates no post-mutation frame dependency and does not change source behavior, layout, ownership, or scores.

## Validator Results

All file-mode commands below ran from exact working directory `C:\FastStorage\NTK_Sources\source-3\project-documentation`. Each exact command is single-line inline text, not an executable fence. Every command exited `0` with `ok: 1`; every generated refresh was deferred. Validator-owned registry/reference/stat/generated side effects are recorded, but no validator-owned file was manually edited.

**Final receipt for every changed by-* file:**

| File | Exact command | Command ID / timestamp | Exit / ok | Command-specific diagnostics, side effects, generated state | Dated receipt SHA256 / bytes / lines |
| --- | --- | --- | --- | --- | --- |
| `by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md --apply --queue-timeout 240` | `000000023821` / `2026-08-15T02:16:24-04:00` | `0 / 1` | none; assigned UID000512, registered route; refresh deferred | `608D9632AD9C03EF7C1861ECA04195DC40ADF0A6485B28B2A6E442B1AEC6DDA6` / 3431 / 45 |
| `by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md --apply --queue-timeout 240` | `000000023823` / `2026-08-15T02:16:25-04:00` | `0 / 1` | none; assigned UID000514, registered route; refresh deferred | `242126EB16A02769E46D2F91DFAB337839D464E2DC767A86EF64E12E00B22564` / 3411 / 58 |
| `by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md --apply --queue-timeout 240` | `000000023822` / `2026-08-15T02:16:25-04:00` | `0 / 1` | none; assigned UID000513, registered route; refresh deferred | `89132D28D7B55E67CC97B39DFF1E3D11026DBA507BBF03E494F3F77FEAA5517A` / 3234 / 56 |
| `by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md --apply --queue-timeout 240` | `000000023824` / `2026-08-15T02:16:38-04:00` | `0 / 1` | none; assigned UID000515, registered route; refresh deferred | `764F96EBFA8C09ADB6132D717A93121339135AFA9F41517A78B3DD29AF745ABA` / 3277 / 67 |
| `by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md --apply --queue-timeout 240` | `000000023825` / `2026-08-15T02:16:38-04:00` | `0 / 1` | none; assigned UID000516, registered route; refresh deferred | `A38A12904DE15F874263DCED1E7B66E3F4B44138E4F3A311200540FB0B6FA46C` / 3521 / 72 |
| `by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md --apply --queue-timeout 240` | `000000023826` / `2026-08-15T02:16:39-04:00` | `0 / 1` | none; assigned UID000517, registered route; refresh deferred | `90B5C0B627BEBB2C052C128C214C805739F4C20F8E624D73A6F1BF3BDBBAE8D5` / 3620 / 83 |
| `by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md --apply --queue-timeout 240` | `000000023829` / `2026-08-15T02:16:59-04:00` | `0 / 1` | none; assigned UID00051A, registered route; refresh deferred | `09454DB9BB675337B9F7854904702BE3FA24AE03BC9AAEBE6B8BFE05C8133DBD` / 3202 / 67 |
| `by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md --apply --queue-timeout 240` | `000000023827` / `2026-08-15T02:16:59-04:00` | `0 / 1` | none; assigned UID000518, registered route; refresh deferred | `64B2B2C00934BF2869ED2DC1561E594D8966C9BA2900D67176F2F89BDFF4A09F` / 3709 / 69 |
| `by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md --apply --queue-timeout 240` | `000000023828` / `2026-08-15T02:16:59-04:00` | `0 / 1` | none; assigned UID000519, registered route; refresh deferred | `DAC73288617E54A3B155A297AF3A6204CF6CFA0746C99ED9FC804071985C3BB2` / 2780 / 47 |
| `by-file/BinaryCodec.md` | `python .\tools\validator.py --mode file --file by-file/BinaryCodec.md --apply --queue-timeout 240` | `000000023879` / `2026-08-15T02:36:48-04:00` | `0 / 1` | none; root/reference index clean at receipt time; refresh deferred | `18B2CED1E03AC1950F978097B322DE75B7BA6EB024734CC11A5765823BB312D6` / 33496 / 180 |
| `by-file/Encoder.md` | `python .\tools\validator.py --mode file --file by-file/Encoder.md --apply --queue-timeout 240` | `000000023877` / `2026-08-15T02:36:48-04:00` | `0 / 1` | none; UID0003IA reference mapping now clean; refresh deferred | `FAB0DBCD3B882C9D8AAFEBC19B7AC1F63AEF848FBD7EE741F6D9604B306FFBC2` / 47423 / 202 |
| `by-file/Decoder.md` | `python .\tools\validator.py --mode file --file by-file/Decoder.md --apply --queue-timeout 240` | `000000023882` / `2026-08-15T02:36:49-04:00` | `0 / 1` | none; path-NONE alias clean; refresh deferred | `01D2D40175AC4E7CEE1F5E1C0C796154129BBA8DA7F6609F23BEE78C5EB34C4E` / 40687 / 186 |
| `by-class/Encoder.md` | `python .\tools\validator.py --mode file --file by-class/Encoder.md --apply --queue-timeout 240` | `000000023880` / `2026-08-15T02:36:48-04:00` | `0 / 1` | none; UID0003IA reference mapping now clean; refresh deferred | `C3A2BD9C8256C1D89890BC71E06CE3E00E02B9EE4A9CB7087B458B3501700599` / 43728 / 256 |
| `by-class/Decoder.md` | `python .\tools\validator.py --mode file --file by-class/Decoder.md --apply --queue-timeout 240` | `000000023878` / `2026-08-15T02:36:48-04:00` | `0 / 1` | none; class route/H clean; refresh deferred | `AA75618B9BDBCC518536AD065E50AB9EEF7894AC16C30AE074F4BEBC00A49A53` / 41961 / 262 |
| `by-type/by-struct/BinaryCodecCursorLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/BinaryCodecCursorLayout.md --apply --queue-timeout 240` | `000000023883` / `2026-08-15T02:36:49-04:00` | `0 / 1` | none; false/non-emitting layout clean; refresh deferred | `4C5C950DEC8D6293434158F210B50A1C99AFB4C7ADA2891F7BBA6740DFD12E0C` / 30517 / 153 |
| `by-type/by-vtable/BinaryCodecVtables.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/BinaryCodecVtables.md --apply --queue-timeout 240` | `000000023881` / `2026-08-15T02:36:48-04:00` | `0 / 1` | none; UID0003IA reference mapping now clean; refresh deferred | `69104F86D5CE816217184E524F7502FF2B8B7D5D561463228A9EE16AE9849D74` / 19099 / 194 |
| `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md --apply --queue-timeout 240` | `000000023840` / `2026-08-15T02:28:05-04:00` | `0 / 1` | missing_ref_uid 0003IA x2, later resolved by 23868; route position 1; refresh deferred | `C9EA0CDC3893BD068EF33A00B84E3BF5E63ACB519DC164225FD3C0911B3B4D11` / 14581 / 115 |
| `by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md --apply --queue-timeout 240` | `000000023841` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; route position 2; refresh deferred | `9FFC3538307B66A49A50DC3320F3A83F2E080397B59E16802420DFA477C34021` / 14161 / 108 |
| `by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md --apply --queue-timeout 240` | `000000023844` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; route/body position 4; refresh deferred | `C8478B48CCAE53F57CF2E4565F79F5737982545CD4FD2BF1E6C8A317ED180354` / 14936 / 133 |
| `by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md --apply --queue-timeout 240` | `000000023842` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; route position 5; refresh deferred | `2043BC2E9B05540FA25F750DA074BEF4812A70DEAF4F0985AF9B2AB0A5EC577E` / 12710 / 123 |
| `by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md --apply --queue-timeout 240` | `000000023845` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; route position 7; refresh deferred | `D39A5EAC9EED7713D46C8FC8F29D2926A4F25858FB5B6322C5A515DEF17A9EA8` / 15157 / 139 |
| `by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md --apply --queue-timeout 240` | `000000023890` / `2026-08-15T02:40:28-04:00` | `0 / 1` | none; signed live signature clean; refresh deferred | `85C364FAA1BAD4F93C95FCA97C9A1591833395E6E98C876689DC2238E5942705` / 15688 / 143 |
| `by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md --apply --queue-timeout 240` | `000000023885` / `2026-08-15T02:40:27-04:00` | `0 / 1` | none; signed live signature clean; refresh deferred | `A05DC3E1659D0FFB6FBC348E17A62F108BAC68794F6992A4BE8D35F7D7E284FD` / 13927 / 130 |
| `by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md --apply --queue-timeout 240` | `000000023848` / `2026-08-15T02:28:05-04:00` | `0 / 1` | missing_ref_uid 0003IA x1, later resolved by 23868; route position 17; refresh deferred | `82382FC41E558B21618F09AF247C50AC3C95E7CDAB4A93704D8838D17DBAAD40` / 17836 / 212 |
| `by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md --apply --queue-timeout 240` | `000000023846` / `2026-08-15T02:28:05-04:00` | `0 / 1` | missing_ref_uid 0003IA x1, later resolved by 23868; route position 18; refresh deferred | `76BCB7CFD4DEA1D071EF417B002E4251D34A93B4F1EEA1A29D120FB745C9CE18` / 8376 / 88 |
| `by-memory/0x004a5640-0x004a5664.DecoderConstructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5640-0x004a5664.DecoderConstructor.md --apply --queue-timeout 240` | `000000023849` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 1; refresh deferred | `083A5128C3C07D9FD07D185E28403FD1E3A9D9090AA888EE1D969665889BF48B` / 10761 / 92 |
| `by-memory/0x004a5670-0x004a5677.DecoderDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5670-0x004a5677.DecoderDestructor.md --apply --queue-timeout 240` | `000000023855` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 2; refresh deferred | `4BD8DAE9056808E7E8B837A1B4873F7320B09C615867FD070995C13454722E47` / 10055 / 93 |
| `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md --apply --queue-timeout 240` | `000000023887` / `2026-08-15T02:40:27-04:00` | `0 / 1` | none; bool live signature clean; refresh deferred | `0D91EA1656F6BF80003AB40B455BEB46BA07368A887538DC21AE7C9A036065D0` / 5956 / 93 |
| `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md --apply --queue-timeout 240` | `000000023856` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 4; refresh deferred | `6FF15F78932357774E7A622FEFDFFC6F02EF86BC928E3CE901AD490095A8F3D3` / 6376 / 113 |
| `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md --apply --queue-timeout 240` | `000000023862` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 5; refresh deferred | `A8D05B8128EE1E87F65489D1B4B1DDDAD3076F35730DD8D9145E618E8707F20B` / 6913 / 130 |
| `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md --apply --queue-timeout 240` | `000000023851` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 6; refresh deferred | `9BDE3A7BD99556A4B05936F4F5EB3D9E54E88F488E732692196725BDD46B055F` / 6795 / 125 |
| `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md --apply --queue-timeout 240` | `000000023857` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 7; refresh deferred | `0A0FFB83C049BA796CDE58DBAD147BD3CCFFDDDBD05A05B657FCD3349B10A131` / 7230 / 138 |
| `by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md --apply --queue-timeout 240` | `000000023852` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 8; refresh deferred | `88E6D41C2D0487118875237D345595C76203276F9E2455E32D40B394F7B6A5A7` / 8163 / 118 |
| `by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md --apply --queue-timeout 240` | `000000023858` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 9; refresh deferred | `97FD3639B49236F22FFB21F49B1ECA559A4D8B5B9761B0F23D468FF208DA5B7C` / 8067 / 132 |
| `by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md --apply --queue-timeout 240` | `000000023859` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; CP_ACP body position 10; refresh deferred | `763CFA1E7113B64D84E515E317E787BA88FF3186044E70584EA42B0095280CA4` / 8326 / 128 |
| `by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md --apply --queue-timeout 240` | `000000023853` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; CP_ACP body position 11; refresh deferred | `4D489C25E5E01B878A4596A09A9DF0F9FC7BDC16017DF6564A225BE4DC73BA3D` / 8760 / 143 |
| `by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md --apply --queue-timeout 240` | `000000023863` / `2026-08-15T02:30:31-04:00` | `0 / 1` | none; CP_ACP body position 12; refresh deferred | `7CDAC6A1BCA34B414712CE741DAB44207AAB9F87C5E174CF2D4EF751FDC9E68F` / 8548 / 133 |
| `by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md --apply --queue-timeout 240` | `000000023886` / `2026-08-15T02:40:27-04:00` | `0 / 1` | none; signed live signature clean; refresh deferred | `C71432CA1C9F8D29216FEF31F0702DCD12FE2A0E89F8FE13F7CF8CCE12824766` / 6758 / 99 |
| `by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md --apply --queue-timeout 240` | `000000023854` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; route position 14; refresh deferred | `41959813237796FFBF58DBC5AEC0F5946104C3C62AEE8D573889E6CAB0095606` / 9322 / 149 |
| `by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md --apply --queue-timeout 240` | `000000023889` / `2026-08-15T02:40:28-04:00` | `0 / 1` | none; signed live signature clean; refresh deferred | `1B38F23E5BFA6B5899C07EE28B7EA734C4491DC406BFAE7F88878F599B66EB69` / 6414 / 94 |
| `by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md --apply --queue-timeout 240` | `000000023888` / `2026-08-15T02:40:28-04:00` | `0 / 1` | none; signed live signature clean; refresh deferred | `CB1C3C18A68E8960117EAD45AA8645DE2B5E027DD94C6F78470DCB0F75863E3A` / 6625 / 89 |
| `by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md --apply --queue-timeout 240` | `000000023864` / `2026-08-15T02:30:31-04:00` | `0 / 1` | none; route position 17; refresh deferred | `8D583BE45D1DE95F0D53EA849D25876D8C4A0E2B0C40C0431B364B5DD87E5781` / 15254 / 103 |
| `by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md --apply --queue-timeout 240` | `000000023866` / `2026-08-15T02:30:31-04:00` | `0 / 1` | none; route position 18; refresh deferred | `51D125F5EE6EDDBAF6B2E392D77EAC31C7B0F1F4F728FBC30913B013682B50D4` / 11185 / 101 |
| `by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000023872` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; true->false and emitter cleared; refresh deferred | `B1005FCAD16A8376BF78F96C4BEE2FCA6E0ACA64CF0E000FC71BD2778E37E321` / 13267 / 92 |
| `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000023867` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; true->false and emitter cleared; refresh deferred | `F3CD0253F7D04EC56E813AA47F2A9756C883296B12712A44D46B2933E3514D82` / 12141 / 100 |
| `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x006192c8-0x006192d4.EncoderVtableData.md --apply --queue-timeout 240` | `000000023868` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; added missing UID0003IA mapping, false/non-emitting registry; refresh deferred | `E35E7149AC9662EBD84512C06EE06FAA2CDBDEEE87ADB1A9ECFDDEDCEF19D529` / 5565 / 70 |
| `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x006192d4-0x006192e0.DecoderVtableData.md --apply --queue-timeout 240` | `000000023873` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; true->false and emitter cleared; refresh deferred | `13786C76DADF680237BF2A66F9D53C503B17A2B59FCE070E96DB774042C03B28` / 8407 / 81 |
| `by-memory/0x004a4e70-0x004a5621.EncoderCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4e70-0x004a5621.EncoderCore.md --apply --queue-timeout 240` | `000000023884` / `2026-08-15T02:36:49-04:00` | `0 / 1` | none; complete-index wording clean; refresh deferred | `2F5485424DD685AE3F9747264BD52876593C81954D9E57F868DFB858E98D32F5` / 27691 / 171 |
| `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md --apply --queue-timeout 240` | `000000023874` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; 94/94 index update; refresh deferred | `A6862C7021B06E0C0046C1DBB95DB7A8FF45C3742CFEE070C5F62FC0BC466321` / 22554 / 140 |
| `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md --apply --queue-timeout 240` | `000000023870` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; stats row removed/rescore recommended for false index; refresh deferred | `E66A9CE224C8E00619A6B65A5409258379D6B2041F114BF2E84F295395BD33DB` / 21539 / 163 |
| `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md` | `python .\tools\validator.py --mode file --file by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md --apply --queue-timeout 240` | `000000023876` / `2026-08-15T02:34:09-04:00` | `0 / 1` | missing_ref_uid 0003I9 x1, unrelated pre-existing mapping; boundary/score update; refresh deferred | `951D99417DD7114AA8B0DE8AFA5F3B283A6FD4649B24F40EB96C41B8735F5222` / 11878 / 102 |
| `by-item/EncodeTextEditState_0058E490.md` | `python .\tools\validator.py --mode file --file by-item/EncodeTextEditState_0058E490.md --apply --queue-timeout 240` | `000000023875` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; stats row updated for sole caller; refresh deferred | `3CA5923228A1703323D2A0FA3A9D8179F5A20A62652ED809A607D0CBC5C50DB3` / 18470 / 130 |
| `by-project-structure/proposed-source-tree.md` | `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240` | `000000023871` / `2026-08-15T02:34:09-04:00` | `0 / 1` | missing_ref_uid 0003LP/0003WL/0003WM/0003WN/0003WO; unrelated pre-existing mappings; codec refs updated; refresh deferred | `B39EFC787FFAB7EB0F7A549A929FEFADC3D319C763FF520DA33A8CD81FADA926` / 320827 / 2155 |

**Earlier callback receipts superseded by the final receipt for the same file but retained for complete command history:**

| File | Exact command | Command ID / timestamp | Exit / ok | Command-specific diagnostics, side effects, generated state | Dated receipt SHA256 / bytes / lines |
| --- | --- | --- | --- | --- | --- |
| `by-file/Encoder.md` | `python .\tools\validator.py --mode file --file by-file/Encoder.md --apply --queue-timeout 240` | `000000023832` / `2026-08-15T02:22:13-04:00` | `0 / 1` | missing_ref_uid 0003IA x4 and projected_cpp_stale Encoder.cpp; path set NONE; refresh deferred | `FAB0DBCD3B882C9D8AAFEBC19B7AC1F63AEF848FBD7EE741F6D9604B306FFBC2` / 47423 / 202 |
| `by-class/Encoder.md` | `python .\tools\validator.py --mode file --file by-class/Encoder.md --apply --queue-timeout 240` | `000000023833` / `2026-08-15T02:22:13-04:00` | `0 / 1` | missing_ref_uid 0003IA x3; owner/emitter/formal CPP/H registered; refresh deferred | `C3A2BD9C8256C1D89890BC71E06CE3E00E02B9EE4A9CB7087B458B3501700599` / 43728 / 256 |
| `by-type/by-vtable/BinaryCodecVtables.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/BinaryCodecVtables.md --apply --queue-timeout 240` | `000000023834` / `2026-08-15T02:22:13-04:00` | `0 / 1` | missing_ref_uid 0003IA x2; false/non-emitting route registered; refresh deferred | `69104F86D5CE816217184E524F7502FF2B8B7D5D561463228A9EE16AE9849D74` / 19099 / 194 |
| `by-file/BinaryCodec.md` | `python .\tools\validator.py --mode file --file by-file/BinaryCodec.md --apply --queue-timeout 240` | `000000023835` / `2026-08-15T02:22:13-04:00` | `0 / 1` | missing_ref_uid 0003IA x1; root/score update; refresh deferred | `18B2CED1E03AC1950F978097B322DE75B7BA6EB024734CC11A5765823BB312D6` / 33496 / 180 |
| `by-class/Decoder.md` | `python .\tools\validator.py --mode file --file by-class/Decoder.md --apply --queue-timeout 240` | `000000023836` / `2026-08-15T02:22:14-04:00` | `0 / 1` | none; owner/emitter/formal CPP/H registered; refresh deferred | `AA75618B9BDBCC518536AD065E50AB9EEF7894AC16C30AE074F4BEBC00A49A53` / 41961 / 262 |
| `by-file/Decoder.md` | `python .\tools\validator.py --mode file --file by-file/Decoder.md --apply --queue-timeout 240` | `000000023837` / `2026-08-15T02:22:14-04:00` | `0 / 1` | projected_cpp_stale Decoder.cpp; path set NONE; refresh deferred | `01D2D40175AC4E7CEE1F5E1C0C796154129BBA8DA7F6609F23BEE78C5EB34C4E` / 40687 / 186 |
| `by-type/by-struct/BinaryCodecCursorLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/BinaryCodecCursorLayout.md --apply --queue-timeout 240` | `000000023838` / `2026-08-15T02:22:14-04:00` | `0 / 1` | none; false/non-emitting layout update; refresh deferred | `4C5C950DEC8D6293434158F210B50A1C99AFB4C7ADA2891F7BBA6740DFD12E0C` / 30517 / 153 |
| `by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md --apply --queue-timeout 240` | `000000023847` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; exact formal body/position 13 registered; refresh deferred | `85C364FAA1BAD4F93C95FCA97C9A1591833395E6E98C876689DC2238E5942705` / 15688 / 143 |
| `by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md --apply --queue-timeout 240` | `000000023843` / `2026-08-15T02:28:05-04:00` | `0 / 1` | none; exact formal body/position 16 registered; refresh deferred | `A05DC3E1659D0FFB6FBC348E17A62F108BAC68794F6992A4BE8D35F7D7E284FD` / 13927 / 130 |
| `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md --apply --queue-timeout 240` | `000000023850` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; bool formal body/position 3 registered; refresh deferred | `0D91EA1656F6BF80003AB40B455BEB46BA07368A887538DC21AE7C9A036065D0` / 5956 / 93 |
| `by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md --apply --queue-timeout 240` | `000000023865` / `2026-08-15T02:30:31-04:00` | `0 / 1` | none; signed formal body/position 13 registered; refresh deferred | `C71432CA1C9F8D29216FEF31F0702DCD12FE2A0E89F8FE13F7CF8CCE12824766` / 6758 / 99 |
| `by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md --apply --queue-timeout 240` | `000000023860` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; signed formal body/position 15 registered; refresh deferred | `1B38F23E5BFA6B5899C07EE28B7EA734C4491DC406BFAE7F88878F599B66EB69` / 6414 / 94 |
| `by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md --apply --queue-timeout 240` | `000000023861` / `2026-08-15T02:30:30-04:00` | `0 / 1` | none; signed formal body/position 16 registered; refresh deferred | `CB1C3C18A68E8960117EAD45AA8645DE2B5E027DD94C6F78470DCB0F75863E3A` / 6625 / 89 |
| `by-memory/0x004a4e70-0x004a5621.EncoderCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x004a4e70-0x004a5621.EncoderCore.md --apply --queue-timeout 240` | `000000023869` / `2026-08-15T02:34:09-04:00` | `0 / 1` | none; nine UID links normalized/added; refresh deferred | `2F5485424DD685AE3F9747264BD52876593C81954D9E57F868DFB858E98D32F5` / 27691 / 171 |

Deferred generation physically settled after command `000000023890`: `auto-generated/NexusTK/util/BinaryCodec.cpp` SHA256 `88245DBBD8DD50E29B71F0D78FD70D918CC9E36B013A27285F188A94634927C9`, 22,508 bytes / 897 lines, physical last-write `2026-08-15T02:41:41-04:00`; `BinaryCodec.h` SHA256 `A213F61279BFE5034A61DBE40B1FFB45FE6CDC0CA4A43CB869C6F77D26AA19AC`, 2,680 bytes / 78 lines, same physical refresh window. Both embed validator command `000000023890`, timestamp `2026-08-15T02:40:28-04:00`, source `deferred-generated-refresh`.

Physical closure scan: exactly 18 `Encoder` definitions followed by exactly 18 `Decoder` definitions; exactly one complete `Encoder` and one complete `Decoder` declaration; required includes `BinaryCodec.h`, `MemoryMan.h`, zlib, `windows.h`, `memory.h`, and `wchar.h`; six `CP_ACP` arguments; seven `MemoryMan::MemmoveWrapper` calls; zero `MoveMemory`, zero old code-page-zero conversions, zero scalar-wrapper/RTTI/vtable source, zero empty markers, stubs, placeholders, TODOs, child tokens, or reconstruction markers. Old generated `Encoder.cpp` and `Decoder.cpp` are absent. Formal source order and every accepted behavior/leak/asymmetry are preserved.

## Changed Files

The callback changed 53 ordinary by-* files. Nine are newly created exact children; 44 are preserved in place with additive/corrective accepted updates. Validator-owned generated/coverage/registry/stat files changed only as validator side effects and were never manually edited.

| Changed ordinary file | SHA256 | Bytes | Lines |
| --- | --- | ---: | ---: |
| `by-memory/0x004a4eb0-0x004a4ebd.EncoderSetByteOrder.md` | `608D9632AD9C03EF7C1861ECA04195DC40ADF0A6485B28B2A6E442B1AEC6DDA6` | 3431 | 45 |
| `by-memory/0x004a4f60-0x004a4fe3.EncoderWriteTriByte.md` | `242126EB16A02769E46D2F91DFAB337839D464E2DC767A86EF64E12E00B22564` | 3411 | 58 |
| `by-memory/0x004a5070-0x004a50e3.EncoderWriteWideString8.md` | `89132D28D7B55E67CC97B39DFF1E3D11026DBA507BBF03E494F3F77FEAA5517A` | 3234 | 56 |
| `by-memory/0x004a50f0-0x004a5189.EncoderWriteWideString16.md` | `764F96EBFA8C09ADB6132D717A93121339135AFA9F41517A78B3DD29AF745ABA` | 3277 | 67 |
| `by-memory/0x004a5190-0x004a5293.EncoderWriteAnsiString8.md` | `A38A12904DE15F874263DCED1E7B66E3F4B44138E4F3A311200540FB0B6FA46C` | 3521 | 72 |
| `by-memory/0x004a52a0-0x004a53ca.EncoderWriteAnsiString16.md` | `90B5C0B627BEBB2C052C128C214C805739F4C20F8E624D73A6F1BF3BDBBAE8D5` | 3620 | 83 |
| `by-memory/0x004a53d0-0x004a5472.EncoderWriteCString.md` | `09454DB9BB675337B9F7854904702BE3FA24AE03BC9AAEBE6B8BFE05C8133DBD` | 3202 | 67 |
| `by-memory/0x004a54d0-0x004a558d.EncoderWriteCompressedBytes.md` | `64B2B2C00934BF2869ED2DC1561E594D8966C9BA2900D67176F2F89BDFF4A09F` | 3709 | 69 |
| `by-memory/0x004a5590-0x004a55b6.EncoderSkipBytes.md` | `DAC73288617E54A3B155A297AF3A6204CF6CFA0746C99ED9FC804071985C3BB2` | 2780 | 47 |
| `by-file/BinaryCodec.md` | `18B2CED1E03AC1950F978097B322DE75B7BA6EB024734CC11A5765823BB312D6` | 33496 | 180 |
| `by-file/Encoder.md` | `FAB0DBCD3B882C9D8AAFEBC19B7AC1F63AEF848FBD7EE741F6D9604B306FFBC2` | 47423 | 202 |
| `by-file/Decoder.md` | `01D2D40175AC4E7CEE1F5E1C0C796154129BBA8DA7F6609F23BEE78C5EB34C4E` | 40687 | 186 |
| `by-class/Encoder.md` | `C3A2BD9C8256C1D89890BC71E06CE3E00E02B9EE4A9CB7087B458B3501700599` | 43728 | 256 |
| `by-class/Decoder.md` | `AA75618B9BDBCC518536AD065E50AB9EEF7894AC16C30AE074F4BEBC00A49A53` | 41961 | 262 |
| `by-type/by-struct/BinaryCodecCursorLayout.md` | `4C5C950DEC8D6293434158F210B50A1C99AFB4C7ADA2891F7BBA6740DFD12E0C` | 30517 | 153 |
| `by-type/by-vtable/BinaryCodecVtables.md` | `69104F86D5CE816217184E524F7502FF2B8B7D5D561463228A9EE16AE9849D74` | 19099 | 194 |
| `by-memory/0x004a4e70-0x004a4e94.EncoderConstructor.md` | `C9EA0CDC3893BD068EF33A00B84E3BF5E63ACB519DC164225FD3C0911B3B4D11` | 14581 | 115 |
| `by-memory/0x004a4ea0-0x004a4ea7.EncoderDestructor.md` | `9FFC3538307B66A49A50DC3320F3A83F2E080397B59E16802420DFA477C34021` | 14161 | 108 |
| `by-memory/0x004a4ec0-0x004a4ef1.EncoderWriteByte.md` | `C8478B48CCAE53F57CF2E4565F79F5737982545CD4FD2BF1E6C8A317ED180354` | 14936 | 133 |
| `by-memory/0x004a4f00-0x004a4f59.EncoderWriteShort.md` | `2043BC2E9B05540FA25F750DA074BEF4812A70DEAF4F0985AF9B2AB0A5EC577E` | 12710 | 123 |
| `by-memory/0x004a4ff0-0x004a506b.EncoderWriteInt.md` | `D39A5EAC9EED7713D46C8FC8F29D2926A4F25858FB5B6322C5A515DEF17A9EA8` | 15157 | 139 |
| `by-memory/0x004a5480-0x004a54c6.EncoderWriteBytes.md` | `85C364FAA1BAD4F93C95FCA97C9A1591833395E6E98C876689DC2238E5942705` | 15688 | 143 |
| `by-memory/0x004a55c0-0x004a55de.EncoderInitialize.md` | `A05DC3E1659D0FFB6FBC348E17A62F108BAC68794F6992A4BE8D35F7D7E284FD` | 13927 | 130 |
| `by-memory/0x004a55e0-0x004a5621.EncoderFinalize.md` | `82382FC41E558B21618F09AF247C50AC3C95E7CDAB4A93704D8838D17DBAAD40` | 17836 | 212 |
| `by-memory/0x004a5630-0x004a5631.EncoderNoopVirtual.md` | `76BCB7CFD4DEA1D071EF417B002E4251D34A93B4F1EEA1A29D120FB745C9CE18` | 8376 | 88 |
| `by-memory/0x004a5640-0x004a5664.DecoderConstructor.md` | `083A5128C3C07D9FD07D185E28403FD1E3A9D9090AA888EE1D969665889BF48B` | 10761 | 92 |
| `by-memory/0x004a5670-0x004a5677.DecoderDestructor.md` | `4BD8DAE9056808E7E8B837A1B4873F7320B09C615867FD070995C13454722E47` | 10055 | 93 |
| `by-memory/0x004a5680-0x004a568d.DecoderSetByteOrder.md` | `0D91EA1656F6BF80003AB40B455BEB46BA07368A887538DC21AE7C9A036065D0` | 5956 | 93 |
| `by-memory/0x004a5690-0x004a56b8.DecoderReadByte.md` | `6FF15F78932357774E7A622FEFDFFC6F02EF86BC928E3CE901AD490095A8F3D3` | 6376 | 113 |
| `by-memory/0x004a56c0-0x004a570f.DecoderReadShort.md` | `A8D05B8128EE1E87F65489D1B4B1DDDAD3076F35730DD8D9145E618E8707F20B` | 6913 | 130 |
| `by-memory/0x004a5710-0x004a576f.DecoderReadTriByte.md` | `9BDE3A7BD99556A4B05936F4F5EB3D9E54E88F488E732692196725BDD46B055F` | 6795 | 125 |
| `by-memory/0x004a5770-0x004a57dc.DecoderReadInt.md` | `0A0FFB83C049BA796CDE58DBAD147BD3CCFFDDDBD05A05B657FCD3349B10A131` | 7230 | 138 |
| `by-memory/0x004a57e0-0x004a5861.DecoderReadWideString8.md` | `88E6D41C2D0487118875237D345595C76203276F9E2455E32D40B394F7B6A5A7` | 8163 | 118 |
| `by-memory/0x004a5870-0x004a5925.DecoderReadWideString16.md` | `97FD3639B49236F22FFB21F49B1ECA559A4D8B5B9761B0F23D468FF208DA5B7C` | 8067 | 132 |
| `by-memory/0x004a5930-0x004a5a3a.DecoderReadAnsiString8.md` | `763CFA1E7113B64D84E515E317E787BA88FF3186044E70584EA42B0095280CA4` | 8326 | 128 |
| `by-memory/0x004a5a40-0x004a5ba7.DecoderReadAnsiString16.md` | `4D489C25E5E01B878A4596A09A9DF0F9FC7BDC16017DF6564A225BE4DC73BA3D` | 8760 | 143 |
| `by-memory/0x004a5bb0-0x004a5c7e.DecoderReadCString.md` | `7CDAC6A1BCA34B414712CE741DAB44207AAB9F87C5E174CF2D4EF751FDC9E68F` | 8548 | 133 |
| `by-memory/0x004a5c80-0x004a5cc4.DecoderReadBytes.md` | `C71432CA1C9F8D29216FEF31F0702DCD12FE2A0E89F8FE13F7CF8CCE12824766` | 6758 | 99 |
| `by-memory/0x004a5cd0-0x004a5d79.DecoderReadCompressedBytes.md` | `41959813237796FFBF58DBC5AEC0F5946104C3C62AEE8D573889E6CAB0095606` | 9322 | 149 |
| `by-memory/0x004a5d80-0x004a5da6.DecoderSkipBytes.md` | `1B38F23E5BFA6B5899C07EE28B7EA734C4491DC406BFAE7F88878F599B66EB69` | 6414 | 94 |
| `by-memory/0x004a5db0-0x004a5dce.DecoderInitialize.md` | `CB1C3C18A68E8960117EAD45AA8645DE2B5E027DD94C6F78470DCB0F75863E3A` | 6625 | 89 |
| `by-memory/0x004a5dd0-0x004a5ded.DecoderFinalize.md` | `8D583BE45D1DE95F0D53EA849D25876D8C4A0E2B0C40C0431B364B5DD87E5781` | 15254 | 103 |
| `by-memory/0x004a5df0-0x004a5df1.DecoderNoopVirtual.md` | `51D125F5EE6EDDBAF6B2E392D77EAC31C7B0F1F4F728FBC30913B013682B50D4` | 11185 | 101 |
| `by-memory/0x004a5e00-0x004a5e24.DecoderScalarDeletingDestructor.md` | `B1005FCAD16A8376BF78F96C4BEE2FCA6E0ACA64CF0E000FC71BD2778E37E321` | 13267 | 92 |
| `by-memory/0x004a5e30-0x004a5e54.EncoderScalarDeletingDestructor.md` | `F3CD0253F7D04EC56E813AA47F2A9756C883296B12712A44D46B2933E3514D82` | 12141 | 100 |
| `by-memory/0x006192c8-0x006192d4.EncoderVtableData.md` | `E35E7149AC9662EBD84512C06EE06FAA2CDBDEEE87ADB1A9ECFDDEDCEF19D529` | 5565 | 70 |
| `by-memory/0x006192d4-0x006192e0.DecoderVtableData.md` | `13786C76DADF680237BF2A66F9D53C503B17A2B59FCE070E96DB774042C03B28` | 8407 | 81 |
| `by-memory/0x004a4e70-0x004a5621.EncoderCore.md` | `2F5485424DD685AE3F9747264BD52876593C81954D9E57F868DFB858E98D32F5` | 27691 | 171 |
| `by-memory/0x004a5680-0x004a5dce.DecoderRawReaderFamily.md` | `A6862C7021B06E0C0046C1DBB95DB7A8FF45C3742CFEE070C5F62FC0BC466321` | 22554 | 140 |
| `by-memory/0x004a5630-0x004a5e54.DecoderAndCodecVtableGlue.md` | `E66A9CE224C8E00619A6B65A5409258379D6B2041F114BF2E84F295395BD33DB` | 21539 | 163 |
| `by-memory/0x006192c6-0x00619340.BinaryCodecDatReadOnlyData.md` | `951D99417DD7114AA8B0DE8AFA5F3B283A6FD4649B24F40EB96C41B8735F5222` | 11878 | 102 |
| `by-item/EncodeTextEditState_0058E490.md` | `3CA5923228A1703323D2A0FA3A9D8179F5A20A62652ED809A607D0CBC5C50DB3` | 18470 | 130 |
| `by-project-structure/proposed-source-tree.md` | `B39EFC787FFAB7EB0F7A549A929FEFADC3D319C763FF520DA33A8CD81FADA926` | 320827 | 2155 |

During the dated callback, no ordinary file was renamed or moved and B002 did not directly edit manual coverage, generated source, tracker, audit/catalog, IDA, goal/notes, or lifecycle files. Short leases covered only immediate ordinary edit/validation batches; each was released, except the first nine Encoder leases expired during their queued validator batch and explicit unlease returned `No active lease`. Current lease state is external and authoritative only from the current lease registry.

Current Gate, manual-coverage, IDA, by-* implementation, report execution/archive, and lifecycle status is external to this report. It is authoritative only from the current supervisor audit, current physical IDB/by-* readback, and validator-owned status/history metadata. Ordinary report prose and report-local checklist states make no assertion about those mutable external states.

## Implementation Tracking Checklist

Section 33 is the exact 72-row twin of Section 11. Every non-`Done` field is verbatim. Report-local allocation is 69 checked/applied and C67-C69 unchecked/proposed; those fixed row states do not assert current external coverage, IDA, Gate, execution/archive, or lifecycle status.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C01 | 0000HQ | BinaryCodec is one retained historical compilation unit containing Encoder then Decoder, not three independent source roots. | High | Contiguous mirrored island, paired RTTI/wrappers, absent path evidence | UID0000HQ placement/status | incorporate | applied |
| [x] | C02 | 00004F | Encoder is a standalone 0x14 class directly owned/emitted by UID0000HQ. | High | RTTI, ctor fields, vtable, stack object size | UID00004F metadata/H | incorporate | applied |
| [x] | C03 | 00003M | Decoder is a standalone 0x14 class directly owned/emitted by UID0000HQ. | High | RTTI, ctor fields, vtable, scalar delete size | UID00003M metadata/H | incorporate | applied |
| [x] | C04 | 0000J1 | Encoder by-file becomes a non-root historical/support alias with path NONE; preserve its evidence. | Medium-high | One-file placement analysis | UID0000J1 metadata/status | incorporate | applied |
| [x] | C05 | 0000IQ | Decoder by-file becomes a non-root historical/support alias with path NONE; preserve its evidence. | Medium-high | One-file placement analysis | UID0000IQ metadata/status | incorporate | applied |
| [x] | C06 | 0001TS | Shared layout page becomes non-reconstructable/non-emitting ABI evidence; class H fragments own declarations. | High | Duplicate layout consequence and empty marker | UID0001TS metadata | incorporate | applied |
| [x] | C07 | 0001X1 | Shared vtable page becomes non-reconstructable/non-emitting compiler evidence. | High | MSVC vtable/RTTI consequence and empty marker | UID0001X1 metadata | incorporate | applied |
| [x] | C08 | 0000HQ | Required final files are BinaryCodec.cpp and BinaryCodec.h; no headerless result is valid. | High | Member definitions need two complete class declarations | UID0000HQ/generated topology | incorporate | applied |
| [x] | C09 | 0000HQ | Cursor/capacity fields and ordinary byte counts are signed int; scalar values and zlib lengths retain unsigned types. | High | Signed bounds branches and zero-extension/logical shifts | class/child types/formal source | incorporate | applied |
| [x] | C10 | 0000HQ | Endian state is a one-byte bool where true selects big-endian and false little-endian. | High | Canonical ctor writes, direct setter, all branch uses | class fields/SetByteOrder docs | incorporate | applied |
| [x] | C11 | 0000HQ | The only live authored route is TextEditPane_EncodeState to the modeled Encoder subset. | High | Exhaustive live xrefs | target/classes/caller inventory | incorporate | applied |
| [x] | C12 | 0000HQ | Nine Encoder raw methods and the entire Decoder authored API are retained dead source, not removable compiler debris. | High | Coherent bodies plus exhaustive zero routes | target/classes/children | incorporate | applied |
| [x] | C13 | 00013C | Encoder constructor initializes null buffer, zero capacity/cursor, big-endian true, writable true. | High | 0x4A4E70 body/hash | constructor child/formal CPP | already-present | applied |
| [x] | C14 | 00013E | Encoder ordinary destructor is empty source; virtual declaration generates ABI teardown. | High | 0x4A4EA0 body/hash | destructor child/formal CPP | already-present | applied |
| [x] | C15 | 000512 | Create exact Encoder SetByteOrder child 0x4A4EB0-0x4A4EBD and direct-store bool behavior. | High | Raw body/hash, mirrored Decoder method | new by-memory child | incorporate | applied |
| [x] | C16 | 00013F | Encoder WriteByte reserves one trailing terminator byte and marks failure on signed overflow. | High | 0x4A4EC0 body/hash | WriteByte child/formal CPP | incorporate | applied |
| [x] | C17 | 00013G | Encoder WriteShort writes selected-endian unsigned 16-bit value and reserves terminator capacity. | High | 0x4A4F00 body/hash | WriteShort child/formal CPP | incorporate | applied |
| [x] | C18 | 000514 | Create exact Encoder WriteTriByte child 0x4A4F60-0x4A4FE3 with selected 24-bit byte order. | High | Raw body/hash, Decoder mirror | new by-memory child | incorporate | applied |
| [x] | C19 | 00013H | Encoder WriteInt writes selected-endian unsigned 32-bit value and reserves terminator capacity. | High | 0x4A4FF0 body/hash | WriteInt child/formal CPP | incorporate | applied |
| [x] | C20 | 000513 | Create exact WriteWideString8 child with signed -1 length, one-byte count, native wchar payload, and reserve byte. | High | 0x4A5070 body/hash | new by-memory child | incorporate | applied |
| [x] | C21 | 000515 | Create exact WriteWideString16 child with selected-endian 16-bit count and native wchar payload. | High | 0x4A50F0 body/hash | new by-memory child | incorporate | applied |
| [x] | C22 | 000516 | Create exact WriteAnsiString8 child with CP_ACP conversion, 255 clamp, and one-byte count. | High | 0x4A5190 body/hash/imports | new by-memory child | incorporate | applied |
| [x] | C23 | 000517 | Create exact WriteAnsiString16 child with 64K scratch, 65535 clamp, and selected-endian count. | High | 0x4A52A0 body/hash/imports | new by-memory child | incorporate | applied |
| [x] | C24 | 00051A | Create exact WriteCString child and preserve its observed temporary-allocation leak. | High | 0x4A53D0 body/hash/no delete route | new by-memory child | incorporate | applied |
| [x] | C25 | 00013I | Encoder WriteBytes uses signed count/cursor checks and MemoryMan::MemmoveWrapper. | High | 0x4A5480 body plus accepted MemoryMan API | WriteBytes child/formal CPP | incorporate | applied |
| [x] | C26 | 000518 | Create exact WriteCompressedBytes child; preserve ignored compress status and overflow-path leak. | High | 0x4A54D0 body/hash/callees | new by-memory child | incorporate | applied |
| [x] | C27 | 000519 | Create exact Encoder SkipBytes child with reserve-byte bounds and no write. | High | 0x4A5590 body/hash | new by-memory child | incorporate | applied |
| [x] | C28 | 00013J | Encoder Initialize attaches caller storage with signed capacity and resets writable state. | High | 0x4A55C0 body/hash | Initialize child/formal CPP | incorporate | applied |
| [x] | C29 | 00013K | Encoder Finalize reports prior state/count, writes terminator, detaches, and resets. | High | 0x4A55E0 body/hash | Finalize child/formal CPP | already-present | applied |
| [x] | C30 | 00013L | Encoder NoopVirtual is empty virtual source and only vtable-referenced. | High | 0x4A5630 one-byte body/xref | noop child/formal CPP | incorporate | applied |
| [x] | C31 | 00013N | Decoder constructor initializes null input, zero size/cursor, big-endian true, valid true. | High | 0x4A5640 body/hash | constructor child/formal CPP | incorporate | applied |
| [x] | C32 | 00013O | Decoder ordinary destructor is empty source. | High | 0x4A5670 body/hash | destructor child/formal CPP | incorporate | applied |
| [x] | C33 | 0003K8 | Decoder SetByteOrder directly stores a bool endian selector. | High | 0x4A5680 body/hash | exact child/formal CPP | incorporate | applied |
| [x] | C34 | 0003K9 | ReadByte checks signed bounds, advances one, or invalidates and returns zero. | High | 0x4A5690 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C35 | 0003KA | ReadShort performs selected-endian unsigned 16-bit read with signed bounds. | High | 0x4A56C0 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C36 | 0003KB | ReadTriByte performs selected-endian unsigned 24-bit read. | High | 0x4A5710 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C37 | 0003KC | ReadInt performs selected-endian unsigned 32-bit read. | High | 0x4A5770 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C38 | 0003L6 | ReadWideString8 reads one-byte count and native wchar payload with exact output reset. | High | 0x4A57E0 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C39 | 0003L7 | ReadWideString16 reads selected-endian count and native wchar payload. | High | 0x4A5870 body/hash | exact child/formal CPP | already-present | applied |
| [x] | C40 | 0003L8 | ReadAnsiString8 copies counted bytes, converts CP_ACP, and enforces output capacity after conversion. | High | 0x4A5930 body/hash/imports | exact child/formal CPP | already-present | applied |
| [x] | C41 | 0003L9 | ReadAnsiString16 preserves 64K scratch, selected-endian count, ACP conversion, and checks. | High | 0x4A5A40 body/hash/imports | exact child/formal CPP | already-present | applied |
| [x] | C42 | 0003LA | ReadCString scans through NUL, allocates/copies/converts/frees, advances through terminator. | High | 0x4A5BB0 body/hash/callees | exact child/formal CPP | already-present | applied |
| [x] | C43 | 0003LB | ReadBytes uses signed count and advances only after a successful copy. | High | 0x4A5C80 body/hash | exact child/formal CPP | incorporate | applied |
| [x] | C44 | 0003LC | ReadCompressedBytes preserves selected count, ignored uncompress status, advance, produced-size check. | High | 0x4A5CD0 body/hash/callee | exact child/formal CPP | already-present | applied |
| [x] | C45 | 0003LD | Decoder SkipBytes uses signed count and requires one remaining byte. | High | 0x4A5D80 body/hash | exact child/formal CPP | incorporate | applied |
| [x] | C46 | 0003LE | Decoder Initialize attaches const input with signed size and resets valid state. | High | 0x4A5DB0 body/hash | exact child/formal CPP | incorporate | applied |
| [x] | C47 | 00013S | Decoder Finalize returns prior validity and detaches/resets without consumption validation. | High | 0x4A5DD0 body/hash | exact child/formal CPP | incorporate | applied |
| [x] | C48 | 00013T | Decoder NoopVirtual is empty virtual source and only vtable-referenced. | High | 0x4A5DF0 one-byte body/xref | exact child/formal CPP | incorporate | applied |
| [x] | C49 | 00013U | Decoder scalar deleting destructor is compiler-covered, non-reconstructable, non-emitting. | High | 0x4A5E00 flags wrapper/vtable xref | scalar child metadata/no-code | incorporate | applied |
| [x] | C50 | 00013V | Encoder scalar deleting destructor is compiler-covered, non-reconstructable, non-emitting. | High | 0x4A5E30 flags wrapper/vtable xref | scalar child metadata/no-code | incorporate | applied |
| [x] | C51 | 0003IA | Encoder RTTI/vtable data is compiler-covered, non-reconstructable, non-emitting. | High | Exact 12 bytes and ABI slots | vtable child metadata/no-code | incorporate | applied |
| [x] | C52 | 0003IB | Decoder RTTI/vtable data is compiler-covered, non-reconstructable, non-emitting. | High | Exact 12 bytes and ABI slots | vtable child metadata/no-code | incorporate | applied |
| [x] | C53 | 000257 | The 0x6192E0 successor table belongs to ParseEntries and remains excluded. | High | Boundary/xref at 0x4A5E9E | DAT aggregate/target negatives | already-present | applied |
| [x] | C54 | 0000HQ | All 38 internal/terminal gaps are CC alignment and own no authored source. | High | Exact bytes/xrefs/boundaries | target range analysis | incorporate | applied |
| [x] | C55 | 0000UM | Preserve the sole TextEdit caller's one-buffer 0x7FFE-capacity serialization evidence without claiming network packet ownership. | High | 0x58E490 decompile/xrefs | caller support/target | incorporate | applied |
| [x] | C56 | SUPPORT | Preserve broad aggregates as false/non-emitting indexes and update them with complete exact-child inventory. | High | Overlap and child coverage | UIDs 00013D/00013Q/00013M/000257 | incorporate | applied |
| [x] | C57 | 00004F | Encoder formal CPP supplies includes plus CHILDREN; formal H supplies complete class declaration. | High | Final source topology | class formal channels | incorporate | applied |
| [x] | C58 | 00003M | Decoder formal CPP supplies CHILDREN only; formal H supplies complete class declaration. | High | Final source topology | class formal channels | incorporate | applied |
| [x] | C59 | SUPPORT | Existing authored children route to their direct class in exact address/source order; nine new Encoder children fill positions. | High | Complete 36-method inventory | all exact child metadata | incorporate | applied |
| [x] | C60 | SUPPORT | Remove stale MoveMemory, unsigned cursor/count, provisional split, and unresolved-liveness prose without losing history. | High | Dated pre-callback docs versus dated live evidence | affected support docs | reject-stale | applied |
| [x] | C61 | SOURCE-TREE | Replace provisional BinaryCodec/Encoder/Decoder three-root tree with one BinaryCodec.cpp/.h family. | Medium-high | Ranked placement result | proposed-source-tree.md | incorporate | applied |
| [x] | C62 | GENERATED | Fresh BinaryCodec.cpp must contain 36 authored definitions exactly once and no empty markers/stubs/TODOs. | High | Resolved emitter graph and formal CPP | supervisor generated readback | incorporate | applied |
| [x] | C63 | GENERATED | Fresh BinaryCodec.h must contain two complete 0x14 class declarations exactly once. | High | Formal H and compile requirement | supervisor generated readback | incorporate | applied |
| [x] | C64 | GENERATED | No manual scalar-wrapper/vtable/RTTI definitions may appear in generated source. | High | Compiler-covered classification | supervisor generated readback | incorporate | applied |
| [x] | C65 | 0000HQ | Raise target to 94/93 after complete ordinary implementation and physical generated readback. | Medium-high | Full closure with lexical/path/liveness caps | target metadata | incorporate | applied |
| [x] | C66 | SUPPORT | Apply item-specific support scores from Section 26 without crossing the 95 completion barrier. | Medium-high | Resolved source and remaining caps | affected support metadata | incorporate | applied |
| [ ] | C67 | COVERAGE | Section 28 records exact manual-coverage replacement/insert proposals from the dated callback freeze; current coverage disposition is external to this report. | High | Dated callback-freeze stale/absent rows; current authority requires current supervisor audit and physical by-*/coverage readback | manual coverage reports | incorporate | proposed |
| [ ] | C68 | IDA | Section 21 records the database-bound structured A01-A40 handoff, including 23 explicit-bound `define_func` chains: 19 raw rows omit `set_type` and preserve exact observed D frames with type absent because no literal post-type frame is read-only provable; A24-A27 retain exact no-argument type requests with unchanged frames; current IDB and Gate 2B disposition is external to this report. | High | Dated live state, exact body/frame evidence, deterministic row-local contracts; current authority requires current supervisor audit and IDB readback | IDA handoff | incorporate | proposed |
| [ ] | C69 | IDA | Section 21 records byte-for-byte and exact-xref protections for two vtable records and the unrelated successor table; current IDB disposition is external to this report. | High | Dated item/byte/xref evidence; current authority requires current supervisor audit and IDB readback | IDA protections | incorporate | proposed |
| [x] | C70 | 0000HQ | External dependencies remain MemoryMan, Win32 ACP conversion, zlib, CRT allocation/memmove, and compiler support; no duplication. | High | Complete callee/import inventory | target/classes/formal CPP | incorporate | applied |
| [x] | C71 | 0000HQ | No codec-owned global/static/string/resource/enum/table exists beyond compiler RTTI/vtables. | High | Listing/string/data/import negative searches | target inventory/negative evidence | incorporate | applied |
| [x] | C72 | 0000HQ | By-file reconstructable blank is schema-correct; source reconstruction is expressed through class/method metadata. | High | by-structure/by-file guidance | target metadata/status | already-present | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000024285","destination_path":"executed-b-agent-research/B002/0000HQ-BinaryCodec-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000HQ-BinaryCodec-file-source-quality.md","timestamp":"2026-08-15T09:07:55-04:00","uid":"0000HQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
