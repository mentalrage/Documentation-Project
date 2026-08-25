** TARGET-REPORT-UID:00029T **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:00029T] MainMenuTextUrlStaticString Ownership Research

## Final Recommendation

Assign [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) to [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md) / `NexusTK/app/MiscWorkThread.cpp`.

Treat the item as a process-wide NCA confirm-user URL override static string, not as MainMenu-owned UI text. A better descriptive label is `NcauthConfirmUserUrlOverrideStaticString`; the current filename can remain until a supervisor-approved rename pass, but the parent/routing should not remain blank.

Recommended target-page routing:

- `RECONSTRUCTABLE:TRUE`
- `AUTOGEN_PARENT_UID:0000LG`
- `COMPLETION:88`
- `CONFIDENCE:92`
- no final `RECONSTRUCTION_CPP` yet

The decisive evidence is that the only semantic consumer is `ProcessNCAUpdate` at `0x00527bb0`, already owned by `MiscWorkThread.cpp`. That worker first tests `dword_69B3D0`; if non-empty, it copies the string into `szUrl` and opens that URL. If empty, it decodes and formats the built-in fallback URL at [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md), which is already attached to the same [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md) parent. The MainMenuPane and MapPane paths are packet-state writers for opcode `0x66` / subtype `3`; they do not consume the value and are weaker declaration owners.

No split is required. The range is already an exact four-byte static string/object handle with clean neighboring boundaries, exactly six live address occurrences, and no hidden pointer-table refs. No new by-memory child page is needed.

Rejected owner summary:

- [UID:0000L0][MainMenuPane](../../../../../by-file/MainMenuPane.md): writes the value from pre-login packet opcode `0x66`, but never reads or uses it; also the file page is below the strict confidence gate.
- [UID:0000L3][MapPane](../../../../../by-file/MapPane.md): writes the same packet subtype while in-game, but never reads or owns the auth URL behavior.
- [UID:0000M0][NexonclubRegistrationDialog](../../../../../by-file/NexonclubRegistrationDialog.md): queues NCA work and consumes `ncauth::Notification`, but does not touch this static storage.
- `Socket`, `CashShopRequest`, `Thread`, packet-buffer helpers, static initializer thunks, and generic string helpers: infrastructure only, not semantic owners.
- New standalone `auth/Ncauth.cpp` or `network/Ncauth.cpp`: plausible in abstract source-layout terms, but weaker than existing `MiscWorkThread.cpp` because IDA and current project docs place the worker, fallback URL, message id, and notification class in the MiscWorkThread family.

Confidence:

- Storage/boundary confidence: `94/100`.
- Behavior confidence: `93/100`.
- `MiscWorkThread.cpp` ownership inference: `90/100`.
- Literal original symbol/name confidence: `65/100`. `NcauthConfirmUserUrlOverrideStaticString` is a descriptive reconstruction name, not a recovered original symbol.

## Exact Pending by-memory/-coverage-report.md Replacement Row

Replace only the existing `00029T` row in `by-memory/-coverage-report.md`; keep the surrounding `00029S` and `00029U` rows as-is.

```markdown
    - [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) 0x0069b3d0-0x0069b3d4 | static string/object handle | NcauthConfirmUserUrlOverrideStaticString : reconstructable : 88% : very-strong : B001-050 recommends assignment to [UID:0000LG][MiscWorkThread](by-file/MiscWorkThread.md); live IDA found exactly six address occurrences/xrefs, no hidden pointer-table refs, generic startup construction/cleanup, opcode `0x66` subtype-3 packet writers in MainMenuPane and MapPane, and the sole semantic reader in `ProcessNCAUpdate`, which uses this slot as the NCA confirm-user URL override before falling back to [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md).
```

## Exact Pending Target-Page Metadata Recommendation

Do not apply this from B001 unless explicitly reassigned as an edit task. If supervisor/A-agent applies the ownership update, the target header should become:

```markdown
*** UID:00029T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LG | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended content update: revise the title/summary from "Main Menu Text URL" to "NCA Auth Confirm-User URL Override Static String" or a close equivalent. A coordinated filename rename to `0x0069b3d0-0x0069b3d4.NcauthConfirmUserUrlOverrideStaticString.md` is optional; parent assignment does not require the rename.

## Supporting Research

### Target

- Target UID: `00029T`
- Target path: `by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md`
- Supervisor assignment: B001-050, `reviewed-85-but-ownership-unknown-under-review`
- Source queue state: A003 Batch 231 raised child `85/91 -> 86/92`; parent remained blank due to apparent split across MainMenuPane, MapPane, and auth/update code.
- Current manual coverage row: `reconstructable : 86% : very-strong`, unassigned due split ownership.

### Method

I re-read `goal.md`, `inference_research.md`, and the relevant by-structure guidance before using documentation leads and live IDA. Existing docs were treated as hypotheses; ownership conclusions below are based on the current IDA evidence plus project source-layout fit.

Evidence types used:

- IDA MCP `py_eval` for bytes, item boundaries, xrefs, raw address scans, decompilation, callers, and callees.
- Existing target, parent, neighboring, and fallback by-memory/by-file/by-class docs.
- Proposed source tree context for `app/MiscWorkThread.cpp`, `login/MainMenuPane.cpp`, and `map/MapPane.cpp`.
- Negative evidence: raw pointer scan, source-string/PDB scan, adjacent item review, and rejected infrastructure owners.

No by-* page, generated report, coverage report, project-level report, or tool-owned file was edited.

### Live IDA Environment

IDA MCP was attached to:

```text
C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe
imagebase: 0x00400000
md5: 4247e04e20b65d6414c7238aa8ff5515
```

Source metadata scan result:

- No `.pdb`, `RSDS`, `NB10`, `.cpp`, `.cxx`, `.hpp`, `\src\`, or `/src/` strings were found by the IDA string scan.
- The only `NexusTK` string hits were runtime/service URLs, not source paths.

Therefore this report does not claim recovered original source-file proof from debug metadata. The source owner is a strong binary/layout inference.

### Confirmed IDA Facts

Target item:

| Fact | Value |
| --- | --- |
| IDA name | `dword_69B3D0` |
| Segment | `.data` |
| Item range | `0x0069b3d0-0x0069b3d4` |
| Item size | `4` |
| Raw bytes | `ff ff ff ff` |

Neighbor check:

| Address | IDA item | Xrefs | Ownership implication |
| --- | --- | ---: | --- |
| `0x0069b39c` | `dword_69B39C` | 3 | Static string-vector control storage; separate earlier item. |
| `0x0069b3ac` | `dword_69B3AC`, size `36` | 2 | TimerMgr static object storage; separate owner. |
| `0x0069b3cc` | inside `dword_69B3AC` | 0 | Confirms previous object tail has no target refs. |
| `0x0069b3d0` | `dword_69B3D0`, size `4` | 6 | Current target. |
| `0x0069b3d4` | `byte_69B3D4`, size `1` | 7 | Surface pixel-format flags; separate successor. |
| `0x0069b3d8` | `dword_69B3D8` | 12 | Surface/render neighbor; separate successor cluster. |

Direct xrefs to target:

| Ref | Function | Role |
| --- | --- | --- |
| `0x00419f50` | `0x00419f50-0x00419f66` | Static string/object construction: `sub_582A80(&dword_69B3D0)` and `atexit(sub_60C250)`. |
| `0x00502ece` | `0x00502e30-0x0050305c` | MainMenuPane opcode `0x66` helper assigns subtype `3` packet string. |
| `0x0051404e` | `0x00513da0-0x0051408f` | MapPane opcode `0x66` helper assigns subtype `3` packet string. |
| `0x00527c71` | `0x00527bb0-0x00527ea4` | `ProcessNCAUpdate` tests whether override string is non-empty. |
| `0x00527c7f` | `0x00527bb0-0x00527ea4` | `ProcessNCAUpdate` copies override string into URL buffer. |
| `0x0060c250` | `0x0060c250-0x0060c25a` | Static cleanup: `sub_582B30(&dword_69B3D0)`. |

Raw address scan:

- The little-endian bytes for `0x0069b3d0` occur exactly six times in the IDB.
- Those six raw occurrences are the same six xrefs above.
- No additional absolute pointer, pointer-table, vtable, data-table, or hidden code occurrence was found for the target address.

### Static Lifetime Evidence

IDA decompilation of `0x00419f50`:

```c
int sub_419F50()
{
  sub_582A80(&dword_69B3D0);
  return atexit(sub_60C250);
}
```

IDA decompilation of `0x0060c250`:

```c
void __cdecl sub_60C250()
{
  sub_582B30(&dword_69B3D0);
}
```

The static initializer area around `0x00419e80-0x0041a040` constructs mixed objects: OLE cleanup, `dword_66DAEC`, MemoryMan storage, TimerMgr storage, the target string handle, and other unrelated statics. This area is not a source owner. It only proves source-declared static lifetime.

The string helpers are generic:

- `sub_582A80` has 13 code refs.
- `sub_582B30` has 165 code refs.
- `sub_582BB0` has 15 code refs.
- `sub_584CF0` has 27 code refs.
- `sub_584540` has 171 code refs.

Therefore constructor/destructor/helper refs are type/lifetime evidence, not owner evidence.

### Packet Writer Evidence

MainMenuPane path:

- `MainMenuPane::OnServerMessage`-style dispatcher `0x004f6d80-0x004f75ba` calls `0x00502e30` at `0x004f74c2`.
- The dispatch case is packet opcode `0x66`.
- `0x00502e30` subtype `3` calls packet string reader `sub_575A90`, assigns the temporary string to `dword_69B3D0` with `sub_582BB0`, then destroys the temporary.

IDA decompilation excerpt:

```c
if ( v3 == 3 )
{
  v4 = sub_575A90(&Block, a1, &v18);
  v20 = 2;
  sub_582BB0(&dword_69B3D0, (const char **)v4);
  sub_582B30(&Block);
}
```

MapPane path:

- `MapPane::HandlePacket`-style dispatcher `0x00507c90-0x00508e06` calls `0x00513da0` at `0x00508829`.
- The dispatch case is also packet opcode `0x66`.
- `0x00513da0` subtype `3` uses the same `sub_575A90` -> `sub_582BB0(&dword_69B3D0)` -> temporary destructor pattern.

IDA decompilation excerpt:

```c
case 3u:
  v15 = sub_575A90(&Block, a2, &v20);
  v23 = 4;
  sub_582BB0(&dword_69B3D0, (const char **)v15);
  sub_582B30(&Block);
  break;
