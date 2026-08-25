*** UID:0000MX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# QuitDialogs

## UID00037R Public Header And MapPane Consumer - 2026-08-24

- `NexusTK/ui/dialogs/QuitDialogs.h` now owns the one complete [UID:0000BG][QuitDialog](by-class/QuitDialog.md) declaration. The declaration includes `AlertPanes.h`, forward-declares `InputEvent`, and preserves public constructor/key handling plus protected primary-button handling.
- `NexusTK/ui/dialogs/QuitDialogs.cpp` includes `QuitDialogs.h` once, then receives the existing exact child definitions. The class is no longer declared locally in the CPP channel, so generated CPP/H contain one declaration and one definition set rather than duplicate class text.
- [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) consumes the header from `NexusTK/map/MapPane.cpp` through exact relative include `../ui/dialogs/QuitDialogs.h` and constructs `QuitDialog` on Alt+X at `0x00507068`.
- The consumer relationship does not transfer source ownership. QuitDialogs remains `91/92`, `CANONICAL_OWNER:FILE`, path `NexusTK/ui/dialogs/`, and sole owner of the class and method children; MapPane owns only its keyboard dispatch.

## Status

- Proposed module folder: `NexusTK/ui/dialogs/`.
- Candidate source file: `NexusTK/ui/dialogs/QuitDialogs.cpp`.
- Confidence: very strong for quit-prompt source grouping, complete modal/typed declarations, launcher body/routes, direct Singleton lifetime, retained/inlined constructor disposition, prompt resources, exact child C++ ownership, and compiler exclusions.

`QuitDialogs.cpp` owns the in-game quit confirmation UI. It contains the shared launcher policy, the modern modal Yes/No quit dialog path, the legacy typed `QuitInputPane` path, and the source-declared labels used by the modal path. The menu selector and `UserPane` key handler only reach the quit action; they do not own the dialog implementations.

## Source Contents

| Entity | Range / doc | Source role |
| --- | --- | --- |
| [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) / [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) | `0x005a94b0-0x005a95d2` | Complete void `OpenQuitPrompt` source route. UserPane calls directly; IconsPane action 7 uses a five-byte thunk. Source chooses `new QuitDialog` when `g_useEpfAssets` is true, otherwise guarded `new QuitInputPane`; allocation/EH/inlined constructor/vptr lowering stays compiler-only. |
| [UID:0000BG][QuitDialog](by-class/QuitDialog.md) / [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md) | `0x005addf0-0x005adf2e` | Complete `AlertPane`-derived modal Yes/No declaration with constructor, key handler, protected primary callback, and exact child order; UID0001KT remains a non-emitting split/index parent over constructor/key/switch-data/primary-button children. |
| [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md) | `0x005addf0-0x005ade40` | Exact first-draft C++ owner for `QuitDialog::QuitDialog()`, using localized prompt id `3`, [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md), and source-declared `Yes (Y)` / `No (N)` labels. |
| [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md) | `0x005ade40-0x005adedb` | Exact first-draft C++ owner for `QuitDialog::OnKeyInput(const InputEvent *event)`, handling message type `8`, `Y/y`, `N/n`, close, and inherited fallback. |
| [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) | `0x005adedb-0x005adf20` | Non-emitting compiler-lowered switch data and `0xcc` alignment for `QuitDialog::OnKeyInput`; source semantics are covered by the key-handler child. |
| [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md) | `0x005adf20-0x005adf2e` | Exact first-draft C++ owner for `QuitDialog::OnPrimaryButton()`, routing affirmative confirmation to [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)`->ExitToMenu(true)`. |
| [UID:0003JO][0x006309f4-0x00630a14.QuitPromptYesNoStrings](by-memory/0x006309f4-0x00630a14.QuitPromptYesNoStrings.md) | `0x006309f4-0x00630a14` | Source-declared `No (N)` and `Yes (Y)` labels shared by the launcher and modal dialog setup. |
| [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) | class owner | Complete fieldless `CharInputPane, Singleton<QuitInputPane>` typed prompt at exact size `0x108`, using localized id `3`, implicit singleton lifetime, and one-character `Y/y` confirmation. |
| [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) | `0x005adcc0-0x005add18` | Unique 88-byte retained out-of-line constructor definition, SHA256 `E904698CBABF89AB65CA604C07B1BC2D2D3928BA72A3B76F8D70E41CF4BE8CFB`; its address has no route after exhaustive scans, while the live launcher contains the same normalized base/Singleton/vptr sequence inline. |
| [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) | `0x005add20-0x005add8a` | Exact first-draft C++ owner for `QuitInputPane::OnConfirmInput()`, primary-vtable slot `0x0062f09c`. |
| [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md) | `0x005b7b30-0x005b7b75` | Exact source anchor for the empty `QuitInputPane::~QuitInputPane()`. Direct Singleton-base destruction owns the early global clear; inherited teardown, scalar flags, release/guard paths, return-this ABI, vtable dispatch, and adjustor thunks remain compiler-generated. |
| [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md) | `0x005adcc0-0x005add8a` | Non-emitting split index over the constructor child, eight-byte internal `0xcc` gap, and confirm-handler child. |
| [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) / [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md) | `0x0069bf5c` | Active legacy typed quit prompt singleton, source-defined once in this file as a null-initialized `QuitInputPane *`; exact loader-zeroed storage remains a non-duplicating blank formal page. |

