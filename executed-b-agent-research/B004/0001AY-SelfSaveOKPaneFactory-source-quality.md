** TARGET-REPORT-UID:0001AY **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Research Report - [UID:0001AY] SelfSaveOKPaneFactory Source Quality

## Assignment

- Agent: B004
- Assignment ID: `B004-goal2-self-save-ok-pane-factory-source-quality-0001AY-20260623`
- Target: [UID:0001AY] `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md`
- Starting score: `COMPLETION:86`, `CONFIDENCE:86`
- Task type: report-only source-quality research
- Report path: `tools/leaser/Agents/Agent-B004/research/0001AY-SelfSaveOKPaneFactory-source-quality.md`
- Date: 2026-06-23

This pass did not edit by-* documentation, generated files, project-level files, IDA state, tool state, or any `-coverage-report.md` file.

## Executive Recommendation

The target should remain owned and emitted by [UID:0000NN] `SelfSaveOKPane`, with a source-quality increase to `COMPLETION:89`, `CONFIDENCE:89`. The current `CANONICAL_OWNER:0000NN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NN`, and blank emitter position should stay unchanged.

The target should receive first-draft C++ rather than an exact no-code proof. The current code-entry gate is satisfied: the page is reconstructable, has a nonblank emitter, is above the 85 average threshold, and is not a no-owner dead-end. Fresh evidence still proves no ordinary route to `0x00513800`, so the C++ must stay source-shaped and cautious: a retained file-local creation helper that constructs a `SelfSaveOKPane` and returns success, not a packet dispatcher implementation and not generated/IDA-shaped manual vtable writes.

Recommended first-draft C++:

```cpp
static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)
{
    (void)unusedPacket;

    SelfSaveOKPane *pane = new SelfSaveOKPane;
    (void)pane;

    return true;
}
```

The score should remain capped below 90 because IDA MCP and the supplemental raw PE scan still find zero caller, xref, table, pointer, VA, RVA, or raw-offset route hits to the helper entry; the original source spelling and parameter type remain inferred; and `0x00513920+` is a separate no-route successor that is still not modeled as its own by-memory page.

## Current Target State

Current target metadata:

- `UID:0001AY`
- `COMPLETION:86`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000NN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000NN`
- blank emitter position
- blank first-draft C++ block

The page currently describes `0x00513800-0x00513920` as IDA function `sub_513800`, size `0x120` / 288 bytes (Verified with `int_convert.py`). It identifies the helper as a standalone SelfSaveOKPane factory-like routine that allocates `0x174` / 372 bytes (Verified with `int_convert.py`), runs the same construction sequence seen in the standalone constructor and in MapPane packet case `0x21`, installs the three SelfSaveOKPane vtables, loads localized string id `0x3d` / 61 (Verified with `int_convert.py`), attaches the pane to the screen/render layer globals, schedules a 1000 ms timer, and returns success.

The current page correctly warns that there are no direct code xrefs and that the original source role is unresolved. The main stale part is the blanket "Do not emit C++ yet" posture. Under the current code-entry gate and the close `SelfSaveInputPaneFactory` precedent, the route gap should cap confidence but should not block a source-shaped first draft.

## Evidence Checked

### Target and Support Documentation

- `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md`
- `by-class/SelfSaveOKPane.md`
- `by-file/SelfSaveOKPane.md`
- `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md`
- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- `by-file/MapPane.md`
- `by-type/by-enum/MapServerPacketOpcode.md`
- `by-memory/0x0061e7a0-0x0061e854.SelfSaveOKPaneVtableData.md`
- `by-type/by-vtable/SelfSaveOKPane_vtables.md`
- `by-memory/0x0061ea8c-0x0061eaa8.SelfSaveOKPaneSpacerString.md`
- `by-project-structure/proposed-source-tree.md`
- `by-memory/-coverage-report.md` read only for supervisor-owned coverage text
- `auto-generated/-ag-memory-coverage.md` read only for generated status
- `auto-generated/NexusTK/ui/dialogs/SelfSaveOKPane.cpp` read only for generated emitter context

### Prior Report Evidence Rechecked

- B001 MapPane packet split audit for [UID:0001AW], including the recommendation to keep [UID:0001AY] under [UID:0000NN] and not move it to MapPane.
- B001 batch route scans showing zero raw PE route hits for `0x00513800`.
- B001 raw-start reports around `0x00513680`, `0x00513780`, `0x005137d0`, and `0x00513800`, which support the local no-route island pattern but do not prove the helper dead.
- `by-memory/0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`, used as current source-quality precedent for a retained no-ordinary-route pane factory that can still receive source-shaped first-draft C++.

### IDA MCP Evidence

IDA MCP was used after the supervisor restored the mandatory endpoint.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active accepted session used for final evidence: `0b5e057e`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- MCP-reported input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Image base: `0x400000`
- Server health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, string cache size `2067`
- Stale/discarded sessions: `15216dde` and `0f0b38fb`. Both were superseded by supervisor MCP session updates; all final MCP evidence in this report was rerun against `0b5e057e` for the same `.i64` input.
- Tools used: `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `disasm`, `xrefs_to`, `search_text`.

