** TARGET-REPORT-UID:0000L0 **
** AUTHOR-AGENT-ID:B011 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000L0 MainMenuPane Empty-Emitter Family Source-Quality Report

ASSIGNMENT:B011-report-0000L0-MainMenuPane-empty-emitter-family-20260701
MODE:implementation-callback-applied
AGENT:Agent-B011
DATE:2026-07-01

## Executive Disposition

[UID:0000L0] `by-file/MainMenuPane.md` is the correct source root for `NexusTK/login/MainMenuPane.cpp`. The current generated file has 21 total emitters, 9 filled code emitters, and 12 empty markers. Ten of the 12 empty markers are support/class/address-alias markers that should receive formal comment-only reconstruction blocks to make the no-duplicate-body disposition explicit. Two markers, [UID:00019P] `OpenCreateUserDialog` and [UID:00019S] `OpenTerminalPane`, are exact retained helper bodies that should now receive first-draft C++.

The stale retained-helper rule on [UID:00019P], [UID:00019S], [UID:0000TB], and [UID:0000TF] should be superseded. Current MCP evidence still finds no direct entry xrefs or VA/RVA pointer-byte route to `0x004f8fa0` or `0x004f91c0`, but B010/B004/B003 precedent in this same source family treats that as a confidence cap, not a blank-C++ blocker, when the active `MainMenuPane::ActivateMenuItem` dispatcher duplicates the retained body and the owner/emitter route is already valid.

## Evidence Used

- Current generated output: `auto-generated/NexusTK/login/MainMenuPane.cpp` header `validator-command-id:000000003465`, refreshed `2026-07-01T05:44:04-04:00`, source UID `0000L0`.
- Current generated filled bodies: [UID:00019J] `CloseMainMenuDialogSingletons`, [UID:00019M] `ComputeMenuItemRect`, [UID:00019N] `HitTestMenuItem`, [UID:00019O] `HandleLegacyMainMenuPacket`, [UID:0002Q6] `OpenTransferServerDialog`, [UID:00019Q] `OpenChangePasswordDialog`, [UID:0003H6] `OpenStoryViewingPane`, [UID:0003H7] `OpenHistoryViewingPane`, and [UID:00022Y] `MainMenuAnsiTextDialogPacketHelpers`.
- Current empty markers in generated output: [UID:00007O], [UID:0000PH], [UID:0000PI], [UID:0000SZ], [UID:0000T1], [UID:0000TA], [UID:0000TB], [UID:0000TC], [UID:0000TE], [UID:0000TF], [UID:00019P], and [UID:00019S].
- Callback generated proof: `auto-generated/NexusTK/login/MainMenuPane.cpp` now has header `validator-command-id:000000003545`, refreshed `2026-07-01T06:13:51-04:00`, source UID `0000L0`; [UID:00019P] emits `static void OpenCreateUserDialog()` and [UID:00019S] emits `static void OpenTerminalPane(MainMenuPane *pane)`.
- Current by-* docs: `by-file/MainMenuPane.md`, `by-class/MainMenuPane.md`, the ten by-global alias pages, exact child pages [UID:00019P]/[UID:00019S], and support aggregate [UID:00019I].
- Executed report precedents opened by targeted search: B010 `00019Q-OpenChangePasswordDialog-source-quality.md`, B010 `00019J-CloseMainMenuDialogSingletons-source-quality.md`, B007 `00019M-ComputeMenuItemRect-source-quality.md`, B012 `00019N-MainMenuHitTest-source-quality.md`, B001 `00019O-LegacyMainMenuPacket-source-quality.md`, B003 `0002Q6-OpenTransferServerDialog-source-quality.md`, B004 `00019R-HistoryViewingPaneLaunchHelpers-source-quality.md`, B010 `0001CR-CreateUserDialogVariants-source-quality.md`, and terminal/config support reports for `OpenTerminalPane`.
- Live IDA MCP session `supervisor_resume_20260629`: `server_health` reports status `ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`.

## Current Empty Marker Inventory

