** TARGET-REPORT-UID:00032H **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00032H] ConfigEntryVectorCopyWrappersRaw Source-Quality Report

Agent: Agent-B005  
Task type: B-agent source-quality / heuristic research  
Target: `source-3/project-documentation/by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`  
Required disposition: report-only. No target/support by-* docs edited. No coverage report edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep `00032H` reconstructable under [UID:0000IE] `Config`, raise the target to `88/90`, and populate first-draft C++ for the two private Config copy wrappers.
- Final disposition: source-authored but unreferenced/retained private wrapper pair for copying the Config-owned MIDI track-path list to and from a caller-supplied `List`.
- Required action: update target metadata/prose/C++, replace raw `sub_4F3140` and `this + 0x2912b4` wording with source-facing names, document the no-route search, and update support docs that still describe the field as a vague "config-entry vector".
- Confidence: very strong for byte boundaries, wrapper semantics, Config ownership, `List::AssignFrom` helper identity, and no direct route evidence; medium-high for exact original wrapper names because no caller names or symbols survive.

Recommended target metadata:

```yaml
COMPLETION: 88
CONFIDENCE: 90
CANONICAL_OWNER: 0000IE
RECONSTRUCTABLE: TRUE
EMITTER_UIDS: 0000IE
```

Recommended target C++:

```cpp
void Config::CopyMidiTrackPathsTo(List *destination) const
{
    destination->AssignFrom(m_midiTrackPaths);
}

void Config::CopyMidiTrackPathsFrom(List *source)
{
    m_midiTrackPaths->AssignFrom(source);
}
```

The method names are descriptive/inferred, not original-proof. If the broader `Config` naming pass prefers get/set phrasing, use `GetMidiTrackPaths(List*)` and `SetMidiTrackPaths(List*)`; the source behavior and signatures stay the same.

## Supporting Research

## Target

- Target UID: `00032H`
- Target path: `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`
- Current scores and metadata: `85/86`, `CANONICAL_OWNER:0000IE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000IE`, blank C++.
- Current generated state: `auto-generated/-ag-memory-coverage.md` lists the target as `emits` to `auto-generated/NexusTK/config/Config.cpp`, but with `no` C++; generated `Config.cpp` contains only an empty emitter marker.
- Current coverage row: reconstructable `85% : strong`, describing raw wrappers that forward `this + 0x2912b4` to `sub_4F3140`.

## Executive Recommendation

`00032H` should remain with [UID:0000IE] `Config`. The two wrappers operate on a `Config` member list, sit in the Config/RegistryConfig defaults island immediately between the RegistryConfig raw `Type` probe and Config string/preference helpers, and call the shared `List::AssignFrom` method. They are not RegistryConfig persistence methods, not MIDI-player source, not generic `List` methods, and not compiler-generated thunks.

The source-facing field at `Config + 0x2912b4` should be named `m_midiTrackPaths` or `m_midiTrackPathList`. I prefer `m_midiTrackPaths`: constructor bytes show it is a heap-allocated `List` object with element size `0x42` / decimal `66` (Verified with int_convert.py) and page size `0x10` / decimal `16` (Verified with int_convert.py). The adjacent Config string helpers scan this list by a one-byte selector and copy a wide string at entry offset `+2`. `SaveToRegistry` serializes the same list under the `Midi` registry subkey, and `MidiPlayerTrackSelectionHelpers` consume the lookup/setter helpers for selected MIDI track paths.

No direct live route to the raw wrapper starts was found. That should be documented, but it should not cause deassignment or no-code output. The functions are complete source-shaped wrappers retained in the Config object file, likely because object-level linking kept unused private helper methods. They should be reconstructed as private `Config` methods with descriptive names.

## Supervisor Active Recheck

This report was triggered by the 2026-06-19 B005 assignment for [UID:00032H] after the finished `0002P1` report. This was a report-only pass. I did not edit the target, support docs, generated files, or `by-memory/-coverage-report.md`.

The assignment required investigation of:

- raw wrapper liveness/source-name proof;
- `this + 0x2912b4` field/source name;
- `sub_4F3140` helper identity;
- no-xref route search;
- source placement;
- relationship to adjacent Config string helpers;
- first-draft C++ versus raw-retained proof.

All items are addressed below.

## Evidence Checked

Target/support docs checked:

- `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`
- `by-file/Config.md`
- `by-class/Config.md`
- `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`
- `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`
- `by-memory/0x0048e550-0x0048e77a.ConfigConstructor.md`
- `by-memory/0x00494020-0x00494126.ConfigDeletingDestructor.md`
- `by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md`
- `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`
- `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`
- `by-memory/0x00526100-0x00526332.MidiPlayerTrackSelectionHelpers.md`
- `by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md`
- `by-class/List.md`
- `by-memory/0x004f3140-0x004f35fd.ListCoreMethods.md`
- `by-memory/0x006168d0-0x006168e8.ConfigVtableData.md`
- `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/config/Config.cpp`
- `by-memory/-coverage-report.md`
- `by-memory/-guidance.md`, `by-structure.md`, `tools/validator_README.txt`

Tool/evidence checks performed:

- Current IDA MCP `tools/list` check against `http://127.0.0.1:13337/mcp`: unavailable, returned `Unable to connect to the remote server`.
- Direct PE byte scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE section-aware rel32 `E8`/`E9` call/jump scan for `0x0048ea70`, `0x0048ea90`, and `0x004f3140`.
- Absolute VA/RVA byte searches for `0x0048ea70` and `0x0048ea90`.
- Export directory check: executable has no export directory.
- Byte searches for all `0x2912b4` immediate references, mapped to VAs.
- `tools/int_convert.py` checks for important offsets/sizes.

Number-base checks:

- `0x2912b4` is decimal `2691764` (Verified with int_convert.py).
- `0x42` is decimal `66` (Verified with int_convert.py).
- `0x10` is decimal `16` (Verified with int_convert.py).
- `0x14` is decimal `20` (Verified with int_convert.py).
- `0x15` is decimal `21` (Verified with int_convert.py).
- `0xf` is decimal `15` (Verified with int_convert.py).
- `0xb` is decimal `11` (Verified with int_convert.py).

## Heuristic / Inference Reanalysis And Validation

### Raw wrapper boundaries and semantics

Confirmed bytes from direct PE scan:

```text
0x0048ea70: 55 8b ec ff b1 b4 12 29 00 8b 4d 08 e8 bf 46 06 00 5d c2 04 00
0x0048ea85: cc cc cc cc cc cc cc cc cc cc cc
0x0048ea90: 55 8b ec 8b 89 b4 12 29 00 5d e9 a1 46 06 00
0x0048ea9f: cc
```

Interpretation:

- `0x0048ea70-0x0048ea85` is a `0x15` / decimal `21` byte (Verified with int_convert.py) wrapper:
  - receives `Config* this` in `ecx`;
  - pushes `[this + 0x2912b4]` as the source `List*`;
  - loads caller argument `[ebp + 8]` into `ecx` as the destination `List*`;
  - calls `0x004f3140`;
  - returns with `retn 4`.
- `0x0048ea85-0x0048ea90` is `0xb` / decimal `11` bytes of `0xcc` padding (Verified with int_convert.py).
- `0x0048ea90-0x0048ea9f` is a `0xf` / decimal `15` byte (Verified with int_convert.py) tail-call wrapper:
  - receives `Config* this` in `ecx`;
  - replaces `ecx` with `[this + 0x2912b4]` as the destination `List*`;
  - tail-jumps to `0x004f3140` with the caller argument still on the stack as the source `List*`.
- `0x0048ea9f-0x0048eaa0` is one `0xcc` padding byte before the modeled string helper at `0x0048eaa0`.

Best source behavior:

```cpp
destination->AssignFrom(m_midiTrackPaths); // 0x0048ea70
m_midiTrackPaths->AssignFrom(source);      // 0x0048ea90
```

