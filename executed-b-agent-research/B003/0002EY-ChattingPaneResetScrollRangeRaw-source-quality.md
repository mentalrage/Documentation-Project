** TARGET-REPORT-UID:0002EY **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002EY ChattingPane ResetScrollRange Raw Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: accept a source-quality repair for [UID:0002EY] by renaming the source-facing role from stale `ResetScrollRange` to `ChattingPane::ScrollToBottom()`, raising the page from `85/88` to `87/90`, and adding first-draft C++ on the exact raw child page.
- Final disposition: keep the exact range `0x0047fd40-0x0047fd68`, owner/emitter [UID:00001X] `ChattingPane`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_POSITION_OPTIONAL`. The body remains an IDA-unmodeled raw helper, but current MCP evidence proves a complete `thiscall` no-argument method body whose helper names and source placement are now resolved well enough for first-draft C++ under the active gate.
- Required action if accepted: rename the target page to `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`, update support docs and links from the old `ResetScrollRangeRaw` wording, add the C++ shown below, and leave `-coverage-report.md` edits to the supervisor.
- Confidence: high for bytes, boundaries, helper roles, owner/emitter, and source-file route; medium-high for the exact original spelling `ScrollToBottom` because no direct caller, vtable cell, string, or symbol names the helper. That remaining no-route condition caps the score but no longer blocks draft C++.

## Supporting Research

This report was produced under the project-level `ntk-b-agent-workflow` skill for assignment `B003-report-chatting-pane-reset-scroll-range-raw-source-quality-0002EY-mcp-20260623`. No by-* documentation, generated/project-level files, IDA DB state, tool state, or `-coverage-report.md` files were edited. No leases were required because this is report-only work in the B003 research folder.

## Target

- Target UID: `0002EY`.
- Current target path: `by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md`.
- Recommended target path after acceptance: `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`.
- Current metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001X`, blank emitter position, blank `RECONSTRUCTION_CPP`.
- Current owner/source route: [UID:00001X] `ChattingPane`, source-file route [UID:0000I5] `Chatting`, aggregate containment [UID:000104] `ChattingUI`.
- Current blocker text in the target and support docs: no IDA function model, no incoming xrefs, stale `ResetScrollRange`/range-setter wording, raw `sub_55E950`/`sub_55E910`/`sub_55EAE0` helper labels, and blank C++.

## Current Target State

The existing page is already range-correct and ownership-correct, but its role description is stale. The body does not "reset scroll range"; it reads the current vertical scroll position, reads the current vertical maximum, and applies the maximum as the new position. The current best source-facing role is "scroll to bottom" or "scroll to latest message", with `ScrollToBottom` preferred because the raw body is UI-scroll generic and does not inspect message objects.

Existing support docs confirm the target belongs to the `ChattingPane` family but still preserve old wording:

- `by-class/ChattingPane.md` calls it a "raw reset scroll range helper" and says it reads current/max and calls the shared range setter.
- `by-file/Chatting.md` lists it as the raw reset-scroll-range helper under the `ChattingPane` file contents.
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md` and `by-memory/-ignored.md` retain the old child title in range/padding references.
- `auto-generated/NexusTK/social/Chatting.cpp` contains a placeholder marker for [UID:0002EY] but no body; nearby generated first-draft children already use `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`. `ChattingPaneSetVisibleRowCount` still has one stale `SetScrollRange(0, currentPosition, maximumPosition)` call in generated output and should be synchronized to the accepted helper name if this report is implemented.

## Executive Recommendation

The old no-function/no-xref/helper-name blockers were actively rechecked under MCP session `80de0a67`. The exact raw bytes, padding, unique signature, helper xrefs, pointer-route negatives, and helper decompilations now support the following implementation-ready conclusion:

- Keep direct owner/emitter [UID:00001X] `ChattingPane`; reject direct file ownership, `ScrollablePane` ownership, `ChattingUI` aggregate ownership, no-owner/non-emitting, and merge into predecessor/successor functions.
- Rename the source-facing helper to `ChattingPane::ScrollToBottom()` and, if accepted, rename the by-memory page to `ChattingPaneScrollToBottomRaw.md`.
- Raise metadata to `COMPLETION:87`, `CONFIDENCE:90`. Completion stays below neighboring modeled functions because the helper still lacks an IDA function object and incoming route; confidence rises because the byte/range/helper-name/owner evidence is now current and target-specific.
- Add bounded first-draft C++ to the target. The no-route evidence remains a score cap and historical caveat, not a draft-C++ blocker, because the ABI, body, helper semantics, class owner, and source-file route are resolved and the function consumes only `this`.

## Supervisor Active Recheck

The assignment explicitly required this pass to resolve the old score/C++ blockers rather than repeating "no function", "no xrefs", or "helper names unresolved" as future work. I rechecked those blockers with live MCP, generated output, current support docs, and the archived B001 chatting-message-ingress report as a lead. No split or child creation is required because the existing exact child already covers only `0x0047fd40-0x0047fd68`; both neighboring spans are padding or separate modeled functions.

Every source-bearing item in scope has an implementation-ready decision:

- `0x0047fd40-0x0047fd68`: keep exact child, rename role/path, raise score, add first-draft `ScrollToBottom` C++.
- `0x0047fd3b-0x0047fd40`: preserve ignored five-byte `0xcc` padding.
- `0x0047fd68-0x0047fd70`: preserve ignored eight-byte `0xcc` padding.
- Predecessor [UID:0002EX] `0x0047fc70-0x0047fd3b`: no split change.
- Successor [UID:0002EZ] `0x0047fd70-0x0047ff80`: no split change.

## Inference Research Guidance Check

IDA facts, documentation evidence, and inference are separated below. The MCP-backed facts are byte/range/function/xref/helper-decompilation facts. Existing docs are used only after current MCP confirmation. Generated output and the archived B001 report are treated as leads, not authority. Stale Wave2/Wave3 language was not used as evidence.

The active by-structure rule that final C++ can be first-draft when `(completion + confidence) / 2 > 85` matters here: the recommended `87/90` score clears the gate after the old helper-name blocker is resolved. The remaining no-route condition is documented as a confidence/score cap rather than a code-entry blocker.

## Heuristic / Inference Reanalysis And Validation

### Raw body role

IDA disassembly shows:

```asm
0047FD40  push    esi
0047FD41  push    edi
0047FD42  push    0
0047FD44  mov     edi, ecx
0047FD46  call    sub_55E950
0047FD4B  push    0
0047FD4D  mov     ecx, edi
0047FD4F  movzx   esi, ax
0047FD52  call    sub_55E910
0047FD57  movzx   eax, ax
0047FD5A  mov     ecx, edi
0047FD5C  push    eax
0047FD5D  push    esi
0047FD5E  push    0
0047FD60  call    sub_55EAE0
0047FD65  pop     edi
0047FD66  pop     esi
0047FD67  retn
```

`sub_55E950(this, 0)` returns the vertical current position, `sub_55E910(this, 0)` returns the vertical maximum/range, and `sub_55EAE0(this, 0, current, maximum)` applies a selected-axis scroll movement. The target therefore scrolls the chat display to the vertical maximum. `ResetScrollRange` and `SetScrollRange` are rejected because the body does not recompute range or update the maximum; it uses the existing maximum as the target position.

Best source-facing name: `ChattingPane::ScrollToBottom()`.

Rejected names:

- `ResetScrollRange`: stale and behaviorally wrong; no range value is written or recomputed here.
- `SetScrollRange`: stale role alias for `0x0055eae0`; that helper applies a new position, refreshes dependent regions, and only early-outs when old and target positions match.
- `ScrollToLatestMessage`: plausible in the chat context, but the body only knows "vertical max" and has no message-list dependency.
- `SynchronizeScrollbars`: belongs to `0x0055e990`, not this helper.
- `ApplyScrollPositionToMaximum`: mechanically accurate but too decompiler-like for a source-facing method name.

### Shared helper names

Current MCP decompilation resolves the helper trio:

- `0x0055e950`: `ScrollablePane::GetScrollPosition(char axis)`. It selects the horizontal child at `this+0xf8` when axis is nonzero, vertical child at `this+0xfc` when axis is zero, and returns child word `+0xfe` or `0`.
- `0x0055e910`: `ScrollablePane::GetScrollMax(char axis)`. It selects the same child and returns child word `+0x100` or `0`.
- `0x0055eae0`: `ScrollablePane::ApplyScrollPosition(char axis, unsigned short oldPosition, unsigned short targetPosition)`. It early-outs if old and target match, updates the selected child current word at `+0xfe`, invokes child vslot `+0x20`, calls the pane virtual at primary vslot `+0x5c` to convert the delta, and refreshes/clips content/render regions.

These names match current accepted `ChattingPaneKeyboardScrollHandler` generated/source text and `ScrollablePaneCore` support docs. The only stale support code found is `SetVisibleRowCount` using `SetScrollRange` for the same `0x0055eae0` role; that should be corrected if this report is accepted.

### Reachability and source-shape status

MCP session `80de0a67` confirms no incoming xref to `0x0047fd40`, no backward data-flow edge, no absolute VA/RVA/raw-offset pointer hit, and no IDA function object at `0x0047fd40`. This proves no static route is currently known. It does not prove the bytes are non-source or unsafe to emit: the raw helper is bounded by `0xcc` padding, has a complete `thiscall` no-argument method shape, returns with plain `retn`, and uses the exact helper trio used by nearby `ChattingPane` modeled methods.

Best classification: real unreferenced or callback-adjacent local source helper emitted in the `ChattingPane` translation unit, not an inlined fragment and not padding. "Missed function target" is also true at the IDA-modeling level, but there is no evidence for a branch/call/vtable route into it. The target should remain a raw helper child rather than be merged or reclassified.

## Evidence Standards Used

Evidence types used:

- MCP `server_health`, `lookup_funcs`, `get_bytes`, `insn_query`, `decompile`, `callees`, `xrefs_to`, `xref_query`, `trace_data_flow`, `find_bytes`, and `make_signature_for_range`.
- Existing by-* docs for `ChattingPane`, `Chatting`, `ChattingUI`, sibling `ChattingPane` children, `ScrollablePaneCore`, and padding rows.
- Generated output `auto-generated/NexusTK/social/Chatting.cpp`.
- Archived B001 chatting-message-ingress report as a lead.
- Negative evidence for no xref, no pointer route, no vtable/callback route, no function model, and no full-body duplicate.

The evidence is strong enough to resolve behavior, owner, source placement, and first-draft C++ because all facts needed for a no-argument instance helper are current and consistent. The evidence is not strong enough to claim final original spelling or direct runtime reachability, so the recommendation is capped at `87/90`.

## Evidence Checked

### MCP session and health

- MCP endpoint: `http://127.0.0.1:13337/mcp`.
- Active database/session: `80de0a67`.
- `server_health(database=80de0a67)`: status `ok`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

### MCP function and boundary checks

- `lookup_funcs`:
  - `0x0047fd40`: not a function.
  - `0x0047fd68`: not a function.
  - `0x0047fd70`: `sub_47FD70`, size `0x1f0`.
  - `0x0047fc70`: `sub_47FC70`, size `0xcb`.
  - `0x0055e950`: `sub_55E950`, size `0x39`.
  - `0x0055e910`: `sub_55E910`, size `0x39`.
  - `0x0055eae0`: `sub_55EAE0`, size `0x120`.
  - `0x0055e990`: `sub_55E990`, size `0x145`.
- `get_bytes(0x0047fd3b, 0x35)` confirms five pre-padding `0xcc` bytes, the exact 40-byte target body, and eight post-padding `0xcc` bytes.
- `make_signature_for_range(0x0047fd40,0x0047fd68,wildcard_operands=false)`: exact body signature, unique, match at `0x47fd40`.
- `decompile(0x0047fd40)`: failed at `0x47fd40` because there is no function object; this is expected and confirms the raw/no-function state rather than an MCP outage.

### Bytes and hashes

Target bytes:

```text
56 57 6A 00 8B F9 E8 05 EC 0D 00 6A 00 8B CF 0F B7 F0 E8 B9 EB 0D 00 0F B7 C0 8B CF 50 56 6A 00 E8 7B ED 0D 00 5F 5E C3
```

- Length: `40` bytes.
- SHA256: `1094287b969ed7231c50a221a5bc1eba36f16c3307f8f1064ce3db72024071b3`.
- SHA16: `1094287b969ed723`.
- Pre-padding: `0x0047fd3b-0x0047fd40`, five bytes, all `0xcc`.
- Post-padding: `0x0047fd68-0x0047fd70`, eight bytes, all `0xcc`.

### MCP route and negative checks

