# UID0000KK LanguageMan Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000KK **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **


## Finalized Report / Current Recommendation

- Current recommendation: retain the now-implemented UID0000KK single `NexusTK/localization/LanguageMan.cpp` compilation-unit owner and do not create a second `LanguageManager` module.
- Final disposition: the accepted callback implemented the exact class header, recursive include/child assembly route, file constants/literals, singleton definition/specializations, constructor, destructor, pointer lookup, and by-value `StringBase<wchar_t>` lookup described below. The adjacent zero initializer remains file-owned but class-excluded and non-emitting; EH cleanup, scalar deleting destructor, vtable, RTTI, padding, and backing storage remain compiler/data-only.
- Remaining externally owned scope: C047-C063 and C065 remain supervisor-owned, and their disposition is authoritative only from external supervisor audit and validator lifecycle state. B005-owned C001-C046, C064, and C066-C071 are implemented and physically validated; this report performs none of the remaining supervisor-owned work.
- Confidence: `96/100` overall. Runtime behavior, ranges, class identity, singleton lowering, copy-result ABI, and file inventory are direct or strongly corroborated. Remaining caps concern original private lexical spellings and whether the two retained `0x400` dwords were named constants in the original translation unit.

## Supporting Research

- Historical research-phase statement: this artifact began as a report-only UID0000KK investigation with no implementation or validator claim. The accepted callback now records B005-owned ordinary-document implementation and validator-generated readback only; it still contains no B005 IDA mutation, manual coverage edit, lifecycle, execution, or archive claim.
- The report is lifecycle-neutral: its current authority is its path plus any validator-owned status/history metadata that may later be added. Gate, callback, execution, invalidation, and archive truth are external to the prose.
- Historical report-time snapshot at `2026-08-24T06:47Z`: read-only IDA MCP session `supervisor_uid0000jr_canonical_verify_20260824_064700` used exact path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; its physical receipt was SHA256 `43A4BEAC940C47FF2B4136C278E1DB6F70E6C7F4ACE31C9FD5B76F8B627F47D7`, 143,211,656 bytes, last-write `2026-08-24T06:41:59.9312987Z`. This dated path/hash/session proves only the report-time prestate and is not present authority. The supervisor must dynamically re-establish current canonical path/hash/session authority at each gate.
- In that historical snapshot, public `runtime_attestation` at `2026-08-24T06:47:29.717738Z` returned schema `1`, `ok:true`, exact expected session/path match, listener PID `3612` parent `17668` at `127.0.0.1:13337`, listener manifest `D3C792133956B855EBA751FDB5783B2D7177FA204134CFF1D897E0D0770FB7CE`, redirector PID `11108`, and stateful worker PID `27396` parent `11108` at `127.0.0.1:54235`. Worker attestation at `2026-08-24T06:47:29.834345Z` returned `ok:true` and manifest `2E883F9025B9811708B812077B7194021F72F741508E32BEEA1A491A59B23C00`; attestation errors were empty. These process receipts are historical evidence, not current runtime authority.
- Historical authority note: session `supervisor_canonical_research_20260824_0503` and every earlier physical-IDB receipt, including the superseded `6327...E1B7` family, predate the failed review and are not current authority. Their bounded research conclusions were rechecked against the then-current dated `2026-08-24T06:47Z` snapshot above; that recheck is also historical evidence rather than present gate authority.
- `server_health` returned `status: ok`, module `NexusTK.exe`, image base `0x00400000`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, Hex-Rays available, and 2,067 strings ready. `auto_analysis_ready:false` was recorded, but every bounded function, byte, item, xref, type, RTTI, and comment query used by this report completed successfully and consistently; no mutation or process-management operation was attempted.
- Historical Wave2/Wave3 names, generated alias files, and stale exporter grades were treated as leads only. No Wave2/Wave3 artifact was used as current authority.

## Target

- Target UID: `0000KK`.
- Additional target UIDs: none.
- Declared target: `by-file/LanguageMan.md`, now a reconstructable file page scored `94/94`, owner/source path `NexusTK/localization/`.
- Inferred compilation-unit boundary: one authored `LanguageMan.cpp` plus its `LanguageMan.h`, covering the `LanguageMan` direct-base class, `g_pLanguageMan` and its `Singleton<LanguageMan>` specializations, parser constants, three UTF-16 literals, constructor/destructor, raw-pointer lookup, and by-value string lookup. Exact executable membership is `[0x004f0010,0x004f0477)` with explicit padding gaps; exact LanguageMan read-only data is `[0x0061c9d4,0x0061ca44)` after exclusion of KeySpeedMgr `[0x0061c9c4,0x0061c9d4)`; backing storage is `[0x0067a750,0x0067a754)`; source resource is `str.res`.
- Boundary proof: contiguous executable ordering, vtable stores, direct class RTTI, constructor/destructor field access, shared fallback literal use, global singleton lifetime accesses, parent split pages, source-tree placement, and current generated routing all converge on this unit. The neighboring KeySpeedMgr and Layer ranges are explicitly excluded.

## Current Target State

- Current target document state: `COMPLETION:94` and `CONFIDENCE:94`. A by-file page has no literal `RECONSTRUCTABLE` metadata key; semantic reconstructability is the current prose/coverage disposition. Its reconstruction-path metadata contains `NexusTK/localization/`, and the physical command-`000000027614` CPP/H readback proves that route is implemented rather than merely proposed.
- Current owner/emitter state is complete: UID000071 remains canonically owned by UID0000KK and is the sole direct CPP assembly parent at position `0`; its explicit recursive marker orders UID0000RC/UID00040V/UID00040X and the four authored methods at positions `10` through `70`. Canonical ownership remains UID0000KK for file-local data/global and UID000071 for methods. Compiler artifacts and UID00018T are non-emitting with no empty markers.
- Current formal source is coherent: includes precede the global and file-local data; constructor source uses `DATFile::GetPosition()` and `memoryMan->MemmoveWrapper`; UID00040Q emits by-value source; no stale `Tell`, free `MemmoveWrapper`, source `GetString`, `g_pStringTable`, duplicate body, empty marker, or placeholder remains in generated LanguageMan output.
- Current `LanguageMan.h` exposes the one-pointer `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >` return by value and retains the complete guarded direct-base `0x2c` declaration. The machine-level explicit pointer remains documented only as hidden-result ABI lowering.
- The private tail remains `unsigned int m_reservedState[8]`. Live evidence does not establish field semantics or attach UID00018T to this class; retaining neutral ABI-preserving storage is stronger than inventing seven or eight fields.
- Current validator-owned generated authority for this revision is command `000000027614`, timestamp `2026-08-24T07:26:44-04:00`: `auto-generated/NexusTK/localization/LanguageMan.cpp` SHA256 `400C108A0C509BD36FB42A6A16F76A18F8F26E6006CEE3ABA3C0ED6D99EB04BA`, 4,868 bytes, 145 LF, 0 CRLF, eight exact ordered UID fragments `000071,0000RC,00040V,00040X,00041V,00018S,00040P,00040Q`, and zero placeholders/empty markers; `LanguageMan.h` SHA256 `6C462978AEAE39C31AC2CA8FBC1F90D097B02C0B96BBE19359E07CB89859A92F`, 1,097 bytes, 37 LF, 0 CRLF, one complete UID000071 fragment, and zero placeholders. CPP contains the sole UID0000RC definition and H contains the matching UID000071 extern declaration. Both files were physically reread without direct editing.
- Commands `000000027320` and `000000027382` remain historical pre-callback receipts only. Historical accepted-callback command `000000027513`, timestamp `2026-08-24T04:21:21-04:00`, superseded them and resolved every semantic/output defect recorded in those dated snapshots. Historical read-only command `000000027608`, timestamp `2026-08-24T06:10:10-04:00`, preserved the complete output before C072; current validator command `000000027614` supersedes its metadata receipt without semantic change.
- Complete current inventory: seven functions, seven exact executable padding gaps/boundaries, two parser dwords, one four-entry vtable region including COL, three UTF-16 literals, one singleton pointer/backing object, two direct RTTI names plus hierarchy descriptors, one resource, two aggregate/index pages, and two class identities (one canonical, one rejected alias). Section 14 gives every item a source/no-code, owner, emitter, metadata, and output disposition.
- Current report state is the completed ordinary callback artifact. External supervisor audit and validator-owned metadata exclusively establish all later gate, execution, and archive state; report prose and status messages establish none of them.

## Executive Recommendation

- Keep UID0000KK and UID000071 as the direct file/class pair. `LanguageManager` is only a historical/generated alias: live RTTI contains `LanguageMan` and `Singleton<LanguageMan>` but no `LanguageManager` type, allocation, vtable, or destructor identity.
- Preserve the implemented recursive source order: UID000071 include preamble/direct file route at `0`; under its explicit child anchor, UID0000RC singleton definition/specializations at `10`; UID00040V constants at `20`; UID00040X literals at `30`; UID00041V constructor at `40`; UID00018S destructor at `50`; UID00040P raw lookup at `60`; UID00040Q by-value lookup at `70`.
- Keep UID00018T owned by UID0000KK because exact source/linker adjacency makes this the strongest file candidate, but keep it outside UID000071 and remove its emitter. Its seven stores are real custom code, yet zero callers, pointers, vtable routes, EH routes, globals, strings, and type evidence leave no safe source-facing function or object type.
- Keep UID00040R, UID00018V, UID00040W, RTTI, and all `0xCC` gaps compiler-generated/no-code. Do not synthesize a clear helper, deleting destructor, vtable definition, or padding source.
- No blocker remains for coherent C++ after the by-value `StringBase` correction and singleton specializations. Original private lexical names remain confidence caps, not implementation blockers.

## Supervisor Active Recheck

- Historical trigger: the supervisor originally assigned a report-only whole-file investigation of UID0000KK with mandatory read-only IDA MCP evidence, complete source inventory, blocker resolution, exact report/checklist twins, and no ordinary implementation before acceptance. That restriction governed the research phase only; the later accepted callback implemented the B005-owned rows and is now part of this artifact's current state.
- Historical repair-cycle note: no split repair was required because exact children already partition every executable and read-only-data subrange. The accepted callback completed the source-quality reconciliation, emitter/order repair, and stale KeySpeedMgr child-range correction; the bounded additive Gate 1 repair that produced this revision corrected only report-state/inventory wording while preserving that research and implementation.
- Every source-bearing child has a precise disposition: UID00041V/UID00018S/UID00040P retain repaired source; UID00040Q gains exact source; UID00040V/UID00040X retain source with order; UID0000RC gains specializations; UID000071 supplies includes/header; UID00018T remains intentionally non-emitting after exhaustive negative closure. Compiler children remain exact no-code.

## Inference Research Guidance Check

- The project inference discipline permits strongest human source reconstruction without claiming original spelling. Direct binary facts are separated from documentation and source-shape inference throughout.
- Existing assumptions rechecked as uncertain were `LanguageManager` ownership, explicit-output `CopyLocalizedString`, `sub_582560` as assignment, `SimpleUString`/`std::wstring` as the result type, handwritten singleton writes, UID00018T as a possible class initializer, and stored parser dwords as address-used constants.
- Direct facts: ranges, bytes, field offsets, calls, xrefs, string storage, stack result lifetime, RTTI/PMD, vtable slots, global accesses, and comments. Documentation evidence: accepted `StringBase`/`Singleton` formal APIs, class layout, generated output, source tree, and by-* parent routes. Inference: human names, private reserved tail, constant naming, and the translation-unit source order.
- Historical Wave2/Wave3 mentions were found in UID0000KK and exporter context and ignored as stale. No current override authorizes their generated owner/name conclusions.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis and evidence | Final disposition |
| --- | --- | --- |
| `LanguageMan` versus `LanguageManager` | Live RTTI strings are `.?AVLanguageMan@@` and `.?AV?$Singleton@VLanguageMan@@@@`; hierarchy has LanguageMan, LObject, Singleton. No `LanguageManager` RTTI/type/vtable/allocation was found. | Canonical class/file is `LanguageMan`; keep UID000072 ignored and reject a compatibility alias or second source file. |
| UID00040Q output type/API | Both callers allocate an uninitialized one-dword stack object, call `0x004f0380`, then use `c_str` and destroy it. Callee `0x00582560` allocates from raw UTF-16 and never releases old storage. Current canonical StringBase is one pointer; canonical SimpleUString is a separate 24-byte SSO object. | Source is by-value `StringBase<wchar_t,...> CopyLocalizedString(int) const`; IDA may expose the hidden result pointer. Reject explicit output, assignment, `std::wstring`, and SimpleUString. |
| Singleton writes/clears | RTTI PMD for direct `Singleton<LanguageMan>` base is `{mdisp=4,pdisp=-1,vdisp=0}`. Constructor `this+4/-4` publication and destructor/EH/wrapper clears match compiler lowering. Existing accepted singleton pattern uses class-specific specializations beside each global. | Put specialization bodies beside `g_pLanguageMan`; omit explicit singleton writes from LanguageMan ctor/dtor source. |
| UID00018T ownership | Seven descending dword zero stores at `+0x24..+0x0c`, bounded in the LanguageMan executable island. No callers, xrefs, pointers, strings, globals, vtable, EH, or type route. Offsets do not match proven LanguageMan initialization and the constructor already allocates exactly `0x2c`. | Retain UID0000KK file-context owner only; exclude UID000071; blank emitter and formal CPP/H; preserve custom-code reconstructable status without invented function/class. |
| Parser dwords | Exact stored values are two `1024` dwords at `0x0061c9d4/0x0061c9d8`, with zero direct xrefs. Constructor independently uses immediate `0x400` for byte cap, conversion cap, and count cap. | Keep two descriptive file-local constants with confidence cap; do not claim stored addresses are loaded at runtime. |
| Source order/buildability | Pre-callback generated source put the global and methods before constants, lacked includes, and used undeclared symbols before definition. Current command `000000027614` physically contains the complete corrected sequence. | Implemented through UID000071's include fragment and recursive child anchor with positions `10` through `70`; preserve that exact order. |
| Raw helper names | `GetPosition`, `MemoryMan::MemmoveWrapper`, `InitializeWideFromRaw`, `GetMemoryMan`, and `FreeBufferMemory` are established by current support docs/formals and exact consumers. | Replace stale `Tell` and free-function spelling; update StringBase support to constructor/initializer terminology. |
| Tail class layout | `sizeof(LanguageMan)==0x2c`; known fields end at `+0x0c`, but no safe semantic names exist for remaining eight dwords. | Preserve `m_reservedState[8]`; do not map UID00018T stores to those fields. |
| Compiler/source boundaries | EH helper is metadata-only referenced, scalar wrapper is vtable-only, vtable/COL/RTTI are declaration-generated, and padding has no source semantics. | No formal bodies or empty emitters for compiler artifacts. |
| Stale lookup call spelling | Callback formal-block audit finds 18 canonical calls across C030-C045 destinations plus all 13 UID0003V9 calls, for 31 `g_pLanguageMan->GetLocalizedString` occurrences across the 17 source pages. It finds zero stale source aliases; six support pages are also normalized. | Implemented without a compatibility alias; the only remaining `LanguageMan::GetString` text in the accepted destination set is explicitly historical rejection prose. |