Rejected alternatives:

- Compiler adjustor thunk: rejected because the bodies do semantic work with a member field and `List::AssignFrom`, not just `this` adjustment and jump.
- Pure padding/data: rejected by exact executable instruction bytes.
- Generic `List` method: rejected because both wrappers read a `Config` object field at `+0x2912b4`.
- RegistryConfig method: rejected because the touched field is base Config storage and the same field is used by Config string/MIDI helpers; RegistryConfig only persists the state.

### `sub_4F3140` helper identity

Best source-facing identity: `List::AssignFrom` / `List::CopyFrom`.

Evidence:

- [UID:0003JT] `0x004f3140-0x004f31cc.ListAssignFrom.md` documents `sub_4F3140` as a `List` method that copies another list's `elementSize`, `pageSize`, `count`, and backing data into `this`.
- The method releases this list's old backing buffer, allocates page-rounded storage, and copies `elementSize * count` bytes from the source list.
- Direct PE rel32 scan found the two expected references to `0x004f3140`:
  - `0x0048ea7c` calls it from the copy-out wrapper.
  - `0x0048ea9a` jumps to it from the copy-in wrapper.

Recommendation: target docs should never leave this as raw `sub_4F3140`. Use `List::AssignFrom`, with `List::CopyFrom` noted only as an alternate if the `List` API naming sweep later chooses that spelling.

### `this + 0x2912b4` field/source name

Best source-facing field name: `m_midiTrackPaths`.

Acceptable alternate: `m_midiTrackPathList` if the project prefers explicit container suffixes.

Evidence:

- Constructor bytes around `0x0048e680-0x0048e6aa` allocate `0x14` / decimal `20` bytes (Verified with int_convert.py), call the `List` constructor, and store the returned object at `[this + 0x2912b4]`.
- The constructor passes `0x42` / decimal `66` (Verified with int_convert.py) and `0x10` / decimal `16` (Verified with int_convert.py) into the `List` constructor. This is a 66-byte element list with 16-entry pages.
- A 66-byte element matches a one-byte selector, one alignment byte, and a fixed 32-wide-character string at entry offset `+2`.
- [UID:00032I] string helpers scan this same list by selector byte and copy or replace the wide string at entry offset `+2`.
- `SaveToRegistry` references the same member while serializing entries under the `Midi` registry subkey.
- [UID:0001CH] `MidiPlayerTrackSelectionHelpers` uses the `0x0048eaa0` lookup and `0x0048eb00` setter to resolve selected track paths and write fallback `D%d`-style paths.
- Destructor paths delete the pointer at `+0x2912b4` through the list object's virtual destructor and then null the field.

Rejected field names:

- `m_configEntryVector`: too vague and conflicts with the separate 0x18-byte `ConfigEntry` / `ConfigEntryBlock` storage family.
- `m_configEntryBlock`: rejected because `ConfigEntryBlock` is the embedded block cleaned at `0x00494130`, not this heap `List`.
- `m_registryEntries`: rejected because the field is used by Config/MIDI helpers and only persisted by RegistryConfig.
- `m_stringPreferences`: directionally true but less precise than `m_midiTrackPaths`; it would obscure the `Midi` registry subkey and MIDI consumer evidence.

Recommended record type direction:

```cpp
struct ConfigMidiTrackPathEntry
{
    unsigned char selector;
    unsigned char reserved;
    wchar_t path[32];
};
```

This record shape is inferred from the `0x42` element size and the string helper's `entry + 2` wide-string operations. The original type name is unproven; the field name should be marked descriptive/inferred.

### Raw reachability and liveness

Current result: no live route to either wrapper start was found.

Checks:

- Existing IDA-backed docs record `lookup_funcs` found no modeled function at `0x0048ea70` or `0x0048ea90`.
- Existing IDA-backed docs record `xrefs_to 0x0048ea70` and `xrefs_to 0x0048ea90` returned no direct refs.
- A001's 2026-06-16 active-IDB pass recorded zero absolute pointer-byte hits for raw starts `0x0048ea70` and `0x0048ea90`.
- Current direct PE scan found zero absolute little-endian VA hits for `0x0048ea70` and `0x0048ea90`.
- Current direct PE scan found zero absolute little-endian RVA hits for `0x0008ea70` and `0x0008ea90`.
- Current PE section-aware `E8`/`E9` rel32 scan found zero calls/jumps to `0x0048ea70` and zero calls/jumps to `0x0048ea90`.
- [UID:0003FU] Config vtable has no slot for these wrappers.
- Export directory check found no export table in the executable.

Inference:

The wrappers are likely retained unused private methods or file-private helpers from `Config.cpp`. They are not proven live in this retail executable, but they are source-shaped and Config-specific. Old MSVC/link settings can retain uncalled functions from an object file, especially when not using function-level elimination. This justifies reconstructable source output with descriptive names, while keeping a no-live-route caveat in the target docs.

### Source placement

Best owner/emitter: [UID:0000IE] `Config`.

Evidence:

- The target is a `Config` field wrapper pair and does not touch registry APIs.
- The field is constructed in `Config::Config`, deleted in Config/RegistryConfig destructor paths, read/written by Config string helpers, and serialized by RegistryConfig as inherited/base config state.
- Adjacent [UID:00032I] is already Config-owned and uses the same field with live MIDI/UI consumer calls.
- The containing aggregate [UID:000110] is a mixed inventory and explicitly routes `00032H` and `00032I` to Config.

Rejected placements:

- [UID:0000N4] `RegistryConfig`: persistence consumer only; the wrappers are not registry load/save methods.
- [UID:0000LD] `MidiPlayer`: consumer only; `MidiPlayer` calls Config string helpers, not these wrappers.
- [UID:000079] `List`: callee/helper owner only; the wrappers are Config-specific forwarding methods.
- New `ConfigEntry.cpp`: not justified for this target alone. The list field, string helpers, raw wrappers, constructor, and destructor all fit the existing `config/Config.cpp` route.

### First-draft C++ readiness

The target clears the active code-entry gate:

- `RECONSTRUCTABLE:TRUE`.
- Nonblank `EMITTER_UIDS:0000IE`.
- Generated route surfaces to `auto-generated/NexusTK/config/Config.cpp`.
- Current score average is already above 85, and the recommended score is `88/90`.

First-draft C++ is appropriate because:

- The exact target range contains only two source-shaped helper bodies plus padding.
- The callee and field semantics are resolved enough for source-facing code.
- Leaving blank C++ would preserve an empty emitter marker despite a straightforward wrapper implementation.

Safety caveats:

- Method names are descriptive, not original-proof.
- Return type is inferred as `void`; no live caller exists to prove whether a returned `List*` from `AssignFrom` was ever observed. `void` is the better mid-2000s source shape for copy wrappers with side effects.
- The `List::AssignFrom` declaration should exist in `List` support source before final build integration.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0048ea70-0x0048ea85` | part of `00032H` | copy Config MIDI track-path list to caller list | yes | [UID:0000IE] `Config` | recommend `88/90` target | source-authored retained helper, no direct route found |
| `0x0048ea85-0x0048ea90` | ignored internal padding | `0xcc` alignment | no | none | 100% if ledgered | already documented as padding in aggregate/ignored ledger |
| `0x0048ea90-0x0048ea9f` | part of `00032H` | copy caller list into Config MIDI track-path list | yes | [UID:0000IE] `Config` | recommend `88/90` target | source-authored retained helper, no direct route found |
| `0x0048ea9f-0x0048eaa0` | successor padding | `0xcc` before `00032I` | no | none | 100% if ledgered | documented by containing aggregate/ignored ledger |

No split is recommended. The page already cleanly covers the two adjacent same-owner wrappers and their internal padding.

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0048ea70` | no `lookup_funcs` function object; no xrefs; no rel32 or absolute pointer route found | raw retained wrapper start, not live-routed in current evidence |
| `0x0048ea7c` | rel32 call to `0x004f3140` | copy-out wrapper calls `List::AssignFrom` |
| `0x0048ea90` | no `lookup_funcs` function object; no xrefs; no rel32 or absolute pointer route found | raw retained tail wrapper start, not live-routed in current evidence |
| `0x0048ea9a` | rel32 jump to `0x004f3140` | copy-in wrapper tail-jumps to `List::AssignFrom` |
| `0x0048e6a9` | constructor write to `[this + 0x2912b4]` | stores heap-allocated `List(0x42, 0x10)` |
| `0x0048e7a8`, `0x0048e7be`, `0x00494048`, `0x00494065` | destructor/cleanup refs to `[this + 0x2912b4]` | virtual delete and nulling of the list field |
| `0x0048eaa0`, `0x0048eb00` helpers | read `[this + 0x2912b4]`, call virtual slot `+0x10` | selector/path lookup and setter over same list |
| `0x004922ca`, `0x004922e2`, `0x004936df`, `0x004937d8` | registry save/load refs to `[this + 0x2912b4]` | persistence of MIDI track-path entries |

