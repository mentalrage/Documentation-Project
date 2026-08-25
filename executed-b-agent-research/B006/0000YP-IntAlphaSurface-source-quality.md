** TARGET-REPORT-UID:0000YP **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0000YP IntAlphaSurface Source-Quality Research


## Finalized Report / Current Recommendation

- Current lifecycle state: implementation callback complete after supervisor Gate 1 pass for SHA256 `EA9F47BEEC54DF0358DDA0E2A95F7BCF7139909571CBE7C1DBFC56D1A657B60F`; no `execute_report`, lifecycle/archive command, generated-file manual edit, coverage-report edit, or manual report move was run by B006. This artifact is awaiting supervisor Gate 2 review.
- Current recommendation/status: [UID:0000YP] `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md` is now a source-ready emitting destructor child for [UID:00006K] `IntAlphaSurface`.
- Final disposition applied: kept the current target path/range, kept `CANONICAL_OWNER:00006K`, kept `RECONSTRUCTABLE:TRUE`, kept `EMITTER_UIDS:00006K`, raised target score from `85/89` to `88/91`, and inserted a formal ordinary `IntAlphaSurface::~IntAlphaSurface()` source body into the target's `RECONSTRUCTION_CPP CODE` block.
- Release-slot disposition applied: the validator assigned exact by-memory release-helper child [UID:0004FR] `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md`. That child is `88/91`, owned/emitted by [UID:00006K], and carries the formal `IntAlphaSurface::ReleaseOwnedPixels()` C++ block. [UID:0000TX] `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md` is now non-reconstructable/non-emitting alias/support to avoid duplicate output.
- Confidence: strong for binary behavior, field offsets, virtual-slot routing, direct class owner, and `0x004632c0` exclusion; capped below final confidence because the physical source file may still be `IntAlphaSurface.cpp`, `AlphaMaskSurface.cpp`, or a neighboring render-surface source file, and exact original member spellings are source-facing reconstructions rather than recovered symbols.

## Supporting Research

This report began as a report-only assignment for UID0000YP. After supervisor Gate 1 acceptance, B006 performed the implementation callback and modified only accepted target/support by-* docs plus this report. Validator-scoped file commands updated validator-owned state and project stats; B006 did not manually edit generated files, coverage reports, validator state, IDA DB state, report lifecycle state, archives, or supervisor ledgers.

The assignment required mandatory IDA MCP evidence. Current usable MCP session is `b010_00032w_20260703`; all current MCP facts below come from that session on 2026-07-03 unless explicitly labeled as existing documentation or older executed-report lead evidence. MCP was available after the supervisor override, so this is not fallback-only research.

## Target

- Target UID: `0000YP`
- Target path: `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`, assignment-time score `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: implementation callback complete, awaiting supervisor Gate 2 review.
- Current target metadata after implementation: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006K`, blank optional position, formal destructor C++ populated.

## Current Target State

- Existing range/path state: `0x00463270-0x004632b1` is already the correct half-open scalar deleting destructor range. The final instruction is `retn 4`, and `0xcc` padding starts at `0x004632b1`.
- Existing owner/emitter state: direct class parent [UID:00006K] `IntAlphaSurface`, with file route [UID:0000K8] `IntAlphaSurface` and possible physical colocation with [UID:0000HF] `AlphaMaskSurface`.
- Implemented C++ state: the target formal C++ block contains the accepted ordinary destructor body. The stale informal destructor/release sketch and old field-name variants were replaced/historicalized in the target/support docs.
- Implemented blocker resolution: target and release-helper docs no longer treat field names/source split as a `95/95` blank-C++ blocker. Current by-structure reconstruction gates and B009's implemented view-initializer support remove that as a target-specific blocker. Exact source-file colocation remains a confidence cap, not a no-code proof.
- Related target/support docs checked: target by-memory page, [UID:0000TX] release helper by-item page, [UID:00006K] class page, [UID:0000K8] file page, [UID:0001XT] vtable page, [UID:0001TP] layout page, [UID:0000YL] AlphaMaskSurface constructor/helper aggregate, [UID:0002NM] InitAlphaSurfaceView, [UID:0000YQ] ApplicationErrorStateCleanup, and executed B001/B009 reports as lead material.
- Current artifact/lifecycle status: this report is active in `tools/leaser/Agents/Agent-B006/research/` after implementation callback; it has not been executed or archived and is awaiting supervisor Gate 2 review.

## Executive Recommendation

Raise UID0000YP to `88/91` and insert the formal destructor C++ below. Keep the current class owner/emitter [UID:00006K]; do not reparent to `AlphaMaskSurface`, `ApplicationErrorStateCleanup`, a raw constructor block, or a standalone free helper.

The target is now code-ready because current MCP reconfirms exact range, byte body, vtable-only reachability, destructor vtable reset, ownership flag and pixel pointer offsets, CRT free wrapper call, scalar-delete wrapper call, and the neighboring `0x004632c0` exclusion. Current support docs now also provide consistent source-facing field names through [UID:0002NM] `InitAlphaSurfaceView`: `m_pixels`, `m_width`, `m_height`, `m_stride`, and `m_ownsBuffer`.

The release-slot helper received its own exact formal body on validator-assigned [UID:0004FR] `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md`, not in the UID0000YP C++ block. No UID was guessed; command `000000005574` assigned UID0004FR before support docs were linked to it.

## Supervisor Active Recheck

- Supervisor instruction: continue UID0000YP only, use existing MCP session `b010_00032w_20260703`, do not call `idb_open`, `idb_close`, process lifecycle commands, archive/lifecycle commands, generated-file manual edits, coverage-report edits, or `execute_report`.
- Split repair required before final report: no split for UID0000YP. The target destructor page range is exact. A separate exact release-helper page is recommended because `0x00462260-0x00462282` is outside the target.
- Source-bearing children in scope: UID0000YP destructor and new release helper [UID:0004FR]; no change to `0x004632c0`, which was already sufficient and left unedited.

## Inference Research Guidance Check

Evidence discipline used direct MCP facts first: server health, function lookup, decompile, callees, xrefs, xref query, paged disassembly, byte reads, pointer-pattern search, RTTI/name query, and integer conversion with `tools/int_convert.py`. Existing by-* docs and executed reports were used as leads and consistency checks, not as final authority.

