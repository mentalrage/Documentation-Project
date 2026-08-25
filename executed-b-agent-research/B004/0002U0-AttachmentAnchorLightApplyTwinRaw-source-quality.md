** TARGET-REPORT-UID:0002U0 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Source-Quality MCP Redo: UID 0002U0 AttachmentAnchorLightApplyTwinRaw

## Assignment

- Agent: B004.
- Assignment id: `B004-redo-attachment-anchor-light-apply-twin-raw-source-quality-0002U0-mcp-20260623`.
- Target: [UID:0002U0] `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`.
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Task type: report-only MCP-backed redo/update. No target/support by-* docs, generated/project-level files, IDA DB, tool state, or `-coverage-report.md` files were edited in this pass.
- Required skill used: project-level `ntk-b-agent-workflow`; read `SKILL.md`, `references/b-agent-research-and-implementation-workflow.md`, and updated `Agent-B004/goal.md`.

## Recommendation Summary

Keep the target at `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000O`, and blank emitter position. Keep the existing first-draft C++ unchanged:

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

The previous B004 report was not acceptable under current rules because it recorded MCP unavailable. This redo removes that acceptance blocker: current IDA MCP session `b880584f` is live and reconfirms the target as a code-shaped raw island with no function object, no incoming xrefs, no direct caller/callee model, and no pointer/literal route to `0x0053c9f0`. The source semantics and C++ wrapper remain valid, but the score should stay capped because the core source-quality blocker is now positively confirmed: no caller, callback, table, vtable, or pointer route to the raw start is known.

## Evidence Sources

Current target and support docs checked:

- `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`
- `by-class/AttachmentAnchorResolver.md`
- `by-file/AttachmentAnchorResolver.md`
- `by-memory/0x0069b450-0x0069b454.g_pLightObjImageLib.md`
- `by-type/by-vtable/LightObjImageLibVtable.md`
- `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`
- `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`
- `by-class/MapPane.md`
- `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`
- `by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md`
- `by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md`
- `by-memory/-coverage-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`
- `project-level/-auto-completion-stats.md`, `project-level/-resolved.md`, and `project-level/-unresolved.md`

Current MCP/PE evidence:

- IDA MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active session: `b880584f`.
- Active IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Executable paths checked: MCP health input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; local PE path `E:\NTK\Resources\NexusTK\NexusTK.exe`.
- PE MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- PE SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## MCP Session And Schema Facts

