** TARGET-REPORT-UID:0003A4 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# UID0003A4 BlitSurfaceToDisplay Empty-Emitter Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: retain the callback-applied `ScreenPane` class/source route, complete `void ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)` formal body, and `93/94` target score. Supervisor Gate 2B is `APPLIED_VERIFIED`; return this post-Gate-2B reconciled exact artifact to fresh supervisor Gate 1 review, then proceed to supervisor-only execution/archive and post-execution manual coverage.
- Final disposition: one complete source-authored `ScreenPane` method over `0x005595d0-0x00559a0f`; no split, merge, ignored executable subrange, or no-code disposition is justified.
- Current callback state: supervisor Gate 1 passed exact pre-callback SHA `E24945806424801CD81C66D496C44373F3C95D2407B77F03A860305498CC4B3F`; B002 applied and validated C3A4-001 through C3A4-018 and verified C3A4-021. Fresh post-callback Gate 1 rejected SHA `81D9563E486451B845CFF1AC9BAD97288572692A8321F0F81173EFFFD398AC90` because three Gate 2B rows did not state every post-action comment channel separately. The next exact artifact, SHA `86C31DD6FD1A0D8DD2D5E114C1A32564AD5EC2A311BEDF5AA10A3E1F96CFF63B`, was rejected for stale validator-phase wording, a non-auditable protected `0x0069b3d4` disposition, and an overbroad retry claim. Those defects were repaired, prerequisite supervisor Gate 1 and Gate 2A passed, and supervisor Gate 2B C3A4-019 is now `APPLIED_VERIFIED`. This post-Gate-2B reconciliation requires fresh exact-artifact Gate 1 review. C3A4-020 manual coverage and report execution/archive remain supervisor-owned and pending.
- Confidence: very strong for behavior, receiver, parameters, field layout, source route, boundaries, and draft C++; strong for inferred original member/global spellings.

## Supporting Research

- Assignment-time history: this report began as the report-only artifact for B002 UID0003A4; before Gate 1, no implementation callback, validator, IDA mutation, lifecycle command, or manual coverage edit had occurred.
- Current implementation state: after supervisor Gate 1 acceptance, B002 completed the ordinary-document callback under commands `17259`, `17260`, `17262`, `17265`, and `17267` through `17272`. B002 did not mutate IDA, edit manual coverage, or run/probe any report lifecycle command.
- The active project skill, current B-agent workflow, literal report template, assignment `goal.md`, target page, parent aggregate, ScreenPane/Surface/Application support pages, generated outputs, research tracker, and manual coverage reports were read before finalizing this report.
- IDA MCP was mandatory and healthy. A fresh `idb_list` returned active non-analyzing NexusTK database session `1ce787ed`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `16896`; `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x00400000`, Hex-Rays ready, and string cache ready with 2067 strings. B002 made no process-control or IDA mutation call.
- Fresh post-callback Gate 1 repair recheck: `idb_list` at local session timestamp `2026-07-24T11:17:47.408676` again returned the single active, non-analyzing session `1ce787ed`; bounded `server_health`, `lookup_funcs`, `analyze_function`, `get_comments`, `entity_query`, `get_global_value`, and `get_bytes` calls re-read `0x005595d0`, `0x0067a93c`, and `0x0066d40c` read-only after B003's later save. The exact saved-IDB continuity checkpoint at this recheck is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,187,026 bytes, last write `2026-07-24T10:57:57.6474369-04:00`, SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`; later unrelated supervisor saves may advance the shared IDB while preserving this checkpoint evidence.
- Latest Gate 1 repair recheck: fresh `idb_list` at local session timestamp `2026-07-24T11:26:25.003546` still returned only active session `1ce787ed`; `server_health` was `status:ok`, Hex-Rays/string cache ready. Read-only `inspect_items`, `list_globals`, `entity_query`, `get_bytes`, `get_global_value`, `get_comments`, `xrefs_to`, and full bounded `disasm` independently revalidated protected item `0x0069b3d4` and all three presentation/retry paths. The saved-IDB checkpoint remained `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,187,026 bytes, last write `2026-07-24T10:57:57.6474369-04:00`, SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`; B002 made no IDA mutation.
- Supervisor-owned Gate 2B completed after prerequisite Gate 1 and Gate 2A. The supervisor backed up the pre-mutation database to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0003A4-20260724-114534.bak` at pre-SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`, applied and read back the function, two globals, and six instruction-comment actions, independently verified protected `0x0069b3d4` unchanged, and saved the IDB at `2026-07-24T11:48:53.8873820-04:00`, 143,187,027 bytes, SHA256 `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99`. This is the exact UID0003A4 Gate 2B checkpoint; later unrelated supervisor saves may advance the shared IDB while preserving these `APPLIED_VERIFIED` and `NO_CHANGE_VERIFIED` states. B002 did not mutate IDA.
- The exact input executable is `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, 2,679,296 bytes, SHA256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`.
- The target did not have an existing active B report; repository search found only the current assignment reference in B002 `goal.md`.

## Target

- Target UID: `0003A4`.
- Additional target UIDs: none.
- Declared-target inventory: [UID:0003A4] `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`, one modeled display-presentation method currently leaving an Empty Emitter Marker.
- Target path: `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, Files With Empty Emitters / reconstructable, assignment-time `87/89`, tracker counts `0/0/0`.
- Current supervisor classification: reconstructable source-authored empty emitter requiring exhaustive ownership, source-quality, C++, and IDA-handoff resolution.
- Assignment-time scores and parent state: `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank position and formal C++.

## Current Target State

- Assignment-time metadata and prose classified the body as a Surface helper because it uses DirectDraw and was split from the mixed SurfacePresentation address aggregate. That historical route sent UID0003A4 to [UID:0000OC] and produced one Surface.cpp Empty Emitter Marker.
- Assignment-time target checkpoint: SHA256 `BA957DD204ED2DF45BC3C39FD0B274DA012979285C5BB503C96F2583E775B64A`, 6,958 bytes / 81 lines. Assignment-time generated checkpoints were `render/Surface.cpp` SHA256 `740749031B81251E2EB32C8AE0D70C41C20433963B2ACB5B455FA439CC1258BC`, 45,674 bytes / 1,395 lines, one UID0003A4 empty marker, and `ui/core/ScreenPane.cpp` SHA256 `71E600E3B4781718DDB3CB897BBCC56DA9F018CCA396FB44192C459133BBF323`, 17,218 bytes / 546 lines, zero target occurrences.
- Assignment-time open questions were receiver identity, return type, arguments, mode polarity, conversion details, DirectDraw/GDI selection, Application geometry, final globals, owner/emitter route, source placement, and blank C++. The accepted research and callback resolve each to implementation-ready state.
- Current callback-applied target: SHA256 `DFEAB69C0AF272C15DFE74CE1C635F5FB5F577AB8FF142B773EEA63488185367`, 19,505 bytes / 270 lines; metadata is `93/94`, owner/emitter UID0000CB, reconstructable true, blank position, complete formal, and `Nested:0`.
- Current generated readback: `ui/core/ScreenPane.cpp` SHA256 `1F503F0BF5D4A51AD5F4B7B909F5187427866A546A3F4D7C5F378C18C685E46C`, 23,465 bytes / 692 lines, one UID0003A4, one `ScreenPane::BlitSurfaceToDisplay`, and zero target empty markers; `render/Surface.cpp` SHA256 `8B290D49FC028B30F43F4BD4F9A0AF5A4024D2E9052672B4A933C68E3D6284B7`, 45,543 bytes / 1,392 lines, zero UID0003A4 occurrences.
- The stale sentence that ScreenPane has "no ownership signal" is contradicted by the live typed receiver, all four caller argument sets, and direct `ScreenPane` fields `+0x100/+0x104`; it must be preserved only as a historical rejected assumption.
- Current artifact/lifecycle status: ordinary implementation, scoped validation, prerequisite supervisor Gate 1 and Gate 2A, and supervisor Gate 2B C3A4-019 are complete. This report-only Gate 2B reconciliation requires fresh exact-artifact supervisor Gate 1 review before supervisor-only execution/archive. Post-execution manual coverage C3A4-020 remains pending and outside B002 authority.

## Executive Recommendation

- Direct owner: [UID:0000CB] `by-class/ScreenPane.md`.
- Source emitter route: [UID:0000CB] through [UID:0000NB] `by-file/ScreenPane.md` into `NexusTK/ui/core/ScreenPane.cpp`.
- Source-facing method: `void ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)`.
- Keep the exact target path and address range. Change metadata to `93/94`, owner/emitter `0000CB`, reconstructable true, blank optional position, `Nested:0`, and the complete managed formal below.
- Surface remains a dependency and historical presentation-neighborhood bucket, not the owner of this method. DirectX, Application, GDI, and pixel-format globals remain dependency/storage owners.
- The target has no remaining behavioral or source-placement blocker. Exact original spellings are inferred with high probability and cap the score below final-audit territory; they do not justify raw IDA labels or blank C++.

## Supervisor Active Recheck

