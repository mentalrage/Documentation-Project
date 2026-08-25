** TARGET-REPORT-UID:00024T **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00024T ApplicationStartupReadOnlyData Source-Quality Report

## Target And Mode

- Agent: Agent-B004
- Mode: report-only research
- Target UID: 00024T
- Target file: `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md`
- Target range: `0x006125a8-0x00612f3c`
- Required output: this report only
- Report file: `tools/leaser/Agents/Agent-B004/research/00024T-ApplicationStartupReadOnlyData-source-quality.md`
- Leases: none, per report-only override
- By-* edits: none, per report-only override
- Generated/project-level/coverage/tool-state/IDA DB edits: none

## Current Target State

The target currently presents the whole range as Application-owned startup read-only data:

- `COMPLETION:85`
- `CONFIDENCE:91`
- `CANONICAL_OWNER:0000HG`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000HG`
- formal `RECONSTRUCTION_CPP CODE` block is blank
- `Nested:-4`

That metadata is too source-specific for the actual range. The range is not one source-authored Application declaration. It is a contiguous `.rdata` interval containing several unrelated compiler-generated vtables/RTTI cells, source literals used by multiple classes/files, and Application startup string pools. The correct disposition is a non-emitting split/index page with blank formal C++.

## MCP Session And Requests

IDA MCP was mandatory and was available. I did not use fallback-only evidence.

- `MCP-1001`, `2026-06-26T19:59:00.0990016-04:00`: MCP `tools/list`, HTTP 200, 65 tools visible.
- `MCP-1003`, `2026-06-26T19:59:16-04:00`: `idb_list`, active session `80de0a67`, path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `26892`, `is_analyzing:false`.
- `MCP-1004`, `2026-06-26T19:59:16-04:00`: `server_health`, status `ok`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
- `MCP-1008`: name/string survey for `0x006125a8-0x00612f3c`.
- `MCP-1009`: representative bytes for the range.
- `MCP-1010` through `MCP-1013`: chunked entity/name survey and string reads.
- `MCP-1014`: xrefs to key vtable, RTTI, string, mutex, resource, license, patcher, and successor-boundary addresses.
- `MCP-1016`: xrefs to exact UTF-16 resource path starts.
- `MCP-1017`: function lookup for key consumer addresses.
- `MCP-1018`: resource-path bytes and UTF-16 decode.
- `MCP-1019`: dword inspection for vtable/RTTI transition cells.
- `MCP-1020`: function lookup for dword slot targets.
- `MCP-1022`: binary/segment survey.
- `MCP-REV-2001`, revision pass: MCP initialize succeeded.
- `MCP-REV-2002`, revision pass: MCP `tools/list` succeeded and confirmed the tool surface remained available.
- `MCP-REV-2004`, revision pass: `idb_list` confirmed the same active session `80de0a67`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend worker PID `26892`, `is_analyzing:false`.
- `MCP-REV-2005`, revision pass: `server_health` with database `80de0a67` returned status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready. `MCP-REV-2003` was a health call without the required database argument and returned the expected database-required error; it was not an MCP availability failure.

Segment proof from `MCP-1022`: `.rdata` is `0x0060d670-0x0066d000`, read-only, and the target range lies wholly inside it. The IDB hash proof was MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.

## Range And Boundary Analysis

The half-open range begins with `??_7PasswordError@@6B@` at `0x006125a8` and ends immediately before the BackGroundPane vtable at `0x00612f3c`. The final dword inside this range, `0x00612f38`, is the BackGroundPane RTTI/COL pointer for the successor vtable, not Application startup data. This alone disproves a single Application owner.

Representative named regions from the live IDA survey:

- `0x006125a8`: `??_7PasswordError@@6B@`
- `0x006125bc`: PasswordError descriptor string start, labeled internally as `aSswordWarning` at `0x006125c0`
- `0x006125e4`: `??_7Application@@6B@`
- `0x00612604`: `??_7Application@@6B@_0`
- `0x0061260c`: shared UTF-16 path separator dword, not an Application vtable cell
- `0x00612610`: RegistryConfig RTTI/COL pointer
- `0x00612614-0x00612624`: RegistryConfig vtable slots
- `0x00612628`: FunctionObject0 RTTI/COL pointer
- `0x0061262c`: `??_7FunctionObject0@@6B@`
- `0x00612640-0x00612e38`: OS/version/registry/DAT/resource/mutex/display/path string pool
- `0x00612e3c`: PlainMemberFunctionObject0<Application> RTTI/COL pointer
- `0x00612e40`: `??_7?$PlainMemberFunctionObject0@P8Application@@AEXXZV1@@@6B@`
- `0x00612e54-0x00612f34`: version/license/localization/error/patcher strings
- `0x00612f38`: BackGroundPane RTTI/COL pointer
- `0x00612f3c`: successor `??_7BackGroundPane@@6B@`

The child pages already present in the target are real source-quality children, but they cover only selected vtables:

- `by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md`
- `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md`
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`
- `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`

The gaps between and around those children are not filler. They include source literals, RTTI/COL pointers, a RegistryConfig vtable, shared path text, and a successor-class RTTI pointer.

## Xref Findings

`MCP-1014`, `MCP-1016`, `MCP-1019`, and `MCP-1020` resolve the stale blockers around ownership and source placement.

PasswordError:

- `0x006125a8` is referenced by `0x00467172` in the PasswordError constructor path.
- `0x006125bc` is referenced by `0x00467400` in `PasswordErrorGetErrorDescriptor`.
- Existing PasswordError docs already route the class to the Error hierarchy. This subrange is not Application-owned.

Application vtable and direct startup strings:

- `0x006125e4` and `0x00612604` are referenced by `Application__Constructor`, the Application destructor path, and the scalar deleting destructor path.
- `0x00612640` (`Win95:%02d%02d`) is used by Application constructor/version logic.
- `0x006126b4` (`[Key:%08x]`) and `0x006126cc` (`!! %s%s%s%s : %s, [%d,%d,%d,%d] OS:%s`) are used by the timer-skew/heartbeat diagnostic path.
- `0x0061271c` (`%s%d.DAT`) is used by Application initialization and the indexed DAT loader.
- `0x006127f8` (`IsWow64Process`) and OS label strings are used by the OS detection path.
- `0x00612b24` (`Global\Nexon.SingleInstance`) and `0x00612b40` (`Nexon.SingleInstance`) are used by Application initialization.
- Selected UTF-16 resource starts, including `DATA/MISC.DAT`, `DATA/MUS000.DAT`, and `DATA/BINT`, have direct Application initialization xrefs.

Shared literals and non-Application users:

- `0x0061260c` is referenced by Application version/license helpers and FolderTreePane path helpers at `0x004b1d50` and `0x004b3090`. It cannot be an Application-only literal.
- `0x006126f4` (`File not found : %s`) is referenced by Application constructor/Initialize, the indexed DAT loader, and the FileError constructor. It cannot be an Application-only literal.
- `0x00612980` (`Software\KRU\NexusTK`) is referenced by Application initialization and StartupWindow logic.
- `0x00612f24` (`runas`) and `0x00612f2c` (`patcher.exe`) are referenced by Application initialization and by update/patch helper code at `0x00548270` and `0x00548a80`.

RegistryConfig:

- `0x00612610` is a RegistryConfig RTTI/COL pointer.
- `0x00612614` points to `0x00467340`, documented as `RegistryConfigScalarDeletingDestructor`.
- `0x00612618` points to shared `LObject` slot code.
- `0x0061261c` points to `nullsub_18`.
- `0x00612620` points to `RegistryConfig::SaveToRegistry`.
- `0x00612624` points to `RegistryConfig::LoadFromRegistry`.
- Existing `by-class/RegistryConfig.md` already records this vtable beginning at `0x00612610`; the target page should not absorb it as Application startup data.

FunctionObjects:

- `0x00612628` is a FunctionObject0 RTTI/COL pointer.
- `0x0061262c` is the FunctionObject0 vtable and is already represented by child UID `0003OE`.
- `0x00612e3c` is the PlainMemberFunctionObject0<Application> RTTI/COL pointer.
- `0x00612e40-0x00612e54` is the PlainMemberFunctionObject0<Application> callback vtable and is already represented by child UID `0003OF`.

Successor boundary:

- `0x00612f38` is the BackGroundPane RTTI/COL pointer.
- `0x00612f3c` is the BackGroundPane vtable start and the next range boundary.
- Existing successor documentation for BackGroundPane/BackPane data should own that successor-class boundary evidence, not Application.

## Resource String Decode

The UTF-16 resource path pool is not visible correctly through every string label. `MCP-1018` byte reads resolve it:

- `0x00612b58`: `DATA/MISC.DAT`
- `0x00612b74`: `DATA/CHAR.DAT`
- `0x00612b90`: `DATA/TILE.DAT`
- `0x00612bac`: `DATA/MON.DAT`
- `0x00612bc8`: `DATA/EFX.DAT`
- `0x00612be4`: `DATA/MNM.DAT`
- `0x00612c00`: `DATA/FACEDEC`
- `0x00612c1c`: `DATA/EMOTION`
- `0x00612c38`: `DATA/HAIRDEC`
- `0x00612c54`: `DATA/NECK`
- `0x00612c68`: `DATA/BODY`
- `0x00612c7c`: `DATA/SWORD`
- `0x00612c94`: `DATA/SPEAR`
- `0x00612cac`: `DATA/FAN`
- `0x00612cc0`: `DATA/SHIELD`
- `0x00612cd8`: `DATA/TILE`
- `0x00612cec`: `DATA/TILEC`
- `0x00612d04`: `DATA/EFX`
- `0x00612d18`: `DATA/BOW`
- `0x00612d2c`: `DATA/HAIR`
- `0x00612d40`: `DATA/FACE`
- `0x00612d54`: `DATA/HELMET`
- `0x00612d6c`: `DATA/MANTLE`
- `0x00612d84`: `DATA/SHOES`
- `0x00612d9c`: `DATA/COAT`
- `0x00612db0`: `DATA/SND.DAT`
- `0x00612dcc`: `DATA/MUS000.DAT`
- `0x00612dec`: `DATA/BARAM.DAT`
- `0x00612e0c`: `DATA/BINT`
- `0x00612e20`: `DATA/WM.DAT`

This pool is legitimate Application startup/resource-loader data, but it still should not make the whole parent range Application-owned because the parent also contains PasswordError, RegistryConfig, FunctionObjects, shared literals, and BackGroundPane metadata.

## Current Documentation Defects

The target page has these source-quality defects:

1. It assigns the entire mixed `.rdata` interval to Application (`CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`).
2. It treats compiler-generated vtables/RTTI, shared literals, and unrelated class data as if they belong to a single Application source owner.
3. It lacks explicit no-code proof for why the parent formal C++ block must remain blank.
4. It does not identify the RegistryConfig vtable/RTTI island at `0x00612610-0x00612628`.
5. It does not identify the shared `L"\\"` path separator at `0x0061260c-0x00612610`.
6. It does not identify the FunctionObject0 RTTI pointer at `0x00612628-0x0061262c`.
7. It does not identify the PlainMemberFunctionObject0<Application> RTTI pointer at `0x00612e3c-0x00612e40`.
8. It does not identify the BackGroundPane RTTI/COL pointer at `0x00612f38-0x00612f3c`.
9. It does not separate Application-only startup literals from shared literals such as `File not found : %s`, `Software\KRU\NexusTK`, `runas`, and `patcher.exe`.
10. Generated coverage/index rows are stale and still imply a single reconstructable owner; they must not be manually edited.

## Required Parent Metadata

The implementation update for the target metadata is:

- `COMPLETION:88`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:NONE`
- `RECONSTRUCTABLE:FALSE`
- `EMITTER_UIDS:` blank
- keep `Nested:-4`
- keep formal `RECONSTRUCTION_CPP CODE` blank

Rationale for `88/92`: the live MCP evidence resolves the old ownership and split blockers, including RegistryConfig, FunctionObjects, shared literals, and the successor RTTI boundary. It should not be scored as complete/final because several gap children must be created during implementation and generated coverage remains stale until refreshed by the normal pipeline.

## Formal C++ And No-Code Disposition

The parent `RECONSTRUCTION_CPP CODE` block should remain blank. Exact no-code proof:

The range is a linker-contiguous `.rdata` interval, not a source-authored declaration. It crosses PasswordError vtable/descriptor data, Application vtable/startup literals, RegistryConfig RTTI/vtable data, FunctionObject0 and PlainMemberFunctionObject0 generated callback metadata, shared literals with FolderTreePane/FileError/StartupWindow/update-helper users, and the BackGroundPane successor RTTI pointer. Emitting a single C++ block here would invent an aggregate that is not present in the source. The source-bearing bodies belong in their owning functions/classes, and the compiler-generated vtables/RTTI cells are represented as blank-C++ data pages with exact slot evidence.

Existing child formal C++ dispositions:

- `0x006125a8-0x006125bc.PasswordErrorVtableData`: keep blank formal C++. It is compiler-generated vtable data for PasswordError, already routed to the Error hierarchy.
- `0x006125e4-0x0061260c.ApplicationVtableData`: keep blank formal C++. It is compiler-generated Application vtable data. The page should stop describing the following transition bytes as unresolved Application data once split children are added.
- `0x0061262c-0x00612640.FunctionObject0VtableData`: keep blank formal C++. It is compiler-generated FunctionObject0 vtable data from the FunctionObjects source family.
- `0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData`: keep blank formal C++. It is compiler-generated callback-template vtable data used by `Application::RequestExit`.

No exact formal source C++ is inserted for the parent or for any child data page in this range. Source-bearing function/class pages outside this aggregate are not part of this implementation. String and vtable pages here must document source-use ownership and remain blank formal C++.

## Finalized Exact Split Strategy

Use one exact half-open split. Do not substitute smaller literal pages, merge any of these rows, or attach `0x00612f38-0x00612f3c` to the successor range. Rows marked New require creation of the named by-memory page at the exact path shown; their UIDs are assigned by the normal documentation workflow during implementation.

| Status | Path | Range | Entity kind | Completion | Confidence | Canonical owner | Reconstructable | Emitters | Nested | Formal C++ disposition |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Existing, no edit | `by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md` | `0x006125a8-0x006125bc` | PasswordError vtable data | `88` | `91` | `0000A8` | `TRUE` | `0000A8` | `4` | Blank; compiler-generated vtable already documented. |
| New | `by-memory/0x006125bc-0x006125e0.PasswordErrorDescriptorStringData.md` | `0x006125bc-0x006125e0` | PasswordError UTF-16 descriptor literal | `86` | `90` | `0000A8` | `TRUE` | `0000A8` | `0` | Blank; descriptor source belongs with `PasswordErrorGetErrorDescriptor`, not a standalone data declaration. |
| New | `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` | `0x006125e0-0x006125e4` | Application RTTI/COL pointer | `86` | `91` | `0000HG` | `TRUE` | `0000HG` | `0` | Blank; compiler-generated RTTI/COL pointer from Application class emission. |
| Existing, edit summary/transition notes | `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md` | `0x006125e4-0x0061260c` | Application primary/secondary vtable data | `86` | `91` | `0000HG` | `TRUE` | `0000HG` | `8` | Blank; compiler-generated Application vtable. |
| New | `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md` | `0x0061260c-0x00612610` | Shared UTF-16 path separator literal `L"\\"` | `88` | `92` | `NONE` | `TRUE` | `0000HG,0000JG` | `0` | Blank; no single declaration, source-use emitters are Application and FolderTreePane. |
| New | `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md` | `0x00612610-0x00612614` | RegistryConfig RTTI/COL pointer | `86` | `91` | `0000BW` | `TRUE` | `0000BW` | `0` | Blank; compiler-generated RTTI/COL pointer from RegistryConfig class emission. |
| New | `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md` | `0x00612614-0x00612628` | RegistryConfig vtable data | `88` | `92` | `0000BW` | `TRUE` | `0000BW` | `0` | Blank; compiler-generated vtable with resolved scalar-deleting, shared support, save, and load slots. |
| New | `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md` | `0x00612628-0x0061262c` | FunctionObject0 RTTI/COL pointer | `86` | `91` | `0000JO` | `TRUE` | `0000JO` | `0` | Blank; compiler-generated RTTI/COL pointer from FunctionObjects declarations. |
| Existing, edit summary | `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` | `0x0061262c-0x00612640` | FunctionObject0 vtable data | `88` | `92` | `0000JO` | `TRUE` | `0000JO` | `0` | Blank; compiler-generated FunctionObject0 vtable. |
| New | `by-memory/0x00612640-0x00612980.ApplicationOsAndRuntimeStringData.md` | `0x00612640-0x00612980` | Application OS/version/runtime string pool with FileError shared literal | `87` | `91` | `NONE` | `TRUE` | `0000HG,0000J5` | `0` | Blank; literals are emitted by Application and Error/FileError source uses. |
| New | `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` | `0x00612980-0x00612b24` | Registry root/display-mode/startup string pool | `87` | `90` | `NONE` | `TRUE` | `0000HG,0000O5` | `0` | Blank; `Software\KRU\NexusTK` is shared by Application and StartupWindow source uses. |
| New | `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md` | `0x00612b24-0x00612e3c` | Application mutex and resource/DAT path string pool | `88` | `91` | `0000HG` | `TRUE` | `0000HG` | `0` | Blank; literals belong in Application initialization/resource-loader source use, not standalone raw data emission. |
| New | `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md` | `0x00612e3c-0x00612e40` | PlainMemberFunctionObject0<Application> RTTI/COL pointer | `86` | `91` | `0000JO` | `TRUE` | `0000JO` | `0` | Blank; compiler-generated callback-template RTTI/COL pointer. |
| Existing, edit summary | `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md` | `0x00612e40-0x00612e54` | PlainMemberFunctionObject0<Application> vtable data | `88` | `92` | `0000JO` | `TRUE` | `0000JO` | `0` | Blank; compiler-generated callback-template vtable used by Application callbacks. |
| New | `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | `0x00612e54-0x00612f38` | Version/license/localization/error/patcher string pool | `87` | `91` | `NONE` | `TRUE` | `0000HG,0000MH` | `0` | Blank; literals are source-use strings in Application and PatchPane/update helper code. |
| New | `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md` | `0x00612f38-0x00612f3c` | BackGroundPane RTTI/COL pointer | `86` | `91` | `0000HO` | `TRUE` | `0000HO` | `0` | Blank; compiler-generated RTTI/COL pointer immediately preceding the successor BackGroundPane vtable. |

