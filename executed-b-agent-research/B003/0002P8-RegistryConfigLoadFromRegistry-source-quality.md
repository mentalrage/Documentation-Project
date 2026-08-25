** TARGET-REPORT-UID:0002P8 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B003 source-quality report: [UID:0002P8] RegistryConfigLoadFromRegistry

Status: FINISHED

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002P8-RegistryConfigLoadFromRegistry-source-quality.md`

Primary target: `source-3/project-documentation/by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`

Assignment: B-agent report-only source-quality / heuristic reanalysis for [UID:0002P8] `RegistryConfigLoadFromRegistry`. Do not edit by-* docs or `by-memory/-coverage-report.md` during this pass.

## Executive recommendation

[UID:0002P8] should remain a reconstructable `RegistryConfig` class method owned and emitted by [UID:0000BW] `RegistryConfig`, sourced through [UID:0000N4] `RegistryConfig.cpp`.

Recommended target metadata:

- `COMPLETION:88`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000BW`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000BW`

The active code-entry gate is cleared. The target should no longer keep formal C++ blank because of generic "below 95/95" wording. The method is large and still has some original-member-spelling uncertainty, but the source-facing method identity, boundary, registry API imports, value semantics, helper relationships, cleanup route, and enough field roles are now resolved for a first-draft method body. The by-memory target should emit `bool RegistryConfig::LoadFromRegistry()`; class/file/support docs should carry the inventory and unresolved-name caveats. No range split is recommended.

Main remaining score cap: exact original field/member spellings for the MIDI list object, multi-server entry structure, helper-presence word, and several one-byte option members are inferred from registry names and consumers rather than symbol-proven. This caps completion below 90 even though confidence in the binary behavior is high.

## Evidence checked

Repository/documentation evidence:

- `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md`
- `by-class/RegistryConfig.md`
- `by-file/RegistryConfig.md`
- `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`
- `by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md`
- `by-memory/0x0048eed0-0x0048f3f1.RegistryConfigInitializeDefaults.md`
- `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`
- `by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md`
- `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md`
- `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`
- `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`
- `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md`
- `by-type/by-struct/RegistryConfigUserProfileBlock.md`
- `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`
- `by-memory/-coverage-report.md` current row only, read for exact replacement style.
- `auto-generated/NexusTK/config/RegistryConfig.cpp`; it currently has an empty marker for [UID:0002P8] and a real `QueryInstallRegistryType()` helper for [UID:00032G].
- Prior accepted B003 report `tools/leaser/Agents/Agent-B003/research/executed/00032G-RegistryConfigTypeProbeRaw-source-quality.md` for registry import naming and source-file policy.

Binary evidence:

- Binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- Manual PE parse and Capstone disassembly of `0x004926a0-0x00493e29`.
- String-reference scan of the target body.
- Direct call/import scan of the target body.
- Object-offset scan for `[ebx + imm]` writes/reads inside the body.
- Manual cross-check against adjacent child docs for padding and post-body helper boundaries.

## Boundary and range decision

Keep the target range exactly:

- `0x004926a0-0x00493e29`: `RegistryConfig::LoadFromRegistry()` body.
- `0x00492695-0x004926a0`: 11 bytes of `0xcc` padding after [UID:0002P7] `RegistryConfigSaveToRegistry`.
- `0x00493e29-0x00493e30`: 7 bytes of `0xcc` padding after this method.
- `0x00493e30-0x00493ef0`: sibling retained raw helper [UID:0002VB] `UnreferencedAdapterPhysicalAddressFormatterRaw`; not part of `LoadFromRegistry`.
- `0x00493ef0-0x004941d6`: later cleanup/global/entry-block helper children in the aggregate.

No merge or split is recommended. The complete method starts with the standard prologue at `0x004926a0`:

- `push ebp`
- stack frame setup
- large local allocation through the compiler stack-probe helper
- security-cookie setup
- `mov ebx, ecx`, making `ebx` the `RegistryConfig *this`.

The final instruction is `ret` at `0x00493e28`, and the following seven bytes are padding. The successor at `0x00493e30` has its own raw-helper behavior and no fallthrough from this method.

## Ownership, emitter, and source placement

Recommended owner/emitter:

- Canonical owner: [UID:0000BW] `RegistryConfig`
- Emitter: [UID:0000BW] `RegistryConfig`
- Source file route: [UID:0000N4] `NexusTK/config/RegistryConfig.cpp`

Reasoning:

- The current target is the virtual `RegistryConfig::LoadFromRegistry()` body; `by-class/RegistryConfig.md` already lists it in the method table and ties it to the vtable slot at `0x00612624`.
- The method writes and reads `this` fields throughout the `RegistryConfig` object, with `ebx` as the stable `this` register.
- The body directly mirrors [UID:0002P7] `RegistryConfigSaveToRegistry`, sharing registry strings, field offsets, config-entry cleanup, and source file.
- [UID:00032G] `RegistryConfigTypeProbeRaw` is a file-static retained helper under [UID:0000N4], not a `RegistryConfig` method. Its current-directory `Type` query is distinct from this `HKCU` load path.
- [UID:0002VB] `UnreferencedAdapterPhysicalAddressFormatterRaw` is a sibling retained raw clone. The adapter-formatting logic is inlined inside `LoadFromRegistry`; `LoadFromRegistry` does not call [UID:0002VB].

Rejected owners:

- [UID:0000N4] `RegistryConfig` file as canonical owner only: file ownership is correct for source placement, but the body is a virtual class method and should keep class owner/emitter [UID:0000BW].
- [UID:0000IE] `Config` / config base class: `ConfigEntryBlock` cleanup and `g_pConfig` storage are dependencies, not the owning method. This body is the derived registry persistence implementation.
- [UID:00032G] `RegistryConfigTypeProbeRaw`: separate retained no-xref file helper. It queries `HKLM\...\<current-directory>\Type`; this body opens `HKCU\Software\Nexon\Kingdom of the Winds`.
- [UID:0002VB] raw adapter formatter: sibling/dead clone with no call route. The in-method adapter block should be described as inline `LoadFromRegistry` code.
- MD5/string/config-entry utility owners: the method calls those helpers, but the persistence body and object fields belong to `RegistryConfig`.

## Reachability and caller route

The method has no ordinary direct code call in the current docs, but it is not dead code.

Recommended route wording:

- `0x004926a0` is the virtual `RegistryConfig::LoadFromRegistry()` implementation.
- The method is reachable through the `RegistryConfig` vtable slot at `0x00612624`.
- The lack of direct rel32 callers is expected for this virtual persistence method and is not a no-xref/raw-helper reason.
- Save side [UID:0002P7] is paired through the adjacent vtable slot at `0x00612620`.

This route distinguishes [UID:0002P8] from [UID:0002VB] and [UID:00032G], both of which have retained no-direct-xref/file-helper caveats.

## Registry import and helper resolution

Resolved import/global names used by this body:

| Address / slot | Source-facing name | Evidence / use |
| --- | --- | --- |
| `0x0060d000` | `ADVAPI32!RegSetValueExW` | Direct IAT call at `0x004927bb` when writing generated `CLSID`. Dynamic slot `dword_69BEA8` is initialized to the same API and is used by SaveToRegistry. |
| `0x0060d004` | `ADVAPI32!RegQueryInfoKeyW` | Dynamic slot `dword_69BEA0`; called at `0x00493739` to enumerate the `Midi` subkey values. |
| `0x0060d008` | `ADVAPI32!RegEnumValueW` | Dynamic slot `dword_69BE9C`; called at `0x0049378d` inside the `Midi` enumeration loop. |
| `0x0060d010` | `ADVAPI32!RegCloseKey` | Direct IAT closes class/root/server handles at `0x004927d3`, `0x00493c80`, `0x00493c8c`, and related exits. |
| `0x0060d014` | `ADVAPI32!RegQueryValueExW` | Direct IAT query for `CLSID` at `0x00492742`; dynamic slot `dword_69BEA4` is used for the main option/value reads. |
| `0x0060d01c` | `ADVAPI32!RegCreateKeyExW` | Direct IAT call for `HKCR\NXKRI.Ctrl.1`; dynamic slot `dword_69BE94` creates/opens the root, `Midi`, and `Servers` keys. |
| `0x0060d090` / wrapper call `0x005c8bdf` | `IPHLPAPI!GetAdaptersAddresses` | Called at `0x00492827` to find the first physical adapter address. |
| `0x0060d17c` | `KERNEL32!GetSystemDirectoryA` | Called at `0x00493c9e` for the `mscfg.dll` / `grcframe.exe` system-directory presence probe. |
| `0x00443a00` | narrow secure formatting helper, `_sprintf_s`-style | Formats adapter physical address bytes with `%s%.2X-` and `%s%.2X]`. |
| `0x004944f0` | wide scan helper, `swscanf`-style | Parses MIDI value names and multi-server address strings. |
| `0x005153e0` | `Md5BytesToBuffer` / MD5 bytes-to-digest helper | Called at `0x004928ba` to digest the formatted adapter-address string into `this + 0x28de38`. |
| `0x00494130` | `ConfigEntryBlock::ReleaseOwnedBuffers` | Called at `0x004938d6` before rebuilding server entries and at `0x00493e01` on partial-load cleanup. |

Dynamic import slot initialization is visible in the project docs around the registry import loader:

- `dword_69BE94` = `RegCreateKeyExW`
- `dword_69BE98` = `RegDeleteKeyW`
- `dword_69BE9C` = `RegEnumValueW`
- `dword_69BEA0` = `RegQueryInfoKeyW`
- `dword_69BEA4` = `RegQueryValueExW`
- `dword_69BEA8` = `RegSetValueExW`

The target doc should explicitly resolve `dword_69BE9C` and `dword_69BEA0`; those are currently underdocumented compared with the SaveToRegistry-focused slots.

## High-level behavior

Best source-facing signature:

```cpp
bool RegistryConfig::LoadFromRegistry();
```

Behavior summary:

1. Opens/creates `HKEY_CLASSES_ROOT\NXKRI.Ctrl.1` with `KEY_ALL_ACCESS`.
2. Reads value `CLSID` as a `REG_DWORD`; if missing, zero, wrong, or otherwise unusable, generates a pseudorandom DWORD from four `rand()` bytes seeded by current time, writes it back as `CLSID`, and stores it in `this + 0x28de34`.
3. If the class key cannot be opened, uses fallback identity DWORD `0xff00ff00` at `this + 0x28de34`.
4. Queries the first adapter with `GetAdaptersAddresses`, formats its physical address bytes as a narrow string using `%s%.2X-` for interior bytes and `%s%.2X]` for the final byte, MD5-hashes that string, and stores the digest at `this + 0x28de38`.
5. Opens/creates `HKEY_CURRENT_USER\Software\Nexon\Kingdom of the Winds` with `KEY_READ`. Failure to open this root returns `false`.
6. Loads scalar options, string/blob settings, chat color/defaults, dialog position records, the `Midi` subkey, and the `Servers` subkey.
7. Rebuilds the multi-server/config-entry block through `ConfigEntryBlock::ReleaseOwnedBuffers` before reading `Servers`.
8. Closes opened registry handles on success/failure paths.
9. Probes `%SystemRoot%\System32\mscfg.dll` and `%SystemRoot%\System32\grcframe.exe`; if either exists, writes word `0x0a01` to `this + 0x2918f8`.
10. Returns `true` on the successful main load path. Failure to open the root key or the `Midi` subkey takes the false return path. Failure to open `Servers` is tolerated; it closes the root key and continues the system-helper tail.

## Registry value and field map

All offsets below are relative to `RegistryConfig *this`. Names are source-facing recommendations. Confidence grades describe original-spelling confidence, not behavioral confidence.

### Identity and adapter fields

| Registry value / source | Offset | Type / validation | Recommended field name | Confidence |
| --- | ---: | --- | --- | --- |
| `HKCR\NXKRI.Ctrl.1\CLSID` | `+0x28de34` | `REG_DWORD`, nonzero preferred; fallback random DWORD or `0xff00ff00` if class key unavailable | `m_registryClassIdSeed` / `m_clsidSeed` | High role, medium original spelling |
| First adapter physical address digest | `+0x28de38` | 16-byte MD5 digest of formatted narrow adapter address string | `m_adapterPhysicalAddressDigest` / `m_adapterIdentityDigest` | High role, medium original spelling |

The string-data doc [UID:0003FX] should keep `%s%.2X-` and `%s%.2X]` tied to both the inline block in [UID:0002P8] and the retained raw clone [UID:0002VB]. The `mscfg.dll` / `grcframe.exe` literals also belong to the tail helper-presence probe inside [UID:0002P8].

### Root registry key

The main config root is:

```text
HKEY_CURRENT_USER\Software\Nexon\Kingdom of the Winds
```

This is distinct from [UID:00032G], which probes `HKEY_LOCAL_MACHINE\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type`.

### String/blob values

| Value | Offset / storage | Type / validation | Recommended name | Notes |
| --- | ---: | --- | --- | --- |
| `LogData` | `+0x2916cc` heap pointer | `REG_BINARY`; size must be even; allocates `(size / 2 + 1) * sizeof(wchar_t)`, copies bytes, NUL-terminates | `m_logDataText` / `m_logDataWide` | Heap pointer should be released by destructor/config cleanup. |
| `LastServer` | `+0x2916d0` fixed wide buffer | `REG_SZ`; copied/formatted through `%s`; buffer capacity appears 16 wide chars | `m_lastServerName` / `m_lastServer` | Server-select docs also consume the last-server storage around this cluster. |
| `MP3Dir` | `+0x29190c` string object/storage | `REG_SZ`; non-empty string assigned through StringBase/SimpleUString helper | `m_musicFolderPath` / `m_localMusicPath` | Matches MusicControlDialog support docs for local music path. |

### Scalar option values

| Value | Offset | Validation | Recommended field name | Notes |
| --- | ---: | --- | --- | --- |
| `Font` | `+0x28de30` WORD | DWORD <= 3 | `m_fontIndex` | Loaded as a small integer, stored as word. |
| `Icons` | `+0x28de32` byte | DWORD <= 1 | `m_iconsPaneReducedMode` / `m_iconDisplayMode` | Existing IconsPane docs prove zero = full icon strip, nonzero = reduced. Prefer a name that preserves that polarity. |
| `Sound` | `+0x28de48` byte | DWORD <= 1 | `m_soundEnabled` | Used by MusicControlDialog/SoundManager-related options. |
| `SoundVolume` | `+0x28de4c` DWORD | DWORD <= 100 | `m_soundVolume` | Volume percent. |
| `Music` | `+0x28de50` byte | DWORD <= 1 | `m_musicEnabled` | Legacy top-level music enabled flag. |
| `MusicVolume` | `+0x28de54` DWORD | DWORD <= 100 | `m_musicVolume` | Volume percent. |
| `SoundLatency` | `+0x2918f4` DWORD | `REG_DWORD` size 4; default `0x10` on failure | `m_soundLatency` | String lives in [UID:0003FX]. |
| `DoubleClick` | `+0x28de5a` byte | DWORD <= 1 | `m_doubleClickEnabled` | |
| `AutoMove` | no surviving object write found in this body | Query is issued then discarded before `TabVSwap` setup | `AutoMove` compatibility/stale query | SaveToRegistry writes this value; LoadFromRegistry appears to query and ignore it. Document as compatibility/no-op until an offset write is proven. |
| `TabVSwap` | `+0x28de63` byte | DWORD <= 1 | `m_tabVerticalSwap` / `m_tabVSwap` | |
| `ShowDamage` | `+0x28de64` byte | DWORD <= 1 | `m_showDamage` | |
| `GroupBar` | `+0x28de65` byte | DWORD <= 1 | `m_groupBarEnabled` | |
| `CarnageColor` | `+0x28de66` byte | DWORD <= 1 | `m_carnageColorEnabled` | |
| `Shadow` | `+0x28de5e` byte | DWORD <= 1 | `m_shadowEnabled` | |
| `Balloon` | `+0x28de5c` byte | DWORD <= 1 | `m_balloonEnabled` | |
| `GraphicsSetting` | `+0x28de68` DWORD | DWORD <= 1, sign-extends stored byte to DWORD | `m_graphicsSetting` | Might be a low/high graphics setting, not just bool. |
| `orbTargetShare` | `+0x28de6c` byte | DWORD <= 1 | `m_orbTargetShare` | |
| `f1Swap` | `+0x28de6d` byte | DWORD <= 1 | `m_f1Swap` | |
| `ShowUserName` | `+0x28de5f` byte | DWORD <= 2 | `m_showUserNameMode` | Three-state option. |
| `HearSnore` | `+0x28de71` byte | DWORD <= 2 | `m_hearSnoreMode` | MotionAnimation docs read this field. |
| `SeeThrough` | `+0x28de76` byte | DWORD <= 1 | `m_seeThroughEnabled` | |
| `SayWithEnter` | `+0x28de59` byte | DWORD <= 1 | `m_sayWithEnter` | |
| `HearEmotions` | `+0x28de77` byte | DWORD <= 1 | `m_hearEmotions` | |
| `MapEffect` | `+0x28de58` byte | DWORD <= 1 | `m_mapEffectEnabled` | |
| `MusicType` | `+0x291908` DWORD | `REG_DWORD` size 4 | `m_musicSourceMode` / `m_musicPlaybackMode` | Existing MusicControlDialog/SoundManager docs prove values `0` disabled/fallback, `1` stream/local, `2` Redbook/CD. |
| `MusicCdRomDrive` | `+0x291910` WORD | `REG_DWORD` size 4; low word stored | `m_redbookDriveLetter` / `m_cdRomDrive` | |
| `PlayRandom` | `+0x291912` byte | DWORD <= 1 | `m_randomizeMusicOrder` / `m_shuffleMusic` | Existing MusicControlDialog docs use shuffle/randomize naming. |
| `PlayRepeat` | `+0x291913` byte | DWORD <= 1 | `m_musicRepeatEnabled` | |
| `SoundFreq` | `+0x291914` byte | `REG_DWORD` size 4; low byte stored | `m_musicOutputSelection` / `m_soundFrequency` | Existing docs call this music output/playback selection; original registry name is SoundFreq. |
| `ClickMove` | `+0x28de8e` byte | `REG_DWORD` size 4; default 1 | `m_clickMoveEnabled` | |
| `ClickLook` | `+0x28de8f` byte | `REG_DWORD` size 4; default 1 | `m_clickLookEnabled` | |
| `SystemMessageHeight` | `+0x28de90` DWORD | `REG_DWORD` size 4; default `0x46` | `m_systemMessageHeight` | |

### Chat window/color values

| Value | Offset / storage | Type / validation | Recommended field name | Notes |
| --- | ---: | --- | --- | --- |
| `ChatWindow` | packed into `+0x28de78`, `+0x28de7c`, `+0x28de80`, `+0x28de81` | `REG_DWORD` size 4 | `m_chatVisibleLineCount`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, `m_chatHandleLeftToggle` | These names match [UID:0001VR] `RegistryConfigUserProfileBlock`. Invalid/missing value defaults to line count 8, mode 1, and both toggles enabled. |
| `ChatColor` | `+0x28de82..+0x28de8d` | `REG_BINARY`, exact size `0x0c` | `m_chatColorPairs[6]` | Six foreground/background pairs: Talk/Shout/Whisper/Group/Clan/System per support struct doc. |
| `Color%d`, `0 <= i < 4` | `+0x28de94 + i * 2` | `REG_DWORD` size 4; low word stored | `m_paletteColorOverrides[4]` / `m_interfaceColorSlots[4]` | Separate from the 12 chat-color bytes. |

### MIDI value enumeration

Subkey:

```text
HKCU\Software\Nexon\Kingdom of the Winds\Midi
```

Binary route:

- Opens/creates `Midi` under the root key with `RegCreateKeyExW` at `0x0049370e`.
- Failure to open `Midi` branches to the false return path.
- Calls `RegQueryInfoKeyW` through `dword_69BEA0` at `0x00493739` to get value count.
- Enumerates values with `RegEnumValueW` through `dword_69BE9C` at `0x0049378d`.
- Uses a wide local value-name buffer of about 0x20 wide chars and a data buffer of about 0x20 wide chars.
- Accepts `REG_SZ` values whose data length fits.
- Parses the value name as an integer with the `swscanf`-style wrapper at `0x004944f0` and `%d`.
- Copies the value string and calls virtual slot `+0x18` on the object pointer at `this + 0x2912b4`.

Recommended field/helper naming:

- `this + 0x2912b4`: `m_midiList` / `m_midiRegistryList` / `m_musicTitleMap`.
- Loop helper if extracted in source: `LoadMidiRegistryValues(HKEY midiKey)`.

Confidence:

- High for behavior and storage route.
- Medium/low for exact original object name. Existing `Config` docs say this slot is a config-entry vector/helper wrapper, but the `Midi` enumeration semantics strongly support a MIDI/music registry list role here. Do not call it a generic profile block.

### Dialog position records

Value family:

```text
DialogPos%d
```

Recommended field:

- `this + 0x2914b8`: `m_dialogPositions[21]`

Behavior:

- Loops indexed values, matching SaveToRegistry's 21-record family.
- Each successful read accepts `REG_BINARY` with exact size `0x0c` and copies directly into the 12-byte record.
- Recommended record type: `DialogPositionRecord` with three DWORDs or a 12-byte persisted binary layout. The target should not claim the internal field names until a UI consumer confirms x/y/state ordering.

### Multi-server records

Subkey:

```text
HKCU\Software\Nexon\Kingdom of the Winds\Servers
```

Values:

- `MultiServerInfoVersion`
- `MultiServerAddr%d`
- `MultiServerName%d`
- `MultiServerDesc%d`
- `MultiServerAgreement%d`

Recommended field map:

| Offset / storage | Recommended name | Evidence |
| ---: | --- | --- |
| `+0x28db10` | `m_serverEntries` / `m_multiServerEntries` config-entry block | Passed to `ConfigEntryBlock::ReleaseOwnedBuffers` at `0x004938d6` and `0x00493e01`. |
| `+0x28de10` | `m_serverEntryCount` / `m_multiServerCount` | Updated after the load loop. |
| `+0x28de14` | `m_multiServerInfoVersion` | Written from `MultiServerInfoVersion` if nonnegative DWORD. |
| `+0x28db24 + i * 0x18` and nearby negative offsets | per-entry address/id/name/description/agreement fields | The loop starts with `esi = this + 0x28db24` and walks records by `0x18`. |

Behavior:

- Opens/creates `Servers` after `Midi`.
- If `Servers` is absent or cannot be opened, the method closes the root key and continues the final system-directory tail; this is not a hard failure.
- On `Servers` success, clears old entry heap strings through `ConfigEntryBlock::ReleaseOwnedBuffers`.
- Loads `MultiServerInfoVersion` into the one-byte or small integer field at `+0x28de14` only if the DWORD is nonnegative.
- For index `i`, reads `MultiServerAddr%d` as a string and parses it with format `%d:%d.%d.%d.%d:%d`.
- The parsed fields populate a 0x18-byte record. The first parsed integer is likely a server/group id or protocol/channel value; the four middle integers are IP octets; the last is a port-like value. Exact record member spellings remain open.
- Then reads `MultiServerName%d`, `MultiServerDesc%d`, and `MultiServerAgreement%d` as heap UTF-16 strings into the same record.
- On partial-record allocation/query failure, calls `ConfigEntryBlock::ReleaseOwnedBuffers` and exits through the false/cleanup route.

Recommended entry type:

```cpp
struct RegistryConfigServerEntry
{
    int addressKindOrId;
    wchar_t *name;
    wchar_t *description;
    wchar_t *agreementText;
    unsigned char addressOctets[4];
    unsigned short port;
    // Exact padding/order should remain binary-verified in the by-struct support doc.
};
```

Do not hard-commit this exact struct layout in implementation until a follow-up structure target verifies the record offsets. It is sufficient for [UID:0002P8] to document the 0x18 stride, string pointer ownership, address format, and count/version fields.

### System-directory helper presence tail

String evidence:

- `0x006178d8`: wide `mscfg.dll`
- `0x006178ec`: wide `grcframe.exe`
- pointer table in the `.data` string-pointer island includes those literals for this tail.

Behavior:

- Calls `GetSystemDirectoryA` into a local path buffer.
- Builds a StringBase/SimpleUString-style path by appending backslash and each helper name.
- Calls a CRT file-existence/access helper, likely `_access(path, 0)`.
- If either file exists, writes word `0x0a01` to `this + 0x2918f8`.

Recommended field name:

- `m_systemHelperFlags`
- Alternative: `m_securityHelperPresenceFlags`

Confidence:

- High for file-existence behavior and write value.
- Medium/low for original field name and exact meaning of the `0x0a01` bit pattern.

## Open questions resolved or bounded

### Should this still have blank C++?

No. The active code-entry gate is cleared by current metadata and the method is reconstructable with a nonblank emitter. The old "leave blank until 95/95" wording is obsolete for this target. The method is long, but the unresolved parts are original-field-spelling issues, not blockers to a source-level first draft.

Recommended treatment:

- Add first-draft `bool RegistryConfig::LoadFromRegistry()` to the by-memory formal C++ block.
- Keep comments about inferred member names and helper extraction candidates.
- Do not emit C++ on the class page except a declaration if the class-page policy wants declarations.

### Is `0x00493e30-0x00493ef0` part of this method?

No. [UID:0002VB] is a sibling retained raw helper/dead clone. It has its own padding boundary, no fallthrough, and no direct call route from `LoadFromRegistry`. The inline adapter formatting block in `LoadFromRegistry` duplicates the raw helper's physical-address formatting logic, but the raw helper should stay separate under [UID:0000N4].

### Is `AutoMove` loaded?

The binary issues a query for `AutoMove`, but no surviving object write was found before the body resets the query locals and moves on to `TabVSwap`. SaveToRegistry writes `AutoMove`, so this is best documented as a compatibility/stale read whose result is discarded in this build. Do not invent an `AutoMove` offset until a direct write is proven.

### Is [UID:00032G] `Type` related to this loader?

Only by shared source file and some registry-root string overlap. [UID:00032G] queries `HKLM\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type`; [UID:0002P8] opens `HKCU\Software\Nexon\Kingdom of the Winds` and does not query `Type`. Do not claim [UID:0002P8] calls or depends on [UID:00032G].

### Does the `CLSID` value mean a real COM CLSID?

Not in the normal `REG_SZ` GUID-string sense. The body opens `HKCR\NXKRI.Ctrl.1`, queries value `CLSID`, and accepts a four-byte `REG_DWORD`. If missing or zero, it writes a pseudorandom DWORD. The best source-facing name is `m_registryClassIdSeed` or `m_clsidSeed`, not a COM `CLSID` structure.

### What owns the adapter MD5 digest?

The digest belongs to `RegistryConfig` at `this + 0x28de38`. The physical-address string is temporary local data. The sibling raw helper [UID:0002VB] formats the same style of address string but is not called here. The source-facing helper extraction candidate is `BuildFirstAdapterPhysicalAddressString`, but the binary has it inline.

### Is `this + 0x2912b4` a final MIDI list name?

No final original spelling is proven, but the role is not a passive blocker. In this method it is the object receiving parsed `Midi` subkey entries through a virtual `+0x18` add/set slot after a prior virtual `+0x20` clear/reset slot. Recommended working name: `m_midiRegistryList` or `m_midiList`. Support docs should state the exact route and confidence.

### Is the multi-server record struct final?

No. The value family, 0x18 stride, count/version fields, heap-string ownership, address parse format, and cleanup helper are resolved. Exact field order and original member names remain a structure-documentation task, but they do not block first-draft method C++.

## First-draft C++ recommendation

Add a first-draft C++ block to [UID:0002P8]. The following is intentionally source-level and mid-2000s plausible. Helper names are source-facing extraction candidates for repeated registry reads and inline blocks; they are not all proven as separate binary functions.

```cpp
bool RegistryConfig::LoadFromRegistry()
{
    HKEY classKey = 0;
    HKEY rootKey = 0;
    HKEY midiKey = 0;
    HKEY serversKey = 0;
    DWORD disposition = 0;
    DWORD valueType = 0;
    DWORD valueSize = 0;
    DWORD dwordValue = 0;

    m_registryClassIdSeed = 0xff00ff00;

    if (RegCreateKeyExW(HKEY_CLASSES_ROOT,
                        L"NXKRI.Ctrl.1",
                        0,
                        0,
                        0,
                        KEY_ALL_ACCESS,
                        0,
                        &classKey,
                        &disposition) == ERROR_SUCCESS)
    {
        valueSize = sizeof(dwordValue);
        if (RegQueryValueExW(classKey,
                             L"CLSID",
                             0,
                             &valueType,
                             reinterpret_cast<BYTE *>(&dwordValue),
                             &valueSize) != ERROR_SUCCESS ||
            valueType != REG_DWORD ||
            valueSize != sizeof(dwordValue) ||
            dwordValue == 0)
        {
            srand(static_cast<unsigned int>(time(0)));
            dwordValue = ((rand() & 0xff) << 24) |
                         ((rand() & 0xff) << 16) |
                         ((rand() & 0xff) << 8) |
                         (rand() & 0xff);

            RegSetValueExW(classKey,
                           L"CLSID",
                           0,
                           REG_DWORD,
                           reinterpret_cast<const BYTE *>(&dwordValue),
                           sizeof(dwordValue));
        }

        m_registryClassIdSeed = dwordValue;
        RegCloseKey(classKey);
    }

    char adapterText[256];
    adapterText[0] = 0;
    BuildFirstAdapterPhysicalAddressString(adapterText, sizeof(adapterText));
    Md5BytesToBuffer(adapterText, strlen(adapterText), m_adapterPhysicalAddressDigest);

    if (RegCreateKeyExW(HKEY_CURRENT_USER,
                        L"Software\\Nexon\\Kingdom of the Winds",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &rootKey,
                        &disposition) != ERROR_SUCCESS)
    {
        return false;
    }

    ReadBinaryWideStringValue(rootKey, L"LogData", &m_logDataText);
    ReadFixedWideStringValue(rootKey, L"LastServer", m_lastServerName, _countof(m_lastServerName));

    ReadClampedWordValue(rootKey, L"Font", 3, &m_fontIndex);
    ReadClampedByteValue(rootKey, L"Icons", 1, &m_iconsPaneReducedMode);
    ReadClampedByteValue(rootKey, L"Sound", 1, &m_soundEnabled);
    ReadClampedDwordValue(rootKey, L"SoundVolume", 100, &m_soundVolume);
    ReadClampedByteValue(rootKey, L"Music", 1, &m_musicEnabled);
    ReadClampedDwordValue(rootKey, L"MusicVolume", 100, &m_musicVolume);

    m_soundLatency = 0x10;
    ReadDwordValue(rootKey, L"SoundLatency", &m_soundLatency);

    ReadClampedByteValue(rootKey, L"DoubleClick", 1, &m_doubleClickEnabled);

    // Retained compatibility read in this binary: the result is not stored.
    QueryDwordValue(rootKey, L"AutoMove", &dwordValue);

    ReadClampedByteValue(rootKey, L"TabVSwap", 1, &m_tabVSwap);
    ReadClampedByteValue(rootKey, L"ShowDamage", 1, &m_showDamage);
    ReadClampedByteValue(rootKey, L"GroupBar", 1, &m_groupBarEnabled);
    ReadClampedByteValue(rootKey, L"CarnageColor", 1, &m_carnageColorEnabled);
    ReadClampedByteValue(rootKey, L"Shadow", 1, &m_shadowEnabled);
    ReadClampedByteValue(rootKey, L"Balloon", 1, &m_balloonEnabled);
    ReadClampedDwordValue(rootKey, L"GraphicsSetting", 1, &m_graphicsSetting);
    ReadClampedByteValue(rootKey, L"orbTargetShare", 1, &m_orbTargetShare);
    ReadClampedByteValue(rootKey, L"f1Swap", 1, &m_f1Swap);
    ReadClampedByteValue(rootKey, L"ShowUserName", 2, &m_showUserNameMode);
    ReadClampedByteValue(rootKey, L"HearSnore", 2, &m_hearSnoreMode);
    ReadClampedByteValue(rootKey, L"SeeThrough", 1, &m_seeThroughEnabled);
    ReadClampedByteValue(rootKey, L"SayWithEnter", 1, &m_sayWithEnter);
    ReadClampedByteValue(rootKey, L"HearEmotions", 1, &m_hearEmotions);
    ReadClampedByteValue(rootKey, L"MapEffect", 1, &m_mapEffectEnabled);

    ReadDwordValue(rootKey, L"MusicType", &m_musicSourceMode);
    ReadStringValue(rootKey, L"MP3Dir", &m_musicFolderPath);
    ReadWordFromDwordValue(rootKey, L"MusicCdRomDrive", &m_redbookDriveLetter);
    ReadClampedByteValue(rootKey, L"PlayRandom", 1, &m_randomizeMusicOrder);
    ReadClampedByteValue(rootKey, L"PlayRepeat", 1, &m_musicRepeatEnabled);
    ReadByteFromDwordValue(rootKey, L"SoundFreq", &m_musicOutputSelection);

    if (!ReadChatWindowValue(rootKey,
                             &m_chatVisibleLineCount,
                             &m_chatHandleModeIndex,
                             &m_secondaryChatEnabled,
                             &m_chatHandleLeftToggle))
    {
        m_chatVisibleLineCount = 8;
        m_chatHandleModeIndex = 1;
        m_secondaryChatEnabled = true;
        m_chatHandleLeftToggle = true;
    }

    if (!ReadBinaryValue(rootKey, L"ChatColor", m_chatColorPairs, sizeof(m_chatColorPairs)))
    {
        SetDefaultChatColors();
    }

    for (int i = 0; i < 4; ++i)
    {
        wchar_t valueName[32];
        swprintf(valueName, L"Color%d", i);
        ReadWordFromDwordValue(rootKey, valueName, &m_paletteColorOverrides[i]);
    }

    ReadBoolDefaultTrue(rootKey, L"ClickMove", &m_clickMoveEnabled);
    ReadBoolDefaultTrue(rootKey, L"ClickLook", &m_clickLookEnabled);

    m_systemMessageHeight = 0x46;
    ReadDwordValue(rootKey, L"SystemMessageHeight", &m_systemMessageHeight);

    if (RegCreateKeyExW(rootKey,
                        L"Midi",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &midiKey,
                        &disposition) != ERROR_SUCCESS)
    {
        RegCloseKey(rootKey);
        return false;
    }

    LoadMidiRegistryValues(midiKey, m_midiRegistryList);
    RegCloseKey(midiKey);

    for (int i = 0; i < 21; ++i)
    {
        wchar_t valueName[32];
        swprintf(valueName, L"DialogPos%d", i);
        ReadBinaryValue(rootKey, valueName, &m_dialogPositions[i], sizeof(m_dialogPositions[i]));
    }

    if (RegCreateKeyExW(rootKey,
                        L"Servers",
                        0,
                        0,
                        0,
                        KEY_READ,
                        0,
                        &serversKey,
                        &disposition) == ERROR_SUCCESS)
    {
        m_serverEntries.ReleaseOwnedBuffers();

        ReadNonNegativeByteValue(serversKey,
                                 L"MultiServerInfoVersion",
                                 &m_multiServerInfoVersion);

        if (!LoadMultiServerEntries(serversKey, &m_serverEntries))
        {
            m_serverEntries.ReleaseOwnedBuffers();
            RegCloseKey(serversKey);
            RegCloseKey(rootKey);
            return false;
        }

        RegCloseKey(serversKey);
    }

    RegCloseKey(rootKey);

    if (SystemDirectoryFileExists("mscfg.dll") ||
        SystemDirectoryFileExists("grcframe.exe"))
    {
        m_systemHelperFlags = 0x0a01;
    }

    return true;
}
```

Implementation note for this C++ draft:

- If the doc style rejects unproven helper bodies in a by-memory C++ block, keep the method body and introduce the helper names as comments/descriptive calls rather than as separate emitted functions.
- The binary inlines most repeated registry reads. The helper names are acceptable as source-quality names because they express source intent and reduce decompiler-shaped duplication, but support docs must note which helpers are extraction candidates rather than separately identified functions.
- Do not model [UID:0002VB] as the implementation of `BuildFirstAdapterPhysicalAddressString`; it is a retained sibling clone.

## Heuristic / Inference Reanalysis And Validation

This section is the explicit B-agent heuristic/source-quality reanalysis required for signoff. Existing target/support docs, generated output, and previous registry reports were treated as leads only; each meaningful source-quality issue below was rechecked against the target body, neighboring docs, string references, import slots, xrefs, and adjacent ranges. The conclusions below do not replace the detailed evidence sections above; they gather the inference decisions in one audit-ready location.

### 1. Source-facing method identity and signature

- Evidence checked:
  - Target metadata and docs identify [UID:0002P8] as [UID:0000BW] `RegistryConfig`.
  - [UID:0000BW] `by-class/RegistryConfig.md` lists this body in the `RegistryConfig` method/vtable inventory and records the vtable route at `0x00612624`.
  - Disassembly of `0x004926a0-0x00493e29` shows a normal `thiscall` method with `ecx` saved into `ebx` and persistent writes through `this` offsets across the whole body.
  - Return paths set `al` as a boolean success/failure value: root-key open failure and `Midi` open failure return false; the successful load path returns true.
- Candidate interpretations:
  - `bool RegistryConfig::LoadFromRegistry()`: best source-facing match.
  - `int RegistryConfig::LoadFromRegistry()`: possible if a decompiler keeps `int` for `eax`, but callers/source semantics use success/failure only.
  - File-static `LoadRegistryConfig(RegistryConfig *)`: rejected because the vtable slot and stable `thiscall` receiver identify a class virtual method.
- Final direction:
  - Use `bool RegistryConfig::LoadFromRegistry()`.
  - Original member names remain descriptive/inferred, but the method identity, signature class, source owner, and return semantics are strong enough for first-draft C++.
- Score/C++ impact:
  - This resolves the blank-C++ blocker tied to method identity. It supports raising the target to `88/90` and adding a source-level method body.

### 2. Identity and adapter member names

- Evidence checked:
  - `HKCR\NXKRI.Ctrl.1` is opened directly at the top of the function.
  - Value `CLSID` is queried and written as a four-byte `REG_DWORD`, not a string GUID or COM `CLSID` struct.
  - Failure to open the class key stores `0xff00ff00` to `this + 0x28de34`; success stores the queried or generated DWORD there.
  - The adapter block calls `GetAdaptersAddresses`, formats physical-address bytes with `%s%.2X-` / `%s%.2X]`, calls `Md5BytesToBuffer` at `0x004928ba`, and writes the digest at `this + 0x28de38`.
- Candidate interpretations:
  - `this + 0x28de34` as `m_registryClassIdSeed` / `m_clsidSeed`: accepted, because the persisted value is named `CLSID` but is a DWORD seed.
  - `this + 0x28de34` as real COM `CLSID`: rejected because the binary validates `REG_DWORD` size 4 and writes random DWORD bytes.
  - `this + 0x28de38` as `m_adapterPhysicalAddressDigest` / `m_adapterIdentityDigest`: accepted, because the value is a 16-byte MD5 digest of the formatted first adapter address.
  - `this + 0x28de38` as raw MAC/address text: rejected because the formatted text is local temporary data and the stored field receives MD5 output.
- Final direction:
  - Use descriptive member names `m_registryClassIdSeed` and `m_adapterPhysicalAddressDigest` in target prose and first-draft C++.
- Score/C++ impact:
  - Original spelling is not proven, but source roles are strong. This is a naming cap, not a code blocker.

### 3. Scalar option field-name inferences

- Evidence checked:
  - Registry string references and paired `RegQueryValueExW` calls map each scalar option to a `this` offset.
  - Existing support docs for IconsPane, MusicControlDialog, SoundManager, MotionAnimation, and chat controls already confirm several consumer roles.
  - [UID:0002P7] `SaveToRegistry` writes the same value families, providing save/load symmetry where the load result is stored.
- Candidate interpretations and final direction:
  - `+0x28de30`: `m_fontIndex`; accepted from `Font` value, range `0..3`, WORD store.
  - `+0x28de32`: `m_iconsPaneReducedMode` / `m_iconDisplayMode`; accepted from `Icons` value and IconsPane support docs proving zero means full strip and nonzero means reduced.
  - `+0x28de48`: `m_soundEnabled`; accepted from `Sound` value and audio-option consumers.
  - `+0x28de4c`: `m_soundVolume`; accepted from `SoundVolume <= 100`.
  - `+0x28de50`: `m_musicEnabled`; accepted from `Music`.
  - `+0x28de54`: `m_musicVolume`; accepted from `MusicVolume <= 100`.
  - `+0x2918f4`: `m_soundLatency`; accepted from `SoundLatency`, default `0x10`.
  - `+0x28de5a`: `m_doubleClickEnabled`; accepted from `DoubleClick`.
  - `+0x28de63`: `m_tabVSwap`; accepted from `TabVSwap`.
  - `+0x28de64`: `m_showDamage`; accepted from `ShowDamage`.
  - `+0x28de65`: `m_groupBarEnabled`; accepted from `GroupBar`.
  - `+0x28de66`: `m_carnageColorEnabled`; accepted from `CarnageColor`.
  - `+0x28de5e`: `m_shadowEnabled`; accepted from `Shadow`.
  - `+0x28de5c`: `m_balloonEnabled`; accepted from `Balloon`.
  - `+0x28de68`: `m_graphicsSetting`; accepted from `GraphicsSetting`, stored as DWORD after byte/sign-extension behavior.
  - `+0x28de6c`: `m_orbTargetShare`; accepted from same registry value.
  - `+0x28de6d`: `m_f1Swap`; accepted from same registry value.
  - `+0x28de5f`: `m_showUserNameMode`; accepted as three-state because load accepts `0..2`.
  - `+0x28de71`: `m_hearSnoreMode`; accepted as three-state because load accepts `0..2` and MotionAnimation docs consume this field.
  - `+0x28de76`: `m_seeThroughEnabled`; accepted from `SeeThrough`.
  - `+0x28de59`: `m_sayWithEnter`; accepted from `SayWithEnter`.
  - `+0x28de77`: `m_hearEmotions`; accepted from `HearEmotions`.
  - `+0x28de58`: `m_mapEffectEnabled`; accepted from `MapEffect`.
  - `+0x28de8e`: `m_clickMoveEnabled`; accepted from `ClickMove`, default true.
  - `+0x28de8f`: `m_clickLookEnabled`; accepted from `ClickLook`, default true.
  - `+0x28de90`: `m_systemMessageHeight`; accepted from `SystemMessageHeight`, default `0x46`.
- Rejected alternatives:
  - Generic `byte_`/`dword_` names: rejected because registry value strings and consumers provide role names.
  - Treating all fields as booleans: rejected for values with explicit `<= 2`, volume percent, DWORD/WORD storage, or known mode semantics.
- Score/C++ impact:
  - These names are source-facing/descriptive, not original-proof. They are sufficient for first-draft method C++ and explain the remaining score cap.

### 4. `AutoMove` compatibility/stale query

- Evidence checked:
  - The target body issues a `RegQueryValueExW`-style query for `AutoMove`.
  - The disassembly then resets query locals and proceeds to `TabVSwap` without any observed write to a `RegistryConfig` object offset.
  - [UID:0002P7] `SaveToRegistry` writes `AutoMove`, so the value exists in the save-side inventory.
- Candidate interpretations:
  - Load-side compatibility/stale query whose result is discarded: accepted.
  - Hidden write through an indirect helper: rejected for now because no helper call or object write occurs between the query result and the next value setup in the checked instruction window.
  - Some unknown field offset: rejected; no offset should be invented without an object write.
- Final direction:
  - Document `AutoMove` as queried but not stored in this build. Keep it in the registry inventory as a compatibility/stale read.
- Score/C++ impact:
  - This avoids false field naming. It is a behavioral caveat but not a C++ blocker; first-draft C++ should preserve the no-op query or comment it explicitly.

### 5. Chat and color fields

- Evidence checked:
  - `ChatWindow` is read as a DWORD and unpacked into `+0x28de78`, `+0x28de7c`, `+0x28de80`, and `+0x28de81`.
  - [UID:0001VR] `RegistryConfigUserProfileBlock` already documents these as `m_chatVisibleLineCount`, `m_chatHandleModeIndex`, `m_secondaryChatEnabled`, and `m_chatHandleLeftToggle`.
  - `ChatColor` is accepted only as 12 bytes of `REG_BINARY` and copied into `+0x28de82..+0x28de8d`; defaults are written byte/dword/word chunks when missing or invalid.
  - `Color%d` reads four DWORD values and stores low words at `+0x28de94 + i * 2`.
- Candidate interpretations:
  - `m_chatColorPairs[6]`: accepted for the 12 bytes because support docs map six foreground/background category pairs.
  - Four `Color%d` entries as `m_paletteColorOverrides[4]` / `m_interfaceColorSlots[4]`: accepted but lower original-spelling confidence.
  - Treating `Color%d` as part of `m_chatColorPairs`: rejected because storage is distinct and word-sized.
- Final direction:
  - Use existing `RegistryConfigUserProfileBlock` names for chat-window fields, `m_chatColorPairs[6]` for `ChatColor`, and descriptive `m_paletteColorOverrides[4]` for `Color%d`.
- Score/C++ impact:
  - Existing support docs make these strong enough for C++. Exact category enum names and `Color%d` original spelling remain polish items.

### 6. Music-control field names

- Evidence checked:
  - `MusicType`, `MP3Dir`, `MusicCdRomDrive`, `PlayRandom`, `PlayRepeat`, and `SoundFreq` all write/read the `+0x291908..+0x291914` cluster.
  - MusicControlDialog and SoundManager pages already consume `+0x291908` as values `0` disabled/fallback, `1` stream/local, `2` Redbook/CD.
  - Existing docs identify `+0x29190c` as local music path, `+0x291910` as Redbook/CD drive, `+0x291912` as shuffle/randomize, `+0x291913` as repeat, and `+0x291914` as output/selection byte.
- Candidate interpretations:
  - Keep registry-name-derived names: `m_musicSourceMode`, `m_musicFolderPath`, `m_redbookDriveLetter`, `m_randomizeMusicOrder`, `m_musicRepeatEnabled`, `m_musicOutputSelection`: accepted.
  - Treat `SoundFreq` literally as audio sample frequency: rejected as final claim because MusicControlDialog docs use it as control id 3 output/playback selection; preserve registry-name note.
- Final direction:
  - Use the music-control names already standardized in support docs, with a note that `SoundFreq` is the registry value name while source role appears to be output/playback selection.
- Score/C++ impact:
  - Strong enough for first-draft C++; exact original spelling remains descriptive/inferred.

### 7. MIDI enumeration and `this + 0x2912b4`

- Evidence checked:
  - The body opens subkey `Midi` under the root with `RegCreateKeyExW`.
  - It calls `RegQueryInfoKeyW` through `dword_69BEA0` to get the value count and `RegEnumValueW` through `dword_69BE9C` to enumerate values.
  - It accepts `REG_SZ`, parses value names with the wide scan helper and `%d`, copies the value string, and calls a virtual add/set slot on the object pointer at `this + 0x2912b4`.
  - Constructor/default docs describe this offset as a config-entry/vector-like helper wrapper, but this body's value family is specifically `Midi`.
- Candidate interpretations:
  - `m_midiRegistryList`: best descriptive name because the body clears/loads indexed `Midi` registry values into this object.
  - `m_midiList`: shorter acceptable alternative.
  - Generic `m_configEntryVector`: rejected for target C++ because it loses the observed registry semantics.
  - `m_selectedProfileName`: rejected because nearby `+0x2912b8` is selected profile/name storage in support docs; `+0x2912b4` is an object pointer/list route.
- Final direction:
  - Use `m_midiRegistryList` in first-draft C++ or prose, with `m_midiList` as an acceptable shorter alias.
  - State confidence as high for behavior and medium for original field spelling.
- Score/C++ impact:
  - Does not block C++ because the route, value family, and object interaction are clear. Original list class/type name remains a score cap.

### 8. Dialog position record inference

- Evidence checked:
  - The body loops `DialogPos%d` values, matching SaveToRegistry's same family.
  - Each successful read accepts `REG_BINARY` of exact size `0x0c`.
  - Storage begins at `this + 0x2914b8`, and SaveToRegistry documents the same 21-record family.
- Candidate interpretations:
  - `m_dialogPositions[21]`: accepted as source-facing role.
  - Exact `struct DialogPositionRecord { x, y, state }`: rejected as a final field-order claim because this target proves size and storage but not internal member order from UI consumers.
  - Raw byte array only: rejected for C++ readability because the registry value family and 12-byte records strongly indicate persisted dialog position records.
- Final direction:
  - Document `DialogPositionRecord m_dialogPositions[21]`, with exact internal fields bounded/unproven.
- Score/C++ impact:
  - Sufficient for first-draft method C++. Internal field-order uncertainty is a structure-polish item, not a method-body blocker.

### 9. Multi-server and ConfigEntryBlock route

- Evidence checked:
  - The body opens `Servers` after `Midi`.
  - On success it calls `ConfigEntryBlock::ReleaseOwnedBuffers` at `0x004938d6` on `this + 0x28db10` before rebuilding records.
  - It reads `MultiServerInfoVersion` into `+0x28de14`.
  - It loops `MultiServerAddr%d`, `MultiServerName%d`, `MultiServerDesc%d`, and `MultiServerAgreement%d`.
  - Address values are parsed with `%d:%d.%d.%d.%d:%d`.
  - `ConfigEntryBlock::ReleaseOwnedBuffers` is called again at `0x00493e01` on partial-load cleanup.
  - Count/state fields around `+0x28de10` are updated by the loop.
- Candidate interpretations:
  - `this + 0x28db10` as `m_serverEntries` / `m_multiServerEntries`: accepted.
  - `+0x28de10` as `m_serverEntryCount` / `m_multiServerCount`: accepted.
  - `+0x28de14` as `m_multiServerInfoVersion`: accepted.
  - Entry stride `0x18` as `RegistryConfigServerEntry`: accepted as descriptive; exact member order remains partly inferred.
  - Treat `ConfigEntryBlock::ReleaseOwnedBuffers` as owner of the load method: rejected; it is a cleanup callee for owned records, not the method owner.
  - Treat `Servers` open failure as hard failure: rejected; the checked branch closes root and continues the system-directory tail.
- Final direction:
  - Document a multi-server/config-entry block with version/count fields, 0x18-byte records, three heap strings, parsed address fields, and cleanup ownership through `ConfigEntryBlock::ReleaseOwnedBuffers`.
- Score/C++ impact:
  - Strong enough for C++ with helper extraction `LoadMultiServerEntries`. Exact server-entry struct field names/order cap completion below final audit.

### 10. System-directory helper-presence probe

- Evidence checked:
  - Tail calls `GetSystemDirectoryA` through the direct import at `0x0060d17c`.
  - It uses StringBase/SimpleUString-style helpers to append `mscfg.dll` and `grcframe.exe`.
  - It calls a CRT access/existence helper with mode `0`.
  - On either successful existence check, it writes word `0x0a01` to `this + 0x2918f8`.
- Candidate interpretations:
  - `m_systemHelperFlags`: accepted as descriptive name.
  - `m_securityHelperPresenceFlags`: possible, but less directly supported by names.
  - Treat this tail as a separate raw helper: rejected because it is inside `0x004926a0-0x00493e29` and there is no split/padding before it.
  - Treat `0x0a01` as fully decoded bitfield: rejected; exact bit meanings are not proven.
- Final direction:
  - Document `this + 0x2918f8` as system helper presence flags set to `0x0a01` when `%SystemRoot%\System32\mscfg.dll` or `grcframe.exe` exists.
- Score/C++ impact:
  - Use a descriptive `SystemDirectoryFileExists` helper in draft C++; exact bit names remain a score cap.

### 11. Registry API import/global slot naming

- Evidence checked:
  - Direct IAT calls and dynamic import-slot assignments around the registry import loader.
  - LoadFromRegistry call sites for `RegQueryInfoKeyW` and `RegEnumValueW`, which were underdocumented in SaveToRegistry-focused prose.
  - Existing accepted [UID:00032G] report for `RegCreateKeyExW`, `RegQueryValueExW`, and related imports.
- Candidate interpretations and final direction:
  - `dword_69BE94 = RegCreateKeyExW`: accepted.
  - `dword_69BE98 = RegDeleteKeyW`: accepted for sibling SaveToRegistry; not central in this load body.
  - `dword_69BE9C = RegEnumValueW`: accepted, called in the `Midi` enumeration loop.
  - `dword_69BEA0 = RegQueryInfoKeyW`: accepted, called before `Midi` enumeration.
  - `dword_69BEA4 = RegQueryValueExW`: accepted, used for the main option/value load reads.
  - `dword_69BEA8 = RegSetValueExW`: accepted, relevant to `CLSID` direct/IAT write and SaveToRegistry slot naming.
  - Direct IAT `ADVAPI32!RegCloseKey`: accepted for handle cleanup.
- Rejected alternatives:
  - Leaving raw `dword_69BE9C` / `dword_69BEA0` labels: rejected because call argument shape and import initialization resolve them.
  - Treating these as wrapper functions: rejected; they are function-pointer slots/direct imports, not source-authored helpers.
- Score/C++ impact:
  - Resolves raw import naming for target and support docs. Supports first-draft C++ using Win32 API names directly.

### 12. Separation from [UID:00032G] `RegistryConfigTypeProbeRaw`

- Evidence checked:
  - [UID:00032G] accepted report and implemented support docs identify a retained no-xref helper querying `HKLM\SOFTWARE\Nexon\Kingdom of the Winds\<current-directory>\Type`.
  - [UID:0002P8] opens/creates `HKCU\Software\Nexon\Kingdom of the Winds` and does not query `Type`.
  - [UID:0002P8] is vtable-routed through `RegistryConfig::LoadFromRegistry`; [UID:00032G] has no direct xrefs and is file-static retained helper code.
- Candidate interpretations:
  - Shared `RegistryConfig.cpp` source file only: accepted.
  - [UID:00032G] as callee/helper of [UID:0002P8]: rejected; no call, no shared target key, and distinct HKLM/HKCU semantics.
  - [UID:00032G] as class method: rejected; already settled as file-level helper.
- Final direction:
  - Target and support docs must explicitly distinguish normal HKCU option load from retained HKLM current-directory `Type` probe.
- Score/C++ impact:
  - Prevents source-route pollution. No C++ blocker.

### 13. Separation from [UID:0002VB] `UnreferencedAdapterPhysicalAddressFormatterRaw`

- Evidence checked:
  - [UID:0002VB] starts at `0x00493e30` after seven bytes of padding following [UID:0002P8].
  - [UID:0002VB] has no direct callers/pointer hits in its page; it is a retained raw clone/file helper.
  - [UID:0002P8] contains an inline adapter-formatting block at `0x00492800-0x00492899` and then calls `Md5BytesToBuffer`.
  - There is no call from [UID:0002P8] to `0x00493e30`.
- Candidate interpretations:
  - [UID:0002VB] as sibling retained clone: accepted.
  - [UID:0002VB] as continuation after [UID:0002P8]: rejected because of `ret`, padding, and separate body.
  - [UID:0002VB] as callee implementation of `BuildFirstAdapterPhysicalAddressString`: rejected because no call route exists.
- Final direction:
  - In draft C++, `BuildFirstAdapterPhysicalAddressString` is a descriptive source-extraction name for the inline block, not a call to [UID:0002VB].
- Score/C++ impact:
  - Clears range/split and helper ownership issues. No reason to keep target C++ blank.

### 14. Helper-extraction names in first-draft C++

- Evidence checked:
  - The body inlines many repeated `RegQueryValueExW` patterns, string allocation/copy logic, MIDI enumeration, multi-server load, and system-directory path testing.
  - No separate binary functions were found for most high-level helper names in the draft C++.
  - The goal is plausible mid-2000s source C++, not a decompiler-shaped 0x1789-byte monolith.
- Candidate helper names and classification:
  - `BuildFirstAdapterPhysicalAddressString`: source-facing extraction candidate for the inline `GetAdaptersAddresses` formatting block; not a proven separate binary function and not [UID:0002VB].
  - `ReadBinaryWideStringValue`, `ReadFixedWideStringValue`, `ReadClampedByteValue`, `ReadDwordValue`, etc.: source-facing extraction candidates or documentation shorthand for repeated registry query idioms; not proven separate binary functions.
  - `LoadMidiRegistryValues`: source-facing extraction candidate for the `Midi` enumeration loop; not proven separate binary function.
  - `LoadMultiServerEntries`: source-facing extraction candidate for the `Servers` loop; not proven separate binary function.
  - `SystemDirectoryFileExists`: source-facing extraction candidate for the tail file-existence probe; not proven separate binary function.
  - `ConfigEntryBlock::ReleaseOwnedBuffers`: proven separate binary callee at `0x00494130`.
  - `Md5BytesToBuffer`: proven separate binary callee at `0x005153e0`.
- Rejected alternatives:
  - Emitting only raw calls and stack locals: rejected because it would be decompiler-shaped and less likely original source.
  - Claiming extraction helpers are proven functions: rejected because binary evidence does not support separate function starts/calls.
- Final direction:
  - Use helper names as descriptive source-level extraction candidates in first-draft C++ and mark them as such in the documentation.
- Score/C++ impact:
  - Helper-extraction uncertainty caps final completion but does not block draft C++.

### 15. First-draft C++ readiness and obsolete blank-C++ wording

- Evidence checked:
  - Current target metadata is `84/90` before recommended changes, reconstructable true, nonblank emitter [UID:0000BW]; current average is already above the active code-entry threshold.
  - [UID:0000BW] and [UID:0000N4] provide a valid emitter route to `auto-generated/NexusTK/config/RegistryConfig.cpp`.
  - Boundary, ownership, return type, registry API names, major field roles, sibling separation, and range splits are resolved enough for source-level code.
  - Existing target/class text still uses obsolete "below 95/95" style reasoning.
- Candidate outcomes:
  - Populate first-draft method C++: accepted.
  - Keep C++ blank until 95/95: rejected as obsolete under current rules and not target-specific.
  - Keep C++ blank because original field spellings are not proven: rejected; source-quality names are strong enough and remaining spellings can be documented as inferred.
  - Defer because of multi-server/MIDI struct uncertainty: rejected as a full blocker; these affect exact struct polish, not method identity or source behavior.
- Final direction:
  - Raise to `88/90`, replace obsolete blank-C++ wording, and add first-draft `bool RegistryConfig::LoadFromRegistry()` with descriptive names and caveats.
- Score/C++ impact:
  - First-draft C++ is ready. Completion is capped below 90 by original spelling/struct helper uncertainty; confidence rises because the binary behavior and source route are strongly validated.

### 16. Implementation checklist stability

This correction adds the required structured heuristic/inference section and does not change the report's recommendations. The implementation checklist, target metadata recommendation, support-doc checklist, first-draft C++ direction, and exact pending coverage row remain unchanged unless the supervisor chooses to adjust wording during callback review.

## Recommended target doc changes

Apply the following to `by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md` during the implementation callback:

1. Raise metadata:
   - `COMPLETION:85 -> 88`
   - `CONFIDENCE:87 -> 90`
   - Keep `CANONICAL_OWNER:0000BW`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:0000BW`
