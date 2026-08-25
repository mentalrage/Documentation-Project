** TARGET-REPORT-UID:0002KD **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0002KD] ParcelPaneOnKeyDown Source-Quality Report

## Scope And Current State

- Mode: report-only research pass. No by-* target/support documents were edited.
- Target: `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`
- Required report path: `tools/leaser/Agents/Agent-B011/research/0002KD-ParcelPaneOnKeyDown-source-quality.md`
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A6`, blank formal C++.
- Current generated tracker row is stale: `auto-generated/-ag-research-tracker.md` still lists [UID:0002KD] at `80/86` with report count `0`. Do not edit generated tracker files manually.
- Current blocker state: the target already has exact boundary, vtable slot, and byte-offset behavior, but still carries stale `dword_67A754` / `ctype::do_narrow` wording and leaves final C++ blank.

Recommended target metadata after implementation:

- `COMPLETION:90`
- `CONFIDENCE:92`
- Keep `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000A6`.
- Populate formal C++ with the first-draft body in this report.
- Do not raise above `90/92` in this callback: behavior, owner, and slot identity are exact, but `PaneKeyEvent` field names and the exact original spelling of the EventMan key-normalization method remain descriptive project names rather than recovered symbols.

## IDA MCP Evidence

IDA MCP was mandatory for this assignment and was used. No fallback-only evidence was used.

- Endpoint: `http://127.0.0.1:13337/mcp`
- Active database session: `398b87c1`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- `server_health`: `status: ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Target function evidence:

- `lookup_funcs 0x005465e0` returns `sub_5465E0`, size `0x2a`. `int_convert.py` verifies `0x2a` is 42.
- `lookup_funcs 0x0054660a` returns not a function. Bytes show the target ends at `0x0054660a`, followed by six `0xcc` padding bytes and the successor prologue at `0x00546610`.
- Decompile:

```c
char __stdcall sub_5465E0(_BYTE *a1)
{
  if ( a1[4] == 8 )
    std::ctype<char>::do_narrow(a1[8], (unsigned __int8)a1[266]);
  return 0;
}
```

- Disassembly confirms the exact operands:
  - `cmp byte ptr [ecx+4], 8`
  - `movzx eax, byte ptr [ecx+10Ah]`
  - `push eax`
  - `movzx eax, byte ptr [ecx+8]`
  - `mov ecx, dword_67A754`
  - `push eax`
  - `call 0x004a8b10`
  - `xor al, al`
  - `retn 4`
- `xrefs_to 0x005465e0` reports the sole meaningful inbound reference as data/vtable slot `0x00621c98`.
- `callees 0x005465e0` reports only `0x004a8b10`.
- `analyze_function 0x005465e0` reports size 42, 3 basic blocks, cyclomatic complexity 2, no strings, no ordinary callers, and the same always-false return.

Vtable and boundary evidence:

- `get_bytes 0x00621c90 size 0x20` decodes:
  - `0x00621c90 -> 0x00546eb7` ParcelPane secondary destructor adjustor.
  - `0x00621c94 -> 0x00546610` ParcelPane mouse-event virtual.
  - `0x00621c98 -> 0x005465e0` ParcelPane key-event virtual.
- [UID:0002OH][0x00621bb0-0x00621d50.ParcelNotificationVtableData](by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md) already records `0x00621c98 -> 0x005465e0`.
- [UID:0001YE][ParcelNotificationVtableFamily](by-type/by-vtable/ParcelNotificationVtableFamily.md) places the function at ParcelPane secondary slot `+0x08`, adjacent to [UID:0002KE][0x00546610-0x00546807.ParcelPaneOnMouseEvent](by-memory/0x00546610-0x00546807.ParcelPaneOnMouseEvent.md) at secondary slot `+0x04`.

EventMan and key-event producer evidence:

- `decompile 0x004a96a0` shows EventMan key-down dispatch constructing an `Event` stack record:
  - type byte `8` written at event offset `+0x04`.
  - translated/narrowed key byte written at event offset `+0x08`.
  - modifier/state byte written at event offset `+0x10a`.
  - tick/message-time argument written at event offset `+0x10c`.
  - dispatch call through `sub_4A6EF0`.
- The same stack layout proves [UID:0002KD]'s raw reads from `event+0x04`, `event+0x08`, and `event+0x10a` are the key-down event type, key byte, and modifier/state byte. `int_convert.py` verifies `0x10a` is 266.
- `decompile 0x004a98a0` shows the paired key-up path prepares type `9` and the same key/modifier offsets, which supports type `8` as key-down rather than a generic input event.
- [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) names event type `8` as `kEventKeyDown` and records key byte at Event `+0x08`, with modifier/state bytes in the same key payload family.

Helper and global evidence:

- `decompile 0x004a8b10` shows the stale IDA name `std::ctype<char>::do_narrow(char,int)` with body `return a1;`.
- `disasm 0x004a8b10` is `mov al, [ebp+arg_0]; retn 8`; it consumes two stack arguments and ignores the second.
- `xrefs_to 0x004a8b10 limit 120` returns 81 total local code xrefs and includes this target at `0x005465ff`, plus accepted key-handler users such as `0x0057c710`, `0x0057edb0`, `0x005a5bd0`, and `0x005b0010`.
- [UID:00014C] and [UID:00004O][EventMan](by-class/EventMan.md) reject the CRT/locale interpretation and name `0x004a8b10` as `EventMan::TranslateEventKey(unsigned char key, unsigned char modifiers)` / `TranslateEventKeyByte`.
- [UID:00028L][0x0067a754-0x0067a758.g_pEventMan](by-memory/0x0067a754-0x0067a758.g_pEventMan.md) identifies `dword_67A754` as the process-wide `EventMan *` singleton `g_pEventMan`. The current MCP bytes at `0x0067a754` are zero-initialized data, matching the global page.

Prior report and precedent check:

- No executed B-agent report for [UID:0002KD] itself was found.
- Executed B002 report for [UID:0002KE] proves the neighboring ParcelPane secondary input slot/source route and accepted `ParcelPane::OnMouseEvent(const PaneMouseEvent& event)` at `0x00621c94`.
- Executed B008 report for [UID:00014C] rejects the stale `ctype/narrow` identity for `0x004a8b10` and establishes the EventMan event type map.
- Existing accepted key-handler pages use `PaneKeyEvent` as the current project-facing name for this shared event shape. Examples include `ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)` and `SpellInventoryPane2::OnKeyEvent(PaneKeyEvent *event)`.
- Executed B001 GroupListPane virtual-stub research accepts `OnKeyDown` as the source-facing name for a secondary slot `+0x08` key-down dispatch override when the body is a false-return virtual.

## Blocker Resolution

| Blocker | Resolution | Evidence and implementation impact |
| --- | --- | --- |
| Event structure naming | Use `PaneKeyEvent` for the pane-facing callback parameter. Use `eventKind`/`payload[0]`/`keyState` in first-draft source, matching accepted key-handler pages. | EventMan producer proves raw offsets `+0x04`, `+0x08`, and `+0x10a`; accepted key pages already use `PaneKeyEvent`, `event->payload[0]`, and `event->keyState`. Exact original field spelling remains descriptive but no longer blocks first-draft C++. |
| Final source-facing method name | Keep `ParcelPane::OnKeyDown`. | Current target filename/class row use `OnKeyDown`; vtable secondary slot `+0x08` is the documented key-down dispatch slot; EventMan type `8` is key-down; GroupListPane precedent accepts `OnKeyDown` for the same slot role. Do not rename to generic `OnKeyEvent` in this callback. |
| `dword_67A754` interpretation | Replace raw `dword_67A754` wording with `g_pEventMan`. | [UID:00028L] identifies the global as process-wide `EventMan *`; MCP confirms the target loads it immediately before calling `0x004a8b10`. |
| Key-normalization helper role | Replace stale `std::ctype<char>::do_narrow` / CRT wording with `EventMan::TranslateEventKey` or `TranslateEventKeyByte`. | MCP shows the helper returns its first byte and consumes two arguments; 81 xrefs tie it to key handlers; B008/EventMan docs reject CRT/locale naming. For this target, use `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)` in first-draft C++. |
| Vtable slot and source placement | Keep owner/emitter [UID:0000A6] `ParcelPane`; source route [UID:0000MF] `ParcelPane.cpp`; vtable slot `0x00621c98`, ParcelPane secondary `+0x08`. | MCP bytes and docs place the slot next to accepted `OnMouseEvent` at `0x00621c94`; no ordinary callers exist, which is expected for a virtual-only callback. |
| Return behavior | Always returns `false` / zero. The key-normalization return is ignored. | Disassembly falls through or branches to `xor al, al; retn 4` on every path. There are no owner-field writes and no event mutations. This callback does not consume the key. |
| First-draft C++ readiness | Ready for target formal C++ after supervisor acceptance. | The body is tiny, source-owned, reconstructable, exact range and slot are proven, helper/global names are now resolved to accepted project names, and remaining field-name uncertainty is within accepted `PaneKeyEvent` descriptive naming practice. |

## Heuristic And Inference Reanalysis

Rejected interpretations:

- `std::ctype<char>::do_narrow` as a CRT locale helper: rejected. The function is a two-argument EventMan key-translation adaptor with 81 local key-handler refs, and the old decorated name is an IDA mislabel.
- `dword_67A754` as a `std::ctype` facet or unknown locale context: rejected. The accepted global page identifies it as `g_pEventMan`, and EventMan constructor/destructor docs own its lifecycle.
- `OnKeyEvent` as the final target method name: weaker for this exact ParcelPane slot. The callback is installed in the secondary `+0x08` key-down slot and tests type `8`; `OnKeyDown` is already the local filename/class name and matches the slot role.
- A no-code or dead-code disposition: rejected. The target is a live vtable entry in the ParcelPane secondary table, has a source class and source file route, and reconstructs to a valid source-authored virtual override.
- Treating the call result as consumed key state: rejected. The return byte from `TranslateEventKey` is never tested or stored; the method always returns false.

Accepted source-facing inferences:

- Source signature: `bool ParcelPane::OnKeyDown(const PaneKeyEvent *event)`.
- Source event type constant: use current pane-facing `kPaneKeyDown` in formal C++; record raw type `8` and EventMan `kEventKeyDown` in evidence.
- Source key helper: `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)`.
- Result: no consume behavior. This is a no-op key-down filter except for preserving the compiled key-normalization call.

## Ranked Ownership And Source Disposition

1. **[UID:0000A6] ParcelPane / exact emitting class child.** Correct owner and emitter. The function is a ParcelPane secondary-vtable key-down callback at `0x00621c98`, adjacent to the accepted ParcelPane mouse callback, and routes through [UID:0000MF] `NexusTK/ui/panels/ParcelPane.cpp`.
2. **[UID:0001EH] ParcelNotificationPanes aggregate.** Useful family context only. It should not replace the exact child owner/emitter.
3. **[UID:0000J6] Event / [UID:00004O] EventMan support.** Owns `g_pEventMan`, the key event producer, and `TranslateEventKey`; it does not own the ParcelPane callback.
4. **No-owner/raw-helper.** Rejected because vtable slot, source class, source file, behavior, and first-draft method body are all recoverable.

No split, merge, or range change is recommended.

## Recommended Target Update

Update `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md` to:

- Set `COMPLETION:90` and `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000A6`.
- Replace stale `dword_67A754` / `std::ctype<char>::do_narrow` prose with `g_pEventMan` / `EventMan::TranslateEventKey`.
- State that `0x004a8b10` is the accepted EventMan key-translation adaptor, exact original spelling still inferred.
- Replace the item summary with:

```text
*** Item Summary: MCP-backed ParcelPane secondary key-down virtual at `0x00621c98`; formal `ParcelPane::OnKeyDown(const PaneKeyEvent *event)` checks key-down type `8`, calls `g_pEventMan->TranslateEventKey` with event bytes `+0x08/+0x10a`, ignores the returned byte, and returns false for every path; `PaneKeyEvent` field names and exact helper spelling remain descriptive project names. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

