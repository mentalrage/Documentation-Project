** TARGET-REPORT-UID:0001MN **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-spellspellinputpane-source-quality-0001MN-0001MP-0001MQ-20260617

Agent: B001  
Date: 2026-06-17  
Scope: report-only source-quality reanalysis for [UID:0001MN], [UID:0001MP], and [UID:0001MQ]. No by-* docs, generated reports, generated source, source files, IDA database, or `by-memory/-coverage-report.md` were edited.

## Target Summary

Targets reviewed:

- [UID:0001MN] `by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md`
- [UID:0001MP] `by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md`
- [UID:0001MQ] `by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md`

Recommended state:

- Keep all three targets as exact reconstructable/emitting method pages owned by [UID:0000DT] `SpellSpellInputPane`.
- Keep [UID:0001MO] `SpellSpellInputPane` aggregate as a non-emitting index over exact children. No split repair is needed for this assignment.
- Keep source placement under [UID:0000O0] `SpellInputPanes` / `NexusTK/ui/dialogs/SpellInputPanes.cpp`, not [UID:0000ID] `CommandInputPanes`, not [UID:0000O1] `SpellInventoryPane`.
- Populate first-draft C++ for all three target pages after applying the source-facing names below. Do not carry forward generated-source `SpellManager` / `g_pSpellMan` names.

Recommended target scores:

- [UID:0001MN] `86/90`
- [UID:0001MP] `86/90`
- [UID:0001MQ] `87/90`

## Evidence Reviewed

Documentation and structure context:

- Target pages [UID:0001MN], [UID:0001MP], [UID:0001MQ].
- Aggregate [UID:0001MO] `SpellSpellInputPane`.
- Class [UID:0000DT] `SpellSpellInputPane`.
- File docs [UID:0000O0] `SpellInputPanes` and [UID:0000ID] `CommandInputPanes`.
- Shared input/base docs [UID:000077] `LineInputPane`, [UID:00018Y] `LineInputPaneSetPromptText`, and related `CharInputPane` behavior from nearby exact pages.
- Vtable docs [UID:0002N7] `SpellSpellInputPaneVtableData` and [UID:0003HL] `SpellSpellInputPaneVtables`.
- Related prompt pages [UID:0001LM], [UID:0001LV], [UID:0001LW], [UID:0001LX].
- Global/support docs [UID:0000QK] / [UID:0001OR] for `dword_67A748`, [UID:0000R0] `g_pGeneralPurposePanel`, [UID:00028R] `g_pSoundManager`, [UID:0000RC] `g_pLanguageMan`, [UID:0000WO] CRT formatted-output glue, and [UID:0003UC] `0x005a4530` command/spell-slot dispatch.
- Generated source `source-3/simroot_v2/class_SpellSpellInputPane.cpp`.
- `by-memory/-coverage-report.md` current rows for [UID:0001MO]-[UID:0001MQ].

IDA/MCP evidence checked:

- Function boundaries: `0x005b6120` size `0xc7`, `0x005b61f0` size `0x6c`, `0x005b6260` size `0x68`.
- Direct xrefs:
  - `0x005b6120`: no direct code xrefs.
  - `0x005b61f0`: data xref from secondary vtable slot `0x00630474`.
  - `0x005b6260`: data xref from primary vtable slot `0x00630464`.
- Vtable stores to `0x0063041c`, `0x0063046c`, and `0x0063049c` in the constructor and in raw/open construction routes at `0x005a6ac2`/`0x005a9e78` neighborhoods.
- Constructor callees: `0x004f28a0`, `0x005a4310`, `0x004f0350`, `0x0041b9b0`, `0x004f20a0`.
- Key-input callees: `0x004a8b10`, `0x004b8650`, `0x0057a5c0`, `0x004f2920`.
- Accept callees: `0x004f2310`, `0x004f2300`, `0x005a4530`.
- Helper `0x005a4310` decompilation: scans local-player spell records with stride `0x148`, active flag around `+0x13a834`, emits lower/upper spell shortcut letters and collapsed ranges into a UTF-16 prompt fragment.
- Helper `0x005a4530` decompilation: validates a 1..52 spell/command slot against local-player spell state, then opens the proper spell argument pane or sends a direct cast packet according to the slot record type.

## Heuristic / Inference Reanalysis And Validation

### Overall Split And Ownership

