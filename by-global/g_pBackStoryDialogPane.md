*** UID:0000Q9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class BackStoryDialogPane;

BackStoryDialogPane *g_pBackStoryDialogPane = 0;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pBackStoryDialogPane

## Status

- Semantic type: `BackStoryDialogPane *`.
- Exact physical storage: [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md), four PE loader-zeroed bytes at `0x0069b498`.
- Source owner: [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md) / `NexusTK/login/BackStoryDialogPane.cpp`.
- Source role: sole externally linked definition, emitted at file position 0 before the class/method children.
- Initializer: explicit C++03-style zero `= 0`; the binary cannot distinguish this lexical token from implicit/static zero, but current project/family style makes it the highest-probability human source shape.

## Purpose And Lifecycle

`g_pBackStoryDialogPane` stores the retained main-menu BackStory text-dialog singleton. The direct `Singleton<BackStoryDialogPane>` base publishes and clears it through compiler/template lowering, while main-menu cleanup reads it across source ownership when a retained instance is live.

Exactly five direct references define the observed lifecycle:

| Address | Access | Source interpretation |
| --- | --- | --- |
| `0x004f69ce` | read | `CloseMainMenuDialogSingletons` checks/closes the externally visible singleton. |
| `0x005000e5` | write object | Direct Singleton construction publishes the complete BackStory object. |
| `0x005000ec` | write zero | Constructor fallback/EH lowering clears publication. |
| `0x00502390` | write zero | [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md) performs constructor-unwind/base-destructor clear. |
| `0x00502606` | write zero | [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md) performs normal reverse-destruction clear. |

## Initializer And Physical Storage

- The current physical bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`.
- PE `.data` raw backing ends at VA `0x0067a800`, while its virtual extent continues to `0x0069ce24`; this slot lies `0x20c98` bytes beyond raw backing and is loader-zeroed.
- No hidden pointer initializer, RVA/VA/raw-offset pointer table, sentinel write, or alternate typed use was found.
- Historical `0xffffffff` wording is rejected as stale. The semantic source definition is a zero-initialized pointer, not an integer sentinel.

## Type And Template Evidence

- Constructor publication stores an adjusted complete [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) object.
- [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md) and [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md) prove the BackStory type and exact class family.
- RTTI proves direct `Singleton<BackStoryDialogPane>` inheritance with PMD `{0x26c,-1,0}`, attributes `0x40`, and empty-base placement at the end of the `0x26c`-byte complete object.
- Direct Singleton lowering explains all four writes. Authored constructor/destructor bodies must not repeat publication or clear statements.

## Linkage And One-Definition Decision

- Publication/teardown belongs to the BackStory class/source family, but the read at `0x004f69ce` belongs to the main-menu cleanup source family. That cross-source use requires a shared declaration and strongly supports external linkage.
- This page owns the sole source definition in `BackStoryDialogPane.cpp`.
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md) emits the forward declaration/`extern` contract used by class/source consumers.
- UID00029F remains a false/non-emitting physical child. Emitting from both pages would violate one-definition semantics.
- No evidence supports a file-local anonymous static, a class static data member, a template-owned storage variable, or a duplicate main-menu definition.

## Retained Compatibility Context

- Current active story/history menu routes construct `HistoryViewingPane`, not BackStoryDialogPane.
- No current direct caller, rel32/VA/RVA/raw pointer route, constructor table, or external BackStory vtable-head store survives for constructor `0x00500090`.
- The complete class/source/lifecycle artifacts remain linked, and `CloseMainMenuDialogSingletons` still consumes this pointer. The correct source classification is retained compatibility code with a removed/replaced launcher, not dead data.

## Negative Evidence And Rejected Alternatives

- MainMenuPane cleanup consumption does not transfer global definition ownership to `MainMenuPane.cpp`.
- HistoryViewingPane is the current replacement route, not the identity or owner of this pointer.
- `BackPane` is an unrelated in-game map/background UI class and is rejected.
- A raw `dword_69B498`, integer sentinel, physical-address wrapper, duplicate definition, explicit constructor assignment, or handwritten clear helper would contradict the combined type/lifecycle/source evidence.

## Score Rationale

- Completion `92`: definition, type, initializer, linkage, physical mapping, five-ref lifecycle, direct Singleton source cause, one-definition route, retained context, rejected alternatives, and formal C++ are complete.
- Confidence `94`: current bytes/PE mapping, all xrefs, RTTI/EBO, class/compiler pages, and external cleanup use agree. Original lexical zero token and historical launcher remain bounded confidence caps.

## Cross-References

- [UID:0000HP][BackStoryDialogPane](by-file/BackStoryDialogPane.md)
- [UID:00000T][BackStoryDialogPane](by-class/BackStoryDialogPane.md)
- [UID:0001A2][0x00500090-0x0050040d.BackStoryDialogPaneCore](by-memory/0x00500090-0x0050040d.BackStoryDialogPaneCore.md)
- [UID:00029F][0x0069b498-0x0069b49c.g_pBackStoryDialogPane](by-memory/0x0069b498-0x0069b49c.g_pBackStoryDialogPane.md)
- [UID:0003HH][0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor](by-memory/0x00502390-0x0050239b.BackStoryDialogPaneSingletonBaseDestructor.md)
- [UID:0004W8][0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks](by-memory/0x0050245e-0x00502474.BackStoryDialogPaneDestructorAdjustorThunks.md)
- [UID:0004W9][0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor](by-memory/0x00502600-0x00502645.BackStoryDialogPaneScalarDeletingDestructor.md)
- [UID:0004WA][0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData](by-memory/0x0061da54-0x0061daf0.BackStoryDialogPaneVtableData.md)
- [UID:0004WB][BackStoryDialogPaneVtables](by-type/by-vtable/BackStoryDialogPaneVtables.md)
- [UID:0000PH][CloseMainMenuDialogSingletons_4F69A0](by-global/CloseMainMenuDialogSingletons_4F69A0.md)

## Historical And Superseded Assumptions

- Earlier docs described physical bytes as `0xffffffff`; current loader-zero bytes and PE section mapping supersede that initializer claim.
- Earlier formal C++ was blank while the physical page emitted, leaving an empty global marker. One-definition analysis now routes the exact source definition here and leaves the physical page blank.
- Earlier text treated active construction as unresolved. Exhaustive negative routing plus current HistoryViewing construction resolves BackStory as retained compatibility source.

## Changes

- Historical scoring moved from unevaluated through `86/84` and `88/87` as address/type/lifecycle/source ownership were established.
- 2026-06-22 B014 Rule 26 incorporation separated retained BackStory singleton state from active HistoryViewing construction.
- 2026-07-22 B002 UID00029F accepted callback: raised `88/87 -> 92/94`, set emitter position 0, inserted the sole exact zero-initialized pointer definition, corrected loader-zero/`0xffffffff` history, and incorporated complete type/linkage/Singleton/one-definition evidence.
