** TARGET-REPORT-UID:00022F **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B011 Source-Quality Report: [UID:00022F] BuildFramePartPanes

Status: FINISHED report-only pass. No by-* documentation files and no `by-memory/-coverage-report.md` file were edited.

Target: `source-3/project-documentation/by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B011/research/00022F-BuildFramePartPanes-source-quality.md`

## Recommendation Summary

[UID:00022F] is source-authored frame-chrome setup code, not compiler-only glue and not a no-owner raw island. It should remain reconstructable and file-owned by [UID:0000JL] `FrameChrome`.

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 89
CANONICAL_OWNER: 0000JL
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000JL
```

The current blank C++ rationale is stale. Under the active project gate, the item has `RECONSTRUCTABLE:TRUE`, a valid emitter route through `FrameChrome`, and `(85 + 86) / 2 = 85.5`, so the old below-`95/95` reason is no longer a valid blocker. The route issue is real and should cap confidence, but it does not prove no-code. The body is a normal source-shaped helper with five fixed `Rect` setup blocks, five `FramePartPane` allocations/constructor calls, and five writes into frame-chrome slot storage.

Recommended source-facing helper name: keep `BuildFramePartPanes`. It matches the existing UID/page name, the older by-item index, and the neighboring `BuildAboveFrameBorder` naming pattern.

Recommended slot declaration direction: prefer one source-facing array, `g_framePartPanes[5]`, with documented index semantics. If the implementation callback wants individual names, use the same semantic order: top strip, left side, right side, lower-left piece, lower-right piece.

First-draft C++ is ready for the target page, with the unresolved direct-caller route recorded as a confidence cap.

## Evidence Checked

Process and policy files:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B011/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`

Target and support documentation:

- `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`
- `by-item/BuildFramePartPanes_004B7120.md`
- `by-file/FrameChrome.md`
- `by-class/FramePartPane.md`
- `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`
- `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`
- `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`
- `by-global/FrameChromeSlots.md`
- `by-type/by-vtable/FramePartPaneVtables.md`
- `by-memory/0x0061a7f8-0x0061a880.FramePartPaneVtableData.md`
- `by-memory/0x0069b364-0x0069b370.MainUiLayerSlotsHead.md`
- `by-global/MainUiLayerSlots.md`
- `by-memory/-coverage-report.md` read only for the exact pending row
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/ui/core/FrameChrome.cpp`

Prior related B-agent evidence checked:

- `tools/leaser/Agents/Agent-B002/research/00015O-FramePartPane-source-quality.md`

Cached analyzer / binary evidence checked:

- `source-3/core/data/cache/prewave/functions/0x004b7120.json`
- `source-3/core/data/cache/prewave/_bundles/decompiled/e1e53d25f1129da8d7cf2354562e5e02fc203a341c76050a3f34ee885d6f9566.json`
- `source-3/core/data/cache/prewave/functions/0x004b7480.json`
- `source-3/core/data/cache/prewave/_bundles/decompiled/8ca24c5285f0a933218af75ed788742dad54081d8d704511c2a4de92c96cb371.json`
- `source-3/core/data/cache/prewave/functions/0x004b7c50.json`
- `source-3/core/data/cache/prewave/_bundles/decompiled/5f355f0739ba5850b50f1ccf86cc876295cd28a14fdac8a9d0033c39bebe9629.json`
- `source-3/core/data/cache/prewave/functions/0x004b7e10.json`
- `source-3/core/data/cache/prewave/_bundles/decompiled/37ad1f6ba2de8534169434643e4963f47d03c42fed3d65809166eeaf8be78b63.json`
- Local PE bytes from `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- `python .\tools\validator.py --help` from `source-3/project-documentation` to confirm validator modes

No live IDA MCP server was used in this pass. The report relies on existing live-IDA documentation, local cached prewave exports, and a fresh local PE byte/reference scan.

## Binary Facts Rechecked

### Range, padding, and function object

Fresh local PE section mapping confirms:

- Image base: `0x00400000`.
- Target bytes map to `.text` and have length `0x1ff` / 511 bytes at `0x004b7120-0x004b731f`.
- Bytes before the helper at `0x004b7112-0x004b7120` are fourteen `0xcc` bytes.
- Byte at `0x004b731f` is `0xcc`, so the modeled function ends half-open at `0x004b731f`.
- The following raw cleanup body begins at `0x004b7320`; the PE bytes for `0x004b7320-0x004b73a3` are the known five-slot cleanup sequence, followed by thirteen `0xcc` bytes at `0x004b73a3-0x004b73b0`.

Cached analyzer metadata agrees:

- `0x004b7120` is `sub_4B7120`, size `511`, signatures `undefined __stdcall FUN_004b7120(void)` in Ghidra and `int()` in IDA.
- `num_callers` is `0` in both cached Ghidra/IDA metadata.
- Direct callees are only `0x004b7c50`, `0x004b7e10`, `0x004f4aa0`, `0x004b7480`, and `0x005c772f` security-cookie check.

### Body shape

The cached IDA decompilation is source-shaped and stable:

- Reuses one local rectangle object.
- Calls `sub_4B7C50(&rect, left, top, right, bottom)` to set the rectangle.
- Calls `sub_4B7E10(&rect, dx, dy)` to offset the rectangle.
- Calls `sub_4F4AA0(252)` for each allocation.
- If allocation succeeds, calls `FramePartPane::FramePartPane(storage, partIndex, &rect)`.
- Stores the returned pointer to one of the five slot globals.
- Stores null on allocation failure.

Constructor call refs from the PE disassembly are exactly:

- `0x004b718c -> 0x004b7480`
- `0x004b71e2 -> 0x004b7480`
- `0x004b723b -> 0x004b7480`
- `0x004b7294 -> 0x004b7480`
- `0x004b72f0 -> 0x004b7480`

Slot writes from the disassembly are:

- `0x004b719b`: stores slot `0x0069b33c`
- `0x004b71f1`: stores slot `0x0069b340`
- `0x004b724a`: stores slot `0x0069b344`
- `0x004b72a3`: stores slot `0x0069b348`
- `0x004b72f5`: stores slot `0x0069b34c`
- `0x004b72fc`: allocation-failure clear for slot `0x0069b34c`

The cached decompiler shows the complete five-item layout:

| Slot | Raw global | Recommended source role | Part index | Rect before offset | Offset |
| --- | --- | --- | ---: | --- | --- |
| 0 | `0x0069b33c` / `dword_69B33C` | `g_framePartPanes[0]`, top strip | 4 | `(0, 0, 198, 6)` | `(118, 12)` |
| 1 | `0x0069b340` / `dword_69B340` | `g_framePartPanes[1]`, left side | 0 | `(0, 0, 56, 93)` | `(14, 12)` |
| 2 | `0x0069b344` / `dword_69B344` | `g_framePartPanes[2]`, right side | 1 | `(0, 0, 57, 93)` | `(365, 12)` |
| 3 | `0x0069b348` / `dword_69B348` | `g_framePartPanes[3]`, lower-left piece | 2 | `(0, 0, 77, 37)` | `(14, 335)` |
| 4 | `0x0069b34c` / `dword_69B34C` | `g_framePartPanes[4]`, lower-right piece | 3 | `(0, 0, 79, 39)` | `(343, 333)` |

The semantic names are high-probability visual roles from the dimensions and offsets, not recovered symbols. The source declaration can safely use an array plus index comments without pretending the original names are proven.

### Rectangle helper names

`0x004b7c50` decompiles to:

```c
rect[0] = left;
rect[1] = top;
rect[2] = right;
rect[3] = bottom;
```

Recommended source-facing name: `Rect::Set` or `SetRect`. Behavior confidence is high; exact class/function spelling is medium because the generic helper has many callers and no final project-wide rectangle naming pass is cited here.

`0x004b7e10` decompiles to:

```c
rect[0] += dx;
rect[1] += dy;
rect[2] += dx;
rect[3] += dy;
```

Recommended source-facing name: `Rect::Offset` or `OffsetRect`. Behavior confidence is high; exact spelling is medium for the same reason.

### FramePartPane constructor relationship

`0x004b7480` decompiles as `FramePartPane::FramePartPane(this, int partIndex, Rect *bounds)`:

- Calls `Pane::Pane(this, 1)` via `0x00544460`.
- Writes three `FramePartPane` vtable views at `+0x00`, `+0xa0`, and `+0xa4`.
- Stores `partIndex` at `this + 0xf8`.
- Calls the pane attach/bounds helper `0x00544c70(this, bounds, 0, 0, dword_69B364)`.
- Registers for the notification tag `0x676f6f67` (`goog`) through `0x004f4b30(dword_67A740, this, tag, 0)`.

This proves the helper constructs actual `FramePartPane` objects and not generic panes or resource-only records. The `dword_69B364` attach argument is owned by the MainUiLayerSlots family, so the source draft should use a provisional layer/context dependency name rather than moving ownership of this helper to MainUiGraph.

### EH funclet implications

The target has normal MSVC EH scaffolding around the five allocation/constructor blocks:

- Disassembly begins with SEH/EH setup and pushes handler `0x005ff187`.
- PE byte scan found an absolute `0x005ff187` reference at `0x004b7126` inside the target prologue.
- Absolute references to funclet addresses appear in `.rdata`:
  - `0x005ff150` at `.rdata` VA `0x0065d45c`
  - `0x005ff15b` at `.rdata` VA `0x0065d464`
  - `0x005ff166` at `.rdata` VA `0x0065d46c`
  - `0x005ff171` at `.rdata` VA `0x0065d474`
  - `0x005ff17c` at `.rdata` VA `0x0065d47c`
- No rel32 call/jump targets those funclets.

These funclets are compiler-generated constructor-unwind cleanup support for the five `new`/constructor states. They should remain documented as compiler/EH implementation detail in the ignored MSVC funclet island, not as source-authored helpers and not as separate `BuildFramePartPanes` C++.

### Direct and indirect route search

Fresh local PE route scan results:

- No direct `call` or `jmp` rel32 references to `0x004b7120`.
- No absolute VA dword pattern for `0x004b7120` anywhere in the PE file.
- No RVA dword pattern for `0x004b7120` anywhere in the PE file.
- No direct `call` or `jmp` rel32 references to raw cleanup start `0x004b7320`.
- No absolute VA or RVA dword pattern for `0x004b7320`.
- Five direct rel32 calls to `0x004b7480` exist, all from inside this target.
- Absolute slot-address patterns exist only in the expected builder, raw cleanup, and notification clear code:
  - `0x0069b33c`: builder store, raw cleanup read/clear, notification clear
  - `0x0069b340`: builder store, raw cleanup read/clear, notification clear
  - `0x0069b344`: builder store, raw cleanup read/clear, notification clear
  - `0x0069b348`: builder store, raw cleanup read/clear, notification clear
  - `0x0069b34c`: builder store, builder allocation-failure clear, raw cleanup read/clear, notification clear

Conclusion: no static caller, VA table, RVA table, or raw cleanup route was recovered. This is stronger negative route evidence than the current target doc has. It supports a retained/dormant or currently un-routed frame-chrome factory caveat. It does not turn the body into compiler glue or no-code, because the body is still normal project source with fixed UI layout constants and object construction.

## Source-Quality Decisions

### Source-bearing versus no-code

Recommended decision: source-bearing, first-draft C++ ready.

Reasons:

- The target body contains hand-authored UI layout constants, not a vtable-only thunk, scalar deleting destructor, or SEH funclet.
- The code performs five high-level `new FramePartPane(partIndex, rect)` constructions and publishes the results into frame-chrome global state.
- The callee and slot lifecycle match `FramePartPane` constructor, cleanup, and notification support docs.
- Owner/emitter route already points to file UID `0000JL` and clears the active gate.
- The only compiler-generated pieces are the prologue/EH state tracking and external funclets; those should be documented and omitted from source C++.

Rejected no-code alternative:

- A no-code/compiler-glue classification would be appropriate for the EH funclets, scalar deleting destructor wrappers, or adjustor thunks, but not for this body. The body has no `this` adjustor pattern, no delete-flags parameter, no vtable-only dispatch role, and no ABI wrapper signature. It is an ordinary helper/factory.

### Direct owner and emitter

Keep:

```yaml
CANONICAL_OWNER: 0000JL
EMITTER_UIDS: 0000JL
```

Rationale:

- The helper has no object receiver and writes file-global frame-chrome state, so it is not directly owned by the `FramePartPane` class.
- It constructs `FramePartPane` objects, but construction of objects is not the same as method ownership.
- The global slot family and sibling `AboveFrame` builders are routed to `FrameChrome`.
- The `FRMPART` resource family, shared `goog` notification tag, and vtable/support docs all point to the visible frame-chrome module.

Rejected owner alternatives:

- `FramePartPane` class: too narrow for a free helper with no `this` and file-global writes.
- `MainUiGraph`: `dword_69B364` is a layer/context consumer dependency only; no caller from MainUiGraph to this helper was found.
- `FrameMgr`: no frame scheduling behavior here; it is pane construction/layout state.
- `ResourceLayoutTable` or EPF resource ownership: resources are used by `FramePartPane` paint/constructor support, but this helper does not own resource loading or layout lookup.
- `NONE`: too conservative. The body is project source and has a valid file-level owner/emitter route.

### Helper and slot names

Use `BuildFramePartPanes` as the final helper name unless a later symbol source proves a different original spelling. It is a good source-facing name and aligns with `BuildAboveFrameBorder`.

For globals, prefer:

```cpp
static FramePartPane* g_framePartPanes[5];
```

Recommended index comments or enum roles:

```cpp
// 0: top strip, 1: left side, 2: right side, 3: lower-left piece, 4: lower-right piece.
```

If implementation requires individual variables instead of an array, use:

- `g_pTopFramePartPane` for `0x0069b33c`
- `g_pLeftFramePartPane` for `0x0069b340`
- `g_pRightFramePartPane` for `0x0069b344`
- `g_pLowerLeftFramePartPane` for `0x0069b348`
- `g_pLowerRightFramePartPane` for `0x0069b34c`

Array form is the stronger source-modeling choice because the five slots are contiguous, built in a fixed sequence, deleted in a repeated sequence, and bulk-cleared by `FramePartPane::OnNotification`.

### First-draft C++ readiness

The target can emit first-draft C++ now. The route caveat should remain in prose; it should not keep the formal C++ block blank under the current gate.

Recommended formal C++:

```cpp
void BuildFramePartPanes()
{
    Rect rect;

    rect.Set(0, 0, 198, 6);
    rect.Offset(118, 12);
    g_framePartPanes[0] = new FramePartPane(4, rect);

    rect.Set(0, 0, 56, 93);
    rect.Offset(14, 12);
    g_framePartPanes[1] = new FramePartPane(0, rect);

    rect.Set(0, 0, 57, 93);
    rect.Offset(365, 12);
    g_framePartPanes[2] = new FramePartPane(1, rect);

    rect.Set(0, 0, 77, 37);
    rect.Offset(14, 335);
    g_framePartPanes[3] = new FramePartPane(2, rect);

    rect.Set(0, 0, 79, 39);
    rect.Offset(343, 333);
    g_framePartPanes[4] = new FramePartPane(3, rect);
}
```

Implementation notes:

- If accepted support docs prefer helper functions over methods, use `SetRect(rect, ...)` / `OffsetRect(rect, ...)`; behavior is the same.
- If accepted support docs prefer five named statics over an array, replace `g_framePartPanes[i]` with the individual source names above.
- Do not handwrite EH state variables, security-cookie checks, null-constructor branches, vtable writes, or unwind funclets. Those are compiler lowering for the C++ above.
- The custom/project `operator new` wrapper at `0x004f4aa0` returns through a null-check in the binary; source should still use normal `new FramePartPane(...)` unless the project-wide allocator declaration requires a nothrow spelling.

## Open Questions and Resolutions

1. Is there a direct or indirect live route to `0x004b7120`?

   Attempted resolution: checked cached function metadata, cached xrefs, PE rel32 `call`/`jmp` refs, absolute VA dwords, and RVA dwords. No route was found. Because there is no VA/RVA pointer to the entry, a normal callback/table route is also unsupported by current static bytes. Best-supported direction: document as retained/dormant or still-unrouted frame-chrome factory. Do not claim startup reachability.

