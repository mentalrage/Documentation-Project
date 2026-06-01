*** UID:0000SA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pSimpleHelpPane2

## Status

- Address: [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md)
- Symbol kind: process-wide singleton pointer.
- Likely owner file: [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- Current generated names: `g_pSimpleHelpPane2`, `dword_67A7D4`
- Confidence: strong.

## Purpose

`g_pSimpleHelpPane2` points to the active [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md), the `HelpPane`-derived tooltip with anchor-rectangle and auto-hide behavior. The adjacent factory at `0x004c7680` replaces any active instance before constructing a new one, while the raw helper cluster at [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) wraps factory calls and checks anchor/cursor state.

## Evidence Notes

- 2026-05-30 live IDA MCP storage check reports `0x0067a7d4` as a 4-byte `.data` item named `dword_67A7D4` with 9 data references.
- References include both the direct `SimpleHelpPane2` constructor path and [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md): constructor-like code at `0x004c751b` writes the active pointer and clears it on null fallback at `0x004c7522`; the factory reads/replaces the active singleton at `0x004c76ad`, stores the newly-created pane at `0x004c772a`, and clears on fallback at `0x004c7731`.
- Destructor/helper cleanup clears this singleton at `0x004c75fa`, `0x004ce320`, and `0x004ce520`.
- A UI feature caller at `0x00451adb` reads the pointer before using or closing the active `SimpleHelpPane2` tooltip.
- 2026-05-28 IDA MCP raw disassembly confirms [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md) immediately after the factory; the helper page does not add a new global, but it is part of the same singleton management neighborhood.
- 2026-05-30 live IDA MCP confirms [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md) includes `ClearSimpleHelpPane2Singleton` at `0x004ce320`, which writes zero to this storage from constructor/factory unwind cleanup.

## Cross-References

- [UID:0001OY][0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2](by-memory/0x0067a7d4-0x0067a7d8.g_pSimpleHelpPane2.md)
- [UID:0000JU][HelpPanes](by-file/HelpPanes.md)
- [UID:0000D7][SimpleHelpPane2](by-class/SimpleHelpPane2.md)
- [UID:00016T][0x004c7680-0x004c77e0.SimpleHelpPane2Factory](by-memory/0x004c7680-0x004c77e0.SimpleHelpPane2Factory.md)
- [UID:00022O][0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers](by-memory/0x004c77e0-0x004c78db.SimpleHelpPane2FactoryHelpers.md)
- [UID:00022P][0x004ce160-0x004ce34b.HelpTooltipSupportHelpers](by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md)
- [UID:00016S][0x004c6f90-0x004c7680.SimpleHelpPanes](by-memory/0x004c6f90-0x004c7680.SimpleHelpPanes.md)

## Changes

- What existed before: the page had correct address and role notes but unevaluated completion/confidence metadata and only summarized the xrefs.
- What changed to: the page now records the current live IDA MCP xref set for constructor, factory, cleanup, clear-helper, and UI caller paths. Completion/confidence were set to `78/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0067a7d4` / `dword_67A7D4` as a 4-byte `.data` singleton pointer with 9 xrefs: UI caller read at `0x00451adb`, constructor assignment/fallback at `0x004c751b`/`0x004c7522`, destructor/helper clear at `0x004c75fa`, factory read/write/fallback at `0x004c76ad`/`0x004c772a`/`0x004c7731`, and clear-helper/destructor cleanup at `0x004ce320`/`0x004ce520`.
