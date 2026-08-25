** TARGET-REPORT-UID:00032G **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Research: 00032G RegistryConfigTypeProbeRaw

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00032G] as a reconstructable RegistryConfig file-level helper owned and emitted by [UID:0000N4] `RegistryConfig`.
- Final disposition: source-authored or retained source helper, not compiler/runtime glue and not a `RegistryConfig` class method.
- Required action: update the target and support docs to resolve the raw names, correct the subkey semantics from "computer/machine-specific" to "current-directory/install-directory", document the no-xref route search, raise score to `88/89`, and add first-draft file-static C++ unless the supervisor explicitly applies a marker-only retained-code policy.
- Confidence: strong for raw behavior, boundaries, Win32 API names, registry path/value semantics, and file owner; medium for original helper spelling and whether any source caller was optimized/removed or the helper was retained as dead code.

## Target

- Target UID: `00032G`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\00032G-RegistryConfigTypeProbeRaw-source-quality.md`
- Current target score: `85/86`
- Current owner/emitter: `CANONICAL_OWNER:0000N4`, `EMITTER_UIDS:0000N4`
- Current C++: blank
- Report-only status: no by-* docs, generated files, IDA database, or coverage files were edited.

## Supporting Research

### Evidence Checked

Required and support docs:

- `source-3/project-documentation/by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md`
- [UID:0000N4] `by-file/RegistryConfig.md`
- [UID:0000BW] `by-class/RegistryConfig.md`
- [UID:000110] `by-memory/0x0048e480-0x0048f3f1.ConfigAndRegistryDefaults.md`
- [UID:00030U] `by-memory/0x0048e860-0x0048e94f.RegistryConfigLoadOrInitialize.md`
- [UID:0002P7] `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`
- [UID:0002P8] `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`
- [UID:000220] `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`
- [UID:0003FV] `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- [UID:0003FW] `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md`
- [UID:0003FX] `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`
- [UID:000251] `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md`
- [UID:0002VB] `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`
- [UID:0003TY] `by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md`
- `project-level/-unresolved.md`, `project-level/-resolved.md`
- `auto-generated/-ag-memory-coverage.md`
- `by-memory/-coverage-report.md` as read-only evidence
- Existing executed B001 report: `tools/leaser/Agents/Agent-B001/research/executed/older/000110-ConfigAndRegistryDefaults.md`

Direct binary evidence:

- Read-only binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247E04E20B65D6414C7238AA8FF5515`
- Direct PE section/import parsing and Capstone x86 disassembly.
- IDA MCP endpoint `http://127.0.0.1:13337/mcp` was checked but not reachable in this session. Existing docs' IDA MCP facts were treated as documentation evidence and rechecked with direct PE bytes where possible.

### Direct Binary Facts

The range `0x0048e950-0x0048ea6e` is a complete raw function-shaped body:

- `0x0048e950`: `push ebp`
- stack frame size: `0x224`
- stack-cookie setup through `dword_672f24`
- failure return at `0x0048e9f1`
- success/normal return at `0x0048ea6d`
- predecessor byte `0x0048e94f` is `0xcc`
- successor bytes `0x0048ea6e-0x0048ea70` are `0xcc 0xcc`

The helper performs this sequence:

1. Calls the dynamic slot at `dword_69BE94`, resolved to `RegCreateKeyExW`, with:
   - root handle `0x80000002` (`HKEY_LOCAL_MACHINE`)
   - subkey `0x006168e8`, wide `SOFTWARE\Nexon\Kingdom of the Winds`
   - access mask `0x20019` (`KEY_READ`)
   - output handle local at `[ebp-0x210]`
   - disposition local at `[ebp-0x21c]`
2. On failure, returns `0`.
3. Calls the dynamic slot at `dword_69BE70`, resolved to `GetCurrentDirectoryW`, with:
   - length `0x104`
   - output buffer local at `[ebp-0x20c]`
4. Calls `RegCreateKeyExW` again, this time with:
   - parent handle `[ebp-0x210]`
   - subkey equal to the current-directory buffer
   - access mask `0x20019`
   - output handle local at `[ebp-0x218]`