Rejected alternatives were a new LanguageManager module, a compatibility `GetString` wrapper, `std::wstring`, 24-byte `SimpleUString`, explicit singleton assignments in LanguageMan methods, attachment of UID00018T to the class, a handwritten singleton-clear helper, direct generated-file edits, and direct vtable/RTTI definitions. Each either contradicts live layout/ABI or duplicates compiler behavior.

No material research question remains unresolved. The exact original names of `CopyLocalizedString`, the two constants, and private tail members are not symbol-proven; the chosen names are descriptive, internally consistent, and behavior-preserving, while score caps prevent overclaiming original lexical recovery.

## Evidence Standards Used

- Primary evidence: live bounded IDA MCP function lookup/decompile/disassembly, exact bytes/items, comments, stack variables, callers/callees/xrefs, string refs, vtable pointers, UDT sizes, RTTI descriptors, PMD values, allocation size, and negative searches.
- Secondary evidence: current by-file/class/memory/global/resource/type docs, accepted StringBase and Singleton patterns, current generated CPP/H, manual coverage, source-tree placement, and matching executed/active report searches.
- Evidence ladder: direct bytes/control flow and ABI outrank decompiler labels; RTTI/vtable/global routes establish class identity; repeated caller lifetime patterns establish hidden-result construction; source documentation supplies human API spelling only where consistent with binary facts.
- Tool limitation: analysis-ready was false in health output, so no global "analysis complete" claim is made. Every conclusion is instead tied to successful bounded queries and cross-checked raw bytes/items. This lowers no behavior conclusion because all relevant ranges were decoded and reconciled.

## Evidence Checked

- Historical rotated-authority recheck at `2026-08-24T06:47Z`: `idb_list`, fail-closed public `runtime_attestation`, `server_health`, `lookup_funcs` for all seven LanguageMan bodies plus Layer successor, bounded `get_bytes` for every gap/copy body/data/global span, `inspect_items` and `get_comments` for every Section 21 action/protection entity, `xrefs_to(0x004f0380)`, `stack_frame(0x004f0380)`, `type_inspect(StringBaseWide)`, and exact desired-name `list_funcs` collision lookup all ran read-only on session `supervisor_uid0000jr_canonical_verify_20260824_064700`. Results match the preserved research as a dated snapshot; current gate authority and prestates must be freshly established by the supervisor.
- Live MCP bounded functions: `0x004f0010`, `0x004f0290`, `0x004f0310`, `0x004f0350`, `0x004f0380`, `0x004f03c0`, `0x004f03d0`, successor `0x004f0480`, copy callers `0x00530c27` and `0x005c08a2`, raw initializer `0x00582560`, and startup allocation/call route around `0x004640ed/0x00464108`.
- Live bytes/items: every executable body and all seven adjacent `0xCC` gaps; `[0x0061c9d4,0x0061ca44)`; `[0x0067a750,0x0067a754)`; vtable pointer values; three UTF-16 items; stack arguments at UID00040Q; current names/types/comments for all Gate 2B entities.
- Live xrefs: all code/data refs to seven functions, two parser dwords, vtable/COL slots, literals, and singleton global. UID00040P has 351 direct call xrefs; UID00040Q exactly two; UID00041V one; UID00018T/UID00018S no direct callers; UID00040R one EH metadata ref; UID00018V one vtable ref; global has 192 total data-typed xrefs, documented as five writes/clears and 187 reads.
- Types/RTTI: incomplete IDA `LanguageMan`; one-pointer `StringBaseWide`; rejected four-byte IDA `SimpleUString` artifact versus current 24-byte project source; LanguageMan/Singleton RTTI strings, hierarchy count three, direct Singleton PMD, and absence of LanguageManager identities.
- Documentation: UID0000KK, UID000071/000072, UID00018R/18S/18T/18U/18V, UID00040P/Q/R/V/W/X, UID00041V, UID0000RC, UID0001OS, UID0001RP, UID00025M, UID00031P, StringBase/Singleton support, both copy callers and parent file pages, all stale GetString/g_pStringTable formal pages, manual coverage rows, proposed source tree, and generated LanguageMan CPP/H.
- Report searches used target UID, `LanguageMan`, `LanguageManager`, exact function addresses, `CopyLocalizedString`, `sub_582560`, `InitializeWideFromRaw`, `Singleton<LanguageMan>`, `g_pLanguageMan`, and stale aliases. Historical non-executed material was treated only as a lead.
- Negative checks: no LanguageManager RTTI/type/vtable/allocation; no UID00018T caller/pointer/EH/vtable/global/string/type route; no parser-dword address xrefs; no UID00040P callees; no extra functions inside the executable island; no copy-helper prior-value release; no current source contract for `GetString` or `g_pStringTable`.
- Historical research-phase exclusions: IDA mutation/save/process control, ordinary-document edits, validators, generated refresh, manual coverage, lifecycle, archive, and execution were prohibited before acceptance. The later accepted callback changed 52 ordinary documents and invoked validator-owned generation; IDA, manual coverage, Gate 2, lifecycle, execution, and archive remained supervisor-owned. This bounded repair edits only the report.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---:|---|---|---|---|
| C0000KK-001 | 0000KK | LanguageMan is one localization compilation unit whose complete source/data/resource/compiler inventory and ordered emitter plan are Sections 14/22 | 99 | Live whole-file inventory plus generated CPP/H | `by-file/LanguageMan.md` all sections/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-002 | 000071 | LanguageMan is the canonical direct LObject and Singleton class; its CPP fragment supplies includes and its H fragment returns StringBase by value while preserving 0x2c layout | 99 | RTTI/PMD, allocation size, formal header, copy ABI | `by-class/LanguageMan.md` formal CPP/H and prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-003 | 000072 | LanguageManager is a rejected historical/generated alias with no live RTTI/type/vtable/allocation or source emitter | 100 | Live negative RTTI/type/allocation searches | `by-class/LanguageManager.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-004 | 000072 | The ignored-class index must preserve LanguageManager only as search context and point to canonical LanguageMan | 100 | Canonical alias disposition | `by-class/-ignored.md` UID000072 row | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-005 | 00018R | The executable island remains a non-emitting exact split index over seven functions and all padding; no aggregate C++ or empty marker | 100 | Live bounds/items/function inventory | UID00018R aggregate | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-006 | 00041V | Constructor source keeps complete parser behavior but uses DATFile::GetPosition and memoryMan->MemmoveWrapper and emits at position 40 | 99 | Exact decompile plus current support APIs | UID00041V formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-007 | 00018S | Destructor remains authored string/table release only; Singleton clear and LObject teardown are compiler lowering; emit at position 50 | 100 | Exact decompile, RTTI/PMD, helper identities | UID00018S formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-008 | 00018T | Seven-store zero initializer remains UID0000KK file-context owned, UID000071-excluded, reconstructable but non-emitting with blank emitter and no invented source type/name | 98 | Exact body plus exhaustive zero-route evidence | UID00018T metadata/prose/blank CPP/H | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-009 | 00018U | Lookup/singleton aggregate remains non-emitting exact split index and records final child source/compiler dispositions | 100 | Exact child inventory | UID00018U aggregate | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-010 | 00040P | GetLocalizedString is exact signed bounds-check pointer lookup using kInvalidStringIdText and emits at position 60 | 100 | 34-byte body, 351 calls, zero callees | UID00040P formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-011 | 00040Q | CopyLocalizedString returns one-pointer mystr::StringBase<wchar_t,...> by value; assign UID000071 emitter and position 70 | 99 | Hidden-result callers plus InitializeWideFromRaw | UID00040Q formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-012 | 00040R | 0x004f03c0 is compiler EH Singleton clear only and must remain blank/non-emitting | 100 | Sole EH metadata xref and body | UID00040R | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| C0000KK-013 | 00018V | 0x004f03d0 is compiler scalar deleting destructor only and must remain blank/non-emitting | 100 | Sole vtable route, delete flags, duplicated cleanup | UID00018V | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| C0000KK-014 | 00040V | Two inferred 1024 parser constants remain file-local source with no runtime address-use claim and emit at position 20 | 95 | Exact dwords, zero xrefs, three immediates | UID00040V formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-015 | 00040W | LanguageMan COL/vtable region is declaration-generated compiler data and emits no formal source or marker | 100 | Exact four pointer cells and vtable routes | UID00040W | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| C0000KK-016 | 00040X | str.res, Too many strings, and Invalid String ID are file-local UTF-16 literals emitted at position 30 | 100 | Exact strings and four code refs | UID00040X formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-017 | 0000RC | g_pLanguageMan definition plus class-specific Singleton constructor/destructor specializations emit at position 10 | 99 | PMD lowering and accepted singleton pattern | `by-global/g_pLanguageMan.md` formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-018 | 0001OS | 0x0067a750 is the four-byte backing storage for the sole g_pLanguageMan definition, not a second emitted global | 100 | Exact type/bytes/192 xrefs | UID0001OS | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-019 | 0001RP | str.res remains the parser resource: byte lines, CR/LF handling, 0x11 remap, CP0 conversion, 1024 caps | 99 | Constructor behavior and literal ref | `by-resource/str-res-localized-strings.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-020 | 00025M | Mixed KeySpeedMgr/LanguageMan rdata parent remains an ignored split index with exact child boundary 0x0061c9d4 | 100 | Exact bytes/locators/children | UID00025M | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-021 | 00031P | KeySpeedMgr vtable child ends at 0x0061c9d4, not 0x0061c9dc; LanguageMan parser dwords are excluded | 100 | Live item boundary and successor role | UID00031P | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-022 | 0000OA | StringBase docs must classify 0x00582560 as raw UTF-16 constructor/initializer, not assignment/copy | 100 | Callee allocates and never releases prior storage | `by-file/StringBase.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-023 | 0001WS | StringBase template support should add UID00040Q as a by-value hidden-result consumer of InitializeWideFromRaw | 99 | Two exact caller lifetimes and type size | `by-type/by-template/StringBaseTemplate.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-024 | 0004ZK | Singleton docs should add LanguageMan class-specific specialization and compiler-lowering example | 99 | PMD plus accepted g_pMiscWorkThread pattern | `by-file/Singleton.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-025 | 0004ZL | Singleton template support should add LanguageMan direct-base publication/clear route and null-preserving adjustment | 99 | RTTI hierarchy and machine lowering | `by-type/by-template/SingletonTemplate.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-026 | 0001CY | NumberInput caller should initialize a const StringBase from CopyLocalizedString by value before c_str use | 100 | Caller stack lifetime at 0x00530c27 | UID0001CY formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-027 | 0000M1 | NumberInputDialog file inventory should record corrected LanguageMan by-value dependency | 99 | UID0001CY route | `by-file/NumberInputDialog.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-028 | 0001NV | Virus scan caller should initialize canonical StringBase by value instead of a SimpleUString output object | 100 | Caller stack lifetime at 0x005c08a2 | UID0001NV formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-029 | 0000P5 | VirusChecker file inventory should record corrected LanguageMan/StringBase dependency | 99 | UID0001NV route | `by-file/VirusChecker.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-030 | 000331 | BrowserInvoke source must replace LanguageMan::GetString(235) with g_pLanguageMan->GetLocalizedString(235) | 100 | Canonical current header/global | UID000331 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-031 | 0001ER | PatchPane packet source must normalize localized lookup 176 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0001ER formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-032 | 00046E | CreateUser constructor body-shape source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00046E formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-033 | 00046I | SelectBodyShape source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00046I formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-034 | 00046O | Registration source must normalize localized id 227 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID00046O formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-035 | 00046V | Create-submit source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID00046V formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-036 | 0002QS | NewCreateUser source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0002QS formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-037 | 0004PB | NewUser constructor source must normalize localized id 89 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0004PB formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-038 | 0004PG | NewUser submit source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0004PG formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-039 | 00043O | NewUser2 nation source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00043O formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-040 | 000441 | NewUser2 source must normalize both localized ids 89 and 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID000441 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-041 | 0002T2 | IconsPane source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0002T2 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-042 | 0001MK | PostInputPane source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001MK formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-043 | 0001M5 | ChangeItem slot source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001M5 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-044 | 0001M7 | ChangeSpell slot source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001M7 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-045 | 0001MN | SpellSpell prompt source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001MN formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-046 | 0003V9 | UserPane source must replace all 13 g_pStringTable->GetString calls with g_pLanguageMan->GetLocalizedString | 100 | Exact formal search plus canonical global/header | UID0003V9 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-047 | 0000KK | Manual file/class/global/resource/memory coverage requires the exact Section 28 replacements and additions | 100 | Current manual coverage read | Supervisor-owned coverage files | incorporate | Unchecked/proposed; supervisor-owned |
| C0000KK-048 | 00040Q | Gate 2B must derive DB from exact current-schema idb_open({input_path:TX,run_auto_analysis:false,mode:"force_headless"}), require runtime_attestation({expected_database:DB,expected_canonical_path:TX}), rerun every exact prestate there, then perform A01 and its readbacks only on DB before A02 | 99 | Historical report-time evidence plus dynamically re-established current authority and isolated DB collision/name/type/comment/frame/bytes/xref contract | IDA Gate 2B A01 | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| C0000KK-049 | 00040Q | Cumulative A02 consumes A01's exact post-name state on the same returned DB, applies the one signature there, preserves __saved_registers/__return_address, changes only arg_0/result and arg_4/stringId at fixed offsets/widths, and binds every readback to DB before A03 | 99 | Isolated DB four-row frame plus StringBaseWide size4/m_data+0 layout | IDA Gate 2B A02 | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| C0000KK-050 | 00040Q | Cumulative A03 consumes A02's exact post-type/postframe state on the same returned DB, applies and reads back the exact function_regular comment there, and permits the sole later idb_save(database:DB,path:TX) only after the complete final endpoint passes | 99 | Isolated dynamic DB cumulative Section 21 endpoint/save contract; canonical verifier remains read-only | IDA Gate 2B A03/final endpoint | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| C0000KK-051 | 00041V | Protect constructor 0x004f0010 name/type/comment/bytes/bounds/xrefs from this report | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-052 | 00018S | Protect destructor 0x004f0290 name/type/comment/bytes/bounds from this report | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-053 | 00018T | Protect zero initializer 0x004f0310 raw name/type/empty comments/bounds while class identity remains unproven | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-054 | 00040P | Protect GetLocalizedString 0x004f0350 current name/type/comment/bytes/bounds/xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-055 | 00040R | Protect compiler EH helper 0x004f03c0 current name/type/comment/bytes/bounds/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-056 | 00018V | Protect compiler scalar wrapper 0x004f03d0 current name/type/comment/bytes/bounds/vtable route | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-057 | 00040V | Protect unnamed byte item at 0x0061c9d4 with bytes 00 04 00 00, empty comments, and zero xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-058 | 00040V | Protect unnamed byte item at 0x0061c9d8 with bytes 00 04 00 00, empty comments, and zero xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-059 | 00040W | Protect exact 0x0061c9dc-0x0061c9ec COL/vtable pointer cells and empty comments from source-data mutation | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-060 | 00040X | Protect aStrRes at 0x0061c9ec exact type/bytes/comment/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-061 | 00040X | Protect aTooManyStrings at 0x0061c9fc exact type/bytes/comment/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-062 | 00040X | Protect aInvalidStringI at 0x0061ca20 exact type/bytes/comments/two xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-063 | 0000RC | Protect g_pLanguageMan at 0x0067a750 current name/type/comment/bytes/192 xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| C0000KK-064 | 0000KK | Accepted callback must run only scoped file validators and a waited refresh, then physically reread coherent generated LanguageMan.cpp/h against every source-bearing inventory row | 100 | Workflow, pre-callback incomplete output, and final generated readback | Validation/generated readback | applied | Checked/applied; historical 2026-08-24 callback validators 000000027432-000000027513 passed; current validator-owned authority 000000027614 physically passed |
| C0000KK-065 | 0000KK | Accepted callback changed 52 ordinary documents plus validator-owned generated outputs; IDA, manual coverage, Gate 2, lifecycle, execution, and archive remain supervisor-owned | 100 | Accepted callback changed-file and validator-owned generated-output receipts | Role/lifecycle boundary | not-applicable | Unchecked/proposed; supervisor-owned boundary |
| C0000KK-066 | 0001FU | ConnectionClosed helper prose must normalize its documented localized id 0xf1 call to g_pLanguageMan->GetLocalizedString | 100 | Exact support-page stale token | UID0001FU prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-067 | 0000IJ | CreateUserDialogPane file prose must normalize its documented localized id 227 call | 100 | Exact support-page stale token | `by-file/CreateUserDialogPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-068 | 00003B | CreateUserDialogPane class prose must normalize its documented localized id 227 call | 100 | Exact support-page stale token | `by-class/CreateUserDialogPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-069 | 00001J | ChangeItemSlotInputPane class inventory must normalize its documented localized id 46 call | 100 | Exact support-page stale token | `by-class/ChangeItemSlotInputPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-070 | 00001M | ChangeSpellSlotInputPane class prose must reject GetString as an acceptable alias and use GetLocalizedString for id 45 | 100 | Exact support-page stale token | `by-class/ChangeSpellSlotInputPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-071 | 0001M8 | ChangeSpellSlotInputPane aggregate prose must normalize id 45 and remove the obsolete alias-equivalence claim | 100 | Exact support-page stale token | UID0001M8 prose | applied | Checked/applied; B005 callback 2026-08-24 |
| C0000KK-072 | 0001OS | UID0001OS must historicalize its former position-0/future-header route and record UID0000RC as the sole LanguageMan.cpp definition emitter at position 10, UID000071 as the matching LanguageMan.h extern emitter, and UID0001OS as non-emitting backing storage | 100 | Current command 000000027614 CPP/H route plus exact storage-page evidence | UID0001OS summary/status/route/history | applied | Checked/applied; B005 C072 callback and validator 000000027614 passed 2026-08-24 |

