** TARGET-REPORT-UID:00035C **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B007 Report: UID00035C SurfacePaletteCallbackForwarderRaw Empty Emitter

Assignment: `B007-report-00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-20260628`

Revision assignment: `B007-revise-00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-20260628`

Target: [UID:00035C] `by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md`

Mode: report-only research. No leases were taken. No by-* docs, generated files, coverage reports, project-level files, tool state, or IDA database state were edited.

## Required Disposition

Use a non-emitting metadata repair, not formal C++ and not a comment-only no-code marker.

The raw range is real source-shaped code and should remain reconstructable with [UID:0000OC] `Surface` as the canonical documentation owner, but current evidence still proves no entry route to the raw start. A generated `Surface.cpp` empty-emitter marker exists only because the target currently has `EMITTER_UIDS:0000OC` while the formal C++ block is blank. The implementation callback should clear `EMITTER_UIDS:` on the exact target and keep the formal `RECONSTRUCTION_CPP CODE` block blank.

Recommended target metadata:

```text
COMPLETION:86
CONFIDENCE:89
CANONICAL_OWNER:0000OC
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
RECONSTRUCTION_CPP CODE:[[[]]]
```

Do not insert a formal C++ body for this pass. The best source-level behavior and naming family are known, but the callable route and ordinary C++ declaration/output route are not safe enough for source emission. A comment-only emitted block would hide that this is real, uncovered raw code rather than padding, compiler metadata, or a parent-covered child. Clearing `EMITTER_UIDS` removes the stale generated empty marker while preserving the exact raw helper for later source recovery.

## Supervisor Rejection Reanalysis

The revised recommendation remains non-emitting, but the proof needs to be read under the current project rules, not as a general preference for leaving hard code blank.

### Direct rule and precedent for `RECONSTRUCTABLE:TRUE` plus blank `EMITTER_UIDS:`

The current by-structure rule explicitly separates semantic ownership from generated-output routing. `CANONICAL_OWNER` records the best documentation owner; `EMITTER_UIDS` routes generated C++ to an output root. The relevant rule states that a page can have a canonical owner but no emitters when ownership is known but generated output is not ready or not applicable, and that if IDA/MCP evidence shows NexusTK-owned source that must be rebuilt, the page should remain `RECONSTRUCTABLE:TRUE` even when final owner, emitter route, exact source-file owner, or final C++ code is not ready. The same paragraph states that if the final emitter route or source shape is not clear, the correct state is `RECONSTRUCTABLE:TRUE` with `EMITTER_UIDS` and/or `RECONSTRUCTION_CPP CODE` blank as appropriate.

The validator README matches that rule: `RECONSTRUCTABLE:TRUE` means confirmed NexusTK-owned source that must be rebuilt; a reconstructable page may intentionally have no canonical owner or emitter route yet, and the reports list missing routing as `non-emits` until relationships are proven. It also states that empty marker comments are emitted only for reconstructable documents with nonblank `EMITTER_UIDS` and blank C++; marker comments are not emitted for blank `EMITTER_UIDS`. Therefore clearing this target's emitter does not mark the bytes covered or non-reconstructable; it moves the page out of the false routed-empty-output state and leaves it visible as a reconstructable non-emitter.

Current project precedent is not limited to source-declared compiler metadata. [UID:000424] `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md` is `RECONSTRUCTABLE:TRUE`, has concrete owner `00007Q`, intentionally blank `EMITTER_UIDS`, and says formal C++ remains blank because emitting the raw no-function body would invent call reachability. [UID:00045K] `by-memory/0x00542180-0x005421e3.IntegrateMacroDialogRetreatMacroPageRaw.md` is `RECONSTRUCTABLE:TRUE`, has concrete owner `00006L`, intentionally blank `EMITTER_UIDS`, and keeps formal C++ blank because the exact raw helper has no modeled function entry and no xref/pointer/direct-branch route. UID00035C is the same structural class: concrete owner, custom source-shaped bytes, but no proven entry/source declaration route. This is not a coverage dodge because the page remains reconstructable, exact, separately documented, and not covered by a parent, `[[CHILDREN]]`, or a comment-only marker.

### Best-supported declaration shape and why it is not source-safe yet

The best behavioral declaration family is now resolved more tightly than "unknown": UID00035C is a five-stack-argument, `thiscall`-shaped Surface/GrafPort render forwarder that preserves the incoming `ecx` destination receiver, resolves its fifth stack argument through `g_pPaletteLib` / `PaletteLib::GetPaletteByName`, and calls SurfaceRenderCallbackTable slot 3 / `dword_69B3EC` with the first four explicit arguments plus the resolved palette. The likely source-facing roles are destination `GrafPort` receiver, source/image or frame/RLE descriptor, source rectangle or draw record pointer, destination rectangle, draw mode/composition argument, and palette-name lookup token. The slot-3 callback targets are the RLE fill/composition implementations `0x004bd420` and `0x004c3190`.

That resolves the behavior, but it does not resolve the source declaration well enough for formal output. A conventional file-static helper with an explicit `GrafPort *` parameter would have six stack arguments and would not naturally preserve the observed hidden receiver in `ecx`. A `Surface` free function with a hand-written `__thiscall`-style hidden receiver would be reverse-engineering ABI scaffolding, not plausible mid-2000s source. A `GrafPort` member method is the only ordinary C++ shape that matches the hidden receiver, but current evidence finds no caller, vtable slot, pointer literal, registration table, or source-use site that would justify adding a new member API to `GrafPort` or routing the page through the GrafPort emitter. Keeping Surface as owner while emitting a `GrafPort` member body would also contradict the target metadata, while emitting a `Surface` member would give the wrong receiver model.

