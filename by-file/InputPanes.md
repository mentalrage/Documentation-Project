*** UID:0000K7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# InputPanes

## UID000364 Canonical Event Handler Completion - 2026-07-20

- [UID:000364][0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent](by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md) is the complete source-authored `bool CharInputPane::HandleKeyOrTextEvent(Event *event)` body. It translates key/modifiers before filtering, returns true for non-key-down events, propagates Escape through LineInputPane, accepts inclusive printable ASCII `0x20..0x7e`, rewrites the Event as one UTF-16 text code unit, queues deferred pane removal, clears `UserPane::m_activeLineInputPane` through `ClearActiveLineInputPane()`, invokes inherited handling and `OnAccept()` in exact order, returns false only for four translated arrow keys, and handles all other key-down values.
- The active slot at complete UserPane `+0x210` is a `LineInputPane *`: the LineInputPane constructor reads and queues the previous pane and is the sole non-null typed writer, while UID000364 and the related input handlers clear it during dismissal. The previously documented pending-target `ObjectPane *` role is disproved because no ObjectPane pointer is stored in the slot and target-selection objects remain separate.

### Historical UID000364 Pending-Target Interpretation

The earlier summary said UID000364 cleared `m_pendingTargetObject` through `ClearPendingTargetObject()`. That interpretation arose because target-selection handlers dismiss an input pane adjacent to object interaction. Exact read/queue/store/clear data flow proves the slot instead tracks the active LineInputPane. The old terminology is retained here only as dated reconstruction history and must not re-enter current formal C++.
- [UID:00001P][CharInputPane](by-class/CharInputPane.md), [UID:000077][LineInputPane](by-class/LineInputPane.md), and [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) now expose the canonical `Event *` / `HandleKeyOrTextEvent` contract. NumberInputPane, NumberArgsInputPane, MultiLineInputPane, and SayToUserName retain their independent filters/algorithms while inheriting or referencing this same base signature.
- [UID:00004L][Event](by-class/Event.md) supplies the exact `0x110` layout, byte input-code/byte text-length/UTF-16 overlay, Escape/arrows, and complete Alt/Menu `0x01`, Control `0x02`, Shift `0x04` modifiers. [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md) retains compiler-only vtable/RTTI emission while documenting the canonical secondary `+0x08` slot source cause.
- Historical blank-body, `CharInputPaneKeyAccept`, `InputKeyEvent`, `InputEvent`, `OnKeyInput`, `NarrowInputKey`, and raw `do_narrow` descriptions are superseded provenance. The source route, existing scores, complete family inventory, children, destructor/adjustor split, and all unrelated prompt behavior remain unchanged.

## Status

