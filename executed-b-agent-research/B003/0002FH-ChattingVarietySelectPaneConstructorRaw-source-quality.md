** TARGET-REPORT-UID:0002FH **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002FH ChattingVarietySelectPaneConstructorRaw Source-Quality Research

## Final Recommendation

Keep [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](../../../../../by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) at `COMPLETION:84`, `CONFIDENCE:91`, `CANONICAL_OWNER:00001Z`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001Z`, blank emitter position, and blank `RECONSTRUCTION_CPP`.

Current IDA MCP session `ff68e691` reconfirms the target as a real source-authored `ChattingVarietySelectPane` constructor-shaped body, but it does not add the missing entry/liveness route. IDA still has no modeled function at `0x004810f0`, no direct xrefs to `0x004810f0`, no xrefs to the body end `0x00481146`, no direct xrefs to sibling destructor start `0x00481150`, and no VA/RVA/raw-offset literal pointer hits for the raw constructor start, constructor end, or destructor start. The compact popup opener at `0x00480cd0` still duplicates the constructor stores inline. That evidence is strong enough for the existing `84/91` source-quality state and a current evidence refresh, but not enough to raise completion to `85+` or emit a first-draft constructor body.

The accepted implementation callback has been completed as a documentation refresh, not a split or C++ pass: the target, class support page, and file support page now replace stale 2026-06-04/05/raw-fallback-style wording with current `ff68e691` evidence, use source-facing `g_pChattingVarietySelectPane` and selector field names `m_pressCaptured`/`m_hotRow` while retaining `dword_67ADDC` / `unk_67ADDC` only as historical IDA aliases, preserve the exact no-code proof, and leave supervisor-owned coverage for the stale `82%` row to be updated to the current `84%` row.

## Assignment Scope And Write Boundaries

- Agent: B003.
- Report assignment ID: `B003-report-chatting-variety-select-pane-constructor-raw-source-quality-0002FH-mcp-20260623`.
- Implementation assignment ID: `B003-implement-chatting-variety-select-pane-constructor-raw-source-quality-0002FH-mcp-20260623`.
- Target UID/path: [UID:0002FH] `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`.
- Starting score: `84/91`.
- Report path: `tools/leaser/Agents/Agent-B003/research/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md`.
- The original evidence pass was report-only. After supervisor acceptance, B003 edited the accepted target/support by-* docs and this report only; no IDA DB, unrelated tool state, or `-coverage-report.md` file was edited by B003.
- No lease was needed for the original report-only pass. During the accepted implementation callback, B003 took short leases only for the three edited by-* docs and released them after the edit/validator batch.
- IDA MCP was mandatory and was used with current session `ff68e691`.

## Evidence Checked

### Current IDA MCP Health And Operational Notes

- `server_health(database="ff68e691")` returned HTTP 200 with `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready with 2067 strings.
- Supervisor-stated listener PID `23996` was checked read-only after one broad `tools/list` request timed out at 15 seconds. `Get-NetTCPConnection` showed `127.0.0.1:13337` listening under PID `23996`, and `Get-Process -Id 23996` showed a responding `python` process started at 2026-06-23 12:41:32 EDT.
- A smaller retry `server_health(database="ff68e691")` immediately after the timeout succeeded. The timed-out broad schema request was not used as target evidence. All target evidence below comes from bounded `lookup_funcs`, `get_bytes`, `xrefs_to`, `decompile`, `insn_query`, `find_bytes`, `get_int`, and `callees` requests.
- A prior heavy multi-query `insn_query` timeout was superseded by narrower range-only `insn_query` calls. The current report is not fallback-only.

### Current Target Function And Neighbor State

`lookup_funcs(database="ff68e691")` checked the target, side padding, and modeled neighbors:

| Address | MCP result | Source-quality impact |
| --- | --- | --- |
| `0x00481000` | `sub_481000`, size `0x0a` | predecessor modeled function before raw helper/padding neighborhood |
| `0x00481010` | not a function | adjacent raw compact helper remains unmodeled |
| `0x00481060` | not a function | adjacent raw compact hit-test helper remains unmodeled |
| `0x004810ea` | not a function | padding/body boundary before target |
| `0x004810f0` | not a function | target is still an IDA-unmodeled raw constructor body |
| `0x00481146` | not a function | exact target end is not a modeled function boundary |
| `0x00481150` | `sub_481150`, size `0x6c` | modeled ordinary selector destructor starts after ten bytes of padding |
| `0x004811c0` | `sub_4811C0`, size `0x2a1` | modeled selector `OnMouseEvent` follows destructor/padding |
| `0x00480cd0` | `sub_480CD0`, size `0x1b0` | compact opener contains inline duplicate construction path |
| `0x00544460` | `sub_544460`, size `0x118` | base `Pane` construction helper called by raw body and inline path |
| `0x00483db0` | `sub_483DB0`, size `0xad` | scalar deleting destructor family for the selector |

