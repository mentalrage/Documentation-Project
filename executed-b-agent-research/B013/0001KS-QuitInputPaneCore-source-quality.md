** TARGET-REPORT-UID:0001KS **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001KS QuitInputPaneCore Source-Quality Report

Agent: B013  
Assignment: `B013-goal2-quitinputpanecore-source-quality-0001KS-20260619`  
Status: FINISHED, report-only. No by-* documentation, generated files, IDA DB files, or `by-memory/-coverage-report.md` were edited.

## Target Paths

- Primary target: `source-3/project-documentation/by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0001KS-QuitInputPaneCore-source-quality.md`
- Canonical class owner: `source-3/project-documentation/by-class/QuitInputPane.md` [UID:0000BH]
- Source/file owner: `source-3/project-documentation/by-file/QuitDialogs.md` [UID:0000MX], source route `NexusTK/ui/dialogs/QuitDialogs.cpp`
- Related launcher: `source-3/project-documentation/by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md` [UID:0001KP]
- Singleton global: `source-3/project-documentation/by-global/g_pQuitInputPane.md`
- Destructor support:
  - `source-3/project-documentation/by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md`
  - `source-3/project-documentation/by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md`
- Vtable aggregate: `source-3/project-documentation/by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`

## Executive Recommendation

`0001KS` is not a single source function. It is an aggregate island containing:

- `0x005adcc0-0x005add18`: retained raw `QuitInputPane::QuitInputPane()` constructor body.
- `0x005add18-0x005add20`: eight bytes of `0xcc` padding.
- `0x005add20-0x005add8a`: vtable-only `QuitInputPane::OnConfirmInput()` virtual handler.

Recommended implementation path:

1. Split this aggregate into two exact reconstructable child pages:
   - `0x005adcc0-0x005add18.QuitInputPaneConstructor.md`
   - `0x005add20-0x005add8a.QuitInputPaneConfirmInput.md`
2. Convert `0001KS` to a non-emitting split index/container with `RECONSTRUCTABLE:FALSE`, blank formal C++, and `EMITTER_UIDS:` empty.
3. Put first-draft C++ on the exact children, not on the aggregate. The parent includes padding and two C++ member functions, so direct aggregate C++ would be less exact than child emission.
4. Keep canonical owner [UID:0000BH] `QuitInputPane` and file/emitter route [UID:0000MX] `QuitDialogs.cpp`.

If the supervisor chooses not to split immediately, the existing target can be raised from stale coverage text to current `85/87` documentation quality, but formal C++ should stay blank until the exact child pages exist.

## Evidence Checked

Documentation reviewed:

- Current target page `0x005adcc0-0x005add8a.QuitInputPaneCore.md`
- `by-class/QuitInputPane.md`
- `by-file/QuitDialogs.md`
- `by-global/g_pQuitInputPane.md`
- `by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md`
- `by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md`
- `by-global/OpenQuitPrompt_5A94B0.md`
- `by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md`
- `by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md`
- `by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md`
- `by-class/CharInputPane.md`
- `by-class/ConfirmInputPane.md`
- `by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md`
- `by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md`
- `by-memory/0x004f0350-0x004f03cb.LanguageManLookupAndSingletonHelpers.md`
- `by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- `by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md`
- `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`
- `by-global/g_activeMapPane.md`
- `by-global/g_pCollectionData.md`
- `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`
- `by-memory/-coverage-report.md` only for current row text; no edits made.

Binary evidence:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- SHA-256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
- PE image base: `0x00400000`
- Sections used for route scan:
  - `.text`: `0x00401000-0x0060c4ac`
  - `.rdata`: `0x0060d000-0x0066c0be`
  - `.data`: `0x0066d000-0x0069ce24`
  - `.rsrc`: `0x0069d000-0x006b2c38`
- Disassembly used Capstone 5.0.7 from a local Python PE-aware script.
- Validator dry run:
  - Command: `python source-3/project-documentation/tools/validator.py --mode file --file "source-3/project-documentation/by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md"`
  - Result: `ok: 1`; `0001KS by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md UID header exists`; dry run only, no `--apply`.

## Raw Bytes, Boundaries, And Padding

Confirmed exact aggregate range:

- Start: `0x005adcc0`
- End: `0x005add8a`
- Size: `0xca` bytes / 202 bytes

Child boundary evidence:

- `0x005adcc0-0x005add18` ends with plain `ret` at `0x005add17`.
- `0x005add18-0x005add20` is eight bytes of `0xcc` padding.
- `0x005add20-0x005add8a` starts with a normal function prologue and ends with plain `ret` at `0x005add89`.
- `0x005add8a-0x005add90` is post-function `0xcc` padding and belongs outside the current aggregate. It is already handled as ignored padding by surrounding coverage.

The existing target range therefore includes an internal alignment gap but correctly excludes the successor external padding. That is the main reason the parent should become a non-emitting split index after exact children are created.

## Disassembly Facts

### `0x005adcc0-0x005add18`: Raw Constructor Body

Disassembly:

```asm
005adcc0 push ebp
005adcc1 mov ebp, esp
005adcc3 push ecx
005adcc4 push esi
005adcc5 mov esi, ecx
005adcc7 mov ecx, dword ptr [0x0067a750]
005adccd push 3
005adccf mov dword ptr [ebp-4], esi
005adcd2 call 0x004f0350
005adcd7 push eax
005adcd8 mov ecx, esi
005adcda call 0x004f28a0
005adcdf lea eax, [esi+0x108]
005adce5 test eax, eax
005adce7 je 0x005adcf0
005adce9 add eax, -0x108
005adcee jmp 0x005adcf2
005adcf0 xor eax, eax
005adcf2 mov dword ptr [0x0069bf5c], eax
005adcf7 mov eax, esi
005adcf9 mov dword ptr [esi], 0x0062f054
005adcff mov dword ptr [esi+0xa0], 0x0062f0a4
005add09 mov dword ptr [esi+0xa4], 0x0062f0d4
005add13 pop esi
005add14 mov esp, ebp
005add16 pop ebp
005add17 ret
```

Resolved roles:

- `0x0067a750`: `g_pLanguageMan`
- pushed literal `3`: localized prompt id for the typed quit prompt.
- `0x004f0350`: best source-facing role `LanguageMan::GetLocalizedString(int)` or equivalent singleton lookup wrapper.
- `0x004f28a0`: `CharInputPane::CharInputPane(const wchar_t *prompt)`.
- `0x0069bf5c`: `g_pQuitInputPane`.
- `0x0062f054`, `0x0062f0a4`, `0x0062f0d4`: `QuitInputPane` primary/secondary/tertiary vftables.

The `lea eax, [esi+0x108]` / `add eax, -0x108` sequence is an adjustment artifact. For non-null `this`, it computes the original `this` and publishes it to `g_pQuitInputPane`. Since `this+0x108` cannot be null for a real object pointer in normal C++, the source should be treated as:

```cpp
g_pQuitInputPane = this;
```

The vtable stores are compiler-generated constructor stores, not source statements.

### `0x005add20-0x005add8a`: Confirmation Handler

Disassembly:

```asm
005add20 push ebp
005add21 mov ebp, esp
005add23 push ecx
005add24 push esi
005add25 mov esi, ecx
005add27 call 0x004f2310
005add2c cmp ax, 1
005add30 jne 0x005add85
005add32 push 1
005add34 lea eax, [ebp-4]
005add37 mov ecx, esi
005add39 push eax
005add3a call 0x004f2300
005add3f mov eax, dword ptr [ebp-4]
005add42 cmp ax, 0x79
005add46 je 0x005add5a
005add48 cmp ax, 0x59
005add4c je 0x005add5a
005add4e mov ecx, esi
005add50 call 0x00544690
005add55 pop esi
005add56 mov esp, ebp
005add58 pop ebp
005add59 ret
005add5a mov ecx, dword ptr [0x0067a748]
005add60 lea eax, [ecx+0xa4]
005add66 neg ecx
005add68 sbb ecx, ecx
005add6a and ecx, eax
005add6c push ecx
005add6d mov ecx, dword ptr [0x0067ab80]
005add73 call 0x00597a10
005add78 mov ecx, dword ptr [0x0067a764]
005add7e push 1
005add80 call 0x005047f0
005add85 pop esi
005add86 mov esp, ebp
005add88 pop ebp
005add89 ret
```

Resolved roles:

- `0x004f2310`: `LineInputPane::GetTextLength()`, returns a 16-bit length observed via `cmp ax, 1`.
- `0x004f2300`: `LineInputPane::CopyText(wchar_t *out, int count)`.
- stack local at `[ebp-4]`: one UTF-16 character buffer for the copied answer.
- `0x00544690`: `Pane::MarkForDeletion()`.
- `0x0067a748`: documented canonical name `g_pCollectionData`; behavior here is local-player/UserPane state pointer.
- field `+0xa4` from that pointer: timer handler/owner subobject passed to timer manager removal.
- `0x0067ab80`: `g_pTimerMgr`.
- `0x00597a10`: `TimerMgr::RemovePendingTimersForOwner(TimerHandler *owner)` or equivalent direct core helper.
- `0x0067a764`: `g_activeMapPane`.
- `0x005047f0`: `MapPane::ExitToMenu(bool notifyServer)`, with `true`.

Behavior:

- If the current text length is not exactly `1`, return and keep the pane alive.
- Copy one UTF-16 character from the line input.
- If the character is neither `L'y'` nor `L'Y'`, mark this pane for deletion and return.
- If the character is `L'y'` or `L'Y'`, remove pending timers for the local-player/UserPane timer owner when available, then request main-menu teardown through `g_activeMapPane->ExitToMenu(true)`.

The `neg` / `sbb` / `and` sequence computes:

```cpp
TimerHandler *timerOwner = g_pCollectionData != NULL ? &g_pCollectionData->m_timerHandler : NULL;
```

The exact source-facing type name for `g_pCollectionData` is not fully settled by this target alone. Existing docs call the global `g_pCollectionData`; cross-references show it is broader local-player/UserPane state. The support-doc update should preserve the canonical name while noting this handler specifically uses its `+0xa4` timer owner subobject.

## Route And Xref Reanalysis

PE-aware route scans were performed across `.text`, `.rdata`, `.data`, and `.rsrc` for rel32 call/jump targets, absolute VA dwords, and RVA dwords.

Findings:

- `0x005adcc0` has no direct rel32 call/jump xref, no absolute VA dword xref, and no RVA dword xref.
- `0x005add20` has no direct rel32 call/jump xref and no RVA dword xref. It has one absolute VA dword xref in `.rdata` at `0x0062f09c`, the primary `QuitInputPane` vtable slot.
- `0x005add18` and `0x005add8a` have no rel32/VA/RVA route hits; both are boundaries/padding-adjacent, not live function targets.
- `0x0069bf5c` (`g_pQuitInputPane`) absolute VA hits in `.text` are:
  - `0x005a954f`: launcher duplicate guard.
  - `0x005a9598`: launcher publish.
  - `0x005a95a0`: launcher fallback clear.
  - `0x005adcf3`: raw constructor publish.
  - `0x005b7b38`: scalar deleting destructor clear.
- `0x0062f054` vtable literal hits:
  - `0x005a95aa`: launcher inlined construction path.
  - `0x005adcfb`: raw constructor body.
- `0x0062f0a4` vtable literal hits:
  - `0x005a95b4`: launcher inlined construction path.
  - `0x005add05`: raw constructor body.
- `0x0062f0d4` vtable literal hits:
  - `0x005a95be`: launcher inlined construction path.
  - `0x005add0f`: raw constructor body.

Positive controls:

- The modeled launcher at `0x005a94b0-0x005a95d2` contains a live direct route from the UserPane key path and duplicates the same typed-quit construction sequence: allocate `0x108`, localize id `3`, call `CharInputPane`, publish `g_pQuitInputPane`, and install the same three `QuitInputPane` vtables.
- The UserPane key case for quit calls `OpenQuitPrompt_5A94B0` from `0x005a5cc8`.
- The destructor and scalar deleting destructor are vtable-routed and clear `g_pQuitInputPane`, confirming class/singleton ownership.

Conclusion:

- The constructor body is no-route raw code from the static route perspective, but it is not an unknown helper. It is best interpreted as a retained out-of-line `QuitInputPane::QuitInputPane()` body whose construction sequence was duplicated/inlined in the live launcher.
- The handler is live through the primary `QuitInputPane` vtable and should be treated as a normal virtual method even though there are no direct static call xrefs.

## Vtable And Singleton Evidence

Confirmed `QuitInputPane` vtable slice:

- Primary vtable start: `0x0062f054`
  - slot `0x0062f054`: `0x005b7b30`, scalar deleting destructor.
  - slot `0x0062f09c`: `0x005add20`, target confirmation handler.
- Secondary vtable start: `0x0062f0a4`
  - slot `0x0062f0a4`: `0x005b7836`, destructor thunk.
  - slot `0x0062f0ac`: `0x004f2920`, inherited `CharInputPane` input/key behavior.
- Tertiary vtable start: `0x0062f0d4`
  - slot `0x0062f0d4`: `0x005b7841`, destructor thunk.

Recommended source-facing names:

- `0x0062f054`: `QuitInputPane::vftable`
- `0x0062f0a4`: `QuitInputPane::vftable_Secondary` or class-layout-specific secondary base vtable name, if the project has a better base-interface convention.
- `0x0062f0d4`: `QuitInputPane::vftable_Tertiary` or class-layout-specific tertiary base vtable name.
- `0x0069bf5c`: `g_pQuitInputPane`, type `QuitInputPane *`.

The target constructor and launcher both install all three vtable pointers at offsets `+0x0`, `+0xa0`, and `+0xa4`. These are compiler vtable stores for multiple inheritance or secondary interface base subobjects, not source-authored assignments.

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Status

Best-supported conclusion: `0x005adcc0-0x005add18` is `QuitInputPane::QuitInputPane()`.

Evidence:

- The body uses `ecx` as `this`, preserves it in `esi`, and calls the base constructor `CharInputPane::CharInputPane(prompt)`.
- The prompt is obtained from `g_pLanguageMan` with resource id `3`, matching the launcher and `QuitInputPane` class docs.
- The body publishes the singleton `g_pQuitInputPane`.
- It installs the three `QuitInputPane` vtable pointers also used by the live launcher.
- It has no parameters and returns with a plain `ret`, matching a `__thiscall` constructor.

Rejected alternatives:

- Standalone factory helper: rejected because the function does not allocate and assumes `ecx` is already the object pointer.
- Inlined launcher fragment: rejected for this exact address because it is a separately delimited function-shaped body ending in `ret`. The launcher contains a separate duplicated construction sequence elsewhere.
- Base `CharInputPane` constructor: rejected because it calls `CharInputPane::CharInputPane` and then installs `QuitInputPane` vtables/singleton state.

Remaining uncertainty:

- Static route/liveness for the raw constructor is not proven by a direct call, pointer table, or RVA table. This should be kept as a confidence caveat, not a naming blocker.

### Localized Prompt Id `3`

Best-supported conclusion: prompt id `3` is the typed quit confirmation prompt passed to the `CharInputPane` base.

Evidence:

- Constructor body pushes literal `3` into `LanguageMan::GetLocalizedString`.
- Launcher duplicates the same literal `3` before constructing the typed quit pane.
- `QuitInputPane` is a typed one-character prompt. The handler accepts `Y/y`, aligning with a localized quit prompt such as a yes/no quit confirmation.

Rejected alternatives:

- Runtime mode flag: rejected because the literal is passed to the localization helper, not stored in object state.
- Packet/opcode id: rejected because there is no encoder/packet construction in this range.

### Confirmation Handler Signature

Recommended signature:

```cpp
void QuitInputPane::OnConfirmInput();
```

Acceptable alternate if class naming conventions prefer inherited virtual wording:

```cpp
void QuitInputPane::OnEnterKey();
```

Evidence:

- It is installed as the primary vtable slot at `0x0062f09c`.
- It takes only `this` in `ecx`, no stack arguments, and returns `void`.
- It reads the current line-input text and performs submit/confirm behavior.
- `ConfirmInputPane` docs identify the analogous slot as an enter/confirmation action; the behavior here is not a general raw key event.

Rejected names:

- `OnKeyEvent`: rejected because this target receives no key-code argument and inherited key handling is in another vtable slot.
- `Quit`: rejected because one-character non-yes input deletes only this pane, while yes input performs timer cleanup and map exit. The method is the submit/confirm handler, not the full quit operation.
- `OnCancel`: rejected because the method also performs affirmative quit on `Y/y`.

### Timer Helper Name

Recommended source-facing call:

```cpp
g_pTimerMgr->RemovePendingTimersForOwner(timerOwner);
```

Evidence:

- Target directly loads `g_pTimerMgr` from `0x0067ab80`, pushes a computed owner pointer, and calls `0x00597a10`.
- `TimerHandlerScheduleRemoveWrappers.md` documents `0x00597600` as a wrapper that forwards `this` through `g_pTimerMgr` into `0x00597a10`.
- The broader TimerMgr page places `0x00597a10` in the removal-helper region.

Rejected source shape:

- `timerOwner->RemovePendingTimers()`: rejected for this target because it does not call the wrapper at `0x00597600`; it calls the manager helper directly.
- `delete timerOwner`: rejected because the helper is in timer queue removal code and there is no destructor/free path here.

### Main-Menu Helper Name

Recommended source-facing call:

```cpp
g_activeMapPane->ExitToMenu(true);
```

Evidence:

- Target loads `g_activeMapPane` from `0x0067a764`, pushes literal `1`, and calls `0x005047f0`.
- `MapPaneExitToMenuTeardown.md` resolves `0x005047f0` as `MapPane::ExitToMenu(bool notifyServer)`, where the boolean controls optional logout packet behavior.
- The quit confirmation path should notify the server; passing `true` is consistent with the resolved `MapPane` behavior.

Rejected names:

- `ReturnToLogin`: too broad and not consistent with the resolved `MapPane::ExitToMenu` support doc.
- `CloseMapPane`: too narrow; the callee performs teardown and optional logout notification.

### Field Names Around `g_pCollectionData + 0xa4`

Best-supported local name:

```cpp
TimerHandler *timerOwner = g_pCollectionData != NULL ? &g_pCollectionData->m_timerHandler : NULL;
```

Evidence:

- The handler computes `ptr + 0xa4` only when `ptr` is non-null.
- That computed pointer is passed as the owner to the TimerMgr remove helper.
- Existing global docs caution that `g_pCollectionData` is broader than its name and is tied to local-player/UserPane state.

Recommended documentation wording:

- Use existing canonical global name `g_pCollectionData` for now.
- Describe `+0xa4` as a local-player/UserPane `TimerHandler` owner subobject.
- Do not force a final global rename from this target alone.

Rejected alternatives:

- Collection-specific data field: rejected because the field is used for timer ownership in a quit-to-menu path, and the global has broad UserPane/local-player xrefs.
- Direct `TimerHandler *g_pCollectionData`: rejected because the code adds `0xa4` before passing the owner.

### Singleton And Vtable Names

Best-supported names:

- `g_pQuitInputPane` for `0x0069bf5c`.
- `QuitInputPane::vftable` for `0x0062f054`.
- Secondary and tertiary `QuitInputPane` vtable names for `0x0062f0a4` and `0x0062f0d4`.

Evidence:

- The launcher, raw constructor, destructor, and global docs consistently use this singleton for the typed quit prompt.
- The vtable pointers are installed after the `CharInputPane` base constructor and point back to `QuitInputPane` destructor/handler entries.

### Source Placement

Best-supported route:

- Class owner: `QuitInputPane` [UID:0000BH].
- File/source owner: `QuitDialogs.cpp` [UID:0000MX].

Rejected owners:

- `CharInputPane`/`InputPanes`: rejected because they are base/helper dependencies. The target installs `QuitInputPane` vtables and singleton state.
- `UserPane`: rejected because it only reaches the launcher via a quit key case.
- `MapPane`: rejected because it is only the affirmative teardown callee.
- `TimerMgr`: rejected because it is only the timer cleanup callee.
- `g_pQuitInputPane` global page: rejected as source owner because it documents singleton storage only, not the methods.

### Generated Name Cleanup

No compiler/generated names need to remain as blockers:

- `sub_5ADCC0` should be replaced in docs/IDA comments by `QuitInputPane::QuitInputPane`.
- `sub_5ADD20` should be replaced by `QuitInputPane::OnConfirmInput` or, if project convention requires, `QuitInputPane::OnEnterKey`.
- `sub_4F0350` should be described as `LanguageMan::GetLocalizedString`.
- `sub_4F28A0` should be `CharInputPane::CharInputPane`.
- `sub_4F2310` should be `LineInputPane::GetTextLength`.
- `sub_4F2300` should be `LineInputPane::CopyText`.
- `sub_544690` should be `Pane::MarkForDeletion`.
- `sub_597A10` should be `TimerMgr::RemovePendingTimersForOwner`.
- `sub_5047F0` should be `MapPane::ExitToMenu`.

The only remaining source-quality uncertainty is the final C++ type name for the `g_pCollectionData` object and its `+0xa4` timer field. The behavior and role are strong enough for first-draft C++ with a documented placeholder field name.

## First-Draft C++ Readiness

The exact children are C++ ready. The current aggregate parent should not emit C++ directly.

### Child Draft: `QuitInputPane::QuitInputPane()`

Preferred source-style draft:

```cpp
QuitInputPane::QuitInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(3))
{
    g_pQuitInputPane = this;
}
```

If the project source style uses a global/localization wrapper instead of a direct singleton method:

```cpp
QuitInputPane::QuitInputPane()
    : CharInputPane(GetLocalizedString(3))
{
    g_pQuitInputPane = this;
}
```

Do not include compiler vtable stores in C++.

### Child Draft: `QuitInputPane::OnConfirmInput()`

Preferred readable draft:

```cpp
void QuitInputPane::OnConfirmInput()
{
    if (GetTextLength() != 1)
        return;

    wchar_t answer = 0;
    CopyText(&answer, 1);

    if (answer != L'y' && answer != L'Y')
    {
        MarkForDeletion();
        return;
    }

    TimerHandler *timerOwner = NULL;
    if (g_pCollectionData != NULL)
        timerOwner = &g_pCollectionData->m_timerHandler;

    g_pTimerMgr->RemovePendingTimersForOwner(timerOwner);
    g_activeMapPane->ExitToMenu(true);
}
```

More conservative draft if the `g_pCollectionData` type is not yet declared:

```cpp
void QuitInputPane::OnConfirmInput()
{
    if (GetTextLength() != 1)
        return;

    wchar_t answer = 0;
    CopyText(&answer, 1);

    if (answer != L'y' && answer != L'Y')
    {
        MarkForDeletion();
        return;
    }

    TimerHandler *timerOwner = NULL;
    if (g_pCollectionData != NULL)
        timerOwner = reinterpret_cast<TimerHandler *>(reinterpret_cast<unsigned char *>(g_pCollectionData) + 0xa4);

    g_pTimerMgr->RemovePendingTimersForOwner(timerOwner);
    g_activeMapPane->ExitToMenu(true);
}
```

The first version is better source-style C++. The second version is safer if the implementation pass cannot yet introduce or reference the local-player/UserPane state layout.

### Parent No-Code Proof

`0001KS` should not emit formal C++ after split because:

- It contains two distinct source member functions.
- It contains internal `0xcc` alignment padding from `0x005add18-0x005add20`.
- Exact child pages can own both C++ bodies without crossing range boundaries.
- Parent C++ would either include two unrelated method bodies in one by-memory item or omit one method, both of which would be inferior to exact child emission.

Recommended parent metadata after split:

- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- formal C++ blank
- `COMPLETION:88`
- `CONFIDENCE:90`
- keep `CANONICAL_OWNER:0000BH`

Recommended child metadata:

- Constructor child:
  - `COMPLETION:86`
  - `CONFIDENCE:88`
  - `RECONSTRUCTABLE:TRUE`
  - `CANONICAL_OWNER:0000BH`
  - `EMITTER_UIDS:0000BH` or file emitter route through `0000MX`, depending on current validator convention for class children.
- Confirm handler child:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `RECONSTRUCTABLE:TRUE`
  - `CANONICAL_OWNER:0000BH`
  - `EMITTER_UIDS:0000BH` or file emitter route through `0000MX`, depending on current validator convention for class children.

If no split is applied immediately, keep `0001KS` as `RECONSTRUCTABLE:TRUE` but leave formal C++ blank with explicit child-split blocker text. The score can remain `85/87`; do not cite stale `90/90+` gate language.

## Recommended Target And Support Doc Changes

### `by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md`

Recommended exact content changes for the current parent:

- Replace stale no-code rationale about the old `90/90+` gate with the active gate/correct split rationale:
  - The item is above the active `85/85` gate by score, but it is an aggregate containing two source functions and internal padding. C++ should move to exact child pages.
- Add/retain `[[CHILDREN]]` pointing to the two future exact pages once created.
- Update behavior narrative:
  - `0x005adcc0-0x005add18`: retained out-of-line `QuitInputPane::QuitInputPane()` constructor; no direct route; duplicates launcher construction shape; localizes prompt id `3`; calls `CharInputPane`; publishes `g_pQuitInputPane`; compiler installs three `QuitInputPane` vtables.
  - `0x005add18-0x005add20`: eight bytes `0xcc`.
  - `0x005add20-0x005add8a`: vtable-only `QuitInputPane::OnConfirmInput()`; text length must be `1`; accepts `Y/y`; one-character non-confirming answer calls `Pane::MarkForDeletion`; `Y/y` removes pending timers for local-player/UserPane timer owner at `g_pCollectionData + 0xa4` and calls `MapPane::ExitToMenu(true)`.
- Update route notes:
  - constructor has no rel32/VA/RVA route, but has strong class/source evidence.
  - handler is routed through primary vtable slot `0x0062f09c`.
- Add rejected alternatives:
  - constructor is not a factory, not a base constructor, and not owned by `UserPane`.
  - handler is not a raw key event method and not a timer or map helper.
- Recommended metadata after split:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank

### New child `by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md`

Implementation checklist:

- Create exact by-memory page for range `0x005adcc0-0x005add18`.
- Assign validator UID.
- Metadata:
  - `CANONICAL_OWNER:0000BH`
  - `COMPLETION:86`
  - `CONFIDENCE:88`
  - `RECONSTRUCTABLE:TRUE`
  - emitter route to `QuitInputPane` / `QuitDialogs.cpp`.
- Include first-draft C++ constructor shown above.
- Evidence text must mention:
  - no static route found for start address;
  - constructor-shaped `thiscall` body;
  - prompt id `3`;
  - `LanguageMan::GetLocalizedString`;
  - `CharInputPane::CharInputPane`;
  - `g_pQuitInputPane = this`;
  - vtable writes as compiler-generated.

### New child `by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md`

Implementation checklist:

- Create exact by-memory page for range `0x005add20-0x005add8a`.
- Assign validator UID.
- Metadata:
  - `CANONICAL_OWNER:0000BH`
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `RECONSTRUCTABLE:TRUE`
  - emitter route to `QuitInputPane` / `QuitDialogs.cpp`.
- Include first-draft C++ handler shown above.
- Evidence text must mention:
  - vtable-only route at `0x0062f09c`;
  - no direct rel32 route required for virtual method;
  - `GetTextLength() == 1` guard;
  - `CopyText(&answer, 1)`;
  - accepts `L'y'` and `L'Y'`;
  - non-yes single character calls `Pane::MarkForDeletion()`;
  - yes path removes timers through `g_pTimerMgr->RemovePendingTimersForOwner(timerOwner)`;
  - yes path calls `g_activeMapPane->ExitToMenu(true)`.

### `by-class/QuitInputPane.md`

Recommended updates:

- Method map should name:
  - `0x005adcc0-0x005add18`: `QuitInputPane::QuitInputPane()`
  - `0x005add20-0x005add8a`: `QuitInputPane::OnConfirmInput()`; note acceptable source-convention alias `OnEnterKey`.
- Replace stale blank-C++ rationale with:
  - class C++ is ready through exact method children; broad aggregate `0001KS` should not emit after split.
- Add field/source notes:
  - `g_pQuitInputPane` is published by constructor and cleared by scalar deleting destructor.
  - prompt id `3` is the localized typed-quit prompt.
  - inherited line input helpers provide `GetTextLength` and `CopyText`.
- Add behavior notes:
  - length not `1`: no-op return.
  - one-character not `Y/y`: mark pane for deletion.
  - `Y/y`: remove local-player/UserPane timer owner and exit to menu with server notification.

### `by-file/QuitDialogs.md`

Recommended updates:

- Add or refine `QuitInputPane` method inventory:
  - constructor child range and handler child range.
  - launcher range remains a separate helper that duplicates the typed-construction sequence in its fallback branch.
- Clarify source placement:
  - `QuitInputPane` belongs to `NexusTK/ui/dialogs/QuitDialogs.cpp`.
  - `OpenQuitPrompt_5A94B0` creates modern `QuitDialog` or legacy typed `QuitInputPane` depending on the EPF/modern UI flag.
- Add the active source-quality decision:
  - exact child pages should emit constructor/handler C++; parent aggregate should not.

### `by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md` and `by-global/OpenQuitPrompt_5A94B0.md`

Recommended updates:

- Note that the typed branch inlines or duplicates the same construction sequence as retained raw constructor `0x005adcc0-0x005add18`.
- Keep `OpenQuitPrompt_5A94B0` as launcher/factory helper, not as owner of the constructor body.
- Clarify that the raw constructor start has no direct route, while the launcher branch is live through UserPane key handling.

### `by-global/g_pQuitInputPane.md` and memory global page

Recommended updates:

- Add xref evidence:
  - `0x005a954f`, `0x005a9598`, `0x005a95a0`, `0x005adcf3`, `0x005b7b38`.
- Clarify lifecycle:
  - set by launcher fallback or retained constructor;
  - cleared by launcher fallback failure and scalar deleting destructor.

### `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`

Recommended updates:

- Add exact early `QuitInputPane` vtable details:
  - primary vtable at `0x0062f054`, destructor `0x005b7b30`, handler slot `0x0062f09c -> 0x005add20`.
  - secondary vtable at `0x0062f0a4`, destructor thunk `0x005b7836`, inherited CharInputPane input/key slot `0x004f2920`.
  - tertiary vtable at `0x0062f0d4`, destructor thunk `0x005b7841`.
- Note that exact child pages, not the vtable aggregate, should own handler C++.

### Timer/Map/Global Support Docs

Recommended support-doc updates:

- `TimerHandlerScheduleRemoveWrappers.md` / `TimerMgrAndTimerQueue.md`:
  - Add `0x005add73` as a caller/evidence site for direct manager removal by owner.
  - Preferred helper name: `TimerMgr::RemovePendingTimersForOwner`.
- `MapPaneExitToMenuTeardown.md`:
  - Add `0x005add80` as a quit-confirmation caller with `notifyServer=true`.
- `g_pCollectionData.md`:
  - Add evidence that quit confirmation treats `g_pCollectionData + 0xa4` as a `TimerHandler` owner subobject.
  - Preserve caveat that the global's final source name/type is broader than collection-only.

## Score And Metadata Recommendation

Current target metadata is already above the active `85/85` gate:

- Current: `COMPLETION:85`, `CONFIDENCE:87`, `RECONSTRUCTABLE:TRUE`, owner `0000BH`, emitter `0000BH`.

Recommended after child split:

- Parent `0001KS`:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - `RECONSTRUCTABLE:FALSE`
  - `EMITTER_UIDS:` blank
  - Reason: fully understood aggregate/split index; no direct C++ emission because exact children cover source functions.
- Constructor child:
  - `COMPLETION:86`
  - `CONFIDENCE:88`
  - `RECONSTRUCTABLE:TRUE`
  - Reason: source body is clear, but no direct route keeps confidence below handler.
- Handler child:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `RECONSTRUCTABLE:TRUE`
  - Reason: exact vtable route, complete behavior, and helper names resolved; minor residual uncertainty only in the final source type name of `g_pCollectionData + 0xa4`.

No score cap below the C++ gate is justified for the handler. The parent's no-code state is due to aggregate policy, not missing behavior.

## Exact Coverage Row Text

Current stale row in `by-memory/-coverage-report.md` says `78%` and references outdated alignment/handler wording. Do not edit this file during report-only work.

If supervisor wants an immediate no-split replacement before child pages are created, replace the current `0001KS` row with this exact row:

```md
    - [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md) 0x005adcc0-0x005add8a | class method island | QuitInputPaneCore : reconstructable : 85% : strong : Raw typed-quit constructor and modeled `QuitInputPane::OnConfirmInput()` handler; B013 source-quality pass confirms the exact `0xca`/202-byte aggregate, raw constructor `0x005adcc0-0x005add18`, eight-byte internal padding, vtable-only handler `0x005add20-0x005add8a`, prompt id `3`, `g_pQuitInputPane` publish, `QuitInputPane` vtable stores at `0x0062f054/0x0062f0a4/0x0062f0d4`, handler slot `0x0062f09c`, `Y/y` confirmation behavior, `Pane::MarkForDeletion` rejection path, `TimerMgr` removal for local-player/UserPane timer owner `g_pCollectionData + 0xa4`, and `MapPane::ExitToMenu(true)`; formal C++ should remain blank until exact constructor/handler child split is applied.