- The supervisor assigned the next reconstructable Empty Emitter target and required report-only research under the current B-agent skill.
- Split repair is not required: live IDA models one function from `0x005595d0` through exclusive end `0x00559a0f`, followed by exactly one alignment byte.
- The source-bearing body is fully covered by UID0003A4. The successor raw helper begins at `0x00559a10` under existing UID00023S and is not absorbed.
- Every target blocker named in the assignment was investigated. None is deferred as "needs investigation" or "final C++ later."

## Inference Research Guidance Check

- Binary facts, documentation statements, and source-shape inferences are separated throughout this report.
- Existing Surface ownership was treated as a provisional split-era classification, not authoritative fact. Exact receiver fields and caller contracts outweigh address-neighborhood and dependency naming.
- The method/global names are selected from project naming conventions, exact registry value names, typed object layout, and observed behavior. Final source uses no `sub_`, `dword_`, `unk_`, raw array-index, or decompiler temporary names.
- Runtime behavior is preserved exactly, including weak error checking and one-shot lost-surface retries only in the converted windowed DrawType-1 `Blt` and exclusive `BltFast` paths; the ordinary non-32-bit windowed `Blt` result remains intentionally ignored with no restore/retry. Source shape is reconstructed as plausible human-written mid-2000s DirectDraw/GDI C++.
- Historical Wave2/Wave3 references were found in `by-memory/-report.old.md`; they were ignored as stale. Its `FolderTreePane` owner and `int` signature are rejected by current live evidence.

## Heuristic / Inference Reanalysis And Validation

- Receiver: inferred `ScreenPane *` with very-strong confidence. The function reads receiver slots `+0x100` and `+0x104`, both exact members of the live 0x5b4-byte `ScreenPane` UDT, and all four callers use the same ScreenPane object.
- Method name: `BlitSurfaceToDisplay` is descriptive rather than symbol-proven, but it is already the stable project name and precisely covers all DirectDraw/GDI presentation paths. `PresentSurface`, `CopySurfaceToPrimary`, and the stale `FolderTreePane::BlitSurfaceToDisplay` were considered; the current name best matches project vocabulary without narrowing away GDI/stretch behavior.
- Return type: source-facing `void` is preferred. All four callers discard EAX, and each machine return simply preserves the latest DirectDraw/GDI call result after local error handling. `HRESULT`/`int` remains ABI-compatible at call sites but would falsely imply a consumed status contract.
- First parameter: `LPDIRECTDRAWSURFACE sourceSurface`; callers pass either the inherited GrafPort surface at `ScreenPane+0x18` or `m_renderSurface` at `+0x108`, and the body calls DirectDrawSurface methods on it.
- Second parameter: `RECT *sourceRect`; entry copies exactly 16 bytes, full-screen callers pass `{0,0,g_screenWidth,g_screenHeight}`, clipped callers pass a dirty rectangle, and the function uses `left/top` for `BltFast`. Non-const spelling is preferred because the legacy DirectDraw API accepts `LPRECT` without source casts.
- `0x0067a93c`: existing `ApplicationActiveGate` is too broad and semantically wrong for this consumer. `Application::Initialize` derives it from registry `DisplayMode`, value 1 takes `DDSCL_NORMAL`/windowed presentation, value 0 takes exclusive display mode and `BltFast`. Best name is `g_isWindowedDisplayMode`; storage remains four-byte `int`.
- `0x0066d40c`: exact registry value `DrawType`, initial value 1, accepted values 1..3, and target mode dispatch resolve the existing raw label. Preserve the already emitted project name `g_displayStartupDrawType`; type remains four-byte `int` rather than inventing an unproven binary enum type.
- `0x0069b3d4`: existing name `g_surfaceUses32BitPresentation` is validated. Its one-byte storage is set only for the 32-bit display mode and gates the RGB565-to-32-bit copy. No rename is needed.
- Application fields `+0xa58/+0xa5c/+0xa60/+0xa64`: best descriptive names are `m_windowTop`, `m_windowLeft`, `m_windowHeight`, and `m_windowWidth`. Their order is proven by destination rectangle construction and BitBlt/StretchBlt arguments. A `RECT` field is rejected because storage order is top/left/height/width, not RECT left/top/right/bottom.
- RGB conversion: each 16-bit RGB565 pixel expands to `((pixel & 0xf800) << 8) | ((pixel & 0x07e0) << 5) | ((pixel & 0x001f) << 3)`. Low-order channel bits are not replicated and alpha remains zero. Loop counters are 16-bit and pitches are divided by 2/4.
- Error behavior: Lock must equal `DD_OK`; destination Lock failure still causes source Unlock; GetDC results are unchecked; no status propagates to callers. Recovery is path-specific: converted windowed DrawType-1 `Blt` at `0x00559847` compares its result at `0x0055984a`, restores at `0x0055985e`, and retries once at `0x0055987f` only for `DDERR_SURFACELOST`; exclusive `BltFast` at `0x005599d1` compares at `0x005599d4`, restores at `0x005599e4`, and retries once at `0x005599f9` only for that same error. The ordinary non-32-bit windowed `Blt` at `0x005599a9` falls directly into the return epilogue at `0x005599ac`, so its HRESULT is ignored and it never restores or retries.
- Source placement: a private ScreenPane implementation in `ui/core/ScreenPane.cpp` is stronger than Surface.cpp because it consumes ScreenPane-owned DirectDraw fields and is called only from ScreenPane presentation methods. Surface provides callback globals and pixel-format dependencies only.

## Evidence Standards Used

- Direct evidence: current IDA MCP function lookup, decompilation, disassembly-derived call sites, xrefs, raw bytes, comments, UDT/type layout, globals, and collision checks.
- Corroborating evidence: exact by-memory/class/file/global docs, parent aggregate inventory, generated output, manual coverage rows, and research tracker.
- Negative evidence: no alternate callers, no data/pointer owner route, no FolderTreePane receiver, no function split, no second executable byte at the end, no status consumer, no existing collisions for proposed IDA names, and no RGB low-bit replication.
- The evidence ladder favors typed receiver and caller argument identity over adjacency, generated bucket names, or legacy reports.
- Confidence remains below 95 because original symbol/member spellings and the source declaration visibility of the four Application fields are inferred, not recovered from symbols.

## Evidence Checked

