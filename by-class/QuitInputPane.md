*** UID:0000BH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# QuitInputPane

## Status

- Confidence: strong for behavior and `QuitDialogs.cpp` ownership; medium-high for raw constructor modeling.
- Likely source file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- Core address range: [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- Destructor ranges: [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md) and [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- Singleton storage: [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_QuitInputPane.cpp`

## Class Purpose

`QuitInputPane` is an older typed quit confirmation prompt built on [UID:00001P][CharInputPane](by-class/CharInputPane.md). It prompts with localized string id `3`, stores itself in [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md), and only accepts a one-character `Y` or `y` response as confirmation.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x005adcc0-0x005add18` | `QuitInputPane::QuitInputPane()` | Calls `CharInputPane`, stores `g_pQuitInputPane`, and installs three vtable views. IDA currently does not define this as a function. |
| `0x005add20-0x005add8a` | `OnConfirmInput()` | Reads one input character. On `Y/y`, unregisters the player timer handler and returns to main menu; otherwise marks the pane for deletion. |
| `0x005b7836-0x005b784c` | destructor adjustor thunks | Compiler-generated secondary/tertiary adjustor thunks now listed in [UID:0000VN][-ignored](by-memory/-ignored.md); adjust `this` from secondary bases and tail-call the scalar deleting destructor. |
| `0x005b7b30-0x005b7b75` | scalar deleting destructor | Clears `g_pQuitInputPane`, tears down the input-pane base, and conditionally deletes. |

## Shared Helper Caveat

Active `class_QuitInputPane.cpp` also emits:

| Address | Current emitted name | Correct ownership |
| --- | --- | --- |
| `0x004f2300-0x004f230f` | `QuitInputPane::ReadInputText` | Shared [UID:000077][LineInputPane](by-class/LineInputPane.md) text-copy helper. |
| `0x004f2310-0x004f231b` | `QuitInputPane::GetInputLength` | Shared [UID:000077][LineInputPane](by-class/LineInputPane.md) input-length helper. |

IDA caller fanout shows these helpers are used by many typed input panes, so they belong in [UID:0000K7][InputPanes](by-file/InputPanes.md), not in this quit-specific source.

## Evidence Notes

- IDA MCP `disasm 0x005adcc0` confirms constructor-shaped bytes from `0x005adcc0` through `0x005add17`, including `CharInputPane` construction and `dword_69BF5C` storage.
- IDA MCP `decompile 0x005add20` confirms exact `Y/y` handling, timer unregister call, and parcel/main-menu transition.
- IDA MCP `decompile 0x005b7b30` confirms the destructor clears `dword_69BF5C` before calling the input-pane base destructor.
- IDA MCP `lookup_funcs 0x005adcc0` still reports `Not a function`; keep this as a raw/projected constructor boundary until IDA/Wave3 function ownership is repaired.
- IDA MCP `xrefs_to 0x005b7836` and `0x005b7841` shows vtable data refs at `0x0062f0a4` and `0x0062f0d4`.
- 2026-05-26 recheck: `0x005b7836-0x005b784c` is compiler-generated thunk glue, now listed in [UID:0000VN][-ignored](by-memory/-ignored.md).
- `OpenQuitPrompt_5A94B0` also creates this class in the non-modal quit prompt path, guarded by `g_pQuitInputPane`.
- 2026-06-02 IDA MCP refresh confirms `0x005add20-0x005add8a` as the modeled handler, no direct callers for `0x005add20`, vtable data reference at `0x0062f09c`, `g_pQuitInputPane` writes from `OpenQuitPrompt` and raw constructor bytes, and `g_pQuitInputPane` clear in the scalar deleting destructor.
- 2026-06-02 raw byte read confirms the constructor-shaped body `0x005adcc0-0x005add18`, eight `0xcc` alignment bytes at `0x005add18-0x005add20`, the modeled handler body `0x005add20-0x005add8a`, and alignment bytes at `0x005add8a-0x005add90`.

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0001N7][0x005b7836-0x005b784c.QuitInputPaneDestructorThunks](by-memory/0x005b7836-0x005b784c.QuitInputPaneDestructorThunks.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0000K7][InputPanes](by-file/InputPanes.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/82`.
  - Before: The page was unevaluated though it documented constructor bytes, singleton storage, confirm behavior, destructor thunks, shared helper caveats, and evidence.
  - After: Scored as high completion and strong confidence with final source grouping still treated as medium uncertainty.
  - Evidence: Existing method map, shared helper caveat, IDA MCP evidence notes, singleton cross-references, and `OpenQuitPrompt` relationship cover the class behavior.
- 2026-06-02: Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).
  Evidence: parent file now has strong `ui/dialogs/QuitDialogs.cpp` confidence, and current IDA MCP revalidates the class-specific constructor/handler/destructor/singleton evidence.