```

Preferred replacement for the parent after child split:

```md
    - [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md) 0x005adcc0-0x005add8a | non-emitting split index | QuitInputPaneCore : ignored/non-emitting : 88% : very strong : B013 source-quality pass resolves the aggregate as a two-method `QuitInputPane` island under `QuitDialogs.cpp`: exact child `0x005adcc0-0x005add18` is the retained raw `QuitInputPane::QuitInputPane()` constructor body using localized prompt id `3`, `CharInputPane`, `g_pQuitInputPane`, and compiler vtable stores, while exact child `0x005add20-0x005add8a` is the primary-vtable `QuitInputPane::OnConfirmInput()` handler that accepts one-character `Y/y`, rejects one-character non-confirmation with `Pane::MarkForDeletion`, removes pending timers for the local-player/UserPane timer owner at `g_pCollectionData + 0xa4`, and calls `MapPane::ExitToMenu(true)`; the parent includes eight-byte internal `0xcc` padding and should not emit C++ directly.
```

Child coverage rows to add after validator assigns UIDs. Replace `<new-ctor-uid>` and `<new-handler-uid>` with actual UIDs assigned during implementation:

```md
    - [UID:<new-ctor-uid>][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) 0x005adcc0-0x005add18 | raw constructor | QuitInputPane::QuitInputPane : reconstructable : 86% : strong : Retained no-direct-route `QuitInputPane` constructor body; obtains localized prompt id `3` through `LanguageMan::GetLocalizedString`, calls `CharInputPane::CharInputPane`, publishes `g_pQuitInputPane = this`, and installs compiler-generated `QuitInputPane` vtables at `0x0062f054/0x0062f0a4/0x0062f0d4`; first-draft constructor C++ is ready with route caveat noted.
    - [UID:<new-handler-uid>][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) 0x005add20-0x005add8a | virtual method | QuitInputPane::OnConfirmInput : reconstructable : 88% : very strong : Primary-vtable quit confirmation handler at slot `0x0062f09c`; requires one-character input, copies the UTF-16 answer, accepts `Y/y`, marks the pane for deletion on one-character non-confirmation, removes pending timers for the local-player/UserPane timer owner at `g_pCollectionData + 0xa4`, and calls `MapPane::ExitToMenu(true)`; first-draft handler C++ is ready.
