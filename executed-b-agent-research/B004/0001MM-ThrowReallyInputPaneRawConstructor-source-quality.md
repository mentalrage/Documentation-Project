** TARGET-REPORT-UID:0001MM **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:0001MM] ThrowReallyInputPaneRawConstructor

## Assignment

- Agent: B004
- Assignment id: `B004-report-0001MM-throw-really-input-pane-raw-constructor-20260625`
- Target: [UID:0001MM][by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md](../../../../../by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md)
- Required disposition for this turn: report only. I made no by-* edits in this pass.
- Goal-path note: the supervisor goal text still names the stale suffix `0x005b5b30-0x005b5b80`, but the current exact target file and current MCP evidence use `0x005b5b30-0x005b5b7e` with `0x005b5b7e-0x005b5b80` as two padding bytes.
- Current-pass update: this report was rechecked in place on 2026-06-25 with live IDA MCP session `80de0a67`; no subagents, leases, target/support edits, generated edits, coverage edits, validator-state edits, or IDA DB writes were used.
- Revision-pass update: this report was revised in place on 2026-06-29 under assignment `B004-revise-report-0001MM-ThrowReallyInputPaneRawConstructor-source-quality-20260629`. The existing 2026-06-25 evidence below is preserved. I added the current Rule 26 claim/incorporation ledger, current implementation tracking checklist, current MCP spot-check against session `07c55da0`, stale Wave/simroot/recovered-source disposition, and current score-blocker audit. This revision made no by-* edits, generated edits, manual coverage edits, validator/tool-state edits, executed-report edits, lock-file edits, or IDA DB writes.

## Recommendation

Implementation direction remains valid, and the accepted verify-only callback confirms the target/support incorporation is already present because executed B006/B007 work applied the same constructor evidence. This report records the already-present target/support state rather than reapplying stale 2026-06-25 instructions from scratch.

- Target score recommendation: keep current `COMPLETION:88`, `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:0000EZ`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000EZ`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Keep the stale "C++ blank under the 95+ gate" rationale historical only. The current gate is satisfied: reconstructable true, nonblank emitter UID, and `(88 + 90) / 2 = 89`, above the current code-entry threshold.

Exact formal insertion for the target page's `RECONSTRUCTION_CPP CODE` block:

```cpp
ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)
    : CharInputPane(g_pLanguageMan->GetLocalizedString(0xa5)),
      m_itemSlot(itemSlot)
{
}
```

This is the exact formal `RECONSTRUCTION_CPP CODE` content, not an illustrative side snippet. It is source-ready first-draft C++. The field spelling is the remaining inference: `m_itemSlot` is the best current source-facing name for the byte at `this + 0x108`; `m_inventorySlot` would also be defensible if a later class-header pass standardizes item slot member naming differently. Do not emit the vtable stores in source C++; they are compiler output after base construction.

Recommended target source-disposition marker for implementation:

```text
Source disposition: exact retained raw `ThrowReallyInputPane` constructor; formal first-draft C++ is ready, while the absent raw-start function/xref route remains a confidence cap.
```

## Current Target State

2026-06-29 read-only state:

- Target [UID:0001MM][by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md](../../../../../by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) now has `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter [UID:0000EZ][ThrowReallyInputPane](../../../../../by-class/ThrowReallyInputPane.md), `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EZ`, and blank `EMITTER_POSITION_OPTIONAL`.
- Its formal C++ block is populated with the exact constructor text above.
- The old 95+ blank-C++ language is preserved only in historical `Changes` context; the active target text treats no raw-start function/xref/pointer as a confidence cap, not a no-code blocker.
- The exact live file remains `by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md`; older `0x005b5b30-0x005b5b80` mentions are historical or stale generated/manual-coverage residue, not current target identity.
- Support docs already contain the B006/B007 implementation state: [UID:0000EZ] records `m_itemSlot` at `+0x108`, [UID:0000KC] routes the constructor through the item-action pane module, [UID:0001XU] keeps this target in the retained raw-constructor policy bucket, [UID:0001ML] treats the range as a non-emitting aggregate inventory, and [UID:0003NY] stays a separate retained helper that emits from its own exact page.

## Live IDA MCP Session