Stale Wave/import or generated-source assumptions were not treated as proof. The current target is reconstructable because the binary body and class route are sufficient, not because an old generated sketch exists. Field names are source-facing names supported by implemented current docs, not recovered original symbols.

## Heuristic / Inference Reanalysis And Validation

- Destructor range: current MCP `lookup_funcs` reports `sub_463270`, size `0x41` / 65 (Verified with `int_convert.py`), matching half-open range `0x00463270-0x004632b1`.
- Destructor bytes: current MCP `get_bytes` shows `55 8b ec 56 8b f1 80 7e 24 00 c7 06 ec 12 61 00 74 17 8b 46 14 85 c0 74 10 50 e8 0a 45 16 00 83 c4 04 c7 46 14 00 00 00 00 f6 45 08 01 74 0b 6a 28 56 e8 7f 42 16 00 83 c4 08 8b c6 5e 5d c2 04 00`, followed by `0xcc` padding.
- Source-vs-wrapper shape: the binary function is the MSVC scalar deleting destructor. Source C++ should be the ordinary destructor body; the scalar-delete flag, `push 0x28`, and delete helper call are compiler-generated wrapper behavior and must not be hand-written in source.
- Release helper: current MCP `lookup_funcs` reports `sub_462260`, size `0x22` / 34 (Verified with `int_convert.py`), half-open range `0x00462260-0x00462282`; bytes end in `5e c3`, followed by `0xcc` padding.
- Vtable-only reachability: current MCP `xrefs_to` and `find_bytes` report `0x00463270` only as data at `0x006112ec`, and `0x00462260` only as data at `0x006112f0`. There are no direct code callers for either virtual target.
- Vtable base refs: current MCP reports `off_6112EC` stores/uses at raw `0x0046212c`, active constructor `0x0046217b`, EH cleanup `0x00462237`, view initializer `0x00462415`, and destructor reset `0x0046327a`.
- Field offsets: `this+0x24` / decimal 36 is the ownership byte, `this+0x14` / decimal 20 is the pixel pointer, and scalar delete passes object size `0x28` / decimal 40 to the delete helper (all verified with `int_convert.py`). Existing layout docs place bounds at `+0x04`, dimensions at `+0x18/+0x1c`, stride at `+0x20`, and ownership byte at `+0x24`.
- Name validation: [UID:0002NM] current formal C++ already uses `IntAlphaSurface *`, `m_pixels`, `m_width`, `m_height`, `m_stride`, and `m_ownsBuffer`, so the older `m_ownsPixels` or `m_pixelData` variants should be historicalized as descriptive aliases.
- Exclusion validation: `0x004632c0` is a separate `sub_4632C0`, size `0x4b`, whose function pointer occurs at `0x00612574` and whose vtable base references are `0x00419e8f`, `0x004632c9`, and `0x0060c0b6`. It is not part of the IntAlphaSurface vtable or source body.

## Evidence Standards Used

Evidence types used: IDA MCP `server_health`, `lookup_funcs`, `decompile`, `callees`, `xrefs_to`, `xref_query`, paged `disasm`, `get_bytes`, `find_bytes`, `entity_query`; local by-* docs; executed B-report searches as leads; `tools/int_convert.py` for numeric conversions; current by-structure reconstruction rules.

The evidence is strong enough for range, behavior, field offsets, owner/emitter, rejected alternatives, score movement, and first-draft destructor C++. It is not strong enough to settle the physical source-file colocation between a standalone `IntAlphaSurface.cpp`, `AlphaMaskSurface.cpp`, or a broader render-surface source file, so that remains a confidence cap.

## Evidence Checked

- IDA MCP endpoint/session:
  - JSON-RPC endpoint `http://127.0.0.1:13337/mcp`.
  - Supervisor-restored session `b010_00032w_20260703` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health` command id `10`: status ok, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Target/release MCP checks:
  - `lookup_funcs` command id `11` for `0x00463270`, `0x004632b1`, `0x00462260`, `0x00462282`, `0x00462170`, `0x00462120`, `0x00462230`, `0x004623c0`, `0x004632c0`, and vtable addresses.
  - `decompile` command id `12` for `0x00463270`.
  - `decompile` command id `13` for `0x00462260`.
  - `callees` command id `14` for destructor, release helper, active constructor/helper, view initializer, and `0x004632c0`.
  - `xrefs_to` command id `15` for destructor, release helper, IntAlphaSurface vtable base, raw constructor address, active constructor, and `0x004632c0`.
  - `xref_query` command id `16` for destructor/release/vtable/neighbor refs.
  - `disasm` command id `17` for `0x00463270`.
  - `disasm` command id `18` for `0x00462260`.
  - `entity_query` command id `21` for RTTI/name ranges around `0x006112e8`, `0x00641e9c`, and `0x006744ec`.
  - `get_bytes` command id `23` for destructor, release helper, vtable bytes, and post-destructor alignment.
  - `find_bytes` command id `24` for little-endian pointer patterns to destructor, release helper, vtable base, release slot address, `0x004632c0`, and `0x00612574`.
- Local documentation checked:
  - `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`
  - `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`
  - `by-class/IntAlphaSurface.md`
  - `by-file/IntAlphaSurface.md`
  - `by-type/by-vtable/IntAlphaSurfaceVtable.md`
  - `by-type/by-struct/AlphaMaskSurfaceLayout.md`
  - `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
  - `by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md`
  - `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`
  - Executed B001/B009 reports found by local `rg` search for UID0000YP, `0x00463270`, `0x00462260`, and `IntAlphaSurface`.
- Negative/failed checks:
  - No fallback-only evidence was used.
  - The first `get_bytes` attempt used obsolete `start` schema and failed; the schema was checked and retried with `regions` in command id `23`.
  - The first `find_bytes` attempt used obsolete object-pattern schema and failed; it was retried with string patterns in command id `24`.
  - No `idb_open`, `idb_close`, process management, lifecycle/archive, IDA DB write, or `execute_report` command was run. Scoped file validators were run only after supervisor implementation callback; those commands are recorded in `Validator Results`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0000YP range remains `0x00463270-0x004632b1`, function `sub_463270`, size `0x41` / 65, with padding after `0x004632b1`. | high | MCP `lookup_funcs` id 11, `disasm` id 17, `get_bytes` id 23, `int_convert.py` | Target Status/Evidence/Range | incorporated into target | applied: target Item Summary, Assignment Gate, Evidence Notes, and validator command `000000005585` |
