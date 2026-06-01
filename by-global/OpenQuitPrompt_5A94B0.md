*** UID:0000TD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OpenQuitPrompt_5A94B0

## Status

- Confidence: strong for function behavior and boundary.
- Address range: [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- Symbol kind: free helper / quit prompt launcher.
- Likely owner file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- Current generated owner: not emitted as a standalone active class body during this pass.

## Behavior

`OpenQuitPrompt_5A94B0` is a mode-gated quit confirmation launcher.

Observed behavior:

- reads mode byte `byte_66DA97`;
- when the byte is `1`, allocates `0x270` bytes and constructs [UID:0000BG][QuitDialog](by-class/QuitDialog.md);
- otherwise checks [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) and avoids creating a duplicate typed prompt;
- allocates `0x108` bytes, constructs [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md), stores the singleton, and installs its vtables;
- uses localized string id `3` for both prompt variants.

## Evidence

- IDA MCP `lookup_funcs 0x005a94b0` reports `sub_5A94B0`, size `0x122`.
- IDA MCP `callers 0x005a94b0` reports a direct call from `0x005a5cc8` inside `sub_5A5BD0`.
- IDA MCP `xrefs_to 0x005a94b0` also reports a code thunk/reference at `0x005a5a80`.
- IDA decompilation shows explicit `QuitDialog` and `QuitInputPane` vtable installation and singleton writes to `dword_69BF5C`.

## Source Placement

Keep this helper with `QuitDialogs.cpp`. It owns the choice between the modal alert and typed-input quit prompt, while [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) only owns the menu action that can reach the quit flow.

## Cross-References

- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented quit prompt launcher behavior, caller/xref evidence, vtable/singleton writes, and source placement but remained unevaluated.
  - After: score reflects documented mode-gated prompt selection, constructor targets, singleton handling, localized string use, and QuitDialogs ownership.
  - Evidence: IDA notes confirm function size, call/reference sites, explicit `QuitDialog`/`QuitInputPane` vtable installation, and `dword_69BF5C` singleton writes.