This confirms no split/range change is needed. The target remains an exact raw body at `0x004810f0-0x00481146`, bracketed by padding and modeled destructor code.

### Current Bytes, Padding, And Hashes

`get_bytes(database="ff68e691", addr=0x004810ea, size=102)` returned:

- `0x004810ea-0x004810f0`: six `0xcc` bytes.
- `0x004810f0-0x00481146`: 86 constructor bytes.
- `0x00481146-0x00481150`: ten `0xcc` bytes.

The raw target bytes are:

```text
55 8b ec 51 56 8b f1 6a 01 89 75 fc e8 5f 33 0c
00 8d 86 f8 00 00 00 85 c0 74 08 8d 88 08 ff ff
ff eb 02 33 c9 89 0d dc ad 67 00 c6 00 00 8b c6
c7 06 2c 4f 61 00 c7 86 a0 00 00 00 80 4f 61 00
c7 86 a4 00 00 00 b0 4f 61 00 c6 86 f9 00 00 00
ff 5e 8b e5 5d c3
```

Hashes calculated from the MCP-returned byte sequence:

- Body `0x004810f0-0x00481146`: SHA-256 `a0a8b1182eb3447701982d3849325580db4ce4940a6304468ce51bb504169350`, SHA16 `a0a8b1182eb34477`.
- Padded neighborhood `0x004810ea-0x00481150`: SHA-256 `49c17d879d9457f01b0bff2d87c4e49a6b584f4d30b34c8f43a4e80bb813b70f`, SHA16 `49c17d879d9457f0`.

`get_bytes(database="ff68e691", addr=0x0067addc, size=4)` returned `00 00 00 00`, matching the current documented `g_pChattingVarietySelectPane` zero-filled storage page rather than old static-image `0xffffffff` wording.

### Current Raw Disassembly Evidence

Bounded `insn_query(database="ff68e691", start=0x004810f0, end=0x00481146, count=40)` returned 25 instructions, all with `fn:null`. The important sequence is:

```asm
0x004810f0  push ebp
0x004810f1  mov ebp, esp
0x004810f3  push ecx
0x004810f4  push esi
0x004810f5  mov esi, ecx
0x004810f7  push 1
0x004810f9  mov [ebp-4], esi
0x004810fc  call sub_544460
0x00481101  lea eax, [esi+0F8h]
0x00481107  test eax, eax
0x00481109  jz short loc_481113
0x0048110b  lea ecx, [eax-0F8h]
0x00481115  mov dword ptr unk_67ADDC, ecx
0x0048111b  mov byte ptr [eax], 0
0x0048111e  mov eax, esi
0x00481120  mov dword ptr [esi], offset ??_7ChattingVarietySelectPane@@6B@
0x00481126  mov dword ptr [esi+0A0h], offset ??_7ChattingVarietySelectPane@@6B@_0
0x00481130  mov dword ptr [esi+0A4h], offset ??_7ChattingVarietySelectPane@@6B@_1
0x0048113a  mov byte ptr [esi+0F9h], 0FFh
0x00481145  retn
```

Interpretation:

- `ECX` is `this`; `ESI` preserves it.
- `push 1; call sub_544460` is the base `Pane` construction path.
- `lea eax,[esi+0xf8]` followed by `mov byte ptr [eax],0` clears selector field `m_pressCaptured` at `+0xf8`.
- `mov byte ptr [esi+0xf9],0xff` initializes selector field `m_hotRow` to `-1`.
- `mov dword ptr unk_67ADDC, ecx` writes the singleton. Source-facing documentation should call it `g_pChattingVarietySelectPane`; `unk_67ADDC`/`dword_67ADDC` should remain only as historical IDA/generated aliases.
- The three vtable stores install the `ChattingVarietySelectPane` primary/secondary/tertiary vtables at `this+0`, `this+0xa0`, and `this+0xa4`.

