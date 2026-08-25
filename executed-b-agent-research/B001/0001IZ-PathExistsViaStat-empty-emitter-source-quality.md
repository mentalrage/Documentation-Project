** TARGET-REPORT-UID:0001IZ **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0001IZ PathExistsViaStat Empty-Emitter Source-Quality Report


## Finalized Report / Current Recommendation

- Agent: `B001`.
- Assignment: fresh report-only research and accepted implementation callback for [UID:0001IZ] `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`, resumed from three preserved ordinary partials after the earlier callback revocation.
- Report state: supervisor Gate 1, Gate 2A, and Gate 2B passed; the accepted ordinary-document and IDA changes were verified; validator command `000000017125` executed this report into the canonical archive; and supervisor commands `000000017128` through `000000017130` validated the four applied manual coverage replacements. B001 made no IDA, manual-coverage, report-lifecycle, audit, goal, or tracker mutation.
- Current recommendation: retain [UID:0001IZ] as the one source-bearing emitter under [UID:0000MI] `PathUtil`, populate its formal C++ block with `PathExistsViaStat(const wchar_t *path)`, and reclassify [UID:0000V6] as a non-emitting evidence mirror owned by [UID:0001IZ].
- Source placement: `NexusTK/util/PathUtil.cpp`, with an inferred declaration in `NexusTK/util/PathUtil.h`; consume the PlatformApi-owned `g_pfnWideStat` declaration rather than declaring a raw local `dword_69BE18`.
- Recommended target score: `92/94`, below the 95 barrier because original lexical names and header layout are inferred and no rebuilt-object comparison exists.
- Gate order: exact-artifact supervisor Gate 1, ordinary callback, Gate 2A, Gate 2B, report execution/archive, and post-execution manual coverage validation are complete.

## Supporting Research

- Healthy live IDA MCP session: `supervisor_gate2b_0002OT_20260723`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `3368`, `is_analyzing:false` at the 2026-07-24 B001 read-only check.
- Target function: `sub_582460`, exact half-open range `[0x00582460,0x00582495)`, 53 bytes, one basic block, cyclomatic complexity 1.
- Exact target bytes: `55 8B EC 83 EC 34 A1 24 2F 67 00 33 C5 89 45 FC 8B 45 08 8D 4D CC 51 50 FF 15 18 BE 69 00 8B 4D FC 83 C4 08 83 F8 FF 0F 95 C0 33 CD E8 9E 52 04 00 8B E5 5D C3`.
- Target-byte SHA256: `9283C746FB482BB7DED5096C9BA3E63F003646AACC801D31BA549C69D260CAA0`.
- The 22-byte entry signature through `lea ecx,[ebp-34h]` occurs exactly once at `0x00582460`; the raw little-endian VA bytes `60 24 58 00` occur zero times.
- Live decompilation: `bool __cdecl sub_582460(int a1)` with a 48-byte stack object and `return unk_69BE18(a1, v2) != -1;`.
- The existing IDA `_stat64i32` UDT is exactly 48 bytes and matches the stack allocation. The dispatch target `_wstat64i32` at `0x005e25aa` already has the exact prototype `int __cdecl(const wchar_t *FileName, struct _stat64i32 *Stat)`.
- The dispatch slot at `0x0069be18` is zero-initialized storage assigned `_wstat64i32` by the live initializer at `0x0041a438` and by retained constructor projections at `0x0059976d` and `0x005999a8`.
- Current project source already emits the human declaration `int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *buffer);` through [UID:0002AS]. This report independently revalidated that declaration against live initializer, wrapper, consumer, and UDT evidence.
- Preserved partials independently read back and accepted by B001 during this callback:
  - UID0001IZ was repaired and validated by command `000000017088`; current SHA256 `D04135DF3BD0772749D5B5BAF75CD65DF608A2F1CECB5AA2F38D87591B1505AB`.
  - UID0000V6 required no repair after exact readback; current SHA256 `3CA4E048D0CE7356C3AB1F567A616420464D657309C7B1D007D303C85E766DEC`, preserving successful validator command `000000017083`.
  - UID0000MI required no repair after exact readback; current SHA256 `CAFC65728B9F41734AD6CFCA9A696612CF9005489EADC2B292F0940A631B6DAA`, preserving successful validator command `000000017086`.
  - Validator-owned `auto-generated/NexusTK/util/PathUtil.cpp` refreshed from command `000000017088`; current SHA256 `3668BCE8646D4FD97521899C15D0AD3CF6C3702B32619D8FEC8C80C431E73158`, 658 bytes, 16 lines, exactly one UID0001IZ body, zero UID0001IZ/UID0000V6 empty markers, and one unchanged UID00022K empty marker.
- Every report-listed support page was inspected. Exact current content already satisfied the report in FileIO UID0000JD, StdioFile aggregate UID0001IR, StdioFileOpen UID0001IT, live WideApi initializer UID0000WD, and FileExists UID00022K, so those files were not edited. Literal target-specific gaps were repaired in StdioFile UID0000O9, dispatch body UID0002AS, dispatch global UID0000TQ, retained constructor UID0004N6, PlatformApi UID0000ML, and proposed source tree UID0001R1.

## Target

- Primary target UID: `0001IZ`.
- Target path: `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`.
- Exact binary range: `[0x00582460,0x00582495)`.
- Entity: free C++03 wide-path existence helper using the PlatformApi `_wstat64i32` function-pointer slot.
- Declared report coverage: only [UID:0001IZ]. Support recommendations for [UID:0000V6], [UID:0000MI], and dispatch/source-tree pages do not claim additional report coverage for those UIDs.

## Current Target State

- Historical research baseline before implementation: UID0001IZ `87/89`, owner/emitter UID0000MI, reconstructable true, blank formal, SHA256 `CE9EE809170A4D4B5CBF2F9C9F1F74229A668E1C69AF6561BAE9A84C304E2658`; UID0000V6 `87/89`, owner/emitter UID0000MI, reconstructable true, blank formal, SHA256 `2E5C4806A4B7CEF35C188EF9698DEB84531B16C8433C3A8267D2D2DF368738E6`; UID0000MI SHA256 `3BD1C1A263FA5A54EDEE4D7D4CC21A7CC65CBD07E6DFEB2EB175ADF3CC7CA239`.
- Current `APPLIED_VERIFIED` target: UID0001IZ is `92/94`, retains owner/emitter UID0000MI and reconstructable true, contains the exact formal and complete Gate 2B pre-state handoff, and has SHA256 `D04135DF3BD0772749D5B5BAF75CD65DF608A2F1CECB5AA2F38D87591B1505AB` after validator `000000017088`.
- Current `APPLIED_VERIFIED` mirror: UID0000V6 is `91/94`, owner UID0001IZ, reconstructable false, blank emitter/formal, SHA256 `3CA4E048D0CE7356C3AB1F567A616420464D657309C7B1D007D303C85E766DEC`; exact readback accepted existing validator `000000017083`.
- Current `APPLIED_VERIFIED` file root: UID0000MI is `90/92`, canonical `PathUtil.cpp` current route with compact alternatives historicalized, SHA256 `CAFC65728B9F41734AD6CFCA9A696612CF9005489EADC2B292F0940A631B6DAA`; exact readback accepted existing validator `000000017086`.
- Current validator-owned generated state: SHA256 `3668BCE8646D4FD97521899C15D0AD3CF6C3702B32619D8FEC8C80C431E73158`, command `000000017088`, one UID0001IZ body, no UID0001IZ/UID0000V6 empty marker, and unchanged separate UID00022K empty marker.
- Historical state: older notes treated `PathUtil.cpp` versus compact `FileIO.cpp` or `StdioFile.cpp`, and `dword_69BE18` naming, as unresolved. Current FileIO, PlatformApi, source-tree, dispatch-table, and live MCP evidence closes those blockers for this target.

## Executive Recommendation

