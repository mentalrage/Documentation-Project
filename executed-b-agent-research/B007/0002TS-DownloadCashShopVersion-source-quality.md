** TARGET-REPORT-UID:0002TS **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B007 report-only source-quality report

Target: [UID:0002TS] `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`  
Report path: `tools/leaser/Agents/Agent-B007/research/0002TS-DownloadCashShopVersion-source-quality.md`  
Mode: report-only research; no leases taken; no by-* documentation edited.  
Required MCP status: satisfied with live IDA MCP session `80de0a67`.

## Current Target State

Current target metadata is `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC`, blank optional emitter position, and a populated first-draft formal C++ block.

The target is already routed as a FileDownloader-local worker for downloader message `10002`, with feature state in FittingRoom and payload identity in `CashShopVersionRequest`. That ownership route remains correct. The blocker is source-body accuracy: the current formal C++ block preserves the high-level behavior, but live MCP shows several exact source-shape details that the older B001 draft simplified incorrectly.

## Evidence Checked

Documentation checked:

- Target page `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`.
- Direct sibling/route pages: `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`, `by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md`, `by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md`, and aggregate `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`.
- Direct parent/support docs: `by-file/FileDownloader.md`, `by-type/by-constant/DownloaderMessageIds.md`, `by-global/g_pCashShopRequest.md`, `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`, `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`, `by-file/CashShopVersionRequest.md`, `by-class/CashShopVersionRequest.md`, `by-file/FittingRoom.md`, `by-class/FittingRoomDialog.md`, and `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`.
- Literal/JsonCpp support: `by-memory/0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md`, `by-memory/0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md`, `by-memory/0x0060d94c-0x0060d958.SharedVersionJsonKey.md`, `by-memory/0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md`, `by-file/JsonCpp.md`, and `by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md`.
- Prior B001 report `executed-b-agent-research/B001/0002TR-0002TS-0002TT-FileDownloaderDownloadHelpers-source-quality.md`, used as a lead only and revalidated against current MCP.

Live MCP session facts:

- `tools/list` responded from `http://127.0.0.1:13337/mcp`.
- `idb_list` reports one active session: `80de0a67`, input `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, backend `worker`, PID/worker PID `26892`.
- `server_health(database=80de0a67)` reports `status:"ok"`, module `NexusTK.exe`, input executable `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

## Live IDA MCP Evidence

Function and boundary facts:

| Address | MCP result |
| --- | --- |
| `0x0041aa00` | `sub_41AA00`, size `0x41c` |
| `0x0041ae1c` | not a function |
| `0x0041ae20` | `sub_41AE20`, size `0x2ec` |
| `0x0041b10c` | not a function |
| `0x0041b110` | `sub_41B110`, size `0x70` |
| `0x0041b270` | `sub_41B270`, size `0x59` |
| `0x0041bdd0` | `sub_41BDD0`, size `0x480` |
| `0x004298f0` | `sub_4298F0`, size `0x119`, `Json::Reader::Reader()` |
| `0x00429b30` | `sub_429B30`, size `0x103`, `Json::Reader::parse(const std::string&, Json::Value&, bool)` |
| `0x004278e0` | `sub_4278E0`, size `0x3c`, JsonCpp value lookup/get helper |
| `0x0041b8b0` | `sub_41B8B0`, size `0xeb`, small-string assign/copy helper |
| `0x0041b740` | `sub_41B740`, size `0x166`, small-string append/helper |
| `0x0041b9b0` | `sub_41B9B0`, size `0x2e`, wide `__stdio_common_vswprintf_s` wrapper |

Xref and route facts:

- `xrefs_to 0x0041aa00` returns exactly one code xref: `0x0041b13c` in `sub_41B110`.
- `xrefs_to 0x0041ae20` returns exactly one code xref: `0x0041b156` in `sub_41B110`.
- `xrefs_to 0x0041b110` returns one data xref: `0x0060d7d4`; `get_global_value 0x0060d7d4` returns `0x0041b110`, confirming the FileDownloader vtable route.
- `xrefs_to 0x0041b270` returns exactly one code xref: `0x0041c21b` in the FittingRoomDialog constructor `sub_41BDD0`.
- `find_bytes` for absolute VA bytes `00 aa 41 00` and RVA bytes `00 aa 01 00` returns no hits; `find_bytes` for direct call pattern `E8 BF F8 FF FF` returns exactly `0x0041b13c`.
- `get_bytes 0x0041ae1c size 16` returns four `0xcc` bytes followed by the catalog worker prologue, confirming `0x0041ae1c-0x0041ae20` padding.

Literal and global facts:

- `get_string 0x0060d7e0` returns only `H`, matching the known IDA split-label artifact for the pooled UTF-16LE `HTTPTEST` literal; `xrefs_to 0x0060d7e0` returns five source-use refs, including `0x0041aa3b` in this target.
- `get_string 0x0060d8b8` returns `https://secure.kru.com/itemshop/data/itemshop.ver`; `xrefs_to` returns the sole target ref at `0x0041aa64`.
- `get_string 0x0060d91c` returns `Downloading : %d / %d\n`; `xrefs_to` returns `0x0041aca3` in the target and `0x0041b086` in the catalog sibling.
- `get_string 0x0060d94c` returns `version`; `xrefs_to` returns exactly three refs: `0x0041ad2e` in this target, `0x004227c6` in FittingRoom item-state parsing, and `0x00580cab` in StartupWindow update parsing.
- `get_global_value 0x0067a738` and `0x0067a73c` both return `0`; `xrefs_to 0x0067a738` returns the known nine FileDownloader singleton xrefs, and `xrefs_to 0x0067a73c` returns the known sixteen fitting-room dialog pointer xrefs.
- `get_global_value 0x0060d798` returns `0x0041b5e0`; `xrefs_to 0x0060d798` returns the version submit helper vtable write at `0x0041b2a4` and the scalar deleting destructor reference at `0x0041b5ea`.

Target body facts from current decompile/disassembly:

- Function prototype remains `void __stdcall sub_41AA00(int a1)` with `retn 4`; source-facing parameter is still best modeled as `CashShopVersionRequest *request`.
- The worker calls `InternetOpenW(&szAgent, 0, 0, 0, 0)` at `0x0041aa46`, then `InternetOpenUrlW(... itemshop.ver ..., 0x80000000, 0)` at `0x0041aa70`.
- If `InternetOpenUrlW` fails, it closes only the `InternetOpenW` handle at `0x0041aa77`.
- It sets timeout value `3000` through options `2`, `6`, `5`, `7`, and `8`, matching connect, receive, send, data-send, and data-receive timeout fields in the order emitted by the binary.
- It uses `DWORD statusLength = 256` and a `wchar_t` status buffer of 128 elements. The `HttpQueryInfoW(..., HTTP_QUERY_STATUS_CODE, ...)` return value is ignored; `_wtoi`-style conversion is called unconditionally and compared to `200`.
- It constructs the response string before the status comparison. If status is not `200`, it destroys that string and returns without closing the remote file or internet handle; the formal reconstruction should preserve this observed behavior instead of normalizing cleanup.
- On status `200`, it queries `HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER` into a local dword initialized to zero, then stores that value at `request + 0x08` / `request->contentLength`.
- It uses a local `char[100000]` text buffer, not `char[0x4000]`. It does not cap `dwNumberOfBytesAvailable` before `InternetReadFile`.
- After each successful `InternetReadFile`, it writes a null terminator at `buffer[bytesRead]`, constructs a temporary text string using `strlen(buffer)`, appends that text to the accumulated response, increments a local downloaded-byte total by `bytesRead`, writes the total to `request + 0x0c` / `request->bytesDownloaded`, formats progress into a `wchar_t[256]` buffer through the wide safe-format wrapper, and calls `OutputDebugStringW`.
- The loop logs the zero-byte terminal read when `InternetReadFile` succeeds with `bytesRead == 0`; only then does the `do/while` exit.
- It constructs a `Json::Value root`, then a `Json::Reader reader`, and calls `reader.parse(responseText, root, true)` at `0x0041ad09`.
- JsonCpp lookup helper `0x004278e0` is the source-facing `Json::Value::get(const char*, const Json::Value&) const` shape: it looks up the string key over `[key, key + strlen(key))`, falls back to the provided default, and copies the result. The target therefore corresponds to `root.get("version", Json::Value())`, not a direct `root["version"]` reference.
- The target tests `versionValue.isNull()`, converts the non-null value through the string conversion helper, and writes/copies that string to `dword_67A73C + 0x790`, i.e. `g_pFittingRoomDialog->m_itemShopVersion`, when `g_pFittingRoomDialog` is non-null.
- The worker closes `remoteFile` and `internet` only after the `version` value is non-null. If parsing fails or the `version` value is null, the current binary destroys JsonCpp/string locals and returns without those closes. This is target-specific and differs from the catalog sibling.

Dispatcher and submit-helper facts:

- `FileDownloader::OnMessage` at `0x0041b110` switches on `10000`, `10001`, and `10002`.
- Case `10002` null-checks the payload at `0x0041b139`, calls `0x0041aa00` at `0x0041b13c`, then invokes the payload virtual destructor with flag `1` at `0x0041b147`.
- The version submit helper at `0x0041b270` allocates `0x10`, zeroes byte `+0x04` and dwords `+0x08/+0x0c`, writes `CashShopVersionRequest::vftable` at `0x0041b2a4`, and posts message `10002` through `sub_596960(this, 10002, payload, 0)`. If allocation fails, it still posts `10002` with a null payload.
- The FittingRoomDialog constructor reads `dword_67A738` at `0x0041c215` and calls `0x0041b270` at `0x0041c21b`, so the receiver is the FileDownloader/download-dispatcher singleton, not a `CashShopRequest *` payload.

Sibling comparison:

- `DownloadCashShopCatalog` at `0x0041ae20` shares the user-agent, timeout option order, `statusLength = 256`, unguarded status-query return, `char[100000]` text buffer, no available-byte cap, null-terminated/`strlen` append behavior, zero-byte terminal read logging, and progress buffer count `0x100`.
- The sibling differs after the loop: it marks `request + 0x04` complete, conditionally deletes the catalog request when `g_pFittingRoomDialog == NULL` or `m_activeCatalogRequest != request`, then closes both handles after the status-200 branch. It does not parse JsonCpp itself.

