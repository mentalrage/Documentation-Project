*** UID:0000S1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pQuitInputPane

## Status

- Address: `0x0069bf5c` (`dword_69BF5C` in IDA)
- Symbol kind: process-wide singleton pointer
- Primary memory doc: [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- Likely owner file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- Confidence: strong.

## Purpose

`g_pQuitInputPane` points to the active typed quit confirmation prompt. It prevents duplicate `QuitInputPane` creation in the older quit-confirmation path and is cleared when the prompt is destroyed.

## Evidence

- Live IDA MCP check on 2026-05-30 confirms `0x0069bf5c` is `dword_69BF5C`, a 4-byte `.data` item.
- IDA data xrefs to `0x0069bf5c` are `0x005a954d`, `0x005a9597`, `0x005a959e`, `0x005adcf2`, and `0x005b7b36`.
- `0x005a954d` in [UID:0000TD][OpenQuitPrompt_5A94B0](by-global/OpenQuitPrompt_5A94B0.md) compares `dword_69BF5C` against zero and branches away from allocation when an active pane already exists.
- `0x005a9597` stores the adjusted constructed pointer into `dword_69BF5C`; `0x005a959e` stores zero on the null-allocation path. The nearby instructions assign the three `QuitInputPane` vftables.
- `0x005adcc0` constructs [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md), then stores the adjusted object pointer into `dword_69BF5C`.
- `0x005adcf2` is not currently inside an IDA function, but the instruction window around it stores `eax` into `dword_69BF5C` immediately before `QuitInputPane` vftable writes at `0x005adcf9`, `0x005adcff`, and `0x005add09`.
- `0x005b7b30` clears `dword_69BF5C` at `0x005b7b36` before calling `sub_4F2010` and honoring the scalar-deleting destructor flag.

## Caveat

Do not confuse this singleton with `0x0069b504`. Live IDA names `0x0069b504` as `puDeviceID`; its xrefs are in the `0x00525920`/`0x00525dc0` device-ID block, not the quit input flow. The quit input singleton is `0x0069bf5c`.

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)

## Changes

- 2026-05-30: What existed before: the page had the correct singleton address and high-level behavior but no completion/confidence grade and only a compact xref summary. What changed: set completion/confidence to `82/88` and expanded the evidence with live IDA MCP storage, xref, allocation, constructor, and destructor details. Summary/evidence: IDA reports `0x0069bf5c` as a 4-byte `.data` item with five data xrefs; the checked instruction windows show duplicate-prevention, assignment after construction, null-path clearing, and destructor clearing. The score is below 100 because `0x005adcf2` is not currently attached to an IDA function and source-level file/function names still need final reconstruction.
