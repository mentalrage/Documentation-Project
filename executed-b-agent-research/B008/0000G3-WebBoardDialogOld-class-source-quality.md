** TARGET-REPORT-UID:0000G3 **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000G3 WebBoardDialogOld Class Source-Quality Reanalysis

## Report Scope And Recommendation

- Target: [UID:0000G3] `by-class/WebBoardDialogOld.md`.
- Current target metadata checked: `COMPLETION:88`, `CONFIDENCE:85`, `CANONICAL_OWNER:0000P9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P9`, blank class C++.
- Required mode: report-only. This pass did not edit any by-* documentation file and did not edit `by-memory/-coverage-report.md`.
- Recommended target metadata after acceptance: `COMPLETION:90`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000P9`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P9`.
- Recommended source route: `NexusTK/ui/dialogs/WebBoardDialog.cpp` through [UID:0000P9] `WebBoardDialog`.
- Recommended class name: `WebBoardDialogOld`.
- Recommended owner strategy: keep the class page owned/emitted by the source file [UID:0000P9], but normalize class method children that are currently file-owned in metadata to direct class owner/emitter [UID:0000G3] where their own prose already identifies `WebBoardDialogOld` ownership.
- Recommended C++ strategy: the class page is eligible for a conservative first-draft declaration shell with `[[CHILDREN]]`. Do not emit standalone method bodies from the class page. Method bodies remain delegated to exact by-memory child pages. Raw no-route children keep blank formal C++ unless route evidence appears.

## Evidence Checked

Documentation read for this pass:

- Target [UID:0000G3] `by-class/WebBoardDialogOld.md`.
- Source owner [UID:0000P9] `by-file/WebBoardDialog.md`.
- Active sibling [UID:0000G2] `by-class/WebBoardDialog.md`.
- Ranking exclusion [UID:0000MZ] `by-file/RankingDialog.md`.
- Browser dependency boundary [UID:0000HV] `by-file/Browser.md`.
- Old fixed-art resource owner [UID:0001RT] `by-resource/webboard-dialog-resources.md`.
- Singleton [UID:0000SR] `by-global/g_pWebBoardDialogOld.md`.
- Mixed vtable/string index [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`.
- Cleanup/thunk support [UID:000336] `by-memory/0x004701d0-0x00470278.BrowserDialogCleanupAndVariantThunks.md`.
- Scalar deleting destructor [UID:00033F] `by-memory/0x004707f0-0x0047084f.WebBoardDialogOldScalarDeletingDestructor.md`.
- Child memory pages [UID:0003V5], [UID:0000ZA], [UID:000211], [UID:0000ZB], [UID:000212], [UID:0000ZC], [UID:000213], [UID:0000ZD], and [UID:000214].

Local executable evidence checked:

- PE path used: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Image base: `0x00400000`.
- Sections observed: `.text` at `0x00401000`, `.rdata` at `0x0060d000`, `.data` at `0x0066d000`, `.rsrc` at `0x0069d000`.
- Read-only local scan checked padding bytes, absolute dword pointer hits, and direct `call`/`jmp`/near conditional rel32 routes for old-dialog starts and companion thunks.

Scoped validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [0000G3-WebBoardDialogOld-class-source-quality-removed.md](0000G3-WebBoardDialogOld-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Working directory: `E:\NTK\GhidraBridge\source-3\project-documentation`.
- Exit code: `0`.
- `ok` count: `1`.
- Run mode: dry run, no `--apply`.

## Exact Half-Open Boundary And Padding Recheck

The old class executable island is best documented as `0x0046e260-0x0046efda` for the direct old-dialog range, plus companion cleanup/destructor thunks at `0x00470260` and `0x004707f0-0x0047084f`.

Local PE padding scan results:

| Range | Bytes | Conclusion |
| --- | --- | --- |
| `0x0046e25b-0x0046e260` | 5 bytes, all `0xcc` | Separates active WebBoardDialog draw/frame cluster from old raw teardown start. |
| `0x0046e294-0x0046e2a0` | 12 bytes, all `0xcc` | Separates raw teardown helper from modeled layout refresh. |
| `0x0046e4b6-0x0046e4c0` | 10 bytes, all `0xcc` | Separates modeled layout refresh from raw mode-rect helper. |
| `0x0046e63c-0x0046e640` | 4 bytes, all `0xcc` | Separates mode-rect switch tables from old constructor. |
| `0x0046e8be-0x0046e8c0` | 2 bytes, all `0xcc` | Separates constructor from ordinary destructor. |
| `0x0046e8e9-0x0046e8f0` | 7 bytes, all `0xcc` | Internal callback-cluster alignment. |
| `0x0046e92b-0x0046e930` | 5 bytes, all `0xcc` | Internal callback-cluster alignment. |
| `0x0046e9f5-0x0046ea00` | 11 bytes, all `0xcc` | Separates input callback from packet forwarder. |
| `0x0046ea23-0x0046ea30` | 13 bytes, all `0xcc` | Separates packet forwarder from raw initial-request helper. |
| `0x0046ea99-0x0046eaa0` | 7 bytes, all `0xcc` | Separates raw initial-request helper from response handler. |
| `0x0046ee7a-0x0046ee80` | 6 bytes, all `0xcc` | Separates response handler from raw old URL escape helper. |
| `0x0046efda-0x0046efe0` | 6 bytes, all `0xcc` | Separates old URL escape helper from following AutoInit/OLE helper. |

Boundary conclusion: do not merge the old island backward into active [UID:0000G2] `WebBoardDialog`, forward into AutoInit/OLE/browser cleanup code, or laterally into [UID:0000MZ] `RankingDialog`. The old class range is internally split by real function/raw-helper starts and compiler alignment, not by arbitrary documentation cuts.

## Caller, Vtable, And Reachability Evidence

Local PE route scan summary:

| Target | Absolute dword hits | Rel32 hits | Interpretation |
| --- | --- | --- | --- |
| `0x0046e260` | none | none | Raw old browser-control teardown has no proven inbound route; keep no-body policy. |
| `0x0046e2a0` | none | none | Modeled layout refresh has no current inbound route; real function, but source name/caller remain inferred. |
| `0x0046e4c0` | none | none | Raw mode-rect helper has no inbound route; switch tables are local only. |
| `0x0046e640` | none | `0x00508ddd`, `0x0051461e` calls | Constructor is live from two old web-board open paths. |
| `0x0046e8c0` | none | none | Ordinary destructor has no direct call route; lifecycle is through class destruction wrappers/vtables. |
| `0x0046e8f0` | `0x006136d4` | none | Old close-state callback is vtable-referenced. |
| `0x0046e930` | `0x00613704` | none | Old browser-reposition input callback is vtable-referenced. |
| `0x0046ea00` | `0x00613710` | none | Old packet/event callback is vtable-referenced. |
| `0x0046ea30` | none | none | Raw initial request helper has no proven inbound route; constructor contains inline-equivalent branch. |
| `0x0046eaa0` | none | `0x0046e850` call, `0x0046ea1e` tail jump | Old response handler is live from constructor and packet forwarder. |
| `0x0046ee80` | none | none | Raw old URL escape helper has no proven inbound route in current binary. |
| `0x00470260` | none | `0x005fae43` jump | Singleton-clear thunk is part of cleanup/static helper machinery, not a normal class method body. |
| `0x004707f0` | `0x0061368c` | `0x004702ec`, `0x004702f7` jumps | Scalar deleting destructor is vtable/adjustor reachable; ordinary destructor source body remains [UID:000212]. |

Important vtable bytes/anchors from local scan:

- `0x0061368c` begins with pointer `0x004707f0`, confirming the scalar deleting destructor slot.
- `0x006136d4` contains `0x0046e8f0`.
- `0x00613704` contains `0x0046e930`.
- `0x00613710` contains `0x0046ea00`.
- [UID:0001OB] documents the surrounding `WebBoardDialogOld` vtable slices at `0x0061368c`, `0x00613700`, and `0x00613730`, with constructor setup refs at `0x0046e6e1`, `0x0046e6e7`, and `0x0046e6f1`.
- [UID:000212] documents the `WebBoardDialogOld` RTTI pointer at `0x006136fc`.

String/global evidence:

- `0x00613ae4` decodes as wide `WEBBOARD.PAD`.
- `0x00613b00` decodes as wide `WEBBOARD.EPD`.
- `0x00613ab0` decodes `domain`.
- `0x00613ab8` decodes `boardinfo`.
- `0x00613adc` decodes `%%%2X`.
- [UID:0000SR] confirms `g_pWebBoardDialogOld` storage at `0x0067aba0` and lifecycle refs from constructor, destructor, cleanup thunk, and scalar deleting destructor.

## Heuristic / Inference Reanalysis And Validation

### Class Name

Best-supported source-facing class name: `WebBoardDialogOld`.

Evidence:

- The current target and child docs consistently name the old class `WebBoardDialogOld`.
- [UID:0001OB] and [UID:000212] document `WebBoardDialogOld` RTTI/vtable evidence around `0x0061368c`, `0x00613700`, `0x00613730`, and RTTI pointer `0x006136fc`.
- The singleton is documented as `g_pWebBoardDialogOld`, not `g_pOldWebBoardDialog`.
- The generated pollution strings in `class_RankingDialog.cpp` still preserve `WebBoardDialogOld_Constructor`, which is not source ownership proof but is a search alias supporting this class-name order.

Rejected alternative: `OldWebBoardDialog`. No current vtable, singleton, target page, child page, or generated search alias uses this order. Keep it rejected unless future symbol evidence appears.

### Active-Vs-Old Variant Relationship

Best-supported relationship: active `WebBoardDialog` and `WebBoardDialogOld` are two variants in the same `WebBoardDialog.cpp` source family.

Evidence:

- Active range is adjacent before old range: active WebBoard code runs through `0x0046e25b`, then `0x0046e25b-0x0046e260` is only `0xcc` padding, then old raw teardown starts at `0x0046e260`.
- Both variants derive through the `BrowserPane`/`BrowserControlPane` family and use embedded browser-control state.
- Both variants use board response handling, web-board cookies, opcode `0x73`, and timer id `0x572`.
- The active singleton `g_pWebBoardDialog` at `0x0067ab9c` and old singleton `g_pWebBoardDialogOld` at `0x0067aba0` are adjacent slots in the same browser/web-board singleton neighborhood, but [UID:0000HV] explicitly keeps the two web-board singletons with `WebBoardDialog.cpp`, not the generic Browser module.
- [UID:0000P9] already stages both active and old rows under `NexusTK/ui/dialogs/WebBoardDialog.cpp`.
- [UID:0001RT] ties old `WEBBOARD.EPD`/`WEBBOARD.PAD` resources to the old constructor only, while active draw helpers use EPF/PAL resources. This is an active/old resource split, not evidence for a different source owner.

Rejected alternatives:

- Separate `RankingDialog.cpp` ownership: rejected. Ranking uses opcode `0x7d`, ranking vtables/singletons, and ranking EPF/PAL resources. The Ranking page explicitly excludes WebBoardDialogOld pollution.
- Generic `Browser.cpp` ownership: rejected for board-specific singleton, opcode, cookies, resources, and response parser. Browser is an infrastructure dependency.
- Broad `BoardDialogs.cpp` ownership: possible feature adjacency only, but [UID:0000P9] is the narrower direct source route for browser-backed board dialogs.

### Source File Placement

Best-supported placement: `NexusTK/ui/dialogs/WebBoardDialog.cpp`.

Evidence:

- [UID:0000P9] has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and documents both active and old variants in one source file.
- [UID:0000HV] lists `WebBoardDialog` / `WebBoardDialogOld` as browser-coupled but not Browser-owned.
- [UID:0000MZ] lists WebBoardDialogOld as generated-output pollution to exclude from Ranking.
- [UID:0001RT] canonical owner is [UID:0000P9] for old fixed-art web-board resources.
- The local PE range is contiguous with active WebBoard code and uses WebBoard-specific data.

This closes the current target open question asking whether active and old variants shared `WebBoardDialog.cpp` or lived beside browser legacy classes. The evidence strongly supports shared `WebBoardDialog.cpp`, with Browser only as dependency.

### Owner And Emitter Strategy

Target class page:

- Keep [UID:0000G3] `CANONICAL_OWNER:0000P9` and `EMITTER_UIDS:0000P9`. Class pages emit through their source file owner.

Child pages:

- [UID:0003V5], [UID:0000ZA], [UID:000211], [UID:000212], [UID:000213], and [UID:00033F] already route direct owner/emitter to [UID:0000G3] where appropriate.
- [UID:0000ZB] constructor, [UID:0000ZC] packet forwarder, and [UID:0000ZD] response handler have headers currently routing to [UID:0000P9] even though their body prose says owner [UID:0000G3]. Recommendation: normalize `CANONICAL_OWNER` and `EMITTER_UIDS` to `0000G3` for these class methods in the implementation callback, while preserving `WebBoardDialog.cpp` as the source module through the class parent.
- [UID:000214] should not become an ordinary `WebBoardDialogOld` instance method. It is old-class-family support, but the best current source-facing interpretation from B004/B006 is a file-local helper `EscapeOldWebBoardUrl(...)` under [UID:0000P9]. Treat it as a file-local support helper used by old response code unless future route evidence proves an instance/static class declaration.
- [UID:0002AH] old URL escape state stays file/module static state under [UID:0000P9].

### Field, Global, Helper, And Placeholder Name Recommendations

| Raw/generated item | Best source-quality name | Evidence and disposition |
| --- | --- | --- |
| `dword_67ABA0` | `g_pWebBoardDialogOld` | [UID:0000SR] and exact child [UID:0002WK] document constructor set and destructor/cleanup/scalar clears. Type `WebBoardDialogOld *`. |
| `dword_67AB9C` | `g_pWebBoardDialog` | Active sibling singleton; useful only for active/old boundary. |
| `[this+0x26c]` / `this[155]` | `m_browserControlPane` | Constructor stores BrowserControlPane child; teardown/callbacks use same pointer. Type `BrowserControlPane *`. |
| `[this+0x278]` | `m_closeButton` | Layout/constructor delete or create close button/control; type likely `ImageButtonControlPane *` or close control pane pointer. |
| close button id `30` | close button command/control id | Constructor creates close button with id 30; rejected as the `0x46e8f0` callback state. |
| `dword_67A74C` | `g_pApplicationCleanupQueue` | Used by raw teardown and close callback before `BlackHole::QueuePaneForDeferredDeletion`. |
| `sub_469180` | `BlackHole::QueuePaneForDeferredDeletion(Pane *)` | Queue callee, not owner. |
| `sub_46BA90` | `BrowserControlPane::ShutdownBrowserWindow` / `Shutdown` | Browser control shutdown callee, not owner. |
| `dword_67A7EC` | packet send/queue object | Used with `QueueAndSendPacket`; keep packet writer global name from packet docs when available. |
| `sub_575380` | `PacketBufferWriteByte` | Writes one byte plus terminator in packet construction. |
| `sub_574BB0` | `QueueAndSendPacket` | Sends exact packet length. |
| `sub_5975E0` | `StartTimer` / timer helper | Starts timer id `0x572` for `0x4e20`/20000. |
| `byte_67ACB0` | `s_oldWebBoardUrlEscapeInitialized` | Old URL escape guard. B004/B006 should correct initial-state wording to BSS zero fill. |
| `byte_67ACB8` | `s_oldWebBoardUrlEscapeTable[256]` | Old URL escape table. |
| `0x0066d44c` / `0x0066d458` | `kOldWebBoardUrlReservedChars` / `kOldWebBoardUrlUnsafeChars` | Old escape table seed character sets. |
| `sub_443A00` | `_sprintf_s` / `sprintf_s` formatting helper | Used with `%%%2X` for percent escapes. |
| `0x0061368c`, `0x00613700`, `0x00613730` | `WebBoardDialogOld` vtable slices | Compiler output, not source data declarations. |
| `0x006136fc` | `WebBoardDialogOld` RTTI pointer | Compiler output. Use for identity only. |
| `RankingDialog::WebBoardDialogOld_Constructor` | generated search alias only | Reject as source owner. Replace narrative with `WebBoardDialogOld::WebBoardDialogOld`. |
| `RankingDialog::HandleWebBoardResponse` | generated search alias only | Reject as source owner. Replace narrative with `WebBoardDialogOld::HandleBoardResponse`. |
| generated `SetModeControlRect` | useful search alias, not final C++ | Body default behavior and calling convention differ from safe source form; prefer `GetWebBoardDialogOldModeRect` in docs until source declaration is proven. |

### Child Inventory And Source-Shape Decisions

| UID / range | Best role and name | Source-quality decision |
| --- | --- | --- |
| [UID:0003V5] `0x0046e260-0x0046e294` | retained raw no-route browser-control teardown/deferred-delete core | Owner [UID:0000G3]. No standalone method-body C++. It shuts down and clears `m_browserControlPane`, calls inherited cleanup/detach vslots `+0x38/+0x40`, then queues through `g_pApplicationCleanupQueue`. No function object, dword hit, rel32 route, vtable slot, or table route was found. |
| [UID:0000ZA] `0x0046e2a0-0x0046e4b6` | `WebBoardDialogOld::RefreshOldLayout(int mode)` / layout refresh helper | Real modeled function, class-owned, no direct xrefs. Rebuilds close/browser children for modes 0/4/6 and applies main dialog rects. Do not call it constructor. Final method name remains inferred; no method-body C++ yet. |
| [UID:000211] `0x0046e4c0-0x0046e63c` | static/stack-cleaning `GetWebBoardDialogOldModeRect(Rect *out, int selector, int mode)` | Owner [UID:0000G3]. It does not consume `ecx` as `this` and returns with `retn 0Ch`. Keep C++ blank until route/static declaration and generated `SetModeControlRect` default-behavior mismatch are resolved. |
| [UID:0000ZB] `0x0046e640-0x0046e8be` | `WebBoardDialogOld::WebBoardDialogOld(...)` | Constructor is live from calls at `0x00508ddd` and `0x0051461e`; installs old vtables, stores singleton, creates `WEBBOARD.EPD/PAD` fixed-art shell, close button id 30, BrowserControlPane child, opcode `0x73` request, timer `0x572`. Normalize metadata to class owner/emitter. |
| [UID:000212] `0x0046e8c0-0x0046e9f5` | destructor plus `OnCloseStateChanged` and `OnInputEventWithBrowserReposition` | Owner/emitter [UID:0000G3]. First-draft C++ is already populated. Keep names as high-probability descriptive callback names until BrowserPane/DialogPane typedef work proves shorter original names. |
| [UID:0000ZC] `0x0046ea00-0x0046ea23` | packet/event forwarder, best class callback name `OnWebBoardPacket` or `OnPacket` | Vtable slot `0x00613710`; checks payload byte `0x62`, returns false on mismatch, and tail-jumps to `HandleBoardResponse` with `this - 0xa0`. Normalize metadata to class owner/emitter. |
| [UID:000213] `0x0046ea30-0x0046ea99` | retained raw no-route `SendInitialBoardRequest()` helper | Owner [UID:0000G3]. Sends `0x73,0x00`, length 2, timer `0x572`/20000. No route found; old constructor contains inline-equivalent branch. Keep formal C++ blank. |
| [UID:0000ZD] `0x0046eaa0-0x0046ee7a` | `WebBoardDialogOld::HandleBoardResponse` | Live from constructor call `0x0046e850` and packet tail jump `0x0046ea1e`; cancels timer, parses payload, sets `domain`/`boardinfo` cookies, uses old escape state, updates BrowserControlPane URL state, navigates. Normalize metadata to class owner/emitter; C++ can wait for packet/field names. |
| [UID:000214] `0x0046ee80-0x0046efda` | file-local `EscapeOldWebBoardUrl(const char *source, short sourceLength, char *dest, short destCapacity)` | Old-class support but best owner/emitter is [UID:0000P9], not an instance method. B004/B006 report-level evidence supports `88/90`, BSS-zero old guard/table state, and first-draft helper C++ if accepted. |
| [UID:000336] `0x00470260-0x0047026b` slice | old singleton clear thunk | Mixed cleanup/thunk page remains non-emitting. Treat `0x00470260` as WebBoardDialogOld singleton cleanup effect, not a class method body. |
| [UID:00033F] `0x004707f0-0x0047084f` | scalar deleting destructor | Owner/emitter [UID:0000G3]. ABI/compiler wrapper around source destructor and delete flag; no ordinary destructor source body should be duplicated from this page. |

### Constructor, Destructor, Callback, Singleton, And Vtable Validation

Constructor:

- Exact range `0x0046e640-0x0046e8be`.
- Direct caller evidence: `0x00508ddd` and `0x0051461e`.
- Installs BrowserPane vtables first and `WebBoardDialogOld` vtables after base setup.
- Stores `g_pWebBoardDialogOld` at `0x0067aba0`.
- Uses `WEBBOARD.PAD` and `WEBBOARD.EPD`.
- Builds fixed background `(0,0)-(540,379)` and outer dialog/update rect `(50,50)-(590,429)`.
- Builds close button `(234,342)-(306,358)` with id `30`.
- Builds browser child `(30,30)-(510,334)` and stores pointer at `+0x26c`.
- If immediate payload exists, calls `0x0046eaa0`.
- If no payload and no direct URL exists, sends opcode `0x73` with zero payload byte and starts timer `0x572` for 20000 ms.

Destructor and callbacks:

- Ordinary destructor `0x0046e8c0-0x0046e8e9` clears `g_pWebBoardDialogOld` and restores BrowserPane vtables.
- Close-state callback `0x0046e8f0-0x0046e92b` is vtable slot `0x006136d4`, gates on `state == 1`, calls close/deactivation vslot `+0x68`, shuts down `m_browserControlPane`, calls vslots `+0x38/+0x40`, and queues through `g_pApplicationCleanupQueue`. It is not the close button id `30` handler and not a deleting destructor.
- Input callback `0x0046e930-0x0046e9f5` is vtable slot `0x00613704`; it delegates to generic input handling, then repositions the hosted browser HWND using old fixed inset `+30,+30` and refreshes `g_pScreenPane`.
- Packet callback `0x0046ea00-0x0046ea23` is vtable slot `0x00613710`; it checks payload byte `0x62` and tail-jumps to response handling.
- Scalar deleting destructor `0x004707f0-0x0047084f` is vtable/adjustor reachable and should remain a separate ABI wrapper page.
- Singleton clear thunk `0x00470260` is cleanup machinery and should remain documented in mixed thunk support, not as source-authored class method.

## Rejected Alternatives

- `RankingDialog` ownership: rejected. The only ranking evidence is generated-output pollution. Ranking has opcode `0x7d`, ranking-specific singleton/vtables/resources, and its file page explicitly excludes WebBoardDialogOld. Old web-board code has `g_pWebBoardDialogOld`, opcode `0x73`, old vtables, `WEBBOARD.EPD/PAD`, `domain`/`boardinfo`, and `WebBoardDialog.cpp` source route.
- Generic Browser ownership: rejected. Browser owns BrowserPane/BrowserControlPane infrastructure. WebBoardDialogOld owns board-specific singleton lifecycle, packet opcode, cookies, resources, and response navigation policy.
- `BrowserControlPane` ownership for teardown paths: rejected. `BrowserControlPane::ShutdownBrowserWindow` is a callee; the receiver object and `+0x26c` member belong to `WebBoardDialogOld`.
- `BlackHole` ownership for deferred deletion: rejected. `BlackHole::QueuePaneForDeferredDeletion` is a cleanup queue callee, not the owner of old-dialog teardown bodies.
- Dead/padding treatment for raw helpers: rejected. The raw helper starts have complete source-shaped bodies and exact padding boundaries. No-route only blocks standalone C++ bodies.
- Merging [UID:0003V5] back into the old active/render split index [UID:000210]: rejected. The exact child has strong old-class semantics; [UID:000210] is a non-emitting split index.
- Treating [UID:000211] as ordinary instance `__thiscall`: rejected. The helper uses stack args and `retn 0Ch`, with no `this` consumption.
- Treating [UID:000213] as live packet callback: rejected. The vtable packet callback is [UID:0000ZC] at `0x0046ea00`; [UID:000213] is retained no-route request/timer helper.
- Treating [UID:000214] as ordinary class method: not supported. It is old-class support logic, but current best source shape is file-local helper under `WebBoardDialog.cpp`.

## Open-Question Closure

- Final class name: closed as `WebBoardDialogOld`. `OldWebBoardDialog` is not supported by current evidence.
- Final source placement: closed as `NexusTK/ui/dialogs/WebBoardDialog.cpp`. Browser is a dependency and Ranking is pollution.
- Active vs old relationship: closed as same source family, separate classes/variants, distinct active and old resource sets.
- `0x0046e2a0` no-xref layout helper: closed enough for source-quality ownership. It is a real old layout refresh helper, not the constructor. Final original method name remains inferred, so body C++ should remain blank.
- `0x0046e4c0` raw mode-rect helper: closed as class-scoped static/stack-cleaning old mode rect helper. No route/calling convention proof means no C++ body yet.
- `0x0046e260` raw teardown helper: closed as retained raw no-route old teardown/deferred-delete evidence. No standalone body emission.
- `0x0046ea30` raw request helper: closed as retained raw no-route `SendInitialBoardRequest()`-shaped helper with constructor inline-equivalent branch accounting for reachability. No standalone body emission.
- `0x0046ee80` raw URL escape helper: class-context role is closed as old response support, but final owner should be file-local [UID:0000P9] per B004/B006 rather than instance method. First-draft helper C++ belongs to that exact support callback if accepted.
- Stale Ranking/generated names: closed as generated search aliases only. Replace with WebBoardDialogOld/source-file names during implementation.
- Callback names: current best names are descriptive and good enough for 90/88 class documentation: `OnCloseStateChanged`, `OnInputEventWithBrowserReposition`, and a packet callback such as `OnWebBoardPacket`/`OnPacket`. Exact typedef names remain unproved, which caps confidence but does not block ownership/source placement.

## First-Draft C++ Recommendation

The class page is eligible for a conservative first-draft declaration shell because:

- The target is `RECONSTRUCTABLE:TRUE`.
- Current average score is `(88 + 85) / 2 = 86.5`, above the corrected >85 draft gate.
- Recommended metadata raises it to `90/88`.
- The source file route [UID:0000P9] is stable and above gate.
- The class identity, vtables, singleton, destructor/callback cluster, constructor route, and fields `+0x26c/+0x278` are stable.

Recommended shell for implementation callback:

```cpp
class WebBoardDialogOld : public BrowserPane
{
public:
    WebBoardDialogOld(void *initialResponsePayload, const wchar_t *initialUrl);
    virtual ~WebBoardDialogOld();

    virtual void OnCloseStateChanged(int state, int reason);
    virtual bool OnInputEventWithBrowserReposition(InputEvent *event);
    virtual bool OnWebBoardPacket(void *event);

    void HandleBoardResponse(const unsigned char *payload);

private:
    BrowserControlPane *m_browserControlPane; // +0x26c
    ImageButtonControlPane *m_closeButton;    // +0x278
};

[[CHILDREN]]
```

Shell caveats:

- The constructor parameter types are best current placeholders from body behavior: an optional immediate response payload and optional direct URL. If implementation policy forbids placeholder pointer types in class declarations, emit the class shell without constructor parameter detail or keep constructor declaration out of the shell until [UID:0000ZB] gets its own constructor-specific C++ pass.
- Do not declare retained raw no-route helpers as source methods in the class shell. `0x0046e260`, `0x0046e4c0`, and `0x0046ea30` remain documented children with no standalone method-body emission.
- Do not declare `EscapeOldWebBoardUrl` as a class member. It belongs as a file-local helper under [UID:0000P9] if B004/B006 are accepted.
- Do not duplicate [UID:000212] method bodies at the class page. Child pages remain the body emitters.

## Proposed Scores And Metadata

Target [UID:0000G3]:

- `COMPLETION:90`.
- `CONFIDENCE:88`.
- `CANONICAL_OWNER:0000P9`.
- `RECONSTRUCTABLE:TRUE`.
- `EMITTER_UIDS:0000P9`.

Rationale:

- Completion rises because the current open questions are now closed with explicit evidence: final class name, source placement, active-vs-old relationship, Ranking pollution, raw no-route helper policy, class/file owner split, vtable/singleton evidence, and first-draft class-shell strategy.
- Confidence rises because local PE scan independently reconfirmed padding and route/no-route facts; remaining cap is due to unproved exact original callback typedef names, constructor parameter types, and several retained raw helper source declarations.

Support metadata recommendations:

- [UID:0000ZB] `WebBoardDialogOldConstructor`: change owner/emitter metadata from [UID:0000P9] to [UID:0000G3]; keep source module route text [UID:0000P9].
- [UID:0000ZC] `WebBoardDialogOldPacketForwarder`: change owner/emitter metadata from [UID:0000P9] to [UID:0000G3].
- [UID:0000ZD] `WebBoardDialogOldHandleBoardResponse`: change owner/emitter metadata from [UID:0000P9] to [UID:0000G3].
- [UID:000214] `WebBoardDialogOldUrlEscapeHelper`: if B004/B006 are accepted, raise to `88/90`, keep owner/emitter [UID:0000P9], name file-local helper `EscapeOldWebBoardUrl`, correct old escape state as BSS zero-filled, and emit first-draft helper C++ there rather than on the class page.
- [UID:0002AH] old URL escape state: synchronize BSS-zero initial-state correction if [UID:000214] is implemented.

## Exact Target/Support Implementation Checklist

Target [UID:0000G3] `by-class/WebBoardDialogOld.md`:

- Change metadata to `COMPLETION:90` and `CONFIDENCE:88`; keep owner/emitter [UID:0000P9].
- Replace the current `Open Questions` section with closed findings from this report.
- Add the source placement conclusion: `WebBoardDialogOld` is the old fixed-art variant in `NexusTK/ui/dialogs/WebBoardDialog.cpp`, not RankingDialog or Browser.
- Add boundary/padding proof for the old range and companion thunks.
- Add caller/reachability table for constructor, callbacks, packet forwarder, response handler, raw no-route helpers, cleanup thunk, and scalar deleting destructor.
- Add source-quality name map for fields/globals/helpers/generated aliases.
- Add class declaration shell only if implementation policy accepts conservative placeholder pointer types. Otherwise document the exact reason the shell is deferred and keep method bodies blank.
- Keep [UID:0003V5], [UID:000211], and [UID:000213] formal C++ blank with explicit no-route/no-body proof.
- Do not move [UID:000214] into the class as an instance method.

Source/support pages:

- [UID:0000P9] `by-file/WebBoardDialog.md`: update the old variant row with the final class/source placement, raw no-route policies, method metadata-normalization plan, and file-local URL escape helper context.
- [UID:0000G2] `by-class/WebBoardDialog.md`: keep active/old split explicit; active and old share source file but not class identity or resource set.
- [UID:0001RT] `by-resource/webboard-dialog-resources.md`: no score change needed, but support callback can cite this report for `WEBBOARD.EPD/PAD` old-only ownership and Ranking EPF/PAL collision rejection.
- [UID:0000SR] `by-global/g_pWebBoardDialogOld.md` and exact child [UID:0002WK]: no name change; cite class report for final `WebBoardDialogOld*` type and lifecycle.
- [UID:0001OB] `BrowserVtablesAndStrings`: no score change required; cite final class report for old vtable slices remaining WebBoard-owned inside mixed Browser data.
- [UID:0000HV] `Browser`: no ownership migration; keep WebBoardDialogOld under WebBoardDialog source and Browser as dependency.
- [UID:0000MZ] `RankingDialog`: no migration; keep WebBoardDialogOld pollution exclusion.
- [UID:000336] cleanup/thunk page: no ownership change; ensure `0x00470260` remains WebBoardDialogOld singleton clear effect, non-emitting.
- [UID:00033F] scalar deleting destructor: keep owner/emitter [UID:0000G3]; no ordinary destructor body duplication.
- [UID:0000ZA]: add best source/search alias `RefreshOldLayout(int mode)` and close the "not constructor" point.
- [UID:000211]: keep direct class owner and no C++; add this report's `GetWebBoardDialogOldModeRect` naming recommendation while preserving generated `SetModeControlRect` caveat.
- [UID:0000ZB], [UID:0000ZC], [UID:0000ZD]: normalize owner/emitter metadata to [UID:0000G3] and remove stale file-owned method ambiguity.
- [UID:000214] and [UID:0002AH]: implement B004/B006 support if accepted; treat as file-local helper/state under [UID:0000P9].

Coverage/report files:

- Do not edit `by-memory/-coverage-report.md` for this class report.
- If implementation edits only the class page, supervisor-owned coverage update is the `by-class/-coverage-report.md` row below.
- If implementation also edits by-memory support pages, use their accepted report-specific rows separately; do not infer by-memory rows from this class report unless supervisor requests them.

Validators after implementation:

- Run scoped validator for every edited by-* file:
  - `python .\tools\validator.py --mode file --file by-class\WebBoardDialogOld.md --apply --queue-timeout 240`
  - plus one `--apply` run for each support by-* file edited.
- Report command, exit code, and `ok` count for each.

## Exact Supervisor-Owned Coverage Row Text

Replacement row for `by-class/-coverage-report.md`:

```markdown
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) : reconstructable : 90% : strong : B008 2026-06-19 source-quality reanalysis validates `WebBoardDialogOld` as the old fixed-art browser-backed WebBoard class under [UID:0000P9] `WebBoardDialog.cpp`, closes active-vs-old source placement and RankingDialog pollution questions, records MSVC vtable/singleton evidence (`0x0061368c/0x00613700/0x00613730`, `g_pWebBoardDialogOld`), fixed `WEBBOARD.EPD/PAD` geometry, opcode `0x73` request and `0x62` response path, destructor/close/reposition callback names, retained raw no-route helper policies for `0x0046e260`, `0x0046e4c0`, `0x0046ea30`, file-local old URL escape-helper context at `0x0046ee80`, support metadata-normalization checklist for stale file-owned old methods, and class-level first-draft declaration-shell readiness while method-body C++ remains delegated to exact by-memory children.
```

No `by-memory/-coverage-report.md` row is required for this report-only class target.

## Validator Baseline Result

Baseline command:

> Executable block R002 was removed from this report and preserved verbatim in [0000G3-WebBoardDialogOld-class-source-quality-removed.md](0000G3-WebBoardDialogOld-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- `ok: 1`.
- Key validator status: `ok 0000G3 by-class/WebBoardDialogOld.md UID header exists`.
- Dry run only; no `--apply`.
- The validator also reported `autogen_emitter_has_no_code 0000G3 by-class/WebBoardDialogOld.md emitting children only`, matching the current blank class C++ and supporting the declaration-shell recommendation as the only target-level C++ candidate.

## Report-Only File Policy

This pass created this research report and is intended to update `tools/leaser/Agents/Agent-B008/notes.md` only. No by-* documentation files and no coverage reports were edited in this pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000G3-WebBoardDialogOld-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:32","uid":"0000G3"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000G3-WebBoardDialogOld-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000G3-WebBoardDialogOld-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000G3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
