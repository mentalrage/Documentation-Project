** TARGET-REPORT-UID:000019 **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000019 BrowserPane Class Source-Quality Reanalysis

## Finalized Report / Current Recommendation

- Status: FINISHED.
- Target UID: [UID:000019].
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\BrowserPane.md`.
- Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\000019-BrowserPane-class-source-quality.md`.
- Current target state: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000HV`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HV`, formal C++ blank.
- Recommended target state after implementation: `COMPLETION:87`, `CONFIDENCE:89`, keep `CANONICAL_OWNER:0000HV`, keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000HV`, keep `EMITTER_POSITION_OPTIONAL` blank.
- Recommended source-facing role: `BrowserPane`, a browser-module `DialogPane`-derived base for browser dialog command, key, and timer-facet behavior.
- Recommended source placement: keep the direct file owner [UID:0000HV] `Browser`, current physical reconstruction root `NexusTK/browser/Browser.cpp`. Treat a later `BrowserPane.cpp` / `BrowserDialog.cpp` split as possible but not required or proven now.
- Recommended formal C++ for the class page now: keep the target formal C++ block blank. The class page is eligible numerically, but the constructor signature is still unsafe, exact method bodies are not all split into direct child pages, and one existing method child carries a stale `PlaySound` name that should be corrected first. The report provides method-level C++ readiness guidance below.
- Coverage report handling: do not edit `by-memory/-coverage-report.md`. Exact class coverage row and supervisor-owned memory-row templates are provided below.
- Report-only compliance: no by-* documentation file and no `by-memory/-coverage-report.md` were edited in this pass.

## Target

`BrowserPane` currently describes a browser-related `DialogPane`-derived UI base that handles browser command codes, a browser key-event filter, timer delegation through the inherited `+0xa4` timer/event facet, and destruction/vtable cleanup. The target page is currently good enough for source ownership but still carries open questions about:

- the raw constructor-shaped block at `0x0046a860`;
- the final one-file versus split-file browser source placement;
- stale or underspecified helper names, especially the `BrowserPanePlaySound` child;
- whether `0x0046ad80` is a BrowserPane method;
- shared `DialogPane` helper exclusions;
- whether first-draft class or method C++ should be emitted now.

This report closes the source-placement direction to the strongest current inference, corrects the raw constructor range, corrects the timer-cancel/sound naming issue, and gives exact target/support implementation steps.

## Evidence Checked

Documentation evidence checked:

- Target class [UID:000019] `by-class/BrowserPane.md`.
- Browser file owner [UID:0000HV] `by-file/Browser.md`.
- BrowserDialog class [UID:000017] `by-class/BrowserDialog.md`.
- Mixed executable aggregate [UID:0000Z5] `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md`.
- Scalar deleting destructor child [UID:00033C] `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`.
- Timer/sound-stale child [UID:000217] `by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md`.
- Mixed OLE/thunk aggregate [UID:00033M] `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`.
- Browser vtable/string container [UID:0001OB] `by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md`.
- Browser alert strings [UID:0001OD] `by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md`.
- Shared dialog-control helper inventory [UID:00012S] `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`.
- DialogPane layout [UID:0001U4] `by-type/by-struct/DialogPaneLayout.md`.
- TimerHandler class [UID:0000F0] `by-class/TimerHandler.md`.
- TimerHandler wrappers [UID:0001K8] `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md` and [UID:0001K9] `by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md`.
- Active browser-pane global [UID:0000PP] `by-global/g_activeBrowserPane.md` and exact storage [UID:0001P9] `by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md`.
- Proposed source tree `by-project-structure/proposed-source-tree.md`, especially `browser/Browser.cpp`.
- Prior B002 report `tools/leaser/Agents/Agent-B002/research/0000Z5-BrowserPaneAndDialog-source-quality.md`.
- Current auto-generated `NexusTK/browser/Browser.cpp`, which contains only empty BrowserPane markers.

Local PE evidence checked:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA1: `c285b73dc7b54c9a0e28ff7591a9bdde2ac55f9a`.
- Image base: `0x00400000`.
- Capstone disassembly over `0x0046a860-0x0046a8a0`, `0x0046a8a0-0x0046a8c0`, `0x0046a8e0-0x0046a910`, `0x0046a910-0x0046aa40`, `0x00470690-0x004706e5`, `0x00470fc0-0x00470fdc`, and `0x004710d0-0x004710df`.
- Dword scans for absolute and RVA pointer hits to selected BrowserPane method starts and into the raw constructor body.
- Rel32 branch scan for calls/jumps to selected BrowserPane method starts.
- Vtable dword dump over `0x006132ec-0x00613444` and `0x006135dc-0x00613734`.

Validator baseline:

> Executable block R001 was removed from this report and preserved verbatim in [000019-BrowserPane-class-source-quality-removed.md](000019-BrowserPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The validator output included generated/autogen no-op and "emitter has no code" diagnostics across the registry, but the direct target validation succeeded with `ok: 1`.

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor-Shaped Block At `0x0046a860`

Best-supported source-facing name:

- `BrowserPane::BrowserPane(...)`, retained raw constructor-shaped body.
- The exact source parameter list is not safe. The body ends with `ret 8`, so two stack arguments are cleaned, but the local PE body does not read `[ebp+8]` or `[ebp+0xc]`.

Validated facts:

- The body begins at `0x0046a860` with `push ebp; mov ebp, esp`.
- It pushes `1`, `-1`, and `0x0060db20`, stores `this` in `esi`, calls `0x0049d8a0`, installs BrowserPane vtables at `this+0x00 = 0x006132ec`, `this+0xa0 = 0x00613360`, and `this+0xa4 = 0x00613390`, then returns `this` in `eax`.
- Local PE disassembly proves the `ret 8` instruction starts at `0x0046a898` and occupies bytes `0x0046a898-0x0046a89b`.
- Therefore the source-bearing half-open constructor-shaped range is `0x0046a860-0x0046a89b`, and padding is `0x0046a89b-0x0046a8a0`.
- This corrects both older target prose that implied `0x0046a860-0x0046a898` and the B002 note that the generated source-map lead might be `0x0046a860-0x0046a89a`.

Negative evidence checked:

- Local PE absolute pointer scan found no pointer hit to `0x0046a860`.
- Local PE RVA scan found no RVA hit to `0x0046a860`.
- Local PE rel32 call/jump scan found no direct branch to `0x0046a860`.
- Local PE absolute pointer scan found no pointer into the constructor body `0x0046a860-0x0046a898`.
- Existing docs also report no IDA function at `0x0046a860`; previous function is `0x0046a630-0x0046a6ea`, and the next modeled function is `0x0046a8a0-0x0046a8bf`.

Inference:

- This is almost certainly a retained source-authored `BrowserPane` constructor body because it calls the `DialogPane` constructor and installs the exact BrowserPane three-view vtable family.
- It is not a safe formal C++ body yet because the entry route is unproven and the two cleaned stack arguments have no observed use.
- Do not emit `BrowserPane::BrowserPane()` as a no-argument constructor. That shape contradicts `ret 8`.
- A future split child should use exact range `0x0046a860-0x0046a89b` and document `0x0046a89b-0x0046a8a0` as `int3` padding.

Rejected alternatives:

- Reject `BrowserDialog` ownership: BrowserDialog construction later installs BrowserPane vtables, then BrowserDialog vtables, but this standalone raw body installs only BrowserPane vtables.
- Reject a general Browser file helper name: object construction and vtable stores are class-specific.
- Reject final constructor C++ now: no entry xref and unknown unused stack parameters make the source signature unsafe.

### `0x0046a8a0` Vtable Reset / Base Cleanup Wrapper

Best-supported source-facing name:

- `BrowserPane::~BrowserPane()` non-deleting cleanup body, or `BrowserPane` destructor-family cleanup.
- Keep the descriptive wording "vtable reset / base cleanup wrapper" until the three refs are classified as EH/unwind cleanup versus ordinary destructor calls.

Validated facts:

- Local PE bytes for `0x0046a8a0-0x0046a8bf` write the same BrowserPane vtable pointers at `+0x00`, `+0xa0`, and `+0xa4`, then tail-jump to `0x0049d9f0`.
- `0x0049d9f0` is the `DialogPane` cleanup / non-deleting destructor body per [UID:00012R] and [UID:0001U4].
- Local PE rel32 scan found three branch refs to `0x0046a8a0` at `0x005fac2e`, `0x005fad79`, and `0x005fae35`. These are not ordinary BrowserPane vtable refs and should be documented as cleanup/EH table route evidence pending a focused EH pass.
- There is one byte of `int3` padding at `0x0046a8bf-0x0046a8c0`.

Inference:

- This is BrowserPane-owned destructor-family code. It is not BrowserDialog-owned and not a generic Browser helper.
- It should not get independent source C++ body text until the cleanup refs are classified. The handwritten C++ effect is likely an empty destructor with base cleanup generated by the compiler.

Rejected alternatives:

- Reject assigning this to the scalar deleting wrapper child: [UID:00033C] at `0x00470690-0x004706e5` is the scalar deleting destructor slot and repeats the vtable restore/base cleanup plus delete-flag logic.
- Reject emitting compiler vtable stores as handwritten source statements.

### `BrowserPane::OnKeyEvent` At `0x0046a8e0`

Best-supported source-facing name:

- `BrowserPane::OnKeyEvent`, `BrowserPane::HandleKeyEvent`, or a project-local equivalent.
- Current docs use `OnKeyEvent`; keep it.

Validated facts:

- Local PE bytes for `0x0046a8e0-0x0046a901` compare byte `[event+4]` to `8` and byte `[event+8]` to `0x90`.
- If both match, it returns `al = 1` and `ret 4`.
- Otherwise it tail-jumps to `0x0049e6e0` with the event pointer preserved.
- [UID:00012R] identifies `0x0049e6e0` as the shared `DialogPane` keyboard/focus/selection handler.
- Vtable refs place this method at `0x00613368`, `0x00613418`, and `0x00613708`, proving BrowserPane-family virtual reachability.
- Padding is `0x0046a901-0x0046a910`.

Inference:

- This is a BrowserPane virtual key/filter override that consumes one specific input-event tuple and otherwise delegates to the inherited DialogPane input path.
- The exact event type and field names are not safe. The two byte tests are facts; names such as `keyCode`, `message`, `modifierFlags`, or `virtualKey` remain descriptive guesses until the shared event layout is source-quality reviewed.

Rejected alternatives:

- Reject a BrowserDialog-only owner: the vtable refs include BrowserPane and WebBoard-derived BrowserPane-family slots.
- Reject B002's illustrative `VK_BACK`/modifier draft as final. It is useful behavior guidance only. The current binary facts are byte `+4 == 8` and byte `+8 == 0x90`; no source field names are proven.

### `BrowserPane::OnCommand` At `0x0046a910`

Best-supported source-facing name:

- `BrowserPane::OnCommand`.
- Command constants should be named as Browser command/error constants, not raw decimals.

Validated facts:

- Exact range: `0x0046a910-0x0046aa34`; padding `0x0046aa34-0x0046aa40`.
- Function returns `al = 1` and `ret 0x0c`, so it cleans three stack arguments.
- Vtable refs place the method at `0x00613348`, `0x006133f8`, `0x00613638`, and `0x006136e8`.
- It handles:
  - `0x42436470` decimal `1111712880`, displayed as `"BCdp"`, using `0x00613a20` `Dispose`.
  - `0x4243666c` decimal `1111713388`, displayed as `"BCfl"`, using `0x00613a30` `Navigation Failed`.
  - `0x4243746f` decimal `1111716975`, displayed as `"BCto"`, using `0x00613a54` `Navigation Timeout`.
  - `0x00000572` decimal `1394`, using `0x00613a7c` `Web Board Request Timeout`.
- Each handled branch allocates `0x270` bytes through `0x004f4aa0`, constructs an alert through `0x0049feb0`, passes shared OK text `0x00613a18`, and calls `0x0049df20(this)` afterward.
- [UID:0001OD] already resolves the four browser alert literals and rejects `g_pBrowserFileLoadText` / `g_pBrowserTimeoutText` as direct-pointer globals.
- [UID:00012S] resolves `0x0049df20` as the shared `DialogPaneActivatePendingControl` child, not a BrowserPane-private helper.

Inference:

- Source-facing C++ should use named Browser command constants and Browser alert string constants.
- The shared OK string remains external/shared dialog text.
- `sub_49DF20(this)` should be written as inherited/shared `DialogPane::ActivatePendingControl()` or the accepted local equivalent, not as a browser-private activation helper.

Rejected alternatives:

- Reject `g_pBrowserFileLoadText` and `g_pBrowserTimeoutText` as source globals. They are generated aliases over direct string literal addresses.
- Reject assigning `0x0049df20` to BrowserPane. Its caller fan-in and exact child split prove DialogPane ownership.

### Timer-Facet Schedule Method At `0x00470fc0`

Best-supported source-facing name:

- `BrowserPane::ScheduleTimer`, `BrowserPane::ScheduleTimerEvent`, or inherited virtual forwarding to `TimerHandler::ScheduleTimer`.
- Current class wording `ScheduleTimer` is acceptable.

Validated facts:

- Exact body: `0x00470fc0-0x00470fdc`.
- It pushes two zero payload arguments, forwards `[ebp+0xc]` and `[ebp+8]`, adjusts `ecx += 0xa4`, calls `0x005975e0`, and returns `ret 8`.
- [UID:0001K8] resolves `0x005975e0` as a generic `TimerHandler::ScheduleTimer` candidate forwarding through `g_pTimerMgr`.
- Vtable refs place this BrowserPane-family method at `0x0061334c`, `0x006133fc`, `0x0061363c`, and `0x006136ec`.
- The method currently lives only inside mixed non-emitting [UID:00033M], which inventories it as a BrowserPane semantic owner but does not provide an exact child page.

Inference:

- This should be split into an exact BrowserPane child page `0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md`.
- The direct parent should be [UID:000019] `BrowserPane`, emitting through [UID:0000HV] `Browser`.
- Formal method C++ can be a thin wrapper only after the TimerHandler method names are accepted. Until then, prose can safely say it forwards to the `+0xa4` TimerHandler facet.

Rejected alternatives:

- Reject leaving the method only in the mixed OLE/thunk aggregate long term. It is a source-shaped BrowserPane virtual helper, not an ABI adjustor thunk.
- Reject assigning it to TimerMgr/TimerHandler as direct owner. The callee is TimerHandler, but this wrapper is BrowserPane vtable-owned.

### `0x004710d0` Historical `PlaySound` Child

Best-supported source-facing name:

- `BrowserPane::CancelTimer` or `BrowserPane::CancelTimerEvent`.
- Keep `BrowserPanePlaySound` only as historical/search wording until the file can be renamed.

Validated facts:

- Exact body: `0x004710d0-0x004710df`.
- It adjusts `ecx += 0xa4` and tail-jumps to `0x00597610`.
- [UID:0001K9] resolves `0x00597610` / `sub_597610` as the generic `TimerHandler::CancelTimer` candidate, forwarding through `g_pTimerMgr` to `0x00597b80`.
- Local PE vtable refs place this BrowserPane-family method at `0x00613350`, `0x00613400`, `0x00613640`, and `0x006136f0`.
- The body contains no audio or sound-manager logic.

Inference:

- The current [UID:000217] filename and generated name `BrowserPanePlaySound` are stale. The best source-quality role is `BrowserPane::CancelTimer(int eventId)` or `CancelTimerEvent(int eventId)`.
- This is paired with `0x00470fc0` schedule forwarding: schedule uses `TimerHandler::ScheduleTimer`, cancel uses `TimerHandler::CancelTimer`.
- If the broader Pane virtual table historically named this slot something audio-related, the implementation must still document that the local body is a timer-cancel forwarder, not sound playback. Current TimerHandler evidence makes `PlaySound` weaker than `CancelTimer`.

Rejected alternatives:

- Reject SoundManager ownership: [UID:0001K9] already rejects stale SoundManager ownership for `0x00597610`; the BrowserPane wrapper is a caller/forwarder only.
- Reject final source name `PlaySound` as best-supported. It is contradicted by the callee semantics and the schedule/cancel slot pairing.

### Scalar Deleting Destructor At `0x00470690`

Best-supported source-facing role:

- MSVC scalar deleting destructor wrapper for `BrowserPane`, not a handwritten source body.

Validated facts:

- Exact range: `0x00470690-0x004706e5`.
- Primary BrowserPane vtable slot `0x006132ec` points to this wrapper.
- Adjustor thunk refs are at `0x004702c0` and `0x004702cb`.
- The body restores BrowserPane vtables, calls `0x0049d9f0`, tests delete flag bit `1`, tests flag bit `4`, and then calls either `0x004f4ac0` or `0x0041b6a0` with size `0x278`.
- [UID:00033C] documents the same behavior and already says to reconstruct via the destructor/class declaration, not by hand-emitting the wrapper.

Inference:

- Keep [UID:00033C] formal C++ blank. The source-level declaration is a virtual destructor on `BrowserPane`; the scalar deleting wrapper is compiler output.
- The allocation/delete size `0x278` supports `BrowserPane` object size or an allocator-size path, but do not force a final `sizeof(BrowserPane)` field layout solely from this wrapper without reconciling derived BrowserDialog sizes.

Rejected alternatives:

- Reject ordinary source method emission for the scalar wrapper.
- Reject folding the wrapper into mixed [UID:00033M] or [UID:0000Z5]; exact BrowserPane ownership is proven by vtable slot and vtable restores.

### `0x0046ad80` BrowserDialog Input/Reposition Override

Best-supported source-facing owner:

- [UID:000017] `BrowserDialog`, not [UID:000019] `BrowserPane`.

Validated facts:

- [UID:000017] lists `0x0046ad80-0x0046aea8` as `BrowserDialog::OnInputEventWithBrowserReposition(...)`.
- BrowserDialog vtable slot `0x00613414` points to `0x0046ad80`.
- It belongs to the adjacent [UID:00020X] BrowserDialog virtual cluster after `0x0046ad10`.

Inference:

- Remove or rewrite the BrowserPane method row that currently lists `0x0046ad80` as "resized input handler installed through the BrowserDialog/BrowserPane vtable cluster."
- Correct support wording: BrowserPane is the inherited base dependency, but the concrete method is BrowserDialog-owned.

Rejected alternatives:

- Reject making [UID:000019] directly own `0x0046ad80`.
- Reject using BrowserPane inheritance alone as a direct ownership signal.

### Shared DialogPane Helper Exclusions

Best-supported source-facing roles:

- `0x0049d8a0`: `DialogPane::DialogPane` constructor.
- `0x0049d9f0`: `DialogPane` cleanup / non-deleting destructor body.
- `0x0049e6e0`: shared `DialogPane` keyboard/focus/selection handler.
- `0x0049df20`: [UID:0003KP] `DialogPaneActivatePendingControl`.
- `0x0049feb0`: AlertPane construction path, source owner AlertPanes/Dialog alert infrastructure, not BrowserPane.
- `0x004f4aa0`: allocation helper / operator-new wrapper.
- `0x004f4ac0`: scalar delete/operator-delete wrapper.

Inference:

- BrowserPane consumes these helpers; it does not own them.
- BrowserPane source C++ should call inherited/dialog/alert abstractions rather than emit `sub_` helpers as BrowserPane-local functions.

Rejected alternatives:

- Reject Browser-private ownership of the `0x0049dd20-0x0049dfc4` control helper band. [UID:00012S] has exact child splitting and broad caller distribution proving `DialogPane` ownership.

### Fields, Types, Globals, And Vtables

Best-supported layout/type directions:

- `BrowserPane` derives from `DialogPane` or a same-layout dialog base with inherited three-view vtable layout at `+0x00`, `+0xa0`, and `+0xa4`.
- `+0x00`: primary BrowserPane view, table `0x006132ec`.
- `+0xa0`: secondary inherited/interface view, table `0x00613360`.
- `+0xa4`: tertiary timer/event-handler view, table `0x00613390`.
- The `+0xa4` facet should be named as an inherited TimerHandler/event-update facet when writing behavior notes. Do not model it as a BrowserPane-specific data field.
- `g_activeBrowserPane` at `0x0067ab84`: high-probability `BrowserPane *` active owner/callback target, Browser-owned global. Current docs still keep final lifetime clear open, but BrowserPane type is the best source-facing direction because BrowserControlPane constructor publishes a browser-pane owner and Browser dispatch uses it for close/document-complete callback routing.
- `word_60DB20`: unresolved DialogPane constructor title/resource operand for the raw BrowserPane constructor. Do not rename beyond a cautious `kBrowserPaneDialogTitle` / `kBrowserPaneDialogResource` candidate until raw bytes/string identity are decoded.

Rejected alternatives:

- Reject treating `+0xa4` as a SoundManager field. TimerHandler docs prove scheduler ownership and broad timer-facet usage across pane classes.
- Reject a BrowserPane-owned global for the alert literals. [UID:0001OD] owns constants under the Browser file root.

### Source Placement

Best-supported source route:

- Keep BrowserPane under [UID:0000HV] `Browser`, current `NexusTK/browser/Browser.cpp` route.

Evidence:

- `by-project-structure/proposed-source-tree.md` has a dedicated `browser/Browser.cpp` grouping for `Browser`, `BrowserWindow`, `BrowserThread`, `BrowserControlPane`, `BrowserControlPaneOld`, `BrowserDialog`, `BrowserDialogOld`, `BrowserPane`, `browser::Notification`, COM helpers, browser enums, globals, and browser static strings.
- [UID:0000HV] `Browser.md` currently proposes `browser/Browser.cpp` and lists BrowserPane in that source root.
- BrowserPane `OnCommand` consumes Browser alert constants and browser command ids.
- BrowserPane vtables are reused by BrowserDialog and WebBoard-derived browser dialogs.
- Dense memory locality ties BrowserPane to the browser/OLE module around `0x00469290-0x004710df`.

Inference:

- Original source may have had separate files inside a browser folder, but the highest-probability current reconstruction route is the established Browser file root. The source split question should be documented as "possible later browser-folder refinement", not an unresolved blocker for ownership.

Rejected alternatives:

- Reject moving BrowserPane to generic `DialogPane` or UI-core ownership. It derives from DialogPane but implements browser-specific command and timer behavior.
- Reject WebBoard ownership. WebBoard dialogs depend on BrowserPane, but BrowserPane is the base and also used by BrowserDialog.
- Reject standalone `BrowserPane.cpp` as a required current implementation target. It is plausible but not proven by binary evidence; current source-tree model groups the browser subsystem.

## Local PE Disassembly Facts

### Raw Constructor-Shaped Body

```asm
0046a860  push ebp
0046a861  mov ebp, esp
0046a863  push ecx
0046a864  push esi
0046a865  push 1
0046a867  push -1
0046a869  mov esi, ecx
0046a86b  push 60DB20h
0046a870  mov [ebp-4], esi
0046a873  call 49D8A0h
0046a878  mov dword ptr [esi], 6132ECh
0046a87e  mov eax, esi
0046a880  mov dword ptr [esi+0A0h], 613360h
0046a88a  mov dword ptr [esi+0A4h], 613390h
0046a894  pop esi
0046a895  mov esp, ebp
0046a897  pop ebp
0046a898  ret 8
0046a89b  int3
0046a89c  int3
0046a89d  int3
0046a89e  int3
0046a89f  int3
```

Conclusion: source body `0x0046a860-0x0046a89b`; padding `0x0046a89b-0x0046a8a0`.

### Cleanup Wrapper

```asm
0046a8a0  mov dword ptr [ecx], 6132ECh
0046a8a6  mov dword ptr [ecx+0A0h], 613360h
0046a8b0  mov dword ptr [ecx+0A4h], 613390h
0046a8ba  jmp 49D9F0h
0046a8bf  int3
```

### Key Event Override

```asm
0046a8e0  push ebp
0046a8e1  mov ebp, esp
0046a8e3  mov eax, [ebp+8]
0046a8e6  cmp byte ptr [eax+4], 8
0046a8ea  jne 46A8F8h
0046a8ec  cmp byte ptr [eax+8], 90h
0046a8f0  jne 46A8F8h
0046a8f2  mov al, 1
0046a8f4  pop ebp
0046a8f5  ret 4
0046a8f8  mov [ebp+8], eax
0046a8fb  pop ebp
0046a8fc  jmp 49E6E0h
0046a901  int3
```

### Command Override

Important local PE facts:

- Exact range: `0x0046a910-0x0046aa34`.
- SEH setup references `0x005fac10`.
- Command compare order: `0x4243666c`, `0x00000572`, `0x42436470`, `0x4243746f`.
- Allocation size: `0x270`.
- Alert constructor: `0x0049feb0`.
- Shared OK string: `0x00613a18`.
- Browser alert strings: `0x00613a20`, `0x00613a30`, `0x00613a54`, `0x00613a7c`.
- Shared DialogPane activation: `0x0049df20`.
- Return: `al = 1`, `ret 0x0c`.

### Timer-Facet Wrappers

`0x00470fc0-0x00470fdc`:

```asm
00470fc0  push ebp
00470fc1  mov ebp, esp
00470fc3  push 0
00470fc5  push 0
00470fc7  push [ebp+0Ch]
00470fca  add ecx, 0A4h
00470fd0  push [ebp+8]
00470fd3  call 5975E0h
00470fd8  pop ebp
00470fd9  ret 8
```

`0x004710d0-0x004710df`:

```asm
004710d0  push ebp
004710d1  mov ebp, esp
004710d3  add ecx, 0A4h
004710d9  pop ebp
004710da  jmp 597610h
```

Conclusion: schedule and cancel timer facet methods, not schedule and sound.

## Function / Child Inventory

| Range / item | Current UID/path | Best role | Direct parent | C++ readiness | Status |
| --- | --- | --- | --- | --- | --- |
| `0x0046a860-0x0046a89b` | Inside [UID:0000Z5] | `BrowserPane::BrowserPane(...)` raw constructor-shaped body | [UID:000019] BrowserPane | blank | Needs exact child split; no entry xref and stack parameters unsafe. |
| `0x0046a89b-0x0046a8a0` | currently inside [UID:0000Z5] | padding | ignored | none | Five `int3` bytes; old range notes should be corrected. |
| `0x0046a8a0-0x0046a8bf` | Inside [UID:0000Z5] | `BrowserPane` destructor-family cleanup | [UID:000019] BrowserPane | blank | Needs exact child split; classify cleanup refs. |
| `0x0046a8bf-0x0046a8c0` | currently inside [UID:0000Z5] | padding | ignored | none | One `int3` byte. |
| `0x0046a8c0-0x0046a8d7` | Inside [UID:0000Z5] | `BrowserDialog::NavigateToUrl` | [UID:000017] BrowserDialog | ready after split | Not BrowserPane-owned. |
| `0x0046a8d7-0x0046a8e0` | currently inside [UID:0000Z5] | padding | ignored | none | Alignment. |
| `0x0046a8e0-0x0046a901` | Inside [UID:0000Z5] | `BrowserPane::OnKeyEvent` | [UID:000019] BrowserPane | near-ready | Event field names still provisional. |
| `0x0046a901-0x0046a910` | currently inside [UID:0000Z5] | padding | ignored | none | Alignment. |
| `0x0046a910-0x0046aa34` | Inside [UID:0000Z5] | `BrowserPane::OnCommand` | [UID:000019] BrowserPane | ready after constants/types | Command and alert behavior source-quality enough after split. |
| `0x0046aa34-0x0046aa40` | currently inside [UID:0000Z5] | padding | ignored | none | Alignment. |
| `0x0046aa40-0x0046ad0a` | Inside [UID:0000Z5] | `BrowserDialog::BrowserDialog` | [UID:000017] BrowserDialog | blank | Not BrowserPane-owned. |
| `0x00470690-0x004706e5` | [UID:00033C] | BrowserPane scalar deleting destructor | [UID:000019] BrowserPane | blank | Compiler wrapper; document source-level destructor instead. |
| `0x00470fc0-0x00470fdc` | Inside [UID:00033M] | `BrowserPane::ScheduleTimer` | [UID:000019] BrowserPane | blank or thin wrapper after split | Should become exact child. |
| `0x004710d0-0x004710df` | [UID:000217] currently `BrowserPanePlaySound` | `BrowserPane::CancelTimer` / `CancelTimerEvent` | [UID:000019] BrowserPane | blank or thin wrapper after rename | Existing title/name is stale. |
| `0x0046ad80-0x0046aea8` | [UID:00020X] BrowserDialog virtual cluster | `BrowserDialog::OnInputEventWithBrowserReposition` | [UID:000017] BrowserDialog | separate BrowserDialog target | Remove as direct BrowserPane method. |

## Direct Xref / Caller Inventory

| Target | Evidence | Meaning |
| --- | --- | --- |
| `0x0046a860` | `abs=0`, `rva=0`, `rel32=0`; no absolute pointer into constructor body | Raw constructor-shaped block has no proven ordinary entry route. |
| `0x0046a8a0` | rel32 refs at `0x005fac2e`, `0x005fad79`, `0x005fae35`; no absolute/rva hits | Cleanup/EH-style route, not vtable dispatch. |
| `0x0046a8e0` | absolute dwords at `0x00613368`, `0x00613418`, `0x00613708` | BrowserPane-family virtual key slot. |
| `0x0046a910` | absolute dwords at `0x00613348`, `0x006133f8`, `0x00613638`, `0x006136e8` | BrowserPane-family virtual command slot. |
| `0x00470690` | absolute dword at `0x006132ec`; rel32 refs at `0x004702c0`, `0x004702cb` | Scalar deleting destructor vtable slot plus adjustor thunks. |
| `0x00470fc0` | absolute dwords at `0x0061334c`, `0x006133fc`, `0x0061363c`, `0x006136ec` | BrowserPane-family virtual schedule slot. |
| `0x004710d0` | absolute dwords at `0x00613350`, `0x00613400`, `0x00613640`, `0x006136f0` | BrowserPane-family virtual cancel-timer slot; stale "sound" wording. |
| `0x0046ad80` | BrowserDialog vtable slot `0x00613414` per local vtable dump and [UID:000017] | BrowserDialog-owned input/reposition override. |

## Ranked Ownership Analysis

### 1. [UID:000019] BrowserPane Under [UID:0000HV] Browser

Evidence for:

- Raw constructor-shaped body installs BrowserPane vtables only.
- Key, command, schedule, cancel-timer, and scalar destructor slots all have BrowserPane-family vtable refs.
- BrowserPane uses Browser alert constants and Browser command FourCCs.
- BrowserPane vtables are inherited/reused by BrowserDialog and WebBoard-derived browser dialogs.
- [UID:0000HV] Browser source root is the current proposed source-tree owner for the browser subsystem and clears the parent gate.

Evidence against:

- The raw constructor has no ordinary xref and an unresolved two-stack-argument cleanup.
- Some methods are physically inside mixed aggregates and should be split before formal method C++.
- `0x0046ad80` is currently mentioned on BrowserPane but is BrowserDialog-owned.

Decision:

- Accept BrowserPane as the direct class owner.
- Keep Browser file root [UID:0000HV] as source owner/emitter.
- Raise class documentation after implementation to `87/89` but keep formal C++ blank until constructor signature and child splits are corrected.

### 2. [UID:0000HV] Browser As File-Level Root

Evidence for:

- Proposed source tree groups browser classes and helpers under `browser/Browser.cpp`.
- Browser file page already groups BrowserPane, BrowserDialog, BrowserControlPane, BrowserWindow, BrowserThread, COM helpers, browser enums/globals, and alert strings.
- Dense address locality and shared Browser/OLE data support a browser source root.

Evidence against:

- Some source-level class files may have existed separately inside a browser folder.
- WebBoard-derived browser dialogs are not Browser-owned despite depending on BrowserPane.

Decision:

- Keep current Browser source root. Document possible later file split as source-tree refinement only.

### 3. DialogPane / UI-Core Ownership

Evidence for:

- BrowserPane derives from DialogPane and uses DialogPane constructor, cleanup, key/focus handling, and activation helpers.

Evidence against:

- BrowserPane command ids, alert strings, vtables, and derived browser dialog relationships are browser-specific.
- DialogPane helper docs show shared helper ownership for callees, not BrowserPane itself.

Decision:

- Reject as direct owner. DialogPane is an inherited dependency.

### 4. BrowserDialog Ownership

Evidence for:

- BrowserDialog uses BrowserPane vtables in construction and derives from BrowserPane.
- Some currently adjacent methods are BrowserDialog-owned.

Evidence against:

- BrowserPane methods and vtables exist independently and are reused by BrowserDialog and WebBoard-derived classes.
- The raw constructor and BrowserPane command/key/timer slots install or reference BrowserPane-family vtables.

Decision:

- Reject for BrowserPane class. Keep `0x0046ad80` and BrowserDialog constructor/navigation on BrowserDialog.

### 5. WebBoardDialog / WebBoard Ownership

Evidence for:

- WebBoard and WebBoardOld vtables reuse BrowserPane command, schedule, cancel-timer, and key slots.

Evidence against:

- Reuse of a base virtual slot does not make the base source WebBoard-owned.
- WebBoard docs already place board-specific dialogs under [UID:0000P9] WebBoardDialog, not Browser.

Decision:

- Reject for BrowserPane ownership. WebBoard classes are BrowserPane consumers/derived classes.

## Open-Question Closure

- Raw constructor boundary: closed. Exact source-bearing half-open range is `0x0046a860-0x0046a89b`; padding is `0x0046a89b-0x0046a8a0`.
- Raw constructor source signature: still unresolved with concrete evidence. The body cleans two stack args but does not read them; no entry xref or pointer route is known. This blocks formal constructor C++.
- Raw constructor reachability: closed enough for documentation. Local PE scan confirms no absolute/RVA/rel32 pointer to `0x0046a860` and no absolute pointer into `0x0046a860-0x0046a898`.
- `0x0046a8a0` source role: best inference is BrowserPane destructor-family non-deleting cleanup. Exact EH/ordinary call classification remains a targeted blocker for formal destructor C++, but ownership is closed.
- `OnKeyEvent` naming: keep `BrowserPane::OnKeyEvent`; exact event field names remain unsafe. Document byte tests rather than inventing field names.
- `OnCommand` naming and behavior: closed. Use BrowserPane command override, Browser command constants, Browser alert constants, shared OK string, and inherited DialogPane activation.
- Timer/sound method naming: closed as stale. `0x00470fc0` is schedule; `0x004710d0` is cancel timer, not sound playback.
- `0x0046ad80` BrowserPane ownership: closed as rejected. It is BrowserDialog-owned.
- DialogPane helper ownership: closed. BrowserPane consumes inherited DialogPane and AlertPane helpers.
- Source placement: closed to high probability. Use Browser source root now; optional later split inside browser folder is not a blocker.
- First-draft C++: target class page should stay blank now. OnCommand is first-draft-ready after child split; OnKeyEvent is near-ready after event type; raw constructor and cleanup/destructor remain no-code.

## First-Draft C++ Recommendation / No-Code Proof

### Target Class Page [UID:000019]

Do not populate the [UID:000019] formal C++ block in the immediate implementation callback.

Target-specific no-code proof:

- The class page is a source-quality class summary, not an exact body page.
- The raw constructor-shaped body is proven class-owned but still has no modeled function at `0x0046a860`, no absolute/RVA/rel32 entry reference, no absolute pointer into its body, and two cleaned but unread stack parameters.
- Exact method body pages for the raw constructor, cleanup wrapper, key handler, command handler, and schedule wrapper are not yet split out from mixed aggregates. Emitting those method bodies on the class page would violate the rule that class pages should not contain method-body specifics.
- The existing exact child [UID:000217] uses stale `PlaySound` wording and should be corrected to `CancelTimer` before class declarations name that virtual slot.
- The multiple-inheritance/facet declaration syntax for the inherited `+0xa4` timer/event view is not final enough for a source-quality class declaration.
- Therefore the generated empty emitter marker is intentional until the method children and constructor signature are repaired.

### Method-Level Draft Guidance For Later Child Splits

`BrowserPane::OnCommand` is ready for a first-draft method body after an exact child split. Use accepted project names if they differ:

```cpp
bool BrowserPane::OnCommand(int commandId, int, int)
{
    const wchar_t *messageText = 0;

    switch (commandId) {
    case kBrowserCommandDispose:                // 0x42436470, "BCdp"
        messageText = kBrowserDisposeAlertText;
        break;
    case kBrowserCommandNavigationFailed:       // 0x4243666c, "BCfl"
        messageText = kBrowserNavigationFailedAlertText;
        break;
    case kBrowserCommandNavigationTimeout:      // 0x4243746f, "BCto"
        messageText = kBrowserNavigationTimeoutAlertText;
        break;
    case kBrowserCommandWebBoardRequestTimeout: // 0x00000572
        messageText = kBrowserWebBoardRequestTimeoutAlertText;
        break;
    default:
        return true;
    }

    new AlertPane(messageText, this, kDialogOkButtonString, 0);
    ActivatePendingControl();
    return true;
}
```

Notes for this draft:

- The method cleans three stack arguments, so keep placeholder extra parameters until the virtual signature is known.
- Use `AlertPane`/dialog helper names accepted by [UID:0001OD] and [UID:00012S].
- Do not emit raw `sub_` calls or generated pointer aliases.

`BrowserPane::OnKeyEvent` is near-ready but should not be emitted until the shared event type is known:

```cpp
bool BrowserPane::OnKeyEvent(InputEvent *event)
{
    if (event != 0 && event->byte_04 == 8 && event->byte_08 == 0x90)
        return true;

    return DialogPane::OnKeyEvent(event);
}
```

This is intentionally illustrative. Do not use `byte_04` / `byte_08` as final names. If no accepted event type exists, the child page should keep formal C++ blank and document the byte tests.

`BrowserPane::ScheduleTimer` and `BrowserPane::CancelTimer` are source-shaped forwarding methods. They can become thin wrappers after the TimerHandler public method names are accepted:

```cpp
void BrowserPane::ScheduleTimer(int eventId, int delay)
{
    m_timerHandler.ScheduleTimer(eventId, delay, 0, 0);
}

