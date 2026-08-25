** TARGET-REPORT-UID:0001MX **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B004 Report: [UID:0001MX] BlockListenInputPaneKeyHandler

## Assignment

- Agent: B004
- Assignment id: `B004-report-0001MX-block-listen-input-pane-key-handler-20260626`
- Target: [UID:0001MX][by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md](../../../../../by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md)
- Required disposition for this turn: report only. I made no by-* edits, generated edits, project-level edits, coverage edits, validator/tool-state edits, or IDA DB writes.
- Supervisor override applied: live IDA MCP was used and responsive; no fallback-only report was written; no subagents were spawned.

## Recommendation

Implement after supervisor validation.

- Target score recommendation: `COMPLETION:90`, `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00000X`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00000X`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Replace the stale blank-C++ blocker. The event-field, string-helper, alert-class, and config block-list route questions are now resolved enough for first-draft source C++.
- Source-facing method recommendation: `BlockListenInputPane::OnKeyInput(const InputEvent *event)`. The current class page's `HandleKeyEvent(...)` label is a descriptive alias and should be normalized or cross-noted during implementation; the closest accepted sibling with the same `?`/mode/type gate uses `OnKeyInput` and `CharInputPane::OnKeyInput(event)`.

Recommended formal insertion for the target page's `RECONSTRUCTION_CPP CODE` block:

```cpp
bool BlockListenInputPane::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (key == '?' &&
        event->narrowFallback == 4 &&
        event->type == 8) {
        SimpleUString blockListText;
        for (SimpleUString *it = g_pConfig->m_blockListenNames.begin;
             it != g_pConfig->m_blockListenNames.end;
             ++it) {
            blockListText.AppendWideSliceFromString(*it, 0, it->Length());
            blockListText.AppendWideFill(1, L'\n');
        }

        new AlertPane(blockListText.c_str(),
                      g_activeMapPane,
                      kDialogOkButtonText,
                      NULL);

        return true;
    }

    return CharInputPane::OnKeyInput(event);
}
```

This is source-ready first-draft C++. Remaining name caveats are source-facing spelling caps, not blank-code blockers: `InputEvent::keyCode`, `InputEvent::narrowFallback`, `InputEvent::type`, `NarrowInputKey`, `SimpleUString`, `m_blockListenNames`, `g_activeMapPane`, and `kDialogOkButtonText` are the best current project-level aliases from support pages and nearby accepted C++.

Recommended target source-disposition marker for implementation:

```text
Source disposition: exact modeled `BlockListenInputPane::OnKeyInput` override; first-draft C++ is ready. It handles Ctrl+`?`/event type `8` by displaying the newline-delimited local block-list names in an `AlertPane`, otherwise forwarding to `CharInputPane::OnKeyInput`.
```

## Current Target State

The target page currently has `COMPLETION:86`, `CONFIDENCE:88`, owner/emitter [UID:00000X][BlockListenInputPane](../../../../../by-class/BlockListenInputPane.md), `RECONSTRUCTABLE:TRUE`, and a blank C++ block. Its summary already identifies the high-level behavior: Ctrl+`?` opens a current block-list alert and other input falls through to the base input-pane handler. The stale blocker is the final source naming for event fields, string helpers, alert class, and config block-list fields.

Those blockers are now resolved at first-draft source level:

- The event gate matches the accepted [UID:0001MP][SpellSpellInputPaneKeyInput](../../../../../by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md) pattern: `NarrowInputKey(event->keyCode, event->narrowFallback) == '?'`, `event->narrowFallback == 4`, and `event->type == 8`.
- The base fallback is [UID:000362][CharInputPaneKeyAccept](../../../../../by-memory/0x004f2920-0x004f29ca.CharInputPaneKeyAccept.md), modeled in source as `CharInputPane::OnKeyInput(event)` by the accepted sibling.
- The block-list vector is the `g_pConfig + 0x2918fc/+0x291900` vector span documented under [UID:0000RD][g_pConfig](../../../../../by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md) and [UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md); the best current field spelling is `Config::m_blockListenNames`.
- The string operations are `StringBase`/`SimpleUString` helpers: initialize empty wide string, append each full element, append one newline, read `c_str`, and release on scope exit.
- The alert path is [UID:0001A7][AlertPaneCore](../../../../../by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), allocated through the global operator-new wrapper with size `0x270` / 624 and constructed with message text, active map pane, shared OK label, and null secondary label.

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
- Final `idb_list` snapshot: `B004-MCP-0021` at `2026-06-26T17:36:51.2887615-04:00`, one active adopted worker session, backend `worker`, PID/worker PID `26892`, `is_analyzing:false`, last accessed `2026-06-26T17:36:14.646421`.
- Final `server_health`: `B004-MCP-0022` at `2026-06-26T17:36:51.7439246-04:00`, `status: ok`, `uptime_sec:213661.974`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Evidence commands used in this pass include `B004-MCP-0003` lookup, `B004-MCP-0004` target analysis/decompile, `B004-MCP-0008` disassembly, `B004-MCP-0010` xrefs, `B004-MCP-0011` callees, `B004-MCP-0015` integer reads at `2026-06-26T17:35:52.1603442-04:00`, `B004-MCP-0016` bytes at `2026-06-26T17:35:52.6258861-04:00`, `B004-MCP-0017` OK-label string probe at `2026-06-26T17:35:52.6638956-04:00`, `B004-MCP-0019` helper lookup at `2026-06-26T17:36:14.1861135-04:00`, and `B004-MCP-0020` helper analysis at `2026-06-26T17:36:14.6411320-04:00`.
- Schema-correction attempts `B004-MCP-0005` through `B004-MCP-0007`, `B004-MCP-0012` through `B004-MCP-0014`, and `B004-MCP-0018` produced request-shape errors only. They are not behavioral evidence and did not require fallback analysis.

## Boundary And Function Evidence

Live MCP confirms the exact modeled function and boundary:

- `lookup_funcs` reports `0x005b6900` as `sub_5B6900`, size `0x11b` / 283.
- `lookup_funcs` reports `0x005b6a1b` is not a function and `0x005b6a20` is successor `sub_5B6A20`.
- `get_bytes 0x005b6a1b size 5` returns five `0xcc` bytes, so the target body ends at `0x005b6a1b` and alignment padding runs to `0x005b6a20`.
- `xrefs_to 0x005b6900` reports exactly three data xrefs: `0x0040ade3`, `0x0040b313`, and vtable/data slot `0x006306a4`; no direct code callers.
- `get_int 0x006306a4` returns decimal `5990656`, which `int_convert.py` confirms is `0x005b6900`. This is the direct dispatch slot for the target.
- `get_int 0x006306a8` returns decimal `5186944` / `0x004f2580`, confirming the next data slot is not a duplicate target pointer.

Live decompilation for `0x005b6900` has the following source-shape:

```c
if ((unsigned __int8)std::ctype<char>::do_narrow(*(_BYTE *)(event + 8), *(unsigned __int8 *)(event + 266)) != 63
    || *(_BYTE *)(event + 266) != 4
    || *(_BYTE *)(event + 4) != 8)
    return sub_4F2920(this, event);