Ledger row count is 72. Current allocation is exactly 54 checked B005-owned rows and 18 unchecked supervisor-owned rows. Section 33 contains the exact ordered 72-row full-row twins with only the leading checkbox column added.

## Positive Evidence Summary

- The executable island has exactly seven bounded functions in source order and no hidden extra code item. Constructor/destructor/lookups use one consistent `LanguageMan` layout and vtable.
- Startup allocates exactly `0x2c` bytes and calls UID00041V. The class header's base/field/reserved shape preserves that size.
- LanguageMan and direct `Singleton<LanguageMan>` RTTI, hierarchy count three, and PMD `{4,-1,0}` prove the canonical class and explain singleton pointer adjustment/publication/clear without handwritten LanguageMan assignments.
- UID00040Q's two callers independently create a one-dword uninitialized result, consume `c_str`, then destroy it. UID0002RM/`0x00582560` allocates raw UTF-16 storage and does not release a prior value. This is a constructor into an ABI-hidden result, not assignment to an explicit source argument.
- Exact literal and resource xrefs connect `str.res`, `Too many strings`, and `Invalid String ID` to the constructor and both lookup variants. Exact immediate uses connect the two descriptive 1024 constants to parser limits while retaining the no-address-xref caveat.
- Existing accepted `g_pMiscWorkThread` source demonstrates the class-specialized Singleton definition pattern required to reproduce the observed LanguageMan base lowering.
- Current command `000000027614` generated output demonstrates the implemented route: the required include preamble and by-value copy body are present, declarations/API calls/source order are corrected, UID0000RC's sole definition is at position `10`, UID000071's matching extern is in the header, and the two former empty emitters are absent. The deficient state with missing includes/copy body, wrong declaration/API calls/order, and two empty markers belonged only to superseded pre-callback snapshots dated `2026-08-24`.

## IDA MCP Facts

- The facts in this section were observed in the dated `2026-08-24T06:47Z` report-time snapshot: IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, SHA256 `43A4BEAC940C47FF2B4136C278E1DB6F70E6C7F4ACE31C9FD5B76F8B627F47D7`, session `supervisor_uid0000jr_canonical_verify_20260824_064700`. Bounded read-only queries succeeded despite `auto_analysis_ready:false`; health was `status:ok`, with Hex-Rays/string cache ready. This is historical evidence only, not present authority; the supervisor dynamically re-establishes current canonical path/hash/session authority and reruns required exact prestates at each gate.
- Functions: `0x004f0010 LanguageMan__Constructor` size `0x27c`; `0x004f0290 LanguageMan__Destructor` size `0x80`; `0x004f0310 sub_4F0310` size `0x32`; `0x004f0350 LanguageMan__GetLocalizedString` size `0x22`; `0x004f0380 sub_4F0380` size `0x3b`; `0x004f03c0 sub_4F03C0` size `0x0b`; `0x004f03d0 sub_4F03D0` size `0xa7`; next function begins `0x004f0480`.
- Padding: `[0x004f0008,0x004f0010)` eight `CC`; `[0x004f028c,0x004f0290)` four; `[0x004f0342,0x004f0350)` fourteen; `[0x004f0372,0x004f0380)` fourteen; `[0x004f03bb,0x004f03c0)` five; `[0x004f03cb,0x004f03d0)` five; `[0x004f0477,0x004f0480)` nine.
- Parser/data: `0x0061c9d4` and `0x0061c9d8` each store little-endian `00 04 00 00`; both are unnamed one-byte undefined heads with no comments/xrefs. Vtable region values are COL `0x006498c0`, scalar wrapper `0x004f03d0`, `LObject::GetRuntimeClass` `0x004f4b10`, and `LObject::OnChangeMessage` `0x0041b6c0`.
- Literals: `aStrRes` `[0x0061c9ec,0x0061c9fc)`; `aTooManyStrings` `[0x0061c9fc,0x0061ca1e)`; two-byte alignment `[0x0061ca1e,0x0061ca20)`; `aInvalidStringI` `[0x0061ca20,0x0061ca44)`. All comments are literal empty.
- Global: `g_pLanguageMan` `[0x0067a750,0x0067a754)`, type `LanguageMan *`, bytes `00 00 00 00`, exact regular comment recorded in Section 21, repeatable comment empty, 192 total xrefs.
- Copy ABI: current type `void **__thiscall(_DWORD *this, void **, int)`; stack arguments are `arg_0` at `+0x0c` and `arg_4` at `+0x10`; body constructs the hidden result through `0x00582560` from selected table text or fallback and returns it.
- Negative IDA facts: no LanguageManager identity, no UID00018T route, no parser-address use, no extra function, no direct UID00018V call, no ordinary UID00040R call, and no existing UID00040Q comment.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Source/output disposition |
|---|---|---|---|---|---|---|
| `[0x004f0008,0x004f0010)` | boundary gap | predecessor alignment | no code | none | exact | Eight `CC`; protect, no doc/source child. |
| `[0x004f0010,0x004f028c)` | UID00041V | `LanguageMan::LanguageMan` | true | UID000071 | `92/94 -> 94/95` | Exact repaired CPP at position 40; H blank because class declares it. |
| `[0x004f028c,0x004f0290)` | boundary gap | alignment | no code | UID00018R context | exact | Four `CC`; no source. |
| `[0x004f0290,0x004f0310)` | UID00018S | `LanguageMan::~LanguageMan` authored cleanup | true | UID000071 | `92/94 -> 93/95` | Preserve exact CPP at position 50; H blank. |
| `[0x004f0310,0x004f0342)` | UID00018T | adjacent seven-dword zero initializer | true custom code, source blocked | UID0000KK file context only | `85/91 -> 90/94` | Blank emitter/CPP/H; no empty marker; class exclusion explicit. |
| `[0x004f0342,0x004f0350)` | boundary gap | alignment | no code | UID00018R context | exact | Fourteen `CC`; no source. |
| `[0x004f0350,0x004f0372)` | UID00040P | pointer-return localized lookup | true | UID000071 | `90/93 -> 93/95` | Exact CPP at position 60; H declaration in UID000071. |
| `[0x004f0372,0x004f0380)` | boundary gap | alignment | no code | UID00018U context | exact | Fourteen `CC`; no source. |
| `[0x004f0380,0x004f03bb)` | UID00040Q | by-value StringBase localized lookup | true | UID000071 | `88/91 -> 94/95` | Exact CPP at position 70; corrected H declaration in UID000071. |
| `[0x004f03bb,0x004f03c0)` | boundary gap | alignment | no code | UID00018U context | exact | Five `CC`; no source. |
| `[0x004f03c0,0x004f03cb)` | UID00040R | Singleton constructor-unwind clear | false/compiler | none | `90/94 -> 92/95` | Blank CPP/H/emitter; no marker. Regenerated by direct base. |
| `[0x004f03cb,0x004f03d0)` | boundary gap | alignment | no code | UID00018U context | exact | Five `CC`; no source. |
| `[0x004f03d0,0x004f0477)` | UID00018V | scalar deleting destructor | false/compiler | none | `91/94 -> 93/95` | Blank CPP/H/emitter; regenerated from virtual destructor. |
| `[0x004f0477,0x004f0480)` | boundary gap | terminal alignment | no code | UID00018R context | exact | Nine `CC`; excludes Layer successor. |
| `[0x0061c9d4,0x0061c9dc)` | UID00040V | two inferred parser limits | true data | UID0000KK | `88/90 -> 91/91` | Exact file-local constants at position 20; H blank. |
| `[0x0061c9dc,0x0061c9ec)` | UID00040W | COL plus three-slot LanguageMan vtable | false/compiler | semantic UID000071 | `90/94 -> 92/95` | No CPP/H/emitter/marker; declarations regenerate. |
| `[0x0061c9ec,0x0061ca44)` | UID00040X | three UTF-16 source literals and alignment | true data | UID0000KK | `87/93 -> 91/95` | Exact file-local arrays at position 30; H blank. |
| `0x0067a750` source identity | UID0000RC | global definition plus Singleton specializations | true | UID0000KK | `92/94 -> 94/96` | Exact CPP at position 10; extern remains in class header. |
| `[0x0067a750,0x0067a754)` | UID0001OS | global backing storage | compiler/data | UID0000RC | `92/94 -> 94/96` | No duplicate source; document exact storage/xrefs. |
| `str.res` | UID0001RP | DAT localization resource | resource | UID0000KK consumer | `90/94 -> 92/95` | No C++ body; parser contract support. |
| LanguageMan class/type | UID000071 | complete 0x2c public/private declaration | true | UID0000KK | `89/92 -> 94/95` | Exact include CPP at position 0 and complete H. |
| LanguageManager alias | UID000072 plus ignored index | stale alias only | false | canonical UID000071 | `-1/-1 -> ignored 90/96` | No source/header alias; historical search context only. |
| `[0x004f0010,0x004f0477)` | UID00018R | mixed executable split index | false aggregate | none | recommend `94/95` | No emitter; exact rows above own behavior. |
| `[0x004f0350,0x004f03cb)` | UID00018U | lookup/EH split index | false aggregate | none | recommend `94/95` | No emitter; exact children own behavior. |
| `[0x0061c9c4,0x0061ca44)` | UID00025M | KeySpeedMgr/LanguageMan rdata split index | false aggregate | none | preserve ignored, recommend `90/94` | Exact child boundary correction only. |
| `[0x0061c9c4,0x0061c9d4)` | UID00031P | KeySpeedMgr COL/vtable only | compiler/data | UID00006Z | remains `88/92` | Correct stale displayed end `0x0061c9dc` to `0x0061c9d4`; excludes UID00040V. |
| LanguageMan RTTI descriptors | existing compiler data inside RTTI region | `LanguageMan`, `LObject`, `Singleton<LanguageMan>` hierarchy | false/compiler | declarations | exact | No standalone source or new UID; direct evidence only. |
| `NexusTK/localization/LanguageMan.cpp` | generated output | generated compilation unit | generated | UID0000KK | command `000000027614` complete | Current physical readback contains the expected eight ordered source fragments, UID0000RC's sole position-10 definition, and zero placeholders/empty markers; validator-owned output, never hand-edit. |
| `NexusTK/localization/LanguageMan.h` | generated output | generated class header | generated | UID000071/0000KK | command `000000027614` complete | Current physical readback contains one complete UID000071 fragment, including the matching extern declaration, and zero placeholders; validator-owned output, never hand-edit. |

