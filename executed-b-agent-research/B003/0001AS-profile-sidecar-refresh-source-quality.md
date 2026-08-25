** TARGET-REPORT-UID:0001AS **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AS ProfileSidecarRefresh Source-Quality Report

Assignment: `B003-goal2-profile-sidecar-refresh-source-quality-0001AS-20260617`  
Agent: `Agent-B003`  
Primary target: [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](../../../by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)  
Report-only result: no by-* docs, generated source, IDA DB, or coverage reports were edited.

## Executive Recommendation

Raise [UID:0001AS] from `82/88` to `88/91`, keep `RECONSTRUCTABLE:TRUE`, keep owner/emitter [UID:0000MS][ProfileStorage](../../../by-file/ProfileStorage.md), and populate the formal `RECONSTRUCTION_CPP` block with the first-draft C++ below.

The main correction is that sidecar image and `.jpf` filenames are keyed by the local-player-name string helper at `0x005a2dc0` / [UID:0002AA][LocalPlayerNameWideBuffer](../../../by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md), while `g_pConfig + 0x2912b8` is the selected profile name appended to outbound opcode `79`. Existing docs currently blur those roles.

Source placement should remain `NexusTK/profile/ProfileStorage.cpp`. No split is required: the helper is a real standalone `void __cdecl RefreshSelectedProfileData()` function, bounded exactly by padding, with ProfileDialog and MapPane as triggers/consumers rather than owners.

## Evidence Checked

- Current target/support docs: [UID:0001AS], [UID:0000MS], [UID:0000MR], [UID:0001DU], [UID:0000L3], [UID:0001QL], [UID:0001VR], [UID:00027P], [UID:0003IV], [UID:000175], [UID:0002AA], [UID:0000Q5], packet helper docs [UID:0001HZ] and [UID:0001HU].
- Existing B reports searched for `0001AS`, `ProfileSidecarRefresh`, `RefreshSelectedProfileData`, and `0x005063e0`; no prior B report for this UID was found. The only old research hit was a non-authoritative B001 resource-layout reference.
- Generated output checked: `auto-generated/NexusTK/profile/ProfileStorage.cpp` exists but is `0` bytes.
- Live IDA MCP endpoint `http://127.0.0.1:13337/mcp`, database session `b003_00018a_ime_comp_20260617`; `server_health` reported `NexusTK.exe.i64`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
- Live IDA calls used: `server_health`, `lookup_funcs`, `xrefs_to`, `decompile`, `analyze_function`, `disasm`, `callees`, `get_bytes`, and `find_bytes`.

## Target Findings

`lookup_funcs` and `analyze_function` now name the function `RefreshSelectedProfileData`, address `0x005063e0`, size `0x582`, prototype `void __cdecl()`. The target has no real `this` receiver.

Direct reachability is exactly three code refs: `0x005089e3` in `sub_507C90` / MapPane packet dispatcher case `73`, `0x0053fe65` in ProfileDialog action/apply flow, and `0x0053fe96` in the tiny wrapper `0x0053fe90`. `xrefs_to 0x0053fe90` reports no callers. Raw VA pointer scans for `e0 63 50 00` and `90 fe 53 00` found no absolute pointer-table reachability.

The ProfileDialog caller writes sanitized accepted text into `g_pConfig + 0x2912b8` using `_wcscpy_s(..., 0x100, Source)` and then calls `RefreshSelectedProfileData()`. The wrapper decompiles to a tail call; raw disassembly shows `mov ecx, dword_67A764; jmp RefreshSelectedProfileData`, but the target is `__cdecl`, so the ECX load is not source ownership evidence.

The MapPane caller at `0x005089e3` sits in jump-table case `73`; disassembly shows `lea ecx, [esi-0xa0]` before the call, but the callee ignores ECX. This is a packet-trigger route into profile refresh, not a MapPane-owned helper.

The sidecar filename stem is not `g_pConfig + 0x2912b8`. The target calls `0x005a2dc0` at `0x00506426`, and live decompilation of `0x005a2dc0` is:

