*** UID:0000MX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# QuitDialogs

## Status

- Confidence: strong for class grouping and `ui/dialogs/` placement; medium-high for final split between menu launcher and dialog implementation.
- Proposed module folder: `ui/dialogs/`
- Candidate file: `NexusTK/ui/dialogs/QuitDialogs.cpp`
- Current generated sources: `class_QuitDialog.cpp` and `class_QuitInputPane.cpp`.
- Evidence basis: `simroot_v2` generated files, Wave3 metadata, and targeted IDA MCP checks on 2026-05-24. `wave3.py` was not used because `wave3-status.md` was marked `DEBUGGING`.

## Hypothesis

`QuitDialogs.cpp` should own the client quit confirmation UI used by the in-game menu. The modern path presents an [UID:0000HE][AlertPanes](by-file/AlertPanes.md)-derived Yes/No modal, while an older typed prompt path uses a [UID:00001P][CharInputPane](by-class/CharInputPane.md)-derived `QuitInputPane`.

Likely structure:

```text
ui/dialogs/QuitDialogs.cpp
```

Possible placement:

```text
ui/menu/QuitDialogs.cpp
```

The menu selector should only dispatch the quit action. The confirmation dialog implementation should not be folded into [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md).

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) | `0x005a94b0-0x005a95d2` | not emitted as a standalone class file | Mode-gated quit prompt launcher that chooses `QuitDialog` or `QuitInputPane`. |
| [UID:0000BG][QuitDialog](by-class/QuitDialog.md) | `0x005addf0-0x005adf2e` | `class_QuitDialog.cpp` | Modal Yes/No quit confirmation built on `AlertPane`. |
| [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) | `0x005adcc0-0x005add8a`, `0x005b7836-0x005b784c`, `0x005b7b30-0x005b7b75` | `class_QuitInputPane.cpp` | Older typed quit prompt built on `CharInputPane`; `y`/`Y` returns to main menu. The `0x005b7836-0x005b784c` adjustor thunks are compiler glue in [UID:0000VN][-ignored](by-memory/-ignored.md). |
| [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) | [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md) | `class_QuitInputPane.cpp` | Active typed quit prompt singleton. |

## IDA MCP Evidence

Targeted checks on 2026-05-24 confirmed:

- `OpenQuitPrompt_5A94B0` is a real function at `0x005a94b0`, size `0x122`. It is called from `0x005a5cc8` and has a thunk/reference at `0x005a5a80`.
- `QuitInputPane` constructor bytes at `0x005adcc0-0x005add18` are real and install `QuitInputPane` vtables, but the current IDA database does not mark `0x005adcc0` as a function.
- `QuitInputPane::OnConfirmInput` is `0x005add20-0x005add8a`; it reads one character, accepts only `Y`/`y`, unregisters the player timer handler, and returns to main menu.
- `QuitDialog` functions are `0x005addf0-0x005ade40`, `0x005ade40-0x005adedb`, and `0x005adf20-0x005adf2e`.
- `QuitInputPane` destructor adjustors are `0x005b7836-0x005b784c`; the scalar deleting destructor is `0x005b7b30-0x005b7b75`.
- `g_pQuitInputPane` is `dword_69BF5C` at `0x0069bf5c`, written by the typed-prompt constructor/launcher and cleared by the destructor.
- 2026-05-26 recheck confirms `0x005b7836-0x005b784c` are compiler-generated destructor adjustor thunks; model the `QuitInputPane` destructor/inheritance, not handwritten thunk functions.

2026-06-02 IDA MCP refresh confirmed:

- `OpenQuitPrompt_5A94B0` remains `0x005a94b0-0x005a95d2`, called from `0x005a5cc8`; it chooses the modal `QuitDialog` path when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1` and otherwise creates a singleton typed `QuitInputPane`.
- `lookup_funcs` still reports `0x005adcc0` and `0x005add18` as `Not a function`, while `0x005add20` is `sub_5ADD20`, size `0x6a`, ending at `0x005add8a`.
- `disasm 0x005adcc0` shows constructor-shaped bytes through `0x005add17`, then `0xcc` alignment bytes through the modeled handler start at `0x005add20`.
- `decompile 0x005add20` confirms one-character `Y/y` handling, timer unregister through `0x00597a10`, and main-menu/parcel transition through `0x005047f0`; non-confirming input calls `0x00544690`.
- `xrefs_to 0x0069bf5c` still reports duplicate prevention/allocation writes from `OpenQuitPrompt`, constructor-shaped singleton write at `0x005adcf2`, and destructor clear at `0x005b7b36`.
- `xrefs_to 0x0062f0a4` and `0x0062f0d4` reports `QuitInputPane` vtable writes in both `OpenQuitPrompt` and the raw constructor-shaped body.

## Ownership Notes

- `ReadInputText` at `0x004f2300` and `GetInputLength` at `0x004f2310` are shared [UID:000077][LineInputPane](by-class/LineInputPane.md) helpers with broad caller fanout. They are emitted in `class_QuitInputPane.cpp`, but they should remain in [UID:0000K7][InputPanes](by-file/InputPanes.md).
- `QuitDialog` is launched from [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md) and from `OpenQuitPrompt_5A94B0`. The selector owns the menu row and click dispatch, not the dialog implementation.
- `OpenQuitPrompt_5A94B0` chooses the modal dialog path when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97` is `1`; otherwise it creates the older typed input prompt if `g_pQuitInputPane` is null.
- The generated constructor code labels [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md) / `dword_67A740` as `g_pReconnectServer`. Treat that parent/context pointer name as provisional until the broader main-menu/global pass confirms it.

## Cross-References

- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0001KT][0x005addf0-0x005adf2e.QuitDialogCore](by-memory/0x005addf0-0x005adf2e.QuitDialogCore.md)
- [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)
- [UID:00028J][0x0067a740-0x0067a744.g_pBackPane](by-memory/0x0067a740-0x0067a744.g_pBackPane.md)
- [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)

## Changes

- 2026-06-07 A005 resolved-name cleanup:
  - Before: quit-dialog source grouping notes used only historical `dword_67A740`.
  - After: the page records canonical `g_pBackPane` beside the historical label and cross-links the global page.
  - Evidence: generated resolved-name report maps `dword_67A740` to `g_pBackPane`; existing source grouping notes already identify the value as the quit-dialog parent/context pointer.
- 2026-06-07 A008 alias cleanup: normalized the `OpenQuitPrompt_5A94B0` `byte_66DA97` branch to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), preserving `byte_66DA97` as the IDA lookup alias.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents quit prompt grouping, modal/typed paths, global singleton, IDA evidence, shared input helper boundary, generated-name caveat, and cross-references; confidence remains capped by final folder/name uncertainty.
- 2026-06-02: Raised to `86/82` and added `NexusTK/ui/dialogs/` reconstruction path.
  - Evidence: fresh IDA MCP revalidated the launcher, modal/typed branch behavior, raw typed-prompt constructor, modeled input handler, singleton xrefs, destructor clear, and vtable-store map. The remaining uncertainty is source-file split rather than feature ownership.