MCP was available and current. I did not use a fallback-only report.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Server: `ida-pro-mcp` version `1.0.0`
- JSON-RPC flow used: `initialize`, `tools/list`, then `tools/call` with explicit `database` argument per the current schema.
- Session id: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Module: `NexusTK.exe`
- Imagebase: `0x400000`
- Health: `status: ok`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`
- `idb_list` status: one active adopted worker session, `is_analyzing:false`, backend `worker`, PID/worker PID `26892`, last accessed during this pass at `2026-06-25T17:46:00`.
- `server_health(database=80de0a67)`: `uptime_sec:127810.55`, `strings_cache_size:2067`.

### 2026-06-29 Current MCP Spot-Check

MCP was available for the revision pass, so this report is not fallback-only.

- Listener/process state: `127.0.0.1:13337` was listening under python PID `8860`; `idalib-mcp.exe` PID `20228` and worker python PIDs `9064`/`22044` were present.
- JSON-RPC `initialize` and `tools/list` succeeded against `http://127.0.0.1:13337/mcp`.
- Active IDB session: `07c55da0`, backend `worker`, owned/adopted, `is_analyzing:false`, worker PID `9064`.
- `server_health(database=07c55da0)`: `status: ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- `lookup_funcs(database=07c55da0)` confirms `0x005b5b30` and `0x005b5b7e` are not functions; `0x005b5b80` remains `sub_5B5B80`, size `0xa0` / 160; `0x005aba80` remains `sub_5ABA80`, size `0x9a` / 154.
- `get_bytes(database=07c55da0, 0x005b5b2c size 84)` reconfirms four `0xcc` bytes before the body, the same constructor bytes from `0x005b5b30-0x005b5b7e`, and two `0xcc` bytes at `0x005b5b7e-0x005b5b80`.
- `insn_query(database=07c55da0, 0x005b5b30-0x005b5b80)` returns the same constructor facts: `g_pLanguageMan`, prompt id `0xa5`, `LanguageMan::GetLocalizedString`, `CharInputPane` base construction, `[esi+0x108]` byte write from `[ebp+8]`, vtable stores `0x00630278`/`0x006302c8`/`0x006302f8`, and `retn 4`.
- `xrefs_to(database=07c55da0)` reconfirms zero xrefs to `0x005b5b30`, one vtable-slot data xref to `0x005b5b80` from `0x006302c0`, and the same three xrefs for each ThrowReallyInputPane vtable pointer: inline mirrors at `0x005a7b87`/`0x005abae5` plus the raw target store, then `0x005a7b8d`/`0x005abaeb` plus the raw target store, then `0x005a7b97`/`0x005abaf5` plus the raw target store.
- `find_bytes(database=07c55da0)` reconfirms zero raw-start VA/RVA pointer hits for `30 5B 5B 00` and `30 5B 1B 00`; vtable pointer patterns still match only the two construction mirrors and target raw body.
- `insn_query(database=07c55da0, 0x005b5bc0-0x005b5c16)` reconfirms `OnAccept` consumes `this+0x108` for confirmed throw: `push 17h`, `push 1`, `movsx eax, byte ptr [esi+108h]`, and `push 3`.

### Boundary And Raw Body Evidence

Live MCP `lookup_funcs` confirms the constructor body is still not an IDA-modeled function:

- `0x005b5b2c`: not a function.
- `0x005b5b30`: not a function.
- `0x005b5b5d`: not a function.
- `0x005b5b7d`: not a function.
- `0x005b5b7e`: not a function.
- `0x005b5b80`: `sub_5B5B80`, size `0xa0` / 160.

Live MCP `get_bytes` confirms the split:

- `0x005b5b2c-0x005b5b30`: `0xcc 0xcc 0xcc 0xcc`, four bytes of predecessor padding.
- `0x005b5b30-0x005b5b7e`: exact 78-byte constructor body (`0x4e` / 78 by `int_convert.py`).
- `0x005b5b7e-0x005b5b80`: `0xcc 0xcc`, two bytes of successor padding.
- `0x005b5b80`: modeled accept handler starts immediately after the padding.
- `make_signature_for_range 0x005b5b30-0x005b5b7e` returned a unique signature for the 78-byte body:
  `55 8B EC 51 56 8B F1 8B 0D 50 A7 67 00 68 A5 00 00 00 89 75 FC E8 06 A8 F3 FF 50 8B CE E8 4E CD F3 FF 8A 45 08 88 86 08 01 00 00 8B C6 C7 06 78 02 63 00 C7 86 A0 00 00 00 C8 02 63 00 C7 86 A4 00 00 00 F8 02 63 00 5E 8B E5 5D C2 04 00`.

Live MCP `insn_query 0x005b5b2c-0x005b5b80` returns 24 matches: predecessor alignment at `0x005b5b2c`, 22 constructor-body instructions from `0x005b5b30` through `0x005b5b7b`, and successor alignment at `0x005b5b7e`. All target body instructions have `fn: null`, matching a retained raw constructor:

- `0x005b5b35`: saves `this` in `esi`.
- `0x005b5b37`: reads `dword_67A750`, the documented `g_pLanguageMan`.
- `0x005b5b3d`: pushes prompt id `0xa5` / 165.
- `0x005b5b45`: calls `sub_4F0350`, the documented `LanguageMan::GetLocalizedString(int)`.
- `0x005b5b4d`: calls `sub_4F28A0`, the documented `CharInputPane::CharInputPane(const wchar_t *promptText)`.
- `0x005b5b52-0x005b5b55`: copies `[ebp+8]` into `[esi+0x108]`.
- `0x005b5b5d`: stores `??_7ThrowReallyInputPane@@6B@` at `this + 0`.
- `0x005b5b63`: stores `??_7ThrowReallyInputPane@@6B@_0` at `this + 0xa0`.
- `0x005b5b6d`: stores `??_7ThrowReallyInputPane@@6B@_1` at `this + 0xa4`.
- `0x005b5b7b`: `retn 4`, proving one stack argument after `this`.

The numeric conversions used in this report were checked with `source-3/project-documentation/tools/int_convert.py`: `0xa5` is 165, `0x4e` is 78, `0x10c` is 268, `0x108` is 264, `0xa0` is 160, `0xa4` is 164, and `0x17` is 23.

### Vtable And Mirror Evidence

Live MCP `xrefs_to` confirms the target vtable identity and two construction mirrors:

- `0x00630278`: xrefs at `0x005a7b87`, `0x005abae5`, and target raw body `0x005b5b5d`.
- `0x006302c8`: xrefs at `0x005a7b8d`, `0x005abaeb`, and target raw body `0x005b5b63`.
- `0x006302f8`: xrefs at `0x005a7b97`, `0x005abaf5`, and target raw body `0x005b5b6d`.
- `0x005b5b80`: data xref from vtable slot `0x006302c0`.

Live MCP `find_bytes` gives the same positive and negative pattern result:

- No VA pointer hit for raw constructor start pattern `30 5B 5B 00`.
- No RVA pointer hit for raw constructor start pattern `30 5B 1B 00`.
- No pointer hit for nearby stale/boundary patterns `2B 5B 5B 00` or `7E 5B 5B 00`.
- Vtable pointer `78 02 63 00` occurs at `0x005a7b89`, `0x005abae7`, and `0x005b5b5f`.
- Vtable pointer `C8 02 63 00` occurs at `0x005a7b93`, `0x005abaf1`, and `0x005b5b69`.
- Vtable pointer `F8 02 63 00` occurs at `0x005a7b9d`, `0x005abafb`, and `0x005b5b73`.

The inline construction slice in `sub_5A76C0` at `0x005a7b70-0x005a7ba5` repeats the same source constructor sequence: read `g_pLanguageMan`, push `0xa5`, call `sub_4F0350`, call `sub_4F28A0`, store the three ThrowReallyInputPane vtables, and store the slot byte at `[esi+0x108]`.

The raw helper `sub_5ABA80` is also a construction mirror. Live MCP `analyze_function 0x005aba80` decompiles it as `char __stdcall sub_5ABA80(char *Block)`: it narrows `Block + 1` to a byte, allocates `0x10c` / 268 bytes, resolves localized string id `165`, calls `sub_4F28A0`, installs the three ThrowReallyInputPane vtables, and writes `*(_BYTE *)(v2 + 264) = v1`. Its focused instruction slice at `0x005abacd-0x005abb05` shows the same prompt/base/vtable/member sequence.

`xrefs_to 0x005aba80` reports no direct cross-references, so the helper has the same no-route caveat as the target raw constructor. That is a confidence cap, not a source-code blocker.

### Field Use Evidence

The constructor's only new data member write is the byte at `this + 0x108`. Live MCP ties that member to confirmed throw behavior:

- `ThrowReallyInputPane::OnAccept` at `0x005b5b80` is a modeled `0xa0` / 160-byte function.
- `analyze_function 0x005b5b80` decompiles the affirmative path as accepting `y` / `Y`, writing opcode `23` (`0x17`), writing mode `1`, reading `*(_BYTE *)(this + 264)`, and sending exactly three bytes through `sub_574BB0((_BYTE *)dword_67A7EC, &Src, 3)`.
- The focused instruction slice at `0x005b5bc2-0x005b5c10` shows `push 17h`, `push 1`, `movsx eax, byte ptr [esi+108h]`, and `push 3` before the queue/send call.

Local support pages align with this interpretation:

- [UID:00040P][LanguageManGetLocalizedString](../../../../../by-memory/0x004f0350-0x004f0372.LanguageManGetLocalizedString.md) owns `LanguageMan::GetLocalizedString(int stringId) const`.
- [UID:000363][CharInputPaneConstructor](../../../../../by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md) owns `CharInputPane::CharInputPane(const wchar_t *promptText)`.
- [UID:0000Q5][g_packetSender](../../../../../by-global/g_packetSender.md) documents `0x005b5b80` as sending throw opcode `0x17`, mode byte `1`, and the stored slot with length `3`.
- [UID:0003NY][SendThrowConfirmedItemPacketRaw](../../../../../by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md) independently documents the same stored-slot confirmed-throw packet shape for the adjacent raw helper.

## Heuristic Reanalysis

The old no-C++ rationale should be superseded.

Positive evidence:

- The raw body is exact, isolated, and padding-bounded.
- It has normal MSVC constructor ABI shape: `this` in `ecx`, one stack byte argument, base-constructor call, derived vtable stores, returns `this`, `retn 4`.
- IDA has demangled vtable labels for `ThrowReallyInputPane`, and the primary vtable slot points to the modeled `OnAccept` handler.
- Two independent construction mirrors repeat the same prompt/base/vtable/member sequence.
- The written member is consumed by the modeled accept handler and packet path.
- Source-facing helper names are already stabilized in support docs: `g_pLanguageMan`, `LanguageMan::GetLocalizedString`, and `CharInputPane`.

Negative evidence and caps:

- IDA still has no function object at `0x005b5b30`.
- `xrefs_to 0x005b5b30` is empty.
- `find_bytes` finds no raw-start VA or RVA pointer pattern.
- The exact original member name at `this + 0x108` is not proven; `m_itemSlot` is a source-facing reconstruction choice.
- The exact source constant name for prompt id `0xa5` is not proven, so the formal block should use the numeric id rather than inventing a constant.
- The out-of-line retained constructor and inline construction mirrors suggest compiler/linker duplication or retained raw bodies; do not create extra source functions for each mirror.

These negatives explain why the score should remain `88/90` rather than near-final. They do not justify a blank C++ block under the current policy.

The current Rule 26/code-entry result is therefore positive: the target is reconstructable, has a nonblank emitter route through [UID:0000EZ], has average target score above the current gate after the recommended `88/90` update, and has exact formal insertion text. A target-specific no-code proof is not defensible here because the only serious negatives are liveness/name caps, not source-shape blockers.

## Ownership And Placement

Ranked route recommendation:

1. Direct owner/emitter remains [UID:0000EZ][ThrowReallyInputPane](../../../../../by-class/ThrowReallyInputPane.md). The target is its constructor and stores its vtables.
2. Source file route remains [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md), which already groups the item-action input pane constructors and packet handlers.
3. Support route remains [UID:0001ML][ThrowUseEatInputPanes](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) and [UID:0001XU][ItemActionInputPaneVtableFamily](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md) for cluster/vtable context.

Rejected owners:

- Do not route this constructor to `CharInputPane`; it is only the base constructor callee.
- Do not route it to `LanguageMan`; the language helper only supplies the prompt.
- Do not route it to `Socket` or packet helpers; the constructor stores the slot byte, while packet sending happens in `OnAccept` and adjacent helpers.
- Do not route it as a standalone raw helper with no class owner; the vtable identity and member use are class-specific.

## Split And Range

Keep the target range exactly `0x005b5b30-0x005b5b7e`.

- Predecessor `0x005b5ab0-0x005b5b2c` is [UID:0003NX][SendThrowItemPacketRaw](../../../../../by-memory/0x005b5ab0-0x005b5b2c.SendThrowItemPacketRaw.md).
- `0x005b5b2c-0x005b5b30` is four bytes of padding.
- Target `0x005b5b30-0x005b5b7e` is the retained constructor body.
- `0x005b5b7e-0x005b5b80` is two bytes of padding.
- Successor `0x005b5b80-0x005b5c20` is `ThrowReallyInputPane::OnAccept`.

No split or merge is recommended. The constructor should not absorb the successor padding or `OnAccept`, and it should not be merged into the raw packet helper cluster.

## Source-Facing Names

Recommended names for implementation:

- Constructor: `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)`.
- Base: `CharInputPane`.
- Prompt lookup: `g_pLanguageMan->GetLocalizedString(0xa5)`.
- Member: `m_itemSlot` at `this + 0x108`.

Rationale:

- `unsigned char itemSlot` matches a byte slot argument and nearby generated item packet senders that use item-slot terminology.
- `m_itemSlot` directly describes the stored inventory/item slot consumed by confirmed throw send behavior.
- `GetLocalizedString(0xa5)` matches the exact child page and current accepted item-action constructor pattern. Do not use a new constant until `str.res` prompt-constant naming is recovered.

## Generated And Coverage State

2026-06-29 read-only generated checks:

- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` now includes the [UID:0001MM] `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` constructor and the [UID:0003NY] helper C++ emitted from its own page.
- `auto-generated/-ag-research-tracker.md` now lists [UID:0001MM] as `88/90`, `emits:true`, generated count `1`, and executed report path `executed-b-agent-research/B006/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md`.
- `auto-generated/-ag-coverage-report-by-memory.md` now lists [UID:0001MM] at exact range `0x005b5b30-0x005b5b7e`, `emits_code:true`, and `88%`.
- `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` still has a class-level [UID:0000EZ] empty-emitter marker. That is a broader class-declaration/owner marker, not a blocker for [UID:0001MM].
- Manual `by-memory/-coverage-report.md` remains supervisor-owned and still has stale old range/score/blank-C++ text for this UID. I did not edit it.