5. If the second key open/create fails, closes the root handle and returns `0`.
6. Initializes `[ebp-0x214]` to `4` and calls `dword_69BEA4`, resolved to `RegQueryValueExW`, with:
   - key `[ebp-0x218]`
   - value name `0x00616930`, wide `Type`
   - `lpType` at `[ebp-0x220]`
   - `lpData` at `[ebp-0x224]`
   - `lpcbData` at `[ebp-0x214]`
7. Accepts the result only when:
   - `RegQueryValueExW` returns success
   - returned registry value type is `4` (`REG_DWORD`)
   - returned data length is `4`
8. Returns the low byte of the DWORD data on success, otherwise `0`.
9. Closes the child key and root key on the success-path cleanup.

Recommended local variable roles:

| Stack location | Source-facing role |
| --- | --- |
| `[ebp-0x224]` | `DWORD typeValue` |
| `[ebp-0x220]` | `DWORD valueType` |
| `[ebp-0x21c]` | `DWORD disposition` |
| `[ebp-0x218]` | `HKEY installKey` / current-directory child key |
| `[ebp-0x214]` | `DWORD valueSize` |
| `[ebp-0x210]` | `HKEY rootKey` |
| `[ebp-0x20c]` | `wchar_t currentDirectory[MAX_PATH]` |

### Import / Dispatch Slot Resolution

The target doc should stop listing raw import slots as unresolved. Direct PE import and initializer evidence supports these mappings:

| Raw name | Resolved source/import name | Evidence |
| --- | --- | --- |
| `dword_69BE94` | `RegCreateKeyExW` | Initializer at `0x0041a3e3-0x0041a3e8` copies IAT `0x0060d01c`; target calls at `0x0048e988` and `0x0048e9cc` use `RegCreateKeyExW` argument order. |
| `dword_69BE70` | `GetCurrentDirectoryW` | Initializer at `0x0041a389-0x0041a38e` copies IAT `0x0060d26c`; target call at `0x0048e99e` passes `0x104` and a wide buffer. |
| `dword_69BEA4` | `RegQueryValueExW` | Initializer at `0x0041a40b-0x0041a410` copies IAT `0x0060d014`; target call at `0x0048ea1f` uses `HKEY, valueName, reserved, lpType, lpData, lpcbData`. |
| IAT `0x0060d010` | `RegCloseKey` | Imported directly from `ADVAPI32.dll`; target calls at `0x0048e9dc`, `0x0048ea4b`, and `0x0048ea57`. |

This resolves all raw helper/import names in the current target scope.

### Registry Key And `Type` Semantics

The current target doc says "obtains the computer name" and "machine-specific subkey." That is not supported by the raw code. The helper obtains the current directory with `GetCurrentDirectoryW`, then uses that string as the child key under:

```text
HKEY_LOCAL_MACHINE\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type
```

Best source-facing interpretation:

- The subkey is per-installation or per-current-directory state, not computer-name state.
- The Application constructor and related startup paths set current directory from the executable path, so "current-directory" likely means the client install directory during normal startup.
- The `Type` value is probably an install/channel/distribution discriminator set by an external installer, launcher, or channel integration path.
- The helper returns the low byte of a `REG_DWORD` `Type` value, defaulting to `0` for missing, malformed, or inaccessible registry state.

Rejected interpretations:

- Not a class/type-id probe. It never touches `this`, vtables, or object storage.
- Not a general RegistryConfig option. The `Type` literal has only the target xref at `0x0048ea14` and lives in [UID:0003FV] channel/startup string data, not the main option-key cluster [UID:0003FW].
- Not a computer-name/machine-name subkey. No `GetComputerNameW` import/call appears in the target; the actual call is `GetCurrentDirectoryW`.
- Not simply the `lpType` out-parameter of `RegQueryValueExW`. There are two related meanings: value name `Type`, and returned registry value type `REG_DWORD`.

### Reachability / Liveness Search

Direct route search results from direct PE evidence:

- No VA dword references to `0x0048e950`.
- No RVA dword references to `0x0008e950`.
- No VA/RVA dword references to the final return address checked as a route sanity check.
- No `E8`/`E9` rel32 call/jump references to `0x0048e950`.
- Existing IDA MCP evidence in target/support docs reports no function object and no `xrefs_to 0x0048e950`.
- The predecessor `RegistryConfigLoadOrInitialize` body ends with `ret`, followed by `0xcc` at `0x0048e94f`; there is no fallthrough.
- The successor begins after `0x0048ea6e-0x0048ea70` padding; there is no successor fallthrough into this body.
- A broad raw scan did not produce a usable callable entry route. The only non-start dword-like interior hit found during exploration points into the target epilogue area rather than the prologue and should be rejected as a route unless future disassembly proves otherwise.

Conclusion: this is source-shaped retained code with no currently proven runtime caller. It should be documented as a retained/private raw helper or dead helper body. That does not force owner/emitter removal because the body is RegistryConfig-specific and already has a valid file route, but it should cap confidence below final-audit level.

### Neighbor And Sibling Evidence

The root/current-directory registry pattern appears in three places:

- [UID:00032G] at `0x0048e97e` / `0x0048e9bf`: reads current-directory `Type` under the uppercase root.
- [UID:0002P7] `SaveToRegistry` near `0x0049262e`: opens the same uppercase root and a current-directory subkey near the save tail.
- [UID:0003TY] `MapPaneHandleMapTransitionPacket` around `0x0051006d`: opens the same uppercase root and current-directory subkey as part of transfer/transition handling.

Only [UID:00032G] references the `Type` value name at `0x00616930`. This supports keeping the helper in RegistryConfig/source-startup territory while describing the `Type` value as a narrow channel/install discriminator whose live caller is not currently recovered.

## Heuristic / Inference Reanalysis And Validation

### Source Placement

Best placement remains [UID:0000N4] `RegistryConfig` / `NexusTK/config/RegistryConfig.cpp`.

Evidence for:

- The helper uses RegistryConfig-owned string data [UID:0003FV].
- It sits in the exact Config/RegistryConfig defaults island [UID:000110].
- It uses the same root registry key family as `SaveToRegistry` and `LoadFromRegistry`.
- The helper has no `this` and no vtable route, making file-level placement stronger than class-method placement.
- [UID:0000N4] already owns other file-level raw/retained RegistryConfig helpers, including [UID:0002VB].

Evidence against:

- No direct caller or function object is recovered.
- Original helper spelling is not symbol-proven.

Decision: keep `CANONICAL_OWNER:0000N4` and `EMITTER_UIDS:0000N4`. Do not move to [UID:0000BW] because this is not a method.

### Ownership Alternatives

1. [UID:0000N4] `RegistryConfig` file root
   - Accepted. It best represents file-private registry/startup helper code with no class `this` parameter.

2. [UID:0000BW] `RegistryConfig` class
   - Rejected as direct owner. RegistryConfig class docs should reference this helper, but the helper has no `this`, no vtable slot, and no class-method call edge.

3. [UID:0000IE] `Config`
   - Rejected. The body does not touch base Config entry storage, `g_pConfig`, or Config helper state.

4. [UID:000220] `RegistryCommandLineParsers`
   - Rejected as direct owner. The helper is adjacent to that source island and uses channel/startup strings, but it is not a command-line parser and sits before the parser island boundary.

5. Leave no-owner/non-emitting
   - Rejected. The missing caller is real, but the code is RegistryConfig-specific, the file parent clears the gate, and [UID:0002VB] establishes the same no-xref retained-helper policy for this source file.

### Raw Helper Liveness

Best inference: retained, possibly dead, file-static helper. It may have been called in an earlier source configuration, from a source path not represented by direct binary references after optimization/linking, or kept because the object file was linked as a whole. No evidence supports an active direct runtime route in the current binary.

Score impact: cap confidence below `90`; do not call it live. This does not block first-draft C++ because the page owns an exact function-shaped source body and the generated source can contain a file-static retained helper.

### Source-Facing Name