The decimal offsets and values used in this report were converted with `tools/int_convert.py`: `252 -> 0xfc`, `248 -> 0xf8`, `249 -> 0xf9`, `160 -> 0xa0`, and `164 -> 0xa4`.

### Decompilation Evidence

- `decompile(database="ff68e691", addr=0x004810f0, include_addresses=true)` returned `code:null` and `error:"Decompilation failed at 0x4810f0"`. This is an IDA function-model absence at the raw start, not MCP unavailability.
- `decompile(database="ff68e691", addr=0x00480cd0, include_addresses=true)` returned a modeled compact opener. Its create branch checks `unk_67ADDC`, allocates `0xfc` bytes with `sub_4F4AA0`, calls `sub_544460(v7, 1)`, writes `unk_67ADDC`, stores the same selector vtables at `v8+0`, `v8+0xa0`, and `v8+0xa4`, writes `v8+0xf8 = 0` and `v8+0xf9 = -1`, stores the popup pointer in `this[23]`, sets rectangle `(7,617,74,727)`, and dispatches setup through vtable slots `+0x30` and `+0x3c`.
- `decompile(database="ff68e691", addr=0x00481150, include_addresses=true)` returned the ordinary destructor shape: restore the same three selector vtables, call `sub_544CE0`, call `sub_544D70`, clear `unk_67ADDC = 0`, then call `sub_544580`.

The decompiler still labels the singleton `unk_67ADDC`. Current by-global/by-memory storage pages already resolve source-facing `g_pChattingVarietySelectPane`; the target page should use that name and keep `unk_67ADDC` only when citing exact MCP/IDA output.

### Inline Duplicate Construction Path

Bounded `insn_query(database="ff68e691", start=0x00480d7a, end=0x00480e05, count=70)` returned the source-equivalent inline construction sequence inside `sub_480CD0`:

- `0x00480d7f`: compare `unk_67ADDC` to zero.
- `0x00480d8c`: push allocation size `0xfc`.
- `0x00480d91`: call `sub_4F4AA0`.
- `0x00480da9-0x00480dad`: pass `1`, set `ECX=ESI`, call `sub_544460`.
- `0x00480dc2` / `0x00480dc9`: write `unk_67ADDC` with the constructed pointer or zero.
- `0x00480dd3`, `0x00480dd9`, `0x00480de3`: store the same three selector vtable pointers.
- `0x00480ded`: clear `+0xf8`.
- `0x00480df0`: set `+0xf9` to `0xff`.

This is the main C++ blocker. The raw body is source-equivalent to `ChattingVarietySelectPane::ChattingVarietySelectPane()`, but the executable also contains the same construction logic inline in the popup opener. Without a direct caller, entry pointer, original symbol, or other entry route, adding a constructor C++ body to [UID:0002FH] would force a standalone out-of-line source representation that the binary has not proven and could incorrectly drive de-duplication of [UID:0002FC].

### Destructor And Scalar Deleting Destructor Context

Bounded `insn_query(database="ff68e691", start=0x00481150, end=0x004811bc, count=60)` returned the modeled ordinary destructor body:

- `0x00481175`, `0x0048117b`, `0x00481185`: restore the three selector vtables.
- `0x0048118f`: call `sub_544CE0`.
- `0x00481196`: call `sub_544D70`.
- `0x0048119d`: clear `unk_67ADDC`.
- `0x004811a7`: call `sub_544580`.

Bounded `insn_query(database="ff68e691", start=0x00483db0, end=0x00483e5d, count=90)` returned the scalar deleting destructor family for the same class:

- `0x00483ddc`, `0x00483de2`, `0x00483dec`: restore the same three vtables.
- `0x00483df6`, `0x00483dfd`, `0x00483e0e`: call the same cleanup/base helpers.
- `0x00483e04`: clear `unk_67ADDC`.
- `0x00483e1f`: optional delete through `sub_4F4AC0`; alternate guarded path at `0x00483e3b-0x00483e46`.

This strengthens class ownership but does not create a constructor entry route. The destructor page [UID:0002FI] already carries first-draft destructor C++; the constructor target should remain blank C++.

### Xrefs, Vtables, Global, And Pointer-Route Negatives

`xrefs_to(database="ff68e691")` returned:

- `0x004810f0`: zero xrefs.
- `0x00481146`: zero xrefs.
- `0x00481150`: zero xrefs.
- `0x0067addc`: seven data xrefs:
  - `0x00480d7f`, `0x00480dc2`, `0x00480dc9` in `sub_480CD0`.
  - `0x00480eb2` in `sub_480E80`.
  - `0x00481115` in the raw constructor body, with no function owner.
  - `0x0048119d` in `sub_481150`.
  - `0x00483e04` in `sub_483DB0`.
