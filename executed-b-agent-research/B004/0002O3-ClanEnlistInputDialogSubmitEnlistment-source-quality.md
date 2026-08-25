** TARGET-REPORT-UID:0002O3 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Source-Quality Report: [UID:0002O3] ClanEnlistInputDialogSubmitEnlistment

Agent: B004  
Date: 2026-06-19  
Assignment id: `B004-goal2-clan-enlist-submit-source-quality-0002O3-20260619`  
Target: `source-3/project-documentation/by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`  
Report-only pass: no by-* documentation, generated files, IDA DB, project-level reports, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

- Current recommendation: replace the stale no-C++/source-quality blocker with a class-owned, first-draft-ready virtual submit method.
- Final disposition: keep `RECONSTRUCTABLE:TRUE`; change direct owner/emitter from file [UID:0000I8] `Clan` to class [UID:00002B] `ClanEnlistInputDialog`, while preserving generated source routing through [UID:0000I8] `NexusTK/social/Clan.cpp`.
- Recommended metadata: `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:00002B`, `EMITTER_UIDS:00002B`.
- Recommended source-facing method: inferred/descriptive `int ClanEnlistInputDialog::OnSubmitEnlistment()`.
- Recommended helper API direction: keep durable helper label `SendClanAttributePacket`, but document the ABI/source-shape evidence for a status-pane/context call. The strongest source-facing API is `g_pClanStatusPane->SendClanAttributePacket(...)` / `ClanStatusPane::SendClanAttributePacket(...)`, because prior raw-byte evidence shows `ECX = dword_67ADE4` immediately before the call and [UID:00010E] pops four stack arguments. If the helper remains a file-local free helper in current docs, use an explicit context-argument variant consistently with the existing `SendClanLeaveResponse(g_pClanStatusPane, ...)` reconstruction style.
- First-draft C++: ready. The remaining original UI-label/member spelling uncertainty should cap the score below final-audit quality, but it no longer blocks a source-shaped method body under the active 85/85 gate.

## Target

- Target UID: `0002O3`
- Target path: `source-3/project-documentation/by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`
- Current target scores: `COMPLETION:84`, `CONFIDENCE:90`
- Current target owner/emitter: `CANONICAL_OWNER:0000I8`, `EMITTER_UIDS:0000I8`
- Current target state: `RECONSTRUCTABLE:TRUE`, blank formal C++.
- Current coverage row summary: exact vtable-only submitter, no direct callers, sole `SendClanAttributePacket` callee, four inherited fields at `+0x26c/+0x46c/+0x66c/+0x86c`, adjacent alignment, and Clan parent attachment.

## Evidence Checked

Read and used as controlling workflow/documentation evidence:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B004/goal.md`
- Target by-memory page [UID:0002O3].
- [UID:00002B] `by-class/ClanEnlistInputDialog.md`
- [UID:000024] `by-class/ClanAttrInputDialog.md`
- [UID:00010L] `by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md`
- [UID:00010E] `by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md`
- [UID:00021W] `by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md`
- [UID:00010M] `by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md`
- [UID:0002MN] `by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md`
- [UID:0001TY] `by-type/by-struct/ClanInputDialogLayouts.md`
- [UID:0000I8] `by-file/Clan.md`
- [UID:0000IA] `by-file/ClanDialogs.md`
- Sibling/precedent docs [UID:0002O5] `ClanChangeInputDialogSubmitClanChange`, [UID:00010F] `SubmitClanChangeHelper`, and accepted first-draft submitter pages such as [UID:0002NS] and [UID:0002NW].
- Exported function data `resources/exported_data/functions/0x00489fc0.json` and `resources/exported_data/functions/0x00485ac0.json`.
- Exported vtable data `resources/exported_data/master_vtables.json` around the `0x00489fc0` slot.
- Current generated memory route row from `auto-generated/-ag-memory-coverage.md`.
- Prior same-target B-agent report `Agent-B003/research/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md` as a lead, rechecked against current docs/exported data. I did not copy its conclusions blindly: the current B004 checks reconfirmed the exported function/vtable/caller facts and support-doc state. The prior local PE raw-byte scan remains the source for the exact instruction-level `ECX = dword_67ADE4` observation, because a fresh read of the external read-only PE at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` failed with access denied in this session.

