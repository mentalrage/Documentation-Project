# 0000N1 RectangleControlPane Whole-File Source-Quality Research
** TARGET-REPORT-UID:0000N1 **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

Project context: this report supports local preservation and behaviorally faithful source reconstruction of the unsupported NexusTK client.

## Finalized Report / Current Recommendation

- Settle [UID:0000N1] as the standalone `NexusTK/ui/controls/RectangleControlPane.cpp` source root with required sibling `RectangleControlPane.h`.
- Treat [UID:0000BT] as the declaration/preamble emitter at position `10`; authored method definitions follow as constructor `20`, ordinary destructor `30`, `OnPaint` `40`, and `HitTestPart` `50`.
- Correct [UID:000128] from the stale `RectangleControlPaneTypeId` interpretation to `RectangleControlPane::HitTestPart(int,int)`. The exact terminal primary-vtable override ignores both coordinates and returns part identifier `21`.
- Keep [UID:000122] adjustor thunks, [UID:000125] scalar deleting wrapper, [UID:0002OE] vtable/RTTI data, and [UID:0003IT] vtable layout non-emitting compiler/binary evidence. Their source causes are the class declaration and authored ordinary destructor.
- The physically applied file/class/paint metadata is `94/95`, `94/95`, and `92/94`. The accepted dependency callback now makes those values source-closure justified: generated CPP includes Surface, calls the declaration-owned global directly, preserves all four authored definitions in order, and has a complete unchanged H. Original symbols and direct source-file debug records remain unavailable, preventing a 95-plus final-source claim for the file/class.
- The ordinary callbacks now implement the complete inventory, ownership, layout, compiler dispositions, header, four authored methods, exact Surface dependency, and slot-7 consumer evidence. CN1-003, CN1-010, CN1-055, CN1-057, and CN1-058 are applied and checked; the later narrow UID000122 callback also physically applied, scoped-validated, and reread the corrected canonical A05/A06 body hashes for CN1-014/CN1-015. The exact manual coverage payloads CN1-041..047 are already physically present and remain unchecked solely for supervisor verification/no-op; supervisor IDA Gate 2B CN1-048..054 and the remaining IDA/save/lifecycle portion of CN1-056 remain proposed and unchecked.

## Supporting Research

- Fresh read-only IDA evidence was collected on 2026-08-16 from canonical session `supervisor_uid0000li_i21rollback_20260816` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Public `runtime_attestation` schema 1 returned `ok:true`, `errors:[]`, listener `127.0.0.1:13337` PID `14320`, worker route `127.0.0.1:57948`, registered redirector PID `20568`, worker PID `11500`, and exact session/path agreement. These are dated read-only receipts and confer no future mutation authority.
- The preceding session `supervisor_uid0000li_i18rollback_20260816` answered bounded health/lookup requests but disappeared during a deeper call. Research paused, the supervisor-owned replacement session was selected, and every material bounded query was repeated successfully on that dated replacement session.
- `server_health` was `status:ok`, imagebase `0x400000`, module `NexusTK.exe`, Hex-Rays ready, and `auto_analysis_ready:false`. Successful bounded IDB queries make that flag context rather than an availability failure.
- Assignment-time target identity: [UID:0000N1] SHA256 `FAA0647731F56FDD84E481DCB5D06B2882F0494687C496B5D8F0F9A0862B989B`, 18,808 bytes / 116 physical lines.
- Dated generated snapshot: `auto-generated/NexusTK/ui/controls/RectangleControlPane.cpp`, validator command `000000024621`, refreshed `2026-08-16T00:23:06-04:00`, SHA256 `EF901B5AA246468C619F3FF2D7CC6955B8C1946D81DC2A5CBDF9B5CA5B6A085B`, 1,464 bytes / 33 physical lines. It contains constructor, ordinary destructor, and `OnPaint`, followed by empty-emitter markers for UID0000BT, UID000128, UID0002OE, and UID0003IT. `RectangleControlPane.h` is absent. This dated snapshot has no continuing current-state authority; callback validation must use fresh generated readback.
- Dated research-tracker snapshot: SHA256 `1DD930388A92EDB1083BEC56D0EF95D58C61F0D17F0D54C17C99B6F52B624343`, 1,763,297 bytes / 6,907 physical lines. Its Rectangle row was 7 total / 3 covered / 4 empty / 42.9 percent.
- Dated implementation-generated receipt: validator command `000000024682`, refreshed `2026-08-16T01:45:46-04:00`. `RectangleControlPane.cpp` SHA256 `AF85123FCDBC735F3175357E57C0DDC56315561A4C321ACD6A4C00454D9AB25E`, 1,275 bytes / 34 lines; `RectangleControlPane.h` SHA256 `CEE19406A34B1C6FCE218B1E45565DFFFD66419803FAD2901BCA778038281AAB`, 718 bytes / 23 lines. Fresh callback readback found the exact four-definition order, complete H, and no empty/fallback/compiler-glue markers. These hashes are dated receipts; current generated identity remains dynamic.
- Repair-time read-only IDA evidence from dated session `supervisor_uid0000li_i37rollback3_20260816` was schema-1 attested against the canonical IDB and reconfirmed `0x00499d00`: `mov ecx,esi`, `push &outBounds`, then `call dword ptr ds:69B3FCh`. Decompilation is exactly `GrafPort_GetBounds(this,&outBounds); MEMORY[0x69B3FC](this,&outBounds);`. This session is historical evidence only and confers no mutation authority.
- Repair-time support evidence selected the direct Surface-global route. The dated pre-callback UID0000TN identity was SHA256 `9835A9E4F6BBF133191441DD709F8340A32873785EA575E93519D34F5F0C2FB3`, 96,342 bytes / 567 lines. Accepted callback UID0000TN identity after scoped validation is SHA256 `CC72D4E3A35D4774E8314AB981FA4429705324A9FED88BFF935B0014058FC0C3`, 98,307 / 578; it preserves `SurfaceFillRectProc`, the one `g_pfnFillRect` definition, the extern declaration, `94/95`, UID0000OC owner/emitter, and position 20 while adding the exact Rectangle consumer. [UID:0000OC] `by-file/Surface.md` (dated evidence SHA256 `5EFC71B47B170DB5ACB121BFB0BA53F217C37164C4F2C1720BF416F82B74E5D0`, 143,638 / 621) owns `NexusTK/render/Surface.cpp/.h`. [UID:0000JR] `by-file/GrafPort.md` (dated evidence SHA256 `5827AA846A1E81985A8DCB84174372188235643BE78FA211787D8E1FF71A69B7`, 63,686 / 321) explicitly records that slot 7 has no GrafPort member/vtable route and needs no GrafPort metadata or formal-source change.
- Repair-time generated dependency readback found `Surface.h` SHA256 `D3811B8FE092E3BA48F26E7954EE5522A2D796B9817EF1FDAC1C99AD615D6DCF`, 3,087 / 102, with exact typedef `void (__thiscall *)(GrafPort *,const RectBounds *)` and `extern SurfaceFillRectProc g_pfnFillRect`; `GrafPort.h` SHA256 `2094DF4BDB150323FE820F4779DB11EAA97551355BA9D687E31964F247F91AD4`, 5,066 / 124, has no `FillRect` declaration. These generated identities are dated evidence and remain dynamically owned by validator refresh.
- Dated accepted-callback generated receipt: owning-file command `000000024719`, timestamp `2026-08-16T04:18:26-04:00`, exited `0` with `ok:1` and completed generated refresh. Physical CPP SHA256 `8CEBD211524AD72E55B61D11249CFD25F3372BC7C14B200FAD6F4F587158A6C4`, 1,320 bytes / 35 lines; H SHA256 `844A89529E7E93535E1E68E26CEC6D8B723FAEAC0337839305DB50B1E8DD498B`, 718 bytes / 23 lines. The CPP has both includes, exactly four authored definitions in positions `20/30/40/50`, and direct `g_pfnFillRect(this, &bounds)`; the H is complete and unchanged. Target-specific empty/stub/placeholder/compiler-glue scans were all zero. These identities are dated receipts; fresh supervisor Gate readback remains the dynamic authority.
- Dated Gate 2B preflight-repair evidence was re-read through public read-only MCP on 2026-08-16 from session `supervisor_uid0000md_persistverify_20260816` at exact canonical path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. Public `runtime_attestation` schema 1 returned `ok:true`, `errors:[]`; `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, and Hex-Rays ready. B006 then re-read all seven A01-A07 entities through `lookup_funcs`, `inspect_items`, `stack_frame`, `get_comments`, `xref_query`, and `get_bytes`. A01/A03/A07 had the exact weak-type drift repaired below; A02 and A04-A06 matched their literal prestates. All seven function ranges, body bytes/hashes, frames outside the stated type-dependent rows, comments, inbound/entry-continuation xrefs, and protected identities remained compatible. This session/attestation is dated evidence only; it grants no future mutation authority. The failed supervisor preflight and this B006 recheck performed no IDA mutation, backup, or save.

## Target

- Primary target: [UID:0000N1] `by-file/RectangleControlPane.md`.
- Additional target UIDs: none. Every other UID below is support evidence or an affected implementation destination, not an additional report-coverage declaration.
- Assignment-time metadata was `86/88`. Physical metadata is `COMPLETION:94`, `CONFIDENCE:95`, path `NexusTK/ui/controls/`, `CANONICAL_OWNER:FILE`; accepted callback implementation, scoped validation, generated refresh, and physical CPP/H readback now justify that source-closure score.
- Whole-file boundary: the authored class source comprises constructor `[0x00499c60,0x00499cd2)`, ordinary destructor `[0x00499ce0,0x00499cff)`, `OnPaint` `[0x00499d00,0x00499d37)`, and terminal virtual `HitTestPart` `[0x0049b8f0,0x0049b8f5)`. Compiler-generated destructor family, vtables, RTTI, and alignment are file-associated binary evidence but not handwritten source definitions.
- The file has no source-owned globals, statics, resources, imports, string literals, tables, or new data members. The only class-specific data cluster is compiler-emitted vtable/RTTI storage.

## Current Target State

- The current file page now settles the minimal filled-rectangle control as standalone `ui/controls` source, records the sole MiniMap consumer, and exhaustively separates four authored definitions from destructor/vtable compiler output.
- The former no-argument "type id" assumption is preserved only as rejected history. UID000128 is renamed and documented as `HitTestPart(int,int)` with exact ABI, slot, sibling, source position, and formal C++.
- [UID:0000BT] emits `#include "RectangleControlPane.h"`, `#include "../../render/Surface.h"`, then child expansion at position `10`; UID00011R uses the declaration-owned callback directly. The complete H declaration remains correct and unchanged. Method definitions remain at positions `20/30/40/50`.
- UID0002OE and UID0003IT are now class-attributed but non-reconstructable/non-emitting. UID000122 and UID000125 remain compiler no-code. No compiler product produces a generated source body or empty marker.
- Dated command `000000024682` remains historical proof of the former undeclared-member defect. Accepted callback command `000000024719` supersedes that defect with both required includes, the same exact four-definition order, direct `g_pfnFillRect(this, &bounds)`, complete H, and zero target-specific empty/fallback/stub/placeholder/compiler-glue markers. Generated identity is dynamic, so the hashes in Supporting Research are dated callback receipts rather than permanent authority.
- Related docs checked: UID0000BT, UID00011Q, UID00011P, UID0004HL, UID00011R, UID000122, UID000125, UID000128, UID0002OE, UID0003IT, StaticTextControlPane2, ButtonChoiceControlDestructors, NumericRectangleControlPaneVtables, MiniMap, MiniMapDialog, PaneCore, GrafPortDrawStateAccessors, SurfaceRenderCallbackTable, proposed-source-tree, all matching manual coverage rows, dated generated snapshots, and the dated tracker snapshot.
- Complete inventory: four authored definitions; two adjustor thunks; one scalar deleting wrapper; one core split container; one 164-byte vtable/RTTI data range; one vtable layout page; three COL/vtable views; seven RTTI bases; three short alignment gaps; one compiler EH continuation; no source-owned global/static/resource/import/string/table item.
- Report execution/archive state is supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata.

## Executive Recommendation

- Keep direct owner `FILE` for UID0000N1 and direct class owner/emitter UID0000N1 for UID0000BT.
- Implement one complete class declaration and CPP preamble through UID0000BT, then route all four authored definitions through child positions `20/30/40/50`.
- Rename the UID000128 page to `0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md` without changing UID or range.
- Reclassify UID0002OE and UID0003IT as non-reconstructable, clear their emitter routes, and retain their class owner and complete evidence. This matches the repaired CheckBoxControlPane vtable policy.
- Keep UID000122 and UID000125 no-owner/non-emitting. They are compiler ABI output, not source methods.
- Preserve exact behavior: base kind `8`, draw-color setup, full-bounds fill, empty authored destructor, and fixed hit-test part `21`.
- Implement full-bounds fill as `g_pfnFillRect(this, &bounds)` after including `../../render/Surface.h`; do not invent `GrafPort::FillRect` or transfer callback ownership away from UID0000TN/UID0000OC.

## Supervisor Active Recheck

- The supervisor assigned this uncovered by-file whole-file target and required complete inventory, formal CPP/H, source placement, IDA handoff, score movement, manual coverage text, and zero-loss support planning.
- No target split was required. The existing child partition correctly separates authored methods, compiler destructor glue, and vtable data; only UID000128's semantic title/source route and the vtable reconstructable flags are wrong.
- Every reasonably discoverable child has exact binary/source disposition, and the accepted Surface include/direct-global repair now gives the paint child truthful generated callable closure.
- The open standalone-versus-broad-control-file question was actively rechecked against physical clustering, dedicated RTTI/vtables, project topology, analog controls, consumers, and negative boundary evidence; standalone is the highest-probability conclusion.

## Inference Research Guidance Check