Best recommendation: no split repair. The three target pages are exact method bodies and the existing aggregate [UID:0001MO] should remain a non-emitting index. The exact pages cover:

- `0x005b6120-0x005b61e7`: constructor body.
- `0x005b61f0-0x005b625c`: secondary key/input-interface handler.
- `0x005b6260-0x005b62c8`: primary accept/submit handler.

Rejected alternatives:

- Do not make [UID:0001MO] emitting. It is already a method-family index and would duplicate exact child methods.
- Do not merge the three children into the aggregate. Each child has a separate vtable/reachability role and should remain separately scoreable.
- Do not move ownership to [UID:0000ID] `CommandInputPanes`. That file is an address-neighborhood umbrella for command prompt panes, but its own notes already point spell-specific prompt classes back to [UID:0000O0].
- Do not move ownership to [UID:0000O1] `SpellInventoryPane`. `0x005a4530` and spell inventory routes create or dispatch prompt panes, but these three methods are UI dialog input-pane code.

Impact: exact child pages should advance above the code-entry average threshold; aggregate can stay non-emitting and should only be updated as an index/support page.

### Constructor [UID:0001MN]

Best source-facing name/signature:

```cpp
SpellSpellInputPane::SpellSpellInputPane();
```

Best source-facing behavior:

- Calls the `CharInputPane`/`LineInputPane` base constructor with a zero/false option.
- Installs the primary, secondary, and tertiary `SpellSpellInputPane` vtables at object offsets `+0`, `+0xa0`, and `+0xa4`.
- Builds a localized prompt from language string id `0x24` / decimal `36`.
- The format argument is not the current spell name. It is the available spell shortcut/range text built by helper `0x005a4310` from local-player spell records.
- Calls `LineInputPaneSetPromptText` with the formatted prompt.

Best helper and data names:

- `0x005a4310`: recommend `BuildAvailableSpellSlotRangeText` or `BuildAvailableSpellShortcutRangeText`. This helper should not be named `GetCurrentSpellName`. It scans active spell slots and emits shortcut letters/ranges.
- `dword_67A748`: keep linked to existing [UID:0000QK] / [UID:0001OR], but source-facing use in this class is best described as `g_pLocalUserPane`, `g_pLocalPlayerState`, or `g_pPlayerState`, not `g_pSpellMan` and not collection-only ownership.
- Spell table field direction:
  - base pointer: local-player spell/command state under `dword_67A748`.
  - stride: `0x148`.
  - active flag used by range builder: `+0x13a834 + slot * 0x148`.
  - prompt/name text used by dispatch-created panes: `+0x13a794 + slot * 0x148`.
  - slot record base used by dispatch helper: `+0x13a6ec + slot * 0x148`.
  - global active/spell-state flag checked by dispatch: `+0x13ead4`.

Rejected alternatives:

- Generated `SpellManager::GetCurrentSpellName(g_pSpellMan, spellName)` is wrong. The live helper receives `dword_67A748` as `this`, not a spell-manager global, and scans the player spell table to produce available shortcut letters.
- Naming the prompt helper as a language lookup helper is too broad; language lookup is a separate call to `0x004f0350`.
- Treating `0x0041b9b0` as a NexusTK helper is wrong; [UID:0000WO] and IDA decompilation support CRT `swprintf_s` wrapper semantics.

Remaining uncertainty and impact:

- The exact original global name for `dword_67A748` is still a project-wide naming issue. This does not block a first draft because the target behavior and field meanings are strong enough; keep confidence below 95 and update support docs rather than using generated `g_pSpellMan`.
- The helper name `BuildAvailableSpellSlotRangeText` is inferred from behavior, not symbol recovery. It is source-facing and defensible, but support docs should record it as inferred.

### Key Handler [UID:0001MP]

Best source-facing name/signature:

```cpp
bool SpellSpellInputPane::OnKeyInput(const InputEvent *event);
```

If the project standard passes the event by reference, use:

```cpp
bool SpellSpellInputPane::OnKeyInput(const InputEvent& event);
```

The binary body is a secondary vtable method reached through the object view at `+0xa0`. The method does not subtract `0xa0` before delegating; the base fallback is called with the same adjusted key/input-interface pointer. Source should express this as a normal override, not a manual pointer adjustment.

Best event/helper names:

- `event + 0x04 == 8`: keyboard input event kind. Recommended symbolic name for now: `InputEventKind::KeyInput` or `kInputEventKey`.
- `event + 0x08`: key/character byte narrowed through the CRT/std ctype helper.
- `event + 0x10a == 4`: narrow/default/key-mode byte required by the existing input-pane shortcut idiom. Recommended field name until event layout is finalized: `narrowFallback` or `keyMode`.
- `0x004a8b10`: compiler/runtime `std::ctype<char>::do_narrow`; do not emit it as a game helper.
- `0x004b8650`: [UID:00015X] `GeneralPurposePanel::SwitchActiveTab`.
- `0x0057a5c0`: [UID:00028R] sound effect helper on `g_pSoundManager`.
- Sound constants: effect/sample id `0x198`, volume `100`.
- Tab constant: `3`, best source-facing name `SpellHelpTab` or `SpellPanelTab`.
- Fallback: `CharInputPane::OnKeyInput(event)` via `0x004f2920`.

Best behavior:

- If the input event is the `?` shortcut in the expected key mode/event type, switch the general-purpose/help panel to tab 3, play sound `0x198` at volume `100`, and return handled.
- For every other event, delegate to `CharInputPane::OnKeyInput` and return that result.

Rejected alternatives:

- Do not call this a mouse handler or a primary Pane handler; vtable data shows the key/input override is on the secondary vtable at `0x00630474`.
- Do not mark non-`?` events as locally handled. The only unconditional handled return is the help shortcut path; the fallback return is whatever `CharInputPane::OnKeyInput` returns.
- Do not attribute `0x004b8650` to `SpellOneArgInputPane`; that is generated owner pollution already rejected by [UID:00015X].

Remaining uncertainty and impact:

- The exact project event struct field names are not finalized. The semantic checks are strong because the same idiom appears in related spell input panes. This should cap the page below final 95-level source certainty but should not keep it below 85/85.

### Accept Handler [UID:0001MQ]

Best source-facing name/signature:

```cpp
void SpellSpellInputPane::OnAccept();
```

Best behavior:

- Uses `LineInputPaneTextLength` / `0x004f2310` and only proceeds when the entered text length is exactly one UTF-16 code unit.
- Uses `LineInputPaneCopyText` / `0x004f2300` to copy one character.
- Maps `a`..`z` to slots `1`..`26`.
- Maps `A`..`Z` to slots `27`..`52`.
- Rejects all other characters.
- Calls `0x005a4530` on `dword_67A748` with the selected slot.

Best helper/global names:

- `0x005a4530`: recommend `LivingObjectPane::UseCommandSlot`, `LivingObjectPane::UseSpellSlot`, or `LocalPlayerPane::DispatchSpellSlot`. Existing page [UID:0003UC] title `LivingObjectPaneUseCommandSlotDispatch` is directionally correct.
- The accept handler itself should not be named `SelectSpell` if that implies merely storing the value. It dispatches the selected spell/command slot through the player-state helper, which may open another input pane or send a direct packet.
- `dword_67A748` is the local user/player state object used by this dispatch path. It is currently documented under `g_pCollectionData`, but this target should not present it as a collection-only global.

Rejected alternatives:

- Generated `SpellManager::SelectSpell(g_pSpellMan, spellIndex)` is wrong. The live call target is `0x005a4530` with `ecx = dword_67A748`, and the target validates active player spell records before dispatch.
- Do not add a second explicit range check against the number of active spells in this method. The binary only maps letters to 1..52 and delegates active-record validation to `0x005a4530`.
- Do not model this as a direct packet sender. Direct packet send is only one branch inside `0x005a4530` for spell type 5.

Remaining uncertainty and impact:

- The exact source class name for the object behind `dword_67A748` remains broader than this target. Use a source-facing local-player/user-pane name in first-draft C++ and keep the existing UID links so the global can be reconciled in a future global pass.
- The exact final name of `0x005a4530` is still being refined across LivingObjectPane/SpellInventory docs. This does not block a draft here because the call semantics and ownership boundary are clear.

### Vtable, Reachability, And Padding

Recommended reachability text:

- [UID:0001MN]: no direct code xrefs to the function start were found. Keep it as the ordinary source constructor body because the body has constructor shape, installs all three class vtables, and identical class vtable routes are live through spell-input construction/open neighborhoods. This should be described as no-direct-xref constructor evidence, not vtable-only virtual reachability.
- [UID:0001MP]: vtable-only live through secondary key/input slot `0x00630474`.
- [UID:0001MQ]: vtable-only live through primary accept/submit slot `0x00630464`.

