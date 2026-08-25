** TARGET-REPORT-UID:0000N4 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B007 source-quality report: [UID:0000N4] RegistryConfig empty-emitter family

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0000N4-RegistryConfig-empty-emitter-family-source-quality.md`

Target path: `source-3/project-documentation/by-file/RegistryConfig.md`

Assignment ID: `B007-revise-0000N4-RegistryConfig-empty-emitter-family-20260630`

Mode: report-only research. No by-* docs, generated files, coverage reports, validator state, IDA DB, supervisor ledgers, lock files, or executed archives were edited. No leases were taken. No subagents were spawned.

## Current Target State And Queue Row

Queue source: `auto-generated/-ag-research-tracker.md` -> `Files With Empty Emitters`.

Current queue row: [UID:0000N4] `RegistryConfig` has `31` total emitters, `14` filled, `17` empty, `45.2%` complete, generated file `auto-generated/NexusTK/config/RegistryConfig.cpp`, source path `by-file/RegistryConfig.md`.

Current by-file metadata and revised recommendation:

| Field | Current state | Recommendation |
| --- | --- | --- |
| UID | `0000N4` | unchanged |
| Completion | `88` | raise to `90` |
| Confidence | `85` | raise to `90` |
| Canonical owner | `FILE` | unchanged |
| Source path | `NexusTK/config/` | unchanged |

The by-file root is already the correct source root for registry-backed configuration, command-line/startup helper code, and file-level raw helper/literal support. The rejection repair resolves the previous method-body blockers for `RegistryConfig::~RegistryConfig`, `LoadOrInitialize`, `InitializeUserDataDefaults`, `InitializeDefaults`, and `SaveToRegistry`: each now has first-draft formal C++ using best-supported field/API names and evidence-backed caveats. The by-file score should therefore move to `90/90`. The remaining caps are not empty-emitter blockers: exact original field spellings for a few inferred names, final class-wide data layout polish, and parser-island class-method-vs-file-static routing remain confidence caps while current child/source bodies are implementation-ready.

## Evidence Checked

Current generated output inspected read-only:

- `auto-generated/NexusTK/config/RegistryConfig.cpp`
- Header facts: source by-file UID `0000N4`; generated source path `by-file/RegistryConfig.md`; `validator-command-id: 000000002443`; `validator-refreshed-at: 2026-06-30T05:43:37-04:00`; `validator-refresh-source: foreground-generated-refresh`.
- Filled emitters already present: [UID:0002P8] `RegistryConfig::LoadFromRegistry()`, [UID:00032G] `static unsigned char QueryInstallRegistryType()`, and parser children [UID:0002BG]-[UID:0002BR].
- Empty markers are the 17 UIDs inventoried below at generated lines near `1326-1358`.

Current IDA MCP evidence:

| MCP call | Result used |
| --- | --- |
| `tools/list` | Endpoint exposed `idb_list`, `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `decompile`, `entity_query`, and related narrow read-only tools. |
| `idb_list` call id `915` | Active session `supervisor_resume_20260629`; input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; active/adopted/owned worker; `pid=17592`, `worker_pid=17592`; `is_analyzing:false`. |
| `server_health` call id `916` | `status: ok`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis ready; Hex-Rays ready; strings cache ready size `2067`. |
| `lookup_funcs` call id `917` | `0x00467340 sub_467340 size 0x3b`; `0x0048e780 sub_48E780 size 0xda`; `0x0048e860 sub_48E860 size 0xef`; `0x0048ebc0 sub_48EBC0 size 0x30f`; `0x0048eed0 sub_48EED0 size 0x521`; `0x00491b30 sub_491B30 size 0xb65`; `0x0048f400 Not a function`; `0x00493e30 Not a function`. |
| `xrefs_to` call id `918` | `0x00467340` has one data xref from `0x00612614`; `0x0048e780` has one code xref from scalar wrapper `0x00467346`; `0x00491b30` has one vtable/data xref from `0x00612620`; `0x004926a0` has one vtable/data xref from `0x00612624`; `0x0048f400` has zero xrefs; `0x00493e30` has zero xrefs. Pointer table xrefs: `0x0066d468` one raw parser data xref at `0x0048f6a3`; `0x0066d46c` one `sub_4926A0` data xref at `0x00493d0c`; `0x0066d470` zero xrefs; `0x0066d474` three `sub_4918E0` xrefs; `0x0066d478` three `sub_4918E0` xrefs. |
| `get_bytes` call id `919` | Vtable/COL bytes at `0x00612610`: `00 21 64 00 40 73 46 00 10 4b 4f 00 c0 b6 41 00 30 1b 49 00 a0 26 49 00`, proving COL `0x00642100`, scalar wrapper `0x00467340`, support slots `0x004f4b10` / `0x0041b6c0`, save `0x00491b30`, load `0x004926a0`. Pointer bytes at `0x0066d468`: `3c 69 61 00 d8 78 61 00 ec 78 61 00 4c 79 61 00 54 79 61 00`. Padding: `0x0048e85a` six `0xcc`; `0x00491b28` eight `0xcc`; `0x00492695` eleven `0xcc`; `0x00493e29` seven `0xcc`. |
| `decompile` call id `920` | `sub_48E860` decompiles as `RegistryConfig::LoadOrInitialize` shape: writes `this + 0x28d9dd = 0`, calls `sub_48EED0`, calls virtual slot `+0x10` and retries `sub_48EED0` on failure, calls `sub_516030`, writes word `this + 0x2916ca = 1`, copies `GetCommandLineW()` into a 1024-wide buffer, skips quoted or space-delimited executable token, tokenizes with `_wcstok_s(L" ")`, scans up to the eighth token, and repeats the `+0x2916ca` write when tokenization exhausts before the cap. |
| `tools/list` call id `1101` | Rechecked current schema before revision; endpoint still exposes narrow read-only calls including `idb_list`, `server_health`, `lookup_funcs`, `find_bytes`, `disasm`, `xrefs_to`, and `decompile`. |
| `idb_list` call id `1201` / `server_health` call id `1202` | Active session remains `supervisor_resume_20260629`; worker `pid=17592`, `worker_pid=17592`, `is_analyzing:false`; `status: ok`; IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; module `NexusTK.exe`; input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`; imagebase `0x400000`; auto-analysis and Hex-Rays ready; strings cache ready size `2067`. |
| `lookup_funcs` call id `1203` | Reconfirmed `0x0048e780 sub_48E780 size 0xda`, `0x0048e860 sub_48E860 size 0xef`, `0x0048ebc0 sub_48EBC0 size 0x30f`, `0x0048eed0 sub_48EED0 size 0x521`, and `0x00491b30 sub_491B30 size 0xb65`. |
| `find_bytes` call id `1204` | Rechecked offset immediates. `dd d9 28 00` (`+0x28d9dd`) appears at `0x0048e878` and `0x00574605`; `d8 d9 28 00` (`+0x28d9d8`) appears at `0x0048f38f` and `0x0057460c`; `d4 d9 28 00` (`+0x28d9d4`) appears only in the fixed-table helper region. |
| `disasm` call ids `1213` / `1214` and `decompile` call id `1222` | The second `+0x28d9dd` occurrence is in `0x005745b0` `SendServerSelectPacket`: it compares `g_pConfig + 0x28d9dd`, stores selected server id to `g_pConfig + 0x28d9d8`, and only formats the selected endpoint text when the `+0x28d9dd` flag is clear. Current docs already name these as `selectedServerId` and `alternateServerEndpointActive` / endpoint-preserve flag, resolving the rejected `this+0x28d9dd` blocker for `LoadOrInitialize`. |
| `xrefs_to` call id `1223` | `0x005745b0` has code xrefs from `0x00574510` and a near-boundary code ref at `0x005745a1`, matching the existing `ServerSelectHelpers_574510_5745b0.md` support page rather than a RegistryConfig method. |
| `decompile` call ids `1232`, `1233`, `1242`, `1252` | Current decompiles for `RegistryConfig::~RegistryConfig`, `InitializeUserDataDefaults`, `InitializeDefaults`, and `SaveToRegistry` were used to convert the prior generic "unsafe names" blockers into first-draft formal C++. Key facts: destructor cleanup order and `g_pConfig` clear; user-data localized/default string rows, compact shortcut rows, 30 macro records, target-option bytes, 20 string slots, and block-list vector clear; built-in scalar defaults, dialog-position center loop with special record 13, selected-server/default music state; and save-side root/Midi/Servers registry writes including the duplicate `MusicType` write and uppercase HKLM/current-directory tail. |

Current docs inspected:

- Target/source root: `by-file/RegistryConfig.md`
- Class and support: `by-class/RegistryConfig.md`, `by-class/Config.md`
- Empty by-memory/type pages listed in the inventory below.
- Existing exact source children: `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`, parser child pages [UID:0002BG]-[UID:0002BR], and relevant Config constructor/layout support.

Old reports and notes searched:

- `executed-b-agent-research/B007/0002BG-CommandLineArgumentCounter-source-quality.md`: exact tokenizer-tail evidence and accepted first-draft helper body; used as sibling evidence for `LoadOrInitialize`, not copied into the method body because current MCP found the additional `+0x28d9dd` write.
- `executed-b-agent-research/B003/0002P8-RegistryConfigLoadFromRegistry-source-quality.md`: accepted load-side body, option/string role map, adapter-formatting inline path, `mscfg.dll`/`grcframe.exe` helper probe, and sibling raw clone exclusion.
- `executed-b-agent-research/B003/00032G-RegistryConfigTypeProbeRaw-source-quality.md`: registry `Type` probe separation from normal load/save option roots.
- Prior parser child reports from B001/B003/B006/B008/B009/B010/B011/B013: already incorporated in parser child pages; used only as support that children emit individually and the aggregate should stay non-monolithic.
- `tools/leaser/Agents/Agent-A002/notes.md`: parser aggregate evidence, all twelve child splits, and zero direct dispatcher/xref/pointer-route facts.
- `tools/leaser/Agents/Agent-A003/notes.md`: prior pointer-table decision for [UID:000279], especially the no-direct-xref caveat for the `grcframe.exe` slot.

## Empty-Emitter Inventory And Disposition

| UID | Current target | Current metadata | Disposition |
| --- | --- | --- | --- |
| `0000BW` | `by-class/RegistryConfig.md` | `87/87`, owner/emitter `0000N4`, blank C++ | Immediate class declaration shell. Raise to `88/90`, set `EMITTER_POSITION_OPTIONAL:0`, preserve owner/emitter. |
| `000329` | `0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md` | `85/89`, owner/emitter `0000BW`, blank C++ | Immediate comment-only compiler-wrapper marker. Metadata unchanged. |
| `00032F` | `0x0048e780-0x0048e85a.RegistryConfigDestructor.md` | `86/89`, owner/emitter `0000BW`, blank C++ | Immediate first-draft destructor C++. Raise to `88/90`; preserve owner/emitter. Field names use current Config/RegistryConfig support docs, with `m_configScratchString` recorded as inferred from the `+0x28de18` StringBase helper-family evidence. |
| `00030U` | `0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md` | `85/88`, owner/emitter `0000BW`, blank C++ | Immediate first-draft load/bootstrap C++. Raise to `88/90`; preserve owner/emitter. The rejected `this + 0x28d9dd` blocker is resolved as `m_alternateServerEndpointActive` / endpoint-preserve flag by current ServerSelect helper evidence. |
| `00030W` | `0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` | `85/89`, owner/emitter `0000BW`, blank C++ | Immediate first-draft user-data default C++. Raise to `88/90`; preserve owner/emitter. Uses the accepted `RegistryConfigUserProfileBlock` role names and `MacroHotkeyRecord` struct. |
| `00030Y` | `0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md` | `86/88`, owner/emitter `0000BW`, blank C++ | Immediate first-draft built-in default initializer C++. Raise to `88/90`; preserve owner/emitter. Uses grouped source helpers only where the binary repeats a clear setting idiom such as dialog-position initialization. |
| `0002P7` | `0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md` | `85/88`, owner/emitter `0000BW`, blank C++ | Immediate first-draft registry save C++. Raise to `88/90`; preserve owner/emitter. Reuses the accepted load-side helper vocabulary and documents save-only/duplicate behaviors such as `AutoMove` and duplicate `MusicType`. |
| `000480` | `0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md` | `86/91`, owner/emitter `0000BW`, blank C++ | Immediate comment-only generated RTTI/COL marker. Metadata unchanged. |
| `000481` | `0x00612614-0x00612628.RegistryConfigVtableData.md` | `88/92`, owner/emitter `0000BW`, blank C++ | Immediate comment-only generated vtable marker. Metadata unchanged. |
| `0003FW` | `0x00617420-0x006178c8.RegistryConfigOptionStringData.md` | `88/91`, owner/emitter `0000BW`, blank C++ | Immediate comment-only pooled string-use marker. Metadata unchanged. |
| `0001VR` | `by-type/by-struct/RegistryConfigUserProfileBlock.md` | `88/88`, owner/emitter `0000BW`, blank C++ | Immediate comment-only layout-slice marker. Metadata unchanged. |
| `0001V1` | `by-type/by-struct/MacroHotkeyRecord.md` | `85/89`, owner `0001VR`, emitter `0001VR`, blank C++ | Immediate real struct declaration. Raise to `88/90`; preserve canonical owner `0001VR`; route directly to `EMITTER_UIDS:0000N4` at position `0` so the shared type appears in `RegistryConfig.cpp` without depending on the non-standalone layout slice. |
| `000220` | `0x0048f400-0x00491b28.RegistryCommandLineParsers.md` | `86/89`, owner/emitter `0000N4`, blank C++ | Immediate comment-only aggregate/index marker. Metadata unchanged. |
| `0002VB` | `0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md` | `85/88`, owner/emitter `0000N4`, blank C++ | Immediate comment-only retained raw clone marker. Metadata unchanged. |
| `0003FV` | `0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md` | `86/90`, owner/emitter `0000N4`, blank C++ | Immediate comment-only pooled string-use marker. Metadata unchanged. |
| `0003FX` | `0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md` | `85/89`, owner/emitter `0000N4`, blank C++ | Immediate comment-only pooled string-use marker. Metadata unchanged. |
| `000279` | `0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md` | `86/89`, owner/emitter `0000N4`, blank C++ | Immediate comment-only pointer-table marker. Metadata unchanged. |

No UID is deferred outside this report. The implementation callback can repair all 17 markers in one leased batch or smaller immediate batches.

## Ownership And Source-Placement Analysis

RegistryConfig class route:

- Base class: `Config`, already declared in [UID:000031] `by-class/Config.md` with pure virtual `SaveToRegistry()` and `LoadFromRegistry()`.
- Destructor route: vtable slot `0x00612614` targets scalar wrapper `0x00467340`, which calls real non-deleting destructor `0x0048e780`.
- Vtable slots from current MCP bytes: `0x00467340`, `0x004f4b10`, `0x0041b6c0`, `0x00491b30`, `0x004926a0`. Existing docs resolve the last two as concrete `SaveToRegistry` and `LoadFromRegistry` overrides.
- Method inventory: destructor, `LoadOrInitialize`, `InitializeUserDataDefaults`, `InitializeDefaults`, `SaveToRegistry`, and `LoadFromRegistry`. The base constructor remains owned by `Config`; do not add an unproven `RegistryConfig()` declaration in this callback.
- Known child bodies: `LoadFromRegistry` and parser children already emit; the repaired pass now makes destructor, load/bootstrap, defaults, user-data defaults, and save source-ready as first-draft formal C++. Their final original field spellings remain score caps, not no-code blockers.
- Layout state: current docs resolve enough startup/server-select/profile/registry fields for first-draft method C++, especially `m_alternateServerEndpointActive`, `m_selectedServerId`, `m_serverEndpointPrefix`, `m_startupReady`, the profile slice names, and the registry load/save map. The full class declaration should still remain method-only in this callback because a broad field declaration block would overstate final layout recovery.

Command-line parser placement:

- The aggregate [UID:000220] is an index over twelve exact children, not a monolithic source function. Current MCP again found `0x0048f400` is not a function and has zero direct xrefs.
- Existing exact parser children already emit first-draft file-static helpers under `RegistryConfig.cpp`; this aggregate should get a comment-only marker explaining that exact children carry source bodies.
- Do not promote the parser island to class methods in this callback. The `ecx` config pointer is real, but no dispatcher/caller route, vtable route, or stored pointer route has been recovered.

Data/string placement:

- The `.rdata` string clusters [UID:0003FV], [UID:0003FW], and [UID:0003FX] are source-use literal pools. Their source reconstruction belongs at exact parser/load/save use sites, not as synthetic standalone arrays.
- The `.data` pointer table [UID:000279] is stronger than a generic literal cluster because it has writable pointers and direct slot xrefs, but current MCP still reconfirms one zero-xref slot at `0x0066d470` (`grcframe.exe`). Current generated/source child bodies use literals/semantic constants at their use sites. A synthetic five-pointer table would encode grouping that is not proven as source-authored.

Raw helper placement:

- [UID:0002VB] remains RegistryConfig file-level support, not a class method and not a `LoadFromRegistry` callee. Current MCP reconfirms `0x00493e30` is not a function and has zero xrefs; [UID:0002P8] contains the live inline adapter formatting.

## Heuristic / Inference Reanalysis

Accepted inferences:

- `RegistryConfig : public Config` is source-safe: the base class page declares the pure persistence virtuals, and current vtable bytes prove concrete save/load slots.
- `MacroHotkeyRecord` is source-safe as a first-draft type despite the original name cap: the row size, field offsets, state values, defaulting, file load/save, UI mutation, and runtime dispatch consumers are all corroborated. The generated repository already uses `MacroHotkeyRecord::Text`, `Spell`, and `Item` in other emitted source, so formalizing the enum-state struct improves consistency.
- The five exact source-authored method pages are source-ready at first-draft quality. The former field-name blockers were rechecked rather than deferred:
  - `+0x28d9dd` is the server-select endpoint-preserve / alternate-endpoint flag. MCP found it in `LoadOrInitialize` and `SendServerSelectPacket`; current support docs name the source role as `alternateServerEndpointActive`.
  - `+0x28d9d8` is `selectedServerId`, and `+0x28d9dc` is best inferred as `m_multiServerListEnabled` because `SaveToRegistry` gates `Servers` subkey emission on that byte plus positive server-entry count.
  - `+0x28de18` remains semantically weaker but belongs to the StringBase-style helper family constructed/destroyed with the Config object; `m_configScratchString` is a source-facing first-draft name and a confidence cap, not a reason to suppress `~RegistryConfig`.
  - Save-side helper names should mirror the accepted `LoadFromRegistry` body: `WriteDwordValue`, `WriteStringValue`, `SaveMidiRegistryValues`, and `SaveMultiServerEntries` are source extraction names for repeated inline registry idioms unless separate binary functions are later recovered.
- Comment-only markers remain source-quality for compiler-generated metadata/wrappers, pooled literal clusters, aggregate index pages, the profile-block documentation slice, and no-xref raw/data pages.

Rejected alternatives:

- Keep `RegistryConfig::LoadOrInitialize()` comment-only because of `this + 0x28d9dd`: rejected by the revision. Current MCP and support docs prove the byte's source role well enough for first-draft `m_alternateServerEndpointActive = false`.
- Keep destructor/default/save/user-default bodies comment-only because source member names are not final: rejected by the revision. Current docs and sibling accepted C++ already use the necessary role names; remaining original-spelling uncertainty is a confidence cap.
- Emit broad `RegistryConfig` field declarations with the method bodies: rejected. Method first drafts can use source-facing member names, but the class page should not pretend the full object layout is final.
- Clear source-owned literal pages to `RECONSTRUCTABLE:FALSE`: rejected because the source-use route is meaningful and should remain visible in generated `RegistryConfig.cpp` as a covered/no-standalone marker.
- Emit raw vtable/RTTI dword tables: rejected; class declaration and virtual methods regenerate them.
- Emit the parser aggregate as one function: rejected; exact children own individual bodies, and current MCP found no function at the aggregate start.
- Emit [UID:0002VB] as `BuildFirstAdapterPhysicalAddressString`: rejected; that name is a useful extraction label for [UID:0002P8]'s live inline block, not proof that the no-xref raw clone is called.
- Emit static declarations for [UID:000279]'s five pointers: rejected; four source-use routes and one no-xref slot do not prove a single source table or final per-entry declaration split.

## Score And Metadata Disposition

Recommended score/metadata changes:

| UID | Change |
| --- | --- |
| `0000N4` | Raise `COMPLETION:90`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/config/"`; add a support note that the former 17-empty-emitter family is resolved by method/type/class C++, comment-only compiler/data/aggregate markers, and evidence-backed no-standalone pages. |
| `0000BW` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000N4`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000N4`; set `EMITTER_POSITION_OPTIONAL:0`; insert the formal class shell below. |
| `00032F` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`; insert the formal destructor first draft below. |
| `00030U` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`; insert the formal load/bootstrap first draft below. |
| `00030W` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`; insert the formal user-data defaults first draft below. |
| `00030Y` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`; insert the formal built-in defaults first draft below. |
| `0002P7` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`; insert the formal registry-save first draft below. |
| `0001V1` | Raise `COMPLETION:88`, `CONFIDENCE:90`; preserve `CANONICAL_OWNER:0001VR`; preserve `RECONSTRUCTABLE:TRUE`; change `EMITTER_UIDS:0000N4`; set `EMITTER_POSITION_OPTIONAL:0`; insert the formal struct below. |

Recommended no score/metadata changes:

- `000329`, `000480`, `000481`, `0003FW`, `0001VR`, `000220`, `0002VB`, `0003FV`, `0003FX`, and `000279`.

Open questions are evidence-backed score caps, not callback blockers:

- The exact original spellings for `m_alternateServerEndpointActive`, `m_multiServerListEnabled`, `m_configScratchString`, `m_serverEndpointPrefix`, and several scalar option fields are inferred from current docs and call/data flow rather than PDB/source proof. These names are source-facing and better than raw offsets; they cap confidence rather than blocking emission.
- `SaveToRegistry` helper names are extraction names for repeated inline registry idioms. No separate binary functions are claimed for `WriteDwordValue`, `SaveMidiRegistryValues`, or `SaveMultiServerEntries`.
- Profile layout: role-accurate fields are documented, but the whole `RegistryConfigUserProfileBlock` name remains a documentation slice rather than a proven standalone C++ type.
- Pointer/literal data: source use is proven, but standalone declaration grouping and exact original names are not.

## Exact Formal C++ / No-Code Blocks

### [UID:0000BW] `by-class/RegistryConfig.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- `EMITTER_POSITION_OPTIONAL:0`

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class RegistryConfig : public Config
{
public:
    virtual ~RegistryConfig();

    void LoadOrInitialize();
    void InitializeUserDataDefaults();
    void InitializeDefaults();

    virtual void SaveToRegistry();
    virtual bool LoadFromRegistry();
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000329] `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated RegistryConfig scalar deleting destructor wrapper.
// Source reconstruction is the RegistryConfig virtual destructor declaration; the vtable wrapper is regenerated by the compiler.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00032F] `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
RegistryConfig::~RegistryConfig()
{
    delete m_midiTrackPaths;
    m_midiTrackPaths = 0;

    free(m_logDataText);
    m_logDataText = 0;

    m_musicFolderPath.Release();
    m_blockListenNames.Clear();
    m_startupLauncherId.Release();

    for (int i = 0; i < 20; ++i)
        m_profileStringSlots[i].Release();

    m_configScratchString.Release();
    m_serverEntries.ReleaseOwnedBuffers();
    m_serverEntries.DestroyRecords();

    g_pConfig = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00030U] `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegistryConfig::LoadOrInitialize()
{
    m_alternateServerEndpointActive = false;

    InitializeDefaults();
    if (!LoadFromRegistry())
        InitializeDefaults();

    GetMemoryMan();
    m_startupReady = 1;

    wchar_t commandLine[0x400];
    wcscpy_s(commandLine, _countof(commandLine), GetCommandLineW());

    wchar_t *argumentStart = wcschr(commandLine, L'"');
    if (argumentStart)
        argumentStart = wcschr(argumentStart + 1, L'"');
    else
        argumentStart = wcschr(commandLine, L' ');

    if (!argumentStart)
        return;

    wchar_t *context = 0;
    int tokenCount = 0;
    wchar_t *token = wcstok_s(argumentStart + 1, L" ", &context);
    if (!token) {
        m_startupReady = 1;
        return;
    }

    while (++tokenCount < 8) {
        token = wcstok_s(0, L" ", &context);
        if (!token) {
            m_startupReady = 1;
            return;
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00030W] `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegistryConfig::InitializeUserDataDefaults()
{
    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_profileTextSlots[i], _countof(m_profileTextSlots[i]),
                 g_pLanguageMan->GetLocalizedString(67 + i));

    for (int i = 0; i < 10; ++i)
        wcscpy_s(m_legacyShortcutText[i], _countof(m_legacyShortcutText[i]), L"");

    wcscpy_s(m_selectedProfileName, _countof(m_selectedProfileName), L"");

    for (int i = 0; i < 20; ++i) {
        m_compactShortcutRecords[i].key = static_cast<wchar_t>(L'a' + i);
        m_compactShortcutRecords[i].mode = 1;
    }

    for (int i = 0; i < 30; ++i) {
        m_macroHotkeys[i].ordinal = static_cast<unsigned short>(i);
        m_macroHotkeys[i].state = MacroHotkeyRecord::Spell;

        const wchar_t key =
            static_cast<wchar_t>((i < 26) ? (L'a' + i) : (L'A' + (i - 26)));
        m_macroHotkeys[i].text[0] = key;
        m_macroHotkeys[i].text[1] = L'\0';
    }

    m_targetOptionRows[0].first = 1;
    m_targetOptionRows[0].second = 1;
    m_targetOptionRows[1].first = 1;
    m_targetOptionRows[1].second = 0;

    for (int i = 0; i < 20; ++i)
        m_profileStringSlots[i].Assign(L"");

    m_blockListenNames.Clear();
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:00030Y] `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegistryConfig::InitializeDefaults()
{
    m_startupServerId = 1;
    m_fontIndex = 0;
    m_iconsPaneReducedMode = false;
    m_startupPort = 0;
    m_startupConnectionMode = 5;
    m_terminalBaudRate = 57600;

    m_soundEnabled = true;
    m_soundVolume = 100;
    m_musicEnabled = true;
    m_musicVolume = 100;

    m_mapEffectEnabled = true;
    m_sayWithEnter = true;
    m_doubleClickEnabled = true;
    m_autoMoveEnabled = false;
    m_balloonEnabled = true;
    m_shadowEnabled = true;
    m_showUserNameMode = 1;
    m_graphicsSetting = 2;
    m_tabVSwap = false;
    m_showDamage = true;
    m_groupBarEnabled = true;
    m_carnageColorEnabled = true;
    m_orbTargetShare = false;
    m_f1Swap = false;
    m_hearSnoreMode = 1;
    m_seeThroughEnabled = true;
    m_hearEmotions = true;

    m_paletteColorOverrides[0] = 10;
    m_paletteColorOverrides[1] = static_cast<unsigned short>(-1);
    m_paletteColorOverrides[2] = 17;
    m_paletteColorOverrides[3] = 11;

    m_serverEndpointPrefix = 0;

    InitializeUserDataDefaults();

    for (int i = 0; i < 21; ++i) {
        m_dialogPositions[i].state = 1;
        m_dialogPositions[i].position.Set(g_screenWidth / 2, g_screenHeight / 2);
    }

    m_dialogPositions[13].state = 2;
    m_dialogPositions[13].position.Set(11, 432);

    m_selectedServerId = -1;
    m_multiServerListEnabled = false;

    m_soundLatency = 16;
    m_musicOutputSelection = 1;
    m_musicSourceMode = 0;
    m_redbookDriveLetter = 0;
    m_randomizeMusicOrder = false;
    m_musicRepeatEnabled = false;
    m_musicFolderPath.Assign(L"");

    m_systemMessageHeight = 70;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002P7] `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`
- `EMITTER_POSITION_OPTIONAL:` unchanged blank

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void RegistryConfig::SaveToRegistry()
{
    HKEY rootKey = 0;
    HKEY childKey = 0;
    DWORD disposition = 0;

    wchar_t currentDirectory[MAX_PATH];

    if (RegCreateKeyExW(HKEY_CURRENT_USER,
                        L"Software\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_WRITE,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return;
    }

    if (m_logDataText)
        WriteBinaryWideStringValue(rootKey, L"LogData", m_logDataText);

    GetCurrentDirectoryW(_countof(currentDirectory), currentDirectory);
    WriteStringValue(rootKey, L"Location", currentDirectory);
    WriteStringValue(rootKey, L"LastServer", m_lastServerName);

    WriteDwordValue(rootKey, L"Font", m_fontIndex);
    WriteDwordValue(rootKey, L"Icons", m_iconsPaneReducedMode);
    WriteDwordValue(rootKey, L"Sound", m_soundEnabled);
    WriteDwordValue(rootKey, L"SoundVolume", m_soundVolume);
    WriteDwordValue(rootKey, L"Music", m_musicEnabled);
    WriteDwordValue(rootKey, L"MusicVolume", m_musicVolume);
    WriteDwordValue(rootKey, L"DoubleClick", m_doubleClickEnabled);
    WriteDwordValue(rootKey, L"AutoMove", m_autoMoveEnabled);
    WriteDwordValue(rootKey, L"TabVSwap", m_tabVSwap);
    WriteDwordValue(rootKey, L"ShowDamage", m_showDamage);
    WriteDwordValue(rootKey, L"GroupBar", m_groupBarEnabled);
    WriteDwordValue(rootKey, L"CarnageColor", m_carnageColorEnabled);
    WriteDwordValue(rootKey, L"Shadow", m_shadowEnabled);
    WriteDwordValue(rootKey, L"Balloon", m_balloonEnabled);
    WriteDwordValue(rootKey, L"GraphicsSetting", m_graphicsSetting);
    WriteDwordValue(rootKey, L"orbTargetShare", m_orbTargetShare);
    WriteDwordValue(rootKey, L"f1Swap", m_f1Swap);
    WriteDwordValue(rootKey, L"ShowUserName", m_showUserNameMode);
    WriteDwordValue(rootKey, L"HearSnore", m_hearSnoreMode);
    WriteDwordValue(rootKey, L"SeeThrough", m_seeThroughEnabled);
    WriteDwordValue(rootKey, L"SayWithEnter", m_sayWithEnter);
    WriteDwordValue(rootKey, L"HearEmotions", m_hearEmotions);
    WriteDwordValue(rootKey, L"MapEffect", m_mapEffectEnabled);

    WriteDwordValue(rootKey, L"MusicType", m_musicSourceMode);
    WriteDwordValue(rootKey, L"MusicType", m_musicSourceMode);
    WriteStringValue(rootKey, L"MP3Dir", m_musicFolderPath);
    WriteDwordValue(rootKey, L"MusicCdRomDrive", m_redbookDriveLetter);
    WriteDwordValue(rootKey, L"PlayRandom", m_randomizeMusicOrder);
    WriteDwordValue(rootKey, L"PlayRepeat", m_musicRepeatEnabled);
    WriteDwordValue(rootKey, L"SoundFreq", m_musicOutputSelection);

    const DWORD chatWindow =
        PackChatWindowValue(m_chatVisibleLineCount,
                            m_chatHandleModeIndex,
                            m_secondaryChatEnabled,
                            m_chatHandleLeftToggle);
    WriteDwordValue(rootKey, L"ChatWindow", chatWindow);
    WriteBinaryValue(rootKey, L"ChatColor", m_chatColorPairs, sizeof(m_chatColorPairs));

    for (int i = 0; i < 4; ++i) {
        wchar_t valueName[32];
        swprintf_s(valueName, _countof(valueName), L"Color%d", i);
        WriteDwordValue(rootKey, valueName, m_paletteColorOverrides[i]);
    }

    WriteDwordValue(rootKey, L"ClickMove", m_clickMoveEnabled);
    WriteDwordValue(rootKey, L"ClickLook", m_clickLookEnabled);
    WriteDwordValue(rootKey, L"SystemMessageHeight", m_systemMessageHeight);

    RegDeleteKeyW(rootKey, L"Midi");
    if (RegCreateKeyExW(rootKey, L"Midi", 0, 0, 0, KEY_WRITE, 0, &childKey, &disposition) == ERROR_SUCCESS) {
        SaveMidiRegistryValues(childKey, m_midiTrackPaths);
        RegCloseKey(childKey);
        childKey = 0;
    }

    for (int i = 0; i < 21; ++i) {
        wchar_t valueName[32];
        swprintf_s(valueName, _countof(valueName), L"DialogPos%d", i + 1);
        WriteBinaryValue(rootKey, valueName, &m_dialogPositions[i], sizeof(m_dialogPositions[i]));
    }

    if (m_multiServerListEnabled && m_serverEntryCount > 0) {
        RegDeleteKeyW(rootKey, L"Servers");
        if (RegCreateKeyExW(rootKey, L"Servers", 0, 0, 0, KEY_WRITE, 0, &childKey, &disposition) != ERROR_SUCCESS) {
            RegCloseKey(rootKey);
            return;
        }

        WriteDwordValue(childKey, L"MultiServerInfoVersion", m_multiServerInfoVersion);
        for (int i = 0; i < m_serverEntryCount; ++i) {
            const ServerSelectEntry &entry = m_serverEntries.entries[i];
            wchar_t valueName[64];
            wchar_t addressText[128];

            swprintf_s(addressText, _countof(addressText), L"%d:%d.%d.%d.%d:%d",
                       entry.serverId,
                       entry.address[0],
                       entry.address[1],
                       entry.address[2],
                       entry.address[3],
                       entry.portOrEndpointSuffix);

            swprintf_s(valueName, _countof(valueName), L"MultiServerAddr%d", i);
            WriteStringValue(childKey, valueName, addressText);
            swprintf_s(valueName, _countof(valueName), L"MultiServerName%d", i);
            WriteStringValue(childKey, valueName, entry.name);
            swprintf_s(valueName, _countof(valueName), L"MultiServerDesc%d", i);
            WriteStringValue(childKey, valueName, entry.description);
            swprintf_s(valueName, _countof(valueName), L"MultiServerAgreement%d", i);
            WriteStringValue(childKey, valueName, entry.agreement);
        }

        RegCloseKey(childKey);
        childKey = 0;
    }

    RegCloseKey(rootKey);

    rootKey = 0;
    if (RegCreateKeyExW(HKEY_LOCAL_MACHINE,
                        L"SOFTWARE\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_WRITE,
                        0,
                        &rootKey,
                        &disposition) == ERROR_SUCCESS)
    {
        if (RegCreateKeyExW(rootKey,
                            currentDirectory,
                            0,
                            0,
                            0,
                            KEY_WRITE,
                            0,
                            &childKey,
                            &disposition) == ERROR_SUCCESS)
        {
            RegCloseKey(childKey);
        }

        RegCloseKey(rootKey);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000480] `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated RegistryConfig RTTI/COL pointer.