- IDA MCP: fresh `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, address-bearing `decompile`, full bounded `disasm`, `xrefs_to`, `get_bytes`, `get_global_value`, `entity_query`, `list_globals`, `inspect_items`, `type_inspect`, `get_comments`, and collision searches.
- Exact target bytes: 1,087 bytes, SHA256 `69A8F9C4C1C5F32131968F8F55593208CE8DBE30CF843DC15578A6011AB18D2B`.
- Boundaries: predecessor alignment through `0x005595cf`, modeled entry at `0x005595d0`, machine `retn 8` ending before `0x00559a0f`, one `0xcc` at `0x00559a0f`, raw successor prologue at `0x00559a10`.
- Documentation: UID0003A4, UID0001G6, UID0003A3, UID00039P/Q/R/T/W/Z, UID00023S, UID0000CB, UID0000NB, UID0000OC, UID00028Z, UID00035N, UID00029U, UID00000D, UID0000HG, generated ScreenPane.cpp/Surface.cpp, research tracker, and manual class/file/memory coverage.
- Negative checks: proposed IDA names have zero collisions; no additional active UID0003A4 report exists; no caller uses EAX; no source field write occurs in the target; no padding is included in the function.
- Phase distinction: the initial report-only research phase ran no validator and made no ordinary-document or IDA mutation. After supervisor accepted the pre-callback artifact, the later implementation callback ran scoped ordinary-document validators `17259`, `17260`, `17262`, `17265`, and `17267` through `17272`, exactly as recorded under `## Validator Results`; every command exited `0` with `ok:1`. IDA remained read-only during the initial research, implementation callback, and both Gate 1 repair passes.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C3A4-001 | 0003A4 | Exact modeled body is 0x005595d0-0x00559a0f, 1,087 bytes, with one-byte successor padding. | very strong | lookup, bytes, hash, neighboring UID0003A3/00023S | target Address Range / Evidence | replace terse boundary record | implemented/read back; validator 17259 ok |
| C3A4-002 | 0003A4 | Receiver is ScreenPane and ABI is thiscall with two stack arguments and `retn 8`. | very strong | live UDT, decompile, caller assembly, epilogue | target Signature / Ownership | add exact ABI and receiver proof | implemented/read back; validator 17259 ok |
| C3A4-003 | 0003A4 | Exactly four calls originate in 0x557140 and 0x5583a0, passing inherited/render surfaces and full/dirty RECTs. | very strong | xrefs and both caller decompiles | target Caller Inventory | incorporate all four calls | implemented/read back; validator 17259 ok |
| C3A4-004 | 0003A4 | Zero display-mode global selects exclusive BltFast with one lost-surface restore/retry. | very strong | target decompile/disassembly | target Behavior | add exact branch | implemented/read back; validator 17259 ok |
| C3A4-005 | 0003A4 | Nonzero display mode selects windowed presentation; the non-32-bit path calls primary Blt using the copied destination RECT, ignores that call's HRESULT, and performs no lost-surface restore/retry. | very strong | `0x00559615 -> 0x00559993`, Blt at `0x005599a9`, immediate epilogue at `0x005599ac` | target Behavior | add exact branch and explicit no-retry limitation | implemented/read back; validator 17259 ok |
| C3A4-006 | 0003A4 | 32-bit path locks source/offscreen surfaces and expands RGB565 without low-bit replication using exact pitches and WORD counters. | very strong | body, DDSURFACEDESC layout | target Behavior / Formal C++ | add exact conversion | implemented/read back; validator 17259 ok |
| C3A4-007 | 0003A4 | DrawType 1 uses DirectDraw Blt; 2 uses GDI COLORONCOLOR; 3/fallback uses HALFTONE. | very strong | DrawType registry/write and target branches | target Behavior; UID00035N | resolve mode semantics | implemented/read back; validators 17259/17269 ok |
| C3A4-008 | 0003A4 | Lock/GetDC/Unlock/Restore error behavior and cleanup order are intentionally weak: only converted DrawType-1 Blt and exclusive BltFast test for `DDERR_SURFACELOST`, restore unchecked, and retry once; ordinary non-32-bit windowed Blt ignores its HRESULT and never retries. | very strong | exact control flow at `0x00559847-0x0055987f`, `0x005599a9-0x005599ac`, and `0x005599d1-0x005599f9` | target Error Semantics / Formal C++ | document and emit exact path-specific behavior | implemented/read back; validator 17259 ok |
| C3A4-009 | 0003A4 | Canonical owner/emitter is UID0000CB ScreenPane, not UID0000OC Surface. | very strong | receiver, fields, caller family | target metadata / ownership | reroute owner/emitter | implemented/read back; validator 17259 ok |
| C3A4-010 | 0003A4 | Target is eligible for complete first-draft C++ and should score 93/94. | strong | closed behavior and dependencies | target header/formal/score | insert managed block | implemented/read back; validator 17259 ok |
| C3A4-011 | 0000CB | ScreenPane class must declare the private method and record exact +0x100/+0x104 use. | very strong | UDT and target body | by-class/ScreenPane.md | support synchronization | implemented/read back; validator 17260 ok |
| C3A4-012 | 0000NB | ScreenPane.cpp is the method-definition source route. | very strong | exact method family and file history | by-file/ScreenPane.md | replace provisional bucket caveat for target | implemented/read back; validator 17262 ok |
| C3A4-013 | 0000OC | Surface.cpp becomes dependency/history context for UID0003A4, not emitter. | very strong | rejected owner analysis | by-file/Surface.md | historicalize old route | implemented/read back; validator 17265 ok |
| C3A4-014 | 0001G6 | Mixed aggregate child row must show ScreenPane route and 93/94. | very strong | exact child analysis | SurfacePresentation child table | update row only; parent stays non-emitting | implemented/read back; validator 17267 ok |
| C3A4-015 | 00028Z | Second dword is windowed-display-mode state, best named g_isWindowedDisplayMode. | very strong | initialize writer plus 18 readers and DirectDraw modes | ApplicationLifecycleFlags | rename formal/prose; 90/94 | implemented/read back; validator 17268 ok |
| C3A4-016 | 00035N | Existing g_displayStartupDrawType name is validated by exact DrawType registry token and 1..3 consumers. | very strong | initialize and target xrefs | DisplayStartupPresentationGlobals | remove raw-name uncertainty; 90/94 | implemented/read back; validator 17269 ok |
| C3A4-017 | 00029U | D4 source flag is a validated one-byte 32-bit-presentation gate consumed at 0x55960e. | very strong | seven xrefs, initializer writers, target | SurfacePixelFormatFlags | add target behavior detail; score unchanged | implemented/read back; validator 17270 ok |
| C3A4-018 | 00000D | Application +0xa58/+0xa5c/+0xa60/+0xa64 are window top/left/height/width. | strong | exact destination-rectangle and GDI arguments | by-class/Application.md | add inferred layout record | implemented/read back in class/file; validators 17271/17272 ok |
| C3A4-019 | 0003A4 | Supervisor Gate 2B renamed/typed/commented the target, two globals, and six instruction heads while preserving the protected dependency state. | strong | supervisor backup, exact per-entity readback, unchanged xrefs/bytes/control-flow, and saved-IDB checkpoint | IDA supervisor handoff | applied after Gate 2A | `APPLIED_VERIFIED`; protected `0x0069b3d4` `NO_CHANGE_VERIFIED`; pre-SHA `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`, post-SHA `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99` |
| C3A4-020 | 0003A4 | Manual memory coverage lacks UID0003A4 and several support rows are stale. | very strong | direct manual report reads | coverage reports | supervisor-only exact text | report-only; pending supervisor |
| C3A4-021 | 0003A4 | Generated result should move from one Surface empty marker to one ScreenPane method and zero target empty markers. | very strong | current generated baselines and route | generated readback after validation | verify after callback | verified: ScreenPane one UID/method, zero empty markers; Surface zero UID |

## Positive Evidence Summary

- Live `ScreenPane` UDT size is 1,460 / `0x5b4`; exact fields used by the target are `m_primarySurface +0x100` and `m_offscreenSurface +0x104`.
- All four direct calls are inside two ScreenPane presentation bodies, and each passes the same ScreenPane receiver plus a valid Surface/RECT pair.
- Target uses the expected ScreenPane presentation dependencies: primary/offscreen DirectDraw surfaces, Application window rectangle, global screen dimensions, pixel-format flag, and startup draw type.
- Exact source branches are closed and mutually consistent across DirectDraw exclusive, DirectDraw windowed, GDI copy/stretch, and 32-bit conversion paths.
- Binary control flow proves the retry asymmetry: only the converted DrawType-1 Blt and exclusive BltFast branches compare against `0x887601c2`, call Restore, and retry; the ordinary non-32-bit windowed Blt has no compare, Restore, or second call before its epilogue.
- Existing ScreenPane docs already identify this target as the display destination user for `m_primarySurface`; current live evidence closes the remaining owner-route question.

## IDA MCP Facts