- `0x00614f2c`: four data xrefs at `0x00480dd3`, `0x00481120`, `0x00481175`, and `0x00483ddc`.
- `0x00614f80`: four data xrefs at `0x00480dd9`, `0x00481126`, `0x0048117b`, and `0x00483de2`.
- `0x00614fb0`: four data xrefs at `0x00480de3`, `0x00481130`, `0x00481185`, and `0x00483dec`.

`get_int(database="ff68e691")` with `ty="u32le"` returned:

- `0x00614f2c`: decimal `4734384` = `0x00483db0` (Verified with `tools/int_convert.py`), the primary first slot/scalar deleting destructor route.
- `0x00614f80`: decimal `4733573` = `0x00483a85` (Verified with `tools/int_convert.py`), secondary vtable adjustor route.
- `0x00614fb0`: decimal `4733584` = `0x00483a90` (Verified with `tools/int_convert.py`), tertiary vtable adjustor route.
- `0x0067addc`: zero.

`find_bytes(database="ff68e691")` with plain byte patterns found zero matches for all of these little-endian literal forms:

- Constructor start VA/RVA/raw-offset patterns: `f0 10 48 00`, `f0 10 08 00`, `f0 04 08 00`.
- Constructor end VA/RVA/raw-offset patterns: `46 11 48 00`, `46 11 08 00`, `46 05 08 00`.
- Destructor start VA/RVA/raw-offset patterns: `50 11 48 00`, `50 11 08 00`, `50 05 08 00`.

The raw-offset forms assume the documented `.text` mapping for this PE: image base `0x00400000`, `.text` VA `0x00401000`, and `.text` raw pointer `0x00000400`, so `0x004810f0` corresponds to file offset `0x000804f0`, `0x00481146` to `0x00080546`, and `0x00481150` to `0x00080550`. The scan result is negative for all three representation families.

`callees(database="ff68e691")` returned modeled sibling dependencies:

- `sub_480CD0` callees: `sub_4B7C50`, `sub_4B7E80`, `sub_4F4AA0`, `sub_544460`, `sub_544690`, and `@__security_check_cookie@4`.
- `sub_481150` callees: `sub_544CE0`, `sub_544D70`, `sub_544580`.
- `sub_483DB0` callees: `sub_544CE0`, `sub_544D70`, `sub_544580`, `sub_4F4AC0`, and `@_guard_check_icall_nop@4`.

## Current Documentation State

- Target [UID:0002FH] is already `84/91`, owned/emitted by [UID:00001Z], reconstructable, and blank-C++. Its prose still starts from stale 2026-06-04/06-05 MCP wording, uses `dword_67ADDC` prominently in the behavior summary, and has old `95/95` code-entry phrasing in historical text. The current report recommends refreshing that body with session `ff68e691` evidence while keeping historical entries as history.
- [UID:00001Z][ChattingVarietySelectPane](../../../../../by-class/ChattingVarietySelectPane.md) is already `87/91`, emits declaration-only class C++, declares `ChattingVarietySelectPane()`, declares `~ChattingVarietySelectPane()`, and has fields `m_pressCaptured`, `m_hotRow`, and `m_reservedFA[2]`. It already says the raw constructor is source-equivalent but no-entry capped.
- [UID:0000I5][Chatting](../../../../../by-file/Chatting.md) already places the selector class in the Chatting source family and states that [UID:00001Z] emits declaration-only class C++ while exact method/helper bodies stay in by-memory children.
- [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](../../../../../by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md) already documents the inline duplicate construction path and keeps formal C++ blank until constructor/source de-duplication and Pane slot names are final.
- [UID:0002XA][g_pChattingVarietySelectPane](../../../../../by-global/g_pChattingVarietySelectPane.md) and [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](../../../../../by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md) already resolve the source-facing global name, type hypothesis, zero-filled storage, seven xrefs, and raw constructor cap.
- [UID:0003AT][0x00614cdc-0x00615284.ChattingVtableData](../../../../../by-memory/0x00614cdc-0x00615284.ChattingVtableData.md) already lists the selector vtable bases and representative store/xref evidence.
- `by-memory/-ignored.md` already has current 2026-06-23 B001 evidence for the `0x004810ea-0x004810f0` pre-target padding. Its `0x00481146-0x00481150` post-target padding entry is accurate but still cites older 2026-05-31 evidence; a future implementation callback may refresh that one line to current B003 MCP evidence, but this is not required for the target score/C++ decision.
- `by-memory/-coverage-report.md` still shows [UID:0002FH] as `82%` and mentions `dword_67ADDC`; it should be supervisor-updated to the exact `84%` row supplied below after accepted implementation.

