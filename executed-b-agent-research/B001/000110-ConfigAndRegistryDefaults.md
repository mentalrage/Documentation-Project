** TARGET-REPORT-UID:000110 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
## Finalized Report / Current Recommendation

- Target: [UID:000110] `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`.
- Assignment: B001-015.
- Final recommendation: keep [UID:000110] parent-blank as a non-emitting mixed split inventory. Do not assign the master to Config or RegistryConfig. Exact children now carry the source-owner decisions.
- Recommended status/classification: `ignored` / `RECONSTRUCTABLE:FALSE` mixed inventory/container, `88/90`, parent blank.
- Confidence: high. IDA MCP confirms every modeled function, raw helper body, caller/xref pattern, and padding span needed for the split. Remaining uncertainty is final helper spelling and no-xref raw-helper provenance, not the container decision.
- Concrete next action for supervisor/A-agents: accept/archive B001-015; no further split work required for this range unless later source recovery needs final helper names for the raw/no-xref helpers.
- Report state: final.
- Supervisor status refresh: 2026-06-10 request confirmed this file is final and current.

## Final Child Decisions

| UID | Range / page | Before | After | Parent decision |
| --- | --- | --- | --- | --- |
| `000110` | `0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults` | `85/89`, reconstructable, parent blank | `88/90`, non-reconstructable/ignored inventory, parent blank | Master remains mixed; exact children own source. |
| `00032D` | `0x0048e480-0x0048e4a8.ConfigEntryInitialize` | missing child | `85/88`, reconstructable | [UID:0000IE] `Config` file. |
| `00032E` | `0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers` | missing child, `0x0048e500` hidden in gap | `85/88`, reconstructable | [UID:0000IE] `Config` file. |
| `00030S` | `0x0048e550-0x0048e77a.ConfigConstructor` | `85/88`, parent `000031` | unchanged | [UID:000031] `Config` class remains correct. |
| `00032F` | `0x0048e780-0x0048e85a.RegistryConfigDestructor` | missing child | `86/89`, reconstructable | [UID:0000BW] `RegistryConfig` class. |
| `00030U` | `0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize` | `85/88`, parent `0000BW` | unchanged; stale parent-score wording fixed | [UID:0000BW] `RegistryConfig` class remains correct. |
| `00032G` | `0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw` | missing raw child | `85/86`, reconstructable | [UID:0000N4] `RegistryConfig` file as private file helper. |
| `00032H` | `0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw` | missing raw child | `85/86`, reconstructable | [UID:0000IE] `Config` file. |
| `00032I` | `0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers` | missing helper cluster | `86/88`, reconstructable | [UID:0000IE] `Config` file. |
| `00030W` | `0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults` | `85/89`, parent `0000BW` | unchanged; stale parent-score wording fixed | [UID:0000BW] `RegistryConfig` class remains correct. |
| `00030Y` | `0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults` | `86/88`, parent `0000BW` | unchanged; stale parent-score wording fixed | [UID:0000BW] `RegistryConfig` class remains correct. |

## Supporting Research

### IDA MCP Evidence