Because generated files, project-level generated files, manual coverage reports, validator/tool state, and executed reports are excluded from this assignment, the only report action here is to record the current state. A future supervisor-owned manual coverage refresh can use the row below if needed.

Recommended supervisor-owned replacement row for `by-memory/-coverage-report.md`:

```markdown
    - [UID:0001MM][0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor](by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) 0x005b5b30-0x005b5b7e | raw constructor | ThrowReallyInputPaneRawConstructor : reconstructable : 88% : very strong : B004 2026-06-29 revised source-quality report preserves exact 0x4e/78-byte retained constructor body, prompt id 0xa5/165 via g_pLanguageMan->GetLocalizedString, CharInputPane base construction, selected item slot byte stored at this+0x108 as inferred m_itemSlot, ThrowReallyInputPane vtable stores 0x00630278/0x006302c8/0x006302f8 at this+0/+0xa0/+0xa4, inline construction mirrors at 0x005a7b87/0x005abae5, accept path consumes m_itemSlot for opcode 0x17 mode 1 length 3, no IDA function object or raw-start xrefs/pointers, and already-emitted formal first-draft constructor C++ while preserving no-route/source-name caveats.
```

## Wave, simroot, And Recovered-Source Disposition

This B004 report does not use Wave2, Wave3, simroot, recovered-source, or generated C++ as authority for the target's reconstruction. The active evidence is IDA MCP plus by-* support documentation.

