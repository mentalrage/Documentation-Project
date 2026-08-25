** TARGET-REPORT-UID:00027J **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID00027J g_emptySimpleUString Storage Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation and applied ordinary state: retain [UID:00027J] as the exact non-duplicating storage child of semantic global [UID:0000PW], keep the owner/emitter chain `00027J -> 0000PW -> 0000OB`, and use the now-applied externally linked default-constructed `SimpleUString g_emptySimpleUString;` in `NexusTK/util/StringUtil.cpp` with an `extern` declaration in `StringUtil.h`.
- Final disposition: the binary object is one 24-byte MSVC/Dinkumware-compatible UTF-16 SSO-7 string object, not three unrelated dwords. Its exact ABI is an inline/heap union at `+0x00`, length at `+0x10`, and capacity at `+0x14`; the loader image holds `{zero inline storage, length 0, capacity 7}`, CRT startup lowers default construction through the shared empty wide literal and a count-zero assignment, and compiler-generated cleanup releases heap storage if needed and restores that empty state.
- Applied action: B004 incorporated the exact layout, static-lifetime, linkage, source-placement, consumer, negative-evidence, historical-assumption, formal CPP/H, and score changes into all seven accepted ordinary destinations. Supervisor Gate 2B applied, verified, saved, and cataloged the bounded IDA UDT/data/wrapper handoff as entry `0360`. Fresh supervisor gates, the seven manual coverage replacements, generated/tracker closure, and supervisor-only lifecycle execution remain outstanding.
- Confidence: very strong for range, bytes, ABI layout, static-lifetime behavior, shared fallback role, and non-duplicating emitter route; strong for `StringUtil.cpp` placement, external linkage, `SimpleUString` project-facing type, and bare default-construction source shape; medium-high only for exact original lexical spellings because the executable has no original data or wrapper symbols.

## Supporting Research

- Live read-only IDA MCP session `1da2b2ae` was healthy and answered target data, byte, xref, pointer-pattern, function, decompilation, disassembly, frame, type-catalog, name-collision, and comment-channel queries. Required evidence was obtained before report finalization; the later local PowerShell client process encountered host paging pressure while attempting a redundant xref re-fetch, not an MCP evidence failure.
- Input executable checkpoint: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`, 2,679,296 bytes.
- Catalog entry `0360` records the historical UID00027J Gate 2B save for active database `1da2b2ae`: SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, 143,190,601 bytes, last write `2026-07-29T13:03:43.9987735-04:00`; `idb_save` returned `ok:true`. Byte-identical prestate backup `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B004-UID00027J-20260729-130145.i64` has SHA256 `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`, 143,190,452 bytes. The later `905D1AB1...604C1`, `296ED21C...63CF8B`, `0E0AF938...AB481`, `3C8F3178...5B69`, `E9600F...1611`, `24B033...EC31`, and `2823AB...4C3` checkpoints are historical. The current authoritative shared IDB is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, session `1da2b2ae`, SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`.
- Current ordinary-document post-callback checkpoints: target SHA256 `6DD260F78519060EFDC3B8E4E19B74355F9F72EBD3D2D0E4890BC70C5575CB47`; global SHA256 `9F40B27492B2B5144FE0F342DC71877C112A925B72DD941EED4BDC98CE1B61E6`; file SHA256 `308E8098D7231ACF978ED09E4EF3CBC4BD1ACE49079B815A3BC1BF0D68BD8653`; class SHA256 `1481FCB762336F47CC21C14944A4EE025E522970E75A34F9860F993796035B13`; layout SHA256 `68D7F75A7530124D72B607FF48D3D28E7E1A95C751B87BA794258053821B9995`; initializer-container SHA256 `D5E67BC86D8B3F72E79A6902F9CD3DA0346884B5E404C27A4AAF17205BE79D2A`; cleanup-container SHA256 `751D1D1F447AF96740D44C224E2D97C0335FADBB97A808E1472204DBBE5DEB00`. Earlier post-callback hashes and frozen pre-callback hashes remain historical implementation checkpoints.
- Current read-only tracker checkpoint: `auto-generated/-ag-research-tracker.md`, validator command `000000019483`, refreshed `2026-07-29T14:30:34-04:00`, source `foreground-generated-refresh`, SHA256 `A2C97D53EA038671299109D5455954FD909A2DFF0E6BCB9673E8CABD2518DC65`, 1,676,576 bytes, last write `2026-07-29T14:30:53.2980054-04:00`; its UID00027J row now reads `92/94`, reconstructable, with zero direct/additional/total report coverage because report execution remains supervisor-owned. Command19259 (`2026-07-29T12:31:09-04:00`, SHA256 `0100F9163CD9178641161A1A2A43B16185D3C663A4BE02A05DD2D410635813A0`, 1,676,445 bytes, last write `2026-07-29T12:31:30.0100870-04:00`) is the dated pre-callback tracker checkpoint where the row remained `87/89`; command19221, command19201, and commands19068/19152/19153 are earlier historical checkpoints. The tracker remains a moving validator-owned artifact and must be reread before supervisor lifecycle action.
- Current read-only generated checkpoint is validator command `000000019483`, refreshed `2026-07-29T14:30:34-04:00`, source `foreground-generated-refresh`: `auto-generated/NexusTK/util/StringUtil.cpp` SHA256 `BF10363E64564DBA46695CF548CD634C0634963DE056A872701E1AD1D9F18EA8`, 10,585 bytes, 339 lines, last write `2026-07-29T14:30:48.7376881-04:00`, contains the exact UID0000PW `SimpleUString g_emptySimpleUString;` definition; `auto-generated/NexusTK/util/StringUtil.h` SHA256 `B4F70F39FA9BB0D4633ADC019429400A3D6206161B0DB316F2040C3C1201DBD3`, 962 bytes, 34 lines, last write `2026-07-29T14:30:48.5273726-04:00`, contains the complete UID0000D9 class declaration and exact UID0000PW `extern SimpleUString g_emptySimpleUString;`. Command19259 remains the dated pre-callback generated checkpoint (`StringUtil.cpp` SHA256 `EA875399F844128FF17CDE676166DD7806462FCCDCE26B561D4F18D1934CB16D`, 10,989 bytes, and absent H); command19221, command19201, and commands19068/19152 are earlier history. B004 did not edit generated files.
- Historical B007 StringUtil-family research correctly established shared fallback semantics, owner routing, and no-duplicate storage emission, but left linkage and `StringUtil.cpp` versus `SimpleUString.cpp` open. This report preserves the valid evidence and resolves those source-quality questions using the complete xref spread, static-lifetime lowering, and present source-tree organization.
- Historical pre-action currentness preflight on live session `1da2b2ae` reverified all twelve IDA-27J prestates and protected `sub_421310`, `sub_421590`, and `initialText` dependencies against prestate SHA `08D31FD...54F5A`. Supervisor catalog entry `0360` then applied and read back every accepted action: the two exact SSO-7 compatibility types exist; the object is consolidated, typed, named, and repeatable-commented; both wrappers have final names/prototypes/comments; the cleanup prototype remained a no-change `void __cdecl()`; xrefs remain `33/0/0/0/12/12`; and all protected bytes, fences, frames, helpers, literal, and unrelated entities remain unchanged. IDA's automatic intermediate item name `stru_66DAEC` during consolidation is preserved as historical tooling state, not final source identity. A bounded read-only recheck against current authoritative IDB `412DA7E8...519CD` confirmed the same UDT members, `g_emptySimpleUString` item/type/value/AP, wrapper names/prototypes/return-only frames/FP comments, helper names/prototypes/caller sets, xref vector, and exact byte hashes `15EBE3D8...D47D60`, `068F4C43...CE35C`, `9C127BED...64CAE`, `2917FEBD...DAA5F`, `2E2B7DE0...DBEB2`, `96A296D2...9CFC7`, and successor `11BDC778...5BD6`; no UID00027J drift was found. The prior `905D1AB1...604C1` and `296ED21C...63CF8B` no-drift checkpoints are historical.
- Final source-shape comparison checked sibling [UID:0000Q2] `by-global/g_metaAliasTableName.md` (SHA256 `40EC6D526AD4B04A45E6096AB95FED6B2E25101E271D378D4C925A3420EF4635`) and [UID:0001OL] `by-memory/0x0066de18-0x0066de30.g_metaAliasTableName.md` (SHA256 `7ADD467972A1148C765896758206E8C05ACD654EA900C47FD82346C7D4150847`). Live IDA shows sibling initializer `sub_419FF0` performs the same `sub_421590(..., shared-empty-literal, 0)` plus `atexit` pattern, while the accepted human source formal is bare `SimpleUString g_metaAliasTableName;`. This repeated family lowering rejects inventing a target-only `const wchar_t *` constructor overload and supports bare default construction for UID0000PW.

## Target

- Target UID: `00027J`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:00027J] `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`, the exact concrete `.data` storage range for the semantic global. All other UIDs in this report are support destinations only and receive no report-coverage claim.
- Target path: `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`.
- Source queue/report row at current command19483: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; row `92/94`, reconstructable, zero report counts. Command19259 is the dated pre-callback `87/89` queue checkpoint, and command19221 is earlier report-time history.
- Assignment classification: accepted source-quality/empty-emitter implementation callback. B004 completed the ordinary-document work; the supervisor completed Gate 2B IDA work. No B004 IDA mutation or lifecycle execution occurred.
- Current scores and parent state: `92/94`, `CANONICAL_OWNER:0000PW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PW`; semantic global [UID:0000PW] is `92/93` and routes to file [UID:0000OB]. Current command19483 reflects the target's `92/94` row and generated CPP/H topology; command19259's `87/89` row is historical.

## Current Target State

