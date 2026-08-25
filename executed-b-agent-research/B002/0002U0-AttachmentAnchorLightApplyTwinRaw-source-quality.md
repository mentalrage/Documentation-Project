** TARGET-REPORT-UID:0002U0 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B002 Source-Quality Report: UID 0002U0 AttachmentAnchorLightApplyTwinRaw

## Assignment

- Agent: B002.
- Assignment id: `B002-report-attachment-anchor-light-apply-twin-raw-source-quality-0002U0-mcp-20260623`.
- Target: [UID:0002U0] `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`.
- Current target score: `COMPLETION:85`, `CONFIDENCE:87`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Task type: report-only MCP-backed source-quality research. No target/support by-* docs, generated/project-level files, IDA DB, tool state, reports under `executed`, or `-coverage-report.md` files were edited.
- Required skill used: project-level `ntk-b-agent-workflow`; read `SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, relevant `by-structure.md` MCP/scoring/owner sections, and updated `Agent-B002/goal.md`.
- Lease status: no lease needed or taken. This pass writes only the B002-owned research report.

## Recommendation Summary

Keep [UID:0002U0] at:

- `COMPLETION:85`
- `CONFIDENCE:87`
- `CANONICAL_OWNER:00000O`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000O`
- blank `EMITTER_POSITION_OPTIONAL`
- existing first-draft C++ unchanged

The current MCP session `ff68e691` is healthy and reconfirms the exact raw helper bytes, no-function state, failed raw-start decompilation, zero incoming xrefs, zero VA/RVA/raw-offset pointer matches to `0x0053c9f0`, positive controls for the live mode-1 sibling and LightObjImageLib vtable dwords, and the same `g_pLightObjImageLib`/`DrawLightMode2`/`m_lightImageIndex`/`MapPane::m_selectionOverlay` source interpretation already in the page. A fresh local PE supplement also reconfirms zero direct `E8`/`E9`/near-conditional routes and zero pointer-literal routes to the raw target start while finding the expected mode-1 sibling calls and vtable/global positive controls.

This pass does not justify raising the target above `85/87`. The remaining blocker is not stale evidence; it is positively confirmed raw-helper liveness uncertainty. No caller, callback table, vtable slot, function pointer, branch/jump, data pointer, or raw literal route to `0x0053c9f0` is known. Original helper spelling, original `MapPane +0x3e0` member spelling, and final source-file placement also remain inferred. The existing first-draft C++ remains appropriate as draft-only source guidance because the behavior, owner/emitter route, callee/global/field names, and code-entry gate are strong enough, but it should not be described as final-source quality.

Existing formal C++ to keep:

```cpp
void AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY)
{
    g_pLightObjImageLib->DrawLightMode2(
        mapPane->m_selectionOverlay,
        centerX,
        centerY,
        m_lightImageIndex);
}
```

## Evidence Sources

Current by-* and project docs checked as lead/support material:

- `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`
- `by-class/AttachmentAnchorResolver.md`
- `by-file/AttachmentAnchorResolver.md`
- `by-file/AttachedObjectPane.md`
- `by-class/MapPane.md`
- `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`
- `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`
- `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
- `by-type/by-vtable/LightObjImageLibVtable.md`
- `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
- `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
- `by-memory/-coverage-report.md` as read-only supervisor-owned coverage context
- `auto-generated/-ag-memory-coverage.md` as read-only generated state
- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` as read-only generated output
- `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, and `project-level/-unresolved.md` as read-only generated/project state
- `by-project-structure/proposed-source-tree.md` as read-only source-placement context

Prior reports checked as leads, not authority:

- Active executed B004 report `tools/leaser/Agents/Agent-B004/research/executed/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Archived B014 report `archived/b-agent-reports-20260623/Agent-B014/research/executed/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Archived B006 report for [UID:0002TZ] `AttachmentAnchorApplyLight`.
- Archived B011/B015 reports for adjacent `AttachmentAnchorResolver` raw/modelled siblings.

Current MCP evidence:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Active session: `ff68e691`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP health input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- MCP module: `NexusTK.exe`, imagebase `0x400000`.

Fresh local PE supplement:

- PE path: `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## MCP Health And Schema

- `initialize` succeeded. MCP server name `ida-pro-mcp`, protocol `2025-06-18`.
- `tools/list` succeeded and returned `65` tools.
- `idb_list` returned one active worker-backed session:
  - session id `ff68e691`;
  - input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`;
  - filename `NexusTK.exe.i64`;
  - `is_active:true`;
  - `is_analyzing:false`;
  - backend `worker`;
  - PID/worker PID `14256`;
  - created `2026-06-23T12:41:35.735698`.
- `server_health(database=ff68e691)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- Current schemas used:
  - `lookup_funcs(queries,database)`;
  - `get_bytes(regions,database)`;
  - `insn_query(queries,database)`;
  - `decompile(addr,include_addresses,database)`;
  - `disasm(addr,max_instructions,include_total,database)`;
  - `xrefs_to(addrs,limit,database)`;
  - `xref_query(queries,database)`;
  - `find_bytes(patterns,limit,offset,database)`;
  - `callees(addrs,limit,database)`;
  - `analyze_function(addr,include_asm,database)`;
  - `int_convert(inputs,database)`.
- The current schema did not provide a usable `callers` method; `tools/call callers` returned `Method 'callers' not found`. Caller evidence therefore comes from `xrefs_to`, `xref_query`, and raw instruction windows.
- No MCP availability failure occurred. `decompile(0x0053c9f0)` and `analyze_function(0x0053c9f0)` returned target-specific analysis failures because the raw address is not an IDA function object; those are evidence, not MCP unavailability.