- Direct IDA facts are addresses, bytes, item/function state, types, frames, comments, xrefs, callers/callees, constants, vtable slots, RTTI names, and decompilation.
- Documentation evidence is current by-* metadata/prose/formal source, generated output, coverage rows, tracker state, and source-tree routes.
- Inference supplies human source names, the standalone compilation-unit boundary, class declaration/access shape, and source order where symbols/debug file records are absent.
- Exact execution fidelity ranks first, human-written late-1990s/mid-2000s C++ source shape second, and cross-project naming consistency third.
- Existing "type id" and possible broad-file-fold assumptions were treated as hypotheses, not facts. Raw `sub_*`, `_DWORD`, and decompiler ownership labels are not carried into final source.
- No Wave2/Wave3 evidence was used. Any historical mention of those workflows is stale under the current skill.

## Heuristic / Inference Reanalysis And Validation

| Issue | Reanalysis | Best-supported resolution |
| --- | --- | --- |
| Terminal five-byte virtual | `0x0049b8f0` returns 21 with `retn 8`, occupies primary slot `0x00618494`, and has current weak type `char __stdcall(int,int)`. Same-slot CheckBox `0x0049b8d0` and Scrollable `0x0049b900` are named `HitTestPart` overrides with two coordinates and fixed byte returns. | Authored `unsigned char RectangleControlPane::HitTestPart(int,int)`, not a no-argument type-id helper. |
| Standalone source unit | Constructor/destructor/paint are one contiguous class island; terminal virtual is in the shared tail-virtual island; RTTI/vtables are dedicated; current source tree and analogous controls use standalone files. | Keep `RectangleControlPane.cpp/.h`. The broader `BasicControlPanes.cpp` fold is rejected as unsupported. |
| Class layout | Constructor passes kind 8 and installs complete, EventHandler, and TimerHandler views at offsets `0`, `0xA0`, and `0xA4`; scalar delete size is `0x108`. No Rectangle-specific field access occurs. | Inherit `ControlPane` without new data members; exact size comes entirely from the base layout. |
| Destructor source | Ordinary body only restores compiler vptrs then tears down Pane; no Rectangle-specific cleanup. Scalar wrapper and two adjustors implement delete ABI. | Authored out-of-line empty virtual destructor; all deleting glue remains compiler-covered/no-code. |
| Paint name/type | Primary vtable slot points to `0x00499d00`; body copies bounds and invokes the shared rectangle callback. | Protected virtual `void OnPaint()`; reject generic `Paint` and invalidation-helper alternatives. |
| Constructor parameter names | Kind 8 is fixed; second source parameter becomes inherited draw color; third is bounds. | `RectangleControlPane(int drawColor, const RectBounds *bounds)`. |
| IDA weak types | Constructor/paint/terminal virtual currently carry base/decompiler-shaped types; thunks/scalar carry weak compiler-glue types. | Formal source uses exact inferred class types. Structured IDA handoff proposes safe staged type updates only for authored constructor/paint/hit methods; compiler-glue types are protected. |
| Vtable emission | Assignment-time vtable pages were reconstructable and created empty markers, but the C++ compiler generates storage from the class declaration. | Applied class-owned evidence, `RECONSTRUCTABLE:FALSE`, blank emitters/formal source. |
| Consumer ownership | Sole constructor caller is MiniMap dialog code. No Rectangle method/data is MiniMap-specific. | MiniMap is consumer evidence only; generic control remains under `ui/controls`. |
| Missing header | Final source needs inheritance, virtual declarations, constructor signature, and forward declaration for `RectBounds`. | Required sibling H generated by the class formal H block. |
| Rectangle fill dependency | Binary `0x00499d22` is a direct indirect call through slot `0x0069b3fc` with `this` in `ecx` and `&bounds` on the stack. UID0000TN already emits the exact `SurfaceFillRectProc g_pfnFillRect` definition/extern in `Surface.cpp/.h`; generated `Surface.h` exposes it. GrafPort docs explicitly reject a member/vtable route, and generated `GrafPort.h` has no such declaration. | Include `../../render/Surface.h` in RectangleControlPane.cpp and call `g_pfnFillRect(this, &bounds)`. Preserve RectangleControlPane.h unchanged and keep UID0000TN/UID0000OC ownership/metadata/formal declarations. |

Rejected alternatives:

- Keep `RectangleControlPaneTypeId`: rejected by `retn 8`, primary-slot position, and two independently named same-slot siblings.
- Emit scalar deleting destructor/adjustors/vtables as source: rejected because standard MSVC class/destructor declarations generate them.
- Fold into MiniMap: rejected because MiniMap only allocates the reusable control and the class is physically/topologically generic.
- Fold into ControlPane/GrafPort: rejected because those are base/dependency owners and Rectangle has dedicated RTTI, vtables, constructor, destructor, and virtual overrides.
- Invent a draw-color field: rejected because the constructor calls inherited `SetDrawColor` and no new field is accessed.
- Add `GrafPort::FillRect(const RectBounds *)`: rejected because no member body, symbol, vtable slot, or current declaration exists; UID0000JR explicitly records no GrafPort member route, while the binary calls global slot `0x0069b3fc` directly.

## Evidence Standards Used

- Strongest evidence: exact bytes/ranges/hashes, vtable data refs, named same-slot siblings, direct constructor caller, complete function bodies, compiler ABI patterns, and decorated RTTI/vtable identities.
- Corroboration: current by-* hierarchy, analog CheckBox source policy, generated emitter behavior, proposed source tree, and subsystem consumers.
- Negative evidence: absent ordinary callers for vtable-only methods/glue, no source-owned data/resource/import/string inventory, no source-file debug symbols, and no evidence for MiniMap/base/broad-file ownership.
- The evidence supports high-confidence behavior and the implemented direct-global source shape. Missing original lexical symbols and debug source-file records cap final confidence below proof-level 96-plus; accepted callback validation and physical generated readback verified the exact callable route.

## Evidence Checked

- MCP: `idb_list`, `runtime_attestation`, `server_health`, `lookup_funcs`, `analyze_function`, `inspect_items`, `stack_frame`, `get_comments`, `xref_query`, bounded bytes/disassembly, and vtable/RTTI entity lookups.
- Functions checked: `0x00499c60`, `0x00499ce0`, `0x00499d00`, `0x0049afc1`, `0x0049afcc`, `0x0049b490`, `0x0049b8f0`, sibling `0x0049b8d0`, sibling `0x0049b900`, and MiniMap caller `0x004523d0`.
- Data checked: `[0x00618430,0x006184d4)`, primary/secondary/tertiary vtable heads, key slots, COLs, type descriptor, successor CheckBox boundary, and predecessor Numeric boundary.
- Boundaries checked: exact authored ranges, `0xCC` gaps, adjustor pair, scalar pre/post padding, terminal-virtual pre/post padding, and vtable data range.
- Documentation checked: all target/support pages named in Current Target State; UID0000TN/UID0000OC Surface ownership and formal declarations; UID0000JR GrafPort's explicit no-member-route evidence; generated Surface.h/GrafPort.h/RectangleControlPane CPP/H; manual coverage rows; research tracker; proposed source tree; and matching historical-report searches by UID/address/name.
- Negative searches found no extra Rectangle-authored function, global/static, resource/import, string/table, or separate data definition needing source emission.
- Research remained read-only in IDA. The accepted callback changed only the listed ordinary documentation/report files, ran scoped validators, and permitted validator-owned generated refresh. No IDA mutation/save, manual coverage edit, report execution, or archive movement was performed.

## Claim And Incorporation Ledger

