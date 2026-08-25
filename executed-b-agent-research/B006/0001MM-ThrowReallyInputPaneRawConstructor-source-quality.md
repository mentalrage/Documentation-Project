** TARGET-REPORT-UID:0001MM **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B006 Report: [UID:0001MM] ThrowReallyInputPaneRawConstructor

## Assignment

- Agent: B006.
- Assignment id: `B006-report-0001MM-throw-really-input-pane-raw-constructor-20260626`.
- Mode: report-only research first; no by-* implementation edits in this pass.
- Target: [UID:0001MM][by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md](../../../../../by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md).
- Required report path: `tools/leaser/Agents/Agent-B006/research/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md`.
- Goal caveat followed: the generated tracker still names the stale `0x005b5b30-0x005b5b80` filename in places, but the live target is the corrected half-open body range `0x005b5b30-0x005b5b7e`; do not recreate the stale filename.
- Operational state for this report: no subagents, no by-* edits, no generated edits, no manual coverage edits, no validator/tool-state edits, no IDA DB writes, and no by-* leases.

## Recommendation

Implement after supervisor acceptance.

- Target metadata recommendation:
  - Keep `UID:0001MM`.
  - Set `COMPLETION:88`.
  - Keep `CONFIDENCE:90`.
  - Keep `CANONICAL_OWNER:0000EZ`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000EZ`.
  - Keep `EMITTER_POSITION_OPTIONAL:` blank.
  - Keep `Nested:-8`.
- Exact target `Item Summary` recommendation:
  - `Retained ThrowReallyInputPane constructor body: localized prompt id 0xa5, CharInputPane base construction, item-slot argument stored at inferred m_itemSlot (this+0x108), vtable stores and inline construction mirrors confirmed; no raw-start function/xrefs/pointers, but formal first-draft constructor C++ is ready under current policy.`
- The old "C++ blank under the 95+ gate" rationale should be removed. The current code-entry policy is satisfied because the page is reconstructable, has a nonblank emitter route through [UID:0000EZ], and the recommended score average is `(88 + 90) / 2 = 89`, above the current threshold.
- The remaining negatives are confidence caps, not no-code blockers: IDA still has no function object at the raw start, no direct raw-start xref, no raw-start pointer hit, no exact original member name, and no recovered source constant name for prompt id `0xa5`.

## Formal C++ Disposition

This is the exact formal `RECONSTRUCTION_CPP CODE` insertion content for [UID:0001MM]. It is not illustrative text. During implementation, insert exactly these lines between the target page's `RECONSTRUCTION_CPP CODE:BEGIN` and `RECONSTRUCTION_CPP CODE:END` markers, without the Markdown fence.

```cpp
ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0xa5)),
      m_itemSlot(itemSlot)
{
}
```

Do not emit the compiler vtable stores in source. Do not call or inline the adjacent retained packet helper from this constructor. Do not invent a symbolic prompt constant until the resource enum is recovered. The formal block uses the numeric prompt id deliberately.

## Current Target State

The live target page currently has `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EZ`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.

The current body text is already strong on range, prompt id, stored slot offset, vtable stores, inline construction mirrors, and the no-direct-xref caveat. Its stale blocker is the statement that C++ remains blank under an obsolete 95+ gate. That blocker no longer matches current accepted raw-constructor policy in the neighboring item-action pages.

The current exact file exists at:

- `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`

Stale generated and manual ledgers still mention:

- `by-memory/0x005b5b30-0x005b5b80.ThrowReallyInputPaneRawConstructor.md`

Those stale tracker/coverage rows are observations only. They must not be hand-edited by B006 in the implementation callback unless the supervisor explicitly grants coverage ownership.

## MCP Session

IDA MCP was available and responsive. This report is not fallback-only.

- Endpoint checked: `http://127.0.0.1:13337/mcp`.
- Server: `ida-pro-mcp` version `1.0.0`.
- Required current schema used: `tools/call` with explicit `database`.
- Active session id: `80de0a67`.
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Input path from `server_health`: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Module: `NexusTK.exe`.
- Imagebase: `0x400000`.
- `server_health(database=80de0a67)`: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `idb_list`: active worker session, backend `worker`, `is_analyzing:false`.