Recommended descriptive names:

- Documentation/title can keep `RegistryConfigTypeProbeRaw`.
- Source-facing helper: `QueryInstallRegistryType` or `RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey`.
- IDA label if creating a function: `RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey`.

Reasoning: the value is not a C++ type and not a machine name. The clearest source meaning is "query the per-install/current-directory registry `Type` DWORD".

### `Type` Value Name

Recommended field/value name in prose:

- `installType`
- `channelType`
- `distributionType`

Use `installType` as the safest first-draft variable. It is descriptive and does not overclaim which ISP/channel set the value.

### C++ Readiness

The item qualifies under the current code-entry gate:

- `RECONSTRUCTABLE:TRUE`
- nonblank emitter route through [UID:0000N4] to `auto-generated/NexusTK/config/RegistryConfig.cpp`
- current average `(85 + 86) / 2 = 85.5`, and recommended score is higher
- exact body, boundaries, imports, strings, and cleanup behavior are understood

Primary recommendation: add first-draft C++ as a `static` helper in the target doc.

Marker-only fallback: if the supervisor applies a strict "no direct xref raw retained helper must not emit function bodies" policy, keep the target C++ block as a nonempty marker comment such as:

```cpp
// Retained RegistryConfig raw helper; documented in by-memory, no proven runtime caller in this build.
```

That fallback is weaker than emitting the helper body. It should only be used if generated output policy prefers markers for no-xref retained helpers.

## First-Draft C++ Recommendation

Recommended formal C++ for the target:

```cpp
static unsigned char QueryInstallRegistryType()
{
    HKEY rootKey;
    HKEY installKey;
    DWORD disposition;
    DWORD valueType;
    DWORD valueSize;
    DWORD typeValue;
    wchar_t currentDirectory[MAX_PATH];
    unsigned char result = 0;

    if (RegCreateKeyExW(HKEY_LOCAL_MACHINE,
                        L"SOFTWARE\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return 0;
    }

    GetCurrentDirectoryW(MAX_PATH, currentDirectory);

    if (RegCreateKeyExW(rootKey,
                        currentDirectory,
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &installKey,
                        &disposition) != ERROR_SUCCESS)
    {
        RegCloseKey(rootKey);
        return 0;
    }

    valueSize = sizeof(typeValue);
    if (RegQueryValueExW(installKey,
                         L"Type",
                         0,
                         &valueType,
                         reinterpret_cast<BYTE *>(&typeValue),
                         &valueSize) == ERROR_SUCCESS &&
        valueType == REG_DWORD &&
        valueSize == sizeof(typeValue))
    {
        result = static_cast<unsigned char>(typeValue);
    }

    RegCloseKey(installKey);
    RegCloseKey(rootKey);
    return result;
}
```

Notes for implementation:

- The source name is descriptive, not symbol-proven.
- The source intentionally ignores `GetCurrentDirectoryW` failure, matching the binary's lack of a return-value check.
- Use `KEY_READ` rather than raw `0x20019`.
- Use `HKEY_LOCAL_MACHINE` rather than raw `0x80000002`.
- The function returns a byte even though the registry value is a DWORD. The binary returns only the low byte.

## Recommended Exact Doc Changes

### Target [UID:00032G]

Recommended target edits:

- Change current score from `85/86` to `88/89`.
- Keep `CANONICAL_OWNER:0000N4`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `EMITTER_UIDS:0000N4`.
- Replace "computer name" and "machine-specific subkey" wording with:

```text
The helper opens `HKLM\SOFTWARE\Nexon\Kingdom of the Winds`, calls `GetCurrentDirectoryW(MAX_PATH, ...)`, opens or creates the current-directory child key, queries value name `Type`, accepts only a `REG_DWORD` with a four-byte payload, returns the low byte of that DWORD, and returns `0` on any open/query/type/size failure.
```

- Replace raw helper/import prose with:
  - `dword_69BE94` -> `RegCreateKeyExW`
  - `dword_69BE70` -> `GetCurrentDirectoryW`
  - `dword_69BEA4` -> `RegQueryValueExW`
  - `RegCloseKey` -> direct import/IAT `ADVAPI32!RegCloseKey`
