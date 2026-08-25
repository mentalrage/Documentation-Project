** TARGET-REPORT-UID:00022V **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00022V] MapiSendMailHelper Source-Quality Reanalysis

Assignment: `B003-goal2-mapi-send-mail-helper-source-quality-00022V-20260619`

Primary target: [UID:00022V] `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004f5b20-0x004f5c73.MapiSendMailHelper.md`

Report-only output. No by-* docs, generated reports/source, IDA database, or `by-memory/-coverage-report.md` were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:00022V] as a reconstructable PlatformApi-owned helper, retain `CANONICAL_OWNER:0000ML` and `EMITTER_UIDS:0000ML`, raise the page to `COMPLETION:88` and `CONFIDENCE:89`, and populate first-draft C++ in the target formal code block after supervisor acceptance.
- Final disposition: source-authored retained Win32 Simple MAPI helper, not startup-logo code, not `WinMain`, not in-game mail packet code, not conversion-helper owner, and not a mixed range requiring split.
- Required action: update target/support docs with the field/parameter/type closure below; add bounded formal C++ for this helper; add a no-op/comment emitter for [UID:0003OT] if the MAPI lookup literals remain represented by a separate emitting string child, because the literals should be emitted inline by this helper rather than duplicated as standalone globals.
- Confidence: strong. Function shape, stack layout, Windows MAPI structure interpretation, dynamic API lookup, conversion helper dependency, and PlatformApi route are well supported. Confidence stays below final-audit quality because the original source symbol and direct feature caller are still absent, and the live IDA MCP endpoint was unavailable during this 2026-06-19 pass.

## Target

- Target UID: `00022V`
- Target path: `by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md`
- Current scores/state: `COMPLETION:85`, `CONFIDENCE:87`, `CANONICAL_OWNER:0000ML`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000ML`, blank formal C++.
- Current route: [UID:0000ML] `PlatformApi` -> `auto-generated/NexusTK/platform/PlatformApi.cpp`.
- Current generated output: `auto-generated/NexusTK/platform/PlatformApi.cpp` contains [UID:000249] conversion helpers and an empty emitter marker for [UID:00022V].
- Current by-memory coverage row is stale at `78% : strong` even though the target header is `85/87`.

## Supervisor Active Recheck

The supervisor/user assigned a source-quality reanalysis for the existing target only. This pass did not require split repair: the current half-open range `0x004f5b20-0x004f5c73` is one function-shaped helper bounded by documented padding before and after. The assignment required:

- source-quality reanalysis;
- a mandatory `## Heuristic / Inference Reanalysis And Validation` section;
- best-supported names for helpers, fields, types, globals, and placeholders;
- caller/reachability and owner/source placement;
- open-question closure;
- first-draft C++ if eligible or exact no-code proof;
- exact supervisor-owned coverage row text;
- target/support implementation checklist.

All of those are included below.

## Evidence Standards Used

Evidence used:

- Existing IDA-backed target/support docs under `project-documentation`.
- Local Ghidra exported function JSON at `resources/exported_data/functions/0x004f5b20.json`, plus duplicated Ghidra/combined test exports.
- Local exported string/global indexes for `0x0061d0f8` and `0x0061d104`.
- Current Windows SDK `MAPI.h` for `MapiMessage`, `MapiRecipDesc`, `MapiFileDesc`, `LPMAPISENDMAIL`, `MAPI_TO`, `MAPI_RECEIPT_REQUESTED`, and `MAPI_SENT` field/constant interpretation.
- Current `by-file/PlatformApi.md`, [UID:000249] `PlatformStringConversionHelpers`, [UID:0003OT] `MapiLookupStrings`, neighbor [UID:00022U] `StartupLogoBinkMidpointRestart`, neighbor [UID:00019G] `WinMain`, `auto-generated/-ag-memory-coverage.md`, `by-memory/-coverage-report.md`, and `by-project-structure/proposed-source-tree.md`.
- B002 executed report `000249-platform-string-conversion-source-quality.md` for accepted conversion-helper names and rejected ownership alternatives.
- Negative evidence: no Ghidra callers, prior target docs' 2026-06-06/2026-06-15 live IDA no-function/no-caller/no-xref checks, no source path evidence tying this helper to startup-logo or `WinMain`.

Evidence caveat:

- IDA MCP at `http://127.0.0.1:13337/mcp` was unreachable on 2026-06-19 (`Unable to connect to the remote server`). This pass therefore does not claim fresh live IDA verification. It rechecks current docs against local Ghidra exports, generated reports, local SDK structure definitions, and prior IDA-backed support pages. That limits confidence but does not reopen the already-validated range/behavior conclusions.
- The executable itself was not found under the obvious workspace/Desktop paths, so I could not run a fresh PE rel32/absolute-pointer scan for `0x004f5b20`. Existing Ghidra callers `[]` and prior IDA `xrefs_to/callers` no-edge checks remain the available reachability evidence.