void BrowserPane::CancelTimer(int eventId)
{
    m_timerHandler.CancelTimer(eventId);
}
```

This is not ready for formal insertion until the inherited TimerHandler facet field/source spelling is accepted.

The raw constructor should not emit C++ now. A future draft must account for `ret 8` and the hardcoded `DialogPane` construction arguments:

```cpp
BrowserPane::BrowserPane(int unused0, int unused1)
    : DialogPane(/* word_60DB20 */, -1, 1)
{
}
```

This sketch is intentionally not recommended for formal insertion because `unused0`, `unused1`, and the `word_60DB20` operand are not source-quality names.

The scalar deleting destructor [UID:00033C] should never emit the compiler wrapper. Source reconstruction should declare a virtual destructor on the class or emit an ordinary destructor body only if an exact source destructor child is accepted.

## Implementation Checklist For Later Callback

### Target `by-class/BrowserPane.md`

Apply these changes if this report is accepted:

- Update metadata to `COMPLETION:87`, `CONFIDENCE:89`.
- Keep `CANONICAL_OWNER:0000HV`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000HV`.
- Keep formal C++ blank with the target-specific no-code proof above.
- Rewrite summary/source-placement to say BrowserPane is a Browser-module `DialogPane`-derived base for browser command/key/timer-facet behavior, not a generic UI-core class.
- Close the open source-placement question: current route is `NexusTK/browser/Browser.cpp`; separate `BrowserPane.cpp` remains possible but not proven or required.
- Correct the raw constructor method row:
  - no modeled IDA function at `0x0046a860`;
  - exact source-bearing half-open range `0x0046a860-0x0046a89b`;
  - `ret 8` at `0x0046a898-0x0046a89b`;
  - five bytes `0xcc` padding at `0x0046a89b-0x0046a8a0`;
  - pushes `1`, `-1`, and `0x0060db20` before calling `DialogPane::DialogPane`;
  - installs vtables at `+0x00`, `+0xa0`, and `+0xa4`;
  - local PE scan found no absolute/RVA/rel32 pointer to start and no absolute pointer into the body.