| UID | Doc | Current generated state | Recommended disposition |
| --- | --- | --- | --- |
| 00007O | `by-class/MainMenuPane.md` | Empty marker | Comment-only formal block. Aggregate class context; child pages emit bodies. |
| 0000PH | `by-global/CloseMainMenuDialogSingletons_4F69A0.md` | Empty marker | Comment-only formal block. Body is [UID:00019J]. |
| 0000PI | `by-global/ComputeMenuItemRect_4F8B90.md` | Empty marker | Comment-only formal block. Body is [UID:00019M]. |
| 0000SZ | `by-global/HandleLegacyMainMenuPacket_4F8D00.md` | Empty marker | Comment-only formal block. Body is [UID:00019O]. |
| 0000T1 | `by-global/HitTestMenuItem_4F8C10.md` | Empty marker | Comment-only formal block. Body is [UID:00019N]. |
| 0000TA | `by-global/OpenChangePasswordDialog_4F9060.md` | Empty marker | Comment-only formal block. Body is [UID:00019Q]. |
| 0000TB | `by-global/OpenCreateUserDialog_4F8FA0.md` | Empty marker | Comment-only formal block after [UID:00019P] gets body. |
| 0000TC | `by-global/OpenHistoryViewingPane_4F9140.md` | Empty marker | Comment-only formal block. Body is [UID:0003H7]. |
| 0000TE | `by-global/OpenStoryViewingPane_4F90C0.md` | Empty marker | Comment-only formal block. Body is [UID:0003H6]. |
| 0000TF | `by-global/OpenTerminalPane_4F91C0.md` | Empty marker | Comment-only formal block after [UID:00019S] gets body. |
| 00019P | `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md` | Empty marker | First-draft `static void OpenCreateUserDialog()` body; raise to `88/90`. |
| 00019S | `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md` | Empty marker | First-draft `static void OpenTerminalPane(MainMenuPane *pane)` body; raise to `88/90`. |

## Live IDA MCP Findings

### OpenCreateUserDialog, `0x004f8fa0-0x004f9055`

- `lookup_funcs 0x004f8fa0`: `sub_4F8FA0`, size `0xb5`.
- `decompile 0x004f8fa0`: no-argument function. If `byte_66DA97 == 1`, it closes `unk_69B484` through `sub_49DAD0`, allocates `640` bytes, calls `sub_52DD30`, then calls `sub_579E30(dword_67A7D0, 0, 100, 1)`. Else it allocates `640` bytes and calls `sub_52A540`.
- `callees 0x004f8fa0`: `0x49dad0`, `0x4f4aa0`, `0x52dd30`, `0x579e30`, `0x52a540`.
- `xrefs_to 0x004f8fa0`: zero direct xrefs.
- `find_bytes` for VA/RVA little-endian pointers `A0 8F 4F 00` and `A0 8F 0F 00`: zero matches.
- `get_bytes 0x004f9055 size 11`: eleven `0xcc` bytes, confirming the documented padding before `0x004f9060`.
- `decompile 0x004f7a10`: active `MainMenuPane::ActivateMenuItem` case `0` duplicates this helper exactly: close login dialog at `0x004f7a60`, construct `CreateUserDialogPane` at `0x004f7a82`, call `sub_579E30` at `0x004f7a9a`, or construct `NewUserDialogPane2` at `0x004f7ad0`.
- Current SoundManager docs identify `0x00579e30` as `SoundManager::PlayTrackByIndex(int trackIndex, int fadeOutMillis, int loopCount)`, so the source-facing call should be `g_pSoundManager->PlayTrackByIndex(0, 100, 1)`.

### OpenTerminalPane, `0x004f91c0-0x004f927d`

- `lookup_funcs 0x004f91c0`: `sub_4F91C0`, size `0xbd`.
- `decompile 0x004f91c0`: `void __thiscall sub_4F91C0(void *this)`. It calls `sub_574B20(dword_67A7EC)`, `sub_596620(dword_67A7EC)`, optionally closes `unk_69B484` through `sub_49DAD0`, queues `this` through `sub_469180(dword_67A74C, this)`, tests `*(byte *)(dword_67A7C8 + 2692810)`, calls `sub_464E40(unk_67AB1C)` if set, otherwise allocates `624` bytes and calls `sub_58AF50`, then plays sample `0x192` through `sub_57A5C0(dword_67A7D0, 0x192, 100)`.
- `callees 0x004f91c0`: `0x574b20`, `0x596620`, `0x49dad0`, `0x469180`, `0x464e40`, `0x4f4aa0`, `0x58af50`, `0x57a5c0`.
- `xrefs_to 0x004f91c0`: zero direct xrefs.
- `find_bytes` for VA/RVA little-endian pointers `C0 91 4F 00` and `C0 91 0F 00`: zero matches.
- `get_bytes 0x004f927d size 3`: three `0xcc` bytes, confirming the documented padding before `0x004f9280`.
- `decompile 0x004f7a10`: active `MainMenuPane::ActivateMenuItem` case `5` duplicates this helper exactly at `0x004f7c58-0x004f7cd4`, including cleanup, wait/drain, login-close, `BlackHole` queueing, config-byte exit branch, `TerminalPane` construction, and sample `0x192`.
- Existing support docs accept `g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(...)` for `sub_469180`, `g_packetSender->WaitForQueueDrain()` for `sub_596620`, `g_pApplication->RequestExit()` for `sub_464E40`, and `g_pSoundManager->PlaySample(id, volume)` for `sub_57A5C0`.