The exact method pages, not the parent aggregate, own `QuitInputPane` method C++. UID0003ZQ and UID0003ZR cover the constructor/handler split, while UID0001NC is the separate destructor source anchor. This keeps generated output aligned to source functions instead of emitting a mixed constructor/padding/handler island or handwritten deleting-destructor wrapper.

## Launcher Relationship

The launcher is the shared entry point for the quit prompt. UserPane key case `0x51` calls it directly at `0x005a5cc8`. IconsPane action case `7` reaches its five-byte thunk at `0x005a5a80` from `0x004cf712`; the raw IconsPane duplicate at `0x004cf949` references that same thunk but remains a separate retained/no-route body.

Branch behavior:

| Branch | Condition | Effect |
| --- | --- | --- |
| Modern modal quit prompt | `g_useEpfAssets` / historical `byte_66DA97 == 1` | Allocates the larger `0x270`-byte modal `QuitDialog`, uses localized string id `3`, consumes the `No (N)` / `Yes (Y)` labels, and installs `QuitDialog` vtables. |
| Legacy typed duplicate guard | `byte_66DA97 != 1` and `g_pQuitInputPane` is non-null | Returns without constructing another typed prompt. |
| Legacy typed prompt construction | `byte_66DA97 != 1` and `g_pQuitInputPane` is null | Source constructs a new `QuitInputPane`; compiler output allocates `0x108`, inlines localized `CharInputPane` plus direct Singleton construction, publishes the adjusted complete pointer, and installs the same three vptrs as the retained definition. |
| Legacy typed fallback clear | adjusted compiler result is null | Compiler null/EH fallback stores zero; no handwritten source clear or separate branch is emitted. |

The launcher contains an independently generated inline-equivalent of [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md): id `3`, `CharInputPane`, adjusted Singleton publication, and three vptrs in the same order. This proves source liveness while the zero-address-route standalone copy remains the unique out-of-line definition. It does not transfer member ownership to the launcher.

## QuitInputPane Source Placement

`QuitInputPane` belongs to this file because:

- The typed prompt is one of the two quit-confirmation UI forms selected by the launcher.
- The constructor and launcher both use localized prompt id `3`.
- The singleton `g_pQuitInputPane` is only meaningful for the typed quit prompt lifecycle.
- The handler's affirmative path performs quit-specific cleanup and calls `MapPane::ExitToMenu(true)`.
- The vtable family at `0x0062f054/0x0062f0a4/0x0062f0d4` is named and used as `QuitInputPane`, not as a generic input-pane class.

Rejected source owners:

- `InputPanes`: owns inherited `LineInputPane` / `CharInputPane` helpers, not the quit-specific class.
- `UserPane`: owns key dispatch into the launcher, not quit dialog policy or typed prompt methods.
- `MapPane`: owns exit-to-menu teardown, reached only after affirmative confirmation.
- `TimerMgr`: owns timer removal helpers, consumed only for cleanup before exiting.
- `g_pQuitInputPane`: documents storage, not class methods.

## QuitInputPane Declaration And Source Order

[UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) owns the complete fieldless declaration with direct `CharInputPane` and empty `Singleton<QuitInputPane>` bases, constructor, virtual destructor, `OnConfirmInput`, a closed class before `[[CHILDREN]]`, and an external backing-pointer declaration. Direct RTTI places Singleton at non-virtual PMD `+0x108`; complete allocation and guarded-delete size are both `0x108`. The class shell emits before exact method children through this file owner.

[UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) owns the single null-initialized definition in `QuitDialogs.cpp`. [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md) records the exact `00 00 00 00` loader-zeroed storage but stays formally blank so the generated translation unit receives no duplicate definition.

The source route is therefore complete class declaration and extern, one backing-pointer definition, then exact constructor, confirmation-handler, and ordinary-destructor definitions through class `[[CHILDREN]]`. Compiler Singleton publication/clear, vtables, adjustor thunks, base teardown, deleting flags, object release, guard/size mechanics, EH, allocation helpers, and mixed parent ranges do not become handwritten source entities.

[UID:0000BG][QuitDialog](by-class/QuitDialog.md) likewise emits a complete `AlertPane`-derived declaration before its children: parameterless constructor and `OnKeyInput` are public, `OnPrimaryButton` is protected, no `Singleton<QuitDialog>` base is invented, and the class closes before `[[CHILDREN]]`.

## QuitDialog Method C++ Ownership

Exact child method pages now own the accepted `QuitDialog` C++ while UID0001KT remains a non-emitting parent:

```cpp
QuitDialog::QuitDialog()
    : AlertPane(g_pLanguageMan->GetLocalizedString(3),
                g_pBackPane,
                L"Yes (Y)",
                L"No (N)")
{
}
```

```cpp
bool QuitDialog::OnKeyInput(const InputEvent *event)
{
    const char key = NarrowInputKey(event->keyCode, event->narrowFallback);

    if (event->type != 8)
        return false;

    switch (key) {
    case 'Y':
    case 'y':
        OnPrimaryButton();
        CloseDialog();
        return true;

    case 'N':
    case 'n':
        OnSecondaryButton();
        CloseDialog();
        return true;

    default:
        return DialogPane::OnKeyInput(event);
    }
}
```

```cpp
void QuitDialog::OnPrimaryButton()
{
    g_activeMapPane->ExitToMenu(true);
}
```

The source C++ intentionally excludes constructor vtable stores and the `0x005adedb-0x005adf20` switch data/alignment bytes. Those bytes are compiler-generated from the key-handler switch and are documented on [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) with blank emitter/C++.

## QuitInputPane Method C++ Ownership

Exact child method pages own the accepted `QuitInputPane` constructor and confirmation-handler C++; UID0001NC separately owns the accepted ordinary destructor formal block:

```cpp
QuitInputPane::QuitInputPane()
    : CharInputPane(g_pLanguageMan->GetLocalizedString(3)),
      Singleton<QuitInputPane>()
{
}
```

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

The constructor C++ intentionally omits compiler vtable stores. The handler C++ uses the best-supported semantic field role for `g_pCollectionData + 0xa4`; final containing type/global spelling remains a UserPane/local-player state open item, not a blocker for the method split.

[UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md) emits an empty source-visible virtual destructor. Reverse direct-base destruction makes the binary's early global clear an implicit Singleton effect. The `LineInputPane` teardown, hidden scalar-delete flags, normal object release, guarded `0x108` path, original-pointer return, and two adjustor thunks remain ABI evidence and are intentionally excluded from source text.

## Shared Helper Boundary