- Describe `0x0046a8a0` as BrowserPane destructor-family vtable reset/base cleanup, not generic cleanup.
- Keep `OnKeyEvent` but document exact byte tests and inherited DialogPane delegation.
- Keep `OnCommand` and document exact command ids, alert literal addresses, allocation size `0x270`, AlertPane constructor call, shared OK string, and DialogPane activation helper.
- Remove `0x0046ad80` from the BrowserPane direct-method list or explicitly mark it as BrowserDialog-owned.
- Replace the stale `PlaySound` method role with `CancelTimer` / `CancelTimerEvent` for `0x004710d0`; preserve `BrowserPanePlaySound` as historical/search wording only.
- Add `0x00470fc0` as `ScheduleTimer`, noting it currently needs an exact child split from [UID:00033M].
- Add a small "Historical/Stale Assumptions Corrected" section for:
  - raw constructor end previously written as `0x0046a898` or guessed as `0x0046a89a`;
  - `BrowserPanePlaySound` stale name;
  - `0x0046ad80` stale BrowserPane direct-method wording;
  - generated `g_pBrowserFileLoadText` / `g_pBrowserTimeoutText` pointer-global aliases.

### Support `by-file/Browser.md`

- Update BrowserPane row to say BrowserPane owns browser command/key and TimerHandler-facet schedule/cancel forwarding, not "timer/sound" behavior.
- Mention B012 2026-06-19 local PE reanalysis corrected the raw BrowserPane constructor range to `0x0046a860-0x0046a89b`.
- Note `0x004710d0` is the BrowserPane cancel-timer forwarder and the current `BrowserPanePlaySound` title is stale.
- Keep Browser file score unchanged unless the implementation also incorporates broader Browser-source cleanup. Current `86/88` is still reasonable.
- Keep source root `browser/Browser.cpp`; do not force `BrowserPane.cpp`.