| C02 | Destructor writes vtable `0x006112ec`, tests ownership byte `this+0x24`, frees/clears pixel pointer `this+0x14`, and conditionally calls delete helper only for scalar-delete flag bit `1`. | high | MCP `decompile` id 12, `disasm` id 17, `callees` id 14 | Target Behavior/Reconstruction Notes/C++ rationale | incorporated into target and support | applied: target Evidence Notes/Reconstruction Notes; class/file/vtable support synced |
| C03 | The source-level formal body should be ordinary `IntAlphaSurface::~IntAlphaSurface()` and must not hand-write the compiler scalar-delete flag or delete-helper wrapper. | high | MSVC scalar deleting destructor shape; MCP disasm shows wrapper-only delete helper path | Target C++ block and notes | inserted formal C++ | applied: target `RECONSTRUCTION_CPP CODE` contains ordinary destructor only; wrapper is documented as compiler-generated |
| C04 | Release helper at `0x00462260-0x00462282` is source-ready as `IntAlphaSurface::ReleaseOwnedPixels()` but belongs on its own exact page, not in UID0000YP. | high | MCP `lookup_funcs` id 11, `decompile` id 13, `disasm` id 18, `get_bytes` id 23 | New release helper by-memory page and UID0000TX support page | created/promoted exact page | applied: validator command `000000005574` assigned [UID:0004FR], final validator `000000005586`; UID0000TX converted to non-emitting alias in `000000005587` |
| C05 | Destructor and release helper are vtable-only targets: pointer patterns occur only at `0x006112ec` and `0x006112f0`, with no direct code callers. | high | MCP `xrefs_to` id 15, `xref_query` id 16, `find_bytes` id 24 | Target, vtable, class support docs | incorporated | applied: target, UID0004FR, class, file, vtable, AlphaMask aggregate |
| C06 | IntAlphaSurface vtable refs are raw `0x0046212c`, active constructor `0x0046217b`, EH cleanup `0x00462237`, view initializer `0x00462415`, and destructor reset `0x0046327a`. | high | MCP `xrefs_to` id 15, `find_bytes` id 24 | Target/class/file/vtable support docs | incorporated | applied: target, class, file, vtable support synced; raw/EH caveats preserved |
| C07 | `0x004632c0` is a separate ApplicationErrorStateCleanup function, not an IntAlphaSurface neighbor child. | high | MCP `lookup_funcs` id 11, `xrefs_to` id 15, `find_bytes` id 24, current by-memory UID0000YQ | Target negative evidence and support exclusion | preserve/incorporate | applied/already-present: target/class/file/vtable/new UID0004FR preserve exclusion; UID0000YQ was already at same-or-greater detail and was not edited |
| C08 | Field names should standardize to `m_pixels` and `m_ownsBuffer`, with dimensions/stride named as in UID0002NM. | medium-high | UID0002NM formal C++; layout docs; MCP offset validation | Target, class, file, layout support docs | incorporated | applied: target and UID0004FR formal C++ use `m_pixels`/`m_ownsBuffer`; class/file/layout text synced |
| C09 | Owner/emitter should remain [UID:00006K] class, with [UID:0000K8] as file route and source-file colocation caveat. | high | RTTI names from current docs and MCP entity query id 21; vtable-slot behavior; support docs | Target metadata and source placement docs | confirmed/incorporated | applied: UID0000YP unchanged owner/emitter; UID0004FR owner/emitter set to 00006K; file route caveat preserved |
| C10 | Blank/no-code treatment is now stale for UID0000YP; source split uncertainty is a confidence cap, not a blocker. | medium-high | Current MCP evidence plus UID0002NM field-name support | Target C++/score rationale | incorporated | applied: formal destructor C++ inserted and stale no-code wording replaced/historicalized |
| C11 | Recommended target score is `88/91`, owner/emitter/reconstructable unchanged. | medium-high | Evidence completeness, formal C++ readiness, remaining source-file/name cap | Target metadata | incorporated | applied: target validator command `000000005585` recorded completion/confidence updates to `88/91` |

## Positive Evidence Summary

- Direct facts supporting the recommendation: current MCP confirms exact destructor function, exact release helper, exact bytes, exact vtable entries, no direct callers, field offsets, CRT free wrapper, scalar delete helper, vtable-store xrefs, and neighboring exclusion.
- Corroborating documentation evidence: [UID:00006K] class docs already attach the vtable and destructor to `IntAlphaSurface`; [UID:0001XT] vtable docs record RTTI naming `IntAlphaSurface`; [UID:0002NM] formal C++ uses the field names required by this destructor; [UID:0000YQ] already owns the separate `0x004632c0` cleanup.
- Strongest inference chain: RTTI-backed vtable plus vtable slot 0 pointer to `0x00463270` plus destructor body layout and scalar-delete wrapper shape make the source-level ordinary destructor safe. Release slot 1 is source-ready too, but it must be represented separately because UID0000YP's byte range does not include it.

## IDA MCP Facts

- Function/range facts:
  - `lookup_funcs` id `11` reports `0x00463270` as `sub_463270`, size `0x41`; `0x004632b1` is not a function.
  - `lookup_funcs` id `11` reports `0x00462260` as `sub_462260`, size `0x22`; `0x00462282` is not a function.
  - `lookup_funcs` id `11` reports `0x004623c0` as `sub_4623C0`, size `0x154`; `0x00462230` is inside that function rather than a separate function start.
  - `lookup_funcs` id `11` reports `0x004632c0` as `sub_4632C0`, size `0x4b`.
- Byte/vtable facts:
  - `get_bytes` id `23` shows destructor bytes ending in `c2 04 00`, then `0xcc` padding from `0x004632b1`.
  - `get_bytes` id `23` shows release helper bytes ending in `5e c3`, then `0xcc` padding from `0x00462282`.
  - `get_bytes` id `23` at `0x006112e8` shows complete object locator pointer `9c 1e 64 00`, slot 0 function pointer `70 32 46 00`, slot 1 function pointer `60 22 46 00`, and two zero slots.