- Applied metadata: target `92/94`, owner/emitter `0000PW`, reconstructable, blank optional position. The target formal CPP is the accepted no-duplicate ABI/storage comment; formal H is blank.
- Applied owner/emitter/reconstructable state remains structurally unchanged. The concrete address page emits no second definition; [UID:0000PW] emits through [UID:0000OB].
- Applied C++/emitter state: [UID:0000PW] emits bare `SimpleUString g_emptySimpleUString;` in CPP and exact `extern SimpleUString g_emptySimpleUString;` in H. [UID:0000D9] formal CPP is blank and formal H contains the complete accepted class declaration. UID0000PW/0000D9/0000OB/0001W5 scores are `92/93`, `90/92`, `90/91`, and `90/93`; aggregate scores remain unchanged.
- Applied IDA state: exact compatibility union/struct, consolidated `g_emptySimpleUString` item and AP comment, `g_emptySimpleUString_StaticInitializer` with `int __cdecl()` and exact FP, and `g_emptySimpleUString_StaticCleanup` with preserved `void __cdecl()` and exact FP were durably saved under catalog `0360`. Current authoritative IDB `412DA7E8...519CD` preserves that complete target state without drift; `905D1AB1...604C1`, `296ED21C...63CF8B`, catalog0360's `03F102...DBE5DA`, `0E0AF938...AB481`, `3C8F3178...5B69`, and all earlier identities are historical. Raw dword/sub labels remain only historical prestates.
- Former blockers around fields, ABI, loader/runtime initialization, cleanup, linkage, source split, wrappers, and formal channels are resolved. Remaining work is supervisor verification, manual coverage/generated closure, and lifecycle handling, not source investigation.
- Related target/support docs checked: UIDs `0000PW`, `0000OB`, `0000D9`, `0001W5`, `0000W9`, `00024F`, `0000Q2`, `0001OL`, `0001C9`, `00006U`, `00002X`, `0000LC`, `0001Z8`, sibling static-string pages, generated StringUtil source, manual coverage reports, tracker, and executed/archived StringUtil-family research.
- Historical report-only creation checkpoint: B004 created this artifact without changing ordinary docs, coverage, generated files, validator state, IDA state, catalog, or lifecycle registry. Current report execution/archive state is authoritative only from the artifact's actual path plus validator-owned status/history metadata; this report prose does not assert a current lifecycle stage.

## Executive Recommendation

- Keep the direct semantic owner [UID:0000PW] and source root [UID:0000OB]. The global is shared infrastructure, not MetaMan-owned data and not a private ItemHelpPane or CollectionPane object.
- Treat `[0x0066daec,0x0066db04)` as one typed object. Reject splitting the union, length, and capacity into independent source globals.
- Keep [UID:00027J] non-duplicating and emit the definition/header declaration only through [UID:0000PW]/[UID:0000OB].
- Resolve the source placement to `NexusTK/util/StringUtil.cpp` plus `StringUtil.h`. The broad cross-subsystem caller set and established StringUtil owner are positive evidence; no unique function/string/type cluster establishes a separate `SimpleUString.cpp` translation unit.
- Use `SimpleUString` as the project-canonical human source-facing type while documenting that the exact recovered ABI is MSVC/Dinkumware wide-string SSO-7 compatible and the original lexical type name is inferred. Do not leak `dword_66DAEC`, `sub_419F20`, `sub_60C100`, or a raw `std::basic_string` implementation spelling into finalized project source.

## Supervisor Active Recheck

- The supervisor assigned UID00027J specifically to resolve its compiler-generated field/type/global names, exact SSO layout, static lifetime, source split/linkage, owner/emitter, and formal CPP/H rather than preserving old blockers.
- No range split is required before the master recommendation: the 24-byte half-open range is an exact object with a clean predecessor and successor fence.
- Every source-bearing element is covered: the storage page is non-duplicating, the semantic global owns the formal definition/declaration, StringUtil owns placement, SimpleUString owns the public class/facade, the SSO layout page owns ABI proof, and the startup/cleanup bodies remain compiler-generated support evidence.

## Inference Research Guidance Check

- `by-structure.md` discipline requires one concrete storage child under one semantic global and forbids duplicate emission. It also requires compiler-generated static wrappers to be explained by ordinary source rather than emitted as handwritten helpers.
- Existing documentation was treated as evidence, not authority. In particular, the prior unresolved source split, IDA's `dword_*` labels, the current 4-byte IDA `SimpleUString` UDT, and the assumption that loader bytes alone prove aggregate initialization were independently rechecked.
- Direct IDA fact: exact 24-byte bytes, fields, xrefs, helper bodies, wrapper boundaries, comment channels, type catalog, and matching sibling initializer lowering. Documentation evidence: current UID routing, project-facing `SimpleUString` conventions, and sibling bare default-construction formal. Inference: original source spelling, external linkage, default-construction source shape, and `StringUtil.cpp` placement.
- Wave2/Wave3 mentions in older material were ignored as stale workflow labels. No recommendation depends on them.

## Heuristic / Inference Reanalysis And Validation

- Global naming: 33 exact xrefs identify one process-wide empty fallback used by unrelated subsystems. Best name is `g_emptySimpleUString`, project-canonical and semantically specific. This is inferred/descriptive, not an original-symbol recovery.
- Field naming: `+0x00` is a storage union, not a pointer-only dword; `+0x10` is `m_length`; `+0x14` is `m_capacity`. The cleanup gate `capacity >= 8`, assignment helper, comparison loops, 24-byte element stride, terminator writes, and empty state `length=0/capacity=7` jointly resolve the fields.
- ABI type: exact layout is compatible with the Microsoft/Dinkumware UTF-16 `basic_string` SSO-7 representation. Existing IDA `SimpleUString` ordinal 835 is size 4 with only `wchar_t *m_data`; applying it would truncate/misdescribe the target. The safe IDA handoff therefore creates a separate 24-byte compatibility UDT while project source remains human-facing `SimpleUString`.
- Static-lifetime semantics: the loader image already contains the canonical empty-state bytes, then startup `0x419f20` invokes counted wide assignment from shared empty literal `0x60db20` with count zero and registers cleanup `0x60c100` through `atexit`. This is both initialized image state and dynamic construction lowering, not one or the other exclusively.
- Source initializer: bare default construction is the highest-probability source shape. The target and sibling UID0000Q2/UID0001OL static objects both lower through the same shared-empty-literal/count-zero assignment and paired `atexit` cleanup, while the sibling's accepted source formal is bare. The binary proves the lowering but cannot distinguish a literal `L""` source initializer by itself; inventing that spelling and a new overload would overfit compiler output.
- Cleanup: `0x60c100` is compiler-generated static destruction. It frees heap storage only when capacity exceeds the inline threshold, validates the allocation header for large aligned storage, then restores `length=0`, `capacity=7`, and the first inline wide NUL. It must not be emitted as a handwritten source function.
- Linkage: external linkage is strongly preferred. One address is referenced by reconstructed source families in metadata, item-help, collection, and later UI/string code. Under the current multi-file source model those users require one declaration visible outside StringUtil.cpp; file-local `static` is rejected.
- Source split: `StringUtil.cpp` is preferred over `SimpleUString.cpp`. Existing ownership, helper family grouping, generated route, and broad utility use support StringUtil. No path/string/RTTI/function neighborhood positively establishes a separate SimpleUString translation unit.
- Rejected `std::wstring` source replacement: the ABI/helpers are strongly standard-library-compatible, but current project docs and consumer-facing APIs consistently use `SimpleUString`. Replacing the full family with `std::wstring` from this one global would overreach and could erase project-facing wrapper semantics. Preserve the ABI compatibility note and defer any project-wide alias collapse to a separate whole-family audit.
- Rejected MetaMan ownership: MetaMan returns the fallback but does not uniquely construct, mutate, or own it; non-metadata users are direct counterevidence.

## Evidence Standards Used

- Evidence types: exact image bytes, item boundaries, data definitions, current names/types/comments, all field xref counts, representative callers/decompilations, VA/RVA/raw-offset pointer searches, static startup-table reachability, atexit registration, cleanup semantics, assignment/clear helper bodies, allocation/error strings, type catalog, neighboring boundaries, current docs, generated source, coverage/tracker state, and older reports.
- The evidence ladder starts with exact binary fact, uses repeated helper/caller behavior to identify the ABI, then applies project naming/source-tree conventions only where the executable cannot preserve lexical source.
- Confidence remains below certainty because original symbols and source files are absent. Tool limits do not affect layout or behavior: the object bytes, offsets, xrefs, and helper semantics are directly observable.

## Evidence Checked