```cpp
void **__cdecl sub_5A2DC0(void **out)
{
    sub_582560(out, word_69BEE0);
    return out;
}
```

`xrefs_to 0x0069bee0` confirms the known four refs: setter `0x005a2d80`, copy-out helper `0x005a2da0`, string-object helper `0x005a2dc0`, and block-list validation `0x005b6cc0`. Therefore best source-facing names are `GetLocalPlayerNameString` / `localPlayerName` for the sidecar path stem, and `RegistryConfig::selectedProfileName` for the packet field at `+0x2912b8`.

The sidecar table [UID:00027P] remains a five-entry ProfileStorage static extension list. Live `xrefs_to 0x0066dd60` reports one table-base ref at `0x005064d0` inside the target. String xrefs to `0x0061e990`, `0x0061e9a4`, `0x0061e9c8`, and `0x0061e9dc` all resolve inside the target. Raw pointer scans for `60 dd 66 00`, `c8 e9 61 00`, and `dc e9 61 00` found the expected target-only references.

Packet semantics are now source-quality enough for a first draft:

- Writes opcode `79` with `0x00575650` / cursor byte append.
- Writes a 16-bit payload length with `0x00575670` / cursor big-endian uint16 append.
- For valid JPF files, reads the full `.jpf` into the packet after the three-byte header and decodes the payload through [UID:000175] `0x004d07b0`.
- Accepts the payload only when decoded bounds are exactly `48 x 56` (`right-left == 48`, `bottom-top == 56`).
- On missing, oversized (`>= 0x2710`), or wrong-dimension JPF data, sends opcode `79` with length `0`.
- Appends the selected profile name from `g_pConfig + 0x2912b8` using `0x00575850` / wide-string-to-ANSI one-byte length-prefixed append.
- Queues through [UID:0001HU] `0x00574bb0(dword_67A7EC, packet, cursor)`.

Range is exact. `get_bytes 0x005063db size 5` returned five `0xcc` bytes before the function, and `get_bytes 0x00506962 size 14` returned fourteen `0xcc` bytes after it. There is no internal raw-island or child-split pressure.

## Heuristic / Inference Reanalysis And Validation

