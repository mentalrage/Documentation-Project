** TARGET-REPORT-UID:00020W **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:00020W] BrowserRawWindowProcClone Empty-Emitter Source-Quality Report

## Final Recommendation

[UID:00020W] `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md` should be repaired as a **Browser-owned non-emitting retained raw duplicate**, not as a standalone code-ready emitter.

The live MCP recheck confirms that `0x0046a760` is source-shaped WndProc-like code with local switch data, but it has no IDA function object, no Hex-Rays decompile route, no xrefs, no constructor registration, and no pointer/immediate references to the entry address. The live registered Browser window procedure remains sibling [UID:00020V] at `0x0046a630`, loaded into `WNDCLASSA.lpfnWndProc` at `0x00469758`/`0x0046975e`.

Implementation should therefore:

- keep `CANONICAL_OWNER:0000HV` because the bytes remain Browser-family code;
- keep `RECONSTRUCTABLE:TRUE` because the body is source-authored code, not padding;
- clear `EMITTER_UIDS:` so this target is no longer a code-ready emitter;
- leave the formal `RECONSTRUCTION_CPP CODE` blocks blank;
- update target prose to record the exact no-code proof below;
- update Browser/BrowserWindow support docs at report-level detail so they state that 00020W is a non-emitting retained raw duplicate and [UID:00020V] is the only live emitted callback route.

Recommended score after the target/support repair: `COMPLETION:86`, `CONFIDENCE:91`. This is a small increase over the current by-memory header (`85/90`) because current live MCP now proves the no-emitter disposition, but the original source-retention reason and source symbol remain unproven.

## Assignment Scope

- Current target: [UID:00020W] `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`
- Queue reason: temporary Files With Empty Emitters priority queue.
- Report path: `tools/leaser/Agents/Agent-B010/research/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md`
- Report-only restrictions observed: no by-* edits, no leases, no generated/project/manual coverage/tool/IDA/MCP process-state edits, and no `execute_report`.

## Current Target State

Current target header/prose is internally inconsistent:

- target by-memory header is `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`;
- formal `RECONSTRUCTION_CPP CODE` blocks are blank;
- generated tracker still lists the older queue-facing `80/88` state and `auto-generated/NexusTK/browser/Browser.cpp` contains an Empty Emitter Marker for [UID:00020W];
- target summary still contains stale selector labels `0xf000/0xf100/0xf200/0xf300/0xf600`; live bytes prove the consumed command classes are `0xf000/0xf010/0xf020/0xf030/0xf060`.

The empty emitter is not solved by inventing a standalone C++ callback. It is solved by removing this target from code-emitter status and documenting the exact no-code proof.

## Live MCP Evidence

MCP was usable for this resumed pass.

- MCP probe time: `2026-06-28T04:16:11-04:00` through `2026-06-28T04:16:33-04:00`
- Live session used: `b009_0001Q4_20260628`
- Database path reported by health check: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Health: status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready
- Other active sessions were present, but this report used the healthy `b009_0001Q4_20260628` session.

### Function And Range Probe

`lookup_funcs` / `entity_query` around `0x0046a500-0x0046a900`:

- `0x0046a510` is `sub_46A510`, size `0x107`.
- `0x0046a630` is `sub_46A630`, size `0xba`.
- `0x0046a6ea` is not a function.
- `0x0046a760` is not a function.
- `0x0046a7ec` is not a function.
- `0x0046a7f4` is not a function.
- `0x0046a855` is not a function.
- `0x0046a860` is not a function.
- `0x0046a8a0` is `sub_46A8A0`, size `0x1f`.
- Neighbor functions also include `sub_46A500`, `sub_46A8C0`, and `sub_46A8E0`.

Hex-Rays `decompile 0x0046a760` failed because there is no function object at the raw clone entry. This confirms that a formal C++ function for this exact address would be agent-invented unless a source route is proven elsewhere.

### Registration And Reachability Probe