- IDA MCP checks: `server_health`, data/entity queries at `0x66daec/0x66daf0/0x66daf4/0x66daf8/0x66dafc/0x66db00/0x66db04`, exact bytes and integer values, `xrefs_to`, VA/RVA/raw-offset `find_bytes`, type/name searches, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, frames, and all four comment channels for the target and wrappers.
- Docs/reports checked: target/global/file/class/layout pages, static initializer and cleanup aggregates, sibling UID0000Q2/UID0001OL global/storage pages, MetaMan lookup and representative consumer docs, data-section boundary, generated StringUtil source, all relevant manual coverage rows, current research tracker, and older executed StringUtil/static-string reports.
- Negative checks: no xrefs to interior `0x66daf0/4/8`; no RVA pointer pattern; one raw-offset byte hit belongs to a broader raw-offset/resource table, not a target pointer; no second object or target alias; no original source symbol; no type/name collisions for proposed compatibility UDT/wrapper names; no separate SimpleUString source-file proof; no evidence that the shared `L""` lowering came from an explicit source initializer rather than the established default constructor.
- Failed/unavailable checks: a redundant final PowerShell HTTP xref re-fetch was interrupted by host paging pressure after the required live MCP queries had already succeeded and their results were captured. No evidence claim depends on that redundant client attempt.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C01 | 00027J | Range `[0x66daec,0x66db04)` is one exact 24-byte object. | very strong | Bytes, item/xref fields, successor fence | `by-memory/...g_emptySimpleUString.md` / Summary, Layout | incorporate | applied |
| C02 | 00027J | Loader bytes are 20 zero bytes then capacity dword 7. | very strong | MCP bytes/value readback | target / Layout, Evidence | incorporate | applied |
| C03 | 00027J | `+0x00` is inline/heap union storage. | very strong | assign/clear/compare helpers | target / Layout | incorporate | applied |
| C04 | 00027J | `+0x10` is unsigned length. | very strong | helper stores/compares, 12 xrefs | target / Layout | incorporate | applied |
| C05 | 00027J | `+0x14` is unsigned capacity with SSO threshold seven. | very strong | cleanup gate/reset, 12 xrefs | target / Layout | incorporate | applied |
| C06 | 00027J | Object has 33 whole-storage xrefs and no interior aliases. | strong | `xrefs_to`, interior negative checks | target / Evidence | incorporate | applied |
| C07 | 00027J | Predecessor remap data and successor HourPane table are hard fences. | very strong | bytes/items at `0x66dae0` and `0x66db04` | target / Range analysis | incorporate | applied |
| C08 | 00027J | One raw-offset-pattern hit is resource-table coincidence, not pointer alias. | strong | VA/RVA/raw-offset search and surrounding table | target / Negative Evidence | incorporate | applied |
| C09 | 00027J | Target remains non-duplicating under semantic global UID0000PW. | very strong | by-structure chain and existing metadata | target / Assignment Gate, formal CPP | already-present | already-present |
| C10 | 00027J | Target score becomes `92/94`; route/reconstructable fields remain unchanged. | strong | blocker closure in this report | target / metadata, Score | incorporate | applied |
| C11 | 0000PW | Semantic name remains `g_emptySimpleUString`. | strong | cross-subsystem fallback semantics | global / Status, Role | already-present | already-present |
| C12 | 0000PW | Document that the retained bare global definition default-constructs through the observed shared-empty/count-zero lowering. | strong | matching target and UID0000Q2/UID0001OL startup wrappers plus sibling source formal | global / Lifetime, Source Declaration | incorporate | applied |
| C13 | 0000PW | Global header emits external declaration. | strong | multi-module users and source route | global / formal H | incorporate | applied |
| C14 | 0000PW | Global has external, not internal, linkage. | strong | one address used across reconstructed modules | global / Linkage | incorporate | applied |
| C15 | 0000PW | Global score becomes `92/93`; owner/emitter remain UID0000OB. | strong | layout/lifetime/linkage/source split closure | global / metadata | incorporate | applied |
| C16 | 0000OB | Source placement resolves to `NexusTK/util/StringUtil.cpp` and `.h`. | strong | owner chain, broad utility use, no separate-file evidence | file / source placement | incorporate | applied |
| C17 | 0000OB | StringUtil score becomes `90/91`; broader module facts remain. | medium-high | exact source/linkage closure, broader file still incomplete | file / metadata, Changes | incorporate | applied |
| C18 | 0000D9 | Move the complete `SimpleUString` class declaration from formal CPP to formal H; class CPP becomes blank. | very strong | declaration/definition channel rule and StringUtil.h owner route | class / formal CPP and H | incorporate | applied |
| C19 | 0000D9 | Exact ABI is MSVC/Dinkumware-compatible UTF-16 SSO-7. | very strong | helper bodies and layout | class / Representation Map | incorporate | applied |
| C20 | 0000D9 | Preserve the existing default constructor in formal H and reject an invented target-only `const wchar_t *` overload. | strong | repeated family lowering and UID0000Q2 sibling formal | class / formal H, Historical Assumptions | reject-invalid | excluded-with-reason |
| C21 | 0000D9 | Class score becomes `90/92`; owner/emitter stay UID0000OB. | strong | ABI/facade/static-instance/default-constructor lowering resolved | class / metadata | incorporate | applied |
| C22 | 0001W5 | Layout page records exact union/length/capacity field names and static instance proof. | very strong | target plus helpers | layout / Layout, Evidence | incorporate | applied |
| C23 | 0001W5 | Layout score becomes `90/93`; owner/emitter unchanged. | strong | target-specific live confirmation | layout / metadata | incorporate | applied |
| C24 | 0000W9 | `0x419f20` is target-specific compiler startup wrapper. | very strong | decompile/disasm/startup table | initializer aggregate / child inventory | incorporate | applied |
| C25 | 0000W9 | Wrapper assigns shared empty literal with count zero and registers cleanup. | very strong | exact body | initializer aggregate / Evidence | incorporate | applied |
| C26 | 0000W9 | Aggregate remains nonreconstructable/non-emitting and score unchanged. | very strong | compiler startup lowering | initializer aggregate / metadata | already-present | already-present |
| C27 | 00024F | `0x60c100` is target-specific static cleanup body. | very strong | sole registration xref and exact body | cleanup aggregate / child inventory | incorporate | applied |
| C28 | 00024F | Cleanup restores length zero, capacity seven, and inline NUL after conditional free. | very strong | decompile/disassembly | cleanup aggregate / Evidence | incorporate | applied |
| C29 | 00024F | Aggregate remains nonreconstructable/non-emitting and score unchanged. | very strong | compiler static-destruction lowering | cleanup aggregate / metadata | already-present | already-present |
| C30 | 00027J | MetaMan is a consumer, not owner. | strong | non-metadata xrefs and fallback returns | target / Ranked ownership | incorporate | applied |
| C31 | 00027J | ItemHelpPane and CollectionPane are consumers, not owners. | strong | representative xrefs and one global address | target / Ranked ownership | incorporate | applied |
| C32 | 00027J | Do not split the three IDA dwords into source globals. | very strong | coherent object helper behavior | target / Range analysis | incorporate | applied |
| C33 | 00027J | Historical open StringUtil/SimpleUString source split is resolved, not deleted. | strong | current source-tree and negative evidence | target / Historical assumptions | historicalize | applied |
| C34 | 0000PW | Reject the overfit explicit-`L""` definition/new-overload alternative and preserve why matching sibling lowering favors the historical bare definition. | strong | UID0000Q2/UID0001OL wrapper and source-formal comparison | global / Historical Assumptions, formal CPP | reject-invalid | excluded-with-reason |
| C35 | 0000D9 | Reject applying current IDA ordinal835 size-4 `SimpleUString` to target. | very strong | type catalog and target size | class / IDA status | reject-invalid | excluded-with-reason |
| C36 | 00027J | Create IDA union `SimpleUStringSso7Storage` with exact size `0x10` and the two offset-zero inline/heap members. | very strong | exact helper ABI, target bytes, and absent-name/type collision checks | report IDA handoff / IDA-27J-001 | incorporate | applied |
| C37 | 00027J | Create IDA struct `SimpleUStringSso7` with exact size `0x18` and storage/length/capacity members at `+0x00/+0x10/+0x14`. | very strong | exact helper ABI, target field xrefs, and absent-name/type collision checks | report IDA handoff / IDA-27J-002 | incorporate | applied |
| C38 | 00027J | Consolidate `[0x66daec,0x66db04)` as one `SimpleUStringSso7` IDA data item without changing bytes, xrefs, or fences. | very strong | exact item boundaries, bytes, field xrefs, predecessor, and successor | report IDA handoff / IDA-27J-003 | incorporate | applied |
| C39 | 00027J | Rename the consolidated IDA data item at `0x66daec` to `g_emptySimpleUString`. | strong | project-canonical shared-fallback semantics and absent collision | report IDA handoff / IDA-27J-004 | incorporate | applied |
| C40 | 00027J | Add the exact repeatable IDA address comment for `g_emptySimpleUString`. | strong | resolved layout, lifetime, and source-owner evidence | report IDA handoff / IDA-27J-005 | incorporate | applied |
| C41 | 0000W9 | Rename function `[0x419f20,0x419f3d)` to `g_emptySimpleUString_StaticInitializer`. | strong | exact startup wrapper body, target use, atexit pairing, and absent collision | report IDA handoff / IDA-27J-006 | incorporate | applied |
| C42 | 0000W9 | Set the initializer wrapper declaration to `int __cdecl g_emptySimpleUString_StaticInitializer(void)`. | strong | exact no-argument frame, call graph, body, and current `int()` prestate | report IDA handoff / IDA-27J-007 | incorporate | applied |
| C43 | 0000W9 | Remove the stale regular address comment `int` from `0x419f20`. | strong | literal current comment prestate and absence of semantic value | report IDA handoff / IDA-27J-008 | incorporate | applied |
| C44 | 0000W9 | Add the exact function-repeatable static-initialization comment at `0x419f20`. | strong | exact shared-empty assignment, target, and atexit behavior | report IDA handoff / IDA-27J-009 | incorporate | applied |
| C45 | 00024F | Rename function `[0x60c100,0x60c15d)` to `g_emptySimpleUString_StaticCleanup`. | strong | exact sole registration, cleanup body, current live type readback, and absent collision | report IDA handoff / IDA-27J-010 | incorporate | applied |
| C46 | 00024F | Preserve the already-present no-argument cleanup prototype whose exact live IDA presentation is `void __cdecl()`; perform no type mutation. | very strong | independent `inspect_items` and `analyze_function` readback plus unchanged ABI/frame | report IDA handoff / IDA-27J-011 | already-present | already-present |
| C47 | 00024F | Add the exact function-repeatable static-destruction comment at `0x60c100`. | strong | exact conditional-free, validation, and empty-state restoration body | report IDA handoff / IDA-27J-012 | incorporate | applied |
| C48 | 00027J | Shared helpers `0x421310/0x421590` remain protected dependencies. | strong | broad caller fan-in | report IDA handoff / protected dependencies | already-present | already-present |
| C49 | 00027J | Formal target CPP remains a no-duplicate ABI/storage comment and H remains blank. | very strong | emitter chain | target / formal CPP/H | incorporate | applied |
| C50 | 00027J | Manual by-memory coverage row needs exact replacement. | very strong | current stale 86% row | `by-memory/-coverage-report.md` / UID00027J | incorporate | proposed |
| C51 | 0000PW | Manual by-global coverage row needs exact replacement. | very strong | current stale 88% row | `by-global/-coverage-report.md` / UID0000PW | incorporate | proposed |
| C52 | 0000OB | Manual by-file coverage row needs exact replacement. | strong | score/source summary change | `by-file/-coverage-report.md` / UID0000OB | incorporate | proposed |
| C53 | 0000D9 | Manual by-class coverage row needs exact replacement. | strong | score/ABI summary change | `by-class/-coverage-report.md` / UID0000D9 | incorporate | proposed |
| C54 | 0001W5 | Manual by-struct coverage row needs exact replacement. | strong | score/layout summary change | `by-type/by-struct/-coverage-report.md` / UID0001W5 | incorporate | proposed |
| C55 | 0000W9 | Manual initializer aggregate row needs exact same-score description replacement. | strong | target wrapper now exact | `by-memory/-coverage-report.md` / UID0000W9 | incorporate | proposed |
| C56 | 00024F | Manual cleanup aggregate row needs exact same-score description replacement. | strong | target cleanup now exact | `by-memory/-coverage-report.md` / UID00024F | incorporate | proposed |
| C57 | 00027J | Command19483 refreshed generated StringUtil CPP/H and the tracker after ordinary callback; future supervisor lifecycle may advance the moving tracker but no generated source change is presently missing. | very strong | current command19483 CPP/H hashes and tracker 92/94 row | supervisor lifecycle / generated currentness | inspect-and-retain | already-present |

