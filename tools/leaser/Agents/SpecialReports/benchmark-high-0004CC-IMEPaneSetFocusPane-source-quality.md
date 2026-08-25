** TARGET-REPORT-UID:0004CC **
** AUTHOR-AGENT-ID:BENCH-HIGH **
** BENCHMARK-REASONING:high **

# 0004CC IMEPaneSetFocusPane Source-Quality Report

## Finalized Report / Current Recommendation

- Target: [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`
- Current recommendation: change UID0004CC from non-emitting/blank-C++ to an emitting [UID:00006H] `IMEPane` child with formal `IMEPane::SetFocusPane(Pane *pane, bool makeActive)` C++.
- Final disposition: current blank emitter/no-code state is no longer justified.
- Required action: update target metadata, add `EMITTER_UIDS:00006H`, add formal C++ body, and update support class/file docs to record the two-argument signature and List slot evidence.
- Confidence: strong for behavior, owner, route, and first-draft C++; medium-high for exact original spelling of the boolean parameter.

## Current Target State

- Current target page metadata:
  - `COMPLETION:82`
  - `CONFIDENCE:89`
  - `CANONICAL_OWNER:00006H`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:` blank
  - `RECONSTRUCTION_CPP CODE` blank
- Current generated state:
  - `auto-generated/-ag-research-tracker.md` lists UID0004CC at `82/89`, average `85.5`, reconstructable `true`, blank emitter, blank formal C++.
  - `auto-generated/-ag-memory-coverage.md` lists UID0004CC as `non-emits`, owner `00006H`, no emitter.
  - `auto-generated/-ag-coverage-report-by-memory.md` lists UID0004CC as `emits_code:false`.
  - `auto-generated/NexusTK/input/IMEPanes.cpp` refreshed at validator command id `000000004100`, `2026-07-01T17:45:51-04:00`, includes the [UID:00006H] class shell with `void SetFocusPane(Pane *pane);` but has no UID0004CC body.
- Current owner/source route:
  - Target owner is [UID:00006H] `IMEPane`.
  - Source route is [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes`.
  - [UID:00006H] currently clears `88/91`, emits through [UID:0000K5], and has class-level `[[CHILDREN]]`.
  - [UID:0000K5] currently clears `90/88`, has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/input/"`, and is a valid file emitter.

## Evidence Checked

IDA MCP session/provenance:

- Endpoint: `http://127.0.0.1:13337/mcp`.
- Initialized JSON-RPC session successfully; server reported `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` reported active database/session `supervisor_resume_20260629`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `14860`, not analyzing.
- `server_health` on `supervisor_resume_20260629` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

IDA MCP positive checks:

- `lookup_funcs`:
  - `0x004e80a0` -> `sub_4E80A0`, size `0x6b`.
  - `0x004e810b` -> not a function, confirming the exclusive endpoint is outside a modeled function.
  - `0x004e8110` -> not a function, matching the adjacent raw-helper page.
  - Neighbor functions: `0x004e7f20` size `0xd5`, `0x004e8000` size `0x98`, `0x004e81a0` size `0x5`.
- `analyze_function 0x004e80a0`:
  - Prototype: `void __thiscall(_DWORD *this, int, char)`.
  - Size: 107 bytes.
  - Callers: `sub_58DCE0`, `sub_58E140`, `sub_58EA80`, `sub_595390`.
  - Xrefs to target: `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, `0x00595463`.
  - No direct named callees because the body dispatches through the embedded `List` vtable.
- `disasm 0x004e80a0`:
  - Reads `focusPaneCount` at `this+0x110`.
  - Iterates backward from `focusPaneCount - 1`.
  - Reads the embedded list vtable from `this+0x104`.
  - Calls `List` virtual slot `+0x10`, dereferences the returned element slot, and compares it against the pane parameter.
  - Calls `List` virtual slot `+0x1c` with index and count `1` to remove the existing match.
  - If the byte argument is nonzero and the pane pointer is non-null, calls `List` virtual slot `+0x18` with count `1` and `&pane`.
  - Returns with `retn 8`, proving two explicit arguments after `this`.
- `xrefs_to 0x004e80a0`:
  - Exactly four code xrefs: `0x0058e0d9`, `0x0058e20c`, `0x0058ead9`, `0x00595463`.
- Caller decompilations:
  - `0x0058dce0` `TextEditPane` constructor calls `sub_4E80A0(g_pIMEPane, this, 1)` after `sub_544EA0(this, 1)` when the editor is focus-registerable.
  - `0x0058e140` `TextEditPane` destructor guards `g_pIMEPane` then calls `sub_4E80A0(g_pIMEPane, this, 0)` before inherited teardown.
  - `0x0058ea80` text edit editable/active mode setter calls `sub_4E80A0(g_pIMEPane, this, 1)` on active/editable entry and `sub_4E80A0(g_pIMEPane, this, 0)` on inactive/uneditable exit.
  - `0x00595390` `TextBoxPane` constructor calls `sub_4E80A0(g_pIMEPane, this, 0)` after `sub_544EA0(this, 0)`.
- `decompile 0x004e7f20`:
  - `IMEPane` constructor calls `List::List` at `this+0x104` with element size `4` and page size/capacity `4`, then zeroes child slots at `+0xf8/+0xfc/+0x100`.
- `decompile 0x004e8000`:
  - `IMEPane` destructor calls `List` destructor at `this+0x104`, clears `g_pIMEPane`, and tears down Pane base state.
- `get_bytes 0x0061ce2c`:
  - `List` vtable slots include `+0x10 -> 0x004f32b0`, `+0x18 -> 0x004f33c0`, `+0x1c -> 0x004f33e0`.
- `decompile 0x004f32b0`, `0x004f33c0`, `0x004f33e0`:
  - `0x004f32b0` is `List::GetElementAt`, returning the address of the indexed element storage.
  - `0x004f33c0` is `List::Append`, implemented as `InsertAt(m_count, count, source)`.
  - `0x004f33e0` is `List::RemoveAt`, moving later elements down and decrementing `m_count`.
- `get_bytes 0x004e810b`:
  - Bytes `0x004e810b-0x004e8110` are five `0xcc` alignment bytes after UID0004CC.
  - Bytes `0x004e8192-0x004e81a0` are fourteen `0xcc` alignment bytes after the adjacent raw helper.

Documentation/generated/report checks:

- Read target page `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Read [UID:00006H] `by-class/IMEPane.md`.
- Read [UID:0000K5] `by-file/IMEPanes.md`.
- Read [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
- Read [UID:00031G] `by-memory/0x004e8110-0x004e8192.IMEPaneFocusCaretAnchorHelper.md`.
- Read [UID:0001PS] `by-memory/0x0069b458-0x0069b45c.g_pIMEPane.md`.
- Read [UID:0000R7] `by-global/g_pIMEPane.md`.
- Read caller docs for [UID:0002ZY] `TextEditPaneConstructor`, [UID:0002ZZ] `TextEditPaneDestructor`, and [UID:0002RV] `TextBoxPaneConstructor`.
- Read generated lead `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Read generated lead `auto-generated/NexusTK/util/List.cpp`.
- Searched current docs and generated tracker/coverage with `0004CC`, `0x004e80a0`, `0x004e810b`, `IMEPaneSetFocusPane`, `SetFocusPane`, `IMEPane`, `IMEPanes`, `focusPaneList`, and `focusPaneCount`.
- Searched executed and active B-agent reports with `0004CC`, `0x004e80a0`, `0x004e810b`, `IMEPaneSetFocusPane`, and `SetFocusPane`.
- Matching old/central leads:
  - `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md` listed UID0004CC as an exact split child but did not provide a target-specific body.
  - `by-memory/-report.old.md` contains historical Wave2 lead text naming `IMEPane::SetFocusPane(Pane *pPane, bool makeActive)`, matching current IDA's two-argument shape and caller polarity. Treated as lead only.
  - `executed-b-agent-research/B004/0001JO-TextBoxPane-source-quality.md` and `B008/0002RV-TextBoxPaneConstructor-source-quality.md` support the TextBox constructor caller route.

Negative checks:

- No prior accepted target-specific UID0004CC B-report was found in executed B reports or active agent reports.
- `lookup_funcs 0x004e810b` reports not a function.
- `lookup_funcs 0x004e8110` reports not a function, so UID0004CC must not absorb the adjacent raw helper.
- `get_bytes` confirms `0x004e810b-0x004e8110` is `0xcc` padding; no hidden instruction bytes are left in the UID0004CC gap.
- `xrefs_to 0x004e80a0` reports only four direct code xrefs, all text-entry focus-management routes.
- Generated `IMEPanes.cpp` contains only the [UID:00006H] declaration `void SetFocusPane(Pane *pane);`; no body or generated UID0004CC marker is present.
- `entity_query` for names near the List code range found no current function symbols for List methods; generated `List.cpp` and current IDA behavior are used for source-facing names.
- `py_eval` MCP request failed with `Method 'py_eval' not found`; this was not needed because `get_bytes`, `lookup_funcs`, and decompile/disasm provided the required proof.
- Initial `get_bytes` schema attempts using `start/size` and then `regions.start` failed; corrected schema `regions=@{addr='...'; size=...}` succeeded. These failures did not affect evidence quality.

## Positive Evidence

- UID0004CC is a complete modeled function at `0x004e80a0`, size `0x6b`, with clean padding immediately after its exclusive endpoint.
- The body is source-authored method logic, not compiler glue: it implements a compact list update over a root IME focus list.
- The owner is strongly supported:
  - The function uses `this+0x104`/`this+0x110`, which current class and generated List evidence identify as the embedded `IMEPane::focusPaneList` and its count field.
  - `IMEPane` constructor initializes that embedded List at `this+0x104` with 4-byte elements and capacity/page size `4`.
  - `IMEPane` destructor destroys the same List.
  - Consumers in composition/candidate code use the same focus list/count to derive IME popup anchors.
- The second argument is proven:
  - IDA prototype has a byte-sized third machine parameter after `this` and pane pointer.
  - `TextEditPane` constructor and editable/active setter pass `1` to make the pane the current focus entry.
  - Destructor and inactive/uneditable paths pass `0` to remove without re-adding.
  - The target body tests the byte argument before appending.
- The current `IMEPane` and `IMEPanes` route is valid:
  - [UID:00006H] already emits through [UID:0000K5].
  - [UID:0000K5] is a valid file route to `NexusTK/input/IMEPanes.cpp`.
  - Generated `IMEPanes.cpp` already has class declarations and neighboring emitted IME methods.
- The body is small enough and the dependencies are documented enough for first-draft C++:
  - Uses only `Pane`, `List::GetElementAt`, `List::RemoveAt`, `List::Append`, `focusPaneCount`, and `focusPaneList`.
  - No strings, resources, packets, external globals beyond already documented caller-owned `g_pIMEPane`.

## Negative Evidence

- The current blank `EMITTER_UIDS` is a stale split-callback state, not a current evidence-backed no-code proof. The parent class and file route now clear the gate.
- The current class declaration is incomplete: it declares `void SetFocusPane(Pane *pane);`, but IDA and all callers prove `void SetFocusPane(Pane *pane, bool makeActive)`.
- TextEditPane, TextBoxPane, and self-save/text-edit helper callers are consumers, not owners. Their xrefs prove use of the IME focus-list API but do not move ownership out of `IMEPane`.
- `g_pIMEPane` is a singleton access path, not the direct owner of the method body. The actual state mutated is inside the `IMEPane` object.
- The broad aggregate [UID:000189] should not own the body directly; it is only a method-family container with child insertion.
- The adjacent raw helper [UID:00031G] starts at `0x004e8110` and is separate. UID0004CC must not absorb its focus-caret-anchor refresh logic.
- The exact original boolean parameter name is not proven. `makeActive` is the best current source-facing name because caller polarity and historical lead text support it, but it remains inferred.
- The current generated [UID:00018A] body uses `focusPaneList.GetAt(...)` as if it returns a pane pointer directly. Current IDA and generated `List.cpp` show `List::GetElementAt` returns an element slot address, so any future support cleanup should align focus-list reads as pointer-slot dereferences. This does not block UID0004CC because its exact body can express the dereference directly.

## Heuristic / Inference Reanalysis And Validation

- Field/member names:
  - `focusPaneList` is strongly supported by the `List::List(this+0x104, 4, 4)` constructor call, target List vtable dispatches, callers from text-entry focus paths, and popup-anchor consumers.
  - `focusPaneCount` is strongly supported as the List count at `focusPaneList +0x0c`, complete object `IMEPane +0x110`. It is an alias to the embedded List's `m_count`, not an independent source-authored field after the List object. Current docs should clarify this.
  - `focusCaretAnchorX/Y` are not written by UID0004CC but are the downstream consumers of the last-focused pane maintained here.
- Helper/API names:
  - `List::GetElementAt`, `List::Append`, and `List::RemoveAt` are supported by current generated `List.cpp`, current List vtable bytes, and current decompile of their bodies.
  - `SetFocusPane` is directly supported by class docs, old Wave2 lead, and current caller semantics.
  - `makeActive` is inferred but safe: the byte argument means "append this pane after removal" and is passed as `1` when text-entry focus should become active, `0` when the pane should be absent from the active focus list.
- Source-shape inference:
  - The method's binary shape is a normal hand-authored method over an embedded List. It should be emitted as C++ using the project `List` API, not as raw vtable dispatch.
  - Scanning backward is behaviorally relevant because duplicate stale entries may exist; the method removes the most recent matching entry first, then optionally appends the pane as the new last-focused entry.
  - It removes at most one matching entry, then breaks. Formal C++ must preserve that exact single-removal behavior.
  - It still scans/removes even when `pane == NULL`; only append is gated by `pane != NULL`. Formal C++ must not early-return on null before the removal loop.
- Rejected alternatives:
  - `registerFocus`: too broad and conflicts with `TextBoxPane` calling `SetFocusRegistration(false)` plus `SetFocusPane(this, false)`.
  - `addToFocusList`: mechanically accurate but less source-like than `makeActive`; the method always removes first and only conditionally appends.
  - `SetFocusPane(Pane *pane)` one-parameter signature: contradicted by `retn 8`, stack frame `arg_0/arg_4`, and all four callers.
  - No-code proof: invalid because the target is a normal function with a valid class/file route and source-level body.

## Ranked Owner / Source Placement Disposition

1. [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes`
   - Evidence for: mutates `IMEPane` embedded List at `+0x104/+0x110`; constructor/destructor initialize/destroy that List; callers use `g_pIMEPane`; class and file docs already route the family; [UID:00006H] has a generated class shell with `[[CHILDREN]]`.
   - Evidence against: current method declaration is missing the boolean parameter and target emitter is blank.
   - Decision: direct owner and emitter route. Update signature and emit UID0004CC through [UID:00006H].

2. [UID:0000K5] `IMEPanes` direct file owner
   - Evidence for: final generated source file owns the IME pane family.
   - Evidence against: the function is a class method using `this`; direct owner should be the class, not the file root.
   - Decision: file is only the final route through [UID:00006H].

3. [UID:0000R7]/[UID:0001PS] `g_pIMEPane`
   - Evidence for: all external callers reach the method through the singleton.
   - Evidence against: singleton storage does not own the method body; it only points at the object.
   - Decision: dependency/support evidence only.

4. TextEditPane/TextBoxPane/SelfSave caller owners
   - Evidence for: all direct callers are text-entry focus paths.
   - Evidence against: caller xrefs are consumers. The mutated storage and source family are in `IMEPane`.
   - Decision: rejected as owners; cite as caller evidence.

5. [UID:000189] aggregate
   - Evidence for: range containment and source-order context.
   - Evidence against: aggregate is not the narrow semantic owner and should not receive a broad body.
   - Decision: support/containment only.

## Score / Metadata Disposition

Recommended target metadata:

```text
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00006H | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Score rationale:

- Raise completion from `82` to `89` because the exact function body, signature, caller polarity, List operation mapping, boundary/padding, owner route, and formal C++ are now documented.
- Raise confidence from `89` to `91` because current IDA MCP directly proves the behavior and route, and generated `List.cpp` supports the container API names.
- Do not raise higher because:
  - The exact original spelling of the boolean parameter is inferred.
  - Current [UID:00006H] class shell represents `focusPaneCount` as if it were a separate member after `List`; evidence shows it is the embedded List count at `focusPaneList +0x0c`.
  - Current [UID:00018A] generated lead still has a focus-list dereference mismatch that should be cleaned up in a support pass.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Reason eligibility is now met:

- `RECONSTRUCTABLE:TRUE`.
- Recommended nonblank `EMITTER_UIDS:00006H`.
- [UID:00006H] emits through [UID:0000K5], a valid generated file route.
- Recommended score average is `(89 + 91) / 2 = 90`, above the current reconstruction-code gate.
- The body is small, exact, and has no unresolved external side effects beyond accepted `List` API names.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for UID0004CC:

```cpp
void IMEPane::SetFocusPane(Pane *pane, bool makeActive)
{
    for (int index = focusPaneCount - 1; index >= 0; --index) {
        Pane **entry = static_cast<Pane **>(focusPaneList.GetElementAt(index));
        if (*entry == pane) {
            focusPaneList.RemoveAt(index, 1);
            break;
        }
    }

    if (makeActive && pane != NULL) {
        focusPaneList.Append(1, &pane);
    }
}
```

Required support signature update in [UID:00006H] `IMEPane` class shell:

```cpp
void SetFocusPane(Pane *pane, bool makeActive);
```

Behavior preservation proof:

- Backward loop starts at `focusPaneCount - 1`, matching `mov esi, [ebx+110h]; sub esi, 1`.
- The loop calls List slot `+0x10`, dereferences the returned storage slot, compares it with `pane`, and decrements until negative.
- On a match, it calls `RemoveAt(index, 1)` once and breaks, matching slot `+0x1c` with pushed `1` and `index`.
- It tests the byte argument and pane pointer before appending, matching `cmp [arg_4], 0` then `cmp [arg_0], 0`.
- It appends exactly one pointer slot from the stack local `pane`, matching `lea edx, [arg_0]; push edx; push 1; call [List+0x18]`.
- It emits no explicit focus-count write because `List::RemoveAt` and `List::Append` update the embedded `m_count`.

No-code proof status: not applicable. The target is code-emitting and should no longer remain blank.

## Implementation-Ready Target / Support Doc Changes

Target doc: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`

- Change metadata to `COMPLETION:89`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`, preserve owner/reconstructable.
- Replace the current emitter note with a statement that the child now emits through [UID:00006H] into [UID:0000K5].
- Update behavior to the exact two-argument method: remove one existing matching pane from the embedded focus list, and append the pane as last focused only when `makeActive && pane != NULL`.
- Add raw evidence from MCP:
  - function `0x004e80a0`, size `0x6b`;
  - `retn 8` two-argument signature;
  - `focusPaneList +0x104`, `focusPaneCount/List::m_count +0x110`;
  - List slots `+0x10`, `+0x18`, `+0x1c`;
  - four callers and argument polarity;
  - `0x004e810b-0x004e8110` padding.
- Add the formal C++ block above.
- Update score rationale to explain why `89/91` is appropriate and why no 95+ score is recommended.

Support doc: `by-class/IMEPane.md`

- Change method declaration from `void SetFocusPane(Pane *pane);` to `void SetFocusPane(Pane *pane, bool makeActive);`.
- Clarify that `focusPaneList` stores `Pane *` entries and that `focusPaneCount` is the embedded List count at `focusPaneList +0x0c` / complete object `+0x110`.
- Add method note that UID0004CC now emits formal C++ and that the boolean argument controls whether the pane is appended as the current/last focused pane after removing any existing entry.

Support doc: `by-file/IMEPanes.md`

- Update the `IMEPane` proposed-contents row to say `SetFocusPane` is an emitting [UID:00006H] child with `Pane *pane, bool makeActive`, not only a non-emitting focus-list note.
- Add evidence note that current MCP proved the four callers and the List slot mapping.

Generated expectations:

- Do not edit generated files directly.
- After supervisor-approved implementation and scoped validation, `auto-generated/NexusTK/input/IMEPanes.cpp` should contain the UID0004CC marker/body under the `IMEPane` class route, and generated coverage should move UID0004CC out of `non-emits`.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0004CC is a modeled function at `0x004e80a0`, size `0x6b`, exclusive end `0x004e810b`. | Strong | MCP `lookup_funcs`, `disasm` | Target Evidence/Status | incorporate | proposed |
| C2 | The signature has two explicit arguments after `this`: `Pane *pane` and byte/bool `makeActive`. | Strong | MCP prototype, stack frame, `retn 8`, caller decompilations | Target Signature/Behavior; class shell | incorporate | proposed |
| C3 | The method scans the embedded focus list backward and removes one matching pane entry. | Strong | MCP disasm/decompile, List slot mapping | Target Behavior/C++ | incorporate | proposed |
| C4 | The method appends the pane only when `makeActive` is true and `pane` is non-null. | Strong | MCP disasm/decompile and caller polarity | Target Behavior/C++ | incorporate | proposed |
| C5 | `focusPaneList` starts at `IMEPane +0x104`; `focusPaneCount` is List `m_count` at complete object `+0x110`. | Strong | Constructor `List::List(this+0x104, 4, 4)`, List layout, target reads | Target Touched State; class observed state | incorporate | proposed |
| C6 | List slots used are `GetElementAt`, `Append`, and `RemoveAt`. | Strong | `get_bytes` List vtable, generated `List.cpp`, decompile of List methods | Target Evidence/C++ | incorporate | proposed |
| C7 | Direct callers are text edit constructor/destructor, text edit editable/active setter, and TextBox constructor. | Strong | MCP `xrefs_to` and caller decompiles | Target Callers; support docs | incorporate | proposed |
| C8 | Owner remains [UID:00006H] `IMEPane`; source route is [UID:00006H] -> [UID:0000K5]. | Strong | Class/file docs, object state, caller use through `g_pIMEPane` | Target metadata; source placement | incorporate | proposed |
| C9 | Blank emitter/no-code is stale and should be replaced by formal C++ through [UID:00006H]. | Strong | Current route clears gate; body exact; current generated non-emits row | Target metadata/C++ | incorporate | proposed |
| C10 | Score should become `89/91`, not 95+, because parameter spelling and support List/member source shape are still inferred. | Medium-high | Evidence completeness plus remaining naming/layout caveats | Target score rationale | incorporate | proposed |
| C11 | TextEdit/TextBox/SelfSave callers are consumers, not owners. | Strong | Mutated state is `IMEPane` List; callers only pass `g_pIMEPane` | Ownership analysis | incorporate | proposed |
| C12 | Adjacent [UID:00031G] raw helper remains separate and should not be merged into UID0004CC. | Strong | No function at `0x004e8110`, padding after UID0004CC, existing raw-helper page | Range/split notes | incorporate | proposed |

## Unchecked Implementation Tracking Checklist

- [ ] Supervisor validation required before implementation.
- [ ] Update target doc `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- [ ] Change UID0004CC metadata to `COMPLETION:89`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`, preserving `CANONICAL_OWNER:00006H` and `RECONSTRUCTABLE:TRUE`.
- [ ] Add the exact formal `IMEPane::SetFocusPane(Pane *pane, bool makeActive)` C++ block from this report to the target `RECONSTRUCTION_CPP CODE` block.
- [ ] Add target evidence for MCP session `supervisor_resume_20260629`, function size, signature, disassembly behavior, List slots, caller xrefs, and padding.
- [ ] Update [UID:00006H] `by-class/IMEPane.md` declaration to `void SetFocusPane(Pane *pane, bool makeActive);`.
- [ ] Update [UID:00006H] state notes to clarify the focus list stores `Pane *` entries and `focusPaneCount` is the embedded List count at complete object `+0x110`.
- [ ] Update [UID:0000K5] `by-file/IMEPanes.md` to record UID0004CC as an emitting `IMEPane` child and preserve List/caller evidence.
- [ ] Preserve rejected alternatives: TextEdit/TextBox caller ownership, global ownership, aggregate-only ownership, no-code proof, one-argument signature, and adjacent raw-helper merge.
- [ ] Preserve open score caps: boolean parameter spelling inferred; support List/member source shape not final-audit.
- [ ] Run scoped validator after accepted implementation only: `python .\tools\validator.py --mode file --file by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md --apply --queue-timeout 240`.
- [ ] Run scoped validators for support docs touched after accepted implementation only.
- [ ] Confirm generated refresh moves UID0004CC out of `non-emits` and inserts the UID0004CC body into `auto-generated/NexusTK/input/IMEPanes.cpp`.
- [ ] Update Claim And Incorporation Ledger verification states after implementation.

## Validator Results

- Validators were not run. The benchmark explicitly forbids validator commands because they can write generated/state files.

## Changed Files

- This report was saved to `source-3/project-documentation/tools/leaser/Agents/Agent-B014/research/benchmark-high-0004CC-IMEPaneSetFocusPane-source-quality.md`.
- No target/support by-* docs, generated files, coverage reports, project-level files, validator/tool state, supervisor ledgers, queues, archives, lock files, `goal.md`, `notes.md`, or IDA DB files were modified.

## Token / Usage

- token usage: unavailable