## Ranked Ownership And Source Placement

1. `MainMenuPane.cpp` / [UID:0000L0] is accepted for all 12 markers. Positive evidence: the generated source route is already [UID:0000L0], exact retained helpers sit in the main-menu/login island, active `ActivateMenuItem` duplicates [UID:00019P] and [UID:00019S], and prior accepted B001/B003/B004/B007/B010/B012 reports use the same file-local helper policy for neighboring retained bodies.
2. Exact by-memory child pages own body emission for real helper functions. For `0x004f8fa0` and `0x004f91c0`, the by-memory pages are the only correct places to put first-draft C++. Address-suffixed by-global pages must not duplicate them.
3. By-global pages are search/support aliases. They should keep owner/emitter [UID:0000L0] but carry only formal comment markers explaining the no-duplicate-body policy.
4. `by-class/MainMenuPane.md` is an aggregate class context. It should not invent a broad class declaration/body from child method evidence; a formal comment marker is appropriate.
5. Rejected owners: `CreateUserDialogPane`, `NewUserDialogPane2`, `TerminalPane`, `SoundManager`, `Socket`, `Thread`, `BlackHole`, `Application`, `MemoryMan`, generated-only/no-owner buckets. These are callees or dependency owners, not owners of the launch helpers.

## First-Draft Formal C++ Recommendations

### [UID:00019P] `OpenCreateUserDialog`

Set metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L0`. Insert this exact multiline formal block:

```cpp
static void OpenCreateUserDialog()
{
    if (g_useEpfAssets == 1) {
        if (g_pLoginDialogPane != NULL)
            CloseDialogPane(g_pLoginDialogPane);

        new CreateUserDialogPane;
        g_pSoundManager->PlayTrackByIndex(0, 100, 1);
    } else {
        new NewUserDialogPane2;
    }
}
```

Rationale: this matches current generated style for [UID:00019Q], [UID:0003H6], and [UID:0003H7], which use source-level `new Type(...)` where constructor publication owns the live singleton. The exact allocation size and constructor targets remain in prose evidence; source C++ does not need explicit `operator new(0x280)` wrappers.

### [UID:00019S] `OpenTerminalPane`

Set metadata to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:0000L0`. Insert this exact multiline formal block:

```cpp
static void OpenTerminalPane(MainMenuPane *pane)
{
    g_packetSender->SendCleanupPacket();
    g_packetSender->WaitForQueueDrain();

    if (g_pLoginDialogPane != NULL)
        CloseDialogPane(g_pLoginDialogPane);

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(pane);

    if (g_pConfig->m_startupTerminalReady != 0) {
        g_pApplication->RequestExit();
    } else {
        new TerminalPane;
    }

    g_pSoundManager->PlaySample(0x192, 100);
}
```

Rationale: the raw ABI is `thiscall` and uses the incoming `this` solely as the caller pane queued through `BlackHole`. A source-facing file-local helper with an explicit `MainMenuPane *pane` parameter is clearer than making it a `TerminalPane` method or leaking a raw `void *this` label. `m_startupTerminalReady` is an inferred field name already supported by RegistryConfig/TerminalPane docs; exact final Config field spelling remains a confidence cap, not a blocker.

## Formal Comment-Only Recommendations

These comments should be inserted into the multiline `RECONSTRUCTION_CPP CODE:BEGIN/END` formal blocks. The single-line `RECONSTRUCTION_CPP CODE:[[[]]]` header value remains unchanged.

```cpp
// MainMenuPane method bodies and file-local helpers are emitted by exact child pages in [UID:0000L0]; this aggregate class page remains declaration/context support and does not duplicate child bodies.
```

```cpp
// CloseMainMenuDialogSingletons is emitted by exact helper [UID:00019J]; this address-suffixed global page is an alias/search marker and does not duplicate the helper body.
```

```cpp
// ComputeMenuItemRect is emitted by exact helper [UID:00019M]; this address-suffixed global page is an alias/search marker and does not duplicate the helper body.
```