- This report itself had no active Wave2/Wave3/simroot/recovered-source basis to preserve.
- [UID:0000KC][ItemActionInputPanes](../../../../../by-file/ItemActionInputPanes.md) retains older recovered file names and Wave3 dry-run details only as historical/generated migration context. Those mentions should remain historicalized.
- [UID:0001ML][ThrowUseEatInputPanes](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md) retains older Wave3 owner/projection labels only as historical generated leads; current authority is IDA MCP plus exact child pages.
- [UID:0001XU][ItemActionInputPaneVtableFamily](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md) records `simroot_v2` reporting `vtable_count:0` as a data-issue lead because IDA confirms the vtables. Do not use that simroot output to lower or block [UID:0001MM].
- Older `0x005b5b30-0x005b5b80` labels should stay historicalized or be rejected stale if they appear as active target identity. The current exact constructor body is `0x005b5b30-0x005b5b7e`.

## Score Blocker Recheck

Current Rule 26/code-entry result remains positive.

- [UID:0001MM] is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000EZ`, and the current target score average is `(88 + 90) / 2 = 89`, above the current code-entry threshold.
- The old blank-C++/95+ blocker is stale and should remain historical only. It is not an active score blocker.
- No direct IDA function object, no raw-start xref, and no raw-start pointer hit remain true. These are confidence caps because the byte body, ABI shape, vtable identity, mirror constructors, and field use prove source shape.
- `m_itemSlot` and prompt constant naming remain source-facing inference caps, not blockers. The formal C++ uses numeric prompt id `0xa5` until a real source enum is recovered.
- [UID:0003NY] no longer creates a blank-helper contradiction; it emits retained helper C++ from its own exact page and remains separate/no-route. Do not merge it into this constructor.
- The class-level [UID:0000EZ] empty-emitter marker in generated C++ is out of scope for this target and does not block [UID:0001MM] constructor emission.
- No unresolved "needs investigation" blocker remains for this target under the current standard.

## Implementation Verification Callback

Verification callback assignment `B004-verify-implementation-0001MM-ThrowReallyInputPaneRawConstructor-source-quality-20260629` was completed as verify-only. I checked the accepted ledger claims against the target and required support docs:

- [UID:0001MM][by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md](../../../../../by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md)
- [UID:0000EZ][by-class/ThrowReallyInputPane.md](../../../../../by-class/ThrowReallyInputPane.md)
- [UID:0000KC][by-file/ItemActionInputPanes.md](../../../../../by-file/ItemActionInputPanes.md)
- [UID:0001XU][by-type/by-vtable/ItemActionInputPaneVtableFamily.md](../../../../../by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md](../../../../../by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0003NY][by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md](../../../../../by-memory/0x005b5c20-0x005b5c93.SendThrowConfirmedItemPacketRaw.md)

Result: all accepted target/support details were already present at same-or-greater detail. I made no by-* edits, acquired no leases, and ran no validators because there was no edited by-* file to validate. Generated/manual state was inspected read-only: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` emits [UID:0001MM] constructor C++ and [UID:0003NY] helper C++; [UID:0000EZ] remains a class-level empty-emitter marker only; generated tracker/auto coverage are current for [UID:0001MM]; manual `by-memory/-coverage-report.md` remains stale and supervisor-owned.