## Documentation Evidence And IDA Status

Existing docs that support the conclusion:

- [UID:00032H] already records exact wrapper disassembly, no IDA function objects, no xrefs, and Config ownership.
- [UID:0003JT] resolves `sub_4F3140` as `List::AssignFrom`.
- [UID:00032I] documents same field use for selector lookup/setter and MIDI consumer callers.
- [UID:0000IE] and [UID:000031] route Config helper children through `NexusTK/config/Config.cpp`.
- [UID:000110] records the surrounding mixed aggregate split and same Config owner for `00032H` and `00032I`.
- [UID:0001CH] links the Config string helper behavior to MIDI track selection.

Existing docs that need refresh:

- `00032H` still says `sub_4F3140` and `this + 0x2912b4`; replace with `List::AssignFrom` and `m_midiTrackPaths`.
- `00032H` currently describes "copy/append wrappers"; neither wrapper appends. Both perform full `List::AssignFrom` list replacement/copy.
- `Config.md`, `Config` class, and `00032I` use vague "config-entry vector" wording. Update to "MIDI track-path list" while preserving the historical relationship to Config entry/string helper docs.
- `ListAssignFrom.md` says the final name is provisional because callers need semantic review. This target supplies that review for the two callers: `AssignFrom`/`CopyFrom` remains the right source direction.

Generated/coverage report state:

- `auto-generated/NexusTK/config/Config.cpp` currently emits an empty marker for `00032H`.
- `auto-generated/-ag-memory-coverage.md` shows `00032H` as `emits`, owner/emitter `0000IE`, but `no` C++.
- `by-memory/-coverage-report.md` row is stale because it still names raw `sub_4F3140` and omits the no-route byte scan plus field/type/name resolution.

## Ranked Ownership Analysis

### 1. [UID:0000IE] `Config` / `NexusTK/config/Config.cpp`

Evidence for:

- Direct member field access on `Config + 0x2912b4`.
- Constructor allocation and destructor deletion of the same field.
- Adjacent Config string helpers use the same field and have live callers through `g_pConfig`.
- The list stores configuration data persisted by RegistryConfig but consumed through base Config helpers.
- Existing aggregate split already routes the child to Config.

Evidence against:

- No direct caller route proves live method use.
- Original method names are not recovered.

Decision: accepted. The negative evidence affects liveness/name confidence, not source owner.

### 2. [UID:000031] `Config` class

Evidence for:

- These wrappers are semantically `Config` methods.
- They access a `Config` member and take/return no separate file-global state.

Evidence against:

- Current target owner/emitter is the Config file, not the class, likely because the class declaration and full field map are not source-ready.
- The target page is a raw helper gap from the file-level split, not a vtable-reached class method page.

Decision: support class docs should mention the methods/field, but keep target owner/emitter [UID:0000IE] unless a broader class declaration implementation callback reroutes all private Config helpers through [UID:000031].