## Current Target State

- The by-memory target already contains first-draft C++ and detailed B004 `b880584f` evidence.
- `project-level/-auto-completion-stats.md` lists [UID:0002U0] at `85 | 87 | 86.0`.
- `auto-generated/-ag-memory-coverage.md` classifies [UID:0002U0] as `coded` through `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`.
- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` emits `AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY)` for [UID:0002U0].
- `by-memory/-coverage-report.md` currently cites B004 MCP session `b880584f`; if this B002 report is accepted, the supervisor-owned row should be updated to cite current B002 session `ff68e691`.
- `project-level/-unresolved.md` still reports `dword_69B450`, `sub_53CA20`, and `this+0x128` in target/support prose. These unresolved entries are mostly raw-evidence alias/search-term noise, not unresolved behavior, but they support keeping completion below final-audit levels.

## MCP Function And Range Evidence

`lookup_funcs(database=ff68e691)` produced:

| Address | MCP result | Interpretation |
| --- | --- | --- |
| `0x0053c6b0` | Not a function | raw metric sibling, no IDA function object |
| `0x0053c700` | `sub_53C700`, size `0x102` | modeled `ResolveAnchorPoint` helper |
| `0x0053c810` | `sub_53C810`, size `0x11e` | modeled `ComputeScreenBounds` helper |
| `0x0053c930` | Not a function | raw screen-bounds notification sibling |
| `0x0053c980` | `sub_53C980`, size `0x35` | neighboring `LightingObjectPaneSetIntensity` |
| `0x0053c9c0` | `sub_53C9C0`, size `0x2b` | modeled caller-backed mode-1 sibling |
| `0x0053c9eb` | Not a function | alignment after mode-1 sibling |
| `0x0053c9f0` | Not a function | target raw mode-2 twin |
| `0x0053ca1a` | Not a function | final byte inside target body |
| `0x0053ca1b` | Not a function | first post-body padding byte |
| `0x0053ca20` | `sub_53CA20`, size `0x94` | next modeled successor after padding |
| `0x004dfbb0` | `sub_4DFBB0`, size `0xaa` | `LightObjImageLib::DrawLightMode1` |
| `0x004dfc60` | `sub_4DFC60`, size `0xaa` | `LightObjImageLib::DrawLightMode2` |
| `0x0061b750`, `0x0061b760`, `0x0069b450` | Not functions | vtable/global data, not code starts |

Conversions used in this report were checked with both MCP `int_convert` and project `tools/int_convert.py`:

| Value | Decimal | Meaning |
| --- | ---: | --- |
| `0x2b` | 43 | target/mode-1 body length (Verified with int_convert.py) |
| `0x5` | 5 | pre/post padding length (Verified with int_convert.py) |
| `0x0c` | 12 | `retn 0Ch`, three explicit stack arguments (Verified with int_convert.py) |
| `0x10` | 16 | LightObjImageLib virtual slot for mode 2 (Verified with int_convert.py) |
| `0x128` | 296 | resolver `m_lightImageIndex` field offset (Verified with int_convert.py) |
| `0x3e0` | 992 | `MapPane::m_selectionOverlay` offset (Verified with int_convert.py) |
| `0xaa` | 170 | draw-mode method body size (Verified with int_convert.py) |
| `0x102` | 258 | modeled `0x0053c700` size (Verified with int_convert.py) |
| `0x11e` | 286 | modeled `0x0053c810` size (Verified with int_convert.py) |
| `0x35` | 53 | neighboring `0x0053c980` size (Verified with int_convert.py) |
| `0x94` | 148 | successor `0x0053ca20` size (Verified with int_convert.py) |
| `0x0013c9f0` | 1296880 | target RVA pointer search value (Verified with int_convert.py) |
| `0x0013bdf0` | 1293808 | target raw-offset pointer search value (Verified with int_convert.py) |

## MCP Bytes, Padding, And Raw Disassembly

`get_bytes(database=ff68e691)` returned:

| Range | Bytes |
| --- | --- |
| `0x0053c9eb-0x0053c9f0` | `cc cc cc cc cc` |
| `0x0053c9f0-0x0053ca1b` | `55 8b ec 8b 15 50 b4 69 00 8b 45 08 56 ff b1 28 01 00 00 8b 32 8b ca ff 75 10 ff 75 0c ff b0 e0 03 00 00 ff 56 10 5e 5d c2 0c 00` |
| `0x0053ca1b-0x0053ca20` | `cc cc cc cc cc` |
| `0x0053c9c0-0x0053c9eb` | same wrapper shape as the target except the indirect call uses `[esi+0Ch]` instead of `[esi+10h]` |
| `0x0061b750-0x0061b768` | `0c 90 64 00 e0 65 4e 00 10 4b 4f 00 c0 b6 41 00 b0 fb 4d 00 60 fc 4d 00` |
| `0x0069b450-0x0069b454` | `00 00 00 00` in the current IDB read |

`insn_query(database=ff68e691, start=0x0053c9f0, end=0x0053ca1b)` rendered the complete raw body:

```asm
0053c9f0  push ebp
0053c9f1  mov ebp, esp
0053c9f3  mov edx, dword ptr unk_69B450
0053c9f9  mov eax, [ebp+8]
0053c9fc  push esi
0053c9fd  push dword ptr [ecx+128h]
0053ca03  mov esi, [edx]
0053ca05  mov ecx, edx
0053ca07  push dword ptr [ebp+10h]
0053ca0a  push dword ptr [ebp+0Ch]
0053ca0d  push dword ptr [eax+3E0h]
0053ca13  call dword ptr [esi+10h]
0053ca16  pop esi
0053ca17  pop ebp
0053ca18  retn 0Ch
```

`insn_query` reported `fn:null` for every target instruction, confirming the code-shaped body exists but is not in an IDA function object. The half-open range is exact: `retn 0Ch` begins at `0x0053ca18`, its two operand bytes occupy through `0x0053ca1a`, and `0x0053ca1b-0x0053ca20` is five `0xcc` bytes before `sub_53CA20`.

The modeled mode-1 sibling at `0x0053c9c0-0x0053c9eb` has the same body shape but calls `[esi+0Ch]`. MCP reports it as function `sub_53C9C0`, size `0x2b`; the target remains unmodeled despite being byte-for-byte analogous except for the virtual slot.

## MCP Decompilation And Callee Evidence

- `decompile(database=ff68e691, addr=0x0053c9f0)` returned `code:null`, `error:"Decompilation failed at 0x53c9f0"`. This is expected no-function evidence.
- `analyze_function(database=ff68e691, addr=0x0053c9f0)` returned `error:"No function at 0x53c9f0"`.
- `callees(database=ff68e691, addr=0x0053c9f0)` returned `No function found`.
- `callees(database=ff68e691, addr=0x0053c9c0)` returned an empty list because the modeled mode-1 helper's only meaningful call is indirect.
- `callees(database=ff68e691, addr=0x004dfbb0)` and `callees(database=ff68e691, addr=0x004dfc60)` returned the same internal dependencies: `0x004b7c50`, `0x00462e10`, and `@__security_check_cookie@4`.
- `callees(database=ff68e691, addr=0x0053ca20)` returned `0x005372d0`, reinforcing that the successor belongs to unrelated SoundObjectPane/ObjectPane setup rather than this raw target.

The modeled mode-1 sibling decompiles as:

```c
int __thiscall sub_53C9C0(_DWORD *this, int a2, int a3, int a4)
{
  return (*(int (__thiscall **)(int, _DWORD, int, int, _DWORD))(*(_DWORD *)unk_69B450 + 12))(
           unk_69B450,
           *(_DWORD *)(a2 + 992),
           a3,
           a4,
           this[74]);
}
```

This decompiler result is a shape check only. Source-quality interpretation is `void AttachmentAnchorResolver::ApplyLightAtAnchor(MapPane *mapPane, int centerX, int centerY)`, because both live callers ignore the result and the virtual draw method is source-modeled as `void`.

MCP decompilation of `0x004dfbb0` and `0x004dfc60` confirms the LightObjImageLib pair: both select a `LightInfo` row or fallback, load the generated frame, compute centered source/destination rectangles, and call the shared blitter. The mode-1 method passes final literal `1`; the mode-2 method passes final literal `2`. This strongly supports interpreting the target's `[esi+10h]` virtual call as `LightObjImageLib::DrawLightMode2`.

## MCP Xref, Pointer, And Route Evidence

Incoming xrefs from current MCP:

| Target | MCP result |
| --- | --- |
| `0x0053c6b0` | zero xrefs |
| `0x0053c700` | two code refs: `0x005096be`, `0x0050aabf` |
| `0x0053c810` | ten code refs: `0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, `0x0053c958` |
| `0x0053c930` | zero xrefs |
| `0x0053c9c0` | two code refs: `0x005096cc` in `sub_5094B0` and `0x0050aacf` with no containing-function metadata |
| `0x0053c9f0` | zero xrefs; `xrefs_to` message `No cross-references to this address` |
| `0x0053ca20` | six code refs, all into the SoundObjectPane successor |
| `0x004dfbb0` | one data ref at `0x0061b760` |
| `0x004dfc60` | one data ref at `0x0061b764` |
| `0x0061b760` / `0x0061b764` | zero incoming refs to the slot dword addresses themselves |
| `0x0069b450` | nineteen data refs, including `0x0053c9c3` and raw target read `0x0053c9f3` |