## IDA / Ghidra / Header Facts

Function/range facts:

- Existing target docs record prior live IDA raw body `0x004f5b20-0x004f5c73`, adjacent `0xcc` padding at `0x004f5b1e-0x004f5b20` and `0x004f5c73-0x004f5c80`, and body size `0x153` / 339 bytes (Verified with `int_convert.py` during this pass).
- Existing target docs record stack frame size `0x70` / 112 bytes (Verified with `int_convert.py` during this pass).
- Local Ghidra export reports `FUN_004f5b20`, size 339, signature `undefined __cdecl FUN_004f5b20(LPCWSTR param_1, LPCWSTR param_2, LPCWSTR param_3, LPCWSTR param_4)`, `is_thunk:false`, `num_callers:0`, `num_callees:5`, and `callers:[]`.
- Ghidra callees are `LoadLibraryA`, `GetProcAddress`, `FUN_00599440`, `FUN_005994b0`, and `FreeLibrary`.
- Existing target docs record prior live IDA no-function-object status for `0x004f5b20` and `0x004f5c73`, with `_WinMain@16` beginning at `0x004f5c80`.

String/data facts:

- [UID:0003OT] records `MAPI32.DLL` at `0x0061d0f8` and `MAPISendMail` at `0x0061d104`, successor `BaramApp` vtable at `0x0061d118`, and xref from the MAPI helper at `0x004f5b3d`.
- Local exported `master_strings.json` agrees that `0x0061d0f8` is `MAPI32.DLL` and `0x0061d104` is `MAPISendMail`.
- Local exported `master_globals.json` names `0x0061d0f8` as Ghidra `s_MAPI32.DLL_0061d0f8` / IDA `aMapi32Dll` and `0x0061d104` as Ghidra `s_MAPISendMail_0061d104` / IDA `aMapisendmail`.

Windows MAPI header facts:

- `MapiFileDesc` fields are `ulReserved`, `flFlags`, `nPosition`, `lpszPathName`, `lpszFileName`, and `lpFileType`; 32-bit size is `0x18` / 24 bytes (Verified with `int_convert.py` for `0x18`).
- `MapiRecipDesc` fields are `ulReserved`, `ulRecipClass`, `lpszName`, `lpszAddress`, `ulEIDSize`, and `lpEntryID`; 32-bit size is `0x18` / 24 bytes (Verified with `int_convert.py` for `0x18`).
- `MAPI_TO` is `1`.
- `MapiMessage` fields are `ulReserved`, `lpszSubject`, `lpszNoteText`, `lpszMessageType`, `lpszDateReceived`, `lpszConversationID`, `flFlags`, `lpOriginator`, `nRecipCount`, `lpRecips`, `nFileCount`, and `lpFiles`; 32-bit size is `0x30` / 48 bytes (Verified with `int_convert.py` for `0x30`).
- `MAPI_RECEIPT_REQUESTED` is `0x00000002`; `MAPI_SENT` is `0x00000004`. Therefore this helper's `message.flFlags = 2` is receipt-requested, not `MAPI_SENT`.
- `LPMAPISENDMAIL` is the SDK pointer type for `MAPISendMail` and matches the function pointer returned by `GetProcAddress`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score Recommendation | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004f5b1e-0x004f5b20` | [UID:0000VN] `by-memory/-ignored.md` | padding between startup-logo helper and MAPI helper | false/ignored | ignored ledger | unchanged | existing row valid |
| `0x004f5b20-0x004f5c73` | [UID:00022V] target | retained PlatformApi Simple MAPI send helper | true | [UID:0000ML] PlatformApi | `88/89` | update target and populate C++ |
| `0x004f5c73-0x004f5c80` | [UID:0000VN] `by-memory/-ignored.md` | padding between MAPI helper and `WinMain` | false/ignored | ignored ledger | unchanged | existing row valid |
| `0x0061d0f0-0x0061d118` | [UID:0003OT] `MapiLookupStrings` | source-authored MAPI lookup literals consumed by [UID:00022V] | true | [UID:0000ML] PlatformApi | keep score; add no-op emitter comment if formal C++ is required | do not duplicate literals as standalone globals |
| `0x00599440-0x005995a7` | [UID:000249] `PlatformStringConversionHelpers` | PlatformApi conversion/free helpers consumed by [UID:00022V] | true | [UID:0000ML] PlatformApi | unchanged | dependency names already accepted |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004f5b20` | Ghidra callers `[]`; prior IDA `xrefs_to/callers` empty | No direct static caller is currently proven. Treat as retained no-direct-caller helper unless future PE/IDA evidence finds an indirect or missed route. |
| `0x004f5b27` | prior [UID:00025O]/[UID:0003OT] literal xref to `MAPI32.DLL` | Dynamic library load string consumed by this helper. |
| `0x004f5b3d` | prior [UID:0003OT] xref to `MAPISendMail` | Dynamic procedure lookup string consumed by this helper. |
| `0x004f5b58`, `0x004f5b61`, `0x004f5b6c`, `0x004f5b77`, `0x004f5b8c` | calls to [UID:000249] `AllocAnsiFromWideDefaultCodepage` | Converts recipient twice, subject, note text, and optional attachment path. |
| `0x004f5c3a`, `0x004f5c45`, `0x004f5c4d`, `0x004f5c55`, `0x004f5c5d` | calls to [UID:000249] `FreeAllocatedAnsiString` | Cleanup for optional attachment path, note text, subject, recipient name, recipient address. |
| external `LoadLibraryA` | callee | Dynamically loads `MAPI32.DLL`; the helper intentionally avoids an import-table dependency on Simple MAPI. |
| external `GetProcAddress` | callee | Resolves `MAPISendMail`. |
| external `FreeLibrary` | callee | Releases the loaded MAPI library before return. |