- Add local layout table from this report.
- Add reachability section:
  - no IDA function object
  - no direct xrefs
  - no VA/RVA pointer hits to start
  - no rel32 call/jump hits to start
  - no fallthrough from predecessor/successor
  - conclusion: retained no-xref file helper, not proven live
- Add source placement section:
  - file-level [UID:0000N4] helper
  - not [UID:0000BW] class method
  - not [UID:0000IE] Config storage helper
- Insert the first-draft C++ above unless the supervisor chooses the marker-only fallback.

### RegistryConfig File [UID:0000N4]

Recommended updates:

- Update the proposed contents row for [UID:00032G] to say:

```text
Private file-static retained helper that queries `HKLM\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type`, validates the value as a 4-byte `REG_DWORD`, and returns the low byte as an install/channel type. It has no direct xrefs in the current binary, so it is file-level retained code rather than a `RegistryConfig` class method.
```

- Add `QueryInstallRegistryType` / `RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey` as the source-facing descriptive name.
- Mention that the prior "computer-name" wording is superseded by direct `GetCurrentDirectoryW` evidence.

### RegistryConfig Class [UID:0000BW]

Recommended updates:

- Keep [UID:00032G] as a file-helper reference only.
- Replace "reads the `Type` value" with the current-directory key semantics.
- Do not add it to the method table as a class method.
- Keep class scores unchanged unless a broader RegistryConfig source-quality pass is done.

### ConfigAndRegistryDefaults Aggregate [UID:000110]

Recommended update to the exact child map row:

```text
Raw unmodeled RegistryConfig file helper; no direct xrefs, but raw code opens `HKLM\SOFTWARE\Nexon\Kingdom of the Winds`, derives a current-directory/install child key through `GetCurrentDirectoryW`, queries `Type`, validates `REG_DWORD` and four-byte size, returns the low byte, and closes both registry handles.
```

### RegistryConfig Channel Startup String Data [UID:0003FV]

Recommended updates:

- For `0x00616930` wide `Type`, add:

```text
The only current xref is [UID:00032G] at `0x0048ea14`. In that helper it is a registry value name under the current-directory child key, not a C++ type name or ordinary option key.
```

- Consider adding a note that `0x006168e8` root is shared by [UID:00032G], [UID:0002P7], and [UID:0003TY].

### Save/Load And MapPane Support Docs

Recommended support notes:

- [UID:0002P7] `SaveToRegistry`: add a cross-reference that its uppercase root/current-directory tail pattern is the save-side sibling of the [UID:00032G] install-directory probe, while `Type` itself is not in the normal save option inventory.
- [UID:0002P8] `LoadFromRegistry`: no direct behavior change required, but a cross-reference to [UID:00032G] may help distinguish the main option load from the retained `Type` probe.
- [UID:0003TY] `MapPaneHandleMapTransitionPacket`: if this page is later improved, note that the registry helper route also uses `GetCurrentDirectoryW` and the uppercase root; do not claim this is a caller of [UID:00032G].

## IDA Rename / Type / Comment Recommendations

No IDA database edits were made. If an IDA cleanup pass is authorized:

- Create function at `0x0048e950-0x0048ea6e` only if the project accepts no-xref raw function creation.
  - Suggested name: `RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey`
  - Confidence: high for role, medium for original spelling.
  - Type: `unsigned char __cdecl RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey(void)`
- Rename/comment dynamic dispatch slots if not already done:
  - `dword_69BE94` -> `pRegCreateKeyExW` or `RegCreateKeyExW_dispatch`
  - `dword_69BE70` -> `pGetCurrentDirectoryW` or `GetCurrentDirectoryW_dispatch`
  - `dword_69BEA4` -> `pRegQueryValueExW` or `RegQueryValueExW_dispatch`
- Add comment at `0x0048e99e`:
  - `GetCurrentDirectoryW(MAX_PATH, currentDirectory); current directory becomes registry child key`