Inventory totals: seven functions; seven alignment/boundary gaps; three source data fragments comprising two dwords and three strings; one compiler vtable/COL region; one global identity/backing object; one resource; two canonical class/type records plus one rejected alias; three aggregate/index rows; two generated outputs; RTTI descriptors. Every row above has a source/no-code, owner/emitter, metadata, destination, ledger, and checklist disposition.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
|---|---|---|
| `0x004f0010` | one code call from Application startup `0x00464108`; allocates `0x2c` at `0x004640ed` | Sole observed construction route and exact class size. |
| `0x004f0010` callees | LObject construction; Singleton lowering; DATFile ctor/open/GetSize/GetPosition/Read/Seek/dtor; MemoryMan alloc/copy/free; `MultiByteToWideChar`; MyError/throw | Complete parser and resource source dependency set. |
| `0x004f0290` | no direct callers; calls GetMemoryMan, FreeBufferMemory, LObject teardown | Ordinary virtual cleanup reached through compiler destruction routes. |
| `0x004f0310` | zero callers, callees, strings, globals, vtable refs, EH refs, or pointers | Strong file-context-only/class-exclusion disposition. |
| `0x004f0350` | 351 direct code xrefs, 129 named caller functions plus one null-function xref key; zero callees | Highly live raw pointer API; complete fan-in was counted rather than sampled. |
| `0x004f0380` | exactly `0x00530c27` UID0001CY and `0x005c08a2` UID0001NV; both branches call `0x00582560` | Live by-value StringBase API and two exact consumer repairs. |
| `0x004f03c0` | one EH metadata/near-jump route at `0x00600a64`; zero ordinary calls/callees | Compiler constructor-unwind clear, not authored helper. |
| `0x004f03d0` | one data route from vtable `0x0061c9e0`; no direct rel32 callers | Compiler scalar deleting destructor. |
| `0x0061c9d4/0x0061c9d8` | zero direct address xrefs; constructor immediates at `0x004f011f`, `0x004f0167`, `0x004f01d1` | Descriptive source constants with retained/pool caveat. |
| `0x0061c9dc` | COL `0x006498c0`; no direct source xref | RTTI/vtable prefix. |
| `0x0061c9e0` | points to `0x004f03d0`; constructor/destructor/wrapper vtable stores refer to the vtable base | Virtual destructor slot. |
| `0x0061c9e4/0x0061c9e8` | point to inherited `0x004f4b10/0x0041b6c0` | Inherited virtual slots; no handwritten LanguageMan bodies. |
| `0x0061c9ec` | one constructor open-path ref | `L"str.res"`. |
| `0x0061c9fc` | one constructor throw-path ref | `L"Too many strings"`. |
| `0x0061ca20` | two refs, one from each lookup helper | Shared `L"Invalid String ID"` fallback. |
| `0x0067a750` | 192 total xrefs: five lifetime writes/clears and 187 reads | One source global plus compiler-lowered base lifecycle, not multiple definitions. |

## Documentation Evidence And IDA Status

- Supporting current docs already establish the exact children, class size, direct base, parser behavior, MemoryMan/DATFile surface, source tree, resource semantics, vtable role, and global identity. These facts are retained at same-or-greater detail.
- Historical pre-callback documentation defects, all repaired by the accepted ordinary callback on `2026-08-24`, were UID00040Q explicit-output/assignment uncertainty, UID00041V `Tell`/free copy spelling, UID000071 empty CPP and wrong H signature, UID0000RC definition without specializations, UID00018T empty emitter, UID00031P stale displayed end, StringBase assignment wording, and legacy `GetString`/`g_pStringTable` source occurrences. The later UID0001OS position-`0`/future-header statement was repaired by C072. Current disposition is by-value UID00040Q source, `GetPosition` plus `memoryMan->MemmoveWrapper`, complete UID000071 CPP/H with extern, UID0000RC position-`10` definition/specializations, blank non-emitting UID00018T and UID0001OS with no generated markers, corrected UID00031P end, raw-initializer StringBase terminology, and canonical `GetLocalizedString`/`g_pLanguageMan`; command `000000027614` confirms the complete generated result.
- Current IDA is already source-quality for constructor, destructor, raw lookup, compiler helpers, and global. The only bounded improvement is UID00040Q A01-A03. No other name/type/comment change is justified by this report.
- Manual coverage is stale at the file/class/global/memory children described in Section 28. Generated coverage and generated source remain read-only and validator-owned.

## Ranked Ownership Analysis

### 1. UID0000KK LanguageMan.cpp with UID000071 LanguageMan

- Evidence for: exact contiguous method order, class RTTI/vtable, field layout, singleton global, resource/literal refs, source-tree placement, current emitter routing, and generated file.
- Evidence against: the adjacent UID00018T lacks class/liveness evidence and parser dwords lack address xrefs. Both are explicitly contained without weakening the rest of the unit.
- Decision: direct and overwhelmingly strongest compilation-unit/class owner pair.

### 2. A separate LanguageManager compatibility module

- Evidence for: stale generated/exported alias naming and older docs.
- Evidence against: no live RTTI/type/vtable/allocation, while LanguageMan identity is direct and complete.
- Decision: reject; historicalize UID000072 only.

### 3. KeySpeedMgr, caller modules, or a generic resource/string module

- Evidence for: linker adjacency for KeySpeedMgr and many consumers for lookup APIs.
- Evidence against: exact KeySpeedMgr data ends before parser dwords; consumers do not define localization storage; StringBase only owns result construction, not localization selection.
- Decision: support dependencies only, never direct owner.

### Proposed new file/grouping, if applicable

- Not applicable. No new file, child UID, split, or merge is warranted. Existing exact children are sufficient; the recommendation completes their current routes.

## Source Placement

- Recommended placement: `NexusTK/localization/LanguageMan.h` and `NexusTK/localization/LanguageMan.cpp` under UID0000KK/UID000071.
- The header owns class/base declarations, extern global, public APIs, private ABI-preserving layout, and size assertion. The CPP owns includes, global/specializations, constants/literals, and four authored methods in the exact dependency order stated above.
- Rejected placements: separate `LanguageManager.cpp`; StringBase.cpp for copy selection; Singleton.cpp for class-specific global specializations; resource docs as source emitters; KeySpeedMgr.cpp for parser dwords; direct generated-file edits.
- Remaining placement uncertainty is limited to whether original source named both stored 1024 constants. File placement itself is settled.

## Range / Split / Padding / Reclassification Analysis

- Exact executable boundaries and all seven padding gaps are listed in Sections 13/14. No range overlaps, hidden functions, tail chunks, or new split requirement were found.
- UID00018R and UID00018U remain non-emitting split indexes. Exact children own source/compiler dispositions.
- UID00018T remains separate from UID000071. Its file-context owner is retained, emitter removed, and generated empty marker eliminated. This is a source-emission reclassification, not a byte-range or reconstructable-status change.
- UID00025M remains a mixed ignored index. UID00031P's exact range must end at `0x0061c9d4`; UID00040V starts there. UID00040W starts at the LanguageMan COL at `0x0061c9dc`; UID00040X starts at `0x0061c9ec`; successor Layer starts at `0x0061ca44`.
- Compiler data and padding remain non-source. No direct `.rdata` definition is emitted for COL/vtable/RTTI.

## Negative Evidence Summary

- No `LanguageManager` live identity exists despite exhaustive string/type/RTTI/allocation/vtable searches.
- UID00018T has no liveness or object identity route. Executable adjacency alone does not prove a LanguageMan member method or the meaning of its seven stores.
- The two parser dwords have no address xrefs. Their source role is based on value/order/immediate corroboration, so the report does not claim the binary loads them.
- UID00040Q never releases a prior output buffer. Assignment and explicit output-source signatures are therefore rejected.
- The four-byte IDA `SimpleUString` artifact is incompatible with current canonical 24-byte SSO source and does not outweigh exact one-pointer StringBase behavior.
- UID00040R has only an EH route; UID00018V has only a vtable route and delete mechanics. Neither proves a standalone authored method.
- Consumer fan-in does not transfer ownership of lookup methods or the global to caller files.
- Linker adjacency does not transfer LanguageMan parser data to KeySpeedMgr, and inherited vtable slots do not create LanguageMan method bodies.

## IDA Rename / Type / Comment Recommendations

The report-time canonical-verifier session `supervisor_uid0000jr_canonical_verify_20260824_064700`, canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and physical SHA256 `43A4BEAC940C47FF2B4136C278E1DB6F70E6C7F4ACE31C9FD5B76F8B627F47D7` are dated read-only prestate evidence only. They are never a Gate 2B mutation or save target: do not pass that verifier session to `rename`, `set_type`, `set_function_comments`, or `idb_save`, and do not mutate or save the canonical path.

For this section, symbolic `TX` means the exact isolated current-canonical-derived working path selected by the supervisor for the later transaction, and symbolic `DB` means only the exact database/session identifier returned when the supervisor opens that exact TX with `idb_open({input_path:TX,run_auto_analysis:false,mode:"force_headless"})`. Do not name, predict, or substitute a preferred session identifier. Stop before any mutation unless the open succeeds, the returned DB is not the report-time verifier session, TX is not the canonical path, and `runtime_attestation({expected_database:DB,expected_canonical_path:TX})` passes for that exact returned DB and exact opened TX path.

After attestation and before A01, rerun every literal A01/P01-P13 prestate, the exact desired-name collision lookup, and the `StringBaseWide` layout inspection on DB. All results must match the dated report-time evidence exactly; any name, type, comment, frame, range, byte, xref, item, support-layout, or collision difference stops the transaction. A01-A03 are then one ordered cumulative transaction, not three independent alternatives: execute only `A01 -> immediate DB readback -> A02 -> immediate DB readback -> A03 -> immediate DB readback`. Every mutation and every named `lookup_funcs`, `list_funcs`, `inspect_items`, `get_comments`, `stack_frame`, `get_bytes`, `xrefs_to`, and `type_inspect` prestate/readback call must use `database:DB`. Stop before the next action on any operation error or poststate mismatch. Only after the complete final A03 endpoint passes may the supervisor perform the sole save as `idb_save({database:DB,path:TX})`; require `ok:true` and returned `path` exactly TX, then obtain a separate physical TX size/SHA256 receipt. Never save the report-time verifier session or canonical path.

Fresh report-time collision precheck at `2026-08-24T06:47Z`: exact `list_funcs` filter `LanguageMan__CopyLocalizedString`, offset `0`, count `20`, returned `data:[]`, `next_offset:null`. The supervisor must repeat that exact collision lookup with `database:DB` immediately before A01 and stop unless it is still empty. Current `StringBaseWide` inspection returned UDT size `4`, exactly one member `wchar_t *m_data` at `+0x0`, size `4`.