`xref_query(database=ff68e691)` split the target-start route into code/data checks:

- `to 0x0053c9f0`, type `code`: zero results.
- `to 0x0053c9f0`, type `data`: zero results.
- `from 0x0053c9f0`, type `data`: zero results.
- `from 0x0053c9f0`, type `code`: only the normal fall-through to `0x0053c9f1`.

Outgoing operand checks:

- `xref_query(from=0x0053c9f3)` returned the data ref to `0x0069b450` and ordinary fall-through to `0x0053c9f9`.
- `xref_query(from=0x0053ca13)` returned only fall-through to `0x0053ca16`; IDA cannot resolve the raw indirect virtual call at `[esi+10h]`.
- The modeled sibling's analogous reads at `0x0053c9c3` and indirect call at `0x0053c9e3` behave the same way, except the containing function metadata is available for the modeled sibling.

`find_bytes(database=ff68e691)` searched direct dword encodings:

| Pattern | Meaning | Result |
| --- | --- | --- |
| `f0 c9 53 00` | VA `0x0053c9f0` | zero matches |
| `f0 c9 13 00` | RVA `0x0013c9f0` | zero matches |
| `f0 bd 13 00` | raw offset `0x0013bdf0` | zero matches |
| `c0 c9 53 00` | VA `0x0053c9c0` | zero matches, expected because sibling reachability is by direct `rel32` calls |
| `b0 fb 4d 00` | VA `0x004dfbb0` | one match at `0x0061b760` |
| `60 fc 4d 00` | VA `0x004dfc60` | one match at `0x0061b764` |
| `50 b4 69 00` | VA `0x0069b450` | nineteen matches, including operand bytes at `0x0053c9c5` and `0x0053c9f5` |