`0x004f2300` and `0x004f2310` are shared line-input helpers with broad caller fanout. They are inherited dependencies of `QuitInputPane::OnConfirmInput()`, not `QuitDialogs.cpp` local helpers:

- `0x004f2300`: `LineInputPane::CopyText`.
- `0x004f2310`: `LineInputPane::GetTextLength`.

Keep them under [UID:0000K7][InputPanes](by-file/InputPanes.md) / [UID:000077][LineInputPane](by-class/LineInputPane.md).

## Singleton Lifecycle

`g_pQuitInputPane` is owned by the typed quit prompt source family and routes through this file:

| Site | Role |
| --- | --- |
| `0x005a954f` | launcher duplicate guard. |
| `0x005a9598` | launcher-inline Singleton base publishes the adjusted complete prompt. |
| `0x005a95a0` | compiler null-adjustment fallback stores zero. |
| `0x005adcf3` | retained constructor's Singleton base publishes the adjusted complete object. |
| `0x005b7b38` | implicit Singleton base destruction clears before CharInputPane teardown. |

The singleton prevents duplicate legacy typed prompts. It should not be confused with unrelated neighboring globals.

## IDA / Source-Quality Evidence

Accepted B013 source-quality implementation confirmed:

- `0x005adcc0-0x005add18` is a separately delimited raw constructor body ending with `ret` at `0x005add17`.
- `0x005add18-0x005add20` is eight bytes of `0xcc` internal padding.
- `0x005add20-0x005add8a` is a modeled function, `sub_5ADD20`, size `0x6a`.
- `0x005add20` has a primary vtable route at `0x0062f09c`; lack of direct code callers is expected for this virtual handler.
- `0x005add8a-0x005add90` is external post-handler `0xcc` padding outside `0001KS`.
- The retained constructor has no inbound IDA xref, executable E8/E9 target, VA/RVA/raw-offset pointer, constructor table, factory table, or vtable cell. Its exact body occurs once; the live launcher supplies a normalized inline equivalent and two semantic launcher routes, resolving source liveness without inventing a direct target call.
- Direct RTTI proves `CharInputPane` and `Singleton<QuitInputPane>` as direct bases, Singleton PMD `0x108/-1/0`, exact size `0x108`, and implicit publication/clear. Historical manual-global source statements are superseded while all five physical access sites remain evidence.
- Current `STR.RES` zero-based id `3` is `Do you really want to leave? (Y/N) `; both branches preserve runtime lookup rather than hard-coded English.

Accepted B004 UID0001NC implementation additionally confirms:

- `0x005b7b30-0x005b7b75` is one exact 69-byte, five-block scalar deleting entry with unique primary-vtable and two adjustor-thunk routes and no separate ordinary-destructor function.
- The derived human destructor is empty; direct Singleton-base destruction owns the unconditional clear while all deleting ABI mechanics remain compiler-only.
- Exact storage at `0x0069bf5c` is loader-zeroed virtual-tail `.data`, replacing the stale `0xffffffff` interpretation and supporting one source definition initialized to `NULL`.
- Rejected owners remain `InputPanes`, `UserPane`, `MapPane`, and `TimerMgr`; each is an inherited dependency, caller, or affirmative-path callee rather than the quit-specific class/global/destructor source owner.

Accepted B012 `QuitDialog` split implementation confirmed:

- [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md) is the source-bearing constructor child: MCP session `aa3930bd` confirmed size `0x50`, direct calls from `0x00507068` and `0x005bd202`, localized string id `3`, `g_pBackPane`, Yes/No labels, and compiler vtable stores that are excluded from source.
- [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md) is the source-bearing key handler child: size `0x9b`, vtable data xref `0x0062f150`, message type `8`, `Y/y` primary route, `N/n` secondary route, close helper, and inherited fallback.
- [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) is non-reconstructable compiler-lowered switch data/alignment: no function start at `0x005adedb`, no standalone source route, and source semantics covered by the key-handler switch.
- [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md) is the source-bearing primary-button child: size `0x0e`, vtable data xref `0x0062f13c`, and `g_activeMapPane->ExitToMenu(true)` source route through MapPane teardown support.
- Rejected owners remain `MenuVarietyPanes`, `MenuVarietySelectPane`, `DialogPane`/`AlertPane` base ownership, and `MapPane` ownership. Those pages provide callers/dependencies; `QuitDialogs.cpp` owns the modal quit-dialog source.

