** TARGET-REPORT-UID:00022Y **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00022Y MainMenu ANSI Text Dialog Packet Helpers Source-Quality Report

Assignment: `B003-goal2-mainmenu-ansi-text-dialog-packet-helpers-source-quality-00022Y-20260618`  
Submission id: `019edc0b-f192-7810-816e-2ea4d75d7fc8`  
Agent: `Agent-B003`  
Date: 2026-06-18  

Target:
- [UID:00022Y] `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`
- Current state: `COMPLETION:84`, `CONFIDENCE:88`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000L0`, `EMITTER_UIDS:0000L0`, formal C++ blank.

Recommendation:
- Raise to `COMPLETION:87`, `CONFIDENCE:90`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `CANONICAL_OWNER:0000L0`.
- Keep `EMITTER_UIDS:0000L0`.
- Populate first-draft C++ under [UID:0000L0] `by-file/MainMenuPane.md` / `NexusTK/login/MainMenuPane.cpp`.
- Do not reassign ownership to `AlertPanes`, `PacketBuffer`, `MiscWorkThread`, `MapPane`, or `ScreenDimmer`; this page is a MainMenuPane file-local packet-adapter helper cluster.

## Evidence Checked

Supervisor and agent rules:
- Read `tools/leaser/Agents/Supervisor.md`.
- Read updated `tools/leaser/Agents/Agent-B003/goal.md`; it names this assignment as the current active assignment and confirms report-only handling.
- Read `tools/leaser/Agents/Agent-B003/notes.md`.
- Read `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.

Primary and support documentation:
- [UID:00022Y] `by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md`.
- [UID:0000L0] `by-file/MainMenuPane.md`.
- [UID:00007O] `by-class/MainMenuPane.md`.
- [UID:00019I] `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`.
- [UID:00036Y] `by-memory/0x004f6700-0x004fb62a.MainMenuPaneCore.md`.
- [UID:0000HE] `by-file/AlertPanes.md`.
- [UID:0000FF] `by-class/UrlAlertPane.md`.
- [UID:0001KF] `by-memory/0x00599a40-0x00599cb3.UrlAlertPane.md`.
- [UID:0000S5] `by-global/g_pScreenDimmer.md`.
- [UID:0000C8] `by-class/ScreenDimmer.md`.
- [UID:0000NA] `by-file/ScreenDimmer.md`.
- [UID:00029T] `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`.
- [UID:0000M8] `by-file/PacketBuffer.md`.
- [UID:0001HZ] `by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md`.
- [UID:0003YK] `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`.
- [UID:0003YP] `by-memory/0x00575a10-0x00575abb.PacketBufferOneByteStringReadHelpers.md`.
- [UID:0000SM] `by-global/g_pUrlAlertPane.md`.
- [UID:0000RF] `by-global/g_pMainUiGraph.md`.
- [UID:0002RN] `by-memory/0x00582b30-0x00582d10.StringBaseAssignmentAndReleaseHelpers.md`.
- Current `by-memory/-coverage-report.md` row for [UID:00022Y].
- Current `project-level/-auto-completion-stats.md`.
- Current generated memory coverage under `auto-generated/-ag-memory-coverage.md`.
- Current generated source state for `auto-generated/NexusTK/login/MainMenuPane.cpp`.

Prior-report search:
- Searched Agent-B001/B002/B003 research and executed report trees for `00022Y`, `0x00502e10`, `0x00502e30`, `MainMenuAnsiTextDialogPacketHelpers`, `MainMenuTextUrlStaticString`, and related string/global names.
- No prior dedicated [UID:00022Y] B report was found.
- Prior adjacent reports for [UID:0002BD]/[UID:0002BE] use [UID:00022Y] only as the left neighbor/control boundary and support keeping the `0x0050305c-0x00503060` padding before [UID:00022Z].
- Prior B research for [UID:00029T] supports the stronger conclusion that `0x0069b3d0` is a MiscWorkThread-owned NCA confirm-user URL override string, not a MainMenuPane-owned static.

IDA MCP:
- Tried the local IDA MCP endpoint at `http://127.0.0.1:13337/mcp` with `tools/list`.
- Result: `IDA_MCP_UNAVAILABLE: Unable to connect to the remote server`.
- Continued with existing IDA-backed documentation plus raw PE/Capstone-style checks against the executable. This is not a documentation blocker because the raw boundary, direct-call, pointer-route, byte, and callee checks were independently reproduced.

Raw PE and disassembly evidence:
- Binary checked: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- PE image base: `0x00400000`.
- Relevant sections:
  - `.text`: `0x00401000-0x0060c600`, raw `0x00000400-0x0020ba00`.
  - `.rdata`: `0x0060d000-0x0066c200`, raw `0x0020ba00-0x0026ac00`.
  - `.data`: `0x0066d000-0x0069ce24`, raw `0x0026ac00-0x00278400`.
  - `.rsrc`: `0x0069d000-0x006b2e00`, raw `0x00278400-0x0028e200`.
- `tools/int_convert.py` was used for decimal conversions cited below.