The positive controls matter. The current IDB search finds real direct calls to modeled resolver helpers, real data refs to LightObjImageLib vtable entries, and real absolute encodings of `g_pLightObjImageLib`. The absence of any equivalent route to `0x0053c9f0` is meaningful negative evidence, not merely a missing symbol name.

## Sibling Caller Context

Current MCP instruction windows confirm the modeled mode-1 sibling remains live in two MapPane paths:

```asm
005096be  call sub_53C700
005096c3  push [ebp+var_60]
005096c6  mov ecx, esi
005096c8  push [ebp+var_5C]
005096cb  push ebx
005096cc  call sub_53C9C0
```

```asm
0050aabf  call sub_53C700
0050aac4  push dword ptr [ebp-0Ch]
0050aac7  mov ecx, edi
0050aac9  push dword ptr [ebp-8]
0050aacc  push dword ptr [ebp-2Ch]
0050aacf  call sub_53C9C0
```

Both sequences call `ComputeScreenBounds` earlier, test/intersect visibility, call `ResolveAnchorPoint`, then call the mode-1 helper with `MapPane *` and resolved coordinates. No analogous caller sequence reaches `0x0053c9f0`. This strongly supports keeping [UID:0002TZ] and [UID:0002U0] separate: the first is caller-backed mode 1, the second is a retained raw mode-2 twin with behavior proven but liveness unproven.

## Fresh PE Route-Scan Supplement

This supplement is not a fallback for MCP. It was run after MCP succeeded to independently test raw reachability.

PE section map:

| Section | VA range basis | Raw range basis |
| --- | --- | --- |
| `.text` | `0x00401000`, virtual size `0x20b4ac` | raw `0x00000400`, size `0x20b600` |
| `.rdata` | `0x0060d000`, virtual size `0x5f0be` | raw `0x0020ba00`, size `0x5f200` |
| `.data` | `0x0066d000`, virtual size `0x2fe24` | raw `0x0026ac00`, size `0xd800` |

Fresh range hashes:

| Range | Raw offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| pre-padding `0x0053c9eb-0x0053c9f0` | `0x0013bdeb` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` |
| target `0x0053c9f0-0x0053ca1b` | `0x0013bdf0` | `0x2b` | `0c3c02b5675b5030e3d04c9923bc1e029e238a0f2717ca8b330dcbab0d3fd21b` |
| post-padding `0x0053ca1b-0x0053ca20` | `0x0013be1b` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` |
| modeled sibling `0x0053c9c0-0x0053c9eb` | `0x0013bdc0` | `0x2b` | `13c17a8da20ed2414a145ef2f7fb3c912f64384514d363e5d802b2fbfc547b97` |

Fresh `.text` direct control-transfer scan for `E8`, `E9`, and near conditional `0F 8x` targets:

| Target | Result |
| --- | --- |
| `0x0053c6b0` raw metric sibling | zero hits |
| `0x0053c700` `ResolveAnchorPoint` | two hits: `call@0x005096be`, `call@0x0050aabf` |
| `0x0053c810` `ComputeScreenBounds` | ten hits: `call@0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, `0x0053c958` |
| `0x0053c930` raw screen-bounds sibling | zero hits |
| `0x0053c9c0` modeled mode-1 sibling | two hits: `call@0x005096cc`, `call@0x0050aacf` |
| `0x0053c9f0` target raw mode-2 twin | zero hits |
| `0x004dfbb0` `DrawLightMode1` | zero direct control hits, expected because vtable-only |
| `0x004dfc60` `DrawLightMode2` | zero direct control hits, expected because vtable-only |

Fresh dword literal scan across `.text`, `.rdata`, and `.data`:

| Literal | Result |
| --- | --- |
| VA `0x0053c9f0` | zero hits |
| RVA `0x0013c9f0` | zero hits |
| raw offset `0x0013bdf0` | zero hits |
| VA `0x0053c9c0` | zero hits; sibling route is direct `rel32` calls |
| VA `0x004dfbb0` | one hit at `0x0061b760` |
| VA `0x004dfc60` | one hit at `0x0061b764` |
| VA `0x0069b450` | nineteen hits, including `0x0053c9c5` and `0x0053c9f5` |

The fresh PE supplement agrees with the current MCP pass and the already incorporated B004 route scan.

## Behavior And Data Flow

The target is a compact consumer-side wrapper:

1. It reads global singleton storage `0x0069b450`, source-facing `g_pLightObjImageLib`.
2. It reads the first explicit stack argument as a `MapPane *`.
3. It pushes resolver field `this+0x128`, source-facing `m_lightImageIndex`.
4. It loads the LightObjImageLib vtable through the singleton.
5. It pushes the two caller-supplied coordinates.
6. It pushes `MapPane+0x3e0`, current source-facing `m_selectionOverlay`, as the target alpha-mask surface.
7. It calls LightObjImageLib virtual slot `+0x10`, resolved by vtable data as `LightObjImageLib::DrawLightMode2`.
8. It returns with `retn 0Ch`, confirming three explicit stack arguments.

Source-quality field/name map:

| Raw evidence | Source-facing conclusion | Strength |
| --- | --- | --- |
| `mov edx, dword ptr unk_69B450`, 19 refs to `0x0069b450` | `g_pLightObjImageLib`, type `LightObjImageLib *` | Strong for role/current project name; original symbol spelling not IDB-proven |
| vtable dword `0x0061b764 -> 0x004dfc60`, call `[esi+10h]` | `LightObjImageLib::DrawLightMode2` | Strong |
| sibling slot `0x0061b760 -> 0x004dfbb0`, call `[esi+0Ch]` | `LightObjImageLib::DrawLightMode1` for [UID:0002TZ] | Strong |
| `push dword ptr [ecx+128h]` / sibling `this[74]` | `AttachmentAnchorResolver::m_lightImageIndex` | Strong role, medium original spelling |
| `push dword ptr [eax+3E0h]` | `mapPane->m_selectionOverlay`, `AlphaMaskSurface *`-style target surface | Strong enough for draft C++; target alone proves only an offset-based surface pointer |
| `[ebp+0Ch]` and `[ebp+10h]` | resolved anchor coordinates `centerX`, `centerY` | Strong by modeled sibling caller sequence |
| helper spelling | `ApplyLightMode2AtAnchor` | Descriptive/inferred, not original-symbol proof |

The `MapPane +0x3e0` field is supported by [UID:00007Q] `MapPane` and [UID:0002I7] `MapPaneInitialize`, which document allocation of an `AlphaMaskSurface`-style selection/overlay surface from back-pane bounds and storage at `+0x3e0`. If a later MapPane field pass renames `m_selectionOverlay`, update this target's draft member spelling only.

## Ownership And Source Placement Reanalysis

Ranked owner/source-placement candidates:

1. [UID:00000O] `AttachmentAnchorResolver` via [UID:0000HL] `AttachmentAnchorResolver` - keep. Evidence: the receiver field is resolver `m_lightImageIndex`, the mode-1 sibling is caller-backed under the resolver class, the resolver/bounds/metric siblings use the same LightObjImageLib index family, and current generated output routes the wrapper through `NexusTK/map/AttachmentAnchorResolver.cpp`. This target is consumer-side anchor placement glue, not the image library implementation.
2. Broad [UID:0000HJ] `AttachedObjectPane` source-file fold - keep as a source-layout caveat only. Current source-tree and file docs say the original source may have used a private helper/class inside `AttachedObjectPane.cpp`. That is plausible for original file placement, but it does not replace the narrow semantic owner or justify a route migration in this one raw-helper report.
3. [UID:0000KP] `LightObjImageLib` - reject as owner. LightObjImageLib owns `g_pLightObjImageLib`, the vtable, and `DrawLightMode2`; this target merely prepares a MapPane target surface, resolved coordinates, and resolver light index before dispatching to the library.
4. [UID:0000L3] `MapPane` - reject as direct owner. MapPane supplies live caller context for the modeled mode-1 sibling and owns `m_selectionOverlay`, but this target's receiver is the resolver object and the light index belongs to the attachment-anchor family.
5. [UID:0000KO] `LightingObjectPane` - reject. The target is near lighting-object code in memory, but `LightingObjectPaneSetIntensity` ends at `0x0053c9b5`, is separated by padding, and uses different state and callers.
6. [UID:0000NW] `SoundObjectPane` - reject. `SoundObjectPaneCore` starts after five `0xcc` bytes at `0x0053ca20`; its modeled function, vtable writes, timer/sound state, and constructor flow are unrelated.
7. No-owner/non-emitting - reject. The body is reconstructable custom game code with resolved class state, singleton dependency, vtable target, and current emitter route. Missing liveness caps confidence; it does not make the bytes non-source or non-emitting.

Source route recommendation:

- Keep current route `NexusTK/map/AttachmentAnchorResolver.cpp` through [UID:0000HL] for now.
- Preserve the stronger original-source caveat that `AttachmentAnchorResolver` may eventually fold into `map/AttachedObjectPane.cpp` as a private helper/class.
- Do not migrate this target alone. A migration should be a family-level supervisor decision covering the class page, file root, modeled resolver/bounds method, mode-1 helper, and raw siblings together.

## Split, Range, And Boundary Decision

No split, merge, range rename, or child creation is recommended.

- Keep exact half-open range `0x0053c9f0-0x0053ca1b`.
- Keep pre-padding `0x0053c9eb-0x0053c9f0` as five `0xcc` bytes.
- Keep post-padding `0x0053ca1b-0x0053ca20` as five `0xcc` bytes.
- Keep [UID:0002TZ] `0x0053c9c0-0x0053c9eb` separate. It is the live modeled mode-1 helper and uses slot `+0x0c`.
- Keep [UID:0001DJ] `0x0053ca20-0x0053ce3c.SoundObjectPaneCore` separate. The successor starts at `0x0053ca20` after padding and has unrelated SoundObjectPane/ObjectPane behavior.
- Do not treat the target as padding or ignored bytes. It has a normal prologue/body/indirect-call/`retn 0Ch` shape and source-authored data flow.

## C++ Readiness Recommendation

Keep the existing formal first-draft C++ block. Do not replace it with a no-code marker in this pass.

Reasons to keep C++:

- The target is `RECONSTRUCTABLE:TRUE`.
- It has a confirmed nonblank `EMITTER_UIDS:00000O` route that surfaces to `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`.
- The combined score `(85 + 87) / 2 = 86` clears the current minimum code-entry gate.
- The body has complete byte and instruction evidence with one unambiguous virtual dispatch.
- The callee identity, global name, field role, first argument type, and coordinate roles are source-quality enough for a compact human-written wrapper.
- The existing code avoids decompiler-shaped pointer arithmetic and matches the modeled mode-1 sibling's established style.

Why this is still draft-only:

- No current route proves the raw start is live.
- No original symbol proves `ApplyLightMode2AtAnchor`; `DrawLightMode2AtAnchor` remains a possible future spelling if the family standardizes on draw terminology.
- `m_selectionOverlay` and `m_lightImageIndex` are current source-facing names, not PDB-proven original spellings.
- The original source-file layout may have been private `AttachedObjectPane.cpp` rather than standalone `AttachmentAnchorResolver.cpp`.

If a later project-wide policy forbids formal C++ on raw no-xref helpers, the safe fallback is to replace only the formal code block with a target-specific comment/no-code marker while preserving all behavior evidence. I do not recommend that now.

## Score And Metadata Recommendation

Keep metadata unchanged:

| Field | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| `COMPLETION` | 85 | 85 | The page is already detailed, and current MCP/PE rechecks add current provenance but do not resolve the remaining liveness/source-placement/original-name blockers. |
| `CONFIDENCE` | 87 | 87 | Current MCP confirms exact bytes, range, no-function state, xref negatives, pointer negatives, sibling/vtable/global positives, and no-code fallback caveat. Confidence remains capped by no proven route to the raw start and inferred original spelling/source file. |
| `CANONICAL_OWNER` | `00000O` | `00000O` | AttachmentAnchorResolver is the best narrow semantic owner. |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` | Source-authored game-code wrapper bytes. |
| `EMITTER_UIDS` | `00000O` | `00000O` | Current source route is valid and already emits. |
| `EMITTER_POSITION_OPTIONAL` | blank | blank | No ordering change recommended. |
| `RECONSTRUCTION_CPP` | populated | keep populated | Existing C++ remains source-shaped and eligible, but draft-only. |