```cpp
// HandleLegacyMainMenuPacket is emitted by exact helper [UID:00019O]; this address-suffixed global page preserves packet-helper evidence without duplicating the body.
```

```cpp
// HitTestMenuItem is emitted by exact helper [UID:00019N]; this address-suffixed global page is an alias/search marker and does not duplicate the hit-test body.
```

```cpp
// OpenChangePasswordDialog is emitted by exact helper [UID:00019Q]; this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
```

```cpp
// OpenCreateUserDialog is emitted by exact helper [UID:00019P]; this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
```

```cpp
// OpenHistoryViewingPane is emitted by exact helper [UID:0003H7]; this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
```

```cpp
// OpenStoryViewingPane is emitted by exact helper [UID:0003H6]; this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
```

```cpp
// OpenTerminalPane is emitted by exact helper [UID:00019S]; this address-suffixed global page remains a search/support alias and does not duplicate the retained launcher body.
```

## Metadata And Support Doc Recommendations

- [UID:0000L0] `by-file/MainMenuPane.md`: keep exact `89/86`. Update the `OpenCreateUserDialog_4F8FA0` and `OpenTerminalPane_4F91C0` inventory rows, key behavior, migration notes, score rationale, and changes section to state that exact children [UID:00019P]/[UID:00019S] now carry first-draft C++; no-entry/no-pointer evidence remains a confidence cap.
- [UID:00007O] `by-class/MainMenuPane.md`: keep exact `85/89`; insert formal comment-only block and update helper table rows for `OpenCreateUserDialog` and `OpenTerminalPane`.
- [UID:00019I] `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`: keep exact `85/88`, set `CANONICAL_OWNER:0000L0` per the accepted implementation callback, keep `RECONSTRUCTABLE:FALSE` and blank emitters; update the two retained-helper rows from "live reachability unresolved" to "exact child emits first-draft C++; live reachability remains a confidence cap".
- [UID:00019P] exact page: raise to `88/90`; replace `final C++ deferred`, `intentionally blank`, and "not accepted while no inbound callback/table route is proven" wording with first-draft-body acceptance language.
- [UID:00019S] exact page: raise to `88/90`; replace the stale `95/95 reconstruction-code gate` wording with the current `(completion + confidence) / 2 > 85` standard and first-draft-body acceptance language.
- [UID:0000TB] alias page: keep exact `86/90`; replace "no final C++ is emitted" and "Code intentionally blank" with alias-only comment formal block and child-body ownership through [UID:00019P].
- [UID:0000TF] alias page: keep exact `86/90`; replace `95+/95+` and "source shape reaches the reconstruction-code gate" wording with alias-only comment formal block and child-body ownership through [UID:00019S].
- Existing alias pages [UID:0000PH], [UID:0000PI], [UID:0000SZ], [UID:0000T1], [UID:0000TA], [UID:0000TC], [UID:0000TE] already have mostly correct alias prose; add formal comment-only blocks so generated output no longer reports them as empty markers.

## Claim And Incorporation Ledger