## Child No-Code Proofs

- `PasswordErrorDescriptorStringData`: direct xref `0x00467400` returns the descriptor string; the string is a source literal attached to PasswordError/Error behavior and must not emit a synthetic raw data object.
- `ApplicationRttiLocatorPointer`, `RegistryConfigRttiLocatorPointer`, `FunctionObject0RttiLocatorPointer`, `PlainMemberFunctionObject0ApplicationRttiLocatorPointer`, and `BackGroundPaneRttiLocatorPointer`: each is a compiler-generated RTTI/COL pointer immediately adjacent to its class or callback vtable; blank formal C++ is the only source-faithful disposition.
- `RegistryConfigVtableData`: slot dwords resolve to `RegistryConfigScalarDeletingDestructor`, shared support slots, `SaveToRegistry`, and `LoadFromRegistry`; the vtable is generated from the class declaration and remains blank formal C++.
- `SharedWidePathSeparatorLiteral`: live xrefs prove Application and FolderTreePane consumers; no single source owner or central declaration exists.
- `ApplicationOsAndRuntimeStringData`: contains Application OS/version/runtime strings plus `File not found : %s` shared with FileError. It is a source-use string pool, not an aggregate declaration.
- `ApplicationRegistryDisplayStringData`: contains `Software\KRU\NexusTK` used by Application and StartupWindow plus display-mode text; blank formal C++ records source-use routing only.
- `ApplicationStartupResourceStringData`: contains mutex names and resource/DAT path literals used by Application initialization/resource loader; the owning source code is the function body, not a separate data declaration.
- `ApplicationPatchAndVersionStringData`: contains version/license/localization/error/patcher strings, including `runas` and `patcher.exe` used by both Application and PatchPane/update helper paths; no standalone declaration is reconstructable here.
- Existing `PasswordErrorVtableData`, `ApplicationVtableData`, `FunctionObject0VtableData`, and `PlainMemberFunctionObject0ApplicationVtableData` remain blank because they are compiler-generated vtable pages.

## Exact Target Doc Edit

Implement the parent target as a mixed `.rdata` index:

- Metadata becomes `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal `RECONSTRUCTION_CPP CODE`, and existing `Nested:-4`.
- Item Summary becomes: `Mixed read-only data index for PasswordError, Application, RegistryConfig, FunctionObjects, shared startup literals, and the BackGroundPane successor RTTI pointer; live IDA MCP resolves the exact child split and proves the parent is non-emitting.`
- Summary text must say the page is a non-emitting split/index page, not Application source.
- Add the finalized split table above, the xref matrix from this report, the UTF-16 resource decode list, and the parent no-code proof.
- State explicitly that generated coverage remains stale and must be refreshed by the normal pipeline, not edited manually.

## Exact Support-Doc Ledger

Report-only phase made no by-* edits and took no leases. The accepted implementation must use the following exact doc ledger.

| File | Disposition | Exact edit or no-edit reason |
| --- | --- | --- |
| `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md` | Edit | Apply the parent metadata, blank-C++ no-code proof, range map, MCP evidence, UTF-16 decode, and finalized child split. |
| `by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md` | No edit | Already has exact range, owner `0000A8`, descriptor boundary, parent linkage, blank formal C++ proof, and adequate item summary. |
| `by-memory/0x006125bc-0x006125e0.PasswordErrorDescriptorStringData.md` | Create | Use the metadata in the split table; summary: `PasswordError descriptor string data returned by PasswordErrorGetErrorDescriptor; actual start 0x006125bc with IDA label inside at 0x006125c0, source owned by Error/PasswordError and not Application.` |
| `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` | Create | Use the metadata in the split table; document dword `0x00641ff8` as Application RTTI/COL pointer and keep formal C++ blank. |
| `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md` | Edit | Set Item Summary to `Application primary and secondary vtable data; constructor/destructor/scalar-deleting refs verified, with successor transition split to shared path separator and RegistryConfig/FunctionObject0 metadata children.` Replace the open transition question with resolved links to `SharedWidePathSeparatorLiteral`, `RegistryConfigRttiLocatorPointer`, `RegistryConfigVtableData`, and `FunctionObject0RttiLocatorPointer`. |
| `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md` | Create | Use the metadata in the split table; document Application and FolderTreePane xrefs and blank formal C++ source-use proof. |
| `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md` | Create | Use the metadata in the split table; document dword `0x00642100` as RegistryConfig RTTI/COL pointer and keep formal C++ blank. |
| `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md` | Create | Use the metadata in the split table; document slots `0x00467340`, `0x004f4b10`, `0x0041b6c0`, `0x00491b30`, and `0x004926a0`; keep formal C++ blank. |
| `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md` | Create | Use the metadata in the split table; document dword `0x006421e0` as FunctionObject0 RTTI/COL pointer and keep formal C++ blank. |
| `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` | Edit | Set Item Summary to `FunctionObject0 zero-argument callback vtable; destructor-variant refs and purecall slots verified, compiler-generated from FunctionObjects declarations.` Add a related-memory link to the new RTTI child. |
| `by-memory/0x00612640-0x00612980.ApplicationOsAndRuntimeStringData.md` | Create | Use the metadata in the split table; list OS/runtime strings and the `File not found : %s` FileError shared exception; keep formal C++ blank. |
| `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` | Create | Use the metadata in the split table; list `Software\KRU\NexusTK`, display-mode text, Application xrefs, and StartupWindow xref; keep formal C++ blank. |
| `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md` | Create | Use the metadata in the split table; include mutex names and the decoded DAT/resource path list; keep formal C++ blank. |
| `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md` | Create | Use the metadata in the split table; document dword `0x0064222c` as PlainMemberFunctionObject0<Application> RTTI/COL pointer and keep formal C++ blank. |
| `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md` | Edit | Set Item Summary to `PlainMemberFunctionObject0<Application> callback vtable used by Application::RequestExit; slot targets map to FunctionObject0 destructor, shared support, invoke, and object-size helpers, compiler-generated from FunctionObjects template declarations.` Add a related-memory link to the new RTTI child. |
| `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | Create | Use the metadata in the split table; list `.exe`, license, `%s`, `Error #%03d`, `_ENG.STR`, patch info/script, `Continuing patch...`, `runas`, and `patcher.exe`; keep formal C++ blank. |
| `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md` | Create | Use the metadata in the split table; document dword `0x0064227c` as BackGroundPane RTTI/COL pointer immediately before successor `0x00612f3c`; keep formal C++ blank. |
| `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md` | Edit | Add a boundary note that predecessor `0x00612f38-0x00612f3c` is the exact BackGroundPane RTTI locator child outside this half-open range; do not change metadata. |
| `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md` | Edit | Add 00024T as a mixed non-emitting index with the finalized child split; do not edit generated coverage. |
| `by-class/PasswordError.md` | Edit | Add the descriptor child `0x006125bc-0x006125e0.PasswordErrorDescriptorStringData` to status/cross refs and note actual start `0x006125bc` with IDA label inside at `0x006125c0`; no metadata change. |
| `by-file/Error.md` | Edit | Add PasswordError descriptor string child and xref `0x00467400` to Error/PasswordError evidence; no metadata change. |
| `by-class/Application.md` | Edit | Add that 00024T is a no-owner index; link Application RTTI/vtable, Application-owned resource string child, and Application source-use string children; explicitly exclude PasswordError, RegistryConfig, FunctionObjects, FolderTreePane/FileError/StartupWindow shared literals, and BackGroundPane metadata from Application ownership. |
| `by-file/Application.md` | Edit | Add the same 00024T split routing to the file evidence/cross refs, distinguishing Application-owned children from shared source-use children; no metadata change. |
| `by-file/FolderTreePane.md` | Edit | Add `0x0061260c-0x00612610.SharedWidePathSeparatorLiteral` as the shared `L"\\"` literal used by FolderTreePane path helpers `0x004b1d50` and `0x004b3090`; no metadata change. |
| `by-class/FolderTreePane.md` | No edit | File-level source route carries the shared literal claim; no class metadata or method C++ changes are required. |
| `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md` | No edit | The literal source-use child and `by-file/FolderTreePane.md` support note are sufficient; no function reconstruction changes in the FolderTreePane core range. |
| `by-class/RegistryConfig.md` | Edit | Add exact RegistryConfig RTTI and vtable children for `0x00612610-0x00612628` near status/evidence notes; no metadata change. |
| `by-file/RegistryConfig.md` | Edit | Add exact RegistryConfig RTTI/vtable data references to Proposed Contents/Cross-References; no metadata change. |
| `by-file/Config.md` | No edit | The island is RegistryConfig-specific and already routed through RegistryConfig docs, not base Config ownership. |
| `by-file/FunctionObjects.md` | Edit | Add FunctionObject0 RTTI child, existing FunctionObject0 vtable child, PlainMemberFunctionObject0<Application> RTTI child, and existing callback vtable child to Proposed Contents/Cross-References; no metadata change. |
| `by-class/FunctionObject0.md` | Edit | Add new FunctionObject0 RTTI child and existing vtable child to related memory/cross refs; no metadata change. |
| `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` | Edit | Add new RTTI child and existing vtable child to related memory/cross refs; no metadata change. |
| `by-file/StartupWindow.md` | Edit | Add `ApplicationRegistryDisplayStringData` as a shared source-use string child for `Software\KRU\NexusTK`; no metadata change. |
| `by-file/PatchPane.md` | Edit | Add `ApplicationPatchAndVersionStringData` as a shared source-use string child for `runas` and `patcher.exe` xrefs from update/patch helper code; no metadata change. |
| `by-file/BackPane.md` | Edit | Add `BackGroundPaneRttiLocatorPointer` and note it is the predecessor dword before the 00024U BackGroundPane vtable island; no metadata change. |
| `by-class/BackGroundPane.md` | Edit | Add the new RTTI locator pointer child to data/vtable notes and cross refs; no metadata change. |
| `by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md` | No edit | The predecessor `0x006125a4-0x006125a8` PasswordError RTTI page remains outside 00024T and is already represented separately. |
| `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md` | No edit | It was only a comparison pattern for non-emitting read-only data; no claim in 00024T depends on editing it. |
| `by-file/PasswordGuard.md` | No edit | It is only a consumer of PasswordError throwing paths; descriptor and vtable data route through Error/PasswordError docs. |
| `by-file/WinMain.md` | No edit | The live xrefs for `runas` and `patcher.exe` route through Application and PatchPane/update helper code, not WinMain. |
| `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, validator state, tool state, IDA DB files | Forbidden | Do not edit manually. Generated refresh is a normal pipeline follow-up after accepted by-* edits. |

## Scoped Validator Plan For Accepted Implementation

Run the file validator after the edit batch for every changed or created by-* file listed as Edit or Create above:

> Executable block R001 was removed from this report and preserved verbatim in [00024T-ApplicationStartupReadOnlyData-source-quality-removed.md](00024T-ApplicationStartupReadOnlyData-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Required validator file set:

- `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md`
- `by-memory/0x006125bc-0x006125e0.PasswordErrorDescriptorStringData.md`
- `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md`
- `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md`
- `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md`
- `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md`
- `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md`
- `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md`
- `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md`
- `by-memory/0x00612640-0x00612980.ApplicationOsAndRuntimeStringData.md`
- `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md`
- `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md`
- `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md`
- `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md`
- `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md`
- `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md`
- `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md`
- `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md`
- `by-class/PasswordError.md`
- `by-file/Error.md`
- `by-class/Application.md`
- `by-file/Application.md`
- `by-file/FolderTreePane.md`
- `by-class/RegistryConfig.md`
- `by-file/RegistryConfig.md`
- `by-file/FunctionObjects.md`
- `by-class/FunctionObject0.md`
- `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md`
- `by-file/StartupWindow.md`
- `by-file/PatchPane.md`
- `by-file/BackPane.md`
- `by-class/BackGroundPane.md`

Do not manually edit `by-memory/-coverage-report.md`, `auto-generated/-ag-memory-coverage.md`, validator state, tool state, or IDA DB files.

## Rejected Alternatives

- Reject keeping `CANONICAL_OWNER:0000HG`. PasswordError, RegistryConfig, FunctionObjects, shared FolderTreePane/FileError/StartupWindow/update-helper literals, and BackGroundPane metadata are inside the same half-open range.
- Reject keeping `RECONSTRUCTABLE:TRUE` on the parent. There is no source aggregate declaration corresponding to this exact linker interval.
- Reject inserting a parent C++ declaration. It would synthesize a data object not present in source.
- Reject treating `0x00612610-0x00612628` as Application transition padding. It is RegistryConfig RTTI plus vtable cells with resolved slot functions.
- Reject treating `0x00612f38` as Application tail data. It is the BackGroundPane RTTI/COL pointer immediately before the successor vtable.
- Reject treating `0x0061260c` and `0x006126f4` as Application-only literals. Live xrefs prove FolderTreePane and FileError users.
- Reject treating `runas` and `patcher.exe` as Application-only literals. Live xrefs include update/patch helper functions outside Application.

## Generated And Coverage Refresh State

Generated/manual coverage was not edited. Current generated coverage is stale:

- `by-memory/-coverage-report.md` still reports UID 00024T as reconstructable and shows only a stale child subset.
- `auto-generated/-ag-memory-coverage.md` still reflects the older Application-emitting interpretation.

Expected implementation state after accepted edits: generated refresh required by the normal project pipeline. This report does not request or perform manual generated-file repair.

Implementation refresh state: scoped validators for this implementation all reported `generated_refresh: deferred`. Manual generated files, manual coverage reports, validator/tool state, and IDA DB files were not manually edited.

## Implementation Tracking Checklist

- [x] Lease only the immediate edit batch, edit the exact files marked Edit/Create in the support-doc ledger, run the scoped validators, then release all leases immediately after the validator batch.
  - Proof: B004 leased the existing edit-file batch before by-* edits; new child pages were created as immediate implementation children. After validators, `python .\tools\leaser\leaser.py B004 unlease` returned `B004: No active leases`, and `tools/leaser/Agents/current_leases.md` showed no active B004 leases.
- [x] Update `by-memory/0x006125a8-0x00612f3c.ApplicationStartupReadOnlyData.md` metadata to `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++, and `Nested:-4`.
  - Proof: validator command `000000003491` at `2026-06-26T20:56:44-04:00`, exit `0`, ok `1/1`.