## Heuristic / Inference Reanalysis And Validation

Signature and request payload:

- Evidence checked: target prototype and `retn 4`; submit helper allocation/vtable write; dispatcher destruction path; CashShopVersionRequest file/class pages.
- Decision: keep `static void __stdcall DownloadCashShopVersion(CashShopVersionRequest *request)`.
- Rejected alternatives: `CashShopRequest *` is wrong for this worker because the submit helper writes the `CashShopVersionRequest` vtable at `0x0060d798`, allocates only `0x10`, and the catalog sibling owns the `0x28` `CashShopRequest` payload. A raw `int` parameter is decompiler-only.
- Remaining uncertainty: exact original class declaration/base class spelling is not recovered, but field names `state`, `contentLength`, and `bytesDownloaded` are source-quality enough for this target.

Body/source shape:

- Evidence checked: live decompile, disassembly, stack frame, formatter/helper decompiles, string docs, sibling decompile.
- Decision: replace the current formal C++ with an exact source-shaped body that preserves `statusLength = 256`, `char chunkBuffer[100000]`, `strlen` text append, zero-byte terminal logging, explicit `collectComments = true`, `root.get("version", Json::Value())`, and the target-specific handle-close placement.
- Rejected alternatives: keep the old `0x4000` binary-buffer loop; check `HttpQueryInfoW` status-query return; cap `available` before reading; break before logging zero-byte reads; close handles through a common cleanup epilogue. All of these are cleaner, but current MCP disassembly contradicts them.
- Remaining uncertainty: exact original source used the project/MSVC string wrapper emitted as `std::string`-compatible helpers. The formal should use `std::string` as the current project convention and record the wrapper caveat in prose.

JsonCpp boundary:

- Evidence checked: JsonCpp docs, `lookup_funcs` for `0x004298f0/0x00429b30/0x004278e0`, current xrefs to parse front ends, and value helper decompile.
- Decision: JsonCpp remains a third-party dependency. Product code owns the URL, download buffer, schema key use, and fitting-room state write; JsonCpp owns parser/value implementation.
- Rejected alternatives: assigning target parsing behavior to JsonCpp, or treating the `"version"` literal as JsonCpp-owned. The literal is caller-supplied product schema data shared by FileDownloader, FittingRoom, and StartupWindow.

Source placement:

- Evidence checked: `xrefs_to`, dispatcher vtable slot, submit helper receiver, FileDownloader parent docs, FittingRoom docs, CashShopVersionRequest docs.
- Decision: keep owner/emitter as [UID:0000JC] `FileDownloader` and source placement under `NexusTK/network/FileDownloader.cpp`, with FittingRoom and CashShopVersionRequest as support contexts.
- Rejected alternatives: FittingRoom ownership is not supported because FittingRoom only submits the request and owns the written state; CashShopVersionRequest ownership is not supported because the class owns the payload layout/vtable/destructor, not the HTTP worker; no-owner is rejected because the function has a single FileDownloader dispatcher route and source-shaped body.

FittingRoom field meanings:

- Evidence checked: target write at `0x0041ad82-0x0041ada7`, `g_pFittingRoomDialog` global xrefs, FittingRoom file support, FittingRoomDialog class/constructor current wording.
- Decision: `dword_67A73C + 0x790` should be treated as `FittingRoomDialog::m_itemShopVersion` for this target. `+0x7a8` is `m_activeCatalogRequest`, not a stored version request pointer.
- Rejected alternatives: treating `+0x790` as an unrelated equipment-name cache when documenting the version worker, and treating `+0x7a8` as pending version request state. The version request payload is destroyed by the dispatcher and is not stored in the dialog.

Generated/stale artifacts:

- Evidence checked: prior B001 report, current target/support docs, generated/recovered output mentions in old docs, FittingRoom constructor formal call text.
- Decision: the old B001 high-level worker route remains valid, but its formal C++ body is superseded in the exact body details above. Generated/recovered names such as `g_pCashShopRequest` are stale aliases for `g_pFileDownloader`/download-dispatcher state at `0x0067a738`.
- Rejected alternatives: preserving the old `SubmitCashShopVersionRequest(g_pCashShopRequest, 10002)` constructor wording as source-quality. Current MCP shows `0x0041b270` takes the downloader receiver in `ecx` and embeds message `10002` internally.

## Source Placement

Recommended placement remains [UID:0000JC] `FileDownloader`, emitted through `NexusTK/network/FileDownloader.cpp`.

This placement fits because the only code route into the worker is `FileDownloader::OnMessage` case `10002`, the dispatcher is vtable-routed through `0x0060d7d4`, and the request-submission path calls the FileDownloader/download-dispatcher singleton at `0x0067a738`. FittingRoom constructs the dialog and consumes the result, but does not own the worker-thread HTTP body. CashShopVersionRequest owns the payload type and destructor context, but not the downloader flow.