No IDA database changes, renames, type edits, comments, patches, or saves were made. MCP was used for inspection only.

MCP function/range results:

| Query | MCP result |
| --- | --- |
| `0x00513800` | `sub_513800`, size `0x120` |
| `0x00513920` | not a function |
| `0x005147d0` | `sub_5147D0`, size `0x106` |
| `0x005148e0` | `sub_5148E0`, size `0x34` |
| `0x00508511` | inside `sub_507C90`, size `0x1176` |

MCP decompilation and compact analysis for `sub_513800`:

- Prototype: `char __stdcall(int)`
- Size: 288 bytes
- Callers: empty
- Xrefs to function entry: empty
- Callees: `sub_4F4AA0`, `sub_595390`, `sub_58E270`, `sub_4F0350`, `sub_4B7C50`, `sub_55EE10`, `sub_5975E0`, and `@__security_check_cookie@4`
- Decompiler confirms allocation of 372 bytes, null-check, `sub_595390(..., 408, 12, 0, 143, 1, 0)`, vtable stores to `SelfSaveOKPane::vftable` variants, two spacer appends, localized string id `61`, rect `(14,456)-(422,468)`, attach through `dword_67A740` and `unk_69B368`, timer scheduling through `this + 41`, and unconditional `return 1`.

MCP disassembly for `sub_513800` confirms:

- `0x0051382a`: `push 174h`
- `0x0051382f`: `call sub_4F4AA0`
- `0x0051385f`: `call sub_595390`
- `0x00513866`: `push offset asc_61EA8C`
- `0x00513871`: store `??_7SelfSaveOKPane@@6B@`
- `0x00513877`: store `??_7SelfSaveOKPane@@6B@_0`
- `0x00513881`: store `??_7SelfSaveOKPane@@6B@_1`
- `0x00513890`: load `dword_67A750`
- `0x00513898`: `push 3Dh`
- `0x0051389a`: `call sub_4F0350`
- `0x005138a9`: second `push offset asc_61EA8C`
- `0x005138b5`/`0x005138ba`/`0x005138bf`/`0x005138c7`: rect immediates `1D4h`, `1A6h`, `1C8h`, `0Eh`
- `0x005138d7`: `push dword ptr unk_69B368`
- `0x005138dd`: `push dword_67A740`
- `0x005138e6`: `call sub_55EE10`
- `0x005138ef`: `push 3E8h`
- `0x005138f6`: `lea ecx, [edi+0A4h]`
- `0x005138fc`: `call sub_5975E0`
- `0x0051391d`: `retn 4`

MCP xref/caller negative results:

| Address | MCP xref result |
| --- | --- |
| `0x00513800` | zero xrefs; no callers in `analyze_function` |
| `0x00513920` | zero xrefs; not an IDA function |
| `0x005147d0` | zero xrefs; no callers in `analyze_function` |
| `0x005148e0` | one data xref from `0x0061e850`, the SelfSaveOKPane timer vtable slot |

MCP positive vtable/string controls:

| Target | MCP xrefs |
| --- | --- |
| `0x0061e7a4` | `0x0050855b` in `sub_507C90`, `0x00513871` in `sub_513800`, `0x00514829` in `sub_5147D0` |
| `0x0061e81c` | `0x00508561` in `sub_507C90`, `0x00513877` in `sub_513800`, `0x0051482f` in `sub_5147D0` |
| `0x0061e84c` | `0x0050856b` in `sub_507C90`, `0x00513881` in `sub_513800`, `0x00514839` in `sub_5147D0` |
| `0x0061ea8c` | `0x00508550`, `0x00508593`, `0x00513866`, `0x005138a9`, `0x0051481b`, `0x00514861` |

MCP constructor/timer relationship:

- `sub_5147D0` prototype is `_DWORD *__thiscall(_DWORD *this)`, size 262, with no callers and no entry xrefs. Its decompilation repeats the same `sub_595390(..., 408, 12, 0, 143, 1, 0)`, SelfSaveOKPane vtable stores, two spacer appends, localized string id `61`, rect `(14,456)-(422,468)`, screen/render attach, and 1000 ms timer setup, then returns `this`.
- `sub_5148E0` prototype is `char __thiscall(_DWORD *this, int, int, int)`, size 52. Its only entry xref is data at `0x0061e850`, confirming the timer-handler vtable slot route.

MCP MapPane packet case relationship:

- Scoped `search_text` over `0x00508500-0x005085f0` found `0x00508511 push 174h` with IDA comment `jumptable 00507CE2 case 33`; `0x21` equals decimal `33` (Verified with `int_convert.py`).
- The same scoped search found `0x00508550` and `0x00508593` spacer refs, vtable stores at `0x0050855b`, `0x00508561`, and `0x0050856b`, `0x00508582 push 3Dh`, and `0x005085d9 push 3E8h`.
- This confirms the inline MapPane packet case `0x21` body is the live sibling construction route, not a caller route to [UID:0001AY].

MCP boundary note:

- `search_text` over `0x00513910-0x00513945` found `0x0051391d retn 4` inside `sub_513800`, then `0x00513920 push ebp`, `0x00513923 sub esp, 14h`, and `0x00513936 call sub_575480` outside any named function.
- Combined with `lookup_funcs` reporting `0x00513920` is not a function and `xrefs_to` reporting zero xrefs to `0x00513920`, the successor remains a separate unmodeled no-route candidate and should not be absorbed into [UID:0001AY].

## Fresh PE Route-Scan Evidence

Executable provenance:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`

Local PE section map:

| Section | VA range | RVA/size | Raw/size | Virtual size | Characteristics |
| --- | --- | --- | --- | --- | --- |
| `.text` | `0x00401000-0x0060c600` | `0x00001000+0x20b600` | `0x00000400+0x20b600` | `0x20b4ac` | `0x60000020` |
| `.rdata` | `0x0060d000-0x0066c200` | `0x0020d000+0x5f200` | `0x0020ba00+0x5f200` | `0x5f0be` | `0x40000040` |
| `.data` | `0x0066d000-0x0069ce24` | `0x0026d000+0x2fe24` | `0x0026ac00+0xd800` | `0x2fe24` | `0xc0000040` |

Route scan method:

- `.text` scan for `E8` call rel32, `E9` jump rel32, and `0F 8x` near conditional rel32 targets.
- Dword literal scan across `.text`, `.rdata`, and `.data` for VA, RVA, and raw-offset encodings.
- Positive controls were included so a zero result for `0x00513800` is meaningful rather than a broken scanner result.

Branch route results:

| Target | Result |
| --- | --- |
| `0x005104d0` | positive control: `call@0x00507f10` |
| `0x00510960` | positive control: `call@0x00507ffa` |
| `0x00511440` | positive control: `call@0x0050800b` |
| `0x00511710` | positive control: `call@0x0050801c` |
| `0x00511c90` | positive control: `call@0x005082f6`, `call@0x00512c04` |
| `0x00511db0` | positive control: `call@0x00508307` |
| `0x00512960` | positive control: `call@0x0050837e` |
| `0x00512d60` | positive control: `call@0x0050838f` |
| `0x00512f20` | positive control: `call@0x005083a0` |
| `0x00513310` | positive control: `call@0x005083b1` |
| `0x00513680` | zero hits |
| `0x00513780` | zero hits |
| `0x005137d0` | zero hits |
| `0x00513800` | zero hits |
| `0x00513920` | zero hits |
| `0x00514380` | zero hits |
| `0x005147d0` | zero hits |
| `0x005148e0` | zero branch hits; the timer handler has a positive `.rdata` vtable slot control below |

Dword literal route results:

| Searched value | Result |
| --- | --- |
| `0x00513800` VA | zero hits |
| `0x00113800` RVA for `0x00513800` | zero hits |
| `0x00112c00` raw offset for `0x00513800` | zero hits |
| `0x005147d0` VA | zero hits |
| `0x005148e0` VA | positive control: `.rdata@VA0x0061e850/raw0x0021d250` |
| `0x0061e7a4` primary vtable base | positive controls: `.text@0x0050855d`, `.text@0x00513873`, `.text@0x0051482b` |
| `0x0061e81c` secondary vtable base | positive controls: `.text@0x00508567`, `.text@0x0051387d`, `.text@0x00514835` |
| `0x0061e84c` timer vtable base | positive controls: `.text@0x00508571`, `.text@0x00513887`, `.text@0x0051483f` |
| `0x0061ea8c` spacer string | positive controls: `.text@0x00508551`, `.text@0x00508594`, `.text@0x00513867`, `.text@0x005138aa`, `.text@0x0051481c`, `.text@0x00514862` |

Conclusion from the fresh scan: there is still no PE branch route, pointer route, table route, VA literal route, RVA route, or raw-offset route to `0x00513800`. The helper is not reachable through an ordinary direct xref currently visible in the executable. This does not make the code non-source, because the body is coherent, modeled as an IDA function, emits under a valid file owner, and matches a known retained factory pattern elsewhere in the project.

## Function Behavior Verification

Fresh Capstone disassembly confirms the target range is a complete modeled routine:

- Entry: `0x00513800`
- End: `0x00513920`
- Size: `0x120` / 288 bytes (Verified with `int_convert.py`)
- Calling convention shape: callee pops one stack argument with `ret 4`
- Return behavior: success byte in `AL`; both allocation-success and allocation-null paths reach `mov al, 1`
- Allocation: `push 0x174`; `call 0x004f4aa0`
- Allocation size: `0x174` / 372 bytes (Verified with `int_convert.py`)
- TextBoxPane construction call: `call 0x00595390`
- Constructor-like arguments include width/height/count-style constants already reflected in the target page.
- Spacer string reference: `0x0061ea8c`, twice in this target.
- Primary vtable store: `0x00513871`, value `0x0061e7a4`
- Secondary vtable store: `0x00513877`, value `0x0061e81c`, object offset `+0xa0` / 160 (Verified with `int_convert.py`)
- Timer vtable store: `0x00513881`, value `0x0061e84c`, object offset `+0xa4` / 164 (Verified with `int_convert.py`)
- Localized string lookup owner/global: loads manager from `0x0067a750`
- Localized string id: `0x3d` / 61 (Verified with `int_convert.py`)
- Frame rectangle immediate sequence: `0x0e`, `0x1c8`, `0x1a6`, `0x1d4`
- Frame rectangle: `(14,456)-(422,468)`; `0x1c8` / 456, `0x1a6` / 422, and `0x1d4` / 468 are Verified with `int_convert.py`
- Attach path: pushes globals at `0x0069b368` and `0x0067a740`, then calls `0x0055ee10`
- Timer scheduling: `lea ecx,[edi+0xa4]`; pushes `0`, `0x3e8`, `0`, `0`, then calls `0x005975e0`
- Timer delay: `0x3e8` / 1000 ms (Verified with `int_convert.py`)
- Cookie/check epilogue: calls `0x005c772f`, restores frame, and returns with `ret 4`

The routine does not consume the incoming stack argument. That supports a retained callback/helper signature with one unused parameter, not a class member method and not the standalone constructor itself.

## Relationship to Constructor and MapPane Packet Case 0x21

The target body is the third occurrence of the same SelfSaveOKPane construction pattern:

1. Inline MapPane packet case `0x21` block around `0x00508511`, within [UID:0001AW] / [UID:00007Q]. This is the known live packet-dispatch route. It allocates `0x174` bytes, installs the same three vtables, uses spacer `0x0061ea8c`, localized string id `61`, the same screen rectangle, the same attach globals, and the same 1000 ms timer.
2. Factory-like target [UID:0001AY] at `0x00513800-0x00513920`. This pass confirms the same construction details but no ordinary route to its entry.
3. Standalone constructor [UID:0001B0] at `0x005147d0-0x005148d5`, which receives `this` in `ECX`, performs the same construction body, and returns `this`.

The best source explanation is that the original source had a small creation/helper entry whose body was compiled with the `SelfSaveOKPane` constructor inlined. The helper's source can therefore be expressed as `new SelfSaveOKPane; return true;` while constructor-specific details stay in [UID:0001B0] / [UID:0000CX]. The target page should still preserve the binary-level evidence for vtable stores, string id, rectangle, attach path, and timer schedule so the source-level simplification remains auditable.

## Range, Split, and Padding Analysis

The current range is exact and should not be split or expanded.

Predecessor boundary:

- Bytes before entry include the previous routine's `ret 4` at `0x005137fc-0x005137fe`.
- A one-byte `0xcc` pad sits at `0x005137ff`.
- Target prologue starts cleanly at `0x00513800` with `55 8b ec`.

Target end:

- The target epilogue ends with `ret 4` at `0x0051391d`.
- The covered range ends at `0x00513920`.

Successor boundary:

- `0x00513920` begins with a separate prologue-shaped sequence: `55 8b ec 83 ec 14 ...`.
- Fresh Capstone decoding from `0x00513920` shows a separate routine-shaped body that calls `0x00575480`, `0x00575380`, `0x005753a0`, and `0x00574bb0`, then performs a cookie check and returns with `ret 4` near `0x005139a1`.
- Fresh PE route scan found zero branch or pointer hits to `0x00513920`.
- No by-memory page for `0x00513920` was found in the current documentation scan.

Recommendation: do not absorb `0x00513920+` into [UID:0001AY]. It should remain an unresolved no-route successor candidate for separate future triage. The unmodeled successor is a confidence cap, not a reason to change [UID:0001AY]'s end boundary.

## Direct Caller, Xref, Pointer, and Table Route Recheck

Rechecked direct route evidence:

- No `E8` call rel32 to `0x00513800`.
- No `E9` jump rel32 to `0x00513800`.
- No `0F 8x` near conditional branch to `0x00513800`.
- No VA dword hit for `0x00513800`.
- No RVA dword hit for `0x00113800`.
- No raw-offset dword hit for `0x00112c00`.
- Existing by-* documentation also reports no direct callers/xrefs.

Positive controls validate the negative result:

- Multiple MapPane packet target calls around the same dispatcher region were found by the same branch-route scanner.
- The timer handler pointer `0x005148e0` was found in `.rdata` at SelfSaveOKPane's timer vtable slot.
- SelfSaveOKPane vtable base dwords were found at the inline MapPane block, this target, and the standalone constructor.
- The spacer string address was found at the inline MapPane block, this target, and the standalone constructor.

Conclusion: the target is source-like and reconstructable, but liveness remains inferred from coherent retained code and owner evidence rather than a currently visible caller.

## Heuristic and Inference Reanalysis

### Retained/Dead Factory

The no-route evidence leaves a possible retained-dead helper interpretation. However, the helper is not garbage-like:

- It is a clean IDA function with prologue, cookie setup, coherent constructor body, cookie check, and `ret 4`.
- It uses the same live vtable bases and spacer string as the inline packet case and constructor.
- It allocates the exact class size and schedules the exact class timer.
- It returns the callback-friendly success value `true`.

Verdict: retained no-ordinary-route helper is plausible and should cap the score, but it should remain emitted under `SelfSaveOKPane`.

### Packet Callback

The `ret 4` shape and unused argument are compatible with a packet callback or dispatch-table handler. The fresh pointer scan did not find a function-pointer table entry or dword route to `0x00513800`, and the live MapPane packet case `0x21` contains an inline construction block rather than a call to this helper.

Verdict: possible original source role, but not proven enough to rename as a packet handler or move under MapPane.

### Alternate Constructor

The target inlines the class construction body, but it is not an alternate constructor:

- It allocates memory before construction.
- It is not `thiscall`; it uses a callee-popped stack argument and does not consume `ECX` as `this`.
- It returns a success byte, not `this`.

Verdict: reject alternate-constructor classification. The standalone constructor [UID:0001B0] remains the class constructor.

### Source-Local Creation Helper

This is the best fit:

- It constructs exactly one `SelfSaveOKPane`.
- Its source-facing shape can be a small file-local helper with an unused callback argument.
- It belongs naturally in `NexusTK/ui/dialogs/SelfSaveOKPane.cpp`.
- It matches the accepted `SelfSaveInputPaneFactory` pattern: a no-ordinary-route factory/helper can still receive a concise source-level draft when constructor details are class-owned and the helper is reconstructable.

Verdict: classify as a source-local retained creation helper, likely named `CreateSelfSaveOKPane` or similar.

## Ranked Ownership and Source Placement Alternatives

1. [UID:0000NN] `SelfSaveOKPane` file owner - keep.
   The function body only creates and initializes SelfSaveOKPane. All specific evidence points to this pane: allocation size, vtable stores, spacer string, localized string id `61`, rectangle, attach path, and timer setup. This owner already owns the file-level source placement and matches generated output routing.

2. [UID:0000CX] `SelfSaveOKPane` class owner - related but not canonical for this page.
   The target uses class-owned vtables and constructor behavior, but the routine itself is a free/static helper rather than a `thiscall` method. The class page should cross-reference it, but file-level [UID:0000NN] is the better canonical owner/emitter.

3. [UID:00007Q] `MapPane` - reject as canonical owner.
   MapPane owns the packet parser and the live inline case `0x21`, but this target has no branch or pointer route from MapPane. Moving the helper to MapPane would confuse packet-routing ownership with the constructed UI class.

4. [UID:0000L3] packet opcode/dispatcher ownership - reject.
   The opcode enum and dispatcher documentation explain why the inline `0x21` construction exists. They do not prove a route to this helper, and the helper has no packet parsing behavior.

5. No-owner/non-emitting - reject.
   The target is reconstructable, source-like, and already has a coherent owner/emitter. The lack of direct route should cap confidence, not remove ownership.

## Source-Facing Name and Role

Recommended source-facing role: file-local retained creation helper for SelfSaveOKPane.

Recommended source-facing name: `CreateSelfSaveOKPane`.

Rejected names/roles:

- `SelfSaveOKPaneFactory`: useful documentation slug, but it reads like a generated documentation label rather than a likely source function name.
- `HandleSelfSaveOKPacket`: overstates packet-handler proof; the function does not parse packet data and has no current dispatch-table route.
- `MapPaneSelfSaveOK`: overstates MapPane ownership.
- `SelfSaveOKPane::SelfSaveOKPane`: wrong calling convention and return behavior.
- `ShowSelfSaveOKPane` / `OpenSelfSaveOKPane`: possible, because the constructor attaches and schedules a timer, but less directly supported than `CreateSelfSaveOKPane` and easier to overread as a user-facing command.

Recommended prototype caveat: the binary proves a one-argument `ret 4` helper whose parameter is unused. The exact source type is unresolved. `int unusedPacket` is the least-inventive draft placeholder; a project-specific packet pointer type should not be invented until a route or prototype source proves it.

## C++ Readiness and No-Code Proof

Recommended: add first-draft C++.

Reasoning:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank emitter [UID:0000NN].
- Average score is already above 85.
- Target is not no-owner/non-emitting.
- The body is source-coherent and not compiler-only glue.
- The analogous `SelfSaveInputPaneFactory` target already uses source-shaped C++ despite a no-route caveat.
- Constructor details should remain in `SelfSaveOKPane`; the factory/helper draft can express the source intent without manual vtable stores.

The existing no-code rationale should be retired or narrowed. The exact no-code proof would only apply if the project now required a visible caller/table route for all helper C++ entry. Current B-agent rules do not impose that gate, and the accepted nearby precedent argues against using no-route as an absolute C++ blocker.

Recommended first-draft C++ block:

```cpp
static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)
{
    (void)unusedPacket;

    SelfSaveOKPane *pane = new SelfSaveOKPane;
    (void)pane;

    return true;
}
```

Implementation notes for the target page:

- Keep this source-shaped; do not write a generated/IDA-shaped block with explicit vtable stores, SEH cookie locals, or raw calls to `0x00595390`, `0x0058e270`, `0x0055ee10`, or `0x005975e0`.
- Preserve the binary evidence below the C++ block so the simplification to `new SelfSaveOKPane` remains auditable.
- State that the constructor was likely inlined in this helper, explaining why the binary contains the construction sequence instead of a call to [UID:0001B0].
- State that allocation failure still returns true in the binary; the source-shaped draft follows the local compiler/source convention rather than inventing an explicit decompiler-style null branch.

## Score and Metadata Recommendation

Recommended target metadata after implementation:

- `COMPLETION:89`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000NN` unchanged
- `RECONSTRUCTABLE:TRUE` unchanged
- `EMITTER_UIDS:0000NN` unchanged
- Blank emitter position unchanged