- `xrefs_to(0x0047fd40)`: no xrefs.
- `xref_query(addr=0x0047fd40,direction=to,xref_type=any)`: no cross-references.
- `trace_data_flow(addr=0x0047fd40,direction=backward,max_depth=2)`: depth `0`, one node at `0x47fd40`, no edges.
- `find_bytes`:
  - VA little-endian `40 FD 47 00`: zero matches.
  - RVA little-endian `40 FD 07 00`: zero matches.
  - PE raw-offset little-endian `40 F1 07 00`: zero matches.
  - full 40-byte body: one match at `0x47fd40`.
- A broad `insn_query op_any=0x0047fd40` timed out once, but MCP remained responsive. Per supervisor instruction, the check was retried with smaller bounded ranges; the scoped Chatting range and subsequent smaller scans found no operand route. Because `xrefs_to`, `xref_query`, `trace_data_flow`, and `find_bytes` are all negative, no direct static route is known.
- The MCP `callers` method returned `Method 'callers' not found` in this server schema. This is not treated as unavailable MCP because `xrefs_to` returned caller-function context for all relevant code references.

### Helper xref inventories

`xrefs_to` for the helper trio confirms the target's calls sit inside the same helper family used by neighboring `ChattingPane` methods.

`0x0055e950` (`GetScrollPosition`) has 52 code xrefs:

```text
0x474ede[0x474ec0], 0x47ad9e[0x47ad80], 0x47f3ce[0x47f370], 0x47f46e[0x47f370], 0x47f4c2[0x47f370],
0x47f75c[0x47f6f0], 0x47f7d6[0x47f6f0], 0x47fc2f[0x47fbd0], 0x47fd46[fn:null], 0x4986da[fn:null],
0x4b2586[0x4b2580], 0x4b25bb[0x4b2580], 0x4b3244[0x4b3210], 0x4b3261[0x4b3210], 0x4f495e[0x4f4920],
0x4f49a8[0x4f4920], 0x567329[fn:null], 0x5673ed[0x567380], 0x567442[0x567380], 0x56bdc5[0x56bca0],
0x56bdd9[0x56bca0], 0x56be85[0x56be20], 0x56c3ad[0x56c300], 0x56c3c9[0x56c300], 0x56c667[0x56c630],
0x56c917[0x56c8e0], 0x570d08[0x570c80], 0x570e99[fn:null], 0x570f5d[0x570ef0], 0x585382[0x585360],
0x5853ed[0x585360], 0x585430[0x585360], 0x5855cb[0x585580], 0x585677[0x585580], 0x5862ac[fn:null],
0x586446[0x586440], 0x588a6c[0x588800], 0x588b88[0x588800], 0x5892b4[0x5892a0], 0x5893c3[0x589350],
0x5894c8[fn:null], 0x589cf6[fn:null], 0x58e970[0x58e890], 0x58e9f2[0x58e890], 0x594da4[0x594cb0],
0x594df4[0x594cb0], 0x5a1d9a[0x5a1cd0], 0x5a1ec2[0x5a1df0], 0x5a1f8d[0x5a1f20],
0x5a206a[0x5a1ff0], 0x5a20cf[0x5a1ff0], 0x5a2132[0x5a1ff0]
```

`0x0055e910` (`GetScrollMax`) has 27 code xrefs:

```text
0x474eee[0x474ec0], 0x47adae[0x47ad80], 0x47f3da[0x47f370], 0x47f47a[0x47f370], 0x47f7e2[0x47f6f0],
0x47fc3b[0x47fbd0], 0x47fd52[fn:null], 0x4986ca[fn:null], 0x4b25a0[0x4b2580], 0x4b3296[0x4b3210],
0x4b32a4[0x4b3210], 0x567431[0x567380], 0x58538e[0x585360], 0x5853f9[0x585360], 0x58543c[0x585360],
0x5855d7[0x585580], 0x585683[0x585580], 0x5862b8[fn:null], 0x586452[0x586440], 0x588a79[0x588800],
0x5892c0[0x5892a0], 0x5893cf[0x589350], 0x5894d4[fn:null], 0x589d02[fn:null], 0x58e97f[0x58e890],
0x58e9fe[0x58e890], 0x5a20be[0x5a1ff0]
```

`0x0055eae0` (`ApplyScrollPosition`) has 52 code xrefs:

```text
0x47f3e8[0x47f370], 0x47f488[0x47f370], 0x47f4d6[0x47f370], 0x47f4fe[0x47f370],
0x47f794[0x47f6f0], 0x47f7bc[0x47f6f0], 0x47f80c[0x47f6f0], 0x47f84d[0x47f6f0],
0x47fc49[0x47fbd0], 0x47fd60[fn:null], 0x4b25c8[0x4b2580], 0x4b32b2[0x4b3210],
0x4f4982[0x4f4920], 0x4f49ca[0x4f4920], 0x55e1a0[0x55dfd0], 0x55e5de[0x55e210],
0x55f04f[0x55ef50], 0x56733a[fn:null], 0x5673fe[0x567380], 0x567453[0x567380],
0x56bde6[0x56bca0], 0x56be92[0x56be20], 0x56c3da[0x56c300], 0x56c678[0x56c630],
0x56c928[0x56c8e0], 0x570d19[0x570c80], 0x570eaa[fn:null], 0x570f6e[0x570ef0],
0x58539c[0x585360], 0x585407[0x585360], 0x58544a[0x585360], 0x5855e5[0x585580],
0x585691[0x585580], 0x5862c6[fn:null], 0x586460[0x586440], 0x588a8a[0x588800],
0x588b99[0x588800], 0x5892ce[0x5892a0], 0x5893dd[0x589350], 0x5894e2[fn:null],
0x589d10[fn:null], 0x58e999[0x58e890], 0x58e9ad[0x58e890], 0x58ea1c[0x58e890],
0x594db5[0x594cb0], 0x594e05[0x594cb0], 0x5a1dab[0x5a1cd0], 0x5a1ed3[0x5a1df0],
0x5a1f9e[0x5a1f20], 0x5a207b[0x5a1ff0], 0x5a20e0[0x5a1ff0], 0x5a2143[0x5a1ff0]
```

