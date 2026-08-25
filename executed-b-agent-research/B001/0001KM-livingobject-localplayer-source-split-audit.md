** TARGET-REPORT-UID:0001KM **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Audit: UID 0001KM LivingObjectPaneLocalPlayerExtensions Source Split

Assignment: `B001-goal2-memory-tool-livingobject-localplayer-source-split-0001KM-20260616`  
Target: `[UID:0001KM] source-3/project-documentation/by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md`  
Agent: `Agent-B001`  
Date: 2026-06-16

## Executive recommendation

[UID:0001KM] should not remain a reconstructable emitting C++ aggregate in its current form. The address neighborhood is real and useful, but it mixes at least five source families:

- LivingObjectPane local-player movement, hotkey/action, and server-packet helpers.
- UserPane methods and vtable-adjacent helpers.
- SayInputPanes / Chatting helpers.
- Quit and SelfSave dialog factories.
- Raw no-xref helper islands that IDA does not model as functions.

Recommended final route after child pages are created:

```text
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
```

Treat [UID:0001KM] as a non-emitting split index. Exact child pages should carry the actual canonical owner/emitter. If the supervisor wants to keep [UID:0001KM] as a LivingObjectPane-owned umbrella during a transitional pass, it should still be `RECONSTRUCTABLE:FALSE` with blank emitters until source-family exclusions and raw islands are split out.

The current filename/range also has a half-open boundary mismatch: live IDA reports `sub_5AD360` at `0x005ad360` with size `0xe1`, ending at `0x005ad441`, while the target filename ends at `0x005ad440`. The documentation body already cites `0x005ad360-0x005ad441` for the attack-target packet helper. If the aggregate continues to cover that helper, update the coverage range and eventual filename to end at `0x005ad441`.

## Evidence used

Required workflow instructions read before acting:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B001/notes.md`

Documentation rules and local evidence checked:

- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/by-memory/-guidance.md`
- `source-3/project-documentation/by-memory/-coverage-report.md`
- [UID:0001KM] target page.
- [UID:0000KU] `by-file/LivingObjectPane.md`
- [UID:00007B] `by-class/LivingObjectPane.md`
- [UID:0000P1] `by-file/UserPane.md`
- [UID:0000FQ] `by-class/UserPane.md`
- [UID:0001KO] `0x005a4b60-0x005a5791.SayModeHelpers.md`
- [UID:0001KP] `0x005a94b0-0x005a95d2.QuitPromptLauncher.md`
- [UID:0001KQ] `0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory.md`
- [UID:0001KR] `0x005adc20-0x005adcb3.GroupMemberMarkers.md`
- [UID:0001KS] `0x005adcc0-0x005add8a.QuitInputPaneCore.md`
- [UID:0001KT] `0x005addf0-0x005adf2e.QuitDialogCore.md`
- [UID:00027W] `0x0066decc-0x0066dee0.LivingObjectPaneWordSlots_66DECC.md`
- [UID:00030B] `0x0069bf74-0x0069bf78.g_lastFunctionKeyTick.md`
- [UID:0002A3] `0x0069bf68-0x0069bf78.KeyboardInputCommandStateGlobals.md`

IDA/Wave evidence checked:

- Opened `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` read-only in IDA session `b001_0001KM_20260616`.
- Health check: imagebase `0x400000`, Hex-Rays available, strings cache ready.
- Used `lookup_funcs`, `entity_query`, `xrefs_to`, `callees`, `search_text`, and `make_signature_for_range`.
- `callers` was not available in the MCP surface, so caller evidence comes from `xrefs_to`.

## Boundary and ownership findings

### UserPane exclusions

UserPane-owned functions are physically interleaved with the target range and should not be emitted through LivingObjectPane:

- `0x005a40d0-0x005a4523`: UserPane inventory/spell label helpers from UserPane docs.
- `0x005a5b80-0x005a5bc7`: UserPane OnBoundsChanged.
- `0x005a5bd0-0x005a7422`: UserPane OnKeyEvent.
- `0x005a76c0-0x005a82bd`: UserPane OnServerMessage.
- `0x005a83b0-0x005a87ad`: UserPane OnAnimationStep.
- `0x005a8840-0x005a88cf`: UserPane OnClipBounds.
- `0x005a8e70-0x005a8f8c`: UserPane name-label show/hide helpers.
- `0x005a9240-0x005a9249`: data xref from `0x0062ef88`, likely a vtable target; route should be checked with UserPane vtable docs before assigning to LivingObjectPane.

Disconfirming evidence checked: the LivingObjectPane docs intentionally keep movement/combat helpers called from UserPane with LivingObjectPane. This does not rescue the actual UserPane methods above; their owner docs already bind them to UserPane.

### SayInputPanes and Chatting exclusions

The existing [UID:0001KO] `SayModeHelpers` page covers `0x005a4b60-0x005a5791` and is already correctly non-reconstructable. It contains the exact [UID:0002RX] `0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode` child. This span should remain a sibling/exclusion, not a child emitted through [UID:0001KM].

The `0x005a95e0-0x005aa0c0` region remains likely ChatInputPane/Chatting material. Evidence checked: global ChatInputPane data docs point into `0x005a95e0`, and the target page lists this as input-pane/chat-adjacent unresolved material. I did not find enough source-boundary evidence in this pass to safely assign exact owner rows inside that subrange.

### Quit, SelfSave, and Group exclusions

- [UID:0001KP] `0x005a94b0-0x005a95d2.QuitPromptLauncher` is a Quit/dialog helper, called from UserPane OnKeyEvent, not LivingObjectPane source.
- [UID:0001KQ] `0x005aa140-0x005aa1bf.SelfSaveInputPaneFactory` is SelfSaveInputPane, not LivingObjectPane.
- [UID:0001KR] Group marker helpers begin at `0x005adc20`, after the target aggregate. They are outside [UID:0001KM] and should stay outside it.

### LivingObjectPane local movement/action/server packet ownership

The following groups have strong evidence for LivingObjectPane file/class ownership:

- Local movement and prediction helpers around `0x005a2e00`, `0x005a36f0`, `0x005a3770`, `0x005a5a90`, `0x005a87e0`, `0x005a8810`, `0x005a88d0`, `0x005a8cf0`.
- Hotkey/action helpers around `0x005a3a20`, `0x005a3ae0`, `0x005a3e30`, `0x005a4530`, `0x005acc30`, `0x005ad360`.
- Server-packet handlers around `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005aaff0`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abb20`, `0x005abda0`, `0x005ac070`, `0x005ac1b0`, `0x005ac280`, `0x005ac7e0`, `0x005ac9a0`, `0x005acae0`, `0x005acb20`.

Some of these are called by UserPane OnServerMessage. That is dispatcher reachability, not necessarily UserPane ownership. The existing LivingObjectPane file/class docs already claim the local-player packet-handler family.

## Raw/projected starts audited

### `0x005a3a20`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: unique bytes for `0x005a3a20-0x005a3ae0`.  
Reachability inside body: raw xrefs/calls to `0x005a4530` at `0x005a3ab8` and `0x005a3e30` at `0x005a3ac6`.  
Boundary: prologue-shaped body appears to end at `0x005a3ad4`, then `0x005a3ad4-0x005a3ae0` is `0xcc` alignment before modeled `LivingObjectPane_ExecuteHotkeyAction`.

Recommendation: create a raw child page for `0x005a3a20-0x005a3ad4` under LivingObjectPane local action/hotkey ownership, with no final emitted C++ until an entrypoint/caller explanation is found. Add ignored row `0x005a3ad4-0x005a3ae0`.

### `0x005a9250`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: unique bytes for `0x005a9250-0x005a9310`.  
Data evidence: [UID:00030B] says this raw helper reads `g_lastFunctionKeyTick` at `0x0069bf74`, uses debounce constant `0x64`, and calls `0x005a4530`; no writer was found.  
Boundary: existing evidence supports body `0x005a9250-0x005a9307`, then alignment `0x005a9307-0x005a9310`.

Recommendation: create a raw LivingObjectPane file-level helper child `0x005a9250-0x005a9307`; keep non-emitting or score-limited until entrypoint is known. Add ignored row `0x005a9307-0x005a9310`.

### `0x005aaff0`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: unique bytes for `0x005aaff0-0x005ab090`.  
Callee evidence: body parses packet bytes and calls `0x005a5a90`; it clears local movement/link activity flags around `this+0x13eb14` / `this+0x13eb18`.  
Boundary: body appears to end at `0x005ab084`, then `0x005ab084-0x005ab090` alignment.

Recommendation: create raw LivingObjectPane packet/movement child `0x005aaff0-0x005ab084`; keep source reconstruction gated because no caller/entry xref is present. Add ignored row `0x005ab084-0x005ab090`.

### `0x005ac1b0`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: unique bytes for `0x005ac1b0-0x005ac280`.  
Callee evidence: body parses coordinate/position-sync fields, checks `this+0x1c4`, calls `0x005a5a90`, then returns true.  
Boundary: body appears to end at `0x005ac27c`, then `0x005ac27c-0x005ac280` alignment.

Recommendation: create raw LivingObjectPane packet/position-sync child `0x005ac1b0-0x005ac27c`; keep final C++ gated by no-entrypoint caveat. Add ignored row `0x005ac27c-0x005ac280`.

### `0x005ac7e0`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: unique bytes for `0x005ac7e0-0x005acae0`.  
Boundary evidence: stack packet helper with security cookie and packet sender. Prior [UID:0003H4] documentation identifies the preceding function's `retn 0x0c`, range-check failure tail, and `0xcc` alignment at `0x005ac99b-0x005ac9a0`.

Recommendation: create raw LivingObjectPane packet child `0x005ac7e0-0x005ac99b`. Add ignored row `0x005ac99b-0x005ac9a0`.

### `0x005ac9a0`

IDA status: not a function.  
Xrefs to start: none.  
Signature evidence: same unique `0x005ac7e0-0x005acae0` island.  
Boundary evidence: second stack packet helper begins at `0x005ac9a0`, sends direction/facing style packet fields, updates linked-record array fields, and returns with `retn 4`; `0x005acad5-0x005acae0` is alignment before existing [UID:0003H4].

Recommendation: create raw LivingObjectPane packet child `0x005ac9a0-0x005acad5`. Add ignored row `0x005acad5-0x005acae0`. The exact semantic name should remain conservative until a byte-level field map is completed.

## Exact executable child split candidates

Rows below are sorted by address. "Route" is the recommended owner/emitter route, not a direct coverage edit. New UID allocation is intentionally left to the normal validator/supervisor process.

| Range | Current IDA status | Route | Recommendation |
| --- | --- | --- | --- |
| `0x005a2de0-0x005a2dfb` | function | LivingObjectPane | Existing [UID:0002RW], keep. |
| `0x005a2e00-0x005a36de` | function | LivingObjectPane | Create exact local movement/prediction child. |
| `0x005a36f0-0x005a3766` | function | LivingObjectPane | Create exact walk/animation helper child. |
| `0x005a3770-0x005a386a` | function | LivingObjectPane | Create exact directional animation helper child. |
| `0x005a3870-0x005a3889` | function | LivingObjectPane | Create exact slot/accessor child; broad xrefs from inventory/item/dialog paths support shared helper. |
| `0x005a3890-0x005a38c4` | function, no start xrefs | unresolved | Do not emit yet; packet-buffer-like body, no caller evidence. |
| `0x005a39a0-0x005a39d4` | function, no start xrefs | unresolved | Do not emit yet; no caller evidence. |
| `0x005a3a20-0x005a3ad4` | raw no-xref island | LivingObjectPane | Create raw child; keep final C++ gated. |
| `0x005a3ae0-0x005a3d39` | function | LivingObjectPane | Create exact `ExecuteHotkeyAction` child. |
| `0x005a3e30-0x005a3ff3` | function | LivingObjectPane | Existing [UID:0001KN], keep. |
| `0x005a40d0-0x005a4523` | functions | UserPane | Exclude from LivingObjectPane; route through UserPane exact children. |
| `0x005a4530-0x005a4908` | function | LivingObjectPane | Create exact use-command/use-slot helper child. |
| `0x005a4b60-0x005a5791` | functions | SayInputPanes/Chatting | Existing [UID:0001KO], keep as non-Living sibling/index. |
| `0x005a57a0-0x005a5811` | function | LivingObjectPane likely | Create child only after naming check; caller from map-side path. |
| `0x005a5820-0x005a58bc` | functions | unresolved | Keep roadmap until behavior/source owner is named. |
| `0x005a58c0-0x005a5983` | function | LivingObjectPane | Create exact local action helper child; calls [UID:target child candidate] `0x005acc30`. |
| `0x005a5990-0x005a59fa` | function | unresolved | Caller from `0x005036ec`; insufficient owner evidence. |
| `0x005a5a80-0x005a5a85` | tiny function | unresolved | Do not emit as source child until behavior is explained. |
| `0x005a5a90-0x005a5b79` | function | LivingObjectPane | Create exact warp/position helper child. |
| `0x005a5b80-0x005a88cf` | functions | UserPane with embedded Living helpers | UserPane methods must be excluded; Living helpers at `0x005a87e0` and `0x005a8810` can be split separately if exact boundaries are made clear. |
| `0x005a87e0-0x005a8832` | functions | LivingObjectPane | Create exact local movement cleanup/status children. |
| `0x005a88d0-0x005a89c9` | function | LivingObjectPane | Create exact movement/screen update helper child after naming audit. |
| `0x005a89d0-0x005a8ad6` | functions/mixed | unresolved | Keep roadmap; one function has map-side caller, one has no xrefs. |
| `0x005a8b80-0x005a8c16` | raw no-xref island | LivingObjectPane | Create raw word-slot setter child or leave documented under [UID:00027W] until exact child pass. |
| `0x005a8c20-0x005a8c5c` | raw no-xref island | LivingObjectPane | Create raw word-slot setter child or leave documented under [UID:00027W] until exact child pass. |
| `0x005a8c60-0x005a8ce7` | function | unresolved | Caller evidence exists from `0x00540910`, but owner/name unresolved. |
| `0x005a8cf0-0x005a8e67` | function | LivingObjectPane | Create exact movement packet child. |
| `0x005a8e70-0x005a8f8c` | functions | UserPane | Exclude; UserPane name-label helpers. |
| `0x005a8fc0-0x005a9249` | functions/mixed | unresolved/UserPane likely for `0x005a9240` | Do not route to LivingObjectPane without vtable/source audit. |
| `0x005a9250-0x005a9307` | raw no-xref island | LivingObjectPane file-level | Create raw function-key debounce helper child; keep non-final due no entry xref. |
| `0x005a9310-0x005a934a` | function | LivingObjectPane | Create small packet/movement helper child. |
| `0x005a9350-0x005a94a4` | functions/mixed | unresolved | Function name at `0x005a9350` is misleading; source owner unresolved. |
| `0x005a94b0-0x005a95d2` | function | QuitDialogs | Existing [UID:0001KP], exclude. |
| `0x005a95e0-0x005aa0c0` | function series | Chatting/ChatInputPane likely | Exclude from LivingObjectPane until Chatting child split audit. |
| `0x005aa140-0x005aa1bf` | function | SelfSaveInputPane | Existing [UID:0001KQ], exclude. |
| `0x005aa480-0x005aa702` | function | LivingObjectPane | Create exact server settings packet child. |
| `0x005aa710-0x005aaa2c` | function | LivingObjectPane | Create exact spell/slot update packet child. |
| `0x005aac80-0x005aafe3` | function | LivingObjectPane | Create exact server-entry/local-player packet child. |
| `0x005aaff0-0x005ab084` | raw no-xref island | LivingObjectPane | Create raw movement/position packet child; keep final C++ gated. |
| `0x005ab090-0x005ab410` | function | LivingObjectPane | Create exact movement ack/correction packet child. |
| `0x005ab410-0x005ab75d` | function | LivingObjectPane | Create exact movement ack/correction packet child. |
| `0x005ab860-0x005aba7b` | function | LivingObjectPane with Chatting dependency | Create exact chat-message packet child; do not assign to Chatting solely because it handles text. |
| `0x005aba80-0x005abb1a` | function, no start xrefs | unresolved | Keep roadmap. |
| `0x005abb20-0x005abc6f` | function, no start xrefs | LivingObjectPane likely | Create child only with note that direct reachability was not found; may be indirectly dispatched. |
| `0x005abc70-0x005abd99` | function, no start xrefs | unresolved | Keep roadmap. |
| `0x005abda0-0x005abee8` | function | LivingObjectPane server packet / UI-pane dependency | Create exact packet child; panel owners are dependencies, not necessarily canonical owner. |
| `0x005ac000-0x005ac061` | function, no start xrefs | unresolved | Keep roadmap. |
| `0x005ac070-0x005ac1a8` | function | LivingObjectPane server packet, medium confidence | Create exact message-show packet child; note dependency on MessageShowPane constructor. |
| `0x005ac1b0-0x005ac27c` | raw no-xref island | LivingObjectPane | Create raw position-sync packet child; keep final C++ gated. |
| `0x005ac280-0x005ac69b` | function | LivingObjectPane | Create exact linked object/player packet parser child. |
| `0x005ac7e0-0x005ac99b` | raw no-xref island | LivingObjectPane | Create raw packet child; keep final C++ gated. |
| `0x005ac9a0-0x005acad5` | raw no-xref island | LivingObjectPane | Create raw packet child; semantic name still conservative. |
| `0x005acae0-0x005acb1f` | raw no-xref island | LivingObjectPane | Existing [UID:0003H4], keep. |
| `0x005acb20-0x005acc23` | raw no-xref island | LivingObjectPane | Existing [UID:0003H5], keep. |
| `0x005acc30-0x005acd85` | function | LivingObjectPane | Create exact auto-face/action packet child. |
| `0x005acf10-0x005acf5f` | function | LivingObjectPane likely | Called from UserPane OnKeyEvent; create only after action name audit. |
| `0x005acfe0-0x005ad02c` | function | LivingObjectPane helper likely | Called by `0x005abda0`; create after panel-switch helper naming audit. |
| `0x005ad360-0x005ad441` | function | LivingObjectPane | Create exact attack-target packet child; fix parent half-open range mismatch. |

## Caller and callee reachability highlights

Xref evidence supporting LivingObjectPane helpers:

- `0x005a2de0`: callers from map-side movement/render paths at `0x50591f`, `0x505a01`, `0x50c87e`, `0x50d159`.
- `0x005a2e00`: callers include map-side paths and UserPane OnKeyEvent calls at `0x005a6e95`, `0x005a6eb1`, `0x005a6ecd`, `0x005a6ee9`.
- `0x005a3ae0`: caller from UserPane OnKeyEvent at `0x005a5ce5`.
- `0x005a4530`: called from raw `0x005a3a20`, `ExecuteHotkeyAction`, raw `0x005a9250`, and another path at `0x005b6260`.
- `0x005a5a90`: called by UserPane OnServerMessage, OnAnimationStep, movement handlers, raw `0x005aaff0`, and raw `0x005ac1b0`.
- `0x005ac070`: called from UserPane OnServerMessage at `0x005a8172`.
- `0x005ac280`: called from UserPane OnServerMessage at `0x005a8002`.
- `0x005acc30`: called by `0x005a58c0` at `0x005a5956`.
- `0x005ad360`: called four times from UserPane OnKeyEvent at `0x005a5e40`, `0x005a5e54`, `0x005a5e68`, `0x005a5e7c`.

Callee evidence checked:

- `0x005a2e00` calls packet sender/state/movement helpers and walk-animation helpers.
- `0x005a3ae0` calls `0x005a3e30`, `0x005a4530`, packet sender, and character conversion helpers.
- `0x005a4530` calls input-pane/allocation helpers and packet sender.
- `0x005a58c0` calls `0x005acc30`.
- `0x005a76c0` dispatches into many local-player packet handlers: `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abda0`, `0x005ac070`, `0x005ac280`.
- `0x005aa480`, `0x005aa710`, `0x005aac80`, `0x005ab090`, `0x005ab410`, `0x005ab860`, `0x005abb20`, `0x005abda0`, `0x005ac070`, `0x005ac280`, `0x005acc30`, and `0x005ad360` all have packet-parser/sender or local-player state dependencies consistent with LivingObjectPane local-player packet work.

## Raw islands and ignored rows

Recommended ignored rows after exact child creation:

```text
        - 0x005a3ad4-0x005a3ae0: padding/alignment after raw helper 0x005a3a20-0x005a3ad4.
        - 0x005a9307-0x005a9310: padding/alignment after raw helper 0x005a9250-0x005a9307.
        - 0x005ab084-0x005ab090: padding/alignment after raw helper 0x005aaff0-0x005ab084.
        - 0x005ac27c-0x005ac280: padding/alignment after raw helper 0x005ac1b0-0x005ac27c.
        - 0x005ac99b-0x005ac9a0: padding/alignment after raw helper 0x005ac7e0-0x005ac99b.
        - 0x005acad5-0x005acae0: padding/alignment after raw helper 0x005ac9a0-0x005acad5.