Exact modeled boundaries and padding:
- Preceding padding: `0x00502e0b-0x00502e10`, five `0xcc` bytes.
- First helper: `0x00502e10-0x00502e21`, size `0x11` / 17 bytes.
- Inter-helper padding: `0x00502e21-0x00502e30`, fifteen `0xcc` bytes.
- Second helper: `0x00502e30-0x0050305c`, size `0x22c` / 556 bytes.
- Following padding: `0x0050305c-0x00503060`, four `0xcc` bytes.

Exact bytes for `0x00502e10-0x00502e21`:

```asm
8b 0d 08 ae 69 00 85 c9 74 06 8b 01 6a 01 ff 10 c3
```

Disassembly for `0x00502e10-0x00502e21`:

```asm
00502e10  mov  ecx, dword ptr [0x0069ae08]
00502e16  test ecx, ecx
00502e18  je   0x00502e20
00502e1a  mov  eax, dword ptr [ecx]
00502e1c  push 1
00502e1e  call dword ptr [eax]
00502e20  ret
```

This is the MSVC polymorphic delete/scalar-deleting-destructor call pattern for `g_pScreenDimmer`: load the singleton, check non-null, call virtual slot `+0x00` with deleting flag `1`, return. The source-facing helper is better described as active screen-dimmer destruction/close, not patch-launch preparation.

Disassembly facts for `0x00502e30-0x0050305c`:
- Function prologue establishes SEH and a stack cookie and reserves `0x7dc` / 2012 bytes of stack.
- The packet pointer is loaded from `[ebp+8]` into `esi`.
- Cursor local starts at `1`; subtype byte is read from `packet+1`; cursor becomes `2`.
- The subtype byte is read through `0x00575470`, which is a tiny byte-load / Dinkumware narrow-char helper, not a PacketBuffer semantic reader.
- The function repeats the active screen-dimmer delete pattern inline: load `g_pScreenDimmer` at `0x0069ae08`; if non-null, call virtual slot `+0x00` with deleting flag `1`.
- Subtype dispatch is:
  - `1`: parse URL/text fields and construct `UrlAlertPane` with exit-after-open flag `1`.
  - `2`: parse URL/text fields and construct `UrlAlertPane` with exit-after-open flag `0`.
  - `3`: read a one-byte length-prefixed ANSI string with `0x00575a90`, assign it to `0x0069b3d0`, release the temporary string.
  - Any other subtype returns success with no side effect.
- All successful paths end with `AL=1`; there is no failure return path in normal modeled control flow.

Direct call and hidden route checks:
- `rel32` direct calls to `0x00502e10`: one hit, at `0x004f733a`.
- `rel32` direct calls to `0x00502e30`: one hit, at `0x004f74c2`.
- `rel32` direct calls to `0x00502e21`, `0x0050305c`, and `0x00503060`: no hits.
- VA/RVA/raw dword pattern scans over the PE found no pointer-table/raw-address references to helper starts `0x00502e10`, `0x00502e30`, `0x0050305c`, or `0x00503060`.
- Positive-control pointer scans did find expected VA references for `g_pScreenDimmer` at `0x0069ae08`, the NCA URL override string at `0x0069b3d0`, and `g_pUrlAlertPane` storage at `0x0069b4dc`, so the negative helper-entry pointer result is meaningful.
- The caller at `0x004f733a` and the caller at `0x004f74c2` are both within `MainMenuPane::OnServerMessage` / [UID:00036Y] `MainMenuPaneCore`.
- No vtable, jump-table, raw PE pointer, or hidden direct-address route was found for either helper entry.

Callee and helper identity checks:
- `0x00575470`: byte-load / `std::_Narrow_char_traits<char,int>::to_char_type`-style helper; 975 references. It loads `al = *arg`. This should not be documented as a MainMenu-owned helper or PacketBuffer semantic reader.
- `0x00575480`: [UID:0003YK] `PacketBufferReadUInt16BE`; reads a two-byte big-endian unsigned integer.
- `0x00575a90`: [UID:0003YP] `PacketBufferReadAnsiBytes8`; reads a one-byte length-prefixed ANSI string into caller-provided string storage and advances the packet cursor.
- `0x00582bb0`: [UID:0002RN] StringBase ANSI assignment helper.
- `0x00582b30`: [UID:0002RN] StringBase ANSI release/destructor helper.
- `0x004f4aa0`: allocation helper used before `UrlAlertPane` construction; allocation size pushed by this target is `0x278` / 632 bytes.
- `0x00599a40`: [UID:0001KF] `UrlAlertPane` constructor.
- `MultiByteToWideChar`: used for ANSI/multibyte prompt text conversion to UTF-16.
- `0x005c7655`: compiler/runtime range-check failure helper reached only if the wide-string terminator index would exceed the local buffer bounds.
- `0x005c772f`: stack-cookie/security epilogue helper.

UrlAlertPane relationship:
- [UID:0001KF] and [UID:0000FF] show the constructor stores URL buffer state at `this+0x270` and an exit/open flag at `this+0x274`.
- Constructor xrefs are `0x00503034`, `0x00513f7e`, and `0x0051402f`.
- The `0x00503034` call is the target's MainMenu helper; the other two are the MapPane analog.
- The first constructor argument used by subtype `1` is `1`; subtype `2` uses `0`. Given the UrlAlertPane class field at `+0x274`, the defensible semantic name is `exitAfterOpen`, not "clickable" versus "non-clickable." The dialog is URL-capable in both cases; the flag controls post-confirm/open behavior.
- The parent/context argument in this MainMenu helper is `g_pMainUiGraph` at `0x0067aba4`, not a MainMenuPane `this` pointer. The MapPane analog passes `this`.