- Function `sub_5595D0`: start `0x005595d0`, size `0x43f` / 1,087, exclusive end `0x00559a0f`, 29 basic blocks, cyclomatic complexity 12, current prototype `int __thiscall(_DWORD **this, _DWORD *, _DWORD *)`.
- Target raw bytes SHA256: `69A8F9C4C1C5F32131968F8F55593208CE8DBE30CF843DC15578A6011AB18D2B`.
- Current calls: `0x557211`, `0x557301`, `0x5584cf`, `0x5585bf`; no data xref to the entry.
- Direct named callees/imports: `_memset`, `BitBlt`, `SetStretchBltMode`, `StretchBlt`, and security-cookie support; remaining calls are DirectDrawSurface vtable dispatch.
- DirectDraw slots in this body: Blt `+0x14`, BltFast `+0x1c`, GetDC `+0x44`, Lock `+0x64`, ReleaseDC `+0x68`, Restore `+0x6c`, Unlock `+0x80`.
- `DDSURFACEDESC` is 108 bytes; `dwHeight +0x8`, `dwWidth +0xc`, `lPitch +0x10`, `lpSurface +0x24`.
- Global bytes: `0x0067a93c = 00 00 00 00`, `0x0066d40c = 01 00 00 00`, `0x0069b3d4 = 00`.
- Global xrefs: 18 to `0x0067a93c`, three to `0x0066d40c`, seven to `0x0069b3d4`.
- Current global entity state: no named entity at `0x0067a93c`; no named entity at `0x0066d40c`; protected item `[0x0069b3d4,0x0069b3d5)` has project name `g_surfaceUses32BitPresentation`, exact semantic type `bool`, physical width 1, byte/value 0, seven xrefs, and separate absent regular/repeatable comments.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| 0x00559410-0x005595ca | UID0003A3 ScreenPanePresentationTraversal | preceding ScreenPane traversal method | true | UID0000NB current file route | 90/92 | source-bearing sibling |
| 0x005595ca-0x005595d0 | UID0000VN ignored | six-byte alignment | false | ignored | 100 | outside target |
| 0x005595d0-0x00559a0f | UID0003A4 target | ScreenPane display presentation method | true | recommend UID0000CB | 87/89 -> 93/94 | complete body |
| 0x00559a0f-0x00559a10 | UID0000VN ignored | one-byte alignment | false | ignored | 100 | outside target |
| 0x00559a10-0x00559aef | UID00023S raw helper | separate retained DirectDraw copy/create helper | true | current Surface route | 88/91 in aggregate table | must remain separate |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00557211` | `ScreenPane_RenderPresentation` at `0x00557140` | passes inherited GrafPort surface `ScreenPane+0x18` and full-screen RECT |
| `0x00557301` | `ScreenPane_RenderPresentation` at `0x00557140` | passes `ScreenPane::m_renderSurface +0x108` and clipped dirty RECT |
| `0x005584cf` | presentation body `sub_5583A0` | same inherited-surface/full-screen contract |
| `0x005585bf` | presentation body `sub_5583A0` | same render-surface/clipped-RECT contract |
| `0x0055960e` | read of `g_surfaceUses32BitPresentation` | selects RGB565-to-32-bit offscreen conversion |
| `0x005597b4` | read of `g_displayStartupDrawType` | selects DirectDraw, COLORONCOLOR, or HALFTONE presentation |
| `0x005595e3` | read of `0x0067a93c` | selects windowed versus exclusive presentation |

## Documentation Evidence And IDA Status

- UID0000CB already declares ScreenPane surfaces and identifies UID0003A4 as a `+0x100` display destination consumer, but does not declare this method.
- UID0000NB already says class receiver and field lifecycle should decide the exact route, explicitly queues UID0003A4 for strict owner cleanup, and routes neighboring source-ready ScreenPane methods to ScreenPane.cpp.
- UID0000OC and UID0001G6 retain split-era Surface ownership for UID0003A4; those rows are now contradicted by live receiver/caller evidence and should be historicalized, not silently deleted.
- UID00028Z accurately records 18 xrefs and Application ownership, but its `ApplicationActiveGate` semantic label is superseded for the second dword by exact display-mode behavior.
- UID00035N already emits `g_displayStartupDrawType = 1`; current live evidence validates that name and removes its stated raw-name blocker.
- UID00029U already emits `g_surfaceUses32BitPresentation`; no owner, name, or score change is required.
- Generated Surface.cpp contains only an Empty Emitter Marker for this target, proving there is no existing body to preserve or merge.

## Ranked Ownership Analysis

### 1. ScreenPane class / ScreenPane.cpp

- Evidence for: exact typed receiver, direct `m_primarySurface`/`m_offscreenSurface` fields, four ScreenPane-only callers, adjacent ScreenPane presentation methods, and current project source route.
- Evidence against: DirectDraw/pixel-format dependencies live in Surface-related docs and the address cluster was historically named SurfacePresentation.
- Decision: accepted. Dependencies and address adjacency do not override object receiver and method-call evidence.

### 2. Surface.cpp

- Evidence for: DirectDraw surfaces, pixel conversion, startup draw type, and historical aggregate bucket.
- Evidence against: no Surface object receiver, no Surface-class field access, no free-function call shape, and all callers are ScreenPane methods passing ScreenPane as ECX.
- Decision: rejected as direct owner; retain dependency and historical source-boundary context.

### 3. DirectX/Application/FolderTreePane

- Evidence for: DirectX interfaces and Application display fields are consumed; old report named FolderTreePane.
- Evidence against: none supplies the receiver; DirectX/Application are dependency/storage owners, and FolderTreePane has no current caller, field, vtable, or object-layout evidence.
- Decision: rejected.

### Proposed new file/grouping, if applicable

- Not applicable. Use existing `NexusTK/ui/core/ScreenPane.cpp` and the existing `ScreenPane` class.

## Source Placement

- Recommended placement: private `ScreenPane` method definition in `NexusTK/ui/core/ScreenPane.cpp`, declared in `ScreenPane` private methods after `RenderPresentation()` or beside the other presentation helpers.
- This matches the receiver, DirectDraw field lifetime, caller family, adjacent traversal helper, and existing class/file split.
- `NexusTK/render/Surface.cpp` remains the declaration/implementation route for pixel-format flags and surface callback logic only.
- No separate `SurfacePresentation.cpp`, `DisplayBlit.cpp`, DirectX method, or Application method is justified.
- Remaining uncertainty is exact original visibility/order and spelling, not source file or owner.

## Range / Split / Padding / Reclassification Analysis

- Exact function range is already correct and requires no rename or split of the by-memory path.
- Six preceding `0xcc` bytes belong to existing alignment after UID0003A3; one following `0xcc` byte belongs to existing ignored range before UID00023S.
- Target contains one modeled body and no embedded data island, jump table, child function, or compiler-only tail.
- Reclassify owner/emitter only: Surface method bucket -> ScreenPane class method.
- Parent UID0001G6 remains a non-reconstructable/non-emitting mixed index; only its child row changes.

## Negative Evidence Summary

- No alternate caller or pointer route supports Surface, DirectX, Application, or FolderTreePane ownership.
- No caller consumes EAX, so an externally meaningful HRESULT/int contract is unsupported.
- No RGB888 low-bit replication, alpha fill, clipping loop, format query, or color-mask branch exists in this body.
- No repeated retry loop exists. Converted DrawType-1 Blt and exclusive BltFast each handle only `DDERR_SURFACELOST` with at most one unchecked Restore and one retry; the ordinary non-32-bit windowed Blt does not inspect failure at all and therefore has no recovery path.
- No GetDC result check exists and no compensating branch may be invented.
- No safe reason exists to absorb UID00023S or the alignment byte into this formal.
- No proposed IDA name collides with a current database name.

## IDA Rename / Type / Comment Recommendations

Gate 2B is supervisor-only. B002 performed only the read-only pre-state collection recorded below and did not mutate IDA. After prerequisite supervisor Gate 1 and Gate 2A passed, the supervisor backed up `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` to `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0003A4-20260724-114534.bak` at pre-SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`, applied the accepted actions, performed exact readback, and saved a 143,187,027-byte IDB at `2026-07-24T11:48:53.8873820-04:00`, SHA256 `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99`. The historical table preserves the exact pre-state and accepted action. The disposition table that follows it is the current UID0003A4 Gate 2B state.