## Positive Evidence Summary

- Exact object bytes and helper behavior independently agree on a 24-byte SSO-7 object: union storage `+0x00`, length `+0x10`, capacity `+0x14`, inline threshold seven, wide NUL terminator, and 24-byte array stride.
- Startup and cleanup are paired by literal target address and `atexit`, proving one static-lifetime object rather than incidental constants.
- Sibling UID0000Q2/UID0001OL has the same 24-byte empty SSO state and the same shared-empty/count-zero startup lowering, yet its accepted source formal is bare default construction; this supplies family-level positive evidence for `SimpleUString g_emptySimpleUString;` and negative evidence against a target-only overload.
- Missing metadata lookups return the exact object, while ItemHelpPane, CollectionPane, and later UI/string code also consume it; this proves shared fallback semantics and rejects consumer-local ownership.
- The current owner chain already matches source structure. The newly resolved linkage and source placement are a refinement, not a routing reversal.

## IDA MCP Facts

- Current function/range facts after catalog0360: `g_emptySimpleUString_StaticInitializer` is `[0x419f20,0x419f3d)`, `0x1d` bytes, exact live prototype `int __cdecl()`; protected `sub_421310` is `[0x421310,0x421362)`, `0x52` bytes; protected `sub_421590` is `[0x421590,0x4216cb)`, `0x13b` bytes; `g_emptySimpleUString_StaticCleanup` is `[0x60c100,0x60c15d)`, `0x5d` bytes, exact preserved prototype `void __cdecl()`.
- Sibling-lowering fact: `sub_419FF0` `[0x419ff0,0x41a00d)` initializes UID0001OL `g_metaAliasTableName` with the same `sub_421590(..., shared-empty-literal, 0)` pattern and registers `sub_60C2A0` through `atexit`; this is independent family evidence for default-constructor lowering.
- Historical data prestate was `dword_66DAEC` size 4 type `void *`, undefined interiors, `dword_66DAFC` size 4 type `int`, and `dword_66DB00` size 4 with blank type. Current saved state is one exact `[0x66daec,0x66db04)` `SimpleUStringSso7` item named `g_emptySimpleUString`; IDA's automatic intermediate `stru_66DAEC` normalization is historical. Successor `g_hourFrameTable` still begins exactly at `0x66db04` as `__int16[12]`.
- Xref facts: 33 refs to `0x66daec`, 12 to `0x66dafc`, 12 to `0x66db00`, and zero to interior `0x66daf0/4/8`. Startup target use is at `0x419f27`; cleanup is registered at `0x419f31`; cleanup has no ordinary caller.
- Current type facts: `SimpleUStringSso7Storage` is an exact `0x10` union with `wchar_t m_inlineBuffer[8]` and `wchar_t *m_heapBuffer` at offset zero. `SimpleUStringSso7` is an exact `0x18` struct with that union at `+0x00`, unsigned `m_length` at `+0x10`, and unsigned `m_capacity` at `+0x14`. IDA `SimpleUString` ordinal 835 remains size 4 with `wchar_t *m_data` and was protected unchanged.
- Current comment facts: `g_emptySimpleUString` has absent address regular comment and the exact accepted repeatable address comment. Both wrappers have address regular/repeatable and function regular comments absent; each has its exact accepted function-repeatable compiler-lowering comment. The stale initializer address-regular `int` was removed.
- Cleanup-prototype fact: catalog0360 preserved exact empty-parentheses `void __cdecl()` for `g_emptySimpleUString_StaticCleanup`; no cleanup type mutation occurred. Initializer type readback is exact `int __cdecl()`.
- Protected facts: target/member xrefs remain `33/0/0/0/12/12`; object/wrapper/helper/literal byte hashes and fences remain unchanged; no original symbol, interior alias, RVA pointer pattern, separate SimpleUString source identity, or valid target pointer at the one raw-offset table hit appeared.
- Save/currentness fact: catalog0360's successful UID00027J save is historical SHA256 `03F10207763C01455EA5F767F330A371FEDD9885FBFD98705F5A486985DBE5DA`, 143,190,601 bytes, last write `2026-07-29T13:03:43.9987735-04:00`; prestate backup SHA256 is `08D31FD1C7B80721D6CD7774B42C5A5157B3A4683670A3E27EA5660290554F5A`. Later `905D1AB1...604C1`, `296ED21C...63CF8B`, `0E0AF938...AB481`, and `3C8F3178...5B69` identities are historical. The current authoritative shared IDB is SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; bounded read-only MCP readback found no UID00027J drift.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x66daec-0x66db04` | UID00027J target | exact global storage | true | UID0000PW | 92/94 | source-bearing evidence, non-duplicating; ordinary and IDA state applied |
| semantic global | UID0000PW `by-global/g_emptySimpleUString.md` | definition/declaration owner | true | UID0000OB | 92/93 | bare CPP and extern H applied |
| `0x419f20-0x419f3d` | child of UID0000W9 | `g_emptySimpleUString_StaticInitializer`, compiler wrapper | false as standalone | source global | aggregate 80/strong | catalog0360 saved support; non-emitting |
| `0x421310-0x421362` | UID0002DV | shared SSO clear method | true | UID0000D9 | 85/strong | protected shared dependency |
| `0x421590-0x4216cb` | UID0002E3 | shared counted wide assign method | true | UID0000D9 | 85/strong | protected shared dependency |
| `0x60c100-0x60c15d` | child of UID00024F | `g_emptySimpleUString_StaticCleanup`, compiler wrapper | false as standalone | source global | aggregate 75/strong | catalog0360 saved support; non-emitting |
| `0x66de18-0x66de30` | UID0001OL / UID0000Q2 sibling | matching empty static SSO object | true, support-only | UID0000Q2 | 88/89 support | family-level default-construction comparator; no report coverage/change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x66daec` | 33 data refs across startup, cleanup, MetaMan, ItemHelpPane, CollectionPane, and later UI/string code | one shared object identity |
| `0x66dafc` | 12 refs | length field read/write |
| `0x66db00` | 12 refs | capacity field read/write/gate |
| `0x419f20` | sole startup-table data route at `0x60d6ac` | compiler CRT initialization, no human caller |
| `0x419f27` | target passed to `sub_421590` with `initialText`, count 0 | observed default-constructor lowering through shared empty-wide assignment |
| `0x419f31` | `atexit(sub_60C100)` | static-lifetime cleanup pairing |
| `0x4ccca0` | ItemHelpPane population family | compare against shared empty fallback |
| `0x523120/0x5231f0/0x523a70/0x523b40` | MetaMan lookup family | missing lookup returns or compares fallback |
| `0x56edc0` | CollectionPane family | shared string fallback use |
| `0x5adad0` | later UI/string helper | copies fallback into 24-byte fields |
| `0x60c100` | sole initializer registration route | compiler static cleanup, no ordinary code caller |
| `0x419ff0` | sibling UID0001OL initializer | same shared-empty/count-zero assignment plus `atexit`, supporting default-constructor lowering |

## Documentation Evidence And IDA Status

- Supporting docs correctly identify the semantic global, exact storage, shared fallback role, owner chain, SSO-7 helper family, and compiler-generated wrapper containers.
- Applied ordinary state: target/global fields, source split, external declaration, default-constructor lowering, class/layout static-instance proof, formal CPP/H channels, historical assumptions, and accepted scores are now synchronized across all seven destinations. The exact post-callback hashes are recorded under Supporting Research and Changed Files.
- Applied IDA state: catalog0360 replaces raw target/wrapper labels with the exact typed object and source-quality navigation names/comments while preserving bytes/xrefs/fences and broad shared helpers. Manual coverage rows remain stale until supervisor applies the seven exact payloads.
- Current generated state is command19483: StringUtil.cpp contains the exact UID0000PW definition and StringUtil.h contains the complete UID0000D9 class plus UID0000PW extern declaration. Command19259 is preserved as the dated pre-callback checkpoint where the class/global routing was stale and StringUtil.h was absent; command19221/19201 and commands19068/19152 are earlier history. B004 did not edit generated files, and the supervisor must reread these moving artifacts before lifecycle action rather than assuming this checkpoint remains current.

## Ranked Ownership Analysis

### 1. UID0000PW global through UID0000OB StringUtil

- Evidence for: exact semantic/global relationship, broad shared consumers, established owner chain, string utility infrastructure, and one non-duplicating source definition.
- Evidence against: no original source path string or symbol survives.
- Decision: accepted with strong confidence.

### 2. UID0000D9 SimpleUString / dedicated SimpleUString.cpp

- Evidence for: the object uses the exact SSO-7 class ABI and methods.
- Evidence against: class ownership does not establish a separate translation unit; current source tree and emitter root are StringUtil; no neighboring cluster uniquely requires `SimpleUString.cpp`.
- Decision: class remains type owner, but a separate source file is rejected for this pass.

### 3. UID0000LC MetaMan or consumer-local ownership

- Evidence for: MetaMan missing-lookup paths prominently return the object.
- Evidence against: ItemHelpPane, CollectionPane, and unrelated UI/string paths use the same address; MetaMan does not uniquely initialize or mutate it.
- Decision: rejected as source owner; retain as consumer/dependency.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new file. Use existing `NexusTK/util/StringUtil.cpp` and `StringUtil.h`.
- Likely full contents: existing StringUtil class/helper/global family plus the single global definition/declaration.
- Candidate related items that belong: UID0000PW definition/header declaration; UID0000D9 class declaration; UID0001W5 ABI documentation.
- Candidate related items rejected: compiler wrapper bodies as standalone source, MetaMan-local duplicate, and a speculative new SimpleUString.cpp.
- Standalone/narrow/broad inference: broad existing StringUtil source root is best supported.

## Source Placement

- Recommended placement: `NexusTK/util/StringUtil.cpp` definition, `NexusTK/util/StringUtil.h` declaration, with UID0000PW as semantic emitter and UID00027J as concrete storage evidence.
- This fits the current source-tree route, shared cross-feature use, and the class/helper family already grouped under StringUtil.
- Rejected placements: `metadata/MetaMan.cpp` is consumer-biased; ItemHelp/Collection source would duplicate ownership; `SimpleUString.cpp` lacks affirmative split evidence; anonymous-namespace/file-static placement conflicts with external multi-module use.
- Remaining uncertainty: exact original filename and namespace cannot be symbol-proven. The selected placement is sufficiently probable for human source reconstruction and no longer blocks formal code.

## Range / Split / Padding / Reclassification Analysis

- Exact range: target begins at `0x66daec` after legacy/remap data and ends at `0x66db04` immediately before the 24-byte HourPane frame table.
- No child split: the three current IDA dwords are fields of one object; splitting would destroy the union and object-lifetime semantics.
- The 12 interior bytes at `0x66daf0-0x66dafc` are inline UTF-16 storage within the union, not padding or unowned data.
- No reclassification of reconstructability or owner route is needed. Only IDA item consolidation/type/name and documentation detail/score/formal changes are required.

## Negative Evidence Summary

- Zero xrefs to interior storage reject independent subglobals.
- No RVA pointer hit and the raw-offset table context reject a hidden alternate target pointer.
- No original symbols or source paths prove lexical spelling; all source names remain explicitly classified as project-canonical inference.
- Existing IDA ordinal835 cannot type this object because it is only 4 bytes.
- Broad consumer xrefs reject MetaMan/private UI ownership.
- No source-cluster evidence supports a dedicated SimpleUString.cpp.
- Cleanup/startup-table-only reachability rejects handwritten wrapper emission.

## IDA Rename / Type / Comment Recommendations

All IDA actions were supervisor-owned. Historical literal prestates are preserved in each row; catalog entry `0360` is the authoritative applied/read-back action record and its `03F102...DBE5DA` save is a historical UID00027J checkpoint. Every row's current state was reverified without drift under authoritative shared IDB `412DA7E8...519CD`; `905D1AB1...604C1` and `296ED21C...63CF8B` are historical. B004 made no IDA mutation. Comment-channel notation is literal: address regular (AR), address repeatable (AP), function regular (FR), function repeatable (FP).

| Action ID | Exact entity/range | Literal current prestate | Canonical classification | Exact action and evidence | Protected constraints | Literal expected readback |
| --- | --- | --- | --- | --- | --- | --- |
| IDA-27J-001 | type catalog, union | Current saved state: `SimpleUStringSso7Storage` exists once, size `0x10`, with `wchar_t m_inlineBuffer[8]` and `wchar_t *m_heapBuffer` at offset zero; type comment channels are not applicable. Historical prestate: name/declaration/size/ordinal/members absent. | already present | Catalog0360 applied the accepted exact union from helper ABI and target bytes; very strong. | Existing ordinal835 `SimpleUString` remains size four and unchanged; do not create a 4-byte alias. | Catalog0360 readback matched one exact `0x10` union with the two stated offset-zero members and no collision at historical save `03F102...DBE5DA`; current authoritative `412DA7E8...519CD` readback remains identical. |
| IDA-27J-002 | type catalog, struct | Current saved state: `SimpleUStringSso7` exists once, size `0x18`, with `SimpleUStringSso7Storage m_storage` `+0x00`, `unsigned int m_length` `+0x10`, and `unsigned int m_capacity` `+0x14`; type comment channels are not applicable. Historical prestate: absent. | already present | Catalog0360 applied the accepted exact struct from helper ABI and field xrefs. | Preserve union size/offsets; no packing invention; do not replace project source type. | Catalog0360 readback matched exact size, three members, offsets, and types with no collision at historical save `03F102...DBE5DA`; current authoritative `412DA7E8...519CD` readback remains identical. |
| IDA-27J-003 | data `[0x66daec,0x66db04)` | Current saved state: one item, size `0x18`, final name `g_emptySimpleUString`, type `SimpleUStringSso7`, AR absent, exact AP from IDA-27J-005, FR/FP not applicable. Historical prestate: three dword pieces/undefined interiors; `make_data` automatically normalized intermediate name to `stru_66DAEC` before the final rename. | already present | Catalog0360 consolidated exactly the accepted range as one typed item. | Preserve all 24 bytes, xrefs `33/0/0/0/12/12`, predecessor, successor `g_hourFrameTable`, and no item beyond `0x66db04`. | One exact `[0x66daec,0x66db04)` item with final name/type/comments; automatic `stru_66DAEC` is historical; bytes/xrefs/fences unchanged and saved. |
| IDA-27J-004 | data head `0x66daec` | Current saved state: exact name `g_emptySimpleUString`, item `[0x66daec,0x66db04)`, size `0x18`, type `SimpleUStringSso7`, AR absent, exact AP present, FR/FP not applicable. Historical prestate name `dword_66DAEC`; proposed-name collision was absent. | already present | Catalog0360 applied the accepted semantic rename after consolidation. | Do not rename fields as globals or create interior aliases; preserve range/type/bytes/xrefs. | Exact final name is present once with no duplicate/collision; member xrefs remain attached and saved. |
| IDA-27J-005 | data head `0x66daec` | Current saved state: final name/type/range as above; AR absent; AP exactly `Process-wide empty SimpleUString fallback. ABI view is a 24-byte UTF-16 SSO-7 object: inline/heap union +0x00, length +0x10, capacity +0x14; default construction lowers through shared L"" count-zero assignment and paired static cleanup.`; FR/FP not applicable. Historical prestate comments were absent. | already present | Catalog0360 applied the exact accepted AP after consolidation/rename. | Leave AR absent; no interior comments or original-symbol claim; preserve range/type/name/bytes/xrefs. | Exact AP and blank AR were read back on the final one-item state and saved. |
| IDA-27J-006 | function `[0x419f20,0x419f3d)` | Current saved state: `g_emptySimpleUString_StaticInitializer`, exact live prototype `int __cdecl()`, frame `__return_address +0x0`, AR/AP/FR absent, exact FP from IDA-27J-009. Historical prestate name `sub_419F20`, type `int()`, AR literal `int`, other comments absent. | already present | Catalog0360 applied the accepted source-quality navigation rename. | Preserve bytes/range/xrefs/frame/declaration/comments and compiler-wrapper non-emitting status. | Exact final name/range/frame/comments/prototype were read back; bytes/xrefs unchanged and saved. |
| IDA-27J-007 | function `[0x419f20,0x419f3d)` | Current saved state: `g_emptySimpleUString_StaticInitializer`, exact live prototype presentation `int __cdecl()`, frame `__return_address +0x0`, AR/AP/FR absent, exact FP present. Historical prestate type was `int()`. | already present | Catalog0360 applied the accepted cdecl/no-argument type; live presentation normalized to `int __cdecl()` rather than report proposal spelling with `(void)`. | Preserve no-argument frame/range/call graph/bytes/xrefs; do not invent a constructor method. | Exact live `int __cdecl()` presentation, one return-address frame entry, range/call graph, and comments were read back and saved. |
| IDA-27J-008 | address `0x419f20` | Current saved state: initializer name/type/range as above; AR absent, AP absent, FR absent, exact FP present. Historical AR literal was `int`. | already present | Catalog0360 removed only the stale regular address comment. | Do not remove code/function or alter AP/FR/FP; preserve exact range/declaration/frame/bytes/xrefs. | AR is absent and all other final channels/state match the accepted poststate. |
| IDA-27J-009 | function `[0x419f20,0x419f3d)` | Current saved state: final name/type/frame; AR/AP/FR absent; FP exactly `Compiler static-initialization wrapper for g_emptySimpleUString. Default construction lowers through shared L"" count-zero assignment to the 24-byte SSO-7 object, then registers g_emptySimpleUString_StaticCleanup with atexit; represent this through the source-level global, not a standalone helper.` Historical FP was absent. | already present | Catalog0360 applied the exact accepted compiler-lowering FP. | Preserve exact range/prototype/frame/bytes/xrefs/startup-table route and non-emitting disposition. | Exact FP and blank other channels were read back and saved; range/bytes/xrefs unchanged. |
| IDA-27J-010 | function `[0x60c100,0x60c15d)` | Current saved state: `g_emptySimpleUString_StaticCleanup`, exact live prototype `void __cdecl()`, frame `__return_address +0x0`, AR/AP/FR absent, exact FP from IDA-27J-012. Historical prestate name `sub_60C100`; comments absent. | already present | Catalog0360 applied the accepted source-quality navigation rename. | Preserve bytes/range/xrefs/frame/declaration/comments, existing no-argument type, and non-emitting status. | Exact final name/range/frame/prototype/comments were read back; sole registration/bytes/xrefs unchanged and saved. |
| IDA-27J-011 | function `[0x60c100,0x60c15d)` | Current saved state: `g_emptySimpleUString_StaticCleanup`, exact live no-argument prototype `void __cdecl()`; frame/comment state as above. Historical prestate already had `void __cdecl()`. | already present | Catalog0360 intentionally performed no cleanup type mutation; earlier `(void)` wording was report presentation only. | Do not add `this`, arguments, return value, or class scope; preserve range/frame/bytes/xrefs/comments. | Exact empty-parentheses no-argument prototype remains unchanged after rename/comment actions and is durably saved. |
| IDA-27J-012 | function `[0x60c100,0x60c15d)` | Current saved state: final name/prototype/frame; AR/AP/FR absent; FP exactly `Compiler static-destruction wrapper for g_emptySimpleUString. Frees heap storage when capacity exceeds the inline SSO-7 threshold, then restores length 0, capacity 7, and the first inline wide NUL; represent this through the source-level global destructor.` Historical FP was absent. | already present | Catalog0360 applied the exact accepted compiler-destruction FP without type mutation. | Preserve exact range/prototype/frame/bytes/xrefs/allocation validation, cleanup body, and no-argument ABI. | Exact FP and blank other channels were read back and saved; range/bytes/xrefs unchanged. |

Protected shared dependencies: `sub_421310` `[0x421310,0x421362)` and `sub_421590` `[0x421590,0x4216cb)` are broad-caller class methods and are outside this bounded target mutation. Preserve their bytes, names/types/comments, and xrefs for their direct UID pages; do not duplicate class-method changes from this storage report. Shared empty literal `initialText` at `0x60db20` is used broadly and must not be renamed target-specifically.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The object behavior, source owner, linkage, and exact ABI are strong enough.
- Target [UID:00027J] exact resulting CPP block:

```cpp
// Storage for g_emptySimpleUString is emitted by UID0000PW. The executable
// materializes this one 24-byte UTF-16 SSO-7 object as inline/heap storage,
// length, and capacity; do not emit a duplicate definition from this page.
```

- Target [UID:00027J] exact resulting H block: blank.
- Semantic global [UID:0000PW] exact resulting CPP block:

```cpp
SimpleUString g_emptySimpleUString;
```

- Semantic global [UID:0000PW] exact resulting H block:

```cpp
extern SimpleUString g_emptySimpleUString;
```

- Class [UID:0000D9] exact resulting CPP block: blank. No standalone class implementation belongs in this channel; method definitions remain attached through exact child emitters.
- Class [UID:0000D9] exact complete resulting H block:

```cpp
class SimpleUString
{
public:
    SimpleUString();
    ~SimpleUString();