This is a source-shape blocker, not an original-name blocker. The report already uses source-facing names where evidence supports them: `g_pPaletteLib`, `PaletteLib::GetPaletteByName`, `SurfaceRenderCallbackTable`, slot 3 / RLE fill-composition target, `RenderTileFrame`, `ForwardToTileFrameBlitHelper`, `FrameDrawRecord`, `RectBounds`, draw mode, and palette-name/lookup token. Lack of original symbol proof would not by itself justify blank C++; the blocker is that no current evidence proves the callable source declaration or ordinary C++ ownership route required to place those names in a formal block without inventing reachability or ABI.

### Sibling and route comparison required by rejection

`RenderTileFrame` at `0x004b9980` is the positive control for slot-2 palette forwarding. Current MCP command `b007-00035c-reject-reanalysis-decomp-9980` decompiles it as resolving `sub_543D70(dword_67A7E0, Source)` and forwarding through `unk_69B3E8`; current disassembly command `b007-00035c-reject-reanalysis-disasm-9980` confirms it saves the incoming `ecx`, restores it before the callback, pushes six explicit stack arguments, and returns with `retn 18h`. Existing docs give it 311 direct routes, and current `b007-00035c-reject-reanalysis-xrefs2` still samples a live inbound call surface with `more:true`. It is a shared helper with real callsites, not merely an adjacent behavior template.

[UID:000166] `0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper` is the next positive control. Current MCP command `b007-00035c-reject-reanalysis-decomp-99f0` confirms it builds an offset rectangle and forwards through `unk_69B3E8`; current xrefs still show the three direct callers at `0x004b5917`, `0x005c3b60`, and `0x005c3db0`. This is why UID000166 can remain routed through Surface despite blank formal C++: its entry and source-use route are known. UID00035C has no comparable route.

SurfaceRenderCallbackTable slot-3 comparison rejects the callback-target interpretation. `b007-00035c-reject-reanalysis-xrefs2` still reports UID00035C only as a data reference/consumer of `0x0069b3ec` at `0x004b99e3`; the slot target refs remain `0x004bd420` at `0x00558728` and `0x00558b9e`, and `0x004c3190` at `0x00558816` and `0x00558eba`. The support docs around `SurfaceRenderCallbackTable`, `Surface.cpp`, and `GrafPort::DrawTiledBackground` support slot 2's receiver/callback shape and slot 3's RLE fill/composition target role, but they do not supply any callsite or registration edge into `0x004b99c0`.

Current generated evidence reinforces the problem rather than solving it. `auto-generated/NexusTK/render/Surface.cpp` is fresh at validator command id `000000005255`, refreshed `2026-06-28T18:43:20-04:00`, and still contains only the UID00035C `Empty Emitter Marker`. `auto-generated/-ag-research-tracker.md` is fresh at command id `000000005258`, refreshed `2026-06-28T18:43:51-04:00`, and still lists UID00035C in Files With Empty Emitters at stale `82/86`, Reports `0`. `auto-generated/-ag-coverage-report-by-memory.md` is fresh at command id `000000005256`, refreshed `2026-06-28T18:43:36-04:00`, and still carries the stale raw-helper split rationale. Generated output currently proves a stale routed-empty state, not a valid source declaration.

### Final-source standard answer

The final-source standard requires inferred source-facing names when code is emitted. UID00035C should not remain blank merely because the original symbol name, exact typedef spelling, or exact parameter names are unavailable. The current no-emission recommendation instead rests on the stricter rule that emitted C++ must have a confirmed nonblank emitter route and a source shape clear enough to be plausible original source. Here, the best behavior can be named, but no ordinary C++ declaration is supported: static/free helper conflicts with the hidden receiver, `Surface` member conflicts with the receiver, `GrafPort` member conflicts with the current owner/emitter evidence and lacks any callsite, and callback-target ownership is disproven by slot target refs. Emitting any of those would make generated `Surface.cpp` look populated by inventing source reachability. Blank emitter keeps the custom code auditable as reconstructable non-emitting source, exactly as the by-structure rule and UID000424/UID00045K precedents allow.

## Audit Questions For The Non-Emitting Reconstructable Disposition

### Why is this still `RECONSTRUCTABLE:TRUE` if it is intentionally non-emitting?

`RECONSTRUCTABLE:TRUE` is still correct because the bytes are custom NexusTK executable code, not padding, compiler metadata, a CRT/library artifact, an import thunk, or a data table. Current MCP and byte evidence show a normal project-code prologue/body/epilogue at `0x004b99c0-0x004b99ee`: it saves the incoming `ecx` receiver, consumes a caller-supplied fifth stack argument through the process palette library, dispatches the active Surface render callback slot `0x0069b3ec`, restores the saved register/frame, and returns with `retn 14h`.

The non-emitting recommendation is only about current generated-source routing. `EMITTER_UIDS` is a claim that this page should contribute source to generated output through the named emitter. The current target has a nonblank emitter but no formal C++ and no parent/child coverage marker, so generated `Surface.cpp` can only produce an empty-emitter marker. Clearing `EMITTER_UIDS:` states the audit truth: the code remains reconstructable and Surface-owned for documentation, but no current source output route is safe enough to emit.