sub_582B20(&localString);
for (it = *(void **)(dword_67A7C8 + 0x2918fc);
     it != *(void **)(dword_67A7C8 + 0x291900);
     ++it) {
    length = sub_584CF0(it);
    sub_584320(&localString, it, 0, length);
    sub_5843D0(&localString, 1, 0x0a);
}
alertBlock = sub_4F4AA0(0x270);
if (alertBlock) {
    sub_49FEB0(alertBlock, sub_584540(&localString), dword_67A764, &off_613A18, 0);
}
sub_582B70(&localString);
return 1;
```

The raw IDA name `std::ctype<char>::do_narrow` is not a source owner. `B004-MCP-0020` confirms the function at `0x004a8b10` is a 10-byte helper that returns the first byte argument. [UID:000117][EventManAndEventFactoryHelpers](../../../../../by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) and [UID:000071][EventMan](../../../../../by-class/EventMan.md) identify the project-level role as the shared narrow/translated key helper. The accepted source-facing spelling from the closest sibling is `NarrowInputKey`.

The numeric conversions used here were checked with `source-3/project-documentation/tools/int_convert.py`: `0x11b` is 283, `0x270` is 624, `0x2918fc` is 2693372, `0x291900` is 2693376, `0x291904` is 2693380, `0x10a` is 266, `0x3f` is 63 and ASCII `?`, `0x0a` is 10, `0x04` is 4, and `0x08` is 8.

## Resolved Source-Quality Blockers

### Ctrl+`?` Gate

The target tests the same three fields as [UID:0001MP][SpellSpellInputPaneKeyInput](../../../../../by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md):

- Event key byte at `event + 0x08` is passed as the first argument to `0x004a8b10`.
- Event modifier/filter byte at `event + 0x10a` is passed as the second argument and separately compared with `4`.
- Event type byte at `event + 0x04` is compared with `8`.
- The translated/narrowed result is compared with `0x3f` / `?`.

The best source form is the accepted sibling form:

```cpp
const char key = NarrowInputKey(event->keyCode, event->narrowFallback);
```

The method handles the shortcut only when `key == '?'`, `event->narrowFallback == 4`, and `event->type == 8`. All other inputs call the base key handler. This resolves the stale "Ctrl+`?` gate" blocker without requiring final enum names.

### Event And Message Fields

Use the current shared `InputEvent` aliases already accepted in [UID:0001MP]:

- `event->type` for `+0x04`, value `8`, documented as key-down/key-input event kind by EventMan support pages.
- `event->keyCode` for `+0x08`, the key byte passed to the narrow helper.
- `event->narrowFallback` for `+0x10a`, the mode/modifier/filter byte. The value `4` is the same shortcut mode observed in the accepted spell-help key handler.

Do not preserve the raw CRT-style helper label in source. Do not invent a new event structure for this method alone. The exact final field names remain a shared EventMan/InputEvent naming cap, but the target has enough sibling precedent for first-draft C++.

### Base `CharInputPane` Fallback

The fallback callee is `sub_4F2920`, size `0xaa`, documented as [UID:000362][CharInputPaneKeyAccept](../../../../../by-memory/0x004f2920-0x004f29ca.CharInputPaneKeyAccept.md). The source-facing fallback should be `CharInputPane::OnKeyInput(event)` to match the accepted `SpellSpellInputPane::OnKeyInput` body. The older [UID:00009Y][CharInputPane](../../../../../by-class/CharInputPane.md) method row label `OnCharInput` is descriptive for the base behavior, not a reason to keep this target's C++ blank.

### Block-List Vector Naming And Source Route

The loop reads:

- `dword_67A7C8` as `g_pConfig`.
- `g_pConfig + 0x2918fc` as vector begin.
- `g_pConfig + 0x291900` as vector end.
- Support layout [SimpleUStringVectorLayout](../../../../../by-type/by-struct/SimpleUStringVectorLayout.md) identifies this as a vector of one-pointer wide-string objects, with capacity naturally at `+0x291904`.

[UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md) already routes this field cluster through the social block-list feature and records the best field-name direction as `Config::m_blockListenNames` / `m_blockListNames`. For this target, `m_blockListenNames` is the stronger spelling because the owning source file and classes consistently use the `BlockListen` feature name. Config remains a dependency owner for storage, not the method owner or source file route.

### String Accumulation

The string path maps directly to `StringBase`/`SimpleUString` operations documented in local support pages:

- [UID:0002AO][StringBaseShareAssignAndAccess](../../../../../by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md): `0x00582b20` initializes an empty wide string and `0x00582b70` releases it.
- [UID:0002AP][StringBaseAppendAndFind](../../../../../by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md): `0x00584320` appends a wide slice from another string, `0x005843d0` appends repeated wide characters, and `0x00584540` returns the string data pointer.
- [UID:0002AQ][StringBaseSpliceGrowAndSubstring](../../../../../by-memory/0x00584990-0x00584d7e.StringBaseSpliceGrowAndSubstring.md): `0x00584cf0` returns string length.

The loop appends each full block-list name and then appends one newline (`0x0a`). It does not suppress the trailing newline. Source should preserve that behavior rather than trimming the final line break.

### Alert Creation Path

The alert sequence is source-owned by shared UI alert infrastructure:

- `sub_4F4AA0(0x270)` is [UID:0000SD][OperatorNewWrapper](../../../../../by-memory/0x004f4aa0-0x004f4ab4.OperatorNewWrapper.md). In source, use `new AlertPane(...)`.
- `sub_49FEB0` is [UID:0001A7][AlertPaneCore](../../../../../by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md), with constructor shape `AlertPane(const wchar_t *messageText, Pane *layoutReference, const wchar_t *primaryButtonText, const wchar_t *secondaryButtonText)`.
- `dword_67A764` is [UID:0000RD-related][ActiveMapPaneSingleton](../../../../../by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md), source-facing `g_activeMapPane`.
- `off_613A18` is [UID:0002IB][DialogOkButtonString](../../../../../by-memory/0x00613a18-0x00613a1e.DialogOkButtonString.md). Live `get_bytes` returns `4f 00 4b 00 00 00 00 00`, the UTF-16 `OK` label plus terminator/padding. Source should use the shared OK label alias `kDialogOkButtonText`, not the raw data label.
- The fifth pushed argument is `0`, matching null/no secondary button text.

The returned alert pointer is intentionally unused in this method. The constructor/dialog framework owns registration/lifetime side effects; the compiler's EH cleanup around the allocation is not source behavior to spell out.

## Ownership And Placement

Ranked route recommendation:

1. Direct owner/emitter remains [UID:00000X][BlockListenInputPane](../../../../../by-class/BlockListenInputPane.md). The target is its key input override and is reached through its vtable/data slot.
2. Source file route remains [UID:0000HS][BlockListenInputPanes](../../../../../by-file/BlockListenInputPanes.md), under `NexusTK/social/BlockListenInputPanes.cpp`.
3. The aggregate [UID:0001MW][BlockListenInputPanes](../../../../../by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md) remains the exact local cluster route.
4. Dependency routes are [UID:00009Y][CharInputPane](../../../../../by-class/CharInputPane.md), [UID:000071][EventMan](../../../../../by-class/EventMan.md), [UID:0000RC/0000RD config globals](../../../../../by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md), [StringBase](../../../../../by-type/by-template/StringBaseTemplate.md), [UID:00003T][AlertPane](../../../../../by-class/AlertPane.md), and [UID:000084][AlertPanes](../../../../../by-file/AlertPanes.md).

Rejected owners:

- Do not route this target to Config. Config owns the vector storage, not the key handler.
- Do not route it to AlertPanes. AlertPanes owns the dialog class and shared OK label, not the feature-specific shortcut.
- Do not route it to StringBase helpers. They are generic container/string operations.
- Do not route it to EventMan or CRT. The key translator is a shared helper and the IDA CRT label is misleading at source level.
- Do not route it to `CharInputPane`. That is the fallback base implementation only.
- Do not split or merge with `0x005b6a20-0x005b6bff`; the successor is the command dispatcher and starts after five padding bytes.

## Heuristic Reanalysis

Positive evidence:

- The target is an IDA-modeled function with exact size `0x11b` / 283 and explicit five-byte padding before the successor.
- Decompilation is structurally simple and maps to a normal virtual key-input override.
- Vtable/data slot `0x006306a4` contains the target address.
- No direct callers are expected for this override; vtable/data dispatch is the correct route.
- The `?`/mode/type gate exactly matches a sibling source-ready `OnKeyInput` implementation.
- All callees have local support-page routes and source-facing names.
- The string and alert behavior is fully represented by existing project abstractions; no raw helper must be emitted into this target.

Negative evidence and caps:

- Final project-wide `InputEvent` field names are still inferred from sibling documentation rather than symbol-proven.
- The exact public facade spelling for the wide string type is still a source-facing choice. `SimpleUString` is the best current alias from the vector/string layout docs.
- The exact Config field spelling is not symbol-proven. `m_blockListenNames` is the best current feature-local spelling.
- The exact shared OK-label constant name is not symbol-proven. `kDialogOkButtonText` is the best current source-facing alias for `off_613A18`.
- The source name `HandleKeyEvent` appears in the current class row, but the accepted sibling and fallback style support `OnKeyInput`.

These negatives explain why the recommendation should be `90/91`, not final-audit quality. They do not justify retaining a blank C++ block.

The current C++ readiness gate is satisfied: the target is reconstructable, has a nonblank owner/emitter route through [UID:00000X], has a recommended average score above 85, and has exact formal first-draft source content.

## Split And Range

Keep the target range exactly `0x005b6900-0x005b6a1b`.

- Predecessor [UID:0001MV][0x005b68c0-0x005b6900.BlockListenInputPaneConstructor](../../../../../by-memory/0x005b68c0-0x005b6900.BlockListenInputPaneConstructor.md) ends at `0x005b6900`.
- Target `0x005b6900-0x005b6a1b` is the modeled key-input handler.
- `0x005b6a1b-0x005b6a20` is five bytes of `0xcc` padding.
- Successor [UID:0001MY][0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher](../../../../../by-memory/0x005b6a20-0x005b6bff.BlockListenInputPaneCommandDispatcher.md) starts at `0x005b6a20`.

No split or merge is recommended.

## Generated And Coverage State

Generated/project-level/manual coverage/tool-state files were not edited and should not be hand edited by B004 in this report-only phase.

- `auto-generated` outputs may still be stale because the target C++ block is blank in the by-memory page.
- `by-memory/-coverage-report.md` and any other `-coverage-report.md` files remain untouched.
- Validator/tool-state files remain untouched.
- If the supervisor accepts this report for implementation, generated refresh state should be reported after the scoped validator batch, not during this report-only pass.

Recommended supervisor-owned coverage-row text, if a coverage owner later refreshes manual coverage:

```markdown
    - [UID:0001MX][0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler](by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md) 0x005b6900-0x005b6a1b | virtual key input handler | BlockListenInputPaneKeyHandler : reconstructable : 90% : very strong : B004 2026-06-26 source-quality reanalysis confirms exact 0x11b/283-byte modeled handler, vtable/data slot 0x006306a4, Ctrl+? gate via event+0x08/event+0x10a/event+0x04, base CharInputPane fallback at 0x004f2920, block-list vector g_pConfig+0x2918fc/+0x291900, SimpleUString accumulation with per-name trailing newline, AlertPane allocation size 0x270 using active map pane and shared OK label, no direct callers expected due vtable route, and first-draft C++ readiness with shared InputEvent/Config/string/OK-label spelling caps.