| ID | Exact entity | Literal current prestate | Proposed action or protection | Expected readback |
|---|---|---|---|---|
| A01 rename | function `[0x004f0380,0x004f03bb)`, 59 bytes | Fresh DB prestate must show name `sub_4F0380`; type `void **__thiscall(_DWORD *this, void **, int)`; regular `""`; repeatable `""`; function_regular `""`; function_repeatable `""`. Frame exactly `__saved_registers +0x4 size 4 _DWORD`; `__return_address +0x8 size 4 _UNKNOWN *`; `arg_0 +0xc size 4 _DWORD`; `arg_4 +0x10 size 4 _DWORD`. Callers exactly `0x00530c27` and `0x005c08a2`; exact 59 bytes are `55 8b ec 8b 55 0c 56 85 d2 78 1b 3b 51 08 7d 16 8b 41 04 8b 4d 08 ff 34 90 e8 c2 21 09 00 8b 45 08 5e 5d c2 08 00 8b 4d 08 68 20 ca 61 00 e8 ad 21 09 00 8b 45 08 5e 5d c2 08 00`. DB desired-name lookup must return no function. | Exact `rename` payload uses `database:DB`; batch function `{addr:"0x4f0380", name:"LanguageMan__CopyLocalizedString"}`; `pure:true`; `allow_overwrite:false`; `stop_on_error:true`; `dry_run:false`. Do not create/move/split a function. | Require rename summary `total:1`, `ok:1`, `failed:0`, `stopped:false`, `allow_overwrite:false`, `stop_on_error:true`. Every immediate readback uses `database:DB` and must show name exactly `LanguageMan__CopyLocalizedString`; size `0x3b`; desired-name `list_funcs` now returns one row at `0x004f0380`; type still exactly `void **__thiscall(_DWORD *this, void **, int)`; all four comments `""`; frame exactly the four prestate rows/offsets/sizes/types; exact range/bytes/two callers unchanged. This exact DB post-name state is A02's only valid prestate. |
| A02 set_type | same function on DB, only after exact A01 endpoint | On DB, name exactly `LanguageMan__CopyLocalizedString`; size `0x3b`; type exactly `void **__thiscall(_DWORD *this, void **, int)`; all four comments `""`; frame exactly `__saved_registers +0x4 size 4 _DWORD`; `__return_address +0x8 size 4 _UNKNOWN *`; `arg_0 +0xc size 4 _DWORD`; `arg_4 +0x10 size 4 _DWORD`; callers/bytes/range exactly A01-protected. Required support type on DB is exact UDT `StringBaseWide`, size `4`, sole member `wchar_t *m_data` at `+0x0`, size `4`. | Exact `set_type` payload uses `database:DB`; one function edit `{addr:"0x4f0380", kind:"function", signature:"StringBaseWide *__thiscall LanguageMan__CopyLocalizedString(LanguageMan *this, StringBaseWide *result, int stringId)"}`. This signature edit is the sole permitted frame semantic change: only `arg_0 -> result` with `StringBaseWide *` and `arg_4 -> stringId` with `int`; both stay size `4` at offsets `+0xc/+0x10`. Protect the saved-register and return-address rows exactly. | Require result row `ok:true`, kind `function`, no error. Every immediate readback uses `database:DB` and must show name exactly `LanguageMan__CopyLocalizedString`; type exactly `StringBaseWide *__thiscall(LanguageMan *this, StringBaseWide *result, int stringId)`; frame exactly `__saved_registers +0x4 size 4 _DWORD`; `__return_address +0x8 size 4 _UNKNOWN *`; `result +0xc size 4 StringBaseWide *`; `stringId +0x10 size 4 int`; all four comments `""`; exact range/bytes/two callers unchanged. This exact DB post-type/postframe state is A03's only valid prestate. |
| A03 set_function_comments | same function on DB, only after exact A02 endpoint | On DB, name exactly `LanguageMan__CopyLocalizedString`; size `0x3b`; type exactly `StringBaseWide *__thiscall(LanguageMan *this, StringBaseWide *result, int stringId)`; frame exactly `__saved_registers +0x4 size 4 _DWORD`; `__return_address +0x8 size 4 _UNKNOWN *`; `result +0xc size 4 StringBaseWide *`; `stringId +0x10 size 4 int`; regular `""`; repeatable `""`; function_regular `""`; function_repeatable `""`; exact range/bytes/two callers unchanged. | Exact `set_function_comments` payload uses `database:DB`; one item `{addr:"0x4f0380", comment:"Source LanguageMan::CopyLocalizedString(int stringId) const returns a one-pointer StringBaseWide by value. IDA exposes the MSVC hidden result object as an explicit argument; each branch constructs that result from selected or fallback UTF-16 text through sub_582560."}`. | Require result address `0x4f0380`, no error. Every immediate readback uses `database:DB` and must show exact A02 name/type/four frame rows; function_regular exactly the payload text; regular/repeatable/function_repeatable `""`; exact range/59 bytes/two callers unchanged. Only this full cumulative DB endpoint is Gate 2B success for C048-C050; only then may the supervisor perform the sole `idb_save({database:DB,path:TX})` and verify `ok:true`, exact returned TX path, and a separate physical TX receipt. |
| P01 | function `[0x004f0010,0x004f028c)` | `LanguageMan__Constructor`; `void __thiscall(LanguageMan *this)`; regular/repeatable/function-repeatable `""`; function_regular `Source LanguageMan constructor. RTTI proves direct LObject and Singleton<LanguageMan> bases; publication of g_pLanguageMan through the this+4/-4 adjustment is compiler lowering for the direct Singleton base, not a handwritten assignment.` | No change | Preserve exact prestate, bytes, bounds, and one caller |
| P02 | function `[0x004f0290,0x004f0310)` | `LanguageMan__Destructor`; `void __thiscall(LanguageMan *this)`; regular/repeatable/function-repeatable `""`; function_regular `Source LanguageMan destructor; previous Boost exception destructor identity was symbol pollution. Frees authored localization strings. Clearing g_pLanguageMan and lower-base teardown are implicit direct Singleton<LanguageMan>/LObject destruction mechanics.` | No change | Preserve exact prestate, bytes, bounds |
| P03 | function `[0x004f0310,0x004f0342)` | `sub_4F0310`; `void __thiscall(_DWORD *this)`; all four comment fields `""` | No change; no inferred class/name/type/comment is safe | Preserve exact prestate, seven stores, bytes, bounds, zero routes |
| P04 | function `[0x004f0350,0x004f0372)` | `LanguageMan__GetLocalizedString`; `const wchar_t *__thiscall(LanguageMan *this, int stringId)`; regular/repeatable/function-repeatable `""`; function_regular `Source LanguageMan::GetLocalizedString(int stringId). Returns the stored wide string for an in-range id or the static Invalid String ID fallback.` | No change | Preserve exact prestate, bytes, bounds, 351 calls |
| P05 | function `[0x004f03c0,0x004f03cb)` | `sub_4F03C0`; `void __cdecl()`; regular/repeatable/function-repeatable `""`; function_regular `Compiler constructor-unwind cleanup for the direct Singleton<LanguageMan> base. Sole EH metadata route clears g_pLanguageMan; this is not an original source helper and must remain non-emitting.` | No change | Preserve exact prestate, bytes, bounds, sole EH route |
| P06 | function `[0x004f03d0,0x004f0477)` | `sub_4F03D0`; `LanguageMan *__thiscall(LanguageMan *this, unsigned __int8 deletingFlags)`; regular/repeatable/function-repeatable `""`; function_regular `MSVC scalar deleting destructor for LanguageMan. Compiler-only wrapper expands authored destruction, implicit Singleton/LObject teardown, deleting flags, object-size/delete mechanics, and return-this ABI; do not expose as a source method.` | No change | Preserve exact prestate, bytes, bounds, sole vtable route |
| P07 | item `0x0061c9d4` | one-byte undefined head; name/type `""`; bytes `00 04 00 00`; regular/repeatable `""`; zero xrefs | No change | Preserve exact item, bytes, comments, xrefs |
| P08 | item `0x0061c9d8` | one-byte undefined head; name/type `""`; bytes `00 04 00 00`; regular/repeatable `""`; zero xrefs | No change | Preserve exact item, bytes, comments, xrefs |
| P09 | range `[0x0061c9dc,0x0061c9ec)` | `0x61c9dc` unnamed undefined one-byte head -> `0x6498c0`; `0x61c9e0 off_61C9E0` four-byte data -> `0x4f03d0`; `0x61c9e4` unnamed four-byte data -> `0x4f4b10`; `0x61c9e8` unnamed four-byte data -> `0x41b6c0`; every regular/repeatable comment `""` | No change | Preserve every exact head/name/type/width/value/comment and vtable-store/data route |
| P10 | item `[0x0061c9ec,0x0061c9fc)` | `aStrRes`; `const wchar_t[]`; size 16; exact UTF-16 `L"str.res"`; regular/repeatable `""`; one code ref | No change | Preserve exact item/bytes/type/comments/xref |
| P11 | item `[0x0061c9fc,0x0061ca1e)` | `aTooManyStrings`; `const wchar_t`; size 34; exact UTF-16 `L"Too many strings"`; regular/repeatable `""`; one code ref | No change | Preserve exact item/bytes/type/comments/xref |
| P12 | item `[0x0061ca20,0x0061ca44)` | `aInvalidStringI`; type `""`; size 36; exact UTF-16 `L"Invalid String ID"`; regular/repeatable `""`; two code refs | No change | Preserve exact item/bytes/type/comments/xrefs and two-byte predecessor alignment |
| P13 | item `[0x0067a750,0x0067a754)` | `g_pLanguageMan`; `LanguageMan *`; bytes `00 00 00 00`; regular `Sole externally linked LanguageMan singleton pointer. Canonical source identity is g_pLanguageMan; historical dword_67A750, DAT_0067a750, and g_pStringTable aliases are rejected.`; repeatable `""`; 192 xrefs | No change | Preserve exact name/type/bytes/comments/item/bounds/all xrefs |

Negative constraints: do not rename/type/comment UID00018T; do not materialize parser dwords or vtable cells; do not create a `LanguageManager` type; do not rename `sub_582560` in this report; do not expose the hidden result pointer in source C++; do not alter any function boundary, chunk, bytes, xref, compiler helper, frame offset, or frame width. A02 is the sole permitted frame semantic edit and may change only the two argument names/types stated above; `__saved_registers` and `__return_address` are protected. Dependencies outside this table receive no Gate 2B action, readback claim, or completion dependency.

## First-Draft C++ Recommendation

All code below is the exact implemented formal-channel text applied by the accepted callback and confirmed by current read-only generated output. It is neither example nor unapplied draft code. No direct generated-file edit is permitted.

UID000071 `RECONSTRUCTION_CPP` at emitter position `0`:

```cpp
#include "LanguageMan.h"
#include "../archive/DATFile.h"
#include "../util/Error.h"
#include "../util/MemoryMan.h"

#include <windows.h>

[[CHILDREN]]
```

UID000071 complete `RECONSTRUCTION_H` replacement:

```cpp
#ifndef NEXUSTK_LOCALIZATION_LANGUAGEMAN_H
#define NEXUSTK_LOCALIZATION_LANGUAGEMAN_H

#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class LanguageMan;
extern LanguageMan *g_pLanguageMan;

class LanguageMan : public LObject, public Singleton<LanguageMan>
{
public:
    LanguageMan();
    virtual ~LanguageMan();

    const wchar_t *GetLocalizedString(int stringId) const;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
    CopyLocalizedString(int stringId) const;

private:
    wchar_t **m_strings;
    int m_stringCount;
    unsigned int m_reservedState[8];
};

typedef char LanguageManSizeMustBe44[
    sizeof(LanguageMan) == 0x2c ? 1 : -1];

#endif
```

UID0000RC `RECONSTRUCTION_CPP` at emitter position `10`:

```cpp
LanguageMan *g_pLanguageMan = 0;

template <>
Singleton<LanguageMan>::Singleton()
{
    g_pLanguageMan = static_cast<LanguageMan *>(this);
}

template <>
Singleton<LanguageMan>::~Singleton()
{
    g_pLanguageMan = 0;
}
```

UID00040V `RECONSTRUCTION_CPP` at emitter position `20`:

```cpp
namespace {
const int kMaxStringResourceLineBytes = 1024;
const int kMaxLocalizedStringCount = 1024;
}
```

UID00040X `RECONSTRUCTION_CPP` at emitter position `30`:

```cpp
namespace {
const wchar_t kStringResourceName[] = L"str.res";
const wchar_t kTooManyStringsMessage[] = L"Too many strings";
const wchar_t kInvalidStringIdText[] = L"Invalid String ID";
}
```

UID00041V `RECONSTRUCTION_CPP` at emitter position `40`:

```cpp
LanguageMan::LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    DATFile stringResource;
    stringResource.Open(kStringResourceName);
    (void)stringResource.GetSize();

    wchar_t **temporaryStrings =
        static_cast<wchar_t **>(
            memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * kMaxLocalizedStringCount));
    m_stringCount = 0;

    bool reachedEndOfFile = false;
    char multiByteLine[kMaxStringResourceLineBytes * 2];
    wchar_t wideLine[kMaxStringResourceLineBytes];

    do {
        int lineLength = 0;

        while (stringResource.GetPosition() < stringResource.GetSize()) {
            stringResource.Read(&multiByteLine[lineLength], 1);

            if (multiByteLine[lineLength] == '\r') {
                stringResource.Seek(1, 1);
                break;
            }

            if (multiByteLine[lineLength] == '\n' || ++lineLength >= kMaxStringResourceLineBytes)
                break;
        }

        if (stringResource.GetPosition() >= stringResource.GetSize())
            reachedEndOfFile = true;

        for (int i = 0; i < lineLength; ++i) {
            if (multiByteLine[i] == 0x11)
                multiByteLine[i] = '\r';
        }

        const int wideChars = MultiByteToWideChar(
            0,
            0,
            multiByteLine,
            lineLength,
            wideLine,
            kMaxStringResourceLineBytes);
        const size_t byteCount = static_cast<size_t>(wideChars) * sizeof(wchar_t);
        wchar_t *copiedLine =
            static_cast<wchar_t *>(
                memoryMan->AllocateBufferMemory(byteCount + sizeof(wchar_t)));

        temporaryStrings[m_stringCount] = copiedLine;
        memoryMan->MemmoveWrapper(temporaryStrings[m_stringCount], wideLine, byteCount);
        temporaryStrings[m_stringCount][wideChars] = L'\0';

        const int storedIndex = m_stringCount++;
        if (storedIndex >= kMaxLocalizedStringCount)
            throw MyError(kTooManyStringsMessage);
    } while (!reachedEndOfFile);

    m_strings =
        static_cast<wchar_t **>(memoryMan->AllocateBufferMemory(sizeof(wchar_t *) * m_stringCount));
    for (int i = 0; i < m_stringCount; ++i)
        m_strings[i] = temporaryStrings[i];

    memoryMan->FreeBufferMemory(temporaryStrings);
}
```

UID00018S `RECONSTRUCTION_CPP` at emitter position `50`:

```cpp
LanguageMan::~LanguageMan()
{
    MemoryMan* memoryMan = GetMemoryMan();

    for (int i = 0; i < m_stringCount; ++i)
        memoryMan->FreeBufferMemory(m_strings[i]);

    memoryMan->FreeBufferMemory(m_strings);
}
```

UID00040P `RECONSTRUCTION_CPP` at emitter position `60`:

```cpp
const wchar_t *LanguageMan::GetLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return m_strings[stringId];
    }

    return kInvalidStringIdText;
}
```

UID00040Q `RECONSTRUCTION_CPP` at emitter position `70`:

```cpp
mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
LanguageMan::CopyLocalizedString(int stringId) const
{
    if (stringId >= 0 && stringId < m_stringCount) {
        return mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >(
            m_strings[stringId]);
    }

    return mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >(
        kInvalidStringIdText);
}
```

UID00018T, UID00040R, UID00018V, UID00040W, UID0001OS, UID00018R, and UID00018U keep both formal channels blank. Their exact no-code/no-emitter proofs are respectively: no safe source identity after exhaustive liveness/type checks; constructor EH lowering; scalar deleting wrapper lowering; declaration-generated vtable/COL; backing storage already represented by UID0000RC; executable aggregate; lookup aggregate. None should generate an empty marker.

Behavioral fidelity: this source preserves the constructor's post-store/post-increment overflow check, byte-by-byte CR/LF parsing, `0x11` remap, CP0 conversion, allocation sizes, per-string terminator, pointer-table copy, and cleanup. The by-value copy method preserves separate branch-local raw construction into the compiler-hidden result. Direct Singleton specializations preserve the observed complete-object pointer adjustment and lifetime clears while leaving compiler EH/delete scaffolding implicit.