Reason not higher:

- No function object at `0x0053c9f0`.
- No incoming code/data xrefs to `0x0053c9f0`.
- No direct `rel32` call/jump/near-conditional route to `0x0053c9f0`.
- No VA/RVA/raw-offset dword literal route to `0x0053c9f0`.
- No callback/table/vtable slot pointing to `0x0053c9f0`.
- No original helper name or original file placement proof.
- Project unresolved output still sees raw aliases preserved in evidence prose.

Reason not lower:

- Current MCP and PE both confirm exact range, bytes, padding, instruction semantics, source dependencies, sibling relationship, vtable target, and positive controls.
- The owner/emitter route is coherent and already used by generated output.
- The no-route state is a confidence cap, not evidence that the target is dead padding or non-source.

## Open Questions And Evidence Needed To Raise

- Liveness: a future code ref, callback table entry, function-pointer literal, runtime trace, or static analysis proof must reach `0x0053c9f0` before confidence can move meaningfully above the current cap.
- Original helper spelling: a source/PDB/map symbol or stronger family naming convention would be needed to prefer `ApplyLightMode2AtAnchor` over `DrawLightMode2AtAnchor` as original-source spelling.
- Original source file: family-level migration evidence would be needed to move `AttachmentAnchorResolver` from the current synthetic file root into `AttachedObjectPane.cpp`.
- MapPane field spelling: a later MapPane layout/name pass may rename `m_selectionOverlay`; behavior would not change.

## Target And Support Changes Needed If Accepted

Required target sync:

- `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- Keep metadata and formal C++ unchanged.
- Add a dated B002 `ff68e691` MCP-backed evidence section, or supersede the existing B004 `b880584f` section with current B002 evidence while preserving valid B004/PE facts as historical support.
- Include current endpoint/session/health/schema facts; current `lookup_funcs`; current exact bytes/padding; current `insn_query` raw disassembly; current decompile/analyze-function failure at the raw start; current `xrefs_to`/`xref_query` zero incoming refs; current `find_bytes` zero VA/RVA/raw-offset target hits; current sibling/vtable/global positive controls; fresh PE route-scan supplement; owner/source-placement reanalysis; score rationale; and current draft-only C++ rationale.
- Replace or rewrite any wording that implies the active cap is due to old MCP availability. The active cap is confirmed raw no-route evidence.

Required support sync:

- `by-class/AttachmentAnchorResolver.md`
  - Update the `0002U0` method/layout/evidence notes to cite current B002 session `ff68e691` instead of only B004 `b880584f`.
  - Preserve endpoint/range/no-function/no-xref/no-pointer evidence, `g_pLightObjImageLib`, `DrawLightMode2`, `m_lightImageIndex`, `MapPane::m_selectionOverlay`, the modeled mode-1 sibling contrast, and draft-only caveat.
- `by-file/AttachmentAnchorResolver.md`
  - Update the proposed-contents/boundary/current MCP route section to cite current B002 session `ff68e691`.
  - Preserve current synthetic `NexusTK/map/AttachmentAnchorResolver.cpp` route, possible private `AttachedObjectPane.cpp` fold caveat, rejected LightingObjectPane/SoundObjectPane/MapPane/LightObjImageLib/no-owner alternatives, and draft-only status.

Optional/no-op support checks:

- `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`: likely no edit needed. It already records the mode-1/mode-2 relationship and raw twin no-route cap at enough detail for the sibling's role. Add a one-sentence `ff68e691` current-session note only if the supervisor wants all related pages to cite this B002 pass.
- `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`, `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`, `by-type/by-vtable/LightObjImageLibVtable.md`, `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`, `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`, `by-class/MapPane.md`, and `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`: no required edit found. They already support the needed vtable/global/field roles at same-or-greater detail.

No by-project-structure, generated/project-level, IDA DB, tool-state, or `-coverage-report.md` edits should be made by B002 during implementation unless a future supervisor callback explicitly expands scope.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the current [UID:0002U0] row under the local `0x0053c9c0`/`0x0053ca20` neighborhood if the supervisor accepts this current-session provenance update.

```text
    - [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) 0x0053c9f0-0x0053ca1b | raw helper method | AttachmentAnchorLightApplyTwinRaw : reconstructable : 85% : strong : Attached under `AttachmentAnchorResolver`; source-quality reanalysis resolves `dword_69B450`/`unk_69B450` as `g_pLightObjImageLib`, virtual slot `+0x10` as `LightObjImageLib::DrawLightMode2`, `this+0x128` as resolver `m_lightImageIndex`, and `arg0+0x3e0` as current `MapPane::m_selectionOverlay`; B002 MCP-backed pass on 2026-06-23 using IDA MCP session `ff68e691` reconfirms the exact `0x0053c9f0-0x0053ca1b` raw body, five-byte `0xcc` padding before and after, no modeled function/decompile/analyze-function result at the raw start, zero incoming code/data xrefs or VA/RVA/raw-offset pointer hits to `0x0053c9f0`, fresh PE supplement zero direct control-transfer routes, positive controls for the modeled mode-1 sibling callers, resolver helper callers, LightObjImageLib vtable dwords, and `g_pLightObjImageLib` references, and keeps draft-only `ApplyLightMode2AtAnchor` C++ while preserving final-source confidence caps for reachability, original helper spelling, MapPane field spelling, and original source-file folding.