- Keep [UID:0001IZ] as reconstructable and source-bearing with owner/emitter [UID:0000MI].
- Raise [UID:0001IZ] to `92/94` and install the complete formal body in `NexusTK/util/PathUtil.cpp`.
- Reclassify [UID:0000V6] to `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0001IZ`, blank `EMITTER_UIDS`, blank formal C++, and `91/94`; retain it as a detailed evidence/index mirror only.
- Raise [UID:0000MI] `PathUtil` to `90/92`, remove the stale compact-file caveat from current-state prose, and preserve compact FileIO/StdioFile placement only as a rejected historical theory.
- Keep [UID:0000JD] `FileIO` as a non-emitting umbrella and keep [UID:0000O9] `StdioFile` as the concrete stream source root. Neither owns this stat-only free helper.
- Keep PlatformApi ownership of `g_pfnWideStat`; do not duplicate the function-pointer definition in PathUtil.

## Supervisor Active Recheck

- The active assignment required resolution of dispatch type/name/source placement and the empty-emitter C++ blocker, not another summary of those questions.
- No split of the 53-byte target is needed. Its one basic block is a complete function, and surrounding `0xcc` bytes prove clean boundaries.
- The source-bearing duplicate problem is resolved by retaining the exact by-memory page as the emitter and converting the by-item page to a covered-by evidence mirror.
- Every source-bearing item in assignment scope has an implementation-ready disposition. The unrelated sibling [UID:00022K] remains a separate PathUtil emitter and is not absorbed by this report.

## Inference Research Guidance Check

- Direct IDA facts are separated from documentation evidence and inferred source shape throughout this report.
- Existing docs were not assumed correct merely because they agreed with one another. The old report conclusions for UID0002AS, UID00022K, and StdioFile were used as search leads, then checked against current docs and the live IDB.
- The source name `PathExistsViaStat`, parameter `path`, local `statBuffer`, and global `g_pfnWideStat` are descriptive human-source reconstructions, not recovered original symbols. They are selected because they match established project usage, function behavior, and current PlatformApi style without exposing decompiler labels.
- The current proposed source tree and FileIO umbrella explicitly separate `File.cpp`, `StdioFile.cpp`, and `PathUtil.cpp`; this is stronger current evidence than the older compact-file caveat.
- Stale Wave2/Wave3 wording found in target history/status prose was ignored as authority and retained only in clearly dated historical context during callback.

## Heuristic / Inference Reanalysis And Validation

- Helper name: `PathExistsViaStat` is the best descriptive name. It distinguishes the stat-backed helper from [UID:00022K] `FileExists`, appears consistently in current callers/docs, and accurately states the observable role. `FileExists` for both helpers was rejected because it would collide and hide their differing semantics.
- ABI: `bool __cdecl PathExistsViaStat(const wchar_t *path)` is selected. The caller pushes one pointer, the callee performs plain `retn`, no `this` is read, and `setnz al` proves boolean return normalization.
- Dispatch name/type: `g_pfnWideStat` with `int (__cdecl *)(const wchar_t *, struct _stat64i32 *)` is selected. `_wstat64i32` is assigned to this exact slot by all initializer realizations, the CRT wrapper already has that prototype, and StdioFile uses the same slot/UDT.
- Local type/name: `struct _stat64i32 statBuffer` is selected. The live UDT is exactly 48 bytes and the target reserves exactly 48 data bytes plus the separate four-byte /GS cookie.
- Source placement: `NexusTK/util/PathUtil.cpp` is selected. Cross-subsystem callers, no object state, the sibling open-based existence probe, FileIO's current umbrella decision, and the proposed source tree all converge on PathUtil.
- Header placement: `NexusTK/util/PathUtil.h` is inferred because callers span startup, application, menu, map, and audio translation units. This is a source-shape inference, not PDB proof.
- Dispatch declaration dependency: PathUtil should include the PlatformApi declaration that exposes `g_pfnWideStat`; it must not define or redeclare storage locally. Exact include spelling is project-level header policy, but ownership is resolved.
- Return semantics: test exactly `!= -1`. Do not rewrite to `== 0`, even though normal `_wstat64i32` success is zero, because the binary accepts every non-`-1` result.
- Stack cookie: do not emit explicit security-cookie source. The local 48-byte struct naturally accounts for compiler /GS instrumentation in the binary build.
- Duplicate route: one formal body must live only on UID0001IZ. UID0000V6 should become non-reconstructable evidence owned by UID0001IZ rather than emitting a second function.
- Rejected raw forms: `sub_582460`, `dword_69BE18`, `unk_69BE18`, `_BYTE v2[48]`, `int a1`, and decompiler casts are not source-quality names or types.
- Rejected ownership: StdioFile adjacency is insufficient; FileIO is an umbrella; PlatformApi owns the slot but not consumer behavior; caller modules consume the helper but do not own it.
- No unresolved implementation blocker remains. Original lexical spelling and header include style remain bounded final-audit uncertainty and justify staying below 95, not leaving C++ blank.

## Evidence Standards Used

- Strong direct evidence: exact bytes, function boundaries, assembly, decompilation, CFG, callers, callees, xrefs, UDT layout, initializer stores, imported-wrapper prototype, zero-initialized slot bytes, and padding.
- Corroborating documentation evidence: target/item pages, PathUtil/FileIO/StdioFile roots, StdioFile Open, WideApi dispatch pages, WideApi initializer pages, proposed source tree, current generated PathUtil output, caller docs, and matching archived reports.
- Negative evidence: no function/xref at the exclusive end, no raw pointer to the target VA, no second entry-signature match, no object-state access, no vtable evidence, no original PathExists/WideStat IDA symbols, and no basis for consumer ownership.
- The evidence ladder supports exact behavior/type/routing at very strong confidence. Only original lexical and translation-unit spelling lack direct symbol/source proof.

## Evidence Checked