Plausible mid-2000s shape: raw pointers, explicit MemoryMan/DATFile helpers, VC-compatible size typedef assertion, numeric parser limits, `0` initialization, direct base specializations, and no modern library replacement match established project style. No third-party import directive applies.

## Final Recommendation

- C001-C046 and C066-C072 are applied at full report-level detail. Preserve their completed source, behavior, rejected alternatives, and support-page normalization.
- Keep canonical ownership assignments UID000071 -> UID0000KK, authored methods -> UID000071, constants/literals/global -> UID0000KK, and UID0001OS -> UID0000RC. For deterministic recursive CPP assembly, UID0000RC/UID00040V/UID00040X and the authored methods emit through UID000071's explicit child anchor while surfacing to UID0000KK; keep UID00018T -> UID0000KK only, with explicit UID000071 exclusion and no emitter.
- Preserve C072's exact global route: UID0000RC emits the sole `LanguageMan.cpp` definition at position `10`, UID000071 emits `extern LanguageMan *g_pLanguageMan;` in `LanguageMan.h`, and UID0001OS remains non-emitting backing storage. The former position-`0`/future-header statement is historical only.
- Keep UID00040R, UID00018V, UID00040W, RTTI, aggregates, and padding non-emitting. Do not add new UIDs or source files.
- Supervisor independently owns C047 manual coverage and C048-C050 IDA. C051-C063 remain explicit protected no-change contracts. C064 scoped validation/readback is complete; C065 remains supervisor-owned lifecycle boundary.
- Future work outside this assignment: none required for LanguageMan source completion. Broader consumers may still have unrelated reconstruction gaps, but the stale lookup tokens listed here are fully allocated.

## Recommended Target Doc Changes

- Target `by-file/LanguageMan.md` is applied at `94/94`; because by-file pages have no literal `RECONSTRUCTABLE` metadata key, reconstructability remains its semantic prose/coverage disposition. Its reconstruction-path metadata contains `NexusTK/localization/`, with the complete Section 14 model, source/compiler boundaries, UID00018T exclusion, by-value copy resolution, Singleton lowering, and exact generated proof.
- Exact emitter order `0,10,20,30,40,50,60,70` is implemented through UID000071's explicit recursive anchor; generated CPP has all eight fragments exactly once and zero empty markers.
- Historical generated LanguageManager alias, Boost destructor pollution, old file-local clear-helper interpretation, old copy-output uncertainty, and Wave3 exporter grade remain only where explicitly labeled historical or superseded.

## Recommended Support Doc Changes

- Core class/alias, every exact code/index child, global/resource pages, StringBase/Singleton dependencies, and NumberInput/VirusChecker callers are applied exactly per C002-C029. Compiler pages retain blank source.
- C030-C045 now contain 18 canonical `g_pLanguageMan->GetLocalizedString(...)` formal calls across their 16 destination pages; IDs/expressions and surrounding behavior are unchanged. C046 supplies 13 more in UID0003V9.
- C066-C071 support prose is normalized without behavior or ID loss, and no source compatibility alias was added.
- C072 is applied to UID0001OS at report-level detail: summary/status/route/history now record UID0000RC position `10`, the already-emitted UID000071 header extern, non-emitting physical storage, and the superseded position-`0`/future-header history.

## Score And Metadata Recommendation

| UID | Pre-callback | Applied current | Metadata/source change and cap |
|---|---:|---:|---|
| 0000KK | 89/89 | 94/94 | Complete file inventory/source route; cap for private lexical names and stored-constant provenance. |
| 000071 | 89/92 | 94/95 | Complete header/include emitter and exact direct-base/ABI shape; reserved tail stays intentionally neutral. |
| 000072 | ignored 80/strong | ignored 90/96 | Exhaustive live negative identity closure; no source. |
| 00018R | current split index | 94/95 | Complete seven-function/padding/source/no-code inventory. |
| 00041V | 92/94 | 94/95 | Full behavior retained and two source API defects resolved. |
| 00018S | 92/94 | 93/95 | Exact authored/compiler teardown split retained. |
| 00018T | 85/91 | 90/94 | Exhaustive file-context ownership and class/liveness exclusion; source remains blocked. |
| 00018U | current split index | 94/95 | Complete exact-child and padding reconciliation. |
| 00040P | 90/93 | 93/95 | Exact pointer-return behavior, 351-call inventory, constant reuse. |
| 00040Q | 88/91 | 94/95 | Hidden-result StringBase API and source body fully resolved. |
| 00040R | 90/94 | 92/95 | Exact compiler EH route and no-code source cause. |
| 00018V | 91/94 | 93/95 | Exact vtable-only compiler wrapper and no-code source cause. |
| 00040V | 88/90 | 91/91 | Source-ready descriptive constants; no-address-xref cap retained. |
| 00040W | 90/94 | 92/95 | Exact COL/vtable inventory and declaration-regeneration proof. |
| 00040X | 87/93 | 91/95 | Exact strings, bounds, xrefs, source order. |
| 0000RC | 92/94 | 94/96 | One definition plus exact direct-Singleton specializations. |
| 0001OS | 92/94 | 94/96 | Exact storage, xrefs, semantic/physical one-definition split. |
| 0001RP | 90/94 | 92/95 | Complete parser/resource contract and current consumer normalization. |

UID00025M remains an ignored mixed index but may move to `90/94` after exact child synchronization. UID00031P remains exactly `88/92`; its manual payload changes only the stale displayed range and summary wording, not those page metadata scores. Other support scores should remain unchanged unless their own page-wide score rationale explicitly attributes a cap to the stale LanguageMan token corrected here.

## Open Questions With Attempted Resolution

| Question | Attempted resolution | Result / score impact |
|---|---|---|
| Is UID00040Q assignment or construction? | Decompiled both branches and `0x00582560`; checked both caller stack lifetimes and StringBase destructor/c_str use | Resolved construction into hidden return object; no blocker. |
| Is result StringBase, SimpleUString, WideString, or std::wstring? | Compared live UDT sizes and current canonical type docs/formals | Resolved canonical one-pointer StringBase; other alternatives rejected. |
| Was the source API explicit output or by value? | Reconstructed x86 hidden-result ABI and two call sites | Resolved by value; IDA retains explicit ABI parameter only. |
| Does LanguageManager require compatibility source? | Searched RTTI, types, allocations, vtables, destructors, generated and docs | Resolved no; normalize consumers to canonical API. |
| Who authors singleton publication/clear? | Read RTTI PMD/lowering and accepted class-specialization pattern | Resolved Singleton specializations; no explicit LanguageMan method assignment. |
| Does UID00018T initialize LanguageMan tail? | Checked calls/pointers/xrefs/EH/vtable/globals/strings/type route, offsets, allocation and constructor | Resolved class exclusion; file-context ownership only; no safe source body. |
| Were `0x0061c9d4/d8` named constants? | Checked exact items, xrefs, values, constructor immediates and linker order | Descriptive constants remain strongest source inference; original spelling/address use unresolved and score-capped. |
| Is `m_reservedState[8]` semantically complete? | Checked all LanguageMan methods, exact size, UID00018T, and current layout evidence | No safe member names; neutral ABI storage is the evidence-backed final disposition. |
| Can current generated files compile coherently? | Physically reread current command `000000027614` CPP/H and compared declarations, includes, exact UID order, helper APIs, duplicates, markers, stale tokens, UID0000RC definition position, and UID000071 extern | Resolved: every identified LanguageMan-local generation defect and the C072 route are coherent at the documented reconstruction level. |

No question remains as a future-investigation placeholder. The two lexical uncertainties are explicitly contained and do not prevent implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Manual coverage remains supervisor-owned. Apply these exact replacements only if the referenced current rows remain unchanged after callback.

Replace UID0000KK in `by-file/-coverage-report.md` with:

> - [UID:0000KK][LanguageMan](by-file/LanguageMan.md) : reconstructable : 94% : very-strong : Complete `NexusTK/localization/LanguageMan.cpp` source unit with ordered include preamble, sole `g_pLanguageMan` definition and direct `Singleton<LanguageMan>` specializations, two parser limits, three UTF-16 literals, exact str.res constructor, authored destructor, raw-pointer and by-value StringBase lookups, coherent LanguageMan.h, explicit adjacent zero-initializer class exclusion, compiler EH/scalar/vtable separation, canonical LanguageMan identity, and zero generated empty emitters.

Replace UID000071 and UID000072 in `by-class/-coverage-report.md` with:

> - [UID:000071][LanguageMan](by-class/LanguageMan.md) : reconstructable : 94% : very-strong : Complete 0x2c `LanguageMan : LObject, Singleton<LanguageMan>` declaration with m_strings/m_stringCount, ABI-preserving reserved tail, exact constructor/destructor, raw-pointer GetLocalizedString, by-value one-pointer StringBase CopyLocalizedString, extern singleton, direct-base specialization lowering, source/compiler boundaries, and UID0000KK owner/emitter route.

> - [UID:000072][LanguageManager](by-class/LanguageManager.md) : ignored : 90% : very-strong : Historical/generated alias only; exhaustive current RTTI/type/vtable/allocation searches find LanguageMan and Singleton<LanguageMan> but no standalone LanguageManager identity, source file, header, allocation, or emitter.

Replace UID0000RC in `by-global/-coverage-report.md` with:

> - [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md) : reconstructable : 94% : very-strong : Sole externally linked `LanguageMan *g_pLanguageMan = 0` definition in `NexusTK/localization/LanguageMan.cpp`, followed by class-specific Singleton<LanguageMan> constructor/destructor specializations that reproduce direct-base publication and clear; exact storage UID0001OS has 192 refs, five compiler/base lifetime writes or clears, 187 reads, canonical RTTI, one header extern, and no LanguageManager/g_pStringTable alias source.

Replace UID0001RP in `by-resource/-coverage-report.md` with:

> - [UID:0001RP][str-res-localized-strings](by-resource/str-res-localized-strings.md) : reconstructable : 92% : very-strong : DAT-backed `str.res` localization contract consumed by LanguageMan; exact parser reads byte lines, handles CR/LF, remaps 0x11 to CR, converts with code page 0, enforces 1024 line/count limits with the observed post-store overflow path, allocates owned UTF-16 strings, serves 351 raw lookup calls and two by-value StringBase calls, and preserves current package/id evidence without hard-coding English in consumers.

Replace the current by-memory LanguageMan executable block from UID00018R through its terminal padding with:

>     - [UID:00018R][0x004f0010-0x004f0477.LanguageManLocalization](by-memory/0x004f0010-0x004f0477.LanguageManLocalization.md) 0x004f0010-0x004f0477 | exact split index | LanguageMan localization lifecycle and helpers : ignored : 94% : very-strong : Complete non-emitting seven-function LanguageMan.cpp island with exact authored constructor/destructor/two lookups, file-context-only zero initializer, compiler Singleton unwind/scalar wrapper, and all internal padding; exact children own source/no-code dispositions and no aggregate marker is emitted.
>
>         - [UID:00041V][0x004f0010-0x004f028c.LanguageManConstructor](by-memory/0x004f0010-0x004f028c.LanguageManConstructor.md) 0x004f0010-0x004f028c | constructor | LanguageMan::LanguageMan : reconstructable : 94% : very-strong : Exact str.res parser/allocator constructor with one Application startup caller, direct Singleton<LanguageMan> base publication, complete DATFile GetPosition/Read/Seek, MemoryMan allocation/copy/free, MultiByteToWideChar, 0x11 remap, post-store MyError overflow, and source-ready C++ at position 40.
>
>         - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f028c-0x004f0290 | padding | LanguageMan internal alignment : ignored : 100% : strong : Exact four `0xcc` bytes after the constructor.
>
>         - [UID:00018S][0x004f0290-0x004f0310.LanguageManCleanupDestructor](by-memory/0x004f0290-0x004f0310.LanguageManCleanupDestructor.md) 0x004f0290-0x004f0310 | destructor | LanguageMan::~LanguageMan : reconstructable : 93% : very-strong : Exact authored destructor releases every localized string and the pointer table through MemoryMan; direct Singleton clear and LObject teardown are compiler/base lowering excluded from source C++ at position 50.
>
>         - [UID:00018T][0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer](by-memory/0x004f0310-0x004f0342.LocalizationAdjacentZeroInitializer.md) 0x004f0310-0x004f0342 | file-context helper | localization-adjacent seven-dword zero initializer : reconstructable : 90% : very-strong : Exact 0x32 body stores zero at +0x24 through +0x0c and is linker-adjacent inside LanguageMan.cpp, but exhaustive live checks find no caller, pointer, vtable, EH, global, string, or type route; keep UID0000KK ownership, exclude LanguageMan class ownership, and emit no invented source or empty marker.
>
>         - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f0342-0x004f0350 | padding | LanguageMan internal alignment : ignored : 100% : strong : Exact fourteen `0xcc` bytes after the zero initializer.
>
>         - [UID:00018U][0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers](by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md) 0x004f0350-0x004f03cb | exact split index | LanguageMan lookups and Singleton unwind support : ignored : 94% : very-strong : Non-emitting index over exact pointer-return lookup, by-value StringBase lookup, compiler constructor-unwind clear, and internal padding; canonical LanguageMan source and all exact child dispositions are closed.
>
>             - [UID:00040P][0x004f0350-0x004f0372.LanguageManGetLocalizedString](by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) 0x004f0350-0x004f0372 | method | LanguageMan::GetLocalizedString : reconstructable : 93% : very-strong : Exact signed bounds check returns m_strings[id] or kInvalidStringIdText; 351 direct call xrefs, zero callees, canonical UID000071 owner/emitter, and source-ready C++ at position 60.
>
>             - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f0372-0x004f0380 | padding | LanguageMan lookup alignment : ignored : 100% : strong : Exact fourteen `0xcc` bytes.
>
>             - [UID:00040Q][0x004f0380-0x004f03bb.LanguageManCopyLocalizedString](by-memory/0x004f0380-0x004f03bb.LanguageManCopyLocalizedString.md) 0x004f0380-0x004f03bb | method | LanguageMan::CopyLocalizedString : reconstructable : 94% : very-strong : Exact signed bounds check constructs a one-pointer mystr::StringBase<wchar_t> return value from selected or fallback UTF-16 text through the ABI-hidden result pointer; two live callers prove construction/lifetime, UID000071 owns/emits source at position 70, and explicit-output/SimpleUString/std::wstring alternatives are rejected.
>
>             - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f03bb-0x004f03c0 | padding | LanguageMan lookup alignment : ignored : 100% : strong : Exact five `0xcc` bytes.
>
>             - [UID:00040R][0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper](by-memory/0x004f03c0-0x004f03cb.LanguageManClearSingletonHelper.md) 0x004f03c0-0x004f03cb | compiler EH cleanup | LanguageMan Singleton constructor-unwind clear : ignored : 92% : very-strong : Exact 11-byte clear with one EH metadata route, zero ordinary callers/callees, and direct Singleton<LanguageMan> base source cause; blank/non-emitting with no standalone handwritten helper.
>
>         - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f03cb-0x004f03d0 | padding | LanguageMan compiler-helper alignment : ignored : 100% : strong : Exact five `0xcc` bytes.
>
>         - [UID:00018V][0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor](by-memory/0x004f03d0-0x004f0477.LanguageManScalarDeletingDestructor.md) 0x004f03d0-0x004f0477 | compiler scalar deleting destructor | LanguageMan scalar deleting destructor : ignored : 93% : very-strong : Exact vtable-only wrapper expands authored cleanup, implicit Singleton/LObject teardown, delete flags, 0x2c size/delete mechanics, and return-this ABI; no direct calls and no handwritten wrapper source.
>
>     - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004f0477-0x004f0480 | padding | LanguageMan to Layer alignment : ignored : 100% : strong : Exact nine `0xcc` bytes before the Layer successor.