| Address / entity | Literal current pre-state | Proposed supervisor action | Evidence / safety constraints | Expected readback |
| --- | --- | --- | --- | --- |
| `0x005595d0-0x00559a0f`, modeled function | Name `sub_5595D0`; prototype `int __thiscall(_DWORD **this, _DWORD *, _DWORD *)`; size 1087; function regular comment absent (`""`); function repeatable comment absent (`""`); entry regular comment absent (`""`); entry repeatable comment absent (`""`). | Rename to `ScreenPane__BlitSurfaceToDisplay`; apply `void __thiscall ScreenPane__BlitSurfaceToDisplay(ScreenPane *this, LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)`. Leave the function regular comment absent (`""`). Set the function repeatable comment exactly to `Presents a ScreenPane render surface through exclusive BltFast, windowed DirectDraw, RGB565-to-32-bit, or GDI copy/stretch paths; retries once on DDERR_SURFACELOST only for converted DrawType-1 Blt and exclusive BltFast.` Leave the entry regular comment absent (`""`). Leave the entry repeatable comment absent (`""`). | ScreenPane UDT already exists at size 0x5b4 with +0x100/+0x104 fields. Proposed name has zero collisions. Do not change bounds or create a function at 0x00559a10. Do not duplicate the function comment into either entry-comment channel or imply recovery on the ordinary non-32-bit windowed Blt. | Name is exactly `ScreenPane__BlitSurfaceToDisplay`; prototype is exactly `void __thiscall ScreenPane__BlitSurfaceToDisplay(ScreenPane *this, LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)`; function regular comment remains absent (`""`); function repeatable comment equals the recommended sentence exactly; entry regular comment remains absent (`""`); entry repeatable comment remains absent (`""`); decompile resolves ScreenPane fields and two typed arguments; xrefs remain exactly four. |
| `0x0067a93c`, four-byte writable global | No named entity returned by names/globals query; decompiler label `unk_67A93C`; bytes `00 00 00 00`; value `0`; physical width 4; semantic type absent; regular comment absent (`""`); repeatable comment absent (`""`). | Create/rename data item as `g_isWindowedDisplayMode`, type `int`. Leave the regular comment absent (`""`). Set the repeatable comment exactly to `Nonzero after registry DisplayMode 1 passes desktop capability checks; selects DDSCL_NORMAL/windowed presentation. Zero selects exclusive display mode and BltFast.` | 18 existing xrefs; no name collision; preserve four-byte width and zero value. Do not convert to one-byte bool or rename the neighboring phase-state dword. Do not duplicate the repeatable comment into the regular-comment channel. | Name is exactly `g_isWindowedDisplayMode`; type is exactly `int`; value remains 0; regular comment remains absent (`""`); repeatable comment equals the recommended sentence exactly; all 18 xrefs remain unchanged. |
| `0x0066d40c`, four-byte initialized global | No named entity returned by names/globals query; decompiler label `dword_66D40C`; bytes `01 00 00 00`; value `1`; physical width 4; semantic type absent; regular comment absent (`""`); repeatable comment absent (`""`). | Create/rename data item as `g_displayStartupDrawType`, type `int`. Leave the regular comment absent (`""`). Set the repeatable comment exactly to `Registry DrawType selector: 1 uses DirectDraw Blt, 2 uses GDI COLORONCOLOR stretch, and 3 uses GDI HALFTONE stretch.` | Three xrefs; no collision; exact source page already emits this name. Preserve initialized value 1 and four-byte width; do not invent an IDA enum without a project-wide enum declaration. Do not duplicate the repeatable comment into the regular-comment channel. | Name is exactly `g_displayStartupDrawType`; type is exactly `int`; value remains 1; regular comment remains absent (`""`); repeatable comment equals the recommended sentence exactly; all three xrefs remain unchanged. |
| `0x0055960e`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `cmp byte ptr ds:69B3D4h, 0`. Exact instruction bytes: `80 3D D4 B3 69 00 00`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant targets: data xref to `0x0069b3d4`; direct fall-through code xref to `0x00559615`; this instruction has no direct branch target. | Set the regular comment exactly to `32-bit presentation uses the RGB565-to-XRGB8888 offscreen conversion path.` Leave the repeatable comment absent. | Do not rename/retype the already source-ready global here, alter the instruction bytes, or change either xref. | Bytes remain exactly `80 3D D4 B3 69 00 00`; disassembly remains exactly `cmp byte ptr ds:69B3D4h, 0`; data target remains `0x0069b3d4`; fall-through remains `0x00559615`; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |
| `0x00559723`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `mov eax, ecx`. Exact instruction bytes: `8B C1`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant target: direct fall-through code xref to `0x00559725`; this register-to-register instruction has no direct data or branch target. | Set the regular comment exactly to `Expand RGB565 to 0x00RRGGBB by left-shifting channels; low bits are not replicated.` Leave the repeatable comment absent. | Do not imply alpha or rounded channel expansion, alter the instruction bytes, or create a data/branch xref that the current instruction does not have. | Bytes remain exactly `8B C1`; disassembly remains exactly `mov eax, ecx`; fall-through remains `0x00559725`; no direct data or branch target is introduced; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |
| `0x005597d5`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `jnz loc_559895`. Exact instruction bytes: `0F 85 BA 00 00 00`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant control-flow targets: taken branch `0x00559895`; fall-through `0x005597db`. | Set the regular comment exactly to `DrawType 1 presents the converted offscreen surface with DirectDraw Blt.` Leave the repeatable comment absent. | Modes 2/3 continue into the GDI path. Do not alter the branch encoding or either control-flow target. | Bytes remain exactly `0F 85 BA 00 00 00`; disassembly remains exactly `jnz loc_559895`; taken target remains `0x00559895`; fall-through remains `0x005597db`; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |
| `0x0055984f`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `jnz loc_5599FC`. Exact instruction bytes: `0F 85 A7 01 00 00`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant control-flow targets: taken branch `0x005599fc`; fall-through `0x00559855`. | Set the regular comment exactly to `Converted DrawType-1 Blt restores the primary surface and retries once on DDERR_SURFACELOST.` Leave the repeatable comment absent. | Do not label the retry as a loop, propagate a status contract, imply recovery on the ordinary non-32-bit windowed Blt, alter the branch encoding, or change either control-flow target. | Bytes remain exactly `0F 85 A7 01 00 00`; disassembly remains exactly `jnz loc_5599FC`; taken target remains `0x005599fc`; fall-through remains `0x00559855`; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |
| `0x00559906`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `jnz short loc_55990C`. Exact instruction bytes: `75 04`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant control-flow targets: taken branch `0x0055990c`; fall-through `0x00559908`. | Set the regular comment exactly to `DrawType 2 selects COLORONCOLOR; other non-DirectDraw mode selects HALFTONE.` Leave the repeatable comment absent. | Initializer bounds normal values to 1..3; preserve fallback behavior for any other value. Do not alter the short-branch encoding or either control-flow target. | Bytes remain exactly `75 04`; disassembly remains exactly `jnz short loc_55990C`; taken target remains `0x0055990c`; fall-through remains `0x00559908`; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |
| `0x005599d9`, instruction | Containing function: `sub_5595D0` at `0x005595d0`, size `0x43f`. Verbatim current disassembly: `jnz short loc_5599FC`. Exact instruction bytes: `75 21`. Current regular comment: absent (`""`). Current repeatable comment: absent (`""`). Relevant control-flow targets: taken branch `0x005599fc`; fall-through `0x005599db`. | Set the regular comment exactly to `Exclusive presentation restores the primary surface and retries BltFast once on DDERR_SURFACELOST.` Leave the repeatable comment absent. | Do not merge this retry with the windowed Blt retry, alter the short-branch encoding, or change either control-flow target. | Bytes remain exactly `75 21`; disassembly remains exactly `jnz short loc_5599FC`; taken target remains `0x005599fc`; fall-through remains `0x005599db`; regular comment equals the recommended sentence exactly; repeatable comment remains absent (`""`). |

Supervisor Gate 2B disposition and exact verified readback (supervisor-owned; B002 did not mutate IDA):

| Address / entity | Supervisor disposition | Exact verified readback |
| --- | --- | --- |
| `0x005595d0-0x00559a0f`, modeled function | `APPLIED_VERIFIED` | Name is exactly `ScreenPane__BlitSurfaceToDisplay`; prototype is exactly `void __thiscall ScreenPane__BlitSurfaceToDisplay(ScreenPane *this, LPDIRECTDRAWSURFACE sourceSurface, RECT *sourceRect)`; size remains 1087; function regular comment is absent (`""`); function repeatable comment is exactly `Presents a ScreenPane render surface through exclusive BltFast, windowed DirectDraw, RGB565-to-32-bit, or GDI copy/stretch paths; retries once on DDERR_SURFACELOST only for converted DrawType-1 Blt and exclusive BltFast.`; entry regular comment is absent (`""`); entry repeatable comment is absent (`""`); decompile resolves `ScreenPane` fields and both typed arguments; xrefs remain exactly four. |
| `0x0067a93c`, four-byte writable global | `APPLIED_VERIFIED` | Name is exactly `g_isWindowedDisplayMode`; type is exactly `int`; physical width remains 4; value remains 0; regular comment is absent (`""`); repeatable comment is exactly `Nonzero after registry DisplayMode 1 passes desktop capability checks; selects DDSCL_NORMAL/windowed presentation. Zero selects exclusive display mode and BltFast.`; all 18 xrefs remain unchanged. |
| `0x0066d40c`, four-byte initialized global | `APPLIED_VERIFIED` | Name is exactly `g_displayStartupDrawType`; type is exactly `int`; physical width remains 4; value remains 1; regular comment is absent (`""`); repeatable comment is exactly `Registry DrawType selector: 1 uses DirectDraw Blt, 2 uses GDI COLORONCOLOR stretch, and 3 uses GDI HALFTONE stretch.`; all three xrefs remain unchanged. |
| `0x0055960e`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `80 3D D4 B3 69 00 00`; disassembly remains exactly `cmp byte ptr ds:69B3D4h, 0`; data target remains `0x0069b3d4`; fall-through remains `0x00559615`; regular comment is exactly `32-bit presentation uses the RGB565-to-XRGB8888 offscreen conversion path.`; repeatable comment is absent (`""`). |
| `0x00559723`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `8B C1`; disassembly remains exactly `mov eax, ecx`; fall-through remains `0x00559725`; no direct data or branch target was introduced; regular comment is exactly `Expand RGB565 to 0x00RRGGBB by left-shifting channels; low bits are not replicated.`; repeatable comment is absent (`""`). |
| `0x005597d5`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `0F 85 BA 00 00 00`; disassembly remains exactly `jnz loc_559895`; taken target remains `0x00559895`; fall-through remains `0x005597db`; regular comment is exactly `DrawType 1 presents the converted offscreen surface with DirectDraw Blt.`; repeatable comment is absent (`""`). |
| `0x0055984f`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `0F 85 A7 01 00 00`; disassembly remains exactly `jnz loc_5599FC`; taken target remains `0x005599fc`; fall-through remains `0x00559855`; regular comment is exactly `Converted DrawType-1 Blt restores the primary surface and retries once on DDERR_SURFACELOST.`; repeatable comment is absent (`""`). |
| `0x00559906`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `75 04`; disassembly remains exactly `jnz short loc_55990C`; taken target remains `0x0055990c`; fall-through remains `0x00559908`; regular comment is exactly `DrawType 2 selects COLORONCOLOR; other non-DirectDraw mode selects HALFTONE.`; repeatable comment is absent (`""`). |
| `0x005599d9`, instruction | `APPLIED_VERIFIED` | Bytes remain exactly `75 21`; disassembly remains exactly `jnz short loc_5599FC`; taken target remains `0x005599fc`; fall-through remains `0x005599db`; regular comment is exactly `Exclusive presentation restores the primary surface and retries BltFast once on DDERR_SURFACELOST.`; repeatable comment is absent (`""`). |
| `[0x0069b3d4,0x0069b3d5)`, protected one-byte item | `NO_CHANGE_VERIFIED` | Item head remains `0x0069b3d4`, exclusive end `0x0069b3d5`, size 1, name exactly `g_surfaceUses32BitPresentation`, type exactly `bool`, byte/value exactly `00`/`0`, xref count exactly seven at the same sites, regular comment is absent (`""`), repeatable comment is absent (`""`), and every adjacent item head/range remains unchanged. |

Protected/no-action entities:

| Address / protected entity | Independently re-read current state | Disposition | Adjacent-item and collision safety | Exact expected unchanged readback |
| --- | --- | --- | --- | --- |
| `[0x0069b3d4,0x0069b3d5)`, item head `0x0069b3d4` | Physical width 1; current project name `g_surfaceUses32BitPresentation` from `list_globals`/`entity_query`; exact attached semantic type `bool` from `inspect_items`; byte `00`, value `0`; exactly seven data xrefs at `0x005586cf`, `0x005586eb`, `0x005587c4`, `0x00558b56`, `0x00558b72`, `0x00558e79`, and `0x0055960e`; regular comment absent (`""`); repeatable comment absent (`""`). | `NO_CHANGE_VERIFIED`: do not rename, retype, resize, rewrite, or comment this protected source-ready item. The separate instruction action at `0x0055960e` may be applied without changing the global. | `0x0069b3d5-0x0069b3d6` is a distinct one-byte `bool` item named `g_surfaceUsesRgb565Pixels`; `0x0069b3d6` and `0x0069b3d7` are separate one-byte unnamed/untyped item heads; the next named item starts at `0x0069b3d8` as `g_surfaceColorLookup5Bit`. Preserve every boundary and adjacent byte; no proposed mutable name collides with this protected symbol. | Item head remains `0x0069b3d4`, exclusive end `0x0069b3d5`, size 1, name exactly `g_surfaceUses32BitPresentation`, type exactly `bool`, byte/value exactly `00`/`0`, xref count exactly seven with the same sites, regular comment remains absent (`""`), repeatable comment remains absent (`""`), and all adjacent item heads/ranges remain unchanged. |
- Existing `ScreenPane` UDT is protected at exact size `0x5b4` with `m_primarySurface +0x100`, `m_offscreenSurface +0x104`, and `m_renderSurface +0x108`. Do not resize it or replace provisional storage while applying this handoff.
- Broad Application UDT/member mutation is not recommended because the current IDB does not expose a complete safe Application layout. Record the inferred `+0xa58..+0xa64` fields in documentation only.
- Do not alter GDI imports, DirectDraw interface declarations/vtable slots, compiler cookie comments, target bounds, the padding byte, or raw successor UID00023S.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. Behavior, arguments, receiver fields, APIs, branches, cleanup, and boundaries are closed.
- Recommended destination-ready managed target block:

```cpp
*** UID:0003A4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000CB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000CB | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScreenPane::BlitSurfaceToDisplay(LPDIRECTDRAWSURFACE sourceSurface,
                                      RECT *sourceRect)
{
    RECT destinationRect = *sourceRect;

    if (g_isWindowedDisplayMode != 0) {
        if (g_surfaceUses32BitPresentation) {
            DDSURFACEDESC sourceDescription;
            memset(&sourceDescription, 0, sizeof(sourceDescription));
            sourceDescription.dwSize = sizeof(sourceDescription);

            if (sourceSurface->Lock(NULL,
                                    &sourceDescription,
                                    DDLOCK_WAIT,
                                    NULL) == DD_OK) {
                DDSURFACEDESC destinationDescription;
                memset(&destinationDescription, 0, sizeof(destinationDescription));
                destinationDescription.dwSize = sizeof(destinationDescription);

                if (m_offscreenSurface->Lock(NULL,
                                             &destinationDescription,
                                             DDLOCK_WAIT,
                                             NULL) == DD_OK) {
                    WORD *sourcePixels =
                        static_cast<WORD *>(sourceDescription.lpSurface);
                    DWORD *destinationPixels =
                        static_cast<DWORD *>(destinationDescription.lpSurface);
                    const int sourcePitch = sourceDescription.lPitch / sizeof(WORD);
                    const int destinationPitch =
                        destinationDescription.lPitch / sizeof(DWORD);

                    for (unsigned short y = 0;
                         y < sourceDescription.dwHeight;
                         ++y) {
                        for (unsigned short x = 0;
                             x < sourceDescription.dwWidth;
                             ++x) {
                            const WORD pixel = sourcePixels[y * sourcePitch + x];
                            destinationPixels[y * destinationPitch + x] =
                                ((pixel & 0xf800) << 8) |
                                ((pixel & 0x07e0) << 5) |
                                ((pixel & 0x001f) << 3);
                        }
                    }

                    m_offscreenSurface->Unlock(destinationDescription.lpSurface);
                }

                sourceSurface->Unlock(sourceDescription.lpSurface);
            }

            const int windowTop = g_pApplication->m_windowTop;
            const int windowLeft = g_pApplication->m_windowLeft;
            const int windowHeight = g_pApplication->m_windowHeight;
            const int windowWidth = g_pApplication->m_windowWidth;

            if (g_displayStartupDrawType == 1) {
                RECT windowRect = {
                    windowLeft,
                    windowTop,
                    windowLeft + windowWidth,
                    windowTop + windowHeight
                };
                RECT fullSurfaceRect = { 0, 0, g_screenWidth, g_screenHeight };

                // Only this converted DrawType-1 Blt path handles a lost surface.
                HRESULT result = m_primarySurface->Blt(&windowRect,
                                                       m_offscreenSurface,
                                                       &fullSurfaceRect,
                                                       DDBLT_WAIT,
                                                       NULL);
                if (result == DDERR_SURFACELOST) {
                    m_primarySurface->Restore();
                    m_primarySurface->Blt(&windowRect,
                                          m_offscreenSurface,
                                          &fullSurfaceRect,
                                          DDBLT_WAIT,
                                          NULL);
                }
                return;
            }

            HDC sourceDC;
            HDC destinationDC;
            sourceSurface->GetDC(&sourceDC);
            m_primarySurface->GetDC(&destinationDC);

            if (windowWidth == g_screenWidth &&
                windowHeight == g_screenHeight) {
                BitBlt(destinationDC,
                       windowLeft,
                       windowTop,
                       g_screenWidth,
                       g_screenHeight,
                       sourceDC,
                       0,
                       0,
                       SRCCOPY);
            } else {
                SetStretchBltMode(destinationDC,
                                  g_displayStartupDrawType == 2
                                      ? COLORONCOLOR
                                      : HALFTONE);
                StretchBlt(destinationDC,
                           windowLeft,
                           windowTop,
                           windowWidth,
                           windowHeight,
                           sourceDC,
                           0,
                           0,
                           g_screenWidth,
                           g_screenHeight,
                           SRCCOPY);
            }

            sourceSurface->ReleaseDC(sourceDC);
            m_primarySurface->ReleaseDC(destinationDC);
            return;
        }

        // The ordinary non-32-bit windowed path ignores Blt failure and never retries.
        m_primarySurface->Blt(&destinationRect,
                              sourceSurface,
                              sourceRect,
                              DDBLT_WAIT,
                              NULL);
        return;
    }

    // Exclusive BltFast also restores and retries once only on surface loss.
    HRESULT result = m_primarySurface->BltFast(sourceRect->left,
                                               sourceRect->top,
                                               sourceSurface,
                                               sourceRect,
                                               DDBLTFAST_WAIT);
    if (result == DDERR_SURFACELOST) {
        m_primarySurface->Restore();
        m_primarySurface->BltFast(sourceRect->left,
                                  sourceRect->top,
                                  sourceSurface,
                                  sourceRect,
                                  DDBLTFAST_WAIT);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: ScreenPane display-presentation method with exact exclusive BltFast, windowed DirectDraw/GDI, RGB565-to-32-bit conversion, DrawType 1/2/3 selection, Application destination geometry, one-shot DDERR_SURFACELOST recovery only for converted DrawType-1 Blt and exclusive BltFast, and deliberately unchecked ordinary non-32-bit windowed Blt. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- The code preserves all observed unchecked API results, source/destination Unlock order, exact 16-bit loop counters, pitch arithmetic, channel shifts, and DrawType dispatch. It emits one-shot lost-surface recovery only around converted DrawType-1 Blt and exclusive BltFast; the ordinary non-32-bit windowed Blt remains a bare call whose HRESULT is ignored.
- It uses human source-facing names and standard DirectDraw/GDI constants typical of the project period; no raw address, IDA temporary, or compiler-generated name is emitted.
- Third-party import directive: not applicable; this is NexusTK source-authored ScreenPane logic.
- Exact no-code proof: not applicable; blank C++ is no longer justified.

## Final Recommendation

- Retain the callback-applied target claims C3A4-001 through C3A4-018 and generated verification C3A4-021 exactly; all are implemented, read back, and scoped-validated.
- Preserve the binary-proven recovery asymmetry in every later destination: converted DrawType-1 Blt and exclusive BltFast each have one `DDERR_SURFACELOST` restore/retry, while ordinary non-32-bit windowed Blt has no result check, Restore, or retry.
- Prerequisite supervisor Gate 1 and Gate 2A passed, and C3A4-019 Gate 2B is `APPLIED_VERIFIED` with protected `0x0069b3d4` `NO_CHANGE_VERIFIED`. Supervisor next performs fresh exact-artifact Gate 1 review on this post-Gate-2B reconciliation; if it passes, supervisor-only execution/archive follows, then C3A4-020 manual coverage under the current lifecycle order.
- Leave UID00023S, target path/range, ignored padding, DirectDraw types, and Surface pixel-format owner unchanged.
- Future final audit may refine original visibility/member spelling, but must not restore Surface ownership, raw labels, or blank C++ absent contradictory evidence.

## Recommended Target Doc Changes

- Applied at `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`: metadata/formal/summary, ScreenPane status/route, exact ABI/range/hash/callers/slots/fields/globals/branches/conversion/cleanup, ownership alternatives, and generated expectation.
- Readback confirms old Surface and FolderTreePane assertions remain only in historical/superseded context, while UID00039Z and UID00029U evidence was expanded rather than pruned.

## Recommended Support Doc Changes

- Applied and validated: UID0000CB private declaration/fields/behavior/four callers; UID0000NB accepted ScreenPane.cpp route; UID0000OC dependency/history treatment at current `89/87`; UID0001G6 child row at `93/94` while parent remains `88/90`, NONE/FALSE/blank.
- Applied and validated: UID00028Z second formal/prose global `g_isWindowedDisplayMode` at `90/94`; UID00035N validated `g_displayStartupDrawType` at `90/94`; UID00029U exact conversion consumer with unchanged `88/93`; UID00000D/UID0000HG geometry/global relationships with existing scores and broad Application formal policy preserved.

## Score And Metadata Recommendation

- Assignment-time target: `87/89`, owner/emitter UID0000OC, reconstructable true, blank position/formal, `Nested:0`.
- Current callback-applied target: `93/94`, owner/emitter UID0000CB, reconstructable true, blank position, complete formal, `Nested:0`.
- Completion rises because every behavior branch, argument, field, cleanup path, source route, formal, support dependency, and manual handoff is now implementation-ready.
- Confidence rises because current live UDT/caller/xref/type/byte evidence replaces generic Surface-bucket reasoning.
- Reason not higher: exact original method visibility/spelling, `void` versus ignored HRESULT source declaration, four Application member spellings, and source linkage of two globals remain inferred rather than symbol-proven. These are normal source-reconstruction uncertainties, not blockers.
- Reason not lower: exact runtime behavior, boundaries, receiver, parameters, field offsets, caller set, API slots, constants, and generated correction are directly observed and mutually corroborated.
- Applied support scores: UID00028Z `88/92 -> 90/94`; UID00035N `88/92 -> 90/94`; UID0000CB/0000NB/0000OC/0001G6/00029U/00000D/0000HG scores otherwise unchanged.
- Score-improvement attempts closed the former receiver, global naming, type, source route, C++, and behavior blockers; none is merely deferred.

## Open Questions With Attempted Resolution

- Exact original return type: four callers and machine cleanup were checked. `void` is the best source reconstruction because no caller consumes EAX; the ignored latest-call result explains decompiler `int`. This is resolved for draft source and remains only a below-95 spelling confidence cap.
- Exact original method name: old report, project naming, caller role, and full behavior were compared. `BlitSurfaceToDisplay` is retained as the strongest descriptive human name.
- Display-mode global: initializer writers, registry string, cooperative-level flags, SetDisplayMode/RestoreDisplayMode readers, activation readers, and target branch were checked. `g_isWindowedDisplayMode` resolves the stale active-gate label.
- Draw-type global: initial bytes, registry `DrawType`, bounded 1..3 validation, and target dispatch were checked. Existing `g_displayStartupDrawType` is validated.
- Application geometry fields: all four offsets and every use in DirectDraw/GDI destination construction were checked. Top/left/height/width is high-probability; no RECT or point/size aggregate matches the physical order.
- Exact private declaration order and global linkage remain unavailable from symbols. They do not affect owner, body, emitted route, or score eligibility and are explicitly capped below 95 rather than left as blockers.
- No question remains that requires additional current binary research before implementation.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

B002 inspected the current manual rows. UID0003A4 is absent from `by-memory/-coverage-report.md` between UID0003A3 and the `0x00559a0f` ignored row. The following text is supervisor-owned and must not be applied by B002.

- File/placement: `by-memory/-coverage-report.md`, insert immediately after the UID0003A3 row and before UID0000VN `0x00559a0f-0x00559a10`:

`        - [UID:0003A4][0x005595d0-0x00559a0f.BlitSurfaceToDisplay](by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md) 0x005595d0-0x00559a0f | method | ScreenPane::BlitSurfaceToDisplay : reconstructable : 93% : very-strong : Exact ScreenPane display-presentation method with four typed presentation callers, primary/offscreen DirectDraw fields, exclusive BltFast, windowed DirectDraw/GDI paths, RGB565-to-32-bit conversion, DrawType 1/2/3 selection, Application destination geometry, one-shot DDERR_SURFACELOST recovery only for converted DrawType-1 Blt and exclusive BltFast, and an unchecked ordinary non-32-bit windowed Blt.`

- File/placement: replace current UID0001G6 row in `by-memory/-coverage-report.md`:

`    - [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) 0x00557140-0x00559aef | surface/render helper cluster | SurfacePresentation : not_reconstructable : 88% : very strong : Non-emitting mixed source-family index over ScreenPane presentation, cursor, screenshot, minimap, and traversal children; current exact children include source-ready ScreenPane::TraversePresentationList and ScreenPane::BlitSurfaceToDisplay while preserving all raw boundaries, padding, screenshot cross-file routing, Surface callback dependencies, and mixed-family ownership.`

- File/placement: replace current UID00028Z row in `by-memory/-coverage-report.md`:

`    - [UID:00028Z][0x0067a938-0x0067a940.ApplicationLifecycleFlags](by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md) 0x0067a938-0x0067a940 | application flags | ApplicationLifecycleFlags : reconstructable : 90% : very-strong : Application phase-state plus exact four-byte g_isWindowedDisplayMode state; current IDA preserves zero bytes, five phase refs, eighteen display-mode refs, registry DisplayMode polarity, DDSCL_NORMAL versus exclusive behavior, and ScreenPane presentation consumers.`

- File/placement: replace current UID00035N row in `by-memory/-coverage-report.md`:

`        - [UID:00035N][0x0066d408-0x0066d410.DisplayStartupPresentationGlobals](by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md) 0x0066d408-0x0066d410 | initialized global data | DisplayStartupPresentationGlobals : reconstructable : 90% : very-strong : Application-owned g_displayStartupWidth and g_displayStartupDrawType defaults; exact bytes encode 1024 and 1, Application::Initialize reads WindowWidth/DrawType and validates modes 1..3, and ScreenPane::BlitSurfaceToDisplay consumes mode 1 as DirectDraw, 2 as COLORONCOLOR, and 3 as HALFTONE.`

- File/placement: replace UID0000CB row in `by-class/-coverage-report.md`, retaining its existing full class detail and changing the score/current summary to include UID0003A4:

`- [UID:0000CB][ScreenPane](by-class/ScreenPane.md) : reconstructable : 93% : very strong : Root Pane/FrameHandler/Singleton<ScreenPane> controller with exact 0x5b4 layout, singleton/surface/cursor/dimension/dirty/fade/presentation state, source-ready cursor and presentation methods, and complete compiler/source split; now includes exact private ScreenPane::BlitSurfaceToDisplay with four callers, exclusive/windowed DirectDraw, GDI copy/stretch, RGB565-to-32-bit conversion, one-shot lost-surface recovery limited to converted DrawType-1 Blt and exclusive BltFast, and unchanged ignored ordinary-windowed Blt failure while preserving all existing class-layout and compiler-output constraints.`

- File/placement: replace UID0000NB row in `by-file/-coverage-report.md`, retaining all current ScreenPane source-root detail and adding the accepted method route:

`- [UID:0000NB][ScreenPane](by-file/ScreenPane.md) : reconstructable : 93% : very-strong : NexusTK/ui/core ScreenPane source root retaining canonical singleton, complete 0x5b4 class/layout, layer/presentation/cursor state, exact source-ready method children, compiler/source exclusions, and generated-output constraints; UID0003A4 now emits exact ScreenPane::BlitSurfaceToDisplay here rather than as a Surface.cpp Empty Emitter Marker, with DirectDraw/GDI/RGB565 presentation behavior and Application display dependencies preserved.`

- File/placement: replace UID0000OC row in `by-file/-coverage-report.md`, preserving all unrelated Surface detail and removing UID0003A4 as a current owner:

`- [UID:0000OC][Surface](by-file/Surface.md) : reconstructable : 89% : strong : Actual generated root NexusTK/render/Surface.cpp owns Surface callback typedefs/implementations, initializer selection, pixel-format/lookup globals, software callback families, and true Surface helpers; ScreenPane::BlitSurfaceToDisplay is retained only as historical presentation-neighborhood and dependency context and now emits through ScreenPane.cpp, while broader current Surface source-unit caveats remain preserved.`

- UID00029U manual row already accurately says `88%`, source-ready names, seven D4 refs, and the 32-bit presentation-copy role; no replacement is needed.
- Reason B002 must not apply: all `-coverage-report.md` files are supervisor-only collision points and are applied only after report execution under the current lifecycle.

## Follow-Up Actions

- Completed: supervisor Gate 1 accepted exact SHA `E24945806424801CD81C66D496C44373F3C95D2407B77F03A860305498CC4B3F`; B002 implemented every accepted ordinary-document claim, used short leases, ran serial scoped validators, reread generated ScreenPane.cpp/Surface.cpp, and reconciled this same report.
- Completed by supervisor after the callback: prerequisite Gate 1 and independent Gate 2A passed; C3A4-019 Gate 2B was applied, read back exactly, and saved at the checkpoint recorded in the IDA section. B002 did not mutate IDA.
- Supervisor next: freshly review this post-Gate-2B reconciled exact artifact at Gate 1; if it passes, execute/archive the exact report, then apply and validate C3A4-020 manual coverage.
- No A-agent action is required.
- B002 future research: none for this target unless the fresh post-callback Gate 1 review identifies another exact contradiction.

## Confidence

- Recommendation confidence: very strong (`94`).
- Score confidence: strong; `93/94` reflects implementation-ready behavior with honest below-95 source-spelling caps.
- Remaining uncertainty: original visibility/order and a handful of human spellings only. Runtime behavior and ownership are not uncertain.

## Validator Results

- `17259`, `2026-07-24T10:51:15-04:00`: target UID0003A4, exit `0`, `ok:1`; registered `93/94`, owner/emitter UID0000CB, and nonblank formal.
- `17260`, `2026-07-24T10:52:41-04:00`: `by-class/ScreenPane.md`, exit `0`, `ok:1`; 15 pre-existing missing-ref warnings.
- `17262`, `2026-07-24T10:53:43-04:00`: `by-file/ScreenPane.md`, exit `0`, `ok:1`; 17 pre-existing missing-ref warnings.
- `17265`, `2026-07-24T10:54:42-04:00`: `by-file/Surface.md`, exit `0`, `ok:1`; 15 pre-existing missing-ref warnings.
- `17267`, `2026-07-24T10:56:03-04:00`: UID0001G6 aggregate, exit `0`, `ok:1`; 29 pre-existing missing-ref warnings and two validator-added reference links.
- `17268`, `2026-07-24T10:57:35-04:00`: UID00028Z, exit `0`, `ok:1`; registered `90/94`, three pre-existing UID00039R warnings.
- `17269`, `2026-07-24T10:58:30-04:00`: UID00035N, exit `0`, `ok:1`; registered `90/94`, no warnings.
- `17270`, `2026-07-24T10:59:15-04:00`: UID00029U, exit `0`, `ok:1`; no warnings.
- `17271`, `2026-07-24T11:00:01-04:00`: `by-class/Application.md`, exit `0`, `ok:1`; no warnings.
- `17272`, `2026-07-24T11:00:55-04:00`: `by-file/Application.md`, exit `0`, `ok:1`; two pre-existing UID0003OY missing-ref warnings.
- Every command used `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240` from `source-3/project-documentation`. No validator failed; warnings are pre-existing reference-index gaps, not callback defects.

## Changed Files

- `by-memory/0x005595d0-0x00559a0f.BlitSurfaceToDisplay.md`: SHA256 `DFEAB69C0AF272C15DFE74CE1C635F5FB5F577AB8FF142B773EEA63488185367`, 19,505 bytes / 270 lines.
- `by-class/ScreenPane.md`: SHA256 `9F1F86A8A3F85CEAB93208580AC4753ACB7AF3810BC229924ED7444E566CE6B1`, 61,990 bytes / 392 lines.
- `by-file/ScreenPane.md`: SHA256 `8A91FC37444ADE48F06AD0C78D2A782C8C949CA30634569A1094202B86E84B70`, 56,264 bytes / 266 lines.
- `by-file/Surface.md`: SHA256 `1797C0994EE0653004F2948B1A78B910B28F776B50CF5665376DE031FAA7EDAD`, 122,575 bytes / 517 lines.
- `by-memory/0x00557140-0x00559aef.SurfacePresentation.md`: SHA256 `61F033FC374CAEBEE51C633BC80B6A704813D38C1AC6C73978DDF69398FCC0DF`, 59,404 bytes / 247 lines.
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`: SHA256 `611BAB9E24DCFF4FC141530933712BE234A661743105B82B7681D545DC866585`, 10,178 bytes / 99 lines.
- `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`: SHA256 `FB509C4404A9101E228EDBD5F0119470DF8AE5690C7550910DCAC789288E5C5F`, 8,666 bytes / 90 lines.
- `by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md`: SHA256 `4FE9B5A4A6BEA198BD71CF429B981BD92A2EF434102469B4A665F17C478AF1BB`, 19,496 bytes / 141 lines.
- `by-class/Application.md`: SHA256 `104736717339F780D25BA1E1805B2FDE9D46576194C7AD16CB1C4D9C45CBEBA5`, 113,253 bytes / 449 lines.
- `by-file/Application.md`: SHA256 `AC7B863EFA318285CC449CDBAB67879577FFE527A934DCF6867041E00BDBA841`, 156,402 bytes / 505 lines.
- Generated readback only: `auto-generated/NexusTK/ui/core/ScreenPane.cpp` SHA256 `1F503F0BF5D4A51AD5F4B7B909F5187427866A546A3F4D7C5F378C18C685E46C`, 23,465 bytes / 692 lines, one UID0003A4/method and zero empty markers; `auto-generated/NexusTK/render/Surface.cpp` SHA256 `8B290D49FC028B30F43F4BD4F9A0AF5A4024D2E9052672B4A933C68E3D6284B7`, 45,543 bytes / 1,392 lines, zero UID0003A4.
- Supervisor-owned IDA Gate 2B checkpoint (not a B002 edit): backup `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.pre-0003A4-20260724-114534.bak`; pre-SHA256 `6A2658F0B4AC0ACC9A51E72472300A06A49497117F6A32EE975032C8A1A56112`; saved-IDB SHA256 `F28C8B463F64693561E118790FD5E9D68739F85C697B9B58F391F56E1911ED99`, 143,187,027 bytes, save time `2026-07-24T11:48:53.8873820-04:00`. This is the exact UID0003A4 Gate 2B checkpoint; later unrelated supervisor saves may advance the shared IDB while preserving the verified states.
- Manual coverage remains unchanged and stale exactly as C3A4-020 records; no generated, coverage, tracker, audit, goal, or lifecycle file was manually edited. B002 did not edit IDA; the supervisor performed the Gate 2B IDA changes recorded above. All B002 ordinary-file leases were released; B002 did not run/probe/dry-run `execute_report` or any lifecycle command.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor Gate 1 accepted exact SHA `E24945806424801CD81C66D496C44373F3C95D2407B77F03A860305498CC4B3F` before implementation.
- [x] Prerequisite fresh post-callback supervisor Gate 1 and independent Gate 2A passed before supervisor Gate 2B began.
- [x] Target/support docs updated: UID0003A4, UID0000CB, UID0000NB, UID0000OC, UID0001G6, UID00028Z, UID00035N, UID00029U, UID00000D, and UID0000HG.
- [x] Every declared additional UID has target-specific evidence, recommendation, ledger rows, destination docs, and planned validation: not applicable; no additional target UID is declared.
- [x] Current target state and actual evidence checked recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score changes applied: UID0003A4 93/94, UID00028Z 90/94, UID00035N 90/94.
- [x] Score-limiting blockers researched to resolution or rare exact no-improvement proof.
- [x] Owner/emitter/reconstructable changes applied: UID0003A4 owner/emitter UID0000CB, true.
- [x] Split/rename/new-child decision applied: no path/range split; owner reclassification only.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment dispositions recorded.
- [x] Supervisor Gate 2B IDA handoff lists every exact actionable address/entity, literal pre-state, proposed action, safety constraint, expected readback, and current supervisor disposition.
- [x] First-draft C++ complete managed block applied.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 artifacts encountered and rejected as stale.
- [x] Open questions closed or reduced to explicit below-95 source-spelling caps.
- [x] Serial scoped validators run only after callback edits.
- [x] Generated refresh/readback completed and supervisor-owned manual coverage payloads reconfirmed without editing coverage.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Declared UID0003A4 verified independently against ledger and destination docs.
- [x] Claim And Incorporation Ledger updated with implemented verification state.
- [x] Metadata/score/owner/emitter/C++ changes applied.
- [x] Historical assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with exhaustive evidence.
- [x] Serial scoped validators run and exact results recorded.
- [x] Generated ScreenPane.cpp/Surface.cpp readback completed and manual coverage text reconfirmed.
- [x] Supervisor independent Gate 2A audit passed before Gate 2B.
- [x] C3A4-019 supervisor-owned Gate 2B is `APPLIED_VERIFIED`; protected `0x0069b3d4` is `NO_CHANGE_VERIFIED`; B002 did not mutate IDA.
- [ ] Fresh exact-artifact supervisor Gate 1 must accept this post-Gate-2B reconciled report before execution/archive.
- [ ] Supervisor-only report execution/archive remains pending after the fresh exact-artifact Gate 1 review.
- [ ] C3A4-020 supervisor-owned manual coverage remains pending until after report execution.
- [x] Remaining supervisor actions are limited exactly to fresh exact-artifact Gate 1 review, lifecycle execution/archive, and C3A4-020 manual coverage.

READY_FOR_SUPERVISOR_GATE1_REVIEW

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000017282","destination_path":"executed-b-agent-research/B002/0003A4-BlitSurfaceToDisplay-empty-emitter-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0003A4-BlitSurfaceToDisplay-empty-emitter-source-quality.md","timestamp":"2026-07-24T11:57:20-04:00","uid":"0003A4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