Padding/boundary recommendation:

- [UID:0001MN] ends at `0x005b61e7`; padding continues to `0x005b61f0`.
- [UID:0001MP] begins after that padding and ends at `0x005b625c`; padding continues to `0x005b6260`.
- [UID:0001MQ] covers `0x005b6260-0x005b62c8`.
- No interleaved child ownership or split-range repair is needed.

### Source Placement

Best placement: [UID:0000O0] `SpellInputPanes` / `NexusTK/ui/dialogs/SpellInputPanes.cpp`.

Reasons:

- Constructor prompt text, key shortcut, and accept dispatch are spell-specific dialog input-pane behavior.
- Related spell prompt classes and analogous helpers are already documented in `SpellInputPanes`.
- [UID:0000ID] `CommandInputPanes` is a broader address/source-family umbrella and should keep only cross-reference notes for these spell-specific panes.
- [UID:0000O1] `SpellInventoryPane` and LivingObjectPane dispatch helpers own the callers/slot dispatch machinery, not the prompt-pane methods.

Impact: do not change the canonical owner/emitter for the three target pages; keep [UID:0000DT] as canonical owner and [UID:0000O0] as the source file route through the class.

## First-Draft C++ Recommendation

Populate formal C++ for all three targets using the following source-facing names. The draft intentionally avoids the generated-source `SpellManager` and `g_pSpellMan` names because live evidence rejects them.

### [UID:0001MN] Constructor

```cpp
SpellSpellInputPane::SpellSpellInputPane()
    : CharInputPane(false)
{
    wchar_t availableSlots[100];
    wchar_t prompt[128];

    BuildAvailableSpellSlotRangeText(g_pLocalUserPane, availableSlots);

    const wchar_t *format = g_pLanguageMan->GetString(36);
    swprintf_s(prompt, 128, format, availableSlots);

    SetPromptText(prompt);
}
```

Notes for supervisor application:

- `BuildAvailableSpellSlotRangeText` is the recommended source-facing name for `0x005a4310`.
- `g_pLocalUserPane` is the recommended source-facing replacement for the historical `dword_67A748`/`g_pCollectionData` alias in spell/player-state contexts. If the broader global pass is not ready to rename it, keep the UID link but avoid `g_pSpellMan`.
- The compiler vtable stores and SEH cleanup should not be emitted in source C++.

### [UID:0001MP] Key Input

```cpp
bool SpellSpellInputPane::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (key == '?' &&
        event->narrowFallback == 4 &&
        event->type == 8) {
        g_pGeneralPurposePanel->SwitchActiveTab(3, false);
        g_pSoundManager->PlayEffect(0x198, 100);
        return true;
    }

    return CharInputPane::OnKeyInput(event);
}
```

Notes for supervisor application:

- Replace `InputEvent::type`, `InputEvent::keyCode`, and `InputEvent::narrowFallback` with the final project event-struct names if they are already standardized elsewhere.
- `NarrowInputKey` is source-facing shorthand for the binary `std::ctype<char>::do_narrow` path at `0x004a8b10`.
- If the source convention uses constants, prefer `kInputEventKey`, `kSpellHelpTab`, and `kSpellHelpSoundId` over raw `8`, `3`, and `0x198`.
- The source method is a normal override even though the binary vtable route is the secondary `+0xa0` input-interface view.

### [UID:0001MQ] Accept

```cpp
void SpellSpellInputPane::OnAccept()
{
    if (GetTextLength() != 1) {
        return;
    }

    wchar_t ch = 0;
    CopyText(&ch, 1);

    unsigned char slot = 0xff;
    if (ch >= L'a' && ch <= L'z') {
        slot = static_cast<unsigned char>(ch - L'a' + 1);
    } else if (ch >= L'A' && ch <= L'Z') {
        slot = static_cast<unsigned char>(ch - L'A' + 27);
    } else {
        return;
    }

    if (slot != 0xff) {
        g_pLocalUserPane->UseCommandSlot(slot);
    }
}
```

Notes for supervisor application:

- `UseCommandSlot` may become `UseSpellSlot` or `DispatchSpellSlot` if [UID:0003UC] settles on a more specific source name. The target should still describe the call as local-player command/spell-slot dispatch through `0x005a4530`.
- Do not emit a direct packet send or a `SpellManager::SelectSpell` call here.