- [x] Set the target Item Summary to the exact mixed read-only data index wording from this report.
- [x] Add the MCP evidence list including `MCP-1001`, `MCP-1003`, `MCP-1004`, `MCP-1008` through `MCP-1022`, and revision availability checks `MCP-REV-2001` through `MCP-REV-2005`.
- [x] Add the parent no-code proof explaining that the linker-contiguous range crosses PasswordError, Application, RegistryConfig, FunctionObjects, shared literals, and BackGroundPane RTTI.
- [x] Add the finalized exact split table to the target with the sixteen child rows and no alternate grouping language.
- [x] Create `by-memory/0x006125bc-0x006125e0.PasswordErrorDescriptorStringData.md` with `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000A8`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000A8`, `Nested:0`, blank formal C++, descriptor-start proof, and xref `0x00467400`.
  - Proof: validator assigned UID `00047X`; command `000000003478` at `2026-06-26T20:55:19-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` with `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, `Nested:0`, blank formal C++, and dword `0x00641ff8` proof.
  - Proof: validator assigned UID `00047Y`; command `000000003479` at `2026-06-26T20:55:50-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md` with the exact Item Summary and resolved transition links named in the support-doc ledger; leave metadata and formal C++ unchanged.
  - Proof: validator command `000000003492` at `2026-06-26T20:56:51-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md` with `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG,0000JG`, `Nested:0`, blank formal C++, Application xrefs, and FolderTreePane xrefs.
  - Proof: validator assigned UID `00047Z`; command `000000003480` at `2026-06-26T20:55:57-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612610-0x00612614.RegistryConfigRttiLocatorPointer.md` with `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, `Nested:0`, blank formal C++, and dword `0x00642100` proof.
  - Proof: validator assigned UID `000480`; command `000000003481` at `2026-06-26T20:55:58-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612614-0x00612628.RegistryConfigVtableData.md` with `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000BW`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000BW`, `Nested:0`, blank formal C++, and slot proofs `0x00467340`, `0x004f4b10`, `0x0041b6c0`, `0x00491b30`, `0x004926a0`.
  - Proof: validator assigned UID `000481`; command `000000003482` at `2026-06-26T20:56:00-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612628-0x0061262c.FunctionObject0RttiLocatorPointer.md` with `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JO`, `Nested:0`, blank formal C++, and dword `0x006421e0` proof.
  - Proof: validator assigned UID `000482`; command `000000003483` at `2026-06-26T20:56:01-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-memory/0x0061262c-0x00612640.FunctionObject0VtableData.md` with the exact Item Summary and related-memory RTTI link from the support-doc ledger; leave metadata and formal C++ unchanged.
  - Proof: validator command `000000003493` at `2026-06-26T20:56:54-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612640-0x00612980.ApplicationOsAndRuntimeStringData.md` with `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG,0000J5`, `Nested:0`, blank formal C++, OS/runtime literals, and FileError shared-literal proof.
  - Proof: validator assigned UID `000483`; command `000000003484` at `2026-06-26T20:56:03-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` with `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG,0000O5`, `Nested:0`, blank formal C++, `Software\KRU\NexusTK`, display-mode text, and StartupWindow shared-use proof.
  - Proof: validator assigned UID `000484`; command `000000003485` at `2026-06-26T20:56:05-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md` with `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HG`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG`, `Nested:0`, blank formal C++, mutex names, and the decoded resource/DAT path list.
  - Proof: validator assigned UID `000485`; command `000000003486` at `2026-06-26T20:56:06-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612e3c-0x00612e40.PlainMemberFunctionObject0ApplicationRttiLocatorPointer.md` with `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000JO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JO`, `Nested:0`, blank formal C++, and dword `0x0064222c` proof.
  - Proof: validator assigned UID `000486`; command `000000003487` at `2026-06-26T20:56:08-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-memory/0x00612e40-0x00612e54.PlainMemberFunctionObject0ApplicationVtableData.md` with the exact Item Summary and related-memory RTTI link from the support-doc ledger; leave metadata and formal C++ unchanged.
  - Proof: validator command `000000003494` at `2026-06-26T20:56:56-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` with `COMPLETION:87`, `CONFIDENCE:91`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HG,0000MH`, `Nested:0`, blank formal C++, version/license/localization/error/patcher strings, and Application/PatchPane shared-use proof.
  - Proof: validator assigned UID `000487`; command `000000003488` at `2026-06-26T20:56:10-04:00`, exit `0`, ok `1/1`.