2. Replace stale "keep C++ blank" / "below 95/95" wording with:
   - `The active code-entry gate is cleared. Source C++ should model bool RegistryConfig::LoadFromRegistry(), including the HKCR NXKRI.Ctrl.1 CLSID DWORD seed, adapter physical-address MD5 digest, HKCU Kingdom of the Winds option load, Midi/DialogPos/Servers loops, ConfigEntryBlock cleanup, and system-directory helper-file probe. Remaining uncertainty is original member spelling, not an emitter blocker.`
3. Populate the formal C++ block with a source-level first draft based on the C++ section above.
4. Add the exact range/padding boundary map from this report.
5. Add the route/liveness section:
   - no direct ordinary code caller required;
   - virtual route through `RegistryConfig` vtable slot `0x00612624`;
   - adjacent SaveToRegistry vtable slot `0x00612620`;
   - sibling raw helper [UID:0002VB] not a continuation or callee.
6. Add the registry import slot table, especially `dword_69BE9C = RegEnumValueW`, `dword_69BEA0 = RegQueryInfoKeyW`, and `dword_69BEA4 = RegQueryValueExW`.
7. Add the value/offset map above. It is acceptable to place the table in the target or split a longer final field inventory to support docs, but the target should at least carry every registry value family and object-offset role.
8. Add explicit current-directory/Type probe separation:
   - [UID:00032G] queries `HKLM\...\<current-directory>\Type`;
   - [UID:0002P8] loads regular options from `HKCU\Software\Nexon\Kingdom of the Winds`.