Implementation-return allocation: 43 checked / 15 unchecked across 58 claims. All accepted ordinary claims, including reopened CN1-003/CN1-010/CN1-055/CN1-057/CN1-058 and the current UID000122 A05/A06 hash correction for CN1-014/CN1-015, are applied and physically verified. Coverage rows CN1-041..047 are already present and remain unchecked for supervisor verification/no-op. IDA CN1-048..054 and the remaining IDA/save/lifecycle work in CN1-056 remain proposed. The checklist is the exact eight-field twin after removing `Done`.

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| CN1-001 | 0000N1 | Settle standalone `NexusTK/ui/controls/RectangleControlPane.cpp` with required sibling H. | Strong | Dedicated class island/RTTI/vtables; source-tree analogs. | UID0000N1 Status/Ownership/Source Placement | incorporate | applied |
| CN1-002 | 0000BT | Define RectangleControlPane as ControlPane-derived, size `0x108`, with no new data members. | Very strong | Constructor/scalar size; no derived field accesses. | UID0000BT Class Purpose/Layout | incorporate | applied |
| CN1-003 | 0000BT | Emit exact CPP preamble with `#include "RectangleControlPane.h"`, `#include "../../render/Surface.h"`, then `[[CHILDREN]]`. | Certain | Applied formal CPP and generated command 24719 exact include readback. | UID0000BT RECONSTRUCTION_CPP CODE | incorporate | applied |
| CN1-004 | 0000BT | Emit complete formal H declaration with constructor, virtual destructor, OnPaint, HitTestPart, and RectBounds forward declaration. | Very strong | Complete authored inventory/vtable surface. | UID0000BT RECONSTRUCTION_H CODE | incorporate | applied |
| CN1-005 | 0000N1 | Use source positions class 10, constructor 20, destructor 30, OnPaint 40, HitTestPart 50; UID0004HL current prose explicitly records position 30. | Very strong | Physical/source dependency order; correction command 000000024896. | UID0000N1 source-order table; child metadata | incorporate | applied |
| CN1-006 | 00011P | Preserve ctor range `[0x00499c60,0x00499cd2)`, 114 bytes, SHA256 `327363D27A59A1FA412FD0B26772EB1A226085D2ECCAD156F9121FD21EA23538`. | Certain | MCP/local binary hash. | UID00011P Exact Binary Identity | incorporate | applied |
| CN1-007 | 00011P | Emit constructor `: ControlPane(8,bounds)` and `SetDrawColor(drawColor)`; vptr stores are compiler output. | Very strong | Full decompile/assembly and helper identity. | UID00011P Behavior/formal CPP | incorporate | applied |
| CN1-008 | 00011P | Record sole caller `0x0045252c` in MiniMap function `0x004523d0` and compiler EH continuation at `0x005fd191`. | Certain | Fresh xrefs/function analysis. | UID00011P Callers/EH; UID0000N1 Evidence | incorporate | applied |
| CN1-009 | 0004HL | Preserve `[0x00499ce0,0x00499cff)`, SHA256 `963C57BEA32FB9D07CEFA3DC6D519C4DCFD699B0D20F1522A96059AD0608B4F9`, as authored empty ordinary destructor. | Very strong | Exact body, no direct caller, compiler teardown shape. | UID0004HL Identity/CPP; UID0000BT Method Map | incorporate | applied |
| CN1-010 | 00011R | Preserve `[0x00499d00,0x00499d37)`, SHA256 `BF22E68F1908E0FA2F8588FCD95674D9A46B137C82524614ADD59E0D6AE87E33`, as OnPaint copying bounds then calling `g_pfnFillRect(this,&bounds)`. | Certain | Applied formal CPP; exact ECX/stack/global-slot ABI; generated command 24719 readback. | UID00011R Identity/CPP; UID0000BT Method Map | incorporate | applied |
| CN1-011 | 000128 | Preserve `[0x0049b8f0,0x0049b8f5)`, SHA256 `385706FAB0C4627BC251D23DF72EEA0C738DC9FD150143FCD23390DC9F2B36B8`, rename semantic/path identity to RectangleControlPaneHitTestPart, emit fixed-return `HitTestPart(int,int)`, and use that current identity in constructor sibling prose while retaining type-id only as dated superseded history. | Certain | `retn 8`, slot `0x618494`, sibling named overrides; correction commands 000000024895/000000024899. | UID000128 title/path/identity/CPP; UID00011P sibling evidence; UID0000N1 inventory | reject-stale | applied |
| CN1-012 | 000128 | Preserve same-slot CheckBox return 20 and Scrollable return 18 as independent signature/name corroboration. | Certain | Fresh sibling function types/frames/vtable refs. | UID000128 Type/Slot Evidence | incorporate | applied |
| CN1-013 | 00011Q | Preserve core children and gaps: 14-byte ctor gap, one-byte dtor gap, nine-byte trailing CC alignment. | Certain | Exact bytes/hashes and item boundaries. | UID00011Q split/boundary table | incorporate | applied |
| CN1-014 | 000122 | Preserve A0 adjustor `[0x0049afc1,0x0049afcc)`, exact canonical bytes `81 E9 A0 00 00 00 E9 C4 04 00 00`, and corrected SHA256 `B4B18B0EB6661954847D9BE7E3CF8630B876E81CB29DB8FB46B3D8A6C5DBA1E8`. | Certain | Fresh public `get_bytes` output and independent SHA256 recomputation; UID000122 command `000000025096` exited `0` with `ok:1`; current destination physically reread. | UID000122 thunk inventory | incorporate | applied |
| CN1-015 | 000122 | Preserve A4 adjustor `[0x0049afcc,0x0049afd7)`, exact canonical bytes `81 E9 A4 00 00 00 E9 B9 04 00 00`, and corrected SHA256 `D1CAB38FF0C6FDD535AEF489A2279E8CE885299C88B77972EA827326FC97B14E`. | Certain | Fresh public `get_bytes` output and independent SHA256 recomputation; UID000122 command `000000025096` exited `0` with `ok:1`; current destination physically reread. | UID000122 thunk inventory | incorporate | applied |
| CN1-016 | 000125 | Preserve scalar wrapper `[0x0049b490,0x0049b4e5)`, 85 bytes, SHA256 `CFA7F3A8CCF45931D37CECF32C567418671B7B51D68A9A59E13E42358F5D43D5`, as compiler no-code. | Certain | Full body/vtable/thunk refs/delete flags. | UID000125 Identity/No-Code Proof | incorporate | applied |
| CN1-017 | 0000BT | Preserve exact complete-object size `0x108` and subobject offsets `0/0xA0/0xA4`. | Certain | Scalar delete size; COL/vptr stores. | UID0000BT Layout/ABI | incorporate | applied |
| CN1-018 | 0002OE | Preserve vtable data `[0x00618430,0x006184d4)`, 164 bytes, SHA256 `BE245C307949282DC57E5EB938C0FA85DDB5A50AC43F8EA58FF8BA47A4A6E277`. | Certain | Exact data/hash/boundaries. | UID0002OE Exact Binary Identity | incorporate | applied |
| CN1-019 | 0002OE | Record 25-slot primary, 11-slot secondary, 2-slot tertiary views; paint slot `0x618478`, hit slot `0x618494`, adjustors `0x61849c/0x6184cc`. | Certain | Fresh vtable data/xrefs. | UID0002OE Slot Map; UID0003IT | incorporate | applied |
| CN1-020 | 0003IT | Preserve COL offsets `0/0xA0/0xA4` and seven-base hierarchy Rectangle/ControlPane/Pane/GrafPort/LObject/EventHandler/TimerHandler. | Certain | Decorated RTTI/COL entities. | UID0003IT RTTI/Layout | incorporate | applied |
| CN1-021 | 0002OE | Make UID0002OE and UID0003IT non-reconstructable/non-emitting while retaining class ownership and evidence. | Certain | Compiler emits vtables/RTTI from class declaration. | UID0002OE/UID0003IT metadata | incorporate | applied |
| CN1-022 | 0000N1 | Record no source-owned globals/statics/constants/tables beyond compiler vtable/RTTI data. | Very strong | Whole-file data/global search. | UID0000N1 Complete Inventory | not-applicable | excluded-with-reason |
| CN1-023 | 0000N1 | Record no source-owned strings, resources, imports, or third-party embeds. | Very strong | Function/string/import/resource audit. | UID0000N1 Complete Inventory | not-applicable | excluded-with-reason |
| CN1-024 | 0000N1 | Preserve MiniMap as sole confirmed constructor consumer, not source owner. | Certain | Caller `0x45252c`; generic class semantics. | UID0000N1 Consumers; MiniMap verify-only | incorporate | applied |
| CN1-025 | 0000N1 | Reject MiniMap, ControlPane/GrafPort, and broad BasicControlPanes fold as weaker owners/placements. | Strong | Consumer/base-only relationships; no fold evidence. | UID0000N1 Ownership Decision/Historical Alternatives | reject-stale | applied |
| CN1-026 | 0000N1 | Physical score change `86/88 -> 94/95` and unchanged path/FILE owner are applied and source-closure justified. | Strong | Whole inventory, direct-global repair, validators, generated CPP/H readback. | UID0000N1 metadata/Score | incorporate | applied |
| CN1-027 | 0000BT | Physical score change `85/89 -> 94/95`, owner/emitter, position 10, and exact CPP dependency preamble are applied. | Strong | Complete class surface and generated two-include readback. | UID0000BT metadata | incorporate | applied |
| CN1-028 | 00011Q | Raise core `88/92 -> 92/94`; remain non-reconstructable/no emitter. | Strong | Complete split/boundary inventory. | UID00011Q metadata | incorporate | applied |
| CN1-029 | 00011P | Raise constructor `88/92 -> 92/94`; retain class route and position 20, with former scores only in dated history. | Strong | Exact body/caller/source resolved; correction command 000000024895. | UID00011P metadata/current score prose | incorporate | applied |
| CN1-030 | 0004HL | Keep `92/94`; retain class route and explicit source position 30. | Very strong | Exact ordinary destructor source and correction command 000000024896. | UID0004HL metadata/source-position prose | already-present | applied |
| CN1-031 | 00011R | Physical score change `86/90 -> 92/94`, class route, position 40, exact direct-global body, and current score prose are applied and verified. | Strong | Exact body/name/callback ABI; correction command 000000024897 and generated readback. | UID00011R metadata/current gate | incorporate | applied |
| CN1-032 | 000122 | Raise adjustors `88/92 -> 92/94`; remain NONE/FALSE/no emitter, with `88/92` retained only as dated history. | Strong | Exact thunk pair/compiler cause and correction command 000000024898. | UID000122 metadata/current score rationale | incorporate | applied |
| CN1-033 | 000125 | Raise scalar wrapper `88/92 -> 92/94`; remain NONE/FALSE/no emitter. | Strong | Exact wrapper/delete ABI/no-code proof. | UID000125 metadata | incorporate | applied |
| CN1-034 | 000128 | Raise corrected HitTestPart `88/92 -> 94/96`; owner/emitter UID0000BT, position 50, reconstructable true, with exact body SHA256 `385706FAB0C4627BC251D23DF72EEA0C738DC9FD150143FCD23390DC9F2B36B8`. | Very strong | Exact slot/body/sibling proof and correction command 000000024899. | Renamed UID000128 metadata/identity | incorporate | applied |
| CN1-035 | 0002OE | Raise vtable data `87/92 -> 94/96`; owner UID0000BT, reconstructable false, blank emitter; historicalize `87/92`/reconstructable-true wording. | Very strong | Exact complete cluster/class cause and correction command 000000024900. | UID0002OE metadata/current and historical score rationale | incorporate | applied |
| CN1-036 | 0003IT | Raise vtable type `88/93 -> 94/96`; owner UID0000BT, reconstructable false, blank emitter; historicalize the former owner/emitter/reconstructable state. | Very strong | Exact layout/RTTI/class cause and correction command 000000024901. | UID0003IT metadata/assignment/current-state prose | incorporate | applied |
| CN1-037 | 000128 | Correct stale Rectangle "type-id" references in StaticTextControlPane2 support. | Certain | Same-slot semantic correction. | StaticTextControlPane2 historical/cross-reference prose | reject-stale | applied |
| CN1-038 | 000128 | Correct stale Rectangle "type-id" references in ButtonChoiceControlDestructors while retaining historical correction context. | Certain | Same-slot semantic correction. | ButtonChoiceControlDestructors child map/history | reject-stale | applied |
| CN1-039 | 0003IT | Correct NumericRectangleControlPaneVtables Rectangle slot `+0x60` and source-emission disposition. | Certain | Exact vtable slot/layout. | NumericRectangleControlPaneVtables | reject-stale | applied |
| CN1-040 | 0000N1 | Keep proposed-source-tree standalone RectangleControlPane entry and mark former fold uncertainty historical. | Strong | Source placement analysis. | proposed-source-tree Rectangle entry | already-present | applied |
| CN1-041 | 0000N1 | Supervisor verify/no-op: the exact 94 percent standalone source/header/HitTestPart by-file coverage row is already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 86-percent row is historical. | by-file/-coverage-report.md | already-present | supervisor-verify |
| CN1-042 | 0000BT | Supervisor verify/no-op: the exact 94 percent complete class/header/method-surface by-class coverage row is already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 85-percent row is historical. | by-class/-coverage-report.md | already-present | supervisor-verify |
| CN1-043 | 00011Q | Supervisor verify/no-op: the exact core/constructor/destructor/paint rows with current scores and HitTest-aware source route are already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage rows/scores are historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| CN1-044 | 000122 | Supervisor verify/no-op: the exact adjustor/scalar 92 percent compiler no-code rows are already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 88-percent rows are historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| CN1-045 | 000128 | Supervisor verify/no-op: the old TypeId row is absent and the renamed 94 percent HitTestPart row is already physically present in address order. | Certain | Fresh supervisor coverage audit confirms the corrected path/title/role row. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| CN1-046 | 0002OE | Supervisor verify/no-op: the exact 94 percent non-reconstructable class-generated vtable-data row is already physically present. | Certain | Fresh supervisor coverage audit; the dated reconstructable 87-percent row is historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| CN1-047 | 0003IT | Supervisor verify/no-op: the exact 94 percent non-reconstructable class-generated vtable-type row is already physically present. | Certain | Fresh supervisor coverage audit; the dated reconstructable 88-percent row is historical. | by-vtable/-coverage-report.md | already-present | supervisor-verify |
| CN1-048 | 00011P | Stage safe ctor rename/type/repeatable-comment handoff from exact weak pretype `_DWORD *__thiscall(_DWORD *this, int, int *)`; preserve the IDA frame row `color/+0x20/4/int` through R/T/C while `set_type` changes only `arg_4` to `bounds/+0x24/4/const RectBounds *`. The strong source-facing signature may retain `drawColor`; no cosmetic stack/local rename is authorized. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread, observed public `set_type` poststate, and current public endpoint schemas. | Supervisor Gate 2B A01 | incorporate | proposed |
| CN1-049 | 0004HL | Stage safe ordinary-dtor rename/repeatable-comment handoff while preserving existing FR. | Strong | Fresh exact type/frame/comments/body. | Supervisor Gate 2B A02 | incorporate | proposed |
| CN1-050 | 00011R | Stage safe OnPaint rename/type/repeatable-comment handoff from exact weak pretype `int __thiscall(void *this)` with the complete local/saved/return frame preserved through R/T/C states. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread plus current public endpoint schemas. | Supervisor Gate 2B A03 | incorporate | proposed |
| CN1-051 | 000128 | Stage HitTestPart rename/type/repeatable-comment handoff with exact x/y frame result. | Very strong | Named same-slot sibling types/frames. | Supervisor Gate 2B A04 | incorporate | proposed |
| CN1-052 | 000122 | Stage A0 adjustor rename/comment only; preserve weak type and sole return row. | Strong | Exact thunk body/frame/xref. | Supervisor Gate 2B A05 | incorporate | proposed |
| CN1-053 | 000122 | Stage A4 adjustor rename/comment only; preserve weak type and sole return row. | Strong | Exact thunk body/frame/xref. | Supervisor Gate 2B A06 | incorporate | proposed |
| CN1-054 | 000125 | Stage scalar-wrapper rename/comment only from exact weak pretype `_DWORD *__thiscall(_DWORD *Block, char)`; preserve the complete saved/return/argument frame and delete ABI through R/C states. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread plus current public endpoint schemas. | Supervisor Gate 2B A07 | incorporate | proposed |
| CN1-055 | 0000N1 | Scoped-validate every changed ordinary page, validate the owning file with generated wait, and physically verify both CPP/H declarations and callable closure. | Certain | Commands 24710/24712/24715/24717/24719; exact CPP/H hashes and zero-marker scan. | Validator/generated checklist | incorporate | applied |
| CN1-056 | 0000N1 | Keep the remaining IDA mutation/save, report execution, and archive movement supervisor-owned; manual coverage is already present and requires only supervisor verification/no-op. | Certain | Role/lifecycle rules and current already-present C041-C047 coverage state. | IDA/lifecycle checklist; coverage verification no-op | incorporate | proposed |
| CN1-057 | 0000N1 | Document the exact Surface dependency route, required relative include, direct global-call ABI, rejected GrafPort-member alternative, unchanged H, and resolved score/closure state. | Certain | Applied file section; IDA call; generated header comparison; UID0000JR negative evidence. | UID0000N1 Dependencies/Source Closure/Score | incorporate | applied |
| CN1-058 | 0000TN | Add RectangleControlPane::OnPaint as an exact slot-7 consumer while preserving UID0000TN/UID0000OC ownership, 94/95 metadata, and existing Surface CPP/H typedef/global/extern text unchanged. | Certain | Applied consumer section and slot inventory; declaration/formals preserved; scoped validation. | UID0000TN Consumer Evidence; UID0000OC verify-only | incorporate | applied |

## Positive Evidence Summary

- Constructor, ordinary destructor, and paint form a tight contiguous class island; the terminal virtual is independently tied to the primary vtable.
- Three dedicated decorated vtable heads and three COL offsets exactly match the inherited complete/EventHandler/TimerHandler views and `0x108` object size.
- The constructor's only caller allocates the class for MiniMap UI but contains no ownership evidence; reusable control semantics and source topology point to `ui/controls`.
- Named same-slot siblings make the UID000128 signature and role certain despite the absent original Rectangle symbol.
- Constructor/destructor/HitTestPart bodies and the class H are source-ready. Paint behavior and source closure are now exact: the CPP includes Surface and uses declaration-owned `g_pfnFillRect(this,&bounds)` with the observed ABI.

## IDA MCP Facts