### 3. [UID:0000N4] `RegistryConfig`

Evidence for:

- Registry save/load methods serialize/read the list.
- The concrete runtime instance is likely `RegistryConfig`.

Evidence against:

- Persistence is consumer/derived-class behavior. The list is base Config storage constructed in `Config::Config`, deleted in base cleanup, and accessed by Config helpers.
- The wrappers do not use registry APIs, registry literals, or RegistryConfig-only fields.

Decision: rejected as direct owner.

### 4. [UID:0000LD] `MidiPlayer`

Evidence for:

- MIDI track selection consumes the selector/path helpers.

Evidence against:

- MIDI code calls Config helper functions through `g_pConfig`; it does not own the storage or wrappers.
- The wrappers do not touch MidiPlayer object/global state.

Decision: rejected as owner; useful consumer evidence for field naming.

### 5. [UID:000079] `List`

Evidence for:

- The target calls `List::AssignFrom`.

Evidence against:

- The wrappers are not generic `List` methods. They are Config forwarding wrappers around a Config-owned `List*`.

Decision: rejected as owner; keep as dependency/callee.

## Negative Evidence Summary

- No IDA function objects at `0x0048ea70` or `0x0048ea90`.
- No IDA xrefs to either wrapper start in existing docs.
- No absolute VA or RVA pointer hits for either wrapper start in direct PE scan.
- No section-aware rel32 calls/jumps to either wrapper start in direct PE scan.
- No Config vtable slot points to either wrapper.
- No export directory exists.

Impact:

- Do not claim these wrappers are proven live in this retail executable.
- Do not lower them to ignored/generated/compiler output; their instruction bodies are source-authored, Config-specific, and meaningful.
- Keep confidence below final-audit levels and mark names descriptive/inferred.

## Recommended Exact Doc Changes

### Target: `by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md`

1. Change metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Keep:

```text
*** CANONICAL_OWNER:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

2. Populate the C++ block with:

```cpp
void Config::CopyMidiTrackPathsTo(List *destination) const
{
    destination->AssignFrom(m_midiTrackPaths);
}

void Config::CopyMidiTrackPathsFrom(List *source)
{
    m_midiTrackPaths->AssignFrom(source);
}
```

3. Update status/source-facing role:

```text
- Source-facing role: retained private Config wrappers that copy the MIDI track-path `List` at `m_midiTrackPaths` (`this + 0x2912b4`) to/from a caller-supplied `List` through `List::AssignFrom`.
```

4. Update covered ranges:

```text
| `0x0048ea70-0x0048ea85` | `Config::CopyMidiTrackPathsTo` / copy-out wrapper | Calls `destination->AssignFrom(m_midiTrackPaths)`. No direct route to this raw start is currently known. |
| `0x0048ea85-0x0048ea90` | padding | Eleven `0xcc` alignment bytes. |
| `0x0048ea90-0x0048ea9f` | `Config::CopyMidiTrackPathsFrom` / copy-in wrapper | Tail-jumps to `m_midiTrackPaths->AssignFrom(source)`. No direct route to this raw start is currently known. |
```

5. Replace raw IDA evidence bullets with current evidence:

- Use `List::AssignFrom` instead of `sub_4F3140`.
- Correct the second wrapper jump displacement to `e9 a1 46 06 00`.
- Record direct PE no-route scan results: no absolute VA/RVA pointer hits, no rel32 call/jump hits to either start, no export table, no vtable slot.
- Record that the two rel32 refs to `0x004f3140` are exactly `0x0048ea7c` and `0x0048ea9a`.

6. Add a touched-state / field section:

```text
`m_midiTrackPaths` at `Config + 0x2912b4` is a heap `List*` constructed as `List(0x42, 0x10)`, meaning 66-byte entries and 16-entry pages. The entry shape is inferred as selector byte plus fixed wide string at offset `+2`. Adjacent helpers [UID:00032I] scan the same list for MIDI track path lookup/setter behavior, and registry save/load paths persist it under the `Midi` subkey.
```

7. Add a change entry for the B005 report:

```text
- 2026-06-19 B005 source-quality report:
  - Recommended `85/86 -> 88/90`, kept owner/emitter [UID:0000IE], resolved `sub_4F3140` as `List::AssignFrom`, resolved `this + 0x2912b4` as descriptive `Config::m_midiTrackPaths`, and recommended first-draft C++ for the copy-out/copy-in wrappers.
  - Evidence: direct PE byte scan confirms exact wrapper bytes and padding; section-aware rel32 scan finds no route to either raw start and only the two expected refs to `List::AssignFrom`; constructor bytes allocate `List(0x42, 0x10)` into `+0x2912b4`; adjacent string helpers, registry persistence, and MIDI caller docs confirm MIDI track-path semantics.