| Topic | Best defensible inference | Evidence checked | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Source name/signature | `void RefreshSelectedProfileData()` as a file-level/free helper in `ProfileStorage.cpp`. | IDA name `RefreshSelectedProfileData`; `analyze_function` prototype `void __cdecl()`; decompile has no parameters. | `ProfileStorage::RefreshSelectedProfileData(this)` and `MapPane::Refresh...` rejected because ECX is ignored and the two non-wrapper callers call the same cdecl helper. | Clears signature blocker; supports formal C++ and `88/91`. |
| Filename identity | Sidecar files use local player name from `word_69BEE0` via `0x005a2dc0`. | Target decompile calls `sub_5A2DC0(v27)` before `%s/%s.%s`, `%s/%s.jpf`, and `./users/%s.jpf`; `0x005a2dc0` copies `word_69BEE0`; [UID:0002AA] documents the 32-wide-char local-player-name buffer. | Existing statement that `g_pConfig +0x2912b8` forms `<profile>.jpf` is rejected. `0x005a2da0` user-id helper is also rejected for this target because the live call is `0x005a2dc0`. | Requires target/meta/layout doc correction; increases completion because a listed field/path blocker is resolved. |
| Packet selected profile field | `RegistryConfig::selectedProfileName` or `selectedProfileName[0x100]` at `+0x2912b8`. | ProfileDialog action handler writes accepted profile text to `g_pConfig+2691768`; target appends the same field to opcode `79`; [UID:0001VR] records `wchar_t[0x100]`. | Treating the field as generic user id or filename stem is rejected because path formation uses `word_69BEE0`; treating it as UI-only is rejected because target appends it to network packet. | Field name is stable enough for first draft; support docs should phrase it as packet selected-profile text, not filename source. |
| Extension table | `kProfileSidecarExtensions = { L"bmp", L"pcx", L"jpg", L"jpeg", L"pnm" }`. | [UID:00027P] exact pointer table; live `xrefs_to` one base ref; target loop bound is five entries. | Generic image writer/global image-extension owner rejected because no non-ProfileStorage consumer exists. | Supports ProfileStorage ownership and C++ static data. |
| FaceRipper role | Compatibility conversion/normalization tool run for the first found sidecar image. | Target formats `FaceRipper.exe %s`, initializes `STARTUPINFO` with cb `68`, calls process-launch import, waits `0x2710` ms. | Image decoder ownership rejected; the decoder is not run until later `.jpf` handling. UI ownership rejected; no UI state is touched. | Source helper stays profile sidecar refresh; no split. |
| JPF helper | [UID:000175] `DecodeJpfImageToTileContext` is a decoder dependency, not owner. | Target calls `0x004d07b0((char*)packet+3, fileSize, tileContext)` after reading JPF bytes; [UID:000175] has other image consumers. | Moving target into ImageLoaders rejected because all path/profile/packet logic is ProfileStorage and decoder is a callee. | Source placement remains `profile/ProfileStorage.cpp`. |
| Opcode `79` payload | Profile portrait/sidecar refresh request: byte opcode `79`, uint16 JPF length, optional raw JPF bytes, then selected-profile string. | Decompile/disasm around `0x50679f`, `0x5067b2`, `0x506835`, `0x506858`, `0x506875`, `0x5068de`, `0x5068f3`, `0x506911`; packet helper docs for `0x00575650`, `0x00575670`, `0x00575850`, and `0x00574bb0`. | A pure "upload local player name" packet rejected because the selected-profile field is appended after the image payload. A FaceRipper control packet rejected because FaceRipper is local process execution before packet construction. | Protocol semantics are stable enough for formal draft; exact enum label can remain descriptive. |
| Ownership/source placement | [UID:0000MS] `ProfileStorage`, `NexusTK/profile/ProfileStorage.cpp`. | Proposed source tree groups this helper with profile load/save/import; function uses profile file paths, sidecars, config profile field, and packet sender dependency; generated route is `auto-generated/NexusTK/profile/ProfileStorage.cpp`. | `ProfileDialog.cpp` rejected because dialog only writes selected text and triggers. `MapPane.cpp` rejected because packet case only triggers. `Socket/PacketBuffer.cpp` rejected because those are generic send helpers. `ImageLoaders.cpp` rejected because decoder is a dependency. | Owner/emitter unchanged; no child split. |
| Range/split | Exact one-function target; no in-scope split. | Function size `0x582`; padding before/after confirmed; no raw starts inside target; callees are external/shared helpers. | Creating child docs for extension table, strings, local player buffer, decoder, or packet helpers rejected because those already exist and are dependencies, not contained children. | Report-only scope is correct. |
| Generated output | Current generated file is missing target body. | `Get-Item auto-generated/NexusTK/profile/ProfileStorage.cpp` reported length `0`. | Treating generated output as authoritative rejected; it is an omission. | First-draft C++ should be provided for supervisor application. |

Remaining blockers are below the code-entry gate, not completion blockers: exact original filename (`ProfileStorage.cpp` versus legacy equivalent), exact source names for generic wide-string/path wrappers, and the official opcode enum label are not proven. They do not cap [UID:0001AS] below 85 because the target-specific source shape, field roles, caller map, packet layout, and owner route are now evidence-backed.

## Exact Supervisor-Owned Doc Changes

### [UID:0001AS] Metadata

Recommended header changes:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the current Status confidence bullet with:

```markdown
- Confidence: very strong for boundary, cdecl signature, behavior, local-player filename stem, selected-profile packet field, sidecar table, caller map, ProfileStorage ownership, and first-draft C++ shape; medium-high for final original source filename and generic path/string wrapper names.
```

Replace the current Behavior section with:

```markdown
This function is shared by profile UI and a packet-driven `MapPane` path. IDA confirms direct callers at `0x005089e3` in `sub_507C90` / MapPane packet case `73`, `0x0053fe65` in ProfileDialog apply flow, and wrapper tail jump `0x0053fe96` from [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md). The wrapper has no direct callers and only loads `dword_67A764` before jumping; live `analyze_function` reports the target prototype as `void __cdecl()`, so ECX is not semantic ownership evidence.

`RefreshSelectedProfileData` builds sidecar filenames from the local-player-name string helper `0x005a2dc0`, which wraps [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md). It uses [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) field `g_pConfig + 0x2912b8` as the selected profile name appended to outbound opcode `79`, not as the `.jpf` filename stem.

The helper creates/checks `Documents\NexusTK` and `Documents\NexusTK\users`, probes sidecar image extensions `bmp`, `pcx`, `jpg`, `jpeg`, and `pnm`, optionally launches `FaceRipper.exe <sidecar path>` and waits `10000` ms, then loads `<local-player-name>.jpf` from the documents users folder or `./users`. It queues opcode `79` with a 16-bit payload length, optional raw `.jpf` bytes, and a length-prefixed ANSI form of the selected profile name. Only `.jpf` data below `0x2710` bytes and decoded through [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) to exactly `48 x 56` is sent as a nonzero payload.
```

Replace the `selected profile/name` row in `Touched State` and insert a local-player row:

```markdown
| local player name | reads [UID:0002AA][LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) through `0x005a2dc0` | filename stem for `%s/%s.%s`, `%s/%s.jpf`, and `./users/%s.jpf` sidecar paths |
| selected profile/name | reads [UID:0001VR][RegistryConfigUserProfileBlock](by-type/by-struct/RegistryConfigUserProfileBlock.md) field at `g_pConfig + 0x2912b8` | profile text appended to outbound opcode `79`; ProfileDialog writes this field before triggering refresh |
```

Replace the Reconstruction Decision section with:

```markdown
Attach this helper to [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md). The two external trigger families are MapPane packet handling and ProfileDialog apply flow, but the body is selected-profile/local-player sidecar storage logic: it builds NexusTK user-profile paths, normalizes local image sidecars, decodes JPF profile portrait data, reads the selected profile field from `RegistryConfig`, and uses generic packet helpers only for final transport.

No child split is required. The range is one modeled `void __cdecl RefreshSelectedProfileData()` function with `0xcc` padding before and after it. The sidecar extension table, sidecar strings, local-player-name buffer, JPF decoder, packet writers, and Socket queue are existing dependencies/support docs, not contained child code.

Formal C++ should be populated with the first-draft source below. The remaining uncertainty is limited to original helper spelling for generic string/path/packet wrappers and the official opcode enum label; it does not block the active `85/85+` code-entry gate for this target.
```

Add a Changes entry:

```markdown
- 2026-06-17 B003 source-quality report: recommended `82/88` -> `88/91`, kept owner/emitter [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md), resolved source signature as `void __cdecl RefreshSelectedProfileData()`, corrected sidecar filename stem to [UID:0002AA][LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) via `0x005a2dc0`, kept `g_pConfig + 0x2912b8` as the selected-profile packet field, confirmed opcode `79` payload layout, rejected ProfileDialog/MapPane/Socket/ImageLoaders ownership alternatives, and supplied first-draft C++ for formal reconstruction.
```

### [UID:0000MS] ProfileStorage

No score change required. Replace the open question:

```markdown
- Whether `RefreshSelectedProfileData` should be split into `ProfileImage.cpp` or a small profile-network helper after packet send ownership is cleaned up.
```

with:

```markdown
- `RefreshSelectedProfileData` should remain in `ProfileStorage.cpp` unless future source-file evidence proves an original narrower profile-image helper file. B003's 2026-06-17 reanalysis showed the helper is a cdecl storage-side routine: sidecar filenames use the local-player-name buffer, packet text uses `RegistryConfig::selectedProfileName`, FaceRipper/JPF decode/PacketBuffer/Socket calls are dependencies, and ProfileDialog/MapPane are triggers rather than owners.
```

### [UID:0001QL] client_profile_storage

Replace the Source Ownership `RefreshSelectedProfileData` bullet with:

```markdown
- `RefreshSelectedProfileData` at `0x005063e0-0x00506962`.
```

Replace the Selected Profile Sidecars lead and first bullets with:

```markdown
`RefreshSelectedProfileData` uses the local-player-name buffer [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) through helper `0x005a2dc0` as the sidecar filename stem. It uses the selected profile/name field at `g_pConfig + 0x2912b8` as the profile text appended to outbound opcode `79`.

Observed sidecar behavior:

- It checks `bmp`, `pcx`, `jpg`, `jpeg`, and `pnm` files in `Documents\NexusTK\users` using the local-player-name stem.
- If any sidecar image exists, it launches `FaceRipper.exe <path>` and waits up to `10000` ms.
- It then looks for `<local-player-name>.jpf` in `Documents\NexusTK\users`, with `./users/<local-player-name>.jpf` as a fallback.
```

### [UID:0001VR] RegistryConfigUserProfileBlock

Replace the layout row for `+0x2912b8` with:

```markdown
| `+0x2912b8` | `0x200` bytes | `wchar_t[0x100]` | Selected profile/name field. ProfileDialog writes accepted profile text here; `RefreshSelectedProfileData` appends it to outbound opcode `79`. Sidecar filenames are instead keyed by the local-player-name helper at `0x005a2dc0`. |
```

Replace the Runtime Flow bullet for [UID:0001AS] with:

```markdown
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) reads `+0x2912b8` as the selected profile name appended to packet opcode `79`; it gets sidecar filename stems from the local-player-name helper at `0x005a2dc0`.
```

### [UID:0002AA] LocalPlayerNameWideBuffer

No score change required. Add this evidence bullet:

```markdown
- `0x005063e0` / `RefreshSelectedProfileData` calls `0x005a2dc0` and uses the resulting local-player-name string as the sidecar filename stem for `%s/%s.%s`, `%s/%s.jpf`, and `./users/%s.jpf`; the selected-profile config field is appended to the packet separately.
```

## Coverage Row Text

Supervisor-owned `by-memory/-coverage-report.md` replacement for [UID:0001AS], at the existing row between the `0x005063db-0x005063e0` padding row and the `0x00506962-0x00506970` padding row:

```markdown
    - [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) 0x005063e0-0x00506962 | function | ProfileSidecarRefresh : reconstructable : 88% : very-strong : Live 2026-06-17 IDA reconfirmed exact cdecl `RefreshSelectedProfileData` bounds, three direct trigger refs, no raw pointer-table reachability, local-player-name sidecar filename stem via `0x005a2dc0`, selected-profile packet field at `g_pConfig+0x2912b8`, five-entry sidecar extension table, FaceRipper launch/wait, JPF cap/decode with `48x56` acceptance, opcode `79` payload layout, Socket queue dependency, ProfileStorage ownership, no split pressure, and first-draft C++ readiness.
```

Supervisor-owned `by-memory/-coverage-report.md` replacement for stale [UID:00027P], at the existing row in the `0x0066dd60-0x0066dd78` area:

```markdown
    - [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md) 0x0066dd60-0x0066dd78 | pointer table | ImageExtensionPointerTable : reconstructable : 85% : very-strong : Five-entry ProfileStorage image-sidecar extension pointer table for `bmp`, `pcx`, `jpg`, `jpeg`, and `pnm`; live IDA confirms exact pointer bytes, indexed table-base ref at `0x005064d0`, five-entry loop bound, zero padding, clean neighboring data boundaries, and sole consumption by `RefreshSelectedProfileData`.
```

Optional supervisor-owned `by-memory/-coverage-report.md` replacement for [UID:0002AA] if the new consumer bullet is applied:

```markdown
    - [UID:0002AA][0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer](by-memory/0x0069bee0-0x0069bf20.LocalPlayerNameWideBuffer.md) 0x0069bee0-0x0069bf20 | global-data buffer | LocalPlayerNameWideBuffer : reconstructable : 87% : very-strong : Assigned to UserPane after exact wchar_t[32] size proof from _wcscpy_s(..., 0x20, ...), full setter/getter/string-conversion/ProfileSidecarRefresh/block-list xrefs, contiguous neighbor check, and no-split review.
```