- `initialize` succeeded; server name `ida-pro-mcp`, protocol version `2025-06-18`.
- `tools/list` succeeded and returned `65` tools.
- `idb_list` returned one active session: `b880584f`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, PID/worker PID `27504`.
- `server_health(database=b880584f)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and strings cache size `2067`.
- Current schemas used in this pass: `lookup_funcs(queries,database)`, `xref_query(queries,database)`, `xrefs_to(addrs,limit,database)`, `callees(addrs,limit,database)`, `decompile(addr,include_addresses,database)`, `disasm(addr,max_instructions,include_total,database)`, `get_bytes(regions,database)`, `get_int(queries,database)`, `find_bytes(patterns,limit,offset,database)`, `entity_query(queries,database)`, and `int_convert(inputs,database)`.
- No MCP calls failed in a way that required pausing. `decompile(0x0053c9f0)` returned a target-specific analysis error because the address is not a modeled function; that is evidence, not MCP unavailability.

## Current Target State

The current target page already has the source-quality wrapper populated and still appears in project stats at `85/87`:

- `project-level/-auto-completion-stats.md` lists [UID:0002U0] as `85 | 87 | 86.0`.
- `auto-generated/-ag-memory-coverage.md` classifies [UID:0002U0] as `coded` through `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp`.
- `auto-generated/NexusTK/map/AttachmentAnchorResolver.cpp` emits the existing `AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY)` wrapper.
- `by-memory/-coverage-report.md` already records the current `85%` row with `g_pLightObjImageLib`, `DrawLightMode2`, `m_lightImageIndex`, `MapPane::m_selectionOverlay`, draft-only C++, no-function/no-xref caps, rejected owners, and final-source confidence limits.
- `project-level/-unresolved.md` still flags `dword_69B450`, `this+0x128`, and `sub_53CA20` references in the target, mostly because raw disassembly/evidence sections preserve IDA aliases. These are cleanup noise, not unresolved behavior, but they are a reason to keep completion below final.

## MCP Function And Range Evidence

`lookup_funcs(database=b880584f)` rechecked the local family:

| Address | MCP result |
| --- | --- |
| `0x0053c6b0` | `Not a function` |
| `0x0053c700` | `sub_53C700`, size `0x102` |
| `0x0053c810` | `sub_53C810`, size `0x11e` |
| `0x0053c930` | `Not a function` |
| `0x0053c980` | `sub_53C980`, size `0x35` |
| `0x0053c9c0` | `sub_53C9C0`, size `0x2b` |
| `0x0053c9f0` | `Not a function` |
| `0x0053ca1a` | `Not a function` |
| `0x0053ca20` | `sub_53CA20`, size `0x94` |
| `0x004dfbb0` | `sub_4DFBB0`, size `0xaa` |
| `0x004dfc60` | `sub_4DFC60`, size `0xaa` |

`int_convert(database=b880584f)` reconfirmed the numeric values used in the report:

| Value | Decimal | Meaning |
| --- | ---: | --- |
| `0x2b` | 43 | target/mode-1 body length (Verified with MCP `int_convert`) |
| `0x5` | 5 | pre/post `0xcc` padding length (Verified with MCP `int_convert`) |
| `0x0c` | 12 | `retn 0Ch`, three explicit stack arguments (Verified with MCP `int_convert`) |
| `0x10` | 16 | LightObjImageLib slot for `DrawLightMode2` (Verified with MCP `int_convert`) |
| `0x128` | 296 | resolver `m_lightImageIndex` offset (Verified with MCP `int_convert`) |
| `0x3e0` | 992 | MapPane `m_selectionOverlay` offset (Verified with MCP `int_convert`) |

## MCP Bytes, Padding, And Raw Body

`get_bytes(database=b880584f)` returned:

| Range | Bytes |
| --- | --- |
| `0x0053c9eb-0x0053c9f0` | `cc cc cc cc cc` |
| `0x0053c9f0-0x0053ca1b` | `55 8b ec 8b 15 50 b4 69 00 8b 45 08 56 ff b1 28 01 00 00 8b 32 8b ca ff 75 10 ff 75 0c ff b0 e0 03 00 00 ff 56 10 5e 5d c2 0c 00` |
| `0x0053ca1b-0x0053ca20` | `cc cc cc cc cc` |
| `0x0053c9c0-0x0053c9eb` | same shape as target, but calls `[esi+0Ch]` instead of `[esi+10h]` |
| `0x0061b760-0x0061b768` | `b0 fb 4d 00 60 fc 4d 00`, proving vtable dwords to `0x004dfbb0` and `0x004dfc60` |
| `0x0069b450-0x0069b454` | `00 00 00 00` in the current IDB read |

`disasm(database=b880584f, addr=0x0053c9f0)` returned `<no function>` but still rendered the raw listing:

```asm
53c9f0  push ebp
53c9f1  mov ebp, esp
53c9f3  mov edx, dword ptr unk_69B450
53c9f9  mov eax, [ebp+8]
53c9fc  push esi
53c9fd  push dword ptr [ecx+128h]
53ca03  mov esi, [edx]
53ca05  mov ecx, edx
53ca07  push dword ptr [ebp+10h]
53ca0a  push dword ptr [ebp+0Ch]
53ca0d  push dword ptr [eax+3E0h]
53ca13  call dword ptr [esi+10h]
53ca16  pop esi
53ca17  pop ebp
53ca18  retn 0Ch
53ca1b  align 10h
53ca20  push ebp ; sub_53CA20
```

This revalidates the exact half-open raw range `0x0053c9f0-0x0053ca1b`: the helper body ends at `retn 0Ch`, then five `0xcc` bytes pad to [UID:0001DJ] `SoundObjectPaneCore` at `0x0053ca20`. There is no interior split point, embedded data, or merge case with the sibling or successor.

## MCP Xref And Route Evidence

Incoming xrefs:

| Target | MCP result |
| --- | --- |
| `0x0053c9f0` | `xref_query` total `0`; `xrefs_to` count `0`; message `No cross-references to this address` |
| `0x0053c9c0` | two code refs: `0x005096cc` in `sub_5094B0` and `0x0050aacf` with no containing function metadata |
| `0x0053c700` | two code refs: `0x005096be` in `sub_5094B0` and `0x0050aabf` |
| `0x0053c810` | ten code refs: `0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, `0x0053c958` |
| `0x0053c930` | zero xrefs |
| `0x004dfbb0` | one data ref at `0x0061b760` |
| `0x004dfc60` | one data ref at `0x0061b764` |
| `0x0061b760` / `0x0061b764` | zero incoming xrefs to the slot dword addresses themselves |
| `0x0069b450` | nineteen data refs, including `0x0053c9c3` in `sub_53C9C0` and raw no-function `0x0053c9f3` |