9. Add `AutoMove` caveat:
   - query observed, no object write found; treat as compatibility/no-op load-side read until an offset is proven.
10. Add source-placement/rejected-owner bullets from this report.

## Support-doc update checklist

### `by-class/RegistryConfig.md`

Recommended updates:

- Update [UID:0002P8] row to `bool RegistryConfig::LoadFromRegistry()` and note vtable slot `0x00612624`.
- Replace stale "Final C++ remains blank because registry persistence bodies are below 95/95" wording. New wording should say the by-memory target emits the method body; the class page carries class/API inventory and declarations.
- Add class field-role inventory or link to target:
  - `m_registryClassIdSeed` at `+0x28de34`
  - `m_adapterPhysicalAddressDigest` at `+0x28de38`
  - `m_iconsPaneReducedMode` at `+0x28de32`
  - chat fields at `+0x28de78..+0x28de8d`
  - music-control cluster at `+0x291908..+0x291914`
  - `m_dialogPositions` at `+0x2914b8`
  - `m_serverEntries` at `+0x28db10`
  - `m_serverEntryCount` at `+0x28de10`
  - `m_multiServerInfoVersion` at `+0x28de14`
- Keep [UID:00032G] as file-helper reference only, not a class method.
- Keep [UID:0002VB] as file-level retained raw helper/dead clone.

