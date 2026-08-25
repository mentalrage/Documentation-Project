** TARGET-REPORT-UID:0002O3 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Report: [UID:0002O3] ClanEnlistInputDialogSubmitEnlistment

Agent: B003  
Date: 2026-06-19  
Target: `source-3/project-documentation/by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md`  
Required output only: research report. No target/support by-* pages and no coverage report were edited.

## Summary

[UID:0002O3] is ready to move past the current "no code emitted" source-quality blocker. Fresh local PE evidence confirms the exact `0x29` / 41-byte function body, primary vtable-only reachability, no direct code callers, a single direct callee [UID:00010E] at `0x00489fe3`, inherited `ClanAttrInputDialog` field offsets `+0x26c/+0x46c/+0x66c/+0x86c`, and adjacent `0xcc` alignment before the next constructor.

The best source-quality direction is to treat the function as a `ClanEnlistInputDialog` virtual submit method, not as a file-level helper. Recommended metadata change:

```yaml
CANONICAL_OWNER: 00002B
EMITTER_UIDS: 00002B
COMPLETION: 86
CONFIDENCE: 91
```

The source-file route should remain `NexusTK/social/Clan.cpp`, but through `[UID:00002B] ClanEnlistInputDialog -> [UID:0000I8] Clan`, not by direct file ownership. The current target already clears the active C++ gate because it is `RECONSTRUCTABLE:TRUE`, has a nonblank emitter route, and `(84 + 90) / 2 = 87`. After this recheck, I recommend replacing the empty emitter marker with first-draft C++.

## Evidence Checked

- Read workflow and ownership rules:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B003/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
- Read the target page and support docs:
  - `[UID:0002O3]` target submitter page.
  - `[UID:00010E]` `SendClanAttributePacket`.
  - `[UID:00010L]` `ClanAttrInputDialogCore`.
  - `[UID:00002B]` `ClanEnlistInputDialog`.
  - `[UID:000024]` `ClanAttrInputDialog`.
  - `[UID:0001TY]` `ClanInputDialogLayouts`.
  - `[UID:0001X9]`, `[UID:0003HE]`, `[UID:0002MN]` vtable/data support pages.
  - `[UID:0000I8]` `Clan.md` and `[UID:0000IA]` `ClanDialogs.md`.
  - Sibling submitter and helper pages `[UID:0002O5]`, `[UID:00010F]`, `[UID:00010J]`, `[UID:00021S]`.