Outgoing target-body refs:

- `xref_query(from=0x0053c9f3)` returned a data xref from the raw target body to `0x0069b450` and fall-through to `0x0053c9f9`.
- `xref_query(from=0x0053ca13)` returned only code fall-through to `0x0053ca16`; IDA cannot resolve the indirect virtual call to a fixed callee at this raw call instruction.
- The analogous sibling `xref_query(from=0x0053c9c3)` returned the data xref to `0x0069b450`; `xref_query(from=0x0053c9e3)` returned only fall-through to `0x0053c9e6`.

`callees(database=b880584f)` returned:

- `0x0053c9c0`: empty callee list, because the virtual call is indirect.
- `0x0053c9f0`: `No function found`.
- `0x004dfbb0` and `0x004dfc60`: both call `0x004b7c50`, `0x00462e10`, and `@__security_check_cookie@4`.
- `0x0053ca20`: calls `0x005372d0`, consistent with unrelated SoundObjectPane setup.

This is the key score cap: the target has outgoing behavior evidence, but no incoming route evidence and no function object.

## MCP Decompilation Evidence

`decompile(0x0053c9f0)` returned `code:null` with `error:"Decompilation failed at 0x53c9f0"` because the raw start is not a function. This is expected and supports the raw-island classification.

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

`decompile(0x004dfbb0)` and `decompile(0x004dfc60)` show matching `LightObjImageLib` draw functions: both select a `LightInfo` row or fallback, read the generated frame, build source/destination rectangles, and call the shared frame blitter. The mode-1 method calls the blitter with final literal `1`; the mode-2 method calls it with final literal `2`. This confirms the target's `+0x10` slot interpretation as `DrawLightMode2`, while the sibling's `+0x0c` slot is `DrawLightMode1`.

## MCP Literal/Pointer Search Evidence

`find_bytes(database=b880584f)` searched the IDB for direct dword encodings:

| Pattern | Meaning | Result |
| --- | --- | --- |
| `f0 c9 53 00` | VA `0x0053c9f0` | zero matches |
| `f0 c9 13 00` | RVA `0x0013c9f0` | zero matches |
| `f0 bd 13 00` | raw offset `0x0013bdf0` | zero matches |
| `c0 c9 53 00` | VA `0x0053c9c0` | zero matches, expected because sibling reachability is direct `rel32` calls rather than dword pointers |
| `b0 fb 4d 00` | `0x004dfbb0` | one match at `0x0061b760` |
| `60 fc 4d 00` | `0x004dfc60` | one match at `0x0061b764` |
| `50 b4 69 00` | `0x0069b450` | nineteen matches, including `0x0053c9c5` and `0x0053c9f5` operand bytes |

The zero VA/RVA/raw-offset matches for `0x0053c9f0` independently support the no-pointer/no-table route. The vtable/global positive controls prove the search method does find real dword references in the current IDB.

`entity_query(database=b880584f)` for `0x0053c680-0x0053ca40` returned only five modeled functions (`0x0053c700`, `0x0053c810`, `0x0053c980`, `0x0053c9c0`, `0x0053ca20`) and no names in the local address window, so there is no recovered original symbol/name for `0x0053c9f0`. `entity_query` on `0x0061b750-0x0061b768` returned the LightObjImageLib vtable name at `0x0061b754`; `entity_query` on `0x0069b440-0x0069b460` returned no global name, matching the raw IDA alias situation for `dword_69B450`/`unk_69B450`.

## Fresh PE Route Scan

Local PE supplement used `E:\NTK\Resources\NexusTK\NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`, imagebase `0x400000`.

Section map:

| Section | VA range | Raw range |
| --- | --- | --- |
| `.text` | `0x00401000-0x0060c4ac` (`VirtualSize 0x20b4ac`) | raw `0x00000400+0x20b600` |
| `.rdata` | `0x0060d000-0x0066c0be` (`VirtualSize 0x5f0be`) | raw `0x0020ba00+0x5f200` |
| `.data` | `0x0066d000-0x0069ce24` (`VirtualSize 0x2fe24`) | raw `0x0026ac00+0xd800` |