```

Interpretation: MainMenuPane and MapPane are state-specific packet adapters. The same server packet can update the override while the client is at the login screen or while it is in the live map. That dual writer pattern is weaker than the auth worker's exclusive read/use pattern for declaration ownership.

### NCA Worker Evidence

`ProcessNCAUpdate` at `0x00527bb0-0x00527ea4` is the only function that reads the target. It is called from `MiscWorkThread::ProcessWorkItem` at `0x0052803f` when the queued worker message id is `0x4e434175`.

IDA decompilation excerpt:

```c
v3 = InternetOpenA(0, 0, 0, 0, 0);
if ( v3 )
{
  if ( sub_584CF0(&dword_69B3D0) )
  {
    v7 = (const char *)sub_584540(&dword_69B3D0);
    strcpy_s(szUrl, 0x100u, v7);
  }
  else
  {
    v9 = strlen(byte_66DE30);
    ...
    Format[v10] = ~byte_66DE30[v10];
    ...
    sub_443A00(szUrl, 0x100u, Format, password, account);
  }
  v15 = InternetOpenUrlA(v3, szUrl, Locale, 0, 0, 0);
  ...
}
```

Important disassembly:

- `0x00527c71`: `mov ecx, offset dword_69B3D0`; `call sub_584CF0`; branch to fallback when empty.
- `0x00527c7f`: `mov ecx, offset dword_69B3D0`; `call sub_584540`; `_strcpy_s(szUrl, 0x100, source)`.
- `0x00527ca3`: `mov edx, offset byte_66DE30`, start of fallback length/decode path.
- `0x00527d40`: `mov cl, byte_66DE30[eax]`; `not cl`; store decoded byte into the URL format buffer.
- `0x00527df8`: `InternetOpenUrlA`.
- `0x00527e0d` / `0x00527e86`: `sub_528560` posts `ncauth::Notification` states.

The target and fallback URL are paired in one function:

- [UID:00029T] is the packet-populated override URL.
- [UID:00027S] is the built-in confirm-user URL format fallback.
- [UID:00027S] is already attached to [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md) because the same `ProcessNCAUpdate` worker owns the URL construction/open/parse/notification flow.

### Worker Queue And Registration Context

`MiscWorkThread::ProcessWorkItem` at `0x00527fe0-0x005281a1` dispatches message id `1313030517` (`0x4e434175`, `NCAu`) to `ProcessNCAUpdate`:

```c
case 1313030517:
  sub_527BB0((const WCHAR **)Block, (const WCHAR **)Block + 1);
  ...