2. Does the no-route state force no-code?

   Resolution: no. The no-route state caps confidence and should be visible in the target/status/coverage row. It does not reclassify source-shaped project code as compiler glue. The function has a normal source body and current owner/emitter gate is satisfied.

3. What is the final helper name?

   Resolution: use `BuildFramePartPanes`. It is source-facing, precise, already used by the canonical page and by-item index, and parallels `BuildAboveFrameBorder`. Alternatives like `CreateFramePartPanes` or `BuildFramePartPaneSlots` are plausible but have no stronger evidence.

4. Are the five globals individual variables or an array?

   Best-supported inference: source-facing `g_framePartPanes[5]` or array-equivalent storage. Evidence: contiguous dword range, uniform build/delete/clear lifecycle, and the notification handler bulk-clears all five. Raw addresses and exact index meanings should stay in docs because original declaration spelling is not proven.

5. What are the semantic part names?

   Best-supported inference from dimensions/offsets: top strip, left side, right side, lower-left piece, lower-right piece. The raw `partIndex` values are not in visual order because top strip uses part index `4`, while left/right/lower pieces use `0..3`. Do not rename the part indexes themselves until an asset-layout table names the FRMPART pieces.

6. What do the EH funclets mean?

   Resolution: compiler-generated constructor-unwind cleanup. They do not split the source helper and do not need direct C++ emission. The implementation callback should keep them as evidence only.

7. Does `dword_69B364` change owner/source placement?

   Resolution: no. `dword_69B364` is a MainUiLayerSlots layer/context dependency passed to `FramePartPane::FramePartPane`. It is not a caller or owner of this factory.

8. Should `FramePartPaneSlotCleanup` be merged with this helper?

   Resolution: no. `0x004b7320-0x004b73a3` is adjacent and lifecycle-related, but it is a separate raw cleanup body after an `0xcc` byte at `0x004b731f`. The target helper ends at `0x004b731f`; cleanup should remain [UID:00015N]. Support docs should explain that cleanup is source-level lifecycle behavior but still has its own raw/no-function/no-route caveat.

## Recommended Exact Doc Changes

### Target doc: `by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md`

Metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 89
CANONICAL_OWNER: 0000JL
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000JL
```

Replace stale C++/gate wording with:

```text
2026-06-19 B011 source-quality pass: the active source-C++ gate is satisfied by RECONSTRUCTABLE: TRUE, a valid FrameChrome emitter route, and an average score above 85. The old below-95/95 rationale is stale. Direct/static route remains unresolved and caps confidence, but it does not make this source-shaped factory no-code.
```

Add route evidence:

```text
Fresh PE/static route scan found no rel32 call/jump to 0x004b7120, no absolute VA pointer to 0x004b7120, no RVA pointer to 0x004b7120, and no equivalent route to raw cleanup start 0x004b7320. The only entry-local absolute compiler pointer is the EH handler 0x005ff187 pushed at 0x004b7125. EH funclet pointers at 0x0065d45c, 0x0065d464, 0x0065d46c, 0x0065d474, and 0x0065d47c target 0x005ff150, 0x005ff15b, 0x005ff166, 0x005ff171, and 0x005ff17c as constructor-unwind compiler support.
```

Update helper mapping:

```text
Source-facing helper mapping: sub_4B7C50 is a Rect set helper; sub_4B7E10 is a Rect offset helper; sub_4F4AA0 is the MemoryMan-backed operator new wrapper; sub_4B7480 is FramePartPane::FramePartPane(int partIndex, const Rect& bounds).
```

Update the slot table to add source-facing names:

```text
Prefer source-facing g_framePartPanes[5] with index roles:
- [0] 0x0069b33c: top strip, part index 4, rect (0,0,198,6), offset (118,12).
- [1] 0x0069b340: left side, part index 0, rect (0,0,56,93), offset (14,12).
- [2] 0x0069b344: right side, part index 1, rect (0,0,57,93), offset (365,12).
- [3] 0x0069b348: lower-left piece, part index 2, rect (0,0,77,37), offset (14,335).
- [4] 0x0069b34c: lower-right piece, part index 3, rect (0,0,79,39), offset (343,333).
```

Populate `RECONSTRUCTION_CPP` with the first-draft C++ block from this report, adjusted only for accepted project-wide spellings of `Rect`, `Set`, `Offset`, and the slot array.

### Support doc: `by-file/FrameChrome.md`

Recommended additions:

- State that `BuildFramePartPanes` is a source-authored file-level frame-chrome factory ready for first-draft C++ under the current gate.
- Preserve the unresolved no-static-caller caveat with the stronger PE evidence: no rel32 call/jump, no absolute VA pointer, and no RVA pointer to `0x004b7120`.
- Clarify that no-route means retained/dormant or still-unrouted construction, not compiler glue.
- Add `g_framePartPanes[5]` as the preferred source-facing slot-family name while preserving exact addresses and provisional status.

No `FrameChrome` score change is required from this report alone, though a small confidence increase would be defensible after implementation if the page is updated.

### Support doc: `by-class/FramePartPane.md`

Recommended additions:

- Add the constructor relationship: `BuildFramePartPanes` calls `FramePartPane::FramePartPane(int partIndex, const Rect& bounds)` five times with part indexes `4,0,1,2,3`.
- State that builder liveness remains unresolved but no longer blocks first-draft source for the file-level builder or class methods under the active gate.
- Keep class ownership for methods/vtables; do not move the builder into the class.

### Support doc: `by-memory/0x004b73b0-0x004b7661.FramePartPane.md`

Recommended additions:

- Update stale below-`95/95` wording if touched. The current blocker for unresolved details is exact method/helper spelling and lifecycle route confidence, not an obsolete 95/95 threshold.
- Refer to `g_framePartPanes[5]` as the source-facing slot family for notification clears.
- Preserve the compiler-only status of adjustor thunks and scalar deleting destructor wrappers.

### Support doc: `by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md`

Recommended additions:

- Replace stale below-`95/95` final-code wording with current gate analysis.
- Add `g_framePartPanes[5]` as the preferred source-facing declaration.
- Add semantic index roles and preserve raw addresses.
- Keep the live construction route caveat, now strengthened by the PE no-VA/no-RVA/no-rel32 scan.

### Support doc: `by-global/FrameChromeSlots.md`

Recommended additions:

- Prefer `g_framePartPanes[5]` for the five-slot family.
- Clarify that IDA `FF` bytes remain unbacked-tail/initializer caveat and do not affect the builder C++.
- Keep ownership on `FrameChromeSlots`/`FrameChrome`, not `MainUiGraph` or `ResourceLayoutTable`.

### Support doc: `by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md`

Recommended additions if touched:

- Replace stale below-`95/95` wording. A better current rationale for blank C++ is: raw no-function body, no direct/VA/RVA route to the raw start, and still-unresolved exact source representation for this separate cleanup path.
- Keep it separate from [UID:00022F]. It starts after a `0xcc` byte and has no modeled function object.
- State that its behavior is source-level frame-chrome lifecycle cleanup, but it is not part of `BuildFramePartPanes` formal C++.

### Support doc: `by-item/BuildFramePartPanes_004B7120.md`

Recommended additions:

- Keep the by-item page non-reconstructable as an index.
- Point to [UID:00022F] as the canonical code-emitting page.
- Update wording from "final C++ blank" to "canonical by-memory page is ready for first-draft C++; route still unresolved."

## Score Rationale

Completion `88`:

- Adds current gate analysis and first-draft source readiness.
- Resolves helper/source name direction.
- Resolves rectangle helper behavior.
- Resolves best source-facing slot declaration and semantic index roles.
- Adds stronger no-route proof through local PE scan.
- Keeps exact range, padding, callee set, constructor refs, slot lifecycle, allocation-failure path, and EH funclet caveat.
- Still below `90` because no direct/static route to the helper was recovered and original global/helper names remain inferred rather than symbol-proven.

Confidence `89`:

- Strong agreement across existing live-IDA docs, cached prewave decompilation, local PE disassembly, and support pages.
- Capped below `90` because route/liveness is genuinely unresolved and no original source symbols were recovered for the five slots.

## Exact Pending Coverage Text

Do not edit `by-memory/-coverage-report.md` in the B-agent report pass. If the supervisor accepts implementation, replace the [UID:00022F] row with:

```text
    - [UID:00022F][0x004b7120-0x004b731f.BuildFramePartPanes](by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md) 0x004b7120-0x004b731f | function | BuildFramePartPanes : reconstructable : 88% : strong : B011 source-quality pass resolves this as a source-authored FrameChrome factory ready for first-draft C++: five unrolled Rect set/offset blocks, MemoryMan-backed `operator new(0xfc)` allocation, `FramePartPane(partIndex, rect)` construction, writes to source-facing `g_framePartPanes[0..4]` / raw `0x0069b33c-0x0069b34c`, and EH funclets identified as compiler constructor-unwind glue; stale 95/95 wording should be replaced by the current combined-score gate, while no direct rel32/VA/RVA route to the factory remains the confidence cap.