Range hashes:

| Range | Raw offset | Size | SHA-256 |
| --- | ---: | ---: | --- |
| `0x0053c9eb-0x0053c9f0` pre-padding | `0x0013bdeb` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` |
| `0x0053c9f0-0x0053ca1b` target | `0x0013bdf0` | `0x2b` | `0c3c02b5675b5030e3d04c9923bc1e029e238a0f2717ca8b330dcbab0d3fd21b` |
| `0x0053ca1b-0x0053ca20` post-padding | `0x0013be1b` | `0x5` | `992cf51486f901aa1aa7d1f63e18c150c9156166e08e0b9e59cc3faf98177329` |
| `0x0053c9c0-0x0053c9eb` mode-1 sibling | `0x0013bdc0` | `0x2b` | `13c17a8da20ed2414a145ef2f7fb3c912f64384514d363e5d802b2fbfc547b97` |

`.text` control-transfer scan for direct `E8` calls, `E9` jumps, and near conditional `0F 8x` branches:

| Target | Result |
| --- | --- |
| `0x0053c6b0` raw metric sibling | 0 hits |
| `0x0053c700` `ResolveAnchorPoint` | 2 hits: `call@0x005096be`, `call@0x0050aabf` |
| `0x0053c810` `ComputeScreenBounds` | 10 hits: `call@0x0050969d`, `0x0050aa9f`, `0x00537458`, `0x005375af`, `0x0053767c`, `0x0053784c`, `0x005381c6`, `0x005383b1`, `0x005384ec`, `0x0053c958` |
| `0x0053c930` raw screen-bounds sibling | 0 hits |
| `0x0053c9c0` modeled mode-1 sibling | 2 hits: `call@0x005096cc`, `call@0x0050aacf` |
| `0x0053c9f0` target raw mode-2 twin | 0 hits |
| `0x004dfbb0` `DrawLightMode1` | 0 direct control hits, expected because vtable-only |
| `0x004dfc60` `DrawLightMode2` | 0 direct control hits, expected because vtable-only |

Dword literal scan across `.text`, `.rdata`, and `.data`:

| Literal | Result |
| --- | --- |
| VA `0x0053c9f0` | 0 hits |
| RVA `0x0013c9f0` | 0 hits |
| Raw offset `0x0013bdf0` | 0 hits |
| VA `0x0053c9c0` | 0 hits; sibling route is by `rel32` calls |
| VA `0x004dfbb0` | 1 hit at `.rdata@0x0061b760` |
| VA `0x004dfc60` | 1 hit at `.rdata@0x0061b764` |
| VA `0x0069b450` | 19 `.text` hits, including target/sibling operand bytes at `0x0053c9c5` and `0x0053c9f5` |

The PE and MCP results agree: direct callers and vtable pointers are discoverable, but none reach `0x0053c9f0`.

## Relationship To UID 0002TZ

[UID:0002TZ] `AttachmentAnchorApplyLight` remains the caller-backed mode-1 helper:

- MCP models it as `sub_53C9C0`, size `0x2b`.
- MCP xrefs show two direct code refs at `0x005096cc` and `0x0050aacf`.
- MCP disassembly shows the same `g_pLightObjImageLib`, `MapPane +0x3e0`, coordinate, and `this+0x128` argument sources.
- Its virtual call uses `[esi+0Ch]`, and the vtable page resolves slot `+0x0c` to [UID:0002IW] `LightObjImageLibDrawLightMode1`.

[UID:0002U0] is the adjacent mode-2 raw twin:

- MCP does not model it as a function.
- MCP disassembly shows the same wrapper shape but calls `[esi+10h]`.
- Vtable data resolves slot `+0x10` to [UID:0002IX] `LightObjImageLibDrawLightMode2`.
- MCP and PE route scans find no direct caller, table route, or pointer/literal route to the raw start.

Do not merge the pages. They are source-shape siblings with different route quality. The modeled sibling can sit at `88/90`; this raw twin should remain `85/87`.

## Name And Type Revalidation

| Raw evidence | Source-facing conclusion | Strength |
| --- | --- | --- |
| `mov edx, dword ptr unk_69B450` / 19 xrefs to `0x0069b450` | `g_pLightObjImageLib`, type `LightObjImageLib *` | Strong for role and current project name; original symbol spelling still not IDB-proven. |
| `call dword ptr [esi+10h]` and vtable dword `0x0061b764 -> 0x004dfc60` | `LightObjImageLib::DrawLightMode2` | Strong. Mode-2 method has first-draft C++ and vtable-only xref evidence. |
| `push dword ptr [ecx+128h]` / `this[74]` | `AttachmentAnchorResolver::m_lightImageIndex` | Strong for role, medium for original spelling. Same field feeds bounds, brightness metric, mode-1 draw, and mode-2 draw paths. |
| `push dword ptr [eax+3E0h]` | `mapPane->m_selectionOverlay` / `AlphaMaskSurface *targetSurface` | Strong enough for first-draft C++ via MapPane initialization and mode-1 caller support; target alone only proves a target-surface field at offset `0x3e0`. |
| `[ebp+0Ch]`, `[ebp+10h]` | resolved anchor coordinates `centerX`, `centerY` | Strong by sibling caller sequence after `ResolveAnchorPoint`. |
| helper name | `ApplyLightMode2AtAnchor` | Descriptive/inferred. `DrawLightMode2AtAnchor` remains a possible future spelling if the project standardizes on draw terminology. |

## Ownership And Placement Reanalysis

Ranked alternatives:

1. [UID:00000O] `AttachmentAnchorResolver` via [UID:0000HL] `AttachmentAnchorResolver` - keep. Evidence: receiver field `m_lightImageIndex`, adjacency to modeled mode-1 helper, resolver/bounds/metric sibling family, MapPane caller context for mode-1, and synthetic emitter route already in generated `NexusTK/map/AttachmentAnchorResolver.cpp`. The target is consumer-side anchor placement glue, not image-library implementation.
2. Broad [UID:0000HJ] `AttachedObjectPane` source-file fold - keep as source-layout caveat only. Existing class/file docs say original placement may have been a private helper/class in `AttachedObjectPane.cpp`; this does not replace the narrow semantic owner or current emitter route.
3. `LightObjImageLib` - reject as owner. It owns `g_pLightObjImageLib`, vtable data, and `DrawLightMode2`, but this target only prepares a MapPane surface and resolver index before calling the library.
4. `MapPane` - reject as direct owner. MapPane supplies caller context for mode-1 and owns `m_selectionOverlay`, but this target's receiver state is the resolver object and the helper belongs to the anchor-placement family.
5. `LightingObjectPane` - reject. It is a physical predecessor, but `LightingObjectPaneSetIntensity` ends at `0x0053c9b5`, the mode-1 helper starts after padding at `0x0053c9c0`, and the target reads no LightingObjectPane state.
6. `SoundObjectPane` - reject. `SoundObjectPaneCore` begins after five `0xcc` bytes at `0x0053ca20`, has modeled function `sub_53CA20`, vtable writes, and sound/timer/object-pane construction state unrelated to this target.
7. Generic raw/no-owner bucket - reject. Behavior, class field, dependency, sibling relation, and current emitter route are strong enough for a reconstructable AttachmentAnchorResolver child even though reachability is unproven.

## Score And Metadata Recommendation

Keep:

- `COMPLETION:85`
- `CONFIDENCE:87`
- `CANONICAL_OWNER:00000O`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00000O`
- blank `EMITTER_POSITION_OPTIONAL`
- existing first-draft C++ unchanged