## Heuristic / Inference Reanalysis

### Claim: This Is `ChattingVarietySelectPane::ChattingVarietySelectPane()` Source-Equivalent Code

Confidence: strong for source-equivalent behavior, not strong enough for standalone C++ emission.

Evidence:

- The raw body is bracketed by `0xcc` padding and contains a complete constructor-shaped prologue/body/return sequence.
- It receives `this` in `ECX`, preserves it in `ESI`, calls the base `Pane` construction helper with argument `1`, writes class vtables, writes the selector singleton, clears `+0xf8`, initializes `+0xf9` to `-1`, and returns `this`.
- The three vtable stores are exactly the `ChattingVarietySelectPane` vtable family used by inline construction, ordinary destructor, and scalar deleting destructor.
- The same singleton is checked/written by the opener, written by the raw constructor, and cleared by destructor/scalar destructor.
- The class page already owns the fields and declaration-only constructor.

Counter-evidence checked:

- IDA still has no function model at `0x004810f0`.
- `xrefs_to 0x004810f0` is empty.
- `find_bytes` found no VA/RVA/raw-offset literal pointer forms for the constructor start.
- The compact opener duplicates the construction stores inline instead of calling the raw start.

Decision:

Document as source-equivalent constructor code attached to [UID:00001Z], but do not claim a proven callable out-of-line constructor route.

### Claim: Source-Facing Global Name Should Be `g_pChattingVarietySelectPane`

Confidence: strong.

Evidence:

- Current `by-global` and exact storage child pages already resolve [UID:0002XA] / [UID:0002XB] as `g_pChattingVarietySelectPane`, type hypothesis `ChattingVarietySelectPane *`, with seven refs.
- Current MCP `xrefs_to 0x0067addc` repeats the same seven-ref lifecycle: opener check/write, paint/use, raw constructor write, ordinary destructor clear, scalar deleting destructor clear.
- Current MCP `get_bytes 0x0067addc` confirms zero-filled storage, matching the global pages.

Counter-evidence checked:

- MCP decompile/disasm still prints `unk_67ADDC`; current IDA naming is not sufficient to override accepted by-global source naming. Keep the IDA/generated names only as historical/search aliases.

Decision:

Use `g_pChattingVarietySelectPane` in target/support prose. Preserve `dword_67ADDC` / `unk_67ADDC` only when quoting older docs or exact MCP output.

### Claim: Field Names `m_pressCaptured` And `m_hotRow` Remain Correct

Confidence: strong for these two bytes; `+0xfa..+0xfb` remain reserved/padding.

Evidence:

- Raw constructor clears `this+0xf8` and sets `this+0xf9` to `0xff`.
- Inline opener duplicate does the same.
- Existing class/method documentation ties `+0xf8` to active press capture and `+0xf9` to hover/current row `0..5` or `-1`.
- Allocation size is `0xfc`, so `+0xfa..+0xfb` sit at the tail of the object and no current independent use proves named fields.

Counter-evidence checked:

- Current MCP did not add any contradictory xref or alternate layout fact.

Decision:

Target and support docs should retain `m_pressCaptured` at `+0xf8`, `m_hotRow` at `+0xf9`, and tail padding/reserved bytes at `+0xfa..+0xfb`.

### Claim: Owner/Emitter Route Is [UID:00001Z] With File Route [UID:0000I5]

Confidence: strong for documentation ownership and current emitter route.

Evidence:

- Vtable stores, destructor/scalar-destructor context, field names, singleton lifecycle, and selector method inventory all point to `ChattingVarietySelectPane`.
- [UID:00001Z] is above gate and already emits the declaration-only class shell through [UID:0000I5] `Chatting`.
- [UID:0000I5] already places the selector class and neighboring chat UI classes in the `social/Chatting.cpp` family.

Rejected alternatives:

- `no-owner` / non-emitting: rejected because the bytes are source-authored constructor code for a documented class with a valid owner/emitter route.
- [UID:0000I5] direct file owner: rejected as the canonical owner because the direct source entity is a class constructor body, not file-level code. The file remains the source-placement route.
- [UID:000104] `ChattingUI` aggregate: rejected as canonical owner because it is a broad range/container; the direct class owner is known.
- [UID:00001Y] `ChattingVarietyPane`: rejected as owner. It contains the opener and inline duplicate construction path, but the vtables, fields, destructor, scalar destructor, and singleton target are for `ChattingVarietySelectPane`.
- [UID:0002XA] / [UID:0002XB] global owner: rejected as code owner. The global proves lifecycle and naming, but it does not own the constructor code.
- [UID:0003AT] vtable data owner: rejected as code owner. The vtables prove class identity and dispatch context, but source code belongs to the class.
- Generated/decompiler-name route (`sub_4810f0`, `dword_67ADDC`, `unk_67ADDC`): rejected for source-facing docs. Use source names where evidence supports them.

### Claim: Completion Should Remain `84`, Not Rise Above 85

Confidence: strong.

Evidence for keeping `84`:

- Exact boundary, bytes, padding, behavior, owner, emitter, fields, global, vtables, and source family are known.
- Current MCP adds a stronger negative route pass than older docs: no direct xrefs, no modeled function, and no VA/RVA/raw-offset literal pointer patterns for the raw constructor start.
- The raw body has no direct caller/callback/vtable route, and its behavior is duplicated inline in the opener. A standalone constructor source body would overstate liveness and source representation.

Why not lower:

- The raw body is not unknown, dead padding, or compiler-only glue. It is a coherent constructor body with exact bytes and matching selector lifecycle evidence.

Why not raise:

- The missing entry route is not a minor documentation gap. It directly determines whether formal source should contain a callable out-of-line constructor body, whether the opener should be rewritten as `new ChattingVarietySelectPane()`, and how generated output avoids duplicating or hardening an unproven de-duplication shape.

Decision:

Keep `84/91`. This is a high-evidence raw body whose completion is intentionally capped below 85 by no-entry/no-liveness proof.

## First-Draft C++ Decision

Do not add first-draft C++ to [UID:0002FH].

Unsafe candidate that should not be emitted yet:

```cpp
ChattingVarietySelectPane::ChattingVarietySelectPane()
    : Pane(1),
      m_pressCaptured(0),
      m_hotRow(-1)
{
    g_pChattingVarietySelectPane = this;
}
```

The behavior is plausible and source-equivalent, but it is not safe as final reconstruction code for this target because:

- No current MCP evidence proves `0x004810f0` is reachable as a callable out-of-line constructor. IDA does not model it, direct xrefs are zero, and literal pointer scans are zero.
- The opener [UID:0002FC] contains the same construction sequence inline. Emitting this body could force a source-level de-duplication decision not proven by the executable.
- The exact source form of `sub_544460(this, 1)` is not fully settled for a constructor initializer list versus base helper call in this local source family.
- The source should not harden `dword_67ADDC`/`unk_67ADDC` or generated helper names into code; even with the accepted global name, the missing entry route is enough to keep this child blank.

Recommended C++ disposition:

- Keep [UID:0002FH] `RECONSTRUCTION_CPP` blank.
- Keep [UID:00001Z] class declaration-only C++ as already implemented: it may declare `ChattingVarietySelectPane();`, but the raw constructor child should not emit a body.
- Preserve [UID:0002FC] no-code policy for the opener until constructor de-duplication and Pane slot names are code-ready.

## Applied Target Doc Changes

Applied during the accepted implementation callback:

- Updated `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`.
- Kept metadata unchanged:
  - `COMPLETION:84`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00001Z`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:00001Z`
  - blank `EMITTER_POSITION_OPTIONAL`
  - blank `RECONSTRUCTION_CPP`
- Replaced stale `Live IDA MCP on 2026-06-04/2026-06-05` lead wording with current `ff68e691` MCP evidence.
- Added the current `server_health`, exact function inventory, bytes/padding, SHA16 values, bounded raw `insn_query`, decompile failure, inline duplicate `sub_480CD0` evidence, destructor/scalar context, xrefs, `find_bytes` pointer negatives, `get_int` vtable values, and `callees` evidence at report-level detail.
- Replaced prominent source-facing `dword_67ADDC` wording with `g_pChattingVarietySelectPane`; retained `dword_67ADDC` / `unk_67ADDC` only as historical/generated aliases or exact MCP label quotes.
- Preserved the rejected alternatives: no-owner/non-emitting, direct file owner, `ChattingUI` aggregate owner, `ChattingVarietyPane` owner, global/vtable ownership, generated/decompiler naming, callback/vtable constructor route, pure inline-only/no separate raw body, and unsafe first-draft constructor C++.
- Preserved the exact no-code proof and kept the raw constructor from driving de-duplication of [UID:0002FC].

