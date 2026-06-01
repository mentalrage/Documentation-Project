*** UID:0001Q5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-meta Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-meta`
- Coverage summary: 25 covered reconstructable rows, 0 covered ignored rows, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001Q7][client_anticheat](by-meta/client_anticheat.md) : reconstructable : 50% : medium : - Scope: client-side anti-cheat, anti-virus/process scanning, suspicious-input controls, and anti-modification checks where they are visible in the recovered client.
- [UID:0001Q8][client_audio](by-meta/client_audio.md) : reconstructable : 50% : medium : - Confidence: strong for current source-family split; medium for exact original folder name.
- [UID:0001Q9][client_callback_dispatch](by-meta/client_callback_dispatch.md) : reconstructable : 70% : strong : This page tracks reusable callback-object infrastructure used by UI, application, dialog, and panel code. It is a source-structure topic, not a packet or event-routing spec. Exa...
- [UID:0001QA][client_containers](by-meta/client_containers.md) : reconstructable : 70% : strong : This page tracks reusable collection/allocation primitives that cut across feature modules. Original-source ownership lives in `by-file`; exact address evidence lives in `by-mem...
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md) : reconstructable : 70% : strong : This page tracks process crash reporting, deliberate crash triggers, and related diagnostic reporting paths. Exact source ownership lives in `by-file`; exact address ranges live...
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md) : reconstructable : 50% : medium : - Confidence: medium for archive ownership, public APIs, mapped entry-table layout, and consumer/source split; weak for exact original on-disk field names and sentinel-row semantics.
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md) : reconstructable : 50% : medium : - Scope: Win32 input bridge, IME event routing, pane-side IME UI, and text-entry controls.
- [UID:0001QE][client_libraries](by-meta/client_libraries.md) : reconstructable : 50% : medium : - Confidence: medium; this page is a working index and should be expanded as source modules are reviewed.
- [UID:0001QF][client_localization](by-meta/client_localization.md) : reconstructable : 50% : medium : - Scope: localized text loading, numeric string-id lookup, and resource-level localization behavior.
- [UID:0001QG][client_map_system](by-meta/client_map_system.md) : reconstructable : 70% : strong : This page tracks the live game-world map system: map files, map packet dispatch, object indexing, weather/day-night effects, map companion panes, and source-file placement. Exac...
- [UID:0001QH][client_network](by-meta/client_network.md) : reconstructable : 50% : medium : - Confidence: medium
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md) : reconstructable : 50% : medium : - Confidence: medium for the 16-bit RGB565 surface path, open for the full old/new feature distinction.
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md) : reconstructable : 50% : medium : - Confidence: medium for retained compatibility/legacy render paths; open for the exact product-level mode switch.
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md) : reconstructable : 70% : strong : Catalog all opcodes, analyze what they do, and record the code that consumes or emits them. This page should stay as the index; detailed opcode families should live in `by-type/...
- [UID:0001QL][client_profile_storage](by-meta/client_profile_storage.md) : reconstructable : 50% : medium : - Confidence: strong for file paths and serialized layout; medium for final field names.
- [UID:0001QM][client_s1-startup](by-meta/client_s1-startup.md) : reconstructable : 50% : medium : - Confidence: medium; this is a working startup-flow index, not full coverage yet.
- [UID:0001QN][client_s2-main_menu](by-meta/client_s2-main_menu.md) : reconstructable : 50% : medium : - Scope: main menu through login/account dialog entry, excluding full character-creator internals.
- [UID:0001QO][client_s3-character-creation](by-meta/client_s3-character-creation.md) : reconstructable : 70% : strong : This is going to document the new character/charactercreator menu reached from the main menu of the game. This is going to have detailed information on function calls, libraries...
- [UID:0001QP][client_s4-login-process](by-meta/client_s4-login-process.md) : reconstructable : 70% : strong : This is going to document the login/authentication process that occurs when a new character is created as well as when a character is reseting password, and importantlly, loggin...
- [UID:0001QQ][client_s5-ui-and-gameworld-rendering](by-meta/client_s5-ui-and-gameworld-rendering.md) : reconstructable : 50% : medium : - Scope: live in-game UI/rendering, map panes, object panes, and rendering support needed after successful login.
- [UID:0001QR][client_s6-client-limiters](by-meta/client_s6-client-limiters.md) : reconstructable : 70% : strong : This is going to document specific areas of the client that limit player actions, intervals of actions, etc. The goal is a 100% reconstruction and the goals in to rebuild the cl...
- [UID:0001QS][client_string_handling](by-meta/client_string_handling.md) : reconstructable : 50% : medium : This page tracks client-level string utility findings. Source ownership lives in StringUtil; exact address evidence lives in `by-memory`.
- [UID:0001QT][client_threading](by-meta/client_threading.md) : reconstructable : 50% : medium : This page tracks client-level threading and synchronization behavior. File ownership decisions live in `by-file`; exact function boundaries live in `by-memory`.
- [UID:0001QU][client_timing](by-meta/client_timing.md) : reconstructable : 70% : strong : This page tracks client-level timing and scheduler behavior. Source ownership decisions live in `by-file`; exact address evidence lives in `by-memory`.
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md) : reconstructable : 50% : medium : - Scope: reusable UI base classes, pane tree, event routing, root screen pane, frame scheduling/chrome, scrollbar infrastructure, and shared dirty-region helpers.

## Covered Items To Ignore

- None recorded yet.

## Uncovered Items

- by-meta inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-meta is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