MapPane analog check:
- Disassembled `0x00513da0-0x0051408f` as a related in-game packet handler.
- It uses the same subtype byte, the same URL/text parsing pattern, the same `UrlAlertPane` constructor for subtypes `1` and `2`, and the same assignment to `0x0069b3d0` for subtype `3`.
- The MapPane handler also has a subtype `0` browser/dialog path that is not present in this MainMenu helper.
- This supports treating the MainMenu target as a source-authored opcode-family packet adapter, not as a UrlAlertPane-owned helper or dead duplicate.

Static/global string relationship:
- [UID:00029T] now identifies `0x0069b3d0` as an NCA auth confirm-user URL override static string owned by [UID:0000LG] `MiscWorkThread`, with the old `MainMenuTextUrlStaticString` label retained for generated/report compatibility.
- This target writes that string for subtype `3`; it does not own the global or determine the later NCA-use semantics.
- The only semantic reader is `MiscWorkThread::ProcessNCAUpdate` at `0x00527bb0`, which uses the string as an override URL and otherwise falls back to the obfuscated default URL page.

Generated/source state:
- `auto-generated/NexusTK/login/MainMenuPane.cpp` exists but is zero bytes.
- `auto-generated/-ag-memory-coverage.md` lists [UID:00022Y] as generated through root [UID:0000L0], code present `no`.
- `project-level/-auto-completion-stats.md` lists [UID:00022Y] at `84/88`, average `86.0`.
- Current validator dry run for the target documentation file succeeded: `python tools/validator.py --mode file --file by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md` returned `ok:1`.
- The same validator run reports known unrelated generated-source noops and an unrelated `autogen_cpp_conflict` for [UID:0000K5] `auto-generated/NexusTK/input/IMEPanes.cpp`; this does not affect [UID:00022Y].

## Heuristic / Inference Reanalysis And Validation

### Helper at `0x00502e10`

Best source-facing name:
- `DestroyActiveScreenDimmer`.

Recommended signature:

```cpp
static void DestroyActiveScreenDimmer();
```

Evidence:
- Exact body loads only `g_pScreenDimmer` from `0x0069ae08`.
- If the pointer is non-null, the body calls the first virtual slot with pushed argument `1`.
- This is the normal MSVC code shape for `delete g_pScreenDimmer` when the static type is polymorphic and has a scalar deleting destructor at vslot `0`.
- The only direct caller is `MainMenuPane::OnServerMessage` at `0x004f733a`.

Rejected alternatives:
- `PreparePatchLaunch`: rejected. [UID:0000L0] currently uses this as a tentative name, but the body contains no patch-launch state, launch path, version check, packet parse, or launch setup. It only destroys/closes the active dimmer singleton. The name is caller-context biased.
- `ClearScreenDimmerSingleton`: rejected as the exact body for this target. [UID:0000S5]/[UID:0001GB] document a singleton clear helper elsewhere, but this function does not store zero into the global. It invokes deletion through the object vtable. The destructor path may eventually clear the singleton, but that is downstream behavior, not the direct operation here.
- `ScreenDimmerScalarDeletingDestructorWrapper`: rejected for source-facing docs. It describes the compiler lowering rather than the likely source statement.
- `CloseActiveScreenDimmer`: acceptable as an alternate descriptive name, but `DestroyActiveScreenDimmer` better captures the deleting-destructor flag `1`.

Remaining uncertainty:
- The exact original source spelling is not provable from current evidence.
- The exact ScreenDimmer vslot `0` source name should remain a ScreenDimmer-class question. This target should document the source-level operation as `delete g_pScreenDimmer`, not invent a public method name for the vslot.

Score/C++ impact:
- This uncertainty does not block first-draft C++; the machine pattern supports a clean source statement and the helper's source route is exact enough for `87/90`.

### Helper at `0x00502e30`

Best source-facing name:
- `HandleAnsiTextUrlDialogPacket`.

Recommended signature:

```cpp
static bool HandleAnsiTextUrlDialogPacket(const unsigned char *packet);
```

Evidence:
- Direct caller `0x004f74c2` passes one packet pointer argument from `MainMenuPane::OnServerMessage`.
- No `this` pointer is consumed by the helper; the helper uses globals and the packet pointer only.
- The helper returns `AL=1` on all modeled normal paths, matching a `bool` success result.
- It handles opcode-family payloads for ANSI text and URL alert dialog construction, plus an NCA URL override string update.
- [UID:0000L0] and [UID:00036Y] already route the call through MainMenuPane server-message handling for opcode `0x66`.

Rejected alternatives:
- `sub_502e30`: rejected because packet layout, callee set, direct caller, and dialog effects are now understood.
- `HandleAnsiTextDialogPacket`: acceptable but less complete because subtypes `1` and `2` are URL alert dialogs and subtype `3` writes a URL override string.
- `UrlAlertPanePacketHandler`: rejected because subtype `3` does not construct UrlAlertPane and because the handler is a MainMenu packet adapter. `UrlAlertPane` owns the dialog class, not this network opcode helper.
- `PacketBuffer` helper ownership/name: rejected. The target calls PacketBuffer readers but is not a generic buffer helper.
- `MapPane` shared handler: rejected. A MapPane analog exists at `0x00513da0`, but the target has MainMenu-specific parent/context (`g_pMainUiGraph`) and direct MainMenu caller.