## Behavior Reanalysis

Best-supported source behavior:

1. Load `MAPI32.DLL` with `LoadLibraryA`.
2. If loading fails, return without side effects.
3. Resolve `MAPISendMail` with `GetProcAddress`.
4. If resolution fails, return without freeing the library in the observed decompiler shape? Recheck: Ghidra shows `FreeLibrary` inside the combined success block only. Existing target docs also say the helper frees the library after the send path. This means the current source draft must match the observed behavior and call `FreeLibrary` only after `MAPISendMail` is resolved and attempted; it must not insert a cleanup on the `GetProcAddress` failure path unless later raw assembly contradicts Ghidra.
5. Convert four wide-string roles to ANSI through [UID:000249] `AllocAnsiFromWideDefaultCodepage`:
   - the first input is converted twice, once for `MapiRecipDesc.lpszAddress` and once for `MapiRecipDesc.lpszName`;
   - the second input becomes `MapiMessage.lpszSubject`;
   - the third input becomes `MapiMessage.lpszNoteText`;
   - the fourth input is optional and becomes `MapiFileDesc.lpszPathName` when the input pointer is non-null.
6. Build one `MapiRecipDesc` with `ulRecipClass = MAPI_TO`, no entry ID, and the first input used as both display name and address.
7. If the optional attachment input is non-null, build one `MapiFileDesc` with `nPosition = 0xffffffff` / 4294967295 unsigned, i.e. `(ULONG)-1` (Verified with `int_convert.py`), `lpszPathName = converted attachment path`, and no file-name override or file-type descriptor.
8. Build one `MapiMessage` with:
   - `lpszSubject = converted second input`;
   - `lpszNoteText = converted third input`;
   - message type/date/conversation/originator null;
   - `flFlags = MAPI_RECEIPT_REQUESTED`;
   - `nRecipCount = 1`, `lpRecips = &recipient`;
   - attachment count/pointer set only when the fourth input is non-null.
9. Call `MAPISendMail(0, 0, &message, 0, 0)` and ignore the return value.
10. Free the optional attachment buffer only if the converted pointer is non-null; then free note text, subject, recipient name, and recipient address; then call `FreeLibrary`.

Corrected stale/weak interpretations:

- The first parameter is best named `recipient`, not `sender`, `originator`, or `originatorName`. The structure field being populated is `lpRecips`, not `lpOriginator`; the originator field is zero. Ghidra's generated LLM summary saying "sender/originator" is rejected by the `MapiMessage` layout.
- The second parameter is `subject`.
- The third parameter is `noteText`, `bodyText`, or `messageText`; `noteText` best matches the SDK field.
- The fourth parameter is `attachmentPath` or `optionalAttachmentPath`.
- `message.flFlags = 2` is `MAPI_RECEIPT_REQUESTED`, not `MAPI_SENT`.
- The `MAPISendMail` call flags argument is zero, so the helper does not explicitly pass `MAPI_DIALOG`, `MAPI_LOGON_UI`, or `MAPI_NEW_SESSION`. Any UI behavior would come from the provider/default profile behavior, not from a source flag in this helper.
- The helper does not call `MAPILogon`, does not keep a MAPI session handle, and does not use `MAPISendMailW`.

## Heuristic / Inference Reanalysis And Validation

### Issue 1: Function name and placeholder replacement

- Placeholder checked: `FUN_004f5b20` / raw helper at `0x004f5b20`.
- Best-supported source-facing name: `MapiSendMailHelper`.
- Classification: descriptive/inferred, not original-proof.
- Evidence: literal `MAPI32.DLL`, literal `MAPISendMail`, Simple MAPI stack structures, dynamic `MAPISendMail` function pointer, no class `this` usage, and [UID:0000ML] PlatformApi source route.
- Rejected alternatives:
  - `MAPISendMailHelper` all-caps: rejected because the modern Windows SDK has a Unicode shim with that exact style; using it would imply a Microsoft SDK helper rather than this product-local function.
  - `SendMailPacket` / in-game mail name: rejected because this function uses Win32 Simple MAPI, not NexusTK network packets.
  - `StartupLogo...` or `WinMain...`: rejected because address adjacency is separated by padding and no caller/data relationship ties the function to those neighbors.
  - `SendBugReportMail`: possible feature guess only; no caller, UI string, attachment naming, crash path, or support/contact page proves that feature.