    void Clear();
    SimpleUString& Assign(const wchar_t *source, unsigned int length);
    wchar_t *MutableData()
    {
        return m_capacity > 7 ? m_heapBuffer : m_inlineBuffer;
    }

private:
    union
    {
        wchar_t m_inlineBuffer[8];
        wchar_t *m_heapBuffer;
    };
    unsigned int m_length;
    unsigned int m_capacity;

    [[CHILDREN]]
};
```
- Reason behavior is preserved: the established default constructor lowers to the observed shared-empty counted assignment, one shared external object supports all consumers, and normal static destruction accounts for the cleanup body.
- Reason source shape is plausible: the matching UID0000Q2/UID0001OL object uses the same lowering with a bare source definition, so an ordinary named utility global, existing default constructor, extern declaration, and private SSO fields better resemble mid-2000s MSVC C++ source than a target-only overload inferred from decompiler output.
- Inferred source-facing names: `g_emptySimpleUString`, `m_inlineBuffer`, `m_heapBuffer`, `m_length`, `m_capacity`; all are marked inferred/project-canonical rather than original-symbol proof.
- Style: existing project `g_` global convention and `m_` member convention; execution fidelity and human source shape take priority over style consistency.
- Third-party import: not applicable; this is project-owned source/ABI evidence, not a vetted source embed.

## Final Recommendation

- B004 applied every accepted target/support documentation and score change while preserving historical evidence and rejected alternatives.
- UID00027J is `92/94` with unchanged owner/emitter/reconstructable state and the exact non-duplicate CPP/blank-H disposition.
- UID0000PW is `92/93` with bare formal CPP, exact extern H, linkage/placement/default-constructor-lowering detail, and unchanged owner/emitter.
- UID0000OB is `90/91`; UID0000D9 is `90/92` with blank CPP and complete H; UID0001W5 is `90/93`. UID0000W9 and UID00024F contain exact wrapper evidence while retaining ignored/non-emitting classifications and existing scores.
- Supervisor Gate 2B applied and verified IDA-27J-001 through IDA-27J-012 and cataloged entry `0360`; its save SHA `03F102...DBE5DA` is historical. Bounded current readback under authoritative shared IDB `412DA7E8...519CD` found no target/dependency drift; `905D1AB1...604C1` and `296ED21C...63CF8B` are historical. Command19483 already provides post-callback generated CPP/H and tracker currentness; fresh supervisor Gate 1/Gate 2 review, manual coverage, and lifecycle execution remain outstanding.
- No target remains no-owner or blocked. Lexical original-name uncertainty remains a score cap, not a reason to keep raw labels or blank source.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md`.
- Applied exact bytes, one-object range, union/length/capacity layout, xref families, pointer-pattern negatives, loader/dynamic lifetime, sibling default-constructor lowering, external linkage, StringUtil placement, ABI/source-type distinction, protected helpers, saved IDA state, and historicalized prior split caveat.
- Applied metadata `92/94`; owner `0000PW`, reconstructable true, emitter `0000PW`, and position remain unchanged.
- Applied the exact no-duplicate CPP block; H remains blank. Historical B007 evidence is retained, with only unresolved split/linkage and less precise field wording explicitly superseded.