Remaining uncertainty:
- Exact original source spelling is not provable. `HandleAnsiTextUrlDialogPacket` is the highest-probability descriptive name suitable for source-quality docs and draft C++.

Score/C++ impact:
- This no longer blocks first-draft C++; a descriptive inferred name is acceptable under the current policy.

### Packet opcode and subtype layout

Best current protocol description:
- `MainMenuPane::OnServerMessage` routes opcode `0x66` to this helper.
- The helper's first semantic read is `packet[1]`, the subtype byte.
- The cursor starts at `1`, advances to `2` after subtype read, and subtype payload begins at `packet+2`.

Subtype `1`:
- Reads a two-byte big-endian URL byte length.
- Treats the following bytes as an ANSI URL buffer and passes pointer plus byte length directly to `UrlAlertPane`.
- Reads a two-byte big-endian message byte length after the URL bytes.
- Converts that many ANSI/multibyte message bytes to UTF-16 with `MultiByteToWideChar(0, 0, ..., 999)`.
- NUL-terminates the wide buffer.
- Constructs `UrlAlertPane` with parent/context `g_pMainUiGraph`, the wide prompt text, the URL pointer/length, and `exitAfterOpen = true`.

Subtype `2`:
- Same URL/text parsing as subtype `1`.
- Constructs `UrlAlertPane` with `exitAfterOpen = false`.

Subtype `3`:
- Reads a one-byte length-prefixed ANSI string with `PacketBufferReadAnsiBytes8`.
- Assigns that temporary string into the global string at `0x0069b3d0`.
- The global is best named in this target as `g_ncauthConfirmUserUrlOverride` or `g_ncauthConfirmUserUrlOverrideString`, following [UID:00029T]'s current semantic title. The old `MainMenuTextUrlStaticString` label should be retained only as a compatibility alias/page filename.

Other subtypes:
- No action.
- Return success.

Rejected alternatives:
- "Subtype `1` clickable, subtype `2` non-clickable": rejected as the primary semantic name. Prior generated comments use this wording, but UrlAlertPane evidence points to an exit-after-open flag at `+0x274`. Both subtypes are URL alert flows; the constructor flag controls post-confirm behavior.
- "Subtype `3` main-menu text string": rejected as ownership/semantic wording. The strongest current evidence names it an NCA confirm-user URL override string used by MiscWorkThread.
- "Packet offset `0` subtype": rejected. The helper reads `packet+1`; offset `0` is the opcode byte or dispatcher-level command already handled by the caller.

Remaining uncertainty:
- The external protocol name for opcode `0x66` is not proven. A descriptive name such as `ServerTextUrlDialogPacket` or `AnsiTextUrlDialogPacket` should be used until a packet enum source name is found.
- Exact subtype enum names are not proven; recommended descriptive names:
  - `MAIN_MENU_TEXT_URL_EXIT_AFTER_OPEN = 1`
  - `MAIN_MENU_TEXT_URL_STAY_OPEN = 2`
  - `MAIN_MENU_NCA_CONFIRM_URL_OVERRIDE = 3`

Score/C++ impact:
- The lack of exact enum spellings does not block source-quality improvement. Use descriptive enum constants or comments in draft C++.

### ANSI/text/URL buffer types and conversion

Best current type interpretation:
- Packet argument: `const unsigned char *packet` or `const BYTE *packet`.
- Subtype: `unsigned char`.
- Cursor/offset: signed `int`.
- URL length: `unsigned short` from `PacketBufferReadUInt16BE`.
- URL bytes: `const char *` pointer into the packet payload; the target does not allocate or NUL-terminate the URL before passing it to `UrlAlertPane`.
- Prompt/message length: `unsigned short` from `PacketBufferReadUInt16BE`.
- Prompt/message bytes: ANSI/multibyte `const char *`.
- Prompt/message wide buffer: stack `wchar_t messageText[1000]` equivalent. The API limit is `0x3e7` / 999 wide characters; the code writes one terminator after the returned count.
- Subtype `3` string: `StringBase`/project ANSI string object, read via `PacketBufferReadAnsiBytes8`, assigned through the StringBase assignment helper, then released.

Rejected alternatives:
- "URL field is NUL-terminated in packet": not supported. The target passes explicit URL length to the `UrlAlertPane` constructor.
- "Text field is wide in packet": rejected. The target calls `MultiByteToWideChar` on packet bytes.
- "Subtype `3` uses a two-byte length": rejected. The callee is `PacketBufferReadAnsiBytes8`, not the two-byte scalar helper.

Remaining uncertainty:
- Exact project string class name in source may be `String`, `StringBase`, or a typedef. Existing support docs use `StringBase`; this report uses `StringBase` as the best current support-doc type.

Score/C++ impact:
- This is sufficient for first-draft C++ with typed local variables and descriptive packet comments.

### `g_pScreenDimmer` and virtual teardown