- IDA MCP: `idb_list`, `analyze_function 0x00582460` with assembly, `xrefs_to` for `0x00582460`, `0x0069be18`, and `0x00582495`, `type_inspect _stat64i32`, `get_bytes` around the target and dispatch table, `find_bytes` for the entry signature and raw VA pointer, plus prior same-pass checks of the initializer, StdioFile Open, `_wstat64i32`, retained constructor, caller contexts, and neighboring functions.
- Ordinary docs: UID0001IZ, UID0000V6, UID0000MI PathUtil, UID0000JD FileIO, UID0000O9 StdioFile, UID0001IT StdioFileOpen, UID0002AS dispatch storage, UID0000TQ dispatch global, UID0000WD initializer, UID0004N6 retained constructor, UID00022K FileExists, PlatformApi, caller docs, and proposed source tree.
- Generated/manual reports: current `auto-generated/NexusTK/util/PathUtil.cpp`; current by-memory, by-item, by-file, and by-global manual coverage rows.
- Matching archived reports: B001 UID0002AS, B001 UID00022K, B010 UID0000O9, B015 UID0000WD. They were treated as leads and revalidated rather than as direct proof.
- Failed/unavailable checks: none required for the assigned conclusions. Original PDB/source symbols and rebuilt object-code comparison do not exist in current evidence and therefore cap the final score.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C1IZ-01 | 0001IZ | Exact range is `[0x00582460,0x00582495)`, 53 bytes, SHA256 `9283C746...AA0`. | exact | Live bytes/function readback | Target Covered Range / Evidence | APPLIED_VERIFIED | target SHA `D04135DF...05AB`, validator `17088`, exact readback |
| C1IZ-02 | 0001IZ | Function is one-block `__cdecl`, one wide-path pointer argument, normalized bool return. | very strong | Assembly, callers, `setnz al`, plain `retn` | Target ABI / Behavior | APPLIED_VERIFIED | target ABI/behavior read back at report-level detail |
| C1IZ-03 | 0001IZ | Local object is exact 48-byte `_stat64i32`; separate four-byte cookie completes `sub esp,34h`. | exact | Stack frame and live UDT | Target Stack Layout | APPLIED_VERIFIED | exact UDT members/local/cookie split present in target |
| C1IZ-04 | 0001IZ | Return predicate must remain `g_pfnWideStat(...) != -1`. | exact | `cmp eax,-1; setnz al` | Target Behavior / formal C++ | APPLIED_VERIFIED | exact predicate and formal body read back |
| C1IZ-05 | 0001IZ | Dispatch slot `0x0069be18` receives `_wstat64i32`. | exact | Three initializer stores and wrapper xrefs | Target Dependency / PlatformApi support | APPLIED_VERIFIED | target plus UID0002AS/UID0000TQ/UID0004N6/UID0000ML record five exact xrefs |
| C1IZ-06 | 0001IZ | Source-facing slot is `g_pfnWideStat` with exact cdecl pointer type. | very strong | Wrapper prototype, UDT, current UID0002AS formal | Target Dependencies / IDA handoff | APPLIED_VERIFIED | ordinary docs/formal declaration and supervisor IDA name/type/comment readback verified |
| C1IZ-07 | 0001IZ | Exactly six direct call sites exist. | exact | Live xrefs and no pointer matches | Target Caller Inventory | APPLIED_VERIFIED | target and mirror exact six-call inventories match |
| C1IZ-08 | 0001IZ | Calls span startup video, application startup, main menu, map cache, and Miles loose-file fallback. | very strong | Caller decomp/docs | Target Caller Semantics | APPLIED_VERIFIED | target/mirror meanings and support boundaries read back |
| C1IZ-09 | 0001IZ | Only semantic callee is wide-stat dispatch; cookie check is compiler instrumentation. | exact | Live callee list/assembly | Target Callee Inventory | APPLIED_VERIFIED | target source/compiler boundary verified |
| C1IZ-10 | 0001IZ | Seven leading and eleven trailing `0xcc` bytes separate adjacent functions. | exact | Live bytes/neighbor lookup | Target Boundary / Padding | APPLIED_VERIFIED | target and mirror boundary evidence verified |
| C1IZ-11 | 0001IZ | Entry signature is unique and target VA has no raw pointer hits. | exact | `find_bytes` | Target Uniqueness | APPLIED_VERIFIED | target and mirror uniqueness evidence verified |
| C1IZ-12 | 0001IZ | PathUtil is canonical semantic/source owner. | strong | Caller spread, sibling helper, source tree | Target Ownership / PathUtil | APPLIED_VERIFIED | target, PathUtil, FileIO, StdioFile, and source tree agree |
| C1IZ-13 | 0001IZ | FileIO remains an umbrella, not the emitted translation unit. | strong | Current FileIO decision | Target rejected alternatives | APPLIED_VERIFIED | unchanged FileIO SHA `CA730C89...372E` independently verified |
| C1IZ-14 | 0001IZ | StdioFile adjacency does not imply ownership. | very strong | No `this`/field/vtable state; aggregate excludes target | Target negative evidence / StdioFile | APPLIED_VERIFIED | aggregate unchanged; StdioFile stale folding statement historicalized by validator `17089` |
| C1IZ-15 | 0001IZ | PlatformApi owns the dispatch slot but not this consumer body. | very strong | Initializer and broad slot consumers | Target dependency boundary | APPLIED_VERIFIED | PlatformApi and dispatch docs synchronized by validators `17090`-`17093` |
| C1IZ-16 | 0001IZ | Best source name is `PathExistsViaStat`. | strong inferred | Established docs and role distinction | Target naming / formal C++ | APPLIED_VERIFIED | target/formal/source-root naming verified |
| C1IZ-17 | 0001IZ | Best parameter/local names are `path` and `statBuffer`. | strong inferred | Type/role/style consistency | Target source-quality names | APPLIED_VERIFIED | formal plus supervisor IDA argument/local name and type readback verified |
| C1IZ-18 | 0001IZ | Definition belongs in `NexusTK/util/PathUtil.cpp`; declaration likely belongs in `PathUtil.h`. | strong inferred | Current source tree and cross-module callers | Target Source Placement / PathUtil | APPLIED_VERIFIED | target/PathUtil/source tree current route verified; source tree validator `17094` |
| C1IZ-19 | 0001IZ | Formal C++ body is implementation-ready and must not remain blank. | very strong | Exact behavior/type/dependency closure | Target formal block | APPLIED_VERIFIED | one target formal and one generated body verified |
| C1IZ-20 | 0001IZ | Target metadata should become `92/94`, owner/emitter unchanged. | strong | Closed blockers and draft under-95 rule | Target metadata | APPLIED_VERIFIED | target metadata/hash verified after validator `17088` |
| C1IZ-21 | 0000V6 | By-item duplicate should become non-reconstructable evidence mirror owned by UID0001IZ. | very strong | Same function/range and duplicate generated marker | By-item metadata/status/autogen | APPLIED_VERIFIED | mirror SHA `3CA4E048...6DEC`, validator `17083`, blank formal/emitter verified |
| C1IZ-22 | 0000MI | PathUtil current route should be synchronized and raised to `90/92`. | strong | Two helper children, FileIO decision, source tree | PathUtil status/contents/history | APPLIED_VERIFIED | PathUtil SHA `CAFC6572...6DAA`, validator `17086`, current/historical split verified |
| C1IZ-23 | 0001IZ | Compact FileIO/StdioFile placement is rejected current state and retained only as history. | strong | Current FileIO and source-tree decisions | Target/PathUtil history | APPLIED_VERIFIED | target/PathUtil/FileIO plus corrected StdioFile/source tree verified |
| C1IZ-24 | 0001IZ | Generated PathUtil output should contain one UID0001IZ body and no UID0001IZ/UID0000V6 empty markers. | exact expected | Current duplicate markers and proposed routing | Generated verification | APPLIED_VERIFIED | generated SHA `3668BCE8...3158`, command `17088`, exact counts verified |
| C1IZ-25 | 0001IZ | UID00022K remains an independent PathUtil sibling and its empty marker is not covered here. | exact scope | Separate range/function/report | Target/PathUtil scope note | APPLIED_VERIFIED | generated one UID00022K empty marker; unchanged UID00022K SHA `87044F36...E608` |
| C1IZ-26 | 0001IZ | IDA target should be renamed/typed/commented as PathExistsViaStat. | strong | Live pre-state and source reconstruction | Supervisor Gate 2B handoff | APPLIED_VERIFIED | Supervisor renamed and typed `0x00582460`, applied the regular function comment, renamed/typed `statBuffer`, and read back the exact human decompilation before IDB save. |
| C1IZ-27 | 0001IZ | IDA slot should be renamed/typed/commented as g_pfnWideStat. | strong | Exact initializer/wrapper/UDT evidence | Supervisor Gate 2B handoff | APPLIED_VERIFIED | Supervisor renamed and typed `0x0069be18`, applied the regular data comment, and read back the name, four-byte storage, zero value, comment, call expression, and five xrefs before IDB save. |
| C1IZ-28 | 0001IZ | `_stat64i32`, `_wstat64i32`, cookie helper, callers, and boundaries should remain unchanged. | exact | Current correct entities/protected constraints | Supervisor Gate 2B handoff | NO_CHANGE_VERIFIED | Supervisor readback preserved `_stat64i32`, `_wstat64i32`, `StackCookie`, six callers, five slot xrefs, exact bytes, 53-byte bounds, and leading/trailing padding. |
| C1IZ-29 | 0001IZ | Manual target/item/PathUtil and stale UID0002AS coverage rows need exact supervisor payloads. | exact current-state | Current manual rows | Manual coverage handoff | APPLIED_VERIFIED | Supervisor applied all four exact replacements after execution and validated by-memory/by-item/by-file coverage as commands 17128/17129/17130. |
| C1IZ-30 | 0001IZ | No blocker remains that justifies blank C++; uncertainty is lexical/final-audit only. | strong | Exhaustive resolution above | Target score rationale/open questions | APPLIED_VERIFIED | populated formal/current score rationale verified; Gate 2B does not block draft C++ |

## Positive Evidence Summary

- The function is fully modeled, uniquely signatured, directly called six times, and separated from neighbors by alignment bytes.
- Its 48-byte local exactly matches the live `_stat64i32` UDT, while the indirect slot is assigned the exact `_wstat64i32` wrapper in all current initializer realizations.
- `StdioFile::Open` independently uses the same slot and `_stat64i32` spelling, including `st_size` at offset `0x14`, which corroborates both type and source-facing dispatch name.
- Broad callers prove free utility scope; current PathUtil/FileIO/source-tree docs prove the selected source route; the current PlatformApi formal proves declaration ownership.
- The resulting C++ is short, human-readable C++03 and reproduces the exact call, local allocation, return predicate, and compiler-generated /GS condition.