## Recommended Support Doc Changes

- `by-global/g_emptySimpleUString.md` [UID0000PW]: exact ABI/lifetime/linkage/source-placement/sibling evidence, bare CPP, extern H, score `92/93`, and saved IDA reconciliation are applied; owner/emitter `0000OB` retained.
- `by-file/StringUtil.md` [UID0000OB]: exact StringUtil.cpp/.h placement, external declaration, class/global H routing, ABI/source distinction, score `90/91`, broader history, and catalog0360 state are applied.
- `by-class/SimpleUString.md` [UID0000D9]: complete declaration moved from CPP to H, blank CPP retained, existing default constructor preserved, unsupported target-only overload rejected, static-instance/lifetime/ABI evidence added, score `90/92`, and owner/emitter `0000OB` retained.
- `by-type/by-struct/SimpleUStringSso7Layout.md` [UID0001W5]: exact object/fields/initializer/cleanup/compatibility UDT evidence and score `90/93` are applied; owner `0000D9` and emitter route retained.
- `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md` [UID0000W9]: exact initializer child/source cause and saved name/type/comment state are applied; ignored/non-emitting classification and current page score retained.
- `by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md` [UID00024F]: exact cleanup child/source cause and saved name/no-change-type/comment state are applied; ignored/non-emitting classification and current page score retained.
- Consumer pages are evidence-only and need no score/formal/metadata change from this report.
- Sibling UID0000Q2/UID0001OL pages are inspected-and-retained evidence-only comparators; their current bare default-construction formal and metadata require no change and receive no report coverage claim.

## Score And Metadata Recommendation

- UID00027J: applied `87/89 -> 92/94`; owner/emitter/reconstructable unchanged.
- UID0000PW: applied `89/88 -> 92/93`; owner/emitter/reconstructable unchanged.
- UID0000OB: applied `89/89 -> 90/91`; broader file ownership unchanged.
- UID0000D9: applied `89/90 -> 90/92`; owner/emitter/reconstructable unchanged.
- UID0001W5: applied `86/89 -> 90/93`; owner/emitter/reconstructable unchanged.
- UID0000W9 and UID00024F: retain aggregate classifications/scores; target-specific detail improves documentation without making compiler wrappers source emitters.
- Reason not higher: no original symbols/source path survive, `SimpleUString` versus the exact original library/facade spelling remains inferred, and current class/layout/StringBase evidence proves this target's SSO-7 side but cannot recover the original project-wide lexical alias relationship with the separate pointer-backed family.
- Reason not lower: exact bytes, boundaries, all field/whole-object xrefs, startup/cleanup pair, helper ABI, consumer spread, source route, formal emitter placement, and safe IDA handoff are now resolved.
- Score-improvement work: every formerly named blocker was actively checked and closed to a high-probability direction; none is left as "needs investigation." The final family comparison corrected rather than deferred the initializer/source-shape ambiguity.

## Open Questions With Attempted Resolution