### Support `by-class/BrowserDialog.md`

- Ensure `0x0046ad80-0x0046aea8` remains BrowserDialog-owned.
- Cross-link the BrowserPane report only as inherited-base support, not direct ownership transfer.
- Keep BrowserDialog source placement as Browser root or optional `BrowserDialog.cpp` within browser folder.

### Support [UID:0000Z5] `by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md`

- Update raw constructor range facts to `0x0046a860-0x0046a89b` plus padding `0x0046a89b-0x0046a8a0`.
- Correct the child inventory accordingly.
- Preserve that [UID:0000Z5] is mixed BrowserPane/BrowserDialog code and should not emit aggregate C++.
- If implementation scope allows split creation, create exact children for:
  - `0x0046a860-0x0046a89b.BrowserPaneRawConstructor`;
  - `0x0046a8a0-0x0046a8bf.BrowserPaneNonDeletingDestructorOrCleanup`;
  - `0x0046a8e0-0x0046a901.BrowserPaneOnKeyEvent`;
  - `0x0046a910-0x0046aa34.BrowserPaneOnCommand`;
  - plus BrowserDialog children from the B002 inventory if not already split.
- If exact children are not created, update [UID:0000Z5] prose at report-level detail and leave it as a reconstructable Browser-owned aggregate with blank C++.