## Numeric Conversion Evidence

Decimal conversions in this report were checked from `E:\NTK\GhidraBridge\source-3\project-documentation` with this batch command:

> Executable block R001 was removed from this report and preserved verbatim in [0001MM-ThrowReallyInputPaneRawConstructor-source-quality-removed.md](0001MM-ThrowReallyInputPaneRawConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

All conversion records returned `error:null`. Values inherited into the target/support docs should use:

- `0x4e` = 78.
- `0xa5` = 165.
- `0x10c` = 268.
- `0x108` = 264.
- `0xa0` = 160.
- `0xa4` = 164.
- `0x17` = 23.
- `0x59` = 89, ASCII `Y`.
- `0x79` = 121, ASCII `y`.
- `0x9a` = 154.
- `0xbfd` = 3069.
- `0x02` = 2.
- `0x04` = 4.
- `0x0a` = 10.
- `0x03` = 3.

## MCP Evidence

### Boundary And Function Map

`lookup_funcs` against database `80de0a67` confirms:

- `0x005b5b2c`: not a function.
- `0x005b5b30`: not a function.
- `0x005b5b5d`: not a function.
- `0x005b5b7e`: not a function.
- `0x005b5b80`: modeled function `sub_5B5B80`, size `0xa0` / 160.
- `0x005aba80`: modeled function `sub_5ABA80`, size `0x9a` / 154.
- `0x005a76c0`: modeled function `sub_5A76C0`, size `0xbfd` / 3069.
- `0x005a7b70`: contained in `sub_5A76C0`.
- `0x005b5ab0`, `0x005b5c20`, and `0x005b5c93`: not functions.
- `0x005b5ca0`: modeled function `sub_5B5CA0`, size `0xc7`.

`get_bytes` confirms the exact split:

- `0x005b5b2c-0x005b5b30`: four `0xcc` predecessor padding bytes.
- `0x005b5b30-0x005b5b7e`: exact 78-byte constructor-shaped body.
- `0x005b5b7e-0x005b5b80`: two `0xcc` successor padding bytes.
- `0x005b5c93-0x005b5ca0`: thirteen `0xcc` bytes before the next modeled Use constructor.

`make_signature_for_range 0x005b5b30-0x005b5b7e` returned `unique:true` with this full body signature:

```text
55 8B EC 51 56 8B F1 8B 0D 50 A7 67 00 68 A5 00 00 00 89 75 FC E8 06 A8 F3 FF 50 8B CE E8 4E CD F3 FF 8A 45 08 88 86 08 01 00 00 8B C6 C7 06 78 02 63 00 C7 86 A0 00 00 00 C8 02 63 00 C7 86 A4 00 00 00 F8 02 63 00 5E 8B E5 5D C2 04 00
```

### Raw Instruction Semantics

`insn_query 0x005b5b2c-0x005b5b80` returns predecessor alignment at `0x005b5b2c`, the constructor body from `0x005b5b30` through `0x005b5b7b`, and successor alignment at `0x005b5b7e`. All body instructions have `fn:null`, matching a retained raw constructor rather than an IDA-modeled function.

Key instruction facts:

- `0x005b5b35` saves `this` in `esi`.
- `0x005b5b37` loads `dword_67A750`, already documented as `g_pLanguageMan`.
- `0x005b5b3d` pushes prompt id `0xa5` / 165.
- `0x005b5b45` calls `sub_4F0350`, documented as `LanguageMan::GetLocalizedString`.
- `0x005b5b4d` calls `sub_4F28A0`, documented as the `CharInputPane` constructor.
- `0x005b5b52-0x005b5b55` copies the single stack argument byte into `this+0x108`.
- `0x005b5b5d`, `0x005b5b63`, and `0x005b5b6d` install the three `ThrowReallyInputPane` vtables at `this+0`, `this+0xa0`, and `this+0xa4`.
- `0x005b5b7b` returns with `retn 4`, proving exactly one stack argument beyond `this`.

### Route And Negative Pointer Evidence

`xrefs_to` confirms:

- `0x005b5b30`: zero xrefs.
- `0x005b5b7e`: zero xrefs.
- `0x005b5b80`: one data xref from vtable slot `0x006302c0`.
- `0x00630278`: xrefs from `0x005a7b87`, `0x005abae5`, and the target body `0x005b5b5d`.
- `0x006302c8`: xrefs from `0x005a7b8d`, `0x005abaeb`, and the target body `0x005b5b63`.
- `0x006302f8`: xrefs from `0x005a7b97`, `0x005abaf5`, and the target body `0x005b5b6d`.
- `0x005aba80`: zero xrefs.
- `0x005b5c20`: zero xrefs.

`find_bytes` confirms:

- Raw constructor VA pointer pattern `30 5B 5B 00`: zero matches.
- Raw constructor RVA pointer pattern `30 5B 1B 00`: zero matches.
- Stale/boundary pointer pattern `7E 5B 5B 00`: zero matches.
- Accept-handler pointer pattern `80 5B 5B 00`: one match at `0x006302c0`.
- Vtable pointer patterns match only the two construction mirrors and the target raw body:
  - `78 02 63 00`: `0x005a7b89`, `0x005abae7`, `0x005b5b5f`.
  - `C8 02 63 00`: `0x005a7b93`, `0x005abaf1`, `0x005b5b69`.
  - `F8 02 63 00`: `0x005a7b9d`, `0x005abafb`, `0x005b5b73`.

These negatives preserve the callgraph caveat. They do not overturn the constructor source shape.

### Inline Construction Mirrors

`insn_query 0x005a7b70-0x005a7ba5` inside `sub_5A76C0` shows the same source constructor sequence:

- Load `g_pLanguageMan`.
- Push prompt id `0xa5`.
- Call the localized-string helper.
- Call the `CharInputPane` constructor.
- Store the three `ThrowReallyInputPane` vtables.
- Store the slot byte at `this+0x108`.

`analyze_function 0x005aba80` shows another construction mirror:

- IDA models the function as `sub_5ABA80`, size `0x9a` / 154.
- It narrows a byte from `Block + 1`.
- It allocates `0x10c` / 268 bytes.
- It resolves localized string id 165.
- It calls the same base constructor.
- It installs the same three vtables.
- It writes the narrowed byte to offset 264.

`insn_query 0x005abacd-0x005abb08` verifies the raw instructions behind the decompilation: prompt lookup, base construction, vtable stores at `0x005abae5`, `0x005abaeb`, and `0x005abaf5`, and the final slot-byte store.

These mirrors explain why no direct call to `0x005b5b30` is present. The raw retained body still describes the same source constructor.

### Accept Handler And Field Use

`analyze_function 0x005b5b80` reports the vtable-routed accept handler as a modeled `0xa0` / 160-byte function. It:

- Checks whether one character is available.
- Reads one character.
- Accepts only `y` or `Y`.
- Writes opcode `0x17` / 23.
- Writes mode byte `1`.
- Reads the byte at `this+0x108`.
- Sends exactly three bytes through the packet sender.
- Writes a local trailing zero that is not part of the send length.

`insn_query 0x005b5bc0-0x005b5c16` confirms the send path at instruction level:

- `push 17h` for the throw opcode.
- `push 1` for confirmed-throw mode.
- `movsx eax, byte ptr [esi+108h]` for the stored constructor field.
- `push 3` before the queue/send call.

This proves the constructor argument is the same item-slot state consumed by confirmed throw behavior. `m_itemSlot` is the best current source-facing field name. The exact original member name is still inferred, so it should remain a confidence cap.

## Source-Quality Reanalysis

The old blank-C++ rationale should be superseded for [UID:0001MM].

Positive source reconstruction evidence:

- Exact 78-byte constructor body is isolated by padding.
- The body has normal MSVC constructor shape: `this` in `ecx`, one stack argument, base-constructor call, derived vtable stores, object pointer returned, and `retn 4`.
- The prompt helper, language global, and base constructor already have stable source-facing names in support docs.
- IDA demangles all three vtable labels as `ThrowReallyInputPane`.
- The primary vtable action slot points to the modeled accept handler at `0x005b5b80`.
- Two construction mirrors repeat the same prompt/base/vtable/member sequence.
- The stored member is consumed by the modeled accept path and adjacent retained helper packet path.
- Neighboring accepted item-action raw constructors now emit first-draft constructor C++ while preserving no-function/no-route as a confidence cap.

Remaining blockers investigated and resolved:

- No IDA function object at `0x005b5b30`: still true, but the byte body is exact and constructor-shaped; this caps confidence rather than requiring no-code.
- No direct raw-start xrefs: still true, but inline construction mirrors and vtable stores supply source-shape evidence.
- No raw-start pointer hit: still true; it reinforces retained/no-route status, not no-code status.
- Source helper names: stabilized as `g_pLanguageMan`, `LanguageMan::GetLocalizedString`, and `CharInputPane`.
- Adjacent raw helper split: [UID:0003NY] remains separate, class-owned, blank-C++/no-route retained helper; it should not be merged into the constructor.
- Constructor inlining policy: current local precedent accepts first-draft C++ for exact raw constructors when source shape is fully proven and the route negatives are documented.
- Field/type name: `m_itemSlot` is inferred but best-supported by the constructor write and confirmed-throw send consumption; the field spelling is not final-source proof.

Rejected alternatives:

- Do not keep the target formal C++ blank under an obsolete 95+ gate.
- Do not route ownership to `CharInputPane`; it is only the base constructor callee.
- Do not route ownership to `LanguageMan`; it only supplies localized text.
- Do not route ownership to `Socket`, packet helpers, or `g_packetSender`; sending happens outside the constructor.
- Do not merge `0x005b5b7e-0x005b5b80` padding or the accept handler into this target.
- Do not merge the adjacent retained helper `0x005b5c20-0x005b5c93` into this constructor.
- Do not invent a resource enum name for prompt id `0xa5`.

## Ownership And Source Placement

Recommended ownership route:

1. [UID:0000EZ][ThrowReallyInputPane](../../../../../by-class/ThrowReallyInputPane.md) remains the direct canonical owner and emitter because the target is its constructor and installs its vtables.
2. [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md) remains the file/module route because the item-action input pane family already owns adjacent direct item command prompts and accepted raw-constructor precedents.
3. [UID:0001XU][ItemActionInputPaneVtableFamily](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md) remains vtable context only.
4. [UID:0001ML][ThrowUseEatInputPanes](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) remains a non-emitting range inventory, not the source emitter.

## Split And Range Decision

Keep the range exactly `0x005b5b30-0x005b5b7e`.

- `0x005b5ab0-0x005b5b2c`: preceding throw-packet helper.
- `0x005b5b2c-0x005b5b30`: four bytes of padding.
- `0x005b5b30-0x005b5b7e`: target constructor body.
- `0x005b5b7e-0x005b5b80`: two bytes of padding.
- `0x005b5b80-0x005b5c20`: modeled accept handler.
- `0x005b5c20-0x005b5c93`: adjacent retained confirmed-throw packet helper.

No split, merge, or filename change is recommended for the live target. The stale generated/tracker `0x005b5b30-0x005b5b80` references should be resolved by normal validator/generator refresh after implementation, not by hand.

## Support-Doc Decisions

Required support edits after acceptance:

- `by-class/ThrowReallyInputPane.md`: update the score to `86/88`, add the `m_itemSlot` field/offset note at report-level detail, state that [UID:0001MM] now emits formal first-draft constructor C++ under current policy, preserve the no-function/no-route caveat, and document that [UID:0003NY] remains a separate retained helper.
- `by-file/ItemActionInputPanes.md`: update the `ThrowReallyInputPane` row and boundary notes to say [UID:0001MM] follows the same accepted retained raw-constructor first-draft policy as TakeOff, ChangeItemSlot, DropGold, and GiveGold; preserve no modeled function/no raw-start xref/no raw-start pointer as route caveats.
- `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`: update the `ThrowReallyInputPane` row or reconstruction notes to state [UID:0001MM] is first-draft constructor-C++ ready while no-function/no-route remains only a function-boundary/callgraph caveat; keep the vtable-family C++ block blank.
- `by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md`: add a support note that `this+0x108` is the same inferred `m_itemSlot` field initialized by [UID:0001MM], while preserving the helper as a separate class-owned no-route retained helper with blank formal C++.

Conditional support edits:

- `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`: edit only if, at implementation time, it contains wording that says [UID:0001MM] remains blank-C++, no-code, blocked, or owned by the aggregate. Current read found no such contradiction, so no edit is required now.
- `by-global/g_pLanguageMan.md`: no edit required unless implementation finds the page lacks or contradicts the `g_pLanguageMan` source-facing name used by this report. Current support is sufficient.
- `by-global/g_packetSender.md`: no edit required unless implementation finds the page lacks or contradicts the confirmed-throw opcode/mode/slot/length facts already present. Current support is sufficient.

## Generated And Coverage State

Read-only checks found stale generated/manual references:

- `by-memory/-coverage-report.md` still has a stale row for `0x005b5b30-0x005b5b80`, old score text, and a blank-C++ summary.
- `auto-generated/-ag-research-tracker.md` still lists the stale filename and older `74/84` tracker score.
- `auto-generated/-ag-coverage-report-by-memory.md` still has stale/file-missing references for the old filename.

Do not hand-edit these files during B006 implementation. Expected generated refresh state after accepted implementation and scoped validators: generated/tracker output should eventually converge on the live `0x005b5b30-0x005b5b7e` path and detect that formal C++ now exists. If stale generated rows remain after validators, report them rather than manually editing generated/tool-state files.

Supervisor-owned manual coverage note: `by-memory/-coverage-report.md` may need a supervisor coverage-row refresh after implementation, because B-agents are not authorized to edit manual `-coverage-report.md` files in this assignment.

## Implementation Callback Checklist

Implementation callback completed on 2026-06-26. All accepted by-* edits were applied or explicitly excluded with no-edit proof. Validator `--apply` performed its normal generated/tracker/stat refresh side effects; I did not manually edit generated files, project-level generated files, validator/tool state, coverage reports, or the IDA database.

- [x] Lease handling:
  - [x] Initial edit batch acquired leases only for the five by-* files being edited: `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`, `by-class/ThrowReallyInputPane.md`, `by-file/ItemActionInputPanes.md`, `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`, and `by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md`; `leaser.py B006 lease ...` returned `Success` for all five.
  - [x] Resume-time lease check at `2026-06-26T04:32:12-04:00` found no active B006 rows before the remaining support validators.
  - [x] Remaining validator batch reacquired only the four still-pending validator targets: `by-class/ThrowReallyInputPane.md`, `by-file/ItemActionInputPanes.md`, `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`, and `by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md`; `leaser.py B006 lease ...` returned `Success` for all four.
  - [x] Final release command `python .\leaser.py B006 unlease` from `tools\leaser` returned `Success` for those four files, and the final `current_leases.md` read showed only expired Supervisor rows and no active B006 leases.

- [x] Target page edit: `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`.
  - [x] Header now has `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EZ`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:-8`.
  - [x] `Item Summary` was replaced with the accepted retained-constructor summary: prompt id `0xa5`, `CharInputPane` base construction, inferred `m_itemSlot` at `this+0x108`, vtable stores, inline construction mirrors, no raw-start function/xrefs/pointers, and first-draft constructor C++ readiness.
  - [x] The formal `RECONSTRUCTION_CPP CODE` block contains only the accepted constructor text, without a Markdown fence:
    - `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)`
    - `: CharInputPane(g_pLanguageMan->GetLocalizedString(0xa5)),`
    - `m_itemSlot(itemSlot)`
  - [x] Stale no-code/95+ gate wording was superseded by the current code-entry policy and `88/90` score rationale.
  - [x] Report-level detail was incorporated for exact range `0x005b5b30-0x005b5b7e`, predecessor/successor padding, unique byte signature, no raw-start function/xrefs/pointers, prompt id, base constructor, vtable stores, inline mirrors, `m_itemSlot`, accept-handler consumption, opcode `0x17`, mode `1`, send length `3`, local-only trailing zero, adjacent helper split, rejected alternatives, and score cap.
  - [x] Added a `2026-06-26 B006 source-quality implementation` change entry.
  - [x] Validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - Command: `python .\tools\validator.py --mode file --file by-memory\0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md --apply --queue-timeout 240`
    - `command_id: 000000002368`
    - `command_timestamp: 2026-06-26T04:30:49-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Generated refresh observation: `generated_refresh: deferred`; command also reported expected path/score/emitter/autogen-registry updates. It emitted unrelated known missing-reference diagnostics from manual coverage, but no target-specific error.