Why raise from `86/86`:

- IDA MCP now confirms the target function range, prototype shape, decompiled behavior, disassembly details, empty caller list, empty entry xrefs, callee list, vtable/string/global routes, constructor sibling, timer vtable route, MapPane inline sibling, and successor boundary.
- Fresh PE route-scan evidence is now documented with positive controls.
- Fresh Capstone verification confirms exact construction details and the exact boundary.
- The no-code question can be resolved under the current code-entry gate.
- The target can receive source-shaped first-draft C++ while keeping the route caveat visible.

Why cap at `89/89`:

- No direct branch, pointer, VA, RVA, or raw-offset route to `0x00513800`.
- IDA MCP finds zero entry xrefs/callers for `0x00513800` and no function at `0x00513920`.
- Original source spelling is inferred.
- Exact unused parameter type is inferred.
- Packet callback versus retained file-local helper remains unresolved.
- `0x00513920+` is a separate no-route successor that appears function-shaped but is still not modeled as its own page.

## Target Documentation Changes Needed if Accepted

Update `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md` with report-level detail:

- Change score to `COMPLETION:89`, `CONFIDENCE:89`.
- Keep owner/emitter metadata unchanged.
- Add the first-draft C++ block above.
- Add a dated 2026-06-23 IDA MCP and PE route-scan note:
  - endpoint `http://127.0.0.1:13337/mcp`;
  - session `0b5e057e`;
  - IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`;
  - `lookup_funcs`, `analyze_function`, `disasm`, `xrefs_to`, and scoped `search_text` results;
  - `sub_513800` prototype `char __stdcall(int)`, size `0x120`, empty callers, empty entry xrefs, and callee list;
  - `0x00513920` not a function and has zero xrefs;
  - constructor/timer relationship and MapPane inline case `0x21` / decimal `33` (Verified with `int_convert.py`);
  - executable path/hash/provenance;
  - local section map;
  - zero branch hits to `0x00513800`;
  - zero VA/RVA/raw-offset dword hits to `0x00513800`;
  - positive branch-route controls for nearby MapPane packet targets;
  - positive vtable/spacer controls for SelfSaveOKPane.
- Add a construction evidence section preserving:
  - `0x120` / 288-byte range size;
  - `0x174` / 372-byte allocation;
  - vtable stores at `0x00513871`, `0x00513877`, `0x00513881`;
  - localized string id `0x3d` / 61;
  - screen rect `(14,456)-(422,468)`;
  - attach globals `0x0069b368` and `0x0067a740`;
  - 1000 ms timer scheduling at object offset `+0xa4`.
- Add relationship notes for:
  - inline MapPane packet case `0x21`;
  - standalone constructor [UID:0001B0];
  - SelfSaveOKPane vtable data and spacer string pages.
- Preserve and sharpen rejected alternatives:
  - not MapPane owner;
  - not packet opcode owner;
  - not alternate constructor;
  - not no-owner/non-emitting.
- Add boundary note:
  - predecessor `ret 4` and one-byte `0xcc` at `0x005137ff`;
  - target `ret 4` at `0x0051391d`;
  - separate no-route successor starting at `0x00513920`.
- Add score-cap rationale with no-route/no-caller MCP evidence, unresolved source spelling/prototype caveats, and the unmodeled no-route successor caveat.

## Support Documentation Changes Needed if Accepted

Required or likely support updates:

- `by-file/SelfSaveOKPane.md`
  - Update the factory/helper entry to state that [UID:0001AY] is now recommended as source-shaped `CreateSelfSaveOKPane(int unusedPacket)`.
  - Preserve the no-route route-scan caveat and the MapPane owner rejection.
  - Mention that constructor detail remains class-owned and the helper draft intentionally does not manually emit vtable writes.

- `by-class/SelfSaveOKPane.md`
  - Update method/factory notes to reflect the first-draft helper role and no-route cap.
  - Preserve relationship to inline MapPane packet case `0x21` and constructor [UID:0001B0].

- `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md`
  - Optional but useful: update relationship notes so the constructor page no longer treats [UID:0001AY] source shape as fully blocked. It should say [UID:0001AY] can be represented as `new SelfSaveOKPane` while this page retains constructor-detail ownership.

- `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
  - Optional only if implementation wants support synchronization: add that packet case `0x21` remains the live inline route and that [UID:0001AY] still has no route from the dispatcher.