## IDA / Exported Function Facts

Function/range facts:

- `resources/exported_data/functions/0x00489fc0.json` reports address `0x00489fc0`, IDA name `sub_489FC0`, Ghidra name `virt_meth_0x489fc0`, and size `41` bytes, so the half-open range is exactly `0x00489fc0-0x00489fe9`.
- Ghidra signature is `undefined __thiscall virt_meth_0x489fc0(ClanEnlistInputDialog * this)`.
- IDA signature is `int __thiscall(int this)`.
- Ghidra decompiles the body as a `void` method calling `FUN_00485ac0` with four fields from the embedded `ClanAttrInputDialog` base.
- IDA decompiles the body as returning `sub_485AC0((LPCWCH)(this + 620), (LPCWCH)(this + 1132), (const WCHAR *)(this + 1644), *(_WORD *)(this + 2156))`.
- The decompiler return-type disagreement is expected for this kind of tiny virtual callback. It does not change the behavior: source may use `int` consistently with accepted sibling `OnSubmitText` pages because the method preserves/returns the send helper result; a future final class-declaration audit could still decide the base slot is logically `void` if callers ignore `EAX`.

Vtable/caller facts:

- `xrefs_to` for `0x00489fc0` reports a single data xref from `0x00615e54`.
- `resources/exported_data/master_vtables.json` places `0x00489fc0` at vtable index `23`, offset `92` (`+0x5c`) in the `ClanEnlistInputDialog` primary vtable.
- Ghidra callers list is empty; there are no direct code callers in exported caller data.
- The current target and aggregate docs also record no direct callers and a vtable-only route.
- [UID:00010L] `ClanAttrInputDialogCore` documents that `OnDialogAction` collects controls `8`, `9`, and `10`, stores submitted values, dispatches the primary vtable slot `+0x5c`, and then closes the dialog. This is the direct source-level call context for `0x00489fc0`.

Callee/helper facts:

- `resources/exported_data/functions/0x00489fc0.json` reports one callee: `0x00485ac0` / `FUN_00485ac0`.
- `resources/exported_data/functions/0x00485ac0.json` reports [UID:00010E] size `510` (`0x1fe`), one caller from `0x00489fc0`, and IDA xref from `0x00489fe3`.
- [UID:00010E] serializes opcode `0x4b`, subtype `6`, action `2`, then three CP_ACP/WideCharToMultiByte string payloads with one-byte converted lengths and a final big-endian 16-bit value through `0x005753a0`.
- [UID:00010E] sends through `sub_574BB0((_BYTE *)dword_67A7EC, &Src, payloadEnd + 2)`, tying the helper to [UID:0001P0] `g_packetSender`.
- Prior B003 local PE scan records exact target instructions:

```asm
0x00489fc0: movzx eax, word ptr [ecx + 0x86c]
0x00489fc7: push  eax
0x00489fc8: lea   eax, [ecx + 0x66c]
0x00489fce: push  eax
0x00489fcf: lea   eax, [ecx + 0x46c]
0x00489fd5: push  eax
0x00489fd6: lea   eax, [ecx + 0x26c]
0x00489fdc: mov   ecx, dword ptr [0x67ade4]
0x00489fe2: push  eax
0x00489fe3: call  0x00485ac0
0x00489fe8: ret
```