### Why is clearing `EMITTER_UIDS:` more correct than first-draft formal C++, a comment-only covered-by marker, `[[CHILDREN]]`, or `RECONSTRUCTABLE:FALSE`?

Clearing `EMITTER_UIDS:` is the least false representation of the current evidence.

- First-draft formal C++ would require inventing a source declaration and output route, not just writing the known instruction behavior. Current evidence supports a destination-receiver palette forwarder into slot 3, but it does not prove an ordinary C++ declaration: a `GrafPort` member matches the hidden receiver but lacks caller/vtable/source-use and emitter evidence; a Surface helper keeps current ownership but requires artificial ABI scaffolding or the wrong receiver; a callback-table target is disproven.
- A comment-only covered-by marker is wrong because no other by-memory page emits this 46-byte body. [UID:000165] is an aggregate/container context, [UID:000166] starts after the two-byte padding at `0x004b99f0`, and the slot targets at `0x004bd420`/`0x004c3190` are callees, not coverage for this wrapper.
- `[[CHILDREN]]` is wrong because UID00035C is already an exact raw-body page with no child ranges. There is no split/container tree that would emit the body through child pages.
- `RECONSTRUCTABLE:FALSE` is wrong because the range is real source-shaped project code and participates in the Surface render/palette subsystem. The fact that no entry route is currently proven does not turn the bytes into ignored padding or compiler metadata.

### Why can the known body not currently be emitted with best-inferred source-facing helper/type/callback names?

Project rules allow inferred source-facing names when the emitted result can still plausibly represent the original source shape. Here the body semantics and best naming family are known well enough to describe, but the ordinary C++ declaration and output route are not. A formal C++ block would have to choose among unsupported source shapes:

- a `GrafPort` member is the only normal C++ spelling that naturally explains the hidden `ecx` receiver, but no caller, vtable slot, source-use site, or emitter-route evidence currently supports moving/routing UID00035C through GrafPort;
- a `Surface` member or file-level `Surface.cpp` helper preserves the current canonical owner but gives the wrong receiver shape unless it uses artificial `__thiscall` ABI scaffolding;
- a conventional file-static helper with explicit receiver would add a sixth stack argument and would not match the observed `retn 14h` / five-stack-argument body;
- a callback-table target declaration is disproven because slot 3 targets are `0x004bd420` and `0x004c3190`, while UID00035C is only a consumer at `0x004b99e3`.

The raw helper has no inbound xrefs, no VA/RVA pointer literal route, no direct branch route, and no callback-table target assignment. The adjacent positive controls show the difference: `RenderTileFrame` at `0x004b9980` has 311 direct code routes and [UID:000166] at `0x004b99f0` has three direct code routes. Adding a formal C++ helper for UID00035C would therefore create a source artifact with an invented callable declaration and no proven source-use site. Under the current project rules, that is weaker than a non-emitting reconstructable record with exact behavior and negative-route proof.

### What exact current evidence would let a future B agent safely change this back to a code-emitting target?

A future B agent should reconsider code emission if current evidence finds one or more of these routes:

- a direct `E8`/`E9`, xref, relocation, VA/RVA pointer literal, vtable slot, registration table, or callback-table assignment that targets `0x004b99c0`;
- an IDA function object or reliable manual function boundary that recovers a caller/callee relationship beyond internal fallthrough;
- a source/debug/PDB/map breadcrumb, symbol, string, or source import that names the helper or establishes the original source declaration;
- sibling callback documentation that proves the exact slot-3 typedef, receiver type, return semantics, and source-level helper family for this wrapper;
- a validated parent/child emission route proving this 46-byte body is covered by another source-bearing page;
- stronger binary evidence that the original code intentionally retained this as an uncalled file-static helper and that emitting an unused static helper is source-faithful rather than generated-source noise.

Without one of those evidence classes, the current correction should remain `RECONSTRUCTABLE:TRUE`, Surface-owned, and intentionally non-emitting.

## Current Source/Generated Mismatch

The target source page already has stronger metadata than the generated queue row:

- Target header currently says `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank formal C++.
- The target item summary is stale: it still says the helper is "unassigned" and below the `85/85` gate.
- Generated `auto-generated/NexusTK/render/Surface.cpp` currently contains line 82:
  `UID:00035C ... Completion:82 | Confidence:86 | Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` currently lists UID00035C in Files With Empty Emitters at `82/86`, combined `84.0`, reconstructable `true`, Reports `0`.
- `auto-generated/-ag-coverage-report-by-memory.md` currently reports the same stale `82%` unassigned rationale.

Generated freshness checked 2026-06-28:

- `auto-generated/NexusTK/render/Surface.cpp`: validator command id `000000005192`, refreshed `2026-06-28T18:15:58-04:00`.
- `auto-generated/-ag-research-tracker.md`: validator command id `000000005195`, refreshed `2026-06-28T18:19:10-04:00`.
- Despite those fresh timestamps, the generated artifacts still read the older `82/86`/empty-emitter state. This is an output/state reconciliation issue to prove during implementation validation.
- Rejection-reanalysis generated-state recheck: `auto-generated/NexusTK/render/Surface.cpp` now has validator command id `000000005255`, refreshed `2026-06-28T18:43:20-04:00`, and still contains the UID00035C `Empty Emitter Marker`; `auto-generated/-ag-research-tracker.md` now has command id `000000005258`, refreshed `2026-06-28T18:43:51-04:00`, and still lists UID00035C in Files With Empty Emitters at stale `82/86`, combined `84.0`, Reports `0`; `auto-generated/-ag-coverage-report-by-memory.md` now has command id `000000005256`, refreshed `2026-06-28T18:43:36-04:00`, and still carries the stale raw-helper split/unassigned rationale.

## Current MCP Evidence

MCP was available and mandatory evidence was collected from session `supervisor_20260628_resume`.

Session/health proof:

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active IDB session: `supervisor_20260628_resume`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input binary: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Imagebase: `0x400000`.
- `server_health` command id `b007-00035c-health2`: `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Revision recheck 2026-06-28T18:34:09-04:00: `b007-00035c-rev-idb-list` still reports one active session `supervisor_20260628_resume`, PID/worker PID `5124`, `is_analyzing:false`; `b007-00035c-rev-health` reports `status:"ok"`, same IDB/input paths, `imagebase:"0x400000"`, `auto_analysis_ready:true`, and `hexrays_ready:true`.
- Revision target recheck 2026-06-28T18:34:26-04:00: `b007-00035c-rev-lookup` still reports no function at `0x004b99c0` or `0x004b99ee`, `sub_4B9980` size `0x31`, and `sub_4B99F0` size `0x73`; `b007-00035c-rev-xrefs` still reports zero inbound xrefs to `0x004b99c0`, three inbound xrefs to `0x004b99f0`, 311 code xrefs to `0x004b9980`, and eleven refs involving `0x0069b3ec`; `b007-00035c-rev-decomp-raw` still reports `Decompilation failed at 0x4b99c0`.
- Supervisor-rejection reanalysis recheck 2026-06-28T18:39-18:44-04:00: `b007-00035c-reject-reanalysis-idb-list` reports active session `supervisor_20260628_resume`, PID/worker PID `5124`, `is_analyzing:false`; the first health/lookup/xref requests without explicit `database` returned schema errors saying `database is required`, so the pass reran with `database=supervisor_20260628_resume` rather than treating that as MCP unavailability. `b007-00035c-reject-reanalysis-health2` reports `status:"ok"`, auto-analysis ready, Hex-Rays ready, and strings cache ready. `b007-00035c-reject-reanalysis-lookup2` still reports no function at `0x004b99c0` or `0x004b99ee`, `sub_4B9980` size `0x31`, `sub_4B99F0` size `0x73`, slot targets `sub_4BD420` size `0x889` and `sub_4C3190` size `0x8b0`, and initializer `sub_558840` size `0x723`. `b007-00035c-reject-reanalysis-xrefs2` still reports zero xrefs to `0x004b99c0`, sampled live xrefs to `0x004b9980` with `more:true`, three xrefs to `0x004b99f0`, eleven refs to `0x0069b3ec`, and slot-target refs to `0x004bd420` / `0x004c3190`. `b007-00035c-reject-reanalysis-decomp-9980` and `b007-00035c-reject-reanalysis-decomp-99f0` reconfirm the sibling slot-2 wrapper behaviors; singular-`addr` disassembly commands rechecked the three neighboring bodies.

Function/boundary evidence, command id `b007-00035c-lookup-nearby`:

| Address | MCP result |
| --- | --- |
| `0x004b9980` | Function `sub_4B9980`, size `0x31` / 49 bytes. |
| `0x004b99b1` | Not a function. |
| `0x004b99c0` | Not a function. |
| `0x004b99ee` | Not a function. |
| `0x004b99f0` | Function `sub_4B99F0`, size `0x73` / 115 bytes. |
| `0x00543d70` | Function `sub_543D70`, size `0xce`. |
| `0x004bd420` | Function `sub_4BD420`, size `0x889` / 2185 bytes. |
| `0x004c3190` | Function `sub_4C3190`, size `0x8b0` / 2224 bytes. |
| `0x00558840` | Function `sub_558840`, size `0x723`. |

Raw byte/padding evidence, command id `b007-00035c-bytes`:

- `0x004b99b1-0x004b99c0`: fifteen `0xcc` bytes.
- `0x004b99c0-0x004b99ee`: 46 bytes of code:
  `55 8b ec 56 ff 75 18 8b f1 8b 0d e0 a7 67 00 e8 9c a3 08 00 50 ff 75 14 8b ce ff 75 10 ff 75 0c ff 75 08 ff 15 ec b3 69 00 5e 5d c2 14 00`.
- `0x004b99ee-0x004b99f0`: two `0xcc` bytes.

Size checks:

- `python .\tools\int_convert.py` verified `0x2e` as 46 decimal bytes.
- `python .\tools\int_convert.py` verified `0x14` as 20 decimal bytes, matching five 4-byte stack arguments popped by `retn 14h`.
- The same local conversion batch verified sibling sizes `0x31` as 49, `0x73` as 115, `0x889` as 2185, and `0x8b0` as 2224.

Raw disassembly evidence, command id `b007-00035c-disasm-raw`:

```asm
0x004b99c0  push ebp
0x004b99c1  mov ebp, esp
0x004b99c3  push esi
0x004b99c4  push dword ptr [ebp+18h]
0x004b99c7  mov esi, ecx
0x004b99c9  mov ecx, dword_67A7E0
0x004b99cf  call sub_543D70
0x004b99d4  push eax
0x004b99d5  push dword ptr [ebp+14h]
0x004b99d8  mov ecx, esi
0x004b99da  push dword ptr [ebp+10h]
0x004b99dd  push dword ptr [ebp+0Ch]
0x004b99e0  push dword ptr [ebp+8]
0x004b99e3  call dword ptr unk_69B3EC
0x004b99e9  pop esi
0x004b99ea  pop ebp
0x004b99eb  retn 14h
0x004b99ee  align 10h
```