### Support [UID:00033M] `by-memory/0x00470fc0-0x004710b8.BrowserOleAdjustorAndDelegationThunks.md`

- Split or at least explicitly stage `0x00470fc0-0x00470fdc` as `BrowserPane::ScheduleTimer`.
- Keep [UID:00033M] non-emitting/ignored because the rest is mixed Browser/BrowerControlPane/BrowserWindow OLE adjustor thunk material.

### Support [UID:000217] `by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md`

- Prefer rename to `0x004710d0-0x004710df.BrowserPaneCancelTimer.md`.
- If renaming is not done in the first implementation pass, update title/prose to "BrowserPane CancelTimer (historical BrowserPanePlaySound)".
- Update metadata recommendation to `COMPLETION:87`, `CONFIDENCE:91` if the stale-name correction and TimerHandler evidence are incorporated.
- Keep owner/emitter [UID:000019].
- Keep formal C++ blank unless TimerHandler method names and BrowserPane timer-facet field spelling are accepted.
- Document `sub_597610` as [UID:0001K9] `TimerHandler::CancelTimer` candidate, not SoundManager or sound playback.

### Support [UID:00033C] `by-memory/0x00470690-0x004706e5.BrowserPaneScalarDeletingDestructor.md`

- No score change required.
- Add a cross-note that source-level reconstruction belongs to BrowserPane destructor/class declaration, while `0x0046a8a0` is a separate destructor-family cleanup body and `0x00470690` is the scalar deleting wrapper.
- Keep formal C++ blank.