- Insert this exact formal C++ between the target's existing `RECONSTRUCTION_CPP CODE:BEGIN` and `END` markers:

```cpp
bool ParcelPane::OnKeyDown(const PaneKeyEvent *event)
{
    if (event->eventKind == kPaneKeyDown)
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);

    return false;
}
```

Implementation note: this is source-style C++, not IDA pseudocode. IDA labels the function `__stdcall` because the hidden member `this` value in `ecx` is unused; the vtable slot and ParcelPane source route still make it a source member override.

## Recommended Support Updates

- `by-class/ParcelPane.md`
  - Update the [UID:0002KD] method row from "still below final-source naming quality" to source-ready `ParcelPane::OnKeyDown(const PaneKeyEvent *event)`.
  - Record slot `0x00621c98`, type `8` key-down gate, `g_pEventMan->TranslateEventKey(event->payload[0], event->keyState)`, ignored return, and always-false/no-consume behavior.
  - Narrow the open question: key-event callback name is resolved; remaining class caveats are timer/private-helper/declaration polish.
  - Leave class-level score unchanged unless the supervisor wants a small support-score bump; this single callback does not resolve all remaining ParcelPane caveats.
- `by-file/ParcelPane.md`
  - Add a change note that [UID:0002KD] now emits first-draft `ParcelPane::OnKeyDown` C++ and no longer blocks on key-event naming.
  - Keep broader timer/helper caveats intact.
  - Leave file score unchanged unless supervisor policy requires a support bump.
