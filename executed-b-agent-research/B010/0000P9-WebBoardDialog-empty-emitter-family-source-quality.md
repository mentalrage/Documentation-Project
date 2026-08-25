** TARGET-REPORT-UID:0000P9 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** TARGET: by-file/WebBoardDialog.md **
** ASSIGNMENT: B010-report-0000P9-WebBoardDialog-empty-emitter-family-20260630 **
** REPORT-TYPE: Empty-emitter family source-quality research **
** STATUS: FINALIZED REPORT - DO NOT IMPLEMENT UNTIL SUPERVISOR CALLBACK **

## Current Recommendation

[UID:0000P9] `by-file/WebBoardDialog.md` is correctly the source module owner for `NexusTK/ui/dialogs/WebBoardDialog.cpp`, but the generated file still contains 17 empty emitter markers. This revision resolves the previously rejected same-pass blockers instead of treating them as callback exclusions.

Recommended callback batch:

- Edit target root `by-file/WebBoardDialog.md` to add this empty-emitter family disposition and keep the source route in `NexusTK/ui/dialogs/`.
- Edit all 17 current empty-emitter support pages listed in this report.
- Edit `by-class/WebBoardDialog.md` and `by-class/WebBoardDialogOld.md` because the response handlers return truth values and the raw request/layout helpers now have source-facing declarations.
- Supervisor-verification repair: [UID:0003V1] `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md` is generated as support in the WebBoardDialog source route and must carry a nonblank no-duplicate/source-disposition marker. The active `EscapeWebBoardUrl` implementation and active support statics remain emitted through [UID:0000Z9]; do not duplicate that helper body on [UID:0003V1].
- Update active packet/response children [UID:0000Z8] and [UID:0000Z9] from file-owned to class-owned under [UID:0000G2].
- Keep old packet/response/layout/request children under [UID:0000G3].
- Promote packet forwarders, response handlers, input/request helpers, old constructor, old layout refresh, old mode-rect helper, and old initial request helper to first-draft formal C++.
- Keep marker-only C++ only where it prevents duplicate storage or documents compiler output: [UID:00033F], [UID:0002WJ], [UID:0002WK], [UID:000278], [UID:0002AG], and [UID:0002AH].
- Emit source-level singleton globals for [UID:0000SQ] and [UID:0000SR] as null-initialized pointers.

Recommended root metadata after callback:

```text
COMPLETION:91
CONFIDENCE:92
CANONICAL_OWNER:FILE
PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"
```

Score rationale: this revision now supplies first-draft source for the high-score code gates that were previously left marker-only, resolves the packet/event payload layout enough for source-quality `void *event` callbacks with a file-local `GetWebBoardPacketPayload` accessor, changes handler contracts to `bool`, resolves active/old response packet field order into best-supported length-prefixed source readers, promotes raw request helpers under the same retained-helper standard already accepted for `EscapeOldWebBoardUrl`, and makes URL support-data placement exact rather than deferred. The root should still remain below final quality because the response/parser code remains first-draft and several helper/control names are inferred rather than original-symbol proven.

## Current Target State

Current target page:

- [UID:0000P9] `by-file/WebBoardDialog.md`
- `COMPLETION:88`
- `CONFIDENCE:90`
- `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`
- `CANONICAL_OWNER:FILE`

Observed generated file:

- `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp`
- Header observed from validator command id `000000002418` during the revision pass
- Timestamp observed: `2026-06-30T05:25:47-04:00`
- Generated source UID: `0000P9`

Files With Empty Emitters queue row observed for this assignment:

```text
[UID:0000P9] WebBoardDialog | 24 emitters | 7 filled | 17 empty | 29.2% | auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp
```

Already filled generated emitters:

| UID | Generated source shape |
| --- | --- |
| 0000G2 | `class WebBoardDialog` declaration shell with `[[CHILDREN]]` |
| 0000Z7 | Active `WebBoardDialog` constructor body |
| 00020Y | Active destructor, close, and reposition bodies |
| 00033E | Active scalar deleting destructor source-disposition marker |
| 0000G3 | `class WebBoardDialogOld` declaration shell with `[[CHILDREN]]` |
| 000212 | Old destructor, close, and reposition bodies |
| 000214 | Old URL escape helper and old support static bodies |

Current generated empty emitters:

| UID | Path | Current score | Current owner/emitter |
| --- | --- | --- | --- |
| 00020Z | `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md` | 85/90 | 0000G2 |
| 0000ZA | `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md` | 85/88 | 0000G3 |
| 000211 | `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md` | 86/89 | 0000G3 |
| 0000ZB | `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md` | 88/90 | 0000G3 |
| 0000ZC | `by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md` | 90/92 | 0000G3 |
| 000213 | `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md` | 85/90 | 0000G3 |
| 0000ZD | `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md` | 86/90 | 0000G3 |
| 00033F | `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` | 85/88 | 0000G3 |
| 0000SQ | `by-global/g_pWebBoardDialog.md` | 86/90 | 0000P9 |
| 0002WJ | `by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md` | 86/90 | 0000SQ |
| 0000SR | `by-global/g_pWebBoardDialogOld.md` | 86/90 | 0000P9 |
| 0002WK | `by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md` | 86/90 | 0000SR |
| 0000Z8 | `by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md` | 90/92 | 0000P9 |
| 0000Z9 | `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md` | 86/90 | 0000P9 |
| 000278 | `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md` | 86/93 | 0000P9 |
| 0002AG | `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md` | 86/90 | 0000P9 |
| 0002AH | `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md` | 86/90 | 0000P9 |

## Evidence Checked

Workflow and assignment inputs:

- Read `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`.
- Read `references/b-agent-research-and-implementation-workflow.md`.
- Read `references/score-blocker-audit-standard.md`.
- Read `references/b-agent-report-template.md`.
- Read `source-3/project-documentation/by-structure.md` for schema-current MCP and ownership rules.
- Read `by-file/-guidance.md`.
- Read Agent-B010 `goal.md` for assignment `B010-report-0000P9-WebBoardDialog-empty-emitter-family-20260630`.

Target/support docs reviewed:

- `by-file/WebBoardDialog.md`
- `by-class/WebBoardDialog.md`
- `by-class/WebBoardDialogOld.md`
- `by-global/g_pWebBoardDialog.md`
- `by-global/g_pWebBoardDialogOld.md`
- All 17 current empty-emitter by-memory/by-global pages listed above.

Prior report search:

- Searched executed and active B-agent research folders for `0000P9`, `WebBoardDialog`, and all 17 empty child UIDs.
- No previous direct `0000P9-WebBoardDialog-empty-emitter-family` report was found.
- Matching child/family reports found and considered through current by-doc incorporation and direct inspection where needed:
  - `executed-b-agent-research/B001/000210-webboard-render-escape-source-split.md`
  - `executed-b-agent-research/B001/000211-webboard-oldmode-raw-rect-source-route.md`
  - `executed-b-agent-research/B002/00020X-00020Y-000212-browser-webboard-...`
  - `executed-b-agent-research/B002/00020Z-000213-webboard-request-source-quality.md`
  - `executed-b-agent-research/B004/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`
  - `executed-b-agent-research/B005/0000Z7-WebBoardDialog-source-quality.md`
  - `executed-b-agent-research/B006/000214-WebBoardDialogOldUrlEscapeHelper-source-quality.md`
  - `executed-b-agent-research/B008/0000G3-WebBoardDialogOld-class-source-quality.md`
  - `executed-b-agent-research/B010/0003V5-WebBoardDialogOldBrowserControlTeardownRaw-source-quality.md`
  - `executed-b-agent-research/B011/00033E-WebBoardDialogScalarDeletingDestructor-source-quality.md`

MCP availability and listener/process state:

- MCP endpoint used: `http://127.0.0.1:13337/mcp`
- `initialize` succeeded.
- MCP server: `ida-pro-mcp` `1.0.0`, protocol `2025-06-18`.
- `tools/list` succeeded; schema-current tools include `server_health`, `lookup_funcs`, `xrefs_to`, `analyze_batch`, `get_bytes`, and `get_global_value`.
- `idb_list` JSON-RPC id `3`: one active session `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker pid `17592`, active/owned/adopted.
- `server_health` JSON-RPC id `4`: status `ok`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready true, Hex-Rays ready true, strings cache ready true.

Schema note:

- One `xrefs_to` call using obsolete `addr` parameter failed with `missing required parameters: ['addrs']`.
- Retried with schema-current `addrs`, consistent with `by-structure.md`; the retry succeeded.

MCP function boundary evidence from `lookup_funcs` JSON-RPC id `7`:

| Address | MCP result |
| --- | --- |
| `0x0046d480` | `sub_46D480`, size `0x23` |
| `0x0046d4b0` | `sub_46D4B0`, size `0x5e` |
| `0x0046d510` | not a function |
| `0x0046d580` | `sub_46D580`, size `0x4e3` |
| `0x0046e2a0` | `sub_46E2A0`, size `0x216` |
| `0x0046e4c0` | not a function |
| `0x0046e640` | `sub_46E640`, size `0x27e` |
| `0x0046ea00` | `sub_46EA00`, size `0x23` |
| `0x0046ea30` | not a function |
| `0x0046eaa0` | `sub_46EAA0`, size `0x3da` |
| `0x004707f0` | `sub_4707F0`, size `0x5f` |
| `0x0067ab9c` | not a function |
| `0x0067aba0` | not a function |
| `0x0066d430` | not a function |
| `0x0067aba8` | not a function |
| `0x0067acb0` | not a function |

MCP xref evidence from `xrefs_to` JSON-RPC id `8`:

| Target | Xref result |
| --- | --- |
| `0x0046d480` | one data xref from active vtable `0x00613660` |
| `0x0046d510` | zero xrefs |
| `0x0046d580` | code refs from `0x0046d2a6` in `sub_46D050` and `0x0046d49e` in `sub_46D480` |
| `0x0046e2a0` | zero xrefs |
| `0x0046e4c0` | zero xrefs |
| `0x0046e640` | code refs from `0x00508ddd` in `sub_507C90` and `0x0051461e` in `sub_514580` |
| `0x0046ea00` | one data xref from old vtable `0x00613710` |
| `0x0046ea30` | zero xrefs |
| `0x0046eaa0` | code refs from `0x0046e850` in `sub_46E640` and `0x0046ea1e` in `sub_46EA00` |
| `0x004707f0` | code refs from adjustor region `0x004702ec`, `0x004702f7`, plus vtable data xref `0x0061368c` |
| `0x0067ab9c` | eight refs: `0x0046d0d1`, `0x0046d0d8`, `0x0046d330`, `0x00470250`, `0x00470796`, `0x00554d3f`, `0x005bd0a1`, `0x005bd20e` |
| `0x0067aba0` | five refs: `0x0046e6ba`, `0x0046e6c1`, `0x0046e8c0`, `0x00470260`, `0x004707f6` |
| `0x0066d430` | refs from active escape helper at `0x0046d74e`, `0x0046daad` |
| `0x0066d43c` | refs from active escape helper at `0x0046d7d0`, `0x0046db30` |
| `0x0066d44c` | refs from old escape helper at `0x0046ec5c`, `0x0046eebd` |
| `0x0066d458` | refs from old escape helper at `0x0046ece0`, `0x0046ef40` |
| `0x0067aba8` | four refs to active URL escape guard/table base |
| `0x0067abb0` | 24 refs to active URL escape table/body area |
| `0x0067acb0` | four refs to old URL escape guard/table base |
| `0x0067acb8` | 24 refs to old URL escape table/body area |

MCP decompiler and behavior evidence from `analyze_batch` JSON-RPC id `9`:

- `0x0046d480` decompiled as a `__thiscall` packet forwarder. It reads a payload pointer from event offset `+0x0c`, accepts only opcode `0x62`, returns false on mismatch, and tail-calls `sub_46D580(this-40, payload)`. The vtable xref is `0x00613660`; constants include `0x62`, `0x4`, and `-0xa0`.
- `0x0046ea00` is the old variant with the same opcode gate and tail-calls `sub_46EAA0(this-40, payload)`. The vtable xref is `0x00613710`.
- `0x004707f0` clears `unk_67ABA0`, sets BrowserPane-related vtables, calls the base destructor chain, and conditionally calls `sub_4F4AC0` when delete flags are set. This is a compiler scalar deleting destructor wrapper, not an ordinary source destructor body.
- `0x0046d4b0` is a key/input override. It handles event type `8`, key `'b'`, no modifier state, and calls `sub_49DF20(this-40)` on the accepted shortcut. It suppresses event code `0x90`; otherwise it falls through to `sub_49E6E0`. Vtable xref is `0x00613658`.
- `0x0046e2a0` is old layout refresh behavior. It rebuilds children at offsets `+0x278` and `+0x26c`, has mode-dependent close/browser/dialog rectangles, allocates sizes `276` and `824`, constructs through `sub_495BF0` and `sub_46B520`, and has no direct callers/xrefs.

MCP byte/global evidence from `get_bytes` JSON-RPC id `10` and `get_global_value` JSON-RPC id `11`:

- `0x0046d510` bytes show a retained raw helper that writes opcode `0x73`, copies one caller byte, sends length `2`, starts timer `0x572` for `0x4e20`, returns with `c2 04 00`, then padding `cc`.
- `0x0046ea30` bytes show the old retained raw helper that writes opcode `0x73`, writes zero payload byte, sends length `2`, starts timer `0x572` for `0x4e20`, returns with `c3`, then padding `cc`.
- `0x0046e4c0` bytes show a raw old mode-rectangle helper with local switch/jump-table behavior and rectangle constants; MCP still does not recognize it as a function and finds no inbound route.
- `0x0067ab9c` eight bytes read as zero, covering both singleton slots at `0x0067ab9c` and `0x0067aba0`.
- `get_global_value` returns `0x0` for `0x0067ab9c` and `0x0` for `0x0067aba0`.
- `0x0066d430` 56 bytes are two repeated URL escape character-set literal groups:
  - first group at `0x0066d430`: `$&+,/:=?@`
  - second group at `0x0066d43c`: space, `"`, `<`, `>`, `#`, `%`, `{`, `}`, `|`, `\`, `^`, `~`, `[`, `]`, ``` ` ```
  - repeated for old helper at `0x0066d44c` and `0x0066d458`
- `0x0067aba8` and `0x0067acb0` each read as 264 zero bytes.

Revision MCP evidence gathered after supervisor rejection:

- `decompile` JSON-RPC ids `100` and `101` prove both response handlers return `char` truth values: `sub_46D580` and `sub_46EAA0` both end normal paths with `return 1;` and range-check failures on oversize copies. This changes the best class source contract from `void HandleBoardResponse(...)` to `bool HandleBoardResponse(...)`.
- `decompile` JSON-RPC ids `102` and `103` prove the packet forwarders are body-ready: each reads the payload pointer at `event + 0x0c`, checks opcode byte `0x62`, returns `0` on mismatch, and returns the corresponding handler result on match after the compiler-applied `-0xa0` secondary-base adjustment.
- `decompile` JSON-RPC id `130` reconfirms the active key/input handler source shape: event type byte `8`, narrowed key `'b'`, modifier mask `& 7`, close/back call, NumLock `0x90` suppression, otherwise DialogPane input forwarding, and truth return.
- `decompile` JSON-RPC id `131` fails at raw `0x0046d510`, matching the no-function-object state, but current bytes and previous callee evidence still support first-draft body emission under the retained-helper standard already used for [UID:000214].
- `decompile` JSON-RPC id `132` provides a first-draft-ready old constructor body: fixed `WEBBOARD.EPD`/`WEBBOARD.PAD` frame, close button id `30`, browser rect `(30,30)-(510,334)`, singleton store, immediate-response branch, no-url request branch, opcode `0x73`, and timer `0x572`/`20000`.
- `decompile` JSON-RPC id `133` provides a first-draft-ready old layout refresh body: clears/refreshes old children, deletes/replaces close and browser controls at offsets `+0x278`/`+0x26c`, uses mode `0`/`4`/`6` rectangles, constructs close button id `14`, recreates BrowserControlPane with null initial URL, and resets pane state.
- `xrefs_to` JSON-RPC id `160` reconfirms zero direct xrefs to raw helper starts `0x0046d510`, `0x0046e4c0`, `0x0046ea30`, `0x0046da70`, and `0x0046ee80`. Under this revision, zero xrefs no longer blocks body emission when the body/source role is complete; it remains a confidence cap and retained-helper liveness fact.
- `get_bytes` JSON-RPC id `161` initially failed with `missing required parameters: ['regions']`; `get_bytes` JSON-RPC id `162` retried with schema-current `regions` and reconfirmed raw active request helper bytes, old mode-rect helper bytes including the switch tables, raw old request helper bytes, and zero-filled active/old URL escape state blocks.

## Ownership And Source-Placement Resolution

The direct owner for `WebBoardDialog.cpp` remains [UID:0000P9]. The file contains active WebBoard dialog source, old WebBoard dialog source, singleton globals, and URL escape support data.

The class pages are already legitimate class declaration emitters:

- [UID:0000G2] `WebBoardDialog` is a source class shell with `[[CHILDREN]]`. Its known children include constructor/destructor/close/reposition, input, packet forwarding, and response handling. The active class shell needs a signature update because current MCP proves `HandleBoardResponse` returns a truth value and the key handler can use the existing `InputEvent *` source-facing type.
- [UID:0000G3] `WebBoardDialogOld` is a source class shell with `[[CHILDREN]]`. Its known children include old constructor/destructor/close/reposition, layout refresh, mode rectangle helper relationship, packet forwarding, response handling, old request behavior, old scalar deleting destructor wrapper, and old URL escape helper relationships. The old class shell needs signature additions for `RefreshOldLayout`, `SendInitialBoardRequest`, and truth-valued `HandleBoardResponse`.

Recommended owner/emitter updates:

- [UID:0000Z8] should move from [UID:0000P9] to [UID:0000G2]. MCP proves this is a vtable-dispatched active `WebBoardDialog` packet callback, and [UID:0000G2] already declares the matching packet method route.
- [UID:0000Z9] should move from [UID:0000P9] to [UID:0000G2]. MCP proves it is called by the active constructor path and active packet forwarder, and [UID:0000G2] already declares `HandleBoardResponse`.