- Original type spelling: checked current type catalog, helper ABI, older reports, class/layout docs, and standard-library signatures. Resolution: preserve project source `SimpleUString`, explicitly document MSVC/Dinkumware SSO-7 compatibility, and use a distinct IDA ABI UDT. Exact lexical proof is unavailable and caps confidence only.
- Default versus explicit empty initializer: checked loader bytes, target startup decompile/disassembly, shared literal, count argument, cleanup registration, and the independently matching UID0000Q2/UID0001OL initializer/source formal. Resolution: bare default construction is strongest; its compiler lowering performs the observed shared-`L""` count-zero assignment. An explicit source literal and a new `const wchar_t *` constructor overload are rejected as unsupported overfitting.
- Internal versus external linkage: checked cross-subsystem xrefs and current multi-file source routes. Resolution: external linkage plus header declaration; `static` rejected.
- StringUtil.cpp versus SimpleUString.cpp: checked current owner tree, generated path, helper grouping, docs, and absence of source-file evidence. Resolution: StringUtil.cpp/.h; separate file rejected.
- SSO-7 versus pointer-backed family identity: checked UID0000D9, UID0001W5, UID0001W4, UID0001WS, exact helper object sizes, and current formal APIs. Resolution: this target is the 24-byte SSO-7 `SimpleUString` side; the size-4 pointer-backed family is excluded from this object's type and formal code. The stripped binary cannot prove the original project-wide alias spelling, which caps the broader class confidence but does not defer or block this target's source reconstruction.
- Whether to emit wrappers: checked startup-table-only and atexit-only routes. Resolution: no standalone source emission; ordinary global construction/destruction is sufficient.
- Residual lexical-spelling disposition: the stripped executable cannot prove the original identifiers, but cross-family behavior and project style support `g_emptySimpleUString`, `m_inlineBuffer`, `m_heapBuffer`, `m_length`, and `m_capacity` as the deterministic human-source names. No raw label remains in finalized source. This evidence-bounded lexical uncertainty caps 95+ confidence but is resolved for implementation and does not defer source or IDA action.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Frozen report-time manual checkpoints: `by-memory/-coverage-report.md` SHA `4590B3D98DBA30CB219E064E793186C941E766EE4B539856B3D6ADAD16DFC8FE`; `by-global/-coverage-report.md` SHA `C8402BC1CF8E639E7A9F75BC94BD9A7F0F17010E1E4FB363775C643440A32D89`; `by-file/-coverage-report.md` SHA `7ED5B1C29EDB238363AE743F78AF63871102F8B5AC6E0D688D397A2A00E3D511`; `by-class/-coverage-report.md` SHA `91E531941902D7EB9D4C3BCBB9CC58B7385F223C1E82B17C70FE7069FBA99354`; `by-type/by-struct/-coverage-report.md` SHA `9522306D105A425C756E1D8F74633B07F4821F3766C2C69280ADEFF1C6FABFA7`. At that checkpoint every listed UID row and predecessor/successor anchor was textually unchanged and each payload below was an applicable in-place replacement, not an insert or no-op. The supervisor must re-read moving manual files before applying any payload.
- Current read-only manual-coverage identities: `by-memory/-coverage-report.md` SHA `BB5E391E0198251142EC7BA4907D524E9ABCC80A5A2DFB0EBA53CE3F93802E20`; `by-global/-coverage-report.md` SHA `C8402BC1CF8E639E7A9F75BC94BD9A7F0F17010E1E4FB363775C643440A32D89`; `by-file/-coverage-report.md` SHA `BDB85AA42D17E235E4C449A520DA2120D609247F0690ADC708B30121E995C83E`; `by-class/-coverage-report.md` SHA `EB1ADFEAD1D3702137748D16942EF1AA2A4A39637C24FB9EA1230172B2FA41C5`; `by-type/by-struct/-coverage-report.md` SHA `9522306D105A425C756E1D8F74633B07F4821F3766C2C69280ADEFF1C6FABFA7`. All seven payloads remain applicable in-place replacements with exact current anchors: UID00027J after UID00027I/before UID00027K; UID0000PW between UID0000PV/UID0000PX; UID0000OB between UID0000OA/UID0000OC; UID0000D9 between UID0000D8/UID0000DA; UID0001W5 between UID0001W4/UID0001W6; UID0000W9 between UID0000W8/UID0000WA; UID00024F between UID0001O6/UID0001O7. None is an insert or no-op. These remain moving supervisor-owned files and require a final pre-application readback.
- Replace the UID00027J row in place after UID00027I and before UID00027K with exactly:

```text
    - [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md) 0x0066daec-0x0066db04 | static SimpleUString object | g_emptySimpleUString : reconstructable : 92% : very strong : Exact one-object 24-byte UTF-16 SSO-7 storage for the process-wide empty SimpleUString fallback: inline/heap union +0x00, length +0x10, capacity +0x14, loader bytes length 0/capacity 7, default-construction lowering through shared empty-wide count-zero assignment, paired static cleanup, complete field/whole-object xref families, hard predecessor/HourPane fences, external StringUtil linkage, non-duplicating UID0000PW emitter route, and bounded compatibility-UDT/IDA handoff.
```

- Replace the UID0000PW row in place between UID0000PV and UID0000PX with exactly:

```text
- [UID:0000PW][g_emptySimpleUString](by-global/g_emptySimpleUString.md) : reconstructable : 92% : very strong : Externally linked StringUtil-owned process-wide empty SimpleUString fallback with exact 24-byte UTF-16 SSO-7 storage, inline/heap union plus length/capacity fields, loader empty state, default construction lowered through shared L"" count-zero assignment, compiler-generated cleanup, metadata and non-metadata consumer spread, resolved StringUtil.cpp/.h placement, formal CPP definition plus H declaration, and non-duplicating storage child [UID:00027J][0x0066daec-0x0066db04.g_emptySimpleUString](by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md).
```

- Replace the UID0000OB row in place between UID0000OA and UID0000OC with exactly:

```text
- [UID:0000OB][StringUtil](by-file/StringUtil.md) : reconstructable : 90% : very strong : Shared utility-string module rooted at `NexusTK/util/StringUtil.cpp` plus `StringUtil.h`, with live IDA-backed SSO endpoint helpers, header-routed complete SimpleUString and extern g_emptySimpleUString declarations, CPP-routed global definition, SimpleUStringVector/StringIter coordination, pointer-backed StringBase boundary, exact static-lifetime source cause, source-facing SimpleUString versus 24-byte MSVC/Dinkumware-compatible SSO-7 ABI distinction, and preserved broader utility family evidence.
```

- Replace the UID0000D9 row in place between UID0000D8 and UID0000DA with exactly:

```text
- [UID:0000D9][SimpleUString](by-class/SimpleUString.md) : reconstructable : 90% : very strong : StringUtil-owned human source facade with a complete declaration routed through formal H, blank class CPP, exact 24-byte UTF-16 SSO-7 inline/heap union plus length/capacity, Clear/Assign/MutableData, default-constructor lowering proven by matching g_emptySimpleUString and g_metaAliasTableName startup patterns, exact static instance and cleanup evidence, pointer-backed StringBase exclusion, and documented MSVC/Dinkumware ABI compatibility without leaking raw library/decompiler names into project source.
```

- Replace the UID0001W5 row in place between UID0001W4 and UID0001W6 with exactly:

```text
- [UID:0001W5][SimpleUStringSso7Layout](by-type/by-struct/SimpleUStringSso7Layout.md) : reconstructable : 90% : very strong : Attached to [UID:0000D9][SimpleUString](by-class/SimpleUString.md); exact 24-byte UTF-16 SSO-7 ABI has inline wchar[8]/heap-pointer union +0x00, unsigned length +0x10, unsigned capacity +0x14, threshold seven, counted assign/clear/growth semantics, concrete g_emptySimpleUString loader/runtime/cleanup proof, 24-byte consumer stride, and explicit separation from both the size-4 current IDA SimpleUString UDT and pointer-backed StringBase family.
```

- Replace the UID0000W9 row in place between UID0000W8 and UID0000WA with exactly:

```text
    - [UID:0000W9][0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle](by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md) : ignored : 80% : strong : Compiler startup-wrapper island; exact child 0x00419f20 lowers g_emptySimpleUString default construction through shared L"" count-zero assignment to the 24-byte SSO-7 object and registers the paired 0x0060c100 cleanup through atexit. Regenerate from the bare source-level global and do not emit the wrapper as handwritten source.
```

- Replace the UID00024F row in place between UID0001O6 and UID0001O7 with exactly:

```text
    - [UID:00024F][0x0060c100-0x0060c260.StaticStringContainerCleanupThunks](by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md) 0x0060c100-0x0060c260 | compiler-generated static cleanup | StaticStringContainerCleanupThunks : ignored : 75% : strong : Compiler static string/container cleanup island; exact child 0x0060c100 conditionally frees g_emptySimpleUString heap storage, validates large aligned allocation state, and restores inline NUL, length 0, and capacity 7. Source ownership belongs to the StringUtil global, not this emitted thunk body.
```

- The tracker is validator-owned. Do not manually edit its UID00027J row; refresh it after ordinary docs, supervisor IDA reconciliation, manual coverage, and generated closure.
- B004 must not apply any listed manual row. The supervisor owns these collision-prone files after accepting and verifying the implementation.

## Follow-Up Actions

- Historical completed callback steps: the supervisor passed Gate 1 on frozen SHA `FE23B827...775E`, B004 implemented and serially validated all seven accepted ordinary destinations, and the supervisor applied/read back/saved IDA-27J-001 through IDA-27J-012 as catalog entry `0360`.
- Current supervisor work: fresh Gate 1 on this reconciled report, Gate 2A claim-by-claim verification of the seven ordinary pages, and Gate 2B confirmation that the current authoritative `412DA7E8...519CD` no-drift state still matches catalog0360. No repeated IDA mutation is proposed.
- Supervisor closure after both gates: apply the seven exact manual coverage replacements against then-current anchors, confirm command19483 generated/tracker artifacts remain current or refresh them only if later drift requires it, and alone handle validator-owned report execution/archive state.
- A-agent actions: none.
- B004 future actions: only an exact-defect repair or reconciliation callback for this same report; do not start a new target while it is active.