| ID | Claim/fact to preserve | Evidence | Destination/exclusion | Action | Verification state |
| --- | --- | --- | --- | --- | --- |
| MMP-001 | Generated `MainMenuPane.cpp` initially had 12 empty markers and 9 filled bodies. | Initial generated header `000000003465`; callback generated header `000000003545`. | Report inventory and generated freshness proof. | incorporate | verified: generated file refreshed `2026-07-01T06:13:51-04:00`, now has comment markers/bodies instead of old empty-marker text. |
| MMP-002 | [UID:00007O] is aggregate class context, not a body owner. | Current class doc and generated marker; exact children emit methods/helpers. | `by-class/MainMenuPane.md` formal comment block plus `[[CHILDREN]]`. | incorporate | applied: validator `000000003504` at `2026-07-01T06:05:35-04:00`, exit `0`, ok `1`; generated line 7 comment marker present. |
| MMP-003 | [UID:0000PH] is alias-only for [UID:00019J]. | Current by-global prose and generated [UID:00019J] body. | `by-global/CloseMainMenuDialogSingletons_4F69A0.md`. | incorporate | applied: validator `000000003505` at `2026-07-01T06:05:47-04:00`, exit `0`, ok `1`; generated lines 11-12 comment-only alias. |
| MMP-004 | [UID:0000PI] is alias-only for [UID:00019M]. | Current by-global prose and generated [UID:00019M] body. | `by-global/ComputeMenuItemRect_4F8B90.md`. | incorporate | applied: validator `000000003506` at `2026-07-01T06:05:57-04:00`, exit `0`, ok `1`; generated lines 14-15 comment-only alias. |
| MMP-005 | [UID:0000SZ] is alias-only for [UID:00019O]. | Current by-global prose and generated [UID:00019O] body. | `by-global/HandleLegacyMainMenuPacket_4F8D00.md`. | incorporate | applied: validator `000000003507` at `2026-07-01T06:06:07-04:00`, exit `0`, ok `1`; generated lines 17-18 comment-only alias. |
| MMP-006 | [UID:0000T1] is alias-only for [UID:00019N]. | Current by-global prose and generated [UID:00019N] body. | `by-global/HitTestMenuItem_4F8C10.md`. | incorporate | applied: validator `000000003508` at `2026-07-01T06:06:18-04:00`, exit `0`, ok `1`; generated lines 20-21 comment-only alias. |
| MMP-007 | [UID:0000TA] is alias-only for [UID:00019Q]. | B010 accepted/executed report and generated [UID:00019Q] body. | `by-global/OpenChangePasswordDialog_4F9060.md`. | incorporate | applied: validator `000000003509` at `2026-07-01T06:06:29-04:00`, exit `0`, ok `1`; generated lines 23-24 comment-only alias. |
| MMP-008 | [UID:0000TC] is alias-only for [UID:0003H7]. | B004 accepted/executed report and generated [UID:0003H7] body. | `by-global/OpenHistoryViewingPane_4F9140.md`. | incorporate | applied: validator `000000003513` at `2026-07-01T06:06:59-04:00`, exit `0`, ok `1`; generated lines 29-30 comment-only alias. |
| MMP-009 | [UID:0000TE] is alias-only for [UID:0003H6]. | B004 accepted/executed report and generated [UID:0003H6] body. | `by-global/OpenStoryViewingPane_4F90C0.md`. | incorporate | applied: validator `000000003515` at `2026-07-01T06:07:20-04:00`, exit `0`, ok `1`; generated lines 32-33 comment-only alias. |
| MMP-010 | [UID:00019P] is a real retained create-user helper under `MainMenuPane.cpp`. | MCP `lookup_funcs`, `decompile`, `callees`, boundary bytes, active case-0 duplicate. | `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`; `by-file/MainMenuPane.md`; [UID:00019I]. | incorporate | applied: exact page validator `000000003502`; by-file validator `000000003519`; aggregate validator `000000003521`; all exit `0`, ok `1`. |
| MMP-011 | [UID:00019P] has no direct helper-start xrefs or VA/RVA pointer-byte route. | MCP `xrefs_to 0x004f8fa0` zero; `find_bytes` zero for VA/RVA patterns. | Preserve as confidence cap in exact/support docs. | incorporate | applied: [UID:00019P], [UID:0000L0], and [UID:00019I] prose now says no-entry evidence caps confidence but does not block first-draft C++. |
| MMP-012 | [UID:00019P] should emit first-draft `static void OpenCreateUserDialog()` despite no entry route. | Active case-0 duplicate; B010 retained-helper precedent; valid owner/emitter. | [UID:00019P] formal C++ block. | incorporate | verified: generated lines 158-159 emit [UID:00019P] `static void OpenCreateUserDialog()`; exact validator `000000003502`, exit `0`, ok `1`. |
| MMP-013 | [UID:0000TB] should not duplicate [UID:00019P]. | By-global guidance and existing alias/body split pattern. | `by-global/OpenCreateUserDialog_4F8FA0.md` formal comment. | incorporate | applied: validator `000000003511` at `2026-07-01T06:06:39-04:00`, exit `0`, ok `1`; generated lines 26-27 are comment-only alias. |
| MMP-014 | `0x00579e30` is `SoundManager::PlayTrackByIndex`, not `PlaySample`. | Current SoundManagerMusicSelection docs for `0x00579e30-0x0057a0a5`. | [UID:00019P] C++ and prose. | incorporate | verified: [UID:00019P] formal block contains `g_pSoundManager->PlayTrackByIndex(0, 100, 1)`. |
| MMP-015 | [UID:00019S] is a real retained terminal launcher under `MainMenuPane.cpp`. | MCP `lookup_funcs`, `decompile`, `callees`, boundary bytes, active case-5 duplicate. | `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`; `by-file/MainMenuPane.md`; [UID:00019I]. | incorporate | applied: exact page validator `000000003503`; by-file validator `000000003519`; aggregate validator `000000003521`; all exit `0`, ok `1`. |
| MMP-016 | [UID:00019S] has no direct helper-start xrefs or VA/RVA pointer-byte route. | MCP `xrefs_to 0x004f91c0` zero; `find_bytes` zero for VA/RVA patterns. | Preserve as confidence cap in exact/support docs. | incorporate | applied: [UID:00019S], [UID:0000L0], and [UID:00019I] prose now says no-entry evidence caps confidence but does not block first-draft C++. |
| MMP-017 | [UID:00019S] should emit first-draft `static void OpenTerminalPane(MainMenuPane *pane)`. | Active case-5 duplicate; raw ABI queues incoming `this`; B010/B004 retained-helper precedent. | [UID:00019S] formal C++ block. | incorporate | verified: generated lines 196-197 emit [UID:00019S] `static void OpenTerminalPane(MainMenuPane *pane)`; exact validator `000000003503`, exit `0`, ok `1`. |
| MMP-018 | [UID:0000TF] should not duplicate [UID:00019S]. | By-global guidance and existing alias/body split pattern. | `by-global/OpenTerminalPane_4F91C0.md` formal comment. | incorporate | applied: validator `000000003517` at `2026-07-01T06:07:40-04:00`, exit `0`, ok `1`; generated lines 35-36 are comment-only alias. |
| MMP-019 | Stale `95/95` or `95+/95+` reconstruction-code gate wording is invalid here. | Current workflow Rule 26 and goal; accepted retained-helper reports use current score/blocker model. | [UID:00019S], [UID:0000TF], stale support prose. | reject-stale | applied: current prose historicalizes/supersedes old gate wording; validators `000000003503` and `000000003517` passed. |
| MMP-020 | "Live reachability unresolved" remains true but cannot be left as a future blocker. | MCP negative route evidence plus active duplicate positive evidence. | Exact/support docs as confidence cap. | historicalize | applied: exact/support docs now preserve no-xref evidence as confidence cap and remove future-helper-body blocker language. |
| MMP-021 | `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` remains non-emitting. | Current callback header `CANONICAL_OWNER:0000L0`, `RECONSTRUCTABLE:FALSE`, mixed-owner range. | Support aggregate prose only; no formal code. | incorporate | applied: validator `000000003521` at `2026-07-01T06:08:19-04:00`, exit `0`, ok `1`; canonical owner update `NONE -> 0000L0`, blank emitters preserved. |
| MMP-022 | Manual coverage reports, generated reports, generated C++ files, validator state, queues, archives, supervisor ledgers, and IDA DB must not be manually edited. | Goal scope. | Exclude from manual edits except validator-owned generated refresh. | not-applicable | verified: generated/tool files changed only by validator runs; manual edits were limited to accepted by-* docs and this B011 report. |