### `by-file/RegistryConfig.md`

Recommended updates:

- Update the proposed contents row for [UID:0002P8] to describe the now source-ready `RegistryConfig::LoadFromRegistry()` method.
- Add that the generated source should no longer leave [UID:0002P8] as an empty marker after accepted implementation.
- Add dynamic import slots `RegQueryInfoKeyW` and `RegEnumValueW` to the registry API wrapper/import inventory.
- Add the source helper name recommendations:
  - `BuildFirstAdapterPhysicalAddressString` for the inline adapter block.
  - `LoadMidiRegistryValues` for `Midi` subkey enumeration.
  - `LoadMultiServerEntries` for `Servers` record rebuild.
  - `SystemDirectoryFileExists` or `UpdateSystemHelperFlagsFromSystemDirectory` for the `mscfg.dll` / `grcframe.exe` tail.
- Preserve distinction between normal option save/load, current-directory `Type` probe [UID:00032G], and retained adapter clone [UID:0002VB].

### `by-memory/0x00491b30-0x00492695.RegistryConfigSaveToRegistry.md`

Recommended updates:

- Add cross-reference to [UID:0002P8]'s matching load-side value map.
- Note that `AutoMove` is written by SaveToRegistry but the current LoadFromRegistry body only performs a compatibility/stale query with no observed object write.
- Add or link field names for values shared with LoadFromRegistry.
- Preserve SaveToRegistry as a separate adjacent method ending at `0x00492695`, with 11 bytes of padding before LoadFromRegistry.