- `0x00499c60`: dated repair-snapshot name `sub_499C60`, range size `0x72`, exact item type `_DWORD *__thiscall(_DWORD *this, int, int *)`, sole inbound caller `0x0045252c`; frame argument `color/+0x20/4/int` remains exact. A later supervisor Gate 2B parser trial accepted the strong source-facing signature, retained this IDA frame-row name, and changed only `arg_4` to `bounds/+0x24/4/const RectBounds *`; the trial was rolled back without save and defines the deterministic A01 T/C contract below.
- `0x00499ce0`: current name `RectangleControlPane_destructor`, size `0x1f`, exact type `void __thiscall(RectangleControlPane *this)`, no inbound caller.
- `0x00499d00`: dated repair-snapshot name `sub_499D00`, size `0x37`, exact item type `int __thiscall(void *this)`, vtable data xref `0x00618478`; exact call sequence sets `ecx=this`, pushes `&outBounds`, and calls global slot `0x0069b3fc` directly.
- `0x0049afc1/0x0049afcc`: two 11-byte `this-0xA0/0xA4` jump adjustors, vtable refs `0x0061849c/0x006184cc`.
- `0x0049b490`: 85-byte scalar deleting wrapper, inbound refs `0x0049afc7`, `0x0049afd2`, and `0x00618434`.
- `0x0049b490`: dated repair-snapshot name `sub_49B490`, exact item type `_DWORD *__thiscall(_DWORD *Block, char)`, and unchanged complete frame `saved/+0x4/4/_DWORD; return/+0x8/4/_UNKNOWN *; arg_0/+0xc/4/_DWORD`.
- `0x0049b8f0`: current name `sub_49B8F0`, size `5`, type `char __stdcall(int,int)`, body `mov al,15h; retn 8`, vtable ref `0x00618494`.
- CheckBox `0x0049b8d0` is named `CheckBoxControlPane__HitTestPart`, typed with `this,x,y`, returns 20; Scrollable `0x0049b900` is named `ScrollableControlPane_HitTestPart`, has the same ABI, returns 18.
- All target action entities currently have AR/AP/FP absent. The ordinary destructor alone has a nonempty FR, quoted exactly in Section 21.
- Vtable data spans 164 bytes and terminates immediately before CheckBox; Numeric precedes it. No overlap or unclassified source-owned data remains.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Recommended score/status |
| --- | --- | --- | --- | --- | --- |
| File source root | UID0000N1 by-file/RectangleControlPane.md | Standalone CPP/H owner | file root | FILE | 94/95 |
| Class/type | UID0000BT by-class/RectangleControlPane.md | Complete declaration and CPP preamble | true | UID0000N1 | 94/95, position 10 |
| `[0x499c60,0x499d37)` split container | UID00011Q | Non-emitting authored-core index | false | UID0000BT | 92/94 |
| `[0x499c60,0x499cd2)` | UID00011P | Authored constructor | true | UID0000BT | 92/94, position 20 |
| `[0x499cd2,0x499ce0)` | UID00011Q | 14-byte CC alignment | no-code | UID00011Q | preserved |
| `[0x499ce0,0x499cff)` | UID0004HL | Authored out-of-line empty destructor | true | UID0000BT | 92/94, position 30 |
| `[0x499cff,0x499d00)` | UID00011Q | one-byte CC alignment | no-code | UID00011Q | preserved |
| `[0x499d00,0x499d37)` | UID00011R | Authored OnPaint; exact direct `g_pfnFillRect(this,&bounds)` implemented and generated | true | UID0000BT | 92/94, position 40 |
| `[0x499d37,0x499d40)` | UID00011Q | nine-byte CC alignment | no-code | UID00011Q | preserved |
| `0x005fd191` continuation | compiler EH | Constructor cleanup to Pane teardown | compiler-covered | constructor/base | preserve, no emitter |
| `[0x49afc1,0x49afcc)` | UID000122 | EventHandler-view deleting adjustor | false | NONE | 92/94 |
| `[0x49afcc,0x49afd7)` | UID000122 | TimerHandler-view deleting adjustor | false | NONE | 92/94 |
| `[0x49b487,0x49b490)` | UID000125 context | nine-byte prepad | no-code | NONE | preserved |
| `[0x49b490,0x49b4e5)` | UID000125 | Scalar deleting destructor wrapper | false | NONE | 92/94 |
| `[0x49b4e5,0x49b4f0)` | UID000125 context | eleven-byte postpad | no-code | NONE | preserved |
| `[0x49b8e5,0x49b8f0)` | UID000128 context | eleven-byte prepad | no-code | UID0000BT | preserved |
| `[0x49b8f0,0x49b8f5)` | UID000128 renamed HitTestPart | Authored terminal virtual | true | UID0000BT | 94/96, position 50 |
| `[0x49b8f5,0x49b900)` | UID000128 context | eleven-byte postpad | no-code | UID0000BT | preserved |
| `[0x618430,0x6184d4)` | UID0002OE | Compiler-emitted three-view vtables/RTTI refs | false | UID0000BT | 94/96, no emitter |
| Vtable layout | UID0003IT | Source-declaration evidence, no storage source | false | UID0000BT | 94/96, no emitter |
| RTTI COL/type hierarchy | within UID0002OE/UID0003IT | Three COLs, seven bases, type descriptor | compiler-covered | UID0000BT | documented, no emitter |
| Globals/statics/constants/tables | none discovered | No source-owned data definition | not applicable | UID0000N1 | explicit negative |
| Strings/resources/imports/third-party | none discovered | No source-owned item | not applicable | UID0000N1 | explicit negative |
| MiniMap constructor consumer | UID0000LE/UID00008C | Consumer only | external | MiniMap | excluded from file |
| Numeric predecessor / CheckBox successor | UID0001YA family | Neighbor boundary evidence | external | own files/classes | excluded from file |
| Surface rectangle callback declaration/definition | UID0000TN under UID0000OC | Required external dependency, typedef, extern, and storage owner | external support | UID0000OC | 94/95 unchanged; consumer link proposed |
| GrafPort fill-member alternative | UID0000JR | Rejected dependency route; no member/vtable body or declaration | verify-only support | UID0000JR | 89/88 unchanged; no edit |

Inventory reconciliation: 4 authored methods, 3 destructor ABI functions, 1 core container, 3 alignment families, 1 EH continuation, 1 vtable-data range, 1 vtable-layout page, 3 COL views, 7 RTTI bases, and zero source-owned global/resource/import/string items. Every row has a source/no-code, owner, metadata, destination, ledger, and checklist disposition.

## Direct Xref / Caller Inventory

| Address / item | Xref / caller / callee | Meaning |
| --- | --- | --- |
| `0x499c60` | inbound code `{0x45252c}`; entry continuation `0x499c61` | Sole ordinary construction route from MiniMap dialog cluster. |
| `0x499c60` | calls ControlPane construction, SetDrawColor; installs three vptrs | Exact constructor behavior; vptr stores are compiler output. |
| `0x499ce0` | no inbound xref; entry continuation and data ref to `0x618434` | Retained ordinary destructor body with no Rectangle cleanup. |
| `0x499d00` | inbound data `{0x618478}`; entry continuation | Primary-vtable-only OnPaint dispatch. |
| `0x499d00` | `GetBounds`; then `mov ecx,esi`, `push &outBounds`, `call [0x69b3fc]` | Exact `g_pfnFillRect(this,&bounds)` ABI and full-bounds solid fill; no GrafPort member call. |
| `0x49afc1` | inbound data `{0x61849c}`; jumps at `0x49afc7` to scalar wrapper | EventHandler-view destructor adjustment. |
| `0x49afcc` | inbound data `{0x6184cc}`; jumps at `0x49afd2` to scalar wrapper | TimerHandler-view destructor adjustment. |
| `0x49b490` | inbound `{0x49afc7 code,0x49afd2 code,0x618434 data}` | Complete-object scalar deleting wrapper. |
| `0x49b8f0` | inbound data `{0x618494}`; entry continuation `0x49b8f2` | Primary-vtable-only terminal HitTestPart override. |
| `0x618430-0x6184d4` | constructor/dtor/scalar vptr stores and function/data slots | Dedicated class topology and compiler artifacts. |
| MiniMap `0x45252c` | direct call to constructor | Consumer evidence only. |

## Documentation Evidence And IDA Status

- Applied ordinary docs preserve constructor kind/color behavior, authored empty ordinary destructor reasoning, exact direct-global paint bounds/callback behavior, corrected HitTestPart semantics, scalar/adjustor compiler exclusions, object size, three-view vtables, standalone source placement, MiniMap consumer evidence, Surface declaration ownership, and the rejected GrafPort-member alternative.
- Assignment-time docs called UID000128 a type id, left class CPP/H blank, kept file-split uncertainty current, and routed vtable pages as reconstructable emitters. Those facts are now explicitly historical rather than silently deleted.
- Dated research-time IDA had only the ordinary destructor partly source-named; constructor, paint, thunks, scalar wrapper, and terminal virtual retained raw/decompiler labels, and authored signatures were weak except the destructor. Supervisor Gate 2B must re-read every prestate before any mutation.
- Assignment-time generated command `000000024621` had no header, omitted HitTestPart, and showed vtable/class empty markers. Dated prior callback command `000000024682` fixed those structural defects but exposed `FillRect(&bounds)` as an undeclared call. Accepted dependency callback command `000000024719` supersedes that defect with both includes, direct `g_pfnFillRect(this, &bounds)`, complete H, and zero target-specific marker/glue results. Generated identity remains dynamic after each dated receipt.
- Incorrect type-id/fold/emitter assumptions remain in explicit historical-correction sections with the evidence that superseded them.

## Ranked Ownership Analysis

**1. Standalone RectangleControlPane.cpp/.h**

- Evidence for: dedicated constructor/destructor/paint island, dedicated terminal virtual and RTTI/vtables, generic class semantics, existing source-tree route, and standalone analog controls.
- Evidence against: no original debug source-file record and the authored body is small.
- Decision: highest-probability owner and final current route.

**2. Broader BasicControlPanes.cpp or another tiny-control aggregate**

- Evidence for: the class is small and adjacent binary code contains other controls.
- Evidence against: no named aggregate, no shared source-level helper/data, no combined emitter route, and current repaired controls use dedicated source roots.
- Decision: rejected; retain only as historical speculation.

**3. MiniMap.cpp**

- Evidence for: sole constructor caller is in MiniMap UI construction.
- Evidence against: no MiniMap-specific state or behavior; class has generic RTTI/vtable identity under control infrastructure.
- Decision: consumer only.

**4. ControlPane.cpp or GrafPort.cpp**

- Evidence for: base construction and inherited drawing helpers.
- Evidence against: base/dependency calls do not transfer ownership; Rectangle has its own type and virtual surface. GrafPort has no `FillRect` member/vtable route. Surface owns the external callback declaration/storage only.
- Decision: rejected as file owner. Retain GrafPort as inherited `GetBounds` dependency and Surface as external `g_pfnFillRect` dependency.

Applied grouping remains `NexusTK/ui/controls/RectangleControlPane.cpp` and `.h`, containing exactly the class declaration, constructor, ordinary destructor, OnPaint, and HitTestPart. The CPP must include `../../render/Surface.h`; callback typedef/storage remain owned by Surface and are not duplicated. Compiler glue/vtables/RTTI are covered by the class declarations and definitions.

## Source Placement

- Recommended placement: existing `NexusTK/ui/controls/` path, standalone `RectangleControlPane.cpp` with sibling H.
- The class belongs beside `ControlPane`, CheckBox, and related reusable control implementations; MiniMap imports/constructs it.
- Source order is class preamble/declaration, constructor, ordinary destructor, OnPaint, HitTestPart. The CPP preamble needs both local `RectangleControlPane.h` and external `../../render/Surface.h`; the H remains independent of Surface because no callback type appears in the class declaration.
- No separate source definition is required for vtables, RTTI, deleting wrappers, adjustors, padding, or EH cleanup.
- Original historical file naming/grouping remains lexical uncertainty. The prior source-closure block is superseded: CN1-003, CN1-010, CN1-055, CN1-057, and CN1-058 were applied, and dated command `000000024719` regenerated `RectangleControlPane.cpp`/`.h` with both includes, four authored definitions at positions `20/30/40/50`, direct `g_pfnFillRect(this, &bounds)`, complete H, and zero target-specific empty/stub/placeholder/compiler-glue markers. Later generated command/hash authority remains dynamic and requires fresh supervisor readback.

## Range / Split / Padding / Reclassification Analysis

- Core split remains correct: ctor `[0x499c60,0x499cd2)`, 14 CC bytes, dtor `[0x499ce0,0x499cff)`, one CC byte, paint `[0x499d00,0x499d37)`, nine CC bytes.
- Adjustor pair remains one non-reconstructable page; individual hashes prove exact subranges.
- Scalar wrapper remains a separate non-reconstructable page with exact nine-byte prepad and eleven-byte postpad.
- UID000128 keeps its exact five-byte range and is renamed/reclassified semantically from TypeId to HitTestPart.
- UID0002OE and UID0003IT remain useful class-owned evidence and are now non-reconstructable with blank emitters; the class declaration is their source cause.
- No new child, merge, range expansion, data split, or ignored-byte reassignment is required.

## Negative Evidence Summary

- No original PDB, source-file line record, or lexical symbol proves the standalone filename; placement is high-probability inference.
- No direct ordinary caller exists for destructor, OnPaint, HitTestPart, adjustors, or scalar wrapper; their vtable/thunk routes fully explain reachability.
- No Rectangle-specific cleanup exists, so scalar/ordinary teardown output does not imply hidden fields/resources.
- No source-owned global/static/table/string/resource/import was found. Vtable/RTTI data is compiler output.
- Physical adjacency to Numeric/CheckBox and a MiniMap caller do not prove shared source ownership.
- Current weak IDA types do not override the stronger complete binary/vtable/sibling source inference.
- No function body, symbol, declaration, vtable slot, or direct call supports `GrafPort::FillRect`; using that spelling without adding a new member is non-compiling, and adding the member would invent a source abstraction contradicted by current UID0000JR evidence.
- No ownership change is implied by the direct Surface callback. `g_pfnFillRect` is external dependency storage under UID0000TN/UID0000OC, while RectangleControlPane remains the owner of its OnPaint call site.

## IDA Rename / Type / Comment Recommendations

This is a structured, non-executable supervisor handoff. `AR` is regular address comment, `AP` repeatable address comment, `FR` regular function comment, and `FP` repeatable function comment. Every action uses the exact canonical session selected by the supervisor from a fresh schema-1 `runtime_attestation` immediately before Gate 2B. The dated research and preflight-repair sessions above confer no mutation authority. Public endpoint schemas were rechecked without invocation: pure function renames use `rename` with `batch.func:{addr,name}`, `pure:true`, and `stop_on_error:true`; function types use `set_type` with `edits:{addr,signature}`; repeatable function comments use `set_repeatable_comments` with `items:{addr,comment}`. No row authorizes a stack/local rename endpoint, a regular-comment endpoint, an address-comment endpoint, or any unlisted mutation.

