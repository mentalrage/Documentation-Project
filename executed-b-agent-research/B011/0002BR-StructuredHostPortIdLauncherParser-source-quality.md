** TARGET-REPORT-UID:0002BR **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B011 Report - [UID:0002BR] StructuredHostPortIdLauncherParser Source Quality

## Assignment

- Agent: B011
- Assignment: `B011-report-0002BR-StructuredHostPortIdLauncherParser-source-quality-20260627`
- Target: [UID:0002BR] `by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md`
- Current target metadata before this report:
  - `COMPLETION:86`
  - `CONFIDENCE:90`
  - `CANONICAL_OWNER:0000N4`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000N4`
  - Formal C++: blank
- Report-only status: this report does not edit by-* files, generated reports, or coverage files. It is ready for supervisor validation and an implementation callback.

## MCP Session Verification

- Current live IDA MCP session verified by B011 before evidence collection: `398b87c1`.
- `idb_list` result used:
  - Session id: `398b87c1`
  - Input file: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - Filename: `NexusTK.exe.i64`
  - Backend: worker
  - PID/worker PID: `2704`
  - Active: true
  - Auto-analysis: not currently analyzing
- `server_health` on session `398b87c1` returned healthy:
  - Status: `ok`
  - Module: `NexusTK.exe`
  - Input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - Imagebase: `0x400000`
  - Auto-analysis ready: true
  - Hex-Rays ready: true
  - Strings cache ready: true
- Old session `80de0a67` was not used. All MCP evidence below is from session `398b87c1`.

## Target Shape And Boundaries

- `lookup_funcs` confirms `0x004918e0` is a modeled function:
  - Name: `sub_4918E0`
  - Address: `0x004918e0`
  - Size: `0x248`
  - End boundary: `0x00491b28`
- Boundary checks:
  - `0x004918dc` is not a modeled function and the bytes before `0x004918e0` include `int3` padding before the target prologue.
  - `0x00491b27` is inside `sub_4918E0`.
  - `0x00491b28` is not a modeled function.
  - `0x00491b30` is the next modeled function, `sub_491B30`, size `0xb65`.
- `get_bytes` confirms the target ends with the normal epilogue before `int3` padding:
  - `59 5f 5e 5b 8b e5 5d c3`
  - followed by `cc` padding before `0x00491b30`.
- SEH cleanup chunk is outside the contiguous body but belongs to this function:
  - Cleanup and handler code at `0x005fcdc2`, `0x005fcdca`, `0x005fcdd2`, `0x005fcdda`, and `0x005fcde2`.
  - `0x005fcde2` is `SEH_4918E0`, calls the security-cookie check and `___CxxFrameHandler3`.

## Positive Evidence

- Decompilation of `0x004918e0` succeeds in session `398b87c1` and reconstructs a structured command-line parser.
- The target calls `GetCommandLineW`, wraps the returned wide string in the project StringBase/SimpleUString machinery, searches for three markers, extracts values, resolves the host name, writes startup connection state into the config object, and releases all temporary strings.
- The three required markers are:
  - `/host:`
  - `/portno:`
  - `/id:`
- Raw literal bytes at `0x00617994` show the actual wide-string sequence:
  - Wide `/host:` begins at `0x00617994`.
  - Wide `/portno:` begins at `0x006179a4`.
  - Wide `/id:` begins at `0x006179b8`.
  - Host-lookup failure text begins at `0x006179c4`.
- IDA's string typing around these literals is partly misaligned. Raw bytes, not the stale string names, should drive the documentation update.
- `xrefs_to` confirms this target references the marker and fatal text data:
  - `0x00617994` referenced at `0x00491947`.
  - `0x006179a4` referenced at `0x004919a8`.
  - `0x006179b8` referenced at `0x00491a14`.
  - `0x006179c4` referenced at `0x00491abc`.
- The delimiter set used by the parser is `off_66D474`, shown by disassembly as `"/ \t"`.
- The id value only is trimmed with the trim-set pointer at `off_67027C`.
- `callees` for `0x004918e0` confirms the expected helper set:
  - `GetCommandLineW`
  - `sub_582560`
  - `sub_5830C0`
  - `sub_583450`
  - `sub_5829A0`
  - `sub_584680`
  - `sub_465CB0`
  - `sub_5847A0`
  - `sub_584D00`
  - `sub_583E70`
  - `sub_583F70`
  - `sub_584540`
  - `sub_575580`
  - `sub_582670`
  - `sub_582C60`
  - `sub_582B70`
- `analyze_function 0x00575580` confirms the host resolver behavior:
  - Converts the wide host string to an ANSI buffer with `WideCharToMultiByte`.
  - Range-checks the converted length against a 100-byte buffer.
  - Calls `gethostbyname`.
  - Copies four bytes from the first address-list entry to the caller-provided output with `sub_516220`.
  - Returns `1` on success and `0` on failure.
  - The only xref/caller is this parser at `0x00491ab0`.
- Support doc [UID:0003YL] already gives the source-facing resolver name `ResolveHostAddressFromWideName`.
- `analyze_function 0x00465cb0` confirms the fatal helper:
  - Gets the application/window handle.
  - Calls `MessageBoxW`.
  - Calls `PostQuitMessage(0)`.
  - Calls `_loaddll(0)`.
  - Calls `__debugbreak()`.
  - It is a noreturn fatal dialog/break helper.
- Support doc [UID:0002VI] already gives the source-facing fatal helper name `FatalError`.

## Negative Evidence And Attempted Resolution

- Direct caller/dispatcher route:
  - `xrefs_to 0x004918e0` returns zero xrefs.
  - `xrefs_to 0x00491b28` returns zero xrefs.
  - `find_bytes` found no direct little-endian VA/RVA/raw pointer hits for:
    - `e0 18 49 00`
    - `e0 18 09 00`
    - `28 1b 49 00`
    - `28 1b 09 00`
  - This means the direct dispatch route is still not recovered through simple code/data/immediate/pointer evidence.
  - This does not make the target non-reconstructable because the function body, parent island, helper roles, field writes, literals, and emitted source placement are now strongly supported.
- Original source symbols:
  - No original symbol names were recovered for this function or its local temporaries.
  - This is resolved through evidence-based source-facing names, matching the surrounding RegistryConfig command-line parser naming pattern.
- IDA literal typing:
  - Existing support data around `0x00617994` has stale/misaligned names for parts of the marker sequence.
  - Raw bytes resolve the marker identities. The support literal page should be corrected during implementation.
- Exact final class-layout names:
  - `+0x2915b4`, `+0x2916c4`, `+0x2916ca`, and `+0x28de28` already have strong sibling-parser support.
  - `+0x2918f0` needs a support-doc update because this target writes the trimmed `/id:` string there with StringBase assignment semantics.
  - Best current source-facing name for this target is `m_startupLauncherId`.
  - Broader `Config` docs should preserve any older block-list/music-control evidence but stop treating `+0x2918f0` as exclusively that role.

## Behavioral Reconstruction

The target is a RegistryConfig-owned command-line parser for a structured launcher format. It expects a command line containing `/host:`, `/portno:`, and `/id:` tokens.

The function:

- Reads the process command line with `GetCommandLineW`.
- Initializes a StringBase/SimpleUString-style command-line object from the raw wide string.
- Normalizes/detaches the string through StringBase writable/capacity helpers before searching.
- Searches for `/host:` from offset zero with a marker length of six characters.
- If `/host:` is missing, calls the generic fatal helper.
- Finds the next delimiter from the host marker region using the delimiter set `"/ \t"`.
- Extracts the host value into a temporary wide string.
- Searches for `/portno:` from offset zero with a marker length of eight characters.
- If `/portno:` is missing, calls the generic fatal helper.
- Finds the next delimiter from the port marker region and extracts the port text into a temporary wide string.
- Searches for `/id:` from offset zero with a marker length of four characters.
- If `/id:` is missing, calls the generic fatal helper.
- Finds the next delimiter from the id marker region and extracts the id text into a temporary wide string.
- Trims the id text on the left and right with the wide whitespace trim set.
- Resolves the host name through `ResolveHostAddressFromWideName`.
- If host resolution fails, calls `FatalError` with the host-lookup failure text at `0x006179c4`.
- Stores the resolved four-byte host address at `this + 0x2915b4`.
- Converts the port text with the StringBase numeric conversion helper and stores it at `this + 0x2916c4`.
- Sets the startup-ready flag at `this + 0x2916ca` to `1`.
- Sets the startup connection mode at `this + 0x28de28` to `5`.
- Assigns the trimmed id string to the StringBase-style member at `this + 0x2918f0`.
- Releases the id, port, host, and command-line temporary string objects through the observed StringBase destructor path.

## Source Placement And Ownership

- Keep `CANONICAL_OWNER:0000N4`.
- Keep `EMITTER_UIDS:0000N4`.
- Keep `RECONSTRUCTABLE:TRUE`.
- This should remain RegistryConfig-owned source, not PacketBuffer, Application, StringBase, or a generated dispatch artifact.
- The most accurate current source placement is a file-static helper in the RegistryConfig command-line parser cluster.
- Recommended source-facing function name:
  - `ParseStructuredHostPortIdLauncher(RegistryConfig *config)`
- Reasoning:
  - The sibling parser cluster in `by-file/RegistryConfig.md`, `by-class/RegistryConfig.md`, and `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md` uses source-facing helper names such as `ParseLauncherHostPortPayload`, `ParseMihosoftLauncher`, `ParseLgInternetSessionLauncher`, and `ParseNetsgoStartupAuthentication`.
  - This target is structurally another launcher parser, but with `/host:`, `/portno:`, and `/id:` tokens.
  - No current evidence proves it was a `RegistryConfig::` method. File-static helper placement is safer and consistent with sibling parser evidence.

## Field And Helper Name Decisions

- `config->m_startupAddress`
  - Offset: `+0x2915b4`
  - Evidence: `sub_575580(host, this + 2692532)`; `2692532 == 0x2915b4`, verified with `tools/int_convert.py`.
  - Four-byte host address output from `ResolveHostAddressFromWideName`.
- `config->m_startupPort`
  - Offset: `+0x2916c4`
  - Evidence: `*(DWORD *)(this + 2692804) = sub_582670(&portText)`; `2692804 == 0x2916c4`, verified with `tools/int_convert.py`.
  - Same offset is used by sibling startup host/port parsers.
- `config->m_startupReady`
  - Offset: `+0x2916ca`
  - Evidence: `*(WORD *)(this + 2692810) = 1`; `2692810 == 0x2916ca`, verified with `tools/int_convert.py`.
- `config->m_startupConnectionMode`
  - Offset: `+0x28de28`
  - Evidence: `*(BYTE *)(this + 2678312) = 5`; `2678312 == 0x28de28`, verified with `tools/int_convert.py`.
  - Existing Config/global docs identify this as a startup/terminal connection mode byte.
- `config->m_startupLauncherId`
  - Offset: `+0x2918f0`
  - Evidence: `sub_582C60((void **)(this + 2693360), &idText)`; `2693360 == 0x2918f0`, verified with `tools/int_convert.py`.
  - This is a StringBase-style assignment of the trimmed `/id:` token.
- `FatalError`
  - Evidence: support doc [UID:0002VI] and current MCP `analyze_function 0x00465cb0`.
- `ResolveHostAddressFromWideName`
  - Evidence: support doc [UID:0003YL] and current MCP `analyze_function 0x00575580`.
- `kCommandLineTokenDelimiters`
  - Evidence: `off_66D474`, disassembly comment `"/ \t"`.
  - Name is inferred, human source-facing, and should not remain as `off_66D474`.
- `kWideWhitespace`
  - Evidence: trim calls use `off_67027C`; target-specific role is whitespace trimming for `/id:`.
  - Name is inferred, human source-facing, and should not remain as `off_67027C`.

## Recommended Metadata Change

After implementation, update the target metadata to:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000N4`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000N4`

Reason not lower:

- Current MCP session `398b87c1` confirms the function boundary, SEH cleanup chunk, marker literals, helper calls, field writes, host resolver semantics, fatal path semantics, and source placement in the RegistryConfig parser island.
- The remaining unresolved dispatcher route does not prevent correct first-draft source reconstruction because the parser body and owner/emitter placement are strong.
- Source-facing names are now resolved enough for human-readable draft C++ instead of raw `sub_`, `off_`, or offset labels.

Reason not higher:

- The direct caller/dispatcher route is still not recovered.
- Exact original source spellings for helper constants and member fields remain inferred rather than symbol-proven.
- `+0x2918f0` needs associated Config documentation updates to reconcile this target's StringBase id assignment with older support-doc descriptions.
- The host-failure text role is clear, but the exact original Korean/source constant spelling is not recovered.

## Required Implementation Checklist

When supervisor validates this report and sends the implementation callback, B011 should apply the following updates. No `-coverage-report.md` files should be edited by B011.

- [x] Update target [UID:0002BR] `by-memory/0x004918e0-0x00491b28.StructuredHostPortIdLauncherParser.md`.
  - [x] Change metadata to `COMPLETION:90` and `CONFIDENCE:92`.
  - [x] Keep owner/emitter/reconstructable metadata unchanged.
  - [x] Add current MCP session `398b87c1` evidence.
  - [x] Document the exact parser behavior, field writes, helper roles, SEH cleanup chunk, and negative caller-route evidence.
  - [x] Add the formal C++ block below.
  - Proof: `rg` confirmed `COMPLETION:90`, `CONFIDENCE:92`, MCP session `398b87c1`, and `ParseStructuredHostPortIdLauncher(RegistryConfig *config)` in the target; validator command `000000004389` at `2026-06-27T13:23:37-04:00` returned `ok: 1` with `generated_refresh: completed`.
- [x] Update parent aggregate `by-memory/0x0048f400-0x00491b28.RegistryCommandLineParsers.md`.
  - [x] Update the [UID:0002BR] child row with the first-draft helper name, marker behavior, field writes, and no-direct-route caveat.
  - [x] Add `+0x2918f0` as the structured launcher id storage written by this target.
  - Proof: `rg` confirmed the child row, `/host:` / `/portno:` / `/id:` behavior, no-direct-route caveat, and `+0x2918f0` startup launcher id wording; validator command `000000004399` at `2026-06-27T13:28:04-04:00` returned `ok: 1`.
- [x] Update `by-file/RegistryConfig.md`.
  - [x] Add [UID:0002BR] to the command-line/session parser helper inventory with `ParseStructuredHostPortIdLauncher(RegistryConfig *config)`.
  - [x] Record the `/host:`, `/portno:`, `/id:` extraction, id trimming, host resolution, fatal paths, and startup field writes.
  - Proof: `rg` confirmed the helper inventory entry, extraction behavior, id trim, `ResolveHostAddressFromWideName`, fatal paths, and startup field writes including `+0x2918f0`; validator command `000000004400` at `2026-06-27T13:28:11-04:00` returned `ok: 1` with pre-existing `0003FW` missing-reference warnings only.
- [x] Update `by-class/RegistryConfig.md`.
  - [x] Add the same source-facing helper and field-use summary for [UID:0002BR].
  - Proof: `rg` confirmed the helper inventory entry, source-facing summary, startup field rows, `+0x2918f0`, cross-reference, and change-log entry; validator command `000000004386` at `2026-06-27T13:22:41-04:00` returned `ok: 1` with pre-existing `0003FW` missing-reference warnings only.
- [x] Update `by-memory/0x006178c8-0x006179ec.RegistryConfigAdapterHelperStringData.md`.
  - [x] Correct/add literal inventory rows for `0x00617994` wide `/host:`, `0x006179a4` wide `/portno:`, `0x006179b8` wide `/id:`, and `0x006179c4` host lookup failure text.
  - [x] Note that raw bytes resolve the stale/misaligned IDA string typing.
  - Proof: `rg` confirmed the four corrected literal rows and stale/misaligned IDA-string note; validator command `000000004345` at `2026-06-27T13:13:52-04:00` returned `ok: 1`.
- [x] Update `by-memory/0x0067a7c8-0x0067a7cc.g_pConfig.md`.
  - [x] Add [UID:0002BR] to the evidence for `+0x2915b4`, `+0x2916c4`, `+0x2916ca`, and `+0x28de28`.
  - [x] Add or refine `+0x2918f0` as StringBase-style structured launcher id storage.
  - Proof: `rg` confirmed [UID:0002BR] evidence on the startup address, port, ready, and mode fields plus the `+0x2918f0` StringBase launcher-id row; validator command `000000004387` at `2026-06-27T13:22:52-04:00` returned `ok: 1` with pre-existing `0003UA/0003UJ` missing-reference warnings only.
- [x] Update `by-class/Config.md`.
  - [x] Revise the `+0x2918f0` wording so it includes this target's structured launcher id write and does not exclusively describe the member as block-list/music-control state.
  - Proof: `rg` confirmed the structured-launcher overlay wording and change-log entry; validator command `000000004346` at `2026-06-27T13:14:02-04:00` returned `ok: 1` with pre-existing `0003FU` missing-reference warnings only.
- [x] Update `by-file/Config.md`.
  - [x] Apply the same `+0x2918f0` clarification as `by-class/Config.md`.
  - Proof: `rg` confirmed the same `+0x2918f0` clarification and change-log entry; validator command `000000004347` at `2026-06-27T13:14:09-04:00` returned `ok: 1` with pre-existing `0003FU` missing-reference warnings only.
- [x] Do not edit generated files or any `-coverage-report.md` file.
  - Proof: B011 made no manual edits to generated reports, generated C++ files, project-level generated reports, manual `-coverage-report.md` files, validator/tool state, or the IDA DB; only validator-owned generated refresh ran during target validation command `000000004389`.
- [x] After implementation, supervisor should run scoped validators for each changed by-* file. The target validation should include generated-output waiting because it gains formal C++.
  - Proof: scoped validators completed for all changed by-* files: `000000004345`, `000000004346`, `000000004347`, `000000004386`, `000000004387`, `000000004389 --wait-generated`, `000000004399`, and `000000004400`; each returned `ok: 1`, and target command `000000004389` reported `generated_refresh: completed`.

## Recommended Formal C++ Insertion

The target should no longer keep formal C++ blank after implementation. The following is a first-draft, source-shaped reconstruction intended for the target document's `RECONSTRUCTION_CPP` field. It avoids IDA labels and uses source-facing names justified by the evidence above.

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void ParseStructuredHostPortIdLauncher(RegistryConfig *config)
{
    SimpleUString commandLine(GetCommandLineW());
    commandLine.MakeExclusive();

    const int hostMarker = commandLine.Find(L"/host:", 0, 6);
    if (hostMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString host;
    const int hostEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                                hostMarker + 1);
    commandLine.SubString(host, hostMarker + 6,
                          hostEnd - (hostMarker + 6));

    const int portMarker = commandLine.Find(L"/portno:", 0, 8);
    if (portMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString portText;
    const int portEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                                portMarker + 1);
    commandLine.SubString(portText, portMarker + 8,
                          portEnd - (portMarker + 8));

    const int idMarker = commandLine.Find(L"/id:", 0, 4);
    if (idMarker == -1)
        FatalError(g_startupLauncherMissingArgumentText);

    SimpleUString launcherId;
    const int idEnd = commandLine.FindFirstOf(kCommandLineTokenDelimiters,
                                              idMarker + 1);
    commandLine.SubString(launcherId, idMarker + 4,
                          idEnd - (idMarker + 4));
    launcherId.TrimLeft(kWideWhitespace);
    launcherId.TrimRight(kWideWhitespace);

    if (!ResolveHostAddressFromWideName(host.c_str(),
                                        config->m_startupAddress))
        FatalError(g_structuredLauncherHostLookupFailureText);

    config->m_startupPort = portText.ToLong();
    config->m_startupReady = 1;
    config->m_startupConnectionMode = 5;
    config->m_startupLauncherId = launcherId;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

## Validation Plan For Implementation Callback

After implementation, run from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0002BR-StructuredHostPortIdLauncherParser-source-quality-removed.md](0002BR-StructuredHostPortIdLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also run scoped file validation for each changed support by-* file:

> Executable block R002 was removed from this report and preserved verbatim in [0002BR-StructuredHostPortIdLauncherParser-source-quality-removed.md](0002BR-StructuredHostPortIdLauncherParser-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The generated research tracker row for [UID:0002BR] is stale (`80/86` in `auto-generated/-ag-research-tracker.md` while the target header is already `86/90`). It should not be manually edited by B011. Supervisor can refresh generated reports after report execution.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0002BR-StructuredHostPortIdLauncherParser-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0002BR-StructuredHostPortIdLauncherParser-source-quality.md","timestamp":"2026-06-27T13:33:12","uid":"0002BR"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002BR-StructuredHostPortIdLauncherParser-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0002BR-StructuredHostPortIdLauncherParser-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002BR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