Best current source interpretation:
- `g_pScreenDimmer` at `0x0069ae08` is a global pointer to the active screen-dimmer/modal-overlay pane.
- The target's vslot `+0x00` call with argument `1` is source-level `delete g_pScreenDimmer`, compiled through a scalar deleting destructor.
- The target does not itself assign `g_pScreenDimmer = 0`.

Rejected alternatives:
- Direct call to `ScreenDimmerSingletonClear`: not the machine shape.
- Direct `Pane::Close()` method: not provable; the flag and first-vslot call fit deleting destructor more strongly.

Remaining uncertainty:
- The exact static type could be `ScreenDimmer *` or a base pane/control interface pointer. [UID:0000S5] already carries that global-type uncertainty.

Score/C++ impact:
- Use `delete g_pScreenDimmer` in first-draft C++ and keep the exact global type question in ScreenDimmer/global docs, not as a blocker for this target.

### `UrlAlertPane` ownership boundary

Best current source placement:
- `UrlAlertPane` class, vtable, and constructor remain owned by [UID:0000HE] `AlertPanes.cpp`.
- This target constructs a `UrlAlertPane` as a consumer/adaptor in `MainMenuPane.cpp`.
- The target should document constructor parameters as:

```cpp
UrlAlertPane(bool exitAfterOpen,
             void *parentOrUiGraph,
             const wchar_t *messageText,
             const char *urlBytes,
             int urlLength);
```

The exact formal type of the second parameter should follow AlertPanes support docs; in this target it is the global `g_pMainUiGraph`.

Rejected alternatives:
- Moving the helper under [UID:0000HE]: rejected because direct callers and packet dispatch belong to MainMenuPane.
- Treating `UrlAlertPane` allocation as a generated artifact with no source: rejected. Direct constructor xrefs show normal source construction from packet handlers.

Remaining uncertainty:
- Exact constructor parameter names are inferred. `exitAfterOpen`, `parentOrUiGraph`, `messageText`, `urlBytes`, and `urlLength` are the best descriptive names.

Score/C++ impact:
- Sufficient for target C++; support docs should receive these parameter names as inferred/descriptive rather than raw stack offsets.

### Static string/global naming

Best current name:
- `g_ncauthConfirmUserUrlOverrideString` or `g_ncauthConfirmUserUrlOverride`.

Evidence:
- [UID:00029T] names the data semantically as an NCA auth confirm-user URL override static string.
- This target and the MapPane analog write the string.
- `MiscWorkThread::ProcessNCAUpdate` reads it as the URL override for confirm-user/NCA flow.

Rejected alternatives:
- `MainMenuTextUrlStaticString`: stale/generated page filename; acceptable as alias only.
- MainMenuPane ownership: rejected by the sole semantic reader and [UID:00029T]'s owner/emitter state.

Remaining uncertainty:
- Exact original global variable spelling is unknown. Use [UID:00029T]'s semantic name in target docs and avoid claiming original spelling.

Score/C++ impact:
- Does not block C++; descriptive global name is enough for draft.

### Source placement and owner ranking

Accepted owner:
1. [UID:0000L0] `MainMenuPane.cpp`.

Evidence:
- Both direct callers are in `MainMenuPane::OnServerMessage`.
- [UID:0000L0] already lists both helpers in proposed contents.
- The packet dispatcher context is the main-menu login/account server-message path.
- The handler uses `g_pMainUiGraph`, matching login/main-menu UI state rather than an in-game `MapPane` receiver.

Rejected alternatives:
2. [UID:0000HE] `AlertPanes.cpp`: rejected. It owns `UrlAlertPane`, not this network packet adapter.
3. [UID:0000M8] `PacketBuffer.cpp`: rejected. PacketBuffer only supplies readers.
4. [UID:0000LG] `MiscWorkThread`: rejected for this target. It owns the static string and reader/use site, not the packet writer.
5. `MapPane.cpp`: rejected. It has an analogous opcode-family handler, but the MainMenu target is independently called and uses MainMenu UI globals.
6. [UID:0000NA] `ScreenDimmer.cpp`: rejected. This target consumes/deletes the active dimmer but is driven by MainMenu packet handling.

Emitter:
- Keep [UID:0000L0].

Split/range:
- No required split for source-quality application.
- The modeled range is a coherent cluster of two MainMenu file-local helpers separated by `0xcc` padding. A future exact-child split could be created if the supervisor wants non-overlapping helper pages, but that is optional and not necessary to resolve source placement, score, or C++ readiness.
- The inter-helper padding row at `0x00502e21-0x00502e30` and following padding row at `0x0050305c-0x00503060` remain valid ignored-code/padding documentation.

### Formal C++ readiness

The stale "below 95/95" or generic "names provisional" rationale should be removed.

Reasons formal C++ is now appropriate:
- Target is reconstructable and already routes to a source emitter.
- Direct callers are known and source-facing.
- Hidden pointer/table routes were checked and not found.
- All material callees have defensible support-doc names.
- Packet fields and subtype behavior are understood enough for readable source.
- Remaining exact-name uncertainty can be handled by inferred descriptive names, which is allowed under current draft-code policy.

No-code proof is not applicable. This is not read-only compiler data, not dead unowned padding, and not a pure runtime artifact. It is source-authored packet-handling logic.