This report treats that instruction listing as prior PE evidence, not as a fresh B004 byte read. The exported data independently confirms the size, vtable ref, field arguments, and call target. The `ECX` load should be revalidated in IDA during implementation if the supervisor wants to decide between member-call and free-helper spelling in the formal C++ block.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct parent now | Recommended parent | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00489f80-0x00489fb5` | [UID:00021W] `ClanEnlistInputDialogRawConstructor` | raw constructor-shaped bytes | true | [UID:00002B] | unchanged | Constructor identity is class-owned but no direct function/xref route; formal C++ remains blank there. |
| `0x00489fb5-0x00489fc0` | ignored padding | alignment | ignored | n/a | unchanged | Eleven `0xcc` bytes before submitter. |
| `0x00489fc0-0x00489fe9` | [UID:0002O3] target | vtable-backed submit override | true | [UID:0000I8] file | [UID:00002B] class | Should become class-owned/emitted and first-draft C++ ready. |
| `0x00489fe9-0x00489ff0` | ignored padding | alignment | ignored | n/a | unchanged | Seven `0xcc` bytes before `ClanChangeInputDialog` raw constructor. |
| `0x00489fc0-0x0048a0be` | [UID:00010M] aggregate | submitter/raw-constructor/leave callback index | false | none | unchanged | Non-emitting aggregate; exact children carry decisions. |

## Submitted Field Analysis

The four target arguments are inherited `ClanAttrInputDialog` submitted-field storage, not local variables or raw packet offsets. They are populated by [UID:00010L] before the derived submit slot is invoked.

| Offset | Decimal | Current evidence | Recommended descriptive member name | Confidence |
| --- | ---: | --- | --- | --- |
| `+0x26c` | `620` | Constructor stores the first packet-supplied wide string here; both target [UID:0002O3] and sibling [UID:0002O5] pass its address as the first helper argument. | `m_submittedClanName` | High for role as first persistent submitted string / clan-name field; medium-high for exact noun because original UI label is not recovered. |
| `+0x46c` | `1132` | `ClanAttrInputDialog::OnDialogAction` copies control id `8` here before dispatch; target passes it as second helper argument. | `m_submittedDescriptionText` | Medium; current docs identify this as second editable submitted text, and `description` is the best source-level semantic direction for enlist/change attributes. |
| `+0x66c` | `1644` | `OnDialogAction` copies control id `9` here; target passes it as third helper argument. | `m_submittedAttributeText` | Medium; `attributeText` is stronger than raw `field_66c`, but exact label could be a flag/motto/profile field. Do not use an original-looking name without a caveat. |
| `+0x86c` | `2156` | `OnDialogAction` parses control id `10` into this 16-bit field; target passes it by value. | `m_submittedAttributeType` | High for 16-bit type/value; exact source name may be `type`, `attributeType`, or another UI noun. |

Recommendation: use these descriptive member names in first-draft C++ and document them as inferred/descriptive. Leaving raw offsets or `field_` names in the formal source body is no longer justified for a mid-2000s source-style draft.

## Heuristic / Inference Reanalysis And Validation

### Method Name / Virtual Signature

- Evidence checked: target title, exported signatures, `ClanAttrInputDialogCore` dispatch behavior, vtable offset `+0x5c`, sibling accepted `ClanNameInputDialog` submitter pages, and `ClanLeaveConfirmDialog` callback naming.
- Best inference: `ClanEnlistInputDialog::OnSubmitEnlistment()`.
- Return type recommendation: `int` for this method body's first draft, matching the accepted clan text/money submitter pages that return the packet send helper result. The Ghidra `void` output and likely ignored caller result should be documented as a final-declaration caveat, not as a blocker.
- Rejected names:
  - `sub_489FC0`: compiler/generated placeholder only.
  - `SubmitEnlistment` alone: acceptable page title/behavior label, but less source-shaped than an override name.
  - `OnSubmitText(const wchar_t *)`: wrong base family. This is not a `ClanNameInputDialog` one-field text submitter; `ClanAttrInputDialog` dispatches a no-argument confirmation slot after storing three submitted controls.
  - `ParseClanAttributePacket` / `HideAllControls`: stale Wave2/status-handler ownership from the class page, already rejected by current docs because those functions operate on `ClanStatusPane`.

### Helper Name / API

- Evidence checked: [UID:00010E] helper doc, exported helper signature, sole call from `0x00489fe3`, predecessor subtype-6 action-0/action-1 helper docs, sibling `SendClanLeaveResponse` callback C++ precedent, [UID:0002XH]/[UID:0002XG] `g_pClanStatusPane`, and prior B003 PE instruction listing.
- Best helper name: keep `SendClanAttributePacket` as durable page/helper name. It accurately captures subtype-6/action-2 attribute/enlistment packet behavior and avoids premature rename churn.
- Best helper API direction: source-facing `ClanStatusPane::SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)` is the strongest ABI explanation if the `ECX = g_pClanStatusPane` load is accepted. The body can still not reference `this`, causing decompilers to show `__stdcall` with four stack arguments.
- Acceptable implementation compromise: if the project wants to keep packet helpers as file-local functions, use an explicit context first argument consistently with existing `SendClanLeaveResponse(g_pClanStatusPane, 1)` formal C++ style:

```cpp
SendClanAttributePacket(g_pClanStatusPane, ...);
```

- Rejected helper directions:
  - Rename to `SubmitClanChangeHelper`: wrong subtype and wrong sibling. [UID:00010F] handles subtype `10`, action `2`; [UID:00010E] handles subtype `6`, action `2`.
  - Treat as a generic URL/string/packet utility: no; sole caller, opcode `0x4b`, subtype `6`, and address adjacency place it in Clan packet helpers.
  - Treat `dword_67ADE4` as an extra explicit stack argument in the binary: no; prior raw bytes show it in `ECX`, while exported helper data shows four stack arguments. Model it as hidden/context receiver or as project-style explicit context in source, not as a fifth stack push.

### Owner / Emitter / Source Placement

- Evidence checked: target xref `0x00615e54`, [UID:00002B] class scores and method table, [UID:00021W] constructor owner/emitter, [UID:0000I8] Clan file route, [UID:0000IA] ClanDialogs split candidate, [UID:0002MN] vtable data, [UID:00010M] aggregate, and current generated memory route rows.
- Best direct owner: [UID:00002B] `ClanEnlistInputDialog`.
- Best emitter: [UID:00002B] `ClanEnlistInputDialog`. Generated output still resolves to `auto-generated/NexusTK/social/Clan.cpp` through the class-to-file route.
- Rejected alternatives:
  - Direct [UID:0000I8] file ownership: too broad for an exact class virtual method. It was a useful parent during earlier routing but should be replaced now that the class page clears the gate.
  - [UID:00010M] aggregate ownership: aggregate is non-reconstructable/non-emitting and deliberately indexes exact child pages.
  - [UID:000024] `ClanAttrInputDialog`: base owns the submitted-field storage and dispatch, but the vtable cell is `ClanEnlistInputDialog`'s override slot.
  - [UID:0000IA] `ClanDialogs`: still a source split candidate, but current docs keep it lower-confidence/provisional. Do not route this target to a candidate split while [UID:0000I8] remains the stronger source root.
  - No-owner/non-emitting: not defensible. The exact class vtable slot, class page, and source route satisfy the gate.

### Reachability / Liveness

- Evidence checked: exported xrefs/callers, target docs, aggregate docs, vtable data, generated coverage row, prior PE scan.
- Best conclusion: target is live via vtable-only dispatch from `ClanAttrInputDialog::OnDialogAction`; no direct code callers are expected.
- Positive route: `ClanAttrInputDialog::OnDialogAction` OK path stores controls `8/9/10`, dispatches primary slot `+0x5c`, `ClanEnlistInputDialog` primary vtable cell `0x00615e54` points to `0x00489fc0`, then the target calls [UID:00010E].
- Negative evidence: no direct branch/call references to `0x00489fc0` in exported caller data; prior B003 PE scan found no direct branches and one VA dword hit at `0x00615e54`.
- Impact: vtable-only reachability is sufficient for reconstructable/emitting method status; it should not be treated as a no-route/raw helper caveat.

### Range / Split / Neighbor

- Evidence checked: target size `0x29`, aggregate child table, constructor neighbor [UID:00021W], successor [UID:0002O4], padding docs.
- Best conclusion: no split or merge is needed for [UID:0002O3]. The half-open function range `0x00489fc0-0x00489fe9` is exact.
- Neighbor relationship: preceding [UID:00021W] raw constructor ends at `0x00489fb5`, eleven bytes of `0xcc` padding end at `0x00489fc0`; target ends at `0x00489fe9`, seven bytes of `0xcc` padding end at `0x00489ff0`; [UID:0002O4] `ClanChangeInputDialogRawConstructor` begins at `0x00489ff0`.
- Rejected merge: do not merge with [UID:00010M] aggregate; the aggregate is intentionally non-emitting.

### First-Draft C++ Readiness

- Evidence checked: current score/route, class parent score, helper score, field/source route, sibling first-draft methods, current code gate in B004 goal, and remaining uncertainties.
- Gate result: target already qualifies numerically (`RECONSTRUCTABLE:TRUE`, nonblank emitter route, `(84 + 90) / 2 = 87`). After this research, class owner/emitter and descriptive names are strong enough for first-draft C++.
- Remaining caveats: exact original member names and exact helper declaration style are not final; this caps scores below final-audit quality but does not block an initial source-style body.

## Recommended First-Draft C++

Preferred ABI/source-shape draft if [UID:00010E] is documented as a status-pane method or context call:

```cpp
int ClanEnlistInputDialog::OnSubmitEnlistment()
{
    return g_pClanStatusPane->SendClanAttributePacket(
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}
```

Project-style fallback if [UID:00010E] remains a file-local helper with explicit context, matching existing `SendClanLeaveResponse(g_pClanStatusPane, ...)` formal C++ style:

```cpp
int ClanEnlistInputDialog::OnSubmitEnlistment()
{
    return SendClanAttributePacket(
        g_pClanStatusPane,
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}
```

Strict four-argument fallback if the supervisor decides to ignore the `ECX` context load until [UID:00010E] is separately audited:

```cpp
int ClanEnlistInputDialog::OnSubmitEnlistment()
{
    return SendClanAttributePacket(
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}
```

B004 recommendation for implementation: use the first form if support docs accept the `ClanStatusPane::SendClanAttributePacket` API direction; otherwise use the second form and explicitly document it as a reconstruction convention for the hidden `g_pClanStatusPane` context. Do not leave the formal C++ block blank.

## Recommended Exact Target Changes

Target metadata:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00002B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00002B | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Target title/body should identify the method as:

```text
`ClanEnlistInputDialog::OnSubmitEnlistment()`, the `ClanAttrInputDialog` confirmation-slot override for the enlistment dialog.
```

Replace the stale no-code rationale with:

```text
This target clears the active first-draft C++ gate: it is reconstructable, has a confirmed class emitter route through [UID:00002B] `ClanEnlistInputDialog` to [UID:0000I8] `NexusTK/social/Clan.cpp`, and its exact body is a single source-shaped submit call using inherited fields populated by [UID:00010L]. Remaining original member/helper spelling uncertainty caps the score below final-audit quality but no longer blocks first-draft C++.
```

Add behavior detail:

```text
The method forwards the inherited DLGCLAN2 submitted fields to [UID:00010E] `SendClanAttributePacket`: `m_submittedClanName` at `this+0x26c`, `m_submittedDescriptionText` at `this+0x46c`, `m_submittedAttributeText` at `this+0x66c`, and `m_submittedAttributeType` at `this+0x86c`. The exact original UI labels for controls `8`, `9`, and `10` remain unrecovered; these names are descriptive/inferred and should be kept below final-source confidence.
```

Add reachability/detail:

```text
The only durable route is the `ClanEnlistInputDialog` primary vtable cell `0x00615e54` at slot `+0x5c` / decimal `92`; no direct code callers are expected. [UID:00010L] reaches this slot after the OK path copies controls `8`, `9`, and `10` into inherited submitted fields. The sole direct callee is [UID:00010E] at call site `0x00489fe3`.
```

Add helper/API caveat:

```text
Prior PE raw-byte evidence records `ECX = dword_67ADE4` / `g_pClanStatusPane` before the [UID:00010E] call, while decompilers show [UID:00010E] as a four-stack-argument helper. This supports either a `ClanStatusPane::SendClanAttributePacket(...)` source method whose `this` is not used in the body, or a project-style file helper that carries the status-pane context explicitly in reconstructed C++. The helper name `SendClanAttributePacket` remains the durable label until [UID:00010E] receives a focused API/signature implementation pass.
```

## Recommended Support-Doc Changes

[UID:00002B] `by-class/ClanEnlistInputDialog.md`:

- Change the method row from role-only `SubmitEnlistment` to `OnSubmitEnlistment` / `ClanEnlistInputDialog::OnSubmitEnlistment()`.
- State that [UID:0002O3] is direct class-owned and class-emitted, with generated output still routed through `Clan.cpp`.
- Add vtable evidence: primary slot `0x00615e54`, slot `+0x5c`, no direct callers.
- Add field forwarding: `+0x26c/+0x46c/+0x66c/+0x86c` descriptive names and [UID:00010E] callee.
- Keep the raw constructor [UID:00021W] no-route caveat separate; constructor reachability does not block this method body C++.

[UID:000024] `by-class/ClanAttrInputDialog.md` and [UID:00010L] `ClanAttrInputDialogCore`:

- Add the no-argument confirmation-slot interpretation for DLGCLAN2 derived classes: OK path copies controls `8`, `9`, and `10`, parses the word field, calls primary slot `+0x5c`, and then closes.
- Name the submitted fields descriptively as `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType`, with exact original label caveats.

[UID:0001TY] `ClanInputDialogLayouts`:

- Add [UID:0002O3] as the enlistment consumer of the `ClanAttrInputDialog` submitted fields.
- Replace raw/generic "first/second/third submitted wide string" wording where appropriate with the descriptive names above, while preserving caveats that final UI labels are not recovered.
- Note that [UID:0002O5] likely needs the same class-owner/source-quality pass later; do not modify [UID:0002O5] during a 0002O3-only implementation unless the supervisor explicitly includes it.

[UID:00010E] `SendClanAttributePacket`:

- Keep helper title `SendClanAttributePacket`.
- Add alias/context note: subtype-6/action-2 clan attribute/enlistment submit packet helper.
- Add sole direct caller [UID:0002O3] at `0x00489fe3`.
- Add the `g_pClanStatusPane`/`ECX` API caveat and recommend later focused helper API revalidation.
- If accepted during implementation, update source-facing signature direction toward `ClanStatusPane::SendClanAttributePacket(const wchar_t *, const wchar_t *, const wchar_t *, unsigned short)` or the project-style explicit context helper.

[UID:0000I8] `by-file/Clan.md`:

- Update the `ClanEnlistInputDialog` row to say raw constructor [UID:00021W] and submit override [UID:0002O3] are class-owned by [UID:00002B], with `Clan.cpp` as the source file route.
- Update the `SendClanAttributePacket` row to mention [UID:0002O3] as the sole direct caller and the descriptive field roles.

[UID:0000IA] `by-file/ClanDialogs.md`:

- If touched, fix the `ClanEnlistInputDialog` row so it does not imply ownership of parser/status handlers. It should say raw constructor [UID:00021W] and submit override [UID:0002O3] only; [UID:00021S] packet handlers remain `ClanStatusPane` context.

[UID:00010M] aggregate:

- Optional support update only if supervisor wants aggregate wording refreshed: list [UID:0002O3] as `ClanEnlistInputDialog::OnSubmitEnlistment`, direct class owner [UID:00002B], and first-draft C++ ready. Keep aggregate non-emitting.

Generated/autogen:

- After implementation, generated memory route should change from direct file owner/emitter `0000I8` to class owner/emitter `00002B` while still resolving output to `auto-generated/NexusTK/social/Clan.cpp`.

## Rejected Alternatives And Negative Evidence

- Rejected no-code proof: the target is not a raw no-route helper. It has an exact function object, exact vtable slot, class owner, and source route. The blank formal C++ block is stale under the current combined-score/emitter gate.
- Rejected direct-file owner as final direct owner: [UID:0000I8] remains the source file route but is too broad for an exact class virtual method. The sibling constructor [UID:00021W] already uses [UID:00002B], and [UID:0002O3] should match the direct class-owner model.
- Rejected `ClanAttrInputDialog` ownership: it owns the base fields and dispatch code, not the derived vtable override cell.
- Rejected `ClanDialogs` direct owner: useful split candidate, but current project route and gate favor [UID:0000I8] through the class.
- Rejected raw/generated names in source C++: `sub_489FC0`, `sub_485AC0`, `dword_67ADE4`, and `field_0x26c` style names should remain evidence labels only. The draft source should use descriptive class/helper/global/member names.
- Rejected treating the constructor no-xref caveat as a method-body blocker: [UID:00021W] remains no-code due raw-constructor reachability, but [UID:0002O3] is an ordinary vtable-backed method with a proven vtable route.

## Score / Metadata Rationale

Before:

```text
COMPLETION:84
CONFIDENCE:90
CANONICAL_OWNER:0000I8
EMITTER_UIDS:0000I8
formal C++ blank
```

Recommended after implementation:

```text
COMPLETION:86
CONFIDENCE:91
CANONICAL_OWNER:00002B
EMITTER_UIDS:00002B
formal C++ populated
```

Rationale:

- Completion increases because the stale source-quality blocker is resolved, class ownership is made direct, source-facing method/member/helper names are recommended, the vtable route is explicitly tied to `ClanAttrInputDialog` dispatch, and first-draft C++ is ready.
- Confidence increases modestly because exported function/vtable data, current docs, and prior PE scan agree on the function shape. It should not rise higher because exact original UI labels, helper declaration form, and final `Clan.cpp` versus `ClanDialogs.cpp` split remain below final-audit confidence.

## Exact Implementation Checklist For Callback

1. Edit target `by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`.
2. Change metadata to `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:00002B`, `EMITTER_UIDS:00002B`; keep `RECONSTRUCTABLE:TRUE`.
3. Replace stale no-code/source-quality blocker with current gate analysis and first-draft C++ readiness.
4. Add method name/signature evidence for `int ClanEnlistInputDialog::OnSubmitEnlistment()`.
5. Add the exact range and split notes: `0x00489fc0-0x00489fe9`, no split needed, seven-byte successor padding `0x00489fe9-0x00489ff0`, raw constructor successor at `0x00489ff0`, preceding raw constructor/padding relationship through [UID:00021W].
6. Add vtable-only reachability: primary vtable cell `0x00615e54`, slot `+0x5c` / `92`, no direct code callers, dispatch from [UID:00010L] OK path.
7. Add sole callee: [UID:00010E] at call site `0x00489fe3`, subtype `6`, action `2`.
8. Add field/member mapping:
   - `this+0x26c` -> `m_submittedClanName`
   - `this+0x46c` -> `m_submittedDescriptionText`
   - `this+0x66c` -> `m_submittedAttributeText`
   - `this+0x86c` -> `m_submittedAttributeType`
   Keep original-label caveat.
9. Add helper API caveat and preferred source direction for `g_pClanStatusPane->SendClanAttributePacket(...)` or explicit context helper.
10. Populate formal C++ with the accepted preferred/fallback form from this report. B004 recommends not leaving it blank.
11. Update support docs listed above as needed, with report-level detail rather than a short summary.
12. Do not edit `by-memory/-coverage-report.md`; return the exact pending replacement row below for supervisor-owned application.
13. Run scoped validators from `source-3/project-documentation` for every touched by-* file with `--apply --queue-timeout 240`.
14. If formal C++ changes generated output or projected stats, report generated/stat file changes. Do not hand-edit generated files unless repository workflow requires it.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during this report pass. If accepted, replace the current [UID:0002O3] row with:

```text
        - [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) 0x00489fc0-0x00489fe9 | method | ClanEnlistInputDialog::OnSubmitEnlistment : reconstructable : 86% : very strong : B004 2026-06-19 source-quality recheck resolves the vtable-backed submitter as inferred/descriptive `ClanEnlistInputDialog::OnSubmitEnlistment()`, recommends direct class owner/emitter [UID:00002B], keeps generated source routing through [UID:0000I8] `NexusTK/social/Clan.cpp`, confirms exact `0x29` / 41-byte bounds, primary vtable slot `0x00615e54` / `+0x5c` / decimal `92`, no direct code callers, sole direct call to [UID:00010E] at `0x00489fe3`, inherited `ClanAttrInputDialog` fields `+0x26c/+0x46c/+0x66c/+0x86c` as submitted clan-name/description/attribute-text/type values, prior PE raw-byte evidence for `g_pClanStatusPane` context load before the helper call, adjacent `0xcc` alignment at `0x00489fe9-0x00489ff0`, and first-draft C++ readiness with helper-API caveat.
```

## Validator Needs

No validators were run because this was a report-only pass and no by-* docs were edited.

Expected commands from `source-3/project-documentation` during implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md](0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:00010M] aggregate is also updated:

> Executable block R002 was removed from this report and preserved verbatim in [0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md](0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## IDA Rename / Type / Comment Recommendations

High confidence:

- Rename/comment `0x00489fc0` as `ClanEnlistInputDialog::OnSubmitEnlistment` or `ClanEnlistInputDialog_OnSubmitEnlistment` depending on IDA naming policy.
- Comment vtable cell `0x00615e54`: `ClanEnlistInputDialog primary +0x5c submit/confirm override -> OnSubmitEnlistment`.
- Comment offsets in `ClanAttrInputDialog` layout:
  - `+0x26c` `m_submittedClanName`
  - `+0x46c` `m_submittedDescriptionText`
  - `+0x66c` `m_submittedAttributeText`
  - `+0x86c` `m_submittedAttributeType`
- Rename/comment `dword_67ADE4` as `g_pClanStatusPane` if not already applied in IDA.

Medium confidence:

- Give `0x00485ac0` a source-facing type/comment as one of:
  - `int __thiscall ClanStatusPane::SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)`
  - or `int SendClanAttributePacket(ClanStatusPane *statusPane, const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType)` as reconstruction convention.
- Keep existing durable label `SendClanAttributePacket`; do not rename to `SubmitClanChange`.

Lower confidence / defer:

- Exact original UI labels for controls `8`, `9`, and `10`.
- Final `Clan.cpp` versus `ClanDialogs.cpp` file split.
- Whether final class declarations should declare this base slot as `int` or `void`. Current first draft uses `int` to match accepted submitter pages and helper return preservation.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`
- Modified: none
- Generated/project-level files changed: none
- `by-memory/-coverage-report.md` edited: no

FINISHED report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B004/research/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:30","uid":"0002O3"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002O3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