No generated/project-level files should be edited manually. No `-coverage-report.md` file should be edited by B004 unless explicitly assigned by the supervisor.

## Exact Supervisor-Owned Coverage Text

If the supervisor accepts the report and chooses to update coverage, replace the current [UID:0001AY] row with:

```markdown
        - [UID:0001AY][0x00513800-0x00513920.SelfSaveOKPaneFactory](by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md) 0x00513800-0x00513920 | function | CreateSelfSaveOKPane retained SelfSaveOKPane factory/helper : reconstructable : 89% : strong : B004 source-quality pass confirms through IDA MCP session 0b5e057e and supplemental PE checks the exact 0x120 / 288-byte modeled helper ending in ret 4, one-byte 0xcc predecessor padding at 0x005137ff, separate no-route prologue-shaped successor at 0x00513920, char __stdcall(int) prototype shape, empty caller list, zero entry xrefs, 0x174 / 372-byte allocation, SelfSaveOKPane vtable stores at 0x00513871/0x00513877/0x00513881, spacer refs to 0x0061ea8c, localized string id 0x3d / 61, rect (14,456)-(422,468), attach through screen/render-layer globals, and 1000 ms timer setup at object offset +0xa4; MCP xrefs and raw PE scan found no ordinary caller/table/pointer/branch/VA/RVA/raw-offset route to 0x00513800 while positive controls found nearby MapPane packet case 0x21 / decimal 33 construction hits, the SelfSaveOKPane timer vtable slot, vtable base stores, and spacer refs; owner/emitter stays [UID:0000NN] over MapPane, packet-dispatcher, alternate-constructor, and no-owner alternatives, with first-draft source-shaped C++ recommended as CreateSelfSaveOKPane(int unusedPacket) using new SelfSaveOKPane and returning true; confidence remains capped by no ordinary route, inferred original spelling/prototype, packet-callback-versus-retained-helper uncertainty, and the still-unmodeled no-route successor at 0x00513920.
```