- Pointer-pattern facts:
  - `find_bytes` id `24`: `70 32 46 00` matches only `0x6112ec`.
  - `find_bytes` id `24`: `60 22 46 00` matches only `0x6112f0`.
  - `find_bytes` id `24`: `ec 12 61 00` matches `0x46212e`, `0x46217d`, `0x462239`, `0x462417`, and `0x46327c`, corresponding to the documented vtable stores/loads.
  - `find_bytes` id `24`: `f0 12 61 00` has no matches, expected because code stores the vtable base, not the slot address.
  - `find_bytes` id `24`: `c0 32 46 00` matches only `0x612574`, the separate ApplicationErrorStateCleanup vtable.
  - `find_bytes` id `24`: `74 25 61 00` matches `0x419e95`, `0x4632cb`, and `0x60c0bc`, matching the separate cleanup's vtable refs.
- Decompile/disasm facts:
  - `decompile` id `12` for `0x00463270` writes `off_6112EC`, checks byte `+36`, frees pointer dword `+5` / offset `+20`, clears it, conditionally calls `sub_5C7526(Block)` if `a2 & 1`, and returns `Block`.
  - `disasm` id `17` confirms `cmp byte ptr [esi+24h], 0`, `mov dword ptr [esi], offset off_6112EC`, `mov eax, [esi+14h]`, call `j_j_j___free_base`, clear `[esi+14h]`, test scalar-delete flag, push `28h`, push `esi`, call `sub_5C7526`, and `retn 4`.
  - `decompile` id `13` and `disasm` id `18` for `0x00462260` confirm the same owned-buffer release without vtable write or delete helper.
- Xref facts:
  - `xrefs_to` id `15` for `0x00463270`: one data xref from `0x006112ec`.
  - `xrefs_to` id `15` for `0x00462260`: one data xref from `0x006112f0`.
  - `xrefs_to` id `15` for `0x006112ec`: data xrefs from `0x0046212c`, `0x0046217b`, `0x00462237`, `0x00462415`, and `0x0046327a`.
  - `xrefs_to` id `15` for `0x00462120`: no xrefs; this remains a raw no-function caveat.
  - `xrefs_to` id `15` for `0x00462170`: code xrefs at `0x004df9a9`, `0x0050442c`, `0x005a288d`, and `0x005a2b8e`.
  - `xrefs_to` id `15` for `0x004632c0`: one data xref from `0x00612574`.
- RTTI/name facts:
  - `entity_query` id `21` finds `??_R4IntAlphaSurface@@6B@` at `0x00641e9c`, `??_R3IntAlphaSurface@@8` at `0x00641eb0`, and `??_R0?AVIntAlphaSurface@@@8` at `0x006744ec`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00463270-0x004632b1` | [UID:0000YP] `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md` | scalar deleting destructor range; source ordinary destructor body | true | [UID:00006K] | current `85/89`, recommended `88/91` | insert formal destructor C++ |
| `0x00462260-0x00462282` | currently [UID:0000TX] `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`; recommended exact by-memory child through TMP UID workflow | vtable slot 1 release helper | true | recommended [UID:00006K] | current by-item `86/90`, recommended exact child `88/91` | create/promote exact page and insert release C++ |
| `0x00462170-0x00462227` | covered in [UID:0000YL] `AlphaMaskSurface` aggregate | active constructor/helper | true | Alpha/Int surface family | support | constructor/use evidence only |
| `0x00462120-0x00462161` | [UID:0000YK] raw default-constructor-shaped block | raw/no-function caveat | true/partial | alpha-surface family | support | no xrefs; not target owner |
| `0x00462230-0x00462258` | [UID:0000YM] EH cleanup | compiler unwind cleanup | true/commentary | alpha-surface family | support | not normal method |
| `0x004623c0-0x00462514` | [UID:0002NM] `InitAlphaSurfaceView` | AlphaMaskSurface-owned view initializer using `IntAlphaSurface *` destination | true | [UID:0000HF] | `90/91` | field-name support only |
| `0x004632c0-0x0046330b` | [UID:0000YQ] `ApplicationErrorStateCleanup` | separate application error-state cleanup | true | [UID:0000HG] | `86/91` | excluded |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006112ec` | data pointer to `0x00463270` | IntAlphaSurface vtable slot 0 destructor |
| `0x006112f0` | data pointer to `0x00462260` | IntAlphaSurface vtable slot 1 release helper |
| `0x0046212c` | raw no-function vtable store/use | raw constructor-shaped caveat, not a modeled function |
| `0x0046217b` | vtable store in active constructor/helper `sub_462170` | positive constructor/use evidence |
| `0x00462237` | vtable store in EH cleanup tail owned by `sub_4623C0` | compiler cleanup, not normal release helper |
| `0x00462415` | vtable store in `InitAlphaSurfaceView` | view construction/use-site evidence |
| `0x0046327a` | destructor vtable reset | expected destructor behavior |
| `0x00612574` | data pointer to `0x004632c0` | separate ApplicationErrorStateCleanup vtable, exclusion proof |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target page already records exact destructor range, vtable-only dispatch, owned pixel offsets, CRT free dependency, scalar-delete helper, raw constructor caveat, and `0x004632c0` exclusion.
  - [UID:00006K] class page records `IntAlphaSurface` layout and vtable refs, and B001 RTTI ownership proof.
  - [UID:0001XT] vtable page records slot 0 destructor and slot 1 release helper.
  - [UID:0001TP] layout page records offsets compatible with the destructor.
  - [UID:0002NM] formal C++ resolves the source-facing member names and proves `IntAlphaSurface *` as a real source type in current output.
- Existing docs that are stale or incomplete:
  - UID0000YP and UID0000TX both retain "final C++ remains blank because 95/95/source split" wording. Under current B-agent rules and current support docs, that is no longer a target-specific blocker.
  - UID0000YP's informal reconstruction sketch uses `m_ownsPixels`; support docs now favor `m_ownsBuffer`.
  - UID0000TX remains only a by-item page and lists range `0x00462260-0x00462281` in terminal-inclusive style. Current function extent is half-open `0x00462260-0x00462282`.