- `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`
  - Update `0x00621c98 -> 0x005465e0` wording from generic key-event virtual to source-ready `ParcelPane::OnKeyDown(const PaneKeyEvent *)`, no-consume false override.
- `by-type/by-vtable/ParcelNotificationVtableFamily.md`
  - Mirror the source-ready slot name for ParcelPane secondary `+0x08`.
- No update is required to `ParcelNotificationPaneLayouts.md` for fields: this target does not read ParcelPane owner fields or change the class layout.
- No update is required to [UID:00014C], [UID:00028L], or [UID:00027C] unless the supervisor wants a cross-reference note; those docs already carry the EventMan/global/helper interpretations used here.

## Validation Plan For Implementation Callback

Run validators only after supervisor accepts this report and sends an implementation callback. From `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002KD-ParcelPaneOnKeyDown-source-quality-removed.md](0002KD-ParcelPaneOnKeyDown-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If any support doc is unchanged because it already contains equal-or-stronger wording at callback time, record that as proof in the implementation checklist instead of forcing churn.

## Report-Only Proof Checklist

- [x] Read Agent-B011 `goal.md` and applied the report-only override.
- [x] Used the project-level `ntk-b-agent-workflow` skill and did not spawn subagents.
- [x] Completed an MCP-backed pass through session `398b87c1`; health was `ok` with Hex-Rays ready.
- [x] Rechecked target boundary, decompile, disassembly, xrefs, bytes, vtable slot, helper body, EventMan key-down producer, and prior accepted support docs.
- [x] Searched prior B-agent reports; no exact [UID:0002KD] report was found, and relevant B001/B002/B008/B015 precedent was incorporated as context.
- [x] Did not edit target/support by-* docs, generated reports, generated C++ files, project-level generated reports, coverage reports, validator/tool state, or IDA DB.
- [x] Did not take any B011 leases for this report-only pass. `current_leases.md` contains no B011 active lease entries; only stale expired Supervisor entries from 2026-06-18 are present.

## Implementation Tracking Checklist

Implementation callback completed 2026-06-27 by B011 under the ACTIVE SUPERVISOR CALLBACK OVERRIDE.

- [x] Lease only the immediate target/support docs about to be edited, then release immediately after the edit/validator batch.
  - Proof: B011 leased the five edited by-* docs before editing, then took a second short lease only for `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md` and `by-class/ParcelPane.md` for stale-wording cleanup. Final cleanup unlease succeeded for those two files, and current `tools/leaser/Agents/current_leases.md` has no B011 rows. `by-file/ParcelPane.md` was later leased by B007 at `2026-06-28T00:53:39Z`, after the B011 by-file edit and validator command `000000004444`.
- [x] Edit `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`:
  - Applied metadata `COMPLETION:90`, `CONFIDENCE:92`.
  - Kept `CANONICAL_OWNER:0000A6`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000A6`.
  - Replaced stale helper/global wording with `g_pEventMan` and `EventMan::TranslateEventKey`.
  - Inserted the formal `ParcelPane::OnKeyDown(const PaneKeyEvent *event)` C++ body.
  - Recorded MCP session `398b87c1`, range size `0x2a` / 42, event offset `0x10a` / 266, vtable slot `0x00621c98`, ignored helper return, and always-false behavior.