- Read generated output:
  - `source-3/project-documentation/auto-generated/NexusTK/social/Clan.cpp`.
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`.
- Read prior relevant B-agent reports:
  - B015 `00021K-ClanSubtype6PacketHelpers-source-quality.md`.
  - B013 `00021S-ClanStatusPacketDialogHandlers-source-quality.md`.
  - B001 `0002NS-0002NU-0002NW-0002NY-0002O0-0002O2-clan-submitters-source-quality.md`.
- Live IDA MCP was unavailable at `127.0.0.1:13337`, so fresh checks below are from local read-only PE scanning of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

## Fresh Binary Checks

Local PE scan of `NexusTK.exe`:

```text
ImageBase: 0x00400000
.text: 0x00401000-0x0060c600
.rdata: 0x0060d000-0x0066c200
```

Target bytes at `0x00489fc0`:

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

Additional local xref/bounds results:

- Target size is `0x29` / 41 bytes. Verified with `int_convert.py`.
- The next seven bytes after `0x00489fe9` are `0xcc`, and the next function starts at `0x00489ff0`.
- No direct branch/call references to `0x00489fc0` were found.
- The only VA dword hit for `0x00489fc0` is `0x00615e54` in `.rdata`.
- `0x00615e54` is the `ClanEnlistInputDialog` primary vtable slot `+0x5c`; `0x5c` is 92. Verified with `int_convert.py`.
- The only direct branch to [UID:00010E] from this body is the `call 0x00485ac0` at `0x00489fe3`.
- [UID:00010E] ends in `ret 0x10`, so it pops four stack arguments. The caller also loads `ecx = dword_67ADE4` immediately before the call; this is compatible with a thiscall-style helper where the status-pane/global receiver is set even though the helper primarily uses its four stack arguments.

## Submitted Fields

The four submitted values are not raw local temporaries; they are inherited `ClanAttrInputDialog`/layout fields already populated by `[UID:00010L] ClanAttrInputDialogCore`.

| Offset | Decimal | Evidence | Recommended source-facing field direction |
| --- | ---: | --- | --- |
| `+0x26c` | 620 | Constructor stores the first packet string; submitter passes its address as arg1. Verified with `int_convert.py`. | `m_submittedClanName` or `m_enlistmentClanName`. High confidence as first submitted wide string; medium confidence on final semantic noun. |
| `+0x46c` | 1132 | `OnDialogAction` copies dialog control id 8 here; submitter passes its address as arg2. Verified with `int_convert.py`. | `m_submittedDescriptionText`. Medium confidence from sibling `ClanChangeInputDialog` docs and shared DLGCLAN2 schema. |
| `+0x66c` | 1644 | `OnDialogAction` copies dialog control id 9 here; submitter passes its address as arg3. Verified with `int_convert.py`. | `m_submittedAttributeText` or `m_submittedFlagText`. Prefer `m_submittedAttributeText` until a UI label is recovered. |
| `+0x86c` | 2156 | `OnDialogAction` parses control id 10 into this word; submitter passes it by value. Verified with `int_convert.py`. | `m_submittedAttributeType`. High confidence as numeric/type word. |

I do not recommend leaving these as `field_26C`, `field_46C`, `field_66C`, and `field_86C` in the first-draft C++. The evidence supports descriptive inherited member names, with a note that the exact original UI labels remain unrecovered.

## Method And Helper Names

Recommended target method name:

```cpp
ClanEnlistInputDialog::OnSubmitEnlistment()
```

Rationale:

- The function is reached through the `ClanEnlistInputDialog` primary vtable slot `+0x5c`, not by direct callers.
- `[UID:00010L]` dispatches that slot as the no-argument confirmation/submit hook after collecting the DLGCLAN2 fields.
- Prior accepted clan dialog submitter work uses source-facing class methods instead of raw `sub_` names.

Alternative acceptable name if the supervisor wants a generic base-slot naming pattern:

```cpp
ClanEnlistInputDialog::OnSubmitAttributes()
```

Recommended packet helper name direction:

- Keep `[UID:00010E]`'s durable doc title `SendClanAttributePacket` for now to avoid unnecessary support churn.
- Add a source-facing alias/note that the helper is the subtype-6/action-2 clan attribute/enlistment packet helper.
- If renamed later, the best descriptive name is `SendClanEnlistAttributePacket`, not a generic `SubmitClanChange` name.

Important relationship to [UID:00010E]:

- [UID:0002O3] is the sole direct caller of [UID:00010E].
- [UID:00010E] serializes opcode `0x4b` / 75, subtype `0x06` / 6, action `0x02` / 2, then three wide strings converted to multibyte payload text and a final 16-bit value.
- The target sets `ecx = dword_67ADE4` before the call. This should be documented on [UID:00010E] because it affects whether first-draft code should model the helper as `g_pClanStatusPane->SendClanAttributePacket(...)` or `SendClanAttributePacket(g_pClanStatusPane, ...)`.

## Owner, Emitter, And Source-File Routing

Current target metadata uses file-level ownership:

```yaml
CANONICAL_OWNER: 0000I8
EMITTER_UIDS: 0000I8
```

Recommended replacement:

```yaml
CANONICAL_OWNER: 00002B
EMITTER_UIDS: 00002B
```

Reasoning:

- This is an exact class virtual method, not a standalone file helper.
- The only non-code pointer is the `ClanEnlistInputDialog` vtable slot at `0x00615e54`.
- `[UID:00002B]` is the narrowest true owner and already routes to `[UID:0000I8] Clan`.
- The generated file should remain `NexusTK/social/Clan.cpp` through the class-to-file route.
- `ClanDialogs.cpp` remains a proposed split candidate only; it should not become the current emitter route for this target.

## Caller And Vtable Evidence

Recommended target-page vtable/caller note:

```text
Fresh PE scan found no direct branch/call references to 0x00489fc0. The only VA dword pointer hit is 0x00615e54 in .rdata, which is the ClanEnlistInputDialog primary vtable slot +0x5c (92, Verified with int_convert.py). The body's only direct callee is [UID:00010E] at 0x00489fe3.
```

Recommended class-page note for `[UID:00002B]`:

```text
[UID:0002O3] is the vtable-backed submit override for ClanEnlistInputDialog. It forwards the inherited DLGCLAN2 submitted fields at +0x26c/+0x46c/+0x66c/+0x86c to [UID:00010E].
```

## Heuristic / Inference Reanalysis And Validation

Heuristic issues and current best directions:

| Issue | Prior state | B003 direction |
| --- | --- | --- |
| Submitted string/attribute names | Raw offsets and generic "four inherited field arguments". | Use descriptive inherited members: `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, `m_submittedAttributeType`. Mark exact UI labels open. |
| Source-facing method name | Page title `ClanEnlistInputDialogSubmitEnlistment`, raw `sub_489FC0` in some context. | Use `ClanEnlistInputDialog::OnSubmitEnlistment()` as inferred/descriptive method name. |
| Packet helper relationship | Helper relationship known but source API unresolved. | [UID:0002O3] is the sole direct caller; [UID:00010E] is subtype-6/action-2 clan attribute/enlistment helper. Document the `g_pClanStatusPane`/`ecx` setup before final helper signature. |
| Owner/emitter | File-level `[UID:0000I8]`. | Change direct owner/emitter to `[UID:00002B]`; preserve `social/Clan.cpp` route through `[UID:0000I8]`. |
| Vtable/caller evidence | IDA note says vtable-only/no direct callers. | Fresh PE scan independently confirms no direct branches and only `.rdata` pointer hit at `0x00615e54`. |
| Support doc split | `ClanDialogs.md` still risks implying this owns parser/handlers. | Keep current generated file route in `Clan.cpp`; update `ClanDialogs.md` to say raw constructor and submitter only, while status packet handlers live with `[UID:00002K] ClanStatusPane`. |
| Compiler-generated names | `sub_489FC0`, `sub_485AC0`, `dword_67ADE4`. | Replace/annotate as `ClanEnlistInputDialog::OnSubmitEnlistment`, `[UID:00010E] SendClanAttributePacket`, and `g_pClanStatusPane`/global clan status pane context. |
| First-draft C++ | Empty emitter marker because field/helper names unresolved. | Ready for first-draft C++ with descriptive member names and a helper-signature note. |