```

## Implementation Callback Checklist

- [x] Lease only the immediate by-* files to edit, then release the leases immediately after the edit/validator batch. Proof: B004 leased only `by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md`, `by-class/BlockListenInputPane.md`, `by-file/BlockListenInputPanes.md`, and `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`; `python tools\leaser\leaser.py B004 unlease ...` returned `Success` for all four after validators. A final target-only lease for the stale fallback UID correction was also released with `Success`.
- [x] Update [UID:0001MX][by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md](../../../../../by-memory/0x005b6900-0x005b6a1b.BlockListenInputPaneKeyHandler.md): set `COMPLETION:90`, `CONFIDENCE:91`, keep owner/emitter/reconstructable fields, populate the exact `RECONSTRUCTION_CPP CODE` body from this report, and replace the stale blank-C++ blocker with the resolved event/string/config/alert evidence. Proof: target header now has `90/91`, owner/emitter/reconstructable unchanged, formal `BlockListenInputPane::OnKeyInput(const InputEvent *event)` C++ inserted exactly, and evidence notes preserve MCP session `80de0a67`, `0x11b`/283-byte body, vtable slot `0x006306a4`, no direct callers, padding, Ctrl+`?` gate, base fallback, `g_pConfig->m_blockListenNames`, `SimpleUString` trailing-newline accumulation, `AlertPane` path, and rejected raw-label/owner alternatives. The accepted report/goal fallback UID label `000362` was documented as stale because that UID is the number-input key-filter page; the target uses the exact `0x004f2920-0x004f29ca.CharInputPaneKeyAccept` path link while preserving the accepted fallback behavior.
- [x] Update [UID:00000X][by-class/BlockListenInputPane.md](../../../../../by-class/BlockListenInputPane.md): normalize or cross-note the method row from `HandleKeyEvent(...)` to the source-facing `BlockListenInputPane::OnKeyInput(const InputEvent *)`, record the Ctrl+`?` alert behavior, base fallback, and target C++ readiness. Proof: method map row now names `BlockListenInputPane::OnKeyInput(const InputEvent *)`, notes the earlier descriptive alias, and evidence/parent-chain/score/change sections record the B004 target C++ readiness and behavior.
- [x] Update [UID:0000HS][by-file/BlockListenInputPanes.md](../../../../../by-file/BlockListenInputPanes.md): record that [UID:0001MX] now has source-ready first-draft C++ in `NexusTK/social/BlockListenInputPanes.cpp`; keep Config, StringBase, AlertPane, EventMan, and CharInputPane as dependencies rather than owners. Proof: proposed-contents row, IDA MCP evidence, ownership notes, and change log now record [UID:0001MX] as source-ready `OnKeyInput` in the social file route and preserve dependency/rejected-owner alternatives.
- [x] Update [UID:0001MW][by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md](../../../../../by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md): mark the child target source-ready, preserve the exact range and sibling boundaries, and keep the command dispatcher as a separate unresolved body. Proof: covered-range row and child-disposition table now mark [UID:0001MX] as `90/91` with formal first-draft C++ present, keep range `0x005b6900-0x005b6a1b`, preserve five-byte padding before [UID:0001MY], and state the dispatcher remains separate.
- [x] If the implementation edits mention support dependency state, keep support changes limited to directly affected by-* docs and do not edit generated/project-level/manual coverage/tool-state/IDA DB files. Proof: manual edits were limited to the four accepted by-* docs plus this B004 report checklist; no manual edits were made to generated/project-level/manual coverage/tool-state/IDA DB files. Validator-owned side effects are reported separately.
- [x] Run the scoped validators listed in the accepted implementation callback for every changed by-* file and report validator command ids/timestamps. Proof: target validator `000000003111` at `2026-06-26T17:55:35-04:00` passed with `ok:1`, and final target validator `000000003119` at `2026-06-26T17:59:12-04:00` passed with `ok:1` after the stale fallback UID repair; `000000003112` at `2026-06-26T17:55:59-04:00` validated the class with `ok:1`; `000000003113` at `2026-06-26T17:56:07-04:00` validated the file with `ok:1`; `000000003114` at `2026-06-26T17:56:14-04:00` validated the aggregate with `ok:1`.
- [x] Report generated-refresh state without manually editing generated outputs. Proof: final target validator `000000003119` used `--wait-generated` and reported `generated_refresh: completed`; support validators `000000003112`, `000000003113`, and `000000003114` reported `generated_refresh: deferred`. Generated/project-level/tool-state changes were validator-owned side effects only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0001MX-BlockListenInputPaneKeyHandler-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0001MX-BlockListenInputPaneKeyHandler-source-quality.md","timestamp":"2026-06-26T18:02:21","uid":"0001MX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