## Applied Support Doc Changes

Applied support sync:

- `by-class/ChattingVarietySelectPane.md`
  - No metadata or class C++ change.
  - Refreshed the raw constructor note to mention current MCP session `ff68e691`, no modeled function at `0x004810f0`, no direct xrefs/pointer route, exact `g_pChattingVarietySelectPane`/`m_pressCaptured`/`m_hotRow` evidence, and blank-C++/no-entry cap.

- `by-file/Chatting.md`
  - No metadata or source split change.
  - Refreshed the selector row/evidence note only enough to state that current MCP session `ff68e691` reconfirmed the raw constructor no-code policy and [UID:00001Z] remains declaration-only under the `Chatting` source family.

Only-if-stale support sync:

- `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`
  - Already documents the inline duplicate construction path and blank-C++ blocker. If edited during accepted implementation, replace prominent `dword_67ADDC` wording with `g_pChattingVarietySelectPane` while preserving exact `unk_67ADDC`/`dword_67ADDC` disassembly labels as aliases.
  - No score/C++ change.

- `by-memory/-ignored.md`
  - The `0x00481146-0x00481150` padding row is accurate but cites 2026-05-31 evidence. If the supervisor wants a support refresh, update that padding evidence to current B003 MCP session `ff68e691`: constructor body ends at `0x00481146`, `sub_481150` begins at `0x00481150`, and ten `0xcc` bytes fill the span.
  - No coverage-report edit by B003.

No required change:

- `by-global/g_pChattingVarietySelectPane.md`: already source-names the global and documents zero-filled storage, seven refs, raw constructor cap, and Chatting owner route.
- `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`: already exact four-byte storage, global owner, zero-filled bytes, seven refs, and raw constructor cap.
- `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`: already lists the selector vtable bases and representative xrefs; current MCP does not require score or row changes.
- `by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md`: already has accepted destructor C++ and the current pass only uses it as sibling evidence. No edit needed.

## Supervisor-Owned Coverage Text

Do not let B003 edit any `-coverage-report.md` file. After this accepted implementation callback, supervisor should replace the current [UID:0002FH] row in `by-memory/-coverage-report.md` around the `0x004810f0` Chatting selector block with:

```markdown
        - [UID:0002FH][0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw](by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md) 0x004810f0-0x00481146 | raw constructor body | ChattingVarietySelectPaneConstructorRaw : reconstructable : 84% : very strong : B003 current MCP session ff68e691 reconfirms this exact 86-byte raw body as source-equivalent `ChattingVarietySelectPane::ChattingVarietySelectPane()` code: six-byte pre-padding and ten-byte post-padding are `0xcc`, the body calls the Pane base constructor helper `sub_544460(1)`, writes `g_pChattingVarietySelectPane` at `0x0067addc`, clears `m_pressCaptured` at `+0xf8`, initializes `m_hotRow` at `+0xf9` to `-1`, installs selector vtables `0x00614f2c/0x00614f80/0x00614fb0`, and matches the inline duplicate construction path in [UID:0002FC] `ChattingVarietyPaneOnMouseEvent`; completion stays below 85 because current MCP still reports no modeled function at `0x004810f0`, no direct xrefs to the raw start/end/destructor start, and no VA/RVA/raw-offset pointer-table route, so formal C++ remains blank and this raw body must not force constructor de-duplication.
```

No by-class or by-file coverage row change is required unless the supervisor wants those rows to mention current session `ff68e691`; scores for [UID:00001Z] and [UID:0000I5] remain unchanged by this single-target report.

