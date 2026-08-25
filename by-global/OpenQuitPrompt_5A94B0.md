*** UID:0000TD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void OpenQuitPrompt();

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# OpenQuitPrompt_5A94B0

## Status

- Confidence: very strong for function behavior, void source signature, boundary, both caller routes, source-level branches, inline constructor semantics, and QuitDialogs ownership.
- Address range: [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- Symbol kind: free helper / quit prompt launcher.
- Likely owner file: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)

## Behavior

`OpenQuitPrompt` is the source-facing descriptive name for the mode-gated quit confirmation launcher. The address-suffixed page title remains useful provenance; it is not emitted as a source symbol.

Observed behavior:

- reads [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) / historical IDA alias `byte_66DA97`;
- when the byte is `1`, allocates `0x270` bytes and constructs [UID:0000BG][QuitDialog](by-class/QuitDialog.md);
- otherwise checks [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md) and avoids creating a duplicate typed prompt;
- allocates `0x108` bytes and constructs [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) when the typed singleton is clear; compiler-inlined `Singleton<QuitInputPane>` construction publishes the backing pointer and derived construction installs its vptrs;
- uses localized string id `3` for both prompt variants.

The typed branch contains the same normalized operation order as exact child [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md): localized id `3`, `CharInputPane` base construction, adjusted direct `Singleton<QuitInputPane>` publication, and three compiler-generated derived vptr stores. The launcher adds allocation/null/EH context, so it is an inline-equivalent sequence rather than a byte duplicate. The target remains the unique retained out-of-line constructor definition; the launcher is the live free entry helper. Virtual confirmation behavior remains on [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md).

Both callers ignore EAX and the helper has only side effects, establishing a `void` source signature. Source-level behavior is exactly a `g_useEpfAssets` branch that constructs a modal `QuitDialog`, otherwise a null-guarded construction of `QuitInputPane`. Allocation helpers, constructor inlining, null/EH cleanup, adjusted Singleton stores, and vptr stores are compiler output and are absent from the managed child definition.

## Evidence

- IDA MCP `lookup_funcs 0x005a94b0` reports `sub_5A94B0`, size `0x122`.
- IDA MCP `callers 0x005a94b0` reports a direct call from `0x005a5cc8` inside `sub_5A5BD0`.
- IDA MCP `xrefs_to 0x005a94b0` also reports a code thunk/reference at `0x005a5a80`.
- IDA decompilation shows explicit `QuitDialog` and `QuitInputPane` vtable installation and singleton writes to `dword_69BF5C`.
- IDA MCP recheck on 2026-06-05 confirmed `sub_5A94B0`, size `0x122`, direct caller `0x005a5cc8`, and constructor/setup callees in the quit-dialog family.
- 2026-06-14 A003 live IDA MCP refresh reconfirmed `sub_5A94B0` as `0x122` / `290` bytes (Verified with int_convert.py), with one direct caller (`sub_5A5BD0`) and a separate 5-byte code thunk/reference at `0x005a5a80`.
- 2026-06-14 decompilation shows the `g_useEpfAssets` / historical `byte_66DA97` branch exactly: value `1` allocates `0x270` / `624` bytes (Verified with int_convert.py), fetches localized string id `3`, calls the modal quit-dialog setup path, and installs the three `QuitDialog` vtable views.
- 2026-06-14 decompilation shows the non-EPF path checks [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md), allocates `0x108` / `264` bytes (Verified with int_convert.py) only when the singleton is clear, calls the typed-input setup path, stores or clears the singleton, and installs the three `QuitInputPane` vtable views.
- 2026-06-14 `xrefs_to 0x0069bf5c` reconfirmed exactly five singleton refs: duplicate guard and publish/fallback-clear inside this launcher, constructor-shaped publish at `0x005adcf2`, and scalar-deleting destructor clear at `0x005b7b36`.
- The direct call at `0x005a5cc8` is the UserPane quit-key case (`0x51`). The five-byte thunk at `0x005a5a80` is reached from IconsPane action case `7` at `0x004cf712`; retained raw action-dispatch code at `0x004cf949` references the same thunk but remains a separate no-route duplicate.
- The launcher contains 92 instructions in exact range `0x005a94b0-0x005a95d2`; `0x005a95d2-0x005a95e0` is fourteen bytes of external `0xcc` alignment.
- Current source names/types used by the formal route are already supported: `bool g_useEpfAssets`, complete `QuitDialog` and `QuitInputPane` class declarations, and the typed `QuitInputPane *g_pQuitInputPane` backing pointer.
- The current `STR.RES` payload decodes zero-based id `3` as `Do you really want to leave? (Y/N) `. The launcher must preserve lookup/construction source and never hard-code that English resource text.