Residual inference risk:

- Exact original member names and dialog labels for controls 8/9/10 are not recovered.
- [UID:00010E] should be rechecked before finalizing whether the public helper signature exposes `ClanStatusPane *` or uses method-call syntax. The binary caller sets `ecx`; the helper body uses four stack arguments and returns with `ret 0x10`.
- `Clan.cpp` versus future `ClanDialogs.cpp` remains a project-level source-split question. Current route should not change for this target.

## Recommended Exact Target Doc Changes

Recommended frontmatter replacement:

```yaml
COMPLETION: 86
CONFIDENCE: 91
CANONICAL_OWNER: 00002B
EMITTER_UIDS: 00002B
```

Recommended `## Inferred Semantics` replacement/addition:

```text
`ClanEnlistInputDialog::OnSubmitEnlistment()` is the `ClanAttrInputDialog` confirmation-slot override for the enlistment dialog. It forwards the inherited DLGCLAN2 submitted fields to [UID:00010E] `SendClanAttributePacket`: the first packet-supplied/submitted clan-name string at `this+0x26c`, the editable description text at `this+0x46c`, the editable attribute/flag text at `this+0x66c`, and the parsed 16-bit attribute/type value at `this+0x86c`. The exact original UI labels for the two editable text attributes remain unrecovered, so these names are descriptive rather than symbol-backed.
```

Recommended `## Evidence` replacement/addition:

```text
Fresh PE scan confirms the `0x29` / 41-byte body (Verified with `int_convert.py`): `movzx [ecx+0x86c]`, pushes it, pushes addresses of `[ecx+0x66c]`, `[ecx+0x46c]`, and `[ecx+0x26c]`, loads `ecx = dword_67ADE4`, calls [UID:00010E] at `0x00489fe3`, and returns. There are no direct branches to `0x00489fc0`; the only VA dword pointer hit is `0x00615e54` in `.rdata`, the `ClanEnlistInputDialog` primary vtable slot `+0x5c` (92, Verified with `int_convert.py`). Bytes after `0x00489fe9` are `0xcc` padding before the next constructor at `0x00489ff0`.
```

Recommended `## Source Reconstruction Notes` replacement:

```text
Use direct class ownership/emission through [UID:00002B] `ClanEnlistInputDialog`; the generated source file remains `NexusTK/social/Clan.cpp` through [UID:0000I8]. First-draft C++ should call [UID:00010E] with the inherited submitted fields. If [UID:00010E] is kept as a free helper, model the call as `SendClanAttributePacket(m_submittedClanName, m_submittedDescriptionText, m_submittedAttributeText, m_submittedAttributeType)`. If its thiscall-like `ecx = g_pClanStatusPane` setup is modeled in source, use `SendClanAttributePacket(g_pClanStatusPane, ...)` or `g_pClanStatusPane->SendClanAttributePacket(...)` consistently with the helper page.
```

Recommended generated C++ body:

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