### Optional Support Docs Not Edited In This Pass

- `by-type/by-struct/DialogPaneLayout.md`: no direct edit required for this class pass. It already documents `+0xa0` and `+0xa4` inherited vtable views and the shared DialogPane fields. BrowserPane-specific documentation should link to it rather than over-generalizing BrowserPane fields into DialogPane layout.
- `by-class/TimerHandler.md` and TimerHandler wrapper pages: no direct edit required unless implementing the `BrowserPanePlaySound` correction wants a backlink. Current TimerHandler docs already establish `ScheduleTimer` and `CancelTimer` semantics.
- `by-memory/-coverage-report.md`: do not edit. Use supervisor-owned row text below.

## Exact Coverage / Report Text

### Preferred `by-class/-coverage-report.md` Replacement Row

```text
- [UID:000019][BrowserPane](by-class/BrowserPane.md) : reconstructable : 87% : strong : B012 2026-06-19 source-quality reanalysis keeps BrowserPane under the Browser source root [UID:0000HV] and resolves the class as a DialogPane-derived browser command/key/timer-facet base; local PE disassembly corrects the raw constructor-shaped body to exact half-open range 0x0046a860-0x0046a89b with ret 8 at 0x0046a898 and padding 0x0046a89b-0x0046a8a0, confirms no absolute/RVA/rel32 entry route or pointer into that raw body, preserves the BrowserPane vtable reset/base-cleanup wrapper at 0x0046a8a0, documents OnKeyEvent byte tests and OnCommand BCdp/BCfl/BCto/0x572 alert dispatch through Browser alert strings and shared DialogPane activation, corrects stale BrowserPanePlaySound wording to a TimerHandler-facet CancelTimer forwarder, keeps 0x0046ad80 BrowserDialog-owned, rejects Browser-private ownership for shared DialogPane helpers, and keeps formal class C++ blank until exact child splits and constructor signature are safe.
```