- Generated/coverage report state: generated tracker still lists UID0000YP as unreported at assignment time. No generated report was edited; lifecycle-generated report counts should change only after supervisor execution.

## Ranked Ownership Analysis

### 1. [UID:00006K] IntAlphaSurface class

- Evidence for: RTTI names `IntAlphaSurface`; vtable slot 0 and slot 1 point to destructor/release methods; destructor writes `off_6112EC`; class docs record the matching object layout; current formal view initializer uses `IntAlphaSurface *`.
- Evidence against: physical constructor/helper code is interleaved with AlphaMaskSurface helper code, and the final `.cpp` colocation is not proven.
- Decision: keep as canonical owner and emitter for UID0000YP and the release helper.

### 2. [UID:0000K8] IntAlphaSurface file route

- Evidence for: existing file page is the documented route for the class and vtable, with a proposed `NexusTK/render/IntAlphaSurface.cpp`.
- Evidence against: by-structure method bodies should attach to the class when supported; the file page remains a physical colocation candidate rather than the semantic owner.
- Decision: keep as source-file route, not direct canonical owner of UID0000YP.

### 3. [UID:0000HF] AlphaMaskSurface

- Evidence for: active constructor/helper and view initializer live near AlphaMaskSurface code and store the IntAlphaSurface vtable.
- Evidence against: RTTI and vtable method targets are IntAlphaSurface; [UID:0002NM] is now proven AlphaMaskSurface-owned only because `ECX` is the source AlphaMaskSurface and the `IntAlphaSurface *` is an explicit destination parameter.
- Decision: preserve as file-colocation/use-site support, reject as class owner for destructor/release.

### 4. ApplicationErrorStateCleanup / neighboring `0x004632c0`

- Evidence for: near in memory.
- Evidence against: separate function, separate vtable `0x00612574`, separate xref set, separate current by-memory owner.
- Decision: reject and preserve exclusion.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: keep [UID:00006K] class owner and [UID:0000K8] file route. The most plausible file remains `NexusTK/render/IntAlphaSurface.cpp`, with documented possibility of colocation in `AlphaMaskSurface.cpp` or broader `Surface.cpp`.
- Candidate related items that belong: UID0000YP destructor, `0x00462260-0x00462282` release helper, vtable [UID:0001XT], layout [UID:0001TP], and constructor/helper evidence from UID0000YL/UID0002NM.
- Candidate related items rejected: `0x004632c0`, raw `0x00462120` as a normal constructor owner, EH cleanup as a normal method, CRT/free/delete helpers as source owners.

## Source Placement

- Recommended source placement: `IntAlphaSurface` class methods emitted through [UID:00006K], with file route [UID:0000K8] `NexusTK/render/IntAlphaSurface.cpp`.
- Why this placement fits: methods operate on the IntAlphaSurface vtable/layout, RTTI names IntAlphaSurface, and formal neighboring support now exposes `IntAlphaSurface *` and field names.
- Rejected placements and why: `AlphaMaskSurface` class ownership rejected by RTTI/method-target evidence; `ApplicationErrorStateCleanup` rejected by separate vtable; raw constructor block rejected by no-function/no-xref caveat; CRT/delete helper owners rejected as runtime dependencies.
- Remaining placement uncertainty: original source may have folded these small methods into `AlphaMaskSurface.cpp` or `Surface.cpp`. That uncertainty caps confidence but does not prevent class-method C++.

## Range / Split / Padding / Reclassification Analysis

- Target range: keep `0x00463270-0x004632b1`; no rename/recreate.
- Destructor padding: `get_bytes` id `23` confirms `0xcc` from `0x004632b1` before the next `0x004632c0` function.
- Release helper range: use half-open `0x00462260-0x00462282`; byte check shows `retn` at the terminal byte before `0x00462282` padding.
- New child/split recommendation: create/promote an exact release-helper by-memory page for `0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md` through validator/TMP UID workflow. Do not guess the final UID in this report.
- Parent/container impact: class/file/vtable support docs should mention that destructor and release are both source-ready IntAlphaSurface methods; UID0000YP remains a normal emitting child, not a split/index parent.

## Negative Evidence Summary

- No direct code caller exists for the destructor or release helper; both are vtable-only. This is expected for virtual teardown/release and is not dead-code proof.
- `0x00462120` has no IDA function object or xrefs in current MCP, so it remains raw constructor-shaped support only.
- `0x00462230` is inside `sub_4623C0` and belongs to EH cleanup, not a normal method body.
- `0x004632c0` belongs to a separate vtable and cleanup family.
- There is no evidence that the scalar-delete flag or `sub_5C7526` call was source-authored; hand-writing a decompiler-shaped scalar deleting destructor would be wrong.
- The final original member spellings are not recovered; use current source-facing names from UID0002NM and document the naming confidence cap.
- Blank/no-code treatment is rejected for UID0000YP because owner/emitter route, field names, and source body are now sufficiently supported.

## IDA Rename / Type / Comment Recommendations

- Source-facing names/types/comments used for implementation docs; IDA names/types/comments were not applied:
  - Function/source body: `IntAlphaSurface::~IntAlphaSurface()`
  - Release slot: `IntAlphaSurface::ReleaseOwnedPixels()`
  - Pixel pointer: `m_pixels`
  - Ownership byte: `m_ownsBuffer`
  - Other layout fields: `m_width`, `m_height`, `m_stride`, `m_bounds`
- Evidence for names/types: UID0002NM formal C++ and layout docs use these names; MCP validates the exact offsets.
- Items intentionally left unchanged: IDA names/types/comments were not edited. No IDA DB writes were requested or performed.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested for this B-agent assignment and not performed.

## First-Draft C++ Recommendation