## Score And Metadata Recommendations

### [UID:0001MN] `SpellSpellInputPaneConstructor`

Recommended metadata:

- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000DT`
- `EMITTER_UIDS: 0000DT`
- Score: `86/90`
- Source route: [UID:0000DT] `SpellSpellInputPane` -> [UID:0000O0] `SpellInputPanes`.
- Formal C++: populate with the constructor draft above.

Reason for score:

- Exact range, constructor shape, vtable installs, prompt building, CRT format, base setter, padding, and source placement are resolved.
- Confidence remains below final-grade because the original source names for `dword_67A748` and `0x005a4310` are inferred rather than recovered.

### [UID:0001MP] `SpellSpellInputPaneKeyInput`

Recommended metadata:

- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000DT`
- `EMITTER_UIDS: 0000DT`
- Score: `86/90`
- Source route: [UID:0000DT] `SpellSpellInputPane` -> [UID:0000O0] `SpellInputPanes`.
- Formal C++: populate with the key-input draft above.

Reason for score:

- Exact range, vtable-only liveness, secondary-interface role, shortcut behavior, tab/sound helper ownership, fallback semantics, and source placement are resolved.
- Confidence remains below final-grade because event struct field names are inferred from layout and sibling behavior.

### [UID:0001MQ] `SpellSpellInputPaneAccept`

Recommended metadata:

- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 0000DT`
- `EMITTER_UIDS: 0000DT`
- Score: `87/90`
- Source route: [UID:0000DT] `SpellSpellInputPane` -> [UID:0000O0] `SpellInputPanes`.
- Formal C++: populate with the accept draft above.

Reason for score:

- Exact range, vtable-only liveness, text-length/copy helpers, letter-to-slot mapping, local-player dispatch ownership, range behavior, and source placement are resolved.
- Confidence remains below final-grade because the final project-wide name for `dword_67A748` and `0x005a4530` is still being reconciled across support docs.

No score downgrade is recommended for the no-direct-caller/no-direct-xref observations. [UID:0001MP] and [UID:0001MQ] are virtual-only by design; [UID:0001MN] is a source constructor body whose direct start xref is absent but whose body, vtable installation, and raw construction neighborhoods are consistent with the class.

## Support Docs To Update

Recommended support-doc edits for supervisor:

- [UID:0000DT] `by-class/SpellSpellInputPane.md`
  - Update method summary with final method names:
    - `SpellSpellInputPane::SpellSpellInputPane()`
    - `SpellSpellInputPane::OnKeyInput(const InputEvent *)`
    - `SpellSpellInputPane::OnAccept()`
  - Record that generated `SpellManager`/`g_pSpellMan` names are rejected.
  - Prefer `g_pLocalUserPane`/local-player state wording for `dword_67A748`.
  - Raise confidence to about `87/90` if class scoring is being refreshed.

- [UID:0000O0] `by-file/SpellInputPanes.md`
  - Confirm `SpellSpellInputPane` as owned by `NexusTK/ui/dialogs/SpellInputPanes.cpp`.
  - Add note that `CommandInputPanes` is a source-family/address-neighborhood cross-reference, not the final owner for this class.
  - Raise confidence from `88/85` to about `88/87` if file confidence is being refreshed.

- [UID:0000ID] `by-file/CommandInputPanes.md`
  - Keep a cross-reference only; note that `SpellSpellInputPane` resolves to `SpellInputPanes`.

- [UID:0001MO] `by-memory/0x005b6120-0x005b62c8.SpellSpellInputPane.md`
  - Keep as non-emitting index.
  - Update child summaries with the names and scores recommended here.

- [UID:0003UC] `by-memory/0x005a4530-0x005a4908.LivingObjectPaneUseCommandSlotDispatch.md`
  - Add caller note: [UID:0001MQ] maps a single entered spell shortcut to 1..52 and calls this helper on `dword_67A748`.
  - Consider settling source-facing name as `UseCommandSlot`, `UseSpellSlot`, or `DispatchSpellSlot`.

- [UID:0000QK] / [UID:0001OR] `g_pCollectionData` / `0x0067a748`
  - Add spell-input view of the local-player spell table:
    - `+0x13a6ec + slot * 0x148`: spell/command slot record base.
    - `+0x13a794 + slot * 0x148`: spell prompt/name text used by dispatch-created panes.
    - `+0x13a834 + slot * 0x148`: active/learned flag used by `0x005a4310`.
    - `+0x13ead4`: global active/spell state guard checked by `0x005a4530`.
  - Note that `g_pCollectionData` is too narrow for this global's spell/input role; prefer a future local-player/UserPane source-facing alias.

- [UID:00015X] `GeneralPurposePanelSwitchActiveTab` and [UID:00028R] `g_pSoundManager`
  - No ownership change needed. Optional cross-reference from [UID:0001MP] for the `?` help shortcut.

## Supervisor-Owned Coverage Rows

Do not edit `by-memory/-coverage-report.md` directly from B001. Replace the current rows for [UID:0001MN], [UID:0001MP], and [UID:0001MQ] with the following exact text. No insert/delete rows are needed.

Placement context: under the existing [UID:0001MO] `SpellSpellInputPane` aggregate row and before [UID:0001MR] `WieldInputPane`.

```markdown
    - [UID:0001MN][0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor](by-memory/0x005b6120-0x005b61e7.SpellSpellInputPaneConstructor.md) 0x005b6120-0x005b61e7 | constructor | SpellSpellInputPaneConstructor : reconstructable : 86% : very strong : B001 2026-06-17 source-quality reanalysis confirms exact constructor range, no direct start xrefs but constructor-shaped class body, CharInputPane base construction, available spell shortcut/range prompt helper `0x005a4310`, localized format id `0x24`, CRT `swprintf_s`, LineInputPane prompt setter, primary/secondary/tertiary vtables at +0/+0xa0/+0xa4, padding, SpellInputPanes ownership, generated current-spell-name rejection, and first-draft constructor C++.
    - [UID:0001MP][0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput](by-memory/0x005b61f0-0x005b625c.SpellSpellInputPaneKeyInput.md) 0x005b61f0-0x005b625c | method | SpellSpellInputPaneKeyInput : reconstructable : 86% : very strong : B001 2026-06-17 source-quality reanalysis confirms exact secondary-vtable key/input override range, vtable-only reachability through `0x00630474`, adjusted +0xa0 interface/base route, `?` shortcut event checks (`event+0x04 == 8`, narrowed `event+0x08`, `event+0x10a == 4`), GeneralPurposePanel tab 3 switch, SoundManager effect `0x198` at volume `100`, fallback CharInputPane key handling, padding, SpellInputPanes ownership, and first-draft key-input C++.
    - [UID:0001MQ][0x005b6260-0x005b62c8.SpellSpellInputPaneAccept](by-memory/0x005b6260-0x005b62c8.SpellSpellInputPaneAccept.md) 0x005b6260-0x005b62c8 | method | SpellSpellInputPaneAccept : reconstructable : 87% : very strong : B001 2026-06-17 source-quality reanalysis confirms exact primary-vtable accept override range, vtable-only reachability through `0x00630464`, LineInputPane text-length/copy helpers, single-character `a`..`z`/`A`..`Z` mapping to spell/command slots 1..52, `dword_67A748` as local-player/UserPane spell state rather than generated SpellManager, dispatch through `0x005a4530`/LivingObjectPane command-slot helper, no direct packet send in this method, padding, SpellInputPanes ownership, and first-draft accept C++.
```

## Validation Commands For Supervisor

Recommended validation after applying target/support doc updates and coverage rows:

> Executable block R001 was removed from this report and preserved verbatim in [0001MN-0001MP-0001MQ-spellspellinputpane-source-quality-removed.md](0001MN-0001MP-0001MQ-spellspellinputpane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Changed Files

Report created:

- `tools/leaser/Agents/Agent-B001/research/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md`

No by-* docs, generated reports, generated source, source files, IDA database, or `by-memory/-coverage-report.md` were edited by B001.

## Remaining Follow-Up

The only material follow-up is a broader source-name reconciliation for `dword_67A748` and the LivingObjectPane spell/command-slot dispatch helper at `0x005a4530`. This report recommends enough target-local naming to move [UID:0001MN], [UID:0001MP], and [UID:0001MQ] above the B-agent source-quality threshold without waiting for that global pass.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"0001MN"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001MN-0001MP-0001MQ-spellspellinputpane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/0001MN-0001MP-0001MQ-spellspellinputpane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001MN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