Recommended owner/emitter retentions:

- [UID:00020Z] remains under [UID:0000G2].
- [UID:0000ZA], [UID:000211], [UID:0000ZB], [UID:0000ZC], [UID:000213], [UID:0000ZD], and [UID:00033F] remain under [UID:0000G3].
- [UID:0000SQ] and [UID:0000SR] remain file-level globals under [UID:0000P9].
- [UID:0002WJ] and [UID:0002WK] remain exact storage children under their by-global owners.
- [UID:000278], [UID:0002AG], and [UID:0002AH] remain file-level support-data pages under [UID:0000P9].

## Per-UID Disposition

| UID | Callback disposition | Metadata recommendation | Source-shape rationale |
| --- | --- | --- | --- |
| 00020Z | Emit first-draft C++ for `WebBoardDialog::OnKeyEvent(InputEvent *)` and retained `WebBoardDialog::SendInitialBoardRequest(unsigned char)` | Raise to 88/91, owner/emitter `0000G2` | Current MCP and existing docs resolve the input-event role and raw helper body enough for source-quality code. The zero-xref raw helper fact remains documented as retained source-shaped code, not a no-code blocker. |
| 0000ZA | Emit first-draft `WebBoardDialogOld::RefreshOldLayout(int mode)` | Raise to 88/90, owner/emitter `0000G3` | Current MCP decompile resolves mode rectangles, child teardown/rebuild, close id `14`, BrowserControlPane recreation, and state reset. No entry xrefs remain a liveness caveat only. |
| 000211 | Emit first-draft `static void __stdcall GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)` | Raise to 89/91, owner/emitter `0000G3` | Current docs and MCP bytes resolve null-output, invalid-mode, invalid-selector no-write behavior and all mode/selector rectangles; the generated `SetModeControlRect` mismatch is fixed by choosing an exact `Get...Rect` source shape. |
| 0000ZB | Emit first-draft `WebBoardDialogOld::WebBoardDialogOld(const unsigned char *, OLECHAR *)` | Raise to 90/91, owner/emitter `0000G3` | Current MCP decompile resolves constructor parameters, fixed-art resources, child controls, singleton, immediate-response branch, no-url request branch, and timer/request behavior. |
| 0000ZC | Emit first-draft `WebBoardDialogOld::OnWebBoardPacket(void *event)` plus shared packet payload accessor | Raise to 91/93, owner/emitter `0000G3` | Current MCP resolves payload pointer at `event + 0x0c`, opcode `0x62`, false return, handler return propagation, and old class ownership. |
| 000213 | Emit first-draft retained `WebBoardDialogOld::SendInitialBoardRequest()` | Raise to 88/91, owner/emitter `0000G3` | Raw body and old constructor inline duplicate are complete; no-xref state is retained-helper liveness, not a body blocker. |
| 0000ZD | Emit first-draft `bool WebBoardDialogOld::HandleBoardResponse(const unsigned char *payload)` | Raise to 89/91, owner/emitter `0000G3` | Current MCP resolves bool return, length-prefixed field order, cookie extraction, old URL escape state/helper use, BrowserControlPane URL state update, and navigation. |
| 00033F | Insert scalar-deleting destructor marker | Raise to 86/90, owner/emitter `0000G3` | Compiler-generated wrapper; ordinary old destructor source is already [UID:000212]. |
| 0000SQ | Emit real singleton global definition | Raise to 88/92, owner/emitter `0000P9` | MCP reads current slot as zero; source shape is a null-initialized `WebBoardDialog*`. |
| 0002WJ | Insert covered-storage marker | Raise to 87/91, owner/emitter `0000SQ` | Exact storage is covered by by-global definition; do not duplicate storage. |
| 0000SR | Emit real singleton global definition | Raise to 88/92, owner/emitter `0000P9` | MCP reads current slot as zero; source shape is a null-initialized `WebBoardDialogOld*`. |
| 0002WK | Insert covered-storage marker | Raise to 87/91, owner/emitter `0000SR` | Exact storage is covered by by-global definition; do not duplicate storage. |
| 0000Z8 | Emit first-draft `WebBoardDialog::OnPacket(void *event)` | Raise to 91/93, change owner/emitter to `0000G2` | Vtable callback is class-owned; current MCP resolves packet payload offset, opcode gate, return contract, and handler call. |
| 0000Z9 | Emit first-draft `bool WebBoardDialog::HandleBoardResponse(const void *packet)` plus active URL escape helper/support statics | Raise to 89/91, change owner/emitter to `0000G2` | Current MCP resolves bool return, active special branch, normal field order, cookie extraction, active URL escape table, BrowserControlPane URL state update, and navigation. |
| 000278 | Insert exact covered-literal marker | Keep 86/93, owner/emitter `0000P9` | Active literals are emitted with [UID:0000Z9] because that block must appear before the active handler body uses them; old literals already emit with [UID:000214]. This page must not define duplicate static arrays. |
| 0002AG | Insert exact covered-storage marker | Keep 86/90, owner/emitter `0000P9` | Active guard/table storage is emitted with [UID:0000Z9] in generated order before active handler code uses it; this exact storage page documents address/xrefs and must not duplicate definitions. |
| 0002AH | Insert exact covered-storage marker | Keep 86/90, owner/emitter `0000P9` | Old guard/table storage is already emitted locally by [UID:000214], which precedes old response handler use in the generated file; duplicate storage here would be wrong. |

## Exact Formal RECONSTRUCTION_CPP Blocks

Every block below is the exact formal insertion text recommended for the implementation callback. These are not standalone summaries; they are the callback-ready `RECONSTRUCTION_CPP CODE` values to place on the named docs.

### [UID:00020Z] WebBoardDialogInputAndRequestHelpers

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const unsigned char kWebBoardInitialRequestOpcode = 0x73;
static const unsigned int kWebBoardRequestTimerId = 0x572;
static const unsigned int kWebBoardRequestTimerDuration = 20000;

bool WebBoardDialog::OnKeyEvent(InputEvent *event)
{
    const char key =
        NarrowInputCharacter(event->rawKey, event->modifierState);

    if (event->type == 8) {
        if (key == 'b' && (event->modifierState & 7) == 0) {
            CloseOrBackFromBoardOwner();
            return true;
        }

        if (event->rawKey == 0x90)
            return true;
    }

    DialogPane::OnKeyEvent(event);
    return true;
}