```

The child rows are intentionally not exact final replacement rows until UIDs exist, but the row text after the UID fields is ready for supervisor-owned application.

## Validation Commands Needed After Implementation

Before any implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0001KS-QuitInputPaneCore-source-quality-removed.md](0001KS-QuitInputPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

After creating/splitting child pages and updating support docs:

> Executable block R002 was removed from this report and preserved verbatim in [0001KS-QuitInputPaneCore-source-quality-removed.md](0001KS-QuitInputPaneCore-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation result:

- No UID/header errors.
- Parent no longer reports as an emitter with blank C++ after metadata changes.
- Child pages should be recognized as reconstructable and routable to `QuitInputPane` / `QuitDialogs.cpp`.
- Auto-generated `QuitDialogs.cpp` should gain the child C++ bodies only after child metadata and formal C++ are applied.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Create or rename function at `0x005adcc0` to `QuitInputPane__QuitInputPane` / `QuitInputPane::QuitInputPane`.
- Rename function at `0x005add20` to `QuitInputPane__OnConfirmInput` / `QuitInputPane::OnConfirmInput`.
- Name global `0x0069bf5c` as `g_pQuitInputPane`, type `QuitInputPane *`.
- Name vtable starts:
  - `0x0062f054`: `QuitInputPane::vftable`
  - `0x0062f0a4`: `QuitInputPane::vftable_Secondary`
  - `0x0062f0d4`: `QuitInputPane::vftable_Tertiary`
- Add comment at `0x005adccd`: `localized typed-quit prompt id 3`.
- Add comment at `0x005adcf2`: `g_pQuitInputPane = this; adjustment sequence is compiler artifact`.
- Add comment at `0x005add42`: `accept lowercase y`.
- Add comment at `0x005add48`: `accept uppercase Y`.
- Add comment at `0x005add60`: `compute local-player/UserPane timer owner at +0xa4 when g_pCollectionData is non-null`.
- Add comment at `0x005add73`: `TimerMgr::RemovePendingTimersForOwner(timerOwner)`.
- Add comment at `0x005add80`: `g_activeMapPane->ExitToMenu(true)`.

Medium confidence:

- Type the `g_pCollectionData + 0xa4` field as a `TimerHandler` subobject named `m_timerHandler` or `m_playerTimerHandler`. The role is strong, but final containing type/global name should be validated against broader UserPane/local-player state work before hardening.
- If project naming convention follows `ConfirmInputPane`, use `QuitInputPane::OnEnterKey` as the IDA function name and document `OnConfirmInput` as semantic alias. Otherwise use `OnConfirmInput`.

Rejected IDA/type changes:

- Do not rename `0x005adcc0` as a launcher/factory. It does not allocate and is a constructor body.
- Do not type `0x005add20` as a key-event method with a key-code argument. It takes only `this`.
- Do not assign source ownership to `MapPane` or `TimerMgr`.

## Open Questions Closed Or Remaining

Closed:

- Raw constructor status: constructor body, not unknown helper.
- Prompt id `3`: localized typed quit prompt.
- Handler signature: `void __thiscall QuitInputPane::OnConfirmInput()` / source `void QuitInputPane::OnConfirmInput()`.
- Main-menu helper: `MapPane::ExitToMenu(true)`.
- Timer helper: direct `TimerMgr::RemovePendingTimersForOwner`.
- Singleton: `g_pQuitInputPane`.
- Owner/source: `QuitInputPane` in `QuitDialogs.cpp`.
- First-draft C++: ready for exact children.
- Parent emission: should become non-emitting split index.

Remaining:

- Final source name of the broad object behind `g_pCollectionData` and its `+0xa4` timer field. This target proves the field role but not the best final containing type name. The implementation can use either a provisional typed field `m_timerHandler` or a conservative byte-offset cast in first-draft C++ until the broader global/type doc is updated.

## Implementation Callback Checklist

If supervisor accepts this report, a same-agent implementation callback should request:

1. Create the constructor child page `0x005adcc0-0x005add18.QuitInputPaneConstructor.md` with validator-assigned UID, metadata, evidence, and first-draft constructor C++.
2. Create the handler child page `0x005add20-0x005add8a.QuitInputPaneConfirmInput.md` with validator-assigned UID, metadata, evidence, and first-draft handler C++.
3. Update parent `0001KS` as a non-emitting split index with `[[CHILDREN]]`, child links, no formal C++, and the no-code proof above.
4. Update `QuitInputPane.md` method map and class behavior/source-shape notes.
5. Update `QuitDialogs.md` source/file inventory.
6. Update `g_pQuitInputPane.md` lifecycle/xref evidence.
7. Update `UserPaneInputVtables.md` exact `QuitInputPane` vtable slice.
8. Optionally update TimerMgr/MapPane/global support docs with the caller/field evidence.
9. Do not manually edit `by-memory/-coverage-report.md` unless the supervisor owns that step; if requested, use the exact row text above and replace child UID placeholders after validator assignment.
10. Run the validation commands listed above.

## Files Changed In This Pass

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0001KS-QuitInputPaneCore-source-quality.md`
- No by-* documentation changed.
- `by-memory/-coverage-report.md` was not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001KS-QuitInputPaneCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001KS"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001KS-QuitInputPaneCore-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001KS-QuitInputPaneCore-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001KS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