## Confidence

- Recommendation confidence: `94/100` for behavior/layout/lifetime/owner route; `91/100` for source placement/linkage; `88/100` for exact source lexical spelling.
- Score confidence: strong. Recommended values are below 95 because original symbols/source are absent and broader string-family aliasing remains outside scope.
- Remaining uncertainty is bounded to historical spelling/file organization, not object behavior, source eligibility, or safe implementation direction.

## Validator Results

- Initial accepted-callback scoped commands, all with `--apply --queue-timeout 240 --no-generated-refresh`, returned exit `0` and `ok: 1`: command19277 target, command19281 global, command19282 target final pass, command19283 StringUtil file, command19287 SimpleUString class, command19299 layout, command19300 initializer aggregate, and command19301 cleanup aggregate.
- Final currentness-reconciliation scoped commands, all with the same flags, returned exit `0` and `ok: 1`: command19427 target (`2026-07-29T14:26:27-04:00`), command19432 global (`14:26:58`), command19435 StringUtil file (`14:27:29`), command19439 SimpleUString class (`14:28:00`), command19455 layout (`14:28:31`), command19459 initializer aggregate (`14:29:01`), and command19473 cleanup aggregate (`14:29:35`).
- Known unrelated warnings persisted: five missing UID0003MS references in StringUtil, one missing UID0003GZ reference in SimpleUString, and four missing UID0003MS references in the cleanup aggregate. Every command still returned `ok: 1`; no target-specific warning or error occurred.
- Every scoped command reported `generated_refresh: skipped` because `--no-generated-refresh` was binding. Validator-owned projected completion-stat sections were updated as reported side effects. A separate validator foreground refresh, command19483, subsequently produced current StringUtil.cpp, newly nonempty StringUtil.h, and the tracker `92/94` row; command19259 remains the explicit stale pre-callback checkpoint.

## Changed Files

- Modified: `by-memory/0x0066daec-0x0066db04.g_emptySimpleUString.md` SHA256 `6DD260F78519060EFDC3B8E4E19B74355F9F72EBD3D2D0E4890BC70C5575CB47`; `by-global/g_emptySimpleUString.md` SHA256 `9F40B27492B2B5144FE0F342DC71877C112A925B72DD941EED4BDC98CE1B61E6`; `by-file/StringUtil.md` SHA256 `308E8098D7231ACF978ED09E4EF3CBC4BD1ACE49079B815A3BC1BF0D68BD8653`; `by-class/SimpleUString.md` SHA256 `1481FCB762336F47CC21C14944A4EE025E522970E75A34F9860F993796035B13`; `by-type/by-struct/SimpleUStringSso7Layout.md` SHA256 `68D7F75A7530124D72B607FF48D3D28E7E1A95C751B87BA794258053821B9995`; `by-memory/0x00419ef4-0x00419f70.StaticInitializerWrappersAfterOle.md` SHA256 `D5E67BC86D8B3F72E79A6902F9CD3DA0346884B5E404C27A4AAF17205BE79D2A`; `by-memory/0x0060c100-0x0060c260.StaticStringContainerCleanupThunks.md` SHA256 `751D1D1F447AF96740D44C224E2D97C0335FADBB97A808E1472204DBBE5DEB00`; and this same report.
- Created: none during callback implementation.
- Renamed: none.
- Historical report-only action boundary: B004 created the initial report without ordinary-document or IDA mutation. During the accepted callback B004 edited only the seven authorized ordinary pages plus this report, used scoped validators, and made no IDA mutation. B004 did not edit manual coverage, generated, audit, catalog, lifecycle, goal, or notes files and did not run/probe `execute_report`. Current execution/archive state is authoritative only from the artifact's actual path plus validator-owned status/history metadata.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted frozen report SHA `FE23B827FF83155B7ADFF59FC235FFFE2D86E57320D4D29A392057399064775E` before implementation; this reconciled artifact requires a fresh supervisor Gate 1.
- [x] Report-only destination plan completed and callback applied: UID00027J, UID0000PW, UID0000OB, UID0000D9, UID0001W5, UID0000W9, and UID00024F received the accepted details; UID0000D9's complete declaration is now in formal H with blank CPP.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; there are no additional target UIDs.
- [x] Current target state and actual evidence checked are recorded with exact report-time identities and bounded historical/current distinctions.
- [x] Claim And Incorporation Ledger remains 57 contiguous atomic claims; C01-C49 use allowed callback states (`applied`, `already-present`, or `excluded-with-reason`), supervisor-owned manual rows C50-C56 remain `proposed`, and current generated/tracker row C57 is `already-present` from command19483.
- [x] Metadata/score plan completed: UID00027J 92/94, UID0000PW 92/93, UID0000OB 90/91, UID0000D9 90/92, UID0001W5 90/93; wrapper aggregates retain scores.
- [x] Score-limiting blockers researched to resolution: exact fields/type/lifetime/linkage/source placement/formal code are resolved; only lexical proof remains as a bounded cap.
- [x] Owner/emitter/reconstructable research completed: no route change is recommended, and the existing routes are documented for callback verification.
- [x] Range/split/new-child planning completed: no documentation split or new child is needed; the report separately hands off supervisor-owned IDA consolidation of the current dword pieces into one object plus target/wrapper renames.
- [x] Source placement, range/padding/reclassification, and IDA recommendation planning completed with exact implementation-ready actions; this check records report preparation only and does not mark any IDA action applied.
- [x] Supervisor Gate 2B applied/read back IDA-27J-001..012 as catalog0360, preserving exact `void __cdecl()` cleanup presentation with no type mutation; bounded read-only currentness recheck under authoritative `412DA7E8...519CD` found no target/dependency drift, and `905D1AB1...604C1` plus `296ED21C...63CF8B` are historical.
- [x] First-draft CPP/H planning completed: target no-duplicate CPP comment and blank H; UID0000PW bare definition in CPP and extern declaration in H; UID0000D9 blank CPP with exact no-implementation proof and complete class declaration in H. Physical incorporation is separately tracked under the implementation callback pass.
- [x] Third-party import disposition completed: not applicable because this is project-owned source.
- [x] Exact target/support documentation facts are enumerated at report-level detail for later accepted callback incorporation.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are identified with exact preservation requirements.
- [x] Wave2/Wave3 mentions encountered in older material were explicitly ignored/rejected as stale.
- [x] Open questions were investigated to deterministic implementation directions or documented as bounded lexical uncertainty that does not defer source/IDA action.
- [x] Serial scoped validators ran for every changed ordinary page using `--apply --queue-timeout 240 --no-generated-refresh`; all current final passes returned exit `0`, `ok: 1`, and skipped generated refresh.
- [x] Report-only manual coverage preparation completed: seven exact replacement payloads, current row anchors, and frozen manual-file identities are supplied; this check does not mark any manual row applied.
- [ ] Supervisor-owned manual coverage application and execution/archive handling must be established from then-current files and validator-owned status/history metadata; command19483 generated/tracker currentness is separately observed below, and this agent checklist does not assert completion of the remaining supervisor-owned operations.

Implementation callback pass:
- [x] Supervisor closed each accepted IDA recommendation during Gate 2B as catalog0360; B004 made no IDA mutation, and current authoritative `412DA7E8...519CD` readback remains no-drift; `905D1AB1...604C1` and `296ED21C...63CF8B` are historical.
- [x] Report was accepted by the supervisor for this implementation callback at frozen SHA `FE23B827...775E`.
- [x] All accepted target/support document details were incorporated at report-level detail into the seven authorized ordinary pages.
- [ ] Fresh independent supervisor Gate 2A verification of primary UID00027J and each support UID remains required against the current hashes above; B004 completed claim-by-claim self-verification without treating supports as additional report targets.
- [x] Claim And Incorporation Ledger was updated to allowed exact callback states for C01-C49; supervisor-owned manual rows C50-C56 remain `proposed`, while generated/tracker currentness C57 is `already-present` from command19483.
- [x] Metadata/score/owner/emitter/split/rename/CPP/H changes were applied or explicitly retained with reason, including target no-duplicate CPP/blank H, global bare CPP/extern H, and class blank CPP/complete H.
- [x] Historical/stale assumptions, rejected alternatives, negative evidence, and automatic intermediate `stru_66DAEC` state were preserved and labeled.
- [x] Open questions remain resolved or bounded as lexical uncertainty that does not block source or IDA state.
- [x] Validators ran serially and exact current command IDs/results/hashes are recorded above.
- [x] Current generated CPP/H and tracker were refreshed by validator command19483 after the ordinary callback: StringUtil.cpp contains the UID0000PW definition, StringUtil.h contains UID0000D9 plus UID0000PW declarations, and the tracker records UID00027J at `92/94`; command19259 and command19221 remain dated historical evidence. This records observed validator-owned current state and does not assert report execution/archive completion.
- [x] Remaining unapplied work is exhaustively listed: fresh supervisor Gate 1/Gate 2 review, C50-C56 manual coverage replacements, and supervisor-owned execution/archive handling. No accepted ordinary-document, IDA, or generated-source action remains unapplied.

READY_FOR_SUPERVISOR_GATE2_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000019716","destination_path":"executed-b-agent-research/B004/00027J-g_emptySimpleUString-storage-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00027J-g_emptySimpleUString-storage-source-quality.md","timestamp":"2026-07-29T15:20:09-04:00","uid":"00027J"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