- UID0000OJ dependency closure: UID000077 is now the single formal CPP/H root. Generated CPP include order is BlackHole, `InputPanes.h`, then `TextEditPane.h`, followed by method children. Generated H has one guard, includes Pane before LineInputPane, and orders CharInputPane/CharArgsInputPane after the complete base. This replaces the dated pre-include CharArgs and unguarded/derived-before-base snapshot without changing input behavior.
- Confidence: very strong for the reusable input-pane base family, exact LineInputPane constructor and `0x108` layout, method boundaries, class/file emitter graph, and compiler-thunk separation; exact original filename and final include order remain inferred.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/InputPanes.cpp`
- Generated header route: `ui/dialogs/InputPanes.h` receives complete reusable base declarations, including [UID:00001P][CharInputPane](by-class/CharInputPane.md). `InputPanes.cpp` includes that header and receives the exact method-body children; feature-derived headers therefore inherit from a complete base without duplicating the declaration in a source channel.
- Type docs: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Evidence basis: IDA MCP boundary, decompile, caller/callee, vtable, and byte checks, combined with current project-documentation cross-references.

## UID0000OJ Incorporation - 2026-08-16

| Claim | Incorporated disposition |
| --- | --- |
| C0000OJ-053 / C0000OJ-467 | Exact root, include, guard, and complete-base declaration order is formalized through UID000077. |
| C0000OJ-476 / C0000OJ-477 | BlackHole and Pane dependencies retain their established owning headers; TextEditPane visibility is consumed through UID0000EO. |

## Hypothesis

`InputPanes.cpp` should own the reusable typed input prompt base classes used by item, command, chat, spell, and confirmation prompt panes. These classes are infrastructure for short in-game command prompts rather than feature-specific item/social command panes.

Feature-specific derivatives should stay in neighboring modules such as [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).

## Proposed Contents

| Entity | Current range | Source placement | Role |
| --- | --- | --- | --- |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | `0x004f1c00-0x004f2f62` | `InputPanes.cpp` | Exact `0x108` base one-line prompt with source-ready constructor, label/edit children, two deferred-submit fields, prompt text setup, active UserPane slot, EventDispatcher guard timer, chat refresh, Enter/Escape/Tab handling, shared cleanup, and text access helpers. |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | `0x004f27a0-0x004f289a` | `InputPanes.cpp` | Numeric-only line input variant. |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | `0x004f28a0-0x004f2faa` | `InputPanes.cpp` | Single-character accepting variant that dismisses the pane and notifies the owner after a printable character. |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | `0x004f2a10-0x004f2a57`, `0x004f2fb0-0x004f3017`, `0x005b75d0-0x005b760e` | `InputPanes.cpp` | Yes/no confirmation input wrapper over `CharInputPane`; owns a `FunctionObject0 *m_acceptAction` callback at `+0x108`, with constructor/class C++ now source-ready under the active gate. |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | `0x004f2a60-0x004f2b73` | `InputPanes.cpp` | Character-argument line input allowing letters, comma, and space. |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | `0x004f2b80-0x004f2c84` | `InputPanes.cpp` | Numeric-argument line input allowing digits, comma, and space. |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | `0x004f2c90-0x004f2dca` | `InputPanes.cpp` | Multi-line input variant; Enter submits/clears, Escape or Ctrl+C closes. |

## 2026-07-01 Empty-Emitter Family Sync

B011's accepted [UID:0000K7] empty-emitter report resolves the ten remaining empty generated markers in `auto-generated/NexusTK/ui/dialogs/InputPanes.cpp` without moving ownership away from this reusable input-pane module. Live MCP session `supervisor_resume_20260629` was responsive on the NexusTK IDB; `server_health` reported module `NexusTK.exe`, auto-analysis ready, Hex-Rays ready, and strings cache size `2067`. The report also rechecked current generated `InputPanes.cpp`, current by-* docs, B001 split evidence, and B009 ConfirmInputPane precedent.

Accepted dispositions:

| UID | Target | Disposition |
| --- | --- | --- |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | Class declaration | Emits a declaration shell with `OnKeyInput` and `[[CHILDREN]]`; constructor/filter bodies remain on exact by-memory children. |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | Header class declaration | Emits the complete `CharInputPane : public LineInputPane` declaration through generated `InputPanes.h`, including the constructor, virtual destructor, canonical `HandleKeyOrTextEvent(Event *)`, source-defined empty `OnAccept()`, and no data fields; formal CPP includes `InputPanes.h` and emits exact method-body children. |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | Base class declaration | Emits the reusable one-line prompt class shell with `m_promptTextPane` at `+0xf8`, `m_textEditPane` at `+0xfc`, method declarations, and `[[CHILDREN]]`. |
| [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md) | Method body | Emits first-draft `LineInputPane::SetPromptText` preserving prompt measurement, first-create/update paths, the `byte_66DA97` layout branch, prompt child `+0xf8`, edit child `+0xfc`, and attach/update calls. |
| [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md) | Method body | Emits tiny `LineInputPane::CopyText` accessor forwarding to the edit child at `+0xfc`; IDA xrefs show 40 direct callers. |
| [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md) | Method body | Emits tiny `LineInputPane::TextLength` accessor forwarding to the edit child at `+0xfc`; IDA xrefs show 37 direct callers. |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | Class declaration | Emits a declaration shell with `HandleKeyInput` and `[[CHILDREN]]`; Enter/Escape/Ctrl+C body remains on exact child pages. |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | Class declaration | Emits a declaration shell with `OnKeyInput` and `[[CHILDREN]]`; digit/comma/space filter body remains on exact child pages. |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | Class declaration | Emits a declaration shell with `OnKeyInput` and `[[CHILDREN]]`; digit/control filter body remains on exact child pages. |
| [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md) | Formal no-duplicate source comment | Emits only a comment documenting that vtables are compiler/linker output from class declarations; fixed vtable dwords remain documented in [UID:000389][0x0061ca54-0x0061ce28.InputPaneBaseVtableData](by-memory/0x0061ca54-0x0061ce28.InputPaneBaseVtableData.md). |

The stale `95/95` no-code gate is superseded for this family: all ten pages are reconstructable, route to valid emitters, and clear the active `(COMPLETION + CONFIDENCE) / 2 > 85` code-entry gate after the accepted score updates. Feature-specific prompt files remain consumers only; do not move reusable base helper bodies into `ItemActionInputPanes`, `TargetSelectionInputPanes`, `SpellInputPanes`, `Chatting`, `CommandInputPanes`, `SayInputPanes`, or `BlockListenInputPanes`.

After scoped callback validators with `--wait-generated`, `auto-generated/NexusTK/ui/dialogs/InputPanes.cpp` is expected to have a `validator-refreshed-at` timestamp equal to or newer than the final scoped validator command and no old empty-marker lines for [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md), [UID:00001P][CharInputPane](by-class/CharInputPane.md), [UID:000077][LineInputPane](by-class/LineInputPane.md), [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md), [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md), [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md), [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md), [UID:00009L][NumberInputPane](by-class/NumberInputPane.md), or [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md).

## Exact Split Children

B001-042 split the compact [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) aggregate into exact source-bearing child pages. These children are direct-owned by class pages; this file page remains the shared source-file parent for those classes.

| Class | Exact children |
| --- | --- |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md), [UID:00035Q][0x004f2010-0x004f2092.LineInputPaneCleanupBody](by-memory/0x004f2010-0x004f2092.LineInputPaneCleanupBody.md), [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), [UID:00035R][0x004f2300-0x004f230f.LineInputPaneCopyText](by-memory/0x004f2300-0x004f230f.LineInputPaneCopyText.md), [UID:00035S][0x004f2310-0x004f231b.LineInputPaneTextLength](by-memory/0x004f2310-0x004f231b.LineInputPaneTextLength.md), [UID:00035T][0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout](by-memory/0x004f2320-0x004f242f.LineInputPaneUpdateChildLayout.md), [UID:00035U][0x004f2430-0x004f24b5.LineInputPaneAttachChildren](by-memory/0x004f2430-0x004f24b5.LineInputPaneAttachChildren.md), [UID:00035V][0x004f24c0-0x004f24e5.LineInputPaneShowChildren](by-memory/0x004f24c0-0x004f24e5.LineInputPaneShowChildren.md), [UID:00035W][0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder](by-memory/0x004f24f0-0x004f257a.LineInputPaneHitTestForwarder.md), [UID:00035X][0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder](by-memory/0x004f2580-0x004f2598.LineInputPaneActiveChildForwarder.md), [UID:00035Y][0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput](by-memory/0x004f25a0-0x004f2754.LineInputPaneHandleKeyInput.md), [UID:00035Z][0x004f2760-0x004f2783.LineInputPaneTextEditForwarder](by-memory/0x004f2760-0x004f2783.LineInputPaneTextEditForwarder.md), [UID:000360][0x004f2790-0x004f2791.LineInputPaneNoOpVirtual](by-memory/0x004f2790-0x004f2791.LineInputPaneNoOpVirtual.md), [UID:00036D][0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor](by-memory/0x004f2dd0-0x004f2e59.LineInputPaneCompleteDestructor.md), [UID:00036E][0x004f2ea0-0x004f2f63.LineInputPaneScalarDeletingDestructor](by-memory/0x004f2ea0-0x004f2f63.LineInputPaneScalarDeletingDestructor.md). |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | [UID:000361][0x004f27a0-0x004f2813.NumberInputPaneConstructor](by-memory/0x004f27a0-0x004f2813.NumberInputPaneConstructor.md), [UID:000362][0x004f2820-0x004f289b.NumberInputPaneKeyFilter](by-memory/0x004f2820-0x004f289b.NumberInputPaneKeyFilter.md). |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | [UID:000363][0x004f28a0-0x004f2913.CharInputPaneConstructor](by-memory/0x004f28a0-0x004f2913.CharInputPaneConstructor.md), [UID:000364][0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent](by-memory/0x004f2920-0x004f29ca.CharInputPaneHandleKeyOrTextEvent.md), [UID:00036F][0x004f2f70-0x004f2fab.CharInputPaneScalarDeletingDestructor](by-memory/0x004f2f70-0x004f2fab.CharInputPaneScalarDeletingDestructor.md). |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | [UID:000365][0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor](by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md), [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md), [UID:00036G][0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor](by-memory/0x004f2fb0-0x004f3017.ConfirmInputPaneScalarDeletingDestructor.md), plus the late constructor [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md). |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | [UID:000367][0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor](by-memory/0x004f2a60-0x004f2ad3.CharArgsInputPaneConstructor.md), [UID:000368][0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter](by-memory/0x004f2ae0-0x004f2b74.CharArgsInputPaneKeyFilter.md). |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | [UID:000369][0x004f2b80-0x004f2bf3.NumberArgsInputPaneConstructor](by-memory/0x004f2b80-0x004f2bf3.NumberArgsInputPaneConstructor.md), [UID:00036A][0x004f2c00-0x004f2c85.NumberArgsInputPaneKeyFilter](by-memory/0x004f2c00-0x004f2c85.NumberArgsInputPaneKeyFilter.md). |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | [UID:00036B][0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor](by-memory/0x004f2c90-0x004f2cc5.MultiLineInputPaneConstructor.md), [UID:00036C][0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler](by-memory/0x004f2cd0-0x004f2dcb.MultiLineInputPaneKeyHandler.md). |
| Compiler artifacts | [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md) is compiler-generated and remains non-reconstructable/parent blank. |

## Boundary Notes

- IDA confirms the compact base cluster at `0x004f1c00-0x004f3017`; `0x004f3020` starts unrelated `EnsureServerSelectPane`.
- IDA confirms the early `LineInputPane` body sequence inside that cluster: constructor `0x004f1c00-0x004f2009`, shared cleanup/lifecycle body `0x004f2010-0x004f2092`, prompt setter [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), and text helpers at `0x004f2300` / `0x004f2310`.
- IDA confirms `0x004f2300` and `0x004f2310` as shared line-input text read/length helpers with broad typed-input caller fanout. Older output attached them to `QuitInputPane`, but IDA caller fanout places them in this reusable input-pane base source.
- IDA confirms [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md) is not a direct `LineInputPane` body: current class evidence places it in [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md), with `LineInputPane::HandleKeyInput` used as the fallback delegate.
- IDA confirms [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) as a late constructor that calls `CharInputPane`, stores owning `FunctionObject0 *m_acceptAction` at `+0x108`, and has the exact half-open range `0x005b75d0-0x005b760e`. B009 Rule 26 reanalysis clears the active constructor C++ gate; feature-specific drop/give call-site logic remains in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) and concrete callback template support remains in [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
- B003 Rule 26 reanalysis identifies the action object used by the four drop/give item confirmation paths as [UID:000040][DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528](by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md), created by [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) and invoked through [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) after `ConfirmInputPane` accepts `y`/`Y`.
- B001-042 live IDA disassembly confirms the previously undocumented `0x004f29d0-0x004f2a05` `ConfirmInputPane` complete-destructor body between padding spans; it is now [UID:000365][0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor](by-memory/0x004f29d0-0x004f2a05.ConfirmInputPaneCompleteDestructor.md).
- 2026-05-26 IDA MCP vtable pass confirms the reusable input-pane vtable band at `0x0061ca58-0x0061ce20`; see [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md).
- 2026-06-05 IDA MCP refresh confirms `ConfirmInputPane` method starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`, the constructor callers from drop/give item-action prompt handlers, and the primary/secondary/tertiary vtable stores.
- 2026-06-20 B006 source-routing recheck confirms [UID:00018Z][0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks](by-memory/0x004f2e59-0x004f2e9b.InputPaneBaseAdjustorThunks.md) is a six-function compiler-thunk island, not source-authored input-pane code. `NumberInputPane`, `CharArgsInputPane`, `NumberArgsInputPane`, and `MultiLineInputPane` reuse the LineInputPane-family secondary/tertiary scalar deleting destructor slots rather than owning custom destructor bodies in that range.