```

Reason B002 must not apply it directly: the assignment and B-agent workflow reserve `-coverage-report.md` edits for supervisor-owned application unless a current explicit override permits that exact file. No such override exists.

## Validators Expected After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for every changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md](0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional sibling/support pages are edited during a callback, run the same scoped validator for each changed relative by-* path. No validators were run in the original report-only pass because no by-* docs were edited then. Implementation callback validators are recorded in the checklist below.

## Changed Files In This Report Pass

- Created: `tools/leaser/Agents/Agent-B002/research/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Modified by-* docs: none.
- Modified generated/project-level files: none.
- Modified `-coverage-report.md` files: none.
- IDA DB/tool state edits: none.
- Leases used: none.

## Changed Files In Implementation Callback

- Modified by-* docs:
  - `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
  - `by-class/AttachmentAnchorResolver.md`
  - `by-file/AttachmentAnchorResolver.md`
- Checked and left unchanged:
  - `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md` already documented the mode-1/mode-2 split and the raw twin no-route contrast at same-or-greater detail.
- Modified report:
  - `tools/leaser/Agents/Agent-B002/research/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`
- Modified `-coverage-report.md` files: none. Supervisor-owned coverage text remains supplied above.
- Validator side effects observed during required `--apply` runs: `project-level/-auto-completion-stats.md` projected stats/stat rows and `tools/validator.ini` registry rebuild were updated by the validator; auto-generated reports/C++ were reported as noop. These are validator side effects, not manual edits.
- IDA DB/tool state edits: none.
- Leases used for by-* edit/validation batch: attempted exact B002 lease for the three edited docs; all three lease requests succeeded. `release` is not a valid leaser command; `unlease` then reported `Rejected[No active lease]` for all three paths, and `current_leases.md` had no B002/AttachmentAnchor entries after validation.

## Blockers

No MCP operational blocker remains for this report. Session `ff68e691` was healthy and responsive.

Remaining target/source-quality blockers:

- no IDA function object at `0x0053c9f0`;
- no incoming xrefs or direct route to `0x0053c9f0`;
- raw-start decompilation and function analysis fail because no function object exists;
- no VA/RVA/raw-offset literal or table/pointer route to the raw start;
- no original helper spelling proof;
- final original source-file placement remains unresolved between current synthetic `AttachmentAnchorResolver.cpp` and possible private `AttachedObjectPane.cpp` fold;
- current MapPane `m_selectionOverlay` spelling is supported but not original-symbol proof.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and updated `goal.md` for implementation callback `B002-implement-attachment-anchor-light-apply-twin-raw-source-quality-0002U0-mcp-20260623`.
- [x] Target doc to update if accepted: `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`. Proof: updated Status, Raw IDA Evidence, new `2026-06-23 B002 Accepted MCP-Backed Implementation Evidence`, Boundary Notes, Source-Quality Reanalysis, Score Rationale, and Changes. Metadata remains `85/87`, owner/emitter `00000O`, reconstructable true, blank emitter position, and existing first-draft C++ unchanged.
- [x] Required support doc to update if accepted: `by-class/AttachmentAnchorResolver.md`. Proof: updated method inventory, Layout Notes, Evidence Notes, Score Rationale, and Changes to cite current B002 `ff68e691` route/no-route proof while preserving valid B004/PE history, field roles, draft-only caveat, and source-placement caveat.
- [x] Required support doc to update if accepted: `by-file/AttachmentAnchorResolver.md`. Proof: updated Proposed Contents, Boundary Notes, new `2026-06-23 B002 Accepted MCP-Backed 0002U0 Route Check`, Score Rationale, and Changes to cite current B002 `ff68e691`; preserved synthetic route, possible `AttachedObjectPane.cpp` fold, rejected owners, and raw no-route cap.
- [x] Optional support check if accepted: `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`. Proof: checked before editing and left unchanged because it already records the mode-1/mode-2 relationship, raw twin no-function/no-xref/no-pointer cap, and no folding of [UID:0002U0] into the mode-1 method at same-or-greater detail.
- [x] Optional/no-op support check if accepted: `by-memory/0x004dfbb0-0x004dfc5a.LightObjImageLibDrawLightMode1.md`, `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`, `by-type/by-vtable/LightObjImageLibVtable.md`, `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`, `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`, `by-class/MapPane.md`, and `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`. Proof: no accepted implementation scope required edits to these pages, and the target/class/file docs now preserve their vtable/global/field roles by reference.
- [x] Metadata/score changes to apply or explicitly not apply: keep target `COMPLETION:85`, `CONFIDENCE:87`; no owner/emitter/reconstructable/C++ metadata change. Proof: target metadata lines remain `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000O`, blank `EMITTER_POSITION_OPTIONAL`, and unchanged formal C++.
- [x] Split/rename/new-child changes to apply or explicitly not apply: none. Proof: target remains exact half-open range `0x0053c9f0-0x0053ca1b`; target page records pre-padding `0x0053c9eb-0x0053c9f0`, post-padding `0x0053ca1b-0x0053ca20`, modeled mode-1 sibling separate, and SoundObjectPane successor separate.
- [x] First-draft C++ or no-code disposition to apply: keep existing source-shaped `AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY)` block. Proof: formal block unchanged; target/class/file prose now marks the body explicitly draft-only and rejects decompiler-shaped pointer arithmetic or blank/no-code replacement.
- [x] Exact target/support facts to incorporate if accepted: MCP health/session/schema facts; function/no-function inventory; exact body/padding bytes; raw disassembly; decompile/analyze-function failure at raw start; zero xrefs to `0x0053c9f0`; outgoing data ref to `g_pLightObjImageLib`; no resolved raw indirect callee; sibling decompile/disassembly; vtable bytes; `find_bytes` zero VA/RVA/raw-offset target hits; fresh PE hash/section/range hashes/direct-control/dword-literal results; positive controls; field/name/type decisions; rejected owners; score/C++ rationale. Proof: incorporated into target B002 evidence section and synchronized summaries in class/file docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve if accepted: old MCP-unavailable language should be superseded as stale, not deleted without explanation if it remains useful history; preserve rejected `LightObjImageLib`, `LightingObjectPane`, `SoundObjectPane`, `MapPane`, broad `AttachedObjectPane`, and no-owner/non-emitting alternatives; preserve no-function/no-xref/no-pointer/no-route negative evidence. Proof: B014 MCP-unavailable caveat is now explicitly superseded by B002 `ff68e691`; B004 `b880584f` remains historical corroboration; rejected owners and negative route evidence remain in target/class/file docs.
- [x] Wave2/Wave3/generated artifacts encountered and ignored/rejected as authority: generated output and project stats were read as state/lead material only; they do not override current MCP evidence. Proof: no generated/source tree docs were manually edited; validator side effects are recorded separately.
- [x] Open questions to close or document as evidence-backed unresolved if accepted: liveness route, original helper spelling, exact original source-file placement, and future MapPane field spelling. Proof: target/class/file docs preserve these as the active score/confidence caps.
- [x] Validators to run after accepted implementation: run the scoped commands listed in `Validators Expected After Implementation` for each changed by-* doc and record command, exit code, `ok` count, warnings, and side effects. Proof: all three required validators are recorded below.
- [x] Supervisor-owned coverage-report/tracker text to apply: replace the [UID:0002U0] row in `by-memory/-coverage-report.md` with the exact text supplied above if supervisor accepts this provenance update. B002 must not edit `-coverage-report.md` during callback unless explicitly authorized. Proof: exact text remains supplied above; no `-coverage-report.md` file was edited.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted in supervisor callback for [UID:0002U0] and implemented under updated `goal.md`.
- [x] Leases taken only immediately before editing and released immediately after edit/validator batch: `python .\tools\leaser\leaser.py B002 lease by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md by-class\AttachmentAnchorResolver.md by-file\AttachmentAnchorResolver.md` exited `0` with `Success` for all three files. `release` is not a valid command; `python .\tools\leaser\leaser.py B002 unlease ...` exited `1` with `Rejected[No active lease]` for all three paths, and read-only `current_leases.md` check showed no B002/AttachmentAnchor/0002U0 entries afterward.
- [x] All accepted target/support doc details incorporated at report-level detail: target, class, and file docs now cite B002 `ff68e691` current MCP evidence, PE supplement, no-route proof, field/name/type decisions, rejected owners, source-placement caveat, and draft-only C++ rationale.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target metadata kept at `85/87`, owner/emitter `00000O`, reconstructable true, blank emitter position, unchanged draft C++, no split/rename/new child.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B004 and B014 history retained as historical corroboration; B014 MCP-unavailable caveat superseded by B002; all rejected owners and negative route facts preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: live reachability, original helper spelling, final source-file fold, and exact original `MapPane +0x3e0` spelling remain documented score caps.
- [x] Validators run and results recorded:
  - `python .\tools\validator.py --mode file --file by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects included `stats_row_update: 4`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, stale registry warnings for `0003E6` and `00026U`, auto-generated C++/coverage reports noop.
  - `python .\tools\validator.py --mode file --file by-class\AttachmentAnchorResolver.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects included `uid_link_insert 0002U0`, `stats_incremental_noop: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, stale registry warnings for `0003E6` and `00026U`, auto-generated C++/coverage reports noop.
  - `python .\tools\validator.py --mode file --file by-file\AttachmentAnchorResolver.md --apply --queue-timeout 240`: exit `0`, `ok: 1`; side effects included `stats_incremental_noop: 1`, `projected_stats_update: 1`, `autogen_registry_rebuild: 1`, stale registry warnings for `0003E6` and `00026U`, auto-generated C++/coverage reports noop.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact [UID:0002U0] coverage row remains in this report; B002 did not edit `by-memory/-coverage-report.md`.
- [x] Remaining unapplied accepted items listed with exact blocker: none. Optional sibling [UID:0002TZ] and broader LightObjImageLib/MapPane supports were already sufficient or out of accepted edit scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0002U0"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002U0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