## IDA MCP Facts

- Function: `sub_582460`, start `0x00582460`, end `0x00582495`, size `0x35`, one block, complexity 1, current prototype `bool __cdecl(int)`.
- Assembly stack shape: `sub esp,34h`; `_stat64i32` candidate at `[ebp-34h]`; security cookie at `[ebp-4]`.
- Dispatch instruction: `call dword ptr unk_69BE18` at `0x00582478` after pushes of local address and input path.
- Return sequence: `cmp eax,0FFFFFFFFh`, `setnz al`.
- Target xrefs: `0x004f5765`, `0x004f5781`, `0x004f640d`, `0x004f6853`, `0x00504c7d`, `0x0057b6be`.
- Slot xrefs at `0x0069be18`: initializer `0x0041a438`, StdioFile consumer `0x00582104`, target consumer `0x00582478`, retained constructor `0x0059976d`, raw retained projection `0x005999a8`.
- UDT: `_stat64i32`, size `0x30`; members at `0x00/0x04/0x06/0x08/0x0a/0x0c/0x10/0x14/0x18/0x20/0x28`, with implicit alignment at `0x0e-0x0f`.
- Padding: `0x00582459-0x00582460` is seven `0xcc` bytes; `0x00582495-0x005824a0` is eleven `0xcc` bytes.
- Neighbors: predecessor `sub_582410` ends at `0x00582459`; successor `sub_5824A0` begins at `0x005824a0`. No function or xref exists at `0x00582495`.
- Negative names: no current `PathExists*` or `WideStat*` IDA entity collides with the proposed names. Current slot is `unk_69BE18` and has no applied global type.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00582460-0x00582495` | UID0001IZ target | Exact source-bearing stat existence helper | true | UID0000MI | current `87/89`, proposed `92/94` | one formal body |
| Same exact function | UID0000V6 by-item mirror | Search/index/evidence mirror | proposed false | proposed UID0001IZ | current `87/89`, proposed `91/94` | no emitter/body |
| `0x004b81f0-0x004b821e` | UID00022K FileExists | Separate open-based existence sibling | true | UID0000MI | `88/90` | outside declared coverage |
| `0x00582070-0x00582459` plus family | UID0001IR/StdioFile children | Concrete stream object methods | mixed by child | UID0000O9 | existing | excludes target |
| `0x0069be18` | UID0002AS/UID0000TQ | PlatformApi dispatch storage | true data | UID0000TQ | `90/90` child, `92` global | dependency only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f5765` | `PlayStartupLogoBinkFile` first probe | Tests one of `LOGO.PAK`/`LOGO.PAD` before stream open. |
| `0x004f5781` | Same startup-logo function second probe | Tests alternate logo movie asset; second call site in same caller. |
| `0x004f640d` | `Application::Startup` | Tests `NEXON.LGO` to select LogoPane versus TerminalPane path. |
| `0x004f6853` | `MainMenuPane::MainMenuPane` | Tests optional `LEVEL.BMP` before StdioFile-backed load/decode. |
| `0x00504c7d` | `MapPane::LoadCompressedMapFile` | Tests `Documents\NexusTK\Maps\TK%06d.cmp` before CMAP read path. |
| `0x0057b6be` | `AILFileOpenCallback` | Tests loose-file fallback after DAT lookup before allocating StdioFile. |
| `0x00582478` | `unk_69BE18` / proposed `g_pfnWideStat` | Sole semantic call from target. |
| `0x0058248c` | `@__security_check_cookie@4` | Compiler /GS epilogue, not handwritten helper logic. |

## Documentation Evidence And IDA Status

- Target and by-item pages now contain exact range/caller/behavior evidence with one source-bearing UID0001IZ body and non-emitting UID0000V6 mirror routing; formerly stale blockers remain only in dated history.
- PathUtil owns this target and UID00022K, and its current prose selects standalone `PathUtil.cpp`; compact FileIO/StdioFile folding remains only as rejected historical layout theory.
- FileIO now explicitly rejects compact folding as the canonical current route and retains PathUtil as a separate source root.
- Proposed source tree explicitly lists `util/File.cpp`, `util/StdioFile.cpp`, and `util/PathUtil.cpp` and states that PlatformApi owns `_wfopen`/`_wstat64i32` dispatch entries.
- UID0002AS emits the exact source-facing `g_pfnWideStat` declaration and now records canonical UID0001IZ plus all five exact slot xrefs; its supervisor-owned manual by-memory row remains stale at `87%` despite the source page being `90/90`.
- B001's recorded live raw pre-state was the exact supervisor Gate 2B baseline. The supervisor has since applied and read back the accepted function, argument, local, slot, and regular-comment changes; B001 itself made no IDA mutation.

## Ranked Ownership Analysis

### 1. PathUtil

- Evidence for: free helper, no object state, five subsystem families, paired existence helper, current by-file owner, current proposed source tree, and active generated PathUtil root.
- Evidence against: no recovered original source filename or PDB.
- Decision: selected direct source owner and translation unit.

### 2. Compact FileIO translation unit

- Evidence for: historical possibility that small file utilities were grouped together.
- Evidence against: current FileIO page is explicitly non-emitting and rejects compact folding; current source tree and generated roots separate PathUtil and StdioFile.
- Decision: rejected as current canonical route; preserve only as historical source-layout uncertainty.

### 3. StdioFile, PlatformApi, or caller-owned modules

- Evidence for: target is adjacent to StdioFile; it consumes a PlatformApi slot; callers include several feature modules.
- Evidence against: no `this`/field/vtable state, no stream open/read behavior, PlatformApi only owns storage/initialization, and callers are consumers with unrelated feature ownership.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- No new by-file page is needed. Use existing [UID:0000MI] `NexusTK/util/PathUtil.cpp`.
- Likely source contents are this stat-backed helper and separate UID00022K open-backed helper, with declarations in an inferred PathUtil header.
- Do not absorb StdioFile methods or PlatformApi globals.

## Source Placement

- Definition: `NexusTK/util/PathUtil.cpp`.
- Declaration: inferred `NexusTK/util/PathUtil.h` because the six calls originate in five source families.
- Required C runtime type declaration: `<sys/stat.h>` or the project-equivalent header that exposes `_stat64i32` and `_wstat64i32` spelling under the historical compiler.
- Required project dependency: PlatformApi declaration for `g_pfnWideStat`; storage/initializer remain in `NexusTK/platform/PlatformApi.cpp`.
- Rejected placements: `StdioFile.cpp` because there is no object behavior; `FileIO.cpp` because current root is an umbrella; PlatformApi because it owns only the dispatch; feature caller files because caller locality is not ownership.
- Remaining uncertainty is limited to exact historical header filename/include order. It does not block the selected function definition or formal C++.

## Range / Split / Padding / Reclassification Analysis

- Target function occupies the complete half-open range `[0x00582460,0x00582495)` with no child split.
- Seven leading `0xcc` bytes after predecessor end and eleven trailing `0xcc` bytes before successor start are alignment, not target code.
- UID0001IZ must remain the exact-range source emitter.
- UID0000V6 covers the same semantic/binary item and should be reclassified as a non-emitting evidence mirror. It should point to UID0001IZ through `CANONICAL_OWNER:0001IZ` and have blank `EMITTER_UIDS` and formal C++.
- UID00022K remains a separate function and emitter. No merge is recommended merely because both functions answer path-existence questions.
- StdioFile aggregate/method pages remain unchanged; adjacency does not expand their range over this function.

## Negative Evidence Summary

- No original symbol proves `PathExistsViaStat`, `path`, `statBuffer`, or `g_pfnWideStat`; these are bounded human-source inferences.
- No direct pointer table references the function start; all six uses are direct calls.
- No second entry-signature match exists.
- No function/xref exists at exclusive end `0x00582495`.
- No `this` pointer, object field, vtable, stream handle, cached size, or virtual dispatch appears in the target.
- No caller module dominates ownership; the caller spread instead rejects feature-local placement.
- No evidence supports creating explicit source code for the security-cookie operations.
- No evidence supports emitting a local raw `dword_69BE18` declaration or a fabricated wrapper around `g_pfnWideStat`.

## IDA Rename / Type / Comment Recommendations