- Impact: the target filename can stay `MapiSendMailHelper`; formal C++ should use `static void MapiSendMailHelper(...)` unless a later symbol/caller proves a feature-specific original name.

### Issue 2: Parameter names and roles

- Best-supported names:
  - `const wchar_t *recipient`
  - `const wchar_t *subject`
  - `const wchar_t *noteText`
  - `const wchar_t *attachmentPath`
- Evidence: Ghidra decompilation and Windows `MapiMessage` field layout map parameter 2 to `lpszSubject`, parameter 3 to `lpszNoteText`, parameter 4 to `MapiFileDesc.lpszPathName`, and parameter 1 to both `MapiRecipDesc.lpszName` and `lpszAddress`.
- Rejected alternatives:
  - `sender`/`originator`: rejected because `lpOriginator` is zero and the populated structure is `lpRecips`.
  - two separate recipient-name/address parameters: rejected because both conversions read `[ebp+0x08]`/`param_1`; there is no fifth argument and no distinct source string.
  - `fileName`: weaker than `attachmentPath`; the structure field populated is `lpszPathName`, while `lpszFileName` remains null.
- Remaining uncertainty: the original source may have named the first argument `to`, `mail`, `address`, or `recipientAddress`. `recipient` is the best neutral source-facing name because the same input fills both MAPI name and address.
- Impact: closes the target page's previous source-facing parameter-name blocker enough for first-draft C++.

### Issue 3: MAPI structure/type interpretation

- Best-supported local types: SDK `MapiMessage`, `MapiRecipDesc`, `MapiFileDesc`, and `LPMAPISENDMAIL`.
- Evidence: stack sizes and field order match the SDK layout: `MapiMessage` is `0x30` / 48 bytes (Verified with `int_convert.py`), `MapiRecipDesc` and `MapiFileDesc` are each `0x18` / 24 bytes (Verified with `int_convert.py`). Ghidra's local variable groupings align with these fields.
- Rejected alternatives:
  - custom product packet/message struct: rejected by dynamic MAPI imports/literals and exact SDK field layout.
  - Unicode `MapiMessageW`: rejected because the function resolves `MAPISendMail` and converts every caller string to ANSI before the call.
  - global/static MAPI structures: rejected because the decompilation constructs stack-local records and no global state is touched except literals/import helpers.
- Impact: type names are resolved; no custom by-type page is required for these SDK structures.

### Issue 4: Message flag constant

- Best-supported interpretation: `message.flFlags = MAPI_RECEIPT_REQUESTED`.
- Evidence: local Windows SDK `MAPI.h` defines `MAPI_RECEIPT_REQUESTED` as `0x00000002` and `MAPI_SENT` as `0x00000004`; the body stores `2`.
- Rejected alternative: generated LLM summary's "likely MAPI_SENT" is wrong for this SDK layout.
- Impact: update target/support docs and C++ with `MAPI_RECEIPT_REQUESTED`.

### Issue 5: Attachment descriptor semantics

- Best-supported interpretation: optional single attachment with `fileDesc.nPosition = (ULONG)-1`, `fileDesc.lpszPathName = attachmentPathAnsi`, `fileDesc.lpszFileName = NULL`, and `fileDesc.lpFileType = NULL`.
- Evidence: Ghidra sets `local_44 = 0`, `local_34 = 0`, `local_3c = 0xffffffff`, and `local_38 = pCVar2` when `param_4 != NULL`. Windows `MapiFileDesc` field order puts `nPosition` at the third `ULONG`, `lpszPathName` after it, then `lpszFileName` and `lpFileType`.
- Rejected alternatives:
  - attachment display filename: rejected because `lpszFileName` remains null.
  - OLE/file-type attachment: rejected because `flFlags` and `lpFileType` remain null.
  - mandatory attachment: rejected because file count/pointer are set only if caller input 4 is non-null.
- Impact: attachment field naming and source draft are safe.

### Issue 6: Conversion helper ownership and names

- Best-supported helper names: [UID:000249] `AllocAnsiFromWideDefaultCodepage` and `FreeAllocatedAnsiString`.
- Evidence: [UID:000249] target now has accepted B002 source-quality analysis and formal C++ naming these helpers; B002 reported exactly five calls from [UID:00022V] to each live ANSI conversion/free helper and rejected MAPI ownership for the broader helper island.
- Rejected alternatives:
  - MAPI-local conversion helpers: rejected because [UID:000249] contains inverse conversion helpers and a UTF-16 file reader not reached by MAPI.
  - generic `StringUtil` owner: rejected by B002 due no broader non-platform use and existing PlatformApi route.