void WebBoardDialog::SendInitialBoardRequest(unsigned char boardMode)
{
    unsigned char packet[3];

    PacketBufferWriteByte(kWebBoardInitialRequestOpcode, &packet[0]);
    PacketBufferWriteByte(boardMode, &packet[1]);
    packet[2] = 0;

    QueueAndSendPacket(g_pPacketQueue, packet, 2);
    StartPaneTimer(kWebBoardRequestTimerId,
                   kWebBoardRequestTimerDuration,
                   0,
                   0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000ZA] WebBoardDialogOldLayoutRefresh

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void WebBoardDialogOld::RefreshOldLayout(int mode)
{
    ReleaseDialogControls();
    DetachDialogChildren();
    SetVisible(true);
    SetEnabled(false);

    if (m_closeButton != NULL)
        m_closeButton->Destroy(true);

    if (m_browserControlPane != NULL)
        m_browserControlPane->Destroy(true);

    Rect closeRect;
    if (mode == 0 || mode == 4)
        closeRect.Set(318, 468, 381, 492);
    else if (mode == 6)
        closeRect.Set(368, 568, 431, 592);

    m_closeButton = new ImageButtonControlPane(14, closeRect);
    AddChild(m_closeButton);

    Rect browserRect;
    if (mode == 0)
        browserRect.Set(11, 42, 689, 460);
    else if (mode == 4)
        browserRect.Set(11, 42, 407, 526);
    else if (mode == 6)
        browserRect.Set(11, 42, 789, 560);

    m_browserControlPane = new BrowserControlPane(browserRect, NULL, this);
    AddChild(m_browserControlPane);

    Rect dialogRect;
    if (mode == 0)
        dialogRect.Set(162, 134, 862, 634);
    else if (mode == 4)
        dialogRect.Set(303, 101, 721, 667);
    else if (mode == 6)
        dialogRect.Set(112, 84, 912, 684);

    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(false);
    SetEnabled(false);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000211] WebBoardDialogOldModeRectHelper

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall GetWebBoardDialogOldModeRect(Rect *out,
                                                   int selector,
                                                   int mode)
{
    if (out == NULL)
        return;

    switch (mode) {
    case 0:
        switch (selector) {
        case 0: out->Set(162, 134, 862, 634); break;
        case 1: out->Set(318, 468, 381, 492); break;
        case 2: out->Set(11, 42, 689, 460); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    case 4:
        switch (selector) {
        case 0: out->Set(303, 101, 721, 667); break;
        case 1: out->Set(318, 468, 381, 492); break;
        case 2: out->Set(11, 42, 407, 526); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    case 6:
        switch (selector) {
        case 0: out->Set(112, 84, 912, 684); break;
        case 1: out->Set(368, 568, 431, 592); break;
        case 2: out->Set(11, 42, 789, 560); break;
        case 3: out->Set(0, 0, 0, 0); break;
        default: break;
        }
        break;

    default:
        break;
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000ZB] WebBoardDialogOldConstructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialogOld::WebBoardDialogOld(const unsigned char *initialResponsePayload,
                                     OLECHAR *initialUrl)
    : BrowserPane(L"", -1, true),
      m_browserControlPane(NULL),
      m_closeButton(NULL)
{
    g_pWebBoardDialogOld = this;

    Rect frameRect(0, 0, 540, 379);
    ImagePane *frame =
        new ImagePane(L"WEBBOARD.EPD", frameRect, true, L"WEBBOARD.PAD");
    AddChild(frame);

    Rect closeRect(234, 342, 306, 358);
    m_closeButton = new ImageButtonControlPane(30, closeRect);
    AddChild(m_closeButton);

    Rect browserRect(30, 30, 510, 334);
    m_browserControlPane = new BrowserControlPane(browserRect,
                                                  initialUrl,
                                                  this);
    AddChild(m_browserControlPane);

    Rect dialogRect(50, 50, 590, 429);
    SetBackgroundImage(L"WEBBOARD.EPD", 0);
    SetPaneRect(dialogRect, 0, 0, g_layoutContext_69B374);
    SetScrollOffset(0, 0);
    FinishDialogSetup();
    SetVisible(true);
    SetEnabled(true);

    if (initialResponsePayload != NULL)
        HandleBoardResponse(initialResponsePayload);
    else if (initialUrl == NULL)
        SendInitialBoardRequest();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000ZC] WebBoardDialogOldPacketForwarder

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const unsigned char kWebBoardResponseOpcode = 0x62;

static const unsigned char *GetWebBoardPacketPayload(const void *event)
{
    const unsigned char * const *payloadSlot =
        reinterpret_cast<const unsigned char * const *>(
            static_cast<const unsigned char *>(event) + 0x0c);
    return *payloadSlot;
}

bool WebBoardDialogOld::OnWebBoardPacket(void *event)
{
    const unsigned char *payload = GetWebBoardPacketPayload(event);

    if (payload == NULL || payload[0] != kWebBoardResponseOpcode)
        return false;

    return HandleBoardResponse(payload);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000213] WebBoardDialogOldInitialRequestHelper

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void WebBoardDialogOld::SendInitialBoardRequest()
{
    unsigned char packet[3];

    PacketBufferWriteByte(kWebBoardInitialRequestOpcode, &packet[0]);
    PacketBufferWriteByte(0, &packet[1]);
    packet[2] = 0;

    QueueAndSendPacket(g_pPacketQueue, packet, 2);
    StartPaneTimer(kWebBoardRequestTimerId,
                   kWebBoardRequestTimerDuration,
                   0,
                   0);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000ZD] WebBoardDialogOldHandleBoardResponse

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static const unsigned char *CopyWebBoardPacketField(const unsigned char *cursor,
                                                    char *dest,
                                                    size_t destCapacity)
{
    const unsigned int length = *cursor++;

    if (length >= destCapacity)
        __report_rangecheckfailure(0);

    memcpy(dest, cursor, length);
    dest[length] = '\0';
    return cursor + length;
}

static const char *ExtractWebBoardCookieValue(const char *cookieData,
                                              char *domainValue,
                                              size_t domainCapacity,
                                              short *boardInfoLength)
{
    const char *equals = strchr(cookieData, '=');
    const char *ampersand = (equals != NULL) ? strchr(equals + 1, '&') : NULL;

    if (equals == NULL || ampersand == NULL)
        __report_rangecheckfailure(0);

    const size_t domainLength = static_cast<size_t>(ampersand - (equals + 1));
    if (domainLength >= domainCapacity)
        __report_rangecheckfailure(0);

    strncpy_s(domainValue, domainCapacity, equals + 1, domainLength);
    domainValue[domainLength] = '\0';

    const char *boardInfo = ampersand + 1;
    *boardInfoLength = static_cast<short>(strlen(boardInfo));
    return boardInfo;
}

bool WebBoardDialogOld::HandleBoardResponse(const unsigned char *payload)
{
    StopPaneTimer(kWebBoardRequestTimerId);

    const unsigned char *cursor = payload + 2;
    char url[256];
    char navigateTarget[256];
    char cookieData[256];
    char domainValue[128];
    char escapedBoardInfo[1024];
    wchar_t wideUrl[256];
    wchar_t wideTarget[256];

    cursor = CopyWebBoardPacketField(cursor, url, sizeof(url));
    cursor = CopyWebBoardPacketField(cursor, navigateTarget, sizeof(navigateTarget));
    cursor = CopyWebBoardPacketField(cursor, cookieData, sizeof(cookieData));

    short boardInfoLength = 0;
    const char *boardInfo = ExtractWebBoardCookieValue(cookieData,
                                                       domainValue,
                                                       sizeof(domainValue),
                                                       &boardInfoLength);

    InternetSetCookieA(url, "domain", domainValue);
    EscapeOldWebBoardUrl(boardInfo,
                         boardInfoLength,
                         escapedBoardInfo,
                         sizeof(escapedBoardInfo));
    InternetSetCookieA(url, "boardinfo", escapedBoardInfo);

    const int urlChars = MultiByteToWideChar(0, 0, url, strlen(url),
                                             wideUrl, 256);
    if (urlChars >= 256)
        __report_rangecheckfailure(0);
    wideUrl[urlChars] = 0;

    m_browserControlPane->SetCurrentUrl(wideUrl);

    const int targetChars = MultiByteToWideChar(0, 0,
                                                navigateTarget,
                                                strlen(navigateTarget),
                                                wideTarget,
                                                256);
    if (targetChars >= 256)
        __report_rangecheckfailure(0);
    wideTarget[targetChars] = 0;

    m_browserControlPane->Navigate(wideTarget, NULL);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00033F] WebBoardDialogOldScalarDeletingDestructor

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated scalar deleting destructor for WebBoardDialogOld.
// Source reconstruction is the virtual destructor declaration plus WebBoardDialogOld::~WebBoardDialogOld()
// emitted by [UID:000212]; do not hand-author this wrapper.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000SQ] g_pWebBoardDialog

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialog *g_pWebBoardDialog = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WJ] g_pWebBoardDialog Exact Storage

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pWebBoardDialog is covered by [UID:0000SQ]
// by-global/g_pWebBoardDialog.md.
// Current MCP reads the slot as zero-initialized; do not emit duplicate storage here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000SR] g_pWebBoardDialogOld

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
WebBoardDialogOld *g_pWebBoardDialogOld = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002WK] g_pWebBoardDialogOld Exact Storage

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted storage for g_pWebBoardDialogOld is covered by [UID:0000SR]
// by-global/g_pWebBoardDialogOld.md.
// Current MCP reads the slot as zero-initialized; do not emit duplicate storage here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000Z8] WebBoardDialogPacketForwarder

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool WebBoardDialog::OnPacket(void *event)
{
    const unsigned char *payload = GetWebBoardPacketPayload(event);

    if (payload == NULL || payload[0] != kWebBoardResponseOpcode)
        return false;

    return HandleBoardResponse(payload);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000Z9] WebBoardDialogHandleBoardResponse

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static bool s_webBoardUrlEscapeInitialized;
static unsigned char s_webBoardUrlEscapeTable[256];

static const char kWebBoardUrlReservedChars[] = "$&+,/:=?@";
static const char kWebBoardUrlUnsafeChars[] = " \"<>#%{}|\\^~[]`";

static void InitializeWebBoardUrlEscapeTable()
{
    if (s_webBoardUrlEscapeInitialized)
        return;

    for (int ch = 0; ch < 256; ++ch)
        s_webBoardUrlEscapeTable[ch] = (ch < 0x20 || ch >= 0x80) ? 1 : 0;

    for (int i = 0; i < 9; ++i)
        s_webBoardUrlEscapeTable[
            static_cast<unsigned char>(kWebBoardUrlReservedChars[i])] = 1;

    for (int i = 0; i < 15; ++i)
        s_webBoardUrlEscapeTable[
            static_cast<unsigned char>(kWebBoardUrlUnsafeChars[i])] = 1;

    s_webBoardUrlEscapeInitialized = true;
}

static char *EscapeWebBoardUrl(const char *source,
                               short sourceLength,
                               char *dest,
                               short destCapacity)
{
    InitializeWebBoardUrlEscapeTable();

    short sourceIndex = 0;
    short produced = 0;

    while (sourceIndex < sourceLength && produced < destCapacity - 3) {
        const unsigned char ch =
            static_cast<unsigned char>(source[sourceIndex]);

        if (s_webBoardUrlEscapeTable[ch] == 1) {
            sprintf_s(dest + produced,
                      destCapacity - produced,
                      "%%%2X",
                      static_cast<unsigned int>(ch));
            produced += 3;
        } else {
            dest[produced++] = static_cast<char>(ch);
        }

        ++sourceIndex;
    }

    dest[produced] = '\0';
    return dest;
}

bool WebBoardDialog::HandleBoardResponse(const void *packet)
{
    const unsigned char *payload =
        static_cast<const unsigned char *>(packet);

    StopPaneTimer(kWebBoardRequestTimerId);

    const unsigned char *cursor = payload + 1;
    const bool ownerPageResponse = (*cursor++ != 0);

    if (ownerPageResponse) {
        char baseUrl[256];
        char checkedField[256];
        wchar_t wideBaseUrl[512];
        wchar_t wideCheckedField[1024];
        wchar_t navigateUrl[1024];

        cursor = CopyWebBoardPacketField(cursor, baseUrl, sizeof(baseUrl));
        const int baseChars = MultiByteToWideChar(0, 0,
                                                  baseUrl,
                                                  strlen(baseUrl),
                                                  wideBaseUrl,
                                                  512);
        if (baseChars >= 512)
            __report_rangecheckfailure(0);
        wideBaseUrl[baseChars] = 0;

        cursor = CopyWebBoardPacketField(cursor,
                                         checkedField,
                                         sizeof(checkedField));
        const int checkedChars = MultiByteToWideChar(0, 0,
                                                     checkedField,
                                                     strlen(checkedField),
                                                     wideCheckedField,
                                                     1024);
        if (checkedChars >= 1024)
            __report_rangecheckfailure(0);
        wideCheckedField[checkedChars] = 0;

        swprintf_s(navigateUrl,
                   1024,
                   L"%s/%s.html",
                   wideBaseUrl,
                   m_boardOwnerName);
        m_browserControlPane->Navigate(navigateUrl, NULL);
        return true;
    }

    char url[256];
    char navigateTarget[256];
    char cookieData[256];
    char domainValue[128];
    char escapedBoardInfo[1024];
    wchar_t wideUrl[256];
    wchar_t wideTarget[256];

    cursor = CopyWebBoardPacketField(cursor, url, sizeof(url));
    cursor = CopyWebBoardPacketField(cursor, navigateTarget, sizeof(navigateTarget));
    cursor = CopyWebBoardPacketField(cursor, cookieData, sizeof(cookieData));

    short boardInfoLength = 0;
    const char *boardInfo = ExtractWebBoardCookieValue(cookieData,
                                                       domainValue,
                                                       sizeof(domainValue),
                                                       &boardInfoLength);

    InternetSetCookieA(url, "domain", domainValue);
    EscapeWebBoardUrl(boardInfo,
                      boardInfoLength,
                      escapedBoardInfo,
                      sizeof(escapedBoardInfo));
    InternetSetCookieA(url, "boardinfo", escapedBoardInfo);

    const int urlChars = MultiByteToWideChar(0, 0, url, strlen(url),
                                             wideUrl, 256);
    if (urlChars >= 256)
        __report_rangecheckfailure(0);
    wideUrl[urlChars] = 0;

    m_browserControlPane->SetCurrentUrl(wideUrl);

    const int targetChars = MultiByteToWideChar(0, 0,
                                                navigateTarget,
                                                strlen(navigateTarget),
                                                wideTarget,
                                                256);
    if (targetChars >= 256)
        __report_rangecheckfailure(0);
    wideTarget[targetChars] = 0;

    m_browserControlPane->Navigate(wideTarget, NULL);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000278] BrowserUrlEscapeCharacterSets

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// WebBoard URL escape character-set literals are documented here.
// Active literal definitions are emitted with [UID:0000Z9] so the active response
// parser and EscapeWebBoardUrl helper see them before use in generated order.
// Old literal definitions are already emitted with [UID:000214] EscapeOldWebBoardUrl.
// Do not emit duplicate table definitions from this exact support-data page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002AG] WebBoardDialogUrlEscapeState

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Active WebBoard URL escape guard/table storage is documented here.
// The source definitions are emitted with [UID:0000Z9] before the active
// response parser and EscapeWebBoardUrl helper use them in generated order.
// Do not emit duplicate static storage from this exact address page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002AH] WebBoardDialogOldUrlEscapeState

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Old WebBoard URL escape guard/table storage is documented here.
// The source definitions are already emitted with [UID:000214] EscapeOldWebBoardUrl,
// which appears before the old response parser in generated order.
// Do not emit duplicate static storage from this exact address page.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000G2] WebBoardDialog Class Shell Support Update

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WebBoardDialog : public BrowserPane {
public:
    WebBoardDialog(int boardMode,
                   const wchar_t *boardOwnerName,
                   const void *initialResponsePacket,
                   OLECHAR *initialUrl);
    virtual ~WebBoardDialog();
    virtual void OnCloseStateChanged(int state, int reason);
    virtual int OnInputEventWithBrowserReposition(void *event);
    virtual bool OnPacket(void *event);
    virtual bool OnKeyEvent(InputEvent *event);

    bool HandleBoardResponse(const void *packet);
    void SendInitialBoardRequest(unsigned char boardMode);

protected:
    BrowserControlPane *m_browserControlPane; // +0x26c
    ImageButtonControlPane *m_closeButton;    // +0x278
    wchar_t m_boardOwnerName[0x80];           // +0x27c
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0000G3] WebBoardDialogOld Class Shell Support Update

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class WebBoardDialogOld : public BrowserPane
{
public:
    WebBoardDialogOld(const unsigned char *initialResponsePayload,
                      OLECHAR *initialUrl);
    virtual ~WebBoardDialogOld();

    virtual void OnCloseStateChanged(int state, int reason);
    virtual bool OnInputEventWithBrowserReposition(InputEvent *event);
    virtual bool OnWebBoardPacket(void *event);

    void RefreshOldLayout(int mode);
    bool HandleBoardResponse(const unsigned char *payload);
    void SendInitialBoardRequest();

private:
    BrowserControlPane *m_browserControlPane; // +0x26c
    ImageButtonControlPane *m_closeButton;    // +0x278
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Blocker Conversion And Resolution

These are implementation-ready dispositions. Each item is resolved to a first-draft source shape, an exact support-doc repair, or a duplicate/compiler no-code proof.

| Topic | Resolution for this callback |
| --- | --- |
| Exact source file split | Resolved: keep all listed pages under `NexusTK/ui/dialogs/WebBoardDialog.cpp` through [UID:0000P9]. No split to `RankingDialog` or `Browser` support modules. |
| Packet/event typedefs | Resolved to first-draft `void *event` class signatures plus file-local `GetWebBoardPacketPayload(const void *event)`. MCP proves the only field needed in this pass is a payload pointer at `event + 0x0c`. A full engine packet-event struct would be broader than this file, so this callback records the offset in one source accessor instead of leaving bodies blank. |
| Handler return contracts | Resolved: both handlers return truth values. Update class declarations and child bodies to `bool HandleBoardResponse(...)`, and make both packet forwarders return handler results. |
| Active response packet layout | Resolved to best-supported first-draft parsing: byte `0` is opcode `0x62`, byte `1` is active special/owner-page flag, then length-prefixed fields. Special branch reads base URL and a checked second field, formats `L"%s/%s.html"` with `m_boardOwnerName`, and navigates. Normal branch reads URL, navigation target, and cookie/query data; extracts `domain` between `=` and `&`; escapes boardinfo after `&`; sets cookies and navigates. |
| Old response packet layout | Resolved to best-supported first-draft parsing: byte `0` is opcode `0x62`, byte `1` is read/ignored by the old handler, then the same normal length-prefixed URL, navigation target, and cookie/query fields begin at byte `2`. |
| Response packet/cookie/url field names | Resolved to source-quality names `url`, `navigateTarget`, `cookieData`, `domainValue`, and `boardInfo`. These are not original-symbol proven, but they are validated by `InternetSetCookieA(..., "domain", ...)`, `InternetSetCookieA(..., "boardinfo", ...)`, `MultiByteToWideChar`, browser URL-state writes, and final navigation. |
| Raw request helpers `0x0046d510` and `0x0046ea30` | Resolved to retained first-draft bodies. MCP still finds zero inbound xrefs, but byte behavior, constructor inline duplicates, opcode/timer roles, and class ownership are complete. Emit `WebBoardDialog::SendInitialBoardRequest(unsigned char)` and `WebBoardDialogOld::SendInitialBoardRequest()`; preserve the no-xref fact as a liveness caveat. |
| Old mode rectangle helper `0x0046e4c0` | Resolved to `static void __stdcall GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)`. The generated `SetModeControlRect` mismatch is rejected because it does not preserve no-write behavior for invalid mode/selector. This exact `Get...Rect` body preserves null output, valid modes `0`/`4`/`6`, selectors `0..3`, clear-rect case, and no-write defaults. |
| Old layout refresh `0x0046e2a0` | Resolved to first-draft `WebBoardDialogOld::RefreshOldLayout(int mode)`. MCP decompile now supplies enough child-rebuild detail for source C++; no entry xrefs remain a retained-helper liveness caveat only. |
| URL escape support-data placement | Resolved by generated-order and duplicate-definition audit. Active statics and active character-set literals emit with [UID:0000Z9] before `WebBoardDialog::HandleBoardResponse` uses them. Old statics and old literals remain with already-emitted [UID:000214] before `WebBoardDialogOld::HandleBoardResponse` uses `EscapeOldWebBoardUrl`. Exact data pages [UID:000278], [UID:0002AG], and [UID:0002AH] receive covered-storage/literal markers to prevent duplicate static definitions. |
| Active raw URL escape helper [UID:0003V1] | Supervisor verification after refresh `000000002569` proved [UID:0003V1] is generated in the WebBoardDialog source route and a blank formal C++ block became an empty-emitter marker. Resolved by inserting the exact no-duplicate/source-disposition marker below: active `EscapeWebBoardUrl` source and active support statics are emitted through [UID:0000Z9]; [UID:0003V1] documents the retained helper range only and must not duplicate the active helper body. |
| Singleton initializer conflict | Resolved by current MCP. The active and old singleton slots read as zero; callback should correct stale `0xffffffff` wording and emit source `NULL` pointer definitions on by-global pages only. |
| Scalar deleting destructor [UID:00033F] | Resolved as compiler-generated no-code marker. Ordinary source destructor remains [UID:000212]; no standalone wrapper source body should be emitted. |
| Missing or uncertain class method ownership for active packet/handler | Resolved for metadata. Move [UID:0000Z8] and [UID:0000Z9] to [UID:0000G2] because MCP proves vtable/caller class relationship and current class docs already declare the methods. |

Supervisor-verification repair marker for [UID:0003V1]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Active EscapeWebBoardUrl source is emitted with [UID:0000Z9]
// by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md.
// This raw helper page documents the retained helper range only; do not
// duplicate the active helper body, guard/table storage, or character literals here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Rejected Alternatives

Rejected: leave [UID:0000Z8] and [UID:0000ZC] marker-only because the full engine packet typedef is not named.

Reason: current MCP proves the only packet-event field needed here: payload pointer at `event + 0x0c`. The source-quality compromise is a file-local `GetWebBoardPacketPayload(const void *event)` accessor, not a blank body. The return contract is now resolved as truth-valued because both response handlers return `1` on success and packet forwarders return the handler result.

Rejected: invent a broad project-wide `WebBoardPacketEvent` or response-packet struct in this callback.

Reason: the assignment is a by-file empty-emitter repair, not a global engine-event type pass. The report resolves the local layout with helper functions and source-quality names while preserving exact offset/length facts. A global type can be introduced later without changing these method bodies.

Rejected: keep active/old response parsers marker-only because exact original packet field names are not proven.

Reason: same-pass MCP and docs resolve field order and behavior enough for first-draft source. The report uses inferred names `url`, `navigateTarget`, `cookieData`, `domainValue`, and `boardInfo`, validated by cookie names, URL conversion, browser-control state writes, and navigation. Lack of original spelling caps score but no longer blocks C++.

Rejected: keep raw request helpers [UID:00020Z] and [UID:000213] marker-only solely because current binary has no inbound call.

Reason: [UID:000214] already sets the local project precedent that a retained raw helper with no direct caller can emit first-draft C++ when the body, arguments, state, range, owner, and duplicate live path are fully documented. Both request helpers satisfy that standard now.

Rejected: keep [UID:000211] marker-only because generated `SetModeControlRect` does not match the binary.

Reason: that mismatch is resolved by rejecting the generated name and emitting exact `GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)` source. The first-draft body preserves no-write behavior for null output, invalid mode, and invalid selector.

Rejected: move URL escape support statics from already-emitted [UID:000214] into exact data pages in this callback.

Reason: generated order currently places [UID:000214] before old response handler [UID:0000ZD], and the old handler can call `EscapeOldWebBoardUrl` safely. Moving old statics to [UID:000278]/[UID:0002AH] would require editing an already-filled helper and adding forward declarations to avoid use-before-declaration. The better current repair is exact covered-storage markers on the data pages and no duplicate definitions.

Rejected: define active URL support statics on [UID:000278] and [UID:0002AG].

Reason: those pages emit after [UID:0000Z9] in current generated order, while the active handler body needs `s_webBoardUrlEscapeInitialized`, `s_webBoardUrlEscapeTable`, and the active literals before use. Emitting active support definitions inside [UID:0000Z9] is the only current callback-safe source placement that removes the empty marker and avoids order breakage.

Rejected: keep [UID:0000Z8] and [UID:0000Z9] directly file-owned.

Reason: both are active `WebBoardDialog` class behavior. [UID:0000Z8] is vtable-dispatched and [UID:0000Z9] is reached from the active constructor and packet forwarder. [UID:0000G2] is the correct direct owner; [UID:0000P9] remains the file/source-module ancestor.

Rejected: keep stale singleton initializer text that says the slots are `0xffffffff`.

Reason: current MCP `get_bytes` and `get_global_value` read both singleton slots as zero. Source-level singleton definitions should be null-initialized.

Rejected: emit exact storage children [UID:0002WJ] and [UID:0002WK] as separate pointer definitions.

Reason: the by-global pages are the source storage emitters. Exact storage pages should only document address/bytes and point to the by-global definition to avoid duplicate definitions.

## Score And Metadata Recommendations

Root:

- [UID:0000P9] `COMPLETION:91`, `CONFIDENCE:92`.
- Rationale: the callback resolves all current empty emitters as source definitions or exact duplicate/compiler markers, corrects class ownership for two active children, corrects singleton storage, promotes packet/response/request/layout/constructor bodies to first-draft C++, and closes URL support-data placement. The root should not rise above `91/92` because response parser names and several helper/control names remain inferred first-draft source rather than original-symbol proven final source.

Class pages:

- [UID:0000G2] keep score unless supervisor chooses a class score bump, but update formal C++ to `bool HandleBoardResponse(const void *packet)` and `virtual bool OnKeyEvent(InputEvent *event)`.
- [UID:0000G3] keep score unless supervisor chooses a class score bump, but update formal C++ to `WebBoardDialogOld(const unsigned char *initialResponsePayload, OLECHAR *initialUrl)`, `void RefreshOldLayout(int mode)`, `bool HandleBoardResponse(const unsigned char *payload)`, and `void SendInitialBoardRequest()`.

Promoted code pages:

- [UID:00020Z] `COMPLETION:88`, `CONFIDENCE:91`.
- [UID:0000ZA] `COMPLETION:88`, `CONFIDENCE:90`.
- [UID:000211] `COMPLETION:89`, `CONFIDENCE:91`.
- [UID:0000ZB] `COMPLETION:90`, `CONFIDENCE:91`.
- [UID:0000ZC] `COMPLETION:91`, `CONFIDENCE:93`.
- [UID:000213] `COMPLETION:88`, `CONFIDENCE:91`.
- [UID:0000ZD] `COMPLETION:89`, `CONFIDENCE:91`.
- [UID:0000Z8] `COMPLETION:91`, `CONFIDENCE:93`.
- [UID:0000Z9] `COMPLETION:89`, `CONFIDENCE:91`.

Global/storage pages:

- [UID:0000SQ] `COMPLETION:88`, `CONFIDENCE:92`; emit `WebBoardDialog *g_pWebBoardDialog = NULL;`.
- [UID:0000SR] `COMPLETION:88`, `CONFIDENCE:92`; emit `WebBoardDialogOld *g_pWebBoardDialogOld = NULL;`.
- [UID:0002WJ] `COMPLETION:87`, `CONFIDENCE:91`; marker-only covered storage under [UID:0000SQ].
- [UID:0002WK] `COMPLETION:87`, `CONFIDENCE:91`; marker-only covered storage under [UID:0000SR].

Compiler wrapper:

- [UID:00033F] `COMPLETION:86`, `CONFIDENCE:90`; marker-only compiler wrapper, ordinary destructor already [UID:000212].

Owner updates:

- [UID:0000Z8] `CANONICAL_OWNER:0000G2`, `EMITTER_UIDS:0000G2`.
- [UID:0000Z9] `CANONICAL_OWNER:0000G2`, `EMITTER_UIDS:0000G2`.

Support-data marker pages:

- [UID:000278] keep `86/93`; insert the covered-literal marker that names [UID:0000Z9] and [UID:000214] as the definition sites.
- [UID:0002AG] keep `86/90`; insert the covered-storage marker that names [UID:0000Z9] as the active definition site.
- [UID:0002AH] keep `86/90`; insert the covered-storage marker that names [UID:000214] as the old definition site.

## Implementation Callback Plan

Implementation callback was applied on 2026-06-30 after supervisor acceptance. Leases were taken in the three immediate edit batches below, scoped validators were run with `--wait-generated` after each batch, and explicit release attempts found no remaining active leases because the lease ledger had already cleared them by the time release was requested.

1. Batch A: root and class-routing docs.
   - `by-file/WebBoardDialog.md`
   - `by-class/WebBoardDialog.md`
   - `by-class/WebBoardDialogOld.md`
   - `by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md`
   - `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`
2. Batch B: active/old method first-draft bodies plus the old scalar-deleting-destructor marker.
   - `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md`
   - `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`
   - `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md`
   - `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md`
   - `by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md`
   - `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md`
   - `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`
   - `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`
3. Batch C: singleton globals and support data.
   - `by-global/g_pWebBoardDialog.md`
   - `by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md`
   - `by-global/g_pWebBoardDialogOld.md`
   - `by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md`
   - `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`
   - `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`
   - `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`
4. Supervisor-verification repair for the support page proven generated after refresh `000000002569`.
   - `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`
   - Purpose: replace the blank formal block with the exact no-duplicate/source-disposition marker, recording that active `EscapeWebBoardUrl` support is emitted through [UID:0000Z9] and must not be duplicated on [UID:0003V1].

All callback batches used scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation`. The latest B010 repair validators were `000000002571` for [UID:0003V1] and `000000002572` for `by-file/WebBoardDialog.md`, both with `--wait-generated`. Subsequent read-only freshness checks observed later generated header `validator-command-id: 000000002576` / `validator-refreshed-at: 2026-06-30T06:31:10-04:00` and last write `2026-06-30T06:31:15-04:00`; direct scans still found no generic empty-emitter terms and found the expected promoted bodies/markers, including the UID0003V1 no-duplicate marker.

## Claim And Incorporation Ledger

| Claim | Evidence | Callback incorporation target | Callback proof |
| --- | --- | --- | --- |
| Root `WebBoardDialog.cpp` source route remains `NexusTK/ui/dialogs/`. | Current target page and generated file header. | `by-file/WebBoardDialog.md` score/disposition section. | Applied `91/92` and the 17-emitter disposition to `by-file/WebBoardDialog.md`; validator `000000002467` exited `0`, `ok:1`. |
| There are 17 current empty emitters. | Empty-emitter tracker row and generated file inventory. | Root disposition plus all listed support pages. | All 17 current emitters received first-draft bodies or exact markers. Final generated scan of `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` found no empty-emitter terms. |
| Active and old response handlers return truth values. | MCP decompile ids `100`/`101`; packet forwarders return handler result. | Update `by-class/WebBoardDialog.md`, `by-class/WebBoardDialogOld.md`, [UID:0000Z9], and [UID:0000ZD] signatures/bodies. | Applied class signatures and handler bodies; validators `000000002468`, `000000002469`, `000000002472`, and `000000002506` all exited `0`, `ok:1`. |
| Packet event layout is resolved locally as payload pointer at `event + 0x0c`. | MCP decompile ids `102`/`103`. | Emit `GetWebBoardPacketPayload` in [UID:0000ZC]; use it from [UID:0000ZC]/[UID:0000Z8]. | Applied helper in [UID:0000ZC] and use in [UID:0000Z8]; validators `000000002470` and `000000002503` exited `0`, `ok:1`. |
| [UID:0000Z8] is an active class packet callback. | MCP `analyze_batch`/`decompile` `0x0046d480`, vtable xref `0x00613660`, tail-call to active handler. | Change owner/emitter to `0000G2`; insert first-draft body. | Applied owner/emitter `0000G2`, score `91/93`, and `WebBoardDialog::OnPacket`; validator `000000002470` exited `0`, `ok:1`. |
| [UID:0000Z9] is active class response parser behavior. | MCP xrefs from active constructor and packet forwarder; decompile id `100`. | Change owner/emitter to `0000G2`; insert first-draft body and active URL escape support. | Applied owner/emitter `0000G2`, score `89/91`, active parser body, and active URL escape support; validator `000000002472` exited `0`, `ok:1`. |
| [UID:0000ZC] is old class packet callback. | MCP `analyze_batch`/`decompile` `0x0046ea00`, vtable xref `0x00613710`. | Keep owner/emitter `0000G3`; insert first-draft body. | Applied score `91/93` and `WebBoardDialogOld::OnWebBoardPacket`; validator `000000002503` exited `0`, `ok:1`. |
| [UID:0000ZD] is old class response parser behavior. | MCP xrefs from old constructor and old packet forwarder; decompile id `101`. | Keep owner/emitter `0000G3`; insert first-draft body. | Applied score `89/91`, shared field helpers, and `WebBoardDialogOld::HandleBoardResponse`; validator `000000002506` exited `0`, `ok:1`. |
| Raw request helpers are retained body-ready helpers. | MCP zero xrefs id `160`; raw bytes id `162`; constructor duplicate branches. | Insert first-draft bodies on [UID:00020Z] and [UID:000213]; preserve no-xref liveness caveat. | Applied bodies and no-xref caveats; validators `000000002499` and `000000002504` exited `0`, `ok:1`. |
| Old layout refresh is body-ready. | MCP decompile id `133`; current docs with mode rectangles/child offsets. | Insert first-draft body on [UID:0000ZA]. | Applied `WebBoardDialogOld::RefreshOldLayout`; validator `000000002500` exited `0`, `ok:1`. |
| Old mode rectangle helper is body-ready with exact no-write defaults. | Current docs and MCP bytes id `162`; zero xrefs id `160`. | Insert first-draft `GetWebBoardDialogOldModeRect` body on [UID:000211]. | Applied static `__stdcall` body with invalid-input no-write defaults; validator `000000002501` exited `0`, `ok:1`. |
| Old constructor is body-ready. | MCP decompile id `132`; current docs for resources/callers/singleton. | Insert first-draft body on [UID:0000ZB]. | Applied score `90/91` and constructor body; validator `000000002502` exited `0`, `ok:1`. |
| [UID:00033F] is compiler-generated wrapper. | MCP wrapper decompile plus B011 active scalar-deleting destructor precedent. | Insert scalar-deleting destructor marker; raise to 86/90. | Applied comment-only wrapper marker and score `86/90`; validator `000000002508` exited `0`, `ok:1`. |
| Singleton slots are zero/null now. | MCP `get_bytes` and `get_global_value` for `0x0067ab9c` and `0x0067aba0`. | Emit by-global definitions and correct stale initializer wording. | Applied `WebBoardDialog *g_pWebBoardDialog = NULL;` and `WebBoardDialogOld *g_pWebBoardDialogOld = NULL;`; validators `000000002539` and `000000002543` exited `0`, `ok:1`. |
| Exact singleton storage children must not duplicate definitions. | Ownership hierarchy under by-global pages; duplicate-definition risk. | Insert covered-storage markers on [UID:0002WJ]/[UID:0002WK]. | Applied covered-storage markers and zero-initialized wording; validators `000000002541` and `000000002545` exited `0`, `ok:1`. |
| URL escape literals and state storage placement is resolved. | Generated order, [UID:000214] existing old definitions, MCP bytes/refs, active body needs definitions before use. | Emit active definitions in [UID:0000Z9]; keep old definitions in [UID:000214]; insert covered markers on [UID:000278], [UID:0002AG], [UID:0002AH]. | Applied [UID:0000Z9] active definitions plus marker-only [UID:000278]/[UID:0002AG]/[UID:0002AH]; validators `000000002472`, `000000002547`, `000000002549`, and `000000002550` exited `0`, `ok:1`. Optional [UID:0003V1] support note applied with validator `000000002551`, exit `0`, `ok:1`. |
| [UID:0003V1] support marker must not be blank. | Supervisor refresh `000000002569` still produced `Empty Emitter Marker` for [UID:0003V1]; generated route includes the support page. | Insert nonblank formal source-disposition marker on `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`; validate [UID:0003V1] and root file with `--wait-generated`. | Applied marker-only no-duplicate/source-disposition text; validators `000000002571` (`2026-06-30T06:28:28-04:00`) and `000000002572` (`2026-06-30T06:28:40-04:00`) both exited `0`, `ok:1`. Generated scan found UID0003V1 at lines `688-692` with no `Empty Emitter Marker` term. |

## Implementation Tracking Checklist

Report-only status:

- [x] Read project B-agent workflow skill.
- [x] Read Agent-B010 updated `goal.md`.
- [x] Confirmed no leases are needed or allowed for report-only research.
- [x] Confirmed MCP availability and active IDA listener/process state.
- [x] Used schema-current MCP calls after correcting the `xrefs_to` parameter.
- [x] Reviewed target root, class, global, and all current empty-emitter pages.
- [x] Searched prior executed and active reports for target/family/child UIDs.
- [x] Identified all 17 current empty emitters.
- [x] Resolved per-UID source disposition.
- [x] Revisited rejected blockers in the same pass: packet/event payload layout, handler returns, response field layout, raw request helpers, old mode rectangle helper, old layout refresh, URL support-data placement, and singleton storage.
- [x] Supplied exact formal `RECONSTRUCTION_CPP CODE` insertion text for every recommended body/marker, including support class shells.
- [x] Converted blockers into first-draft bodies, support-doc repairs, duplicate-definition markers, or compiler-wrapper no-code proofs.
- [x] Recommended score/metadata changes with rationale.
- [x] Did not edit by-* docs, generated files, coverage reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.
- [x] Did not spawn subagents.

Implementation callback checklist for supervisor validation:

- [x] Lease only the immediate batch of by-* files before editing. Proof: batches A/B/C were leased before edits; lease commands returned success for all targeted files.
- [x] Apply root score/disposition section to `by-file/WebBoardDialog.md`: `COMPLETION:91`, `CONFIDENCE:92`, current 17-empty-emitter disposition, and generated-order support-data policy. Proof: validator `000000002467`, exit `0`, `ok:1`.
- [x] Apply `by-class/WebBoardDialog.md` class-shell update: `bool HandleBoardResponse(const void *packet)` and `virtual bool OnKeyEvent(InputEvent *event)`. Proof: validator `000000002468`, exit `0`, `ok:1`.
- [x] Apply `by-class/WebBoardDialogOld.md` class-shell update: constructor `const unsigned char *`/`OLECHAR *`, `RefreshOldLayout(int mode)`, `bool HandleBoardResponse(const unsigned char *)`, and `SendInitialBoardRequest()`. Proof: validator `000000002469`, exit `0`, `ok:1`.
- [x] Apply [UID:0000Z8] owner/emitter change to `0000G2`, score `91/93`, and exact first-draft packet-forwarder body. Proof: validator `000000002470`, exit `0`, `ok:1`.
- [x] Apply [UID:0000Z9] owner/emitter change to `0000G2`, score `89/91`, and exact first-draft active response/escape body. Proof: validator `000000002472`, exit `0`, `ok:1`.
- [x] Apply exact first-draft bodies for [UID:00020Z], [UID:0000ZA], [UID:000211], [UID:0000ZB], [UID:0000ZC], [UID:000213], and [UID:0000ZD]. Proof: validators `000000002499`, `000000002500`, `000000002501`, `000000002502`, `000000002503`, `000000002504`, and `000000002506` exited `0`, `ok:1`.
- [x] Apply exact compiler-wrapper marker for [UID:00033F]. Proof: validator `000000002508`, exit `0`, `ok:1`.
- [x] Apply singleton by-global definitions for [UID:0000SQ] and [UID:0000SR], including stale initializer correction to current null/zero evidence. Proof: validators `000000002539` and `000000002543` exited `0`, `ok:1`.
- [x] Apply covered-storage markers for [UID:0002WJ] and [UID:0002WK]. Proof: validators `000000002541` and `000000002545` exited `0`, `ok:1`.
- [x] Apply covered-literal/storage markers for [UID:000278], [UID:0002AG], and [UID:0002AH] naming [UID:0000Z9] and [UID:000214] as definition sites. Proof: validators `000000002547`, `000000002549`, and `000000002550` exited `0`, `ok:1`.
- [x] Supervisor-verification repair: update [UID:0003V1] formal C++ from blank to the exact no-duplicate/source-disposition marker, because refresh `000000002569` still emitted an `Empty Emitter Marker` for this support page. Proof: validator `000000002571`, timestamp `2026-06-30T06:28:28-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validators for every changed by-* file and record command ids/timestamps/exits/ok counts/warnings. Proof: see Validator Results below.
- [x] Run the required root/file validation after the UID0003V1 repair. Proof: validator `000000002572`, timestamp `2026-06-30T06:28:40-04:00`, exit `0`, `ok:1`.
- [x] Release leases immediately after each edit/validator batch. Proof: UID0003V1 and `by-file/WebBoardDialog.md` repair release commands both reported `Success`, and final lease ledger scan returned `NO_MATCHING_ACTIVE_LEASES`.
- [x] Refresh/wait generated output if required and confirm generated freshness. Proof: every validator used `--wait-generated`; B010 repair root validator `000000002572` refreshed generated output, and a later read-only freshness check observed generated `WebBoardDialog.cpp` last write `2026-06-30T06:31:15-04:00` with header `validator-command-id: 000000002576` / `validator-refreshed-at: 2026-06-30T06:31:10-04:00`.
- [x] Confirm `WebBoardDialog.cpp` no longer contains the 17 current empty emitter markers or the supervisor-reported [UID:0003V1] empty marker. Proof: final scan found no `Empty Emitter Marker` terms and found UID0003V1 emitted as the no-duplicate marker at generated lines `688-692`.

## Validator Results

All validators were run from `E:/NTK/GhidraBridge/source-3/project-documentation` with `--mode file --apply --wait-generated`.

| File | command_id | command_timestamp | Exit | ok | Warning/counter notes |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/WebBoardDialog.md` | `000000002467` | `2026-06-30T06:03:42-04:00` | 0 | 1 | `autogen_children_marker_missing=59`, `autogen_emitter_has_no_code=338`, `missing_ref_uid=19` |
| `by-class/WebBoardDialog.md` | `000000002468` | `2026-06-30T06:03:53-04:00` | 0 | 1 | `autogen_children_marker_missing=59`, `autogen_emitter_has_no_code=338`, `missing_ref_uid=16` |
| `by-class/WebBoardDialogOld.md` | `000000002469` | `2026-06-30T06:04:03-04:00` | 0 | 1 | `autogen_children_marker_missing=59`, `autogen_emitter_has_no_code=338`, `missing_ref_uid=10` |
| `by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md` | `000000002470` | `2026-06-30T06:04:14-04:00` | 0 | 1 | `autogen_children_marker_missing=59`, `autogen_emitter_has_no_code=338` |
| `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md` | `000000002472` | `2026-06-30T06:04:25-04:00` | 0 | 1 | `autogen_children_marker_missing=59`, `autogen_emitter_has_no_code=338`, `missing_ref_uid=1` |
| `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md` | `000000002499` | `2026-06-30T06:10:55-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md` | `000000002500` | `2026-06-30T06:11:16-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md` | `000000002501` | `2026-06-30T06:11:27-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md` | `000000002502` | `2026-06-30T06:11:38-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336`, `missing_ref_uid=2` |
| `by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md` | `000000002503` | `2026-06-30T06:11:49-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md` | `000000002504` | `2026-06-30T06:12:01-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md` | `000000002506` | `2026-06-30T06:12:12-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md` | `000000002508` | `2026-06-30T06:12:32-04:00` | 0 | 1 | `autogen_children_marker_missing=52`, `autogen_emitter_has_no_code=336` |
| `by-global/g_pWebBoardDialog.md` | `000000002539` | `2026-06-30T06:18:03-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md` | `000000002541` | `2026-06-30T06:18:18-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-global/g_pWebBoardDialogOld.md` | `000000002543` | `2026-06-30T06:18:40-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md` | `000000002545` | `2026-06-30T06:19:02-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md` | `000000002547` | `2026-06-30T06:19:24-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md` | `000000002549` | `2026-06-30T06:19:45-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md` | `000000002550` | `2026-06-30T06:20:07-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md` | `000000002551` | `2026-06-30T06:20:18-04:00` | 0 | 1 | `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330` |
| `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md` | `000000002571` | `2026-06-30T06:28:28-04:00` | 0 | 1 | Supervisor-verification repair; `autogen_children_marker_missing=54`, `autogen_cpp_update=1`, `autogen_emitter_has_no_code=330`, `generated_refresh=completed` |
| `by-file/WebBoardDialog.md` | `000000002572` | `2026-06-30T06:28:40-04:00` | 0 | 1 | Post-repair root/file validation; `autogen_children_marker_missing=54`, `autogen_emitter_has_no_code=330`, `missing_ref_uid=16`, `generated_refresh=completed` |

Generated freshness proof: B010 repair validator `000000002572` refreshed `auto-generated/NexusTK/ui/dialogs/WebBoardDialog.cpp` with `--wait-generated`; a later read-only freshness check observed last write `2026-06-30T06:31:15-04:00`, header `validator-command-id: 000000002576` / `validator-refreshed-at: 2026-06-30T06:31:10-04:00`. Final scans found no empty-emitter terms and found the expected emitted lines for `WebBoardDialog::OnPacket`, `WebBoardDialog::OnKeyEvent`, `WebBoardDialog::HandleBoardResponse`, `WebBoardDialogOld::RefreshOldLayout`, `GetWebBoardDialogOldModeRect`, `WebBoardDialogOld::WebBoardDialogOld`, `WebBoardDialogOld::OnWebBoardPacket`, `WebBoardDialogOld::SendInitialBoardRequest`, `WebBoardDialogOld::HandleBoardResponse`, the old scalar-deleting-destructor marker, both singleton `NULL` definitions, duplicate-support markers, and the UID0003V1 no-duplicate marker at generated lines `688-692`.

## Changed Files

Changed by-* docs:

- `by-file/WebBoardDialog.md`
- `by-class/WebBoardDialog.md`
- `by-class/WebBoardDialogOld.md`
- `by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md`
- `by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md`
- `by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md`
- `by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md`
- `by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md`
- `by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md`
- `by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md`
- `by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md`
- `by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md`
- `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`
- `by-global/g_pWebBoardDialog.md`
- `by-memory/0x0067ab9c-0x0067aba0.g_pWebBoardDialog.md`
- `by-global/g_pWebBoardDialogOld.md`
- `by-memory/0x0067aba0-0x0067aba4.g_pWebBoardDialogOld.md`
- `by-memory/0x0066d430-0x0066d468.BrowserUrlEscapeCharacterSets.md`
- `by-memory/0x0067aba8-0x0067acb0.WebBoardDialogUrlEscapeState.md`
- `by-memory/0x0067acb0-0x0067adb8.WebBoardDialogOldUrlEscapeState.md`
- `by-memory/0x0046da70-0x0046dbca.WebBoardDialogUrlEscapeHelper.md`

Changed report:

- `tools/leaser/Agents/Agent-B010/research/0000P9-WebBoardDialog-empty-emitter-family-source-quality.md`

Validator-owned generated refresh occurred through `--wait-generated`; no generated file was hand-edited. No manual coverage reports, project-level reports, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files were edited by hand.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000P9-WebBoardDialog-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000P9-WebBoardDialog-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T06:33:07","uid":"0000P9"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