- Add comment at `0x0048ea1f`:
  - `RegQueryValueExW(childKey, L"Type", ..., &valueType, &typeValue, &valueSize)`
- Add comment at `0x0048ea29-0x0048ea3b`:
  - `accept only REG_DWORD with sizeof(DWORD); return low byte`

## Open Questions With Attempted Resolution

- Original helper name: unresolved. No symbol/source proof exists. Best descriptive names are `QueryInstallRegistryType` or `RegistryConfig_QueryInstallTypeFromCurrentDirectoryKey`; this does not block target C++.
- Runtime caller: unresolved after route search. No direct call, no pointer table, no VA/RVA start hit, and no fallthrough were found. Treat as retained no-xref helper/dead helper body; this caps confidence but does not invalidate RegistryConfig file ownership.
- Exact `Type` value meaning: partially unresolved. Evidence supports install/channel/distribution type under the current-directory subkey. No current binary consumer proves exact enum values, so do not assign an enum beyond `0` default and byte result.
- "Machine-specific" wording: resolved as wrong for this body. The helper uses `GetCurrentDirectoryW`, not `GetComputerNameW`.

## Score / Metadata Recommendation

Target before:

- `COMPLETION:85`
- `CONFIDENCE:86`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- C++ blank

Recommended after:

- `COMPLETION:88`
- `CONFIDENCE:89`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`
- C++ populated with the file-static helper body, or a nonempty marker only if the supervisor rejects code for no-xref retained helpers

Rationale: the current blockers have been resolved or narrowed. Behavior, imports, stack layout, registry path, `Type` semantics, owner, and no-xref search are now understood. Confidence remains below `90` because original helper spelling, exact external producer of the `Type` value, and live caller status remain unproven.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts the target score and C++ recommendation, replace the current row with:

```text
        - [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md) 0x0048e950-0x0048ea6e | raw file helper | RegistryConfigTypeProbeRaw : reconstructable : 88% : strong : B003 2026-06-19 source-quality reanalysis assigns this retained no-xref helper to [UID:0000N4][RegistryConfig](by-file/RegistryConfig.md), resolves `dword_69BE94` as `RegCreateKeyExW`, `dword_69BE70` as `GetCurrentDirectoryW`, `dword_69BEA4` as `RegQueryValueExW`, corrects the subkey from computer-name to current-directory/install-directory, confirms `HKLM\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type`, validates `REG_DWORD` plus four-byte payload semantics, documents low-byte return and handle cleanup, records no VA/RVA/rel32 start route or fallthrough, and recommends first-draft file-static helper C++.
```

Expected generated memory-coverage row after formal C++ is added and autogen reports are refreshed:

```text
| [UID:00032G][0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw](by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md) | emits | `0000N4` | `0000N4` |  | yes | `auto-generated/NexusTK/config/RegistryConfig.cpp` | `by-memory/0x0048e950-0x0048ea6e.RegistryConfigTypeProbeRaw.md` |  |
```

If the supervisor chooses marker-only retained-code handling, keep the same by-memory coverage row but replace the final phrase with:

```text
and recommends a nonempty retained-helper marker instead of formal function C++ under the no-xref raw-helper policy.
```

## Validator Needs

No validator was run because this was a report-only pass and no by-* docs were edited. After implementation, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [00032G-RegistryConfigTypeProbeRaw-source-quality-removed.md](00032G-RegistryConfigTypeProbeRaw-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If support notes are added to [UID:0002P7], [UID:0002P8], or [UID:0003TY], validate those files in the same style.

## Implementation Readiness

Ready for implementation callback.

The target has a valid owner/emitter route, complete raw behavior, resolved helper/import names, corrected registry semantics, and a plausible mid-2000s file-static C++ body. The only remaining uncertainty is original helper spelling and no-xref liveness, which should be documented as a confidence cap rather than treated as an ownership or C++ blocker.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00032G-RegistryConfigTypeProbeRaw-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"00032G"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00032G-RegistryConfigTypeProbeRaw-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00032G-RegistryConfigTypeProbeRaw-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00032G"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