- Impact: [UID:00022V] should reference these source-facing helper names and call them in the formal C++.

### Issue 7: Caller/reachability

- Best-supported current state: no direct static caller is proven; treat this as a retained no-direct-caller PlatformApi helper.
- Evidence: Ghidra export reports `num_callers:0` and `callers:[]`; existing target docs record prior live IDA `xrefs_to` and `callers` empty on 2026-06-06 and reconfirmed on 2026-06-15. The target is still function-shaped code with external API calls and source-authored behavior, so no-caller does not make it padding or compiler-generated.
- Rejected alternatives:
  - impossible/unreachable garbage: rejected by complete function body, API string references, and real conversion/helper calls.
  - direct startup-logo caller: rejected by [UID:00022U] sole caller evidence and padding separation.
  - direct `WinMain` caller: rejected by [UID:00019G] boundary and no xref.
  - indirect callback/table route: not proven. No table/data xref is currently documented; the executable was unavailable here for a fresh pointer scan.
- Remaining blocker: a future full PE/IDA pointer scan could still discover an absolute-function-pointer route. Current evidence does not prove one.
- Impact: no direct caller should stay documented, but it no longer blocks PlatformApi source placement or first-draft C++ because the helper itself has a valid owner/emitter and bounded source behavior.

### Issue 8: Owner/source placement

- Best owner: [UID:0000ML] `PlatformApi`.
- Evidence for:
  - Behavior is Windows platform integration: dynamic `LoadLibraryA`, `GetProcAddress`, Simple MAPI, `FreeLibrary`.
  - It consumes [UID:000249] PlatformApi default-codepage conversion helpers.
  - [UID:0003OT] MAPI lookup strings already route through PlatformApi.
  - Proposed source tree's `platform/PlatformApi.cpp` section explicitly includes default-codepage allocation/free helpers used by MAPI and states IDA confirms the nearby helpers are called by `MapiSendMailHelper`.
  - Parent [UID:0000ML] is `88/85` and has a valid reconstruction path `NexusTK/platform/`.
- Evidence against:
  - No direct feature caller proves whether the original gameplay/UI feature was support/contact/crash-reporting/startup help.
  - PlatformApi is an inferred module, not a symbol-proven original filename.
- Rejected owners:
  - `StartupLogoPanes`: physical neighbor only; no caller/data relationship; [UID:00022U] is separately bounded with own startup-logo route.
  - `WinMain`: successor only; padding separates the helper; [UID:00019G] has no call to this function.
  - `PlatformStringConversionHelpers`: dependency owner, not owner of the MAPI helper.
  - `client_libraries`: meta/dependency index, not a source owner.
  - new `Mail`/`Support` file: too speculative without a caller, UI string, or related cluster.
- Impact: keep `CANONICAL_OWNER:0000ML` and `EMITTER_UIDS:0000ML`. Do not create a new file.

### Issue 9: Range split/merge/container choice

- Best-supported decision: no split.
- Evidence: one contiguous helper body, no interleaved data, documented padding on both sides, no nested child function starts inside the range, and all behavior is one Simple MAPI send operation.
- Rejected alternatives:
  - split attachment branch: not a source-level separate function.
  - merge with startup-logo or WinMain neighbors: rejected by padding and unrelated source owners.
  - move MAPI lookup strings into the executable range: rejected by by-memory range type; keep [UID:0003OT] as separate `.rdata` support child but avoid duplicate source output.
- Impact: update in place; no child creation/rename required.

### Issue 10: Final C++ eligibility

- Eligibility: yes.
- Evidence: target is `RECONSTRUCTABLE:TRUE`, has nonblank `EMITTER_UIDS:0000ML`, the emitter route surfaces to `auto-generated/NexusTK/platform/PlatformApi.cpp`, current average is already `(85 + 87) / 2 = 86`, and this report closes parameter/type/source-placement blockers enough for a bounded first draft.
- Rejected no-code proof: direct feature caller remains unknown, but formal code for a standalone retained helper does not require knowing its caller if the helper is source-authored, bounded, owned, and routable.
- Remaining C++ caveat: original exact name and first-argument source spelling are inferred. Use descriptive names and document the no-caller state.

## Ranked Ownership Analysis

### 1. [UID:0000ML] PlatformApi

- Evidence for: Windows API dynamic-loading helper; Simple MAPI; default-codepage conversion dependency; MAPI lookup string child already routes to PlatformApi; proposed source tree and [UID:0000ML] explicitly include this area; parent clears `85/85`.
- Evidence against: no direct caller identifies final feature context; exact original filename not symbol-proven.
- Decision: accept as current best direct owner/emitter.