### Preferred [UID:0000Z5] `by-memory/-coverage-report.md` Replacement Row If Parent Is Updated But Not Split

```text
    - [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md) 0x0046a860-0x0046ad0a | mixed BrowserPane/BrowserDialog source cluster | BrowserPaneAndDialog : reconstructable : 85% : strong : B012 2026-06-19 BrowserPane class source-quality reanalysis keeps this Browser-routed mixed aggregate blank and corrects the BrowserPane raw constructor-shaped body to 0x0046a860-0x0046a89b with ret 8 at 0x0046a898 and padding at 0x0046a89b-0x0046a8a0; the aggregate still mixes BrowserPane constructor/cleanup/key/command methods with BrowserDialog NavigateToUrl and constructor bodies, so formal aggregate C++ remains blocked pending exact child splits and raw-constructor signature proof.
```

### Preferred [UID:000217] `by-memory/-coverage-report.md` Replacement Row If Renamed

```text
    - [UID:000217][0x004710d0-0x004710df.BrowserPaneCancelTimer](by-memory/0x004710d0-0x004710df.BrowserPaneCancelTimer.md) 0x004710d0-0x004710df | class method | BrowserPaneCancelTimer : reconstructable : 87% : strong : B012 2026-06-19 BrowserPane class source-quality reanalysis corrects stale BrowserPanePlaySound naming: local PE bytes and existing TimerHandler docs prove this exact BrowserPane-family vtable method adjusts ecx by +0xa4 and tail-jumps to [UID:0001K9] TimerHandler::CancelTimer at 0x00597610, with vtable refs at 0x00613350, 0x00613400, 0x00613640, and 0x006136f0; source C++ remains blank until the inherited TimerHandler facet field and public method spelling are accepted.
```