`0x0055e990` (`SyncScrollbars`) has 43 code xrefs and is relevant as a nearby sibling helper but is not called by the target. In ChattingPane it appears at constructor calls `0x47f0e3`, `0x47f182`, AddIncomingMessage calls `0x47f3c5`, `0x47f424`, `0x47f454`, `0x47f4e8`, `0x47f505`, and SetVisibleRowCount call `0x47fc26`.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Remaining uncertainty |
| --- | --- | --- | --- | --- |
| Exact target range stays `0x0047fd40-0x0047fd68` | High | `get_bytes`, `lookup_funcs`, unique signature, padding before/after | Predecessor `sub_47FC70` and successor `sub_47FD70` checked | None |
| Existing name `ResetScrollRange` is stale | High | Body applies max position through `ApplyScrollPosition`; no range write | Helper decompilation and sibling generated code checked | None |
| Best source name is `ChattingPane::ScrollToBottom()` | Medium-high | Vertical axis zero, current/max read, target=max, chat-display class context | `ScrollToLatestMessage`, `SetScrollRange`, `SyncScrollbars` rejected | Exact original spelling unavailable |
| Owner/emitter remains `ChattingPane` [UID:00001X] | High | Class band, sibling methods, helper family, current docs | Direct file, aggregate, ScrollablePane, no-owner rejected | None |
| First-draft C++ is safe | Medium-high | ABI is `thiscall`, no args, no locals requiring type invention, helper names resolved, score clears gate | No incoming xrefs and no function model checked | Direct runtime caller remains unknown |
| No route is known | High | `xrefs_to`, `xref_query`, `trace_data_flow`, `find_bytes`, smaller `insn_query` retry | Pointer VA/RVA/raw and full-body duplicate checked | A dynamic/callback-only route could still exist but is not provable from current IDB |

## Positive Evidence Summary

- The raw span is exactly 40 bytes and bounded by `0xcc` padding on both sides.
- MCP confirms no modeled predecessor overlap: `sub_47FC70` ends at `0x0047fd3b`, then five `0xcc` bytes, then this body, then eight `0xcc` bytes before `sub_47FD70`.
- The body is a complete instance helper: `ecx` is preserved in `edi`, no stack arguments are consumed, and the function returns with `retn`.
- The body calls the same `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition` helpers used by `ChattingPaneAddIncomingMessage`, `ChattingPaneKeyboardScrollHandler`, and `ChattingPaneSetVisibleRowCount`.
- Current generated `Chatting.cpp` already uses `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition` in accepted siblings; [UID:0002EY] has only an empty marker because its C++ was previously blank.
- The archived B001 message-ingress report confirms the `ChattingPane` owner/source route for nearby message and scroll metric methods; it did not prove a better owner for this raw helper.

## IDA MCP Facts

- Function/range facts: no function at `0x0047fd40` or `0x0047fd68`; predecessor `sub_47FC70` size `0xcb`; successor `sub_47FD70` size `0x1f0`; helper functions modeled at `0x0055e950`, `0x0055e910`, `0x0055eae0`, and `0x0055e990`.
- Padding facts: `0x0047fd3b-0x0047fd40` and `0x0047fd68-0x0047fd70` are `0xcc` padding.
- Xref facts: no xref to the raw target start; helper xrefs place the target as the `fn:null` ChattingPane-local call site among modeled sibling calls.
- Type/helper facts: helper decompilation proves `axis` is a `char`/byte selector, returned positions are `unsigned short`/word values, and `ApplyScrollPosition` takes old and target positions.
- Negative IDA facts: no direct caller, no vtable data xref, no known pointer route, no duplicate full-body byte pattern, no decompilation because no function object exists.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0047fc70-0x0047fd3b` | [UID:0002EX] `ChattingPaneComputeLineCount` | modeled line-count method | true | `ChattingPane` | `87/90` current | no change |
| `0x0047fd3b-0x0047fd40` | ignored row | alignment padding | ignored | `ChattingUI`/neighbor rows | `100` coverage row | preserve |
| `0x0047fd40-0x0047fd68` | [UID:0002EY] current `ChattingPaneResetScrollRangeRaw`; recommended `ChattingPaneScrollToBottomRaw` | raw no-function `ScrollToBottom` helper | true | `ChattingPane` | recommend `87/90` | rename/score/C++ update |
| `0x0047fd68-0x0047fd70` | ignored row | alignment padding | ignored | `ChattingUI`/neighbor rows | current ignored | preserve |
| `0x0047fd70-0x0047ff80` | [UID:0002EZ] `ChatPacketType13Handler` | modeled packet handler | true | `Chatting`/packet route | current | no change |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0047fd40` | no xrefs to target start | no direct route into raw helper is known |
| `0x0047fd46` | calls `0x0055e950` | target reads vertical current position |
| `0x0047fd52` | calls `0x0055e910` | target reads vertical maximum position |
| `0x0047fd60` | calls `0x0055eae0` | target applies vertical position change to maximum |
| `0x0047f370` | sibling uses helper trio multiple times | AddIncomingMessage provides domain context |
| `0x0047f6f0` | sibling uses helper trio multiple times | KeyboardScrollHandler provides accepted names |
| `0x0047fbd0` | sibling uses `0x0055e990`, `0x0055e950`, `0x0055e910`, `0x0055eae0` | SetVisibleRowCount should use the same helper names |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- `ChattingPane.md` already attaches [UID:0002EY] to the class and records exact raw bytes, padding, no incoming xrefs, and helper calls.
- `Chatting.md` already places the range inside the `ChattingPane` file cluster.
- `ChattingUI.md` contains this child in the exact aggregate range after the modeled `ComputeLineCount` child.
- `ChattingPaneKeyboardScrollHandler.md` and generated `Chatting.cpp` already use `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`.
- `ScrollablePaneCore.md` documents the helper-family roles and raw/no-function xref caveat.

Existing docs that are stale or incomplete:

- [UID:0002EY] target title/body says `ResetScrollRangeRaw` and "range setter"; this is behaviorally stale.
- `ChattingPane.md`, `Chatting.md`, `ChattingUI.md`, `by-memory/-ignored.md`, and the by-memory coverage row use the old child title/path.
- `ChattingPaneSetVisibleRowCount.md` and generated `Chatting.cpp` still show `SetScrollRange(0, currentPosition, maximumPosition)` for `0x0055eae0`. The source-quality name should be `ApplyScrollPosition(0, currentPosition, maximumPosition)` or at minimum explicitly treat `SetScrollRange` as a rejected/historical alias.

Generated/coverage report state:

- `auto-generated/NexusTK/social/Chatting.cpp` has no [UID:0002EY] body, only an empty marker. That is consistent with the current blank C++ and should change only after by-* implementation is accepted and validators regenerate output.
- `by-memory/-coverage-report.md` currently has an `80%` row with old `ResetScrollRangeRaw` wording. Supervisor should replace it after validating implementation.

## Ranked Ownership Analysis

### 1. [UID:00001X] ChattingPane

- Evidence for: range lies inside the ChattingPane method band; siblings before and after are ChattingPane methods; helper trio is used by ChattingPane message and scroll methods; current docs already attach the page to ChattingPane; ABI is `thiscall` over the same pane object.
- Evidence against: no direct caller or vtable route names the method.
- Decision: keep `ChattingPane` as canonical owner and emitter.