## Claim And Incorporation Ledger

Implementation verification states were updated during the verify-only callback. No ledger row is blocked.

| ID | Claim / fact to apply or preserve | Action | Target/support destination | Verification state | Current proof / callback instruction |
| --- | --- | --- | --- | --- | --- |
| L01 | [UID:0001MM] canonical target identity is exact range `0x005b5b30-0x005b5b7e`; `0x005b5b7e-0x005b5b80` is padding and `0x005b5b30-0x005b5b80` is stale as active identity. | already-present | [UID:0001MM] target; [UID:0000EZ]; [UID:0000KC]; [UID:0001XU]; [UID:0001ML] | already-present | Target header and title use `0x005b5b30-0x005b5b7e`; target range table records `0x005b5b7e-0x005b5b80` as two-byte padding and historicalizes the old `0x005b5b30-0x005b5b80` filename. Class/file/vtable/aggregate support pages also use the exact child path and preserve old-range notes only as historical changes. No edit needed. |
| L02 | Target metadata should stay `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000EZ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000EZ`, blank `EMITTER_POSITION_OPTIONAL`. | already-present | [UID:0001MM] header | already-present | Target header lines already contain `88/90`, owner/emitter `0000EZ`, reconstructable true, and blank emitter position. No edit needed. |
| L03 | Formal constructor C++ is exact insertion text and should stay populated as `ThrowReallyInputPane::ThrowReallyInputPane(unsigned char itemSlot)` with `CharInputPane(g_pLanguageMan->GetLocalizedString(0xa5))` and `m_itemSlot(itemSlot)`. | already-present | [UID:0001MM] `RECONSTRUCTION_CPP CODE` | already-present | Target formal block already contains exactly the accepted constructor text. Generated C++ also emits [UID:0001MM] constructor at `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` lines 102-108. No edit needed. |
| L04 | Source disposition: exact retained raw constructor; no raw-start function/xref/pointer remains a confidence cap, not a no-code blocker. | already-present | [UID:0001MM] summary, reconstruction notes, rejected alternatives | already-present | Target status records exact retained raw constructor and confidence-cap wording; source-quality section says old blank-C++ rationale is superseded; rejected alternatives explicitly reject blank C++ under the old 95+ gate. No edit needed. |
| L05 | Current MCP spot-check session `07c55da0` reconfirms the target body, boundaries, no-route facts, vtable identity, mirror constructors, and `OnAccept` field use. | incorporate | This report; optional future target/support evidence note if supervisor requests latest-session evidence in by-* docs | applied | The `2026-06-29 Current MCP Spot-Check` section is incorporated in this report. Target/support docs already carry same-or-greater B006/B007 MCP detail from sessions `80de0a67` and `agent_b009_0002my_20260628`, so no by-* latest-session note was required in this verify-only callback. |
| L06 | Constructor body uses `g_pLanguageMan`, prompt id `0xa5`, `LanguageMan::GetLocalizedString`, and `CharInputPane`; do not invent a resource enum name. | already-present | [UID:0001MM]; [UID:0000EZ]; [UID:0000KC] | already-present | Target formal C++ and source-quality notes use numeric `0xa5`; target raw instruction evidence and class/file support docs record `g_pLanguageMan`, prompt id `0xa5`, and `CharInputPane` base construction without inventing a resource enum. No edit needed. |
| L07 | The argument byte is stored at `this+0x108`; `m_itemSlot` is the best source-facing field name, but the exact original spelling remains inferred. | already-present | [UID:0001MM]; [UID:0000EZ] field table; [UID:0003NY] helper notes | already-present | Target C++/notes record `m_itemSlot`; class page field table records `unsigned char m_itemSlot` at `+0x108` and says spelling is inferred; helper page ties `this+0x108` to the same `m_itemSlot` field. No edit needed. |
| L08 | Vtable stores `0x00630278`, `0x006302c8`, and `0x006302f8` identify `ThrowReallyInputPane`; vtable stores are compiler output and should not appear in source C++. | already-present | [UID:0001MM]; [UID:0001XU]; [UID:0000EZ] | already-present | Target raw instruction/xref sections list the three stores and source-quality section states vtable stores are compiler output not emitted in source. Vtable-family row for `ThrowReallyInputPane` records the same table bases and caveat. No edit needed. |
| L09 | Inline construction mirrors at `0x005a7b87`/`0x005abae5` and sibling vtable-store sites explain absence of a direct call to raw start; do not create extra source constructors for mirrors. | already-present | [UID:0001MM]; [UID:0000KC]; [UID:0001XU] | already-present | Target xref/mirror sections and support pages record inline construction mirrors in `sub_5A76C0` and `sub_5ABA80`, while retaining no-direct-route as a caveat. No support page emits or proposes extra mirror constructors. No edit needed. |
| L10 | `OnAccept` at `0x005b5b80` consumes `m_itemSlot` for opcode `0x17`, mode `1`, length `3`, proving constructor field meaning. | already-present | [UID:0001MM]; [UID:0000EZ]; [UID:0000KC]; [UID:0003NY] | already-present | Target accept-handler tie-in records opcode `0x17`, mode `1`, send length `3`, and `m_itemSlot`; class/file/helper pages repeat the same field and packet behavior. No edit needed. |
| L11 | [UID:0003NY] is a separate retained helper; it must not be merged into this constructor or rewritten as an `OnAccept` call without route proof. | already-present | [UID:0001MM]; [UID:0003NY]; [UID:0000EZ]; [UID:0000KC] | already-present | Target source-quality section says [UID:0003NY] remains separate and must not be called/inlined/absorbed; helper page rejects merge into `OnAccept`; class/file support pages preserve no-route and inline-accept warnings. No edit needed. |
| L12 | Ownership route remains [UID:0000EZ] direct class owner/emitter, [UID:0000KC] source-file/module route, [UID:0001XU] vtable context, and [UID:0001ML] non-emitting aggregate context. | already-present | Target and support docs | already-present | Target header owner/emitter is [UID:0000EZ]; target/status and class/file/vtable/aggregate pages route source through [UID:0000EZ] to [UID:0000KC], keep [UID:0001XU] as vtable context, and keep [UID:0001ML] as non-emitting inventory. No edit needed. |
| L13 | Reject alternative owners `CharInputPane`, `LanguageMan`, packet helpers, Socket/global sender, standalone raw helper, or aggregate owner for this constructor. | already-present | [UID:0001MM] rejected alternatives; support docs as needed | already-present | Target rejected-alternatives section explicitly rejects `CharInputPane`, `LanguageMan`, `Socket`/packet helpers, blank C++, and merging with padding/accept/helper; support pages keep packet/global dependencies as dependencies only. No edit needed. |
| L14 | Wave2/Wave3/recovered-source names are not authority for this target; existing Wave3/recovered-source mentions in support docs are historical/generated leads only. | historicalize | [UID:0000KC]; [UID:0001ML]; this report | already-present | File page states recovered/Wave3 route data are historical/generated leads only and records a B008 stale Wave3/recovered-source correction; aggregate page states older Wave3 labels are historical generated leads. No edit needed. |
| L15 | `simroot_v2 vtable_count:0` on the vtable-family page is a data-issue lead, not a reason to lower/block this constructor. | historicalize | [UID:0001XU] `Wave3 Data Issue`; this report | already-present | Vtable-family status says current `simroot_v2` metadata is only a data-issue lead, and the `Wave3 Data Issue` section states IDA confirms the tables despite `vtable_count:0`. No edit needed. |
| L16 | Generated C++/auto tracker/auto coverage are now current for [UID:0001MM]; manual `by-memory/-coverage-report.md` remains stale and supervisor-owned. | incorporate | This report; optional supervisor manual coverage row | applied | Read-only generated checks confirm [UID:0001MM] constructor in generated C++ lines 102-108, tracker row `88/90` with executed B006 report, and auto by-memory coverage row `emits_code:true`/`88%`. Manual `by-memory/-coverage-report.md` still has stale `0x005b5b30-0x005b5b80`, `74%`, blank-C++ text; not edited because manual coverage is supervisor-owned. |
| L17 | Class-level [UID:0000EZ] empty-emitter marker in generated C++ is broader class-declaration work, not a [UID:0001MM] target blocker. | not-applicable | This report; [UID:0000EZ] future class pass only | excluded-with-reason | Generated C++ read-only check shows [UID:0001MM] emits constructor C++ while [UID:0000EZ] appears only as an `Empty Emitter Marker`; class page says its formal block stays blank pending a coordinated class-declaration pass. Excluded as class-scope work, not a UID0001MM blocker. |
| L18 | Validators and generated freshness checks should run only after a future accepted implementation callback, and only for edited by-* docs under leases. | incorporate | Implementation tracking checklist | excluded-with-reason | This accepted callback was verify-only and found every accepted by-* detail already present. No by-* docs were edited, no leases were needed, and scoped validators were not run. Generated freshness was checked read-only and recorded above. |