```

If the implementation callback also updates support rows for [UID:00015N] or [UID:0001PF], the supervisor should generate those rows separately from the support doc changes. This report only requires the exact [UID:00022F] replacement row.

## Validator Needs After Implementation

Expected validation commands from `source-3/project-documentation` if the implementation callback touches the target plus the recommended support docs:

> Executable block R001 was removed from this report and preserved verbatim in [00022F-BuildFramePartPanes-source-quality-removed.md](00022F-BuildFramePartPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row:

> Executable block R002 was removed from this report and preserved verbatim in [00022F-BuildFramePartPanes-source-quality-removed.md](00022F-BuildFramePartPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Because the target recommendation populates formal C++ and should change `auto-generated/NexusTK/ui/core/FrameChrome.cpp` from an empty marker to emitted code, also run:

> Executable block R003 was removed from this report and preserved verbatim in [00022F-BuildFramePartPanes-source-quality-removed.md](00022F-BuildFramePartPanes-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result: each file-mode validator returns success with updated UID references/metadata only for touched files; autogen refresh should keep [UID:00022F] routed to `auto-generated/NexusTK/ui/core/FrameChrome.cpp`.

No validators were run against target/support docs in this report-only pass.

## IDA Rename, Type, and Comment Recommendations

High confidence:

- Rename `sub_4B7120` to `BuildFramePartPanes`.
- Type `0x004b7480` as `FramePartPane *__thiscall FramePartPane::FramePartPane(FramePartPane *this, int partIndex, const Rect *bounds)` or the local class-method equivalent.
- Add a function comment at `0x004b7120`: "FrameChrome helper: builds five FramePartPane globals; no static caller recovered in current binary."
- Mark/comment `0x005ff150`, `0x005ff15b`, `0x005ff166`, `0x005ff171`, `0x005ff17c` as compiler-generated constructor-unwind funclets for `BuildFramePartPanes`, not source methods.

Medium-high confidence:

- Create an array type at `0x0069b33c`: `FramePartPane *g_framePartPanes[5]`.
- Add per-index comments: top strip, left side, right side, lower-left piece, lower-right piece.

Behavior high, exact spelling medium:

- Rename/comment `sub_4B7C50` as `Rect::Set` / `SetRect`.
- Rename/comment `sub_4B7E10` as `Rect::Offset` / `OffsetRect`.

Do not:

- Rename `0x004b7120` as a `FramePartPane` method.
- Promote the EH funclets as source helpers.
- Move the slot family to `MainUiGraph`, `FrameMgr`, or `ResourceLayoutTable`.

## Implementation Checklist

1. Edit only after supervisor implementation callback.
2. Update target metadata to `88/89`, with owner/emitter unchanged.
3. Replace stale below-`95/95` wording with current gate analysis.
4. Insert the source-ready `BuildFramePartPanes` C++ block, using accepted `Rect` and slot names.
5. Add route evidence: no direct rel32, no absolute VA, no RVA pointer to `0x004b7120`; no equivalent route to `0x004b7320`.
6. Add EH funclet note: compiler constructor-unwind only.
7. Add source-facing slot table with `g_framePartPanes[5]` and semantic roles.
8. Update support docs listed above if supervisor includes them in the callback.
9. Do not edit `by-memory/-coverage-report.md` directly unless the supervisor explicitly assigns that shared-file change.
10. Run the scoped validators and autogen refresh listed in this report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/00022F-BuildFramePartPanes-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"00022F"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022F-BuildFramePartPanes-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/00022F-BuildFramePartPanes-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022F"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
