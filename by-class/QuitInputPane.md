*** UID:0000BH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class QuitInputPane : public CharInputPane,
                      public Singleton<QuitInputPane>
{
public:
    QuitInputPane();
    virtual ~QuitInputPane();

    virtual void OnConfirmInput();
};

extern QuitInputPane *g_pQuitInputPane;

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# QuitInputPane

## Status

- Source family: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), candidate source file `NexusTK/ui/dialogs/QuitDialogs.cpp`.
- Split-index core: [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md).
- Exact constructor child: [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md).
- Exact confirm-handler child: [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md).
- Destructor ranges: [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md) and [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md).
- Singleton storage: [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md), documented globally as [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md).

This fieldless derived-class shell emits through `QuitDialogs.cpp` with direct `CharInputPane` and empty `Singleton<QuitInputPane>` bases, then routes its exact constructor, destructor, and confirmation-handler children through `[[CHILDREN]]`. The class is closed before the child marker, and the backing pointer is declared after the class. Method bodies remain on their exact by-memory source anchors.

## Class Purpose

`QuitInputPane` is the legacy typed quit confirmation prompt built on [UID:00001P][CharInputPane](by-class/CharInputPane.md) and the direct RTTI-proven empty base `Singleton<QuitInputPane>`. It prompts with localized string id `3`; the Singleton base publishes the active prompt through `g_pQuitInputPane`; and the pane accepts only a one-character `Y` or `y` response as affirmative quit confirmation.

It belongs to `QuitDialogs.cpp`, not to `UserPane`, `MapPane`, `TimerMgr`, or `InputPanes`. `UserPane` only reaches the launcher through the quit key case. `MapPane` and `TimerMgr` are callees on the affirmative confirmation path. `InputPanes` owns the inherited line-input helpers but not this quit-specific class.

## Method Map

| Address | Method | Source role |
| --- | --- | --- |
| `0x005adcc0-0x005add18` | [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) | Unique retained out-of-line constructor definition. It obtains localized id `3`, constructs direct `CharInputPane` and `Singleton<QuitInputPane>` bases, and receives compiler-generated primary/secondary/tertiary vptrs. The standalone address has no route after exhaustive scans, while the live launcher contains an inline-equivalent sequence. |
| `0x005add20-0x005add8a` | [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) | Primary-vtable submit/confirmation handler at `0x0062f09c -> 0x005add20`. It requires one input character, accepts `Y/y`, deletes the prompt on one-character non-confirmation, removes pending timers for the local-player/UserPane timer owner at `g_pCollectionData + 0xa4`, and calls `MapPane::ExitToMenu(true)`. |
| `0x005b7836-0x005b784c` | destructor adjustor thunks | Compiler-generated secondary/tertiary adjustor thunks now listed in [UID:0000VN][-ignored](by-memory/-ignored.md); they adjust `this` from secondary bases and tail-call the scalar deleting destructor. |
| `0x005b7b30-0x005b7b75` | [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md) | Source-emitting ordinary-destructor anchor inside the scalar deleting entry. Human derived destructor is empty; reverse direct-base destruction makes the early singleton clear an implicit `Singleton<QuitInputPane>` effect. Inherited teardown, flags, release, guard, return-this ABI, vtable dispatch, and adjustor mechanics are compiler-generated. |

`OnEnterKey()` remains an acceptable final-source alias for `OnConfirmInput()` only if the inherited input-pane convention later proves the slot is named after Enter-key submission. The current best-supported semantic name is `OnConfirmInput()` because the handler receives no key-code argument and implements submit/confirm behavior.

## Layout And Vtable Evidence

`QuitInputPane` has three vtable views installed by the retained constructor and duplicated by the typed launcher:

| Vtable | Store offsets / slots | Meaning |
| --- | --- | --- |
| `0x0062f054` | primary pointer stored at object `+0x0`; primary destructor slot `0x0062f054 -> 0x005b7b30`; handler slot `0x0062f09c -> 0x005add20` | Main `QuitInputPane` view and confirm-input virtual. |
| `0x0062f0a4` | secondary pointer stored at object `+0xa0`; slot `0x0062f0a4 -> 0x005b7836`; inherited input/key slot `0x0062f0ac -> 0x004f2920` | Secondary input-pane/base-interface view. |
| `0x0062f0d4` | tertiary pointer stored at object `+0xa4`; slot `0x0062f0d4 -> 0x005b7841` | Tertiary base/interface view. |

These vtable stores are compiler-generated constructor output. They are evidence for class layout and ownership, not source statements to include in method C++.