### 2. [UID:0000I5] Chatting file

- Evidence for: source-file route owns the broader social/chat translation unit and generated output path `NexusTK/social/Chatting.cpp`.
- Evidence against: direct file ownership is weaker than the class owner for a `thiscall` instance method.
- Decision: keep as source-file route/support doc, not canonical owner/emitter.

### 3. [UID:000104] ChattingUI aggregate

- Evidence for: target lies inside the broad aggregate.
- Evidence against: aggregate covers many classes/handlers and should not own exact class-local source methods.
- Decision: update range inventory if accepted, but do not use as owner/emitter.

### 4. [UID:0000CF] ScrollablePane / helper-family owner

- Evidence for: target calls inherited/shared scroll helpers.
- Evidence against: body operates on a `ChattingPane` instance and lives in the ChattingPane range; helper callees do not own caller code.
- Decision: reject as owner; use for helper-name evidence only.

### 5. No-owner/non-emitting, dead helper, or merge into neighbor

- Evidence for: no incoming route is known.
- Evidence against: exact method-shaped body, `0xcc` padding, unique signature, and class-local helper calls prove source-bearing code, not padding or data. No neighbor range overlaps.
- Decision: reject no-owner and merge. Treat as raw source helper with no-route caveat.

## Source Placement

Recommended placement:

- Class method: `ChattingPane::ScrollToBottom()`.
- Source file route: [UID:0000I5] `Chatting`, generated path family `NexusTK/social/Chatting.cpp`.
- Exact child page: `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`.

Rejected placements:

- `ScrollablePane.cpp`: target is a caller over a `ChattingPane` object, not an inherited helper implementation.
- Packet-handler source ownership: successor `sub_47FD70` is separate, begins after padding, and has one xref from packet-router code; the raw helper has no packet parsing behavior.
- Free function in `Chatting.cpp`: ABI and field context are a class instance helper.
- Leaving IDA names as final source names: current helper decompilation and sibling docs provide stronger source-facing names.

## Range / Split / Padding / Reclassification Analysis

No split is required. The existing target is already exact and should be repaired in place/renamed.

- Preserve predecessor [UID:0002EX] `0x0047fc70-0x0047fd3b` as modeled `ChattingPaneComputeLineCount`.
- Preserve `0x0047fd3b-0x0047fd40` as five-byte `0xcc` padding; update the padding row text/link only if the target is renamed.
- Preserve [UID:0002EY] as exact raw helper `0x0047fd40-0x0047fd68`; recommended new path/name `ChattingPaneScrollToBottomRaw`.
- Preserve `0x0047fd68-0x0047fd70` as eight-byte `0xcc` padding; update the padding row text/link only if the target is renamed.
- Preserve successor [UID:0002EZ] `0x0047fd70-0x0047ff80` as separate modeled packet handler.

Reclassification to padding/data is rejected because the body has valid call instructions, saves/restores registers, and returns. Reclassification to a broad aggregate is rejected because exact child coverage already exists and should carry the source body.

## Negative Evidence Summary

The following routes were checked and rejected:

- Direct code/data xrefs to `0x0047fd40`: none.
- Backward data-flow to `0x0047fd40`: none.
- Function model at `0x0047fd40` or `0x0047fd68`: none.
- VA/RVA/raw-offset pointer bytes to `0x0047fd40`: none.
- Full-body duplicate: none; unique match at `0x47fd40`.
- Direct vtable/callback route: none found; sibling vtable-routed scroll virtuals are elsewhere (`0x0047f520` onward), and the raw helper is not in that vtable cluster.
- Merge into predecessor `ComputeLineCount`: rejected by five-byte padding and separate behavior.
- Merge into successor `ChatPacketType13Handler`: rejected by eight-byte padding and separate function model/xref.
- Keep `ResetScrollRange` or `SetScrollRange`: rejected by helper semantics.

The unresolved route question is now a documented confidence cap. It is not a reason to leave score/C++ unchanged, because every reasonable current route check has been performed and the source body/name are otherwise resolved.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested in this report-only pass.

Source-facing names to use in documentation/C++:

- `ChattingPane::ScrollToBottom()` for [UID:0002EY].
- `ScrollablePane::GetScrollPosition(char axis)` for `0x0055e950`.
- `ScrollablePane::GetScrollMax(char axis)` for `0x0055e910`.
- `ScrollablePane::ApplyScrollPosition(char axis, unsigned short oldPosition, unsigned short targetPosition)` for `0x0055eae0`.
- `ScrollablePane::SyncScrollbars()` or `SynchronizeScrollbarsFromContent()` for `0x0055e990`; not called by [UID:0002EY], but relevant to support synchronization.

Names intentionally left as descriptive/inferred rather than original-proof: `ScrollToBottom` and `kVerticalAxis`. They are safe source-facing names for first-draft C++ but should not be treated as recovered symbols.

## First-Draft C++ Recommendation

Eligible for draft C++: yes, after the target is raised to `87/90`.

Recommended code:

```cpp
void ChattingPane::ScrollToBottom()
{
    constexpr unsigned char kVerticalAxis = 0;

    const unsigned short currentPosition = GetScrollPosition(kVerticalAxis);
    const unsigned short maximumPosition = GetScrollMax(kVerticalAxis);
    ApplyScrollPosition(kVerticalAxis, currentPosition, maximumPosition);
}
```

Why this preserves exact behavior:

- The body consumes no explicit stack arguments and returns `void`.
- `ecx` is the `ChattingPane`/`ScrollablePane`-derived object pointer.
- The first call pushes axis `0`, calls `GetScrollPosition`, and stores the returned word in `esi`.
- The second call pushes axis `0`, calls `GetScrollMax`, and keeps the returned word in `eax`.
- The final call passes axis `0`, old/current position, and maximum/target position to `ApplyScrollPosition`.

Why this matches likely source shape:

- Nearby generated and accepted C++ uses `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition` with vertical axis `0`.
- A no-argument `ScrollToBottom` helper is a natural private `ChattingPane` method around the same helper trio.
- The target body does not expose fields, heap allocation, packet data, or unresolved object types that would force unsafe source names.

No-code proof is not recommended. The prior blank-C++ rationale depended on unresolved helper names and call surface. Helper names are now resolved; no-route remains real but is not enough by itself to suppress a bounded raw child body that is exact, class-owned, and gate-cleared.

## Final Recommendation