| Action ID | Classification | Complete staged contract |
| --- | --- | --- |
| A01 / CN1-048 | apply | Entity `0x00499c60`, function range `[0x00499c60,0x00499cd2)`, 114 bytes, body SHA256 `327363D27A59A1FA412FD0B26772EB1A226085D2ECCAD156F9121FD21EA23538`, inbound set `{0x0045252c code}`, entry-out set `{0x00499c61 code}`, AR absent, AP absent, FR absent, FP absent. **R stage:** exact pre name `sub_499C60`, type `_DWORD *__thiscall(_DWORD *this, int, int *)`, frame `var_10/+0x8/4/_DWORD *; var_C/+0xc/4/_DWORD; var_4/+0x14/4/_DWORD; saved/+0x18/4/_DWORD; return/+0x1c/4/_UNKNOWN *; color/+0x20/4/int; arg_4/+0x24/4/_DWORD`; invoke public `rename` as `batch.func:{addr:"0x00499c60",name:"RectangleControlPane__Constructor"}`, `pure:true`, `stop_on_error:true`. Exact R post is name `RectangleControlPane__Constructor`, unchanged type `_DWORD *__thiscall(_DWORD *this, int, int *)`, the complete same frame, all comments absent, and unchanged range/hash/xrefs. **T stage:** exact pre is that complete R post; invoke public `set_type` as `edits:{addr:"0x00499c60",signature:"RectangleControlPane *__thiscall RectangleControlPane__Constructor(RectangleControlPane *this, int drawColor, const RectBounds *bounds)"}`. Exact T post is that strong source-facing signature with frame `var_10/+0x8/4/_DWORD *; var_C/+0xc/4/_DWORD; var_4/+0x14/4/_DWORD; saved/+0x18/4/_DWORD; return/+0x1c/4/_UNKNOWN *; color/+0x20/4/int; bounds/+0x24/4/const RectBounds *`; `set_type` changes only the function signature and the `arg_4` row, retains the existing IDA `color` row, and authorizes no cosmetic stack/local rename; name, comments, range/hash/xrefs, all other locals, saved, and return rows remain exact. **C stage:** exact pre is the complete T post, including `color/+0x20/4/int` and `bounds/+0x24/4/const RectBounds *`, with AR/AP/FR/FP absent; invoke public `set_repeatable_comments` as `items:{addr:"0x00499c60",comment:"Constructs RectangleControlPane as ControlPane type 8, installs the three compiler-generated view vtables, and applies drawColor through GrafPort_SetDrawColor."}`. Exact C post changes only FP to that text and otherwise repeats the complete T state, including the protected IDA `color` row. Stop before the next stage and do not save on any byte/range/xref/local/nonargument/comment-channel or expected-poststate drift, including any change from `color` to `drawColor`. |
| A02 / CN1-049 | apply | Entity `0x00499ce0`, range `[0x00499ce0,0x00499cff)`, 31 bytes, SHA256 `963C57BEA32FB9D07CEFA3DC6D519C4DCFD699B0D20F1522A96059AD0608B4F9`, no inbound xref, outgoing entry/data set `{0x00499ce6 code,0x00618434 data}`, type `void __thiscall RectangleControlPane_destructor(RectangleControlPane *this)`, frame exactly `return/+0x0/4/_UNKNOWN *`, AR absent, AP absent, FP absent, FR exactly `Ordinary complete-object RectangleControlPane destructor. Restores the three derived callback-view vptrs, then tears down inherited Pane state. No delete flags or deallocation; keep distinct from scalar deleting wrapper 0x0049b490.` **R stage:** invoke public `rename` as `batch.func:{addr:"0x00499ce0",name:"RectangleControlPane__Destructor"}`, `pure:true`, `stop_on_error:true`; exact post changes only name and repeats every other literal field. **C stage:** exact pre is R post; invoke public `set_repeatable_comments` as `items:{addr:"0x00499ce0",comment:"Ordinary out-of-line RectangleControlPane destructor; source body is empty. Compiler restores the three derived views and chains Pane teardown."}`; exact post changes only FP and preserves FR verbatim. No `set_type` or frame action. Stop and do not save on any other delta. |
| A03 / CN1-050 | apply | Entity `0x00499d00`, range `[0x00499d00,0x00499d37)`, 55 bytes, SHA256 `BF22E68F1908E0FA2F8588FCD95674D9A46B137C82524614ADD59E0D6AE87E33`, inbound `{0x00618478 data}`, entry-out `{0x00499d01 code}`, AR absent, AP absent, FR absent, FP absent. **R stage:** exact pre name/type `sub_499D00` / `int __thiscall(void *this)` and frame `outBounds/+0x4/0x10/RectBounds; var_4/+0x14/4/_DWORD; saved/+0x18/4/_DWORD; return/+0x1c/4/_UNKNOWN *`; invoke public `rename` as `batch.func:{addr:"0x00499d00",name:"RectangleControlPane__OnPaint"}`, `pure:true`, `stop_on_error:true`. Exact R post is name `RectangleControlPane__OnPaint`, unchanged type `int __thiscall(void *this)`, complete unchanged frame, absent comments, and unchanged range/hash/xrefs. **T stage:** exact pre is R post; invoke public `set_type` as `edits:{addr:"0x00499d00",signature:"void __thiscall RectangleControlPane__OnPaint(RectangleControlPane *this)"}`. Exact T post changes only the function type to that strong signature; `outBounds/+0x4/0x10/RectBounds; var_4/+0x14/4/_DWORD; saved/+0x18/4/_DWORD; return/+0x1c/4/_UNKNOWN *`, name, comments, bytes, range, and xrefs remain exact. **C stage:** exact pre is T post with all comments absent; invoke public `set_repeatable_comments` as `items:{addr:"0x00499d00",comment:"RectangleControlPane::OnPaint copies inherited bounds and fills them through the active rectangle renderer."}`. Exact C post changes only FP and repeats complete T state. Stop and do not save on any local/frame/byte/xref/other-comment or expected-poststate drift. |
| A04 / CN1-051 | apply | Entity `0x0049b8f0`, range `[0x0049b8f0,0x0049b8f5)`, 5 bytes, SHA256 `385706FAB0C4627BC251D23DF72EEA0C738DC9FD150143FCD23390DC9F2B36B8`, inbound `{0x00618494 data}`, entry-out `{0x0049b8f2 code}`, AR/AP/FR/FP absent. Exact rechecked prestate name/type is `sub_49B8F0` / `char __stdcall sub_49B8F0(int,int)`; frame only `return/+0x0/4/_UNKNOWN *`. **R stage:** invoke public `rename` as `batch.func:{addr:"0x0049b8f0",name:"RectangleControlPane__HitTestPart"}`, `pure:true`, `stop_on_error:true`; exact post changes only name. **T stage:** exact pre is R post; invoke public `set_type` as `edits:{addr:"0x0049b8f0",signature:"unsigned __int8 __thiscall RectangleControlPane__HitTestPart(RectangleControlPane *this, int x, int y)"}`; expected frame becomes exactly `return/+0x0/4/_UNKNOWN *; x/+0x4/4/int; y/+0x8/4/int`, matching the named CheckBox/Scrollable same-slot ABI, with every other field unchanged. **C stage:** exact pre is T post; invoke public `set_repeatable_comments` as `items:{addr:"0x0049b8f0",comment:"RectangleControlPane::HitTestPart(int,int) terminal ControlPane override; returns fixed part identifier 21 and ignores both coordinates."}`; exact post changes only FP. Stop and do not save if the parser does not produce the exact frame or any protected field changes. |
| A05 / CN1-052 | apply | Entity `0x0049afc1`, range `[0x0049afc1,0x0049afcc)`, 11 bytes, exact canonical bytes `81 E9 A0 00 00 00 E9 C4 04 00 00`, corrected SHA256 `B4B18B0EB6661954847D9BE7E3CF8630B876E81CB29DB8FB46B3D8A6C5DBA1E8` independently recomputed from fresh public `get_bytes` output, inbound `{0x0061849c data}`, entry-out `{0x0049afc7 code}`, exact rechecked prestate name/type `sub_49AFC1` / `_DWORD *__thiscall sub_49AFC1(_DWORD *this,char)`, frame only `return/+0x0/4/_UNKNOWN *`, AR/AP/FR/FP absent. **R stage:** invoke public `rename` as `batch.func:{addr:"0x0049afc1",name:"RectangleControlPane__ScalarDeletingDestructorAdjustorA0"}`, `pure:true`, `stop_on_error:true`; exact post changes only name and preserves weak type, frame, comments, canonical bytes/range/corrected hash/xrefs. **C stage:** invoke public `set_repeatable_comments` as `items:{addr:"0x0049afc1",comment:"Compiler-generated adjustor: subtracts the EventHandler-view offset 0xA0 and tail-forwards to RectangleControlPane scalar deleting destruction."}`; exact post changes only FP. No `set_type` or frame action. Stop and do not save on any other delta. |
| A06 / CN1-053 | apply | Entity `0x0049afcc`, range `[0x0049afcc,0x0049afd7)`, 11 bytes, exact canonical bytes `81 E9 A4 00 00 00 E9 B9 04 00 00`, corrected SHA256 `D1CAB38FF0C6FDD535AEF489A2279E8CE885299C88B77972EA827326FC97B14E` independently recomputed from fresh public `get_bytes` output, inbound `{0x006184cc data}`, entry-out `{0x0049afd2 code}`, exact rechecked prestate name/type `sub_49AFCC` / `_DWORD *__thiscall sub_49AFCC(_DWORD *this,char)`, frame only `return/+0x0/4/_UNKNOWN *`, AR/AP/FR/FP absent. **R stage:** invoke public `rename` as `batch.func:{addr:"0x0049afcc",name:"RectangleControlPane__ScalarDeletingDestructorAdjustorA4"}`, `pure:true`, `stop_on_error:true`; exact post changes only name and preserves weak type, frame, comments, canonical bytes/range/corrected hash/xrefs. **C stage:** invoke public `set_repeatable_comments` as `items:{addr:"0x0049afcc",comment:"Compiler-generated adjustor: subtracts the TimerHandler-view offset 0xA4 and tail-forwards to RectangleControlPane scalar deleting destruction."}`; exact post changes only FP. No `set_type` or frame action. Stop and do not save on any other delta. |
| A07 / CN1-054 | apply | Entity `0x0049b490`, range `[0x0049b490,0x0049b4e5)`, 85 bytes, SHA256 `CFA7F3A8CCF45931D37CECF32C567418671B7B51D68A9A59E13E42358F5D43D5`, inbound `{0x0049afc7 code,0x0049afd2 code,0x00618434 data}`, entry-out `{0x0049b491 code}`, AR absent, AP absent, FR absent, FP absent. **R stage:** exact pre name/type `sub_49B490` / `_DWORD *__thiscall(_DWORD *Block, char)` and frame `saved/+0x4/4/_DWORD; return/+0x8/4/_UNKNOWN *; arg_0/+0xc/4/_DWORD`; invoke public `rename` as `batch.func:{addr:"0x0049b490",name:"RectangleControlPane__ScalarDeletingDestructor"}`, `pure:true`, `stop_on_error:true`. Exact R post is name `RectangleControlPane__ScalarDeletingDestructor`, unchanged type `_DWORD *__thiscall(_DWORD *Block, char)`, complete unchanged frame, absent comments, and unchanged range/hash/xrefs. **C stage:** exact pre is R post; invoke public `set_repeatable_comments` as `items:{addr:"0x0049b490",comment:"Compiler-generated RectangleControlPane scalar deleting destructor wrapper; restores derived views, runs Pane teardown, and applies MSVC delete-flag paths for a 0x108-byte object."}`. Exact C post changes only FP and repeats complete R state. Preserve weak type/frame and exact flags behavior; no `set_type` or frame action. Stop and do not save on any byte/range/xref/type/frame/other-comment or expected-poststate drift. |

Protected state for every action:

- Fresh schema-1 attestation must pass with exact canonical path before any backup or mutation; the supervisor selects the dynamic session and performs all endpoints.
- Preserve all bytes, function boundaries, range hashes, xref sets, callees, vtable/RTTI data, AR/AP/FR channels not explicitly changed, and every unaffected frame row.
- Stop on collision, prestate mismatch, parser/frame mismatch, endpoint error, third comment value, byte/xref/boundary drift, or any mutation outside the stated stage delta. A stopped or failed transaction must not save; the supervisor must restore/verify the exact prestate before any retry.
- Only after every accepted stage and complete protected-state readback succeed may the supervisor perform the required durable save and fresh post-save readback under Gate 2B. The B agent performs no mutation, backup, or save.
- Vtables, COLs, RTTI, EH continuation, padding, MiniMap caller, dependencies, and neighbor controls are protected no-change entities, not padded mutation rows.

## First-Draft C++ Recommendation

- Implemented and generated after the accepted dependency callback. Exact behavior, ABI, class surface, owner, source order, header need, direct Surface call, and callable declaration closure are physically verified under CN1-003/CN1-010/CN1-055.
- UID0000BT formal CPP:

~~~cpp
#include "RectangleControlPane.h"
#include "../../render/Surface.h"

[[CHILDREN]]
~~~

- UID0000BT formal H:

~~~cpp
#pragma once

#include "ControlPane.h"

struct RectBounds;

class RectangleControlPane : public ControlPane
{
public:
    RectangleControlPane(int drawColor, const RectBounds *bounds);
    virtual ~RectangleControlPane();

protected:
    virtual void OnPaint();
    virtual unsigned char HitTestPart(int x, int y);
};
~~~

- UID00011P formal CPP:

~~~cpp
RectangleControlPane::RectangleControlPane(int drawColor, const RectBounds *bounds)
    : ControlPane(8, bounds)
{
    SetDrawColor(drawColor);
}
~~~

- UID0004HL formal CPP:

~~~cpp
RectangleControlPane::~RectangleControlPane()
{
}
~~~

- UID00011R formal CPP:

~~~cpp
void RectangleControlPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);
    g_pfnFillRect(this, &bounds);
}
~~~

- Renamed UID000128 formal CPP:

~~~cpp
unsigned char RectangleControlPane::HitTestPart(int, int)
{
    return 21;
}
~~~

- All authored child H blocks remain blank because UID0000BT owns the complete declaration. RectangleControlPane.h needs no Surface include because its public/protected surface does not expose callback types. UID000122, UID000125, UID0002OE, and UID0003IT retain blank CPP/H with exact compiler/no-code proof.
- `SurfaceFillRectProc` is already formalized by UID0000TN as `void (__thiscall *)(GrafPort *,const RectBounds *)`, with one `g_pfnFillRect` definition and one extern declaration. No new Surface CPP/H declaration is emitted here; the only required dependency source is the relative include and direct call above.
- This source preserves the observed receiver/stack/global-dispatch ABI and resembles ordinary project-era C++ rather than decompiler output. It is more probable than inventing a GrafPort member because the binary uses process-wide runtime-selected storage and current GrafPort evidence explicitly rejects a member route.

## Final Recommendation