Reason not higher:

- Current MCP removes the prior outage caveat, but it confirms the important negative evidence: no function object, no incoming xrefs, no callee model, decompilation failure at the raw start, zero VA/RVA/raw-offset pointer/literal matches, and zero direct PE control-transfer routes to `0x0053c9f0`.
- The original helper spelling is inferred.
- The exact original source-file placement remains unresolved between the current synthetic `AttachmentAnchorResolver.cpp` route and a possible private `AttachedObjectPane.cpp` fold.
- The MapPane `m_selectionOverlay` spelling is current and well-supported, but still a project-doc inferred field name rather than original symbol proof.
- Project-level unresolved scans still see raw aliases in the target evidence prose.

Reason not lower:

- MCP and PE both confirm the exact range, padding, body bytes, argument order, global read, vtable slot, mode-2 callee identity, sibling relation, and current wrapper source shape.
- The target has a valid owner/emitter route and already passes the current code-entry gate for draft C++.
- The no-route state is a confidence cap, not proof that the helper is non-source or should be removed.

## C++ Readiness Recommendation

Keep the formal C++ block. The source-shaped wrapper is preferable to decompiler-shaped pointer arithmetic because all user-visible semantics are resolved:

- `g_pLightObjImageLib` is the source-facing singleton name.
- `DrawLightMode2` is the resolved vtable `+0x10` method.
- `MapPane *mapPane` and `mapPane->m_selectionOverlay` are supported by MapPane initialization and the mode-1 caller path.
- `m_lightImageIndex` is supported by bounds, metric, mode-1 draw, and mode-2 draw paths.
- `centerX` and `centerY` are supported by the mode-1 caller sequence after anchor resolution.