If the helper remains documented as a four-argument static/free function, use this variant instead:

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

B003 recommendation: prefer the five-argument/context-preserving draft until [UID:00010E] is revalidated, because the caller explicitly loads `ecx` from `dword_67ADE4` immediately before the helper call and the helper returns with `ret 0x10`.

## Clan Dialog Support Docs Needing Updates

Recommended `[UID:00002B] ClanEnlistInputDialog` update:

```text
Add [UID:0002O3] as direct class-owned submit override `ClanEnlistInputDialog::OnSubmitEnlistment()`. Note the primary vtable slot `+0x5c`, no direct callers, and forwarding of inherited fields `+0x26c/+0x46c/+0x66c/+0x86c` to [UID:00010E].
```

Recommended `[UID:000024] ClanAttrInputDialog` update:

```text
Document the shared DLGCLAN2 confirmation path: `OnDialogAction` collects controls 8, 9, and 10 into inherited submitted fields `+0x46c/+0x66c/+0x86c`, preserves the first packet/submitted string at `+0x26c`, and dispatches the derived no-argument submit slot at primary vtable `+0x5c`.
```

Recommended `[UID:0001TY] ClanInputDialogLayouts` update:

```text
For the DLGCLAN2 multi-field layout, use descriptive field names `m_submittedClanName` (`+0x26c`), `m_submittedDescriptionText` (`+0x46c`), `m_submittedAttributeText` (`+0x66c`), and `m_submittedAttributeType` (`+0x86c`) until exact UI labels are recovered. Mark `m_submittedAttributeText` versus `m_submittedFlagText` as an open naming question.
```

Recommended `[UID:00010E] SendClanAttributePacket` update:

```text
Clarify that [UID:0002O3] is the sole direct caller and that the caller loads `ecx = dword_67ADE4`/global clan status pane context immediately before the call. The helper still serializes four submitted values as subtype-6/action-2: first string, second string, third string, and 16-bit type/value. Revalidate whether the source-facing helper should be a free function with an explicit `ClanStatusPane *` context or a status-pane method whose `this` is unused by the current helper body.
```

Recommended `[UID:0000I8] Clan.md` update:

```text
Change the target row/notes to show [UID:0002O3] as class-owned by [UID:00002B] but still emitted through the Clan source file route. Keep [UID:00010E] as the packet helper until its helper API is finalized.
```

Recommended `[UID:0000IA] ClanDialogs.md` update:

```text
For `ClanEnlistInputDialog`, say "raw constructor [UID:00021W] and submit override [UID:0002O3]" rather than "parser/handlers and submitter". [UID:00021S] status packet handlers should remain routed through `ClanStatusPane`, not this dialog.
```

Recommended sibling follow-up:

```text
[UID:0002O5] `ClanChangeInputDialogSubmitClanChange` likely has the same direct class-owner/emitter issue and should receive a later source-quality pass against [UID:000027].
```

## Validator Needs

No validators were run for this report because this B-agent pass did not edit target/support by-* pages.

On an implementation callback, validate at least:

> Executable block R001 was removed from this report and preserved verbatim in [0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md](0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also refresh/check generated output for `auto-generated/NexusTK/social/Clan.cpp` after changing owner/emitter and adding the C++ body.

## Exact Pending Coverage Text

Do not edit `source-3/project-documentation/by-memory/-coverage-report.md` during this B-agent report pass. If accepted, replace the current [UID:0002O3] row with:

```text
    - [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) 0x00489fc0-0x00489fe9 | method | ClanEnlistInputDialog::OnSubmitEnlistment : reconstructable : 86% : very strong : B003 source-quality recheck resolves the vtable-backed submitter as inferred/descriptive `ClanEnlistInputDialog::OnSubmitEnlistment()`, recommends class owner/emitter [UID:00002B], confirms exact `0x29` / 41-byte bounds (Verified with int_convert.py), primary vtable slot `0x00615e54` / `+0x5c` (92, Verified with int_convert.py), no direct branches, sole `.rdata` VA pointer hit at the vtable slot, sole direct call to [UID:00010E] at `0x00489fe3`, inherited `ClanAttrInputDialog` fields `+0x26c/+0x46c/+0x66c/+0x86c` as submitted clan-name/description/attribute-text/type values, `g_pClanStatusPane` context load before the helper call, adjacent `0xcc` alignment, `social/Clan.cpp` source route through [UID:00002B] -> [UID:0000I8], and first-draft C++ readiness.
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002O3"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002O3-ClanEnlistInputDialogSubmitEnlistment-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002O3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
