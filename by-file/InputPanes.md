*** UID:0000K7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# InputPanes

## Status

- Confidence: strong for reusable input-pane base family and corrected LineInputPane method boundaries; medium for exact original filename and final source split details.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/InputPanes.cpp`
- Type docs: [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- Evidence basis: IDA MCP boundary, decompile, caller/callee, vtable, and byte checks, combined with current project-documentation cross-references.

## Hypothesis

`InputPanes.cpp` should own the reusable typed input prompt base classes used by item, command, chat, spell, and confirmation prompt panes. These classes are infrastructure for short in-game command prompts rather than feature-specific item/social command panes.

Feature-specific derivatives should stay in neighboring modules such as [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md), [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).

## Proposed Contents

| Entity | Current range | Source placement | Role |
| --- | --- | --- | --- |
| [UID:000077][LineInputPane](by-class/LineInputPane.md) | `0x004f1c00-0x004f2f62` | `InputPanes.cpp` | Base one-line prompt with label/edit child panes, prompt text setup, active input singleton state, Enter/Escape handling, shared cleanup, and text access helpers. |
| [UID:00009L][NumberInputPane](by-class/NumberInputPane.md) | `0x004f27a0-0x004f289a` | `InputPanes.cpp` | Numeric-only line input variant. |
| [UID:00001P][CharInputPane](by-class/CharInputPane.md) | `0x004f28a0-0x004f2faa` | `InputPanes.cpp` | Single-character accepting variant that dismisses the pane and notifies the owner after a printable character. |
| [UID:000035][ConfirmInputPane](by-class/ConfirmInputPane.md) | `0x004f2a10-0x004f2a57`, `0x004f2fb0-0x004f3017`, `0x005b75d0-0x005b760e` | `InputPanes.cpp` | Yes/no confirmation input wrapper over `CharInputPane`. |
| [UID:00001O][CharArgsInputPane](by-class/CharArgsInputPane.md) | `0x004f2a60-0x004f2b73` | `InputPanes.cpp` | Character-argument line input allowing letters, comma, and space. |
| [UID:00009J][NumberArgsInputPane](by-class/NumberArgsInputPane.md) | `0x004f2b80-0x004f2c84` | `InputPanes.cpp` | Numeric-argument line input allowing digits, comma, and space. |
| [UID:00008T][MultiLineInputPane](by-class/MultiLineInputPane.md) | `0x004f2c90-0x004f2dca` | `InputPanes.cpp` | Multi-line input variant; Enter submits/clears, Escape or Ctrl+C closes. |

## Boundary Notes

- IDA confirms the compact base cluster at `0x004f1c00-0x004f3017`; `0x004f3020` starts unrelated `EnsureServerSelectPane`.
- IDA confirms the early `LineInputPane` body sequence inside that cluster: constructor `0x004f1c00-0x004f2009`, shared cleanup/lifecycle body `0x004f2010-0x004f2092`, prompt setter [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md), and text helpers at `0x004f2300` / `0x004f2310`.
- IDA confirms `0x004f2300` and `0x004f2310` as shared line-input text read/length helpers with broad typed-input caller fanout. Older output attached them to `QuitInputPane`, but IDA caller fanout places them in this reusable input-pane base source.
- IDA confirms [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md) is not a direct `LineInputPane` body: current class evidence places it in [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md), with `LineInputPane::HandleKeyInput` used as the fallback delegate.
- IDA confirms [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md) as a late constructor that calls `CharInputPane`, stores the confirmation callback/action object, and has the exact half-open range `0x005b75d0-0x005b760e`.
- 2026-05-26 IDA MCP vtable pass confirms the reusable input-pane vtable band at `0x0061ca58-0x0061ce20`; see [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md).
- 2026-06-05 IDA MCP refresh confirms `ConfirmInputPane` method starts at `0x004f2a10`, `0x004f2fb0`, and `0x005b75d0`, the constructor callers from drop/give item-action prompt handlers, and the primary/secondary/tertiary vtable stores.

## Data Caveats

- Older output left the `HandleKeyInput` body at `0x004f25a0` effectively absent after a local struct declaration. IDA decompilation confirms real Enter/Escape/Tab dismissal and owner notification behavior. Track this under [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- Older helper/base labels such as `TextButtonExControlPane::~Pane` should be treated as shared pane-base teardown labels until the exact pane inheritance is resolved.
- Older output attached `0x004f2300` and `0x004f2310` to the quit-specific class, but IDA caller fanout shows they are shared input base helpers.
- Block-list add/delete prompts also call `0x004f2300` and `0x004f2310`; keep those helpers here and leave feature packet/state logic in [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md).

## Cross-References

- [UID:00018X][0x004f1c00-0x004f3017.InputPaneBases](by-memory/0x004f1c00-0x004f3017.InputPaneBases.md)
- [UID:00018Y][0x004f20a0-0x004f22f4.LineInputPaneSetPromptText](by-memory/0x004f20a0-0x004f22f4.LineInputPaneSetPromptText.md)
- [UID:0001XS][InputPaneBaseVtableFamily](by-type/by-vtable/InputPaneBaseVtableFamily.md)
- [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md)
- [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)

## Changes

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