- Exact live pre-state provenance: healthy read-only MCP session `supervisor_gate2b_0002OT_20260723` on 2026-07-24. B001 used `stack_frame`, `lookup_funcs`, `analyze_function`, `get_global_value`, `entity_query`, and exact-span `search_text` comment readback. No IDA mutation or save was performed.
- Supervisor Gate 2B item 1, target function `0x00582460-0x00582495`:
  - Exact current entity state: modeled function `sub_582460`, start `0x00582460`, size `0x35` / 53 bytes, one block, six code xrefs, and `has_type:true`.
  - Exact current applied declaration/type: `bool __cdecl sub_582460(int)`. The current argument is frame member `arg_0`, offset `0x3c`, size `0x4`, type `_DWORD`; Hex-Rays renders it as `int a1`.
  - Exact current function-comment state: regular function comment absent and repeatable function comment absent. `analyze_function` returns no comment entry at `0x00582460`; exact-span rendered-comment readback shows only IDA's synthetic separator, `Attributes: bp-based frame`, and synthetic declaration line, not a user regular/repeatable function comment.
  - Existing non-function comment to preserve: instruction `0x0058248a` has exact regular comment `StackCookie`; no repeatable comment is returned there. This instruction comment is not the proposed function comment and must remain unchanged.
  - Proposed name: `PathExistsViaStat`.
  - Proposed type: `bool __cdecl PathExistsViaStat(const wchar_t *path)`.
  - Proposed regular function comment: `Returns true when the PlatformApi wide-stat dispatch can query the supplied path. Uses a stack _stat64i32 buffer and preserves the binary's exact success test against -1.` Current regular function comment is absent; current repeatable function comment is absent. Apply as a regular function comment and do not create a repeatable duplicate.
  - Confidence: very strong for signature/behavior, strong inferred for source-facing name.
- Supervisor Gate 2B item 1a, exact stack local at `[ebp-34h]` inside target function range `[0x00582460,0x00582495)`:
  - Exact current frame-member state: IDA frame name `var_34`, frame offset `0x0`, size `0x30`, type `_BYTE[48]`. Hex-Rays renders the same storage as pseudocode local `v2[48]`; `v2` is not the frame-member name.
  - Exact current stack-local comment state: regular stack-member comment absent and repeatable stack-member comment absent; `stack_frame` returns only `name:var_34`, `offset:0x0`, `size:0x30`, and `type:_BYTE[48]`, with no comment text/state for this member.
  - Proposed frame-member name/type: rename `var_34` to `statBuffer` and apply `struct _stat64i32`. Do not create a stack-member comment; the function comment supplies the behavioral explanation.
  - Preserve adjacent frame state exactly: `var_4` at frame offset `0x30`, size `0x4`, type `_DWORD` is the separate security-cookie storage; preserve saved registers, return address, and argument offsets.
- Supervisor Gate 2B item 2, dispatch data `0x0069be18`:
  - Exact current storage/value state: four-byte zero-initialized data; `get_global_value` returns `0x0`.
  - Exact current name/entity state: call operands auto-render the dummy label `unk_69BE18`, but exact-address `entity_query` returns zero `globals` and zero `names`. Therefore no user/global name entity is currently applied at `0x0069be18`.
  - Exact current declaration/type state: absent. No global entity or applied data declaration/type is returned for the exact address; only raw four-byte storage and the auto-rendered dummy label exist.
  - Exact current data-comment state: regular comment absent and repeatable comment absent. Exact-span `search_text` with `include:comments` over `[0x0069be18,0x0069be1c)` returns zero hits.
  - Exact current xrefs: initializer store `0x0041a438`, StdioFile read `0x00582104`, target read `0x00582478`, retained constructor store `0x0059976d`, and retained raw projection store `0x005999a8`; total five.
  - Proposed name: `g_pfnWideStat`.
  - Proposed type/declaration: `int (__cdecl *g_pfnWideStat)(const wchar_t *path, struct _stat64i32 *statBuffer)`.
  - Proposed regular data comment: `PlatformApi wide-stat dispatch slot. NT initialization assigns _wstat64i32; PathExistsViaStat and StdioFile::Open consume it.` Current regular data comment is absent; current repeatable data comment is absent. Apply as a regular data comment and do not create a repeatable duplicate.
  - Confidence: very strong for function-pointer type/role, strong inferred for project-consistent source name.
- Supporting type pre-state:
  - `_stat64i32` already exists and is correct at size `0x30`. Preserve all 11 member offsets and the `0x0e-0x0f` alignment gap; do not create a duplicate UDT.
  - `_wstat64i32` at `0x005e25aa` already has exact current prototype `int __cdecl(const wchar_t *FileName, struct _stat64i32 *Stat)`; no change recommended.
- Collision and boundary pre-state:
  - Entity collision searches return no current `PathExists*` or `WideStat*` function/name collisions. The auto-generated `sub_582460` and `unk_69BE18` labels are the exact current raw names.
  - Preserve target bounds `[0x00582460,0x00582495)`, size `0x35`, all six callers, all five slot xrefs, seven leading and eleven trailing `0xcc` bytes, predecessor `sub_582410`, successor `sub_5824A0`, and no-function/no-xref state at `0x00582495`.
- Items intentionally unchanged: security-cookie global/helper and `StackCookie` instruction comment, initializer functions, retained constructor/raw projection, all six callers, predecessor/successor functions, padding, UID00022K, PlatformApi sibling slots, and existing correct CRT entities.
- Negative constraints: do not create a function at `0x00582495`; do not extend target bounds; do not rename the slot to target-local ownership; do not overwrite existing PlatformApi sibling names/types; do not preserve `_BYTE[48]` after applying the verified `_stat64i32` local type; do not add repeatable duplicates of either proposed regular comment.
- Expected readback: target name/declaration, argument, `statBuffer` frame member/type, and regular function comment applied with size/callers/bounds unchanged; slot name/declaration and regular data comment applied with five xrefs unchanged; decompilation should show `g_pfnWideStat(path, &statBuffer) != -1`; regular/repeatable comment readback must distinguish the new regular comments from absent repeatable comments; IDB save required.
- Action classification: target function apply; stack local apply; dispatch slot apply; `_stat64i32` already present/no change; `_wstat64i32` already present/no change; protected entities no change.
- B001 performed no IDA mutation. The supervisor-owned Gate 2B disposition and saved-IDB evidence are recorded immediately below.

### Supervisor Gate 2B Disposition - 2026-07-24