```

`RequestNCAUpdate` at `0x00528310-0x005283a6` allocates two adjacent `SimpleUString` payloads and queues the same worker message:

```c
sub_582D20((void **)v5, Src);
sub_582D20((void **)(v5 + 4), a3);
return sub_596960((int)this, 1313030517, v5, 0);
```

The registration dialog command handler at `0x00530060-0x0053022b` calls `RequestNCAUpdate` through `g_pMiscWorkThread`:

- `0x00530141`: loads `dword_67AB50` / `g_pMiscWorkThread`.
- `0x0053015f`: calls `sub_528310`.
- Then it marks pending state and starts a 30000 ms timer.

The registration response handler at `0x00530230-0x005303ef` consumes notification channel `0x4e634175` and maps states `0..5` to success or message ids `228..232`. It does not reference `dword_69B3D0`.

Interpretation: `NexonclubRegistrationDialog` is a request producer and notification consumer. It is not the URL storage owner. The URL build/open/fallback/parse behavior belongs to the worker.

### Documentation Leads Audited

- [UID:00029T][target page](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md): correct for bytes, refs, lifecycle, writers, and reader; stale in stopping at split ownership.
- [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md): current `86/85`; owns `ProcessNCAUpdate`, worker queue wrappers, notification classes, and source placement `NexusTK/app/`.
- [UID:00008I][MiscWorkThread](../../../../../by-class/MiscWorkThread.md): current `85/85`; confirms worker message ids and request wrappers.
- [UID:0001CJ][MiscWorkThreadAndNotifications](../../../../../by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md): current `84/88`; documents `ProcessNCAUpdate`, `RequestNCAUpdate`, `ProcessWorkItem`, and notification helpers.
- [UID:00027S][NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md): current `82/88`, already parented to `0000LG`, explicitly describes [UID:00029T] as the packet-populated override URL storage.
- [UID:00022Y][MainMenuAnsiTextDialogPacketHelpers](../../../../../by-memory/0x00502e10-0x0050305c.MainMenuAnsiTextDialogPacketHelpers.md): correct for opcode `0x66` writer behavior.
- [UID:0001AW][MapPanePacketHandlersAndDelete](../../../../../by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md): broad/older but consistent with `0x00513da0` as MapPane packet helper.
- [UID:0001CU][NexonclubRegistrationSupportHelpers](../../../../../by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md): confirms registration queues NCA work through the worker and consumes notifications.
- `by-project-structure/proposed-source-tree.md`: places `MiscWorkThread.cpp` under `app/`, with WinInet HTTP fetches and NCA auth/update probes; places MainMenuPane in `login/` and MapPane in `map/`.

### Ranked Ownership Analysis

#### 1. [UID:0000LG] `MiscWorkThread` / `NexusTK/app/MiscWorkThread.cpp`

Recommendation rank: accepted.

Evidence for:

- IDA confirms the only target reader is `ProcessNCAUpdate`, a MiscWorkThread-owned helper.
- The target value is used as a URL override immediately before `InternetOpenUrlA`.
- The fallback URL object [UID:00027S] is consumed by the same worker function and already parented to `MiscWorkThread`.
- `RequestNCAUpdate`, `MiscWorkThreadMessageId`, and `ncauth::Notification` already form a coherent worker-owned NCA source family.
- [UID:0000LG] is already `86/85`, clearing the strict direct-parent gate.

Evidence against:

- The worker does not write the override; packet helpers do. That is acceptable because the writers are adapters receiving server state, while the worker owns the semantic use.
- Literal source-file proof is absent because no debug/source metadata exists in the IDB.

Conclusion: best owner and recommended route.

Confidence: `90/100`.

#### 2. [UID:0000L0] `MainMenuPane`

Recommendation rank: rejected.

Evidence for:

- MainMenu opcode `0x66` dispatch calls `0x00502e30`.
- Subtype `3` writes the target.
- The historical name "MainMenuTextUrl" came from this visible writer.

Evidence against:

- MainMenuPane never reads the value.
- The same write exists in MapPane, so pre-login UI cannot be the exclusive declaration owner.
- The value's only semantic use is auth URL override behavior in `ProcessNCAUpdate`.
- The current MainMenuPane file page is below the strict confidence gate.

Conclusion: writer/producer only.

Confidence as direct owner: `35/100`.

#### 3. [UID:0000L3] `MapPane`

Recommendation rank: rejected.

Evidence for:

- MapPane opcode `0x66` dispatch calls `0x00513da0`.
- Subtype `3` writes the same target using the same packet string assignment pattern.

Evidence against:

- MapPane never reads the value.
- The write is identical packet-state ingestion, not URL/auth behavior.
- Assigning to MapPane would leave the pre-login writer and auth worker unexplained.

Conclusion: writer/producer only.

Confidence as direct owner: `32/100`.

#### 4. [UID:0000M0] `NexonclubRegistrationDialog`

Recommendation rank: rejected.

Evidence for:

- Registration UI queues the NCA request with account/password data.
- It consumes the `ncauth::Notification` result.

Evidence against:

- It has no refs to `dword_69B3D0`.
- The worker owns URL construction/open/read/parse behavior.
- Registration is one producer/consumer context for the worker, not the declaration owner.

Conclusion: request/notification consumer context only.

Confidence as direct owner: `25/100`.

#### 5. New `auth/Ncauth.cpp` or `network/Ncauth.cpp`

Recommendation rank: rejected for current application.

Evidence for:

- The target and fallback URL are NCA-specific.
- A historical project could have factored auth helpers into a small auth source file.

Evidence against:

- Current IDA and project docs place the NCA worker, fallback URL, notification class, post helper, message id, and request wrapper in `MiscWorkThread.cpp`.
- The worker multiplexes HTTP, NCA, and browse-directory tasks; current source-tree rationale intentionally keeps it under `app/` instead of network.
- No source metadata, constructor island, vtable, or adjacent coherent data cluster proves a separate auth translation unit.

Conclusion: possible future refactor if source proof appears, but weaker than existing parent.

Confidence as direct owner: `40/100`.

#### 6. Socket, CashShopRequest, Thread, PacketBuffer, StringUtil helpers

Recommendation rank: rejected.

Evidence for:

- Thread queue helpers dispatch the worker request.
- Generic string helpers construct, assign, test, and copy the target.
- Packet parsing helpers supply the subtype string.

Evidence against:

- These are infrastructure or data-type helpers, not semantic declaration owners.
- No target-specific URL behavior exists in them.

Conclusion: dependencies only.

Confidence as direct owner: near zero.

### Split / Rename Decision

No split is needed:

- The target is an exact single item, `0x0069b3d0-0x0069b3d4`.
- The previous range ends cleanly at `0x0069b3d0`; the next range begins at `0x0069b3d4`.
- IDA found no hidden child refs, no mixed bytes inside the item, and no uncovered non-padding issue.

Rename recommendation:

- The current filename is misleading because the static is not owned by MainMenuPane.
- A content/title update to "NCA Auth Confirm-User URL Override Static String" is recommended.
- A coordinated filename rename is optional. If performed, use validator-supported coordinated rename/registration workflow; do not hand-edit generated reports.

### Related Items Likely In Same Source Family

Already-supported `MiscWorkThread.cpp` source family items:

- [UID:0001CJ][0x005277c0-0x005285dd.MiscWorkThreadAndNotifications](../../../../../by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md)
- [UID:00008I][MiscWorkThread](../../../../../by-class/MiscWorkThread.md)
- [UID:0000RQ][g_pMiscWorkThread](../../../../../by-global/g_pMiscWorkThread.md)
- [UID:0001P8][0x0067ab50-0x0067ab54.g_pMiscWorkThread](../../../../../by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md)
- [UID:00008X][ncauth__Notification](../../../../../by-class/ncauth__Notification.md)
- [UID:0001SQ][NcauthNotificationState](../../../../../by-type/by-enum/NcauthNotificationState.md)
- [UID:0001SP][MiscWorkThreadMessageId](../../../../../by-type/by-enum/MiscWorkThreadMessageId.md)
- [UID:00027S][0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated](../../../../../by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md)
- [UID:00027T][0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding](../../../../../by-memory/0x0066de6c-0x0066deb0.NcauthUrlToTableSentinelPadding.md), as ignored/padding context rather than source code.
- [UID:00029T][0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md), recommended addition as the packet-populated NCA URL override storage.

Do not pull the MainMenu and MapPane packet helper pages into `MiscWorkThread.cpp`. They remain with their dispatching UI/source modules as packet-state writers.

### Negative Evidence Summary

- No PDB/source-file/source-path metadata was found.
- No extra raw address occurrences for `0x0069b3d0` were found beyond the six documented refs.
- No vtable, RTTI, pointer table, or data-table owner reference points to this target.
- No direct refs from `Socket`, `CashShopRequest`, `Thread`, `NexonclubRegistrationDialog`, or generic network send helpers to this target.
- Address adjacency is mixed and not an ownership proof: TimerMgr storage ends immediately before the target, and Surface pixel-format flags start immediately after it.
- The static initializer/cleanup wrappers construct mixed source-owned objects and do not identify the original declaration module.

### Validation / Changed Files

Changed files:

- `tools/leaser/Agents/Agent-B001/research/00029T-MainMenuTextUrlStaticString.md`

Leases used:

- None. `goal.md` states that no lease is needed to create or update reports inside `Agent-B001/research`, and no by-* documentation or coverage report was edited.

Validator:

- Not run. No by-memory, by-file, by-class, by-global, generated, or coverage files were edited. The exact validator/apply work belongs to the supervisor or A-agent that applies the pending target-page metadata/content update.

### Final Action List

Supervisor/A-agent actions:

- Update [UID:00029T][target page](../../../../../by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md) to parent [UID:0000LG][MiscWorkThread](../../../../../by-file/MiscWorkThread.md), with recommended score `88/92`.
- Replace the `00029T` `by-memory/-coverage-report.md` row with the exact row above.
- Revise the title/summary to express `NcauthConfirmUserUrlOverrideStaticString` semantics. Filename rename is optional and should be coordinated through validator tooling if chosen.
- Do not create a new standalone auth source file for this item under current evidence.
- Do not assign the target to MainMenuPane or MapPane; keep those as packet writer contexts only.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00029T-MainMenuTextUrlStaticString.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:21","uid":"00029T"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