```

### Support: `by-file/Config.md`

Recommended updates:

- In proposed contents, change "Config-entry vector wrappers" to "MIDI track-path list copy wrappers" or add that phrase next to the existing row.
- Replace "raw wrappers forwarding the Config member at `this + 0x2912b4` to a shared copy helper" with:

```text
retained private wrappers copying `m_midiTrackPaths` (`List*`, constructed as `List(0x42, 0x10)`) to/from caller-supplied `List` objects through `List::AssignFrom`; no direct call/pointer/export/vtable route is known in the retail binary.
```

- Recommended score update: `87/86 -> 88/88` if the target and `00032I` support details are incorporated. The file still remains below final-source confidence because broader Config field names and header/source declarations remain open.

### Support: `by-class/Config.md`

Recommended updates:

- Add a field/layout note:

```text
`m_midiTrackPaths` at `+0x2912b4` is a heap `List*` constructed as `List(0x42, 0x10)`. Entries are inferred `ConfigMidiTrackPathEntry` records: one-byte selector, one byte padding, and a fixed 32-wide-character path at `+2`.
```

- Add private helper rows for the target's two wrappers using the descriptive names above.
- Keep class C++ blank unless the supervisor accepts a broader class declaration update. The field is resolved, but the class still has many large unresolved members.
- Recommended score update: `85/86 -> 86/88` after adding this field/method evidence.

### Support: `by-memory/0x0048eaa0-0x0048ebb3.ConfigStringPreferenceHelpers.md`

Recommended updates:

- Replace `config-entry vector at this + 0x2912b4` with `m_midiTrackPaths`.
- Add constructor/type evidence: `List(0x42, 0x10)`, 66-byte entries, selector byte, wide string at `+2`.
- Rename behavior rows to "MIDI track-path lookup" and "MIDI track-path setter" while keeping the broader Config preference wording as context.
- Recommended score update: `86/88 -> 87/89` if this field/type evidence is incorporated.

### Support: `by-memory/0x004f3140-0x004f31cc.ListAssignFrom.md`

Recommended updates:

- Add caller-semantics note:

```text
The two current caller refs at `0x0048ea7c` and `0x0048ea9a` come from [UID:00032H] Config MIDI track-path copy wrappers. They support `AssignFrom`/`CopyFrom` naming: one wrapper assigns the Config list into an external list, and the other assigns an external list into the Config list.
```

- No metadata change required unless the List API naming pass is also being implemented.

### Support: `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md` and `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`

Recommended updates:

- Where these pages discuss the indirect collection/list interface behind MIDI/registry entries, link to `00032H`/`00032I` and call the field `m_midiTrackPaths`.
- Do not move ownership to RegistryConfig; these pages persist/restore the base Config field.

## Exact Pending Coverage Replacement Row

Do not edit `by-memory/-coverage-report.md` during this report-only pass. If implementation is accepted, replace the current `00032H` row with exactly:

```text
        - [UID:00032H][0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw](by-memory/0x0048ea70-0x0048ea9f.ConfigEntryVectorCopyWrappersRaw.md) 0x0048ea70-0x0048ea9f | raw wrapper pair | ConfigEntryVectorCopyWrappersRaw : reconstructable : 88% : very strong : Source-quality recheck keeps owner/emitter [UID:0000IE][Config](by-file/Config.md) and resolves the raw wrappers as retained private Config MIDI track-path list copy helpers: `0x0048ea70` copies `m_midiTrackPaths` (`Config +0x2912b4`, heap `List*`, `List(0x42,0x10)`) into a caller list through `List::AssignFrom`, while `0x0048ea90` copies a caller list back into `m_midiTrackPaths` via a tail jump to `List::AssignFrom`. Direct PE route search found no calls/jumps, VA/RVA pointer hits, export, or vtable route to either raw start; exact bytes, constructor/destructor field use, adjacent MIDI path helpers, and registry persistence support reconstructing first-draft private Config C++.