### `by-memory/0x00491b30-0x004941d6.RegistryPersistenceAndConfigEntryCleanup.md`

Recommended updates:

- Update the [UID:0002P8] child row to the recommended `88/90` source-quality state.
- Expand the child summary:
  - virtual `RegistryConfig::LoadFromRegistry`;
  - HKCR `NXKRI.Ctrl.1` `CLSID` DWORD seed;
  - adapter MD5 digest;
  - HKCU option load;
  - `Midi`, `DialogPos%d`, and `Servers` loops;
  - system-directory helper-file tail;
  - [UID:0002VB] remains a sibling raw helper, not part of the method.
- Keep aggregate C++ blank/non-emitting; children emit.

### `by-memory/0x00617420-0x006178c8.RegistryConfigOptionStringData.md`

Recommended updates:

- Add LoadFromRegistry-specific xref notes for the complete option-value inventory listed in this report.
- For `AutoMove`, add the load-side caveat: queried in [UID:0002P8], result not observed stored.
- Add that `ChatWindow`, `ChatColor`, `Color%d`, `Midi`, `DialogPos%d`, and `Servers` subkey value families are now mapped to source roles.

### `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`

Recommended updates:

- Tie `%s%.2X-` and `%s%.2X]` to both:
  - inline adapter formatting inside [UID:0002P8] at `0x00492800-0x00492899`;
  - retained raw clone [UID:0002VB] at `0x00493e30-0x00493ef0`.