The block should stay draft-only in target prose. If a future project-wide policy forbids formal code for raw no-xref helpers, the correct fallback would be to replace only the formal block with a comment/no-code marker while preserving the behavior evidence. I do not recommend that change now because the target already emits through [UID:00000O] and the code is source-shaped.

## Target And Support Changes Needed If Accepted

Required target sync:

- `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`
- Keep metadata and C++ unchanged.
- Add a dated `2026-06-23 B004 MCP-backed redo` evidence section with endpoint/session/IDB/health, PE hash/section map, `lookup_funcs` function/no-function results, zero `xrefs_to`/`xref_query` refs to `0x0053c9f0`, sibling/vtable/global positive controls, `get_bytes` body/padding proof, `disasm` raw listing proof, `decompile(0x0053c9f0)` failure as no-function evidence, `find_bytes` zero VA/RVA/raw-offset matches, PE route scan zero direct control hits, and current score-cap rationale.
- Supersede any wording that implies the current cap is due to MCP outage. The current cap is due to confirmed no-route/raw-island state and unresolved original helper/source-layout names.

Required support sync:

- `by-class/AttachmentAnchorResolver.md`
- `by-file/AttachmentAnchorResolver.md`
- Add or update a dated note that B004's `b880584f` MCP redo now reconfirms the raw `0x0053c9f0` no-function/no-xref/no-pointer route while preserving `ApplyLightMode2AtAnchor` as draft-only source guidance. This should supersede older B014 wording that could not add fresh MCP route evidence.

Optional/no-op support checks:

- `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`: likely no edit needed because it already carries the mode-1/mode-2 relationship and route difference at strong detail. A callback may add one sentence only if the supervisor wants every sibling page to cite the `b880584f` redo.
- `by-class/MapPane.md`, `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`, `by-type/by-vtable/LightObjImageLibVtable.md`, `by-memory/0x0061b750-0x0061b768.LightObjImageLibVtableData.md`, and `by-memory/0x004dfc60-0x004dfd0a.LightObjImageLibDrawLightMode2.md`: no required edits; existing facts already support `m_selectionOverlay`, vtable `+0x10`, and `DrawLightMode2`.

Do not edit any `-coverage-report.md` file during implementation; use the supervisor-owned text below.

## Exact Supervisor-Owned Coverage Text

File/placement: `by-memory/-coverage-report.md`, replace the current [UID:0002U0] row under the local `0x0053c9c0`/`0x0053ca20` neighborhood.

```text
    - [UID:0002U0][0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw](by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md) 0x0053c9f0-0x0053ca1b | raw helper method | AttachmentAnchorLightApplyTwinRaw : reconstructable : 85% : strong : Attached under `AttachmentAnchorResolver`; source-quality reanalysis resolves `dword_69B450`/`unk_69B450` as `g_pLightObjImageLib`, virtual slot `+0x10` as `LightObjImageLib::DrawLightMode2`, `this+0x128` as resolver `m_lightImageIndex`, and `arg0+0x3e0` as current `MapPane::m_selectionOverlay`; B004 MCP-backed redo on 2026-06-23 using IDA MCP session `b880584f` reconfirms the exact `0x0053c9f0-0x0053ca1b` raw body, five-byte `0xcc` padding before and after, no modeled function/decompile at the raw start, zero incoming xrefs or VA/RVA/raw-offset pointer hits to `0x0053c9f0`, zero PE direct control-transfer routes, positive controls for the modeled mode-1 sibling callers and LightObjImageLib vtable dwords, and keeps draft-only `ApplyLightMode2AtAnchor` C++ while preserving final-source confidence caps for reachability, original helper spelling, MapPane field spelling, and original source-file folding.
```

Reason B004 must not apply it directly: B-agent rules reserve `-coverage-report.md` edits for supervisor-owned application unless an explicit current override names the file and permits the edit. No such override exists.