## Data Caveats

- Older output left the `HandleKeyInput` body at `0x004f25a0` effectively absent after a local struct declaration. IDA decompilation confirms real Enter/Escape/Tab dismissal and owner notification behavior. Track this under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- Older helper/base labels such as `TextButtonExControlPane::~Pane` should be treated as shared pane-base teardown labels until the exact pane inheritance is resolved.
- Older output attached `0x004f2300` and `0x004f2310` to the quit-specific class, but IDA caller fanout shows they are shared input base helpers.
- Block-list add/delete prompts also call `0x004f2300` and `0x004f2310`; keep those helpers here and leave feature packet/state logic in [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).

## Cross-References

- [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:0001ME][0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4072.SayToUserNameInputPaneHistoryNavigation.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)

## Changes

- 2026-08-01 B005 UID0003VX header-channel support callback:
  - Kept `92/92`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` unchanged.
  - Recorded that [UID:00001P][CharInputPane](by-class/CharInputPane.md) contributes its complete declaration to generated `InputPanes.h`; its formal CPP includes that header and contributes only `[[CHILDREN]]` to `InputPanes.cpp`.
  - This placement supplies a complete `CharInputPane` base to feature-derived headers such as `SpellInputPanes.h` while preserving all exact child method ownership, compiler-only artifacts, unrelated input-pane inventory, and historical evidence.

- 2026-07-30 B008 UID00035P accepted ordinary implementation callback:
  - Raised the file page from `91/88` to `92/92` while preserving `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) now contributes the exact source-ready `LineInputPane::LineInputPane(const wchar_t *)` definition through `InputPanes.cpp`; [UID:000077][LineInputPane](by-class/LineInputPane.md) contributes the complete `0x108` declaration through `InputPanes.h`.
  - The constructor preserves both asset-layout branches, prompt/edit construction, `g_pBackPane`/`rootPaneLayerContext` attachment, EventDispatcher text-input guard, active UserPane slot lifecycle, and ChattingVarietyPane refresh without duplicating dependency definitions in this file.
  - Current source terminology is `GetTextWidth`, `g_useEpfAssets`, `g_pBackPane`, `rootPaneLayerContext`, `m_activeLineInputPane`, and `HandleKeyOrTextEvent(Event *)`. Earlier `MeasureTextWidth`, `g_useLargeInputPaneLayout`, generic attachment aliases, `m_pendingTargetObject`, `HandleKeyInput`, and raw `byte_`/`dword_` spellings remain dated historical reconstruction steps, not current source recommendations.
  - Source output requires one UID00035P constructor, one complete LineInputPane declaration with the two `+0x100/+0x104` fields, no target empty marker after the supervisor refresh, and no duplicate class or constructor emission.