- Tie `mscfg.dll` and `grcframe.exe` to the [UID:0002P8] system-directory helper-presence tail.
- Clarify that `CLSID` at `0x00617920` is a four-byte registry DWORD value name in this body, not a C++ `CLSID` struct.

### `by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md`

Recommended updates:

- Add a cross-reference saying [UID:0002P8] does not query `Type`; [UID:00032G] remains the only current xref to the wide `Type` value name.
- Keep root-string sharing notes but prevent conflating HKLM current-directory `Type` probe with HKCU normal option load.

### `by-type/by-struct/RegistryConfigUserProfileBlock.md`

Recommended updates:

- Keep existing chat-field names and add/confirm registry-load routes for:
  - `+0x28de78` `m_chatVisibleLineCount`
  - `+0x28de7c` `m_chatHandleModeIndex`
  - `+0x28de80` `m_secondaryChatEnabled`
  - `+0x28de81` `m_chatHandleLeftToggle`
  - `+0x28de82..+0x28de8d` `m_chatColorPairs[6]`
- Add note that [UID:0002P8] decodes `ChatWindow` and `ChatColor` into these fields and applies binary defaults on invalid/missing values.
- Consider adding adjacent RegistryConfig field roles outside the profile sub-block if local policy allows, especially `+0x28de10`, `+0x28de14`, `+0x28de30`, `+0x28de32`, `+0x28de34`, `+0x28de38`, and `+0x28db10`.