- [x] Create `by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md` with `COMPLETION:86`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000HO`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000HO`, `Nested:0`, blank formal C++, and dword `0x0064227c` proof.
  - Proof: validator assigned UID `000488`; command `000000003489` at `2026-06-26T20:56:11-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-memory/0x00612f3c-0x006131b4.BackGroundBalloonBlackHoleReadOnlyData.md` with the predecessor boundary note; leave metadata unchanged.
  - Proof: validator command `000000003495` at `2026-06-26T20:56:57-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-memory/0x0060d670-0x0066d000.ReadOnlyDataSection.md` with the 00024T mixed-index split inventory; leave generated coverage alone.
  - Proof: validator command `000000003496` at `2026-06-26T20:56:59-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-class/PasswordError.md` and `by-file/Error.md` with exact descriptor child routing and xref proof; leave metadata unchanged.
  - Proof: validator commands `000000003497` at `2026-06-26T20:57:01-04:00` and `000000003498` at `2026-06-26T20:57:03-04:00`, exits `0`, ok `1/1` each.
- [x] Edit `by-class/Application.md` and `by-file/Application.md` with the 00024T no-owner split and Application-owned/shared-use child routing; leave metadata unchanged.
  - Proof: validator commands `000000003499` at `2026-06-26T20:57:04-04:00` and `000000003500` at `2026-06-26T20:57:07-04:00`, exits `0`, ok `1/1` each.