Decompiler evidence:

- `b007-00035c-decomp-raw`: decompilation fails at `0x004b99c0` because IDA has no function object there.
- `b007-00035c-decomp-prev`: `sub_4B9980` resolves a palette through `sub_543D70(dword_67A7E0, Source)` and forwards through `unk_69B3E8`.
- `b007-00035c-decomp-next`: `sub_4B99F0` builds an offset rectangle and forwards through `unk_69B3E8`.

The sibling evidence is important but not sufficient for UID00035C source emission. `0x004b9980` is the accepted `RenderTileFrame`-style wrapper with 311 direct callers and six stack arguments. UID00035C is the adjacent five-stack-argument slot-3 variant, but current evidence does not recover any caller or registration route into `0x004b99c0`.

## Negative Entry-Route Evidence

MCP inbound xrefs, command id `b007-00035c-inbound-only`:

| Target | Inbound result |
| --- | --- |
| `0x004b99c0` | 0 xrefs. |
| `0x004b99ee` | 0 xrefs. |
| `0x004b99f0` | 3 code xrefs: `0x004b5917`, `0x005c3b60`, `0x005c3db0`. |
| `0x004b9980` | 311 code xrefs; first sampled refs at `0x0041bbf8`, `0x0041bc17`, `0x0041bc39`, `0x0041bd7d`, `0x0041bd9c`. |

MCP byte search, command id `b007-00035c-find-pointers`:

- `C0 99 4B 00` / VA literal for `0x004b99c0`: 0 matches.
- `C0 99 0B 00` / RVA literal for `0x004b99c0`: 0 matches.
- `F0 99 4B 00` / VA literal for `0x004b99f0`: 0 matches.
- `EC B3 69 00` / slot storage literal for `0x0069b3ec`: 11 matches, including operand bytes at `0x004b99e5`.

Mapped PE scan, command id `B007-00035C-PE-SCAN-MAPPED-20260628T1822`, timestamp `2026-06-28T18:22:14-04:00`:

| Target | VA literal count | RVA literal count | Direct `E8/E9` branch count |
| --- | ---: | ---: | ---: |
| `0x004b99c0` | 0 | 0 | 0 |
| `0x004b9980` | 0 | 0 | 311 |
| `0x004b99f0` | 0 | 0 | 3 |
| `0x0069b3ec` | 11 | 0 | 0 |
| `0x004bd420` | 2 | 0 | 0 |
| `0x004c3190` | 2 | 0 | 0 |

The mapped PE scan used PE section mapping rather than raw-file-offset-as-RVA arithmetic. It is a positive-control pass: direct branches to neighboring modeled helpers are found, table and target pointer literals are found, but `0x004b99c0` has no VA, RVA, or direct-branch route.

## Callback-Table Route

UID00035C is a consumer of slot `0x0069b3ec`, not a table target and not an initializer.

MCP xrefs and initializer evidence:

- `b007-00035c-xrefquery-raw`: `0x0069b3ec` has 11 refs. They include UID00035C's indirect call at `0x004b99e3`, call/use sites at `0x0049f283`, `0x004d5e49`, `0x004d6ab9`, `0x004db4c0`, `0x004dcbba`, `0x004e3165`, `0x00500dcb`, and initializer refs at `0x00558753`, `0x00558b9e`, and `0x00558eba`.
- `b007-00035c-xrefquery-targets`: `0x004bd420` has target-address refs at `0x00558728` and `0x00558b9e`; `0x004c3190` has target-address refs at `0x00558816` and `0x00558eba`.
- `b007-00035c-disasm-init`: the modeled initializer `sub_558840` assigns `unk_69B3EC = sub_4BD420` at `0x00558b9e` in the compat/RGB555 family and `unk_69B3EC = sub_4C3190` at `0x00558eba` in the RGB565-capable family.

This proves the slot-3 implementation targets are [UID:0002TB] `0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback` and [UID:0002TF] `0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback`. UID00035C is a wrapper/caller that resolves a palette key and dispatches to the active slot-3 target. It should be cross-linked as a slot-3 consumer, but it must not be modeled as a callback-table target or as storage.

## Palette Evidence

The body loads `dword_67A7E0` / [UID:0000RW] `g_pPaletteLib` into `ecx`, pushes the fifth stack argument, and calls `0x00543d70`.

Support docs already identify:

- `g_pPaletteLib` at `0x0067a7e0` as the process-wide PaletteLib singleton with 83 xrefs.
- `0x00543d70` as the named-palette lookup helper used by shared render paths such as `RenderTileFrame` and `GrafPort::DrawTiledBackground`.

The palette dependency does not transfer ownership to PaletteLib. UID00035C is a render callback forwarder that consumes the palette service before dispatching through Surface render slot `dword_69B3EC`.

## Ownership And Emitter Analysis

Keep `CANONICAL_OWNER:0000OC`.

Reasons:

- The raw code is embedded in the coherent `0x004b9820-0x004ba24a` SurfacePaintHelpers cluster.
- It is bracketed by all-`0xcc` padding after `RenderTileFrame` and before [UID:000166] `ForwardToTileFrameBlitHelper`.
- It uses the same palette-service-and-callback-forwarder pattern as adjacent shared Surface/GrafPort render wrappers.
- Its only meaningful runtime dependency is slot `dword_69B3EC` in [UID:0000TN] `SurfaceRenderCallbackTable`.
- The prior B003 GrafPort boundary report already treats `0x004b99c0` as a split Surface palette callback forwarder with no GrafPort action.
- The prior B002 raw-island comparison used UID00035C as the strong assigned no-entry raw helper because it sits in this coherent SurfacePaintHelpers cluster; that comparison remains valid for owner context.

Clear `EMITTER_UIDS`.

Reasons:

- No formal C++ can be emitted without inventing a callable source entry, source name, and callback typedef.
- The body is not covered by a parent emitted block.
- The range has no children and is not a container, so `[[CHILDREN]]` is not the right repair.
- It is not padding or compiler-generated metadata, so `RECONSTRUCTABLE:FALSE` or an ignored/no-code classification would be wrong.
- A comment-only C++ block would remove the marker but would not represent either source code or a true covered/no-code proof.
- Non-emitting reconstructable metadata is the honest state: owner and behavior are documented, but generated `Surface.cpp` should not emit an empty marker for a body whose source entry route remains unproven.

## Rejected Alternatives

Formal C++ block: rejected for this pass. The body can be described with source-facing names as "preserve the destination receiver, resolve the fifth stack argument through `g_pPaletteLib->GetPaletteByName`, then call slot `dword_69B3EC` with the first four stack args and the resolved palette." The rejection is not based on lack of original symbol proof; it is based on the absence of a supported ordinary C++ declaration/output route. A `GrafPort` member best matches the hidden receiver but lacks any caller/vtable/source-use route and conflicts with the current Surface owner/emitter; a Surface helper preserves the owner but requires artificial `__thiscall` ABI scaffolding or the wrong receiver; a callback-table target is disproven by the slot-3 initializer refs. The sibling `RenderTileFrame` path has 311 callers and accepted source-facing semantics; UID00035C has none.

`[[CHILDREN]]`: rejected. UID00035C is an exact 46-byte raw body with no child ranges.

Covered-by/no-code marker: rejected. The bytes are source-shaped code, not covered by [UID:000165], [UID:000166], or the callback-table targets. There is no proof that another emitted page reproduces this body.

Padding/ignored metadata: rejected. MCP bytes decode a normal prologue/body/epilogue and the adjacent padding spans are already isolated.

Callback-table target ownership: rejected. MCP proves the slot targets are `0x004bd420` and `0x004c3190`; UID00035C only calls the slot at `0x004b99e3`.

PaletteLib ownership: rejected. `g_pPaletteLib` / `sub_543D70` are dependencies used to resolve the fifth stack argument before Surface render dispatch.

GrafPort direct owner: not accepted from current evidence. The body preserves the incoming `ecx` receiver and forwards it to the active callback, but no receiver field reads, vtable route, or ordinary callers prove a GrafPort method declaration. Surface remains the stronger documentation owner because of local cluster placement and callback-table context.

## Implementation-Ready Target Changes

Edit `by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md` after supervisor callback:

1. Set metadata to the recommended block above.
2. Replace the stale item summary. The new summary should state that this is a 46-byte Surface raw helper with no modeled function and no proven entry route; current MCP and mapped PE scans prove zero inbound raw-start refs, pointer literals, RVA literals, or direct branch routes; the body resolves the fifth stack palette key through `g_pPaletteLib` / `PaletteLib::GetPaletteByName` and forwards through `dword_69B3EC`; Surface remains canonical owner, but emitter is intentionally blank.
3. Update `Status` to record the 2026-06-28 MCP session `supervisor_20260628_resume`, the non-emitting metadata disposition, and that this is source-authored code but not currently emitted.
4. Replace the provisional pseudocode warning with a "C++ emission decision" section: formal C++ remains blank; do not emit a comment-only marker; clearing `EMITTER_UIDS` is the empty-emitter repair.
5. Update raw evidence with the current disassembly, byte/padding evidence, function lookup, `int_convert.py` sizes, decompile failure, sibling `RenderTileFrame`/`ForwardToTileFrameBlitHelper` comparison, and current negative entry-route evidence.
6. Add a generated-state note naming `Surface.cpp` validator id `000000005192` and tracker id `000000005195` as stale relative to the target header.
7. Add the supervisor rejection reanalysis at by-doc level: cite the by-structure/validator rule that allows reconstructable non-emits while source shape/output route is not ready, cite current known-owner no-route precedents UID000424 and UID00045K, explain why this is not a coverage dodge, and record that the final-source naming standard was considered.
8. Add rejected alternatives at report-level detail.
9. Update score rationale to `86/89`: exact byte behavior and owner context are current and stronger, but source emission remains capped by no entry route and unresolved ordinary C++ declaration/source-route proof, not by lack of original symbols alone.
10. Add a 2026-06-28 B007 change entry with this report path and command ids.

Do not insert formal C++.

## Implementation-Ready Support Sync

Required support edits after supervisor callback:

1. `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md`
   - Fix the stale item summary and function row that still call UID00035C "unassigned".
   - Keep the aggregate owner/emitter metadata intact unless a separate supervisor instruction changes it.
   - Update the UID00035C row to say Surface-owned documentation child / non-emitting raw helper, no active generated source, no entry route, slot-3 consumer of `dword_69B3EC`.
   - Add 2026-06-28 evidence: no modeled function at `0x004b99c0`, 46-byte body, `0xcc` padding before/after, zero inbound xrefs/VA/RVA/rel32 route, `RenderTileFrame` positive control with 311 direct branch routes, `ForwardToTileFrameBlitHelper` positive control with 3 routes.