## Implementation Tracking Checklist

This checklist was updated during the accepted verify-only implementation callback. All accepted items are resolved; none are blocked.

- [x] Report revision scope recorded: 2026-06-29 in-place revision preserved the 2026-06-25 MCP evidence and added current Rule 26 sections.
- [x] Current MCP availability verified during the report revision and a narrow current-session spot-check from session `07c55da0` remains in this report.
- [x] Claim And Incorporation Ledger added with one row for every accepted claim/fact that must be applied, preserved, historicalized, rejected stale, or excluded as not applicable.
- [x] Formal C++ is identified as exact `RECONSTRUCTION_CPP CODE` insertion text, not illustrative side text; target verification confirms the exact constructor block is already present.
- [x] Target check completed: [UID:0001MM][by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md](../../../../../by-memory/0x005b5b30-0x005b5b7e.ThrowReallyInputPaneRawConstructor.md) already has `88/90`, owner/emitter [UID:0000EZ], exact half-open range, exact formal C++, source-disposition wording, rejected alternatives, and old 95+ blank-C++ language only in historical change context.
- [x] Support check completed: [UID:0000EZ], [UID:0000KC], [UID:0001XU], [UID:0001ML], and [UID:0003NY] already preserve the constructor/helper boundary, `m_itemSlot` evidence, vtable-family context, non-emitting aggregate status, and historical Wave/recovered-source/simroot treatment.
- [x] Wave2/Wave3/simroot/recovered-source mentions encountered in support docs are already classified: Wave3/recovered-source as historical/generated leads; `simroot_v2` as data-issue lead only.
- [x] Current score blockers rechecked: no active no-code blocker remains; remaining negatives are confidence/name/route caps and are already documented in target/support docs.
- [x] Generated freshness checked read-only: `auto-generated/NexusTK/ui/dialogs/ItemActionInputPanes.cpp` has validator header `000000000262` / `2026-06-29T01:27:53-04:00`, emits [UID:0001MM] constructor C++ at lines 102-108 and [UID:0003NY] helper C++ at lines 109-117, and lists [UID:0000EZ] only as a class-level empty-emitter marker at line 198.
- [x] Generated tracker and auto coverage checked read-only: `auto-generated/-ag-research-tracker.md` lists [UID:0001MM] as `88/90`, generated count `1`, executed B006 report; `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0001MM] exact range `0x005b5b30-0x005b5b7e`, `emits_code:true`, `88%`.
- [x] Manual coverage handling completed: `by-memory/-coverage-report.md` still has stale `0x005b5b30-0x005b5b80`, `74%`, blank-C++ row text for [UID:0001MM]; it was not edited because manual coverage is supervisor-owned and excluded by this assignment.
- [x] Lease handling completed: no by-* docs needed edits, so no leases were acquired.
- [x] Validator handling completed: no by-* docs were edited, so scoped validators were excluded-with-reason and not run.
- [x] Claim ledger verification completed: every row now has callback verification state `already-present`, `applied`, or `excluded-with-reason` with proof. No row remains `proposed` or `blocked`.
- [x] No by-* docs, generated files, manual coverage reports, project-level generated files, validator/tool state, executed reports, lock files, or IDA DB state were edited. `execute_report` was not run.

## Final Implementation Verification Status

FINISHED_IMPLEMENTATION_VERIFIED. The accepted UID0001MM implementation was verified claim-by-claim against the target/support docs. All accepted details are already present, incorporated in this report, or excluded with a concrete reason; there are no blocked ledger rows. No by-* edits, leases, validators, generated/manual coverage edits, project-level edits, executed-report edits, lock-file edits, tool-state edits, IDA DB writes, or `execute_report` run occurred during this verify-only callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001MM-ThrowReallyInputPaneRawConstructor-source-quality.md","timestamp":"2026-06-29T01:36:53","uid":"0001MM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