- [x] Edit `by-file/FolderTreePane.md` with the shared `L"\\"` literal child and helper xrefs `0x004b1d50` and `0x004b3090`; leave metadata unchanged.
  - Proof: validator command `000000003501` at `2026-06-26T20:57:19-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-class/RegistryConfig.md` and `by-file/RegistryConfig.md` with exact RegistryConfig RTTI/vtable children; leave metadata unchanged.
  - Proof: validator commands `000000003502` at `2026-06-26T20:57:21-04:00` and `000000003503` at `2026-06-26T20:57:23-04:00`, exits `0`, ok `1/1` each.
- [x] Edit `by-file/FunctionObjects.md`, `by-class/FunctionObject0.md`, and `by-class/PlainMemberFunctionObject0_void____thiscall_Application_____void____class_Application_.md` with exact RTTI/vtable children; leave metadata unchanged.
  - Proof: validator commands `000000003504` at `2026-06-26T20:57:24-04:00`, `000000003505` at `2026-06-26T20:57:26-04:00`, and `000000003506` at `2026-06-26T20:57:28-04:00`, exits `0`, ok `1/1` each.
- [x] Edit `by-file/StartupWindow.md` with the shared `Software\KRU\NexusTK` child; leave metadata unchanged.
  - Proof: validator command `000000003507` at `2026-06-26T20:57:30-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-file/PatchPane.md` with the shared `runas` and `patcher.exe` child; leave metadata unchanged.
  - Proof: validator command `000000003508` at `2026-06-26T20:57:31-04:00`, exit `0`, ok `1/1`.
- [x] Edit `by-file/BackPane.md` and `by-class/BackGroundPane.md` with the BackGroundPane RTTI child; leave metadata unchanged.
  - Proof: validator commands `000000003510` at `2026-06-26T20:57:43-04:00` and `000000003512` at `2026-06-26T20:57:46-04:00`, exits `0`, ok `1/1` each.
- [x] Do not edit `by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md`, `by-class/FolderTreePane.md`, `by-memory/0x004b1b90-0x004b32c9.FolderTreePaneCore.md`, `by-file/Config.md`, `by-memory/0x00610ed8-0x006125a8.AboveFrameAndLocaleReadOnlyData.md`, `by-memory/0x006168d0-0x00617a38.ConfigChannelReadOnlyData.md`, `by-file/PasswordGuard.md`, or `by-file/WinMain.md`; the support-doc ledger gives exact no-edit reasons.
  - Proof: no manual edits were made to these no-edit/forbidden rows during this implementation pass.
- [x] Run the scoped file validator command for every path in the `Scoped Validator Plan For Accepted Implementation` file set and record command IDs, timestamps, exit codes, and ok counts.
  - Proof: 32 scoped validator commands completed with exit `0`, ok `1/1` each, all with `generated_refresh: deferred`. Command IDs: `000000003478`, `000000003479`, `000000003480`, `000000003481`, `000000003482`, `000000003483`, `000000003484`, `000000003485`, `000000003486`, `000000003487`, `000000003488`, `000000003489`, `000000003491`, `000000003492`, `000000003493`, `000000003494`, `000000003495`, `000000003496`, `000000003497`, `000000003498`, `000000003499`, `000000003500`, `000000003501`, `000000003502`, `000000003503`, `000000003504`, `000000003505`, `000000003506`, `000000003507`, `000000003508`, `000000003510`, `000000003512`.
- [x] Do not manually edit generated files, project-level generated files, manual coverage reports, validator/tool state, or IDA DB files.
  - Proof: manual edits were limited to accepted by-* docs and this agent report; validator-managed generated refresh state remained `deferred`.
- [x] Record leases used and released during implementation.
  - Proof: B004 implementation lease batch was used for immediate existing by-* edit files; final release check `python .\tools\leaser\leaser.py B004 unlease` returned `B004: No active leases`, and `current_leases.md` contained only unrelated B002 leases at final check.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00024T-ApplicationStartupReadOnlyData-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/00024T-ApplicationStartupReadOnlyData-source-quality.md","timestamp":"2026-06-26T22:10:39","uid":"00024T"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00024T-ApplicationStartupReadOnlyData-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00024T-ApplicationStartupReadOnlyData-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00024T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