## Validators For Accepted Implementation Callback

Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted callback edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md](0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`; result: `ok: 1`.
- Relevant side effects: `uid_link_update 000104` twice for the Chatting UI link label, `reference_index_add` for `00001Y`, `0002FG`, `0002FI`, `0002XA`, `0002XB`, and `0003AT`, `stats_row_update 0002FH` in `project-level/-auto-completion-stats.md`, `projected_stats_update`, and `autogen_registry_rebuild validator.ini`.
- Relevant warnings/noops: known unrelated `autogen_registry_stale` rows `0003E6` and `00026U`, plus broad autogen advisory/noop messages.

> Executable block R002 was removed from this report and preserved verbatim in [0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md](0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`; result: `ok: 1`.
- Relevant side effects: `uid_link_insert 0002FH`, `reference_index_add 0002FC`, `stats_incremental_noop 00001Z`, `projected_stats_update`, and `autogen_registry_rebuild validator.ini`.
- Relevant warnings/noops: same known unrelated `autogen_registry_stale` rows `0003E6` and `00026U`, plus broad autogen advisory/noop messages.

> Executable block R003 was removed from this report and preserved verbatim in [0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md](0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Exit code: `0`; result: `ok: 1`.
- Relevant side effects: `reference_index_add 0002FC`, `reference_index_add 0002FH`, `stats_incremental_noop 0000I5`, `projected_stats_update`, and `autogen_registry_rebuild validator.ini`.
- Relevant warnings/noops: same known unrelated `autogen_registry_stale` rows `0003E6` and `00026U`, plus broad autogen advisory/noop messages.

Optional support docs were not edited, so optional validators were not run:

> Executable block R004 was removed from this report and preserved verbatim in [0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md](0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No `-coverage-report.md` validator was run because B003 did not edit any coverage report.

## Implementation Tracking Checklist

Implementation callback completed for assignment `B003-implement-chatting-variety-select-pane-constructor-raw-source-quality-0002FH-mcp-20260623`. B003 edited only the accepted target/support by-* docs and this report; no coverage report was edited.

- [x] `by-memory/0x004810f0-0x00481146.ChattingVarietySelectPaneConstructorRaw.md`: kept metadata `84/91`, owner/emitter `00001Z`, reconstructable true, blank emitter position, and blank C++; replaced stale 2026-06-04/05 evidence with current MCP session `ff68e691` health/function/bytes/disasm/decompile/xrefs/find-bytes/get-int/callees facts.
- [x] Target doc: added exact bytes, SHA16 `a0a8b1182eb34477` for the body, SHA16 `49c17d879d9457f0` for the padded neighborhood, six-byte pre-padding, ten-byte post-padding, and no split/range change.
- [x] Target doc: used source-facing `g_pChattingVarietySelectPane`, `m_pressCaptured`, and `m_hotRow`; preserved `dword_67ADDC` / `unk_67ADDC` only as historical/generated aliases or exact MCP output labels.
- [x] Target doc: preserved no-code proof for [UID:0002FH], including no modeled function, no direct xrefs, no VA/RVA/raw-offset pointer route, inline duplicate construction path in [UID:0002FC], unresolved standalone out-of-line constructor liveness, and unsafe de-duplication risk.
- [x] Target doc: preserved rejected alternatives: no-owner/non-emitting, direct file owner, `ChattingUI` aggregate owner, `ChattingVarietyPane` owner, global/vtable ownership, generated/decompiler naming, callback/vtable constructor route, pure inline-only/no separate raw body, and unsafe first-draft constructor C++.
- [x] `by-class/ChattingVarietySelectPane.md`: added a concise current-session support note for [UID:0002FH] without changing metadata or declaration-only class C++.
- [x] `by-file/Chatting.md`: added a concise current-session support/source-route note without changing metadata or source split.
- [x] `by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md`: not edited because no stale wording had to be touched for this accepted callback.
- [x] `by-memory/-ignored.md`: not edited because the supervisor requested current padding refresh only if the file was touched; the target doc now carries current `0x00481146-0x00481150` padding proof.
- [x] Confirmed no required changes to `by-global/g_pChattingVarietySelectPane.md`, `by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md`, `by-memory/0x00614cdc-0x00615284.ChattingVtableData.md`, or `by-memory/0x00481150-0x004811bc.ChattingVarietySelectPaneDestructor.md`; no stale contradictions required edits.
- [x] Ran validator for each changed by-* doc from `E:\NTK\GhidraBridge\source-3\project-documentation` and recorded command, exit code, `ok` count, warnings, and side effects above.
- [x] Did not edit any `-coverage-report.md`; supervisor applies the exact [UID:0002FH] replacement row above after validating implementation.
- [x] Took short leases immediately before by-* edits, released them after the edit/scoped-validator batch, and found no active conflicting lease on the accepted target/support paths before editing.
- [x] Remaining blockers: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0002FH"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002FH-ChattingVarietySelectPaneConstructorRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