Sibling [UID:00020V] at `0x0046a630`:

- `0x00469758`: `mov [ebp+WndClass.lpfnWndProc], offset sub_46A630`
- `0x0046975e`: little-endian pointer bytes for `0x0046a630`
- `xref_query 0x0046a630`: one data xref from `0x00469758` in `sub_469640`
- `find data_ref 0x0046a630`: one match at `0x00469758`
- `find immediate 0x0046a630`: one match at `0x00469758`
- `find_bytes 30 A6 46 00`: one match at `0x0046975e`

Raw clone [UID:00020W] at `0x0046a760`:

- `xref_query 0x0046a760`: zero xrefs
- `find data_ref 0x0046a760`: zero matches
- `find immediate 0x0046a760`: zero matches
- `find_bytes 60 A7 46 00`: zero matches

Next possible entry/alignment candidate `0x0046a860`:

- `lookup_funcs 0x0046a860`: not a function
- `xref_query 0x0046a860`: zero xrefs
- `find data_ref 0x0046a860`: zero matches
- `find immediate 0x0046a860`: zero matches
- `find_bytes 60 A8 46 00`: zero matches

This is the decisive no-emitter proof: the live executable registers [UID:00020V], not [UID:00020W], and current IDA has no evidence that `0x0046a760` is called or referenced through any route.

### Raw Body And Switch Data Probe

`disasm`/`insn_query 0x0046a760-0x0046a860` showed source-shaped WndProc code and local compiler switch data:

- `0x0046a760-0x0046a7ec`: raw WndProc-like body, no function owner.
- `0x0046a7ec-0x0046a7f4`: local jump table with two entries.
- `0x0046a7f4-0x0046a855`: 97-byte selector table.
- `0x0046a855-0x0046a860`: eleven `0xcc` alignment bytes already belong in `by-memory/-ignored.md`.

Key raw instructions:

- standard `/GS` frame setup starts at `0x0046a760`;
- `Msg == 0x0f` routes to the paint handler at `0x0046a7c3`;
- `Msg == 0x112` routes to the system-command selector;
- default path at `0x0046a7a6` calls `DefWindowProcA`;
- paint path calls `BeginPaint` at `0x0046a7c8` and `EndPaint` at `0x0046a7d3`;
- consumed command path returns zero through `0x0046a7d9`;
- stack-cookie checks appear before both returns.

Local switch data:

- `xref_query 0x0046a7ec`: one local data xref from `0x0046a79f`, no owning function.
- `xref_query 0x0046a7f4`: one local data xref from `0x0046a798`, no owning function.
- `get_int 0x0046a7ec u32le`: `0x0046a7d9`
- `get_int 0x0046a7f0 u32le`: `0x0046a7a6`
- selector table zeros at offsets `0x00`, `0x10`, `0x20`, `0x30`, and `0x60`.

`tools/int_convert.py` confirmed the selector offsets:

- `16 -> 0x10`
- `32 -> 0x20`
- `48 -> 0x30`
- `96 -> 0x60`
- `4630489 -> 0x46a7d9`
- `4630438 -> 0x46a7a6`
- `4630064 -> 0x46a630`
- `4630368 -> 0x46a760`
- `4630624 -> 0x46a860`

The correct consumed system commands are therefore:

- `0xf000`
- `0xf010`
- `0xf020`
- `0xf030`
- `0xf060`

The current target summary's `0xf100/0xf200/0xf300/0xf600` labels are stale and should be replaced.

## Comparison To Registered Sibling [UID:00020V]

MCP decompile of `0x0046a630` produced the live registered callback:

- function: `LRESULT __stdcall sub_46A630(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)`
- first branch: if `GetWindowLongA(hWnd, -21)` is zero, return `DefWindowProcA`;
- handles `WM_PAINT` with `BeginPaint`/`EndPaint`, returning zero;
- handles `WM_SYSCOMMAND` for `wParam & 0xfff0` values `0xf000`, `0xf010`, `0xf020`, `0xf030`, and `0xf060`, returning zero;
- delegates all other cases to `DefWindowProcA`.