Implement the following if the supervisor accepts this report:

- Rename [UID:0002EY] from `ChattingPaneResetScrollRangeRaw` to `ChattingPaneScrollToBottomRaw` while preserving UID and exact range.
- Update metadata to `COMPLETION:87`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001X`, and blank `EMITTER_POSITION_OPTIONAL`.
- Add first-draft `ChattingPane::ScrollToBottom()` C++ to the exact child.
- Update `ChattingPane`, `Chatting`, `ChattingUI`, `ChattingPaneSetVisibleRowCount`, and padding references to use `ScrollToBottom`, `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`.
- Preserve all negative route evidence and rejected alternatives so the no-route confidence cap is durable.

No child creation, range split, owner reassignment, or coverage-report edit should be performed by B003 during report-only work.

## Recommended Target Doc Changes

Target path:

- Rename current `by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md` to `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`.

Target metadata:

- Change `COMPLETION:85` to `COMPLETION:87`.
- Change `CONFIDENCE:88` to `CONFIDENCE:90`.
- Keep `CANONICAL_OWNER:00001X`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:00001X`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Populate `RECONSTRUCTION_CPP` with the recommended `ChattingPane::ScrollToBottom()` body.

Target facts to incorporate:

- MCP session `80de0a67`, health status, exact IDB/module/input path, and current schema caveat for `callers`.
- Exact range `0x0047fd40-0x0047fd68`, length `40`, bytes, SHA256/SHA16, pre-padding `0x0047fd3b-0x0047fd40`, post-padding `0x0047fd68-0x0047fd70`.
- Function model facts: no function at `0x0047fd40`/`0x0047fd68`; predecessor `sub_47FC70`; successor `sub_47FD70`.
- Helper decompilation facts: `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`, selected vertical axis `0`, child fields `+0xfe` and `+0x100`.
- Route negatives: no xrefs, no backward data-flow edges, no pointer/VA/RVA/raw route, no duplicate body, no vtable/callback route found.
- Rejected names and owners: `ResetScrollRange`, `SetScrollRange`, `ScrollToLatestMessage` as final name, direct file owner, `ScrollablePane` owner, aggregate owner, no-owner/non-emitting, merge with predecessor/successor.

## Recommended Support Doc Changes

- `by-class/ChattingPane.md`: replace "raw reset scroll range helper" with [UID:0002EY] `ChattingPane::ScrollToBottom()` / `ChattingPaneScrollToBottomRaw`; record current MCP evidence, helper names, no-route caveat, and first-draft C++ readiness. Keep class-level C++ blank unless already decided elsewhere.
- `by-file/Chatting.md`: update the `ChattingPane` row and source-route notes to say the exact raw child now emits bounded `ScrollToBottom` C++ through the `ChattingPane` owner, with no source-file split change.
- `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`: update the child inventory row/title/link and the current range-quality note; keep the broad aggregate C++ policy unchanged.
- `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`: replace stale `SetScrollRange(0, currentPosition, maximumPosition)` terminology with `ApplyScrollPosition(0, currentPosition, maximumPosition)` or explicitly mark `SetScrollRange` as historical alias rejected by the current helper decompilation. Metadata does not need to change unless the implementation materially changes its C++ block.
- `by-memory/-ignored.md`: update owner-doc links/text for `0x0047fd3b-0x0047fd40` and `0x0047fd68-0x0047fd70` only to reflect the renamed [UID:0002EY] path/title and current MCP padding evidence; do not alter padding ranges.
- `by-memory/0x0047f6f0-0x0047f890.ChattingPaneKeyboardScrollHandler.md`: no required edit; it already uses `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`.
- `by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md`: no required edit; it already records the helper family roles and raw/no-function xref caveat.
- `by-memory/0x0047f370-0x0047f512.ChattingPaneAddIncomingMessage.md`: no required edit for this target unless implementation finds a direct stale contradiction; current owner/helper-family route is sufficient.

## Score And Metadata Recommendation

Current score/metadata:

- `COMPLETION:85`, `CONFIDENCE:88`, owner/emitter [UID:00001X], reconstructable true, blank C++.

Recommended score/metadata:

- `COMPLETION:87`, `CONFIDENCE:90`, owner/emitter unchanged [UID:00001X], reconstructable true, blank emitter position, populated first-draft C++.

Reason for score increase:

- Helper-name blocker resolved from current helper decompilation and accepted sibling usage.
- Body role corrected from stale `ResetScrollRange` to `ScrollToBottom`.
- Route negatives refreshed with MCP session `80de0a67`.
- Exact bytes, SHA16, padding, unique signature, and no-function facts are now current and implementation-ready.
- First-draft C++ is now safe because the only unresolved element is direct route/original spelling, not behavior or type shape.

Reason not higher:

- IDA still has no function object at `0x0047fd40`.
- No incoming xref, pointer route, vtable slot, callback table entry, or original symbol/string names the helper.
- `ScrollToBottom` is a high-probability source-facing name, not original-proof.

Score-limiting blocker audit:

- No-function blocker: confirmed by `lookup_funcs` and `decompile`; resolved as "raw exact child, not split/merge"; still caps score.
- No-xref blocker: checked by `xrefs_to`, `xref_query`, `trace_data_flow`, `find_bytes`, and bounded operand checks; no route found; still caps score.
- Helper-name blocker: resolved; use `GetScrollPosition`, `GetScrollMax`, `ApplyScrollPosition`.
- Source-name blocker: resolved to best source-facing `ScrollToBottom`; exact original spelling remains confidence cap.
- Source-placement blocker: resolved to `ChattingPane` through `Chatting`.

## Open Questions With Attempted Resolution

- Is this reachable at runtime? Current answer: no static route is known. Evidence checked: xrefs, data-flow, pointer bytes, full-body uniqueness, helper-family xrefs, predecessor/successor boundaries. This remains unresolved but no longer blocks C++ because the body is exact and self-contained.
- Was the original name exactly `ScrollToBottom`? Current answer: not provable. `ScrollToBottom` is the best source-facing name because the body applies vertical maximum and does not inspect message objects. This caps confidence but is sufficient for first-draft C++.
- Should the method remain named `ResetScrollRange` because the file already uses that name? No. The current helper semantics directly contradict that role.
- Should this be split, merged, or reclassified? No. The exact child exists, is bounded, and is neither padding nor data.

## Exact Supervisor-Owned Coverage Text

Do not edit `by-memory/-coverage-report.md` during B-agent implementation. If accepted, supervisor should replace the current [UID:0002EY] row under [UID:000104] `ChattingUI`, between the `0x0047fd3b-0x0047fd40` padding row and the `0x0047fd68-0x0047fd70` padding/successor area, with:

```markdown
        - [UID:0002EY][0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw](by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md) 0x0047fd40-0x0047fd68 | raw helper | ChattingPaneScrollToBottomRaw : reconstructable : 87% : very-strong : B003 MCP session 80de0a67 confirms exact raw ChattingPane scroll-to-bottom helper body, SHA16 1094287b969ed723, no IDA-modeled function at 0x0047fd40/0x0047fd68, no incoming xrefs/backward data-flow/pointer-route to the raw start, unique body signature, five-byte and eight-byte 0xcc padding spans, predecessor sub_47FC70 and successor sub_47FD70 boundaries, helper calls resolved as GetScrollPosition(0), GetScrollMax(0), and ApplyScrollPosition(0,current,max), rejected stale ResetScrollRange/SetScrollRange wording, owner/emitter retained through ChattingPane, and bounded first-draft ChattingPane::ScrollToBottom C++ accepted while the no-route caveat remains a score cap.
```

If the supervisor chooses not to rename the file, use the same row text but keep the existing path/title; the report recommendation is to rename.

## Follow-Up Actions

- Supervisor: validate/accept or reject this report; if accepted, send an implementation callback for the target/support docs. Apply the coverage row after validating B003 implementation.
- B003 implementation callback if accepted: lease only immediately before editing existing docs, apply the exact target rename/score/C++/support changes, validate every changed by-* file, update this report's checklist with proof, then release leases.
- No A-agent or other B-agent work is required before this implementation package can be applied.

## Confidence

- Recommendation confidence: high for score/owner/source placement and medium-high for the exact new method name.
- Score confidence: high for `87/90`; lower or unchanged would ignore resolved helper-name/source-shape blockers, while higher would overstate the no-route/no-function uncertainty.
- Remaining uncertainty: direct runtime reachability and exact original spelling only.

## Validator Results

Implementation validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted edit batch:

> Executable block R001 was removed from this report and preserved verbatim in [0002EY-ChattingPaneResetScrollRangeRaw-source-quality-removed.md](0002EY-ChattingPaneResetScrollRangeRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- `by-memory\0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`: exit code `0`, `ok: 1`. Target-side side effects recorded by validator: `path_update` from `ChattingPaneResetScrollRangeRaw`, `completion_update 87`, `confidence_update 90`, `autogen_registry_update`, `autogen_cpp_update` for `auto-generated/NexusTK/social/Chatting.cpp`, `projected_stats_update`, `stats_row_remove 0002EY`, `uid_link_update` for the `ComputeLineCount` reference, and a temporary `uid_link_update` to `by-memory/-coverage-report.md` that B003 restored because coverage rows are supervisor-owned.
- `by-class\ChattingPane.md`: exit code `0`, `ok: 1`. Common validator side effects/warnings only: `projected_stats_update`, `autogen_registry_rebuild`, known stale registered missing files `0003E6`/`00026U`, explicit-children marker warnings, and pre-existing `autogen_cpp_conflict` warnings.
- `by-file\Chatting.md`: exit code `0`, `ok: 1`. Common validator side effects/warnings only: `projected_stats_update`, `autogen_registry_rebuild`, stale `0003E6`/`00026U`, explicit-children marker warnings, and pre-existing autogen C++ conflicts.
- `by-memory\0x0047efb0-0x00483ef7.ChattingUI.md`: exit code `0`, `ok: 1`. Common validator side effects/warnings only: `projected_stats_update`, `autogen_registry_rebuild`, stale `0003E6`/`00026U`, explicit-children marker warnings, and pre-existing autogen C++ conflicts.
- `by-memory\0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`: exit code `0`, `ok: 1`. Common validator side effects/warnings only: `projected_stats_update`, `autogen_registry_rebuild`, stale `0003E6`/`00026U`, explicit-children marker warnings, and pre-existing autogen C++ conflicts.
- `by-memory\-ignored.md`: exit code `0`, `ok: 1`. Warning includes existing `missing_ref_target 0003E6` for `by-memory/0x0062e960-0x0062e998.UserListDialogPaneVtableLeadInData.md`, plus common registry/children/autogen warnings.
- `by-memory\0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`: exit code `0`, `ok: 1`. This file was not part of the manual support edit set; it was leased and validated because the target rename validator updated its UID link to the new [UID:0002EY] path. Common side effects/warnings only.

Validator warnings not introduced by this implementation and left unresolved here: `autogen_registry_stale` for missing registered files `0003E6` and `00026U`, `missing_ref_target 0003E6` in `by-memory/-ignored.md`, explicit `[[CHILDREN]]` marker warnings, and pre-existing `autogen_cpp_conflict` warnings for generated files without validator sentinels.

Coverage report handling: the target validator attempted a UID-link update in `by-memory/-coverage-report.md`; B003 restored the [UID:0002EY] coverage row to the pre-callback supervisor-owned text. The exact replacement row remains in this report for supervisor-owned application after verification.

## Changed Files

- Renamed/deleted old target path: `by-memory/0x0047fd40-0x0047fd68.ChattingPaneResetScrollRangeRaw.md`.
- Created renamed target path: `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`.
- Modified: `by-class/ChattingPane.md`.
- Modified: `by-file/Chatting.md`.
- Modified: `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`.
- Modified: `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`.
- Modified: `by-memory/-ignored.md`.
- Validator link-cleanup touch/validated: `by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md`.
- Validator/generated side effects: `auto-generated/NexusTK/social/Chatting.cpp` and `project-level/-auto-completion-stats.md`; validators also reported `autogen_registry_rebuild` for `validator.ini`, with no final scoped diff observed for that file.
- Coverage reports: no B003 coverage row applied. Any non-0002EY working-tree differences in `*-coverage-report.md` files are outside this implementation.
- Report updated: `tools/leaser/Agents/Agent-B003/research/0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md`.
- Moved to executed: none.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: this report is report-only and no by-* docs were edited.
- [x] Current target state and evidence checked recorded. Proof: target metadata, owner/emitter, C++ state, stale wording, MCP session `80de0a67`, exact bytes/SHA, padding, function inventory, helper xrefs, route negatives, generated output, and archived B001 lead are documented above.
- [x] Score-limiting blockers researched to resolution or evidence-backed cap. Proof: no-function/no-xref/pointer-route blockers were rechecked; helper names and source role were resolved; no-route remains a score cap, not a C++ blocker.
- [x] Metadata/score changes to apply. Apply `85/88 -> 87/90`, keep owner/emitter/reconstructable/emitter-position state unchanged.
- [x] Owner/emitter/reconstructable changes to apply. No owner/emitter/reconstructable change; keep [UID:00001X] `ChattingPane`.
- [x] Split/rename/new-child changes to apply. Rename existing exact child path to `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`; no new child, split, merge, or range change.
- [x] Source-placement/range/padding/reclassification changes to apply or confirm not applicable. Keep source route [UID:0000I5] `Chatting`; preserve `0x0047fd3b-0x0047fd40` and `0x0047fd68-0x0047fd70` as padding; reject reclassification.
- [x] First-draft C++ or no-code proof to apply. Add `ChattingPane::ScrollToBottom()` C++ shown above; preserve no-route evidence as score cap.
- [x] Target/support docs to update listed. Required docs: target renamed path, `by-class/ChattingPane.md`, `by-file/Chatting.md`, `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`, `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`, and `by-memory/-ignored.md`.
- [x] Exact report facts to incorporate at implementation. Proof: target/support sections list exact bytes, SHA16, MCP calls, helper names, route negatives, owner/source placement, stale wording, and rejected alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: stale `ResetScrollRange`, stale `SetScrollRange`, no-route/no-function/pointer negatives, direct-file/ScrollablePane/aggregate/no-owner alternatives, and predecessor/successor merge rejections are documented.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale. Proof: none used as current evidence.
- [x] Open questions closed or documented as evidence-backed unresolved. Proof: reachability and exact original spelling remain unresolved with exact evidence and score/C++ impact documented.
- [x] Validators to run listed. Proof: scoped validator commands are listed above for every recommended changed by-* file.
- [x] Supervisor-owned coverage text supplied. Proof: exact replacement row for [UID:0002EY] is included above.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation. Proof: supervisor implementation callback accepted this report under assignment `B003-implement-chatting-pane-scroll-to-bottom-raw-source-quality-0002EY-mcp-20260623`.
- [x] Lease existing target/support docs only immediately before editing, then release after edit/validator batch. Proof: B003 leased the exact edit set before manual edits: old target path, `by-class/ChattingPane.md`, `by-file/Chatting.md`, `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md`, `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md`, and `by-memory/-ignored.md`; B003 also leased `by-memory/0x0047fc70-0x0047fd3b.ChattingPaneComputeLineCount.md` after validator link-cleanup touched it. Release proof: explicit `unlease` for `ComputeLineCount` returned `Success`; the original edit-set paths returned `No active lease` because they had already expired/released, and final `current_leases.md` shows no B003 lease rows.
- [x] Rename target file to `by-memory/0x0047fd40-0x0047fd68.ChattingPaneScrollToBottomRaw.md`, preserve UID `0002EY`, exact range, owner/emitter, reconstructable state, and blank emitter position. Proof: old file deleted, new file created with UID `0002EY`, range `0x0047fd40-0x0047fd68`, `CANONICAL_OWNER:00001X`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001X`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Update target metadata to `87/90` and add first-draft `ChattingPane::ScrollToBottom()` C++. Proof: target metadata is `COMPLETION:87`, `CONFIDENCE:90`; C++ block emits `void ChattingPane::ScrollToBottom()` with `GetScrollPosition`, `GetScrollMax`, and `ApplyScrollPosition`.
- [x] Update target body with MCP session `80de0a67`, bytes/SHA, padding, function inventory, helper decompilation, xref inventories, route negatives, support/source placement, rejected alternatives, and no-route score cap. Proof: target sections `Status`, `Behavior`, `Raw Code Evidence`, `Helper Semantics`, `Route And Xref Evidence`, `Rejected Alternatives`, `Score Rationale`, and `Changes` incorporate those facts.
- [x] Update `by-class/ChattingPane.md` at report-level detail for source-facing role, helper names, score/C++ readiness, and no-route caveat. Proof: class page method inventory and evidence notes now list [UID:0002EY] as `ScrollToBottom`, preserve no-route/no-function evidence as a score cap, and state the accepted first-draft C++ readiness.
- [x] Update `by-file/Chatting.md` for source-route/support note and renamed child inventory; do not force a source split. Proof: `Proposed Contents` and 2026-06-23 change note route [UID:0002EY] through `social/Chatting.cpp`, record accepted helper names/evidence, and explicitly keep no source split change.
- [x] Update `by-memory/0x0047efb0-0x00483ef7.ChattingUI.md` for renamed child inventory, score, and aggregate no-duplicate policy. Proof: aggregate inventory row now links `ChattingPaneScrollToBottomRaw` and change note records the target raise to `87/90`, first-draft child C++ placement, exact padding, route negatives, and blank aggregate policy.
- [x] Update `by-memory/0x0047fbd0-0x0047fc6b.ChattingPaneSetVisibleRowCount.md` to replace or explicitly reject stale `SetScrollRange` wording in favor of `ApplyScrollPosition`. Proof: formal C++ and behavior/source-shape notes use `ApplyScrollPosition(0, currentPosition, maximumPosition)` and document stale `SetScrollRange` as rejected by helper decompilation.
- [x] Update `by-memory/-ignored.md` owner-doc links/text for the two padding spans only as needed after target rename. Proof: padding entries `0x0047fd3b-0x0047fd40` and `0x0047fd68-0x0047fd70` now reference `ChattingPaneScrollToBottomRaw`, preserve exact spans, and cite MCP session `80de0a67`.
- [x] Preserve no required changes to `ChattingPaneKeyboardScrollHandler`, `ScrollablePaneCore`, and `ChattingPaneAddIncomingMessage` unless implementation finds a direct stale contradiction; if touched, validate and record proof. Proof: no direct stale contradiction was found in the accepted support scan; these files were not edited in this callback.
- [x] Run validators listed in this report and record command, exit code, `ok` count, warnings, and side effects. Proof: validator section above records all commands, exit code `0`, `ok: 1`, warnings, and side effects for every changed/touched by-* doc.
- [x] Do not edit any `-coverage-report.md`; leave the supplied row for supervisor-owned application. Proof: the target validator attempted a coverage UID-link update, but B003 restored [UID:0002EY] to the prior supervisor-owned coverage row. The exact replacement row remains above.
- [x] Update this checklist with checked items and proof after implementation. Proof: this checklist now records file-specific implementation proof, validation proof, side effects, coverage handling, and lease handling.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:16","uid":"0002EY"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002EY-ChattingPaneResetScrollRangeRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002EY-ChattingPaneResetScrollRangeRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002EY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
