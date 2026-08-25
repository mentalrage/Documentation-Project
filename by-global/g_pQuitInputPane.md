*** UID:0000S1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
QuitInputPane *g_pQuitInputPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pQuitInputPane

## Status

- Address: `0x0069bf5c` (`dword_69BF5C` in IDA).
- Symbol kind: process-wide `QuitInputPane *` singleton pointer.
- Primary storage doc: [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md).
- Source owner: [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md).
- Class owner/consumer: [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md).
- Source definition: `QuitInputPane *g_pQuitInputPane = NULL;` in `NexusTK/ui/dialogs/QuitDialogs.cpp`; [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) carries the matching `extern` declaration.
- Confidence: very strong for address, zero initialization, typed backing-pointer purpose, direct `Singleton<QuitInputPane>` lifecycle source cause, source owner, class declaration route, and one-definition placement.

## Purpose

`g_pQuitInputPane` points to the active legacy typed quit confirmation prompt. It is the backing pointer used by the direct empty `Singleton<QuitInputPane>` base and the source-level duplicate guard in `OpenQuitPrompt`. Compiler-inlined Singleton construction publishes it; Singleton destruction clears it before inherited input-pane teardown.

The singleton belongs to `QuitDialogs.cpp` because it is part of the typed quit prompt source family. It is not owned by `UserPane`; `UserPane` only reaches the quit prompt launcher through the quit key path. It is not owned by `MapPane` or `TimerMgr`; those are affirmative-path callees from `QuitInputPane::OnConfirmInput()`.

## Initial State And Storage

The exact four-byte storage is [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md). Fresh MCP reads return `00 00 00 00`. PE mapping places the address in the `.data` virtual tail beyond raw-backed end `0x0067a800`, so the loader supplies zero initialization. Historical `0xffffffff` text was an unbacked-file interpretation and is superseded.

The source-facing definition uses `NULL`, matching project-era style and every runtime compare/clear. The global page owns the sole emitted definition; the exact storage page remains formally blank to prevent duplicate source definitions.

## Lifecycle Evidence

| Address | Function/range | Access | Meaning |
| --- | --- | --- | --- |
| `0x005a954f` | [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) | compare against zero | Launcher duplicate guard for legacy typed quit prompt. |
| `0x005a9598` | [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) | store adjusted complete pointer | Launcher-inline `Singleton<QuitInputPane>` construction publishes the new prompt. |
| `0x005a95a0` | [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) | store zero | Compiler null-adjustment/EH fallback; not a separate source clear. |
| `0x005adcf3` | [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) | store adjusted complete pointer | Retained constructor's direct Singleton base publishes the prompt. |
| `0x005b7b38` | [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md) | store zero | Implicit Singleton base destruction clears before CharInputPane teardown. |

The accepted B013 source-quality pass performed a PE-aware route scan and confirmed these as the complete physical access set. B003's direct RTTI pass resolves the source cause: `Singleton<QuitInputPane>` has TypeDescriptor `0x00679c54` and non-virtual PMD `0x108/-1/0`, exactly matching the adjusted publication and reverse destruction order. Earlier offsets in older notes sometimes appear as `0x005a954d`, `0x005a9597`, `0x005a959e`, `0x005adcf2`, and `0x005b7b36` due instruction-start/display differences; the physical lifecycle meaning is unchanged.

## Constructor And Launcher Relationship

[UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md) and [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md) both:

- use localized prompt id `3`;
- initialize the `CharInputPane` base/input-pane state;
- construct the direct Singleton base, whose compiler lowering publishes this backing pointer;
- install the three `QuitInputPane` vtable views at `0x0062f054`, `0x0062f0a4`, and `0x0062f0d4`.

The duplicated construction shape proves compiler inlining and `QuitInputPane` identity. It does not make the launcher the source owner of the constructor definition. The launcher is the live free entry; the constructor child is the unique retained out-of-line source definition. Exhaustive scans found no target-address route, while UserPane and IconsPane reach the launcher.

## Reconstruction Policy

This global is reconstructable and routes through [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md). Its formal block is the one source definition, while [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md) supplies the matching external declaration and direct Singleton base. Constructor/destructor children carry the source anchors whose compiler-generated base lifetime performs the physical publish/clear operations:

- [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)

[UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md) consumes the active pane's inherited state but does not directly read or write this global.

## Caveat

Do not confuse this singleton with `0x0069b504`. Live IDA names `0x0069b504` as `puDeviceID`; its xrefs are in the `0x00525920` / `0x00525dc0` device-ID block, not the quit input flow. The quit input singleton is `0x0069bf5c`.

## Score Rationale

Completion is `90` because the page records the exact address, zero-filled storage child, source/class owner, all five physical accesses, direct Singleton publication/destruction cause, launcher/constructor relationship, typed-prompt duplicate guard, unrelated-global rejection, matching extern route, single-definition policy, and exact formal source definition.

Confidence is `94` because the complete xref set, direct Singleton RTTI/PMD/EBO, launcher behavior, constructor child, exact PE/MCP storage state, destruction order, complete class declaration, and `QuitDialogs.cpp` route agree. Original linkage/debug spelling is unavailable, so `95+` is not claimed.

## Cross-References

- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)
- [UID:0000BH][QuitInputPane](by-class/QuitInputPane.md)
- [UID:0001Q2][0x0069bf5c-0x0069bf60.g_pQuitInputPane](by-memory/0x0069bf5c-0x0069bf60.g_pQuitInputPane.md)
- [UID:0001KS][0x005adcc0-0x005add8a.QuitInputPaneCore](by-memory/0x005adcc0-0x005add8a.QuitInputPaneCore.md)
- [UID:0003ZQ][0x005adcc0-0x005add18.QuitInputPaneConstructor](by-memory/0x005adcc0-0x005add18.QuitInputPaneConstructor.md)
- [UID:0003ZR][0x005add20-0x005add8a.QuitInputPaneConfirmInput](by-memory/0x005add20-0x005add8a.QuitInputPaneConfirmInput.md)
- [UID:0001NC][0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor](by-memory/0x005b7b30-0x005b7b75.QuitInputPaneScalarDeletingDestructor.md)
- [UID:0001KP][0x005a94b0-0x005a95d2.QuitPromptLauncher](by-memory/0x005a94b0-0x005a95d2.QuitPromptLauncher.md)

## Changes

- 2026-07-14 B003 UID0003ZQ callback: score/formal/owner route unchanged at `90/94`; preserved exact zero storage, one definition, all five physical sites, duplicate guard, and unrelated-global rejection; added direct Singleton TypeDescriptor/PMD/EBO source cause, live inline launcher relationship, retained out-of-line disposition, and historicalized the former handwritten constructor/destructor publish/clear interpretation.
- 2026-07-14 B004 UID0001NC callback: raised `88/91` to `90/94`, inserted the sole source definition `QuitInputPane *g_pQuitInputPane = NULL;`, proved loader-zeroed virtual-tail storage, finalized the class extern/source-file route and one-definition policy, preserved all five lifecycle sites, and historicalized the stale `0xffffffff`/deferred-placement state.
- 2026-06-19 B013 implementation: raised `86/90` to `88/91`, replaced compact lifecycle notes with exact launcher guard/publish/fallback-clear, constructor publish, and destructor clear table, added child split links, clarified the launcher/constructor relationship, and preserved the declaration-no-code policy for the global.