- [x] Class support edit: `by-class/ThrowReallyInputPane.md`.
  - [x] Header now has `COMPLETION:86`, `CONFIDENCE:88`.
  - [x] Added `m_itemSlot` at `+0x108` as the source-facing inferred stored item-slot byte, with evidence from the constructor write, inline mirrors, `OnAccept`, and the adjacent helper packet path.
  - [x] Method notes now say [UID:0001MM] is formal first-draft constructor-C++ ready under current retained raw-constructor policy while preserving no raw-start function/xref/pointer caveats.
  - [x] Method notes state [UID:0003NY] remains a separate class-owned retained helper with blank formal C++ until a route/caller/declaration shape is proven.
  - [x] Added a B006 2026-06-26 change entry and direct-parent gate proof (`86/88` parent, `88/90` child).
  - [x] Validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - Command: `python .\tools\validator.py --mode file --file by-class\ThrowReallyInputPane.md --apply --queue-timeout 240`
    - `command_id: 000000002371`
    - `command_timestamp: 2026-06-26T04:32:29-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Generated refresh observation: `generated_refresh: deferred`; validator recorded completion/confidence updates.

- [x] File support edit: `by-file/ItemActionInputPanes.md`.
  - [x] Updated the `ThrowReallyInputPane` row to say raw constructor [UID:0001MM] now emits formal first-draft `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` C++ through the item-action module, with prompt id `0xa5`, `CharInputPane`, inferred `m_itemSlot`, opcode `0x17`, mode `1`, send length `3`, and separate retained helper [UID:0003NY].
  - [x] Boundary notes put [UID:0001MM] in the same accepted retained raw-constructor policy bucket as TakeOff, ChangeItemSlot, DropGold, and GiveGold.
  - [x] Preserved file score `90/85` and preserved no modeled raw-start function/no direct raw-start xref/no raw-start pointer caveats.
  - [x] Added a B006 2026-06-26 change entry.
  - [x] Validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - Command: `python .\tools\validator.py --mode file --file by-file\ItemActionInputPanes.md --apply --queue-timeout 240`
    - `command_id: 000000002373`
    - `command_timestamp: 2026-06-26T04:32:35-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Generated refresh observation: `generated_refresh: deferred`; validator reported `missing_ref_uid: 29` for pre-existing old UID references in this file and no B006 target-specific failure.