// The source declaration is class RegistryConfig; no standalone C++ object is emitted for this dword.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000481] `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated RegistryConfig vtable data.
// The source declaration is class RegistryConfig with virtual SaveToRegistry() and LoadFromRegistry(); no raw vtable dword table is emitted.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0003FW] `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryConfig option-key string literals are covered by SaveToRegistry() and LoadFromRegistry() source-use sites.
// No standalone pooled-string cluster declaration is emitted for 0x00617420-0x006178c8.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001VR] `by-type/by-struct/RegistryConfigUserProfileBlock.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryConfigUserProfileBlock is a layout documentation slice inside RegistryConfig, not a confirmed standalone source struct.
// Emit exact nested row types such as MacroHotkeyRecord separately; keep this aggregate layout page comment-only.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0001V1] `by-type/by-struct/MacroHotkeyRecord.md`

Metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0001VR`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- `EMITTER_POSITION_OPTIONAL:0`

Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MacroHotkeyRecord
{
    enum State {
        Text = 1,
        Spell = 2,
        Item = 3
    };

    unsigned short ordinal;
    unsigned short reserved;
    State state;
    wchar_t text[0x80];
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryCommandLineParsers is an aggregate/index over exact parser children.
// The twelve child helpers emit individually under RegistryConfig.cpp; no monolithic parser-island function is emitted here.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0002VB] `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Retained no-xref adapter physical-address formatter clone.
// The live source path is the inline adapter formatting in RegistryConfig::LoadFromRegistry(); this raw unmodeled clone has no caller, no xref, and no stored pointer route, so it emits no standalone body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryConfig channel/startup literals are emitted through their exact parser and registry helper use sites.
// No standalone pooled-string cluster declaration is emitted for 0x006168e8-0x00617420.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:0003FX] `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// RegistryConfig adapter/helper literals are emitted through LoadFromRegistry(), parser helpers, and the documented raw-clone support context.
// No standalone pooled-string cluster declaration is emitted for 0x006178c8-0x006179ec.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