## Scoped Validator Commands For Accepted Callback

Run validators only after implementing accepted edits. Prefer one file per command for clean proof; include `--wait-generated` where generated `MainMenuPane.cpp` freshness matters.

> Executable block R001 was removed from this report and preserved verbatim in [0000L0-MainMenuPane-empty-emitter-family-source-quality-removed.md](0000L0-MainMenuPane-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Callback validator proof, second summarized pass from `source-3/project-documentation`:

| File | Command id | Timestamp | Exit | ok | Generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md` | `000000003502` | `2026-07-01T06:05:12-04:00` | 0 | 1 | completed |
| `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md` | `000000003503` | `2026-07-01T06:05:24-04:00` | 0 | 1 | completed |
| `by-class/MainMenuPane.md` | `000000003504` | `2026-07-01T06:05:35-04:00` | 0 | 1 | completed |
| `by-global/CloseMainMenuDialogSingletons_4F69A0.md` | `000000003505` | `2026-07-01T06:05:47-04:00` | 0 | 1 | completed |
| `by-global/ComputeMenuItemRect_4F8B90.md` | `000000003506` | `2026-07-01T06:05:57-04:00` | 0 | 1 | completed |
| `by-global/HandleLegacyMainMenuPacket_4F8D00.md` | `000000003507` | `2026-07-01T06:06:07-04:00` | 0 | 1 | completed |
| `by-global/HitTestMenuItem_4F8C10.md` | `000000003508` | `2026-07-01T06:06:18-04:00` | 0 | 1 | completed |
| `by-global/OpenChangePasswordDialog_4F9060.md` | `000000003509` | `2026-07-01T06:06:29-04:00` | 0 | 1 | completed |
| `by-global/OpenCreateUserDialog_4F8FA0.md` | `000000003511` | `2026-07-01T06:06:39-04:00` | 0 | 1 | completed |
| `by-global/OpenHistoryViewingPane_4F9140.md` | `000000003513` | `2026-07-01T06:06:59-04:00` | 0 | 1 | completed |
| `by-global/OpenStoryViewingPane_4F90C0.md` | `000000003515` | `2026-07-01T06:07:20-04:00` | 0 | 1 | completed |
| `by-global/OpenTerminalPane_4F91C0.md` | `000000003517` | `2026-07-01T06:07:40-04:00` | 0 | 1 | completed |
| `by-file/MainMenuPane.md` | `000000003519` | `2026-07-01T06:07:59-04:00` | 0 | 1 | completed |
| `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md` | `000000003521` | `2026-07-01T06:08:19-04:00` | 0 | 1 | completed |

Validator warnings were pre-existing/global or accepted-scope side effects: repeated `autogen_children_marker_missing` / `autogen_emitter_has_no_code` project-wide notices, plus `missing_ref_uid 00036Y` on MainMenuPane support docs. None failed the scoped files; every command returned `ok: 1`.

Generated freshness proof after callback: `auto-generated/NexusTK/login/MainMenuPane.cpp` was read back with header `validator-command-id: 000000003545`, `validator-refreshed-at: 2026-07-01T06:13:51-04:00`, `validator-refresh-source: foreground-generated-refresh`, source UID `0000L0`.

- [UID:00019P] emits `static void OpenCreateUserDialog()` at generated lines 158-159.
- [UID:00019S] emits `static void OpenTerminalPane(MainMenuPane *pane)` at generated lines 196-197.
- [UID:00007O], [UID:0000PH], [UID:0000PI], [UID:0000SZ], [UID:0000T1], [UID:0000TA], [UID:0000TB], [UID:0000TC], [UID:0000TE], and [UID:0000TF] now appear as validator-supported comment-only markers, not old empty-marker/no-code text.
- `rg "^static .*\\(" auto-generated/NexusTK/login/MainMenuPane.cpp` shows one definition each for `CloseMainMenuDialogSingletons`, `ComputeMenuItemRect`, `HandleLegacyMainMenuPacket`, `HitTestMenuItem`, `OpenChangePasswordDialog`, `OpenCreateUserDialog`, `OpenHistoryViewingPane`, `OpenStoryViewingPane`, and `OpenTerminalPane`; no duplicate helper bodies were found.

## Implementation Tracking Checklist

- [x] Lease only the files being edited for the accepted callback, and release all leases after validation. Proof: B011 leased the 14 by-* edit files successfully before edits; release/no-lease proof is recorded after validation in the final callback.
- [x] `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`: change `COMPLETION:85` to `88`, `CONFIDENCE:88` to `90`, update Item Summary to remove "final C++ deferred", and insert the exact `static void OpenCreateUserDialog()` formal C++ block from this report. Proof: validator `000000003502`, exit `0`, ok `1`; generated [UID:00019P] body at lines 158-159.
- [x] `by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md`: update Status, Behavior Summary, Disposition, and Changes to replace blank-C++/reachability-blocker wording with first-draft body acceptance and no-entry/no-pointer confidence cap. Proof: current page prose supersedes blank-C++ blocker; validator `000000003502`.
- [x] `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`: change `COMPLETION:86` to `88`, keep `CONFIDENCE:90`, update Item Summary to remove "final C++ deferred", and insert the exact `static void OpenTerminalPane(MainMenuPane *pane)` formal C++ block from this report. Proof: validator `000000003503`, exit `0`, ok `1`; generated [UID:00019S] body at lines 196-197.
- [x] `by-memory/0x004f91c0-0x004f927d.OpenTerminalPane.md`: remove stale `95/95 reconstruction-code gate` wording and replace it with current retained-helper policy and no-entry/no-pointer confidence cap. Proof: current prose historicalizes/supersedes old gate wording; validator `000000003503`.
- [x] `by-class/MainMenuPane.md`: keep `85/89`, insert the exact class aggregate comment-only formal block, and update helper rows for `OpenCreateUserDialog` and `OpenTerminalPane` to say exact children [UID:00019P]/[UID:00019S] emit first-draft bodies. Proof: validator `000000003504`, generated lines 7-9.
- [x] `by-global/CloseMainMenuDialogSingletons_4F69A0.md`: keep `86/90`, insert the exact [UID:00019J] alias comment-only formal block. Proof: validator `000000003505`, generated lines 11-12.
- [x] `by-global/ComputeMenuItemRect_4F8B90.md`: keep `86/90`, insert the exact [UID:00019M] alias comment-only formal block. Proof: validator `000000003506`, generated lines 14-15.
- [x] `by-global/HandleLegacyMainMenuPacket_4F8D00.md`: keep `86/90`, insert the exact [UID:00019O] alias comment-only formal block. Proof: validator `000000003507`, generated lines 17-18.
- [x] `by-global/HitTestMenuItem_4F8C10.md`: keep `86/90`, insert the exact [UID:00019N] alias comment-only formal block and historicalize any "keeping reconstruction C++ blank" wording as superseded by comment-only alias marker. Proof: validator `000000003508`, generated lines 20-21.
- [x] `by-global/OpenChangePasswordDialog_4F9060.md`: keep `88/90`, insert the exact [UID:00019Q] alias comment-only formal block. Proof: validator `000000003509`, generated lines 23-24.
- [x] `by-global/OpenCreateUserDialog_4F8FA0.md`: keep `86/90`, insert the exact [UID:00019P] alias comment-only formal block, and replace "no final C++ emitted"/"Code intentionally blank" wording with child-body ownership through [UID:00019P]. Proof: validator `000000003511`, generated lines 26-27.
- [x] `by-global/OpenHistoryViewingPane_4F9140.md`: keep `86/90`, insert the exact [UID:0003H7] alias comment-only formal block. Proof: validator `000000003513`, generated lines 29-30.
- [x] `by-global/OpenStoryViewingPane_4F90C0.md`: keep `86/90`, insert the exact [UID:0003H6] alias comment-only formal block. Proof: validator `000000003515`, generated lines 32-33.
- [x] `by-global/OpenTerminalPane_4F91C0.md`: keep `86/90`, insert the exact [UID:00019S] alias comment-only formal block, and remove stale `95+/95+` gate wording. Proof: validator `000000003517`, generated lines 35-36.
- [x] `by-file/MainMenuPane.md`: keep `89/86`; update Proposed Contents, Key Behavior, Migration Notes, Score Rationale, and Changes for [UID:00019P]/[UID:00019S] first-draft C++ readiness and accepted exact-child body ownership. Proof: validator `000000003519`, exit `0`, ok `1`.
- [x] `by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md`: keep `85/88`, set `CANONICAL_OWNER:0000L0` per callback, keep `RECONSTRUCTABLE:FALSE` and blank emitters; update retained-helper inventory/prose for [UID:00019P]/[UID:00019S]. Proof: validator `000000003521`, exit `0`, ok `1`, canonical owner update `NONE -> 0000L0`.
- [x] Update this report ledger rows from `proposed` to callback proof states only after actual implementation; keep this report path as the only B011 research/report edit. Proof: ledger rows above now carry applied/verified proof.
- [x] Run the scoped validators listed above and record command ids, timestamps, exit codes, `ok` counts, generated refresh status, and warnings. Proof: validation table above.
- [x] Read back `auto-generated/NexusTK/login/MainMenuPane.cpp` after validator refresh and record validator freshness plus [UID:00019P]/[UID:00019S] body presence and absence of duplicate helper bodies. Proof: generated header `000000003545`, refreshed `2026-07-01T06:13:51-04:00`; `rg "^static .*\\("` found one function definition per helper.
- [x] Do not manually edit generated C++ files, generated reports, project-level reports, manual `-coverage-report.md` files, validator/tool state, queue files, archives, supervisor ledgers, by-project-structure docs, or IDA DB. Proof: manual edits were only accepted by-* docs and this B011 report; validator-owned generated/tool/project files changed through validator runs only.
- [x] Release all B011 leases and confirm no B011 leases remain before returning the callback. Proof: `unlease` after validation reported `No active lease` for all B011 target files, and `Select-String` over global/per-agent `current_leases.md` found no `B011` entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B011","command_id":"000000004165","destination_path":"executed-b-agent-research/B011/0000L0-MainMenuPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B011/research/0000L0-MainMenuPane-empty-emitter-family-source-quality.md","timestamp":"2026-07-01T06:15:54","uid":"0000L0"} -->
<!-- {"agent":"B011","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000L0-MainMenuPane-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B011/0000L0-MainMenuPane-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000L0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