- [x] Vtable-family support edit: `by-type/by-vtable/ItemActionInputPaneVtableFamily.md`.
  - [x] Updated the `ThrowReallyInputPane` row and reconstruction notes so [UID:0001MM] is first-draft constructor-C++ ready and no-function/no-route/no-pointer remains an IDA/callgraph caveat only.
  - [x] Kept vtable-family score `86/89`.
  - [x] Kept the vtable-family formal C++ block blank because the page is a vtable inventory, not the constructor emitter.
  - [x] Added a B006 2026-06-26 change entry.
  - [x] Validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - Command: `python .\tools\validator.py --mode file --file by-type\by-vtable\ItemActionInputPaneVtableFamily.md --apply --queue-timeout 240`
    - `command_id: 000000002374`
    - `command_timestamp: 2026-06-26T04:32:43-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Generated refresh observation: `generated_refresh: deferred`; no target-specific failure.

- [x] Adjacent helper support edit: `by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md`.
  - [x] Added notes that `this+0x108` is the same inferred `m_itemSlot` field initialized by [UID:0001MM] and consumed by confirmed-throw packet behavior.
  - [x] Preserved `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000EZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EZ`, and blank `EMITTER_POSITION_OPTIONAL`.
  - [x] Kept the helper formal C++ block blank because no direct route/caller to the raw helper is proven.
  - [x] Preserved the separate-helper boundary from [UID:0001MM] and `OnAccept`; no constructor/accept/helper merge was introduced.
  - [x] Added a B006 2026-06-26 change entry.
  - [x] Validator run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - Command: `python .\tools\validator.py --mode file --file by-memory\0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md --apply --queue-timeout 240`
    - `command_id: 000000002375`
    - `command_timestamp: 2026-06-26T04:32:52-04:00`
    - Exit code: `0`
    - `ok: 1`
    - Generated refresh observation: `generated_refresh: deferred`; no target-specific failure.

- [x] Conditional aggregate support decision: `by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md`.
  - [x] No edit required. Implementation-time read found it remains a non-emitting range inventory and routes source-bearing work through exact children; it did not say [UID:0001MM] remains blank-C++/no-code/blocked/aggregate-owned.
  - [x] Because the exact contradiction condition was not met, no validator command was run for this page.

- [x] Conditional globals decision: `by-global/g_pLanguageMan.md` and `by-global/g_packetSender.md`.
  - [x] `by-global/g_pLanguageMan.md`: no edit required. Implementation-time read confirmed the page already supports the source-facing `g_pLanguageMan` language-manager singleton used by the constructor.
  - [x] `by-global/g_packetSender.md`: no edit required. Implementation-time read confirmed the page already documents the confirmed-throw sender facts for `0x005b5b80`: opcode `0x17`, mode `1`, stored slot, and length `3`.
  - [x] Because neither exact contradiction condition was met, no validator command was run for either global page.

- [x] Generated refresh expectation:
  - [x] No manual edits were made to generated files, project-level generated files, validator/tool state, IDA DB, or manual coverage reports. Required scoped validators used `--apply`, which performed normal automatic refresh/stat side effects.
  - [x] Read-only check after validators: `auto-generated/-ag-research-tracker.md` line 3248 now lists [UID:0001MM] as `88/90`, average `89.0`, path `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`.
  - [x] Read-only check after validators: `auto-generated/-ag-coverage-report-by-memory.md` line 2150 now lists [UID:0001MM] at `0x005b5b30-0x005b5b7e`, `emits_code:true`, `88%`, updated `2026-06-26 04:30:50`.
  - [x] Read-only check after validators: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` lines 102-108 include the emitted `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` constructor.
  - [x] Manual coverage remains supervisor-owned/stale: `by-memory/-coverage-report.md` line 2967 links to the corrected file path but still describes `0x005b5b30-0x005b5b80`, `74%`, and blank C++ under the old gate. I did not hand-edit it.
  - [x] Validator `--apply` also updated `project-level/-auto-completion-stats.md`; this was an automatic validator side effect, not a manual B006 edit.

- [x] Implementation report proof:
  - [x] Every accepted checklist item above is checked with path/section proof.
  - [x] Validator command, `command_id`, `command_timestamp`, exit code, and `ok` count are recorded for every edited by-* file.
  - [x] No-edit-required proof is recorded for every conditional page not edited.
  - [x] Final lease proof is recorded: `python .\leaser.py B006 unlease` returned success for the active B006 leases, and the final `current_leases.md` read showed no active B006 lease rows.

## Implementation Status

FINISHED_IMPLEMENTATION proof is complete for [UID:0001MM]. All accepted by-* doc edits were applied, required scoped validators passed, conditional pages were excluded with concrete read-back proof, and no B006 leases remain active.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-26T04:39:19","uid":"0001MM"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MM-ThrowReallyInputPaneRawConstructor-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