### 2. New feature file such as `SupportMail.cpp`, `CrashReport.cpp`, or `ContactSupport.cpp`

- Evidence for: user-visible email helpers often belong to support/contact/crash-report features, and optional attachment could fit diagnostics.
- Evidence against: no caller, no UI text, no crash/reporting xref, no adjacent feature cluster, and no proposed source-tree support for such a file.
- Decision: reject for now; document as speculative future route only if a caller is found.

### 3. StartupLogoPanes

- Evidence for: address-adjacent predecessor.
- Evidence against: predecessor has its own sole startup-logo WndProc caller, separate Bink state, and padding before `0x004f5b20`. MAPI strings/API behavior are unrelated.
- Decision: reject.

### 4. WinMain

- Evidence for: address-adjacent successor near app startup.
- Evidence against: padding before `_WinMain@16`, no caller edge, and `WinMain` doc's behavior/callee list does not include MAPI.
- Decision: reject.

### 5. MAPI lookup string child or conversion helper island as owner

- Evidence for: direct dependencies/children.
- Evidence against: string child and conversion island are support items, not the semantic owner of this send-mail operation.
- Decision: reject as owner; keep them as support docs under PlatformApi.

## Open-Question Closure

| Existing open question/blocker | Closure |
| --- | --- |
| Direct caller not found | Keep documented as no-direct-static-caller/retained helper. This is a reachability caveat, not an ownership or C++ blocker for a bounded PlatformApi helper. |
| Source-facing parameter names unclear | Close with `recipient`, `subject`, `noteText`, and `attachmentPath`; note that `recipient` is used for both MAPI `lpszName` and `lpszAddress`. |
| Message subject/text ambiguity | Close: parameter 2 -> `MapiMessage.lpszSubject`, parameter 3 -> `MapiMessage.lpszNoteText`. |
| `flFlags = 2` meaning unclear/stale generated summary says `MAPI_SENT` | Close: `2` is `MAPI_RECEIPT_REQUESTED`; `MAPI_SENT` is `4`. |
| Attachment descriptor fields unclear | Close: optional `MapiFileDesc` with `nPosition=(ULONG)-1`, `lpszPathName=attachmentPathAnsi`, `lpszFileName=NULL`, `lpFileType=NULL`. |
| Source placement uncertain | Close to current best: PlatformApi. Feature context remains unknown but no stronger source owner exists. |
| Formal C++ blank | Close: first-draft C++ is eligible and should be inserted after supervisor acceptance. |
| MAPI lookup strings as separate emitter child | Close with support policy: literals should be emitted inline by [UID:00022V]; [UID:0003OT] should use a no-op/comment emitter if tooling requires nonblank code. |

## First-Draft C++ Recommendation

Populate [UID:00022V]'s `RECONSTRUCTION_CPP CODE` block with this bounded first draft after supervisor acceptance. It intentionally covers only `0x004f5b20-0x004f5c73` and uses [UID:000249] helper names already accepted in PlatformApi.

```cpp
static void MapiSendMailHelper(const wchar_t *recipient,
                               const wchar_t *subject,
                               const wchar_t *noteText,
                               const wchar_t *attachmentPath)
{
    HMODULE mapiLibrary = LoadLibraryA("MAPI32.DLL");
    if (mapiLibrary == NULL)
        return;

    LPMAPISENDMAIL sendMail =
        (LPMAPISENDMAIL)GetProcAddress(mapiLibrary, "MAPISendMail");
    if (sendMail == NULL)
        return;

    char *recipientAddress = AllocAnsiFromWideDefaultCodepage(recipient);
    char *recipientName = AllocAnsiFromWideDefaultCodepage(recipient);
    char *ansiSubject = AllocAnsiFromWideDefaultCodepage(subject);
    char *ansiNoteText = AllocAnsiFromWideDefaultCodepage(noteText);
    char *ansiAttachmentPath = NULL;

    if (attachmentPath != NULL)
        ansiAttachmentPath = AllocAnsiFromWideDefaultCodepage(attachmentPath);

    MapiRecipDesc recipientDesc = {0};
    recipientDesc.ulRecipClass = MAPI_TO;
    recipientDesc.lpszName = recipientName;
    recipientDesc.lpszAddress = recipientAddress;

    MapiFileDesc fileDesc = {0};
    if (attachmentPath != NULL) {
        fileDesc.nPosition = (ULONG)-1;
        fileDesc.lpszPathName = ansiAttachmentPath;
    }

    MapiMessage message = {0};
    message.lpszSubject = ansiSubject;
    message.lpszNoteText = ansiNoteText;
    message.flFlags = MAPI_RECEIPT_REQUESTED;
    message.nRecipCount = 1;
    message.lpRecips = &recipientDesc;
    if (attachmentPath != NULL) {
        message.nFileCount = 1;
        message.lpFiles = &fileDesc;
    }

    sendMail(0, 0, &message, 0, 0);

    if (ansiAttachmentPath != NULL)
        FreeAllocatedAnsiString(ansiAttachmentPath);
    FreeAllocatedAnsiString(ansiNoteText);
    FreeAllocatedAnsiString(ansiSubject);
    FreeAllocatedAnsiString(recipientName);
    FreeAllocatedAnsiString(recipientAddress);
    FreeLibrary(mapiLibrary);
}
```