```

## Validator Needs

No validators were run because this was report-only and no by-* docs were edited.

If implementation is accepted, run from `source-3/project-documentation` after edits:

> Executable block R001 was removed from this report and preserved verbatim in [00032H-ConfigEntryVectorCopyWrappersRaw-source-quality-removed.md](00032H-ConfigEntryVectorCopyWrappersRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only run the support-doc commands for files actually touched. If generated output changes, report `auto-generated/NexusTK/config/Config.cpp`, `auto-generated/-ag-memory-coverage.md`, and any projected stats files changed by the validator/autogen refresh.

## IDA Rename / Type / Comment Recommendations

No IDA changes were made.

Recommended future IDA actions if an IDA edit pass is authorized:

- Create/label function at `0x0048ea70` as `Config::CopyMidiTrackPathsTo` or `Config_CopyMidiTrackPathsTo`; confidence high for behavior, medium for original name.
- Create/label function at `0x0048ea90` as `Config::CopyMidiTrackPathsFrom` or `Config_CopyMidiTrackPathsFrom`; confidence high for behavior, medium for original name.
- Rename/comment `0x004f3140` as `List::AssignFrom` / `List::CopyFrom`; confidence high for helper role.
- Add `Config + 0x2912b4` field comment/name `m_midiTrackPaths`; type `List*`; confidence high for type, medium-high for exact name.
- Add local type/comment for list entry shape:

```cpp
struct ConfigMidiTrackPathEntry {
    unsigned char selector;
    unsigned char reserved;
    wchar_t path[32];
};
```

- Add repeatable comments to both wrapper starts: "no known direct refs; retained private Config helper".
- Do not use raw names `sub_4F3140`, `dword` field labels, or broad `ConfigEntryVector` wording in source-facing comments without a MIDI/list clarification.

## Open Questions And Attempted Resolution

- Exact original wrapper names: unresolved. No caller names, symbols, or vtable slots survived. Descriptive `CopyMidiTrackPathsTo` / `CopyMidiTrackPathsFrom` is the best-supported direction.
- Return type: no live callers prove whether any `AssignFrom` return value was observed. `void` is recommended because both wrappers are side-effect-only copy helpers.
- Exact record type name: unresolved. `ConfigMidiTrackPathEntry` is descriptive/inferred from size and use.
- Liveness: no route found. This should be preserved as a caveat but should not block source C++ because the wrappers are source-authored retained code, not compiler-generated glue.
- Full Config class declaration: still not ready from this target alone. This report resolves one field and two private wrappers; broader Config fields/destructor/source split remain class-level work.

## Implementation Readiness

Ready for supervisor implementation callback.

Recommended implementation scope:

- Update target `00032H` metadata/prose/C++.
- Update Config file/class support docs with `m_midiTrackPaths`, `List(0x42,0x10)`, no-route search, and first-draft wrapper names.
- Update `00032I` to use the same field/record names.
- Optionally update `ListAssignFrom` with the caller-semantics note.
- Do not edit `by-memory/-coverage-report.md`; use the exact replacement row above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/00032H-ConfigEntryVectorCopyWrappersRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"00032H"} -->
<!-- {"agent":"B005","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00032H-ConfigEntryVectorCopyWrappersRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B005/00032H-ConfigEntryVectorCopyWrappersRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00032H"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