The raw clone [UID:00020W] is similar but **not exact**: it lacks the `GetWindowLongA(hwnd, GWL_USERDATA)` gate present in [UID:00020V]. Because of that difference, a formal "covered by 00020V" code marker would be imprecise if it implied byte/body identity. The source-reconstruction route should emit the registered callback [UID:00020V] and keep [UID:00020W] as documented retained raw code with no standalone emitter.

## Heuristic And Inference Reanalysis

### Ownership

Best owner remains [UID:0000HV] Browser.

Evidence:

- address locality is in the same Browser window-procedure cluster as [UID:00020V];
- behavior is browser-window host behavior, not generic runtime or third-party library code;
- sibling [UID:00020V] is registered from Browser construction code at `0x00469758`;
- existing `by-file/Browser.md` and `by-class/BrowserWindow.md` already place this clone beside the registered Browser callback.

No stronger non-Browser owner was found.

### Source Placement

Recommended source-placement statement:

- [UID:00020V] is the live emitted Browser window procedure in `NexusTK/browser/Browser.cpp`.
- [UID:00020W] is retained raw Browser-adjacent duplicate code with local switch data and no current source-level emission route.

Do not introduce a new public API, method, or standalone callback name for [UID:00020W] unless a future pass finds a registration/caller/source symbol route.

### Emitter Disposition

Current `EMITTER_UIDS:0000HV` is too strong because it requires either first-draft C++ or an exact code-block no-code marker. The target-specific proof supports a cleaner repair:

```text
EMITTER_UIDS:
```

This removes [UID:00020W] from the code-ready emitter set while preserving ownership and behavioral documentation.

### Reconstructable Disposition

Keep:

```text
RECONSTRUCTABLE:TRUE
```

Rationale: the body is real source-authored WndProc-like code and local switch data. It is not padding, imported library data, or random unreachable bytes. The no-code decision is about current emission readiness, not whether the bytes can be understood.

### Split And Padding

Do not split [UID:00020W].

The body and switch tables belong together for documentation:

- `0x0046a760-0x0046a7ec`: raw body
- `0x0046a7ec-0x0046a7f4`: local jump table
- `0x0046a7f4-0x0046a855`: selector table

The post-target alignment bytes remain outside the by-memory target:

- `0x0046a855-0x0046a860`: eleven `0xcc` bytes, already tracked by `by-memory/-ignored.md`

No by-memory split, child page, or padding migration is required for this report.

## Formal C++ / No-Code Proof

Rule 26 readiness requires first-draft C++ for code-ready emitters, or exact target-specific no-code proof. This target should use the no-code proof and should not remain a code-ready emitter.

Accepted no-code proof for [UID:00020W]:

```text
[UID:00020W] is a non-emitting retained raw Browser WndProc clone. Current live MCP proves no IDA function/decompile route at 0x0046a760, no xrefs, no data-ref/immediate/pointer hits to 0x0046a760, and no WNDCLASS registration. The live registered callback is sibling [UID:00020V] at 0x0046a630 via 0x00469758/0x0046975e. Because 00020W lacks 00020V's GetWindowLongA(GWL_USERDATA) gate, a covered-by formal C++ marker would be imprecise. Leave 00020W's formal RECONSTRUCTION_CPP CODE blocks blank and clear EMITTER_UIDS so generated output no longer creates an Empty Emitter Marker.
```

Recommended formal block state after implementation:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] ***
```

and

```text
*** RECONSTRUCTION_CPP CODE:

***
```

Both blocks intentionally remain empty because `EMITTER_UIDS:` is blank.

## Required Target Edits For Implementation

Edit `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md` only during the implementation callback, not during this report-only pass.

Recommended header:

```text
*** COMPLETION:86 ***
*** CONFIDENCE:91 ***
*** CANONICAL_OWNER:0000HV ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS: ***
```

Required prose updates:

- Replace stale summary command labels with `0xf000/0xf010/0xf020/0xf030/0xf060`.
- State that [UID:00020W] is a retained raw Browser WndProc clone with no current caller/registration/pointer route.
- State that [UID:00020V] is the registered emitted callback route.
- Add the live MCP evidence above, including `b009_0001Q4_20260628`, `server_health ok`, no function at `0x0046a760`, zero xrefs, zero pointer/immediate/data hits, and sibling registration at `0x00469758`/`0x0046975e`.
- Update reconstruction/autogen notes so `EMITTER_UIDS:` is blank and generated output should no longer create a Browser.cpp empty-emitter marker for [UID:00020W].
- Keep the body/table range breakdown and `by-memory/-ignored.md` padding note.

## Required Support-Doc Edits For Implementation

Support docs already contain useful placement evidence. Implementation should update them only at report-level detail, preserving existing work.

### `by-file/Browser.md`

Recommended support update:

- Record the B010 live MCP recheck that [UID:00020V] is the registered WndProc at `0x0046a630` and [UID:00020W] at `0x0046a760` has no current route.
- Change old deferred-disposition wording to the final disposition: [UID:00020W] is a non-emitting retained raw duplicate with blank formal C++ and blank `EMITTER_UIDS`.

### `by-class/BrowserWindow.md`

Recommended support update:

- Record that [UID:00020V] remains the only live emitted BrowserWindow host WndProc.
- Record that [UID:00020W] is BrowserWindow-adjacent retained raw code, not a second callable method/callback in current source reconstruction.

### Sibling [UID:00020V]

No mandatory sibling page edit is required if current [UID:00020V] support prose remains accurate. If implementation touches it, the only allowed addition should be a short cross-note that the adjacent raw clone [UID:00020W] was rechecked by B010 on `2026-06-28` and remains non-emitting/no-route.

### Generated And Manual Coverage Reports

Do not edit generated or manual coverage reports directly.

Expected generated refresh after implementation:

- `auto-generated/NexusTK/browser/Browser.cpp` should no longer contain an Empty Emitter Marker for [UID:00020W] after validator/generator refresh.
- `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-coverage-report-by-memory.md` should reflect the updated score/disposition from the by-memory source page.
- Manual `by-memory/-coverage-report.md` remains supervisor/tool-owned for this workflow and should not be edited by B010.

## Validator Plan For Implementation Callback

No validators were run in this report-only pass because no by-* docs were edited.

Implementation callback should use short leases only for the immediate edit/validator batch, then release them. Suggested scoped validation:

> Executable block R001 was removed from this report and preserved verbatim in [00020W-BrowserRawWindowProcClone-empty-emitter-source-quality-removed.md](00020W-BrowserRawWindowProcClone-empty-emitter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the validator has a report execution callback for this report, the supervisor should run it after acceptance. B010 should not execute/archive this report during report-only assignment.

## Implementation Tracking Checklist

- [x] Target header updated to `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_UIDS:`. Proof: `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md` now has `*** COMPLETION:86 ***`, `*** CONFIDENCE:91 ***`, `*** CANONICAL_OWNER:0000HV ***`, `*** RECONSTRUCTABLE:TRUE ***`, and `*** EMITTER_UIDS: ***`.
- [x] Target `Item Summary` corrected to non-emitting retained raw Browser WndProc clone and selector labels `0xf000/0xf010/0xf020/0xf030/0xf060`. Proof: target `Item Summary` now starts `B010 live MCP confirms Browser-owned non-emitting retained raw WndProc clone` and names the selector table as consuming `0xf000/0xf010/0xf020/0xf030/0xf060`.
- [x] Target live MCP evidence added with session `b009_0001Q4_20260628`, health ok, no function/decompile route at `0x0046a760`, zero xrefs/ref searches, and sibling registration at `0x00469758`/`0x0046975e`. Proof: target `Evidence` and `B010 2026-06-28 Empty-Emitter Source-Quality Reanalysis` sections record `server_health` ok, no IDA function/decompile route, zero xrefs/data-ref/immediate/pointer hits for `0x0046a760`, and [UID:00020V] registration at `0x00469758/0x0046975e`.
- [x] Target formal `RECONSTRUCTION_CPP CODE` blocks intentionally left blank with `EMITTER_UIDS:` blank and exact no-code proof in prose. Proof: target inline and multiline formal C++ blocks remain empty, `EMITTER_UIDS:` is blank, and the B010 no-code proof states that [UID:00020W] lacks [UID:00020V]'s `GetWindowLongA(hwnd, GWL_USERDATA)` gate and should not receive a C++ stub or covered-by marker.
- [x] Target range breakdown preserves body/table ownership and `0x0046a855-0x0046a860` ignored padding note. Proof: target `Range Breakdown` still lists `0x0046a760-0x0046a7ec` raw WndProc body, `0x0046a7ec-0x0046a7f4` jump table, `0x0046a7f4-0x0046a855` selector table, and `0x0046a855-0x0046a860` alignment tracked in [UID:0000VN].
- [x] `by-file/Browser.md` updated at support-doc level to identify [UID:00020V] as the live emitted callback and [UID:00020W] as non-emitting retained raw duplicate. Proof: `by-file/Browser.md` now records the 2026-06-28 B010 empty-emitter repair, [UID:00020V] registration at `0x00469758/0x0046975e`, no function/decompile/xref/data-ref/immediate/pointer route for `0x0046a760`, and blank `EMITTER_UIDS:`/formal C++ for [UID:00020W].
- [x] `by-class/BrowserWindow.md` updated at support-doc level with the same final disposition. Proof: `by-class/BrowserWindow.md` method inventory and evidence now call `0x0046a760-0x0046a855` a non-emitting retained raw clone with blank emitter metadata, not the live BrowserWindow WndProc or a second callable callback/method; the 2026-06-28 change note repeats the live MCP no-route proof.
- [x] Scoped validators run and generated refresh observed; `auto-generated/NexusTK/browser/Browser.cpp` no longer has an Empty Emitter Marker for [UID:00020W]. Proof: validators completed with exit code `0` and `ok: 1`: target command `000000005073` at `2026-06-28T14:23:37-04:00`, Browser final command `000000005076` at `2026-06-28T14:24:57-04:00`, BrowserWindow final command `000000005077` at `2026-06-28T14:25:17-04:00`; intermediate support commands `000000005074`/`000000005075` were superseded by the final support wording cleanup. Generated refresh completed for each final command, `auto-generated/NexusTK/browser/Browser.cpp` header now has `validator-command-id: 000000005077`, and `rg "00020W|0x0046a760|BrowserRawWindowProcClone" auto-generated/NexusTK/browser/Browser.cpp` has no hits.
- [x] Leases used only for immediate implementation/validator batch and released. Proof: B010 leased `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`, `by-file/Browser.md`, and `by-class/BrowserWindow.md` immediately before editing/validation; `python .\tools\leaser\leaser.py B010 unlease ...` returned `Success` for all three paths after validation.

## Changed Files And Implementation Callback

Report-only pass:

- Created `tools/leaser/Agents/Agent-B010/research/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md`.

Implementation callback:

- Modified `by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md`.
- Modified `by-file/Browser.md`.
- Modified `by-class/BrowserWindow.md`.
- Modified this report checklist with implementation proof.

No generated files, project-level files, manual coverage reports, validator/tool state, IDA DB files, or MCP process state were manually edited by B010. Scoped validators refreshed generated output and validator-owned state as normal side effects of the requested `--wait-generated` validation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md","timestamp":"2026-06-28T14:27:37","uid":"00020W"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00020W-BrowserRawWindowProcClone-empty-emitter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/00020W-BrowserRawWindowProcClone-empty-emitter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00020W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