Eligible for draft C++: yes for UID0000YP. The target is reconstructable, has a nonblank class emitter, has average score above the code-entry gate, and current evidence resolves the prior field/source split blocker into a confidence cap.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for [UID:0000YP] `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IntAlphaSurface::~IntAlphaSurface()
{
    if (m_ownsBuffer && m_pixels != NULL) {
        free(m_pixels);
        m_pixels = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for the exact release-helper destination after it exists or is explicitly selected by supervisor:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IntAlphaSurface::ReleaseOwnedPixels()
{
    if (m_ownsBuffer && m_pixels != NULL) {
        free(m_pixels);
        m_pixels = NULL;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason this preserves exact original behavior: the destructor source body releases owned pixel storage and clears the pointer. The compiler-generated scalar deleting destructor wrapper accounts for the vtable reset, scalar-delete flag test, object-size `0x28`, and delete helper call. The release helper body matches slot 1 and omits object deletion.

Reason this matches plausible mid-2000s C++ source shape: it uses normal class methods, `NULL`, and `free`, not decompiler temporaries, raw offsets, or explicit `__thiscall`/scalar-delete wrapper syntax.

Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_ownsBuffer`, `m_pixels`, and `IntAlphaSurface` from current docs and formal support code. Exact original spellings remain a confidence cap.

No-code proof is rejected for UID0000YP: the target is a modeled function with vtable owner, class route, sufficient field names, and source-shape evidence. Blank formal C++ would now be stale.

## Final Recommendation

- Exact changes recommended for UID0000YP: set `COMPLETION:88`, set `CONFIDENCE:91`, keep `CANONICAL_OWNER:00006K`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:00006K`, keep blank optional position, insert the formal destructor C++ block above, and replace the stale 95/95/source-split no-code blocker with current MCP-backed source-ready evidence.
- Exact parent assignments recommended: keep direct class parent [UID:00006K]; keep file route [UID:0000K8] and source colocation caveat.
- Exact release-helper action recommended: create/promote exact `0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels` by-memory page through validator/TMP UID workflow; insert the formal release helper C++; update UID0000TX and support docs to avoid duplicate emitting pages.
- Exact items left no-owner/non-emitting and why: none in UID0000YP. Raw `0x00462120` remains raw/no-function support only; `0x004632c0` remains separate cleanup.
- Exact future work outside this assignment scope: if later evidence proves physical source colocation under `AlphaMaskSurface.cpp` or a broader render `Surface.cpp`, update file-level placement, not the class ownership of the destructor/release methods.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:85 -> 88`
  - `CONFIDENCE:89 -> 91`
  - Keep `CANONICAL_OWNER:00006K`
  - Keep `RECONSTRUCTABLE:TRUE`
  - Keep `EMITTER_UIDS:00006K`
  - Keep `EMITTER_POSITION_OPTIONAL:` blank
  - Insert the formal destructor C++ block from this report.
- Exact report facts to incorporate:
  - Current MCP session `b010_00032w_20260703`, `server_health` id `10` OK.
  - `lookup_funcs` id `11` confirms `sub_463270`, size `0x41` / 65, and `0x004632b1` not a function.
  - Exact destructor bytes and post-range `0xcc` padding from `get_bytes` id `23`.
  - Vtable slot 0 at `0x006112ec`; destructor pointer pattern `70 32 46 00` occurs only there.
  - Body writes vtable, tests `this+0x24`, frees/clears `this+0x14`, conditionally calls delete helper with size `0x28` under scalar-delete flag.
  - Source C++ should be ordinary destructor body, not decompiler-shaped scalar deleting destructor.
  - Release helper is source-ready but belongs to separate exact page/range `0x00462260-0x00462282`.
  - Current source-facing fields: `m_pixels`, `m_ownsBuffer`; older `m_ownsPixels`/`m_pixelData` wording is historical/descriptive.
  - Preserve raw `0x00462120` caveat, EH cleanup distinction, vtable-only reachability, and `0x004632c0` exclusion.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: no direct callers expected for virtual target; reject `0x004632c0`, raw constructor ownership, EH cleanup as normal method, decompiler wrapper C++, and blank/no-code treatment.

## Recommended Support Doc Changes

- Support path: `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md` (new exact page via validator/TMP UID workflow; do not guess UID)
  - Exact report facts to incorporate: current MCP `sub_462260`, size `0x22` / 34, exact bytes, vtable slot 1 pointer at `0x006112f0`, no direct callers, tests `m_ownsBuffer`, frees/clears `m_pixels`, no object deletion, source-ready formal release C++.
  - Metadata/link/score/coverage/source-placement changes: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006K`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006K`, blank optional position, formal release C++.
  - If this child-page workflow is unavailable: pause and report exact blocker rather than inventing UID; if supervisor chooses existing UID0000TX instead, update UID0000TX consistently and prevent duplicate emitting release pages.

- Support path: `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`
  - Exact report facts to incorporate: current MCP session evidence, half-open range `0x00462260-0x00462282`, source-ready release helper body, class owner [UID:00006K], and no object deletion.
  - Metadata/link/score/coverage/source-placement changes: if retained as the canonical release carrier, change owner/emitter to [UID:00006K] and raise to `88/91`; if an exact by-memory page is created, convert this by-item wording into a support alias/cross-reference so there is not a duplicate source-emitting body.