- MCP and IDB: healthy MCP transport session `ce96437c-ce92-451f-81fb-c77e845eb237`, active database `supervisor_gate2b_0002OT_20260723`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, Hex-Rays ready.
- Pre-mutation backup: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0001IZ-20260724-082619.bak`, 143,184,868 bytes, SHA256 `4F1F76E332E002C8D0CE48742CF3782EBC52E7D40F60FE3081DA203069ABB025`.
- Target function `0x00582460`: `sub_582460` -> `PathExistsViaStat`; `bool __cdecl(int)` -> `bool __cdecl PathExistsViaStat(const wchar_t *path)`; exact proposed regular comment applied; repeatable comment left absent.
- Stack local `[ebp-34h]`: `_BYTE[48] var_34` -> `_stat64i32 statBuffer`; argument readback became `const wchar_t *path`; adjacent `var_4` and frame state were preserved.
- Dispatch slot `0x0069be18`: dummy `unk_69BE18` / no applied global entity -> `g_pfnWideStat`; exact cdecl `_stat64i32` function-pointer declaration applied; exact proposed regular data comment applied; repeatable comment left absent.
- Post-mutation decompilation is `return g_pfnWideStat(path, &statBuffer) != -1;`. Target size remains 53 bytes with six code xrefs. Slot storage remains four zero bytes with the same five xrefs. `StackCookie` at `0x0058248a` remains unchanged.
- IDB save succeeded to the active path. Saved IDB is 143,186,697 bytes, SHA256 `25EB523953ED2443C024108DF4EE9195A15A54B4397F7D38352E970A18FC8798`, write time `2026-07-24T12:28:21.7229554Z`.

## First-Draft C++ Recommendation

- Eligible: yes. Every behavior, type, owner, dependency, duplicate route, and source-placement blocker has an implementation-ready resolution.
- Exact destination formal block for UID0001IZ:

```markdown
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool PathExistsViaStat(const wchar_t *path)
{
    struct _stat64i32 statBuffer;

    return g_pfnWideStat(path, &statBuffer) != -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Exact ownership/range: [UID:0001IZ], `[0x00582460,0x00582495)`, emitted through [UID:0000MI] into `NexusTK/util/PathUtil.cpp`.
- Behavioral fidelity: one stack `_stat64i32`, one indirect cdecl call, and exact non-`-1` boolean predicate. The compiler may reproduce /GS cookie code from the local object; source must not spell cookie internals.
- Human source shape: plain C++03 free function, established PascalCase helper name, descriptive parameter/local names, no raw address labels, no casts, no decompiler temporaries, and no modern syntax.
- Dependencies: `_stat64i32` declaration and PlatformApi `g_pfnWideStat` extern declaration.
- UID0000V6 must retain a blank formal block after reclassification to prevent duplicate emission.
- Third-party import directive: not applicable; this is NexusTK-owned utility code.

## Final Recommendation

- C1IZ-01 through C1IZ-30 are applied and verified in their ordinary-document, supervisor-owned IDA, or supervisor-owned manual coverage destinations.
- UID0001IZ alone contains the formal C++ body and retains owner/emitter UID0000MI.
- UID0000V6 is a detailed non-emitting mirror owned by UID0001IZ.
- PathUtil current-state/source-placement prose and score are synchronized; FileIO, StdioFile, PlatformApi ownership, and UID00022K behavior remain unchanged. Support edits only corrected target-specific cross-references, exact xrefs, and stale current-versus-historical source-placement wording.
- Supervisor Gate 2A, Gate 2B, report execution/archive, and the exact manual coverage replacements are complete.
- No future B-agent investigation is needed to make UID0001IZ source-ready. A later rebuild comparison may improve confidence above 94 but is not a blocker to the first draft.

## Recommended Target Doc Changes

- Path: `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`.
- Applied metadata: `COMPLETION:92`, `CONFIDENCE:94`; `CANONICAL_OWNER:0000MI`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000MI` preserved.
- Applied formal: exact block in this report.
- Applied evidence: exact bytes/hash, UDT layout, ABI, return semantics, full six-call inventory, dispatch-slot initializer/consumer evidence, signature uniqueness, padding, source/header placement, duplicate route, and exact Gate 2B pre-state/action/readback handoff.
- Stale current statements that final dispatch name/type and PathUtil/FileIO split were unresolved are preserved only in dated history; current sections record the evidence-backed resolution.
- Item summary now describes source-ready one-body emission without repeating generated metadata.

## Recommended Support Doc Changes

- `by-item/PathExistsViaStat_00582460.md` [UID:0000V6]: verified `91/94`, owner UID0001IZ, reconstructable false, blank emitters/formal, complete evidence mirror, and preserved history at SHA `3CA4E048...6DEC`.
- `by-file/PathUtil.md` [UID:0000MI]: verified `90/92`, standalone `PathUtil.cpp` current route, target formal/dependencies/duplicate route, and historical compact alternatives at SHA `CAFC6572...6DAA`.
- `by-file/FileIO.md` [UID:0000JD]: unchanged after read-only verification; its non-emitting umbrella and rejected compact route already agree.
- `by-file/StdioFile.md`: corrected one literal stale folding statement, linked UID0001IZ, and preserved StdioFile object-method ownership. StdioFile aggregate UID0001IR remained unchanged after verification.
- `by-memory/0x005820d0-0x005821c9.StdioFileOpen.md`: unchanged after verification; its existing `g_pfnWideStat`/`_stat64i32` formal corroborates this report.
- `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`, `by-global/WideApiDispatchTable.md`, retained constructor UID0004N6, and `by-file/PlatformApi.md`: added the missing canonical UID0001IZ relation and exact five-xref/store details while preserving current formal, owner, score, and source disposition. Live initializer UID0000WD already satisfied the report and stayed unchanged.
- `by-project-structure/proposed-source-tree.md`: replaced the mirror-as-body/still-current-folding wording with canonical UID0001IZ, non-emitting UID0000V6, UID00022K sibling, and historical rejected compact-file theory.
- UID00022K remained unchanged after verification; it is a separate PathUtil sibling outside report coverage.
- Generated/tracker files: never hand-edit. Verify them only after scoped callback validation refresh.

## Score And Metadata Recommendation

- UID0001IZ historical baseline: `87/89`, owner/emitter UID0000MI, reconstructable true, blank formal. Current applied state: `92/94`, owner/emitter unchanged, reconstructable true, populated formal.
- UID0000V6 historical baseline: `87/89`, owner/emitter UID0000MI, reconstructable true, blank formal. Current applied state: `91/94`, owner UID0001IZ, reconstructable false, blank emitter/formal.
- UID0000MI historical baseline: `87/88`. Current applied state: `90/92` with source route and target emission resolved.
- Reason not higher: no original PDB/source lexical proof, exact historical header/include spelling remains inferred, and no rebuilt object/executable comparison has verified code generation. Under the 95 barrier, this draft is appropriately scored below final-source certainty.
- Reason not lower: exact bytes/hash/bounds/CFG, six callers, unique signature, precise UDT, exact dispatch initializer/wrapper, dependency ownership, source placement, duplicate routing, and destination C++ are all resolved.
- Score-improvement work removed every formerly stated blocker: live wrapper/UDT/initializer evidence resolved dispatch type; current PlatformApi formal resolved human declaration; FileIO/source-tree evidence resolved source placement; exact mirror pattern resolved duplicate emission; exact C++ resolves the empty emitter.

## Open Questions With Attempted Resolution

- Original helper name: no symbol exists. Checked entity names, caller semantics, docs, and collision risk. Best resolution is descriptive `PathExistsViaStat`; uncertainty is lexical only.
- Original header filename/include order: no PDB/source exists. Checked cross-module caller spread and current source tree. Best resolution is inferred `PathUtil.h` plus PlatformApi/stat declarations; this does not alter runtime behavior.
- Original compact versus standalone translation unit: checked current PathUtil, FileIO, StdioFile, generated roots, and proposed source tree. Resolution is standalone `PathUtil.cpp`; compact placement is historical/rejected current state.
- Dispatch-slot spelling: checked all initializer stores, `_wstat64i32` wrapper prototype, live UDT, current PlatformApi formal, and StdioFile consumer. Resolution is `g_pfnWideStat`; raw labels are rejected.
- Exact success predicate: checked assembly. Resolution is `!= -1`, not generalized `== 0`.
- Duplicate page: checked metadata/generated markers and established project covered-by pattern. Resolution is one by-memory emitter plus non-reconstructable by-item mirror.
- Remaining unresolved questions: none that block ownership, formal C++, implementation, or score movement. Only original lexical/header proof and rebuild comparison are unavailable and cap confidence below 95.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Inspected `by-memory/-coverage-report.md` UID0001IZ row at current line 3389. Exact replacement:

```markdown
    - [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md) 0x00582460-0x00582495 | function | PathExistsViaStat : reconstructable : 92% : very strong : Exact 53-byte/SHA256-anchored wide-path stat helper with one-block cdecl ABI, 48-byte `_stat64i32` local, exact non-`-1` success predicate, six direct callers, unique entry signature, clean padding, PlatformApi-owned `g_pfnWideStat` dependency, canonical PathUtil.cpp source route, one-body duplicate policy, and source-ready human C++03 formal.
```

- Inspected `by-item/-coverage-report.md` UID0000V6 row at current line 65. Exact replacement:

```markdown
- [UID:0000V6][PathExistsViaStat_00582460](by-item/PathExistsViaStat_00582460.md) : not_reconstructable : 91% : very strong : Non-emitting by-item evidence mirror for canonical source-bearing [UID:0001IZ][0x00582460-0x00582495.PathExistsViaStat](by-memory/0x00582460-0x00582495.PathExistsViaStat.md), preserving the exact 53-byte/hash, six-call-site, `_stat64i32`, `g_pfnWideStat`, PathUtil.cpp, boundary, and rejected-owner evidence while leaving emitter/formal C++ blank to prevent duplicate output.
```

- Inspected `by-file/-coverage-report.md` UID0000MI row at current line 207. Exact replacement:

```markdown
- [UID:0000MI][PathUtil](by-file/PathUtil.md) : reconstructable : 90% : very strong : Canonical `NexusTK/util/PathUtil.cpp` source root for the stat-backed UID0001IZ and open-backed UID00022K wide-path existence helpers, with exact caller spread, PlatformApi dispatch ownership, source/header dependencies, one-body UID0001IZ/UID0000V6 duplicate routing, source-ready PathExistsViaStat formal, and compact FileIO/StdioFile placement retained only as rejected historical layout.
```

- Inspected `by-memory/-coverage-report.md` UID0002AS row at current line 4568. It is stale at `87%` while the source page is `90/90`. Exact replacement:

```markdown
    - [UID:0002AS][0x0069be14-0x0069bec4.WideApiDispatchPointerTable](by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md) 0x0069be14-0x0069bec4 | global-data pointer table | WideApiDispatchPointerTable : reconstructable : 90% : very strong : Source-bearing PlatformApi main wide-dispatch storage with 44 zero-initialized dwords, all initializer assignments and representative consumers revalidated, grouped human function-pointer declarations including `g_pfnWideStat`, exact sibling/tail boundaries, and rejected raw-dword, consumer-owned, and forced-struct alternatives.
```

- Inspected UID00022K, UID0000TQ, and UID0000JD manual rows. They need no target-driven replacement: their current state remains separate PathUtil sibling, PlatformApi global owner, and non-emitting FileIO umbrella respectively.
- B001 must not apply these rows. Manual `-coverage-report.md` files are supervisor-owned collision points and are updated only after report execution under the binding workflow.

## Follow-Up Actions

- Supervisor Gate 1 passed exact SHA `DA34CF03976E873EF9D9566EEC54AA651BF2C87FE68F7375ADBC2A7FB34ADDA0`; B001 callback implementation and own readback are complete.
- Supervisor Gate 2A completed: all applied claims/destinations, formal block, generated marker counts, validator results/warnings, current hashes, and released leases were independently verified.
- Supervisor Gate 2B completed: exact target function, argument, stack local, dispatch slot, and regular comments were applied/read back; every protected entity and comment-state distinction was preserved; the IDB was saved after backup.
- Supervisor lifecycle completed in the required order: Gate 2 passed, validator command `17125` executed/archived the report, then commands `17128`-`17130` validated the exact C1IZ-29 manual coverage replacements.
- No A-agent action.
- No further B001 action unless supervisor Gate 2A identifies a concrete documentation or report defect.

## Confidence

- Recommendation confidence: very strong for behavior, ABI, type, dispatch role, source owner, one-body policy, and C++.
- Score confidence: strong; `92/94` reflects source-ready evidence without claiming original lexical/rebuild proof.
- Remaining uncertainty: exact original helper/header spelling and final compiler-output equivalence only. Neither is a valid reason to retain raw names or blank C++.

## Validator Results

- Gate 1 passed exact report SHA256 `DA34CF03976E873EF9D9566EEC54AA651BF2C87FE68F7375ADBC2A7FB34ADDA0` before this resumed callback.
- Preserved successful validator `000000017083`: `python .\tools\validator.py --mode file --file by-item\PathExistsViaStat_00582460.md --apply --queue-timeout 240`; exit `0`, `ok:1`. Exact callback readback found no repair necessary at SHA `3CA4E048...6DEC`.
- Preserved successful validator `000000017086`: `python .\tools\validator.py --mode file --file by-file\PathUtil.md --apply --queue-timeout 240`; exit `0`, `ok:1`. Exact callback readback found no repair necessary at SHA `CAFC6572...6DAA`.
- Callback validator `000000017088`, timestamp `2026-07-24T08:06:05-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x00582460-0x00582495.PathExistsViaStat.md --apply --queue-timeout 240`; exit `0`, `ok:1`, target `92/94`, generated refresh deferred.
- Callback validator `000000017089`, timestamp `2026-07-24T08:06:43-04:00`: `python .\tools\validator.py --mode file --file by-file\StdioFile.md --apply --queue-timeout 240`; exit `0`, `ok:1`, two expected reference-index additions.
- Callback validator `000000017090`, timestamp `2026-07-24T08:07:25-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --apply --queue-timeout 240`; exit `0`, `ok:1`, two expected reference-index additions.
- Callback validator `000000017091`, timestamp `2026-07-24T08:08:03-04:00`: `python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply --queue-timeout 240`; exit `0`, `ok:1`.
- Callback validator `000000017092`, timestamp `2026-07-24T08:08:39-04:00`: `python .\tools\validator.py --mode file --file by-memory\0x005995b0-0x005997dd.UniAPIInitConstructor.md --apply --queue-timeout 240`; exit `0`, `ok:1`, two expected reference-index additions.
- Callback validator `000000017093`, timestamp `2026-07-24T08:09:43-04:00`: `python .\tools\validator.py --mode file --file by-file\PlatformApi.md --apply --queue-timeout 240`; exit `0`, `ok:1`. It retained three pre-existing `missing_ref_uid 0003OT` warnings and added expected UID0000MI/UID0001IT/UID0001IZ references; no target-specific failure occurred.
- Callback validator `000000017094`, timestamp `2026-07-24T08:10:26-04:00`: `python .\tools\validator.py --mode file --file by-project-structure\proposed-source-tree.md --apply --queue-timeout 240`; exit `0`, `ok:1`. It retained five pre-existing missing-reference warnings for UIDs `0003LP`, `0003WL`, `0003WM`, `0003WN`, and `0003WO`; no target-specific failure occurred.
- Every callback validator reported `projected_stats_update:1` and deferred generated refresh. No validator cleared an Item Summary.
- Waited generated readback is authoritative for PathUtil command `000000017088`: SHA256 `3668BCE8646D4FD97521899C15D0AD3CF6C3702B32619D8FEC8C80C431E73158`, 658 bytes, 16 lines, one UID0001IZ body, zero UID0001IZ/UID0000V6 empty markers, and one unchanged UID00022K empty marker.
- B001 ran no report lifecycle, execution, registry, or coverage command.
- Supervisor Gate 2A reran all seven changed ordinary-document validators successfully as commands `000000017110` through `000000017117` (command `17114` was used by unrelated concurrent work). PlatformApi retained the same three pre-existing `0003OT` warnings; proposed-source-tree retained the same five pre-existing `0003LP`/`0003WL`/`0003WM`/`0003WN`/`0003WO` warnings. Every scoped pass exited `0` with `ok:1`.
- Generated PathUtil readback after supervisor command `000000017110`: SHA256 `7D7F74279D57F283E7526149D0EECE8193DDA8FD7551473901334633C8CCB523`, one UID0001IZ body, no UID0001IZ/UID0000V6 empty marker, and one unchanged UID00022K empty marker. The hash changed from the callback artifact only because the generated validator command/timestamp header advanced.
- Three shared support hashes advanced after B001's callback because later validator reference-index work touched them: UID0002AS is now `1D699D33F81430AAB531E44271461BE5FD458235EA3D41584855070746B0CAE5`, UID0000TQ is now `8FFFB41B2A23679235A581C03D3CB4FE2C847E4C5A0E6762BECF427D4CA0C226`, and UID0001R1 is now `EBD435494BFDF625E3D5792A81AD45078E7E8C37A98950625770A127DC8B37AD`. Independent content readback found the accepted UID0001IZ claims still present at equal or greater detail.
- Supervisor Gate 2B applied and read back C1IZ-26 and C1IZ-27, verified C1IZ-28 protected state, and saved the IDB. Validator command `17125` then executed the report, and commands `17128`-`17130` validated the completed C1IZ-29 manual coverage work.
- Coverage validation details: by-memory command `17128` exited `0`, `ok:1`, with four unrelated pre-existing missing-reference warnings and one expected reference-index removal; by-item command `17129` exited `0`, `ok:1`, with three unrelated pre-existing missing-reference warnings and the expected UID0001IZ add/UID0000MI removal; by-file command `17130` exited `0`, `ok:1` without missing-reference warnings.

## Changed Files

- Updated same report: `tools/leaser/Agents/Agent-B001/research/0001IZ-PathExistsViaStat-empty-emitter-source-quality.md`.
- Changed/validated target: `by-memory/0x00582460-0x00582495.PathExistsViaStat.md`, SHA256 `D04135DF3BD0772749D5B5BAF75CD65DF608A2F1CECB5AA2F38D87591B1505AB`, validator `000000017088`.
- Changed/validated support: `by-file/StdioFile.md`, SHA256 `40C9619C08B048166F251D94AA197020D96B288ED3CFEE42A834F3E0D62810D2`, validator `000000017089`.
- Changed/validated support: `by-memory/0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md`, SHA256 `18967F767B694BA59C5D183944391C265C2BC6B13E31FE27AEF23091E56ABD61`, validator `000000017090`.
- Changed/validated support: `by-global/WideApiDispatchTable.md`, SHA256 `B1F5A4D51A9279DA938541640D71ED00E71118E4A7E56360B228D71495F53D32`, validator `000000017091`.
- Changed/validated support: `by-memory/0x005995b0-0x005997dd.UniAPIInitConstructor.md`, SHA256 `A6EEF5B0DBFE4D3FDE35364C16A23133D2DB2E616B43BA76611CABBA7B3B4F27`, validator `000000017092`.
- Changed/validated support: `by-file/PlatformApi.md`, SHA256 `B4CD9271E548E712A359CE8B1651FC8249CE40313EC02274C1AFCB0505572CF1`, validator `000000017093`.
- Changed/validated support: `by-project-structure/proposed-source-tree.md`, SHA256 `2308990FEDA70D3FEEA353A7992C2737139D320686EFA8FB3FC3FB8121988614`, validator `000000017094`.
- Unchanged after exact callback readback: UID0000V6 `by-item/PathExistsViaStat_00582460.md`, SHA `3CA4E048D0CE7356C3AB1F567A616420464D657309C7B1D007D303C85E766DEC`; UID0000MI `by-file/PathUtil.md`, SHA `CAFC65728B9F41734AD6CFCA9A696612CF9005489EADC2B292F0940A631B6DAA`; UID0000JD `by-file/FileIO.md`, SHA `CA730C89F50433E46DDEDED87E34EE1269717F0BBA66D6EF279FC4377EA1372E`; UID0001IR aggregate, SHA `235E0A98CF21BF40FE4B51F51796CC646AB40AC79072B98286663B8B9A8EA1EA`; UID0001IT StdioFileOpen, SHA `09607ED09B43C527D7AAE63526A9B6AA5CEC50B9FCD4C1356DD7733DC673D3A7`; UID0000WD initializer, SHA `0D1931327A8AFFBDA7653E67A4835928AEE529C5DF0916B72DD60BFA16568EEA`; UID00022K FileExists, SHA `87044F3600C7394B766AEEDB2DA88E80CB82F1F37349AB1697ACA4D31294E608`.
- Validator-generated, never hand-edited: `auto-generated/NexusTK/util/PathUtil.cpp`, SHA256 `3668BCE8646D4FD97521899C15D0AD3CF6C3702B32619D8FEC8C80C431E73158`, command `000000017088`.
- Renamed: none.
- IDA mutation: none; B001 used MCP read-only.
- Supervisor-owned IDA mutation after callback: applied and verified the accepted target function, stack local, argument, dispatch-slot type/name, and regular comments; saved the active IDB at SHA256 `25EB5239...8798` after backup SHA256 `4F1F76E3...025`.
- Reverted/deleted ordinary files: none.
- Leases: each changed ordinary file was leased immediately before its edit and released immediately after its serial validator. B001 has no active lease at the final B001 checkpoint; any concurrent supervisor lease is outside this callback and is not claimed as B001 state.
- Coverage/generated/audit/supervisor/goal/validator/lifecycle files manually edited by B001: none.
- Report execution: not run. B001 did not run, probe, dry-run, or invoke `execute_report` or any lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Fresh supervisor Gate 1 passed exact report SHA `DA34CF03...ADDA0` before callback resumption.
- [x] UID0001IZ, UID0000V6, and UID0000MI preserved partials reviewed claim by claim; target repaired, mirror/PathUtil accepted unchanged.
- [x] Every declared UID is scoped correctly: only UID0001IZ is report coverage; support UIDs remain support-only.
- [x] Current target/mirror/file-root metadata, hashes, formals, routing, and history read back by B001.
- [x] Claim And Incorporation Ledger ordinary claims advanced only after destination readback.
- [x] Metadata/scores verified: UID0001IZ `92/94`, UID0000V6 `91/94`, UID0000MI `90/92`.
- [x] Score-limiting blockers researched and resolved to implementation-ready human source.
- [x] Owner/emitter/reconstructable disposition verified: UID0001IZ sole body, UID0000V6 non-emitting mirror, UID0000MI file root.
- [x] No range split, rename, or new child required; duplicate by-item reclassification verified.
- [x] Source placement, range/padding, duplicate route, and historical alternatives incorporated at report-level detail.
- [x] Supervisor Gate 2B handoff contains exact addresses/ranges, current names/declarations/types/local state, current regular/repeatable comments, actions, constraints, and readback requirements.
- [x] UID0001IZ formal C++ and UID0000V6 blank-formal disposition verified.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support facts incorporated or independently confirmed already present at equal/greater detail.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Stale Wave2/Wave3 material rejected as authority.
- [x] Open questions closed or bounded to lexical/header/rebuild-comparison uncertainty.
- [x] Validators `17083`, `17086`, and callback commands `17088`-`17094` read back with exact results/warnings.
- [x] Generated SHA `3668BCE8...3158` callback state and later command `17110` refresh were read back; exact manual coverage payloads were subsequently applied and validated.

Implementation callback pass:
- [x] B001 applied no IDA mutation; all IDA work remains supervisor-owned.
- [x] Fresh report artifact accepted by supervisor after the prior Gate 1 revocation.
- [x] Preserved ordinary partials reviewed claim by claim without deleting history.
- [x] All fourteen exact target/support destinations inspected; seven changed/validated and seven accepted unchanged at recorded hashes.
- [x] Ledger rows C1IZ-01..25 and C1IZ-30 were marked `APPLIED_VERIFIED` only after B001 readback; supervisor closed C1IZ-26..28 with IDA readback/save evidence and C1IZ-29 with exact manual coverage validation.
- [x] Metadata, scores, owner/emitter route, mirror reclassification, and C++ disposition verified.
- [x] Historical assumptions, rejected alternatives, and negative evidence confirmed preserved.
- [x] Open questions retained as resolved/bounded current truth.
- [x] Scoped validator command IDs/results/warnings and final no-active-B001-lease state recorded.
- [x] Generated PathUtil confirms one UID0001IZ body, no UID0001IZ/UID0000V6 empty markers, and UID00022K unchanged/outside report coverage.
- [x] All supervisor Gate 2, execution/archive, and manual coverage work completed in the required order.

Supervisor-only remaining items:
- [x] Gate 2A independently verified all applied claims, current destination hashes, validator warnings, generated readback, and released leases; three shared support hashes were newer but retained equal-or-greater accepted detail.
- [x] Gate 2B applied/read back the target function, stack local, argument, and dispatch-slot actions, preserved protected entities, and saved the IDB after a timestamped backup.
- [x] Supervisor executed/archived this report through validator command `17125` after Gate 2A and Gate 2B passed; B001 ran no lifecycle command.
- [x] Supervisor applied the exact C1IZ-29 manual coverage replacements after execution and validated them as commands `17128`-`17130`.

EXECUTED_AND_COVERAGE_APPLIED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000017125","destination_path":"executed-b-agent-research/B001/0001IZ-PathExistsViaStat-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B001/research/0001IZ-PathExistsViaStat-empty-emitter-source-quality.md","timestamp":"2026-07-24T08:33:51-04:00","uid":"0001IZ"} -->
<!-- {"agent":"B001","command_id":"000000017135","details":"post-execution content change accepted; size/hash refreshed","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001IZ-PathExistsViaStat-empty-emitter-source-quality.md","timestamp":"2026-07-24T08:37:37-04:00","uid":"0001IZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