Replace the current UID00025M block and children through UID00040X with:

>     - [UID:00025M][0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData](by-memory/0x0061c9c4-0x0061ca44.KeySpeedStringResourceReadOnlyData.md) 0x0061c9c4-0x0061ca44 | exact read-only-data split index | KeySpeedMgr and LanguageMan data : ignored : 90% : very-strong : Exact mixed index whose KeySpeedMgr COL/vtable ends at 0x0061c9d4 and whose LanguageMan children are two inferred parser-limit dwords, declaration-generated COL/vtable, and three directly referenced UTF-16 literals ending at the Layer locator boundary.
>
>         - [UID:00031P][0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData](by-memory/0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md) 0x0061c9c4-0x0061c9d4 | compiler RTTI/vtable data | KeySpeedMgrVtableData : reconstructable : 88% : very-strong : Exact KeySpeedMgr complete-object locator and three-slot primary vtable only; successor 0x0061c9d4 begins LanguageMan parser data and is excluded from this child; UID00031P page metadata remains 88/92.
>
>         - [UID:00040V][0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants](by-memory/0x0061c9d4-0x0061c9dc.LanguageManParserLimitConstants.md) 0x0061c9d4-0x0061c9dc | source constants | LanguageMan parser limits : reconstructable : 91% : very-strong : Two stored 1024 dwords best modeled as line/conversion and localized-string-count limits; exact zero address xrefs and three matching constructor immediates preserve the retained/pool confidence cap; emitted in LanguageMan.cpp at position 20.
>
>         - [UID:00040W][0x0061c9dc-0x0061c9ec.LanguageManVtableData](by-memory/0x0061c9dc-0x0061c9ec.LanguageManVtableData.md) 0x0061c9dc-0x0061c9ec | compiler RTTI/vtable data | LanguageMan vtable data : ignored : 92% : very-strong : Exact COL plus scalar deleting destructor and inherited LObject slots; direct RTTI/vtable stores prove class bases while declarations regenerate all bytes and no source array/marker is emitted.
>
>         - [UID:00040X][0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals](by-memory/0x0061c9ec-0x0061ca44.LanguageManStringResourceLiterals.md) 0x0061c9ec-0x0061ca44 | source literals | LanguageMan resource and diagnostic text : reconstructable : 91% : very-strong : Exact `str.res`, `Too many strings`, and `Invalid String ID` UTF-16 items with one, one, and two code refs respectively; emitted as file-local arrays in LanguageMan.cpp at position 30.

Replace UID0001OS in `by-memory/-coverage-report.md` with:

>     - [UID:0001OS][0x0067a750-0x0067a754.g_pLanguageMan](by-memory/0x0067a750-0x0067a754.g_pLanguageMan.md) 0x0067a750-0x0067a754 | singleton backing storage | g_pLanguageMan : ignored : 94% : very-strong : Exact four-byte zero-initialized LanguageMan pointer with 192 refs, five direct-Singleton/compiler lifetime writes or clears, 187 reads, exact current name/type/comment and neighboring bounds; UID0000RC emits the sole definition plus specializations, so this physical page emits no duplicate source.

No generated coverage, tracker, audit, catalog, registry, or lifecycle file should be hand-edited by B005.

## Follow-Up Actions

1. Later Gate 2, coverage, execution, archive, and every lifecycle decision are supervisor-owned externally. No B005 work remains unless this same report is returned for a specific repair.
2. B005-owned ordinary-document rows C001-C046/C066-C071 and validator/readback row C064 are complete and checked. Preserve their implementation pending fresh supervisor review.
3. Supervisor independently decides whether to accept A01-A03. If accepted, first dynamically re-establish current canonical authority, create isolated TX, derive DB only from the exact current-schema Section 21 `idb_open`, require the exact Section 21 runtime attestation and fresh DB prestates, then apply the cumulative actions/readbacks only to DB. This report delegates no preferred-session, verifier, or canonical-path mutation/save. C051-C063 allocate no mutation.
4. Supervisor applies still-current C047 manual coverage text and validates it through supervisor-authorized workflow.
5. Report execution/archive and every lifecycle transition remain supervisor/validator-owned under C065. Do not infer them from prose or status messages.

## Confidence

Overall report confidence is `96/100`.

- Function/data/range inventory: `100`.
- Runtime parser/lookup/destructor behavior: `99`.
- Canonical class/global/resource ownership: `100`.
- Copy-result ABI and source-facing StringBase shape: `99`.
- Singleton specialization source shape: `99`.
- Adjacent zero-initializer file context: `94`; class exclusion/no-emitter: `99`.
- Exact original private names and stored parser-constant declarations: `70-80`, explicitly score-capped without behavioral impact.

## Validator Results

Accepted callback validation is complete. The 52 initial scoped file validators ran as commands `000000027432` through `000000027483`; each scanned one file with `--apply --queue-timeout 240`, exited successfully, and reported `ok: 1`. A first waited command `000000027484` exposed a deferred-refresh backlog; after it drained, foreground command `000000027503` proved the queue was current but physically exposed the missing recursive emitter anchor. B005 repaired only the accepted five route documents and reran their scoped validators as `000000027505` through `000000027509`, each `ok: 1`. Queue-status command `000000027512` then reported zero queued and zero processing generated refreshes.

Historical accepted-callback final waited command `000000027513`, timestamp `2026-08-24T04:21:21-04:00`, reported `ok: 1`, `generated_refresh: completed`, and `generated_refresh_command_id: 000000027513`. Its dated physical post-command receipts were:

- Historical command-`000000027513` `auto-generated/NexusTK/localization/LanguageMan.cpp`: SHA256 `BB5EABD7C6E8F3062CCF268AE1A0DA4DBC023AF43C43BEB3AFE01B8A9DEDB302`; 4,868 bytes; 145 LF; 0 CRLF; terminal LF true. UID fragments were exactly `000071,0000RC,00040V,00040X,00041V,00018S,00040P,00040Q`, each once in that order. Placeholder/empty-marker count was zero.
- Historical command-`000000027513` `auto-generated/NexusTK/localization/LanguageMan.h`: SHA256 `8F40B16321C949D157C6C0AF0686DEBF253BB308DEA543FAF7F540018194F566`; 1,097 bytes; 37 LF; 0 CRLF; terminal LF true. It had one UID000071 fragment, complete guard/includes/extern/direct bases/methods/fields/size assertion, and zero placeholders.
- Historical command-`000000027513` semantic readback had `GetPosition`, `memoryMan->MemmoveWrapper`, by-value `CopyLocalizedString`, exact constants/literals, and Singleton specializations; it had zero `Tell`, free `MemmoveWrapper`, stale `GetString`, `g_pStringTable`, explicit-output facade, duplicate method, empty marker, or unresolved child token. Formal-source audit across C030-C046 found 31 canonical calls and zero stale aliases.

Historical pre-C072 read-only generated receipt was command `000000027608`, timestamp `2026-08-24T06:10:10-04:00`; B005 did not invoke it. Its physical receipts were:

- Historical command-`000000027608` `auto-generated/NexusTK/localization/LanguageMan.cpp`: SHA256 `51E5B94667EA7C98B03DDA9CEE5ECE43CC49615979B45CF0458AC5B7397FC5B6`; 4,868 bytes; 145 LF; 0 CRLF; terminal LF true. UID fragments were exactly `000071,0000RC,00040V,00040X,00041V,00018S,00040P,00040Q`, each once in that order; placeholder/empty-marker count was zero.
- Historical command-`000000027608` `auto-generated/NexusTK/localization/LanguageMan.h`: SHA256 `F508FF8FCF9D31E70C05FC690C740A2E2460517FAE32CA960EAC8B9091AAA407`; 1,097 bytes; 37 LF; 0 CRLF; terminal LF true. It had one complete UID000071 fragment with guard/includes/extern/direct bases/methods/fields/size assertion and zero placeholders.

C072 scoped validation used `python .\tools\validator.py --mode file --file by-memory\0x0067a750-0x0067a754.g_pLanguageMan.md --apply --queue-timeout 240 --wait-generated`. Command `000000027614`, timestamp `2026-08-24T07:26:44-04:00`, exited `0`, scanned one Markdown file, reported `ok: 1`, and completed generated refresh under the same command id/timestamp. Physical reread proved UID0001OS SHA256 `7309424B42110DB76187210264020F9B5F761A4913D2C5A4D836FB55A04DCB4B`, 18,012 bytes, 124 LF, 0 CRLF, terminal LF true, with no Item Summary loss and zero active position-`0`/future-header statement. Validator-owned side effects were registry rebuild, generated metadata refresh, memory auto-coverage refresh, research-tracker refresh, projected-stats refresh, and `validator.ini` refresh; B005 made no direct generated/state edit.

Current validator-owned generated authority is command `000000027614`, timestamp `2026-08-24T07:26:44-04:00`. Physical receipts:

- `auto-generated/NexusTK/localization/LanguageMan.cpp`: SHA256 `400C108A0C509BD36FB42A6A16F76A18F8F26E6006CEE3ABA3C0ED6D99EB04BA`; 4,868 bytes; 145 LF; 0 CRLF; terminal LF true. UID fragments are exactly `000071,0000RC,00040V,00040X,00041V,00018S,00040P,00040Q`, each once in that order; UID0000RC contributes the sole definition, the copy body remains present, and placeholder/empty-marker count is zero.
- `auto-generated/NexusTK/localization/LanguageMan.h`: SHA256 `6C462978AEAE39C31AC2CA8FBC1F90D097B02C0B96BBE19359E07CB89859A92F`; 1,097 bytes; 37 LF; 0 CRLF; terminal LF true. It has one complete UID000071 fragment, exactly one `extern LanguageMan *g_pLanguageMan;`, complete guard/includes/direct bases/methods/fields/size assertion, and zero placeholders.
- Current semantic readback has UID0000RC's sole definition at position `10`, UID000071's matching header extern, the required include preamble, `GetPosition`, `memoryMan->MemmoveWrapper`, the by-value `CopyLocalizedString` body, exact constants/literals, Singleton specializations, and exact source order; it has zero stale aliases, duplicate methods, empty markers, placeholders, or unresolved child tokens.

The report contains zero executable PowerShell, Python, shell, validator, transaction, process-control, or lifecycle fences. Its `cpp` fences contain only implemented formal-channel C++ mirrored from the applied destination documents.

## Changed Files

Direct B005 edits in this accepted callback are this report plus exactly 52 ordinary by-* destinations allocated by C001-C046/C066-C071:

- Core/file/class: `by-file/LanguageMan.md`; `by-class/LanguageMan.md`; `by-class/LanguageManager.md`; `by-class/-ignored.md`.
- LanguageMan executable/data/global/resource: UID00018R, UID00041V, UID00018S, UID00018T, UID00018U, UID00040P, UID00040Q, UID00040R, UID00018V, UID00040V, UID00040W, UID00040X, UID00025M, UID00031P, `by-global/g_pLanguageMan.md`, UID0001OS, and `by-resource/str-res-localized-strings.md` at their exact ledger paths.
- Type/copy support: `by-file/StringBase.md`; `by-type/by-template/StringBaseTemplate.md`; `by-file/Singleton.md`; `by-type/by-template/SingletonTemplate.md`; UID0001CY; `by-file/NumberInputDialog.md`; UID0001NV; `by-file/VirusChecker.md`.
- Formal caller normalization: UID000331, UID0001ER, UID00046E, UID00046I, UID00046O, UID00046V, UID0002QS, UID0004PB, UID0004PG, UID00043O, UID000441, UID0002T2, UID0001MK, UID0001M5, UID0001M7, UID0001MN, and UID0003V9 at their exact ledger paths.
- Support prose normalization: UID0001FU; `by-file/CreateUserDialogPane.md`; `by-class/CreateUserDialogPane.md`; `by-class/ChangeItemSlotInputPane.md`; `by-class/ChangeSpellSlotInputPane.md`; UID0001M8.
- Current C072 callback directly edited only this report and the already-listed UID0001OS support page. Validator command `000000027614` made only the validator-owned generated/metadata side effects recorded in Section 31.

Generated CPP/H, `tools/validator.ini`, generated coverage metadata, and projected stats were changed only by the required validator commands, never by direct editing. B005 did not edit manual coverage, IDA, supervisor, tracker, audit, catalog, lifecycle, or archive files and did not invoke `execute_report`. The UID0001OS lease was released before validation. The report reconciliation lease was released after exact artifact reread, and the authoritative `Agent-B005/current_leases.md` receipt records zero B005 entries.

## Implementation Tracking Checklist