C++ caveats to document with the inserted code:

- `MapiSendMailHelper` and parameter names are descriptive, not symbol-proven.
- The missing `FreeLibrary` on the `GetProcAddress` failure path is intentionally preserved from the Ghidra decompilation/observed structure. Do not "fix" it in reconstruction without raw assembly proving the decompiler lost a cleanup edge.
- The function ignores `MAPISendMail`'s return value, as observed.
- If the future project-wide PlatformApi include strategy does not include `MAPI.h`, the owning file needs equivalent declarations for `MapiMessage`, `MapiRecipDesc`, `MapiFileDesc`, and `LPMAPISENDMAIL`; do not invent custom structs while `MAPI.h` is available.

## Recommended Metadata / Score Changes

Target [UID:00022V]:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000ML
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000ML
EMITTER_POSITION_OPTIONAL:
```

Score rationale:

- Completion should rise from `85` to `88` because the report closes parameter names, SDK structure fields, `MAPI_RECEIPT_REQUESTED` flag semantics, optional attachment layout, source-placement alternatives, and C++ eligibility, and supplies a bounded first draft.
- Confidence should rise from `87` to `89` because Ghidra export, prior IDA docs, local MAPI header layout, and support docs agree. It should not go higher because direct caller remains absent, original exact symbol is not proven, live IDA was unavailable during this pass, and no fresh PE pointer scan could be run.

Support scores:

- [UID:0000ML] `PlatformApi`: no score change required. It is already `88/85` and remains a valid parent/emitter.
- [UID:000249] `PlatformStringConversionHelpers`: no score change required. It is already `88/91` after B002 implementation.
- [UID:0003OT] `MapiLookupStrings`: no score change required unless the implementation adds a no-op/comment emitter; then leave `86/91` unless the support edit materially expands the page.

## Supervisor-Owned Coverage Row Text

Replace the existing [UID:00022V] row in `by-memory/-coverage-report.md` at the `0x004f5b20` position, between the existing `0x004f5b1e-0x004f5b20` padding row and the `0x004f5c73-0x004f5c80` padding row, with:

```text
    - [UID:00022V][0x004f5b20-0x004f5c73.MapiSendMailHelper](by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md) 0x004f5b20-0x004f5c73 | function | MapiSendMailHelper : reconstructable : 88% : strong : Source-quality reanalysis confirms retained no-direct-caller PlatformApi Simple MAPI helper: exact `0x153` / 339-byte body, four-parameter `__cdecl` wide-string signature, dynamic `MAPI32.DLL`/`MAPISendMail` lookup, SDK `MapiMessage`/`MapiRecipDesc`/optional `MapiFileDesc` stack layout, one `MAPI_TO` recipient using the first wide string as both name and address, `MAPI_RECEIPT_REQUESTED` message flag, optional attachment path with `nPosition=(ULONG)-1`, five calls to `AllocAnsiFromWideDefaultCodepage`, five cleanup calls to `FreeAllocatedAnsiString`, no proven direct caller/xref route, valid [UID:0000ML] PlatformApi owner/emitter route, and first-draft C++ ready for supervisor-accepted implementation.