The three-view layout, typed-launcher allocation, and guarded-delete size all fix the complete object at `0x108`. No `QuitInputPane`-specific field is accessed beyond inherited `CharInputPane` state. The direct empty Singleton base occupies a source base position without increasing the complete size; the size is ABI/layout evidence, not a source constant or padding member to place in the class.

Direct RTTI evidence:

| Record | Address / value | Meaning |
| --- | --- | --- |
| `QuitInputPane` TypeDescriptor | `0x00679c38` | Exact derived class identity. |
| `Singleton<QuitInputPane>` TypeDescriptor | `0x00679c54` | Exact direct empty-base specialization. |
| Primary COL / CHD / base array | `0x006521ac` / `0x006521c0` / `0x006521d0` | Nine-entry complete hierarchy. |
| Self / Singleton base descriptors | `0x006521f8` / `0x00652214` | Self contains eight following inherited entries; Singleton is a leaf direct base. |
| Singleton PMD / attributes | `0x108/-1/0`, `0x40` | Non-virtual empty base at one-past the `CharInputPane` subobject. |

The flattened hierarchy contains `QuitInputPane`, `CharInputPane`, `LineInputPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`, and `Singleton<QuitInputPane>`. Only `CharInputPane` and Singleton are direct source bases; the other entries are inherited through `CharInputPane`.

## Singleton Lifecycle

`g_pQuitInputPane` is the active typed quit prompt singleton and duplicate guard:

| Access site | Role |
| --- | --- |
| `0x005a954f` | launcher duplicate guard before typed-prompt allocation. |
| `0x005a9598` | launcher-inline Singleton base publishes the constructed complete prompt. |
| `0x005a95a0` | compiler null-adjustment fallback stores zero in the launcher inline sequence. |
| `0x005adcf3` | retained constructor's Singleton base publishes the adjusted complete object. |
| `0x005b7b38` | implicit Singleton base destruction clears the pointer before `CharInputPane` teardown. |

The constructor child and launcher both use localized prompt id `3`, call the same base constructor, perform the same adjusted Singleton publication, and install the same vtable triplet. That normalized duplicate confirms compiler inlining and class identity while preserving the source distinction: the launcher is a free entry helper, and the child is the retained out-of-line constructor definition. UserPane calls the launcher directly; IconsPane action 7 reaches its five-byte thunk.

Current PE-aware storage checks show `0x0069bf5c` is loader-zeroed virtual-tail `.data`, not an initialized `0xffffffff` sentinel. The source declaration is `extern QuitInputPane *g_pQuitInputPane;`; the single definition belongs to [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) in `QuitDialogs.cpp`.

## Confirm-Input Behavior

The confirm handler uses inherited line-input helpers:

- `LineInputPane::GetTextLength()` at `0x004f2310`.
- `LineInputPane::CopyText(wchar_t *out, int count)` at `0x004f2300`.

Behavior:

1. If the current text length is not exactly `1`, return and keep the pane alive.
2. Copy one UTF-16 character into a local stack buffer.
3. If the character is neither `L'y'` nor `L'Y'`, call `Pane::MarkForDeletion()` and return.
4. If the character is `L'y'` or `L'Y'`, compute the local-player/UserPane timer owner at `g_pCollectionData + 0xa4` when `g_pCollectionData` is non-null.
5. Call the direct TimerMgr removal helper `0x00597a10` through `g_pTimerMgr` to remove pending timers for that owner.
6. Call `g_activeMapPane->ExitToMenu(true)`, where `true` requests the exit/menu path with server notification.

The `+0xa4` timer-owner field is strongly supported by the handler's call shape, but the final source-facing containing type/name for `g_pCollectionData` remains broader local-player/UserPane state and should not be forced to a collection-only type.

## Shared Helper Caveat

The inherited line-input helpers are not quit-specific source:

| Address | Current or historical emitted name | Correct ownership |
| --- | --- | --- |
| `0x004f2300-0x004f230f` | `QuitInputPane::ReadInputText` / text-copy helper | Shared [UID:000077][LineInputPane](by-class/LineInputPane.md) copy helper in [UID:0000K7][InputPanes](by-file/InputPanes.md). |
| `0x004f2310-0x004f231b` | `QuitInputPane::GetInputLength` / length helper | Shared [UID:000077][LineInputPane](by-class/LineInputPane.md) length helper in [UID:0000K7][InputPanes](by-file/InputPanes.md). |

Caller fanout shows these helpers are used by many typed input panes. They should not be moved into `QuitDialogs.cpp` just because the quit confirm handler consumes them.

## Source-Quality Decisions

Resolved:

- Raw constructor status: unique retained out-of-line definition, not unknown helper or launcher-covered no-code; live calls use an inline-equivalent launcher sequence.
- Prompt id `3`: localized typed quit prompt.
- Confirm-handler signature: `void QuitInputPane::OnConfirmInput()`.
- Main-menu transition: `MapPane::ExitToMenu(true)`.
- Timer cleanup: direct `TimerMgr::RemovePendingTimersForOwner`.
- Singleton: direct empty `Singleton<QuitInputPane>` base at PMD `+0x108`; `g_pQuitInputPane` is its loader-zeroed backing pointer and duplicate guard.
- Owner/source: `QuitInputPane` in `QuitDialogs.cpp`.
- Parent emission: [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md) is a non-emitting split index; exact children emit.
- Destructor source split: [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md) emits an empty `QuitInputPane::~QuitInputPane()`; implicit Singleton base destruction owns the early clear. No separate ordinary-destructor function exists; scalar-delete ABI remains compiler-only.
- Class declaration: fieldless `QuitInputPane : public CharInputPane, public Singleton<QuitInputPane>` with constructor, virtual destructor, `OnConfirmInput`, singleton extern, and a closed class before `[[CHILDREN]]`.

Rejected:

- Constructor as launcher/factory: it does not allocate and assumes `ecx == this`.
- Constructor as `CharInputPane`: it calls `CharInputPane` and then installs `QuitInputPane` state.
- Handler as raw key event: no key-code argument exists.
- Handler as `MapPane` or `TimerMgr` source: those are affirmative-path callees.
- `g_pCollectionData` forced to a collection-only type: the handler proves a local-player/UserPane timer owner view at `+0xa4`.
- Manual constructor/destructor assignment to `g_pQuitInputPane`: rejected by direct Singleton RTTI, non-virtual PMD `+0x108`, compiler adjustment pattern, and reverse base destruction order.
- Omitting Singleton from the class shell: rejected because it would contradict the exact hierarchy and leave the adjusted publication/clear source cause unexplained.
- Handwritten deleting-destructor flags, base calls, object release, guard helper, vptr stores, object-size constants, adjustor thunks, or a synthetic singleton-clear child: all duplicate compiler output or invent a nonexistent source entry.

Remaining:

- Final source type/global name for the broad object currently documented as `g_pCollectionData`, and the exact field spelling for its `+0xa4` timer-handler owner. This affects final header/type cleanup, not the class split, method ownership, or first-draft child C++.

## Score Rationale

Completion is `92` because the page records complete direct-base class/extern/children syntax, exact constructor/destructor/handler children, target hash and retained/inlined disposition, full RTTI/PMD/EBO/0x108 layout, three-view vtables, implicit Singleton lifecycle and zero storage, launcher callers, prompt resource ownership, inherited helper boundary, TimerMgr/MapPane callees, rejected alternatives, and source/compiler emission policy.

Confidence is `94` because raw constructor bytes, direct RTTI, complete-size controls, vtable data, live launcher inlining/routes, all five physical singleton xrefs, unique destructor entry, inherited base contract, and exact handler disassembly independently agree. Original symbols, original TU spelling, and the broad `g_pCollectionData` type/name are not recovered, so `95+` is not claimed.

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md)
- [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md)
- [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)
- [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)

## Changes

- 2026-07-14 B003 UID0003ZQ callback: raised `90/93` to `92/94`; installed the exact closed `CharInputPane, Singleton<QuitInputPane>` class declaration; added TypeDescriptor/COL/CHD/BCD/PMD, EBO, exact `0x108` layout, retained-out-of-line/live-inline constructor disposition, launcher caller, prompt-resource, implicit Singleton lifetime, compiler exclusion, rejected-alternative, and score evidence; changed the ordinary source destructor to empty while preserving all confirm-handler and shared-helper facts.
- 2026-07-14 B004 UID0001NC callback: raised `88/90` to `90/93`, inserted the complete closed `QuitInputPane : public CharInputPane` declaration with constructor, virtual destructor, `OnConfirmInput`, singleton extern, and `[[CHILDREN]]`; attached UID0001NC as the ordinary-destructor source anchor while excluding compiler deleting-destructor mechanics; and preserved the existing constructor/handler behavior and wider source-family caveats.
- 2026-06-19 B013 implementation: raised `85/86` to `88/90`, replaced stale below-`90/90` C++ blocker with exact child emission policy, added [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) and [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) method links, recorded the vtable slot `0x0062f09c`, prompt id `3`, singleton lifecycle, inherited input helpers, `Y/y` behavior, TimerMgr removal for `g_pCollectionData + 0xa4`, and `MapPane::ExitToMenu(true)`.