- [x] Edit `by-class/ParcelPane.md` only for the accepted [UID:0002KD] sync:
  - Marked key callback name/source shape resolved as source-ready `ParcelPane::OnKeyDown(const PaneKeyEvent *event)`.
  - Preserved unrelated timer/private-helper caveats and left class score unchanged at `88/90`.
- [x] Edit `by-file/ParcelPane.md` only for the accepted [UID:0002KD] sync:
  - Recorded first-draft key callback C++ readiness through the `ParcelPane.cpp` source route.
  - Preserved broader file caveats and narrowed remaining caveats away from key-handler naming to timer/private declaration issues.
- [x] Edit `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md` if its key slot row still uses weaker wording.
  - Proof: slot `0x00621c98 -> 0x005465e0` now names source-ready `ParcelPane::OnKeyDown(const PaneKeyEvent *)`, `g_pEventMan->TranslateEventKey`, and false/no-consume behavior.
- [x] Edit `by-type/by-vtable/ParcelNotificationVtableFamily.md` if its ParcelPane secondary `+0x08` row still uses weaker wording.
  - Proof: ParcelPane secondary `+0x08` row now mirrors the source-ready `ParcelPane::OnKeyDown(const PaneKeyEvent *)` wording.
- [x] Do not edit generated reports, generated C++ files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, or IDA DB.
  - Proof: only target/support by-* docs and this B011 report were edited manually. Validator-owned generated files refreshed through scoped validator commands only.