- The accepted callbacks physically applied and verified all ordinary claims, including CN1-003, CN1-010, CN1-055, CN1-057, CN1-058, and the current canonical UID000122 A05/A06 hash correction for CN1-014/CN1-015 under scoped command `000000025096`. CN1-041..047 coverage payloads are already physically present and remain unchecked only for supervisor verification/no-op; CN1-048..054 remain supervisor Gate 2B work, and CN1-056 now covers only the remaining IDA/save/lifecycle work plus that no-op coverage verification.
- Keep compiler-generated functions/data documented but non-emitting; do not synthesize source bodies for them.
- Use the staged IDA handoff CN1-048 through CN1-054 only under supervisor Gate 2B with fresh prestates and fail-closed readback.
- Preserve historical "type id" and broad-file-fold assumptions only as explicitly rejected history.
- The previously omitted dependency was investigated, implemented, regenerated, and physically reread through one exact route. No research or ordinary implementation question remains on the fill ABI or callable closure. Original lexical/file debug proof would refine confidence without changing this route.

## Recommended Target Doc Changes

- `by-file/RectangleControlPane.md`: the settled standalone CPP/H recommendation, complete authored/compiler/data inventory, exact source order, ownership ranking, no-data/resource/import result, scores, negative evidence, historical corrections, exact Surface include/global-call dependency, rejected GrafPort-member route, unchanged H, and resolved closure rationale are applied under CN1-057.
- `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, `CANONICAL_OWNER:FILE`, and physical `94/95` metadata remain unchanged and are now generated-closure justified.
- The class child owns both CPP includes and the complete H while authored method children own definitions. RectangleControlPane.h remains unchanged.
- Dated command-24719 generated readback confirms both includes, four definitions, direct global call, one complete H declaration, no class/HitTest/vtable empty markers, and no emitted compiler glue/vtable storage.

## Recommended Support Doc Changes

- UID0000BT class: full purpose/layout/method map, source route/order, formal H, object size, no-new-field conclusion, compiler-artifact dispositions, and the formal CPP preamble with both local H and `../../render/Surface.h` are applied; `94/95`, position 10.
- UID00011Q core: applied exact child/gap hashes and current source route; set `92/94`, remains non-emitting.
- UID00011P ctor: applied exact identity/caller/EH/type/source reasoning and position 20; set `92/94`.
- UID0004HL dtor: retained `92/94`, added position 30 and coordinated class/header reasoning.
- UID00011R paint: exact identity/vtable/callback/source reasoning and position 40 are preserved; undeclared `FillRect(&bounds)` was replaced by exact `g_pfnFillRect(this,&bounds)` and generated readback justifies `92/94`.
- UID000122 adjustors and UID000125 scalar wrapper: applied exact hashes/frames/xrefs/compiler cause and raised to `92/94`; remain NONE/FALSE/no emitter. The narrow UID000122 callback replaced only the two stale A05/A06 body-hash values with the fresh canonical recomputations and physically verified them after scoped command `000000025096`.
- UID000128: renamed file/title to RectangleControlPaneHitTestPart, replaced type-id interpretation with exact two-coordinate terminal virtual, added formal CPP and position 50; set `94/96`.
- UID0002OE and UID0003IT: preserved complete vtable/RTTI facts, set `94/96`, retained class owner, changed to non-reconstructable, and cleared emitters/formal source.
- StaticTextControlPane2, ButtonChoiceControlDestructors, and NumericRectangleControlPaneVtables: corrected stale Rectangle type-id/slot/emitter wording without losing historical explanation.
- proposed-source-tree: standalone entry is corrected to exact ranges/HitTestPart/compiler exclusions, and former fold uncertainty is rejected history.
- UID0000TN SurfaceRenderCallbackTable: RectangleControlPane OnPaint is now an exact slot-7 consumer; existing `94/95`, UID0000OC owner/emitter, typedef, definition, extern, and providers remain unchanged. UID0000OC Surface was verify-only because it already owns/emits the dependency correctly.
- UID0000JR GrafPort, MiniMap/MiniMapDialog, and other base/dependency pages are verify-only. GrafPort's existing no-member-route statement is positive negative-evidence closure and must not be replaced by an invented member declaration.

## Score And Metadata Recommendation

| UID | Assignment-time | Physical applied/current | Metadata disposition |
| --- | --- | --- | --- |
| 0000N1 | 86/88 | 94/95 | FILE/path unchanged; dependency callback and generated readback close source |
| 0000BT | 85/89 | 94/95 | owner/emitter 0000N1; true; position 10; exact Surface include applied |
| 00011Q | 88/92 | 92/94 | false; no emitter |
| 00011P | 88/92 | 92/94 | owner/emitter 0000BT; true; position 20 |
| 0004HL | 92/94 | 92/94 | owner/emitter 0000BT; true; position 30 |
| 00011R | 86/90 | 92/94 | owner/emitter 0000BT; true; position 40; direct global call applied and verified |
| 000122 | 88/92 | 92/94 | NONE; false; no emitter |
| 000125 | 88/92 | 92/94 | NONE; false; no emitter |
| 000128 | 88/92 | 94/96 | rename path/title; owner/emitter 0000BT; true; position 50 |
| 0002OE | 87/92 | 94/96 | owner 0000BT; false; clear emitter |
| 0003IT | 88/93 | 94/96 | owner 0000BT; false; clear emitter |

Reason not higher: no original lexical symbols or source-file debug record proves exact filename/access/naming; IDA type mutations require supervisor parser/readback confirmation; source equivalence is evidence-backed rather than original-source proof. The implemented dependency is no longer a score cap.

Reason not lower: every function/data/type/boundary is inventoried; runtime behavior, source causes, owner, source order, class layout, header surface, consumer, vtable slots, compiler exclusions, terminal virtual identity, exact direct callback dependency, and generated callable closure are independently corroborated.

Score-improvement result: the stale type-id, blank class/header, missing terminal method, vtable empty emitters, split uncertainty, weak IDA names/types, compiler-glue ownership, manual coverage drift, and undeclared fill dependency were each investigated and converted into exact decisions. The dependency claims are applied and generated-verified, and the exact manual coverage rows are now physically present; coverage verification/no-op and IDA remain explicitly supervisor-owned rather than ordinary source blockers.

## Open Questions With Attempted Resolution

- **Was the original file standalone?** Checked physical island, RTTI/vtable identity, consumers, source tree, analog controls, dependencies, and possible aggregates. Resolution: standalone is high probability; no positive evidence supports a fold.
- **Was the terminal method a type-id helper?** Checked ABI cleanup, primary slot, sibling slots/types/frames/names. Resolution: no; it is `HitTestPart(int,int)`.
- **Did Rectangle add a color field?** Checked constructor helper, all methods, layout, size, scalar wrapper. Resolution: no; color is inherited GrafPort state.
- **Should compiler glue/vtables emit source?** Checked ABI patterns and repaired CheckBox policy. Resolution: no; ordinary class/destructor source generates them.
- **Is a header required?** Checked inheritance, declarations, generated absence, and standalone source. Resolution: yes; class formal H is mandatory.
- **Is `FillRect` an inherited member or a Surface callback?** Checked exact IDA instructions/decompilation, slot `0x0069b3fc`, UID0000TN/UID0000OC formal CPP/H, generated Surface.h/GrafPort.h, UID0000JR no-member evidence, and existing direct-global consumers. Resolution: it is the declaration-owned Surface global `g_pfnFillRect`; Rectangle CPP must include `../../render/Surface.h` and call `g_pfnFillRect(this,&bounds)`. A new GrafPort member is rejected.
- **Exact original access/casing?** No symbol proves it. Protected virtual placement and current project naming are the strongest human-source inference. This residual lexical uncertainty caps score but does not justify IDA labels in final source.
- No assignment-scope question remains as "needs investigation." The resolved dependency has completed ordinary implementation and generated verification.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

The dated pre-coverage snapshot that found stale scores, UID000128 path/role, and vtable reconstructability is historical. Current manual coverage files physically contain the exact payloads below. CN1-041..047 therefore require supervisor verification/no-op rather than application and remain unchecked for B-agent implementation credit. B006 did not edit manual coverage files.

- `by-file/-coverage-report.md`, current already-present UID0000N1 row for supervisor verification/no-op:
  `- [UID:0000N1][RectangleControlPane](by-file/RectangleControlPane.md) : reconstructable : 94% : very-strong : Standalone RectangleControlPane.cpp/.h with complete class declaration, constructor, empty ordinary destructor, direct Surface g_pfnFillRect OnPaint dependency, corrected HitTestPart(int,int), exact compiler destructor/vtable exclusions, MiniMap consumer, source order, and generated-output contract documented.`
- `by-class/-coverage-report.md`, current already-present UID0000BT row for supervisor verification/no-op:
  `- [UID:0000BT][RectangleControlPane](by-class/RectangleControlPane.md) : reconstructable : 94% : very-strong : Complete 0x108-byte ControlPane-derived class declaration and four authored methods, with three-view RTTI/vtables, deleting-wrapper/adjustor compiler causes, standalone RectangleControlPane.cpp/.h route, and no new data members documented.`
- `by-memory/-coverage-report.md`, current already-present UID00011Q row for supervisor verification/no-op:
  `    - [UID:00011Q][0x00499c60-0x00499d37.RectangleControlPaneCore](by-memory/0x00499c60-0x00499d37.RectangleControlPaneCore.md) : not_reconstructable : 92% : very-strong : Non-emitting split index for exact RectangleControlPane constructor, ordinary destructor, OnPaint, internal/trailing alignment, source order, and compiler destructor-family exclusions.`
- Current already-present UID00011P row:
  `    - [UID:00011P][0x00499c60-0x00499cd2.RectangleControlPaneConstructor](by-memory/0x00499c60-0x00499cd2.RectangleControlPaneConstructor.md) : reconstructable : 92% : very-strong : Exact RectangleControlPane constructor with ControlPane kind 8, three compiler vptr installs, inherited draw-color setup, sole MiniMap caller, EH continuation, closed boundaries, and source-ready formal C++.`
- Current already-present UID0004HL row:
  `    - [UID:0004HL][0x00499ce0-0x00499cff.RectangleControlPaneDestructor](by-memory/0x00499ce0-0x00499cff.RectangleControlPaneDestructor.md) : reconstructable : 92% : very-strong : Exact authored out-of-line empty RectangleControlPane destructor; three view-vptr restores and Pane teardown are compiler output, distinct from scalar deleting glue, with closed boundaries and source position 30.`
- Current already-present UID00011R row:
  `    - [UID:00011R][0x00499d00-0x00499d37.RectangleControlPanePaint](by-memory/0x00499d00-0x00499d37.RectangleControlPanePaint.md) : reconstructable : 92% : very-strong : Exact RectangleControlPane::OnPaint primary-vtable override; copies inherited bounds and calls declaration-owned g_pfnFillRect(this,&bounds), with Surface.h dependency, closed alignment, and source position 40.`
- Current already-present UID000122 row:
  `    - [UID:000122][0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks](by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md) : not_reconstructable : 92% : very-strong : Two exact compiler-generated deleting-destructor adjustors subtract 0xA0/0xA4 and tail-forward to UID000125; exact hashes, vtable refs, frames, and authored-destructor cause documented with no source emitter.`
- Current already-present UID000125 row:
  `    - [UID:000125][0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor](by-memory/0x0049b490-0x0049b4e5.RectangleControlPaneScalarDeletingDestructor.md) : not_reconstructable : 92% : very-strong : Exact 85-byte MSVC scalar deleting wrapper for the 0x108-byte RectangleControlPane; vtable/thunk routes, Pane teardown, delete flags, padding, and compiler no-code disposition documented.`
- Current state has no old UID000128 TypeId row and contains this already-present row in address order:
  `    - [UID:000128][0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart](by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md) : reconstructable : 94% : very-strong : Exact terminal RectangleControlPane::HitTestPart(int,int) primary-vtable override; ignores both coordinates, returns part identifier 21, matches named sibling ABI/slot evidence, and emits at source position 50.`
- Current already-present UID0002OE row:
  `        - [UID:0002OE][0x00618430-0x006184d4.RectangleControlPaneVtableData](by-memory/0x00618430-0x006184d4.RectangleControlPaneVtableData.md) 0x00618430-0x006184d4 | vtable-data | RectangleControlPaneVtableData : not_reconstructable : 94% : very-strong : Exact compiler-emitted primary/secondary/tertiary RTTI-vtable cluster generated from UID0000BT; COL offsets 0/0xA0/0xA4, seven-base hierarchy, deleting adjustors, OnPaint/HitTestPart slots, hashes, and neighbor boundaries documented without source emission.`
- `by-type/by-vtable/-coverage-report.md`, current already-present UID0003IT row for supervisor verification/no-op:
  `- [UID:0003IT][RectangleControlPaneVtables](by-type/by-vtable/RectangleControlPaneVtables.md) : not_reconstructable : 94% : very-strong : Non-emitting source-declaration evidence for RectangleControlPane primary/secondary/tertiary views; exact slot map, COL offsets, seven-base hierarchy, authored overrides, compiler destructor entries, and UID0002OE backing data documented under class owner UID0000BT.`

## Follow-Up Actions

- Supervisor: perform fresh exact-artifact post-callback Gate 1 and Gate 2A against this implementation-return report and its changed ordinary destinations.
- Exact regenerated CPP/H closure is complete. Manual coverage CN1-041..047 is already physically present and needs only supervisor verification/no-op; fail-closed Gate 2B CN1-048..054 remains after accepted gates.
- Remaining IDA mutation/save, report execution, and archive movement remain supervisor-only under narrowed CN1-056.
- No A-agent or additional B-agent research is needed for this target. Any Gate 1 defect should be repaired additively in this same report.

## Confidence

- Recommendation confidence: certain for the callback ABI/dependency and very strong for behavior, class surface, owner, route, source order, header need, and compiler exclusions. Direct global dispatch is observed and already has an owning formal declaration.
- Score confidence: strong for the applied values; dependency callback and fresh generated readback now supply source-closure evidence.
- Remaining uncertainty: exact original filename grouping, access ordering, and spelling are inferred, not debug-symbol proven. No remaining uncertainty affects runtime behavior or ordinary implementation eligibility.

## Validator Results

- Every scoped callback command used `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`, serially, and exited `0` with `ok:1`: class/file initial `000000024643`/`000000024644`; core/constructor/destructor/paint `000000024645`/`000000024646`/`000000024647`/`000000024648`; adjustors/scalar/renamed HitTestPart `000000024665`/`000000024667`/`000000024669`; vtable data/type `000000024670`/`000000024671`; StaticText/ButtonChoice/Numeric support `000000024672`/`000000024673`/`000000024674`; class/core/vtable-data/vtable-type rereads `000000024675`/`000000024676`/`000000024677`/`000000024678`; proposed-source-tree `000000024679`; and final class-H correction `000000024681`.
- Owning-file generated waits used command `000000024680` at `2026-08-16T01:44:26-04:00` and final command `000000024682` at `2026-08-16T01:45:46-04:00`; both exited `0` with `ok:1` and completed generated refresh. Command `000000024681` removed the unnecessary H child marker before final generation.
- Dated command-24682 physical readback remains the historical defect receipt: order, H surface, and zero-marker scan passed, but CPP called undeclared `FillRect`.
- Accepted dependency callback scoped validators all exited `0` with `ok:1`: UID0000BT `000000024710` at `2026-08-16T04:15:40-04:00`; UID00011R `000000024712` at `2026-08-16T04:16:30-04:00`; UID0000N1 initial `000000024715` at `2026-08-16T04:17:19-04:00`; UID0000TN `000000024717` at `2026-08-16T04:18:03-04:00`. UID0000TN reported only the pre-existing missing-reference warning for UID0003XE.
- Final owning-file validation used `python .\tools\validator.py --mode file --file by-file\RectangleControlPane.md --apply --queue-timeout 240 --wait-generated`, command `000000024719` at `2026-08-16T04:18:26-04:00`; it exited `0` with `ok:1` and completed generated refresh.
- Dated command-24719 physical readback: CPP SHA256 `8CEBD211524AD72E55B61D11249CFD25F3372BC7C14B200FAD6F4F587158A6C4`, 1,320 bytes / 35 lines; H SHA256 `844A89529E7E93535E1E68E26CEC6D8B723FAEAC0337839305DB50B1E8DD498B`, 718 bytes / 23 lines. CPP line order is two includes, constructor, ordinary destructor, OnPaint, HitTestPart; OnPaint contains one direct `g_pfnFillRect(this, &bounds)` call. H contains the complete declaration. Target-specific empty-emitter, TODO, placeholder, stub, scalar-deleting, adjustor, and vtable marker scans were all zero. Generated hashes are dated receipts; final Gate readback is dynamic.
- Validator command `000000024669` historically normalized UID000128 references to the renamed path, including an automatic link-only update in `by-memory/-coverage-report.md`; that command alone did not implement CN1-041..047. A later supervisor-owned coverage pass made the exact current payloads already present. The rows remain unchecked for B-agent credit and require supervisor verification/no-op only.
- Gate 2A correction validators used the same scoped command form and each exited `0` with `ok:1`: UID00011P command `000000024895` at `2026-08-16T07:43:20-04:00`; UID0004HL `000000024896` at `2026-08-16T07:43:43-04:00`; UID00011R `000000024897` at `2026-08-16T07:44:07-04:00`; UID000122 `000000024898` at `2026-08-16T07:44:34-04:00`; UID000128 `000000024899` at `2026-08-16T07:44:53-04:00`; UID0002OE `000000024900` at `2026-08-16T07:45:20-04:00`; UID0003IT `000000024901` at `2026-08-16T07:45:52-04:00`. Each reported `projected_stats_update:1`, `stats_incremental_noop:1` because its UID was absent from the generated stats lists, and `generated_refresh: deferred`; no target-specific validator failure occurred.
- Narrow UID000122 hash-correction validation used `python .\tools\validator.py --mode file --file by-memory/0x0049afc1-0x0049afd7.RectangleControlPaneAdjustorThunks.md --apply --queue-timeout 240`, command `000000025096` at `2026-08-16T10:03:53-04:00`; it exited `0` with `ok:1`, reported `projected_stats_update:1`, `stats_incremental_noop:1` because UID000122 is absent from generated stats lists, and `generated_refresh: deferred`. Physical reread found corrected hashes at lines 65-66 and current UID000122 identity SHA256 `B78C658AE429D35E0BB767FD405B506D0C96ACAB7C3A2FB96950BEFCF8EFFBFA`, 7,284 bytes / 76 lines, terminal LF present.
- Current physical generated readback after command `000000024899`: `auto-generated/NexusTK/ui/controls/RectangleControlPane.cpp` SHA256 `506A34A3BCB5D9F15F500FB2F2B5378CB53DB99B86AF03D9E4801F2627E72493`, 1,318 bytes / 35 lines; `.h` SHA256 `F408F456A8BDEBB4CF8CD4197750BF226A954830EA350F5D78E0DF7DBF8CB105`, 716 bytes / 23 lines. CPP still contains both includes, constructor, destructor, OnPaint, HitTestPart, and direct `g_pfnFillRect(this, &bounds)` in the accepted order; H retains the complete class declaration. Empty-emitter, TODO, placeholder, stub, scalar-deleting, adjustor, and compiler-glue scans are zero in both files. Generated identity remains dynamic at later supervisor readback.

## Changed Files

- Current ordinary identities after the narrow UID000122 callback: UID00011P SHA256 `58D327F00DADB0DA0F83098EEE9C3E0653C80AE7CA87ED182AC1B1CDB5F52A9E`, 14,428 bytes / 169 lines; UID0004HL `D6C9A7D12E3F4EAB58131E852F3E92D6AF0EAED27DE80FB7B2202D3DAC39AF07`, 13,516 / 119; UID00011R `ADEFF322385C163732875FCB0733B3074FF6BFF3BA0212E93F1CA28909E07899`, 8,171 / 87; UID000122 `B78C658AE429D35E0BB767FD405B506D0C96ACAB7C3A2FB96950BEFCF8EFFBFA`, 7,284 / 76; UID000128 `DECE1BA19490BFE8EF5E04263D3832390CD5A3AE0416E6DCCA6F3B9530F4CC5B`, 4,562 / 65; UID0002OE `B581F128E3D82186E4E97C4D490B96730D18C70474ADF37BFCB5E3472F52C3CA`, 13,939 / 120; UID0003IT `302482EBD79B1D3C1C27360C60A69107F4C26CBBCD5FBCAFC611B8F866CBA1EE`, 10,225 / 89.
- Gate 2A pre-correction baselines are dated historical receipts only: UID00011P `0A95337DD979A8831F948E9829C1055F50C0ACDFBBF73860300A1B463F007357`; UID0004HL `C9EA85BA183E2E48B2A9DE91A4C62DF5F80C2A7BCC170E9CA39608EA4F263DC1`; UID00011R `C762F3F8541DA00F9BEBE4DB235A012651707062637E8A527DCD13769BC26F62`; UID000122 `0313C4973B1703E0C7E529EBDA0FA33EF3EE7F6EFCA49170E29E4810E1AAAD0F`; UID000128 `65F796CAB1F52871D691BFDCEB658EB38F29D91C33B85CD8BFF851617D43B60B`; UID0002OE `5E3A5D26B9DBB3317E2D6D462AE125C40604B495D25F85291353F3B0102B26F4`; UID0003IT `CD7B31117600B13BED1CC2C4B0EB1694EF2924936092B77C60F99ACBBE3313E1`.
- Unchanged accepted dependency/source identities remain: `by-file/RectangleControlPane.md` SHA256 `CD1BB79D6A11D9B38A13AB3709731B273AFDAAAA380EADE063E6A2C678417059`, 26,248 bytes / 157 lines; `by-class/RectangleControlPane.md` SHA256 `153CDEE34E735A3922C2A41A230BE70E6229CA90AAB8439710D5590840F81AEB`, 22,006 / 150; `by-global/SurfaceRenderCallbackTable.md` SHA256 `CC72D4E3A35D4774E8314AB981FA4429705324A9FED88BFF935B0014058FC0C3`, 98,307 / 578; UID00011Q `17922E219F4E8F0F86C061A17BCC42ED325E33A001F6F0BB562D50DC441E09A5`, 14,619 / 97; UID000125 `CF961E8659DA8B65CBFD6E4AFB948FE0142D6041E563142F4F471FB9E75C6D74`, 16,299 / 107.
- Historical prior-callback support-page receipts: StaticTextControlPane2 `D36EE661557B83B19975AC5DD6EB9F80D4B50060BCF9DE798322FFECD317E096`, 15,267 / 104; ButtonChoiceControlDestructors `EB149BC50F07EFDA380D247F146F627BBAEDC75E764411FF8032B7ED1E84430C`, 65,052 / 290; NumericRectangleControlPaneVtables `A03814C94AB6F7D6B96AAE2CAADB9381C8644336E88E8FCCE33BEAC1527B102B`, 16,443 / 149; proposed-source-tree `60B73DEC39D9BD0CE5037D1DD1324FD095671C341DC9EC05AA3CD1C87E910172`, 324,204 / 2,159.
- Renamed ordinary path: `by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneTypeId.md` -> `by-memory/0x0049b8f0-0x0049b8f5.RectangleControlPaneHitTestPart.md`, preserving UID000128 and exact range.
- Generated files remained validator-owned and were only physically read. The initial Gate 2A correction changed the seven ordinary pages listed above; the later narrow callback changed only UID000122's two stale hash values and this same report. Required validator command `000000025096` reported its automatic projected-stats update and deferred generated refresh; B006 did not manually edit any coverage, generated, tracker, audit, registry, IDA, lifecycle, goal, or notes file. Each ordinary page and the report were leased only for its immediate edit/validation or reconciliation batch and released immediately afterward. Report execution/archive authority remains supervisor-owned.

## Implementation Tracking Checklist

Implementation-return allocation: 43 checked / 15 unchecked across 58 claims. CN1-014/CN1-015 are checked only after command `000000025096` and physical current-page verification of both corrected hashes. Unchecked C041-C047 are already-present supervisor verification/no-op rows; C048-C054 and the remaining IDA/save/lifecycle work in C056 are proposed. Rows are exact ledger twins after removing `Done`.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | CN1-001 | 0000N1 | Settle standalone `NexusTK/ui/controls/RectangleControlPane.cpp` with required sibling H. | Strong | Dedicated class island/RTTI/vtables; source-tree analogs. | UID0000N1 Status/Ownership/Source Placement | incorporate | applied |
| [x] | CN1-002 | 0000BT | Define RectangleControlPane as ControlPane-derived, size `0x108`, with no new data members. | Very strong | Constructor/scalar size; no derived field accesses. | UID0000BT Class Purpose/Layout | incorporate | applied |
| [x] | CN1-003 | 0000BT | Emit exact CPP preamble with `#include "RectangleControlPane.h"`, `#include "../../render/Surface.h"`, then `[[CHILDREN]]`. | Certain | Applied formal CPP and generated command 24719 exact include readback. | UID0000BT RECONSTRUCTION_CPP CODE | incorporate | applied |
| [x] | CN1-004 | 0000BT | Emit complete formal H declaration with constructor, virtual destructor, OnPaint, HitTestPart, and RectBounds forward declaration. | Very strong | Complete authored inventory/vtable surface. | UID0000BT RECONSTRUCTION_H CODE | incorporate | applied |
| [x] | CN1-005 | 0000N1 | Use source positions class 10, constructor 20, destructor 30, OnPaint 40, HitTestPart 50; UID0004HL current prose explicitly records position 30. | Very strong | Physical/source dependency order; correction command 000000024896. | UID0000N1 source-order table; child metadata | incorporate | applied |
| [x] | CN1-006 | 00011P | Preserve ctor range `[0x00499c60,0x00499cd2)`, 114 bytes, SHA256 `327363D27A59A1FA412FD0B26772EB1A226085D2ECCAD156F9121FD21EA23538`. | Certain | MCP/local binary hash. | UID00011P Exact Binary Identity | incorporate | applied |
| [x] | CN1-007 | 00011P | Emit constructor `: ControlPane(8,bounds)` and `SetDrawColor(drawColor)`; vptr stores are compiler output. | Very strong | Full decompile/assembly and helper identity. | UID00011P Behavior/formal CPP | incorporate | applied |
| [x] | CN1-008 | 00011P | Record sole caller `0x0045252c` in MiniMap function `0x004523d0` and compiler EH continuation at `0x005fd191`. | Certain | Fresh xrefs/function analysis. | UID00011P Callers/EH; UID0000N1 Evidence | incorporate | applied |
| [x] | CN1-009 | 0004HL | Preserve `[0x00499ce0,0x00499cff)`, SHA256 `963C57BEA32FB9D07CEFA3DC6D519C4DCFD699B0D20F1522A96059AD0608B4F9`, as authored empty ordinary destructor. | Very strong | Exact body, no direct caller, compiler teardown shape. | UID0004HL Identity/CPP; UID0000BT Method Map | incorporate | applied |
| [x] | CN1-010 | 00011R | Preserve `[0x00499d00,0x00499d37)`, SHA256 `BF22E68F1908E0FA2F8588FCD95674D9A46B137C82524614ADD59E0D6AE87E33`, as OnPaint copying bounds then calling `g_pfnFillRect(this,&bounds)`. | Certain | Applied formal CPP; exact ECX/stack/global-slot ABI; generated command 24719 readback. | UID00011R Identity/CPP; UID0000BT Method Map | incorporate | applied |
| [x] | CN1-011 | 000128 | Preserve `[0x0049b8f0,0x0049b8f5)`, SHA256 `385706FAB0C4627BC251D23DF72EEA0C738DC9FD150143FCD23390DC9F2B36B8`, rename semantic/path identity to RectangleControlPaneHitTestPart, emit fixed-return `HitTestPart(int,int)`, and use that current identity in constructor sibling prose while retaining type-id only as dated superseded history. | Certain | `retn 8`, slot `0x618494`, sibling named overrides; correction commands 000000024895/000000024899. | UID000128 title/path/identity/CPP; UID00011P sibling evidence; UID0000N1 inventory | reject-stale | applied |
| [x] | CN1-012 | 000128 | Preserve same-slot CheckBox return 20 and Scrollable return 18 as independent signature/name corroboration. | Certain | Fresh sibling function types/frames/vtable refs. | UID000128 Type/Slot Evidence | incorporate | applied |
| [x] | CN1-013 | 00011Q | Preserve core children and gaps: 14-byte ctor gap, one-byte dtor gap, nine-byte trailing CC alignment. | Certain | Exact bytes/hashes and item boundaries. | UID00011Q split/boundary table | incorporate | applied |
| [x] | CN1-014 | 000122 | Preserve A0 adjustor `[0x0049afc1,0x0049afcc)`, exact canonical bytes `81 E9 A0 00 00 00 E9 C4 04 00 00`, and corrected SHA256 `B4B18B0EB6661954847D9BE7E3CF8630B876E81CB29DB8FB46B3D8A6C5DBA1E8`. | Certain | Fresh public `get_bytes` output and independent SHA256 recomputation; UID000122 command `000000025096` exited `0` with `ok:1`; current destination physically reread. | UID000122 thunk inventory | incorporate | applied |
| [x] | CN1-015 | 000122 | Preserve A4 adjustor `[0x0049afcc,0x0049afd7)`, exact canonical bytes `81 E9 A4 00 00 00 E9 B9 04 00 00`, and corrected SHA256 `D1CAB38FF0C6FDD535AEF489A2279E8CE885299C88B77972EA827326FC97B14E`. | Certain | Fresh public `get_bytes` output and independent SHA256 recomputation; UID000122 command `000000025096` exited `0` with `ok:1`; current destination physically reread. | UID000122 thunk inventory | incorporate | applied |
| [x] | CN1-016 | 000125 | Preserve scalar wrapper `[0x0049b490,0x0049b4e5)`, 85 bytes, SHA256 `CFA7F3A8CCF45931D37CECF32C567418671B7B51D68A9A59E13E42358F5D43D5`, as compiler no-code. | Certain | Full body/vtable/thunk refs/delete flags. | UID000125 Identity/No-Code Proof | incorporate | applied |
| [x] | CN1-017 | 0000BT | Preserve exact complete-object size `0x108` and subobject offsets `0/0xA0/0xA4`. | Certain | Scalar delete size; COL/vptr stores. | UID0000BT Layout/ABI | incorporate | applied |
| [x] | CN1-018 | 0002OE | Preserve vtable data `[0x00618430,0x006184d4)`, 164 bytes, SHA256 `BE245C307949282DC57E5EB938C0FA85DDB5A50AC43F8EA58FF8BA47A4A6E277`. | Certain | Exact data/hash/boundaries. | UID0002OE Exact Binary Identity | incorporate | applied |
| [x] | CN1-019 | 0002OE | Record 25-slot primary, 11-slot secondary, 2-slot tertiary views; paint slot `0x618478`, hit slot `0x618494`, adjustors `0x61849c/0x6184cc`. | Certain | Fresh vtable data/xrefs. | UID0002OE Slot Map; UID0003IT | incorporate | applied |
| [x] | CN1-020 | 0003IT | Preserve COL offsets `0/0xA0/0xA4` and seven-base hierarchy Rectangle/ControlPane/Pane/GrafPort/LObject/EventHandler/TimerHandler. | Certain | Decorated RTTI/COL entities. | UID0003IT RTTI/Layout | incorporate | applied |
| [x] | CN1-021 | 0002OE | Make UID0002OE and UID0003IT non-reconstructable/non-emitting while retaining class ownership and evidence. | Certain | Compiler emits vtables/RTTI from class declaration. | UID0002OE/UID0003IT metadata | incorporate | applied |
| [x] | CN1-022 | 0000N1 | Record no source-owned globals/statics/constants/tables beyond compiler vtable/RTTI data. | Very strong | Whole-file data/global search. | UID0000N1 Complete Inventory | not-applicable | excluded-with-reason |
| [x] | CN1-023 | 0000N1 | Record no source-owned strings, resources, imports, or third-party embeds. | Very strong | Function/string/import/resource audit. | UID0000N1 Complete Inventory | not-applicable | excluded-with-reason |
| [x] | CN1-024 | 0000N1 | Preserve MiniMap as sole confirmed constructor consumer, not source owner. | Certain | Caller `0x45252c`; generic class semantics. | UID0000N1 Consumers; MiniMap verify-only | incorporate | applied |
| [x] | CN1-025 | 0000N1 | Reject MiniMap, ControlPane/GrafPort, and broad BasicControlPanes fold as weaker owners/placements. | Strong | Consumer/base-only relationships; no fold evidence. | UID0000N1 Ownership Decision/Historical Alternatives | reject-stale | applied |
| [x] | CN1-026 | 0000N1 | Physical score change `86/88 -> 94/95` and unchanged path/FILE owner are applied and source-closure justified. | Strong | Whole inventory, direct-global repair, validators, generated CPP/H readback. | UID0000N1 metadata/Score | incorporate | applied |
| [x] | CN1-027 | 0000BT | Physical score change `85/89 -> 94/95`, owner/emitter, position 10, and exact CPP dependency preamble are applied. | Strong | Complete class surface and generated two-include readback. | UID0000BT metadata | incorporate | applied |
| [x] | CN1-028 | 00011Q | Raise core `88/92 -> 92/94`; remain non-reconstructable/no emitter. | Strong | Complete split/boundary inventory. | UID00011Q metadata | incorporate | applied |
| [x] | CN1-029 | 00011P | Raise constructor `88/92 -> 92/94`; retain class route and position 20, with former scores only in dated history. | Strong | Exact body/caller/source resolved; correction command 000000024895. | UID00011P metadata/current score prose | incorporate | applied |
| [x] | CN1-030 | 0004HL | Keep `92/94`; retain class route and explicit source position 30. | Very strong | Exact ordinary destructor source and correction command 000000024896. | UID0004HL metadata/source-position prose | already-present | applied |
| [x] | CN1-031 | 00011R | Physical score change `86/90 -> 92/94`, class route, position 40, exact direct-global body, and current score prose are applied and verified. | Strong | Exact body/name/callback ABI; correction command 000000024897 and generated readback. | UID00011R metadata/current gate | incorporate | applied |
| [x] | CN1-032 | 000122 | Raise adjustors `88/92 -> 92/94`; remain NONE/FALSE/no emitter, with `88/92` retained only as dated history. | Strong | Exact thunk pair/compiler cause and correction command 000000024898. | UID000122 metadata/current score rationale | incorporate | applied |
| [x] | CN1-033 | 000125 | Raise scalar wrapper `88/92 -> 92/94`; remain NONE/FALSE/no emitter. | Strong | Exact wrapper/delete ABI/no-code proof. | UID000125 metadata | incorporate | applied |
| [x] | CN1-034 | 000128 | Raise corrected HitTestPart `88/92 -> 94/96`; owner/emitter UID0000BT, position 50, reconstructable true, with exact body SHA256 `385706FAB0C4627BC251D23DF72EEA0C738DC9FD150143FCD23390DC9F2B36B8`. | Very strong | Exact slot/body/sibling proof and correction command 000000024899. | Renamed UID000128 metadata/identity | incorporate | applied |
| [x] | CN1-035 | 0002OE | Raise vtable data `87/92 -> 94/96`; owner UID0000BT, reconstructable false, blank emitter; historicalize `87/92`/reconstructable-true wording. | Very strong | Exact complete cluster/class cause and correction command 000000024900. | UID0002OE metadata/current and historical score rationale | incorporate | applied |
| [x] | CN1-036 | 0003IT | Raise vtable type `88/93 -> 94/96`; owner UID0000BT, reconstructable false, blank emitter; historicalize the former owner/emitter/reconstructable state. | Very strong | Exact layout/RTTI/class cause and correction command 000000024901. | UID0003IT metadata/assignment/current-state prose | incorporate | applied |
| [x] | CN1-037 | 000128 | Correct stale Rectangle "type-id" references in StaticTextControlPane2 support. | Certain | Same-slot semantic correction. | StaticTextControlPane2 historical/cross-reference prose | reject-stale | applied |
| [x] | CN1-038 | 000128 | Correct stale Rectangle "type-id" references in ButtonChoiceControlDestructors while retaining historical correction context. | Certain | Same-slot semantic correction. | ButtonChoiceControlDestructors child map/history | reject-stale | applied |
| [x] | CN1-039 | 0003IT | Correct NumericRectangleControlPaneVtables Rectangle slot `+0x60` and source-emission disposition. | Certain | Exact vtable slot/layout. | NumericRectangleControlPaneVtables | reject-stale | applied |
| [x] | CN1-040 | 0000N1 | Keep proposed-source-tree standalone RectangleControlPane entry and mark former fold uncertainty historical. | Strong | Source placement analysis. | proposed-source-tree Rectangle entry | already-present | applied |
| [ ] | CN1-041 | 0000N1 | Supervisor verify/no-op: the exact 94 percent standalone source/header/HitTestPart by-file coverage row is already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 86-percent row is historical. | by-file/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-042 | 0000BT | Supervisor verify/no-op: the exact 94 percent complete class/header/method-surface by-class coverage row is already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 85-percent row is historical. | by-class/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-043 | 00011Q | Supervisor verify/no-op: the exact core/constructor/destructor/paint rows with current scores and HitTest-aware source route are already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage rows/scores are historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-044 | 000122 | Supervisor verify/no-op: the exact adjustor/scalar 92 percent compiler no-code rows are already physically present. | Certain | Fresh supervisor coverage audit; the dated pre-coverage 88-percent rows are historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-045 | 000128 | Supervisor verify/no-op: the old TypeId row is absent and the renamed 94 percent HitTestPart row is already physically present in address order. | Certain | Fresh supervisor coverage audit confirms the corrected path/title/role row. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-046 | 0002OE | Supervisor verify/no-op: the exact 94 percent non-reconstructable class-generated vtable-data row is already physically present. | Certain | Fresh supervisor coverage audit; the dated reconstructable 87-percent row is historical. | by-memory/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-047 | 0003IT | Supervisor verify/no-op: the exact 94 percent non-reconstructable class-generated vtable-type row is already physically present. | Certain | Fresh supervisor coverage audit; the dated reconstructable 88-percent row is historical. | by-vtable/-coverage-report.md | already-present | supervisor-verify |
| [ ] | CN1-048 | 00011P | Stage safe ctor rename/type/repeatable-comment handoff from exact weak pretype `_DWORD *__thiscall(_DWORD *this, int, int *)`; preserve the IDA frame row `color/+0x20/4/int` through R/T/C while `set_type` changes only `arg_4` to `bounds/+0x24/4/const RectBounds *`. The strong source-facing signature may retain `drawColor`; no cosmetic stack/local rename is authorized. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread, observed public `set_type` poststate, and current public endpoint schemas. | Supervisor Gate 2B A01 | incorporate | proposed |
| [ ] | CN1-049 | 0004HL | Stage safe ordinary-dtor rename/repeatable-comment handoff while preserving existing FR. | Strong | Fresh exact type/frame/comments/body. | Supervisor Gate 2B A02 | incorporate | proposed |
| [ ] | CN1-050 | 00011R | Stage safe OnPaint rename/type/repeatable-comment handoff from exact weak pretype `int __thiscall(void *this)` with the complete local/saved/return frame preserved through R/T/C states. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread plus current public endpoint schemas. | Supervisor Gate 2B A03 | incorporate | proposed |
| [ ] | CN1-051 | 000128 | Stage HitTestPart rename/type/repeatable-comment handoff with exact x/y frame result. | Very strong | Named same-slot sibling types/frames. | Supervisor Gate 2B A04 | incorporate | proposed |
| [ ] | CN1-052 | 000122 | Stage A0 adjustor rename/comment only; preserve weak type and sole return row. | Strong | Exact thunk body/frame/xref. | Supervisor Gate 2B A05 | incorporate | proposed |
| [ ] | CN1-053 | 000122 | Stage A4 adjustor rename/comment only; preserve weak type and sole return row. | Strong | Exact thunk body/frame/xref. | Supervisor Gate 2B A06 | incorporate | proposed |
| [ ] | CN1-054 | 000125 | Stage scalar-wrapper rename/comment only from exact weak pretype `_DWORD *__thiscall(_DWORD *Block, char)`; preserve the complete saved/return/argument frame and delete ABI through R/C states. | Strong | Fresh canonical item/type/frame/comments/xrefs/bytes reread plus current public endpoint schemas. | Supervisor Gate 2B A07 | incorporate | proposed |
| [x] | CN1-055 | 0000N1 | Scoped-validate every changed ordinary page, validate the owning file with generated wait, and physically verify both CPP/H declarations and callable closure. | Certain | Commands 24710/24712/24715/24717/24719; exact CPP/H hashes and zero-marker scan. | Validator/generated checklist | incorporate | applied |
| [ ] | CN1-056 | 0000N1 | Keep the remaining IDA mutation/save, report execution, and archive movement supervisor-owned; manual coverage is already present and requires only supervisor verification/no-op. | Certain | Role/lifecycle rules and current already-present C041-C047 coverage state. | IDA/lifecycle checklist; coverage verification no-op | incorporate | proposed |
| [x] | CN1-057 | 0000N1 | Document the exact Surface dependency route, required relative include, direct global-call ABI, rejected GrafPort-member alternative, unchanged H, and resolved score/closure state. | Certain | Applied file section; IDA call; generated header comparison; UID0000JR negative evidence. | UID0000N1 Dependencies/Source Closure/Score | incorporate | applied |
| [x] | CN1-058 | 0000TN | Add RectangleControlPane::OnPaint as an exact slot-7 consumer while preserving UID0000TN/UID0000OC ownership, 94/95 metadata, and existing Surface CPP/H typedef/global/extern text unchanged. | Certain | Applied consumer section and slot inventory; declaration/formals preserved; scoped validation. | UID0000TN Consumer Evidence; UID0000OC verify-only | incorporate | applied |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000025131","destination_path":"executed-b-agent-research/B006/0000N1-RectangleControlPane-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000N1-RectangleControlPane-file-source-quality.md","timestamp":"2026-08-16T10:26:08-04:00","uid":"0000N1"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