### [UID:000279] `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`

Metadata unchanged. Formal block:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Command-line/config string pointers are documented as a writable pointer table, but current source use is per-literal and one slot still has no direct code xref.
// Do not emit a synthetic five-pointer table; use the exact literals at their parser/load use sites.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Target/Support Doc Updates For Callback

Implementation should edit only these docs unless validation reveals a direct local consistency issue:

- `by-file/RegistryConfig.md`
- `by-class/RegistryConfig.md`
- `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md`
- `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`
- `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`
- `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md`
- `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`
- `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`
- `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md`
- `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`
- `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-type/by-struct/MacroHotkeyRecord.md`
- `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`
- `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`

By-file support note to add:

- The empty-emitter family now has an item-level disposition: declaration shell for `RegistryConfig`, first-draft method bodies for `~RegistryConfig`, `LoadOrInitialize`, `InitializeUserDataDefaults`, `InitializeDefaults`, and `SaveToRegistry`, first-draft `MacroHotkeyRecord`, and comment-only/no-standalone markers for compiler wrappers, RTTI/vtable, parser aggregate, raw clone, pooled string clusters, profile-block layout slice, and pointer table. Root score should move from `88/85` to `90/90` because the prior exact method-body blockers are resolved. Remaining class-layout and exact original spelling questions are evidence-backed confidence caps, not empty-emitter blockers.