No `by-file/-coverage-report.md` row change is required for [UID:0000MS] because the recommended support edit closes placement wording without changing its score.

## First-Draft C++ Recommendation

Populate the formal `RECONSTRUCTION_CPP` block for [UID:0001AS]. This draft intentionally uses source-facing helper names for already documented dependencies; the binary addresses behind them are documented in this report and the support pages.

```cpp
namespace {

constexpr unsigned char kProfileRefreshOpcode = 79;
constexpr unsigned int kMaxProfileJpfBytes = 0x2710;
constexpr int kProfilePortraitWidth = 48;
constexpr int kProfilePortraitHeight = 56;
constexpr DWORD kFaceRipperWaitMs = 10000;

const wchar_t* const kProfileSidecarExtensions[] = {
    L"bmp",
    L"pcx",
    L"jpg",
    L"jpeg",
    L"pnm",
};

void SendProfileRefreshPacket(const unsigned char* jpfBytes, unsigned int jpfSize, bool includeJpf)
{
    unsigned char stackPacket[1024];
    AutoBuffer<unsigned char> heapPacket;
    unsigned char* packet = stackPacket;

    if (includeJpf) {
        heapPacket.Allocate(10010);
        packet = heapPacket.Data();
    }

    int cursor = 0;
    PacketBufferAppendByte(kProfileRefreshOpcode, packet, &cursor);
    PacketBufferAppendUInt16(includeJpf ? static_cast<unsigned short>(jpfSize) : 0, packet, &cursor);

    if (includeJpf) {
        memcpy(packet + cursor, jpfBytes, jpfSize);
        cursor += static_cast<int>(jpfSize);
    }

    PacketBufferAppendWideStringAsAnsi(g_pConfig->userProfile.selectedProfileName, packet, &cursor);
    QueueAndSendPacket(g_packetSender, packet, cursor);
}

bool CreateDirectoryIfNeeded(const wchar_t* path)
{
    if (CreateDirectoryW(path, nullptr)) {
        return true;
    }
    return GetLastError() == ERROR_ALREADY_EXISTS;
}

} // namespace

void RefreshSelectedProfileData()
{
    WideString localPlayerName;
    GetLocalPlayerNameString(localPlayerName);

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(nullptr, CSIDL_PERSONAL, nullptr, 0, documentsPath) != S_OK) {
        return;
    }

    wchar_t nexusDir[MAX_PATH];
    FormatWide(nexusDir, MAX_PATH, L"%s\\NexusTK", documentsPath);
    if (!CreateDirectoryIfNeeded(nexusDir)) {
        return;
    }

    wchar_t usersDir[MAX_PATH];
    FormatWide(usersDir, MAX_PATH, L"%s\\NexusTK\\users", documentsPath);
    if (!CreateDirectoryIfNeeded(usersDir)) {
        return;
    }

    WideString sidecarPath;
    for (const wchar_t* extension : kProfileSidecarExtensions) {
        FormatWide(sidecarPath, L"%s/%s.%s", usersDir, localPlayerName.c_str(), extension);
        if (!FileExists(sidecarPath.c_str())) {
            continue;
        }

        WideString commandLine;
        FormatWide(commandLine, L"FaceRipper.exe %s", sidecarPath.c_str());

        STARTUPINFOW startupInfo = {};
        PROCESS_INFORMATION processInfo = {};
        startupInfo.cb = sizeof(startupInfo);
        if (CreateProcessW(nullptr, commandLine.data(), nullptr, nullptr, FALSE, CREATE_NEW_CONSOLE,
                           nullptr, nullptr, &startupInfo, &processInfo)) {
            WaitForSingleObject(processInfo.hProcess, kFaceRipperWaitMs);
        }
        break;
    }

    WideString jpfPath;
    FormatWide(jpfPath, L"%s/%s.jpf", usersDir, localPlayerName.c_str());
    if (!FileExists(jpfPath.c_str())) {
        FormatWide(jpfPath, L"./users/%s.jpf", localPlayerName.c_str());
        if (!FileExists(jpfPath.c_str())) {
            SendProfileRefreshPacket(nullptr, 0, false);
            return;
        }
    }

    FILE* file = OpenBinaryFile(jpfPath.c_str());
    if (file == nullptr) {
        SendProfileRefreshPacket(nullptr, 0, false);
        return;
    }

    unsigned char ignoredHeader[4];
    fread(ignoredHeader, 1, sizeof(ignoredHeader), file);
    fseek(file, 0, SEEK_END);
    unsigned int jpfSize = static_cast<unsigned int>(ftell(file));

    if (jpfSize >= kMaxProfileJpfBytes) {
        SendProfileRefreshPacket(nullptr, 0, false);
        return;
    }

    AutoBuffer<unsigned char> packetBytes;
    packetBytes.Allocate(10010);

    int cursor = 0;
    PacketBufferAppendByte(kProfileRefreshOpcode, packetBytes.Data(), &cursor);
    PacketBufferAppendUInt16(static_cast<unsigned short>(jpfSize), packetBytes.Data(), &cursor);

    fseek(file, 0, SEEK_SET);
    cursor += static_cast<int>(fread(packetBytes.Data() + cursor, 1, jpfSize, file));

    ImageDrawContext decodedImage;
    InitializeImageDrawContext(&decodedImage);
    DecodeJpfImageToTileContext(packetBytes.Data() + 3, jpfSize, &decodedImage);

    const bool hasExpectedPortraitBounds =
        decodedImage.bounds.Width() == kProfilePortraitWidth &&
        decodedImage.bounds.Height() == kProfilePortraitHeight;

    if (hasExpectedPortraitBounds) {
        PacketBufferAppendWideStringAsAnsi(g_pConfig->userProfile.selectedProfileName, packetBytes.Data(), &cursor);
    } else {
        cursor = 1;
        PacketBufferAppendUInt16(0, packetBytes.Data(), &cursor);
        PacketBufferAppendWideStringAsAnsi(g_pConfig->userProfile.selectedProfileName, packetBytes.Data(), &cursor);
    }

    QueueAndSendPacket(g_packetSender, packetBytes.Data(), cursor);
    DestroyImageDrawContext(&decodedImage);
}
```