## Source Placement

Keep this helper with `QuitDialogs.cpp`. It owns the choice between the modal alert and typed-input quit prompt, while UserPane and IconsPane only own trigger sites and [UID:0000L8][MenuVarietyPanes](by-file/MenuVarietyPanes.md) only owns menu selection. `InputPanes.cpp` owns the inherited base classes, not this policy helper.

## Autogen And Score Rationale

- Owner/emitter route remains [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md), which has a valid `NexusTK/ui/dialogs/` reconstruction path and surfaces to `auto-generated/NexusTK/ui/dialogs/QuitDialogs.cpp` without a dead end.
- Completion is `91` because this page now records the exact function range/size/instruction count/padding, void signature, direct and thunk caller routes, branch predicate, source-level class construction, allocation sizes, localized id/resource ownership, inline target normalization, Singleton source cause, vtable/EH exclusions, source placement, complete declaration/child route, and rejected owner distinctions.
- Confidence is `93` because live IDA decompilation, caller/thunk xrefs, class declarations, direct Singleton RTTI, complete-size evidence, and five physical singleton xrefs agree. Original debug spelling for the helper and TU is unavailable, so the descriptive `OpenQuitPrompt` name and file route remain below `95+` certainty.

## Cross-References

- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BG][QuitDialog](by-class/QuitDialog.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0000S1][g_pQuitInputPane](by-global/g_pQuitInputPane.md)
- [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md)
- [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md)

## Changes

- 2026-07-14 B003 UID0003ZQ callback: raised `86/90` to `91/93`; installed the exact `void OpenQuitPrompt();` declaration and `[[CHILDREN]]` route; added both live caller routes, 92-instruction/14-byte-padding facts, source-level branch/new semantics, inline constructor/Singleton evidence, prompt resource ownership, compiler exclusions, source placement, and updated score rationale; historicalized the former blank-C++ blocker while preserving the address-suffixed page title as provenance.
- 2026-05-30: Grading changed from `0/0` to `82/88`.
  - Before: page documented quit prompt launcher behavior, caller/xref evidence, vtable/singleton writes, and source placement but remained unevaluated.
  - After: score reflects documented mode-gated prompt selection, constructor targets, singleton handling, localized string use, and QuitDialogs ownership.
  - Evidence: IDA notes confirm function size, call/reference sites, explicit `QuitDialog`/`QuitInputPane` vtable installation, and `dword_69BF5C` singleton writes.
- 2026-06-05: Marked reconstructable and attached to [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).
  - Reason: live IDA MCP recheck confirms a source-authored quit prompt launcher with quit-dialog constructor/setup behavior and a quit-menu caller, so the helper belongs with QuitDialogs.
- 2026-06-07 A008 alias cleanup:
  - Normalized the mode-byte evidence to canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md), retaining `byte_66DA97` as the historical IDA lookup alias.
- 2026-06-14 A003 goal2 score pass: raised `82/88` to `86/90`.
  - Evidence: live IDA MCP reconfirmed `0x005a94b0` as a `0x122` / `290`-byte launcher (Verified with int_convert.py), one direct caller plus the 5-byte thunk/reference, the `g_useEpfAssets` branch, modal `0x270` / `624`-byte allocation, typed `0x108` / `264`-byte allocation, localized id `3`, and all five `g_pQuitInputPane` singleton refs.
  - Code-entry decision: no reconstruction C++ was added; the emitted route is valid and the score gate is now met, but mode-byte naming and source-quality helper/class setup declarations remain unresolved. The raw constructor representation was later resolved through exact child [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md).
- 2026-06-22 Rule 26 support sync from B013 `QuitInputPaneCore`:
  - Score unchanged at `86/90`.
  - Summary/evidence: added the exact constructor/handler child links and removed the stale implication that the raw `QuitInputPane` constructor shape is unresolved. The launcher still emits no C++ because original launcher naming, mode-byte spelling, modal setup helper signature, and class/header declarations remain broader support items.