## Recommended Metadata And Score Changes

For [UID:00022Y]:

```yaml
COMPLETION: 87
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 0000L0
EMITTER_UIDS: 0000L0
```

Rationale:
- Completion rises because the previous source-facing helper-name, packet-field, global/string ownership, `UrlAlertPane` boundary, and stale C++ readiness blockers are now resolved or have high-probability descriptive names.
- Confidence rises because raw PE checks validated boundaries, padding, body bytes, direct callers, no hidden pointer routes, callee identities, and exact subtype parsing.
- Confidence should not exceed 90 yet because live IDA MCP was unavailable and exact original source spellings for helper names, packet enum constants, and the project string typedef are not proven.

Do not change:
- `RECONSTRUCTABLE`.
- `CANONICAL_OWNER`.
- `EMITTER_UIDS`.

Recommended source-quality summary replacement for the target:

```text
This page contains two MainMenuPane file-local packet helpers: `DestroyActiveScreenDimmer` at `0x00502e10-0x00502e21` and `HandleAnsiTextUrlDialogPacket` at `0x00502e30-0x0050305c`. Raw PE recheck on 2026-06-18 confirms the first helper is a 17-byte active-screen-dimmer delete wrapper (`g_pScreenDimmer`, vslot `+0x00`, deleting flag `1`) with sole direct caller `MainMenuPane::OnServerMessage+0x5ba` (`0x004f733a`). The second helper is a 556-byte opcode `0x66` payload handler with sole direct caller `MainMenuPane::OnServerMessage+0x742` (`0x004f74c2`). It reads subtype `packet[1]`, destroys any active screen dimmer, handles subtypes `1` and `2` by reading two-byte big-endian URL and prompt-text lengths, converting ANSI prompt bytes to a stack UTF-16 buffer with `MultiByteToWideChar`, and constructing `UrlAlertPane` with `g_pMainUiGraph` plus exit-after-open flag `1` or `0`; subtype `3` reads a one-byte length-prefixed ANSI string with `PacketBufferReadAnsiBytes8` and assigns it to the MiscWorkThread-owned NCA confirm-user URL override string at `0x0069b3d0`; other subtypes return success without side effects. VA/RVA/raw pointer scans found no helper-entry table routes, and the prior blank-C++ rationale is stale because this is source-authored, reconstructable, and owner/emitter-routed through [UID:0000L0].
```

## First-Draft C++ Recommendation

Recommended formal C++ should be placed under [UID:0000L0] `MainMenuPane.cpp` as file-local helpers. The code below intentionally uses descriptive inferred names rather than raw addresses. It also uses source-level `delete g_pScreenDimmer`; the binary lowers that statement to the observed virtual scalar-deleting-destructor call with flag `1`.

```cpp
static void DestroyActiveScreenDimmer()
{
    if (g_pScreenDimmer != 0)
        delete g_pScreenDimmer;
}

static bool HandleAnsiTextUrlDialogPacket(const unsigned char *packet)
{
    int offset = 1;
    unsigned char subtype = packet[offset++];

    DestroyActiveScreenDimmer();

    if (subtype == 1 || subtype == 2) {
        unsigned short urlLength = PacketBufferReadUInt16BE(packet + offset);
        const char *urlText = (const char *)(packet + offset + 2);
        offset += 2 + urlLength;

        unsigned short messageLength = PacketBufferReadUInt16BE(packet + offset);
        offset += 2;

        wchar_t messageText[1000];
        int wideLength = MultiByteToWideChar(
            0,
            0,
            (const char *)(packet + offset),
            messageLength,
            messageText,
            999);
        messageText[wideLength] = 0;

        new UrlAlertPane(
            subtype == 1,
            g_pMainUiGraph,
            messageText,
            urlText,
            urlLength);
    } else if (subtype == 3) {
        StringBase overrideUrl;
        PacketBufferReadAnsiBytes8(&overrideUrl, packet, &offset);
        g_ncauthConfirmUserUrlOverrideString = overrideUrl;
    }

    return true;
}
```

Supervisor implementation notes for formal C++:
- If the formal source style requires exact binary allocation shape, replace the high-level `new UrlAlertPane(...)` expression with an explicit allocation/placement-new block. The binary allocates `0x278` / 632 bytes and skips the constructor if allocation returns null.
- If the formal support type for the global string is not `StringBase`, substitute the project string typedef used by [UID:00029T] and [UID:0003YP]. Do not use `dword_69B3D0` in formal C++.
- If the formal support type for `g_pMainUiGraph` is known in [UID:0000RF], use that type for the constructor argument instead of `void *`.
- The compiler inlined or duplicated the dimmer-delete block in `0x00502e30`; the draft calls `DestroyActiveScreenDimmer()` for source clarity. If the supervisor wants closer machine-shape draft code, inline the two-line delete block in `HandleAnsiTextUrlDialogPacket` while keeping the same helper at `0x00502e10`.
- Do not encode the runtime helper `0x00575470` in C++; source should read `packet[offset++]`.

## Exact Supervisor Changes Required

### Target Page [UID:00022Y]

Replace stale helper-name/source-quality wording with the following placement-ready text:

```text
Source-facing names and signatures:
- `0x00502e10-0x00502e21`: `static void DestroyActiveScreenDimmer();`
- `0x00502e30-0x0050305c`: `static bool HandleAnsiTextUrlDialogPacket(const unsigned char *packet);`

`DestroyActiveScreenDimmer` loads `g_pScreenDimmer` at `0x0069ae08`, checks for null, and calls the object's first vtable slot with deleting flag `1`. This is the MSVC lowering of `delete g_pScreenDimmer` for a polymorphic object, not a raw singleton-clear store. The helper has one direct caller at `0x004f733a` in `MainMenuPane::OnServerMessage`.

`HandleAnsiTextUrlDialogPacket` is the MainMenuPane opcode `0x66` payload helper. It receives the packet pointer, reads subtype `packet[1]`, advances the cursor to payload offset `2`, deletes any active `g_pScreenDimmer`, and returns `true` on all modeled normal paths. Subtypes `1` and `2` read a two-byte big-endian URL length, pass the following URL byte span directly to `UrlAlertPane`, read a two-byte big-endian prompt-text length, convert that ANSI prompt text to a stack UTF-16 buffer with `MultiByteToWideChar(0, 0, ..., 999)`, NUL-terminate it, and construct `UrlAlertPane` with `g_pMainUiGraph`, the prompt text, URL pointer/length, and `exitAfterOpen` set to `true` for subtype `1` and `false` for subtype `2`. Subtype `3` reads a one-byte length-prefixed ANSI string with `PacketBufferReadAnsiBytes8`, assigns it to the MiscWorkThread-owned NCA confirm-user URL override string at `0x0069b3d0`, and releases the temporary string. Other subtype values do nothing and return success.

Raw PE recheck on 2026-06-18 confirms `0x00502e0b-0x00502e10` is five bytes of `0xcc`, `0x00502e10-0x00502e21` is a 17-byte function, `0x00502e21-0x00502e30` is fifteen bytes of `0xcc`, `0x00502e30-0x0050305c` is a 556-byte function, and `0x0050305c-0x00503060` is four bytes of `0xcc`. Direct rel32 callers are limited to `0x004f733a` for the dimmer helper and `0x004f74c2` for the packet helper. VA/RVA/raw pointer scans found no helper-entry pointer-table routes.
```

Replace stale blank-C++ rationale with:

```text
Formal C++ should be populated as first-draft MainMenuPane file-local helper code. The previous blank-C++ reason based on a 95/95 gate is stale. Exact original helper and enum spellings remain unproven, but descriptive names `DestroyActiveScreenDimmer`, `HandleAnsiTextUrlDialogPacket`, and subtype comments are supported by caller, callee, packet-layout, and global-owner evidence. No target-specific no-code proof applies because this is source-authored packet-handling logic, not read-only compiler data or unreachable padding.
```

### [UID:0000L0] `by-file/MainMenuPane.md`

In the proposed contents / helper inventory, replace the old tentative row/name:

```text
`PreparePatchLaunch_502E10` / `0x00502e10-0x00502e21`
```

with:

```text
`DestroyActiveScreenDimmer` / `0x00502e10-0x00502e21`: file-local MainMenu helper that deletes the active `g_pScreenDimmer` if present. Raw body is `g_pScreenDimmer` null check plus virtual scalar-deleting-destructor call with flag `1`; sole direct caller is `MainMenuPane::OnServerMessage` at `0x004f733a`.
```

Replace the current opcode helper name:

```text
`HandleAnsiTextDialogPacket_502E30`
```

with:

```text
`HandleAnsiTextUrlDialogPacket` / `0x00502e30-0x0050305c`: file-local opcode `0x66` payload helper called from `MainMenuPane::OnServerMessage` at `0x004f74c2`; handles subtype `1`/`2` URL alert dialog packets and subtype `3` NCA confirm-user URL override assignment.
```

Add or update source placement note:

```text
[UID:00022Y] remains emitted by `MainMenuPane.cpp`. `UrlAlertPane` construction is a dependency on [UID:0000HE] `AlertPanes.cpp`; the NCA confirm-user URL override string at `0x0069b3d0` remains owned by [UID:0000LG]/[UID:00029T]; PacketBuffer readers remain owned by [UID:0000M8]. These dependencies do not move packet-handler ownership out of MainMenuPane.
```

### [UID:00007O] `by-class/MainMenuPane.md`

Add or replace a local-helper note:

```text
MainMenuPane server-message handling owns two file-local helpers at [UID:00022Y]: `DestroyActiveScreenDimmer` (`0x00502e10-0x00502e21`) and `HandleAnsiTextUrlDialogPacket` (`0x00502e30-0x0050305c`). They are not class virtual methods and consume no `this` pointer; both are reached only from `MainMenuPane::OnServerMessage`.
```

### [UID:00036Y] `MainMenuPaneCore`

Where `OnServerMessage` callouts are described, update names:

```text
`0x004f733a` calls [UID:00022Y] `DestroyActiveScreenDimmer`.
`0x004f74c2` calls [UID:00022Y] `HandleAnsiTextUrlDialogPacket` for opcode `0x66`.
```

### [UID:0000FF] / [UID:0001KF] `UrlAlertPane`

Add or verify this constructor-use note:

```text
The MainMenu opcode `0x66` helper [UID:00022Y] constructs `UrlAlertPane` at call site `0x00503034`. Subtypes `1` and `2` share the same URL/prompt-text field layout; the constructor flag differs (`1` for subtype `1`, `0` for subtype `2`) and should be documented as the `exitAfterOpen` behavior stored at `UrlAlertPane+0x274`, not as ownership of the packet helper.
```

### [UID:00029T] `MainMenuTextUrlStaticString`

If the support page still exposes the old generated name as the primary semantic name, change references from:

```text
MainMenuTextUrlStaticString
```

to:

```text
NCA confirm-user URL override string (`MainMenuTextUrlStaticString` compatibility label)
```

Add this cross-reference if not already present at same-or-greater detail:

```text
[UID:00022Y] subtype `3` is one of the writer paths. It reads a one-byte length-prefixed ANSI string from the opcode `0x66` payload with `PacketBufferReadAnsiBytes8` and assigns it to this global; later MiscWorkThread NCA processing is the semantic reader/owner.
```

### [UID:0000M8] / [UID:0001HZ] PacketBuffer Support

No ownership change is recommended. If [UID:00022Y] currently calls `0x00575470` a PacketBuffer helper, replace that wording with:

```text
`0x00575470` is a tiny narrow-char byte-load helper used to read `packet[1]`; the semantic PacketBuffer readers used by [UID:00022Y] are `PacketBufferReadUInt16BE` at `0x00575480` and `PacketBufferReadAnsiBytes8` at `0x00575a90`.
```

### Generated Source / Emitter

When generated source is populated for [UID:0000L0], include [UID:00022Y]'s two helpers in `auto-generated/NexusTK/login/MainMenuPane.cpp`. The current file is empty, so this will be a new source contribution rather than a conflict with existing generated code.

Do not edit generated files directly in this B-agent pass.

## Coverage Report Replacement Text

Current row placement:
- File: `by-memory/-coverage-report.md`
- Replace the existing [UID:00022Y] row in the `0x00502e10-0x0050305c` location. Keep surrounding padding rows intact unless the supervisor chooses a future exact-child split.

Exact replacement row:

```text
    - [UID:00022Y][0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers](by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md) 0x00502e10-0x0050305c | MainMenu ANSI URL/text packet helper cluster | MainMenuAnsiTextDialogPacketHelpers : reconstructable : 87% : very strong : B003 2026-06-18 PE/Capstone recheck confirms exact modeled helpers `0x00502e10-0x00502e21` and `0x00502e30-0x0050305c`, 5/15/4 byte `0xcc` padding, sole rel32 callers `0x004f733a` and `0x004f74c2`, no VA/RVA/raw pointer-table routes to helper starts, `DestroyActiveScreenDimmer` delete pattern through `g_pScreenDimmer`, opcode `0x66` subtype field at `packet+1`, subtypes `1`/`2` two-byte URL/text lengths with `PacketBufferReadUInt16BE`, ANSI-to-wide prompt conversion capped at 999 chars, `UrlAlertPane` construction with `g_pMainUiGraph` parent and exit-after-open flag 1/0, subtype `3` `PacketBufferReadAnsiBytes8` assignment to MiscWorkThread-owned NCA confirm-user URL override string, non-action subtypes returning success, and first-draft file-local C++ under [UID:0000L0].
```

No other coverage row is required for this assignment.

## Validation Commands

Commands run or recommended for supervisor validation:

> Executable block R001 was removed from this report and preserved verbatim in [00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md](00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Observed result:
- `ok:1` for the target file.
- Unrelated generated-source status still includes a known `autogen_cpp_conflict` for [UID:0000K5] and multiple generated noops; [UID:00022Y]/[UID:0000L0] remains a no-op only because `auto-generated/NexusTK/login/MainMenuPane.cpp` has no assembled code yet.

Recommended after supervisor applies docs/coverage/source updates:

> Executable block R002 was removed from this report and preserved verbatim in [00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md](00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Suggested grep/state checks:

> Executable block R003 was removed from this report and preserved verbatim in [00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md](00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Remaining Blockers

No blocker remains that should keep [UID:00022Y] below the current draft-code gate or keep formal C++ blank.

Residual uncertainties to preserve honestly:
- Exact original helper names are not recoverable from current evidence. `DestroyActiveScreenDimmer` and `HandleAnsiTextUrlDialogPacket` are high-probability descriptive names based on body, callers, and callee evidence.
- Exact external protocol enum names for opcode `0x66` subtypes `1`, `2`, and `3` are not proven. The behavior is proven enough to use descriptive constants/comments.
- Exact project string typedef for the subtype `3` local/global may be `StringBase` or a project typedef wrapping it. Support docs currently justify `StringBase` as the best available type.
- Exact static type of `g_pScreenDimmer` remains a global/support-doc issue. This target only requires the source-level delete semantics, which are strongly supported by the vslot-0 deleting-destructor call with flag `1`.
- IDA MCP was unavailable during this pass; raw PE checks and existing IDA-backed documentation covered the needed evidence. If live IDA later disagrees on a symbol name, update the descriptive names but keep the ownership and behavior conclusions unless caller/callee evidence changes.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"00022Y"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/00022Y-MainMenuAnsiTextDialogPacketHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00022Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