Safety notes for the supervisor: this should be treated as first-draft source, not final polished source. It deliberately preserves the observed no-payload fallback behavior and the local-player-name versus selected-profile-name distinction. The original binary's file-handle cleanup is not visible in the target's ordinary callee list, so final source should verify surrounding CRT/file wrapper behavior before adding/removing cleanup in production reconstruction.

## Validation Commands

Commands/evidence used for this report:

> Executable block R001 was removed from this report and preserved verbatim in [0001AS-profile-sidecar-refresh-source-quality-removed.md](0001AS-profile-sidecar-refresh-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

IDA MCP calls were run through `http://127.0.0.1:13337/mcp` with database `b003_00018a_ime_comp_20260617`:

```text
server_health
lookup_funcs: 0x005063e0, 0x00507c90, 0x005089e3, 0x0053fdc0, 0x0053fe65, 0x0053fe90, 0x00575650, 0x00575670, 0x00575850, 0x00574bb0, 0x004d07b0, 0x005a2dc0, 0x005a2da0
xrefs_to: 0x005063e0, 0x0053fe90, 0x0066dd60, 0x0061e990, 0x0061e9a4, 0x0061e9c8, 0x0061e9dc, 0x0069bee0
decompile: 0x005063e0, 0x0053fdc0, 0x0053fe90, 0x005a2dc0, 0x005a2da0
analyze_function: 0x005063e0
disasm: 0x005089d0, 0x0053fe90, 0x00506780
callees: 0x005063e0
get_bytes: 0x005063db size 5, 0x00506962 size 14
find_bytes: e0 63 50 00, 90 fe 53 00, 60 dd 66 00, c8 e9 61 00, dc e9 61 00
```

No by-* validator was run because this assignment only created this report and did not edit supervisor-owned documentation.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001AS-profile-sidecar-refresh-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001AS"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001AS-profile-sidecar-refresh-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001AS-profile-sidecar-refresh-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001AS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