## Score Rationale

Completion is `91` because this file page records the source path, complete `OpenQuitPrompt` declaration/body and two caller routes, modern/legacy branch source semantics, complete QuitDialog and `CharInputPane, Singleton<QuitInputPane>` declarations, retained/inlined constructor relationship, exact child C++ ownership, implicit singleton lifecycle and zero definition, prompt resource, vtable/compiler exclusions, shared-helper boundary, rejected owners, and split-index handling.

Confidence is `92` because direct bytes/RTTI/vtables, complete-size controls, launcher callers/branches, exact children, singleton storage, and related class/global/resource docs converge. Original launcher/TU spellings and the final local-player/UserPane type behind `g_pCollectionData` remain broader confidence caps but do not block this file route or emitted source.

## Cross-References

- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md)
- [UID:0003JO][0x006309f4-0x00630a14.QuitPromptYesNoStrings](by-memory/0x006309f4-0x00630a14.QuitPromptYesNoStrings.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md)
- [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md)
- [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md)
- [UID:0004GY][0x005addf0-0x005ade40.QuitDialogConstructor](by-memory/0x005addf0-0x005ade40.QuitDialogConstructor.md)
- [UID:0004GZ][0x005ade40-0x005adedb.QuitDialogOnKeyInput](by-memory/0x005ade40-0x005adedb.QuitDialogOnKeyInput.md)
- [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md)
- [UID:0004H1][0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton](by-memory/0x005adf20-0x005adf2e.QuitDialogOnPrimaryButton.md)
- [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)

## Changes

- 2026-07-14 B003 UID0003ZQ callback: raised `89/88` to `91/92`; synchronized complete R1-R6 source routing, direct Singleton RTTI/EBO/0x108 class lifetime, empty derived destructor, live UserPane/IconsPane launcher routes, exact retained/inlined constructor disposition, prompt id 3 resource ownership, compiler exclusions, source order, physical lifecycle sites, rejected owners, and score rationale while preserving all QuitDialog/confirm-handler/helper/label history and unrelated content.
- 2026-07-14 B004 UID0001NC callback: score unchanged at `89/88`; added the source-emitting ordinary `QuitInputPane` destructor anchor, complete class/extern/children route, single null-initialized singleton definition and blank exact-storage policy, exact source/compiler destructor split, zero-fill correction, source order, and generated ownership expectations while preserving all modern `QuitDialog`, launcher, handler, string, timer, MapPane, and rejected-owner detail.
- 2026-07-04 B012 split-first implementation: added exact `QuitDialog` child method inventory and C++ ownership, reclassified [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md) as the non-emitting split/index parent, documented [UID:0004H0][0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable](by-memory/0x005adedb-0x005adf20.QuitDialogOnKeyInputSwitchTable.md) as compiler-lowered switch data/alignment, and preserved the rejected MenuVariety/DialogPane/MapPane ownership routes. Evidence: accepted B012 report for UID0001KT and MCP session `aa3930bd` verified function sizes, constructor callers, key/primary vtable refs, switch-data bytes, localized prompt id `3`, `g_pBackPane`, and `g_activeMapPane->ExitToMenu(true)`.

- 2026-06-19 B013 implementation: raised `87/85` to `89/88`, added exact `QuitInputPane` child method inventory and C++ ownership, documented the non-emitting parent split, clarified the launcher relationship and modern/legacy branch behavior, preserved the shared input-helper ownership boundary, and tied `g_pQuitInputPane`, `g_pCollectionData + 0xa4`, TimerMgr removal, and `MapPane::ExitToMenu(true)` support evidence into the source-file plan.