Ordered-twin proof: all 72 checklist rows exactly mirror the complete Section 11 ledger rows in identical order. Removing only the leading checkbox column from each checklist row produces its byte-equivalent ledger row. Exactly 54 rows are checked/applied or checked/already-present; C047-C063 and C065 are the exact 18 unchecked/proposed supervisor rows.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
|---|---|---|---|---:|---|---|---|---|
| [x] | C0000KK-001 | 0000KK | LanguageMan is one localization compilation unit whose complete source/data/resource/compiler inventory and ordered emitter plan are Sections 14/22 | 99 | Live whole-file inventory plus generated CPP/H | `by-file/LanguageMan.md` all sections/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-002 | 000071 | LanguageMan is the canonical direct LObject and Singleton class; its CPP fragment supplies includes and its H fragment returns StringBase by value while preserving 0x2c layout | 99 | RTTI/PMD, allocation size, formal header, copy ABI | `by-class/LanguageMan.md` formal CPP/H and prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-003 | 000072 | LanguageManager is a rejected historical/generated alias with no live RTTI/type/vtable/allocation or source emitter | 100 | Live negative RTTI/type/allocation searches | `by-class/LanguageManager.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-004 | 000072 | The ignored-class index must preserve LanguageManager only as search context and point to canonical LanguageMan | 100 | Canonical alias disposition | `by-class/-ignored.md` UID000072 row | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-005 | 00018R | The executable island remains a non-emitting exact split index over seven functions and all padding; no aggregate C++ or empty marker | 100 | Live bounds/items/function inventory | UID00018R aggregate | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-006 | 00041V | Constructor source keeps complete parser behavior but uses DATFile::GetPosition and memoryMan->MemmoveWrapper and emits at position 40 | 99 | Exact decompile plus current support APIs | UID00041V formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-007 | 00018S | Destructor remains authored string/table release only; Singleton clear and LObject teardown are compiler lowering; emit at position 50 | 100 | Exact decompile, RTTI/PMD, helper identities | UID00018S formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-008 | 00018T | Seven-store zero initializer remains UID0000KK file-context owned, UID000071-excluded, reconstructable but non-emitting with blank emitter and no invented source type/name | 98 | Exact body plus exhaustive zero-route evidence | UID00018T metadata/prose/blank CPP/H | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-009 | 00018U | Lookup/singleton aggregate remains non-emitting exact split index and records final child source/compiler dispositions | 100 | Exact child inventory | UID00018U aggregate | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-010 | 00040P | GetLocalizedString is exact signed bounds-check pointer lookup using kInvalidStringIdText and emits at position 60 | 100 | 34-byte body, 351 calls, zero callees | UID00040P formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-011 | 00040Q | CopyLocalizedString returns one-pointer mystr::StringBase<wchar_t,...> by value; assign UID000071 emitter and position 70 | 99 | Hidden-result callers plus InitializeWideFromRaw | UID00040Q formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-012 | 00040R | 0x004f03c0 is compiler EH Singleton clear only and must remain blank/non-emitting | 100 | Sole EH metadata xref and body | UID00040R | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| [x] | C0000KK-013 | 00018V | 0x004f03d0 is compiler scalar deleting destructor only and must remain blank/non-emitting | 100 | Sole vtable route, delete flags, duplicated cleanup | UID00018V | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| [x] | C0000KK-014 | 00040V | Two inferred 1024 parser constants remain file-local source with no runtime address-use claim and emit at position 20 | 95 | Exact dwords, zero xrefs, three immediates | UID00040V formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-015 | 00040W | LanguageMan COL/vtable region is declaration-generated compiler data and emits no formal source or marker | 100 | Exact four pointer cells and vtable routes | UID00040W | already-present | Checked/already-present; B005 callback verified 2026-08-24 |
| [x] | C0000KK-016 | 00040X | str.res, Too many strings, and Invalid String ID are file-local UTF-16 literals emitted at position 30 | 100 | Exact strings and four code refs | UID00040X formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-017 | 0000RC | g_pLanguageMan definition plus class-specific Singleton constructor/destructor specializations emit at position 10 | 99 | PMD lowering and accepted singleton pattern | `by-global/g_pLanguageMan.md` formal CPP/prose/metadata | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-018 | 0001OS | 0x0067a750 is the four-byte backing storage for the sole g_pLanguageMan definition, not a second emitted global | 100 | Exact type/bytes/192 xrefs | UID0001OS | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-019 | 0001RP | str.res remains the parser resource: byte lines, CR/LF handling, 0x11 remap, CP0 conversion, 1024 caps | 99 | Constructor behavior and literal ref | `by-resource/str-res-localized-strings.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-020 | 00025M | Mixed KeySpeedMgr/LanguageMan rdata parent remains an ignored split index with exact child boundary 0x0061c9d4 | 100 | Exact bytes/locators/children | UID00025M | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-021 | 00031P | KeySpeedMgr vtable child ends at 0x0061c9d4, not 0x0061c9dc; LanguageMan parser dwords are excluded | 100 | Live item boundary and successor role | UID00031P | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-022 | 0000OA | StringBase docs must classify 0x00582560 as raw UTF-16 constructor/initializer, not assignment/copy | 100 | Callee allocates and never releases prior storage | `by-file/StringBase.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-023 | 0001WS | StringBase template support should add UID00040Q as a by-value hidden-result consumer of InitializeWideFromRaw | 99 | Two exact caller lifetimes and type size | `by-type/by-template/StringBaseTemplate.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-024 | 0004ZK | Singleton docs should add LanguageMan class-specific specialization and compiler-lowering example | 99 | PMD plus accepted g_pMiscWorkThread pattern | `by-file/Singleton.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-025 | 0004ZL | Singleton template support should add LanguageMan direct-base publication/clear route and null-preserving adjustment | 99 | RTTI hierarchy and machine lowering | `by-type/by-template/SingletonTemplate.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-026 | 0001CY | NumberInput caller should initialize a const StringBase from CopyLocalizedString by value before c_str use | 100 | Caller stack lifetime at 0x00530c27 | UID0001CY formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-027 | 0000M1 | NumberInputDialog file inventory should record corrected LanguageMan by-value dependency | 99 | UID0001CY route | `by-file/NumberInputDialog.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-028 | 0001NV | Virus scan caller should initialize canonical StringBase by value instead of a SimpleUString output object | 100 | Caller stack lifetime at 0x005c08a2 | UID0001NV formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-029 | 0000P5 | VirusChecker file inventory should record corrected LanguageMan/StringBase dependency | 99 | UID0001NV route | `by-file/VirusChecker.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-030 | 000331 | BrowserInvoke source must replace LanguageMan::GetString(235) with g_pLanguageMan->GetLocalizedString(235) | 100 | Canonical current header/global | UID000331 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-031 | 0001ER | PatchPane packet source must normalize localized lookup 176 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0001ER formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-032 | 00046E | CreateUser constructor body-shape source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00046E formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-033 | 00046I | SelectBodyShape source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00046I formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-034 | 00046O | Registration source must normalize localized id 227 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID00046O formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-035 | 00046V | Create-submit source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID00046V formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-036 | 0002QS | NewCreateUser source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0002QS formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-037 | 0004PB | NewUser constructor source must normalize localized id 89 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0004PB formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-038 | 0004PG | NewUser submit source must normalize localized id 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID0004PG formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-039 | 00043O | NewUser2 nation source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID00043O formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-040 | 000441 | NewUser2 source must normalize both localized ids 89 and 90 to g_pLanguageMan->GetLocalizedString | 100 | Canonical current header/global | UID000441 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-041 | 0002T2 | IconsPane source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0002T2 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-042 | 0001MK | PostInputPane source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001MK formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-043 | 0001M5 | ChangeItem slot source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001M5 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-044 | 0001M7 | ChangeSpell slot source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001M7 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-045 | 0001MN | SpellSpell prompt source must normalize its LanguageMan::GetString occurrence | 100 | Canonical current header/global | UID0001MN formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-046 | 0003V9 | UserPane source must replace all 13 g_pStringTable->GetString calls with g_pLanguageMan->GetLocalizedString | 100 | Exact formal search plus canonical global/header | UID0003V9 formal CPP/prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [ ] | C0000KK-047 | 0000KK | Manual file/class/global/resource/memory coverage requires the exact Section 28 replacements and additions | 100 | Current manual coverage read | Supervisor-owned coverage files | incorporate | Unchecked/proposed; supervisor-owned |
| [ ] | C0000KK-048 | 00040Q | Gate 2B must derive DB from exact current-schema idb_open({input_path:TX,run_auto_analysis:false,mode:"force_headless"}), require runtime_attestation({expected_database:DB,expected_canonical_path:TX}), rerun every exact prestate there, then perform A01 and its readbacks only on DB before A02 | 99 | Historical report-time evidence plus dynamically re-established current authority and isolated DB collision/name/type/comment/frame/bytes/xref contract | IDA Gate 2B A01 | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| [ ] | C0000KK-049 | 00040Q | Cumulative A02 consumes A01's exact post-name state on the same returned DB, applies the one signature there, preserves __saved_registers/__return_address, changes only arg_0/result and arg_4/stringId at fixed offsets/widths, and binds every readback to DB before A03 | 99 | Isolated DB four-row frame plus StringBaseWide size4/m_data+0 layout | IDA Gate 2B A02 | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| [ ] | C0000KK-050 | 00040Q | Cumulative A03 consumes A02's exact post-type/postframe state on the same returned DB, applies and reads back the exact function_regular comment there, and permits the sole later idb_save(database:DB,path:TX) only after the complete final endpoint passes | 99 | Isolated dynamic DB cumulative Section 21 endpoint/save contract; canonical verifier remains read-only | IDA Gate 2B A03/final endpoint | incorporate | Unchecked/proposed; supervisor-owned cumulative Gate 2B |
| [ ] | C0000KK-051 | 00041V | Protect constructor 0x004f0010 name/type/comment/bytes/bounds/xrefs from this report | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-052 | 00018S | Protect destructor 0x004f0290 name/type/comment/bytes/bounds from this report | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-053 | 00018T | Protect zero initializer 0x004f0310 raw name/type/empty comments/bounds while class identity remains unproven | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-054 | 00040P | Protect GetLocalizedString 0x004f0350 current name/type/comment/bytes/bounds/xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-055 | 00040R | Protect compiler EH helper 0x004f03c0 current name/type/comment/bytes/bounds/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-056 | 00018V | Protect compiler scalar wrapper 0x004f03d0 current name/type/comment/bytes/bounds/vtable route | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-057 | 00040V | Protect unnamed byte item at 0x0061c9d4 with bytes 00 04 00 00, empty comments, and zero xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-058 | 00040V | Protect unnamed byte item at 0x0061c9d8 with bytes 00 04 00 00, empty comments, and zero xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-059 | 00040W | Protect exact 0x0061c9dc-0x0061c9ec COL/vtable pointer cells and empty comments from source-data mutation | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-060 | 00040X | Protect aStrRes at 0x0061c9ec exact type/bytes/comment/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-061 | 00040X | Protect aTooManyStrings at 0x0061c9fc exact type/bytes/comment/xref | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-062 | 00040X | Protect aInvalidStringI at 0x0061ca20 exact type/bytes/comments/two xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [ ] | C0000KK-063 | 0000RC | Protect g_pLanguageMan at 0x0067a750 current name/type/comment/bytes/192 xrefs | 100 | Fresh literal Section 21 prestate | IDA protection | already-present | Unchecked/proposed protection; no mutation allocated |
| [x] | C0000KK-064 | 0000KK | Accepted callback must run only scoped file validators and a waited refresh, then physically reread coherent generated LanguageMan.cpp/h against every source-bearing inventory row | 100 | Workflow, pre-callback incomplete output, and final generated readback | Validation/generated readback | applied | Checked/applied; historical 2026-08-24 callback validators 000000027432-000000027513 passed; current validator-owned authority 000000027614 physically passed |
| [ ] | C0000KK-065 | 0000KK | Accepted callback changed 52 ordinary documents plus validator-owned generated outputs; IDA, manual coverage, Gate 2, lifecycle, execution, and archive remain supervisor-owned | 100 | Accepted callback changed-file and validator-owned generated-output receipts | Role/lifecycle boundary | not-applicable | Unchecked/proposed; supervisor-owned boundary |
| [x] | C0000KK-066 | 0001FU | ConnectionClosed helper prose must normalize its documented localized id 0xf1 call to g_pLanguageMan->GetLocalizedString | 100 | Exact support-page stale token | UID0001FU prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-067 | 0000IJ | CreateUserDialogPane file prose must normalize its documented localized id 227 call | 100 | Exact support-page stale token | `by-file/CreateUserDialogPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-068 | 00003B | CreateUserDialogPane class prose must normalize its documented localized id 227 call | 100 | Exact support-page stale token | `by-class/CreateUserDialogPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-069 | 00001J | ChangeItemSlotInputPane class inventory must normalize its documented localized id 46 call | 100 | Exact support-page stale token | `by-class/ChangeItemSlotInputPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-070 | 00001M | ChangeSpellSlotInputPane class prose must reject GetString as an acceptable alias and use GetLocalizedString for id 45 | 100 | Exact support-page stale token | `by-class/ChangeSpellSlotInputPane.md` | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-071 | 0001M8 | ChangeSpellSlotInputPane aggregate prose must normalize id 45 and remove the obsolete alias-equivalence claim | 100 | Exact support-page stale token | UID0001M8 prose | applied | Checked/applied; B005 callback 2026-08-24 |
| [x] | C0000KK-072 | 0001OS | UID0001OS must historicalize its former position-0/future-header route and record UID0000RC as the sole LanguageMan.cpp definition emitter at position 10, UID000071 as the matching LanguageMan.h extern emitter, and UID0001OS as non-emitting backing storage | 100 | Current command 000000027614 CPP/H route plus exact storage-page evidence | UID0001OS summary/status/route/history | applied | Checked/applied; B005 C072 callback and validator 000000027614 passed 2026-08-24 |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000027627","destination_path":"executed-b-agent-research/B005/0000KK-LanguageMan-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0000KK-LanguageMan-file-source-quality.md","timestamp":"2026-08-24T09:04:23-04:00","uid":"0000KK"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