- [x] Run scoped validators listed above for every edited by-* file, with `--apply --queue-timeout 240`.
  - Target `by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md`: final command `python .\tools\validator.py --mode file --file by-memory/0x005465e0-0x0054660a.ParcelPaneOnKeyDown.md --apply --queue-timeout 240 --wait-generated`; command_id `000000004465`, timestamp `2026-06-27T20:55:19-04:00`, exit `0`, `ok: 1`, generated_refresh `completed`. Earlier target validator `000000004441` also passed before the stale-wording cleanup. Validator reported unrelated stale registry/missing-file noise plus stale missing reference target for old [UID:00014C] path `by-memory/0x004a8b40-0x004ab476.EventMan.md`.
  - `by-class/ParcelPane.md`: final command_id `000000004469`, timestamp `2026-06-27T20:55:38-04:00`, exit `0`, `ok: 1`, generated_refresh `deferred`. Earlier class validator `000000004443` also passed before the stale-wording cleanup.
  - `by-file/ParcelPane.md`: command_id `000000004444`, timestamp `2026-06-27T20:53:08-04:00`, exit `0`, `ok: 1`, generated_refresh `deferred`.
  - `by-memory/0x00621bb0-0x00621d50.ParcelNotificationVtableData.md`: command_id `000000004445`, timestamp `2026-06-27T20:53:17-04:00`, exit `0`, `ok: 1`, generated_refresh `deferred`.
  - `by-type/by-vtable/ParcelNotificationVtableFamily.md`: command_id `000000004446`, timestamp `2026-06-27T20:53:23-04:00`, exit `0`, `ok: 1`, generated_refresh `deferred`.
- [x] Run `python .\tools\validator.py --queue-status` and record proof that queued/processing jobs are clear, or record any validator-owned deferred refresh exactly.
  - Final queue-status command_id `000000004477`, timestamp `2026-06-27T20:56:01-04:00`: worker running, queued jobs `1`, processing jobs `0`, queued generated refresh jobs `6`, processing generated refresh jobs `1`. Relevant generated `auto-generated/NexusTK/ui/panels/ParcelPane.cpp` was current for the target at validator-command-id `000000004466` / `2026-06-27T20:55:24-04:00` and contains [UID:0002KD] at `90/92` with the inserted `ParcelPane::OnKeyDown` body. The generated file header had not yet caught up to later class support command `000000004469`; that deferred refresh is validator-owned and not a B011 manual edit.
- [x] Recheck this report's implementation checklist, mark completed items checked with proof, and confirm no active B011 lease remains before returning `FINISHED_IMPLEMENTATION` in a later callback.
  - Proof: checklist updated here; current lease report contains no B011 rows.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002KD-ParcelPaneOnKeyDown-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002KD-ParcelPaneOnKeyDown-source-quality.md","timestamp":"2026-06-27T20:56:44","uid":"0002KD"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002KD-ParcelPaneOnKeyDown-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002KD-ParcelPaneOnKeyDown-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002KD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