2. `by-file/Surface.md`
   - Add UID00035C as an explicit proposed-content/context row between `RenderTileFrame` and UID000166, or update the nearby proposed contents if a row already exists during implementation.
   - State that it is a Surface-context non-emitting raw callback forwarder, not a generated C++ emitter.
   - Preserve the owner distinction: Surface owns the source neighborhood and callback-table context, but the exact helper remains blank until entry route/source declaration proof.
   - Add a short generated-state note that clearing the exact child emitter should remove the stale `Surface.cpp` empty-emitter marker.

3. `by-global/SurfaceRenderCallbackTable.md`
   - Add UID00035C as a concrete slot-3 consumer of `dword_69B3EC`.
   - State it is not a table target and not an initializer.
   - Cite current MCP: slot target refs to `0x004bd420` at `0x00558728`/`0x00558b9e` and `0x004c3190` at `0x00558816`/`0x00558eba`; UID00035C references the slot at `0x004b99e3`.

4. `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
   - Mirror the slot-3 consumer note if the implementation edits the global table page.
   - Keep table/storage ownership unchanged.

No mandatory edit is needed for `by-global/g_pPaletteLib.md`; it already documents the singleton and xref breadth. Add a consumer note only if the supervisor wants every dependency cross-linked.

## Validator And Generated Refresh Plan

After implementation callback, lease only the files about to be edited, release immediately after the edit/validator batch, and run scoped validators from `E:\NTK\GhidraBridge\source-3\project-documentation`.

Minimum validators if the required target/support files are edited:

> Executable block R001 was removed from this report and preserved verbatim in [00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-removed.md](00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the callback-table support pages are edited, also run:

> Executable block R002 was removed from this report and preserved verbatim in [00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-removed.md](00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Generated expectations:

- `auto-generated/NexusTK/render/Surface.cpp` should no longer contain UID00035C as an `Empty Emitter Marker`.
- `auto-generated/-ag-research-tracker.md` should no longer list UID00035C in Files With Empty Emitters.
- UID00035C may remain reconstructable/non-emitting in coverage/tracker outputs. That is expected and better than an empty emitted source marker.

## Implementation Tracking Checklist

Report-time proofs:

- [x] Read current `Agent-B007/goal.md`.
- [x] Used project-level `ntk-b-agent-workflow` skill.
- [x] Did not spawn subagents.
- [x] Took no leases during report-only research.
- [x] Did not edit by-* docs, generated files, project-level files, coverage reports, validator/tool state, or IDA DB.
- [x] Verified MCP availability on session `supervisor_20260628_resume`.
- [x] Collected current MCP function, byte, disassembly, decompiler, xref, callback-table, and conversion evidence.
- [x] Ran mapped local PE scan with positive controls for neighboring helpers and callback targets.
- [x] Checked generated `Surface.cpp`, tracker, and coverage freshness/marker state.
- [x] Resolved the disposition as non-emitting metadata repair with blank formal C++ and blank `EMITTER_UIDS`.
- [x] Revision added mandatory headers `TARGET-REPORT-UID:00035C` and `AUTHOR-AGENT-ID:B007`.
- [x] Revision rechecked MCP availability and target facts with command ids `b007-00035c-rev-idb-list`, `b007-00035c-rev-health`, `b007-00035c-rev-lookup`, `b007-00035c-rev-xrefs`, and `b007-00035c-rev-decomp-raw`.
- [x] Revision added audit answers explaining why `RECONSTRUCTABLE:TRUE` plus blank `EMITTER_UIDS:` is more accurate than formal C++, a comment-only covered-by marker, `[[CHILDREN]]`, or `RECONSTRUCTABLE:FALSE`.
- [x] Revision kept the non-emitting recommendation after re-review; first-draft C++ remains unsafe under current evidence.
- [x] Rejection reanalysis added the required `Supervisor Rejection Reanalysis` section instead of rewriting the report from scratch.
- [x] Rejection reanalysis cited explicit current rules from `by-structure.md` and `tools/validator_README.txt` for reconstructable non-emits and marker emission.
- [x] Rejection reanalysis cited current known-owner no-route custom-code precedents [UID:000424] and [UID:00045K].
- [x] Rejection reanalysis resolved the best-supported behavior/declaration family, compared it against `RenderTileFrame`, [UID:000166], slot-3 targets, `SurfaceRenderCallbackTable`, `Surface.cpp`, and `GrafPort::DrawTiledBackground`, and still rejected formal C++ for source-shape/source-route reasons rather than original-name uncertainty.
- [x] Rejection reanalysis rechecked MCP session `supervisor_20260628_resume` with command ids `b007-00035c-reject-reanalysis-idb-list`, `b007-00035c-reject-reanalysis-health2`, `b007-00035c-reject-reanalysis-lookup2`, `b007-00035c-reject-reanalysis-xrefs2`, `b007-00035c-reject-reanalysis-decomp-9980`, and `b007-00035c-reject-reanalysis-decomp-99f0`.
- [x] Rejection reanalysis rechecked generated `Surface.cpp`, research tracker, and by-memory coverage freshness; UID00035C still appears as a stale empty-emitter marker/row before any by-* implementation callback.

Implementation callback checklist:

- [x] Lease `by-memory/0x004b99c0-0x004b99ee.SurfacePaletteCallbackForwarderRaw.md` only when ready to edit.
  - Proof: `python .\tools\leaser\leaser.py B007 lease ...` returned `Success` for the target before edits.
- [x] Lease `by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md` only when ready to edit.
  - Proof: same lease command returned `Success` for the SurfacePaintHelpers support doc before edits.
- [x] Lease `by-file/Surface.md` only when ready to edit.
  - Proof: same lease command returned `Success` for the Surface file support doc before edits.
- [x] If edited, lease `by-global/SurfaceRenderCallbackTable.md` and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` only when ready to edit.
  - Proof: both callback-table support pages were edited and the same lease command returned `Success` for both before edits.