## Validators Expected After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for each changed by-* doc:

> Executable block R001 was removed from this report and preserved verbatim in [0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md](0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If an optional sibling/support page is edited, run the same scoped validator for that page. No validators were run in this report-only pass because no by-* docs were edited.

## Changed Files In This Report Pass

- Modified: `tools/leaser/Agents/Agent-B004/research/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md`.
- Created: none.
- Modified by-* docs: none.
- Modified generated/project-level files: none.
- Modified `-coverage-report.md` files: none.
- IDA DB/tool state edits: none.
- Leases used: none; own research report edits do not require a lease.

## Blockers

No MCP blocker remains. MCP session `b880584f` was live for this redo. The remaining blockers are target/source-quality blockers only:

- no function object at `0x0053c9f0`;
- no incoming xrefs or direct code/data/pointer route to the raw start;
- decompilation fails at `0x0053c9f0` because there is no function object;
- original helper spelling is not symbol-proven;
- original source placement remains unresolved between the current synthetic `AttachmentAnchorResolver.cpp` emitter route and possible private `AttachedObjectPane.cpp` placement.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor callback accepted this report for assignment `B004-implement-attachment-anchor-light-apply-twin-raw-source-quality-0002U0-mcp-20260623`.
- [x] Target/support docs to update: target `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`; required support sync `by-class/AttachmentAnchorResolver.md` and `by-file/AttachmentAnchorResolver.md`; optional/no-op support check `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md`. Proof: three required docs edited; optional sibling left unchanged because it already records the mode-1/mode-2 relationship, `g_pLightObjImageLib`, `DrawLightMode2`, `m_selectionOverlay`, `m_lightImageIndex`, and raw no-function/no-route cap at same-or-greater detail for its sibling role.
- [x] Current target state and actual evidence checked recorded: target remains `85/87` with first-draft C++ present; this redo adds live MCP session `b880584f`, tool/schema facts, function/no-function checks, xrefs, bytes, decompile/disasm, literal search, PE route scan, and positive controls. Proof: target now has `## 2026-06-23 B004 MCP-Backed Redo Evidence` plus `## 2026-06-23 B004 PE Route-Scan Evidence`.
- [x] Metadata/score changes to apply: keep target `COMPLETION:85`, `CONFIDENCE:87`; no owner/emitter/reconstructable/C++ metadata changes. Proof: target header still has `COMPLETION:85`, `CONFIDENCE:87`; C++ block unchanged.
- [x] Owner/emitter/reconstructable changes to apply: keep `CANONICAL_OWNER:00000O`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000O`, and blank emitter position. Proof: target header unchanged for those fields.
- [x] Split/rename/new-child changes to apply: none; keep exact half-open range `0x0053c9f0-0x0053ca1b`, five-byte pre/post padding, and [UID:0001DJ] successor at `0x0053ca20`. Proof: target boundary notes and B004 MCP/PE sections document exact body/padding/successor; no new/split files created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: preserve current synthetic `AttachmentAnchorResolver.cpp` route while documenting possible private `AttachedObjectPane.cpp` source-layout caveat; no IDA DB edits recommended. Proof: target, class, and file pages keep the synthetic route and private `AttachedObjectPane.cpp` caveat; no IDA/tool state edits were made.
- [x] First-draft C++ or no-code proof to apply: keep existing source-shaped `AttachmentAnchorResolver::ApplyLightMode2AtAnchor(MapPane *mapPane, int centerX, int centerY)` block unchanged; do not replace it with raw pointer/decompiler-shaped code. Proof: target formal block still contains the same source-shaped wrapper and support docs describe it as draft-only child C++.
- [x] Exact target/support doc facts to incorporate at report-level detail: MCP endpoint/session/health/schema facts, lookup/no-function evidence, zero xrefs to `0x0053c9f0`, raw disassembly, decompile failure at raw start, sibling decompile/disassembly, vtable/get_int/get_bytes proof, `find_bytes` zero VA/RVA/raw-offset pointer hits, PE control-transfer route scan, positive controls for mode-1 sibling and vtable dwords, owner rejections, generated/project-state caveats, and revised score-cap rationale. Proof: target has the full detailed sections; class and file support pages have dated B004 `b880584f` route/no-route summaries and revised score-cap text.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: supersede prior B014/B004 live-MCP-unavailable wording; preserve no-function/no-xref/no-pointer negative evidence, rejected LightObjImageLib/LightingObjectPane/SoundObjectPane/MapPane/no-owner alternatives, raw alias cleanup caveats, and original source spelling/layout uncertainty. Proof: target and support docs mark the old MCP-unavailable caveat as superseded and keep rejected alternatives and open original-spelling/source-layout caps.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: `source-3/simroot_v2`/generated output remains lead material only and does not override MCP/by-* evidence; no current Wave2/Wave3 instruction changes scope. Proof: no Wave2/Wave3 material was used as implementation evidence.
- [x] Open questions to close or document as evidence-backed unresolved: original helper spelling, original source-file/private-section placement, MapPane `m_selectionOverlay` original spelling, and any future caller/callback/table route remain unresolved score caps. Proof: target/source-quality and score-rationale sections plus class/file support sections preserve these as the active caps.
- [x] Validators to run after accepted implementation: run scoped validators listed in `Validators Expected After Implementation` for every changed by-* doc. Proof: all three required validator commands ran; each exited `0` with `ok: 1`.
- [x] Supervisor-owned coverage-report/tracker text to apply: replace the [UID:0002U0] row in `by-memory/-coverage-report.md` with the exact row supplied above; no no-owner tracker update needed. Proof: exact row remains in this report; no `-coverage-report.md` file was edited by B004.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: supervisor callback accepted this report and named required docs `by-memory/0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md`, `by-class/AttachmentAnchorResolver.md`, and `by-file/AttachmentAnchorResolver.md`.
- [x] Leases taken and released for edited by-* docs: `python .\tools\leaser\leaser.py B004 lease by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md by-class\AttachmentAnchorResolver.md by-file\AttachmentAnchorResolver.md` returned `Success` for all three. Release command returned `Rejected[No active lease]` for all three, and `tools/leaser/Agents/current_leases.md` then reported `No active leases`.
- [x] All accepted target/support doc details incorporated at report-level detail: target now has B004 MCP/PE detailed evidence; class and file docs have dated B004 support sync with no-route proof, positive controls, draft-only source guidance, and source-placement caveats.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target metadata stayed `85/87`, owner/emitter stayed `00000O`, reconstructable stayed `TRUE`, emitter position stayed blank, no split/rename/new child was made, and first-draft C++ remained unchanged because the callback explicitly required no metadata/C++ change.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: old B014 fresh-MCP-unavailable wording is retained only as superseded history; rejected `LightObjImageLib`, `LightingObjectPane`, `SoundObjectPane`, `MapPane`, broad `AttachedObjectPane`, and no-owner/non-emitting alternatives are preserved; no-function/no-xref/no-pointer/no-route negative evidence remains the active cap.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: original helper spelling, original MapPane `m_selectionOverlay` spelling, source-file/private-section placement, and future caller/callback/table route remain unresolved and are named as score caps.
- [x] Validators run and results recorded:
  - `python .\tools\validator.py --mode file --file by-memory\0x0053c9f0-0x0053ca1b.AttachmentAnchorLightApplyTwinRaw.md --apply --queue-timeout 240` exited `0`, `ok: 1`; side effects included `reference_index_add 0000L3`, stats row updates for `0002U0`, projected stats update, and validator registry rebuild.
  - `python .\tools\validator.py --mode file --file by-class\AttachmentAnchorResolver.md --apply --queue-timeout 240` exited `0`, `ok: 1`; side effects included `stats_incremental_noop 00000O`, projected stats update, and validator registry rebuild.
  - `python .\tools\validator.py --mode file --file by-file\AttachmentAnchorResolver.md --apply --queue-timeout 240` exited `0`, `ok: 1`; side effects included `uid_link_insert 0002U0`, `stats_incremental_noop 0000HL`, projected stats update, and validator registry rebuild.
- [x] Supervisor-owned coverage-report/tracker text supplied or confirmed unchanged: exact replacement row remains under `## Exact Supervisor-Owned Coverage Text`; B004 did not edit `by-memory/-coverage-report.md` or any `-coverage-report.md`.
- [x] Remaining unapplied accepted items listed with exact blocker: none. Optional sibling `by-memory/0x0053c9c0-0x0053c9eb.AttachmentAnchorApplyLight.md` was not edited because it already had adequate sibling relationship/no-route text and was optional-only in the callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0002U0"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002U0-AttachmentAnchorLightApplyTwinRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002U0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