- `lookup_funcs` confirmed modeled starts/ranges inside the target: `0x0048e480` size `0x28`, `0x0048e4b0` size `0x4a`, `0x0048e500` size `0x4a`, `0x0048e550` size `0x22a`, `0x0048e780` size `0xda`, `0x0048e860` size `0xef`, `0x0048eaa0` size `0x57`, `0x0048eb00` size `0x4e`, `0x0048eb50` size `0x63`, `0x0048ebc0` size `0x30f`, and `0x0048eed0` size `0x521`.
- `lookup_funcs` reported no function object at `0x0048e950`, `0x0048ea70`, or `0x0048ea90`; raw byte/head scan confirmed complete code-shaped bodies there.
- Raw byte scan confirmed the internal padding spans are `0xcc`: `0x0048e4a8-0x0048e4b0`, `0x0048e4fa-0x0048e500`, `0x0048e54a-0x0048e550`, `0x0048e77a-0x0048e780`, `0x0048e85a-0x0048e860`, `0x0048e94f-0x0048e950`, `0x0048ea6e-0x0048ea70`, `0x0048ea85-0x0048ea90`, `0x0048ea9f-0x0048eaa0`, `0x0048eaf7-0x0048eb00`, `0x0048eb4e-0x0048eb50`, `0x0048ebb3-0x0048ebc0`, and `0x0048eecf-0x0048eed0`.
- `xrefs_to 0x0048e480` showed data refs from the Config constructor at `0x0048e5e0` and from `sub_4F6D80` at `0x004f6e18`.
- `xrefs_to 0x0048e4b0` showed callback refs from Config construction, RegistryConfig destruction, Config deleting destructor, and `sub_4F6D80`; `callers 0x0048e500` showed direct caller `0x004f6e34` in `sub_4F6D80`.
- `callers 0x0048e780` showed the RegistryConfig scalar deleting wrapper [UID:000329] at `0x00467346`.
- `xrefs_to 0x0048e950`, `0x0048ea70`, and `0x0048ea90` reported no direct refs. Ownership there is inference-backed by behavior and source clustering.
- `0x0048e950-0x0048ea6e` raw disassembly opens/creates registry keys, obtains the computer name, reads value `Type`, validates DWORD-sized data, closes keys, and returns a byte.
- `0x0048ea70` and `0x0048ea90` raw wrappers forward the Config member at `this + 0x2912b4` to `sub_4F3140`.
- `callers 0x0048eaa0` and `0x0048eb00` came from `sub_526100`, whose decompilation reads/writes MIDI track path preferences through `g_pConfig`.
- `callers 0x0048eb50` were `0x004fa729`, `0x004facc4`, `0x0052c14f`, `0x0052db1f`, and `0x0052f50f`; decompilation shows UI/login/create-user handlers storing a short wide string into `g_pConfig`.

### Ownership Analysis

The master cannot be assigned to one direct owner. Config owns the config-entry initializer/destructor helpers, vector wrappers, and string/preference helpers because they touch Config storage and are consumed through `g_pConfig` by unrelated callers. RegistryConfig owns the destructor and default/load methods because they are class lifecycle/default behavior. The raw `Type` probe has no direct xrefs, but its registry-only behavior and placement inside the RegistryConfig default/load cluster make `RegistryConfig.cpp` the strongest file-level owner.

Rejected alternatives:

- Assigning the whole range to Config would incorrectly absorb RegistryConfig destructor/default/load methods.
- Assigning the whole range to RegistryConfig would incorrectly absorb base Config entry-storage helpers.
- Assigning helper ownership to MIDI, server-select, or login/create-user callers would confuse consumers with owners.
- Creating a new source file is not justified. The likely broader contents already fit existing `Config.cpp` and `RegistryConfig.cpp`: Config receives entry/storage/string helpers, while RegistryConfig receives registry/default helpers.

### Documentation Changes

Created:

- `by-memory/0x0048e480-0x0048e4a8.ConfigEntryInitialize.md`
- `by-memory/0x0048e4b0-0x0048e54a.ConfigEntryDestroyHelpers.md`
- `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`
- `by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md`
- `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`
- `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`

Updated:

- `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`
- existing child pages `00030U`, `00030W`, and `00030Y` for stale parent-score wording only
- `by-class/Config.md`, `by-class/RegistryConfig.md`
- `by-file/Config.md`, `by-file/RegistryConfig.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `by-file/-coverage-report.md`
- `by-class/-coverage-report.md`

### Validation

Ran targeted validator with `--mode file --apply` for every touched by-* file. All returned `ok: 1`; final validator pass reported last used UID `00032I`.

Validation logs are under:

`tools/leaser/Agents/Agent-B001/research/validation-logs/B001-015-final`

### Remaining Uncertainty

No blocker remains for supervisor review. The unresolved facts are limited to final original helper spellings and whether no-xref raw helpers `00032G` / `00032H` were live private helpers or retained dead helper bodies. That uncertainty is documented in the exact child pages and does not justify leaving the master reconstructable or unassigned as source-bearing.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000110-ConfigAndRegistryDefaults.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000110"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