- [x] Target metadata set to `86/89`, owner `0000OC`, reconstructable true, `EMITTER_UIDS:` blank, `EMITTER_POSITION_OPTIONAL:` blank, formal C++ blank.
  - Proof: target validator command `000000005282` at `2026-06-28T19:06:11-04:00` exited `0` with `ok:1`, `completion_update 00035C ... 86`, `confidence_update 00035C ... 89`, and `canonical_owner_update 00035C ... 0000OC`; post-validator header keeps blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank inline/multiline C++.
- [x] Target stale unassigned/below-gate rationale replaced with current MCP evidence and non-emitting metadata reasoning.
  - Proof: target now records MCP session `supervisor_20260628_resume`, the blank-emitter repair, validator/by-structure rule support, and generated-marker reason instead of the stale below-gate/unassigned rationale.
- [x] Target includes negative evidence: no modeled function, zero inbound xrefs, zero VA/RVA pointer literals, zero direct branch routes, no callback-table target/initializer route, and positive controls for neighboring helpers.
  - Proof: target sections `Current MCP Evidence`, `Negative Route Evidence`, `Slot-3 Callback Table Relationship`, and `Sibling Comparison` carry these details, including `RenderTileFrame` 311-route and UID000166 three-route positive controls.
- [x] Target includes rejected alternatives: formal C++, `[[CHILDREN]]`, covered-by/no-code marker, padding/ignored, callback-table target, PaletteLib owner, GrafPort direct owner.
  - Proof: target `Rejected Alternatives` section now lists all accepted alternatives and reasons.
- [x] Target includes supervisor rejection reanalysis details: explicit rule/precedent for non-emitting reconstructable state, why blank emitter is not coverage hiding, sibling/source-declaration comparison, and final-source-standard reasoning.
  - Proof: target `Source Shape Analysis`, `Non-Emitting Reconstructable Proof`, and `Score Rationale` cite current rules, UID000424/UID00045K precedents, and source-shape/source-route reasoning.
- [x] SurfacePaintHelpers support row and stale summary synchronized.
  - Proof: support validator command `000000005283` at `2026-06-28T19:06:33-04:00` exited `0` with `ok:1`; the summary and UID00035C row now say Surface-owned non-emitting child.
- [x] Surface file support row/note synchronized.
  - Proof: support validator command `000000005284` at `2026-06-28T19:06:49-04:00` exited `0` with `ok:1`; `Surface.md` now has a UID00035C proposed-content/context row and evidence note. The validator reported existing missing-ref UID registry notes but no failure.
- [x] Callback-table support pages synchronized if edited.
  - Proof: `by-global/SurfaceRenderCallbackTable.md` validator command `000000005285` at `2026-06-28T19:07:05-04:00` exited `0` with `ok:1`, and `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md` validator command `000000005286` at `2026-06-28T19:07:20-04:00` exited `0` with `ok:1`; both pages record UID00035C as a slot-3 consumer only.
- [x] `by-global/g_pPaletteLib.md` not edited.
  - Proof: accepted facts only needed dependency references from target/support docs; existing `g_pPaletteLib` singleton/xref documentation was not contradictory and no supervisor requirement requested a dependency backlink.
- [x] Scoped validators run with `--apply --queue-timeout 240 --wait-generated` for every edited by-* doc.
  - Proof: ran the five scoped validators listed above. All exited `0` with `ok:1` and generated refresh completed through command `000000005286`.
- [x] Generated `auto-generated/NexusTK/render/Surface.cpp` checked: UID00035C no longer appears as an `Empty Emitter Marker`.
  - Proof: generated `Surface.cpp` header has validator command `000000005286`, refreshed `2026-06-28T19:07:20-04:00`; `rg "00035C|SurfacePaletteCallbackForwarderRaw"` found no UID00035C match in `Surface.cpp`. Other Surface empty markers remain for unrelated UIDs.
- [x] Generated tracker checked: UID00035C no longer appears in Files With Empty Emitters.
  - Proof: generated tracker header has command `000000005286`, refreshed `2026-06-28T19:07:20-04:00`; `Files With Empty Emitters` begins at line 51 and does not contain UID00035C. The only UID00035C tracker match is line 2565 under `## by-memory`, where it appears as `86/89`, reconstructable `true`, reports `0`, with no generated file/empty-emitter columns filled.
- [x] Leases released immediately after edit/validator batch.
  - Proof: post-validator `unlease` command reported `Rejected[No active lease]` for all five paths, indicating the short-lived leases had already expired; `tools/leaser/Agents/Agent-B007/current_leases.md` shows no active B007 lease rows, only unrelated expired Supervisor rows.

## Final Report Status

FINISHED_REPORT_REVISION

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality.md","timestamp":"2026-06-28T19:13:21","uid":"00035C"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/00035C-SurfacePaletteCallbackForwarderRaw-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00035C"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