### `by-memory/0x00493e30-0x00493ef0.UnreferencedAdapterPhysicalAddressFormatterRaw.md`

Recommended updates:

- Add a support note that [UID:0002P8] contains the live inline version of the adapter-formatting pattern.
- Preserve no-xref/file-helper/dead-clone treatment for [UID:0002VB].
- Do not make [UID:0002VB] the owner or callee of [UID:0002P8].

### `by-memory/0x00494130-0x004941d6.ConfigEntryBlockReleaseOwnedBuffers.md`

Recommended updates:

- Add that [UID:0002P8] calls this helper at `0x004938d6` before rebuilding `Servers` entries and at `0x00493e01` on partial-load cleanup.
- Confirm the block base `this + 0x28db10` and relationship to `m_serverEntries`.

### `by-memory/0x0066d468-0x0066d47c.CommandLineAndConfigStringPointers.md`

Recommended optional update:

- Add that the `mscfg.dll` / `grcframe.exe` string pointers are consumed by [UID:0002P8]'s system-directory helper-presence probe and set `this + 0x2918f8` to `0x0a01` when either file exists.

### MD5/string utility support docs

Recommended optional update:

- In the MD5 helper/file docs, add that [UID:0002P8] passes a formatted first-adapter physical-address string into `Md5BytesToBuffer` at `0x004928ba` and stores the 16-byte digest at `RegistryConfig + 0x28de38`.
- In string utility docs, no ownership transfer is needed; StringBase/SimpleUString helpers are dependencies for `MP3Dir` and the system-directory tail only.