If the file is not renamed in the implementation pass, use the same text with the old link/title and an explicit phrase `BrowserPaneCancelTimer (historical BrowserPanePlaySound filename)`.

### New Exact Child Row Template For `0x00470fc0-0x00470fdc`

The UID cannot be exact until validator registration creates the child, so this is a template for supervisor application after split:

```text
      - [UID:NEW][0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer](by-memory/0x00470fc0-0x00470fdc.BrowserPaneScheduleTimer.md) 0x00470fc0-0x00470fdc | class method | BrowserPaneScheduleTimer : reconstructable : 87% : strong : B012 2026-06-19 BrowserPane class source-quality reanalysis splits the BrowserPane schedule forwarder out of the mixed OLE/thunk aggregate; local PE bytes prove it pushes zero payload fields, adjusts ecx by +0xa4, forwards event id and delay to [UID:0001K8] TimerHandler::ScheduleTimer at 0x005975e0, returns with ret 8, and is reached only through BrowserPane-family vtable slots at 0x0061334c, 0x006133fc, 0x0061363c, and 0x006136ec.
```

### [UID:00033M] Row Note If Schedule Child Is Split

Update the existing [UID:00033M] row only to say `0x00470fc0-0x00470fdc` has been split to the new BrowserPaneScheduleTimer child, while the remainder stays parent-blank and non-emitting as mixed ABI/delegation thunk inventory. Do not assign the whole aggregate to BrowserPane.

## Validator Results

> Executable block R002 was removed from this report and preserved verbatim in [000019-BrowserPane-class-source-quality-removed.md](000019-BrowserPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No scoped validator was run with `--apply` during this report-only pass.

## Changed Files

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\000019-BrowserPane-class-source-quality.md`

Modified:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\notes.md` should be updated to record this active BrowserPane assignment and report path.

Not edited:

- No `by-*` documentation files.
- No `by-memory/-coverage-report.md`.
- No generated files.

FINISHED

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/000019-BrowserPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"000019"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000019-BrowserPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/000019-BrowserPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000019"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