Generated-output expectation:

- After validation/generated refresh, `auto-generated/NexusTK/config/RegistryConfig.cpp` should not contain the 17 current `Empty Emitter Marker` lines for the listed UIDs.
- It should contain the `RegistryConfig` class shell near the top because `0000BW` should use `EMITTER_POSITION_OPTIONAL:0`.
- It should contain the `MacroHotkeyRecord` struct near the top because `0001V1` should route directly to `0000N4` with `EMITTER_POSITION_OPTIONAL:0`.
- It should contain first-draft source bodies for `RegistryConfig::~RegistryConfig`, `RegistryConfig::LoadOrInitialize`, `RegistryConfig::InitializeUserDataDefaults`, `RegistryConfig::InitializeDefaults`, and `RegistryConfig::SaveToRegistry`.
- It should contain comment-only markers for the 10 no-standalone pages, preserving evidence without emitting synthetic wrappers, raw tables, pooled string arrays, or no-xref helper bodies.
- Existing emitted bodies for [UID:0002P8], [UID:00032G], and parser children [UID:0002BG]-[UID:0002BR] should remain unchanged except for normal generated ordering if the class/type position changes.

## Validators For Callback

Run scoped validators from `E:/NTK/GhidraBridge/source-3/project-documentation`.

Recommended pattern for each changed doc:

> Executable block R001 was removed from this report and preserved verbatim in [0000N4-RegistryConfig-empty-emitter-family-source-quality-removed.md](0000N4-RegistryConfig-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Use `--wait-generated` for `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, `by-type/by-struct/MacroHotkeyRecord.md`, and every changed by-memory/type page whose formal block routes to `auto-generated/NexusTK/config/RegistryConfig.cpp`. The callback checkpoint should include command IDs, timestamps, exit codes, ok counts, warnings, and generated freshness state for `auto-generated/NexusTK/config/RegistryConfig.cpp`.

Do not edit `auto-generated/NexusTK/config/RegistryConfig.cpp` directly. Do not edit generated project reports, `-coverage-report.md`, validator/tool state, IDA DB, executed archives, supervisor ledgers, or lock files.

## Claim And Incorporation Ledger

| Claim ID | Claim | Evidence | Implementation target | Callback status |
| --- | --- | --- | --- | --- |
| C001 | RegistryConfig is declaration-ready as a method shell with `Config` base and save/load overrides; no `RegistryConfig()` constructor should be declared in this callback. | Current class docs, Config base declaration, MCP vtable bytes/cross refs for scalar wrapper/save/load; constructor page [UID:00030S] remains owned by `Config`. | `by-class/RegistryConfig.md`; generated `RegistryConfig.cpp`. | Applied. `by-class/RegistryConfig.md` now has `88/90`, `EMITTER_POSITION_OPTIONAL:0`, the formal class shell, declaration audit, and rejected constructor/full-layout alternatives. Validator `000000002553` passed; generated header was observed at or after `000000002572` and contains `UID:0000BW` at line 7. |
| C002 | By-file root should record the repaired empty-emitter family and raise to `90/90`. | Current generated header/inventory plus repaired method-body audit. The file owns all registry/default/parser support, and method-body blockers are resolved; remaining broad layout questions are caps. | `by-file/RegistryConfig.md`. | Applied. `by-file/RegistryConfig.md` now records `COMPLETION:90`, `CONFIDENCE:90`, `CANONICAL_OWNER:FILE`, `NexusTK/config/`, and the empty-emitter family disposition. Validator `000000002552` passed; generated header reports `Source by-file UID: 0000N4`. |
| C003 | Scalar deleting destructor and vtable/RTTI pages should emit comment-only generated markers, not code/data tables. | MCP `get_bytes` and `xrefs_to`; existing no-code proofs. | `000329`, `000480`, `000481`. | Applied. The scalar deleting destructor, RTTI locator pointer, and vtable data docs contain the exact comment-only formal markers. Validators `000000002554`, `000000002560`, and `000000002561` passed; generated lines 21, 552, and 556 contain the comment-marker sections. |
| C004 | `RegistryConfig::~RegistryConfig` should emit first-draft C++. | Current MCP decompile call id `1232`; destructor page cleanup order; Config docs for `m_midiTrackPaths`, `m_logDataText`, `m_startupLauncherId`, `m_blockListenNames`, `m_musicFolderPath`, `m_serverEntries`; weak `+0x28de18` named `m_configScratchString` as confidence cap. | `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`. | Applied. Destructor doc now has `88/90`, exact formal C++, cleanup-order evidence, scalar-wrapper route, `g_pConfig` clear, and `m_configScratchString` score cap. Validator `000000002555` passed; generated line 25 starts `UID:00032F`. |
| C005 | `RegistryConfig::LoadOrInitialize` should emit first-draft C++; the rejected `this + 0x28d9dd` blocker is resolved. | MCP decompile call id `1205`; byte search/disasm/decompile call ids `1204`, `1213`, `1222`; `ServerSelectHelpers_574510_5745b0.md` and `g_pConfig` docs naming `selectedServerId` and `alternateServerEndpointActive`. | `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`. | Applied. Load/bootstrap doc now has `88/90`, exact formal C++, default-load-retry flow, `GetMemoryMan` tokenizer tail, `m_startupReady`, and resolved `m_alternateServerEndpointActive` evidence. Existing support docs for [UID:0000VG] and [UID:00028Q] already preserved the route. Validator `000000002556` passed; generated line 48 starts `UID:00030U`. |
| C006 | `RegistryConfig::InitializeUserDataDefaults` should emit first-draft C++ using accepted profile-slice and macro-row names. | MCP decompile call id `1233`; `RegistryConfigUserProfileBlock.md` layout names; `MacroHotkeyRecord.md` row contract; profile/macro consumers. | `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md`. | Applied. User-data defaults doc now has `88/90`, exact formal C++, localized string ids, legacy empty rows, selected-profile clear, shortcut defaults, 30 macro rows, target-option byte pattern, 20 string-slot resets, and block-list vector clear. Validator `000000002557` passed; generated line 89 starts `UID:00030W`. |
| C007 | `RegistryConfig::InitializeDefaults` should emit first-draft C++. | MCP decompile call id `1242`; current class/file docs for scalar option roles, startup fields, server-select defaults, music defaults, and dialog-position records. | `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`. | Applied. Defaults doc now has `88/90`, exact formal C++, scalar defaults, dialog-position center loop and record `13` special case, selected/multi-server defaults, music defaults, and field-name score caps. Validator `000000002558` passed; generated line 127 starts `UID:00030Y`. |
| C008 | `RegistryConfig::SaveToRegistry` should emit first-draft C++ and raise to `88/90`. | MCP decompile call id `1252`; existing save page value inventory and API map; accepted load-side helper vocabulary; current docs for `AutoMove` save/load asymmetry, `m_midiTrackPaths`, `m_serverEntries`, `m_dialogPositions`, and duplicate `MusicType` write. | `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`. | Applied. Save doc now has `88/90`, exact formal C++, root/key inventory, duplicate `MusicType`, `AutoMove` asymmetry, `Midi` delete/recreate, `DialogPos%d`, gated `Servers` rewrite, multi-server value families, and HKLM uppercase/current-directory tail. Validator `000000002559` passed; generated line 191 starts `UID:0002P7`. |
| C009 | `MacroHotkeyRecord` can emit a first-draft struct with enum states and exact row layout. | `MacroHotkeyRecord.md` row layout, default/load/save/UI/runtime consumers, existing generated use of `MacroHotkeyRecord::Text/Spell/Item`. | `by-type/by-struct/MacroHotkeyRecord.md`; route to `0000N4` position `0`. | Applied. Struct doc now has `88/90`, owner `0001VR`, `EMITTER_UIDS:0000N4`, `EMITTER_POSITION_OPTIONAL:0`, exact formal struct, routing rationale, and score rationale. Validator `000000002564` passed; generated line 568 starts `UID:0001V1`. |
| C010 | `RegistryConfigUserProfileBlock` should remain a comment-only layout slice, not a standalone emitted struct. | The page states it is a documentation name for a slice inside RegistryConfig; exact nested row type is separate and first-draft methods use the field roles without emitting the aggregate type. | `by-type/by-struct/RegistryConfigUserProfileBlock.md`. | Applied. Profile-block doc contains the exact comment-only layout-slice marker and current owner/emitter wording. Validator `000000002563` passed; generated line 564 starts `UID:0001VR`. |
| C011 | Parser aggregate should not emit a monolithic body. | Current MCP: `0x0048f400` not a function and zero xrefs; exact parser children already emit. | `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`. | Applied. Parser aggregate doc contains the exact comment-only marker and preserves the child-helper route. Validator `000000002565` passed; generated line 684 starts `UID:000220`. |
| C012 | Raw adapter clone should not emit a standalone body. | Current MCP: `0x00493e30` not a function and zero xrefs; [UID:0002P8] has live inline source path. | `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`. | Applied. Raw adapter doc contains the exact no-xref clone marker and preserves the live inline source path through [UID:0002P8]. Validator `000000002566` passed; generated line 1696 starts `UID:0002VB`. |
| C013 | String clusters should emit comment-only use-site markers, not synthetic literal arrays. | Existing literal/xref pages and current MCP names/bytes; exact parser/load/save children own use sites. | `0003FV`, `0003FW`, `0003FX`. | Applied. The option, channel/startup, and adapter/helper string-cluster docs contain exact use-site comment markers. Validators `000000002562`, `000000002567`, and `000000002568` passed; generated lines 560, 1700, and 1704 contain the sections. |
| C014 | Pointer table should not emit a synthetic five-pointer declaration. | Current MCP pointer bytes and per-slot xrefs; `0x0066d470` still zero xrefs; source use is per-literal. | `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`. | Applied. Pointer-table doc contains the exact no-synthetic-table marker and preserves the zero-xref slot caveat. Validator `000000002569` passed; generated line 1708 starts `UID:000279`. |

## Implementation Tracking Checklist

- [x] Lease only the immediate batch files to edit; release immediately after edit/validator batch. Proof: B007 leased the 18 changed by-* docs for the edit/validator batch; both release attempts returned `Rejected[No active lease]` after expiration, and `tools/leaser/Agents/Agent-B007/current_leases.md` lists no active B007 leases.
- [x] Update [UID:0000N4] `by-file/RegistryConfig.md` with the family repair support note and metadata raise to `90/90`; preserve source path `NexusTK/config/` and file owner. Proof: by-file doc now contains the `90/90` metadata, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/config/"`, and the empty-emitter family disposition; validator `000000002552` passed.
- [x] Update [UID:0000BW] `by-class/RegistryConfig.md`: metadata to `88/90`, `EMITTER_POSITION_OPTIONAL:0`, formal class shell, declaration audit note, rejected constructor/full-layout alternatives, change log. Proof: class doc has all listed edits and generated `RegistryConfig.cpp` line 7 contains `UID:0000BW`; validator `000000002553` passed.
- [x] Update [UID:0001V1] `by-type/by-struct/MacroHotkeyRecord.md`: metadata to `88/90`, `EMITTER_UIDS:0000N4`, `EMITTER_POSITION_OPTIONAL:0`, formal struct block, score rationale, change log. Proof: struct doc has all listed edits and generated line 568 contains `UID:0001V1`; validator `000000002564` passed.
- [x] Update [UID:00032F] `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md`: metadata to `88/90`, insert the exact formal destructor C++ block, and preserve cleanup order, scalar wrapper caller, ConfigEntryBlock release, entry destroy callback, `g_pConfig` clear, and `+0x28de18` inferred-name confidence cap. Proof: destructor doc contains the formal body and evidence notes; validator `000000002555` passed.
- [x] Update [UID:00030U] `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`: metadata to `88/90`, insert the exact formal load/bootstrap C++ block, preserve default-load-retry flow, `GetMemoryMan`, tokenizer tail, `m_startupReady`, and resolved `+0x28d9dd` as `m_alternateServerEndpointActive`. Proof: load/bootstrap doc contains the formal body and resolved-field evidence; validator `000000002556` passed.
- [x] Update [UID:00030W] `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md`: metadata to `88/90`, insert the exact formal user-data defaults C++ block, preserve localized string ids `67..76`, empty legacy rows, selected profile clear, compact shortcut defaults, 30 macro rows, target option byte pattern, 20 string-slot resets, and block-list vector clear. Proof: user-data defaults doc contains the formal body and listed evidence; validator `000000002557` passed.
- [x] Update [UID:00030Y] `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`: metadata to `88/90`, insert the exact formal defaults C++ block, preserve scalar option defaults, dialog-position center loop and record `13` special `(11,432)` state, selected-server/multi-server defaults, music defaults, and score-cap notes for inferred field spellings. Proof: defaults doc contains the formal body and listed evidence; validator `000000002558` passed.
- [x] Update [UID:0002P7] `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`: metadata to `88/90`, insert the exact formal registry-save C++ block, preserve root key, `LogData`/`Location`/`LastServer`, all scalar option values, duplicate `MusicType`, `AutoMove` save/load asymmetry, `Midi` delete/recreate, `DialogPos%d` loop, `Servers` gated delete/recreate, multi-server value families, and HKLM uppercase root/current-directory tail. Proof: save doc contains the formal body and listed evidence; validator `000000002559` passed.
- [x] Insert the exact formal comment-only/no-standalone blocks for `000329`, `000480`, `000481`, `0003FW`, `0001VR`, `000220`, `0002VB`, `0003FV`, `0003FX`, and `000279`. Proof: the ten docs contain their accepted formal markers; validators `000000002554`, `000000002560`, `000000002561`, `000000002562`, `000000002563`, `000000002565`, `000000002566`, `000000002567`, `000000002568`, and `000000002569` passed.
- [x] Preserve exact current evidence in the support docs: MCP session/result facts, function boundaries, vtable/pointer bytes, padding, zero-xref facts, resolved `+0x28d9dd`/`+0x28d9d8` server-select route, parser aggregate child route, raw adapter no-caller route, string-literal use-site placement, and pointer-table no-xref slot. Proof: changed docs preserve the accepted evidence; support docs `by-class/Config.md`, `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`, `by-item/ServerSelectHelpers_574510_5745b0.md`, and `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md` already contained the required same-or-greater detail and were not edited.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`, using `--wait-generated` for files that refresh `auto-generated/NexusTK/config/RegistryConfig.cpp`. Proof: all 18 changed by-* docs passed scoped validators with `--apply --wait-generated --queue-timeout 240`; command IDs `000000002552` through `000000002569` each returned exit `0`, `ok: 1`, `errors: 0`.
- [x] Confirm generated freshness: new validator command id/timestamp should be later than current `000000002443` / `2026-06-30T05:43:37-04:00`, and generated `RegistryConfig.cpp` should no longer contain these 17 empty marker lines. Proof: scoped validator batch refreshed through `validator-command-id: 000000002569`; generated header was observed at or after `validator-command-id: 000000002572` / `2026-06-30T06:28:40-04:00` with `foreground-generated-refresh`; scan found all expected UID sections and no `Empty Emitter Marker` text. The final checkpoint reports the latest header observed at handoff.
- [x] Release all leases and report lease status, validator command IDs/timestamps/exit codes/ok counts/warnings, changed files, generated freshness state, and any unchecked blockers. Proof: release attempts found no active B007 leases; current B007 lease file has no B007 rows. The final checkpoint reports changed files, command IDs/timestamps, exit/ok counts, warnings/autogen count, generated freshness, and blocker state.

Callback validator proof:

| File | Command ID | Command timestamp | Exit | OK | Notes |
| --- | --- | --- | --- | --- | --- |
| `by-file/RegistryConfig.md` | `000000002552` | `2026-06-30T06:21:28-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-class/RegistryConfig.md` | `000000002553` | `2026-06-30T06:21:39-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00467340-0x0046737b.RegistryConfigScalarDeletingDestructor.md` | `000000002554` | `2026-06-30T06:21:49-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0048e780-0x0048e85a.RegistryConfigDestructor.md` | `000000002555` | `2026-06-30T06:21:59-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md` | `000000002556` | `2026-06-30T06:22:10-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0048ebc0-0x0048eecf.RegistryConfigInitializeUserDataDefaults.md` | `000000002557` | `2026-06-30T06:22:20-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md` | `000000002558` | `2026-06-30T06:22:31-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md` | `000000002559` | `2026-06-30T06:22:41-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md` | `000000002560` | `2026-06-30T06:22:52-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md` | `000000002561` | `2026-06-30T06:23:03-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md` | `000000002562` | `2026-06-30T06:23:13-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-type/by-struct/RegistryConfigUserProfileBlock.md` | `000000002563` | `2026-06-30T06:23:24-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-type/by-struct/MacroHotkeyRecord.md` | `000000002564` | `2026-06-30T06:23:34-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` | `000000002565` | `2026-06-30T06:23:45-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md` | `000000002566` | `2026-06-30T06:23:56-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md` | `000000002567` | `2026-06-30T06:24:06-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md` | `000000002568` | `2026-06-30T06:24:17-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |
| `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md` | `000000002569` | `2026-06-30T06:24:27-04:00` | `0` | `1` | `generated_refresh: completed`; `warnings_or_autogen:396`; `errors:0` |

Unchecked blockers for implementation callback: none. Remaining open questions are documented score caps and should not block applying the exact formal blocks above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000N4-RegistryConfig-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000N4-RegistryConfig-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T06:34:55","uid":"0000N4"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000N4-RegistryConfig-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000N4-RegistryConfig-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000N4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