## IDA rename/type/comment recommendations

Function/type names:

- `0x004926a0`: `RegistryConfig::LoadFromRegistry` or `RegistryConfig_LoadFromRegistry`
- `0x005153e0`: `Md5BytesToBuffer` if not already named
- `0x004944f0`: `WideStringScanf` / `swscanf` wrapper
- `0x00443a00`: `SprintfS_Narrow` / `_sprintf_s` wrapper
- `0x00494130`: `ConfigEntryBlock::ReleaseOwnedBuffers`
- `0x00493e30`: `RegistryConfig_FormatFirstAdapterPhysicalAddress_RetainedRaw` / `UnreferencedAdapterPhysicalAddressFormatterRaw`

Import/global names:

- `dword_69BE94`: `pRegCreateKeyExW`
- `dword_69BE9C`: `pRegEnumValueW`
- `dword_69BEA0`: `pRegQueryInfoKeyW`
- `dword_69BEA4`: `pRegQueryValueExW`
- `dword_69BEA8`: `pRegSetValueExW`

Structure/member comments on `RegistryConfig`:

- `+0x28db10`: multi-server/config-entry block base, `m_serverEntries`
- `+0x28de10`: loaded multi-server count
- `+0x28de14`: `MultiServerInfoVersion`
- `+0x28de30`: font index
- `+0x28de32`: IconsPane reduced/display-mode byte, zero means full strip, nonzero means reduced
- `+0x28de34`: HKCR `NXKRI.Ctrl.1\CLSID` DWORD seed
- `+0x28de38`: adapter physical-address MD5 digest, 16 bytes
- `+0x28de48..+0x28de77`: scalar audio/UI option cluster
- `+0x28de78..+0x28de8d`: chat-window/chat-color cluster
- `+0x28de90`: system message height
- `+0x28de94..+0x28de9b`: four WORD `Color%d` values
- `+0x2912b4`: MIDI registry list object pointer/reference; exact original name unproven
- `+0x2914b8`: `DialogPos%d` 12-byte records
- `+0x2916cc`: heap `LogData` wide text
- `+0x2916d0`: last server fixed string
- `+0x2918f4`: sound latency
- `+0x2918f8`: system helper presence flags, value `0x0a01`
- `+0x291908..+0x291914`: music-control cluster

Comments:

- At `0x004928ba`: `// MD5 of formatted first adapter physical address -> this+0x28de38`
- At `0x00492ceb`: `// AutoMove compatibility query; no object store observed before next value`
- At `0x00493739`: `// RegQueryInfoKeyW for Midi value count`
- At `0x0049378d`: `// RegEnumValueW for Midi indexed values`
- At `0x004938d6`: `// clear existing server entries before loading Servers subkey`
- At `0x00493c9e`: `// GetSystemDirectoryA; probe mscfg.dll/grcframe.exe`

## Exact pending coverage row

Do not edit `by-memory/-coverage-report.md` during this report pass. If the implementation is accepted, supervisor can replace the current row with:

```text
        - [UID:0002P8][0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry](by-memory/0x004926a0-0x00493e29.RegistryConfigLoadFromRegistry.md) 0x004926a0-0x00493e29 | method | RegistryConfig::LoadFromRegistry : reconstructable : 88% : very strong : B003 2026-06-19 source-quality reanalysis confirms exact vtable-routed `RegistryConfig::LoadFromRegistry` body, HKCR `NXKRI.Ctrl.1`/`CLSID` DWORD seed read/write, adapter physical-address formatting and `Md5BytesToBuffer` digest at `this+0x28de38`, HKCU `Software\Nexon\Kingdom of the Winds` option load, resolved `RegCreateKeyExW`/`RegQueryInfoKeyW`/`RegEnumValueW`/`RegQueryValueExW`/`RegSetValueExW`/`RegCloseKey`/`GetSystemDirectoryA`/`GetAdaptersAddresses` roles, mapped registry values to `RegistryConfig` offsets including chat/color/profile/audio/server blocks, distinguished retained `Type` probe and raw adapter clone, documented `Midi`/`DialogPos%d`/`Servers` loops and `ConfigEntryBlock` cleanup, and recommends first-draft method C++ with remaining original field spellings capped as source-quality uncertainty.
```

## Validation commands expected after implementation

Run from `source-3/project-documentation` after by-* implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002P8-RegistryConfigLoadFromRegistry-source-quality-removed.md](0002P8-RegistryConfigLoadFromRegistry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If optional MD5/string-pointer support docs are edited, validate those files with the same `--mode file --file ... --apply --queue-timeout 240` pattern.

No validators were run during this report-only pass because no by-* documentation was edited.

## Implementation checklist for supervisor callback

1. Edit only accepted target/support docs; do not edit `by-memory/-coverage-report.md`.
2. Apply target metadata `85/87 -> 88/90`.
3. Add the first-draft `bool RegistryConfig::LoadFromRegistry()` C++ block or an equivalent source-level method body preserving the helper and field-name caveats.
4. Replace stale no-C++/95-gate wording.
5. Insert or merge the boundary/range, route/liveness, import-slot, value/offset, source-placement, rejected-owner, and open-question sections above.
6. Update support docs in the checklist with no loss of detail:
   - class API and field inventory;
   - file-level source route and helper names;
   - Save/Load relationship and `AutoMove` mismatch;
   - aggregate child row;
   - option/adapter/channel string-data cross-references;
   - ConfigEntryBlock cleanup route;
   - raw adapter clone separation.
7. Provide the exact pending coverage row above in implementation notes but leave the coverage file unchanged.
8. Run the validators listed above and report exact results.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002P8-RegistryConfigLoadFromRegistry-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002P8"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002P8-RegistryConfigLoadFromRegistry-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002P8-RegistryConfigLoadFromRegistry-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002P8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