- Support path: `by-class/IntAlphaSurface.md`
  - Exact report facts to incorporate: UID0000YP source-ready destructor, release helper source-ready, current MCP `b010_00032w_20260703` evidence, field-name standardization to `m_pixels` and `m_ownsBuffer`, and `0x004632c0` exclusion.
  - Metadata/link/score/coverage/source-placement changes: optional score bump from `85/89` to `88/91` if class formal method notes are updated; keep `CANONICAL_OWNER:0000K8`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000K8`.

- Support path: `by-file/IntAlphaSurface.md`
  - Exact report facts to incorporate: destructor/release are source-ready class methods; source-file split remains a file-placement caveat only; [UID:0002NM] remains AlphaMaskSurface-owned use-site evidence rather than a direct IntAlphaSurface method.
  - Metadata/link/score/coverage/source-placement changes: optional score bump from `85/88` to `86/90` if support text is synchronized; keep file route provisional and do not force a final physical source file.

- Support path: `by-type/by-vtable/IntAlphaSurfaceVtable.md`
  - Exact report facts to incorporate: current vtable bytes from MCP id `23`, pointer-pattern uniqueness from id `24`, slot 0 destructor and slot 1 release helper are source-ready IntAlphaSurface methods, slots 2 and 3 remain zero.
  - Metadata/link/score/coverage/source-placement changes: no metadata change required unless stale score text blocks support sync.

- Support path: `by-type/by-struct/AlphaMaskSurfaceLayout.md`
  - Exact report facts to incorporate: only if stale, ensure layout names align with `m_pixels`, `m_width`, `m_height`, `m_stride`, and `m_ownsBuffer`.
  - Metadata/link/score/coverage/source-placement changes: no score/metadata change required.

- Support path: `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`
  - Exact report facts to incorporate: optional narrow support sync that UID0000YP destructor and release slot are source-ready IntAlphaSurface methods; keep view initializer/constructor ownership unchanged.
  - Metadata/link/score/coverage/source-placement changes: no score/metadata change required.

- Support path: `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`
  - Exact report facts to incorporate: no edit required if it already states the exclusion; if stale support text references UID0000YP adjacency ambiguously, preserve that `0x004632c0` is separate application error cleanup.
  - Metadata/link/score/coverage/source-placement changes: none.

## Score And Metadata Recommendation

- Current UID0000YP score/metadata: `85/89`, owner/emitter [UID:00006K], reconstructable true, blank C++.
- Recommended UID0000YP score/metadata: `88/91`, owner/emitter unchanged, reconstructable true, formal destructor C++ inserted.
- Score rationale and reason not higher/lower: raise completion because current MCP closes the explicit recheck list and supports first-draft C++; raise confidence because field names and owner are now stronger than earlier docs. Do not raise to `95/95` because exact original member spellings and physical source-file colocation are still not recovered.
- Score-improvement attempt:
  - Range and bytes: checked by `lookup_funcs`, `disasm`, `get_bytes`; resolved.
  - Vtable-only dispatch: checked by `xrefs_to`, `xref_query`, and `find_bytes`; resolved.
  - Owned pixel offsets: checked by decompile/disasm and `int_convert.py`; resolved.
  - CRT free/delete helpers: checked by `callees` and disasm; resolved as source destructor plus compiler scalar-delete wrapper.
  - Constructor/unwind refs: checked by `xrefs_to` to vtable base and lookup status of raw/tail chunks; resolved as support refs, not owner blockers.
  - `0x004632c0` exclusion: checked by lookup/xrefs/pointer patterns; resolved.
  - Field/source split blocker: checked against UID0002NM formal C++ and class/layout docs; resolved as confidence cap, not no-code proof.
- Metadata fields to change or leave unchanged: change only target scores and C++ body; keep owner/emitter/reconstructable. Support release helper should move to class owner/emitter when exact by-memory page is created/promoted.

## Open Questions With Attempted Resolution

- Open question: can UID0000YP formal C++ now be inserted?
  - Evidence checked: current MCP destructor/release evidence, field layout, class/file/vtable docs, UID0002NM formal C++.
  - Best supported resolution: yes. Insert ordinary destructor body; do not hand-write scalar-delete wrapper.
  - Remaining unresolved: exact original field spelling and physical source file. Score/C++ impact: caps confidence at `91`, does not keep C++ blank.
- Open question: can release helper C++ be inserted?
  - Evidence checked: current MCP `0x00462260` decompile/disasm/bytes/xrefs and existing UID0000TX docs.
  - Best supported resolution: yes, but on a separate exact destination. Create/promote `0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels` through TMP UID workflow or explicitly update UID0000TX if supervisor chooses that route.
  - Remaining unresolved: final by-memory UID. Implementation must not guess it.
- Open question: should owner/emitter move to AlphaMaskSurface?
  - Evidence checked: RTTI, vtable slots, view initializer support docs, source colocation notes.
  - Best supported resolution: no. Keep class owner [UID:00006K]; keep AlphaMaskSurface as colocation/use-site evidence.
- Open question: is `0x004632c0` related?
  - Evidence checked: function lookup, vtable pointer patterns, xrefs, current UID0000YQ docs.
  - Best supported resolution: no. Preserve exclusion.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. Do not edit generated `auto-generated/-ag-*` reports or manual coverage reports during this pass. The generated tracker/report count should update only through supervisor-owned lifecycle execution after implementation and validation.

## Follow-Up Actions

- Supervisor actions: perform Gate 2 verification against the changed by-* docs, validator outputs, ledger, and checklist. If Gate 2 passes, supervisor may perform the supervisor-owned execute lifecycle later.
- B006 implementation actions remaining: none known. All accepted target/support items were applied, already present, or excluded with reason.
- A-agent actions: none requested.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `88/91`.
- Remaining uncertainty: exact original field/member spelling and physical source-file colocation only.

## Validator Results

Initial new-file UID assignment:
- `python .\tools\validator.py --mode file --file by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md --apply --queue-timeout 240`
- command_id `000000005574`, command_timestamp `2026-07-03T16:05:04-04:00`, exit code `0`.
- Result: assigned new UID `0004FR`, inserted validator metadata/header, scanned `1` file. The output did not include an `ok:` line because it made initial UID/header insertions. Generated refresh: deferred under command id `000000005574`.

Final scoped validators after edits:
- `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`: command_id `000000005585`, command_timestamp `2026-07-03T16:09:45-04:00`, exit code `0`, `ok: 1`. Updates included completion/confidence `88/91`, reconstruction block registry update, reference adds for `0002NM` and `0004FR`, stats row remove/rescore recommendation. Generated refresh: deferred.
- `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md`: command_id `000000005586`, command_timestamp `2026-07-03T16:09:47-04:00`, exit code `0`, `ok: 1`. Updates included completion/confidence `88/91`, canonical owner `00006K`, reconstructable true, emitter `00006K`, reconstruction block registry update. Generated refresh: deferred.
- `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`: command_id `000000005587`, command_timestamp `2026-07-03T16:09:49-04:00`, exit code `0`, `ok: 1`. Updates included completion/confidence `88/91`, canonical owner `0004FR`, reconstructable `false`, cleared emitter, UID link insertion for `0004FR`, stats row remove/rescore recommendation. Generated refresh: deferred.
- `by-class/IntAlphaSurface.md`: command_id `000000005589`, command_timestamp `2026-07-03T16:09:51-04:00`, exit code `0`, `ok: 1`. Updates included completion/confidence `88/91`, reference add for `0004FR`, stats row remove/rescore recommendation. Generated refresh: deferred.
- `by-file/IntAlphaSurface.md`: command_id `000000005590`, command_timestamp `2026-07-03T16:09:53-04:00`, exit code `0`, `ok: 1`. Updates included completion/confidence `86/90`, reference add for `0004FR`, stats row remove/rescore recommendation. Generated refresh: deferred.
- `by-type/by-vtable/IntAlphaSurfaceVtable.md`: command_id `000000005591`, command_timestamp `2026-07-03T16:09:56-04:00`, exit code `0`, `ok: 1`. Updates included validator-normalized UID link text for UID0000YP/UID0004FR, reference add for `0004FR`, stats row update. Generated refresh: deferred.
- `by-type/by-struct/AlphaMaskSurfaceLayout.md`: command_id `000000005592`, command_timestamp `2026-07-03T16:09:57-04:00`, exit code `0`, `ok: 1`. Updates included reference add for `0004FR`, stats row update. Generated refresh: deferred.
- `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`: command_id `000000005593`, command_timestamp `2026-07-03T16:09:59-04:00`, exit code `0`, `ok: 1`. Updates included validator-normalized UID link text for UID0004FR, reference add for `0004FR`. Generated refresh: deferred.

Validator-owned side effects observed:
- `tools/validator.ini` and `project-level/-auto-completion-stats.md` changed through scoped validator commands. These were not manually edited by B006.
- Each command reported `generated_refresh: deferred`; no manual generated file or coverage-report edit was made.
- No unresolved validator errors were reported in the scoped outputs.

Lease status:
- Lease command succeeded for seven existing editable files: target, UID0000TX by-item, IntAlphaSurface class/file, IntAlphaSurface vtable, AlphaMaskSurfaceLayout, and AlphaMaskSurface aggregate. New UID0004FR could not be leased before it existed under the documented workflow.
- Cleanup `unlease` command was attempted after validation and returned `Rejected[No active lease]` for each leased path, meaning the short leases had already expired before cleanup. Current lease report check showed no active B006 lease.

## Changed Files

By-* files changed or created:
- Modified: `by-memory/0x00463270-0x004632b1.IntAlphaSurface.md`
- Created: `by-memory/0x00462260-0x00462282.IntAlphaSurfaceReleaseOwnedPixels.md` with validator-assigned [UID:0004FR]
- Modified: `by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md`
- Modified: `by-class/IntAlphaSurface.md`
- Modified: `by-file/IntAlphaSurface.md`
- Modified: `by-type/by-vtable/IntAlphaSurfaceVtable.md`
- Modified: `by-type/by-struct/AlphaMaskSurfaceLayout.md`
- Modified: `by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md`

Accepted stale-only support excluded/already-present:
- `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md` was checked and already preserved the `0x004632c0` exclusion at same-or-greater detail, so it was not edited.

Report file changed:
- Modified: `tools/leaser/Agents/Agent-B006/research/0000YP-IntAlphaSurface-source-quality.md`

Validator-owned side effects:
- `tools/validator.ini` and `project-level/-auto-completion-stats.md` were updated by scoped validators.
- Generated refreshes were deferred by validator commands; no generated or coverage file was manually edited.

Renamed: none.
Report execution: not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation. Proof: supervisor Gate 1 pass cited SHA256 `EA9F47BEEC54DF0358DDA0E2A95F7BCF7139909571CBE7C1DBFC56D1A657B60F`.
- [x] Target/support docs to update: implemented target, exact release child, UID0000TX alias, class, file, vtable, layout, and AlphaMask aggregate. ApplicationErrorStateCleanup checked and excluded as already-present.
- [x] Current target state and actual evidence checked recorded: report records MCP session `b010_00032w_20260703`, command ids, current target metadata, current support docs, and evidence sources.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger above now records applied/already-present proof.
- [x] Metadata/score changes to apply: UID0000YP `85/89 -> 88/91`; UID0004FR `88/91`; UID0000TX alias `88/91`; class `88/91`; file `86/90`.
- [x] Owner/emitter/reconstructable changes to apply: UID0000YP unchanged [UID:00006K]/true/[UID:00006K]; UID0004FR set [UID:00006K]/true/[UID:00006K]; UID0000TX set non-reconstructable/non-emitting alias owned by UID0004FR.
- [x] Split/rename/new-child changes to apply: no rename for UID0000YP; exact release helper created at `0x00462260-0x00462282` and validator assigned UID0004FR.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: target range, release range, padding, source placement, and no IDA edits documented.
- [x] First-draft C++ or no-code proof to apply: formal destructor C++ inserted into UID0000YP; formal release C++ inserted into UID0004FR; blank/no-code rejected for UID0000YP.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP evidence, exact bytes, vtable xrefs/pointer patterns, owned offsets, CRT free/delete helper facts, constructor/unwind refs, raw constructor caveat, `0x004632c0` exclusion, field names, rejected alternatives, and score rationale incorporated or already present.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: source-file colocation caveat, raw `0x00462120` caveat, EH cleanup distinction, ApplicationErrorState cleanup exclusion, no decompiler-shaped scalar-delete C++, and no standalone helper ownership preserved.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: older informal reconstruction and `95/95` blocker wording treated as historical; not used to keep C++ blank.
- [x] Open questions closed or documented as evidence-backed unresolved: C++ readiness closed as yes; source-file colocation and exact original member spelling remain confidence caps.
- [x] Validators run during implementation callback: scoped file validators run for every changed/created by-* file; command IDs/timestamps/results recorded above.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual generated/coverage edit; generated refreshes deferred by validators and reported.
- [x] Lease requirements: leases taken for existing edited docs; new child file created under documented workflow; cleanup attempted and no active leases remained.
- [x] Prohibited actions maintained: no generated-file manual edits, coverage-report edits, validator-state manual edits, lifecycle/archive commands, IDA DB edits, or `execute_report`.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/new-child/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and command ids/timestamps/results recorded.
- [x] Generated freshness observations recorded; no manual generated/coverage edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000005618","destination_path":"executed-b-agent-research/B006/0000YP-IntAlphaSurface-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0000YP-IntAlphaSurface-source-quality.md","timestamp":"2026-07-03T16:30:00-04:00","uid":"0000YP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