This report did not edit `by-memory/-coverage-report.md`.

## Expected Validators After Implementation

Run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation` for each changed by-* page:

> Executable block R001 was removed from this report and preserved verbatim in [0001AY-SelfSaveOKPaneFactory-source-quality-removed.md](0001AY-SelfSaveOKPaneFactory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support docs are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [0001AY-SelfSaveOKPaneFactory-source-quality-removed.md](0001AY-SelfSaveOKPaneFactory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If a supervisor-owned coverage row is applied, the supervisor should validate the coverage file separately.

No validators were run during this report-only pass because no by-* documentation was edited.

## Open Questions and Blockers

- IDA MCP is available for inspection and confirms the current route/callee/xref evidence. No IDA DB rename/type/comment edits were requested or made during this report-only pass.
- Original helper spelling unresolved: `CreateSelfSaveOKPane` is recommended as a source-facing draft name, not proven original spelling.
- Unused argument type unresolved: binary proves `ret 4` and no use of the parameter, but not whether the original source type was an integer, packet pointer, or callback context pointer.
- Runtime route unresolved: fresh PE scan found no branch, pointer, VA, RVA, or raw-offset route to `0x00513800`.
- Successor `0x00513920+` unresolved: appears function-shaped and separate, but has zero route hits and no by-memory page found.
- Allocation failure source semantics unresolved: binary returns true even when allocation returns null; first-draft C++ should avoid decompiler-shaped null-branch invention and leave the constructor/new behavior source-shaped.

None of these blockers prevent a target documentation update or source-shaped first-draft C++ under the current gate. They justify the recommended score cap.

## IDA Rename, Type, and Comment Recommendations

No IDA changes were made. If the supervisor later approves IDA DB edits:

- Function name candidate: `CreateSelfSaveOKPane`
- Conservative type candidate: `bool __stdcall CreateSelfSaveOKPane(int unusedPacket)`
- Avoid changing the target to a `SelfSaveOKPane::` member.
- Avoid naming it as a MapPane packet handler unless a current route/table entry is found.
- Add a comment noting no direct PE route found as of 2026-06-23 and that constructor body is likely inlined from `SelfSaveOKPane`.

## Wave2/Wave3 Staleness Handling

No current explicit Wave2/Wave3 instruction applied to this target. Any stale Wave2/Wave3 ownership or score assertions should be rejected unless reissued by current supervisor instruction. This report uses current goal.md, current by-* documentation, fresh local PE evidence, and current B-agent workflow rules.

## Changed Files in This Pass

- `tools/leaser/Agents/Agent-B004/research/0001AY-SelfSaveOKPaneFactory-source-quality.md`

No other files were intentionally changed.

## Implementation Tracking Checklist

- [x] Target metadata updated to `COMPLETION:89`, `CONFIDENCE:89`, while keeping `CANONICAL_OWNER:0000NN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NN`, and blank emitter position.
  - Proof: `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md` metadata now shows `COMPLETION:89`, `CONFIDENCE:89`, owner/emitter `0000NN`, `RECONSTRUCTABLE:TRUE`, and unchanged blank `EMITTER_POSITION_OPTIONAL`.
- [x] First-draft C++ inserted into `by-memory/0x00513800-0x00513920.SelfSaveOKPaneFactory.md` as source-shaped `CreateSelfSaveOKPane(int unusedPacket)` using `new SelfSaveOKPane` and returning true.
  - Proof: target reconstruction block now contains `static bool __stdcall CreateSelfSaveOKPane(int unusedPacket)`, `(void)unusedPacket`, `SelfSaveOKPane *pane = new SelfSaveOKPane`, `(void)pane`, and `return true`; it avoids manual allocation/vtable/decompiler helper calls.
- [x] Target page updated with 2026-06-23 PE route-scan evidence, including executable hash, section map, zero route hits to `0x00513800`, and positive controls.
  - Proof: target sections `2026-06-23 IDA MCP Evidence` and `2026-06-23 Supplemental PE Route Scan` now record MCP endpoint/session/provenance, executable path/hash/size, `.text`/`.rdata`/`.data` map, zero branch and VA/RVA/raw-offset dword hits to `0x00513800`, zero controls for nearby raw starts, and positive controls for live MapPane dispatcher calls plus SelfSaveOKPane vtable/string routes.
- [x] Target page updated with construction evidence at report-level detail: `0x120` size, `0x174` allocation, vtable stores, spacer refs, string id `61`, rect, attach globals, and timer setup.
  - Proof: target sections `Function Summary`, `2026-06-23 IDA MCP Evidence`, and `Touched State And Construction Facts` now preserve `0x120` / 288 bytes, `0x174` / 372-byte allocation, `0x00513871`/`0x00513877`/`0x00513881` vtable stores, spacer refs `0x00513866`/`0x005138a9`, string id `0x3d` / 61, rect `(14,456)-(422,468)`, `dword_67A740`/`unk_69B368`, and timer setup at `+0xa4`.
- [x] Target page preserves rejected alternatives and score-cap rationale: MapPane rejected, packet dispatcher rejected, alternate constructor rejected, no-owner rejected, IDA MCP no-route/no-caller cap retained, original spelling/prototype caveats retained.
  - Proof: target sections `Ownership And Rejected Alternatives` and `Confidence, Score Cap, And Open Questions` explicitly reject MapPane, packet-dispatcher, alternate-constructor, and no-owner/non-emitting alternatives; cap remains `89/89` because no caller/xref/table/pointer/route proof was found, spelling/prototype are inferred, callback-vs-retained-helper remains uncertain, and `0x00513920+` remains unresolved.
- [x] Target page preserves boundary analysis: `0x005137ff` padding, `0x0051391d` `ret 4`, separate no-route successor at `0x00513920+`.
  - Proof: target section `Address Range And Boundary` records one-byte `0xcc` predecessor at `0x005137ff-0x00513800`, security-cookie check at `0x00513915`, `ret 4` at `0x0051391d`, and a separate prologue-shaped no-xref/not-function successor at `0x00513920`.
- [x] Support docs updated as needed without summarizing away route-scan and rejected-alternative evidence.
  - Proof: `by-file/SelfSaveOKPane.md` now documents `CreateSelfSaveOKPane(int unusedPacket)`, the no-route PE/MCP caveat, MapPane rejection, and source-shaped C++ rationale; `by-class/SelfSaveOKPane.md` now documents the helper/factory relationship and first-draft/no-route cap; `by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md` now says [UID:0001AY] may be represented as `new SelfSaveOKPane` while constructor-detail ownership remains on the constructor page; `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md` now preserves packet case `0x21` as the live inline sibling route and states [UID:0001AY] still has no dispatcher/caller/table/pointer route.
- [x] Scoped validators run for every changed by-* doc.
  - Proof: from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - `python .\tools\validator.py --mode file --file by-memory\0x00513800-0x00513920.SelfSaveOKPaneFactory.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`; validator applied metadata/reconstruction generation and updated generated/stats outputs.
    - `python .\tools\validator.py --mode file --file by-file\SelfSaveOKPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`; validator inserted five [UID:0001AY] links and updated stats.
    - `python .\tools\validator.py --mode file --file by-class\SelfSaveOKPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`; validator inserted three [UID:0001AY] links and updated stats.
    - `python .\tools\validator.py --mode file --file by-memory\0x005147d0-0x00514914.SelfSaveOKPane.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`; validator inserted four [UID:0001AY] links.
    - `python .\tools\validator.py --mode file --file by-memory\0x0050e4c0-0x00514920.MapPanePacketHandlers.md --apply --queue-timeout 240` -> exit code `0`, `ok: 1`; validator inserted four [UID:0001AY] links.
- [x] Supervisor-owned coverage row applied only by supervisor or in an explicit implementation callback that permits coverage edits.
  - Proof: no `-coverage-report.md` file was edited by B004 during implementation. The exact replacement row remains in this report's `Supervisor-Owned Coverage Text` section for supervisor-owned application.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001AY-SelfSaveOKPaneFactory-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:17","uid":"0001AY"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AY-SelfSaveOKPaneFactory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0001AY-SelfSaveOKPaneFactory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