Remaining placement uncertainty is limited to exact original helper visibility: the worker may have been a file-local/static helper in `FileDownloader.cpp` rather than a public method. The current formal `static void __stdcall DownloadCashShopVersion(...)` remains the best source-facing shape.

## Range / Split / Padding / Reclassification Analysis

No split, merge, range repair, or reclassification is recommended.

- Target function range remains `0x0041aa00-0x0041ae1c`, size `0x41c`.
- Successor `0x0041ae1c-0x0041ae20` is four `0xcc` bytes before `DownloadCashShopCatalog` at `0x0041ae20`.
- Predecessor/aggregate relationships remain covered by the existing exact-child inventory page `0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`.
- The target remains reconstructable source-authored code. It is not a non-emitting aggregate and not a generated/compiler helper.

## Negative Evidence Summary

Checked and rejected:

- Hidden pointer-table or direct non-dispatch route to `0x0041aa00`: rejected by `xrefs_to` one-code-xref result and MCP `find_bytes` negative absolute-VA/RVA scans.
- `CashShopRequest *` target parameter: rejected by version-submit allocation size `0x10`, `CashShopVersionRequest` vtable write, and dispatcher virtual destruction through the version payload.
- FittingRoom as direct owner: rejected because FittingRoom reads `g_pFileDownloader` and calls a FileDownloader receiver helper, then later receives the result through `g_pFittingRoomDialog`.
- JsonCpp as owner: rejected because JsonCpp parser/value helpers are public library callees; product code owns the URL and schema interpretation.
- Shared literal declarations for `HTTPTEST`, `Downloading : %d / %d\n`, or `"version"`: rejected for target ownership. The literal pages already document pooled/multi-use state where applicable.
- Current formal body details `char buffer[0x4000]`, checked status-query return, binary append by `bytesRead`, common handle cleanup, and no terminal-zero-byte logging: rejected by current target decompile/disassembly.
- IDA DB rename/type/comment edits: not requested. Source-facing names are ready for docs/formal C++, but database edits would be process out-of-scope for this report-only assignment.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are recommended.

Source-facing names/types to use in documentation and formal C++:

- Function: `DownloadCashShopVersion`.
- Parameter/type: `CashShopVersionRequest *request`.
- Payload fields: `state`, `contentLength`, `bytesDownloaded`.
- Global: `g_pFileDownloader` for `0x0067a738` in support docs, with stale filename/alias caveat retained where paths still say `g_pCashShopRequest`.
- Global: `g_pFittingRoomDialog`.
- Dialog field: `m_itemShopVersion` at `+0x790`.
- Dialog field: `m_activeCatalogRequest` at `+0x7a8`, not version request storage.
- Locals: `responseText`, `chunkBuffer`, `bytesDownloaded`, `contentLength`, `versionValue`, `versionText`.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. Replace the current target formal block with the exact formal content below. This is the only formal C++ recommendation in this report.

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void __stdcall DownloadCashShopVersion(CashShopVersionRequest *request)
{
    int bytesDownloaded = 0;
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return;
    }

    HINTERNET remoteFile = InternetOpenUrlW(internet,
                                            L"https://secure.kru.com/itemshop/data/itemshop.ver",
                                            NULL,
                                            0,
                                            INTERNET_FLAG_RELOAD,
                                            0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return;
    }

    DWORD timeout = 3000;
    InternetSetOptionW(remoteFile, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    DWORD statusLength = 256;
    wchar_t statusText[128];
    HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL);

    std::string responseText;
    if (_wtoi(statusText) == HTTP_STATUS_OK) {
        DWORD contentLength = 0;
        DWORD lengthSize = sizeof(contentLength);
        HttpQueryInfoW(remoteFile,
                       HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER,
                       &contentLength,
                       &lengthSize,
                       NULL);
        request->contentLength = contentLength;

        wchar_t progress[256] = {};
        char chunkBuffer[100000];
        DWORD bytesRead = 0;

        do {
            DWORD available = 0;

            if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0) ||
                !InternetReadFile(remoteFile, chunkBuffer, available, &bytesRead)) {
                break;
            }

            chunkBuffer[bytesRead] = '\0';
            responseText.append(chunkBuffer, strlen(chunkBuffer));

            bytesDownloaded += bytesRead;
            request->bytesDownloaded = bytesDownloaded;

            swprintf_s(progress,
                       _countof(progress),
                       L"Downloading : %d / %d\n",
                       bytesDownloaded,
                       contentLength);
            OutputDebugStringW(progress);
        } while (bytesRead != 0);

        Json::Value root;
        Json::Reader reader;
        if (reader.parse(responseText, root, true)) {
            Json::Value versionValue = root.get("version", Json::Value());
            if (!versionValue.isNull()) {
                std::string versionText = versionValue.asString();
                if (g_pFittingRoomDialog != NULL) {
                    g_pFittingRoomDialog->m_itemShopVersion = versionText;
                }

                InternetCloseHandle(remoteFile);
                InternetCloseHandle(internet);
            }
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior:

- It preserves the current function signature, URLs, option values/order, status-query return-value omission, status/content-length buffer sizes, response string construction before status check, 100000-byte text buffer, no available-byte cap, null-terminated/`strlen` append semantics, terminal zero-byte read logging, explicit JsonCpp `collectComments = true`, `root.get("version", Json::Value())`, fitting-room version write, and target-specific handle close path.

Reason it matches plausible original developer source shape:

- The body uses normal WinINet handles, `DWORD` WinINet sizes, `std::string` text accumulation, JsonCpp legacy `Reader`/`Value` APIs, and existing project naming conventions for globals and fields. It avoids IDA labels while preserving the odd behavior that current binary evidence proves.

Reason not higher/final:

- Exact original string typedef/wrapper spelling, exact helper visibility, and final header declaration style remain unrecovered. The body is now exact enough for first-draft reconstruction but not final 95+ source.

## Final Recommendation

Recommended target disposition:

- Change [UID:0002TS] to `COMPLETION:91`, `CONFIDENCE:93`.
- Keep `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC`, and blank optional emitter position unchanged.
- Replace the target formal C++ block with the exact formal block above.
- Incorporate the current MCP session facts, exact route/xref/body/byte facts, refined JsonCpp/body details, sibling parity/differences, and rejected old-body alternatives.

Recommended support disposition:

- Update direct FileDownloader/aggregate support docs to record the refined source shape and to supersede the old `0x4000`/common-cleanup draft wording for [UID:0002TS].
- Update FittingRoom/FittingRoomDialog support docs where they still call `0x0067a738` `g_pCashShopRequest` as a primary source name or describe `+0x790/+0x7a8` imprecisely.
- Leave JsonCpp, literal, global, and CashShopVersionRequest support pages unchanged when implementation inspection confirms they already contain equal-or-greater detail.
- Do not edit generated files, project-level files, manual coverage reports, tool state, or IDA DB.

## Recommended Target Doc Changes

Target path: `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`

Exact changes to apply after supervisor validation:

- Metadata: `COMPLETION:88 -> 91`, `CONFIDENCE:90 -> 93`.
- Owner/emitter/reconstructable: unchanged.
- Formal C++: replace the current block with the exact block in this report.
- Behavior/evidence: add current MCP session `80de0a67` provenance, active database and server-health facts, exact function size `0x41c`, one dispatcher xref at `0x0041b13c`, no VA/RVA byte hits, exact call-pattern hit, tail padding `cc cc cc cc`, and exact decompile/body details.
- Preserve and correct historical B001 details: B001 correctly resolved owner/route/payload/message ID, but its first-draft body used a 0x4000 binary append loop, checked status-query return, and common cleanup that current MCP disproves.
- Add negative evidence: no hidden pointer table/direct route; no FittingRoom/CashShopVersionRequest/JsonCpp owner; no source justification to clean up the observed leak paths.

## Recommended Support Doc Changes

Support paths recommended for implementation callback:

1. `by-file/FileDownloader.md`
   - Add a B007 support-sync bullet for [UID:0002TS] stating the current source body uses `statusLength = 256`, `wchar_t statusText[128]`, `char chunkBuffer[100000]`, null-terminated/`strlen` response appends, zero-byte terminal read logging, `Json::Reader::parse(..., true)`, `root.get("version", Json::Value())`, and closes handles only in the non-null-version path.
   - Keep FileDownloader source placement and message `10002` route unchanged.

2. `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`
   - Update the [UID:0002TS] child behavior summary with the exact B007 MCP body details and the target-specific cleanup behavior.
   - Preserve that [UID:0002TT] shares the same text-buffer/`strlen` WinINet skeleton but differs by marking completion, conditional request deletion, and post-status-200 handle cleanup.
   - Keep aggregate non-emitting status unchanged.

3. `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`
   - Add a sibling-parity note only: current MCP comparison shows the catalog formal body has the same old simplifications in the shared WinINet loop (`statusLength = 256`, `char[100000]`, `strlen`, terminal zero-byte logging). Do not change [UID:0002TT] metadata or formal C++ from this [UID:0002TS] report unless the supervisor explicitly expands the callback to sibling formal C++ correction.

4. `by-file/FittingRoom.md`
   - Replace stale primary wording that says the constructor submits through `g_pCashShopRequest` with `g_pFileDownloader` / download-dispatcher singleton, while retaining the stale filename/alias caveat through the global page link.
   - Confirm existing `m_itemShopVersion +0x790` and `m_activeCatalogRequest +0x7a8` paragraph already has equal-or-greater detail after the wording sync.

5. `by-class/FittingRoomDialog.md`
   - Update field-role wording so `+0x790` is `m_itemShopVersion` for the version worker and `+0x7a8` is `m_activeCatalogRequest` for the catalog request. Do not describe `+0x7a8` as version-request storage.

6. `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`
   - Add prose correction that the live call at `0x0041c215-0x0041c21b` loads `dword_67A738` / `g_pFileDownloader` and calls the zero-argument receiver helper `0x0041b270`, which internally posts message `10002`.
   - Record the existing formal constructor line using `g_pCashShopRequest` and an explicit `10002` argument as stale/generated-source wording. Do not change constructor score or perform a full constructor C++ rewrite from this target report unless the supervisor callback explicitly authorizes it.

Support paths where no edit is currently required if implementation inspection confirms equal-or-greater detail:

- `by-file/CashShopVersionRequest.md` and `by-class/CashShopVersionRequest.md`: already carry the `0x10` payload layout, vtable/destructor identity, FileDownloader worker split, and `m_itemShopVersion` write.
- `by-global/g_pCashShopRequest.md` and `by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md`: already reject `CashShopRequest *` as primary and emit `FileDownloader *g_pFileDownloader;`.
- `by-memory/0x0067a73c-0x0067a740.g_pFittingRoomDialog.md`: already records the target read at `0x0041ad75` and fitting-room singleton route.
- `by-type/by-constant/DownloaderMessageIds.md`: already maps `10002` to `kDownloadCashShopVersionMessage`.
- JsonCpp and literal pages listed above: already record product caller xrefs, shared literal routing, and parser ownership boundaries at equal-or-greater detail.

## Score And Metadata Recommendation

Current score/metadata: `88/90`, owner/emitter `0000JC`, reconstructable true, formal C++ populated.

Recommended score/metadata: `91/93`, owner/emitter/reconstructable unchanged, formal C++ replaced.

Score rationale:

- Completion rises because the current pass resolves the main source-quality blockers left by the old B001 draft: exact buffer size, text append semantics, status-query behavior, JsonCpp accessor form, progress buffer size, terminal-read behavior, target-specific cleanup placement, current route scan, and stale support wording.
- Confidence rises because live MCP decompile/disassembly/xrefs/bytes agree with existing route docs and sibling behavior.
- Score does not exceed `91/93` because original project string typedef names, helper visibility, final header declaration style, and exact global/member original spellings are still inferred from binary/support context rather than recovered from source/debug artifacts.

Score-improvement attempts and results:

| Blocker | Research performed | Result |
| --- | --- | --- |
| Formal body might be only approximate | Live target decompile, disassembly, helper decompile, sibling decompile | Replace formal block; old draft body is stale in exact loop/status/cleanup details |
| FileDownloader vs feature owner | Current `xrefs_to`, dispatcher decompile, submit helper decompile, constructor call disassembly | FileDownloader route remains correct |
| Hidden pointer/table route | Current MCP `xrefs_to` plus byte searches for VA/RVA/direct call pattern | No hidden VA/RVA route; exactly one direct call at `0x0041b13c` |
| Payload type/fields | Submit helper allocation/vtable write, dispatcher virtual delete, CashShopVersionRequest docs | `CashShopVersionRequest *`, `contentLength`, `bytesDownloaded` resolved |
| JsonCpp API shape | Parse front-end docs and decompile of `0x004278e0`/`0x004269d0`/`0x00425ac0` | Use `reader.parse(..., true)`, `root.get("version", Json::Value())`, `isNull`, `asString` |
| FittingRoom field role | Target write and support docs compared | `+0x790` is item-shop version string for this worker; `+0x7a8` is catalog request ownership |
| Sibling relationship | Catalog decompile and support docs compared | Shared WinINet loop refined; catalog cleanup differs and remains support-only here |

## Open Questions With Attempted Resolution

- Exact original string type/wrapper: current target uses MSVC/Dinkumware small-string helpers. `std::string` remains the right formal source-level spelling unless a project typedef is later recovered. This limits final-audit score only.
- Exact original helper visibility/name: no source/debug/map symbol proves whether the worker was a private static helper, namespace function, or method-like helper. Single dispatcher route and existing FileDownloader naming support `static void __stdcall DownloadCashShopVersion(...)`.
- Exact original global name for `0x0067a738`: current docs support `FileDownloader *g_pFileDownloader` with possible `g_pDownloadDispatcher` facade caveat. `g_pCashShopRequest` as primary type/name is rejected for this target.
- Whether the observed handle-close placement is an original source bug or decompiler artifact: disassembly confirms where close calls exist. No evidence supports inventing a common cleanup path, so the formal block should preserve the observed behavior.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

No manual `-coverage-report.md` edit is recommended for B007. Do not edit `by-memory/-coverage-report.md` or any other coverage report. Validator-owned generated reports should refresh through scoped validators after implementation.

No supervisor-owned tracker row text is required from this report. The generated research tracker should be refreshed by normal validator/report execution only if the supervisor chooses.

## Follow-Up Actions

Supervisor actions:

- Validate this report claim-by-claim.
- If accepted, send an implementation callback naming the exact target/support docs to edit and whether support-only stale constructor formal wording should be corrected in prose only or expanded to a constructor formal C++ update.
- Keep sibling [UID:0002TT] formal C++ correction separate unless explicitly expanding scope.

A-agent actions: none.

B007 future research actions: none required for [UID:0002TS] after the recommended target/support incorporation. A separate [UID:0002TT] pass can correct catalog formal C++ if the supervisor wants sibling body precision to match this report.

## Confidence

Recommendation confidence: 93/100.  
Score confidence: 93/100.  
Remaining uncertainty is limited to original source spelling and header/file-local declaration style, not behavior, route, payload type, or source ownership.

## Validator Results

Implementation validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` after the accepted by-* edits, while the B007 lease batch was active:

| Command | command_id | command_timestamp | Exit | ok | Warnings / generated-refresh state |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md --apply --queue-timeout 240` | `000000003163` | `2026-06-26T19:03:36-04:00` | `0` | `1` | No missing-ref warnings; `generated_refresh: deferred`; validator updated target metadata/index state and projected stats. |
| `python .\tools\validator.py --mode file --file by-file\FileDownloader.md --apply --queue-timeout 240` | `000000003164` | `2026-06-26T19:03:43-04:00` | `0` | `1` | Pre-existing `missing_ref_uid` warnings for `0003FT`, `0003G0`, `0003G2`, and `0003AL`; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md --apply --queue-timeout 240` | `000000003165` | `2026-06-26T19:03:55-04:00` | `0` | `1` | Pre-existing `missing_ref_uid 0003GY` and `missing_ref_target 0000WH` warnings; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-memory\0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md --apply --queue-timeout 240` | `000000003166` | `2026-06-26T19:04:05-04:00` | `0` | `1` | No missing-ref warnings; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-file\FittingRoom.md --apply --queue-timeout 240` | `000000003167` | `2026-06-26T19:04:13-04:00` | `0` | `1` | Pre-existing missing target/UID warnings for stale support references including `0002DW`, `0002E0`, `00030R`, `00030T`, and `0003AM`; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-class\FittingRoomDialog.md --apply --queue-timeout 240` | `000000003168` | `2026-06-26T19:04:26-04:00` | `0` | `1` | No missing-ref warnings; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-memory\0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md --apply --queue-timeout 240` | `000000003169` | `2026-06-26T19:04:35-04:00` | `0` | `1` | Pre-existing `missing_ref_target 00024M` warning; `generated_refresh: deferred`; projected stats updated. |
| `python .\tools\validator.py --mode file --file by-memory\0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md --apply --queue-timeout 240` | `000000003170` | `2026-06-26T19:07:28-04:00` | `0` | `1` | Final target revalidation after one-space formal-block formatting correction; no missing-ref warnings; `generated_refresh: deferred`; projected stats updated. |

Validator-owned side effects reported by the scoped runs: `tools/validator.ini`/autogen registry updates for the changed source files, UID/reference link normalization in the edited by-* docs, and validator-driven `project-level/-auto-completion-stats.md` projected-stat updates. No generated/project-level/tool-state file was edited manually by B007.

Queue/generated-refresh status after lease release: `python .\tools\validator.py --queue-status` returned command `000000003172` at `2026-06-26T19:09:15-04:00`, exit `0`, worker running, `queued jobs: 0`, `processing jobs: 0`, `queued generated refresh jobs: 0`, and `processing generated refresh jobs: 0`.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0002TS-DownloadCashShopVersion-source-quality.md`

Modified during implementation:

- `source-3/project-documentation/by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`
- `source-3/project-documentation/by-file/FileDownloader.md`
- `source-3/project-documentation/by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`
- `source-3/project-documentation/by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`
- `source-3/project-documentation/by-file/FittingRoom.md`
- `source-3/project-documentation/by-class/FittingRoomDialog.md`
- `source-3/project-documentation/by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B007/research/0002TS-DownloadCashShopVersion-source-quality.md`

Renamed: none.

Leases: B007 leased the seven by-* files immediately before editing, ran the scoped validators above while leased, and released all seven immediately afterward. A narrow target-only lease was then taken for the one-space formal-block correction, target validator `000000003170` was run, and that lease was released immediately. Release commands returned `Success`; the current lease report afterward showed no active B007 entries, only expired June 18 Supervisor entries.

Report execution: not run by B007. Supervisor executes the report after implementation verification.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor accepted this report and callback `B007-implement-0002TS-download-cash-shop-version-source-quality-20260626` was present in `goal.md`.
- [x] Target/support docs to update: target `by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md`; direct support `by-file/FileDownloader.md`; aggregate support `by-memory/0x0041aa00-0x0041b2c9.CashShopVersionAndCatalogDownload.md`; sibling support note in `by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md`; fitting-room support wording in `by-file/FittingRoom.md`, `by-class/FittingRoomDialog.md`, and `by-memory/0x0041bdd0-0x0041c250.FittingRoomDialogConstructor.md`. Proof: all seven files were edited and validated. No edits were made to CashShopVersionRequest, JsonCpp, literal, message-id, or global pages because report inspection found equal-or-greater detail there.
- [x] Current target state and actual evidence checked recorded: preserve current `88/90` state, MCP session `80de0a67`, `server_health`, exact bounds `0x0041aa00-0x0041ae1c`, one dispatcher xref `0x0041b13c`, byte route scan, tail padding, target decompile/disassembly facts, submit/dispatcher/constructor facts, sibling comparison, and support-doc comparison. Proof: target page now has B007 MCP/session/body/route/padding facts; support pages carry route/body/sibling notes.
- [x] Metadata/score changes to apply: change [UID:0002TS] to `COMPLETION:91`, `CONFIDENCE:93`; leave owner/emitter/reconstructable/optional emitter unchanged. Proof: target header is `91/93` after validator `000000003163`; `CANONICAL_OWNER:0000JC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JC`, and blank optional emitter position are unchanged.
- [x] Score-limiting blockers researched to resolution: incorporate exact replacement for old formal body, route proof, payload layout, JsonCpp accessor, fitting-room field, sibling relationship, and evidence-backed reason score remains below final-audit level. Proof: target behavior/evidence/rejected-alternatives/open-caveat sections now record these details and final score cap rationale.
- [x] Owner/emitter/reconstructable changes to apply: none; keep [UID:0000JC] owner/emitter and reconstructable true. Proof: target metadata and validator output preserve those fields.
- [x] Split/rename/new-child changes to apply: none; keep range and child inventory unchanged. Proof: no files renamed/created beyond the existing report; aggregate support preserves the existing exact-child inventory.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: preserve FileDownloader placement, no IDA DB edits, no range repair, no reclassification. Proof: support pages preserve FileDownloader route and aggregate non-emitting classification; no IDA DB or generated/manual coverage file edits were made by B007.
- [x] First-draft C++ or no-code proof to apply: replace [UID:0002TS] formal C++ with the exact formal block in this report; do not add any other formal C++ from this report. Proof: target formal block was replaced; [UID:0002TT] and constructor formal blocks were intentionally left unchanged under callback constraints.
- [x] Exact target/support doc facts to incorporate at report-level detail: current MCP session facts, WinINet option order, status query return omission, status/progress buffer sizes, 100000-byte text buffer, `strlen` append, zero-byte terminal logging, `reader.parse(..., true)`, `root.get("version", Json::Value())`, `m_itemShopVersion +0x790`, close-handle placement, dispatcher destruction, submit-helper payload initialization, and sibling catalog difference. Proof: incorporated in target behavior/evidence/rejection sections plus FileDownloader, aggregate, catalog, FittingRoom, FittingRoomDialog, and constructor support notes.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old B001 high-level route valid but old body details superseded; reject `0x4000` buffer, bytesRead binary append, status-query return guard, common cleanup, FittingRoom/CashShopVersionRequest/JsonCpp ownership, hidden pointer-table route, `CashShopRequest *` parameter, primary `g_pCashShopRequest` name/type, and `+0x7a8` as version request storage. Proof: target `Rejected Old-Body Alternatives` plus support notes preserve these rejections.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated/recovered output and old B001 body used as leads only; unrelated Wave3 `0x0041b9e0` raw-constructor mention not relevant to this target. Proof: target/support docs record stale B001 body supersession and constructor support keeps stale generated-source wording caveat; no Wave3 material was used as authority.
- [x] Open questions to close or document as evidence-backed unresolved: exact source typedef/string wrapper, helper visibility, final global/header spelling, and handle-close bug/source artifact distinction documented with score/C++ impact. Proof: target `Confidence And Open Questions` records these as score caps after behavior/route blockers were resolved.
- [x] Validators to run: run scoped validators from `source-3/project-documentation` for each changed by-* file listed in `Validator Results`; record command id, timestamp, exit code, ok count, warnings, and generated-refresh state during implementation. Proof: validators `000000003163` through `000000003169`, plus final target revalidation `000000003170`, recorded above; all exit `0` / `ok: 1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh only through validators; no manual coverage/tracker edit by B007. Proof: scoped validators reported `generated_refresh: deferred`, and queue-status command `000000003172` later showed no queued or processing generated refresh jobs; no manual generated/project-level/tool-state/coverage edits were made by B007.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation: accepted by callback in `goal.md`; implementation performed without rewriting the report from scratch.
- [x] All accepted target/support doc details incorporated at report-level detail: target and six support by-* files edited with exact MCP/body/route/sibling/FittingRoom route details; CashShopVersionRequest, JsonCpp, literal, message-id, and global pages were already at equal-or-greater detail and left untouched.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target `91/93`; owner/emitter/reconstructable unchanged; no split/rename/new child; target formal C++ replaced; sibling/constructor formal C++ not rewritten because callback explicitly excluded those rewrites.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: stale B001 body details, `g_pCashShopRequest`/`CashShopRequest *` alias caveat, hidden route rejection, and `+0x7a8` version-storage rejection are documented in target/support pages.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: remaining original spelling/helper visibility/global/header/handle-close caveats are documented as score caps, not implementation blockers.
- [x] Validators run and results recorded: scoped validator table above records commands, command IDs, timestamps, exit codes, ok counts, warnings, and generated-refresh state, including final target revalidation `000000003170`.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: validators reported deferred generated refresh; queue-status command `000000003172` showed no queued or processing generated refresh jobs afterward. B007 did not manually edit generated reports or coverage/tracker files. No explicit manual coverage/tracker text is needed.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002TS-DownloadCashShopVersion-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002TS-DownloadCashShopVersion-source-quality.md","timestamp":"2026-06-26T19:10:46","uid":"0002TS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