- 2026-07-01 Agent-B011 [UID:0000K7] empty-emitter family implementation: raised from `90/86` to `91/88`, preserved `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, and recorded the accepted dispositions for all ten remaining `InputPanes.cpp` empty markers. Evidence/provenance: B011 report `tools/leaser/Agents/Agent-B011/research/0000K7-InputPanes-empty-emitter-family-source-quality.md`, live MCP session `supervisor_resume_20260629`, current generated `InputPanes.cpp`, B001 exact split report, and B009 ConfirmInputPane precedent.
- 2026-06-20 B003 ConfirmInputPane action-object support sync:
  - Score unchanged at `90/86`.
  - Added the concrete FunctionObjects action-object route for drop/give item confirmations.
- 2026-06-21 B009 ConfirmInputPane constructor source-quality sync:
  - Score unchanged at `90/86`.
  - Recorded that [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) now emits constructor C++ through `InputPanes.cpp`, with `m_acceptAction` typed as `FunctionObject0*`; drop/give construction remains in `ItemActionInputPanes.cpp` and callback-template support remains in `FunctionObjects`.
- 2026-06-11 Agent-B001 B001-042:
  - Before: `InputPanes` was `88/84`, the broad input-pane base aggregate had only two exact child pages, and most class pages sat below the strict `85/85` parent gate.
  - After: `InputPanes` is `90/86`; [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) is a non-emitting split aggregate; exact child pages cover every source-bearing method in the compact cluster; and direct class parents now clear `85/85`.
  - Evidence: B001-042 live IDA `lookup_funcs`, byte/padding checks, decompilation/disassembly, caller/xref checks, and vtable ownership evidence across the `0x004f1c00-0x004f3017` cluster.
- 2026-06-02: Filled `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
  - Before: prose and `by-project-structure/proposed-source-tree.md` both placed `InputPanes.cpp` under `ui/dialogs/`, but the validator-managed path was blank.
  - After: the projected path now matches the existing source-tree placement.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ui/dialogs/InputPanes.cpp`, and this page's status/proposed source file already names the same folder.

### 2026-05-28 - Corrected InputPaneBases terminal byte

- What existed before: `InputPanes` file-level contents listed the base cluster as ending at `0x004f3016`.
- What changed: the compact base cluster now ends at `0x004f3017`.
- Evidence: IDA MCP shows `sub_4F2FB0` ending at `0x004f3017`; `0x004f3016` is the final byte of the `ConfirmInputPane` scalar deleting destructor's `retn 4`, while `0x004f3017-0x004f3020` is alignment before the next helper.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: reusable typed input-pane family, class inventory, vtable family, non-contiguous history/confirmation helpers, data caveats, and feature-module boundaries are documented; confidence is capped by exact original filename and base-owner pollution.
- 2026-06-05 ConfirmInputPane refresh:
  - Before: the page still carried stale output-provenance wording and listed the late constructor as ending at `0x005b760d`.
  - After: evidence basis now cites IDA MCP and current project docs only, and the `ConfirmInputPane` late constructor is documented as `0x005b75d0-0x005b760e`.
  - Evidence: current IDA MCP confirms constructor size `0x3e`, `CharInputPane` base construction, `this + 0x108` action-object storage, vtable stores, and four item-action construction callers.
- 2026-06-06 LineInputPane boundary refresh:
  - Before: the proposed contents still treated the `0x005b3e80` chat history helper as part of the `LineInputPane` range and did not call out the `0x004f2010` cleanup body or linked prompt setter.
  - After: the `LineInputPane` row now stays on the compact base cluster, boundary notes list constructor/cleanup/prompt/text-helper spans, and the history helper is described as `SayToUserNameInputPane` code that delegates to the shared base key handler.
  - Evidence: 2026-06-06 IDA MCP `lookup_funcs`, `decompile`, byte checks, and the updated [UID:000077][LineInputPane](by-class/LineInputPane.md) / [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md) pages.