```

Existing ignored rows that remain correct:

```text
        - 0x005acb1f-0x005acb20: padding/alignment after [UID:0003H4].
        - 0x005acc23-0x005acc30: padding/alignment after [UID:0003H5].
```

Additional small gaps exist throughout the broader neighborhood. I did not recommend blanket ignored rows for every function gap because several have not yet been byte-confirmed as pure padding in this pass.

## Coverage report recommendation

Do not apply this replacement until the supervisor is ready to perform the corresponding by-memory edits and either rename the target page to the corrected half-open end or intentionally keep the old filename with an explicit range note.

Placement: replace the current [UID:0001KM] row and nested subtree under [UID:0001KL] in `by-memory/-coverage-report.md`.

Exact replacement parent row text:

```text
    - [UID:0001KM][0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad440.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | mixed source-family split index | LivingObjectPaneLocalPlayerExtensions : non-reconstructable : 88% : strong : B001 2026-06-16 audit recommends reclassifying this overbroad local-player/UserPane neighborhood as a non-emitting split index after exact child pages are created; live IDA confirms modeled LivingObjectPane movement/action/server-packet starts, UserPane and social/dialog exclusions, raw no-xref helper islands at 0x005a3a20/0x005a9250/0x005aaff0/0x005ac1b0/0x005ac7e0/0x005ac9a0, and a function-end mismatch requiring the parent range to cover the 0x005ad360-0x005ad441 attack helper.
```

If the page is renamed to the corrected half-open end, use this link target instead:

```text
    - [UID:0001KM][0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions](by-memory/0x005a2de0-0x005ad441.LivingObjectPaneLocalPlayerExtensions.md) 0x005a2de0-0x005ad441 | mixed source-family split index | LivingObjectPaneLocalPlayerExtensions : non-reconstructable : 88% : strong : B001 2026-06-16 audit recommends reclassifying this overbroad local-player/UserPane neighborhood as a non-emitting split index after exact child pages are created; live IDA confirms modeled LivingObjectPane movement/action/server-packet starts, UserPane and social/dialog exclusions, raw no-xref helper islands at 0x005a3a20/0x005a9250/0x005aaff0/0x005ac1b0/0x005ac7e0/0x005ac9a0, and a function-end mismatch requiring the parent range to cover the 0x005ad360-0x005ad441 attack helper.
```

Child rows should then be inserted below this parent in address order after UIDs are allocated. Do not invent final UIDs in the coverage report. Use the existing child rows for [UID:0002RW], [UID:0001KN], [UID:0003H4], and [UID:0003H5], preserve [UID:0001KO], [UID:0001KP], and [UID:0001KQ] as source-family exclusions/siblings, and add the raw ignored rows listed above.

## Remaining unresolved issues

1. `0x005a3890-0x005a38c4` and `0x005a39a0-0x005a39d4` have no xrefs to their starts.
   Evidence checked: `lookup_funcs`, `entity_query`, `xrefs_to`, and local disassembly text. The first body appears packet-buffer-like, but no caller or source-family document binds it safely. Keep them out of emitted source until caller/behavior evidence is found.

2. `0x005a57a0-0x005a5a85` is not cleanly named.
   Evidence checked: function starts, xrefs, callees for `0x005a57a0`, `0x005a5820`, `0x005a5870`, `0x005a58c0`, `0x005a5990`, `0x005a5a80`. `0x005a58c0` is strongly connected to `0x005acc30`, but the surrounding small functions have weaker source-owner evidence.

3. `0x005a89d0-0x005a8ad6`, `0x005a8c60-0x005a8ce7`, and `0x005a8fc0-0x005a94a4` need a separate naming/vtable pass.
   Evidence checked: function starts and xrefs. Some starts have map-side callers or data xrefs, and `0x005a9240` is vtable-adjacent. That is enough to avoid LivingObjectPane emission, not enough for final owner assignment.

4. `0x005a95e0-0x005aa0c0` appears ChatInputPane/Chatting-related but remains unsplit.
   Evidence checked: target page, ChatInputPane global docs, function inventory. The evidence supports exclusion from LivingObjectPane but not exact source boundaries inside the region.

5. `0x005abb20`, `0x005aba80`, `0x005abc70`, and `0x005ac000` have weak or absent direct start xrefs.
   Evidence checked: `xrefs_to` for starts and `callees`. Some bodies fit the local-player packet-handler family, but absent direct reachability limits final C++ confidence. If retained as children, mark the reachability caveat explicitly.

6. `0x005ac070-0x005ac1a8` constructs/uses MessageShowPane but is called as a server packet handler from UserPane OnServerMessage.
   Evidence checked: xref from `0x005a8172`, callees including MessageShowPane constructor. The best current route is LivingObjectPane server-packet child with MessageShowPane dependency, but source placement confidence is medium.

7. Parent end `0x005ad440` conflicts with IDA function end `0x005ad441`.
   Evidence checked: `lookup_funcs` reports `0x005ad360` size `0xe1`; target body already cites `0x005ad360-0x005ad441`. This should be fixed before final coverage normalization.

## Validations run

- IDA read-only session opened successfully for `NexusTK.exe` with MCP health check OK.
- `lookup_funcs` confirmed modeled and non-modeled starts across the requested target range.
- `entity_query` enumerated function starts across `0x005a2530-0x005ad440`.
- `xrefs_to` checked requested raw starts and principal child start candidates.
- `callees` checked representative movement, action, UserPane dispatch, and packet-handler functions.
- `make_signature_for_range` confirmed unique signatures for raw islands `0x005a3a20-0x005a3ae0`, `0x005a9250-0x005a9310`, `0x005aaff0-0x005ab090`, `0x005ac1b0-0x005ac280`, and `0x005ac7e0-0x005acae0`.
- No by-memory, by-file, generated report, coverage report, or IDA database files were edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001KM-livingobject-localplayer-source-split-audit.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001KM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