```

No auto-generated report should be edited by hand. After target/support docs are implemented and validated, the validator/autogen refresh should change the [UID:00022V] row in `auto-generated/-ag-memory-coverage.md` from `emits`/`no` to `coded`/`yes`.

## Target / Support Implementation Checklist

Implementation pass should edit only accepted target/support docs, with leases as required:

1. [UID:00022V] `by-memory/0x004f5b20-0x004f5c73.MapiSendMailHelper.md`
   - Set `COMPLETION:88`, `CONFIDENCE:89`; keep owner/emitter metadata unchanged.
   - Add/replace behavior detail with the source-quality closure above: `recipient`, `subject`, `noteText`, `attachmentPath`; `MapiMessage`; `MapiRecipDesc`; optional `MapiFileDesc`; `MAPI_TO`; `MAPI_RECEIPT_REQUESTED`; `nPosition=(ULONG)-1`; `MAPISendMail(0,0,&message,0,0)`; ignored return value; exact cleanup order.
   - Preserve no-direct-caller evidence and explicitly recast it as retained no-direct-caller PlatformApi helper status, not final C++ blocker.
   - Add stale-generated-summary correction: `MAPI_SENT` rejected because `MAPI_SENT == 4`, while the helper stores `2`.
   - Insert the first-draft C++ above into formal `RECONSTRUCTION_CPP CODE`.
   - Add a C++ note that the `GetProcAddress` failure path currently returns without `FreeLibrary` because Ghidra/observed structure places `FreeLibrary` only on the successful send path.

2. [UID:0000ML] `by-file/PlatformApi.md`
   - Add [UID:00022V] to likely contents/responsibilities as a retained Simple MAPI send helper using the PlatformApi default-codepage conversion helpers.
   - State that no feature caller is currently proven; PlatformApi is the best direct source owner because the helper is a Win32 platform integration utility.
   - Mention that `MapiLookupStrings` are emitted inline by the helper if support C++ is populated.

3. [UID:000249] `by-memory/0x00599440-0x005995a7.PlatformStringConversionHelpers.md`
   - No required metadata/code change.
   - If edited for cross-reference clarity, add that [UID:00022V] consumes only `AllocAnsiFromWideDefaultCodepage` and `FreeAllocatedAnsiString` to build `MapiMessage`, `MapiRecipDesc`, and optional `MapiFileDesc`.

4. [UID:0003OT] `by-memory/0x0061d0f0-0x0061d118.MapiLookupStrings.md`
   - Add support note that `MAPI32.DLL` and `MAPISendMail` should be emitted as string literals inside [UID:00022V]'s `MapiSendMailHelper`, not as standalone global definitions.
   - If the page remains `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:0000ML`, consider setting formal code to a no-op/comment marker such as:

```cpp
// MAPI lookup string literals are emitted inline by MapiSendMailHelper.
```

5. [UID:00025O] `by-memory/0x0061cf68-0x0061d118.LObjectLogoReadOnlyData.md`
   - Optional support update only if claim-by-claim incorporation requires it: clarify that the MAPI string child belongs to PlatformApi and is represented inline by [UID:00022V]'s helper C++.

6. [UID:00022U] and [UID:00019G] neighbor docs
   - No required edits. They already document padding boundaries. Do not move or merge the MAPI helper into those owners.

7. `by-memory/-coverage-report.md`
   - Do not edit as B-agent. Supervisor should apply the replacement row above after accepted implementation.

Required validation after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [00022V-MapiSendMailHelper-source-quality-removed.md](00022V-MapiSendMailHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If [UID:000249], [UID:0003OT], or [UID:00025O] are edited, run the same scoped validator command for each edited file. Then run:

> Executable block R002 was removed from this report and preserved verbatim in [00022V-MapiSendMailHelper-source-quality-removed.md](00022V-MapiSendMailHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Negative Evidence Summary

- Address adjacency does not prove source ownership. [UID:00022U] and [UID:00019G] are rejected as owners because documented padding separates them and their behavior/caller evidence is unrelated.
- No direct caller is not proof the bytes are dead garbage. The helper has a complete source-shaped body, literal xrefs, imported API behavior, and conversion helper calls.
- Consumer xrefs from MAPI to [UID:000249] do not make [UID:000249] MAPI-owned; B002's accepted report proves the conversion island belongs to PlatformApi.
- `MapiLookupStrings` should not be treated as startup-logo resource data even though they physically sit after startup-logo strings. Their only semantic consumer is this MAPI helper.
- Feature-specific mail/reporting ownership remains speculative without a caller or UI string.

## Final Recommendation

- Apply target metadata `88/89`, owner/emitter unchanged.
- Populate [UID:00022V] first-draft C++ with the bounded `MapiSendMailHelper` draft above.
- Keep source placement in [UID:0000ML] `PlatformApi`.
- Preserve no-direct-caller status as documented reachability evidence, not a no-code proof.
- Update support docs to close parameter/type/flag/literal-emission questions.
- Supervisor should apply the exact by-memory coverage row text above after implementation.

## Follow-Up Actions

- Supervisor: review this report; if accepted, issue an implementation checklist to B003 using the target/support checklist above; apply the supervisor-owned coverage row after B003 implementation validates.
- A-agent/B-agent future work: if a later executable/IDA session is available, run a PE-aware rel32/absolute VA/RVA/table scan for `0x004f5b20` to try to close the final no-direct-caller caveat. This is not required before implementing the helper C++.
- Broader PlatformApi pass: eventually decide final include/header strategy for `MAPI.h`, `Windows.h`, conversion helpers, and `PlatformApi.h` declarations.

## Validator Results

- No by-* docs were edited in this report-only pass, so no scoped validator was run.
- `int_convert.py` was run for cited values:
  - `0x153` -> 339.
  - `0x70` -> 112.
  - `0x30` -> 48.
  - `0x18` -> 24.
  - `0xffffffff` -> 4294967295.

## Changed Files

- Created: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B003\research\00022V-MapiSendMailHelper-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00022V-MapiSendMailHelper-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00022V"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022V-MapiSendMailHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00022V-MapiSendMailHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
